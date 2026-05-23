#define ARM64_SIM_ENABLE_STACK 1
#define ARM64_SIM_RETURN_CASES \
	case 0x34ULL: __a64_lr = 0; goto arm64_l_34; \
	case 0x40ULL: __a64_lr = 0; goto arm64_l_40; \
	case 0x4cULL: __a64_lr = 0; goto arm64_l_4c; \
	case 0x6cULL: __a64_lr = 0; goto arm64_l_6c; \
	case 0x90ULL: __a64_lr = 0; goto arm64_l_90; \
	case 0x9cULL: __a64_lr = 0; goto arm64_l_9c; \
	case 0xacULL: __a64_lr = 0; goto arm64_l_ac;
#include "../arm64_sim_local_bpf.h"

/*
 * Stage 2 test: most-complex case -- 3 helpers + 2 maps of different
 * inline classes (HASH + PERCPU_HASH).
 *
 * Real-world shape: a tetragon/tracee-style stats aggregator that
 * tags each observation with (pid_tgid mod K) into a HASH bucket
 * for cross-cpu aggregation and bumps a PERCPU_HASH per-cpu rate
 * counter at the same time.
 *
 * Multi-map (HASH + PERCPU_HASH) so native-link inline is disabled;
 * both lookups go through plain `bpf_map_lookup_elem`. Stored tag is
 * `bpf_get_current_uid_gid()` (deterministic across runtimes, both
 * run as root) rather than `bpf_ktime_get_ns()` (advances between
 * the two TEST_RUN calls), so the XOR of the two re-reads is a
 * stable, bit-identical value `uid_gid ^ 1` across native_lab and
 * kernel runs even though pid_tgid and smp_id route them to
 * different bucket slots.
 *
 * Maps: 2 (HASH + PERCPU_HASH).   Helpers: 3.
 * Inline-eligible: no (multi-map).
 */
#include "../../test/include/native_helpers.h"

struct {
    __uint(type, BPF_MAP_TYPE_HASH);
    __uint(max_entries, 64);
    __type(key, __u32);
    __type(value, __u64);
} stats_h SEC(".maps");

struct {
    __uint(type, BPF_MAP_TYPE_PERCPU_HASH);
    __uint(max_entries, 64);
    __type(key, __u32);
    __type(value, __u64);
} rate_pcpu SEC(".maps");

