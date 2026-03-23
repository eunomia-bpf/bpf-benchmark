// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT kinsn: ENDIAN_LOAD — fused load-and-byte-swap via REV (ARM64)
 *
 * Registers three kfuncs with KF_KINSN:
 *   bpf_endian_load16(void *addr) -> u64  (16-bit load + bswap)
 *   bpf_endian_load32(void *addr) -> u64  (32-bit load + bswap)
 *   bpf_endian_load64(void *addr) -> u64  (64-bit load + bswap)
 *
 * BPF register -> ARM64 register mapping (from bpf_jit_comp.c bpf2a64[]):
 *   BPF_REG_0 = X7  (return value)
 *   BPF_REG_1 = X0  (arg1 = addr)
 *
 * Emitted ARM64 sequences:
 *   bpf_endian_load16: LDRH W7, [X0]  +  REV16 W7, W7  +  AND X7, X7, #0xFFFF
 *   bpf_endian_load32: LDR  W7, [X0]  +  REV   W7, W7
 *   bpf_endian_load64: LDR  X7, [X0]  +  REV   X7, X7
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

/* ---- ARM64 JIT emit callbacks ---- */

/*
 * ARM64 register IDs matching bpf2a64[] in bpf_jit_comp.c:
 *   BPF_REG_0  -> X7   (return value)
 *   BPF_REG_1  -> X0   (arg1 = addr)
 */
#define ARM64_BPF_R0	7	/* X7 */
#define ARM64_BPF_R1	0	/* X0 */

/*
 * LDRH Wt, [Xn]  (Load Register Halfword, unsigned offset=0)
 *   01 111 0 01 01 imm12(0) Rn Rt
 *   = 0x79400000 | (Rn << 5) | Rt
 */
static inline u32 a64_ldrh(u8 rt, u8 rn)
{
	return 0x79400000U | ((u32)rn << 5) | (u32)rt;
}

/*
 * LDR Wt, [Xn]  (Load Register 32-bit, unsigned offset=0)
 *   10 111 0 01 01 imm12(0) Rn Rt
 *   = 0xB9400000 | (Rn << 5) | Rt
 */
static inline u32 a64_ldr_w(u8 rt, u8 rn)
{
	return 0xB9400000U | ((u32)rn << 5) | (u32)rt;
}

/*
 * LDR Xt, [Xn]  (Load Register 64-bit, unsigned offset=0)
 *   11 111 0 01 01 imm12(0) Rn Rt
 *   = 0xF9400000 | (Rn << 5) | Rt
 */
static inline u32 a64_ldr_x(u8 rt, u8 rn)
{
	return 0xF9400000U | ((u32)rn << 5) | (u32)rt;
}

/*
 * REV16 Wt, Wn  (Reverse bytes in 16-bit halfwords, 32-bit)
 *   0 1 01 1010 11 00000 00001 0 Rn Rd
 *   = 0x5AC00400 | (Rn << 5) | Rd
 */
static inline u32 a64_rev16_w(u8 rd, u8 rn)
{
	return 0x5AC00400U | ((u32)rn << 5) | (u32)rd;
}

/*
 * REV Wt, Wn  (Reverse bytes in 32-bit word)
 *   0 1 01 1010 11 00000 00010 0 Rn Rd
 *   = 0x5AC00800 | (Rn << 5) | Rd
 */
static inline u32 a64_rev_w(u8 rd, u8 rn)
{
	return 0x5AC00800U | ((u32)rn << 5) | (u32)rd;
}

/*
 * REV Xt, Xn  (Reverse bytes in 64-bit doubleword)
 *   1 1 01 1010 11 00000 00011 0 Rn Rd
 *   = 0xDAC00C00 | (Rn << 5) | Rd
 */
static inline u32 a64_rev_x(u8 rd, u8 rn)
{
	return 0xDAC00C00U | ((u32)rn << 5) | (u32)rd;
}

/*
 * AND Xt, Xn, #imm  (Logical immediate, 64-bit)
 * For #0xFFFF (16 bits set from bit 0):
 *   N=0, immr=0, imms=001111 (0xF)
 *   1 00 100100 N(0) immr(000000) imms(001111) Rn Rd
 *   = 0x92400000 | (0xF << 10) | (Rn << 5) | Rd
 */
static inline u32 a64_and_imm_0xffff(u8 rd, u8 rn)
{
	return 0x92400000U | (0xFU << 10) | ((u32)rn << 5) | (u32)rd;
}

/*
 * bpf_endian_load16: LDRH W7, [X0] + REV16 W7, W7 + AND X7, X7, #0xFFFF
 * 3 instructions, 12 bytes.
 */
static int emit_endian_load16_arm64(u32 *image, int *idx, bool emit,
				    const struct bpf_kinsn_call *call,
				    struct bpf_prog *prog)
{
	u32 insns[3];
	u8 dst = call->encoding == BPF_KINSN_ENC_PACKED_CALL ?
		 kinsn_arm64_reg(call->dst_reg) : ARM64_BPF_R0;
	u8 base = call->encoding == BPF_KINSN_ENC_PACKED_CALL ?
		  kinsn_arm64_reg(call->operands[0].regno) : ARM64_BPF_R1;

