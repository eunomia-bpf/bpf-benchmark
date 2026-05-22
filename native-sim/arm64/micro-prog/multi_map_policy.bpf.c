#define ARM64_SIM_ENABLE_STACK 1
#define ARM64_SIM_RETURN_CASES \
	case 0x5cULL: __a64_lr = 0; goto arm64_l_5c; \
	case 0x88ULL: __a64_lr = 0; goto arm64_l_88; \
	case 0xa8ULL: __a64_lr = 0; goto arm64_l_a8; \
	case 0xb4ULL: __a64_lr = 0; goto arm64_l_b4; \
	case 0xc8ULL: __a64_lr = 0; goto arm64_l_c8; \
	case 0xe4ULL: __a64_lr = 0; goto arm64_l_e4;
#include "../arm64_sim_local_bpf.h"

/*
 * Stage 2 test: 3-map chain (ARRAY -> HASH -> PERCPU_ARRAY).
 *
 * Real-world shape: cilium-style policy chain --
 *   index by something packet-derived into a POLICY ARRAY,
 *   take that policy id and look up metadata in a HASH table,
 *   then bump a per-cpu counter so userspace can read rates.
 *
 * Crucially, this is a multi-map program: native-link MUST NOT inline
 * `bpf_map_lookup_elem` here, because two of the three lookups go to
 * non-HASH maps and would be misrouted to `__htab_map_lookup_elem`.
 * The runner enforces that (single-HASH-only inline) so this test
 * verifies the correctness guard works.
 *
 * Maps: 3 (ARRAY + HASH + PERCPU_ARRAY).
 * Helpers: 0 (besides map ops).
 * Inline-eligible: no (multi-map; runner refuses to set
 *                  --inline-hash-lookup when other map types coexist).
 */
#include "../../test/include/native_helpers.h"

struct {
    __uint(type, BPF_MAP_TYPE_ARRAY);
    __uint(max_entries, 16);
    __type(key, __u32);
    __type(value, __u64);
} policy_array SEC(".maps");

struct {
    __uint(type, BPF_MAP_TYPE_HASH);
    __uint(max_entries, 64);
    __type(key, __u64);
    __type(value, __u64);
} meta_hash SEC(".maps");

struct {
    __uint(type, BPF_MAP_TYPE_PERCPU_ARRAY);
    __uint(max_entries, 8);
    __type(key, __u32);
    __type(value, __u64);
} counter_pcpu SEC(".maps");

SEC("xdp")
int multi_map_policy_arm64_sim_xdp(struct xdp_md *ctx)
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
	/* 0xc: b.ls 18 <multi_map_policy+0x18> */
	ARM64_SIM_A64_JCC(ARM64_COND_LS, 0xc, 0x18, arm64_l_18);
arm64_l_10:
	/* 0x10: mov w0, wzr */
	ARM64_SIM_RUN_OP3(ARM64_OP_MOV_REG, ARM64_X0, ARM64_XZR, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_32, 0, 0);
arm64_l_14:
	/* 0x14: b 128 <__native_link_arm64_ret_trampoline> */
	ARM64_SIM_A64_JMP(0x14, 0x128, arm64_l_128);
arm64_l_18:
	/* 0x18: sub sp, sp, #0x50 */
	ARM64_SIM_RUN_OP3(ARM64_OP_ALU_IMM, ARM64_SP, ARM64_SP, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_ALU(ARM64_ALU_SUB, ARM64_MOD_NONE, 0), 80ULL);
arm64_l_1c:
	/* 0x1c: nop */
	ARM64_SIM_RUN_OP3(ARM64_OP_NOP, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, 0, 0);
arm64_l_20:
	/* 0x20: mov x9, #0x11 */
	ARM64_SIM_RUN_OP3(ARM64_OP_MOV_IMM, ARM64_X9, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, 0, 17ULL);
