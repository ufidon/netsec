# its454 lectures

course materials and references for its454

## Lab10: SEED 2.0 The Kaminsky Attack Lab

This lab is revised from [SEED 2.0 The Kaminsky Attack Lab](https://seedsecuritylabs.org/Labs_20.04/Networking/DNS/DNS_Remote/)

**1. Tasks to be complete:**

Complete all tasks described in [SEED 2.0 The Kaminsky Attack Lab](./refs/DNSRemote.pdf):

- [x] (20%, each 10%) Task 1: Lab Environment Setup Task
  - [x] Get the IP address of ns.attacker32.com
  - [x] Get the IP address of www.example.com.
- [x] (80%, each 20%) The Attack Tasks
  - [x]  Task 2: Construct DNS request
  - [x]  Task 3: Spoof DNS replies
  - [x]  Task 4: Launch the Kaminsky attack
  - [x]  Task 5: Result verification

**Note**
* If you see the following cache poisoning result, the attack succeeded COMPLETELY:

```bash
rndc dumpdb -cache && grep attack /var/cache/bind/dump.db 

ns.attacker32.com.	615597	\-AAAA	;-$NXRRSET
; attacker32.com. SOA ns.attacker32.com. admin.attacker32.com. 2008111001 28800 7200 2419200 86400
example.com.		777597	NS	ns.attacker32.com.

```

* If you see the following cache poisoning result, the attack succeeded PARTLY. In this case, please restart the local DNS server container: docker container restart local-dns-server-10.9.0.53

```bash
rndc dumpdb -cache && grep attack /var/cache/bind/dump.db

attacker32.com.		777096	NS	ns13.domaincontrol.com.
ns.attacker32.com.	604896	\-ANY	;-$NXDOMAIN
; attacker32.com. SOA ns13.domaincontrol.com. dns.jomax.net. 2020062300 28800 7200 604800 600
example.com.		690206	NS	ns.attacker32.com.

```
* If you rarely get lucky with attack.c, try using attack-fast.c. Still unlucky, restart the local DNS server container, still unlucky, restart all containers...
* TRY INTERMITTENTLY!
* A stable and reliable attack is still not found, please let me know if you found one.

**2. Report**

Write a report about the process you complete the tasks in the description, key screen snapshots are needed as evidences. In your report, each task has its own subsection.


**3. Demo video**
* [SEED 2.0 The Kaminsky Attack Lab](https://youtu.be/OFrUw9mkXxc)

**4. References**
* This lab is revised from [SEED 2.0 The Kaminsky Attack Lab](https://seedsecuritylabs.org/Labs_20.04/Networking/DNS/DNS_Remote/)
* [tc - show / manipulate traffic control settings](https://man7.org/linux/man-pages/man8/tc.8.html)
* [An Illustrated Guide to the Kaminsky DNS Vulnerability](http://unixwiz.net/techtips/iguide-kaminsky-dns-vuln.html)
* [Domain Name System](https://en.wikipedia.org/wiki/Domain_Name_System)
  * [domains](https://support.google.com/a/topic/3540977)
  * [Online nslookup](https://www.nslookup.io/)
  * [IP Information](https://ipinfo.io/)
* _dns commands_
  * [dig - DNS lookup utility](http://manpages.ubuntu.com/manpages/focal/man1/dig.1.html)
  * [host - DNS lookup utility](http://manpages.ubuntu.com/manpages/focal/man1/host.1.html)
  * [named - Internet domain name server](http://manpages.ubuntu.com/manpages/focal/man8/named.8.html)
    * [rndc - name server control utility](http://manpages.ubuntu.com/manpages/focal/en/man8/rndc.8.html)
  * [delv - DNS lookup and validation utility](http://manpages.ubuntu.com/manpages/focal/man1/delv.1.html)
* [Wireshark imports Hex Dump](https://www.wireshark.org/docs/wsug_html_chunked/ChIOImportSection.html)
