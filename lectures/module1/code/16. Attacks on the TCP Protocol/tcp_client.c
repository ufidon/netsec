/* tcp_client
connect to server at socket (server_ip,port_number)
complition:
  gcc tcp_client.c -o tcp_client
usage:
  open two terminal tabs, in one, run
  nc -l server_ip port_number
  e.g.
  nc -l 127.0.0.7 9090
  in the other, run
  ./tcp_client server_ip port_number
  e.g.
  ./tcp_client 127.0.0.7 9090

Refs:
1. https://serverfault.com/questions/512333/how-can-i-configure-netcat-or-some-other-stock-linux-utility-to-listen-on-a-sp  
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
  if (argc != 3)
  {
    printf("Usage: %s server_ip port_number\n", argv[0]);
    return 1;
  }

  
  // Step 1: Create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);

  // Step 2: Set the destination information
  struct sockaddr_in dest;
  memset(&dest, 0, sizeof(struct sockaddr_in));
  dest.sin_family = AF_INET;
  dest.sin_addr.s_addr = inet_addr(argv[1]); // "10.0.2.69"
  dest.sin_port = htons(atoi(argv[2])); // 9090

  // Step 3: Connect to the server
  connect(sockfd, (struct sockaddr *)&dest,
          sizeof(struct sockaddr_in));

  // Step 4: Send data to the server
  char *buffer1 = "Hello Server!\n";
  char *buffer2 = "Hello Again!\n";
  write(sockfd, buffer1, strlen(buffer1));

  write(sockfd, buffer2, strlen(buffer2));

  // Step 5: Close the connection
  close(sockfd);

  return 0;
}

