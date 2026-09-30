# cgroup_skb_hash_chain

## Original C
```c
not captured
```

## Native ASM
```asm
Disassembly of section .init:

0000000000000468 <_init>:
 468:	d503201f 	nop
 46c:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 470:	910003fd 	mov	x29, sp
 474:	94000013 	bl	4c0 <call_weak_fn>
 478:	a8c17bfd 	ldp	x29, x30, [sp], #16
 47c:	d65f03c0 	ret

Disassembly of section .plt:

0000000000000480 <.plt>:
 480:	a9bf7bf0 	stp	x16, x30, [sp, #-16]!
 484:	f00000f0 	adrp	x16, 1f000 <__FRAME_END__+0x1e700>
 488:	f947fe11 	ldr	x17, [x16, #4088]
 48c:	913fe210 	add	x16, x16, #0xff8
 490:	d61f0220 	br	x17
 494:	d503201f 	nop
 498:	d503201f 	nop
 49c:	d503201f 	nop

00000000000004a0 <__cxa_finalize@plt>:
 4a0:	90000110 	adrp	x16, 20000 <__cxa_finalize@GLIBC_2.17>
 4a4:	f9400211 	ldr	x17, [x16]
 4a8:	91000210 	add	x16, x16, #0x0
 4ac:	d61f0220 	br	x17

00000000000004b0 <__gmon_start__@plt>:
 4b0:	90000110 	adrp	x16, 20000 <__cxa_finalize@GLIBC_2.17>
 4b4:	f9400611 	ldr	x17, [x16, #8]
 4b8:	91002210 	add	x16, x16, #0x8
 4bc:	d61f0220 	br	x17

Disassembly of section .text:

00000000000004c0 <call_weak_fn>:
 4c0:	f00000e0 	adrp	x0, 1f000 <__FRAME_END__+0x1e700>
 4c4:	f947ec00 	ldr	x0, [x0, #4056]
 4c8:	b4000040 	cbz	x0, 4d0 <call_weak_fn+0x10>
 4cc:	17fffff9 	b	4b0 <__gmon_start__@plt>
 4d0:	d65f03c0 	ret
 4d4:	d503201f 	nop
 4d8:	d503201f 	nop
 4dc:	d503201f 	nop

00000000000004e0 <deregister_tm_clones>:
 4e0:	90000100 	adrp	x0, 20000 <__cxa_finalize@GLIBC_2.17>
 4e4:	91006000 	add	x0, x0, #0x18
 4e8:	90000101 	adrp	x1, 20000 <__cxa_finalize@GLIBC_2.17>
 4ec:	91006021 	add	x1, x1, #0x18
 4f0:	eb00003f 	cmp	x1, x0
 4f4:	540000c0 	b.eq	50c <deregister_tm_clones+0x2c>  // b.none
 4f8:	f00000e1 	adrp	x1, 1f000 <__FRAME_END__+0x1e700>
 4fc:	f947e421 	ldr	x1, [x1, #4040]
 500:	b4000061 	cbz	x1, 50c <deregister_tm_clones+0x2c>
 504:	aa0103f0 	mov	x16, x1
 508:	d61f0200 	br	x16
 50c:	d65f03c0 	ret

0000000000000510 <register_tm_clones>:
 510:	90000100 	adrp	x0, 20000 <__cxa_finalize@GLIBC_2.17>
 514:	91006000 	add	x0, x0, #0x18
 518:	90000101 	adrp	x1, 20000 <__cxa_finalize@GLIBC_2.17>
 51c:	91006021 	add	x1, x1, #0x18
 520:	cb000021 	sub	x1, x1, x0
 524:	d37ffc22 	lsr	x2, x1, #63
 528:	8b810c41 	add	x1, x2, x1, asr #3
 52c:	9341fc21 	asr	x1, x1, #1
 530:	b40000c1 	cbz	x1, 548 <register_tm_clones+0x38>
 534:	f00000e2 	adrp	x2, 1f000 <__FRAME_END__+0x1e700>
 538:	f947f042 	ldr	x2, [x2, #4064]
 53c:	b4000062 	cbz	x2, 548 <register_tm_clones+0x38>
 540:	aa0203f0 	mov	x16, x2
 544:	d61f0200 	br	x16
 548:	d65f03c0 	ret
 54c:	d503201f 	nop

0000000000000550 <__do_global_dtors_aux>:
 550:	d503233f 	paciasp
 554:	a9be7bfd 	stp	x29, x30, [sp, #-32]!
 558:	910003fd 	mov	x29, sp
 55c:	f9000bf3 	str	x19, [sp, #16]
 560:	90000113 	adrp	x19, 20000 <__cxa_finalize@GLIBC_2.17>
 564:	39406260 	ldrb	w0, [x19, #24]
 568:	37000140 	tbnz	w0, #0, 590 <__do_global_dtors_aux+0x40>
 56c:	f00000e0 	adrp	x0, 1f000 <__FRAME_END__+0x1e700>
 570:	f947e800 	ldr	x0, [x0, #4048]
 574:	b4000080 	cbz	x0, 584 <__do_global_dtors_aux+0x34>
 578:	90000100 	adrp	x0, 20000 <__cxa_finalize@GLIBC_2.17>
 57c:	f9400800 	ldr	x0, [x0, #16]
 580:	97ffffc8 	bl	4a0 <__cxa_finalize@plt>
 584:	97ffffd7 	bl	4e0 <deregister_tm_clones>
 588:	52800020 	mov	w0, #0x1                   	// #1
 58c:	39006260 	strb	w0, [x19, #24]
 590:	f9400bf3 	ldr	x19, [sp, #16]
 594:	a8c27bfd 	ldp	x29, x30, [sp], #32
 598:	d50323bf 	autiasp
 59c:	d65f03c0 	ret

00000000000005a0 <frame_dummy>:
 5a0:	d503245f 	bti	c
 5a4:	17ffffdb 	b	510 <register_tm_clones>
 5a8:	d503201f 	nop
 5ac:	d503201f 	nop
 5b0:	d503201f 	nop
 5b4:	d503201f 	nop
 5b8:	d503201f 	nop
 5bc:	d503201f 	nop

00000000000005c0 <cgroup_skb_hash_chain_prog>:
 5c0:	f9406807 	ldr	x7, [x0, #208]
 5c4:	f940280a 	ldr	x10, [x0, #80]
 5c8:	eb0a00ff 	cmp	x7, x10
 5cc:	910020e8 	add	x8, x7, #0x8
 5d0:	910140e9 	add	x9, x7, #0x50
 5d4:	fa4a9102 	ccmp	x8, x10, #0x2, ls	// ls = plast
 5d8:	fa4a9122 	ccmp	x9, x10, #0x2, ls	// ls = plast
 5dc:	540000c9 	b.ls	5f4 <cgroup_skb_hash_chain_prog+0x34>  // b.plast
 5e0:	12800009 	mov	w9, #0xffffffff            	// #-1
 5e4:	2a1f03e8 	mov	w8, wzr
 5e8:	29062409 	stp	w9, w9, [x0, #48]
 5ec:	2a0803e0 	mov	w0, w8
 5f0:	d65f03c0 	ret
 5f4:	aa0803ea 	mov	x10, x8
 5f8:	aa0903eb 	mov	x11, x9
 5fc:	9100214c 	add	x12, x10, #0x8
 600:	eb0b015f 	cmp	x10, x11
 604:	fa4b9182 	ccmp	x12, x11, #0x2, ls	// ls = plast
 608:	54fffec8 	b.hi	5e0 <cgroup_skb_hash_chain_prog+0x20>  // b.pmore
 60c:	29412cea 	ldp	w10, w11, [x7, #8]
 610:	7100415f 	cmp	w10, #0x10
 614:	7a480960 	ccmp	w11, #0x8, #0x0, eq	// eq = none
 618:	54fffe41 	b.ne	5e0 <cgroup_skb_hash_chain_prog+0x20>  // b.any
 61c:	9100210a 	add	x10, x8, #0x8
 620:	eb09015f 	cmp	x10, x9
 624:	54fffde8 	b.hi	5e0 <cgroup_skb_hash_chain_prog+0x20>  // b.pmore
 628:	91012108 	add	x8, x8, #0x48
 62c:	eb09011f 	cmp	x8, x9
 630:	54fffd88 	b.hi	5e0 <cgroup_skb_hash_chain_prog+0x20>  // b.pmore
 634:	f81a0ffd 	str	x29, [sp, #-96]!
 638:	a9016ffc 	stp	x28, x27, [sp, #16]
 63c:	a90267fa 	stp	x26, x25, [sp, #32]
 640:	a9035ff8 	stp	x24, x23, [sp, #48]
 644:	a90457f6 	stp	x22, x21, [sp, #64]
 648:	a9054ff4 	stp	x20, x19, [sp, #80]
 64c:	d28f82a8 	mov	x8, #0x7c15                	// #31765
 650:	a9412cea 	ldp	x10, x11, [x7, #16]
 654:	d28464bc 	mov	x28, #0x2325                	// #8997
 658:	d29df2ad 	mov	x13, #0xef95                	// #61333
 65c:	d29be551 	mov	x17, #0xdf2a                	// #57130
 660:	a9423cee 	ldp	x14, x15, [x7, #32]
 664:	f2afe948 	movk	x8, #0x7f4a, lsl #16
 668:	d299d7e3 	mov	x3, #0xcebf                	// #52927
 66c:	d297ca85 	mov	x5, #0xbe54                	// #48724
 670:	a94308e1 	ldp	x1, x2, [x7, #48]
 674:	d295bd34 	mov	x20, #0xade9                	// #44521
 678:	d293afd6 	mov	x22, #0x9d7e                	// #40318
 67c:	d291a277 	mov	x23, #0x8d13                	// #36115
 680:	a9441ce6 	ldp	x6, x7, [x7, #64]
 684:	d28f9519 	mov	x25, #0x7ca8                	// #31912
 688:	f2cf3728 	movk	x8, #0x79b9, lsl #32
 68c:	f2b0845c 	movk	x28, #0x8422, lsl #16
 690:	f2bbd04d 	movk	x13, #0xde82, lsl #16
 694:	f2b7a0b1 	movk	x17, #0xbd05, lsl #16
 698:	f2b37103 	movk	x3, #0x9b88, lsl #16
 69c:	f2af4165 	movk	x5, #0x7a0b, lsl #16
 6a0:	f2ab11d4 	movk	x20, #0x588e, lsl #16
 6a4:	f2a6e236 	movk	x22, #0x3711, lsl #16
 6a8:	f2a2b297 	movk	x23, #0x1594, lsl #16
 6ac:	f2be82f9 	movk	x25, #0xf417, lsl #16
 6b0:	f2f3c6e8 	movk	x8, #0x9e37, lsl #48
 6b4:	d2803669 	mov	x9, #0x1b3                 	// #435
 6b8:	f2d39c9c 	movk	x28, #0x9ce4, lsl #32
 6bc:	f2c4a86d 	movk	x13, #0x2543, lsl #32
 6c0:	f2c950f1 	movk	x17, #0x4a87, lsl #32
 6c4:	f2cdf963 	movk	x3, #0x6fcb, lsl #32
 6c8:	f2d2a1e5 	movk	x5, #0x950f, lsl #32
 6cc:	f2d74a74 	movk	x20, #0xba53, lsl #32
 6d0:	f2dbf2f6 	movk	x22, #0xdf97, lsl #32
 6d4:	f2c09b77 	movk	x23, #0x4db, lsl #32
 6d8:	f2c543d9 	movk	x25, #0x2a1e, lsl #32
 6dc:	f2c02009 	movk	x9, #0x100, lsl #32
 6e0:	f2f97e5c 	movk	x28, #0xcbf2, lsl #48
 6e4:	528007cc 	mov	w12, #0x3e                  	// #62
 6e8:	f2fa268d 	movk	x13, #0xd134, lsl #48
 6ec:	528006f0 	mov	w16, #0x37                  	// #55
 6f0:	f2f44d11 	movk	x17, #0xa268, lsl #48
 6f4:	52800592 	mov	w18, #0x2c                  	// #44
 6f8:	f2ee7383 	movk	x3, #0x739c, lsl #48
 6fc:	52800424 	mov	w4, #0x21                  	// #33
 700:	f2e89a05 	movk	x5, #0x44d0, lsl #48
 704:	528002d3 	mov	w19, #0x16                  	// #22
 708:	f2e2c094 	movk	x20, #0x1604, lsl #48
 70c:	52800175 	mov	w21, #0xb                   	// #11
 710:	f2fce716 	movk	x22, #0xe738, lsl #48
 714:	f2f70db7 	movk	x23, #0xb86d, lsl #48
 718:	528006b8 	mov	w24, #0x35                  	// #53
 71c:	f2f13439 	movk	x25, #0x89a1, lsl #48
 720:	5280055a 	mov	w26, #0x2a                  	// #42
 724:	aa0803fb 	mov	x27, x8
 728:	ca0d037d 	eor	x29, x27, x13
 72c:	8b1d015d 	add	x29, x10, x29
 730:	ca1c03bc 	eor	x28, x29, x28
 734:	4b0c021d 	sub	w29, w16, w12
 738:	9add2f9c 	ror	x28, x28, x29
 73c:	ca11037d 	eor	x29, x27, x17
 740:	9b097f9c 	mul	x28, x28, x9
 744:	8b1d017d 	add	x29, x11, x29
 748:	ca5c77bd 	eor	x29, x29, x28, lsr #29
 74c:	ca1c03bc 	eor	x28, x29, x28
 750:	4b0c025d 	sub	w29, w18, w12
 754:	9add2f9c 	ror	x28, x28, x29
 758:	ca03037d 	eor	x29, x27, x3
 75c:	9b097f9c 	mul	x28, x28, x9
 760:	8b1d01dd 	add	x29, x14, x29
 764:	ca5c77bd 	eor	x29, x29, x28, lsr #29
 768:	ca1c03bc 	eor	x28, x29, x28
 76c:	4b0c009d 	sub	w29, w4, w12
 770:	9add2f9c 	ror	x28, x28, x29
 774:	ca05037d 	eor	x29, x27, x5
 778:	9b097f9c 	mul	x28, x28, x9
 77c:	8b1d01fd 	add	x29, x15, x29
 780:	ca5c77bd 	eor	x29, x29, x28, lsr #29
 784:	ca1c03bc 	eor	x28, x29, x28
 788:	4b0c027d 	sub	w29, w19, w12
 78c:	9add2f9c 	ror	x28, x28, x29
 790:	ca14037d 	eor	x29, x27, x20
 794:	9b097f9c 	mul	x28, x28, x9
 798:	8b1d003d 	add	x29, x1, x29
 79c:	ca5c77bd 	eor	x29, x29, x28, lsr #29
 7a0:	ca1c03bc 	eor	x28, x29, x28
 7a4:	4b0c02bd 	sub	w29, w21, w12
 7a8:	9add2f9c 	ror	x28, x28, x29
 7ac:	ca16037d 	eor	x29, x27, x22
 7b0:	9b097f9c 	mul	x28, x28, x9
 7b4:	8b1d005d 	add	x29, x2, x29
 7b8:	ca5c77bd 	eor	x29, x29, x28, lsr #29
 7bc:	ca1c03bc 	eor	x28, x29, x28
 7c0:	4b0c03fd 	neg	w29, w12
 7c4:	9add2f9c 	ror	x28, x28, x29
 7c8:	ca17037d 	eor	x29, x27, x23
 7cc:	9b097f9c 	mul	x28, x28, x9
 7d0:	8b1d00dd 	add	x29, x6, x29
 7d4:	ca5c77bd 	eor	x29, x29, x28, lsr #29
 7d8:	ca1c03bc 	eor	x28, x29, x28
 7dc:	4b0c031d 	sub	w29, w24, w12
 7e0:	9add2f9c 	ror	x28, x28, x29
 7e4:	ca19037d 	eor	x29, x27, x25
 7e8:	8b08037b 	add	x27, x27, x8
 7ec:	9b097f9c 	mul	x28, x28, x9
 7f0:	8b1d00fd 	add	x29, x7, x29
 7f4:	ca5c77bd 	eor	x29, x29, x28, lsr #29
 7f8:	ca1c03bc 	eor	x28, x29, x28
 7fc:	4b0c035d 	sub	w29, w26, w12
 800:	9100158c 	add	x12, x12, #0x5
 804:	9add2f9c 	ror	x28, x28, x29
 808:	f102399f 	cmp	x12, #0x8e
 80c:	9b097f9c 	mul	x28, x28, x9
 810:	ca5c779c 	eor	x28, x28, x28, lsr #29
 814:	54fff8a1 	b.ne	728 <cgroup_skb_hash_chain_prog+0x168>  // b.any
 818:	b900301c 	str	w28, [x0, #48]
 81c:	d360ff89 	lsr	x9, x28, #32
 820:	a9454ff4 	ldp	x20, x19, [sp, #80]
 824:	52800028 	mov	w8, #0x1                   	// #1
 828:	a94457f6 	ldp	x22, x21, [sp, #64]
 82c:	a9435ff8 	ldp	x24, x23, [sp, #48]
 830:	a94267fa 	ldp	x26, x25, [sp, #32]
 834:	a9416ffc 	ldp	x28, x27, [sp, #16]
 838:	f84607fd 	ldr	x29, [sp], #96
 83c:	b9003409 	str	w9, [x0, #52]
 840:	2a0803e0 	mov	w0, w8
 844:	d65f03c0 	ret

Disassembly of section .fini:

0000000000000848 <_fini>:
 848:	d503201f 	nop
 84c:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 850:	910003fd 	mov	x29, sp
 854:	a8c17bfd 	ldp	x29, x30, [sp], #16
 858:	d65f03c0 	ret
```

## Original Kernel JIT ASM
```asm
not captured
```

## llvmbpf JIT ASM
```asm
not captured
```
