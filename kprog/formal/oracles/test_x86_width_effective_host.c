/*
 * Host cross-check for the generated x86-64 effective-width contract (STEP
 * 0105).
 *
 * `KPROG_X86_WIDTH_EFFECTIVE(CODE)` resolves a decoded width code to the code a
 * body operates at: the absent code `KPROG_X86_WIDTH_ABSENT_CODE` (0, the code
 * an unused width field carries) falls back to
 * `KPROG_X86_WIDTH_EFFECTIVE_DEFAULT` (the 64-bit width), every other code is
 * used as decoded. `KProgFormal/X86Width.lean` proves
 * `GeneratedX86Width.effective` equals an independent
 * `if c = 0 then 8 else c`, that the absent code names no width, and that the
 * fallback code is exactly the 64-bit width's code. The simulator's bodies
 * restated this resolution inline; they now share it through
 * `X86_SIM_L_EFFECTIVE_WIDTH`.
 *
 * This oracle includes only the generated header, defines the width codes the
 * generated assertions expect, sweeps the full decoded-code domain (0..255) plus
 * the width codes and the absent code's neighbours, and compares against an
 * independent `code ? code : 64-bit-code` model and the pinned width table.
 * Exit 1 on mismatch.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. test_x86_width_effective_host.c -o /tmp/t_x86we
 *   /tmp/t_x86we
 */
typedef unsigned char __u8;

#define X86_WIDTH_8 1U
#define X86_WIDTH_16 2U
#define X86_WIDTH_32 4U
#define X86_WIDTH_64 8U

#include "generated/x86_width.h"

#include <stdio.h>

static int failures;

/* The width codes the generated contract pins, independently restated. */
static const __u8 width_codes[] = { 1U, 2U, 4U, 8U };

int main(void)
{
	unsigned long cases = 0;
	unsigned code;

	/* The absent field's fallback code is the 64-bit width, pinned against
	 * the generated decode so the default cannot drift. */
	if (KPROG_X86_WIDTH_ABSENT_CODE != 0U) {
		printf("MISMATCH absent code %u\n",
		       (unsigned)KPROG_X86_WIDTH_ABSENT_CODE);
		failures++;
	}
	if (KPROG_X86_WIDTH_EFFECTIVE_DEFAULT != X86_WIDTH_64) {
		printf("MISMATCH effective default %u\n",
		       (unsigned)KPROG_X86_WIDTH_EFFECTIVE_DEFAULT);
		failures++;
	}

	for (code = 0; code <= 0xffU; code++) {
		__u8 c = (__u8)code;
		/* Independent model: the absent code resolves to the 64-bit
		 * width's code, every other code is used as decoded. Written
		 * without the generated macro so it cannot echo it. */
		__u8 want = (c != 0U) ? c : (__u8)X86_WIDTH_64;
		__u8 got = (__u8)KPROG_X86_WIDTH_EFFECTIVE(c);
		unsigned i;

		cases++;
		if (got != want) {
			printf("MISMATCH effective code=%u got=%u want=%u\n",
			       code, (unsigned)got, (unsigned)want);
			failures++;
		}

		/* The resolution is the identity on a real width code and only
		 * rewrites the absent code. */
		for (i = 0; i < sizeof(width_codes) / sizeof(width_codes[0]);
		     i++) {
			__u8 wc = width_codes[i];
			__u8 r = (__u8)KPROG_X86_WIDTH_EFFECTIVE(wc);

			cases++;
			if (r != wc) {
				printf("MISMATCH identity code=%u got=%u\n",
				       (unsigned)wc, (unsigned)r);
				failures++;
			}
		}
	}

	if (failures != 0) {
		printf("x86 width effective host cross-check: FAIL (%d)\n",
		       failures);
		return 1;
	}
	printf("x86 width effective host cross-check: OK (%lu cases)\n",
	       cases);
	return 0;
}
