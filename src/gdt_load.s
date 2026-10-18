.section .text
.global gdt_load

gdt_load:
	mov 4(%esp), %eax	# loads gdt ptr which was pushed in gdt.c file 
	lgdt (%eax)		# loads the gdtr with the gdt ptr	
	
set_CR0:
	mov %cr0, %eax 		
	or $0x1, %eax		# Sets last bit to set protected mode
	mov %eax, %cr0
	
far_jump:				# Far jump for protected mode to enable and 
					# Reloading cs register

	ljmp $0x08, $reload_regs 	# Sets cs as 0x08 and jumps
					# ljmp as in GAS AT&T syntax

reload_regs:
	mov $0x10, %ax	
	mov %ax, %ds
	mov %ax, %ss
	mov %ax, %es
	mov %ax, %fs
	mov %ax, %gs
	ret
