/*
 * Host cross-check for the AArch64 stack-arena storage-model contract
 * (generated/arm64_stack_arena.h from generate_arm64_stack_arena_spec.py).
 *
 * The AArch64 stack arena is a union of two overlapping views
 * (native-sim/arm64/arm64_sim_local_bpf.h):
 *
 *   union {
 *       __u8  b[ARM64_SIM_STACK_BYTES];
 *       __u64 q[KPROG_ARM64_STACK_WORDS(ARM64_SIM_STACK_BYTES)];
 *   } __a64_stack;
 *
 * `ARM64_SIM_L_STACK_READ` / `_WRITE_TAG` use the word view `q[INDEX >> 3]` on
 * the 64-bit path only when the index is word-aligned, and otherwise
 * split/reassemble a 64-bit value byte by byte through `b[]` using the
 * generated AArch64 byte-lane contract (`KPROG_ARM64_BYTE_AT`). The generator
 * binds the slot / alignment / slot-count arithmetic as macros.
 *
 * This oracle drives the *generated* macros and compares them, over a grid of
 * capacities, aligned and unaligned byte indices, and word values, against
 * independent restatements:
 *   - the word slot / alignment guard against `index / 8` and `index % 8`;
 *   - the byte lane against a shift/mask reconstruction of the same word, so a
 *     64-bit value written through the word view and read back byte-by-byte
 *     through the byte view (and vice versa) is the same value;
 *   - the word-slot count against the round-up (`words*8 >= capacity` and, for
 *     a non-empty arena, `(words-1)*8 <= capacity-1`).
 * Exit 1 on any mismatch.
 *
 * Build/run:
 *   cd native-sim/formal
 *   cc -Wall -Wextra -O2 -I. test_arm64_stack_arena_host.c -o /tmp/t_asa && /tmp/t_asa
 */
typedef unsigned char __u8;
typedef unsigned int __u32;
typedef unsigned long long __u64;

#include "generated/arm64_stack_arena.h"
#include "generated/arm64_byte_lane.h"

#include <stdio.h>

static int failures;
static int cases;

#define LANE_BYTE(lane, value) KPROG_ARM64_BYTE_AT(lane, value, __builtin_trap())

static void check_slot(const char *what, __u32 index, __u32 want_slot,
		       int want_aligned)
{
	__u32 slot = KPROG_ARM64_STACK_WORD_INDEX(index);
	int aligned = KPROG_ARM64_STACK_WORD_ALIGNED(index);
	__u32 indep_slot = index / 8U;
	int indep_aligned = (index % 8U) == 0U;

	cases++;
	if (slot != want_slot || slot != indep_slot) {
		printf("MISMATCH %s slot: index=%u got=%u indep=%u want=%u\n",
		       what, index, slot, indep_slot, want_slot);
		failures++;
	}
	if (aligned != want_aligned || aligned != indep_aligned) {
		printf("MISMATCH %s align: index=%u got=%d indep=%d want=%d\n",
		       what, index, aligned, indep_aligned, want_aligned);
		failures++;
	}
	/* An aligned slot shifted back is the original index. */
	if (aligned && (slot << 3) != index) {
		printf("MISMATCH %s roundtrip: index=%u slot=%u\n", what, index,
		       slot);
		failures++;
	}
}

static void check_words(const char *what, __u32 capacity)
{
	__u32 words = KPROG_ARM64_STACK_WORDS(capacity);
	__u32 indep = (capacity + 7U) / 8U;

	cases++;
	if (words != indep) {
		printf("MISMATCH %s words: capacity=%u got=%u indep=%u\n", what,
		       capacity, words, indep);
		failures++;
	}
	/* Every capacity byte is reachable inside the rounded-up word array. */
	if (words * 8U < capacity) {
		printf("MISMATCH %s coverage: capacity=%u words=%u\n", what,
		       capacity, words);
		failures++;
	}
	/* A non-empty arena wastes no whole slot. */
	if (capacity > 0U && (words - 1U) * 8U > capacity - 1U) {
		printf("MISMATCH %s tightness: capacity=%u words=%u\n", what,
		       capacity, words);
		failures++;
	}
}

