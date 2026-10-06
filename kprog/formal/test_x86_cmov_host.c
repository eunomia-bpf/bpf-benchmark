/*
 * Host cross-check for the x86-64 `CMOV` / `CMOV_MEM` handler composition
 * (`X86_OP_CMOV`, `0x15`, and `X86_OP_CMOV_MEM`, `0x40`), the bodies
 * `X86_SIM_L_EXEC_CMOV` and `X86_SIM_L_EXEC_CMOV_MEM`.
 *
 * Part 1 verifies the condition sources against the raw codes: the 14-way
 * expression table, the register form's whole-word source (the 14 accepted
 * `X86_CC_*` words with bits 8..31 zero fold back to their own code and every
 * other word pins to the C default 0 of `KPROG_X86_EVAL_CC`), the
 * truncating byte source composed with `EVAL_CC`, and the memory form's
 * source-shift byte at bits 24..31.
 *
 * Part 2 verifies the generated writeback table KPROG_X86_CMOV_WRITEBACK:
 * a 64-bit resolved width selects the pointer-preserving write, every other
 * width selects the scalarizing partial-register write, cross-checked against
 * the resolved width KPROG_X86_CMOV_WIDTH.
 *
 * Part 3 drives the register form over a deterministic register file: it
 * resolves the width through the generated width macro, evaluates the
 * condition through the generated whole-word source and the real
 * KPROG_X86_EVAL_CC expression, and writes through the generated register
 * write contracts — the 64-bit arm as the pointer-preserving assignment,
 * the narrow arms through KPROG_X86_WRITE_REG{8,16,32}. Every byte and tag
 * of every register must match a hand-written model of the C body.
 *
 * Part 4 drives the memory form over a deterministic register, memory and
 * stack model: it decodes the condition through the generated source-shift
 * byte, resolves the two-level access width through the generated
 * KPROG_X86_CMOV_MEM_WIDTH, addresses through the generated offset and
 * displacement contracts, selects the value source through the generated
 * dispatch table, loads through the generated load, and writes back through
 * the generated register write contracts. Every result bit and the
 * destination's tag must match the hand-written model.
 *
 * The point of this oracle is the asymmetries the composition is about:
 * both forms are *conditional* (the whole body, value production included,
 * is inside the condition test, so a false condition leaves the destination
 * exactly as it was), the register form's condition is the whole AUX word
 * while the memory form's is the source-shift byte, and the 64-bit
 * writeback preserves the source's provenance tag only in the register form
 * — the memory form scalarizes through the partial-register write at every
 * width, because its C body writes through X86_SIM_L_WRITE_REG_WIDTH
 * unconditionally.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. test_x86_cmov_host.c -o /tmp/t_cmv && /tmp/t_cmv
 */
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;
typedef signed char __s8;
typedef short __s16;
typedef int __s32;
typedef signed long long __s64;

/* The generated headers define __always_inline functions in the kernel build;
 * provide the attribute for the host build. */
#ifndef __always_inline
#define __always_inline inline __attribute__((always_inline))
#endif

#define X86_WIDTH_8 1U
#define X86_WIDTH_16 2U
#define X86_WIDTH_32 4U
#define X86_WIDTH_64 8U

#define X86_REG_NONE 0xffU
#define X86_RSP 4U

#define X86_OP_CMOV 0x15U
#define X86_OP_CMOV_MEM 0x40U

#define X86_CC_O 0U
#define X86_CC_NO 1U
#define X86_CC_B 2U
#define X86_CC_AE 3U
#define X86_CC_E 4U
#define X86_CC_NE 5U
#define X86_CC_BE 6U
#define X86_CC_A 7U
#define X86_CC_S 8U
#define X86_CC_NS 9U
#define X86_CC_L 12U
#define X86_CC_GE 13U
#define X86_CC_LE 14U
#define X86_CC_G 15U

#define X86_SIM_TAG_SCALAR 0U
#define X86_SIM_TAG_ABI 1U
#define X86_SIM_TAG_PACKET 2U
#define X86_SIM_TAG_STACK 4U
#define X86_SIM_TAG_MAP_PTR 5U
#define X86_SIM_TAG_HELPER_ID 7U

/* Restate the addressing AUX decoders x86_sim.h defines, so the oracle
 * exercises the same encoding the sim uses. */
#define X86_MEM_AUX(INDEX, SCALE_LOG2)                                      \
	(((__u32)(INDEX) & 0xffU) | (((__u32)(SCALE_LOG2) & 0xffU) << 8))
#define X86_MEM_AUX_INDEX(AUX) ((__u8)((AUX) & 0xffU))
#define X86_MEM_AUX_SCALE_LOG2(AUX) ((__u8)(((AUX) >> 8) & 0xffU))
#define X86_MEM_AUX_MEM_WIDTH(AUX) ((__u8)(((AUX) >> 16) & 0xffU))
/* The condition field's own encoder, restated from x86_sim.h. */
#define X86_REG_AUX_SRC_SHIFT(SHIFT) (((__u32)(SHIFT) & 0xffU) << 24)

#include "generated/x86_cmov.h"
#include "generated/x86_cond.h"
#include "generated/x86_width.h"
#include "generated/x86_reg_read.h"
#include "generated/x86_reg_write.h"
#include "generated/x86_mem_offset.h"
#include "generated/x86_mem_access.h"
#include "generated/x86_mem_dispatch.h"

#include <stdint.h>
#include <stdio.h>
#include <string.h>

