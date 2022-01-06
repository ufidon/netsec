#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# sniff
# sniff packets filtered by the assigned filter
# Prerequisite:
#  Python3 and scapy
# Usage:
# ./sniff.py [BPF filter string] [number of packets to capture]
# if [number of packets to capture] is supplied, [BPF filter string] must be supplied
# default [number of packets to capture] is 5
# default [BPF filter string] is 'icmp'
# Run with sudo, e.g.
# sudo python3 sniff.py
# or make it executable
# chmod +x sniff.py
# then
# sudo ./sniff.py "icmp" 2
#
# ref: 
# 1. https://scapy.readthedocs.io
# 2. https://stackoverflow.com/questions/279561/what-is-the-python-equivalent-of-static-variables-inside-a-function

import os, sys
from scapy.all import *

# filter follows Berkeley Packet Filter(BPF) syntax, the same as in pcap
pktfilter  = 'icmp'

totalpkts = 5 # record
# callback function used in sniff
def print_pkt(pkt): 
   print_pkt.pktcounter += 1   
   print("Captured packet: {}".format(print_pkt.pktcounter))                  
   print("Source IP:", pkt[IP].src)
   print("Destination IP:", pkt[IP].dst)
   print("Protocol:", pkt[IP].proto)
   print("\n")
   if print_pkt.pktcounter == totalpkts:
      exit(0)
print_pkt.pktcounter = 0



if __name__ == "__main__":
   # test code
   if len(sys.argv) >1:
      pktfilter = sys.argv[1]
   if len(sys.argv) >2:
      totalpkts = int(sys.argv[2])

   print("SNIFFING PACKETS.........")
   # prn the callback function
   pkts = sniff(filter=pktfilter,prn=print_pkt)  