// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT x86 kop: PREFETCHT0 for x86-64
 */

#include "kop_x86_emit.h"

__bpf_kfunc_start_defs();
__bpf_kfunc void bpf_x86_prefetcht0(void) {}
__bpf_kfunc_end_defs();

BTF_KFUNCS_START(bpf_x86_prefetch_kfunc_ids)
BTF_ID_FLAGS(func, bpf_x86_prefetcht0)
BTF_KFUNCS_END(bpf_x86_prefetch_kfunc_ids)

static __always_inline int decode_prefetcht0_payload(u64 payload, u8 *ptr_reg)
{
	u8 hint_kind = (payload >> 4) & 0xf;

	*ptr_reg = kop_payload_reg(payload, 0);

	if (hint_kind)
		return -EINVAL;
	if (payload >> 8)
		return -EINVAL;
	if (*ptr_reg > BPF_REG_10)
		return -EINVAL;
	if (!kop_x86_reg_valid(*ptr_reg))
		return -EINVAL;

	return 0;
}

static int instantiate_prefetcht0(u64 payload, struct bpf_insn *insn_buf)
{
	u8 ptr_reg;
	int err;

	err = decode_prefetcht0_payload(payload, &ptr_reg);
	if (err)
		return err;

	insn_buf[0] = BPF_JMP_A(0);
	return 1;
}

static void emit_prefetcht0_mem(u8 *buf, u32 *len, u8 base_reg)
{
	u8 rm = kop_x86_reg_code(base_reg);

	kop_emit_rex(buf, len, false, false, false, kop_x86_ext(base_reg));
	kop_emit_u8(buf, len, 0x0F);
	kop_emit_u8(buf, len, 0x18);

	if (rm == 4) {
		kop_emit_u8(buf, len, 0x0C);
		kop_emit_u8(buf, len, 0x24);
		return;
	}

	if (rm == 5) {
		kop_emit_u8(buf, len, 0x4D);
		kop_emit_u8(buf, len, 0);
		return;
	}

	kop_emit_u8(buf, len, 0x08 | rm);
}

static int emit_prefetcht0_x86(u8 *image, u32 *off, bool emit,
			     u64 payload, const struct bpf_prog *prog,
			 const u8 *final_ip)
{
	u8 ptr_reg;
	u8 buf[6];
	u32 len = 0;
	int err;

	err = decode_prefetcht0_payload(payload, &ptr_reg);
	if (err)
		return err;
	ptr_reg = kop_x86_reg_for_prog(prog, ptr_reg);
	if (!kop_x86_valid(ptr_reg))
		return -EINVAL;

	emit_prefetcht0_mem(buf, &len, ptr_reg);

	return kop_emit_finish(image, off, emit, buf, len);
}

const struct bpf_kop bpf_x86_prefetcht0_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 1 + KOP_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 6,
	.instantiate_insn = instantiate_prefetcht0,
	.emit_x86 = emit_prefetcht0_x86,
};

static const struct bpf_kop * const bpf_x86_prefetch_kop_descs[] = {
	&bpf_x86_prefetcht0_desc,
};

DEFINE_KOP_V2_MODULE(bpf_x86_prefetch, "BpfReJIT x86 kop: PREFETCHT0",
		       bpf_x86_prefetch_kfunc_ids, bpf_x86_prefetch_kop_descs);
