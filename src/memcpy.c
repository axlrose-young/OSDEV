#include <string.h>
#include <stdint.h>

/* __restrict keyword is used when both pointers don't overlap
   hence the compiler can make memory optimizations around it 
   Also provides code clarity */

void* memcpy(void* restrict dst, void* restrict src, size_t size){
	uint8_t* d = (uint8_t*)dst;	
	uint8_t* s = (uint8_t*)src;	
	while(size--){
		*d++ = *s++;
	}
	return dst;
}
