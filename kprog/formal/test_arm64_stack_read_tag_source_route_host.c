/*
 * Route host cross-check for the AArch64 stack slot-tag read source
 * contract (STEP 0138).
 *
 * Drives the simulator's real `ARM64_SIM_L_STACK_READ_TAG` helper through
 * the generated source selector and compares the tag it returns against an
 * independent model of the per-slot tag array and the byte image. The model
 * restates the 2-way source selection from the two raw facts (the width-64
 * test and the 8-aligned slot test) with no reference to the generated
 * selector: at the 64-bit aligned slot the read helper returns the slot's
 * word in the tag array, and at every other fact pair it returns the scalar
 * marker. The oracle also pins the generated source selector against the
 * independent 2-way statement at every fact pair and width code. A 20000-
 * iteration sweep interleaves the real tagged write helper (which commits to
 * the same tag array and byte image) with the real tag read helper. Exit 1
 * on mismatch.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog \
 *       -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *       test_arm64_stack_read_tag_source_route_host.c -o /tmp/t_srts_route
 *   /tmp/t_srts_route
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

/* Independent models of the arena byte image and the slot tag array. */
static __u8 model_b[ARM64_SIM_STACK_BYTES];
static __u8 model_tag[KPROG_ARM64_STACK_TAG_SLOTS(ARM64_SIM_STACK_BYTES)];

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

/* The independent 2-way source selection: the stack-tag-array source exactly
 * when the read is 64-bit and the slot is 8-aligned, the scalar default
 * otherwise. Restated from the two raw facts with no reference to the
 * generated selector. */
static unsigned model_source(unsigned w64, unsigned aligned)
{
	if (w64 && aligned)
		return 0;
	return 1;
}

/* The independent expected tag of a stack slot read: at the 64-bit aligned
 * slot the slot's tag-array word, otherwise the scalar marker. */
static __u8 model_read_tag(__s64 off, __u32 width)
{
	__u32 idx = ref_index(off);
	unsigned w64 = (width == ARM64_WIDTH_64);
	unsigned aligned = ((idx & 7U) == 0U);

	if (model_source(w64, aligned) == 0)
		return model_tag[KPROG_ARM64_STACK_WORD_INDEX(idx)];
	return ARM64_SIM_TAG_SCALAR;
}

/* The generated source selector must name the same source the independent
 * 2-way statement names, at every fact pair and at every width code the
 * helper feeds it. */
static void check_selector(void)
{
	static const __u32 widths[] = { ARM64_WIDTH_8, ARM64_WIDTH_16,
					ARM64_WIDTH_32, ARM64_WIDTH_64 };
	unsigned wi;
	unsigned w64;
	unsigned aligned;

	cases++;
	if (KPROG_ARM64_STACK_READ_TAG_SOURCE_COUNT != 2U) {
		printf("MISMATCH source count got=%u want=2\n",
		       (unsigned)KPROG_ARM64_STACK_READ_TAG_SOURCE_COUNT);
		failures++;
	}

	for (w64 = 0; w64 <= 1U; w64++) {
		for (aligned = 0; aligned <= 1U; aligned++) {
			cases++;
			if (KPROG_ARM64_STACK_READ_TAG_SOURCE(w64, aligned) !=
			    model_source(w64, aligned)) {
				printf("MISMATCH source w64=%u aligned=%u "
				       "got=%u\n",
				       w64, aligned,
				       KPROG_ARM64_STACK_READ_TAG_SOURCE(
					       w64, aligned));
				failures++;
			}
		}
	}

	for (wi = 0; wi < sizeof(widths) / sizeof(widths[0]); wi++) {
		for (aligned = 0; aligned <= 1U; aligned++) {
			unsigned w64f = (widths[wi] == ARM64_WIDTH_64);

			cases++;
			if (KPROG_ARM64_STACK_READ_TAG_SOURCE(w64f, aligned) !=
			    model_source(w64f, aligned)) {
				printf("MISMATCH source width=%u aligned=%u "
				       "got=%u\n",
				       widths[wi], aligned,
				       KPROG_ARM64_STACK_READ_TAG_SOURCE(
					       w64f, aligned));
				failures++;
			}
		}
	}
}

/* Drive the real tag read helper at one offset/width and compare the tag it
 * returns to the independent model. */
