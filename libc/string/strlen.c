#include <string.h>
#include <stddef.h>

size_t strlen(char* s){
	size_t size = 0;	
	while(*s++)
		size++;			
	return size;
}
