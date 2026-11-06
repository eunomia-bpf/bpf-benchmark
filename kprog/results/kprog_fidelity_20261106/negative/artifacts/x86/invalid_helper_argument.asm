
build-x86/negative/invalid_helper_argument.native.o:     file format elf64-x86-64


Disassembly of section .text:

0000000000000000 <entry>:
   0:	48 c7 c7 01 00 00 00                            	mov    rdi,0x1
   7:	48 c7 c6 00 00 00 00                            	mov    rsi,0x0
   e:	e8 00 00 00 00                                  	call   13 <entry+0x13>
			f: R_X86_64_PLT32	bpf_map_lookup_elem-0x4
  13:	c3                                              	ret
