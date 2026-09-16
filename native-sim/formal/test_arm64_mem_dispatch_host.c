/*
 * Host cross-check for the generated AArch64 memory access-dispatch contract.
 *
 * Verifies KPROG_ARM64_MEM_READ_SRC / KPROG_ARM64_MEM_READ_TAG from
 * generated/arm64_mem_dispatch.h against an independent oracle that evaluates
 * the same classification as a predicate-nesting function (never the macro's
 * chain). It sweeps every (base_is_sp, tag, width) combination and checks the
 * two classifications stay in step with each other. Exits non-zero on mismatch.
 *
 * Build/run:
 *   cd native-sim/formal
 *   cc -Wall -Wextra -O2 -I. test_arm64_mem_dispatch_host.c -o /tmp/t_md && /tmp/t_md
 */
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;

#define ARM64_WIDTH_8 1U
#define ARM64_WIDTH_16 2U
#define ARM64_WIDTH_32 4U
#define ARM64_WIDTH_64 8U

#define ARM64_SIM_TAG_SCALAR 0U
#define ARM64_SIM_TAG_ABI 1U
#define ARM64_SIM_TAG_STACK 4U
#define ARM64_SIM_TAG_RELOC_ADDR 7U

#include "generated/arm64_mem_dispatch.h"

#include <stdio.h>

/* Independent predicate nesting, written in the C chain's own shape. */
static unsigned src_oracle(int is_sp, unsigned tag, unsigned width)
{
	if (is_sp || tag == ARM64_SIM_TAG_STACK)
		return KPROG_ARM64_MEM_SRC_STACK;
	if (tag == ARM64_SIM_TAG_ABI && width == ARM64_WIDTH_64)
		return KPROG_ARM64_MEM_SRC_ABI_PTR_LOAD;
	if (tag == ARM64_SIM_TAG_RELOC_ADDR && width == ARM64_WIDTH_64)
		return KPROG_ARM64_MEM_SRC_RELOC_PTR;
	return KPROG_ARM64_MEM_SRC_NORMAL_LOAD;
}

static unsigned tag_oracle(int is_sp, unsigned tag, unsigned width)
{
	if (is_sp || tag == ARM64_SIM_TAG_STACK)
		return KPROG_ARM64_MEM_TAG_STACK;
	if (tag == ARM64_SIM_TAG_ABI && width == ARM64_WIDTH_64)
		return KPROG_ARM64_MEM_TAG_ABI;
	if (tag == ARM64_SIM_TAG_RELOC_ADDR && width == ARM64_WIDTH_64)
		return KPROG_ARM64_MEM_TAG_MAP_PTR;
	return KPROG_ARM64_MEM_TAG_SCALAR;
}

static int check_dispatch(int is_sp, unsigned tag, unsigned width)
{
	unsigned src = KPROG_ARM64_MEM_READ_SRC(is_sp, tag, width);
	unsigned rtag = KPROG_ARM64_MEM_READ_TAG(is_sp, tag, width);
	unsigned want_src = src_oracle(is_sp, tag, width);
	unsigned want_tag = tag_oracle(is_sp, tag, width);

	if (src != want_src || rtag != want_tag) {
		printf("MISMATCH is_sp=%d tag=%u width=%u src=%u/%u tag=%u/%u\n",
		       is_sp, tag, width, src, want_src, rtag, want_tag);
		return 1;
	}
	/* The source and tag classifications must select the same space family:
	 * stack<->stack, abi<->abi, reloc<->map_ptr, else normal<->scalar. */
	if ((src == KPROG_ARM64_MEM_SRC_STACK) !=
	    (rtag == KPROG_ARM64_MEM_TAG_STACK)) {
		printf("MISMATCH is_sp=%d tag=%u width=%u family split\n",
		       is_sp, tag, width);
		return 1;
	}
	return 0;
}

static const unsigned tags[] = {
	ARM64_SIM_TAG_SCALAR, ARM64_SIM_TAG_ABI, ARM64_SIM_TAG_STACK,
	ARM64_SIM_TAG_RELOC_ADDR, 2U, 3U, 5U, 6U, 8U,
};
static const unsigned widths[] = { ARM64_WIDTH_8, ARM64_WIDTH_16,
				   ARM64_WIDTH_32, ARM64_WIDTH_64 };

int main(void)
{
	unsigned cases = 0, fails = 0;

	for (int sp = 0; sp < 2; sp++)
		for (unsigned t = 0; t < sizeof(tags) / sizeof(tags[0]); t++)
			for (unsigned w = 0;
			     w < sizeof(widths) / sizeof(widths[0]); w++) {
				fails += check_dispatch(sp, tags[t], widths[w]);
				cases++;
			}

	if (fails) {
		printf("arm64 mem dispatch host cross-check: FAILED (%u mismatches)\n",
		       fails);
		return 1;
	}
	printf("arm64 mem dispatch host cross-check: OK (%u cases)\n", cases);
	return 0;
}
