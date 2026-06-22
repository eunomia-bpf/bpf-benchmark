extern char __config_enable_xdp_prefilter;
extern char __config_tracing_ip_option_type;
extern char cilium_cidr_v4_dyn;
extern char cilium_cidr_v4_fix;
extern char cilium_percpu_trace_id;
extern char cilium_xdp_scratch;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int cilium_bpf_xdp_cil_xdp_entry_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_3:
	/* 0x3: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_4:
	/* 0x4: sub    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 16ULL);
x86_l_8:
	/* 0x8: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_b:
	/* 0xb: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_tracing_ip_option_type)));
x86_l_12:
	/* 0x12: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15:
	/* 0x15: je     55 <cil_xdp_entry+0x55> */
	X86_SIM_X86_JCC(X86_CC_E, 0x15, 0x55, x86_l_55);
x86_l_17:
	/* 0x17: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1a:
	/* 0x1a: mov    rax,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d:
	/* 0x1d: mov    rcx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_21:
	/* 0x21: lea    rdi,[rax+0xe] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_25:
	/* 0x25: cmp    rdi,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RCX, X86_WIDTH_64);
x86_l_28:
	/* 0x28: jbe    137 <cil_xdp_entry+0x137> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x28, 0x137, x86_l_137);
x86_l_2e:
	/* 0x2e: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_36:
	/* 0x36: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3b:
	/* 0x3b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_percpu_trace_id)));
x86_l_42:
	/* 0x42: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_47:
	/* 0x47: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_49:
	/* 0x49: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4c:
	/* 0x4c: je     55 <cil_xdp_entry+0x55> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4c, 0x55, x86_l_55);
x86_l_4e:
	/* 0x4e: mov    QWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_55:
	/* 0x55: mov    rcx,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_58:
	/* 0x58: lea    rdx,[rcx+0xe] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_5c:
	/* 0x5c: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_61:
	/* 0x61: cmp    rdx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_65:
	/* 0x65: ja     1d1 <cil_xdp_entry+0x1d1> */
	X86_SIM_X86_JCC(X86_CC_A, 0x65, 0x1d1, x86_l_1d1);
x86_l_6b:
	/* 0x6b: movzx  ebp,WORD PTR [rcx+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_6f:
	/* 0x6f: cmp    bp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_16, 6ULL);
x86_l_73:
	/* 0x73: jb     1d1 <cil_xdp_entry+0x1d1> */
	X86_SIM_X86_JCC(X86_CC_B, 0x73, 0x1d1, x86_l_1d1);
x86_l_79:
	/* 0x79: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_81:
	/* 0x81: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_86:
	/* 0x86: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_8d:
	/* 0x8d: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_92:
	/* 0x92: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_94:
	/* 0x94: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_97:
	/* 0x97: je     a0 <cil_xdp_entry+0xa0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x97, 0xa0, x86_l_a0);
x86_l_99:
	/* 0x99: mov    DWORD PTR [rax+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_a0:
	/* 0xa0: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_a8:
	/* 0xa8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ad:
	/* 0xad: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_b4:
	/* 0xb4: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b9:
	/* 0xb9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bb:
	/* 0xbb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_be:
	/* 0xbe: je     c7 <cil_xdp_entry+0xc7> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbe, 0xc7, x86_l_c7);
x86_l_c0:
	/* 0xc0: mov    DWORD PTR [rax+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_c7:
	/* 0xc7: cmp    bp,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_16, 8ULL);
x86_l_cb:
	/* 0xcb: jne    18e <cil_xdp_entry+0x18e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xcb, 0x18e, x86_l_18e);
x86_l_d1:
	/* 0xd1: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_xdp_prefilter)));
x86_l_d8:
	/* 0xd8: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_db:
	/* 0xdb: je     18e <cil_xdp_entry+0x18e> */
	X86_SIM_X86_JCC(X86_CC_E, 0xdb, 0x18e, x86_l_18e);
x86_l_e1:
	/* 0xe1: mov    rax,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e4:
	/* 0xe4: lea    rcx,[rax+0x22] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_e8:
	/* 0xe8: cmp    rcx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_ec:
	/* 0xec: ja     12d <cil_xdp_entry+0x12d> */
	X86_SIM_X86_JCC(X86_CC_A, 0xec, 0x12d, x86_l_12d);
