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
#define ARM64_OP_ADDS_REG 0x42U
#define ARM64_OP_BICS_REG 0x43U
#define ARM64_OP_CSETM 0x44U
#define ARM64_OP_CSNEG 0x45U
#define ARM64_OP_RET 0xffU

#include "../formal/generated/arm64_decode.h"

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
#include "../formal/generated/arm64_width.h"

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

#endif
