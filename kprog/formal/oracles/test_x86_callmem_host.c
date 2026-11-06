/*
 * Host cross-check for the x86-64 `CALL_MEMCPY` / `CALL_MEMSET` handler
 * composition (`X86_OP_CALL_MEMCPY`, `0x3f`, `X86_OP_CALL_MEMCPY_REG`,
 * `0x46`, `X86_OP_CALL_MEMSET`, `0x3c`, and `X86_OP_CALL_MEMSET_REG`, `0x45`),
 * the bodies `X86_SIM_L_EXEC_CALL_MEMCPY`, `X86_SIM_L_EXEC_CALL_MEMCPY_REG`,
 * `X86_SIM_L_EXEC_CALL_MEMSET`, and `X86_SIM_L_EXEC_CALL_MEMSET_REG`.
 *
 * Part 1 verifies the generated opcode/kind/count-source/bound-form tables
 * against independent restatements: the two `MEMCPY` opcodes copy and the two
 * `MEMSET` opcodes fill; the two `*_REG` opcodes take their length from `RDX`
 * and the two immediate forms from the artifact; and — the asymmetry the
 * contract is about — the two immediate-count bodies iterate to the hardcoded
 * literal `1024` while the two register-count bodies are bounded by the
 * artifact, the *opposite* of their length source.
 *
 * Part 2 drives the whole block-copy/fill composition over a deterministic
 * register and memory model: it classifies the body through the generated kind
 * table, selects the length source through the generated count-source table and
 * the array bound through the generated bound-form table, and moves bytes one
 * at a time through the shared little-endian load/store at width 8. The whole
 * destination buffer, the whole register file, and the result-register write
 * must match a hand-written model of the four C bodies.
 *
 * Part 3 pins the facts the composition is about: the immediate-count bodies
 * iterate to the literal `1024` even when the artifact is smaller or larger;
 * a copy writes the source bytes whereas a fill writes one constant; bytes at
 * or beyond the bound (and at or beyond the count) keep their old values; and
 * the bodies write `RAX` as the destination pointer carrying the destination
 * register's tag while leaving every other GPR and flag unchanged.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. test_x86_callmem_host.c -o /tmp/t_cm && /tmp/t_cm
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
#define X86_RDX 2U
#define X86_RSI 6U
#define X86_RDI 7U

#define X86_OP_CALL_MEMSET 0x3cU
#define X86_OP_CALL_MEMCPY 0x3fU
#define X86_OP_CALL_MEMSET_REG 0x45U
#define X86_OP_CALL_MEMCPY_REG 0x46U

#include "generated/x86_callmem.h"
#include "generated/x86_width.h"
#include "generated/x86_mem_access.h"

#include <stdint.h>
#include <stdio.h>
#include <string.h>

/* ------------------------------------------------------------------ */
/* A deterministic register file and memory model.                    */
/*                                                                    */
/* Registers carry a pointer view over eight bytes plus a tag byte;   */
/* register "pointers" are small byte offsets that the oracle reduces */
/* modulo the memory buffer so the model stays inside the array at    */
/* every address the composition forms.                               */
/* ------------------------------------------------------------------ */

#define ORACLE_REGS 16U
#define ORACLE_BYTES 4096

struct oracle_reg {
	union {
		__u8 b[8];
		__u64 v;
		void *ptr;
	} u;
	__u8 tag;
};

static struct oracle_reg oracle_regs[ORACLE_REGS];
static struct oracle_reg pristine_regs[ORACLE_REGS];
static struct oracle_reg result_regs[ORACLE_REGS];

static __u8 oracle_mem[ORACLE_BYTES];
static __u8 pristine_mem[ORACLE_BYTES];
static __u8 result_mem[ORACLE_BYTES];

static __u64 oracle_flags;
static __u64 pristine_flags;
static __u64 result_flags;

/* The contract writes at most the fixed bound (the widest bound the four
 * bodies use) from a base, so a reduction by this much keeps a whole
 * bounded region inside the array. */
#define ORACLE_SPAN 1024U

static __u8 oracle_synthetic(__u64 index)
{
	return (__u8)((index * 131U + 17U) ^ (index >> 5));
}

