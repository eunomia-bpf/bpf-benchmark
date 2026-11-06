
build-arm64/negative/invalid_helper_argument.native.o:     file format elf64-littleaarch64


Disassembly of section .text:

0000000000000000 <entry>:
   0:	d2800020 	mov	x0, #0x1                   	// #1
   4:	d2800001 	mov	x1, #0x0                   	// #0
   8:	94000000 	bl	0 <bpf_map_lookup_elem>
			8: R_AARCH64_CALL26	bpf_map_lookup_elem
   c:	d65f03c0 	ret
