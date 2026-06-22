extern char __config_eth_header_length;
extern char __config_security_label;
extern char __config_tracing_ip_option_type;
extern char cilium_calls;
extern char cilium_metrics;
extern char cilium_percpu_trace_id;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int cilium_bpf_host_tail_srv6_decap_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: sub    rsp,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 32ULL);
x86_l_5:
	/* 0x5: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_8:
	/* 0x8: mov    WORD PTR [rsp+0x10],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 68719476744ULL);
x86_l_f:
	/* 0xf: mov    rax,QWORD PTR [rip+0x1387] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_16:
	/* 0x16: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_19:
	/* 0x19: mov    ecx,DWORD PTR [rdi+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_1c:
	/* 0x1c: mov    edx,DWORD PTR [rdi+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1f:
	/* 0x1f: lea    rsi,[rcx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_23:
	/* 0x23: add    rsi,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_27:
	/* 0x27: mov    ebp,0x86 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 134ULL);
x86_l_2c:
	/* 0x2c: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_2f:
	/* 0x2f: ja     ac <tail_srv6_decap+0xac> */
	X86_SIM_X86_JCC(X86_CC_A, 0x2f, 0xac, x86_l_ac);
x86_l_31:
	/* 0x31: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_34:
	/* 0x34: movzx  r14d,BYTE PTR [rcx+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_39:
	/* 0x39: cmp    r14d,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 41ULL);
x86_l_3d:
	/* 0x3d: je     86 <tail_srv6_decap+0x86> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3d, 0x86, x86_l_86);
x86_l_3f:
	/* 0x3f: cmp    r14d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 4ULL);
x86_l_43:
	/* 0x43: jne    ac <tail_srv6_decap+0xac> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x43, 0xac, x86_l_ac);
x86_l_45:
	/* 0x45: mov    eax,0x1f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 31ULL);
x86_l_4a:
	/* 0x4a: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_4d:
	/* 0x4d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_52:
	/* 0x52: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_54:
	/* 0x54: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_56:
	/* 0x56: mov    ebp,0x8d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 141ULL);
x86_l_5b:
	/* 0x5b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5d:
	/* 0x5d: js     ac <tail_srv6_decap+0xac> */
	X86_SIM_X86_JCC(X86_CC_S, 0x5d, 0xac, x86_l_ac);
x86_l_5f:
	/* 0x5f: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_64:
	/* 0x64: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_69:
	/* 0x69: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_6c:
	/* 0x6c: mov    esi,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 12ULL);
x86_l_71:
	/* 0x71: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_76:
	/* 0x76: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_79:
	/* 0x79: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7b:
	/* 0x7b: mov    esi,0xffffffec */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4294967276ULL);
x86_l_80:
	/* 0x80: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_82:
	/* 0x82: jns    8b <tail_srv6_decap+0x8b> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x82, 0x8b, x86_l_8b);
x86_l_84:
	/* 0x84: jmp    ac <tail_srv6_decap+0xac> */
	X86_SIM_X86_JMP(0x84, 0xac, x86_l_ac);
x86_l_86:
	/* 0x86: mov    esi,0xffffffd8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4294967256ULL);
x86_l_8b:
	/* 0x8b: mov    eax,0x32 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_90:
	/* 0x90: mov    ecx,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 32ULL);
x86_l_95:
	/* 0x95: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_98:
	/* 0x98: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_9d:
	/* 0x9d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9f:
	/* 0x9f: mov    ebp,0x86 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 134ULL);
x86_l_a4:
	/* 0xa4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a6:
	/* 0xa6: je     15b <tail_srv6_decap+0x15b> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa6, 0x15b, x86_l_15b);
x86_l_ac:
	/* 0xac: mov    rax,QWORD PTR [rip+0x1387] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_security_label)));
x86_l_b3:
	/* 0xb3: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b5:
	/* 0xb5: mov    DWORD PTR [rbx+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_b8:
	/* 0xb8: mov    DWORD PTR [rbx+0x34],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 223338299392ULL);
x86_l_bf:
	/* 0xbf: mov    DWORD PTR [rbx+0x38],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_c2:
	/* 0xc2: movabs rax,0x1d8660200000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 132968347783397376ULL);
x86_l_cc:
	/* 0xcc: mov    QWORD PTR [rbx+0x3c],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_d0:
	/* 0xd0: mov    r14d,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d3:
	/* 0xd3: movabs rax,0x6601c60103 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 438116417795ULL);
x86_l_dd:
	/* 0xdd: add    rax,0x1200fd */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1179901ULL);
