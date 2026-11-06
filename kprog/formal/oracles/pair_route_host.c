/*
 * Step 0449 battery-local route oracle: drives the real AArch64 pair-move
 * (`LDP` / `STP`) arms of `ARM64_SIM_L_EXEC`, both through the dispatcher
 * arms and through the direct `ARM64_SIM_L_LDP` / `ARM64_SIM_L_STP` aliases,
 * against an independent flat-image model of the memory ladder the pair body
 * routes through (`MEM_PRE` -> `MEM_READ` + `MEM_READ_TAG` /
 * `MEM_WRITE` -> `MEM_POST`) restated over the flat little-endian images.
 *
 * Unlike the Step 0090 `test_arm64_pair_mem_route_host.c` (which pins the
 * direction/slot-count/stride selectors with its own model), this oracle
 * paints the pair-body's own line paragraphs: the LDP low-slot writeback
 * lane going to DST and the high slot to SRC through
 * `KPROG_ARM64_PAIR_LOAD_TAG_ROUTE`'s two-bit mask (tag-copy PTR_TAG write
 * versus tag-dropping width write), the STP lane going SRC then SRC2 out at
 * slot offsets 0 and the access width, pre/post writeback deltas of the base
 * register (SP and GPR both), and the totality of the pair selector on
 * unlisted opcodes. Scenes drive all four width codes x 3 bases (the
 * stack-pointer base, the scalar GPR base, and the ABI-tagged GPR base) x
 * both flag byte variants (offset/pre+post) x 3 indices x 6 immediates: a
 * swapped or dropped slot lane, a swapped LOAD_TAG_ROUTE accessor, a
 * dropped pre/post delta, a 64-bit-hardcoded high offset, a wrong slot
 * order, or a width-narrowing paint on either slot write shows up as a
 * register, memory-image, or tag difference. Oracle unsupported opcodes are
 * counted through the caller hook.
 *
 * Build and run:
 *   cd kprog/formal &&
 *   cc -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog \
 *      -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *      build/pair_route_host.c -o build/mut_pairroute &&
 *   ./build/mut_pairroute
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

static unsigned long unsupported_calls;
static void arm64_sim_unsupported_opcode(void)
{
	unsupported_calls++;
}

static int failures;
static unsigned long cases;

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

#define SEED_GPR_ONE(REG, NAME) \
	do { \
		__a64_##NAME.ptr = (void *)(long)(0x9e3779b97f4a7c15ULL * ((REG) + 1U)); \
		__a64_##NAME##_tag = ARM64_SIM_TAG_SCALAR; \
	} while (0);
#define SEED_GPRS() ARM64_SIM_L_FOR_EACH_GPR(SEED_GPR_ONE)

#define SEED_FLAGS() \
	do { \
		__a64_n = 1; \
		__a64_z = 0; \
		__a64_c = 1; \
		__a64_v = 0; \
	} while (0)

/* ------------------------------------------------------------ */
/* Independent flat-image memory model (own ladder restatement). */
/* ------------------------------------------------------------ */
#define HEAP_BYTES 4096U
#define SCALAR_BASE_OFF 1024U
#define ABI_BASE_OFF 2048U
static __u8 heap[HEAP_BYTES];
static __u8 heap_exp[HEAP_BYTES];
static __u8 heap_img[HEAP_BYTES];

#define STACK_BYTES 160U
#define STACK_SLOTS 20U
static __u8 stk_exp[STACK_BYTES];
static __u8 stk_tag_exp[STACK_SLOTS];
static __u8 stk_img[STACK_BYTES];
static __u8 stk_tag_img[STACK_SLOTS];

#define STACK_BASE_VAL (-64LL)
#define INDEX_VALUE 1ULL

/* model register file kept parallel to the simulator's */
static __u64 mreg[31];
static __u8 mtag[31];
static __s64 msp;

static __u64 pattern_reg(unsigned i)
{
	return 0x9e3779b97f4a7c15ULL * (__u64)(i + 1U) +
	       0x0123456789abcdefULL;
}

static __u8 pattern_tag(unsigned i)
{
	return (__u8)(1U + (i % 5U));
}

static unsigned long heap_off(__u64 addr)
{
	return (unsigned long)(addr - (__u64)(unsigned long)heap);
}

