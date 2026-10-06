/*
 * Host cross-check for the x86-64 pointer-write provenance handler
 * (`X86_OP_MOV_LOAD_MAP_PTR`, `0x2c`, and `X86_OP_MOV_LOAD_HELPER_ID`, `0x2d`),
 * the two `X86_SIM_L_EXEC` arms that install pointer bits together with a
 * provenance tag.
 *
 * This is the first handler whose sim C actually routes through the generated
 * contract rather than restating it: the two arms call
 * `KPROG_X86_PTR_WRITE_TAG` for the tag and `KPROG_X86_PTR_WRITE_IS_HELPER_ID`
 * to gate the helper-id arm's preliminary width-64 scalar lane write, then
 * perform the pointer write through `X86_SIM_L_WRITE_REG_PTR_TAG`. The oracle
 * therefore drives the generated macros exactly as the arms do and compares
 * against a hand-written model of the arms.
 *
 * Part 1 pins the generated tag table against an independent restatement of
 * the raw codes and asserts the out-of-range fallthrough code is distinct.
 *
 * Part 2 exercises the tag selector over all four fact pairs against an
 * independent nesting that restates the chain's map-pointer-first order.
 *
 * Part 3 exercises `KPROG_X86_PTR_WRITE_IS_HELPER_ID` over every tag byte.
 *
 * Part 4 drives the whole arm over a deterministic register file: the tag is
 * selected, the helper-id arm's lane write is gated, and the pointer write
 * installs the bits and the tag. The whole register file, the lane-write
 * count, and the flags must match the hand-written model.
 *
 * Part 5 pins the asymmetries the handler is about: the map-pointer arm writes
 * no width at all; the helper-id arm's width-64 lane write is replaced bit for
 * bit by the pointer write, so the two writes are observationally one
 * pointer+tag write; neither arm writes flags; `X86_REG_NONE` writes nothing;
 * and the pointer bits alone do not distinguish the two provenances.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. test_x86_mov_load_map_ptr_host.c -o /tmp/t_pw && /tmp/t_pw
 */
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;
typedef signed char __s8;
typedef short __s16;
typedef int __s32;
typedef signed long long __s64;

#define X86_WIDTH_8 1U
#define X86_WIDTH_16 2U
#define X86_WIDTH_32 4U
#define X86_WIDTH_64 8U

#define X86_REG_NONE 0xffU
#define X86_RSP 4U

#define X86_OP_MOV_LOAD_MAP_PTR 0x2cU
#define X86_OP_MOV_LOAD_HELPER_ID 0x2dU
#define X86_OP_MOVBE_LOAD 0x28U
#define X86_OP_UNRELATED 0x2bU

#define X86_SIM_TAG_SCALAR 0U
#define X86_SIM_TAG_ABI 1U
#define X86_SIM_TAG_PACKET 2U
#define X86_SIM_TAG_PACKET_END 3U
#define X86_SIM_TAG_STACK 4U
#define X86_SIM_TAG_MAP_PTR 5U
#define X86_SIM_TAG_MAP_VALUE 6U
#define X86_SIM_TAG_HELPER_ID 7U

#include "generated/x86_ptr_write.h"
#include "generated/x86_reg_write.h"

#include <stdint.h>
#include <stdio.h>
#include <string.h>

/* ------------------------------------------------------------------ */
/* A deterministic register file and flag model.                      */
/*                                                                    */
/* Registers carry a byte view, a 16-bit view and a pointer view over */
/* the same eight bytes plus the tag byte, the way the register-write */
/* helpers expect.                                                    */
/* ------------------------------------------------------------------ */

#define ORACLE_REGS 16U

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

struct oracle_flags {
	__u8 cf;
	__u8 zf;
	__u8 sf;
	__u8 of;
};

static struct oracle_flags oracle_flags;
static struct oracle_flags pristine_flags;

/* The number of preliminary width-64 scalar lane writes the contract makes;
 * this is the one thing the final register bits cannot show, because the
 * pointer write replaces the lane. */
