.intel_syntax noprefix

.section .text
.global gdt_load

gdt_load:
	mov eax, [esp + 4] 	# loads gdt ptr which was pushed in gdt.c file 
	lgdt [eax]		# loads the gdtr with the gdt ptr	
	
.set_CR0:
	mov eax, cr0
	or eax, 0x1		# Sets last bit to set protected mode
	mov cr0, eax		

.far_jump:				# Far jump for protected mode to enable  
					# Reloading cs register

	ljmp 0x08, .reload_regs		# Sets cs as 0x08 and jumps
					# ljmp as in GAS AT&T syntax

.reload_regs:
	mov ax, 0x10		# Moving second index to other registers
	mov ds, ax
	mov ss, ax
	mov es, ax
	mov fs, ax
	mov gs, ax
	ret	
