Part 1:

/*

-------- 4k alignment--------
Expecte time :30 mints
Actual time: 90 mints

Description: If given data is 4K aligned then provide the memory allocation
for the data with 4K alignment of address.

*/

#include <stdio.h>
#include <stdlib.h>

#define FOURKB 4096

void *my_malloc(size_t size, size_t Alignment);

int main(void){

  size_t data_size;
  void *ptd;
  printf(" Please enter size of data to allocate memory or \"Q\" to quit: \n");
  
  while (scanf("%u",&data_size)){
    if(data_size%FOURKB != 0){
      printf(" Data is not aligned \n");
    }
    else {
      ptd = my_malloc(data_size, FOURKB);
      printf("allocated address for the data with 4K alignment is: %u \n",(unsigned int) ptd);
    }
    printf(" Please enter size of data to allocate memory or \"Q\" to quit: \n");
  }//while

} //main

void *my_malloc(size_t size, size_t Alignment){

  void *ptd;
  unsigned int temp_address;
  ptd = malloc(size+Alignment);
  printf("Address of the pointer before the alignment: %u \n", (unsigned int)ptd);
  temp_address = (unsigned int)ptd % Alignment;
  if (temp_address==0)
    return (void *)ptd;
  else
    return (void *)(((unsigned int)ptd)+(Alignment-temp_address));
}





Part II: Hardware (discovery keep within 1 hr)

Expected/actual -- 60 mints/ 60 mints

Device:  Netgear Wireless –G router
Model no:  WGR614 V9
Serial No: 1SV89A72228AD
PCB No: U12H094T00 LF

Component 1: Broadcom chip       Product ID: BCM5354KFBG
http://pdf1.alldatasheet.net/datasheet-pdf/view/175111/BOARDCOM/BCM5354.html

Component 2: ISSI 		Product ID: IC42S16400F-7TL, XA796100W 0930 -- SYNCHRONOUS DYNAMIC RAM 
http://datasheet.octopart.com/IS42S16400F-6TL-ISSI-datasheet-14189613.pdf

Component 3:  74L VCO4AD

Component 4: MX -12G   25L1605DM2I –Serial flash memory 
http://www.datasheetarchive.com/dl/Datasheet-023/DSA00412104.pdf

Component 5: 3 Inductors   0936 –HN2018CG, 0934 HN1618CG

Component 6:  JM56141 – K001-4F  -- Modular  Jack Connector 
http://www.datasheets360.com/pdf/-8257758881768691129
