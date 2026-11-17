        .section .rodata.str1.1,"aMS",@progbits,1
        .globl in_range
        .type in_range, @object
        .size in_range, 8
in_range:
        .asciz "abcdefg"
        .globl beyond
        .type beyond, @object
        .size beyond, 8
beyond:
        .asciz "hijklmn"
        .globl wrapped
        .type wrapped, @object
        .size wrapped, 0xfffffffffffffffc
wrapped:
        .asciz "wxyz"
        .text
        .globl entry
        .type entry, @function
entry:
        ret
        .size entry, 1
