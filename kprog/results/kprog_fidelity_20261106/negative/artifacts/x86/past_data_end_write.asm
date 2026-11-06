
build-x86/negative/past_data_end_write.native.o:     file format elf64-x86-64


Disassembly of section .text:

0000000000000000 <entry>:
   0:	48 8b 47 08                                     	mov    rax,QWORD PTR [rdi+0x8]
   4:	c6 00 01                                        	mov    BYTE PTR [rax],0x1
   7:	b8 02 00 00 00                                  	mov    eax,0x2
   c:	c3                                              	ret
