#include <stdio.h>

#include <kernel/tty.h>

int putchar(int ic){
	char c[2];
	c[0] = (char) ic;		
	c[1] = '\0';
	terminal_writestring(c);
	return ic; 
}
