# tetragon_process_event_arg_filter

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
 494:	f00000f0 	adrp	x16, 1f000 <__FRAME_END__+0x1e680>
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
 4e0:	f00000e0 	adrp	x0, 1f000 <__FRAME_END__+0x1e680>
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
 518:	f00000e1 	adrp	x1, 1f000 <__FRAME_END__+0x1e680>
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
 554:	f00000e2 	adrp	x2, 1f000 <__FRAME_END__+0x1e680>
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
 58c:	f00000e0 	adrp	x0, 1f000 <__FRAME_END__+0x1e680>
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

00000000000005e0 <tetragon_process_event_arg_filter_xdp>:
 5e0:	a9402408 	ldp	x8, x9, [x0]
 5e4:	aa0803ea 	mov	x10, x8
 5e8:	eb09015f 	cmp	x10, x9
 5ec:	54000069 	b.ls	5f8 <tetragon_process_event_arg_filter_xdp+0x18>  // b.plast
 5f0:	2a1f03e0 	mov	w0, wzr
 5f4:	d65f03c0 	ret
 5f8:	9100214b 	add	x11, x10, #0x8
 5fc:	9110414c 	add	x12, x10, #0x410
 600:	2a1f03e0 	mov	w0, wzr
 604:	eb09017f 	cmp	x11, x9
 608:	fa499182 	ccmp	x12, x9, #0x2, ls	// ls = plast
 60c:	540015c8 	b.hi	8c4 <tetragon_process_event_arg_filter_xdp+0x2e4>  // b.pmore
 610:	b9400949 	ldr	w9, [x10, #8]
 614:	7100813f 	cmp	w9, #0x20
 618:	54001561 	b.ne	8c4 <tetragon_process_event_arg_filter_xdp+0x2e4>  // b.any
 61c:	b9400d49 	ldr	w9, [x10, #12]
 620:	7100813f 	cmp	w9, #0x20
 624:	54001501 	b.ne	8c4 <tetragon_process_event_arg_filter_xdp+0x2e4>  // b.any
 628:	a9bb6ffc 	stp	x28, x27, [sp, #-80]!
 62c:	a90167fa 	stp	x26, x25, [sp, #16]
 630:	a9025ff8 	stp	x24, x23, [sp, #32]
 634:	a90357f6 	stp	x22, x21, [sp, #48]
 638:	a9044ff4 	stp	x20, x19, [sp, #64]
 63c:	91005d4b 	add	x11, x10, #0x17
 640:	d2851b6a 	mov	x10, #0x28db                	// #10459
 644:	d28f2e0f 	mov	x15, #0x7970                	// #31088
 648:	528c2c4c 	mov	w12, #0x6162                	// #24930
 64c:	528eac6e 	mov	w14, #0x7563                	// #30051
 650:	aa1f03e9 	mov	x9, xzr
 654:	5280048d 	mov	w13, #0x24                  	// #36
 658:	528d0e70 	mov	w16, #0x6873                	// #26739
 65c:	f2b4168a 	movk	x10, #0xa0b4, lsl #16
 660:	f2ad0e8f 	movk	x15, #0x6874, lsl #16
 664:	72ad0e6c 	movk	w12, #0x6873, lsl #16
 668:	72ad8e4e 	movk	w14, #0x6c72, lsl #16
 66c:	52800b31 	mov	w17, #0x59                  	// #89
 670:	f2cfda2a 	movk	x10, #0x7ed1, lsl #32
 674:	f2cdcdef 	movk	x15, #0x6e6f, lsl #32
 678:	f2fce06a 	movk	x10, #0xe703, lsl #48
 67c:	14000007 	b	698 <tetragon_process_event_arg_filter_xdp+0xb8>
 680:	aa008312 	orr	x18, x24, x0, lsl #32
 684:	ca0a024a 	eor	x10, x18, x10
 688:	91000529 	add	x9, x9, #0x1
 68c:	9100816b 	add	x11, x11, #0x20
 690:	f100813f 	cmp	x9, #0x20
 694:	540010a0 	b.eq	8a8 <tetragon_process_event_arg_filter_xdp+0x2c8>  // b.none
 698:	39401572 	ldrb	w18, [x11, #5]
 69c:	39401960 	ldrb	w0, [x11, #6]
 6a0:	2a002240 	orr	w0, w18, w0, lsl #8
 6a4:	7100101f 	cmp	w0, #0x4
 6a8:	540000ec 	b.gt	6c4 <tetragon_process_event_arg_filter_xdp+0xe4>
 6ac:	7100041f 	cmp	w0, #0x1
 6b0:	540001c0 	b.eq	6e8 <tetragon_process_event_arg_filter_xdp+0x108>  // b.none
 6b4:	7100081f 	cmp	w0, #0x2
 6b8:	54000121 	b.ne	6dc <tetragon_process_event_arg_filter_xdp+0xfc>  // b.any
 6bc:	52800461 	mov	w1, #0x23                  	// #35
 6c0:	14000010 	b	700 <tetragon_process_event_arg_filter_xdp+0x120>
 6c4:	7100141f 	cmp	w0, #0x5
 6c8:	54000140 	b.eq	6f0 <tetragon_process_event_arg_filter_xdp+0x110>  // b.none
 6cc:	7100241f 	cmp	w0, #0x9
 6d0:	54000061 	b.ne	6dc <tetragon_process_event_arg_filter_xdp+0xfc>  // b.any
 6d4:	52800821 	mov	w1, #0x41                  	// #65
 6d8:	1400000a 	b	700 <tetragon_process_event_arg_filter_xdp+0x120>
 6dc:	7100341f 	cmp	w0, #0xd
 6e0:	1a9f0221 	csel	w1, w17, wzr, eq	// eq = none
 6e4:	14000007 	b	700 <tetragon_process_event_arg_filter_xdp+0x120>
 6e8:	52800221 	mov	w1, #0x11                  	// #17
 6ec:	14000005 	b	700 <tetragon_process_event_arg_filter_xdp+0x120>
 6f0:	528006e1 	mov	w1, #0x37                  	// #55
 6f4:	d503201f 	nop
 6f8:	d503201f 	nop
 6fc:	d503201f 	nop
 700:	78411162 	ldurh	w2, [x11, #17]
 704:	39404d63 	ldrb	w3, [x11, #19]
 708:	aa034043 	orr	x3, x2, x3, lsl #16
 70c:	39405162 	ldrb	w2, [x11, #20]
 710:	39405965 	ldrb	w5, [x11, #22]
 714:	d3585ca5 	lsl	x5, x5, #40
 718:	aa026064 	orr	x4, x3, x2, lsl #24
 71c:	39405562 	ldrb	w2, [x11, #21]
 720:	6b0c009f 	cmp	w4, w12
 724:	aa0280a2 	orr	x2, x5, x2, lsl #32
 728:	aa040042 	orr	x2, x2, x4
 72c:	540000e0 	b.eq	748 <tetragon_process_event_arg_filter_xdp+0x168>  // b.none
 730:	6b0e009f 	cmp	w4, w14
 734:	54000161 	b.ne	760 <tetragon_process_event_arg_filter_xdp+0x180>  // b.any
 738:	52800056 	mov	w22, #0x2                   	// #2
 73c:	b85f9178 	ldur	w24, [x11, #-7]
 740:	35000261 	cbnz	w1, 78c <tetragon_process_event_arg_filter_xdp+0x1ac>
 744:	17ffffcf 	b	680 <tetragon_process_event_arg_filter_xdp+0xa0>
 748:	52800036 	mov	w22, #0x1                   	// #1
 74c:	b85f9178 	ldur	w24, [x11, #-7]
 750:	350001e1 	cbnz	w1, 78c <tetragon_process_event_arg_filter_xdp+0x1ac>
 754:	17ffffcb 	b	680 <tetragon_process_event_arg_filter_xdp+0xa0>
 758:	d503201f 	nop
 75c:	d503201f 	nop
 760:	eb0f005f 	cmp	x2, x15
 764:	540000a1 	b.ne	778 <tetragon_process_event_arg_filter_xdp+0x198>  // b.any
 768:	52800076 	mov	w22, #0x3                   	// #3
 76c:	b85f9178 	ldur	w24, [x11, #-7]
 770:	350000e1 	cbnz	w1, 78c <tetragon_process_event_arg_filter_xdp+0x1ac>
 774:	17ffffc3 	b	680 <tetragon_process_event_arg_filter_xdp+0xa0>
 778:	eb10007f 	cmp	x3, x16
 77c:	1a9f17e3 	cset	w3, eq	// eq = none
 780:	531e7476 	lsl	w22, w3, #2
 784:	b85f9178 	ldur	w24, [x11, #-7]
 788:	34fff7c1 	cbz	w1, 680 <tetragon_process_event_arg_filter_xdp+0xa0>
 78c:	3940057a 	ldrb	w26, [x11, #1]
 790:	78407160 	ldurh	w0, [x11, #7]
 794:	71010b5f 	cmp	w26, #0x42
 798:	39402564 	ldrb	w4, [x11, #9]
 79c:	39402965 	ldrb	w5, [x11, #10]
 7a0:	39402d66 	ldrb	w6, [x11, #11]
 7a4:	39403177 	ldrb	w23, [x11, #12]
 7a8:	39403567 	ldrb	w7, [x11, #13]
 7ac:	39403975 	ldrb	w21, [x11, #14]
 7b0:	39403d73 	ldrb	w19, [x11, #15]
 7b4:	39404174 	ldrb	w20, [x11, #16]
 7b8:	39405d79 	ldrb	w25, [x11, #23]
 7bc:	3940617b 	ldrb	w27, [x11, #24]
 7c0:	b85fd163 	ldur	w3, [x11, #-3]
 7c4:	54000200 	b.eq	804 <tetragon_process_event_arg_filter_xdp+0x224>  // b.none
 7c8:	8a0d00bc 	and	x28, x5, x13
 7cc:	b50001dc 	cbnz	x28, 804 <tetragon_process_event_arg_filter_xdp+0x224>
 7d0:	39400972 	ldrb	w18, [x11, #2]
 7d4:	39400d60 	ldrb	w0, [x11, #3]
 7d8:	aa122352 	orr	x18, x26, x18, lsl #8
 7dc:	39401161 	ldrb	w1, [x11, #4]
 7e0:	aa004252 	orr	x18, x18, x0, lsl #16
 7e4:	aa016252 	orr	x18, x18, x1, lsl #24
 7e8:	ca034252 	eor	x18, x18, x3, lsl #16
 7ec:	8b0a024a 	add	x10, x18, x10
 7f0:	91000529 	add	x9, x9, #0x1
 7f4:	9100816b 	add	x11, x11, #0x20
 7f8:	f100813f 	cmp	x9, #0x20
 7fc:	54fff4e1 	b.ne	698 <tetragon_process_event_arg_filter_xdp+0xb8>  // b.any
 800:	1400002a 	b	8a8 <tetragon_process_event_arg_filter_xdp+0x2c8>
 804:	d3503c21 	lsl	x1, x1, #48
 808:	aa16a021 	orr	x1, x1, x22, lsl #40
 80c:	aa006021 	orr	x1, x1, x0, lsl #24
 810:	aa180021 	orr	x1, x1, x24
 814:	36080180 	tbz	w0, #1, 844 <tetragon_process_event_arg_filter_xdp+0x264>
 818:	34000176 	cbz	w22, 844 <tetragon_process_event_arg_filter_xdp+0x264>
 81c:	d3481f76 	lsl	x22, x27, #56
 820:	92400a52 	and	x18, x18, #0x7
 824:	aa19c2d6 	orr	x22, x22, x25, lsl #48
 828:	aa0202c2 	orr	x2, x22, x2
 82c:	91000656 	add	x22, x18, #0x1
 830:	52001652 	eor	w18, w18, #0x3f
 834:	9ad62056 	lsl	x22, x2, x22
 838:	9ad22452 	lsr	x18, x2, x18
 83c:	aa1202d2 	orr	x18, x22, x18
 840:	ca120021 	eor	x1, x1, x18
 844:	d3689ef2 	lsl	x18, x23, #24
 848:	d3585ea2 	lsl	x2, x21, #40
 84c:	d3481e94 	lsl	x20, x20, #56
 850:	aa052084 	orr	x4, x4, x5, lsl #8
 854:	721e001f 	tst	w0, #0x4
 858:	12000920 	and	w0, w9, #0x7
 85c:	aa064252 	orr	x18, x18, x6, lsl #16
 860:	aa078042 	orr	x2, x2, x7, lsl #32
 864:	aa040252 	orr	x18, x18, x4
 868:	aa13c284 	orr	x4, x20, x19, lsl #48
 86c:	aa020082 	orr	x2, x4, x2
 870:	aa120052 	orr	x18, x2, x18
 874:	ca030252 	eor	x18, x18, x3
 878:	9a9203f2 	csel	x18, xzr, x18, eq	// eq = none
 87c:	8b120032 	add	x18, x1, x18
 880:	11000401 	add	w1, w0, #0x1
 884:	52001400 	eor	w0, w0, #0x3f
 888:	9ac12241 	lsl	x1, x18, x1
 88c:	9ac02652 	lsr	x18, x18, x0
 890:	aa120032 	orr	x18, x1, x18
 894:	ca0a024a 	eor	x10, x18, x10
 898:	91000529 	add	x9, x9, #0x1
 89c:	9100816b 	add	x11, x11, #0x20
 8a0:	f100813f 	cmp	x9, #0x20
 8a4:	54ffefa1 	b.ne	698 <tetragon_process_event_arg_filter_xdp+0xb8>  // b.any
 8a8:	a9444ff4 	ldp	x20, x19, [sp, #64]
 8ac:	52800040 	mov	w0, #0x2                   	// #2
 8b0:	f900010a 	str	x10, [x8]
 8b4:	a94357f6 	ldp	x22, x21, [sp, #48]
 8b8:	a9425ff8 	ldp	x24, x23, [sp, #32]
 8bc:	a94167fa 	ldp	x26, x25, [sp, #16]
 8c0:	a8c56ffc 	ldp	x28, x27, [sp], #80
 8c4:	d65f03c0 	ret

Disassembly of section .fini:

00000000000008c8 <_fini>:
 8c8:	d503201f 	nop
 8cc:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 8d0:	910003fd 	mov	x29, sp
 8d4:	a8c17bfd 	ldp	x29, x30, [sp], #16
 8d8:	d65f03c0 	ret
```

## Original Kernel JIT ASM
```asm
not captured
```

## llvmbpf JIT ASM
```asm
not captured
```
