extern char __config_trace_payload_len;
extern char __config_tracing_ip_option_type;
extern char cilium_calls;
extern char cilium_metrics;
extern char cilium_percpu_trace_id;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int cilium_bpf_overlay_cil_from_overlay_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_3:
	/* 0x3: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_5:
	/* 0x5: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_7:
	/* 0x7: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_8:
	/* 0x8: sub    rsp,0x40 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 64ULL);
x86_l_c:
	/* 0xc: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_f:
	/* 0xf: mov    DWORD PTR [rdi+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_16:
	/* 0x16: mov    DWORD PTR [rdi+0x2c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188978561024ULL);
x86_l_1d:
	/* 0x1d: mov    DWORD PTR [rdi+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_24:
	/* 0x24: mov    DWORD PTR [rdi+0x34],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 223338299392ULL);
x86_l_2b:
	/* 0x2b: mov    DWORD PTR [rdi+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_32:
	/* 0x32: and    BYTE PTR [rdi+0x86],0xfb */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RDI, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 575525617915ULL);
x86_l_39:
	/* 0x39: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_tracing_ip_option_type)));
x86_l_40:
	/* 0x40: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_43:
	/* 0x43: je     7e <cil_from_overlay+0x7e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x43, 0x7e, x86_l_7e);
x86_l_45:
	/* 0x45: movzx  ebp,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_48:
	/* 0x48: mov    eax,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_4b:
	/* 0x4b: sub    eax,DWORD PTR [rbx+0x74] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 116ULL);
x86_l_4e:
	/* 0x4e: cmp    eax,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_51:
	/* 0x51: jae    12e <cil_from_overlay+0x12e> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x51, 0x12e, x86_l_12e);
x86_l_57:
	/* 0x57: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_5f:
	/* 0x5f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_64:
	/* 0x64: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_percpu_trace_id)));
x86_l_6b:
	/* 0x6b: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_70:
	/* 0x70: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_72:
	/* 0x72: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_75:
	/* 0x75: je     7e <cil_from_overlay+0x7e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x75, 0x7e, x86_l_7e);
x86_l_77:
	/* 0x77: mov    QWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7e:
	/* 0x7e: mov    ecx,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_81:
	/* 0x81: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_83:
	/* 0x83: sub    edx,DWORD PTR [rbx+0x74] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 116ULL);
x86_l_86:
	/* 0x86: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_88:
	/* 0x88: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_8b:
	/* 0x8b: jb     37b <cil_from_overlay+0x37b> */
	X86_SIM_X86_JCC(X86_CC_B, 0x8b, 0x37b, x86_l_37b);
x86_l_91:
	/* 0x91: mov    rdx,QWORD PTR [rbx+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_98:
	/* 0x98: movzx  r15d,WORD PTR [rdx+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_9d:
	/* 0x9d: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_a1:
	/* 0xa1: jb     37b <cil_from_overlay+0x37b> */
	X86_SIM_X86_JCC(X86_CC_B, 0xa1, 0x37b, x86_l_37b);
x86_l_a7:
	/* 0xa7: movabs r14,0x302300103 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 12921602307ULL);
x86_l_b1:
	/* 0xb1: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b3:
	/* 0xb3: cmp    r15d,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 8ULL);
x86_l_b7:
	/* 0xb7: jne    247 <cil_from_overlay+0x247> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xb7, 0x247, x86_l_247);
x86_l_bd:
	/* 0xbd: mov    DWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_c5:
	/* 0xc5: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_ce:
	/* 0xce: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_d7:
	/* 0xd7: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_e0:
	/* 0xe0: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_e9:
	/* 0xe9: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_f2:
	/* 0xf2: mov    eax,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 20ULL);
x86_l_f7:
	/* 0xf7: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_fc:
	/* 0xfc: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_ff:
	/* 0xff: mov    edx,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 28ULL);
x86_l_104:
	/* 0x104: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_106:
	/* 0x106: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_108:
	/* 0x108: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_10a:
	/* 0x10a: jne    4d2 <cil_from_overlay+0x4d2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x10a, 0x4d2, x86_l_4d2);
x86_l_110:
	/* 0x110: mov    ebp,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_114:
	/* 0x114: cmp    ebp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_117:
	/* 0x117: jne    241 <cil_from_overlay+0x241> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x117, 0x241, x86_l_241);
x86_l_11d:
	/* 0x11d: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_122:
	/* 0x122: mov    ecx,0xab */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 171ULL);
