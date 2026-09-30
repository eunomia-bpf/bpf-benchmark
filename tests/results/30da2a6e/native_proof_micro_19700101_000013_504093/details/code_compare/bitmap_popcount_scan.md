# bitmap_popcount_scan

## Original C
```c
not captured
```

## Native ASM
```asm
Disassembly of section .init:

0000000000000468 <_init>:
 468:	d503201f 	nop
 46c:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 470:	910003fd 	mov	x29, sp
 474:	94000013 	bl	4c0 <call_weak_fn>
 478:	a8c17bfd 	ldp	x29, x30, [sp], #16
 47c:	d65f03c0 	ret

Disassembly of section .plt:

0000000000000480 <.plt>:
 480:	a9bf7bf0 	stp	x16, x30, [sp, #-16]!
 484:	f00000f0 	adrp	x16, 1f000 <__FRAME_END__+0x1e8e0>
 488:	f947fe11 	ldr	x17, [x16, #4088]
 48c:	913fe210 	add	x16, x16, #0xff8
 490:	d61f0220 	br	x17
 494:	d503201f 	nop
 498:	d503201f 	nop
 49c:	d503201f 	nop

00000000000004a0 <__cxa_finalize@plt>:
 4a0:	90000110 	adrp	x16, 20000 <__cxa_finalize@GLIBC_2.17>
 4a4:	f9400211 	ldr	x17, [x16]
 4a8:	91000210 	add	x16, x16, #0x0
 4ac:	d61f0220 	br	x17

00000000000004b0 <__gmon_start__@plt>:
 4b0:	90000110 	adrp	x16, 20000 <__cxa_finalize@GLIBC_2.17>
 4b4:	f9400611 	ldr	x17, [x16, #8]
 4b8:	91002210 	add	x16, x16, #0x8
 4bc:	d61f0220 	br	x17

Disassembly of section .text:

00000000000004c0 <call_weak_fn>:
 4c0:	f00000e0 	adrp	x0, 1f000 <__FRAME_END__+0x1e8e0>
 4c4:	f947ec00 	ldr	x0, [x0, #4056]
 4c8:	b4000040 	cbz	x0, 4d0 <call_weak_fn+0x10>
 4cc:	17fffff9 	b	4b0 <__gmon_start__@plt>
 4d0:	d65f03c0 	ret
 4d4:	d503201f 	nop
 4d8:	d503201f 	nop
 4dc:	d503201f 	nop

00000000000004e0 <deregister_tm_clones>:
 4e0:	90000100 	adrp	x0, 20000 <__cxa_finalize@GLIBC_2.17>
 4e4:	91006000 	add	x0, x0, #0x18
 4e8:	90000101 	adrp	x1, 20000 <__cxa_finalize@GLIBC_2.17>
 4ec:	91006021 	add	x1, x1, #0x18
 4f0:	eb00003f 	cmp	x1, x0
 4f4:	540000c0 	b.eq	50c <deregister_tm_clones+0x2c>  // b.none
 4f8:	f00000e1 	adrp	x1, 1f000 <__FRAME_END__+0x1e8e0>
 4fc:	f947e421 	ldr	x1, [x1, #4040]
 500:	b4000061 	cbz	x1, 50c <deregister_tm_clones+0x2c>
 504:	aa0103f0 	mov	x16, x1
 508:	d61f0200 	br	x16
 50c:	d65f03c0 	ret

0000000000000510 <register_tm_clones>:
 510:	90000100 	adrp	x0, 20000 <__cxa_finalize@GLIBC_2.17>
 514:	91006000 	add	x0, x0, #0x18
 518:	90000101 	adrp	x1, 20000 <__cxa_finalize@GLIBC_2.17>
 51c:	91006021 	add	x1, x1, #0x18
 520:	cb000021 	sub	x1, x1, x0
 524:	d37ffc22 	lsr	x2, x1, #63
 528:	8b810c41 	add	x1, x2, x1, asr #3
 52c:	9341fc21 	asr	x1, x1, #1
 530:	b40000c1 	cbz	x1, 548 <register_tm_clones+0x38>
 534:	f00000e2 	adrp	x2, 1f000 <__FRAME_END__+0x1e8e0>
 538:	f947f042 	ldr	x2, [x2, #4064]
 53c:	b4000062 	cbz	x2, 548 <register_tm_clones+0x38>
 540:	aa0203f0 	mov	x16, x2
 544:	d61f0200 	br	x16
 548:	d65f03c0 	ret
 54c:	d503201f 	nop

0000000000000550 <__do_global_dtors_aux>:
 550:	d503233f 	paciasp
 554:	a9be7bfd 	stp	x29, x30, [sp, #-32]!
 558:	910003fd 	mov	x29, sp
 55c:	f9000bf3 	str	x19, [sp, #16]
 560:	90000113 	adrp	x19, 20000 <__cxa_finalize@GLIBC_2.17>
 564:	39406260 	ldrb	w0, [x19, #24]
 568:	37000140 	tbnz	w0, #0, 590 <__do_global_dtors_aux+0x40>
 56c:	f00000e0 	adrp	x0, 1f000 <__FRAME_END__+0x1e8e0>
 570:	f947e800 	ldr	x0, [x0, #4048]
 574:	b4000080 	cbz	x0, 584 <__do_global_dtors_aux+0x34>
 578:	90000100 	adrp	x0, 20000 <__cxa_finalize@GLIBC_2.17>
 57c:	f9400800 	ldr	x0, [x0, #16]
 580:	97ffffc8 	bl	4a0 <__cxa_finalize@plt>
 584:	97ffffd7 	bl	4e0 <deregister_tm_clones>
 588:	52800020 	mov	w0, #0x1                   	// #1
 58c:	39006260 	strb	w0, [x19, #24]
 590:	f9400bf3 	ldr	x19, [sp, #16]
 594:	a8c27bfd 	ldp	x29, x30, [sp], #32
 598:	d50323bf 	autiasp
 59c:	d65f03c0 	ret

00000000000005a0 <frame_dummy>:
 5a0:	d503245f 	bti	c
 5a4:	17ffffdb 	b	510 <register_tm_clones>
 5a8:	d503201f 	nop
 5ac:	d503201f 	nop
 5b0:	d503201f 	nop
 5b4:	d503201f 	nop
 5b8:	d503201f 	nop
 5bc:	d503201f 	nop

00000000000005c0 <bitmap_popcount_scan_xdp>:
 5c0:	a9402408 	ldp	x8, x9, [x0]
 5c4:	aa0803eb 	mov	x11, x8
 5c8:	eb09017f 	cmp	x11, x9
 5cc:	54000488 	b.hi	65c <bitmap_popcount_scan_xdp+0x9c>  // b.pmore
 5d0:	9100216a 	add	x10, x11, #0x8
 5d4:	9120416c 	add	x12, x11, #0x810
 5d8:	eb09015f 	cmp	x10, x9
 5dc:	fa499182 	ccmp	x12, x9, #0x2, ls	// ls = plast
 5e0:	540003e8 	b.hi	65c <bitmap_popcount_scan_xdp+0x9c>  // b.pmore
 5e4:	b9400149 	ldr	w9, [x10]
 5e8:	7104013f 	cmp	w9, #0x100
 5ec:	54000381 	b.ne	65c <bitmap_popcount_scan_xdp+0x9c>  // b.any
 5f0:	b9400d6a 	ldr	w10, [x11, #12]
 5f4:	aa1f03e9 	mov	x9, xzr
 5f8:	91005d6b 	add	x11, x11, #0x17
 5fc:	b200c3ec 	mov	x12, #0x101010101010101     	// #72340172838076673
 600:	f85f916d 	ldur	x13, [x11, #-7]
 604:	9100216b 	add	x11, x11, #0x8
 608:	ca0a01ae 	eor	x14, x13, x10
 60c:	d341fdcf 	lsr	x15, x14, #1
 610:	9200f1ef 	and	x15, x15, #0x5555555555555555
 614:	cb0f01ce 	sub	x14, x14, x15
 618:	9200e5cf 	and	x15, x14, #0x3333333333333333
 61c:	d342fdce 	lsr	x14, x14, #2
 620:	9200e5ce 	and	x14, x14, #0x3333333333333333
 624:	8b0e01ee 	add	x14, x15, x14
 628:	8b4e11ce 	add	x14, x14, x14, lsr #4
 62c:	9200cdce 	and	x14, x14, #0xf0f0f0f0f0f0f0f
 630:	9b0c7dce 	mul	x14, x14, x12
 634:	8b4ee14a 	add	x10, x10, x14, lsr #56
 638:	9240092e 	and	x14, x9, #0x7
 63c:	91000529 	add	x9, x9, #0x1
 640:	9ace25ad 	lsr	x13, x13, x14
 644:	f104013f 	cmp	x9, #0x100
 648:	ca0d014a 	eor	x10, x10, x13
 64c:	54fffda1 	b.ne	600 <bitmap_popcount_scan_xdp+0x40>  // b.any
 650:	52800040 	mov	w0, #0x2                   	// #2
 654:	f900010a 	str	x10, [x8]
 658:	d65f03c0 	ret
 65c:	2a1f03e0 	mov	w0, wzr
 660:	d65f03c0 	ret

Disassembly of section .fini:

0000000000000664 <_fini>:
 664:	d503201f 	nop
 668:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 66c:	910003fd 	mov	x29, sp
 670:	a8c17bfd 	ldp	x29, x30, [sp], #16
 674:	d65f03c0 	ret
```

## Original Kernel JIT ASM
```asm
not captured
```

## llvmbpf JIT ASM
```asm
not captured
```
