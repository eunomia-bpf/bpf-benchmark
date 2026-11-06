/*
 * Host cross-check for the AArch64 simulator's routing of its store helper's
 * body choice through the machine-checked store-arm contract (STEP 0123): the
 * generated `generated/arm64_mem_write_arm.h`.
 *
 * The macro under test is the real simulator macro `ARM64_SIM_L_MEM_WRITE`,
 * declared by including the real header `../arm64/arm64_sim_local_bpf.h`. The
 * helper resolves its body from the closed pair (base is the stack pointer,
 * base's resolved tag names a stack slot): either the stack arena write or the
 * plain little-endian byte store. The oracle drives the real write and checks
 * the destination the write reached *by observation*: a stack base or a
 * stack-tagged base must write the caller's stack arena and leave the pointed-to
 * heap untouched, and a scalar base must write the heap and leave the arena
 * untouched. A helper routed to the wrong destination — or to both — diverges.
 * The arena's byte image and slot-tag image are both modelled: an independent
 * model of the slot-tag rule (a qword-aligned 64-bit write tags the slot, a
 * sub-qword aligned write scalarises it, an unaligned write leaves it alone)
 * must match byte for byte.
 *
 * The write is then read back through the real load path to close the round
 * trip.
 *
 * Build and run:
 *   cd kprog/formal &&
 *   cc -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog \
 *      -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *      test_arm64_mem_write_arm_route_host.c -o build/test_arm64_mem_write_arm_route_host &&
 *   ./build/test_arm64_mem_write_arm_route_host
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

static void arm64_sim_unsupported_opcode(void)
{
}

static int failures;
static unsigned long cases;

#define HEAP_BYTES 4096U
#define BASE_OFF 2048U
#define STACK_BYTES ARM64_SIM_STACK_BYTES
#define STACK_SLOTS 20U
/* The pointed-to heap the memory arm writes; a file-scope image so a register
 * can hold its address. */
static __u8 heap[HEAP_BYTES];
static __u8 heap_model[HEAP_BYTES];

static unsigned width_bytes(unsigned width)
{
	if (width == ARM64_WIDTH_8)
		return 1;
	if (width == ARM64_WIDTH_16)
		return 2;
	if (width == ARM64_WIDTH_32)
		return 4;
	return 8;
}

/* Independent model: scatter `value & width_mask` as the width's low bytes,
 * never touching a byte above the width. */
static void model_store(__u8 *base, unsigned width, __u64 value)
{
	__u64 v = value;
	int n = width_bytes(width);
	int i;

	if (n < 8)
		v &= (1ULL << (8 * n)) - 1ULL;
	for (i = 0; i < n; i++)
		base[i] = (__u8)(v >> (8 * i));
}

/* Independent statement of the slot tag a stack write installs: a 64-bit
 * qword-aligned access tags the whole 8-byte slot, a sub-qword access at a
 * qword-aligned index drops the slot to the scalar tag, and an unaligned index
 * leaves every slot tag alone. */
static void model_stack_tag(__u8 *tags, unsigned index, unsigned width, __u8 tag)
{
	if (index % 8U != 0U)
		return;
	if (width == ARM64_WIDTH_64)
		tags[index / 8U] = tag;
	else
		tags[index / 8U] = ARM64_SIM_TAG_SCALAR;
}

static void fill_images(void)
{
	unsigned i;

	for (i = 0; i < HEAP_BYTES; i++)
		heap[i] = heap_model[i] = (__u8)(0x30U + i * 7U + (i >> 3));
}

/* ---- the three base kinds the helper resolves ---- */
#define VARIANT_SP 0         /* base is ARM64_SP: always the stack arm */
#define VARIANT_REG_TAG 1    /* base is a register tagged as a stack address */
#define VARIANT_REG_SCALAR 2 /* base is a plain scalar register */
#define VARIANT_REG_ABI 3    /* base is a register tagged with a non-stack tag */

/* Drive the real write at one (variant, index, width, value, tag) and compare
 * both whole images and the slot-tag image against the model of the arm the
 * contract names. */
static int is_stack_variant(unsigned variant)
{
	return variant == VARIANT_SP || variant == VARIANT_REG_TAG;
}

