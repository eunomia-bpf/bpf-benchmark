/*
 * Host cross-check for the AArch64 simulator's *routing* of its two
 * immediate/register operand-source arms through the machine-checked
 * operand-source contract (generated/arm64_imm_operand.h, STEP 0127).
 *
 * The macro under test is the real generated selector KPROG_ARM64_IMM_RHS(OP,
 * IMM, REG), reached through the real dispatcher `ARM64_SIM_L_EXEC` of
 * `../arm64/arm64_sim_local_bpf.h` at the two arms that select an operand
 * between the decoded immediate and a register expression:
 *
 *   - the move arm (ARM64_OP_MOV_IMM / ARM64_OP_MOV_REG), where the register
 *     expression is the source read;
 *   - the shift arm (ARM64_OP_SHIFT_IMM / ARM64_OP_SHIFT_REG), where the
 *     register expression is the second-source read.
 *
 * Each case plants distinct immediate and register values, so a selector that
 * picked the wrong one writes a visibly different destination. The oracle
 * computes the whole post-state with an independent model and requires the two
 * to agree exactly: the immediate form writes the immediate, the register form
 * writes the source register (or the second source for the shift), through the
 * same width-narrowed write.
 *
 * The move arm's register form at doubleword width writes through the tag-copy
 * path, so the register forms are driven at all four widths: the tag-copy path
 * at 64-bit and the width-narrowed scalar path otherwise. The immediate form
 * never preserves provenance.
 *
 * A non-member opcode (RET) must reach the unsupported arm exactly once and
 * leave the state unchanged, so the counter is not vacuously zero.
 *
 * Build and run:
 *   cd kprog/formal &&
 *   cc -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog \
 *      -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *      test_arm64_imm_operand_route_host.c -o build/test_arm64_imm_operand_route_host &&
 *   ./build/test_arm64_imm_operand_route_host
 */

#define ARM64_SIM_ENABLE_STACK 1
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;
typedef signed long long __s64;
typedef signed int __s32;

#define __always_inline inline

#include "../arm64/arm64_sim_local_bpf.h"

#include <stdio.h>
#include <string.h>

/* The simulator header expects this hook. Its call count is the observable that
 * a member reached its own arm and a non-member did not. */
static unsigned long unsupported_calls;
static void arm64_sim_unsupported_opcode(void)
{
	unsupported_calls++;
}

/* The model's own unsupported hook, so a generated sub-contract that took its
 * default arm is caught without touching the simulator's counter. */
static unsigned long model_unsupported_calls;
static void model_unsupported(void)
{
	model_unsupported_calls++;
}

static int failures;
static unsigned long cases;

/* ---- Model state ------------------------------------------------------- */

/* The register file the model tracks, kept parallel to the simulator's own
 * state so the whole file (value and tag) can be compared after every case. */
static __u64 mreg[31];
static __u8 mtag[31];
static __s64 msp;
static __u64 m_v0;
static __u64 m_v0_hi;
static __u8 m_n;
static __u8 m_z;
static __u8 m_c;
static __u8 m_v;

/* The memory windows the memory-family arms the planted registers point into,
 * so the whole image stays comparable (no arm drives memory here, but the
 * planted bases still have to agree). */
#define HEAP_BYTES 4096U
#define MISC_BASE_OFF 1024U
#define RELOC_BASE_OFF 2048U
#define ABI_BASE_OFF 3072U
static __u8 heap[HEAP_BYTES];
static __u8 heap_exp[HEAP_BYTES];
static __u8 heap_img[HEAP_BYTES];

/* The stack arena image, indexed exactly as `ARM64_SIM_L_STACK_*` index it
 * (bias included). */
#define STACK_BYTES 160U
#define STACK_SLOTS 20U
static __u8 stk_exp[STACK_BYTES];
static __u8 stk_tag_exp[STACK_SLOTS];
static __u8 stk_img[STACK_BYTES];
static __u8 stk_tag_img[STACK_SLOTS];

/* The stack base pointer value the oracle plants. */
#define STACK_BASE_VAL (-64LL)

/* A deterministic register pattern: distinct per index, with high bits set so
 * a 64-bit-vs-narrow write is observable. */
static __u64 pattern_reg(unsigned i)
{
	return 0x9e3779b97f4a7c15ULL * (__u64)(i + 1U) + 0x0123456789abcdefULL;
}

/* A non-scalar tag pattern: never `ARM64_SIM_TAG_SCALAR`, so a form that
 * scalarizes changes the destination tag. */
static __u8 pattern_tag(unsigned i)
{
	return (__u8)(1U + (i % 5U));
}

