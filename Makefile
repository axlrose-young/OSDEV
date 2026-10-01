.PHONY: all kernel libc iso clean

all: kernel

kernel: libc
	$(MAKE) -C kernel

libc: 
	$(MAKE) install -C libc

iso: 
	mkdir -p sysroot/boot/grub
	cp kernel/myos sysroot/boot/myos
	grub-mkrescue -o myos.iso sysroot

clean: 
	$(MAKE) clean -C kernel
	$(MAKE) clean -C libc
	rm -f myos.iso
	
