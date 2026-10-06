# cilium_ct_nat_tuple_rewrite

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
 494:	f00000f0 	adrp	x16, 1f000 <__FRAME_END__+0x1e7f8>
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
 4e0:	f00000e0 	adrp	x0, 1f000 <__FRAME_END__+0x1e7f8>
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
 518:	f00000e1 	adrp	x1, 1f000 <__FRAME_END__+0x1e7f8>
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
 554:	f00000e2 	adrp	x2, 1f000 <__FRAME_END__+0x1e7f8>
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
 58c:	f00000e0 	adrp	x0, 1f000 <__FRAME_END__+0x1e7f8>
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

00000000000005e0 <cilium_ct_nat_tuple_rewrite_xdp>:
 5e0:	a9402408 	ldp	x8, x9, [x0]
 5e4:	aa0803ea 	mov	x10, x8
 5e8:	eb09015f 	cmp	x10, x9
 5ec:	54000069 	b.ls	5f8 <cilium_ct_nat_tuple_rewrite_xdp+0x18>  // b.plast
 5f0:	2a1f03e0 	mov	w0, wzr
 5f4:	d65f03c0 	ret
 5f8:	9100214b 	add	x11, x10, #0x8
 5fc:	9110414c 	add	x12, x10, #0x410
 600:	2a1f03e0 	mov	w0, wzr
 604:	eb09017f 	cmp	x11, x9
 608:	fa499182 	ccmp	x12, x9, #0x2, ls	// ls = plast
 60c:	540009e8 	b.hi	748 <cilium_ct_nat_tuple_rewrite_xdp+0x168>  // b.pmore
 610:	b9400949 	ldr	w9, [x10, #8]
 614:	7100813f 	cmp	w9, #0x20
 618:	54000981 	b.ne	748 <cilium_ct_nat_tuple_rewrite_xdp+0x168>  // b.any
 61c:	b9400d49 	ldr	w9, [x10, #12]
 620:	7100813f 	cmp	w9, #0x20
 624:	54000921 	b.ne	748 <cilium_ct_nat_tuple_rewrite_xdp+0x168>  // b.any
 628:	d298dc6b 	mov	x11, #0xc6e3                	// #50915
 62c:	aa1f03e9 	mov	x9, xzr
 630:	91005d4a 	add	x10, x10, #0x17
 634:	f2b3910b 	movk	x11, #0x9c88, lsl #16
 638:	f2cd5e0b 	movk	x11, #0x6af0, lsl #32
 63c:	f2f1d78b 	movk	x11, #0x8ebc, lsl #48
 640:	14000035 	b	714 <cilium_ct_nat_tuple_rewrite_xdp+0x134>
 644:	39401d52 	ldrb	w18, [x10, #7]
 648:	7841114e 	ldurh	w14, [x10, #17]
 64c:	91002551 	add	x17, x10, #0x9
 650:	d1001d44 	sub	x4, x10, #0x7
 654:	91003550 	add	x16, x10, #0xd
 658:	d1000d43 	sub	x3, x10, #0x3
 65c:	39401940 	ldrb	w0, [x10, #6]
 660:	8b2c416b 	add	x11, x11, w12, uxtw
 664:	78403141 	ldurh	w1, [x10, #3]
 668:	7200025f 	tst	w18, #0x1
 66c:	78401142 	ldurh	w2, [x10, #1]
 670:	7841314f 	ldurh	w15, [x10, #19]
 674:	13000245 	sbfx	w5, w18, #0, #1
 678:	2a0d61ed 	orr	w13, w15, w13, lsl #24
 67c:	53030a4f 	lsl	w15, w18, #29
 680:	9a910091 	csel	x17, x4, x17, eq	// eq = none
 684:	721f025f 	tst	w18, #0x2
 688:	53020644 	lsl	w4, w18, #30
 68c:	0a0e00a5 	and	w5, w5, w14
 690:	9a900070 	csel	x16, x3, x16, eq	// eq = none
 694:	b9400231 	ldr	w17, [x17]
 698:	0a847dc4 	and	w4, w14, w4, asr #31
 69c:	4a050042 	eor	w2, w2, w5
 6a0:	7200001f 	tst	w0, #0x1
 6a4:	12003dce 	and	w14, w14, #0xffff
 6a8:	b9400210 	ldr	w16, [x16]
 6ac:	4a040021 	eor	w1, w1, w4
 6b0:	4a0e218e 	eor	w14, w12, w14, lsl #8
 6b4:	1a820020 	csel	w0, w1, w2, eq	// eq = none
 6b8:	1a810041 	csel	w1, w2, w1, eq	// eq = none
 6bc:	0a8f7dce 	and	w14, w14, w15, asr #31
 6c0:	1a910202 	csel	w2, w16, w17, eq	// eq = none
 6c4:	1a900230 	csel	w16, w17, w16, eq	// eq = none
 6c8:	12003c11 	and	w17, w0, #0xffff
 6cc:	4a1101ad 	eor	w13, w13, w17
 6d0:	aa10804c 	orr	x12, x2, x16, lsl #32
 6d4:	4a0141ad 	eor	w13, w13, w1, lsl #16
 6d8:	4ac255ad 	eor	w13, w13, w2, ror #21
 6dc:	4a1001ad 	eor	w13, w13, w16
 6e0:	0b0e01ad 	add	w13, w13, w14
 6e4:	8b0d816b 	add	x11, x11, x13, lsl #32
 6e8:	1200092d 	and	w13, w9, #0x7
 6ec:	110005ae 	add	w14, w13, #0x1
 6f0:	520015ad 	eor	w13, w13, #0x3f
 6f4:	9ace218e 	lsl	x14, x12, x14
 6f8:	9acd258c 	lsr	x12, x12, x13
 6fc:	aa0c01cc 	orr	x12, x14, x12
 700:	ca0c016b 	eor	x11, x11, x12
 704:	91000529 	add	x9, x9, #0x1
 708:	9100814a 	add	x10, x10, #0x20
 70c:	f100813f 	cmp	x9, #0x20
 710:	54000180 	b.eq	740 <cilium_ct_nat_tuple_rewrite_xdp+0x160>  // b.none
 714:	3940154d 	ldrb	w13, [x10, #5]
 718:	b841514c 	ldur	w12, [x10, #21]
 71c:	710019bf 	cmp	w13, #0x6
 720:	7a5119a4 	ccmp	w13, #0x11, #0x4, ne	// ne = any
 724:	54fff900 	b.eq	644 <cilium_ct_nat_tuple_rewrite_xdp+0x64>  // b.none
 728:	aa0de18c 	orr	x12, x12, x13, lsl #56
 72c:	ca0b018b 	eor	x11, x12, x11
 730:	91000529 	add	x9, x9, #0x1
 734:	9100814a 	add	x10, x10, #0x20
 738:	f100813f 	cmp	x9, #0x20
 73c:	54fffec1 	b.ne	714 <cilium_ct_nat_tuple_rewrite_xdp+0x134>  // b.any
 740:	52800040 	mov	w0, #0x2                   	// #2
 744:	f900010b 	str	x11, [x8]
 748:	d65f03c0 	ret

Disassembly of section .fini:

000000000000074c <_fini>:
 74c:	d503201f 	nop
 750:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 754:	910003fd 	mov	x29, sp
 758:	a8c17bfd 	ldp	x29, x30, [sp], #16
 75c:	d65f03c0 	ret
```

## Original Kernel JIT ASM
```asm
not captured
```

## llvmbpf JIT ASM
```asm
not captured
```
