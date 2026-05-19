#ifndef X86_SIM_H
#define X86_SIM_H

#define X86_OP_NOP 0x00U
#define X86_OP_MOV_IMM 0x01U
#define X86_OP_MOV_REG 0x02U
#define X86_OP_ADD_IMM 0x03U
#define X86_OP_ADD_REG 0x04U
#define X86_OP_XOR_REG 0x05U
#define X86_OP_MOV_LOAD 0x06U
#define X86_OP_MOV_STORE_IMM 0x07U
#define X86_OP_MOV_STORE_REG 0x08U
#define X86_OP_LEA 0x09U
#define X86_OP_ALU_IMM 0x0aU
#define X86_OP_ALU_REG 0x0bU
#define X86_OP_CMP_IMM 0x0cU
#define X86_OP_CMP_REG 0x0dU
#define X86_OP_TEST_IMM 0x0eU
#define X86_OP_TEST_REG 0x0fU
#define X86_OP_JCC 0x10U
#define X86_OP_JMP 0x11U
#define X86_OP_PUSH 0x12U
#define X86_OP_POP 0x13U
#define X86_OP_CALL 0x14U
#define X86_OP_CMOV 0x15U
#define X86_OP_SETCC 0x16U
#define X86_OP_BSWAP 0x17U
#define X86_OP_POPCNT 0x18U
#define X86_OP_XCHG 0x19U
#define X86_OP_DIV 0x1aU
#define X86_OP_SHLD_IMM 0x1bU
#define X86_OP_SHRD_IMM 0x1cU
#define X86_OP_CMP_MEM_IMM 0x1dU
#define X86_OP_TEST_MEM_IMM 0x1eU
#define X86_OP_CMP_MEM_REG 0x1fU
#define X86_OP_MOVZX_REG 0x20U
#define X86_OP_MOVSX_REG 0x21U
#define X86_OP_MOVSX_LOAD 0x22U
#define X86_OP_ALU_MEM 0x23U
#define X86_OP_RET 0xffU

#define X86_OP_MOV_IMM64 X86_OP_MOV_IMM
#define X86_OP_MOV_REG64 X86_OP_MOV_REG
#define X86_OP_ADD_IMM64 X86_OP_ADD_IMM
#define X86_OP_ADD_REG64 X86_OP_ADD_REG
#define X86_OP_XOR_REG32 X86_OP_XOR_REG

#define X86_ALU_ADD 0U
#define X86_ALU_SUB 1U
#define X86_ALU_XOR 2U
#define X86_ALU_OR 3U
#define X86_ALU_AND 4U
#define X86_ALU_SHL 5U
#define X86_ALU_SHR 6U
#define X86_ALU_SAR 7U
#define X86_ALU_ROL 8U
#define X86_ALU_IMUL 9U
#define X86_ALU_INC 10U
#define X86_ALU_NOT 11U
#define X86_ALU_SBB 12U

#define X86_CC_O 0U
#define X86_CC_NO 1U
#define X86_CC_B 2U
#define X86_CC_AE 3U
#define X86_CC_E 4U
#define X86_CC_NE 5U
#define X86_CC_BE 6U
#define X86_CC_A 7U
#define X86_CC_S 8U
#define X86_CC_NS 9U
#define X86_CC_L 12U
#define X86_CC_GE 13U
#define X86_CC_LE 14U
#define X86_CC_G 15U

#define X86_WIDTH_8 1U
#define X86_WIDTH_16 2U
#define X86_WIDTH_32 4U
#define X86_WIDTH_64 8U

#define X86_RAX 0U
#define X86_RCX 1U
#define X86_RDX 2U
#define X86_RBX 3U
#define X86_RSP 4U
#define X86_RBP 5U
#define X86_RSI 6U
#define X86_RDI 7U
#define X86_R8 8U
#define X86_R9 9U
#define X86_R10 10U
#define X86_R11 11U
#define X86_R12 12U
#define X86_R13 13U
#define X86_R14 14U
#define X86_R15 15U
#define X86_REG_NONE 0xffU

