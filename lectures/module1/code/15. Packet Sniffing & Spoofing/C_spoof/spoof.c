/* send out raw packet
Refs:
1. https://stackoverflow.com/questions/3998569/how-to-bind-raw-socket-to-specific-interface
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <net/if.h>

#include "myheader.h"

/*************************************************************
  Given an IP packet, send it out using a raw socket.
**************************************************************/
void send_raw_ip_packet(char *intf, struct ipheader *ip)
{
  struct sockaddr_in dest_info;
  int enable = 1;
  int ret = 0;

  // Step 1: Create a raw network socket.
  int sock = socket(AF_INET, SOCK_RAW, IPPROTO_RAW);
  if (sock < 0)
  {
    printf("send_raw_ip_packet: failed to create raw socket\n");
    return;
  }

  // Step 2: Set socket option.
  ret = setsockopt(sock, IPPROTO_IP, IP_HDRINCL,
                   &enable, sizeof(enable));
  if (ret < 0)
  {
    printf("send_raw_ip_packet: setsockopt failed.\n");
  }

  // bind to specified interface
  unsigned int len = strnlen(intf, IFNAMSIZ);
  if (len == IFNAMSIZ)
  {
    fprintf(stderr, "Too long iface name");
    return;
  }
  ret = setsockopt(sock, SOL_SOCKET, SO_BINDTODEVICE, intf, len);
  if (ret < 0)
  {
    printf("send_raw_ip_packet: setsockopt failed to bind interface.\n");
  }
  // Step 3: Provide needed information about destination.
  dest_info.sin_family = AF_INET;
  dest_info.sin_addr = ip->iph_destip;

  // Step 4: Send the packet out.
  ret = sendto(sock, ip, ntohs(ip->iph_len), 0,
               (struct sockaddr *)&dest_info, sizeof(dest_info));
  if (ret < 0)
  {
    printf("send_raw_ip_packet: failed to send raw packet.\n");
  }
  close(sock);
}
