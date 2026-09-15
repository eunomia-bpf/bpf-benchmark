# packet_vlan_tcpopt_parser

## Original C
```c
not captured
```

## Native ASM
```asm
Disassembly of section .init:

0000000000000490 <_init>:
 490:	d503201f 	nop
 494:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 498:	910003fd 	mov	x29, sp
 49c:	94000015 	bl	4f0 <call_weak_fn>
 4a0:	a8c17bfd 	ldp	x29, x30, [sp], #16
 4a4:	d65f03c0 	ret

Disassembly of section .plt:

00000000000004b0 <.plt>:
 4b0:	a9bf7bf0 	stp	x16, x30, [sp, #-16]!
 4b4:	f00000f0 	adrp	x16, 1f000 <__FRAME_END__+0x1e6d8>
 4b8:	f947fe11 	ldr	x17, [x16, #4088]
 4bc:	913fe210 	add	x16, x16, #0xff8
 4c0:	d61f0220 	br	x17
 4c4:	d503201f 	nop
 4c8:	d503201f 	nop
 4cc:	d503201f 	nop

00000000000004d0 <__cxa_finalize@plt>:
 4d0:	90000110 	adrp	x16, 20000 <__cxa_finalize@GLIBC_2.17>
 4d4:	f9400211 	ldr	x17, [x16]
 4d8:	91000210 	add	x16, x16, #0x0
 4dc:	d61f0220 	br	x17

00000000000004e0 <__gmon_start__@plt>:
 4e0:	90000110 	adrp	x16, 20000 <__cxa_finalize@GLIBC_2.17>
 4e4:	f9400611 	ldr	x17, [x16, #8]
 4e8:	91002210 	add	x16, x16, #0x8
 4ec:	d61f0220 	br	x17

Disassembly of section .text:

00000000000004f0 <call_weak_fn>:
 4f0:	f00000e0 	adrp	x0, 1f000 <__FRAME_END__+0x1e6d8>
 4f4:	f947ec00 	ldr	x0, [x0, #4056]
 4f8:	b4000040 	cbz	x0, 500 <call_weak_fn+0x10>
 4fc:	17fffff9 	b	4e0 <__gmon_start__@plt>
 500:	d65f03c0 	ret
 504:	d503201f 	nop
 508:	d503201f 	nop
 50c:	d503201f 	nop

0000000000000510 <deregister_tm_clones>:
 510:	90000100 	adrp	x0, 20000 <__cxa_finalize@GLIBC_2.17>
 514:	91008000 	add	x0, x0, #0x20
 518:	90000101 	adrp	x1, 20000 <__cxa_finalize@GLIBC_2.17>
 51c:	91008021 	add	x1, x1, #0x20
 520:	eb00003f 	cmp	x1, x0
 524:	540000c0 	b.eq	53c <deregister_tm_clones+0x2c>  // b.none
 528:	f00000e1 	adrp	x1, 1f000 <__FRAME_END__+0x1e6d8>
 52c:	f947e421 	ldr	x1, [x1, #4040]
 530:	b4000061 	cbz	x1, 53c <deregister_tm_clones+0x2c>
 534:	aa0103f0 	mov	x16, x1
 538:	d61f0200 	br	x16
 53c:	d65f03c0 	ret

0000000000000540 <register_tm_clones>:
 540:	90000100 	adrp	x0, 20000 <__cxa_finalize@GLIBC_2.17>
 544:	91008000 	add	x0, x0, #0x20
 548:	90000101 	adrp	x1, 20000 <__cxa_finalize@GLIBC_2.17>
 54c:	91008021 	add	x1, x1, #0x20
 550:	cb000021 	sub	x1, x1, x0
 554:	d37ffc22 	lsr	x2, x1, #63
 558:	8b810c41 	add	x1, x2, x1, asr #3
 55c:	9341fc21 	asr	x1, x1, #1
 560:	b40000c1 	cbz	x1, 578 <register_tm_clones+0x38>
 564:	f00000e2 	adrp	x2, 1f000 <__FRAME_END__+0x1e6d8>
 568:	f947f042 	ldr	x2, [x2, #4064]
 56c:	b4000062 	cbz	x2, 578 <register_tm_clones+0x38>
 570:	aa0203f0 	mov	x16, x2
 574:	d61f0200 	br	x16
 578:	d65f03c0 	ret
 57c:	d503201f 	nop

0000000000000580 <__do_global_dtors_aux>:
 580:	d503233f 	paciasp
 584:	a9be7bfd 	stp	x29, x30, [sp, #-32]!
 588:	910003fd 	mov	x29, sp
 58c:	f9000bf3 	str	x19, [sp, #16]
 590:	90000113 	adrp	x19, 20000 <__cxa_finalize@GLIBC_2.17>
 594:	39407260 	ldrb	w0, [x19, #28]
 598:	37000140 	tbnz	w0, #0, 5c0 <__do_global_dtors_aux+0x40>
 59c:	f00000e0 	adrp	x0, 1f000 <__FRAME_END__+0x1e6d8>
 5a0:	f947e800 	ldr	x0, [x0, #4048]
 5a4:	b4000080 	cbz	x0, 5b4 <__do_global_dtors_aux+0x34>
 5a8:	90000100 	adrp	x0, 20000 <__cxa_finalize@GLIBC_2.17>
 5ac:	f9400800 	ldr	x0, [x0, #16]
 5b0:	97ffffc8 	bl	4d0 <__cxa_finalize@plt>
 5b4:	97ffffd7 	bl	510 <deregister_tm_clones>
 5b8:	52800020 	mov	w0, #0x1                   	// #1
 5bc:	39007260 	strb	w0, [x19, #28]
 5c0:	f9400bf3 	ldr	x19, [sp, #16]
 5c4:	a8c27bfd 	ldp	x29, x30, [sp], #32
 5c8:	d50323bf 	autiasp
 5cc:	d65f03c0 	ret

00000000000005d0 <frame_dummy>:
 5d0:	d503245f 	bti	c
 5d4:	17ffffdb 	b	540 <register_tm_clones>
 5d8:	d503201f 	nop
 5dc:	d503201f 	nop

00000000000005e0 <packet_vlan_tcpopt_parser_xdp>:
 5e0:	a9403008 	ldp	x8, x12, [x0]
 5e4:	91002109 	add	x9, x8, #0x8
 5e8:	eb0c011f 	cmp	x8, x12
 5ec:	fa4c9122 	ccmp	x9, x12, #0x2, ls	// ls = plast
 5f0:	54000088 	b.hi	600 <packet_vlan_tcpopt_parser_xdp+0x20>  // b.pmore
 5f4:	9100590b 	add	x11, x8, #0x16
 5f8:	eb0c017f 	cmp	x11, x12
 5fc:	54000069 	b.ls	608 <packet_vlan_tcpopt_parser_xdp+0x28>  // b.plast
 600:	2a1f03e0 	mov	w0, wzr
 604:	d65f03c0 	ret
 608:	79402909 	ldrh	w9, [x8, #20]
 60c:	5ac00529 	rev16	w9, w9
 610:	7120013f 	cmp	w9, #0x800
 614:	540004e0 	b.eq	6b0 <packet_vlan_tcpopt_parser_xdp+0xd0>  // b.none
 618:	5291150a 	mov	w10, #0x88a8                	// #34984
 61c:	2a1f03e0 	mov	w0, wzr
 620:	6b0a013f 	cmp	w9, w10
 624:	5290200a 	mov	w10, #0x8100                	// #33024
 628:	7a4a1124 	ccmp	w9, w10, #0x4, ne	// ne = any
 62c:	54fffec1 	b.ne	604 <packet_vlan_tcpopt_parser_xdp+0x24>  // b.any
 630:	9100690b 	add	x11, x8, #0x1a
 634:	eb0c017f 	cmp	x11, x12
 638:	54fffe48 	b.hi	600 <packet_vlan_tcpopt_parser_xdp+0x20>  // b.pmore
 63c:	79402d09 	ldrh	w9, [x8, #22]
 640:	7940310a 	ldrh	w10, [x8, #24]
 644:	5ac00929 	rev	w9, w9
 648:	5ac0054a 	rev16	w10, w10
 64c:	53107d29 	lsr	w9, w9, #16
 650:	7120015f 	cmp	w10, #0x800
 654:	54001040 	b.eq	85c <packet_vlan_tcpopt_parser_xdp+0x27c>  // b.none
 658:	5291150b 	mov	w11, #0x88a8                	// #34984
 65c:	6b0b015f 	cmp	w10, w11
 660:	54000080 	b.eq	670 <packet_vlan_tcpopt_parser_xdp+0x90>  // b.none
 664:	5290200b 	mov	w11, #0x8100                	// #33024
 668:	6b0b015f 	cmp	w10, w11
 66c:	54fffca1 	b.ne	600 <packet_vlan_tcpopt_parser_xdp+0x20>  // b.any
 670:	9100790a 	add	x10, x8, #0x1e
 674:	eb0c015f 	cmp	x10, x12
 678:	54fffc48 	b.hi	600 <packet_vlan_tcpopt_parser_xdp+0x20>  // b.pmore
 67c:	7940390a 	ldrh	w10, [x8, #28]
 680:	2a1f03e0 	mov	w0, wzr
 684:	5ac0054a 	rev16	w10, w10
 688:	7120015f 	cmp	w10, #0x800
 68c:	54fffbc1 	b.ne	604 <packet_vlan_tcpopt_parser_xdp+0x24>  // b.any
 690:	9100c90a 	add	x10, x8, #0x32
 694:	eb0c015f 	cmp	x10, x12
 698:	54fffb68 	b.hi	604 <packet_vlan_tcpopt_parser_xdp+0x24>  // b.pmore
 69c:	7940350a 	ldrh	w10, [x8, #26]
 6a0:	9100790b 	add	x11, x8, #0x1e
 6a4:	5ac0054d 	rev16	w13, w10
 6a8:	5280004a 	mov	w10, #0x2                   	// #2
 6ac:	14000007 	b	6c8 <packet_vlan_tcpopt_parser_xdp+0xe8>
 6b0:	2a1f03e9 	mov	w9, wzr
 6b4:	2a1f03ea 	mov	w10, wzr
 6b8:	9100516d 	add	x13, x11, #0x14
 6bc:	eb0c01bf 	cmp	x13, x12
 6c0:	54fffa08 	b.hi	600 <packet_vlan_tcpopt_parser_xdp+0x20>  // b.pmore
 6c4:	aa1f03ed 	mov	x13, xzr
 6c8:	3940016e 	ldrb	w14, [x11]
 6cc:	2a1f03e0 	mov	w0, wzr
 6d0:	121c0dcf 	and	w15, w14, #0xf0
 6d4:	710101ff 	cmp	w15, #0x40
 6d8:	54fff961 	b.ne	604 <packet_vlan_tcpopt_parser_xdp+0x24>  // b.any
 6dc:	92400dd0 	and	x16, x14, #0xf
 6e0:	7100161f 	cmp	w16, #0x5
 6e4:	54fff903 	b.cc	604 <packet_vlan_tcpopt_parser_xdp+0x24>  // b.lo, b.ul, b.last
 6e8:	8b10096e 	add	x14, x11, x16, lsl #2
 6ec:	eb0c01df 	cmp	x14, x12
 6f0:	54fff888 	b.hi	600 <packet_vlan_tcpopt_parser_xdp+0x20>  // b.pmore
 6f4:	3940256f 	ldrb	w15, [x11, #9]
 6f8:	710019ff 	cmp	w15, #0x6
 6fc:	54fff821 	b.ne	600 <packet_vlan_tcpopt_parser_xdp+0x20>  // b.any
 700:	910051d1 	add	x17, x14, #0x14
 704:	eb0c023f 	cmp	x17, x12
 708:	54fff7c8 	b.hi	600 <packet_vlan_tcpopt_parser_xdp+0x20>  // b.pmore
 70c:	394031cf 	ldrb	w15, [x14, #12]
 710:	710141ff 	cmp	w15, #0x50
 714:	54fff763 	b.cc	600 <packet_vlan_tcpopt_parser_xdp+0x20>  // b.lo, b.ul, b.last
 718:	d342fdef 	lsr	x15, x15, #2
 71c:	927e0def 	and	x15, x15, #0x3c
 720:	8b0f01d2 	add	x18, x14, x15
 724:	eb0c025f 	cmp	x18, x12
 728:	54fff6c8 	b.hi	600 <packet_vlan_tcpopt_parser_xdp+0x20>  // b.pmore
 72c:	910081d2 	add	x18, x14, #0x20
 730:	2a1f03e0 	mov	w0, wzr
 734:	eb0c025f 	cmp	x18, x12
 738:	54fff668 	b.hi	604 <packet_vlan_tcpopt_parser_xdp+0x24>  // b.pmore
 73c:	710081ff 	cmp	w15, #0x20
 740:	54fff623 	b.cc	604 <packet_vlan_tcpopt_parser_xdp+0x24>  // b.lo, b.ul, b.last
 744:	3940022c 	ldrb	w12, [x17]
 748:	7100099f 	cmp	w12, #0x2
 74c:	54fff5a1 	b.ne	600 <packet_vlan_tcpopt_parser_xdp+0x20>  // b.any
 750:	394055cc 	ldrb	w12, [x14, #21]
 754:	7100119f 	cmp	w12, #0x4
 758:	54fff543 	b.cc	600 <packet_vlan_tcpopt_parser_xdp+0x20>  // b.lo, b.ul, b.last
 75c:	394061cc 	ldrb	w12, [x14, #24]
 760:	7100059f 	cmp	w12, #0x1
 764:	54fff4e1 	b.ne	600 <packet_vlan_tcpopt_parser_xdp+0x20>  // b.any
 768:	394065cc 	ldrb	w12, [x14, #25]
 76c:	71000d9f 	cmp	w12, #0x3
 770:	54fff481 	b.ne	600 <packet_vlan_tcpopt_parser_xdp+0x20>  // b.any
 774:	394069cc 	ldrb	w12, [x14, #26]
 778:	71000d9f 	cmp	w12, #0x3
 77c:	54fff423 	b.cc	600 <packet_vlan_tcpopt_parser_xdp+0x20>  // b.lo, b.ul, b.last
 780:	394071cc 	ldrb	w12, [x14, #28]
 784:	7100119f 	cmp	w12, #0x4
 788:	54fff3c1 	b.ne	600 <packet_vlan_tcpopt_parser_xdp+0x20>  // b.any
 78c:	394075cc 	ldrb	w12, [x14, #29]
 790:	7100099f 	cmp	w12, #0x2
 794:	54fff363 	b.cc	600 <packet_vlan_tcpopt_parser_xdp+0x20>  // b.lo, b.ul, b.last
 798:	394079cc 	ldrb	w12, [x14, #30]
 79c:	7100059f 	cmp	w12, #0x1
 7a0:	54fff301 	b.ne	600 <packet_vlan_tcpopt_parser_xdp+0x20>  // b.any
 7a4:	394059c1 	ldrb	w1, [x14, #22]
 7a8:	39405dc2 	ldrb	w2, [x14, #23]
 7ac:	d37ef60c 	lsl	x12, x16, #2
 7b0:	2a0903e9 	mov	w9, w9
 7b4:	aa0941a9 	orr	x9, x13, x9, lsl #16
 7b8:	79400570 	ldrh	w16, [x11, #2]
 7bc:	794001d2 	ldrh	w18, [x14]
 7c0:	aa012043 	orr	x3, x2, x1, lsl #8
 7c4:	794005c0 	ldrh	w0, [x14, #2]
 7c8:	2941ad71 	ldp	w17, w11, [x11, #12]
 7cc:	d3689c42 	lsl	x2, x2, #24
 7d0:	5ac00610 	rev16	w16, w16
 7d4:	5ac00652 	rev16	w18, w18
 7d8:	5ac00400 	rev16	w0, w0
 7dc:	5ac00a31 	rev	w17, w17
 7e0:	5ac0096b 	rev	w11, w11
 7e4:	91000863 	add	x3, x3, #0x2
 7e8:	8b100250 	add	x16, x18, x16
 7ec:	ca014061 	eor	x1, x3, x1, lsl #16
 7f0:	8b000210 	add	x16, x16, x0
 7f4:	52800040 	mov	w0, #0x2                   	// #2
 7f8:	8b020021 	add	x1, x1, x2
 7fc:	39406dc2 	ldrb	w2, [x14, #27]
 800:	39407dce 	ldrb	w14, [x14, #31]
 804:	ca110210 	eor	x16, x16, x17
 808:	9140c021 	add	x1, x1, #0x30, lsl #12
 80c:	8b0b020b 	add	x11, x16, x11
 810:	91040021 	add	x1, x1, #0x100
 814:	ca090169 	eor	x9, x11, x9
 818:	d378dd8b 	lsl	x11, x12, #8
 81c:	d2c000cc 	mov	x12, #0x600000000           	// #25769803776
 820:	aa0aa16b 	orr	x11, x11, x10, lsl #40
 824:	521d794a 	eor	w10, w10, #0xfffffffb
 828:	ca028021 	eor	x1, x1, x2, lsl #32
 82c:	aa0f016b 	orr	x11, x11, x15
 830:	ca024021 	eor	x1, x1, x2, lsl #16
 834:	8b0c016b 	add	x11, x11, x12
 838:	aa0ea02e 	orr	x14, x1, x14, lsl #40
 83c:	d2a88001 	mov	x1, #0x44000000            	// #1140850688
 840:	8b0b0129 	add	x9, x9, x11
 844:	f2c00021 	movk	x1, #0x1, lsl #32
 848:	8b0101ce 	add	x14, x14, x1
 84c:	9aca2dca 	ror	x10, x14, x10
 850:	ca090149 	eor	x9, x10, x9
 854:	f9000109 	str	x9, [x8]
 858:	d65f03c0 	ret
 85c:	5280002a 	mov	w10, #0x1                   	// #1
 860:	9100516d 	add	x13, x11, #0x14
 864:	eb0c01bf 	cmp	x13, x12
 868:	54ffecc8 	b.hi	600 <packet_vlan_tcpopt_parser_xdp+0x20>  // b.pmore
 86c:	17ffff96 	b	6c4 <packet_vlan_tcpopt_parser_xdp+0xe4>

Disassembly of section .fini:

0000000000000870 <_fini>:
 870:	d503201f 	nop
 874:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 878:	910003fd 	mov	x29, sp
 87c:	a8c17bfd 	ldp	x29, x30, [sp], #16
 880:	d65f03c0 	ret
```

## Original Kernel JIT ASM
```asm
not captured
```

## llvmbpf JIT ASM
```asm
not captured
```
