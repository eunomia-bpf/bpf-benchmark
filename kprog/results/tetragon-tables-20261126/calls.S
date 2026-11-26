.text
.macro entry name, callee
.globl \name
.type \name,@function
\name:
    call \callee
.endm
.macro end name
    ret
.size \name,.-\name
.endm

entry unused_local, quiet
    xor %eax,%eax
end unused_local
entry callee_reads_register, read_register
end callee_reads_register
entry caller_reads_register, quiet
    mov %rdx,%rax
end caller_reads_register
entry callee_reads_flags, read_flags
end callee_reads_flags
entry caller_reads_flags, quiet
    setc %al
    movzbl %al,%eax
end caller_reads_flags
entry unresolved_external, absent_function
end unresolved_external
entry known_helper, bpf_get_smp_processor_id
end known_helper
entry caller_discards_return, empty
    xor %eax,%eax
end caller_discards_return
entry caller_uses_return, empty
end caller_uses_return
entry callee_defines_return, quiet
end callee_defines_return
entry callee_partial_return, partial
end callee_partial_return
entry callee_conditional_return, conditional
end callee_conditional_return
entry callee_nested_return, nested
end callee_nested_return
entry callee_defines_flags, clear_flags
    setc %al
    movzbl %al,%eax
end callee_defines_flags
entry redirected_return, skip_return
    mov %rdx,%rax
end redirected_return
entry unresolved_return, lose_return
end unresolved_return

.type lose_return,@function
lose_return:
    movq $0,(%rsp)
    ret
.size lose_return,.-lose_return

.type partial,@function
partial:
    mov $0,%al
    ret
.size partial,.-partial
.type conditional,@function
conditional:
    test %edi,%edi
    jz 1f
    mov $0,%eax
1:  ret
.size conditional,.-conditional
.type nested,@function
nested:
    call quiet
    ret
.size nested,.-nested
.type clear_flags,@function
clear_flags:
    xor %eax,%eax
    ret
.size clear_flags,.-clear_flags
.type skip_return,@function
skip_return:
    add $8,%rsp
    xor %eax,%eax
    ret
.size skip_return,.-skip_return

.type empty,@function
empty:
    ret
.size empty,.-empty

.type quiet,@function
quiet:
    mov $0,%eax
    ret
.size quiet,.-quiet
.type read_register,@function
read_register:
    mov %r8,%rax
    ret
.size read_register,.-read_register
.type read_flags,@function
read_flags:
    setc %al
    movzbl %al,%eax
    ret
.size read_flags,.-read_flags

.macro table_entry name, external
.globl \name
.type \name,@function
\name:
    mov $0,%ecx
    lea .Ltable_\name(%rip),%r8
    movslq (%r8,%rcx,4),%rdx
    add %r8,%rdx
    jmp *%rdx
.Lcase_\name:
    .if \external
    mov %rdi,%rsp
    .endif
    mov $0,%eax
    ret
.size \name,.-\name
.pushsection .rodata
.Ltable_\name:
    .long .Lcase_\name - .Ltable_\name
.popsection
.endm
table_entry table_private_stack, 0
table_entry table_external_stack, 1
.text
.macro return_lea name, displacement
entry \name, callee_\name
    xor %eax,%eax
end \name
.type callee_\name,@function
callee_\name:
    mov (%rsp),%rax
    lea \displacement(%rax),%rax
    mov %rax,(%rsp)
    ret
.size callee_\name,.-callee_\name
.endm
return_lea return_lea_copy, 0
return_lea return_lea_forward, 1
return_lea return_lea_backward, -1
.section .note.GNU-stack,"",@progbits
