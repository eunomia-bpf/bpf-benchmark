# bcc_tcpconnect_ipv4_tuple_filter

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
 494:	f00000f0 	adrp	x16, 1f000 <__FRAME_END__+0x1e770>
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
 4e0:	f00000e0 	adrp	x0, 1f000 <__FRAME_END__+0x1e770>
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
 518:	f00000e1 	adrp	x1, 1f000 <__FRAME_END__+0x1e770>
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
 554:	f00000e2 	adrp	x2, 1f000 <__FRAME_END__+0x1e770>
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
 58c:	f00000e0 	adrp	x0, 1f000 <__FRAME_END__+0x1e770>
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

00000000000005e0 <bcc_tcpconnect_ipv4_tuple_filter_xdp>:
 5e0:	a9402408 	ldp	x8, x9, [x0]
 5e4:	aa0803ea 	mov	x10, x8
 5e8:	eb09015f 	cmp	x10, x9
 5ec:	54000069 	b.ls	5f8 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x18>  // b.plast
 5f0:	2a1f03e0 	mov	w0, wzr
 5f4:	d65f03c0 	ret
 5f8:	9100214b 	add	x11, x10, #0x8
 5fc:	910c414c 	add	x12, x10, #0x310
 600:	eb09017f 	cmp	x11, x9
 604:	fa499182 	ccmp	x12, x9, #0x2, ls	// ls = plast
 608:	54000069 	b.ls	614 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x34>  // b.plast
 60c:	2a1f03e0 	mov	w0, wzr
 610:	d65f03c0 	ret
 614:	29412d49 	ldp	w9, w11, [x10, #8]
 618:	7100813f 	cmp	w9, #0x20
 61c:	7a580960 	ccmp	w11, #0x18, #0x0, eq	// eq = none
 620:	54000060 	b.eq	62c <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x4c>  // b.none
 624:	2a1f03e0 	mov	w0, wzr
 628:	d65f03c0 	ret
 62c:	d28c85ec 	mov	x12, #0x642f                	// #25647
 630:	aa1f03e9 	mov	x9, xzr
 634:	91004d4a 	add	x10, x10, #0x13
 638:	5283f1eb 	mov	w11, #0x1f8f                	// #8079
 63c:	1280004d 	mov	w13, #0xfffffffd            	// #-3
 640:	528ea5ee 	mov	w14, #0x752f                	// #29999
 644:	5283f20f 	mov	w15, #0x1f90                	// #8080
 648:	52841f70 	mov	w16, #0x20fb                	// #8443
 64c:	f2af17ac 	movk	x12, #0x78bd, lsl #16
 650:	f2c3ac8c 	movk	x12, #0x1d64, lsl #32
 654:	f2f40ecc 	movk	x12, #0xa076, lsl #48
 658:	14000008 	b	678 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x98>
 65c:	d503201f 	nop
 660:	aa01c051 	orr	x17, x2, x1, lsl #48
 664:	ca0c022c 	eor	x12, x17, x12
 668:	91000529 	add	x9, x9, #0x1
 66c:	9100614a 	add	x10, x10, #0x18
 670:	f100813f 	cmp	x9, #0x20
 674:	54000ac0 	b.eq	7cc <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x1ec>  // b.none
 678:	7840f140 	ldurh	w0, [x10, #15]
 67c:	13003c12 	sxth	w18, w0
 680:	6b0b001f 	cmp	w0, w11
 684:	540001ec 	b.gt	6c0 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0xe0>
 688:	7101401f 	cmp	w0, #0x50
 68c:	540003e0 	b.eq	708 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x128>  // b.none
 690:	7106ec1f 	cmp	w0, #0x1bb
 694:	540002a1 	b.ne	6e8 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x108>  // b.any
 698:	52800051 	mov	w17, #0x2                   	// #2
 69c:	39404541 	ldrb	w1, [x10, #17]
 6a0:	b85fd142 	ldur	w2, [x10, #-3]
 6a4:	7100083f 	cmp	w1, #0x2
 6a8:	54fffdc1 	b.ne	660 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x80>  // b.any
 6ac:	1400001d 	b	720 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x140>
 6b0:	d503201f 	nop
 6b4:	d503201f 	nop
 6b8:	d503201f 	nop
 6bc:	d503201f 	nop
 6c0:	6b0f001f 	cmp	w0, w15
 6c4:	54000060 	b.eq	6d0 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0xf0>  // b.none
 6c8:	6b10001f 	cmp	w0, w16
 6cc:	540000e1 	b.ne	6e8 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x108>  // b.any
 6d0:	52800071 	mov	w17, #0x3                   	// #3
 6d4:	39404541 	ldrb	w1, [x10, #17]
 6d8:	b85fd142 	ldur	w2, [x10, #-3]
 6dc:	7100083f 	cmp	w1, #0x2
 6e0:	54fffc01 	b.ne	660 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x80>  // b.any
 6e4:	1400000f 	b	720 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x140>
 6e8:	6b0e025f 	cmp	w18, w14
 6ec:	1a9fd7f1 	cset	w17, gt
 6f0:	531e7631 	lsl	w17, w17, #2
 6f4:	39404541 	ldrb	w1, [x10, #17]
 6f8:	b85fd142 	ldur	w2, [x10, #-3]
 6fc:	7100083f 	cmp	w1, #0x2
 700:	54fffb01 	b.ne	660 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x80>  // b.any
 704:	14000007 	b	720 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x140>
 708:	52800031 	mov	w17, #0x1                   	// #1
 70c:	39404541 	ldrb	w1, [x10, #17]
 710:	b85fd142 	ldur	w2, [x10, #-3]
 714:	7100083f 	cmp	w1, #0x2
 718:	54fffa41 	b.ne	660 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x80>  // b.any
 71c:	d503201f 	nop
 720:	b8401141 	ldur	w1, [x10, #1]
 724:	39404943 	ldrb	w3, [x10, #18]
 728:	360004c3 	tbz	w3, #0, 7c0 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x1e0>
 72c:	340004b1 	cbz	w17, 7c0 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x1e0>
 730:	b8405140 	ldur	w0, [x10, #5]
 734:	b8409144 	ldur	w4, [x10, #9]
 738:	12003e52 	and	w18, w18, #0xffff
 73c:	721e007f 	tst	w3, #0x4
 740:	4ac46400 	eor	w0, w0, w4, ror #25
 744:	39403545 	ldrb	w5, [x10, #13]
 748:	39403946 	ldrb	w6, [x10, #14]
 74c:	53103ca4 	lsl	w4, w5, #16
 750:	78413147 	ldurh	w7, [x10, #19]
 754:	0b020025 	add	w5, w1, w2
 758:	2a066084 	orr	w4, w4, w6, lsl #24
 75c:	4a040000 	eor	w0, w0, w4
 760:	53020464 	lsl	w4, w3, #30
 764:	0a847ca4 	and	w4, w5, w4, asr #31
 768:	4a040252 	eor	w18, w18, w4
 76c:	4a120012 	eor	w18, w0, w18
 770:	4b1101a0 	sub	w0, w13, w17
 774:	4a070252 	eor	w18, w18, w7
 778:	1ac02e40 	ror	w0, w18, w0
 77c:	1a800252 	csel	w18, w18, w0, eq	// eq = none
 780:	12000920 	and	w0, w9, #0x7
 784:	aa128052 	orr	x18, x2, x18, lsl #32
 788:	11000402 	add	w2, w0, #0x1
 78c:	52001400 	eor	w0, w0, #0x3f
 790:	9ac22242 	lsl	x2, x18, x2
 794:	9ac02652 	lsr	x18, x18, x0
 798:	aa120052 	orr	x18, x2, x18
 79c:	ca0c024c 	eor	x12, x18, x12
 7a0:	d3707cf2 	ubfiz	x18, x7, #16, #32
 7a4:	aa11e251 	orr	x17, x18, x17, lsl #56
 7a8:	ca010231 	eor	x17, x17, x1
 7ac:	8b11018c 	add	x12, x12, x17
 7b0:	17ffffae 	b	668 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x88>
 7b4:	d503201f 	nop
 7b8:	d503201f 	nop
 7bc:	d503201f 	nop
 7c0:	aa018011 	orr	x17, x0, x1, lsl #32
 7c4:	8b0c022c 	add	x12, x17, x12
 7c8:	17ffffa8 	b	668 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x88>
 7cc:	52800040 	mov	w0, #0x2                   	// #2
 7d0:	f900010c 	str	x12, [x8]
 7d4:	d65f03c0 	ret

Disassembly of section .fini:

00000000000007d8 <_fini>:
 7d8:	d503201f 	nop
 7dc:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 7e0:	910003fd 	mov	x29, sp
 7e4:	a8c17bfd 	ldp	x29, x30, [sp], #16
 7e8:	d65f03c0 	ret
```

## Original Kernel JIT ASM
```asm
not captured
```

## llvmbpf JIT ASM
```asm
not captured
```