arm64_l_24:
	/* 0x24: str x8, [sp, #8] */
	ARM64_SIM_RUN_OP3(ARM64_OP_STORE, ARM64_SP, ARM64_X8, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_MEM(ARM64_REG_NONE, ARM64_MOD_NONE, 0, 0), 8ULL);
arm64_l_28:
	/* 0x28: mov w8, #0x3 */
	ARM64_SIM_RUN_OP3(ARM64_OP_MOV_IMM, ARM64_X8, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_32, 0, 3ULL);
arm64_l_2c:
	/* 0x2c: movk x9, #0xeeff, lsl #16 */
	ARM64_SIM_RUN_OP3(ARM64_OP_MOVK, ARM64_X9, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_MOVK(16), 61183ULL);
arm64_l_30:
	/* 0x30: str w8, [sp, #60] */
	ARM64_SIM_RUN_OP3(ARM64_OP_STORE, ARM64_SP, ARM64_X8, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_32, ARM64_AUX_MEM(ARM64_REG_NONE, ARM64_MOD_NONE, 0, 0), 60ULL);
arm64_l_34:
	/* 0x34: adrp x19, 0 <policy_array> */
	(void)0;
arm64_l_38:
	/* 0x38: movk x9, #0xccdd, lsl #32 */
	ARM64_SIM_RUN_OP3(ARM64_OP_MOVK, ARM64_X9, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_MOVK(32), 52445ULL);
arm64_l_3c:
	/* 0x3c: add x1, sp, #0x3c */
	ARM64_SIM_RUN_OP3(ARM64_OP_ALU_IMM, ARM64_X1, ARM64_SP, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_ALU(ARM64_ALU_ADD, ARM64_MOD_NONE, 0), 60ULL);
arm64_l_40:
	/* 0x40: add x2, sp, #0x30 */
	ARM64_SIM_RUN_OP3(ARM64_OP_ALU_IMM, ARM64_X2, ARM64_SP, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_ALU(ARM64_ALU_ADD, ARM64_MOD_NONE, 0), 48ULL);
arm64_l_44:
	/* 0x44: movk x9, #0xaabb, lsl #48 */
	ARM64_SIM_RUN_OP3(ARM64_OP_MOVK, ARM64_X9, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_MOVK(48), 43707ULL);
arm64_l_48:
	/* 0x48: mov x3, xzr */
	ARM64_SIM_RUN_OP3(ARM64_OP_MOV_REG, ARM64_X3, ARM64_XZR, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, 0, 0);
arm64_l_4c:
	/* 0x4c: str x9, [sp, #48] */
	ARM64_SIM_RUN_OP3(ARM64_OP_STORE, ARM64_SP, ARM64_X9, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_MEM(ARM64_REG_NONE, ARM64_MOD_NONE, 0, 0), 48ULL);
arm64_l_50:
	/* 0x50: ldr x19, [x19] */
	ARM64_SIM_L_WRITE_REG_MAP_PTR(ARM64_X19, &policy_array);
arm64_l_54:
	/* 0x54: mov x0, x19 */
	ARM64_SIM_RUN_OP3(ARM64_OP_MOV_REG, ARM64_X0, ARM64_X19, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, 0, 0);
arm64_l_58:
	/* 0x58: bl 0 <bpf_map_update_elem> */
	ARM64_SIM_BPF_CALL_bpf_map_update_elem();
arm64_l_5c:
	/* 0x5c: mov x8, #0x5678 */
	ARM64_SIM_RUN_OP3(ARM64_OP_MOV_IMM, ARM64_X8, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, 0, 22136ULL);
arm64_l_60:
	/* 0x60: adrp x0, 0 <meta_hash> */
	(void)0;
arm64_l_64:
	/* 0x64: add x1, sp, #0x30 */
	ARM64_SIM_RUN_OP3(ARM64_OP_ALU_IMM, ARM64_X1, ARM64_SP, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_ALU(ARM64_ALU_ADD, ARM64_MOD_NONE, 0), 48ULL);