#define X86_LEA_AUX_RODATA 1U

#define X86_SKB_LEN_OFF 0x70LL
#define X86_SKB_DATA_OFF 0xd0LL

#define X86_MEM_AUX(INDEX, SCALE_LOG2)                                      \
	(((__u32)(INDEX) & 0xffU) | (((__u32)(SCALE_LOG2) & 0xffU) << 8))
#define X86_MEM_AUX_FULL(INDEX, SCALE_LOG2, MEM_WIDTH)                      \
	(X86_MEM_AUX((INDEX), (SCALE_LOG2)) |                               \
	 (((__u32)(MEM_WIDTH) & 0xffU) << 16))
#define X86_REG_AUX_SRC_SHIFT(SHIFT) (((__u32)(SHIFT) & 0xffU) << 24)
#define X86_MEM_AUX_ALU_OP(ALU) (((__u32)(ALU) & 0xffU) << 24)
#define X86_MEM_AUX_INDEX(AUX) ((__u8)((AUX) & 0xffU))
#define X86_MEM_AUX_SCALE_LOG2(AUX) ((__u8)(((AUX) >> 8) & 0xffU))
#define X86_MEM_AUX_MEM_WIDTH(AUX) ((__u8)(((AUX) >> 16) & 0xffU))
#define X86_REG_AUX_GET_SRC_SHIFT(AUX) ((__u8)(((AUX) >> 24) & 0xffU))
#define X86_MEM_AUX_GET_ALU_OP(AUX) ((__u8)(((AUX) >> 24) & 0xffU))

static __always_inline __u64 x86_width_mask(__u8 width)
{
	if (width == X86_WIDTH_8)
		return 0xffULL;
	if (width == X86_WIDTH_16)
		return 0xffffULL;
	if (width == X86_WIDTH_32)
		return 0xffffffffULL;
	return 0xffffffffffffffffULL;
}

static __always_inline __u32 x86_width_bits(__u8 width)
{
	if (width == X86_WIDTH_8)
		return 8;
	if (width == X86_WIDTH_16)
		return 16;
	if (width == X86_WIDTH_32)
		return 32;
	return 64;
}

static __always_inline __u64 x86_apply_width(__u64 value, __u8 width)
{
	return value & x86_width_mask(width);
}

static __always_inline __u64 x86_sign_extend(__u64 value, __u8 width)
{
	__u64 narrowed = x86_apply_width(value, width);

	if (width == X86_WIDTH_8)
		return (__u64)(__s64)(__s8)narrowed;
	if (width == X86_WIDTH_16)
		return (__u64)(__s64)(__s16)narrowed;
	if (width == X86_WIDTH_32)
		return (__u64)(__s64)(__s32)narrowed;
	return narrowed;
}

static __always_inline __u8 x86_shift_count(__u64 rhs, __u8 width)
{
	if (width == X86_WIDTH_64)
		return rhs & 0x3f;
	return rhs & 0x1f;
}

static __always_inline __u64 x86_signed_abs_width(__u64 value, __u8 width)
{
	__u64 narrowed = x86_apply_width(value, width);
	__u64 sign = 1ULL << (x86_width_bits(width) - 1);

	if (!(narrowed & sign))
		return narrowed;
	return ((~narrowed) + 1) & x86_width_mask(width);
}

static __always_inline __u64 x86_rol(__u64 value, __u64 shift, __u8 width)
{
	__u32 bits = x86_width_bits(width);
	__u64 mask = x86_width_mask(width);
	__u64 amount = shift & (bits - 1);
	__u64 narrowed = value & mask;

	if (amount == 0)
		return narrowed;
	return ((narrowed << amount) | (narrowed >> (bits - amount))) & mask;
}