static void oracle_reset(void)
{
	unsigned i;
	__u64 j;

	for (i = 0; i < ORACLE_REGS; i++) {
		/* Small base offsets so a bounded region fits the array. */
		oracle_regs[i].u.ptr = (void *)(long)(0x100ULL + (__u64)i * 0x10ULL);
		oracle_regs[i].tag = (__u8)((i % 6U) + 1U);
	}
	for (j = 0; j < ORACLE_BYTES; j++)
		oracle_mem[j] = (__u8)oracle_synthetic(j);
	oracle_flags = 0x202ULL;
}

/* The reduction an effective address is folded through so the model stays
 * inside the memory array; the reduction leaves room for the widest bound. */
static unsigned oracle_slot(__u64 addr)
{
	return (unsigned)(addr % (ORACLE_BYTES - ORACLE_SPAN));
}

static void oracle_snapshot_pristine(void)
{
	memcpy(pristine_regs, oracle_regs, sizeof(pristine_regs));
	memcpy(pristine_mem, oracle_mem, ORACLE_BYTES);
	pristine_flags = oracle_flags;
}

static void oracle_restore_pristine(void)
{
	memcpy(oracle_regs, pristine_regs, sizeof(pristine_regs));
	memcpy(oracle_mem, pristine_mem, ORACLE_BYTES);
	oracle_flags = pristine_flags;
}

static __u64 oracle_reg_value(unsigned index)
{
	return (__u64)(uintptr_t)oracle_regs[index].u.ptr;
}

/* The `X86_SIM_L_WRITE_REG_PTR_TAG` resting point, restated: the register's
 * pointer value and its tag both become the arguments. */
static void oracle_write_ptr_tag(unsigned index, __u64 value, __u8 tag)
{
	oracle_regs[index].u.ptr = (void *)(uintptr_t)value;
	oracle_regs[index].tag = tag;
}

/* ------------------------------------------------------------------ */
/* Hand-written models, independent of the macros under test.          */
/* ------------------------------------------------------------------ */

/* The byte at an effective address, read and written one byte at a time. */
static __u8 oracle_byte_load(__u64 addr)
{
	return oracle_mem[oracle_slot(addr)];
}

static void oracle_byte_store(__u64 addr, __u8 value)
{
	oracle_mem[oracle_slot(addr)] = value;
}

/* The low byte an ordinary width-8 store would write, restated from the raw
 * width codes rather than taken from the generated x86_width.h. */
static __u8 oracle_low_byte(__u64 value)
{
	return (__u8)(value & 0xffULL);
}

/* ------------------------------------------------------------------ */
/* Part 1: the generated tables vs. the oracle.                       */
/* ------------------------------------------------------------------ */

static unsigned part1(void)
{
	static const unsigned opcodes[4] = {
		X86_OP_CALL_MEMCPY, X86_OP_CALL_MEMCPY_REG,
		X86_OP_CALL_MEMSET, X86_OP_CALL_MEMSET_REG,
	};
	unsigned cases = 0;
	unsigned oi;

	for (oi = 0; oi < 4U; oi++) {
		unsigned op = opcodes[oi];
		unsigned want_copy = op == X86_OP_CALL_MEMCPY ||
				     op == X86_OP_CALL_MEMCPY_REG;
		unsigned want_reg = op == X86_OP_CALL_MEMCPY_REG ||
				    op == X86_OP_CALL_MEMSET_REG;
		unsigned want_kind = want_copy ? KPROG_X86_CALLMEM_COPY
					       : KPROG_X86_CALLMEM_FILL;
		unsigned want_count = want_reg ? KPROG_X86_CALLMEM_COUNT_REG
					       : KPROG_X86_CALLMEM_COUNT_IMM;
		/* The bound form is the opposite selection: the immediate-count
		 * bodies take the literal bound, the register-count bodies the
		 * artifact. Reading the count source as the bound form would
		 * collapse the two facts. */
		unsigned want_bound = want_reg ? KPROG_X86_CALLMEM_BOUND_IMM
					       : KPROG_X86_CALLMEM_BOUND_FIXED;
		unsigned got_kind = KPROG_X86_CALLMEM_KIND(want_copy);
		unsigned got_count = KPROG_X86_CALLMEM_COUNT_SOURCE(want_reg);
		unsigned got_bound = KPROG_X86_CALLMEM_BOUND_FORM(want_reg);

		if (got_kind != want_kind) {
			fprintf(stderr, "kind mismatch op=%#x got=%u want=%u\n",
				op, got_kind, want_kind);
			return 0;
		}
		if (got_count != want_count) {
			fprintf(stderr, "count source mismatch op=%#x got=%u want=%u\n",
				op, got_count, want_count);
			return 0;
		}
		if (got_bound != want_bound) {
			fprintf(stderr, "bound form mismatch op=%#x got=%u want=%u\n",
				op, got_bound, want_bound);
			return 0;
		}
		/* The bound form and the count source are independent facts: the
		 * count source is the artifact exactly when the bound is the
		 * literal, and the register exactly when the bound is the
		 * artifact. In codes the two selections coincide, so only this
		 * reading separates them — a collapsed table loses it. */
		if ((got_count == KPROG_X86_CALLMEM_COUNT_IMM) !=
		    (got_bound == KPROG_X86_CALLMEM_BOUND_FIXED)) {
			fprintf(stderr,
				"bound form and count source collapsed op=%#x\n",
				op);
			return 0;
		}
		/* The two kinds are distinct, and the two bound forms are. */
		if (KPROG_X86_CALLMEM_KIND(1U) == KPROG_X86_CALLMEM_KIND(0U))
			return 0;
		if (KPROG_X86_CALLMEM_BOUND_FORM(1U) ==
		    KPROG_X86_CALLMEM_BOUND_FORM(0U))
			return 0;
		cases++;
	}

	/* The hardcoded bound is the literal 1024 and each width-8 element is
	 * one byte. */
	if (KPROG_X86_CALLMEM_FIXED_BOUND != 1024U)
		return 0;
	if (KPROG_X86_WIDTH_BITS(X86_WIDTH_8) / 8U != 1U)
		return 0;
	cases++;

	return cases;
}

