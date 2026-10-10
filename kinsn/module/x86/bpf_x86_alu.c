// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT x86 kinsn: immediate ALU instructions.
 */

#include "kinsn_x86_emit.h"

__bpf_kfunc_start_defs();
__bpf_kfunc void bpf_x86_addb(void) {}
__bpf_kfunc void bpf_x86_andb(void) {}
__bpf_kfunc void bpf_x86_andq(void) {}
__bpf_kfunc void bpf_x86_andl(void) {}
__bpf_kfunc void bpf_x86_divl(void) {}
__bpf_kfunc void bpf_x86_incb(void) {}
__bpf_kfunc void bpf_x86_incl(void) {}
__bpf_kfunc void bpf_x86_incq(void) {}
__bpf_kfunc void bpf_x86_xorb(void) {}
__bpf_kfunc void bpf_x86_xorw(void) {}
__bpf_kfunc void bpf_x86_orb(void) {}
__bpf_kfunc void bpf_x86_orw(void) {}
__bpf_kfunc void bpf_x86_addq(void) {}
__bpf_kfunc void bpf_x86_addl(void) {}
__bpf_kfunc void bpf_x86_subb(void) {}
__bpf_kfunc void bpf_x86_subq(void) {}
__bpf_kfunc void bpf_x86_subl(void) {}
__bpf_kfunc void bpf_x86_xorq(void) {}
__bpf_kfunc void bpf_x86_xorl(void) {}
__bpf_kfunc void bpf_x86_orq(void) {}
__bpf_kfunc void bpf_x86_orl(void) {}
__bpf_kfunc void bpf_x86_shlq(void) {}
__bpf_kfunc void bpf_x86_shll(void) {}
__bpf_kfunc void bpf_x86_shlb(void) {}
__bpf_kfunc void bpf_x86_shrb(void) {}
__bpf_kfunc void bpf_x86_shrq(void) {}
__bpf_kfunc void bpf_x86_shrl(void) {}
__bpf_kfunc void bpf_x86_sarq(void) {}
__bpf_kfunc void bpf_x86_sarl(void) {}
__bpf_kfunc_end_defs();

BTF_KFUNCS_START(bpf_x86_alu_kfunc_ids)
BTF_ID_FLAGS(func, bpf_x86_addb)
BTF_ID_FLAGS(func, bpf_x86_addl)
BTF_ID_FLAGS(func, bpf_x86_addq)
BTF_ID_FLAGS(func, bpf_x86_andb)
BTF_ID_FLAGS(func, bpf_x86_andl)
BTF_ID_FLAGS(func, bpf_x86_andq)
BTF_ID_FLAGS(func, bpf_x86_divl)
BTF_ID_FLAGS(func, bpf_x86_incb)
BTF_ID_FLAGS(func, bpf_x86_incl)
BTF_ID_FLAGS(func, bpf_x86_incq)
BTF_ID_FLAGS(func, bpf_x86_orb)
BTF_ID_FLAGS(func, bpf_x86_orl)
BTF_ID_FLAGS(func, bpf_x86_orq)
BTF_ID_FLAGS(func, bpf_x86_orw)
BTF_ID_FLAGS(func, bpf_x86_sarl)
BTF_ID_FLAGS(func, bpf_x86_sarq)
BTF_ID_FLAGS(func, bpf_x86_shlb)
BTF_ID_FLAGS(func, bpf_x86_shll)
BTF_ID_FLAGS(func, bpf_x86_shlq)
BTF_ID_FLAGS(func, bpf_x86_shrb)
BTF_ID_FLAGS(func, bpf_x86_shrl)
BTF_ID_FLAGS(func, bpf_x86_shrq)
BTF_ID_FLAGS(func, bpf_x86_subb)
BTF_ID_FLAGS(func, bpf_x86_subl)
BTF_ID_FLAGS(func, bpf_x86_subq)
BTF_ID_FLAGS(func, bpf_x86_xorb)
BTF_ID_FLAGS(func, bpf_x86_xorl)
BTF_ID_FLAGS(func, bpf_x86_xorq)
BTF_ID_FLAGS(func, bpf_x86_xorw)
BTF_KFUNCS_END(bpf_x86_alu_kfunc_ids)

#define KINSN_X86_ALU_FORM_RR		1
#define KINSN_X86_ALU_FORM_IMM		2
#define KINSN_X86_ALU_FORM_MEM		4
#define KINSN_X86_ALU_FORM_SIB		5
#define KINSN_X86_ALU_FORM_ARCH_MEM	9
#define KINSN_X86_ALU_FORM_ARCH_RR	12
#define KINSN_X86_ALU_FORM_ARCH_IMM	13
#define KINSN_X86_ALU_FORM_ARCH_SIB	14

struct kinsn_x86_alu_payload {
	u8 form;
	u8 dst_reg;
	u8 src_reg;
	u8 base_reg;
	u8 index_reg;
	u8 scale_log2;
	s32 imm;
	s16 offset;
};

/*
 * One kinsn name covers one x86 mnemonic+width, while this payload describes
 * the operand form. Register/immediate forms write only dst. Memory forms
 * declare a second output, data_reg: the lowest writable BPF register not
 * equal to dst, base, or the active index. Both proof and native leave the
 * zero-extended loaded operand in data_reg. There is no hidden scratch state.
 */
static __always_inline int decode_x86_alu_payload(u64 payload,
						  struct kinsn_x86_alu_payload *alu)
{
	payload = kinsn_payload_decode(payload);
	alu->form = payload & 0xf;

	if (alu->form == KINSN_X86_ALU_FORM_RR ||
	    alu->form == KINSN_X86_ALU_FORM_ARCH_RR) {
		alu->dst_reg = (payload >> 4) & 0xf;
		alu->src_reg = (payload >> 8) & 0xf;
		if (payload >> 12)
			return -EINVAL;
		if (!kinsn_x86_reg_is_bpf_writable(alu->dst_reg) ||
		    !kinsn_x86_operand_valid(alu->src_reg))
			return -EINVAL;
		return 0;
	}

	if (alu->form == KINSN_X86_ALU_FORM_IMM ||
	    alu->form == KINSN_X86_ALU_FORM_ARCH_IMM) {
		alu->dst_reg = (payload >> 4) & 0xf;
		alu->src_reg = 0;
		alu->imm = (s32)((u32)(payload >> 8));
		if (payload >> 40)
			return -EINVAL;
		if (!kinsn_x86_reg_is_bpf_writable(alu->dst_reg))
			return -EINVAL;
		return 0;
	}

	if (alu->form == KINSN_X86_ALU_FORM_MEM ||
	    alu->form == KINSN_X86_ALU_FORM_ARCH_MEM) {
		alu->dst_reg = kinsn_payload_reg(payload, 4);
		alu->base_reg = kinsn_payload_reg(payload, 8);
		alu->offset = kinsn_payload_s16(payload, 12);
		if (payload >> 28)
			return -EINVAL;
		if (!kinsn_x86_reg_is_bpf_writable(alu->dst_reg) ||
		    !kinsn_x86_operand_valid(alu->base_reg))
			return -EINVAL;
		return 0;
	}

