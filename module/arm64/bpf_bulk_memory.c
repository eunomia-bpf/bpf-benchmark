// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT kinsn: bulk memcpy/memset via ARM64 pair load/store loops
 */

#include "kinsn_common.h"

__bpf_kfunc_start_defs();
__bpf_kfunc void bpf_memcpy_bulk(void) {}
__bpf_kfunc void bpf_memset_bulk(void) {}
__bpf_kfunc_end_defs();

BTF_KFUNCS_START(bpf_bulk_memory_kfunc_ids)
BTF_ID_FLAGS(func, bpf_memcpy_bulk)
BTF_ID_FLAGS(func, bpf_memset_bulk)
BTF_KFUNCS_END(bpf_bulk_memory_kfunc_ids)

#define A64_TMP_DST_PTR		9
#define A64_TMP_SRC_PTR		10
#define A64_TMP_FILL		10
#define A64_TMP_DATA0		11
#define A64_TMP_DATA1		12
#define A64_TMP_CNT		13

#define A64_COND_GT		0xCU

static __always_inline u8 bulk_width_from_class(u8 width_class)
{
	switch (width_class) {
	case 0:
		return BPF_B;
	case 1:
		return BPF_H;
	case 2:
		return BPF_W;
	case 3:
		return BPF_DW;
	default:
		return 0;
	}
}

static __always_inline u8 bulk_width_bytes(u8 width)
{
	switch (width) {
	case BPF_B:
		return 1;
	case BPF_H:
		return 2;
	case BPF_W:
		return 4;
	case BPF_DW:
		return 8;
	default:
		return 0;
	}
}

static __always_inline bool bulk_byte_window_ok(s16 start, u8 len)
{
	s32 last_byte = (s32)start + len - 1;

	return last_byte >= SHRT_MIN && last_byte <= SHRT_MAX;
}

static int decode_memcpy_payload(u64 payload, u8 *dst_base_reg, u8 *src_base_reg,
				 s16 *dst_off, s16 *src_off, u8 *len,
				 u8 *tmp_reg)
{
	u16 decoded_len;

	*dst_base_reg = kinsn_payload_reg(payload, 0);
	*src_base_reg = kinsn_payload_reg(payload, 4);
	*dst_off = kinsn_payload_s16(payload, 8);
	*src_off = kinsn_payload_s16(payload, 24);
	*tmp_reg = kinsn_payload_reg(payload, 48);
	decoded_len = (u16)kinsn_payload_u8(payload, 40) + 1;

	if (payload >> 52)
		return -EINVAL;
	if (*dst_base_reg > BPF_REG_10 || *src_base_reg > BPF_REG_10 ||
	    *tmp_reg > BPF_REG_10)
		return -EINVAL;
	if (*tmp_reg == BPF_REG_10 || *tmp_reg == *dst_base_reg ||
	    *tmp_reg == *src_base_reg)
		return -EINVAL;
	if (!decoded_len || decoded_len > 128)
		return -EINVAL;
	*len = decoded_len;
	if (!bulk_byte_window_ok(*dst_off, *len) ||
	    !bulk_byte_window_ok(*src_off, *len))
		return -EINVAL;

	return 0;
}

static int decode_memset_payload(u64 payload, u8 *dst_base_reg, u8 *val_reg,
				 s16 *dst_off, u8 *len, u8 *width,
				 bool *value_from_reg, bool *zero_fill,
				 u8 *fill_byte)
{
	u16 decoded_len;
	u8 width_class;

	*dst_base_reg = kinsn_payload_reg(payload, 0);
	*val_reg = kinsn_payload_reg(payload, 4);
	*dst_off = kinsn_payload_s16(payload, 8);
	width_class = kinsn_payload_u8(payload, 32) & 0x3;
	*width = bulk_width_from_class(width_class);
	*value_from_reg = !!(payload & BIT_ULL(34));
	*zero_fill = !!(payload & BIT_ULL(35));
	*fill_byte = kinsn_payload_u8(payload, 36);
	decoded_len = (u16)kinsn_payload_u8(payload, 24) + 1;

	if (payload >> 44)
		return -EINVAL;
	if (*dst_base_reg > BPF_REG_10 || *val_reg > BPF_REG_10)
		return -EINVAL;
	if (!*width)
		return -EINVAL;
	if (!decoded_len || decoded_len < bulk_width_bytes(*width) ||
	    decoded_len > 128)
		return -EINVAL;
	*len = decoded_len;
	if (*len % bulk_width_bytes(*width))
		return -EINVAL;
	if (*zero_fill && *fill_byte)
		return -EINVAL;
	if (!bulk_byte_window_ok(*dst_off, *len))
		return -EINVAL;

	return 0;
}