arm64_l_68:
	/* 0x68: movk x8, #0x1234, lsl #16 */
	ARM64_SIM_RUN_OP3(ARM64_OP_MOVK, ARM64_X8, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_MOVK(16), 4660ULL);
arm64_l_6c:
	/* 0x6c: add x2, sp, #0x28 */
	ARM64_SIM_RUN_OP3(ARM64_OP_ALU_IMM, ARM64_X2, ARM64_SP, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_ALU(ARM64_ALU_ADD, ARM64_MOD_NONE, 0), 40ULL);
arm64_l_70:
	/* 0x70: mov x3, xzr */
	ARM64_SIM_RUN_OP3(ARM64_OP_MOV_REG, ARM64_X3, ARM64_XZR, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, 0, 0);
arm64_l_74:
	/* 0x74: movk x8, #0x5678, lsl #32 */
	ARM64_SIM_RUN_OP3(ARM64_OP_MOVK, ARM64_X8, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_MOVK(32), 22136ULL);
arm64_l_78:
	/* 0x78: movk x8, #0x1234, lsl #48 */
	ARM64_SIM_RUN_OP3(ARM64_OP_MOVK, ARM64_X8, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_MOVK(48), 4660ULL);
arm64_l_7c:
	/* 0x7c: str x8, [sp, #40] */
	ARM64_SIM_RUN_OP3(ARM64_OP_STORE, ARM64_SP, ARM64_X8, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_MEM(ARM64_REG_NONE, ARM64_MOD_NONE, 0, 0), 40ULL);
arm64_l_80:
	/* 0x80: ldr x0, [x0] */
	ARM64_SIM_L_WRITE_REG_MAP_PTR(ARM64_X0, &meta_hash);
arm64_l_84:
	/* 0x84: bl 0 <bpf_map_update_elem> */
	ARM64_SIM_BPF_CALL_bpf_map_update_elem();
arm64_l_88:
	/* 0x88: str wzr, [sp, #36] */
	ARM64_SIM_RUN_OP3(ARM64_OP_STORE, ARM64_SP, ARM64_XZR, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_32, ARM64_AUX_MEM(ARM64_REG_NONE, ARM64_MOD_NONE, 0, 0), 36ULL);
arm64_l_8c:
	/* 0x8c: adrp x0, 0 <counter_pcpu> */
	(void)0;
arm64_l_90:
	/* 0x90: add x1, sp, #0x24 */
	ARM64_SIM_RUN_OP3(ARM64_OP_ALU_IMM, ARM64_X1, ARM64_SP, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_ALU(ARM64_ALU_ADD, ARM64_MOD_NONE, 0), 36ULL);
arm64_l_94:
	/* 0x94: str xzr, [sp, #24] */
	ARM64_SIM_RUN_OP3(ARM64_OP_STORE, ARM64_SP, ARM64_XZR, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_MEM(ARM64_REG_NONE, ARM64_MOD_NONE, 0, 0), 24ULL);
arm64_l_98:
	/* 0x98: add x2, sp, #0x18 */
	ARM64_SIM_RUN_OP3(ARM64_OP_ALU_IMM, ARM64_X2, ARM64_SP, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_ALU(ARM64_ALU_ADD, ARM64_MOD_NONE, 0), 24ULL);
arm64_l_9c:
	/* 0x9c: mov x3, xzr */
	ARM64_SIM_RUN_OP3(ARM64_OP_MOV_REG, ARM64_X3, ARM64_XZR, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, 0, 0);
arm64_l_a0:
	/* 0xa0: ldr x0, [x0] */
	ARM64_SIM_L_WRITE_REG_MAP_PTR(ARM64_X0, &counter_pcpu);
arm64_l_a4:
	/* 0xa4: bl 0 <bpf_map_update_elem> */
	ARM64_SIM_BPF_CALL_bpf_map_update_elem();
