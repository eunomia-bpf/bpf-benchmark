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

#define ARM64_SIM_TAG_SCALAR 0U
#define ARM64_SIM_TAG_ABI 1U
#define ARM64_SIM_TAG_PACKET 2U
#define ARM64_SIM_TAG_PACKET_END 3U
#define ARM64_SIM_TAG_STACK 4U
#define ARM64_SIM_TAG_MAP_PTR 5U
#define ARM64_SIM_TAG_MAP_VALUE 6U
#define ARM64_SIM_TAG_RELOC_ADDR 7U
#define ARM64_SIM_TAG_RODATA_ADDR 8U

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
	union arm64_sim_gpr __a64_##NAME = { .x = 0 };                    \
	__u8 __a64_##NAME##_tag = ARM64_SIM_TAG_SCALAR;

#ifdef ARM64_SIM_ENABLE_STACK
#define ARM64_SIM_L_DECLARE_STACK()                                         \
	union {                                                            \
		__u8 b[160];                                              \
		__u64 q[20];                                              \
	} __a64_stack = {};                                            \
	__u8 __a64_stack_tag[20] = {};                                  \
	__s64 __a64_sp = 0
#else
#define ARM64_SIM_L_DECLARE_STACK()                                         \
	union {                                                            \
		__u8 b[1];                                                \
		__u64 q[1];                                               \
	} __a64_stack = {};                                             \
	__u8 __a64_stack_tag[1] = {};                                   \
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
	__u64 __a64_v0_hi = 0

#define ARM64_SIM_ENTRY_XDP(CTX)                                            \
	struct arm64_sim_xdp_abi __a64_sim_abi = {                         \
		.data = (void *)(long)(CTX)->data,                         \
		.data_end = (void *)(long)(CTX)->data_end,                 \
	};                                                               \
	struct __sk_buff *__a64_sim_skb_ctx = (struct __sk_buff *)0;      \
	ARM64_SIM_L_DECLARE_STATE();                                      \
	ARM64_SIM_L_DECLARE_STACK();                                      \
	__a64_x0.ptr = &__a64_sim_abi;                                    \
	__a64_x0_tag = ARM64_SIM_TAG_ABI

#define ARM64_SIM_ENTRY_SKB(CTX)                                            \
	struct arm64_sim_skb_abi __a64_sim_abi = {                         \
		.data_end = (void *)(long)(CTX)->data_end,                 \
		.data = (void *)(long)(CTX)->data,                         \
	};                                                               \
	struct __sk_buff *__a64_sim_skb_ctx = (CTX);                      \
	ARM64_SIM_L_DECLARE_STATE();                                      \
	ARM64_SIM_L_DECLARE_STACK();                                      \
	__a64_x0.ptr = &__a64_sim_abi;                                    \
	__a64_x0_tag = ARM64_SIM_TAG_ABI

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
		if ((REG) == ARM64_SP) {                                  \
			__a64_l_ptr = (void *)(long)__a64_sp;             \
		} else {                                                   \
			switch (REG) {                                    \
			ARM64_SIM_L_FOR_EACH_GPR(ARM64_SIM_L_REG_PTR_CASE)\
			default:                                          \
				__a64_l_ptr = (void *)0;                  \
				break;                                    \
			}                                                 \
		}                                                         \
		__a64_l_ptr;                                              \
	})

#define ARM64_SIM_L_REG_TAG_CASE(REG, NAME)                                 \
	case REG:                                                          \
		__a64_l_tag = __a64_##NAME##_tag;                       \
		break;

#define ARM64_SIM_L_REG_TAG(REG)                                            \
	({                                                                 \
		__u8 __a64_l_tag = ARM64_SIM_TAG_SCALAR;                 \
		if ((REG) == ARM64_SP) {                                  \
			__a64_l_tag = ARM64_SIM_TAG_STACK;                \
		} else {                                                   \
			switch (REG) {                                    \
			ARM64_SIM_L_FOR_EACH_GPR(ARM64_SIM_L_REG_TAG_CASE)\
			default:                                          \
				break;                                    \
			}                                                 \
		}                                                         \
		__a64_l_tag;                                              \
	})

#define ARM64_SIM_L_WRITE_REG64_CASE(REG, NAME)                             \
	case REG:                                                          \
		__a64_##NAME.x = __a64_l_next;                          \
		__a64_##NAME##_tag = ARM64_SIM_TAG_SCALAR;              \
		break;

#define ARM64_SIM_L_WRITE_REG32_CASE(REG, NAME)                             \
	case REG:                                                          \
		__a64_##NAME.x = (__u32)__a64_l_next;                   \
		__a64_##NAME##_tag = ARM64_SIM_TAG_SCALAR;              \
		break;

#define ARM64_SIM_L_WRITE_REG_PTR_CASE(REG, NAME)                           \
	case REG:                                                          \
		__a64_##NAME.ptr = __a64_l_next_ptr;                    \
		__a64_##NAME##_tag = __a64_l_next_tag;                 \
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
		__u8 __a64_l_next_tag = ARM64_SIM_TAG_SCALAR;            \
		if ((REG) != ARM64_XZR && (REG) != ARM64_REG_NONE) {      \
			switch (REG) {                                    \
			ARM64_SIM_L_FOR_EACH_GPR(ARM64_SIM_L_WRITE_REG_PTR_CASE)\
			default: break;                                   \
			}                                                 \
		}                                                          \
	} while (0)

#define ARM64_SIM_L_WRITE_REG_PTR_TAG(REG, VALUE, TAG)                       \
	do {                                                               \
		void *__a64_l_next_ptr = (void *)(VALUE);                \
		__u8 __a64_l_next_tag = (TAG);                           \
		if ((REG) != ARM64_XZR && (REG) != ARM64_REG_NONE) {      \
			switch (REG) {                                    \
			ARM64_SIM_L_FOR_EACH_GPR(ARM64_SIM_L_WRITE_REG_PTR_CASE)\
			default: break;                                   \
			}                                                 \
		}                                                          \
	} while (0)

#define ARM64_SIM_L_WRITE_REG_MAP_PTR(REG, VALUE)                            \
	ARM64_SIM_L_WRITE_REG_PTR_TAG((REG), (VALUE), ARM64_SIM_TAG_MAP_PTR)

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
		__u64 __a64_str_value;                                    \
		if (__a64_str_width == ARM64_WIDTH_64 &&                  \
		    (__a64_str_index & 7U) == 0) {                        \
			__a64_str_value = __a64_stack.q[__a64_str_index >> 3];\
		} else {                                                   \
			__a64_str_value = __a64_stack.b[__a64_str_index];  \
			if (__a64_str_width >= ARM64_WIDTH_16)            \
				__a64_str_value |= (__u64)__a64_stack.b[__a64_str_index + 1] << 8;\
			if (__a64_str_width >= ARM64_WIDTH_32) {          \
				__a64_str_value |= (__u64)__a64_stack.b[__a64_str_index + 2] << 16;\
				__a64_str_value |= (__u64)__a64_stack.b[__a64_str_index + 3] << 24;\
			}                                                 \
			if (__a64_str_width == ARM64_WIDTH_64) {          \
				__a64_str_value |= (__u64)__a64_stack.b[__a64_str_index + 4] << 32;\
				__a64_str_value |= (__u64)__a64_stack.b[__a64_str_index + 5] << 40;\
				__a64_str_value |= (__u64)__a64_stack.b[__a64_str_index + 6] << 48;\
				__a64_str_value |= (__u64)__a64_stack.b[__a64_str_index + 7] << 56;\
			}                                                 \
		}                                                         \
		__a64_str_value;                                          \
	})

#define ARM64_SIM_L_STACK_READ_TAG(OFF, WIDTH)                              \
	({                                                                 \
		__u32 __a64_srt_index = ARM64_SIM_L_STACK_INDEX(OFF);     \
		__u8 __a64_srt_width = (WIDTH);                           \
		(__a64_srt_width == ARM64_WIDTH_64 &&                     \
		 (__a64_srt_index & 7U) == 0) ?                           \
			__a64_stack_tag[__a64_srt_index >> 3] :            \
			ARM64_SIM_TAG_SCALAR;                             \
	})

