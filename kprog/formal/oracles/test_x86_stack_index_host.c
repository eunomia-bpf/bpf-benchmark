/*
 * Host cross-check for the x86-64 stack-index (frame-offset -> arena-index)
 * contract (generated/x86_stack_index.h from generate_x86_stack_index_spec.py).
 *
 * `X86_SIM_L_STACK_INDEX(OFF)` in `x86_sim_local_bpf.h` and the
 * `X86_SIM_L_STACK_PTR` / `X86_SIM_L_STACK_READ` / `_WRITE` helpers resolve an
 * abstract frame offset to a byte index into the fixed `X86_SIM_STACK_BYTES`
 * arena. The generator binds that map as `KPROG_X86_STACK_INDEX(OFF, CAPACITY)`.
 *
 * This oracle drives the *generated* macro and compares it, over a grid that
 * includes the frame base, the arena top, negative offsets below the base, and
 * offsets whose high 32 bits are set, against an independent restatement that
 * accumulates in unsigned 64-bit and keeps the low 32 bits. It also checks the
 * affine law / frame-base-is-zero / high-32-bit-aliasing properties the
 * refinement module proves. Exit 1 on mismatch.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. test_x86_stack_index_host.c -o /tmp/t_xsi && /tmp/t_xsi
 */
typedef unsigned char __u8;
typedef unsigned int __u32;
typedef unsigned long long __u64;
typedef long long __s64;

#include "generated/x86_stack_index.h"

#include <stdio.h>

static int failures;

static void check_index(const char *what, __u64 capacity, __s64 off,
			unsigned long want)
{
	unsigned long got = KPROG_X86_STACK_INDEX(off, capacity);

	if (got != want) {
		printf("MISMATCH %s: cap=%llu off=%lld got=%lu want=%lu\n", what,
		       capacity, off, got, want);
		failures++;
	}
}

int main(void)
{
	static const __u64 capacities[] = { 1U, 64U, 128U };
	const size_t ncaps = sizeof(capacities) / sizeof(capacities[0]);
	unsigned long cases = 0;
	size_t i;
	long delta;

	for (i = 0; i < ncaps; i++) {
		__u64 cap = capacities[i];
		__s64 base = -(__s64)cap;

		/* Frame base maps to index 0; arena top maps to capacity. */
		check_index("frame_base", cap, base, 0U);
		check_index("arena_top", cap, 0, (unsigned long)cap);
		cases += 2;

		/* Affine over the accessible frame: base + delta -> delta. */
		for (delta = 0; delta <= (long)cap; delta++) {
			unsigned long want = (unsigned long)delta;

			check_index("affine", cap, base + delta, want);
			cases++;
		}

		/* Cross-check the generated macro against the independent
		 * unsigned-64-bit low-32-bits restatement over a broad grid,
		 * including offsets below the base and offsets with the high
		 * 32 bits set. */
		for (delta = -8; delta <= (long)cap + 8; delta++) {
			__s64 off = base + delta;
			unsigned long want =
				(unsigned long)(((__u64)off + (__u64)cap) &
						0xffffffffULL);

			check_index("restate", cap, off, want);
			/* Aliasing: adding 2^32 to the offset keeps the index. */
			check_index("alias", cap, off + 0x100000000LL, want);
			cases += 2;
		}
	}

	if (failures) {
		printf("x86 stack index host cross-check: %d FAILURES\n", failures);
		return 1;
	}
	printf("x86 stack index host cross-check: OK (%lu cases)\n", cases);
	return 0;
}
