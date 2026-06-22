extern char __config_enable_l2_announcements;
extern char __config_eth_header_length;
extern char __config_interface_mac;
extern char __config_l2_announcements_max_liveness;
extern char __config_trace_payload_len;
extern char __config_tracing_ip_option_type;
extern char cilium_calls;
extern char cilium_ipcache_v2;
extern char cilium_l2_responder_v4;
extern char cilium_metrics;
extern char cilium_percpu_trace_id;
extern char cilium_runtime_config;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int cilium_bpf_host_cil_from_netdev_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 56ULL);
x86_l_7:
	/* 0x7: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_a:
	/* 0xa: mov    DWORD PTR [rdi+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_11:
	/* 0x11: mov    DWORD PTR [rdi+0x2c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188978561024ULL);
x86_l_18:
	/* 0x18: mov    DWORD PTR [rdi+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1f:
	/* 0x1f: mov    DWORD PTR [rdi+0x34],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 223338299392ULL);
x86_l_26:
	/* 0x26: mov    DWORD PTR [rdi+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_2d:
	/* 0x2d: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&__config_tracing_ip_option_type)));
x86_l_34:
	/* 0x34: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_38:
	/* 0x38: je     bf <cil_from_netdev+0xbf> */
	X86_SIM_X86_JCC(X86_CC_E, 0x38, 0xbf, x86_l_bf);
x86_l_3e:
	/* 0x3e: movzx  ebp,BYTE PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_42:
	/* 0x42: mov    rcx,QWORD PTR [rbx+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_49:
	/* 0x49: mov    edx,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_4c:
	/* 0x4c: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_53:
	/* 0x53: sub    edx,DWORD PTR [rbx+0x74] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 116ULL);
x86_l_56:
	/* 0x56: movzx  esi,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_59:
	/* 0x59: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5c:
	/* 0x5c: je     74 <cil_from_netdev+0x74> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5c, 0x74, x86_l_74);
x86_l_5e:
	/* 0x5e: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_60:
	/* 0x60: jb     98 <cil_from_netdev+0x98> */
	X86_SIM_X86_JCC(X86_CC_B, 0x60, 0x98, x86_l_98);
x86_l_62:
	/* 0x62: movzx  esi,WORD PTR [rcx+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_66:
	/* 0x66: cmp    si,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_16, 6ULL);
x86_l_6a:
	/* 0x6a: jb     98 <cil_from_netdev+0x98> */
	X86_SIM_X86_JCC(X86_CC_B, 0x6a, 0x98, x86_l_98);
x86_l_6c:
	/* 0x6c: cmp    si,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_16, 8ULL);
x86_l_70:
	/* 0x70: je     81 <cil_from_netdev+0x81> */
	X86_SIM_X86_JCC(X86_CC_E, 0x70, 0x81, x86_l_81);
x86_l_72:
	/* 0x72: jmp    98 <cil_from_netdev+0x98> */
	X86_SIM_X86_JMP(0x72, 0x98, x86_l_98);
x86_l_74:
	/* 0x74: movzx  esi,WORD PTR [rbx+0xb4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 180ULL);
x86_l_7b:
	/* 0x7b: cmp    si,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_16, 8ULL);
x86_l_7f:
	/* 0x7f: jne    98 <cil_from_netdev+0x98> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x7f, 0x98, x86_l_98);
x86_l_81:
	/* 0x81: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_84:
	/* 0x84: movzx  esi,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_87:
	/* 0x87: lea    rdi,[rcx+rsi*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_8b:
	/* 0x8b: add    rdi,0x14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 20ULL);
x86_l_8f:
	/* 0x8f: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_92:
	/* 0x92: jbe    3f5 <cil_from_netdev+0x3f5> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x92, 0x3f5, x86_l_3f5);
x86_l_98:
	/* 0x98: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_a0:
	/* 0xa0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a5:
	/* 0xa5: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_percpu_trace_id)));
x86_l_ac:
	/* 0xac: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b1:
	/* 0xb1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b3:
	/* 0xb3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b6:
	/* 0xb6: je     bf <cil_from_netdev+0xbf> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb6, 0xbf, x86_l_bf);
x86_l_b8:
	/* 0xb8: mov    QWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bf:
	/* 0xbf: mov    rax,QWORD PTR [rbx+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_c6:
	/* 0xc6: mov    ecx,DWORD PTR [rbx+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_cc:
	/* 0xcc: movzx  ecx,BYTE PTR [rax+rcx*1+0x1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 1ULL);
x86_l_d1:
	/* 0xd1: mov    rax,QWORD PTR [rbx+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_d8:
	/* 0xd8: mov    rdx,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_db:
	/* 0xdb: neg    rdx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_de:
	/* 0xde: lea    rsi,[rax+rdx*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_e2:
	/* 0xe2: add    rsi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_e6:
	/* 0xe6: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e8:
	/* 0xe8: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_eb:
	/* 0xeb: ja     f5 <cil_from_netdev+0xf5> */
	X86_SIM_X86_JCC(X86_CC_A, 0xeb, 0xf5, x86_l_f5);
x86_l_ed:
	/* 0xed: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_f0:
	/* 0xf0: sub    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_f3:
	/* 0xf3: mov    edx,DWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f5:
	/* 0xf5: mov    ecx,DWORD PTR [rbx+0x9c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_fb:
	/* 0xfb: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_fd:
	/* 0xfd: je     145 <cil_from_netdev+0x145> */
	X86_SIM_X86_JCC(X86_CC_E, 0xfd, 0x145, x86_l_145);
x86_l_ff:
	/* 0xff: test   ecx,0xfff0000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_32, 268369920ULL);
x86_l_105:
	/* 0x105: je     145 <cil_from_netdev+0x145> */
	X86_SIM_X86_JCC(X86_CC_E, 0x105, 0x145, x86_l_145);
x86_l_107:
	/* 0x107: mov    rax,QWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10b:
	/* 0x10b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_10e:
	/* 0x10e: je     476 <cil_from_netdev+0x476> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10e, 0x476, x86_l_476);
x86_l_114:
	/* 0x114: mov    eax,DWORD PTR [rax+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_11a:
	/* 0x11a: cmp    eax,0x75 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 117ULL);
x86_l_11d:
	/* 0x11d: je     45c <cil_from_netdev+0x45c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11d, 0x45c, x86_l_45c);
x86_l_123:
	/* 0x123: cmp    eax,0x74 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 116ULL);
x86_l_126:
	/* 0x126: jne    476 <cil_from_netdev+0x476> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x126, 0x476, x86_l_476);
x86_l_12c:
	/* 0x12c: and    ecx,0xffe0000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 268304384ULL);
x86_l_132:
	/* 0x132: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_134:
	/* 0x134: cmp    ecx,0xfa00000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 262144000ULL);
x86_l_13a:
	/* 0x13a: jne    476 <cil_from_netdev+0x476> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x13a, 0x476, x86_l_476);
x86_l_140:
	/* 0x140: jmp    971 <cil_from_netdev+0x971> */
	X86_SIM_X86_JMP(0x140, 0x971, x86_l_971);
