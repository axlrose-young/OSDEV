#include <stdio.h>

#include <kernel/tty.h>

int putchar(int ic){
	char c = (char) ic;		
	terminal_writestring(&c);
	return ic; 
}
