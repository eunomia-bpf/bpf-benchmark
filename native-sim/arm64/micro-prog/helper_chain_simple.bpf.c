#define ARM64_SIM_ENABLE_STACK 1
#define ARM64_SIM_RETURN_CASES \
	case 0x2cULL: __a64_lr = 0; goto arm64_l_2c; \
	case 0x4cULL: __a64_lr = 0; goto arm64_l_4c; \
	case 0x58ULL: __a64_lr = 0; goto arm64_l_58; \
	case 0x78ULL: __a64_lr = 0; goto arm64_l_78;
#include "../arm64_sim_local_bpf.h"

/*
 * Stage 2 test: chain of 4 distinct deterministic helper calls.
 *
 * Exercises uid_gid + map_update + map_lookup + map_delete on a
 * single-slot HASH map. The stored value is `bpf_get_current_uid_gid()`
 * which is identical between the native_lab and kernel TEST_RUN
 * processes (both run as root), and lookup returns exactly what
 * update wrote, so result is bit-identical across runtimes -- a real
 * correctness invariant rather than a non-deterministic loose check.
 *
 * Replaces an earlier ktime/prandom-XOR chain that varied by design.
 *
 * Maps: 1 (HASH).   Helpers: 4.   Inline-eligible: yes (HASH map).
 */
#include "../../test/include/native_helpers.h"

struct {
    __uint(type, BPF_MAP_TYPE_HASH);
    __uint(max_entries, 1);
    __type(key, __u32);
    __type(value, __u64);
} chain_h SEC(".maps");

SEC("xdp")
int helper_chain_simple_arm64_sim_xdp(struct xdp_md *ctx)
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
	/* 0xc: b.ls 18 <helper_chain_simple+0x18> */
	ARM64_SIM_A64_JCC(ARM64_COND_LS, 0xc, 0x18, arm64_l_18);
arm64_l_10:
	/* 0x10: mov w0, wzr */
	ARM64_SIM_RUN_OP3(ARM64_OP_MOV_REG, ARM64_X0, ARM64_XZR, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_32, 0, 0);
arm64_l_14:
	/* 0x14: b 90 <helper_chain_simple+0x90> */
	ARM64_SIM_A64_JMP(0x14, 0x90, arm64_l_90);
arm64_l_18:
	/* 0x18: sub sp, sp, #0x30 */
	ARM64_SIM_RUN_OP3(ARM64_OP_ALU_IMM, ARM64_SP, ARM64_SP, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_ALU(ARM64_ALU_SUB, ARM64_MOD_NONE, 0), 48ULL);
arm64_l_1c:
	/* 0x1c: stp x30, x19, [sp, #32] */
	ARM64_SIM_RUN_OP3(ARM64_OP_STP, ARM64_SP, ARM64_X30, ARM64_X19, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_MEM(ARM64_REG_NONE, ARM64_MOD_NONE, 0, 0), 32ULL);
arm64_l_20:
	/* 0x20: str x8, [sp, #8] */
	ARM64_SIM_RUN_OP3(ARM64_OP_STORE, ARM64_SP, ARM64_X8, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_MEM(ARM64_REG_NONE, ARM64_MOD_NONE, 0, 0), 8ULL);
arm64_l_24:
	/* 0x24: str wzr, [sp, #28] */
	ARM64_SIM_RUN_OP3(ARM64_OP_STORE, ARM64_SP, ARM64_XZR, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_32, ARM64_AUX_MEM(ARM64_REG_NONE, ARM64_MOD_NONE, 0, 0), 28ULL);
arm64_l_28:
	/* 0x28: bl 0 <bpf_get_current_uid_gid> */
	ARM64_SIM_BPF_CALL_bpf_get_current_uid_gid();
arm64_l_2c:
	/* 0x2c: str x0, [sp, #16] */
	ARM64_SIM_RUN_OP3(ARM64_OP_STORE, ARM64_SP, ARM64_X0, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_MEM(ARM64_REG_NONE, ARM64_MOD_NONE, 0, 0), 16ULL);
arm64_l_30:
	/* 0x30: adrp x19, 0 <chain_h> */
	(void)0;
arm64_l_34:
	/* 0x34: add x1, sp, #0x1c */
	ARM64_SIM_RUN_OP3(ARM64_OP_ALU_IMM, ARM64_X1, ARM64_SP, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_ALU(ARM64_ALU_ADD, ARM64_MOD_NONE, 0), 28ULL);
arm64_l_38:
	/* 0x38: ldr x19, [x19] */
	ARM64_SIM_L_WRITE_REG_MAP_PTR(ARM64_X19, &chain_h);
arm64_l_3c:
	/* 0x3c: add x2, sp, #0x10 */
	ARM64_SIM_RUN_OP3(ARM64_OP_ALU_IMM, ARM64_X2, ARM64_SP, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_ALU(ARM64_ALU_ADD, ARM64_MOD_NONE, 0), 16ULL);
