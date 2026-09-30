# packed_header_bitfield_decode

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
 494:	f00000f0 	adrp	x16, 1f000 <__FRAME_END__+0x1e6b0>
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
 4e0:	f00000e0 	adrp	x0, 1f000 <__FRAME_END__+0x1e6b0>
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
 518:	f00000e1 	adrp	x1, 1f000 <__FRAME_END__+0x1e6b0>
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
 554:	f00000e2 	adrp	x2, 1f000 <__FRAME_END__+0x1e6b0>
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
 58c:	f00000e0 	adrp	x0, 1f000 <__FRAME_END__+0x1e6b0>
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

00000000000005e0 <packed_header_bitfield_decode_xdp>:
 5e0:	a9402408 	ldp	x8, x9, [x0]
 5e4:	aa0803ea 	mov	x10, x8
 5e8:	eb09015f 	cmp	x10, x9
 5ec:	54000069 	b.ls	5f8 <packed_header_bitfield_decode_xdp+0x18>  // b.plast
 5f0:	2a1f03e0 	mov	w0, wzr
 5f4:	d65f03c0 	ret
 5f8:	9100214b 	add	x11, x10, #0x8
 5fc:	9108414c 	add	x12, x10, #0x210
 600:	eb09017f 	cmp	x11, x9
 604:	fa499182 	ccmp	x12, x9, #0x2, ls	// ls = plast
 608:	54000069 	b.ls	614 <packed_header_bitfield_decode_xdp+0x34>  // b.plast
 60c:	2a1f03e0 	mov	w0, wzr
 610:	d65f03c0 	ret
 614:	29412d49 	ldp	w9, w11, [x10, #8]
 618:	7100813f 	cmp	w9, #0x20
 61c:	7a420960 	ccmp	w11, #0x2, #0x0, eq	// eq = none
 620:	54000060 	b.eq	62c <packed_header_bitfield_decode_xdp+0x4c>  // b.none
 624:	2a1f03e0 	mov	w0, wzr
 628:	d65f03c0 	ret
 62c:	f81a0ffd 	str	x29, [sp, #-96]!
 630:	a9016ffc 	stp	x28, x27, [sp, #16]
 634:	a90267fa 	stp	x26, x25, [sp, #32]
 638:	a9035ff8 	stp	x24, x23, [sp, #48]
 63c:	a90457f6 	stp	x22, x21, [sp, #64]
 640:	a9054ff4 	stp	x20, x19, [sp, #80]
 644:	d299212e 	mov	x14, #0xc909                	// #51465
 648:	aa1f03e9 	mov	x9, xzr
 64c:	91007d4a 	add	x10, x10, #0x1f
 650:	5280016b 	mov	w11, #0xb                   	// #11
 654:	528001ac 	mov	w12, #0xd                   	// #13
 658:	5280026d 	mov	w13, #0x13                  	// #19
 65c:	f2be778e 	movk	x14, #0xf3bc, lsl #16
 660:	f2dcccee 	movk	x14, #0xe667, lsl #32
 664:	f2ed412e 	movk	x14, #0x6a09, lsl #48
 668:	385f4150 	ldurb	w16, [x10, #-12]
 66c:	385fb140 	ldurb	w0, [x10, #-5]
 670:	d3689e03 	lsl	x3, x16, #24
 674:	385f8150 	ldurb	w16, [x10, #-8]
 678:	385fc145 	ldurb	w5, [x10, #-4]
 67c:	385fa152 	ldurb	w18, [x10, #-6]
 680:	385fe154 	ldurb	w20, [x10, #-2]
 684:	385f3159 	ldurb	w25, [x10, #-13]
 688:	385fd153 	ldurb	w19, [x10, #-3]
 68c:	39400156 	ldrb	w22, [x10]
 690:	d370bc06 	lsl	x6, x0, #16
 694:	d3689ca7 	lsl	x7, x5, #24
 698:	385ff157 	ldurb	w23, [x10, #-1]
 69c:	d3585e95 	lsl	x21, x20, #40
 6a0:	d3481ed6 	lsl	x22, x22, #56
 6a4:	aa0703e5 	mov	x5, x7
 6a8:	385f6151 	ldurb	w17, [x10, #-10]
 6ac:	2a0600e6 	orr	w6, w7, w6
 6b0:	b3701c07 	bfi	x7, x0, #16, #8
 6b4:	aa194063 	orr	x3, x3, x25, lsl #16
 6b8:	385f5159 	ldurb	w25, [x10, #-11]
 6bc:	aa1382b5 	orr	x21, x21, x19, lsl #32
 6c0:	aa17c2d6 	orr	x22, x22, x23, lsl #48
 6c4:	d3585e22 	lsl	x2, x17, #40
 6c8:	d378de51 	lsl	x17, x18, #8
 6cc:	b3601e65 	bfi	x5, x19, #32, #8
 6d0:	385f114f 	ldurb	w15, [x10, #-15]
 6d4:	385f2157 	ldurb	w23, [x10, #-14]
 6d8:	d356fc7c 	lsr	x28, x3, #22
 6dc:	d3481e04 	lsl	x4, x16, #56
 6e0:	385f9150 	ldurb	w16, [x10, #-7]
 6e4:	aa198042 	orr	x2, x2, x25, lsl #32
 6e8:	385f7159 	ldurb	w25, [x10, #-9]
 6ec:	aa1721f8 	orr	x24, x15, x23, lsl #8
 6f0:	d34116f7 	ubfx	x23, x23, #1, #5
 6f4:	9100414a 	add	x10, x10, #0x10
 6f8:	aa18007a 	orr	x26, x3, x24
 6fc:	d3462b18 	ubfx	x24, x24, #6, #5
 700:	aa1a0042 	orr	x2, x2, x26
 704:	d34b575a 	ubfx	x26, x26, #11, #11
 708:	aa1003e1 	mov	x1, x16
 70c:	d35eac43 	ubfx	x3, x2, #30, #14
 710:	b3781e41 	bfi	x1, x18, #8, #8
 714:	aa19c084 	orr	x4, x4, x25, lsl #48
 718:	924015f9 	and	x25, x15, #0x3f
 71c:	924009ef 	and	x15, x15, #0x7
 720:	aa020084 	orr	x4, x4, x2
 724:	8b180338 	add	x24, x25, x24
 728:	aa0100e7 	orr	x7, x7, x1
 72c:	d36cd49d 	ubfx	x29, x4, #44, #10
 730:	d376fc82 	lsr	x2, x4, #54
 734:	92400e04 	and	x4, x16, #0xf
 738:	d3442c21 	ubfx	x1, x1, #4, #8
 73c:	8b1a0318 	add	x24, x24, x26
 740:	aa0702a7 	orr	x7, x21, x7
 744:	d366b2b5 	ubfx	x21, x21, #38, #7
 748:	8b180058 	add	x24, x2, x24
 74c:	8b1d0079 	add	x25, x3, x29
 750:	aa0702db 	orr	x27, x22, x7
 754:	b3581e96 	bfi	x22, x20, #40, #8
 758:	d3589ce7 	ubfx	x7, x7, #24, #16
 75c:	d368ff74 	lsr	x20, x27, #40
 760:	aa1600b3 	orr	x19, x5, x22
 764:	b3701c13 	bfi	x19, x0, #16, #8
 768:	2a060220 	orr	w0, w17, w6
 76c:	8b1712e6 	add	x6, x23, x23, lsl #4
 770:	d34c5c00 	ubfx	x0, x0, #12, #12
 774:	b3781e53 	bfi	x19, x18, #8, #8
 778:	8b150000 	add	x0, x0, x21
 77c:	8b100272 	add	x18, x19, x16
 780:	2a100230 	orr	w16, w17, w16
 784:	8b170131 	add	x17, x9, x23
 788:	91000529 	add	x9, x9, #0x1
 78c:	8b52a092 	add	x18, x4, x18, lsr #40
 790:	8b030864 	add	x4, x3, x3, lsl #2
 794:	53047e10 	lsr	w16, w16, #4
 798:	f100813f 	cmp	x9, #0x20
 79c:	8b456252 	add	x18, x18, x5, lsr #24
 7a0:	8b140e85 	add	x5, x20, x20, lsl #3
 7a4:	8b000252 	add	x18, x18, x0
 7a8:	8b1a0740 	add	x0, x26, x26, lsl #1
 7ac:	ca040000 	eor	x0, x0, x4
 7b0:	d37df024 	lsl	x4, x1, #3
 7b4:	8b300250 	add	x16, x18, w16, uxtb
 7b8:	8b3c0312 	add	x18, x24, w28, uxtb
 7bc:	cb010081 	sub	x1, x4, x1
 7c0:	9bac7ce4 	umull	x4, w7, w12
 7c4:	9bad7ea7 	umull	x7, w21, w13
 7c8:	ca010000 	eor	x0, x0, x1
 7cc:	9bab7c41 	umull	x1, w2, w11
 7d0:	8b100230 	add	x16, x17, x16
 7d4:	8b190252 	add	x18, x18, x25
 7d8:	ca0400a4 	eor	x4, x5, x4
 7dc:	ca0100c1 	eor	x1, x6, x1
 7e0:	ca040021 	eor	x1, x1, x4
 7e4:	ca070031 	eor	x17, x1, x7
 7e8:	910005e1 	add	x1, x15, #0x1
 7ec:	520015ef 	eor	w15, w15, #0x3f
 7f0:	9ac12201 	lsl	x1, x16, x1
 7f4:	9acf260f 	lsr	x15, x16, x15
 7f8:	4a020290 	eor	w16, w20, w2
 7fc:	aa0f002f 	orr	x15, x1, x15
 800:	12000e10 	and	w16, w16, #0xf
 804:	ca1201ef 	eor	x15, x15, x18
 808:	8b0e01ee 	add	x14, x15, x14
 80c:	8b00022f 	add	x15, x17, x0
 810:	ca0f01ce 	eor	x14, x14, x15
 814:	8b0302ef 	add	x15, x23, x3
 818:	8b0f028f 	add	x15, x20, x15
 81c:	8b0e01ee 	add	x14, x15, x14
 820:	1100060f 	add	w15, w16, #0x1
 824:	52001610 	eor	w16, w16, #0x3f
 828:	9acf21cf 	lsl	x15, x14, x15
 82c:	9ad025ce 	lsr	x14, x14, x16
 830:	aa0e01ee 	orr	x14, x15, x14
 834:	54fff1a1 	b.ne	668 <packed_header_bitfield_decode_xdp+0x88>  // b.any
 838:	d348fdc9 	lsr	x9, x14, #8
 83c:	a9454ff4 	ldp	x20, x19, [sp, #80]
 840:	52800040 	mov	w0, #0x2                   	// #2
 844:	3900010e 	strb	w14, [x8]
 848:	39000509 	strb	w9, [x8, #1]
 84c:	d350fde9 	lsr	x9, x15, #16
 850:	39000909 	strb	w9, [x8, #2]
 854:	d358fde9 	lsr	x9, x15, #24
 858:	a94457f6 	ldp	x22, x21, [sp, #64]
 85c:	39000d09 	strb	w9, [x8, #3]
 860:	d360fde9 	lsr	x9, x15, #32
 864:	39001109 	strb	w9, [x8, #4]
 868:	d368fde9 	lsr	x9, x15, #40
 86c:	a9435ff8 	ldp	x24, x23, [sp, #48]
 870:	39001509 	strb	w9, [x8, #5]
 874:	d370fde9 	lsr	x9, x15, #48
 878:	39001909 	strb	w9, [x8, #6]
 87c:	a94267fa 	ldp	x26, x25, [sp, #32]
 880:	d378fde9 	lsr	x9, x15, #56
 884:	39001d09 	strb	w9, [x8, #7]
 888:	a9416ffc 	ldp	x28, x27, [sp, #16]
 88c:	f84607fd 	ldr	x29, [sp], #96
 890:	d65f03c0 	ret

Disassembly of section .fini:

0000000000000894 <_fini>:
 894:	d503201f 	nop
 898:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 89c:	910003fd 	mov	x29, sp
 8a0:	a8c17bfd 	ldp	x29, x30, [sp], #16
 8a4:	d65f03c0 	ret
```

## Original Kernel JIT ASM
```asm
not captured
```

## llvmbpf JIT ASM
```asm
not captured
```
