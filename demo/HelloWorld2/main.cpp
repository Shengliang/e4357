/*
 * Enter a hex number [0-9a-fA-F]; Decode it in 4-bit binary format and display them on 4 on board leds.
 *
 * What is the address of ledArr[0]?
 * What is the address of ch?
 *
 */

#include "mbed.h"

Serial pc(USBTX, USBRX); // tx, rx
DigitalOut ledArr[4] = {DigitalOut(LED1), DigitalOut(LED2), DigitalOut(LED3), DigitalOut(LED4)};
Serial uart(p9, p10);

#define dprintf uart.printf

void DisplayLed(int ch)
{
    int i=0;
    if(ch>='0' && ch<='9') ch-='0';
    else if(ch>='A' && ch<='F') { ch-='A'; ch+=10; }
    else if(ch>='a' && ch<='f') { ch-='a'; ch+=10; }
    else {ch=0;}
    for(i=0; i<4; i++) {
        if(ch& (1<<i)) {
            ledArr[i] = 1;
        }
        else {
            ledArr[i] = 0;
        }
    }
}

int main(void) {
    int ch, i, j, sz;
    unsigned int *p;
    pc.baud(115200);
    uart.baud(115200);
    dprintf("\r\nDebug Console!");

    sz = sizeof(ledArr[0])/sizeof(unsigned int);

    while(1) {
        for (i = 0; i < sz; i++) {
            dprintf("\r\n%04x:", i);
            for (j = 0; j < 4; j++) {
                p = (unsigned int *)&ledArr[j];
                dprintf("%08X ", p[i]);
            }
            if (i != 4 && i != 5)
                continue;
                
            dprintf("\r\n%04x:", i);
            for (j = 0; j < 4; j++) {
                p = (unsigned int *)&ledArr[j];
                dprintf("%08X ", *((unsigned int*)p[i]));
            }
        }
        dprintf("\r\n");
        pc.printf("\r\nEnter:");
        ch = pc.getc();
        pc.putc(ch);
        DisplayLed(ch);
    }
}