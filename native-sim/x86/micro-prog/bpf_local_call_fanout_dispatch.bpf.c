#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int bpf_local_call_fanout_dispatch_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 24ULL);
x86_l_7:
	/* 0x7: mov    rsi,QWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a:
	/* 0xa: mov    rcx,QWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e:
	/* 0xe: mov    r15,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RSI, X86_WIDTH_64);
x86_l_11:
	/* 0x11: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13:
	/* 0x13: cmp    r15,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R15, X86_RCX, X86_WIDTH_64);
x86_l_16:
	/* 0x16: jbe    24 <bpf_local_call_fanout_dispatch_xdp+0x24> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x16, 0x24, x86_l_24);
x86_l_18:
	/* 0x18: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1c:
	/* 0x1c: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_1e:
	/* 0x1e: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_1f:
	/* 0x1f: jmp    2e4 <local_call_bytes+0xdd> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_24:
	/* 0x24: lea    rdx,[r15+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28:
	/* 0x28: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d:
	/* 0x2d: cmp    rdx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_30:
	/* 0x30: ja     18 <bpf_local_call_fanout_dispatch_xdp+0x18> */
	X86_SIM_X86_JCC(X86_CC_A, 0x30, 0x18, x86_l_18);
x86_l_32:
	/* 0x32: lea    rdx,[r15+0x190] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 400ULL);
x86_l_39:
	/* 0x39: cmp    rdx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_3c:
	/* 0x3c: ja     18 <bpf_local_call_fanout_dispatch_xdp+0x18> */
	X86_SIM_X86_JCC(X86_CC_A, 0x3c, 0x18, x86_l_18);
x86_l_3e:
	/* 0x3e: cmp    DWORD PTR [r15+0x8],0x10 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738384ULL);
x86_l_43:
	/* 0x43: jne    18 <bpf_local_call_fanout_dispatch_xdp+0x18> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x43, 0x18, x86_l_18);
x86_l_45:
	/* 0x45: cmp    DWORD PTR [r15+0xc],0x18 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607576ULL);
x86_l_4a:
	/* 0x4a: jne    18 <bpf_local_call_fanout_dispatch_xdp+0x18> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4a, 0x18, x86_l_18);
x86_l_4c:
	/* 0x4c: mov    QWORD PTR [rsp+0x10],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_51:
	/* 0x51: movabs rdi,0x243f6a8885a308d3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_64, 2611923443488327891ULL);
x86_l_5b:
	/* 0x5b: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5e:
	/* 0x5e: mov    r13d,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 23ULL);
x86_l_64:
	/* 0x64: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_67:
	/* 0x67: jmp    9d <bpf_local_call_fanout_dispatch_xdp+0x9d> */
	X86_SIM_X86_JMP(0x67, 0x9d, x86_l_9d);
x86_l_69:
	/* 0x69: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6e:
	/* 0x6e: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_70:
	/* 0x70: call   fd <local_call_pressure> */
	X86_SIM_X86_CALL(x86_l_fd, 0x75ULL);