x86_l_ee:
	/* 0xee: mov    eax,DWORD PTR [rax+0x1a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_f1:
	/* 0xf1: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_f5:
	/* 0xf5: mov    DWORD PTR [rsp+0x8],0x20 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738400ULL);
x86_l_fd:
	/* 0xfd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_102:
	/* 0x102: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_cidr_v4_dyn)));
x86_l_109:
	/* 0x109: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10e:
	/* 0x10e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_110:
	/* 0x110: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_113:
	/* 0x113: jne    12d <cil_xdp_entry+0x12d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x113, 0x12d, x86_l_12d);
x86_l_115:
	/* 0x115: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_11a:
	/* 0x11a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_cidr_v4_fix)));
x86_l_121:
	/* 0x121: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_126:
	/* 0x126: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_128:
	/* 0x128: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_12b:
	/* 0x12b: je     18e <cil_xdp_entry+0x18e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12b, 0x18e, x86_l_18e);
x86_l_12d:
	/* 0x12d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_132:
	/* 0x132: jmp    1d1 <cil_xdp_entry+0x1d1> */
	X86_SIM_X86_JMP(0x132, 0x1d1, x86_l_1d1);
x86_l_137:
	/* 0x137: cmp    WORD PTR [rax+0xc],0x8 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 51539607560ULL);
x86_l_13c:
	/* 0x13c: jne    2e <cil_xdp_entry+0x2e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x13c, 0x2e, x86_l_2e);
x86_l_142:
	/* 0x142: lea    rsi,[rax+0x22] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_146:
	/* 0x146: cmp    rsi,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_64);
x86_l_149:
	/* 0x149: ja     2e <cil_xdp_entry+0x2e> */
	X86_SIM_X86_JCC(X86_CC_A, 0x149, 0x2e, x86_l_2e);
x86_l_14f:
	/* 0x14f: movzx  edi,BYTE PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_152:
	/* 0x152: and    edi,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_155:
	/* 0x155: cmp    dil,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_8, 6ULL);
x86_l_159:
	/* 0x159: jae    1de <cil_xdp_entry+0x1de> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x159, 0x1de, x86_l_1de);
x86_l_15f:
	/* 0x15f: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_162:
	/* 0x162: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_16a:
	/* 0x16a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_16f:
	/* 0x16f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_percpu_trace_id)));
x86_l_176:
	/* 0x176: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17b:
	/* 0x17b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17d:
	/* 0x17d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_180:
	/* 0x180: je     55 <cil_xdp_entry+0x55> */
	X86_SIM_X86_JCC(X86_CC_E, 0x180, 0x55, x86_l_55);
x86_l_186:
	/* 0x186: mov    QWORD PTR [rax],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_189:
	/* 0x189: jmp    55 <cil_xdp_entry+0x55> */
	X86_SIM_X86_JMP(0x189, 0x55, x86_l_55);