#define ARM64_SIM_L_STACK_WRITE_TAG(OFF, WIDTH, VALUE, TAG)                  \
	do {                                                               \
		__u32 __a64_stw_index = ARM64_SIM_L_STACK_INDEX(OFF);     \
		__u8 __a64_stw_width = (WIDTH);                           \
		__u64 __a64_stw_value = arm64_apply_width((VALUE), __a64_stw_width);\
		if (__a64_stw_width == ARM64_WIDTH_64 &&                  \
		    (__a64_stw_index & 7U) == 0) {                        \
			__a64_stack.q[__a64_stw_index >> 3] = __a64_stw_value;\
			__a64_stack_tag[__a64_stw_index >> 3] = (TAG);    \
		} else {                                                   \
			if ((__a64_stw_index & 7U) == 0)                   \
				__a64_stack_tag[__a64_stw_index >> 3] = ARM64_SIM_TAG_SCALAR;\
			__a64_stack.b[__a64_stw_index] = (__u8)__a64_stw_value;\
			if (__a64_stw_width >= ARM64_WIDTH_16)            \
				__a64_stack.b[__a64_stw_index + 1] = (__u8)(__a64_stw_value >> 8);\
			if (__a64_stw_width >= ARM64_WIDTH_32) {          \
				__a64_stack.b[__a64_stw_index + 2] = (__u8)(__a64_stw_value >> 16);\
				__a64_stack.b[__a64_stw_index + 3] = (__u8)(__a64_stw_value >> 24);\
			}                                                 \
			if (__a64_stw_width == ARM64_WIDTH_64) {          \
				__a64_stack.b[__a64_stw_index + 4] = (__u8)(__a64_stw_value >> 32);\
				__a64_stack.b[__a64_stw_index + 5] = (__u8)(__a64_stw_value >> 40);\
				__a64_stack.b[__a64_stw_index + 6] = (__u8)(__a64_stw_value >> 48);\
				__a64_stack.b[__a64_stw_index + 7] = (__u8)(__a64_stw_value >> 56);\
			}                                                 \
		}                                                         \
	} while (0)

#define ARM64_SIM_L_STACK_WRITE(OFF, WIDTH, VALUE)                          \
	ARM64_SIM_L_STACK_WRITE_TAG((OFF), (WIDTH), (VALUE), ARM64_SIM_TAG_SCALAR)

#define ARM64_SIM_L_STACK_PTR(OFF)                                         \
	((void *)&__a64_stack.b[ARM64_SIM_STACK_BIAS + (__s64)(long)(OFF)])

#define ARM64_SIM_L_HELPER_ARG_PTR(REG)                                    \
	(ARM64_SIM_L_REG_TAG(REG) == ARM64_SIM_TAG_STACK ?                 \
	 ARM64_SIM_L_STACK_PTR((__s64)(long)ARM64_SIM_L_READ_REG_PTR(REG)) :\
	 ARM64_SIM_L_READ_REG_PTR(REG))

#define ARM64_SIM_L_STORE_Q0_STACK(OFF)                                    \
	do {                                                               \
		ARM64_SIM_L_STACK_WRITE((OFF), ARM64_WIDTH_64, __a64_v0);\
		ARM64_SIM_L_STACK_WRITE((__s64)(OFF) + 8, ARM64_WIDTH_64,\
					__a64_v0_hi);                    \
	} while (0)

#define ARM64_SIM_L_LOAD_ADDR(ADDR, WIDTH)                                  \
	({                                                                 \
		volatile const __u8 *__a64_lda_addr =                    \
			(volatile const __u8 *)(ADDR);                   \
		__u8 __a64_lda_width = (WIDTH);                           \
		__u64 __a64_lda_value = __a64_lda_addr[0];               \
		if (__a64_lda_width >= ARM64_WIDTH_16)                    \
			__a64_lda_value |= (__u64)__a64_lda_addr[1] << 8;\
		if (__a64_lda_width >= ARM64_WIDTH_32) {                  \
			__a64_lda_value |= (__u64)__a64_lda_addr[2] << 16;\
			__a64_lda_value |= (__u64)__a64_lda_addr[3] << 24;\
		}                                                         \
		if (__a64_lda_width == ARM64_WIDTH_64) {                  \
			__a64_lda_value |= (__u64)__a64_lda_addr[4] << 32;\
			__a64_lda_value |= (__u64)__a64_lda_addr[5] << 40;\
			__a64_lda_value |= (__u64)__a64_lda_addr[6] << 48;\
			__a64_lda_value |= (__u64)__a64_lda_addr[7] << 56;\
		}                                                         \
		__a64_lda_value;                                          \
	})

#define ARM64_SIM_L_LOAD_PTR_ADDR(ADDR) (*(void **)(ADDR))

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
				ARM64_SIM_L_WRITE_REG_PTR_TAG((BASE),     \
					(__u8 *)ARM64_SIM_L_READ_REG_PTR(BASE) + __a64_l_pre,\
					ARM64_SIM_L_REG_TAG(BASE));        \
		}                                                          \
	} while (0)

#define ARM64_SIM_L_MEM_POST(BASE, AUX, IMM)                                \
	do {                                                               \
		if (ARM64_SIM_L_MEM_FLAGS(AUX) & ARM64_MEM_POST) {        \
			__s64 __a64_l_post = (__s64)(IMM);                \
			if ((BASE) == ARM64_SP)                            \
				__a64_sp += __a64_l_post;                 \
			else                                               \
				ARM64_SIM_L_WRITE_REG_PTR_TAG((BASE),     \
					(__u8 *)ARM64_SIM_L_READ_REG_PTR(BASE) + __a64_l_post,\
					ARM64_SIM_L_REG_TAG(BASE));        \
		}                                                          \
	} while (0)

#define ARM64_SIM_L_MEM_READ(BASE, INDEX, AUX, IMM, EXTRA, WIDTH)            \
	({                                                                 \
		__s64 __a64_mrd_off = ARM64_SIM_L_MEM_BASE_OFF((AUX), (INDEX), (IMM)) + (EXTRA);\
		__u8 __a64_mrd_tag = ARM64_SIM_L_REG_TAG(BASE);          \
		__u64 __a64_mrd_value;                                    \
		if ((BASE) == ARM64_SP || __a64_mrd_tag == ARM64_SIM_TAG_STACK) {\
			__s64 __a64_mrd_base = (BASE) == ARM64_SP ? __a64_sp :\
				(__s64)(long)ARM64_SIM_L_READ_REG_PTR(BASE);\
			__a64_mrd_value = ARM64_SIM_L_STACK_READ(__a64_mrd_base + __a64_mrd_off, (WIDTH));\
		} else if (__a64_mrd_tag == ARM64_SIM_TAG_ABI &&          \
			   (WIDTH) == ARM64_WIDTH_64) {                  \
			void *__a64_mrd_addr = (__u8 *)ARM64_SIM_L_READ_REG_PTR(BASE) + __a64_mrd_off;\
			__a64_mrd_value = (__u64)(long)ARM64_SIM_L_LOAD_PTR_ADDR(__a64_mrd_addr);\
		} else if (__a64_mrd_tag == ARM64_SIM_TAG_RELOC_ADDR &&    \
			   (WIDTH) == ARM64_WIDTH_64) {                    \
			if (__a64_mrd_off != 0)                            \
				ARM64_SIM_L_UNSUPPORTED_OPCODE();          \
			__a64_mrd_value =                                 \
				(__u64)(long)ARM64_SIM_L_READ_REG_PTR(BASE);\
		} else {                                                   \
			void *__a64_mrd_addr = (__u8 *)ARM64_SIM_L_READ_REG_PTR(BASE) + __a64_mrd_off;\
			__a64_mrd_value = ARM64_SIM_L_LOAD_ADDR(__a64_mrd_addr, (WIDTH));\
		}                                                         \
		__a64_mrd_value;                                          \
	})

