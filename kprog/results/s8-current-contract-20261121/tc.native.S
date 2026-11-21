.intel_syntax noprefix
.text
.global entry
.type entry,@function
entry:
push rbx
mov rbx,rdi
sub rsp,24
mov DWORD PTR [rsp],0
mov QWORD PTR [rsp+16],7
mov rdi,QWORD PTR tail_counter@GOTPCREL[rip]
mov rsi,rsp
mov eax,1
call rax
test rax,rax
je done
add QWORD PTR [rax],1
mov rdi,rbx
mov rsi,QWORD PTR tail_jumps@GOTPCREL[rip]
xor edx,edx
mov eax,12
call rax
done:
mov eax,DWORD PTR [rsp+16]
cmp eax,7
sete al
movzx eax,al
add eax,eax
add rsp,24
pop rbx
ret
.size entry,.-entry
.section .note.GNU-stack,"",@progbits
