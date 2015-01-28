Total Hours Spent: 1.5/1.5
		   Actual/Expect

4357 Embedded Firmware Essentials
- Program Assignment #2

1. Register & Login @ https://developer.mbed.org/

2. https://developer.mbed.org/platforms/mbed-LPC1768/
   - install firmware to your window
   - download LPC1768 schematics and data sheets

3. Export the "Hello World" program offline

   What is the "Entry point address:" of your program?  (hint: using readelf)
   a.	Exporting to uVision
   b.	Exporting to GCC ARM Embedded

   Note: Right Click your program, then select "export ..."

4. binwalk, objdump, nm to Analysis binaries files
   http://binwalk.org/

5. git clone https://github.com/mbedmicro/mbed

Note:
ARM GCC on Ubuntu 14.04 64-bit x86
 https://launchpad.net/~terry.guo/+archive/ubuntu/gcc-arm-embedded
1). sudo apt-get remove binutils-arm-none-eabi gcc-arm-none-eabi
2). sudo add-apt-repository ppa:terry.guo/gcc-arm-embedded
3). sudo apt-get update
4). sudo apt-get install gcc-arm-none-eabi=4.8.4.2014q3-0trusty11
