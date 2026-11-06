
build-x86/negative/uninitialized_stack.native.o:     file format elf64-x86-64


Disassembly of section .text:

0000000000000000 <entry>:
   0:	48 8b 44 24 f8                                  	mov    rax,QWORD PTR [rsp-0x8]
   5:	c3                                              	ret