/* ------------------------------------------------------------------ */
/* A deterministic register file, memory and stack model.             */
/*                                                                    */
/* Registers carry a byte view, a 16-bit view and a pointer view over */
/* the same eight bytes plus the tag byte, the way the write helpers */
/* expect; register "pointers" are held as byte offsets that the      */
/* oracle reduces modulo the memory buffer so the model stays inside  */
/* the arrays at every address it forms.                              */
/* ------------------------------------------------------------------ */

#define ORACLE_REGS 16U
#define ORACLE_BYTES 4096
#define ORACLE_STACK_BYTES 64U

struct oracle_reg {
	union {
		__u8 b[8];
		__u16 w;
		void *ptr;
	} u;
	__u8 tag;
};

static struct oracle_reg oracle_regs[ORACLE_REGS];
static struct oracle_reg pristine_regs[ORACLE_REGS];
static struct oracle_reg result_regs[ORACLE_REGS];

static __u8 oracle_mem[ORACLE_BYTES];
static __u8 oracle_stack[ORACLE_STACK_BYTES];

static __u8 pristine_mem[ORACLE_BYTES];
static __u8 pristine_stack[ORACLE_STACK_BYTES];

static __u64 oracle_synthetic(__u64 index)
{
	return (__u8)((index * 131U + 17U) ^ (index >> 5));
}

static void oracle_reset(void)
{
	unsigned i;
	__u64 j;

	for (i = 0; i < ORACLE_REGS; i++) {
		oracle_regs[i].u.ptr =
			(void *)(long)(0x200ULL + (__u64)i * 0x20ULL);
		oracle_regs[i].tag = (__u8)(i % 6U);
	}
	for (j = 0; j < ORACLE_BYTES; j++)
		oracle_mem[j] = (__u8)oracle_synthetic(j);
	for (j = 0; j < ORACLE_STACK_BYTES; j++)
		oracle_stack[j] = (__u8)oracle_synthetic(j + 7U);
}

/* The reduction a stored effective address is folded through so the model
 * stays inside the memory array; the reduction leaves room for the widest
 * (8-byte) load or pointer read. Both paths share this convention; it is
 * not part of the contract under test. */
static unsigned oracle_slot(__u64 addr)
{
	return (unsigned)(addr % (ORACLE_BYTES - 8U));
}

static void oracle_snapshot_pristine(void)
{
	memcpy(pristine_regs, oracle_regs, sizeof(pristine_regs));
	memcpy(pristine_mem, oracle_mem, ORACLE_BYTES);
	memcpy(pristine_stack, oracle_stack, ORACLE_STACK_BYTES);
}

static void oracle_restore_pristine(void)
{
	memcpy(oracle_regs, pristine_regs, sizeof(pristine_regs));
	memcpy(oracle_mem, pristine_mem, ORACLE_BYTES);
	memcpy(oracle_stack, pristine_stack, ORACLE_STACK_BYTES);
}

/* ------------------------------------------------------------------ */
/* Hand-written models, independent of the macros under test.          */
/* ------------------------------------------------------------------ */

/* The width mask, restated from the raw codes rather than taken from the
 * generated x86_width.h. */
static __u64 oracle_mask(unsigned width)
{
	if (width == X86_WIDTH_8)
		return 0xffULL;
	if (width == X86_WIDTH_16)
		return 0xffffULL;
	if (width == X86_WIDTH_32)
		return 0xffffffffULL;
	return 0xffffffffffffffffULL;
}

/* The condition expression table, restated from the raw codes rather than
 * taken from the generated x86_cond.h. */
static __u8 oracle_eval_cc(__u8 cc, int cf, int zf, int sf, int of)
{
	switch (cc) {
	case X86_CC_O:
		return (__u8)of;
	case X86_CC_NO:
		return (__u8)!of;
	case X86_CC_B:
		return (__u8)cf;
	case X86_CC_AE:
		return (__u8)!cf;
	case X86_CC_E:
		return (__u8)zf;
	case X86_CC_NE:
		return (__u8)!zf;
	case X86_CC_BE:
		return (__u8)(cf || zf);
	case X86_CC_A:
		return (__u8)(!cf && !zf);
	case X86_CC_S:
		return (__u8)sf;
	case X86_CC_NS:
		return (__u8)!sf;
	case X86_CC_L:
		return (__u8)(sf != of);
	case X86_CC_GE:
		return (__u8)(sf == of);
	case X86_CC_LE:
		return (__u8)(zf || (sf != of));
	case X86_CC_G:
		return (__u8)(!zf && (sf == of));
	default:
		return 0U;
	}
}

/* The acceptance table, restated from the raw codes: exactly the 14
 * `X86_CC_*` codes are supported, everything else in the byte space
 * folds to 0. */
static int oracle_cc_supported(__u8 cc)
{
	return cc == X86_CC_O || cc == X86_CC_NO || cc == X86_CC_B ||
	       cc == X86_CC_AE || cc == X86_CC_E || cc == X86_CC_NE ||
	       cc == X86_CC_BE || cc == X86_CC_A || cc == X86_CC_S ||
	       cc == X86_CC_NS || cc == X86_CC_L || cc == X86_CC_GE ||
	       cc == X86_CC_LE || cc == X86_CC_G;
}

/* The ordinary little-endian load: exactly `width` bytes of the
 * width-masked value, least significant first. */
static __u64 oracle_load(__u64 addr, unsigned width)
{
	__u64 v = 0;
	unsigned i;

	for (i = 0; i < width; i++)
		v |= (__u64)oracle_mem[oracle_slot(addr) + i] << (8 * i);
	return v & oracle_mask(width);
}