x86_l_145:
	/* 0x145: movzx  ecx,WORD PTR [rbx+0x86] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 134ULL);
x86_l_14c:
	/* 0x14c: and    ecx,0xfffffffb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294967291ULL);
x86_l_14f:
	/* 0x14f: mov    esi,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_151:
	/* 0x151: and    esi,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 1ULL);
x86_l_154:
	/* 0x154: lea    ecx,[rcx+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_157:
	/* 0x157: mov    WORD PTR [rbx+0x86],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 134ULL);
x86_l_15e:
	/* 0x15e: test   dl,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_8, 4ULL);
x86_l_161:
	/* 0x161: je     17a <cil_from_netdev+0x17a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x161, 0x17a, x86_l_17a);
x86_l_163:
	/* 0x163: mov    ecx,0xfffff0ff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294963455ULL);
x86_l_168:
	/* 0x168: and    ecx,DWORD PTR [rbx+0xa8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 168ULL);
x86_l_16e:
	/* 0x16e: or     ecx,0x300 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_OR, 768ULL);
x86_l_174:
	/* 0x174: mov    DWORD PTR [rbx+0xa8],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_17a:
	/* 0x17a: movabs r14,0x1045c0103 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 4368105731ULL);
x86_l_184:
	/* 0x184: mov    ecx,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_187:
	/* 0x187: mov    edx,DWORD PTR [rbx+0x74] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_18a:
	/* 0x18a: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_191:
	/* 0x191: movzx  esi,BYTE PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_196:
	/* 0x196: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19b:
	/* 0x19b: je     212 <cil_from_netdev+0x212> */
	X86_SIM_X86_JCC(X86_CC_E, 0x19b, 0x212, x86_l_212);
x86_l_19d:
	/* 0x19d: mov    edi,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RCX, X86_WIDTH_32);
x86_l_19f:
	/* 0x19f: sub    edi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1a1:
	/* 0x1a1: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_1a3:
	/* 0x1a3: jb     1af <cil_from_netdev+0x1af> */
	X86_SIM_X86_JCC(X86_CC_B, 0x1a3, 0x1af, x86_l_1af);
x86_l_1a5:
	/* 0x1a5: movzx  eax,WORD PTR [rax+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_1a9:
	/* 0x1a9: cmp    ax,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_16, 5ULL);
x86_l_1ad:
	/* 0x1ad: ja     219 <cil_from_netdev+0x219> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1ad, 0x219, x86_l_219);
x86_l_1af:
	/* 0x1af: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b3:
	/* 0x1b3: je     1d3 <cil_from_netdev+0x1d3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1b3, 0x1d3, x86_l_1d3);
x86_l_1b5:
	/* 0x1b5: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1bd:
	/* 0x1bd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1c2:
	/* 0x1c2: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_percpu_trace_id)));
x86_l_1c9:
	/* 0x1c9: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ce:
	/* 0x1ce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d0:
	/* 0x1d0: mov    ecx,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1d3:
	/* 0x1d3: mov    ebx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RCX, X86_WIDTH_32);
x86_l_1d5:
	/* 0x1d5: add    r14,0x6900fd */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 6881533ULL);
x86_l_1dc:
	/* 0x1dc: mov    QWORD PTR [rsp],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e0:
	/* 0x1e0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1e5:
	/* 0x1e5: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1ec:
	/* 0x1ec: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1ef:
	/* 0x1ef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f1:
	/* 0x1f1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1f4:
	/* 0x1f4: jne    3e7 <cil_from_netdev+0x3e7> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1f4, 0x3e7, x86_l_3e7);
x86_l_1fa:
	/* 0x1fa: mov    QWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_203:
	/* 0x203: mov    QWORD PTR [rsp+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_208:
	/* 0x208: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_20d:
	/* 0x20d: jmp    632 <cil_from_netdev+0x632> */
	X86_SIM_X86_JMP(0x20d, 0x632, x86_l_632);
x86_l_212:
	/* 0x212: movzx  eax,WORD PTR [rbx+0xb4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 180ULL);
x86_l_219:
	/* 0x219: mov    rdx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_220:
	/* 0x220: mov    edx,DWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_222:
	/* 0x222: movzx  eax,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_225:
	/* 0x225: cmp    eax,0x608 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1544ULL);
x86_l_22a:
	/* 0x22a: je     312 <cil_from_netdev+0x312> */
	X86_SIM_X86_JCC(X86_CC_E, 0x22a, 0x312, x86_l_312);
x86_l_230:
	/* 0x230: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_233:
	/* 0x233: jne    39c <cil_from_netdev+0x39c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x233, 0x39c, x86_l_39c);
x86_l_239:
	/* 0x239: movzx  r12d,BYTE PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_23e:
	/* 0x23e: lea    ebp,[r12+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_243:
	/* 0x243: mov    eax,0x27 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 39ULL);
x86_l_248:
	/* 0x248: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_24b:
	/* 0x24b: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_24d:
	/* 0x24d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24f:
	/* 0x24f: mov    eax,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_252:
	/* 0x252: sub    eax,DWORD PTR [rbx+0x74] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 116ULL);
x86_l_255:
	/* 0x255: cmp    ebp,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_257:
	/* 0x257: ja     336 <cil_from_netdev+0x336> */
	X86_SIM_X86_JCC(X86_CC_A, 0x257, 0x336, x86_l_336);
