# its454 lectures

course materials and references for its454

## Lab09: SEED 2.0 Local DNS Attack Lab

This lab is revised from [SEED 2.0 Local DNS Attack Lab](https://seedsecuritylabs.org/Labs_20.04/Networking/DNS/DNS_Local/)

**1. Tasks to be complete:**

Complete all tasks described in [SEED 2.0 Local DNS Attack Lab](./refs/DNSLocal.pdf):

- [x] (10%, each 5%) Lab Environment Setup Task
  - [x] Get the IP address of ns.attacker32.com
  - [x] Get the IP address of www.example.com.
- [x] (90%, each 18%) The Attack Tasks
  - [x]  Task 1: Directly Spoofing Response to User
  - [x]  Task 2: DNS Cache Poisoning Attack – Spoofing Answers
  - [x]  Task 3: Spoofing NS Records
  - [x]  Task 4: Spoofing NS Records for Another Domain
  - [x]  Task 5: Spoofing Records in the Additional Section


**2. Report**

Write a report about the process you complete the tasks in the description, key screen snapshots are needed as evidences. In your report, each task has its own subsection.


**3. Demo video**
* [SEED 2.0 Local DNS Attack Lab](https://youtu.be/7Phz7s6XES0)
* Optional video:
  * [SEED 2.0 DNS In A Box Lab](https://youtu.be/JyMxhNowBCk)
**4. References**
* This lab is revised from [SEED 2.0 Local DNS Attack Lab](https://seedsecuritylabs.org/Labs_20.04/Networking/DNS/DNS_Local/)
* [tc - show / manipulate traffic control settings](https://man7.org/linux/man-pages/man8/tc.8.html)
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
