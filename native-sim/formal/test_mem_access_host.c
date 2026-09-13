/*
 * Host cross-check for the generated x86 little-endian memory contract.
 *
 * Verifies KPROG_X86_MEM_LOAD / KPROG_X86_MEM_STORE from
 * generated/x86_mem_access.h against an independent byte-level oracle:
 *   - load: value == sum over i of byte[i] << (8*i), for the access width
 *   - store: after the store, memory[j] == (value >> (8*j)) & 0xff for j
 *            below the width, and bytes at or above the width are untouched
 * Runs explicit boundary vectors plus a fixed-seed random sweep over all four
 * legal widths. Exits non-zero on any mismatch.
 *
 * Build/run:
 *   cd native-sim/formal
 *   cc -Wall -Wextra -O2 -I. test_mem_access_host.c -o /tmp/t_mem && /tmp/t_mem
 */
typedef unsigned char __u8;
typedef unsigned long long __u64;

#define X86_WIDTH_8 1U
#define X86_WIDTH_16 2U
#define X86_WIDTH_32 4U
#define X86_WIDTH_64 8U

#include "generated/x86_width.h"
#include "generated/x86_mem_access.h"

#include <stdio.h>
#include <string.h>

static unsigned width_bytes(unsigned width)
{
	switch (width) {
	case X86_WIDTH_8:
		return 1;
	case X86_WIDTH_16:
		return 2;
	case X86_WIDTH_32:
		return 4;
	default:
		return 8;
	}
}

/* Independent little-endian load oracle over a 16-byte scratch buffer. */
static __u64 oracle_load(const __u8 *mem, unsigned width)
{
	unsigned n = width_bytes(width);
	__u64 v = 0;

	for (unsigned i = 0; i < n; i++)
		v |= (__u64)mem[i] << (8 * i);
	return v;
}

static int check_load(const __u8 *mem, unsigned width)
{
	__u64 want = oracle_load(mem, width);
	__u64 got = KPROG_X86_MEM_LOAD(mem, width);

	if (got != want) {
		printf("MISMATCH load w=%u got=%#llx want=%#llx mem=%02x%02x%02x%02x%02x%02x%02x%02x\n",
		       width, got, want, mem[7], mem[6], mem[5], mem[4],
		       mem[3], mem[2], mem[1], mem[0]);
		return 1;
	}
	return 0;
}

static int check_store(__u64 value, unsigned width)
{
	__u8 mem[16];
	__u8 ref[16];
	unsigned n = width_bytes(width);
	unsigned bad = 0;

	memset(mem, 0xa5, sizeof(mem));
	memset(ref, 0xa5, sizeof(ref));
	KPROG_X86_MEM_STORE(mem, width, value);
	for (unsigned i = 0; i < n; i++)
		ref[i] = (__u8)(value >> (8 * i));
	if (memcmp(mem, ref, sizeof(mem)) != 0)
		bad = 1;
	/* A load of what we just stored must reproduce the width-masked value. */
	if (KPROG_X86_MEM_LOAD(mem, width) != oracle_load(ref, width))
		bad = 1;
	if (bad) {
		printf("MISMATCH store w=%u value=%#llx\n", width, value);
		return 1;
	}
	return 0;
}

int main(void)
{
	static const __u8 vectors[][8] = {
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		{0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff},
		{0x78, 0x56, 0x34, 0x12, 0x00, 0x00, 0x00, 0x00},
		{0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef},
		{0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80},
	};
	static const unsigned widths[4] = {X86_WIDTH_8, X86_WIDTH_16,
					   X86_WIDTH_32, X86_WIDTH_64};
	unsigned cases = 0;
	unsigned fails = 0;

	for (unsigned v = 0; v < sizeof(vectors) / sizeof(vectors[0]); v++)
		for (unsigned w = 0; w < 4; w++) {
			fails += check_load(vectors[v], widths[w]);
			cases++;
		}

	/* Fixed-seed LCG sweep: random bytes, random values, all widths. */
	__u64 state = 0x12345678ULL;
	for (unsigned iter = 0; iter < 20000; iter++) {
		__u8 mem[8];
		for (unsigned i = 0; i < 8; i++) {
			state = state * 6364136223846793005ULL + 1442695040888963407ULL;
			mem[i] = (__u8)(state >> 33);
		}
		unsigned width = widths[iter & 3];
		fails += check_load(mem, width);
		fails += check_store(state, width);
		cases += 2;
	}

	if (fails) {
		printf("x86 memory-access host cross-check: FAILED (%u mismatches)\n", fails);
		return 1;
	}
	printf("x86 memory-access host cross-check: OK (%u cases)\n", cases);
	return 0;
}
