/*
 * Host cross-check for the x86-64 shared `MOV_STORE` handler composition
 * (`X86_SIM_L_EXEC_STORE`, the single body shared by `X86_OP_MOV_STORE_IMM`
 * (`0x07`) and `X86_OP_MOV_STORE_REG` (`0x08`)).
 *
 * Part 1 verifies the generated width-resolution contract
 * KPROG_X86_STORE_WIDTH from generated/x86_store.h against an independent
 * oracle that restates the fallback from the raw codes.
 *
 * Part 2 verifies the generated arm contract KPROG_X86_STORE_ARM against an
 * independent oracle that restates the branch from the destination register's
 * identity.
 *
 * Part 3 drives the whole handler over a deterministic memory, register, and
 * stack model: it resolves the width through the generated width macro,
 * selects the displacement slice through the generated displacement macro,
 * selects the value's source and the AUX shift source through the generated
 * macros, computes the effective address through the generated offset contract
 * (KPROG_X86_MEM_OFFSET), selects the destination arm through the generated
 * arm macro, and writes through the generated little-endian store contract
 * (KPROG_X86_MEM_STORE) or the stack helper's restatement. Every resulting
 * byte of both the memory and the stack model must match a hand-written model
 * of the C body byte for byte.
 *
 * The point of this oracle is the asymmetries of this handler: it resolves one
 * width used for both the immediate value and the write, the stack arm
 * re-derives the same `FLAGS ? FLAGS : 64` expression (there is no second,
 * AUX-sourced memory width as in the read body), the immediate form takes
 * `(s32)(IMM >> 32)` while the register form takes `(s64)IMM`, only the
 * register form consults the AUX source-shift field, and the register source is
 * read at the full 64 bits even at a narrow store width.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. test_x86_store_host.c -o /tmp/t_st && /tmp/t_st
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

#define X86_OP_MOV_STORE_IMM 0x07U
#define X86_OP_MOV_STORE_REG 0x08U

/* Restate the addressing AUX decoders x86_sim.h defines, so the oracle
 * exercises the same encoding the sim uses. */
#define X86_MEM_AUX(INDEX, SCALE_LOG2)                                      \
	(((__u32)(INDEX) & 0xffU) | (((__u32)(SCALE_LOG2) & 0xffU) << 8))
#define X86_MEM_AUX_INDEX(AUX) ((__u8)((AUX) & 0xffU))
#define X86_MEM_AUX_SCALE_LOG2(AUX) ((__u8)(((AUX) >> 8) & 0xffU))

/* The store's AUX source-shift decoder, restated from x86_sim.h; the generated
 * store header consumes it but does not define it. */
#define X86_REG_AUX_GET_SRC_SHIFT(AUX) ((__u8)(((AUX) >> 24) & 0xffU))

#include "generated/x86_store.h"
#include "generated/x86_mem_offset.h"
#include "generated/x86_mem_access.h"
#include "generated/x86_immediate.h"
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
 * little-endian. The C helper's 64-bit aligned-slot fast path writes the
 * unmasked value, which the width-64 mask makes identical to the byte path. */
static void oracle_stack_store(__s64 off, unsigned width, __u64 value)
{
	__u32 index = (__u32)(off + ORACLE_STACK_BYTES);
	__u64 narrowed = value & oracle_mask(width ? width : X86_WIDTH_64);
	unsigned i;

	for (i = 0; i < width; i++)
		oracle_stack[(index + i) % ORACLE_STACK_BYTES] =
			(__u8)(narrowed >> (8 * i));
}

/* The immediate-value rule, restated from the raw artifact. */
static __u64 oracle_immediate_value(__u64 imm, unsigned width)
{
	if (width == X86_WIDTH_64 && (imm & 0x80000000ULL))
		return (imm & 0xffffffffULL) | 0xffffffff00000000ULL;
	return imm & 0xffffffffULL;
}

/* The immediate store's displacement slice, restated: the artifact's high 32
 * bits sign-extended. */