static __u64 img_load(const __u8 *base, unsigned width)
{
	__u64 v = 0;
	unsigned i;
	unsigned n = width == ARM64_WIDTH_64 ? 8U :
		     width == ARM64_WIDTH_32 ? 4U :
		     width == ARM64_WIDTH_16 ? 2U : 1U;

	for (i = 0; i < n; i++)
		v |= (__u64)base[i] << (8U * i);
	return v;
}

static void img_store(__u8 *base, unsigned width, __u64 value)
{
	__u64 v = KPROG_ARM64_APPLY_WIDTH(value, width);
	unsigned i;

	for (i = 0; i < width; i++)
		base[i] = (__u8)(v >> (8U * i));
}

static __u64 heap_read(__u64 addr, unsigned width)
{
	return img_load(&heap_exp[heap_off(addr)], width);
}

static void heap_write(__u64 addr, unsigned width, __u64 value)
{
	img_store(&heap_exp[heap_off(addr)], width, value);
}

/* The stack helpers' own arm: word read at a qword-aligned 64-bit width,
 * byte ladder otherwise; write stores the word and the slot tag at the word
 * case and scatters bytes at every other one (clearing the tag at a
 * boundary). */
static __u64 stack_read(__u32 idx, unsigned width)
{
	if (width == ARM64_WIDTH_64 && (idx & 7U) == 0U)
		return img_load(&stk_exp[idx], ARM64_WIDTH_64);
	return img_load(&stk_exp[idx], width);
}

static __u8 stack_read_tag(__u32 idx, unsigned width)
{
	return KPROG_ARM64_STACK_TAG(width == ARM64_WIDTH_64,
				     (idx & 7U) == 0U)
		       ? stk_tag_exp[idx >> 3]
		       : ARM64_SIM_TAG_SCALAR;
}

static void stack_write(__u32 idx, unsigned width, __u64 value, __u8 tag)
{
	__u64 v = KPROG_ARM64_APPLY_WIDTH(value, width);

	if (KPROG_ARM64_STACK_TAG(width == ARM64_WIDTH_64, (idx & 7U) == 0U)) {
		img_store(&stk_exp[idx], ARM64_WIDTH_64, v);
		stk_tag_exp[idx >> 3] = tag;
	} else {
		if ((idx & 7U) == 0U)
			stk_tag_exp[idx >> 3] = ARM64_SIM_TAG_SCALAR;
		img_store(&stk_exp[idx], width, v);
	}
}

static __u64 m_base_val(unsigned base)
{
	return base == ARM64_SP ? (__u64)msp : mreg[base];
}

static __u8 m_base_tag(unsigned base)
{
	return base == ARM64_SP ? ARM64_SIM_TAG_STACK : mtag[base];
}

/* The offset ladder: pre/post access suppresses the immediate here and
 * applies it as its own writeback; the index register contributes through
 * the identity modifier at width 64. */
static __s64 model_base_off(unsigned aux, unsigned index, __s64 imm)
{
	return (__s64)KPROG_ARM64_MEM_OFFSET(
		(__u64)(ARM64_SIM_L_MEM_FLAGS(aux) &
			(ARM64_MEM_PRE | ARM64_MEM_POST)),
		KPROG_ARM64_MEM_INDEX_PRESENT(index),
		(__u64)imm,
		index != ARM64_REG_NONE ? mreg[index] : 0ULL);
}

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

static __u8 model_mem_read_tag(unsigned base, unsigned index, unsigned aux,
			       __s64 imm, __s64 extra, unsigned width)
{
	__s64 off = model_base_off(aux, index, imm) + extra;
	__u8 tag = m_base_tag(base);
	__u8 src = KPROG_ARM64_MEM_READ_TAG(base == ARM64_SP, tag, width);

	if (src == KPROG_ARM64_MEM_TAG_STACK)
		return stack_read_tag((__u32)(ARM64_SIM_STACK_BIAS +
					      ((__s64)m_base_val(base) + off)),
				      width);
	if (src == KPROG_ARM64_MEM_TAG_ABI)
		return KPROG_ABI_LOAD_TAG(KPROG_ABI_KIND_XDP, off,
					  ARM64_SIM_TAG_SCALAR,
					  ARM64_SIM_TAG_PACKET,
					  ARM64_SIM_TAG_PACKET_END);
	if (src == KPROG_ARM64_MEM_TAG_MAP_PTR)
		return ARM64_SIM_TAG_MAP_PTR;
	return ARM64_SIM_TAG_SCALAR;
}

