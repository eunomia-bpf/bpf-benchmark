/*
 * Host cross-check for the AArch64 simulator's routing of its store helper's
 * body choice through the machine-checked byte-ladder store contract (STEP
 * 0122): the generated `generated/arm64_store_bytes.h`.
 *
 * The macro under test is the real simulator macro `ARM64_SIM_L_MEM_WRITE`,
 * declared by including the real header `../arm64/arm64_sim_local_bpf.h`. A
 * scalar base register routes the write to its memory arm, which selects between
 * the four store widths from a closed set; this oracle drives the simulator's
 * write over a deterministic heap byte image while an independent byte-pointer
 * model (never the macro's ladder) scatters the width's low bytes little-endian
 * and leaves every byte above the width untouched. The simulator's write must
 * equal the model byte for byte; a helper routed to the wrong width — a
 * truncated or over-wide window — diverges from the model. The store is then
 * read back through the real load path to close the round trip.
 *
 * Build and run:
 *   cd kprog/formal &&
 *   cc -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog \
 *      -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *      test_arm64_store_bytes_route_host.c -o build/test_arm64_store_bytes_route_host &&
 *   ./build/test_arm64_store_bytes_route_host
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
#include <string.h>

static void arm64_sim_unsupported_opcode(void)
{
}

static int failures;
static unsigned long cases;

#define HEAP_BYTES 4096U
#define BASE_OFF 2048U
static __u8 heap[HEAP_BYTES];
static __u8 model[HEAP_BYTES];

static unsigned width_bytes(unsigned width)
{
	if (width == ARM64_WIDTH_8)
		return 1;
	if (width == ARM64_WIDTH_16)
		return 2;
	if (width == ARM64_WIDTH_32)
		return 4;
	return 8;
}

/* Independent model: scatter `value & width_mask` as the width's low bytes,
 * never touching a byte above the width. */
static void model_store(__u8 *base, unsigned width, __u64 value)
{
	__u64 v = value;
	int n = width_bytes(width);
	int i;

	if (n < 8)
		v &= (1ULL << (8 * n)) - 1ULL;
	for (i = 0; i < n; i++)
		base[i] = (__u8)(v >> (8 * i));
}

static void fill_images(void)
{
	unsigned i;

	for (i = 0; i < HEAP_BYTES; i++)
		heap[i] = model[i] = (__u8)(0x30U + i * 7U + (i >> 3));
}

/* Drive the real write at one width/value and compare the whole heap image. */
static void drive_store(unsigned width, __u64 value)
{
	ARM64_SIM_L_DECLARE_STATE();
	ARM64_SIM_L_DECLARE_STACK();
	unsigned i;

	(void)__a64_sp;
	(void)__a64_n;
	(void)__a64_z;
	(void)__a64_c;
	(void)__a64_v;
	(void)__a64_lr;
	(void)__a64_v0;
	(void)__a64_v0_hi;
	(void)__a64_stack;
	(void)__a64_stack_tag;

	fill_images();

	ARM64_SIM_L_WRITE_REG_PTR_TAG(ARM64_X2,
				      (void *)(long)(heap + BASE_OFF),
				      ARM64_SIM_TAG_SCALAR);

	model_store(model + BASE_OFF, width, value);
	ARM64_SIM_L_MEM_WRITE(ARM64_X2, ARM64_REG_NONE, 0U, 0, 0, width,
			      value, ARM64_SIM_TAG_SCALAR);

	for (i = 0; i < HEAP_BYTES; i++) {
		cases++;
		if (heap[i] != model[i]) {
			printf("MISMATCH width=%u value=%#llx byte %u: "
			       "got=%02x want=%02x\n",
			       width, value, i, heap[i], model[i]);
			failures++;
			return;
		}
	}
}

/* Store through the real write, read back through the real load: the covered
 * window must round-trip at every width. */
static void drive_roundtrip(unsigned width, __u64 value)
{
	ARM64_SIM_L_DECLARE_STATE();
	ARM64_SIM_L_DECLARE_STACK();
	unsigned n = width_bytes(width);
	__u64 mask = n == 8 ? ~0ULL : (1ULL << (8 * n)) - 1ULL;
	__u64 got;

	(void)__a64_sp;
	(void)__a64_n;
	(void)__a64_z;
	(void)__a64_c;
	(void)__a64_v;
	(void)__a64_lr;
	(void)__a64_v0;
	(void)__a64_v0_hi;
	(void)__a64_stack;
	(void)__a64_stack_tag;

	fill_images();
	ARM64_SIM_L_WRITE_REG_PTR_TAG(ARM64_X2,
				      (void *)(long)(heap + BASE_OFF),
				      ARM64_SIM_TAG_SCALAR);
	ARM64_SIM_L_MEM_WRITE(ARM64_X2, ARM64_REG_NONE, 0U, 0, 0, width,
			      value, ARM64_SIM_TAG_SCALAR);

	got = ARM64_SIM_L_MEM_READ(ARM64_X2, ARM64_REG_NONE, 0U, 0, 0, width);
	cases++;
	if (got != (value & mask)) {
		printf("MISMATCH roundtrip width=%u value=%#llx got=%#llx "
		       "want=%#llx\n", width, value, got, value & mask);
		failures++;
	}
}

int main(void)
{
	static const unsigned widths[] = { ARM64_WIDTH_8, ARM64_WIDTH_16,
					   ARM64_WIDTH_32, ARM64_WIDTH_64 };
	static const __u64 patterns[] = {
		0x0000000000000000ULL,
		0xffffffffffffffffULL,
		0x0123456789abcdefULL,
		0x80c0402000100804ULL,
		0x0408102040c08001ULL,
		0xff00ff00ff00ff00ULL,
	};
	__u64 state = 0x9a2f5c81e4b70d36ULL;
	unsigned w, p, iter;

	for (p = 0; p < sizeof(patterns) / sizeof(patterns[0]); p++)
		for (w = 0; w < sizeof(widths) / sizeof(widths[0]); w++) {
			drive_store(widths[w], patterns[p]);
			drive_roundtrip(widths[w], patterns[p]);
		}

	for (iter = 0; iter < 4000; iter++) {
		state = state * 6364136223846793005ULL +
			1442695040888963407ULL;
		w = iter % 4U;
		drive_store(widths[w], state);
		drive_roundtrip(widths[w], state);
	}

	if (failures) {
		printf("arm64 store bytes route host cross-check: FAIL (%d)\n",
		       failures);
		return 1;
	}
	printf("arm64 store bytes route host cross-check: OK (%lu cases)\n",
	       cases);
	return 0;
}
