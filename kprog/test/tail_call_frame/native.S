.intel_syntax noprefix
.text
.global entry
.type entry,@function
entry:
sub rsp,24
mov QWORD PTR [rsp],7
mov rax,QWORD PTR tail_counter_value@GOTPCREL[rip]
add QWORD PTR [rax],1
mov rsi,QWORD PTR tail_jumps@GOTPCREL[rip]
xor edx,edx
mov eax,12
call rax
mov eax,DWORD PTR [rsp]
cmp eax,7
sete al
movzx eax,al
add eax,eax
add rsp,24
ret
.size entry,.-entry
.section .note.GNU-stack,"",@progbits
