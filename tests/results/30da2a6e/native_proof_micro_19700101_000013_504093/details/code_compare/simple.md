# simple

## Original C
```c
not captured
```

## Native ASM
```asm
Disassembly of section .init:

0000000000000458 <_init>:
 458:	d503201f 	nop
 45c:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 460:	910003fd 	mov	x29, sp
 464:	94000013 	bl	4b0 <call_weak_fn>
 468:	a8c17bfd 	ldp	x29, x30, [sp], #16
 46c:	d65f03c0 	ret

Disassembly of section .plt:

0000000000000470 <.plt>:
 470:	a9bf7bf0 	stp	x16, x30, [sp, #-16]!
 474:	f00000f0 	adrp	x16, 1f000 <__FRAME_END__+0x1e958>
 478:	f947fe11 	ldr	x17, [x16, #4088]
 47c:	913fe210 	add	x16, x16, #0xff8
 480:	d61f0220 	br	x17
 484:	d503201f 	nop
 488:	d503201f 	nop
 48c:	d503201f 	nop

0000000000000490 <__cxa_finalize@plt>:
 490:	90000110 	adrp	x16, 20000 <__cxa_finalize@GLIBC_2.17>
 494:	f9400211 	ldr	x17, [x16]
 498:	91000210 	add	x16, x16, #0x0
 49c:	d61f0220 	br	x17

00000000000004a0 <__gmon_start__@plt>:
 4a0:	90000110 	adrp	x16, 20000 <__cxa_finalize@GLIBC_2.17>
 4a4:	f9400611 	ldr	x17, [x16, #8]
 4a8:	91002210 	add	x16, x16, #0x8
 4ac:	d61f0220 	br	x17

Disassembly of section .text:

00000000000004b0 <call_weak_fn>:
 4b0:	f00000e0 	adrp	x0, 1f000 <__FRAME_END__+0x1e958>
 4b4:	f947ec00 	ldr	x0, [x0, #4056]
 4b8:	b4000040 	cbz	x0, 4c0 <call_weak_fn+0x10>
 4bc:	17fffff9 	b	4a0 <__gmon_start__@plt>
 4c0:	d65f03c0 	ret
 4c4:	d503201f 	nop
 4c8:	d503201f 	nop
 4cc:	d503201f 	nop

00000000000004d0 <deregister_tm_clones>:
 4d0:	90000100 	adrp	x0, 20000 <__cxa_finalize@GLIBC_2.17>
 4d4:	91006000 	add	x0, x0, #0x18
 4d8:	90000101 	adrp	x1, 20000 <__cxa_finalize@GLIBC_2.17>
 4dc:	91006021 	add	x1, x1, #0x18
 4e0:	eb00003f 	cmp	x1, x0
 4e4:	540000c0 	b.eq	4fc <deregister_tm_clones+0x2c>  // b.none
 4e8:	f00000e1 	adrp	x1, 1f000 <__FRAME_END__+0x1e958>
 4ec:	f947e421 	ldr	x1, [x1, #4040]
 4f0:	b4000061 	cbz	x1, 4fc <deregister_tm_clones+0x2c>
 4f4:	aa0103f0 	mov	x16, x1
 4f8:	d61f0200 	br	x16
 4fc:	d65f03c0 	ret

0000000000000500 <register_tm_clones>:
 500:	90000100 	adrp	x0, 20000 <__cxa_finalize@GLIBC_2.17>
 504:	91006000 	add	x0, x0, #0x18
 508:	90000101 	adrp	x1, 20000 <__cxa_finalize@GLIBC_2.17>
 50c:	91006021 	add	x1, x1, #0x18
 510:	cb000021 	sub	x1, x1, x0
 514:	d37ffc22 	lsr	x2, x1, #63
 518:	8b810c41 	add	x1, x2, x1, asr #3
 51c:	9341fc21 	asr	x1, x1, #1
 520:	b40000c1 	cbz	x1, 538 <register_tm_clones+0x38>
 524:	f00000e2 	adrp	x2, 1f000 <__FRAME_END__+0x1e958>
 528:	f947f042 	ldr	x2, [x2, #4064]
 52c:	b4000062 	cbz	x2, 538 <register_tm_clones+0x38>
 530:	aa0203f0 	mov	x16, x2
 534:	d61f0200 	br	x16
 538:	d65f03c0 	ret
 53c:	d503201f 	nop

0000000000000540 <__do_global_dtors_aux>:
 540:	d503233f 	paciasp
 544:	a9be7bfd 	stp	x29, x30, [sp, #-32]!
 548:	910003fd 	mov	x29, sp
 54c:	f9000bf3 	str	x19, [sp, #16]
 550:	90000113 	adrp	x19, 20000 <__cxa_finalize@GLIBC_2.17>
 554:	39406260 	ldrb	w0, [x19, #24]
 558:	37000140 	tbnz	w0, #0, 580 <__do_global_dtors_aux+0x40>
 55c:	f00000e0 	adrp	x0, 1f000 <__FRAME_END__+0x1e958>
 560:	f947e800 	ldr	x0, [x0, #4048]
 564:	b4000080 	cbz	x0, 574 <__do_global_dtors_aux+0x34>
 568:	90000100 	adrp	x0, 20000 <__cxa_finalize@GLIBC_2.17>
 56c:	f9400800 	ldr	x0, [x0, #16]
 570:	97ffffc8 	bl	490 <__cxa_finalize@plt>
 574:	97ffffd7 	bl	4d0 <deregister_tm_clones>
 578:	52800020 	mov	w0, #0x1                   	// #1
 57c:	39006260 	strb	w0, [x19, #24]
 580:	f9400bf3 	ldr	x19, [sp, #16]
 584:	a8c27bfd 	ldp	x29, x30, [sp], #32
 588:	d50323bf 	autiasp
 58c:	d65f03c0 	ret

0000000000000590 <frame_dummy>:
 590:	d503245f 	bti	c
 594:	17ffffdb 	b	500 <register_tm_clones>
 598:	d503201f 	nop
 59c:	d503201f 	nop

00000000000005a0 <simple_xdp>:
 5a0:	a9402408 	ldp	x8, x9, [x0]
 5a4:	aa0803ea 	mov	x10, x8
 5a8:	eb09015f 	cmp	x10, x9
 5ac:	540000c8 	b.hi	5c4 <simple_xdp+0x24>  // b.pmore
 5b0:	9100214b 	add	x11, x10, #0x8
 5b4:	9101214a 	add	x10, x10, #0x48
 5b8:	eb09017f 	cmp	x11, x9
 5bc:	fa499142 	ccmp	x10, x9, #0x2, ls	// ls = plast
 5c0:	54000069 	b.ls	5cc <simple_xdp+0x2c>  // b.plast
 5c4:	2a1f03e0 	mov	w0, wzr
 5c8:	d65f03c0 	ret
 5cc:	528c29c9 	mov	w9, #0x614e                	// #24910
 5d0:	52800040 	mov	w0, #0x2                   	// #2
 5d4:	b800311f 	stur	wzr, [x8, #3]
 5d8:	39001d1f 	strb	wzr, [x8, #7]
 5dc:	79000109 	strh	w9, [x8]
 5e0:	52801789 	mov	w9, #0xbc                  	// #188
 5e4:	39000909 	strb	w9, [x8, #2]
 5e8:	d65f03c0 	ret

Disassembly of section .fini:

00000000000005ec <_fini>:
 5ec:	d503201f 	nop
 5f0:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 5f4:	910003fd 	mov	x29, sp
 5f8:	a8c17bfd 	ldp	x29, x30, [sp], #16
 5fc:	d65f03c0 	ret
```

## Original Kernel JIT ASM
```asm
not captured
```

## llvmbpf JIT ASM
```asm
not captured
```
