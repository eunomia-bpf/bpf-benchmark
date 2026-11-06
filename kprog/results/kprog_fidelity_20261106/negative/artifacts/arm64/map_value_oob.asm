
build-arm64/negative/map_value_oob.native.o:     file format elf64-littleaarch64


Disassembly of section .text:

0000000000000000 <entry>:
   0:	f9400001 	ldr	x1, [x0]
   4:	f9400402 	ldr	x2, [x0, #8]
   8:	91001023 	add	x3, x1, #0x4
   c:	eb02007f 	cmp	x3, x2
  10:	540000e8 	b.hi	2c <entry+0x2c>  // b.pmore
  14:	90000000 	adrp	x0, 0 <neg_map>
			14: R_AARCH64_ADR_GOT_PAGE	neg_map
  18:	f9400000 	ldr	x0, [x0]
			18: R_AARCH64_LD64_GOT_LO12_NC	neg_map
  1c:	94000000 	bl	0 <bpf_map_lookup_elem>
			1c: R_AARCH64_CALL26	bpf_map_lookup_elem
  20:	b4000060 	cbz	x0, 2c <entry+0x2c>
  24:	f9400400 	ldr	x0, [x0, #8]
  28:	d65f03c0 	ret
  2c:	d2800000 	mov	x0, #0x0                   	// #0
  30:	d65f03c0 	ret