x86_l_e3:
	/* 0xe3: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e8:
	/* 0xe8: mov    BYTE PTR [rsp+0x8],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ed:
	/* 0xed: mov    rdi,QWORD PTR [rip+0x1387] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_f4:
	/* 0xf4: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f9:
	/* 0xf9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_fe:
	/* 0xfe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_100:
	/* 0x100: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_103:
	/* 0x103: je     10e <tail_srv6_decap+0x10e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x103, 0x10e, x86_l_10e);
x86_l_105:
	/* 0x105: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_108:
	/* 0x108: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_10c:
	/* 0x10c: jmp    136 <tail_srv6_decap+0x136> */
	X86_SIM_X86_JMP(0x10c, 0x136, x86_l_136);
x86_l_10e:
	/* 0x10e: mov    QWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_117:
	/* 0x117: mov    QWORD PTR [rsp+0x18],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_11c:
	/* 0x11c: mov    rdi,QWORD PTR [rip+0x1387] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_123:
	/* 0x123: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_128:
	/* 0x128: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_12d:
	/* 0x12d: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_132:
	/* 0x132: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_134:
	/* 0x134: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_136:
	/* 0x136: mov    rsi,QWORD PTR [rip+0x1387] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_13d:
	/* 0x13d: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_142:
	/* 0x142: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_145:
	/* 0x145: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_14a:
	/* 0x14a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14c:
	/* 0x14c: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_151:
	/* 0x151: add    rsp,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_155:
	/* 0x155: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_156:
	/* 0x156: jmp    33c <tail_srv6_decap+0x33c> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_15b:
	/* 0x15b: mov    DWORD PTR [rbx+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_162:
	/* 0x162: mov    QWORD PTR [rbx+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_16a:
	/* 0x16a: mov    QWORD PTR [rbx+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_172:
	/* 0x172: cmp    r14d,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 41ULL);
x86_l_176:
	/* 0x176: je     1ee <tail_srv6_decap+0x1ee> */
	X86_SIM_X86_JCC(X86_CC_E, 0x176, 0x1ee, x86_l_1ee);
x86_l_178:
	/* 0x178: mov    ebp,0x8b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 139ULL);
x86_l_17d:
	/* 0x17d: cmp    r14d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 4ULL);
x86_l_181:
	/* 0x181: jne    ac <tail_srv6_decap+0xac> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x181, 0xac, x86_l_ac);
x86_l_187:
	/* 0x187: mov    r14,QWORD PTR [rip+0x138a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_security_label)));
x86_l_18e:
	/* 0x18e: mov    eax,DWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_191:
	/* 0x191: mov    rax,QWORD PTR [rip+0x138a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_tracing_ip_option_type)));
x86_l_198:
	/* 0x198: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19b:
	/* 0x19b: je     1b8 <tail_srv6_decap+0x1b8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x19b, 0x1b8, x86_l_1b8);
x86_l_19d:
	/* 0x19d: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1a5:
	/* 0x1a5: mov    rdi,QWORD PTR [rip+0x138a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_percpu_trace_id)));
x86_l_1ac:
	/* 0x1ac: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b1:
	/* 0x1b1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1b6:
	/* 0x1b6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b8:
	/* 0x1b8: movabs r15,0x6601c60103 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_64, 438116417795ULL);
x86_l_1c2:
	/* 0x1c2: mov    r13d,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c5:
	/* 0x1c5: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ca:
	/* 0x1ca: mov    rdi,QWORD PTR [rip+0x138a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1d1:
	/* 0x1d1: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d6:
	/* 0x1d6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1db:
	/* 0x1db: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dd:
	/* 0x1dd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1e0:
	/* 0x1e0: je     25c <tail_srv6_decap+0x25c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1e0, 0x25c, x86_l_25c);
x86_l_1e2:
	/* 0x1e2: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1e5:
	/* 0x1e5: add    QWORD PTR [rax+0x8],r13 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1e9:
	/* 0x1e9: jmp    284 <tail_srv6_decap+0x284> */
	X86_SIM_X86_JMP(0x1e9, 0x284, x86_l_284);
