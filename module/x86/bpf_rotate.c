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

static int decode_rotate_call(const struct bpf_insn *insn,
			      struct bpf_kinsn_call *call)
{
	(void)insn;

	if (call->encoding != BPF_KINSN_ENC_PACKED_CALL)
		return 0;

	call->dst_reg = kinsn_payload_reg(call->payload, 0);
	call->nr_operands = 2;
	kinsn_set_reg_operand(call, 0, kinsn_payload_reg(call->payload, 4));
	kinsn_set_imm32_operand(call, 1, kinsn_payload_u8(call->payload, 8));
	return 0;
}

static int validate_rotate_call(const struct bpf_kinsn_call *call,
				struct bpf_verifier_log *log)
{
	(void)log;

	if (call->encoding != BPF_KINSN_ENC_PACKED_CALL)
		return 0;
	if (!kinsn_operand_is_reg(call, 0) || !kinsn_operand_is_imm32(call, 1))
		return -EINVAL;
	if (call->operands[1].imm32 < 0 || call->operands[1].imm32 > 63)
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

static void emit_rol_imm(u8 *buf, u32 *len, u8 dst_reg, u8 imm8)
{
	emit_rex_rr(buf, len, true, 0, dst_reg);
	emit_u8(buf, len, 0xC1);
	emit_u8(buf, len, 0xC0 | kinsn_x86_reg_code(dst_reg));
	emit_u8(buf, len, imm8);
}

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
	u8 buf[8];
	u32 len = 0;

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

	(void)prog;

	if (call->encoding == BPF_KINSN_ENC_PACKED_CALL) {
		u8 dst_reg = call->dst_reg;
		u8 src_reg = call->operands[0].regno;
		u8 shift = call->operands[1].imm32 & 63;

		if (!kinsn_x86_reg_valid(dst_reg) || !kinsn_x86_reg_valid(src_reg))
			return -EINVAL;

		if (dst_reg != src_reg)
			emit_mov_rr(buf, &len, dst_reg, src_reg);
		if (shift)
			emit_rol_imm(buf, &len, dst_reg, shift);

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

static int model_rotate_call(const struct bpf_kinsn_call *call,
			     const struct bpf_kinsn_scalar_state *scalar_regs,
			     struct bpf_kinsn_effect *effect)
{
	(void)scalar_regs;

	if (call->encoding == BPF_KINSN_ENC_PACKED_CALL) {
		effect->input_mask = BIT(call->operands[0].regno);
		effect->clobber_mask = BIT(call->dst_reg);
		effect->result_reg = call->dst_reg;
	} else {
		effect->input_mask = BIT(BPF_REG_1) | BIT(BPF_REG_2);
		effect->clobber_mask = BIT(BPF_REG_0) | BIT(BPF_REG_4);
		effect->result_reg = BPF_REG_0;
	}
	effect->result_type = BPF_KINSN_RES_SCALAR;
	effect->result_size = sizeof(u64);
	return 0;
}

static const struct bpf_kinsn_ops rotate_ops = {
	.owner = THIS_MODULE,
	.api_version = 1,
	.supported_encodings = BPF_KINSN_ENC_LEGACY_KFUNC |
			       BPF_KINSN_ENC_PACKED_CALL,
	.decode_call = decode_rotate_call,
	.validate_call = validate_rotate_call,
	.model_call = model_rotate_call,
	.emit_x86 = emit_rotate_x86,
	.max_emit_bytes = 16,
};

/* ---- module definition ---- */

DEFINE_KINSN_MODULE(bpf_rotate, "bpf_rotate64", &rotate_ops,
		    "BpfReJIT kinsn: ROTATE (ROL) inline kfunc");
