#include <stdio.h>
#include <kernel/tty.h>
#include <stdarg.h>
#include <stddef.h>

void printf(const char* fmt,...){
	va_list args;
	va_start(args,fmt);	
	while(*fmt){
		if(*fmt == '%'){
			fmt++;
			switch(*fmt){
				case 's':{
					char* s = va_arg(args,char*);
					while(*s)
						putchar(*s++);
					break;
				}
				case 'd':{
					int d = va_arg(args,int);
					if(d < 0){
						putchar('-');
						d = -d;
					}
					size_t divisor = 1;
					while(d / divisor > 9){
						divisor *= 10;
					}
					while(divisor > 0){
						putchar(d/divisor + 48);
						d %= divisor;
						divisor /= 10;
					}
					break;
				}
				case '%':{
					putchar('%');
					break;
				}
			}
		}
		else{ 
			putchar(*fmt);
		}
		fmt++;
	}	
	va_end(args);	
} 
