/*
 * Host cross-check for the x86 simulator's *routing* of its stack write and
 * read helpers' byte ladders through the machine-checked per-lane activation
 * contract (STEP 0146): the generated `generated/x86_stack_write_lanes.h`.
 *
 * The macros under test are the real simulator macros `X86_SIM_L_STACK_WRITE`
 * and `X86_SIM_L_STACK_READ`, declared by including the real header
 * `../x86/x86_sim_local_bpf.h` with `X86_SIM_ENABLE_STACK` set. The write
 * helper's byte ladder writes lane `k` of the access exactly when lane `k` is
 * active for the width — the monotone activation the helper previously
 * recomputed by hand as four nested gates (`width >= 16`, `>= 32`, `== 64`) —
 * and the read helper assembles lane `k` back under the same activation. The
 * oracle drives the simulator's write over a deterministic byte pattern while
 * an independent model (the access width's little-endian window, never the
 * helper's per-lane gates) scatters the width's low bytes and leaves every byte
 * above the width untouched. A ladder routed to a wrong lane set — a byte
 * written past the window, a byte of the window missed, or a read lane the
 * write activated — diverges from the model. The write is then read back
 * through the real stack read helper, which routes through the same activation,
 * to close the round trip.
 *
 * Build and run:
 *   cd kprog/formal &&
 *   cc -Wall -Wextra -O2 -I. -I../x86 -I../../kprog \
 *      -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *      test_x86_stack_write_lanes_route_host.c \
 *      -o build/test_x86_stack_write_lanes_route_host &&
 *   ./build/test_x86_stack_write_lanes_route_host
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

/* The resolved stack index the sim computes, restated from the raw offset and
 * the frame capacity. */
static __u32 ref_index(__s64 off)
{
	return (__u32)X86_SIM_L_STACK_INDEX(off);
}

/* The number of bytes an access touches, from the raw width code: the absent
 * code 0 falls back to the full 64 bits, exactly as `x86_width_effective` does.
 * The real codes are the byte counts 1/2/4/8. */
static unsigned width_bytes(__u32 width)
{
	return width ? width : 8U;
}

/* Independent per-lane activation: lane `k` of an access is touched exactly
 * when its number is below the width's byte count, restated from the raw facts
 * with no reference to the generated `KPROG_X86_STACK_WRITE_LANE_ACTIVE`. */
static unsigned model_lane_active(__u32 width, unsigned lane)
{
	return (lane < width_bytes(width)) ? 1U : 0U;
}

/* Plant a deterministic byte pattern into both the model image and the given
 * arena, so a wrong lane set has a distinguishable divergence. */
static void fill_pattern(__u8 *arena, unsigned long bytes)
{
	unsigned long i;

	for (i = 0; i < bytes; i++) {
		__u8 v = (__u8)((i * 37UL + 11UL) & 0xffUL);

		arena[i] = v;
		model_bytes[i] = v;
	}
}

/* Commit a stack write to the independent byte image: the access width's
 * little-endian window `[idx, idx+n)`, every byte above the width untouched. */
static void model_write(__u32 idx, __u32 width, __u64 value)
{
	unsigned n = width_bytes(width);
	unsigned k;

	for (k = 0; k < n; k++)
		model_bytes[idx + k] = (__u8)((value >> (8 * k)) & 0xffU);
}

/* The generated activation must name the same lane set the independent model
 * names, at every width and lane, and the mask must be the low bits set. */
