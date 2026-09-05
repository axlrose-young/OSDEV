#if defined(__linux__)
#error "You are not using a cross-compiler"
#endif

#if !defined(__i386__)
#error "Needs to be compiled with a ix86-elf compiler"
#endif

#include <stddef.h>
#include <kernel/tty.h>
#include <stdio.h>

void kernel_main(void){
	terminal_init();	

	terminal_writestring("Hello World!\nWhat is your name?\n");
	putchar('a');
	putchar('\n');
	putchar('\n');
	putchar('a');
}