#define ARM64_SIM_L_MEM_READ_TAG(BASE, INDEX, AUX, IMM, EXTRA, WIDTH)        \
	({                                                                 \
		__s64 __a64_mrt_off = ARM64_SIM_L_MEM_BASE_OFF((AUX), (INDEX), (IMM)) + (EXTRA);\
		__u8 __a64_mrt_tag = ARM64_SIM_L_REG_TAG(BASE);          \
		__u8 __a64_mrt_value_tag = ARM64_SIM_TAG_SCALAR;         \
		if ((BASE) == ARM64_SP || __a64_mrt_tag == ARM64_SIM_TAG_STACK) {\
			__s64 __a64_mrt_base = (BASE) == ARM64_SP ? __a64_sp :\
				(__s64)(long)ARM64_SIM_L_READ_REG_PTR(BASE);\
			__a64_mrt_value_tag = ARM64_SIM_L_STACK_READ_TAG( \
				__a64_mrt_base + __a64_mrt_off, (WIDTH));\
		} else if (__a64_mrt_tag == ARM64_SIM_TAG_ABI &&          \
			   (WIDTH) == ARM64_WIDTH_64) {                  \
			__a64_mrt_value_tag = __a64_mrt_off == 8 ?        \
				ARM64_SIM_TAG_PACKET_END : ARM64_SIM_TAG_PACKET;\
		} else if (__a64_mrt_tag == ARM64_SIM_TAG_RELOC_ADDR &&    \
			   (WIDTH) == ARM64_WIDTH_64) {                    \
			if (__a64_mrt_off != 0)                            \
				ARM64_SIM_L_UNSUPPORTED_OPCODE();          \
			__a64_mrt_value_tag = ARM64_SIM_TAG_MAP_PTR;       \
		}                                                         \
		__a64_mrt_value_tag;                                      \
	})

#define ARM64_SIM_L_MEM_WRITE(BASE, INDEX, AUX, IMM, EXTRA, WIDTH, VALUE, TAG)\
	do {                                                               \
		__s64 __a64_mwr_off = ARM64_SIM_L_MEM_BASE_OFF((AUX), (INDEX), (IMM)) + (EXTRA);\
		__u8 __a64_mwr_tag = ARM64_SIM_L_REG_TAG(BASE);          \
		if ((BASE) == ARM64_SP || __a64_mwr_tag == ARM64_SIM_TAG_STACK) {\
			__s64 __a64_mwr_base = (BASE) == ARM64_SP ? __a64_sp :\
				(__s64)(long)ARM64_SIM_L_READ_REG_PTR(BASE);\
			ARM64_SIM_L_STACK_WRITE_TAG(__a64_mwr_base + __a64_mwr_off,\
						    (WIDTH), (VALUE), (TAG));\
		} else {                                                   \
			void *__a64_mwr_addr = (__u8 *)ARM64_SIM_L_READ_REG_PTR(BASE) + __a64_mwr_off;\
			ARM64_SIM_L_STORE_ADDR(__a64_mwr_addr, (WIDTH), (VALUE));\
		}                                                         \
	} while (0)

#define ARM64_SIM_L_LOAD_D0_MEM(BASE, INDEX, AUX, IMM)                      \
	do {                                                               \
		ARM64_SIM_L_MEM_PRE((BASE), (AUX), (IMM));               \
		__a64_v0 = ARM64_SIM_L_MEM_READ((BASE), (INDEX), (AUX), \
							(IMM), 0, ARM64_WIDTH_64);\
		ARM64_SIM_L_MEM_POST((BASE), (AUX), (IMM));              \
	} while (0)

#define ARM64_SIM_L_LOAD_Q0_MEM(BASE, INDEX, AUX, IMM)                      \
	do {                                                               \
		ARM64_SIM_L_MEM_PRE((BASE), (AUX), (IMM));               \
		__a64_v0 = ARM64_SIM_L_MEM_READ((BASE), (INDEX), (AUX), \
							(IMM), 0, ARM64_WIDTH_64);\
		__a64_v0_hi = ARM64_SIM_L_MEM_READ((BASE), (INDEX), (AUX),\
							(IMM), ARM64_WIDTH_64,\
							ARM64_WIDTH_64);       \
		ARM64_SIM_L_MEM_POST((BASE), (AUX), (IMM));              \
	} while (0)

#define ARM64_SIM_L_STORE_D0_MEM(BASE, INDEX, AUX, IMM)                     \
	do {                                                               \
		ARM64_SIM_L_MEM_PRE((BASE), (AUX), (IMM));               \
		ARM64_SIM_L_MEM_WRITE((BASE), (INDEX), (AUX), (IMM), 0, \
				      ARM64_WIDTH_64, __a64_v0,         \
				      ARM64_SIM_TAG_SCALAR);            \
		ARM64_SIM_L_MEM_POST((BASE), (AUX), (IMM));              \
	} while (0)

#define ARM64_SIM_L_STORE_Q0_MEM(BASE, INDEX, AUX, IMM)                     \
	do {                                                               \
		ARM64_SIM_L_MEM_PRE((BASE), (AUX), (IMM));               \
		ARM64_SIM_L_MEM_WRITE((BASE), (INDEX), (AUX), (IMM), 0, \
				      ARM64_WIDTH_64, __a64_v0,         \
				      ARM64_SIM_TAG_SCALAR);            \
		ARM64_SIM_L_MEM_WRITE((BASE), (INDEX), (AUX), (IMM),    \
				      ARM64_WIDTH_64, ARM64_WIDTH_64,   \
				      __a64_v0_hi, ARM64_SIM_TAG_SCALAR);\
		ARM64_SIM_L_MEM_POST((BASE), (AUX), (IMM));              \
	} while (0)

#define ARM64_SIM_L_SET_SUB_FLAGS(LHS, RHS, WIDTH)                          \
	do {                                                               \
		__u8 __a64_sub_width = (WIDTH);                           \
		__u64 __a64_sub_mask = arm64_width_mask(__a64_sub_width); \
		__u64 __a64_sub_lhs = (LHS) & __a64_sub_mask;             \
		__u64 __a64_sub_rhs = (RHS) & __a64_sub_mask;             \
		__u64 __a64_sub_res = (__a64_sub_lhs - __a64_sub_rhs) & __a64_sub_mask;\
		__u64 __a64_sub_sign = arm64_sign_bit(__a64_sub_width);   \
		__a64_z = __a64_sub_lhs == __a64_sub_rhs;                 \
		__a64_n = (__a64_sub_res & __a64_sub_sign) != 0;          \
		__a64_c = __a64_sub_lhs >= __a64_sub_rhs;                 \
		__a64_v = ((__a64_sub_lhs ^ __a64_sub_rhs) & (__a64_sub_lhs ^ __a64_sub_res) & __a64_sub_sign) != 0;\
	} while (0)

#define ARM64_SIM_L_SET_ADD_FLAGS(LHS, RHS, WIDTH)                          \
	do {                                                               \
		__u8 __a64_add_width = (WIDTH);                           \
		__u64 __a64_add_mask = arm64_width_mask(__a64_add_width); \
		__u64 __a64_add_lhs = (LHS) & __a64_add_mask;             \
		__u64 __a64_add_rhs = (RHS) & __a64_add_mask;             \
		__u64 __a64_add_res = (__a64_add_lhs + __a64_add_rhs) & __a64_add_mask;\
		__u64 __a64_add_sign = arm64_sign_bit(__a64_add_width);   \
		__a64_z = __a64_add_res == 0;                             \
		__a64_n = (__a64_add_res & __a64_add_sign) != 0;          \
		__a64_c = __a64_add_lhs > __a64_add_mask - __a64_add_rhs; \
		__a64_v = (~(__a64_add_lhs ^ __a64_add_rhs) & (__a64_add_lhs ^ __a64_add_res) & __a64_add_sign) != 0;\
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
	 (COND) == ARM64_COND_LE ? (__a64_z || (__a64_n != __a64_v)) :        \
	 (COND) == ARM64_COND_AL ? 1 : ({ ARM64_SIM_L_UNSUPPORTED_OPCODE(); 0; }))

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
		__u8 __a64_alu_src_tag = ARM64_SIM_L_REG_TAG(SRC);        \
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
		else                                                      \
			ARM64_SIM_L_UNSUPPORTED_OPCODE();                 \
		if (__a64_alu_width == ARM64_WIDTH_64 &&                  \
		    __a64_alu_op == ARM64_ALU_ADD && (DST) != ARM64_SP && \
		    __a64_alu_src_tag != ARM64_SIM_TAG_SCALAR)            \
			ARM64_SIM_L_WRITE_REG_PTR_TAG((DST),              \
				(__u8 *)ARM64_SIM_L_READ_REG_PTR(SRC) + __a64_alu_rhs,\
				__a64_alu_src_tag);                       \
		else                                                       \
			ARM64_SIM_L_WRITE_REG_WIDTH((DST), __a64_alu_result, __a64_alu_width);\
	} while (0)