x86_l_25d:
	/* 0x25d: mov    rax,QWORD PTR [rbx+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_264:
	/* 0x264: mov    eax,DWORD PTR [rax+r12*1+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 12ULL);
x86_l_269:
	/* 0x269: mov    QWORD PTR [rsp+0xe],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60129542144ULL);
x86_l_272:
	/* 0x272: mov    WORD PTR [rsp+0x1e],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 128849018880ULL);
x86_l_279:
	/* 0x279: mov    QWORD PTR [rsp+0x16],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 94489280512ULL);
x86_l_282:
	/* 0x282: mov    DWORD PTR [rsp+0x8],0x40 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738432ULL);
x86_l_28a:
	/* 0x28a: mov    BYTE PTR [rsp+0xf],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 64424509441ULL);
x86_l_28f:
	/* 0x28f: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_293:
	/* 0x293: mov    WORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_29a:
	/* 0x29a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_29f:
	/* 0x29f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipcache_v2)));
x86_l_2a6:
	/* 0x2a6: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ab:
	/* 0x2ab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ad:
	/* 0x2ad: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2b0:
	/* 0x2b0: je     64c <cil_from_netdev+0x64c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2b0, 0x64c, x86_l_64c);
x86_l_2b6:
	/* 0x2b6: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b8:
	/* 0x2b8: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2ba:
	/* 0x2ba: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2bd:
	/* 0x2bd: cmovne ebp,eax */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RAX, X86_WIDTH_32, X86_CC_NE);
x86_l_2c0:
	/* 0x2c0: mov    DWORD PTR [rbx+0x28],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2c3:
	/* 0x2c3: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c7:
	/* 0x2c7: je     2e4 <cil_from_netdev+0x2e4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2c7, 0x2e4, x86_l_2e4);
x86_l_2c9:
	/* 0x2c9: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_2d1:
	/* 0x2d1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2d6:
	/* 0x2d6: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_percpu_trace_id)));
x86_l_2dd:
	/* 0x2dd: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e2:
	/* 0x2e2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e4:
	/* 0x2e4: mov    r15d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2e8:
	/* 0x2e8: mov    QWORD PTR [rsp],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ec:
	/* 0x2ec: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2f1:
	/* 0x2f1: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_2f8:
	/* 0x2f8: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_2fb:
	/* 0x2fb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fd:
	/* 0x2fd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_300:
	/* 0x300: je     660 <cil_from_netdev+0x660> */
	X86_SIM_X86_JCC(X86_CC_E, 0x300, 0x660, x86_l_660);
x86_l_306:
	/* 0x306: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_309:
	/* 0x309: add    QWORD PTR [rax+0x8],r15 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_30d:
	/* 0x30d: jmp    686 <cil_from_netdev+0x686> */
	X86_SIM_X86_JMP(0x30d, 0x686, x86_l_686);
x86_l_312:
	/* 0x312: movzx  ebp,BYTE PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_317:
	/* 0x317: add    ebp,0x1c */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_ADD, 28ULL);
x86_l_31a:
	/* 0x31a: mov    eax,0x27 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 39ULL);
x86_l_31f:
	/* 0x31f: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_322:
	/* 0x322: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_324:
	/* 0x324: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_326:
	/* 0x326: mov    eax,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_329:
	/* 0x329: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_32b:
	/* 0x32b: sub    ecx,DWORD PTR [rbx+0x74] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 116ULL);
x86_l_32e:
	/* 0x32e: cmp    ebp,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RCX, X86_WIDTH_32);
x86_l_330:
	/* 0x330: jbe    4f4 <cil_from_netdev+0x4f4> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x330, 0x4f4, x86_l_4f4);
x86_l_336:
	/* 0x336: mov    cl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_338:
	/* 0x338: mov    eax,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967162ULL);
x86_l_33d:
	/* 0x33d: mov    edx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_33f:
	/* 0x33f: neg    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_341:
	/* 0x341: cmovs  edx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RAX, X86_WIDTH_32, X86_CC_S);
x86_l_344:
	/* 0x344: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_347:
	/* 0x347: mov    QWORD PTR [rbx+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_34f:
	/* 0x34f: mov    DWORD PTR [rbx+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_352:
	/* 0x352: movabs rdx,0x48d010200000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 327919455969476608ULL);
x86_l_35c:
	/* 0x35c: mov    QWORD PTR [rbx+0x34],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_360:
	/* 0x360: mov    r15d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_364:
	/* 0x364: add    r14,0x30fefd */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 3211005ULL);
x86_l_36b:
	/* 0x36b: mov    QWORD PTR [rsp],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_36f:
	/* 0x36f: mov    BYTE PTR [rsp],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_372:
	/* 0x372: mov    BYTE PTR [rsp+0x1],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_376:
	/* 0x376: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_37b:
	/* 0x37b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_382:
	/* 0x382: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_385:
	/* 0x385: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_387:
	/* 0x387: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_38a:
	/* 0x38a: je     5d9 <cil_from_netdev+0x5d9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x38a, 0x5d9, x86_l_5d9);
x86_l_390:
	/* 0x390: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_393:
	/* 0x393: add    QWORD PTR [rax+0x8],r15 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_397:
	/* 0x397: jmp    5ff <cil_from_netdev+0x5ff> */
	X86_SIM_X86_JMP(0x397, 0x5ff, x86_l_5ff);
x86_l_39c:
	/* 0x39c: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3a0:
	/* 0x3a0: je     3c0 <cil_from_netdev+0x3c0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3a0, 0x3c0, x86_l_3c0);
x86_l_3a2:
	/* 0x3a2: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_3aa:
	/* 0x3aa: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3af:
	/* 0x3af: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_percpu_trace_id)));
x86_l_3b6:
	/* 0x3b6: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3bb:
	/* 0x3bb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3bd:
	/* 0x3bd: mov    ecx,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_3c0:
	/* 0x3c0: mov    ebx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RCX, X86_WIDTH_32);
x86_l_3c2:
	/* 0x3c2: add    r14,0x220000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 2228224ULL);
x86_l_3c9:
	/* 0x3c9: mov    QWORD PTR [rsp],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3cd:
	/* 0x3cd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3d2:
	/* 0x3d2: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_3d9:
	/* 0x3d9: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_3dc:
	/* 0x3dc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3de:
	/* 0x3de: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3e1:
	/* 0x3e1: je     61f <cil_from_netdev+0x61f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3e1, 0x61f, x86_l_61f);
x86_l_3e7:
	/* 0x3e7: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_3ea:
	/* 0x3ea: add    QWORD PTR [rax+0x8],rbx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_3ee:
	/* 0x3ee: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3f0:
	/* 0x3f0: jmp    971 <cil_from_netdev+0x971> */
	X86_SIM_X86_JMP(0x3f0, 0x971, x86_l_971);
x86_l_3f5:
	/* 0x3f5: add    rcx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3f8:
	/* 0x3f8: movzx  r12d,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_3fc:
	/* 0x3fc: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_3ff:
	/* 0x3ff: and    cl,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_AND, 14ULL);
x86_l_402:
	/* 0x402: cmp    cl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_8, 6ULL);
x86_l_405:
	/* 0x405: jb     abc <cil_from_netdev+0xabc> */
	X86_SIM_X86_JCC(X86_CC_B, 0x405, 0xabc, x86_l_abc);
