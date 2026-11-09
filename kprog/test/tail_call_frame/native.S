.intel_syntax noprefix
.text
.global entry
.type entry,@function
entry:
sub rsp,24
mov QWORD PTR [rsp+8],rdi
mov DWORD PTR [rsp],0
mov rsi,rsp
mov rdi,QWORD PTR tail_counter@GOTPCREL[rip]
mov eax,1
call rax
 test rax,rax
je 1f
add QWORD PTR [rax],1
mov rdi,QWORD PTR [rsp+8]
mov rsi,QWORD PTR tail_jumps@GOTPCREL[rip]
xor edx,edx
mov eax,12
call rax
1:
mov eax,2
add rsp,24
ret
.size entry,.-entry
.section .note.GNU-stack,"",@progbits
