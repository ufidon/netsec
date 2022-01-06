#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# sniff_spoof_icmp
# Sniff an icmp echo request packet then spoof an icmp echo reply packet
# Prerequisite:
#  Python3 and scapy
# Usage:
# ./sniff_spoof_icmp.py host_ip
# Run with sudo, e.g.
# sudo python3 sniff_spoof_icmp.py 1.2.3.4
# or make it executable
# chmod +x sniff_spoof_icmp.py
# sudo ./sniff_spoof_icmp.py 1.2.3.4
# ping the host_ip in another terminal, it should receive spoofed reply
# use wireshark or tcpdump to see the whole scenario
# refs:
# 1. https://scapy.readthedocs.io
# 2. https://unix.stackexchange.com/questions/209746/how-to-resolve-no-protocol-specified-for-su-user

import sys
import os
from scapy.all import *


def spoof_pkt(pkt):
    # sniff and print out icmp echo request packet
    if ICMP in pkt and pkt[ICMP].type == 8:
        print("Original Packet.........")
        print("Source IP : ", pkt[IP].src)
        print("Destination IP :", pkt[IP].dst)

        # spoof an icmp echo reply packet
        # swap srcip and dstip
        ip = IP(src=pkt[IP].dst, dst=pkt[IP].src, ihl=pkt[IP].ihl)
        icmp = ICMP(type=0, id=pkt[ICMP].id, seq=pkt[ICMP].seq)
        data = pkt[Raw].load
        newpkt = ip/icmp/data

        print("Spoofed Packet.........")
        print("Source IP : ", newpkt[IP].src)
        print("Destination IP :", newpkt[IP].dst)

        send(newpkt, verbose=0)


if __name__ == "__main__":
   # test code

    if len(sys.argv) != 2:
        print("Usage: sudo {} host_ip\n".format(
            sys.argv[0]))
        exit(1)

    host_ip = sys.argv[1]
    filter = 'icmp and host '+host_ip
    print("filter: {}\n".format(filter))

    pkt = sniff(filter=filter, prn=spoof_pkt)
