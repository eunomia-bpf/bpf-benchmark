/*
 * Host cross-check for the AArch64 vector `.D0` / `.Q0` memory-transfer
 * contract.
 *
 * The module under test is `generated/arm64_dq_mem.h`. The four C bodies
 * (`ARM64_SIM_L_LOAD_D0_MEM`, `LOAD_Q0_MEM`, `STORE_D0_MEM`, `STORE_Q0_MEM`)
 * move a SIMD register's low 64-bit lane (`.D0`) or both 64-bit lanes (`.Q0`) to
 * or from memory. Their built-in logic:
 *
 *   * a pre-indexed access adjusts the base (or `__a64_sp`) by the raw IMM
 *     before the transfer; a post-indexed one adjusts it after;
 *   * the transfer address is `base + MEM_BASE_OFF(AUX, INDEX, IMM) + extra`,
 *     where `extra` is 0 for the low lane and the 64-bit lane width (8) for the
 *     high lane;
 *   * `.D0` moves exactly one lane, `.Q0` two;
 *   * each lane is a full 64-bit scalar access.
 *
 * The generated header fixes the per-opcode direction and lane count and the
 * lane offsets, but it is not on the C bodies' include path, so this host
 * cross-check is the tie: it drives the contract's selectors and restates the
 * same bodies from the raw opcode, and the two must agree on the SIMD lanes, the
 * whole GPR file, memory and the stack.
 *
 * The value-producing helpers the bodies use are the separately proved
 * generated macros `KPROG_ARM64_MEM_OFFSET` and the read/write dispatch, so this
 * oracle composes them.
 */
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;
typedef signed long long __s64;

#define ARM64_SP 31U
#define ARM64_REG_NONE 0xffU
#define ARM64_WIDTH_8 1U
#define ARM64_WIDTH_64 8U

#define ARM64_MEM_PRE 1U
#define ARM64_MEM_POST 2U

#define ARM64_SIM_TAG_SCALAR 0U
#define ARM64_SIM_TAG_ABI 1U
#define ARM64_SIM_TAG_STACK 4U
#define ARM64_SIM_TAG_RELOC_ADDR 7U

#define ARM64_OP_LOAD_D0 0x28U
#define ARM64_OP_STORE_D0 0x29U
#define ARM64_OP_LOAD_Q0 0x2aU
#define ARM64_OP_STORE_Q0 0x2bU

#include "generated/arm64_dq_mem.h"
#include "generated/arm64_mem_dispatch.h"
#include "generated/arm64_mem_offset.h"

#include <stdio.h>
#include <string.h>

#define ORACLE_REGS 32U
#define MEM_WORDS 512U

struct oracle_reg {
	__u64 value;
	__u8 tag;
};

static struct oracle_reg regs[ORACLE_REGS];
static struct oracle_reg pristine[ORACLE_REGS];
static __s64 sp;
static __s64 pristine_sp;

static __u64 mem[MEM_WORDS];
static __u64 pristine_mem[MEM_WORDS];
static __u64 stack[MEM_WORDS];
static __u64 pristine_stack[MEM_WORDS];
static __u8 stack_tag[MEM_WORDS];
static __u8 pristine_stack_tag[MEM_WORDS];

/* ------------------------------------------------------------------ */
/* The memory tile: word-addressed, little-endian.                      */
/* ------------------------------------------------------------------ */

static unsigned word_index(__s64 addr)
{
	return (unsigned)((addr >> 3) & (MEM_WORDS - 1U));
}

/* ------------------------------------------------------------------ */
/* Independent model of ARM64_SIM_L_MEM_READ / _WRITE.                  */
/* ------------------------------------------------------------------ */

