CC = i686-elf-gcc
AR = i686-elf-ar

CFLAGS = -ffreestanding -O2 -Wall -Wextra 
CPPFLAGS = -Iinclude -I../kernel/include

OBJS = \
       string/strlen.o \
       string/memcpy.o \
       stdio/putchar.o

SYSROOT = ../sysroot

string/%.o: string/%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

stdio/%.o: stdio/%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

libk.a: $(OBJS)
	$(AR) rcs $@ $(OBJS)

install: install-headers install-libs

install-headers: 
	mkdir -p $(SYSROOT)/usr/include
	cp -R include/. $(SYSROOT)/usr/include/.

install-libs: libk.a
	mkdir -p $(SYSROOT)/usr/lib
	cp libk.a $(SYSROOT)/usr/lib/

clean: 
	rm -rf $(OBJS) libk.a
