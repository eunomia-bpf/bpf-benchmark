.text
.global entry
entry:
ldr x1, [x0, #8]
ldrb w0, [x1]
ret