static __u64 oracle_lane_writes;

static void oracle_reset(void)
{
	unsigned i;

	for (i = 0; i < ORACLE_REGS; i++) {
		oracle_regs[i].u.ptr =
			(void *)(long)(0x200ULL + (__u64)i * 0x20ULL);
		oracle_regs[i].tag = (__u8)(i % 6U);
	}
	oracle_flags.cf = 1U;
	oracle_flags.zf = 1U;
	oracle_flags.sf = 1U;
	oracle_flags.of = 1U;
	oracle_lane_writes = 0U;
}

static void oracle_snapshot_pristine(void)
{
	memcpy(pristine_regs, oracle_regs, sizeof(pristine_regs));
	pristine_flags = oracle_flags;
}

static void oracle_restore_pristine(void)
{
	memcpy(oracle_regs, pristine_regs, sizeof(pristine_regs));
	oracle_flags = pristine_flags;
	oracle_lane_writes = 0U;
}

static __u64 oracle_reg_value(unsigned index)
{
	return (__u64)(uintptr_t)oracle_regs[index].u.ptr;
}

/* ------------------------------------------------------------------ */
/* The sim's register-write primitives, restated as the two arms use  */
/* them. `X86_REG_NONE` names no register, so the sim's switch falls   */
/* through without writing anything.                                  */
/* ------------------------------------------------------------------ */

static void arm_scalar_lane(unsigned dst, __u64 value)
{
	if (dst == X86_REG_NONE)
		return;
	KPROG_X86_WRITE_REG64(oracle_regs[dst].u, oracle_regs[dst].tag,
			      value, X86_SIM_TAG_SCALAR);
	oracle_lane_writes++;
}

static void arm_ptr_tag(unsigned dst, __u64 value, __u8 tag)
{
	if (dst == X86_REG_NONE)
		return;
	oracle_regs[dst].u.ptr = (void *)(long)value;
	oracle_regs[dst].tag = tag;
}

/* ------------------------------------------------------------------ */
/* Hand-written models, independent of the macros under test.          */
/* ------------------------------------------------------------------ */

/* The opcode-to-tag table, restated from the raw codes rather than taken
 * from the generated defines. */
static __u8 model_tag(unsigned op)
{
	if (op == X86_OP_MOV_LOAD_MAP_PTR)
		return 5U;
	if (op == X86_OP_MOV_LOAD_HELPER_ID)
		return 7U;
	return 0xffU;
}

static unsigned model_is_helper(unsigned op)
{
	return op == X86_OP_MOV_LOAD_HELPER_ID;
}

struct ptr_write_effect {
	__u8 tag;
	unsigned is_helper;
	__u64 dst;
	__u8 dst_tag;
	__u64 lane_writes;
};

/* The contract path: exactly the macro sequence the two `X86_SIM_L_EXEC` arms
 * run. */
static struct ptr_write_effect contract_step(unsigned dst, unsigned op,
					     __u64 imm)
{
	__u8 tag = KPROG_X86_PTR_WRITE_TAG(op == X86_OP_MOV_LOAD_MAP_PTR,
					   op == X86_OP_MOV_LOAD_HELPER_ID);
	struct ptr_write_effect r;

	if (KPROG_X86_PTR_WRITE_IS_HELPER_ID(tag))
		arm_scalar_lane(dst, imm);
	arm_ptr_tag(dst, imm, tag);

	r.tag = tag;
	r.is_helper = KPROG_X86_PTR_WRITE_IS_HELPER_ID(tag);
	r.dst = dst == X86_REG_NONE ? 0ULL : oracle_reg_value(dst);
	r.dst_tag = dst == X86_REG_NONE ? 0U : oracle_regs[dst].tag;
	r.lane_writes = oracle_lane_writes;
	return r;
}

/* The model path: the raw predicate nesting, without the generated macros. */
static struct ptr_write_effect model_step(unsigned dst, unsigned op, __u64 imm)
{
	__u8 tag = model_tag(op);
	unsigned helper = model_is_helper(op);
	struct ptr_write_effect r;