	if (alu->form == KINSN_X86_ALU_FORM_SIB ||
	    alu->form == KINSN_X86_ALU_FORM_ARCH_SIB) {
		alu->dst_reg = kinsn_payload_reg(payload, 4);
		alu->base_reg = kinsn_payload_reg(payload, 8);
		alu->index_reg = kinsn_payload_reg(payload, 12);
		alu->scale_log2 = (payload >> 16) & 0x3;
		alu->offset = kinsn_payload_s16(payload, 20);
		if (payload >> 36)
			return -EINVAL;
		if (payload & (0x3ULL << 18))
			return -EINVAL;
		if (!kinsn_x86_reg_is_bpf_writable(alu->dst_reg) ||
		    !kinsn_x86_operand_valid(alu->base_reg) ||
		    !kinsn_x86_operand_valid(alu->index_reg))
			return -EINVAL;
		return 0;
	}

	return -EINVAL;
}

static __always_inline bool x86_alu_is_shift(u8 op)
{
	return op == BPF_LSH || op == BPF_RSH || op == BPF_ARSH;
}

static __always_inline bool x86_alu_uses_arch_reg(u8 form)
{
	return form == KINSN_X86_ALU_FORM_ARCH_RR ||
	       form == KINSN_X86_ALU_FORM_ARCH_IMM;
}

static __always_inline int emit_bpf_alu_reg(struct bpf_insn *insn, u8 op,
					    u8 width, u8 dst_reg, u8 src_reg)
{
	if (width == 64)
		*insn = BPF_ALU64_REG(op, dst_reg, src_reg);
	else if (width == 32)
		*insn = BPF_ALU32_REG(op, dst_reg, src_reg);
	else
		return -EINVAL;
	return 0;
}

static __always_inline int emit_bpf_alu_imm(struct bpf_insn *insn, u8 op,
					    u8 width, u8 dst_reg, s32 imm)
{
	if (width == 64)
		*insn = BPF_ALU64_IMM(op, dst_reg, imm);
	else if (width == 32)
		*insn = BPF_ALU32_IMM(op, dst_reg, imm);
	else
		return -EINVAL;
	return 0;
}

/* The memory form's declared data output. Its final value, unlike a borrowed
 * temporary, is visible to both the verifier and the native caller. */
static int x86_alu_data_output(const struct kinsn_x86_alu_payload *alu)
{
	bool indexed = alu->form == KINSN_X86_ALU_FORM_SIB ||
		       alu->form == KINSN_X86_ALU_FORM_ARCH_SIB;
	u8 reg;

	for (reg = BPF_REG_0; reg < BPF_REG_10; reg++) {
		if (reg != alu->dst_reg && reg != alu->base_reg &&
		    (!indexed || reg != alu->index_reg))
			return reg;
	}
	return -EINVAL;
}

static int instantiate_x86_alu_mem(const struct kinsn_x86_alu_payload *alu,
				  struct bpf_insn *insn_buf, u8 op, u8 width)
{
	bool indexed = alu->form == KINSN_X86_ALU_FORM_SIB ||
		       alu->form == KINSN_X86_ALU_FORM_ARCH_SIB;
	int temp;
	int cnt = 0;
	int i;
	int err;

	if (width != 8 && width != 16 && width != 32 && width != 64)
		return -EINVAL;
	temp = x86_alu_data_output(alu);
	if (temp < 0)
		return temp;
	insn_buf[cnt++] = BPF_MOV64_REG(temp, alu->base_reg);
	if (indexed) {
		for (i = 0; i < (1U << alu->scale_log2); i++)
			insn_buf[cnt++] = BPF_ALU64_REG(BPF_ADD, temp, alu->index_reg);
	}
	insn_buf[cnt++] = BPF_LDX_MEM(width == 64 ? BPF_DW : width == 32 ? BPF_W :
				    width == 16 ? BPF_H : BPF_B,
				    temp, temp, alu->offset);
	err = emit_bpf_alu_reg(&insn_buf[cnt++], op, width < 32 ? 64 : width,
			       alu->dst_reg, temp);
	if (err)
		return err;
	return cnt;
}

static int instantiate_x86_shift(const struct kinsn_x86_alu_payload *alu,
				  struct bpf_insn *insn_buf, u8 op, u8 width)
{
	int err;

	if (alu->form == KINSN_X86_ALU_FORM_RR ||
	    alu->form == KINSN_X86_ALU_FORM_ARCH_RR) {
		if (alu->src_reg != BPF_REG_4)
			return -EINVAL;
		err = emit_bpf_alu_reg(&insn_buf[0], op, width, alu->dst_reg,
				       alu->src_reg);
	} else if (alu->form == KINSN_X86_ALU_FORM_IMM ||
		   alu->form == KINSN_X86_ALU_FORM_ARCH_IMM) {
		if (alu->imm < 0 || alu->imm >= width)
			return -EINVAL;
		err = emit_bpf_alu_imm(&insn_buf[0], op, width, alu->dst_reg,
				       alu->imm);
	} else {
		/* Memory-source shifts have never had a native emitter. */
		return -EINVAL;
	}
	return err ? err : 1;
}

static int instantiate_x86_alu(u64 payload, struct bpf_insn *insn_buf,
			       u8 op, u8 width)
{
	struct kinsn_x86_alu_payload alu;
	int err;

	err = decode_x86_alu_payload(payload, &alu);
	if (err)
		return err;
	if (x86_alu_is_shift(op))
		return instantiate_x86_shift(&alu, insn_buf, op, width);
	if (alu.form == KINSN_X86_ALU_FORM_MEM ||
	    alu.form == KINSN_X86_ALU_FORM_ARCH_MEM ||
	    alu.form == KINSN_X86_ALU_FORM_SIB ||
	    alu.form == KINSN_X86_ALU_FORM_ARCH_SIB)
		return instantiate_x86_alu_mem(&alu, insn_buf, op, width);
	if (alu.form == KINSN_X86_ALU_FORM_RR ||
	    alu.form == KINSN_X86_ALU_FORM_ARCH_RR)
		err = emit_bpf_alu_reg(&insn_buf[0], op, width, alu.dst_reg, alu.src_reg);
	else
		err = emit_bpf_alu_imm(&insn_buf[0], op, width, alu.dst_reg, alu.imm);
	return err ? err : 1;
}

/* Register logic on a narrow destination can be expressed by independent
 * source-bit tests. This preserves every other register and all upper bits,
 * including self operands, without any scratch slot contract.
 */
static int instantiate_x86_logic_narrow(const struct kinsn_x86_alu_payload *alu,
				        struct bpf_insn *insn_buf, u8 op, u8 width)
{
	u32 low_mask = (1U << width) - 1;
	u32 mask;
	int bit;
	int cnt = 0;

	if (alu->form == KINSN_X86_ALU_FORM_IMM ||
	    alu->form == KINSN_X86_ALU_FORM_ARCH_IMM) {
		if (alu->imm < 0 || alu->imm > low_mask)
			return -EINVAL;
		insn_buf[cnt++] = BPF_ALU64_IMM(op, alu->dst_reg,
				 op == BPF_AND ? alu->imm | ~low_mask : alu->imm);
		return cnt;
	}

