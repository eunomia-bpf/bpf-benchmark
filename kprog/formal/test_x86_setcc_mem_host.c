/*
 * Host cross-check for the x86-64 `SETCC_MEM` handler (`X86_OP_SETCC_MEM`,
 * `0x3e`), the body `X86_SIM_L_EXEC_SETCC_MEM`.
 *
 * Part 1 sweeps the whole 256-value raw condition byte space: the generated
 * KPROG_X86_SETCC_MEM_CONDITION decoder must recover the byte it encoded, and
 * the real KPROG_X86_EVAL_CC expression driven by that byte must agree with an
 * independent restatement of the 14-arm condition table for all 16 raw flag
 * combinations, with every unsupported code pinned to 0.
 *
 * Part 2 verifies the generated base table KPROG_X86_SETCC_MEM_BASE against an
 * independent restatement of the `X86_REG_NONE` test, over all 256 register
 * numbers.
 *
 * Part 3 verifies the generated arm table KPROG_X86_SETCC_MEM_ARM against an
 * independent restatement of the `X86_RSP` test, over both truth values.
 *
 * Part 4 drives the whole handler over a deterministic register, memory, and
 * stack model: it decodes the condition byte through the generated decoder,
 * selects the base and the arm through the generated tables, forms the
 * effective address through the generated offset contract, and writes through
 * the generated little-endian store contract or the stack helper's
 * restatement, while a real KPROG_X86_EVAL_CC resolution supplies the one-byte
 * value. Every resulting byte of both the memory and the stack model, plus the
 * arm, width, value and address, must match a hand-written model of the C body.
 * A nonzero AUX memory-width byte is carried through the sweep so the handler's
 * constant width is exercised against the field that would move a store's.
 *
 * The point of this oracle is what this handler does NOT share with the
 * register form `X86_OP_SETCC`: the condition comes from the AUX *source-shift*
 * byte at bits 24..31, not the payload byte at bits 0..7; the write width is
 * the opcode's constant 8-bit code, so neither FLAGS nor the AUX memory-width
 * byte can widen it; and the destination register number is also the memory
 * base, with `X86_REG_NONE` forming a process-null base rather than a register
 * read, a case the register form has no analogue of.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. test_x86_setcc_mem_host.c -o /tmp/t_scm && /tmp/t_scm
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

#define X86_OP_SETCC_MEM 0x3eU

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

/* Restate the addressing AUX decoders x86_sim.h defines, so the oracle
 * exercises the same encoding the sim uses. */
#define X86_MEM_AUX(INDEX, SCALE_LOG2)                                      \
	(((__u32)(INDEX) & 0xffU) | (((__u32)(SCALE_LOG2) & 0xffU) << 8))
#define X86_MEM_AUX_INDEX(AUX) ((__u8)((AUX) & 0xffU))
#define X86_MEM_AUX_SCALE_LOG2(AUX) ((__u8)(((AUX) >> 8) & 0xffU))
#define X86_MEM_AUX_MEM_WIDTH(AUX) ((__u8)(((AUX) >> 16) & 0xffU))
/* The condition field's own encoder, restated from x86_sim.h. */
#define X86_REG_AUX_SRC_SHIFT(SHIFT) (((__u32)(SHIFT) & 0xffU) << 24)

#include "generated/x86_setcc_mem.h"
#include "generated/x86_cond.h"
#include "generated/x86_mem_offset.h"
#include "generated/x86_mem_access.h"
#include "generated/x86_width.h"

#include <stdint.h>
#include <stdio.h>
#include <string.h>

/* ------------------------------------------------------------------ */
/* A deterministic register file, memory and stack model.             */
/*                                                                    */
/* Register "pointers" are held as byte offsets that the oracle       */
/* reduces modulo the buffer size, so the model stays inside the      */
/* arrays at every address it forms.                                  */
/* ------------------------------------------------------------------ */

#define ORACLE_BYTES 4096
#define ORACLE_STACK_BYTES 64U

static __u8 oracle_mem[ORACLE_BYTES];
static __u8 oracle_stack[ORACLE_STACK_BYTES];

static __u8 pristine_mem[ORACLE_BYTES];
static __u8 pristine_stack[ORACLE_STACK_BYTES];

static __u8 result_mem[ORACLE_BYTES];
static __u8 result_stack[ORACLE_STACK_BYTES];

/* The 16 GPR slots the handler indexes, in X86_SIM_L_FOR_EACH_GPR order:
 * rax rcx rdx rbx rsp rbp rsi rdi r8..r15. */
static __u64 oracle_regs[16];

