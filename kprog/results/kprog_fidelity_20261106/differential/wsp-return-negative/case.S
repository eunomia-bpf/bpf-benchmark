.text
.global entry
.type entry,%function
entry:
    mov w0, #0
    mov wsp, w0
    mov w0, #2
    ret
.size entry,.-entry
.section .note.GNU-stack,"",%progbits
