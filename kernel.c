#include <stddef.h>
#include <stdint.h>

#if defined(__linux__)
#error "You are not using a cross-compiler"
#endif

#if !defined(__i386__)
#error "Needs to be compiled with a ix86-elf compiler"
#endif

enum vga_color {
	VGA_COLOR_BLACK = 0,
	VGA_COLOR_BLUE = 1,
	VGA_COLOR_GREEN = 2,
	VGA_COLOR_CYAN = 3,
	VGA_COLOR_RED = 4,
	VGA_COLOR_MAGENTA = 5,
	VGA_COLOR_BROWN = 6,
	VGA_COLOR_LIGHT_GREY = 7,
	VGA_COLOR_DARK_GREY = 8,
	VGA_COLOR_LIGHT_BLUE = 9,
	VGA_COLOR_LIGHT_GREEN = 10,
	VGA_COLOR_LIGHT_CYAN = 11,
	VGA_COLOR_LIGHT_RED = 12,
	VGA_COLOR_LIGHT_MAGENTA = 13,
	VGA_COLOR_LIGHT_BROWN = 14,
	VGA_COLOR_WHITE = 15,
};

/* Helper functions */
size_t len(char* s){
	size_t size = 0;
	while(*s++)
		size++;	
	return size;	
}

uint8_t vga_set_color(enum vga_color bg, enum vga_color fg){
	return fg | bg << 4;	
}

uint16_t vga_entry(char ch, uint8_t color){
	return ch | color << 8; 		
}

#define VGA_WIDTH   80
#define VGA_HEIGHT  25
#define VGA_MEMORY  0xB8000 
	
uint16_t* terminal_buffer = (uint16_t*)VGA_MEMORY;

void terminal_write(char* s, size_t size){
	uint8_t terminal_color = vga_set_color(VGA_COLOR_BLACK, VGA_COLOR_LIGHT_GREY);		 
	for(size_t i = 0; i < size; i++){
		*(terminal_buffer + i) = vga_entry(s[i], terminal_color);
	}	
}

void terminal_writestring(char* s){
	/* extract data and size */		
	size_t size = len(s);
	terminal_write(s, size);
}

void terminal_init(void){
	uint8_t terminal_color = vga_set_color(VGA_COLOR_BLACK, VGA_COLOR_LIGHT_GREY);		 

	for(size_t y = 0; y < VGA_HEIGHT; y++){
		for(size_t x = 0; x < VGA_WIDTH; x++){
			const size_t index = (y*80) + x;	
			*(terminal_buffer + index) = vga_entry(' ', terminal_color);
		}	
	}
}

void kernel_main(void){
	terminal_init();	

	terminal_writestring("Hello World!");
}
