/*
 * Host cross-check for the AArch64 simulator's *routing* of its stack write
 * slot-tag action (STEP 0137).
 *
 * Drives the live STACK_WRITE_TAG / STACK_WRITE helpers and independently
 * checks every byte and shadow tag. Only a complete aligned 64-bit store
 * transfers its input tag; every other write clears ALL overlapped word tags,
 * including unaligned and cross-word writes. The generated 3-way selector is
 * checked separately as a routing predicate, not a complete mutation rule.
 *
 * Build/run: make -C kprog/formal check
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
#include "stack_store_model_host.h"
#include "guarded_memory_host.h"

/* Unsupported opcode callbacks are forbidden for the valid-width sweeps.
 * Unmapped memory is checked separately through actual CPU faults. */
static unsigned unsupported_calls;
static void arm64_sim_unsupported_opcode(void)
{
	unsupported_calls++;
}


typedef union {
    __u8 b[ARM64_SIM_STACK_BYTES];
    __u64 q[KPROG_ARM64_STACK_WORDS(ARM64_SIM_STACK_BYTES)];
} host_stack_arena;
static volatile host_stack_arena *host_stack;
#define __a64_stack (*host_stack)
static __u8 __a64_stack_tag[ARM64_SIM_TAG_STORAGE_BYTES(ARM64_SIM_STACK_BYTES)] __attribute__((aligned(8)));
struct memory_access { long off; __u32 width; int is_write; };
static void access_boundary(void *argument)
{
    const struct memory_access *access=argument;
    if (access->is_write)
        ARM64_SIM_L_STACK_WRITE(access->off,access->width,0x1122334455667788ULL);
    else
        (void)ARM64_SIM_L_STACK_READ(access->off,access->width);
}

static int failures;
static unsigned long cases;

/* Independent models of the arena byte image and the slot tag array. */
static __u8 model_b[ARM64_SIM_STACK_BYTES];
static __u8 model_tag[((ARM64_SIM_STACK_BYTES + 63U) / 64U) * 8U];

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

/* The independent value mask of a width code: the low bits the helper's width
 * narrowing keeps. */
static __u64 model_mask(__u32 width)
{
	if (width == ARM64_WIDTH_8)
		return 0xffULL;
	if (width == ARM64_WIDTH_16)
		return 0xffffULL;
	if (width == ARM64_WIDTH_32)
		return 0xffffffffULL;
	return 0xffffffffffffffffULL;
}

/* The independent 3-way slot-tag action selection: the qword write and tag
 * store exactly when the access is 64-bit and the slot is 8-aligned, the
 * aligned tag clear and byte-ladder write at every aligned sub-qword access,
 * and the plain byte write otherwise. Restated from the raw facts with no
 * reference to the generated selector. */
static unsigned model_action(unsigned w64, unsigned aligned)
{
	if (w64 && aligned)
		return 0;
	if (aligned)
		return 1;
	return 2;
}

static void fill_pattern(void)
{
	unsigned long i;

	for (i = 0; i < (unsigned long)ARM64_SIM_STACK_BYTES; i++) {
		__u8 v = (__u8)((i * 37UL + 11UL) & 0xffUL);

		__a64_stack.b[i] = v;
		model_b[i] = v;
	}
	for (i = 0;
	     i < sizeof(model_tag); i++) {
		__u8 v = (__u8)((i * 13UL + 5UL) & 0xffUL);

		__a64_stack_tag[i] = v;
		model_tag[i] = v;
	}
}

static void check_image(const char *what)
{
	unsigned long i;

	for (i = 0; i < (unsigned long)ARM64_SIM_STACK_BYTES; i++) {
		cases++;
		if (__a64_stack.b[i] != model_b[i]) {
			printf("MISMATCH %s byte %lu: got=%u want=%u\n", what,
			       i, __a64_stack.b[i], model_b[i]);
			failures++;
		}
	}
}

static void check_tags(const char *what)
{
	unsigned long i;

	for (i = 0;
	     i < sizeof(model_tag); i++) {
		cases++;
		if (__a64_stack_tag[i] != model_tag[i]) {
			printf("MISMATCH %s tag slot %lu: got=%u want=%u\n",
			       what, i, __a64_stack_tag[i], model_tag[i]);
			failures++;
		}
	}
}

/* Byte intervals state the mutation independently of production's byte ladder
 * and selector. Untouched bytes and word tags must remain unchanged. */
static void model_write(__s64 off, __u32 width, __u64 value, __u8 tag)
{
	__u32 idx = ref_index(off);
	unsigned n = width_bytes(width);
	unsigned k;

	for (k = 0; k < n; k++)
		model_b[idx + k] = (__u8)(value >> (8 * k));
	host_stack_store_tags(model_tag, idx, n, tag);
}

/* The generated selector must name the same action the independent 3-way
 * statement names, at every fact pair and at every width code the helper
 * feeds it. */
