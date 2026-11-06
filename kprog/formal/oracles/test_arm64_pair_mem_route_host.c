/*
 * Host cross-check for the AArch64 simulator's routing of the register-pair
 * memory-transfer handler bodies through the machine-checked
 * `generated/arm64_pair_mem.h` contract (STEP 0090). The bodies under test are
 * the real simulator macros `ARM64_SIM_L_LDP` and `ARM64_SIM_L_STP`, driven
 * both directly and through the `ARM64_SIM_L_EXEC` dispatcher arms.
 *
 * The contract facts this oracle exercises, each planted so a wrong selection
 * is numerically distinguishable:
 *
 *   - The access direction (`KPROG_ARM64_PAIR_MEM_OP_*_ACCESS` via
 *     `KPROG_ARM64_PAIR_MEM_INDEX(OP)`): `LDP` fills the register pair from
 *     memory, `STP` scatters it. The two directions are planted with distinct
 *     memory and register images, so swapping them shows up as a differing
 *     register value *and* a differing memory byte.
 *   - The slot count (`KPROG_ARM64_PAIR_MEM_SLOT_COUNT`): a pair move transfers
 *     two slots, the low slot at the base offset and the high slot one access
 *     width higher. A dropped or doubled slot changes the second register and
 *     the upper memory slot.
 *   - The arm index (`KPROG_ARM64_PAIR_MEM_INDEX(OP)`): the shared step selects
 *     direction from this one selector, so the oracle also checks the selector
 *     table and its totality directly.
 *
 * The second slot's byte offset is the *parameterized* access width (the
 * generated `slot offset` is the slot index scaled by the slot stride), so the
 * body honours a 32-bit `LDP` / `STP` (`__a64_l_width == ARM64_WIDTH_32`, seen
 * in the micro corpus) with a 4-byte stride rather than the 64-bit slot stride
 * of the contract's `HIGH_SLOT_STRIDE`. The oracle drives all four width codes
 * so a body that hardcoded 8 would be caught.
 *
 * Every value the body can touch is compared after each case: all 31 general
 * registers (value and provenance tag), the stack pointer, the whole 160-byte
 * stack image with its 20 slot tags, and the whole 4 KiB memory window byte for
 * byte.
 *
 * The model below is a flat, little-endian byte image with the simulator's own
 * `MEM_PRE` / `MEM_POST` writeback, staged-index arithmetic and memory-source
 * classification restated from the raw opcode and AUX word, so a misroute that
 * selects the wrong arm, direction, slot count or stride shows up as a
 * differing byte or field.
 *
 * Build and run:
 *   cd kprog/formal &&
 *   cc -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog \
 *      -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *      test_arm64_pair_mem_route_host.c -o build/test_arm64_pair_mem_route_host &&
 *   ./build/test_arm64_pair_mem_route_host
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

/* The simulator header expects this hook; the oracle drives only fully
 * supported arms, so the no-op stub is never the reason for a difference. */
static void arm64_sim_unsupported_opcode(void)
{
}

static int failures;
static unsigned long cases;

/* The register file the model tracks, kept parallel to the simulator's own
 * state so the whole file (value and tag) can be compared after every case. */
static __u64 mreg[31];
static __u8 mtag[31];
static __s64 msp;

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
 * leaving room for the driven immediates and the second slot. */
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

/* Scatter `APPLY_WIDTH(VALUE, WIDTH)` as `width` little-endian bytes. */
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

/* `ARM64_SIM_L_STACK_READ`: a 64-bit access at a qword-aligned slot reads the
 * slot as a word, every other access assembles bytes. */
static __u64 stack_read(__u32 idx, unsigned width)
{
	if (width == ARM64_WIDTH_64 && (idx & 7U) == 0U)
		return img_load(&stk_exp[idx], ARM64_WIDTH_64);
	return img_load(&stk_exp[idx], width);
}

/* `ARM64_SIM_L_STACK_READ_TAG`: the slot tag only survives a qword-aligned
 * 64-bit access; every other access is scalar. */
static __u8 stack_read_tag(__u32 idx, unsigned width)
{
	return KPROG_ARM64_STACK_TAG(width == ARM64_WIDTH_64,
				     (idx & 7U) == 0U)
		       ? stk_tag_exp[idx >> 3]
		       : ARM64_SIM_TAG_SCALAR;
}

