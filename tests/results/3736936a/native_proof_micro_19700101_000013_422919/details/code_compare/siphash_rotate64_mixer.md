# siphash_rotate64_mixer

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
 484:	f00000f0 	adrp	x16, 1f000 <__FRAME_END__+0x1e5a8>
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
 4c0:	f00000e0 	adrp	x0, 1f000 <__FRAME_END__+0x1e5a8>
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
 4f8:	f00000e1 	adrp	x1, 1f000 <__FRAME_END__+0x1e5a8>
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
 534:	f00000e2 	adrp	x2, 1f000 <__FRAME_END__+0x1e5a8>
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
 56c:	f00000e0 	adrp	x0, 1f000 <__FRAME_END__+0x1e5a8>
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

00000000000005b0 <siphash_rotate64_mixer_xdp>:
 5b0:	a9402408 	ldp	x8, x9, [x0]
 5b4:	aa0803ef 	mov	x15, x8
 5b8:	eb0901ff 	cmp	x15, x9
 5bc:	540000c8 	b.hi	5d4 <siphash_rotate64_mixer_xdp+0x24>  // b.pmore
 5c0:	910021ea 	add	x10, x15, #0x8
 5c4:	910121eb 	add	x11, x15, #0x48
 5c8:	eb09015f 	cmp	x10, x9
 5cc:	fa499162 	ccmp	x11, x9, #0x2, ls	// ls = plast
 5d0:	54000069 	b.ls	5dc <siphash_rotate64_mixer_xdp+0x2c>  // b.plast
 5d4:	2a1f03e0 	mov	w0, wzr
 5d8:	d65f03c0 	ret
 5dc:	a941b5ee 	ldp	x14, x13, [x15, #24]
 5e0:	d28cae71 	mov	x17, #0x6573                	// #25971
 5e4:	d28e4c32 	mov	x18, #0x7261                	// #29281
 5e8:	d29d5a01 	mov	x1, #0xead0                	// #60112
 5ec:	d29bf8c0 	mov	x0, #0xdfc6                	// #57286
 5f0:	a942adec 	ldp	x12, x11, [x15, #40]
 5f4:	f2af2e91 	movk	x17, #0x7974, lsl #16
 5f8:	f2adccb2 	movk	x18, #0x6e65, lsl #16
 5fc:	f2b833e1 	movk	x1, #0xc19f, lsl #16
 600:	a943a5ea 	ldp	x10, x9, [x15, #56]
 604:	f2bafbc0 	movk	x0, #0xd7de, lsl #16
 608:	f2cc8c51 	movk	x17, #0x6462, lsl #32
 60c:	f2ccecb2 	movk	x18, #0x6765, lsl #32
 610:	a940c1ef 	ldp	x15, x16, [x15, #8]
 614:	f2cb2de1 	movk	x1, #0x596f, lsl #32
 618:	f2da9c40 	movk	x0, #0xd4e2, lsl #32
 61c:	f2ee8cb1 	movk	x17, #0x7465, lsl #48
 620:	f2ed8f32 	movk	x18, #0x6c79, lsl #48
 624:	f2f4c181 	movk	x1, #0xa60c, lsl #48
 628:	f2fbdae0 	movk	x0, #0xded7, lsl #48
 62c:	ca1101f1 	eor	x17, x15, x17
 630:	8b120232 	add	x18, x17, x18
 634:	cad1c252 	eor	x18, x18, x17, ror #48
 638:	8b010231 	add	x17, x17, x1
 63c:	d28e64a1 	mov	x1, #0x7325                	// #29477
 640:	f2be1bc1 	movk	x1, #0xf0de, lsl #16
 644:	8b000240 	add	x0, x18, x0
 648:	f2d4ce81 	movk	x1, #0xa674, lsl #32
 64c:	cad2ac12 	eor	x18, x0, x18, ror #43
 650:	f2fc8281 	movk	x1, #0xe414, lsl #48
 654:	ca010221 	eor	x1, x17, x1
 658:	93d18231 	ror	x17, x17, #32
 65c:	8b010000 	add	x0, x0, x1
 660:	8b110251 	add	x17, x18, x17
 664:	cac1cc01 	eor	x1, x0, x1, ror #51
 668:	93c08000 	ror	x0, x0, #32
 66c:	cad2c232 	eor	x18, x17, x18, ror #48
 670:	8b000240 	add	x0, x18, x0
 674:	8b010231 	add	x17, x17, x1
 678:	cad2ac12 	eor	x18, x0, x18, ror #43
 67c:	cac1be21 	eor	x1, x17, x1, ror #47
 680:	93d18231 	ror	x17, x17, #32
 684:	ca0f000f 	eor	x15, x0, x15
 688:	ca100252 	eor	x18, x18, x16
 68c:	8b0101ef 	add	x15, x15, x1
 690:	8b110251 	add	x17, x18, x17
 694:	cac1cde0 	eor	x0, x15, x1, ror #51
 698:	93cf81ef 	ror	x15, x15, #32
 69c:	cad2c232 	eor	x18, x17, x18, ror #48
 6a0:	8b000231 	add	x17, x17, x0
 6a4:	8b0f024f 	add	x15, x18, x15
 6a8:	cac0be20 	eor	x0, x17, x0, ror #47
 6ac:	93d18231 	ror	x17, x17, #32
 6b0:	cad2adf2 	eor	x18, x15, x18, ror #43
 6b4:	8b0001ef 	add	x15, x15, x0
 6b8:	8b110251 	add	x17, x18, x17
 6bc:	cac0cde0 	eor	x0, x15, x0, ror #51
 6c0:	93cf81ef 	ror	x15, x15, #32
 6c4:	cad2c232 	eor	x18, x17, x18, ror #48
 6c8:	8b000231 	add	x17, x17, x0
 6cc:	8b0f024f 	add	x15, x18, x15
 6d0:	cac0be20 	eor	x0, x17, x0, ror #47
 6d4:	93d18231 	ror	x17, x17, #32
 6d8:	cad2adf2 	eor	x18, x15, x18, ror #43
 6dc:	ca1001ef 	eor	x15, x15, x16
 6e0:	ca0e0250 	eor	x16, x18, x14
 6e4:	8b0001ef 	add	x15, x15, x0
 6e8:	8b110211 	add	x17, x16, x17
 6ec:	cac0cdf2 	eor	x18, x15, x0, ror #51
 6f0:	93cf81ef 	ror	x15, x15, #32
 6f4:	52800040 	mov	w0, #0x2                   	// #2
 6f8:	cad0c230 	eor	x16, x17, x16, ror #48
 6fc:	8b120231 	add	x17, x17, x18
 700:	8b0f020f 	add	x15, x16, x15
 704:	cad2be32 	eor	x18, x17, x18, ror #47
 708:	93d18231 	ror	x17, x17, #32
 70c:	cad0adf0 	eor	x16, x15, x16, ror #43
 710:	8b1201ef 	add	x15, x15, x18
 714:	8b110211 	add	x17, x16, x17
 718:	cad2cdf2 	eor	x18, x15, x18, ror #51
 71c:	93cf81ef 	ror	x15, x15, #32
 720:	cad0c230 	eor	x16, x17, x16, ror #48
 724:	8b120231 	add	x17, x17, x18
 728:	8b0f020f 	add	x15, x16, x15
 72c:	cad2be32 	eor	x18, x17, x18, ror #47
 730:	93d18231 	ror	x17, x17, #32
 734:	cad0adf0 	eor	x16, x15, x16, ror #43
 738:	ca0e01ee 	eor	x14, x15, x14
 73c:	ca0d020f 	eor	x15, x16, x13
 740:	8b1201ce 	add	x14, x14, x18
 744:	8b1101f1 	add	x17, x15, x17
 748:	cad2cdd0 	eor	x16, x14, x18, ror #51
 74c:	93ce81ce 	ror	x14, x14, #32
 750:	cacfc22f 	eor	x15, x17, x15, ror #48
 754:	8b100231 	add	x17, x17, x16
 758:	8b0e01ee 	add	x14, x15, x14
 75c:	cad0be30 	eor	x16, x17, x16, ror #47
 760:	93d18231 	ror	x17, x17, #32
 764:	cacfadcf 	eor	x15, x14, x15, ror #43
 768:	8b1001ce 	add	x14, x14, x16
 76c:	8b1101f1 	add	x17, x15, x17
 770:	cad0cdd0 	eor	x16, x14, x16, ror #51
 774:	93ce81ce 	ror	x14, x14, #32
 778:	cacfc22f 	eor	x15, x17, x15, ror #48
 77c:	8b100231 	add	x17, x17, x16
 780:	8b0e01ee 	add	x14, x15, x14
 784:	cad0be30 	eor	x16, x17, x16, ror #47
 788:	93d18231 	ror	x17, x17, #32
 78c:	cacfadcf 	eor	x15, x14, x15, ror #43
 790:	ca0d01cd 	eor	x13, x14, x13
 794:	ca0c01ee 	eor	x14, x15, x12
 798:	8b1001ad 	add	x13, x13, x16
 79c:	cad0cdaf 	eor	x15, x13, x16, ror #51
 7a0:	8b1101d0 	add	x16, x14, x17
 7a4:	93cd81ad 	ror	x13, x13, #32
 7a8:	cacec20e 	eor	x14, x16, x14, ror #48
 7ac:	8b0f0210 	add	x16, x16, x15
 7b0:	8b0d01cd 	add	x13, x14, x13
 7b4:	cacfbe0f 	eor	x15, x16, x15, ror #47
 7b8:	93d08210 	ror	x16, x16, #32
 7bc:	caceadae 	eor	x14, x13, x14, ror #43
 7c0:	8b0f01ad 	add	x13, x13, x15
 7c4:	8b1001d0 	add	x16, x14, x16
 7c8:	cacfcdaf 	eor	x15, x13, x15, ror #51
 7cc:	93cd81ad 	ror	x13, x13, #32
 7d0:	cacec20e 	eor	x14, x16, x14, ror #48
 7d4:	8b0f0210 	add	x16, x16, x15
 7d8:	8b0d01cd 	add	x13, x14, x13
 7dc:	cacfbe0f 	eor	x15, x16, x15, ror #47
 7e0:	93d08210 	ror	x16, x16, #32
 7e4:	caceadae 	eor	x14, x13, x14, ror #43
 7e8:	ca0c01ac 	eor	x12, x13, x12
 7ec:	ca0b01cd 	eor	x13, x14, x11
 7f0:	8b0f018c 	add	x12, x12, x15
 7f4:	cacfcd8e 	eor	x14, x12, x15, ror #51
 7f8:	8b1001af 	add	x15, x13, x16
 7fc:	93cc818c 	ror	x12, x12, #32
 800:	cacdc1ed 	eor	x13, x15, x13, ror #48
 804:	8b0e01ef 	add	x15, x15, x14
 808:	8b0c01ac 	add	x12, x13, x12
 80c:	cacebdee 	eor	x14, x15, x14, ror #47
 810:	93cf81ef 	ror	x15, x15, #32
 814:	cacdad8d 	eor	x13, x12, x13, ror #43
 818:	8b0e018c 	add	x12, x12, x14
 81c:	8b0f01af 	add	x15, x13, x15
 820:	cacecd8e 	eor	x14, x12, x14, ror #51
 824:	93cc818c 	ror	x12, x12, #32
 828:	cacdc1ed 	eor	x13, x15, x13, ror #48
 82c:	8b0e01ef 	add	x15, x15, x14
 830:	8b0c01ac 	add	x12, x13, x12
 834:	cacebdee 	eor	x14, x15, x14, ror #47
 838:	93cf81ef 	ror	x15, x15, #32
 83c:	cacdad8d 	eor	x13, x12, x13, ror #43
 840:	ca0b018b 	eor	x11, x12, x11
 844:	ca0a01ac 	eor	x12, x13, x10
 848:	8b0e016b 	add	x11, x11, x14
 84c:	cacecd6d 	eor	x13, x11, x14, ror #51
 850:	8b0f018e 	add	x14, x12, x15
 854:	93cb816b 	ror	x11, x11, #32
 858:	caccc1cc 	eor	x12, x14, x12, ror #48
 85c:	8b0d01ce 	add	x14, x14, x13
 860:	8b0b018b 	add	x11, x12, x11
 864:	cacdbdcd 	eor	x13, x14, x13, ror #47
 868:	93ce81ce 	ror	x14, x14, #32
 86c:	caccad6c 	eor	x12, x11, x12, ror #43
 870:	8b0d016b 	add	x11, x11, x13
 874:	8b0e018e 	add	x14, x12, x14
 878:	cacdcd6d 	eor	x13, x11, x13, ror #51
 87c:	93cb816b 	ror	x11, x11, #32
 880:	caccc1cc 	eor	x12, x14, x12, ror #48
 884:	8b0d01ce 	add	x14, x14, x13
 888:	8b0b018b 	add	x11, x12, x11
 88c:	cacdbdcd 	eor	x13, x14, x13, ror #47
 890:	93ce81ce 	ror	x14, x14, #32
 894:	caccad6c 	eor	x12, x11, x12, ror #43
 898:	ca0a016a 	eor	x10, x11, x10
 89c:	ca09018b 	eor	x11, x12, x9
 8a0:	8b0d014a 	add	x10, x10, x13
 8a4:	cacdcd4c 	eor	x12, x10, x13, ror #51
 8a8:	8b0e016d 	add	x13, x11, x14
 8ac:	93ca814a 	ror	x10, x10, #32
 8b0:	cacbc1ab 	eor	x11, x13, x11, ror #48
 8b4:	8b0c01ad 	add	x13, x13, x12
 8b8:	8b0a016a 	add	x10, x11, x10
 8bc:	caccbdac 	eor	x12, x13, x12, ror #47
 8c0:	93cd81ad 	ror	x13, x13, #32
 8c4:	cacbad4b 	eor	x11, x10, x11, ror #43
 8c8:	8b0c014a 	add	x10, x10, x12
 8cc:	cacccd4c 	eor	x12, x10, x12, ror #51
 8d0:	8b0d016d 	add	x13, x11, x13
 8d4:	93ca814a 	ror	x10, x10, #32
 8d8:	cacbc1ab 	eor	x11, x13, x11, ror #48
 8dc:	8b0c01ad 	add	x13, x13, x12
 8e0:	8b0a016a 	add	x10, x11, x10
 8e4:	caccbdac 	eor	x12, x13, x12, ror #47
 8e8:	93cd81ad 	ror	x13, x13, #32
 8ec:	cacbad4b 	eor	x11, x10, x11, ror #43
 8f0:	ca090149 	eor	x9, x10, x9
 8f4:	d2401daa 	eor	x10, x13, #0xff
 8f8:	8b0c0129 	add	x9, x9, x12
 8fc:	8b0b014a 	add	x10, x10, x11
 900:	cacccd2c 	eor	x12, x9, x12, ror #51
 904:	93c98129 	ror	x9, x9, #32
 908:	cacbc14b 	eor	x11, x10, x11, ror #48
 90c:	8b0b0129 	add	x9, x9, x11
 910:	8b0a018a 	add	x10, x12, x10
 914:	cacbad2b 	eor	x11, x9, x11, ror #43
 918:	caccbd4c 	eor	x12, x10, x12, ror #47
 91c:	93ca814a 	ror	x10, x10, #32
 920:	8b090189 	add	x9, x12, x9
 924:	8b0b014a 	add	x10, x10, x11
 928:	cacccd2c 	eor	x12, x9, x12, ror #51
 92c:	93c98129 	ror	x9, x9, #32
 930:	cacbc14b 	eor	x11, x10, x11, ror #48
 934:	8b0b0129 	add	x9, x9, x11
 938:	8b0a018a 	add	x10, x12, x10
 93c:	cacbad2b 	eor	x11, x9, x11, ror #43
 940:	caccbd4c 	eor	x12, x10, x12, ror #47
 944:	93ca814a 	ror	x10, x10, #32
 948:	8b090189 	add	x9, x12, x9
 94c:	8b0b014a 	add	x10, x10, x11
 950:	cacccd2c 	eor	x12, x9, x12, ror #51
 954:	93c98129 	ror	x9, x9, #32
 958:	cacbc14b 	eor	x11, x10, x11, ror #48
 95c:	8b0b0129 	add	x9, x9, x11
 960:	8b0a018a 	add	x10, x12, x10
 964:	cacbad2b 	eor	x11, x9, x11, ror #43
 968:	caccbd4c 	eor	x12, x10, x12, ror #47
 96c:	93ca814a 	ror	x10, x10, #32
 970:	8b0b014a 	add	x10, x10, x11
 974:	8b090189 	add	x9, x12, x9
 978:	cacbc14b 	eor	x11, x10, x11, ror #48
 97c:	cacccd29 	eor	x9, x9, x12, ror #51
 980:	93cbad6b 	ror	x11, x11, #43
 984:	8b0a012a 	add	x10, x9, x10
 988:	cac9bd69 	eor	x9, x11, x9, ror #47
 98c:	caca8129 	eor	x9, x9, x10, ror #32
 990:	ca0a0129 	eor	x9, x9, x10
 994:	f9000109 	str	x9, [x8]
 998:	d65f03c0 	ret

Disassembly of section .fini:

000000000000099c <_fini>:
 99c:	d503201f 	nop
 9a0:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 9a4:	910003fd 	mov	x29, sp
 9a8:	a8c17bfd 	ldp	x29, x30, [sp], #16
 9ac:	d65f03c0 	ret
```

## Original Kernel JIT ASM
```asm
not captured
```

## llvmbpf JIT ASM
```asm
not captured
```
