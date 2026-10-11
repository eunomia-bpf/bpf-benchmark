/*
 * Host cross-check for the AArch64 simulator's *routing* of its stack write
 * helper's byte ladder through the machine-checked per-lane activation contract
 * (STEP 0124): the generated `generated/arm64_stack_write_lanes.h`.
 *
 * The macro under test is the real simulator macro `ARM64_SIM_L_STACK_WRITE_TAG`
 * (reached through `ARM64_SIM_L_STACK_WRITE`), declared by including the real
 * header `../arm64/arm64_sim_local_bpf.h` with `ARM64_SIM_ENABLE_STACK` set. The
 * write helper's byte ladder writes lane `k` of the access exactly when lane `k`
 * is active for the width — the monotone activation the helper previously
 * recomputed by hand as four nested gates (`width >= 16`, `>= 32`, `== 64`). The
 * oracle drives the simulator's write over a deterministic byte pattern while an
 * independent model (the access width's little-endian window, never the helper's
 * per-lane gates) scatters the width's low bytes and leaves every byte above the
 * width untouched. A ladder routed to a wrong lane set — a byte written past the
 * window, or a byte of the window missed — diverges from the model. The write is
 * then read back through the real stack read helper to close the round trip.
 *
 * Build and run:
 *   cd kprog/formal &&
 *   cc -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog \
 *      -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *      test_arm64_stack_write_lanes_route_host.c \
 *      -o build/test_arm64_stack_write_lanes_route_host &&
 *   ./build/test_arm64_stack_write_lanes_route_host
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

static unsigned width_bytes(__u32 width)
{
	if (width == ARM64_WIDTH_8)
		return 1;
	if (width == ARM64_WIDTH_16)
		return 2;
	if (width == ARM64_WIDTH_32)
		return 4;
	return 8;
}

/* Independent per-lane activation: lane `k` of an access is written exactly when
 * its number is below the width's byte count, restated from the raw facts with
 * no reference to the generated `KPROG_ARM64_STACK_WRITE_LANE_ACTIVE`. */
static unsigned model_lane_active(__u32 width, unsigned lane)
{
	return (lane < width_bytes(width)) ? 1U : 0U;
}

/* Commit a stack write to the independent byte image: the access width's
 * little-endian window `[idx, idx+n)`, every byte above the width untouched. */
