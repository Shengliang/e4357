Total Hours Spent: 1.5/1.5
		   Actual/Expect

4357 Embedded Firmware Essentials
- Program Assignment #2

1. Login to mbed web site, export the "Hello World" program to all of the following targets. 
   a.	Exporting to uVision 
   b.	Exporting to GCC ARM Embedded 
  
   How many text files and how many lines of text code in the exported offline code package?  
   None
   
   How many binary (library or object) files? 

mkotagiri@ubuntu:~/Downloads$ find . -type f \( -iname "*.o" -o -iname "*.ld" \)./HelloWorld_gcc_arm_lpc1768/mbed/LPC1768/GCC_ARM/LPC1768.ld
./HelloWorld_gcc_arm_lpc1768/mbed/LPC1768/GCC_ARM/core_cm3.o
./HelloWorld_gcc_arm_lpc1768/mbed/LPC1768/GCC_ARM/system_LPC17xx.o
./HelloWorld_gcc_arm_lpc1768/mbed/LPC1768/GCC_ARM/startup_LPC17xx.o
./HelloWorld_gcc_arm_lpc1768/mbed/LPC1768/GCC_ARM/cmsis_nvic.o
./HelloWorld_uvision_lpc1768/mbed/LPC1768/ARM/core_cm3.o
./HelloWorld_uvision_lpc1768/mbed/LPC1768/ARM/system_LPC17xx.o
./HelloWorld_uvision_lpc1768/mbed/LPC1768/ARM/sys.o
./HelloWorld_uvision_lpc1768/mbed/LPC1768/ARM/startup_LPC17xx.o
./HelloWorld_uvision_lpc1768/mbed/LPC1768/ARM/cmsis_nvic.o
mkotagiri@ubuntu:~/Downloads$

            How many files are different between (a) and (b)? (Use linux commands: find, wc, diff) (10 points)
            
mkotagiri@ubuntu:~/Downloads$ diff -r HelloWorld_uvision_lpc1768/ HelloWorld_gcc_arm_lpc1768/
Only in HelloWorld_uvision_lpc1768/: HelloWorld.uvopt
Only in HelloWorld_uvision_lpc1768/: HelloWorld.uvproj
Only in HelloWorld_gcc_arm_lpc1768/: Makefile
Only in HelloWorld_uvision_lpc1768/mbed/LPC1768: ARM
Only in HelloWorld_gcc_arm_lpc1768/mbed/LPC1768: GCC_ARM
 
    What is the "Entry point address:" of your program?  (hint: using readelf)
 
mkotagiri@ubuntu:~/Downloads/HelloWorld_gcc_arm_lpc1768/mbed/LPC1768/GCC_ARM$ readelf -h startup_LPC17xx.o 
ELF Header:
  Magic:   7f 45 4c 46 01 01 01 00 00 00 00 00 00 00 00 00 
  Class:                             ELF32
  Data:                              2's complement, little endian
  Version:                           1 (current)
  OS/ABI:                            UNIX - System V
  ABI Version:                       0
  Type:                              REL (Relocatable file)
  Machine:                           ARM
  Version:                           0x1
  Entry point address:               0x0
  Start of program headers:          0 (bytes into file)
  Start of section headers:          780 (bytes into file)
  Flags:                             0x5000000, Version5 EABI
  Size of this header:               52 (bytes)
  Size of program headers:           0 (bytes)
  Number of program headers:         0
  Size of section headers:           40 (bytes)
  Number of section headers:         13
  Section header string table index: 10
mkotagiri@ubuntu:~/Downloads/HelloWorld_gcc_arm_lpc1768/mbed/LPC1768/GCC_ARM$