x86_l_40b:
	/* 0x40b: movzx  r13d,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_40f:
	/* 0x40f: shl    r12d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHL, 2ULL);
x86_l_413:
	/* 0x413: and    r12d,0x3c */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 60ULL);
x86_l_417:
	/* 0x417: je     abc <cil_from_netdev+0xabc> */
	X86_SIM_X86_JCC(X86_CC_E, 0x417, 0xabc, x86_l_abc);
x86_l_41d:
	/* 0x41d: lea    r14d,[r13+0x14] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_421:
	/* 0x421: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_426:
	/* 0x426: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_429:
	/* 0x429: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_42c:
	/* 0x42c: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_42f:
	/* 0x42f: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_434:
	/* 0x434: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_436:
	/* 0x436: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_438:
	/* 0x438: js     98 <cil_from_netdev+0x98> */
	X86_SIM_X86_JCC(X86_CC_S, 0x438, 0x98, x86_l_98);
x86_l_43e:
	/* 0x43e: movzx  eax,BYTE PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_442:
	/* 0x442: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_444:
	/* 0x444: je     abc <cil_from_netdev+0xabc> */
	X86_SIM_X86_JCC(X86_CC_E, 0x444, 0xabc, x86_l_abc);
x86_l_44a:
	/* 0x44a: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_44d:
	/* 0x44d: jne    97d <cil_from_netdev+0x97d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x44d, 0x97d, x86_l_97d);
x86_l_453:
	/* 0x453: lea    r14d,[r13+0x15] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 21ULL);
x86_l_457:
	/* 0x457: jmp    9fa <cil_from_netdev+0x9fa> */
	X86_SIM_X86_JMP(0x457, 0x9fa, x86_l_9fa);
x86_l_45c:
	/* 0x45c: shr    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_45f:
	/* 0x45f: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_465:
	/* 0x465: add    ecx,0xfffff05d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 4294963293ULL);
x86_l_46b:
	/* 0x46b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_46d:
	/* 0x46d: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_470:
	/* 0x470: jb     971 <cil_from_netdev+0x971> */
	X86_SIM_X86_JCC(X86_CC_B, 0x470, 0x971, x86_l_971);
x86_l_476:
	/* 0x476: mov    QWORD PTR [rbx+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_47e:
	/* 0x47e: mov    QWORD PTR [rbx+0x30],0xb6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430390ULL);
x86_l_486:
	/* 0x486: mov    DWORD PTR [rbx+0x38],0x4e00102 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240599957762ULL);
x86_l_48d:
	/* 0x48d: mov    r14d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_491:
	/* 0x491: movabs rax,0x1045c0103 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 4368105731ULL);
x86_l_49b:
	/* 0x49b: add    rax,0x8400b3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 8650931ULL);
x86_l_4a1:
	/* 0x4a1: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4a5:
	/* 0x4a5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4aa:
	/* 0x4aa: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_4b1:
	/* 0x4b1: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_4b4:
	/* 0x4b4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b6:
	/* 0x4b6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4b9:
	/* 0x4b9: je     4c4 <cil_from_netdev+0x4c4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4b9, 0x4c4, x86_l_4c4);
x86_l_4bb:
	/* 0x4bb: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_4be:
	/* 0x4be: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4c2:
	/* 0x4c2: jmp    4ea <cil_from_netdev+0x4ea> */
	X86_SIM_X86_JMP(0x4c2, 0x4ea, x86_l_4ea);
x86_l_4c4:
	/* 0x4c4: mov    QWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_4cd:
	/* 0x4cd: mov    QWORD PTR [rsp+0x10],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4d2:
	/* 0x4d2: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4d7:
	/* 0x4d7: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_4de:
	/* 0x4de: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_4e1:
	/* 0x4e1: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e6:
	/* 0x4e6: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4e8:
	/* 0x4e8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ea:
	/* 0x4ea: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_4ef:
	/* 0x4ef: jmp    604 <cil_from_netdev+0x604> */
	X86_SIM_X86_JMP(0x4ef, 0x604, x86_l_604);
x86_l_4f4:
	/* 0x4f4: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4f8:
	/* 0x4f8: je     518 <cil_from_netdev+0x518> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4f8, 0x518, x86_l_518);
x86_l_4fa:
	/* 0x4fa: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_502:
	/* 0x502: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_507:
	/* 0x507: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_percpu_trace_id)));
x86_l_50e:
	/* 0x50e: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_513:
	/* 0x513: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_515:
	/* 0x515: mov    eax,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_518:
	/* 0x518: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_521:
	/* 0x521: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_52a:
	/* 0x52a: mov    r15d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_32);
x86_l_52d:
	/* 0x52d: lea    rax,[r14+0x140000] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1310720ULL);
x86_l_534:
	/* 0x534: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_538:
	/* 0x538: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_53d:
	/* 0x53d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_544:
	/* 0x544: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_547:
	/* 0x547: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_549:
	/* 0x549: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_54c:
	/* 0x54c: je     72c <cil_from_netdev+0x72c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x54c, 0x72c, x86_l_72c);
x86_l_552:
	/* 0x552: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_555:
	/* 0x555: add    QWORD PTR [rax+0x8],r15 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_559:
	/* 0x559: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_l2_announcements)));
x86_l_560:
	/* 0x560: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_563:
	/* 0x563: je     762 <cil_from_netdev+0x762> */
	X86_SIM_X86_JCC(X86_CC_E, 0x563, 0x762, x86_l_762);
