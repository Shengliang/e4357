arm-none-eabi-gcc -Os -fomit-frame-pointer -ffunction-sections -fdata-sections -fno-strict-aliasing -Wall -mcpu=cortex-m3 -mthumb -mlittle-endian -c -o main.o main.c
arm-none-eabi-gcc -Os -fomit-frame-pointer -ffunction-sections -fdata-sections -fno-strict-aliasing -Wall -mcpu=cortex-m3 -mthumb -mlittle-endian -c -o LPC1768.o LPC1768.c
arm-none-eabi-gcc -nostartfiles -nostdlib -T LPC1768.ld -Wl,--gc-sections -Wl,--allow-multiple-definition -mcpu=cortex-m3 -mthumb -Wl,-e,Reset_Handler -Wl,-static -o ./LPC1768.elf  LPC1768.o main.o
arm-none-eabi-objdump -d LPC1768.elf > LPC1768.elf.objdump.Os.txt
arm-none-eabi-objcopy -O binary LPC1768.elf LPC1768.bin
