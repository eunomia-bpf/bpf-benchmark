#ifndef ARM64_SIM_LOCAL_BPF_H
#define ARM64_SIM_LOCAL_BPF_H

#include <linux/bpf.h>
#include <bpf_helpers.h>

#include "arm64_sim.h"

#define ARM64_SIM_CONCAT2(A, B) A##B
#define ARM64_SIM_CONCAT(A, B) ARM64_SIM_CONCAT2(A, B)

#ifndef ARM64_SIM_RETURN_CASES
#define ARM64_SIM_RETURN_CASES
#endif

#define ARM64_SIM_L_FOR_EACH_GPR(X)                                         \
	X(ARM64_X0, x0)                                                     \
	X(ARM64_X1, x1)                                                     \
	X(ARM64_X2, x2)                                                     \
	X(ARM64_X3, x3)                                                     \
	X(ARM64_X4, x4)                                                     \
	X(ARM64_X5, x5)                                                     \
	X(ARM64_X6, x6)                                                     \
	X(ARM64_X7, x7)                                                     \
	X(ARM64_X8, x8)                                                     \
	X(ARM64_X9, x9)                                                     \
	X(ARM64_X10, x10)                                                   \
	X(ARM64_X11, x11)                                                   \
	X(ARM64_X12, x12)                                                   \
	X(ARM64_X13, x13)                                                   \
	X(ARM64_X14, x14)                                                   \
	X(ARM64_X15, x15)                                                   \
	X(ARM64_X16, x16)                                                   \
	X(ARM64_X17, x17)                                                   \
	X(ARM64_X18, x18)                                                   \
	X(ARM64_X19, x19)                                                   \
	X(ARM64_X20, x20)                                                   \
	X(ARM64_X21, x21)                                                   \
	X(ARM64_X22, x22)                                                   \
	X(ARM64_X23, x23)                                                   \
	X(ARM64_X24, x24)                                                   \
	X(ARM64_X25, x25)                                                   \
	X(ARM64_X26, x26)                                                   \
	X(ARM64_X27, x27)                                                   \
	X(ARM64_X28, x28)                                                   \
	X(ARM64_X29, x29)                                                   \
	X(ARM64_X30, x30)

union arm64_sim_gpr {
	void *ptr;
	__u64 x;
	__u32 w;
};

struct arm64_sim_xdp_abi {
	void *data;
	void *data_end;
	__u32 cb[5];
};

struct arm64_sim_skb_abi {
	__u8 pad0[ARM64_SKB_CB_OFF];
	__u32 cb[5];
	__u8 pad1[ARM64_SKB_DATA_END_OFF - ARM64_SKB_CB_OFF - sizeof(__u32) * 5];
	void *data_end;
	__u8 pad2[ARM64_SKB_DATA_OFF - ARM64_SKB_DATA_END_OFF - sizeof(void *)];
	void *data;
};

#define ARM64_SIM_L_DECLARE_REG(REG, NAME)                                  \
	union arm64_sim_gpr __a64_##NAME = { .x = 0 };

#ifdef ARM64_SIM_ENABLE_STACK
#define ARM64_SIM_L_DECLARE_STACK()                                         \
	union {                                                            \
		__u8 b[160];                                              \
		__u64 q[20];                                              \
	} __a64_stack = {};                                            \
	__s64 __a64_sp = 0
#else
#define ARM64_SIM_L_DECLARE_STACK()                                         \
	union {                                                            \
		__u8 b[1];                                                \
		__u64 q[1];                                               \
	} __a64_stack = {};                                             \
	__s64 __a64_sp = 0
#endif

#define ARM64_SIM_L_DECLARE_STATE()                                         \
	ARM64_SIM_L_FOR_EACH_GPR(ARM64_SIM_L_DECLARE_REG)                  \
	__u8 __a64_n = 0;                                                  \
	__u8 __a64_z = 0;                                                  \
	__u8 __a64_c = 0;                                                  \
	__u8 __a64_v = 0;                                                  \
	__u64 __a64_lr = 0;                                                \
	__u64 __a64_v0 = 0;                                                \
	volatile __u32 __a64_loop_budget = 4096

#define ARM64_SIM_ENTRY_XDP(CTX)                                            \
	struct arm64_sim_xdp_abi __a64_sim_abi = {                         \
		.data = (void *)(long)(CTX)->data,                         \
		.data_end = (void *)(long)(CTX)->data_end,                 \
	};                                                               \
	struct __sk_buff *__a64_sim_skb_ctx = (struct __sk_buff *)0;      \
	ARM64_SIM_L_DECLARE_STATE();                                      \
	ARM64_SIM_L_DECLARE_STACK();                                      \
	__a64_x0.ptr = &__a64_sim_abi

#define ARM64_SIM_ENTRY_SKB(CTX)                                            \
	struct arm64_sim_skb_abi __a64_sim_abi = {                         \
		.data_end = (void *)(long)(CTX)->data_end,                 \
		.data = (void *)(long)(CTX)->data,                         \
	};                                                               \
	struct __sk_buff *__a64_sim_skb_ctx = (CTX);                      \
	ARM64_SIM_L_DECLARE_STATE();                                      \
	ARM64_SIM_L_DECLARE_STACK();                                      \
	__a64_x0.ptr = &__a64_sim_abi

#define ARM64_SIM_L_READ_REG_CASE(REG, NAME)                                \
	case REG:                                                          \
		__a64_l_value = __a64_##NAME.x;                          \
		break;

#define ARM64_SIM_L_READ_REG(REG)                                           \
	({                                                                 \
		__u64 __a64_l_value = 0;                                  \
		if ((REG) == ARM64_SP) {                                  \
			__a64_l_value = (__u64)__a64_sp;                  \
		} else {                                                   \
			switch (REG) {                                    \
			ARM64_SIM_L_FOR_EACH_GPR(ARM64_SIM_L_READ_REG_CASE)\
			case ARM64_XZR:                                   \
			default:                                          \
				__a64_l_value = 0;                        \
				break;                                    \
			}                                                 \
		}                                                         \
		__a64_l_value;                                            \
	})