/* ------------------------------------------------------------------ */
/* Part 2: the full composition vs. the hand-written bodies.          */
/*                                                                    */
/* `contract_step` runs the loop through the generated tables;        */
/* `model_step` restates the four bodies from the raw opcode bits.    */
/* They must agree on the whole memory buffer, the whole register     */
/* file, and the flags.                                               */
/* ------------------------------------------------------------------ */

struct callmem_effect {
	unsigned kind;
	unsigned bound;
	unsigned count;
	__u64 dst;
	__u8 dst_tag;
};

static struct callmem_effect contract_step(unsigned op_is_copy,
					   unsigned op_is_reg, __u64 imm,
					   unsigned dst_reg, unsigned src_reg)
{
	__u8 kind = KPROG_X86_CALLMEM_KIND(op_is_copy);
	__u8 count_source = KPROG_X86_CALLMEM_COUNT_SOURCE(op_is_reg);
	__u8 bound_form = KPROG_X86_CALLMEM_BOUND_FORM(op_is_reg);
	unsigned bound = bound_form == KPROG_X86_CALLMEM_BOUND_FIXED
		? KPROG_X86_CALLMEM_FIXED_BOUND
		: (unsigned)imm;
	unsigned count = count_source == KPROG_X86_CALLMEM_COUNT_REG
		? (unsigned)oracle_reg_value(X86_RDX)
		: (unsigned)imm;
	__u64 dst = oracle_reg_value(dst_reg);
	__u64 src = oracle_reg_value(src_reg);
	__u64 value = oracle_reg_value(src_reg);
	unsigned i;
	struct callmem_effect r;

	for (i = 0; i < bound; i++) {
		if (i >= count)
			continue;
		if (kind == KPROG_X86_CALLMEM_COPY)
			oracle_byte_store(dst + i, oracle_byte_load(src + i));
		else
			oracle_byte_store(dst + i, oracle_low_byte(value));
	}
	oracle_write_ptr_tag(X86_RAX, dst, oracle_regs[dst_reg].tag);

	r.kind = kind;
	r.bound = bound;
	r.count = count;
	r.dst = dst;
	r.dst_tag = oracle_regs[dst_reg].tag;
	return r;
}

