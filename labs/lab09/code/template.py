#  Task 1: Directly Spoofing Response to User
#!/usr/bin/env python3
from scapy.all import *
import sys

NS_NAME = "example.com"
def spoof_dns(pkt):
  if(DNS in pkt and NS_NAME in pkt[DNS].qd.qname.decode('utf-8')):
    print(pkt.sprintf("{DNS: %IP.src% --> %IP.dst%: %DNS.id%"))

    # complete these constructions
    ip = IP()
    udp = UDP()
    Anssec = DNSRR()
    dns = DNS()
    spoofpkt = ip/udp/dns
    send(spoofpkt)

myFilter = "" # Set the filter
pkt = sniff(iface='br-43d947d991eb', filter=myFilter, prn=spoof_dns)    

