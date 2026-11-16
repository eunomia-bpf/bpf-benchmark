/* The real producer derives both the frame bound and named fact cells. */
#ifndef FRAME
#error FRAME must select the native stack frame
#endif
.intel_syntax noprefix
.text
.globl x86_stack_profile
.type x86_stack_profile,@function
x86_stack_profile:
    sub rsp, FRAME
    lea rax, [rsp+16]
    mov [rsp], rax
    mov [rsp+FRAME-8], rax
    mov qword ptr [rsp], 0
    mov rax, [rsp+FRAME-8]
    mov [rsp+8], rax
    mov qword ptr [rsp+FRAME-8], 0
    mov rax, [rsp+8]
    mov rcx, rax
    shr rcx, 32
    xor eax, ecx
    add rsp, FRAME
    ret
.size x86_stack_profile, .-x86_stack_profile
.section .note.GNU-stack,"",@progbits
