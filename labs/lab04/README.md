# its454 lectures

course materials and references for its454

## Lab04: SEED 2.0 TCP Attacks Lab - Part II

This lab is revised from [SEED 2.0 TCP Attacks Lab](https://seedsecuritylabs.org/Labs_20.04/Networking/TCP_Attacks/)

**1. Tasks to be complete:**

Complete Task 3-4 described in [SEED 2.0 TCP Attacks Lab](../lab03/refs/TCPAttacks.pdf):

- [ ]  Task 1 : SYN Flooding Attack
  - [ ] Task 1.1 : Launching the Attack Using Python
  - [ ] Task 1.2 : Launch the Attack Using C
  - [ ] Task 1.3 : Enable the SYN Cookie Countermeasure
    - [ ]  Redo Task 1.1
    - [ ]  Redo Task 1.2
- [ ] Task 2 : TCP RST Attacks on telnet Connections
  - [ ]  Launching the attack manually
  -  Launching the attack automatically
- [x] Task 3 (60%): TCP Session Hijacking
  - [x] (30%) Launching the attack manually
  - [x] (30%) Launching the attack automatically
- [x] Task 4 (40%): Creating Reverse Shell using TCP Session Hijacking

**2. Report**

Write a report about the process you complete the tasks in the description, key screen snapshots are needed as evidences. In your report, each task has its own subsection.


**3. Demo video**
* [SEED 2.0 TCP Attacks Lab - Part II](https://youtu.be/ZKY-iGrkKZ8)

**4. References**
* This lab is revised from [SEED 2.0 TCP Attacks Lab](https://seedsecuritylabs.org/Labs_20.04/Networking/TCP_Attacks/)
* [BPF filter](https://www.kernel.org/doc/html/latest/networking/filter.html)
  * [cheat sheet](https://www.gigamon.com/content/dam/resource-library/english/guide---cookbook/gu-bpf-reference-guide-gigamon-insight.pdf)
* [scapy](https://scapy.net/)
  * [cheat sheet](https://wiki.sans.blue/Tools/pdfs/ScapyCheatSheet_v0.2.pdf)
* [PROGRAMMING WITH PCAP](https://www.tcpdump.org/pcap.html)
  * [Programming with Libcap - Sniffing the network from our own applicaiton by Luis Martin Garcia.](http://recursos.aldabaknocking.com/libpcapHakin9LuisMartinGarcia.pdf)
* [Killing tcp connection in linux](https://unix.stackexchange.com/questions/71940/killing-tcp-connection-in-linux/80539)
  * [What are CLOSE_WAIT and TIME_WAIT states?](https://superuser.com/questions/173535/what-are-close-wait-and-time-wait-states)
* [Extracting TCP data with Scapy](https://stackoverflow.com/questions/65370305/extracting-tcp-data-with-scapy)
  * [ scapy get an error TCP payload length #707 ](https://github.com/secdev/scapy/issues/707)