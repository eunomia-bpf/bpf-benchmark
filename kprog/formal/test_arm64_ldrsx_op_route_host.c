/*
 * Host cross-check for the AArch64 simulator's routing of the sign-extending
 * load arm through the machine-checked `generated/arm64_ldrsx_op.h` contract
 * (STEP 0128). The body under test is the real simulator dispatcher arm
 * `ARM64_SIM_L_LDRSX_HANDLED` of `ARM64_SIM_L_EXEC` in
 * `../arm64/arm64_sim_local_bpf.h`, driven through `ARM64_SIM_L_EXEC`.
 *
 * The contract fact this oracle exercises is the *derived sign-extending
 * opcode*: each load opcode selects the SX* opcode that widens the loaded value
 * into the destination (SXTB for LDRSB, SXTW for LDRSW, SXTH for LDRSH). The
 * three loads are planted at bases whose bytes give them distinct sign bits, so
 * a misrouted selection (for example LDRSW sign-extending with the byte arm)
 * changes the destination value.
 *
 * Every value the body can touch is compared after each case: all 31 general
 * registers (value and provenance tag), the stack pointer, the SIMD quarter
 * registers, the four condition flags, and the whole 4 KiB memory window and
 * 160-byte stack arena with its 20 slot tags, byte for byte.
 *
 * The model below is a flat, little-endian byte image with the simulator's own
 * `MEM_PRE` / `MEM_POST` writeback and staged-index arithmetic restated from the
 * raw opcode and AUX word. The sign extension is an independent C cast ladder
 * (`(__s8)` / `(__s16)` / `(__s32)`), never the generated mask idiom, so a
 * wrong sign position shows up as a differing destination value. The load width
 * and the sign opcode are decided from the load opcode's numeric code, never
 * the macro's switch.
 *
 * Build and run:
 *   cd kprog/formal &&
 *   cc -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog \
 *      -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *      test_arm64_ldrsx_op_route_host.c -o build/test_arm64_ldrsx_op_route_host &&
 *   ./build/test_arm64_ldrsx_op_route_host
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

/* The simulator header expects this hook. Its call count is the observable
 * that a member reached its own arm and a non-member did not. */
static unsigned long unsupported_calls;
static void arm64_sim_unsupported_opcode(void)
{
	unsupported_calls++;
}

/* The model's own unsupported hook: the derived width and sign opcode are total
 * over the family, so a member case must leave this untouched. */
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

/* The memory window the base registers point into. `heap` is the simulator's
 * backing store; `heap_exp` is the model's expected image. The two are
 * separate arrays so the simulator's writes stay observable. */
#define HEAP_BYTES 4096U
#define SCALAR_BASE_OFF 1024U
#define ABI_BASE_OFF 2048U
#define RELOC_BASE_OFF 3072U
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

/* The stack base pointer value the oracle plants: with the simulator's
 * `ARM64_SIM_STACK_BIAS` of 96, an access at offset 0 lands at arena index 32,
 * leaving room for the driven immediates and the widest load. */
#define STACK_BASE_VAL (-64LL)

/* The index register value: nonzero so the addressing mode is observable, and
 * small so every derived offset stays inside the planted windows. */
#define INDEX_VALUE 1ULL

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

/* Raw offset of an address into the simulator's memory window. */
static unsigned long heap_off(__u64 addr)
{
	return (unsigned long)(addr - (__u64)(unsigned long)heap);
}

/* Assemble `width` little-endian bytes from the model image. This is an
 * independent restatement of `KPROG_ARM64_LOAD_BYTES` for the four width
 * codes (whose numeric value is exactly the byte count). */
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

/* `ARM64_SIM_L_STACK_READ`: a 64-bit access at a qword-aligned slot reads the
 * slot as a word, every other access assembles bytes. */
static __u64 stack_read(__u32 idx, unsigned width)
{
	if (width == ARM64_WIDTH_64 && (idx & 7U) == 0U)
		return img_load(&stk_exp[idx], ARM64_WIDTH_64);
	return img_load(&stk_exp[idx], width);
}

/* The base register's value and provenance tag, as the memory macros read
 * them. */
static __u64 m_base_val(unsigned base)
{
	return base == ARM64_SP ? (__u64)msp : mreg[base];
}

static __u8 m_base_tag(unsigned base)
{
	return base == ARM64_SP ? ARM64_SIM_TAG_STACK : mtag[base];
}

/* `ARM64_SIM_L_MEM_BASE_OFF` with the source modifier the oracle drives at its
 * identity (MOD == 0), so the index register contributes its raw value. */
static __s64 model_base_off(unsigned aux, unsigned index, __s64 imm)
{
	return (__s64)KPROG_ARM64_MEM_OFFSET(
		(__u64)(ARM64_SIM_L_MEM_FLAGS(aux) &
			(ARM64_MEM_PRE | ARM64_MEM_POST)),
		index != ARM64_REG_NONE,
		(__u64)imm,
		index != ARM64_REG_NONE ? mreg[index] : 0ULL);
}

