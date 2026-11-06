/*
 * Host cross-check for the x86 effective-address offset contract and the LEA
 * handler composition on top of it.
 *
 * Part 1 verifies KPROG_X86_MEM_OFFSET from generated/x86_mem_offset.h against
 * an independent oracle that rebuilds the offset from a signed accumulator
 * plus an explicit power-of-two multiply, never the macro's shift:
 *   off = disp + (has_index ? index * (1 << scale) : 0)
 * Part 2 verifies the `X86_SIM_L_EXEC_LEA` exit selection, stated from the
 * addressing fields rather than from the macro's branch order: the 64-bit
 * RODATA fast path (source register NONE) writes the raw immediate and
 * scalarizes; the 64-bit stack-pointer path tags the destination as stack; the
 * 64-bit general path copies the source tag; narrower widths truncate through
 * the partial-register writeback and always scalarize.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. test_x86_lea_handler_host.c -o /tmp/t_lea && /tmp/t_lea
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

#define X86_REG_NONE 0xffU
#define X86_RSP 4U
#define X86_LEA_AUX_RODATA 1U
#define X86_SIM_TAG_STACK 4U

/* The generated offset contract reads its scale via the aux decoder, which the
 * simulator defines in x86_sim.h. Restate the two tiny decoders here so the
 * oracle exercises the same AUX encoding the sim uses. */
#define X86_MEM_AUX(INDEX, SCALE_LOG2)                                      \
	(((__u32)(INDEX) & 0xffU) | (((__u32)(SCALE_LOG2) & 0xffU) << 8))
#define X86_MEM_AUX_INDEX(AUX) ((__u8)((AUX) & 0xffU))
#define X86_MEM_AUX_SCALE_LOG2(AUX) ((__u8)(((AUX) >> 8) & 0xffU))

#include "generated/ptr_add.h"
#include "generated/x86_mem_offset.h"
#include "generated/x86_reg_write.h"

#include <stdio.h>

union reg_storage {
	void *ptr;
	__u64 q;
	__u16 w;
	__u8 b[8];
};

struct lea_result {
	__u64 dst;
	__u8 tag;
};

/* ------------------------------------------------------------------ */
/* Part 1: the shared effective-address offset contract.              */

/* Independent oracle: explicit power-of-two multiply and signed accumulate,
 * truncated to 64 bits on return. The shift amount is reduced modulo 64
 * because both the generated macro's `<<` and Lean's `<<<` do. */
static __u64 offset_oracle(int has_index, __u8 scale, __u64 disp, __u64 index)
{
	__int128 acc = (__int128)(__s64)disp;

	if (has_index)
		acc += (__int128)index * ((__int128)1 << (scale & 63U));
	return (__u64)(__s64)(acc & 0xffffffffffffffffLL);
}

static int check_offset(__u32 aux, __u64 disp, __u64 index, int has_index)
{
	__u8 scale = X86_MEM_AUX_SCALE_LOG2(aux);
	__u64 res = KPROG_X86_MEM_OFFSET(aux, (__s64)disp, index, has_index);
	__u64 want = offset_oracle(has_index, scale, disp, index);

	if (res != want) {
		printf("OFFSET MISMATCH aux=%#x disp=%#llx index=%#llx "
		       "has_index=%d res=%#llx want=%#llx\n",
		       aux, disp, index, has_index, res, want);
		return 1;
	}
	return 0;
}

/* A source register is always present unless the encoded index is NONE, so the
 * index value the macro sees is what X86_SIM_L_READ_REG would have returned. */
static int check_offset_encoded(__u8 index_reg, __u8 scale_log2, __u64 disp,
				__u64 index_value)
{
	__u32 aux = X86_MEM_AUX(index_reg, scale_log2);
	int has_index = index_reg != X86_REG_NONE;

	return check_offset(aux, disp, index_value, has_index);
}

/* ------------------------------------------------------------------ */
/* Part 2: the LEA handler exits.                                     */

/* Independent statement of the partial-register writeback. */
static __u64 oracle_write(__u64 old, __u64 value, unsigned width)
{
	switch (width) {
	case X86_WIDTH_8:
		return (old & ~0xffULL) | (value & 0xffULL);
	case X86_WIDTH_16:
		return (old & ~0xffffULL) | (value & 0xffffULL);
	case X86_WIDTH_32:
		return value & 0xffffffffULL;
	default:
		return value;
	}
}

static __u64 generated_write(__u64 old, __u64 value, unsigned width,
			     __u8 *tag)
{
	union reg_storage storage = { .q = old };

	switch (width) {
	case X86_WIDTH_8:
		KPROG_X86_WRITE_REG8(storage, *tag, value, 0, 0);
		break;
	case X86_WIDTH_16:
		KPROG_X86_WRITE_REG16(storage, *tag, value, 0);
		break;
	case X86_WIDTH_32:
		KPROG_X86_WRITE_REG32(storage, *tag, value, 0);
		break;
	default:
		KPROG_X86_WRITE_REG64(storage, *tag, value, 0);
		break;
	}
	return storage.q;
}

