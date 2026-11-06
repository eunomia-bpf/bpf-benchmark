/*
 * Host cross-check for the x86-64 `PUSH` / `POP` handler contract.
 *
 * The module under test is `generated/x86_pushpop.h`. It fixes, per opcode,
 * the stack-pointer step direction (PUSH decrements before its store, POP
 * increments after its load and destination write), the width each body
 * honours (PUSH hardcodes 64, POP resolves the opcode's FLAGS code with a
 * 64-bit fallback), the code an absent FLAGS resolves to, and the byte amount
 * both bodies step by.
 *
 * The two C handlers restate this logic inline — `X86_SIM_L_EXEC_PUSH` /
 * `X86_SIM_L_EXEC_POP` in `x86_sim_local_bpf.h` — and the generated header is
 * not on their include path, so this host cross-check is the tie between the
 * two: it drives the contract through the generated macros and restates the
 * same bodies from the raw opcode bit, and the two must agree byte for byte on
 * the whole register file, the stack frame, and the flags.
 *
 * The stack helper's byte framing (`X86_SIM_L_STACK_WRITE` / `_READ`) stays in
 * the C handlers and is hand-modelled here the way the movbe host cross-check
 * models it: the frame index is the stack-relative offset biased by the frame
 * size, and a narrow write touches only its low `width` bytes.
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

#define X86_RAX 0U
#define X86_RCX 1U
#define X86_RSP 4U

#define X86_OP_PUSH 0x12U
#define X86_OP_POP 0x13U

#define X86_SIM_TAG_SCALAR 0U

#include "generated/x86_pushpop.h"
#include "generated/x86_width.h"
#include "generated/x86_reg_write.h"

#include <stdint.h>
#include <stdio.h>
#include <string.h>

/* ------------------------------------------------------------------ */
/* A deterministic register file, stack frame and flags model.         */
/*                                                                    */
/* Registers carry a byte view, a 16-bit view and a pointer view over  */
/* the same eight bytes plus the tag byte, the way the register-write  */
/* helpers expect. The stack pointer's value is held as a small         */
/* stack-relative offset so the model stays inside the frame array.    */
/* ------------------------------------------------------------------ */

#define ORACLE_REGS 16U
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

static __u8 oracle_stack[ORACLE_STACK_BYTES];
static __u8 pristine_stack[ORACLE_STACK_BYTES];
static __u8 result_stack[ORACLE_STACK_BYTES];

static __u64 oracle_flags;
static __u64 result_flags;

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
			(void *)(long)(0x200ULL + (__u64)i * 0x20ULL);
		oracle_regs[i].tag = (__u8)(i % 6U);
	}
	for (j = 0; j < ORACLE_STACK_BYTES; j++)
		oracle_stack[j] = (__u8)oracle_synthetic(j + 7U);
}

static void oracle_snapshot_pristine(void)
{
	memcpy(pristine_regs, oracle_regs, sizeof(pristine_regs));
	memcpy(pristine_stack, oracle_stack, ORACLE_STACK_BYTES);
}

static void oracle_restore_pristine(void)
{
	memcpy(oracle_regs, pristine_regs, sizeof(pristine_regs));
	memcpy(oracle_stack, pristine_stack, ORACLE_STACK_BYTES);
}

