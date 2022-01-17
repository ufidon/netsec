#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# sendreceive
# send ICMP echo request, wait for ICMP echo reply, receive reply and print
# Prerequisite:
#  Python3 and scapy
# ref: 
# 1. https://scapy.readthedocs.io
# 2. https://stackoverflow.com/questions/25980777/new-to-scapy-trying-to-understand-the-sr

from scapy.all import *

ip = IP(dst="8.8.4.4")
icmp = ICMP()
pkt = ip/icmp

reply = sr1(pkt)
print("ICMP reply ......")
print("Source IP: ", reply[IP].src)
print("Destination IP", reply[IP].dst)
