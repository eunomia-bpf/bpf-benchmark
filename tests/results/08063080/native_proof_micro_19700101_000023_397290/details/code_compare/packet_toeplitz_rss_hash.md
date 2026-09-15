# packet_toeplitz_rss_hash

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
 484:	f00000f0 	adrp	x16, 1f000 <__FRAME_END__+0x1e668>
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
 4c0:	f00000e0 	adrp	x0, 1f000 <__FRAME_END__+0x1e668>
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
 4f8:	f00000e1 	adrp	x1, 1f000 <__FRAME_END__+0x1e668>
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
 534:	f00000e2 	adrp	x2, 1f000 <__FRAME_END__+0x1e668>
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
 56c:	f00000e0 	adrp	x0, 1f000 <__FRAME_END__+0x1e668>
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

00000000000005c0 <packet_toeplitz_rss_hash_xdp>:
 5c0:	a9402808 	ldp	x8, x10, [x0]
 5c4:	aa0803e9 	mov	x9, x8
 5c8:	eb0a013f 	cmp	x9, x10
 5cc:	540002e8 	b.hi	628 <packet_toeplitz_rss_hash_xdp+0x68>  // b.pmore
 5d0:	9100212b 	add	x11, x9, #0x8
 5d4:	9100f92c 	add	x12, x9, #0x3e
 5d8:	eb0a017f 	cmp	x11, x10
 5dc:	fa4a9182 	ccmp	x12, x10, #0x2, ls	// ls = plast
 5e0:	54000248 	b.hi	628 <packet_toeplitz_rss_hash_xdp+0x68>  // b.pmore
 5e4:	7940292a 	ldrh	w10, [x9, #20]
 5e8:	5ac0054a 	rev16	w10, w10
 5ec:	7120015f 	cmp	w10, #0x800
 5f0:	540001c1 	b.ne	628 <packet_toeplitz_rss_hash_xdp+0x68>  // b.any
 5f4:	3940592a 	ldrb	w10, [x9, #22]
 5f8:	12000d4a 	and	w10, w10, #0xf
 5fc:	7100155f 	cmp	w10, #0x5
 600:	54000141 	b.ne	628 <packet_toeplitz_rss_hash_xdp+0x68>  // b.any
 604:	aa0903eb 	mov	x11, x9
 608:	3841fd6a 	ldrb	w10, [x11, #31]!
 60c:	7100195f 	cmp	w10, #0x6
 610:	540000c1 	b.ne	628 <packet_toeplitz_rss_hash_xdp+0x68>  // b.any
 614:	2a1f03ea 	mov	w10, wzr
 618:	2a1f03ec 	mov	w12, wzr
 61c:	9100892d 	add	x13, x9, #0x22
 620:	5280010e 	mov	w14, #0x8                   	// #8
 624:	1400000f 	b	660 <packet_toeplitz_rss_hash_xdp+0xa0>
 628:	2a1f03e0 	mov	w0, wzr
 62c:	d65f03c0 	ret
 630:	52801852 	mov	w18, #0xc2                  	// #194
 634:	d503201f 	nop
 638:	d503201f 	nop
 63c:	d503201f 	nop
 640:	1acf2230 	lsl	w16, w17, w15
 644:	4b0f01cf 	sub	w15, w14, w15
 648:	1acf264f 	lsr	w15, w18, w15
 64c:	2a1001f1 	orr	w17, w15, w16
 650:	4a0a022a 	eor	w10, w17, w10
 654:	1100058c 	add	w12, w12, #0x1
 658:	7101a19f 	cmp	w12, #0x68
 65c:	54001100 	b.eq	87c <packet_toeplitz_rss_hash_xdp+0x2bc>  // b.none
 660:	53037d90 	lsr	w16, w12, #3
 664:	71007d9f 	cmp	w12, #0x1f
 668:	54000109 	b.ls	688 <packet_toeplitz_rss_hash_xdp+0xc8>  // b.plast
 66c:	7100fd9f 	cmp	w12, #0x3f
 670:	540000c9 	b.ls	688 <packet_toeplitz_rss_hash_xdp+0xc8>  // b.plast
 674:	71013d9f 	cmp	w12, #0x4f
 678:	54000089 	b.ls	688 <packet_toeplitz_rss_hash_xdp+0xc8>  // b.plast
 67c:	71017d9f 	cmp	w12, #0x5f
 680:	aa0b03ef 	mov	x15, x11
 684:	54000048 	b.hi	68c <packet_toeplitz_rss_hash_xdp+0xcc>  // b.pmore
 688:	8b3041af 	add	x15, x13, w16, uxtw
 68c:	394001f1 	ldrb	w17, [x15]
 690:	1200098f 	and	w15, w12, #0x7
 694:	1acf2231 	lsl	w17, w17, w15
 698:	363ffdf1 	tbz	w17, #7, 654 <packet_toeplitz_rss_hash_xdp+0x94>
 69c:	7100161f 	cmp	w16, #0x5
 6a0:	5400016d 	b.le	6cc <packet_toeplitz_rss_hash_xdp+0x10c>
 6a4:	7100221f 	cmp	w16, #0x8
 6a8:	5400024d 	b.le	6f0 <packet_toeplitz_rss_hash_xdp+0x130>
 6ac:	71002a1f 	cmp	w16, #0xa
 6b0:	5400040c 	b.gt	730 <packet_toeplitz_rss_hash_xdp+0x170>
 6b4:	7100261f 	cmp	w16, #0x9
 6b8:	54000681 	b.ne	788 <packet_toeplitz_rss_hash_xdp+0x1c8>  // b.any
 6bc:	5287a012 	mov	w18, #0x3d00                	// #15616
 6c0:	52800871 	mov	w17, #0x43                  	// #67
 6c4:	72ace4b2 	movk	w18, #0x6725, lsl #16
 6c8:	1400003f 	b	7c4 <packet_toeplitz_rss_hash_xdp+0x204>
 6cc:	71000a1f 	cmp	w16, #0x2
 6d0:	5400020c 	b.gt	710 <packet_toeplitz_rss_hash_xdp+0x150>
 6d4:	34000430 	cbz	w16, 758 <packet_toeplitz_rss_hash_xdp+0x198>
 6d8:	7100061f 	cmp	w16, #0x1
 6dc:	54000661 	b.ne	7a8 <packet_toeplitz_rss_hash_xdp+0x1e8>  // b.any
 6e0:	529b4012 	mov	w18, #0xda00                	// #55808
 6e4:	528004b1 	mov	w17, #0x25                  	// #37
 6e8:	72ab4ad2 	movk	w18, #0x5a56, lsl #16
 6ec:	14000036 	b	7c4 <packet_toeplitz_rss_hash_xdp+0x204>
 6f0:	71001a1f 	cmp	w16, #0x6
 6f4:	540002a0 	b.eq	748 <packet_toeplitz_rss_hash_xdp+0x188>  // b.none
 6f8:	71001e1f 	cmp	w16, #0x7
 6fc:	540003e1 	b.ne	778 <packet_toeplitz_rss_hash_xdp+0x1b8>  // b.any
 700:	528ce012 	mov	w18, #0x6700                	// #26368
 704:	528004b1 	mov	w17, #0x25                  	// #37
 708:	72b84832 	movk	w18, #0xc241, lsl #16
 70c:	1400002e 	b	7c4 <packet_toeplitz_rss_hash_xdp+0x204>
 710:	71000e1f 	cmp	w16, #0x3
 714:	540002a0 	b.eq	768 <packet_toeplitz_rss_hash_xdp+0x1a8>  // b.none
 718:	7100121f 	cmp	w16, #0x4
 71c:	540004e1 	b.ne	7b8 <packet_toeplitz_rss_hash_xdp+0x1f8>  // b.any
 720:	5281c012 	mov	w18, #0xe00                 	// #3584
 724:	52801851 	mov	w17, #0xc2                  	// #194
 728:	72a4ab72 	movk	w18, #0x255b, lsl #16
 72c:	14000026 	b	7c4 <packet_toeplitz_rss_hash_xdp+0x204>
 730:	71002e1f 	cmp	w16, #0xb
 734:	54000321 	b.ne	798 <packet_toeplitz_rss_hash_xdp+0x1d8>  // b.any
 738:	52946012 	mov	w18, #0xa300                	// #41728
 73c:	528011f1 	mov	w17, #0x8f                  	// #143
 740:	72a7a872 	movk	w18, #0x3d43, lsl #16
 744:	14000020 	b	7c4 <packet_toeplitz_rss_hash_xdp+0x204>
 748:	52882012 	mov	w18, #0x4100                	// #16640
 74c:	52800cf1 	mov	w17, #0x67                  	// #103
 750:	72a1d852 	movk	w18, #0xec2, lsl #16
 754:	1400001c 	b	7c4 <packet_toeplitz_rss_hash_xdp+0x204>
 758:	528ac012 	mov	w18, #0x5600                	// #22016
 75c:	52801b51 	mov	w17, #0xda                  	// #218
 760:	72adab52 	movk	w18, #0x6d5a, lsl #16
 764:	14000018 	b	7c4 <packet_toeplitz_rss_hash_xdp+0x204>
 768:	528b6012 	mov	w18, #0x5b00                	// #23296
 76c:	528001d1 	mov	w17, #0xe                   	// #14
 770:	72bb44b2 	movk	w18, #0xda25, lsl #16
 774:	14000014 	b	7c4 <packet_toeplitz_rss_hash_xdp+0x204>
 778:	5284a012 	mov	w18, #0x2500                	// #9472
 77c:	528007b1 	mov	w17, #0x3d                  	// #61
 780:	72a82cf2 	movk	w18, #0x4167, lsl #16
 784:	14000010 	b	7c4 <packet_toeplitz_rss_hash_xdp+0x204>
 788:	52886012 	mov	w18, #0x4300                	// #17152
 78c:	52801471 	mov	w17, #0xa3                  	// #163
 790:	72a4a7b2 	movk	w18, #0x253d, lsl #16
 794:	1400000c 	b	7c4 <packet_toeplitz_rss_hash_xdp+0x204>
 798:	5291e012 	mov	w18, #0x8f00                	// #36608
 79c:	52801611 	mov	w17, #0xb0                  	// #176
 7a0:	72a87472 	movk	w18, #0x43a3, lsl #16
 7a4:	14000008 	b	7c4 <packet_toeplitz_rss_hash_xdp+0x204>
 7a8:	5284a012 	mov	w18, #0x2500                	// #9472
 7ac:	52800b71 	mov	w17, #0x5b                  	// #91
 7b0:	72aadb52 	movk	w18, #0x56da, lsl #16
 7b4:	14000004 	b	7c4 <packet_toeplitz_rss_hash_xdp+0x204>
 7b8:	52984012 	mov	w18, #0xc200                	// #49664
 7bc:	52800831 	mov	w17, #0x41                  	// #65
 7c0:	72ab61d2 	movk	w18, #0x5b0e, lsl #16
 7c4:	2a120231 	orr	w17, w17, w18
 7c8:	34fff44f 	cbz	w15, 650 <packet_toeplitz_rss_hash_xdp+0x90>
 7cc:	528004b2 	mov	w18, #0x25                  	// #37
 7d0:	7100161f 	cmp	w16, #0x5
 7d4:	5400012d 	b.le	7f8 <packet_toeplitz_rss_hash_xdp+0x238>
 7d8:	7100221f 	cmp	w16, #0x8
 7dc:	540001cd 	b.le	814 <packet_toeplitz_rss_hash_xdp+0x254>
 7e0:	71002a1f 	cmp	w16, #0xa
 7e4:	5400030c 	b.gt	844 <packet_toeplitz_rss_hash_xdp+0x284>
 7e8:	7100261f 	cmp	w16, #0x9
 7ec:	54000381 	b.ne	85c <packet_toeplitz_rss_hash_xdp+0x29c>  // b.any
 7f0:	52801472 	mov	w18, #0xa3                  	// #163
 7f4:	17ffff93 	b	640 <packet_toeplitz_rss_hash_xdp+0x80>
 7f8:	71000a1f 	cmp	w16, #0x2
 7fc:	5400018c 	b.gt	82c <packet_toeplitz_rss_hash_xdp+0x26c>
 800:	34fff210 	cbz	w16, 640 <packet_toeplitz_rss_hash_xdp+0x80>
 804:	7100061f 	cmp	w16, #0x1
 808:	54000321 	b.ne	86c <packet_toeplitz_rss_hash_xdp+0x2ac>  // b.any
 80c:	52800b72 	mov	w18, #0x5b                  	// #91
 810:	17ffff8c 	b	640 <packet_toeplitz_rss_hash_xdp+0x80>
 814:	71001a1f 	cmp	w16, #0x6
 818:	54fff140 	b.eq	640 <packet_toeplitz_rss_hash_xdp+0x80>  // b.none
 81c:	71001e1f 	cmp	w16, #0x7
 820:	540001a1 	b.ne	854 <packet_toeplitz_rss_hash_xdp+0x294>  // b.any
 824:	528007b2 	mov	w18, #0x3d                  	// #61
 828:	17ffff86 	b	640 <packet_toeplitz_rss_hash_xdp+0x80>
 82c:	71000e1f 	cmp	w16, #0x3
 830:	54fff000 	b.eq	630 <packet_toeplitz_rss_hash_xdp+0x70>  // b.none
 834:	7100121f 	cmp	w16, #0x4
 838:	540001e1 	b.ne	874 <packet_toeplitz_rss_hash_xdp+0x2b4>  // b.any
 83c:	52800832 	mov	w18, #0x41                  	// #65
 840:	17ffff80 	b	640 <packet_toeplitz_rss_hash_xdp+0x80>
 844:	71002e1f 	cmp	w16, #0xb
 848:	540000e1 	b.ne	864 <packet_toeplitz_rss_hash_xdp+0x2a4>  // b.any
 84c:	52801612 	mov	w18, #0xb0                  	// #176
 850:	17ffff7c 	b	640 <packet_toeplitz_rss_hash_xdp+0x80>
 854:	52800872 	mov	w18, #0x43                  	// #67
 858:	17ffff7a 	b	640 <packet_toeplitz_rss_hash_xdp+0x80>
 85c:	528011f2 	mov	w18, #0x8f                  	// #143
 860:	17ffff78 	b	640 <packet_toeplitz_rss_hash_xdp+0x80>
 864:	52801a12 	mov	w18, #0xd0                  	// #208
 868:	17ffff76 	b	640 <packet_toeplitz_rss_hash_xdp+0x80>
 86c:	528001d2 	mov	w18, #0xe                   	// #14
 870:	17ffff74 	b	640 <packet_toeplitz_rss_hash_xdp+0x80>
 874:	52800cf2 	mov	w18, #0x67                  	// #103
 878:	17ffff72 	b	640 <packet_toeplitz_rss_hash_xdp+0x80>
 87c:	b842212b 	ldur	w11, [x9, #34]
 880:	b842612c 	ldur	w12, [x9, #38]
 884:	52800040 	mov	w0, #0x2                   	// #2
 888:	4a0b018b 	eor	w11, w12, w11
 88c:	3940a92d 	ldrb	w13, [x9, #42]
 890:	3940ad2e 	ldrb	w14, [x9, #43]
 894:	3940b12f 	ldrb	w15, [x9, #44]
 898:	3940b529 	ldrb	w9, [x9, #45]
 89c:	d3481dad 	lsl	x13, x13, #56
 8a0:	5ac0096b 	rev	w11, w11
 8a4:	aa0ec1ad 	orr	x13, x13, x14, lsl #48
 8a8:	4a0a016c 	eor	w12, w11, w10
 8ac:	aa0fa1ad 	orr	x13, x13, x15, lsl #40
 8b0:	aa0a818c 	orr	x12, x12, x10, lsl #32
 8b4:	aa0b01ab 	orr	x11, x13, x11
 8b8:	1200094a 	and	w10, w10, #0x7
 8bc:	aa098169 	orr	x9, x11, x9, lsl #32
 8c0:	1100054b 	add	w11, w10, #0x1
 8c4:	5200154a 	eor	w10, w10, #0x3f
 8c8:	9acb212b 	lsl	x11, x9, x11
 8cc:	9aca2529 	lsr	x9, x9, x10
 8d0:	aa090169 	orr	x9, x11, x9
 8d4:	ca0c0129 	eor	x9, x9, x12
 8d8:	f9000109 	str	x9, [x8]
 8dc:	d65f03c0 	ret

Disassembly of section .fini:

00000000000008e0 <_fini>:
 8e0:	d503201f 	nop
 8e4:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 8e8:	910003fd 	mov	x29, sp
 8ec:	a8c17bfd 	ldp	x29, x30, [sp], #16
 8f0:	d65f03c0 	ret
```

## Original Kernel JIT ASM
```asm
not captured
```

## llvmbpf JIT ASM
```asm
not captured
```
