/*
 * Host cross-check for the AArch64 simulator's *routing* of its stack read
 * helper's body choice through the machine-checked word-path/byte-ladder
 * contract (STEP 0121): the generated `generated/arm64_stack_arm.h`.
 *
 * The macro under test is the real simulator macro `ARM64_SIM_L_STACK_READ`,
 * declared by including the real header `../arm64/arm64_sim_local_bpf.h` with
 * `ARM64_SIM_ENABLE_STACK` set. The read helper selects between two bodies from
 * a closed pair of facts — whether the resolved access width is the full
 * 64-bit code and whether the resolved stack index is qword-aligned — and this
 * oracle drives the simulator's read over a deterministic byte pattern while an
 * independent model of both bodies (a direct word-slot read of the covering
 * `q[INDEX >> 3]`, and the little-endian byte ladder over `b[]`) computes what
 * each body yields and the generated `KPROG_ARM64_STACK_ARM` names the body.
 * The simulator's read must equal the body the independent selector chose; a
 * helper routed to the wrong body — the word slot's floor-aligned byte window
 * for an unaligned index, or a truncated window — diverges from the model.
 *
 * Build and run:
 *   cd kprog/formal &&
 *   cc -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog \
 *      -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *      test_arm64_stack_arm_route_host.c -o build/test_arm64_stack_arm_route_host &&
 *   ./build/test_arm64_stack_arm_route_host
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

ARM64_SIM_L_DECLARE_STACK();

static int failures;
static unsigned long cases;

/* Independent model of the arena byte image. */
static __u8 model_b[ARM64_SIM_STACK_BYTES];

static __u32 ref_index(__s64 off)
{
	__s64 v = (__s64)ARM64_SIM_STACK_BIAS + off;

	return (__u32)v;
}

static int width_bytes(__u32 width)
{
	if (width == ARM64_WIDTH_8)
		return 1;
	if (width == ARM64_WIDTH_16)
		return 2;
	if (width == ARM64_WIDTH_32)
		return 4;
	return 8;
}

/* The byte-ladder body: the access width's little-endian window `[idx, idx+n)`. */
static __u64 model_byte(__u32 idx, __u32 width)
{
	__u64 v = 0;
	int n = width_bytes(width);
	int k;

	for (k = 0; k < n; k++)
		v |= (__u64)model_b[idx + k] << (8 * k);
	return v;
}

/* The word-arena body: the full covering slot `q[idx >> 3]`, which starts at the
 * floor-aligned byte `idx & ~7`. This differs from the byte ladder whenever the
 * index is not qword-aligned, which is exactly the mis-selection this oracle
 * detects. */
static __u64 model_word(__u32 idx)
{
	__u32 base = idx & ~7U;
	__u64 v = 0;
	int k;

	for (k = 0; k < 8; k++)
		v |= (__u64)model_b[base + k] << (8 * k);
	return v;
}

/* The independent body selection: the word body exactly when the access is the
 * full 64-bit code and the resolved index is qword-aligned, restated from the
 * raw facts with no reference to the generated selector. */
static unsigned model_arm(unsigned is_w64, unsigned is_aligned)
{
	return (is_w64 && is_aligned) ? 1U : 0U;
}

static int ref_aligned(__u32 index) { return (index & 7U) == 0U; }

/* Commit a write to the independent byte image: the access width's
 * little-endian window `[idx, idx+n)`. */
static void model_write(__s64 off, __u32 width, __u64 value)
{
	__u32 idx = ref_index(off);
	int n = width_bytes(width);
	int k;

	for (k = 0; k < n; k++)
		model_b[idx + k] = (__u8)((value >> (8 * k)) & 0xffU);
}

static void fill_pattern(void)
{
	unsigned long i;

	for (i = 0; i < (unsigned long)ARM64_SIM_STACK_BYTES; i++) {
		__u8 v = (__u8)((i * 37UL + 11UL) & 0xffUL);

		__a64_stack.b[i] = v;
		model_b[i] = v;
	}
}

static void check_image(const char *what)
{
	unsigned long i;

	for (i = 0; i < (unsigned long)ARM64_SIM_STACK_BYTES; i++) {
		cases++;
		if (__a64_stack.b[i] != model_b[i]) {
			printf("MISMATCH %s byte %lu: got=%u want=%u\n", what, i,
			       __a64_stack.b[i], model_b[i]);
			failures++;
		}
	}
}

/* The generated selector must name the same body the independent model names,
 * and the two arm codes must be distinct. */
static void check_selectors(void)
{
	unsigned is_w64;
	unsigned is_aligned;

	cases++;
	if (KPROG_ARM64_STACK_ARM_COUNT != 2U) {
		printf("MISMATCH count got=%u want=2\n",
		       (unsigned)KPROG_ARM64_STACK_ARM_COUNT);
		failures++;
	}
	cases++;
	if (KPROG_ARM64_STACK_ARM_WORD == KPROG_ARM64_STACK_ARM_BYTE) {
		printf("MISMATCH arm codes not distinct\n");
		failures++;
	}

	for (is_w64 = 0; is_w64 <= 0xffU; is_w64++) {
		for (is_aligned = 0; is_aligned <= 0xffU; is_aligned++) {
			unsigned got = KPROG_ARM64_STACK_ARM((__u8)is_w64,
							     (__u8)is_aligned);
			unsigned want = model_arm(is_w64, is_aligned);

			cases++;
			if (got != want) {
				printf("MISMATCH arm w64=%u aligned=%u got=%u "
				       "want=%u\n", is_w64, is_aligned, got,
				       want);
				failures++;
			}
		}
	}

	/* The four selection rows, against the arm-code defines. */
	cases++;
	if (KPROG_ARM64_STACK_ARM(1, 1) != KPROG_ARM64_STACK_ARM_WORD ||
	    KPROG_ARM64_STACK_ARM(1, 0) != KPROG_ARM64_STACK_ARM_BYTE ||
	    KPROG_ARM64_STACK_ARM(0, 1) != KPROG_ARM64_STACK_ARM_BYTE ||
	    KPROG_ARM64_STACK_ARM(0, 0) != KPROG_ARM64_STACK_ARM_BYTE) {
		printf("MISMATCH arm table drift\n");
		failures++;
	}
}