static void check_selector(void)
{
	static const __u32 widths[] = { ARM64_WIDTH_8, ARM64_WIDTH_16,
					ARM64_WIDTH_32, ARM64_WIDTH_64 };
	unsigned wi;
	unsigned w64;
	unsigned aligned;

	cases++;
	if (KPROG_ARM64_STACK_WRITE_TAG_ACTION_COUNT != 3U) {
		printf("MISMATCH action count got=%u want=3\n",
		       (unsigned)KPROG_ARM64_STACK_WRITE_TAG_ACTION_COUNT);
		failures++;
	}

	for (w64 = 0; w64 <= 1U; w64++) {
		for (aligned = 0; aligned <= 1U; aligned++) {
			cases++;
			if (KPROG_ARM64_STACK_WRITE_TAG_ACTION(w64, aligned) !=
			    model_action(w64, aligned)) {
				printf("MISMATCH gate w64=%u aligned=%u got=%u\n",
				       w64, aligned,
				       KPROG_ARM64_STACK_WRITE_TAG_ACTION(
						   w64, aligned));
				failures++;
			}
		}
	}

	for (wi = 0; wi < sizeof(widths) / sizeof(widths[0]); wi++) {
		for (aligned = 0; aligned <= 1U; aligned++) {
			unsigned w64f = (widths[wi] == ARM64_WIDTH_64);

			cases++;
			if (KPROG_ARM64_STACK_WRITE_TAG_ACTION(w64f, aligned) !=
			    model_action(w64f, aligned)) {
				printf("MISMATCH gate width=%u aligned=%u "
				       "got=%u\n",
				       widths[wi], aligned,
				       KPROG_ARM64_STACK_WRITE_TAG_ACTION(
					       w64f, aligned));
				failures++;
			}
		}
	}
}

/* Drive the real tagged write at one offset/width/value/tag and compare the
 * whole byte image and the whole tag array, then read the value back through
 * the real read helper. */
static void drive_tag_write(__s64 off, __u32 width, __u64 value, __u8 tag)
{
	__u64 got;

	fill_pattern();
	ARM64_SIM_L_STACK_WRITE_TAG(off, width, value, tag);
	model_write(off, width, value, tag);
	check_image("write");
	check_tags("write");

	got = ARM64_SIM_L_STACK_READ(off, width);
	cases++;
	if (got != (value & model_mask(width))) {
		printf("MISMATCH roundtrip off=%lld width=%u got=%llu "
		       "want=%llu\n",
		       off, width, got, value & model_mask(width));
		failures++;
	}
}

/* Drive the plain write wrapper (the caller's tag is the scalar marker) and
 * compare byte image, tag array, and the read-back. */
static void drive_write(__s64 off, __u32 width, __u64 value)
{
	__u64 got;

	fill_pattern();
	ARM64_SIM_L_STACK_WRITE(off, width, value);
	model_write(off, width, value, ARM64_SIM_TAG_SCALAR);
	check_image("write");
	check_tags("write");

	got = ARM64_SIM_L_STACK_READ(off, width);
	cases++;
	if (got != (value & model_mask(width))) {
		printf("MISMATCH roundtrip off=%lld width=%u got=%llu "
		       "want=%llu\n",
		       off, width, got, value & model_mask(width));
		failures++;
	}
}

int main(void)
{
    struct host_guarded_memory guarded=host_guarded_memory(ARM64_SIM_STACK_BYTES);
    host_stack=(volatile host_stack_arena *)guarded.data;
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
	    sizeof(__a64_stack_tag) != sizeof(model_tag)) {
		printf("MISMATCH layout: b=%lu q=%lu tag=%lu\n",
		       (unsigned long)sizeof(__a64_stack.b),
		       (unsigned long)sizeof(__a64_stack.q),
		       (unsigned long)sizeof(__a64_stack_tag));
		failures++;
	}

	check_selector();

	/* Keep the exhaustive offset/width/value/tag sweep, including every
	 * crossing of a word boundary and both arena edges. */
	for (t = 0; t < sizeof(tags) / sizeof(tags[0]); t++) {
		for (p = 0; p < sizeof(patterns) / sizeof(patterns[0]); p++) {
			for (wi = 0; wi < sizeof(widths) / sizeof(widths[0]);
			     wi++) {
				__u32 width = widths[wi];
				long n = (long)width_bytes(width);

				for (off = -(long)ARM64_SIM_STACK_BIAS;
				     (long)ARM64_SIM_STACK_BIAS + off + n <=
				     (long)ARM64_SIM_STACK_BYTES;
				     off++) {
					drive_tag_write(off, width, patterns[p],
							tags[t]);
					drive_write(off, width, patterns[p]);
				}
			}
		}
	}

	/* A fixed-seed sweep over offsets, widths, and values through the
	 * plain write wrapper. */
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

    if (unsupported_calls) {
        printf("MISMATCH unexpected unsupported callback: %u\n",unsupported_calls);
        failures+=(int)unsupported_calls;
    }
    {
        struct memory_access past[] = {{64,ARM64_WIDTH_64,0},{64,ARM64_WIDTH_64,1}};
        for (unsigned i=0;i<sizeof(past)/sizeof(past[0]);i++) {
            cases++;
            if (!host_memory_fault(access_boundary,&past[i])) {
                printf("MISMATCH out-of-range %s width=%u did not fault\n",
                    past[i].is_write?"write":"read",past[i].width);
                failures++;
            }
        }
    }
    host_guarded_memory_free(guarded);

	if (failures) {
		printf("arm64 stack write tag action route host cross-check: "
		       "FAIL (%d)\n", failures);
		return 1;
	}
	printf("arm64 stack write tag action route host cross-check: OK "
	       "(%lu cases)\n", cases);
	return 0;
}
