.intel_syntax noprefix
.text
.global entry
entry:
mov rsi, QWORD PTR [rdi]
mov rax, QWORD PTR [rdi+8]
lea rdx, [rsi+4]
cmp rdx, rax
ja 1f
mov rdi, QWORD PTR [rip+neg_map@GOTPCREL]
call bpf_map_lookup_elem
mov rax, QWORD PTR [rax]
ret
1: mov eax, 0
ret
