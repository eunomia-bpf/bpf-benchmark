/*
 * Host cross-check for the AArch64 `LDP` / `STP` pair-move contract.
 *
 * Part 1 checks the generated `KPROG_ARM64_PAIR_MEM_*` constants and the
 * `KPROG_ARM64_PAIR_MEM_INDEX` selector against an independent opcode -> access
 * direction / arm index / slot count / slot stride table, including an opcode
 * off the two-way set that must fall through to the total default arm.
 *
 * Part 2 drives the full composition of both C bodies -- pre/post writeback, the
 * low slot at `MEM_BASE_OFF`, the high slot one 64-bit slot stride higher, the
 * read-before-write ordering of the load (`LDP` gathers both slots before it
 * writes the register pair, so a target register that is also the base still
 * reads the original base), and the register-pair mapping (`LDP`: low->DST,
 * high->SRC; `STP`: low from SRC, high from SRC2). The contract step takes its
 * direction, slot count and slot stride from the generated constants; the model
 * step restates everything from the raw opcode with the literal stride `8`. The
 * two must leave identical register, tag, memory, stack and stack-tag state.
 *
 * Mirrors test_arm64_dq_mem_host.c. Exit status 0 only when both parts pass.
 */
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;
typedef signed long long __s64;

#define ARM64_XZR 31U
#define ARM64_SP 32U
#define ARM64_REG_NONE 0xffU
#define ARM64_WIDTH_8 1U
#define ARM64_WIDTH_64 8U

#define ARM64_MEM_PRE 1U
#define ARM64_MEM_POST 2U

#define ARM64_SIM_TAG_SCALAR 0U
#define ARM64_SIM_TAG_ABI 1U
#define ARM64_SIM_TAG_STACK 4U
#define ARM64_SIM_TAG_RELOC_ADDR 7U

#define ARM64_OP_LDP 0x21U
#define ARM64_OP_STP 0x22U

#include "generated/arm64_pair_mem.h"
#include "generated/arm64_mem_offset.h"

#include <stdio.h>
#include <string.h>

#define ORACLE_REGS 33U /* 0..30 GPR, 31 XZR, 32 SP */
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
/* Register-pair access, matching READ_REG / WRITE_REG_WIDTH.          */
/* ------------------------------------------------------------------ */

static __u64 read_gpr(unsigned reg)
{
	if (reg == ARM64_SP)
		return (__u64)sp;
	if (reg == ARM64_XZR)
		return 0U;
	return regs[reg].value;
}

static void write_gpr(unsigned reg, __u64 value)
{
	if (reg == ARM64_SP) {
		sp = (__s64)value;
	} else if (reg != ARM64_XZR) {
		regs[reg].value = value;
		regs[reg].tag = ARM64_SIM_TAG_SCALAR;
	}
}

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
	} else if (base != ARM64_XZR) {
		regs[base].value += (__u64)imm;
	}
}

/* ------------------------------------------------------------------ */
/* The pair effect, so the two steps can be compared field by field.    */
/* ------------------------------------------------------------------ */

struct pair_effect {
	unsigned idx;
	unsigned access;
	unsigned slots;
	__u64 lo;
	__u64 hi;
	struct oracle_reg r[ORACLE_REGS];
	__s64 sp;
	__u64 mem[MEM_WORDS];
	__u64 stack[MEM_WORDS];
	__u8 stack_tag[MEM_WORDS];
};

static void snapshot(struct pair_effect *e)
{
	memcpy(e->r, regs, sizeof(regs));
	e->sp = sp;
	memcpy(e->mem, mem, sizeof(mem));
	memcpy(e->stack, stack, sizeof(stack));
	memcpy(e->stack_tag, stack_tag, sizeof(stack_tag));
}

/* The pair body shared by both steps. A load gathers both slots at
 * MEM_BASE_OFF + i*slot_stride before writing the pair (`LDP`); a store writes
 * the pair's two values to those slots (`STP`). The stride is a parameter so the
 * contract step takes it from the generated constant and the model step uses the
 * literal 8 the bodies hard-code. */
static void run_slots(unsigned base, unsigned index, unsigned flags, __s64 imm,
		      int is_load, unsigned slots, unsigned slot_stride,
		      unsigned dst_reg, unsigned src_reg, unsigned src2_reg,
		      struct pair_effect *e)
{
	unsigned i;
	__u64 slot[8];
	__u64 p0 = 0, p1 = 0;

	/* A store reads its source pair here, after PRE and before any slot is
	 * written, matching MEM_WRITE's READ_REG(SRC) / READ_REG(SRC2). */
	if (!is_load) {
		p0 = read_gpr(src_reg);
		p1 = read_gpr(src2_reg);
	}
	for (i = 0; i < slots; i++) {
		__s64 off = (__s64)KPROG_ARM64_MEM_OFFSET(
				    flags & (ARM64_MEM_PRE | ARM64_MEM_POST),
				    index != ARM64_REG_NONE, imm, index) +
			    (__s64)i * (__s64)slot_stride;

		if (is_load)
			slot[i] = model_read(base, off, ARM64_WIDTH_64);
		else if (i == 0)
			model_write(base, off, ARM64_WIDTH_64, p0,
				    ARM64_SIM_TAG_SCALAR);
		else
			model_write(base, off, ARM64_WIDTH_64, p1,
				    ARM64_SIM_TAG_SCALAR);
	}
	if (is_load) {
		e->lo = slot[0];
		e->hi = slot[1];
		write_gpr(dst_reg, slot[0]);
		write_gpr(src_reg, slot[1]);
	} else {
		e->lo = p0;
		e->hi = p1;
	}
}

