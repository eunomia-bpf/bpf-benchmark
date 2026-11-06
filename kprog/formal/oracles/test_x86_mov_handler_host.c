/*
 * Host cross-check for the x86 register-writing MOV handlers
 * (`X86_SIM_L_EXEC_MOV_IMM{,_AUX}` and `X86_SIM_L_EXEC_MOV_REG{,_AUX}`).
 *
 * The generated contracts under `generated/` are the artifact under test; the
 * `*_oracle` functions are independent restatements of the same architecture.
 * Built with `-Wall -Wextra -O2` and swept with a fixed-seed LCG so the run is
 * deterministic.
 */
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;
typedef signed long long __s64;

#define X86_WIDTH_8 1U
#define X86_WIDTH_16 2U
#define X86_WIDTH_32 4U
#define X86_WIDTH_64 8U

#define X86_RSP 4U
#define X86_SIM_TAG_STACK 4U

/* The register-lane AUX decoder lives in x86_sim.h; restate the byte-shift
 * extractor here so the oracle exercises the same encoding the sim uses. */
#define X86_REG_LANE_AUX(DST_SHIFT, SRC_SHIFT)                              \
	((((__u32)(DST_SHIFT) & 0xffU) << 8) |                              \
	 (((__u32)(SRC_SHIFT) & 0xffU) << 16))
#define X86_REG_LANE_AUX_DST_SHIFT(AUX) ((__u8)(((AUX) >> 8) & 0xffU))
#define X86_REG_LANE_AUX_SRC_SHIFT(AUX) ((__u8)(((AUX) >> 16) & 0xffU))

#include "generated/ptr_add.h"
#include "generated/x86_reg_write.h"
#include "generated/x86_reg_read.h"
#include "generated/x86_width.h"

#include <stdio.h>

union reg_storage {
	void *ptr;
	__u64 q;
	__u16 w;
	__u8 b[8];
};

struct mov_result {
	__u64 dst;
	__u8 tag;
};

/* ------------------------------------------------------------------ */
/* Part 1: the MOV-immediate handler.                                 */

/* Independent statement of the partial-register writeback with an explicit
 * byte lane; the lane only matters for 8-bit writes. */
static __u64 oracle_write_at(__u64 old, __u64 value, unsigned width, __u8 shift)
{
	switch (width) {
	case X86_WIDTH_8:
		if (shift == 8U)
			return (old & ~0xff00ULL) | ((value & 0xffULL) << 8);
		return (old & ~0xffULL) | (value & 0xffULL);
	case X86_WIDTH_16:
		return (old & ~0xffffULL) | (value & 0xffffULL);
	case X86_WIDTH_32:
		return value & 0xffffffffULL;
	default:
		return value;
	}
}

/* The generated composition, exactly as `X86_SIM_L_EXEC_MOV_IMM_AUX` orders it:
 * the raw immediate goes through the width/lane partial-register writeback. */
static struct mov_result generated_mov_imm(__u64 old, __u8 old_tag,
					   __u64 imm, unsigned width,
					   __u32 aux)
{
	union reg_storage storage = { .q = old };
	struct mov_result out;
	__u8 tag = old_tag;
	__u8 shift = X86_REG_LANE_AUX_DST_SHIFT(aux);

	switch (width) {
	case X86_WIDTH_8:
		KPROG_X86_WRITE_REG8(storage, tag, imm, shift, 0);
		break;
	case X86_WIDTH_16:
		KPROG_X86_WRITE_REG16(storage, tag, imm, 0);
		break;
	case X86_WIDTH_32:
		KPROG_X86_WRITE_REG32(storage, tag, imm, 0);
		break;
	default:
		KPROG_X86_WRITE_REG64(storage, tag, imm, 0);
		break;
	}
	out.dst = storage.q;
	out.tag = tag;
	return out;
}

/* Independent statement of the same composition. */
static struct mov_result oracle_mov_imm(__u64 old, __u8 old_tag, __u64 imm,
					unsigned width, __u32 aux)
{
	struct mov_result out;

	(void)old_tag;

	out.dst = oracle_write_at(old, imm, width,
				  X86_REG_LANE_AUX_DST_SHIFT(aux));
	out.tag = 0U;
	return out;
}

