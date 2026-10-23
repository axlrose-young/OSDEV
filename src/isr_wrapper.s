.intel_syntax noprefix

.global isr_wrapper
.align 4

isr_wrapper:
	pushad		# pushes all general registers (double word)
	cld		# Clears DF flag for forward string operations

	call isr_handler

	popad
	iret
