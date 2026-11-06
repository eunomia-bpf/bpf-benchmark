.intel_syntax noprefix
.text
.global entry
entry:
mov rax, QWORD PTR [rdi]
movzx eax, BYTE PTR [rax]
ret