#define ARM64_SIM_L_REG_PTR_CASE(REG, NAME)                                 \
	case REG:                                                          \
		__a64_l_ptr = __a64_##NAME.ptr;                         \
		break;

#define ARM64_SIM_L_READ_REG_PTR(REG)                                       \
	({                                                                 \
		void *__a64_l_ptr = (void *)0;                            \
		switch (REG) {                                            \
		ARM64_SIM_L_FOR_EACH_GPR(ARM64_SIM_L_REG_PTR_CASE)        \
		default:                                                  \
			__a64_l_ptr = (void *)0;                          \
			break;                                            \
		}                                                         \
		__a64_l_ptr;                                              \
	})

#define ARM64_SIM_L_WRITE_REG64_CASE(REG, NAME)                             \
	case REG:                                                          \
		__a64_##NAME.x = __a64_l_next;                          \
		break;

#define ARM64_SIM_L_WRITE_REG32_CASE(REG, NAME)                             \
	case REG:                                                          \
		__a64_##NAME.x = (__u32)__a64_l_next;                   \
		break;

#define ARM64_SIM_L_WRITE_REG_PTR_CASE(REG, NAME)                           \
	case REG:                                                          \
		__a64_##NAME.ptr = __a64_l_next_ptr;                    \
		break;

#define ARM64_SIM_L_WRITE_REG_WIDTH(REG, VALUE, WIDTH)                      \
	do {                                                               \
		__u64 __a64_l_next = arm64_apply_width((VALUE), (WIDTH)); \
		if ((REG) == ARM64_SP) {                                  \
			__a64_sp = (__s64)__a64_l_next;                   \
		} else if ((REG) != ARM64_XZR && (REG) != ARM64_REG_NONE) {\
			if ((WIDTH) == ARM64_WIDTH_32) {                  \
				switch (REG) {                            \
				ARM64_SIM_L_FOR_EACH_GPR(ARM64_SIM_L_WRITE_REG32_CASE)\
				default: break;                           \
				}                                         \
			} else {                                            \
				switch (REG) {                            \
				ARM64_SIM_L_FOR_EACH_GPR(ARM64_SIM_L_WRITE_REG64_CASE)\
				default: break;                           \
				}                                         \
			}                                                   \
		}                                                          \
	} while (0)

#define ARM64_SIM_L_WRITE_REG_PTR(REG, VALUE)                               \
	do {                                                               \
		void *__a64_l_next_ptr = (void *)(VALUE);                \
		if ((REG) != ARM64_XZR && (REG) != ARM64_REG_NONE) {      \
			switch (REG) {                                    \
			ARM64_SIM_L_FOR_EACH_GPR(ARM64_SIM_L_WRITE_REG_PTR_CASE)\
			default: break;                                   \
			}                                                 \
		}                                                          \
	} while (0)

#define ARM64_SIM_L_MOD(AUX) (((AUX) >> 8) & 0xffU)
#define ARM64_SIM_L_SHIFT(AUX) (((AUX) >> 16) & 0xffU)
#define ARM64_SIM_L_MEM_INDEX(AUX) ((AUX) & 0xffU)
#define ARM64_SIM_L_MEM_FLAGS(AUX) (((AUX) >> 24) & 0xffU)
#define ARM64_SIM_L_BITFIELD_LSB(AUX) (((AUX) >> 8) & 0xffU)
#define ARM64_SIM_L_BITFIELD_WIDTH(AUX) (((AUX) >> 16) & 0xffU)
#define ARM64_SIM_L_CCMP_NZCV(AUX) (((AUX) >> 8) & 0xffU)

#define ARM64_SIM_L_MOD_VALUE(REG, MOD, SHIFT, WIDTH)                       \
	({                                                                 \
		__u64 __a64_l_value = ARM64_SIM_L_READ_REG(REG);          \
		__u8 __a64_l_mod = (MOD);                                 \
		__u8 __a64_l_shift = (SHIFT);                             \
		if (__a64_l_mod == ARM64_MOD_LSL)                         \
			__a64_l_value = arm64_lsl(__a64_l_value, __a64_l_shift, (WIDTH));\
		else if (__a64_l_mod == ARM64_MOD_LSR)                    \
			__a64_l_value = arm64_lsr(__a64_l_value, __a64_l_shift, (WIDTH));\
		else if (__a64_l_mod == ARM64_MOD_ASR)                    \
			__a64_l_value = arm64_asr(__a64_l_value, __a64_l_shift, (WIDTH));\
		else if (__a64_l_mod == ARM64_MOD_ROR)                    \
			__a64_l_value = arm64_ror(__a64_l_value, __a64_l_shift, (WIDTH));\
		else if (__a64_l_mod == ARM64_MOD_UXTW)                   \
			__a64_l_value = ((__u64)(__u32)__a64_l_value) << __a64_l_shift;\
		else if (__a64_l_mod == ARM64_MOD_SXTW)                   \
			__a64_l_value = ((__u64)(__s64)(__s32)__a64_l_value) << __a64_l_shift;\
		else if (__a64_l_mod == ARM64_MOD_UXTH)                   \
			__a64_l_value = ((__u64)(__u16)__a64_l_value) << __a64_l_shift;\
		else if (__a64_l_mod == ARM64_MOD_SXTH)                   \
			__a64_l_value = ((__u64)(__s64)(__s16)__a64_l_value) << __a64_l_shift;\
		else if (__a64_l_mod == ARM64_MOD_UXTB)                   \
			__a64_l_value = ((__u64)(__u8)__a64_l_value) << __a64_l_shift;\
		else if (__a64_l_mod == ARM64_MOD_SXTB)                   \
			__a64_l_value = ((__u64)(__s64)(__s8)__a64_l_value) << __a64_l_shift;\
		__a64_l_value;                                            \
	})

#define ARM64_SIM_L_STACK_INDEX(OFF) ((__u32)(ARM64_SIM_STACK_BIAS + (OFF)))