x86_l_569:
	/* 0x569: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_interface_mac)));
x86_l_570:
	/* 0x570: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_573:
	/* 0x573: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_578:
	/* 0x578: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_57a:
	/* 0x57a: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_57f:
	/* 0x57f: je     95e <cil_from_netdev+0x95e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x57f, 0x95e, x86_l_95e);
x86_l_585:
	/* 0x585: mov    DWORD PTR [rsp+0x24],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 154618822657ULL);
x86_l_58d:
	/* 0x58d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_592:
	/* 0x592: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_runtime_config)));
x86_l_599:
	/* 0x599: lea    rsi,[rsp+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_59e:
	/* 0x59e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a0:
	/* 0x5a0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5a3:
	/* 0x5a3: je     5d2 <cil_from_netdev+0x5d2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5a3, 0x5d2, x86_l_5d2);
x86_l_5a5:
	/* 0x5a5: mov    r15,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5a8:
	/* 0x5a8: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_5ab:
	/* 0x5ab: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_5b0:
	/* 0x5b0: je     95e <cil_from_netdev+0x95e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5b0, 0x95e, x86_l_95e);
x86_l_5b6:
	/* 0x5b6: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_5bb:
	/* 0x5bb: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5bd:
	/* 0x5bd: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_5bf:
	/* 0x5bf: sub    rax,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_5c2:
	/* 0x5c2: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_l2_announcements_max_liveness)));
x86_l_5c9:
	/* 0x5c9: cmp    rax,QWORD PTR [rcx] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_5cc:
	/* 0x5cc: jbe    769 <cil_from_netdev+0x769> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x5cc, 0x769, x86_l_769);
x86_l_5d2:
	/* 0x5d2: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5d4:
	/* 0x5d4: jmp    95e <cil_from_netdev+0x95e> */
	X86_SIM_X86_JMP(0x5d4, 0x95e, x86_l_95e);
x86_l_5d9:
	/* 0x5d9: mov    QWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_5e2:
	/* 0x5e2: mov    QWORD PTR [rsp+0x10],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5e7:
	/* 0x5e7: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5ec:
	/* 0x5ec: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_5f3:
	/* 0x5f3: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_5f6:
	/* 0x5f6: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5fb:
	/* 0x5fb: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5fd:
	/* 0x5fd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5ff:
	/* 0x5ff: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_604:
	/* 0x604: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_60b:
	/* 0x60b: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_60e:
	/* 0x60e: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_613:
	/* 0x613: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_615:
	/* 0x615: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_61a:
	/* 0x61a: jmp    971 <cil_from_netdev+0x971> */
	X86_SIM_X86_JMP(0x61a, 0x971, x86_l_971);
x86_l_61f:
	/* 0x61f: mov    QWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_628:
	/* 0x628: mov    QWORD PTR [rsp+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_62d:
	/* 0x62d: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_632:
	/* 0x632: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_639:
	/* 0x639: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_63c:
	/* 0x63c: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_641:
	/* 0x641: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_643:
	/* 0x643: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_645:
	/* 0x645: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_647:
	/* 0x647: jmp    971 <cil_from_netdev+0x971> */
	X86_SIM_X86_JMP(0x647, 0x971, x86_l_971);
x86_l_64c:
	/* 0x64c: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_64e:
	/* 0x64e: mov    DWORD PTR [rbx+0x28],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_651:
	/* 0x651: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_655:
	/* 0x655: jne    2c9 <cil_from_netdev+0x2c9> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x655, 0x2c9, x86_l_2c9);
x86_l_65b:
	/* 0x65b: jmp    2e4 <cil_from_netdev+0x2e4> */
	X86_SIM_X86_JMP(0x65b, 0x2e4, x86_l_2e4);
x86_l_660:
	/* 0x660: mov    QWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_669:
	/* 0x669: mov    QWORD PTR [rsp+0x10],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_66e:
	/* 0x66e: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_673:
	/* 0x673: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_67a:
	/* 0x67a: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_67d:
	/* 0x67d: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_682:
	/* 0x682: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_684:
	/* 0x684: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_686:
	/* 0x686: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_68b:
	/* 0x68b: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_692:
	/* 0x692: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_695:
	/* 0x695: mov    edx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_69a:
	/* 0x69a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_69c:
	/* 0x69c: mov    DWORD PTR [rbx+0x28],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_69f:
	/* 0x69f: movabs rax,0x78c00000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8297876815872ULL);
x86_l_6a9:
	/* 0x6a9: mov    QWORD PTR [rbx+0x2c],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_6ad:
	/* 0x6ad: movabs rax,0x468010000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 317504873241247744ULL);
x86_l_6b7:
	/* 0x6b7: mov    QWORD PTR [rbx+0x34],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_6bb:
	/* 0x6bb: mov    r15d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_6bf:
	/* 0x6bf: add    r14,0xc0089 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 786569ULL);
x86_l_6c6:
	/* 0x6c6: mov    QWORD PTR [rsp],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6ca:
	/* 0x6ca: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6cf:
	/* 0x6cf: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_6d6:
	/* 0x6d6: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_6d9:
	/* 0x6d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6db:
	/* 0x6db: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6de:
	/* 0x6de: je     6e9 <cil_from_netdev+0x6e9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6de, 0x6e9, x86_l_6e9);
x86_l_6e0:
	/* 0x6e0: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_6e3:
	/* 0x6e3: add    QWORD PTR [rax+0x8],r15 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_6e7:
	/* 0x6e7: jmp    70f <cil_from_netdev+0x70f> */
	X86_SIM_X86_JMP(0x6e7, 0x70f, x86_l_70f);
x86_l_6e9:
	/* 0x6e9: mov    QWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_6f2:
	/* 0x6f2: mov    QWORD PTR [rsp+0x10],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6f7:
	/* 0x6f7: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_6fc:
	/* 0x6fc: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_703:
	/* 0x703: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_706:
	/* 0x706: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_70b:
	/* 0x70b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_70d:
	/* 0x70d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_70f:
	/* 0x70f: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_714:
	/* 0x714: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_71b:
	/* 0x71b: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_71e:
	/* 0x71e: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_723:
	/* 0x723: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_725:
	/* 0x725: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_727:
	/* 0x727: jmp    971 <cil_from_netdev+0x971> */
	X86_SIM_X86_JMP(0x727, 0x971, x86_l_971);
x86_l_72c:
	/* 0x72c: mov    QWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_735:
	/* 0x735: mov    QWORD PTR [rsp+0x10],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_73a:
	/* 0x73a: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_73f:
	/* 0x73f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_746:
	/* 0x746: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_749:
	/* 0x749: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_74e:
	/* 0x74e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_750:
	/* 0x750: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_752:
	/* 0x752: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_l2_announcements)));
x86_l_759:
	/* 0x759: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_75c:
	/* 0x75c: jne    569 <cil_from_netdev+0x569> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x75c, 0x569, x86_l_569);
x86_l_762:
	/* 0x762: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_764:
	/* 0x764: jmp    971 <cil_from_netdev+0x971> */
	X86_SIM_X86_JMP(0x764, 0x971, x86_l_971);