static void model_mem_write(unsigned base, unsigned index, unsigned aux,
			    __s64 imm, __s64 extra, unsigned width,
			    __u64 value, __u8 tag)
{
	__s64 off = model_base_off(aux, index, imm) + extra;
	__u8 t = m_base_tag(base);
	if (base == ARM64_SP || t == ARM64_SIM_TAG_STACK) {
		__s64 b = (__s64)m_base_val(base);

		stack_write((__u32)(ARM64_SIM_STACK_BIAS + (b + off)), width,
			    value, tag);
	} else {
		heap_write(m_base_val(base) + (__u64)off, width, value);
	}
}

static void model_writeback(unsigned base, __s64 imm)
{
	if (base == ARM64_SP)
		msp += imm;
	else
		mreg[base] = mreg[base] + (__u64)imm;
}

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

static void model_write_reg_ptr_tag(unsigned reg, __u64 value, __u8 tag)
{
	if (reg != ARM64_XZR && reg != ARM64_REG_NONE) {
		mreg[reg] = value;
		mtag[reg] = tag;
	}
}

static void model_write_reg(unsigned scalar, unsigned reg, __u64 value,
			    __u8 tag)
{
	if (scalar)
		model_write_reg_width(reg, value, ARM64_WIDTH_64);
	else
		model_write_reg_ptr_tag(reg, value, tag);
}

/* The shared `ARM64_SIM_L_PAIR_MEM_STEP` body, restated. */
static void model_pair(unsigned op, unsigned dst, unsigned src,
		       unsigned src2, unsigned base, unsigned index,
		       unsigned aux, __s64 imm, unsigned width)
{
	unsigned access = KPROG_ARM64_PAIR_MEM_INDEX(op) ==
				  KPROG_ARM64_PAIR_MEM_OP_LDP_INDEX
			  ? KPROG_ARM64_PAIR_MEM_OP_LDP_ACCESS
			  : KPROG_ARM64_PAIR_MEM_OP_STP_ACCESS;
	unsigned slots = KPROG_ARM64_PAIR_MEM_SLOT_COUNT;
	unsigned hi = width;

	if (ARM64_SIM_L_MEM_FLAGS(aux) & ARM64_MEM_PRE)
		model_writeback(base, imm);

	if (access == KPROG_ARM64_PAIR_MEM_ACCESS_LOAD) {
		__u64 v0 = model_mem_read(base, index, aux, imm, 0, width);
		__u64 v1 = slots > 1U
			   ? model_mem_read(base, index, aux, imm, hi, width)
			   : 0;
		__u8 t0 = model_mem_read_tag(base, index, aux, imm, 0, width);
		__u8 t1 = slots > 1U
			  ? model_mem_read_tag(base, index, aux, imm, hi,
					       width)
			  : 0;
		__u8 lo_scalar = !KPROG_ARM64_PAIR_LOAD_TAG_ROUTE_LOW(
			KPROG_ARM64_PAIR_LOAD_TAG_ROUTE(op, t0, t1, width,
				arm64_sim_unsupported_opcode()));
		__u8 hi_scalar = !KPROG_ARM64_PAIR_LOAD_TAG_ROUTE_HIGH(
			KPROG_ARM64_PAIR_LOAD_TAG_ROUTE(
				op, ARM64_SIM_TAG_SCALAR, t1, width,
				arm64_sim_unsupported_opcode()));
		model_write_reg(lo_scalar ? 1U : 0U, dst, v0, t0);
		model_write_reg(hi_scalar ? 1U : 0U, src, v1, t1);
	} else {
		model_mem_write(base, index, aux, imm, 0, width,
				m_base_val(src), m_base_tag(src));
		if (slots > 1U)
			model_mem_write(base, index, aux, imm, hi, width,
					m_base_val(src2), m_base_tag(src2));
	}

	if (ARM64_SIM_L_MEM_FLAGS(aux) & ARM64_MEM_POST)
		model_writeback(base, imm);
}

/* ------------------------------------------------------------ */
/* The checker.                                                  */
/* ------------------------------------------------------------ */
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
		}                                                         \
		if ((INDEX) != ARM64_REG_NONE) {                          \
			ARM64_SIM_L_WRITE_REG_PTR_TAG((INDEX),            \
				(void *)(long)INDEX_VALUE,                \
				ARM64_SIM_TAG_SCALAR);                    \
			mreg[INDEX] = INDEX_VALUE;                        \
			mtag[INDEX] = ARM64_SIM_TAG_SCALAR;               \
		}                                                         \
	} while (0)

