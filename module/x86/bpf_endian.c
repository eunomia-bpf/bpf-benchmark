// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT kinsn: ENDIAN_LOAD — fused load-and-byte-swap for x86-64
 */

#include "kinsn_common.h"

static int decode_endian_call(const struct bpf_insn *insn,
			      struct bpf_kinsn_call *call)
{
	(void)insn;

	if (call->encoding != BPF_KINSN_ENC_PACKED_CALL)
		return 0;

	call->dst_reg = kinsn_payload_reg(call->payload, 0);
	call->nr_operands = 1;
	kinsn_set_reg_operand(call, 0, kinsn_payload_reg(call->payload, 4));
	return 0;
}

static int validate_endian_call(const struct bpf_kinsn_call *call,
				struct bpf_verifier_log *log)
{
	(void)log;

	if (call->encoding != BPF_KINSN_ENC_PACKED_CALL)
		return 0;
	if (!kinsn_operand_is_reg(call, 0))
		return -EINVAL;
	return 0;
}

static void emit_u8(u8 *buf, u32 *len, u8 byte)
{
	buf[(*len)++] = byte;
}

static void emit_rex(u8 *buf, u32 *len, bool is64, bool reg_ext, bool rm_ext)
{
	u8 rex = 0x40;

	if (is64)
		rex |= 0x08;
	if (reg_ext)
		rex |= 0x04;
	if (rm_ext)
		rex |= 0x01;
	if (rex != 0x40)
		emit_u8(buf, len, rex);
}

static void emit_mem_modrm(u8 *buf, u32 *len, u8 reg_field, u8 base_reg)
{
	u8 modrm;

	if (base_reg == BPF_REG_10 || base_reg == BPF_REG_7) {
		modrm = 0x40 |
			(kinsn_x86_reg_code(reg_field) << 3) |
			kinsn_x86_reg_code(base_reg);
		emit_u8(buf, len, modrm);
		emit_u8(buf, len, 0x00);
		return;
	}

	modrm = (kinsn_x86_reg_code(reg_field) << 3) |
		kinsn_x86_reg_code(base_reg);
	emit_u8(buf, len, modrm);
}

static void emit_load16_zx(u8 *buf, u32 *len, u8 dst_reg, u8 base_reg)
{
	emit_rex(buf, len, false, kinsn_x86_reg_ext(dst_reg),
		 kinsn_x86_reg_ext(base_reg));
	emit_u8(buf, len, 0x0F);
	emit_u8(buf, len, 0xB7);
	emit_mem_modrm(buf, len, dst_reg, base_reg);
}

static void emit_load32(u8 *buf, u32 *len, u8 dst_reg, u8 base_reg)
{
	emit_rex(buf, len, false, kinsn_x86_reg_ext(dst_reg),
		 kinsn_x86_reg_ext(base_reg));
	emit_u8(buf, len, 0x8B);
	emit_mem_modrm(buf, len, dst_reg, base_reg);
}

static void emit_load64(u8 *buf, u32 *len, u8 dst_reg, u8 base_reg)
{
	emit_rex(buf, len, true, kinsn_x86_reg_ext(dst_reg),
		 kinsn_x86_reg_ext(base_reg));
	emit_u8(buf, len, 0x8B);
	emit_mem_modrm(buf, len, dst_reg, base_reg);
}

static void emit_rol16_8(u8 *buf, u32 *len, u8 dst_reg)
{
	emit_u8(buf, len, 0x66);
	emit_rex(buf, len, false, false, kinsn_x86_reg_ext(dst_reg));
	emit_u8(buf, len, 0xC1);
	emit_u8(buf, len, 0xC0 | kinsn_x86_reg_code(dst_reg));
	emit_u8(buf, len, 0x08);
}

static void emit_bswap32(u8 *buf, u32 *len, u8 dst_reg)
{
	emit_rex(buf, len, false, false, kinsn_x86_reg_ext(dst_reg));
	emit_u8(buf, len, 0x0F);
	emit_u8(buf, len, 0xC8 + kinsn_x86_reg_code(dst_reg));
}

