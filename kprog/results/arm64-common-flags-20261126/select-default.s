	.text
	.file	"select.c"
	.globl	entry                           // -- Begin function entry
	.p2align	4
	.type	entry,@function
entry:                                  // @entry
	.cfi_startproc
// %bb.0:
	ldr	x8, [x0, #248]
	mov	w9, #31                         // =0x1f
	mov	w10, #63                        // =0x3f
	mov	w11, #47                        // =0x2f
	cmp	x8, x1
	csel	x9, x10, x9, lo
	mov	w10, #15                        // =0xf
	cset	w8, lo
	csel	x10, x11, x10, lo
	ubfiz	x8, x8, #5, #32
	ldr	x11, [x0, x10, lsl #3]
	cmp	x11, x1
	csinc	x8, x8, x10, hs
	csel	x9, x9, x10, lo
	add	x10, x8, x9
	lsr	x10, x10, #1
	ldr	x11, [x0, x10, lsl #3]
	cmp	x11, x1
	csinc	x8, x8, x10, hs
	csel	x9, x9, x10, lo
	add	x10, x8, x9
	lsr	x10, x10, #1
	ldr	x11, [x0, x10, lsl #3]
	cmp	x11, x1
	csinc	x8, x8, x10, hs
	csel	x9, x9, x10, lo
	add	x10, x8, x9
	lsr	x10, x10, #1
	ldr	x11, [x0, x10, lsl #3]
	cmp	x11, x1
	csinc	x8, x8, x10, hs
	csel	x9, x9, x10, lo
	add	x9, x8, x9
	lsr	x9, x9, #1
	ldr	x10, [x0, x9, lsl #3]
	cmp	x10, x1
	csinc	x0, x8, x9, hs
	ret
.Lfunc_end0:
	.size	entry, .Lfunc_end0-entry
	.cfi_endproc
                                        // -- End function
	.ident	"Ubuntu clang version 18.1.3 (1ubuntu1)"
	.section	".note.GNU-stack","",@progbits
	.addrsig