	for (bit = 0; bit < width; bit++) {
		mask = 1U << bit;
		insn_buf[cnt++] = BPF_JMP_IMM(BPF_JSET, alu->src_reg, mask, 1);
		if (op == BPF_AND) {
			insn_buf[cnt++] = BPF_ALU64_IMM(BPF_AND, alu->dst_reg, ~mask);
		} else {
			insn_buf[cnt++] = BPF_JMP_A(1);
			insn_buf[cnt++] = BPF_ALU64_IMM(BPF_OR, alu->dst_reg, mask);
		}
	}
	return cnt;
}

static int x86_alu_narrow_temp(const struct kinsn_x86_alu_payload *alu)
{
	bool reg_src = alu->form == KINSN_X86_ALU_FORM_RR ||
		       alu->form == KINSN_X86_ALU_FORM_ARCH_RR;
	u8 reg;

	for (reg = BPF_REG_0; reg < BPF_REG_10; reg++) {
		if (reg != alu->dst_reg && (!reg_src || reg != alu->src_reg))
			return reg;
	}
	return -EINVAL;
}

/* Decode the original byte entirely in control flow before writing dst.
 * Each leaf replaces only that byte; all other registers and memory survive. */
static int instantiate_narrow_byte_tree(u8 dst, struct bpf_insn *insn_buf,
				       u8 op, u8 depth, u8 value, u8 count)
{
	int cnt = 0;
	int branch;
	int join;
	u8 shifted;

	if (!depth) {
		shifted = op == BPF_LSH ? value << count : value >> count;
		insn_buf[0] = BPF_ALU64_IMM(BPF_AND, dst, -256);
		insn_buf[1] = BPF_ALU64_IMM(BPF_OR, dst, shifted);
		return 2;
	}
	branch = cnt++;
	cnt += instantiate_narrow_byte_tree(dst, insn_buf + cnt, op, depth - 1, value, count);
	join = cnt++;
	insn_buf[branch] = BPF_JMP_IMM(BPF_JSET, dst, 1U << (depth - 1), cnt - branch - 1);
	cnt += instantiate_narrow_byte_tree(dst, insn_buf + cnt, op, depth - 1,
					   value + (1U << (depth - 1)), count);
	insn_buf[join] = BPF_JMP_A(cnt - join - 1);
	return cnt;
}

static int instantiate_narrow_shift_leaf(const struct kinsn_x86_alu_payload *alu,
					struct bpf_insn *insn_buf, u8 op,
					u8 count)
{
	if (!count) {
		insn_buf[0] = BPF_JMP_A(0);
		return 1;
	}
	if (count >= 8) {
		insn_buf[0] = BPF_ALU64_IMM(BPF_AND, alu->dst_reg, -256);
		return 1;
	}
	return instantiate_narrow_byte_tree(alu->dst_reg, insn_buf, op, 8, 0, count);
}

/* Capture all five CL count bits before the chosen leaf writes dst, including
 * dst=CL. Neither dispatch borrows a register or stack slot.
 */
static int instantiate_narrow_shift_tree(const struct kinsn_x86_alu_payload *alu,
					struct bpf_insn *insn_buf, u8 op,
					u8 depth, u8 base)
{
	int cnt = 0;
	int branch;
	int join;

	if (!depth)
		return instantiate_narrow_shift_leaf(alu, insn_buf, op, base);
	branch = cnt++;
	cnt += instantiate_narrow_shift_tree(alu, insn_buf + cnt, op,
					    depth - 1, base);
	join = cnt++;
	insn_buf[branch] = BPF_JMP_IMM(BPF_JSET, BPF_REG_4,
				      1U << (depth - 1), cnt - branch - 1);
	cnt += instantiate_narrow_shift_tree(alu, insn_buf + cnt, op,
					    depth - 1, base + (1U << (depth - 1)));
	insn_buf[join] = BPF_JMP_A(cnt - join - 1);
	return cnt;
}

static int instantiate_x86_alu_narrow(u64 payload, struct bpf_insn *insn_buf,
				      u8 op, u8 width)
{
	struct kinsn_x86_alu_payload alu;
	bool reg_src;
	int temp;
	int cnt = 0;
	int err;

	err = decode_x86_alu_payload(payload, &alu);
	if (err)
		return err;
	if (width != 8 && width != 16)
		return -EINVAL;
	reg_src = alu.form == KINSN_X86_ALU_FORM_RR ||
		  alu.form == KINSN_X86_ALU_FORM_ARCH_RR;
	if (!reg_src && alu.form != KINSN_X86_ALU_FORM_IMM &&
	    alu.form != KINSN_X86_ALU_FORM_ARCH_IMM)
		return -EINVAL;
	if (op == BPF_AND || op == BPF_OR)
		return instantiate_x86_logic_narrow(&alu, insn_buf, op, width);
	if (x86_alu_is_shift(op)) {
		if ((reg_src && alu.src_reg != BPF_REG_4) ||
		    (!reg_src && (alu.imm < 0 || alu.imm >= 32)))
			return -EINVAL;
	} else if (!reg_src && (alu.imm < 0 || alu.imm >= (1U << width))) {
		return -EINVAL;
	}
	if (x86_alu_is_shift(op)) {
		if (reg_src)
			return instantiate_narrow_shift_tree(&alu, insn_buf, op, 5, 0);
		return instantiate_narrow_shift_leaf(&alu, insn_buf, op, alu.imm);
	}
	temp = x86_alu_narrow_temp(&alu);
	if (temp < 0)
		return temp;
	insn_buf[cnt++] = BPF_STX_MEM(BPF_DW, BPF_REG_10, temp, KINSN_X86_PROOF_RHS_OFF);
	insn_buf[cnt++] = BPF_MOV64_REG(temp, alu.dst_reg);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_AND, temp, -(1U << width));
	if (reg_src)
		err = emit_bpf_alu_reg(&insn_buf[cnt++], op, 64, alu.dst_reg, alu.src_reg);
	else
		err = emit_bpf_alu_imm(&insn_buf[cnt++], op, 64, alu.dst_reg, alu.imm);
	if (err)
		return err;
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_AND, alu.dst_reg, (1U << width) - 1);
	insn_buf[cnt++] = BPF_ALU64_REG(BPF_OR, alu.dst_reg, temp);
	insn_buf[cnt++] = BPF_LDX_MEM(BPF_DW, temp, BPF_REG_10, KINSN_X86_PROOF_RHS_OFF);
	return cnt;
}

