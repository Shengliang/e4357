Total Hours Spent: 1.5/1.5
		   Actual/Expect

Homework#1:

Part I: C Programming (keep within 30 min)
- Implement one c function
   ex:
   uint16_t gray_to_binary(uint16_t gray);
   uint16_t binary_to_gray(uint16_t binary);
   void *memcpy(void *dest, const void *src, size_t n);
   void *malloc(size_t size, size_t alignment_size);
   void free(void *ptr, size_t alignment_size);

   /*
    * r' = m * r
    * where m is nxn matrix, r is nx1 vector
    * @param m, a double pointer to a flat 2-dim array
    * { r0c0, r0c1, ..., r0c[n-1],
    *   r1c0, r1c1, ..., r1c[n-1],
    *    ...
    *   r[n-1]c0, r[n-1]c1, ..., r[n-1]c[n-1]
    * }
    * @param r, a double pointer to a 1-dim array
    */
    void next_rank(double *m, /*input */
                   double *r, /*input and output */
                   int n);

Part II: Hardware (discovery keep within 1 hr)
Here is one example:
http://wiki.openwrt.org/toh/d-link/dir-600
http://wiki.openwrt.org/_media/toh/d-link/ar72xx_usb_mod_solder_points.jpg

1. find a device with a micro controller
      (that you bought before)

2. find hardware datasheets of major components in the device
    search for major components
    ex: CPU (mips, arm, or x86)
	|- hardware datasheet
	|- clock frequency
	|- power source, voltage and current

    ex: memory (NOR flash? SPI Interface Flash?)
    ex: RS232 pins (power, ground, tx, rx)
    ex: DDR memory if any
          clk frequency

3. find a firmware SDKs if any

4. find prices info
     |- price at the time you bought
     |- price on today's market

5. write a short summary includes links to datasheets and SDKs if any
