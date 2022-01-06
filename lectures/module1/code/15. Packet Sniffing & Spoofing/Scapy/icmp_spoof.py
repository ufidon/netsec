#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# icmp_spoof
# Spoof then send icmp packet
# Prerequisite:
#  Python3 and scapy
# Usage:
# ./icmp_spoof.py source_ip destination_ip
# Run with sudo, e.g.
# sudo python3 icmp_spoof.py 1.2.3.4 4.3.2.1
# or make it executable
# chmod +x icmp_spoof.py  1.2.3.4 4.3.2.1
# 
# The spoofed ICMP packet can be captured with wireshark or tcpdump
# ref:
# 1. https://scapy.readthedocs.io

import sys
import os
from scapy.all import *

# spoof and send icmp packets
def spsICMP(src_ip='1.2.3.4', dst_ip='4.3.2.1'):
    ip = IP(src=src_ip, dst=dst_ip)
    icmp = ICMP()   # the icmp object is filled with default values
    pkt = ip/icmp   # / is overridden to mean encapsulate the icmp with ip to form an ip packet
    pkt.show()
    send(pkt, verbose=0)



if __name__ == "__main__":
   # test code
    
    if len(sys.argv) != 3:
        print("Usage: sudo {} source_ip destination_ip\n".format(sys.argv[0]))
        exit(1)
    src_ip = sys.argv[1]
    dst_ip = sys.argv[2]

    print("SENDING SPOOFED ICMP PACKET.........")
    spsICMP(src_ip, dst_ip)
    
