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
.p2align 4
.globl choose_near
.type choose_near,@function
choose_near:
    test %edx,%edx
    .byte 0x0f,0x84
    .long selected-.-4
    mov $11,%eax
    ret
.size choose_near,.-choose_near
.section .text.reloc,"ax",@progbits
.globl choose_reloc
.type choose_reloc,@function
choose_reloc:
    test %edx,%edx
    je selected
    mov $11,%eax
    ret
.size choose_reloc,.-choose_reloc
.section .note.GNU-stack,"",@progbits