/* The 8-byte pointer read the ABI arm performs. */
static __u64 oracle_ptr_load(__u64 addr)
{
	__u64 v = 0;
	unsigned i;

	for (i = 0; i < 8U; i++)
		v |= (__u64)oracle_mem[oracle_slot(addr) + i] << (8 * i);
	return v;
}

/* The stack helper's read, restated: the frame index is the stack-relative
 * offset biased by the frame size, and the value is width-masked and read
 * little-endian. */
static __u64 oracle_stack_load(__s64 off, unsigned width)
{
	__u32 index = (__u32)((__s64)off + ORACLE_STACK_BYTES);
	__u64 v = 0;
	unsigned i;

	for (i = 0; i < (width ? width : X86_WIDTH_64); i++)
		v |= (__u64)oracle_stack[(index + i) % ORACLE_STACK_BYTES]
		     << (8 * i);
	return v & oracle_mask(width ? width : X86_WIDTH_64);
}

/* The partial-register writeback the sim performs: 8- and 16-bit writes keep
 * the destination's upper bytes, a 32-bit write zeroes the upper half, and a
 * 64-bit write replaces the register. */
static __u64 oracle_write(__u64 old, __u64 value, unsigned width)
{
	if (width == X86_WIDTH_8)
		return (old & ~0xffULL) | (value & 0xffULL);
	if (width == X86_WIDTH_16)
		return (old & ~0xffffULL) | (value & 0xffffULL);
	if (width == X86_WIDTH_32)
		return value & 0xffffffffULL;
	return value;
}

/* The addressing offset, restated: the displacement, plus the scaled index
 * when the mode carries one. */
static __s64 oracle_mem_offset(__u32 aux, __s64 disp, __u64 index_value)
{
	__s64 off = disp;

	if (X86_MEM_AUX_INDEX(aux) != X86_REG_NONE)
		off += (__s64)(index_value << X86_MEM_AUX_SCALE_LOG2(aux));
	return off;
}

/* The base register the addressing mode names; a `NONE` base contributes the
 * null pointer and the default scalar tag, the way the sim's register-value
 * and register-tag switches fall through. */
static __u64 oracle_base_ptr(unsigned base)
{
	return base == X86_REG_NONE ? 0ULL
			: (__u64)(uintptr_t)oracle_regs[base].u.ptr;
}

static __u8 oracle_base_tag(unsigned base)
{
	return base == X86_REG_NONE ? X86_SIM_TAG_SCALAR
			: oracle_regs[base].tag;
}

/* ------------------------------------------------------------------ */
/* Part 1: the condition sources vs. the raw codes.                    */
/*                                                                    */
/* The register form's source is the whole-word table: the 14 accepted */
/* codes with bits 8..31 zero fold back to their own code and every   */
/* other word pins to the C default. The byte source is the           */
/* *truncating* model the C body does not actually take; composed with */
/* `EVAL_CC` it is the contrast the whole-word decode diverges from.  */
/* ------------------------------------------------------------------ */

static unsigned part1(void)
{
	static const __u8 accepted[14] = {
		X86_CC_O,  X86_CC_NO, X86_CC_B,  X86_CC_AE, X86_CC_E,
		X86_CC_NE, X86_CC_BE, X86_CC_A,  X86_CC_S,  X86_CC_NS,
		X86_CC_L,  X86_CC_GE, X86_CC_LE, X86_CC_G,
	};
	unsigned cases = 0;
	unsigned ci;
	unsigned f;
	unsigned hi;
	unsigned lo;
	unsigned cc;

	/* The 14-way expression table: each accepted code reproduces the raw
	 * KPROG_X86_EVAL_CC expression for all 16 flag combinations. */
	for (ci = 0; ci < 14U; ci++) {
		for (f = 0; f < 16U; f++) {
			__u8 raw =
				(__u8)KPROG_X86_EVAL_CC(
					accepted[ci], ((f >> 0) & 1U),
					((f >> 1) & 1U), ((f >> 2) & 1U),
					((f >> 3) & 1U));
			__u8 model = oracle_eval_cc(accepted[ci],
						    (f >> 0) & 1U,
						    (f >> 1) & 1U,
						    (f >> 2) & 1U,
						    (f >> 3) & 1U);

			if (raw != model) {
				fprintf(stderr,
					"cc expression mismatch "
					"cc=%u f=%u raw=%u model=%u\n",
					accepted[ci], f, raw, model);
				return 0;
			}
			cases++;
		}
	}

	/* The whole-word source over the rejected space: any word with bits
	 * 8..31 set pins to the default 0; so does an unsupported low byte.
	 * The composition through the identity source is what the register
	 * form actually evaluates. */
	for (hi = 0; hi < 256U; hi++) {
		for (lo = 0; lo < 256U; lo++) {
			__u32 word = (hi << 8) | lo;
			__u8 got =
				(__u8)KPROG_X86_EVAL_CC(
					KPROG_X86_CMOV_CONDITION(word),
					1, 1, 1, 1);
			__u8 want = 0U;

			if (hi == 0 && oracle_cc_supported((__u8)lo))
				want = oracle_eval_cc(lo, 1, 1, 1, 1);
			if (got != want) {
				fprintf(stderr,
					"word source mismatch word=%08x "
					"got=%u want=%u\n",
					word, got, want);
				return 0;
			}
			cases++;
		}
	}

	/* The truncating byte source, composed with `EVAL_CC`: accepted
	 * codes fold back to their own expression, unsupported codes to the
	 * C default 0. */
	for (cc = 0; cc < 256U; cc++) {
		for (f = 0; f < 16U; f++) {
			__u8 got =
				(__u8)KPROG_X86_EVAL_CC(
					KPROG_X86_CMOV_CONDITION_BYTE(cc),
					((f >> 0) & 1U), ((f >> 1) & 1U),
					((f >> 2) & 1U), ((f >> 3) & 1U));
			__u8 want = oracle_cc_supported((__u8)cc)
						? oracle_eval_cc(
							cc, (f >> 0) & 1U,
							(f >> 1) & 1U,
							(f >> 2) & 1U,
							(f >> 3) & 1U)
						: 0U;

			if (got != want) {
				fprintf(stderr,
					"byte source mismatch cc=%u "
					"f=%u got=%u want=%u\n",
					cc, f, got, want);
				return 0;
			}
			cases++;
		}
	}

	/* The memory form's source-shift byte is the field at bits 24..31. */
	for (cc = 0; cc < 256U; cc++) {
		__u32 aux = X86_REG_AUX_SRC_SHIFT(cc);
		__u8 got = KPROG_X86_CMOV_MEM_CONDITION(aux);

		if (got != cc) {
			fprintf(stderr,
				"mem condition mismatch aux=%08x "
				"got=%u want=%u\n",
				aux, got, cc);
			return 0;
		}
		cases++;
	}

	return cases;
}

