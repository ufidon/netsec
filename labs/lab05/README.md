# its454 lectures

course materials and references for its454

## Lab05: SEED 2.0 Firewall Exploration Lab - Part I

This lab is revised from [SEED 2.0 Firewall Exploration Lab](https://seedsecuritylabs.org/Labs_20.04/Networking/Firewall/)

**1. Tasks to be complete:**

Complete Task 1-2 described in [SEED 2.0 Firewall Exploration Lab](./refs/Firewall.pdf):

- [x] Task 1(70%): Implementing a Simple Firewall
  - [x] Task 1.A(10%): Implement a Simple Kernel Module
  - [x] Task 1.B(60%, each 20%): Implement a Simple Firewall Using Netfilter
    - [x] 1.(20%) Compile the sample code using the provided Makefile
    - [x] 2.(20%) Hook the printInfo function to all of the netfilter hooks
    - [x] 3.(20%, each 10%) Implement two more hooks to achieve the following:
      - [x] (1, 10%) preventing other computers to ping the VM
      - [x] (2, 10%) preventing other computers to telnet into the VM
- [x] Task 2 (30%, each 10%): Experimenting with Stateless Firewall Rules
  - [x] Task 2.A(10%): Protecting the Router
  - [x] Task 2.B(10%): Protecting the Internal Network
  - [x] Task 2.C(10%): Protecting Internal Servers
- [ ] Task 3: Connection Tracking and Stateful Firewall
  - [ ] Task 3.A: Experiment with the Connection Tracking
    - [ ] ICMP experiment:
    - [ ] UDP experiment
    - [ ] TCP experiment
  - [ ] Task 3.B: Setting Up a Stateful Firewall
- [ ] Task 4: Limiting Network Traffic
- [ ] Task 5: Load Balancing
  - [ ] Using the nth mode (round-robin)
  - [ ] Using the random mode


**2. Report**

Write a report about the process you complete the tasks in the description, key screen snapshots are needed as evidences. In your report, each task has its own subsection.


**3. Demo video**
* [SEED 2.0 Firewall Exploration Lab - Part I](https://youtu.be/kUytcBHaLHs)

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