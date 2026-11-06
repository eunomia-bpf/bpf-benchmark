
build-x86/negative/map_value_oob.native.o:     file format elf64-x86-64


Disassembly of section .text:

0000000000000000 <entry>:
   0:	48 8b 37                                        	mov    rsi,QWORD PTR [rdi]
   3:	48 8b 47 08                                     	mov    rax,QWORD PTR [rdi+0x8]
   7:	48 8d 56 04                                     	lea    rdx,[rsi+0x4]
   b:	48 39 c2                                        	cmp    rdx,rax
   e:	77 16                                           	ja     26 <entry+0x26>
  10:	48 8b 3d 00 00 00 00                            	mov    rdi,QWORD PTR [rip+0x0]        # 17 <entry+0x17>
			13: R_X86_64_REX_GOTPCRELX	neg_map-0x4
  17:	e8 00 00 00 00                                  	call   1c <entry+0x1c>
			18: R_X86_64_PLT32	bpf_map_lookup_elem-0x4
  1c:	48 85 c0                                        	test   rax,rax
  1f:	74 05                                           	je     26 <entry+0x26>
  21:	48 8b 40 08                                     	mov    rax,QWORD PTR [rax+0x8]
  25:	c3                                              	ret
  26:	b8 00 00 00 00                                  	mov    eax,0x0
  2b:	c3                                              	ret