/* The contract step: direction, slot count and slot stride all come from the
 * generated per-opcode constants. */
static struct pair_effect contract_step(unsigned op, unsigned base,
					unsigned index, unsigned flags,
					__s64 imm, unsigned dst_reg,
					unsigned src_reg, unsigned src2_reg)
{
	struct pair_effect e;
	unsigned idx = KPROG_ARM64_PAIR_MEM_INDEX(op);
	unsigned access;

	memset(&e, 0, sizeof(e));
	e.idx = idx;
	e.slots = KPROG_ARM64_PAIR_MEM_SLOT_COUNT;
	if (idx == KPROG_ARM64_PAIR_MEM_OP_LDP_INDEX)
		access = KPROG_ARM64_PAIR_MEM_OP_LDP_ACCESS;
	else
		access = KPROG_ARM64_PAIR_MEM_OP_STP_ACCESS;
	e.access = access;

	if (flags & ARM64_MEM_PRE)
		model_writeback(base, imm);
	run_slots(base, index, flags, imm,
		  access == KPROG_ARM64_PAIR_MEM_ACCESS_LOAD, e.slots,
		  KPROG_ARM64_PAIR_MEM_SLOT_STRIDE, dst_reg, src_reg, src2_reg,
		  &e);
	if (flags & ARM64_MEM_POST)
		model_writeback(base, imm);

	snapshot(&e);
	return e;
}

/* The model step: everything restated from the raw opcode, with the literal
 * slot stride 8, and the pair sources read from the registers. */
static struct pair_effect model_step(unsigned op, unsigned base, unsigned index,
				     unsigned flags, __s64 imm, unsigned dst_reg,
				     unsigned src_reg, unsigned src2_reg)
{
	struct pair_effect e;
	int is_load = op == ARM64_OP_LDP;
	unsigned i;
	__u64 slot[8];
	__u64 p0 = 0, p1 = 0;

	memset(&e, 0, sizeof(e));
	e.idx = (op == ARM64_OP_LDP) ? 0U : 1U;
	e.access = is_load ? 0U : 1U;
	e.slots = 2U;

	if (flags & ARM64_MEM_PRE)
		model_writeback(base, imm);
	if (!is_load) {
		p0 = read_gpr(src_reg);
		p1 = read_gpr(src2_reg);
	}
	for (i = 0; i < 2U; i++) {
		__s64 off = (__s64)KPROG_ARM64_MEM_OFFSET(
				    flags & (ARM64_MEM_PRE | ARM64_MEM_POST),
				    index != ARM64_REG_NONE, imm, index) +
			    (__s64)i * 8;

		if (is_load) {
			slot[i] = model_read(base, off, ARM64_WIDTH_64);
		} else if (i == 0) {
			model_write(base, off, ARM64_WIDTH_64, p0,
				    ARM64_SIM_TAG_SCALAR);
		} else {
			model_write(base, off, ARM64_WIDTH_64, p1,
				    ARM64_SIM_TAG_SCALAR);
		}
	}
	if (is_load) {
		e.lo = slot[0];
		e.hi = slot[1];
		write_gpr(dst_reg, slot[0]);
		write_gpr(src_reg, slot[1]);
	} else {
		e.lo = p0;
		e.hi = p1;
	}
	if (flags & ARM64_MEM_POST)
		model_writeback(base, imm);

	snapshot(&e);
	return e;
}

