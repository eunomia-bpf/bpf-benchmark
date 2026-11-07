.intel_syntax noprefix
.text
.global observe_leave
.type observe_leave,@function
observe_leave:
push rbp
push rbx
push r12
push r13
push r14
push r15
mov [rip+saved_rsp],rsp
mov r15,rdi
push QWORD PTR [r15+128]
popfq
mov rax,[r15+0]
mov rcx,[r15+8]
mov rdx,[r15+16]
mov rbx,[r15+24]
mov rbp,[r15+40]
mov rsi,[r15+48]
mov rdi,[r15+56]
mov r8,[r15+64]
mov r9,[r15+72]
mov r10,[r15+80]
mov r11,[r15+88]
mov r12,[r15+96]
mov r13,[r15+104]
mov r14,[r15+112]
mov rsp,[r15+32]
mov r15,[r15+120]
.global leave_pc
leave_pc:
leave
.global leave_next
leave_next:
mov [rip+observed+0],rax
mov [rip+observed+8],rcx
mov [rip+observed+16],rdx
mov [rip+observed+24],rbx
mov [rip+observed+32],rsp
mov [rip+observed+40],rbp
mov [rip+observed+48],rsi
mov [rip+observed+56],rdi
mov [rip+observed+64],r8
mov [rip+observed+72],r9
mov [rip+observed+80],r10
mov [rip+observed+88],r11
mov [rip+observed+96],r12
mov [rip+observed+104],r13
mov [rip+observed+112],r14
mov [rip+observed+120],r15
mov rsp,[rip+saved_rsp]
pushfq
pop QWORD PTR [rip+observed+128]
pop r15
pop r14
pop r13
pop r12
pop rbx
pop rbp
ret
.section .note.GNU-stack,"",@progbits
