/* udp server
Keep printing out what is received from a client.

Compilation: gcc udp_server.c -o udp_server
Usage: ./udp_server [portnumber]
Ctrl+C to stop
example: ./udp_server 9090
open another terminal tab run: nc -u localhost 9090
then type anything, on the udp_server tab see what is printed.
*/
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/ip.h>

int main(int argc, char* argv[])
{
    struct sockaddr_in server;
    struct sockaddr_in client;
    int clientlen;
    char buf[1500];

    if (argc != 2)
    {
        printf("Usage: %s port_number\n", argv[0]);
        return 1;
    }
    
    // Step 1: create a socket
    int sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

    // Step 2: provide information of the server
    memset((char *) &server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_port = htons(atoi(argv[1]));

    if (bind(sock, (struct sockaddr *) &server, sizeof(server)) < 0)
        perror("ERROR on binding");

    // Step 3: keep receiving and printing out what it received
    while (1) {
        bzero(buf, 1500);
        recvfrom(sock, buf, 1500-1, 0,
                       (struct sockaddr *) &client, &clientlen);
        printf("%s\n", buf);
    }
    close(sock);

    return 0;
}

