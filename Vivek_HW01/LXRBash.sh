#! /bin/bash

sudo apt upgrade -y
wget -O /home/vivek/Downloads/lxr.tgz https://sourceforge.net/projects/lxr/files/latest/download
wget -O /home/vivek/Downloads/linux-5.4.tar.xz https://cdn.kernel.org/pub/linux/kernel/v5.x/linux-5.4.16.tar.xz
sudo apt-get install glimpse -y
sudo apt-get install ctags -y
sudo apt-get install apache2 -y
sudo ufw allow in "Apache Full"
cd /home/vivek/
mkdir lxr-source
mkdir lxr-source/v1
cd /home/vivek/Downloads
tar -zxf lxr.tgz
tar -xf linux-5.4.tar.xz 
mv /home/vivek/Downloads/linux-5.4.16 /home/vivek/lxr-source/v1/
mv /home/vivek/Downloads/lxr-2.3.5/ /home/vivek/
mv /home/vivek/lxr-2.3.5/ /home/vivek/lxr/
sudo apt-get install make -y
sudo apt install mysql-server -y
sudo mysql_secure_installation
<<Comment
	N;
	password;
	password;
	y
	y	
	y
	y
Comment
sudo mysql
<<Comment
	ALTER USER 'root'@'localhost' IDENTIFIED WITH mysql_native_password BY 'password';
	FLUSH PRIVILEGES;
	SELECT user,authentication_string,plugin,host FROM mysql.user;
	exit;
Comment
sudo apt install php libapache2-mod-php php-mysql php-cli -y
sudo apt-get install libapache2-mod-perl2 -y
sudo systemctl restart apache2
#NOT REQ sudo perl -MCPAN -e 'install Bundle::DBI'
#NOT REQ sudo perl -MCPAN -e shell {install DBD::mysql}
sudo apt-get install libdbd-mysql-perl -y
sudo apt-get install libdbi-perl -y
sudo apt-get install libfile-mmagic-perl -y
sudo systemctl restart mysql
cd /home/vivek/lxr
./scripts/configure-lxr.pl -vv 
<<Comment
S
No
Shared
enter
enter
enter
mysql
/home/vivek/glimpse_DB
yes
LXR_tree
no
Files
/home/vivek/lxr-source
enter
enter
list
v1
enter
yes
enter
enter
lxr_project
enter
enter
enter
Comment
./custom.d/initdb.sh
<<Comment
	password
	password
Comment
cp custom.d/lxr.conf .
./genxref --url=http://localhost/lxr --version=v1 --checkonly
sudo cp custom.d/apache-lxrserver.conf /etc/apache2/conf-available
sudo a2enconf apache-lxrserver.conf
systemctl reload apache2