#define ARM64_SIM_L_EXEC(OP, DST, SRC, SRC2, SRC3, FLAGS, AUX, IMM)         \
	do {                                                               \
		__u8 __a64_l_width = (FLAGS) ? (FLAGS) : ARM64_WIDTH_64;  \
		if ((OP) == ARM64_OP_NOP) {                                \
			(void)0;                                           \
		} else if ((OP) == ARM64_OP_ADRP_GOT ||                    \
			   (OP) == ARM64_OP_ADRP_RODATA) {                 \
			ARM64_SIM_L_WRITE_REG_PTR_TAG((DST), (void *)(long)(IMM),\
				(OP) == ARM64_OP_ADRP_GOT ?                \
					ARM64_SIM_TAG_RELOC_ADDR :         \
					ARM64_SIM_TAG_RODATA_ADDR);        \
		} else if ((OP) == ARM64_OP_MOV_IMM) {                     \
			ARM64_SIM_L_WRITE_REG_WIDTH((DST), (IMM), __a64_l_width);\
		} else if ((OP) == ARM64_OP_MOV_REG) {                     \
			if (__a64_l_width == ARM64_WIDTH_64)               \
				ARM64_SIM_L_WRITE_REG_PTR_TAG((DST),       \
					ARM64_SIM_L_READ_REG_PTR(SRC),     \
					ARM64_SIM_L_REG_TAG(SRC));         \
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
			__u64 __a64_l_result = 0;                       \
			if ((AUX) == ARM64_SHIFT_LSL)                    \
				__a64_l_result = arm64_lsl(__a64_l_value, __a64_l_shift, __a64_l_width);\
			else if ((AUX) == ARM64_SHIFT_LSR)               \
				__a64_l_result = arm64_lsr(__a64_l_value, __a64_l_shift, __a64_l_width);\
			else if ((AUX) == ARM64_SHIFT_ASR)               \
				__a64_l_result = arm64_asr(__a64_l_value, __a64_l_shift, __a64_l_width);\
			else if ((AUX) == ARM64_SHIFT_ROR)               \
				__a64_l_result = arm64_ror(__a64_l_value, __a64_l_shift, __a64_l_width);\
			else                                             \
				ARM64_SIM_L_UNSUPPORTED_OPCODE();        \
			ARM64_SIM_L_WRITE_REG_WIDTH((DST), __a64_l_result, __a64_l_width);\
		} else if ((OP) == ARM64_OP_MADD || (OP) == ARM64_OP_MSUB) { \
			__u64 __a64_l_product = ARM64_SIM_L_READ_REG(SRC) * ARM64_SIM_L_READ_REG(SRC2);\
			__u64 __a64_l_result = (OP) == ARM64_OP_MADD ? ARM64_SIM_L_READ_REG(SRC3) + __a64_l_product : ARM64_SIM_L_READ_REG(SRC3) - __a64_l_product;\
			ARM64_SIM_L_WRITE_REG_WIDTH((DST), __a64_l_result, __a64_l_width);\
		} else if ((OP) == ARM64_OP_MUL || (OP) == ARM64_OP_UMULL || (OP) == ARM64_OP_UMULH || (OP) == ARM64_OP_UMADDL || (OP) == ARM64_OP_SMADDL || (OP) == ARM64_OP_UDIV) {\
			__u64 __a64_l_rhs = ARM64_SIM_L_READ_REG(SRC2);   \
			__u64 __a64_l_result = 0;                         \
			if ((OP) == ARM64_OP_UDIV)                         \
				__a64_l_result = __a64_l_rhs ? ARM64_SIM_L_READ_REG(SRC) / __a64_l_rhs : 0;\
			else if ((OP) == ARM64_OP_UMULH)                   \
				__a64_l_result = arm64_umulh(ARM64_SIM_L_READ_REG(SRC), __a64_l_rhs);\
			else if ((OP) == ARM64_OP_UMADDL)                  \
				__a64_l_result = (__u64)(__u32)ARM64_SIM_L_READ_REG(SRC) * (__u64)(__u32)__a64_l_rhs + ARM64_SIM_L_READ_REG(SRC3);\
			else if ((OP) == ARM64_OP_SMADDL)                  \
				__a64_l_result = (__u64)((__s64)(__s32)ARM64_SIM_L_READ_REG(SRC) * (__s64)(__s32)__a64_l_rhs + (__s64)ARM64_SIM_L_READ_REG(SRC3));\
			else if ((OP) == ARM64_OP_UMULL)                   \
				__a64_l_result = (__u64)(__u32)ARM64_SIM_L_READ_REG(SRC) * (__u64)(__u32)__a64_l_rhs;\
			else                                               \
				__a64_l_result = ARM64_SIM_L_READ_REG(SRC) * __a64_l_rhs;\
			ARM64_SIM_L_WRITE_REG_WIDTH((DST), __a64_l_result, __a64_l_width);\
		} else if ((OP) == ARM64_OP_MVN || (OP) == ARM64_OP_NEG) {    \
			__u64 __a64_l_value = ARM64_SIM_L_READ_REG(SRC);     \
			ARM64_SIM_L_WRITE_REG_WIDTH((DST), (OP) == ARM64_OP_MVN ? ~__a64_l_value : -__a64_l_value, __a64_l_width);\
		} else if ((OP) == ARM64_OP_CNEG) {                          \
			__u64 __a64_l_value = ARM64_SIM_L_READ_REG(SRC);     \
			if (ARM64_SIM_L_EVAL_COND(AUX))                      \
				__a64_l_value = -__a64_l_value;              \
			ARM64_SIM_L_WRITE_REG_WIDTH((DST), __a64_l_value, __a64_l_width);\
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
			else if (__a64_bf_kind == ARM64_BITFIELD_BFI) {       \
				__u64 __a64_bf_field_mask = __a64_bf_lsb >= 64 ? 0 : __a64_bf_mask << __a64_bf_lsb;\
				__a64_bf_result = (ARM64_SIM_L_READ_REG(DST) & ~__a64_bf_field_mask) | (__a64_bf_src_l & __a64_bf_field_mask);\
			} else {                                              \
				ARM64_SIM_L_UNSUPPORTED_OPCODE();             \
				__a64_bf_result = 0;                           \
			}                                                     \
			ARM64_SIM_L_WRITE_REG_WIDTH((DST), __a64_bf_result, __a64_l_width);\
		} else if ((OP) == ARM64_OP_REV || (OP) == ARM64_OP_REV16 || (OP) == ARM64_OP_SXTB || (OP) == ARM64_OP_SXTH || (OP) == ARM64_OP_SXTW) {\
			__u64 __a64_l_value = ARM64_SIM_L_READ_REG(SRC);     \
			if ((OP) == ARM64_OP_REV)                             \
				__a64_l_value = arm64_reverse_bytes(__a64_l_value, __a64_l_width);\
			else if ((OP) == ARM64_OP_REV16)                      \
				__a64_l_value = arm64_reverse_bytes16(__a64_l_value, __a64_l_width);\
			else if ((OP) == ARM64_OP_SXTW)                       \
				__a64_l_value = arm64_sign_extend(__a64_l_value & 0xffffffffULL, 32);\
			else if ((OP) == ARM64_OP_SXTB)                       \
				__a64_l_value = arm64_sign_extend(__a64_l_value & 0xffULL, 8);\
			else                                                  \
				__a64_l_value = arm64_sign_extend(__a64_l_value & 0xffffULL, 16);\
			ARM64_SIM_L_WRITE_REG_WIDTH((DST), __a64_l_value, __a64_l_width);\
		} else if ((OP) == ARM64_OP_SUBS_IMM || (OP) == ARM64_OP_SUBS_REG) {\
			__u64 __a64_l_lhs = ARM64_SIM_L_READ_REG(SRC);      \
			__u64 __a64_l_rhs = (OP) == ARM64_OP_SUBS_IMM ? (__u64)(IMM) :\
				ARM64_SIM_L_MOD_VALUE((SRC2), ARM64_SIM_L_MOD(AUX), ARM64_SIM_L_SHIFT(AUX), __a64_l_width);\
			__u64 __a64_l_result = __a64_l_lhs - __a64_l_rhs;  \
			ARM64_SIM_L_WRITE_REG_WIDTH((DST), __a64_l_result, __a64_l_width);\
			ARM64_SIM_L_SET_SUB_FLAGS(__a64_l_lhs, __a64_l_rhs, __a64_l_width);\
		} else if ((OP) == ARM64_OP_ADDS_IMM || (OP) == ARM64_OP_ADDS_REG) {\
			__u64 __a64_l_lhs = ARM64_SIM_L_READ_REG(SRC);      \
			__u64 __a64_l_rhs = (OP) == ARM64_OP_ADDS_IMM ? (__u64)(IMM) :\
				ARM64_SIM_L_MOD_VALUE((SRC2), ARM64_SIM_L_MOD(AUX), ARM64_SIM_L_SHIFT(AUX), __a64_l_width);\
			__u64 __a64_l_result = __a64_l_lhs + __a64_l_rhs;  \
			ARM64_SIM_L_WRITE_REG_WIDTH((DST), __a64_l_result, __a64_l_width);\
			ARM64_SIM_L_SET_ADD_FLAGS(__a64_l_lhs, __a64_l_rhs, __a64_l_width);\
		} else if ((OP) == ARM64_OP_CMN_IMM) {                       \
			ARM64_SIM_L_SET_ADD_FLAGS(ARM64_SIM_L_READ_REG(DST), (__u64)(IMM), __a64_l_width);\
		} else if ((OP) == ARM64_OP_CMN_REG) {                       \
			ARM64_SIM_L_SET_ADD_FLAGS(ARM64_SIM_L_READ_REG(DST), ARM64_SIM_L_MOD_VALUE((SRC), ARM64_SIM_L_MOD(AUX), ARM64_SIM_L_SHIFT(AUX), __a64_l_width), __a64_l_width);\
		} else if ((OP) == ARM64_OP_CMP_IMM || (OP) == ARM64_OP_CMP_REG) {\
			ARM64_SIM_L_SET_SUB_FLAGS(ARM64_SIM_L_READ_REG(DST), (OP) == ARM64_OP_CMP_IMM ? (__u64)(IMM) : ARM64_SIM_L_MOD_VALUE((SRC), ARM64_SIM_L_MOD(AUX), ARM64_SIM_L_SHIFT(AUX), __a64_l_width), __a64_l_width);\
		} else if ((OP) == ARM64_OP_TST_IMM || (OP) == ARM64_OP_TST_REG) {\
			ARM64_SIM_L_SET_LOGIC_FLAGS(ARM64_SIM_L_READ_REG(DST) & ((OP) == ARM64_OP_TST_IMM ? (__u64)(IMM) : ARM64_SIM_L_MOD_VALUE((SRC), ARM64_SIM_L_MOD(AUX), ARM64_SIM_L_SHIFT(AUX), __a64_l_width)), __a64_l_width);\
		} else if ((OP) == ARM64_OP_TST_BIC_REG) {                 \
			ARM64_SIM_L_SET_LOGIC_FLAGS(ARM64_SIM_L_READ_REG(DST) & ~ARM64_SIM_L_MOD_VALUE((SRC), ARM64_SIM_L_MOD(AUX), ARM64_SIM_L_SHIFT(AUX), __a64_l_width), __a64_l_width);\
		} else if ((OP) == ARM64_OP_BICS_REG) {                    \
			__u64 __a64_l_value = ARM64_SIM_L_READ_REG(SRC) & ~ARM64_SIM_L_MOD_VALUE((SRC2), ARM64_SIM_L_MOD(AUX), ARM64_SIM_L_SHIFT(AUX), __a64_l_width);\
			ARM64_SIM_L_WRITE_REG_WIDTH((DST), __a64_l_value, __a64_l_width);\
			ARM64_SIM_L_SET_LOGIC_FLAGS(__a64_l_value, __a64_l_width);\
		} else if ((OP) == ARM64_OP_ANDS_REG || (OP) == ARM64_OP_ANDS_IMM) {\
			__u64 __a64_l_value = ARM64_SIM_L_READ_REG(SRC) & ((OP) == ARM64_OP_ANDS_IMM ? (__u64)(IMM) : ARM64_SIM_L_MOD_VALUE((SRC2), ARM64_SIM_L_MOD(AUX), ARM64_SIM_L_SHIFT(AUX), __a64_l_width));\
			ARM64_SIM_L_WRITE_REG_WIDTH((DST), __a64_l_value, __a64_l_width);\
			ARM64_SIM_L_SET_LOGIC_FLAGS(__a64_l_value, __a64_l_width);\
		} else if ((OP) == ARM64_OP_ORN_REG) {                     \
			__u64 __a64_l_value = ARM64_SIM_L_READ_REG(SRC) | ~ARM64_SIM_L_MOD_VALUE((SRC2), ARM64_SIM_L_MOD(AUX), ARM64_SIM_L_SHIFT(AUX), __a64_l_width);\
			ARM64_SIM_L_WRITE_REG_WIDTH((DST), __a64_l_value, __a64_l_width);\
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
				ARM64_SIM_L_WRITE_REG_PTR_TAG((DST),       \
					ARM64_SIM_L_READ_REG_PTR(SRC),     \
					ARM64_SIM_L_REG_TAG(SRC));         \
			else if (__a64_l_width == ARM64_WIDTH_64)              \
				ARM64_SIM_L_WRITE_REG_PTR_TAG((DST),       \
					ARM64_SIM_L_READ_REG_PTR(SRC2),    \
					ARM64_SIM_L_REG_TAG(SRC2));        \
			else                                                   \
				ARM64_SIM_L_WRITE_REG_WIDTH((DST), ARM64_SIM_L_EVAL_COND(AUX) ? ARM64_SIM_L_READ_REG(SRC) : ARM64_SIM_L_READ_REG(SRC2), __a64_l_width);\
		} else if ((OP) == ARM64_OP_CINV) {                         \
			__u64 __a64_l_value = ARM64_SIM_L_READ_REG(SRC);    \
			if (ARM64_SIM_L_EVAL_COND(AUX))                     \
				__a64_l_value = ~__a64_l_value;             \
			ARM64_SIM_L_WRITE_REG_WIDTH((DST), __a64_l_value, __a64_l_width);\
		} else if ((OP) == ARM64_OP_CSINV) {                        \
			__u64 __a64_l_value = ARM64_SIM_L_EVAL_COND(AUX) ? ARM64_SIM_L_READ_REG(SRC) : ~ARM64_SIM_L_READ_REG(SRC2);\
			ARM64_SIM_L_WRITE_REG_WIDTH((DST), __a64_l_value, __a64_l_width);\
		} else if ((OP) == ARM64_OP_CSINC) {                        \
			__u64 __a64_l_value = ARM64_SIM_L_EVAL_COND(AUX) ? ARM64_SIM_L_READ_REG(SRC) : ARM64_SIM_L_READ_REG(SRC2) + 1;\
			ARM64_SIM_L_WRITE_REG_WIDTH((DST), __a64_l_value, __a64_l_width);\
		} else if ((OP) == ARM64_OP_LOAD) {                            \
			ARM64_SIM_L_MEM_PRE((SRC), (AUX), (IMM));              \
			__u64 __a64_l_value = ARM64_SIM_L_MEM_READ((SRC), (SRC2), (AUX), (IMM), 0, __a64_l_width);\
			__u8 __a64_l_value_tag = ARM64_SIM_L_MEM_READ_TAG( \
				(SRC), (SRC2), (AUX), (IMM), 0, __a64_l_width);\
			if (__a64_l_width == ARM64_WIDTH_64 &&              \
			    __a64_l_value_tag != ARM64_SIM_TAG_SCALAR)      \
				ARM64_SIM_L_WRITE_REG_PTR_TAG((DST),       \
					(void *)(long)__a64_l_value,        \
					__a64_l_value_tag);                 \
			else                                                   \
				ARM64_SIM_L_WRITE_REG_WIDTH((DST), __a64_l_value, __a64_l_width);\
			ARM64_SIM_L_MEM_POST((SRC), (AUX), (IMM));             \
		} else if ((OP) == ARM64_OP_LDRSB) {                         \
			ARM64_SIM_L_MEM_PRE((SRC), (AUX), (IMM));              \
			__u64 __a64_l_value = ARM64_SIM_L_MEM_READ((SRC), (SRC2), (AUX), (IMM), 0, ARM64_WIDTH_8);\
			ARM64_SIM_L_WRITE_REG_WIDTH((DST), arm64_sign_extend(__a64_l_value & 0xffULL, 8), __a64_l_width);\
			ARM64_SIM_L_MEM_POST((SRC), (AUX), (IMM));             \
		} else if ((OP) == ARM64_OP_LDRSW) {                         \
			ARM64_SIM_L_MEM_PRE((SRC), (AUX), (IMM));              \
			__u64 __a64_l_value = ARM64_SIM_L_MEM_READ((SRC), (SRC2), (AUX), (IMM), 0, ARM64_WIDTH_32);\
			ARM64_SIM_L_WRITE_REG_WIDTH((DST), arm64_sign_extend(__a64_l_value & 0xffffffffULL, 32), __a64_l_width);\
			ARM64_SIM_L_MEM_POST((SRC), (AUX), (IMM));             \
		} else if ((OP) == ARM64_OP_LDRSH) {                         \
			ARM64_SIM_L_MEM_PRE((SRC), (AUX), (IMM));              \
			__u64 __a64_l_value = ARM64_SIM_L_MEM_READ((SRC), (SRC2), (AUX), (IMM), 0, ARM64_WIDTH_16);\
			ARM64_SIM_L_WRITE_REG_WIDTH((DST), arm64_sign_extend(__a64_l_value & 0xffffULL, 16), __a64_l_width);\
			ARM64_SIM_L_MEM_POST((SRC), (AUX), (IMM));             \
		} else if ((OP) == ARM64_OP_STORE) {                           \
			ARM64_SIM_L_MEM_PRE((DST), (AUX), (IMM));              \
			ARM64_SIM_L_MEM_WRITE((DST), (SRC2), (AUX), (IMM), 0,\
				__a64_l_width, ARM64_SIM_L_READ_REG(SRC),   \
				ARM64_SIM_L_REG_TAG(SRC));                  \
			ARM64_SIM_L_MEM_POST((DST), (AUX), (IMM));             \
		} else if ((OP) == ARM64_OP_STLXR) {                           \
			ARM64_SIM_L_MEM_WRITE((SRC2), ARM64_REG_NONE,        \
				(AUX), 0, 0, __a64_l_width,                 \
				ARM64_SIM_L_READ_REG(SRC),                  \
				ARM64_SIM_L_REG_TAG(SRC));                  \
			ARM64_SIM_L_WRITE_REG_WIDTH((DST), 0, ARM64_WIDTH_32);\
		} else if ((OP) == ARM64_OP_LDP) {                             \
			ARM64_SIM_L_MEM_PRE((SRC2), (AUX), (IMM));             \
			__u64 __a64_l_v0 = ARM64_SIM_L_MEM_READ((SRC2), (SRC3), (AUX), (IMM), 0, __a64_l_width);\
			__u64 __a64_l_v1 = ARM64_SIM_L_MEM_READ((SRC2), (SRC3), (AUX), (IMM), __a64_l_width, __a64_l_width);\
			__u8 __a64_l_t0 = ARM64_SIM_L_MEM_READ_TAG((SRC2), (SRC3), (AUX), (IMM), 0, __a64_l_width);\
			__u8 __a64_l_t1 = ARM64_SIM_L_MEM_READ_TAG((SRC2), (SRC3), (AUX), (IMM), __a64_l_width, __a64_l_width);\
			if (__a64_l_width == ARM64_WIDTH_64 && (__a64_l_t0 != ARM64_SIM_TAG_SCALAR || __a64_l_t1 != ARM64_SIM_TAG_SCALAR)) {\
				if (__a64_l_t0 != ARM64_SIM_TAG_SCALAR)     \
					ARM64_SIM_L_WRITE_REG_PTR_TAG((DST), (void *)(long)__a64_l_v0, __a64_l_t0);\
				else                                       \
					ARM64_SIM_L_WRITE_REG_WIDTH((DST), __a64_l_v0, __a64_l_width);\
				if (__a64_l_t1 != ARM64_SIM_TAG_SCALAR)     \
					ARM64_SIM_L_WRITE_REG_PTR_TAG((SRC), (void *)(long)__a64_l_v1, __a64_l_t1);\
				else                                       \
					ARM64_SIM_L_WRITE_REG_WIDTH((SRC), __a64_l_v1, __a64_l_width);\
			} else {                                                \
				ARM64_SIM_L_WRITE_REG_WIDTH((DST), __a64_l_v0, __a64_l_width);\
				ARM64_SIM_L_WRITE_REG_WIDTH((SRC), __a64_l_v1, __a64_l_width);\
			}                                                     \
			ARM64_SIM_L_MEM_POST((SRC2), (AUX), (IMM));            \
		} else if ((OP) == ARM64_OP_STP) {                             \
			ARM64_SIM_L_MEM_PRE((DST), (AUX), (IMM));              \
			ARM64_SIM_L_MEM_WRITE((DST), (SRC3), (AUX), (IMM), 0,\
				__a64_l_width, ARM64_SIM_L_READ_REG(SRC),   \
				ARM64_SIM_L_REG_TAG(SRC));                  \
			ARM64_SIM_L_MEM_WRITE((DST), (SRC3), (AUX), (IMM),   \
				__a64_l_width, __a64_l_width,               \
				ARM64_SIM_L_READ_REG(SRC2),                 \
				ARM64_SIM_L_REG_TAG(SRC2));                 \
			ARM64_SIM_L_MEM_POST((DST), (AUX), (IMM));             \
		} else if ((OP) == ARM64_OP_LOAD_D0) {                         \
			ARM64_SIM_L_LOAD_D0_MEM((SRC), (SRC2), (AUX), (IMM));  \
		} else if ((OP) == ARM64_OP_STORE_D0) {                        \
			ARM64_SIM_L_STORE_D0_MEM((DST), (SRC2), (AUX), (IMM)); \
		} else if ((OP) == ARM64_OP_LOAD_Q0) {                         \
			ARM64_SIM_L_LOAD_Q0_MEM((SRC), (SRC2), (AUX), (IMM));  \
		} else if ((OP) == ARM64_OP_STORE_Q0) {                        \
			ARM64_SIM_L_STORE_Q0_MEM((DST), (SRC2), (AUX), (IMM)); \
		} else if ((OP) == ARM64_OP_FMOV) {                            \
			if ((AUX) == ARM64_FMOV_D_FROM_X || (AUX) == ARM64_FMOV_S_FROM_W)\
				__a64_v0 = ARM64_SIM_L_READ_REG(SRC);          \
			else if ((AUX) == ARM64_FMOV_X_FROM_D || (AUX) == ARM64_FMOV_W_FROM_S)\
				ARM64_SIM_L_WRITE_REG_WIDTH((DST), __a64_v0, __a64_l_width);\
			else                                                   \
				ARM64_SIM_L_UNSUPPORTED_OPCODE();              \
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

#define ARM64_SIM_BPF_CALL_bpf_map_lookup_elem()                            \
	do {                                                               \
		void *__a64_bpf_ret = bpf_map_lookup_elem(                \
			ARM64_SIM_L_READ_REG_PTR(ARM64_X0),               \
			ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X1));            \
		ARM64_SIM_L_WRITE_REG_PTR_TAG(ARM64_X0, __a64_bpf_ret,   \
					      ARM64_SIM_TAG_MAP_VALUE);   \
	} while (0)

#define ARM64_SIM_BPF_CALL_bpf_map_update_elem()                            \
	do {                                                               \
		long __a64_bpf_ret = bpf_map_update_elem(                 \
			ARM64_SIM_L_READ_REG_PTR(ARM64_X0),               \
			ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X1),             \
			ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X2),             \
			ARM64_SIM_L_READ_REG(ARM64_X3));                  \
		ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X0, (__u64)__a64_bpf_ret,\
					    ARM64_WIDTH_64);              \
	} while (0)