/* ------------------------------------------------------------------ */
/* The flat little-endian byte image and the model's own read/write.    */
/* ------------------------------------------------------------------ */

/* `ARM64_SIM_L_WRITE_REG_WIDTH`, restated against the model register file. */
static void model_write_reg_width(unsigned reg, __u64 value, unsigned width)
{
	__u64 next = KPROG_ARM64_APPLY_WIDTH(value, width);

	if (reg == ARM64_SP) {
		msp = (__s64)next;
	} else if (reg != ARM64_XZR && reg != ARM64_REG_NONE) {
		if (width == ARM64_WIDTH_32)
			mreg[reg] = (__u32)next;
		else
			mreg[reg] = next;
		mtag[reg] = ARM64_SIM_TAG_SCALAR;
	}
}

/* `ARM64_SIM_L_WRITE_REG_PTR_TAG`, restated against the model register file. */
static void model_write_reg_ptr_tag(unsigned reg, __u64 value, __u8 tag)
{
	if (reg != ARM64_XZR && reg != ARM64_REG_NONE) {
		mreg[reg] = value;
		mtag[reg] = tag;
	}
}

/* The register file as the arm bodies read it: the stack pointer, zero for the
 * zero register and the no-register sentinel, the stored value otherwise. */
static __u64 m_reg(unsigned reg)
{
	if (reg == ARM64_SP)
		return (__u64)msp;
	if (reg >= 31U)
		return 0;
	return mreg[reg];
}

static __u8 m_rtag(unsigned reg)
{
	if (reg == ARM64_SP)
		return ARM64_SIM_TAG_STACK;
	if (reg >= 31U)
		return ARM64_SIM_TAG_SCALAR;
	return mtag[reg];
}

/* ------------------------------------------------------------------ */
/* The independent arm model.                                          */
/* ------------------------------------------------------------------ */

/* One dispatcher arm of `ARM64_SIM_L_EXEC`, restated over the model state.
 * Every arm this oracle drives is total over its operands at the values the
 * oracle plants, so the model's unsupported hook must stay untouched. */
static void model_exec(unsigned op, unsigned dst, unsigned src, unsigned src2,
		       unsigned src3, unsigned width, __u32 aux, __s64 imm)
{
	switch (op) {
	case ARM64_OP_MOV_IMM:
		model_write_reg_width(dst, (__u64)imm, width);
		break;
	case ARM64_OP_MOV_REG:
		/* The register form at doubleword width copies provenance
		 * through the tag-copy write; every other width goes through the
		 * scalar write. */
		if (width == ARM64_WIDTH_64)
			model_write_reg_ptr_tag(dst, m_reg(src), m_rtag(src));
		else
			model_write_reg_width(dst, m_reg(src), width);
		break;
	case ARM64_OP_SHIFT_IMM:
		model_write_reg_width(dst,
			KPROG_ARM64_SHIFT_VALUE(KPROG_ARM64_AUX_B0(aux),
						m_reg(src), (__u64)imm, width,
						model_unsupported()),
			width);
		break;
	case ARM64_OP_SHIFT_REG:
		model_write_reg_width(dst,
			KPROG_ARM64_SHIFT_VALUE(KPROG_ARM64_AUX_B0(aux),
						m_reg(src), m_reg(src2), width,
						model_unsupported()),
			width);
		break;
	default:
		model_unsupported();
		break;
	}
	(void)src3;
}

/* ------------------------------------------------------------------ */
/* The checker.                                                        */
/* ------------------------------------------------------------------ */

/* Plant the simulator and model register files, flags, SIMD quarters and both
 * memory images with the identical pattern, and anchor the shared base, index
 * and value registers. Written as a macro so it expands in the checker's own
 * state scope. */
#define PLANT_ALL()                                                        \
	do {                                                               \
		unsigned __pl_i;                                          \
		for (__pl_i = 0; __pl_i < 31U; __pl_i++) {                \
			ARM64_SIM_L_WRITE_REG_PTR_TAG(                    \
				__pl_i,                                   \
				(void *)(long)pattern_reg(__pl_i),        \
				pattern_tag(__pl_i));                     \
			mreg[__pl_i] = pattern_reg(__pl_i);               \
			mtag[__pl_i] = pattern_tag(__pl_i);               \
		}                                                         \
		__a64_sp = STACK_BASE_VAL;                                \
		msp = STACK_BASE_VAL;                                     \
		__a64_v0 = pattern_reg(40);                               \
		m_v0 = __a64_v0;                                          \
		__a64_v0_hi = pattern_reg(41);                            \
		m_v0_hi = __a64_v0_hi;                                    \
		__a64_n = m_n = 1;                                        \
		__a64_z = m_z = 1;                                        \
		__a64_c = m_c = 1;                                        \
		__a64_v = m_v = 1;                                        \
		for (__pl_i = 0; __pl_i < HEAP_BYTES; __pl_i++) {         \
			heap[__pl_i] = heap_img[__pl_i];                  \
			heap_exp[__pl_i] = heap_img[__pl_i];              \
		}                                                         \
		for (__pl_i = 0; __pl_i < STACK_BYTES; __pl_i++) {        \
			__a64_stack.b[__pl_i] = stk_img[__pl_i];          \
			stk_exp[__pl_i] = stk_img[__pl_i];                \
		}                                                         \
		for (__pl_i = 0; __pl_i < STACK_SLOTS; __pl_i++) {        \
			__a64_stack_tag[__pl_i] = stk_tag_img[__pl_i];    \
			stk_tag_exp[__pl_i] = stk_tag_img[__pl_i];        \
		}                                                         \
	} while (0)

