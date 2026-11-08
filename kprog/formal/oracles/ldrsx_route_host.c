/*
 * Host cross-check for the AArch64 simulator's sim-local sign-extending load
 * arm `ARM64_SIM_L_LDRSX_HANDLED` of `ARM64_SIM_L_EXEC` in
 * `../arm64/arm64_sim_local_bpf.h` (STEP 0452, mutation battery 0452). Unlike
 * STEP 0128 the checker replays the arm through BOTH lanes: the real
 * dispatcher arm (via `ARM64_SIM_L_EXEC`) and a direct inline replay of the
 * arm's own statement sequence, so an exec-routed drift is distinguishable
 * from an arm-body drift.
 *
 * The model below is a flat, little-endian byte image with the simulator's
 * own `MEM_PRE` / `MEM_POST` writeback and staged-index arithmetic restated
 * from the raw opcode and AUX word. The sign extension is an independent C
 * cast ladder (`(__s8)` / `(__s16)` / `(__s32)`), never the generated mask
 * idiom. The load width and the sign opcode are decided from the load
 * opcode's numeric code, never the macro's switch.
 *
 * The base file covers the SCALAR and STACK arena arms. The ABI-pointer and
 * RELOC-pointer load arms die at the checker for the sign-extending widths,
 * so their dispatch code paths stay parked behind the same -Werror gates as
 * every other unwired family member.
 *
 * Build and run:
 *   cd kprog/formal &&
 *   cc -Wall -Wextra -Werror -O2 -I. -I../arm64 -I../../kprog \
 *      -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *      build/ldrsx_route_host.c -o build/mut_ldrsxroute &&
 *   ./build/mut_ldrsxroute
 */

#define ARM64_SIM_ENABLE_STACK 1

typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;
typedef signed long long __s64;
typedef signed int __s32;
typedef signed char __s8;
typedef signed short __s16;

#define __always_inline inline

#include "../arm64/arm64_sim_local_bpf.h"

#include <stdio.h>
#include <string.h>

static unsigned long unsupported_calls;
static void arm64_sim_unsupported_opcode(void)
{
	unsupported_calls++;
}

static int failures;
static unsigned long cases;

/* ------------------------------------------------------------ */
/* Model state.                                                  */
/* ------------------------------------------------------------ */

static __u64 mreg[31];
static __u8 mtag[31];
static __s64 msp;
static unsigned long model_unsupported_calls;

static void model_unsupported(void)
{
	model_unsupported_calls++;
}

#define HEAP_BYTES 4096U
#define SCALAR_BASE_OFF 1024U
#define ABI_BASE_OFF 2048U
#define RELOC_BASE_OFF 3072U
static __u8 heap[HEAP_BYTES];
static __u8 heap_exp[HEAP_BYTES];
static __u8 heap_img[HEAP_BYTES];

#define STACK_BYTES 160U
#define STACK_SLOTS 20U
static __u8 stk_exp[STACK_BYTES];
static __u8 stk_tag_exp[STACK_SLOTS];
static __u8 stk_img[STACK_BYTES];
static __u8 stk_tag_img[STACK_SLOTS];

/* The stack base value the checker plants: with the simulator's
 * `ARM64_SIM_STACK_BIAS` of 96 an access at offset 0 lands at arena index 32. */
#define STACK_BASE_VAL (-64LL)

/* The flag byte of an `AUX` word: the top byte, matching `MEM_FLAGS`. */
#define AUX_FLAGS(AUX) ((unsigned)(((AUX) >> 24U) & 0xffU))
#define AUX_MOD(AUX) ((unsigned)(((AUX) >> 8U) & 0xffU))

#define ARM64_MEM_PRE 1U
#define ARM64_MEM_POST 2U

#define INDEX_VALUE 1ULL

static __u64 pattern_reg(unsigned i)
{
	return 0x9e3779b97f4a7c15ULL * (__u64)(i + 1U) + 0x0123456789abcdefULL;
}

