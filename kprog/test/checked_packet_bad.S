.text
.global packet_bad
.type packet_bad,@function
packet_bad:
    mov 0x100000(%rdi),%eax
    ret
.size packet_bad,.-packet_bad
.section .note.GNU-stack,"",@progbits
