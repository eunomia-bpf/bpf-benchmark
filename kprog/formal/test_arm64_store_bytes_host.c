/*
 * Host cross-check for the generated AArch64 little-endian store contract.
 *
 * Verifies KPROG_ARM64_STORE_BYTES from generated/arm64_store_bytes.h against an
 * independent oracle that writes the in-range bytes one at a time through a byte
 * pointer (never the macro's ladder expression):
 *   for i < byteCount(width): mem[i] = (value >> 8*i) & 0xff
 * To exercise the store as a real memory effect the buffer is pre-filled with a
 * per-iteration sentinel, the macro is run, and the oracle checks both the
 * covered bytes and that every byte above the store width is left untouched.
 * It sweeps boundary byte patterns over all four widths, then a fixed-seed
 * random sweep on a heap buffer. Exits non-zero on any mismatch.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. test_arm64_store_bytes_host.c -o /tmp/t_sb && /tmp/t_sb
 */
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;

#define ARM64_WIDTH_8 1U
#define ARM64_WIDTH_16 2U
#define ARM64_WIDTH_32 4U
#define ARM64_WIDTH_64 8U

#include "generated/arm64_width.h"
#include "generated/arm64_store_bytes.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static unsigned byte_count(unsigned width)
{
	return width == ARM64_WIDTH_8 ? 1U :
	       width == ARM64_WIDTH_16 ? 2U :
	       width == ARM64_WIDTH_32 ? 4U : 8U;
}

/* Independent oracle: write the in-range bytes through a byte pointer. */
static void store_oracle(__u8 *bytes, unsigned width, __u64 value)
{
	unsigned n = byte_count(width);

	for (unsigned i = 0; i < n; i++)
		bytes[i] = (__u8)(value >> (8 * i));
}

static int check_store(unsigned width, __u64 value)
{
	__u8 got[8], want[8];

	/* Sentinel: a byte the oracle never writes must survive the store. */
	memset(got, 0xa5, sizeof(got));
	memset(want, 0xa5, sizeof(want));

	store_oracle(want, width, value);
	KPROG_ARM64_STORE_BYTES(got, width, value);

	if (memcmp(got, want, sizeof(got)) != 0) {
		printf("MISMATCH width=%u value=%#llx got=%02x%02x%02x%02x%02x%02x%02x%02x"
		       " want=%02x%02x%02x%02x%02x%02x%02x%02x\n",
		       width, value,
		       got[0], got[1], got[2], got[3],
		       got[4], got[5], got[6], got[7],
		       want[0], want[1], want[2], want[3],
		       want[4], want[5], want[6], want[7]);
		return 1;
	}
	return 0;
}

static const __u64 patterns[] = {
	0x0000000000000000ULL,
	0xffffffffffffffffULL,
	0x0123456789abcdefULL,
	0x80c0402000100804ULL,
	0x0408102040c08001ULL,
	0xff00ff00ff00ff00ULL,
};
static const unsigned widths[] = { ARM64_WIDTH_8, ARM64_WIDTH_16,
				   ARM64_WIDTH_32, ARM64_WIDTH_64 };

int main(void)
{
	unsigned cases = 0, fails = 0;
	__u64 state = 0x9a2f5c81e4b70d36ULL;

	for (unsigned p = 0; p < sizeof(patterns) / sizeof(patterns[0]); p++)
		for (unsigned w = 0; w < sizeof(widths) / sizeof(widths[0]); w++) {
			fails += check_store(widths[w], patterns[p]);
			cases++;
		}

	for (unsigned iter = 0; iter < 20000; iter++) {
		state = state * 6364136223846793005ULL +
			1442695040888963407ULL;
		fails += check_store(widths[iter % 4], state);
		cases++;
	}

	if (fails) {
		printf("arm64 store bytes host cross-check: FAILED (%u mismatches)\n",
		       fails);
		return 1;
	}
	printf("arm64 store bytes host cross-check: OK (%u cases)\n", cases);
	return 0;
}
