/* raw_sender
Sends out raw packets.
Compilation:
    gcc raw_sender.c -o raw_sender
Usage:
    sudo ./raw_sender interface
    e.g.
    sudo ./raw_sender eth0

Refs:
1. https://stackoverflow.com/questions/33484762/packet-sockets-not-receiving-data-for-custom-protocol-id
2. https://stackoverflow.com/questions/16235692/sendto-function-does-not-use-mac-address-provided-in-struct-sockaddr-ll-when-sen
*/
#include <sys/socket.h>
#include <linux/if_packet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <net/ethernet.h>
#include <net/if.h>
#include <arpa/inet.h>

#define CUSTOM_PROTO 0xB588
#define PAVAN_PROTO CUSTOM_PROTO

int main (int argc, char* argv[])
{
    int sockfd = -1;
    struct sockaddr_ll dest_addr = {0}, src_addr={0};
    unsigned char *buffer = NULL;
    struct ethhdr *eh;

    if (argc != 2)
    {
        printf("Usage: %s interface\n", argv[0]);
        return 1;
    }
    

    sockfd = socket(PF_PACKET, SOCK_RAW, htons(CUSTOM_PROTO) );

    if ( sockfd == -1 )
    {
        perror("socket");
        return -1;
    }
    buffer = malloc(1518);
    eh = (struct ethhdr *)buffer;

    dest_addr.sll_ifindex  = if_nametoindex(argv[1]);
    dest_addr.sll_addr[0]  = 0x0;
    dest_addr.sll_addr[1]  = 0xc;
    dest_addr.sll_addr[2]  = 0x29;
    dest_addr.sll_addr[3]  = 0x49;
    dest_addr.sll_addr[4]  = 0x3f;
    dest_addr.sll_addr[5]  = 0x5b;
    dest_addr.sll_addr[6]  = 0x0;
    dest_addr.sll_addr[7]  = 0x0;

    //other host MAC address
    unsigned char dest_mac[6] = {0x0, 0xc, 0x29, 0x49, 0x3f, 0x5b};

    /*set the frame header*/
    memcpy((void*)buffer, (void*)dest_mac, ETH_ALEN);
    memcpy((void*)(buffer+ETH_ALEN), (void*)dest_mac, ETH_ALEN);

    eh->h_proto = htons(PAVAN_PROTO);

    memcpy((void*)(buffer+ETH_ALEN+ETH_ALEN + 2), "Pavan", 6 );

    int send = sendto(sockfd, buffer, 1514, 0, (struct sockaddr*)&dest_addr,
                      sizeof(dest_addr) );
    if ( send == -1 )
    {
        perror("sendto");
        return -1;
    }
    return 0;
}
