#ifndef ARM64_SIM_H
#define ARM64_SIM_H

#define ARM64_OP_NOP 0x00U
#define ARM64_OP_MOV_IMM 0x01U
#define ARM64_OP_MOV_REG 0x02U
#define ARM64_OP_ADD_IMM 0x03U
#define ARM64_OP_SUB_IMM 0x04U
#define ARM64_OP_MOVK 0x05U
#define ARM64_OP_ALU_IMM 0x06U
#define ARM64_OP_ALU_REG 0x07U
#define ARM64_OP_SHIFT_IMM 0x08U
#define ARM64_OP_SHIFT_REG 0x09U
#define ARM64_OP_MADD 0x0aU
#define ARM64_OP_MSUB 0x0bU
#define ARM64_OP_MUL 0x0cU
#define ARM64_OP_UMULL 0x0dU
#define ARM64_OP_UDIV 0x0eU
#define ARM64_OP_MVN 0x0fU
#define ARM64_OP_NEG 0x10U
#define ARM64_OP_EXTR 0x11U
#define ARM64_OP_BITFIELD 0x12U
#define ARM64_OP_REV 0x13U
#define ARM64_OP_REV16 0x14U
#define ARM64_OP_SXTH 0x15U
#define ARM64_OP_CMP_IMM 0x16U
#define ARM64_OP_CMP_REG 0x17U
#define ARM64_OP_TST_IMM 0x18U
#define ARM64_OP_TST_REG 0x19U
#define ARM64_OP_CCMP_IMM 0x1aU
#define ARM64_OP_CCMP_REG 0x1bU
#define ARM64_OP_CSEL 0x1cU
#define ARM64_OP_CINC 0x1dU
#define ARM64_OP_CSET 0x1eU
#define ARM64_OP_LOAD 0x1fU
#define ARM64_OP_STORE 0x20U
#define ARM64_OP_LDP 0x21U
#define ARM64_OP_STP 0x22U
#define ARM64_OP_FMOV 0x23U
#define ARM64_OP_CNT 0x24U
#define ARM64_OP_UADDLV 0x25U
#define ARM64_OP_ADRP_GOT 0x26U
#define ARM64_OP_ADRP_RODATA 0x27U
#define ARM64_OP_LOAD_D0 0x28U
#define ARM64_OP_STORE_D0 0x29U
#define ARM64_OP_LOAD_Q0 0x2aU
#define ARM64_OP_STORE_Q0 0x2bU
#define ARM64_OP_TST_BIC_REG 0x2cU
#define ARM64_OP_ANDS_REG 0x2dU
#define ARM64_OP_UMULH 0x2eU
#define ARM64_OP_SXTW 0x2fU
#define ARM64_OP_SUBS_IMM 0x30U
#define ARM64_OP_ADDS_IMM 0x31U
#define ARM64_OP_SUBS_REG 0x32U
#define ARM64_OP_CMN_IMM 0x33U
#define ARM64_OP_CINV 0x34U
#define ARM64_OP_ORN_REG 0x35U
#define ARM64_OP_LDRSB 0x36U
#define ARM64_OP_ANDS_IMM 0x37U
#define ARM64_OP_STLXR 0x38U
#define ARM64_OP_LDRSW 0x39U
#define ARM64_OP_CMN_REG 0x3aU
#define ARM64_OP_UMADDL 0x3bU
#define ARM64_OP_SXTB 0x3cU
#define ARM64_OP_CSINV 0x3dU
#define ARM64_OP_CSINC 0x3eU
#define ARM64_OP_LDRSH 0x3fU
#define ARM64_OP_SMADDL 0x40U
#define ARM64_OP_CNEG 0x41U
#define ARM64_OP_RET 0xffU

#define ARM64_ALU_ADD 0U
#define ARM64_ALU_SUB 1U
#define ARM64_ALU_AND 2U
#define ARM64_ALU_BIC 3U
#define ARM64_ALU_EOR 4U
#define ARM64_ALU_ORR 5U

#define ARM64_SHIFT_LSL 0U
#define ARM64_SHIFT_LSR 1U
#define ARM64_SHIFT_ASR 2U
#define ARM64_SHIFT_ROR 3U

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

#define ARM64_BITFIELD_UBFX 0U
#define ARM64_BITFIELD_SBFX 1U
#define ARM64_BITFIELD_UBFIZ 2U
#define ARM64_BITFIELD_BFXIL 3U
#define ARM64_BITFIELD_BFI 4U

