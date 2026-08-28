CC := i686-elf-gcc
CFLAGS := -ffreestanding -Wall -Wextra
CPPFLAGS := -D__kernel
LDFLAGS := -T arch/linker.ld -ffreestanding -nostdlib
LIBS := -lgcc

%.o: %.c 
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

%.o: %.s
	$(CC) $(CFLAGS) -c $< -o $@

OBJS := arch/boot.o kernel.o tty.o

myos.bin: $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) $(LIBS) -o $@

all: myos.bin 

clean: 
	rm -f $(OBJS) myos.bin

.PHONY: all clean
