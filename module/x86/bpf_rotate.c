// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT kinsn: ROTATE — 64-bit rotate left via ROL instruction
 *
 * Registers a kfunc bpf_rotate64(u64 val, u32 shift) with KF_KINSN.
 * When inlined by the x86 JIT, emits a ROL rax, cl sequence instead of a
 * function call.
 *
 * BPF register -> x86 register mapping (from bpf_jit_comp.c):
 *   BPF_REG_0 = RAX (return value)
 *   BPF_REG_1 = RDI (arg1 = val)
 *   BPF_REG_2 = RSI (arg2 = shift)
 *
 * Emitted x86-64 sequence (9 bytes):
 *   48 89 F8       mov rax, rdi      ; result = val
 *   48 89 F1       mov rcx, rsi      ; shift count into CL
 *   48 D3 C0       rol rax, cl       ; rotate left by CL bits
 */

#include "kinsn_common.h"

/* ---- kfunc fallback implementation ---- */

__bpf_kfunc_start_defs();

__bpf_kfunc u64 bpf_rotate64(u64 val, u32 shift)
{
	shift &= 63;
	if (shift == 0)
		return val;
	return (val << shift) | (val >> (64 - shift));
}

__bpf_kfunc_end_defs();

/* ---- BTF kfunc set ---- */

KINSN_KFUNC_SET(bpf_rotate, bpf_rotate64)

/* ---- x86 JIT emit callback ---- */

static int emit_rotate_x86(u8 *image, u32 *off, bool emit,
			   const struct bpf_kinsn_call *call,
			   struct bpf_prog *prog)
{
	/*
	 * mov rax, rdi        48 89 F8
	 * mov rcx, rsi        48 89 F1
	 * rol rax, cl         48 D3 C0
	 */
	static const u8 insns[] = {
		0x48, 0x89, 0xF8,	/* mov rax, rdi */
		0x48, 0x89, 0xF1,	/* mov rcx, rsi */
		0x48, 0xD3, 0xC0,	/* rol rax, cl  */
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

static int model_rotate_call(const struct bpf_kinsn_call *call,
			     const struct bpf_kinsn_scalar_state *scalar_regs,
			     struct bpf_kinsn_effect *effect)
{
	(void)call;
	(void)scalar_regs;

	effect->input_mask = BIT(BPF_REG_1) | BIT(BPF_REG_2);
	effect->clobber_mask = BIT(BPF_REG_0) | BIT(BPF_REG_4);
	effect->result_type = BPF_KINSN_RES_SCALAR;
	effect->result_reg = BPF_REG_0;
	effect->result_size = sizeof(u64);
	return 0;
}

static const struct bpf_kinsn_ops rotate_ops = {
	.owner = THIS_MODULE,
	.api_version = 1,
	.supported_encodings = BPF_KINSN_ENC_LEGACY_KFUNC,
	.model_call = model_rotate_call,
	.emit_x86 = emit_rotate_x86,
	.max_emit_bytes = 16,
};

/* ---- module definition ---- */

DEFINE_KINSN_MODULE(bpf_rotate, "bpf_rotate64", &rotate_ops,
		    "BpfReJIT kinsn: ROTATE (ROL) inline kfunc");
