/*
 * Host cross-check for the AArch64 simulator's *routing* of its generic ALU arm
 * through the machine-checked operand-source-selection contract
 * (generated/arm64_alu_operand_select.h, STEP 0129).
 *
 * The macro under test is the real generated selector
 * KPROG_ARM64_ALU_OPERAND_SELECT(OP), reached through the real dispatcher
 * `ARM64_SIM_L_EXEC` of `../arm64/arm64_sim_local_bpf.h` at the generic ALU arm
 * (ARM64_OP_ALU_IMM / ARM64_OP_ALU_REG). The selector returns the 0/1 source
 * decision that feeds the first argument of `KPROG_ARM64_ALU_RHS`: the ALU
 * immediate opcode selects the decoded immediate, the ALU register opcode
 * selects the (modifier-rewritten) second-source read.
 *
 * Each case plants distinct immediate and second-source values, so a selector
 * that picked the wrong operand writes a visibly different destination. The
 * oracle computes the whole post-state with an independent model (which restates
 * the operand decision from the raw opcode with its own switch, never the
 * generated selector) and requires exact agreement: the immediate form writes
 * the immediate as the right-hand operand, the register form applies
 * KPROG_ARM64_MOD_VALUE to the second source. The two are then folded by the
 * shared KPROG_ALU64_RESULT, and the writeback is the 64-bit ADD pointer path or
 * the width-narrowed scalar write, driven at all four widths.
 *
 * A non-member opcode (RET) must reach the unsupported arm exactly once and
 * leave the state unchanged, so the counter is not vacuously zero.
 *
 * Build and run:
 *   cd kprog/formal &&
 *   cc -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog \
 *      -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *      test_arm64_alu_operand_select_route_host.c -o build/test_arm64_alu_operand_select_route_host &&
 *   ./build/test_arm64_alu_operand_select_route_host
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

#define HEAP_BYTES 4096U
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

/* One dispatcher arm of `ARM64_SIM_L_EXEC`, restated over the model state. The
 * operand-source decision is restated from the raw opcode with a local switch,
 * independent of the generated selector. Every arm this oracle drives is total
 * over its operands at the values the oracle plants, so the model's unsupported
 * hook must stay untouched. */
static void model_exec(unsigned op, unsigned dst, unsigned src, unsigned src2,
		       unsigned src3, unsigned width, __u32 aux, __s64 imm)
{
	if (op == ARM64_OP_ALU_IMM || op == ARM64_OP_ALU_REG) {
		__u64 lhs = m_reg(src);
		__u64 rhs;
		__u8 alu_op = (__u8)(aux & 0xffU);
		__u64 result;
		__u8 src_tag;

		if (op == ARM64_OP_ALU_IMM)
			rhs = (__u64)imm;
		else
			rhs = KPROG_ARM64_MOD_VALUE(KPROG_ARM64_AUX_B1(aux),
						    m_reg(src2),
						    KPROG_ARM64_AUX_B2(aux),
						    width);

		result = KPROG_ALU64_RESULT(alu_op, lhs, rhs, model_unsupported());
		src_tag = m_rtag(src);

		if (KPROG_ARM64_ALU_USE_POINTER(width, alu_op, dst == ARM64_SP,
						src_tag == ARM64_SIM_TAG_SCALAR))
			model_write_reg_ptr_tag(dst,
				(__u64)(__u8 *)(long)m_reg(src) + rhs, src_tag);
		else
			model_write_reg_width(dst, result, width);
		(void)lhs;
	} else {
		model_unsupported();
	}
	(void)src3;
}

/* ------------------------------------------------------------------ */
/* The checker.                                                        */
/* ------------------------------------------------------------------ */

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
 * delta: 0 for a selected opcode (its own arm), 1 for a non-member. When
 * `scalar_src` is set the source register is re-tagged scalar after planting, so
 * the 64-bit ADD pointer path is skipped on both sides. */