/* ------------------------------------------------------------------ */
/* Part 2: the generated writeback table vs. the oracle.              */
/* ------------------------------------------------------------------ */

static unsigned part2(void)
{
	static const __u8 codes[6] = { 0U, X86_WIDTH_8, X86_WIDTH_16,
				       X86_WIDTH_32, X86_WIDTH_64, 9U };
	unsigned cases = 0;
	unsigned fi;

	for (fi = 0; fi < 6U; fi++) {
		__u8 flags = codes[fi];
		__u8 width = KPROG_X86_CMOV_WIDTH(flags);
		__u8 want = (width == X86_WIDTH_64)
				? KPROG_X86_CMOV_WRITEBACK_POINTER_TAG
				: KPROG_X86_CMOV_WRITEBACK_SCALARIZE;
		__u8 got;

		if (width != (flags ? flags : X86_WIDTH_64)) {
			fprintf(stderr, "width mismatch flags=%u got=%u\n",
				flags, width);
			return 0;
		}
		got = KPROG_X86_CMOV_WRITEBACK(width == X86_WIDTH_64);
		if (got != want) {
			fprintf(stderr,
				"writeback mismatch flags=%u width=%u "
				"got=%u want=%u\n",
				flags, width, got, want);
			return 0;
		}
		cases++;
	}
	return cases;
}

/* ------------------------------------------------------------------ */
/* Part 3: the register-form handler composition vs. the hand-written */
/* body. `contract_step` resolves, evaluates and writes through the   */
/* generated contracts; `model_step` restates the body from the raw   */
/* fields. They must agree byte for byte in every register, tag      */
/* included.                                                          */
/*                                                                    */
/* The width code is the FLAGS register, independent of the flag     */
/* nibble that carries the cf/zf/sf/of bits.                          */
/* ------------------------------------------------------------------ */

struct cmov_reg_effect {
	__u8 cond;
	__u8 width;
	__u64 dst;
	__u8 dst_tag;
};

/* flag_nibble is a nibble: bit 0 = cf, bit 1 = zf, bit 2 = sf, bit 3 = of. */
static struct cmov_reg_effect contract_step_reg(unsigned dst, unsigned src,
						__u32 aux, __u8 flag_nibble,
						__u8 width_code)
{
	__u8 width = KPROG_X86_CMOV_WIDTH(width_code);
	__u8 cond = (__u8)KPROG_X86_EVAL_CC(
		KPROG_X86_CMOV_CONDITION(aux), ((flag_nibble >> 0) & 1U),
		((flag_nibble >> 1) & 1U), ((flag_nibble >> 2) & 1U),
		((flag_nibble >> 3) & 1U));
	struct cmov_reg_effect r = {0};

	r.width = width;
	r.cond = cond;
	if (cond) {
		__u64 src_val = (__u64)(uintptr_t)oracle_regs[src].u.ptr;

		if (width == X86_WIDTH_64) {
			/* The 64-bit arm: the destination receives the
			 * source pointer and its provenance tag verbatim,
			 * the sim-local pointer-tag write. */
			oracle_regs[dst].u.ptr = oracle_regs[src].u.ptr;
			oracle_regs[dst].tag = oracle_regs[src].tag;
		} else {
			/* The narrow arms: the source is read at 64 bits and
			 * written through the scalarizing partial-register
			 * write. */
			__u64 value = KPROG_X86_READ_REG_AT(src_val,
					X86_WIDTH_64, 0U);

			if (width == X86_WIDTH_8)
				KPROG_X86_WRITE_REG8(oracle_regs[dst].u,
						oracle_regs[dst].tag,
						value, 0U,
						X86_SIM_TAG_SCALAR);
			else if (width == X86_WIDTH_16)
				KPROG_X86_WRITE_REG16(oracle_regs[dst].u,
						oracle_regs[dst].tag,
						value,
						X86_SIM_TAG_SCALAR);
			else
				KPROG_X86_WRITE_REG32(oracle_regs[dst].u,
						oracle_regs[dst].tag,
						value,
						X86_SIM_TAG_SCALAR);
		}
	}
	r.dst = (__u64)(uintptr_t)oracle_regs[dst].u.ptr;
	r.dst_tag = oracle_regs[dst].tag;
	return r;
}