x86_l_127:
	/* 0x127: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_129:
	/* 0x129: jmp    2e6 <cil_from_overlay+0x2e6> */
	X86_SIM_X86_JMP(0x129, 0x2e6, x86_l_2e6);
x86_l_12e:
	/* 0x12e: cmp    eax,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 34ULL);
x86_l_131:
	/* 0x131: jb     57 <cil_from_overlay+0x57> */
	X86_SIM_X86_JCC(X86_CC_B, 0x131, 0x57, x86_l_57);
x86_l_137:
	/* 0x137: mov    rax,QWORD PTR [rbx+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_13e:
	/* 0x13e: cmp    WORD PTR [rax+0xc],0x8 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 51539607560ULL);
x86_l_143:
	/* 0x143: jne    57 <cil_from_overlay+0x57> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x143, 0x57, x86_l_57);
x86_l_149:
	/* 0x149: movzx  r15d,BYTE PTR [rax+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 14ULL);
x86_l_14e:
	/* 0x14e: and    r15d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_152:
	/* 0x152: cmp    r15b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_8, 6ULL);
x86_l_156:
	/* 0x156: jae    187 <cil_from_overlay+0x187> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x156, 0x187, x86_l_187);
x86_l_158:
	/* 0x158: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15b:
	/* 0x15b: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_163:
	/* 0x163: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_168:
	/* 0x168: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_percpu_trace_id)));
x86_l_16f:
	/* 0x16f: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_174:
	/* 0x174: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_176:
	/* 0x176: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_179:
	/* 0x179: je     7e <cil_from_overlay+0x7e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x179, 0x7e, x86_l_7e);
x86_l_17f:
	/* 0x17f: mov    QWORD PTR [rax],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_182:
	/* 0x182: jmp    7e <cil_from_overlay+0x7e> */
	X86_SIM_X86_JMP(0x182, 0x7e, x86_l_7e);
x86_l_187:
	/* 0x187: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_18c:
	/* 0x18c: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_191:
	/* 0x191: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_194:
	/* 0x194: mov    esi,0x22 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 34ULL);
x86_l_199:
	/* 0x199: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_19e:
	/* 0x19e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a0:
	/* 0x1a0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1a2:
	/* 0x1a2: js     57 <cil_from_overlay+0x57> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1a2, 0x57, x86_l_57);
x86_l_1a8:
	/* 0x1a8: movzx  eax,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_1ad:
	/* 0x1ad: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1af:
	/* 0x1af: je     158 <cil_from_overlay+0x158> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1af, 0x158, x86_l_158);
x86_l_1b1:
	/* 0x1b1: mov    r14d,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 35ULL);
x86_l_1b7:
	/* 0x1b7: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1ba:
	/* 0x1ba: je     396 <cil_from_overlay+0x396> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1ba, 0x396, x86_l_396);
x86_l_1c0:
	/* 0x1c0: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_1c5:
	/* 0x1c5: lea    rdx,[rsp+0x7] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 7ULL);
x86_l_1ca:
	/* 0x1ca: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1cd:
	/* 0x1cd: mov    esi,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 35ULL);
x86_l_1d2:
	/* 0x1d2: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1d7:
	/* 0x1d7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d9:
	/* 0x1d9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1db:
	/* 0x1db: js     57 <cil_from_overlay+0x57> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1db, 0x57, x86_l_57);
x86_l_1e1:
	/* 0x1e1: mov    r14d,0x22 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 34ULL);
x86_l_1e7:
	/* 0x1e7: cmp    BYTE PTR [rsp+0x8],bpl */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ec:
	/* 0x1ec: jne    38c <cil_from_overlay+0x38c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1ec, 0x38c, x86_l_38c);
x86_l_1f2:
	/* 0x1f2: movzx  eax,BYTE PTR [rsp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_1f7:
	/* 0x1f7: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_1fa:
	/* 0x1fa: je     49a <cil_from_overlay+0x49a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1fa, 0x49a, x86_l_49a);
x86_l_200:
	/* 0x200: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_203:
	/* 0x203: je     46e <cil_from_overlay+0x46e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x203, 0x46e, x86_l_46e);
x86_l_209:
	/* 0x209: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_20c:
	/* 0x20c: jne    57 <cil_from_overlay+0x57> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x20c, 0x57, x86_l_57);
x86_l_212:
	/* 0x212: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_217:
	/* 0x217: add    r14d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_21b:
	/* 0x21b: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_220:
	/* 0x220: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_223:
	/* 0x223: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_226:
	/* 0x226: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_22b:
	/* 0x22b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22d:
	/* 0x22d: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_230:
	/* 0x230: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_232:
	/* 0x232: movbe  cx,WORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOVBE_LOAD, X86_RCX, X86_RSP, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_239:
	/* 0x239: movzx  ecx,cx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_23c:
	/* 0x23c: jmp    4c1 <cil_from_overlay+0x4c1> */
	X86_SIM_X86_JMP(0x23c, 0x4c1, x86_l_4c1);
