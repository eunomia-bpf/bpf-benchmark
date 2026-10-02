/*
 * Host cross-check for the x86-64 `CMP_IMM` / `CMP_REG` / `TEST_IMM` /
 * `TEST_REG` handler contract.
 *
 * The module under test is `generated/x86_cmpop.h`. It fixes the one width the
 * bodies resolve (`FLAGS ? FLAGS : 64`) and the two per-opcode facts that
 * separate the four opcodes served by the two `X86_SIM_L_EXEC_CMP_{IMM,REG}_OP`
 * bodies:
 *
 *   * where the right-hand side comes from — the decoded immediate for
 *     `CMP_IMM`/`TEST_IMM`, the width/lane register read of `SRC` for
 *     `CMP_REG`/`TEST_REG`;
 *   * which flags are produced — the zero-borrow subtraction flags for the
 *     `CMP` opcodes, the logical flags of the width-narrowed conjunction for
 *     the `TEST` opcodes.
 *
 * Neither body writes a register. The destination lane is read through the
 * width/lane register read (`X86_SIM_L_READ_REG_WIDTH_SHIFT`, driven by the AUX
 * destination-shift field) and the `_REG` right-hand side through the AUX
 * source-shift field.
 *
 * The two C bodies restate this logic inline and the generated header is not on
 * their include path, so this host cross-check is the tie between the two: it
 * drives the contract through the generated macros and restates the same bodies
 * from the raw opcode, and the two must agree on the resolved width, both
 * operands, all four flags, every register (none written), and memory (none
 * written).
 *
 * The value-producing helpers the bodies use (`X86_SIM_L_READ_REG_WIDTH_SHIFT`,
 * `KPROG_X86_READ_REG_AT`, `x86_store_imm_value`, the width masks, and the
 * subtraction/logical flag production) are hand-modelled here.
 */
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;
typedef signed char __s8;
typedef short __s16;
typedef int __s32;
typedef signed long long __s64;

#ifndef __always_inline
#define __always_inline inline __attribute__((always_inline))
#endif

#define X86_RAX 0U
#define X86_RCX 1U
#define X86_RDX 2U
#define X86_RBX 3U
#define X86_RSI 6U
#define X86_RDI 7U
#define X86_REG_NONE 0xffU

#define X86_OP_CMP_IMM 0x0cU
#define X86_OP_CMP_REG 0x0dU
#define X86_OP_TEST_IMM 0x0eU
#define X86_OP_TEST_REG 0x0fU

#define X86_SIM_TAG_SCALAR 0U

#include "generated/x86_cmpop.h"
#include "generated/x86_width.h"
#include "generated/x86_immediate.h"
#include "generated/x86_reg_read.h"
#include "generated/x86_sub_flags.h"
#include "generated/x86_logic_flags.h"
#include "generated/x86_sbb_result.h"

#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define ORACLE_CODES 5U
#define ORACLE_LANES 2U

#define ORACLE_REGS 16U
#define ORACLE_MEM_BYTES 4096U

struct oracle_reg {
	union {
		__u8 b[8];
		__u16 w;
		__u32 l;
		__u64 q;
		void *ptr;
	} u;
	__u8 tag;
};

static struct oracle_reg oracle_regs[ORACLE_REGS];
static struct oracle_reg pristine_regs[ORACLE_REGS];
static struct oracle_reg result_regs[ORACLE_REGS];

static __u8 oracle_mem[ORACLE_MEM_BYTES];
static __u8 pristine_mem[ORACLE_MEM_BYTES];
static __u8 result_mem[ORACLE_MEM_BYTES];

static __u8 oracle_synthetic(__u64 index)
{
	return (__u8)((index * 131U + 17U) ^ (index >> 5));
}

static void oracle_reset(void)
{
	unsigned i;
	__u64 j;

	for (i = 0; i < ORACLE_REGS; i++) {
		oracle_regs[i].u.ptr =
			(void *)(long)(0x2a00ULL + (__u64)i * 0x20ULL);
		oracle_regs[i].tag = (__u8)(i % 6U);
	}
	for (j = 0; j < ORACLE_MEM_BYTES; j++)
		oracle_mem[j] = (__u8)oracle_synthetic(j + 7U);
}