static int instantiate_memcpy_bulk(u64 payload, struct bpf_insn *insn_buf)
{
	u8 dst_base_reg, src_base_reg, tmp_reg, len;
	s16 dst_off, src_off;
	int cnt = 0;
	int err;
	int i;

	err = decode_memcpy_payload(payload, &dst_base_reg, &src_base_reg,
				    &dst_off, &src_off, &len, &tmp_reg);
	if (err)
		return err;

	for (i = 0; i < len; i++) {
		insn_buf[cnt++] = BPF_LDX_MEM(BPF_B, tmp_reg, src_base_reg,
					      src_off + i);
		insn_buf[cnt++] = BPF_STX_MEM(BPF_B, dst_base_reg, tmp_reg,
					      dst_off + i);
	}

	return cnt;
}

static int instantiate_memset_bulk(u64 payload, struct bpf_insn *insn_buf)
{
	u8 dst_base_reg, val_reg, width, len, fill_byte;
	bool value_from_reg, zero_fill;
	s16 dst_off;
	int cnt = 0;
	int err;
	int i;

	err = decode_memset_payload(payload, &dst_base_reg, &val_reg, &dst_off,
				    &len, &width, &value_from_reg, &zero_fill,
				    &fill_byte);
	if (err)
		return err;

	if (zero_fill || !value_from_reg) {
		u8 imm = zero_fill ? 0 : fill_byte;

		for (i = 0; i < len; i++)
			insn_buf[cnt++] = BPF_ST_MEM(BPF_B, dst_base_reg,
						     dst_off + i, imm);
		return cnt;
	}

	for (i = 0; i < len; i++)
		insn_buf[cnt++] = BPF_STX_MEM(BPF_B, dst_base_reg, val_reg,
					      dst_off + i);

	return cnt;
}

static __always_inline void a64_emit(u32 *image, int *idx, bool emit, u32 insn)
{
	if (emit)
		image[*idx] = cpu_to_le32(insn);
	(*idx)++;
}

static __always_inline u32 a64_add_imm(u8 rd, u8 rn, u16 imm12)
{
	return 0x91000000U |
	       ((u32)imm12 << 10) |
	       ((u32)rn << 5) |
	       (u32)rd;
}

static __always_inline u32 a64_sub_imm(u8 rd, u8 rn, u16 imm12)
{
	return 0xD1000000U |
	       ((u32)imm12 << 10) |
	       ((u32)rn << 5) |
	       (u32)rd;
}

static __always_inline u32 a64_subs_imm(u8 rd, u8 rn, u16 imm12)
{
	return 0xF1000000U |
	       ((u32)imm12 << 10) |
	       ((u32)rn << 5) |
	       (u32)rd;
}

static __always_inline u32 a64_movz(u8 rd, u16 imm16, u8 hw)
{
	return 0xD2800000U |
	       ((u32)hw << 21) |
	       ((u32)imm16 << 5) |
	       (u32)rd;
}

static __always_inline u32 a64_orr_lsl(u8 rd, u8 rn, u8 rm, u8 shift)
{
	return 0xAA000000U |
	       ((u32)rm << 16) |
	       ((u32)shift << 10) |
	       ((u32)rn << 5) |
	       (u32)rd;
}

static __always_inline u32 a64_and_imm_0xff(u8 rd, u8 rn)
{
	return 0x92401C00U | ((u32)rn << 5) | (u32)rd;
}

static __always_inline u32 a64_ldp_post_x(u8 rt, u8 rt2, u8 rn, s16 bytes)
{
	u32 imm7 = ((u32)((s32)(bytes / 8))) & 0x7fU;

	return 0xA8C00000U |
	       (imm7 << 15) |
	       ((u32)rt2 << 10) |
	       ((u32)rn << 5) |
	       (u32)rt;
}

static __always_inline u32 a64_stp_post_x(u8 rt, u8 rt2, u8 rn, s16 bytes)
{
	u32 imm7 = ((u32)((s32)(bytes / 8))) & 0x7fU;

	return 0xA8800000U |
	       (imm7 << 15) |
	       ((u32)rt2 << 10) |
	       ((u32)rn << 5) |
	       (u32)rt;
}