#define QUIET_GPR_ONE(REG, NAME) \
	(void)sizeof(__a64_##NAME); \
	(void)sizeof(__a64_##NAME##_tag);

#define DECL_STATE() \
	ARM64_SIM_L_DECLARE_STATE(); \
	__u8 __a64_sim_abi_kind = KPROG_ABI_KIND_XDP; \
	(void)__a64_sim_abi_kind; \
	ARM64_SIM_L_DECLARE_STACK(); \
	ARM64_SIM_L_FOR_EACH_GPR(QUIET_GPR_ONE); \
	(void)__a64_lr

static __u8 pattern_tag(unsigned i)
{
	static const __u8 tags[4] = {
		ARM64_SIM_TAG_SCALAR, ARM64_SIM_TAG_ABI,
		ARM64_SIM_TAG_PACKET, ARM64_SIM_TAG_MAP_PTR,
	};

	return tags[i % 4U];
}

static unsigned long heap_off(__u64 addr)
{
	return (unsigned long)(addr - (__u64)(unsigned long)heap);
}

/* Assemble `width` little-endian bytes from the model image. */
static __u64 img_load(const __u8 *base, unsigned width)
{
	__u64 v = 0;
	unsigned i;

	for (i = 0; i < width; i++)
		v |= (__u64)base[i] << (8U * i);
	return v;
}

static __u64 heap_read(__u64 addr, unsigned width)
{
	return img_load(&heap_exp[heap_off(addr)], width);
}

static __u64 stack_read(__u32 idx, unsigned width)
{
	/* Both stack arms assemble bytes; the word-index shortcut shape is
	 * identical here, so the model keeps one formula. */
	return img_load(&stk_exp[idx], width);
}

static __u64 m_base_val(unsigned base)
{
	return base == ARM64_SP ? (__u64)msp : mreg[base];
}

static __u8 m_base_tag(unsigned base)
{
	return base == ARM64_SP ? ARM64_SIM_TAG_STACK : mtag[base];
}

/* One dispatcher arm of the source-modifier route, restated: a nonzero MOD
 * brings the index register through `APPLY_WIDTH`, everything else runs at
 * the full 64-bit width. */
static __s64 model_index_value(unsigned aux, unsigned index)
{
	__u64 mod64 = (__u64)AUX_MOD(aux);
	unsigned w = 64U;

	if (mod64 != 0U) {
		switch (mod64 % 6U) {
		case 1U:
			w = 8U;
			break;
		case 2U:
			w = 16U;
			break;
		case 3U:
			w = 32U;
			break;
		case 4U:
		case 5U:
		case 0U:
			w = 64U;
			break;
		}
	}
	if (index == ARM64_REG_NONE)
		return 0;
	if (index == ARM64_SP)
		return (__s64)msp;
	return (__s64)KPROG_ARM64_APPLY_WIDTH(mreg[index], w);
}

/* `ARM64_SIM_L_MEM_BASE_OFF` with the source modifier the checker's rotated
 * AUX suffix drives at its identity (MOD == 0), and with the immediate the
 * PRE/POST decode suppresses: an indexed pre/post access applies `imm` as
 * its own writeback instead of in the offset. */
static __s64 model_base_off(unsigned aux, unsigned index, __s64 imm)
{
	return (__s64)KPROG_ARM64_MEM_OFFSET(
		(__u64)(AUX_FLAGS(aux) & (ARM64_MEM_PRE | ARM64_MEM_POST)),
		index != ARM64_REG_NONE, (__u64)imm,
		(__u64)model_index_value(aux, index));
}

static __u64 model_mem_read(unsigned base, unsigned index, unsigned aux,
			    __s64 imm, __s64 extra, unsigned width)
{
	(void)extra;

	__s64 off = model_base_off(aux, index, imm);
	__u8 tag = m_base_tag(base);
	__u64 bv = m_base_val(base);
	__u8 src = KPROG_ARM64_MEM_READ_SRC(base == ARM64_SP, tag, width);

	if (src == KPROG_ARM64_MEM_SRC_STACK)
		return stack_read((__u32)(ARM64_SIM_STACK_BIAS +
					  ((__s64)bv + off)), width);
	if (src == KPROG_ARM64_MEM_SRC_ABI_PTR_LOAD)
		return heap_read(bv + (__u64)off, width);
	if (src == KPROG_ARM64_MEM_SRC_RELOC_PTR)
		return bv;
	return heap_read(bv + (__u64)off, width);
}

static void model_writeback(unsigned base, __s64 imm)
{
	if (base == ARM64_SP)
		msp += imm;
	else
		mreg[base] = mreg[base] + (__u64)imm;
}

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

/* Independent load-width oracle keyed on the load opcode's numeric code. */
static unsigned ldrsx_load_width(unsigned op)
{
	switch (op) {
	case ARM64_OP_LDRSB:
		return ARM64_WIDTH_8;
	case ARM64_OP_LDRSW:
		return ARM64_WIDTH_32;
	case ARM64_OP_LDRSH:
		return ARM64_WIDTH_16;
	default:
		return 0;
	}
}

/* Independent sign extension: an ordinary C sign-extension cast ladder, not
 * the generated `(v ^ sign) - sign` mask idiom. */
static __u64 model_sign_extend(unsigned load_width, __u64 v)
{
	switch (load_width) {
	case ARM64_WIDTH_8:
		return (__u64)(__s64)(__s8)(v & 0xffULL);
	case ARM64_WIDTH_16:
		return (__u64)(__s64)(__s16)(v & 0xffffULL);
	case ARM64_WIDTH_32:
		return (__u64)(__s64)(__s32)(v & 0xffffffffULL);
	default:
		return v;
	}
}

/* The sim-local sign-extending load arm of `ARM64_SIM_L_EXEC`, restated. */
static void model_exec(unsigned op, unsigned dst, unsigned src, unsigned src2,
		       unsigned dst_width, __u32 aux, __s64 imm)
{
	unsigned load_width = ldrsx_load_width(op);

	if (load_width == 0) {
		model_unsupported();
		return;
	}

	/* Arm WBOVERLAPLD and CheckSPAlignment precede memory/writeback. */
	if (((AUX_FLAGS(aux) & 3U) && src != ARM64_SP && src == dst) ||
	    (src == ARM64_SP && ((__u64)msp & 15U))) {
		model_unsupported();
		return;
	}

	if (AUX_FLAGS(aux) & ARM64_MEM_PRE)
		model_writeback(src, imm);

	{
		__u64 loaded = model_mem_read(src, src2, aux, imm, 0,
					      load_width);
		__u64 sext = model_sign_extend(load_width, loaded);

		model_write_reg_width(dst, sext, dst_width);
	}

	if (AUX_FLAGS(aux) & ARM64_MEM_POST)
		model_writeback(src, imm);
}

/* ------------------------------------------------------------ */
/* The checker.                                                  */
/* ------------------------------------------------------------ */

#define STACK_ARENA_INIT()                                                 \
	do {                                                               \
		unsigned __si_i;                                          \
		for (__si_i = 0; __si_i < STACK_BYTES; __si_i++) {         \
			__a64_stack.b[__si_i] = stk_img[__si_i];          \
			stk_exp[__si_i] = stk_img[__si_i];                \
		}                                                         \
		for (__si_i = 0; __si_i < STACK_SLOTS; __si_i++) {         \
			__a64_stack_tag[__si_i] = stk_tag_img[__si_i];    \
			stk_tag_exp[__si_i] = stk_tag_img[__si_i];        \
		}                                                         \
	} while (0)

/* Plant the simulator and model register files with the identical pattern
 * and anchor the destination, base and index the scene selected. Written as
 * a macro so it expands in the checker's own state scope. */
#define PLANT_STATE(DST, BASE, INDEX)                                      \
	do {                                                               \
		unsigned __pl_i;                                          \
		for (__pl_i = 0; __pl_i < 31U; __pl_i++) {                 \
			ARM64_SIM_L_WRITE_REG_PTR_TAG(                    \
				__pl_i,                                   \
				(void *)(long)pattern_reg(__pl_i),        \
				pattern_tag(__pl_i));                     \
			mreg[__pl_i] = pattern_reg(__pl_i);               \
			mtag[__pl_i] = pattern_tag(__pl_i);               \
		}                                                         \
		__a64_sp = STACK_BASE_VAL;                                \
		msp = STACK_BASE_VAL;                                     \
		ARM64_SIM_L_WRITE_REG_PTR_TAG((ARM64_X2),                 \
			(void *)(long)(heap + SCALAR_BASE_OFF),            \
			ARM64_SIM_TAG_SCALAR);                            \
		mreg[ARM64_X2] = (__u64)(long)(heap + SCALAR_BASE_OFF);    \
		mtag[ARM64_X2] = ARM64_SIM_TAG_SCALAR;                    \
		ARM64_SIM_L_WRITE_REG_PTR_TAG((ARM64_X3),                 \
			(void *)(long)(heap + ABI_BASE_OFF),               \
			ARM64_SIM_TAG_ABI);                               \
		mreg[ARM64_X3] = (__u64)(long)(heap + ABI_BASE_OFF);       \
		mtag[ARM64_X3] = ARM64_SIM_TAG_ABI;                       \
		ARM64_SIM_L_WRITE_REG_PTR_TAG((ARM64_X4),                 \
			(void *)(long)(heap + RELOC_BASE_OFF),             \
			ARM64_SIM_TAG_RELOC_ADDR);                        \
		mreg[ARM64_X4] = (__u64)(long)(heap + RELOC_BASE_OFF);      \
		mtag[ARM64_X4] = ARM64_SIM_TAG_RELOC_ADDR;                \
		ARM64_SIM_L_WRITE_REG_PTR_TAG((ARM64_X5),                 \
			(void *)(long)STACK_BASE_VAL,                      \
			ARM64_SIM_TAG_STACK);                             \
		mreg[ARM64_X5] = (__u64)STACK_BASE_VAL;                    \
		mtag[ARM64_X5] = ARM64_SIM_TAG_STACK;                     \
		ARM64_SIM_L_WRITE_REG_PTR_TAG((ARM64_X7),                 \
			(void *)(long)STACK_BASE_VAL,                      \
			ARM64_SIM_TAG_STACK);                             \
		mreg[ARM64_X7] = (__u64)STACK_BASE_VAL;                    \
		mtag[ARM64_X7] = ARM64_SIM_TAG_STACK;                     \
		ARM64_SIM_L_WRITE_REG_PTR_TAG((ARM64_X1),                 \
			(void *)(long)INDEX_VALUE,                         \
			ARM64_SIM_TAG_SCALAR);                            \
		mreg[ARM64_X1] = INDEX_VALUE;                              \
		mtag[ARM64_X1] = ARM64_SIM_TAG_SCALAR;                    \
		if ((DST) < 31U && (DST) != ARM64_X2 &&                     \
		    (DST) != ARM64_X3 && (DST) != ARM64_X4 &&              \
		    (DST) != ARM64_X5 && (DST) != ARM64_X7 &&              \
		    (DST) != ARM64_X1) {                                    \
			ARM64_SIM_L_WRITE_REG_PTR_TAG((DST),              \
				(void *)(long)pattern_reg((DST) + 5U),     \
				pattern_tag((DST) + 5U));                 \
			mreg[DST] = pattern_reg((DST) + 5U);              \
			mtag[DST] = pattern_tag((DST) + 5U);              \
		}                                                         \
	} while (0)

#define COMPARE_MEM_STATE()                                                \
	do {                                                               \
		cases++;                                                  \
		if (memcmp(heap, heap_exp, HEAP_BYTES) != 0) {             \
			failures++;                                       \
			return;                                           \
		}                                                         \
		cases++;                                                  \
		if (memcmp(__a64_stack.b, stk_exp, STACK_BYTES) != 0) {     \
			failures++;                                       \
			return;                                           \
		}                                                         \
	} while (0)

#define COMPARE_REG_STATE(OP, DST, BASE, INDEX, FLAGS, IMM, VIA)            \
	do {                                                               \
		unsigned __cs_i;                                          \
		for (__cs_i = 0; __cs_i < 31U; __cs_i++) {                 \
			__u64 __cs_got = ARM64_SIM_L_READ_REG(__cs_i);    \
			__u8 __cs_tag = ARM64_SIM_L_REG_TAG(__cs_i);       \
			cases++;                                          \
			if (__cs_got != mreg[__cs_i]) {                   \
				printf("MISMATCH op=%#x dst=%u base=%u "    \
				       "index=%u flags=%u imm=%lld via=%u "  \
				       "reg%u: got 0x%llx want 0x%llx\n",    \
				       (OP), (DST), (BASE), (INDEX),         \
				       (FLAGS), (long long)(IMM), (VIA),     \
				       (unsigned)__cs_i,                     \
				       (unsigned long long)__cs_got,         \
				       (unsigned long long)mreg[__cs_i]);    \
				failures++;                               \
				return;                                   \
			}                                                 \
			cases++;                                          \
			if (__cs_tag != mtag[__cs_i]) {                   \
				printf("MISMATCH op=%#x via=%u reg%u tag: "  \
				       "got %u want %u\n", (OP), (VIA),      \
				       (unsigned)__cs_i, __cs_tag,           \
				       mtag[__cs_i]);                       \
				failures++;                               \
				return;                                   \
			}                                                 \
		}                                                         \
		cases++;                                                  \
		if (__a64_sp != msp) {                                    \
			printf("MISMATCH op=%#x via=%u sp: got %lld "       \
			       "want %lld\n", (OP), (VIA),                  \
			       (long long)__a64_sp, (long long)msp);        \
			failures++;                                       \
			return;                                           \
		}                                                         \
	} while (0)

/* FLAGS carries the raw width code the dispatcher resolves; zero falls back
 * to the 64-bit default inside the dispatcher. AUX is the packed memory
 * operand byte word: PRE/POST flags at AUX [31:24] and the rotated-mod suffix
 * at AUX [15:8] and AUX [7:0], matching the checker's own restatement. */
/* Faults transfer directly to observation, preserving the complete frame
 * at the architectural fault point. Selector probes keep their counting hook. */
#undef ARM64_SIM_L_UNSUPPORTED_OPCODE
#define ARM64_SIM_L_UNSUPPORTED_OPCODE() \
    ({ arm64_sim_unsupported_opcode(); goto observe_fault; })
static void check_case(unsigned op, unsigned dst, unsigned base,
		       unsigned index, unsigned flags, __u32 aux, __s64 imm,
		       unsigned via)
{
	unsigned width = ARM64_SIM_L_EFFECTIVE_WIDTH(flags);
	unsigned long u0 = unsupported_calls;
	unsigned long mu0 = model_unsupported_calls;
	unsigned member = op == ARM64_OP_LDRSB || op == ARM64_OP_LDRSW ||
			  op == ARM64_OP_LDRSH;
	unsigned i;

	DECL_STATE();
	(void)__a64_n;
	(void)__a64_z;
	(void)__a64_c;
	(void)__a64_v;

	PLANT_STATE(dst, base, index);

	for (i = 0; i < HEAP_BYTES; i++) {
		heap[i] = heap_img[i];
		heap_exp[i] = heap_img[i];
	}
	STACK_ARENA_INIT();

	model_exec(op, dst, base, index, width, aux, imm);

	if (via)
		ARM64_SIM_L_EXEC(op, dst, base, index, ARM64_REG_NONE, flags,
				 aux, imm);
	else if (member)
		/* The direct lane replays the arm's own statement sequence,
		 * staging the load width the dispatcher installs before the
		 * body runs. */
		do {
			__u8 __a64_l_width = ARM64_SIM_L_EFFECTIVE_WIDTH(
				flags);

			ARM64_SIM_L_WRITEBACK_OVERLAP((base), (dst), (aux));
			ARM64_SIM_L_MEM_PRE((base), (aux), (imm));
			{
				__u64 __a64_l_value = ARM64_SIM_L_MEM_READ(
					(base), (index), (aux), (imm), 0,
					ARM64_SIM_L_LDRSX_LOAD_WIDTH((op)));
				__u64 __a64_l_sxop =
					ARM64_SIM_L_LDRSX_SXOP((op));

				ARM64_SIM_L_WRITE_REG_WIDTH(
					(dst),
					ARM64_SIM_L_EXTREV_SIGNEXT(
						__a64_l_sxop, __a64_l_value,
						__a64_l_width),
					__a64_l_width);
			}
			ARM64_SIM_L_MEM_POST((base), (aux), (imm));
		} while (0);
	else
		/* A non-member opcode routes to the dispatcher's unsupported
		 * arm once, like the exec lane. */
		ARM64_SIM_L_UNSUPPORTED_OPCODE();

observe_fault:
	if (member && model_unsupported_calls == mu0) {
		cases++;
		if (unsupported_calls != u0) {
			printf("MISMATCH op=%#x dst=%u base=%u index=%u "
			       "flags=%u imm=%lld aux=%#x via=%u reached "
			       "the unsupported arm\n", op, dst, base, index,
			       flags, (long long)imm, (unsigned)aux, via);
			failures++;
			return;
		}
		cases++;
		if (model_unsupported_calls != mu0) {
			printf("MISMATCH op=%#x dst=%u base=%u index=%u "
			       "flags=%u imm=%lld aux=%#x via=%u model took "
			       "an unsupported sub-contract arm\n",
			       op, dst, base, index, flags,
			       (long long)imm, (unsigned)aux, via);
			failures++;
			return;
		}
	} else {
		cases++;
		if (unsupported_calls != u0 + 1UL) {
			printf("MISMATCH op=%#x dst=%u base=%u index=%u "
			       "flags=%u imm=%lld aux=%#x via=%u unsupported "
			       "delta=%lu\n", op, dst, base, index, flags,
			       (long long)imm, (unsigned)aux, via,
			       unsupported_calls - u0);
			failures++;
			return;
		}
		cases++;
		if (model_unsupported_calls != mu0 + 1UL) {
			printf("MISMATCH op=%#x dst=%u base=%u index=%u "
			       "flags=%u imm=%lld aux=%#x via=%u model "
			       "unsupported delta=%lu\n", op, dst, base,
			       index, flags, (long long)imm, (unsigned)aux,
			       via, model_unsupported_calls - mu0);
			failures++;
			return;
		}
	}

	COMPARE_MEM_STATE();
	COMPARE_REG_STATE(op, dst, base, index, flags, imm, via);
}

#undef ARM64_SIM_L_UNSUPPORTED_OPCODE
#define ARM64_SIM_L_UNSUPPORTED_OPCODE() arm64_sim_unsupported_opcode()

/* The derived-sign-opcode selector: the generated macro must map each load
 * opcode to the SX* opcode the checker derives itself, must reach the caller
 * hook for a byte outside the family, and must not collapse two loads onto
 * one sign arm. */
static void check_selectors(void)
{
	static const unsigned load_codes[3] = {
		ARM64_OP_LDRSB, ARM64_OP_LDRSW, ARM64_OP_LDRSH,
	};
	static const unsigned want_sx[3] = {
		ARM64_OP_SXTB, ARM64_OP_SXTW, ARM64_OP_SXTH,
	};
	unsigned i;
	unsigned j;
	unsigned sx[3];

	for (i = 0; i < 3U; i++) {
		sx[i] = (unsigned)KPROG_ARM64_LDRSX_SXOP(
			load_codes[i], model_unsupported());

		cases++;
		if (sx[i] != want_sx[i]) {
			printf("MISMATCH derived sign opcode op=%#x: got %#x "
			       "want %#x\n", load_codes[i], sx[i], want_sx[i]);
			failures++;
		}
		cases++;
		if (sx[i] == load_codes[i]) {
			printf("MISMATCH derived sign opcode equals the load "
			       "opcode op=%#x\n", load_codes[i]);
			failures++;
		}
	}

	/* The three sign opcodes are pairwise distinct, so no two loads share
	 * a sign-extension arm. */
	for (i = 0; i < 3U; i++) {
		for (j = i + 1U; j < 3U; j++) {
			cases++;
			if (sx[i] == sx[j]) {
				printf("MISMATCH sign opcode collision %#x\n",
				       sx[i]);
				failures++;
			}
		}
	}
}

int main(void)
{
	static const unsigned ops[3] = {
		ARM64_OP_LDRSB, ARM64_OP_LDRSW, ARM64_OP_LDRSH,
	};
	static const unsigned dsts[4] = {
		ARM64_X3, ARM64_XZR, ARM64_SP, ARM64_X2,
	};
	static const unsigned bases[5] = {
		ARM64_X2, ARM64_X3, ARM64_X4, ARM64_X5, ARM64_SP,
	};
	static const unsigned flag_sets[4] = {
		0U, ARM64_MEM_PRE, ARM64_MEM_POST,
		ARM64_MEM_PRE | ARM64_MEM_POST,
	};
	static const unsigned indices[2] = { ARM64_REG_NONE, ARM64_X1 };
	static const __s64 imms[3] = { 0, 8, -8 };
	static const __u32 mod_suffixes[2] = { 0x00000000U, 0x00000100U };
	static const __u32 tag_suffixes[2] = { 0x00000000U, 0x000000ffU };
	unsigned lane;
	unsigned o;
	unsigned d;
	unsigned b;
	unsigned fl;
	unsigned w;
	unsigned ix;
	unsigned im;
	unsigned sf;
	unsigned tg;
	unsigned i;

	for (i = 0; i < HEAP_BYTES; i++)
		heap_img[i] = (__u8)(0x30U + i * 7U + (i >> 3));
	for (i = 0; i < STACK_BYTES; i++)
		stk_img[i] = (__u8)(0xa0U + i * 3U);
	for (i = 0; i < STACK_SLOTS; i++)
		stk_tag_img[i] = (__u8)(i % 3U);

	/* The member lattice over both replay lanes. */
	for (lane = 0; lane < 2U; lane++)
		for (o = 0; o < 3U; o++)
			for (d = 0; d < 4U; d++)
				for (b = 0; b < 5U; b++)
					for (fl = 0; fl < 4U; fl++)
						for (w = 0; w < 3U; w++)
							for (ix = 0;
							     ix < 2U;
							     ix++)
								for (im = 0;
								     im < 3U;
								     im++)
									for (
										sf = 0;
										sf < 2U;
										sf++)
										for (
											tg = 0;
											tg < 2U;
											tg++) {
			check_case(
				ops[o], dsts[d], bases[b], indices[ix],
				flag_sets[fl],
				(__u32)flag_sets[fl] << 24 |
					mod_suffixes[sf] | tag_suffixes[tg],
				imms[im], lane);
		}

	check_selectors();

	if (failures != 0) {
		printf("arm64 ldrsx route host cross-check: FAIL (%d)\n",
		       failures);
		return 1;
	}
	printf("arm64 ldrsx route host cross-check: OK (%lu cases)\n", cases);
	return 0;
}