#define ARM64_FMOV_D_FROM_X 0U
#define ARM64_FMOV_X_FROM_D 1U
#define ARM64_FMOV_S_FROM_W 2U
#define ARM64_FMOV_W_FROM_S 3U

#define ARM64_MEM_PRE 1U
#define ARM64_MEM_POST 2U

#define ARM64_AUX(ALU, MOD, SHIFT)                                         \
	(((__u32)(ALU) & 0xffU) | (((__u32)(MOD) & 0xffU) << 8) |           \
	 (((__u32)(SHIFT) & 0xffU) << 16))
#define ARM64_AUX_ALU(A, M, S) ARM64_AUX((A), (M), (S))
#define ARM64_AUX_SHIFT(S) ((__u32)(S) & 0xffU)
#define ARM64_AUX_MOVK(S) (((__u32)(S) & 0xffU) << 16)
#define ARM64_AUX_MEM(INDEX, MOD, SHIFT, FLAGS)                            \
	(((__u32)(INDEX) & 0xffU) | (((__u32)(MOD) & 0xffU) << 8) |         \
	 (((__u32)(SHIFT) & 0xffU) << 16) | (((__u32)(FLAGS) & 0xffU) << 24))
#define ARM64_AUX_BITFIELD(OP, LSB, WIDTH)                                 \
	(((__u32)(OP) & 0xffU) | (((__u32)(LSB) & 0xffU) << 8) |            \
	 (((__u32)(WIDTH) & 0xffU) << 16))
#define ARM64_AUX_CCMP(COND, NZCV)                                         \
	(((__u32)(COND) & 0xffU) | (((__u32)(NZCV) & 0xffU) << 8))

#define ARM64_WIDTH_8 1U
#define ARM64_WIDTH_16 2U
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
#define ARM64_SP 32U
#define ARM64_REG_NONE 0xffU

#define ARM64_COND_EQ 0U
#define ARM64_COND_NE 1U
#define ARM64_COND_CS 2U
#define ARM64_COND_CC 3U
#define ARM64_COND_MI 4U
#define ARM64_COND_PL 5U
#define ARM64_COND_VS 6U
#define ARM64_COND_VC 7U
#define ARM64_COND_HI 8U
#define ARM64_COND_LS 9U
#define ARM64_COND_GE 10U
#define ARM64_COND_LT 11U
#define ARM64_COND_GT 12U
#define ARM64_COND_LE 13U
#define ARM64_COND_AL 14U

#define ARM64_SKB_CB_OFF 0x30LL
#define ARM64_SKB_DATA_END_OFF 0x50LL
#define ARM64_SKB_DATA_OFF 0xd0LL
#define ARM64_SIM_STACK_BIAS 96LL

static __always_inline __u64 arm64_width_mask(__u8 width)
{
	if (width == ARM64_WIDTH_8)
		return 0xffULL;
	if (width == ARM64_WIDTH_16)
		return 0xffffULL;
	if (width == ARM64_WIDTH_32)
		return 0xffffffffULL;
	return 0xffffffffffffffffULL;
}

static __always_inline __u8 arm64_width_bits(__u8 width)
{
	if (width == ARM64_WIDTH_8)
		return 8U;
	if (width == ARM64_WIDTH_16)
		return 16U;
	if (width == ARM64_WIDTH_32)
		return 32U;
	return 64U;
}

static __always_inline __u64 arm64_bits_mask(__u8 bits)
{
	if (!bits)
		return 0;
	if (bits >= 64)
		return 0xffffffffffffffffULL;
	return (1ULL << bits) - 1ULL;
}

static __always_inline __u64 arm64_sign_bit(__u8 width)
{
	return 1ULL << (arm64_width_bits(width) - 1U);
}

static __always_inline __u64 arm64_apply_width(__u64 value, __u8 width)
{
	return value & arm64_width_mask(width);
}

static __always_inline __u64 arm64_sign_extend(__u64 value, __u8 bits)
{
	__u64 mask = arm64_bits_mask(bits);
	__u64 sign;

	if (!bits)
		return 0;

	sign = 1ULL << (bits >= 64 ? 63U : bits - 1U);
	value &= mask;
	return (value ^ sign) - sign;
}

