.intel_syntax noprefix
.text
.global entry
.type entry,@function
entry:
endbr64
lea r11, [rip+subreturn]
call __x86_indirect_thunk_r11
lea r11, [rip+1f]
jmp __x86_indirect_thunk_r11
1: endbr64
sub rsp,24
mov QWORD PTR [rsp],7
mov rax,QWORD PTR tail_counter_value@GOTPCREL[rip]
add QWORD PTR [rax],1
mov rsi,QWORD PTR tail_jumps@GOTPCREL[rip]
xor edx,edx
mov r11d,12
call __x86_indirect_thunk_r11
mov eax,DWORD PTR [rsp]
cmp eax,7
sete al
movzx eax,al
add eax,eax
add rsp,24
jmp __x86_return_thunk
.size entry,.-entry
.type subreturn,@function
subreturn:
endbr64
mov eax,0
jmp __x86_return_thunk
.size subreturn,.-subreturn
.section .note.GNU-stack,"",@progbits
