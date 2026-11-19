.text
.globl locked_inc64
.type locked_inc64,@function
locked_inc64:
    lock incq (%rdi)
    ret
.size locked_inc64,.-locked_inc64
.globl plain_inc64
.type plain_inc64,@function
plain_inc64:
    incq (%rdi)
    ret
.size plain_inc64,.-plain_inc64
.globl locked_inc32
.type locked_inc32,@function
locked_inc32:
    lock incl (%rdi)
    ret
.size locked_inc32,.-locked_inc32
.globl plain_inc32
.type plain_inc32,@function
plain_inc32:
    incl (%rdi)
    ret
.size plain_inc32,.-plain_inc32
.globl locked_add64
.type locked_add64,@function
locked_add64:
    lock addq %rsi,(%rdi)
    ret
.size locked_add64,.-locked_add64
.globl plain_add64
.type plain_add64,@function
plain_add64:
    addq %rsi,(%rdi)
    ret
.size plain_add64,.-plain_add64
.globl locked_addimm64
.type locked_addimm64,@function
locked_addimm64:
    lock addq $7,(%rdi)
    ret
.size locked_addimm64,.-locked_addimm64
.globl plain_addimm64
.type plain_addimm64,@function
plain_addimm64:
    addq $7,(%rdi)
    ret
.size plain_addimm64,.-plain_addimm64
.section .note.GNU-stack,"",@progbits
