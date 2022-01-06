/* spoof_icmp
Spoof an icmp echo request packet and send out, reply is gotten if succeeded.
Compilation:
  gcc spoof.c spoof_icmp.c checksum.c -o spoof_icmp
Usage:
  sudo ./spoof_icmp interface source_ip destination_ip
  e.g.
  Open two terminal tabs, in one, run:
  sudo tcpdump -i lo src 1.2.3.4
  it is better use wireshark
  in the other, run  
  sudo ./spoof_icmp lo 1.2.3.4 127.0.0.2
  sudo ./spoof_icmp eth0 8.8.8.8 8.8.4.4 # don't use

Refs:
1. https://danielmiessler.com/study/tcpdump  
*/
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <arpa/inet.h>

#include "myheader.h"

/******************************************************************
  Spoof an ICMP echo request using an arbitrary source IP Address
*******************************************************************/
int main(int argc, char* argv[]) {
   char buffer[1500];

   memset(buffer, 0, 1500);

  if (argc !=4)
  {
    printf("Usage: %s interface source_ip destination_ip\n", argv[0]);
    return 1;
  }
  
   /*********************************************************
      Step 1: Fill in the ICMP header.
    ********************************************************/
   struct icmpheader *icmp = (struct icmpheader *)
                             (buffer + sizeof(struct ipheader));
   icmp->icmp_type = 8; //ICMP Type: 8 is request, 0 is reply.

   // Calculate the checksum for integrity
   icmp->icmp_chksum = 0;
   icmp->icmp_chksum = in_cksum((unsigned short *)icmp,
                                 sizeof(struct icmpheader));

   /*********************************************************
      Step 2: Fill in the IP header.
    ********************************************************/
   struct ipheader *ip = (struct ipheader *) buffer;
   ip->iph_ver = 4;
   ip->iph_ihl = 5;
   ip->iph_ttl = 20;
   ip->iph_sourceip.s_addr = inet_addr(argv[2]); // "1.2.3.4"
   ip->iph_destip.s_addr = inet_addr(argv[3]); // "10.0.2.69"
   ip->iph_protocol = IPPROTO_ICMP;
   ip->iph_len = htons(sizeof(struct ipheader) +
                       sizeof(struct icmpheader));

   /*********************************************************
      Step 3: Finally, send the spoofed packet
    ********************************************************/
   send_raw_ip_packet (argv[1], ip);

   return 0;
}