#define ARM64_SIM_BPF_CALL_bpf_map_delete_elem()                            \
	do {                                                               \
		long __a64_bpf_ret = bpf_map_delete_elem(                 \
			ARM64_SIM_L_READ_REG_PTR(ARM64_X0),               \
			ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X1));            \
		ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X0, (__u64)__a64_bpf_ret,\
					    ARM64_WIDTH_64);              \
	} while (0)

#define ARM64_SIM_BPF_CALL_bpf_tail_call()                                  \
	do {                                                               \
		ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X0, 0, ARM64_WIDTH_64);\
	} while (0)

#define ARM64_SIM_BPF_CALL_bpf_get_current_uid_gid()                        \
	do {                                                               \
		ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X0, 0, ARM64_WIDTH_64);\
	} while (0)

#define ARM64_SIM_BPF_CALL_bpf_get_current_pid_tgid()                       \
	do {                                                               \
		ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X0, 0, ARM64_WIDTH_64);\
	} while (0)

#define ARM64_SIM_BPF_CALL_bpf_get_current_comm()                           \
	do {                                                               \
		ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X0, 0, ARM64_WIDTH_64);\
	} while (0)

#define ARM64_SIM_BPF_CALL_bpf_get_current_task()                           \
	do {                                                               \
		ARM64_SIM_L_WRITE_REG_PTR_TAG(ARM64_X0, 0,                \
					      ARM64_SIM_TAG_SCALAR);      \
	} while (0)

