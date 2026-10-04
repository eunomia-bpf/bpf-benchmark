/*
 * Host cross-check for the AArch64 simulator's *routing* of its stack helpers
 * through the machine-checked arena geometry (STEP 0094): the generated
 * `generated/arm64_stack_arena.h` and `generated/arm64_stack_index.h`.
 *
 * The macros under test are the real simulator macros
 * `ARM64_SIM_L_STACK_INDEX`, `_STACK_WRITE_TAG`, `_STACK_WRITE`, `_STACK_READ`,
 * `_STACK_READ_TAG` and `_STACK_PTR`, declared by including the real header
 * `../arm64/arm64_sim_local_bpf.h` with `ARM64_SIM_ENABLE_STACK` set.
 *
 * A second, independent model of the arena (a plain byte array, a plain tag
 * array and the biased index `bias + off`) is maintained here with direct
 * arithmetic; after every simulator write the oracle compares the simulator's
 * whole `__a64_stack.b[]` byte image, its `__a64_stack_tag[]` image, its read
 * value and its read tag against that model. A helper routed to the wrong byte
 * window, the wrong word slot, the wrong alignment guard or the wrong tag slot
 * diverges from the model.
 *
 * Build and run:
 *   cd native-sim/formal &&
 *   cc -Wall -Wextra -O2 -I. -I../arm64 -I../../native-sim \
 *      -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *      test_arm64_stack_arena_route_host.c -o build/test_arm64_stack_arena_route_host &&
 *   ./build/test_arm64_stack_arena_route_host
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

/* Independent model of the arena storage and its tag array. */
static __u8 model_b[ARM64_SIM_STACK_BYTES];
static __u8 model_tag[ARM64_SIM_STACK_BYTES / 8];

static __u32 ref_index(__s64 off)
{
	__s64 v = (__s64)ARM64_SIM_STACK_BIAS + off;

	return (__u32)v;
}

static int ref_aligned(__u32 index) { return (index & 7U) == 0U; }

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

static __u64 width_mask(__u32 width)
{
	int n = width_bytes(width);

	return n == 8 ? 0xffffffffffffffffULL : ((1ULL << (8 * n)) - 1ULL);
}

static void model_write(__s64 off, __u32 width, __u64 value, __u32 tag)
{
	__u32 idx = ref_index(off);
	__u64 masked = value & width_mask(width);
	int n = width_bytes(width);
	int k;

	for (k = 0; k < n; k++)
		model_b[idx + k] = (__u8)((masked >> (8 * k)) & 0xffU);
	if (ref_aligned(idx))
		model_tag[idx >> 3] =
			(width == ARM64_WIDTH_64) ? (__u8)tag : ARM64_SIM_TAG_SCALAR;
}

static __u64 model_read(__s64 off, __u32 width)
{
	__u32 idx = ref_index(off);
	__u64 v = 0;
	int n = width_bytes(width);
	int k;

	for (k = 0; k < n; k++)
		v |= (__u64)model_b[idx + k] << (8 * k);
	return v;
}

static __u32 model_read_tag(__s64 off, __u32 width)
{
	__u32 idx = ref_index(off);

	if (width == ARM64_WIDTH_64 && ref_aligned(idx))
		return model_tag[idx >> 3];
	return ARM64_SIM_TAG_SCALAR;
}

static void check_image(const char *what)
{
	unsigned long i;

	for (i = 0; i < (unsigned long)ARM64_SIM_STACK_BYTES; i++) {
		cases++;
		if (__a64_stack.b[i] != model_b[i]) {
			printf("MISMATCH %s arena byte %lu: got=%u want=%u\n", what,
			       i, __a64_stack.b[i], model_b[i]);
			failures++;
		}
	}
	for (i = 0; i < (unsigned long)(ARM64_SIM_STACK_BYTES / 8); i++) {
		cases++;
		if (__a64_stack_tag[i] != model_tag[i]) {
			printf("MISMATCH %s tag %lu: got=%u want=%u\n", what, i,
			       __a64_stack_tag[i], model_tag[i]);
			failures++;
		}
	}
}

static void zero_arena(void)
{
	unsigned long i;

	for (i = 0; i < (unsigned long)ARM64_SIM_STACK_BYTES; i++) {
		__a64_stack.b[i] = 0;
		model_b[i] = 0;
	}
	for (i = 0; i < (unsigned long)(ARM64_SIM_STACK_BYTES / 8); i++) {
		__a64_stack_tag[i] = 0;
		model_tag[i] = 0;
	}
}

static void drive_one(__s64 off, __u32 width, __u64 value, __u32 tag)
{
	__u64 got_read;
	__u32 got_tag;

	zero_arena();
	ARM64_SIM_L_STACK_WRITE_TAG(off, width, value, tag);
	model_write(off, width, value, tag);
	check_image("write");

	got_read = ARM64_SIM_L_STACK_READ(off, width);
	cases++;
	if (got_read != model_read(off, width)) {
		printf("MISMATCH read: off=%lld width=%u got=%llu want=%llu\n", off,
		       width, got_read, model_read(off, width));
		failures++;
	}

	got_tag = ARM64_SIM_L_STACK_READ_TAG(off, width);
	cases++;
	if (got_tag != model_read_tag(off, width)) {
		printf("MISMATCH read_tag: off=%lld width=%u got=%u want=%u\n", off,
		       width, got_tag, model_read_tag(off, width));
		failures++;
	}
}

