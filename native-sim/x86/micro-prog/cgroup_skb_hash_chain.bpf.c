#define X86_SIM_ENABLE_STACK 1
#include "../x86_sim_local_bpf.h"

SEC("cgroup_skb/egress")
int cgroup_skb_hash_chain_x86_sim_xdp(struct __sk_buff *ctx)
{
	X86_SIM_ENTRY_SKB(ctx);
x86_l_0:
	/* 0x0: mov    rsi,QWORD PTR [rdi+0x50] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_4:
	/* 0x4: mov    rax,QWORD PTR [rdi+0xd0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_b:
	/* 0xb: cmp    rax,rsi */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_e:
	/* 0xe: jbe    26 <cgroup_skb_hash_chain_prog+0x26> */
	X86_SIM_X86_JCC(X86_CC_BE, 0xe, 0x26, x86_l_26);
x86_l_10:
	/* 0x10: mov    DWORD PTR [rdi+0x30],0xffffffff */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 210453397503ULL);
x86_l_17:
	/* 0x17: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_19:
	/* 0x19: mov    edx,0xffffffff */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 4294967295ULL);
x86_l_1e:
	/* 0x1e: mov    DWORD PTR [rdi+0x34],edx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_21:
	/* 0x21: jmp    108 <cgroup_skb_hash_chain_prog+0x108> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_26:
	/* 0x26: lea    rcx,[rax+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a:
	/* 0x2a: cmp    rcx,rsi */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RCX, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_2d:
	/* 0x2d: ja     10 <cgroup_skb_hash_chain_prog+0x10> */
	X86_SIM_X86_JCC(X86_CC_A, 0x2d, 0x10, x86_l_10);
x86_l_2f:
	/* 0x2f: lea    rdx,[rax+0x50] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_33:
	/* 0x33: cmp    rdx,rsi */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_36:
	/* 0x36: ja     10 <cgroup_skb_hash_chain_prog+0x10> */
	X86_SIM_X86_JCC(X86_CC_A, 0x36, 0x10, x86_l_10);
x86_l_38:
	/* 0x38: mov    rsi,rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_3b:
	/* 0x3b: mov    r8,rdx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R8, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_3e:
	/* 0x3e: cmp    rsi,r8 */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RSI, X86_R8, X86_WIDTH_64, 0, 0);
x86_l_41:
	/* 0x41: ja     10 <cgroup_skb_hash_chain_prog+0x10> */
	X86_SIM_X86_JCC(X86_CC_A, 0x41, 0x10, x86_l_10);
x86_l_43:
	/* 0x43: add    rsi,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_47:
	/* 0x47: cmp    rsi,r8 */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RSI, X86_R8, X86_WIDTH_64, 0, 0);
x86_l_4a:
	/* 0x4a: ja     10 <cgroup_skb_hash_chain_prog+0x10> */
	X86_SIM_X86_JCC(X86_CC_A, 0x4a, 0x10, x86_l_10);
x86_l_4c:
	/* 0x4c: cmp    DWORD PTR [rax+0x8],0x10 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738384ULL);
x86_l_50:
	/* 0x50: jne    10 <cgroup_skb_hash_chain_prog+0x10> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x50, 0x10, x86_l_10);
x86_l_52:
	/* 0x52: cmp    DWORD PTR [rax+0xc],0x8 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607560ULL);
x86_l_56:
	/* 0x56: jne    10 <cgroup_skb_hash_chain_prog+0x10> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x56, 0x10, x86_l_10);
x86_l_58:
	/* 0x58: lea    rsi,[rcx+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5c:
	/* 0x5c: cmp    rsi,rdx */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_5f:
	/* 0x5f: ja     10 <cgroup_skb_hash_chain_prog+0x10> */
	X86_SIM_X86_JCC(X86_CC_A, 0x5f, 0x10, x86_l_10);
x86_l_61:
	/* 0x61: add    rcx,0x48 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 72ULL);
x86_l_65:
	/* 0x65: cmp    rcx,rdx */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_68:
	/* 0x68: ja     10 <cgroup_skb_hash_chain_prog+0x10> */
	X86_SIM_X86_JCC(X86_CC_A, 0x68, 0x10, x86_l_10);