x86_l_75:
	/* 0x75: mov    ecx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_32);
x86_l_78:
	/* 0x78: and    cl,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_AND, 56ULL);
x86_l_7b:
	/* 0x7b: shlx   rcx,rbx,rcx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RCX, X86_RBX, X86_WIDTH_64, X86_RCX, X86_ALU_SHL);
x86_l_80:
	/* 0x80: mov    edi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_32);
x86_l_82:
	/* 0x82: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_85:
	/* 0x85: xor    rdi,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RAX, X86_WIDTH_64, X86_ALU_XOR);
x86_l_88:
	/* 0x88: add    r14,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_8c:
	/* 0x8c: add    r12d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_ADD, 16ULL);
x86_l_90:
	/* 0x90: add    r13,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_94:
	/* 0x94: cmp    r14,0x80 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_64, 128ULL);
x86_l_9b:
	/* 0x9b: je     eb <bpf_local_call_fanout_dispatch_xdp+0xeb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9b, 0xeb, x86_l_eb);
x86_l_9d:
	/* 0x9d: movzx  ebx,BYTE PTR [r15+r13*1-0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_8), 18446744073709551609ULL);
x86_l_a3:
	/* 0xa3: and    ebx,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_AND, 3ULL);
x86_l_a6:
	/* 0xa6: mov    ebp,DWORD PTR [r15+r13*1-0x3] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 18446744073709551613ULL);
x86_l_ab:
	/* 0xab: xor    ebp,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ae:
	/* 0xae: lea    rdx,[r13-0xf] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551601ULL);
x86_l_b2:
	/* 0xb2: cmp    rbx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 2ULL);
x86_l_b6:
	/* 0xb6: je     cf <bpf_local_call_fanout_dispatch_xdp+0xcf> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb6, 0xcf, x86_l_cf);
x86_l_b8:
	/* 0xb8: cmp    ebx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_bb:
	/* 0xbb: je     69 <bpf_local_call_fanout_dispatch_xdp+0x69> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbb, 0x69, x86_l_69);
x86_l_bd:
	/* 0xbd: test   ebx,ebx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_32);
x86_l_bf:
	/* 0xbf: jne    dd <bpf_local_call_fanout_dispatch_xdp+0xdd> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xbf, 0xdd, x86_l_dd);
x86_l_c1:
	/* 0xc1: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c6:
	/* 0xc6: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_c8:
	/* 0xc8: call   14b <local_call_linear> */
	X86_SIM_X86_CALL(x86_l_14b, 0xcdULL);
x86_l_cd:
	/* 0xcd: jmp    75 <bpf_local_call_fanout_dispatch_xdp+0x75> */
	X86_SIM_X86_JMP(0xcd, 0x75, x86_l_75);
x86_l_cf:
	/* 0xcf: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d4:
	/* 0xd4: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_d6:
	/* 0xd6: call   18b <local_call_crossload> */
	X86_SIM_X86_CALL(x86_l_18b, 0xdbULL);
x86_l_db:
	/* 0xdb: jmp    75 <bpf_local_call_fanout_dispatch_xdp+0x75> */
	X86_SIM_X86_JMP(0xdb, 0x75, x86_l_75);
x86_l_dd:
	/* 0xdd: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e2:
	/* 0xe2: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_e4:
	/* 0xe4: call   207 <local_call_bytes> */
	X86_SIM_X86_CALL(x86_l_207, 0xe9ULL);
x86_l_e9:
	/* 0xe9: jmp    75 <bpf_local_call_fanout_dispatch_xdp+0x75> */
	X86_SIM_X86_JMP(0xe9, 0x75, x86_l_75);
x86_l_eb:
	/* 0xeb: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f0:
	/* 0xf0: mov    QWORD PTR [rax],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f3:
	/* 0xf3: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_f8:
	/* 0xf8: jmp    18 <bpf_local_call_fanout_dispatch_xdp+0x18> */
	X86_SIM_X86_JMP(0xf8, 0x18, x86_l_18);
x86_l_2e4:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
	/* native subroutine native_link_sub_fd */
x86_l_fd:
	/* 0xfd: mov    eax,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RDX, X86_WIDTH_32);
x86_l_ff:
	/* 0xff: mov    rdx,QWORD PTR [rax+rsi*1+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 8ULL);
x86_l_104:
	/* 0x104: mov    rsi,QWORD PTR [rax+rsi*1+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 16ULL);
x86_l_109:
	/* 0x109: xor    rdi,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDX, X86_WIDTH_64, X86_ALU_XOR);
x86_l_10c:
	/* 0x10c: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_10e:
	/* 0x10e: shl    rax,0x11 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 17ULL);
x86_l_112:
	/* 0x112: add    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_115:
	/* 0x115: lea    rcx,[rdi*8+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 3), 0ULL);
x86_l_11d:
	/* 0x11d: shr    rsi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_SHR, 2ULL);
x86_l_121:
	/* 0x121: xor    rsi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_64, X86_ALU_XOR);
x86_l_124:
	/* 0x124: xor    rdx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_XOR);
x86_l_127:
	/* 0x127: rorx   rcx,rdx,0x3b */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RCX, X86_RDX, X86_WIDTH_64, 0, 59ULL);