/* `ARM64_SIM_L_STACK_WRITE_TAG`: the qword-aligned 64-bit case stores the word
 * and the slot tag; the byte case scatters `width` bytes and, at a qword
 * boundary, drops the slot tag to scalar. */
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

/* `ARM64_SIM_L_MEM_READ`, restated over the flat image. */
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

/* `ARM64_SIM_L_MEM_READ_TAG`, restated over the flat image. */
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

/* `ARM64_SIM_L_MEM_WRITE`, restated over the flat image. */
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

/* `ARM64_SIM_L_WRITE_REG_PTR_TAG`, restated against the model register file. */
static void model_write_reg_ptr_tag(unsigned reg, __u64 value, __u8 tag)
{
	if (reg != ARM64_XZR && reg != ARM64_REG_NONE) {
		mreg[reg] = value;
		mtag[reg] = tag;
	}
}

/* The shared `ARM64_SIM_L_PAIR_MEM_STEP` body, with direction, slot count and
 * slot stride restated from the generated per-opcode constants and the
 * caller's access width. */
static void model_pair(unsigned op, unsigned dst, unsigned src, unsigned src2,
		       unsigned base, unsigned index, unsigned aux, __s64 imm,
		       unsigned width)
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
			  ? model_mem_read_tag(base, index, aux, imm, hi, width)
			  : 0;
		__u64 mask = KPROG_ARM64_PAIR_LOAD_TAG_ROUTE(op, t0, t1, width,
							    arm64_sim_unsupported_opcode());

		if (KPROG_ARM64_PAIR_LOAD_TAG_ROUTE_LOW(mask))
			model_write_reg_ptr_tag(dst, v0, t0);
		else
			model_write_reg_width(dst, v0, width);
		if (KPROG_ARM64_PAIR_LOAD_TAG_ROUTE_HIGH(mask))
			model_write_reg_ptr_tag(src, v1, t1);
		else
			model_write_reg_width(src, v1, width);
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

/* ------------------------------------------------------------------ */
/* The checker.                                                        */
/* ------------------------------------------------------------------ */

/* Plant the two register files with the same pattern, and anchor the base,
 * index and source registers for the class the case drives. Written as a macro
 * so it expands in the checker's own state scope. */
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
		ARM64_SIM_L_WRITE_REG_PTR_TAG(ARM64_X16,                  \
			(void *)(long)pattern_reg(50),                    \
			pattern_tag(50));                                 \
		mreg[ARM64_X16] = pattern_reg(50);                        \
		mtag[ARM64_X16] = pattern_tag(50);                        \
		ARM64_SIM_L_WRITE_REG_PTR_TAG(ARM64_X17,                  \
			(void *)(long)pattern_reg(51),                    \
			pattern_tag(51));                                 \
		mreg[ARM64_X17] = pattern_reg(51);                        \
		mtag[ARM64_X17] = pattern_tag(51);                        \
	} while (0)

