/* Scalar data and another root's relative code table share .rodata. */
.intel_syntax noprefix
.text
.global unrelated_switch
.type unrelated_switch,@function
unrelated_switch:
    mov eax,DWORD PTR [rdi]
    and eax,3
    lea rdx,[rip+.Lcodes]
    movsxd rax,DWORD PTR [rdx+rax*4]
    add rax,rdx
    jmp rax
.Lcase0: mov eax,11
    ret
.Lcase1: mov eax,22
    ret
.Lcase2: mov eax,33
    ret
.Lcase3: mov eax,44
    ret
.size unrelated_switch,.-unrelated_switch
.macro scalar name, displacement, mask
.global \name
.type \name,@function
\name:
    mov rcx,QWORD PTR [rdi]
    and ecx,\mask
    lea rdx,[rip+.Lvalues+\displacement]
    mov eax,DWORD PTR [rdx+rcx*4]
    ret
.size \name,.-\name
.endm
scalar scalar_lookup,0,15
scalar scalar_interior_lookup,4,7
.section .rodata
.Lcodes:
    .long .Lcase0-.Lcodes,.Lcase1-.Lcodes,.Lcase2-.Lcodes,.Lcase3-.Lcodes
.local scalar_values
.type scalar_values,@object
scalar_values:
.Lvalues:
.set i,0
.rept 16
    .long 0x12340000+i*0x101
    .set i,i+1
.endr
.size scalar_values,.-scalar_values
.local scalar_values_alias
.type scalar_values_alias,@object
.set scalar_values_alias,scalar_values+4
.size scalar_values_alias,16
.section .note.GNU-stack,"",@progbits