/* Compare the whole simulator state against the model image. */
#define COMPARE_STATE(NAME, OP, WIDTH, AUX, IMM)                           \
	do {                                                               \
		unsigned __cs_i;                                          \
		for (__cs_i = 0; __cs_i < 31U; __cs_i++) {                \
			__u64 __cs_got = ARM64_SIM_L_READ_REG(__cs_i);    \
			__u8 __cs_tag = ARM64_SIM_L_REG_TAG(__cs_i);      \
			cases++;                                          \
			if (__cs_got != mreg[__cs_i]) {                   \
				printf("MISMATCH %s op=%#x width=%u aux=%#x " \
				       "imm=%lld reg%u: got 0x%llx want "     \
				       "0x%llx\n", (NAME), (OP), (WIDTH),     \
				       (AUX), (long long)(IMM),               \
				       (unsigned)__cs_i,                      \
				       (unsigned long long)__cs_got,          \
				       (unsigned long long)mreg[__cs_i]);     \
				failures++;                               \
				return;                                   \
			}                                                 \
			cases++;                                          \
			if (__cs_tag != mtag[__cs_i]) {                   \
				printf("MISMATCH %s op=%#x reg%u tag: got "   \
				       "%u want %u\n", (NAME), (OP),          \
				       (unsigned)__cs_i, __cs_tag,            \
				       mtag[__cs_i]);                         \
				failures++;                               \
				return;                                   \
			}                                                 \
		}                                                         \
		cases++;                                                  \
		if (__a64_sp != msp) {                                    \
			printf("MISMATCH %s op=%#x sp: got %lld want %lld\n",\
			       (NAME), (OP), (long long)__a64_sp,          \
			       (long long)msp);                           \
			failures++;                                       \
			return;                                           \
		}                                                         \
		cases++;                                                  \
		if (__a64_v0 != m_v0 || __a64_v0_hi != m_v0_hi) {         \
			printf("MISMATCH %s op=%#x v0: got 0x%llx/0x%llx "    \
			       "want 0x%llx/0x%llx\n", (NAME), (OP),         \
			       (unsigned long long)__a64_v0,                 \
			       (unsigned long long)__a64_v0_hi,              \
			       (unsigned long long)m_v0,                     \
			       (unsigned long long)m_v0_hi);                 \
			failures++;                                       \
			return;                                           \
		}                                                         \
		cases++;                                                  \
		if (__a64_n != m_n || __a64_z != m_z || __a64_c != m_c || \
		    __a64_v != m_v) {                                     \
			printf("MISMATCH %s op=%#x flags %u%u%u%u/%u%u%u%u\n",\
			       (NAME), (OP), __a64_n, __a64_z, __a64_c,      \
			       __a64_v, m_n, m_z, m_c, m_v);                 \
			failures++;                                       \
			return;                                           \
		}                                                         \
		cases++;                                                  \
		if (memcmp(heap, heap_exp, HEAP_BYTES) != 0 ||            \
		    memcmp(__a64_stack.b, stk_exp, STACK_BYTES) != 0 ||   \
		    memcmp(__a64_stack_tag, stk_tag_exp, STACK_SLOTS) != 0) {\
			printf("MISMATCH %s op=%#x width=%u aux=%#x imm=%lld " \
			       "memory image\n", (NAME), (OP), (WIDTH),      \
			       (AUX), (long long)(IMM));                     \
			failures++;                                       \
			return;                                           \
		}                                                         \
	} while (0)

/* Drive one arm through the real dispatcher and compare the whole state to the
 * model's independent computation. `member` selects the expected unsupported
 * delta: 0 for a selected opcode (its own arm), 1 for a non-member. */