x86_l_241:
	/* 0x241: mov    DWORD PTR [rbx+0x28],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_244:
	/* 0x244: mov    ecx,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_247:
	/* 0x247: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_24e:
	/* 0x24e: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_250:
	/* 0x250: mov    r12d,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RCX, X86_WIDTH_32);
x86_l_253:
	/* 0x253: mov    QWORD PTR [rsp+0x8],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_258:
	/* 0x258: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_25d:
	/* 0x25d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_264:
	/* 0x264: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_269:
	/* 0x269: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26b:
	/* 0x26b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_26e:
	/* 0x26e: je     2ae <cil_from_overlay+0x2ae> */
	X86_SIM_X86_JCC(X86_CC_E, 0x26e, 0x2ae, x86_l_2ae);
x86_l_270:
	/* 0x270: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_273:
	/* 0x273: add    QWORD PTR [rax+0x8],r12 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_277:
	/* 0x277: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_279:
	/* 0x279: cmp    r15d,0xdd86 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 56710ULL);
x86_l_280:
	/* 0x280: je     2e1 <cil_from_overlay+0x2e1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x280, 0x2e1, x86_l_2e1);
x86_l_282:
	/* 0x282: cmp    r15d,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 8ULL);
x86_l_286:
	/* 0x286: jne    37b <cil_from_overlay+0x37b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x286, 0x37b, x86_l_37b);
x86_l_28c:
	/* 0x28c: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_291:
	/* 0x291: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_298:
	/* 0x298: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_29b:
	/* 0x29b: mov    edx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_2a0:
	/* 0x2a0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a2:
	/* 0x2a2: mov    ecx,0x8c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 140ULL);
x86_l_2a7:
	/* 0x2a7: mov    eax,0x700 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1792ULL);
x86_l_2ac:
	/* 0x2ac: jmp    2e6 <cil_from_overlay+0x2e6> */
	X86_SIM_X86_JMP(0x2ac, 0x2e6, x86_l_2e6);
x86_l_2ae:
	/* 0x2ae: mov    QWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_2b7:
	/* 0x2b7: mov    QWORD PTR [rsp+0x18],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2bc:
	/* 0x2bc: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2c1:
	/* 0x2c1: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_2c8:
	/* 0x2c8: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2cd:
	/* 0x2cd: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d2:
	/* 0x2d2: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d4:
	/* 0x2d4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d6:
	/* 0x2d6: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d8:
	/* 0x2d8: cmp    r15d,0xdd86 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 56710ULL);
x86_l_2df:
	/* 0x2df: jne    282 <cil_from_overlay+0x282> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2df, 0x282, x86_l_282);
x86_l_2e1:
	/* 0x2e1: mov    ecx,0x8b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 139ULL);
x86_l_2e6:
	/* 0x2e6: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_2e8:
	/* 0x2e8: mov    DWORD PTR [rbx+0x28],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2eb:
	/* 0x2eb: mov    DWORD PTR [rbx+0x2c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188978561024ULL);
x86_l_2f2:
	/* 0x2f2: mov    DWORD PTR [rbx+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2f5:
	/* 0x2f5: movabs rax,0x250030200000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 166636493337526272ULL);
x86_l_2ff:
	/* 0x2ff: mov    QWORD PTR [rbx+0x34],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_303:
	/* 0x303: mov    r15d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_307:
	/* 0x307: add    r14,0x1ffffd */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 2097149ULL);
