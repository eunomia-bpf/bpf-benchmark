.text
.macro begin name
.globl \name
.type \name,@function
\name:
.endm
.macro lookup name
.Lload_\name:
    movslq (%r15,%rcx,4),%rax
    add %r15,%rax
    jmp *%rax
.Lcase_\name:
.endm
.macro finish name
    xor %eax,%eax
    ret
.size \name,.-\name
.pushsection .rodata.\name
.Ltable_\name:
    .long .Lcase_\name - .Ltable_\name
.popsection
.endm

begin hoisted_loop
    lea .Ltable_hoisted_loop(%rip),%r15
    mov $0,%ecx
    mov $2,%edx
lookup hoisted_loop
    sub $1,%edx
    jne .Lload_hoisted_loop
finish hoisted_loop

begin changed_base
    lea .Ltable_changed_base(%rip),%r15
    mov $0,%ecx
    test %edi,%edi
    jne .Lclobber
lookup changed_base
    xor %eax,%eax
    ret
.Lclobber:
    mov $0,%r15
    jmp .Lload_changed_base
.size changed_base,.-changed_base
.pushsection .rodata.changed_base
.Ltable_changed_base:
    .long .Lcase_changed_base - .Ltable_changed_base
.popsection

begin bypassed_base
    mov $0,%ecx
    test %edi,%edi
    je .Lload_bypassed_base
    lea .Ltable_bypassed_base(%rip),%r15
    mov $1,%edx
lookup bypassed_base
finish bypassed_base

begin observed_base
    lea .Ltable_observed_base(%rip),%r15
    mov %r15,(%rdi)
    mov $0,%ecx
lookup observed_base
finish observed_base

begin live_flags
    lea .Ltable_live_flags(%rip),%r15
    mov $0,%ecx
lookup live_flags
    setc %al
    movzbl %al,%eax
    ret
.size live_flags,.-live_flags
.pushsection .rodata.live_flags
.Ltable_live_flags:
    .long .Lcase_live_flags - .Ltable_live_flags
.popsection

begin redirected_base
    mov $0,%ecx
    jmp .Lcallsite
.Ldefine:
    lea .Ltable_redirected_base(%rip),%r15
    jmp .Lload_redirected_base
.Lcallsite:
    call redirect_wrapper
lookup redirected_base
finish redirected_base
.type redirect_wrapper,@function
redirect_wrapper:
    call skip_wrapper
    jmp .Ldefine
.size redirect_wrapper,.-redirect_wrapper
.type skip_wrapper,@function
skip_wrapper:
    add $8,%rsp
    ret
.size skip_wrapper,.-skip_wrapper

begin callee_changes_base
    lea .Ltable_callee_changes_base(%rip),%r15
    call change_base
    mov $0,%ecx
lookup callee_changes_base
finish callee_changes_base
.type change_base,@function
change_base:
    mov $0,%r15
    ret
.size change_base,.-change_base

begin shared_base
    mov $0,%ecx
    lea .Lshared_table(%rip),%r15
    movslq (%r15,%rcx,4),%rax
    add %r15,%rax
    jmp *%rax
.Lshared_first:
    mov $1,%ecx
    movslq (%r15,%rcx,4),%rax
    add %r15,%rax
    jmp *%rax
.Lshared_second:
    xor %eax,%eax
    ret
.size shared_base,.-shared_base
.pushsection .rodata.shared_base
.Lshared_table:
    .long .Lshared_first - .Lshared_table
    .long .Lshared_second - .Lshared_table
.popsection
.section .note.GNU-stack,"",@progbits
