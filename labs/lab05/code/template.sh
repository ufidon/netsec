# copied from https://seedsecuritylabs.org/Labs_20.04/Files/Firewall/Firewall.pdf
# to save typing

# Task 1: Implementing a Simple Firewall
# check the code in Labsetup folder and lecture code


# Task 2: Experimenting with Stateless Firewall Rules
# iptables -t <table> -<operation> <chain> <rule> -j <target>
# ---------- -------------------- ------- -----------
# Table Chain Rule Action
##### !!!!! DON'T RUN "iptables -t nat -F" #####

# List all the rules in a table (without line number)
iptables -t nat -L -n
# List all the rules in a table (with line number)
iptables -t filter -L -n --line-numbers
# Delete rule No. 2 in the INPUT chain of the filter table
iptables -t filter -D INPUT 2
# Drop all the incoming packets that satisfy the <rule>
iptables -t filter -A INPUT <rule> -j DROP

# Task 2.A: Protecting the Router
iptables -A INPUT -p icmp --icmp-type echo-request -j ACCEPT
iptables -A OUTPUT -p icmp --icmp-type echo-reply -j ACCEPT
iptables -P OUTPUT DROP # ➙Set default rule for OUTPUT
iptables -P INPUT DROP # ➙Set default rule for INPUT

# Cleanup: restore the filter table
# way 1:
iptables -F
iptables -P OUTPUT ACCEPT
iptables -P INPUT ACCEPT
# way 2:
docker restart <Container ID>

# Task 2.B: Protecting the Internal Network
# add the interface options using "-i xyz" (coming in from the xyz interface) 
# and/or "-o xyz" (going out from the xyz interface).
# find out the interface names via the "ip addr" command
# use the "-p icmp" options to specify the match options related to the ICMP protocol
# run "iptables -p icmp -h" to find out all the ICMP match options.
# The following example drops the ICMP echo request.
iptables -A FORWARD -p icmp --icmp-type echo-request -j DROP

# Task 2.C: Protecting Internal Serve
# protect the TCP servers inside the internal network (192.168.60.0/24).
# use the "-p tcp" options to specify the match options related to the TCP protocol.
# run "iptables -p tcp -h" to find out all the TCP match options.
# The following example allows the TCP packets coming from the interface eth0 if their source port is 5000
iptables -A FORWARD -i eth0 -p tcp --sport 5000 -j ACCEPT

#  Task 3: Connection Tracking and Stateful Firewall
# Task 3.A: Experiment with the Connection Tracking
# check connection tracking information
conntrack -L

#  Task 3.B: Setting Up a Stateful Firewall
# The rule allows TCP packets belonging to an existing connection to pass through.
iptables -A FORWARD -p tcp -m conntrack --ctstate ESTABLISHED,RELATED -j ACCEPT
# rule to accept incoming SYN packet:
iptables -A FORWARD -p tcp -i eth0 --dport 8080 --syn -m conntrack --ctstate NEW -j ACCEPT
# set the default policy on FORWARD to drop everything. This way, if a packet is not
# accepted by the two rules above, they will be dropped.
iptables -P FORWARD DROP

# Task 4: Limiting Network Traffic
# use "iptables -m limit -h" to see the manual
iptables -A FORWARD -s 10.9.0.5 -m limit --limit 10/minute --limit-burst 5 -j ACCEPT
iptables -A FORWARD -s 10.9.0.5 -j DROP

# Task 5: Load Balancing
#  use the statistic module to achieve load balancing
# Using the nth mode (round-robin)
iptables -t nat -A PREROUTING -p udp --dport 8080 \
-m statistic --mode nth --every 3 --packet 0 \
-j DNAT --to-destination 192.168.60.5:8080

# Using the random mode.
iptables -t nat -A PREROUTING -p udp --dport 8080 \
-m statistic --mode random --probability P \
-j DNAT --to-destination 192.168.60.5:8080