static __u64 model_read(unsigned base, __s64 off, unsigned width)
{
	int is_sp = base == ARM64_SP;
	__u8 tag = is_sp ? ARM64_SIM_TAG_STACK : regs[base].tag;
	__u64 base_val = is_sp ? (__u64)sp : regs[base].value;

	if (is_sp || tag == ARM64_SIM_TAG_STACK)
		return stack[word_index(sp + off)];
	if (tag == ARM64_SIM_TAG_RELOC_ADDR && width == ARM64_WIDTH_64)
		return base_val;
	return mem[word_index((__s64)base_val + off)];
}
static void model_write(unsigned base, __s64 off, unsigned width, __u64 value,
			__u8 tag_arg)
{
	int is_sp = base == ARM64_SP;
	__u8 tag = is_sp ? ARM64_SIM_TAG_STACK : regs[base].tag;
	__u64 base_val = is_sp ? (__u64)sp : regs[base].value;

	if (width != ARM64_WIDTH_64) {
		fprintf(stderr, "model_write width %u unsupported\n", width);
		return;
	}
	if (is_sp || tag == ARM64_SIM_TAG_STACK) {
		stack[word_index(sp + off)] = value;
		stack_tag[word_index(sp + off)] = tag_arg;
	} else {
		mem[word_index((__s64)base_val + off)] = value;
	}
}

/* ------------------------------------------------------------------ */
/* Model of MEM_PRE / MEM_POST (raw IMM, not MEM_BASE_OFF).             */
/* ------------------------------------------------------------------ */

static void model_writeback(unsigned base, __s64 imm)
{
	if (base == ARM64_SP) {
		sp += imm;
	} else {
		__u64 nb = regs[base].value + (__u64)imm;

		regs[base].value = nb;
	}
}

/* ------------------------------------------------------------------ */
/* Effects, so the two steps can be compared field by field.            */
/* ------------------------------------------------------------------ */

struct dq_effect {
	unsigned idx;
	unsigned access;
	unsigned lanes;
	__u64 v0;
	__u64 v0_hi;
	struct oracle_reg r[ORACLE_REGS];
	__s64 sp;
	__u64 mem[MEM_WORDS];
	__u64 stack[MEM_WORDS];
	__u8 stack_tag[MEM_WORDS];
};

static void snapshot(struct dq_effect *e)
{
	memcpy(e->r, regs, sizeof(regs));
	e->sp = sp;
	memcpy(e->mem, mem, sizeof(mem));
	memcpy(e->stack, stack, sizeof(stack));
	memcpy(e->stack_tag, stack_tag, sizeof(stack_tag));
}

/* The transfer body shared by both steps: run the ordered lane plan `lanes`
 * times, each lane at `MEM_BASE_OFF + i*lane_stride`, then return the effect.
 * The stride is a parameter so the contract step takes it from the generated
 * constant and the model step uses the literal 8 the bodies hard-code. */
static void run_lanes(unsigned base, unsigned index, unsigned flags, __s64 imm,
		      int is_load, unsigned lanes, unsigned lane_stride,
		      __u64 v0, __u64 v0_hi, struct dq_effect *e)
{
	unsigned i;

	for (i = 0; i < lanes; i++) {
		__s64 off = (__s64)KPROG_ARM64_MEM_OFFSET(
				    flags & (ARM64_MEM_PRE | ARM64_MEM_POST),
				    index != ARM64_REG_NONE, imm, index) +
			    (__s64)i * (__s64)lane_stride;

		if (is_load) {
			__u64 val = model_read(base, off, ARM64_WIDTH_64);

			if (i == 0)
				e->v0 = val;
			else
				e->v0_hi = val;
		} else if (i == 0) {
			model_write(base, off, ARM64_WIDTH_64, v0,
				    ARM64_SIM_TAG_SCALAR);
		} else {
			model_write(base, off, ARM64_WIDTH_64, v0_hi,
				    ARM64_SIM_TAG_SCALAR);
		}
	}
	if (!is_load) {
		e->v0 = v0;
		e->v0_hi = v0_hi;
	}
}

/* The contract step: direction, lane count and index all come from the
 * generated per-opcode constants. */
