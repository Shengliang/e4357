Total Hours Spent: 1.5/1.5
		   Actual/Expect

Homework#1:

Part I: Software (keep within 30 min)
- Write a c function 
   ex: 

   void *memcpy(void *dest, const void *src, size_t n);
        
   void *malloc(size_t size, size_t alignment_size);
   void free(void *ptr, size_t alignment_size);

   /*
    r = M * r 
         where M is nxn matrix, r is nx1 vector
    */
    void next_rank(double *m, /*input */
                          double *r, /*input and output */
                          int n);
   

Part II: Hardware (discovery keep within 1 hr)
Here is one example:

http://wiki.openwrt.org/toh/d-link/dir-600

http://wiki.openwrt.org/_media/toh/d-link/ar72xx_usb_mod_solder_points.jpg

1. Walk around the house
    - find an unused device with a micro controller inside 
       ex: laptop/desktop/router/modem

2. open it
3. search for major components
    ex: CPU (mips, arm, or x86)
             search datasheet online
              clock frequency
              Data cache size?
              Instruction cache size?
              L1 cache size?
              L2 cache size?

    ex: memory (NOR flash? SPI Interface Flash?)
    ex: RS232 pins (power, ground, tx, rx)
    ex: DDR memory if any
          clk frequency

4. links to datasheet if found in the web
