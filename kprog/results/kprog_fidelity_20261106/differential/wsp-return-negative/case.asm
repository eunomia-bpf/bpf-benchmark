
/workspaces/repository/kprog/fidelity/build-arm64/wsp-return-negative.o:     file format elf64-littleaarch64


Disassembly of section .text:

0000000000000000 <entry>:
   0:	52800000 	mov	w0, #0x0                   	// #0
   4:	1100001f 	mov	wsp, w0
   8:	52800040 	mov	w0, #0x2                   	// #2
   c:	d65f03c0 	ret
