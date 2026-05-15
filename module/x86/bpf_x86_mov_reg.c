// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT x86 kinsns: MOV register-to-register.
 */

#include "kinsn_x86_emit.h"

__bpf_kfunc_start_defs();
__bpf_kfunc void bpf_x86_movq_rr(void) {}
__bpf_kfunc_end_defs();

BTF_KFUNCS_START(bpf_x86_mov_reg_kfunc_ids)
BTF_ID_FLAGS(func, bpf_x86_movq_rr)
BTF_KFUNCS_END(bpf_x86_mov_reg_kfunc_ids)

static __always_inline int decode_mov_rr_payload(u64 payload, u8 *dst_reg,
						 u8 *src_reg)
{
	*dst_reg = kinsn_payload_reg(payload, 0);
	*src_reg = kinsn_payload_reg(payload, 4);

	if (payload >> 8)
		return -EINVAL;
	if (*dst_reg > BPF_REG_10 || *src_reg > BPF_REG_10)
		return -EINVAL;
	if (!kinsn_x86_reg_valid(*dst_reg) || !kinsn_x86_reg_valid(*src_reg))
		return -EINVAL;

	return 0;
}

static int instantiate_movq_rr(u64 payload, struct bpf_insn *insn_buf)
{
	u8 dst_reg, src_reg;
	int err;

	err = decode_mov_rr_payload(payload, &dst_reg, &src_reg);
	if (err)
		return err;

	insn_buf[0] = BPF_MOV64_REG(dst_reg, src_reg);
	return 1;
}

static int emit_movq_rr_x86(u8 *image, u32 *off, bool emit, u64 payload,
			    const struct bpf_prog *prog)
{
	u8 dst_reg, src_reg;
	u8 buf[4];
	u32 len = 0;
	int err;

	if (!off)
		return -EINVAL;
	if (emit && !image)
		return -EINVAL;

	err = decode_mov_rr_payload(payload, &dst_reg, &src_reg);
	if (err)
		return err;

	dst_reg = kinsn_x86_reg_for_prog(prog, dst_reg);
	src_reg = kinsn_x86_reg_for_prog(prog, src_reg);
	if (!kinsn_x86_valid(dst_reg) || !kinsn_x86_valid(src_reg))
		return -EINVAL;

	kinsn_emit_rex_rr(buf, &len, true, src_reg, dst_reg);
	kinsn_emit_u8(buf, &len, 0x89);
	kinsn_emit_u8(buf, &len, 0xC0 |
		      (kinsn_x86_code(src_reg) << 3) |
		      kinsn_x86_code(dst_reg));

	if (emit)
		memcpy(image + *off, buf, len);
	*off += len;
	return 1;
}

const struct bpf_kinsn bpf_x86_movq_rr_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 1,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_movq_rr,
	.emit_x86 = emit_movq_rr_x86,
};

static const struct bpf_kinsn * const bpf_x86_mov_reg_kinsn_descs[] = {
	&bpf_x86_movq_rr_desc,
};

DEFINE_KINSN_V2_MODULE(bpf_x86_mov_reg, "BpfReJIT x86 kinsns: MOV",
		       bpf_x86_mov_reg_kfunc_ids, bpf_x86_mov_reg_kinsn_descs);
