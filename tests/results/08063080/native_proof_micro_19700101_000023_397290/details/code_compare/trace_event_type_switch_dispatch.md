# trace_event_type_switch_dispatch

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
 494:	f00000f0 	adrp	x16, 1f000 <__FRAME_END__+0x1e3b0>
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
 4e0:	f00000e0 	adrp	x0, 1f000 <__FRAME_END__+0x1e3b0>
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
 518:	f00000e1 	adrp	x1, 1f000 <__FRAME_END__+0x1e3b0>
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
 554:	f00000e2 	adrp	x2, 1f000 <__FRAME_END__+0x1e3b0>
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
 58c:	f00000e0 	adrp	x0, 1f000 <__FRAME_END__+0x1e3b0>
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

00000000000005e0 <trace_event_type_switch_dispatch_xdp>:
 5e0:	a9402808 	ldp	x8, x10, [x0]
 5e4:	aa0803e9 	mov	x9, x8
 5e8:	eb0a013f 	cmp	x9, x10
 5ec:	54000188 	b.hi	61c <trace_event_type_switch_dispatch_xdp+0x3c>  // b.pmore
 5f0:	9100212b 	add	x11, x9, #0x8
 5f4:	9108312c 	add	x12, x9, #0x20c
 5f8:	eb0a017f 	cmp	x11, x10
 5fc:	fa4a9182 	ccmp	x12, x10, #0x2, ls	// ls = plast
 600:	540000e8 	b.hi	61c <trace_event_type_switch_dispatch_xdp+0x3c>  // b.pmore
 604:	b940016a 	ldr	w10, [x11]
 608:	7102015f 	cmp	w10, #0x80
 60c:	54000081 	b.ne	61c <trace_event_type_switch_dispatch_xdp+0x3c>  // b.any
 610:	aa1f03eb 	mov	x11, xzr
 614:	aa1f03ec 	mov	x12, xzr
 618:	14000008 	b	638 <trace_event_type_switch_dispatch_xdp+0x58>
 61c:	2a1f03e0 	mov	w0, wzr
 620:	d65f03c0 	ret
 624:	5280018c 	mov	w12, #0xc                   	// #12
 628:	9100116b 	add	x11, x11, #0x4
 62c:	ca0a018c 	eor	x12, x12, x10
 630:	f108017f 	cmp	x11, #0x200
 634:	54002900 	b.eq	b54 <trace_event_type_switch_dispatch_xdp+0x574>  // b.none
 638:	aa0c03ea 	mov	x10, x12
 63c:	8b0b012c 	add	x12, x9, x11
 640:	b9400d8c 	ldr	w12, [x12, #12]
 644:	71007d9f 	cmp	w12, #0x1f
 648:	540001cc 	b.gt	680 <trace_event_type_switch_dispatch_xdp+0xa0>
 64c:	71003d9f 	cmp	w12, #0xf
 650:	5400038c 	b.gt	6c0 <trace_event_type_switch_dispatch_xdp+0xe0>
 654:	71001d9f 	cmp	w12, #0x7
 658:	540006cc 	b.gt	730 <trace_event_type_switch_dispatch_xdp+0x150>
 65c:	71000d9f 	cmp	w12, #0x3
 660:	54000b8c 	b.gt	7d0 <trace_event_type_switch_dispatch_xdp+0x1f0>
 664:	7100059f 	cmp	w12, #0x1
 668:	5400134c 	b.gt	8d0 <trace_event_type_switch_dispatch_xdp+0x2f0>
 66c:	34001f2c 	cbz	w12, a50 <trace_event_type_switch_dispatch_xdp+0x470>
 670:	7100059f 	cmp	w12, #0x1
 674:	540026a1 	b.ne	b48 <trace_event_type_switch_dispatch_xdp+0x568>  // b.any
 678:	5280056c 	mov	w12, #0x2b                  	// #43
 67c:	17ffffeb 	b	628 <trace_event_type_switch_dispatch_xdp+0x48>
 680:	7100bd9f 	cmp	w12, #0x2f
 684:	540003ec 	b.gt	700 <trace_event_type_switch_dispatch_xdp+0x120>
 688:	71009d9f 	cmp	w12, #0x27
 68c:	5400066c 	b.gt	758 <trace_event_type_switch_dispatch_xdp+0x178>
 690:	71008d9f 	cmp	w12, #0x23
 694:	54000aec 	b.gt	7f0 <trace_event_type_switch_dispatch_xdp+0x210>
 698:	7100859f 	cmp	w12, #0x21
 69c:	5400126c 	b.gt	8e8 <trace_event_type_switch_dispatch_xdp+0x308>
 6a0:	7100819f 	cmp	w12, #0x20
 6a4:	54001da0 	b.eq	a58 <trace_event_type_switch_dispatch_xdp+0x478>  // b.none
 6a8:	7100859f 	cmp	w12, #0x21
 6ac:	540024e1 	b.ne	b48 <trace_event_type_switch_dispatch_xdp+0x568>  // b.any
 6b0:	528004ec 	mov	w12, #0x27                  	// #39
 6b4:	17ffffdd 	b	628 <trace_event_type_switch_dispatch_xdp+0x48>
 6b8:	d503201f 	nop
 6bc:	d503201f 	nop
 6c0:	71005d9f 	cmp	w12, #0x17
 6c4:	540005ec 	b.gt	780 <trace_event_type_switch_dispatch_xdp+0x1a0>
 6c8:	71004d9f 	cmp	w12, #0x13
 6cc:	54000a2c 	b.gt	810 <trace_event_type_switch_dispatch_xdp+0x230>
 6d0:	7100459f 	cmp	w12, #0x11
 6d4:	5400116c 	b.gt	900 <trace_event_type_switch_dispatch_xdp+0x320>
 6d8:	7100419f 	cmp	w12, #0x10
 6dc:	54001c20 	b.eq	a60 <trace_event_type_switch_dispatch_xdp+0x480>  // b.none
 6e0:	7100459f 	cmp	w12, #0x11
 6e4:	54002321 	b.ne	b48 <trace_event_type_switch_dispatch_xdp+0x568>  // b.any
 6e8:	528007cc 	mov	w12, #0x3e                  	// #62
 6ec:	17ffffcf 	b	628 <trace_event_type_switch_dispatch_xdp+0x48>
 6f0:	d503201f 	nop
 6f4:	d503201f 	nop
 6f8:	d503201f 	nop
 6fc:	d503201f 	nop
 700:	7100dd9f 	cmp	w12, #0x37
 704:	5400052c 	b.gt	7a8 <trace_event_type_switch_dispatch_xdp+0x1c8>
 708:	7100cd9f 	cmp	w12, #0x33
 70c:	5400092c 	b.gt	830 <trace_event_type_switch_dispatch_xdp+0x250>
 710:	7100c59f 	cmp	w12, #0x31
 714:	5400102c 	b.gt	918 <trace_event_type_switch_dispatch_xdp+0x338>
 718:	7100c19f 	cmp	w12, #0x30
 71c:	54001a60 	b.eq	a68 <trace_event_type_switch_dispatch_xdp+0x488>  // b.none
 720:	7100c59f 	cmp	w12, #0x31
 724:	54002121 	b.ne	b48 <trace_event_type_switch_dispatch_xdp+0x568>  // b.any
 728:	aa1f03ec 	mov	x12, xzr
 72c:	17ffffbf 	b	628 <trace_event_type_switch_dispatch_xdp+0x48>
 730:	71002d9f 	cmp	w12, #0xb
 734:	540008ec 	b.gt	850 <trace_event_type_switch_dispatch_xdp+0x270>
 738:	7100259f 	cmp	w12, #0x9
 73c:	54000fac 	b.gt	930 <trace_event_type_switch_dispatch_xdp+0x350>
 740:	7100219f 	cmp	w12, #0x8
 744:	54001960 	b.eq	a70 <trace_event_type_switch_dispatch_xdp+0x490>  // b.none
 748:	7100259f 	cmp	w12, #0x9
 74c:	54001fe1 	b.ne	b48 <trace_event_type_switch_dispatch_xdp+0x568>  // b.any
 750:	528007ec 	mov	w12, #0x3f                  	// #63
 754:	17ffffb5 	b	628 <trace_event_type_switch_dispatch_xdp+0x48>
 758:	7100ad9f 	cmp	w12, #0x2b
 75c:	540008ac 	b.gt	870 <trace_event_type_switch_dispatch_xdp+0x290>
 760:	7100a59f 	cmp	w12, #0x29
 764:	54000f2c 	b.gt	948 <trace_event_type_switch_dispatch_xdp+0x368>
 768:	7100a19f 	cmp	w12, #0x28
 76c:	54001860 	b.eq	a78 <trace_event_type_switch_dispatch_xdp+0x498>  // b.none
 770:	7100a59f 	cmp	w12, #0x29
 774:	54001ea1 	b.ne	b48 <trace_event_type_switch_dispatch_xdp+0x568>  // b.any
 778:	5280064c 	mov	w12, #0x32                  	// #50
 77c:	17ffffab 	b	628 <trace_event_type_switch_dispatch_xdp+0x48>
 780:	71006d9f 	cmp	w12, #0x1b
 784:	5400086c 	b.gt	890 <trace_event_type_switch_dispatch_xdp+0x2b0>
 788:	7100659f 	cmp	w12, #0x19
 78c:	54000eac 	b.gt	960 <trace_event_type_switch_dispatch_xdp+0x380>
 790:	7100619f 	cmp	w12, #0x18
 794:	54001760 	b.eq	a80 <trace_event_type_switch_dispatch_xdp+0x4a0>  // b.none
 798:	7100659f 	cmp	w12, #0x19
 79c:	54001d61 	b.ne	b48 <trace_event_type_switch_dispatch_xdp+0x568>  // b.any
 7a0:	5280034c 	mov	w12, #0x1a                  	// #26
 7a4:	17ffffa1 	b	628 <trace_event_type_switch_dispatch_xdp+0x48>
 7a8:	7100ed9f 	cmp	w12, #0x3b
 7ac:	5400082c 	b.gt	8b0 <trace_event_type_switch_dispatch_xdp+0x2d0>
 7b0:	7100e59f 	cmp	w12, #0x39
 7b4:	54000e2c 	b.gt	978 <trace_event_type_switch_dispatch_xdp+0x398>
 7b8:	7100e19f 	cmp	w12, #0x38
 7bc:	54001660 	b.eq	a88 <trace_event_type_switch_dispatch_xdp+0x4a8>  // b.none
 7c0:	7100e59f 	cmp	w12, #0x39
 7c4:	54001c21 	b.ne	b48 <trace_event_type_switch_dispatch_xdp+0x568>  // b.any
 7c8:	528006cc 	mov	w12, #0x36                  	// #54
 7cc:	17ffff97 	b	628 <trace_event_type_switch_dispatch_xdp+0x48>
 7d0:	7100159f 	cmp	w12, #0x5
 7d4:	54000dec 	b.gt	990 <trace_event_type_switch_dispatch_xdp+0x3b0>
 7d8:	7100119f 	cmp	w12, #0x4
 7dc:	540015a0 	b.eq	a90 <trace_event_type_switch_dispatch_xdp+0x4b0>  // b.none
 7e0:	7100159f 	cmp	w12, #0x5
 7e4:	54001b21 	b.ne	b48 <trace_event_type_switch_dispatch_xdp+0x568>  // b.any
 7e8:	528007ac 	mov	w12, #0x3d                  	// #61
 7ec:	17ffff8f 	b	628 <trace_event_type_switch_dispatch_xdp+0x48>
 7f0:	7100959f 	cmp	w12, #0x25
 7f4:	54000dac 	b.gt	9a8 <trace_event_type_switch_dispatch_xdp+0x3c8>
 7f8:	7100919f 	cmp	w12, #0x24
 7fc:	540014e0 	b.eq	a98 <trace_event_type_switch_dispatch_xdp+0x4b8>  // b.none
 800:	7100959f 	cmp	w12, #0x25
 804:	54001a21 	b.ne	b48 <trace_event_type_switch_dispatch_xdp+0x568>  // b.any
 808:	5280008c 	mov	w12, #0x4                   	// #4
 80c:	17ffff87 	b	628 <trace_event_type_switch_dispatch_xdp+0x48>
 810:	7100559f 	cmp	w12, #0x15
 814:	54000d6c 	b.gt	9c0 <trace_event_type_switch_dispatch_xdp+0x3e0>
 818:	7100519f 	cmp	w12, #0x14
 81c:	54001420 	b.eq	aa0 <trace_event_type_switch_dispatch_xdp+0x4c0>  // b.none
 820:	7100559f 	cmp	w12, #0x15
 824:	54001921 	b.ne	b48 <trace_event_type_switch_dispatch_xdp+0x568>  // b.any
 828:	528002ac 	mov	w12, #0x15                  	// #21
 82c:	17ffff7f 	b	628 <trace_event_type_switch_dispatch_xdp+0x48>
 830:	7100d59f 	cmp	w12, #0x35
 834:	54000d2c 	b.gt	9d8 <trace_event_type_switch_dispatch_xdp+0x3f8>
 838:	7100d19f 	cmp	w12, #0x34
 83c:	54001360 	b.eq	aa8 <trace_event_type_switch_dispatch_xdp+0x4c8>  // b.none
 840:	7100d59f 	cmp	w12, #0x35
 844:	54001821 	b.ne	b48 <trace_event_type_switch_dispatch_xdp+0x568>  // b.any
 848:	5280028c 	mov	w12, #0x14                  	// #20
 84c:	17ffff77 	b	628 <trace_event_type_switch_dispatch_xdp+0x48>
 850:	7100359f 	cmp	w12, #0xd
 854:	54000cec 	b.gt	9f0 <trace_event_type_switch_dispatch_xdp+0x410>
 858:	7100319f 	cmp	w12, #0xc
 85c:	540012a0 	b.eq	ab0 <trace_event_type_switch_dispatch_xdp+0x4d0>  // b.none
 860:	7100359f 	cmp	w12, #0xd
 864:	54001721 	b.ne	b48 <trace_event_type_switch_dispatch_xdp+0x568>  // b.any
 868:	5280054c 	mov	w12, #0x2a                  	// #42
 86c:	17ffff6f 	b	628 <trace_event_type_switch_dispatch_xdp+0x48>
 870:	7100b59f 	cmp	w12, #0x2d
 874:	54000cac 	b.gt	a08 <trace_event_type_switch_dispatch_xdp+0x428>
 878:	7100b19f 	cmp	w12, #0x2c
 87c:	540011e0 	b.eq	ab8 <trace_event_type_switch_dispatch_xdp+0x4d8>  // b.none
 880:	7100b59f 	cmp	w12, #0x2d
 884:	54001621 	b.ne	b48 <trace_event_type_switch_dispatch_xdp+0x568>  // b.any
 888:	5280058c 	mov	w12, #0x2c                  	// #44
 88c:	17ffff67 	b	628 <trace_event_type_switch_dispatch_xdp+0x48>
 890:	7100759f 	cmp	w12, #0x1d
 894:	54000c6c 	b.gt	a20 <trace_event_type_switch_dispatch_xdp+0x440>
 898:	7100719f 	cmp	w12, #0x1c
 89c:	54001120 	b.eq	ac0 <trace_event_type_switch_dispatch_xdp+0x4e0>  // b.none
 8a0:	7100759f 	cmp	w12, #0x1d
 8a4:	54001521 	b.ne	b48 <trace_event_type_switch_dispatch_xdp+0x568>  // b.any
 8a8:	528003ec 	mov	w12, #0x1f                  	// #31
 8ac:	17ffff5f 	b	628 <trace_event_type_switch_dispatch_xdp+0x48>
 8b0:	7100f59f 	cmp	w12, #0x3d
 8b4:	54000c2c 	b.gt	a38 <trace_event_type_switch_dispatch_xdp+0x458>
 8b8:	7100f19f 	cmp	w12, #0x3c
 8bc:	54001060 	b.eq	ac8 <trace_event_type_switch_dispatch_xdp+0x4e8>  // b.none
 8c0:	7100f59f 	cmp	w12, #0x3d
 8c4:	54001421 	b.ne	b48 <trace_event_type_switch_dispatch_xdp+0x568>  // b.any
 8c8:	528000ac 	mov	w12, #0x5                   	// #5
 8cc:	17ffff57 	b	628 <trace_event_type_switch_dispatch_xdp+0x48>
 8d0:	7100099f 	cmp	w12, #0x2
 8d4:	54000fe0 	b.eq	ad0 <trace_event_type_switch_dispatch_xdp+0x4f0>  // b.none
 8d8:	71000d9f 	cmp	w12, #0x3
 8dc:	54001361 	b.ne	b48 <trace_event_type_switch_dispatch_xdp+0x568>  // b.any
 8e0:	5280038c 	mov	w12, #0x1c                  	// #28
 8e4:	17ffff51 	b	628 <trace_event_type_switch_dispatch_xdp+0x48>
 8e8:	7100899f 	cmp	w12, #0x22
 8ec:	54000f60 	b.eq	ad8 <trace_event_type_switch_dispatch_xdp+0x4f8>  // b.none
 8f0:	71008d9f 	cmp	w12, #0x23
 8f4:	540012a1 	b.ne	b48 <trace_event_type_switch_dispatch_xdp+0x568>  // b.any
 8f8:	5280036c 	mov	w12, #0x1b                  	// #27
 8fc:	17ffff4b 	b	628 <trace_event_type_switch_dispatch_xdp+0x48>
 900:	7100499f 	cmp	w12, #0x12
 904:	54000ee0 	b.eq	ae0 <trace_event_type_switch_dispatch_xdp+0x500>  // b.none
 908:	71004d9f 	cmp	w12, #0x13
 90c:	540011e1 	b.ne	b48 <trace_event_type_switch_dispatch_xdp+0x568>  // b.any
 910:	528000cc 	mov	w12, #0x6                   	// #6
 914:	17ffff45 	b	628 <trace_event_type_switch_dispatch_xdp+0x48>
 918:	7100c99f 	cmp	w12, #0x32
 91c:	54000e60 	b.eq	ae8 <trace_event_type_switch_dispatch_xdp+0x508>  // b.none
 920:	7100cd9f 	cmp	w12, #0x33
 924:	54001121 	b.ne	b48 <trace_event_type_switch_dispatch_xdp+0x568>  // b.any
 928:	5280006c 	mov	w12, #0x3                   	// #3
 92c:	17ffff3f 	b	628 <trace_event_type_switch_dispatch_xdp+0x48>
 930:	7100299f 	cmp	w12, #0xa
 934:	54000de0 	b.eq	af0 <trace_event_type_switch_dispatch_xdp+0x510>  // b.none
 938:	71002d9f 	cmp	w12, #0xb
 93c:	54001061 	b.ne	b48 <trace_event_type_switch_dispatch_xdp+0x568>  // b.any
 940:	5280048c 	mov	w12, #0x24                  	// #36
 944:	17ffff39 	b	628 <trace_event_type_switch_dispatch_xdp+0x48>
 948:	7100a99f 	cmp	w12, #0x2a
 94c:	54000d60 	b.eq	af8 <trace_event_type_switch_dispatch_xdp+0x518>  // b.none
 950:	7100ad9f 	cmp	w12, #0x2b
 954:	54000fa1 	b.ne	b48 <trace_event_type_switch_dispatch_xdp+0x568>  // b.any
 958:	5280046c 	mov	w12, #0x23                  	// #35
 95c:	17ffff33 	b	628 <trace_event_type_switch_dispatch_xdp+0x48>
 960:	7100699f 	cmp	w12, #0x1a
 964:	54000ce0 	b.eq	b00 <trace_event_type_switch_dispatch_xdp+0x520>  // b.none
 968:	71006d9f 	cmp	w12, #0x1b
 96c:	54000ee1 	b.ne	b48 <trace_event_type_switch_dispatch_xdp+0x568>  // b.any
 970:	5280052c 	mov	w12, #0x29                  	// #41
 974:	17ffff2d 	b	628 <trace_event_type_switch_dispatch_xdp+0x48>
 978:	7100e99f 	cmp	w12, #0x3a
 97c:	54000c60 	b.eq	b08 <trace_event_type_switch_dispatch_xdp+0x528>  // b.none
 980:	7100ed9f 	cmp	w12, #0x3b
 984:	54000e21 	b.ne	b48 <trace_event_type_switch_dispatch_xdp+0x568>  // b.any
 988:	5280020c 	mov	w12, #0x10                  	// #16
 98c:	17ffff27 	b	628 <trace_event_type_switch_dispatch_xdp+0x48>
 990:	7100199f 	cmp	w12, #0x6
 994:	54000be0 	b.eq	b10 <trace_event_type_switch_dispatch_xdp+0x530>  // b.none
 998:	71001d9f 	cmp	w12, #0x7
 99c:	54000d61 	b.ne	b48 <trace_event_type_switch_dispatch_xdp+0x568>  // b.any
 9a0:	5280074c 	mov	w12, #0x3a                  	// #58
 9a4:	17ffff21 	b	628 <trace_event_type_switch_dispatch_xdp+0x48>
 9a8:	7100999f 	cmp	w12, #0x26
 9ac:	54000b60 	b.eq	b18 <trace_event_type_switch_dispatch_xdp+0x538>  // b.none
 9b0:	71009d9f 	cmp	w12, #0x27
 9b4:	54000ca1 	b.ne	b48 <trace_event_type_switch_dispatch_xdp+0x568>  // b.any
 9b8:	5280060c 	mov	w12, #0x30                  	// #48
 9bc:	17ffff1b 	b	628 <trace_event_type_switch_dispatch_xdp+0x48>
 9c0:	7100599f 	cmp	w12, #0x16
 9c4:	54000ae0 	b.eq	b20 <trace_event_type_switch_dispatch_xdp+0x540>  // b.none
 9c8:	71005d9f 	cmp	w12, #0x17
 9cc:	54000be1 	b.ne	b48 <trace_event_type_switch_dispatch_xdp+0x568>  // b.any
 9d0:	5280050c 	mov	w12, #0x28                  	// #40
 9d4:	17ffff15 	b	628 <trace_event_type_switch_dispatch_xdp+0x48>
 9d8:	7100d99f 	cmp	w12, #0x36
 9dc:	54000a60 	b.eq	b28 <trace_event_type_switch_dispatch_xdp+0x548>  // b.none
 9e0:	7100dd9f 	cmp	w12, #0x37
 9e4:	54000b21 	b.ne	b48 <trace_event_type_switch_dispatch_xdp+0x568>  // b.any
 9e8:	5280024c 	mov	w12, #0x12                  	// #18
 9ec:	17ffff0f 	b	628 <trace_event_type_switch_dispatch_xdp+0x48>
 9f0:	7100399f 	cmp	w12, #0xe
 9f4:	540009e0 	b.eq	b30 <trace_event_type_switch_dispatch_xdp+0x550>  // b.none
 9f8:	71003d9f 	cmp	w12, #0xf
 9fc:	54000a61 	b.ne	b48 <trace_event_type_switch_dispatch_xdp+0x568>  // b.any
 a00:	528005cc 	mov	w12, #0x2e                  	// #46
 a04:	17ffff09 	b	628 <trace_event_type_switch_dispatch_xdp+0x48>
 a08:	7100b99f 	cmp	w12, #0x2e
 a0c:	54000960 	b.eq	b38 <trace_event_type_switch_dispatch_xdp+0x558>  // b.none
 a10:	7100bd9f 	cmp	w12, #0x2f
 a14:	540009a1 	b.ne	b48 <trace_event_type_switch_dispatch_xdp+0x568>  // b.any
 a18:	5280076c 	mov	w12, #0x3b                  	// #59
 a1c:	17ffff03 	b	628 <trace_event_type_switch_dispatch_xdp+0x48>
 a20:	7100799f 	cmp	w12, #0x1e
 a24:	540008e0 	b.eq	b40 <trace_event_type_switch_dispatch_xdp+0x560>  // b.none
 a28:	71007d9f 	cmp	w12, #0x1f
 a2c:	540008e1 	b.ne	b48 <trace_event_type_switch_dispatch_xdp+0x568>  // b.any
 a30:	5280068c 	mov	w12, #0x34                  	// #52
 a34:	17fffefd 	b	628 <trace_event_type_switch_dispatch_xdp+0x48>
 a38:	7100f99f 	cmp	w12, #0x3e
 a3c:	54ffdf40 	b.eq	624 <trace_event_type_switch_dispatch_xdp+0x44>  // b.none
 a40:	7100fd9f 	cmp	w12, #0x3f
 a44:	54000821 	b.ne	b48 <trace_event_type_switch_dispatch_xdp+0x568>  // b.any
 a48:	528006ec 	mov	w12, #0x37                  	// #55
 a4c:	17fffef7 	b	628 <trace_event_type_switch_dispatch_xdp+0x48>
 a50:	5280070c 	mov	w12, #0x38                  	// #56
 a54:	17fffef5 	b	628 <trace_event_type_switch_dispatch_xdp+0x48>
 a58:	5280032c 	mov	w12, #0x19                  	// #25
 a5c:	17fffef3 	b	628 <trace_event_type_switch_dispatch_xdp+0x48>
 a60:	5280044c 	mov	w12, #0x22                  	// #34
 a64:	17fffef1 	b	628 <trace_event_type_switch_dispatch_xdp+0x48>
 a68:	528005ac 	mov	w12, #0x2d                  	// #45
 a6c:	17fffeef 	b	628 <trace_event_type_switch_dispatch_xdp+0x48>
 a70:	5280004c 	mov	w12, #0x2                   	// #2
 a74:	17fffeed 	b	628 <trace_event_type_switch_dispatch_xdp+0x48>
 a78:	5280040c 	mov	w12, #0x20                  	// #32
 a7c:	17fffeeb 	b	628 <trace_event_type_switch_dispatch_xdp+0x48>
 a80:	528004cc 	mov	w12, #0x26                  	// #38
 a84:	17fffee9 	b	628 <trace_event_type_switch_dispatch_xdp+0x48>
 a88:	5280002c 	mov	w12, #0x1                   	// #1
 a8c:	17fffee7 	b	628 <trace_event_type_switch_dispatch_xdp+0x48>
 a90:	528001cc 	mov	w12, #0xe                   	// #14
 a94:	17fffee5 	b	628 <trace_event_type_switch_dispatch_xdp+0x48>
 a98:	528006ac 	mov	w12, #0x35                  	// #53
 a9c:	17fffee3 	b	628 <trace_event_type_switch_dispatch_xdp+0x48>
 aa0:	528003ac 	mov	w12, #0x1d                  	// #29
 aa4:	17fffee1 	b	628 <trace_event_type_switch_dispatch_xdp+0x48>
 aa8:	528001ac 	mov	w12, #0xd                   	// #13
 aac:	17fffedf 	b	628 <trace_event_type_switch_dispatch_xdp+0x48>
 ab0:	5280026c 	mov	w12, #0x13                  	// #19
 ab4:	17fffedd 	b	628 <trace_event_type_switch_dispatch_xdp+0x48>
 ab8:	5280010c 	mov	w12, #0x8                   	// #8
 abc:	17fffedb 	b	628 <trace_event_type_switch_dispatch_xdp+0x48>
 ac0:	5280042c 	mov	w12, #0x21                  	// #33
 ac4:	17fffed9 	b	628 <trace_event_type_switch_dispatch_xdp+0x48>
 ac8:	5280078c 	mov	w12, #0x3c                  	// #60
 acc:	17fffed7 	b	628 <trace_event_type_switch_dispatch_xdp+0x48>
 ad0:	5280072c 	mov	w12, #0x39                  	// #57
 ad4:	17fffed5 	b	628 <trace_event_type_switch_dispatch_xdp+0x48>
 ad8:	5280016c 	mov	w12, #0xb                   	// #11
 adc:	17fffed3 	b	628 <trace_event_type_switch_dispatch_xdp+0x48>
 ae0:	528005ec 	mov	w12, #0x2f                  	// #47
 ae4:	17fffed1 	b	628 <trace_event_type_switch_dispatch_xdp+0x48>
 ae8:	5280012c 	mov	w12, #0x9                   	// #9
 aec:	17fffecf 	b	628 <trace_event_type_switch_dispatch_xdp+0x48>
 af0:	5280062c 	mov	w12, #0x31                  	// #49
 af4:	17fffecd 	b	628 <trace_event_type_switch_dispatch_xdp+0x48>
 af8:	528000ec 	mov	w12, #0x7                   	// #7
 afc:	17fffecb 	b	628 <trace_event_type_switch_dispatch_xdp+0x48>
 b00:	5280022c 	mov	w12, #0x11                  	// #17
 b04:	17fffec9 	b	628 <trace_event_type_switch_dispatch_xdp+0x48>
 b08:	528002cc 	mov	w12, #0x16                  	// #22
 b0c:	17fffec7 	b	628 <trace_event_type_switch_dispatch_xdp+0x48>
 b10:	5280014c 	mov	w12, #0xa                   	// #10
 b14:	17fffec5 	b	628 <trace_event_type_switch_dispatch_xdp+0x48>
 b18:	5280030c 	mov	w12, #0x18                  	// #24
 b1c:	17fffec3 	b	628 <trace_event_type_switch_dispatch_xdp+0x48>
 b20:	528001ec 	mov	w12, #0xf                   	// #15
 b24:	17fffec1 	b	628 <trace_event_type_switch_dispatch_xdp+0x48>
 b28:	528003cc 	mov	w12, #0x1e                  	// #30
 b2c:	17fffebf 	b	628 <trace_event_type_switch_dispatch_xdp+0x48>
 b30:	528004ac 	mov	w12, #0x25                  	// #37
 b34:	17fffebd 	b	628 <trace_event_type_switch_dispatch_xdp+0x48>
 b38:	5280066c 	mov	w12, #0x33                  	// #51
 b3c:	17fffebb 	b	628 <trace_event_type_switch_dispatch_xdp+0x48>
 b40:	528002ec 	mov	w12, #0x17                  	// #23
 b44:	17fffeb9 	b	628 <trace_event_type_switch_dispatch_xdp+0x48>
 b48:	5297ea4c 	mov	w12, #0xbf52                	// #48978
 b4c:	72a0002c 	movk	w12, #0x1, lsl #16
 b50:	17fffeb6 	b	628 <trace_event_type_switch_dispatch_xdp+0x48>
 b54:	d348fd89 	lsr	x9, x12, #8
 b58:	d350fd8b 	lsr	x11, x12, #16
 b5c:	52800040 	mov	w0, #0x2                   	// #2
 b60:	3900010c 	strb	w12, [x8]
 b64:	39000509 	strb	w9, [x8, #1]
 b68:	d358fd49 	lsr	x9, x10, #24
 b6c:	3900090b 	strb	w11, [x8, #2]
 b70:	d360fd4b 	lsr	x11, x10, #32
 b74:	39000d09 	strb	w9, [x8, #3]
 b78:	d368fd49 	lsr	x9, x10, #40
 b7c:	3900110b 	strb	w11, [x8, #4]
 b80:	39001509 	strb	w9, [x8, #5]
 b84:	d370fd49 	lsr	x9, x10, #48
 b88:	39001909 	strb	w9, [x8, #6]
 b8c:	d378fd49 	lsr	x9, x10, #56
 b90:	39001d09 	strb	w9, [x8, #7]
 b94:	d65f03c0 	ret

Disassembly of section .fini:

0000000000000b98 <_fini>:
 b98:	d503201f 	nop
 b9c:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 ba0:	910003fd 	mov	x29, sp
 ba4:	a8c17bfd 	ldp	x29, x30, [sp], #16
 ba8:	d65f03c0 	ret
```

## Original Kernel JIT ASM
```asm
not captured
```

## llvmbpf JIT ASM
```asm
not captured
```