/* Drive the real read helper at one access and compare it with the body the
 * independent selector names. */
static void drive_read(__s64 off, __u32 width)
{
	__u32 idx = ref_index(off);
	unsigned is_w64 = (width == ARM64_WIDTH_64) ? 1U : 0U;
	unsigned aligned = (unsigned)ref_aligned(idx);
	unsigned arm = model_arm(is_w64, aligned);
	__u64 want = (arm == 1U) ? model_word(idx) : model_byte(idx, width);
	__u64 got = ARM64_SIM_L_STACK_READ(off, width);

	cases++;
	if (got != want) {
		printf("MISMATCH read off=%lld width=%u arm=%u got=%llu "
		       "want=%llu\n", off, width, arm, got, want);
		failures++;
	}

	/* A read must not disturb the byte image. */
	check_image("read");
}

int main(void)
{
	static const __u32 widths[] = { ARM64_WIDTH_8, ARM64_WIDTH_16,
					ARM64_WIDTH_32, ARM64_WIDTH_64 };
	unsigned long wi;
	long off;

	cases++;
	if (sizeof(__a64_stack.b) != ARM64_SIM_STACK_BYTES ||
	    sizeof(__a64_stack.q) != ARM64_SIM_STACK_BYTES) {
		printf("MISMATCH layout: b=%lu q=%lu\n",
		       (unsigned long)sizeof(__a64_stack.b),
		       (unsigned long)sizeof(__a64_stack.q));
		failures++;
	}

	check_selectors();

	/* A deterministic byte pattern makes every byte window distinguishable:
	 * the word body and the byte ladder disagree for a sub-64-bit access, and
	 * the word body reads the floor-aligned slot for an unaligned index, so a
	 * wrongly selected body is detected. */
	fill_pattern();
	for (wi = 0; wi < sizeof(widths) / sizeof(widths[0]); wi++) {
		__u32 width = widths[wi];
		int n = width_bytes(width);

		for (off = -(long)ARM64_SIM_STACK_BIAS;
		     (long)ARM64_SIM_STACK_BIAS + off + n <=
		     (long)ARM64_SIM_STACK_BYTES;
		     off++)
			drive_read(off, width);
	}

	/* The word body is only ever taken at a qword-aligned 64-bit access, and
	 * there it must agree with the byte ladder over the same 8-byte window. */
	for (off = -(long)ARM64_SIM_STACK_BIAS;
	     (long)ARM64_SIM_STACK_BIAS + off + 8 <=
	     (long)ARM64_SIM_STACK_BYTES;
	     off += 8) {
		__u32 idx = ref_index(off);
		__u64 word = ARM64_SIM_L_STACK_READ(off, ARM64_WIDTH_64);
		__u64 byte = model_byte(idx, ARM64_WIDTH_64);

		cases++;
		if (word != byte) {
			printf("MISMATCH aligned word off=%ld got=%llu "
			       "want=%llu\n", off, word, byte);
			failures++;
		}
	}

	/* Write a known value through the real write helper, then read it back
	 * through the real read helper: the two must round-trip at every width and
	 * every reachable offset as well as against the model's write. */
	for (wi = 0; wi < sizeof(widths) / sizeof(widths[0]); wi++) {
		__u32 width = widths[wi];
		int n = width_bytes(width);

		for (off = -(long)ARM64_SIM_STACK_BIAS;
		     (long)ARM64_SIM_STACK_BIAS + off + n <=
		     (long)ARM64_SIM_STACK_BYTES;
		     off++) {
			__u32 idx = ref_index(off);
			__u64 value = 0x0123456789abcdefULL >> (8 * (8 - n));
			__u64 mask = (n == 8) ? 0xffffffffffffffffULL
					      : ((1ULL << (8 * n)) - 1ULL);
			__u64 got;

			fill_pattern();
			ARM64_SIM_L_STACK_WRITE(off, width, value);
			model_write(off, width, value);
			got = ARM64_SIM_L_STACK_READ(off, width);
			cases++;
			if (got != (value & mask)) {
				printf("MISMATCH roundtrip off=%ld width=%u "
				       "got=%llu want=%llu\n", off, width, got,
				       value & mask);
				failures++;
			}
			/* The aligned 64-bit read after a 64-bit write must also
			 * equal the model's word-slot value. */
			if (width == ARM64_WIDTH_64 && ref_aligned(ref_index(off))) {
				cases++;
				if (got != model_word(ref_index(off))) {
					printf("MISMATCH word read-back "
					       "off=%ld got=%llu want=%llu\n",
					       off, got, model_word(idx));
					failures++;
				}
			}
		}
	}

	if (failures) {
		printf("arm64 stack arm route host cross-check: FAIL (%d)\n",
		       failures);
		return 1;
	}
	printf("arm64 stack arm route host cross-check: OK (%lu cases)\n",
	       cases);
	return 0;
}
