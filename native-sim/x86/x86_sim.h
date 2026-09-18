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
#define X86_OP_CMP_REG_MEM 0x24U
#define X86_OP_MOV_LOAD_SCALAR 0x25U
#define X86_OP_SHIFTX 0x26U
#define X86_OP_RORX 0x27U
#define X86_OP_MOVBE_LOAD 0x28U
#define X86_OP_MOVBE_STORE 0x29U
#define X86_OP_SHIFTX_MEM 0x2aU
#define X86_OP_RORX_MEM 0x2bU
#define X86_OP_MOV_LOAD_MAP_PTR 0x2cU
#define X86_OP_MOV_LOAD_HELPER_ID 0x2dU
#define X86_OP_CALL_HELPER 0x2eU
#define X86_OP_CALL_REG 0x2fU
#define X86_OP_LOAD_XMM0 0x30U
#define X86_OP_STORE_XMM0 0x31U
#define X86_OP_ALU_MEM_UNARY 0x32U
#define X86_OP_ALU_MEM_IMM 0x33U
#define X86_OP_BZHI 0x34U
#define X86_OP_BZHI_MEM 0x35U
#define X86_OP_ALU_MEM_REG 0x36U
#define X86_OP_BT 0x37U
#define X86_OP_IMUL_IMM 0x38U
#define X86_OP_MULX 0x39U
#define X86_OP_REP_MOVS 0x3aU
#define X86_OP_TEST_MEM_REG 0x3bU
#define X86_OP_CALL_MEMSET 0x3cU
#define X86_OP_ANDN 0x3dU
#define X86_OP_SETCC_MEM 0x3eU
#define X86_OP_CALL_MEMCPY 0x3fU
#define X86_OP_CMOV_MEM 0x40U
#define X86_OP_IMUL_MEM_IMM 0x41U
#define X86_OP_BT_IMM 0x42U
#define X86_OP_BT_MEM_IMM 0x43U
#define X86_OP_ANDN_MEM 0x44U
#define X86_OP_CALL_MEMSET_REG 0x45U
#define X86_OP_CALL_MEMCPY_REG 0x46U
#define X86_OP_RET 0xffU

#define X86_OP_MOV_IMM64 X86_OP_MOV_IMM
#define X86_OP_MOV_REG64 X86_OP_MOV_REG
#define X86_OP_ADD_IMM64 X86_OP_ADD_IMM
#define X86_OP_ADD_REG64 X86_OP_ADD_REG
#define X86_OP_XOR_REG32 X86_OP_XOR_REG

#include "../formal/generated/x86_alu_decode.h"

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
#include "../formal/generated/x86_width.h"
#include "../formal/generated/x86_immediate.h"
#include "../formal/generated/x86_adc.h"
#include "../formal/generated/x86_sbb_result.h"
#include "../formal/generated/x86_not.h"
#include "../formal/generated/x86_shift_count.h"
#include "../formal/generated/x86_shift_result.h"
#include "../formal/generated/x86_bswap.h"
#include "../formal/generated/x86_signed.h"
#include "../formal/generated/x86_popcount.h"
#include "../formal/generated/x86_bitops.h"
#include "../formal/generated/x86_doubleshift.h"

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

#define X86_SKB_CB_OFF 0x30LL
#define X86_SKB_DATA_END_OFF 0x50LL
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
#include "../formal/generated/x86_reg_lane_aux.h"

_Static_assert(KPROG_X86_REG_LANE_AUX_PAYLOAD(
	KPROG_X86_REG_LANE_AUX(0xabU, 8U, 0U)) == 0xabU,
	"x86 register AUX payload drift");
_Static_assert(KPROG_X86_REG_LANE_AUX_DST_SHIFT(
	KPROG_X86_REG_LANE_AUX(0U, 8U, 0U)) == 8U,
	"x86 register AUX destination lane drift");
_Static_assert(KPROG_X86_REG_LANE_AUX_SRC_SHIFT(
	KPROG_X86_REG_LANE_AUX(0U, 0U, 8U)) == 8U,
	"x86 register AUX source lane drift");

