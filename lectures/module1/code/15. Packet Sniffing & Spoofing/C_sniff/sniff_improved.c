/*  sniffer_improved by pcap
Keeps sniffing and printing out captured raw packets with simple packet analyser
Compilation: 
  install libpcap-dev first: sudo apt install libpcap-dev
  gcc sniffer_improved.c -o sniffer_improved -lpcap
Usage:
  sudo ./sniffer_improved interface ["bpf expression"] [number_of_packets_to_capture]
  e.g.
  sudo ./sniffer_improved eth0
  or
  sudo ./sniffer_improved eth0 "ip proto icmp"
  or
  sudo ./sniffer_improved eth0 "ip proto icmp" 6
  then generate some network traffics, for example, browse a website
  generate ICMP packets: ping -4 -I interface_name 1.1.1.1
  Ctrl+C to stop  
Refs:
1. https://askubuntu.com/questions/430355/configure-a-network-interface-into-promiscuous-mode
2. https://www.techplayon.com/tcpdump-for-linux-system-a-tool-for-ip-packet-analysis/   
3. https://stackoverflow.com/questions/33484762/packet-sockets-not-receiving-data-for-custom-protocol-id   
4. http://netsniff-ng.org/
5. https://biot.com/capstats/bpf.html
6. https://libpcap.readthedocs.io/
7. https://pcapplusplus.github.io/
*/

#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>

/* Ethernet header */
struct ethheader {
  u_char  ether_dhost[6]; /* destination host address */
  u_char  ether_shost[6]; /* source host address */
  u_short ether_type;     /* protocol type (IP, ARP, RARP, etc) */
};

/* IP Header */
struct ipheader {
  unsigned char      iph_ihl:4, //IP header length
                     iph_ver:4; //IP version
  unsigned char      iph_tos; //Type of service
  unsigned short int iph_len; //IP Packet length (data + header)
  unsigned short int iph_ident; //Identification
  unsigned short int iph_flag:3, //Fragmentation flags
                     iph_offset:13; //Flags offset
  unsigned char      iph_ttl; //Time to Live
  unsigned char      iph_protocol; //Protocol type
  unsigned short int iph_chksum; //IP datagram checksum
  struct  in_addr    iph_sourceip; //Source IP address
  struct  in_addr    iph_destip;   //Destination IP address
};

void got_packet(u_char *args, const struct pcap_pkthdr *header,
                              const u_char *packet)
{
  printf("\npacket info:\n");
  printf("caplen: %d packet length: %d\n", header->caplen, header->len);

// print out raw packet
  for (int i = 0; i < header->len; i++)
  {
    if (i%10 == 0)
          {
              printf("\n");
          }
          printf("%02X ", *(packet+i)); 
  }
  printf("\n");

  struct ethheader *eth = (struct ethheader *)packet;
  if (ntohs(eth->ether_type) == 0x0800) { // 0x0800 is IP type
    struct ipheader * ip = (struct ipheader *)
                           (packet + sizeof(struct ethheader)); 

    printf("       From: %s\n", inet_ntoa(ip->iph_sourceip));   
    printf("         To: %s\n", inet_ntoa(ip->iph_destip));    

    /* determine protocol */
    switch(ip->iph_protocol) {                                 
        case IPPROTO_TCP:
            printf("   Protocol: TCP\n");
            return;
        case IPPROTO_UDP:
            printf("   Protocol: UDP\n");
            return;
        case IPPROTO_ICMP:
            printf("   Protocol: ICMP\n");
            return;
        default:
            printf("   Protocol: others\n");
            return;
    }
  }
}

int main(int argc, char* argv[])
{
  pcap_t *handle;
  char errbuf[PCAP_ERRBUF_SIZE];
  struct bpf_program fp;
  char filter_exp_default[] = "ip proto icmp"; // not work as expected but "icmp" does
  char *filter_exp = filter_exp_default;
  bpf_u_int32 net;

  int cpnum = -1; // -1 means keep capturing
  if (argc < 2 || argc >4)
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
  pcap_loop(handle, cpnum, got_packet, NULL);

  pcap_close(handle);   //Close the handle
  return 0;
}


