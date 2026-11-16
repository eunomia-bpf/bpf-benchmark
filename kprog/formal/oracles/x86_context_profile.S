/* Native pointer-width context offsets from the active x86 ABI.
 * The real parser renders XDP and SKB entry bindings from this one program. */
#if SKB
#define ENTRY x86_context_skb
#define DATA 208
#define END 80
#define EXTRA 48
#define HELPER bpf_skb_pull_data
#else
#define ENTRY x86_context_xdp
#define DATA 0
#define END 8
#define EXTRA 16
#define HELPER bpf_xdp_adjust_head
#endif
.intel_syntax noprefix
.text
.globl ENTRY
.type ENTRY,@function
ENTRY:
    push rbx
    push r12
    push r13
    push r14
    sub rsp,16
    mov rbx,rdi
    mov r12,[rdi+DATA]
    mov r13,[rdi+END]
    mov r14,[rdi+EXTRA]
    xor esi,esi
    call HELPER
    xor r12,rax
    mov rdi,rbx
    mov rax,[rdi+DATA]
    xor rax,r12
    mov rcx,[rdi+END]
    xor rax,r13
    xor rax,rcx
    mov rcx,[rdi+EXTRA]
    xor rax,r14
    xor rax,rcx
    mov rcx,rax
    shr rcx,32
    xor eax,ecx
    add rsp,16
    pop r14
    pop r13
    pop r12
    pop rbx
    ret
.size ENTRY,.-ENTRY
.section .note.GNU-stack,"",@progbits
