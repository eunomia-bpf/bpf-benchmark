# bpftrace_string_search_prefix_scan

## Original C
```c
not captured
```

## Native ASM
```asm
Disassembly of section .init:

0000000000000478 <_init>:
 478:	d503201f 	nop
 47c:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 480:	910003fd 	mov	x29, sp
 484:	94000017 	bl	4e0 <call_weak_fn>
 488:	a8c17bfd 	ldp	x29, x30, [sp], #16
 48c:	d65f03c0 	ret

Disassembly of section .plt:

0000000000000490 <.plt>:
 490:	a9bf7bf0 	stp	x16, x30, [sp, #-16]!
 494:	f00000f0 	adrp	x16, 1f000 <__FRAME_END__+0x1e760>
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
 4e0:	f00000e0 	adrp	x0, 1f000 <__FRAME_END__+0x1e760>
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
 518:	f00000e1 	adrp	x1, 1f000 <__FRAME_END__+0x1e760>
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
 554:	f00000e2 	adrp	x2, 1f000 <__FRAME_END__+0x1e760>
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
 58c:	f00000e0 	adrp	x0, 1f000 <__FRAME_END__+0x1e760>
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

00000000000005e0 <bpftrace_string_search_prefix_scan_xdp>:
 5e0:	a9402808 	ldp	x8, x10, [x0]
 5e4:	aa0803e9 	mov	x9, x8
 5e8:	eb0a013f 	cmp	x9, x10
 5ec:	54000568 	b.hi	698 <bpftrace_string_search_prefix_scan_xdp+0xb8>  // b.pmore
 5f0:	9100212b 	add	x11, x9, #0x8
 5f4:	9101e12c 	add	x12, x9, #0x78
 5f8:	eb0a017f 	cmp	x11, x10
 5fc:	fa4a9182 	ccmp	x12, x10, #0x2, ls	// ls = plast
 600:	540004c8 	b.hi	698 <bpftrace_string_search_prefix_scan_xdp+0xb8>  // b.pmore
 604:	2941292b 	ldp	w11, w10, [x9, #8]
 608:	3941c12c 	ldrb	w12, [x9, #112]
 60c:	3400024c 	cbz	w12, 654 <bpftrace_string_search_prefix_scan_xdp+0x74>
 610:	3941c52d 	ldrb	w13, [x9, #113]
 614:	3400024d 	cbz	w13, 65c <bpftrace_string_search_prefix_scan_xdp+0x7c>
 618:	3941c92d 	ldrb	w13, [x9, #114]
 61c:	3400024d 	cbz	w13, 664 <bpftrace_string_search_prefix_scan_xdp+0x84>
 620:	3941cd2d 	ldrb	w13, [x9, #115]
 624:	3400024d 	cbz	w13, 66c <bpftrace_string_search_prefix_scan_xdp+0x8c>
 628:	3941d12d 	ldrb	w13, [x9, #116]
 62c:	3400024d 	cbz	w13, 674 <bpftrace_string_search_prefix_scan_xdp+0x94>
 630:	3941d52d 	ldrb	w13, [x9, #117]
 634:	3400024d 	cbz	w13, 67c <bpftrace_string_search_prefix_scan_xdp+0x9c>
 638:	3941d92d 	ldrb	w13, [x9, #118]
 63c:	3400024d 	cbz	w13, 684 <bpftrace_string_search_prefix_scan_xdp+0xa4>
 640:	3941dd2d 	ldrb	w13, [x9, #119]
 644:	710001bf 	cmp	w13, #0x0
 648:	528000ed 	mov	w13, #0x7                   	// #7
 64c:	1a8d05ad 	cinc	w13, w13, ne	// ne = any
 650:	1400000e 	b	688 <bpftrace_string_search_prefix_scan_xdp+0xa8>
 654:	2a1f03ed 	mov	w13, wzr
 658:	1400000c 	b	688 <bpftrace_string_search_prefix_scan_xdp+0xa8>
 65c:	5280002d 	mov	w13, #0x1                   	// #1
 660:	1400000a 	b	688 <bpftrace_string_search_prefix_scan_xdp+0xa8>
 664:	5280004d 	mov	w13, #0x2                   	// #2
 668:	14000008 	b	688 <bpftrace_string_search_prefix_scan_xdp+0xa8>
 66c:	5280006d 	mov	w13, #0x3                   	// #3
 670:	14000006 	b	688 <bpftrace_string_search_prefix_scan_xdp+0xa8>
 674:	5280008d 	mov	w13, #0x4                   	// #4
 678:	14000004 	b	688 <bpftrace_string_search_prefix_scan_xdp+0xa8>
 67c:	528000ad 	mov	w13, #0x5                   	// #5
 680:	14000002 	b	688 <bpftrace_string_search_prefix_scan_xdp+0xa8>
 684:	528000cd 	mov	w13, #0x6                   	// #6
 688:	7101817f 	cmp	w11, #0x60
 68c:	7a4d9140 	ccmp	w10, w13, #0x0, ls	// ls = plast
 690:	7a400984 	ccmp	w12, #0x0, #0x4, eq	// eq = none
 694:	54000061 	b.ne	6a0 <bpftrace_string_search_prefix_scan_xdp+0xc0>  // b.any
 698:	2a1f03e0 	mov	w0, wzr
 69c:	d65f03c0 	ret
 6a0:	d29da06f 	mov	x15, #0xed03                	// #60675
 6a4:	d29222cd 	mov	x13, #0x9116                	// #37142
 6a8:	11000d51 	add	w17, w10, #0x3
 6ac:	aa1f03ee 	mov	x14, xzr
 6b0:	91004130 	add	x16, x9, #0x10
 6b4:	f2ba324f 	movk	x15, #0xd192, lsl #16
 6b8:	f2b5db0d 	movk	x13, #0xaed8, lsl #16
 6bc:	f2c9464f 	movk	x15, #0x4a32, lsl #32
 6c0:	f2c6716d 	movk	x13, #0x338b, lsl #32
 6c4:	f2fa36af 	movk	x15, #0xd1b5, lsl #48
 6c8:	f2e9f04d 	movk	x13, #0x4f82, lsl #48
 6cc:	8b0f022f 	add	x15, x17, x15
 6d0:	14000009 	b	6f4 <bpftrace_string_search_prefix_scan_xdp+0x114>
 6d4:	d503201f 	nop
 6d8:	d503201f 	nop
 6dc:	d503201f 	nop
 6e0:	34000752 	cbz	w18, 7c8 <bpftrace_string_search_prefix_scan_xdp+0x1e8>
 6e4:	910005ce 	add	x14, x14, #0x1
 6e8:	8b1101ef 	add	x15, x15, x17
 6ec:	f10165df 	cmp	x14, #0x59
 6f0:	54000740 	b.eq	7d8 <bpftrace_string_search_prefix_scan_xdp+0x1f8>  // b.none
 6f4:	8b0e0152 	add	x18, x10, x14
 6f8:	eb0b025f 	cmp	x18, x11
 6fc:	54ffff48 	b.hi	6e4 <bpftrace_string_search_prefix_scan_xdp+0x104>  // b.pmore
 700:	3400064a 	cbz	w10, 7c8 <bpftrace_string_search_prefix_scan_xdp+0x1e8>
 704:	386e6a12 	ldrb	w18, [x16, x14]
 708:	7100095f 	cmp	w10, #0x2
 70c:	4a120192 	eor	w18, w12, w18
 710:	54fffe83 	b.cc	6e0 <bpftrace_string_search_prefix_scan_xdp+0x100>  // b.lo, b.ul, b.last
 714:	8b0e0200 	add	x0, x16, x14
 718:	3941c522 	ldrb	w2, [x9, #113]
 71c:	71000d5f 	cmp	w10, #0x3
 720:	39400401 	ldrb	w1, [x0, #1]
 724:	4a010041 	eor	w1, w2, w1
 728:	2a010252 	orr	w18, w18, w1
 72c:	54fffda3 	b.cc	6e0 <bpftrace_string_search_prefix_scan_xdp+0x100>  // b.lo, b.ul, b.last
 730:	39400800 	ldrb	w0, [x0, #2]
 734:	3941c921 	ldrb	w1, [x9, #114]
 738:	7100115f 	cmp	w10, #0x4
 73c:	4a000020 	eor	w0, w1, w0
 740:	2a000252 	orr	w18, w18, w0
 744:	54fffce3 	b.cc	6e0 <bpftrace_string_search_prefix_scan_xdp+0x100>  // b.lo, b.ul, b.last
 748:	8b0e0200 	add	x0, x16, x14
 74c:	3941cd22 	ldrb	w2, [x9, #115]
 750:	7100155f 	cmp	w10, #0x5
 754:	39400c01 	ldrb	w1, [x0, #3]
 758:	4a010041 	eor	w1, w2, w1
 75c:	2a010252 	orr	w18, w18, w1
 760:	54fffc03 	b.cc	6e0 <bpftrace_string_search_prefix_scan_xdp+0x100>  // b.lo, b.ul, b.last
 764:	39401000 	ldrb	w0, [x0, #4]
 768:	3941d121 	ldrb	w1, [x9, #116]
 76c:	7100195f 	cmp	w10, #0x6
 770:	4a000020 	eor	w0, w1, w0
 774:	2a000252 	orr	w18, w18, w0
 778:	54fffb43 	b.cc	6e0 <bpftrace_string_search_prefix_scan_xdp+0x100>  // b.lo, b.ul, b.last
 77c:	8b0e0200 	add	x0, x16, x14
 780:	3941d522 	ldrb	w2, [x9, #117]
 784:	71001d5f 	cmp	w10, #0x7
 788:	39401401 	ldrb	w1, [x0, #5]
 78c:	4a010041 	eor	w1, w2, w1
 790:	2a010252 	orr	w18, w18, w1
 794:	54fffa63 	b.cc	6e0 <bpftrace_string_search_prefix_scan_xdp+0x100>  // b.lo, b.ul, b.last
 798:	39401800 	ldrb	w0, [x0, #6]
 79c:	3941d921 	ldrb	w1, [x9, #118]
 7a0:	7100215f 	cmp	w10, #0x8
 7a4:	4a000020 	eor	w0, w1, w0
 7a8:	2a000252 	orr	w18, w18, w0
 7ac:	54fff9a3 	b.cc	6e0 <bpftrace_string_search_prefix_scan_xdp+0x100>  // b.lo, b.ul, b.last
 7b0:	8b0e0200 	add	x0, x16, x14
 7b4:	3941dd21 	ldrb	w1, [x9, #119]
 7b8:	39401c00 	ldrb	w0, [x0, #7]
 7bc:	4a000020 	eor	w0, w1, w0
 7c0:	2a000252 	orr	w18, w18, w0
 7c4:	17ffffc7 	b	6e0 <bpftrace_string_search_prefix_scan_xdp+0x100>
 7c8:	f10181df 	cmp	x14, #0x60
 7cc:	54000060 	b.eq	7d8 <bpftrace_string_search_prefix_scan_xdp+0x1f8>  // b.none
 7d0:	8b0a81c9 	add	x9, x14, x10, lsl #32
 7d4:	cac9f5ed 	eor	x13, x15, x9, ror #61
 7d8:	52800040 	mov	w0, #0x2                   	// #2
 7dc:	f900010d 	str	x13, [x8]
 7e0:	d65f03c0 	ret

Disassembly of section .fini:

00000000000007e4 <_fini>:
 7e4:	d503201f 	nop
 7e8:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 7ec:	910003fd 	mov	x29, sp
 7f0:	a8c17bfd 	ldp	x29, x30, [sp], #16
 7f4:	d65f03c0 	ret
```

## Original Kernel JIT ASM
```asm
not captured
```

## llvmbpf JIT ASM
```asm
not captured
```
