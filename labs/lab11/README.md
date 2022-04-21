# its454 lectures

course materials and references for its454

## Lab11: SEED 2.0 DNS Rebinding Attack Lab

This lab is revised from [SEED 2.0 DNS Rebinding Attack Lab](https://seedsecuritylabs.org/Labs_20.04/Networking/DNS/DNS_Rebinding/)

**1. Tasks to be complete:**

Complete all tasks described in [SEED 2.0 DNS Rebinding Attack Lab](./refs/DNSRebinding.pdf):

- [x] (15%, each 5%) Lab Environment Setup Using Container
  - [x] Container Setup and Commands
  - [x] Configure the User VM
  - [x] Testing the Lab Setup
- [x] (85%)  Launch the Attack on the IoT Device
  - [x]  (25%) Task 1: Understanding the Same-Origin Policy Protection
  - [x]  (30%) Task 2: Defeat the Same-Origin Policy Protection
  - [x]  (30%)Task 3: Launch the Attack


**2. Report**

Write a report about the process you complete the tasks in the description, key screen snapshots are needed as evidences. In your report, each task has its own subsection.


**3. Demo video**
* [SEED 2.0 DNS Rebinding Attack Lab](https://youtu.be/hFw6uPlqN5E)

**4. References**
* This lab is revised from [SEED 2.0 DNS Rebinding Attack Lab](https://seedsecuritylabs.org/Labs_20.04/Networking/DNS/DNS_Rebinding/)
* [tc - show / manipulate traffic control settings](https://man7.org/linux/man-pages/man8/tc.8.html)
* [Reason: CORS header 'Access-Control-Allow-Origin' missing](https://developer.mozilla.org/en-US/docs/Web/HTTP/CORS/Errors/CORSMissingAllowOrigin)
* [Auto reloading python Flask app upon code changes](https://stackoverflow.com/questions/16344756/auto-reloading-python-flask-app-upon-code-changes)
* [405 Method Not Allowed](https://developer.mozilla.org/en-US/docs/Web/HTTP/Status/405)
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
  * [How to test /etc/hosts](https://unix.stackexchange.com/questions/134143/how-to-test-etc-hosts)
  * [nslookup, dig, firefox ignoring /etc/hosts file entries](https://unix.stackexchange.com/questions/212897/nslookup-dig-firefox-ignoring-etc-hosts-file-entries)
    * [nsswitch.conf](https://man7.org/linux/man-pages/man5/nsswitch.conf.5.html)
* [Browsers doesn't see aliases in /etc/hosts](https://unix.stackexchange.com/questions/158419/browsers-doesnt-see-aliases-in-etc-hosts)
  * [How to clear the DNS Cache? ](https://support.opendns.com/hc/en-us/articles/227988627-How-to-clear-the-DNS-Cache-)
  * [Easy Steps to Clear DNS Cache on Windows, Chrome, Firefox and Safari](https://geekflare.com/clear-dns-cache-on-windows-chrome-firefox-and-safari/)
  * [firefox tries to resolve DNS before using /etc/hosts](https://support.mozilla.org/en-US/questions/1197204)
