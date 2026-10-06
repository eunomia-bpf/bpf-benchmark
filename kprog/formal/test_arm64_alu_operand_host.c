/* Cross-check immediate/register RHS selection feeding the AArch64 ALU. */
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;
typedef signed char __s8;
typedef short __s16;
typedef int __s32;
typedef long long __s64;

#define ARM64_MOD_NONE 0U
#define ARM64_MOD_LSL 1U
#define ARM64_MOD_LSR 2U
#define ARM64_MOD_ASR 3U
#define ARM64_MOD_ROR 4U
#define ARM64_MOD_UXTW 5U
#define ARM64_MOD_SXTW 6U
#define ARM64_MOD_UXTH 7U
#define ARM64_MOD_SXTH 8U
#define ARM64_MOD_UXTB 9U
#define ARM64_MOD_SXTB 10U
#define ARM64_WIDTH_8 1U
#define ARM64_WIDTH_16 2U
#define ARM64_WIDTH_32 4U
#define ARM64_WIDTH_64 8U

#include "generated/arm64_width.h"
#include "generated/arm64_mod.h"
#include "generated/arm64_alu_operand.h"

#include <stdio.h>

static __u64 mod_oracle(unsigned mod, __u64 value, unsigned shift,
	unsigned width)
{
	unsigned amount = shift & (width == ARM64_WIDTH_32 ? 31U : 63U);
	__u64 mask = KPROG_ARM64_WIDTH_MASK(width);

	switch (mod) {
	case ARM64_MOD_NONE: return value;
	case ARM64_MOD_LSL: return value << amount & mask;
	case ARM64_MOD_LSR: return (value & mask) >> amount;
	case ARM64_MOD_ASR:
		return width == ARM64_WIDTH_32 ? (__u64)((__s32)value >> amount) :
			(__u64)((__s64)value >> amount);
	case ARM64_MOD_ROR:
		if (width == ARM64_WIDTH_32) {
			__u32 word = (__u32)value;

			return amount ? (__u64)(word >> amount | word << (32U - amount)) : word;
		}
		return amount ? value >> amount | value << (64U - amount) : value;
	case ARM64_MOD_UXTW: return (__u64)(__u32)value << shift;
	case ARM64_MOD_SXTW: return (__u64)(__s64)(__s32)value << shift;
	case ARM64_MOD_UXTH: return (__u64)(__u16)value << shift;
	case ARM64_MOD_SXTH: return (__u64)(__s64)(__s16)value << shift;
	case ARM64_MOD_UXTB: return (__u64)(__u8)value << shift;
	case ARM64_MOD_SXTB: return (__u64)(__s64)(__s8)value << shift;
	default: return 0;
	}
}

static int check(unsigned immediate_mode, __u64 immediate, unsigned mod,
	__u64 value, unsigned shift, unsigned width)
{
	__u64 result = KPROG_ARM64_ALU_RHS(immediate_mode, immediate, mod,
		value, shift, width);
	__u64 want = immediate_mode ? immediate :
		mod_oracle(mod, value, shift, width);

	if (result != want) {
		fprintf(stderr,
			"MISMATCH mode=%u imm=%#llx mod=%u value=%#llx shift=%u width=%u result=%#llx want=%#llx\n",
			immediate_mode, immediate, mod, value, shift, width,
			result, want);
		return 1;
	}
	return 0;
}

int main(void)
{
	static const __u64 vectors[] = {
		0, 1, 0x80, 0xff, 0x80000000, 0xffffffff,
		0x0102030405060708ULL, ~0ULL,
	};
	static const unsigned shifts[] = {0, 1, 7, 8, 16, 31, 32, 63};
	static const unsigned widths[] = {
		ARM64_WIDTH_8, ARM64_WIDTH_16, ARM64_WIDTH_32, ARM64_WIDTH_64,
	};
	unsigned cases = 0;

	for (unsigned mode = 0; mode < 2; mode++)
		for (unsigned mod = 0; mod <= ARM64_MOD_SXTB; mod++)
			for (unsigned i = 0; i < sizeof(vectors) / sizeof(vectors[0]); i++)
				for (unsigned s = 0; s < sizeof(shifts) / sizeof(shifts[0]); s++)
					for (unsigned w = 0; w < sizeof(widths) / sizeof(widths[0]); w++) {
						if (check(mode, vectors[7 - i], mod, vectors[i],
							shifts[s], widths[w]))
							return 1;
						cases++;
					}

	printf("arm64 ALU operand host cross-check: OK (%u cases)\n", cases);
	return 0;
}
