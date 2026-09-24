#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#define ARM64_WIDTH_64 8U
#define ARM64_ALU_ADD 0U
#include "generated/arm64_alu_handler.h"

static bool oracle(uint8_t width, uint8_t op, bool dst_is_sp,
		   bool src_is_scalar)
{
	return width == ARM64_WIDTH_64 && op == ARM64_ALU_ADD &&
	       !dst_is_sp && !src_is_scalar;
}

int main(void)
{
	static const uint8_t widths[] = { 0, 1, 2, 4, 8, 0xff };
	static const uint8_t ops[] = { 0, 1, 2, 3, 4, 5, 0xff };
	unsigned int cases = 0;

	for (unsigned int w = 0; w < sizeof(widths); w++) {
		for (unsigned int op = 0; op < sizeof(ops); op++) {
			for (unsigned int sp = 0; sp < 2; sp++) {
				for (unsigned int scalar = 0; scalar < 2; scalar++) {
					bool got = KPROG_ARM64_ALU_USE_POINTER(
						widths[w], ops[op], sp, scalar);
					bool want = oracle(widths[w], ops[op], sp, scalar);
					cases++;
					if (got != want) {
						fprintf(stderr,
							"MISMATCH width=%u op=%u sp=%u scalar=%u got=%u want=%u\n",
							widths[w], ops[op], sp, scalar,
							got, want);
						return 1;
					}
				}
			}
		}
	}

	printf("arm64 ALU handler path host cross-check: OK (%u cases)\n", cases);
	return 0;
}
