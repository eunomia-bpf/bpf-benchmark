// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT kinsn: COND_SELECT — branchless conditional select via CSEL (ARM64)
 *
 * Registers a kfunc bpf_select64(u64 a, u64 b, u64 cond) with KF_KINSN.
 * Semantics: returns a if cond != 0, otherwise returns b.
 * When inlined by the ARM64 JIT, emits TST + CSEL instead of a BL.
 *
 * BPF register -> ARM64 register mapping (from bpf_jit_comp.c bpf2a64[]):
 *   BPF_REG_0 = X7  (return value)
 *   BPF_REG_1 = X0  (arg1 = a)
 *   BPF_REG_2 = X1  (arg2 = b)
 *   BPF_REG_3 = X2  (arg3 = cond)
 *
 * Emitted ARM64 sequence (2 instructions, 8 bytes):
 *   TST   X2, X2         ; set flags based on cond
 *   CSEL  X7, X0, X1, NE ; X7 = (cond != 0) ? X0(a) : X1(b)
 */

#include "kinsn_common.h"

/* ---- kfunc fallback implementation ---- */

__bpf_kfunc_start_defs();

__bpf_kfunc u64 bpf_select64(u64 a, u64 b, u64 cond)
{
	return cond ? a : b;
}

__bpf_kfunc_end_defs();

/* ---- BTF kfunc set ---- */

KINSN_KFUNC_SET(bpf_select, bpf_select64)

/* ---- ARM64 JIT emit callback ---- */

/*
 * ARM64 register IDs matching bpf2a64[] in bpf_jit_comp.c:
 *   BPF_REG_0 -> X7,  BPF_REG_1 -> X0,  BPF_REG_2 -> X1,  BPF_REG_3 -> X2
 */
#define ARM64_BPF_R0	7	/* X7 */
#define ARM64_BPF_R1	0	/* X0 */
#define ARM64_BPF_R2	1	/* X1 */
#define ARM64_BPF_R3	2	/* X2 */

/*
 * Encode TST Xn, Xm  (= ANDS XZR, Xn, Xm, 64-bit)
 *   31  30 29 28     24 23 22 21 20   16 15     10 9    5 4    0
 *   sf   1  1 01010   shift  0  Rm       imm6     Rn     Rd(=ZR)
 *   sf=1, opc=11(ANDS), shift=00(LSL), imm6=000000
 */
static inline u32 a64_tst(u8 rn, u8 rm)
{
	return (0xEA000000U) |		/* 1 11 01010 00 0 ... */
	       ((u32)rm << 16) |
	       ((u32)rn << 5) |
	       31U;			/* Rd = XZR = 31 */
}

/*
 * Encode CSEL Xd, Xn, Xm, cond  (64-bit, Conditional Select)
 *   31  30 29 28     21 20   16 15    12 11 10 9    5 4    0
 *   sf   0  0 11010100 Rm      cond      0  0  Rn    Rd
 *   sf=1 for 64-bit
 */
#define COND_NE  0x1

static inline u32 a64_csel(u8 rd, u8 rn, u8 rm, u8 cond)
{
	return (1U << 31) |		/* sf = 1 (64-bit) */
	       (0x1A800000U) |		/* 0 0 11010100 base */
	       ((u32)rm << 16) |
	       ((u32)cond << 12) |
	       ((u32)rn << 5) |
	       (u32)rd;
}

static int emit_select_arm64(u32 *image, int *idx, bool emit,
			     const struct bpf_kinsn_call *call,
			     struct bpf_prog *prog)
{
	/*
	 * TST   X2, X2          -- set flags based on cond
	 * CSEL  X7, X0, X1, NE  -- X7 = (cond != 0) ? a : b
	 */
	u32 tst_insn  = a64_tst(ARM64_BPF_R3, ARM64_BPF_R3);
	u32 csel_insn = a64_csel(ARM64_BPF_R0, ARM64_BPF_R1, ARM64_BPF_R2,
				 COND_NE);

	if (!idx)
		return -EINVAL;

	(void)call;
	(void)prog;

	if (emit) {
		if (!image)
			return -EINVAL;
		image[*idx] = cpu_to_le32(tst_insn);
		image[*idx + 1] = cpu_to_le32(csel_insn);
	}

	*idx += 2;
	return 2;	/* 2 instructions emitted */
}

static void union_scalar_states(struct bpf_kinsn_effect *effect,
				const struct bpf_kinsn_scalar_state *a,
				const struct bpf_kinsn_scalar_state *b)
{
	effect->flags |= BPF_KINSN_EFFECT_HAS_TNUM;
	effect->result_tnum = kinsn_tnum_union(a->var_off, b->var_off);
	effect->umin_value = min(a->umin_value, b->umin_value);
	effect->umax_value = max(a->umax_value, b->umax_value);
	effect->smin_value = min(a->smin_value, b->smin_value);
	effect->smax_value = max(a->smax_value, b->smax_value);
}

static int model_select_call(const struct bpf_kinsn_call *call,
			     const struct bpf_kinsn_scalar_state *scalar_regs,
			     struct bpf_kinsn_effect *effect)
{
	const struct bpf_kinsn_scalar_state *true_val = &scalar_regs[0];
	const struct bpf_kinsn_scalar_state *false_val = &scalar_regs[1];
	const struct bpf_kinsn_scalar_state *cond = &scalar_regs[2];

	(void)call;

	effect->input_mask = BIT(BPF_REG_1) | BIT(BPF_REG_2) | BIT(BPF_REG_3);
	effect->clobber_mask = BIT(BPF_REG_0);
	effect->result_type = BPF_KINSN_RES_SCALAR;
	effect->result_reg = BPF_REG_0;
	effect->result_size = sizeof(u64);

	if (tnum_is_const(cond->var_off)) {
		union_scalar_states(effect,
				    cond->var_off.value ? true_val : false_val,
				    cond->var_off.value ? true_val : false_val);
		return 0;
	}

	union_scalar_states(effect, true_val, false_val);
	return 0;
}

static const struct bpf_kinsn_ops select_ops = {
	.owner = THIS_MODULE,
	.api_version = 1,
	.supported_encodings = BPF_KINSN_ENC_LEGACY_KFUNC,
	.model_call = model_select_call,
	.emit_arm64 = emit_select_arm64,
	.max_emit_bytes = 16,
};

/* ---- module definition ---- */

DEFINE_KINSN_MODULE(bpf_select, "bpf_select64", &select_ops,
		    "BpfReJIT kinsn: COND_SELECT (CSEL) inline kfunc for ARM64");