#define ARM64_SIM_BPF_CALL_bpf_get_current_task_btf()                       \
	ARM64_SIM_BPF_CALL_bpf_get_current_task()

#define ARM64_SIM_BPF_CALL_bpf_task_pt_regs()                               \
	ARM64_SIM_BPF_CALL_bpf_get_current_task()

#define ARM64_SIM_BPF_CALL_bpf_get_smp_processor_id()                       \
	do {                                                               \
		ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X0, 0, ARM64_WIDTH_32);\
	} while (0)

#define ARM64_SIM_BPF_CALL_bpf_get_current_cgroup_id()                      \
	do {                                                               \
		ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X0, 0, ARM64_WIDTH_64);\
	} while (0)

#define ARM64_SIM_BPF_CALL_bpf_ktime_get_ns()                               \
	do {                                                               \
		ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X0, bpf_ktime_get_ns(), \
					    ARM64_WIDTH_64);              \
	} while (0)

#define ARM64_SIM_BPF_CALL_bpf_probe_read_kernel()                          \
	do {                                                               \
		long __a64_bpf_ret = bpf_probe_read_kernel(              \
			ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X0),             \
			ARM64_SIM_L_READ_REG(ARM64_X1),                   \
			ARM64_SIM_L_READ_REG_PTR(ARM64_X2));              \
		ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X0, (__u64)__a64_bpf_ret,\
					    ARM64_WIDTH_64);              \
	} while (0)

