# tc_packet_checksum_fold

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
 484:	f00000f0 	adrp	x16, 1f000 <__FRAME_END__+0x1e880>
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
 4c0:	f00000e0 	adrp	x0, 1f000 <__FRAME_END__+0x1e880>
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
 4f8:	f00000e1 	adrp	x1, 1f000 <__FRAME_END__+0x1e880>
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
 534:	f00000e2 	adrp	x2, 1f000 <__FRAME_END__+0x1e880>
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
 56c:	f00000e0 	adrp	x0, 1f000 <__FRAME_END__+0x1e880>
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

00000000000005c0 <tc_packet_checksum_fold_prog>:
 5c0:	f9406808 	ldr	x8, [x0, #208]
 5c4:	f940280b 	ldr	x11, [x0, #80]
 5c8:	eb0b011f 	cmp	x8, x11
 5cc:	91002109 	add	x9, x8, #0x8
 5d0:	9110410a 	add	x10, x8, #0x410
 5d4:	fa4b9122 	ccmp	x9, x11, #0x2, ls	// ls = plast
 5d8:	fa4b9142 	ccmp	x10, x11, #0x2, ls	// ls = plast
 5dc:	540000c9 	b.ls	5f4 <tc_packet_checksum_fold_prog+0x34>  // b.plast
 5e0:	12800009 	mov	w9, #0xffffffff            	// #-1
 5e4:	52800048 	mov	w8, #0x2                   	// #2
 5e8:	29062409 	stp	w9, w9, [x0, #48]
 5ec:	2a0803e0 	mov	w0, w8
 5f0:	d65f03c0 	ret
 5f4:	aa0903eb 	mov	x11, x9
 5f8:	aa0a03ec 	mov	x12, x10
 5fc:	9100216d 	add	x13, x11, #0x8
 600:	eb0c017f 	cmp	x11, x12
 604:	fa4c91a2 	ccmp	x13, x12, #0x2, ls	// ls = plast
 608:	54fffec8 	b.hi	5e0 <tc_packet_checksum_fold_prog+0x20>  // b.pmore
 60c:	b940090b 	ldr	w11, [x8, #8]
 610:	7100817f 	cmp	w11, #0x20
 614:	54fffe61 	b.ne	5e0 <tc_packet_checksum_fold_prog+0x20>  // b.any
 618:	b9400d0b 	ldr	w11, [x8, #12]
 61c:	7108017f 	cmp	w11, #0x200
 620:	54fffe01 	b.ne	5e0 <tc_packet_checksum_fold_prog+0x20>  // b.any
 624:	9100212b 	add	x11, x9, #0x8
 628:	eb0a017f 	cmp	x11, x10
 62c:	54fffda8 	b.hi	5e0 <tc_packet_checksum_fold_prog+0x20>  // b.pmore
 630:	91102129 	add	x9, x9, #0x408
 634:	eb0a013f 	cmp	x9, x10
 638:	54fffd48 	b.hi	5e0 <tc_packet_checksum_fold_prog+0x20>  // b.pmore
 63c:	2a1f03ea 	mov	w10, wzr
 640:	aa1f03e9 	mov	x9, xzr
 644:	529fffeb 	mov	w11, #0xffff                	// #65535
 648:	aa1f03ec 	mov	x12, xzr
 64c:	2a1f03ed 	mov	w13, wzr
 650:	d503201f 	nop
 654:	d503201f 	nop
 658:	d503201f 	nop
 65c:	d503201f 	nop
 660:	8b0c010e 	add	x14, x8, x12
 664:	9100118c 	add	x12, x12, #0x4
 668:	794021cf 	ldrh	w15, [x14, #16]
 66c:	794025ce 	ldrh	w14, [x14, #18]
 670:	f110019f 	cmp	x12, #0x400
 674:	0b0d01ed 	add	w13, w15, w13
 678:	53107daf 	lsr	w15, w13, #16
 67c:	0b2d21ed 	add	w13, w15, w13, uxth
 680:	0b0d01cd 	add	w13, w14, w13
 684:	53107dae 	lsr	w14, w13, #16
 688:	0b2d21cd 	add	w13, w14, w13, uxth
 68c:	54fffea1 	b.ne	660 <tc_packet_checksum_fold_prog+0xa0>  // b.any
 690:	0b4d41ac 	add	w12, w13, w13, lsr #16
 694:	531c054d 	ubfiz	w13, w10, #4, #2
 698:	1100054a 	add	w10, w10, #0x1
 69c:	7100815f 	cmp	w10, #0x20
 6a0:	0a2c016c 	bic	w12, w11, w12
 6a4:	9acd218c 	lsl	x12, x12, x13
 6a8:	ca090189 	eor	x9, x12, x9
 6ac:	54fffce1 	b.ne	648 <tc_packet_checksum_fold_prog+0x88>  // b.any
 6b0:	2a1f03e8 	mov	w8, wzr
 6b4:	b9003009 	str	w9, [x0, #48]
 6b8:	d360fd29 	lsr	x9, x9, #32
 6bc:	b9003409 	str	w9, [x0, #52]
 6c0:	2a0803e0 	mov	w0, w8
 6c4:	d65f03c0 	ret

Disassembly of section .fini:

00000000000006c8 <_fini>:
 6c8:	d503201f 	nop
 6cc:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 6d0:	910003fd 	mov	x29, sp
 6d4:	a8c17bfd 	ldp	x29, x30, [sp], #16
 6d8:	d65f03c0 	ret
```

## Original Kernel JIT ASM
```asm
not captured
```

## llvmbpf JIT ASM
```asm
not captured
```