static unsigned compare_effect(const struct pair_effect *c,
			       const struct pair_effect *m, unsigned op,
			       unsigned base, unsigned index, unsigned flags,
			       __s64 imm)
{
	unsigned k;
	int bad = 0;

	bad |= c->idx != m->idx;
	bad |= c->access != m->access;
	bad |= c->slots != m->slots;
	bad |= c->lo != m->lo;
	bad |= c->hi != m->hi;
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
		       "idx=%u/%u acc=%u/%u slots=%u/%u lo=%#llx/%#llx "
		       "hi=%#llx/%#llx sp=%#llx/%#llx\n",
		       op, base, index, flags, (unsigned long long)imm, c->idx,
		       m->idx, c->access, m->access, c->slots, m->slots,
		       (unsigned long long)c->lo, (unsigned long long)m->lo,
		       (unsigned long long)c->hi, (unsigned long long)m->hi,
		       (unsigned long long)c->sp, (unsigned long long)m->sp);
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
	static const unsigned op_val[2][2] = {
		{ ARM64_OP_LDP, 0U }, { ARM64_OP_STP, 1U },
	};

	if (KPROG_ARM64_PAIR_MEM_SLOT_STRIDE != ARM64_WIDTH_64 ||
	    KPROG_ARM64_PAIR_MEM_HIGH_SLOT_STRIDE != 8U) {
		fprintf(stderr, "pair mem slot stride drift\n");
		return 0;
	}
	cases++;

	if (KPROG_ARM64_PAIR_MEM_SLOT_COUNT != 2U) {
		fprintf(stderr, "pair mem slot count drift\n");
		return 0;
	}
	cases++;

	if (KPROG_ARM64_PAIR_MEM_ACCESS_LOAD ==
	    KPROG_ARM64_PAIR_MEM_ACCESS_STORE) {
		fprintf(stderr, "pair mem access codes collide\n");
		return 0;
	}
	cases++;

	if (KPROG_ARM64_PAIR_MEM_OP_LDP_ACCESS !=
		    KPROG_ARM64_PAIR_MEM_ACCESS_LOAD ||
	    KPROG_ARM64_PAIR_MEM_OP_STP_ACCESS !=
		    KPROG_ARM64_PAIR_MEM_ACCESS_STORE) {
		fprintf(stderr, "pair mem access direction drift\n");
		return 0;
	}
	cases++;

	if (KPROG_ARM64_PAIR_MEM_OP_LDP_INDEX != 0U ||
	    KPROG_ARM64_PAIR_MEM_OP_STP_INDEX != 1U) {
		fprintf(stderr, "pair mem index constant drift\n");
		return 0;
	}
	cases++;

	for (i = 0; i < 2U; i++) {
		unsigned got = KPROG_ARM64_PAIR_MEM_INDEX(op_val[i][0]);

		if (got != op_val[i][1]) {
			fprintf(stderr, "pair mem index select drift op=%#x "
					"got=%u want=%u\n",
				op_val[i][0], got, op_val[i][1]);
			return 0;
		}
		cases++;
	}

	if (KPROG_ARM64_PAIR_MEM_INDEX(0xffU) !=
	    KPROG_ARM64_PAIR_MEM_OP_STP_INDEX) {
		fprintf(stderr, "pair mem index not total off the opcode set\n");
		return 0;
	}
	cases++;

	return cases;
}

/* Seed the STP source pair with distinct values so a swapped pair source is
 * observable; both steps see the same seeded pair. */
static void seed_pair(unsigned src_reg, unsigned src2_reg, __u64 sv, __u64 tv)
{
	if (src_reg != ARM64_XZR && src_reg != ARM64_SP)
		regs[src_reg].value = sv;
	if (src2_reg != ARM64_XZR && src2_reg != ARM64_SP)
		regs[src2_reg].value = tv;
}

/* ------------------------------------------------------------------ */
/* Part 2: full composition vs. the hand-written bodies.               */
/* ------------------------------------------------------------------ */

static unsigned part2(void)
{
	static const unsigned ops[2] = { ARM64_OP_LDP, ARM64_OP_STP };
	static const unsigned regpick[7] = { 0U, 1U, 2U, 3U, 30U, ARM64_XZR,
					     ARM64_SP };
	static const unsigned flagset[3] = { 0U, ARM64_MEM_PRE, ARM64_MEM_POST };
	static const __s64 imms[] = { 0, 8, -8, 0x20, -0x40, 0x100 };
	__u64 state = 0x123456789abcdef0ULL;
	unsigned cases = 0, fails = 0;
	unsigned oi, di, si, ti, bi, fi, xi, pi;

	for (oi = 0; oi < 2U; oi++)
		for (di = 0; di < 7U; di++)
			for (si = 0; si < 7U; si++)
				for (ti = 0; ti < 2U; ti++)
					for (bi = 0; bi < ORACLE_REGS; bi++)
						for (fi = 0; fi < 3U; fi++)
							for (xi = 0; xi < 4U; xi++)
								for (pi = 0; pi < 6U;
								     pi++) {
									unsigned dreq = regpick[di];
									unsigned sreq = regpick[si];
									unsigned treq = 20U + ti;
									unsigned index = xi == 0U ? ARM64_REG_NONE : (2U + xi);
									__s64 imm = imms[pi];
									__u64 sv, tv;
									struct pair_effect c, m;

									state = state * 6364136223846793005ULL + 1442695040888963407ULL;
									sv = state ^ 0xa5a5a5a5a5a5a5a5ULL;
									tv = state * 0x9e3779b97f4a7c15ULL;

									restore_pristine();
									seed_pair(sreq, treq, sv, tv);
									c = contract_step(ops[oi], bi, index, flagset[fi], imm, dreq, sreq, treq);
									restore_pristine();
									seed_pair(sreq, treq, sv, tv);
									m = model_step(ops[oi], bi, index, flagset[fi], imm, dreq, sreq, treq);
									fails += compare_effect(&c, &m, ops[oi], bi, index, flagset[fi], imm);
									cases++;
								}

	if (fails) {
		printf("arm64 LDP/STP pair mem host cross-check: FAILED (%u mismatches)\n",
		       fails);
		return 1;
	}
	printf("arm64 LDP/STP pair mem host cross-check: OK (%u cases)\n", cases);
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