static int instantiate_inc(u64 payload, struct bpf_insn *insn_buf, u8 width)
{
	struct kinsn_x86_alu_payload decoded;
	u8 dst_reg;
	int err;

	err = decode_x86_alu_payload(payload, &decoded);
	if (err)
		return err;
	if ((decoded.form != KINSN_X86_ALU_FORM_IMM &&
	     decoded.form != KINSN_X86_ALU_FORM_ARCH_IMM) ||
	    decoded.imm != 0)
		return -EINVAL;
	if (width != 8 && width != 32 && width != 64)
		return -EINVAL;

	dst_reg = decoded.dst_reg;
	insn_buf[0] = width == 32 ?
		BPF_ALU32_IMM(BPF_ADD, dst_reg, 1) :
		BPF_ALU64_IMM(BPF_ADD, dst_reg, 1);
	if (width == 8) {
		/* Undo the carry into bits 63:8 only when the low byte wraps. */
		insn_buf[1] = BPF_JMP_IMM(BPF_JSET, dst_reg, 0xff, 1);
		insn_buf[2] = BPF_ALU64_IMM(BPF_ADD, dst_reg, -256);
		return 3;
	}
	return 1;
}

static int instantiate_incb(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_inc(payload, insn_buf, 8);
}

static int instantiate_incl(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_inc(payload, insn_buf, 32);
}

static int instantiate_incq(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_inc(payload, insn_buf, 64);
}

/* DIVL's payload register is a read-only divisor, including R10. */
static int decode_divl_payload(u64 payload, u8 *src_reg)
{
	u8 form;

	payload = kinsn_payload_decode(payload);
	form = payload & 0xf;
	if (form != KINSN_X86_ALU_FORM_IMM && form != KINSN_X86_ALU_FORM_ARCH_IMM)
		return -EINVAL;
	*src_reg = kinsn_payload_reg(payload, 4);
	if (payload >> 8 || !kinsn_x86_operand_valid(*src_reg))
		return -EINVAL;
	return 0;
}

static int divl_temps(u8 src_reg, u8 *num, u8 *divisor)
{
	u8 reg;
	int found = 0;

	for (reg = BPF_REG_0; reg < BPF_REG_10; reg++) {
		if (reg == BPF_REG_0 || reg == BPF_REG_3 || reg == src_reg)
			continue;
		if (!found++)
			*num = reg;
		else {
			*divisor = reg;
			return 0;
		}
	}
	return -EINVAL;
}

static int instantiate_divl(u64 payload, struct bpf_insn *insn_buf)
{
	u8 src_reg, num, divisor;
	int cnt = 0;
	int err;

	err = decode_divl_payload(payload, &src_reg);
	if (err)
		return err;
	err = divl_temps(src_reg, &num, &divisor);
	if (err)
		return err;

	insn_buf[cnt++] = BPF_STX_MEM(BPF_DW, BPF_REG_10, num, KINSN_X86_PROOF_LHS_OFF);
	insn_buf[cnt++] = BPF_STX_MEM(BPF_DW, BPF_REG_10, divisor, KINSN_X86_PROOF_RHS_OFF);
	/* Capture divisor before writing either implicit input, even src=R0/R3. */
	insn_buf[cnt++] = BPF_MOV32_REG(divisor, src_reg);
	insn_buf[cnt++] = BPF_MOV32_REG(num, BPF_REG_3);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_LSH, num, 32);
	insn_buf[cnt++] = BPF_MOV32_REG(BPF_REG_0, BPF_REG_0);
	insn_buf[cnt++] = BPF_ALU64_REG(BPF_OR, num, BPF_REG_0);
	insn_buf[cnt++] = BPF_MOV64_REG(BPF_REG_0, num);
	insn_buf[cnt++] = BPF_MOV64_REG(BPF_REG_3, num);
	insn_buf[cnt++] = BPF_ALU64_REG(BPF_MOD, BPF_REG_3, divisor);
	insn_buf[cnt++] = BPF_ALU64_REG(BPF_DIV, BPF_REG_0, divisor);
	insn_buf[cnt++] = BPF_MOV32_REG(BPF_REG_0, BPF_REG_0);
	insn_buf[cnt++] = BPF_MOV32_REG(BPF_REG_3, BPF_REG_3);
	insn_buf[cnt++] = BPF_LDX_MEM(BPF_DW, divisor, BPF_REG_10, KINSN_X86_PROOF_RHS_OFF);
	insn_buf[cnt++] = BPF_LDX_MEM(BPF_DW, num, BPF_REG_10, KINSN_X86_PROOF_LHS_OFF);
	return cnt;
}

static int instantiate_xorb(u64 payload, struct bpf_insn *insn_buf)
{
	struct kinsn_x86_alu_payload decoded;
	int err;

	err = decode_x86_alu_payload(payload, &decoded);
	if (err)
		return err;
	switch (decoded.form) {
	case KINSN_X86_ALU_FORM_IMM:
	case KINSN_X86_ALU_FORM_ARCH_IMM:
		return instantiate_x86_alu_narrow(payload, insn_buf, BPF_XOR, 8);
	case KINSN_X86_ALU_FORM_RR:
	case KINSN_X86_ALU_FORM_ARCH_RR:
		return instantiate_x86_alu_narrow(payload, insn_buf, BPF_XOR, 8);
	case KINSN_X86_ALU_FORM_SIB:
	case KINSN_X86_ALU_FORM_ARCH_SIB:
		return instantiate_x86_alu_mem(&decoded, insn_buf, BPF_XOR, 8);
	default:
		return -EINVAL;
	}
}

static int instantiate_xorw(u64 payload, struct bpf_insn *insn_buf)
{
	struct kinsn_x86_alu_payload decoded;
	int err;

	err = decode_x86_alu_payload(payload, &decoded);
	if (err)
		return err;
	if (decoded.form != KINSN_X86_ALU_FORM_MEM &&
	    decoded.form != KINSN_X86_ALU_FORM_ARCH_MEM)
		return -EINVAL;
	return instantiate_x86_alu_mem(&decoded, insn_buf, BPF_XOR, 16);
}

static void emit_alu_temp_slot(u8 *buf, u32 *len, u8 temp, u8 frame, bool load)
{
	kinsn_emit_rex(buf, len, true, kinsn_x86_ext(temp), false, kinsn_x86_ext(frame));
	kinsn_emit_u8(buf, len, load ? 0x8b : 0x89);
	kinsn_emit_modrm_mem(buf, len, temp, frame, KINSN_X86_PROOF_RHS_OFF);
}

/* One operand read into the declared data output, followed by register ALU.
 * No program-stack access is part of this operation. */
static int emit_alu_data_x86(u8 *image, u32 *off, bool emit,
			     const struct kinsn_x86_alu_payload *alu,
			     const struct bpf_prog *prog, u8 width,
			     u8 opcode, bool indexed)
{
	u8 buf[24];
	u8 dst, base, index = 0, data;
	u32 len = 0;
	int out;

	out = x86_alu_data_output(alu);
	if (out < 0)
		return out;
	data = kinsn_x86_reg_for_prog(prog, out);
	dst = kinsn_x86_reg_for_prog(prog, alu->dst_reg);
	base = kinsn_x86_reg_for_prog(prog, alu->base_reg);
	if (indexed)
		index = kinsn_x86_reg_for_prog(prog, alu->index_reg);
	kinsn_emit_rex(buf, &len, width == 64, kinsn_x86_ext(data),
		       indexed && kinsn_x86_ext(index), kinsn_x86_ext(base));
	if (width < 32) {
		kinsn_emit_u8(buf, &len, 0x0f);
		kinsn_emit_u8(buf, &len, width == 8 ? 0xb6 : 0xb7);
	} else {
		kinsn_emit_u8(buf, &len, 0x8b);
	}
	if (indexed)
		kinsn_emit_sib_mem(buf, &len, data, base, index, alu->scale_log2, alu->offset);
	else
		kinsn_emit_modrm_mem(buf, &len, data, base, alu->offset);
	kinsn_emit_rex_rr(buf, &len, width != 32, dst, data);
	kinsn_emit_u8(buf, &len, opcode);
	kinsn_emit_u8(buf, &len, 0xc0 | (kinsn_x86_code(dst) << 3) | kinsn_x86_code(data));
	return kinsn_emit_finish(image, off, emit, buf, len);
}

