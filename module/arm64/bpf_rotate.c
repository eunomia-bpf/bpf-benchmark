// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT kinsn: ROTATE — 64-bit rotate LEFT via RORV instruction (ARM64)
 *
 * Registers a kfunc bpf_rotate64(u64 val, u32 shift) with KF_KINSN.
 * Semantics: rotate val LEFT by shift bits — same as x86 ROL.
 * When inlined by the ARM64 JIT, computes (64 - shift) & 63 and uses RORV.
 *
 * BPF register -> ARM64 register mapping (from bpf_jit_comp.c bpf2a64[]):
 *   BPF_REG_0 = X7  (return value)
 *   BPF_REG_1 = X0  (arg1 = val)
 *   BPF_REG_2 = X1  (arg2 = shift)
 *   TMP_REG_1 = X10 (scratch)
 *
 * ARM64 has RORV (rotate right). ROL(val, S) == ROR(val, (64-S) & 63).
 *
 * Emitted ARM64 sequence (3 instructions, 12 bytes):
 *   NEG   W10, W1         ; W10 = -shift (= 64-shift mod 64 for bottom 6 bits)
 *   AND   W10, W10, #63   ; W10 = (-shift) & 63  (clean modular negate)
 *   RORV  X7, X0, X10     ; X7 = ROR(val, (64-shift)&63) = ROL(val, shift)
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

/* ---- ARM64 JIT emit callback ---- */

/*
 * ARM64 register IDs matching bpf2a64[] in bpf_jit_comp.c:
 *   BPF_REG_0 -> X7,  BPF_REG_1 -> X0,  BPF_REG_2 -> X1
 *   TMP_REG_1 -> X10  (scratch, safe to clobber)
 */
#define ARM64_BPF_R0	7	/* X7 */
#define ARM64_BPF_R1	0	/* X0 */
#define ARM64_BPF_R2	1	/* X1 */
#define ARM64_TMP	10	/* X10, TMP_REG_1 */

/*
 * Encode NEG Wd, Wm  (= SUB Wd, WZR, Wm, 32-bit)
 *   0 1 0 01011 00 0 Rm 000000 11111 Rd
 *   = 0x4B0003E0 | (Rm << 16) | Rd
 */
static inline u32 a64_neg_w(u8 rd, u8 rm)
{
	return 0x4B0003E0U | ((u32)rm << 16) | (u32)rd;
}

/*
 * Encode AND Wd, Wn, #63  (logical immediate, sf=0)
 *   0 00 100100 N(0) immr(000000) imms(000101) Rn Rd
 *   imms=5 encodes a mask of 0x3F (6 consecutive bits)
 *   = 0x12001400 | (Rn << 5) | Rd
 */
static inline u32 a64_and_w_imm63(u8 rd, u8 rn)
{
	return 0x12001400U | ((u32)rn << 5) | (u32)rd;
}

/*
 * Encode RORV Xd, Xn, Xm  (64-bit, Data Processing 2-source)
 *   31  30 29 28      21 20  16 15  10 9   5 4   0
 *   sf   0  0 11010110  Rm      001011 Rn    Rd
 *
 * sf=1 for 64-bit:  bit 31 = 1
 */
static inline u32 a64_rorv(u8 rd, u8 rn, u8 rm)
{
	return (1U << 31) |	/* sf = 1 (64-bit) */
	       (0x0D6U << 21) |	/* 0 0 11010110 */
	       ((u32)rm << 16) |
	       (0x0BU << 10) |	/* 001011 = RORV opcode */
	       ((u32)rn << 5) |
	       (u32)rd;
}

static inline u32 a64_extr_x(u8 rd, u8 rn, u8 rm, u8 lsb)
{
	return 0x93C00000U |
	       ((u32)rm << 16) |
	       ((u32)lsb << 10) |
	       ((u32)rn << 5) |
	       (u32)rd;
}

static int emit_rotate_arm64(u32 *image, int *idx, bool emit,
			     const struct bpf_kinsn_call *call,
			     struct bpf_prog *prog)
{
	/*
	 * Implement ROL(val, shift) as ROR(val, (64 - shift) & 63):
	 *   NEG  W10, W1        ; W10 = -shift (low 32 bits)
	 *   AND  W10, W10, #63  ; W10 = (-shift) & 63 = (64-shift) & 63
	 *   RORV X7, X0, X10    ; X7 = ROR(val, (64-shift)&63) = ROL(val, shift)
	 *
	 * 3 instructions, 12 bytes.
	 */
	u32 insns[3];

	if (!idx)
		return -EINVAL;

	(void)prog;

	if (call->encoding == BPF_KINSN_ENC_PACKED_CALL) {
		u8 dst = kinsn_arm64_reg(call->dst_reg);
		u8 src = kinsn_arm64_reg(call->operands[0].regno);
		u8 shift = call->operands[1].imm32 & 63;
		u8 ror = (-shift) & 63;
		u32 insn;

		if (dst == 0xff || src == 0xff)
			return -EINVAL;

		insn = a64_extr_x(dst, src, src, ror);
		if (emit) {
			if (!image)
				return -EINVAL;
			image[*idx] = cpu_to_le32(insn);
		}

		*idx += 1;
		return 1;
	}

	insns[0] = a64_neg_w(ARM64_TMP, ARM64_BPF_R2);
	insns[1] = a64_and_w_imm63(ARM64_TMP, ARM64_TMP);
	insns[2] = a64_rorv(ARM64_BPF_R0, ARM64_BPF_R1, ARM64_TMP);

	if (emit) {
		int i;

		if (!image)
			return -EINVAL;
		for (i = 0; i < 3; i++)
			image[*idx + i] = cpu_to_le32(insns[i]);
	}

	*idx += 3;
	return 3;	/* 3 instructions emitted */
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
		effect->clobber_mask = BIT(BPF_REG_0);
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
	.emit_arm64 = emit_rotate_arm64,
	.max_emit_bytes = 16,
};

/* ---- module definition ---- */

DEFINE_KINSN_MODULE(bpf_rotate, "bpf_rotate64", &rotate_ops,
		    "BpfReJIT kinsn: ROTATE (ROL via RORV) inline kfunc for ARM64");