/* Compare the whole simulator state against the model image. */
#define COMPARE_STATE(OP, BASE, INDEX, FLAGS, IMM, WIDTH, VIA)             \
	do {                                                               \
		unsigned __cs_i;                                          \
		for (__cs_i = 0; __cs_i < 31U; __cs_i++) {                \
			__u64 __cs_got = ARM64_SIM_L_READ_REG(__cs_i);    \
			__u8 __cs_tag = ARM64_SIM_L_REG_TAG(__cs_i);      \
			cases++;                                          \
			if (__cs_got != mreg[__cs_i]) {                   \
				printf("MISMATCH op=%#x base=%u index=%u " \
				       "flags=%u imm=%lld width=%u via=%u " \
				       "reg%u: got 0x%llx want 0x%llx\n",  \
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
				printf("MISMATCH op=%#x via=%u reg%u tag: " \
				       "got %u want %u\n", (OP), (VIA),    \
				       (unsigned)__cs_i, __cs_tag,         \
				       mtag[__cs_i]);                      \
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
		    memcmp(__a64_stack_tag, stk_tag_exp, STACK_SLOTS) != 0) {\
			printf("MISMATCH op=%#x base=%u index=%u flags=%u " \
			       "imm=%lld width=%u via=%u memory image\n",  \
			       (OP), (BASE), (INDEX), (FLAGS),             \
			       (long long)(IMM), (WIDTH), (VIA));          \
			failures++;                                       \
			return;                                           \
		}                                                         \
	} while (0)

static void check_case(unsigned op, unsigned base, unsigned index,
		       unsigned flags, unsigned width, __s64 imm, unsigned via)
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

	/* LDP writes DST and SRC; STP reads SRC and SRC2. X16/X17 are
	 * non-overlapping with the base/index classes, so every source register
	 * carries its planted pattern. */
	ARM64_SIM_L_WRITE_REG_PTR_TAG(ARM64_X16, (void *)(long)pattern_reg(50),
				      pattern_tag(50));
	mreg[ARM64_X16] = pattern_reg(50);
	mtag[ARM64_X16] = pattern_tag(50);
	ARM64_SIM_L_WRITE_REG_PTR_TAG(ARM64_X17, (void *)(long)pattern_reg(51),
				      pattern_tag(51));
	mreg[ARM64_X17] = pattern_reg(51);
	mtag[ARM64_X17] = pattern_tag(51);

	/* ---- independent model ---- */
	model_pair(op, ARM64_X0, ARM64_X16, ARM64_X17, base, index, aux, imm,
		   width);

	/* ---- run the real body ---- */
	if (via) {
		/* The two dispatcher arms read the base register from
		 * different operands: LDP takes it as SRC2 (DST/SRC are the
		 * load destinations), STP as DST (SRC/SRC2 are the sources). */
		if (op == ARM64_OP_LDP)
			ARM64_SIM_L_EXEC(op, ARM64_X0, ARM64_X16, base,
					 index, width, aux, imm);
		else
			ARM64_SIM_L_EXEC(op, base, ARM64_X16, ARM64_X17,
					 index, width, aux, imm);
	} else {
		if (op == ARM64_OP_LDP)
			ARM64_SIM_L_LDP(ARM64_X0, ARM64_X16, base, index, aux,
					imm, width);
		else
			ARM64_SIM_L_STP(base, ARM64_X16, ARM64_X17, index, aux,
					imm, width);
	}

	COMPARE_STATE(op, base, index, flags, imm, width, via);
}

/* The routed selectors and slot constants must agree with the contract tables,
 * and the arm index must be total. */
static void check_selectors(void)
{
	static const unsigned ops[2] = { ARM64_OP_LDP, ARM64_OP_STP };
	static const unsigned idxs[2] = { KPROG_ARM64_PAIR_MEM_OP_LDP_INDEX,
					  KPROG_ARM64_PAIR_MEM_OP_STP_INDEX };
	static const unsigned accs[2] = { KPROG_ARM64_PAIR_MEM_OP_LDP_ACCESS,
					  KPROG_ARM64_PAIR_MEM_OP_STP_ACCESS };
	static const unsigned untested[4] = { 0x00U, 0x20U, 0x23U, 0xffU };
	unsigned i;

	for (i = 0; i < 2U; i++) {
		unsigned want_acc = (i == 0U) ? KPROG_ARM64_PAIR_MEM_ACCESS_LOAD
					      : KPROG_ARM64_PAIR_MEM_ACCESS_STORE;

		cases++;
		if (KPROG_ARM64_PAIR_MEM_INDEX(ops[i]) != idxs[i]) {
			printf("MISMATCH pair index op=%#x\n", ops[i]);
			failures++;
		}
		cases++;
		if (accs[i] != want_acc) {
			printf("MISMATCH pair access op=%#x\n", ops[i]);
			failures++;
		}
	}

	/* The selector is total: unlisted opcodes take the last arm. */
	for (i = 0; i < 4U; i++) {
		cases++;
		if (KPROG_ARM64_PAIR_MEM_INDEX(untested[i]) !=
				KPROG_ARM64_PAIR_MEM_OP_STP_INDEX) {
			printf("MISMATCH pair index totality op=%#x\n",
			       untested[i]);
			failures++;
		}
	}

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
	cases++;
	if (KPROG_ARM64_PAIR_MEM_HIGH_SLOT_STRIDE != ARM64_WIDTH_64) {
		printf("MISMATCH pair high slot stride\n");
		failures++;
	}
}

int main(void)
{
	static const unsigned opcodes[2] = { ARM64_OP_LDP, ARM64_OP_STP };
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
			for (b = 0; b < 5U; b++)
				for (fl = 0; fl < 4U; fl++)
					for (w = 0; w < 4U; w++)
						for (ix = 0; ix < 2U; ix++)
							for (im = 0; im < 3U; im++)
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
		printf("arm64 pair_mem route host cross-check: FAIL (%d)\n",
		       failures);
		return 1;
	}
	printf("arm64 pair_mem route host cross-check: OK (%lu cases)\n", cases);
	return 0;
}
