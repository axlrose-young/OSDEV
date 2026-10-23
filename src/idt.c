#include <stdint.h>

/*
 *  Sets the idt pointer and the table
 *
 */

struct idt_ptr {
	uint16_t size;
	uint32_t offset;
}__attribute__((packed));

struct idt_table {
	uint16_t offset_low;
	uint16_t selector;
	uint8_t reserved;
	uint8_t type;
	uint16_t offset_high;
}__attribute__((packed));

struct idt_table idt[256] = {0};
struct idt_ptr idtr = {0};

void
idt_init(void)
{
	idtr.size = (uint16_t)sizeof(idt) - 1;
	idtr.offset = (uint32_t) idt; 
	asm volatile (
		".intel_syntax noprefix\n"
		"lidt [%0]\n"
		".att_syntax prefix\n"
		: 
		: "r"(&idtr)
		: "memory" 
	);
}

int 
main()
{
	return 0;	
}
