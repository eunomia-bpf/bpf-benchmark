# cilium_socket_lb_service_select

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
 494:	f00000f0 	adrp	x16, 1f000 <__FRAME_END__+0x1e7f0>
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
 4e0:	f00000e0 	adrp	x0, 1f000 <__FRAME_END__+0x1e7f0>
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
 518:	f00000e1 	adrp	x1, 1f000 <__FRAME_END__+0x1e7f0>
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
 554:	f00000e2 	adrp	x2, 1f000 <__FRAME_END__+0x1e7f0>
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
 58c:	f00000e0 	adrp	x0, 1f000 <__FRAME_END__+0x1e7f0>
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

00000000000005e0 <cilium_socket_lb_service_select_xdp>:
 5e0:	a9402408 	ldp	x8, x9, [x0]
 5e4:	aa0803ea 	mov	x10, x8
 5e8:	eb09015f 	cmp	x10, x9
 5ec:	54000069 	b.ls	5f8 <cilium_socket_lb_service_select_xdp+0x18>  // b.plast
 5f0:	2a1f03e0 	mov	w0, wzr
 5f4:	d65f03c0 	ret
 5f8:	9100214b 	add	x11, x10, #0x8
 5fc:	9118414c 	add	x12, x10, #0x610
 600:	eb09017f 	cmp	x11, x9
 604:	fa499182 	ccmp	x12, x9, #0x2, ls	// ls = plast
 608:	54000069 	b.ls	614 <cilium_socket_lb_service_select_xdp+0x34>  // b.plast
 60c:	2a1f03e0 	mov	w0, wzr
 610:	d65f03c0 	ret
 614:	29412d49 	ldp	w9, w11, [x10, #8]
 618:	7101013f 	cmp	w9, #0x40
 61c:	7a580960 	ccmp	w11, #0x18, #0x0, eq	// eq = none
 620:	54000060 	b.eq	62c <cilium_socket_lb_service_select_xdp+0x4c>  // b.none
 624:	2a1f03e0 	mov	w0, wzr
 628:	d65f03c0 	ret
 62c:	d2811a6c 	mov	x12, #0x8d3                 	// #2259
 630:	aa1f03e9 	mov	x9, xzr
 634:	91004d4a 	add	x10, x10, #0x13
 638:	528ea5eb 	mov	w11, #0x752f                	// #29999
 63c:	f2b0b46c 	movk	x12, #0x85a3, lsl #16
 640:	f2cd510c 	movk	x12, #0x6a88, lsl #32
 644:	f2e487ec 	movk	x12, #0x243f, lsl #48
 648:	14000007 	b	664 <cilium_socket_lb_service_select_xdp+0x84>
 64c:	aa0d81cd 	orr	x13, x14, x13, lsl #32
 650:	ca0c01ac 	eor	x12, x13, x12
 654:	91000529 	add	x9, x9, #0x1
 658:	9100614a 	add	x10, x10, #0x18
 65c:	f101013f 	cmp	x9, #0x40
 660:	54000760 	b.eq	74c <cilium_socket_lb_service_select_xdp+0x16c>  // b.none
 664:	39402950 	ldrb	w16, [x10, #10]
 668:	b8401152 	ldur	w18, [x10, #1]
 66c:	721f021f 	tst	w16, #0x2
 670:	3940254d 	ldrb	w13, [x10, #9]
 674:	7840b151 	ldurh	w17, [x10, #11]
 678:	7840714e 	ldurh	w14, [x10, #7]
 67c:	1a9f024f 	csel	w15, w18, wzr, eq	// eq = none
 680:	710045bf 	cmp	w13, #0x11
 684:	7a4619a4 	ccmp	w13, #0x6, #0x4, ne	// ne = any
 688:	7a400a24 	ccmp	w17, #0x0, #0x4, eq	// eq = none
 68c:	54fffe00 	b.eq	64c <cilium_socket_lb_service_select_xdp+0x6c>  // b.none
 690:	b85fd142 	ldur	w2, [x10, #-3]
 694:	78405141 	ldurh	w1, [x10, #5]
 698:	6b2ea17f 	cmp	w11, w14, sxth
 69c:	b840d143 	ldur	w3, [x10, #13]
 6a0:	b8411140 	ldur	w0, [x10, #17]
 6a4:	5400012b 	b.lt	6c8 <cilium_socket_lb_service_select_xdp+0xe8>  // b.tstop
 6a8:	37080110 	tbnz	w16, #1, 6c8 <cilium_socket_lb_service_select_xdp+0xe8>
 6ac:	aa12402d 	orr	x13, x1, x18, lsl #16
 6b0:	8b0c01ac 	add	x12, x13, x12
 6b4:	91000529 	add	x9, x9, #0x1
 6b8:	9100614a 	add	x10, x10, #0x18
 6bc:	f101013f 	cmp	x9, #0x40
 6c0:	54fffd21 	b.ne	664 <cilium_socket_lb_service_select_xdp+0x84>  // b.any
 6c4:	14000022 	b	74c <cilium_socket_lb_service_select_xdp+0x16c>
 6c8:	4a014052 	eor	w18, w2, w1, lsl #16
 6cc:	4a0301c1 	eor	w1, w14, w3
 6d0:	2a2d03e2 	mvn	w2, w13
 6d4:	8b0d018c 	add	x12, x12, x13
 6d8:	4a010252 	eor	w18, w18, w1
 6dc:	0b100001 	add	w1, w0, w16
 6e0:	321d0442 	orr	w2, w2, #0x18
 6e4:	53030a10 	lsl	w16, w16, #29
 6e8:	11000400 	add	w0, w0, #0x1
 6ec:	4a0f0252 	eor	w18, w18, w15
 6f0:	d3707def 	ubfiz	x15, x15, #16, #32
 6f4:	0a907c10 	and	w16, w0, w16, asr #31
 6f8:	0b120021 	add	w1, w1, w18
 6fc:	ca0e81ee 	eor	x14, x15, x14, lsl #32
 700:	1ac22c21 	ror	w1, w1, w2
 704:	8b0e018c 	add	x12, x12, x14
 708:	1200092e 	and	w14, w9, #0x7
 70c:	4a120032 	eor	w18, w1, w18
 710:	110005cf 	add	w15, w14, #0x1
 714:	520015ce 	eor	w14, w14, #0x3f
 718:	1ad10a41 	udiv	w1, w18, w17
 71c:	1b11c831 	msub	w17, w1, w17, w18
 720:	11000631 	add	w17, w17, #0x1
 724:	4a100230 	eor	w16, w17, w16
 728:	aa10c24d 	orr	x13, x18, x16, lsl #48
 72c:	9acf21af 	lsl	x15, x13, x15
 730:	9ace25ad 	lsr	x13, x13, x14
 734:	aa0d01ed 	orr	x13, x15, x13
 738:	ca0c01ac 	eor	x12, x13, x12
 73c:	91000529 	add	x9, x9, #0x1
 740:	9100614a 	add	x10, x10, #0x18
 744:	f101013f 	cmp	x9, #0x40
 748:	54fff8e1 	b.ne	664 <cilium_socket_lb_service_select_xdp+0x84>  // b.any
 74c:	52800040 	mov	w0, #0x2                   	// #2
 750:	f900010c 	str	x12, [x8]
 754:	d65f03c0 	ret

Disassembly of section .fini:

0000000000000758 <_fini>:
 758:	d503201f 	nop
 75c:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 760:	910003fd 	mov	x29, sp
 764:	a8c17bfd 	ldp	x29, x30, [sp], #16
 768:	d65f03c0 	ret
```

## Original Kernel JIT ASM
```asm
not captured
```

## llvmbpf JIT ASM
```asm
not captured
```