static int emit_alu_mem_x86(u8 *image, u32 *off, bool emit,
			    const struct kinsn_x86_alu_payload *alu,
			    const struct bpf_prog *prog, u8 width,
			    u8 opcode)
{
	return emit_alu_data_x86(image, off, emit, alu, prog,
				 width, opcode, false);
}

static int emit_alu_sib_x86(u8 *image, u32 *off, bool emit,
			    const struct kinsn_x86_alu_payload *alu,
			    const struct bpf_prog *prog, u8 width, u8 opcode)
{
	return emit_alu_data_x86(image, off, emit, alu, prog, width, opcode, true);
}

static int emit_x86_alu(u8 *image, u32 *off, bool emit, u64 payload,
			const struct bpf_prog *prog, u8 width, u8 op,
			u8 rr_opcode, u8 imm_group)
{
	struct kinsn_x86_alu_payload decoded;
	const struct kinsn_x86_alu_payload *alu = &decoded;
	u8 buf[8];
	u8 dst_reg, src_reg;
	u32 len = 0;
	int err;

	err = decode_x86_alu_payload(payload, &decoded);
	if (err)
		return err;

	if (alu->form == KINSN_X86_ALU_FORM_MEM ||
	    alu->form == KINSN_X86_ALU_FORM_ARCH_MEM) {
		if (x86_alu_is_shift(op))
			return -EINVAL;
		return emit_alu_mem_x86(image, off, emit, alu, prog, width,
					rr_opcode | 0x02);
	}

	if (alu->form == KINSN_X86_ALU_FORM_SIB ||
	    alu->form == KINSN_X86_ALU_FORM_ARCH_SIB) {
		if (x86_alu_is_shift(op))
			return -EINVAL;
		return emit_alu_sib_x86(image, off, emit, alu, prog, width,
					rr_opcode | 0x02);
	}

	dst_reg = kinsn_x86_reg_for_prog(prog, alu->dst_reg);
	if (!kinsn_x86_valid(dst_reg))
		return -EINVAL;

	if (alu->form == KINSN_X86_ALU_FORM_RR ||
	    alu->form == KINSN_X86_ALU_FORM_ARCH_RR) {
		if (x86_alu_is_shift(op)) {
			if (alu->src_reg != BPF_REG_4)
				return -EINVAL;
			kinsn_emit_rex_rr(buf, &len, width == 64, 0, dst_reg);
			kinsn_emit_u8(buf, &len, 0xd3);
			kinsn_emit_u8(buf, &len, 0xc0 | (imm_group << 3) |
				      kinsn_x86_code(dst_reg));
			return kinsn_emit_finish(image, off, emit, buf, len);
		}
		src_reg = kinsn_x86_reg_for_prog(prog, alu->src_reg);
		if (!kinsn_x86_valid(src_reg))
			return -EINVAL;
		kinsn_emit_rex_rr(buf, &len, width == 64, src_reg, dst_reg);
		kinsn_emit_u8(buf, &len, rr_opcode);
		kinsn_emit_u8(buf, &len, 0xc0 |
			      (kinsn_x86_code(src_reg) << 3) |
			      kinsn_x86_code(dst_reg));
	} else {
		if (x86_alu_is_shift(op)) {
			if (alu->imm < 0 || alu->imm >= width)
				return -EINVAL;
			kinsn_emit_rex_rr(buf, &len, width == 64, 0, dst_reg);
			kinsn_emit_u8(buf, &len, 0xc1);
			kinsn_emit_u8(buf, &len, 0xc0 | (imm_group << 3) |
				      kinsn_x86_code(dst_reg));
			kinsn_emit_u8(buf, &len, (u8)alu->imm);
		} else if (alu->imm >= S8_MIN && alu->imm <= S8_MAX) {
			kinsn_emit_rex_rr(buf, &len, width == 64, 0, dst_reg);
			kinsn_emit_u8(buf, &len, 0x83);
			kinsn_emit_u8(buf, &len, 0xc0 | (imm_group << 3) |
				      kinsn_x86_code(dst_reg));
			kinsn_emit_u8(buf, &len, (u8)alu->imm);
		} else {
			kinsn_emit_rex_rr(buf, &len, width == 64, 0, dst_reg);
			kinsn_emit_u8(buf, &len, 0x81);
			kinsn_emit_u8(buf, &len, 0xc0 | (imm_group << 3) |
				      kinsn_x86_code(dst_reg));
			kinsn_emit_s32(buf, &len, alu->imm);
		}
	}

	return kinsn_emit_finish(image, off, emit, buf, len);
}

