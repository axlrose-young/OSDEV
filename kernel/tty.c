#include <stddef.h>
#include <stdint.h>

#include <string.h>
#include <kernel/tty.h>

#define VGA_WIDTH   80
#define VGA_HEIGHT  25
#define VGA_MEMORY  0xB8000 
	
uint16_t* terminal_buffer = (uint16_t*)VGA_MEMORY;
static size_t row = 0;
static size_t col = 0;

void terminal_putchar(char ch){
	uint8_t terminal_color = vga_set_color(VGA_COLOR_BLACK, VGA_COLOR_LIGHT_GREY);		 	

	if(ch == '\n'){
		row++;
		col = 0;
		return;
	}

	if(++col > VGA_WIDTH){
		col = 0;
		if(++row > VGA_HEIGHT)
			row = 0;
	}
	size_t index = row*80 + col;	
	*(terminal_buffer + index) = vga_entry(ch, terminal_color);
}

void terminal_write(char* s, size_t size){
	for(size_t i = 0; i < size; i++)
		terminal_putchar(s[i]);	
}

void terminal_writestring(char* s){
	/* extract data and size */		
	size_t size = strlen(s);
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