static void run_case(unsigned op, unsigned dst, unsigned src, unsigned src2,
		     unsigned src3, unsigned width, __u32 aux, __s64 imm,
		     int member, const char *name)
{
	unsigned long u0 = unsupported_calls;
	unsigned long mu0 = model_unsupported_calls;

	ARM64_SIM_L_DECLARE_STATE();
	ARM64_SIM_L_DECLARE_STACK();
	__u8 __a64_sim_abi_kind = KPROG_ABI_KIND_XDP;
	(void)__a64_sim_abi_kind;
	(void)__a64_lr;

	PLANT_ALL();

	model_exec(op, dst, src, src2, src3, width, aux, imm);
	ARM64_SIM_L_EXEC(op, dst, src, src2, src3, width, aux, imm);

	cases++;
	if (member) {
		if (unsupported_calls != u0) {
			printf("MISMATCH %s op=%#x width=%u reached the "
			       "unsupported arm\n", name, op, width);
			failures++;
		}
		cases++;
		if (model_unsupported_calls != mu0) {
			printf("MISMATCH %s op=%#x width=%u model took an "
			       "unsupported sub-contract arm\n", name, op,
			       width);
			failures++;
		}
	} else {
		if (unsupported_calls != u0 + 1UL) {
			printf("MISMATCH %s op=%#x width=%u unsupported delta=%lu"
			       "\n", name, op, width,
			       unsupported_calls - u0);
			failures++;
		}
	}

	COMPARE_STATE(name, op, width, aux, imm);
}

int main(void)
{
	static const unsigned widths[4] = {
		ARM64_WIDTH_8, ARM64_WIDTH_16, ARM64_WIDTH_32, ARM64_WIDTH_64,
	};
	static const unsigned shift_kinds[4] = {
		ARM64_SHIFT_LSL, ARM64_SHIFT_LSR, ARM64_SHIFT_ASR,
		ARM64_SHIFT_ROR,
	};
	/* Distinct nonzero immediates: none equal to any planted register
	 * value, so a selector that picked the wrong operand diverges. */
	static const __s64 imms[4] = { 0, 1, 0x1234, 0x5a5a5a5aLL };
	unsigned i;
	unsigned k;

	for (i = 0; i < HEAP_BYTES; i++)
		heap_img[i] = (__u8)(0x30U + i * 7U + (i >> 3));
	for (i = 0; i < STACK_BYTES; i++)
		stk_img[i] = (__u8)(0xa0U + i * 3U);
	for (i = 0; i < STACK_SLOTS; i++)
		stk_tag_img[i] = (__u8)(i % 3U);

	(void)MISC_BASE_OFF;
	(void)RELOC_BASE_OFF;
	(void)ABI_BASE_OFF;

	for (k = 0; k < sizeof(widths) / sizeof(widths[0]); k++) {
		__u8 width = (__u8)widths[k];

		/* MOV_IMM: the decoded immediate, all four widths. */
		for (i = 0; i < 4U; i++)
			run_case(ARM64_OP_MOV_IMM, ARM64_X2, ARM64_X1,
				 ARM64_X3, ARM64_X4, width, 0U, imms[i], 1,
				 "movImm");

		/* MOV_REG: the source read; provenance survives only at
		 * doubleword width. */
		run_case(ARM64_OP_MOV_REG, ARM64_X2, ARM64_X1, ARM64_X3,
			 ARM64_X4, width, 0U, (__s64)0xdead, 1, "movReg");

		/* SHIFT_IMM / SHIFT_REG: every shift kind, distinct immediate
		 * and second-source values. */
		for (i = 0; i < 4U; i++) {
			__u32 aux = (__u32)ARM64_AUX_SHIFT(shift_kinds[i]);

			run_case(ARM64_OP_SHIFT_IMM, ARM64_X2, ARM64_X1,
				 ARM64_X3, ARM64_X4, width, aux,
				 (__s64)(3U + i), 1, "shiftImm");
			run_case(ARM64_OP_SHIFT_REG, ARM64_X2, ARM64_X1,
				 ARM64_X3, ARM64_X4, width, aux, 0, 1,
				 "shiftReg");
		}

		/* A non-member opcode must reach the unsupported arm exactly
		 * once and leave the state unchanged. */
		run_case(ARM64_OP_RET, ARM64_X2, ARM64_X1, ARM64_X3, ARM64_X4,
			 width, 0U, 0, 0, "nonmember");
	}

	if (failures != 0) {
		printf("arm64 imm operand route host cross-check: FAIL (%d)\n",
		       failures);
		return 1;
	}
	printf("arm64 imm operand route host cross-check: OK (%lu cases)\n",
	       cases);
	return 0;
}
