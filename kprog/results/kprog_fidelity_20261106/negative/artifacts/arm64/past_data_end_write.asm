
build-arm64/negative/past_data_end_write.native.o:     file format elf64-littleaarch64


Disassembly of section .text:

0000000000000000 <entry>:
   0:	f9400401 	ldr	x1, [x0, #8]
   4:	52800022 	mov	w2, #0x1                   	// #1
   8:	39000022 	strb	w2, [x1]
   c:	52800040 	mov	w0, #0x2                   	// #2
  10:	d65f03c0 	ret