static void model_write(__s64 off, __u32 width, __u64 value)
{
	__u32 idx = ref_index(off);
	unsigned n = width_bytes(width);
	unsigned k;

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

/* The generated activation must name the same lane set the independent model
 * names, at every width and lane, and the mask must be the low bits set. */
static void check_activation(void)
{
	static const __u32 widths[] = { ARM64_WIDTH_8, ARM64_WIDTH_16,
					ARM64_WIDTH_32, ARM64_WIDTH_64 };
	unsigned wi;
	unsigned lane;

	cases++;
	if (KPROG_ARM64_STACK_WRITE_LANE_SLOTS != 8U) {
		printf("MISMATCH slot count got=%u want=8\n",
		       (unsigned)KPROG_ARM64_STACK_WRITE_LANE_SLOTS);
		failures++;
	}

	for (wi = 0; wi < sizeof(widths) / sizeof(widths[0]); wi++) {
		__u32 width = widths[wi];
		unsigned mask = 0;

		for (lane = 0; lane < 8U; lane++) {
			unsigned got =
				KPROG_ARM64_STACK_WRITE_LANE_ACTIVE(width, lane);
			unsigned want = model_lane_active(width, lane);

			cases++;
			if (got != want) {
				printf("MISMATCH active width=%u lane=%u "
				       "got=%u want=%u\n", width, lane, got,
				       want);
				failures++;
			}
			if (got != 0U)
				mask |= 1U << lane;
		}

		cases++;
		if (KPROG_ARM64_STACK_WRITE_MASK(width) != mask) {
			printf("MISMATCH mask width=%u got=%u want=%u\n", width,
			       (unsigned)KPROG_ARM64_STACK_WRITE_MASK(width),
			       mask);
			failures++;
		}
	}

	/* The ladder writes a lane at exactly one byte position, so only the
	 * full 64-bit access may reach the top lane. */
	cases++;
	if (KPROG_ARM64_STACK_WRITE_LANE_ACTIVE(ARM64_WIDTH_64, 7) == 0U ||
	    KPROG_ARM64_STACK_WRITE_LANE_ACTIVE(ARM64_WIDTH_32, 7) != 0U ||
	    KPROG_ARM64_STACK_WRITE_LANE_ACTIVE(ARM64_WIDTH_16, 7) != 0U) {
		printf("MISMATCH top-lane activation drift\n");
		failures++;
	}
}

/* Drive the real write at one offset/width/value and compare the whole byte
 * image, then read it back through the real read helper. */
static void drive_write(__s64 off, __u32 width, __u64 value)
{
	__u32 idx = ref_index(off);
	unsigned n = width_bytes(width);
	__u64 mask = (n == 8) ? 0xffffffffffffffffULL
			      : ((1ULL << (8 * n)) - 1ULL);
	__u64 got;

	fill_pattern();
	ARM64_SIM_L_STACK_WRITE(off, width, value);
	model_write(off, width, value);
	check_image("write");

	got = ARM64_SIM_L_STACK_READ(off, width);
	cases++;
	if (got != (value & mask)) {
		printf("MISMATCH roundtrip off=%lld width=%u idx=%u got=%llu "
		       "want=%llu\n", off, width, idx, got, value & mask);
		failures++;
	}
}

/* A write of the width's byte count must leave every byte above the window
 * untouched: pre-fill a sentinel, write, and check the tail explicitly against
 * the pre-write image. */
static void drive_leaves_tail(__s64 off, __u32 width, __u64 value)
{
	__u32 idx = ref_index(off);
	unsigned n = width_bytes(width);
	unsigned k;

	fill_pattern();
	ARM64_SIM_L_STACK_WRITE(off, width, value);

	for (k = n; k < 8U && idx + k < ARM64_SIM_STACK_BYTES; k++) {
		__u8 sentinel = (__u8)(((idx + k) * 37UL + 11UL) & 0xffUL);

		cases++;
		if (__a64_stack.b[idx + k] != sentinel) {
			printf("MISMATCH tail off=%lld width=%u byte %u: "
			       "got=%u want=%u\n", off, width, idx + k,
			       __a64_stack.b[idx + k], sentinel);
			failures++;
		}
	}
}

int main(void)
{
	static const __u32 widths[] = { ARM64_WIDTH_8, ARM64_WIDTH_16,
					ARM64_WIDTH_32, ARM64_WIDTH_64 };
	static const __u64 patterns[] = {
		0x0000000000000000ULL,
		0xffffffffffffffffULL,
		0x0123456789abcdefULL,
		0x80c0402000100804ULL,
		0x0408102040c08001ULL,
		0xff00ff00ff00ff00ULL,
	};
	__u64 state = 0x5b3e9d10a7c42f86ULL;
	unsigned long wi;
	unsigned p, iter;
	long off;

	cases++;
	if (sizeof(__a64_stack.b) != ARM64_SIM_STACK_BYTES ||
	    sizeof(__a64_stack.q) != ARM64_SIM_STACK_BYTES) {
		printf("MISMATCH layout: b=%lu q=%lu\n",
		       (unsigned long)sizeof(__a64_stack.b),
		       (unsigned long)sizeof(__a64_stack.q));
		failures++;
	}

	check_activation();

	/* Every reachable offset at every width, at the boundary patterns: a
	 * deterministic byte pattern makes the byte windows distinguishable, so a
	 * lane set off by one diverges from the model. */
	for (p = 0; p < sizeof(patterns) / sizeof(patterns[0]); p++) {
		for (wi = 0; wi < sizeof(widths) / sizeof(widths[0]); wi++) {
			__u32 width = widths[wi];
			long n = (long)width_bytes(width);

			for (off = -(long)ARM64_SIM_STACK_BIAS;
			     (long)ARM64_SIM_STACK_BIAS + off + n <=
			     (long)ARM64_SIM_STACK_BYTES;
			     off++) {
				drive_write(off, width, patterns[p]);
				drive_leaves_tail(off, width, patterns[p]);
			}
		}
	}

	/* A fixed-seed sweep over offsets, widths, and values. */
	for (iter = 0; iter < 20000; iter++) {
		__u32 width;
		long n;

		state = state * 6364136223846793005ULL +
			1442695040888963407ULL;
		width = widths[iter % 4U];
		n = (long)width_bytes(width);
		off = (long)(state % (__u64)(ARM64_SIM_STACK_BYTES - n + 1U)) -
		      (long)ARM64_SIM_STACK_BIAS;
		drive_write(off, width, state);
	}

	if (failures) {
		printf("arm64 stack write lanes route host cross-check: FAIL (%d)\n",
		       failures);
		return 1;
	}
	printf("arm64 stack write lanes route host cross-check: OK (%lu cases)\n",
	       cases);
	return 0;
}