#define ARM64_SIM_L_STACK_READ(OFF, WIDTH)                                  \
	({                                                                 \
		__u32 __a64_str_index = ARM64_SIM_L_STACK_INDEX(OFF);     \
		__u8 __a64_str_width = (WIDTH);                           \
		__u64 __a64_str_value = __a64_stack.b[__a64_str_index];   \
		if (__a64_str_width >= ARM64_WIDTH_16)                    \
			__a64_str_value |= (__u64)__a64_stack.b[__a64_str_index + 1] << 8;\
		if (__a64_str_width >= ARM64_WIDTH_32) {                  \
			__a64_str_value |= (__u64)__a64_stack.b[__a64_str_index + 2] << 16;\
			__a64_str_value |= (__u64)__a64_stack.b[__a64_str_index + 3] << 24;\
		}                                                         \
		if (__a64_str_width == ARM64_WIDTH_64) {                  \
			__a64_str_value |= (__u64)__a64_stack.b[__a64_str_index + 4] << 32;\
			__a64_str_value |= (__u64)__a64_stack.b[__a64_str_index + 5] << 40;\
			__a64_str_value |= (__u64)__a64_stack.b[__a64_str_index + 6] << 48;\
			__a64_str_value |= (__u64)__a64_stack.b[__a64_str_index + 7] << 56;\
		}                                                         \
		__a64_str_value;                                          \
	})

#define ARM64_SIM_L_STACK_WRITE(OFF, WIDTH, VALUE)                          \
	do {                                                               \
		__u32 __a64_stw_index = ARM64_SIM_L_STACK_INDEX(OFF);     \
		__u8 __a64_stw_width = (WIDTH);                           \
		__u64 __a64_stw_value = arm64_apply_width((VALUE), __a64_stw_width);\
		__a64_stack.b[__a64_stw_index] = (__u8)__a64_stw_value;   \
		if (__a64_stw_width >= ARM64_WIDTH_16)                    \
			__a64_stack.b[__a64_stw_index + 1] = (__u8)(__a64_stw_value >> 8);\
		if (__a64_stw_width >= ARM64_WIDTH_32) {                  \
			__a64_stack.b[__a64_stw_index + 2] = (__u8)(__a64_stw_value >> 16);\
			__a64_stack.b[__a64_stw_index + 3] = (__u8)(__a64_stw_value >> 24);\
		}                                                         \
		if (__a64_stw_width == ARM64_WIDTH_64) {                  \
			__a64_stack.b[__a64_stw_index + 4] = (__u8)(__a64_stw_value >> 32);\
			__a64_stack.b[__a64_stw_index + 5] = (__u8)(__a64_stw_value >> 40);\
			__a64_stack.b[__a64_stw_index + 6] = (__u8)(__a64_stw_value >> 48);\
			__a64_stack.b[__a64_stw_index + 7] = (__u8)(__a64_stw_value >> 56);\
		}                                                         \
	} while (0)

#define ARM64_SIM_L_LOAD_ADDR(ADDR, WIDTH)                                  \
	({                                                                 \
		__u8 *__a64_lda_addr = (__u8 *)(ADDR);                   \
		__u8 __a64_lda_width = (WIDTH);                           \
		__u64 __a64_lda_value;                                    \
		if (__a64_lda_width == ARM64_WIDTH_8)                     \
			__a64_lda_value = *(__u8 *)__a64_lda_addr;        \
		else if (__a64_lda_width == ARM64_WIDTH_16)               \
			__a64_lda_value = *(__u16 *)__a64_lda_addr;       \
		else if (__a64_lda_width == ARM64_WIDTH_32)               \
			__a64_lda_value = *(__u32 *)__a64_lda_addr;       \
		else                                                      \
			__a64_lda_value = *(__u64 *)__a64_lda_addr;       \
		__a64_lda_value;                                          \
	})

#define ARM64_SIM_L_STORE_ADDR(ADDR, WIDTH, VALUE)                          \
	do {                                                               \
		__u8 *__a64_sta_addr = (__u8 *)(ADDR);                   \
		__u8 __a64_sta_width = (WIDTH);                           \
		__u64 __a64_sta_value = arm64_apply_width((VALUE), __a64_sta_width);\
		if (__a64_sta_width == ARM64_WIDTH_8)                     \
			*(__u8 *)__a64_sta_addr = __a64_sta_value;        \
		else if (__a64_sta_width == ARM64_WIDTH_16)               \
			*(__u16 *)__a64_sta_addr = __a64_sta_value;       \
		else if (__a64_sta_width == ARM64_WIDTH_32)               \
			*(__u32 *)__a64_sta_addr = __a64_sta_value;       \
		else                                                      \
			*(__u64 *)__a64_sta_addr = __a64_sta_value;       \
	} while (0)

#define ARM64_SIM_L_MEM_BASE_OFF(AUX, INDEX, IMM)                           \
	({                                                                 \
		__s64 __a64_mbo_off = 0;                                \
		if (!(ARM64_SIM_L_MEM_FLAGS(AUX) & (ARM64_MEM_PRE | ARM64_MEM_POST)))\
			__a64_mbo_off = (__s64)(IMM);                     \
		if ((INDEX) != ARM64_REG_NONE)                           \
			__a64_mbo_off += (__s64)ARM64_SIM_L_MOD_VALUE((INDEX),\
				ARM64_SIM_L_MOD(AUX), ARM64_SIM_L_SHIFT(AUX), ARM64_WIDTH_64);\
		__a64_mbo_off;                                            \
	})

#define ARM64_SIM_L_MEM_PRE(BASE, AUX, IMM)                                 \
	do {                                                               \
		if (ARM64_SIM_L_MEM_FLAGS(AUX) & ARM64_MEM_PRE) {         \
			__s64 __a64_l_pre = (__s64)(IMM);                 \
			if ((BASE) == ARM64_SP)                            \
				__a64_sp += __a64_l_pre;                  \
			else                                               \
				ARM64_SIM_L_WRITE_REG_PTR((BASE),         \
					(__u8 *)ARM64_SIM_L_READ_REG_PTR(BASE) + __a64_l_pre);\
		}                                                          \
	} while (0)

