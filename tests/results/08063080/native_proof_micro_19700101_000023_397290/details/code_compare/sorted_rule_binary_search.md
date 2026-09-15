# sorted_rule_binary_search

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
 484:	f00000f0 	adrp	x16, 1f000 <__FRAME_END__+0x1e848>
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
 4c0:	f00000e0 	adrp	x0, 1f000 <__FRAME_END__+0x1e848>
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
 4f8:	f00000e1 	adrp	x1, 1f000 <__FRAME_END__+0x1e848>
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
 534:	f00000e2 	adrp	x2, 1f000 <__FRAME_END__+0x1e848>
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
 56c:	f00000e0 	adrp	x0, 1f000 <__FRAME_END__+0x1e848>
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

00000000000005c0 <sorted_rule_binary_search_xdp>:
 5c0:	a9402408 	ldp	x8, x9, [x0]
 5c4:	aa0803e0 	mov	x0, x8
 5c8:	eb09001f 	cmp	x0, x9
 5cc:	54000069 	b.ls	5d8 <sorted_rule_binary_search_xdp+0x18>  // b.plast
 5d0:	2a1f03e0 	mov	w0, wzr
 5d4:	d65f03c0 	ret
 5d8:	9100200a 	add	x10, x0, #0x8
 5dc:	9106400b 	add	x11, x0, #0x190
 5e0:	eb09015f 	cmp	x10, x9
 5e4:	fa499162 	ccmp	x11, x9, #0x2, ls	// ls = plast
 5e8:	54000069 	b.ls	5f4 <sorted_rule_binary_search_xdp+0x34>  // b.plast
 5ec:	2a1f03e0 	mov	w0, wzr
 5f0:	d65f03c0 	ret
 5f4:	29412809 	ldp	w9, w10, [x0, #8]
 5f8:	7100813f 	cmp	w9, #0x20
 5fc:	7a500940 	ccmp	w10, #0x10, #0x0, eq	// eq = none
 600:	54000060 	b.eq	60c <sorted_rule_binary_search_xdp+0x4c>  // b.none
 604:	2a1f03e0 	mov	w0, wzr
 608:	d65f03c0 	ret
 60c:	aa1f03e9 	mov	x9, xzr
 610:	aa1f03ea 	mov	x10, xzr
 614:	9104400b 	add	x11, x0, #0x110
 618:	9104440c 	add	x12, x0, #0x111
 61c:	9104480d 	add	x13, x0, #0x112
 620:	91044c0e 	add	x14, x0, #0x113
 624:	9104500f 	add	x15, x0, #0x114
 628:	91045410 	add	x16, x0, #0x115
 62c:	91045811 	add	x17, x0, #0x116
 630:	91045c12 	add	x18, x0, #0x117
 634:	91005c00 	add	x0, x0, #0x17
 638:	d503201f 	nop
 63c:	d503201f 	nop
 640:	d37df124 	lsl	x4, x9, #3
 644:	aa1f03e2 	mov	x2, xzr
 648:	aa1f03e1 	mov	x1, xzr
 64c:	38646965 	ldrb	w5, [x11, x4]
 650:	38646986 	ldrb	w6, [x12, x4]
 654:	2a1f03e3 	mov	w3, wzr
 658:	aa0620a5 	orr	x5, x5, x6, lsl #8
 65c:	386469a6 	ldrb	w6, [x13, x4]
 660:	aa0640a5 	orr	x5, x5, x6, lsl #16
 664:	386469c6 	ldrb	w6, [x14, x4]
 668:	aa0660a5 	orr	x5, x5, x6, lsl #24
 66c:	386469e6 	ldrb	w6, [x15, x4]
 670:	aa0680a5 	orr	x5, x5, x6, lsl #32
 674:	38646a06 	ldrb	w6, [x16, x4]
 678:	aa06a0a5 	orr	x5, x5, x6, lsl #40
 67c:	38646a26 	ldrb	w6, [x17, x4]
 680:	38646a44 	ldrb	w4, [x18, x4]
 684:	aa06c0a5 	orr	x5, x5, x6, lsl #48
 688:	aa04e0a4 	orr	x4, x5, x4, lsl #56
 68c:	aa0003e5 	mov	x5, x0
 690:	d503201f 	nop
 694:	d503201f 	nop
 698:	d503201f 	nop
 69c:	d503201f 	nop
 6a0:	f85f90a6 	ldur	x6, [x5, #-7]
 6a4:	910020a5 	add	x5, x5, #0x8
 6a8:	eb0400df 	cmp	x6, x4
 6ac:	1a9f17e6 	cset	w6, eq	// eq = none
 6b0:	9a810047 	csel	x7, x2, x1, eq	// eq = none
 6b4:	7200007f 	tst	w3, #0x1
 6b8:	91000442 	add	x2, x2, #0x1
 6bc:	2a060066 	orr	w6, w3, w6
 6c0:	9a871021 	csel	x1, x1, x7, ne	// ne = any
 6c4:	f100805f 	cmp	x2, #0x20
 6c8:	2a0603e3 	mov	w3, w6
 6cc:	54fffea1 	b.ne	6a0 <sorted_rule_binary_search_xdp+0xe0>  // b.any
 6d0:	91008082 	add	x2, x4, #0x20
 6d4:	8b0a0021 	add	x1, x1, x10
 6d8:	720000df 	tst	w6, #0x1
 6dc:	91000529 	add	x9, x9, #0x1
 6e0:	ca0a004a 	eor	x10, x2, x10
 6e4:	9a8a102a 	csel	x10, x1, x10, ne	// ne = any
 6e8:	f100413f 	cmp	x9, #0x10
 6ec:	54fffaa1 	b.ne	640 <sorted_rule_binary_search_xdp+0x80>  // b.any
 6f0:	52800040 	mov	w0, #0x2                   	// #2
 6f4:	f900010a 	str	x10, [x8]
 6f8:	d65f03c0 	ret

Disassembly of section .fini:

00000000000006fc <_fini>:
 6fc:	d503201f 	nop
 700:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 704:	910003fd 	mov	x29, sp
 708:	a8c17bfd 	ldp	x29, x30, [sp], #16
 70c:	d65f03c0 	ret
```

## Original Kernel JIT ASM
```asm
not captured
```

## llvmbpf JIT ASM
```asm
not captured
```
