# Sniffing and Spoofing Attacks

│   README.md                
│                            
├───C_sniff                  
│       raw_receiver.c       
│       raw_sender.c         
│       sniff.c              
│       sniff_improved.c     
│       sniff_raw.c          
│       udp_server.c         
│                            
├───C_spoof                  
│       checksum.c           
│       myheader.h           
│       sniff_snoof_udp.c    
│       spoof.c              
│       spoof_icmp.c         
│       spoof_tcp.c          
│       spoof_udp.c          
│       udp_client.c         
│                            
├───Hybrid                   
│       generate_udp.py      
│       send_premade_udp.c   
│                            
└───Scapy                    
        icmp_spoof.py        
        sniff.py             
        sniff_spoof_icmp.py  
        start.py             
        udp_spoof.py         

## references
* [SEED book code](https://github.com/kevin-w-du/BookCode)   
* [wireshark](https://www.wireshark.org/)   
  * [Tcpdump](https://www.tcpdump.org/)  
  * [mitmproxy](https://mitmproxy.org/)
  * [Zed attack proxy](https://www.zaproxy.org/)
  * [netwox](http://ntwox.sourceforge.net/)
    * [Network Toolbox doc](https://web.ecs.syr.edu/~wedu/SCIENS/seed/Labs/Lab_Setup/netw522/netwox-doc_html/)
* [libpcap](https://libpcap.readthedocs.io)
  * [PcapPlusPlus](https://pcapplusplus.github.io/api-docs/)
* [BPF filter](https://www.kernel.org/doc/html/latest/networking/filter.html)
  * [cheat sheet](./Refs/gu-bpf-reference-guide-gigamon-insight.pdf)
* [scapy](https://scapy.net/)
  * [cheat sheet](./Refs/ScapyCheatSheet_v0.2.pdf)