static void oracle_snapshot_pristine(void)
{
	memcpy(pristine_regs, oracle_regs, sizeof(pristine_regs));
	memcpy(pristine_mem, oracle_mem, ORACLE_MEM_BYTES);
}

static void oracle_restore_pristine(void)
{
	memcpy(oracle_regs, pristine_regs, sizeof(pristine_regs));
	memcpy(oracle_mem, pristine_mem, ORACLE_MEM_BYTES);
}

static __u64 oracle_reg_value(unsigned index)
{
	return (__u64)(uintptr_t)oracle_regs[index].u.ptr;
}

/* ------------------------------------------------------------------ */
/* Hand-written models, independent of the macros under test.          */
/* ------------------------------------------------------------------ */

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

static unsigned oracle_bits(unsigned width)
{
	if (width == X86_WIDTH_8)
		return 8U;
	if (width == X86_WIDTH_16)
		return 16U;
	if (width == X86_WIDTH_32)
		return 32U;
	return 64U;
}

static __u64 oracle_sign_mask(unsigned width)
{
	return 1ULL << (oracle_bits(width) - 1U);
}

/* The width/lane register read the bodies perform: an 8-bit read shifts by the
 * byte-lane offset first, every wider read ignores the lane and narrows to its
 * own width. Restated independently of generated x86_reg_read.h. */
static __u64 oracle_read_reg_at(__u64 value, unsigned width, unsigned lane)
{
	__u64 shifted = width == X86_WIDTH_8 ? value >> lane : value;

	return shifted & oracle_mask(width);
}

/* The immediate widening the `_IMM` bodies' `x86_store_imm_value((IMM),
 * width)` performs: the low 32 bits, sign-extended only under the 64-bit
 * width. */
static __u64 oracle_imm_value(__u64 value, unsigned width)
{
	if (width == X86_WIDTH_64 && (value & 0x80000000ULL) != 0ULL)
		return (value & 0xffffffffULL) | 0xffffffff00000000ULL;
	return value & 0xffffffffULL;
}

static void oracle_sub_flags(__u64 lhs, __u64 rhs, __u64 result, unsigned width,
			     __u8 *cf, __u8 *zf, __u8 *sf, __u8 *of)
{
	__u64 mask = oracle_mask(width);
	__u64 sign = oracle_sign_mask(width);
	__u64 a = lhs & mask;
	__u64 b = rhs & mask;
	__u64 r = result & mask;

	*cf = (__u8)(a < b);
	*zf = (__u8)(a == b);
	*sf = (__u8)((r & sign) != 0);
	*of = (__u8)(((a ^ b) & ((a ^ r) & sign)) != 0);
}

static void oracle_logic_flags(__u64 conjunction, unsigned width,
			       __u8 *cf, __u8 *zf, __u8 *sf, __u8 *of)
{
	__u64 value = conjunction & oracle_mask(width);

	*cf = 0U;
	*zf = (__u8)(value == 0);
	*sf = (__u8)((value >> (oracle_bits(width) - 1U)) & 1U);
	*of = 0U;
}

/* ------------------------------------------------------------------ */
/* Part 1: the generated tables vs. the oracle.                       */
/* ------------------------------------------------------------------ */