#define ARM64_SIM_BPF_CALL_bpf_probe_read()                                 \
	do {                                                               \
		long __a64_bpf_ret = bpf_probe_read(                     \
			ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X0),             \
			ARM64_SIM_L_READ_REG(ARM64_X1),                   \
			ARM64_SIM_L_READ_REG_PTR(ARM64_X2));              \
		ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X0, (__u64)__a64_bpf_ret,\
					    ARM64_WIDTH_64);              \
	} while (0)

#define ARM64_SIM_BPF_CALL_bpf_probe_read_user()                            \
	do {                                                               \
		long __a64_bpf_ret = bpf_probe_read_user(               \
			ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X0),             \
			ARM64_SIM_L_READ_REG(ARM64_X1),                   \
			ARM64_SIM_L_READ_REG_PTR(ARM64_X2));              \
		ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X0, (__u64)__a64_bpf_ret,\
					    ARM64_WIDTH_64);              \
	} while (0)

#define ARM64_SIM_BPF_CALL_bpf_probe_read_str()                             \
	do {                                                               \
		long __a64_bpf_ret = bpf_probe_read_str(                 \
			ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X0),             \
			ARM64_SIM_L_READ_REG(ARM64_X1),                   \
			ARM64_SIM_L_READ_REG_PTR(ARM64_X2));              \
		ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X0, (__u64)__a64_bpf_ret,\
					    ARM64_WIDTH_64);              \
	} while (0)

#define ARM64_SIM_BPF_CALL_bpf_probe_read_user_str()                        \
	do {                                                               \
		long __a64_bpf_ret = bpf_probe_read_user_str(            \
			ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X0),             \
			ARM64_SIM_L_READ_REG(ARM64_X1),                   \
			ARM64_SIM_L_READ_REG_PTR(ARM64_X2));              \
		ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X0, (__u64)__a64_bpf_ret,\
					    ARM64_WIDTH_64);              \
	} while (0)

#define ARM64_SIM_BPF_CALL_bpf_probe_read_kernel_str()                      \
	do {                                                               \
		long __a64_bpf_ret = bpf_probe_read_kernel_str(          \
			ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X0),             \
			ARM64_SIM_L_READ_REG(ARM64_X1),                   \
			ARM64_SIM_L_READ_REG_PTR(ARM64_X2));              \
		ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X0, (__u64)__a64_bpf_ret,\
					    ARM64_WIDTH_64);              \
	} while (0)

#define ARM64_SIM_BPF_CALL_bpf_ktime_get_boot_ns()                          \
	do {                                                               \
		ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X0,                    \
					    bpf_ktime_get_boot_ns(),     \
					    ARM64_WIDTH_64);             \
	} while (0)

#define ARM64_SIM_BPF_CALL_bpf_perf_event_output()                          \
	do {                                                               \
		long __a64_bpf_ret = bpf_perf_event_output(               \
			ARM64_SIM_L_READ_REG_PTR(ARM64_X0),               \
			ARM64_SIM_L_READ_REG_PTR(ARM64_X1),               \
			ARM64_SIM_L_READ_REG(ARM64_X2),                   \
			ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X3),             \
			ARM64_SIM_L_READ_REG(ARM64_X4));                  \
		ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X0, (__u64)__a64_bpf_ret,\
					    ARM64_WIDTH_64);              \
	} while (0)

#define ARM64_SIM_BPF_CALL_bpf_trace_printk()                               \
	do {                                                               \
		ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X0, 0, ARM64_WIDTH_64);\
	} while (0)

#define ARM64_SIM_BPF_CALL_bpf_get_prandom_u32()                            \
	do {                                                               \
		ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X0, 0, ARM64_WIDTH_32);\
	} while (0)

#define ARM64_SIM_BPF_CALL_bpf_skb_store_bytes()                            \
	do {                                                               \
		long __a64_bpf_ret = bpf_skb_store_bytes(                \
			ARM64_SIM_L_READ_REG_PTR(ARM64_X0),               \
			ARM64_SIM_L_READ_REG(ARM64_X1),                   \
			ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X2),             \
			ARM64_SIM_L_READ_REG(ARM64_X3),                   \
			ARM64_SIM_L_READ_REG(ARM64_X4));                  \
		ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X0, (__u64)__a64_bpf_ret,\
					    ARM64_WIDTH_64);              \
	} while (0)

