.intel_syntax noprefix
.text
.global entry
.type entry,@function
entry:
push rbp
mov rbp,rsp
push r15
push r14
push r13
push r12
push rbx
sub rsp,216
mov r12,rdi
mov DWORD PTR [rsp],0
mov QWORD PTR [rsp+8],7
mov rdi,QWORD PTR tail_counter@GOTPCREL[rip]
lea rsi,[rsp]
call bpf_map_lookup_elem@PLT
test rax,rax
je 1f
add QWORD PTR [rax],1
mov rdi,r12
mov rsi,QWORD PTR tail_jumps@GOTPCREL[rip]
xor edx,edx
mov r11d,12
call r11
1:
mov eax,DWORD PTR [rsp+8]
cmp eax,7
sete al
movzx eax,al
add eax,eax
add rsp,216
pop rbx
pop r12
pop r13
pop r14
pop r15
pop rbp
ret
.size entry,.-entry
.section .note.GNU-stack,"",@progbits
