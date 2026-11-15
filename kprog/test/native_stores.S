/* Both MOV store forms, every width, and nonzero indexed displacements. */
.intel_syntax noprefix
.text
.macro store_case name, width, immediate, indexed
.global \name
.type \name,@function
\name:
    mov rdx,QWORD PTR [rdi]
.if \indexed
    mov rsi,QWORD PTR [rdi+8]
.else
    mov esi,0
.endif
    cmp rdx,1
.if \width == 8
.if \immediate
    mov QWORD PTR [rdi+rsi*2+32],-0x1234567
.else
    mov QWORD PTR [rdi+rsi*2+32],rdx
.endif
.elseif \width == 4
.if \immediate
    mov DWORD PTR [rdi+rsi*2+32],0x87654321
.else
    mov DWORD PTR [rdi+rsi*2+32],edx
.endif
.elseif \width == 2
.if \immediate
    mov WORD PTR [rdi+rsi*2+32],0x8675
.else
    mov WORD PTR [rdi+rsi*2+32],dx
.endif
.else
.if \immediate
    mov BYTE PTR [rdi+rsi*2+32],0x85
.else
    mov BYTE PTR [rdi+rsi*2+32],dl
.endif
.endif
    setc r8b
    setz r9b
    sets r10b
    seto r11b
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
.irp width,1,2,4,8
    store_case store\width\()regflat,\width,0,0
    store_case store\width\()regindex,\width,0,1
    store_case store\width\()immflat,\width,1,0
    store_case store\width\()immindex,\width,1,1
.endr
.section .note.GNU-stack,"",@progbits
