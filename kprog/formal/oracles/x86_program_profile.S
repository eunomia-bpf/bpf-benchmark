/* Two real return sites share a helper-calling subroutine. */
.intel_syntax noprefix
.text
.globl x86_program_profile
.type x86_program_profile,@function
x86_program_profile:
    push rbx
    sub rsp, 32
    lea rbx, [rsp+16]
    call x86_program_inner
    mov [rsp], rax
    call x86_program_inner
    mov rcx, [rsp]
    xor rax, rcx
    mov rcx, rbx
    xor rax, rcx
    mov rcx, rax
    shr rcx, 32
    xor eax, ecx
    add rsp, 32
    pop rbx
    ret
.size x86_program_profile, .-x86_program_profile
.type x86_program_inner,@function
x86_program_inner:
    call bpf_ktime_get_ns
    ret
.size x86_program_inner, .-x86_program_inner
.section .note.GNU-stack,"",@progbits
