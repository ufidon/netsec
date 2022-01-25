/* tcp_server_improved
bind to socket server_ip port_number
multiple clients are acceptable
here, server_ip is binding_ip
Usage:
Open two terminal tabs, in one, run
  ./tcp_server_improved binding_ip port_number
  e.g.
  ./tcp_server_improved 127.0.0.7 9090
  Ctrl+C to stop
in the other, run
  nc server_ip port_number
  e.g.
  nc 127.0.0.7 9090
  then type something
Refs:
1. https://stackoverflow.com/questions/5328070/how-to-convert-string-to-ip-address-and-vice-versa
2. https://stackoverflow.com/questions/17523389/check-all-socket-opened-in-linux-os/17523444
3. https://en.wikipedia.org/wiki/0.0.0.0
4. https://en.wikipedia.org/wiki/Reserved_IP_addresses
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
  int sockfd, newsockfd;
  struct sockaddr_in my_addr, client_addr;
  char buffer[100];

  if (argc != 3)
  {
    printf("Usage: %s binding_address port_number\n", argv[0]);
    return 1;
  }
  // Step 1: Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);

  // Step 2: Bind to a port number
  memset(&my_addr, 0, sizeof(struct sockaddr_in));
  my_addr.sin_family = AF_INET;
  inet_pton(AF_INET, argv[1], &(my_addr.sin_addr)); // "192.0.2.33"
  my_addr.sin_port = htons(atoi(argv[2])); // 9090
  bind(sockfd, (struct sockaddr *)&my_addr, sizeof(struct sockaddr_in));

  // Listen for connections
  listen(sockfd, 5);

  int client_len = sizeof(client_addr);
  while (1) {
    newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_len);

    if (fork() == 0) { // The child process           
       close (sockfd);

       // Read data.
       memset(buffer, 0, sizeof(buffer));
       int len = read(newsockfd, buffer, 100);
       printf("Received %d bytes.\n%s\n", len, buffer);

       close (newsockfd);
       return 0;
    } else {  // The parent process                    
       close (newsockfd);
    }
  }

  return 0;
}

