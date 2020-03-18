# its454
Course materials and demos for labs.

Read the first reference below to understand the configuration files.

## Lab08: e-Mail servers

_Description_
```c
Setup and configure Postfix/Dovecot servers on Ubuntu LTS.
```

_Steps_

```bash
# 1. Purge previous installation and reboot
sudo apt purge dovecot*
sudo rm -rf /var/lib/dovecot
sudo rm -rf /etc/dovecot
sudo apt purge postfix*
sudo apt autoremove
reboot

# 2. Install/configure Postfix/Dovecot

# 2.1 Install postfix: Choose 'Internet Site', System mail name: imail.its454
sudo apt install postfix

# 2.2 Configure Postfix
# Download the three files: main.cf, master.cf and virtual_mailbox_domains from Lab08
# From the folder contains the three files downloaded above, copy them to their destination
sudo cp ./main.cf /etc/postfix/main.cf
sudo cp ./master.cf /etc/postfix/master.cf
sudo cp ./virtual_mailbox_domains /etc/postfix/virtual_mailbox_domains

# convert the file virtual_mailbox_domains to a format that Postfix can understand
sudo postmap /etc/postfix/virtual_mailbox_domains

# 2.3 Install Dovecot
sudo apt install dovecot-core dovecot-imapd dovecot-pop3d dovecot-lmtpd

# 2.4 Configure Dovecot
# Download the files:10-auth.conf, 10-ssl.conf,10-mail.conf,auth-passwdfile.conf.ext, 10-master.conf,  dovecot-users  from Lab08
# From the folder contains the files downloaded above, copy them to their destination
sudo cp ./10-mail.conf /etc/dovecot/conf.d/10-mail.conf
sudo cp ./10-master.conf /etc/dovecot/conf.d/10-master.conf
sudo cp ./10-auth.conf /etc/dovecot/conf.d/10-auth.conf
sudo cp ./auth-passwdfile.conf.ext /etc/dovecot/conf.d/auth-passwdfile.conf.ext
sudo cp ./dovecot-users /etc/dovecot/dovecot-users
sudo cp ./10-ssl.conf /etc/dovecot/conf.d/10-ssl.conf

# 2.5 Create Dovecot vhosts directory
sudo mkdir -p /var/mail/vhosts
sudo mkdir -p /var/mail/vhosts/imail.its454

# 2.6 Creating Dovecot vmail User and Group
sudo groupadd -g 5000 vmail
sudo useradd -r -g vmail -u 5000 vmail -d /var/mail/vhosts -c "virtual mail user"
sudo chown -R vmail:vmail /var/mail/vhosts/

# 2.7 Install certificates
# Download the files: ca.crt,imail.crt,imail.key  from Lab08
# From the folder contains the files downloaded above, copy them to their destination
sudo cp ./ca.crt /etc/ssl/certs/ca.crt
sudo cp ./imail.crt /etc/ssl/certs/imail.crt
sudo cp ./imail.key /etc/ssl/private/imail.key

# check access right and ownership
ls -l /etc/ssl/certs/imail.crt /etc/ssl/certs/ca.crt
# Make sure they look like below, you may use command chown and chmod to adjust
# -rw-r--r-- 1 root root 1489 Mar 17 14:17 /etc/ssl/certs/ca.crt
# -rw-r--r-- 1 root root 4729 Mar 17 14:12 /etc/ssl/certs/imail.crt

sudo ls -l /etc/ssl/private/imail.key
# -rw-r----- 1 root root 1679 Mar  9 17:03 /etc/ssl/private/imail.key

# 2.8 Restart email servers, check that they run successfully
sudo systemctl restart postfix
sudo systemctl restart dovecot
sudo systemctl status postfix
sudo systemctl status dovecot

# 3. Use ThunderBird to access emails
# 3.1 Add ca.crt
# Run ThunderBird, cancel the initial account adding
# From menu: Edit -> Preferences, in the opened tab, choose Advanced -> Certificates,
# click button 'Manage Cerificates', in the pop-up dialog, choose Authorities, 
# click button Import to import ca.crt

# 3.2 Add email accounts
# From menu: Edit -> Account Settings, in the pop-up dialog, at bottom-left, 
# click button Account Actions, add the following two email accounts, 
# fill the following information respectively, click continue, then click done:
# Account 1:
# Your name: Administrator
# Email address: admin@imail.its454
# Password: P@ssw0rd

# Account 2:
# Your name: Email user 1
# Email address: euser1@imail.its454
# Password: P@ssw0rd

# Modify /etc/dovecot/dovecot-users, add your name as one user
# From your account, send an email to the Administrator, cc to euser1
# check that the Administrator and euser1 received your email!

```


_References_
* [How to Set Up an Email Server with Postfix, Dovecot and Roundcube on Ubuntu 18.04](https://www.tekfansworld.com/how-to-set-up-an-email-server-with-postfix-dovecot-and-roundcube-on-ubuntu-18-04.html)
* See references in the lecture