static __always_inline __u64 x86_width_mask(__u8 width)
{
	return KPROG_X86_WIDTH_MASK(width);
}

static __always_inline __u32 x86_width_bits(__u8 width)
{
	return KPROG_X86_WIDTH_BITS(width);
}

static __always_inline __u64 x86_width_sign_mask(__u8 width)
{
	return KPROG_X86_WIDTH_SIGN_MASK(width);
}

static __always_inline __u64 x86_apply_width(__u64 value, __u8 width)
{
	return KPROG_X86_APPLY_WIDTH(value, width);
}

static __always_inline __u64 x86_sign_extend(__u64 value, __u8 width)
{
	return kprog_x86_sign_extend_value(value, width);
}

static __always_inline __u8 x86_shift_count(__u64 rhs, __u8 width)
{
	return KPROG_X86_SHIFT_COUNT(rhs, width);
}

static __always_inline __u64 x86_signed_abs_width(__u64 value, __u8 width)
{
	return kprog_x86_abs_width_value(value, width);
}

static __always_inline __u64 x86_ror(__u64 value, __u64 shift, __u8 width)
{
	return kprog_x86_ror_result(value, shift, width);
}

static __always_inline __u64 x86_bswap(__u64 value, __u8 width)
{
	return kprog_x86_bswap_value(value, width);
}

static __always_inline __u64 x86_popcount64(__u64 value)
{
	return kprog_x86_popcount_value(value);
}

static __always_inline __u64 x86_alu_result(__u64 lhs, __u64 rhs,
					    __u32 alu, __u8 width)
{
	if (alu == X86_ALU_ADD)
		return KPROG_X86_ADC_RESULT(lhs, rhs, 0);
	if (alu == X86_ALU_ADC)
		return lhs + rhs;
	if (alu == X86_ALU_SUB)
		return KPROG_X86_SBB_RESULT(lhs, rhs, 0);
	if (alu == X86_ALU_SBB)
		return lhs - rhs;
	if (alu == X86_ALU_XOR)
		return lhs ^ rhs;
	if (alu == X86_ALU_OR)
		return lhs | rhs;
	if (alu == X86_ALU_AND)
		return lhs & rhs;
	if (alu == X86_ALU_SHL)
		return kprog_x86_shl_result(lhs, rhs, width);
	if (alu == X86_ALU_SHR)
		return kprog_x86_shr_result(lhs, rhs, width);
	if (alu == X86_ALU_SAR)
		return kprog_x86_sar_result(lhs, rhs, width);
	if (alu == X86_ALU_ROL)
		return kprog_x86_rol_result(lhs, rhs, width);
	if (alu == X86_ALU_IMUL)
		return lhs * rhs;
	if (alu == X86_ALU_INC)
		return KPROG_X86_ADC_RESULT(lhs, 1, 0);
	if (alu == X86_ALU_DEC)
		return KPROG_X86_SBB_RESULT(lhs, 1, 0);
	if (alu == X86_ALU_NOT)
		return KPROG_X86_NOT_RESULT(lhs);
	if (alu == X86_ALU_NEG)
		return KPROG_X86_SBB_RESULT(0, lhs, 0);
	return lhs;
}

static __always_inline __u64 x86_shld(__u64 dst, __u64 src, __u64 shift,
				      __u8 width)
{
	return kprog_x86_shld_value(dst, src, shift, width);
}

static __always_inline __u64 x86_shrd(__u64 dst, __u64 src, __u64 shift,
				      __u8 width)
{
	return kprog_x86_shrd_value(dst, src, shift, width);
}

static __always_inline __s64 x86_simm(__u64 value)
{
	return (__s64)value;
}

static __always_inline __u64 x86_store_imm_value(__u64 value, __u8 width)
{
	return KPROG_X86_IMMEDIATE_VALUE(value, width);
}

static __always_inline __s32 x86_store_imm_disp(__u64 value)
{
	return (__s32)(value >> 32);
}

#endif