static unsigned part1(void)
{
	static const unsigned codes[ORACLE_CODES] = { 0U, X86_WIDTH_8, X86_WIDTH_16,
						      X86_WIDTH_32, X86_WIDTH_64 };
	unsigned cases = 0;
	unsigned ci;

	if (KPROG_X86_CMPOP_WRITE_WIDTH_DEFAULT != X86_WIDTH_64) {
		fprintf(stderr, "cmpop default width is %u, want 64-bit\n",
			KPROG_X86_CMPOP_WRITE_WIDTH_DEFAULT);
		return 0;
	}
	cases++;

	if (KPROG_X86_CMPOP_OP_CMP_IMM_RHS_SOURCE !=
		    KPROG_X86_CMPOP_RHS_IMMEDIATE ||
	    KPROG_X86_CMPOP_OP_CMP_REG_RHS_SOURCE !=
		    KPROG_X86_CMPOP_RHS_REGISTER ||
	    KPROG_X86_CMPOP_OP_TEST_IMM_RHS_SOURCE !=
		    KPROG_X86_CMPOP_RHS_IMMEDIATE ||
	    KPROG_X86_CMPOP_OP_TEST_REG_RHS_SOURCE !=
		    KPROG_X86_CMPOP_RHS_REGISTER) {
		fprintf(stderr, "cmpop rhs source code drift\n");
		return 0;
	}
	cases++;

	if (KPROG_X86_CMPOP_OP_CMP_IMM_FLAG_KIND != KPROG_X86_CMPOP_FLAGS_SUB ||
	    KPROG_X86_CMPOP_OP_CMP_REG_FLAG_KIND != KPROG_X86_CMPOP_FLAGS_SUB ||
	    KPROG_X86_CMPOP_OP_TEST_IMM_FLAG_KIND != KPROG_X86_CMPOP_FLAGS_LOGIC ||
	    KPROG_X86_CMPOP_OP_TEST_REG_FLAG_KIND != KPROG_X86_CMPOP_FLAGS_LOGIC) {
		fprintf(stderr, "cmpop flag kind code drift\n");
		return 0;
	}
	cases++;

	if (KPROG_X86_CMPOP_RHS_IMMEDIATE == KPROG_X86_CMPOP_RHS_REGISTER) {
		fprintf(stderr, "cmpop rhs source codes collide\n");
		return 0;
	}
	cases++;

	if (KPROG_X86_CMPOP_FLAGS_SUB == KPROG_X86_CMPOP_FLAGS_LOGIC) {
		fprintf(stderr, "cmpop flag kind codes collide\n");
		return 0;
	}
	cases++;

	for (ci = 0; ci < ORACLE_CODES; ci++) {
		unsigned want = codes[ci] ? codes[ci] : X86_WIDTH_64;
		unsigned got = KPROG_X86_CMPOP_WRITE_WIDTH(codes[ci]);

		if (got != want) {
			fprintf(stderr, "cmpop width mismatch flags=%u got=%u "
					"want=%u\n",
				codes[ci], got, want);
			return 0;
		}
		cases++;
	}

	for (ci = 0; ci < 2U; ci++) {
		unsigned got = KPROG_X86_CMPOP_RHS_SOURCE(ci != 0U);
		unsigned want = ci != 0U ? KPROG_X86_CMPOP_RHS_REGISTER
					 : KPROG_X86_CMPOP_RHS_IMMEDIATE;

		if (got != want) {
			fprintf(stderr, "cmpop rhs source select drift\n");
			return 0;
		}
		cases++;
	}

	for (ci = 0; ci < 2U; ci++) {
		unsigned got = KPROG_X86_CMPOP_FLAG_KIND(ci != 0U);
		unsigned want = ci != 0U ? KPROG_X86_CMPOP_FLAGS_LOGIC
					 : KPROG_X86_CMPOP_FLAGS_SUB;

		if (got != want) {
			fprintf(stderr, "cmpop flag kind select drift\n");
			return 0;
		}
		cases++;
	}

	return cases;
}

/* ------------------------------------------------------------------ */
/* Part 2: the full composition vs. the hand-written bodies.          */
/* ------------------------------------------------------------------ */

struct cmpop_effect {
	unsigned rhs_source;
	unsigned flag_kind;
	unsigned width;
	__u64 lhs;
	__u64 rhs;
	__u8 cf;
	__u8 zf;
	__u8 sf;
	__u8 of;
	__u64 dst;
	__u8 dst_tag;
};

