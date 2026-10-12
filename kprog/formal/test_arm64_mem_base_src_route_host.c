/*
 * Route host cross-check for the AArch64 simulator's routing of its scalar
 * memory helpers' stack-arena base address through the machine-checked
 * `generated/arm64_mem_base_src.h` contract (STEP 0140). The bodies under test
 * are the real simulator macros `ARM64_SIM_L_MEM_READ`,
 * `ARM64_SIM_L_MEM_READ_TAG` and `ARM64_SIM_L_MEM_WRITE`, driven directly at
 * both base-address sources.
 *
 * The contract fact this oracle exercises, planted so a wrong selection is
 * numerically distinguishable: the base address of a stack-arena access comes
 * from the *stack pointer register* (`__a64_sp`) exactly when the base register
 * is `ARM64_SP`, and from the *base register's own arena pointer* for every
 * other base. Both sources reach the *same* stack arm, so a body that always
 * used `__a64_sp` (or always the register pointer) would read/write the wrong
 * arena slot for one of the two. The oracle plants `__a64_sp` and a
 * stack-tagged register's pointer at *distinct* arena indices with distinct
 * byte images, so a swapped or collapsed source selection shows up as a
 * differing byte.
 *
 * The product under test is the whole memory effect: the read value, the read
 * tag and the store bytes. Every byte the body can touch is compared after each
 * case: the whole 160-byte stack image with its 20 slot tags, the whole 4 KiB
 * memory window byte for byte, and the stack pointer.
 *
 * The model below restates the base-address source selection from the raw
 * `BASE == ARM64_SP` fact (never from the generated selector), the stack
 * read/tag/store over a flat byte image, and the plain little-endian byte
 * store, so a misroute that picks the wrong base shows up as a differing byte.
 *
 * Build and run:
 *   cd kprog/formal &&
 *   cc -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog \
 *      -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *      test_arm64_mem_base_src_route_host.c -o build/test_arm64_mem_base_src_route_host &&
 *   ./build/test_arm64_mem_base_src_route_host
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

ARM64_SIM_L_DECLARE_STATE();
ARM64_SIM_L_DECLARE_STACK();

/* The ABI-kind byte the tag path reads; the driven bases are the stack-pointer
 * register and a stack-tagged register, so the ABI arm is never selected. */
static __u8 __a64_sim_abi_kind = KPROG_ABI_KIND_XDP;

/* The simulator header expects this hook; the oracle drives only fully
 * supported arms, so the no-op stub is never the reason for a difference. */
static void arm64_sim_unsupported_opcode(void)
{
}

static int failures;
static unsigned long cases;

/* The model's parallel register file: the pointer value and provenance tag of
 * every general-purpose register, plus the stack pointer. */
static __u64 mreg[31];
static __u8 mtag[31];
static __s64 msp;

/* The heap window a plain scalar register aliases; `heap` is the simulator's
 * backing store, `heap_exp` the model's expected image. */
#define HEAP_BYTES 4096U
#define HEAP_BASE_OFF 1024U
static __u8 heap[HEAP_BYTES];
static __u8 heap_exp[HEAP_BYTES];

/* The stack arena image, indexed exactly as `ARM64_SIM_L_STACK_*` index it
 * (bias included). */
#define STACK_BYTES 160U
#define STACK_SLOTS 20U
/* The two base-address source values, at distinct arena indices (with the
 * simulator's `ARM64_SIM_STACK_BIAS` of 96 they land at arena indices 32 and
 * 64 and tag slots 4 and 8), so the two sources never alias. */
#define SP_BASE_VAL (-64LL)
#define REG_BASE_VAL (-32LL)

/* The two register bases the oracle drives: X5 tagged as a stack address (its
 * pointer reaches the stack arm through the gpr arena base source), X2 a plain
 * scalar aliasing the heap (its pointer reaches the byte store). */
#define REG_STACK ARM64_X5
#define REG_SCALAR ARM64_X2

static __u8 stk_exp[STACK_BYTES];
static __u8 stk_tag_exp[STACK_SLOTS];

/* Assemble `width` little-endian bytes from an image. */
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

/* `ARM64_SIM_L_STACK_READ`: a 64-bit access at a qword-aligned slot reads the
 * slot as a word, every other access assembles bytes. */
static __u64 stack_read(__u32 idx, unsigned width)
{
	return img_load(&stk_exp[idx], width);
}

/* `ARM64_SIM_L_STACK_READ_TAG`: the slot tag only survives a qword-aligned
 * 64-bit access; every other access is scalar. */
static __u8 stack_read_tag(__u32 idx, unsigned width)
{
	if (width == ARM64_WIDTH_64 && (idx & 7U) == 0U)
		return stk_tag_exp[idx >> 3];
	return ARM64_SIM_TAG_SCALAR;
}

/* `ARM64_SIM_L_STACK_WRITE_TAG`: the qword-aligned 64-bit case stores the word
 * and the slot tag; the byte case scatters `width` bytes and, at a qword
 * boundary, drops the slot tag to scalar. */