#define ARM64_SIM_BPF_CALL_bpf_l3_csum_replace()                            \
	do {                                                               \
		long __a64_bpf_ret = bpf_l3_csum_replace(                \
			ARM64_SIM_L_READ_REG_PTR(ARM64_X0),               \
			ARM64_SIM_L_READ_REG(ARM64_X1),                   \
			ARM64_SIM_L_READ_REG(ARM64_X2),                   \
			ARM64_SIM_L_READ_REG(ARM64_X3),                   \
			ARM64_SIM_L_READ_REG(ARM64_X4));                  \
		ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X0, (__u64)__a64_bpf_ret,\
					    ARM64_WIDTH_64);              \
	} while (0)

#define ARM64_SIM_BPF_CALL_bpf_l4_csum_replace()                            \
	do {                                                               \
		long __a64_bpf_ret = bpf_l4_csum_replace(                \
			ARM64_SIM_L_READ_REG_PTR(ARM64_X0),               \
			ARM64_SIM_L_READ_REG(ARM64_X1),                   \
			ARM64_SIM_L_READ_REG(ARM64_X2),                   \
			ARM64_SIM_L_READ_REG(ARM64_X3),                   \
			ARM64_SIM_L_READ_REG(ARM64_X4));                  \
		ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X0, (__u64)__a64_bpf_ret,\
					    ARM64_WIDTH_64);              \
	} while (0)

#define ARM64_SIM_BPF_CALL_bpf_redirect()                                   \
	do {                                                               \
		ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X0, 0, ARM64_WIDTH_64);\
	} while (0)

#define ARM64_SIM_BPF_CALL_bpf_clone_redirect()                             \
	do {                                                               \
		ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X0, 0, ARM64_WIDTH_64);\
	} while (0)

#define ARM64_SIM_BPF_CALL_bpf_skb_set_tunnel_key()                         \
	do {                                                               \
		ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X0, 0, ARM64_WIDTH_64);\
	} while (0)

#define ARM64_SIM_BPF_CALL_bpf_csum_diff()                                  \
	do {                                                               \
		ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X0, 0, ARM64_WIDTH_64);\
	} while (0)

#define ARM64_SIM_BPF_CALL_bpf_skb_under_cgroup()                           \
	do {                                                               \
		ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X0, 0, ARM64_WIDTH_64);\
	} while (0)

#define ARM64_SIM_BPF_CALL_bpf_skb_change_proto()                           \
	do {                                                               \
		ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X0, 0, ARM64_WIDTH_64);\
	} while (0)

#define ARM64_SIM_BPF_CALL_bpf_skb_change_type()                            \
	do {                                                               \
		ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X0, 0, ARM64_WIDTH_64);\
	} while (0)

#define ARM64_SIM_BPF_CALL_bpf_skb_change_tail()                            \
	do {                                                               \
		ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X0, 0, ARM64_WIDTH_64);\
	} while (0)

#define ARM64_SIM_BPF_CALL_bpf_skb_pull_data()                              \
	do {                                                               \
		ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X0, 0, ARM64_WIDTH_64);\
	} while (0)

#define ARM64_SIM_BPF_CALL_bpf_skb_change_head()                            \
	do {                                                               \
		ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X0, 0, ARM64_WIDTH_64);\
	} while (0)

#define ARM64_SIM_BPF_CALL_bpf_xdp_adjust_head()                            \
	do {                                                               \
		ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X0, 0, ARM64_WIDTH_64);\
	} while (0)

#define ARM64_SIM_BPF_CALL_bpf_xdp_adjust_tail()                            \
	do {                                                               \
		ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X0, 0, ARM64_WIDTH_64);\
	} while (0)

#define ARM64_SIM_BPF_CALL_bpf_get_socket_cookie()                          \
	do {                                                               \
		ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X0, 0, ARM64_WIDTH_64);\
	} while (0)

#define ARM64_SIM_BPF_CALL_bpf_skb_adjust_room()                            \
	do {                                                               \
		ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X0, 0, ARM64_WIDTH_64);\
	} while (0)

#define ARM64_SIM_BPF_CALL_bpf_fib_lookup()                                 \
	do {                                                               \
		ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X0, 0, ARM64_WIDTH_64);\
	} while (0)

#define ARM64_SIM_BPF_CALL_bpf_redirect_neigh()                             \
	do {                                                               \
		ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X0, 0, ARM64_WIDTH_64);\
	} while (0)

#define ARM64_SIM_BPF_CALL_bpf_jiffies64()                                  \
	do {                                                               \
		ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X0, 0, ARM64_WIDTH_64);\
	} while (0)

#define ARM64_SIM_BPF_CALL_bpf_get_netns_cookie()                           \
	do {                                                               \
		ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X0, 0, ARM64_WIDTH_64);\
	} while (0)

#define ARM64_SIM_BPF_CALL_bpf_skb_load_bytes()                             \
	do {                                                               \
		long __a64_bpf_ret = bpf_skb_load_bytes(                  \
			ARM64_SIM_L_READ_REG_PTR(ARM64_X0),               \
			ARM64_SIM_L_READ_REG(ARM64_X1),                   \
			ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X2),             \
			ARM64_SIM_L_READ_REG(ARM64_X3));                  \
		ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X0, (__u64)__a64_bpf_ret,\
					    ARM64_WIDTH_64);              \
	} while (0)

#define ARM64_SIM_BPF_CALL_bpf_skb_load_bytes_relative()                    \
	do {                                                               \
		long __a64_bpf_ret = bpf_skb_load_bytes_relative(         \
			ARM64_SIM_L_READ_REG_PTR(ARM64_X0),               \
			ARM64_SIM_L_READ_REG(ARM64_X1),                   \
			ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X2),             \
			ARM64_SIM_L_READ_REG(ARM64_X3),                   \
			ARM64_SIM_L_READ_REG(ARM64_X4));                  \
		ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X0, (__u64)__a64_bpf_ret,\
					    ARM64_WIDTH_64);              \
	} while (0)

#define ARM64_SIM_BPF_CALL_bpf_sk_fullsock()                                \
	do {                                                               \
		struct bpf_sock *__a64_bpf_ret = bpf_sk_fullsock(          \
			ARM64_SIM_L_READ_REG_PTR(ARM64_X0));              \
		ARM64_SIM_L_WRITE_REG_PTR_TAG(ARM64_X0, __a64_bpf_ret,   \
					      ARM64_SIM_TAG_SCALAR);      \
	} while (0)

#define ARM64_SIM_BPF_CALL_bpf_current_task_under_cgroup()                  \
	do {                                                               \
		ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X0, 0, ARM64_WIDTH_64);\
	} while (0)

#define ARM64_SIM_BPF_CALL_bpf_get_stackid()                                \
	do {                                                               \
		ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X0, 0, ARM64_WIDTH_64);\
	} while (0)

#define ARM64_SIM_BPF_CALL_bpf_get_stack()                                  \
	do {                                                               \
		ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X0, 0, ARM64_WIDTH_64);\
	} while (0)

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
		goto LABEL;                                                \
	} while (0)

#define ARM64_SIM_A64_JCC_BACKWARD(COND, LABEL, ID)                         \
	do {                                                               \
		if (!ARM64_SIM_L_EVAL_COND(COND)) {                       \
			goto ARM64_SIM_CONCAT(__a64_sim_jcc_fallthrough_, ID);\
		}                                                          \
		goto LABEL;                                                \
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
			if (((__a64_l_value == 0) != (ZERO))) {           \
				goto ARM64_SIM_CONCAT(__a64_sim_cb_fallthrough_, ID);\
			}                                                 \
			goto LABEL;                                      \
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
			if (((__a64_l_value == 0) != (ZERO))) {           \
				goto ARM64_SIM_CONCAT(__a64_sim_tb_fallthrough_, ID);\
			}                                                 \
			goto LABEL;                                      \
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
			default: ARM64_SIM_L_UNSUPPORTED_OPCODE(); break;\
			}                                                 \
		}                                                          \
		ARM64_SIM_RET();                                          \
	} while (0)

#define ARM64_SIM_LICENSE() char LICENSE[] SEC("license") = "GPL"

#endif
