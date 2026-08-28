#if defined(__linux__)
#error "You are not using a cross-compiler"
#endif

#if !defined(__i386__)
#error "Needs to be compiled with a ix86-elf compiler"
#endif

#include <stdint.h>
#include "tty.h"

void kernel_main(void){
	terminal_init();	

	terminal_writestring("Hello World!\nWhat is your name?");
}