static void drive_store(unsigned variant, unsigned index, unsigned width,
			__u64 value, __u8 tag)
{
	ARM64_SIM_L_DECLARE_STATE();
	ARM64_SIM_L_DECLARE_STACK();
	__u8 b_model[STACK_BYTES];
	__u8 t_model[STACK_SLOTS];
	unsigned i;

	(void)__a64_n;
	(void)__a64_z;
	(void)__a64_c;
	(void)__a64_v;
	(void)__a64_lr;
	(void)__a64_v0;
	(void)__a64_v0_hi;

	fill_images();
	for (i = 0; i < STACK_BYTES; i++)
		__a64_stack.b[i] = b_model[i] = (__u8)(0xa0U + i * 5U + (i >> 2));
	for (i = 0; i < STACK_SLOTS; i++)
		__a64_stack_tag[i] = t_model[i] = (__u8)(0x40U + i * 3U);

	if (is_stack_variant(variant)) {
		/* Plant the base at the arena index under test and model the arena
		 * write. */
		__a64_sp = (__s64)index - ARM64_SIM_STACK_BIAS;
		ARM64_SIM_L_WRITE_REG_PTR_TAG(ARM64_X2,
			(void *)(long)((__s64)index - ARM64_SIM_STACK_BIAS),
			ARM64_SIM_TAG_STACK);
		model_store(b_model + index, width, value);
		model_stack_tag(t_model, index, width, tag);
	} else {
		/* A scalar-tagged or non-stack-tagged register aliasing the heap:
		 * both must reach the byte store and leave the arena alone. */
		ARM64_SIM_L_WRITE_REG_PTR_TAG(ARM64_X2,
			(void *)(long)(heap + BASE_OFF),
			variant == VARIANT_REG_ABI ? ARM64_SIM_TAG_ABI
						   : ARM64_SIM_TAG_SCALAR);
		model_store(heap_model + BASE_OFF, width, value);
	}

	if (variant == VARIANT_SP)
		ARM64_SIM_L_MEM_WRITE(ARM64_SP, ARM64_REG_NONE, 0U, 0, 0,
				      width, value, tag);
	else
		ARM64_SIM_L_MEM_WRITE(ARM64_X2, ARM64_REG_NONE, 0U, 0, 0,
				      width, value, tag);

	for (i = 0; i < HEAP_BYTES; i++) {
		cases++;
		if (heap[i] != heap_model[i]) {
			printf("MISMATCH variant=%u index=%u heap byte %u: "
			       "got=%02x want=%02x\n", variant, index, i,
			       heap[i], heap_model[i]);
			failures++;
			return;
		}
	}
	for (i = 0; i < STACK_BYTES; i++) {
		cases++;
		if (__a64_stack.b[i] != b_model[i]) {
			printf("MISMATCH variant=%u index=%u stack byte %u: "
			       "got=%02x want=%02x\n", variant, index, i,
			       __a64_stack.b[i], b_model[i]);
			failures++;
			return;
		}
	}
	for (i = 0; i < STACK_SLOTS; i++) {
		cases++;
		if (__a64_stack_tag[i] != t_model[i]) {
			printf("MISMATCH variant=%u index=%u slot tag %u: "
			       "got=%02x want=%02x\n", variant, index, i,
			       __a64_stack_tag[i], t_model[i]);
			failures++;
			return;
		}
	}
}

/* Store through the real write, read back through the real load: the covered
 * window must round-trip at every width on both destinations. */
static void drive_roundtrip(unsigned variant, unsigned index, unsigned width,
			    __u64 value)
{
	ARM64_SIM_L_DECLARE_STATE();
	ARM64_SIM_L_DECLARE_STACK();
	unsigned n = width_bytes(width);
	__u64 mask = n == 8 ? ~0ULL : (1ULL << (8 * n)) - 1ULL;
	__u64 got;
	(void)__a64_stack;
	(void)__a64_stack_tag;

	(void)__a64_c;
	(void)__a64_v;
	(void)__a64_lr;
	(void)__a64_v0;
	(void)__a64_v0_hi;
	(void)__a64_n;
	(void)__a64_z;
	if (is_stack_variant(variant)) {
		__a64_sp = (__s64)index - ARM64_SIM_STACK_BIAS;
		ARM64_SIM_L_WRITE_REG_PTR_TAG(ARM64_X2,
			(void *)(long)((__s64)index - ARM64_SIM_STACK_BIAS),
			ARM64_SIM_TAG_STACK);
	} else {
		ARM64_SIM_L_WRITE_REG_PTR_TAG(ARM64_X2,
			(void *)(long)(heap + BASE_OFF),
			variant == VARIANT_REG_ABI ? ARM64_SIM_TAG_ABI
						   : ARM64_SIM_TAG_SCALAR);
	}

	if (variant == VARIANT_SP) {
		ARM64_SIM_L_MEM_WRITE(ARM64_SP, ARM64_REG_NONE, 0U, 0, 0,
				      width, value, ARM64_SIM_TAG_STACK);
		got = ARM64_SIM_L_MEM_READ(ARM64_SP, ARM64_REG_NONE, 0U, 0, 0,
					   width);
	} else {
		ARM64_SIM_L_MEM_WRITE(ARM64_X2, ARM64_REG_NONE, 0U, 0, 0,
				      width, value,
				      variant == VARIANT_REG_ABI
					      ? ARM64_SIM_TAG_ABI
					      : variant == VARIANT_REG_TAG
							? ARM64_SIM_TAG_STACK
							: ARM64_SIM_TAG_SCALAR);
		got = ARM64_SIM_L_MEM_READ(ARM64_X2, ARM64_REG_NONE, 0U, 0, 0,
					   width);
	}

	cases++;
	if (got != (value & mask)) {
		printf("MISMATCH roundtrip variant=%u index=%u width=%u "
		       "value=%#llx got=%#llx want=%#llx\n", variant, index,
		       width, value, got, value & mask);
		failures++;
	}
}