/* `ARM64_SIM_L_MEM_READ`, restated over the flat image. The sign-extending
 * load reads at its *load* width (8 / 16 / 32), so the ABI-pointer and
 * relocation arms (which require a 64-bit access) are never selected here. */
static __u64 model_mem_read(unsigned base, unsigned index, unsigned aux,
			    __s64 imm, __s64 extra, unsigned width)
{
	__s64 off = model_base_off(aux, index, imm) + extra;
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

/* `ARM64_SIM_L_MEM_PRE` / `ARM64_SIM_L_MEM_POST` writeback. */
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

/* Independent load-width oracle keyed on the load opcode's numeric code: a
 * byte load reads a byte, a halfword load a halfword, a word load a word.
 * Returns 0 for an opcode outside the family. Never the macro's switch. */
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
 * the generated `(v ^ sign) - sign` mask idiom, so a wrong sign position (or a
 * wrong width) is caught numerically. */
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

/* One dispatcher arm of `ARM64_SIM_L_EXEC`, restated over the model state:
 * the LDRSB / LDRSW / LDRSH load-sign-extend arm. `dst_width` is the
 * destination access width (the arm's `width` operand). */
static void model_exec(unsigned op, unsigned dst, unsigned src, unsigned src2,
		       unsigned dst_width, __u32 aux, __s64 imm)
{
	unsigned load_width = ldrsx_load_width(op);

	if (load_width == 0) {
		model_unsupported();
		return;
	}

	if (ARM64_SIM_L_MEM_FLAGS(aux) & ARM64_MEM_PRE)
		model_writeback(src, imm);

	{
		__u64 loaded = model_mem_read(src, src2, aux, imm, 0,
					      load_width);
		__u64 sext = model_sign_extend(load_width, loaded);

		model_write_reg_width(dst, sext, dst_width);
	}

	if (ARM64_SIM_L_MEM_FLAGS(aux) & ARM64_MEM_POST)
		model_writeback(src, imm);
}

/* ------------------------------------------------------------------ */
/* The checker.                                                        */
/* ------------------------------------------------------------------ */

/* Plant the simulator and model register files, flags, SIMD quarters and both
 * memory images with the identical pattern, and anchor the shared base, index
 * and destination registers. Written as a macro so it expands in the checker's
 * own state scope. */
#define PLANT_STATE(BASE, INDEX)                                           \
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
		if ((BASE) == ARM64_X2) {                                 \
			ARM64_SIM_L_WRITE_REG_PTR_TAG(                    \
				(BASE),                                   \
				(void *)(long)(heap + SCALAR_BASE_OFF),   \
				ARM64_SIM_TAG_SCALAR);                    \
			mreg[BASE] = (__u64)(long)(heap + SCALAR_BASE_OFF);\
			mtag[BASE] = ARM64_SIM_TAG_SCALAR;                \
		} else if ((BASE) == ARM64_X3) {                          \
			ARM64_SIM_L_WRITE_REG_PTR_TAG(                    \
				(BASE),                                   \
				(void *)(long)(heap + ABI_BASE_OFF),      \
				ARM64_SIM_TAG_ABI);                       \
			mreg[BASE] = (__u64)(long)(heap + ABI_BASE_OFF);  \
			mtag[BASE] = ARM64_SIM_TAG_ABI;                   \
		} else if ((BASE) == ARM64_X4) {                          \
			ARM64_SIM_L_WRITE_REG_PTR_TAG(                    \
				(BASE),                                   \
				(void *)(long)(heap + RELOC_BASE_OFF),    \
				ARM64_SIM_TAG_RELOC_ADDR);                \
			mreg[BASE] = (__u64)(long)(heap + RELOC_BASE_OFF);\
			mtag[BASE] = ARM64_SIM_TAG_RELOC_ADDR;            \
		} else if ((BASE) == ARM64_X5) {                          \
			ARM64_SIM_L_WRITE_REG_PTR_TAG(                    \
				(BASE), (void *)(long)STACK_BASE_VAL,     \
				ARM64_SIM_TAG_STACK);                     \
			mreg[BASE] = (__u64)STACK_BASE_VAL;               \
			mtag[BASE] = ARM64_SIM_TAG_STACK;                 \
		}                                                         \
		if ((INDEX) != ARM64_REG_NONE) {                          \
			ARM64_SIM_L_WRITE_REG_PTR_TAG((INDEX),            \
				(void *)(long)INDEX_VALUE,                \
				ARM64_SIM_TAG_SCALAR);                    \
			mreg[INDEX] = INDEX_VALUE;                        \
			mtag[INDEX] = ARM64_SIM_TAG_SCALAR;               \
		}                                                         \
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
#define COMPARE_STATE(NAME, OP, BASE, INDEX, FLAGS, IMM, WIDTH)            \
	do {                                                               \
		unsigned __cs_i;                                          \
		for (__cs_i = 0; __cs_i < 31U; __cs_i++) {                \
			__u64 __cs_got = ARM64_SIM_L_READ_REG(__cs_i);    \
			__u8 __cs_tag = ARM64_SIM_L_REG_TAG(__cs_i);      \
			cases++;                                          \
			if (__cs_got != mreg[__cs_i]) {                   \
				printf("MISMATCH %s op=%#x base=%u index=%u " \
				       "flags=%u imm=%lld width=%u reg%u: "   \
				       "got 0x%llx want 0x%llx\n", (NAME),    \
				       (OP), (BASE), (INDEX), (FLAGS),        \
				       (long long)(IMM), (WIDTH),             \
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
			printf("MISMATCH %s op=%#x base=%u index=%u flags=%u " \
			       "imm=%lld width=%u memory image\n", (NAME),   \
			       (OP), (BASE), (INDEX), (FLAGS),              \
			       (long long)(IMM), (WIDTH));                  \
			failures++;                                       \
			return;                                           \
		}                                                         \
	} while (0)

/* Drive one arm through the real dispatcher and compare the whole state to the
 * model's independent computation. `member` selects the expected unsupported
 * delta: 0 for a selected opcode (its own arm), 1 for a non-member. */
static void run_case(unsigned op, unsigned base, unsigned index, unsigned flags,
		     unsigned width, __s64 imm, int member, const char *name)
{
	__u32 aux = (__u32)flags << 24;
	unsigned long u0 = unsupported_calls;
	unsigned long mu0 = model_unsupported_calls;

	ARM64_SIM_L_DECLARE_STATE();
	ARM64_SIM_L_DECLARE_STACK();
	__u8 __a64_sim_abi_kind = KPROG_ABI_KIND_XDP;
	(void)__a64_sim_abi_kind;
	(void)__a64_lr;

	/* The destination is X0, which is never a base or index register here. */
	PLANT_STATE(base, index);

	/* ---- independent model ---- */
	model_exec(op, ARM64_X0, base, index, width, aux, imm);

	/* ---- run the real body ---- */
	ARM64_SIM_L_EXEC(op, ARM64_X0, base, index, ARM64_X3, width, aux, imm);

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

	COMPARE_STATE(name, op, base, index, flags, imm, width);
}

/* The derived sign opcode must agree with an independent oracle and must not
 * collapse the three loads onto one sign opcode. */
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

	/* The three sign opcodes are pairwise distinct, so no two loads share a
	 * sign-extension arm. */
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
	static const unsigned opcodes[3] = {
		ARM64_OP_LDRSB, ARM64_OP_LDRSW, ARM64_OP_LDRSH,
	};
	static const unsigned bases[5] = {
		ARM64_X2, ARM64_X3, ARM64_X4, ARM64_X5, ARM64_SP,
	};
	static const unsigned flag_sets[4] = {
		0U,
		ARM64_MEM_PRE,
		ARM64_MEM_POST,
		ARM64_MEM_PRE | ARM64_MEM_POST,
	};
	static const unsigned widths[4] = {
		ARM64_WIDTH_8, ARM64_WIDTH_16, ARM64_WIDTH_32, ARM64_WIDTH_64,
	};
	static const unsigned indices[2] = { ARM64_REG_NONE, ARM64_X1 };
	static const __s64 imms[3] = { 0, 8, -8 };
	unsigned o;
	unsigned b;
	unsigned fl;
	unsigned w;
	unsigned ix;
	unsigned im;
	unsigned i;

	for (i = 0; i < HEAP_BYTES; i++)
		heap_img[i] = (__u8)(0x30U + i * 7U + (i >> 3));
	for (i = 0; i < STACK_BYTES; i++)
		stk_img[i] = (__u8)(0xa0U + i * 3U);
	for (i = 0; i < STACK_SLOTS; i++)
		stk_tag_img[i] = (__u8)(i % 3U);

	for (o = 0; o < 3U; o++)
		for (b = 0; b < 5U; b++)
			for (fl = 0; fl < 4U; fl++)
				for (w = 0; w < 4U; w++)
					for (ix = 0; ix < 2U; ix++)
						for (im = 0; im < 3U; im++)
							run_case(
								opcodes[o],
								bases[b],
								indices[ix],
								flag_sets[fl],
								widths[w],
								imms[im], 1,
								"ldrsx");

	/* A non-member opcode must reach the unsupported arm exactly once and
	 * leave the state unchanged. */
	for (w = 0; w < 4U; w++)
		run_case(ARM64_OP_RET, ARM64_X2, ARM64_X1, 0U, widths[w], 0, 0,
			 "nonmember");

	check_selectors();

	if (failures != 0) {
		printf("arm64 ldrsx op route host cross-check: FAIL (%d)\n",
		       failures);
		return 1;
	}
	printf("arm64 ldrsx op route host cross-check: OK (%lu cases)\n", cases);
	return 0;
}
