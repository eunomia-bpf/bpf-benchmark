.intel_syntax noprefix
.text
.macro spill name, escaped
.globl \name
.type \name,@function
\name:
    sub rsp, 64
.if \escaped
    lea rcx, [rsp+16]
    mov QWORD PTR [rdi], rcx
.endif
    mov eax, esi
    mov al, 5
    mov DWORD PTR [rsp+16], eax
    xor eax, eax
    mov esi, DWORD PTR [rsp+16]
    mov BYTE PTR [rsp+24], sil
.if \escaped
    mov rcx, QWORD PTR [rdi]
    mov eax, DWORD PTR [rcx]
.else
    movzx eax, BYTE PTR [rsp+24]
.endif
    add rsp, 64
    ret
.size \name, .-\name
.endm
spill escaped_before, 1
spill private_only, 0
.section .note.GNU-stack,"",@progbits