static __u64 oracle_reg_value(unsigned index)
{
	return (__u64)(uintptr_t)oracle_regs[index].u.ptr;
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

/* The stack helper's load, restated: the frame index is the stack-relative
 * offset biased by the frame size, and the value is width-masked and read
 * little-endian. */
static __u64 oracle_stack_load(__s64 off, unsigned width)
{
	__u32 index = (__u32)((__s64)off + ORACLE_STACK_BYTES);
	__u64 v = 0;
	unsigned i;

	for (i = 0; i < width; i++)
		v |= (__u64)oracle_stack[(index + i) % ORACLE_STACK_BYTES]
		     << (8 * i);
	return v & oracle_mask(width);
}

/* The stack helper's store, restated. */
static void oracle_stack_store(__s64 off, unsigned width, __u64 value)
{
	__u32 index = (__u32)(off + ORACLE_STACK_BYTES);
	__u64 narrowed = value & oracle_mask(width);
	unsigned i;

	for (i = 0; i < width; i++)
		oracle_stack[(index + i) % ORACLE_STACK_BYTES] =
			(__u8)(narrowed >> (8 * i));
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

/* ------------------------------------------------------------------ */
/* Part 1: the generated tables vs. the oracle.                       */
/* ------------------------------------------------------------------ */

static unsigned part1(void)
{
	unsigned cases = 0;
	unsigned op;
	unsigned fa;

	for (op = 0; op < 2U; op++) {
		unsigned want_dir = op ? KPROG_X86_PUSH_STEP_POST_INCREMENT
				       : KPROG_X86_PUSH_STEP_PRE_DECREMENT;
		unsigned want_ws = op ? KPROG_X86_PUSH_WIDTH_FLAGS_OR_64
				      : KPROG_X86_PUSH_WIDTH_HARDCODED_64;
		unsigned got_dir = KPROG_X86_PUSH_STEP_DIRECTION(op);
		unsigned got_ws = KPROG_X86_PUSH_WIDTH_SOURCE(op);

		if (got_dir != want_dir) {
			fprintf(stderr, "step direction mismatch op=%u got=%u "
					"want=%u\n", op, got_dir, want_dir);
			return 0;
		}
		if (got_ws != want_ws) {
			fprintf(stderr, "width source mismatch op=%u got=%u "
					"want=%u\n", op, got_ws, want_ws);
			return 0;
		}
		/* The two facts are one selection: the body that pre-decrements
		 * is the body that hardcodes 64, and the body that
		 * post-increments is the body that resolves the FLAGS code. In
		 * codes the two selections coincide, so only this reading
		 * separates them — a collapsed table loses it. */
		if ((got_dir == KPROG_X86_PUSH_STEP_POST_INCREMENT) !=
		    (got_ws == KPROG_X86_PUSH_WIDTH_FLAGS_OR_64)) {
			fprintf(stderr,
				"step direction and width source collapsed op=%u\n",
				op);
			return 0;
		}
		cases++;
	}

	/* The two directions and the two width sources are distinct. */
	if (KPROG_X86_PUSH_STEP_DIRECTION(1U) ==
	    KPROG_X86_PUSH_STEP_DIRECTION(0U))
		return 0;
	if (KPROG_X86_PUSH_WIDTH_SOURCE(1U) == KPROG_X86_PUSH_WIDTH_SOURCE(0U))
		return 0;

	/* Both directions step the same amount: the literal 8. */
	if (KPROG_X86_PUSH_STACK_STEP != 8U) {
		fprintf(stderr, "stack step is %u, want 8\n",
			KPROG_X86_PUSH_STACK_STEP);
		return 0;
	}
	if (KPROG_X86_WIDTH_BITS(X86_WIDTH_64) / 8U != 8U)
		return 0;
	cases++;

	for (fa = 0; fa < 2U; fa++) {
		unsigned want = fa ? KPROG_X86_PUSH_FLAGS_ABSENT
				   : KPROG_X86_PUSH_FLAGS_RESOLVED;
		unsigned got = KPROG_X86_PUSH_FLAGS_WIDTH(fa);

		if (got != want) {
			fprintf(stderr, "flags width mismatch absent=%u got=%u "
					"want=%u\n", fa, got, want);
			return 0;
		}
		cases++;
	}
	if (KPROG_X86_PUSH_FLAGS_WIDTH(0U) == KPROG_X86_PUSH_FLAGS_WIDTH(1U))
		return 0;
	cases++;

	return cases;
}

/* ------------------------------------------------------------------ */
/* Part 2: the full composition vs. the hand-written bodies.          */
/*                                                                    */
/* `contract_step` runs the bodies through the generated tables;      */
/* `model_step` restates the two bodies from the raw opcode bit. They */
/* must agree on the whole register file, the whole stack frame, and  */
/* the flags.                                                         */
/* ------------------------------------------------------------------ */

struct pushpop_effect {
	unsigned direction;
	unsigned width_source;
	unsigned width;
	unsigned step;
	__u64 value;
	__u64 rsp_before;
	__u64 rsp_after;
	__u64 dst;
	__u8 dst_tag;
};

static struct pushpop_effect contract_step(unsigned op_is_pop, unsigned flags,
					   unsigned src_reg, unsigned dst_reg)
{
	unsigned direction = KPROG_X86_PUSH_STEP_DIRECTION(op_is_pop);
	unsigned width_source = KPROG_X86_PUSH_WIDTH_SOURCE(op_is_pop);
	unsigned step = KPROG_X86_PUSH_STACK_STEP;
	unsigned flags_code =
		KPROG_X86_PUSH_FLAGS_WIDTH(flags == KPROG_X86_PUSH_WIDTH_ABSENT);
	unsigned width = width_source == KPROG_X86_PUSH_WIDTH_FLAGS_OR_64
		? (flags_code == KPROG_X86_PUSH_FLAGS_ABSENT
			   ? X86_WIDTH_64
			   : flags)
		: X86_WIDTH_64;
	__u64 rsp = oracle_reg_value(X86_RSP);
	__u64 value;
	struct pushpop_effect r;

	r.direction = direction;
	r.width_source = width_source;
	r.width = width;
	r.step = step;
	r.rsp_before = rsp;

	if (direction == KPROG_X86_PUSH_STEP_PRE_DECREMENT) {
		/* PUSH: read the source, step down, then store 64 bits. */
		value = oracle_reg_value(src_reg);
		rsp -= step;
		oracle_regs[X86_RSP].u.ptr = (void *)(long)rsp;
		oracle_stack_store((__s64)rsp, X86_WIDTH_64, value);
	} else {
		/* POP: read at the resolved width, write the destination,
		 * then step up. */
		value = oracle_stack_load((__s64)rsp, width);
		if (width == X86_WIDTH_8)
			KPROG_X86_WRITE_REG8(oracle_regs[dst_reg].u,
					     oracle_regs[dst_reg].tag, value, 0U,
					     X86_SIM_TAG_SCALAR);
		else if (width == X86_WIDTH_16)
			KPROG_X86_WRITE_REG16(oracle_regs[dst_reg].u,
					      oracle_regs[dst_reg].tag, value,
					      X86_SIM_TAG_SCALAR);
		else if (width == X86_WIDTH_32)
			KPROG_X86_WRITE_REG32(oracle_regs[dst_reg].u,
					      oracle_regs[dst_reg].tag, value,
					      X86_SIM_TAG_SCALAR);
		else
			KPROG_X86_WRITE_REG64(oracle_regs[dst_reg].u,
					      oracle_regs[dst_reg].tag, value,
					      X86_SIM_TAG_SCALAR);
		rsp = oracle_reg_value(X86_RSP) + step;
		oracle_regs[X86_RSP].u.ptr = (void *)(long)rsp;
	}

	r.value = value;
	r.rsp_after = rsp;
	r.dst = oracle_reg_value(dst_reg);
	r.dst_tag = oracle_regs[dst_reg].tag;
	return r;
}

static struct pushpop_effect model_step(unsigned op_is_pop, unsigned flags,
					unsigned src_reg, unsigned dst_reg)
{
	unsigned width = flags ? flags : X86_WIDTH_64;
	__u64 rsp = oracle_reg_value(X86_RSP);
	__u64 value;
	struct pushpop_effect r;

	r.direction = op_is_pop ? KPROG_X86_PUSH_STEP_POST_INCREMENT
				: KPROG_X86_PUSH_STEP_PRE_DECREMENT;
	r.width_source = op_is_pop ? KPROG_X86_PUSH_WIDTH_FLAGS_OR_64
				   : KPROG_X86_PUSH_WIDTH_HARDCODED_64;
	r.width = op_is_pop ? width : X86_WIDTH_64;
	r.step = 8U;
	r.rsp_before = rsp;

	if (!op_is_pop) {
		value = oracle_reg_value(src_reg);
		rsp -= 8U;
		oracle_regs[X86_RSP].u.ptr = (void *)(long)rsp;
		oracle_stack_store((__s64)rsp, X86_WIDTH_64, value);
	} else {
		value = oracle_stack_load((__s64)rsp, width);
		oracle_regs[dst_reg].u.ptr =
			(void *)(long)oracle_write(oracle_reg_value(dst_reg),
						   value, width);
		oracle_regs[dst_reg].tag = X86_SIM_TAG_SCALAR;
		rsp = oracle_reg_value(X86_RSP) + 8U;
		oracle_regs[X86_RSP].u.ptr = (void *)(long)rsp;
	}

	r.value = value;
	r.rsp_after = rsp;
	r.dst = oracle_reg_value(dst_reg);
	r.dst_tag = oracle_regs[dst_reg].tag;
	return r;
}

static unsigned part2(void)
{
	static const unsigned flags_codes[5] = { 0U, X86_WIDTH_8, X86_WIDTH_16,
						 X86_WIDTH_32, X86_WIDTH_64 };
	static const __s64 rsp_values[5] = { -8, -16, -32, -56, -12 };
	static const unsigned src_regs[3] = { X86_RAX, X86_RSP, 3U };
	static const unsigned dst_regs[3] = { X86_RCX, X86_RSP, 11U };
	unsigned cases = 0;
	unsigned op;
	unsigned fi;
	unsigned ri;
	unsigned si;
	unsigned di;

	for (op = 0; op < 2U; op++) {
		for (fi = 0; fi < 5U; fi++) {
			for (ri = 0; ri < 5U; ri++) {
				for (si = 0; si < 3U; si++) {
					for (di = 0; di < 3U; di++) {
						struct pushpop_effect got;
						struct pushpop_effect want;

						oracle_restore_pristine();
						oracle_regs[X86_RSP].u.ptr =
							(void *)(long)rsp_values[ri];
						oracle_flags = 0xdeadbeefULL;
						got = contract_step(
							op, flags_codes[fi],
							src_regs[si],
							dst_regs[di]);
						memcpy(result_regs, oracle_regs,
						       sizeof(oracle_regs));
						memcpy(result_stack, oracle_stack,
						       ORACLE_STACK_BYTES);
						result_flags = oracle_flags;

						oracle_restore_pristine();
						oracle_regs[X86_RSP].u.ptr =
							(void *)(long)rsp_values[ri];
						oracle_flags = 0xdeadbeefULL;
						want = model_step(
							op, flags_codes[fi],
							src_regs[si],
							dst_regs[di]);

						if (got.width != want.width ||
						    got.value != want.value ||
						    got.rsp_after != want.rsp_after ||
						    got.dst != want.dst ||
						    got.dst_tag != want.dst_tag ||
						    result_flags != oracle_flags ||
						    memcmp(result_regs, oracle_regs,
							   sizeof(oracle_regs)) ||
						    memcmp(result_stack, oracle_stack,
							   ORACLE_STACK_BYTES)) {
							fprintf(stderr,
								"pushpop mismatch "
								"op=%u flags=%u "
								"rsp=%lld src=%u "
								"dst=%u\n",
								op, flags_codes[fi],
								(long long)rsp_values[ri],
								src_regs[si],
								dst_regs[di]);
							return 0;
						}
						cases++;
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

	/* Pin 1: PUSH ignores a narrow FLAGS code — it always stores eight
	 * bytes and steps by eight — and the whole eight-byte value lands. */
	{
		static const __u64 pushed = 0x1122334455667788ULL;
		struct pushpop_effect narrow;
		struct pushpop_effect absent;
		unsigned i;
		unsigned wrong = 0;

		oracle_restore_pristine();
		oracle_regs[X86_RSP].u.ptr = (void *)(long)-8;
		oracle_regs[X86_RAX].u.ptr = (void *)(long)pushed;
		narrow = contract_step(0U, X86_WIDTH_8, X86_RAX, X86_RCX);
		memcpy(result_stack, oracle_stack, ORACLE_STACK_BYTES);

		oracle_restore_pristine();
		oracle_regs[X86_RSP].u.ptr = (void *)(long)-8;
		oracle_regs[X86_RAX].u.ptr = (void *)(long)pushed;
		absent = contract_step(0U, 0U, X86_RAX, X86_RCX);

		if (narrow.width != X86_WIDTH_64)
			return 0;
		if (absent.width != X86_WIDTH_64)
			return 0;
		if (narrow.rsp_after != absent.rsp_after)
			return 0;
		if (memcmp(result_stack, oracle_stack, ORACLE_STACK_BYTES))
			return 0;
		/* The pushed value sits at index -8 - 8 + 64 = 48. */
		for (i = 0; i < 8U; i++)
			wrong += result_stack[48U + i] !=
				 (__u8)((pushed >> (8U * i)) & 0xffULL);
		if (wrong != 0)
			return 0;
		cases++;
	}

	/* Pin 2: POP at an absent FLAGS code defaults to 64 bits and still
	 * steps by exactly eight. */
	{
		struct pushpop_effect e;

		oracle_restore_pristine();
		oracle_regs[X86_RSP].u.ptr = (void *)(long)-8;
		e = contract_step(1U, 0U, X86_RAX, X86_RCX);
		if (e.width != X86_WIDTH_64)
			return 0;
		if (e.rsp_after != (__u64)(long)0)
			return 0;
		if (e.dst != oracle_stack_load((__s64)-8, X86_WIDTH_64))
			return 0;
		cases++;
	}

	/* Pin 3: a push/pop pair round-trips the pointer and the 64-bit
	 * value. */
	{
		static const __u64 v = 0x0102030405060708ULL;
		struct pushpop_effect p;
		struct pushpop_effect q;

		oracle_restore_pristine();
		oracle_regs[X86_RSP].u.ptr = (void *)(long)-8;
		oracle_regs[X86_RAX].u.ptr = (void *)(long)v;
		p = contract_step(0U, 0U, X86_RAX, X86_RCX);
		q = contract_step(1U, 0U, X86_RAX, X86_RCX);
		if (p.rsp_after != (__u64)(long)-16)
			return 0;
		if (q.rsp_after != (__u64)(long)-8)
			return 0;
		if (q.value != v)
			return 0;
		if (oracle_reg_value(X86_RCX) != v)
			return 0;
		cases++;
	}

	/* Pin 4: both directions step the same amount. */
	{
		struct pushpop_effect p;
		struct pushpop_effect q;

		oracle_restore_pristine();
		oracle_regs[X86_RSP].u.ptr = (void *)(long)-32;
		p = contract_step(0U, 0U, X86_RAX, X86_RCX);
		oracle_restore_pristine();
		oracle_regs[X86_RSP].u.ptr = (void *)(long)-32;
		q = contract_step(1U, 0U, X86_RAX, X86_RCX);
		if (p.rsp_before - p.rsp_after != 8U)
			return 0;
		if (q.rsp_after - q.rsp_before != 8U)
			return 0;
		cases++;
	}

	/* Pin 5: PUSH writes no register except the stack pointer. */
	{
		unsigned i;

		oracle_restore_pristine();
		oracle_regs[X86_RSP].u.ptr = (void *)(long)-8;
		(void)contract_step(0U, 0U, X86_RAX, X86_RCX);
		for (i = 0; i < ORACLE_REGS; i++) {
			if (i == X86_RSP)
				continue;
			if (memcmp(&oracle_regs[i], &pristine_regs[i],
				   sizeof(struct oracle_reg)))
				return 0;
		}
		cases++;
	}

	/* Pin 6: POP at an eight-bit FLAGS code reads one byte and keeps the
	 * destination's upper bytes, unlike the 64-bit form which replaces
	 * them. */
	{
		static const __u64 old = 0xaaaaaaaaaaaaaaaaULL;
		__u64 low;

		oracle_restore_pristine();
		oracle_regs[X86_RSP].u.ptr = (void *)(long)-8;
		oracle_regs[X86_RCX].u.ptr = (void *)(long)old;
		low = oracle_stack_load((__s64)-8, X86_WIDTH_8);
		(void)contract_step(1U, X86_WIDTH_8, X86_RAX, X86_RCX);
		if (oracle_reg_value(X86_RCX) !=
		    ((old & ~0xffULL) | (low & 0xffULL)))
			return 0;
		cases++;
	}

	/* Pin 7: neither body writes a flag. */
	{
		oracle_restore_pristine();
		oracle_flags = 0x123456789ULL;
		(void)contract_step(0U, 0U, X86_RAX, X86_RCX);
		(void)contract_step(1U, 0U, X86_RAX, X86_RCX);
		if (oracle_flags != 0x123456789ULL)
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

	/* Each part returns zero exactly when a case failed, so any zero is a
	 * failure even though the readiness line still prints. */
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

	printf("x86 pushpop handler host cross-check: OK (%u cases)\n",
	       c1 + c2 + c3);
	return 0;
}
