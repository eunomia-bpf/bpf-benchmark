extern char cgroup_map;
extern char filter_cg;
extern char infobyreq;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int bcc_biosnoop_blk_account_io_merge_bio_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_1:
	/* 0x1: sub    rsp,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 32ULL);
x86_l_5:
	/* 0x5: mov    rbx,QWORD PTR [rdi+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_9:
	/* 0x9: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&filter_cg)));
x86_l_10:
	/* 0x10: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13:
	/* 0x13: je     28 <blk_account_io_merge_bio+0x28> */
	X86_SIM_X86_JCC(X86_CC_E, 0x13, 0x28, x86_l_28);
x86_l_15:
	/* 0x15: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cgroup_map)));
x86_l_1c:
	/* 0x1c: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e:
	/* 0x1e: call   23 <blk_account_io_merge_bio+0x23> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_current_task_under_cgroup);
x86_l_23:
	/* 0x23: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_26:
	/* 0x26: je     71 <blk_account_io_merge_bio+0x71> */
	X86_SIM_X86_JCC(X86_CC_E, 0x26, 0x71, x86_l_71);
x86_l_28:
	/* 0x28: mov    QWORD PTR [rsp],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c:
	/* 0x2c: call   31 <blk_account_io_merge_bio+0x31> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_get_current_pid_tgid);
x86_l_31:
	/* 0x31: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3a:
	/* 0x3a: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_43:
	/* 0x43: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_47:
	/* 0x47: mov    DWORD PTR [rsp+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4b:
	/* 0x4b: lea    rbx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_50:
	/* 0x50: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_53:
	/* 0x53: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_58:
	/* 0x58: call   5d <blk_account_io_merge_bio+0x5d> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_get_current_comm);
x86_l_5d:
	/* 0x5d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&infobyreq)));
x86_l_64:
	/* 0x64: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_67:
	/* 0x67: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_6a:
	/* 0x6a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6c:
	/* 0x6c: call   71 <blk_account_io_merge_bio+0x71> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_map_update_elem);
x86_l_71:
	/* 0x71: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_73:
	/* 0x73: add    rsp,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_77:
	/* 0x77: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_78:
	/* 0x78: jmp    7d <blk_account_io_merge_bio+0x7d> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_7d:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
