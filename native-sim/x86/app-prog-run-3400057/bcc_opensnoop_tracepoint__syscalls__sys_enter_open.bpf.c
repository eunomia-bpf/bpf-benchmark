extern char start;
extern char targ_pid;
extern char targ_tgid;
extern char targ_uid;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int bcc_opensnoop_tracepoint__syscalls__sys_enter_open_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_2:
	/* 0x2: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_3:
	/* 0x3: sub    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 24ULL);
x86_l_7:
	/* 0x7: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_a:
	/* 0xa: call   f <tracepoint__syscalls__sys_enter_open+0xf> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_get_current_pid_tgid);
x86_l_f:
	/* 0xf: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_13:
	/* 0x13: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&targ_tgid)));
x86_l_1a:
	/* 0x1a: cmp    DWORD PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d:
	/* 0x1d: je     2c <tracepoint__syscalls__sys_enter_open+0x2c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1d, 0x2c, x86_l_2c);
x86_l_1f:
	/* 0x1f: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_22:
	/* 0x22: shr    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_26:
	/* 0x26: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28:
	/* 0x28: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_2a:
	/* 0x2a: jne    8a <tracepoint__syscalls__sys_enter_open+0x8a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2a, 0x8a, x86_l_8a);
x86_l_2c:
	/* 0x2c: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&targ_pid)));
x86_l_33:
	/* 0x33: cmp    DWORD PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_36:
	/* 0x36: je     3e <tracepoint__syscalls__sys_enter_open+0x3e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x36, 0x3e, x86_l_3e);
x86_l_38:
	/* 0x38: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3a:
	/* 0x3a: cmp    ecx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_3c:
	/* 0x3c: jne    8a <tracepoint__syscalls__sys_enter_open+0x8a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x3c, 0x8a, x86_l_8a);
x86_l_3e:
	/* 0x3e: mov    r14,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&targ_uid)));
x86_l_45:
	/* 0x45: mov    eax,DWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_48:
	/* 0x48: cmp    eax,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_4b:
	/* 0x4b: je     59 <tracepoint__syscalls__sys_enter_open+0x59> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4b, 0x59, x86_l_59);
x86_l_4d:
	/* 0x4d: call   52 <tracepoint__syscalls__sys_enter_open+0x52> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_get_current_uid_gid);
x86_l_52:
	/* 0x52: mov    ecx,DWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_55:
	/* 0x55: cmp    ecx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_57:
	/* 0x57: jne    8a <tracepoint__syscalls__sys_enter_open+0x8a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x57, 0x8a, x86_l_8a);
x86_l_59:
	/* 0x59: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_62:
	/* 0x62: mov    rax,QWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_66:
	/* 0x66: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6b:
	/* 0x6b: mov    eax,DWORD PTR [rbx+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6e:
	/* 0x6e: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_72:
	/* 0x72: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&start)));
x86_l_79:
	/* 0x79: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_7e:
	/* 0x7e: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_83:
	/* 0x83: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_85:
	/* 0x85: call   8a <tracepoint__syscalls__sys_enter_open+0x8a> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_map_update_elem);
x86_l_8a:
	/* 0x8a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8c:
	/* 0x8c: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_90:
	/* 0x90: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_91:
	/* 0x91: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_93:
	/* 0x93: jmp    98 <tracepoint__syscalls__sys_enter_open+0x98> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_98:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
