PRE=
CC=$(PRE)gcc
OBJDUMP=$(PRE)objdump
OBJCOPY=$(PRE)objcopy
READELF=$(PRE)readelf
#CFLAG=-g -O3
CFLAG=-O3
all:
	$(CC) $(CFLAG) -c hw1_lib.c -o hw1_lib.o
	$(CC) $(CFLAG) -g -S hw1_lib.c -o hw1_lib.s
	$(CC) $(CFLAG) -g -c hw1_main.c -o hw1_main.o
	$(CC) hw1_main.o hw1_lib.o -o hw1.elf
	file hw1.elf
	$(OBJDUMP) -D hw1.elf > hw1.objdump.txt
	$(OBJCOPY) --gap-fill 0xfe  -O binary hw1.elf hw1.bin
	$(READELF)  -h  hw1.elf 

clean:
	\rm -rf hw1_lib.s hw1.elf hw1.bin hw1_*.o hw1.objdump.txt