	if (helper && dst != X86_REG_NONE) {
		/* The width-64 scalar lane write replaces the register
		 * outright and clears the tag to scalar; the pointer write
		 * below then replaces both. */
		oracle_lane_writes++;
	}
	if (dst != X86_REG_NONE) {
		oracle_regs[dst].u.ptr = (void *)(long)imm;
		oracle_regs[dst].tag = tag;
	}

	r.tag = tag;
	r.is_helper = helper;
	r.dst = dst == X86_REG_NONE ? 0ULL : oracle_reg_value(dst);
	r.dst_tag = dst == X86_REG_NONE ? 0U : oracle_regs[dst].tag;
	r.lane_writes = oracle_lane_writes;
	return r;
}

/* ------------------------------------------------------------------ */
/* Part 1: the generated tag table vs. the oracle.                     */
/* ------------------------------------------------------------------ */

static unsigned part1(void)
{
	unsigned cases = 0U;

	if (KPROG_X86_PTR_WRITE_TAG_SCALAR != 0U)
		return 0U;
	if (KPROG_X86_PTR_WRITE_TAG_MAP_PTR != 5U)
		return 0U;
	if (KPROG_X86_PTR_WRITE_TAG_HELPER_ID != 7U)
		return 0U;
	cases++;

	if (KPROG_X86_PTR_WRITE_TAG_MAP_PTR != X86_SIM_TAG_MAP_PTR ||
	    KPROG_X86_PTR_WRITE_TAG_HELPER_ID != X86_SIM_TAG_HELPER_ID ||
	    KPROG_X86_PTR_WRITE_TAG_SCALAR != X86_SIM_TAG_SCALAR)
		return 0U;
	cases++;

	/* The fallthrough code names no real tag: it is distinct from every
	 * generated tag, and the two real tags are distinct from each other
	 * so the tag distinguishes provenance. */
	if (KPROG_X86_PTR_WRITE_TAG_ANY == KPROG_X86_PTR_WRITE_TAG_MAP_PTR ||
	    KPROG_X86_PTR_WRITE_TAG_ANY == KPROG_X86_PTR_WRITE_TAG_HELPER_ID ||
	    KPROG_X86_PTR_WRITE_TAG_ANY == KPROG_X86_PTR_WRITE_TAG_SCALAR)
		return 0U;
	if (KPROG_X86_PTR_WRITE_TAG_MAP_PTR == KPROG_X86_PTR_WRITE_TAG_HELPER_ID)
		return 0U;
	cases++;

	return cases;
}

/* ------------------------------------------------------------------ */
/* Part 2: the tag selector over every fact pair vs. the oracle.       */
/* ------------------------------------------------------------------ */

static unsigned part2(void)
{
	unsigned cases = 0U;
	unsigned mp;
	unsigned hp;

	for (mp = 0U; mp < 2U; mp++) {
		for (hp = 0U; hp < 2U; hp++) {
			__u8 got = KPROG_X86_PTR_WRITE_TAG(mp, hp);
			__u8 want;

			/* The chain tests the map-pointer fact first. */
			if (mp)
				want = KPROG_X86_PTR_WRITE_TAG_MAP_PTR;
			else if (hp)
				want = KPROG_X86_PTR_WRITE_TAG_HELPER_ID;
			else
				want = KPROG_X86_PTR_WRITE_TAG_ANY;

			if (got != want) {
				fprintf(stderr,
					"tag selector mismatch map=%u helper=%u "
					"got=%u want=%u\n", mp, hp, got, want);
				return 0U;
			}
			cases++;
		}
	}
	return cases;
}

/* ------------------------------------------------------------------ */
/* Part 3: the helper-id test over every tag byte vs. the oracle.      */
/* ------------------------------------------------------------------ */

