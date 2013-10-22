/*
 * File: hw1_main.c
 * gcc -c hw1_main.c -o main.o
 * gcc main.o hw1_lib.o -o hw1
 */
#include "hw1_lib.h"

int main(int argc, char* argv[])
{
   uint16_t b, g;
   if (argc != 3) {
     printf("Usage: %s b binary_input\n"
            "       %s g gray_input\n", argv[0], argv[0]);
     return 0;
   }
   if(argv[1][0]=='g') {
       sscanf(argv[2], "%X", &g);
       b = gray_to_binary(g);
       printf("g:%X => b:%X\n", g, b);
   }
   if(argv[1][0]=='b') {
       sscanf(argv[2], "%X",  &b);
       g = binary_to_gray(b);
       printf("b:%X => g:%X\n", b, g);
   }
   return 0;
}

