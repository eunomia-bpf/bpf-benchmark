/* Distinct operand/count lanes, both value halves and all defined flags. */
.intel_syntax noprefix
.text
.macro bmi2_case name, op, width, memory
.global \name
.type \name,@function
\name:
    mov rdx,QWORD PTR [rdi]
    mov rcx,QWORD PTR [rdi+8]
.if \width == 64
    cmp rdx,1
.if \memory
    \op rax,QWORD PTR [rdi],rcx
.else
    \op rax,rdx,rcx
.endif
.else
    cmp edx,1
.if \memory
    \op eax,DWORD PTR [rdi],ecx
.else
    \op eax,edx,ecx
.endif
.endif
    setc r8b
    setz r9b
    sets r10b
    seto r11b
    cmp DWORD PTR [rdi+16],2
    je .Lflags\@
    cmp DWORD PTR [rdi+16],1
    jne .Ldone\@
    shr rax,32
.Ldone\@:
    ret
.Lflags\@:
    movzx eax,r8b
    movzx ecx,r9b
    shl ecx,1
    or eax,ecx
    movzx ecx,r10b
    shl ecx,2
    or eax,ecx
    movzx ecx,r11b
    shl ecx,3
    or eax,ecx
    ret
.size \name,.-\name
.endm
.irp op,shlx,shrx,sarx,bzhi
    bmi2_case \op\()64reg,\op,64,0
    bmi2_case \op\()64mem,\op,64,1
    bmi2_case \op\()32reg,\op,32,0
    bmi2_case \op\()32mem,\op,32,1
.endr
.section .note.GNU-stack,"",@progbits
