/*
 * Host cross-check for the generated AArch64 little-endian load contract.
 *
 * Verifies KPROG_ARM64_LOAD_BYTES from generated/arm64_load_bytes.h against an
 * independent oracle that walks the in-range bytes one at a time through a byte
 * pointer (never the macro's ladder expression):
 *   value = sum over i < byteCount(width) of bytes[i] << 8*i
 * It sweeps boundary byte patterns over all four widths, then a fixed-seed
 * random sweep on a heap buffer, and checks that the high bytes above the load
 * width stay zero. Exits non-zero on any mismatch.
 *
 * Build/run:
 *   cd native-sim/formal
 *   cc -Wall -Wextra -O2 -I. test_arm64_load_bytes_host.c -o /tmp/t_lb && /tmp/t_lb
 */
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;

#define ARM64_WIDTH_8 1U
#define ARM64_WIDTH_16 2U
#define ARM64_WIDTH_32 4U
#define ARM64_WIDTH_64 8U

#include "generated/arm64_load_bytes.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static unsigned byte_count(unsigned width)
{
	return width == ARM64_WIDTH_8 ? 1U :
	       width == ARM64_WIDTH_16 ? 2U :
	       width == ARM64_WIDTH_32 ? 4U : 8U;
}

/* Independent oracle: assemble the in-range bytes through a byte pointer. */
static __u64 load_oracle(const __u8 *bytes, unsigned width)
{
	unsigned n = byte_count(width);
	__u64 out = 0;

	for (unsigned i = 0; i < n; i++)
		out += (__u64)bytes[i] << (8 * i);
	return out;
}

static int check_load(const __u8 *bytes, unsigned width)
{
	__u64 res = KPROG_ARM64_LOAD_BYTES(bytes, width);
	__u64 want = load_oracle(bytes, width);
	__u64 high_mask = ~((__u64)0) << (8 * byte_count(width));

	if (res != want) {
		printf("MISMATCH width=%u res=%#llx want=%#llx\n",
		       width, res, want);
		return 1;
	}
	if (byte_count(width) < 8 && (res & high_mask) != 0) {
		printf("MISMATCH width=%u high bytes not cleared: %#llx\n",
		       width, res);
		return 1;
	}
	return 0;
}

static const __u8 patterns[][8] = {
	{ 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff },
	{ 0xef, 0xcd, 0xab, 0x89, 0x67, 0x45, 0x23, 0x01 },
	{ 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80 },
	{ 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01 },
	{ 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff },
};
static const unsigned widths[] = { ARM64_WIDTH_8, ARM64_WIDTH_16,
				   ARM64_WIDTH_32, ARM64_WIDTH_64 };

int main(void)
{
	unsigned cases = 0, fails = 0;
	__u64 state = 0x9a2f5c81e4b70d36ULL;

	for (unsigned p = 0; p < sizeof(patterns) / sizeof(patterns[0]); p++)
		for (unsigned w = 0; w < sizeof(widths) / sizeof(widths[0]); w++) {
			fails += check_load(patterns[p], widths[w]);
			cases++;
		}

	{
		__u8 *buf = malloc(8);
		if (!buf) {
			printf("MISMATCH malloc failed\n");
			return 1;
		}
		for (unsigned iter = 0; iter < 20000; iter++) {
			state = state * 6364136223846793005ULL +
				1442695040888963407ULL;
			memcpy(buf, &state, 8);
			fails += check_load(buf, widths[iter % 4]);
			cases++;
		}
		free(buf);
	}

	if (fails) {
		printf("arm64 load bytes host cross-check: FAILED (%u mismatches)\n",
		       fails);
		return 1;
	}
	printf("arm64 load bytes host cross-check: OK (%u cases)\n", cases);
	return 0;
}
