#include <stdint.h>

uint64_t gdttable[3];

void gdtsegmentset(int index, uint32_t base, uint32_t limit, uint8_t accessbyte, uint8_t flags) {
	uint64_t descriptor = 0;

	descriptor |= (base >> 24) << 56;
	descriptor |= ((base >> 16) & 0xff) << 32;
	descriptor |= (base & 0xffff) << 16; 

	descriptor |= ((limit >> 16) & 0xf) << 48; 
	descriptor |= (limit & 0xff); 

	descriptor |= accessbyte << 40;
	descriptor |= (flags & 0xf) << 52;

	gdttable[index] = descriptor;
}

int main() {
	gdtsetsegment(0, 0, 0x00000000, 0x00, 0x0);  	// NULL
	gdtsetsegment(1, 0, 0xfffff, 0x9a, 0xc);	// kernel code segment
	gdtsetsegment(2, 0, 0xfffff, 0x92, 0xc);	// kernel data segment 

	for(int i = 0; i < 3; i++) {
		printf("%d\n", gdttable[i]);
	}
}
