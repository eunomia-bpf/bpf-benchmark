// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT kinsn: PREFETCH - PREFETCHT0 for x86-64
 */

#include "kinsn_common.h"

__bpf_kfunc_start_defs();
__bpf_kfunc void bpf_prefetch(void) {}
__bpf_kfunc_end_defs();

BTF_KFUNCS_START(bpf_prefetch_kfunc_ids)
BTF_ID_FLAGS(func, bpf_prefetch)
BTF_KFUNCS_END(bpf_prefetch_kfunc_ids)

static __always_inline int decode_prefetch_payload(u64 payload, u8 *ptr_reg)
{
	u8 hint_kind = (payload >> 4) & 0xf;

	*ptr_reg = kinsn_payload_reg(payload, 0);

	if (hint_kind)
		return -EINVAL;
	if (payload >> 8)
		return -EINVAL;
	if (*ptr_reg > BPF_REG_10)
		return -EINVAL;
	if (!kinsn_x86_reg_valid(*ptr_reg))
		return -EINVAL;

	return 0;
}

static int instantiate_prefetch(u64 payload, struct bpf_insn *insn_buf)
{
	u8 ptr_reg;
	int err;

	err = decode_prefetch_payload(payload, &ptr_reg);
	if (err)
		return err;

	insn_buf[0] = BPF_JMP_A(0);
	return 1;
}

static void emit_u8(u8 *buf, u32 *len, u8 byte)
{
	buf[(*len)++] = byte;
}

static void emit_rex_b(u8 *buf, u32 *len, u8 base_reg)
{
	if (kinsn_x86_reg_ext(base_reg))
		emit_u8(buf, len, 0x41);
}

static void emit_prefetcht0_mem(u8 *buf, u32 *len, u8 base_reg)
{
	u8 rm = kinsn_x86_reg_code(base_reg);

	emit_rex_b(buf, len, base_reg);
	emit_u8(buf, len, 0x0F);
	emit_u8(buf, len, 0x18);

	if (rm == 4) {
		emit_u8(buf, len, 0x0C);
		emit_u8(buf, len, 0x24);
		return;
	}

	if (rm == 5) {
		emit_u8(buf, len, 0x4D);
		emit_u8(buf, len, 0);
		return;
	}

	emit_u8(buf, len, 0x08 | rm);
}

static int emit_prefetch_x86(u8 *image, u32 *off, bool emit,
			     u64 payload, const struct bpf_prog *prog)
{
	u8 ptr_reg;
	u8 buf[6];
	u32 len = 0;
	int err;

	(void)prog;

	if (!off)
		return -EINVAL;
	if (emit && !image)
		return -EINVAL;

	err = decode_prefetch_payload(payload, &ptr_reg);
	if (err)
		return err;

	emit_prefetcht0_mem(buf, &len, ptr_reg);

	if (emit)
		memcpy(image + *off, buf, len);
	*off += len;
	return len;
}

const struct bpf_kinsn bpf_prefetch_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 1,
	.max_emit_bytes = 6,
	.instantiate_insn = instantiate_prefetch,
	.emit_x86 = emit_prefetch_x86,
};

static const struct bpf_kinsn * const bpf_prefetch_kinsn_descs[] = {
	&bpf_prefetch_desc,
};

DEFINE_KINSN_V2_MODULE(bpf_prefetch, "BpfReJIT kinsn: PREFETCH (PREFETCHT0)",
		       bpf_prefetch_kfunc_ids, bpf_prefetch_kinsn_descs);
