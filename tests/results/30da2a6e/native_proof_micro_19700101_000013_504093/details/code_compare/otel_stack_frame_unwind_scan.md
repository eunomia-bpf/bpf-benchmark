# otel_stack_frame_unwind_scan

## Original C
```c
not captured
```

## Native ASM
```asm
Disassembly of section .init:

0000000000000470 <_init>:
 470:	d503201f 	nop
 474:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 478:	910003fd 	mov	x29, sp
 47c:	94000019 	bl	4e0 <call_weak_fn>
 480:	a8c17bfd 	ldp	x29, x30, [sp], #16
 484:	d65f03c0 	ret

Disassembly of section .plt:

0000000000000490 <.plt>:
 490:	a9bf7bf0 	stp	x16, x30, [sp, #-16]!
 494:	f00000f0 	adrp	x16, 1f000 <__FRAME_END__+0x1e7c8>
 498:	f947fe11 	ldr	x17, [x16, #4088]
 49c:	913fe210 	add	x16, x16, #0xff8
 4a0:	d61f0220 	br	x17
 4a4:	d503201f 	nop
 4a8:	d503201f 	nop
 4ac:	d503201f 	nop

00000000000004b0 <__cxa_finalize@plt>:
 4b0:	90000110 	adrp	x16, 20000 <__cxa_finalize@GLIBC_2.17>
 4b4:	f9400211 	ldr	x17, [x16]
 4b8:	91000210 	add	x16, x16, #0x0
 4bc:	d61f0220 	br	x17

00000000000004c0 <__gmon_start__@plt>:
 4c0:	90000110 	adrp	x16, 20000 <__cxa_finalize@GLIBC_2.17>
 4c4:	f9400611 	ldr	x17, [x16, #8]
 4c8:	91002210 	add	x16, x16, #0x8
 4cc:	d61f0220 	br	x17

Disassembly of section .text:

00000000000004e0 <call_weak_fn>:
 4e0:	f00000e0 	adrp	x0, 1f000 <__FRAME_END__+0x1e7c8>
 4e4:	f947ec00 	ldr	x0, [x0, #4056]
 4e8:	b4000040 	cbz	x0, 4f0 <call_weak_fn+0x10>
 4ec:	17fffff5 	b	4c0 <__gmon_start__@plt>
 4f0:	d65f03c0 	ret
 4f4:	d503201f 	nop
 4f8:	d503201f 	nop
 4fc:	d503201f 	nop

0000000000000500 <deregister_tm_clones>:
 500:	90000100 	adrp	x0, 20000 <__cxa_finalize@GLIBC_2.17>
 504:	91006000 	add	x0, x0, #0x18
 508:	90000101 	adrp	x1, 20000 <__cxa_finalize@GLIBC_2.17>
 50c:	91006021 	add	x1, x1, #0x18
 510:	eb00003f 	cmp	x1, x0
 514:	540000c0 	b.eq	52c <deregister_tm_clones+0x2c>  // b.none
 518:	f00000e1 	adrp	x1, 1f000 <__FRAME_END__+0x1e7c8>
 51c:	f947e421 	ldr	x1, [x1, #4040]
 520:	b4000061 	cbz	x1, 52c <deregister_tm_clones+0x2c>
 524:	aa0103f0 	mov	x16, x1
 528:	d61f0200 	br	x16
 52c:	d65f03c0 	ret

0000000000000530 <register_tm_clones>:
 530:	90000100 	adrp	x0, 20000 <__cxa_finalize@GLIBC_2.17>
 534:	91006000 	add	x0, x0, #0x18
 538:	90000101 	adrp	x1, 20000 <__cxa_finalize@GLIBC_2.17>
 53c:	91006021 	add	x1, x1, #0x18
 540:	cb000021 	sub	x1, x1, x0
 544:	d37ffc22 	lsr	x2, x1, #63
 548:	8b810c41 	add	x1, x2, x1, asr #3
 54c:	9341fc21 	asr	x1, x1, #1
 550:	b40000c1 	cbz	x1, 568 <register_tm_clones+0x38>
 554:	f00000e2 	adrp	x2, 1f000 <__FRAME_END__+0x1e7c8>
 558:	f947f042 	ldr	x2, [x2, #4064]
 55c:	b4000062 	cbz	x2, 568 <register_tm_clones+0x38>
 560:	aa0203f0 	mov	x16, x2
 564:	d61f0200 	br	x16
 568:	d65f03c0 	ret
 56c:	d503201f 	nop

0000000000000570 <__do_global_dtors_aux>:
 570:	d503233f 	paciasp
 574:	a9be7bfd 	stp	x29, x30, [sp, #-32]!
 578:	910003fd 	mov	x29, sp
 57c:	f9000bf3 	str	x19, [sp, #16]
 580:	90000113 	adrp	x19, 20000 <__cxa_finalize@GLIBC_2.17>
 584:	39406260 	ldrb	w0, [x19, #24]
 588:	37000140 	tbnz	w0, #0, 5b0 <__do_global_dtors_aux+0x40>
 58c:	f00000e0 	adrp	x0, 1f000 <__FRAME_END__+0x1e7c8>
 590:	f947e800 	ldr	x0, [x0, #4048]
 594:	b4000080 	cbz	x0, 5a4 <__do_global_dtors_aux+0x34>
 598:	90000100 	adrp	x0, 20000 <__cxa_finalize@GLIBC_2.17>
 59c:	f9400800 	ldr	x0, [x0, #16]
 5a0:	97ffffc4 	bl	4b0 <__cxa_finalize@plt>
 5a4:	97ffffd7 	bl	500 <deregister_tm_clones>
 5a8:	52800020 	mov	w0, #0x1                   	// #1
 5ac:	39006260 	strb	w0, [x19, #24]
 5b0:	f9400bf3 	ldr	x19, [sp, #16]
 5b4:	a8c27bfd 	ldp	x29, x30, [sp], #32
 5b8:	d50323bf 	autiasp
 5bc:	d65f03c0 	ret

00000000000005c0 <frame_dummy>:
 5c0:	d503245f 	bti	c
 5c4:	17ffffdb 	b	530 <register_tm_clones>
 5c8:	d503201f 	nop
 5cc:	d503201f 	nop
 5d0:	d503201f 	nop
 5d4:	d503201f 	nop
 5d8:	d503201f 	nop
 5dc:	d503201f 	nop

00000000000005e0 <otel_stack_frame_unwind_scan_xdp>:
 5e0:	a9402408 	ldp	x8, x9, [x0]
 5e4:	aa0803ea 	mov	x10, x8
 5e8:	eb09015f 	cmp	x10, x9
 5ec:	54000069 	b.ls	5f8 <otel_stack_frame_unwind_scan_xdp+0x18>  // b.plast
 5f0:	2a1f03e0 	mov	w0, wzr
 5f4:	d65f03c0 	ret
 5f8:	9100214b 	add	x11, x10, #0x8
 5fc:	9109414c 	add	x12, x10, #0x250
 600:	eb09017f 	cmp	x11, x9
 604:	fa499182 	ccmp	x12, x9, #0x2, ls	// ls = plast
 608:	54000069 	b.ls	614 <otel_stack_frame_unwind_scan_xdp+0x34>  // b.plast
 60c:	2a1f03e0 	mov	w0, wzr
 610:	d65f03c0 	ret
 614:	29412d49 	ldp	w9, w11, [x10, #8]
 618:	7100613f 	cmp	w9, #0x18
 61c:	7a580960 	ccmp	w11, #0x18, #0x0, eq	// eq = none
 620:	54000060 	b.eq	62c <otel_stack_frame_unwind_scan_xdp+0x4c>  // b.none
 624:	2a1f03e0 	mov	w0, wzr
 628:	d65f03c0 	ret
 62c:	d289986c 	mov	x12, #0x4cc3                	// #19651
 630:	aa1f03e9 	mov	x9, xzr
 634:	91004d4a 	add	x10, x10, #0x13
 638:	d2c0002b 	mov	x11, #0x100000000           	// #4294967296
 63c:	5280010d 	mov	w13, #0x8                   	// #8
 640:	f2aea6ec 	movk	x12, #0x7537, lsl #16
 644:	f2ccb98c 	movk	x12, #0x65cc, lsl #32
 648:	f2eb132c 	movk	x12, #0x5899, lsl #48
 64c:	1400000b 	b	678 <otel_stack_frame_unwind_scan_xdp+0x98>
 650:	d503201f 	nop
 654:	d503201f 	nop
 658:	d503201f 	nop
 65c:	d503201f 	nop
 660:	aa00c250 	orr	x16, x18, x0, lsl #48
 664:	91000529 	add	x9, x9, #0x1
 668:	9100614a 	add	x10, x10, #0x18
 66c:	ca0c020c 	eor	x12, x16, x12
 670:	f100613f 	cmp	x9, #0x18
 674:	54000800 	b.eq	774 <otel_stack_frame_unwind_scan_xdp+0x194>  // b.none
 678:	7840f140 	ldurh	w0, [x10, #15]
 67c:	f85fd152 	ldur	x18, [x10, #-3]
 680:	7100041f 	cmp	w0, #0x1
 684:	b8405150 	ldur	w16, [x10, #5]
 688:	b8409151 	ldur	w17, [x10, #9]
 68c:	7840d14e 	ldurh	w14, [x10, #13]
 690:	b841114f 	ldur	w15, [x10, #17]
 694:	5400016c 	b.gt	6c0 <otel_stack_frame_unwind_scan_xdp+0xe0>
 698:	34000240 	cbz	w0, 6e0 <otel_stack_frame_unwind_scan_xdp+0x100>
 69c:	7100041f 	cmp	w0, #0x1
 6a0:	54fffe01 	b.ne	660 <otel_stack_frame_unwind_scan_xdp+0x80>  // b.any
 6a4:	528006a1 	mov	w1, #0x35                  	// #53
 6a8:	7140061f 	cmp	w16, #0x1, lsl #12
 6ac:	54000289 	b.ls	6fc <otel_stack_frame_unwind_scan_xdp+0x11c>  // b.plast
 6b0:	17ffffec 	b	660 <otel_stack_frame_unwind_scan_xdp+0x80>
 6b4:	d503201f 	nop
 6b8:	d503201f 	nop
 6bc:	d503201f 	nop
 6c0:	7100081f 	cmp	w0, #0x2
 6c4:	54000160 	b.eq	6f0 <otel_stack_frame_unwind_scan_xdp+0x110>  // b.none
 6c8:	71000c1f 	cmp	w0, #0x3
 6cc:	54fffca1 	b.ne	660 <otel_stack_frame_unwind_scan_xdp+0x80>  // b.any
 6d0:	52801121 	mov	w1, #0x89                  	// #137
 6d4:	7140061f 	cmp	w16, #0x1, lsl #12
 6d8:	54000129 	b.ls	6fc <otel_stack_frame_unwind_scan_xdp+0x11c>  // b.plast
 6dc:	17ffffe1 	b	660 <otel_stack_frame_unwind_scan_xdp+0x80>
 6e0:	52800421 	mov	w1, #0x21                  	// #33
 6e4:	7140061f 	cmp	w16, #0x1, lsl #12
 6e8:	540000a9 	b.ls	6fc <otel_stack_frame_unwind_scan_xdp+0x11c>  // b.plast
 6ec:	17ffffdd 	b	660 <otel_stack_frame_unwind_scan_xdp+0x80>
 6f0:	52800aa1 	mov	w1, #0x55                  	// #85
 6f4:	7140061f 	cmp	w16, #0x1, lsl #12
 6f8:	54fffb48 	b.hi	660 <otel_stack_frame_unwind_scan_xdp+0x80>  // b.pmore
 6fc:	71400a3f 	cmp	w17, #0x2, lsl #12
 700:	54fffb08 	b.hi	660 <otel_stack_frame_unwind_scan_xdp+0x80>  // b.pmore
 704:	720001df 	tst	w14, #0x1
 708:	aa0f8021 	orr	x1, x1, x15, lsl #32
 70c:	2a2003e0 	mvn	w0, w0
 710:	1a9101a2 	csel	w2, w13, w17, eq	// eq = none
 714:	ca010252 	eor	x18, x18, x1
 718:	721f01df 	tst	w14, #0x2
 71c:	0b100042 	add	w2, w2, w16
 720:	ca116210 	eor	x16, x16, x17, lsl #24
 724:	12000931 	and	w17, w9, #0x7
 728:	8b02016b 	add	x11, x11, x2
 72c:	ca0b0252 	eor	x18, x18, x11
 730:	9ac02e40 	ror	x0, x18, x0
 734:	9a800252 	csel	x18, x18, x0, eq	// eq = none
 738:	721e01df 	tst	w14, #0x4
 73c:	9a9003f0 	csel	x16, xzr, x16, eq	// eq = none
 740:	8b100250 	add	x16, x18, x16
 744:	11000632 	add	w18, w17, #0x1
 748:	52001631 	eor	w17, w17, #0x3f
 74c:	9ad22212 	lsl	x18, x16, x18
 750:	9ad12610 	lsr	x16, x16, x17
 754:	aa100250 	orr	x16, x18, x16
 758:	8b0c0210 	add	x16, x16, x12
 75c:	aa0ea1ec 	orr	x12, x15, x14, lsl #40
 760:	91000529 	add	x9, x9, #0x1
 764:	9100614a 	add	x10, x10, #0x18
 768:	ca0c020c 	eor	x12, x16, x12
 76c:	f100613f 	cmp	x9, #0x18
 770:	54fff841 	b.ne	678 <otel_stack_frame_unwind_scan_xdp+0x98>  // b.any
 774:	52800040 	mov	w0, #0x2                   	// #2
 778:	f900010c 	str	x12, [x8]
 77c:	d65f03c0 	ret

Disassembly of section .fini:

0000000000000780 <_fini>:
 780:	d503201f 	nop
 784:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 788:	910003fd 	mov	x29, sp
 78c:	a8c17bfd 	ldp	x29, x30, [sp], #16
 790:	d65f03c0 	ret
```

## Original Kernel JIT ASM
```asm
not captured
```

## llvmbpf JIT ASM
```asm
not captured
```
