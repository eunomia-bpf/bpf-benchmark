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

#define KINSN_SELECT_COND_NEZ 0

static int decode_select_call(const struct bpf_insn *insn,
			      struct bpf_kinsn_call *call)
{
	(void)insn;

	if (call->encoding != BPF_KINSN_ENC_PACKED_CALL)
		return 0;

	call->dst_reg = kinsn_payload_reg(call->payload, 0);
	call->nr_operands = 3;
	kinsn_set_reg_operand(call, 0, kinsn_payload_reg(call->payload, 4));
	kinsn_set_reg_operand(call, 1, kinsn_payload_reg(call->payload, 8));
	kinsn_set_reg_operand(call, 2, kinsn_payload_reg(call->payload, 12));
	call->reserved = kinsn_payload_reg(call->payload, 16);
	return 0;
}

static int validate_select_call(const struct bpf_kinsn_call *call,
				struct bpf_verifier_log *log)
{
	(void)log;

	if (call->encoding != BPF_KINSN_ENC_PACKED_CALL)
		return 0;
	if (!kinsn_operand_is_reg(call, 0) || !kinsn_operand_is_reg(call, 1) ||
	    !kinsn_operand_is_reg(call, 2))
		return -EINVAL;
	if (call->reserved != KINSN_SELECT_COND_NEZ)
		return -EINVAL;
	return 0;
}

static void emit_u8(u8 *buf, u32 *len, u8 byte)
{
	buf[(*len)++] = byte;
}

static void emit_rex_rr(u8 *buf, u32 *len, bool is64, u8 reg, u8 rm)
{
	u8 rex = 0x40;

	if (is64)
		rex |= 0x08;
	if (kinsn_x86_reg_ext(reg))
		rex |= 0x04;
	if (kinsn_x86_reg_ext(rm))
		rex |= 0x01;
	if (rex != 0x40)
		emit_u8(buf, len, rex);
}

static void emit_mov_rr(u8 *buf, u32 *len, u8 dst_reg, u8 src_reg)
{
	emit_rex_rr(buf, len, true, src_reg, dst_reg);
	emit_u8(buf, len, 0x89);
	emit_u8(buf, len, 0xC0 |
		(kinsn_x86_reg_code(src_reg) << 3) |
		kinsn_x86_reg_code(dst_reg));
}

static void emit_test_rr(u8 *buf, u32 *len, u8 reg)
{
	emit_rex_rr(buf, len, true, reg, reg);
	emit_u8(buf, len, 0x85);
	emit_u8(buf, len, 0xC0 |
		(kinsn_x86_reg_code(reg) << 3) |
		kinsn_x86_reg_code(reg));
}

static void emit_cmov_rr(u8 *buf, u32 *len, u8 dst_reg, u8 src_reg, u8 cc)
{
	emit_rex_rr(buf, len, true, dst_reg, src_reg);
	emit_u8(buf, len, 0x0F);
	emit_u8(buf, len, cc);
	emit_u8(buf, len, 0xC0 |
		(kinsn_x86_reg_code(dst_reg) << 3) |
		kinsn_x86_reg_code(src_reg));
}

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
	u8 buf[16];
	u32 len = 0;

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

	(void)prog;

	if (call->encoding == BPF_KINSN_ENC_PACKED_CALL) {
		u8 dst_reg = call->dst_reg;
		u8 true_reg = call->operands[0].regno;
		u8 false_reg = call->operands[1].regno;
		u8 cond_reg = call->operands[2].regno;

		if (!kinsn_x86_reg_valid(dst_reg) ||
		    !kinsn_x86_reg_valid(true_reg) ||
		    !kinsn_x86_reg_valid(false_reg) ||
		    !kinsn_x86_reg_valid(cond_reg))
			return -EINVAL;

		if (dst_reg != false_reg && dst_reg != true_reg)
			emit_mov_rr(buf, &len, dst_reg, false_reg);

		emit_test_rr(buf, &len, cond_reg);
		if (dst_reg == true_reg)
			emit_cmov_rr(buf, &len, dst_reg, false_reg, 0x44);
		else
			emit_cmov_rr(buf, &len, dst_reg, true_reg, 0x45);

		if (emit)
			memcpy(image + *off, buf, len);
		*off += len;
		return len;
	}

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

	if (call->encoding == BPF_KINSN_ENC_PACKED_CALL) {
		effect->input_mask = BIT(call->operands[0].regno) |
				     BIT(call->operands[1].regno) |
				     BIT(call->operands[2].regno);
		effect->clobber_mask = BIT(call->dst_reg);
		effect->result_reg = call->dst_reg;
	} else {
		effect->input_mask = BIT(BPF_REG_1) | BIT(BPF_REG_2) | BIT(BPF_REG_3);
		effect->clobber_mask = BIT(BPF_REG_0);
		effect->result_reg = BPF_REG_0;
	}
	effect->result_type = BPF_KINSN_RES_SCALAR;
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
	.supported_encodings = BPF_KINSN_ENC_LEGACY_KFUNC |
			       BPF_KINSN_ENC_PACKED_CALL,
	.decode_call = decode_select_call,
	.validate_call = validate_select_call,
	.model_call = model_select_call,
	.emit_x86 = emit_select_x86,
	.max_emit_bytes = 16,
};

/* ---- module definition ---- */

DEFINE_KINSN_MODULE(bpf_select, "bpf_select64", &select_ops,
		    "BpfReJIT kinsn: COND_SELECT (CMOV) inline kfunc");