#define ARM64_SIM_L_MEM_POST(BASE, AUX, IMM)                                \
	do {                                                               \
		if (ARM64_SIM_L_MEM_FLAGS(AUX) & ARM64_MEM_POST) {        \
			__s64 __a64_l_post = (__s64)(IMM);                \
			if ((BASE) == ARM64_SP)                            \
				__a64_sp += __a64_l_post;                 \
			else                                               \
				ARM64_SIM_L_WRITE_REG_PTR((BASE),         \
					(__u8 *)ARM64_SIM_L_READ_REG_PTR(BASE) + __a64_l_post);\
		}                                                          \
	} while (0)

#define ARM64_SIM_L_MEM_READ(BASE, INDEX, AUX, IMM, EXTRA, WIDTH)            \
	({                                                                 \
		__s64 __a64_mrd_off = ARM64_SIM_L_MEM_BASE_OFF((AUX), (INDEX), (IMM)) + (EXTRA);\
		__u64 __a64_mrd_value;                                    \
		if ((BASE) == ARM64_SP) {                                 \
			__a64_mrd_value = ARM64_SIM_L_STACK_READ(__a64_sp + __a64_mrd_off, (WIDTH));\
		} else {                                                   \
			void *__a64_mrd_addr = (__u8 *)ARM64_SIM_L_READ_REG_PTR(BASE) + __a64_mrd_off;\
			__a64_mrd_value = ARM64_SIM_L_LOAD_ADDR(__a64_mrd_addr, (WIDTH));\
		}                                                         \
		__a64_mrd_value;                                          \
	})

#define ARM64_SIM_L_MEM_WRITE(BASE, INDEX, AUX, IMM, EXTRA, WIDTH, VALUE)    \
	do {                                                               \
		__s64 __a64_mwr_off = ARM64_SIM_L_MEM_BASE_OFF((AUX), (INDEX), (IMM)) + (EXTRA);\
		if ((BASE) == ARM64_SP) {                                 \
			ARM64_SIM_L_STACK_WRITE(__a64_sp + __a64_mwr_off, (WIDTH), (VALUE));\
		} else {                                                   \
			void *__a64_mwr_addr = (__u8 *)ARM64_SIM_L_READ_REG_PTR(BASE) + __a64_mwr_off;\
			ARM64_SIM_L_STORE_ADDR(__a64_mwr_addr, (WIDTH), (VALUE));\
		}                                                         \
	} while (0)

#define ARM64_SIM_L_SET_SUB_FLAGS(LHS, RHS, WIDTH)                          \
	do {                                                               \
		__u8 __a64_sub_width = (WIDTH);                           \
		__u64 __a64_sub_mask = arm64_width_mask(__a64_sub_width); \
		__u64 __a64_sub_lhs = (LHS) & __a64_sub_mask;             \
		__u64 __a64_sub_rhs = (RHS) & __a64_sub_mask;             \
		__u64 __a64_sub_res = (__a64_sub_lhs - __a64_sub_rhs) & __a64_sub_mask;\
		__u64 __a64_sub_sign = arm64_sign_bit(__a64_sub_width);   \
		__a64_z = __a64_sub_res == 0;                             \
		__a64_n = (__a64_sub_res & __a64_sub_sign) != 0;          \
		__a64_c = __a64_sub_lhs >= __a64_sub_rhs;                 \
		__a64_v = ((__a64_sub_lhs ^ __a64_sub_rhs) & (__a64_sub_lhs ^ __a64_sub_res) & __a64_sub_sign) != 0;\
	} while (0)

#define ARM64_SIM_L_SET_LOGIC_FLAGS(VALUE, WIDTH)                           \
	do {                                                               \
		__u8 __a64_log_width = (WIDTH);                           \
		__u64 __a64_log_value = arm64_apply_width((VALUE), __a64_log_width);\
		__u64 __a64_log_sign = arm64_sign_bit(__a64_log_width);   \
		__a64_z = __a64_log_value == 0;                            \
		__a64_n = (__a64_log_value & __a64_log_sign) != 0;         \
		__a64_c = 0;                                               \
		__a64_v = 0;                                               \
	} while (0)

#define ARM64_SIM_L_EVAL_COND(COND)                                         \
	((COND) == ARM64_COND_EQ ? __a64_z :                                  \
	 (COND) == ARM64_COND_NE ? !__a64_z :                                 \
	 (COND) == ARM64_COND_CS ? __a64_c :                                  \
	 (COND) == ARM64_COND_CC ? !__a64_c :                                 \
	 (COND) == ARM64_COND_MI ? __a64_n :                                  \
	 (COND) == ARM64_COND_PL ? !__a64_n :                                 \
	 (COND) == ARM64_COND_VS ? __a64_v :                                  \
	 (COND) == ARM64_COND_VC ? !__a64_v :                                 \
	 (COND) == ARM64_COND_HI ? (__a64_c && !__a64_z) :                    \
	 (COND) == ARM64_COND_LS ? (!__a64_c || __a64_z) :                    \
	 (COND) == ARM64_COND_GE ? (__a64_n == __a64_v) :                     \
	 (COND) == ARM64_COND_LT ? (__a64_n != __a64_v) :                     \
	 (COND) == ARM64_COND_GT ? (!__a64_z && (__a64_n == __a64_v)) :       \
	 (COND) == ARM64_COND_LE ? (__a64_z || (__a64_n != __a64_v)) : 1)

#define ARM64_SIM_L_UNSUPPORTED_OPCODE()                                    \
	do {                                                               \
		extern void arm64_sim_unsupported_opcode(void);           \
		arm64_sim_unsupported_opcode();                           \
	} while (0)

