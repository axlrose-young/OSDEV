#include <stdio.h>
#include <tty.h>
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
				case 'x':{
					// does not handle negative numbers
					unsigned int d = va_arg(args,int);
					uint8_t buffer[8] = {0};
					int count = 0;
					while(d > 0) {
						int digit = d % 16;

						if(digit < 10) 
							buffer[count++] = '0' + digit;		
						else {
							digit -= 10;
							buffer[count++] = 'A' + digit; 	
						}
						
						d /= 16;
					}

					while(count--) {
						putchar(buffer[count]);
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
