# bcc_runqlat_log2_histogram_bucket

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
 494:	f00000f0 	adrp	x16, 1f000 <__FRAME_END__+0x1e830>
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
 4e0:	f00000e0 	adrp	x0, 1f000 <__FRAME_END__+0x1e830>
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
 518:	f00000e1 	adrp	x1, 1f000 <__FRAME_END__+0x1e830>
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
 554:	f00000e2 	adrp	x2, 1f000 <__FRAME_END__+0x1e830>
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
 58c:	f00000e0 	adrp	x0, 1f000 <__FRAME_END__+0x1e830>
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

00000000000005e0 <bcc_runqlat_log2_histogram_bucket_xdp>:
 5e0:	a9402408 	ldp	x8, x9, [x0]
 5e4:	aa0803f2 	mov	x18, x8
 5e8:	eb09025f 	cmp	x18, x9
 5ec:	540008a8 	b.hi	700 <bcc_runqlat_log2_histogram_bucket_xdp+0x120>  // b.pmore
 5f0:	9100224a 	add	x10, x18, #0x8
 5f4:	9110424b 	add	x11, x18, #0x410
 5f8:	eb09015f 	cmp	x10, x9
 5fc:	fa499162 	ccmp	x11, x9, #0x2, ls	// ls = plast
 600:	54000808 	b.hi	700 <bcc_runqlat_log2_histogram_bucket_xdp+0x120>  // b.pmore
 604:	b9400149 	ldr	w9, [x10]
 608:	7102013f 	cmp	w9, #0x80
 60c:	540007a1 	b.ne	700 <bcc_runqlat_log2_histogram_bucket_xdp+0x120>  // b.any
 610:	b9400e50 	ldr	w16, [x18, #12]
 614:	aa1f03e9 	mov	x9, xzr
 618:	9100424a 	add	x10, x18, #0x10
 61c:	9100464b 	add	x11, x18, #0x11
 620:	91004a4c 	add	x12, x18, #0x12
 624:	91004e4d 	add	x13, x18, #0x13
 628:	9100524e 	add	x14, x18, #0x14
 62c:	9100564f 	add	x15, x18, #0x15
 630:	91005a51 	add	x17, x18, #0x16
 634:	91005e52 	add	x18, x18, #0x17
 638:	52800320 	mov	w0, #0x19                  	// #25
 63c:	14000020 	b	6bc <bcc_runqlat_log2_histogram_bucket_xdp+0xdc>
 640:	386169a4 	ldrb	w4, [x13, x1]
 644:	386169e5 	ldrb	w5, [x15, x1]
 648:	7100645f 	cmp	w2, #0x19
 64c:	91000529 	add	x9, x9, #0x1
 650:	1a803042 	csel	w2, w2, w0, cc	// cc = lo, ul, last
 654:	38616a46 	ldrb	w6, [x18, x1]
 658:	aa046063 	orr	x3, x3, x4, lsl #24
 65c:	386169c4 	ldrb	w4, [x14, x1]
 660:	d3585ca5 	lsl	x5, x5, #40
 664:	d3481cc6 	lsl	x6, x6, #56
 668:	aa0480a4 	orr	x4, x5, x4, lsl #32
 66c:	38616a25 	ldrb	w5, [x17, x1]
 670:	927d0821 	and	x1, x1, #0x38
 674:	9ac12041 	lsl	x1, x2, x1
 678:	aa05c0c5 	orr	x5, x6, x5, lsl #48
 67c:	aa0400a4 	orr	x4, x5, x4
 680:	aa030083 	orr	x3, x4, x3
 684:	11000444 	add	w4, w2, #0x1
 688:	9b044130 	madd	x16, x9, x4, x16
 68c:	12000844 	and	w4, w2, #0x7
 690:	11000485 	add	w5, w4, #0x1
 694:	52001484 	eor	w4, w4, #0x3f
 698:	9ac52065 	lsl	x5, x3, x5
 69c:	9ac42464 	lsr	x4, x3, x4
 6a0:	aa0400a4 	orr	x4, x5, x4
 6a4:	ca100090 	eor	x16, x4, x16
 6a8:	ca010201 	eor	x1, x16, x1
 6ac:	8b438210 	add	x16, x16, x3, lsr #32
 6b0:	9a903030 	csel	x16, x1, x16, cc	// cc = lo, ul, last
 6b4:	f102013f 	cmp	x9, #0x80
 6b8:	54000280 	b.eq	708 <bcc_runqlat_log2_histogram_bucket_xdp+0x128>  // b.none
 6bc:	d37df121 	lsl	x1, x9, #3
 6c0:	38616942 	ldrb	w2, [x10, x1]
 6c4:	38616963 	ldrb	w3, [x11, x1]
 6c8:	aa032042 	orr	x2, x2, x3, lsl #8
 6cc:	38616983 	ldrb	w3, [x12, x1]
 6d0:	aa034043 	orr	x3, x2, x3, lsl #16
 6d4:	2a1f03e2 	mov	w2, wzr
 6d8:	d3435864 	ubfx	x4, x3, #3, #20
 6dc:	b4fffb24 	cbz	x4, 640 <bcc_runqlat_log2_histogram_bucket_xdp+0x60>
 6e0:	91000484 	add	x4, x4, #0x1
 6e4:	7100f45f 	cmp	w2, #0x3d
 6e8:	11000442 	add	w2, w2, #0x1
 6ec:	54fffaa8 	b.hi	640 <bcc_runqlat_log2_histogram_bucket_xdp+0x60>  // b.pmore
 6f0:	f1000c9f 	cmp	x4, #0x3
 6f4:	d341fc84 	lsr	x4, x4, #1
 6f8:	54ffff68 	b.hi	6e4 <bcc_runqlat_log2_histogram_bucket_xdp+0x104>  // b.pmore
 6fc:	17ffffd1 	b	640 <bcc_runqlat_log2_histogram_bucket_xdp+0x60>
 700:	2a1f03e0 	mov	w0, wzr
 704:	d65f03c0 	ret
 708:	52800040 	mov	w0, #0x2                   	// #2
 70c:	f9000110 	str	x16, [x8]
 710:	d65f03c0 	ret

Disassembly of section .fini:

0000000000000714 <_fini>:
 714:	d503201f 	nop
 718:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 71c:	910003fd 	mov	x29, sp
 720:	a8c17bfd 	ldp	x29, x30, [sp], #16
 724:	d65f03c0 	ret
```

## Original Kernel JIT ASM
```asm
not captured
```

## llvmbpf JIT ASM
```asm
not captured
```
