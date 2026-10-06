#include <stdint.h>
#include <stdio.h>

/*  
 * Yet to implement TSS
 */

struct descriptor {
	uint16_t limit_low;
	uint16_t base_low;
	uint8_t base_mid;
	uint8_t accessbyte;
	uint8_t limit_high;
	uint8_t base_high;	
}__attribute__((packed));

struct gdt_ptr {
	uint16_t size;
	uint32_t base;
}__attribute__((packed));

struct descriptor gdt[3];	
struct gdt_ptr gdtr;
extern void gdt_load(struct descriptor*);

void gdt_init() {
	gdt[0] = (struct descriptor){0};

	gdt[1].base_high = 0;
	gdt[1].limit_high = 0xcf; 
	gdt[1].accessbyte = 0x9a; 
	gdt[1].base_mid = 0;
	gdt[1].base_low = 0;
	gdt[1].limit_low = 0xffff; 

	gdt[2].base_high = 0;
	gdt[2].limit_high = 0xcf; 
	gdt[2].accessbyte = 0x92; 
	gdt[2].base_mid = 0;
	gdt[2].base_low = 0;
	gdt[2].limit_low = 0xffff; 

	gdtr.size = sizeof(struct descriptor) - 1;
	gdtr.base = (uint32_t)gdt;

	gdt_load(gdt);	
}

int main() {
	gdt_init();
	for(int i = 0; i < 3; i++) {
		printf("descriptor val: %016llx\n",gdt[i]);
	}

	printf("Address of table %p\n",(void*)&(gdt));
}

