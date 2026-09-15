# packet_record_bounds_window

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
 494:	f00000f0 	adrp	x16, 1f000 <__FRAME_END__+0x1e850>
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
 4e0:	f00000e0 	adrp	x0, 1f000 <__FRAME_END__+0x1e850>
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
 518:	f00000e1 	adrp	x1, 1f000 <__FRAME_END__+0x1e850>
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
 554:	f00000e2 	adrp	x2, 1f000 <__FRAME_END__+0x1e850>
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
 58c:	f00000e0 	adrp	x0, 1f000 <__FRAME_END__+0x1e850>
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

00000000000005e0 <packet_record_bounds_window_xdp>:
 5e0:	a9402408 	ldp	x8, x9, [x0]
 5e4:	aa0803ea 	mov	x10, x8
 5e8:	eb09015f 	cmp	x10, x9
 5ec:	54000069 	b.ls	5f8 <packet_record_bounds_window_xdp+0x18>  // b.plast
 5f0:	2a1f03e0 	mov	w0, wzr
 5f4:	d65f03c0 	ret
 5f8:	9100214b 	add	x11, x10, #0x8
 5fc:	910c414c 	add	x12, x10, #0x310
 600:	eb09017f 	cmp	x11, x9
 604:	fa499182 	ccmp	x12, x9, #0x2, ls	// ls = plast
 608:	54000069 	b.ls	614 <packet_record_bounds_window_xdp+0x34>  // b.plast
 60c:	2a1f03e0 	mov	w0, wzr
 610:	d65f03c0 	ret
 614:	29412d49 	ldp	w9, w11, [x10, #8]
 618:	7100813f 	cmp	w9, #0x20
 61c:	7a580960 	ccmp	w11, #0x18, #0x0, eq	// eq = none
 620:	54000060 	b.eq	62c <packet_record_bounds_window_xdp+0x4c>  // b.none
 624:	2a1f03e0 	mov	w0, wzr
 628:	d65f03c0 	ret
 62c:	d29fb26c 	mov	x12, #0xfd93                	// #64915
 630:	aa1f03e9 	mov	x9, xzr
 634:	9100514a 	add	x10, x10, #0x14
 638:	5280600b 	mov	w11, #0x300                 	// #768
 63c:	f2accb2c 	movk	x12, #0x6659, lsl #16
 640:	f2dfd70c 	movk	x12, #0xfeb8, lsl #32
 644:	f2fadd0c 	movk	x12, #0xd6e8, lsl #48
 648:	14000006 	b	660 <packet_record_bounds_window_xdp+0x80>
 64c:	91002129 	add	x9, x9, #0x8
 650:	d100616b 	sub	x11, x11, #0x18
 654:	9100614a 	add	x10, x10, #0x18
 658:	f104013f 	cmp	x9, #0x100
 65c:	54000480 	b.eq	6ec <packet_record_bounds_window_xdp+0x10c>  // b.none
 660:	385fc14d 	ldurb	w13, [x10, #-4]
 664:	5280030e 	mov	w14, #0x18                  	// #24
 668:	b34005ae 	bfxil	x14, x13, #0, #2
 66c:	eb0e017f 	cmp	x11, x14
 670:	54fffee3 	b.cc	64c <packet_record_bounds_window_xdp+0x6c>  // b.lo, b.ul, b.last
 674:	2940414f 	ldp	w15, w16, [x10]
 678:	79402140 	ldrh	w0, [x10, #16]
 67c:	924005ad 	and	x13, x13, #0x3
 680:	8b0c01ec 	add	x12, x15, x12
 684:	29414951 	ldp	w17, w18, [x10, #8]
 688:	385fd14e 	ldurb	w14, [x10, #-3]
 68c:	8b00020f 	add	x15, x16, x0
 690:	aa108230 	orr	x16, x17, x16, lsl #32
 694:	aa118251 	orr	x17, x18, x17, lsl #32
 698:	720001df 	tst	w14, #0x1
 69c:	8b0f018c 	add	x12, x12, x15
 6a0:	7940254f 	ldrh	w15, [x10, #18]
 6a4:	8b100190 	add	x16, x12, x16
 6a8:	ca11018c 	eor	x12, x12, x17
 6ac:	9a920251 	csel	x17, x18, x18, eq	// eq = none
 6b0:	9a8c020c 	csel	x12, x16, x12, eq	// eq = none
 6b4:	120009d0 	and	w16, w14, #0x7
 6b8:	d37e09ce 	ubfiz	x14, x14, #2, #3
 6bc:	9ace222e 	lsl	x14, x17, x14
 6c0:	4a0d020d 	eor	w13, w16, w13
 6c4:	ca0e018c 	eor	x12, x12, x14
 6c8:	927d052e 	and	x14, x9, #0x18
 6cc:	9ace21ee 	lsl	x14, x15, x14
 6d0:	8b0e018c 	add	x12, x12, x14
 6d4:	110005ae 	add	w14, w13, #0x1
 6d8:	520015ad 	eor	w13, w13, #0x3f
 6dc:	9ace218e 	lsl	x14, x12, x14
 6e0:	9acd258c 	lsr	x12, x12, x13
 6e4:	aa0c01cc 	orr	x12, x14, x12
 6e8:	17ffffd9 	b	64c <packet_record_bounds_window_xdp+0x6c>
 6ec:	52800040 	mov	w0, #0x2                   	// #2
 6f0:	f900010c 	str	x12, [x8]
 6f4:	d65f03c0 	ret

Disassembly of section .fini:

00000000000006f8 <_fini>:
 6f8:	d503201f 	nop
 6fc:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 700:	910003fd 	mov	x29, sp
 704:	a8c17bfd 	ldp	x29, x30, [sp], #16
 708:	d65f03c0 	ret
```

## Original Kernel JIT ASM
```asm
not captured
```

## llvmbpf JIT ASM
```asm
not captured
```
