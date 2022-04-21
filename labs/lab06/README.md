# its454 lectures

course materials and references for its454

## Lab06: SEED 2.0 Firewall Exploration Lab - Part II

This lab is revised from [SEED 2.0 Firewall Exploration Lab](https://seedsecuritylabs.org/Labs_20.04/Networking/Firewall/)

**1. Tasks to be complete:**

Complete Task 3-5 described in [SEED 2.0 Firewall Exploration Lab](../lab05/refs/Firewall.pdf):

- [ ] Task 1: Implementing a Simple Firewall
  - [ ] Task 1.A: Implement a Simple Kernel Module
  - [ ] Task 1.B: Implement a Simple Firewall Using Netfilter
    - [ ] 1. Compile the sample code using the provided Makefile
    - [ ] 2. Hook the printInfo function to all of the netfilter hooks
    - [ ] 3. Implement two more hooks to achieve the following:
      - [ ] (1) preventing other computers to ping the VM
      - [ ] (2) preventing other computers to telnet into the VM
- [ ] Task 2: Experimenting with Stateless Firewall Rules
  - [ ] Task 2.A: Protecting the Router
  - [ ] Task 2.B: Protecting the Internal Network
  - [ ] Task 2.C: Protecting Internal Servers
- [x] Task 3 (40%): Connection Tracking and Stateful Firewall
  - [x] Task 3.A (30%, each 10%): Experiment with the Connection Tracking
    - [x] ICMP experiment
    - [x] UDP experiment
    - [x] TCP experiment
  - [x] Task 3.B (10%): Setting Up a Stateful Firewall
- [x] Task 4 (30%): Limiting Network Traffic
- [x] Task 5 (30%, each 15%): Load Balancing
  - [x] (15%) Using the nth mode (round-robin)
  - [x] (15%) Using the random mode


**2. Report**

Write a report about the process you complete the tasks in the description, key screen snapshots are needed as evidences. In your report, each task has its own subsection.


**3. Demo video**
* [SEED 2.0 Firewall Exploration Lab - Part II](https://youtu.be/awYkfbUNzzc)

**4. References**
* This lab is revised from [SEED 2.0 Firewall Exploration Lab](https://seedsecuritylabs.org/Labs_20.04/Networking/Firewall/)
* [netfilter - firewalling, NAT, and packet mangling for Linux](https://www.netfilter.org/) 
  * [Netfilter hooks](https://wiki.nftables.org/wiki-nftables/index.php/Netfilter_hooks)
  * [A Deep Dive into Iptables and Netfilter Architecture](https://www.digitalocean.com/community/tutorials/a-deep-dive-into-iptables-and-netfilter-architecture)
  * [The Linux Kernel Module Programming Guide](https://sysprog21.github.io/lkmpg/)  
* [Iptables Essentials: Common Firewall Rules and Commands](https://www.digitalocean.com/community/tutorials/iptables-essentials-common-firewall-rules-and-commands)
  * [iptables command in Linux with Examples](https://www.geeksforgeeks.org/iptables-command-in-linux-with-examples/)
  * [25 Useful IPtable Firewall Rules Every Linux Administrator Should Know](https://www.tecmint.com/linux-iptables-firewall-rules-examples-commands/)
  * [iptables-cheatsheet](https://gist.github.com/mcastelino/c38e71eb0809d1427a6650d843c42ac2)
* [iptables/ip6tables — administration tool for IPv4/IPv6 packet filtering and NAT](http://manpages.ubuntu.com/manpages/focal/man8/iptables.8.html)
* [Documentation about the netfilter/iptables project](https://www.netfilter.org/documentation/)
* [SSH Tunnel - Local and Remote Port Forwarding Explained With Examples](https://blog.trackets.com/2014/05/17/ssh-tunnel-local-and-remote-port-forwarding-explained-with-examples.html)
  * [SSH Port Forwarding Example](https://www.ssh.com/ssh/tunneling/example)
  * [SSH/OpenSSH/PortForwarding](https://help.ubuntu.com/community/SSH/OpenSSH/PortForwarding)
  * [A Guide to SSH Port Forwarding/Tunnelling](https://www.booleanworld.com/guide-ssh-port-forwarding-tunnelling/)
* [Proxy server](https://en.wikipedia.org/wiki/Proxy_server)
  * [SOCKS](https://en.wikipedia.org/wiki/SOCKS)
  * [Squid: Optimising Web Delivery](http://www.squid-cache.org/)