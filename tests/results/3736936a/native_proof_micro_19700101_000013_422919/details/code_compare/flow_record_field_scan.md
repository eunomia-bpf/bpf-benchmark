# flow_record_field_scan

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
 484:	f00000f0 	adrp	x16, 1f000 <__FRAME_END__+0x1e858>
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
 4c0:	f00000e0 	adrp	x0, 1f000 <__FRAME_END__+0x1e858>
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
 4f8:	f00000e1 	adrp	x1, 1f000 <__FRAME_END__+0x1e858>
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
 534:	f00000e2 	adrp	x2, 1f000 <__FRAME_END__+0x1e858>
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
 56c:	f00000e0 	adrp	x0, 1f000 <__FRAME_END__+0x1e858>
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

00000000000005c0 <flow_record_field_scan_xdp>:
 5c0:	a9402808 	ldp	x8, x10, [x0]
 5c4:	aa0803e9 	mov	x9, x8
 5c8:	eb0a013f 	cmp	x9, x10
 5cc:	540006c8 	b.hi	6a4 <flow_record_field_scan_xdp+0xe4>  // b.pmore
 5d0:	9100212b 	add	x11, x9, #0x8
 5d4:	9110412c 	add	x12, x9, #0x410
 5d8:	eb0a017f 	cmp	x11, x10
 5dc:	fa4a9182 	ccmp	x12, x10, #0x2, ls	// ls = plast
 5e0:	54000628 	b.hi	6a4 <flow_record_field_scan_xdp+0xe4>  // b.pmore
 5e4:	b940016a 	ldr	w10, [x11]
 5e8:	7100815f 	cmp	w10, #0x20
 5ec:	540005c1 	b.ne	6a4 <flow_record_field_scan_xdp+0xe4>  // b.any
 5f0:	b9400d2a 	ldr	w10, [x9, #12]
 5f4:	7100815f 	cmp	w10, #0x20
 5f8:	54000561 	b.ne	6a4 <flow_record_field_scan_xdp+0xe4>  // b.any
 5fc:	d28f82ad 	mov	x13, #0x7c15                	// #31765
 600:	aa1f03ea 	mov	x10, xzr
 604:	aa1f03eb 	mov	x11, xzr
 608:	aa1f03ec 	mov	x12, xzr
 60c:	f2afe94d 	movk	x13, #0x7f4a, lsl #16
 610:	f2cf372d 	movk	x13, #0x79b9, lsl #32
 614:	f2f3c6ed 	movk	x13, #0x9e37, lsl #48
 618:	14000014 	b	668 <flow_record_field_scan_xdp+0xa8>
 61c:	d503201f 	nop
 620:	9240098f 	and	x15, x12, #0x7
 624:	9acf260f 	lsr	x15, x16, x15
 628:	ca0f022f 	eor	x15, x17, x15
 62c:	8b0f01ad 	add	x13, x13, x15
 630:	927d056f 	and	x15, x11, #0x18
 634:	9100814a 	add	x10, x10, #0x20
 638:	9100058c 	add	x12, x12, #0x1
 63c:	9100216b 	add	x11, x11, #0x8
 640:	9acf21cf 	lsl	x15, x14, x15
 644:	f110015f 	cmp	x10, #0x400
 648:	ca0f01ad 	eor	x13, x13, x15
 64c:	120009cf 	and	w15, w14, #0x7
 650:	110005ee 	add	w14, w15, #0x1
 654:	520015ef 	eor	w15, w15, #0x3f
 658:	9ace21ae 	lsl	x14, x13, x14
 65c:	9acf25ad 	lsr	x13, x13, x15
 660:	aa0d01cd 	orr	x13, x14, x13
 664:	54000240 	b.eq	6ac <flow_record_field_scan_xdp+0xec>  // b.none
 668:	8b0a012f 	add	x15, x9, x10
 66c:	a941c1ee 	ldp	x14, x16, [x15, #24]
 670:	794029e0 	ldrh	w0, [x15, #20]
 674:	8b0e0212 	add	x18, x16, x14
 678:	294545ee 	ldp	w14, w17, [x15, #40]
 67c:	aa0e8231 	orr	x17, x17, x14, lsl #32
 680:	b94011ee 	ldr	w14, [x15, #16]
 684:	aa0e4001 	orr	x1, x0, x14, lsl #16
 688:	ca120032 	eor	x18, x1, x18
 68c:	8b0d024d 	add	x13, x18, x13
 690:	3607fc80 	tbz	w0, #0, 620 <flow_record_field_scan_xdp+0x60>
 694:	79402def 	ldrh	w15, [x15, #22]
 698:	8b0f022f 	add	x15, x17, x15
 69c:	ca0d01ed 	eor	x13, x15, x13
 6a0:	17ffffe4 	b	630 <flow_record_field_scan_xdp+0x70>
 6a4:	2a1f03e0 	mov	w0, wzr
 6a8:	d65f03c0 	ret
 6ac:	d348fdc9 	lsr	x9, x14, #8
 6b0:	52800040 	mov	w0, #0x2                   	// #2
 6b4:	3900010d 	strb	w13, [x8]
 6b8:	39000509 	strb	w9, [x8, #1]
 6bc:	d350fdc9 	lsr	x9, x14, #16
 6c0:	39000909 	strb	w9, [x8, #2]
 6c4:	d358fdc9 	lsr	x9, x14, #24
 6c8:	39000d09 	strb	w9, [x8, #3]
 6cc:	d360fdc9 	lsr	x9, x14, #32
 6d0:	39001109 	strb	w9, [x8, #4]
 6d4:	d368fdc9 	lsr	x9, x14, #40
 6d8:	39001509 	strb	w9, [x8, #5]
 6dc:	d370fdc9 	lsr	x9, x14, #48
 6e0:	39001909 	strb	w9, [x8, #6]
 6e4:	d378fdc9 	lsr	x9, x14, #56
 6e8:	39001d09 	strb	w9, [x8, #7]
 6ec:	d65f03c0 	ret

Disassembly of section .fini:

00000000000006f0 <_fini>:
 6f0:	d503201f 	nop
 6f4:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 6f8:	910003fd 	mov	x29, sp
 6fc:	a8c17bfd 	ldp	x29, x30, [sp], #16
 700:	d65f03c0 	ret
```

## Original Kernel JIT ASM
```asm
not captured
```

## llvmbpf JIT ASM
```asm
not captured
```