static __always_inline u32 a64_b_cond(s32 imm19, u8 cond)
{
	return 0x54000000U |
	       ((((u32)imm19) & 0x7ffffU) << 5) |
	       (u32)cond;
}

static __always_inline u32 a64_ldrb(u8 rt, u8 rn)
{
	return 0x39400000U | ((u32)rn << 5) | (u32)rt;
}

static __always_inline u32 a64_ldrb_imm(u8 rt, u8 rn, u16 imm12)
{
	return 0x39400000U |
	       ((u32)imm12 << 10) |
	       ((u32)rn << 5) |
	       (u32)rt;
}

static __always_inline u32 a64_ldrh(u8 rt, u8 rn)
{
	return 0x79400000U | ((u32)rn << 5) | (u32)rt;
}

static __always_inline u32 a64_ldr_w(u8 rt, u8 rn)
{
	return 0xB9400000U | ((u32)rn << 5) | (u32)rt;
}

static __always_inline u32 a64_ldr_x(u8 rt, u8 rn)
{
	return 0xF9400000U | ((u32)rn << 5) | (u32)rt;
}

static __always_inline u32 a64_strb(u8 rt, u8 rn)
{
	return 0x39000000U | ((u32)rn << 5) | (u32)rt;
}

static __always_inline u32 a64_strh(u8 rt, u8 rn)
{
	return 0x79000000U | ((u32)rn << 5) | (u32)rt;
}

static __always_inline u32 a64_str_w(u8 rt, u8 rn)
{
	return 0xB9000000U | ((u32)rn << 5) | (u32)rt;
}

static __always_inline u32 a64_str_x(u8 rt, u8 rn)
{
	return 0xF9000000U | ((u32)rn << 5) | (u32)rt;
}

static void emit_ptr_setup(u32 *image, int *idx, bool emit, u8 ptr_reg,
			   u8 base_reg, s16 offset)
{
	s32 remain = offset;
	u8 src_reg = base_reg;

	if (!remain) {
		a64_emit(image, idx, emit, a64_add_imm(ptr_reg, base_reg, 0));
		return;
	}

	while (remain > 0) {
		u16 chunk = min_t(u16, remain, 4095);

		a64_emit(image, idx, emit, a64_add_imm(ptr_reg, src_reg, chunk));
		src_reg = ptr_reg;
		remain -= chunk;
	}

	while (remain < 0) {
		u16 chunk = min_t(u16, -remain, 4095);

		a64_emit(image, idx, emit, a64_sub_imm(ptr_reg, src_reg, chunk));
		src_reg = ptr_reg;
		remain += chunk;
	}
}

static void emit_memcpy_tail(u32 *image, int *idx, bool emit, u8 dst_ptr_reg,
			     u8 src_ptr_reg, u8 data_reg, u8 tail)
{
	if (tail & 8) {
		a64_emit(image, idx, emit, a64_ldr_x(data_reg, src_ptr_reg));
		a64_emit(image, idx, emit, a64_str_x(data_reg, dst_ptr_reg));
		if ((tail & 7) != 0) {
			a64_emit(image, idx, emit, a64_add_imm(src_ptr_reg,
							       src_ptr_reg, 8));
			a64_emit(image, idx, emit, a64_add_imm(dst_ptr_reg,
							       dst_ptr_reg, 8));
		}
	}
	if (tail & 4) {
		a64_emit(image, idx, emit, a64_ldr_w(data_reg, src_ptr_reg));
		a64_emit(image, idx, emit, a64_str_w(data_reg, dst_ptr_reg));
		if ((tail & 3) != 0) {
			a64_emit(image, idx, emit, a64_add_imm(src_ptr_reg,
							       src_ptr_reg, 4));
			a64_emit(image, idx, emit, a64_add_imm(dst_ptr_reg,
							       dst_ptr_reg, 4));
		}
	}
	if (tail & 2) {
		a64_emit(image, idx, emit, a64_ldrh(data_reg, src_ptr_reg));
		a64_emit(image, idx, emit, a64_strh(data_reg, dst_ptr_reg));
		if (tail & 1) {
			a64_emit(image, idx, emit, a64_add_imm(src_ptr_reg,
							       src_ptr_reg, 2));
			a64_emit(image, idx, emit, a64_add_imm(dst_ptr_reg,
							       dst_ptr_reg, 2));
		}
	}
	if (tail & 1) {
		a64_emit(image, idx, emit, a64_ldrb(data_reg, src_ptr_reg));
		a64_emit(image, idx, emit, a64_strb(data_reg, dst_ptr_reg));
	}
}

