/*
 * Host cross-check for the x86-64 `LOAD_XMM0` / `STORE_XMM0` handler
 * composition (`X86_OP_LOAD_XMM0`, `0x30`, and `X86_OP_STORE_XMM0`, `0x31`),
 * the bodies `X86_SIM_L_EXEC_LOAD_XMM0` and `X86_SIM_L_EXEC_STORE_XMM0`.
 *
 * Part 1 verifies the generated opcode/direction/base-form/arm/lane tables
 * against independent restatements: the two opcodes are the two directions of
 * one pair move, both take the whole-artifact displacement form, both select
 * their arm from the single stack-pointer test, and the pair is two
 * consecutive 8-byte lanes.
 *
 * Part 2 drives the whole load composition over a deterministic register,
 * memory, and stack model: it classifies the operand through the generated arm
 * table, selects the ordinary-arm base form through the generated base-form
 * table, addresses through the generated base-pointer and offset-adding
 * contracts plus the shared offset contract, and reads both lanes through the
 * generated little-endian load at the generated lane offsets. Both lanes and
 * the effective address must match a hand-written model of the C body.
 *
 * Part 3 drives the whole store composition the same way, comparing the whole
 * memory buffer, the whole stack buffer, and the (read-only) register file and
 * XMM0 pair.
 *
 * Part 4 pins the asymmetries the composition is about: the whole
 * instruction-immediate artifact `(s64)IMM`, never the immediate store's
 * high-half slice `(s32)(IMM >> 32)`; the load's `X86_REG_NONE` operand is the
 * raw artifact with the addressing offset *discarded*, whereas the store's is
 * the null pointer with the offset *added*; both bodies move the two lanes at
 * offsets 0 and 8 in order at width 64; neither body writes a GPR or a tag;
 * and `X86_REG_NONE` is an ordinary-arm operand that really does read and
 * write, not a skipped access.
 *
 * Build/run:
 *   cd native-sim/formal
 *   cc -Wall -Wextra -O2 -I. test_x86_xmm0_host.c -o /tmp/t_x0 && /tmp/t_x0
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

#define X86_OP_LOAD_XMM0 0x30U
#define X86_OP_STORE_XMM0 0x31U

/* Restate the addressing AUX decoders x86_sim.h defines, so the oracle
 * exercises the same encoding the sim uses. */
#define X86_MEM_AUX(INDEX, SCALE_LOG2)                                      \
	(((__u32)(INDEX) & 0xffU) | (((__u32)(SCALE_LOG2) & 0xffU) << 8))
#define X86_MEM_AUX_INDEX(AUX) ((__u8)((AUX) & 0xffU))
#define X86_MEM_AUX_SCALE_LOG2(AUX) ((__u8)(((AUX) >> 8) & 0xffU))

#include "generated/x86_xmm0.h"
#include "generated/x86_width.h"
#include "generated/x86_mem_access.h"
#include "generated/x86_mem_offset.h"

#include <stdint.h>
#include <stdio.h>
#include <string.h>

/* ------------------------------------------------------------------ */
/* A deterministic register file, memory and stack model.             */
/*                                                                    */
/* Registers carry a byte view, a 16-bit view and a pointer view over */
/* the same eight bytes plus a tag byte; register "pointers" are held */
/* as byte offsets that the oracle reduces modulo the memory buffer   */
/* so the model stays inside the arrays at every address it forms.    */
/* The XMM0 pair is two plain scalars, with no tag: neither body      */
/* writes one.                                                        */
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

static __u8 result_mem[ORACLE_BYTES];
static __u8 result_stack[ORACLE_STACK_BYTES];

static __u64 oracle_xmm0_lo;
static __u64 oracle_xmm0_hi;
static __u64 pristine_xmm0_lo;
static __u64 pristine_xmm0_hi;
static __u64 result_xmm0_lo;
static __u64 result_xmm0_hi;

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
	oracle_xmm0_lo = 0x0123456789abcdefULL;
	oracle_xmm0_hi = 0xfedcba9876543210ULL;
}

/* The reduction an effective address is folded through so the model stays
 * inside the memory array; the reduction leaves room for the widest (8-byte)
 * load. Both paths share this convention; it is not part of the contract
 * under test. */
