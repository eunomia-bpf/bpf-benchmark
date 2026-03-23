// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT kinsn: COND_SELECT — branchless conditional select via CMOV
 *
 * Registers a kfunc bpf_select64(u64 a, u64 b, u64 cond) with KF_KINSN.
 * Semantics: returns a if cond != 0, otherwise returns b.
 * When inlined by the x86 JIT, emits a CMOVNZ sequence instead of a branch
 * or function call.
 *
 * BPF register -> x86 register mapping (from bpf_jit_comp.c):
 *   BPF_REG_0 = RAX (return value)
 *   BPF_REG_1 = RDI (arg1 = a)
 *   BPF_REG_2 = RSI (arg2 = b)
 *   BPF_REG_3 = RDX (arg3 = cond)
 *
 * Emitted x86-64 sequence (10 bytes):
 *   48 89 F0          mov rax, rsi        ; result = b (default)
 *   48 85 D2          test rdx, rdx       ; set ZF based on cond
 *   48 0F 45 C7       cmovnz rax, rdi     ; if cond != 0, result = a
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

/* ---- x86 JIT emit callback ---- */

static int emit_select_x86(u8 *image, u32 *off, bool emit,
			   const struct bpf_kinsn_call *call,
			   struct bpf_prog *prog)
{
	/*
	 * mov  rax, rsi         48 89 F0
	 * test rdx, rdx         48 85 D2
	 * cmovnz rax, rdi       48 0F 45 C7
	 */
	static const u8 insns[] = {
		0x48, 0x89, 0xF0,		/* mov rax, rsi    */
		0x48, 0x85, 0xD2,		/* test rdx, rdx   */
		0x48, 0x0F, 0x45, 0xC7,	/* cmovnz rax, rdi */
	};

	if (!off)
		return -EINVAL;
	if (emit && !image)
		return -EINVAL;

	(void)call;
	(void)prog;

	if (emit)
		memcpy(image + *off, insns, sizeof(insns));

	*off += sizeof(insns);
	return sizeof(insns);
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
	.emit_x86 = emit_select_x86,
	.max_emit_bytes = 16,
};

/* ---- module definition ---- */

DEFINE_KINSN_MODULE(bpf_select, "bpf_select64", &select_ops,
		    "BpfReJIT kinsn: COND_SELECT (CMOV) inline kfunc");
