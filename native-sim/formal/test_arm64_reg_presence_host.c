/*
 * Host cross-check for the generated AArch64 write-register destination-presence
 * contract (STEP 0103).
 *
 * `KPROG_ARM64_REG_WRITABLE(REG)` decides whether a decoded AArch64 register
 * number names a destination a write lands in: the zero register `31`
 * (`ARM64_XZR`) and the no-register sentinel `0xff` (`ARM64_REG_NONE`) both
 * discard the write, every other number is a GPR. `KPROG_ARM64_REG_CLASS(REG)`
 * names the class. `KProgFormal/Arm64RegPresence.lean` proves the presence
 * predicate equals an independent `decide (reg != 31 && reg != 0xff)` and that
 * the sentinel is the memory-index sentinel.
 *
 * This oracle includes only the generated header, drives the presence and class
 * macros over the full byte range plus both boundaries and their neighbours,
 * and compares against an independent `reg != 31 && reg != 0xff` test and the
 * class code table. Exit 1 on mismatch.
 *
 * Build/run:
 *   cd native-sim/formal
 *   cc -Wall -Wextra -O2 -I. test_arm64_reg_presence_host.c -o /tmp/t_arp
 *   /tmp/t_arp
 */
typedef unsigned char __u8;
typedef unsigned int __u32;

#include "generated/arm64_reg_presence.h"

#include <stdio.h>

static int failures;

int main(void)
{
	unsigned long cases = 0;
	__u32 byte;

	for (byte = 0; byte <= 0xffU; byte++) {
		__u8 reg = (__u8)byte;
		__u8 want_writable =
			(reg != 31U && reg != 0xffU) ? 1U : 0U;
		__u8 want_class = reg == 31U ? KPROG_ARM64_REG_CLASS_ZERO
				  : reg == 0xffU ? KPROG_ARM64_REG_CLASS_NONE
						 : KPROG_ARM64_REG_CLASS_GPR;
		__u8 got_writable = KPROG_ARM64_REG_WRITABLE(reg);
		__u8 got_class = KPROG_ARM64_REG_CLASS(reg);

		cases++;
		if (got_writable != want_writable) {
			printf("MISMATCH writable reg=%u got=%u want=%u\n",
			       byte, got_writable, want_writable);
			failures++;
		}
		cases++;
		if (got_class != want_class) {
			printf("MISMATCH class reg=%u got=%u want=%u\n",
			       byte, got_class, want_class);
			failures++;
		}
		if (got_writable !=
		    (got_class == KPROG_ARM64_REG_CLASS_GPR)) {
			printf("MISMATCH class/writable disagree reg=%u\n", byte);
			failures++;
		}
	}

	if (KPROG_ARM64_REG_XZR != 31U) {
		printf("MISMATCH zero-register value %u\n",
		       (unsigned)KPROG_ARM64_REG_XZR);
		failures++;
	}
	if (KPROG_ARM64_REG_NONE != 0xffU) {
		printf("MISMATCH sentinel value %u\n",
		       (unsigned)KPROG_ARM64_REG_NONE);
		failures++;
	}

	if (failures != 0) {
		printf("arm64 reg presence host cross-check: FAIL (%d)\n",
		       failures);
		return 1;
	}
	printf("arm64 reg presence host cross-check: OK (%lu cases)\n", cases);
	return 0;
}
