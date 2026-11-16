/* Real relocated readonly bytes, including overlapping and unaligned widths. */
.intel_syntax noprefix
.text
.globl x86_readonly_profile
.type x86_readonly_profile,@function
x86_readonly_profile:
    push rbx
    lea rax,[rip+readonly_bytes]
    xor esi,esi
    mov rcx,[rax+rsi]
    movzx edx,WORD PTR [rax+rsi+7]
    xor rcx,rdx
    movzx edx,BYTE PTR [rax+rsi+15]
    xor rcx,rdx
    mov edx,DWORD PTR [rax+rsi+3]
    xor rcx,rdx
    mov rax,rcx
    shr rcx,32
    xor eax,ecx
    pop rbx
    ret
.size x86_readonly_profile,.-x86_readonly_profile
.section .rodata
.p2align 4
.type readonly_bytes,@object
readonly_bytes:
.byte 0x12,0x83,0xfe,0x45,0x67,0x89,0xab,0xcd,0xef,0x20,0x31,0x42,0x53,0x64,0x75,0x96
.size readonly_bytes,.-readonly_bytes
.section .note.GNU-stack,"",@progbits