static __always_inline __u64 arm64_umulh(__u64 lhs, __u64 rhs)
{
	__u64 lhs_lo = (__u32)lhs;
	__u64 lhs_hi = lhs >> 32;
	__u64 rhs_lo = (__u32)rhs;
	__u64 rhs_hi = rhs >> 32;
	__u64 lo = lhs_lo * rhs_lo;
	__u64 mid1 = lhs_hi * rhs_lo;
	__u64 mid2 = lhs_lo * rhs_hi;
	__u64 hi = lhs_hi * rhs_hi;
	__u64 carry = ((lo >> 32) + (__u32)mid1 + (__u32)mid2) >> 32;

	return hi + (mid1 >> 32) + (mid2 >> 32) + carry;
}

static __always_inline __u64 arm64_ror64(__u64 value, __u8 amount)
{
	amount &= 63U;
	return amount ? ((value >> amount) | (value << (64U - amount))) : value;
}

static __always_inline __u32 arm64_ror32(__u32 value, __u8 amount)
{
	amount &= 31U;
	return amount ? ((value >> amount) | (value << (32U - amount))) : value;
}

static __always_inline __u64 arm64_reverse_bytes(__u64 value, __u8 width)
{
	if (width == ARM64_WIDTH_32)
		return ((__u64)__builtin_bswap32((__u32)value));
	return __builtin_bswap64(value);
}

static __always_inline __u64 arm64_reverse_bytes16(__u64 value, __u8 width)
{
	__u64 out = 0;

	if (width == ARM64_WIDTH_32) {
		out |= (value & 0x00ff00ffULL) << 8;
		out |= (value & 0xff00ff00ULL) >> 8;
		return out & 0xffffffffULL;
	}
	out |= (value & 0x00ff00ff00ff00ffULL) << 8;
	out |= (value & 0xff00ff00ff00ff00ULL) >> 8;
	return out;
}

static __always_inline __u64 arm64_replicate_byte_popcounts(__u64 value)
{
	__u64 out = 0;

	out |= ((__u64)__builtin_popcountll(value & 0xffULL)) << 0;
	out |= ((__u64)__builtin_popcountll((value >> 8) & 0xffULL)) << 8;
	out |= ((__u64)__builtin_popcountll((value >> 16) & 0xffULL)) << 16;
	out |= ((__u64)__builtin_popcountll((value >> 24) & 0xffULL)) << 24;
	out |= ((__u64)__builtin_popcountll((value >> 32) & 0xffULL)) << 32;
	out |= ((__u64)__builtin_popcountll((value >> 40) & 0xffULL)) << 40;
	out |= ((__u64)__builtin_popcountll((value >> 48) & 0xffULL)) << 48;
	out |= ((__u64)__builtin_popcountll((value >> 56) & 0xffULL)) << 56;
	return out;
}

static __always_inline __u64 arm64_horizontal_add_u8(__u64 value)
{
	return (value & 0xffULL) +
	       ((value >> 8) & 0xffULL) +
	       ((value >> 16) & 0xffULL) +
	       ((value >> 24) & 0xffULL) +
	       ((value >> 32) & 0xffULL) +
	       ((value >> 40) & 0xffULL) +
	       ((value >> 48) & 0xffULL) +
	       ((value >> 56) & 0xffULL);
}

static __always_inline __u64 arm64_lsl(__u64 value, __u8 amount, __u8 width)
{
	amount &= width == ARM64_WIDTH_32 ? 31U : 63U;
	return arm64_apply_width(value << amount, width);
}

static __always_inline __u64 arm64_lsr(__u64 value, __u8 amount, __u8 width)
{
	amount &= width == ARM64_WIDTH_32 ? 31U : 63U;
	return arm64_apply_width(value, width) >> amount;
}

static __always_inline __u64 arm64_asr(__u64 value, __u8 amount, __u8 width)
{
	amount &= width == ARM64_WIDTH_32 ? 31U : 63U;
	if (width == ARM64_WIDTH_32)
		return (__u64)((__s32)value >> amount);
	return (__u64)((__s64)value >> amount);
}

static __always_inline __u64 arm64_ror(__u64 value, __u8 amount, __u8 width)
{
	if (width == ARM64_WIDTH_32)
		return arm64_ror32((__u32)value, amount);
	return arm64_ror64(value, amount);
}

#endif
