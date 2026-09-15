# tracee_syscall_name_table_lookup

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
 494:	f00000f0 	adrp	x16, 1f000 <__FRAME_END__+0x1e5b0>
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
 4e0:	f00000e0 	adrp	x0, 1f000 <__FRAME_END__+0x1e5b0>
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
 518:	f00000e1 	adrp	x1, 1f000 <__FRAME_END__+0x1e5b0>
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
 554:	f00000e2 	adrp	x2, 1f000 <__FRAME_END__+0x1e5b0>
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
 58c:	f00000e0 	adrp	x0, 1f000 <__FRAME_END__+0x1e5b0>
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

00000000000005e0 <tracee_syscall_name_table_lookup_xdp>:
 5e0:	a9402408 	ldp	x8, x9, [x0]
 5e4:	aa0803eb 	mov	x11, x8
 5e8:	eb09017f 	cmp	x11, x9
 5ec:	54000968 	b.hi	718 <tracee_syscall_name_table_lookup_xdp+0x138>  // b.pmore
 5f0:	9100216a 	add	x10, x11, #0x8
 5f4:	9104316c 	add	x12, x11, #0x10c
 5f8:	eb09015f 	cmp	x10, x9
 5fc:	fa499182 	ccmp	x12, x9, #0x2, ls	// ls = plast
 600:	540008c8 	b.hi	718 <tracee_syscall_name_table_lookup_xdp+0x138>  // b.pmore
 604:	b9400149 	ldr	w9, [x10]
 608:	7101013f 	cmp	w9, #0x40
 60c:	54000861 	b.ne	718 <tracee_syscall_name_table_lookup_xdp+0x138>  // b.any
 610:	f81c0ff9 	str	x25, [sp, #-64]!
 614:	a9015ff8 	stp	x24, x23, [sp, #16]
 618:	a90257f6 	stp	x22, x21, [sp, #32]
 61c:	a9034ff4 	stp	x20, x19, [sp, #48]
 620:	d299212c 	mov	x12, #0xc909                	// #51465
 624:	d29950e0 	mov	x0, #0xca87                	// #51847
 628:	d28e4c23 	mov	x3, #0x7261                	// #29281
 62c:	d28dcea7 	mov	x7, #0x6e75                	// #28277
 630:	d28e8e73 	mov	x19, #0x7473                	// #29811
 634:	d28d2e74 	mov	x20, #0x6973                	// #26995
 638:	d28e4eed 	mov	x13, #0x7277                	// #29303
 63c:	d28d8c6e 	mov	x14, #0x6c63                	// #27747
 640:	f2be778c 	movk	x12, #0xf3bc, lsl #16
 644:	d28e8cef 	mov	x15, #0x7467                	// #29799
 648:	d28c6ab0 	mov	x16, #0x6355                	// #25429
 64c:	d28f0cb1 	mov	x17, #0x7865                	// #30821
 650:	d28eeab2 	mov	x18, #0x7755                	// #30549
 654:	f2b0bd60 	movk	x0, #0x85eb, lsl #16
 658:	d28dcea1 	mov	x1, #0x6e75                	// #28277
 65c:	d28d8aa2 	mov	x2, #0x6c55                	// #27733
 660:	f2ad0c63 	movk	x3, #0x6863, lsl #16
 664:	d28ccaa4 	mov	x4, #0x6655                	// #26197
 668:	d28cace5 	mov	x5, #0x6567                	// #25959
 66c:	d28e0de6 	mov	x6, #0x706f                	// #28783
 670:	f2ad2d87 	movk	x7, #0x696c, lsl #16
 674:	f2ae8c33 	movk	x19, #0x7461, lsl #16
 678:	f2adccf4 	movk	x20, #0x6e67, lsl #16
 67c:	528c4d6a 	mov	w10, #0x626b                	// #25195
 680:	f2dcccec 	movk	x12, #0xe667, lsl #32
 684:	f2ae8d2d 	movk	x13, #0x7469, lsl #16
 688:	f2ae6dee 	movk	x14, #0x736f, lsl #16
 68c:	f2ad2e0f 	movk	x15, #0x6970, lsl #16
 690:	f2aded90 	movk	x16, #0x6f6c, lsl #16
 694:	f2ac6cb1 	movk	x17, #0x6365, lsl #16
 698:	f2ad2c32 	movk	x18, #0x6961, lsl #16
 69c:	f2cf3620 	movk	x0, #0x79b1, lsl #32
 6a0:	f2ad2d81 	movk	x1, #0x696c, lsl #16
 6a4:	f2adcd22 	movk	x2, #0x6e69, lsl #16
 6a8:	f2cc6be3 	movk	x3, #0x635f, lsl #32
 6ac:	f2ae8ea4 	movk	x4, #0x7475, lsl #16
 6b0:	f2ac2e85 	movk	x5, #0x6174, lsl #16
 6b4:	f2adcca6 	movk	x6, #0x6e65, lsl #16
 6b8:	f2cd6dc7 	movk	x7, #0x6b6e, lsl #32
 6bc:	f2cc2653 	movk	x19, #0x6132, lsl #32
 6c0:	f2ccccb4 	movk	x20, #0x6665, lsl #32
 6c4:	aa1f03e9 	mov	x9, xzr
 6c8:	72ad6e4a 	movk	w10, #0x6b72, lsl #16
 6cc:	91003d6b 	add	x11, x11, #0xf
 6d0:	f2ed412c 	movk	x12, #0x6a09, lsl #48
 6d4:	f2c00cad 	movk	x13, #0x65, lsl #32
 6d8:	f2c00cae 	movk	x14, #0x65, lsl #32
 6dc:	f2c00c8f 	movk	x15, #0x64, lsl #32
 6e0:	f2ccadd0 	movk	x16, #0x656e, lsl #32
 6e4:	f2ccaed1 	movk	x17, #0x6576, lsl #32
 6e8:	f2c68e92 	movk	x18, #0x3474, lsl #32
 6ec:	f2f3c6e0 	movk	x0, #0x9e37, lsl #48
 6f0:	f2cd6dc1 	movk	x1, #0x6b6e, lsl #32
 6f4:	f2c00d62 	movk	x2, #0x6b, lsl #32
 6f8:	f2ed8e83 	movk	x3, #0x6c74, lsl #48
 6fc:	f2cf0ca4 	movk	x4, #0x7865, lsl #32
 700:	f2cc8c85 	movk	x5, #0x6464, lsl #32
 704:	f2ce8c26 	movk	x6, #0x7461, lsl #32
 708:	f2ee8c27 	movk	x7, #0x7461, lsl #48
 70c:	f2e00e93 	movk	x19, #0x74, lsl #48
 710:	f2ec8e94 	movk	x20, #0x6474, lsl #48
 714:	14000014 	b	764 <tracee_syscall_name_table_lookup_xdp+0x184>
 718:	2a1f03e0 	mov	w0, wzr
 71c:	d65f03c0 	ret
 720:	528ccc57 	mov	w23, #0x6662                	// #26210
 724:	72a00e17 	movk	w23, #0x70, lsl #16
 728:	ca1602f6 	eor	x22, x23, x22
 72c:	12000937 	and	w23, w9, #0x7
 730:	110006f8 	add	w24, w23, #0x1
 734:	520016f9 	eor	w25, w23, #0x3f
 738:	9ad822d8 	lsl	x24, x22, x24
 73c:	9ad926d6 	lsr	x22, x22, x25
 740:	aa160316 	orr	x22, x24, x22
 744:	8b0c02cc 	add	x12, x22, x12
 748:	531d72f6 	lsl	w22, w23, #3
 74c:	9ad622b5 	lsl	x21, x21, x22
 750:	ca15018c 	eor	x12, x12, x21
 754:	91000529 	add	x9, x9, #0x1
 758:	9100116b 	add	x11, x11, #0x4
 75c:	f101013f 	cmp	x9, #0x40
 760:	540010c0 	b.eq	978 <tracee_syscall_name_table_lookup_xdp+0x398>  // b.none
 764:	385fd175 	ldurb	w21, [x11, #-3]
 768:	385fe176 	ldurb	w22, [x11, #-2]
 76c:	2a1622b6 	orr	w22, w21, w22, lsl #8
 770:	385ff177 	ldurb	w23, [x11, #-1]
 774:	39400178 	ldrb	w24, [x11]
 778:	2a1742d6 	orr	w22, w22, w23, lsl #16
 77c:	2a1862d6 	orr	w22, w22, w24, lsl #24
 780:	71013edf 	cmp	w22, #0x4f
 784:	540001ec 	b.gt	7c0 <tracee_syscall_name_table_lookup_xdp+0x1e0>
 788:	71009adf 	cmp	w22, #0x26
 78c:	540003ac 	b.gt	800 <tracee_syscall_name_table_lookup_xdp+0x220>
 790:	71000adf 	cmp	w22, #0x2
 794:	540005ec 	b.gt	850 <tracee_syscall_name_table_lookup_xdp+0x270>
 798:	34000c16 	cbz	w22, 918 <tracee_syscall_name_table_lookup_xdp+0x338>
 79c:	710006df 	cmp	w22, #0x1
 7a0:	540009c0 	b.eq	8d8 <tracee_syscall_name_table_lookup_xdp+0x2f8>  // b.none
 7a4:	71000adf 	cmp	w22, #0x2
 7a8:	54000dc1 	b.ne	960 <tracee_syscall_name_table_lookup_xdp+0x380>  // b.any
 7ac:	528e0df7 	mov	w23, #0x706f                	// #28783
 7b0:	72adccb7 	movk	w23, #0x6e65, lsl #16
 7b4:	17ffffdd 	b	728 <tracee_syscall_name_table_lookup_xdp+0x148>
 7b8:	d503201f 	nop
 7bc:	d503201f 	nop
 7c0:	710402df 	cmp	w22, #0x100
 7c4:	5400032c 	b.gt	828 <tracee_syscall_name_table_lookup_xdp+0x248>
 7c8:	710276df 	cmp	w22, #0x9d
 7cc:	5400054c 	b.gt	874 <tracee_syscall_name_table_lookup_xdp+0x294>
 7d0:	710142df 	cmp	w22, #0x50
 7d4:	54000a80 	b.eq	924 <tracee_syscall_name_table_lookup_xdp+0x344>  // b.none
 7d8:	71015edf 	cmp	w22, #0x57
 7dc:	54000820 	b.eq	8e0 <tracee_syscall_name_table_lookup_xdp+0x300>  // b.none
 7e0:	710166df 	cmp	w22, #0x59
 7e4:	54000be1 	b.ne	960 <tracee_syscall_name_table_lookup_xdp+0x380>  // b.any
 7e8:	aa0203f7 	mov	x23, x2
 7ec:	17ffffcf 	b	728 <tracee_syscall_name_table_lookup_xdp+0x148>
 7f0:	d503201f 	nop
 7f4:	d503201f 	nop
 7f8:	d503201f 	nop
 7fc:	d503201f 	nop
 800:	7100eadf 	cmp	w22, #0x3a
 804:	5400048c 	b.gt	894 <tracee_syscall_name_table_lookup_xdp+0x2b4>
 808:	71009edf 	cmp	w22, #0x27
 80c:	54000920 	b.eq	930 <tracee_syscall_name_table_lookup_xdp+0x350>  // b.none
 810:	7100e2df 	cmp	w22, #0x38
 814:	540006a0 	b.eq	8e8 <tracee_syscall_name_table_lookup_xdp+0x308>  // b.none
 818:	7100e6df 	cmp	w22, #0x39
 81c:	54000a21 	b.ne	960 <tracee_syscall_name_table_lookup_xdp+0x380>  // b.any
 820:	9133ed57 	add	x23, x10, #0xcfb
 824:	17ffffc1 	b	728 <tracee_syscall_name_table_lookup_xdp+0x148>
 828:	71048adf 	cmp	w22, #0x122
 82c:	5400044c 	b.gt	8b4 <tracee_syscall_name_table_lookup_xdp+0x2d4>
 830:	710406df 	cmp	w22, #0x101
 834:	54000820 	b.eq	938 <tracee_syscall_name_table_lookup_xdp+0x358>  // b.none
 838:	71041edf 	cmp	w22, #0x107
 83c:	540005a0 	b.eq	8f0 <tracee_syscall_name_table_lookup_xdp+0x310>  // b.none
 840:	710466df 	cmp	w22, #0x119
 844:	540008e1 	b.ne	960 <tracee_syscall_name_table_lookup_xdp+0x380>  // b.any
 848:	aa1303f7 	mov	x23, x19
 84c:	17ffffb7 	b	728 <tracee_syscall_name_table_lookup_xdp+0x148>
 850:	71000edf 	cmp	w22, #0x3
 854:	54000760 	b.eq	940 <tracee_syscall_name_table_lookup_xdp+0x360>  // b.none
 858:	710026df 	cmp	w22, #0x9
 85c:	540004e0 	b.eq	8f8 <tracee_syscall_name_table_lookup_xdp+0x318>  // b.none
 860:	528c4d77 	mov	w23, #0x626b                	// #25195
 864:	710032df 	cmp	w22, #0xc
 868:	72ad6e57 	movk	w23, #0x6b72, lsl #16
 86c:	54fff5e0 	b.eq	728 <tracee_syscall_name_table_lookup_xdp+0x148>  // b.none
 870:	1400003c 	b	960 <tracee_syscall_name_table_lookup_xdp+0x380>
 874:	71027adf 	cmp	w22, #0x9e
 878:	54000680 	b.eq	948 <tracee_syscall_name_table_lookup_xdp+0x368>  // b.none
 87c:	71032adf 	cmp	w22, #0xca
 880:	54000420 	b.eq	904 <tracee_syscall_name_table_lookup_xdp+0x324>  // b.none
 884:	710366df 	cmp	w22, #0xd9
 888:	540006c1 	b.ne	960 <tracee_syscall_name_table_lookup_xdp+0x380>  // b.any
 88c:	aa0503f7 	mov	x23, x5
 890:	17ffffa6 	b	728 <tracee_syscall_name_table_lookup_xdp+0x148>
 894:	7100eedf 	cmp	w22, #0x3b
 898:	540005c0 	b.eq	950 <tracee_syscall_name_table_lookup_xdp+0x370>  // b.none
 89c:	7100f2df 	cmp	w22, #0x3c
 8a0:	54000360 	b.eq	90c <tracee_syscall_name_table_lookup_xdp+0x32c>  // b.none
 8a4:	7100f6df 	cmp	w22, #0x3d
 8a8:	540005c1 	b.ne	960 <tracee_syscall_name_table_lookup_xdp+0x380>  // b.any
 8ac:	aa1203f7 	mov	x23, x18
 8b0:	17ffff9e 	b	728 <tracee_syscall_name_table_lookup_xdp+0x148>
 8b4:	71048edf 	cmp	w22, #0x123
 8b8:	54000500 	b.eq	958 <tracee_syscall_name_table_lookup_xdp+0x378>  // b.none
 8bc:	710506df 	cmp	w22, #0x141
 8c0:	54fff300 	b.eq	720 <tracee_syscall_name_table_lookup_xdp+0x140>  // b.none
 8c4:	710532df 	cmp	w22, #0x14c
 8c8:	540004c1 	b.ne	960 <tracee_syscall_name_table_lookup_xdp+0x380>  // b.any
 8cc:	528c2e77 	mov	w23, #0x6173                	// #24947
 8d0:	72af0e97 	movk	w23, #0x7874, lsl #16
 8d4:	17ffff95 	b	728 <tracee_syscall_name_table_lookup_xdp+0x148>
 8d8:	aa0d03f7 	mov	x23, x13
 8dc:	17ffff93 	b	728 <tracee_syscall_name_table_lookup_xdp+0x148>
 8e0:	aa0103f7 	mov	x23, x1
 8e4:	17ffff91 	b	728 <tracee_syscall_name_table_lookup_xdp+0x148>
 8e8:	aa1003f7 	mov	x23, x16
 8ec:	17ffff8f 	b	728 <tracee_syscall_name_table_lookup_xdp+0x148>
 8f0:	aa0703f7 	mov	x23, x7
 8f4:	17ffff8d 	b	728 <tracee_syscall_name_table_lookup_xdp+0x148>
 8f8:	528dadb7 	mov	w23, #0x6d6d                	// #28013
 8fc:	72ae0c37 	movk	w23, #0x7061, lsl #16
 900:	17ffff8a 	b	728 <tracee_syscall_name_table_lookup_xdp+0x148>
 904:	aa0403f7 	mov	x23, x4
 908:	17ffff88 	b	728 <tracee_syscall_name_table_lookup_xdp+0x148>
 90c:	528f0cb7 	mov	w23, #0x7865                	// #30821
 910:	72ae8d37 	movk	w23, #0x7469, lsl #16
 914:	17ffff85 	b	728 <tracee_syscall_name_table_lookup_xdp+0x148>
 918:	528c2c97 	mov	w23, #0x6164                	// #24932
 91c:	72ae4cb7 	movk	w23, #0x7265, lsl #16
 920:	17ffff82 	b	728 <tracee_syscall_name_table_lookup_xdp+0x148>
 924:	528d0c77 	mov	w23, #0x6863                	// #26723
 928:	72ad2c97 	movk	w23, #0x6964, lsl #16
 92c:	17ffff7f 	b	728 <tracee_syscall_name_table_lookup_xdp+0x148>
 930:	aa0f03f7 	mov	x23, x15
 934:	17ffff7d 	b	728 <tracee_syscall_name_table_lookup_xdp+0x148>
 938:	aa0603f7 	mov	x23, x6
 93c:	17ffff7b 	b	728 <tracee_syscall_name_table_lookup_xdp+0x148>
 940:	aa0e03f7 	mov	x23, x14
 944:	17ffff79 	b	728 <tracee_syscall_name_table_lookup_xdp+0x148>
 948:	aa0303f7 	mov	x23, x3
 94c:	17ffff77 	b	728 <tracee_syscall_name_table_lookup_xdp+0x148>
 950:	aa1103f7 	mov	x23, x17
 954:	17ffff75 	b	728 <tracee_syscall_name_table_lookup_xdp+0x148>
 958:	aa1403f7 	mov	x23, x20
 95c:	17ffff73 	b	728 <tracee_syscall_name_table_lookup_xdp+0x148>
 960:	9b007ed5 	mul	x21, x22, x0
 964:	ca0c02ac 	eor	x12, x21, x12
 968:	91000529 	add	x9, x9, #0x1
 96c:	9100116b 	add	x11, x11, #0x4
 970:	f101013f 	cmp	x9, #0x40
 974:	54ffef81 	b.ne	764 <tracee_syscall_name_table_lookup_xdp+0x184>  // b.any
 978:	a9434ff4 	ldp	x20, x19, [sp, #48]
 97c:	52800040 	mov	w0, #0x2                   	// #2
 980:	f900010c 	str	x12, [x8]
 984:	a94257f6 	ldp	x22, x21, [sp, #32]
 988:	a9415ff8 	ldp	x24, x23, [sp, #16]
 98c:	f84407f9 	ldr	x25, [sp], #64
 990:	d65f03c0 	ret

Disassembly of section .fini:

0000000000000994 <_fini>:
 994:	d503201f 	nop
 998:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 99c:	910003fd 	mov	x29, sp
 9a0:	a8c17bfd 	ldp	x29, x30, [sp], #16
 9a4:	d65f03c0 	ret
```

## Original Kernel JIT ASM
```asm
not captured
```

## llvmbpf JIT ASM
```asm
not captured
```