arm64_l_a8:
	/* 0xa8: add x1, sp, #0x3c */
	ARM64_SIM_RUN_OP3(ARM64_OP_ALU_IMM, ARM64_X1, ARM64_SP, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_ALU(ARM64_ALU_ADD, ARM64_MOD_NONE, 0), 60ULL);
arm64_l_ac:
	/* 0xac: mov x0, x19 */
	ARM64_SIM_RUN_OP3(ARM64_OP_MOV_REG, ARM64_X0, ARM64_X19, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, 0, 0);
arm64_l_b0:
	/* 0xb0: bl 0 <bpf_map_lookup_elem> */
	ARM64_SIM_BPF_CALL_bpf_map_lookup_elem();
arm64_l_b4:
	/* 0xb4: cbz x0, d0 <multi_map_policy+0xd0> */
	ARM64_SIM_A64_CBZ(ARM64_X0, 0xb4, 0xd0, arm64_l_d0);
arm64_l_b8:
	/* 0xb8: mov x1, x0 */
	ARM64_SIM_RUN_OP3(ARM64_OP_MOV_REG, ARM64_X1, ARM64_X0, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, 0, 0);
arm64_l_bc:
	/* 0xbc: adrp x0, 0 <meta_hash> */
	(void)0;
arm64_l_c0:
	/* 0xc0: ldr x0, [x0] */
	ARM64_SIM_L_WRITE_REG_MAP_PTR(ARM64_X0, &meta_hash);
arm64_l_c4:
	/* 0xc4: bl 0 <bpf_map_lookup_elem> */
	ARM64_SIM_BPF_CALL_bpf_map_lookup_elem();
arm64_l_c8:
	/* 0xc8: str x0, [sp, #16] */
	ARM64_SIM_RUN_OP3(ARM64_OP_STORE, ARM64_SP, ARM64_X0, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_MEM(ARM64_REG_NONE, ARM64_MOD_NONE, 0, 0), 16ULL);
arm64_l_cc:
	/* 0xcc: b d4 <multi_map_policy+0xd4> */
	ARM64_SIM_A64_JMP(0xcc, 0xd4, arm64_l_d4);
arm64_l_d0:
	/* 0xd0: str xzr, [sp, #16] */
	ARM64_SIM_RUN_OP3(ARM64_OP_STORE, ARM64_SP, ARM64_XZR, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_MEM(ARM64_REG_NONE, ARM64_MOD_NONE, 0, 0), 16ULL);
arm64_l_d4:
	/* 0xd4: adrp x0, 0 <counter_pcpu> */
	(void)0;
arm64_l_d8:
	/* 0xd8: add x1, sp, #0x24 */
	ARM64_SIM_RUN_OP3(ARM64_OP_ALU_IMM, ARM64_X1, ARM64_SP, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_ALU(ARM64_ALU_ADD, ARM64_MOD_NONE, 0), 36ULL);
arm64_l_dc:
	/* 0xdc: ldr x0, [x0] */
	ARM64_SIM_L_WRITE_REG_MAP_PTR(ARM64_X0, &counter_pcpu);
arm64_l_e0:
	/* 0xe0: bl 0 <bpf_map_lookup_elem> */
	ARM64_SIM_BPF_CALL_bpf_map_lookup_elem();
arm64_l_e4:
	/* 0xe4: ldr x8, [sp, #16] */
	ARM64_SIM_RUN_OP3(ARM64_OP_LOAD, ARM64_X8, ARM64_SP, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_MEM(ARM64_REG_NONE, ARM64_MOD_NONE, 0, 0), 16ULL);
arm64_l_e8:
	/* 0xe8: cbz x0, 100 <multi_map_policy+0x100> */
	ARM64_SIM_A64_CBZ(ARM64_X0, 0xe8, 0x100, arm64_l_100);
arm64_l_ec:
	/* 0xec: cbz x8, 100 <multi_map_policy+0x100> */
	ARM64_SIM_A64_CBZ(ARM64_X8, 0xec, 0x100, arm64_l_100);
