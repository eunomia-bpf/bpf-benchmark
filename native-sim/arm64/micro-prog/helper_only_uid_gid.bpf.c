#define ARM64_SIM_ENABLE_STACK 1
#define ARM64_SIM_RETURN_CASES \
	case 0x24ULL: __a64_lr = 0; goto arm64_l_24;
#include "../arm64_sim_local_bpf.h"

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
int helper_only_uid_gid_arm64_sim_xdp(struct xdp_md *ctx)
{
	ARM64_SIM_ENTRY_XDP(ctx);
arm64_l_0:
	/* 0x0: ldp x8, x9, [x0] */
	ARM64_SIM_RUN_OP3(ARM64_OP_LDP, ARM64_X8, ARM64_X9, ARM64_X0, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_MEM(ARM64_REG_NONE, ARM64_MOD_NONE, 0, 0), 0ULL);
arm64_l_4:
	/* 0x4: add x10, x8, #0x8 */
	ARM64_SIM_RUN_OP3(ARM64_OP_ALU_IMM, ARM64_X10, ARM64_X8, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_ALU(ARM64_ALU_ADD, ARM64_MOD_NONE, 0), 8ULL);
arm64_l_8:
	/* 0x8: cmp x10, x9 */
	ARM64_SIM_RUN_OP3(ARM64_OP_CMP_REG, ARM64_X10, ARM64_X9, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_ALU(0, ARM64_MOD_NONE, 0), 0);
arm64_l_c:
	/* 0xc: b.ls 18 <helper_only_uid_gid+0x18> */
	ARM64_SIM_A64_JCC(ARM64_COND_LS, 0xc, 0x18, arm64_l_18);
arm64_l_10:
	/* 0x10: mov w0, wzr */
	ARM64_SIM_RUN_OP3(ARM64_OP_MOV_REG, ARM64_X0, ARM64_XZR, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_32, 0, 0);
arm64_l_14:
	/* 0x14: b 38 <helper_only_uid_gid+0x38> */
	ARM64_SIM_A64_JMP(0x14, 0x38, arm64_l_38);
arm64_l_18:
	/* 0x18: stp x30, x19, [sp, #-16]! */
	ARM64_SIM_RUN_OP3(ARM64_OP_STP, ARM64_SP, ARM64_X30, ARM64_X19, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_MEM(ARM64_REG_NONE, ARM64_MOD_NONE, 0, ARM64_MEM_PRE), 18446744073709551600ULL);
arm64_l_1c:
	/* 0x1c: mov x19, x8 */
	ARM64_SIM_RUN_OP3(ARM64_OP_MOV_REG, ARM64_X19, ARM64_X8, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, 0, 0);
arm64_l_20:
	/* 0x20: bl 0 <bpf_get_current_uid_gid> */
	ARM64_SIM_BPF_CALL_bpf_get_current_uid_gid();
arm64_l_24:
	/* 0x24: mov x8, x0 */
	ARM64_SIM_RUN_OP3(ARM64_OP_MOV_REG, ARM64_X8, ARM64_X0, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, 0, 0);
arm64_l_28:
	/* 0x28: mov w0, #0x2 */
	ARM64_SIM_RUN_OP3(ARM64_OP_MOV_IMM, ARM64_X0, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_32, 0, 2ULL);
arm64_l_2c:
	/* 0x2c: str x8, [x19] */
	ARM64_SIM_RUN_OP3(ARM64_OP_STORE, ARM64_X19, ARM64_X8, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_MEM(ARM64_REG_NONE, ARM64_MOD_NONE, 0, 0), 0ULL);
arm64_l_30:
	/* 0x30: ldp x30, x19, [sp], #16 */
	ARM64_SIM_RUN_OP3(ARM64_OP_LDP, ARM64_X30, ARM64_X19, ARM64_SP, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_MEM(ARM64_REG_NONE, ARM64_MOD_NONE, 0, ARM64_MEM_POST), 16ULL);
arm64_l_34:
	/* 0x34: b 38 <helper_only_uid_gid+0x38> */
	ARM64_SIM_A64_JMP(0x34, 0x38, arm64_l_38);
arm64_l_38:
	/* 0x38: mov x7, x0 */
	ARM64_SIM_RUN_OP3(ARM64_OP_MOV_REG, ARM64_X7, ARM64_X0, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, 0, 0);
	ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X0, ARM64_SIM_L_READ_REG(ARM64_X7), ARM64_WIDTH_64);
	ARM64_SIM_RET();
}

ARM64_SIM_LICENSE();
