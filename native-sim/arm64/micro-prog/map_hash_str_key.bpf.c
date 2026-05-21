#define ARM64_SIM_ENABLE_STACK 1
#define ARM64_SIM_RETURN_CASES \
	case 0x64ULL: __a64_lr = 0; goto arm64_l_64; \
	case 0x70ULL: __a64_lr = 0; goto arm64_l_70;
#include "../arm64_sim_local_bpf.h"

/*
 * Stage 2 test: HASH map with a 16-byte string key.
 *
 * Real-world shape: per-process / per-cgroup / per-command lookup
 * keyed by a fixed-length name buffer (tetragon / bpftrace pattern).
 * Larger key means the inline `add rax, KEY_OFFSET` after
 * `__htab_map_lookup_elem` carries a larger immediate than the u32-key
 * case -- still well within imm8 range here.
 *
 * Maps: 1 (HASH).   Helpers: 0.   Inline-eligible: yes.
 */
#include "../../test/include/native_helpers.h"

/* 16-byte key declared as 2 u64s so clang materializes the literal as
 * two `mov qword [rsp+N], imm64` stack stores instead of `memcpy` from
 * a `.rodata` symbol (the latter would emit an R_X86_64_PC32 reloc that
 * native-link doesn't yet handle for embedded rodata). The map key
 * type is the same 16 contiguous bytes either way. */
struct key16 { __u64 lo; __u64 hi; };

struct {
    __uint(type, BPF_MAP_TYPE_HASH);
    __uint(max_entries, 8);
    __type(key, struct key16);
    __type(value, __u64);
} str_hash SEC(".maps");

SEC("xdp")
int map_hash_str_key_arm64_sim_xdp(struct xdp_md *ctx)
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
	/* 0xc: b.ls 0x18 */
	ARM64_SIM_A64_JCC(ARM64_COND_LS, 0xc, 0x18, arm64_l_18);
arm64_l_10:
	/* 0x10: mov w0, wzr */
	ARM64_SIM_RUN_OP3(ARM64_OP_MOV_REG, ARM64_X0, ARM64_XZR, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_32, 0, 0);
arm64_l_14:
	/* 0x14: b 0x94 */
	ARM64_SIM_A64_JMP(0x14, 0x94, arm64_l_94);
arm64_l_18:
	/* 0x18: sub sp, sp, #0x30 */
	ARM64_SIM_RUN_OP3(ARM64_OP_ALU_IMM, ARM64_SP, ARM64_SP, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_ALU(ARM64_ALU_SUB, ARM64_MOD_NONE, 0), 48ULL);
arm64_l_1c:
	/* 0x1c: stp x30, x19, [sp, #32] */
	ARM64_SIM_RUN_OP3(ARM64_OP_STP, ARM64_SP, ARM64_X30, ARM64_X19, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_MEM(ARM64_REG_NONE, ARM64_MOD_NONE, 0, 0), 32ULL);
arm64_l_20:
	/* 0x20: str x8, [sp] */
	ARM64_SIM_RUN_OP3(ARM64_OP_STORE, ARM64_SP, ARM64_X8, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_MEM(ARM64_REG_NONE, ARM64_MOD_NONE, 0, 0), 0ULL);
arm64_l_24:
	/* 0x24: adrp x8, 0x0 */
	(void)0;
arm64_l_28:
	/* 0x28: add x8, x8, #0x0 */
	(void)0;
arm64_l_2c:
	/* 0x2c: ldr q0, [x8] */
	ARM64_SIM_L_LOAD_CONST16_Q0(7164775529535926370ULL, 3472325312118467944ULL);
arm64_l_30:
	/* 0x30: mov x8, #0xbeef */
	ARM64_SIM_RUN_OP3(ARM64_OP_MOV_IMM, ARM64_X8, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, 0, 48879ULL);
arm64_l_34:
	/* 0x34: adrp x19, 0x0 */
	(void)0;
arm64_l_38:
	/* 0x38: movk x8, #0xdead, lsl #16 */
	ARM64_SIM_RUN_OP3(ARM64_OP_MOVK, ARM64_X8, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_MOVK(16), 57005ULL);
arm64_l_3c:
	/* 0x3c: add x1, sp, #0x10 */
	ARM64_SIM_RUN_OP3(ARM64_OP_ALU_IMM, ARM64_X1, ARM64_SP, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_ALU(ARM64_ALU_ADD, ARM64_MOD_NONE, 0), 16ULL);
arm64_l_40:
	/* 0x40: add x2, sp, #0x8 */
	ARM64_SIM_RUN_OP3(ARM64_OP_ALU_IMM, ARM64_X2, ARM64_SP, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_ALU(ARM64_ALU_ADD, ARM64_MOD_NONE, 0), 8ULL);
arm64_l_44:
	/* 0x44: movk x8, #0xface, lsl #32 */
	ARM64_SIM_RUN_OP3(ARM64_OP_MOVK, ARM64_X8, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_MOVK(32), 64206ULL);