x86_l_12d:
	/* 0x12d: lea    rdx,[rsi+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_131:
	/* 0x131: rorx   rdx,rdx,0x35 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 53ULL);
x86_l_137:
	/* 0x137: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_13a:
	/* 0x13a: xor    rdi,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RAX, X86_WIDTH_64, X86_ALU_XOR);
x86_l_13d:
	/* 0x13d: shr    rax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 7ULL);
x86_l_141:
	/* 0x141: xor    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_XOR);
x86_l_144:
	/* 0x144: add    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_147:
	/* 0x147: xor    rax,rdi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_64, X86_ALU_XOR);
x86_l_14a:
	/* 0x14a: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);

	/* native subroutine native_link_sub_14b */
x86_l_14b:
	/* 0x14b: mov    edx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_14d:
	/* 0x14d: mov    rax,QWORD PTR [rdx+rsi*1+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 8ULL);
x86_l_152:
	/* 0x152: lea    r8,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_156:
	/* 0x156: mov    r9d,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RCX, X86_WIDTH_32);
x86_l_159:
	/* 0x159: add    rdi,r9 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R9, X86_WIDTH_64, X86_ALU_ADD);
x86_l_15c:
	/* 0x15c: add    r8,rdi */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_15f:
	/* 0x15f: add    r8,QWORD PTR [rdx+rsi*1+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R8, X86_RDX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_164:
	/* 0x164: shl    r9,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_64, X86_ALU_SHL, 11ULL);
x86_l_168:
	/* 0x168: add    r9,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_64, X86_ALU_ADD);
x86_l_16b:
	/* 0x16b: and    ecx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_16e:
	/* 0x16e: lea    edx,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_171:
	/* 0x171: shlx   rdx,r9,rdx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_R9, X86_WIDTH_64, X86_RDX, X86_ALU_SHL);
x86_l_176:
	/* 0x176: not    cl */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_NOT, 0);
x86_l_178:
	/* 0x178: shrx   rcx,r9,rcx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RCX, X86_R9, X86_WIDTH_64, X86_RCX, X86_ALU_SHR);
x86_l_17d:
	/* 0x17d: or     rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_OR);
x86_l_180:
	/* 0x180: xor    rcx,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R8, X86_WIDTH_64, X86_ALU_XOR);
x86_l_183:
	/* 0x183: shr    rax,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 3ULL);
x86_l_187:
	/* 0x187: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_18a:
	/* 0x18a: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);

	/* native subroutine native_link_sub_18b */
x86_l_18b:
	/* 0x18b: mov    r11d,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_RDX, X86_WIDTH_32);
x86_l_18e:
	/* 0x18e: movzx  eax,BYTE PTR [rsi+r11*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R11, 0, X86_WIDTH_8), 0ULL);
x86_l_193:
	/* 0x193: lea    r8,[r11+0x4] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_197:
	/* 0x197: movzx  edx,BYTE PTR [rsi+r11*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R11, 0, X86_WIDTH_8), 4ULL);
x86_l_19d:
	/* 0x19d: movsxd r10,r8d */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_R10, X86_R8, X86_WIDTH_64, X86_WIDTH_32);