x86_l_769:
	/* 0x769: mov    eax,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_76c:
	/* 0x76c: sub    eax,DWORD PTR [rbx+0x74] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 116ULL);
x86_l_76f:
	/* 0x76f: mov    rcx,QWORD PTR [rbx+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_776:
	/* 0x776: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_779:
	/* 0x779: movzx  edx,BYTE PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_77e:
	/* 0x77e: movzx  esi,BYTE PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_783:
	/* 0x783: add    rsi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_786:
	/* 0x786: add    rsi,0x1c */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 28ULL);
x86_l_78a:
	/* 0x78a: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_78d:
	/* 0x78d: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_792:
	/* 0x792: ja     95e <cil_from_netdev+0x95e> */
	X86_SIM_X86_JCC(X86_CC_A, 0x792, 0x95e, x86_l_95e);
x86_l_798:
	/* 0x798: movzx  esi,WORD PTR [rcx+rdx*1+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RDX, 0, X86_WIDTH_16), 6ULL);
x86_l_79d:
	/* 0x79d: cmp    esi,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 256ULL);
x86_l_7a3:
	/* 0x7a3: jne    95e <cil_from_netdev+0x95e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x7a3, 0x95e, x86_l_95e);
x86_l_7a9:
	/* 0x7a9: movzx  edx,WORD PTR [rcx+rdx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RDX, 0, X86_WIDTH_16), 0ULL);
x86_l_7ad:
	/* 0x7ad: cmp    edx,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_7b3:
	/* 0x7b3: jne    95e <cil_from_netdev+0x95e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x7b3, 0x95e, x86_l_95e);
x86_l_7b9:
	/* 0x7b9: mov    edx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7bb:
	/* 0x7bb: mov    edi,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RDX, X86_WIDTH_32);
x86_l_7bd:
	/* 0x7bd: not    edi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_7bf:
	/* 0x7bf: movzx  esi,WORD PTR [rcx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_7c3:
	/* 0x7c3: mov    r8d,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RSI, X86_WIDTH_32);
x86_l_7c6:
	/* 0x7c6: xor    r8d,0xffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_XOR, 65535ULL);
x86_l_7cd:
	/* 0x7cd: or     r8d,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDI, X86_WIDTH_32, X86_ALU_OR);
x86_l_7d0:
	/* 0x7d0: je     7e6 <cil_from_netdev+0x7e6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7d0, 0x7e6, x86_l_7e6);
x86_l_7d2:
	/* 0x7d2: xor    edx,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 8ULL);
x86_l_7d6:
	/* 0x7d6: xor    si,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RSI, X86_RSP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 12ULL);
x86_l_7db:
	/* 0x7db: movzx  esi,si */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_WIDTH_16);
x86_l_7de:
	/* 0x7de: or     esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_OR);
x86_l_7e0:
	/* 0x7e0: jne    95e <cil_from_netdev+0x95e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x7e0, 0x95e, x86_l_95e);
x86_l_7e6:
	/* 0x7e6: movzx  eax,BYTE PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_7eb:
	/* 0x7eb: mov    rdx,QWORD PTR [rcx+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_7ef:
	/* 0x7ef: mov    QWORD PTR [rsp],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7f3:
	/* 0x7f3: mov    ebp,DWORD PTR [rcx+rax*1+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 14ULL);
x86_l_7f7:
	/* 0x7f7: mov    r12d,DWORD PTR [rcx+rax*1+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 24ULL);
x86_l_7fc:
	/* 0x7fc: mov    DWORD PTR [rsp+0x24],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_801:
	/* 0x801: mov    eax,DWORD PTR [rbx+0x94] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 148ULL);
x86_l_807:
	/* 0x807: mov    DWORD PTR [rsp+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_80b:
	/* 0x80b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_810:
	/* 0x810: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_l2_responder_v4)));
x86_l_817:
	/* 0x817: lea    rsi,[rsp+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_81c:
	/* 0x81c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_81e:
	/* 0x81e: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_821:
	/* 0x821: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_823:
	/* 0x823: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_826:
	/* 0x826: je     95e <cil_from_netdev+0x95e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x826, 0x95e, x86_l_95e);
x86_l_82c:
	/* 0x82c: mov    r15,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RCX, X86_WIDTH_64);
x86_l_82f:
	/* 0x82f: mov    DWORD PTR [rsp+0x34],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_834:
	/* 0x834: mov    DWORD PTR [rsp+0x30],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_838:
	/* 0x838: mov    WORD PTR [rsp+0x2e],0x200 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 197568496128ULL);
x86_l_83f:
	/* 0x83f: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_844:
	/* 0x844: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_849:
	/* 0x849: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_84c:
	/* 0x84c: mov    esi,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 6ULL);
x86_l_851:
	/* 0x851: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_856:
	/* 0x856: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_859:
	/* 0x859: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_85b:
	/* 0x85b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_85d:
	/* 0x85d: js     b4f <cil_from_netdev+0xb4f> */
	X86_SIM_X86_JCC(X86_CC_S, 0x85d, 0xb4f, x86_l_b4f);
x86_l_863:
	/* 0x863: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_868:
	/* 0x868: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_86b:
	/* 0x86b: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_86e:
	/* 0x86e: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_870:
	/* 0x870: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_875:
	/* 0x875: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_878:
	/* 0x878: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_87a:
	/* 0x87a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_87c:
	/* 0x87c: js     b4f <cil_from_netdev+0xb4f> */
	X86_SIM_X86_JCC(X86_CC_S, 0x87c, 0xb4f, x86_l_b4f);
x86_l_882:
	/* 0x882: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_887:
	/* 0x887: lea    rdx,[rsp+0x2e] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 46ULL);
x86_l_88c:
	/* 0x88c: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_88f:
	/* 0x88f: mov    esi,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 20ULL);
x86_l_894:
	/* 0x894: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_899:
	/* 0x899: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_89c:
	/* 0x89c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_89e:
	/* 0x89e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_8a0:
	/* 0x8a0: js     b4f <cil_from_netdev+0xb4f> */
	X86_SIM_X86_JCC(X86_CC_S, 0x8a0, 0xb4f, x86_l_b4f);
x86_l_8a6:
	/* 0x8a6: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_8ab:
	/* 0x8ab: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8b0:
	/* 0x8b0: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_8b3:
	/* 0x8b3: mov    esi,0x16 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 22ULL);
x86_l_8b8:
	/* 0x8b8: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_8bd:
	/* 0x8bd: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8c0:
	/* 0x8c0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8c2:
	/* 0x8c2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_8c4:
	/* 0x8c4: js     b4f <cil_from_netdev+0xb4f> */
	X86_SIM_X86_JCC(X86_CC_S, 0x8c4, 0xb4f, x86_l_b4f);
