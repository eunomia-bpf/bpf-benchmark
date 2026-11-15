/* A compiler-like relative table whose index is overwritten before dispatch. */
.intel_syntax noprefix
.text
.global scheduled_table
.type scheduled_table,@function
scheduled_table:
    mov eax,DWORD PTR [rdi]
    and eax,7
    cmp eax,3
    ja .Ldefault
    lea rcx,[rip+.Ltable]
    movsxd rdx,DWORD PTR [rcx+rax*4]
    add rdx,rcx
#if defined(SCHEDULE_WRITE_TARGET)
    mov edx,1
#elif defined(SCHEDULE_READ_FLAGS)
    adc esi,0
#endif
    mov eax,1
    mov esi,9
    jmp rdx
.Lcase0:
    add eax,10
    jmp .Ldone
.Lcase1:
    add eax,20
    jmp .Ldone
.Lcase2:
    add eax,30
    jmp .Ldone
.Lcase3:
    add eax,40
.Ldone:
    add eax,esi
    xor ecx,ecx
    xor edx,edx
    ret
.Ldefault:
    xor eax,eax
    ret
.size scheduled_table,.-scheduled_table
.section .rodata
.p2align 2
.Ltable:
    .long .Lcase0-.Ltable
    .long .Lcase1-.Ltable
    .long .Lcase2-.Ltable
    .long .Lcase3-.Ltable
.section .note.GNU-stack,"",@progbits
