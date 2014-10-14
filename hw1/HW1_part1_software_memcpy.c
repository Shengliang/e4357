//Total time spent: 75 minutes.
//	about 30 minutes for the memcpy function
//	about 45 minutes for misc Google searches on size_t, sizeof, etc.

#include <stdio.h>


//debug print paraphrased from http://stackoverflow.com/questions/1941307/c-debug-print-macros
#define DEBUG 1
#define debug_print(fmt, ...) \
            do { if (DEBUG) fprintf(stderr, fmt, __VA_ARGS__); } while (0)

/* Note: size_t is just a typedef identifier; more portable
	See: http://stackoverflow.com/questions/739727/c-why-isnt-size-t-a-c-keyword
	*/
/* Note also: sizeof(char) always equals 1
	See: http://stackoverflow.com/questions/2215445/are-there-machines-where-sizeofchar-1
	*/
void *memcpy2(void *dest, const void *src, size_t n) {
	size_t counter;
	for (counter = 0; counter < n; counter++) {
		*((char*)dest + counter) = *((char*)src + counter);
	}
	return dest;
}

void printhex(void* ptr, size_t len) {
    int i;
    for (i = 0; i < len; i++) debug_print("%02hhX ", ((char*) ptr)[i]);
    debug_print("%s", "\n");
}

typedef unsigned short mytype_t;

int main()
{
	mytype_t a[5] = { 0, 	100, 	200, 	300, 	400 };
	mytype_t b[5] = { 500, 	500, 	500, 	500, 	500 };
	size_t arraysize = sizeof(a);

	debug_print("%s", "before:\n");
	printhex(a, arraysize);
	printhex(b, arraysize);

	memcpy2(b, a, arraysize);

	debug_print("%s", "after:\n");
	printhex(a, arraysize);
	printhex(b, arraysize);
}