static void emit_bswap64(u8 *buf, u32 *len, u8 dst_reg)
{
	emit_rex(buf, len, true, false, kinsn_x86_reg_ext(dst_reg));
	emit_u8(buf, len, 0x0F);
	emit_u8(buf, len, 0xC8 + kinsn_x86_reg_code(dst_reg));
}

static int emit_endian_load_x86(u8 *image, u32 *off, bool emit,
				const struct bpf_kinsn_call *call,
				u8 size)
{
	u8 buf[16];
	u32 len = 0;
	u8 dst_reg = call->encoding == BPF_KINSN_ENC_PACKED_CALL ?
		     call->dst_reg : BPF_REG_0;
	u8 base_reg = call->encoding == BPF_KINSN_ENC_PACKED_CALL ?
		      call->operands[0].regno : BPF_REG_1;

	if (!kinsn_x86_reg_valid(dst_reg) || !kinsn_x86_reg_valid(base_reg))
		return -EINVAL;

	switch (size) {
	case sizeof(u16):
		emit_load16_zx(buf, &len, dst_reg, base_reg);
		emit_rol16_8(buf, &len, dst_reg);
		break;
	case sizeof(u32):
		emit_load32(buf, &len, dst_reg, base_reg);
		emit_bswap32(buf, &len, dst_reg);
		break;
	case sizeof(u64):
		emit_load64(buf, &len, dst_reg, base_reg);
		emit_bswap64(buf, &len, dst_reg);
		break;
	default:
		return -EINVAL;
	}

	if (emit)
		memcpy(image + *off, buf, len);
	*off += len;
	return len;
}

/* ---- kfunc fallback implementations ---- */

__bpf_kfunc_start_defs();

__bpf_kfunc u64 bpf_endian_load16(const void *addr)
{
	u16 val = *(const u16 *)addr;
	return __builtin_bswap16(val);
}

__bpf_kfunc u64 bpf_endian_load32(const void *addr)
{
	u32 val = *(const u32 *)addr;
	return __builtin_bswap32(val);
}

__bpf_kfunc u64 bpf_endian_load64(const void *addr)
{
	u64 val = *(const u64 *)addr;
	return __builtin_bswap64(val);
}

__bpf_kfunc_end_defs();

/* ---- BTF kfunc set ---- */

KINSN_KFUNC_SET_START(bpf_endian)
KINSN_KFUNC_ID(bpf_endian_load16)
KINSN_KFUNC_ID(bpf_endian_load32)
KINSN_KFUNC_ID(bpf_endian_load64)
KINSN_KFUNC_SET_END(bpf_endian)

/* ---- x86 JIT emit callbacks ---- */

static int emit_endian_load16_x86(u8 *image, u32 *off, bool emit,
				  const struct bpf_kinsn_call *call,
				  struct bpf_prog *prog)
{
	(void)prog;
	if (!off || (emit && !image))
		return -EINVAL;
	return emit_endian_load_x86(image, off, emit, call, sizeof(u16));
}

static int emit_endian_load32_x86(u8 *image, u32 *off, bool emit,
				  const struct bpf_kinsn_call *call,
				  struct bpf_prog *prog)
{
	(void)prog;
	if (!off || (emit && !image))
		return -EINVAL;
	return emit_endian_load_x86(image, off, emit, call, sizeof(u32));
}

static int emit_endian_load64_x86(u8 *image, u32 *off, bool emit,
				  const struct bpf_kinsn_call *call,
				  struct bpf_prog *prog)
{
	(void)prog;
	if (!off || (emit && !image))
		return -EINVAL;
	return emit_endian_load_x86(image, off, emit, call, sizeof(u64));
}

static void model_endian_load(const struct bpf_kinsn_call *call,
			      struct bpf_kinsn_effect *effect, u8 size)
{
	u8 result_reg = call->encoding == BPF_KINSN_ENC_PACKED_CALL ?
			call->dst_reg : BPF_REG_0;
	u8 base_reg = call->encoding == BPF_KINSN_ENC_PACKED_CALL ?
		      call->operands[0].regno : BPF_REG_1;
	u64 umax;