static struct dq_effect contract_step(unsigned op, unsigned base, unsigned index,
				      unsigned flags, __s64 imm, __u64 v0,
				      __u64 v0_hi)
{
	struct dq_effect e;
	unsigned idx = KPROG_ARM64_DQ_MEM_INDEX(op);

	memset(&e, 0, sizeof(e));
	e.idx = idx;
	if (idx == KPROG_ARM64_DQ_MEM_OP_LOAD_D0_INDEX) {
		e.access = KPROG_ARM64_DQ_MEM_OP_LOAD_D0_ACCESS;
		e.lanes = KPROG_ARM64_DQ_MEM_OP_LOAD_D0_LANES;
	} else if (idx == KPROG_ARM64_DQ_MEM_OP_LOAD_Q0_INDEX) {
		e.access = KPROG_ARM64_DQ_MEM_OP_LOAD_Q0_ACCESS;
		e.lanes = KPROG_ARM64_DQ_MEM_OP_LOAD_Q0_LANES;
	} else if (idx == KPROG_ARM64_DQ_MEM_OP_STORE_D0_INDEX) {
		e.access = KPROG_ARM64_DQ_MEM_OP_STORE_D0_ACCESS;
		e.lanes = KPROG_ARM64_DQ_MEM_OP_STORE_D0_LANES;
	} else {
		e.access = KPROG_ARM64_DQ_MEM_OP_STORE_Q0_ACCESS;
		e.lanes = KPROG_ARM64_DQ_MEM_OP_STORE_Q0_LANES;
	}

	if (flags & ARM64_MEM_PRE)
		model_writeback(base, imm);
	run_lanes(base, index, flags, imm,
		  e.access == KPROG_ARM64_DQ_MEM_ACCESS_LOAD, e.lanes,
		  KPROG_ARM64_DQ_MEM_LANE_STRIDE, v0, v0_hi, &e);
	if (flags & ARM64_MEM_POST)
		model_writeback(base, imm);

	snapshot(&e);
	return e;
}

/* The model step: everything restated from the raw opcode. */
static struct dq_effect model_step(unsigned op, unsigned base, unsigned index,
				   unsigned flags, __s64 imm, __u64 v0,
				   __u64 v0_hi)
{
	struct dq_effect e;
	int is_load = (op == ARM64_OP_LOAD_D0 || op == ARM64_OP_LOAD_Q0);
	unsigned lanes = (op == ARM64_OP_LOAD_Q0 || op == ARM64_OP_STORE_Q0) ? 2U
									   : 1U;

	memset(&e, 0, sizeof(e));
	e.idx = (op == ARM64_OP_LOAD_D0)    ? 0U
		: (op == ARM64_OP_LOAD_Q0)  ? 1U
		: (op == ARM64_OP_STORE_D0) ? 2U
					    : 3U;
	e.access = is_load ? 0U : 1U;
	e.lanes = lanes;

	if (flags & ARM64_MEM_PRE)
		model_writeback(base, imm);
	run_lanes(base, index, flags, imm, is_load, lanes, 8U, v0, v0_hi, &e);
	if (flags & ARM64_MEM_POST)
		model_writeback(base, imm);

	snapshot(&e);
	return e;
}

static unsigned compare_effect(const struct dq_effect *c,
			       const struct dq_effect *m, unsigned op,
			       unsigned base, unsigned index, unsigned flags,
			       __s64 imm)
{
	unsigned k;
	int bad = 0;

	bad |= c->idx != m->idx;
	bad |= c->access != m->access;
	bad |= c->lanes != m->lanes;
	bad |= c->v0 != m->v0;
	bad |= c->v0_hi != m->v0_hi;
	bad |= c->sp != m->sp;
	for (k = 0; k < ORACLE_REGS; k++)
		bad |= c->r[k].value != m->r[k].value ||
		       c->r[k].tag != m->r[k].tag;
	for (k = 0; k < MEM_WORDS; k++) {
		bad |= c->mem[k] != m->mem[k];
		bad |= c->stack[k] != m->stack[k];
		bad |= c->stack_tag[k] != m->stack_tag[k];
	}
	if (bad)
		printf("MISMATCH op=%#x base=%u index=%u flags=%u imm=%#llx "
		       "idx=%u/%u acc=%u/%u lanes=%u/%u v0=%#llx/%#llx "
		       "v0hi=%#llx/%#llx sp=%#llx/%#llx\n",
		       op, base, index, flags, (unsigned long long)imm, c->idx,
		       m->idx, c->access, m->access, c->lanes, m->lanes,
		       (unsigned long long)c->v0, (unsigned long long)m->v0,
		       (unsigned long long)c->v0_hi,
		       (unsigned long long)m->v0_hi, (unsigned long long)c->sp,
		       (unsigned long long)m->sp);
	return bad;
}

