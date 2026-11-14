.text
.globl entry
.type entry,@function
entry:
    testl %edi,%edi
    je .Lordinary
    jmp leaf@PLT
.Lordinary:
    pushq %rax
    call nested@PLT
    popq %rcx
    addl $2,%eax
    ret
.size entry,.-entry

.globl nested
.type nested,@function
nested:
    jmp leaf@PLT
.size nested,.-nested

.globl leaf
.type leaf,@function
leaf:
    movq %rsp,%rax
    andl $15,%eax
    addl %edi,%eax
    ret
.size leaf,.-leaf

.globl global_tail
.type global_tail,@function
global_tail:
    jmp data_leaf@PLT
.size global_tail,.-global_tail

.globl data_leaf
.type data_leaf,@function
data_leaf:
    movq live_value@GOTPCREL(%rip),%rax
    movl (%rax),%eax
    ret
.size data_leaf,.-data_leaf

.globl external_entry
.type external_entry,@function
external_entry:
    jmp real_external@PLT
.size external_entry,.-external_entry

.globl plain_entry
.type plain_entry,@function
plain_entry:
    leal 10(%rdi),%eax
    ret
.size plain_entry,.-plain_entry

// Arguments seven and eight stay at the same stack offsets across the tail.
.globl stack_entry
.type stack_entry,@function
stack_entry:
    subq $24,%rsp
    movq $101,(%rsp)
    movq $211,8(%rsp)
    call stack_tail@PLT
    addq $24,%rsp
    ret
.size stack_entry,.-stack_entry
.globl stack_tail
.type stack_tail,@function
stack_tail:
    jmp stack_leaf@PLT
.size stack_tail,.-stack_tail
.globl stack_leaf
.type stack_leaf,@function
stack_leaf:
    movq 8(%rsp),%rax
    addq 16(%rsp),%rax
    addq %rdi,%rax
    ret
.size stack_leaf,.-stack_leaf

// A section-local assembler target has no ELF relocation. Place its callee
// before the entry to exercise a backward branch to source address zero.
.section .text.decoded,"ax",@progbits
.type decoded_leaf,@function
decoded_leaf:
    movl $23,%eax
    ret
.size decoded_leaf,.-decoded_leaf
.globl decoded_entry
.type decoded_entry,@function
decoded_entry:
    jmp decoded_leaf
.size decoded_entry,.-decoded_entry

.data
.globl live_value
.type live_value,@object
live_value: .long 37
.size live_value,4
.globl unused_value
.type unused_value,@object
unused_value: .long 91
.size unused_value,4
.section .note.GNU-stack,"",@progbits