#define ARM64_SIM_L_EXEC_ALU(OP, DST, SRC, SRC2, FLAGS, AUX, IMM)           \
	do {                                                               \
		__u8 __a64_alu_width = (FLAGS);                           \
		__u64 __a64_alu_lhs = ARM64_SIM_L_READ_REG(SRC);          \
		__u64 __a64_alu_rhs = (OP) == ARM64_OP_ALU_IMM ? (__u64)(IMM) :\
			ARM64_SIM_L_MOD_VALUE((SRC2), ARM64_SIM_L_MOD(AUX), ARM64_SIM_L_SHIFT(AUX), __a64_alu_width);\
		__u8 __a64_alu_op = (AUX) & 0xffU;                        \
		__u64 __a64_alu_result = 0;                               \
		if (__a64_alu_op == ARM64_ALU_ADD)                        \
			__a64_alu_result = __a64_alu_lhs + __a64_alu_rhs; \
		else if (__a64_alu_op == ARM64_ALU_SUB)                   \
			__a64_alu_result = __a64_alu_lhs - __a64_alu_rhs; \
		else if (__a64_alu_op == ARM64_ALU_AND)                   \
			__a64_alu_result = __a64_alu_lhs & __a64_alu_rhs; \
		else if (__a64_alu_op == ARM64_ALU_BIC)                   \
			__a64_alu_result = __a64_alu_lhs & ~__a64_alu_rhs;\
		else if (__a64_alu_op == ARM64_ALU_EOR)                   \
			__a64_alu_result = __a64_alu_lhs ^ __a64_alu_rhs; \
		else if (__a64_alu_op == ARM64_ALU_ORR)                   \
			__a64_alu_result = __a64_alu_lhs | __a64_alu_rhs; \
		if (__a64_alu_width == ARM64_WIDTH_64 &&                  \
		    __a64_alu_op == ARM64_ALU_ADD)                        \
			ARM64_SIM_L_WRITE_REG_PTR((DST),                  \
				(__u8 *)ARM64_SIM_L_READ_REG_PTR(SRC) + __a64_alu_rhs);\
		else                                                       \
			ARM64_SIM_L_WRITE_REG_WIDTH((DST), __a64_alu_result, __a64_alu_width);\
	} while (0)