static struct cmov_reg_effect model_step_reg(unsigned dst, unsigned src,
					     __u32 aux, __u8 flag_nibble,
					     __u8 width_code)
{
	__u8 width = width_code ? width_code : X86_WIDTH_64;
	__u8 cond;
	__u64 src_val =
		(__u64)(uintptr_t)oracle_regs[src].u.ptr;
	__u64 old = (__u64)(uintptr_t)oracle_regs[dst].u.ptr;
	struct cmov_reg_effect r = {0};

	/* The register form's condition is the whole AUX word: accepted
	 * codes with bits 8..31 zero fold back to the 14 `X86_CC_*`
	 * codes; every word with bits 8..31 set, or a low byte outside
	 * the accepted subset, pins to the C default 0. */
	if ((aux & ~0xffU) == 0U &&
	    oracle_cc_supported((__u8)aux))
		cond = oracle_eval_cc((__u8)aux, (flag_nibble >> 0) & 1U,
				      (flag_nibble >> 1) & 1U,
				      (flag_nibble >> 2) & 1U,
				      (flag_nibble >> 3) & 1U);
	else
		cond = 0U;

	r.width = width;
	r.cond = cond;
	if (cond) {
		if (width == X86_WIDTH_64) {
			oracle_regs[dst].u.ptr = oracle_regs[src].u.ptr;
			oracle_regs[dst].tag = oracle_regs[src].tag;
		} else {
			oracle_regs[dst].u.ptr =
				(void *)(long)oracle_write(old, src_val,
							   width);
			oracle_regs[dst].tag = X86_SIM_TAG_SCALAR;
		}
	}
	r.dst = (__u64)(uintptr_t)oracle_regs[dst].u.ptr;
	r.dst_tag = oracle_regs[dst].tag;
	return r;
}

static unsigned part3(void)
{
	static const __u8 accepted[14] = {
		X86_CC_O,  X86_CC_NO, X86_CC_B,  X86_CC_AE, X86_CC_E,
		X86_CC_NE, X86_CC_BE, X86_CC_A,  X86_CC_S,  X86_CC_NS,
		X86_CC_L,  X86_CC_GE, X86_CC_LE, X86_CC_G,
	};
	static const __u32 hights[3] = { 0U, 1U, 0xffU };
	static const __u8 width_codes[5] = { 0U, X86_WIDTH_8, X86_WIDTH_16,
					      X86_WIDTH_32, X86_WIDTH_64 };
	static const unsigned dsts[3] = { 0U, X86_RSP, 8U };
	static const unsigned srcs[3] = { 1U, 3U, 7U };
	unsigned cases = 0;
	unsigned di;
	unsigned si;
	unsigned ai;
	unsigned hi;
	unsigned fi;
	unsigned flags;

	for (di = 0; di < 3U; di++) {
		for (si = 0; si < 3U; si++) {
			for (ai = 0; ai < 14U; ai++) {
				for (hi = 0; hi < 3U; hi++) {
					for (fi = 0; fi < 5U; fi++) {
						__u32 aux =
							(hights[hi] << 8) |
							accepted[ai];

						for (flags = 0; flags < 16U;
						     flags++) {
							struct cmov_reg_effect
								got;
							struct cmov_reg_effect
								want;

							oracle_restore_pristine();
							got =
								contract_step_reg(
									dsts[di],
									srcs[si],
									aux,
									(__u8)flags,
									width_codes[fi]);
							memcpy(result_regs,
							       oracle_regs,
							       sizeof(oracle_regs));
							oracle_restore_pristine();
							want = model_step_reg(
								dsts[di],
								srcs[si],
								aux,
								(__u8)flags,
								width_codes[fi]);
							if (got.cond !=
							    want.cond ||
							    got.width !=
							    want.width ||
							    got.dst !=
							    want.dst ||
							    got.dst_tag !=
							    want.dst_tag ||
							    memcmp(result_regs,
								   oracle_regs,
								   sizeof(oracle_regs))) {
								fprintf(stderr,
									"reg handler mismatch "
									"dst=%u src=%u "
									"aux=%08x flags=%u "
									"wcode=%u "
									"got=(%u,%u,%llx,%u) "
									"want=(%u,%u,%llx,%u)\n",
									dsts[di],
									srcs[si],
									aux,
									(unsigned)flags,
									width_codes[fi],
									got.cond,
									got.width,
									(unsigned long long)got.dst,
									got.dst_tag,
									want.cond,
									want.width,
									(unsigned long long)want.dst,
									want.dst_tag);
								return 0;
							}
							cases++;
						}
					}
				}
			}
		}
	}
	return cases;
}

/* ------------------------------------------------------------------ */
/* Part 4: the memory-form handler composition vs. the hand-written   */
/* body. `contract_step_mem` decodes, addresses, dispatches, loads and*/
/* writes through the generated contracts; `model_step_mem` restates  */
/* the body from the raw fields. The handler writes only the          */
/* destination register, so the registers are the state compared;    */
/* memory and stack are read-only inputs.                             */
/* ------------------------------------------------------------------ */

struct cmov_mem_effect {
	__u8 cond;
	__u8 width;
	__u8 mem_width;
	__u64 value;
	__u64 dst;
	__u8 dst_tag;
};