/* ------------------------------------------------------------------ */
/* Part 2: the register-source MOV handler.                           */

/* The generated composition, exactly as `X86_SIM_L_EXEC_MOV_REG_AUX` orders it.
 * `src_reg` is the encoded source register; `src_ptr` is that register's raw
 * pointer value and `src_tag` its provenance. */
static struct mov_result generated_mov_reg(__u64 old, __u8 old_tag,
					   __u8 src_reg, __u64 src_ptr,
					   __u8 src_tag, unsigned width,
					   __u32 aux, __u64 stack_base)
{
	union reg_storage storage = { .q = old };
	struct mov_result out;
	__u8 tag = old_tag;

	if (width == X86_WIDTH_64 && src_reg == X86_RSP) {
		out.dst = (__u64)(long)KPROG_PTR_ADD64_BITS(
			(void *)(long)src_ptr, stack_base);
		out.tag = KPROG_PTR_ADD64_TAG(X86_SIM_TAG_STACK);
		return out;
	}
	if (width == X86_WIDTH_64) {
		out.dst = (__u64)(long)KPROG_PTR_ADD64_BITS(
			(void *)(long)src_ptr, 0);
		out.tag = KPROG_PTR_ADD64_TAG(src_tag);
		return out;
	}
	__u64 value = KPROG_X86_READ_REG_AT(
		src_ptr, width, X86_REG_LANE_AUX_SRC_SHIFT(aux));
	switch (width) {
	case X86_WIDTH_8:
		KPROG_X86_WRITE_REG8(storage, tag, value,
				     X86_REG_LANE_AUX_DST_SHIFT(aux), 0);
		break;
	case X86_WIDTH_16:
		KPROG_X86_WRITE_REG16(storage, tag, value, 0);
		break;
	case X86_WIDTH_32:
		KPROG_X86_WRITE_REG32(storage, tag, value, 0);
		break;
	default:
		KPROG_X86_WRITE_REG64(storage, tag, value, 0);
		break;
	}
	out.dst = storage.q;
	out.tag = tag;
	return out;
}

/* Independent statement of the same composition. */
static struct mov_result oracle_mov_reg(__u64 old, __u8 old_tag, __u8 src_reg,
					__u64 src_ptr, __u8 src_tag,
					unsigned width, __u32 aux,
					__u64 stack_base)
{
	struct mov_result out;
	__u8 src_shift = X86_REG_LANE_AUX_SRC_SHIFT(aux);
	__u8 dst_shift = X86_REG_LANE_AUX_DST_SHIFT(aux);
	__u64 value;

	(void)old_tag;
	if (width == X86_WIDTH_64 && src_reg == X86_RSP) {
		out.dst = stack_base + src_ptr;
		out.tag = X86_SIM_TAG_STACK;
		return out;
	}
	if (width == X86_WIDTH_64) {
		out.dst = src_ptr;
		out.tag = src_tag;
		return out;
	}
	if (width == X86_WIDTH_8 && src_shift == 8U)
		value = (src_ptr >> 8) & 0xffULL;
	else
		value = src_ptr & KPROG_X86_WIDTH_MASK(width);
	out.dst = oracle_write_at(old, value, width, dst_shift);
	out.tag = 0U;
	return out;
}

static int same_mov(const char *name, struct mov_result got,
		    struct mov_result want, unsigned width, __u32 aux,
		    __u64 old)
{
	if (got.dst == want.dst && got.tag == want.tag)
		return 0;
	printf("MOV MISMATCH %s w=%u aux=%#x old=%#llx dst=%#llx/%#llx "
	       "tag=%u/%u\n",
	       name, width, aux, old, got.dst, want.dst, got.tag, want.tag);
	return 1;
}

static int check_mov_imm(__u64 old, __u8 old_tag, __u64 imm, unsigned width,
			 __u8 dst_shift)
{
	__u32 aux = X86_REG_LANE_AUX(dst_shift, 0);
	struct mov_result got = generated_mov_imm(old, old_tag, imm, width, aux);
	struct mov_result want = oracle_mov_imm(old, old_tag, imm, width, aux);

	return same_mov("imm", got, want, width, aux, old);
}

