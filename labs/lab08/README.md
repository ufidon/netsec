# its454 lectures

course materials and references for its454

## Lab08: SEED 2.0 VPN Tunneling Lab - Part II

This lab is revised from [SEED 2.0 VPN Tunneling Lab](https://seedsecuritylabs.org/Labs_20.04/Networking/VPN_Tunnel/)

**1. Tasks to be complete:**

Complete Task 7-9 described in [SEED 2.0 VPN Tunneling Lab](../lab07/refs/VPNTunnel.pdf):

- [ ]  Task 1: Network Setup
  - [ ]  Lab setup
  - [ ]  Shared folder
  - [ ]  Packet sniffing
  - [ ]  Testing
    - [ ] Host U can communicate with VPN Server
    - [ ] VPN Server can communicate with Host V
    - [ ] Host U should not be able to communicate with Host V
    - [ ] Run tcpdump on the router, and sniff the traffic on each of the network. Show that you can capture packets
- [ ] Task 2: Create and Configure TUN Interface
  - [ ]  Task 2.a: Name of the Interface
  - [ ]  Task 2.b: Set up the TUN Interface
  - [ ]  Task 2.c: Read from the TUN Interface
  - [ ]  Task 2.d: Write to the TUN Interface
- [ ]  Task 3: Send the IP Packet to VPN Server Through a Tunnel
  - [ ] The server program tun server.py
  - [ ] Implement the client program tun client.py
  - [ ] Testing
- [ ] Task 4: Set Up the VPN Server
  - [ ]  setup
  - [ ]  Testing
- [ ] Task 5: Handling Traffic in Both Directions
  - [ ]  setup
  - [ ]  Testing
- [ ] Task 6: Tunnel-Breaking Experiment
  - [ ]  setup
  - [ ]  Testing
- [x]  (10%) Task 7: Routing Experiment on Host V
- [x]  (40%) Task 8: VPN Between Private Networks
  - [x]  (20%) setup
  - [x]  (20%) Testing
- [x]   (50%) Task 9: Experiment with the TAP Interface
  - [x]  (25%) setup
  - [x]  (25%) Testing


**2. Report**

Write a report about the process you complete the tasks in the description, key screen snapshots are needed as evidences. In your report, each task has its own subsection.


**3. Demo video**
* [SEED 2.0 VPN Tunneling Lab - Part II](https://youtu.be/xYH-2c6DehI)

**4. References**
* This lab is revised from [SEED 2.0 VPN Tunneling Lab](https://seedsecuritylabs.org/Labs_20.04/Networking/VPN_Tunnel/)
* [Socket Programming in Python](https://realpython.com/python-sockets/)
  * [Network Programming with Python](https://www.studytonight.com/network-programming-in-python/)
* [Python Module Index](https://docs.python.org/3/py-modindex.html)
  * [socket — Low-level networking interface](https://docs.python.org/3/library/socket.html)
  * [fcntl — The fcntl and ioctl system calls](https://docs.python.org/3/library/fcntl.html)
  * [os — Miscellaneous operating system interfaces](https://docs.python.org/3/library/os.html)
  * [struct — Interpret bytes as packed binary data](https://docs.python.org/3/library/struct.html)
  * [time — Time access and conversions](https://docs.python.org/3/library/time.html)
  * [select — Waiting for I/O completion](https://docs.python.org/3/library/select.html)
    * [selectors — High-level I/O multiplexing](https://docs.python.org/3/library/selectors.html)
* [BPF filter](https://www.kernel.org/doc/html/latest/networking/filter.html)
  * [cheat sheet](https://www.gigamon.com/content/dam/resource-library/english/guide---cookbook/gu-bpf-reference-guide-gigamon-insight.pdf)
* [scapy](https://scapy.net/)
  * [cheat sheet](https://wiki.sans.blue/Tools/pdfs/ScapyCheatSheet_v0.2.pdf)
* [Container Networking Is Simple!](https://iximiuz.com/en/posts/container-networking-is-simple/)
  * [docker network](https://docs.docker.com/network/)
  * [How Docker Container Networking Works - Mimic It Using Linux Network Namespaces](https://dev.to/polarbit/how-docker-container-networking-works-mimic-it-using-linux-network-namespaces-9mj)
  * [Deep dive into Linux Networking and Docker — Bridge, vETH and IPTables](https://medium.com/techlog/diving-into-linux-networking-and-docker-bridge-veth-and-iptables-a05eb27b1e72)
* [Relationship between interface “vethxxxxx” and container?](https://forums.docker.com/t/relationship-between-interface-vethxxxxx-and-container/12872/22)
  * [dockerveth](https://github.com/micahculpepper/dockerveth)
  * [Find out which network interface belongs to docker container](https://stackoverflow.com/questions/37860936/find-out-which-network-interface-belongs-to-docker-container)
* [How to capture packages via both eth0 and lo at the same time?](https://stackoverflow.com/questions/41997895/how-to-capture-packages-via-both-eth0-and-lo-at-the-same-time)
* [A tcpdump Tutorial with Examples — 50 Ways to Isolate Traffic](https://danielmiessler.com/study/tcpdump/)
  * [TCPDUMP filters](http://alumni.cs.ucr.edu/~marios/ethereal-tcpdump.pdf)
* [How To Customize Bash Prompt in Linux](https://phoenixnap.com/kb/change-bash-prompt-linux)