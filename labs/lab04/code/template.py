# retype following the code in the lab manual to save your time

# Task 1.1 ----------------------------------------------------
#!/usr/bin/env python3
from scapy.all import *

def print_pkt(pkt):
  pkt.show()

# The interface can be found with
# 'docker network ls' in the VM
# or 'ifconfig' in the containner
pkt = sniff(iface='br-c93733e9f913', filter='icmp', prn=print_pkt)  

# Task 1.2 ----------------------------------------------------
from scapy.all import *
a = IP()
a.dst = '10.0.2.3'
b = ICMP()
p = a/b
send(p)

ls(a)

# Task 1.3 ----------------------------------------------------
a = IP()
a.dst = '1.2.3.4'
a.ttl = 3
b = ICMP()
send(a/b)

# Task 1.4 ----------------------------------------------------
# Lookup the code in the lecture