x86_l_6a:
	/* 0x6a: push   r15 */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_6c:
	/* 0x6c: push   r14 */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_6e:
	/* 0x6e: push   r12 */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_70:
	/* 0x70: push   rbx */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_71:
	/* 0x71: movabs rdx,0xcbf29ce484222325 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, 0, 14695981039346656037ULL);
x86_l_7b:
	/* 0x7b: mov    esi,0x7 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 7ULL);
x86_l_80:
	/* 0x80: movabs r8,0xd1342543de82ef95 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_64, 0, 15074714826142052245ULL);
x86_l_8a:
	/* 0x8a: xor    r9d,r9d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_R9, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_8d:
	/* 0x8d: movabs r10,0x9e3779b97f4a7c15 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_64, 0, 11400714819323198485ULL);
x86_l_97:
	/* 0x97: movabs r11,0x100000001b3 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_64, 0, 1099511628211ULL);
x86_l_a1:
	/* 0xa1: inc    r9 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_a4:
	/* 0xa4: mov    rbx,r9 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RBX, X86_R9, X86_WIDTH_64, 0, 0);
x86_l_a7:
	/* 0xa7: imul   rbx,r10 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RBX, X86_R10, X86_WIDTH_64, X86_ALU_IMUL, 0);
x86_l_ab:
	/* 0xab: mov    r14,r8 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R14, X86_R8, X86_WIDTH_64, 0, 0);
x86_l_ae:
	/* 0xae: mov    rcx,rsi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_b1:
	/* 0xb1: xor    r15d,r15d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_b4:
	/* 0xb4: mov    r12,r14 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R12, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_b7:
	/* 0xb7: xor    r12,rbx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_ba:
	/* 0xba: add    r12,QWORD PTR [rax+r15*8+0x10] */
	X86_SIM_RUN_OP(X86_OP_ALU_MEM, X86_R12, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_R15, 3, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_bf:
	/* 0xbf: xor    r12,rdx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R12, X86_RDX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_c2:
	/* 0xc2: rol    r12,cl */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_ROL, 0);
x86_l_c5:
	/* 0xc5: inc    r15 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_c8:
	/* 0xc8: imul   r12,r11 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R12, X86_R11, X86_WIDTH_64, X86_ALU_IMUL, 0);
x86_l_cc:
	/* 0xcc: mov    rdx,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_cf:
	/* 0xcf: shr    rdx,0x1d */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 29ULL);
x86_l_d3:
	/* 0xd3: xor    rdx,r12 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_R12, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_d6:
	/* 0xd6: add    rcx,0xb */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 11ULL);
x86_l_da:
	/* 0xda: add    r14,r8 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R14, X86_R8, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_dd:
	/* 0xdd: cmp    r15,0x8 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, 0, 8ULL);
x86_l_e1:
	/* 0xe1: jne    b4 <cgroup_skb_hash_chain_prog+0xb4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xe1, 0xb4, x86_l_b4);
x86_l_e3:
	/* 0xe3: add    rsi,0x5 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 5ULL);
x86_l_e7:
	/* 0xe7: cmp    r9,0x10 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_64, 0, 16ULL);
x86_l_eb:
	/* 0xeb: jne    a1 <cgroup_skb_hash_chain_prog+0xa1> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xeb, 0xa1, x86_l_a1);
x86_l_ed:
	/* 0xed: mov    DWORD PTR [rdi+0x30],edx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_f0:
	/* 0xf0: shr    rdx,0x20 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_f4:
	/* 0xf4: mov    eax,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_f9:
	/* 0xf9: pop    rbx */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_fa:
	/* 0xfa: pop    r12 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R12, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_fc:
	/* 0xfc: pop    r14 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R14, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_fe:
	/* 0xfe: pop    r15 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R15, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_100:
	/* 0x100: mov    DWORD PTR [rdi+0x34],edx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_103:
	/* 0x103: jmp    108 <cgroup_skb_hash_chain_prog+0x108> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_108:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
