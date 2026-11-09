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

/* This storage-geometry fixture allocates the arena and its guard windows. */
#define ARM64_SIM_L_STACK_SP() (-(__s64)ARM64_SIM_STACK_BIAS - 64)
#include "../arm64/arm64_sim_local_bpf.h"

#include <stdio.h>
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
/* Private metadata accompanies the manually planted zero-origin arena. */
static __u64 __a64_stack_payload[KPROG_ARM64_STACK_WORDS(ARM64_SIM_STACK_BYTES)];
static __u64 __a64_stack_scalar_payload[ARM64_SIM_STACK_SCALAR_PAYLOAD_WORDS];
static __u64 __a64_stack_scalar_valid[(ARM64_SIM_STACK_SCALAR_PAYLOAD_WORDS + 63U) / 64U];
static __u64 __a64_numeric_sp, __a64_numeric_return;
static __u8 __a64_numeric_sp_valid, __a64_numeric_return_valid;
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

	for (i = 0; i < sizeof(__a64_stack_scalar_valid) / sizeof(__a64_stack_scalar_valid[0]); i++)
		__a64_stack_scalar_valid[i] = 0;

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
    struct host_guarded_memory guarded=host_guarded_memory(ARM64_SIM_STACK_BYTES);
    host_stack=(volatile host_stack_arena *)guarded.data;
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

	/* A valid-width stack access must not invoke an unsupported opcode. */
	if (unsupported_calls) {
		printf("MISMATCH unsupported opcode callback reached %u time(s)\n",
		       unsupported_calls);
		failures += (int)unsupported_calls;
	}

    /* An unmapped window must cause the real access to fault. Returning a
     * synthetic zero or skipping a write would fail these boundary cases. */
    {
        struct memory_access past[] = {{64,ARM64_WIDTH_64,0},{64,ARM64_WIDTH_64,1}};
        for (unsigned i=0;i<sizeof(past)/sizeof(past[0]);i++) {
            cases++;
            if (!host_memory_fault(access_boundary,&past[i])) {
                printf("MISMATCH unmapped %s width=%u did not fault\n",
                    past[i].is_write?"write":"read",past[i].width);
                failures++;
            }
        }
    }
    host_guarded_memory_free(guarded);

	if (failures) {
		printf("arm64 stack arm route host cross-check: FAIL (%d)\n",
		       failures);
		return 1;
	}
	printf("arm64 stack arm route host cross-check: OK (%lu cases)\n",
	       cases);
	return 0;
}
