/* raw socket sniffer
Keeps sniffing and printing out captured raw packets.
Compilation: 
    gcc sniff_raw.c -o sniff_raw
Usage:
    sudo ./sniff_raw
    then generate some network traffics, for example, browse a website
    Ctrl+C to stop  
Refs:
1. https://askubuntu.com/questions/430355/configure-a-network-interface-into-promiscuous-mode
2. https://www.techplayon.com/tcpdump-for-linux-system-a-tool-for-ip-packet-analysis/   
3. https://stackoverflow.com/questions/33484762/packet-sockets-not-receiving-data-for-custom-protocol-id   
*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <linux/if_packet.h>
#include <net/ethernet.h>
#include <arpa/inet.h>

int main(int argc, char* argv[]) {
    int PACKET_LEN = 512;
    unsigned char buffer[PACKET_LEN];
    struct sockaddr saddr;
    struct packet_mreq mr;

    // Create the raw socket and capture all packets it received
    int sock = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL)); 
    if(sock < 0)
	{
		printf("Socket Error\n");
		return 1;
	}
    // printf("%d, %d\n",ETH_P_ALL, htons(ETH_P_ALL));

    // Turn on the promiscuous mode to capture others' packet
    mr.mr_type = PACKET_MR_PROMISC;  
    setsockopt(sock, SOL_PACKET, PACKET_ADD_MEMBERSHIP, &mr, sizeof(mr));

    // Getting captured packets
    while (1) {
        // int data_size=recvfrom(sock, buffer, PACKET_LEN, 0, &saddr, (socklen_t*)sizeof(saddr));
        int data_size=recvfrom(sock, buffer, PACKET_LEN, 0, 0, 0);

        if(data_size > 0) {
            printf("\n\nGot one packet of size %d:\n", data_size);
            // print the raw packet in hex numeric
            for (int i = 0; i < data_size; i++)
            {
                if (i%10 == 0 )
                {
                   printf("\n");
                }
                printf("%02X ", buffer[i]);                                
            }                        
        }
    }

    close(sock);
    return 0;
}