/* The generated selector must name each destination at its own fact pair and
 * must be the exact disjunction an independent oracle states. */
static unsigned arm_oracle(int is_sp, unsigned tag)
{
	if (is_sp || tag == ARM64_SIM_TAG_STACK)
		return KPROG_ARM64_MEM_WRITE_ARM_STACK;
	return KPROG_ARM64_MEM_WRITE_ARM_MEMORY;
}

static void check_selector(void)
{
	static const unsigned tags[] = {
		ARM64_SIM_TAG_SCALAR, ARM64_SIM_TAG_ABI, ARM64_SIM_TAG_STACK,
		ARM64_SIM_TAG_MAP_PTR, ARM64_SIM_TAG_RELOC_ADDR, 9U, 10U,
	};
	unsigned sp, t;

	cases++;
	if (KPROG_ARM64_MEM_WRITE_ARM_COUNT != 2U ||
	    KPROG_ARM64_MEM_WRITE_ARM_STACK != 0U ||
	    KPROG_ARM64_MEM_WRITE_ARM_MEMORY != 1U) {
		printf("MISMATCH arm constant drift\n");
		failures++;
	}

	for (sp = 0U; sp < 2U; sp++)
		for (t = 0U; t < sizeof(tags) / sizeof(tags[0]); t++) {
			unsigned arm = KPROG_ARM64_MEM_WRITE_ARM(sp, tags[t]);
			unsigned want = arm_oracle((int)sp, tags[t]);

			cases++;
			if (arm != want) {
				printf("MISMATCH selector sp=%u tag=%u "
				       "arm=%u/%u\n", sp, tags[t], arm, want);
				failures++;
			}
		}
}

int main(void)
{
	static const unsigned widths[] = { ARM64_WIDTH_8, ARM64_WIDTH_16,
					   ARM64_WIDTH_32, ARM64_WIDTH_64 };
	static const unsigned indices[] = { 0U, 8U, 16U, 4U, 32U, 40U, 56U,
					    64U, 96U, 152U, 7U, 3U };
	static const __u64 patterns[] = {
		0x0000000000000000ULL,
		0xffffffffffffffffULL,
		0x0123456789abcdefULL,
		0x80c0402000100804ULL,
		0x0408102040c08001ULL,
		0xff00ff00ff00ff00ULL,
	};
	static const unsigned variants[] = { VARIANT_SP, VARIANT_REG_TAG,
					     VARIANT_REG_SCALAR, VARIANT_REG_ABI };
	__u64 state = 0x9a2f5c81e4b70d36ULL;
	unsigned v, w, ix, p, iter;

	check_selector();

	for (v = 0; v < sizeof(variants) / sizeof(variants[0]); v++)
		for (ix = 0; ix < sizeof(indices) / sizeof(indices[0]); ix++)
			for (w = 0; w < sizeof(widths) / sizeof(widths[0]); w++)
				for (p = 0;
				     p < sizeof(patterns) / sizeof(patterns[0]);
				     p++) {
					__u8 tag = variants[v] == VARIANT_REG_ABI
							   ? ARM64_SIM_TAG_ABI
							   : variants[v] ==
								     VARIANT_REG_SCALAR
								   ? ARM64_SIM_TAG_SCALAR
								   : ARM64_SIM_TAG_STACK;

					drive_store(variants[v], indices[ix],
						    widths[w], patterns[p], tag);
					drive_roundtrip(variants[v],
							indices[ix], widths[w],
							patterns[p]);
				}

	for (iter = 0; iter < 3000; iter++) {
		state = state * 6364136223846793005ULL +
			1442695040888963407ULL;
		v = iter % (sizeof(variants) / sizeof(variants[0]));
		ix = indices[iter % (sizeof(indices) / sizeof(indices[0]))];
		w = iter % 4U;
		drive_store(variants[v], ix, widths[w], state,
			    variants[v] == VARIANT_REG_ABI
				    ? ARM64_SIM_TAG_ABI
				    : variants[v] == VARIANT_REG_SCALAR
					    ? ARM64_SIM_TAG_SCALAR
					    : ARM64_SIM_TAG_STACK);
		drive_roundtrip(variants[v], ix, widths[w], state);
	}

	if (failures) {
		printf("arm64 mem write arm route host cross-check: FAIL (%d)\n",
		       failures);
		return 1;
	}
	printf("arm64 mem write arm route host cross-check: OK (%lu cases)\n",
	       cases);
	return 0;
}