static void stack_write(__u32 idx, unsigned width, __u64 value, __u8 tag)
{
	__u64 v = KPROG_ARM64_APPLY_WIDTH(value, width);

	if (width == ARM64_WIDTH_64 && (idx & 7U) == 0U) {
		img_store(&stk_exp[idx], ARM64_WIDTH_64, v);
		stk_tag_exp[idx >> 3] = tag;
	} else {
		if ((idx & 7U) == 0U)
			stk_tag_exp[idx >> 3] = ARM64_SIM_TAG_SCALAR;
		img_store(&stk_exp[idx], width, v);
	}
}

/* The independent base-address source selection, restated from the raw
 * `BASE == ARM64_SP` fact with no reference to the generated selector: the
 * stack pointer register source yields the simulator's stack pointer, the gpr
 * arena base source yields the base register's own pointer. */
static __s64 model_base(unsigned base)
{
	return base == ARM64_SP ? msp : (__s64)mreg[base];
}

/* Plant the simulator's register file and the model's in lockstep, at both
 * base-address sources with distinct values. */
static void plant(void)
{
	unsigned i;

	for (i = 0; i < 31U; i++) {
		__u64 p = 0x30000ULL + (__u64)i * 0x40ULL;

		ARM64_SIM_L_WRITE_REG_PTR_TAG(i, (void *)(long)p,
					      ARM64_SIM_TAG_SCALAR);
		mreg[i] = p;
		mtag[i] = ARM64_SIM_TAG_SCALAR;
	}
	__a64_sp = SP_BASE_VAL;
	msp = SP_BASE_VAL;

	/* A stack-tagged register whose pointer names a different arena slot. */
	ARM64_SIM_L_WRITE_REG_PTR_TAG(REG_STACK,
				      (void *)(long)REG_BASE_VAL,
				      ARM64_SIM_TAG_STACK);
	mreg[REG_STACK] = (__u64)REG_BASE_VAL;
	mtag[REG_STACK] = ARM64_SIM_TAG_STACK;

	/* A scalar register aliasing the heap window. */
	ARM64_SIM_L_WRITE_REG_PTR_TAG(REG_SCALAR,
				      (void *)(long)(heap + HEAP_BASE_OFF),
				      ARM64_SIM_TAG_SCALAR);
	mreg[REG_SCALAR] = (__u64)(long)(heap + HEAP_BASE_OFF);
	mtag[REG_SCALAR] = ARM64_SIM_TAG_SCALAR;
}

static void fill_images(void)
{
	unsigned i;

	for (i = 0; i < HEAP_BYTES; i++)
		heap[i] = heap_exp[i] = (__u8)(0x11U + i * 13U + (i >> 2));
	for (i = 0; i < STACK_BYTES; i++)
		__a64_stack.b[i] = stk_exp[i] =
			(__u8)(0xa0U + i * 5U + (i >> 1));
	for (i = 0; i < STACK_SLOTS; i++)
		__a64_stack_tag[i] = stk_tag_exp[i] = (__u8)(0x40U + i * 3U);
}

/* Compare the whole stack image, the slot tags, the stack pointer and the heap
 * window, and report the first differing byte. */
static int compare_images(unsigned width)
{
	unsigned i;

	for (i = 0; i < STACK_BYTES; i++) {
		cases++;
		if (__a64_stack.b[i] != stk_exp[i]) {
			printf("MISMATCH width=%u stack byte %u: got=%02x "
			       "want=%02x\n", width, i, __a64_stack.b[i],
			       stk_exp[i]);
			return 1;
		}
	}
	for (i = 0; i < STACK_SLOTS; i++) {
		cases++;
		if (__a64_stack_tag[i] != stk_tag_exp[i]) {
			printf("MISMATCH width=%u slot tag %u: got=%02x "
			       "want=%02x\n", width, i, __a64_stack_tag[i],
			       stk_tag_exp[i]);
			return 1;
		}
	}
	cases++;
	if (__a64_sp != msp) {
		printf("MISMATCH width=%u sp: got=%lld want=%lld\n", width,
		       (long long)__a64_sp, (long long)msp);
		return 1;
	}
	for (i = 0; i < HEAP_BYTES; i++) {
		cases++;
		if (heap[i] != heap_exp[i]) {
			printf("MISMATCH width=%u heap byte %u: got=%02x "
			       "want=%02x\n", width, i, heap[i], heap_exp[i]);
			return 1;
		}
	}
	return 0;
}

/* Drive the real load at one base and width, and compare the value it returns
 * to the independent model of the stack-arena read at the selected base. */
static void drive_read(unsigned base, unsigned width)
{
	__s64 b = model_base(base);
	/* The access offset is zero, so the arena index is bias + base. */
	__u64 want = stack_read((__u32)(ARM64_SIM_STACK_BIAS + b), width);
	__u64 got = ARM64_SIM_L_MEM_READ(base, ARM64_REG_NONE, 0U, 0, 0, width);

	cases++;
	if (got != want) {
		printf("MISMATCH read base=%u width=%u got=%#llx "
		       "want=%#llx\n", base, width, (unsigned long long)got,
		       (unsigned long long)want);
		failures++;
	}
}

