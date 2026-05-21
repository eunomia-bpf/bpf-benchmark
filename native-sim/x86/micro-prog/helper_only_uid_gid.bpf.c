#include "../x86_sim_local_bpf.h"

/*
 * Stage 2 POC: smallest deterministic single-helper program.
 *
 * Calls bpf_get_current_uid_gid() once and writes the result to
 * data[0..8]. Both runtimes run inside the same uid (root, via the
 * micro suite's `sudo: true`), so the value is bit-identical between
 * native_lab and kernel and can be verified by exact-equality
 * comparison -- unlike ktime / pid_tgid baselines which advance or
 * differ between the two TEST_RUN call sites.
 */
#include "../../test/include/native_helpers.h"

SEC("xdp")
int helper_only_uid_gid_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: mov    rbx,QWORD PTR [rdi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3:
	/* 0x3: lea    rcx,[rbx+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7:
	/* 0x7: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_9:
	/* 0x9: cmp    rcx,QWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_d:
	/* 0xd: ja     0x1e */
	X86_SIM_X86_JCC(X86_CC_A, 0xd, 0x1e, x86_l_1e);
x86_l_f:
	/* 0xf: call   QWORD PTR [rip+0x0] */
	X86_SIM_BPF_CALL_bpf_get_current_uid_gid();
x86_l_15:
	/* 0x15: mov    QWORD PTR [rbx],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18:
	/* 0x18: mov    eax,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_1e:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