int main(void)
{
	static const __u64 values[] = {
		0x0ULL, 0x1ULL, 0xffULL, 0x0123456789abcdefULL,
		0xfedcba9876543210ULL, 0xffffffffffffffffULL,
		0x00000000000000a5ULL, 0x00000000dea110c3ULL
	};
	static const __u32 tags[] = { ARM64_SIM_TAG_SCALAR,
				      ARM64_SIM_TAG_MAP_PTR,
				      ARM64_SIM_TAG_RODATA_ADDR };
	static const __u32 widths[] = { ARM64_WIDTH_8, ARM64_WIDTH_16,
					ARM64_WIDTH_32, ARM64_WIDTH_64 };
	unsigned long vi, ti, wi;
	long off;

	cases += 3;
	if (sizeof(__a64_stack.b) != ARM64_SIM_STACK_BYTES ||
	    sizeof(__a64_stack.q) != ARM64_SIM_STACK_BYTES ||
	    sizeof(__a64_stack_tag) != ARM64_SIM_STACK_BYTES / 8) {
		printf("MISMATCH layout: b=%lu q=%lu tag=%lu\n",
		       (unsigned long)sizeof(__a64_stack.b),
		       (unsigned long)sizeof(__a64_stack.q),
		       (unsigned long)sizeof(__a64_stack_tag));
		failures++;
	}

	/* Independent macro contract: the generated words macro yields the
	 * arena's own word-slot count, 20 for the enabled arena. */
	cases++;
	if (KPROG_ARM64_STACK_WORDS(ARM64_SIM_STACK_BYTES) != 20U) {
		printf("MISMATCH words: got=%u want=20\n",
		       KPROG_ARM64_STACK_WORDS(ARM64_SIM_STACK_BYTES));
		failures++;
	}

	/* Every abstract frame offset that a full 64-bit store can reach, every
	 * width and every tag: each write is committed to the simulator arena
	 * and to the independent model, then both are compared whole. */
	for (vi = 0; vi < sizeof(values) / sizeof(values[0]); vi++) {
		for (ti = 0; ti < sizeof(tags) / sizeof(tags[0]); ti++) {
			for (wi = 0; wi < sizeof(widths) / sizeof(widths[0]); wi++) {
				__u32 width = widths[wi];
				int n = width_bytes(width);

				for (off = -(long)ARM64_SIM_STACK_BIAS;
				     (long)ARM64_SIM_STACK_BIAS + off + n <=
				     (long)ARM64_SIM_STACK_BYTES;
				     off++) {
					drive_one(off, width, values[vi],
						  tags[ti]);
				}
			}
		}
	}

	/* Sequential writes over the same arena: the byte images and tag images
	 * stay in agreement as slices overlap. */
	zero_arena();
	for (off = -(long)ARM64_SIM_STACK_BIAS;
	     (long)ARM64_SIM_STACK_BIAS + off + 8 <=
	     (long)ARM64_SIM_STACK_BYTES;
	     off += 8) {
		__u64 value = 0x0102030405060708ULL * (__u64)(off + 1);

		ARM64_SIM_L_STACK_WRITE(off, ARM64_WIDTH_64, value);
		model_write(off, ARM64_WIDTH_64, value, ARM64_SIM_TAG_SCALAR);
		check_image("seq");
	}
	/* A sub-word store at every byte offset of a word slice. */
	zero_arena();
	for (off = -8; off <= 8; off++) {
		ARM64_SIM_L_STACK_WRITE_TAG(off, ARM64_WIDTH_16, 0xbeefULL,
					    ARM64_SIM_TAG_ABI);
		model_write(off, ARM64_WIDTH_16, 0xbeefULL, ARM64_SIM_TAG_ABI);
		check_image("subword");
	}

	/* The stack pointer helper addresses the byte arena at the biased
	 * index: its distance from the arena base is `bias + off`. */
	for (off = -(long)ARM64_SIM_STACK_BIAS;
	     off <= (long)ARM64_SIM_STACK_BIAS; off++) {
		unsigned char *base = &__a64_stack.b[0];
		long delta = (unsigned char *)ARM64_SIM_L_STACK_PTR(off) - base;

		cases++;
		if (delta != (long)ARM64_SIM_STACK_BIAS + off) {
			printf("MISMATCH ptr: off=%ld delta=%ld want=%ld\n", off,
			       delta, (long)ARM64_SIM_STACK_BIAS + off);
			failures++;
		}
	}

	if (failures) {
		printf("arm64 stack arena route host cross-check: FAIL (%d)\n",
		       failures);
		return 1;
	}
	printf("arm64 stack arena route host cross-check: OK (%lu cases)\n",
	       cases);
	return 0;
}
