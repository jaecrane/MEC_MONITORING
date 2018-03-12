Mobile Edge Cloud Node Monitoring Tool
This project is made for monitoring Node's Virtual Machine; 

Getting Started

1. gcc -o "write name" node_monitor.c

2. ./"write name"

Prerequisites

ubuntu14.04(language - american)

xen 4.1.4
 
Built With

•	C

•	GCC 4.x (most of linux system is already installed)

Versioning

We will version up in April.

Authors

•	Jaehak Lee - Initial work  

License

This project is free license

Acknowledgments

•	This code is made for ‘System SW Development in Mobile Edge Cloud for High-Availability and Low-Power Management’ project (NRF-2017M3C4A7081953)


---------------SIFTP implementation description---------------------------

first, u make the folder -> /etx/xen/dnclabm/chalog (log will be store in this folder, and log store path is static.)

second, this "siftp.exe" must be in the etx/xen/dnclabm.

third, place "the node_monitor.c" into /etc/xen/dnclabm.

*becareful, "siftp.exe" and "node_monitor.c" must be in the same directory.

---------------------------------------------------------------------------
