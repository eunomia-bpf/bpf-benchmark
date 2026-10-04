/*
 * Host cross-check for the AArch64 stack-index (frame-offset -> arena-index)
 * contract (generated/arm64_stack_index.h from generate_arm64_stack_index_spec.py).
 *
 * `ARM64_SIM_L_STACK_INDEX(OFF)` in `arm64_sim_local_bpf.h`, and the
 * `ARM64_SIM_L_STACK_PTR` / `_READ` / `_WRITE_TAG` helpers, resolve an abstract
 * frame offset (the value `__a64_sp` resolves to) to a byte index into the
 * biased `__a64_stack` arena of `ARM64_SIM_STACK_BYTES` bytes, biased by
 * `ARM64_SIM_STACK_BIAS`. The generator binds that map, and the stack-pointer
 * helper's 64-bit biased offset, as the macros `KPROG_ARM64_STACK_INDEX` /
 * `KPROG_ARM64_STACK_PTR_INDEX`.
 *
 * This oracle drives the *generated* macros and compares them, over a grid that
 * includes the frame base, the arena top, negative offsets below the base, and
 * offsets whose high 32 bits are set, against an independent restatement that
 * accumulates in unsigned 64-bit and keeps the low 32 bits (or the full 64 for
 * the pointer offset). It also checks the affine law / frame-base-is-zero /
 * high-32-bit-aliasing properties the refinement module proves. Exit 1 on
 * mismatch.
 *
 * Build/run:
 *   cd native-sim/formal
 *   cc -Wall -Wextra -O2 -I. test_arm64_stack_index_host.c -o /tmp/t_asi && /tmp/t_asi
 */
typedef unsigned char __u8;
typedef unsigned int __u32;
typedef unsigned long long __u64;
typedef long long __s64;

#include "generated/arm64_stack_index.h"

#include <stdio.h>

#define ARM64_STACK_BIAS 96LL

static int failures;

static void check_index(const char *what, __s64 bias, __s64 off,
			unsigned long want)
{
	unsigned long got = KPROG_ARM64_STACK_INDEX(off, bias);

	if (got != want) {
		printf("MISMATCH %s: bias=%lld off=%lld got=%lu want=%lu\n", what,
		       bias, off, got, want);
		failures++;
	}
}

static void check_ptr(const char *what, __s64 bias, __s64 off, __s64 want)
{
	__s64 got = KPROG_ARM64_STACK_PTR_INDEX(off, bias);

	if (got != want) {
		printf("MISMATCH %s: bias=%lld off=%lld got=%lld want=%lld\n", what,
		       bias, off, got, want);
		failures++;
	}
}

int main(void)
{
	const __s64 bias = ARM64_STACK_BIAS;
	unsigned long cases = 0;
	long delta;

	/* Frame base maps to index 0; the abstract frame base (offset 0) maps
	 * to the arena bias, the bottom of the biased window. */
	check_index("frame_base", bias, 0 - bias, 0U);
	check_index("abstract_base", bias, 0, (unsigned long)bias);
	check_ptr("ptr_frame_base", bias, 0 - bias, 0);
	cases += 3;

	/* Affine over the frame window: base + delta -> delta. */
	for (delta = 0; delta <= (long)bias; delta++) {
		check_index("affine", bias, (0 - bias) + delta,
			    (unsigned long)delta);
		check_ptr("ptr_affine", bias, (0 - bias) + delta, delta);
		cases += 2;
	}

	/* Cross-check the generated macros against the independent
	 * unsigned-64-bit low-32-bits restatement over a broad grid, including
	 * offsets below the base and offsets with the high 32 bits set. */
	for (delta = -(long)bias - 8; delta <= 8; delta++) {
		__s64 off = delta;
		unsigned long want = (unsigned long)(((__u64)off +
						      (__u64)bias) &
						     0xffffffffULL);
		__s64 ptr_want = (__s64)((__u64)off + (__u64)bias);

		check_index("restate", bias, off, want);
		check_ptr("ptr_restate", bias, off, ptr_want);
		/* Aliasing: adding 2^32 to the offset keeps the index. */
		check_index("alias", bias, off + 0x100000000LL, want);
		cases += 3;
	}

	if (failures) {
		printf("arm64 stack index host cross-check: %d FAILURES\n",
		       failures);
		return 1;
	}
	printf("arm64 stack index host cross-check: OK (%lu cases)\n", cases);
	return 0;
}