/* The generated composition, exactly as `X86_SIM_L_EXEC_LEA` orders it.
 * `src_reg` is the encoded source register (X86_REG_NONE when the mode has no
 * source register, so the sim's null pointer read gives 0). */
static struct lea_result generated_lea(__u64 old, __u8 old_tag, __u8 src_reg,
				       __u64 src_ptr, __u8 src_tag, __u64 raw_imm,
				       __u32 aux, unsigned width, __u64 index,
				       __u64 stack_base)
{
	struct lea_result out;
	__u8 out_tag = old_tag;
	__s64 off = KPROG_X86_MEM_OFFSET(aux, (__s64)raw_imm, index,
					 X86_MEM_AUX_INDEX(aux) != X86_REG_NONE);

	if (width == X86_WIDTH_64 && src_reg == X86_REG_NONE &&
	    aux == X86_LEA_AUX_RODATA) {
		out.dst = generated_write(old, raw_imm, width, &out_tag);
		out.tag = out_tag;
		return out;
	}
	if (width == X86_WIDTH_64 && src_reg == X86_RSP) {
		__u64 base = (__u64)(long)KPROG_PTR_ADD64_BITS(
			(void *)(long)src_ptr, (__u64)off);
		out.dst = (__u64)(long)KPROG_PTR_ADD64_BITS(
			(void *)(long)base, stack_base);
		out_tag = KPROG_PTR_ADD64_TAG(X86_SIM_TAG_STACK);
		out.tag = out_tag;
		return out;
	}
	if (width == X86_WIDTH_64) {
		out.dst = (__u64)(long)KPROG_PTR_ADD64_BITS(
			(void *)(long)src_ptr, (__u64)off);
		out_tag = KPROG_PTR_ADD64_TAG(src_tag);
		out.tag = out_tag;
		return out;
	}
	out.dst = generated_write(
		old,
		(__u64)(long)KPROG_PTR_ADD64_BITS((void *)(long)src_ptr,
						  (__u64)off),
		width, &out_tag);
	out.tag = out_tag;
	return out;
}

/* Independent statement of the same composition. */
static struct lea_result oracle_lea(__u64 old, __u8 old_tag, __u8 src_reg,
				    __u64 src_ptr, __u8 src_tag, __u64 raw_imm,
				    __u32 aux, unsigned width, __u64 index,
				    __u64 stack_base)
{
	struct lea_result out;
	__u8 src_is_none = src_reg == X86_REG_NONE;
	__u8 src_is_rsp = src_reg == X86_RSP;
	int has_index = X86_MEM_AUX_INDEX(aux) != X86_REG_NONE;
	__u64 off;
	__u64 sum;
	(void)old_tag;

	if (has_index)
		off = (__u64)((__s64)raw_imm +
			      (__s64)(index <<
				      (X86_MEM_AUX_SCALE_LOG2(aux) & 63U)));
	else
		off = raw_imm;

	if (width == X86_WIDTH_64 && src_is_none &&
	    aux == X86_LEA_AUX_RODATA) {
		out.dst = raw_imm;
		out.tag = 0U;
		return out;
	}
	if (width == X86_WIDTH_64 && src_is_rsp)
		sum = stack_base + src_ptr + off;
	else
		sum = src_ptr + off;

	if (width == X86_WIDTH_64) {
		out.dst = sum;
		out.tag = src_is_rsp ? X86_SIM_TAG_STACK : src_tag;
		return out;
	}
	out.dst = oracle_write(old, sum, width);
	out.tag = 0U;
	return out;
}

static int same_lea(const char *name, struct lea_result got,
		    struct lea_result want, __u8 src_reg, __u32 aux,
		    unsigned width, __u64 old)
{
	if (got.dst == want.dst && got.tag == want.tag)
		return 0;
	printf("LEA MISMATCH %s w=%u src=%#x aux=%#x old=%#llx "
	       "dst=%#llx/%#llx tag=%u/%u\n",
	       name, width, src_reg, aux, old, got.dst, want.dst, got.tag,
	       want.tag);
	return 1;
}

static int check_lea(__u8 src_reg, __u64 src_ptr, __u8 src_tag, __u64 raw_imm,
		     __u8 index_reg, __u8 scale_log2, __u64 index_value,
		     unsigned width, __u64 old, __u8 old_tag,
		     __u64 stack_base)
{
	__u32 aux = X86_MEM_AUX(index_reg, scale_log2);
	struct lea_result got = generated_lea(old, old_tag, src_reg, src_ptr,
					      src_tag, raw_imm, aux, width,
					      index_value, stack_base);
	struct lea_result want = oracle_lea(old, old_tag, src_reg, src_ptr,
					    src_tag, raw_imm, aux, width,
					    index_value, stack_base);

	return same_lea("lea", got, want, src_reg, aux, width, old);
}