static __s64 oracle_store_imm_disp(__u64 imm)
{
	return (__s32)(imm >> 32);
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
/* Part 1: the generated width-resolution contract vs. the oracle.     */
/* ------------------------------------------------------------------ */

static unsigned part1(void)
{
	static const __u8 codes[5] = { 0U, X86_WIDTH_8, X86_WIDTH_16,
				       X86_WIDTH_32, X86_WIDTH_64 };
	unsigned cases = 0;
	unsigned fi;

	for (fi = 0; fi < 5; fi++) {
		__u8 flags = codes[fi];
		__u8 want = flags ? flags : X86_WIDTH_64;
		__u8 got = KPROG_X86_STORE_WIDTH(flags);

		if (got != want) {
			fprintf(stderr, "width mismatch flags=%u got=%u want=%u\n",
				flags, got, want);
			return 0;
		}
		if (got == KPROG_X86_STORE_WIDTH_ABSENT) {
			fprintf(stderr, "absent width flags=%u\n", flags);
			return 0;
		}
		cases++;
	}
	return cases;
}

/* ------------------------------------------------------------------ */
/* Part 2: the generated arm contract vs. the oracle.                  */
/* ------------------------------------------------------------------ */

static unsigned part2(void)
{
	unsigned cases = 0;
	int rsp;

	for (rsp = 0; rsp < 2; rsp++) {
		__u8 want = rsp ? KPROG_X86_STORE_ARM_STACK
				: KPROG_X86_STORE_ARM_MEMORY;
		__u8 got = KPROG_X86_STORE_ARM(rsp);

		if (got != want) {
			fprintf(stderr, "arm mismatch rsp=%d got=%u want=%u\n",
				rsp, got, want);
			return 0;
		}
		cases++;
	}
	return cases;
}

/* ------------------------------------------------------------------ */
/* Part 3: the full handler composition vs. the hand-written body.     */
/*                                                                    */
/* `contract_step` resolves, selects, addresses and writes through     */
/* the generated contracts; `model_step` restates the body from the    */
/* raw fields. They must agree byte for byte in both buffers.          */
/* ------------------------------------------------------------------ */

struct store_effect {
	__u8 arm;
	__u8 width;
	__u64 value;
	__u64 addr;
};

/* op: 0 = _MOV_STORE_IMM, 1 = _MOV_STORE_REG. */
static struct store_effect contract_step(int base_index, int op, __u32 aux,
					 __u8 flags, __u64 imm,
					 __u64 index_value)
{
	int is_imm = op == 0;
	int src_index = (base_index + 1) % 16;
	__u8 width = KPROG_X86_STORE_WIDTH(flags);
	__u8 arm = KPROG_X86_STORE_ARM(base_index == X86_RSP);
	__s64 disp = KPROG_X86_STORE_DISP(is_imm, imm);
	__u64 value = KPROG_X86_STORE_VALUE(is_imm, imm, width,
					    oracle_regs[src_index]);
	__u64 shift = KPROG_X86_STORE_SRC_SHIFT(is_imm, aux);
	__u64 base_ptr = oracle_regs[base_index];
	__s64 off;
	struct store_effect r;

	value = KPROG_X86_STORE_SHIFTED_VALUE(value, shift);
	off = KPROG_X86_MEM_OFFSET(aux, disp, index_value,
				   X86_MEM_AUX_INDEX(aux) != X86_REG_NONE);

	r.arm = arm;
	r.width = width;
	r.value = value;
	r.addr = base_ptr + (__u64)off;

	if (arm == KPROG_X86_STORE_ARM_STACK)
		oracle_stack_store((__s64)base_ptr + off, width, value);
	else
		KPROG_X86_MEM_STORE(&oracle_mem[oracle_slot(r.addr)], width,
				    value);
	return r;
}

static struct store_effect model_step(int base_index, int op, __u32 aux,
				      __u8 flags, __u64 imm,
				      __u64 index_value)
{
	int is_imm = op == 0;
	int src_index = (base_index + 1) % 16;
	__u8 width = flags ? flags : X86_WIDTH_64;
	__u64 base_ptr = oracle_regs[base_index];
	__u64 value;
	__u64 shift;
	__s64 off;
	struct store_effect r;

	value = is_imm ? oracle_immediate_value(imm, width)
		       : oracle_regs[src_index];
	if (!is_imm && X86_REG_AUX_GET_SRC_SHIFT(aux) != 0) {
		/* `>>=` on a __u64 uses the x86 count modulo 64. */
		shift = X86_REG_AUX_GET_SRC_SHIFT(aux) & 63U;
		value >>= shift;
	}
	off = oracle_mem_offset(aux,
				is_imm ? oracle_store_imm_disp(imm) : (__s64)imm,
				index_value);

	if (base_index == X86_RSP)
		r.arm = KPROG_X86_STORE_ARM_STACK;
	else
		r.arm = KPROG_X86_STORE_ARM_MEMORY;
	r.width = width;
	r.value = value;
	r.addr = base_ptr + (__u64)off;

	if (r.arm == KPROG_X86_STORE_ARM_STACK)
		oracle_stack_store((__s64)base_ptr + off, width, value);
	else
		oracle_store(r.addr, width, value);
	return r;
}

static unsigned part3(void)
{
	static const __u8 codes[5] = { 0U, X86_WIDTH_8, X86_WIDTH_16,
				       X86_WIDTH_32, X86_WIDTH_64 };
	static const __u8 shift_codes[5] = { 0U, 1U, 63U, 64U, 200U };
	static const __u8 index_codes[5] = { X86_REG_NONE, 0U, 1U, 2U, 3U };
	static const unsigned index_values[3] = { 0U, 0xdeadbeefU,
						  0xffffffc7U };
	unsigned cases = 0;
	unsigned ai, si, fi, di, ii, oi;
	int bi;

	for (bi = 0; bi < 16; bi++) {
		for (oi = 0; oi < 2; oi++) {
			for (ai = 0; ai < 5; ai++) {
				for (si = 0; si < 5; si++) {
					for (fi = 0; fi < 5; fi++) {
						for (di = 0; di < 4; di++) {
							for (ii = 0; ii < 3;
							     ii++) {
								__u32 aux =
								 X86_MEM_AUX(
								  index_codes[ai],
								  si % 4) |
								 ((__u32)shift_codes[si] << 24);
								__u64 imm;
								__u64 index_value =
								 (__u64)index_values[ii];
								struct store_effect got;
								struct store_effect want;

								switch (di) {
								case 0:
									imm = 0x0000000012340002ULL;
									break;
								case 1:
									imm = 0x0000000000000010ULL;
									break;
								case 2:
									imm = 0x1234001000000008ULL;
									break;
								default:
									imm = 0xffffffff00000008ULL;
									break;
								}
								oracle_restore_pristine();
								got = contract_step(
									bi, oi, aux,
									codes[fi], imm,
									index_value);
								memcpy(result_mem,
								       oracle_mem,
								       ORACLE_BYTES);
								memcpy(result_stack,
								       oracle_stack,
								       ORACLE_STACK_BYTES);
								oracle_restore_pristine();
								want = model_step(
									bi, oi, aux,
									codes[fi], imm,
									index_value);
								if (got.arm !=
									    want.arm ||
								    got.width !=
									    want.width ||
								    got.value !=
									    want.value ||
								    got.addr !=
									    want.addr ||
								    memcmp(result_mem,
									   oracle_mem,
									   ORACLE_BYTES) ||
								    memcmp(result_stack,
									   oracle_stack,
									   ORACLE_STACK_BYTES)) {
									fprintf(stderr,
										"handler mismatch "
										"base=%d op=%d aux=%x "
										"flags=%u imm=%llx "
										"idx=%llx got=(%u,%u,%llx,%llx) "
										"want=(%u,%u,%llx,%llx)\n",
										bi, oi,
										aux,
										codes[fi],
										(unsigned long long)imm,
										(unsigned long long)index_value,
										got.arm,
										got.width,
										(unsigned long long)got.value,
										(unsigned long long)got.addr,
										want.arm,
										want.width,
										(unsigned long long)want.value,
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
	}
	return cases;
}

/* ------------------------------------------------------------------ */
/* Part 4: pins on the asymmetries the composition is about.           */
/* ------------------------------------------------------------------ */

static unsigned part4(void)
{
	unsigned cases = 0;
	__u64 base = oracle_regs[1];
	struct store_effect a, b;

	/* Pin 1: the immediate store takes the artifact's high 32 bits as its
	 * displacement, the register store the whole artifact. */
	a = contract_step(1, 0, 0U, 0U, 0x1234001000000008ULL, 0U);
	b = contract_step(1, 1, 0U, 0U, 0x1234001000000008ULL, 0U);
	if (a.addr != base + 0x12340010ULL || b.addr != base + 0x1234001000000008ULL)
		return 0;
	if (a.addr == b.addr)
		return 0;
	cases++;

	/* Pin 2: the AUX source shift is read only on the register form, and is
	 * taken modulo 64 (0xc1 = 193, 193 mod 64 = 1). */
	a = contract_step(1, 0, (__u32)0xc1U << 24, 0U,
			  0x0000000000000008ULL, 0U);
	b = contract_step(1, 1, (__u32)0xc1U << 24, 0U,
			  0x0000000000000008ULL, 0U);
	if (a.value != oracle_immediate_value(0x0000000000000008ULL, X86_WIDTH_64))
		return 0;
	if (b.value != (oracle_regs[2] >> 1))
		return 0;
	cases++;

	/* Pin 3: the stack arm is reached at the single resolved width, writes
	 * the stack frame only, and leaves process memory untouched. */
	oracle_restore_pristine();
	a = contract_step(X86_RSP, 0, 0U, X86_WIDTH_8, 0x0000000012340011ULL, 0U);
	if (a.arm != KPROG_X86_STORE_ARM_STACK)
		return 0;
	if (memcmp(oracle_mem, pristine_mem, ORACLE_BYTES) != 0)
		return 0;
	if (oracle_stack[(unsigned)((__s64)oracle_regs[X86_RSP] + 0) %
			 ORACLE_STACK_BYTES] != 0x11U)
		return 0;
	cases++;

	/* Pin 4: a narrow store writes the low byte only; the byte past the
	 * access width keeps its old value. */
	oracle_restore_pristine();
	a = contract_step(1, 0, 0U, X86_WIDTH_8, 0x0000000011223388ULL, 0U);
	{
		unsigned slot = oracle_slot(a.addr);
		__u8 old_next = pristine_mem[slot + 1];

		if (oracle_mem[slot] != 0x88U)
			return 0;
		if (oracle_mem[slot + 1] != old_next)
			return 0;
	}
	cases++;

	/* Pin 5: the 64-bit store writes all eight little-endian bytes of the
	 * width-masked value. */
	oracle_restore_pristine();
	a = contract_step(1, 1, (__u32)0x03U << 24, 0U, 0x0000000000000000ULL, 0U);
	{
		unsigned slot = oracle_slot(a.addr);
		__u64 v = a.value & 0xffffffffffffffffULL;
		unsigned i;
		int ok = 1;

		for (i = 0; i < 8; i++)
			if (oracle_mem[slot + i] !=
			    (__u8)((v >> (8 * i)) & 0xffU))
				ok = 0;
		if (!ok)
			return 0;
	}
	cases++;

	/* Pin 6: an addressing mode carrying an index adds the scaled index to
	 * the offset; the scale exponent is the AUX scale byte. */
	oracle_restore_pristine();
	a = contract_step(1, 0, X86_MEM_AUX(3U, 2U), 0U,
			  0x0000000000000000ULL, 0x1111111100000005ULL);
	if (a.addr != base + ((__u64)0x1111111100000005ULL << 2U))
		return 0;
	cases++;

	return cases;
}

int main(void)
{
	unsigned p1, p2, p3, p4;

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

	printf("x86 store handler host cross-check: OK (%u cases)\n",
	       p1 + p2 + p3 + p4);
	return 0;
}