x86_l_1a0:
	/* 0x1a0: movzx  r9d,BYTE PTR [rsi+r10*1+0x1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R10, 0, X86_WIDTH_8), 1ULL);
x86_l_1a6:
	/* 0x1a6: movzx  r8d,BYTE PTR [rsi+r10*1+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R10, 0, X86_WIDTH_8), 2ULL);
x86_l_1ac:
	/* 0x1ac: add    rdi,QWORD PTR [rsi+r11*1+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_R11, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1b1:
	/* 0x1b1: movzx  r10d,BYTE PTR [rsi+r10*1+0x3] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R10, 0, X86_WIDTH_8), 3ULL);
x86_l_1b7:
	/* 0x1b7: mov    rsi,QWORD PTR [rsi+r11*1+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_R11, 0), 16ULL);
x86_l_1bc:
	/* 0x1bc: xor    rsi,rdi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDI, X86_WIDTH_64, X86_ALU_XOR);
x86_l_1bf:
	/* 0x1bf: and    al,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_AND, 7ULL);
x86_l_1c1:
	/* 0x1c1: lea    r11d,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_1c5:
	/* 0x1c5: shlx   r11,rsi,r11 */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_R11, X86_RSI, X86_WIDTH_64, X86_R11, X86_ALU_SHL);
x86_l_1ca:
	/* 0x1ca: mov    ecx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_1cc:
	/* 0x1cc: shlx   rcx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RCX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SHL);
x86_l_1d1:
	/* 0x1d1: not    al */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_NOT, 0);
x86_l_1d3:
	/* 0x1d3: shrx   rax,rsi,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RAX, X86_RSI, X86_WIDTH_64, X86_RAX, X86_ALU_SHR);
x86_l_1d8:
	/* 0x1d8: or     rax,r11 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R11, X86_WIDTH_64, X86_ALU_OR);
x86_l_1db:
	/* 0x1db: shl    r10,0x21 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_64, X86_ALU_SHL, 33ULL);
x86_l_1df:
	/* 0x1df: shl    r8,0x19 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_64, X86_ALU_SHL, 25ULL);
x86_l_1e3:
	/* 0x1e3: shl    r9d,0x11 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_32, X86_ALU_SHL, 17ULL);
x86_l_1e7:
	/* 0x1e7: shl    edx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHL, 9ULL);
x86_l_1ea:
	/* 0x1ea: or     edx,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_32, X86_ALU_OR);
x86_l_1ed:
	/* 0x1ed: or     rdx,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R8, X86_WIDTH_64, X86_ALU_OR);
x86_l_1f0:
	/* 0x1f0: or     rdx,r10 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R10, X86_WIDTH_64, X86_ALU_OR);
x86_l_1f3:
	/* 0x1f3: xor    rdx,rdi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDI, X86_WIDTH_64, X86_ALU_XOR);
x86_l_1f6:
	/* 0x1f6: xor    rdx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_XOR);
x86_l_1f9:
	/* 0x1f9: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1fc:
	/* 0x1fc: shr    rax,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 5ULL);
x86_l_200:
	/* 0x200: xor    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_XOR);
x86_l_203:
	/* 0x203: add    rax,rdi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_206:
	/* 0x206: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);

	/* native subroutine native_link_sub_207 */
x86_l_207:
	/* 0x207: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_209:
	/* 0x209: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_20b:
	/* 0x20b: movzx  edx,BYTE PTR [rsi+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_20f:
	/* 0x20f: movabs r8,0x94d049bb133111eb */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_64, 10723151780598845931ULL);
x86_l_219:
	/* 0x219: xor    r8,rdi */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDI, X86_WIDTH_64, X86_ALU_XOR);
x86_l_21c:
	/* 0x21c: xor    r8,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDX, X86_WIDTH_64, X86_ALU_XOR);
x86_l_21f:
	/* 0x21f: add    r8,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_222:
	/* 0x222: rorx   rdx,r8,0x3f */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_R8, X86_WIDTH_64, 0, 63ULL);
x86_l_228:
	/* 0x228: movzx  edi,BYTE PTR [rsi+rcx*1+0x1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 1ULL);
x86_l_22d:
	/* 0x22d: shl    edi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHL, 8ULL);
x86_l_230:
	/* 0x230: xor    rdi,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDX, X86_WIDTH_64, X86_ALU_XOR);
x86_l_233:
	/* 0x233: lea    rdx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_237:
	/* 0x237: inc    rdx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_23a:
	/* 0x23a: rorx   rdx,rdx,0x3e */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 62ULL);