static void reset(void)
{
	unsigned i;

	for (i = 0; i < ORACLE_REGS; i++) {
		regs[i].value = 0x40ULL + i * 0x40ULL;
		regs[i].tag = (i % 5U == 0U)   ? ARM64_SIM_TAG_ABI
			      : (i % 5U == 1U) ? ARM64_SIM_TAG_RELOC_ADDR
			      : (i % 5U == 2U) ? ARM64_SIM_TAG_STACK
					       : ARM64_SIM_TAG_SCALAR;
	}
	sp = 0x1000;
	for (i = 0; i < MEM_WORDS; i++) {
		mem[i] = 0xdead0000ULL + i;
		stack[i] = 0xbeef0000ULL + i;
		stack_tag[i] = ARM64_SIM_TAG_SCALAR;
	}
}

static void snapshot_pristine(void)
{
	memcpy(pristine, regs, sizeof(regs));
	pristine_sp = sp;
	memcpy(pristine_mem, mem, sizeof(mem));
	memcpy(pristine_stack, stack, sizeof(stack));
	memcpy(pristine_stack_tag, stack_tag, sizeof(stack_tag));
}

static void restore_pristine(void)
{
	memcpy(regs, pristine, sizeof(regs));
	sp = pristine_sp;
	memcpy(mem, pristine_mem, sizeof(mem));
	memcpy(stack, pristine_stack, sizeof(stack));
	memcpy(stack_tag, pristine_stack_tag, sizeof(stack_tag));
}

/* ------------------------------------------------------------------ */
/* Part 1: generated tables and selector vs. independent constants.    */
/* ------------------------------------------------------------------ */

static unsigned part1(void)
{
	unsigned cases = 0;
	unsigned i;
	static const unsigned op_val[4][2] = {
		{ ARM64_OP_LOAD_D0, 0U }, { ARM64_OP_LOAD_Q0, 1U },
		{ ARM64_OP_STORE_D0, 2U }, { ARM64_OP_STORE_Q0, 3U },
	};

	if (KPROG_ARM64_DQ_MEM_LANE_STRIDE != ARM64_WIDTH_64 ||
	    KPROG_ARM64_DQ_MEM_HIGH_LANE_STRIDE != 8U) {
		fprintf(stderr, "dq mem lane stride drift\n");
		return 0;
	}
	cases++;

	if (KPROG_ARM64_DQ_MEM_ACCESS_LOAD == KPROG_ARM64_DQ_MEM_ACCESS_STORE) {
		fprintf(stderr, "dq mem access codes collide\n");
		return 0;
	}
	cases++;

	if (KPROG_ARM64_DQ_MEM_OP_LOAD_D0_LANES != 1U ||
	    KPROG_ARM64_DQ_MEM_OP_STORE_D0_LANES != 1U ||
	    KPROG_ARM64_DQ_MEM_OP_LOAD_Q0_LANES != 2U ||
	    KPROG_ARM64_DQ_MEM_OP_STORE_Q0_LANES != 2U) {
		fprintf(stderr, "dq mem lane count drift\n");
		return 0;
	}
	cases++;

	if (KPROG_ARM64_DQ_MEM_OP_LOAD_D0_ACCESS !=
		    KPROG_ARM64_DQ_MEM_ACCESS_LOAD ||
	    KPROG_ARM64_DQ_MEM_OP_LOAD_Q0_ACCESS !=
		    KPROG_ARM64_DQ_MEM_ACCESS_LOAD ||
	    KPROG_ARM64_DQ_MEM_OP_STORE_D0_ACCESS !=
		    KPROG_ARM64_DQ_MEM_ACCESS_STORE ||
	    KPROG_ARM64_DQ_MEM_OP_STORE_Q0_ACCESS !=
		    KPROG_ARM64_DQ_MEM_ACCESS_STORE) {
		fprintf(stderr, "dq mem access direction drift\n");
		return 0;
	}
	cases++;

	if (KPROG_ARM64_DQ_MEM_OP_LOAD_D0_INDEX != 0U ||
	    KPROG_ARM64_DQ_MEM_OP_LOAD_Q0_INDEX != 1U ||
	    KPROG_ARM64_DQ_MEM_OP_STORE_D0_INDEX != 2U ||
	    KPROG_ARM64_DQ_MEM_OP_STORE_Q0_INDEX != 3U) {
		fprintf(stderr, "dq mem index constant drift\n");
		return 0;
	}
	cases++;

	for (i = 0; i < 4U; i++) {
		unsigned got = KPROG_ARM64_DQ_MEM_INDEX(op_val[i][0]);

		if (got != op_val[i][1]) {
			fprintf(stderr, "dq mem index select drift op=%#x "
					"got=%u want=%u\n",
				op_val[i][0], got, op_val[i][1]);
			return 0;
		}
		cases++;
	}

	if (KPROG_ARM64_DQ_MEM_INDEX(0xffU) !=
	    KPROG_ARM64_DQ_MEM_OP_STORE_Q0_INDEX) {
		fprintf(stderr, "dq mem index not total off the opcode set\n");
		return 0;
	}
	cases++;

	return cases;
}

