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
.section .note.GNU-stack,"",@progbits