static struct cmov_mem_effect contract_step_mem(unsigned dst, unsigned base,
						__u32 aux, __u8 flag_nibble,
						__u8 width_code,
						__u64 imm,
						__u64 index_value)
{
	__u8 cc = KPROG_X86_CMOV_MEM_CONDITION(aux);
	__u8 cond = (__u8)KPROG_X86_EVAL_CC(cc, ((flag_nibble >> 0) & 1U),
					     ((flag_nibble >> 1) & 1U),
					     ((flag_nibble >> 2) & 1U),
					     ((flag_nibble >> 3) & 1U));
	__u8 width = KPROG_X86_CMOV_WIDTH(width_code);
	__u8 mem_width = KPROG_X86_CMOV_MEM_WIDTH(aux, width_code);
	struct cmov_mem_effect r = {0};

	r.cond = cond;
	r.width = width;
	r.mem_width = mem_width;
	if (cond) {
		__u8 eff = mem_width ? mem_width : X86_WIDTH_64;
		__s64 disp = KPROG_X86_CMOV_MEM_DISP(imm);
		__u8 src_code = KPROG_X86_MEM_READ_SRC(
			(base == X86_RSP), oracle_base_tag(base), eff);
		__u64 base_ptr = oracle_base_ptr(base);
		__s64 off = KPROG_X86_MEM_OFFSET(
			aux, disp, index_value,
			X86_MEM_AUX_INDEX(aux) != X86_REG_NONE);
		__u64 addr = base_ptr + (__u64)off;
		__u64 value;

		if (src_code == KPROG_X86_MEM_SRC_STACK)
			value = oracle_stack_load(
				(__s64)base_ptr + off, eff);
		else if (src_code == KPROG_X86_MEM_SRC_ABI_PTR_LOAD)
			value = KPROG_X86_MEM_LOAD(
				&oracle_mem[oracle_slot(addr)], eff);
		else
			value = KPROG_X86_MEM_LOAD(
				&oracle_mem[oracle_slot(addr)], eff);

		/* The memory form writes through the partial-register
		 * write at every width, including the 64-bit one:
		 * unconditionally scalarizing, unlike the register
		 * form's pointer-preserving 64-bit arm. */
		if (width == X86_WIDTH_8)
			KPROG_X86_WRITE_REG8(oracle_regs[dst].u,
					oracle_regs[dst].tag, value, 0U,
					X86_SIM_TAG_SCALAR);
		else if (width == X86_WIDTH_16)
			KPROG_X86_WRITE_REG16(oracle_regs[dst].u,
					oracle_regs[dst].tag, value,
					X86_SIM_TAG_SCALAR);
		else if (width == X86_WIDTH_32)
			KPROG_X86_WRITE_REG32(oracle_regs[dst].u,
					oracle_regs[dst].tag, value,
					X86_SIM_TAG_SCALAR);
		else
			KPROG_X86_WRITE_REG64(oracle_regs[dst].u,
					oracle_regs[dst].tag, value,
					X86_SIM_TAG_SCALAR);
		r.value = value;
	}
	r.dst = (__u64)(uintptr_t)oracle_regs[dst].u.ptr;
	r.dst_tag = oracle_regs[dst].tag;
	return r;
}

static struct cmov_mem_effect model_step_mem(unsigned dst, unsigned base,
					     __u32 aux, __u8 flag_nibble,
					     __u8 width_code, __u64 imm,
					     __u64 index_value)
{
	__u8 cc = (__u8)((aux >> 24) & 0xffU);
	__u8 cond = oracle_cc_supported(cc) ?
		oracle_eval_cc(cc, (flag_nibble >> 0) & 1U,
			       (flag_nibble >> 1) & 1U,
			       (flag_nibble >> 2) & 1U,
			       (flag_nibble >> 3) & 1U) : 0U;
	__u8 width = width_code ? width_code : X86_WIDTH_64;
	__u8 mem_width = X86_MEM_AUX_MEM_WIDTH(aux) ?
		X86_MEM_AUX_MEM_WIDTH(aux) : width;
	__s64 disp = (__s64)(__s32)(imm >> 32);
	__s64 off;
	__u64 base_ptr = oracle_base_ptr(base);
	__u64 value = 0;
	__u64 old;
	struct cmov_mem_effect r = {0};

	off = oracle_mem_offset(aux, disp, index_value);

	r.cond = cond;
	r.width = width;
	r.mem_width = mem_width;
	if (!cond) {
		r.dst = (__u64)(uintptr_t)oracle_regs[dst].u.ptr;
		r.dst_tag = oracle_regs[dst].tag;
		return r;
	}

	{
		__u8 eff = mem_width ? mem_width : X86_WIDTH_64;
		__u64 addr = base_ptr + (__u64)off;

		if (base == X86_RSP)
			value = oracle_stack_load((__s64)base_ptr + off,
						 eff);
		else if (oracle_base_tag(base) == X86_SIM_TAG_ABI &&
			 eff == X86_WIDTH_64)
			value = oracle_ptr_load(addr);
		else
			value = oracle_load(addr, eff);
	}
	old = (__u64)(uintptr_t)oracle_regs[dst].u.ptr;
	/* The memory form scalarizes at every width. */
	oracle_regs[dst].u.ptr =
		(void *)(long)oracle_write(old, value, width);
	oracle_regs[dst].tag = X86_SIM_TAG_SCALAR;
	r.value = value;
	r.dst = (__u64)(uintptr_t)oracle_regs[dst].u.ptr;
	r.dst_tag = X86_SIM_TAG_SCALAR;
	return r;
}