x86_l_18e:
	/* 0x18e: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_196:
	/* 0x196: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_19b:
	/* 0x19b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_1a2:
	/* 0x1a2: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a7:
	/* 0x1a7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a9:
	/* 0x1a9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ac:
	/* 0x1ac: je     1cc <cil_xdp_entry+0x1cc> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1ac, 0x1cc, x86_l_1cc);
x86_l_1ae:
	/* 0x1ae: mov    ebp,DWORD PTR [rax+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1b1:
	/* 0x1b1: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_1b3:
	/* 0x1b3: je     1cc <cil_xdp_entry+0x1cc> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1b3, 0x1cc, x86_l_1cc);
x86_l_1b5:
	/* 0x1b5: mov    eax,0x36 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 54ULL);
x86_l_1ba:
	/* 0x1ba: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1bd:
	/* 0x1bd: mov    esi,0xfffffffc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4294967292ULL);
x86_l_1c2:
	/* 0x1c2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c4:
	/* 0x1c4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1c6:
	/* 0x1c6: je     297 <cil_xdp_entry+0x297> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1c6, 0x297, x86_l_297);
x86_l_1cc:
	/* 0x1cc: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1d1:
	/* 0x1d1: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1d5:
	/* 0x1d5: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_1d6:
	/* 0x1d6: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_1d8:
	/* 0x1d8: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_1d9:
	/* 0x1d9: jmp    3a0 <cil_xdp_entry+0x3a0> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_1de:
	/* 0x1de: lea    r8,[rax+0x23] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 35ULL);
x86_l_1e2:
	/* 0x1e2: cmp    r8,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RCX, X86_WIDTH_64);
x86_l_1e5:
	/* 0x1e5: ja     2e <cil_xdp_entry+0x2e> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1e5, 0x2e, x86_l_2e);
x86_l_1eb:
	/* 0x1eb: movzx  r14d,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1ef:
	/* 0x1ef: test   r14d,r14d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_32);
x86_l_1f2:
	/* 0x1f2: je     162 <cil_xdp_entry+0x162> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1f2, 0x162, x86_l_162);
x86_l_1f8:
	/* 0x1f8: mov    esi,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 35ULL);
x86_l_1fd:
	/* 0x1fd: cmp    r14d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1ULL);
x86_l_201:
	/* 0x201: jne    2b4 <cil_xdp_entry+0x2b4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x201, 0x2b4, x86_l_2b4);
x86_l_207:
	/* 0x207: lea    edi,[rdi*4+0x22] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 2), 34ULL);
x86_l_20e:
	/* 0x20e: cmp    esi,edi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDI, X86_WIDTH_32);
x86_l_210:
	/* 0x210: jae    15f <cil_xdp_entry+0x15f> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x210, 0x15f, x86_l_15f);
x86_l_216:
	/* 0x216: mov    r8d,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RSI, X86_WIDTH_32);
x86_l_219:
	/* 0x219: lea    r9,[rax+r8*1] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R8, 0), 0ULL);
x86_l_21d:
	/* 0x21d: inc    r9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_220:
	/* 0x220: cmp    r9,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R9, X86_RCX, X86_WIDTH_64);
x86_l_223:
	/* 0x223: ja     2e <cil_xdp_entry+0x2e> */
	X86_SIM_X86_JCC(X86_CC_A, 0x223, 0x2e, x86_l_2e);
x86_l_229:
	/* 0x229: lea    r9,[rax+r8*1] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R8, 0), 0ULL);
x86_l_22d:
	/* 0x22d: movzx  r14d,BYTE PTR [r9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R9, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_231:
	/* 0x231: test   r14d,r14d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_32);
x86_l_234:
	/* 0x234: je     162 <cil_xdp_entry+0x162> */
	X86_SIM_X86_JCC(X86_CC_E, 0x234, 0x162, x86_l_162);
x86_l_23a:
	/* 0x23a: cmp    r14d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1ULL);
x86_l_23e:
	/* 0x23e: jne    32c <cil_xdp_entry+0x32c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x23e, 0x32c, x86_l_32c);
x86_l_244:
	/* 0x244: add    esi,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R14, X86_WIDTH_32, X86_ALU_ADD);
x86_l_247:
	/* 0x247: cmp    esi,edi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDI, X86_WIDTH_32);
x86_l_249:
	/* 0x249: jae    15f <cil_xdp_entry+0x15f> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x249, 0x15f, x86_l_15f);
x86_l_24f:
	/* 0x24f: mov    edi,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_251:
	/* 0x251: lea    r8,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_255:
	/* 0x255: inc    r8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_258:
	/* 0x258: cmp    r8,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RCX, X86_WIDTH_64);
x86_l_25b:
	/* 0x25b: ja     2e <cil_xdp_entry+0x2e> */
	X86_SIM_X86_JCC(X86_CC_A, 0x25b, 0x2e, x86_l_2e);
x86_l_261:
	/* 0x261: lea    r8,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_265:
	/* 0x265: movzx  r8d,BYTE PTR [r8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R8, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_269:
	/* 0x269: cmp    r8b,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_8, 2ULL);
x86_l_26d:
	/* 0x26d: jb     15f <cil_xdp_entry+0x15f> */
	X86_SIM_X86_JCC(X86_CC_B, 0x26d, 0x15f, x86_l_15f);