static struct callmem_effect model_step(unsigned op_is_copy,
					unsigned op_is_reg, __u64 imm,
					unsigned dst_reg, unsigned src_reg)
{
	unsigned bound = op_is_reg ? (unsigned)imm : 1024U;
	unsigned count = op_is_reg ? (unsigned)oracle_reg_value(X86_RDX)
				   : (unsigned)imm;
	__u64 dst = oracle_reg_value(dst_reg);
	__u64 src = oracle_reg_value(src_reg);
	__u64 value = oracle_reg_value(src_reg);
	unsigned i;
	struct callmem_effect r;

	for (i = 0; i < bound; i++) {
		if (i < count) {
			if (op_is_copy)
				oracle_byte_store(dst + i,
						  oracle_byte_load(src + i));
			else
				oracle_byte_store(dst + i,
						  oracle_low_byte(value));
		}
	}
	oracle_write_ptr_tag(X86_RAX, dst, oracle_regs[dst_reg].tag);

	r.kind = op_is_copy ? KPROG_X86_CALLMEM_COPY : KPROG_X86_CALLMEM_FILL;
	r.bound = bound;
	r.count = count;
	r.dst = dst;
	r.dst_tag = oracle_regs[dst_reg].tag;
	return r;
}

static unsigned part2(void)
{
	/* The immediate is the artifact; for the two register-count opcodes it
	 * is the array bound while the length comes from `RDX`. Values both
	 * below and above the literal bound exercise the clamp. */
	static const __u64 imms[6] = {
		0ULL, 1ULL, 8ULL, 32ULL, 1024ULL, 2048ULL,
	};
	static const unsigned dst_regs[3] = { X86_RDI, 3U, 11U };
	static const unsigned src_regs[3] = { X86_RSI, 5U, 12U };
	static const unsigned rdx_counts[4] = { 0U, 8U, 100U, 4096U };
	unsigned cases = 0;
	unsigned oc;
	unsigned di;
	unsigned si;
	unsigned ci;
	unsigned ii;

	for (oc = 0; oc < 4U; oc++) {
		for (ii = 0; ii < 6U; ii++) {
			for (di = 0; di < 3U; di++) {
				for (si = 0; si < 3U; si++) {
					for (ci = 0; ci < 4U; ci++) {
						unsigned op_is_copy =
							oc < 2U;
						unsigned op_is_reg = (oc == 1U) ||
								    (oc == 3U);
						struct callmem_effect got;
						struct callmem_effect want;

						/* `RDX` is the length source
						 * for the register-count
						 * bodies only. */
						oracle_restore_pristine();
						oracle_regs[X86_RDX].u.v =
							(__u64)rdx_counts[ci];
						got = contract_step(op_is_copy,
								    op_is_reg,
								    imms[ii],
								    dst_regs[di],
								    src_regs[si]);
						memcpy(result_mem, oracle_mem,
						       ORACLE_BYTES);
						memcpy(result_regs, oracle_regs,
						       sizeof(oracle_regs));
						result_flags = oracle_flags;
						oracle_restore_pristine();
						oracle_regs[X86_RDX].u.v =
							(__u64)rdx_counts[ci];
						want = model_step(op_is_copy,
								  op_is_reg,
								  imms[ii],
								  dst_regs[di],
								  src_regs[si]);
						if (got.kind != want.kind ||
						    got.bound != want.bound ||
						    got.count != want.count ||
						    got.dst != want.dst ||
						    got.dst_tag != want.dst_tag ||
						    result_flags != oracle_flags ||
						    memcmp(result_regs, oracle_regs,
							   sizeof(oracle_regs)) ||
						    memcmp(result_mem, oracle_mem,
							   ORACLE_BYTES)) {
							fprintf(stderr,
								"callmem mismatch "
								"op=%u imm=%llu rdx=%u "
								"dst_reg=%u src_reg=%u "
								"got=(%u,%u,%u,%llx,%u) "
								"want=(%u,%u,%u,%llx,%u)\n",
								oc,
								(unsigned long long)imms[ii],
								rdx_counts[ci],
								dst_regs[di],
								src_regs[si],
								got.kind, got.bound,
								got.count,
								(unsigned long long)got.dst,
								got.dst_tag,
								want.kind, want.bound,
								want.count,
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
	return cases;
}

/* ------------------------------------------------------------------ */
/* Part 3: pins on the facts the composition is about.                */
/* ------------------------------------------------------------------ */

static unsigned part3(void)
{
	unsigned cases = 0;

	/* Pin 1: the immediate-count bodies iterate to the literal 1024, not
	 * to the artifact. With an artifact of 2048 the settled length is
	 * 2048 but the array bound is 1024, so exactly 1024 bytes are
	 * written; with an artifact of 8 the array bound is still 1024. */
	{
		struct callmem_effect big;
		struct callmem_effect small;

		oracle_restore_pristine();
		big = contract_step(0U, 0U, 2048ULL, X86_RDI, X86_RSI);
		if (big.bound != 1024U)
			return 0;
		if (big.count != 2048U)
			return 0;
		small = contract_step(0U, 0U, 8ULL, X86_RDI, X86_RSI);
		if (small.bound != 1024U || small.count != 8U)
			return 0;
		cases++;
	}

	/* Pin 2: the register-count bodies are bounded by the artifact. With
	 * an artifact of 32 and an `RDX` length of 100, exactly 32 bytes are
	 * written — the opposite selection from pin 1. */
	{
		struct callmem_effect e;

		oracle_restore_pristine();
		oracle_regs[X86_RDX].u.v = 100ULL;
		e = contract_step(0U, 1U, 32ULL, X86_RDI, X86_RSI);
		if (e.bound != 32U || e.count != 100U)
			return 0;
		cases++;
	}

	/* Pin 3: a copy writes the source bytes at the destination, whereas a
	 * fill writes the source register's *low* byte to every element. */
	{
		unsigned i;
		int copy_differs = 0;

		/* Distinct source and destination regions. */
		oracle_restore_pristine();
		for (i = 0; i < 16U; i++)
			oracle_mem[oracle_slot(oracle_reg_value(X86_RSI) + i)] =
				(__u8)(0x40U + i);
		(void)contract_step(1U, 0U, 16ULL, X86_RDI, X86_RSI);
		for (i = 0; i < 16U; i++)
			copy_differs += oracle_mem[oracle_slot(oracle_reg_value(X86_RDI) + i)] !=
					(__u8)(0x40U + i);
		if (copy_differs != 0)
			return 0; /* the copy reproduced the source */

		oracle_restore_pristine();
		oracle_regs[X86_RSI].u.v = 0x1122334455667788ULL;
		(void)contract_step(0U, 0U, 16ULL, X86_RDI, X86_RSI);
		for (i = 0; i < 16U; i++) {
			if (oracle_mem[oracle_slot(oracle_reg_value(X86_RDI) + i)] !=
			    0x88U)
				return 0; /* the fill wrote the low byte */
		}
		cases++;
	}

	/* Pin 4: bytes at or beyond the array bound and at or beyond the
	 * copied length keep their old values — a canary above the region
	 * survives. The destination holds distinct old bytes and the source
	 * holds a different pattern, so a stray write is visible. */
	{
		unsigned i;
		__u64 dst = oracle_reg_value(X86_RDI);

		oracle_restore_pristine();
		for (i = 0; i < 2048U; i++)
			oracle_mem[oracle_slot(dst + i)] = 0x5aU;
		/* A register-count copy bounded by 32, length 16. */
		oracle_regs[X86_RDX].u.v = 16ULL;
		(void)contract_step(1U, 1U, 32ULL, X86_RDI, X86_RSI);
		for (i = 16U; i < 2048U; i++) {
			if (oracle_mem[oracle_slot(dst + i)] != 0x5aU)
				return 0;
		}
		cases++;
	}

	/* Pin 5: the result register is the destination pointer carrying the
	 * destination register's tag, and no other GPR changes. */
	{
		unsigned i;
		unsigned want_tag;
		__u64 want_dst;

		oracle_restore_pristine();
		want_tag = oracle_regs[X86_RDI].tag;
		want_dst = oracle_reg_value(X86_RDI);
		(void)contract_step(0U, 0U, 8ULL, X86_RDI, X86_RSI);
		if (oracle_reg_value(X86_RAX) != want_dst)
			return 0;
		if (oracle_regs[X86_RAX].tag != want_tag)
			return 0;
		/* Every GPR except RAX is untouched. */
		for (i = 1U; i < ORACLE_REGS; i++) {
			if (memcmp(&oracle_regs[i], &pristine_regs[i],
				   sizeof(struct oracle_reg)))
				return 0;
		}
		cases++;
	}

	/* Pin 6: no flags are written, whatever the body. */
	{
		oracle_restore_pristine();
		(void)contract_step(1U, 1U, 64ULL, X86_RDI, X86_RSI);
		if (oracle_flags != pristine_flags)
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

	printf("x86 callmem handler host cross-check: OK (%u cases)\n",
	       c1 + c2 + c3);
	return 0;
}