static void check_activation(void)
{
	static const __u32 widths[] = { X86_WIDTH_8, X86_WIDTH_16,
					X86_WIDTH_32, X86_WIDTH_64 };
	unsigned wi;
	unsigned lane;

	cases++;
	if (KPROG_X86_STACK_WRITE_LANE_SLOTS != 8U) {
		printf("MISMATCH slot count got=%u want=8\n",
		       (unsigned)KPROG_X86_STACK_WRITE_LANE_SLOTS);
		failures++;
	}

	for (wi = 0; wi < sizeof(widths) / sizeof(widths[0]); wi++) {
		__u32 width = widths[wi];
		unsigned mask = 0;

		for (lane = 0; lane < 8U; lane++) {
			unsigned got =
				KPROG_X86_STACK_WRITE_LANE_ACTIVE(width, lane);
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
		if (KPROG_X86_STACK_WRITE_MASK(width) != mask) {
			printf("MISMATCH mask width=%u got=%u want=%u\n", width,
			       (unsigned)KPROG_X86_STACK_WRITE_MASK(width),
			       mask);
			failures++;
		}
	}

	/* The ladder touches a lane at exactly one byte position, so only the
	 * full 64-bit access may reach the top lane. */
	cases++;
	if (KPROG_X86_STACK_WRITE_LANE_ACTIVE(X86_WIDTH_64, 7) == 0U ||
	    KPROG_X86_STACK_WRITE_LANE_ACTIVE(X86_WIDTH_32, 7) != 0U ||
	    KPROG_X86_STACK_WRITE_LANE_ACTIVE(X86_WIDTH_16, 7) != 0U) {
		printf("MISMATCH top-lane activation drift\n");
		failures++;
	}
}

/* Drive the real write at one offset/width/value, compare the whole byte
 * arena against the model, then read it back through the real read helper. */
static void drive_write(__s64 off, __u32 width, __u64 value)
{
	__u32 idx = ref_index(off);
	unsigned n = width_bytes(width);
	__u64 mask = (n == 8) ? 0xffffffffffffffffULL
			      : ((1ULL << (8 * n)) - 1ULL);
	__u64 got;
	unsigned long i;

	X86_SIM_L_DECLARE_STACK();

	fill_pattern(__x86_stack_mem.b, (unsigned long)X86_SIM_STACK_BYTES);
	(void)__x86_stack_mem;

	X86_SIM_L_STACK_WRITE(off, width, value);
	model_write(idx, width, value);
	for (i = 0; i < (unsigned long)X86_SIM_STACK_BYTES; i++) {
		cases++;
		if (__x86_stack_mem.b[i] != model_bytes[i]) {
			printf("MISMATCH write off=%lld width=%u byte %lu: "
			       "got=%u want=%u\n", (long long)off, width, i,
			       __x86_stack_mem.b[i], model_bytes[i]);
			failures++;
			return;
		}
	}

	got = X86_SIM_L_STACK_READ(off, width);
	cases++;
	if (got != (value & mask)) {
		printf("MISMATCH roundtrip off=%lld width=%u idx=%u got=%llu "
		       "want=%llu\n", (long long)off, width, idx,
		       (unsigned long long)got,
		       (unsigned long long)(value & mask));
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

	X86_SIM_L_DECLARE_STACK();

	fill_pattern(__x86_stack_mem.b, (unsigned long)X86_SIM_STACK_BYTES);
	(void)__x86_stack_mem;

	X86_SIM_L_STACK_WRITE(off, width, value);

	for (k = n; k < 8U && idx + k < X86_SIM_STACK_BYTES; k++) {
		__u8 sentinel = (__u8)(((idx + k) * 37UL + 11UL) & 0xffUL);

		cases++;
		if (__x86_stack_mem.b[idx + k] != sentinel) {
			printf("MISMATCH tail off=%lld width=%u byte %u: "
			       "got=%u want=%u\n", (long long)off, width,
			       idx + k, __x86_stack_mem.b[idx + k], sentinel);
			failures++;
		}
	}
}

int main(void)
{
	static const __u32 widths[] = { X86_WIDTH_8, X86_WIDTH_16,
					X86_WIDTH_32, X86_WIDTH_64 };
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

	check_activation();

	/* Every reachable offset at every width, at the boundary patterns: a
	 * deterministic byte pattern makes the byte windows distinguishable, so a
	 * lane set off by one diverges from the model. */
	for (p = 0; p < sizeof(patterns) / sizeof(patterns[0]); p++) {
		for (wi = 0; wi < sizeof(widths) / sizeof(widths[0]); wi++) {
			__u32 width = widths[wi];
			long n = (long)width_bytes(width);

			for (off = -(long)X86_SIM_STACK_BYTES;
			     off + (long)X86_SIM_STACK_BYTES + n <=
			     (long)X86_SIM_STACK_BYTES;
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
		off = (long)(state % (__u64)(X86_SIM_STACK_BYTES - n + 1U)) -
		      (long)X86_SIM_STACK_BYTES;
		drive_write(off, width, state);
	}

	if (failures) {
		printf("x86 stack write lanes route host cross-check: FAIL (%d)\n",
		       failures);
		return 1;
	}
	printf("x86 stack write lanes route host cross-check: OK (%lu cases)\n",
	       cases);
	return 0;
}