#define COMPARE_STATE(OP, BASE, INDEX, FLAGS, IMM, WIDTH, VIA)              \
	do {                                                               \
		unsigned __cs_i;                                          \
		for (__cs_i = 0; __cs_i < 31U; __cs_i++) {                \
			__u64 __cs_got = ARM64_SIM_L_READ_REG(__cs_i);    \
			__u8 __cs_tag = ARM64_SIM_L_REG_TAG(__cs_i);      \
			cases++;                                          \
			if (__cs_got != mreg[__cs_i]) {                   \
				printf("MISMATCH op=%#x base=%u idx=%u "  \
				       "flags=%u imm=%lld width=%u "      \
				       "via=%u reg%u: got 0x%llx "        \
				       "want 0x%llx\n",                   \
				       (OP), (BASE), (INDEX), (FLAGS),     \
				       (long long)(IMM), (WIDTH), (VIA),   \
				       (unsigned)__cs_i,                   \
				       (unsigned long long)__cs_got,       \
				       (unsigned long long)mreg[__cs_i]);  \
				failures++;                               \
				return;                                   \
			}                                                 \
			cases++;                                          \
			if (__cs_tag != mtag[__cs_i]) {                   \
				printf("MISMATCH op=%#x via=%u reg%u "    \
				       "tag: got %u want %u\n",           \
				       (OP), (VIA), (unsigned)__cs_i,     \
				       __cs_tag, mtag[__cs_i]);           \
				failures++;                               \
				return;                                   \
			}                                                 \
		}                                                         \
		cases++;                                                  \
		if (__a64_sp != msp) {                                    \
			printf("MISMATCH op=%#x via=%u sp: got %lld "     \
			       "want %lld\n", (OP), (VIA),                 \
			       (long long)__a64_sp, (long long)msp);       \
			failures++;                                       \
			return;                                           \
		}                                                         \
		cases++;                                                  \
		if (memcmp(heap, heap_exp, HEAP_BYTES) != 0 ||            \
		    memcmp(__a64_stack.b, stk_exp, STACK_BYTES) != 0 ||   \
		    memcmp(__a64_stack_tag, stk_tag_exp,                  \
			   STACK_SLOTS) != 0) {                           \
			printf("MISMATCH op=%#x base=%u idx=%u flags=%u " \
			       "imm=%lld width=%u via=%u memory image\n", \
			       (OP), (BASE), (INDEX), (FLAGS),             \
			       (long long)(IMM), (WIDTH), (VIA));          \
			failures++;                                       \
			return;                                           \
		}                                                         \
	} while (0)

static void check_case(unsigned op, unsigned base, unsigned index,
		       unsigned flags, unsigned width, __s64 imm,
		       unsigned via)
{
	__u32 aux = (__u32)flags << 24;
	unsigned i;

	ARM64_SIM_L_DECLARE_STATE();
	ARM64_SIM_L_DECLARE_STACK();
	__u8 __a64_sim_abi_kind = KPROG_ABI_KIND_XDP;
	(void)__a64_sim_abi_kind;
	(void)__a64_n;
	(void)__a64_z;
	(void)__a64_c;
	(void)__a64_v;
	(void)__a64_lr;

	PLANT_STATE(base, index);

	for (i = 0; i < HEAP_BYTES; i++) {
		heap[i] = heap_img[i];
		heap_exp[i] = heap_img[i];
	}
	for (i = 0; i < STACK_BYTES; i++) {
		__a64_stack.b[i] = stk_img[i];
		stk_exp[i] = stk_img[i];
	}
	for (i = 0; i < STACK_SLOTS; i++) {
		__a64_stack_tag[i] = stk_tag_img[i];
		stk_tag_exp[i] = stk_tag_img[i];
	}

	/* The route arms read/writes the base with pre/post-indexed deltas and
	 * the low slot with the 0-slot access, all tied to the planted images.
	 * x0/x16/x17 stay non-overlapping with the base class. */
	ARM64_SIM_L_WRITE_REG_PTR_TAG(ARM64_X16, (void *)(long)pattern_reg(50),
				      pattern_tag(50));
	mreg[ARM64_X16] = pattern_reg(50);
	mtag[ARM64_X16] = pattern_tag(50);
	ARM64_SIM_L_WRITE_REG_PTR_TAG(ARM64_X17, (void *)(long)pattern_reg(51),
				      pattern_tag(51));
	mreg[ARM64_X17] = pattern_reg(51);
	mtag[ARM64_X17] = pattern_tag(51);

	model_pair(op, ARM64_X0, ARM64_X16, ARM64_X17, base, index, aux, imm,
		   width);

	/* The dispatcher arms route the base through SRC2 for LDP and DST for
	 * STP; the direct aliases carry the same lane plan (DST/SRC for LDP,
	 * SRC/SRC2 for STP). */
	if (via) {
		if (op == ARM64_OP_LDP)
			ARM64_SIM_L_EXEC(op, ARM64_X0, ARM64_X16, base,
					 index, width, aux, imm);
		else
			ARM64_SIM_L_EXEC(op, base, ARM64_X16, ARM64_X17,
					 index, width, aux, imm);
	} else {
		if (op == ARM64_OP_LDP)
			ARM64_SIM_L_LDP(ARM64_X0, ARM64_X16, base, index,
					aux, imm, width);
		else
			ARM64_SIM_L_STP(base, ARM64_X16, ARM64_X17, index,
					aux, imm, width);
	}

	COMPARE_STATE(op, base, index, flags, imm, width, via);
}

