/* udp_client
create a datagram socket and send out a message
Compilation:
    gcc udp_client.c -o udp_client
Usage:
    open two terminal tabs, in the first one run a udp server, e.g.
    nc -lu 9090
    in the second tab, run
    ./udp_client destination_IP destination_port_number [message]
    e.g.
    ./udp_client 127.0.0.1 9090 "Have a great day!"
Note:
nc -lvu 9090 name resolving problem

The error of "nc: getnameinfo: Temporary failure in name resolution" when you run "nc -lv 9090", 
can be solved by

# 1. appending the following two lines to the domain name resolving configuration file /etc/resolv.conf
nameserver 10.20.30.1 # change to your VM gateway, find it with ip route inside your VM
nameserver 8.8.4.4

# 2. restart the domain name resolving service
sudo systemctl restart systemd-resolved.service   

Make the modification permanent:
https://linuxlasse.net/linux/howtos/Static_DNS_/_Protect_the_resolv.conf

*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <arpa/inet.h>

int main(int argc, char* argv[])
{
    struct sockaddr_in dest_info;
    char *data = "UDP message\n";
    if (argv[3] != NULL)
    {
        data = argv[3];
    }
    

    if (argc<3 || argc > 4)
    {
        printf("Usage: %s destination_IP destination_port_number [message]\n", argv[0]);
        return 1;
    }
    

    // Step 1: Create a network socket
    int sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

    // Step 2: Provide information about destination.
    memset((char *) &dest_info, 0, sizeof(dest_info));
    dest_info.sin_family = AF_INET;
    dest_info.sin_addr.s_addr = inet_addr(argv[1]);
    dest_info.sin_port = htons(atoi(argv[2]));

    // Step 3: Send out the packet.
    sendto(sock, data, strlen(data), 0,
                 (struct sockaddr *)&dest_info, sizeof(dest_info));
    close(sock);
}
