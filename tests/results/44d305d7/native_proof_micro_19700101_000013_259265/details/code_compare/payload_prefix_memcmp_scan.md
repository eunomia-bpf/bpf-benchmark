# payload_prefix_memcmp_scan

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
 494:	f00000f0 	adrp	x16, 1f000 <__FRAME_END__+0x1e788>
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
 4e0:	f00000e0 	adrp	x0, 1f000 <__FRAME_END__+0x1e788>
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
 518:	f00000e1 	adrp	x1, 1f000 <__FRAME_END__+0x1e788>
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
 554:	f00000e2 	adrp	x2, 1f000 <__FRAME_END__+0x1e788>
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
 58c:	f00000e0 	adrp	x0, 1f000 <__FRAME_END__+0x1e788>
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

00000000000005e0 <payload_prefix_memcmp_scan_xdp>:
 5e0:	a9402808 	ldp	x8, x10, [x0]
 5e4:	aa0803e9 	mov	x9, x8
 5e8:	eb0a013f 	cmp	x9, x10
 5ec:	540004c8 	b.hi	684 <payload_prefix_memcmp_scan_xdp+0xa4>  // b.pmore
 5f0:	9100212b 	add	x11, x9, #0x8
 5f4:	9103312c 	add	x12, x9, #0xcc
 5f8:	eb0a017f 	cmp	x11, x10
 5fc:	fa4a9182 	ccmp	x12, x10, #0x2, ls	// ls = plast
 600:	54000428 	b.hi	684 <payload_prefix_memcmp_scan_xdp+0xa4>  // b.pmore
 604:	b940016a 	ldr	w10, [x11]
 608:	71000d5f 	cmp	w10, #0x3
 60c:	540003c1 	b.ne	684 <payload_prefix_memcmp_scan_xdp+0xa4>  // b.any
 610:	d29921cd 	mov	x13, #0xc90e                	// #51470
 614:	2a1f03ea 	mov	w10, wzr
 618:	aa1f03eb 	mov	x11, xzr
 61c:	9100312c 	add	x12, x9, #0xc
 620:	528014ae 	mov	w14, #0xa5                  	// #165
 624:	f2be778d 	movk	x13, #0xf3bc, lsl #16
 628:	f2dccced 	movk	x13, #0xe667, lsl #32
 62c:	f2ed412d 	movk	x13, #0x6a09, lsl #48
 630:	d503201f 	nop
 634:	d503201f 	nop
 638:	d503201f 	nop
 63c:	d503201f 	nop
 640:	3840158f 	ldrb	w15, [x12], #1
 644:	4a0a0170 	eor	w16, w11, w10
 648:	4a0e0210 	eor	w16, w16, w14
 64c:	11004610 	add	w16, w16, #0x11
 650:	6b3001ff 	cmp	w15, w16, uxtb
 654:	540001c1 	b.ne	68c <payload_prefix_memcmp_scan_xdp+0xac>  // b.any
 658:	9100116b 	add	x11, x11, #0x4
 65c:	1100754a 	add	w10, w10, #0x1d
 660:	910015ad 	add	x13, x13, #0x5
 664:	f104017f 	cmp	x11, #0x100
 668:	54fffec1 	b.ne	640 <payload_prefix_memcmp_scan_xdp+0x60>  // b.any
 66c:	39412d2a 	ldrb	w10, [x9, #75]
 670:	d296a38b 	mov	x11, #0xb51c                	// #46364
 674:	f2b19ecb 	movk	x11, #0x8cf6, lsl #16
 678:	f2d3fbcb 	movk	x11, #0x9fde, lsl #32
 67c:	f2fe87cb 	movk	x11, #0xf43e, lsl #48
 680:	14000005 	b	694 <payload_prefix_memcmp_scan_xdp+0xb4>
 684:	2a1f03e0 	mov	w0, wzr
 688:	d65f03c0 	ret
 68c:	ca0f01aa 	eor	x10, x13, x15
 690:	12001e0b 	and	w11, w16, #0xff
 694:	8b0b014a 	add	x10, x10, x11
 698:	2a1f03eb 	mov	w11, wzr
 69c:	aa1f03ec 	mov	x12, xzr
 6a0:	9101312d 	add	x13, x9, #0x4c
 6a4:	928000ae 	mov	x14, #0xfffffffffffffffa    	// #-6
 6a8:	528014af 	mov	w15, #0xa5                  	// #165
 6ac:	93caed4a 	ror	x10, x10, #59
 6b0:	d503201f 	nop
 6b4:	d503201f 	nop
 6b8:	d503201f 	nop
 6bc:	d503201f 	nop
 6c0:	384015b0 	ldrb	w16, [x13], #1
 6c4:	4a0b0191 	eor	w17, w12, w11
 6c8:	4a0f0231 	eor	w17, w17, w15
 6cc:	11004631 	add	w17, w17, #0x11
 6d0:	6b31021f 	cmp	w16, w17, uxtb
 6d4:	540001c1 	b.ne	70c <payload_prefix_memcmp_scan_xdp+0x12c>  // b.any
 6d8:	9100118c 	add	x12, x12, #0x4
 6dc:	d10019ce 	sub	x14, x14, #0x6
 6e0:	1100756b 	add	w11, w11, #0x1d
 6e4:	f104019f 	cmp	x12, #0x100
 6e8:	54fffec1 	b.ne	6c0 <payload_prefix_memcmp_scan_xdp+0xe0>  // b.any
 6ec:	d28f82cb 	mov	x11, #0x7c16                	// #31766
 6f0:	f2afe94b 	movk	x11, #0x7f4a, lsl #16
 6f4:	f2cf372b 	movk	x11, #0x79b9, lsl #32
 6f8:	f2f3c6eb 	movk	x11, #0x9e37, lsl #48
 6fc:	ca0b014a 	eor	x10, x10, x11
 700:	39422d2b 	ldrb	w11, [x9, #139]
 704:	8b0b214a 	add	x10, x10, x11, lsl #8
 708:	14000005 	b	71c <payload_prefix_memcmp_scan_xdp+0x13c>
 70c:	cb0e014a 	sub	x10, x10, x14
 710:	12001e2b 	and	w11, w17, #0xff
 714:	ca10214a 	eor	x10, x10, x16, lsl #8
 718:	8b0b014a 	add	x10, x10, x11
 71c:	2a1f03eb 	mov	w11, wzr
 720:	aa1f03ec 	mov	x12, xzr
 724:	93cae94a 	ror	x10, x10, #58
 728:	9102312d 	add	x13, x9, #0x8c
 72c:	928000ce 	mov	x14, #0xfffffffffffffff9    	// #-7
 730:	528014af 	mov	w15, #0xa5                  	// #165
 734:	d503201f 	nop
 738:	d503201f 	nop
 73c:	d503201f 	nop
 740:	384015b0 	ldrb	w16, [x13], #1
 744:	4a0b0191 	eor	w17, w12, w11
 748:	4a0f0231 	eor	w17, w17, w15
 74c:	11004631 	add	w17, w17, #0x11
 750:	6b31021f 	cmp	w16, w17, uxtb
 754:	54000241 	b.ne	79c <payload_prefix_memcmp_scan_xdp+0x1bc>  // b.any
 758:	9100118c 	add	x12, x12, #0x4
 75c:	d1001dce 	sub	x14, x14, #0x7
 760:	1100756b 	add	w11, w11, #0x1d
 764:	f104019f 	cmp	x12, #0x100
 768:	54fffec1 	b.ne	740 <payload_prefix_memcmp_scan_xdp+0x160>  // b.any
 76c:	d28f82cb 	mov	x11, #0x7c16                	// #31766
 770:	39432d29 	ldrb	w9, [x9, #203]
 774:	f2afe94b 	movk	x11, #0x7f4a, lsl #16
 778:	f2cf372b 	movk	x11, #0x79b9, lsl #32
 77c:	f2f3c6eb 	movk	x11, #0x9e37, lsl #48
 780:	b240016b 	orr	x11, x11, #0x1
 784:	ca0b014a 	eor	x10, x10, x11
 788:	8b094149 	add	x9, x10, x9, lsl #16
 78c:	93c9e529 	ror	x9, x9, #57
 790:	52800040 	mov	w0, #0x2                   	// #2
 794:	f9000109 	str	x9, [x8]
 798:	d65f03c0 	ret
 79c:	cb0e0149 	sub	x9, x10, x14
 7a0:	12001e2a 	and	w10, w17, #0xff
 7a4:	ca104129 	eor	x9, x9, x16, lsl #16
 7a8:	8b0a0129 	add	x9, x9, x10
 7ac:	93c9e529 	ror	x9, x9, #57
 7b0:	52800040 	mov	w0, #0x2                   	// #2
 7b4:	f9000109 	str	x9, [x8]
 7b8:	d65f03c0 	ret

Disassembly of section .fini:

00000000000007bc <_fini>:
 7bc:	d503201f 	nop
 7c0:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 7c4:	910003fd 	mov	x29, sp
 7c8:	a8c17bfd 	ldp	x29, x30, [sp], #16
 7cc:	d65f03c0 	ret
```

## Original Kernel JIT ASM
```asm
not captured
```

## llvmbpf JIT ASM
```asm
not captured
```