/* Totality of the pair selector over unlisted opcodes: the STP arm. */
static void check_selectors(void)
{
	static const unsigned untested[4] = { 0x00U, 0x20U, 0x23U, 0xffU };
	unsigned i;

	for (i = 0; i < 4U; i++) {
		cases++;
		if (KPROG_ARM64_PAIR_MEM_INDEX(untested[i]) !=
				KPROG_ARM64_PAIR_MEM_OP_STP_INDEX) {
			printf("MISMATCH pair index totality op=%#x\n",
			       untested[i]);
			failures++;
		}
	}

	/* The LOAD_TAG_ROUTE caller-hook wiring: an unknown opcode reaches the
	 * hook through this alias too. */
	{
		unsigned long before = unsupported_calls;

		cases++;
		(void)ARM64_SIM_L_PAIR_LOAD_TAG_ROUTE(7U,
			ARM64_SIM_TAG_SCALAR, ARM64_SIM_TAG_SCALAR,
			ARM64_WIDTH_64);
		if (unsupported_calls == before) {
			printf("MISMATCH pair load tag unsupported missing\n");
			failures++;
		}
	}

	/* Slot plan: the contract's two-slot plan at both the LDP and STP
	 * codes, with the high slot following at one access width. */
	cases++;
	if (KPROG_ARM64_PAIR_MEM_SLOT_COUNT != 2U) {
		printf("MISMATCH pair slot count\n");
		failures++;
	}
	cases++;
	if (KPROG_ARM64_PAIR_MEM_SLOT_STRIDE != ARM64_WIDTH_64) {
		printf("MISMATCH pair slot stride\n");
		failures++;
	}
}

int main(void)
{
	static const unsigned opcodes[2] = { ARM64_OP_LDP, ARM64_OP_STP };
	static const unsigned bases[3] = { ARM64_X2, ARM64_X3, ARM64_SP };
	static const unsigned flag_sets[3] = {
		0U,
		ARM64_MEM_PRE,
		ARM64_MEM_PRE | ARM64_MEM_POST,
	};
	static const unsigned widths[4] = {
		ARM64_WIDTH_8, ARM64_WIDTH_16, ARM64_WIDTH_32, ARM64_WIDTH_64,
	};
	static const unsigned indices[3] = { ARM64_REG_NONE, ARM64_X1,
					     ARM64_X6 };
	static const __s64 imms[6] = { 0, 8, -8, 4, 16, -4 };
	unsigned via;
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

	for (via = 0; via < 2U; via++)
		for (o = 0; o < 2U; o++)
			for (b = 0; b < 3U; b++)
				for (fl = 0; fl < 3U; fl++)
					for (w = 0; w < 4U; w++)
						for (ix = 0; ix < 3U; ix++)
							for (im = 0; im < 6U;
							     im++)
								check_case(
									opcodes[o],
									bases[b],
									indices[ix],
									flag_sets[fl],
									widths[w],
									imms[im],
									via);

	check_selectors();

	if (failures != 0) {
		printf("arm64 pair route host cross-check: FAIL (%d)\n",
		       failures);
		return 1;
	}
	printf("arm64 pair route host cross-check: OK (%lu cases)\n", cases);
	return 0;
}
