#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# udp_spoof
# Spoof then send udp packet
# Prerequisite:
#  Python3 and scapy
# Usage:
# ./udp_spoof.py source_ip source_port destination_ip destination_port
# Run with sudo, e.g.
# sudo python3 udp_spoof.py 1.2.3.4 1234 4.3.2.1 4321
# or make it executable
# chmod +x udp_spoof.py  1.2.3.4 1234 4.3.2.1 4321
# 
# use nc -lun 4321 to receive the packet
# The spoofed udp packet can be captured with wireshark or tcpdump
# refs:
# 1. https://scapy.readthedocs.io
# 2. https://unix.stackexchange.com/questions/209746/how-to-resolve-no-protocol-specified-for-su-user

import sys
import os
from scapy.all import *


# spoof and send udp packets
def spsUDP(src_ip='1.2.3.4', src_port=1234, dst_ip='4.3.2.1', dst_port=4321):
    ip = IP(src=src_ip, dst=dst_ip)             # IP Layer
    udp = UDP(sport=src_port, dport=dst_port)   # UDP Layer
    data = "Hello UDP!\n"                       # Payload
    pkt = ip/udp/data      # Construct the complete packet
    pkt.show()
    send(pkt,verbose=0)

if __name__ == "__main__":
   # test code
    
    if len(sys.argv) != 5:
        print("Usage: sudo {} source_ip source_port destination_ip destination_port\n".format(sys.argv[0]))
        exit(1)

    src_ip = sys.argv[1]
    src_port = int(sys.argv[2])
    dst_ip = sys.argv[3]
    dst_port = int(sys.argv[4])

    print("SENDING SPOOFED UDP PACKET.........")
    spsUDP(src_ip, src_port, dst_ip, dst_port)