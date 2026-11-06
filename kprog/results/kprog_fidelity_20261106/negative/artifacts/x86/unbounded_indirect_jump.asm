
build-x86/negative/unbounded_indirect_jump.native.o:     file format elf64-x86-64


Disassembly of section .text:

0000000000000000 <entry>:
   0:	48 8b 07                                        	mov    rax,QWORD PTR [rdi]
   3:	ff e0                                           	jmp    rax
