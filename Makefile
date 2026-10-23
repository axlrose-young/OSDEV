.PHONY: all clean run debug

CC=i686-elf-gcc
AS=i686-elf-gcc

CFLAGS= -ffreestanding -O0 -Wall -Wextra -g -Iinclude
ASFLAGS = -Iinclude -g

LDFLAGS= -T linker.ld -ffreestanding -nostdlib -lgcc

OBJS = build/boot.o \
       build/kernel.o \
       build/tty.o \
       build/memcpy.o \
       build/kprintf.o \
       build/putchar.o \
       build/strlen.o \
       build/gdt.o \
       build/gdt_load.o

build/%.o : src/%.c | build
	$(CC) $(CFLAGS) -c $< -o $@ 

build/%.o : src/%.s | build
	$(AS) $(ASFLAGS) -c $< -o $@

myos.bin: $(OBJS) linker.ld
	$(CC) $(LDFLAGS) -o $@ $(OBJS) 

myos.iso: myos.bin
	mkdir -p build/isodir/boot/grub
	cp myos.bin build/isodir/boot/myos.bin 
	cp grub.cfg build/isodir/boot/grub/grub.cfg
	grub-mkrescue -o myos.iso build/isodir

all: myos.iso

build:
	mkdir -p build

clean:
	rm -rf build myos.bin myos.iso

run: myos.iso
	qemu-system-i386 -cdrom myos.iso

debug: myos.iso
	qemu-system-i386 -cdrom myos.iso -s -S -d int -no-reboot
	# -s listens for remote connection on port localhost:1234
	# -S manual gdb usage
	# -d int shows interrupts
	# -no-reboot will stop qemu from rebooting on error