/* Drive the real tag read at one base and width. */
static void drive_read_tag(unsigned base, unsigned width)
{
	__s64 b = model_base(base);
	__u8 want = stack_read_tag((__u32)(ARM64_SIM_STACK_BIAS + b), width);
	__u8 got = ARM64_SIM_L_MEM_READ_TAG(base, ARM64_REG_NONE, 0U, 0, 0,
					    width);

	cases++;
	if (got != want) {
		printf("MISMATCH read tag base=%u width=%u got=%u "
		       "want=%u\n", base, width, got, want);
		failures++;
	}
}

/* Drive the real store at one stack-tagged base and width, and compare the
 * arena bytes and slot tags to the independent stack-write model. */
static void drive_write_stack(unsigned base, unsigned width, __u64 value,
			      __u8 tag)
{
	__s64 b = model_base(base);

	stack_write((__u32)(ARM64_SIM_STACK_BIAS + b), width, value, tag);
	ARM64_SIM_L_MEM_WRITE(base, ARM64_REG_NONE, 0U, 0, 0, width, value,
			      tag);

	if (compare_images(width))
		failures++;
}

/* Drive the real store at the scalar heap base (the memory arm, which does not
 * select a base-address source) and compare the heap window to the plain byte
 * store model. */
static void drive_write_heap(unsigned width, __u64 value)
{
	img_store(&heap_exp[HEAP_BASE_OFF], width, value);
	ARM64_SIM_L_MEM_WRITE(REG_SCALAR, ARM64_REG_NONE, 0U, 0, 0, width, value,
			      ARM64_SIM_TAG_SCALAR);

	if (compare_images(width))
		failures++;
}

/* The generated selector must name the same source the independent 2-way
 * statement names, at the raw fact the helpers compute. */
static void check_selector(void)
{
	static const unsigned regs[] = { 0U, 1U, 2U, 15U, 28U, 30U, 31U, 32U,
					 33U, 255U };
	unsigned ri;

	cases++;
	if (KPROG_ARM64_MEM_BASE_SRC_COUNT != 2U) {
		printf("MISMATCH source count got=%u want=2\n",
		       (unsigned)KPROG_ARM64_MEM_BASE_SRC_COUNT);
		failures++;
	}

	for (ri = 0; ri < sizeof(regs) / sizeof(regs[0]); ri++) {
		unsigned is_sp = (regs[ri] == ARM64_SP);
		unsigned got = KPROG_ARM64_MEM_BASE_SRC(is_sp);
		unsigned want = is_sp ? KPROG_ARM64_MEM_BASE_SRC_SP_REGISTER
				      : KPROG_ARM64_MEM_BASE_SRC_GPR_BASE;

		cases++;
		if (got != want) {
			printf("MISMATCH selector reg=%u got=%u want=%u\n",
			       regs[ri], got, want);
			failures++;
		}
	}
}

int main(void)
{
	static const unsigned widths[] = { ARM64_WIDTH_8, ARM64_WIDTH_16,
					   ARM64_WIDTH_32, ARM64_WIDTH_64 };
	static const __u64 patterns[] = {
		0x0000000000000000ULL,
		0xffffffffffffffffULL,
		0x0123456789abcdefULL,
		0xfedcba9876543210ULL,
	};
	unsigned w;
	unsigned p;

	cases++;
	if (sizeof(__a64_stack.b) != ARM64_SIM_STACK_BYTES) {
		printf("MISMATCH layout: b=%lu\n",
		       (unsigned long)sizeof(__a64_stack.b));
		failures++;
	}

	check_selector();

	for (w = 0; w < sizeof(widths) / sizeof(widths[0]); w++) {
		/* The two base-address sources of the same stack arm: the
		 * stack pointer register and the stack-tagged register. Both
		 * reach the stack arena, at distinct indices. */
		plant();
		fill_images();
		drive_read(ARM64_SP, widths[w]);
		drive_read(REG_STACK, widths[w]);
		drive_read_tag(ARM64_SP, widths[w]);
		drive_read_tag(REG_STACK, widths[w]);

		for (p = 0; p < sizeof(patterns) / sizeof(patterns[0]); p++) {
			plant();
			fill_images();
			drive_write_stack(ARM64_SP, widths[w], patterns[p],
					  ARM64_SIM_TAG_STACK);
			plant();
			fill_images();
			drive_write_stack(REG_STACK, widths[w], patterns[p],
					  ARM64_SIM_TAG_STACK);
			plant();
			fill_images();
			drive_write_heap(widths[w], patterns[p]);
		}
	}

	if (failures) {
		printf("arm64 mem base src route host cross-check: "
		       "FAIL (%d)\n", failures);
		return 1;
	}
	printf("arm64 mem base src route host cross-check: OK "
	       "(%lu cases)\n", cases);
	return 0;
}