static void run_case(unsigned op, unsigned dst, unsigned src, unsigned src2,
		     unsigned src3, unsigned width, __u32 aux, __s64 imm,
		     int member, int scalar_src, const char *name)
{
	unsigned long u0 = unsupported_calls;
	unsigned long mu0 = model_unsupported_calls;

	ARM64_SIM_L_DECLARE_STATE();
	ARM64_SIM_L_DECLARE_STACK();
	__u8 __a64_sim_abi_kind = KPROG_ABI_KIND_XDP;
	(void)__a64_sim_abi_kind;
	(void)__a64_lr;

	PLANT_ALL();

	if (scalar_src) {
		ARM64_SIM_L_WRITE_REG_PTR_TAG(src,
			(void *)(long)pattern_reg(src), ARM64_SIM_TAG_SCALAR);
		mtag[src] = ARM64_SIM_TAG_SCALAR;
	}

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
	static const unsigned alu_ops[6] = {
		ARM64_ALU_ADD, ARM64_ALU_SUB, ARM64_ALU_AND,
		ARM64_ALU_BIC, ARM64_ALU_EOR, ARM64_ALU_ORR,
	};
	static const unsigned mods[9] = {
		ARM64_MOD_NONE, ARM64_MOD_LSL, ARM64_MOD_LSR, ARM64_MOD_ASR,
		ARM64_MOD_ROR, ARM64_MOD_UXTW, ARM64_MOD_UXTH, ARM64_MOD_UXTB,
		ARM64_MOD_SXTB,
	};
	/* Distinct nonzero immediates: none equal to any planted register or
	 * second-source value, so a selector that picked the wrong operand writes
	 * a visibly different destination. */
	static const __s64 imms[4] = { 0x11, 0x1234, 0x5a5a5a5aLL,
				       0x00ff00ff00ff00ffLL };
	unsigned i;
	unsigned k;
	unsigned a;
	unsigned m;

	for (i = 0; i < HEAP_BYTES; i++)
		heap_img[i] = (__u8)(0x30U + i * 7U + (i >> 3));
	for (i = 0; i < STACK_BYTES; i++)
		stk_img[i] = (__u8)(0xa0U + i * 3U);
	for (i = 0; i < STACK_SLOTS; i++)
		stk_tag_img[i] = (__u8)(i % 3U);

	for (k = 0; k < sizeof(widths) / sizeof(widths[0]); k++) {
		__u8 width = (__u8)widths[k];

		for (a = 0; a < sizeof(alu_ops) / sizeof(alu_ops[0]); a++) {
			__u32 aux_imm = KPROG_ARM64_AUX(alu_ops[a], 0U, 0U, 0U);

			/* ALU_IMM: the decoded immediate as the right-hand
			 * operand, all four widths and every ALU operation. */
			for (i = 0; i < 4U; i++)
				run_case(ARM64_OP_ALU_IMM, ARM64_X2, ARM64_X1,
					 ARM64_X5, ARM64_X4, width, aux_imm,
					 imms[i], 1, 0, "aluImm");

			/* ALU_REG: the modifier-rewritten second-source read; a
			 * small shift keeps the extend arms in domain. */
			for (m = 0; m < sizeof(mods) / sizeof(mods[0]); m++) {
				__u32 aux_reg = KPROG_ARM64_AUX(
					alu_ops[a], mods[m], (unsigned)(m % 4U),
					0U);

				run_case(ARM64_OP_ALU_REG, ARM64_X2, ARM64_X1,
					 ARM64_X5, ARM64_X4, width, aux_reg, 0,
					 1, 0, "aluReg");
			}
		}

		/* A non-member opcode must reach the unsupported arm exactly
		 * once and leave the state unchanged. */
		run_case(ARM64_OP_RET, ARM64_X2, ARM64_X1, ARM64_X5, ARM64_X4,
			 width, 0U, 0, 0, 0, "nonmember");
	}

	/* The 64-bit ADD pointer path (dst != SP, source not scalar) is reached
	 * through the immediate form with ALU_ADD at doubleword width. */
	run_case(ARM64_OP_ALU_IMM, ARM64_X2, ARM64_X1, ARM64_X5, ARM64_X4,
		 ARM64_WIDTH_64, KPROG_ARM64_AUX(ARM64_ALU_ADD, 0U, 0U, 0U),
		 0x40, 1, 0, "aluImmPointer");

	/* A scalar-tagged source at doubleword width skips the pointer path and
	 * takes the width-narrowed scalar write. */
	run_case(ARM64_OP_ALU_IMM, ARM64_X2, ARM64_X1, ARM64_X5, ARM64_X4,
		 ARM64_WIDTH_64, KPROG_ARM64_AUX(ARM64_ALU_ADD, 0U, 0U, 0U),
		 0x40, 1, 1, "aluImmScalarSrc");

	/* SP destination: the write reaches SP, never the pointer path. */
	run_case(ARM64_OP_ALU_IMM, ARM64_SP, ARM64_X1, ARM64_X5, ARM64_X4,
		 ARM64_WIDTH_64, KPROG_ARM64_AUX(ARM64_ALU_SUB, 0U, 0U, 0U),
		 0x40, 1, 0, "aluImmSpDst");

	if (failures != 0) {
		printf("arm64 alu operand select route host cross-check: FAIL (%d)\n",
		       failures);
		return 1;
	}
	printf("arm64 alu operand select route host cross-check: OK (%lu cases)\n",
	       cases);
	return 0;
}