static int check_mov_reg(__u8 src_reg, __u64 src_ptr, __u8 src_tag,
			 unsigned width, __u8 dst_shift, __u8 src_shift,
			 __u64 old, __u8 old_tag, __u64 stack_base)
{
	__u32 aux = X86_REG_LANE_AUX(dst_shift, src_shift);
	struct mov_result got = generated_mov_reg(old, old_tag, src_reg, src_ptr,
						  src_tag, width, aux,
						  stack_base);
	struct mov_result want = oracle_mov_reg(old, old_tag, src_reg, src_ptr,
						src_tag, width, aux,
						stack_base);

	return same_mov("reg", got, want, width, aux, old);
}

static const __u64 imms[] = { 0x0ULL, 1ULL, 0xffULL, 0x1234ULL, ~0ULL,
			      0xffffffffULL, 0x80000000ULL, 0x8000000000000000ULL };
static const unsigned widths[] = { X86_WIDTH_8, X86_WIDTH_16, X86_WIDTH_32,
				   X86_WIDTH_64 };
static const __u64 olds[] = { 0x0ULL, 0xffffffffffffffffULL,
			      0x1122334455667788ULL, 0xffffffffffff0000ULL };

int main(void)
{
	unsigned cases = 0, fails = 0;
	__u64 state = 0x51ce7b20a94d3f61ULL;

	/* Part 1: the MOV-immediate handler over its structured grid. */
	for (unsigned w = 0; w < sizeof(widths) / sizeof(widths[0]); w++)
		for (unsigned i = 0; i < sizeof(olds) / sizeof(olds[0]); i++)
			for (unsigned j = 0; j < sizeof(imms) / sizeof(imms[0]);
			     j++) {
				const __u8 shifts[3] = { 0U, 8U, 0xffU };
				const __u8 tags[3] = { 0U, 4U, 6U };

				for (unsigned k = 0; k < 3; k++) {
					fails += check_mov_imm(olds[i], tags[k],
							       imms[j],
							       widths[w],
							       shifts[k]);
					cases++;
				}
			}

	for (unsigned iter = 0; iter < 40000; iter++) {
		__u64 old, imm;
		__u8 old_tag, dst_shift;

		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		old = state;
		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		imm = state;
		old_tag = (__u8)((state >> 24) & 7U);
		dst_shift = (state & 0x100U) ? 8U : 0U;
		fails += check_mov_imm(old, old_tag, imm, widths[state % 4],
				       dst_shift);
		cases++;
	}

	/* Part 2: the register-source MOV handler over its structured grid. */
	for (unsigned w = 0; w < sizeof(widths) / sizeof(widths[0]); w++)
		for (unsigned i = 0; i < sizeof(olds) / sizeof(olds[0]); i++) {
			const __u8 src_regs[2] = { X86_RSP, 7U };
			const __u8 shifts[2] = { 0U, 8U };

			for (unsigned k = 0; k < 2; k++)
				for (unsigned l = 0; l < 2; l++) {
					fails += check_mov_reg(
						src_regs[k],
						0x1122334455667788ULL, 2U,
						widths[w], shifts[l], shifts[k],
						olds[i], 6U, 0x7000ULL);
					cases++;
				}
		}

	for (unsigned iter = 0; iter < 60000; iter++) {
		__u64 src_ptr, old, stack_base;
		__u8 src_reg, src_tag, old_tag, dst_shift, src_shift;

		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		src_ptr = state;
		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		old = state;
		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		stack_base = state;
		src_reg = ((state >> 8) & 1U) ? X86_RSP : (__u8)7U;
		src_tag = (__u8)(state & 7U);
		old_tag = (__u8)((state >> 24) & 7U);
		dst_shift = ((state >> 3) & 1U) ? 8U : 0U;
		src_shift = ((state >> 4) & 1U) ? 8U : 0U;
		fails += check_mov_reg(src_reg, src_ptr, src_tag,
				       widths[state % 4], dst_shift, src_shift,
				       old, old_tag, stack_base);
		cases++;
	}

	if (fails) {
		printf("x86 MOV host cross-check: FAILED (%u mismatches)\n",
		       fails);
		return 1;
	}
	printf("x86 MOV host cross-check: OK (%u cases)\n", cases);
	return 0;
}
