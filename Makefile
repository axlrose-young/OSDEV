.PHONY: all kernel libc iso clean

all: kernel

kernel: libc
	$(MAKE) -C kernel

libc: 
	$(MAKE) install -C libc

iso: 
	mkdir -p isodir/boot/grub
	cp kernel/myos isodir/boot/myos
	grub-mkrescue -o myos.iso isodir

clean: 
	$(MAKE) clean -C kernel
	$(MAKE) clean -C libc
	rm -f myos.iso
	