x86_l_273:
	/* 0x273: lea    r9,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_277:
	/* 0x277: add    r9,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_27b:
	/* 0x27b: cmp    r9,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R9, X86_RCX, X86_WIDTH_64);
x86_l_27e:
	/* 0x27e: ja     2e <cil_xdp_entry+0x2e> */
	X86_SIM_X86_JCC(X86_CC_A, 0x27e, 0x2e, x86_l_2e);
x86_l_284:
	/* 0x284: cmp    r8b,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDX, X86_WIDTH_8);
x86_l_287:
	/* 0x287: jne    15f <cil_xdp_entry+0x15f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x287, 0x15f, x86_l_15f);
x86_l_28d:
	/* 0x28d: add    rdi,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_290:
	/* 0x290: movzx  r8d,BYTE PTR [rdi+0x1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 1ULL);
x86_l_295:
	/* 0x295: jmp    2d0 <cil_xdp_entry+0x2d0> */
	X86_SIM_X86_JMP(0x295, 0x2d0, x86_l_2d0);
x86_l_297:
	/* 0x297: mov    rcx,QWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_29b:
	/* 0x29b: lea    rax,[rcx+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_29f:
	/* 0x29f: cmp    rax,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_2a2:
	/* 0x2a2: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2a7:
	/* 0x2a7: ja     1d1 <cil_xdp_entry+0x1d1> */
	X86_SIM_X86_JCC(X86_CC_A, 0x2a7, 0x1d1, x86_l_1d1);
x86_l_2ad:
	/* 0x2ad: mov    DWORD PTR [rcx],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2af:
	/* 0x2af: jmp    1d1 <cil_xdp_entry+0x1d1> */
	X86_SIM_X86_JMP(0x2af, 0x1d1, x86_l_1d1);
x86_l_2b4:
	/* 0x2b4: lea    rsi,[rax+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2b8:
	/* 0x2b8: cmp    rsi,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_64);
x86_l_2bb:
	/* 0x2bb: ja     2e <cil_xdp_entry+0x2e> */
	X86_SIM_X86_JCC(X86_CC_A, 0x2bb, 0x2e, x86_l_2e);
x86_l_2c1:
	/* 0x2c1: movzx  r8d,BYTE PTR [rax+0x23] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 35ULL);
x86_l_2c6:
	/* 0x2c6: mov    esi,0x22 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 34ULL);
x86_l_2cb:
	/* 0x2cb: cmp    r14b,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R14, X86_RDX, X86_WIDTH_8);
x86_l_2ce:
	/* 0x2ce: jne    311 <cil_xdp_entry+0x311> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2ce, 0x311, x86_l_311);
x86_l_2d0:
	/* 0x2d0: cmp    r8b,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_8, 10ULL);
x86_l_2d4:
	/* 0x2d4: je     37f <cil_xdp_entry+0x37f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2d4, 0x37f, x86_l_37f);
x86_l_2da:
	/* 0x2da: movzx  edx,r8b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_R8, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2de:
	/* 0x2de: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_2e1:
	/* 0x2e1: je     35e <cil_xdp_entry+0x35e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2e1, 0x35e, x86_l_35e);
x86_l_2e3:
	/* 0x2e3: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_2e6:
	/* 0x2e6: jne    2e <cil_xdp_entry+0x2e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2e6, 0x2e, x86_l_2e);
x86_l_2ec:
	/* 0x2ec: mov    edx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2ee:
	/* 0x2ee: lea    rsi,[rax+rdx*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_2f2:
	/* 0x2f2: add    rsi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2f6:
	/* 0x2f6: cmp    rsi,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_64);
x86_l_2f9:
	/* 0x2f9: ja     2e <cil_xdp_entry+0x2e> */
	X86_SIM_X86_JCC(X86_CC_A, 0x2f9, 0x2e, x86_l_2e);
