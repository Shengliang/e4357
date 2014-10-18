/*
 * Ref: http://gcc.gnu.org/onlinedocs/gcc/Function-Attributes.html#Function-Attributes 
 */
#include<stdio.h>

void __attribute__((weak)) a_func(void)
{
	/* Can be implemented by a mainboard */
	printf("I am in %s (weak).\n", __FUNCTION__);
}

void __f () {
	printf("I am in %s\n", __FUNCTION__);
}

void f () __attribute__ ((weak, alias ("__f")));

int main(void) {
	f();	
	a_func();
	return 0;
}