#define ARM64_SIM_L_EXEC(OP, DST, SRC, SRC2, SRC3, FLAGS, AUX, IMM)         \
	do {                                                               \
		__u8 __a64_l_width = (FLAGS) ? (FLAGS) : ARM64_WIDTH_64;  \
		if ((OP) == ARM64_OP_NOP) {                                \
			(void)0;                                           \
		} else if ((OP) == ARM64_OP_MOV_IMM) {                     \
			ARM64_SIM_L_WRITE_REG_WIDTH((DST), (IMM), __a64_l_width);\
		} else if ((OP) == ARM64_OP_MOV_REG) {                     \
			if (__a64_l_width == ARM64_WIDTH_64)               \
				ARM64_SIM_L_WRITE_REG_PTR((DST), ARM64_SIM_L_READ_REG_PTR(SRC));\
			else                                               \
				ARM64_SIM_L_WRITE_REG_WIDTH((DST), ARM64_SIM_L_READ_REG(SRC), __a64_l_width);\
		} else if ((OP) == ARM64_OP_MOVK) {                        \
			__u8 __a64_l_shift = ARM64_SIM_L_SHIFT(AUX);       \
			__u64 __a64_l_mask = 0xffffULL << __a64_l_shift;   \
			__u64 __a64_l_value = (ARM64_SIM_L_READ_REG(DST) & ~__a64_l_mask) | (((__u64)(IMM) << __a64_l_shift) & __a64_l_mask);\
			ARM64_SIM_L_WRITE_REG_WIDTH((DST), __a64_l_value, __a64_l_width);\
		} else if ((OP) == ARM64_OP_ALU_IMM || (OP) == ARM64_OP_ALU_REG) {\
			ARM64_SIM_L_EXEC_ALU((OP), (DST), (SRC), (SRC2), __a64_l_width, (AUX), (IMM));\
		} else if ((OP) == ARM64_OP_SHIFT_IMM || (OP) == ARM64_OP_SHIFT_REG) {\
			__u8 __a64_l_shift = (OP) == ARM64_OP_SHIFT_IMM ? (__u8)(IMM) : (__u8)ARM64_SIM_L_READ_REG(SRC2);\
			__u64 __a64_l_value = ARM64_SIM_L_READ_REG(SRC);  \
			__u64 __a64_l_result = (AUX) == ARM64_SHIFT_LSL ? arm64_lsl(__a64_l_value, __a64_l_shift, __a64_l_width) :\
				(AUX) == ARM64_SHIFT_LSR ? arm64_lsr(__a64_l_value, __a64_l_shift, __a64_l_width) :\
				(AUX) == ARM64_SHIFT_ASR ? arm64_asr(__a64_l_value, __a64_l_shift, __a64_l_width) :\
				arm64_ror(__a64_l_value, __a64_l_shift, __a64_l_width);\
			ARM64_SIM_L_WRITE_REG_WIDTH((DST), __a64_l_result, __a64_l_width);\
		} else if ((OP) == ARM64_OP_MADD || (OP) == ARM64_OP_MSUB) { \
			__u64 __a64_l_product = ARM64_SIM_L_READ_REG(SRC) * ARM64_SIM_L_READ_REG(SRC2);\
			__u64 __a64_l_result = (OP) == ARM64_OP_MADD ? ARM64_SIM_L_READ_REG(SRC3) + __a64_l_product : ARM64_SIM_L_READ_REG(SRC3) - __a64_l_product;\
			ARM64_SIM_L_WRITE_REG_WIDTH((DST), __a64_l_result, __a64_l_width);\
		} else if ((OP) == ARM64_OP_MUL || (OP) == ARM64_OP_UMULL || (OP) == ARM64_OP_UDIV) {\
			__u64 __a64_l_rhs = ARM64_SIM_L_READ_REG(SRC2);   \
			__u64 __a64_l_result = 0;                         \
			if ((OP) == ARM64_OP_UDIV)                         \
				__a64_l_result = __a64_l_rhs ? ARM64_SIM_L_READ_REG(SRC) / __a64_l_rhs : 0;\
			else if ((OP) == ARM64_OP_UMULL)                   \
				__a64_l_result = (__u64)(__u32)ARM64_SIM_L_READ_REG(SRC) * (__u64)(__u32)__a64_l_rhs;\
			else                                               \
				__a64_l_result = ARM64_SIM_L_READ_REG(SRC) * __a64_l_rhs;\
			ARM64_SIM_L_WRITE_REG_WIDTH((DST), __a64_l_result, __a64_l_width);\
		} else if ((OP) == ARM64_OP_MVN || (OP) == ARM64_OP_NEG) {    \
			__u64 __a64_l_value = ARM64_SIM_L_READ_REG(SRC);     \
			ARM64_SIM_L_WRITE_REG_WIDTH((DST), (OP) == ARM64_OP_MVN ? ~__a64_l_value : -__a64_l_value, __a64_l_width);\
		} else if ((OP) == ARM64_OP_EXTR) {                           \
			__u8 __a64_extr_bits = arm64_width_bits(__a64_l_width);\
			__u8 __a64_extr_shift = (__u8)(IMM) & (__a64_extr_bits - 1U);\
			__u64 __a64_extr_low = ARM64_SIM_L_READ_REG(SRC2) >> __a64_extr_shift;\
			__u64 __a64_extr_high = __a64_extr_shift ? ARM64_SIM_L_READ_REG(SRC) << (__a64_extr_bits - __a64_extr_shift) : 0;\
			ARM64_SIM_L_WRITE_REG_WIDTH((DST), __a64_extr_low | __a64_extr_high, __a64_l_width);\
		} else if ((OP) == ARM64_OP_BITFIELD) {                       \
			__u8 __a64_bf_kind = (AUX) & 0xffU;                  \
			__u8 __a64_bf_lsb = ARM64_SIM_L_BITFIELD_LSB(AUX);   \
			__u8 __a64_bf_bits = ARM64_SIM_L_BITFIELD_WIDTH(AUX);\
			__u64 __a64_bf_mask = arm64_bits_mask(__a64_bf_bits);\
			__u64 __a64_bf_src_r = __a64_bf_lsb >= 64 ? 0 : ARM64_SIM_L_READ_REG(SRC) >> __a64_bf_lsb;\
			__u64 __a64_bf_src_l = __a64_bf_lsb >= 64 ? 0 : ARM64_SIM_L_READ_REG(SRC) << __a64_bf_lsb;\
			__u64 __a64_bf_result;                               \
			if (__a64_bf_kind == ARM64_BITFIELD_UBFX)             \
				__a64_bf_result = __a64_bf_src_r & __a64_bf_mask;\
			else if (__a64_bf_kind == ARM64_BITFIELD_SBFX)        \
				__a64_bf_result = arm64_sign_extend(__a64_bf_src_r & __a64_bf_mask, __a64_bf_bits);\
			else if (__a64_bf_kind == ARM64_BITFIELD_UBFIZ)       \
				__a64_bf_result = __a64_bf_src_l & (__a64_bf_lsb >= 64 ? 0 : __a64_bf_mask << __a64_bf_lsb);\
			else if (__a64_bf_kind == ARM64_BITFIELD_BFXIL)       \
				__a64_bf_result = (ARM64_SIM_L_READ_REG(DST) & ~__a64_bf_mask) | (__a64_bf_src_r & __a64_bf_mask);\
			else {                                                \
				__u64 __a64_bf_field_mask = __a64_bf_lsb >= 64 ? 0 : __a64_bf_mask << __a64_bf_lsb;\
				__a64_bf_result = (ARM64_SIM_L_READ_REG(DST) & ~__a64_bf_field_mask) | (__a64_bf_src_l & __a64_bf_field_mask);\
			}                                                     \
			ARM64_SIM_L_WRITE_REG_WIDTH((DST), __a64_bf_result, __a64_l_width);\
		} else if ((OP) == ARM64_OP_REV || (OP) == ARM64_OP_REV16 || (OP) == ARM64_OP_SXTH) {\
			__u64 __a64_l_value = ARM64_SIM_L_READ_REG(SRC);     \
			if ((OP) == ARM64_OP_REV)                             \
				__a64_l_value = arm64_reverse_bytes(__a64_l_value, __a64_l_width);\
			else if ((OP) == ARM64_OP_REV16)                      \
				__a64_l_value = arm64_reverse_bytes16(__a64_l_value, __a64_l_width);\
			else                                                  \
				__a64_l_value = arm64_sign_extend(__a64_l_value & 0xffffULL, 16);\
			ARM64_SIM_L_WRITE_REG_WIDTH((DST), __a64_l_value, __a64_l_width);\
		} else if ((OP) == ARM64_OP_CMP_IMM || (OP) == ARM64_OP_CMP_REG) {\
			ARM64_SIM_L_SET_SUB_FLAGS(ARM64_SIM_L_READ_REG(DST), (OP) == ARM64_OP_CMP_IMM ? (__u64)(IMM) : ARM64_SIM_L_MOD_VALUE((SRC), ARM64_SIM_L_MOD(AUX), ARM64_SIM_L_SHIFT(AUX), __a64_l_width), __a64_l_width);\
		} else if ((OP) == ARM64_OP_TST_IMM || (OP) == ARM64_OP_TST_REG) {\
			ARM64_SIM_L_SET_LOGIC_FLAGS(ARM64_SIM_L_READ_REG(DST) & ((OP) == ARM64_OP_TST_IMM ? (__u64)(IMM) : ARM64_SIM_L_MOD_VALUE((SRC), ARM64_SIM_L_MOD(AUX), ARM64_SIM_L_SHIFT(AUX), __a64_l_width)), __a64_l_width);\
		} else if ((OP) == ARM64_OP_CCMP_IMM || (OP) == ARM64_OP_CCMP_REG) {\
			if (ARM64_SIM_L_EVAL_COND((AUX) & 0xffU)) {          \
				ARM64_SIM_L_SET_SUB_FLAGS(ARM64_SIM_L_READ_REG(DST), (OP) == ARM64_OP_CCMP_IMM ? (__u64)(IMM) : ARM64_SIM_L_READ_REG(SRC), __a64_l_width);\
			} else {                                             \
				__u8 __a64_l_nzcv = ARM64_SIM_L_CCMP_NZCV(AUX);\
				__a64_n = (__a64_l_nzcv >> 3) & 1;           \
				__a64_z = (__a64_l_nzcv >> 2) & 1;           \
				__a64_c = (__a64_l_nzcv >> 1) & 1;           \
				__a64_v = __a64_l_nzcv & 1;                  \
			}                                                     \
		} else if ((OP) == ARM64_OP_CSEL || (OP) == ARM64_OP_CINC || (OP) == ARM64_OP_CSET) {\
			if ((OP) == ARM64_OP_CSET)                            \
				ARM64_SIM_L_WRITE_REG_WIDTH((DST), ARM64_SIM_L_EVAL_COND(AUX) ? 1 : 0, __a64_l_width);\
			else if ((OP) == ARM64_OP_CINC)                       \
				ARM64_SIM_L_WRITE_REG_WIDTH((DST), ARM64_SIM_L_EVAL_COND(AUX) ? ARM64_SIM_L_READ_REG(SRC) + 1 : ARM64_SIM_L_READ_REG(SRC), __a64_l_width);\
			else if (__a64_l_width == ARM64_WIDTH_64 && ARM64_SIM_L_EVAL_COND(AUX))\
				ARM64_SIM_L_WRITE_REG_PTR((DST), ARM64_SIM_L_READ_REG_PTR(SRC));\
			else if (__a64_l_width == ARM64_WIDTH_64)              \
				ARM64_SIM_L_WRITE_REG_PTR((DST), ARM64_SIM_L_READ_REG_PTR(SRC2));\
			else                                                   \
				ARM64_SIM_L_WRITE_REG_WIDTH((DST), ARM64_SIM_L_EVAL_COND(AUX) ? ARM64_SIM_L_READ_REG(SRC) : ARM64_SIM_L_READ_REG(SRC2), __a64_l_width);\
		} else if ((OP) == ARM64_OP_LOAD) {                            \
			ARM64_SIM_L_MEM_PRE((SRC), (AUX), (IMM));              \
			__u64 __a64_l_value = ARM64_SIM_L_MEM_READ((SRC), (SRC2), (AUX), (IMM), 0, __a64_l_width);\
			if (__a64_l_width == ARM64_WIDTH_64 && (SRC) != ARM64_SP)\
				ARM64_SIM_L_WRITE_REG_PTR((DST), (void *)(long)__a64_l_value);\
			else                                                   \
				ARM64_SIM_L_WRITE_REG_WIDTH((DST), __a64_l_value, __a64_l_width);\
			ARM64_SIM_L_MEM_POST((SRC), (AUX), (IMM));             \
		} else if ((OP) == ARM64_OP_STORE) {                           \
			ARM64_SIM_L_MEM_PRE((DST), (AUX), (IMM));              \
			ARM64_SIM_L_MEM_WRITE((DST), (SRC2), (AUX), (IMM), 0, __a64_l_width, ARM64_SIM_L_READ_REG(SRC));\
			ARM64_SIM_L_MEM_POST((DST), (AUX), (IMM));             \
		} else if ((OP) == ARM64_OP_LDP) {                             \
			ARM64_SIM_L_MEM_PRE((SRC2), (AUX), (IMM));             \
			__u64 __a64_l_v0 = ARM64_SIM_L_MEM_READ((SRC2), (SRC3), (AUX), (IMM), 0, __a64_l_width);\
			__u64 __a64_l_v1 = ARM64_SIM_L_MEM_READ((SRC2), (SRC3), (AUX), (IMM), __a64_l_width, __a64_l_width);\
			if (__a64_l_width == ARM64_WIDTH_64 && (SRC2) != ARM64_SP) {\
				ARM64_SIM_L_WRITE_REG_PTR((DST), (void *)(long)__a64_l_v0);\
				ARM64_SIM_L_WRITE_REG_PTR((SRC), (void *)(long)__a64_l_v1);\
			} else {                                                \
				ARM64_SIM_L_WRITE_REG_WIDTH((DST), __a64_l_v0, __a64_l_width);\
				ARM64_SIM_L_WRITE_REG_WIDTH((SRC), __a64_l_v1, __a64_l_width);\
			}                                                     \
			ARM64_SIM_L_MEM_POST((SRC2), (AUX), (IMM));            \
		} else if ((OP) == ARM64_OP_STP) {                             \
			ARM64_SIM_L_MEM_PRE((DST), (AUX), (IMM));              \
			ARM64_SIM_L_MEM_WRITE((DST), (SRC3), (AUX), (IMM), 0, __a64_l_width, ARM64_SIM_L_READ_REG(SRC));\
			ARM64_SIM_L_MEM_WRITE((DST), (SRC3), (AUX), (IMM), __a64_l_width, __a64_l_width, ARM64_SIM_L_READ_REG(SRC2));\
			ARM64_SIM_L_MEM_POST((DST), (AUX), (IMM));             \
		} else if ((OP) == ARM64_OP_FMOV) {                            \
			if ((AUX) == ARM64_FMOV_D_FROM_X || (AUX) == ARM64_FMOV_S_FROM_W)\
				__a64_v0 = ARM64_SIM_L_READ_REG(SRC);          \
			else                                                   \
				ARM64_SIM_L_WRITE_REG_WIDTH((DST), __a64_v0, __a64_l_width);\
		} else if ((OP) == ARM64_OP_CNT) {                             \
			__a64_v0 = arm64_replicate_byte_popcounts(__a64_v0);   \
		} else if ((OP) == ARM64_OP_UADDLV) {                          \
			__a64_v0 = arm64_horizontal_add_u8(__a64_v0) & 0xffffULL;\
		} else {                                                       \
			ARM64_SIM_L_UNSUPPORTED_OPCODE();                      \
		}                                                            \
	} while (0)

