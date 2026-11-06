.intel_syntax noprefix
.text
.global entry
entry:
mov rax, QWORD PTR [rsp-1024]
ret
