# bpf_local_call_fanout_dispatch

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
 494:	f00000f0 	adrp	x16, 1f000 <__FRAME_END__+0x1e650>
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
 4e0:	f00000e0 	adrp	x0, 1f000 <__FRAME_END__+0x1e650>
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
 518:	f00000e1 	adrp	x1, 1f000 <__FRAME_END__+0x1e650>
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
 554:	f00000e2 	adrp	x2, 1f000 <__FRAME_END__+0x1e650>
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
 58c:	f00000e0 	adrp	x0, 1f000 <__FRAME_END__+0x1e650>
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

00000000000005e0 <bpf_local_call_fanout_dispatch_xdp>:
 5e0:	f81b0ffe 	str	x30, [sp, #-80]!
 5e4:	a90167fa 	stp	x26, x25, [sp, #16]
 5e8:	a9025ff8 	stp	x24, x23, [sp, #32]
 5ec:	a90357f6 	stp	x22, x21, [sp, #48]
 5f0:	a9044ff4 	stp	x20, x19, [sp, #64]
 5f4:	a9402415 	ldp	x21, x9, [x0]
 5f8:	aa1503e8 	mov	x8, x21
 5fc:	eb09011f 	cmp	x8, x9
 600:	54000148 	b.hi	628 <bpf_local_call_fanout_dispatch_xdp+0x48>  // b.pmore
 604:	91002113 	add	x19, x8, #0x8
 608:	9106410a 	add	x10, x8, #0x190
 60c:	eb09027f 	cmp	x19, x9
 610:	fa499142 	ccmp	x10, x9, #0x2, ls	// ls = plast
 614:	540000a8 	b.hi	628 <bpf_local_call_fanout_dispatch_xdp+0x48>  // b.pmore
 618:	29412909 	ldp	w9, w10, [x8, #8]
 61c:	7100413f 	cmp	w9, #0x10
 620:	7a580940 	ccmp	w10, #0x18, #0x0, eq	// eq = none
 624:	54000100 	b.eq	644 <bpf_local_call_fanout_dispatch_xdp+0x64>  // b.none
 628:	2a1f03e0 	mov	w0, wzr
 62c:	a9444ff4 	ldp	x20, x19, [sp, #64]
 630:	a94357f6 	ldp	x22, x21, [sp, #48]
 634:	a9425ff8 	ldp	x24, x23, [sp, #32]
 638:	a94167fa 	ldp	x26, x25, [sp, #16]
 63c:	f84507fe 	ldr	x30, [sp], #80
 640:	d65f03c0 	ret
 644:	d2811a60 	mov	x0, #0x8d3                 	// #2259
 648:	aa1f03f6 	mov	x22, xzr
 64c:	2a1f03f7 	mov	w23, wzr
 650:	aa1f03f8 	mov	x24, xzr
 654:	91004119 	add	x25, x8, #0x10
 658:	f2b0b460 	movk	x0, #0x85a3, lsl #16
 65c:	f2cd5100 	movk	x0, #0x6a88, lsl #32
 660:	f2e487e0 	movk	x0, #0x243f, lsl #48
 664:	1400000b 	b	690 <bpf_local_call_fanout_dispatch_xdp+0xb0>
 668:	9400003e 	bl	760 <local_call_pressure>
 66c:	927d0b08 	and	x8, x24, #0x38
 670:	91002318 	add	x24, x24, #0x8
 674:	110042f7 	add	w23, w23, #0x10
 678:	910062d6 	add	x22, x22, #0x18
 67c:	9ac82348 	lsl	x8, x26, x8
 680:	f102031f 	cmp	x24, #0x80
 684:	8b344108 	add	x8, x8, w20, uxtw
 688:	ca080000 	eor	x0, x0, x8
 68c:	540002e0 	b.eq	6e8 <bpf_local_call_fanout_dispatch_xdp+0x108>  // b.none
 690:	8b160328 	add	x8, x25, x22
 694:	aa1303e1 	mov	x1, x19
 698:	910022c2 	add	x2, x22, #0x8
 69c:	39400109 	ldrb	w9, [x8]
 6a0:	b9400508 	ldr	w8, [x8, #4]
 6a4:	9240053a 	and	x26, x9, #0x3
 6a8:	4a170114 	eor	w20, w8, w23
 6ac:	2a1403e3 	mov	w3, w20
 6b0:	71000b5f 	cmp	w26, #0x2
 6b4:	540000c0 	b.eq	6cc <bpf_local_call_fanout_dispatch_xdp+0xec>  // b.none
 6b8:	7100075f 	cmp	w26, #0x1
 6bc:	54fffd60 	b.eq	668 <bpf_local_call_fanout_dispatch_xdp+0x88>  // b.none
 6c0:	3500011a 	cbnz	w26, 6e0 <bpf_local_call_fanout_dispatch_xdp+0x100>
 6c4:	94000013 	bl	710 <local_call_linear>
 6c8:	17ffffe9 	b	66c <bpf_local_call_fanout_dispatch_xdp+0x8c>
 6cc:	94000039 	bl	7b0 <local_call_crossload>
 6d0:	17ffffe7 	b	66c <bpf_local_call_fanout_dispatch_xdp+0x8c>
 6d4:	d503201f 	nop
 6d8:	d503201f 	nop
 6dc:	d503201f 	nop
 6e0:	94000054 	bl	830 <local_call_bytes>
 6e4:	17ffffe2 	b	66c <bpf_local_call_fanout_dispatch_xdp+0x8c>
 6e8:	f90002a0 	str	x0, [x21]
 6ec:	52800040 	mov	w0, #0x2                   	// #2
 6f0:	a9444ff4 	ldp	x20, x19, [sp, #64]
 6f4:	a94357f6 	ldp	x22, x21, [sp, #48]
 6f8:	a9425ff8 	ldp	x24, x23, [sp, #32]
 6fc:	a94167fa 	ldp	x26, x25, [sp, #16]
 700:	f84507fe 	ldr	x30, [sp], #80
 704:	d65f03c0 	ret
 708:	d503201f 	nop
 70c:	d503201f 	nop

0000000000000710 <local_call_linear>:
 710:	8b224028 	add	x8, x1, w2, uxtw
 714:	2a0303eb 	mov	w11, w3
 718:	8b00016c 	add	x12, x11, x0
 71c:	a940a508 	ldp	x8, x9, [x8, #8]
 720:	8b08050a 	add	x10, x8, x8, lsl #1
 724:	8b090189 	add	x9, x12, x9
 728:	8b0a0129 	add	x9, x9, x10
 72c:	8b0b2d2a 	add	x10, x9, x11, lsl #11
 730:	1200086b 	and	w11, w3, #0x7
 734:	1100056c 	add	w12, w11, #0x1
 738:	5200156b 	eor	w11, w11, #0x3f
 73c:	9acc214c 	lsl	x12, x10, x12
 740:	9acb254a 	lsr	x10, x10, x11
 744:	aa0a018a 	orr	x10, x12, x10
 748:	ca090149 	eor	x9, x10, x9
 74c:	8b480d20 	add	x0, x9, x8, lsr #3
 750:	d65f03c0 	ret
 754:	d503201f 	nop
 758:	d503201f 	nop
 75c:	d503201f 	nop

0000000000000760 <local_call_pressure>:
 760:	8b224028 	add	x8, x1, w2, uxtw
 764:	2a0303eb 	mov	w11, w3
 768:	a940a508 	ldp	x8, x9, [x8, #8]
 76c:	ca00010a 	eor	x10, x8, x0
 770:	8b0b452b 	add	x11, x9, x11, lsl #17
 774:	d342fd29 	lsr	x9, x9, #2
 778:	ca0a0d29 	eor	x9, x9, x10, lsl #3
 77c:	ca080168 	eor	x8, x11, x8
 780:	8b0a012c 	add	x12, x9, x10
 784:	93c8ed08 	ror	x8, x8, #59
 788:	93ccd58c 	ror	x12, x12, #53
 78c:	8b080188 	add	x8, x12, x8
 790:	ca4b1d08 	eor	x8, x8, x11, lsr #7
 794:	8b090108 	add	x8, x8, x9
 798:	ca0b0149 	eor	x9, x10, x11
 79c:	ca080120 	eor	x0, x9, x8
 7a0:	d65f03c0 	ret
 7a4:	d503201f 	nop
 7a8:	d503201f 	nop
 7ac:	d503201f 	nop

00000000000007b0 <local_call_crossload>:
 7b0:	2a0203e8 	mov	w8, w2
 7b4:	8b080029 	add	x9, x1, x8
 7b8:	91001108 	add	x8, x8, #0x4
 7bc:	3940012a 	ldrb	w10, [x9]
 7c0:	3868682b 	ldrb	w11, [x1, x8]
 7c4:	8b28c028 	add	x8, x1, w8, sxtw
 7c8:	a940b929 	ldp	x9, x14, [x9, #8]
 7cc:	3940050c 	ldrb	w12, [x8, #1]
 7d0:	3940090d 	ldrb	w13, [x8, #2]
 7d4:	39400d08 	ldrb	w8, [x8, #3]
 7d8:	8b000129 	add	x9, x9, x0
 7dc:	9240094a 	and	x10, x10, #0x7
 7e0:	d377d96b 	lsl	x11, x11, #9
 7e4:	ca0901ce 	eor	x14, x14, x9
 7e8:	9100054f 	add	x15, x10, #0x1
 7ec:	52001550 	eor	w16, w10, #0x3f
 7f0:	9acf21cf 	lsl	x15, x14, x15
 7f4:	9ad025ce 	lsr	x14, x14, x16
 7f8:	aa0c456b 	orr	x11, x11, x12, lsl #17
 7fc:	aa0e01ee 	orr	x14, x15, x14
 800:	aa0d656b 	orr	x11, x11, x13, lsl #25
 804:	aa088568 	orr	x8, x11, x8, lsl #33
 808:	ca0e012b 	eor	x11, x9, x14
 80c:	ca080168 	eor	x8, x11, x8
 810:	2a0303eb 	mov	w11, w3
 814:	9aca216a 	lsl	x10, x11, x10
 818:	8b0a0108 	add	x8, x8, x10
 81c:	ca4e1508 	eor	x8, x8, x14, lsr #5
 820:	8b090100 	add	x0, x8, x9
 824:	d65f03c0 	ret
 828:	d503201f 	nop
 82c:	d503201f 	nop

0000000000000830 <local_call_bytes>:
 830:	8b224029 	add	x9, x1, w2, uxtw
 834:	d2823d6b 	mov	x11, #0x11eb                	// #4587
 838:	2a0303e8 	mov	w8, w3
 83c:	f2a2662b 	movk	x11, #0x1331, lsl #16
 840:	3940012a 	ldrb	w10, [x9]
 844:	f2c9376b 	movk	x11, #0x49bb, lsl #32
 848:	f2f29a0b 	movk	x11, #0x94d0, lsl #48
 84c:	ca0b000b 	eor	x11, x0, x11
 850:	ca0b014a 	eor	x10, x10, x11
 854:	3940052b 	ldrb	w11, [x9, #1]
 858:	8b08014a 	add	x10, x10, x8
 85c:	d378dd6b 	lsl	x11, x11, #8
 860:	cacafd6a 	eor	x10, x11, x10, ror #63
 864:	3940092b 	ldrb	w11, [x9, #2]
 868:	8b0a010a 	add	x10, x8, x10
 86c:	9100054a 	add	x10, x10, #0x1
 870:	d370bd6b 	lsl	x11, x11, #16
 874:	cacaf96a 	eor	x10, x11, x10, ror #62
 878:	39400d2b 	ldrb	w11, [x9, #3]
 87c:	8b0a010a 	add	x10, x8, x10
 880:	9100094a 	add	x10, x10, #0x2
 884:	d3689d6b 	lsl	x11, x11, #24
 888:	cacaf56a 	eor	x10, x11, x10, ror #61
 88c:	3940112b 	ldrb	w11, [x9, #4]
 890:	8b0a010a 	add	x10, x8, x10
 894:	91000d4a 	add	x10, x10, #0x3
 898:	d3607d6b 	lsl	x11, x11, #32
 89c:	cacaf16a 	eor	x10, x11, x10, ror #60
 8a0:	3940152b 	ldrb	w11, [x9, #5]
 8a4:	8b0a010a 	add	x10, x8, x10
 8a8:	9100114a 	add	x10, x10, #0x4
 8ac:	d3585d6b 	lsl	x11, x11, #40
 8b0:	cacaed6a 	eor	x10, x11, x10, ror #59
 8b4:	3940192b 	ldrb	w11, [x9, #6]
 8b8:	8b0a010a 	add	x10, x8, x10
 8bc:	9100154a 	add	x10, x10, #0x5
 8c0:	d3503d6b 	lsl	x11, x11, #48
 8c4:	cacae96a 	eor	x10, x11, x10, ror #58
 8c8:	39401d2b 	ldrb	w11, [x9, #7]
 8cc:	8b0a010a 	add	x10, x8, x10
 8d0:	9100194a 	add	x10, x10, #0x6
 8d4:	d3481d6b 	lsl	x11, x11, #56
 8d8:	cacae56a 	eor	x10, x11, x10, ror #57
 8dc:	8b0a0108 	add	x8, x8, x10
 8e0:	a940a929 	ldp	x9, x10, [x9, #8]
 8e4:	91001d08 	add	x8, x8, #0x7
 8e8:	93c8e108 	ror	x8, x8, #56
 8ec:	8b080128 	add	x8, x9, x8
 8f0:	ca080140 	eor	x0, x10, x8
 8f4:	d65f03c0 	ret

Disassembly of section .fini:

00000000000008f8 <_fini>:
 8f8:	d503201f 	nop
 8fc:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 900:	910003fd 	mov	x29, sp
 904:	a8c17bfd 	ldp	x29, x30, [sp], #16
 908:	d65f03c0 	ret
```

## Original Kernel JIT ASM
```asm
not captured
```

## llvmbpf JIT ASM
```asm
not captured
```
