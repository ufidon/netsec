/* raw_receiver
Keeps receiving and printing out raw packets.
Compilation:
    gcc raw_receiver.c -o raw_receiver
Usage:
    sudo ./raw_receiver

Refs:
1. https://stackoverflow.com/questions/33484762/packet-sockets-not-receiving-data-for-custom-protocol-id
*/
#include <sys/socket.h>
#include <linux/if_packet.h>
#include <linux/if_ether.h>
#include <linux/if_arp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <net/ethernet.h>
#include <arpa/inet.h>
//#define CUSTOM_PROTO 0xB588
#define CUSTOM_PROTO ETH_P_ALL
int main ()
{
    int sockfd = -1;
    struct sockaddr_ll dest_addr = {0}, src_addr={0};
    unsigned char *recvbuf = malloc(1514);

    sockfd = socket(PF_PACKET, SOCK_RAW, htons(CUSTOM_PROTO) );

    if ( sockfd == -1 )
    {
        perror("socket");
        return -1;
    }

    while (1)
    {
        int len = recvfrom(sockfd, recvbuf, 1514, 0, NULL, NULL);
        printf("\n\nI received a packet of size %d: \n", len);
        // print the raw packet in hex numeric
        for (int i = 0; i < len; i++)
        {
            if (i%10 == 0)
            {
                printf("\n");
            }
            printf("%02X ", *(recvbuf+i));                   
        }
    }
    
    return 0;
}