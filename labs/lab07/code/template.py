# Task 2: Create and Configure TUN Interface
# tun.py is inside the volumes folder

# Task 2.c: Read from the TUN Interface
import socket
from struct import pack


while True:
  # Get a packet from the tun interface
  packet = os.read(tun, 2048)
  if packet:
    ip = IP(packet)
    print(ip.summary())

#  Task 2.d: Write to the TUN Interface
# Send out a spoof packet using the tun interface
newip = IP(src='1.2.3.4', dst=ip.src)
newpkt = newip/ip.payload
os.write(tun, bytes(newpkt))

# Task 3: Send the IP Packet to VPN Server Through a Tunnel
# The server program tun server.py

# Implement the client program tun client.py
# Create UDP socket
sock = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)

while True:
  # Get a packet from the tun interface
  packet = os.read(tun, 2048)
  if packet:
    # Send the packet via the tunnel
    sock.sendto(packet, (SERVER_IP, SERVER_PORT))

#  Task 5: Handling Traffic in Both Directions
# We assume that sock and tun file descriptors have already been create

while True:
  # this will block until at least one interface is ready
  ready,_,_ = select.select([sock,tun],[],[])    

  for fd in ready:
    if fd is sock:
      data, (ip,port) = sock.recvfrom(2048)
      pkt = IP(data)
      print("From socket ==>: {} --> {}".format(pkt.src, pkt.dst))
      # ... (code needs to be added by students) ...
    if fd is tun:
      packet = os.read(tun,2048)
      pkt = IP(packet)
      print("From tun ==>: {} --> {}".format(pkt.src, pkt.dst))
      # ... (code needs to be added by students) ...

# Task 9: Experiment with the TAP Interface
tap = os.open("/dev/net/tun", os.O_RDWR)      
ifr = struct.pack('16sH', b'tap%d', IFF_TAP|IFF_NO_PI)
ifname_bytes = fcntl.ioctl(tap, TUNSETIFF, ifr)
ifname = ifname_bytes.decode('UTF-8')[:16].strip("\x00")
...

while True:
  packet = os.read(tap,2048)
  if packet:
    ether = Ether(packet)
    print(ether.summary())


# generate a corresponding ARP reply and write it to the TAP interface.
while True:
  packet = os.read(tun, 2048)
  if packet:
    print("-------------------------------")
    ether = Ether(packet)
    print(ether.summary())

    # Send a spoofed ARP response
    FAKE_MAC = "aa:bb:cc:dd:ee:ff"
    if ARP in ether and ether[ARP].op == 1:
      arp = ether[ARP]
      newether = Ether(dst=ether.src, src=FAKE_MAC)
      newarp = ARP(psrc=arp.pdst, hwsrc=FAKE_MAC, pdst=arp.psrc,hwdst=ether.src, op=2)
      newpkt = newether/newarp

      print("***** Fake response: {}".format(newpkt.summary()))
      os.write(tun, bytes(newpkt))