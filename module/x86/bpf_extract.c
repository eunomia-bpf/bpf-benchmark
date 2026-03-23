// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT kinsn: BITFIELD_EXTRACT — bit-field extraction for x86-64
 *
 * Legacy ABI keeps the existing kfunc signature:
 *   bpf_extract64(u64 val, u32 start, u32 len)
 *
 * Packed ABI targets the in-place pattern produced by the daemon:
 *   dst = extract(dst, start_imm, len_imm)
 */

#include "kinsn_common.h"

static int decode_extract_call(const struct bpf_insn *insn,
			       struct bpf_kinsn_call *call)
{
	(void)insn;

	if (call->encoding != BPF_KINSN_ENC_PACKED_CALL)
		return 0;

	call->dst_reg = kinsn_payload_reg(call->payload, 0);
	call->nr_operands = 3;
	kinsn_set_reg_operand(call, 0, call->dst_reg);
	kinsn_set_imm32_operand(call, 1, kinsn_payload_u8(call->payload, 8));
	kinsn_set_imm32_operand(call, 2, kinsn_payload_u8(call->payload, 16));
	return 0;
}

static int validate_extract_call(const struct bpf_kinsn_call *call,
				 struct bpf_verifier_log *log)
{
	u32 start, len;

	(void)log;

	if (call->encoding != BPF_KINSN_ENC_PACKED_CALL)
		return 0;
	if (!kinsn_operand_is_reg(call, 0) ||
	    !kinsn_operand_is_imm32(call, 1) ||
	    !kinsn_operand_is_imm32(call, 2))
		return -EINVAL;

	start = call->operands[1].imm32;
	len = call->operands[2].imm32;
	if (start >= 64 || !len || len > 32 || start + len > 64)
		return -EINVAL;
	return 0;
}

static void emit_u8(u8 *buf, u32 *len, u8 byte)
{
	buf[(*len)++] = byte;
}

