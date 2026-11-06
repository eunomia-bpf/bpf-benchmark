.intel_syntax noprefix
.text
.global entry
entry:
mov rax, QWORD PTR [rdi+8]
mov BYTE PTR [rax], 1
mov eax, 2
ret
