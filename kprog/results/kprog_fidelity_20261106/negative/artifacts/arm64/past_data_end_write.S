.text
.global entry
entry:
ldr x1, [x0, #8]
mov w2, #1
strb w2, [x1]
mov w0, #2
ret