/* The RODATA fast path applies only with the rodata aux and no source register. */
static int check_lea_rodata(__u64 raw_imm, unsigned width, __u64 old,
			    __u8 old_tag)
{
	__u32 aux = X86_LEA_AUX_RODATA;
	__u8 src_reg = X86_REG_NONE;
	struct lea_result got = generated_lea(old, old_tag, src_reg, 0, 0,
					      raw_imm, aux, width, 0, 0);
	struct lea_result want = oracle_lea(old, old_tag, src_reg, 0, 0, raw_imm,
					    aux, width, 0, 0);

	return same_lea("rodata", got, want, src_reg, aux, width, old);
}

static const __u64 disps[] = { 0x0ULL, 1ULL, 8ULL, 0x10ULL, ~0ULL,
			       0xfffffffffffffff8ULL, 0x8000000000000000ULL,
			       0x7fffffffULL };
static const __u64 indexes[] = { 0x0ULL, 1ULL, 3ULL, 0x10ULL, ~0ULL,
				 0x8000000000000000ULL,
				 0xfffffffffffffff8ULL };
static const __u8 scales[] = { 0, 1, 2, 3, 5, 200 };
static const unsigned widths[] = { X86_WIDTH_8, X86_WIDTH_16, X86_WIDTH_32,
				   X86_WIDTH_64 };

int main(void)
{
	unsigned cases = 0, fails = 0;
	__u64 state = 0x51ce7b20a94d3f61ULL;

	/* Part 1: the offset contract over its encoded addressing modes. */
	for (unsigned s = 0; s < sizeof(scales) / sizeof(scales[0]); s++)
		for (unsigned i = 0; i < sizeof(disps) / sizeof(disps[0]); i++)
			for (unsigned j = 0;
			     j < sizeof(indexes) / sizeof(indexes[0]); j++) {
				fails += check_offset_encoded(3U, scales[s],
							      disps[i],
							      indexes[j]);
				fails += check_offset_encoded(X86_REG_NONE,
							      scales[s], disps[i],
							      indexes[j]);
				cases += 2;
			}

	for (unsigned iter = 0; iter < 20000; iter++) {
		__u64 disp, index;
		__u8 scale, index_reg;

		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		disp = state;
		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		index = state;
		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		scale = (__u8)(state & 0xffU);
		index_reg = (iter & 1U) ? 3U : X86_REG_NONE;
		fails += check_offset_encoded(index_reg, scale, disp, index);
		cases++;
	}

	/* Part 2: the LEA handler exits. */
	for (unsigned w = 0; w < sizeof(widths) / sizeof(widths[0]); w++)
		for (unsigned s = 0; s < sizeof(scales) / sizeof(scales[0]); s++)
			for (unsigned i = 0; i < sizeof(disps) / sizeof(disps[0]);
			     i++) {
				const __u8 src_regs[3] = { X86_REG_NONE, X86_RSP,
							   7U };

				for (unsigned k = 0; k < 3; k++) {
					fails += check_lea(src_regs[k],
							   0x1000ULL, 2U,
							   disps[i], 4U, scales[s],
							   9ULL, widths[w],
							   0xffffffffffff0000ULL,
							   6U, 0x7000ULL);
					cases++;
				}
				fails += check_lea_rodata(disps[i], widths[w],
							  0xffffffffffff0000ULL,
							  6U);
				cases++;
			}

	for (unsigned iter = 0; iter < 40000; iter++) {
		__u64 src_ptr, raw_imm, index, old, stack_base;
		__u8 src_reg, src_tag, index_reg, scale, old_tag;

		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		src_ptr = state;
		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		raw_imm = state;
		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		index = state;
		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		old = state;
		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		stack_base = state;
		src_reg = ((state >> 8) & 1U) ? X86_RSP :
			  (((state >> 9) & 1U) ? X86_REG_NONE : (__u8)7U);
		src_tag = (__u8)(state & 7U);
		index_reg = ((state >> 11) & 1U) ? 4U : X86_REG_NONE;
		scale = (__u8)(state & 0xffU);
		old_tag = (__u8)((state >> 24) & 7U);
		fails += check_lea(src_reg, src_ptr, src_tag, raw_imm, index_reg,
				   scale, index, widths[state % 4], old,
				   old_tag, stack_base);
		cases++;
	}

	if (fails) {
		printf("x86 LEA host cross-check: FAILED (%u mismatches)\n",
		       fails);
		return 1;
	}
	printf("x86 LEA host cross-check: OK (%u cases)\n", cases);
	return 0;
}
