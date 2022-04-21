# its454 lectures

course materials and references for its454

## Lab07: SEED 2.0 VPN Tunneling Lab - Part I

This lab is revised from [SEED 2.0 VPN Tunneling Lab](https://seedsecuritylabs.org/Labs_20.04/Networking/VPN_Tunnel/)

**1. Tasks to be complete:**

Complete Task 1-6 described in [SEED 2.0 VPN Tunneling Lab](./refs/VPNTunnel.pdf):

- [x] (10%) Task 1: Network Setup
  - [x] (2%) Lab setup
  - [x] (1%) Shared folder
  - [x] (1%) Packet sniffing
  - [x] (6%) Testing
    - [x] (1%) Host U can communicate with VPN Server
    - [x] (1%) VPN Server can communicate with Host V
    - [x] (1%) Host U should not be able to communicate with Host V
    - [x] (3%) Run tcpdump on the router, and sniff the traffic on each of the network. Show that you can capture packets
- [x] (40%, each 10%)Task 2: Create and Configure TUN Interface
  - [x]  Task 2.a: Name of the Interface
  - [x]  Task 2.b: Set up the TUN Interface
  - [x]  Task 2.c: Read from the TUN Interface
  - [x]  Task 2.d: Write to the TUN Interface
- [x]  (20%)Task 3: Send the IP Packet to VPN Server Through a Tunnel
  - [x]  (5%) The server program tun server.py
  - [x]  (7%) Implement the client program tun client.py
  - [x]  (8%) Testing
- [x]  (10%, each 5%) Task 4: Set Up the VPN Server
  - [x]  setup
  - [x]  Testing
- [x]  (10%, each 5%) Task 5: Handling Traffic in Both Directions
  - [x]  setup
  - [x]  Testing
- [x]  (10%, each 5%) Task 6: Tunnel-Breaking Experiment
  - [x]  setup
  - [x]  Testing
- [ ]  Task 7: Routing Experiment on Host V
  - [ ]  setup
  - [ ]  Testing
- [ ]  Task 8: VPN Between Private Networks
  - [ ]  setup
  - [ ]  Testing
- [ ]   Task 9: Experiment with the TAP Interface
  - [ ]  setup
  - [ ]  Testing


**2. Report**

Write a report about the process you complete the tasks in the description, key screen snapshots are needed as evidences. In your report, each task has its own subsection.


**3. Demo video**
* [SEED 2.0 VPN Tunneling Lab - Part I](https://youtu.be/t_VmiXNWKkk)

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