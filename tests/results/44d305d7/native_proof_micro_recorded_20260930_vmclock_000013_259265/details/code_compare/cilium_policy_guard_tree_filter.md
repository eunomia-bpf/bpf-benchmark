# cilium_policy_guard_tree_filter

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
 494:	f00000f0 	adrp	x16, 1f000 <__FRAME_END__+0x1e7e0>
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
 4e0:	f00000e0 	adrp	x0, 1f000 <__FRAME_END__+0x1e7e0>
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
 518:	f00000e1 	adrp	x1, 1f000 <__FRAME_END__+0x1e7e0>
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
 554:	f00000e2 	adrp	x2, 1f000 <__FRAME_END__+0x1e7e0>
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
 58c:	f00000e0 	adrp	x0, 1f000 <__FRAME_END__+0x1e7e0>
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

00000000000005e0 <cilium_policy_guard_tree_filter_xdp>:
 5e0:	a9402408 	ldp	x8, x9, [x0]
 5e4:	aa0803ea 	mov	x10, x8
 5e8:	eb09015f 	cmp	x10, x9
 5ec:	54000988 	b.hi	71c <cilium_policy_guard_tree_filter_xdp+0x13c>  // b.pmore
 5f0:	9100214b 	add	x11, x10, #0x8
 5f4:	9108314c 	add	x12, x10, #0x20c
 5f8:	eb09017f 	cmp	x11, x9
 5fc:	fa499182 	ccmp	x12, x9, #0x2, ls	// ls = plast
 600:	540008e8 	b.hi	71c <cilium_policy_guard_tree_filter_xdp+0x13c>  // b.pmore
 604:	b9400169 	ldr	w9, [x11]
 608:	7100813f 	cmp	w9, #0x20
 60c:	54000881 	b.ne	71c <cilium_policy_guard_tree_filter_xdp+0x13c>  // b.any
 610:	d2851b6b 	mov	x11, #0x28db                	// #10459
 614:	aa1f03e9 	mov	x9, xzr
 618:	9100354a 	add	x10, x10, #0xd
 61c:	f2b4168b 	movk	x11, #0xa0b4, lsl #16
 620:	f2cfda2b 	movk	x11, #0x7ed1, lsl #32
 624:	f2fce06b 	movk	x11, #0xe703, lsl #48
 628:	1400000d 	b	65c <cilium_policy_guard_tree_filter_xdp+0x7c>
 62c:	ca0d018c 	eor	x12, x12, x13
 630:	8b0b018b 	add	x11, x12, x11
 634:	1200092d 	and	w13, w9, #0x7
 638:	91000529 	add	x9, x9, #0x1
 63c:	9100414a 	add	x10, x10, #0x10
 640:	110005ac 	add	w12, w13, #0x1
 644:	520015ad 	eor	w13, w13, #0x3f
 648:	f100813f 	cmp	x9, #0x20
 64c:	9acc216c 	lsl	x12, x11, x12
 650:	9acd256b 	lsr	x11, x11, x13
 654:	aa0b018b 	orr	x11, x12, x11
 658:	54000660 	b.eq	724 <cilium_policy_guard_tree_filter_xdp+0x144>  // b.none
 65c:	385ff14d 	ldurb	w13, [x10, #-1]
 660:	f840714c 	ldur	x12, [x10, #7]
 664:	f10085bf 	cmp	x13, #0x21
 668:	54fffe23 	b.cc	62c <cilium_policy_guard_tree_filter_xdp+0x4c>  // b.lo, b.ul, b.last
 66c:	3940014e 	ldrb	w14, [x10]
 670:	3700008e 	tbnz	w14, #0, 680 <cilium_policy_guard_tree_filter_xdp+0xa0>
 674:	8b0e018c 	add	x12, x12, x14
 678:	1400001b 	b	6e4 <cilium_policy_guard_tree_filter_xdp+0x104>
 67c:	d503201f 	nop
 680:	3940054e 	ldrb	w14, [x10, #1]
 684:	373802ae 	tbnz	w14, #7, 6d8 <cilium_policy_guard_tree_filter_xdp+0xf8>
 688:	3940094e 	ldrb	w14, [x10, #2]
 68c:	12001d2f 	and	w15, w9, #0xff
 690:	4a0f01cf 	eor	w15, w14, w15
 694:	710045ff 	cmp	w15, #0x11
 698:	54000243 	b.cc	6e0 <cilium_policy_guard_tree_filter_xdp+0x100>  // b.lo, b.ul, b.last
 69c:	39400d4e 	ldrb	w14, [x10, #3]
 6a0:	0b0d01cd 	add	w13, w14, w13
 6a4:	12001dad 	and	w13, w13, #0xff
 6a8:	7102fdbf 	cmp	w13, #0xbf
 6ac:	54000208 	b.hi	6ec <cilium_policy_guard_tree_filter_xdp+0x10c>  // b.pmore
 6b0:	3940114d 	ldrb	w13, [x10, #4]
 6b4:	121d05ae 	and	w14, w13, #0x18
 6b8:	710041df 	cmp	w14, #0x10
 6bc:	540001c1 	b.ne	6f4 <cilium_policy_guard_tree_filter_xdp+0x114>  // b.any
 6c0:	3940154e 	ldrb	w14, [x10, #5]
 6c4:	7102a9df 	cmp	w14, #0xaa
 6c8:	540001a1 	b.ne	6fc <cilium_policy_guard_tree_filter_xdp+0x11c>  // b.any
 6cc:	ca0d018d 	eor	x13, x12, x13
 6d0:	93cce5ac 	extr	x12, x13, x12, #57
 6d4:	17ffffd7 	b	630 <cilium_policy_guard_tree_filter_xdp+0x50>
 6d8:	ca0e218c 	eor	x12, x12, x14, lsl #8
 6dc:	17ffffd5 	b	630 <cilium_policy_guard_tree_filter_xdp+0x50>
 6e0:	8b0e418c 	add	x12, x12, x14, lsl #16
 6e4:	ca0b018b 	eor	x11, x12, x11
 6e8:	17ffffd3 	b	634 <cilium_policy_guard_tree_filter_xdp+0x54>
 6ec:	ca0e618c 	eor	x12, x12, x14, lsl #24
 6f0:	17ffffd0 	b	630 <cilium_policy_guard_tree_filter_xdp+0x50>
 6f4:	8b0d818c 	add	x12, x12, x13, lsl #32
 6f8:	17fffffb 	b	6e4 <cilium_policy_guard_tree_filter_xdp+0x104>
 6fc:	3940194d 	ldrb	w13, [x10, #6]
 700:	120005af 	and	w15, w13, #0x3
 704:	710005ff 	cmp	w15, #0x1
 708:	54000061 	b.ne	714 <cilium_policy_guard_tree_filter_xdp+0x134>  // b.any
 70c:	ca0dc18c 	eor	x12, x12, x13, lsl #48
 710:	17ffffc8 	b	630 <cilium_policy_guard_tree_filter_xdp+0x50>
 714:	8b0ea18c 	add	x12, x12, x14, lsl #40
 718:	17fffff3 	b	6e4 <cilium_policy_guard_tree_filter_xdp+0x104>
 71c:	2a1f03e0 	mov	w0, wzr
 720:	d65f03c0 	ret
 724:	d348fd89 	lsr	x9, x12, #8
 728:	52800040 	mov	w0, #0x2                   	// #2
 72c:	3900010b 	strb	w11, [x8]
 730:	39000509 	strb	w9, [x8, #1]
 734:	d350fd89 	lsr	x9, x12, #16
 738:	39000909 	strb	w9, [x8, #2]
 73c:	d358fd89 	lsr	x9, x12, #24
 740:	39000d09 	strb	w9, [x8, #3]
 744:	d360fd89 	lsr	x9, x12, #32
 748:	39001109 	strb	w9, [x8, #4]
 74c:	d368fd89 	lsr	x9, x12, #40
 750:	39001509 	strb	w9, [x8, #5]
 754:	d370fd89 	lsr	x9, x12, #48
 758:	39001909 	strb	w9, [x8, #6]
 75c:	d378fd89 	lsr	x9, x12, #56
 760:	39001d09 	strb	w9, [x8, #7]
 764:	d65f03c0 	ret

Disassembly of section .fini:

0000000000000768 <_fini>:
 768:	d503201f 	nop
 76c:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 770:	910003fd 	mov	x29, sp
 774:	a8c17bfd 	ldp	x29, x30, [sp], #16
 778:	d65f03c0 	ret
```

## Original Kernel JIT ASM
```asm
not captured
```

## llvmbpf JIT ASM
```asm
not captured
```