static __always_inline __u64 x86_bswap(__u64 value, __u8 width)
{
	__u64 swapped = ((value & 0x00000000000000ffULL) << 56) |
			((value & 0x000000000000ff00ULL) << 40) |
			((value & 0x0000000000ff0000ULL) << 24) |
			((value & 0x00000000ff000000ULL) << 8) |
			((value & 0x000000ff00000000ULL) >> 8) |
			((value & 0x0000ff0000000000ULL) >> 24) |
			((value & 0x00ff000000000000ULL) >> 40) |
			((value & 0xff00000000000000ULL) >> 56);

	if (width == X86_WIDTH_32)
		return swapped >> 32;
	return swapped;
}

static __always_inline __u64 x86_popcount64(__u64 value)
{
	value = value - ((value >> 1) & 0x5555555555555555ULL);
	value = (value & 0x3333333333333333ULL) +
		((value >> 2) & 0x3333333333333333ULL);
	value = (value + (value >> 4)) & 0x0f0f0f0f0f0f0f0fULL;
	return (value * 0x0101010101010101ULL) >> 56;
}

static __always_inline __u64 x86_alu_result(__u64 lhs, __u64 rhs,
					    __u32 alu, __u8 width)
{
	__u32 bits = x86_width_bits(width);
	__u64 amount = x86_shift_count(rhs, width);

	if (alu == X86_ALU_ADD)
		return lhs + rhs;
	if (alu == X86_ALU_SUB || alu == X86_ALU_SBB)
		return lhs - rhs;
	if (alu == X86_ALU_XOR)
		return lhs ^ rhs;
	if (alu == X86_ALU_OR)
		return lhs | rhs;
	if (alu == X86_ALU_AND)
		return lhs & rhs;
	if (alu == X86_ALU_SHL) {
		if (amount >= bits)
			return 0;
		return lhs << amount;
	}
	if (alu == X86_ALU_SHR) {
		if (amount >= bits)
			return 0;
		return lhs >> amount;
	}
	if (alu == X86_ALU_SAR) {
		if (amount >= bits) {
			if (width == X86_WIDTH_32)
				return ((__u32)lhs & 0x80000000U) ?
					       0xffffffffU :
					       0;
			return ((__u64)lhs & 0x8000000000000000ULL) ?
				       0xffffffffffffffffULL :
				       0;
		}
		if (width == X86_WIDTH_32)
			return (__u32)((__s32)lhs >> amount);
		return (__u64)((__s64)lhs >> amount);
	}
	if (alu == X86_ALU_ROL)
		return x86_rol(lhs, rhs, width);
	if (alu == X86_ALU_IMUL)
		return lhs * rhs;
	if (alu == X86_ALU_INC)
		return lhs + 1;
	if (alu == X86_ALU_NOT)
		return ~lhs;
	return lhs;
}

static __always_inline __u64 x86_shld(__u64 dst, __u64 src, __u64 shift,
				      __u8 width)
{
	__u32 bits = x86_width_bits(width);
	__u64 mask = x86_width_mask(width);
	__u64 amount = x86_shift_count(shift, width);
	__u64 d = dst & mask;
	__u64 s = src & mask;

	if (amount == 0)
		return d;
	if (amount >= bits)
		return (s << (amount - bits)) & mask;
	return ((d << amount) | (s >> (bits - amount))) & mask;
}

static __always_inline __u64 x86_shrd(__u64 dst, __u64 src, __u64 shift,
				      __u8 width)
{
	__u32 bits = x86_width_bits(width);
	__u64 mask = x86_width_mask(width);
	__u64 amount = x86_shift_count(shift, width);
	__u64 d = dst & mask;
	__u64 s = src & mask;

	if (amount == 0)
		return d;
	if (amount >= bits)
		return (s >> (amount - bits)) & mask;
	return ((d >> amount) | (s << (bits - amount))) & mask;
}

static __always_inline __s64 x86_simm(__u64 value)
{
	return (__s64)value;
}

static __always_inline __u64 x86_store_imm_value(__u64 value, __u8 width)
{
	__u32 imm32 = (__u32)value;

	if (width == X86_WIDTH_64)
		return (__u64)(__s64)(__s32)imm32;
	return imm32;
}

static __always_inline __s32 x86_store_imm_disp(__u64 value)
{
	return (__s32)(value >> 32);
}

#endif