static __u64 oracle_synthetic(__u64 index)
{
	return (__u8)((index * 131U + 17U) ^ (index >> 5));
}

static void oracle_reset(void)
{
	unsigned i;
	__u64 j;

	for (i = 0; i < 16; i++)
		oracle_regs[i] = 0x200ULL + (__u64)i * 0x20ULL;
	for (j = 0; j < ORACLE_BYTES; j++)
		oracle_mem[j] = (__u8)oracle_synthetic(j);
	for (j = 0; j < ORACLE_STACK_BYTES; j++)
		oracle_stack[j] = (__u8)oracle_synthetic(j + 7U);
}

/* The reduction a stored effective address is folded through so the model
 * stays inside the memory array. Both paths share this convention; it is not
 * part of the contract under test. */
static unsigned oracle_slot(__u64 addr)
{
	return (unsigned)(addr % (ORACLE_BYTES - 8U));
}

static void oracle_snapshot_pristine(void)
{
	memcpy(pristine_mem, oracle_mem, ORACLE_BYTES);
	memcpy(pristine_stack, oracle_stack, ORACLE_STACK_BYTES);
}

static void oracle_restore_pristine(void)
{
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

/* The acceptance table, restated from the raw codes: exactly the 14 `X86_CC_*`
 * codes are supported, everything else in the byte space folds to 0. */
static int oracle_cc_supported(__u8 cc)
{
	return cc == X86_CC_O || cc == X86_CC_NO || cc == X86_CC_B ||
	       cc == X86_CC_AE || cc == X86_CC_E || cc == X86_CC_NE ||
	       cc == X86_CC_BE || cc == X86_CC_A || cc == X86_CC_S ||
	       cc == X86_CC_NS || cc == X86_CC_L || cc == X86_CC_GE ||
	       cc == X86_CC_LE || cc == X86_CC_G;
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

/* The stack helper's store, restated: the frame index is the stack-relative
 * offset biased by the frame size, and the value is width-masked and written
 * little-endian. */
static void oracle_stack_store(__s64 off, unsigned width, __u64 value)
{
	__u32 index = (__u32)(off + ORACLE_STACK_BYTES);
	__u64 narrowed = value & oracle_mask(width ? width : X86_WIDTH_64);
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
/* Part 1: the condition byte decode and the raw condition sweep.      */
/* ------------------------------------------------------------------ */

static unsigned part1(void)
{
	unsigned cases = 0;
	unsigned cc;
	unsigned flags;

	for (cc = 0; cc < 256U; cc++) {
		__u32 aux = X86_REG_AUX_SRC_SHIFT(cc);
		__u8 decoded = KPROG_X86_SETCC_MEM_CONDITION(aux);

		if (decoded != (__u8)cc) {
			fprintf(stderr,
				"condition decode mismatch aux=%x got=%u want=%u\n",
				aux, decoded, cc);
			return 0;
		}
		for (flags = 0; flags < 16U; flags++) {
			int cf = (int)((flags >> 0) & 1U);
			int zf = (int)((flags >> 1) & 1U);
			int sf = (int)((flags >> 2) & 1U);
			int of = (int)((flags >> 3) & 1U);
			__u8 want = oracle_eval_cc((__u8)cc, cf, zf, sf, of);
			__u8 got = (__u8)KPROG_X86_EVAL_CC(decoded, cf, zf,
							   sf, of);

			if (got != want) {
				fprintf(stderr,
					"condition mismatch cc=%u flags=%u "
					"got=%u want=%u\n",
					cc, flags, got, want);
				return 0;
			}
			if (!oracle_cc_supported((__u8)cc) && want != 0U) {
				fprintf(stderr,
					"unsupported cc=%u not pinned to 0\n",
					cc);
				return 0;
			}
			cases++;
		}
	}
	return cases;
}

/* ------------------------------------------------------------------ */
/* Part 2: the generated base table vs. the oracle.                    */
/* ------------------------------------------------------------------ */

static unsigned part2(void)
{
	unsigned cases = 0;
	unsigned dst;

	for (dst = 0; dst < 256U; dst++) {
		__u8 want = ((__u8)dst == X86_REG_NONE)
				    ? KPROG_X86_SETCC_MEM_BASE_NULL
				    : KPROG_X86_SETCC_MEM_BASE_REGISTER;
		__u8 got = KPROG_X86_SETCC_MEM_BASE((__u8)dst);

		if (got != want) {
			fprintf(stderr, "base mismatch dst=%u got=%u want=%u\n",
				dst, got, want);
			return 0;
		}
		cases++;
	}
	return cases;
}

/* ------------------------------------------------------------------ */
/* Part 3: the generated arm table vs. the oracle.                     */
/* ------------------------------------------------------------------ */

static unsigned part3(void)
{
	unsigned cases = 0;
	unsigned maybe_rsp;

	for (maybe_rsp = 0; maybe_rsp < 256U; maybe_rsp++) {
		__u8 want = maybe_rsp ? KPROG_X86_SETCC_MEM_ARM_STACK
				      : KPROG_X86_SETCC_MEM_ARM_MEMORY;
		__u8 got = KPROG_X86_SETCC_MEM_ARM(maybe_rsp);

		if (got != want) {
			fprintf(stderr, "arm mismatch in=%u got=%u want=%u\n",
				maybe_rsp, got, want);
			return 0;
		}
		cases++;
	}
	return cases;
}

/* ------------------------------------------------------------------ */
/* Part 4: the full handler composition vs. the hand-written body.     */
/*                                                                    */
/* `contract_step` decodes, selects, addresses and writes through      */
/* the generated contracts; `model_step` restates the body from the    */
/* raw fields. They must agree byte for byte in both buffers.          */
/* ------------------------------------------------------------------ */

struct setcc_mem_effect {
	__u8 arm;
	__u8 width;
	__u8 value;
	__u64 addr;
};

/* flags is a nibble: bit 0 = cf, bit 1 = zf, bit 2 = sf, bit 3 = of. */
static struct setcc_mem_effect contract_step(int dst_index, __u32 aux,
					     __u8 flags, __u64 imm,
					     __u64 index_value)
{
	__u8 cc = KPROG_X86_SETCC_MEM_CONDITION(aux);
	__u8 base = KPROG_X86_SETCC_MEM_BASE((__u8)dst_index);
	__u8 arm = KPROG_X86_SETCC_MEM_ARM((__u8)dst_index == X86_RSP);
	__u8 width = KPROG_X86_SETCC_MEM_WIDTH_CODE;
	__s64 disp = (__s64)imm;
	/* The generated expression table leaves its arguments unparenthesized,
	 * so each flag is hoisted into its own variable first, the way the
	 * handler's flag registers are. */
	int cf = (int)((flags >> 0) & 1U);
	int zf = (int)((flags >> 1) & 1U);
	int sf = (int)((flags >> 2) & 1U);
	int of = (int)((flags >> 3) & 1U);
	__u64 value = (__u64)(__u8)KPROG_X86_EVAL_CC(cc, cf, zf, sf, of);
	__u64 base_ptr = (base == KPROG_X86_SETCC_MEM_BASE_NULL)
				 ? 0ULL
				 : oracle_regs[dst_index];
	__s64 off;
	struct setcc_mem_effect r;

	off = KPROG_X86_MEM_OFFSET(aux, disp, index_value,
				   X86_MEM_AUX_INDEX(aux) != X86_REG_NONE);

	r.arm = arm;
	r.width = width;
	r.value = value;
	r.addr = base_ptr + (__u64)off;

	if (arm == KPROG_X86_SETCC_MEM_ARM_STACK)
		oracle_stack_store((__s64)base_ptr + off, width, value);
	else
		KPROG_X86_MEM_STORE(&oracle_mem[oracle_slot(r.addr)], width,
				    value);
	return r;
}

static struct setcc_mem_effect model_step(int dst_index, __u32 aux,
					  __u8 flags, __u64 imm,
					  __u64 index_value)
{
	__u8 cc = (__u8)((aux >> 24) & 0xffU);
	__u8 width = X86_WIDTH_8;
	__u64 base_ptr = (dst_index == (int)X86_REG_NONE)
				 ? 0ULL
				 : oracle_regs[dst_index];
	__u64 value;
	__s64 off;
	struct setcc_mem_effect r;

	value = oracle_eval_cc(cc, (flags >> 0) & 1U, (flags >> 1) & 1U,
			       (flags >> 2) & 1U, (flags >> 3) & 1U);
	off = oracle_mem_offset(aux, (__s64)imm, index_value);

	if (dst_index == (int)X86_RSP)
		r.arm = KPROG_X86_SETCC_MEM_ARM_STACK;
	else
		r.arm = KPROG_X86_SETCC_MEM_ARM_MEMORY;
	r.width = width;
	r.value = value;
	r.addr = base_ptr + (__u64)off;

	if (r.arm == KPROG_X86_SETCC_MEM_ARM_STACK)
		oracle_stack_store((__s64)base_ptr + off, width, value);
	else
		oracle_store(r.addr, width, value);
	return r;
}

static unsigned part4(void)
{
	static const __u32 mem_widths[2] = { 0U, X86_WIDTH_8 };
	static const __u64 imms[4] = {
		0x0000000012340008ULL,
		0x0000000000000010ULL,
		0x1234001000000008ULL,
		0xffffffff00000008ULL,
	};
	unsigned cases = 0;
	unsigned dst;
	unsigned cc;
	unsigned flags;
	unsigned mi;
	unsigned di;
	int indexed;


	for (dst = 0; dst < 16U; dst++) {
		for (cc = 0; cc < 256U; cc++) {
			for (flags = 0; flags < 16U; flags++) {
				for (indexed = 0; indexed < 2; indexed++) {
					for (mi = 0; mi < 2U; mi++) {
						for (di = 0; di < 4U; di++) {
							__u32 aux =
								X86_REG_AUX_SRC_SHIFT(cc) |
								(mem_widths[mi] << 16) |
								(indexed ? X86_MEM_AUX(3U, 1U)
									 : X86_MEM_AUX(X86_REG_NONE, 0U));
							__u64 index_value =
								0x1111111100000005ULL;
							struct setcc_mem_effect got;
							struct setcc_mem_effect want;

							oracle_restore_pristine();
							got = contract_step(
								(int)dst, aux,
								(__u8)flags,
								imms[di],
								index_value);
							memcpy(result_mem,
							       oracle_mem,
							       ORACLE_BYTES);
							memcpy(result_stack,
							       oracle_stack,
							       ORACLE_STACK_BYTES);
							oracle_restore_pristine();
							want = model_step(
								(int)dst, aux,
								(__u8)flags,
								imms[di],
								index_value);
							if (got.arm != want.arm ||
							    got.width != want.width ||
							    got.value != want.value ||
							    got.addr != want.addr ||
							    memcmp(result_mem,
								   oracle_mem,
								   ORACLE_BYTES) ||
							    memcmp(result_stack,
								   oracle_stack,
								   ORACLE_STACK_BYTES)) {
								fprintf(stderr,
									"handler mismatch "
									"dst=%u cc=%u flags=%u "
									"indexed=%d memw=%u imm=%llx "
									"got=(%u,%u,%u,%llx) "
									"want=(%u,%u,%u,%llx)\n",
									dst, cc, flags,
									indexed,
									mem_widths[mi],
									(unsigned long long)imms[di],
									got.arm, got.width,
									got.value,
									(unsigned long long)got.addr,
									want.arm, want.width,
									want.value,
									(unsigned long long)want.addr);
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
/* Part 5: pins on the asymmetries the composition is about.           */
/* ------------------------------------------------------------------ */

static unsigned part5(void)
{
	unsigned cases = 0;
	__u64 base_ptr = oracle_regs[1];
	struct setcc_mem_effect a, b;

	/* Pin 1: the condition byte is the source-shift byte at bits 24..31,
	 * not the payload byte the register form reads. `0x05` decoded from
	 * the high byte is `ne`; the low byte `0x04` is `e`. */
	a = contract_step(1, 0x05000004U, 0x02U, 0, 0U);
	if (a.value != (__u8)!(__u8)1)
		return 0;
	{
		__u8 low_byte_value =
			(__u8)KPROG_X86_EVAL_CC(0x04U, 0, 1, 0, 0);

		if (low_byte_value == a.value)
			return 0;
	}
	cases++;

	/* Pin 2: the displacement is the whole artifact, not a half of it.
	 * The immediate store's high-half slice of the same artifact would be
	 * a different address. */
	a = contract_step(1, 0U, 0x02U, 0x1234001000000008ULL, 0U);
	if (a.addr != base_ptr + 0x1234001000000008ULL)
		return 0;
	if (a.addr == base_ptr + 0x12340010ULL)
		return 0;
	cases++;

	/* Pin 3: a null-base destination takes the ordinary memory arm, writes
	 * through process null plus the offset, and is not the stack pointer's
	 * register number. */
	oracle_restore_pristine();
	a = contract_step((int)X86_REG_NONE, 0U, 0x01U, 0x0000000000000030ULL,
			  0U);
	if (a.arm != KPROG_X86_SETCC_MEM_ARM_MEMORY)
		return 0;
	if (a.addr != 0x30ULL)
		return 0;
	if (oracle_mem[oracle_slot(0x30ULL)] != 0U)
		return 0;
	if (memcmp(oracle_stack, pristine_stack, ORACLE_STACK_BYTES) != 0)
		return 0;
	cases++;

	/* Pin 4: a stack-pointer destination writes the stack frame only, at
	 * the handler's own base pointer plus the offset, and leaves process
	 * memory untouched. */
	oracle_restore_pristine();
	a = contract_step(X86_RSP, 0x05000000U, 0x01U, 0x0000000000000008ULL,
			  0U);
	if (a.arm != KPROG_X86_SETCC_MEM_ARM_STACK)
		return 0;
	if (a.addr != oracle_regs[X86_RSP] + 0x8ULL)
		return 0;
	if (memcmp(oracle_mem, pristine_mem, ORACLE_BYTES) != 0)
		return 0;
	if (oracle_stack[(unsigned)(a.addr) % ORACLE_STACK_BYTES] != a.value)
		return 0;
	cases++;

	/* Pin 5: the width is the opcode's constant 8-bit code, so a nonzero
	 * AUX memory-width byte (`0x08` in bits 16..23) and a FLAGS code that
	 * would otherwise force 64 bits both leave the write one byte wide. */
	oracle_restore_pristine();
	a = contract_step(1, (0x08U << 16), (__u8)X86_WIDTH_64,
			  0x0000000011223308ULL, 0U);
	if (a.width != X86_WIDTH_8)
		return 0;
	if (oracle_mem[oracle_slot(a.addr)] != (__u8)a.value)
		return 0;
	if (oracle_mem[oracle_slot(a.addr) + 1] !=
	    pristine_mem[oracle_slot(a.addr) + 1])
		return 0;
	cases++;

	/* Pin 6: an unsupported condition byte writes the C default zero
	 * through the same one-byte path: neither a parity code (10, 11) nor
	 * any other byte outside the 14-code table resolves to a condition.
	 * The stores are made at distinct offsets only to keep the probes
	 * independent. */
	oracle_restore_pristine();
	a = contract_step(1, X86_REG_AUX_SRC_SHIFT(10U), 0x0fU,
			  0x0000000000000040ULL, 0U);
	if (a.value != 0U)
		return 0;
	if (oracle_mem[oracle_slot(a.addr)] != 0U)
		return 0;
	b = contract_step(1, X86_REG_AUX_SRC_SHIFT(11U), 0x0fU,
			  0x0000000000000048ULL, 0U);
	if (b.value != 0U)
		return 0;
	if (b.addr == a.addr)
		return 0;
	if (oracle_mem[oracle_slot(b.addr)] != 0U)
		return 0;
	/* The payload byte names nothing for this opcode: with a zero
	 * source-shift byte the condition is the supported `o` code, and a
	 * payload byte of `ne` at bits 0..7 must not be consulted, even
	 * though the register form would resolve it. */
	b = contract_step(1, 0x00000005U, 0x00U, 0x0000000000000050ULL, 0U);
	if (b.value != 0U)
		return 0;
	if ((__u8)KPROG_X86_EVAL_CC(0x05U, 0, 0, 0, 0) == 0U)
		return 0;
	cases++;

	/* Pin 7: an addressing mode carrying an index adds the scaled index to
	 * the offset; the scale exponent is the AUX scale byte. Both the
	 * contract's offset helper and the restatement must land on the same
	 * address, and the no-index mode must ignore the index value. */
	oracle_restore_pristine();
	a = contract_step(1, X86_MEM_AUX(3U, 2U), 0x01U, 0x0000000000000008ULL,
			  0x1111111100000005ULL);
	{
		__u64 scaled = 0x1111111100000005ULL << 2U;
		__u64 want_mem = oracle_regs[1] + 8ULL + scaled;
		__s64 want_stack =
			(__s64)oracle_regs[X86_RSP] + 8 +
			(__s64)(0x111111110000005ULL << 4U);

		if (a.addr != want_mem)
			return 0;
		b = contract_step(1, X86_MEM_AUX(3U, 2U), 0x01U,
				  0x0000000000000008ULL, 0x0000000000000000ULL);
		if (b.addr != oracle_regs[1] + 8ULL)
			return 0;
		/* A stack destination carries the index too. */
		oracle_restore_pristine();
		b = contract_step(X86_RSP, X86_MEM_AUX(3U, 4U), 0x01U,
				  0x0000000000000008ULL,
				  0x1111111100000005ULL);
		if (b.arm != KPROG_X86_SETCC_MEM_ARM_STACK)
			return 0;
		if (b.addr != (__u64)(__s64)oracle_regs[X86_RSP] + 8ULL +
				      scaled * 4ULL)
			return 0;
		(void)want_stack;
	}
	cases++;

	return cases;
}

int main(void)
{
	unsigned p1, p2, p3, p4, p5;

	oracle_reset();
	oracle_regs[X86_RSP] = 32U;
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

	printf("x86 setcc_mem handler host cross-check: OK (%u cases)\n",
	       p1 + p2 + p3 + p4 + p5);
	return 0;
}
