.intel_syntax noprefix
.text
.global entry
entry:
mov rax, QWORD PTR [rdi+8]
movzx eax, BYTE PTR [rax]
ret
