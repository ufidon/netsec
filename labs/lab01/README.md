# its454
Course materials and demos for labs


## Lab01: Setup lab environment
**Tasks**

_Description_
```c
In this lab,  setup three virtual machines and put them in a NAT network of VirtualBox:
Windows server and Ubuntu, both use the latest stable versions; as well as SEED VM 16.04.
```

_Steps_

1. Create VMS, NAT network, download ISOs and softwares
2. Setup Windows server, chrome browser
3. Setup Ubuntu & software

```bash
# Inside Ubuntu, open a terminal, run the following commands
sudo apt update
sudo apt upgrade
sudo apt install terminator build-essential git cmake mono-complete
sudo apt install apt-transport-https dirmngr
sudo apt-key adv --keyserver hkp://keyserver.ubuntu.com:80 --recv-keys  3FA7E0328081BFF6A14DA29AA6A19B38D3D831EF
echo "deb https://download.mono-project.com/repo/ubuntu vs-bionic main"  | sudo tee /etc/apt/sources.list.d/mono-official-vs.list
sudo apt update
sudo apt-get install monodevelop openjdk-11-jdk
```
4. download and install SEED VM 16.04

**Where are the OSes and tools?**
  * [VirtualBox 6](https://www.virtualbox.org/)
  * [Ubuntu 18.04LTS](https://ubuntu-mate.org/)
  * [Windows server](https://www.microsoft.com/en-us/cloud-platform/windows-server)
  * [SEED VM](https://seedsecuritylabs.org/)

5. Verify all VMs can ping each other

**Youtube Videos** 
  * [Create empty virtual machines for Ubuntu & Windows Server 2019 in VirtualBox 6](https://youtu.be/3PbnBVNWXpk)
  * [Install Ubuntu 18.04LTS in VirtualBox 6](https://youtu.be/3BHsizTRUg0)
  * [Install Windows Server 2019 in VirtualBox 6](https://youtu.be/fQZFoSTSuPM)
  * [Create SEED Ubuntu 16.04 virtual machines and NAT network](https://youtu.be/pwSlVJSCpu0)
  * [How to run VirtualBox virtual machines on other computers with VirtualBox?](https://youtu.be/Ps30RJ1MzgQ)