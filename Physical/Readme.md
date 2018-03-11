Mobile Edge Cloud Device Monitoring Tool
This project is made for monitoring end devices; especially, ARM based mobile system.
Getting Started

1.	Compile the .c code with any version of GCC compiler

2.	Run the .py code with root privilege. Inside the code, near .subprocess.check_output, a.out is derived from the compiled .c code. If you assign the output file of .c code, you need to change this part)

3.	In the uploaded version, code is valid for Zynq-7000 & Zynq Ultrascale+ (ZCU102) now.

Prerequisites
Nothing special

Installing
Nothing special
Running the tests
Run the .py code on console or shell exec function of your programming language. The output is string format.
Deployment
By adding some register information and ADC converting function in .c code, you can install and run this code in most of ARM based systems.  
Built With

•	Python 3.x

•	Pip3

•	GCC 4.x (most of linux system is already installed)

Versioning
We will version up in April.
Authors

•	Hanyee Kim - Initial work  
License

This project is free license
Acknowledgments

•	This code is made for ‘System SW Development in Mobile Edge Cloud for High-Availability and Low-Power Management’ project (NRF-2017M3C4A7081953)