arm64_l_f0:
	/* 0xf0: ldr x9, [x8] */
	ARM64_SIM_RUN_OP3(ARM64_OP_LOAD, ARM64_X9, ARM64_X8, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_MEM(ARM64_REG_NONE, ARM64_MOD_NONE, 0, 0), 0ULL);
arm64_l_f4:
	/* 0xf4: ldr x8, [sp, #8] */
	ARM64_SIM_RUN_OP3(ARM64_OP_LOAD, ARM64_X8, ARM64_SP, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_MEM(ARM64_REG_NONE, ARM64_MOD_NONE, 0, 0), 8ULL);
arm64_l_f8:
	/* 0xf8: str x9, [x0] */
	ARM64_SIM_RUN_OP3(ARM64_OP_STORE, ARM64_X0, ARM64_X9, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_MEM(ARM64_REG_NONE, ARM64_MOD_NONE, 0, 0), 0ULL);
arm64_l_fc:
	/* 0xfc: b 114 <multi_map_policy+0x114> */
	ARM64_SIM_A64_JMP(0xfc, 0x114, arm64_l_114);
arm64_l_100:
	/* 0x100: ldr x8, [sp, #8] */
	ARM64_SIM_RUN_OP3(ARM64_OP_LOAD, ARM64_X8, ARM64_SP, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_MEM(ARM64_REG_NONE, ARM64_MOD_NONE, 0, 0), 8ULL);
arm64_l_104:
	/* 0x104: cbz x0, 110 <multi_map_policy+0x110> */
	ARM64_SIM_A64_CBZ(ARM64_X0, 0x104, 0x110, arm64_l_110);
arm64_l_108:
	/* 0x108: ldr x9, [x0] */
	ARM64_SIM_RUN_OP3(ARM64_OP_LOAD, ARM64_X9, ARM64_X0, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_MEM(ARM64_REG_NONE, ARM64_MOD_NONE, 0, 0), 0ULL);
arm64_l_10c:
	/* 0x10c: b 114 <multi_map_policy+0x114> */
	ARM64_SIM_A64_JMP(0x10c, 0x114, arm64_l_114);
arm64_l_110:
	/* 0x110: mov x9, xzr */
	ARM64_SIM_RUN_OP3(ARM64_OP_MOV_REG, ARM64_X9, ARM64_XZR, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, 0, 0);
arm64_l_114:
	/* 0x114: nop */
	ARM64_SIM_RUN_OP3(ARM64_OP_NOP, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, 0, 0);
arm64_l_118:
	/* 0x118: mov w0, #0x2 */
	ARM64_SIM_RUN_OP3(ARM64_OP_MOV_IMM, ARM64_X0, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_32, 0, 2ULL);
arm64_l_11c:
	/* 0x11c: str x9, [x8] */
	ARM64_SIM_RUN_OP3(ARM64_OP_STORE, ARM64_X8, ARM64_X9, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_MEM(ARM64_REG_NONE, ARM64_MOD_NONE, 0, 0), 0ULL);
arm64_l_120:
	/* 0x120: add sp, sp, #0x50 */
	ARM64_SIM_RUN_OP3(ARM64_OP_ALU_IMM, ARM64_SP, ARM64_SP, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_ALU(ARM64_ALU_ADD, ARM64_MOD_NONE, 0), 80ULL);
arm64_l_124:
	/* 0x124: b 128 <__native_link_arm64_ret_trampoline> */
	ARM64_SIM_A64_JMP(0x124, 0x128, arm64_l_128);
arm64_l_128:
	/* 0x128: mov x7, x0 */
	ARM64_SIM_RUN_OP3(ARM64_OP_MOV_REG, ARM64_X7, ARM64_X0, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, 0, 0);
	ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X0, ARM64_SIM_L_READ_REG(ARM64_X7), ARM64_WIDTH_64);
	ARM64_SIM_RET();
}

ARM64_SIM_LICENSE();