	if (!idx)
		return -EINVAL;

	(void)prog;
	if (dst == 0xff || base == 0xff)
		return -EINVAL;

	insns[0] = a64_ldrh(dst, base);
	insns[1] = a64_rev16_w(dst, dst);
	insns[2] = a64_and_imm_0xffff(dst, dst);

	if (emit) {
		int i;

		if (!image)
			return -EINVAL;
		for (i = 0; i < 3; i++)
			image[*idx + i] = cpu_to_le32(insns[i]);
	}

	*idx += 3;
	return 3;
}

/*
 * bpf_endian_load32: LDR W7, [X0] + REV W7, W7
 * 2 instructions, 8 bytes.
 */
static int emit_endian_load32_arm64(u32 *image, int *idx, bool emit,
				    const struct bpf_kinsn_call *call,
				    struct bpf_prog *prog)
{
	u32 insns[2];
	u8 dst = call->encoding == BPF_KINSN_ENC_PACKED_CALL ?
		 kinsn_arm64_reg(call->dst_reg) : ARM64_BPF_R0;
	u8 base = call->encoding == BPF_KINSN_ENC_PACKED_CALL ?
		  kinsn_arm64_reg(call->operands[0].regno) : ARM64_BPF_R1;

	if (!idx)
		return -EINVAL;

	(void)prog;
	if (dst == 0xff || base == 0xff)
		return -EINVAL;

	insns[0] = a64_ldr_w(dst, base);
	insns[1] = a64_rev_w(dst, dst);

	if (emit) {
		int i;

		if (!image)
			return -EINVAL;
		for (i = 0; i < 2; i++)
			image[*idx + i] = cpu_to_le32(insns[i]);
	}

	*idx += 2;
	return 2;
}

/*
 * bpf_endian_load64: LDR X7, [X0] + REV X7, X7
 * 2 instructions, 8 bytes.
 */
static int emit_endian_load64_arm64(u32 *image, int *idx, bool emit,
				    const struct bpf_kinsn_call *call,
				    struct bpf_prog *prog)
{
	u32 insns[2];
	u8 dst = call->encoding == BPF_KINSN_ENC_PACKED_CALL ?
		 kinsn_arm64_reg(call->dst_reg) : ARM64_BPF_R0;
	u8 base = call->encoding == BPF_KINSN_ENC_PACKED_CALL ?
		  kinsn_arm64_reg(call->operands[0].regno) : ARM64_BPF_R1;

	if (!idx)
		return -EINVAL;

	(void)prog;
	if (dst == 0xff || base == 0xff)
		return -EINVAL;

	insns[0] = a64_ldr_x(dst, base);
	insns[1] = a64_rev_x(dst, dst);

	if (emit) {
		int i;

		if (!image)
			return -EINVAL;
		for (i = 0; i < 2; i++)
			image[*idx + i] = cpu_to_le32(insns[i]);
	}

	*idx += 2;
	return 2;
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

static const struct bpf_kinsn_ops endian_load16_ops = {
	.owner = THIS_MODULE,
	.api_version = 1,
	.supported_encodings = BPF_KINSN_ENC_LEGACY_KFUNC |
			       BPF_KINSN_ENC_PACKED_CALL,
	.decode_call = decode_endian_call,
	.validate_call = validate_endian_call,
	.model_call = model_endian_load16_call,
	.emit_arm64 = emit_endian_load16_arm64,
	.max_emit_bytes = 16,
};

static const struct bpf_kinsn_ops endian_load32_ops = {
	.owner = THIS_MODULE,
	.api_version = 1,
	.supported_encodings = BPF_KINSN_ENC_LEGACY_KFUNC |
			       BPF_KINSN_ENC_PACKED_CALL,
	.decode_call = decode_endian_call,
	.validate_call = validate_endian_call,
	.model_call = model_endian_load32_call,
	.emit_arm64 = emit_endian_load32_arm64,
	.max_emit_bytes = 16,
};

static const struct bpf_kinsn_ops endian_load64_ops = {
	.owner = THIS_MODULE,
	.api_version = 1,
	.supported_encodings = BPF_KINSN_ENC_LEGACY_KFUNC |
			       BPF_KINSN_ENC_PACKED_CALL,
	.decode_call = decode_endian_call,
	.validate_call = validate_endian_call,
	.model_call = model_endian_load64_call,
	.emit_arm64 = emit_endian_load64_arm64,
	.max_emit_bytes = 16,
};

/* ---- module definition ---- */

static const struct kinsn_ops_entry endian_entries[] = {
	{ "bpf_endian_load16", &endian_load16_ops },
	{ "bpf_endian_load32", &endian_load32_ops },
	{ "bpf_endian_load64", &endian_load64_ops },
};

DEFINE_KINSN_MODULE_MULTI(bpf_endian, endian_entries,
			  "BpfReJIT kinsn: ENDIAN_LOAD (REV) inline kfunc for ARM64");
