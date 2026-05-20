#ifndef ARM64_SIM_H
#define ARM64_SIM_H

#define ARM64_OP_NOP 0x00U
#define ARM64_OP_MOV_IMM 0x01U
#define ARM64_OP_MOV_REG 0x02U
#define ARM64_OP_ADD_IMM 0x03U
#define ARM64_OP_SUB_IMM 0x04U
#define ARM64_OP_RET 0xffU

#define ARM64_WIDTH_32 4U
#define ARM64_WIDTH_64 8U

#define ARM64_X0 0U
#define ARM64_X1 1U
#define ARM64_X2 2U
#define ARM64_X3 3U
#define ARM64_X4 4U
#define ARM64_X5 5U
#define ARM64_X6 6U
#define ARM64_X7 7U
#define ARM64_X8 8U
#define ARM64_X9 9U
#define ARM64_X10 10U
#define ARM64_X11 11U
#define ARM64_X12 12U
#define ARM64_X13 13U
#define ARM64_X14 14U
#define ARM64_X15 15U
#define ARM64_X16 16U
#define ARM64_X17 17U
#define ARM64_X18 18U
#define ARM64_X19 19U
#define ARM64_X20 20U
#define ARM64_X21 21U
#define ARM64_X22 22U
#define ARM64_X23 23U
#define ARM64_X24 24U
#define ARM64_X25 25U
#define ARM64_X26 26U
#define ARM64_X27 27U
#define ARM64_X28 28U
#define ARM64_X29 29U
#define ARM64_X30 30U
#define ARM64_XZR 31U
#define ARM64_REG_NONE 0xffU

static __always_inline __u64 arm64_width_mask(__u8 width)
{
	if (width == ARM64_WIDTH_32)
		return 0xffffffffULL;
	return 0xffffffffffffffffULL;
}

static __always_inline __u64 arm64_apply_width(__u64 value, __u8 width)
{
	return value & arm64_width_mask(width);
}

#endif
