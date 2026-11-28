// AAPCS caller passes a frozen pointer, callee returns a different live pointer.
// The load destination differs from its base so normal address tracking applies.
.macro caller name, target
.global \name
.type \name, %function
\name:
 stp x29, x30, [sp, #-16]!
 mov x29, sp
 adrp x0, :got:frozen_word
 ldr x0, [x0, #:got_lo12:frozen_word]
 adrp x1, :got:mutable_word
 ldr x1, [x1, #:got_lo12:mutable_word]
 bl \target
 ldr w2, [x0]
 mov w0, w2
 ldp x29, x30, [sp], #16
 ret
.size \name, .-\name
.endm
.text
caller entry_reloc, pick_global
caller entry_local, pick_local
.type pick_local, %function
pick_local:
 mov x0, x1
 ret
.size pick_local, .-pick_local
.section .text.pick, "ax"
.global pick_global
.type pick_global, %function
pick_global:
 mov x0, x1
 ret
.size pick_global, .-pick_global
