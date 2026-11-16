.text
.globl entry
.type entry,@function
entry:
    call choose
    ret
.size entry,.-entry
.p2align 4
.globl choose
.type choose,@function
choose:
    test %edx,%edx
    je selected
    mov $11,%eax
    ret
.size choose,.-choose
.p2align 4
.type selected,@function
selected:
    mov $22,%eax
    ret
.size selected,.-selected
.section .note.GNU-stack,"",@progbits