	effect->input_mask = BIT(base_reg);
	effect->clobber_mask = BIT(result_reg);
	effect->result_type = BPF_KINSN_RES_SCALAR;
	effect->result_reg = result_reg;
	effect->result_size = size == sizeof(u32) ? sizeof(u32) : sizeof(u64);
	effect->nr_mem_accesses = 1;
	effect->mem_accesses[0].base_reg = base_reg;
	effect->mem_accesses[0].size = size;
	effect->mem_accesses[0].access_type = BPF_READ;
	effect->mem_accesses[0].flags = BPF_KINSN_MEM_RESULT;

	umax = size == sizeof(u64) ? U64_MAX : ((1ULL << (size * 8)) - 1);
	effect->umin_value = 0;
	effect->umax_value = umax;
	effect->smin_value = 0;
	effect->smax_value = umax;
	if (umax != U64_MAX) {
		effect->flags |= BPF_KINSN_EFFECT_HAS_TNUM;
		effect->result_tnum = kinsn_tnum_low_bits(umax);
	}
}

static int model_endian_load16_call(const struct bpf_kinsn_call *call,
				    const struct bpf_kinsn_scalar_state *scalar_regs,
				    struct bpf_kinsn_effect *effect)
{
	(void)scalar_regs;
	model_endian_load(call, effect, sizeof(u16));
	return 0;
}

static int model_endian_load32_call(const struct bpf_kinsn_call *call,
				    const struct bpf_kinsn_scalar_state *scalar_regs,
				    struct bpf_kinsn_effect *effect)
{
	(void)scalar_regs;
	model_endian_load(call, effect, sizeof(u32));
	return 0;
}

static int model_endian_load64_call(const struct bpf_kinsn_call *call,
				    const struct bpf_kinsn_scalar_state *scalar_regs,
				    struct bpf_kinsn_effect *effect)
{
	(void)scalar_regs;
	model_endian_load(call, effect, sizeof(u64));
	return 0;
}

static struct bpf_kinsn_ops endian_load16_ops = {
	.owner = THIS_MODULE,
	.api_version = 1,
	.supported_encodings = BPF_KINSN_ENC_LEGACY_KFUNC |
			       BPF_KINSN_ENC_PACKED_CALL,
	.decode_call = decode_endian_call,
	.validate_call = validate_endian_call,
	.model_call = model_endian_load16_call,
	.emit_x86 = emit_endian_load16_x86,
	.max_emit_bytes = 16,
};

static struct bpf_kinsn_ops endian_load32_ops = {
	.owner = THIS_MODULE,
	.api_version = 1,
	.supported_encodings = BPF_KINSN_ENC_LEGACY_KFUNC |
			       BPF_KINSN_ENC_PACKED_CALL,
	.decode_call = decode_endian_call,
	.validate_call = validate_endian_call,
	.model_call = model_endian_load32_call,
	.emit_x86 = emit_endian_load32_x86,
	.max_emit_bytes = 16,
};

static struct bpf_kinsn_ops endian_load64_ops = {
	.owner = THIS_MODULE,
	.api_version = 1,
	.supported_encodings = BPF_KINSN_ENC_LEGACY_KFUNC |
			       BPF_KINSN_ENC_PACKED_CALL,
	.decode_call = decode_endian_call,
	.validate_call = validate_endian_call,
	.model_call = model_endian_load64_call,
	.emit_x86 = emit_endian_load64_x86,
	.max_emit_bytes = 16,
};

/* ---- module definition ---- */

static const struct kinsn_ops_entry endian_entries[] = {
	{ "bpf_endian_load16", &endian_load16_ops },
	{ "bpf_endian_load32", &endian_load32_ops },
	{ "bpf_endian_load64", &endian_load64_ops },
};

DEFINE_KINSN_MODULE_MULTI(bpf_endian, endian_entries,
			  "BpfReJIT kinsn: ENDIAN_LOAD inline kfunc");
