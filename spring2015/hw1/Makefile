CC=arm-none-eabi-gcc 
OBJDUMP=arm-none-eabi-objdump
OBJCOPY=arm-none-eabi-objcopy
#OF=s
OF=3
#OF=0
CFLAGS=-O$(OF) -c -Wall -mcpu=cortex-m3 -mthumb -mlittle-endian 
CFLAGS+=-fomit-frame-pointer -ffunction-sections -fdata-sections
CFLAGS+=-fno-strict-aliasing 
SOURCES=LPC1768.c main.c 
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=LPC1768.elf
BIN=LPC1768.bin

LDFLAGS=-nostartfiles -nostdlib -T LPC1768.ld -Wl,--gc-sections -Wl,--allow-multiple-definition -mcpu=cortex-m3 -mthumb -Wl,-e,Reset_Handler -Wl,-static 

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $(EXECUTABLE)
	$(OBJDUMP) -d $(EXECUTABLE) > $(EXECUTABLE).objdump.$(OF).txt
	$(OBJCOPY) -O binary $(EXECUTABLE) $(BIN).$(OF)

.c.o:
	$(CC) $(CFLAGS)$< -o $@

clean:
	rm $(OBJECTS) $(EXECUTABLE) $(BIN).$(OF)
