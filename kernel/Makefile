CC=i686-elf-gcc
AS=i686-elf-as

CFLAGS = -ffreestanding -O2 -Wall -Wextra -I../sysroot/usr/include -Iinclude

OBJS = \
       ../arch/boot.o \
       kernel.o \
       tty.o

myos: $(OBJS) ../sysroot/usr/lib/libk.a
	$(CC) -T ../arch/linker.ld -o myos -ffreestanding -O2 -nostdlib $(OBJS) -lgcc -L../sysroot/usr/lib -lk

../arch/boot.o: ../arch/boot.s
	$(AS) $< -o $@

kernel.o: kernel.c
	$(CC) $(CFLAGS) -c $< -o $@

tty.o: tty.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -rf $(OBJS) myos
