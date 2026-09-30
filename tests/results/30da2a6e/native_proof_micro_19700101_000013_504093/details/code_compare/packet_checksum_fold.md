# packet_checksum_fold

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
 484:	f00000f0 	adrp	x16, 1f000 <__FRAME_END__+0x1e8c0>
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
 4c0:	f00000e0 	adrp	x0, 1f000 <__FRAME_END__+0x1e8c0>
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
 4f8:	f00000e1 	adrp	x1, 1f000 <__FRAME_END__+0x1e8c0>
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
 534:	f00000e2 	adrp	x2, 1f000 <__FRAME_END__+0x1e8c0>
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
 56c:	f00000e0 	adrp	x0, 1f000 <__FRAME_END__+0x1e8c0>
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

00000000000005c0 <packet_checksum_fold_xdp>:
 5c0:	a9402808 	ldp	x8, x10, [x0]
 5c4:	aa0803e9 	mov	x9, x8
 5c8:	eb0a013f 	cmp	x9, x10
 5cc:	54000069 	b.ls	5d8 <packet_checksum_fold_xdp+0x18>  // b.plast
 5d0:	2a1f03e0 	mov	w0, wzr
 5d4:	d65f03c0 	ret
 5d8:	9100212b 	add	x11, x9, #0x8
 5dc:	9110412c 	add	x12, x9, #0x410
 5e0:	2a1f03e0 	mov	w0, wzr
 5e4:	eb0a017f 	cmp	x11, x10
 5e8:	fa4a9182 	ccmp	x12, x10, #0x2, ls	// ls = plast
 5ec:	540004a8 	b.hi	680 <packet_checksum_fold_xdp+0xc0>  // b.pmore
 5f0:	b940092a 	ldr	w10, [x9, #8]
 5f4:	7100815f 	cmp	w10, #0x20
 5f8:	54000441 	b.ne	680 <packet_checksum_fold_xdp+0xc0>  // b.any
 5fc:	b9400d2a 	ldr	w10, [x9, #12]
 600:	7108015f 	cmp	w10, #0x200
 604:	540003e1 	b.ne	680 <packet_checksum_fold_xdp+0xc0>  // b.any
 608:	2a1f03eb 	mov	w11, wzr
 60c:	aa1f03ea 	mov	x10, xzr
 610:	529fffec 	mov	w12, #0xffff                	// #65535
 614:	d503201f 	nop
 618:	d503201f 	nop
 61c:	d503201f 	nop
 620:	aa1f03ed 	mov	x13, xzr
 624:	2a1f03ee 	mov	w14, wzr
 628:	8b0d012f 	add	x15, x9, x13
 62c:	910011ad 	add	x13, x13, #0x4
 630:	794021f0 	ldrh	w16, [x15, #16]
 634:	794025ef 	ldrh	w15, [x15, #18]
 638:	f11001bf 	cmp	x13, #0x400
 63c:	0b0e020e 	add	w14, w16, w14
 640:	53107dd0 	lsr	w16, w14, #16
 644:	0b2e220e 	add	w14, w16, w14, uxth
 648:	0b0e01ee 	add	w14, w15, w14
 64c:	53107dcf 	lsr	w15, w14, #16
 650:	0b2e21ee 	add	w14, w15, w14, uxth
 654:	54fffea1 	b.ne	628 <packet_checksum_fold_xdp+0x68>  // b.any
 658:	0b4e41cd 	add	w13, w14, w14, lsr #16
 65c:	531c056e 	ubfiz	w14, w11, #4, #2
 660:	1100056b 	add	w11, w11, #0x1
 664:	7100817f 	cmp	w11, #0x20
 668:	0a2d018d 	bic	w13, w12, w13
 66c:	9ace21ad 	lsl	x13, x13, x14
 670:	ca0a01aa 	eor	x10, x13, x10
 674:	54fffd61 	b.ne	620 <packet_checksum_fold_xdp+0x60>  // b.any
 678:	52800040 	mov	w0, #0x2                   	// #2
 67c:	f900010a 	str	x10, [x8]
 680:	d65f03c0 	ret

Disassembly of section .fini:

0000000000000684 <_fini>:
 684:	d503201f 	nop
 688:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 68c:	910003fd 	mov	x29, sp
 690:	a8c17bfd 	ldp	x29, x30, [sp], #16
 694:	d65f03c0 	ret
```

## Original Kernel JIT ASM
```asm
not captured
```

## llvmbpf JIT ASM
```asm
not captured
```