#define ARM64_SIM_RUN_OP3(OP, DST, SRC, SRC2, SRC3, FLAGS, AUX, IMM)        \
	ARM64_SIM_L_EXEC((OP), (DST), (SRC), (SRC2), (SRC3), (FLAGS), (AUX), (IMM))

#define ARM64_SIM_RUN_OP(OP, DST, SRC, FLAGS, AUX, IMM)                     \
	ARM64_SIM_RUN_OP3((OP), (DST), (SRC), ARM64_REG_NONE, ARM64_REG_NONE, (FLAGS), (AUX), (IMM))

#define ARM64_SIM_RET()                                                     \
	do {                                                               \
		if (__a64_sim_skb_ctx) {                                   \
			__a64_sim_skb_ctx->cb[0] = __a64_sim_abi.cb[0];    \
			__a64_sim_skb_ctx->cb[1] = __a64_sim_abi.cb[1];    \
		}                                                          \
		return (__u32)__a64_x0.x;                                  \
	} while (0)

#define ARM64_SIM_A64_JMP(CURRENT, TARGET, LABEL)                           \
	do {                                                               \
		if ((TARGET) <= (CURRENT))                                 \
			ARM64_SIM_A64_BACKWARD_GOTO(LABEL);                \
		else                                                       \
			goto LABEL;                                        \
	} while (0)