x86_l_1ee:
	/* 0x1ee: mov    r14,QWORD PTR [rip+0x138a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_security_label)));
x86_l_1f5:
	/* 0x1f5: mov    eax,DWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f8:
	/* 0x1f8: mov    rax,QWORD PTR [rip+0x138a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_tracing_ip_option_type)));
x86_l_1ff:
	/* 0x1ff: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_202:
	/* 0x202: je     21f <tail_srv6_decap+0x21f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x202, 0x21f, x86_l_21f);
x86_l_204:
	/* 0x204: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_20c:
	/* 0x20c: mov    rdi,QWORD PTR [rip+0x138a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_percpu_trace_id)));
x86_l_213:
	/* 0x213: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_218:
	/* 0x218: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_21d:
	/* 0x21d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21f:
	/* 0x21f: movabs r15,0x6601c60103 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_64, 438116417795ULL);
x86_l_229:
	/* 0x229: mov    r13d,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22c:
	/* 0x22c: lea    rax,[r15+0x90000] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 589824ULL);
x86_l_233:
	/* 0x233: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_238:
	/* 0x238: mov    rdi,QWORD PTR [rip+0x138a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_23f:
	/* 0x23f: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_244:
	/* 0x244: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_249:
	/* 0x249: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24b:
	/* 0x24b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_24e:
	/* 0x24e: je     2c8 <tail_srv6_decap+0x2c8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x24e, 0x2c8, x86_l_2c8);
x86_l_250:
	/* 0x250: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_253:
	/* 0x253: add    QWORD PTR [rax+0x8],r13 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_257:
	/* 0x257: jmp    2f0 <tail_srv6_decap+0x2f0> */
	X86_SIM_X86_JMP(0x257, 0x2f0, x86_l_2f0);
x86_l_25c:
	/* 0x25c: mov    QWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_265:
	/* 0x265: mov    QWORD PTR [rsp+0x18],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_26a:
	/* 0x26a: mov    rdi,QWORD PTR [rip+0x138a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_271:
	/* 0x271: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_276:
	/* 0x276: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_27b:
	/* 0x27b: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_280:
	/* 0x280: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_282:
	/* 0x282: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_284:
	/* 0x284: mov    rsi,QWORD PTR [rip+0x138a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_28b:
	/* 0x28b: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_290:
	/* 0x290: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_293:
	/* 0x293: mov    edx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_298:
	/* 0x298: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29a:
	/* 0x29a: mov    eax,DWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29d:
	/* 0x29d: mov    DWORD PTR [rbx+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2a0:
	/* 0x2a0: movabs rax,0x78c00000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8297876815872ULL);
x86_l_2aa:
	/* 0x2aa: mov    QWORD PTR [rbx+0x34],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2ae:
	/* 0x2ae: movabs rax,0x1c9660200000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 128746223132737536ULL);
x86_l_2b8:
	/* 0x2b8: mov    QWORD PTR [rbx+0x3c],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_2bc:
	/* 0x2bc: mov    r14d,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bf:
	/* 0x2bf: add    r15,0x30089 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 196745ULL);
x86_l_2c6:
	/* 0x2c6: jmp    332 <tail_srv6_decap+0x332> */
	X86_SIM_X86_JMP(0x2c6, 0x332, x86_l_332);
x86_l_2c8:
	/* 0x2c8: mov    QWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_2d1:
	/* 0x2d1: mov    QWORD PTR [rsp+0x18],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2d6:
	/* 0x2d6: mov    rdi,QWORD PTR [rip+0x138a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_2dd:
	/* 0x2dd: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e2:
	/* 0x2e2: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e7:
	/* 0x2e7: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2ec:
	/* 0x2ec: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2ee:
	/* 0x2ee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f0:
	/* 0x2f0: mov    rsi,QWORD PTR [rip+0x138a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_2f7:
	/* 0x2f7: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2fc:
	/* 0x2fc: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2ff:
	/* 0x2ff: mov    edx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_304:
	/* 0x304: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_306:
	/* 0x306: mov    eax,DWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_309:
	/* 0x309: mov    DWORD PTR [rbx+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_30c:
	/* 0x30c: movabs rax,0xa8c00000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 11596411699200ULL);
x86_l_316:
	/* 0x316: mov    QWORD PTR [rbx+0x34],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_31a:
	/* 0x31a: movabs rax,0x1d2660200000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 131279497923133440ULL);
x86_l_324:
	/* 0x324: mov    QWORD PTR [rbx+0x3c],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_328:
	/* 0x328: mov    r14d,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_32b:
	/* 0x32b: add    r15,0xc0089 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 786569ULL);
x86_l_332:
	/* 0x332: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_337:
	/* 0x337: jmp    ed <tail_srv6_decap+0xed> */
	X86_SIM_X86_JMP(0x337, 0xed, x86_l_ed);
x86_l_33c:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
