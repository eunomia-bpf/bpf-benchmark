/*
 * Host cross-check for the generated AArch64 memory-index presence contract
 * (STEP 0102).
 *
 * `KPROG_ARM64_MEM_INDEX_PRESENT(INDEX_BYTE)` decides whether an addressing-mode
 * `AUX` index lane carries an index register from its low byte: the sentinel
 * `0xff` (`ARM64_REG_NONE`) is the absent arm and every other byte names an
 * index register. `KProgFormal/Arm64MemIndex.lean` proves the presence predicate
 * equals an independent `decide (indexByte != 0xff)` and that the sentinel is
 * the `GeneratedArm64Aux.regNone` lane value.
 *
 * This oracle includes only the generated header, drives the presence and arm
 * macros over the full byte range plus the sentinel and its immediate
 * neighbours, and compares against an independent `index_byte != 0xff` test and
 * the arm code table. Exit 1 on mismatch.
 *
 * Build/run:
 *   cd native-sim/formal
 *   cc -Wall -Wextra -O2 -I. test_arm64_mem_index_host.c -o /tmp/t_ami && /tmp/t_ami
 */
typedef unsigned char __u8;
typedef unsigned int __u32;

#include "generated/arm64_mem_index.h"

#include <stdio.h>

static int failures;

int main(void)
{
	unsigned long cases = 0;
	__u32 byte;

	for (byte = 0; byte <= 0xffU; byte++) {
		__u8 index_byte = (__u8)byte;
		__u8 want_present = index_byte != 0xffU ? 1U : 0U;
		__u8 got_present = KPROG_ARM64_MEM_INDEX_PRESENT(index_byte);
		__u8 want_arm = want_present ? KPROG_ARM64_MEM_INDEX_ARM_PRESENT
					     : KPROG_ARM64_MEM_INDEX_ARM_ABSENT;
		__u8 got_arm = KPROG_ARM64_MEM_INDEX_ARM(index_byte);

		cases++;
		if (got_present != want_present) {
			printf("MISMATCH present byte=%u got=%u want=%u\n",
			       byte, got_present, want_present);
			failures++;
		}
		cases++;
		if (got_arm != want_arm) {
			printf("MISMATCH arm byte=%u got=%u want=%u\n",
			       byte, got_arm, want_arm);
			failures++;
		}
		if (got_present !=
		    (got_arm == KPROG_ARM64_MEM_INDEX_ARM_PRESENT)) {
			printf("MISMATCH arm/present disagree byte=%u\n", byte);
			failures++;
		}
	}

	if (KPROG_ARM64_MEM_INDEX_SENTINEL != 0xffU) {
		printf("MISMATCH sentinel value %u\n",
		       (unsigned)KPROG_ARM64_MEM_INDEX_SENTINEL);
		failures++;
	}

	if (failures != 0) {
		printf("arm64 mem index host cross-check: FAIL (%d)\n", failures);
		return 1;
	}
	printf("arm64 mem index host cross-check: OK (%lu cases)\n", cases);
	return 0;
}
