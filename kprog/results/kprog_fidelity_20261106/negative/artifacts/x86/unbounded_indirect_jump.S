.intel_syntax noprefix
.text
.global entry
entry:
mov rax, QWORD PTR [rdi]
jmp rax