static int emit_x86_alu_narrow(u8 *image, u32 *off, bool emit, u64 payload,
			       const struct bpf_prog *prog, u8 width, u8 op,
			       u8 rr_opcode, u8 imm_group)
{
	struct kinsn_x86_alu_payload decoded;
	const struct kinsn_x86_alu_payload *alu = &decoded;
	u8 buf[24];
	u8 dst_reg, src_reg;
	int temp = -1;
	u8 frame = kinsn_x86_reg_for_prog(prog, BPF_REG_10);
	u32 len = 0;
	int err;

	err = decode_x86_alu_payload(payload, &decoded);
	if (err)
		return err;
	if (width != 8 && width != 16)
		return -EINVAL;
	if (alu->form != KINSN_X86_ALU_FORM_RR &&
	    alu->form != KINSN_X86_ALU_FORM_ARCH_RR &&
	    alu->form != KINSN_X86_ALU_FORM_IMM &&
	    alu->form != KINSN_X86_ALU_FORM_ARCH_IMM)
		return -EINVAL;

	dst_reg = kinsn_x86_reg_for_prog(prog, alu->dst_reg);
	if (!kinsn_x86_valid(dst_reg))
		return -EINVAL;

	if (op != BPF_AND && op != BPF_OR && !x86_alu_is_shift(op)) {
		temp = x86_alu_narrow_temp(alu);
		if (temp < 0)
			return temp;
		emit_alu_temp_slot(buf, &len, kinsn_x86_reg_for_prog(prog, temp), frame, false);
	}

	if (width == 16)
		kinsn_emit_u8(buf, &len, 0x66);

	if (alu->form == KINSN_X86_ALU_FORM_RR ||
	    alu->form == KINSN_X86_ALU_FORM_ARCH_RR) {
		if (x86_alu_is_shift(op)) {
			if (alu->src_reg != BPF_REG_4)
				return -EINVAL;
			if (width == 8) {
				kinsn_emit_rex8_rm(buf, &len, dst_reg);
				kinsn_emit_u8(buf, &len, 0xd2);
			} else {
				kinsn_emit_rex_rr(buf, &len, false, 0,
						  dst_reg);
				kinsn_emit_u8(buf, &len, 0xd3);
			}
			kinsn_emit_u8(buf, &len, 0xc0 | (imm_group << 3) |
				      kinsn_x86_code(dst_reg));
			goto finish;
		}
		src_reg = kinsn_x86_reg_for_prog(prog, alu->src_reg);
		if (!kinsn_x86_valid(src_reg))
			return -EINVAL;
		if (width == 8)
			kinsn_emit_rex8_rr(buf, &len, src_reg, dst_reg);
		else
			kinsn_emit_rex_rr(buf, &len, false, src_reg, dst_reg);
		kinsn_emit_u8(buf, &len, rr_opcode);
		kinsn_emit_u8(buf, &len, 0xc0 |
			      (kinsn_x86_code(src_reg) << 3) |
			      kinsn_x86_code(dst_reg));
		goto finish;
	}

	if (x86_alu_is_shift(op)) {
		if (alu->imm < 0 || alu->imm >= 32)
			return -EINVAL;
		if (width == 8) {
			kinsn_emit_rex8_rm(buf, &len, dst_reg);
			kinsn_emit_u8(buf, &len, 0xc0);
		} else {
			kinsn_emit_rex_rr(buf, &len, false, 0, dst_reg);
			kinsn_emit_u8(buf, &len, 0xc1);
		}
		kinsn_emit_u8(buf, &len, 0xc0 | (imm_group << 3) |
			      kinsn_x86_code(dst_reg));
		kinsn_emit_u8(buf, &len, (u8)alu->imm);
		goto finish;
	}

	if (width == 8) {
		if (alu->imm < 0 || alu->imm > 0xff)
			return -EINVAL;
		kinsn_emit_rex8_rm(buf, &len, dst_reg);
		kinsn_emit_u8(buf, &len, 0x80);
		kinsn_emit_u8(buf, &len, 0xc0 | (imm_group << 3) |
			      kinsn_x86_code(dst_reg));
		kinsn_emit_u8(buf, &len, (u8)alu->imm);
	} else {
		if (alu->imm < 0 || alu->imm > 0xffff)
			return -EINVAL;
		kinsn_emit_rex_rr(buf, &len, false, 0, dst_reg);
		kinsn_emit_u8(buf, &len, 0x81);
		kinsn_emit_u8(buf, &len, 0xc0 | (imm_group << 3) |
			      kinsn_x86_code(dst_reg));
		kinsn_emit_u8(buf, &len, (u8)alu->imm);
		kinsn_emit_u8(buf, &len, (u8)(alu->imm >> 8));
	}

finish:
	if (temp >= 0)
		emit_alu_temp_slot(buf, &len, kinsn_x86_reg_for_prog(prog, temp), frame, true);
	return kinsn_emit_finish(image, off, emit, buf, len);
}

#define DEFINE_X86_ALU_FUNCS(name, bpf_op, width, rr_opcode, imm_group)	\
static int instantiate_##name(u64 payload, struct bpf_insn *insn_buf)	\
{									\
	return instantiate_x86_alu(payload, insn_buf, bpf_op, width);	\
}									\
									\
static int emit_##name##_x86(u8 *image, u32 *off, bool emit,		\
			     u64 payload, const struct bpf_prog *prog,	\
			     const u8 *final_ip)			\
{									\
	return emit_x86_alu(image, off, emit, payload, prog, width,	\
			    bpf_op, rr_opcode, imm_group);		\
}

#define DEFINE_X86_ALU_NARROW_FUNCS(name, bpf_op, width, rr_opcode, imm_group) \
static int instantiate_##name(u64 payload, struct bpf_insn *insn_buf)	\
{									\
	return instantiate_x86_alu_narrow(payload, insn_buf, bpf_op, width); \
}									\
									\
static int emit_##name##_x86(u8 *image, u32 *off, bool emit,		\
			     u64 payload, const struct bpf_prog *prog,	\
			     const u8 *final_ip)			\
{									\
	return emit_x86_alu_narrow(image, off, emit, payload, prog,	\
				   width, bpf_op, rr_opcode, imm_group);	\
}

DEFINE_X86_ALU_FUNCS(addq, BPF_ADD, 64, 0x01, 0)
DEFINE_X86_ALU_FUNCS(addl, BPF_ADD, 32, 0x01, 0)
DEFINE_X86_ALU_NARROW_FUNCS(addb, BPF_ADD, 8, 0x00, 0)
DEFINE_X86_ALU_NARROW_FUNCS(subb, BPF_SUB, 8, 0x28, 5)
DEFINE_X86_ALU_FUNCS(subq, BPF_SUB, 64, 0x29, 5)
DEFINE_X86_ALU_FUNCS(subl, BPF_SUB, 32, 0x29, 5)
DEFINE_X86_ALU_FUNCS(andq, BPF_AND, 64, 0x21, 4)
DEFINE_X86_ALU_FUNCS(andl, BPF_AND, 32, 0x21, 4)
DEFINE_X86_ALU_NARROW_FUNCS(andb, BPF_AND, 8, 0x20, 4)
DEFINE_X86_ALU_FUNCS(xorq, BPF_XOR, 64, 0x31, 6)
DEFINE_X86_ALU_FUNCS(xorl, BPF_XOR, 32, 0x31, 6)
DEFINE_X86_ALU_FUNCS(orq, BPF_OR, 64, 0x09, 1)
DEFINE_X86_ALU_FUNCS(orl, BPF_OR, 32, 0x09, 1)
DEFINE_X86_ALU_NARROW_FUNCS(orw, BPF_OR, 16, 0x09, 1)
DEFINE_X86_ALU_NARROW_FUNCS(orb, BPF_OR, 8, 0x08, 1)
DEFINE_X86_ALU_FUNCS(shlq, BPF_LSH, 64, 0, 4)
DEFINE_X86_ALU_FUNCS(shll, BPF_LSH, 32, 0, 4)
DEFINE_X86_ALU_NARROW_FUNCS(shlb, BPF_LSH, 8, 0, 4)
DEFINE_X86_ALU_FUNCS(shrq, BPF_RSH, 64, 0, 5)
DEFINE_X86_ALU_FUNCS(shrl, BPF_RSH, 32, 0, 5)
DEFINE_X86_ALU_NARROW_FUNCS(shrb, BPF_RSH, 8, 0, 5)
DEFINE_X86_ALU_FUNCS(sarq, BPF_ARSH, 64, 0, 7)
DEFINE_X86_ALU_FUNCS(sarl, BPF_ARSH, 32, 0, 7)

static int emit_xorb_sib_x86(u8 *image, u32 *off, bool emit,
			     const struct kinsn_x86_alu_payload *alu,
			     const struct bpf_prog *prog)
{
	return emit_alu_data_x86(image, off, emit, alu, prog, 8, 0x33, true);
}

