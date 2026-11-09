.intel_syntax noprefix
.text
.global entry
.type entry,@function
entry:
lea r11, [rip+subreturn]
call r11
lea r11, [rip+1f]
jmp r11
1:
sub rsp,24
mov QWORD PTR [rsp],7
mov rax,QWORD PTR tail_counter_value@GOTPCREL[rip]
add QWORD PTR [rax],1
mov rsi,QWORD PTR tail_jumps@GOTPCREL[rip]
xor edx,edx
mov r11d,12
call r11
mov eax,DWORD PTR [rsp]
cmp eax,7
sete al
movzx eax,al
add eax,eax
add rsp,24
ret
.size entry,.-entry
.type subreturn,@function
subreturn:
mov eax,0
ret
.size subreturn,.-subreturn
.section .note.GNU-stack,"",@progbits