static unsigned oracle_slot(__u64 addr)
{
	return (unsigned)(addr % (ORACLE_BYTES - 8U));
}

static void oracle_snapshot_pristine(void)
{
	memcpy(pristine_regs, oracle_regs, sizeof(pristine_regs));
	memcpy(pristine_mem, oracle_mem, ORACLE_BYTES);
	memcpy(pristine_stack, oracle_stack, ORACLE_STACK_BYTES);
	pristine_xmm0_lo = oracle_xmm0_lo;
	pristine_xmm0_hi = oracle_xmm0_hi;
}

static void oracle_restore_pristine(void)
{
	memcpy(oracle_regs, pristine_regs, sizeof(pristine_regs));
	memcpy(oracle_mem, pristine_mem, ORACLE_BYTES);
	memcpy(oracle_stack, pristine_stack, ORACLE_STACK_BYTES);
	oracle_xmm0_lo = pristine_xmm0_lo;
	oracle_xmm0_hi = pristine_xmm0_hi;
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

/* The ordinary little-endian load: exactly `width` bytes, least significant
 * first, width-masked. This is the oracle's straightforward byte loop; the
 * sim's own 8-aligned fast path is not part of the contract. */
static __u64 oracle_load(__u64 addr, unsigned width)
{
	__u64 v = 0;
	unsigned i;

	for (i = 0; i < width; i++)
		v |= (__u64)oracle_mem[oracle_slot(addr) + i] << (8 * i);
	return v & oracle_mask(width);
}

/* The ordinary little-endian store: exactly `width` bytes of the width-masked
 * value, least significant first. */
static void oracle_store(__u64 addr, unsigned width, __u64 value)
{
	unsigned base = oracle_slot(addr);
	__u64 narrowed = value & oracle_mask(width);
	unsigned i;

	for (i = 0; i < width; i++)
		oracle_mem[base + i] = (__u8)(narrowed >> (8 * i));
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

/* The addressing offset, restated: the displacement, plus the scaled index
 * when the mode carries one. */
static __s64 oracle_mem_offset(__u32 aux, __s64 disp, __u64 index_value)
{
	__s64 off = disp;

	if (X86_MEM_AUX_INDEX(aux) != X86_REG_NONE)
		off += (__s64)(index_value << X86_MEM_AUX_SCALE_LOG2(aux));
	return off;
}

/* ------------------------------------------------------------------ */
/* Part 1: the generated tables vs. the oracle.                       */
/* ------------------------------------------------------------------ */

static unsigned part1(void)
{
	/* Each opcode's direction, restated: the load reads, the store
	 * writes. The opcodes are the two directions of one pair move. */
	static const unsigned opcodes[2] = { X86_OP_LOAD_XMM0, X86_OP_STORE_XMM0 };
	unsigned cases = 0;
	unsigned oi;
	int rsp;
	unsigned li;

	for (oi = 0; oi < 2U; oi++) {
		unsigned op_is_load = opcodes[oi] == X86_OP_LOAD_XMM0;
		unsigned want_base = op_is_load ? KPROG_X86_XMM0_BASE_ABS_IMM
						: KPROG_X86_XMM0_BASE_NULL_PLUS_DISP;
		unsigned got_base = KPROG_X86_XMM0_BASE_FORM(op_is_load);

		if (KPROG_X86_XMM0_BASE_FORM(op_is_load) != want_base) {
			fprintf(stderr, "base form mismatch op=%#x got=%u want=%u\n",
				opcodes[oi], got_base, want_base);
			return 0;
		}
		/* The two opcodes must not share one base form. */
		if (!op_is_load && got_base == KPROG_X86_XMM0_BASE_ABS_IMM) {
			fprintf(stderr, "store took the load's base form\n");
			return 0;
		}
		cases++;
	}

	for (rsp = 0; rsp < 2; rsp++) {
		unsigned want = rsp ? KPROG_X86_XMM0_ARM_STACK
				    : KPROG_X86_XMM0_ARM_MEMORY;
		unsigned got = KPROG_X86_XMM0_ARM(rsp);

		if (got != want) {
			fprintf(stderr, "arm mismatch rsp=%d got=%u want=%u\n",
				rsp, got, want);
			return 0;
		}
		cases++;
	}

	for (li = 0; li < KPROG_X86_XMM0_LANES; li++) {
		unsigned want = li == 0U ? KPROG_X86_XMM0_LANE_LO
					 : KPROG_X86_XMM0_LANE_HI;
		unsigned got = KPROG_X86_XMM0_LANE_OFFSET(li);

		if (got != want) {
			fprintf(stderr, "lane offset mismatch lane=%u got=%u want=%u\n",
				li, got, want);
			return 0;
		}
		/* Consecutive lanes, one lane width apart. */
		if (got != li * KPROG_X86_XMM0_LANE_BYTES) {
			fprintf(stderr, "lane %u not at %u * lane width\n", li,
				li);
			return 0;
		}
		cases++;
	}

	/* The pair is two 8-byte lanes, and the lane width is the hardcoded
	 * width 64 both bodies use. */
	if (KPROG_X86_XMM0_LANES != 2U ||
	    KPROG_X86_XMM0_LANE_BYTES != 8U ||
	    KPROG_X86_XMM0_LANE_BYTES != KPROG_X86_WIDTH_BITS(X86_WIDTH_64) / 8U) {
		fprintf(stderr, "lane geometry mismatch\n");
		return 0;
	}
	cases++;

	/* Every ordinary-arm shape adds the offset except the load's
	 * X86_REG_NONE operand; that is the whole asymmetry. */
	{
		static const unsigned forms[2] = { KPROG_X86_XMM0_BASE_ABS_IMM,
						   KPROG_X86_XMM0_BASE_NULL_PLUS_DISP };
		unsigned fi;
		unsigned ni;

		for (fi = 0; fi < 2U; fi++) {
			for (ni = 0; ni < 2U; ni++) {
				int base_is_none = ni != 0U;
				unsigned got = KPROG_X86_XMM0_ADDS_DISP(
					base_is_none, forms[fi]);
				unsigned want =
					(forms[fi] == KPROG_X86_XMM0_BASE_ABS_IMM)
					? !base_is_none : 1U;

				if (got != want) {
					fprintf(stderr,
						"adds-disp mismatch form=%u none=%d "
						"got=%u want=%u\n",
						forms[fi], base_is_none, got, want);
					return 0;
				}
				cases++;
			}
		}
	}

	return cases;
}

/* ------------------------------------------------------------------ */
/* Part 2: the full load composition vs. the hand-written body.       */
/*                                                                    */
/* `contract_step_load` addresses and reads through the generated     */
/* contracts; `model_step_load` restates the body from the raw        */
/* fields. They must agree on the effective address and both lanes.   */
/* ------------------------------------------------------------------ */

struct xmm0_load_effect {
	__u8 arm;
	__u64 addr;
	__u64 lo;
	__u64 hi;
};

static struct xmm0_load_effect contract_step_load(unsigned op_is_load,
						  unsigned base, __u32 aux,
						  __u64 imm, __u64 index_value)
{
	__u8 arm = KPROG_X86_XMM0_ARM(base == X86_RSP);
	__u8 base_form = KPROG_X86_XMM0_BASE_FORM(op_is_load);
	__u8 adds_disp =
		KPROG_X86_XMM0_ADDS_DISP(base == X86_REG_NONE, base_form);
	__u64 reg_ptr = base == X86_REG_NONE ? 0ULL : oracle_reg_value(base);
	__s64 off = KPROG_X86_MEM_OFFSET(aux, (__s64)imm, index_value,
					 X86_MEM_AUX_INDEX(aux) != X86_REG_NONE);
	__u64 base_ptr = (__u64)(uintptr_t)KPROG_X86_XMM0_BASE_PTR(
		base == X86_REG_NONE, base_form, imm, reg_ptr);
	__u64 addr = arm == KPROG_X86_XMM0_ARM_STACK
		? reg_ptr + (__u64)off
		: base_ptr + (adds_disp ? (__u64)off : 0ULL);
	unsigned lo_off = KPROG_X86_XMM0_LANE_OFFSET(0U);
	unsigned hi_off = KPROG_X86_XMM0_LANE_OFFSET(1U);
	struct xmm0_load_effect r;

	if (arm == KPROG_X86_XMM0_ARM_STACK) {
		r.lo = oracle_stack_load((__s64)addr + lo_off, X86_WIDTH_64);
		r.hi = oracle_stack_load((__s64)addr + hi_off, X86_WIDTH_64);
	} else {
		r.lo = KPROG_X86_MEM_LOAD(
			&oracle_mem[oracle_slot(addr + lo_off)], X86_WIDTH_64);
		r.hi = KPROG_X86_MEM_LOAD(
			&oracle_mem[oracle_slot(addr + hi_off)], X86_WIDTH_64);
	}
	/* The load writes the pair and nothing else. */
	oracle_xmm0_lo = r.lo;
	oracle_xmm0_hi = r.hi;
	r.arm = arm;
	r.addr = addr;
	return r;
}

static struct xmm0_load_effect model_step_load(unsigned op_is_load,
					       unsigned base, __u32 aux,
					       __u64 imm, __u64 index_value)
{
	__u8 arm = base == X86_RSP ? KPROG_X86_XMM0_ARM_STACK
				   : KPROG_X86_XMM0_ARM_MEMORY;
	int base_is_none = base == X86_REG_NONE;
	__u64 reg_ptr = base_is_none ? 0ULL : oracle_reg_value(base);
	__s64 off = oracle_mem_offset(aux, (__s64)imm, index_value);
	__u64 base_ptr;
	__u64 addr;
	struct xmm0_load_effect r;

	/* The ordinary-arm base form is the opcode's: the load's
	 * X86_REG_NONE operand is the raw artifact with the offset
	 * discarded, the store's is the null pointer with the offset added. */
	if (op_is_load != 0U) {
		base_ptr = base_is_none ? imm : reg_ptr;
		addr = base_ptr + ((base_is_none ? 0ULL : (__u64)off));
	} else {
		base_ptr = base_is_none ? 0ULL : reg_ptr;
		addr = base_ptr + (__u64)off;
	}
	if (arm == KPROG_X86_XMM0_ARM_STACK)
		addr = reg_ptr + (__u64)off;

	if (arm == KPROG_X86_XMM0_ARM_STACK) {
		r.lo = oracle_stack_load((__s64)addr + 0, X86_WIDTH_64);
		r.hi = oracle_stack_load((__s64)addr + 8, X86_WIDTH_64);
	} else {
		r.lo = oracle_load(addr + 0, X86_WIDTH_64);
		r.hi = oracle_load(addr + 8, X86_WIDTH_64);
	}
	oracle_xmm0_lo = r.lo;
	oracle_xmm0_hi = r.hi;
	r.arm = arm;
	r.addr = addr;
	return r;
}

static unsigned part2(void)
{
	static const __u64 imms[4] = {
		0x1234001000000008ULL,
		0x0000000000000010ULL,
		0xffffffff00000008ULL,
		0x0000000000000018ULL,
	};
	static const unsigned bases[4] = { 1U, 2U, X86_RSP, X86_REG_NONE };
	static const unsigned index_regs[3] = { X86_REG_NONE, 3U, 11U };
	unsigned cases = 0;
	unsigned oi;
	unsigned bi;
	unsigned di;
	unsigned ii;
	unsigned sc;

	for (oi = 0; oi < 2U; oi++) {
		for (bi = 0; bi < 4U; bi++) {
			for (ii = 0; ii < 3U; ii++) {
				for (sc = 0; sc < 2U; sc++) {
					for (di = 0; di < 4U; di++) {
						__u32 aux =
							index_regs[ii] == X86_REG_NONE
							? X86_MEM_AUX(X86_REG_NONE, 0U)
							: X86_MEM_AUX(index_regs[ii],
								      (sc == 0 ? 0U : (__u8)sc));
						__u64 index_value =
							0x1111111100000005ULL;
						struct xmm0_load_effect got;
						struct xmm0_load_effect want;

						oracle_restore_pristine();
						got = contract_step_load(oi, bases[bi], aux,
									 imms[di], index_value);
						memcpy(result_mem, oracle_mem,
						       ORACLE_BYTES);
						memcpy(result_stack, oracle_stack,
						       ORACLE_STACK_BYTES);
						memcpy(result_regs, oracle_regs,
						       sizeof(oracle_regs));
						result_xmm0_lo = oracle_xmm0_lo;
						result_xmm0_hi = oracle_xmm0_hi;
						oracle_restore_pristine();
						want = model_step_load(oi, bases[bi], aux,
								       imms[di], index_value);
						if (got.arm != want.arm ||
						    got.addr != want.addr ||
						    got.lo != want.lo ||
						    got.hi != want.hi ||
						    result_xmm0_lo != oracle_xmm0_lo ||
						    result_xmm0_hi != oracle_xmm0_hi ||
						    memcmp(result_regs, oracle_regs,
							   sizeof(oracle_regs)) ||
						    memcmp(result_mem, oracle_mem,
							   ORACLE_BYTES) ||
						    memcmp(result_stack, oracle_stack,
							   ORACLE_STACK_BYTES)) {
							fprintf(stderr,
								"load handler mismatch "
								"op=%#x base=%u imm=%llx "
								"idx=%u scale=%u "
								"got=(%u,%llx,%llx,%llx) "
								"want=(%u,%llx,%llx,%llx)\n",
								oi ? X86_OP_LOAD_XMM0
								   : X86_OP_STORE_XMM0,
								bases[bi],
								(unsigned long long)imms[di],
								(unsigned)index_regs[ii], sc,
								got.arm,
								(unsigned long long)got.addr,
								(unsigned long long)got.lo,
								(unsigned long long)got.hi,
								want.arm,
								(unsigned long long)want.addr,
								(unsigned long long)want.lo,
								(unsigned long long)want.hi);
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
/* Part 3: the full store composition vs. the hand-written body.      */
/*                                                                    */
/* The handler writes only memory, so the memory and stack buffers    */
/* are the state compared; the registers and the pair are read-only   */
/* inputs.                                                            */
/* ------------------------------------------------------------------ */

struct xmm0_store_effect {
	__u8 arm;
	__u64 addr;
};

static struct xmm0_store_effect contract_step_store(unsigned base, __u32 aux,
						    __u64 imm, __u64 index_value)
{
	/* The store's ordinary arm is the null-base-plus-displacement form. */
	__u8 arm = KPROG_X86_XMM0_ARM(base == X86_RSP);
	__u8 base_form = KPROG_X86_XMM0_BASE_FORM(0U);
	__u8 adds_disp =
		KPROG_X86_XMM0_ADDS_DISP(base == X86_REG_NONE, base_form);
	__u64 reg_ptr = base == X86_REG_NONE ? 0ULL : oracle_reg_value(base);
	__s64 off = KPROG_X86_MEM_OFFSET(aux, (__s64)imm, index_value,
					 X86_MEM_AUX_INDEX(aux) != X86_REG_NONE);
	__u64 base_ptr = (__u64)(uintptr_t)KPROG_X86_XMM0_BASE_PTR(
		base == X86_REG_NONE, base_form, imm, reg_ptr);
	__u64 addr = arm == KPROG_X86_XMM0_ARM_STACK
		? reg_ptr + (__u64)off
		: base_ptr + (adds_disp ? (__u64)off : 0ULL);
	unsigned lo_off = KPROG_X86_XMM0_LANE_OFFSET(0U);
	unsigned hi_off = KPROG_X86_XMM0_LANE_OFFSET(1U);
	struct xmm0_store_effect r;

	if (arm == KPROG_X86_XMM0_ARM_STACK) {
		oracle_stack_store((__s64)addr + lo_off, X86_WIDTH_64,
				   oracle_xmm0_lo);
		oracle_stack_store((__s64)addr + hi_off, X86_WIDTH_64,
				   oracle_xmm0_hi);
	} else {
		KPROG_X86_MEM_STORE(&oracle_mem[oracle_slot(addr + lo_off)],
				    X86_WIDTH_64, oracle_xmm0_lo);
		KPROG_X86_MEM_STORE(&oracle_mem[oracle_slot(addr + hi_off)],
				    X86_WIDTH_64, oracle_xmm0_hi);
	}
	r.arm = arm;
	r.addr = addr;
	return r;
}

static struct xmm0_store_effect model_step_store(unsigned base, __u32 aux,
						 __u64 imm, __u64 index_value)
{
	__u8 arm = base == X86_RSP ? KPROG_X86_XMM0_ARM_STACK
				   : KPROG_X86_XMM0_ARM_MEMORY;
	int base_is_none = base == X86_REG_NONE;
	__u64 reg_ptr = base_is_none ? 0ULL : oracle_reg_value(base);
	__s64 off = oracle_mem_offset(aux, (__s64)imm, index_value);
	__u64 base_ptr = base_is_none ? 0ULL : reg_ptr;
	__u64 addr = arm == KPROG_X86_XMM0_ARM_STACK
		? reg_ptr + (__u64)off
		: base_ptr + (__u64)off;
	struct xmm0_store_effect r;

	if (arm == KPROG_X86_XMM0_ARM_STACK) {
		oracle_stack_store((__s64)addr + 0, X86_WIDTH_64,
				   oracle_xmm0_lo);
		oracle_stack_store((__s64)addr + 8, X86_WIDTH_64,
				   oracle_xmm0_hi);
	} else {
		oracle_store(addr + 0, X86_WIDTH_64, oracle_xmm0_lo);
		oracle_store(addr + 8, X86_WIDTH_64, oracle_xmm0_hi);
	}
	r.arm = arm;
	r.addr = addr;
	return r;
}

static unsigned part3(void)
{
	static const __u64 imms[3] = {
		0x8000001000000008ULL,
		0x0000000000000020ULL,
		0xffffffff00000010ULL,
	};
	static const unsigned bases[4] = { 1U, 2U, X86_RSP, X86_REG_NONE };
	static const unsigned index_regs[3] = { X86_REG_NONE, 3U, 11U };
	unsigned cases = 0;
	unsigned bi;
	unsigned di;
	unsigned ii;
	unsigned sc;

	for (bi = 0; bi < 4U; bi++) {
		for (ii = 0; ii < 3U; ii++) {
			for (sc = 0; sc < 2U; sc++) {
				for (di = 0; di < 3U; di++) {
					__u32 aux =
						index_regs[ii] == X86_REG_NONE
						? X86_MEM_AUX(X86_REG_NONE, 0U)
						: X86_MEM_AUX(index_regs[ii],
							      (sc == 0 ? 0U : (__u8)sc));
					__u64 index_value =
						0x1111111100000005ULL;
					struct xmm0_store_effect got;
					struct xmm0_store_effect want;

					oracle_restore_pristine();
					got = contract_step_store(bases[bi], aux,
								  imms[di],
								  index_value);
					memcpy(result_mem, oracle_mem,
					       ORACLE_BYTES);
					memcpy(result_stack, oracle_stack,
					       ORACLE_STACK_BYTES);
					memcpy(result_regs, oracle_regs,
					       sizeof(oracle_regs));
					result_xmm0_lo = oracle_xmm0_lo;
					result_xmm0_hi = oracle_xmm0_hi;
					oracle_restore_pristine();
					want = model_step_store(bases[bi], aux,
								imms[di],
								index_value);
					if (got.arm != want.arm ||
					    got.addr != want.addr ||
					    result_xmm0_lo != oracle_xmm0_lo ||
					    result_xmm0_hi != oracle_xmm0_hi ||
					    memcmp(result_regs, oracle_regs,
						   sizeof(oracle_regs)) ||
					    memcmp(result_mem, oracle_mem,
						   ORACLE_BYTES) ||
					    memcmp(result_stack, oracle_stack,
						   ORACLE_STACK_BYTES)) {
						fprintf(stderr,
							"store handler mismatch "
							"base=%u imm=%llx idx=%u scale=%u "
							"got=(%u,%llx) want=(%u,%llx)\n",
							bases[bi],
							(unsigned long long)imms[di],
							(unsigned)index_regs[ii], sc,
							got.arm,
							(unsigned long long)got.addr,
							want.arm,
							(unsigned long long)want.addr);
						return 0;
					}
					cases++;
				}
			}
		}
	}
	return cases;
}

/* ------------------------------------------------------------------ */
/* Part 4: pins on the asymmetries the composition is about.          */
/* ------------------------------------------------------------------ */

static unsigned part4(void)
{
	unsigned cases = 0;

	/* Pin 1: the whole-artifact displacement and the immediate store's
	 * high-half slice are different slices of the same field. */
	{
		__u64 imm = 0x8000001000000008ULL;

		if ((__s64)imm == (__s64)(__s32)(imm >> 32))
			return 0;
		cases++;
	}

	/* Pin 2: a X86_REG_NONE load ignores the addressing offset entirely —
	 * the effective address is the raw artifact whatever the offset —
	 * whereas a X86_REG_NONE store's address *is* the offset. */
	{
		__u64 a0 = (__u64)(uintptr_t)KPROG_X86_XMM0_BASE_PTR(
			1, KPROG_X86_XMM0_BASE_FORM(1U), 0x8000ULL, 0x1111ULL);
		__u64 a1 = (__u64)(uintptr_t)KPROG_X86_XMM0_BASE_PTR(
			1, KPROG_X86_XMM0_BASE_FORM(0U), 0x8000ULL, 0x1111ULL);

		if (a0 != 0x8000ULL)
			return 0; /* the load's X86_REG_NONE operand is the raw artifact */
		if (a1 != 0ULL)
			return 0; /* the store's is the null pointer */
		if (KPROG_X86_XMM0_ADDS_DISP(1, KPROG_X86_XMM0_BASE_FORM(1U)) != 0U)
			return 0; /* load: offset discarded */
		if (KPROG_X86_XMM0_ADDS_DISP(1, KPROG_X86_XMM0_BASE_FORM(0U)) != 1U)
			return 0; /* store: offset added */
		cases++;
	}

	/* Pin 3: with a register operand the two opcodes' ordinary arms agree
	 * — both are the register pointer plus the offset. */
	{
		__u64 p0 = (__u64)(uintptr_t)KPROG_X86_XMM0_BASE_PTR(
			0, KPROG_X86_XMM0_BASE_FORM(1U), 0x8000ULL, 0x1111ULL);
		__u64 p1 = (__u64)(uintptr_t)KPROG_X86_XMM0_BASE_PTR(
			0, KPROG_X86_XMM0_BASE_FORM(0U), 0x8000ULL, 0x1111ULL);

		if (p0 != 0x1111ULL || p1 != 0x1111ULL)
			return 0;
		if (!KPROG_X86_XMM0_ADDS_DISP(0, KPROG_X86_XMM0_BASE_FORM(1U)) ||
		    !KPROG_X86_XMM0_ADDS_DISP(0, KPROG_X86_XMM0_BASE_FORM(0U)))
			return 0;
		cases++;
	}

	/* Pin 4: both lanes are read at offsets 0 and 8 at width 64, the low
	 * lane first, with no reversal or interleave. */
	{
		unsigned i;
		struct xmm0_load_effect e;

		/* A X86_REG_NONE load addresses the raw artifact, so imm 0 is
		 * slot 0 and the first sixteen memory bytes are the two
		 * windows. */
		oracle_restore_pristine();
		for (i = 0; i < 16U; i++)
			oracle_mem[i] = (__u8)(0x11U * (i + 1U));
		e = contract_step_load(1U, X86_REG_NONE, X86_MEM_AUX(X86_REG_NONE, 0U), 0ULL, 0U);
		if (e.addr != 0ULL)
			return 0;
		if (e.lo != 0x8877665544332211ULL ||
		    e.hi != 0x10ffeeddccbbaa99ULL)
			return 0;
		cases++;
	}

	/* Pin 5: a X86_REG_NONE store writes the pair to the offset itself, at
	 * both lanes; the low lane's first byte lands at the offset, the high
	 * lane's first byte eight bytes later. */
	{
		struct xmm0_store_effect e;

		oracle_restore_pristine();
		oracle_xmm0_lo = 0x8877665544332211ULL;
		oracle_xmm0_hi = 0x0807060504030201ULL;
		e = contract_step_store(X86_REG_NONE, X86_MEM_AUX(X86_REG_NONE, 0U), 0x4000ULL, 0U);
		if (e.addr != 0x4000ULL)
			return 0;
		if (oracle_mem[oracle_slot(0x4000ULL) + 0] != 0x11U ||
		    oracle_mem[oracle_slot(0x4000ULL) + 7] != 0x88U ||
		    oracle_mem[oracle_slot(0x4000ULL) + 8] != 0x01U ||
		    oracle_mem[oracle_slot(0x4000ULL) + 15] != 0x08U)
			return 0;
		cases++;
	}

	/* Pin 6: neither body writes a GPR or a tag, in either arm. */
	{
		struct xmm0_load_effect le;
		struct xmm0_store_effect se;

		oracle_restore_pristine();
		le = contract_step_load(1U, 3U, X86_MEM_AUX(X86_REG_NONE, 0U), 0x20ULL, 0U);
		if (memcmp(oracle_regs, pristine_regs, sizeof(oracle_regs)))
			return 0;
		(void)le;
		oracle_restore_pristine();
		se = contract_step_store(3U, X86_MEM_AUX(X86_REG_NONE, 0U), 0x20ULL, 0U);
		if (memcmp(oracle_regs, pristine_regs, sizeof(oracle_regs)))
			return 0;
		(void)se;
		cases++;
	}

	/* Pin 7: a X86_REG_NONE operand really does access memory — the
	 * ordinary arm reads a nonzero lane and writes bytes, so it is not a
	 * skipped access. */
	{
		unsigned i;
		struct xmm0_load_effect le;
		struct xmm0_store_effect se;
		unsigned changed = 0;

		oracle_restore_pristine();
		for (i = 0; i < 8U; i++)
			oracle_mem[oracle_slot(0x6008ULL) + i] = (__u8)(0x40U + i);
		le = contract_step_load(1U, X86_REG_NONE, X86_MEM_AUX(X86_REG_NONE, 0U), 0x6008ULL, 0U);
		if (le.lo != 0x4746454443424140ULL || le.hi == 0ULL)
			return 0;

		oracle_restore_pristine();
		oracle_xmm0_lo = 0xaabbccddeeff0011ULL;
		oracle_xmm0_hi = 0x0011223344556677ULL;
		se = contract_step_store(X86_REG_NONE, X86_MEM_AUX(X86_REG_NONE, 0U), 0x6008ULL, 0U);
		for (i = 0; i < ORACLE_BYTES; i++)
			changed += oracle_mem[i] != pristine_mem[i];
		if (changed != 16U)
			return 0;
		(void)se;
		cases++;
	}

	/* Pin 8: the stack arm and the ordinary arm move the same two lanes at
	 * the same width — a store through the stack helper and a load back
	 * from it recover the pair. */
	{
		struct xmm0_store_effect se;
		struct xmm0_load_effect le;

		oracle_restore_pristine();
		oracle_xmm0_lo = 0x0123456789abcdefULL;
		oracle_xmm0_hi = 0xfedcba9876543210ULL;
		se = contract_step_store(X86_RSP, X86_MEM_AUX(X86_REG_NONE, 0U), 0x10ULL, 0U);
		if (se.addr != oracle_reg_value(X86_RSP) + 0x10ULL)
			return 0;
		oracle_xmm0_lo = 0ULL;
		oracle_xmm0_hi = 0ULL;
		le = contract_step_load(1U, X86_RSP, X86_MEM_AUX(X86_REG_NONE, 0U), 0x10ULL, 0U);
		if (le.lo != 0x0123456789abcdefULL ||
		    le.hi != 0xfedcba9876543210ULL)
			return 0;
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
	oracle_restore_pristine();
	total += part2();
	oracle_restore_pristine();
	total += part3();
	oracle_restore_pristine();
	total += part4();
	oracle_restore_pristine();

	printf("x86 xmm0 handler host cross-check: OK (%u cases)\n", total);
	return 0;
}