static int emit_xorb_x86(u8 *image, u32 *off, bool emit, u64 payload,
			 const struct bpf_prog *prog,
			 const u8 *final_ip)
{
	struct kinsn_x86_alu_payload decoded;
	int err;

	err = decode_x86_alu_payload(payload, &decoded);
	if (err)
		return err;
	switch (decoded.form) {
	case KINSN_X86_ALU_FORM_IMM:
	case KINSN_X86_ALU_FORM_ARCH_IMM:
		return emit_x86_alu_narrow(image, off, emit, payload, prog, 8, BPF_XOR, 0x30, 6);
	case KINSN_X86_ALU_FORM_RR:
	case KINSN_X86_ALU_FORM_ARCH_RR:
		return emit_x86_alu_narrow(image, off, emit, payload, prog, 8, BPF_XOR, 0x30, 6);
	case KINSN_X86_ALU_FORM_SIB:
	case KINSN_X86_ALU_FORM_ARCH_SIB:
		return emit_xorb_sib_x86(image, off, emit, &decoded, prog);
	default:
		return -EINVAL;
	}
}

static int emit_xorw_x86(u8 *image, u32 *off, bool emit, u64 payload,
			 const struct bpf_prog *prog,
			 const u8 *final_ip)
{
	struct kinsn_x86_alu_payload decoded;
	int err;

	err = decode_x86_alu_payload(payload, &decoded);
	if (err)
		return err;
	if (decoded.form != KINSN_X86_ALU_FORM_MEM &&
	    decoded.form != KINSN_X86_ALU_FORM_ARCH_MEM)
		return -EINVAL;
	return emit_alu_mem_x86(image, off, emit, &decoded, prog, 16,
				0x33);
}

static int emit_incb_x86(u8 *image, u32 *off, bool emit,
			 u64 payload, const struct bpf_prog *prog,
			 const u8 *final_ip)
{
	struct kinsn_x86_alu_payload decoded;
	u8 buf[4];
	u8 dst_reg;
	bool arch_reg;
	u32 len = 0;
	int err;

	err = decode_x86_alu_payload(payload, &decoded);
	if (err)
		return err;
	if ((decoded.form != KINSN_X86_ALU_FORM_IMM &&
	     decoded.form != KINSN_X86_ALU_FORM_ARCH_IMM) ||
	    decoded.imm != 0)
		return -EINVAL;

	arch_reg = x86_alu_uses_arch_reg(decoded.form);
	dst_reg = arch_reg ? decoded.dst_reg :
			     kinsn_x86_reg_for_prog(prog, decoded.dst_reg);
	if (!kinsn_x86_valid(dst_reg))
		return -EINVAL;

	kinsn_emit_rex8_rm(buf, &len, dst_reg);
	kinsn_emit_u8(buf, &len, 0xfe);
	kinsn_emit_u8(buf, &len, 0xc0 | kinsn_x86_code(dst_reg));

	return kinsn_emit_finish(image, off, emit, buf, len);
}

static int emit_inc_x86(u8 *image, u32 *off, bool emit, u64 payload,
			const struct bpf_prog *prog, bool is64)
{
	struct kinsn_x86_alu_payload decoded;
	u8 buf[4];
	u8 dst_reg;
	bool arch_reg;
	u32 len = 0;
	int err;

	err = decode_x86_alu_payload(payload, &decoded);
	if (err)
		return err;
	if ((decoded.form != KINSN_X86_ALU_FORM_IMM &&
	     decoded.form != KINSN_X86_ALU_FORM_ARCH_IMM) ||
	    decoded.imm != 0)
		return -EINVAL;

	arch_reg = x86_alu_uses_arch_reg(decoded.form);
	dst_reg = arch_reg ? decoded.dst_reg :
			     kinsn_x86_reg_for_prog(prog, decoded.dst_reg);
	if (!kinsn_x86_valid(dst_reg))
		return -EINVAL;

	kinsn_emit_rex_rr(buf, &len, is64, 0, dst_reg);
	kinsn_emit_u8(buf, &len, 0xff);
	kinsn_emit_u8(buf, &len, 0xc0 | kinsn_x86_code(dst_reg));

	return kinsn_emit_finish(image, off, emit, buf, len);
}

static int emit_incl_x86(u8 *image, u32 *off, bool emit,
			 u64 payload, const struct bpf_prog *prog,
			 const u8 *final_ip)
{
	return emit_inc_x86(image, off, emit, payload, prog, false);
}

static int emit_incq_x86(u8 *image, u32 *off, bool emit,
			 u64 payload, const struct bpf_prog *prog,
			 const u8 *final_ip)
{
	return emit_inc_x86(image, off, emit, payload, prog, true);
}

static void emit_divl_rr(u8 *buf, u32 *len, bool wide, u8 opcode,
			 u8 dst, u8 src)
{
	kinsn_emit_rex_rr(buf, len, wide, src, dst);
	kinsn_emit_u8(buf, len, opcode);
	kinsn_emit_u8(buf, len, 0xc0 | (kinsn_x86_code(src) << 3) | kinsn_x86_code(dst));
}

static void emit_divl_slot(u8 *buf, u32 *len, u8 reg, u8 frame, s16 offset, bool load)
{
	kinsn_emit_rex(buf, len, true, kinsn_x86_ext(reg), false, kinsn_x86_ext(frame));
	kinsn_emit_u8(buf, len, load ? 0x8b : 0x89);
	kinsn_emit_modrm_mem(buf, len, reg, frame, offset);
}