static unsigned part4(void)
{
	static const __u8 cc_bytes[5] = { 0U, X86_CC_E, X86_CC_NE,
					  X86_CC_LE, X86_CC_LE + 1U };
	static const __u8 mem_widths[5] = { 0U, X86_WIDTH_8, X86_WIDTH_16,
					    X86_WIDTH_32, X86_WIDTH_64 };
	static const __u8 width_codes[5] = { 0U, X86_WIDTH_8, X86_WIDTH_16,
					     X86_WIDTH_32, X86_WIDTH_64 };
	static const __u64 imms[3] = {
		0x1234001000000008ULL,
		0x0000000000000010ULL,
		0xffffffff00000008ULL,
	};
	static const unsigned bases[4] = { 1U, 2U, X86_RSP, X86_REG_NONE };
	static const __u8 base_tags[4] = { X86_SIM_TAG_SCALAR, X86_SIM_TAG_ABI,
		X86_SIM_TAG_STACK, X86_SIM_TAG_MAP_PTR };
	static const __u8 index_regs[2] = { X86_REG_NONE, 3U };
	static const __u8 scales[2] = { 0U, 1U };
	static const unsigned dst = 5U;
	unsigned cases = 0;
	unsigned bi;
	unsigned ti;
	unsigned ci;
	unsigned mi;
	unsigned fi;
	unsigned di;
	unsigned ii;
	unsigned sc;
	unsigned flags;

	for (bi = 0; bi < 4U; bi++) {
		for (ti = 0; ti < 4U; ti++) {
			for (ci = 0; ci < 5U; ci++) {
				for (mi = 0; mi < 5U; mi++) {
					for (fi = 0; fi < 5U; fi++) {
						for (di = 0; di < 3U;
						     di++) {
							for (ii = 0;
							     ii < 2U; ii++) {
								for (sc = 0;
								     sc < 2U; sc++) {
									__u32 aux =
										X86_REG_AUX_SRC_SHIFT(
											cc_bytes[ci]) |
										((__u32)mem_widths[mi]
										 << 16) |
										(index_regs[ii] ==
										 X86_REG_NONE ?
										 X86_MEM_AUX(X86_REG_NONE,
											 0U) :
										 X86_MEM_AUX(index_regs[ii],
											 scales[sc]));
									__u64 index_value =
										0x1111111100000005ULL;
									struct cmov_mem_effect got;
									struct cmov_mem_effect want;

									for (flags = 0; flags < 16U;
										 flags++) {
										oracle_restore_pristine();
										if (bi != 3U)
											oracle_regs
											 [bases[bi]].tag =
											base_tags[ti];
										got =
											contract_step_mem(
												dst,
												bases[bi],
												aux,
												(__u8)flags,
												width_codes[fi],
												imms[di],
												index_value);
										memcpy(result_regs,
											   oracle_regs,
											   sizeof(oracle_regs));
										oracle_restore_pristine();
										if (bi != 3U)
											oracle_regs
											 [bases[bi]].tag =
											base_tags[ti];
										want = model_step_mem(
											dst, bases[bi],
											aux,
											(__u8)flags,
											width_codes[fi],
											imms[di],
											index_value);
										if (got.cond !=
										    want.cond ||
										    got.width !=
										    want.width ||
										    got.mem_width !=
										    want.mem_width ||
										    got.value !=
										    want.value ||
										    got.dst !=
										    want.dst ||
										    got.dst_tag !=
										    want.dst_tag ||
										    memcmp(result_regs,
											   oracle_regs,
											   sizeof(oracle_regs))) {
											fprintf(stderr,
												"mem handler "
												"mismatch "
												"base=%u "
												"tag=%u "
												"cc=%u "
												"memw=%u "
												"wcode=%u "
												"imm=%llx "
												"idx=%u "
												"scale=%u "
												"f=%u "
												"got=(%u,"
												"%u,%u,%llx,"
												"%llx,%u) "
												"want=(%u,"
												"%u,%u,%llx,"
												"%llx,%u)\n",
												bases[bi],
												base_tags[ti],
												cc_bytes[ci],
												(unsigned)mem_widths[mi],
												width_codes[fi],
												(unsigned long long)imms[di],
												(unsigned)index_regs[ii],
												scales[sc],
												(unsigned)flags,
												got.cond,
												got.width,
												got.mem_width,
												(unsigned long long)got.value,
												(unsigned long long)got.dst,
												got.dst_tag,
												want.cond,
												want.width,
												want.mem_width,
												(unsigned long long)want.value,
												(unsigned long long)want.dst,
												want.dst_tag);
											return 0;
										}
										cases++;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return cases;
}

/* ------------------------------------------------------------------ */
/* Part 5: pins on the asymmetries the composition is about.          */
/* ------------------------------------------------------------------ */

static unsigned part5(void)
{
	unsigned cases = 0;

	/* Pin 1: a false condition writes nothing, register form — the
	 * destination's bits and tag are exactly untouched at every
	 * width. `e` on a clear zero flag is false. */
	{
		static const __u8 width_codes[4] = { X86_WIDTH_8,
						      X86_WIDTH_16,
						      X86_WIDTH_32,
						      X86_WIDTH_64 };
		unsigned wi;

		for (wi = 0; wi < 4U; wi++) {
			oracle_restore_pristine();
			(void)contract_step_reg(0, 3U, X86_CC_E, 0U,
						 width_codes[wi]);
			if (memcmp(&oracle_regs[0], &pristine_regs[0],
				   sizeof(struct oracle_reg)))
				return 0;
			cases++;
		}
	}

	/* Pin 2: a false condition writes nothing, memory form. */
	{
		oracle_restore_pristine();
		(void)contract_step_mem(5U, 2U,
			X86_REG_AUX_SRC_SHIFT(X86_CC_E) |
			((__u32)X86_WIDTH_64 << 16), 0U, X86_WIDTH_64,
			0x0000000000000010ULL, 0U);
		if (memcmp(&oracle_regs[5U], &pristine_regs[5U],
			   sizeof(struct oracle_reg)))
			return 0;
		cases++;
	}

	/* Pin 3: the 64-bit register-form arm preserves the source's
	 * provenance tag — the destination tag becomes the source tag,
	 * whatever the destination held before. */
	{
		oracle_restore_pristine();
		oracle_regs[3U].tag = X86_SIM_TAG_MAP_PTR;
		oracle_regs[0].tag = X86_SIM_TAG_SCALAR;
		(void)contract_step_reg(0, 3U, X86_CC_E, 0x2U,
					X86_WIDTH_64);
		if (oracle_regs[0].tag != X86_SIM_TAG_MAP_PTR ||
		    oracle_regs[0].u.ptr != oracle_regs[3].u.ptr)
			return 0;
		cases++;
	}

	/* Pin 4: the same condition and width through the memory form
	 * scalarizes the destination — the asymmetry the C body's
	 * unconditional X86_SIM_L_WRITE_REG_WIDTH forces. */
	{
		oracle_restore_pristine();
		oracle_regs[3U].tag = X86_SIM_TAG_MAP_PTR;
		oracle_regs[0].tag = X86_SIM_TAG_MAP_PTR;
		(void)contract_step_mem(0, 3U,
			X86_REG_AUX_SRC_SHIFT(X86_CC_E) |
			((__u32)X86_WIDTH_64 << 16), 0x2U, X86_WIDTH_64,
			0x0000000000000000ULL, 0U);
		if (oracle_regs[0].tag != X86_SIM_TAG_SCALAR)
			return 0;
		cases++;
	}

	/* Pin 5: the register form's whole-word decode and the byte decode
	 * diverge on words with bits 8..31 set: the word table pins to the
	 * C default false, while the byte table would accept the same low
	 * byte. */
	{
		__u32 word = 0x00000105U;
		__u8 whole =
			(__u8)KPROG_X86_EVAL_CC(
				KPROG_X86_CMOV_CONDITION(word),
				0, 0, 0, 0);
		__u8 low =
			(__u8)KPROG_X86_EVAL_CC(
				KPROG_X86_CMOV_CONDITION_BYTE(word),
				0, 0, 0, 0);

		if (whole != 0U || low != 1U || whole == low)
			return 0;
		cases++;
	}

	/* Pin 6: the memory form's condition is the source-shift byte at
	 * bits 24..31, not the low byte the register form reads.
	 * `0x05000004` decodes `ne`, and the low byte `0x04` is `e`, so
	 * the two reads diverge on the same word. */
	{
		__u32 aux = 0x05000004U;
		__u8 mem_cond = KPROG_X86_CMOV_MEM_CONDITION(aux);
		__u8 low = KPROG_X86_CMOV_CONDITION_BYTE(aux);
		__u8 mem_val =
			(__u8)KPROG_X86_EVAL_CC(mem_cond, 0, 1, 0, 0);
		__u8 low_val =
			(__u8)KPROG_X86_EVAL_CC(low, 0, 1, 0, 0);

		if (mem_cond != X86_CC_NE || low != X86_CC_E ||
		    mem_val == low_val)
			return 0;
		cases++;
	}

	/* Pin 7: the memory form's two-level access-width fallback: a
	 * present memory-width byte wins over the width code, and an
	 * absent one falls back to the resolved write width. */
	{
		__u32 aux_present =
			X86_REG_AUX_SRC_SHIFT(X86_CC_E) |
			((__u32)X86_WIDTH_16 << 16);
		__u32 aux_absent = X86_REG_AUX_SRC_SHIFT(X86_CC_E);
		__u8 got_present = KPROG_X86_CMOV_MEM_WIDTH(aux_present,
							 X86_WIDTH_8);
		__u8 got_absent = KPROG_X86_CMOV_MEM_WIDTH(aux_absent,
							    X86_WIDTH_32);

		if (got_present != X86_WIDTH_16 ||
		    got_absent != X86_WIDTH_32)
			return 0;
		cases++;
	}

	/* Pin 8: the memory form's displacement is the high half of the
	 * instruction artifact sign-extended into 64 bits — not the whole
	 * artifact the ordinary store consumes. */
	{
		__s64 got = KPROG_X86_CMOV_MEM_DISP(0x1234001000000008ULL);
		__s64 whole = (__s64)0x1234001000000008ULL;

		if (got != (__s64)0x12340010 || got == whole)
			return 0;
		cases++;
	}

	return cases;
}

int main(void)
{
	unsigned p1, p2, p3, p4, p5;

	oracle_reset();
	oracle_snapshot_pristine();

	p1 = part1();
	if (!p1) {
		fprintf(stderr, "part 1 failed\n");
		return 1;
	}
	p2 = part2();
	if (!p2) {
		fprintf(stderr, "part 2 failed\n");
		return 1;
	}
	p3 = part3();
	if (!p3) {
		fprintf(stderr, "part 3 failed\n");
		return 1;
	}
	p4 = part4();
	if (!p4) {
		fprintf(stderr, "part 4 failed\n");
		return 1;
	}
	p5 = part5();
	if (!p5) {
		fprintf(stderr, "part 5 failed\n");
		return 1;
	}

	printf("x86 cmov handler host cross-check: OK (%u cases)\n",
	       p1 + p2 + p3 + p4 + p5);
	return 0;
}