static void emit_u32(u8 *buf, u32 *len, u32 value)
{
	memcpy(buf + *len, &value, sizeof(value));
	*len += sizeof(value);
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

static void emit_shr_imm(u8 *buf, u32 *len, u8 dst_reg, u8 imm8)
{
	emit_rex_rr(buf, len, true, 0, dst_reg);
	emit_u8(buf, len, 0xC1);
	emit_u8(buf, len, 0xE8 | kinsn_x86_reg_code(dst_reg));
	emit_u8(buf, len, imm8);
}

static void emit_and_imm32(u8 *buf, u32 *len, u8 dst_reg, u32 imm32)
{
	emit_rex_rr(buf, len, false, 0, dst_reg);
	emit_u8(buf, len, 0x81);
	emit_u8(buf, len, 0xE0 | kinsn_x86_reg_code(dst_reg));
	emit_u32(buf, len, imm32);
}

/* ---- kfunc fallback implementation ---- */

__bpf_kfunc_start_defs();

__bpf_kfunc u64 bpf_extract64(u64 val, u32 start, u32 len)
{
	if (start >= 64 || len == 0 || len > 64)
		return 0;
	if (start + len > 64)
		len = 64 - start;
	return (val >> start) & (len >= 64 ? ~0ULL : (1ULL << len) - 1);
}

__bpf_kfunc_end_defs();

/* ---- BTF kfunc set ---- */

KINSN_KFUNC_SET(bpf_extract, bpf_extract64)

/* ---- x86 JIT emit callback ---- */

static int emit_extract_x86(u8 *image, u32 *off, bool emit,
			    const struct bpf_kinsn_call *call,
			    struct bpf_prog *prog)
{
	u8 buf[32];
	u32 len = 0;
	static const u8 legacy_insns[] = {
		0x48, 0x89, 0xF8,		/* mov rax, rdi */
		0x48, 0x89, 0xF1,		/* mov rcx, rsi */
		0x48, 0xD3, 0xE8,		/* shr rax, cl  */
		0x89, 0xD1,			/* mov ecx, edx */
		0x41, 0xBB, 0x01, 0x00, 0x00, 0x00, /* mov r11d, 1 */
		0x49, 0xD3, 0xE3,		/* shl r11, cl  */
		0x49, 0xFF, 0xCB,		/* dec r11      */
		0x4C, 0x21, 0xD8,		/* and rax, r11 */
	};

	if (!off)
		return -EINVAL;
	if (emit && !image)
		return -EINVAL;

	(void)prog;

	if (call->encoding == BPF_KINSN_ENC_PACKED_CALL) {
		u8 dst_reg = call->dst_reg;
		u8 start = call->operands[1].imm32;
		u8 bit_len = call->operands[2].imm32;
		u32 mask = bit_len == 32 ? 0xffffffffU : ((1U << bit_len) - 1);

		if (!kinsn_x86_reg_valid(dst_reg))
			return -EINVAL;

		if (start)
			emit_shr_imm(buf, &len, dst_reg, start);
		emit_and_imm32(buf, &len, dst_reg, mask);

		if (emit)
			memcpy(image + *off, buf, len);
		*off += len;
		return len;
	}

	if (emit)
		memcpy(image + *off, legacy_insns, sizeof(legacy_insns));

	*off += sizeof(legacy_insns);
	return sizeof(legacy_insns);
}

static u64 extract_result_umax(const struct bpf_kinsn_scalar_state *start,
			       const struct bpf_kinsn_scalar_state *len)
{
	u64 width;

	if (tnum_is_const(start->var_off) &&
	    start->var_off.value >= 64)
		return 0;

	if (tnum_is_const(len->var_off)) {
		width = len->var_off.value;
		if (!width || width > 64)
			return 0;
		if (tnum_is_const(start->var_off) && start->var_off.value + width > 64)
			width = 64 - start->var_off.value;
	} else {
		width = min_t(u64, len->umax_value, 64);
		if (!width)
			return 0;
	}

	if (width >= 64)
		return U64_MAX;
	return (1ULL << width) - 1;
}

static int model_extract_call(const struct bpf_kinsn_call *call,
			      const struct bpf_kinsn_scalar_state *scalar_regs,
			      struct bpf_kinsn_effect *effect)
{
	u64 umax;

	if (call->encoding == BPF_KINSN_ENC_PACKED_CALL) {
		u32 bit_len = call->operands[2].imm32;

		effect->input_mask = BIT(call->dst_reg);
		effect->clobber_mask = BIT(call->dst_reg);
		effect->result_reg = call->dst_reg;
		effect->result_size = sizeof(u64);
		umax = bit_len == 32 ? U32_MAX : ((1ULL << bit_len) - 1);
	} else {
		effect->input_mask = BIT(BPF_REG_1) | BIT(BPF_REG_2) | BIT(BPF_REG_3);
		effect->clobber_mask = BIT(BPF_REG_0) | BIT(BPF_REG_4);
		effect->result_reg = BPF_REG_0;
		effect->result_size = sizeof(u64);
		umax = extract_result_umax(&scalar_regs[1], &scalar_regs[2]);
	}

	effect->result_type = BPF_KINSN_RES_SCALAR;
	effect->umin_value = 0;
	effect->umax_value = umax;
	effect->smin_value = 0;
	effect->smax_value = umax;
	if (umax != U64_MAX) {
		effect->flags |= BPF_KINSN_EFFECT_HAS_TNUM;
		effect->result_tnum = kinsn_tnum_low_bits(umax);
	}
	return 0;
}

static struct bpf_kinsn_ops extract_ops = {
	.owner = THIS_MODULE,
	.api_version = 1,
	.supported_encodings = BPF_KINSN_ENC_LEGACY_KFUNC |
			       BPF_KINSN_ENC_PACKED_CALL,
	.decode_call = decode_extract_call,
	.validate_call = validate_extract_call,
	.model_call = model_extract_call,
	.emit_x86 = emit_extract_x86,
	.max_emit_bytes = 32,
};

/* ---- module definition ---- */

DEFINE_KINSN_MODULE(bpf_extract, "bpf_extract64", &extract_ops,
		    "BpfReJIT kinsn: BITFIELD_EXTRACT inline kfunc");