x86_l_240:
	/* 0x240: movzx  edi,BYTE PTR [rsi+rcx*1+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 2ULL);
x86_l_245:
	/* 0x245: shl    edi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHL, 16ULL);
x86_l_248:
	/* 0x248: xor    rdi,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDX, X86_WIDTH_64, X86_ALU_XOR);
x86_l_24b:
	/* 0x24b: lea    rdx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_24f:
	/* 0x24f: add    rdx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_253:
	/* 0x253: rorx   rdx,rdx,0x3d */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 61ULL);
x86_l_259:
	/* 0x259: movzx  edi,BYTE PTR [rsi+rcx*1+0x3] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 3ULL);
x86_l_25e:
	/* 0x25e: shl    edi,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHL, 24ULL);
x86_l_261:
	/* 0x261: xor    rdi,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDX, X86_WIDTH_64, X86_ALU_XOR);
x86_l_264:
	/* 0x264: lea    rdx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_268:
	/* 0x268: add    rdx,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 3ULL);
x86_l_26c:
	/* 0x26c: rorx   rdx,rdx,0x3c */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 60ULL);
x86_l_272:
	/* 0x272: movzx  edi,BYTE PTR [rsi+rcx*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 4ULL);
x86_l_277:
	/* 0x277: shl    rdi,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_27b:
	/* 0x27b: xor    rdi,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDX, X86_WIDTH_64, X86_ALU_XOR);
x86_l_27e:
	/* 0x27e: lea    rdx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_282:
	/* 0x282: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_286:
	/* 0x286: rorx   rdx,rdx,0x3b */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 59ULL);
x86_l_28c:
	/* 0x28c: movzx  edi,BYTE PTR [rsi+rcx*1+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 5ULL);
x86_l_291:
	/* 0x291: shl    rdi,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_SHL, 40ULL);
x86_l_295:
	/* 0x295: xor    rdi,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDX, X86_WIDTH_64, X86_ALU_XOR);
x86_l_298:
	/* 0x298: lea    rdx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_29c:
	/* 0x29c: add    rdx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 5ULL);
x86_l_2a0:
	/* 0x2a0: rorx   rdx,rdx,0x3a */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 58ULL);
x86_l_2a6:
	/* 0x2a6: movzx  edi,BYTE PTR [rsi+rcx*1+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 6ULL);
x86_l_2ab:
	/* 0x2ab: shl    rdi,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_SHL, 48ULL);
x86_l_2af:
	/* 0x2af: xor    rdi,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDX, X86_WIDTH_64, X86_ALU_XOR);
x86_l_2b2:
	/* 0x2b2: lea    rdx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_2b6:
	/* 0x2b6: add    rdx,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 6ULL);
x86_l_2ba:
	/* 0x2ba: rorx   rdx,rdx,0x39 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 57ULL);
x86_l_2c0:
	/* 0x2c0: movzx  edi,BYTE PTR [rsi+rcx*1+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 7ULL);
x86_l_2c5:
	/* 0x2c5: shl    rdi,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_SHL, 56ULL);
x86_l_2c9:
	/* 0x2c9: xor    rdi,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDX, X86_WIDTH_64, X86_ALU_XOR);
x86_l_2cc:
	/* 0x2cc: add    rax,rdi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2cf:
	/* 0x2cf: add    rax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 7ULL);
x86_l_2d3:
	/* 0x2d3: rorx   rax,rax,0x38 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 56ULL);
x86_l_2d9:
	/* 0x2d9: add    rax,QWORD PTR [rsi+rcx*1+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2de:
	/* 0x2de: xor    rax,QWORD PTR [rsi+rcx*1+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 16ULL);
x86_l_2e3:
	/* 0x2e3: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);

x86_sim_ret_dispatch:
	switch (__x86_sim_ret_addr) {
	case 0x75ULL: goto x86_l_75;
	case 0xcdULL: goto x86_l_cd;
	case 0xdbULL: goto x86_l_db;
	case 0xe9ULL: goto x86_l_e9;
	}

}

X86_SIM_LICENSE();