static unsigned part3(void)
{
	unsigned cases = 0U;
	unsigned code;

	for (code = 0U; code < 256U; code++) {
		unsigned want = code == X86_SIM_TAG_HELPER_ID;
		unsigned got = KPROG_X86_PTR_WRITE_IS_HELPER_ID((__u8)code);

		if (got != want) {
			fprintf(stderr,
				"helper-id test mismatch tag=%u got=%u want=%u\n",
				code, got, want);
			return 0U;
		}
		cases++;
	}
	return cases;
}

/* ------------------------------------------------------------------ */
/* Part 4: the full arm composition vs. the hand-written arm.          */
/*                                                                    */
/* The whole register file, the lane-write count and the flags are    */
/* compared; the pointer bits alone cannot show a dropped or extra    */
/* lane write, which is exactly the asymmetry under test.             */
/* ------------------------------------------------------------------ */

static unsigned part4(void)
{
	static const unsigned ops[4] = {
		X86_OP_MOV_LOAD_MAP_PTR,
		X86_OP_MOV_LOAD_HELPER_ID,
		X86_OP_MOVBE_LOAD,
		X86_OP_UNRELATED,
	};
	static const unsigned dsts[3] = { 3U, 7U, X86_REG_NONE };
	static const __u64 imms[4] = {
		0xdeadbeefdeadbeefULL,
		0x0000000000000000ULL,
		0x0000000000000001ULL,
		0xffffffffffffffffULL,
	};
	unsigned cases = 0U;
	unsigned oi;
	unsigned di;
	unsigned ii;

	for (oi = 0U; oi < 4U; oi++) {
		for (di = 0U; di < 3U; di++) {
			for (ii = 0U; ii < 4U; ii++) {
				struct ptr_write_effect got;
				struct ptr_write_effect want;
				struct oracle_flags got_flags;

				oracle_restore_pristine();
				got = contract_step(dsts[di], ops[oi], imms[ii]);
				memcpy(result_regs, oracle_regs,
				       sizeof(oracle_regs));
				got_flags = oracle_flags;
				oracle_restore_pristine();
				want = model_step(dsts[di], ops[oi], imms[ii]);

				if (got.tag != want.tag ||
				    got.is_helper != want.is_helper ||
				    got.dst != want.dst ||
				    got.dst_tag != want.dst_tag ||
				    got.lane_writes != want.lane_writes ||
				    memcmp(result_regs, oracle_regs,
					   sizeof(oracle_regs)) ||
				    memcmp(&got_flags, &oracle_flags,
					   sizeof(oracle_flags))) {
					fprintf(stderr,
						"ptr-write arm mismatch op=%x "
						"dst=%u imm=%llx "
						"got=(%u,%u,%llx,%u,%llu) "
						"want=(%u,%u,%llx,%u,%llu)\n",
						ops[oi], dsts[di],
						(unsigned long long)imms[ii],
						got.tag, got.is_helper,
						(unsigned long long)got.dst,
						got.dst_tag,
						(unsigned long long)got.lane_writes,
						want.tag, want.is_helper,
						(unsigned long long)want.dst,
						want.dst_tag,
						(unsigned long long)want.lane_writes);
					return 0U;
				}
				cases++;
			}
		}
	}
	return cases;
}

/* ------------------------------------------------------------------ */
/* Part 5: pins on the asymmetries the handler is about.               */
/* ------------------------------------------------------------------ */