arm64_l_40:
	/* 0x40: mov x3, xzr */
	ARM64_SIM_RUN_OP3(ARM64_OP_MOV_REG, ARM64_X3, ARM64_XZR, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, 0, 0);
arm64_l_44:
	/* 0x44: mov x0, x19 */
	ARM64_SIM_RUN_OP3(ARM64_OP_MOV_REG, ARM64_X0, ARM64_X19, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, 0, 0);
arm64_l_48:
	/* 0x48: bl 0 <bpf_map_update_elem> */
	ARM64_SIM_BPF_CALL_bpf_map_update_elem();
arm64_l_4c:
	/* 0x4c: add x1, sp, #0x1c */
	ARM64_SIM_RUN_OP3(ARM64_OP_ALU_IMM, ARM64_X1, ARM64_SP, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_ALU(ARM64_ALU_ADD, ARM64_MOD_NONE, 0), 28ULL);
arm64_l_50:
	/* 0x50: mov x0, x19 */
	ARM64_SIM_RUN_OP3(ARM64_OP_MOV_REG, ARM64_X0, ARM64_X19, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, 0, 0);
arm64_l_54:
	/* 0x54: bl 0 <bpf_map_lookup_elem> */
	ARM64_SIM_BPF_CALL_bpf_map_lookup_elem();
arm64_l_58:
	/* 0x58: cbz x0, 64 <helper_chain_simple+0x64> */
	ARM64_SIM_A64_CBZ(ARM64_X0, 0x58, 0x64, arm64_l_64);
arm64_l_5c:
	/* 0x5c: ldr x19, [x0] */
	ARM64_SIM_RUN_OP3(ARM64_OP_LOAD, ARM64_X19, ARM64_X0, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_MEM(ARM64_REG_NONE, ARM64_MOD_NONE, 0, 0), 0ULL);
arm64_l_60:
	/* 0x60: b 68 <helper_chain_simple+0x68> */
	ARM64_SIM_A64_JMP(0x60, 0x68, arm64_l_68);
arm64_l_64:
	/* 0x64: mov x19, xzr */
	ARM64_SIM_RUN_OP3(ARM64_OP_MOV_REG, ARM64_X19, ARM64_XZR, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, 0, 0);
arm64_l_68:
	/* 0x68: adrp x0, 0 <chain_h> */
	(void)0;
arm64_l_6c:
	/* 0x6c: add x1, sp, #0x1c */
	ARM64_SIM_RUN_OP3(ARM64_OP_ALU_IMM, ARM64_X1, ARM64_SP, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_ALU(ARM64_ALU_ADD, ARM64_MOD_NONE, 0), 28ULL);
arm64_l_70:
	/* 0x70: ldr x0, [x0] */
	ARM64_SIM_L_WRITE_REG_MAP_PTR(ARM64_X0, &chain_h);
arm64_l_74:
	/* 0x74: bl 0 <bpf_map_delete_elem> */
	ARM64_SIM_BPF_CALL_bpf_map_delete_elem();
arm64_l_78:
	/* 0x78: ldr x8, [sp, #8] */
	ARM64_SIM_RUN_OP3(ARM64_OP_LOAD, ARM64_X8, ARM64_SP, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_MEM(ARM64_REG_NONE, ARM64_MOD_NONE, 0, 0), 8ULL);
arm64_l_7c:
	/* 0x7c: mov w0, #0x2 */
	ARM64_SIM_RUN_OP3(ARM64_OP_MOV_IMM, ARM64_X0, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_32, 0, 2ULL);
arm64_l_80:
	/* 0x80: str x19, [x8] */
	ARM64_SIM_RUN_OP3(ARM64_OP_STORE, ARM64_X8, ARM64_X19, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_MEM(ARM64_REG_NONE, ARM64_MOD_NONE, 0, 0), 0ULL);
arm64_l_84:
	/* 0x84: ldp x30, x19, [sp, #32] */
	ARM64_SIM_RUN_OP3(ARM64_OP_LDP, ARM64_X30, ARM64_X19, ARM64_SP, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_MEM(ARM64_REG_NONE, ARM64_MOD_NONE, 0, 0), 32ULL);
arm64_l_88:
	/* 0x88: add sp, sp, #0x30 */
	ARM64_SIM_RUN_OP3(ARM64_OP_ALU_IMM, ARM64_SP, ARM64_SP, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_ALU(ARM64_ALU_ADD, ARM64_MOD_NONE, 0), 48ULL);
arm64_l_8c:
	/* 0x8c: b 90 <helper_chain_simple+0x90> */
	ARM64_SIM_A64_JMP(0x8c, 0x90, arm64_l_90);
arm64_l_90:
	/* 0x90: mov x7, x0 */
	ARM64_SIM_RUN_OP3(ARM64_OP_MOV_REG, ARM64_X7, ARM64_X0, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, 0, 0);
	ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X0, ARM64_SIM_L_READ_REG(ARM64_X7), ARM64_WIDTH_64);
	ARM64_SIM_RET();
}

ARM64_SIM_LICENSE();
