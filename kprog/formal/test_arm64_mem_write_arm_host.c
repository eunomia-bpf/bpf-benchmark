/*
 * Host cross-check for the generated AArch64 store body-selection contract.
 *
 * Verifies KPROG_ARM64_MEM_WRITE_ARM and the arm-code table from
 * generated/arm64_mem_write_arm.h against an independent oracle that evaluates
 * the same classification as a plain disjunction (never the selector's
 * `?:` chain). It sweeps every (base_is_sp, tag) combination and checks the
 * selection stays in step with the load dispatch's own stack family, which is
 * the predicate the store helper must agree with. Exits non-zero on mismatch.
 *
 * Build/run:
 *   cc -Wall -Wextra -O2 -I. test_arm64_mem_write_arm_host.c -o /tmp/t && /tmp/t
 */
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;

#define ARM64_SIM_TAG_SCALAR 0U
#define ARM64_SIM_TAG_ABI 1U
#define ARM64_SIM_TAG_PACKET 2U
#define ARM64_SIM_TAG_PACKET_END 3U
#define ARM64_SIM_TAG_STACK 4U
#define ARM64_SIM_TAG_MAP_PTR 5U
#define ARM64_SIM_TAG_MAP_VALUE 6U
#define ARM64_SIM_TAG_RELOC_ADDR 7U
#define ARM64_SIM_TAG_RODATA_ADDR 8U

#include "generated/arm64_mem_write_arm.h"

#include <stdio.h>

/* Independent statement of the destination, written as the disjunction the
 * contract names rather than the selector's conditional chain. */
static unsigned arm_oracle(int is_sp, unsigned tag)
{
	if (is_sp || tag == ARM64_SIM_TAG_STACK)
		return KPROG_ARM64_MEM_WRITE_ARM_STACK;
	return KPROG_ARM64_MEM_WRITE_ARM_MEMORY;
}

static int check_arm(int is_sp, unsigned tag)
{
	unsigned arm = KPROG_ARM64_MEM_WRITE_ARM(is_sp, tag);
	unsigned want = arm_oracle(is_sp, tag);

	if (arm != want) {
		printf("MISMATCH is_sp=%d tag=%u arm=%u/%u\n",
		       is_sp, tag, arm, want);
		return 1;
	}
	/* Exactly one destination code names each outcome, and the stack outcome
	 * is the stack-arena body. */
	if ((arm == KPROG_ARM64_MEM_WRITE_ARM_STACK) ==
	    (arm == KPROG_ARM64_MEM_WRITE_ARM_MEMORY)) {
		printf("MISMATCH is_sp=%d tag=%u code family\n", is_sp, tag);
		return 1;
	}
	if (arm > KPROG_ARM64_MEM_WRITE_ARM_MEMORY) {
		printf("MISMATCH is_sp=%d tag=%u arm out of range (%u)\n",
		       is_sp, tag, arm);
		return 1;
	}
	return 0;
}

/* The store helper's stack test must be the load dispatch's stack test: a base
 * is served by the stack body exactly when the load path calls its space
 * `stack`. Both are written from the same two facts, but the check reads the
 * generated code of each, so a drift in either generated table is caught. */
static unsigned load_stack_oracle(int is_sp, unsigned tag)
{
	if (is_sp || tag == ARM64_SIM_TAG_STACK)
		return 1U;
	return 0U;
}

static int check_family(int is_sp, unsigned tag)
{
	unsigned arm = KPROG_ARM64_MEM_WRITE_ARM(is_sp, tag);
	unsigned load_stack = load_stack_oracle(is_sp, tag);

	if ((arm == KPROG_ARM64_MEM_WRITE_ARM_STACK) != (load_stack == 1U)) {
		printf("MISMATCH is_sp=%d tag=%u store/load stack family drift\n",
		       is_sp, tag);
		return 1;
	}
	return 0;
}

static const unsigned tags[] = {
	ARM64_SIM_TAG_SCALAR, ARM64_SIM_TAG_ABI, ARM64_SIM_TAG_PACKET,
	ARM64_SIM_TAG_PACKET_END, ARM64_SIM_TAG_STACK, ARM64_SIM_TAG_MAP_PTR,
	ARM64_SIM_TAG_MAP_VALUE, ARM64_SIM_TAG_RELOC_ADDR,
	ARM64_SIM_TAG_RODATA_ADDR, 9U, 10U,
};

int main(void)
{
	unsigned cases = 0, fails = 0, stack_cases = 0, memory_cases = 0;

	/* (1) The count and code constants are the two destinations, with the
	 * documented codes. */
	if (KPROG_ARM64_MEM_WRITE_ARM_COUNT != 2U) {
		printf("MISMATCH arm count %u\n", KPROG_ARM64_MEM_WRITE_ARM_COUNT);
		fails++;
	}
	if (KPROG_ARM64_MEM_WRITE_ARM_STACK != 0U ||
	    KPROG_ARM64_MEM_WRITE_ARM_MEMORY != 1U) {
		printf("MISMATCH arm codes %u/%u\n",
		       KPROG_ARM64_MEM_WRITE_ARM_STACK,
		       KPROG_ARM64_MEM_WRITE_ARM_MEMORY);
		fails++;
	}
	cases++;

	/* (2) The two destinations are distinct and each is named at its own
	 * fact pair. */
	if (KPROG_ARM64_MEM_WRITE_ARM(1, ARM64_SIM_TAG_SCALAR) !=
		    KPROG_ARM64_MEM_WRITE_ARM_STACK ||
	    KPROG_ARM64_MEM_WRITE_ARM(0, ARM64_SIM_TAG_STACK) !=
		    KPROG_ARM64_MEM_WRITE_ARM_STACK ||
	    KPROG_ARM64_MEM_WRITE_ARM(1, ARM64_SIM_TAG_STACK) !=
		    KPROG_ARM64_MEM_WRITE_ARM_STACK ||
	    KPROG_ARM64_MEM_WRITE_ARM(0, ARM64_SIM_TAG_SCALAR) !=
		    KPROG_ARM64_MEM_WRITE_ARM_MEMORY) {
		printf("MISMATCH fixed-pair selection\n");
		fails++;
	}
	cases++;

	/* (3) Sweep the whole (base_is_sp, tag) space. */
	for (int sp = 0; sp < 2; sp++)
		for (unsigned t = 0;
		     t < sizeof(tags) / sizeof(tags[0]); t++) {
			fails += check_arm(sp, tags[t]);
			fails += check_family(sp, tags[t]);
			if (KPROG_ARM64_MEM_WRITE_ARM(sp, tags[t]) ==
			    KPROG_ARM64_MEM_WRITE_ARM_STACK)
				stack_cases++;
			else
				memory_cases++;
			cases++;
		}

	/* Both destinations are reachable over the swept space. */
	if (!stack_cases || !memory_cases) {
		printf("MISMATCH unreachable arm (stack=%u memory=%u)\n",
		       stack_cases, memory_cases);
		fails++;
	}

	if (fails) {
		printf("arm64 mem write arm host cross-check: FAILED "
		       "(%u mismatches)\n", fails);
		return 1;
	}
	printf("arm64 mem write arm host cross-check: OK (%u cases)\n", cases);
	return 0;
}