static unsigned part5(void)
{
	unsigned cases = 0U;

	/* Pin 1: the map-pointer arm writes no width at all — no preliminary
	 * lane write and full 64-bit pointer bits with the map-pointer tag. */
	{
		struct ptr_write_effect e;

		oracle_restore_pristine();
		e = contract_step(2U, X86_OP_MOV_LOAD_MAP_PTR,
				  0x0123456789abcdefULL);
		if (e.lane_writes != 0ULL)
			return 0U;
		if (e.tag != X86_SIM_TAG_MAP_PTR)
			return 0U;
		if (oracle_reg_value(2U) != 0x0123456789abcdefULL)
			return 0U;
		if (oracle_regs[2].tag != X86_SIM_TAG_MAP_PTR)
			return 0U;
		cases++;
	}

	/* Pin 2: the helper-id arm writes exactly one preliminary width-64
	 * lane, and the pointer write replaces it bit for bit, so the state
	 * equals a bare pointer write with the helper-id tag. */
	{
		struct ptr_write_effect e;
		struct oracle_reg bare[ORACLE_REGS];
		unsigned i;

		oracle_restore_pristine();
		e = contract_step(2U, X86_OP_MOV_LOAD_HELPER_ID,
				  0x0123456789abcdefULL);
		if (e.lane_writes != 1ULL)
			return 0U;
		if (e.tag != X86_SIM_TAG_HELPER_ID)
			return 0U;
		if (oracle_reg_value(2U) != 0x0123456789abcdefULL)
			return 0U;
		if (oracle_regs[2].tag != X86_SIM_TAG_HELPER_ID)
			return 0U;
		cases++;

		memcpy(bare, oracle_regs, sizeof(bare));
		oracle_restore_pristine();
		arm_ptr_tag(2U, 0x0123456789abcdefULL, X86_SIM_TAG_HELPER_ID);
		for (i = 0U; i < ORACLE_REGS; i++) {
			if (memcmp(&bare[i], &oracle_regs[i], sizeof(bare[i])))
				return 0U;
		}
		cases++;
	}

	/* Pin 3: neither arm writes flags. */
	{
		struct oracle_flags before;

		oracle_restore_pristine();
		before = oracle_flags;
		contract_step(2U, X86_OP_MOV_LOAD_MAP_PTR, 0x20ULL);
		contract_step(2U, X86_OP_MOV_LOAD_HELPER_ID, 0x30ULL);
		if (memcmp(&before, &oracle_flags, sizeof(before)))
			return 0U;
		cases++;
	}

	/* Pin 4: `X86_REG_NONE` writes neither the register nor the lane. */
	{
		struct ptr_write_effect e;

		oracle_restore_pristine();
		e = contract_step(X86_REG_NONE, X86_OP_MOV_LOAD_HELPER_ID,
				  0x40ULL);
		if (e.lane_writes != 0ULL)
			return 0U;
		if (memcmp(pristine_regs, oracle_regs, sizeof(pristine_regs)))
			return 0U;
		cases++;
	}

	/* Pin 5: identical pointer bits under the two opcodes carry
	 * different tags, so the tag is what distinguishes the provenance. */
	{
		__u8 tag_a;
		__u8 tag_b;

		oracle_restore_pristine();
		contract_step(5U, X86_OP_MOV_LOAD_MAP_PTR, 0x50ULL);
		tag_a = oracle_regs[5].tag;
		oracle_restore_pristine();
		contract_step(5U, X86_OP_MOV_LOAD_HELPER_ID, 0x50ULL);
		tag_b = oracle_regs[5].tag;
		if (oracle_reg_value(5U) != 0x50ULL)
			return 0U;
		if (tag_a == tag_b)
			return 0U;
		if (tag_a != X86_SIM_TAG_MAP_PTR ||
		    tag_b != X86_SIM_TAG_HELPER_ID)
			return 0U;
		cases++;
	}

	/* Pin 6: the chain's fallthrough — both facts false — yields the
	 * out-of-range code, so no real opcode can be mistaken for the other
	 * arm. */
	{
		__u8 tag = KPROG_X86_PTR_WRITE_TAG(0U, 0U);

		if (tag != KPROG_X86_PTR_WRITE_TAG_ANY)
			return 0U;
		if (KPROG_X86_PTR_WRITE_IS_HELPER_ID(tag))
			return 0U;
		cases++;
	}

	return cases;
}

int main(void)
{
	unsigned total = 0U;

	oracle_reset();
	oracle_snapshot_pristine();

	total += part1();
	total += part2();
	total += part3();

	oracle_restore_pristine();
	total += part4();
	oracle_restore_pristine();
	total += part5();

	printf("x86 mov_load_map_ptr/helper_id handler host cross-check: OK (%u cases)\n",
	       total);
	return 0;
}
