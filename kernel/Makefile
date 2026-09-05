CC=i686-elf-gcc
AS=i686-elf-as

CFLAGS = -ffreestanding -O2 -Wall -Wextra 
CPPFLAGS = -I../sysroot/usr/include -Iinclude

OBJS = \
       ../arch/boot.o \
       kernel.o \
       tty.o

myos: $(OBJS) ../sysroot/usr/lib/libk.a
	$(CC) -T ../arch/linker.ld -o myos -ffreestanding -O2 -nostdlib $(OBJS) -lgcc -L../sysroot/usr/lib -lk

../arch/boot.o: ../arch/boot.s
	$(AS) $< -o $@

%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

clean: 
	rm -rf $(OBJS) myos
