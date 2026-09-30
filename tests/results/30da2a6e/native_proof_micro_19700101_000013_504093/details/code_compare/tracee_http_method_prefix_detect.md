# tracee_http_method_prefix_detect

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
 494:	f00000f0 	adrp	x16, 1f000 <__FRAME_END__+0x1e698>
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
 4e0:	f00000e0 	adrp	x0, 1f000 <__FRAME_END__+0x1e698>
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
 518:	f00000e1 	adrp	x1, 1f000 <__FRAME_END__+0x1e698>
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
 554:	f00000e2 	adrp	x2, 1f000 <__FRAME_END__+0x1e698>
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
 58c:	f00000e0 	adrp	x0, 1f000 <__FRAME_END__+0x1e698>
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

00000000000005e0 <tracee_http_method_prefix_detect_xdp>:
 5e0:	a9402808 	ldp	x8, x10, [x0]
 5e4:	aa0803e9 	mov	x9, x8
 5e8:	eb0a013f 	cmp	x9, x10
 5ec:	54000148 	b.hi	614 <tracee_http_method_prefix_detect_xdp+0x34>  // b.pmore
 5f0:	9100212b 	add	x11, x9, #0x8
 5f4:	9102412c 	add	x12, x9, #0x90
 5f8:	eb0a017f 	cmp	x11, x10
 5fc:	fa4a9182 	ccmp	x12, x10, #0x2, ls	// ls = plast
 600:	540000a8 	b.hi	614 <tracee_http_method_prefix_detect_xdp+0x34>  // b.pmore
 604:	29412d2a 	ldp	w10, w11, [x9, #8]
 608:	7100215f 	cmp	w10, #0x8
 60c:	7a500960 	ccmp	w11, #0x10, #0x0, eq	// eq = none
 610:	54000060 	b.eq	61c <tracee_http_method_prefix_detect_xdp+0x3c>  // b.none
 614:	2a1f03e0 	mov	w0, wzr
 618:	d65f03c0 	ret
 61c:	9100592a 	add	x10, x9, #0x16
 620:	d28c85e9 	mov	x9, #0x642f                	// #25647
 624:	5280002b 	mov	w11, #0x1                   	// #1
 628:	f2af17a9 	movk	x9, #0x78bd, lsl #16
 62c:	f2c3ac89 	movk	x9, #0x1d64, lsl #32
 630:	f2f40ec9 	movk	x9, #0xa076, lsl #48
 634:	d503201f 	nop
 638:	d503201f 	nop
 63c:	d503201f 	nop
 640:	385fa14c 	ldurb	w12, [x10, #-6]
 644:	385fb14d 	ldurb	w13, [x10, #-5]
 648:	71011d9f 	cmp	w12, #0x47
 64c:	540002ac 	b.gt	6a0 <tracee_http_method_prefix_detect_xdp+0xc0>
 650:	7101119f 	cmp	w12, #0x44
 654:	54000520 	b.eq	6f8 <tracee_http_method_prefix_detect_xdp+0x118>  // b.none
 658:	71011d9f 	cmp	w12, #0x47
 65c:	54000e21 	b.ne	820 <tracee_http_method_prefix_detect_xdp+0x240>  // b.any
 660:	710115bf 	cmp	w13, #0x45
 664:	54000de1 	b.ne	820 <tracee_http_method_prefix_detect_xdp+0x240>  // b.any
 668:	385fc14d 	ldurb	w13, [x10, #-4]
 66c:	710151bf 	cmp	w13, #0x54
 670:	54000941 	b.ne	798 <tracee_http_method_prefix_detect_xdp+0x1b8>  // b.any
 674:	385fd14e 	ldurb	w14, [x10, #-3]
 678:	528008ad 	mov	w13, #0x45                  	// #69
 67c:	710081df 	cmp	w14, #0x20
 680:	54000c21 	b.ne	804 <tracee_http_method_prefix_detect_xdp+0x224>  // b.any
 684:	5280040e 	mov	w14, #0x20                  	// #32
 688:	52800a8f 	mov	w15, #0x54                  	// #84
 68c:	52800030 	mov	w16, #0x1                   	// #1
 690:	14000067 	b	82c <tracee_http_method_prefix_detect_xdp+0x24c>
 694:	d503201f 	nop
 698:	d503201f 	nop
 69c:	d503201f 	nop
 6a0:	7101219f 	cmp	w12, #0x48
 6a4:	54000560 	b.eq	750 <tracee_http_method_prefix_detect_xdp+0x170>  // b.none
 6a8:	7101419f 	cmp	w12, #0x50
 6ac:	54000ba1 	b.ne	820 <tracee_http_method_prefix_detect_xdp+0x240>  // b.any
 6b0:	710155bf 	cmp	w13, #0x55
 6b4:	54000760 	b.eq	7a0 <tracee_http_method_prefix_detect_xdp+0x1c0>  // b.none
 6b8:	71013dbf 	cmp	w13, #0x4f
 6bc:	54000b21 	b.ne	820 <tracee_http_method_prefix_detect_xdp+0x240>  // b.any
 6c0:	385fc14d 	ldurb	w13, [x10, #-4]
 6c4:	71014dbf 	cmp	w13, #0x53
 6c8:	54000a01 	b.ne	808 <tracee_http_method_prefix_detect_xdp+0x228>  // b.any
 6cc:	385fd14d 	ldurb	w13, [x10, #-3]
 6d0:	710151bf 	cmp	w13, #0x54
 6d4:	540009a1 	b.ne	808 <tracee_http_method_prefix_detect_xdp+0x228>  // b.any
 6d8:	385fe14e 	ldurb	w14, [x10, #-2]
 6dc:	528009ed 	mov	w13, #0x4f                  	// #79
 6e0:	710081df 	cmp	w14, #0x20
 6e4:	54000901 	b.ne	804 <tracee_http_method_prefix_detect_xdp+0x224>  // b.any
 6e8:	52800a8e 	mov	w14, #0x54                  	// #84
 6ec:	52800a6f 	mov	w15, #0x53                  	// #83
 6f0:	52800050 	mov	w16, #0x2                   	// #2
 6f4:	1400004e 	b	82c <tracee_http_method_prefix_detect_xdp+0x24c>
 6f8:	710115bf 	cmp	w13, #0x45
 6fc:	54000921 	b.ne	820 <tracee_http_method_prefix_detect_xdp+0x240>  // b.any
 700:	385fc14d 	ldurb	w13, [x10, #-4]
 704:	710131bf 	cmp	w13, #0x4c
 708:	54000481 	b.ne	798 <tracee_http_method_prefix_detect_xdp+0x1b8>  // b.any
 70c:	385fd14d 	ldurb	w13, [x10, #-3]
 710:	710115bf 	cmp	w13, #0x45
 714:	54000421 	b.ne	798 <tracee_http_method_prefix_detect_xdp+0x1b8>  // b.any
 718:	385fe14d 	ldurb	w13, [x10, #-2]
 71c:	710151bf 	cmp	w13, #0x54
 720:	540003c1 	b.ne	798 <tracee_http_method_prefix_detect_xdp+0x1b8>  // b.any
 724:	385ff14d 	ldurb	w13, [x10, #-1]
 728:	710115bf 	cmp	w13, #0x45
 72c:	54000361 	b.ne	798 <tracee_http_method_prefix_detect_xdp+0x1b8>  // b.any
 730:	3940014e 	ldrb	w14, [x10]
 734:	528008ad 	mov	w13, #0x45                  	// #69
 738:	710081df 	cmp	w14, #0x20
 73c:	54000641 	b.ne	804 <tracee_http_method_prefix_detect_xdp+0x224>  // b.any
 740:	528008ae 	mov	w14, #0x45                  	// #69
 744:	5280098f 	mov	w15, #0x4c                  	// #76
 748:	52800090 	mov	w16, #0x4                   	// #4
 74c:	14000038 	b	82c <tracee_http_method_prefix_detect_xdp+0x24c>
 750:	710151bf 	cmp	w13, #0x54
 754:	540003c0 	b.eq	7cc <tracee_http_method_prefix_detect_xdp+0x1ec>  // b.none
 758:	710115bf 	cmp	w13, #0x45
 75c:	54000621 	b.ne	820 <tracee_http_method_prefix_detect_xdp+0x240>  // b.any
 760:	385fc14d 	ldurb	w13, [x10, #-4]
 764:	710105bf 	cmp	w13, #0x41
 768:	54000181 	b.ne	798 <tracee_http_method_prefix_detect_xdp+0x1b8>  // b.any
 76c:	385fd14d 	ldurb	w13, [x10, #-3]
 770:	710111bf 	cmp	w13, #0x44
 774:	54000121 	b.ne	798 <tracee_http_method_prefix_detect_xdp+0x1b8>  // b.any
 778:	385fe14e 	ldurb	w14, [x10, #-2]
 77c:	528008ad 	mov	w13, #0x45                  	// #69
 780:	710081df 	cmp	w14, #0x20
 784:	54000401 	b.ne	804 <tracee_http_method_prefix_detect_xdp+0x224>  // b.any
 788:	5280088e 	mov	w14, #0x44                  	// #68
 78c:	5280082f 	mov	w15, #0x41                  	// #65
 790:	528000b0 	mov	w16, #0x5                   	// #5
 794:	14000026 	b	82c <tracee_http_method_prefix_detect_xdp+0x24c>
 798:	528008ad 	mov	w13, #0x45                  	// #69
 79c:	14000021 	b	820 <tracee_http_method_prefix_detect_xdp+0x240>
 7a0:	385fc14d 	ldurb	w13, [x10, #-4]
 7a4:	710151bf 	cmp	w13, #0x54
 7a8:	54000381 	b.ne	818 <tracee_http_method_prefix_detect_xdp+0x238>  // b.any
 7ac:	385fd14e 	ldurb	w14, [x10, #-3]
 7b0:	52800aad 	mov	w13, #0x55                  	// #85
 7b4:	710081df 	cmp	w14, #0x20
 7b8:	54000261 	b.ne	804 <tracee_http_method_prefix_detect_xdp+0x224>  // b.any
 7bc:	5280040e 	mov	w14, #0x20                  	// #32
 7c0:	52800a8f 	mov	w15, #0x54                  	// #84
 7c4:	52800070 	mov	w16, #0x3                   	// #3
 7c8:	14000019 	b	82c <tracee_http_method_prefix_detect_xdp+0x24c>
 7cc:	385fc14d 	ldurb	w13, [x10, #-4]
 7d0:	710151bf 	cmp	w13, #0x54
 7d4:	540001e1 	b.ne	810 <tracee_http_method_prefix_detect_xdp+0x230>  // b.any
 7d8:	385fd14d 	ldurb	w13, [x10, #-3]
 7dc:	710141bf 	cmp	w13, #0x50
 7e0:	54000181 	b.ne	810 <tracee_http_method_prefix_detect_xdp+0x230>  // b.any
 7e4:	385fe14e 	ldurb	w14, [x10, #-2]
 7e8:	52800a8d 	mov	w13, #0x54                  	// #84
 7ec:	7100bddf 	cmp	w14, #0x2f
 7f0:	54000181 	b.ne	820 <tracee_http_method_prefix_detect_xdp+0x240>  // b.any
 7f4:	52800a0e 	mov	w14, #0x50                  	// #80
 7f8:	52800a8f 	mov	w15, #0x54                  	// #84
 7fc:	528000d0 	mov	w16, #0x6                   	// #6
 800:	1400000b 	b	82c <tracee_http_method_prefix_detect_xdp+0x24c>
 804:	14000007 	b	820 <tracee_http_method_prefix_detect_xdp+0x240>
 808:	528009ed 	mov	w13, #0x4f                  	// #79
 80c:	14000005 	b	820 <tracee_http_method_prefix_detect_xdp+0x240>
 810:	52800a8d 	mov	w13, #0x54                  	// #84
 814:	14000003 	b	820 <tracee_http_method_prefix_detect_xdp+0x240>
 818:	52800aad 	mov	w13, #0x55                  	// #85
 81c:	d503201f 	nop
 820:	385fc14f 	ldurb	w15, [x10, #-4]
 824:	385fd14e 	ldurb	w14, [x10, #-3]
 828:	aa1f03f0 	mov	x16, xzr
 82c:	2a0d03f1 	mov	w17, w13
 830:	9100296d 	add	x13, x11, #0xa
 834:	9100414a 	add	x10, x10, #0x10
 838:	9b1035ad 	madd	x13, x13, x16, x13
 83c:	8b0d012d 	add	x13, x9, x13
 840:	d378dd89 	lsl	x9, x12, #8
 844:	aa114129 	orr	x9, x9, x17, lsl #16
 848:	aa0f6129 	orr	x9, x9, x15, lsl #24
 84c:	aa0e8129 	orr	x9, x9, x14, lsl #32
 850:	aa100129 	orr	x9, x9, x16
 854:	9acb2129 	lsl	x9, x9, x11
 858:	9100056b 	add	x11, x11, #0x1
 85c:	ca0d0129 	eor	x9, x9, x13
 860:	f100257f 	cmp	x11, #0x9
 864:	54ffeee1 	b.ne	640 <tracee_http_method_prefix_detect_xdp+0x60>  // b.any
 868:	d348fd2a 	lsr	x10, x9, #8
 86c:	52800040 	mov	w0, #0x2                   	// #2
 870:	3900010d 	strb	w13, [x8]
 874:	3900050a 	strb	w10, [x8, #1]
 878:	d350fd2a 	lsr	x10, x9, #16
 87c:	3900090a 	strb	w10, [x8, #2]
 880:	d358fd2a 	lsr	x10, x9, #24
 884:	39000d0a 	strb	w10, [x8, #3]
 888:	d360fd2a 	lsr	x10, x9, #32
 88c:	3900110a 	strb	w10, [x8, #4]
 890:	d368fd2a 	lsr	x10, x9, #40
 894:	3900150a 	strb	w10, [x8, #5]
 898:	d370fd2a 	lsr	x10, x9, #48
 89c:	d378fd29 	lsr	x9, x9, #56
 8a0:	3900190a 	strb	w10, [x8, #6]
 8a4:	39001d09 	strb	w9, [x8, #7]
 8a8:	d65f03c0 	ret

Disassembly of section .fini:

00000000000008ac <_fini>:
 8ac:	d503201f 	nop
 8b0:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 8b4:	910003fd 	mov	x29, sp
 8b8:	a8c17bfd 	ldp	x29, x30, [sp], #16
 8bc:	d65f03c0 	ret
```

## Original Kernel JIT ASM
```asm
not captured
```

## llvmbpf JIT ASM
```asm
not captured
```
