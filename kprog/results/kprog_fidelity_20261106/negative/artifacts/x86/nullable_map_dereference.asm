
build-x86/negative/nullable_map_dereference.native.o:     file format elf64-x86-64


Disassembly of section .text:

0000000000000000 <entry>:
   0:	48 8b 37                                        	mov    rsi,QWORD PTR [rdi]
   3:	48 8b 47 08                                     	mov    rax,QWORD PTR [rdi+0x8]
   7:	48 8d 56 04                                     	lea    rdx,[rsi+0x4]
   b:	48 39 c2                                        	cmp    rdx,rax
   e:	77 10                                           	ja     20 <entry+0x20>
  10:	48 8b 3d 00 00 00 00                            	mov    rdi,QWORD PTR [rip+0x0]        # 17 <entry+0x17>
			13: R_X86_64_REX_GOTPCRELX	neg_map-0x4
  17:	e8 00 00 00 00                                  	call   1c <entry+0x1c>
			18: R_X86_64_PLT32	bpf_map_lookup_elem-0x4
  1c:	48 8b 00                                        	mov    rax,QWORD PTR [rax]
  1f:	c3                                              	ret
  20:	b8 00 00 00 00                                  	mov    eax,0x0
  25:	c3                                              	ret