static struct cmpop_effect contract_step(unsigned op, unsigned flags,
					 unsigned dst_reg, unsigned src_reg,
					 __u64 raw_imm, unsigned dst_shift,
					 unsigned src_shift, __u8 cf_old,
					 __u8 zf_old, __u8 sf_old,
					 __u8 of_old)
{
	unsigned width = KPROG_X86_CMPOP_WRITE_WIDTH(flags);
	unsigned rhs_source = KPROG_X86_CMPOP_RHS_SOURCE(
		op == X86_OP_CMP_REG || op == X86_OP_TEST_REG);
	unsigned flag_kind = KPROG_X86_CMPOP_FLAG_KIND(
		op == X86_OP_TEST_IMM || op == X86_OP_TEST_REG);
	struct cmpop_effect r;
	__u8 cf = cf_old;
	__u8 zf = zf_old;
	__u8 sf = sf_old;
	__u8 of = of_old;

	r.rhs_source = rhs_source;
	r.flag_kind = flag_kind;
	r.width = width;
	r.lhs = KPROG_X86_READ_REG_AT(oracle_reg_value(dst_reg), width,
				      dst_shift);
	if (rhs_source == KPROG_X86_CMPOP_RHS_REGISTER)
		r.rhs = KPROG_X86_READ_REG_AT(oracle_reg_value(src_reg), width,
					      src_shift);
	else
		r.rhs = KPROG_X86_IMMEDIATE_VALUE(raw_imm, width);

	if (flag_kind == KPROG_X86_CMPOP_FLAGS_LOGIC)
		KPROG_X86_SET_LOGIC_FLAGS(
			cf, zf, sf, of,
			KPROG_X86_APPLY_WIDTH(r.lhs & r.rhs, width) == 0,
			(KPROG_X86_APPLY_WIDTH(r.lhs & r.rhs, width) >>
			 (KPROG_X86_WIDTH_BITS(width) - 1U)) & 1);
	else {
		__u64 ma = r.lhs & KPROG_X86_WIDTH_MASK(width);
		__u64 mb = r.rhs & KPROG_X86_WIDTH_MASK(width);
		__u64 mr = KPROG_X86_SBB_RESULT(r.lhs, r.rhs, 0) &
			   KPROG_X86_WIDTH_MASK(width);

		KPROG_X86_SET_SUB_FLAGS(cf, zf, sf, of, (ma), (mb), (mr),
					KPROG_X86_WIDTH_SIGN_MASK(width));
	}

	r.cf = cf;
	r.zf = zf;
	r.sf = sf;
	r.of = of;
	r.dst = oracle_reg_value(dst_reg);
	r.dst_tag = oracle_regs[dst_reg].tag;
	return r;
}

static struct cmpop_effect model_step(unsigned op, unsigned flags,
				      unsigned dst_reg, unsigned src_reg,
				      __u64 raw_imm, unsigned dst_shift,
				      unsigned src_shift, __u8 cf_old,
				      __u8 zf_old, __u8 sf_old, __u8 of_old)
{
	unsigned width = flags ? flags : X86_WIDTH_64;
	unsigned rhs_source = (op == X86_OP_CMP_REG || op == X86_OP_TEST_REG)
				      ? KPROG_X86_CMPOP_RHS_REGISTER
				      : KPROG_X86_CMPOP_RHS_IMMEDIATE;
	unsigned flag_kind = (op == X86_OP_TEST_IMM || op == X86_OP_TEST_REG)
				     ? KPROG_X86_CMPOP_FLAGS_LOGIC
				     : KPROG_X86_CMPOP_FLAGS_SUB;
	struct cmpop_effect r;
	__u8 cf = cf_old;
	__u8 zf = zf_old;
	__u8 sf = sf_old;
	__u8 of = of_old;

	r.rhs_source = rhs_source;
	r.flag_kind = flag_kind;
	r.width = width;
	r.lhs = oracle_read_reg_at(oracle_reg_value(dst_reg), width, dst_shift);
	if (rhs_source == KPROG_X86_CMPOP_RHS_REGISTER)
		r.rhs = oracle_read_reg_at(oracle_reg_value(src_reg), width,
					   src_shift);
	else
		r.rhs = oracle_imm_value(raw_imm, width);

	if (flag_kind == KPROG_X86_CMPOP_FLAGS_LOGIC)
		oracle_logic_flags(r.lhs & r.rhs, width, &cf, &zf, &sf, &of);
	else
		oracle_sub_flags(r.lhs, r.rhs,
				 r.lhs - r.rhs, width,
				 &cf, &zf, &sf, &of);

	r.cf = cf;
	r.zf = zf;
	r.sf = sf;
	r.of = of;
	r.dst = oracle_reg_value(dst_reg);
	r.dst_tag = oracle_regs[dst_reg].tag;
	return r;
}

