/*  sniff by pcap
Keeps sniffing and printing out captured  packets
Compilation: 
  install libpcap-dev first: sudo apt install libpcap-dev
  gcc sniff.c -o sniff -lpcap
Usage:
  sudo ./sniff interface  ["bpf expression"] [number_of_packets_to_capture]
  e.g.
  sudo ./sniff eth0
  or 
  sudo ./sniff eth0 "ip proto icmp"
  or 
  sudo ./sniff eth0 "ip proto icmp" 6
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

void got_packet(u_char *args, const struct pcap_pkthdr *header,
        const u_char *packet)
{
   printf("Got a packet\n");
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

