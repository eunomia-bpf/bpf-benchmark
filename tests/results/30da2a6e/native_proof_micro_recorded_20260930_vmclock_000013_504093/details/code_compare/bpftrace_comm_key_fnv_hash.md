# bpftrace_comm_key_fnv_hash

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
 494:	f00000f0 	adrp	x16, 1f000 <__FRAME_END__+0x1e6b8>
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
 4e0:	f00000e0 	adrp	x0, 1f000 <__FRAME_END__+0x1e6b8>
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
 518:	f00000e1 	adrp	x1, 1f000 <__FRAME_END__+0x1e6b8>
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
 554:	f00000e2 	adrp	x2, 1f000 <__FRAME_END__+0x1e6b8>
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
 58c:	f00000e0 	adrp	x0, 1f000 <__FRAME_END__+0x1e6b8>
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

00000000000005e0 <bpftrace_comm_key_fnv_hash_xdp>:
 5e0:	a9402408 	ldp	x8, x9, [x0]
 5e4:	aa0803eb 	mov	x11, x8
 5e8:	eb09017f 	cmp	x11, x9
 5ec:	54000069 	b.ls	5f8 <bpftrace_comm_key_fnv_hash_xdp+0x18>  // b.plast
 5f0:	2a1f03e0 	mov	w0, wzr
 5f4:	d65f03c0 	ret
 5f8:	9100216a 	add	x10, x11, #0x8
 5fc:	9110416c 	add	x12, x11, #0x410
 600:	2a1f03e0 	mov	w0, wzr
 604:	eb09015f 	cmp	x10, x9
 608:	fa499182 	ccmp	x12, x9, #0x2, ls	// ls = plast
 60c:	540013e8 	b.hi	888 <bpftrace_comm_key_fnv_hash_xdp+0x2a8>  // b.pmore
 610:	b9400969 	ldr	w9, [x11, #8]
 614:	7100813f 	cmp	w9, #0x20
 618:	54001381 	b.ne	888 <bpftrace_comm_key_fnv_hash_xdp+0x2a8>  // b.any
 61c:	b9400d69 	ldr	w9, [x11, #12]
 620:	7100813f 	cmp	w9, #0x20
 624:	54001321 	b.ne	888 <bpftrace_comm_key_fnv_hash_xdp+0x2a8>  // b.any
 628:	f81e0ff5 	str	x21, [sp, #-32]!
 62c:	a9014ff4 	stp	x20, x19, [sp, #16]
 630:	d2823d6c 	mov	x12, #0x11eb                	// #4587
 634:	d28464ad 	mov	x13, #0x2325                	// #8997
 638:	d29950ee 	mov	x14, #0xca87                	// #51847
 63c:	d280366a 	mov	x10, #0x1b3                 	// #435
 640:	aa1f03e9 	mov	x9, xzr
 644:	91005d6b 	add	x11, x11, #0x17
 648:	f2a2662c 	movk	x12, #0x1331, lsl #16
 64c:	f2b0844d 	movk	x13, #0x8422, lsl #16
 650:	f2b0bd6e 	movk	x14, #0x85eb, lsl #16
 654:	f2c0200a 	movk	x10, #0x100, lsl #32
 658:	f2c9376c 	movk	x12, #0x49bb, lsl #32
 65c:	f2d39c8d 	movk	x13, #0x9ce4, lsl #32
 660:	f2cf362e 	movk	x14, #0x79b1, lsl #32
 664:	f2f29a0c 	movk	x12, #0x94d0, lsl #48
 668:	f2f97e4d 	movk	x13, #0xcbf2, lsl #48
 66c:	f2f3c6ee 	movk	x14, #0x9e37, lsl #48
 670:	14000015 	b	6c4 <bpftrace_comm_key_fnv_hash_xdp+0xe4>
 674:	d503201f 	nop
 678:	d503201f 	nop
 67c:	d503201f 	nop
 680:	53103e52 	lsl	w18, w18, #16
 684:	9100816b 	add	x11, x11, #0x20
 688:	2a112251 	orr	w17, w18, w17, lsl #8
 68c:	2a006231 	orr	w17, w17, w0, lsl #24
 690:	2a100230 	orr	w16, w17, w16
 694:	12000931 	and	w17, w9, #0x7
 698:	91000529 	add	x9, x9, #0x1
 69c:	11000632 	add	w18, w17, #0x1
 6a0:	52001631 	eor	w17, w17, #0x3f
 6a4:	aa0fe20f 	orr	x15, x16, x15, lsl #56
 6a8:	f100813f 	cmp	x9, #0x20
 6ac:	9ad22032 	lsl	x18, x1, x18
 6b0:	9ad12431 	lsr	x17, x1, x17
 6b4:	aa110251 	orr	x17, x18, x17
 6b8:	ca0c022c 	eor	x12, x17, x12
 6bc:	8b0f018c 	add	x12, x12, x15
 6c0:	54000dc0 	b.eq	878 <bpftrace_comm_key_fnv_hash_xdp+0x298>  // b.none
 6c4:	385f9161 	ldurb	w1, [x11, #-7]
 6c8:	385fa162 	ldurb	w2, [x11, #-6]
 6cc:	ca0d0034 	eor	x20, x1, x13
 6d0:	385fb164 	ldurb	w4, [x11, #-5]
 6d4:	385fc165 	ldurb	w5, [x11, #-4]
 6d8:	385fd163 	ldurb	w3, [x11, #-3]
 6dc:	385fe166 	ldurb	w6, [x11, #-2]
 6e0:	385ff167 	ldurb	w7, [x11, #-1]
 6e4:	39400173 	ldrb	w19, [x11]
 6e8:	39400570 	ldrb	w16, [x11, #1]
 6ec:	39400971 	ldrb	w17, [x11, #2]
 6f0:	d3607c21 	lsl	x1, x1, #32
 6f4:	9b0a7e94 	mul	x20, x20, x10
 6f8:	39400d72 	ldrb	w18, [x11, #3]
 6fc:	39401160 	ldrb	w0, [x11, #4]
 700:	92401c15 	and	x21, x0, #0xff
 704:	aa02a021 	orr	x1, x1, x2, lsl #40
 708:	aa04c021 	orr	x1, x1, x4, lsl #48
 70c:	3940156f 	ldrb	w15, [x11, #5]
 710:	720001ff 	tst	w15, #0x1
 714:	aa05e021 	orr	x1, x1, x5, lsl #56
 718:	aa062021 	orr	x1, x1, x6, lsl #8
 71c:	ca020294 	eor	x20, x20, x2
 720:	aa074021 	orr	x1, x1, x7, lsl #16
 724:	92400a02 	and	x2, x16, #0x7
 728:	9b0a7e94 	mul	x20, x20, x10
 72c:	aa136021 	orr	x1, x1, x19, lsl #24
 730:	aa030021 	orr	x1, x1, x3
 734:	ca040294 	eor	x20, x20, x4
 738:	9b0a7e94 	mul	x20, x20, x10
 73c:	ca050294 	eor	x20, x20, x5
 740:	9b0a7e94 	mul	x20, x20, x10
 744:	ca030294 	eor	x20, x20, x3
 748:	91000443 	add	x3, x2, #0x1
 74c:	52001442 	eor	w2, w2, #0x3f
 750:	9b0a7e94 	mul	x20, x20, x10
 754:	9ac32023 	lsl	x3, x1, x3
 758:	9ac22421 	lsr	x1, x1, x2
 75c:	aa010061 	orr	x1, x3, x1
 760:	ca060294 	eor	x20, x20, x6
 764:	9b0a7e94 	mul	x20, x20, x10
 768:	ca070294 	eor	x20, x20, x7
 76c:	9b0a7e94 	mul	x20, x20, x10
 770:	ca130294 	eor	x20, x20, x19
 774:	9b0a7e94 	mul	x20, x20, x10
 778:	ca100294 	eor	x20, x20, x16
 77c:	9b0a7e94 	mul	x20, x20, x10
 780:	ca110294 	eor	x20, x20, x17
 784:	9b0a7e94 	mul	x20, x20, x10
 788:	ca120294 	eor	x20, x20, x18
 78c:	9b0a7e94 	mul	x20, x20, x10
 790:	ca150294 	eor	x20, x20, x21
 794:	39402575 	ldrb	w21, [x11, #9]
 798:	9b0a7e94 	mul	x20, x20, x10
 79c:	ca150294 	eor	x20, x20, x21
 7a0:	39402975 	ldrb	w21, [x11, #10]
 7a4:	9b0a7e94 	mul	x20, x20, x10
 7a8:	ca150294 	eor	x20, x20, x21
 7ac:	39402d75 	ldrb	w21, [x11, #11]
 7b0:	9b0a7e94 	mul	x20, x20, x10
 7b4:	ca150294 	eor	x20, x20, x21
 7b8:	39403175 	ldrb	w21, [x11, #12]
 7bc:	9b0a7e94 	mul	x20, x20, x10
 7c0:	ca150294 	eor	x20, x20, x21
 7c4:	39403575 	ldrb	w21, [x11, #13]
 7c8:	9b0a7e94 	mul	x20, x20, x10
 7cc:	ca150294 	eor	x20, x20, x21
 7d0:	39403975 	ldrb	w21, [x11, #14]
 7d4:	9b0a7e94 	mul	x20, x20, x10
 7d8:	ca150294 	eor	x20, x20, x21
 7dc:	39403d75 	ldrb	w21, [x11, #15]
 7e0:	9b0a7e94 	mul	x20, x20, x10
 7e4:	ca150294 	eor	x20, x20, x21
 7e8:	39404175 	ldrb	w21, [x11, #16]
 7ec:	9b0a7e94 	mul	x20, x20, x10
 7f0:	ca150294 	eor	x20, x20, x21
 7f4:	39404575 	ldrb	w21, [x11, #17]
 7f8:	9b0a7e94 	mul	x20, x20, x10
 7fc:	ca150294 	eor	x20, x20, x21
 800:	39404975 	ldrb	w21, [x11, #18]
 804:	9b0a7e94 	mul	x20, x20, x10
 808:	ca150294 	eor	x20, x20, x21
 80c:	39404d75 	ldrb	w21, [x11, #19]
 810:	9b0a7e94 	mul	x20, x20, x10
 814:	ca150294 	eor	x20, x20, x21
 818:	39405175 	ldrb	w21, [x11, #20]
 81c:	9b0a7e94 	mul	x20, x20, x10
 820:	ca150294 	eor	x20, x20, x21
 824:	39405575 	ldrb	w21, [x11, #21]
 828:	9b0a7e94 	mul	x20, x20, x10
 82c:	ca150294 	eor	x20, x20, x21
 830:	39405975 	ldrb	w21, [x11, #22]
 834:	9b0a7e94 	mul	x20, x20, x10
 838:	ca150294 	eor	x20, x20, x21
 83c:	39405d75 	ldrb	w21, [x11, #23]
 840:	9b0a7e94 	mul	x20, x20, x10
 844:	ca150294 	eor	x20, x20, x21
 848:	39406175 	ldrb	w21, [x11, #24]
 84c:	9b0a7e94 	mul	x20, x20, x10
 850:	ca150294 	eor	x20, x20, x21
 854:	9b0a7e94 	mul	x20, x20, x10
 858:	ca010281 	eor	x1, x20, x1
 85c:	9a810281 	csel	x1, x20, x1, eq	// eq = none
 860:	360ff10f 	tbz	w15, #1, 680 <bpftrace_comm_key_fnv_hash_xdp+0xa0>
 864:	39402562 	ldrb	w2, [x11, #9]
 868:	8b0e0023 	add	x3, x1, x14
 86c:	7101c05f 	cmp	w2, #0x70
 870:	9a810061 	csel	x1, x3, x1, eq	// eq = none
 874:	17ffff83 	b	680 <bpftrace_comm_key_fnv_hash_xdp+0xa0>
 878:	a9414ff4 	ldp	x20, x19, [sp, #16]
 87c:	52800040 	mov	w0, #0x2                   	// #2
 880:	f900010c 	str	x12, [x8]
 884:	f84207f5 	ldr	x21, [sp], #32
 888:	d65f03c0 	ret

Disassembly of section .fini:

000000000000088c <_fini>:
 88c:	d503201f 	nop
 890:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 894:	910003fd 	mov	x29, sp
 898:	a8c17bfd 	ldp	x29, x30, [sp], #16
 89c:	d65f03c0 	ret
```

## Original Kernel JIT ASM
```asm
not captured
```

## llvmbpf JIT ASM
```asm
not captured
```
