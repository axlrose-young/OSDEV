#if defined(__linux__)
#error "You are not using a cross-compiler"
#endif

#if !defined(__i386__)
#error "Needs to be compiled with a ix86-elf compiler"
#endif

#include <stddef.h>

#include <tty.h>
#include <io.h>
#include <gdt.h>
#include <idt.h>

void 
kernel_main(void)
{
	terminal_init();	
	gdt_init();
	idt_init();

	kprintf("Hello after gdt init\n");
}