#define ARM64_SIM_A64_BACKWARD_GOTO(LABEL)                                  \
	do {                                                               \
		if (!__a64_loop_budget)                                   \
			ARM64_SIM_RET();                                  \
		__a64_loop_budget--;                                      \
		goto LABEL;                                                \
	} while (0)

#define ARM64_SIM_A64_JCC_BACKWARD(COND, LABEL, ID)                         \
	do {                                                               \
		if (!ARM64_SIM_L_EVAL_COND(COND)) {                       \
			goto ARM64_SIM_CONCAT(__a64_sim_jcc_fallthrough_, ID);\
		}                                                          \
		ARM64_SIM_A64_BACKWARD_GOTO(LABEL);                       \
ARM64_SIM_CONCAT(__a64_sim_jcc_fallthrough_, ID):                            \
		;                                                          \
	} while (0)

#define ARM64_SIM_A64_JCC_IMPL(COND, CURRENT, TARGET, LABEL, ID)            \
	do {                                                               \
		if ((TARGET) <= (CURRENT)) {                                \
			ARM64_SIM_A64_JCC_BACKWARD((COND), LABEL, ID);     \
		} else if (ARM64_SIM_L_EVAL_COND(COND)) {                  \
			ARM64_SIM_A64_JMP((CURRENT), (TARGET), LABEL);     \
		}                                                          \
	} while (0)

#define ARM64_SIM_A64_JCC(COND, CURRENT, TARGET, LABEL)                     \
	ARM64_SIM_A64_JCC_IMPL((COND), (CURRENT), (TARGET), LABEL, __LINE__)

#define ARM64_SIM_A64_CBZ_IMPL(REG, ZERO, CURRENT, TARGET, LABEL, ID)       \
	do {                                                               \
		__u64 __a64_l_value = ARM64_SIM_L_READ_REG(REG);          \
		if ((TARGET) <= (CURRENT)) {                              \
			if (((__a64_l_value == 0) != (ZERO)))             \
				goto ARM64_SIM_CONCAT(__a64_sim_cb_fallthrough_, ID);\
			ARM64_SIM_A64_BACKWARD_GOTO(LABEL);              \
ARM64_SIM_CONCAT(__a64_sim_cb_fallthrough_, ID):                             \
			;                                                \
		} else if ((__a64_l_value == 0) == (ZERO)) {             \
			goto LABEL;                                      \
		}                                                         \
	} while (0)

#define ARM64_SIM_A64_CBZ(REG, CURRENT, TARGET, LABEL)                      \
	ARM64_SIM_A64_CBZ_IMPL((REG), 1, (CURRENT), (TARGET), LABEL, __LINE__)

#define ARM64_SIM_A64_CBNZ(REG, CURRENT, TARGET, LABEL)                     \
	ARM64_SIM_A64_CBZ_IMPL((REG), 0, (CURRENT), (TARGET), LABEL, __LINE__)

#define ARM64_SIM_A64_TBZ_IMPL(REG, BIT, ZERO, CURRENT, TARGET, LABEL, ID)  \
	do {                                                               \
		__u64 __a64_l_value = (ARM64_SIM_L_READ_REG(REG) >> (BIT)) & 1ULL;\
		if ((TARGET) <= (CURRENT)) {                              \
			if (((__a64_l_value == 0) != (ZERO)))             \
				goto ARM64_SIM_CONCAT(__a64_sim_tb_fallthrough_, ID);\
			ARM64_SIM_A64_BACKWARD_GOTO(LABEL);              \
ARM64_SIM_CONCAT(__a64_sim_tb_fallthrough_, ID):                             \
			;                                                \
		} else if ((__a64_l_value == 0) == (ZERO)) {             \
			goto LABEL;                                      \
		}                                                         \
	} while (0)

#define ARM64_SIM_A64_TBZ(REG, BIT, CURRENT, TARGET, LABEL)                 \
	ARM64_SIM_A64_TBZ_IMPL((REG), (BIT), 1, (CURRENT), (TARGET), LABEL, __LINE__)

#define ARM64_SIM_A64_TBNZ(REG, BIT, CURRENT, TARGET, LABEL)                \
	ARM64_SIM_A64_TBZ_IMPL((REG), (BIT), 0, (CURRENT), (TARGET), LABEL, __LINE__)

#define ARM64_SIM_A64_CALL(LABEL, RETURN_ADDR)                              \
	do {                                                               \
		__a64_lr = (RETURN_ADDR);                                  \
		__a64_x30.x = __a64_lr;                                   \
		goto LABEL;                                                \
	} while (0)

#define ARM64_SIM_A64_RET()                                                 \
	do {                                                               \
		if (__a64_lr) {                                           \
			switch (__a64_lr) {                               \
			ARM64_SIM_RETURN_CASES                           \
			default: break;                                  \
			}                                                 \
		}                                                          \
		ARM64_SIM_RET();                                          \
	} while (0)

#define ARM64_SIM_LICENSE() char LICENSE[] SEC("license") = "GPL"

#endif