static void emit_memset_fill_pattern(u32 *image, int *idx, bool emit,
				     u8 fill_reg, bool value_from_reg,
				     bool zero_fill, u8 fill_byte, u8 val_reg)
{
	if (zero_fill) {
		a64_emit(image, idx, emit, a64_movz(fill_reg, 0, 0));
		return;
	}

	if (value_from_reg) {
		a64_emit(image, idx, emit, a64_orr_lsl(fill_reg, 31, val_reg, 0));
		a64_emit(image, idx, emit, a64_and_imm_0xff(fill_reg, fill_reg));
	} else {
		a64_emit(image, idx, emit, a64_movz(fill_reg, fill_byte, 0));
	}

	a64_emit(image, idx, emit, a64_orr_lsl(fill_reg, fill_reg, fill_reg, 8));
	a64_emit(image, idx, emit, a64_orr_lsl(fill_reg, fill_reg, fill_reg, 16));
	a64_emit(image, idx, emit, a64_orr_lsl(fill_reg, fill_reg, fill_reg, 32));
}

static void emit_memset_tail(u32 *image, int *idx, bool emit, u8 dst_ptr_reg,
			     u8 fill_reg, u8 tail)
{
	if (tail & 8) {
		a64_emit(image, idx, emit, a64_str_x(fill_reg, dst_ptr_reg));
		if ((tail & 7) != 0)
			a64_emit(image, idx, emit,
				 a64_add_imm(dst_ptr_reg, dst_ptr_reg, 8));
	}
	if (tail & 4) {
		a64_emit(image, idx, emit, a64_str_w(fill_reg, dst_ptr_reg));
		if ((tail & 3) != 0)
			a64_emit(image, idx, emit,
				 a64_add_imm(dst_ptr_reg, dst_ptr_reg, 4));
	}
	if (tail & 2) {
		a64_emit(image, idx, emit, a64_strh(fill_reg, dst_ptr_reg));
		if (tail & 1)
			a64_emit(image, idx, emit,
				 a64_add_imm(dst_ptr_reg, dst_ptr_reg, 2));
	}
	if (tail & 1)
		a64_emit(image, idx, emit, a64_strb(fill_reg, dst_ptr_reg));
}

static int emit_memcpy_bulk_arm64(u32 *image, int *idx, bool emit,
				  u64 payload, const struct bpf_prog *prog)
{
	u8 dst_base_reg, src_base_reg, tmp_reg, len;
	u8 dst_base_arm64, src_base_arm64, tmp_arm64;
	u8 loop_bytes, tail;
	int start_idx;
	s16 dst_off, src_off;
	int err;

	(void)prog;

	if (!idx)
		return -EINVAL;
	if (emit && !image)
		return -EINVAL;

	err = decode_memcpy_payload(payload, &dst_base_reg, &src_base_reg,
				    &dst_off, &src_off, &len, &tmp_reg);
	if (err)
		return err;

	dst_base_arm64 = kinsn_arm64_reg(dst_base_reg);
	src_base_arm64 = kinsn_arm64_reg(src_base_reg);
	tmp_arm64 = kinsn_arm64_reg(tmp_reg);
	if (dst_base_arm64 == 0xff || src_base_arm64 == 0xff ||
	    tmp_arm64 == 0xff)
		return -EINVAL;

	start_idx = *idx;
	emit_ptr_setup(image, idx, emit, A64_TMP_DST_PTR, dst_base_arm64,
		       dst_off);
	emit_ptr_setup(image, idx, emit, A64_TMP_SRC_PTR, src_base_arm64,
		       src_off);

	loop_bytes = len & ~0xfU;
	tail = len & 0xfU;
	if (loop_bytes) {
		a64_emit(image, idx, emit, a64_movz(A64_TMP_CNT, loop_bytes, 0));
		a64_emit(image, idx, emit, a64_ldp_post_x(A64_TMP_DATA0,
							  A64_TMP_DATA1,
							  A64_TMP_SRC_PTR, 16));
		a64_emit(image, idx, emit, a64_stp_post_x(A64_TMP_DATA0,
							  A64_TMP_DATA1,
							  A64_TMP_DST_PTR, 16));
		a64_emit(image, idx, emit, a64_subs_imm(A64_TMP_CNT,
							A64_TMP_CNT, 16));
		a64_emit(image, idx, emit, a64_b_cond(-3, A64_COND_GT));
	}

	emit_memcpy_tail(image, idx, emit, A64_TMP_DST_PTR, A64_TMP_SRC_PTR,
			 tmp_arm64, tail);
	if (!tail) {
		a64_emit(image, idx, emit,
			 a64_sub_imm(A64_TMP_SRC_PTR, A64_TMP_SRC_PTR, 1));
		a64_emit(image, idx, emit, a64_ldrb(tmp_arm64, A64_TMP_SRC_PTR));
	} else if (!(tail & 1)) {
		u8 last_byte_off;

		if (tail & 2)
			last_byte_off = 1;
		else if (tail & 4)
			last_byte_off = 3;
		else
			last_byte_off = 7;
		a64_emit(image, idx, emit,
			 a64_ldrb_imm(tmp_arm64, A64_TMP_SRC_PTR, last_byte_off));
	}

	return *idx - start_idx;
}