x86_l_2ff:
	/* 0x2ff: add    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_302:
	/* 0x302: movbe  ax,WORD PTR [rax+0x2] */
	X86_SIM_RUN_OP(X86_OP_MOVBE_LOAD, X86_RAX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_308:
	/* 0x308: movzx  r14d,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_30c:
	/* 0x30c: jmp    162 <cil_xdp_entry+0x162> */
	X86_SIM_X86_JMP(0x30c, 0x162, x86_l_162);
x86_l_311:
	/* 0x311: movzx  esi,r8b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_R8, X86_WIDTH_32, X86_WIDTH_8);
x86_l_315:
	/* 0x315: add    esi,0x22 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 34ULL);
x86_l_318:
	/* 0x318: lea    edi,[rdi*4+0x22] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 2), 34ULL);
x86_l_31f:
	/* 0x31f: cmp    esi,edi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDI, X86_WIDTH_32);
x86_l_321:
	/* 0x321: jae    15f <cil_xdp_entry+0x15f> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x321, 0x15f, x86_l_15f);
x86_l_327:
	/* 0x327: jmp    216 <cil_xdp_entry+0x216> */
	X86_SIM_X86_JMP(0x327, 0x216, x86_l_216);
x86_l_32c:
	/* 0x32c: lea    r9,[rax+r8*1] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R8, 0), 0ULL);
x86_l_330:
	/* 0x330: add    r9,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_334:
	/* 0x334: cmp    r9,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R9, X86_RCX, X86_WIDTH_64);
x86_l_337:
	/* 0x337: ja     2e <cil_xdp_entry+0x2e> */
	X86_SIM_X86_JCC(X86_CC_A, 0x337, 0x2e, x86_l_2e);
x86_l_33d:
	/* 0x33d: add    r8,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_340:
	/* 0x340: movzx  r8d,BYTE PTR [r8+0x1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R8, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 1ULL);
x86_l_345:
	/* 0x345: cmp    r14b,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R14, X86_RDX, X86_WIDTH_8);
x86_l_348:
	/* 0x348: je     2d0 <cil_xdp_entry+0x2d0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x348, 0x2d0, x86_l_2d0);
x86_l_34a:
	/* 0x34a: movzx  r14d,r8b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_R8, X86_WIDTH_32, X86_WIDTH_8);
x86_l_34e:
	/* 0x34e: add    esi,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R14, X86_WIDTH_32, X86_ALU_ADD);
x86_l_351:
	/* 0x351: cmp    esi,edi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDI, X86_WIDTH_32);
x86_l_353:
	/* 0x353: jae    15f <cil_xdp_entry+0x15f> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x353, 0x15f, x86_l_15f);
x86_l_359:
	/* 0x359: jmp    24f <cil_xdp_entry+0x24f> */
	X86_SIM_X86_JMP(0x359, 0x24f, x86_l_24f);
x86_l_35e:
	/* 0x35e: mov    edx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_360:
	/* 0x360: lea    rsi,[rax+rdx*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_364:
	/* 0x364: add    rsi,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 6ULL);
x86_l_368:
	/* 0x368: cmp    rsi,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_64);
x86_l_36b:
	/* 0x36b: ja     2e <cil_xdp_entry+0x2e> */
	X86_SIM_X86_JCC(X86_CC_A, 0x36b, 0x2e, x86_l_2e);
x86_l_371:
	/* 0x371: add    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_374:
	/* 0x374: movbe  r14d,DWORD PTR [rax+0x2] */
	X86_SIM_RUN_OP(X86_OP_MOVBE_LOAD, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 2ULL);
x86_l_37a:
	/* 0x37a: jmp    162 <cil_xdp_entry+0x162> */
	X86_SIM_X86_JMP(0x37a, 0x162, x86_l_162);
x86_l_37f:
	/* 0x37f: mov    edx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_381:
	/* 0x381: lea    rsi,[rax+rdx*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_385:
	/* 0x385: add    rsi,0xa */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 10ULL);
x86_l_389:
	/* 0x389: cmp    rsi,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_64);
x86_l_38c:
	/* 0x38c: ja     2e <cil_xdp_entry+0x2e> */
	X86_SIM_X86_JCC(X86_CC_A, 0x38c, 0x2e, x86_l_2e);
x86_l_392:
	/* 0x392: add    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_395:
	/* 0x395: movbe  r14,QWORD PTR [rax+0x2] */
	X86_SIM_RUN_OP(X86_OP_MOVBE_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 2ULL);
x86_l_39b:
	/* 0x39b: jmp    162 <cil_xdp_entry+0x162> */
	X86_SIM_X86_JMP(0x39b, 0x162, x86_l_162);
x86_l_3a0:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
