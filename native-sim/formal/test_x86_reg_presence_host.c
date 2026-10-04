/*
 * Host cross-check for the generated x86-64 operand-register presence contract
 * (STEP 0104).
 *
 * `KPROG_X86_REG_PRESENT(REG)` decides whether a decoded x86-64 register number
 * names an operand register: the sentinel byte `0xff` (`X86_REG_NONE`) names
 * none, every other number a register. `KPROG_X86_REG_ABSENT(REG)` is its
 * complement, and `KPROG_X86_REG_ARM(REG)` names the arm.
 * `KProgFormal/X86RegPresence.lean` proves the presence predicate equals an
 * independent `decide (reg != 0xff)`, pins the sentinel against the memory-index
 * sentinel, and shows both arms are reachable.
 *
 * This oracle includes only the generated header, drives the presence, absence
 * and arm macros over the full byte range plus the sentinel boundary and its
 * neighbours, and compares against an independent `reg != 0xff` test and the arm
 * code table. Exit 1 on mismatch.
 *
 * Build/run:
 *   cd native-sim/formal
 *   cc -Wall -Wextra -O2 -I. test_x86_reg_presence_host.c -o /tmp/t_xrp
 *   /tmp/t_xrp
 */
typedef unsigned char __u8;
typedef unsigned int __u32;

#include "generated/x86_reg_presence.h"

#include <stdio.h>

static int failures;

int main(void)
{
	unsigned long cases = 0;
	__u32 byte;

	for (byte = 0; byte <= 0xffU; byte++) {
		__u8 reg = (__u8)byte;
		__u8 want_present = reg != 0xffU ? 1U : 0U;
		__u8 want_absent = reg == 0xffU ? 1U : 0U;
		__u8 want_arm = reg == 0xffU ? KPROG_X86_REG_ARM_ABSENT
					     : KPROG_X86_REG_ARM_PRESENT;
		__u8 got_present = KPROG_X86_REG_PRESENT(reg);
		__u8 got_absent = KPROG_X86_REG_ABSENT(reg);
		__u8 got_arm = KPROG_X86_REG_ARM(reg);

		cases++;
		if (got_present != want_present) {
			printf("MISMATCH present reg=%u got=%u want=%u\n",
			       byte, got_present, want_present);
			failures++;
		}
		cases++;
		if (got_absent != want_absent) {
			printf("MISMATCH absent reg=%u got=%u want=%u\n",
			       byte, got_absent, want_absent);
			failures++;
		}
		cases++;
		if (got_arm != want_arm) {
			printf("MISMATCH arm reg=%u got=%u want=%u\n",
			       byte, got_arm, want_arm);
			failures++;
		}
		/* The two predicates are the two sides of the one sentinel test:
		 * they must be complementary at every byte. */
		if (got_present != (1U - got_absent)) {
			printf("MISMATCH present/absent disagree reg=%u\n",
			       byte);
			failures++;
		}
		/* The arm code and the presence predicate must agree. */
		if (got_present !=
		    (got_arm == KPROG_X86_REG_ARM_PRESENT)) {
			printf("MISMATCH arm/present disagree reg=%u\n", byte);
			failures++;
		}
	}

	if (KPROG_X86_REG_SENTINEL != 0xffU) {
		printf("MISMATCH sentinel value %u\n",
		       (unsigned)KPROG_X86_REG_SENTINEL);
		failures++;
	}

	if (failures != 0) {
		printf("x86 reg presence host cross-check: FAIL (%d)\n",
		       failures);
		return 1;
	}
	printf("x86 reg presence host cross-check: OK (%lu cases)\n", cases);
	return 0;
}
