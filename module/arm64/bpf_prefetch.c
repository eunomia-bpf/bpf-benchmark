// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT kinsn: PREFETCH - PRFM PLDL1KEEP for ARM64
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

static __always_inline u32 a64_prfm_pldl1keep(u8 rn)
{
	return 0xF9800000U | ((u32)rn << 5);
}

static int emit_prefetch_arm64(u32 *image, int *idx, bool emit,
			       u64 payload, const struct bpf_prog *prog)
{
	u8 ptr_reg;
	u32 insn;
	int err;

	(void)prog;

	if (!idx)
		return -EINVAL;
	if (emit && !image)
		return -EINVAL;

	err = decode_prefetch_payload(payload, &ptr_reg);
	if (err)
		return err;

	ptr_reg = kinsn_arm64_reg(ptr_reg);
	if (ptr_reg == 0xff)
		return -EINVAL;

	insn = a64_prfm_pldl1keep(ptr_reg);
	if (emit)
		image[*idx] = cpu_to_le32(insn);
	*idx += 1;
	return 1;
}

const struct bpf_kinsn bpf_prefetch_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 1,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_prefetch,
	.emit_arm64 = emit_prefetch_arm64,
};

static const struct bpf_kinsn * const bpf_prefetch_kinsn_descs[] = {
	&bpf_prefetch_desc,
};

DEFINE_KINSN_V2_MODULE(bpf_prefetch, "BpfReJIT kinsn: PREFETCH (PRFM)",
		       bpf_prefetch_kfunc_ids, bpf_prefetch_kinsn_descs);
