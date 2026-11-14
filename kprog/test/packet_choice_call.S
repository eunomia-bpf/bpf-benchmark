/* Seed the callee-saved output register of the untied empty-asm fixture. */
.text
.globl run_packet_choice
.type run_packet_choice,@function
run_packet_choice:
    push %r12
    mov %rdi,%r11
    mov %rsi,%rdi
    mov %rdx,%r12
    call *%r11
    pop %r12
    ret
.size run_packet_choice,.-run_packet_choice
.section .note.GNU-stack,"",@progbits