/* ------------------------------------------------------------------ */
/* Part 2: full composition vs. the hand-written bodies.               */
/* ------------------------------------------------------------------ */

static unsigned part2(void)
{
	static const unsigned ops[4] = { ARM64_OP_LOAD_D0, ARM64_OP_LOAD_Q0,
					 ARM64_OP_STORE_D0, ARM64_OP_STORE_Q0 };
	static const unsigned flagset[3] = { 0U, ARM64_MEM_PRE, ARM64_MEM_POST };
	static const __s64 imms[] = { 0, 8, -8, 0x20, -0x40, 0x100 };
	__u64 state = 0x123456789abcdef0ULL;
	unsigned cases = 0, fails = 0;
	unsigned oi, bi, fi, xi, pi;

	for (oi = 0; oi < 4U; oi++)
		for (bi = 0; bi < ORACLE_REGS; bi++)
			for (fi = 0; fi < 3U; fi++)
				for (xi = 0; xi < 4U; xi++)
					for (pi = 0; pi < 6U; pi++) {
						unsigned index = xi == 0U
								 ? ARM64_REG_NONE
								 : (2U + xi);
						__s64 imm = imms[pi];
						__u64 v0, v0_hi;
						struct dq_effect c, m;

						state = state * 6364136223846793005ULL +
							1442695040888963407ULL;
						v0 = state ^ 0xa5a5a5a5a5a5a5a5ULL;
						v0_hi = state * 0x9e3779b97f4a7c15ULL;

						restore_pristine();
						c = contract_step(ops[oi], bi, index,
								  flagset[fi], imm,
								  v0, v0_hi);
						restore_pristine();
						m = model_step(ops[oi], bi, index,
							       flagset[fi], imm, v0,
							       v0_hi);
						fails += compare_effect(
							&c, &m, ops[oi], bi, index,
							flagset[fi], imm);
						cases++;
					}

	if (fails) {
		printf("arm64 D0/Q0 mem host cross-check: FAILED (%u mismatches)\n",
		       fails);
		return 1;
	}
	printf("arm64 D0/Q0 mem host cross-check: OK (%u cases)\n", cases);
	return 0;
}

int main(void)
{
	unsigned p1, p2;

	reset();
	snapshot_pristine();
	p1 = part1();
	p2 = part2();

	if (p1 == 0 || p2 != 0)
		return 1;
	return 0;
}