x86_l_8ca:
	/* 0x8ca: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_8cf:
	/* 0x8cf: lea    rdx,[rsp+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_8d4:
	/* 0x8d4: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_8d7:
	/* 0x8d7: mov    esi,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 28ULL);
x86_l_8dc:
	/* 0x8dc: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_8e1:
	/* 0x8e1: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8e4:
	/* 0x8e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8e6:
	/* 0x8e6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_8e8:
	/* 0x8e8: js     b4f <cil_from_netdev+0xb4f> */
	X86_SIM_X86_JCC(X86_CC_S, 0x8e8, 0xb4f, x86_l_b4f);
x86_l_8ee:
	/* 0x8ee: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_8f3:
	/* 0x8f3: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_8f6:
	/* 0x8f6: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_8f9:
	/* 0x8f9: mov    esi,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 32ULL);
x86_l_8fe:
	/* 0x8fe: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_903:
	/* 0x903: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_906:
	/* 0x906: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_908:
	/* 0x908: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_90a:
	/* 0x90a: js     b4f <cil_from_netdev+0xb4f> */
	X86_SIM_X86_JCC(X86_CC_S, 0x90a, 0xb4f, x86_l_b4f);
x86_l_910:
	/* 0x910: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_915:
	/* 0x915: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_91a:
	/* 0x91a: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_91c:
	/* 0x91c: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_91f:
	/* 0x91f: mov    esi,0x26 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 38ULL);
x86_l_924:
	/* 0x924: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_929:
	/* 0x929: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_92c:
	/* 0x92c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_92e:
	/* 0x92e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_930:
	/* 0x930: js     b4f <cil_from_netdev+0xb4f> */
	X86_SIM_X86_JCC(X86_CC_S, 0x930, 0xb4f, x86_l_b4f);
x86_l_936:
	/* 0x936: mov    rax,QWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_93a:
	/* 0x93a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_93d:
	/* 0x93d: je     945 <cil_from_netdev+0x945> */
	X86_SIM_X86_JCC(X86_CC_E, 0x93d, 0x945, x86_l_945);
x86_l_93f:
	/* 0x93f: mov    ebp,DWORD PTR [rax+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_945:
	/* 0x945: mov    eax,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 23ULL);
x86_l_94a:
	/* 0x94a: mov    edi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_32);
x86_l_94c:
	/* 0x94c: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_94e:
	/* 0x94e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_950:
	/* 0x950: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_953:
	/* 0x953: jne    95e <cil_from_netdev+0x95e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x953, 0x95e, x86_l_95e);
x86_l_955:
	/* 0x955: inc QWORD PTR [r15] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_959:
	/* 0x959: mov    eax,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_95e:
	/* 0x95e: mov    cl,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 2ULL);
x86_l_960:
	/* 0x960: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_962:
	/* 0x962: js     33d <cil_from_netdev+0x33d> */
	X86_SIM_X86_JCC(X86_CC_S, 0x962, 0x33d, x86_l_33d);
x86_l_968:
	/* 0x968: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_96b:
	/* 0x96b: je     33d <cil_from_netdev+0x33d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x96b, 0x33d, x86_l_33d);
x86_l_971:
	/* 0x971: add    rsp,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 56ULL);
x86_l_975:
	/* 0x975: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_977:
	/* 0x977: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_978:
	/* 0x978: jmp    b5b <cil_from_netdev+0xb5b> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_97d:
	/* 0x97d: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_982:
	/* 0x982: lea    esi,[r13+0x15] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 21ULL);
x86_l_986:
	/* 0x986: lea    rdx,[rsp+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_98b:
	/* 0x98b: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_98e:
	/* 0x98e: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_993:
	/* 0x993: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_995:
	/* 0x995: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_997:
	/* 0x997: js     98 <cil_from_netdev+0x98> */
	X86_SIM_X86_JCC(X86_CC_S, 0x997, 0x98, x86_l_98);
x86_l_99d:
	/* 0x99d: cmp    BYTE PTR [rsp],bpl */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9a1:
	/* 0x9a1: jne    9f2 <cil_from_netdev+0x9f2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x9a1, 0x9f2, x86_l_9f2);
x86_l_9a3:
	/* 0x9a3: movzx  eax,BYTE PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 36ULL);
x86_l_9a8:
	/* 0x9a8: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_9ab:
	/* 0x9ab: je     b17 <cil_from_netdev+0xb17> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9ab, 0xb17, x86_l_b17);
x86_l_9b1:
	/* 0x9b1: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_9b4:
	/* 0x9b4: je     aeb <cil_from_netdev+0xaeb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9b4, 0xaeb, x86_l_aeb);
x86_l_9ba:
	/* 0x9ba: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_9bd:
	/* 0x9bd: jne    98 <cil_from_netdev+0x98> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x9bd, 0x98, x86_l_98);
x86_l_9c3:
	/* 0x9c3: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_9c8:
	/* 0x9c8: add    r14d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_9cc:
	/* 0x9cc: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9d1:
	/* 0x9d1: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_9d4:
	/* 0x9d4: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_9d7:
	/* 0x9d7: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_9dc:
	/* 0x9dc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9de:
	/* 0x9de: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9e1:
	/* 0x9e1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_9e3:
	/* 0x9e3: movbe  cx,WORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOVBE_LOAD, X86_RCX, X86_RSP, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_9ea:
	/* 0x9ea: movzx  ecx,cx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_9ed:
	/* 0x9ed: jmp    b3e <cil_from_netdev+0xb3e> */
	X86_SIM_X86_JMP(0x9ed, 0xb3e, x86_l_b3e);
x86_l_9f2:
	/* 0x9f2: movzx  eax,BYTE PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 36ULL);
x86_l_9f7:
	/* 0x9f7: add    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_9fa:
	/* 0x9fa: add    r12d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R13, X86_WIDTH_32, X86_ALU_ADD);
x86_l_9fd:
	/* 0x9fd: add    r12d,0x14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_ADD, 20ULL);
x86_l_a01:
	/* 0xa01: cmp    r14d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R14, X86_R12, X86_WIDTH_32);
x86_l_a04:
	/* 0xa04: jae    abc <cil_from_netdev+0xabc> */
	X86_SIM_X86_JCC(X86_CC_AE, 0xa04, 0xabc, x86_l_abc);
