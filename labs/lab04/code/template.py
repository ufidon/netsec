# the code exerpted from the lab manual to save your time

# Task 3.1 ----------------------------------------------------
# Launching the attack manually
#!/usr/bin/env python3
from scapy.all import *

ip = IP(src="@@@@", dst="@@@@")
tcp = TCP(sport=@@, dport=@@, flags="A", seq=@@@@, ack=@@@@)
data = "@@@@"
pkt = ip/tcp/data
ls(pkt)
send(pkt, iface="eth0", verbose=0)

# Task 3.2 ----------------------------------------------------
#  Launching the attack automatically
# check lecture code

# Task 4 ----------------------------------------------------
#  Launching the attack automatically
# check lecture code