x86_l_30e:
	/* 0x30e: mov    QWORD PTR [rsp+0x8],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_313:
	/* 0x313: mov    BYTE PTR [rsp+0x8],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_317:
	/* 0x317: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_31c:
	/* 0x31c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_323:
	/* 0x323: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_328:
	/* 0x328: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32a:
	/* 0x32a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_32d:
	/* 0x32d: je     338 <cil_from_overlay+0x338> */
	X86_SIM_X86_JCC(X86_CC_E, 0x32d, 0x338, x86_l_338);
x86_l_32f:
	/* 0x32f: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_332:
	/* 0x332: add    QWORD PTR [rax+0x8],r15 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_336:
	/* 0x336: jmp    360 <cil_from_overlay+0x360> */
	X86_SIM_X86_JMP(0x336, 0x360, x86_l_360);
x86_l_338:
	/* 0x338: mov    QWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_341:
	/* 0x341: mov    QWORD PTR [rsp+0x18],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_346:
	/* 0x346: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_34b:
	/* 0x34b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_352:
	/* 0x352: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_357:
	/* 0x357: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_35c:
	/* 0x35c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_35e:
	/* 0x35e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_360:
	/* 0x360: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_365:
	/* 0x365: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_36c:
	/* 0x36c: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_36f:
	/* 0x36f: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_374:
	/* 0x374: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_376:
	/* 0x376: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_37b:
	/* 0x37b: add    rsp,0x40 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 64ULL);
x86_l_37f:
	/* 0x37f: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_380:
	/* 0x380: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_382:
	/* 0x382: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_384:
	/* 0x384: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_386:
	/* 0x386: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_387:
	/* 0x387: jmp    4e0 <cil_from_overlay+0x4e0> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_38c:
	/* 0x38c: movzx  r14d,BYTE PTR [rsp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_392:
	/* 0x392: add    r14d,0x22 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADD, 34ULL);
x86_l_396:
	/* 0x396: lea    r15d,[r15*4+0x22] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 34ULL);
x86_l_39e:
	/* 0x39e: cmp    r14d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R14, X86_R15, X86_WIDTH_32);
x86_l_3a1:
	/* 0x3a1: jae    158 <cil_from_overlay+0x158> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x3a1, 0x158, x86_l_158);
x86_l_3a7:
	/* 0x3a7: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_3ac:
	/* 0x3ac: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3b1:
	/* 0x3b1: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_3b4:
	/* 0x3b4: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_3b7:
	/* 0x3b7: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_3bc:
	/* 0x3bc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3be:
	/* 0x3be: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3c0:
	/* 0x3c0: js     57 <cil_from_overlay+0x57> */
	X86_SIM_X86_JCC(X86_CC_S, 0x3c0, 0x57, x86_l_57);
x86_l_3c6:
	/* 0x3c6: movzx  eax,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_3cb:
	/* 0x3cb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3cd:
	/* 0x3cd: je     158 <cil_from_overlay+0x158> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3cd, 0x158, x86_l_158);
x86_l_3d3:
	/* 0x3d3: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3d6:
	/* 0x3d6: je     408 <cil_from_overlay+0x408> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3d6, 0x408, x86_l_408);
x86_l_3d8:
	/* 0x3d8: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_3dd:
	/* 0x3dd: lea    esi,[r14+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_3e1:
	/* 0x3e1: lea    rdx,[rsp+0x7] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 7ULL);
x86_l_3e6:
	/* 0x3e6: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_3e9:
	/* 0x3e9: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_3ee:
	/* 0x3ee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f0:
	/* 0x3f0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3f2:
	/* 0x3f2: js     57 <cil_from_overlay+0x57> */
	X86_SIM_X86_JCC(X86_CC_S, 0x3f2, 0x57, x86_l_57);