x86_l_a0a:
	/* 0xa0a: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_a0f:
	/* 0xa0f: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_a12:
	/* 0xa12: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_a15:
	/* 0xa15: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_a18:
	/* 0xa18: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_a1d:
	/* 0xa1d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a1f:
	/* 0xa1f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a21:
	/* 0xa21: js     98 <cil_from_netdev+0x98> */
	X86_SIM_X86_JCC(X86_CC_S, 0xa21, 0x98, x86_l_98);
x86_l_a27:
	/* 0xa27: movzx  eax,BYTE PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_a2b:
	/* 0xa2b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a2d:
	/* 0xa2d: je     abc <cil_from_netdev+0xabc> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa2d, 0xabc, x86_l_abc);
x86_l_a33:
	/* 0xa33: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a36:
	/* 0xa36: je     a67 <cil_from_netdev+0xa67> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa36, 0xa67, x86_l_a67);
x86_l_a38:
	/* 0xa38: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_a3d:
	/* 0xa3d: lea    esi,[r14+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_a41:
	/* 0xa41: lea    rdx,[rsp+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_a46:
	/* 0xa46: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_a49:
	/* 0xa49: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_a4e:
	/* 0xa4e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a50:
	/* 0xa50: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a52:
	/* 0xa52: js     98 <cil_from_netdev+0x98> */
	X86_SIM_X86_JCC(X86_CC_S, 0xa52, 0x98, x86_l_98);
x86_l_a58:
	/* 0xa58: cmp    BYTE PTR [rsp],bpl */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a5c:
	/* 0xa5c: je     9a3 <cil_from_netdev+0x9a3> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa5c, 0x9a3, x86_l_9a3);
x86_l_a62:
	/* 0xa62: movzx  eax,BYTE PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 36ULL);
x86_l_a67:
	/* 0xa67: add    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_a6a:
	/* 0xa6a: cmp    r14d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R14, X86_R12, X86_WIDTH_32);
x86_l_a6d:
	/* 0xa6d: jae    abc <cil_from_netdev+0xabc> */
	X86_SIM_X86_JCC(X86_CC_AE, 0xa6d, 0xabc, x86_l_abc);
x86_l_a6f:
	/* 0xa6f: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_a74:
	/* 0xa74: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_a77:
	/* 0xa77: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_a7a:
	/* 0xa7a: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_a7d:
	/* 0xa7d: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_a82:
	/* 0xa82: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a84:
	/* 0xa84: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a86:
	/* 0xa86: js     98 <cil_from_netdev+0x98> */
	X86_SIM_X86_JCC(X86_CC_S, 0xa86, 0x98, x86_l_98);
x86_l_a8c:
	/* 0xa8c: cmp    BYTE PTR [rsp],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_a90:
	/* 0xa90: jb     abc <cil_from_netdev+0xabc> */
	X86_SIM_X86_JCC(X86_CC_B, 0xa90, 0xabc, x86_l_abc);
x86_l_a92:
	/* 0xa92: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_a97:
	/* 0xa97: lea    esi,[r14+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_a9b:
	/* 0xa9b: lea    rdx,[rsp+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_aa0:
	/* 0xaa0: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_aa3:
	/* 0xaa3: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_aa8:
	/* 0xaa8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_aaa:
	/* 0xaaa: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_aac:
	/* 0xaac: js     98 <cil_from_netdev+0x98> */
	X86_SIM_X86_JCC(X86_CC_S, 0xaac, 0x98, x86_l_98);
x86_l_ab2:
	/* 0xab2: cmp    BYTE PTR [rsp],bpl */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ab6:
	/* 0xab6: je     9a3 <cil_from_netdev+0x9a3> */
	X86_SIM_X86_JCC(X86_CC_E, 0xab6, 0x9a3, x86_l_9a3);
x86_l_abc:
	/* 0xabc: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_abf:
	/* 0xabf: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_ac7:
	/* 0xac7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_acc:
	/* 0xacc: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_percpu_trace_id)));
x86_l_ad3:
	/* 0xad3: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ad8:
	/* 0xad8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ada:
	/* 0xada: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_add:
	/* 0xadd: je     bf <cil_from_netdev+0xbf> */
	X86_SIM_X86_JCC(X86_CC_E, 0xadd, 0xbf, x86_l_bf);
x86_l_ae3:
	/* 0xae3: mov    QWORD PTR [rax],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ae6:
	/* 0xae6: jmp    bf <cil_from_netdev+0xbf> */
	X86_SIM_X86_JMP(0xae6, 0xbf, x86_l_bf);
x86_l_aeb:
	/* 0xaeb: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_af0:
	/* 0xaf0: add    r14d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_af4:
	/* 0xaf4: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_af9:
	/* 0xaf9: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_afc:
	/* 0xafc: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_aff:
	/* 0xaff: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_b04:
	/* 0xb04: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b06:
	/* 0xb06: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b08:
	/* 0xb08: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b0a:
	/* 0xb0a: movbe  r14d,DWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOVBE_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_b11:
	/* 0xb11: cmovs  r14d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R14, X86_RCX, X86_WIDTH_32, X86_CC_S);
x86_l_b15:
	/* 0xb15: jmp    b42 <cil_from_netdev+0xb42> */
	X86_SIM_X86_JMP(0xb15, 0xb42, x86_l_b42);
x86_l_b17:
	/* 0xb17: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_b1c:
	/* 0xb1c: add    r14d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_b20:
	/* 0xb20: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b25:
	/* 0xb25: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_b28:
	/* 0xb28: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_b2b:
	/* 0xb2b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_b30:
	/* 0xb30: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b32:
	/* 0xb32: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b35:
	/* 0xb35: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b37:
	/* 0xb37: movbe  rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOVBE_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_b3e:
	/* 0xb3e: cmovns r14,rcx */
	X86_SIM_L_EXEC_CMOV(X86_R14, X86_RCX, X86_WIDTH_64, X86_CC_NS);
x86_l_b42:
	/* 0xb42: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b44:
	/* 0xb44: jns    abf <cil_from_netdev+0xabf> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xb44, 0xabf, x86_l_abf);
x86_l_b4a:
	/* 0xb4a: jmp    98 <cil_from_netdev+0x98> */
	X86_SIM_X86_JMP(0xb4a, 0x98, x86_l_98);
x86_l_b4f:
	/* 0xb4f: mov    cl,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 2ULL);
x86_l_b51:
	/* 0xb51: mov    eax,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967155ULL);
x86_l_b56:
	/* 0xb56: jmp    33d <cil_from_netdev+0x33d> */
	X86_SIM_X86_JMP(0xb56, 0x33d, x86_l_33d);
x86_l_b5b:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