SEC("xdp")
int stats_mixed_helpers_arm64_sim_xdp(struct xdp_md *ctx)
{
	ARM64_SIM_ENTRY_XDP(ctx);
arm64_l_0:
	/* 0x0: sub sp, sp, #0x40 */
	ARM64_SIM_RUN_OP3(ARM64_OP_ALU_IMM, ARM64_SP, ARM64_SP, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_ALU(ARM64_ALU_SUB, ARM64_MOD_NONE, 0), 64ULL);
arm64_l_4:
	/* 0x4: nop */
	ARM64_SIM_RUN_OP3(ARM64_OP_NOP, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, 0, 0);
arm64_l_8:
	/* 0x8: nop */
	ARM64_SIM_RUN_OP3(ARM64_OP_NOP, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, 0, 0);
arm64_l_c:
	/* 0xc: ldp x21, x8, [x0] */
	ARM64_SIM_RUN_OP3(ARM64_OP_LDP, ARM64_X21, ARM64_X8, ARM64_X0, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_MEM(ARM64_REG_NONE, ARM64_MOD_NONE, 0, 0), 0ULL);
arm64_l_10:
	/* 0x10: add x9, x21, #0x8 */
	ARM64_SIM_RUN_OP3(ARM64_OP_ALU_IMM, ARM64_X9, ARM64_X21, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_ALU(ARM64_ALU_ADD, ARM64_MOD_NONE, 0), 8ULL);
arm64_l_14:
	/* 0x14: cmp x9, x8 */
	ARM64_SIM_RUN_OP3(ARM64_OP_CMP_REG, ARM64_X9, ARM64_X8, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_ALU(0, ARM64_MOD_NONE, 0), 0);
arm64_l_18:
	/* 0x18: b.ls 30 <stats_mixed_helpers+0x30> */
	ARM64_SIM_A64_JCC(ARM64_COND_LS, 0x18, 0x30, arm64_l_30);
arm64_l_1c:
	/* 0x1c: mov w0, wzr */
	ARM64_SIM_RUN_OP3(ARM64_OP_MOV_REG, ARM64_X0, ARM64_XZR, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_32, 0, 0);
arm64_l_20:
	/* 0x20: nop */
	ARM64_SIM_RUN_OP3(ARM64_OP_NOP, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, 0, 0);
arm64_l_24:
	/* 0x24: nop */
	ARM64_SIM_RUN_OP3(ARM64_OP_NOP, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, 0, 0);
arm64_l_28:
	/* 0x28: add sp, sp, #0x40 */
	ARM64_SIM_RUN_OP3(ARM64_OP_ALU_IMM, ARM64_SP, ARM64_SP, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_ALU(ARM64_ALU_ADD, ARM64_MOD_NONE, 0), 64ULL);
arm64_l_2c:
	/* 0x2c: b e8 <__native_link_arm64_ret_trampoline> */
	ARM64_SIM_A64_JMP(0x2c, 0xe8, arm64_l_e8);
arm64_l_30:
	/* 0x30: bl 0 <bpf_get_current_pid_tgid> */
	ARM64_SIM_BPF_CALL_bpf_get_current_pid_tgid();
arm64_l_34:
	/* 0x34: and w8, w0, #0x3f */
	ARM64_SIM_RUN_OP3(ARM64_OP_ALU_IMM, ARM64_X8, ARM64_X0, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_32, ARM64_AUX_ALU(ARM64_ALU_AND, ARM64_MOD_NONE, 0), 63ULL);
arm64_l_38:
	/* 0x38: str w8, [sp, #28] */
	ARM64_SIM_RUN_OP3(ARM64_OP_STORE, ARM64_SP, ARM64_X8, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_32, ARM64_AUX_MEM(ARM64_REG_NONE, ARM64_MOD_NONE, 0, 0), 28ULL);
arm64_l_3c:
	/* 0x3c: bl 0 <bpf_get_smp_processor_id> */
	ARM64_SIM_BPF_CALL_bpf_get_smp_processor_id();
arm64_l_40:
	/* 0x40: and w8, w0, #0x3f */
	ARM64_SIM_RUN_OP3(ARM64_OP_ALU_IMM, ARM64_X8, ARM64_X0, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_32, ARM64_AUX_ALU(ARM64_ALU_AND, ARM64_MOD_NONE, 0), 63ULL);
arm64_l_44:
	/* 0x44: str w8, [sp, #24] */
	ARM64_SIM_RUN_OP3(ARM64_OP_STORE, ARM64_SP, ARM64_X8, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_32, ARM64_AUX_MEM(ARM64_REG_NONE, ARM64_MOD_NONE, 0, 0), 24ULL);
arm64_l_48:
	/* 0x48: bl 0 <bpf_get_current_uid_gid> */
	ARM64_SIM_BPF_CALL_bpf_get_current_uid_gid();
arm64_l_4c:
	/* 0x4c: str x0, [sp, #16] */
	ARM64_SIM_RUN_OP3(ARM64_OP_STORE, ARM64_SP, ARM64_X0, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_MEM(ARM64_REG_NONE, ARM64_MOD_NONE, 0, 0), 16ULL);
arm64_l_50:
	/* 0x50: adrp x19, 0 <stats_h> */
	ARM64_SIM_RUN_OP3(ARM64_OP_ADRP_GOT, ARM64_X19, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, 0, ((__u64)(long)&stats_h));
arm64_l_54:
	/* 0x54: add x1, sp, #0x1c */
	ARM64_SIM_RUN_OP3(ARM64_OP_ALU_IMM, ARM64_X1, ARM64_SP, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_ALU(ARM64_ALU_ADD, ARM64_MOD_NONE, 0), 28ULL);
arm64_l_58:
	/* 0x58: add x2, sp, #0x10 */
	ARM64_SIM_RUN_OP3(ARM64_OP_ALU_IMM, ARM64_X2, ARM64_SP, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_ALU(ARM64_ALU_ADD, ARM64_MOD_NONE, 0), 16ULL);
arm64_l_5c:
	/* 0x5c: ldr x19, [x19] */
	ARM64_SIM_RUN_OP3(ARM64_OP_LOAD, ARM64_X19, ARM64_X19, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_MEM(ARM64_REG_NONE, ARM64_MOD_NONE, 0, 0), 0ULL);
arm64_l_60:
	/* 0x60: mov x3, xzr */
	ARM64_SIM_RUN_OP3(ARM64_OP_MOV_REG, ARM64_X3, ARM64_XZR, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, 0, 0);
arm64_l_64:
	/* 0x64: mov x0, x19 */
	ARM64_SIM_RUN_OP3(ARM64_OP_MOV_REG, ARM64_X0, ARM64_X19, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, 0, 0);
arm64_l_68:
	/* 0x68: bl 0 <bpf_map_update_elem> */
	ARM64_SIM_BPF_CALL_bpf_map_update_elem();
arm64_l_6c:
	/* 0x6c: mov w8, #0x1 */
	ARM64_SIM_RUN_OP3(ARM64_OP_MOV_IMM, ARM64_X8, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_32, 0, 1ULL);
arm64_l_70:
	/* 0x70: adrp x20, 0 <rate_pcpu> */
	ARM64_SIM_RUN_OP3(ARM64_OP_ADRP_GOT, ARM64_X20, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, 0, ((__u64)(long)&rate_pcpu));
arm64_l_74:
	/* 0x74: add x1, sp, #0x18 */
	ARM64_SIM_RUN_OP3(ARM64_OP_ALU_IMM, ARM64_X1, ARM64_SP, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_ALU(ARM64_ALU_ADD, ARM64_MOD_NONE, 0), 24ULL);
arm64_l_78:
	/* 0x78: str x8, [sp, #8] */
	ARM64_SIM_RUN_OP3(ARM64_OP_STORE, ARM64_SP, ARM64_X8, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_MEM(ARM64_REG_NONE, ARM64_MOD_NONE, 0, 0), 8ULL);
arm64_l_7c:
	/* 0x7c: add x2, sp, #0x8 */
	ARM64_SIM_RUN_OP3(ARM64_OP_ALU_IMM, ARM64_X2, ARM64_SP, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_ALU(ARM64_ALU_ADD, ARM64_MOD_NONE, 0), 8ULL);
arm64_l_80:
	/* 0x80: mov x3, xzr */
	ARM64_SIM_RUN_OP3(ARM64_OP_MOV_REG, ARM64_X3, ARM64_XZR, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, 0, 0);
arm64_l_84:
	/* 0x84: ldr x20, [x20] */
	ARM64_SIM_RUN_OP3(ARM64_OP_LOAD, ARM64_X20, ARM64_X20, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_MEM(ARM64_REG_NONE, ARM64_MOD_NONE, 0, 0), 0ULL);
arm64_l_88:
	/* 0x88: mov x0, x20 */
	ARM64_SIM_RUN_OP3(ARM64_OP_MOV_REG, ARM64_X0, ARM64_X20, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, 0, 0);
arm64_l_8c:
	/* 0x8c: bl 0 <bpf_map_update_elem> */
	ARM64_SIM_BPF_CALL_bpf_map_update_elem();
arm64_l_90:
	/* 0x90: add x1, sp, #0x1c */
	ARM64_SIM_RUN_OP3(ARM64_OP_ALU_IMM, ARM64_X1, ARM64_SP, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_ALU(ARM64_ALU_ADD, ARM64_MOD_NONE, 0), 28ULL);
arm64_l_94:
	/* 0x94: mov x0, x19 */
	ARM64_SIM_RUN_OP3(ARM64_OP_MOV_REG, ARM64_X0, ARM64_X19, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, 0, 0);
arm64_l_98:
	/* 0x98: bl 0 <bpf_map_lookup_elem> */
	ARM64_SIM_BPF_CALL_bpf_map_lookup_elem();
arm64_l_9c:
	/* 0x9c: mov x19, x0 */
	ARM64_SIM_RUN_OP3(ARM64_OP_MOV_REG, ARM64_X19, ARM64_X0, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, 0, 0);
arm64_l_a0:
	/* 0xa0: add x1, sp, #0x18 */
	ARM64_SIM_RUN_OP3(ARM64_OP_ALU_IMM, ARM64_X1, ARM64_SP, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_ALU(ARM64_ALU_ADD, ARM64_MOD_NONE, 0), 24ULL);
arm64_l_a4:
	/* 0xa4: mov x0, x20 */
	ARM64_SIM_RUN_OP3(ARM64_OP_MOV_REG, ARM64_X0, ARM64_X20, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, 0, 0);
arm64_l_a8:
	/* 0xa8: bl 0 <bpf_map_lookup_elem> */
	ARM64_SIM_BPF_CALL_bpf_map_lookup_elem();
arm64_l_ac:
	/* 0xac: cbz x19, c0 <stats_mixed_helpers+0xc0> */
	ARM64_SIM_A64_CBZ(ARM64_X19, 0xac, 0xc0, arm64_l_c0);
arm64_l_b0:
	/* 0xb0: ldr x8, [x19] */
	ARM64_SIM_RUN_OP3(ARM64_OP_LOAD, ARM64_X8, ARM64_X19, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_MEM(ARM64_REG_NONE, ARM64_MOD_NONE, 0, 0), 0ULL);
arm64_l_b4:
	/* 0xb4: cbz x0, c8 <stats_mixed_helpers+0xc8> */
	ARM64_SIM_A64_CBZ(ARM64_X0, 0xb4, 0xc8, arm64_l_c8);
arm64_l_b8:
	/* 0xb8: ldr x9, [x0] */
	ARM64_SIM_RUN_OP3(ARM64_OP_LOAD, ARM64_X9, ARM64_X0, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_MEM(ARM64_REG_NONE, ARM64_MOD_NONE, 0, 0), 0ULL);
arm64_l_bc:
	/* 0xbc: b cc <stats_mixed_helpers+0xcc> */
	ARM64_SIM_A64_JMP(0xbc, 0xcc, arm64_l_cc);
arm64_l_c0:
	/* 0xc0: mov x8, xzr */
	ARM64_SIM_RUN_OP3(ARM64_OP_MOV_REG, ARM64_X8, ARM64_XZR, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, 0, 0);
arm64_l_c4:
	/* 0xc4: cbnz x0, b8 <stats_mixed_helpers+0xb8> */
	ARM64_SIM_A64_CBNZ(ARM64_X0, 0xc4, 0xb8, arm64_l_b8);
arm64_l_c8:
	/* 0xc8: mov x9, xzr */
	ARM64_SIM_RUN_OP3(ARM64_OP_MOV_REG, ARM64_X9, ARM64_XZR, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, 0, 0);
arm64_l_cc:
	/* 0xcc: eor x8, x9, x8 */
	ARM64_SIM_RUN_OP3(ARM64_OP_ALU_REG, ARM64_X8, ARM64_X9, ARM64_X8, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_ALU(ARM64_ALU_EOR, ARM64_MOD_NONE, 0), 0);
arm64_l_d0:
	/* 0xd0: mov w0, #0x2 */
	ARM64_SIM_RUN_OP3(ARM64_OP_MOV_IMM, ARM64_X0, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_32, 0, 2ULL);
arm64_l_d4:
	/* 0xd4: str x8, [x21] */
	ARM64_SIM_RUN_OP3(ARM64_OP_STORE, ARM64_X21, ARM64_X8, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_MEM(ARM64_REG_NONE, ARM64_MOD_NONE, 0, 0), 0ULL);
arm64_l_d8:
	/* 0xd8: nop */
	ARM64_SIM_RUN_OP3(ARM64_OP_NOP, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, 0, 0);
arm64_l_dc:
	/* 0xdc: nop */
	ARM64_SIM_RUN_OP3(ARM64_OP_NOP, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, 0, 0);
arm64_l_e0:
	/* 0xe0: add sp, sp, #0x40 */
	ARM64_SIM_RUN_OP3(ARM64_OP_ALU_IMM, ARM64_SP, ARM64_SP, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_ALU(ARM64_ALU_ADD, ARM64_MOD_NONE, 0), 64ULL);
arm64_l_e4:
	/* 0xe4: b e8 <__native_link_arm64_ret_trampoline> */
	ARM64_SIM_A64_JMP(0xe4, 0xe8, arm64_l_e8);
arm64_l_e8:
	/* 0xe8: mov x7, x0 */
	ARM64_SIM_RUN_OP3(ARM64_OP_MOV_REG, ARM64_X7, ARM64_X0, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, 0, 0);
	ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X0, ARM64_SIM_L_READ_REG(ARM64_X7), ARM64_WIDTH_64);
	ARM64_SIM_RET();
}

ARM64_SIM_LICENSE();
