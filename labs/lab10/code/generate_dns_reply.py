#!/usr/bin/env python3
from scapy.all import *

# Construct the DNS header and payload
name = 'twysw.example.com'
Qdsec = DNSQR(qname=name)
Anssec = DNSRR(rrname=name, type='A', rdata='1.1.2.2', ttl=259200)
dns = DNS(id=0xAAAA, aa=1, rd=0, qr=1,
qdcount=1, ancount=1, nscount=0, arcount=0,
qd=Qdsec, an=Anssec)
# Construct the IP, UDP headers, and the entire packet
ip = IP(dst='10.0.2.7', src='1.2.3.4', chksum=0)
udp = UDP(dport=33333, sport=53, chksum=0)
pkt = ip/udp/dns
# Save the packet to a file
with open('ip.bin', 'wb') as f:
  f.write(bytes(pkt))