arm64_l_48:
	/* 0x48: str q0, [sp, #16] */
	ARM64_SIM_L_STORE_Q0_MEM(ARM64_SP, ARM64_REG_NONE, ARM64_AUX_MEM(ARM64_REG_NONE, ARM64_MOD_NONE, 0, 0), 16ULL);
arm64_l_4c:
	/* 0x4c: mov x3, xzr */
	ARM64_SIM_RUN_OP3(ARM64_OP_MOV_REG, ARM64_X3, ARM64_XZR, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, 0, 0);
arm64_l_50:
	/* 0x50: movk x8, #0xfeed, lsl #48 */
	ARM64_SIM_RUN_OP3(ARM64_OP_MOVK, ARM64_X8, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_MOVK(48), 65261ULL);
arm64_l_54:
	/* 0x54: str x8, [sp, #8] */
	ARM64_SIM_RUN_OP3(ARM64_OP_STORE, ARM64_SP, ARM64_X8, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_MEM(ARM64_REG_NONE, ARM64_MOD_NONE, 0, 0), 8ULL);
arm64_l_58:
	/* 0x58: ldr x19, [x19] */
	ARM64_SIM_L_WRITE_REG_MAP_PTR(ARM64_X19, &str_hash);
arm64_l_5c:
	/* 0x5c: mov x0, x19 */
	ARM64_SIM_RUN_OP3(ARM64_OP_MOV_REG, ARM64_X0, ARM64_X19, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, 0, 0);
arm64_l_60:
	/* 0x60: bl 0x60 */
	ARM64_SIM_BPF_CALL_bpf_map_update_elem();
arm64_l_64:
	/* 0x64: add x1, sp, #0x10 */
	ARM64_SIM_RUN_OP3(ARM64_OP_ALU_IMM, ARM64_X1, ARM64_SP, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_ALU(ARM64_ALU_ADD, ARM64_MOD_NONE, 0), 16ULL);
arm64_l_68:
	/* 0x68: mov x0, x19 */
	ARM64_SIM_RUN_OP3(ARM64_OP_MOV_REG, ARM64_X0, ARM64_X19, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, 0, 0);
arm64_l_6c:
	/* 0x6c: bl 0x6c */
	ARM64_SIM_BPF_CALL_bpf_map_lookup_elem();
arm64_l_70:
	/* 0x70: cbz x0, 0x7c */
	ARM64_SIM_A64_CBZ(ARM64_X0, 0x70, 0x7c, arm64_l_7c);
arm64_l_74:
	/* 0x74: ldr x8, [x0] */
	ARM64_SIM_RUN_OP3(ARM64_OP_LOAD, ARM64_X8, ARM64_X0, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_MEM(ARM64_REG_NONE, ARM64_MOD_NONE, 0, 0), 0ULL);
arm64_l_78:
	/* 0x78: b 0x80 */
	ARM64_SIM_A64_JMP(0x78, 0x80, arm64_l_80);
arm64_l_7c:
	/* 0x7c: mov x8, xzr */
	ARM64_SIM_RUN_OP3(ARM64_OP_MOV_REG, ARM64_X8, ARM64_XZR, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, 0, 0);
arm64_l_80:
	/* 0x80: ldr x9, [sp] */
	ARM64_SIM_RUN_OP3(ARM64_OP_LOAD, ARM64_X9, ARM64_SP, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_MEM(ARM64_REG_NONE, ARM64_MOD_NONE, 0, 0), 0ULL);
arm64_l_84:
	/* 0x84: ldp x30, x19, [sp, #32] */
	ARM64_SIM_RUN_OP3(ARM64_OP_LDP, ARM64_X30, ARM64_X19, ARM64_SP, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_MEM(ARM64_REG_NONE, ARM64_MOD_NONE, 0, 0), 32ULL);
arm64_l_88:
	/* 0x88: mov w0, #0x2 */
	ARM64_SIM_RUN_OP3(ARM64_OP_MOV_IMM, ARM64_X0, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_32, 0, 2ULL);
arm64_l_8c:
	/* 0x8c: str x8, [x9] */
	ARM64_SIM_RUN_OP3(ARM64_OP_STORE, ARM64_X9, ARM64_X8, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_MEM(ARM64_REG_NONE, ARM64_MOD_NONE, 0, 0), 0ULL);
arm64_l_90:
	/* 0x90: add sp, sp, #0x30 */
	ARM64_SIM_RUN_OP3(ARM64_OP_ALU_IMM, ARM64_SP, ARM64_SP, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_ALU(ARM64_ALU_ADD, ARM64_MOD_NONE, 0), 48ULL);
arm64_l_94:
	/* 0x94: mov x7, x0 */
	ARM64_SIM_RUN_OP3(ARM64_OP_MOV_REG, ARM64_X7, ARM64_X0, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, 0, 0);
	ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X0, ARM64_SIM_L_READ_REG(ARM64_X7), ARM64_WIDTH_64);
	ARM64_SIM_RET();
}

ARM64_SIM_LICENSE();
