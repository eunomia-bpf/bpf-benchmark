# katran_lb_consistent_hash_select

## Original C
```c
not captured
```

## Native ASM
```asm
Disassembly of section .init:

0000000000000498 <_init>:
 498:	d503201f 	nop
 49c:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 4a0:	910003fd 	mov	x29, sp
 4a4:	94000013 	bl	4f0 <call_weak_fn>
 4a8:	a8c17bfd 	ldp	x29, x30, [sp], #16
 4ac:	d65f03c0 	ret

Disassembly of section .plt:

00000000000004b0 <.plt>:
 4b0:	a9bf7bf0 	stp	x16, x30, [sp, #-16]!
 4b4:	f00000f0 	adrp	x16, 1f000 <__FRAME_END__+0x1e330>
 4b8:	f947fe11 	ldr	x17, [x16, #4088]
 4bc:	913fe210 	add	x16, x16, #0xff8
 4c0:	d61f0220 	br	x17
 4c4:	d503201f 	nop
 4c8:	d503201f 	nop
 4cc:	d503201f 	nop

00000000000004d0 <__cxa_finalize@plt>:
 4d0:	90000110 	adrp	x16, 20000 <__cxa_finalize@GLIBC_2.17>
 4d4:	f9400211 	ldr	x17, [x16]
 4d8:	91000210 	add	x16, x16, #0x0
 4dc:	d61f0220 	br	x17

00000000000004e0 <__gmon_start__@plt>:
 4e0:	90000110 	adrp	x16, 20000 <__cxa_finalize@GLIBC_2.17>
 4e4:	f9400611 	ldr	x17, [x16, #8]
 4e8:	91002210 	add	x16, x16, #0x8
 4ec:	d61f0220 	br	x17

Disassembly of section .text:

00000000000004f0 <call_weak_fn>:
 4f0:	f00000e0 	adrp	x0, 1f000 <__FRAME_END__+0x1e330>
 4f4:	f947ec00 	ldr	x0, [x0, #4056]
 4f8:	b4000040 	cbz	x0, 500 <call_weak_fn+0x10>
 4fc:	17fffff9 	b	4e0 <__gmon_start__@plt>
 500:	d65f03c0 	ret
 504:	d503201f 	nop
 508:	d503201f 	nop
 50c:	d503201f 	nop

0000000000000510 <deregister_tm_clones>:
 510:	90000100 	adrp	x0, 20000 <__cxa_finalize@GLIBC_2.17>
 514:	91008000 	add	x0, x0, #0x20
 518:	90000101 	adrp	x1, 20000 <__cxa_finalize@GLIBC_2.17>
 51c:	91008021 	add	x1, x1, #0x20
 520:	eb00003f 	cmp	x1, x0
 524:	540000c0 	b.eq	53c <deregister_tm_clones+0x2c>  // b.none
 528:	f00000e1 	adrp	x1, 1f000 <__FRAME_END__+0x1e330>
 52c:	f947e421 	ldr	x1, [x1, #4040]
 530:	b4000061 	cbz	x1, 53c <deregister_tm_clones+0x2c>
 534:	aa0103f0 	mov	x16, x1
 538:	d61f0200 	br	x16
 53c:	d65f03c0 	ret

0000000000000540 <register_tm_clones>:
 540:	90000100 	adrp	x0, 20000 <__cxa_finalize@GLIBC_2.17>
 544:	91008000 	add	x0, x0, #0x20
 548:	90000101 	adrp	x1, 20000 <__cxa_finalize@GLIBC_2.17>
 54c:	91008021 	add	x1, x1, #0x20
 550:	cb000021 	sub	x1, x1, x0
 554:	d37ffc22 	lsr	x2, x1, #63
 558:	8b810c41 	add	x1, x2, x1, asr #3
 55c:	9341fc21 	asr	x1, x1, #1
 560:	b40000c1 	cbz	x1, 578 <register_tm_clones+0x38>
 564:	f00000e2 	adrp	x2, 1f000 <__FRAME_END__+0x1e330>
 568:	f947f042 	ldr	x2, [x2, #4064]
 56c:	b4000062 	cbz	x2, 578 <register_tm_clones+0x38>
 570:	aa0203f0 	mov	x16, x2
 574:	d61f0200 	br	x16
 578:	d65f03c0 	ret
 57c:	d503201f 	nop

0000000000000580 <__do_global_dtors_aux>:
 580:	d503233f 	paciasp
 584:	a9be7bfd 	stp	x29, x30, [sp, #-32]!
 588:	910003fd 	mov	x29, sp
 58c:	f9000bf3 	str	x19, [sp, #16]
 590:	90000113 	adrp	x19, 20000 <__cxa_finalize@GLIBC_2.17>
 594:	39407260 	ldrb	w0, [x19, #28]
 598:	37000140 	tbnz	w0, #0, 5c0 <__do_global_dtors_aux+0x40>
 59c:	f00000e0 	adrp	x0, 1f000 <__FRAME_END__+0x1e330>
 5a0:	f947e800 	ldr	x0, [x0, #4048]
 5a4:	b4000080 	cbz	x0, 5b4 <__do_global_dtors_aux+0x34>
 5a8:	90000100 	adrp	x0, 20000 <__cxa_finalize@GLIBC_2.17>
 5ac:	f9400800 	ldr	x0, [x0, #16]
 5b0:	97ffffc8 	bl	4d0 <__cxa_finalize@plt>
 5b4:	97ffffd7 	bl	510 <deregister_tm_clones>
 5b8:	52800020 	mov	w0, #0x1                   	// #1
 5bc:	39007260 	strb	w0, [x19, #28]
 5c0:	f9400bf3 	ldr	x19, [sp, #16]
 5c4:	a8c27bfd 	ldp	x29, x30, [sp], #32
 5c8:	d50323bf 	autiasp
 5cc:	d65f03c0 	ret

00000000000005d0 <frame_dummy>:
 5d0:	d503245f 	bti	c
 5d4:	17ffffdb 	b	540 <register_tm_clones>
 5d8:	d503201f 	nop
 5dc:	d503201f 	nop

00000000000005e0 <katran_lb_consistent_hash_select_xdp>:
 5e0:	a9402808 	ldp	x8, x10, [x0]
 5e4:	eb0a011f 	cmp	x8, x10
 5e8:	540000e8 	b.hi	604 <katran_lb_consistent_hash_select_xdp+0x24>  // b.pmore
 5ec:	9100210c 	add	x12, x8, #0x8
 5f0:	eb0a019f 	cmp	x12, x10
 5f4:	54000088 	b.hi	604 <katran_lb_consistent_hash_select_xdp+0x24>  // b.pmore
 5f8:	9100590b 	add	x11, x8, #0x16
 5fc:	eb0a017f 	cmp	x11, x10
 600:	54000069 	b.ls	60c <katran_lb_consistent_hash_select_xdp+0x2c>  // b.plast
 604:	2a1f03e0 	mov	w0, wzr
 608:	d65f03c0 	ret
 60c:	7940290d 	ldrh	w13, [x8, #20]
 610:	d28f82a9 	mov	x9, #0x7c15                	// #31765
 614:	529bb0ce 	mov	w14, #0xdd86                	// #56710
 618:	cb0c014c 	sub	x12, x10, x12
 61c:	f2afe949 	movk	x9, #0x7f4a, lsl #16
 620:	f2cf3729 	movk	x9, #0x79b9, lsl #32
 624:	f2f3c6e9 	movk	x9, #0x9e37, lsl #48
 628:	6b0e01bf 	cmp	w13, w14
 62c:	540012a0 	b.eq	880 <katran_lb_consistent_hash_select_xdp+0x2a0>  // b.none
 630:	710021bf 	cmp	w13, #0x8
 634:	54001521 	b.ne	8d8 <katran_lb_consistent_hash_select_xdp+0x2f8>  // b.any
 638:	9100a90d 	add	x13, x8, #0x2a
 63c:	eb0a01bf 	cmp	x13, x10
 640:	54001648 	b.hi	908 <katran_lb_consistent_hash_select_xdp+0x328>  // b.pmore
 644:	3940016b 	ldrb	w11, [x11]
 648:	12000d6b 	and	w11, w11, #0xf
 64c:	7100157f 	cmp	w11, #0x5
 650:	540015c1 	b.ne	908 <katran_lb_consistent_hash_select_xdp+0x328>  // b.any
 654:	3940710b 	ldrb	w11, [x8, #28]
 658:	3940750d 	ldrb	w13, [x8, #29]
 65c:	1200156b 	and	w11, w11, #0x3f
 660:	2a0d216b 	orr	w11, w11, w13, lsl #8
 664:	3500152b 	cbnz	w11, 908 <katran_lb_consistent_hash_select_xdp+0x328>
 668:	39407d0b 	ldrb	w11, [x8, #31]
 66c:	7100057f 	cmp	w11, #0x1
 670:	54001400 	b.eq	8f0 <katran_lb_consistent_hash_select_xdp+0x310>  // b.none
 674:	7100457f 	cmp	w11, #0x11
 678:	54002c20 	b.eq	bfc <katran_lb_consistent_hash_select_xdp+0x61c>  // b.none
 67c:	7100197f 	cmp	w11, #0x6
 680:	54001381 	b.ne	8f0 <katran_lb_consistent_hash_select_xdp+0x310>  // b.any
 684:	9100f90b 	add	x11, x8, #0x3e
 688:	eb0a017f 	cmp	x11, x10
 68c:	540013e8 	b.hi	908 <katran_lb_consistent_hash_select_xdp+0x328>  // b.pmore
 690:	b842610b 	ldur	w11, [x8, #38]
 694:	528c814d 	mov	w13, #0x640a                	// #25610
 698:	5280004a 	mov	w10, #0x2                   	// #2
 69c:	72a0202d 	movk	w13, #0x101, lsl #16
 6a0:	6b0d017f 	cmp	w11, w13
 6a4:	54001281 	b.ne	8f4 <katran_lb_consistent_hash_select_xdp+0x314>  // b.any
 6a8:	7940590b 	ldrh	w11, [x8, #44]
 6ac:	529203ed 	mov	w13, #0x901f                	// #36895
 6b0:	6b0d017f 	cmp	w11, w13
 6b4:	5280004d 	mov	w13, #0x2                   	// #2
 6b8:	540012c1 	b.ne	910 <katran_lb_consistent_hash_select_xdp+0x330>  // b.any
 6bc:	f117a99f 	cmp	x12, #0x5ea
 6c0:	5400124c 	b.gt	908 <katran_lb_consistent_hash_select_xdp+0x328>
 6c4:	3940910e 	ldrb	w14, [x8, #36]
 6c8:	79404510 	ldrh	w16, [x8, #34]
 6cc:	52981ef1 	mov	w17, #0xc0f7                	// #49399
 6d0:	52ae1981 	mov	w1, #0x70cc0000            	// #1892417536
 6d4:	52981ef2 	mov	w18, #0xc0f7                	// #49399
 6d8:	72ae1991 	movk	w17, #0x70cc, lsl #16
 6dc:	3940950f 	ldrb	w15, [x8, #37]
 6e0:	72bc15b2 	movk	w18, #0xe0ad, lsl #16
 6e4:	7940310a 	ldrh	w10, [x8, #24]
 6e8:	53103dcc 	lsl	w12, w14, #16
 6ec:	33101dd0 	bfi	w16, w14, #16, #8
 6f0:	7940550e 	ldrh	w14, [x8, #42]
 6f4:	53081ded 	lsl	w13, w15, #24
 6f8:	39405d0b 	ldrb	w11, [x8, #23]
 6fc:	5ac0054a 	rev16	w10, w10
 700:	2a0c01ac 	orr	w12, w13, w12
 704:	1100514d 	add	w13, w10, #0x14
 708:	33081df0 	bfi	w16, w15, #24, #8
 70c:	52b203ef 	mov	w15, #0x901f0000            	// #-1877016576
 710:	5ac009ad 	rev	w13, w13
 714:	53107dad 	lsr	w13, w13, #16
 718:	0b1101d1 	add	w17, w14, w17
 71c:	2a0f01cf 	orr	w15, w14, w15
 720:	5ac009ce 	rev	w14, w14
 724:	8b0d016b 	add	x11, x11, x13
 728:	529be76d 	mov	w13, #0xdf3b                	// #57147
 72c:	13814a21 	extr	w1, w17, w1, #18
 730:	4a120220 	eor	w0, w17, w18
 734:	0b120212 	add	w18, w16, w18
 738:	8b304130 	add	x16, x9, w16, uxtw
 73c:	4a0c01cc 	eor	w12, w14, w12
 740:	53107d8e 	lsr	w14, w12, #16
 744:	8b0d01cd 	add	x13, x14, x13
 748:	4b010000 	sub	w0, w0, w1
 74c:	8b0d016b 	add	x11, x11, x13
 750:	4a120012 	eor	w18, w0, w18
 754:	13805401 	ror	w1, w0, #21
 758:	d350fd6d 	lsr	x13, x11, #16
 75c:	f140417f 	cmp	x11, #0x10, lsl #12
 760:	4b010252 	sub	w18, w18, w1
 764:	8b2b21ad 	add	x13, x13, w11, uxth
 768:	4a110251 	eor	w17, w18, w17
 76c:	13921e41 	ror	w1, w18, #7
 770:	4b010231 	sub	w17, w17, w1
 774:	9a8d316b 	csel	x11, x11, x13, cc	// cc = lo, ul, last
 778:	4a000220 	eor	w0, w17, w0
 77c:	13914221 	ror	w1, w17, #16
 780:	d350fd6d 	lsr	x13, x11, #16
 784:	f140417f 	cmp	x11, #0x10, lsl #12
 788:	4b010000 	sub	w0, w0, w1
 78c:	8b2b21ad 	add	x13, x13, w11, uxth
 790:	4a120012 	eor	w18, w0, w18
 794:	13807001 	ror	w1, w0, #28
 798:	4b010252 	sub	w18, w18, w1
 79c:	9a8d316b 	csel	x11, x11, x13, cc	// cc = lo, ul, last
 7a0:	4a110251 	eor	w17, w18, w17
 7a4:	13924a52 	ror	w18, w18, #18
 7a8:	d350fd6d 	lsr	x13, x11, #16
 7ac:	f140417f 	cmp	x11, #0x10, lsl #12
 7b0:	4b120231 	sub	w17, w17, w18
 7b4:	8b2b21ad 	add	x13, x13, w11, uxth
 7b8:	4a000232 	eor	w18, w17, w0
 7bc:	13912231 	ror	w17, w17, #8
 7c0:	528c8140 	mov	w0, #0x640a                	// #25610
 7c4:	4b110251 	sub	w17, w18, w17
 7c8:	129fffd2 	mov	w18, #0xffff0001            	// #-65535
 7cc:	72a02020 	movk	w0, #0x101, lsl #16
 7d0:	9a8d316b 	csel	x11, x11, x13, cc	// cc = lo, ul, last
 7d4:	9bb27e32 	umull	x18, w17, w18
 7d8:	0b4b416d 	add	w13, w11, w11, lsr #16
 7dc:	f140417f 	cmp	x11, #0x10, lsl #12
 7e0:	d370fe52 	lsr	x18, x18, #48
 7e4:	1a8d316b 	csel	w11, w11, w13, cc	// cc = lo, ul, last
 7e8:	2a124252 	orr	w18, w18, w18, lsl #16
 7ec:	53103d6b 	lsl	w11, w11, #16
 7f0:	4b120231 	sub	w17, w17, w18
 7f4:	8b101932 	add	x18, x9, x16, lsl #6
 7f8:	8b500a52 	add	x18, x18, x16, lsr #2
 7fc:	8b000252 	add	x18, x18, x0
 800:	ca100250 	eor	x16, x18, x16
 804:	8b101932 	add	x18, x9, x16, lsl #6
 808:	8b500a52 	add	x18, x18, x16, lsr #2
 80c:	8b0f024f 	add	x15, x18, x15
 810:	ca1001ef 	eor	x15, x15, x16
 814:	8b0f1930 	add	x16, x9, x15, lsl #6
 818:	8b4f0a10 	add	x16, x16, x15, lsr #2
 81c:	8b110210 	add	x16, x16, x17
 820:	ca0f020f 	eor	x15, x16, x15
 824:	8b0f1930 	add	x16, x9, x15, lsl #6
 828:	8b4f0a10 	add	x16, x16, x15, lsr #2
 82c:	91000610 	add	x16, x16, #0x1
 830:	ca0f020f 	eor	x15, x16, x15
 834:	8b0f1930 	add	x16, x9, x15, lsl #6
 838:	8b4f0a10 	add	x16, x16, x15, lsr #2
 83c:	ca0f020f 	eor	x15, x16, x15
 840:	8b090150 	add	x16, x10, x9
 844:	8b0f1a10 	add	x16, x16, x15, lsl #6
 848:	8b4f0a10 	add	x16, x16, x15, lsr #2
 84c:	ca0f020e 	eor	x14, x16, x15
 850:	5282158f 	mov	w15, #0x10ac                	// #4268
 854:	2a0f018c 	orr	w12, w12, w15
 858:	5299014f 	mov	w15, #0xc80a                	// #51210
 85c:	72a0400f 	movk	w15, #0x200, lsl #16
 860:	aa0c81ec 	orr	x12, x15, x12, lsl #32
 864:	ca0a018a 	eor	x10, x12, x10
 868:	d280016c 	mov	x12, #0xb                   	// #11
 86c:	f2bfffec 	movk	x12, #0xffff, lsl #16
 870:	f2c0400c 	movk	x12, #0x200, lsl #32
 874:	ca0c014a 	eor	x10, x10, x12
 878:	ca0b014a 	eor	x10, x10, x11
 87c:	140000d6 	b	bd4 <katran_lb_consistent_hash_select_xdp+0x5f4>
 880:	9100f90b 	add	x11, x8, #0x3e
 884:	eb0a017f 	cmp	x11, x10
 888:	54000408 	b.hi	908 <katran_lb_consistent_hash_select_xdp+0x328>  // b.pmore
 88c:	3940710d 	ldrb	w13, [x8, #28]
 890:	7100b1bf 	cmp	w13, #0x2c
 894:	540003a0 	b.eq	908 <katran_lb_consistent_hash_select_xdp+0x328>  // b.none
 898:	7100e9bf 	cmp	w13, #0x3a
 89c:	540002a0 	b.eq	8f0 <katran_lb_consistent_hash_select_xdp+0x310>  // b.none
 8a0:	39405911 	ldrb	w17, [x8, #22]
 8a4:	39405d00 	ldrb	w0, [x8, #23]
 8a8:	710045bf 	cmp	w13, #0x11
 8ac:	79403512 	ldrh	w18, [x8, #26]
 8b0:	b841e10b 	ldur	w11, [x8, #30]
 8b4:	b8422110 	ldur	w16, [x8, #34]
 8b8:	b842610e 	ldur	w14, [x8, #38]
 8bc:	b842a10f 	ldur	w15, [x8, #42]
 8c0:	b842e101 	ldur	w1, [x8, #46]
 8c4:	540001c0 	b.eq	8fc <katran_lb_consistent_hash_select_xdp+0x31c>  // b.none
 8c8:	710019bf 	cmp	w13, #0x6
 8cc:	54000121 	b.ne	8f0 <katran_lb_consistent_hash_select_xdp+0x310>  // b.any
 8d0:	91014902 	add	x2, x8, #0x52
 8d4:	1400000b 	b	900 <katran_lb_consistent_hash_select_xdp+0x320>
 8d8:	8b09018a 	add	x10, x12, x9
 8dc:	8b0a192b 	add	x11, x9, x10, lsl #6
 8e0:	8b4a096b 	add	x11, x11, x10, lsr #2
 8e4:	9100096b 	add	x11, x11, #0x2
 8e8:	ca0a016a 	eor	x10, x11, x10
 8ec:	14000002 	b	8f4 <katran_lb_consistent_hash_select_xdp+0x314>
 8f0:	5280004a 	mov	w10, #0x2                   	// #2
 8f4:	5280004d 	mov	w13, #0x2                   	// #2
 8f8:	14000006 	b	910 <katran_lb_consistent_hash_select_xdp+0x330>
 8fc:	91011902 	add	x2, x8, #0x46
 900:	eb0a005f 	cmp	x2, x10
 904:	54000149 	b.ls	92c <katran_lb_consistent_hash_select_xdp+0x34c>  // b.plast
 908:	5280002a 	mov	w10, #0x1                   	// #1
 90c:	5280002d 	mov	w13, #0x1                   	// #1
 910:	8b0a1929 	add	x9, x9, x10, lsl #6
 914:	52800040 	mov	w0, #0x2                   	// #2
 918:	8b4a0929 	add	x9, x9, x10, lsr #2
 91c:	8b0d0129 	add	x9, x9, x13
 920:	ca0a0129 	eor	x9, x9, x10
 924:	f9000109 	str	x9, [x8]
 928:	d65f03c0 	ret
 92c:	5280004a 	mov	w10, #0x2                   	// #2
 930:	710019bf 	cmp	w13, #0x6
 934:	54fffe01 	b.ne	8f4 <katran_lb_consistent_hash_select_xdp+0x314>  // b.any
 938:	528c814d 	mov	w13, #0x640a                	// #25610
 93c:	72a0202d 	movk	w13, #0x101, lsl #16
 940:	6b0d003f 	cmp	w1, w13
 944:	54fffd81 	b.ne	8f4 <katran_lb_consistent_hash_select_xdp+0x314>  // b.any
 948:	7940810d 	ldrh	w13, [x8, #64]
 94c:	529203e1 	mov	w1, #0x901f                	// #36895
 950:	6b0101bf 	cmp	w13, w1
 954:	5280004d 	mov	w13, #0x2                   	// #2
 958:	54fffdc1 	b.ne	910 <katran_lb_consistent_hash_select_xdp+0x330>  // b.any
 95c:	f117a99f 	cmp	x12, #0x5ea
 960:	54fffd4c 	b.gt	908 <katran_lb_consistent_hash_select_xdp+0x328>
 964:	52981fed 	mov	w13, #0xc0ff                	// #49407
 968:	53081c0a 	lsl	w10, w0, #24
 96c:	12101de0 	and	w0, w15, #0xff0000
 970:	12181de1 	and	w1, w15, #0xff00
 974:	72bbd5ad 	movk	w13, #0xdead, lsl #16
 978:	138a722c 	extr	w12, w17, w10, #28
 97c:	5ac0064a 	rev16	w10, w18
 980:	12081df1 	and	w17, w15, #0xff000000
 984:	12001def 	and	w15, w15, #0xff
 988:	0b0d01d2 	add	w18, w14, w13
 98c:	4b0e016e 	sub	w14, w11, w14
 990:	0b0d0210 	add	w16, w16, w13
 994:	79407d0d 	ldrh	w13, [x8, #62]
 998:	0b000231 	add	w17, w17, w0
 99c:	4ad271ce 	eor	w14, w14, w18, ror #28
 9a0:	0b010231 	add	w17, w17, w1
 9a4:	4b0e0202 	sub	w2, w16, w14
 9a8:	0b100250 	add	w16, w18, w16
 9ac:	0b0f022f 	add	w15, w17, w15
 9b0:	4ace6842 	eor	w2, w2, w14, ror #26
 9b4:	0b1001ce 	add	w14, w14, w16
 9b8:	4b020210 	sub	w16, w16, w2
 9bc:	0b0e0052 	add	w18, w2, w14
 9c0:	4ac26210 	eor	w16, w16, w2, ror #24
 9c4:	4b1001ce 	sub	w14, w14, w16
 9c8:	4ad041ce 	eor	w14, w14, w16, ror #16
 9cc:	0b120210 	add	w16, w16, w18
 9d0:	4b0e0242 	sub	w2, w18, w14
 9d4:	4ace3442 	eor	w2, w2, w14, ror #13
 9d8:	0b1001ce 	add	w14, w14, w16
 9dc:	4b020210 	sub	w16, w16, w2
 9e0:	0b0e0052 	add	w18, w2, w14
 9e4:	0b0e01ee 	add	w14, w15, w14
 9e8:	4ac27210 	eor	w16, w16, w2, ror #28
 9ec:	4a12020f 	eor	w15, w16, w18
 9f0:	13924a50 	ror	w16, w18, #18
 9f4:	4b1001ef 	sub	w15, w15, w16
 9f8:	4a0f01ce 	eor	w14, w14, w15
 9fc:	138f55f0 	ror	w16, w15, #21
 a00:	4b1001ce 	sub	w14, w14, w16
 a04:	4a1201d0 	eor	w16, w14, w18
 a08:	138e1dd1 	ror	w17, w14, #7
 a0c:	52ae1992 	mov	w18, #0x70cc0000            	// #1892417536
 a10:	4b110210 	sub	w16, w16, w17
 a14:	4a0f020f 	eor	w15, w16, w15
 a18:	13904211 	ror	w17, w16, #16
 a1c:	4b1101ef 	sub	w15, w15, w17
 a20:	4a0e01ee 	eor	w14, w15, w14
 a24:	138f71f1 	ror	w17, w15, #28
 a28:	4b1101ce 	sub	w14, w14, w17
 a2c:	52981ef1 	mov	w17, #0xc0f7                	// #49399
 a30:	4a1001d0 	eor	w16, w14, w16
 a34:	138e49ce 	ror	w14, w14, #18
 a38:	72ae1991 	movk	w17, #0x70cc, lsl #16
 a3c:	4b0e020e 	sub	w14, w16, w14
 a40:	0b1101b1 	add	w17, w13, w17
 a44:	138e21d0 	ror	w16, w14, #8
 a48:	4a0f01ce 	eor	w14, w14, w15
 a4c:	13924a32 	extr	w18, w17, w18, #18
 a50:	52b203ef 	mov	w15, #0x901f0000            	// #-1877016576
 a54:	4b1001ce 	sub	w14, w14, w16
 a58:	52981ef0 	mov	w16, #0xc0f7                	// #49399
 a5c:	2a0f01af 	orr	w15, w13, w15
 a60:	5ac009ad 	rev	w13, w13
 a64:	72bc15b0 	movk	w16, #0xe0ad, lsl #16
 a68:	8b0901ef 	add	x15, x15, x9
 a6c:	0b1001ce 	add	w14, w14, w16
 a70:	4a100230 	eor	w16, w17, w16
 a74:	4b120210 	sub	w16, w16, w18
 a78:	4a1001ce 	eor	w14, w14, w16
 a7c:	13905612 	ror	w18, w16, #21
 a80:	4b1201ce 	sub	w14, w14, w18
 a84:	4a1101d1 	eor	w17, w14, w17
 a88:	138e1dd2 	ror	w18, w14, #7
 a8c:	4b120231 	sub	w17, w17, w18
 a90:	4a100230 	eor	w16, w17, w16
 a94:	13914232 	ror	w18, w17, #16
 a98:	4b120210 	sub	w16, w16, w18
 a9c:	4a0e020e 	eor	w14, w16, w14
 aa0:	13907212 	ror	w18, w16, #28
 aa4:	4b1201ce 	sub	w14, w14, w18
 aa8:	d29c03f2 	mov	x18, #0xe01f                	// #57375
 aac:	4a1101d1 	eor	w17, w14, w17
 ab0:	138e49ce 	ror	w14, w14, #18
 ab4:	f2b00972 	movk	x18, #0x804b, lsl #16
 ab8:	4b0e022e 	sub	w14, w17, w14
 abc:	f2cf3732 	movk	x18, #0x79b9, lsl #32
 ac0:	4a1001d0 	eor	w16, w14, w16
 ac4:	138e21ce 	ror	w14, w14, #8
 ac8:	f2f3c6f2 	movk	x18, #0x9e37, lsl #48
 acc:	4b0e020e 	sub	w14, w16, w14
 ad0:	129fffd0 	mov	w16, #0xffff0001            	// #-65535
 ad4:	9bb07dd0 	umull	x16, w14, w16
 ad8:	d370fe10 	lsr	x16, x16, #48
 adc:	2a104210 	orr	w16, w16, w16, lsl #16
 ae0:	4b1001ce 	sub	w14, w14, w16
 ae4:	8b090170 	add	x16, x11, x9
 ae8:	12103d6b 	and	w11, w11, #0xffff0000
 aec:	d37ae611 	lsl	x17, x16, #6
 af0:	4a0b01ab 	eor	w11, w13, w11
 af4:	1100514d 	add	w13, w10, #0x14
 af8:	8b500a31 	add	x17, x17, x16, lsr #2
 afc:	5ac009ad 	rev	w13, w13
 b00:	53107dad 	lsr	w13, w13, #16
 b04:	8b120231 	add	x17, x17, x18
 b08:	8b2c01ac 	add	x12, x13, w12, uxtb
 b0c:	529be76d 	mov	w13, #0xdf3b                	// #57147
 b10:	ca100230 	eor	x16, x17, x16
 b14:	8b1019ef 	add	x15, x15, x16, lsl #6
 b18:	8b5009ef 	add	x15, x15, x16, lsr #2
 b1c:	ca1001ef 	eor	x15, x15, x16
 b20:	8b0f1930 	add	x16, x9, x15, lsl #6
 b24:	8b4f0a10 	add	x16, x16, x15, lsr #2
 b28:	8b0e020e 	add	x14, x16, x14
 b2c:	53107d70 	lsr	w16, w11, #16
 b30:	ca0f01ce 	eor	x14, x14, x15
 b34:	8b0d020d 	add	x13, x16, x13
 b38:	8b0e192f 	add	x15, x9, x14, lsl #6
 b3c:	8b0d018c 	add	x12, x12, x13
 b40:	d350fd8d 	lsr	x13, x12, #16
 b44:	f140419f 	cmp	x12, #0x10, lsl #12
 b48:	8b4e09ef 	add	x15, x15, x14, lsr #2
 b4c:	8b2c21ad 	add	x13, x13, w12, uxth
 b50:	910005ef 	add	x15, x15, #0x1
 b54:	9a8d318c 	csel	x12, x12, x13, cc	// cc = lo, ul, last
 b58:	ca0e01ee 	eor	x14, x15, x14
 b5c:	d350fd8d 	lsr	x13, x12, #16
 b60:	f140419f 	cmp	x12, #0x10, lsl #12
 b64:	8b0e192f 	add	x15, x9, x14, lsl #6
 b68:	8b2c21ad 	add	x13, x13, w12, uxth
 b6c:	8b4e09ef 	add	x15, x15, x14, lsr #2
 b70:	9a8d318c 	csel	x12, x12, x13, cc	// cc = lo, ul, last
 b74:	d350fd8d 	lsr	x13, x12, #16
 b78:	f140419f 	cmp	x12, #0x10, lsl #12
 b7c:	ca0e01ee 	eor	x14, x15, x14
 b80:	8b09014f 	add	x15, x10, x9
 b84:	8b2c21ad 	add	x13, x13, w12, uxth
 b88:	8b0e19ef 	add	x15, x15, x14, lsl #6
 b8c:	9a8d318c 	csel	x12, x12, x13, cc	// cc = lo, ul, last
 b90:	8b4e09ef 	add	x15, x15, x14, lsr #2
 b94:	0b4c418d 	add	w13, w12, w12, lsr #16
 b98:	f140419f 	cmp	x12, #0x10, lsl #12
 b9c:	ca0e01ee 	eor	x14, x15, x14
 ba0:	5282158f 	mov	w15, #0x10ac                	// #4268
 ba4:	1a8d318c 	csel	w12, w12, w13, cc	// cc = lo, ul, last
 ba8:	2a0f016b 	orr	w11, w11, w15
 bac:	5299014f 	mov	w15, #0xc80a                	// #51210
 bb0:	53103d8c 	lsl	w12, w12, #16
 bb4:	72a0400f 	movk	w15, #0x200, lsl #16
 bb8:	aa0b81eb 	orr	x11, x15, x11, lsl #32
 bbc:	ca0a016a 	eor	x10, x11, x10
 bc0:	d280016b 	mov	x11, #0xb                   	// #11
 bc4:	f2bfffeb 	movk	x11, #0xffff, lsl #16
 bc8:	f2c0400b 	movk	x11, #0x200, lsl #32
 bcc:	ca0b014a 	eor	x10, x10, x11
 bd0:	ca0c014a 	eor	x10, x10, x12
 bd4:	8b0e192b 	add	x11, x9, x14, lsl #6
 bd8:	5280006d 	mov	w13, #0x3                   	// #3
 bdc:	8b4e096b 	add	x11, x11, x14, lsr #2
 be0:	8b0a016a 	add	x10, x11, x10
 be4:	ca0e014a 	eor	x10, x10, x14
 be8:	8b0a192b 	add	x11, x9, x10, lsl #6
 bec:	8b4a096b 	add	x11, x11, x10, lsr #2
 bf0:	91000d6b 	add	x11, x11, #0x3
 bf4:	ca0a016a 	eor	x10, x11, x10
 bf8:	17ffff46 	b	910 <katran_lb_consistent_hash_select_xdp+0x330>
 bfc:	9100c90b 	add	x11, x8, #0x32
 c00:	eb0a017f 	cmp	x11, x10
 c04:	5280002a 	mov	w10, #0x1                   	// #1
 c08:	9a8a854a 	cinc	x10, x10, ls	// ls = plast
 c0c:	aa0a03ed 	mov	x13, x10
 c10:	17ffff40 	b	910 <katran_lb_consistent_hash_select_xdp+0x330>

Disassembly of section .fini:

0000000000000c14 <_fini>:
 c14:	d503201f 	nop
 c18:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 c1c:	910003fd 	mov	x29, sp
 c20:	a8c17bfd 	ldp	x29, x30, [sp], #16
 c24:	d65f03c0 	ret
```

## Original Kernel JIT ASM
```asm
not captured
```

## llvmbpf JIT ASM
```asm
not captured
```