static unsigned part2(void)
{
	static const unsigned flags_codes[ORACLE_CODES] = { 0U, X86_WIDTH_8,
							    X86_WIDTH_16,
							    X86_WIDTH_32,
							    X86_WIDTH_64 };
	static const unsigned ops[4] = { X86_OP_CMP_IMM, X86_OP_CMP_REG,
					 X86_OP_TEST_IMM, X86_OP_TEST_REG };
	static const __u64 imms[4] = { 0, 1, 0x80000000ULL, 0x1ffffffffULL };
	static const unsigned dst_regs[3] = { X86_RDI, X86_RBX, 9U };
	static const unsigned src_regs[3] = { X86_RCX, X86_RDX, 12U };
	static const unsigned shifts[ORACLE_LANES] = { 0U, 8U };
	unsigned cases = 0;
	unsigned oi;
	unsigned fi;
	unsigned mi;
	unsigned dswi;
	unsigned sswi;
	unsigned di;
	unsigned si;

	for (oi = 0; oi < 4U; oi++) {
		for (fi = 0; fi < ORACLE_CODES; fi++) {
			for (mi = 0; mi < 4U; mi++) {
				for (di = 0; di < 3U; di++) {
					for (si = 0; si < 3U; si++) {
						for (dswi = 0; dswi < ORACLE_LANES;
						     dswi++) {
							for (sswi = 0;
							     sswi < ORACLE_LANES;
							     sswi++) {
								struct cmpop_effect got;
								struct cmpop_effect want;

								oracle_restore_pristine();
								got = contract_step(
									ops[oi],
									flags_codes[fi],
									dst_regs[di],
									src_regs[si],
									imms[mi],
									shifts[dswi],
									shifts[sswi],
									1U, 0U, 1U,
									0U);
								memcpy(result_regs,
								       oracle_regs,
								       sizeof(oracle_regs));
								memcpy(result_mem,
								       oracle_mem,
								       ORACLE_MEM_BYTES);

								oracle_restore_pristine();
								want = model_step(
									ops[oi],
									flags_codes[fi],
									dst_regs[di],
									src_regs[si],
									imms[mi],
									shifts[dswi],
									shifts[sswi],
									1U, 0U, 1U,
									0U);

								if (got.rhs_source != want.rhs_source ||
								    got.flag_kind != want.flag_kind ||
								    got.width != want.width ||
								    got.lhs != want.lhs ||
								    got.rhs != want.rhs ||
								    got.cf != want.cf ||
								    got.zf != want.zf ||
								    got.sf != want.sf ||
								    got.of != want.of ||
								    got.dst != want.dst ||
								    got.dst_tag != want.dst_tag ||
								    memcmp(result_regs, oracle_regs,
									   sizeof(oracle_regs)) ||
								    memcmp(result_mem, oracle_mem,
									   ORACLE_MEM_BYTES)) {
									fprintf(stderr,
										"cmpop mismatch op=%u flags=%u\n",
										ops[oi],
										flags_codes[fi]);
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
	return cases;
}

/* ------------------------------------------------------------------ */
/* Part 3: pins on the facts the composition is about.                */
/* ------------------------------------------------------------------ */

static unsigned part3(void)
{
	unsigned cases = 0;

	/* Pin 1: `CMP_IMM` reads its right-hand side from the immediate and
	 * produces subtraction flags; neither memory nor any register is
	 * written. */
	{
		struct cmpop_effect e;

		oracle_restore_pristine();
		e = contract_step(X86_OP_CMP_IMM, X86_WIDTH_64, X86_RAX,
				  X86_RCX, 0x1234ULL, 0U, 0U, 0U, 0U, 0U, 0U);
		if (e.rhs_source != KPROG_X86_CMPOP_RHS_IMMEDIATE)
			return 0;
		if (e.flag_kind != KPROG_X86_CMPOP_FLAGS_SUB)
			return 0;
		if (e.rhs != 0x1234ULL)
			return 0;
		if (memcmp(oracle_regs, pristine_regs, sizeof(oracle_regs)))
			return 0;
		if (memcmp(oracle_mem, pristine_mem, ORACLE_MEM_BYTES))
			return 0;
		cases++;
	}

	/* Pin 2: `CMP_REG` reads its right-hand side from the register. */
	{
		struct cmpop_effect e;

		oracle_restore_pristine();
		e = contract_step(X86_OP_CMP_REG, X86_WIDTH_64, X86_RAX,
				  X86_RCX, 0x1234ULL, 0U, 0U, 0U, 0U, 0U, 0U);
		if (e.rhs_source != KPROG_X86_CMPOP_RHS_REGISTER)
			return 0;
		if (e.rhs != oracle_reg_value(X86_RCX))
			return 0;
		cases++;
	}

	/* Pin 3: `TEST_IMM`/`TEST_REG` produce logical flags: carry and overflow
	 * are always clear, zero and sign come from the width-narrowed
	 * conjunction. A conjunction that is zero sets zero and clears sign. */
	{
		struct cmpop_effect e;

		oracle_restore_pristine();
		oracle_regs[X86_RAX].u.ptr = (void *)(long)0x00ffULL;
		oracle_regs[X86_RAX].tag = X86_SIM_TAG_SCALAR;
		e = contract_step(X86_OP_TEST_IMM, X86_WIDTH_16, X86_RAX,
				  X86_RCX, 0x0000ULL, 0U, 0U, 1U, 0U, 1U, 1U);
		if (e.flag_kind != KPROG_X86_CMPOP_FLAGS_LOGIC)
			return 0;
		if (e.cf != 0U || e.of != 0U)
			return 0;
		if (e.zf != 1U || e.sf != 0U)
			return 0;
		cases++;

		/* A nonzero conjunction takes its sign from the width-local top
		 * bit: 0xff00 at 16 bits has bit 15 set, so sign is set. */
		oracle_restore_pristine();
		oracle_regs[X86_RAX].u.ptr = (void *)(long)0xff00ULL;
		oracle_regs[X86_RAX].tag = X86_SIM_TAG_SCALAR;
		e = contract_step(X86_OP_TEST_IMM, X86_WIDTH_16, X86_RAX,
				  X86_RCX, 0x8000ULL, 0U, 0U, 0U, 1U, 0U, 0U);
		if (e.cf != 0U || e.of != 0U)
			return 0;
		if (e.zf != 0U || e.sf != 1U)
			return 0;
		cases++;
	}

	/* Pin 4: `CMP` produces subtraction flags, not logical flags — the same
	 * operands that would clear carry under a test instead set carry from
	 * the borrow. */
	{
		struct cmpop_effect cmp;
		struct cmpop_effect tst;

		oracle_restore_pristine();
		oracle_regs[X86_RAX].u.ptr = (void *)(long)1ULL;
		oracle_regs[X86_RAX].tag = X86_SIM_TAG_SCALAR;
		oracle_regs[X86_RCX].u.ptr = (void *)(long)2ULL;
		oracle_regs[X86_RCX].tag = X86_SIM_TAG_SCALAR;
		cmp = contract_step(X86_OP_CMP_REG, X86_WIDTH_8, X86_RAX,
				    X86_RCX, 0, 0U, 0U, 0U, 0U, 0U, 0U);
		oracle_restore_pristine();
		oracle_regs[X86_RAX].u.ptr = (void *)(long)1ULL;
		oracle_regs[X86_RAX].tag = X86_SIM_TAG_SCALAR;
		oracle_regs[X86_RCX].u.ptr = (void *)(long)2ULL;
		oracle_regs[X86_RCX].tag = X86_SIM_TAG_SCALAR;
		tst = contract_step(X86_OP_TEST_REG, X86_WIDTH_8, X86_RAX,
				    X86_RCX, 0, 0U, 0U, 0U, 0U, 0U, 0U);
		if (cmp.flag_kind == tst.flag_kind)
			return 0;
		if (cmp.cf != 1U)
			return 0;
		if (tst.cf != 0U)
			return 0;
		cases++;
	}

	/* Pin 5: the destination lane is read through the width/lane register
	 * read — an 8-bit `CMP` with destination shift 8 reads the register's
	 * high byte. */
	{
		struct cmpop_effect low;
		struct cmpop_effect high;

		oracle_restore_pristine();
		oracle_regs[X86_RAX].u.ptr = (void *)(long)0x112233445566aa88ULL;
		oracle_regs[X86_RAX].tag = X86_SIM_TAG_SCALAR;
		low = contract_step(X86_OP_CMP_IMM, X86_WIDTH_8, X86_RAX,
				    X86_RCX, 0, 0U, 0U, 0U, 0U, 0U, 0U);
		high = contract_step(X86_OP_CMP_IMM, X86_WIDTH_8, X86_RAX,
				     X86_RCX, 0, 8U, 0U, 0U, 0U, 0U, 0U);
		if (low.lhs != 0x88ULL)
			return 0;
		if (high.lhs != 0xaaULL)
			return 0;
		if (low.lhs == high.lhs)
			return 0;
		cases++;
	}

	/* Pin 6: the `_REG` right-hand side is read through the same width/lane
	 * read, at the AUX source shift. */
	{
		struct cmpop_effect low;
		struct cmpop_effect high;

		oracle_restore_pristine();
		oracle_regs[X86_RCX].u.ptr = (void *)(long)0x112233445566bb44ULL;
		oracle_regs[X86_RCX].tag = X86_SIM_TAG_SCALAR;
		low = contract_step(X86_OP_TEST_REG, X86_WIDTH_8, X86_RAX,
				    X86_RCX, 0, 0U, 0U, 0U, 0U, 0U, 0U);
		high = contract_step(X86_OP_TEST_REG, X86_WIDTH_8, X86_RAX,
				     X86_RCX, 0, 0U, 8U, 0U, 0U, 0U, 0U);
		if (low.rhs != 0x44ULL)
			return 0;
		if (high.rhs != 0xbbULL)
			return 0;
		cases++;
	}

	/* Pin 7: an absent FLAGS code resolves to the 64-bit width, so neither
	 * operand is narrowed. */
	{
		struct cmpop_effect e;

		oracle_restore_pristine();
		e = contract_step(X86_OP_CMP_IMM, 0U, X86_RAX, X86_RCX, 0U, 0U,
				  0U, 0U, 0U, 0U, 0U);
		if (e.width != X86_WIDTH_64)
			return 0;
		cases++;
	}

	/* Pin 8: the `_IMM` form widens the immediate at the resolved width — a
	 * 64-bit immediate with bit 31 set sign-extends, the same bits under a
	 * 32-bit width do not. */
	{
		struct cmpop_effect w64;
		struct cmpop_effect w32;

		oracle_restore_pristine();
		w64 = contract_step(X86_OP_CMP_IMM, X86_WIDTH_64, X86_RAX,
				    X86_RCX, 0x80000000ULL, 0U, 0U, 0U, 0U, 0U,
				    0U);
		w32 = contract_step(X86_OP_CMP_IMM, X86_WIDTH_32, X86_RAX,
				    X86_RCX, 0x80000000ULL, 0U, 0U, 0U, 0U, 0U,
				    0U);
		if (w64.rhs != 0xffffffff80000000ULL)
			return 0;
		if (w32.rhs != 0x80000000ULL)
			return 0;
		cases++;
	}

	/* Pin 9: no `CMP`/`TEST` form writes memory, and none writes a
	 * register — the whole register file and memory are untouched. */
	{
		struct cmpop_effect e;

		oracle_restore_pristine();
		e = contract_step(X86_OP_TEST_REG, X86_WIDTH_32, X86_RAX,
				  X86_RCX, 8, 0U, 0U, 0U, 0U, 0U, 0U);
		if (e.dst != oracle_reg_value(X86_RAX))
			return 0;
		if (e.dst_tag != oracle_regs[X86_RAX].tag)
			return 0;
		if (memcmp(oracle_regs, pristine_regs, sizeof(oracle_regs)))
			return 0;
		if (memcmp(oracle_mem, pristine_mem, ORACLE_MEM_BYTES))
			return 0;
		cases++;
	}

	return cases;
}

int main(void)
{
	unsigned c1;
	unsigned c2;
	unsigned c3;

	oracle_reset();
	oracle_snapshot_pristine();

	c1 = part1();
	if (c1 == 0U)
		return 1;
	oracle_restore_pristine();
	c2 = part2();
	if (c2 == 0U)
		return 1;
	oracle_restore_pristine();
	c3 = part3();
	if (c3 == 0U)
		return 1;
	oracle_restore_pristine();

	printf("x86 cmpop handler host cross-check: OK (%u cases)\n", c1 + c2 + c3);
	return 0;
}
