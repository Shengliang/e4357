#include<stdio.h>
void ex1(void) {
  int arr[7] = {1, 2, 3, 4, 5, 6, 7};
  int *p0 = (&arr[0] + 1) ;
  int *p1 = (arr + 1) ;
  int *p2 = (&arr + 1);  //<= Check Compile Warning here!

  printf("sizeof(arr)= %ld\n", sizeof(arr));
  printf("sizeof(arr[0])= %ld\n", sizeof(arr[0]));

  long long x = (((long long) p1) - ((long long) p0));
  printf("%lld\n", x);  
  x = (((long long) p1) - ((long long) p2));
  printf("%lld\n", x);  
}
void ex2(void) {
  typedef int SevenInt[7];
  SevenInt arr = {1,2, 3,4,5,6,7};
  int *p0 = (&arr[0] + 1) ;
  int *p1 = (arr + 1) ;
  SevenInt* p2 = (&arr + 1); //Compile ok.
  printf("sizeof(SevenInt)= %ld\n", sizeof(SevenInt));
  printf("sizeof(int)= %ld\n", sizeof(int));
  printf("sizeof(arr)= %ld\n", sizeof(arr));
  printf("sizeof(arr[0])= %ld\n", sizeof(arr[0]));

  long long x = (((long long) p1) - ((long long) p0));
  printf("%lld\n", x);  
  x = (((long long) p1) - ((long long) p2));
  printf("%lld\n", x);  
}

void ex3(void) {
  int arr[3];
  // Compile ok.
  2[arr] = 6;
  printf("%d\n", arr[2]);
}

int main(void) {
  ex1();
  ex2();
  ex3();
  return 0;
}
