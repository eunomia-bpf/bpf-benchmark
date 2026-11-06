/*
 * Host cross-check for the x86 simulator's routing of the stack
 * word-path/byte-ladder body-selection contract (STEP 0120).
 *
 * The simulator's `X86_SIM_L_STACK_WRITE` and `X86_SIM_L_STACK_READ` helpers
 * must now select *which body* moves the stack word/bytes through the generated
 * `KPROG_X86_STACK_ARM` two-fact selector: at the full 64-bit width code with a
 * qword-aligned resolved index the helper touches the word arena `q[INDEX >> 3]`
 * directly (one slot covering exactly the byte window `[index, index + 8)`); at
 * every other width and every unaligned index it runs the little-endian byte
 * ladder over `b[]`, narrowing the stored value to the access width and
 * assembling it back on read.
 *
 * This oracle restates the whole routed effect independently: it keeps its own
 * little-endian byte model of the stack arena, plants each case's bytes there,
 * drives the real `X86_SIM_L_STACK_WRITE`, compares the entire byte arena
 * against the model (so a word-path write touching the wrong bytes, or a ladder
 * write spilling past the window, is caught), then drives
 * `X86_SIM_L_STACK_READ` and compares against the model read. Offsets cover
 * qword-aligned and unaligned resolved indices as well as the absent-code width
 * fallback. Exit 1 on mismatch.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. -I../x86 -I../../kprog \
 *      -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *      test_x86_stack_arm_route_host.c -o /tmp/t_stack_arm_route
 *   /tmp/t_stack_arm_route
 */

#define X86_SIM_ENABLE_STACK 1
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;
typedef signed long long __s64;
typedef signed int __s32;

#define __always_inline inline

#include "../x86/x86_sim_local_bpf.h"

#include <stdio.h>

static int failures;
static unsigned long cases;

/* The independent little-endian byte model of the stack arena, kept parallel to
 * the simulator's own storage so the whole arena can be compared. */
static __u8 model_bytes[X86_SIM_STACK_BYTES];

/* The number of bytes an access stores, from the raw width code: the absent
 * code 0 falls back to the full 64 bits, exactly as `x86_width_effective` does.
 * The real codes are the byte counts 1/2/4/8. */
static unsigned model_bytes_of(unsigned width)
{
	return width ? width : 8U;
}

/* The resolved stack index the sim computes, restated from the raw offset and
 * the frame capacity. */
static unsigned model_index(__s64 off)
{
	return (unsigned)(off + (__s64)X86_SIM_STACK_BYTES);
}

/* Zero the model and plant one case's bytes little-endian at the resolved index,
 * narrowed to the access width. */
static void seed_model(unsigned index, unsigned width, __u64 value)
{
	unsigned bytes = model_bytes_of(width);
	__u64 narrowed = value;
	unsigned i;
	unsigned k;

	if (bytes < 8U)
		narrowed &= (1ULL << (8U * bytes)) - 1ULL;
	for (i = 0; i < X86_SIM_STACK_BYTES; i++)
		model_bytes[i] = 0;
	for (k = 0; k < bytes; k++)
		model_bytes[index + k] = (__u8)(narrowed >> (8U * k));
}

/* Assemble the access-width little-endian value the byte ladder would read. */
static __u64 model_read(unsigned index, unsigned width)
{
	unsigned bytes = model_bytes_of(width);
	__u64 value = 0;
	unsigned k;

	for (k = 0; k < bytes; k++)
		value |= ((__u64)model_bytes[index + k]) << (8U * k);
	return value;
}

/* Drive one (offset, width, value) case through the real stack helpers and
 * compare both the whole byte arena and the read-back against the model: the
 * word path must cover exactly the access window and no byte outside it. */
static void check_stack(__s64 off, unsigned width, __u64 value)
{
	unsigned index = model_index(off);
	unsigned bytes = model_bytes_of(width);
	__u64 got;
	unsigned i;

	if (index + bytes > X86_SIM_STACK_BYTES)
		return;

	X86_SIM_L_DECLARE_STACK();
	(void)__x86_stack_mem;

	seed_model(index, width, value);
	for (i = 0; i < X86_SIM_STACK_BYTES; i++)
		__x86_stack_mem.b[i] = model_bytes[i];

	X86_SIM_L_STACK_WRITE(off, width, value);
	for (i = 0; i < X86_SIM_STACK_BYTES; i++) {
		cases++;
		if (__x86_stack_mem.b[i] != model_bytes[i]) {
			printf("MISMATCH arena off=%lld width=%u index=%u "
			       "b[%u]: got %u want %u\n",
			       (long long)off, width, index, i,
			       (unsigned)__x86_stack_mem.b[i],
			       (unsigned)model_bytes[i]);
			failures++;
			return;
		}
	}

	got = X86_SIM_L_STACK_READ(off, width);
	cases++;
	if (got != model_read(index, width)) {
		printf("MISMATCH read off=%lld width=%u index=%u got 0x%llx "
		       "want 0x%llx\n", (long long)off, width, index,
		       (unsigned long long)got,
		       (unsigned long long)model_read(index, width));
		failures++;
	}
}

/* The routed selector must agree with the generated contract's table. */
static void check_selectors(void)
{
	cases++;
	if (KPROG_X86_STACK_ARM_COUNT != 2U) {
		printf("MISMATCH stack arm contract count drift\n");
		failures++;
	}

	cases++;
	if (KPROG_X86_STACK_ARM(1, 1) != KPROG_X86_STACK_ARM_WORD ||
	    KPROG_X86_STACK_ARM(1, 0) != KPROG_X86_STACK_ARM_BYTE ||
	    KPROG_X86_STACK_ARM(0, 1) != KPROG_X86_STACK_ARM_BYTE ||
	    KPROG_X86_STACK_ARM(0, 0) != KPROG_X86_STACK_ARM_BYTE) {
		printf("MISMATCH stack arm selector drift\n");
		failures++;
	}
}

int main(void)
{
	/* Width codes: the absent-code fallback plus each real width. */
	static const unsigned widths[5] = {
		0U, X86_WIDTH_8, X86_WIDTH_16, X86_WIDTH_32, X86_WIDTH_64,
	};
	/* Values chosen so every byte of the access window is non-trivial and
	 * narrowing to a partial width visibly differs from the full value. */
	static const __u64 values[6] = {
		0ULL, ~0ULL, 0x1122334455667788ULL, 0xffeeddccbbaa9988ULL,
		0x00000000000000ffULL, 0x8877665544332211ULL,
	};
	__s64 off;
	unsigned wi;
	unsigned vi;

	check_selectors();

	/* Offsets sweep the whole resolved-index range: the aligned and unaligned
	 * offsets of every window; `check_stack` skips the ones whose window
	 * would leave the arena. */
	for (off = -(__s64)X86_SIM_STACK_BYTES; off < 0; off++)
		for (wi = 0; wi < 5U; wi++)
			for (vi = 0; vi < 6U; vi++)
				check_stack(off, widths[wi], values[vi]);

	if (failures != 0) {
		printf("x86 stack arm route host cross-check: FAIL (%d)\n",
		       failures);
		return 1;
	}
	printf("x86 stack arm route host cross-check: OK (%lu cases)\n", cases);
	return 0;
}
