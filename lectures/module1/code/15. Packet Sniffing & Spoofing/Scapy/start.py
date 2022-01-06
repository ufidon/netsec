#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# How to use scapy?
# Prerequisite:
#  Python3 and scapy
# Usage:
# Scapy can be used in a Python program or in a Python console
# ref: 
# 1. https://scapy.readthedocs.io

# Scapy can be used in a Python program
from scapy.all import *

ip = IP()  # create an ip object with default field values
ip.show() # print out the values of each header field

ls(IP) #  list all the attribute names and their default values
ls(ICMP)
ls(UDP)
ls(TCP)

# or use it interactively in a Python console
