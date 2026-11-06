/*
 * Host cross-check for the AArch64 vector-register half state-field contract
 * (STEP 0143).
 *
 * The module under test is `generated/arm64_vreg_field.h`. It fixes the
 * vector-register state field the simulator's `ARM64_SIM_L_DQ_MEM_STEP` lands a
 * moved half in, selected from a single closed fact: whether the half the plan
 * names is the high half, whose slot offset is the high half's offset. The high
 * half's state field (`__a64_v0_hi`) fires exactly when the moved half's slot
 * offset is the high half's offset; the low half's state field (`__a64_v0`)
 * fires otherwise. This oracle drives the contract's `KPROG_ARM64_VREG_FIELD`
 * and restates the 2-way field selection from the raw fact with no reference to
 * the generated selector. The two must agree, and the selector must name the
 * same field as the vector half offset `KPROG_ARM64_VREG_HALF_OFFSET` yields
 * against `KPROG_ARM64_VREG_HIGH_OFFSET`; the generated `_Static_assert`s
 * additionally pin the field codes and the selector's two fact selections at
 * compile time. Exit 1 on mismatch.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. test_arm64_vreg_field_host.c \
 *       -o /tmp/t_vreg_field
 *   /tmp/t_vreg_field
 */
typedef unsigned char __u8;

#define ARM64_OP_LOAD_D0 0x28U
#define ARM64_OP_STORE_D0 0x29U
#define ARM64_OP_LOAD_Q0 0x2aU
#define ARM64_OP_STORE_Q0 0x2bU

#include "generated/arm64_vreg.h"
#include "generated/arm64_vreg_field.h"

#include <stdio.h>

static int failures;
static unsigned long cases;

/* The independent 2-way state-field selection: the high half's state field
 * exactly when the moved half is the high half, the low half's state field
 * otherwise. Restated from the raw fact. */
static unsigned model_field(unsigned is_high)
{
	if (is_high)
		return 1;
	return 0;
}

int main(void)
{
	unsigned is_high;

	cases++;
	if (KPROG_ARM64_VREG_FIELD_COUNT != 2U) {
		printf("MISMATCH field count got=%u want=2\n",
		       (unsigned)KPROG_ARM64_VREG_FIELD_COUNT);
		failures++;
	}

	/* The field-code defines name the two distinct codes. */
	cases++;
	if (KPROG_ARM64_VREG_LOW_FIELD != 0U ||
	    KPROG_ARM64_VREG_HIGH_FIELD != 1U) {
		printf("MISMATCH field code defines drift\n");
		failures++;
	}

	/* The full selection table: the fact crossed against the independent
	 * 2-way statement. */
	for (is_high = 0; is_high <= 1U; is_high++) {
		unsigned got = KPROG_ARM64_VREG_FIELD(is_high);
		unsigned want = model_field(is_high);

		cases++;
		if (got != want) {
			printf("MISMATCH field is_high=%u got=%u want=%u\n",
			       is_high, got, want);
			failures++;
		}
	}

	/* The selector is a plain expression in its input: feeding the fact the
	 * vector memory step actually computes (the half's slot offset against
	 * the high offset) at each raw half must reach the same fields, so the
	 * state-field contract and the vector-register half contract agree. */
	{
		static const unsigned raw[] = {
			KPROG_ARM64_VREG_HALF_LOW, KPROG_ARM64_VREG_HALF_HIGH
		};
		unsigned ri;

		for (ri = 0; ri < sizeof(raw) / sizeof(raw[0]); ri++) {
			unsigned high = KPROG_ARM64_VREG_HALF_OFFSET(raw[ri]) ==
					KPROG_ARM64_VREG_HIGH_OFFSET;
			if (KPROG_ARM64_VREG_FIELD(high) !=
			    model_field(high)) {
				printf("MISMATCH raw half=%u high=%u\n",
				       raw[ri], high);
				failures++;
			}
			cases++;
			if ((KPROG_ARM64_VREG_FIELD(high) ==
			     KPROG_ARM64_VREG_HIGH_FIELD) != (high != 0U)) {
				printf("MISMATCH half-offset raw half=%u\n",
				       raw[ri]);
				failures++;
			}
		}
	}

	/* The two fields name two distinct codes. */
	cases++;
	{
		unsigned a = KPROG_ARM64_VREG_FIELD(1);
		unsigned b = KPROG_ARM64_VREG_FIELD(0);

		if (a == b) {
			printf("MISMATCH field codes not distinct\n");
			failures++;
		}
	}

	if (failures != 0) {
		printf("arm64 vreg field host cross-check: FAIL (%d)\n",
		       failures);
		return 1;
	}
	printf("arm64 vreg field host cross-check: OK (%lu cases)\n",
	       cases);
	return 0;
}
