
build-arm64/negative/uninitialized_stack.native.o:     file format elf64-littleaarch64


Disassembly of section .text:

0000000000000000 <entry>:
   0:	f85f83e0 	ldur	x0, [sp, #-8]
   4:	d65f03c0 	ret