x86_l_3f8:
	/* 0x3f8: cmp    BYTE PTR [rsp+0x8],bpl */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3fd:
	/* 0x3fd: je     1f2 <cil_from_overlay+0x1f2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3fd, 0x1f2, x86_l_1f2);
x86_l_403:
	/* 0x403: movzx  eax,BYTE PTR [rsp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_408:
	/* 0x408: add    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_40b:
	/* 0x40b: cmp    r14d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R14, X86_R15, X86_WIDTH_32);
x86_l_40e:
	/* 0x40e: jae    158 <cil_from_overlay+0x158> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x40e, 0x158, x86_l_158);
x86_l_414:
	/* 0x414: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_419:
	/* 0x419: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_41e:
	/* 0x41e: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_421:
	/* 0x421: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_424:
	/* 0x424: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_429:
	/* 0x429: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_42b:
	/* 0x42b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_42d:
	/* 0x42d: js     57 <cil_from_overlay+0x57> */
	X86_SIM_X86_JCC(X86_CC_S, 0x42d, 0x57, x86_l_57);
x86_l_433:
	/* 0x433: cmp    BYTE PTR [rsp+0x8],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34359738370ULL);
x86_l_438:
	/* 0x438: jb     158 <cil_from_overlay+0x158> */
	X86_SIM_X86_JCC(X86_CC_B, 0x438, 0x158, x86_l_158);
x86_l_43e:
	/* 0x43e: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_443:
	/* 0x443: lea    esi,[r14+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_447:
	/* 0x447: lea    rdx,[rsp+0x7] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 7ULL);
x86_l_44c:
	/* 0x44c: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_44f:
	/* 0x44f: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_454:
	/* 0x454: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_456:
	/* 0x456: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_458:
	/* 0x458: js     57 <cil_from_overlay+0x57> */
	X86_SIM_X86_JCC(X86_CC_S, 0x458, 0x57, x86_l_57);
x86_l_45e:
	/* 0x45e: cmp    BYTE PTR [rsp+0x8],bpl */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_463:
	/* 0x463: jne    158 <cil_from_overlay+0x158> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x463, 0x158, x86_l_158);
x86_l_469:
	/* 0x469: jmp    1f2 <cil_from_overlay+0x1f2> */
	X86_SIM_X86_JMP(0x469, 0x1f2, x86_l_1f2);
x86_l_46e:
	/* 0x46e: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_473:
	/* 0x473: add    r14d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_477:
	/* 0x477: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_47c:
	/* 0x47c: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_47f:
	/* 0x47f: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_482:
	/* 0x482: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_487:
	/* 0x487: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_489:
	/* 0x489: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_48b:
	/* 0x48b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_48d:
	/* 0x48d: movbe  r14d,DWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOVBE_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 16ULL);
x86_l_494:
	/* 0x494: cmovs  r14d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R14, X86_RCX, X86_WIDTH_32, X86_CC_S);
x86_l_498:
	/* 0x498: jmp    4c5 <cil_from_overlay+0x4c5> */
	X86_SIM_X86_JMP(0x498, 0x4c5, x86_l_4c5);
x86_l_49a:
	/* 0x49a: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_49f:
	/* 0x49f: add    r14d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_4a3:
	/* 0x4a3: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4a8:
	/* 0x4a8: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_4ab:
	/* 0x4ab: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_4ae:
	/* 0x4ae: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4b3:
	/* 0x4b3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b5:
	/* 0x4b5: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4b8:
	/* 0x4b8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4ba:
	/* 0x4ba: movbe  rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOVBE_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_4c1:
	/* 0x4c1: cmovns r14,rcx */
	X86_SIM_L_EXEC_CMOV(X86_R14, X86_RCX, X86_WIDTH_64, X86_CC_NS);
x86_l_4c5:
	/* 0x4c5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4c7:
	/* 0x4c7: jns    15b <cil_from_overlay+0x15b> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x4c7, 0x15b, x86_l_15b);
x86_l_4cd:
	/* 0x4cd: jmp    57 <cil_from_overlay+0x57> */
	X86_SIM_X86_JMP(0x4cd, 0x57, x86_l_57);
x86_l_4d2:
	/* 0x4d2: mov    ecx,0x93 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 147ULL);
x86_l_4d7:
	/* 0x4d7: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4d9:
	/* 0x4d9: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4db:
	/* 0x4db: jmp    2e6 <cil_from_overlay+0x2e6> */
	X86_SIM_X86_JMP(0x4db, 0x2e6, x86_l_2e6);
x86_l_4e0:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
