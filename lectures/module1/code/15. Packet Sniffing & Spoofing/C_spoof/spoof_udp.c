/* spoof_udp
Spoof a udp packet and send out.
Compilation:
  gcc spoof.c spoof_udp.c checksum.c -o spoof_udp
Usage:
  sudo ./spoof_udp interface source_ip source_port destination_ip destination_port
  e.g.
  Open two terminal tabs, in one, run:
  nc -lu 9090
  in the other, run  
  sudo ./spoof_udp lo 1.2.3.4 1234 127.0.0.1 9090
  the packet can be captured with
  sudo tcpdump -i lo dst 127.0.0.1
Refs:
1. https://danielmiessler.com/study/tcpdump  
*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <arpa/inet.h>

#include "myheader.h"

#define SRC_IP     "1.2.3.4"
#define DEST_IP    "10.0.2.5"
#define SRC_PORT   42433
#define DEST_PORT  9090 
#define UDP_DATA   "Hello Server!\n" // length=14

/******************************************************************
  Spoof a UDP packet using an arbitrary source IP Address and port
*******************************************************************/
int main(int argc, char* argv[]) {
   char buffer[1500];

   if (argc != 6)
   {
      printf("Usage: %s interface source_ip source_port destination_ip destination_port\n", argv[0]);
      return 1;
   }

   memset(buffer, 0, 1500);
   struct ipheader *ip = (struct ipheader *) buffer;
   struct udpheader *udp = (struct udpheader *) (buffer +
                                          sizeof(struct ipheader));

   /*********************************************************
      Step 1: Fill in the UDP data field.
    ********************************************************/
   char *data = buffer + sizeof(struct ipheader) +
                         sizeof(struct udpheader);
   const char *msg = UDP_DATA;
   int data_len = strlen(msg);
   strncpy (data, msg, data_len);

   /*********************************************************
      Step 2: Fill in the UDP header.
    ********************************************************/
   udp->udp_sport = htons(atoi(argv[3])); // SRC_PORT
   udp->udp_dport = htons(atoi(argv[5])); // DEST_PORT
   udp->udp_ulen = htons(sizeof(struct udpheader) + data_len);
   udp->udp_sum =  0; /* Many OSes ignore this field, so we do not
                         calculate it. */

   /*********************************************************
      Step 3: Fill in the IP header.
    ********************************************************/
   ip->iph_ver = 4;
   ip->iph_ihl = 5;
   ip->iph_ttl = 20;
   ip->iph_sourceip.s_addr = inet_addr(argv[2]); // Source IP
   ip->iph_destip.s_addr = inet_addr(argv[4]);  // Dest IP
   ip->iph_protocol = IPPROTO_UDP; // The value is 17.
   ip->iph_len = htons(sizeof(struct ipheader) +
                       sizeof(struct udpheader) + data_len);

   /*********************************************************
      Step 4: Finally, send the spoofed packet
    ********************************************************/
   send_raw_ip_packet (argv[1], ip);

   return 0;
}
