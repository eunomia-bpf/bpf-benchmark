.text
.global bounded_dispatch
.type bounded_dispatch,%function
bounded_dispatch:
    stp x19, x30, [sp, #-16]!
    ldr x19, [x0]
    ldr x10, [x0, #8]
    add x11, x19, #9
    cmp x11, x10
    b.hi short_packet
    ldrb w12, [x19, #8]
    adr x8, target_one
    adr x9, target_two
    cmp w12, #0
    csel x8, x8, x9, eq
    blr x8
    str x0, [x19]
    mov w0, #2
    ldp x19, x30, [sp], #16
    ret
short_packet:
    mov w0, #0
    ldp x19, x30, [sp], #16
    ret
target_one:
    mov x0, #41
    ret
target_two:
    // A nested indirect call must restore the caller's actual X30.
    stp x20, x30, [sp, #-16]!
    adr x20, target_one
    blr x20
    add x0, x0, #1
    ldp x20, x30, [sp], #16
    ret
.size bounded_dispatch, .-bounded_dispatch