static void check_word_roundtrip(const char *what, __u64 value)
{
	__u8 bytes[8];
	__u64 reassembled = 0;
	int k;

	for (k = 0; k < 8; k++) {
		bytes[k] = LANE_BYTE(k, value);
		cases++;
		if (bytes[k] != (__u8)((value >> (8 * k)) & 0xffU)) {
			printf("MISMATCH %s byte: value=%llu k=%d got=%u\n", what,
			       value, k, bytes[k]);
			failures++;
		}
		reassembled |= (__u64)bytes[k] << (8 * k);
	}
	cases++;
	if (reassembled != value) {
		printf("MISMATCH %s assemble: value=%llu got=%llu\n", what, value,
		       reassembled);
		failures++;
	}
	/* The fast-path word and the byte-path reconstruction agree: reading
	 * byte `k` back out of the reassembled word yields the byte that was
	 * placed at offset `k`. */
	for (k = 0; k < 8; k++) {
		cases++;
		if (LANE_BYTE(k, reassembled) != bytes[k]) {
			printf("MISMATCH %s view-aliasing: value=%llu k=%d got=%u want=%u\n",
			       what, value, k, LANE_BYTE(k, reassembled),
			       bytes[k]);
			failures++;
		}
	}
}

static void check_arena_roundtrip(const char *what, __u32 capacity)
{
	union {
		__u8 b[256];
		__u64 q[32];
	} arena;
	__u32 words = KPROG_ARM64_STACK_WORDS(capacity);
	__u32 index;
	int k;

	if (capacity == 0U || capacity > (__u32)sizeof(arena.b)) {
		return;
	}
	for (k = 0; k < (int)sizeof(arena.b); k++)
		arena.b[k] = 0;
	/* Fill every byte, then check the word view sees the same bytes. */
	for (index = 0; index < capacity; index++)
		arena.b[index] = (__u8)(index * 31U + 7U);
	for (index = 0; index < words; index++) {
		__u64 word = arena.q[index];

		for (k = 0; k < 8; k++) {
			unsigned long byte_off =
				(unsigned long)index * 8U + (unsigned long)k;
			__u8 want = byte_off < capacity ? arena.b[byte_off] : 0;

			cases++;
			if (LANE_BYTE(k, word) != want) {
				printf("MISMATCH %s aliasing: cap=%u word=%u k=%d got=%u want=%u\n",
				       what, capacity, index, k, LANE_BYTE(k, word),
				       want);
				failures++;
			}
		}
	}
	/* Aligned byte index -> slot -> back is the identity, and the word
	 * stored at that slot is the little-endian window of arena bytes. */
	for (index = 0; index + 8 <= capacity; index += 8) {
		__u32 slot = KPROG_ARM64_STACK_WORD_INDEX(index);
		__u64 via_word = arena.q[slot];
		__u64 via_bytes = 0;

		for (k = 0; k < 8; k++)
			via_bytes |= (__u64)arena.b[index + k] << (8 * k);
		cases++;
		if (via_word != via_bytes || (slot << 3) != index) {
			printf("MISMATCH %s word-window: cap=%u index=%u slot=%u\n",
			       what, capacity, index, slot);
			failures++;
		}
	}
}

int main(void)
{
	static const __u32 capacities[] = { 1U, 2U, 7U, 8U, 16U, 20U, 160U };
	static const __u32 indices[] = {
		0U, 1U, 7U, 8U, 9U, 15U, 16U, 96U, 104U, 159U, 160U, 2147483647U,
		4294967288U, 4294967295U
	};
	static const __u64 values[] = {
		0x0ULL, 0x1ULL, 0xffULL, 0x0123456789abcdefULL,
		0xfedcba9876543210ULL, 0xffffffffffffffffULL, 0x00000000ffffffffULL,
		0xffffffff00000000ULL
	};
	unsigned long i, j;

	for (i = 0; i < sizeof(indices) / sizeof(indices[0]); i++) {
		__u32 index = indices[i];

		check_slot("grid", index, index / 8U, (index % 8U) == 0U);
	}
	for (i = 0; i < sizeof(capacities) / sizeof(capacities[0]); i++)
		check_words("grid", capacities[i]);
	for (i = 0; i < sizeof(values) / sizeof(values[0]); i++)
		check_word_roundtrip("grid", values[i]);
	for (i = 0; i < sizeof(capacities) / sizeof(capacities[0]); i++)
		check_arena_roundtrip("arena", capacities[i]);

	/* Exhaustive over the first 256 byte indices and capacities. */
	for (i = 0; i < 256U; i++)
		check_slot("exh", (__u32)i, (__u32)(i / 8U), (i % 8U) == 0U);
	for (i = 0; i < 256U; i++)
		check_words("exh", (__u32)i);
	for (i = 0; i < 64U; i++)
		for (j = 0; j < 64U; j++)
			check_word_roundtrip("exh", ((__u64)i << 32) | (__u64)j);

	if (failures) {
		printf("arm64 stack arena host cross-check: FAIL (%d/%d)\n", failures,
		       cases);
		return 1;
	}
	printf("arm64 stack arena host cross-check: OK (%d cases)\n", cases);
	return 0;
}
