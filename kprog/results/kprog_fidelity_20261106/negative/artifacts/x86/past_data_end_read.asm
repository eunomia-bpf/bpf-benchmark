
build-x86/negative/past_data_end_read.native.o:     file format elf64-x86-64


Disassembly of section .text:

0000000000000000 <entry>:
   0:	48 8b 47 08                                     	mov    rax,QWORD PTR [rdi+0x8]
   4:	0f b6 00                                        	movzx  eax,BYTE PTR [rax]
   7:	c3                                              	ret