static int emit_memset_bulk_arm64(u32 *image, int *idx, bool emit,
				  u64 payload, const struct bpf_prog *prog)
{
	u8 dst_base_reg, val_reg, width, len, fill_byte;
	u8 dst_base_arm64, val_arm64;
	u8 loop_bytes, tail;
	bool value_from_reg, zero_fill;
	int start_idx;
	s16 dst_off;
	int err;

	(void)prog;

	if (!idx)
		return -EINVAL;
	if (emit && !image)
		return -EINVAL;

	err = decode_memset_payload(payload, &dst_base_reg, &val_reg, &dst_off,
				    &len, &width, &value_from_reg, &zero_fill,
				    &fill_byte);
	if (err)
		return err;
	(void)width;

	dst_base_arm64 = kinsn_arm64_reg(dst_base_reg);
	val_arm64 = kinsn_arm64_reg(val_reg);
	if (dst_base_arm64 == 0xff || (value_from_reg && val_arm64 == 0xff))
		return -EINVAL;

	start_idx = *idx;
	emit_ptr_setup(image, idx, emit, A64_TMP_DST_PTR, dst_base_arm64,
		       dst_off);
	emit_memset_fill_pattern(image, idx, emit, A64_TMP_FILL,
				 value_from_reg, zero_fill, fill_byte,
				 val_arm64);

	loop_bytes = len & ~0xfU;
	tail = len & 0xfU;
	if (loop_bytes) {
		a64_emit(image, idx, emit, a64_movz(A64_TMP_CNT, loop_bytes, 0));
		a64_emit(image, idx, emit, a64_stp_post_x(A64_TMP_FILL,
							  A64_TMP_FILL,
							  A64_TMP_DST_PTR, 16));
		a64_emit(image, idx, emit, a64_subs_imm(A64_TMP_CNT,
							A64_TMP_CNT, 16));
		a64_emit(image, idx, emit, a64_b_cond(-2, A64_COND_GT));
	}

	emit_memset_tail(image, idx, emit, A64_TMP_DST_PTR, A64_TMP_FILL, tail);

	return *idx - start_idx;
}

const struct bpf_kinsn bpf_memcpy_bulk_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 256,
	.max_emit_bytes = 160,
	.instantiate_insn = instantiate_memcpy_bulk,
	.emit_arm64 = emit_memcpy_bulk_arm64,
};

const struct bpf_kinsn bpf_memset_bulk_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 128,
	.max_emit_bytes = 128,
	.instantiate_insn = instantiate_memset_bulk,
	.emit_arm64 = emit_memset_bulk_arm64,
};

static const struct bpf_kinsn * const bpf_bulk_memory_kinsn_descs[] = {
	&bpf_memcpy_bulk_desc,
	&bpf_memset_bulk_desc,
};

DEFINE_KINSN_V2_MODULE(bpf_bulk_memory,
		       "BpfReJIT kinsn: BULK_MEMORY (ARM64 LDP/STP loops)",
		       bpf_bulk_memory_kfunc_ids,
		       bpf_bulk_memory_kinsn_descs);
