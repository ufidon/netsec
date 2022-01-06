/*  sniff_snoof_udp by pcap and raw socket
Keeps sniffing udp packets then spoofing them
Compilation: 
  install libpcap-dev first: sudo apt install libpcap-dev
  gcc spoof.c sniff_snoof_udp.c -o sniff_snoof_udp -lpcap
Usage:
  sudo ./sniff_snoof_udp interface  ["bpf expression"] [number_of_packets_to_capture]
  e.g.
  open two terminal tabs, in one, run
  sudo ./sniff_snoof_udp eth0
  or 
  sudo ./sniff_snoof_udp eth0 "ip proto icmp"
  or 
  sudo ./sniff_snoof_udp eth0 "ip proto icmp" 6
  in the other, run
  nc -u 1.2.3.4 9999
  # type something to send out a udp packet
  both need Ctrl+C to stop  
Refs:
1. https://askubuntu.com/questions/430355/configure-a-network-interface-into-promiscuous-mode
2. https://www.techplayon.com/tcpdump-for-linux-system-a-tool-for-ip-packet-analysis/   
3. https://stackoverflow.com/questions/33484762/packet-sockets-not-receiving-data-for-custom-protocol-id   
4. http://netsniff_snoof_udp-ng.org/
5. https://biot.com/capstats/bpf.html
6. https://libpcap.readthedocs.io/
7. https://pcapplusplus.github.io/
*/

#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <arpa/inet.h>

#include "myheader.h"

#define SPOOFPORT 9999
#define BUFSIZE 65536

void got_packet(u_char *args, const struct pcap_pkthdr *header,
                const u_char *packet)
{
  //printf("Got a packet\n");
  //printf("args: %s\n", (char*)args);
  struct ethheader *eth = (struct ethheader *)packet;
  if (ntohs(eth->ether_type) != 0x0800)
  {
    //printf("Not IP type\n");
    return;
  }
  // 0x0800 is IP type
  struct ipheader *ip = (struct ipheader *)(packet + sizeof(struct ethheader));

  // printf("       From: %s\n", inet_ntoa(ip->iph_sourceip));
  // printf("         To: %s\n", inet_ntoa(ip->iph_destip));

  /* determine protocol */
  switch (ip->iph_protocol)
  {
  case IPPROTO_TCP:
    //printf("   Protocol: TCP\n");
    return;
  case IPPROTO_UDP:
    // printf("   Protocol: UDP\n");
    // printf("       From: %s\n", inet_ntoa(ip->iph_sourceip));
    // printf("         To: %s\n", inet_ntoa(ip->iph_destip));
    break;
  case IPPROTO_ICMP:
    //printf("   Protocol: ICMP\n");
    return;
  default:
    //printf("   Protocol: others\n");
    return;
  }

  const char buffer[BUFSIZE];
  int ip_header_len = ip->iph_ihl * 4;
  struct udpheader *udp = (struct udpheader *)((u_char *)ip +
                                               sizeof(struct ipheader));

  if (ntohs(udp->udp_dport) != SPOOFPORT)
  {
    //printf("We only spoof UDP packets with destination port:%d\n", SPOOFPORT);
    //printf("udp sport:%d, dport:%d\n", ntohs(udp->udp_sport), ntohs(udp->udp_dport));
    return;
  }
  printf("\ncaptudp: %s -> %s \n", inet_ntoa(ip->iph_sourceip), inet_ntoa(ip->iph_destip));
  printf("captudp sport:%d, dport:%d\n\n", ntohs(udp->udp_sport), ntohs(udp->udp_dport));
  // Step 1: Make a copy from the original packet
  memset((char *)buffer, 0, BUFSIZE);
  memcpy((char *)buffer, ip, ntohs(ip->iph_len));

  struct ipheader *newip = (struct ipheader *)buffer;
  struct udpheader *newudp = (struct udpheader *)(buffer + ip_header_len);
  char *data = (char *)newudp + sizeof(struct udpheader);

  // Step 2: Construct the UDP payload, keep track of payload size
  const char *msg = "This is a spoofed reply!\n";
  int data_len = strlen(msg);
  strncpy(data, msg, data_len);

  // Step 3: Construct the UDP header, swap source and destination port numbers
  newudp->udp_dport = udp->udp_sport;
  newudp->udp_sport = udp->udp_dport;
  newudp->udp_ulen = htons(sizeof(struct udpheader) + data_len);
  newudp->udp_sum = 0; // ignored checksum,OK?

  printf("spoofudp sport:%d, dport:%d\n", ntohs(newudp->udp_sport), ntohs(newudp->udp_dport));
  // Step 4: Construct the IP header, keep what we got from the captured packet
  // swap source and destination ip addresses
  newip->iph_destip = ip->iph_sourceip;
  newip->iph_sourceip = ip->iph_destip;
  newip->iph_ttl = 50;
  newip->iph_len = htons(sizeof(struct ipheader) + sizeof(struct udpheader) + data_len);

  printf("spoofudp: %s -> %s \n", inet_ntoa(newip->iph_sourceip), inet_ntoa(newip->iph_destip));
  // Step 5: Send out the spoofed IP packet
  send_raw_ip_packet(args, newip);
  //send_raw_ip_packet ("lo", ip);
}

int main(int argc, char *argv[])
{
  pcap_t *handle;
  char errbuf[PCAP_ERRBUF_SIZE];
  struct bpf_program fp;
  char filter_exp_default[] = "ip proto icmp"; // not work as expected but "icmp" does
  char *filter_exp = filter_exp_default;
  bpf_u_int32 net;
  int cpnum = -1; // -1 means keep capturing
  if (argc < 2 || argc > 4)
  {
    printf("Usage: sudo %s interface [\"bpf expression\"] [number_of_packets_to_capture]\n", argv[0]);
    return 1;
  }
  if (argc > 2)
  {
    filter_exp = argv[2];
  }
  if (argc == 4)
  {
    cpnum = atoi(argv[3]);
  }

  // Step 1: Open live pcap session on NIC with name, e.g. enp0s3
  handle = pcap_open_live(argv[1], BUFSIZ, 1, 1000, errbuf);

  // Step 2: Compile filter_exp into BPF psuedo-code
  pcap_compile(handle, &fp, filter_exp, 0, net);
  pcap_setfilter(handle, &fp);

  // Step 3: Capture packets
  pcap_loop(handle, cpnum, got_packet, argv[1]);

  pcap_close(handle); //Close the handle
  return 0;
}
