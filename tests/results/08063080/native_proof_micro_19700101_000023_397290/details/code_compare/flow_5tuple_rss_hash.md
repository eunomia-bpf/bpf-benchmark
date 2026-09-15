# flow_5tuple_rss_hash

## Original C
```c
not captured
```

## Native ASM
```asm
Disassembly of section .init:

0000000000000488 <_init>:
 488:	d503201f 	nop
 48c:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 490:	910003fd 	mov	x29, sp
 494:	94000013 	bl	4e0 <call_weak_fn>
 498:	a8c17bfd 	ldp	x29, x30, [sp], #16
 49c:	d65f03c0 	ret

Disassembly of section .plt:

00000000000004a0 <.plt>:
 4a0:	a9bf7bf0 	stp	x16, x30, [sp, #-16]!
 4a4:	f00000f0 	adrp	x16, 1f000 <__FRAME_END__+0x1e790>
 4a8:	f947fe11 	ldr	x17, [x16, #4088]
 4ac:	913fe210 	add	x16, x16, #0xff8
 4b0:	d61f0220 	br	x17
 4b4:	d503201f 	nop
 4b8:	d503201f 	nop
 4bc:	d503201f 	nop

00000000000004c0 <__cxa_finalize@plt>:
 4c0:	90000110 	adrp	x16, 20000 <__cxa_finalize@GLIBC_2.17>
 4c4:	f9400211 	ldr	x17, [x16]
 4c8:	91000210 	add	x16, x16, #0x0
 4cc:	d61f0220 	br	x17

00000000000004d0 <__gmon_start__@plt>:
 4d0:	90000110 	adrp	x16, 20000 <__cxa_finalize@GLIBC_2.17>
 4d4:	f9400611 	ldr	x17, [x16, #8]
 4d8:	91002210 	add	x16, x16, #0x8
 4dc:	d61f0220 	br	x17

Disassembly of section .text:

00000000000004e0 <call_weak_fn>:
 4e0:	f00000e0 	adrp	x0, 1f000 <__FRAME_END__+0x1e790>
 4e4:	f947ec00 	ldr	x0, [x0, #4056]
 4e8:	b4000040 	cbz	x0, 4f0 <call_weak_fn+0x10>
 4ec:	17fffff9 	b	4d0 <__gmon_start__@plt>
 4f0:	d65f03c0 	ret
 4f4:	d503201f 	nop
 4f8:	d503201f 	nop
 4fc:	d503201f 	nop

0000000000000500 <deregister_tm_clones>:
 500:	90000100 	adrp	x0, 20000 <__cxa_finalize@GLIBC_2.17>
 504:	91008000 	add	x0, x0, #0x20
 508:	90000101 	adrp	x1, 20000 <__cxa_finalize@GLIBC_2.17>
 50c:	91008021 	add	x1, x1, #0x20
 510:	eb00003f 	cmp	x1, x0
 514:	540000c0 	b.eq	52c <deregister_tm_clones+0x2c>  // b.none
 518:	f00000e1 	adrp	x1, 1f000 <__FRAME_END__+0x1e790>
 51c:	f947e421 	ldr	x1, [x1, #4040]
 520:	b4000061 	cbz	x1, 52c <deregister_tm_clones+0x2c>
 524:	aa0103f0 	mov	x16, x1
 528:	d61f0200 	br	x16
 52c:	d65f03c0 	ret

0000000000000530 <register_tm_clones>:
 530:	90000100 	adrp	x0, 20000 <__cxa_finalize@GLIBC_2.17>
 534:	91008000 	add	x0, x0, #0x20
 538:	90000101 	adrp	x1, 20000 <__cxa_finalize@GLIBC_2.17>
 53c:	91008021 	add	x1, x1, #0x20
 540:	cb000021 	sub	x1, x1, x0
 544:	d37ffc22 	lsr	x2, x1, #63
 548:	8b810c41 	add	x1, x2, x1, asr #3
 54c:	9341fc21 	asr	x1, x1, #1
 550:	b40000c1 	cbz	x1, 568 <register_tm_clones+0x38>
 554:	f00000e2 	adrp	x2, 1f000 <__FRAME_END__+0x1e790>
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
 584:	39407260 	ldrb	w0, [x19, #28]
 588:	37000140 	tbnz	w0, #0, 5b0 <__do_global_dtors_aux+0x40>
 58c:	f00000e0 	adrp	x0, 1f000 <__FRAME_END__+0x1e790>
 590:	f947e800 	ldr	x0, [x0, #4048]
 594:	b4000080 	cbz	x0, 5a4 <__do_global_dtors_aux+0x34>
 598:	90000100 	adrp	x0, 20000 <__cxa_finalize@GLIBC_2.17>
 59c:	f9400800 	ldr	x0, [x0, #16]
 5a0:	97ffffc8 	bl	4c0 <__cxa_finalize@plt>
 5a4:	97ffffd7 	bl	500 <deregister_tm_clones>
 5a8:	52800020 	mov	w0, #0x1                   	// #1
 5ac:	39007260 	strb	w0, [x19, #28]
 5b0:	f9400bf3 	ldr	x19, [sp, #16]
 5b4:	a8c27bfd 	ldp	x29, x30, [sp], #32
 5b8:	d50323bf 	autiasp
 5bc:	d65f03c0 	ret

00000000000005c0 <frame_dummy>:
 5c0:	d503245f 	bti	c
 5c4:	17ffffdb 	b	530 <register_tm_clones>
 5c8:	d503201f 	nop
 5cc:	d503201f 	nop

00000000000005d0 <flow_5tuple_rss_hash_xdp>:
 5d0:	a9402c08 	ldp	x8, x11, [x0]
 5d4:	91002109 	add	x9, x8, #0x8
 5d8:	eb0b011f 	cmp	x8, x11
 5dc:	fa4b9122 	ccmp	x9, x11, #0x2, ls	// ls = plast
 5e0:	540003a8 	b.hi	654 <flow_5tuple_rss_hash_xdp+0x84>  // b.pmore
 5e4:	91005909 	add	x9, x8, #0x16
 5e8:	eb0b013f 	cmp	x9, x11
 5ec:	54000348 	b.hi	654 <flow_5tuple_rss_hash_xdp+0x84>  // b.pmore
 5f0:	7940290a 	ldrh	w10, [x8, #20]
 5f4:	9100a90c 	add	x12, x8, #0x2a
 5f8:	5ac0054a 	rev16	w10, w10
 5fc:	7120015f 	cmp	w10, #0x800
 600:	fa4b0182 	ccmp	x12, x11, #0x2, eq	// eq = none
 604:	54000288 	b.hi	654 <flow_5tuple_rss_hash_xdp+0x84>  // b.pmore
 608:	3940012c 	ldrb	w12, [x9]
 60c:	92400d8a 	and	x10, x12, #0xf
 610:	121c0d8c 	and	w12, w12, #0xf0
 614:	7101019f 	cmp	w12, #0x40
 618:	7a450940 	ccmp	w10, #0x5, #0x0, eq	// eq = none
 61c:	540001c3 	b.cc	654 <flow_5tuple_rss_hash_xdp+0x84>  // b.lo, b.ul, b.last
 620:	8b0a092c 	add	x12, x9, x10, lsl #2
 624:	eb0b019f 	cmp	x12, x11
 628:	54000168 	b.hi	654 <flow_5tuple_rss_hash_xdp+0x84>  // b.pmore
 62c:	39407d0a 	ldrb	w10, [x8, #31]
 630:	39406109 	ldrb	w9, [x8, #24]
 634:	7100455f 	cmp	w10, #0x11
 638:	3940650d 	ldrb	w13, [x8, #25]
 63c:	54000060 	b.eq	648 <flow_5tuple_rss_hash_xdp+0x78>  // b.none
 640:	7100195f 	cmp	w10, #0x6
 644:	54000081 	b.ne	654 <flow_5tuple_rss_hash_xdp+0x84>  // b.any
 648:	9100118e 	add	x14, x12, #0x4
 64c:	eb0b01df 	cmp	x14, x11
 650:	54000069 	b.ls	65c <flow_5tuple_rss_hash_xdp+0x8c>  // b.plast
 654:	2a1f03e0 	mov	w0, wzr
 658:	d65f03c0 	ret
 65c:	7940018e 	ldrh	w14, [x12]
 660:	7940058b 	ldrh	w11, [x12, #2]
 664:	528acf11 	mov	w17, #0x5678                	// #22136
 668:	2a0921ad 	orr	w13, w13, w9, lsl #8
 66c:	5297dde0 	mov	w0, #0xbeef                	// #48879
 670:	528f3721 	mov	w1, #0x79b9                	// #31161
 674:	b842210f 	ldur	w15, [x8, #34]
 678:	72a24691 	movk	w17, #0x1234, lsl #16
 67c:	b8426110 	ldur	w16, [x8, #38]
 680:	72bbd5a0 	movk	w0, #0xdead, lsl #16
 684:	72b3c6e1 	movk	w1, #0x9e37, lsl #16
 688:	39000d09 	strb	w9, [x8, #3]
 68c:	0b110151 	add	w17, w10, w17
 690:	5ac009cc 	rev	w12, w14
 694:	5ac0096e 	rev	w14, w11
 698:	5ac009ef 	rev	w15, w15
 69c:	5ac00a10 	rev	w16, w16
 6a0:	5ac00569 	rev16	w9, w11
 6a4:	53107d8c 	lsr	w12, w12, #16
 6a8:	0b0f01b2 	add	w18, w13, w15
 6ac:	4a1001ef 	eor	w15, w15, w16
 6b0:	138e418e 	extr	w14, w12, w14, #16
 6b4:	138f65ef 	ror	w15, w15, #25
 6b8:	0b0e0231 	add	w17, w17, w14
 6bc:	4b110252 	sub	w18, w18, w17
 6c0:	0b000252 	add	w18, w18, w0
 6c4:	0b010200 	add	w0, w16, w1
 6c8:	4ad17252 	eor	w18, w18, w17, ror #28
 6cc:	0b000231 	add	w17, w17, w0
 6d0:	4b120001 	sub	w1, w0, w18
 6d4:	4ad26820 	eor	w0, w1, w18, ror #26
 6d8:	4b000221 	sub	w1, w17, w0
 6dc:	0b110251 	add	w17, w18, w17
 6e0:	4ac06032 	eor	w18, w1, w0, ror #24
 6e4:	4b120221 	sub	w1, w17, w18
 6e8:	0b110011 	add	w17, w0, w17
 6ec:	4ad24020 	eor	w0, w1, w18, ror #16
 6f0:	4b000221 	sub	w1, w17, w0
 6f4:	0b110251 	add	w17, w18, w17
 6f8:	4ac03432 	eor	w18, w1, w0, ror #13
 6fc:	0b110000 	add	w0, w0, w17
 700:	2a0a61a1 	orr	w1, w13, w10, lsl #24
 704:	b3783d8a 	bfi	x10, x12, #8, #16
 708:	4b120231 	sub	w17, w17, w18
 70c:	0b0e000e 	add	w14, w0, w14
 710:	0b0f000f 	add	w15, w0, w15
 714:	52800040 	mov	w0, #0x2                   	// #2
 718:	4ad27231 	eor	w17, w17, w18, ror #28
 71c:	0b1201ce 	add	w14, w14, w18
 720:	ca090149 	eor	x9, x10, x9
 724:	d3787d8a 	ubfiz	x10, x12, #8, #32
 728:	0b010230 	add	w16, w17, w1
 72c:	138e49d1 	ror	w17, w14, #18
 730:	4a0d414a 	eor	w10, w10, w13, lsl #16
 734:	39000109 	strb	w9, [x8]
 738:	d348fd29 	lsr	x9, x9, #8
 73c:	4a0e0210 	eor	w16, w16, w14
 740:	53107d4a 	lsr	w10, w10, #16
 744:	39000509 	strb	w9, [x8, #1]
 748:	4b110210 	sub	w16, w16, w17
 74c:	3900090a 	strb	w10, [x8, #2]
 750:	4a0f020f 	eor	w15, w16, w15
 754:	13905611 	ror	w17, w16, #21
 758:	4b1101ef 	sub	w15, w15, w17
 75c:	4a0e01ee 	eor	w14, w15, w14
 760:	138f1df1 	ror	w17, w15, #7
 764:	4b1101ce 	sub	w14, w14, w17
 768:	4a1001d0 	eor	w16, w14, w16
 76c:	138e41d1 	ror	w17, w14, #16
 770:	4b110210 	sub	w16, w16, w17
 774:	4a0f020f 	eor	w15, w16, w15
 778:	13907211 	ror	w17, w16, #28
 77c:	4b1101ef 	sub	w15, w15, w17
 780:	4a0e01ee 	eor	w14, w15, w14
 784:	138f49ef 	ror	w15, w15, #18
 788:	4b0f01ce 	sub	w14, w14, w15
 78c:	4a1001cb 	eor	w11, w14, w16
 790:	138e21cc 	ror	w12, w14, #8
 794:	4b0c0169 	sub	w9, w11, w12
 798:	d348fd2a 	lsr	x10, x9, #8
 79c:	39001109 	strb	w9, [x8, #4]
 7a0:	3900150a 	strb	w10, [x8, #5]
 7a4:	d350fd2a 	lsr	x10, x9, #16
 7a8:	d358fd29 	lsr	x9, x9, #24
 7ac:	3900190a 	strb	w10, [x8, #6]
 7b0:	39001d09 	strb	w9, [x8, #7]
 7b4:	d65f03c0 	ret

Disassembly of section .fini:

00000000000007b8 <_fini>:
 7b8:	d503201f 	nop
 7bc:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 7c0:	910003fd 	mov	x29, sp
 7c4:	a8c17bfd 	ldp	x29, x30, [sp], #16
 7c8:	d65f03c0 	ret
```

## Original Kernel JIT ASM
```asm
not captured
```

## llvmbpf JIT ASM
```asm
not captured
```
