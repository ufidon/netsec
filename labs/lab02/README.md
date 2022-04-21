# its454 lectures

course materials and references for its454

## Lab02: SEED 2.0 Packet Sniffing and Spoofing Lab

This lab is revised from [SEED 2.0 Packet Sniffing and Spoofing Lab](https://seedsecuritylabs.org/Labs_20.04/Networking/Sniffing_Spoofing/)

**1. Tasks to be complete:**

Complete Lab Task Set 1: Using Scapy to Sniff and Spoof Packets described in [SEED 2.0 Packet Sniffing and Spoofing Lab](./refs/SniffingSpoofing.pdf):

- [x] Task 1.1(20%, each 10%): Sniffing Packets
  - [x] Task 1.1A.
  - [x] Task 1.1B.
    - [x] (2%)Capture only the ICMP packet
    - [x] (3%)Capture any TCP packet that comes from a particular IP and with a destination port number 23.
    - [x] (5%)Capture packets comes from or to go to a particular subnet. You can pick any subnet, such as 128.230.0.0/16; you should not pick the subnet that your VM is attached to.
- [x] Task 1.2(20%): Spoofing ICMP Packets
- [x] Task 1.3(30%): Traceroute. Select '8.8.4.4' as the target.
- [x] Task 1.4(30%, each 10%): Sniffing and-then Spoofing. Ping the following three IP addresses from the user container
  - [x] ping 1.2.3.4 # a non-existing host on the Internet
  - [x] ping 10.9.0.99 # a non-existing host on the LAN
  - [x] ping 8.8.8.8 # an existing host on the Internet 


**2. Report**

Write a report about the process you complete the tasks in the description, key screen snapshots are needed as evidences. In your report, each task has its own subsection.


**3. Demo video**
* [SEED 2.0 Packet Sniffing and Spoofing Lab - Scapy](https://youtu.be/Qh9BxoCB_Dc)

**4. References**
* [SEED 2.0 Packet Sniffing and Spoofing Lab](https://seedsecuritylabs.org/Labs_20.04/Networking/Sniffing_Spoofing/)
* [BPF filter](https://www.kernel.org/doc/html/latest/networking/filter.html)
  * [cheat sheet](https://www.gigamon.com/content/dam/resource-library/english/guide---cookbook/gu-bpf-reference-guide-gigamon-insight.pdf)
* [scapy](https://scapy.net/)
  * [cheat sheet](https://wiki.sans.blue/Tools/pdfs/ScapyCheatSheet_v0.2.pdf)
* [PROGRAMMING WITH PCAP](https://www.tcpdump.org/pcap.html)
  * [Programming with Libcap - Sniffing the network from our own applicaiton by Luis Martin Garcia.](http://recursos.aldabaknocking.com/libpcapHakin9LuisMartinGarcia.pdf)