static int emit_divl_x86(u8 *image, u32 *off, bool emit,
			 u64 payload, const struct bpf_prog *prog,
			 const u8 *final_ip)
{
	u8 buf[96];
	u8 src_reg, num, divisor;
	u8 frame = kinsn_x86_reg_for_prog(prog, BPF_REG_10);
	u32 len = 0, zero_jump, done_jump;
	int err;

	err = decode_divl_payload(payload, &src_reg);
	if (err)
		return err;
	err = divl_temps(src_reg, &num, &divisor);
	if (err)
		return err;
	src_reg = kinsn_x86_reg_for_prog(prog, src_reg);
	num = kinsn_x86_reg_for_prog(prog, num);
	divisor = kinsn_x86_reg_for_prog(prog, divisor);

	emit_divl_slot(buf, &len, num, frame, KINSN_X86_PROOF_LHS_OFF, false);
	emit_divl_slot(buf, &len, divisor, frame, KINSN_X86_PROOF_RHS_OFF, false);
	emit_divl_rr(buf, &len, false, 0x89, divisor, src_reg);
	emit_divl_rr(buf, &len, false, 0x89, num, BPF_REG_3);
	kinsn_emit_rex_rr(buf, &len, true, 0, num);
	kinsn_emit_u8(buf, &len, 0xc1);
	kinsn_emit_u8(buf, &len, 0xe0 | kinsn_x86_code(num));
	kinsn_emit_u8(buf, &len, 32);
	emit_divl_rr(buf, &len, false, 0x89, BPF_REG_0, BPF_REG_0);
	emit_divl_rr(buf, &len, true, 0x09, num, BPF_REG_0);
	emit_divl_rr(buf, &len, true, 0x89, BPF_REG_0, num);

	/* The guard is self-contained. DIV64 with high half zero cannot overflow;
	 * MOV32 below supplies BPF's truncated quotient and remainder semantics.
	 */
	emit_divl_rr(buf, &len, false, 0x31, BPF_REG_3, BPF_REG_3);
	emit_divl_rr(buf, &len, true, 0x85, divisor, divisor);
	kinsn_emit_u8(buf, &len, 0x74); /* JZ zero */
	zero_jump = len;
	kinsn_emit_u8(buf, &len, 0);
	kinsn_emit_rex_rr(buf, &len, true, 0, divisor);
	kinsn_emit_u8(buf, &len, 0xf7);
	kinsn_emit_u8(buf, &len, 0xf0 | kinsn_x86_code(divisor));
	kinsn_emit_u8(buf, &len, 0xeb); /* JMP done */
	done_jump = len;
	kinsn_emit_u8(buf, &len, 0);
	buf[zero_jump] = len - zero_jump - 1;
	emit_divl_rr(buf, &len, true, 0x89, BPF_REG_3, BPF_REG_0);
	emit_divl_rr(buf, &len, false, 0x31, BPF_REG_0, BPF_REG_0);
	buf[done_jump] = len - done_jump - 1;

	emit_divl_rr(buf, &len, false, 0x89, BPF_REG_0, BPF_REG_0);
	emit_divl_rr(buf, &len, false, 0x89, BPF_REG_3, BPF_REG_3);
	emit_divl_slot(buf, &len, divisor, frame, KINSN_X86_PROOF_RHS_OFF, true);
	emit_divl_slot(buf, &len, num, frame, KINSN_X86_PROOF_LHS_OFF, true);
	return kinsn_emit_finish(image, off, emit, buf, len);
}

const struct bpf_kinsn bpf_x86_addb_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 16 + KINSN_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 24,
	.instantiate_insn = instantiate_addb,
	.emit_x86 = emit_addb_x86,
};

const struct bpf_kinsn bpf_x86_andb_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 16,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_andb,
	.emit_x86 = emit_andb_x86,
};

const struct bpf_kinsn bpf_x86_incb_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 3,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_incb,
	.emit_x86 = emit_incb_x86,
};

const struct bpf_kinsn bpf_x86_incq_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 1,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_incq,
	.emit_x86 = emit_incq_x86,
};

const struct bpf_kinsn bpf_x86_incl_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 1,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_incl,
	.emit_x86 = emit_incl_x86,
};

const struct bpf_kinsn bpf_x86_divl_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 15,
	.max_emit_bytes = 96,
	.instantiate_insn = instantiate_divl,
	.emit_x86 = emit_divl_x86,
};

const struct bpf_kinsn bpf_x86_xorb_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 24 + KINSN_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 32,
	.instantiate_insn = instantiate_xorb,
	.emit_x86 = emit_xorb_x86,
};

const struct bpf_kinsn bpf_x86_xorw_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 18 + KINSN_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 32,
	.instantiate_insn = instantiate_xorw,
	.emit_x86 = emit_xorw_x86,
};

const struct bpf_kinsn bpf_x86_orw_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 48,
	.max_emit_bytes = 8,
	.instantiate_insn = instantiate_orw,
	.emit_x86 = emit_orw_x86,
};

const struct bpf_kinsn bpf_x86_orb_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 24,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_orb,
	.emit_x86 = emit_orb_x86,
};

const struct bpf_kinsn bpf_x86_subb_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 16 + KINSN_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 24,
	.instantiate_insn = instantiate_subb,
	.emit_x86 = emit_subb_x86,
};

const struct bpf_kinsn bpf_x86_shlb_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 7241,
	.max_emit_bytes = 24,
	.instantiate_insn = instantiate_shlb,
	.emit_x86 = emit_shlb_x86,
};

const struct bpf_kinsn bpf_x86_shrb_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 7241,
	.max_emit_bytes = 24,
	.instantiate_insn = instantiate_shrb,
	.emit_x86 = emit_shrb_x86,
};

	#define DEFINE_X86_ALU_DESC(name)					\
const struct bpf_kinsn bpf_x86_##name##_desc = {			\
	.owner = THIS_MODULE,						\
	.max_insn_cnt = 24 + KINSN_X86_SAVE_RESTORE_INSN_CNT,		\
	.max_emit_bytes = 32,						\
	.instantiate_insn = instantiate_##name,				\
	.emit_x86 = emit_##name##_x86,					\
}

DEFINE_X86_ALU_DESC(addq);
DEFINE_X86_ALU_DESC(addl);
DEFINE_X86_ALU_DESC(subq);
DEFINE_X86_ALU_DESC(subl);
DEFINE_X86_ALU_DESC(andq);
DEFINE_X86_ALU_DESC(andl);
DEFINE_X86_ALU_DESC(xorq);
DEFINE_X86_ALU_DESC(xorl);
DEFINE_X86_ALU_DESC(orq);
DEFINE_X86_ALU_DESC(orl);
DEFINE_X86_ALU_DESC(shlq);
DEFINE_X86_ALU_DESC(shll);
DEFINE_X86_ALU_DESC(shrq);
DEFINE_X86_ALU_DESC(shrl);
DEFINE_X86_ALU_DESC(sarq);
DEFINE_X86_ALU_DESC(sarl);

static const struct bpf_kinsn * const bpf_x86_alu_kinsn_descs[] = {
	/*
	 * resolve_btfids stores the set in resolved BTF-id order, not source
	 * declaration order. Keep this array in the same order as .BTF_ids;
	 * otherwise a kfunc call gets the wrong kinsn descriptor and fails
	 * before verifier instruction processing starts.
	 */
	&bpf_x86_addb_desc,
	&bpf_x86_addl_desc,
	&bpf_x86_addq_desc,
	&bpf_x86_andb_desc,
	&bpf_x86_andl_desc,
	&bpf_x86_andq_desc,
	&bpf_x86_divl_desc,
	&bpf_x86_incb_desc,
	&bpf_x86_incl_desc,
	&bpf_x86_incq_desc,
	&bpf_x86_orb_desc,
	&bpf_x86_orl_desc,
	&bpf_x86_orq_desc,
	&bpf_x86_orw_desc,
	&bpf_x86_sarl_desc,
	&bpf_x86_sarq_desc,
	&bpf_x86_shlb_desc,
	&bpf_x86_shll_desc,
	&bpf_x86_shlq_desc,
	&bpf_x86_shrb_desc,
	&bpf_x86_shrl_desc,
	&bpf_x86_shrq_desc,
	&bpf_x86_subb_desc,
	&bpf_x86_subl_desc,
	&bpf_x86_subq_desc,
	&bpf_x86_xorb_desc,
	&bpf_x86_xorl_desc,
	&bpf_x86_xorq_desc,
	&bpf_x86_xorw_desc,
};

DEFINE_KINSN_V2_MODULE(bpf_x86_alu,
		       "BpfReJIT x86 kinsn: immediate ALU",
		       bpf_x86_alu_kfunc_ids,
		       bpf_x86_alu_kinsn_descs);
