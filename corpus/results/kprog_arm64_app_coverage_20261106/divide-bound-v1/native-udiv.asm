
corpus/results/kprog_arm64_app_coverage_20261106/divide-bound-v1/native/divide_same_preserved.native.o:     file format elf64-littleaarch64


Disassembly of section .text:

0000000000000000 <entry>:
   0:	f9400013 	ldr	x19, [x0]
   4:	f9400402 	ldr	x2, [x0, #8]
   8:	91002263 	add	x3, x19, #0x8
   c:	eb02007f 	cmp	x3, x2
  10:	540001e8 	b.hi	4c <entry+0x4c>  // b.pmore
  14:	d29fffe5 	mov	x5, #0xffff                	// #65535
  18:	f2bfffe5 	movk	x5, #0xffff, lsl #16
  1c:	f2dfffe5 	movk	x5, #0xffff, lsl #32
  20:	f2ffffe5 	movk	x5, #0xffff, lsl #48
  24:	d29fffe6 	mov	x6, #0xffff                	// #65535
  28:	f2bfffe6 	movk	x6, #0xffff, lsl #16
  2c:	f2dfffe6 	movk	x6, #0xffff, lsl #32
  30:	f2ffffe6 	movk	x6, #0xffff, lsl #48
  34:	eb0500bf 	cmp	x5, x5
  38:	9ac608a5 	udiv	x5, x5, x6
  3c:	54000081 	b.ne	4c <entry+0x4c>  // b.any
  40:	f9000265 	str	x5, [x19]
  44:	52800040 	mov	w0, #0x2                   	// #2
  48:	d65f03c0 	ret
  4c:	52800000 	mov	w0, #0x0                   	// #0
  50:	d65f03c0 	ret

corpus/results/kprog_arm64_app_coverage_20261106/divide-bound-v1/native/divide_same_stripped.native.o:     file format elf64-littleaarch64


Disassembly of section .text:

0000000000000000 <entry>:
   0:	f9400013 	ldr	x19, [x0]
   4:	f9400402 	ldr	x2, [x0, #8]
   8:	91002263 	add	x3, x19, #0x8
   c:	eb02007f 	cmp	x3, x2
  10:	540001e8 	b.hi	4c <entry+0x4c>  // b.pmore
  14:	d29fffe5 	mov	x5, #0xffff                	// #65535
  18:	f2bfffe5 	movk	x5, #0xffff, lsl #16
  1c:	f2dfffe5 	movk	x5, #0xffff, lsl #32
  20:	f2ffffe5 	movk	x5, #0xffff, lsl #48
  24:	d29fffe6 	mov	x6, #0xffff                	// #65535
  28:	f2bfffe6 	movk	x6, #0xffff, lsl #16
  2c:	f2dfffe6 	movk	x6, #0xffff, lsl #32
  30:	f2ffffe6 	movk	x6, #0xffff, lsl #48
  34:	eb0500bf 	cmp	x5, x5
  38:	9ac608a5 	udiv	x5, x5, x6
  3c:	54000081 	b.ne	4c <entry+0x4c>  // b.any
  40:	f9000265 	str	x5, [x19]
  44:	52800040 	mov	w0, #0x2                   	// #2
  48:	d65f03c0 	ret
  4c:	52800000 	mov	w0, #0x0                   	// #0
  50:	d65f03c0 	ret

corpus/results/kprog_arm64_app_coverage_20261106/divide-bound-v1/native/divide_walias_preserved.native.o:     file format elf64-littleaarch64


Disassembly of section .text:

0000000000000000 <entry>:
   0:	f9400013 	ldr	x19, [x0]
   4:	f9400402 	ldr	x2, [x0, #8]
   8:	91002263 	add	x3, x19, #0x8
   c:	eb02007f 	cmp	x3, x2
  10:	540001e8 	b.hi	4c <entry+0x4c>  // b.pmore
  14:	d29fffe5 	mov	x5, #0xffff                	// #65535
  18:	f2bfffe5 	movk	x5, #0xffff, lsl #16
  1c:	f2c00005 	movk	x5, #0x0, lsl #32
  20:	f2e00005 	movk	x5, #0x0, lsl #48
  24:	d2800066 	mov	x6, #0x3                   	// #3
  28:	f2a00006 	movk	x6, #0x0, lsl #16
  2c:	f2c00006 	movk	x6, #0x0, lsl #32
  30:	f2e00006 	movk	x6, #0x0, lsl #48
  34:	eb0500bf 	cmp	x5, x5
  38:	1ac608a6 	udiv	w6, w5, w6
  3c:	54000081 	b.ne	4c <entry+0x4c>  // b.any
  40:	f9000266 	str	x6, [x19]
  44:	52800040 	mov	w0, #0x2                   	// #2
  48:	d65f03c0 	ret
  4c:	52800000 	mov	w0, #0x0                   	// #0
  50:	d65f03c0 	ret

corpus/results/kprog_arm64_app_coverage_20261106/divide-bound-v1/native/divide_walias_stripped.native.o:     file format elf64-littleaarch64


Disassembly of section .text:

0000000000000000 <entry>:
   0:	f9400013 	ldr	x19, [x0]
   4:	f9400402 	ldr	x2, [x0, #8]
   8:	91002263 	add	x3, x19, #0x8
   c:	eb02007f 	cmp	x3, x2
  10:	540001e8 	b.hi	4c <entry+0x4c>  // b.pmore
  14:	d29fffe5 	mov	x5, #0xffff                	// #65535
  18:	f2bfffe5 	movk	x5, #0xffff, lsl #16
  1c:	f2c00005 	movk	x5, #0x0, lsl #32
  20:	f2e00005 	movk	x5, #0x0, lsl #48
  24:	d2800066 	mov	x6, #0x3                   	// #3
  28:	f2a00006 	movk	x6, #0x0, lsl #16
  2c:	f2c00006 	movk	x6, #0x0, lsl #32
  30:	f2e00006 	movk	x6, #0x0, lsl #48
  34:	eb0500bf 	cmp	x5, x5
  38:	1ac608a6 	udiv	w6, w5, w6
  3c:	54000081 	b.ne	4c <entry+0x4c>  // b.any
  40:	f9000266 	str	x6, [x19]
  44:	52800040 	mov	w0, #0x2                   	// #2
  48:	d65f03c0 	ret
  4c:	52800000 	mov	w0, #0x0                   	// #0
  50:	d65f03c0 	ret

corpus/results/kprog_arm64_app_coverage_20261106/divide-bound-v1/native/divide_wtrunc_preserved.native.o:     file format elf64-littleaarch64


Disassembly of section .text:

0000000000000000 <entry>:
   0:	f9400013 	ldr	x19, [x0]
   4:	f9400402 	ldr	x2, [x0, #8]
   8:	91002263 	add	x3, x19, #0x8
   c:	eb02007f 	cmp	x3, x2
  10:	540001e8 	b.hi	4c <entry+0x4c>  // b.pmore
  14:	d28004a5 	mov	x5, #0x25                  	// #37
  18:	f2a00005 	movk	x5, #0x0, lsl #16
  1c:	f2c00025 	movk	x5, #0x1, lsl #32
  20:	f2e00005 	movk	x5, #0x0, lsl #48
  24:	d2800006 	mov	x6, #0x0                   	// #0
  28:	f2a00006 	movk	x6, #0x0, lsl #16
  2c:	f2c00026 	movk	x6, #0x1, lsl #32
  30:	f2e00006 	movk	x6, #0x0, lsl #48
  34:	eb0500bf 	cmp	x5, x5
  38:	1ac608a5 	udiv	w5, w5, w6
  3c:	54000081 	b.ne	4c <entry+0x4c>  // b.any
  40:	f9000265 	str	x5, [x19]
  44:	52800040 	mov	w0, #0x2                   	// #2
  48:	d65f03c0 	ret
  4c:	52800000 	mov	w0, #0x0                   	// #0
  50:	d65f03c0 	ret

corpus/results/kprog_arm64_app_coverage_20261106/divide-bound-v1/native/divide_wtrunc_stripped.native.o:     file format elf64-littleaarch64


Disassembly of section .text:

0000000000000000 <entry>:
   0:	f9400013 	ldr	x19, [x0]
   4:	f9400402 	ldr	x2, [x0, #8]
   8:	91002263 	add	x3, x19, #0x8
   c:	eb02007f 	cmp	x3, x2
  10:	540001e8 	b.hi	4c <entry+0x4c>  // b.pmore
  14:	d28004a5 	mov	x5, #0x25                  	// #37
  18:	f2a00005 	movk	x5, #0x0, lsl #16
  1c:	f2c00025 	movk	x5, #0x1, lsl #32
  20:	f2e00005 	movk	x5, #0x0, lsl #48
  24:	d2800006 	mov	x6, #0x0                   	// #0
  28:	f2a00006 	movk	x6, #0x0, lsl #16
  2c:	f2c00026 	movk	x6, #0x1, lsl #32
  30:	f2e00006 	movk	x6, #0x0, lsl #48
  34:	eb0500bf 	cmp	x5, x5
  38:	1ac608a5 	udiv	w5, w5, w6
  3c:	54000081 	b.ne	4c <entry+0x4c>  // b.any
  40:	f9000265 	str	x5, [x19]
  44:	52800040 	mov	w0, #0x2                   	// #2
  48:	d65f03c0 	ret
  4c:	52800000 	mov	w0, #0x0                   	// #0
  50:	d65f03c0 	ret

corpus/results/kprog_arm64_app_coverage_20261106/divide-bound-v1/native/divide_wupper_preserved.native.o:     file format elf64-littleaarch64


Disassembly of section .text:

0000000000000000 <entry>:
   0:	f9400013 	ldr	x19, [x0]
   4:	f9400402 	ldr	x2, [x0, #8]
   8:	91002263 	add	x3, x19, #0x8
   c:	eb02007f 	cmp	x3, x2
  10:	540001e8 	b.hi	4c <entry+0x4c>  // b.pmore
  14:	d28004a5 	mov	x5, #0x25                  	// #37
  18:	f2a00005 	movk	x5, #0x0, lsl #16
  1c:	f2c00025 	movk	x5, #0x1, lsl #32
  20:	f2e00005 	movk	x5, #0x0, lsl #48
  24:	d2800066 	mov	x6, #0x3                   	// #3
  28:	f2a00006 	movk	x6, #0x0, lsl #16
  2c:	f2c00026 	movk	x6, #0x1, lsl #32
  30:	f2e00006 	movk	x6, #0x0, lsl #48
  34:	eb0500bf 	cmp	x5, x5
  38:	1ac608a5 	udiv	w5, w5, w6
  3c:	54000081 	b.ne	4c <entry+0x4c>  // b.any
  40:	f9000265 	str	x5, [x19]
  44:	52800040 	mov	w0, #0x2                   	// #2
  48:	d65f03c0 	ret
  4c:	52800000 	mov	w0, #0x0                   	// #0
  50:	d65f03c0 	ret

corpus/results/kprog_arm64_app_coverage_20261106/divide-bound-v1/native/divide_wupper_stripped.native.o:     file format elf64-littleaarch64


Disassembly of section .text:

0000000000000000 <entry>:
   0:	f9400013 	ldr	x19, [x0]
   4:	f9400402 	ldr	x2, [x0, #8]
   8:	91002263 	add	x3, x19, #0x8
   c:	eb02007f 	cmp	x3, x2
  10:	540001e8 	b.hi	4c <entry+0x4c>  // b.pmore
  14:	d28004a5 	mov	x5, #0x25                  	// #37
  18:	f2a00005 	movk	x5, #0x0, lsl #16
  1c:	f2c00025 	movk	x5, #0x1, lsl #32
  20:	f2e00005 	movk	x5, #0x0, lsl #48
  24:	d2800066 	mov	x6, #0x3                   	// #3
  28:	f2a00006 	movk	x6, #0x0, lsl #16
  2c:	f2c00026 	movk	x6, #0x1, lsl #32
  30:	f2e00006 	movk	x6, #0x0, lsl #48
  34:	eb0500bf 	cmp	x5, x5
  38:	1ac608a5 	udiv	w5, w5, w6
  3c:	54000081 	b.ne	4c <entry+0x4c>  // b.any
  40:	f9000265 	str	x5, [x19]
  44:	52800040 	mov	w0, #0x2                   	// #2
  48:	d65f03c0 	ret
  4c:	52800000 	mov	w0, #0x0                   	// #0
  50:	d65f03c0 	ret

corpus/results/kprog_arm64_app_coverage_20261106/divide-bound-v1/native/divide_wz_preserved.native.o:     file format elf64-littleaarch64


Disassembly of section .text:

0000000000000000 <entry>:
   0:	f9400013 	ldr	x19, [x0]
   4:	f9400402 	ldr	x2, [x0, #8]
   8:	91002263 	add	x3, x19, #0x8
   c:	eb02007f 	cmp	x3, x2
  10:	540001e8 	b.hi	4c <entry+0x4c>  // b.pmore
  14:	d28004a5 	mov	x5, #0x25                  	// #37
  18:	f2a00005 	movk	x5, #0x0, lsl #16
  1c:	f2c00005 	movk	x5, #0x0, lsl #32
  20:	f2e00005 	movk	x5, #0x0, lsl #48
  24:	d2800006 	mov	x6, #0x0                   	// #0
  28:	f2a00006 	movk	x6, #0x0, lsl #16
  2c:	f2c00006 	movk	x6, #0x0, lsl #32
  30:	f2e00006 	movk	x6, #0x0, lsl #48
  34:	eb0500bf 	cmp	x5, x5
  38:	1ac608a5 	udiv	w5, w5, w6
  3c:	54000081 	b.ne	4c <entry+0x4c>  // b.any
  40:	f9000265 	str	x5, [x19]
  44:	52800040 	mov	w0, #0x2                   	// #2
  48:	d65f03c0 	ret
  4c:	52800000 	mov	w0, #0x0                   	// #0
  50:	d65f03c0 	ret

corpus/results/kprog_arm64_app_coverage_20261106/divide-bound-v1/native/divide_wz_stripped.native.o:     file format elf64-littleaarch64


Disassembly of section .text:

0000000000000000 <entry>:
   0:	f9400013 	ldr	x19, [x0]
   4:	f9400402 	ldr	x2, [x0, #8]
   8:	91002263 	add	x3, x19, #0x8
   c:	eb02007f 	cmp	x3, x2
  10:	540001e8 	b.hi	4c <entry+0x4c>  // b.pmore
  14:	d28004a5 	mov	x5, #0x25                  	// #37
  18:	f2a00005 	movk	x5, #0x0, lsl #16
  1c:	f2c00005 	movk	x5, #0x0, lsl #32
  20:	f2e00005 	movk	x5, #0x0, lsl #48
  24:	d2800006 	mov	x6, #0x0                   	// #0
  28:	f2a00006 	movk	x6, #0x0, lsl #16
  2c:	f2c00006 	movk	x6, #0x0, lsl #32
  30:	f2e00006 	movk	x6, #0x0, lsl #48
  34:	eb0500bf 	cmp	x5, x5
  38:	1ac608a5 	udiv	w5, w5, w6
  3c:	54000081 	b.ne	4c <entry+0x4c>  // b.any
  40:	f9000265 	str	x5, [x19]
  44:	52800040 	mov	w0, #0x2                   	// #2
  48:	d65f03c0 	ret
  4c:	52800000 	mov	w0, #0x0                   	// #0
  50:	d65f03c0 	ret

corpus/results/kprog_arm64_app_coverage_20261106/divide-bound-v1/native/divide_xalias_preserved.native.o:     file format elf64-littleaarch64


Disassembly of section .text:

0000000000000000 <entry>:
   0:	f9400013 	ldr	x19, [x0]
   4:	f9400402 	ldr	x2, [x0, #8]
   8:	91002263 	add	x3, x19, #0x8
   c:	eb02007f 	cmp	x3, x2
  10:	540001e8 	b.hi	4c <entry+0x4c>  // b.pmore
  14:	d29fffe5 	mov	x5, #0xffff                	// #65535
  18:	f2bfffe5 	movk	x5, #0xffff, lsl #16
  1c:	f2dfffe5 	movk	x5, #0xffff, lsl #32
  20:	f2ffffe5 	movk	x5, #0xffff, lsl #48
  24:	d2800066 	mov	x6, #0x3                   	// #3
  28:	f2a00006 	movk	x6, #0x0, lsl #16
  2c:	f2c00006 	movk	x6, #0x0, lsl #32
  30:	f2e00006 	movk	x6, #0x0, lsl #48
  34:	eb0500bf 	cmp	x5, x5
  38:	9ac608a6 	udiv	x6, x5, x6
  3c:	54000081 	b.ne	4c <entry+0x4c>  // b.any
  40:	f9000266 	str	x6, [x19]
  44:	52800040 	mov	w0, #0x2                   	// #2
  48:	d65f03c0 	ret
  4c:	52800000 	mov	w0, #0x0                   	// #0
  50:	d65f03c0 	ret

corpus/results/kprog_arm64_app_coverage_20261106/divide-bound-v1/native/divide_xalias_stripped.native.o:     file format elf64-littleaarch64


Disassembly of section .text:

0000000000000000 <entry>:
   0:	f9400013 	ldr	x19, [x0]
   4:	f9400402 	ldr	x2, [x0, #8]
   8:	91002263 	add	x3, x19, #0x8
   c:	eb02007f 	cmp	x3, x2
  10:	540001e8 	b.hi	4c <entry+0x4c>  // b.pmore
  14:	d29fffe5 	mov	x5, #0xffff                	// #65535
  18:	f2bfffe5 	movk	x5, #0xffff, lsl #16
  1c:	f2dfffe5 	movk	x5, #0xffff, lsl #32
  20:	f2ffffe5 	movk	x5, #0xffff, lsl #48
  24:	d2800066 	mov	x6, #0x3                   	// #3
  28:	f2a00006 	movk	x6, #0x0, lsl #16
  2c:	f2c00006 	movk	x6, #0x0, lsl #32
  30:	f2e00006 	movk	x6, #0x0, lsl #48
  34:	eb0500bf 	cmp	x5, x5
  38:	9ac608a6 	udiv	x6, x5, x6
  3c:	54000081 	b.ne	4c <entry+0x4c>  // b.any
  40:	f9000266 	str	x6, [x19]
  44:	52800040 	mov	w0, #0x2                   	// #2
  48:	d65f03c0 	ret
  4c:	52800000 	mov	w0, #0x0                   	// #0
  50:	d65f03c0 	ret

corpus/results/kprog_arm64_app_coverage_20261106/divide-bound-v1/native/divide_xfull_preserved.native.o:     file format elf64-littleaarch64


Disassembly of section .text:

0000000000000000 <entry>:
   0:	f9400013 	ldr	x19, [x0]
   4:	f9400402 	ldr	x2, [x0, #8]
   8:	91002263 	add	x3, x19, #0x8
   c:	eb02007f 	cmp	x3, x2
  10:	540001e8 	b.hi	4c <entry+0x4c>  // b.pmore
  14:	d29fffe5 	mov	x5, #0xffff                	// #65535
  18:	f2bfffe5 	movk	x5, #0xffff, lsl #16
  1c:	f2dfffe5 	movk	x5, #0xffff, lsl #32
  20:	f2ffffe5 	movk	x5, #0xffff, lsl #48
  24:	d2800066 	mov	x6, #0x3                   	// #3
  28:	f2a00006 	movk	x6, #0x0, lsl #16
  2c:	f2c00006 	movk	x6, #0x0, lsl #32
  30:	f2e00006 	movk	x6, #0x0, lsl #48
  34:	eb0500bf 	cmp	x5, x5
  38:	9ac608a5 	udiv	x5, x5, x6
  3c:	54000081 	b.ne	4c <entry+0x4c>  // b.any
  40:	f9000265 	str	x5, [x19]
  44:	52800040 	mov	w0, #0x2                   	// #2
  48:	d65f03c0 	ret
  4c:	52800000 	mov	w0, #0x0                   	// #0
  50:	d65f03c0 	ret

corpus/results/kprog_arm64_app_coverage_20261106/divide-bound-v1/native/divide_xfull_stripped.native.o:     file format elf64-littleaarch64


Disassembly of section .text:

0000000000000000 <entry>:
   0:	f9400013 	ldr	x19, [x0]
   4:	f9400402 	ldr	x2, [x0, #8]
   8:	91002263 	add	x3, x19, #0x8
   c:	eb02007f 	cmp	x3, x2
  10:	540001e8 	b.hi	4c <entry+0x4c>  // b.pmore
  14:	d29fffe5 	mov	x5, #0xffff                	// #65535
  18:	f2bfffe5 	movk	x5, #0xffff, lsl #16
  1c:	f2dfffe5 	movk	x5, #0xffff, lsl #32
  20:	f2ffffe5 	movk	x5, #0xffff, lsl #48
  24:	d2800066 	mov	x6, #0x3                   	// #3
  28:	f2a00006 	movk	x6, #0x0, lsl #16
  2c:	f2c00006 	movk	x6, #0x0, lsl #32
  30:	f2e00006 	movk	x6, #0x0, lsl #48
  34:	eb0500bf 	cmp	x5, x5
  38:	9ac608a5 	udiv	x5, x5, x6
  3c:	54000081 	b.ne	4c <entry+0x4c>  // b.any
  40:	f9000265 	str	x5, [x19]
  44:	52800040 	mov	w0, #0x2                   	// #2
  48:	d65f03c0 	ret
  4c:	52800000 	mov	w0, #0x0                   	// #0
  50:	d65f03c0 	ret

corpus/results/kprog_arm64_app_coverage_20261106/divide-bound-v1/native/divide_xz_preserved.native.o:     file format elf64-littleaarch64


Disassembly of section .text:

0000000000000000 <entry>:
   0:	f9400013 	ldr	x19, [x0]
   4:	f9400402 	ldr	x2, [x0, #8]
   8:	91002263 	add	x3, x19, #0x8
   c:	eb02007f 	cmp	x3, x2
  10:	540001e8 	b.hi	4c <entry+0x4c>  // b.pmore
  14:	d28004a5 	mov	x5, #0x25                  	// #37
  18:	f2a00005 	movk	x5, #0x0, lsl #16
  1c:	f2c00005 	movk	x5, #0x0, lsl #32
  20:	f2e00005 	movk	x5, #0x0, lsl #48
  24:	d2800006 	mov	x6, #0x0                   	// #0
  28:	f2a00006 	movk	x6, #0x0, lsl #16
  2c:	f2c00006 	movk	x6, #0x0, lsl #32
  30:	f2e00006 	movk	x6, #0x0, lsl #48
  34:	eb0500bf 	cmp	x5, x5
  38:	9ac608a5 	udiv	x5, x5, x6
  3c:	54000081 	b.ne	4c <entry+0x4c>  // b.any
  40:	f9000265 	str	x5, [x19]
  44:	52800040 	mov	w0, #0x2                   	// #2
  48:	d65f03c0 	ret
  4c:	52800000 	mov	w0, #0x0                   	// #0
  50:	d65f03c0 	ret

corpus/results/kprog_arm64_app_coverage_20261106/divide-bound-v1/native/divide_xz_stripped.native.o:     file format elf64-littleaarch64


Disassembly of section .text:

0000000000000000 <entry>:
   0:	f9400013 	ldr	x19, [x0]
   4:	f9400402 	ldr	x2, [x0, #8]
   8:	91002263 	add	x3, x19, #0x8
   c:	eb02007f 	cmp	x3, x2
  10:	540001e8 	b.hi	4c <entry+0x4c>  // b.pmore
  14:	d28004a5 	mov	x5, #0x25                  	// #37
  18:	f2a00005 	movk	x5, #0x0, lsl #16
  1c:	f2c00005 	movk	x5, #0x0, lsl #32
  20:	f2e00005 	movk	x5, #0x0, lsl #48
  24:	d2800006 	mov	x6, #0x0                   	// #0
  28:	f2a00006 	movk	x6, #0x0, lsl #16
  2c:	f2c00006 	movk	x6, #0x0, lsl #32
  30:	f2e00006 	movk	x6, #0x0, lsl #48
  34:	eb0500bf 	cmp	x5, x5
  38:	9ac608a5 	udiv	x5, x5, x6
  3c:	54000081 	b.ne	4c <entry+0x4c>  // b.any
  40:	f9000265 	str	x5, [x19]
  44:	52800040 	mov	w0, #0x2                   	// #2
  48:	d65f03c0 	ret
  4c:	52800000 	mov	w0, #0x0                   	// #0
  50:	d65f03c0 	ret
