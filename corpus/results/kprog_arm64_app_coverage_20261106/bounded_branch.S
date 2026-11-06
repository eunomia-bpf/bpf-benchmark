.text
.global bounded_branch
.type bounded_branch,%function
bounded_branch:
    ldp x1, x2, [x0]
    add x3, x1, #9
    cmp x3, x2
    b.hi short_packet
    ldrb w12, [x1, #8]
    adr x8, target_one
    adr x9, target_two
    cmp w12, #0
    csel x8, x8, x9, eq
    br x8
target_one:
    mov x0, #41
    b store_result
target_two:
    mov x0, #42
store_result:
    str x0, [x1]
    mov w0, #2
    ret
short_packet:
    mov w0, #0
    ret
.size bounded_branch, .-bounded_branch