static void drive_read(__s64 off, __u32 width)
{
	__u8 got = ARM64_SIM_L_STACK_READ_TAG(off, width);
	__u8 want = model_read_tag(off, width);

	cases++;
	if (got != want) {
		printf("MISMATCH read off=%lld width=%u got=%u want=%u\n",
		       off, width, got, want);
		failures++;
	}
}

/* Commit a tagged stack write to the independent models, then read the tag
 * back through the real read helper. The mirror keeps `model_b` and
 * `model_tag` in lockstep with the real arena so the following read has a
 * defined expected tag. */
static void drive_write_read(__s64 off, __u32 width, __u64 value, __u8 tag)
{
	__u32 idx = ref_index(off);
	unsigned w64 = (width == ARM64_WIDTH_64);
	unsigned aligned = ((idx & 7U) == 0U);
	__u32 word = idx >> 3;
	unsigned n = width_bytes(width);
	unsigned k;

	ARM64_SIM_L_STACK_WRITE_TAG(off, width, value, tag);

	/* The write helper's 3-way action (STEP 0137) commits the byte image
	 * and, for the word-and-tag arm, the slot tag. */
	if (w64 && aligned) {
		__u64 *q = (__u64 *)(model_b + word * 8U);

		*q = value;
		model_tag[word] = tag;
	} else {
		if (aligned)
			model_tag[word] = ARM64_SIM_TAG_SCALAR;
		for (k = 0; k < n; k++)
			model_b[idx + k] =
				(__u8)((value >> (8 * k)) & 0xffULL);
	}

	drive_read(off, width);
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
	};
	static const __u8 tags[] = { ARM64_SIM_TAG_SCALAR,
				     ARM64_SIM_TAG_STACK,
				     ARM64_SIM_TAG_MAP_PTR,
				     ARM64_SIM_TAG_PACKET };
	__u64 state = 0x5b3e9d10a7c42f86ULL;
	unsigned long wi;
	unsigned p, t, iter;
	long off;

	cases++;
	if (sizeof(__a64_stack.b) != ARM64_SIM_STACK_BYTES ||
	    sizeof(__a64_stack.q) != ARM64_SIM_STACK_BYTES ||
	    sizeof(__a64_stack_tag) !=
	    KPROG_ARM64_STACK_TAG_SLOTS(ARM64_SIM_STACK_BYTES)) {
		printf("MISMATCH layout: b=%lu q=%lu tag=%lu\n",
		       (unsigned long)sizeof(__a64_stack.b),
		       (unsigned long)sizeof(__a64_stack.q),
		       (unsigned long)sizeof(__a64_stack_tag));
		failures++;
	}

	check_selector();

	/* Drive the real write + read helpers at every reachable offset and
	 * width; each write commit is mirrored into the model, so every read
	 * has a defined expected tag. */
	for (t = 0; t < sizeof(tags) / sizeof(tags[0]); t++) {
		for (p = 0; p < sizeof(patterns) / sizeof(patterns[0]);
		     p++) {
			for (wi = 0; wi < sizeof(widths) / sizeof(widths[0]);
			     wi++) {
				__u32 width = widths[wi];
				long n = (long)width_bytes(width);

				for (off = -(long)ARM64_SIM_STACK_BIAS;
				     (long)ARM64_SIM_STACK_BIAS + off + n <=
				     (long)ARM64_SIM_STACK_BYTES;
				     off++) {
					drive_write_read(off, width,
							patterns[p], tags[t]);
					drive_read(off, width);
				}
			}
		}
	}

	/* A fixed-seed sweep interleaving the real tagged write and tag read
	 * helpers. */
	for (iter = 0; iter < 20000; iter++) {
		__u32 width;
		long n;

		state = state * 6364136223846793005ULL +
			1442695040888963407ULL;
		width = widths[iter % 4U];
		n = (long)width_bytes(width);
		off = (long)(state % (__u64)(ARM64_SIM_STACK_BYTES - n + 1U)) -
		      (long)ARM64_SIM_STACK_BIAS;
		drive_write_read(off, width, state,
				 tags[(iter >> 4) % 4U]);
		drive_read(off, width);
	}

	if (failures) {
		printf("arm64 stack read tag source route host cross-check: "
		       "FAIL (%d)\n", failures);
		return 1;
	}
	printf("arm64 stack read tag source route host cross-check: OK "
	       "(%lu cases)\n", cases);
	return 0;
}
