#ifndef X86_SIM_LOCAL_BPF_H
#define X86_SIM_LOCAL_BPF_H

#include <linux/bpf.h>
#include <bpf_helpers.h>

#include "x86_sim.h"

#define X86_SIM_CONCAT2(A, B) A##B
#define X86_SIM_CONCAT(A, B) X86_SIM_CONCAT2(A, B)

#ifdef X86_SIM_ENABLE_STACK
#ifndef X86_SIM_STACK_BYTES
#ifdef X86_SIM_ENABLE_STACK_DEEP
#define X86_SIM_STACK_BYTES 128U
#else
#define X86_SIM_STACK_BYTES 64U
#endif
#endif
#endif
#ifndef X86_SIM_STACK_BYTES
#define X86_SIM_STACK_BYTES 1U
#endif

struct x86_sim_xdp_abi {
	void *data;
	void *data_end;
	__u32 cb[5];
};

struct x86_sim_skb_abi {
	__u8 pad0[X86_SKB_CB_OFF];
	__u32 cb[5];
	__u8 pad1[X86_SKB_DATA_END_OFF - X86_SKB_CB_OFF - sizeof(__u32) * 5];
	void *data_end;
	__u8 pad2[X86_SKB_DATA_OFF - X86_SKB_DATA_END_OFF - sizeof(void *)];
	void *data;
};

union x86_sim_gpr {
	void *ptr;
	__u16 w;
	__u8 b[8];
};

#define X86_SIM_TAG_SCALAR 0U
#define X86_SIM_TAG_ABI 1U
#define X86_SIM_TAG_PACKET 2U
#define X86_SIM_TAG_PACKET_END 3U
#define X86_SIM_TAG_STACK 4U
#define X86_SIM_TAG_MAP_PTR 5U
#define X86_SIM_TAG_MAP_VALUE 6U
#define X86_SIM_TAG_HELPER_ID 7U

#define X86_SIM_HELPER_bpf_map_lookup_elem 1ULL
#define X86_SIM_HELPER_bpf_map_update_elem 2ULL
#define X86_SIM_HELPER_bpf_map_delete_elem 3ULL
#define X86_SIM_HELPER_bpf_get_current_uid_gid 4ULL
#define X86_SIM_HELPER_bpf_get_current_pid_tgid 5ULL
#define X86_SIM_HELPER_bpf_get_smp_processor_id 6ULL
#define X86_SIM_HELPER_bpf_ktime_get_ns 7ULL
#define X86_SIM_HELPER_bpf_current_task_under_cgroup 8ULL
#define X86_SIM_HELPER_bpf_get_current_comm 9ULL
#define X86_SIM_HELPER_bpf_get_current_cgroup_id 10ULL
#define X86_SIM_HELPER_bpf_get_stackid 11ULL
#define X86_SIM_HELPER_bpf_perf_event_output 12ULL
#define X86_SIM_HELPER_bpf_probe_read_kernel 13ULL
#define X86_SIM_HELPER_bpf_probe_read_kernel_str 14ULL
#define X86_SIM_HELPER_bpf_probe_read_user_str 15ULL
#define X86_SIM_HELPER_bpf_get_stack 16ULL

#define X86_SIM_L_EFFECTIVE_WIDTH(WIDTH)                                    \
	((WIDTH) ? (WIDTH) : X86_WIDTH_64)

#define X86_SIM_L_MEM_EFFECTIVE_WIDTH(AUX, FLAGS)                           \
	(X86_MEM_AUX_MEM_WIDTH(AUX) ? X86_MEM_AUX_MEM_WIDTH(AUX) :          \
				      X86_SIM_L_EFFECTIVE_WIDTH(FLAGS))

#define X86_SIM_L_FOR_EACH_GPR(X)                                           \
	X(X86_RAX, rax)                                                     \
	X(X86_RCX, rcx)                                                     \
	X(X86_RDX, rdx)                                                     \
	X(X86_RBX, rbx)                                                     \
	X(X86_RSP, rsp)                                                     \
	X(X86_RBP, rbp)                                                     \
	X(X86_RSI, rsi)                                                     \
	X(X86_RDI, rdi)                                                     \
	X(X86_R8, r8)                                                       \
	X(X86_R9, r9)                                                       \
	X(X86_R10, r10)                                                     \
	X(X86_R11, r11)                                                     \
	X(X86_R12, r12)                                                     \
	X(X86_R13, r13)                                                     \
	X(X86_R14, r14)                                                     \
	X(X86_R15, r15)

#define X86_SIM_L_DECLARE_REG(REG, NAME)                                    \
	union x86_sim_gpr __x86_##NAME = { .ptr = (void *)0 };              \
	__u8 __x86_##NAME##_tag = X86_SIM_TAG_SCALAR;

#define X86_SIM_L_DECLARE_STATE()                                           \
	X86_SIM_L_FOR_EACH_GPR(X86_SIM_L_DECLARE_REG)                       \
	__u8 __x86_cf = 0;                                                  \
	__u8 __x86_zf = 0;                                                  \
	__u8 __x86_sf = 0;                                                  \
	__u8 __x86_of = 0;                                                  \
	__u64 __x86_xmm0_lo = 0;                                            \
	__u64 __x86_xmm0_hi = 0;                                            \
	__u64 __x86_sim_ret_addr = 0

#ifdef X86_SIM_ENABLE_STACK
#define X86_SIM_L_DECLARE_STACK()                                           \
	union {                                                            \
		__u8 b[X86_SIM_STACK_BYTES];                              \
		__u64 q[(X86_SIM_STACK_BYTES + 7U) / 8U];                 \
	} __x86_stack_mem = {}
#else
#define X86_SIM_L_DECLARE_STACK()                                           \
	union {                                                            \
		__u8 b[1];                                                \
		__u64 q[1];                                               \
	} __x86_stack_mem = {}
#endif

#define X86_SIM_L_REG_VALUE(REG)                                            \
	((REG) == X86_RAX ? __x86_rax.ptr :                                  \
	 (REG) == X86_RCX ? __x86_rcx.ptr :                                  \
	 (REG) == X86_RDX ? __x86_rdx.ptr :                                  \
	 (REG) == X86_RBX ? __x86_rbx.ptr :                                  \
	 (REG) == X86_RSP ? __x86_rsp.ptr :                                  \
	 (REG) == X86_RBP ? __x86_rbp.ptr :                                  \
	 (REG) == X86_RSI ? __x86_rsi.ptr :                                  \
	 (REG) == X86_RDI ? __x86_rdi.ptr :                                  \
	 (REG) == X86_R8 ? __x86_r8.ptr :                                    \
	 (REG) == X86_R9 ? __x86_r9.ptr :                                    \
	 (REG) == X86_R10 ? __x86_r10.ptr :                                  \
	 (REG) == X86_R11 ? __x86_r11.ptr :                                  \
	 (REG) == X86_R12 ? __x86_r12.ptr :                                  \
	 (REG) == X86_R13 ? __x86_r13.ptr :                                  \
	 (REG) == X86_R14 ? __x86_r14.ptr :                                  \
	 (REG) == X86_R15 ? __x86_r15.ptr : (void *)0)

#define X86_SIM_ENTRY_XDP(CTX)                                               \
	struct x86_sim_xdp_abi __x86_sim_abi = {                         \
		.data = (void *)(long)(CTX)->data,                       \
		.data_end = (void *)(long)(CTX)->data_end,               \
	};                                                               \
	struct __sk_buff *__x86_sim_skb_ctx = (struct __sk_buff *)0;      \
	X86_SIM_L_DECLARE_STATE();                                           \
	X86_SIM_L_DECLARE_STACK();                                           \
	__x86_rdi.ptr = &__x86_sim_abi;                                     \
	__x86_rdi_tag = X86_SIM_TAG_ABI

#define X86_SIM_ENTRY_SKB(CTX)                                               \
	struct x86_sim_skb_abi __x86_sim_abi = {                         \
		.data_end = (void *)(long)(CTX)->data_end,              \
		.data = (void *)(long)(CTX)->data,                       \
	};                                                               \
	struct __sk_buff *__x86_sim_skb_ctx = (CTX);                      \
	X86_SIM_L_DECLARE_STATE();                                           \
	X86_SIM_L_DECLARE_STACK();                                           \
	__x86_rdi.ptr = &__x86_sim_abi;                                     \
	__x86_rdi_tag = X86_SIM_TAG_ABI

#define X86_SIM_L_READ_REG_CASE(REG, NAME)                                  \
	case REG:                                                          \
		__x86_l_value = __x86_##NAME.ptr;                         \
		break;

#define X86_SIM_L_READ_REG_PTR(REG)                                         \
	X86_SIM_L_REG_VALUE(REG)

#define X86_SIM_L_READ_REG(REG)                                             \
	((__u64)(long)X86_SIM_L_READ_REG_PTR(REG))

#define X86_SIM_L_REG_TAG_CASE(REG, NAME)                                  \
	case REG:                                                          \
		__x86_l_tag = __x86_##NAME##_tag;                       \
		break;

#define X86_SIM_L_REG_TAG(REG)                                             \
	({                                                                 \
		__u8 __x86_l_tag = X86_SIM_TAG_SCALAR;                  \
		switch (REG) {                                           \
		X86_SIM_L_FOR_EACH_GPR(X86_SIM_L_REG_TAG_CASE)           \
		default:                                                 \
			break;                                           \
		}                                                        \
		__x86_l_tag;                                             \
	})

#define X86_SIM_L_WRITE_REG_VALUE_CASE(REG, NAME)                           \
	case REG:                                                          \
		__x86_##NAME.ptr = (void *)(long)__x86_wr_next;          \
		__x86_##NAME##_tag = X86_SIM_TAG_SCALAR;                 \
		break;

#define X86_SIM_L_WRITE_REG8_VALUE_CASE(REG, NAME)                          \
	case REG:                                                          \
		__x86_##NAME.b[0] = (__u8)__x86_wr_next;                  \
		__x86_##NAME##_tag = X86_SIM_TAG_SCALAR;                 \
		break;

#define X86_SIM_L_WRITE_REG16_VALUE_CASE(REG, NAME)                         \
	case REG:                                                          \
		__x86_##NAME.w = (__u16)__x86_wr_next;                    \
		__x86_##NAME##_tag = X86_SIM_TAG_SCALAR;                 \
		break;

#define X86_SIM_L_WRITE_REG_PTR_VALUE_CASE(REG, NAME)                       \
	case REG:                                                          \
		__x86_##NAME.ptr = __x86_wr_next_ptr;                    \
		__x86_##NAME##_tag = __x86_wr_next_tag;                  \
		break;

#define X86_SIM_L_WRITE_REG_PTR_TAG(REG, VALUE, TAG)                         \
	do {                                                               \
		void *__x86_wr_next_ptr = (void *)(VALUE);                \
		__u8 __x86_wr_next_tag = (TAG);                           \
		switch (REG) {                                            \
		X86_SIM_L_FOR_EACH_GPR(X86_SIM_L_WRITE_REG_PTR_VALUE_CASE)\
		default:                                                  \
			break;                                            \
		}                                                         \
	} while (0)

#define X86_SIM_L_WRITE_REG_PTR(REG, VALUE)                                 \
	X86_SIM_L_WRITE_REG_PTR_TAG((REG), (VALUE), X86_SIM_TAG_SCALAR)

#define X86_SIM_L_WRITE_REG_MAP_PTR(REG, VALUE)                             \
	X86_SIM_L_WRITE_REG_PTR_TAG((REG), (VALUE), X86_SIM_TAG_MAP_PTR)

#define X86_SIM_L_WRITE_REG_HELPER_ID(REG, VALUE)                           \
	do {                                                               \
		X86_SIM_L_WRITE_REG_WIDTH((REG), (VALUE), X86_WIDTH_64);  \
		X86_SIM_L_WRITE_REG_PTR_TAG((REG),                       \
			(void *)(long)(VALUE), X86_SIM_TAG_HELPER_ID);    \
	} while (0)

#define X86_SIM_L_WRITE_REG_WIDTH(REG, VALUE, WIDTH)                        \
	do {                                                               \
		__u8 __x86_wr_width = (WIDTH) ? (WIDTH) : X86_WIDTH_64;   \
		__u64 __x86_wr_next = (VALUE);                            \
		if (__x86_wr_width == X86_WIDTH_8) {                      \
			switch (REG) {                                    \
			X86_SIM_L_FOR_EACH_GPR(X86_SIM_L_WRITE_REG8_VALUE_CASE)\
			default:                                          \
				break;                                    \
			}                                                 \
		} else if (__x86_wr_width == X86_WIDTH_16) {              \
			switch (REG) {                                    \
			X86_SIM_L_FOR_EACH_GPR(X86_SIM_L_WRITE_REG16_VALUE_CASE)\
			default:                                          \
				break;                                    \
			}                                                 \
		} else if (__x86_wr_width == X86_WIDTH_32) {              \
			__x86_wr_next = (__u32)__x86_wr_next;             \
			switch (REG) {                                    \
			X86_SIM_L_FOR_EACH_GPR(X86_SIM_L_WRITE_REG_VALUE_CASE)\
			default:                                          \
				break;                                    \
			}                                                 \
		} else {                                                  \
			switch (REG) {                                    \
			X86_SIM_L_FOR_EACH_GPR(X86_SIM_L_WRITE_REG_VALUE_CASE)\
			default:                                          \
				break;                                    \
			}                                                 \
		}                                                         \
	} while (0)

#define X86_SIM_L_MEM_OFFSET(AUX, DISP)                                     \
	({                                                                 \
		__s64 __x86_l_off = (DISP);                               \
		__u8 __x86_l_index = X86_MEM_AUX_INDEX(AUX);              \
		if (__x86_l_index != X86_REG_NONE) {                      \
			__u8 __x86_l_scale = X86_MEM_AUX_SCALE_LOG2(AUX); \
			__u64 __x86_l_idx_value =                         \
				X86_SIM_L_READ_REG(__x86_l_index);        \
			__x86_l_off +=                                  \
				(__s64)(__x86_l_idx_value << __x86_l_scale);\
		}                                                         \
		__x86_l_off;                                              \
	})

#define X86_SIM_L_BARRIER_VAR(VAR) asm volatile("" : "+r"(VAR))

#define X86_SIM_L_STACK_INDEX(OFF) ((__u32)((__s64)(OFF) + X86_SIM_STACK_BYTES))

#define X86_SIM_L_STACK_WRITE(OFF, WIDTH, VALUE)                            \
	do {                                                               \
		__u32 __x86_stw_index = X86_SIM_L_STACK_INDEX(OFF);       \
		if (((WIDTH) ? (WIDTH) : X86_WIDTH_64) == X86_WIDTH_64 && \
		    (__x86_stw_index & 7U) == 0) {                        \
			__x86_stack_mem.q[__x86_stw_index >> 3] = (VALUE);\
		} else {                                                  \
			__u8 __x86_stw_width =                            \
				(WIDTH) ? (WIDTH) : X86_WIDTH_64;         \
			__u64 __x86_stw_narrowed = (VALUE) &              \
				x86_width_mask(__x86_stw_width);          \
			__x86_stack_mem.b[__x86_stw_index] =              \
				__x86_stw_narrowed;                      \
			if (__x86_stw_width >= X86_WIDTH_16)              \
				__x86_stack_mem.b[__x86_stw_index + 1] =  \
					__x86_stw_narrowed >> 8;          \
			if (__x86_stw_width >= X86_WIDTH_32) {            \
				__x86_stack_mem.b[__x86_stw_index + 2] =  \
					__x86_stw_narrowed >> 16;         \
				__x86_stack_mem.b[__x86_stw_index + 3] =  \
					__x86_stw_narrowed >> 24;         \
			}                                                 \
			if (__x86_stw_width == X86_WIDTH_64) {            \
				__x86_stack_mem.b[__x86_stw_index + 4] =  \
					__x86_stw_narrowed >> 32;         \
				__x86_stack_mem.b[__x86_stw_index + 5] =  \
					__x86_stw_narrowed >> 40;         \
				__x86_stack_mem.b[__x86_stw_index + 6] =  \
					__x86_stw_narrowed >> 48;         \
				__x86_stack_mem.b[__x86_stw_index + 7] =  \
					__x86_stw_narrowed >> 56;         \
			}                                                 \
		}                                                         \
	} while (0)

#define X86_SIM_L_STACK_READ(OFF, WIDTH)                                    \
	({                                                                 \
		__u32 __x86_str_index = X86_SIM_L_STACK_INDEX(OFF);       \
		__u64 __x86_str_value;                                   \
		if (((WIDTH) ? (WIDTH) : X86_WIDTH_64) == X86_WIDTH_64 && \
		    (__x86_str_index & 7U) == 0) {                        \
			__x86_str_value = __x86_stack_mem.q[__x86_str_index >> 3];\
		} else {                                                  \
			__u8 __x86_str_width =                            \
				(WIDTH) ? (WIDTH) : X86_WIDTH_64;         \
			__x86_str_value = __x86_stack_mem.b[__x86_str_index];\
			if (__x86_str_width >= X86_WIDTH_16)              \
				__x86_str_value |=                        \
					(__u64)__x86_stack_mem.b[__x86_str_index + 1] << 8;\
			if (__x86_str_width >= X86_WIDTH_32) {            \
				__x86_str_value |=                        \
					(__u64)__x86_stack_mem.b[__x86_str_index + 2] << 16;\
				__x86_str_value |=                        \
					(__u64)__x86_stack_mem.b[__x86_str_index + 3] << 24;\
			}                                                 \
			if (__x86_str_width == X86_WIDTH_64) {            \
				__x86_str_value |=                        \
					(__u64)__x86_stack_mem.b[__x86_str_index + 4] << 32;\
				__x86_str_value |=                        \
					(__u64)__x86_stack_mem.b[__x86_str_index + 5] << 40;\
				__x86_str_value |=                        \
					(__u64)__x86_stack_mem.b[__x86_str_index + 6] << 48;\
				__x86_str_value |=                        \
					(__u64)__x86_stack_mem.b[__x86_str_index + 7] << 56;\
			}                                                 \
		}                                                         \
		__x86_str_value;                                          \
	})

#define X86_SIM_L_STACK_PTR(OFF)                                           \
	((void *)&__x86_stack_mem.b[X86_SIM_L_STACK_INDEX((__s64)(long)(OFF))])

#define X86_SIM_L_HELPER_ARG_PTR(REG)                                      \
	X86_SIM_L_READ_REG_PTR(REG)

#define X86_SIM_L_LOAD_ADDR(ADDR, WIDTH)                                    \
	({                                                                 \
		volatile const __u8 *__x86_lda_addr =                    \
			(volatile const __u8 *)(ADDR);                   \
		__u8 __x86_lda_width = (WIDTH) ? (WIDTH) : X86_WIDTH_64; \
		__u64 __x86_lda_value = __x86_lda_addr[0];               \
		if (__x86_lda_width == X86_WIDTH_8)                       \
			(void)0;                                          \
		else {                                                    \
			__x86_lda_value |= (__u64)__x86_lda_addr[1] << 8; \
			if (__x86_lda_width >= X86_WIDTH_32) {            \
				__x86_lda_value |= (__u64)__x86_lda_addr[2] << 16;\
				__x86_lda_value |= (__u64)__x86_lda_addr[3] << 24;\
			}                                                 \
			if (__x86_lda_width == X86_WIDTH_64) {            \
				__x86_lda_value |= (__u64)__x86_lda_addr[4] << 32;\
				__x86_lda_value |= (__u64)__x86_lda_addr[5] << 40;\
				__x86_lda_value |= (__u64)__x86_lda_addr[6] << 48;\
				__x86_lda_value |= (__u64)__x86_lda_addr[7] << 56;\
			}                                                 \
		}                                                         \
		__x86_lda_value;                                          \
	})

#define X86_SIM_L_LOAD_PTR_ADDR(ADDR) (*(void **)(ADDR))

#define X86_SIM_L_STORE_ADDR(ADDR, WIDTH, VALUE)                            \
	do {                                                               \
		__u8 *__x86_sta_addr = (__u8 *)(ADDR);                   \
		__u8 __x86_sta_width = (WIDTH) ? (WIDTH) : X86_WIDTH_64; \
		__u64 __x86_sta_value = (VALUE) & x86_width_mask(__x86_sta_width);\
		if (__x86_sta_width == X86_WIDTH_8)                       \
			*(__u8 *)__x86_sta_addr = __x86_sta_value;        \
		else if (__x86_sta_width == X86_WIDTH_16)                 \
			*(__u16 *)__x86_sta_addr = __x86_sta_value;       \
		else if (__x86_sta_width == X86_WIDTH_32)                 \
			*(__u32 *)__x86_sta_addr = __x86_sta_value;       \
		else                                                      \
			*(__u64 *)__x86_sta_addr = __x86_sta_value;       \
	} while (0)

#define X86_SIM_L_SET_LOGIC_FLAGS(RESULT, WIDTH)                            \
	do {                                                               \
		__u8 __x86_fl_width = (WIDTH) ? (WIDTH) : X86_WIDTH_64;   \
		__u64 __x86_fl_value = x86_apply_width((RESULT),          \
						      __x86_fl_width);    \
		__u32 __x86_fl_bits = x86_width_bits(__x86_fl_width);     \
		__x86_cf = 0;                                             \
		__x86_of = 0;                                             \
		__x86_zf = __x86_fl_value == 0;                           \
		__x86_sf = (__x86_fl_value >> (__x86_fl_bits - 1)) & 1;   \
	} while (0)

#define X86_SIM_L_SET_SUB_FLAGS(LHS, RHS, RESULT, WIDTH)                    \
	do {                                                               \
		__u8 __x86_sub_width = (WIDTH) ? (WIDTH) : X86_WIDTH_64;  \
		__u64 __x86_sub_mask = x86_width_mask(__x86_sub_width);   \
		__u64 __x86_sub_a = (LHS) & __x86_sub_mask;               \
		__u64 __x86_sub_b = (RHS) & __x86_sub_mask;               \
		__u64 __x86_sub_r = (RESULT) & __x86_sub_mask;            \
		__u64 __x86_sub_sign =                                    \
			1ULL << (x86_width_bits(__x86_sub_width) - 1);    \
		__x86_cf = __x86_sub_a < __x86_sub_b;                     \
		__x86_zf = __x86_sub_a == __x86_sub_b;                    \
		__x86_sf = (__x86_sub_r & __x86_sub_sign) != 0;           \
		__x86_of = ((__x86_sub_a ^ __x86_sub_b) &                 \
			    (__x86_sub_a ^ __x86_sub_r) & __x86_sub_sign) != 0;\
	} while (0)

#define X86_SIM_L_SET_ADD_FLAGS(LHS, RHS, RESULT, WIDTH)                    \
	do {                                                               \
		__u8 __x86_add_width = (WIDTH) ? (WIDTH) : X86_WIDTH_64;  \
		__u64 __x86_add_mask = x86_width_mask(__x86_add_width);   \
		__u64 __x86_add_a = (LHS) & __x86_add_mask;               \
		__u64 __x86_add_b = (RHS) & __x86_add_mask;               \
		__u64 __x86_add_r = (RESULT) & __x86_add_mask;            \
		__u64 __x86_add_sign =                                    \
			1ULL << (x86_width_bits(__x86_add_width) - 1);    \
		__x86_cf = __x86_add_r < __x86_add_a;                     \
		__x86_zf = __x86_add_r == 0;                              \
		__x86_sf = (__x86_add_r & __x86_add_sign) != 0;           \
		__x86_of = ((~(__x86_add_a ^ __x86_add_b) &               \
			    (__x86_add_a ^ __x86_add_r) & __x86_add_sign) != 0);\
	} while (0)

#define X86_SIM_L_SET_SBB_FLAGS(LHS, RHS, BORROW, RESULT, WIDTH)            \
	do {                                                               \
		__u8 __x86_sbb_width = (WIDTH) ? (WIDTH) : X86_WIDTH_64;  \
		__u64 __x86_sbb_mask = x86_width_mask(__x86_sbb_width);   \
		__u64 __x86_sbb_a = (LHS) & __x86_sbb_mask;               \
		__u64 __x86_sbb_b = (RHS) & __x86_sbb_mask;               \
		__u64 __x86_sbb_sub = (__x86_sbb_b + (BORROW)) & __x86_sbb_mask;\
		__u64 __x86_sbb_r = (RESULT) & __x86_sbb_mask;            \
		__u64 __x86_sbb_sign =                                    \
			1ULL << (x86_width_bits(__x86_sbb_width) - 1);    \
		__x86_cf = (__x86_sbb_a < __x86_sbb_b) ||                 \
			   ((BORROW) && __x86_sbb_a == __x86_sbb_b);      \
		__x86_zf = __x86_sbb_r == 0;                              \
		__x86_sf = (__x86_sbb_r & __x86_sbb_sign) != 0;           \
		__x86_of = ((__x86_sbb_a ^ __x86_sbb_sub) &               \
			    (__x86_sbb_a ^ __x86_sbb_r) & __x86_sbb_sign) != 0;\
	} while (0)

#define X86_SIM_L_SET_IMUL_FLAGS(LHS, RHS, WIDTH)                           \
	do {                                                               \
		__u8 __x86_imul_width = (WIDTH) ? (WIDTH) : X86_WIDTH_64; \
		__u64 __x86_imul_a_abs = x86_signed_abs_width((LHS),      \
							   __x86_imul_width);\
		__u64 __x86_imul_b_abs = x86_signed_abs_width((RHS),      \
							   __x86_imul_width);\
		__u64 __x86_imul_sign =                                   \
			1ULL << (x86_width_bits(__x86_imul_width) - 1);   \
		__u64 __x86_imul_limit = (((LHS) ^ (RHS)) & __x86_imul_sign) ?\
				       __x86_imul_sign : __x86_imul_sign - 1;\
		__u8 __x86_imul_overflow =                                \
			__x86_imul_a_abs != 0 &&                           \
			__x86_imul_b_abs > __x86_imul_limit / __x86_imul_a_abs;\
		__x86_cf = __x86_imul_overflow;                           \
		__x86_of = __x86_imul_overflow;                           \
	} while (0)

#define X86_SIM_L_SET_SHIFT_FLAGS(LHS, RHS, RESULT, ALU, WIDTH)             \
	do {                                                               \
		__u8 __x86_sh_width = (WIDTH) ? (WIDTH) : X86_WIDTH_64;   \
		__u32 __x86_sh_bits = x86_width_bits(__x86_sh_width);     \
		__u64 __x86_sh_mask = x86_width_mask(__x86_sh_width);     \
		__u64 __x86_sh_a = (LHS) & __x86_sh_mask;                 \
		__u64 __x86_sh_r = (RESULT) & __x86_sh_mask;              \
		__u8 __x86_sh_count = x86_shift_count((RHS), __x86_sh_width);\
		__u64 __x86_sh_sign = 1ULL << (__x86_sh_bits - 1);        \
		if ((ALU) == X86_ALU_ROL) {                               \
			__u8 __x86_sh_amount = __x86_sh_count % __x86_sh_bits;\
			if (__x86_sh_amount != 0) {                      \
				__x86_cf = __x86_sh_r & 1;               \
				if (__x86_sh_amount == 1)                \
					__x86_of = ((__x86_sh_r & __x86_sh_sign) != 0) ^ __x86_cf;\
			}                                                   \
		} else if (__x86_sh_count != 0) {                         \
			__x86_zf = __x86_sh_r == 0;                       \
			__x86_sf = (__x86_sh_r & __x86_sh_sign) != 0;     \
			if ((ALU) == X86_ALU_SHL) {                         \
				__x86_cf = __x86_sh_count <= __x86_sh_bits ?\
					(__x86_sh_a >> (__x86_sh_bits - __x86_sh_count)) & 1 : 0;\
				if (__x86_sh_count == 1)                  \
					__x86_of = ((__x86_sh_r & __x86_sh_sign) != 0) ^ __x86_cf;\
			} else if ((ALU) == X86_ALU_SHR) {                  \
				__x86_cf = __x86_sh_count <= __x86_sh_bits ?\
					(__x86_sh_a >> (__x86_sh_count - 1)) & 1 : 0;\
				if (__x86_sh_count == 1)                  \
					__x86_of = (__x86_sh_a & __x86_sh_sign) != 0;\
			} else if ((ALU) == X86_ALU_SAR) {                  \
				__x86_cf = __x86_sh_count <= __x86_sh_bits ?\
					(__x86_sh_a >> (__x86_sh_count - 1)) & 1 : (__x86_sh_a & __x86_sh_sign) != 0;\
				if (__x86_sh_count == 1)                  \
					__x86_of = 0;                         \
			}                                                   \
		}                                                         \
	} while (0)

#define X86_SIM_L_SET_ALU_FLAGS(LHS, RHS, RESULT, ALU, WIDTH)               \
	do {                                                               \
		__u8 __x86_l_old_cf = __x86_cf;                          \
		if ((ALU) == X86_ALU_ADD)                                 \
			X86_SIM_L_SET_ADD_FLAGS((LHS), (RHS), (RESULT), (WIDTH));\
		else if ((ALU) == X86_ALU_INC) {                          \
			X86_SIM_L_SET_ADD_FLAGS((LHS), 1, (RESULT), (WIDTH));\
			__x86_cf = __x86_l_old_cf;                         \
		} else if ((ALU) == X86_ALU_SUB)                          \
			X86_SIM_L_SET_SUB_FLAGS((LHS), (RHS), (RESULT), (WIDTH));\
		else if ((ALU) == X86_ALU_SBB)                            \
			X86_SIM_L_SET_SBB_FLAGS((LHS), (RHS), 0, (RESULT), (WIDTH));\
		else if ((ALU) == X86_ALU_NOT)                            \
			(void)0;                                          \
		else if ((ALU) == X86_ALU_SHL || (ALU) == X86_ALU_SHR ||  \
			 (ALU) == X86_ALU_SAR || (ALU) == X86_ALU_ROL)    \
			X86_SIM_L_SET_SHIFT_FLAGS((LHS), (RHS), (RESULT), (ALU), (WIDTH));\
		else if ((ALU) == X86_ALU_IMUL)                           \
			X86_SIM_L_SET_IMUL_FLAGS((LHS), (RHS), (WIDTH));   \
		else                                                      \
			X86_SIM_L_SET_LOGIC_FLAGS((RESULT), (WIDTH));      \
	} while (0)

#define X86_SIM_L_EVAL_CC(CC)                                               \
	({                                                                 \
		int __x86_l_ret = 0;                                      \
		if ((CC) == X86_CC_B)                                     \
			__x86_l_ret = __x86_cf;                           \
		else if ((CC) == X86_CC_AE)                               \
			__x86_l_ret = !__x86_cf;                          \
		else if ((CC) == X86_CC_E)                                \
			__x86_l_ret = __x86_zf;                           \
		else if ((CC) == X86_CC_NE)                               \
			__x86_l_ret = !__x86_zf;                          \
		else if ((CC) == X86_CC_BE)                               \
			__x86_l_ret = __x86_cf || __x86_zf;                \
		else if ((CC) == X86_CC_A)                                \
			__x86_l_ret = !__x86_cf && !__x86_zf;              \
		else if ((CC) == X86_CC_S)                                \
			__x86_l_ret = __x86_sf;                           \
		else if ((CC) == X86_CC_NS)                               \
			__x86_l_ret = !__x86_sf;                          \
		else if ((CC) == X86_CC_L)                                \
			__x86_l_ret = __x86_sf != __x86_of;                \
		else if ((CC) == X86_CC_GE)                               \
			__x86_l_ret = __x86_sf == __x86_of;                \
		else if ((CC) == X86_CC_LE)                               \
			__x86_l_ret = __x86_zf || __x86_sf != __x86_of;    \
		else if ((CC) == X86_CC_G)                                \
			__x86_l_ret = !__x86_zf && __x86_sf == __x86_of;   \
		else if ((CC) == X86_CC_O)                                \
			__x86_l_ret = __x86_of;                           \
		else if ((CC) == X86_CC_NO)                               \
			__x86_l_ret = !__x86_of;                          \
		__x86_l_ret;                                             \
	})

#define X86_SIM_L_READ_MEM_VALUE(BASE_REG, AUX, IMM, WIDTH, STORE_DISP)      \
	({                                                                 \
		void *__x86_l_base_ptr = (void *)0;                      \
		__u8 __x86_l_base_tag = X86_SIM_L_REG_TAG(BASE_REG);     \
		__u8 __x86_l_mem_width = X86_SIM_L_EFFECTIVE_WIDTH(WIDTH);\
		__s64 __x86_l_disp = (STORE_DISP) ?                      \
			x86_store_imm_disp(IMM) : x86_simm(IMM);          \
		__x86_l_disp = X86_SIM_L_MEM_OFFSET((AUX), __x86_l_disp);\
		X86_SIM_L_BARRIER_VAR(__x86_l_disp);                    \
		if ((BASE_REG) != X86_REG_NONE)                          \
			__x86_l_base_ptr = X86_SIM_L_READ_REG_PTR(BASE_REG);\
		__u64 __x86_l_value;                                     \
		void *__x86_l_addr = (__u8 *)__x86_l_base_ptr +           \
				     __x86_l_disp;                       \
		if ((BASE_REG) == X86_RSP) {                              \
			__x86_l_value = X86_SIM_L_STACK_READ(             \
				(__s64)(long)__x86_l_base_ptr + __x86_l_disp,\
				__x86_l_mem_width);                       \
		} else if (__x86_l_base_tag == X86_SIM_TAG_ABI &&         \
			   __x86_l_mem_width == X86_WIDTH_64) {          \
			__x86_l_value =                                  \
				(__u64)(long)X86_SIM_L_LOAD_PTR_ADDR(     \
					__x86_l_addr);                    \
		} else {                                                  \
			__x86_l_value = X86_SIM_L_LOAD_ADDR(             \
				(void *)(long)__x86_l_addr,              \
				__x86_l_mem_width);                      \
		}                                                         \
		__x86_l_value;                                            \
	})

#define X86_SIM_L_EXEC_MOV_LOAD(OP, DST, SRC, FLAGS, AUX, IMM)              \
	do {                                                               \
		__u8 __x86_l_mem_width = X86_MEM_AUX_MEM_WIDTH(AUX);      \
		__u8 __x86_l_write_width = (FLAGS) ? (FLAGS) : X86_WIDTH_64;\
		__s64 __x86_l_disp = X86_SIM_L_MEM_OFFSET((AUX), x86_simm(IMM));\
		void *__x86_l_base_ptr = (void *)0;                      \
		__u8 __x86_l_base_tag = X86_SIM_L_REG_TAG(SRC);          \
		__u64 __x86_l_value = 0;                                 \
		if (!__x86_l_mem_width)                                  \
			__x86_l_mem_width = __x86_l_write_width;          \
		if ((SRC) != X86_REG_NONE)                               \
			__x86_l_base_ptr = X86_SIM_L_READ_REG_PTR(SRC);   \
		X86_SIM_L_BARRIER_VAR(__x86_l_disp);                    \
		void *__x86_l_addr = (__u8 *)__x86_l_base_ptr +           \
				     __x86_l_disp;                       \
		if ((SRC) == X86_RSP) {                                   \
			__x86_l_value = X86_SIM_L_STACK_READ(             \
				(__s64)(long)__x86_l_base_ptr + __x86_l_disp,\
				X86_SIM_L_MEM_EFFECTIVE_WIDTH((AUX), (FLAGS)));\
			X86_SIM_L_WRITE_REG_WIDTH((DST), __x86_l_value,   \
						  __x86_l_write_width);     \
		} else if ((OP) == X86_OP_MOV_LOAD &&                    \
			   __x86_l_mem_width == X86_WIDTH_64 &&          \
			   __x86_l_write_width == X86_WIDTH_64 &&        \
			   __x86_l_base_tag == X86_SIM_TAG_ABI) {        \
			__u8 __x86_l_ptr_tag = __x86_l_disp == 8 ?       \
				X86_SIM_TAG_PACKET_END : X86_SIM_TAG_PACKET;\
			X86_SIM_L_WRITE_REG_PTR_TAG((DST),                \
				X86_SIM_L_LOAD_PTR_ADDR(__x86_l_addr),    \
				__x86_l_ptr_tag);                        \
		} else {                                                  \
			__x86_l_value = X86_SIM_L_LOAD_ADDR(             \
				(void *)(long)__x86_l_addr,              \
				__x86_l_mem_width);                       \
			if ((OP) == X86_OP_MOVSX_LOAD)                    \
				__x86_l_value = x86_sign_extend(           \
					__x86_l_value, __x86_l_mem_width);  \
			X86_SIM_L_WRITE_REG_WIDTH((DST), __x86_l_value,   \
						  __x86_l_write_width);     \
		}                                                         \
	} while (0)

#define X86_SIM_L_EXEC_STORE(OP, DST, SRC, FLAGS, AUX, IMM)                 \
	do {                                                               \
		__u8 __x86_l_width = (FLAGS) ? (FLAGS) : X86_WIDTH_64;    \
		__s64 __x86_l_disp = (OP) == X86_OP_MOV_STORE_IMM ?       \
			x86_store_imm_disp(IMM) : x86_simm(IMM);          \
		void *__x86_l_base_ptr = (void *)0;                      \
		__u64 __x86_l_value = (OP) == X86_OP_MOV_STORE_IMM ?      \
			x86_store_imm_value((IMM), __x86_l_width) :       \
			X86_SIM_L_READ_REG(SRC);                          \
		if ((OP) == X86_OP_MOV_STORE_REG &&                       \
		    X86_REG_AUX_GET_SRC_SHIFT(AUX) != 0)                  \
			__x86_l_value >>= X86_REG_AUX_GET_SRC_SHIFT(AUX); \
		__x86_l_disp = X86_SIM_L_MEM_OFFSET((AUX), __x86_l_disp); \
		X86_SIM_L_BARRIER_VAR(__x86_l_disp);                    \
		if ((DST) != X86_REG_NONE)                               \
			__x86_l_base_ptr = X86_SIM_L_READ_REG_PTR(DST);   \
		if ((DST) == X86_RSP)                                     \
			X86_SIM_L_STACK_WRITE(                            \
				(__s64)(long)__x86_l_base_ptr + __x86_l_disp,\
				X86_SIM_L_EFFECTIVE_WIDTH(FLAGS),          \
				__x86_l_value);                            \
		else {                                                    \
			void *__x86_l_addr = (__u8 *)__x86_l_base_ptr +   \
					     __x86_l_disp;               \
			X86_SIM_L_STORE_ADDR(__x86_l_addr,                \
					     __x86_l_width, __x86_l_value);\
			}                                                         \
		} while (0)

#define X86_SIM_L_EXEC_MOVBE_LOAD(DST, SRC, FLAGS, AUX, IMM)               \
	do {                                                               \
		__u8 __x86_l_width = (FLAGS) ? (FLAGS) : X86_WIDTH_64;    \
		__u64 __x86_l_value = X86_SIM_L_READ_MEM_VALUE((SRC),     \
			(AUX), (IMM), __x86_l_width, 0);                  \
		X86_SIM_L_WRITE_REG_WIDTH((DST),                          \
			x86_bswap(__x86_l_value, __x86_l_width),          \
			__x86_l_width);                                    \
	} while (0)

#define X86_SIM_L_EXEC_MOVBE_STORE(DST, SRC, FLAGS, AUX, IMM)              \
	do {                                                               \
		__u8 __x86_l_width = (FLAGS) ? (FLAGS) : X86_WIDTH_64;    \
		__s64 __x86_l_disp = X86_SIM_L_MEM_OFFSET((AUX),          \
			x86_simm(IMM));                                   \
		X86_SIM_L_BARRIER_VAR(__x86_l_disp);                    \
		void *__x86_l_base_ptr = (DST) == X86_REG_NONE ?          \
			(void *)0 : X86_SIM_L_READ_REG_PTR(DST);          \
		__u64 __x86_l_value = x86_bswap(                          \
			X86_SIM_L_READ_REG(SRC), __x86_l_width);          \
		if ((DST) == X86_RSP)                                     \
			X86_SIM_L_STACK_WRITE(                            \
				(__s64)(long)__x86_l_base_ptr + __x86_l_disp,\
				__x86_l_width, __x86_l_value);             \
		else {                                                    \
			void *__x86_l_addr = (__u8 *)__x86_l_base_ptr +   \
					     __x86_l_disp;               \
			X86_SIM_L_STORE_ADDR(__x86_l_addr, __x86_l_width, \
					     __x86_l_value);              \
		}                                                         \
	} while (0)

#define X86_SIM_L_EXEC_LOAD_XMM0(SRC, AUX, IMM)                             \
	do {                                                               \
		__s64 __x86_l_disp = X86_SIM_L_MEM_OFFSET((AUX),          \
			x86_simm(IMM));                                   \
		X86_SIM_L_BARRIER_VAR(__x86_l_disp);                    \
		if ((SRC) == X86_RSP) {                                  \
			void *__x86_l_base_ptr = X86_SIM_L_READ_REG_PTR(SRC);\
			__x86_xmm0_lo = X86_SIM_L_STACK_READ(             \
				(__s64)(long)__x86_l_base_ptr + __x86_l_disp,\
				X86_WIDTH_64);                            \
			__x86_xmm0_hi = X86_SIM_L_STACK_READ(             \
				(__s64)(long)__x86_l_base_ptr + __x86_l_disp + 8,\
				X86_WIDTH_64);                            \
		} else {                                                  \
			void *__x86_l_base_ptr = (SRC) == X86_REG_NONE ?  \
				(void *)(long)(IMM) : X86_SIM_L_READ_REG_PTR(SRC);\
			void *__x86_l_addr = (SRC) == X86_REG_NONE ?      \
				__x86_l_base_ptr :                         \
				(__u8 *)__x86_l_base_ptr + __x86_l_disp;  \
			__x86_xmm0_lo = X86_SIM_L_LOAD_ADDR(__x86_l_addr,\
							    X86_WIDTH_64);\
			__x86_xmm0_hi = X86_SIM_L_LOAD_ADDR(             \
				(__u8 *)__x86_l_addr + 8, X86_WIDTH_64);  \
		}                                                         \
	} while (0)

#define X86_SIM_L_EXEC_STORE_XMM0(DST, AUX, IMM)                            \
	do {                                                               \
		__s64 __x86_l_disp = X86_SIM_L_MEM_OFFSET((AUX),          \
			x86_simm(IMM));                                   \
		X86_SIM_L_BARRIER_VAR(__x86_l_disp);                    \
		void *__x86_l_base_ptr = (DST) == X86_REG_NONE ?         \
			(void *)0 : X86_SIM_L_READ_REG_PTR(DST);         \
		if ((DST) == X86_RSP) {                                  \
			X86_SIM_L_STACK_WRITE(                            \
				(__s64)(long)__x86_l_base_ptr + __x86_l_disp,\
				X86_WIDTH_64, __x86_xmm0_lo);             \
			X86_SIM_L_STACK_WRITE(                            \
				(__s64)(long)__x86_l_base_ptr + __x86_l_disp + 8,\
				X86_WIDTH_64, __x86_xmm0_hi);             \
		} else {                                                  \
			void *__x86_l_addr = (__u8 *)__x86_l_base_ptr +   \
					     __x86_l_disp;               \
			X86_SIM_L_STORE_ADDR(__x86_l_addr, X86_WIDTH_64,  \
					     __x86_xmm0_lo);              \
			X86_SIM_L_STORE_ADDR((__u8 *)__x86_l_addr + 8,    \
					     X86_WIDTH_64, __x86_xmm0_hi);\
		}                                                         \
	} while (0)

#define X86_SIM_L_EXEC_LEA(DST, SRC, FLAGS, AUX, IMM)                       \
	do {                                                               \
		__u8 __x86_l_width = (FLAGS) ? (FLAGS) : X86_WIDTH_64;    \
		__s64 __x86_l_off = X86_SIM_L_MEM_OFFSET((AUX), x86_simm(IMM));\
		X86_SIM_L_BARRIER_VAR(__x86_l_off);                     \
		void *__x86_l_src_ptr = (SRC) == X86_REG_NONE ? (void *)0 :\
					   X86_SIM_L_READ_REG_PTR(SRC);    \
		__u8 __x86_l_src_tag = X86_SIM_L_REG_TAG(SRC);           \
		if (__x86_l_width == X86_WIDTH_64 && (SRC) == X86_REG_NONE &&\
		    (AUX) == X86_LEA_AUX_RODATA) {                        \
			X86_SIM_L_WRITE_REG_WIDTH((DST), (IMM), __x86_l_width);\
		} else {                                                  \
			void *__x86_l_result;                            \
			if (__x86_l_width == X86_WIDTH_64) {              \
				__u8 __x86_l_dst_tag = __x86_l_src_tag;   \
				if ((SRC) == X86_RSP) {                  \
					__s64 __x86_l_stack_off =          \
						(__s64)(long)__x86_l_src_ptr + __x86_l_off;\
					__x86_l_result =                  \
						X86_SIM_L_STACK_PTR(__x86_l_stack_off);\
					__x86_l_dst_tag = X86_SIM_TAG_STACK;\
				} else {                                  \
					__x86_l_result =                  \
						(__u8 *)__x86_l_src_ptr + __x86_l_off;\
				}                                         \
				X86_SIM_L_WRITE_REG_PTR_TAG((DST),        \
					__x86_l_result, __x86_l_dst_tag); \
			} else {                                           \
				__x86_l_result = (__u8 *)__x86_l_src_ptr +  \
						  __x86_l_off;              \
				X86_SIM_L_WRITE_REG_WIDTH((DST),         \
					(__u64)(long)__x86_l_result,     \
					__x86_l_width);                  \
			}                                                 \
		}                                                         \
	} while (0)

#define X86_SIM_L_EXEC_ALU_IMM(DST, FLAGS, ALU, IMM)                        \
	do {                                                               \
		__u8 __x86_l_width = (FLAGS) ? (FLAGS) : X86_WIDTH_64;    \
		__u64 __x86_l_lhs = X86_SIM_L_READ_REG(DST);             \
		__u64 __x86_l_rhs = x86_store_imm_value((IMM), __x86_l_width);\
		__u64 __x86_l_result;                                    \
		if ((ALU) == X86_ALU_SBB) {                               \
			__u8 __x86_l_borrow = __x86_cf;                   \
			__x86_l_result = __x86_l_lhs - __x86_l_rhs -      \
					 __x86_l_borrow;                  \
			X86_SIM_L_SET_SBB_FLAGS(__x86_l_lhs, __x86_l_rhs, \
						__x86_l_borrow,          \
						__x86_l_result,          \
						__x86_l_width);          \
			X86_SIM_L_WRITE_REG_WIDTH((DST), __x86_l_result,  \
						  __x86_l_width);        \
		} else {                                                   \
			__x86_l_result = x86_alu_result(__x86_l_lhs,       \
							__x86_l_rhs,       \
							(ALU),             \
							__x86_l_width);    \
			X86_SIM_L_SET_ALU_FLAGS(__x86_l_lhs, __x86_l_rhs,  \
						__x86_l_result, (ALU), \
						__x86_l_width);        \
			X86_SIM_L_WRITE_REG_WIDTH((DST), __x86_l_result,  \
						  __x86_l_width);        \
		}                                                         \
	} while (0)

#define X86_SIM_L_EXEC_ALU_REG(DST, SRC, FLAGS, ALU)                        \
	do {                                                               \
		__u8 __x86_l_width = (FLAGS) ? (FLAGS) : X86_WIDTH_64;    \
		__u64 __x86_l_lhs = X86_SIM_L_READ_REG(DST);             \
		__u64 __x86_l_rhs = X86_SIM_L_READ_REG(SRC);             \
		__u64 __x86_l_result;                                    \
		if ((ALU) == X86_ALU_SBB) {                               \
			__u8 __x86_l_borrow = __x86_cf;                   \
			__x86_l_result = __x86_l_lhs - __x86_l_rhs -      \
					 __x86_l_borrow;                  \
			X86_SIM_L_SET_SBB_FLAGS(__x86_l_lhs, __x86_l_rhs, \
						__x86_l_borrow,          \
						__x86_l_result,          \
						__x86_l_width);          \
			X86_SIM_L_WRITE_REG_WIDTH((DST), __x86_l_result,  \
						  __x86_l_width);        \
		} else {                                                   \
			__x86_l_result = x86_alu_result(__x86_l_lhs,       \
							__x86_l_rhs,       \
							(ALU),             \
							__x86_l_width);    \
			X86_SIM_L_SET_ALU_FLAGS(__x86_l_lhs, __x86_l_rhs,  \
						__x86_l_result, (ALU), \
						__x86_l_width);        \
			X86_SIM_L_WRITE_REG_WIDTH((DST), __x86_l_result,  \
						  __x86_l_width);        \
		}                                                         \
	} while (0)

#define X86_SIM_L_EXEC_ALU_MEM(DST, SRC, FLAGS, AUX, IMM)                   \
	do {                                                               \
		__u8 __x86_l_width = (FLAGS) ? (FLAGS) : X86_WIDTH_64;    \
		__u8 __x86_l_alu = X86_MEM_AUX_GET_ALU_OP(AUX);           \
		__u64 __x86_l_lhs = X86_SIM_L_READ_REG(DST);             \
		__u64 __x86_l_rhs = X86_SIM_L_READ_MEM_VALUE((SRC), (AUX),\
			(IMM), __x86_l_width, 0);                         \
		__u64 __x86_l_result;                                    \
		if (__x86_l_alu == X86_ALU_SBB) {                         \
			__u8 __x86_l_borrow = __x86_cf;                   \
			__x86_l_result = __x86_l_lhs - __x86_l_rhs -      \
					 __x86_l_borrow;                  \
			X86_SIM_L_SET_SBB_FLAGS(__x86_l_lhs, __x86_l_rhs, \
				__x86_l_borrow, __x86_l_result, __x86_l_width);\
		} else {                                                   \
			__x86_l_result = x86_alu_result(__x86_l_lhs,       \
				__x86_l_rhs, __x86_l_alu, __x86_l_width); \
			X86_SIM_L_SET_ALU_FLAGS(__x86_l_lhs, __x86_l_rhs,  \
				__x86_l_result, __x86_l_alu, __x86_l_width);\
		}                                                         \
		X86_SIM_L_WRITE_REG_WIDTH((DST), __x86_l_result,          \
					  __x86_l_width);                    \
	} while (0)

#define X86_SIM_L_EXEC_ALU_MEM_UNARY(DST, FLAGS, AUX, IMM)                  \
	do {                                                               \
		__u8 __x86_l_width = (FLAGS) ? (FLAGS) : X86_WIDTH_64;    \
		__u8 __x86_l_alu = X86_MEM_AUX_GET_ALU_OP(AUX);           \
		__u64 __x86_l_lhs = X86_SIM_L_READ_MEM_VALUE((DST), (AUX),\
			(IMM), __x86_l_width, 0);                         \
		__u64 __x86_l_result = x86_alu_result(__x86_l_lhs, 1,     \
			__x86_l_alu, __x86_l_width);                      \
		__s64 __x86_l_disp = X86_SIM_L_MEM_OFFSET((AUX),          \
			x86_simm(IMM));                                    \
		void *__x86_l_base_ptr = (void *)0;                       \
		X86_SIM_L_SET_ALU_FLAGS(__x86_l_lhs, 1, __x86_l_result,   \
					__x86_l_alu, __x86_l_width);     \
		X86_SIM_L_BARRIER_VAR(__x86_l_disp);                     \
		if ((DST) != X86_REG_NONE)                                \
			__x86_l_base_ptr = X86_SIM_L_READ_REG_PTR(DST);    \
		if ((DST) == X86_RSP)                                     \
			X86_SIM_L_STACK_WRITE(                            \
				(__s64)(long)__x86_l_base_ptr + __x86_l_disp,\
				__x86_l_width, __x86_l_result);          \
		else {                                                    \
			void *__x86_l_addr = (__u8 *)__x86_l_base_ptr +   \
					     __x86_l_disp;               \
			X86_SIM_L_STORE_ADDR(__x86_l_addr,                \
					     __x86_l_width, __x86_l_result);\
		}                                                         \
	} while (0)

#define X86_SIM_L_EXEC_ALU_MEM_IMM(DST, FLAGS, AUX, IMM)                    \
	do {                                                               \
		__u8 __x86_l_width = (FLAGS) ? (FLAGS) : X86_WIDTH_64;    \
		__u8 __x86_l_alu = X86_MEM_AUX_GET_ALU_OP(AUX);           \
		__u64 __x86_l_lhs = X86_SIM_L_READ_MEM_VALUE((DST), (AUX),\
			(IMM), __x86_l_width, 1);                         \
		__u64 __x86_l_rhs = x86_store_imm_value((IMM),            \
			__x86_l_width);                                   \
		__u64 __x86_l_result = x86_alu_result(__x86_l_lhs,        \
			__x86_l_rhs, __x86_l_alu, __x86_l_width);         \
		__s64 __x86_l_disp = X86_SIM_L_MEM_OFFSET((AUX),          \
			x86_store_imm_disp(IMM));                         \
		void *__x86_l_base_ptr = (void *)0;                       \
		X86_SIM_L_SET_ALU_FLAGS(__x86_l_lhs, __x86_l_rhs,         \
					__x86_l_result, __x86_l_alu,    \
					__x86_l_width);                  \
		X86_SIM_L_BARRIER_VAR(__x86_l_disp);                     \
		if ((DST) != X86_REG_NONE)                                \
			__x86_l_base_ptr = X86_SIM_L_READ_REG_PTR(DST);    \
		if ((DST) == X86_RSP)                                     \
			X86_SIM_L_STACK_WRITE(                            \
				(__s64)(long)__x86_l_base_ptr + __x86_l_disp,\
				__x86_l_width, __x86_l_result);          \
		else {                                                    \
			void *__x86_l_addr = (__u8 *)__x86_l_base_ptr +   \
					     __x86_l_disp;               \
			X86_SIM_L_STORE_ADDR(__x86_l_addr,                \
					     __x86_l_width, __x86_l_result);\
		}                                                         \
	} while (0)

#define X86_SIM_L_EXEC_CMP_MEM(OP, DST, SRC, FLAGS, AUX, IMM)               \
	do {                                                               \
		__u8 __x86_l_width = (FLAGS) ? (FLAGS) : X86_WIDTH_64;    \
		__u64 __x86_l_lhs = X86_SIM_L_READ_MEM_VALUE((DST), (AUX),\
			(IMM), __x86_l_width, (OP) != X86_OP_CMP_MEM_REG);\
		__u64 __x86_l_rhs = (OP) == X86_OP_CMP_MEM_REG ?          \
			X86_SIM_L_READ_REG(SRC) :                         \
			x86_store_imm_value((IMM), __x86_l_width);        \
		if ((OP) == X86_OP_TEST_MEM_IMM)                          \
			X86_SIM_L_SET_LOGIC_FLAGS(__x86_l_lhs & __x86_l_rhs,\
						  __x86_l_width);        \
		else                                                      \
			X86_SIM_L_SET_SUB_FLAGS(__x86_l_lhs, __x86_l_rhs, \
				__x86_l_lhs - __x86_l_rhs, __x86_l_width);\
	} while (0)

#define X86_SIM_L_EXEC_CMP_REG_MEM(DST, SRC, FLAGS, AUX, IMM)               \
	do {                                                               \
		__u8 __x86_l_width = (FLAGS) ? (FLAGS) : X86_WIDTH_64;    \
		__u64 __x86_l_lhs = X86_SIM_L_READ_REG(DST);             \
		__u64 __x86_l_rhs = X86_SIM_L_READ_MEM_VALUE((SRC), (AUX),\
			(IMM), __x86_l_width, 0);                         \
		X86_SIM_L_SET_SUB_FLAGS(__x86_l_lhs, __x86_l_rhs,        \
			__x86_l_lhs - __x86_l_rhs, __x86_l_width);       \
	} while (0)

#define X86_SIM_L_EXEC(OP, DST, SRC, FLAGS, AUX, IMM)                       \
	do {                                                               \
		__u8 __x86_l_width = (FLAGS) ? (FLAGS) : X86_WIDTH_64;    \
		if ((OP) == X86_OP_NOP) {                                  \
			(void)0;                                           \
		} else if ((OP) == X86_OP_MOV_LOAD_MAP_PTR) {             \
			X86_SIM_L_WRITE_REG_MAP_PTR((DST),                \
				(void *)(long)(IMM));                     \
		} else if ((OP) == X86_OP_MOV_LOAD_HELPER_ID) {           \
			X86_SIM_L_WRITE_REG_HELPER_ID((DST), (IMM));      \
		} else if ((OP) == X86_OP_CALL_HELPER) {                  \
			X86_SIM_BPF_CALL_ID((IMM));                       \
		} else if ((OP) == X86_OP_CALL_REG) {                     \
			X86_SIM_BPF_CALL_REG((SRC));                      \
		} else if ((OP) == X86_OP_MOV_IMM) {                       \
			X86_SIM_L_WRITE_REG_WIDTH((DST), (IMM), __x86_l_width);\
		} else if ((OP) == X86_OP_MOV_REG) {                       \
			if (__x86_l_width == X86_WIDTH_64 &&              \
			    (SRC) == X86_RSP) {                           \
				X86_SIM_L_WRITE_REG_PTR_TAG((DST),         \
					X86_SIM_L_STACK_PTR(               \
						(__s64)(long)X86_SIM_L_READ_REG_PTR(SRC)),\
					X86_SIM_TAG_STACK);                \
			} else if (__x86_l_width == X86_WIDTH_64)           \
				X86_SIM_L_WRITE_REG_PTR_TAG((DST),         \
					X86_SIM_L_READ_REG_PTR(SRC),       \
					X86_SIM_L_REG_TAG(SRC));           \
			else {                                            \
				__u64 __x86_l_value =                    \
					X86_SIM_L_READ_REG(SRC);          \
				X86_SIM_L_WRITE_REG_WIDTH((DST),         \
					__x86_l_value, __x86_l_width);    \
			}                                                 \
		} else if ((OP) == X86_OP_MOVZX_REG ||                    \
			   (OP) == X86_OP_MOVSX_REG) {                    \
			__u8 __x86_l_src_width = (AUX) ? (AUX) : __x86_l_width;\
			__u64 __x86_l_value = X86_SIM_L_READ_REG(SRC);     \
			__x86_l_value = (OP) == X86_OP_MOVSX_REG ?         \
				x86_sign_extend(__x86_l_value, __x86_l_src_width) :\
				x86_apply_width(__x86_l_value, __x86_l_src_width);\
			X86_SIM_L_WRITE_REG_WIDTH((DST), __x86_l_value,   \
						  __x86_l_width);        \
			} else if ((OP) == X86_OP_MOV_LOAD ||                     \
				   (OP) == X86_OP_MOV_LOAD_SCALAR ||              \
				   (OP) == X86_OP_MOVSX_LOAD) {                   \
				X86_SIM_L_EXEC_MOV_LOAD((OP), (DST), (SRC), (FLAGS),\
							(AUX), (IMM));          \
			} else if ((OP) == X86_OP_MOVBE_LOAD) {                   \
				X86_SIM_L_EXEC_MOVBE_LOAD((DST), (SRC), (FLAGS),\
							  (AUX), (IMM));     \
			} else if ((OP) == X86_OP_MOV_STORE_IMM ||                \
				   (OP) == X86_OP_MOV_STORE_REG) {                \
				X86_SIM_L_EXEC_STORE((OP), (DST), (SRC), (FLAGS),  \
						     (AUX), (IMM));               \
		} else if ((OP) == X86_OP_MOVBE_STORE) {                  \
			X86_SIM_L_EXEC_MOVBE_STORE((DST), (SRC), (FLAGS),\
						   (AUX), (IMM));    \
		} else if ((OP) == X86_OP_LOAD_XMM0) {                    \
			X86_SIM_L_EXEC_LOAD_XMM0((SRC), (AUX), (IMM));   \
		} else if ((OP) == X86_OP_STORE_XMM0) {                   \
			X86_SIM_L_EXEC_STORE_XMM0((DST), (AUX), (IMM));  \
		} else if ((OP) == X86_OP_LEA) {                          \
			X86_SIM_L_EXEC_LEA((DST), (SRC), (FLAGS), (AUX), (IMM));\
		} else if ((OP) == X86_OP_ALU_IMM ||                      \
			   (OP) == X86_OP_ADD_IMM) {                      \
			X86_SIM_L_EXEC_ALU_IMM((DST), (FLAGS), (AUX), (IMM));\
		} else if ((OP) == X86_OP_ALU_REG ||                      \
			   (OP) == X86_OP_ADD_REG ||                      \
			   (OP) == X86_OP_XOR_REG) {                      \
			X86_SIM_L_EXEC_ALU_REG((DST), (SRC), (FLAGS), (AUX));\
		} else if ((OP) == X86_OP_ALU_MEM) {                      \
			X86_SIM_L_EXEC_ALU_MEM((DST), (SRC), (FLAGS), (AUX), (IMM));\
		} else if ((OP) == X86_OP_ALU_MEM_UNARY) {                \
			X86_SIM_L_EXEC_ALU_MEM_UNARY((DST), (FLAGS), (AUX), (IMM));\
		} else if ((OP) == X86_OP_ALU_MEM_IMM) {                  \
			X86_SIM_L_EXEC_ALU_MEM_IMM((DST), (FLAGS), (AUX), (IMM));\
		} else if ((OP) == X86_OP_CMP_IMM ||                      \
			   (OP) == X86_OP_TEST_IMM) {                    \
			__u64 __x86_l_lhs = X86_SIM_L_READ_REG(DST);      \
			__u64 __x86_l_rhs = x86_store_imm_value((IMM), __x86_l_width);\
			if ((OP) == X86_OP_TEST_IMM)                      \
				X86_SIM_L_SET_LOGIC_FLAGS(__x86_l_lhs & __x86_l_rhs,\
							  __x86_l_width);    \
			else                                              \
				X86_SIM_L_SET_SUB_FLAGS(__x86_l_lhs, __x86_l_rhs,\
					__x86_l_lhs - __x86_l_rhs, __x86_l_width);\
		} else if ((OP) == X86_OP_CMP_REG ||                      \
			   (OP) == X86_OP_TEST_REG) {                    \
			__u64 __x86_l_lhs = X86_SIM_L_READ_REG(DST);      \
			__u64 __x86_l_rhs = X86_SIM_L_READ_REG(SRC);      \
			if ((OP) == X86_OP_TEST_REG)                      \
				X86_SIM_L_SET_LOGIC_FLAGS(__x86_l_lhs & __x86_l_rhs,\
							  __x86_l_width);    \
			else                                              \
				X86_SIM_L_SET_SUB_FLAGS(__x86_l_lhs, __x86_l_rhs,\
					__x86_l_lhs - __x86_l_rhs, __x86_l_width);\
		} else if ((OP) == X86_OP_CMP_MEM_IMM ||                  \
			   (OP) == X86_OP_TEST_MEM_IMM ||                 \
			   (OP) == X86_OP_CMP_MEM_REG) {                  \
			X86_SIM_L_EXEC_CMP_MEM((OP), (DST), (SRC), (FLAGS),\
					       (AUX), (IMM));             \
		} else if ((OP) == X86_OP_CMP_REG_MEM) {                  \
			X86_SIM_L_EXEC_CMP_REG_MEM((DST), (SRC), (FLAGS), \
						   (AUX), (IMM));        \
		} else if ((OP) == X86_OP_CMOV) {                         \
			if (X86_SIM_L_EVAL_CC(AUX)) {                      \
				if (__x86_l_width == X86_WIDTH_64)        \
					X86_SIM_L_WRITE_REG_PTR_TAG((DST), \
						X86_SIM_L_READ_REG_PTR(SRC),\
						X86_SIM_L_REG_TAG(SRC));\
				else {                                    \
					__u64 __x86_l_value =            \
						X86_SIM_L_READ_REG(SRC);  \
					X86_SIM_L_WRITE_REG_WIDTH((DST), \
						__x86_l_value, __x86_l_width);\
				}                                       \
			}                                                   \
		} else if ((OP) == X86_OP_SETCC) {                        \
			X86_SIM_L_WRITE_REG_WIDTH((DST), X86_SIM_L_EVAL_CC(AUX),\
						  X86_WIDTH_8);          \
		} else if ((OP) == X86_OP_BSWAP) {                        \
			X86_SIM_L_WRITE_REG_WIDTH((DST),                  \
				x86_bswap(X86_SIM_L_READ_REG(DST), __x86_l_width),\
				__x86_l_width);                          \
			} else if ((OP) == X86_OP_POPCNT) {                       \
				__u64 __x86_l_src = X86_SIM_L_READ_REG(SRC);      \
				__u64 __x86_l_result =                            \
					x86_popcount64(x86_apply_width(__x86_l_src,\
								       __x86_l_width));\
				__x86_cf = 0; __x86_of = 0; __x86_sf = 0;          \
				__x86_zf = x86_apply_width(__x86_l_src, __x86_l_width) == 0;\
				X86_SIM_L_WRITE_REG_WIDTH((DST), __x86_l_result,  \
							  __x86_l_width);        \
			} else if ((OP) == X86_OP_SHIFTX) {                       \
				__u64 __x86_l_src = X86_SIM_L_READ_REG(SRC);      \
				__u64 __x86_l_count = X86_SIM_L_READ_REG(AUX);    \
				__u64 __x86_l_result = x86_alu_result(            \
					__x86_l_src, __x86_l_count, (IMM),        \
					__x86_l_width);                          \
				X86_SIM_L_WRITE_REG_WIDTH((DST), __x86_l_result,  \
							  __x86_l_width);        \
			} else if ((OP) == X86_OP_SHIFTX_MEM) {                   \
				__u64 __x86_l_src = X86_SIM_L_READ_MEM_VALUE(     \
					(SRC), (AUX), (IMM), (FLAGS), 1);         \
				__u64 __x86_l_count = X86_SIM_L_READ_REG(         \
					X86_REG_AUX_GET_SRC_SHIFT(AUX));          \
				__u64 __x86_l_result = x86_alu_result(            \
					__x86_l_src, __x86_l_count,              \
					(__u8)(IMM), __x86_l_width);             \
				X86_SIM_L_WRITE_REG_WIDTH((DST), __x86_l_result,  \
							  __x86_l_width);        \
			} else if ((OP) == X86_OP_RORX) {                         \
				__u64 __x86_l_src = X86_SIM_L_READ_REG(SRC);      \
				X86_SIM_L_WRITE_REG_WIDTH((DST),                  \
					x86_ror(__x86_l_src, (IMM), __x86_l_width),\
					__x86_l_width);                          \
			} else if ((OP) == X86_OP_RORX_MEM) {                     \
				__u64 __x86_l_src = X86_SIM_L_READ_MEM_VALUE(     \
					(SRC), (AUX), (IMM), (FLAGS), 1);         \
				X86_SIM_L_WRITE_REG_WIDTH((DST),                  \
					x86_ror(__x86_l_src, (__u8)(IMM),         \
						__x86_l_width),                   \
					__x86_l_width);                          \
			} else if ((OP) == X86_OP_XCHG) {                         \
				if (__x86_l_width == X86_WIDTH_64) {              \
					void *__x86_l_dst_ptr =                    \
					X86_SIM_L_READ_REG_PTR(DST);       \
				void *__x86_l_src_ptr =                    \
					X86_SIM_L_READ_REG_PTR(SRC);       \
				X86_SIM_L_WRITE_REG_PTR((DST),             \
							__x86_l_src_ptr);  \
				X86_SIM_L_WRITE_REG_PTR((SRC),             \
							__x86_l_dst_ptr);  \
			} else {                                            \
				__u64 __x86_l_dst_value =                  \
					X86_SIM_L_READ_REG(DST);            \
				__u64 __x86_l_src_value =                  \
					X86_SIM_L_READ_REG(SRC);            \
				X86_SIM_L_WRITE_REG_WIDTH((DST),           \
					__x86_l_src_value, __x86_l_width);  \
				X86_SIM_L_WRITE_REG_WIDTH((SRC),           \
					__x86_l_dst_value, __x86_l_width);  \
			}                                                   \
		} else if ((OP) == X86_OP_DIV) {                          \
			__u64 __x86_l_divisor = X86_SIM_L_READ_REG(SRC);  \
			__u64 __x86_l_rax = X86_SIM_L_READ_REG(X86_RAX);  \
			__u64 __x86_l_rdx = X86_SIM_L_READ_REG(X86_RDX);  \
			if (__x86_l_width == X86_WIDTH_8) {                \
				__u32 __x86_l_dividend = (__u16)__x86_l_rax;\
				__u8 __x86_l_q = __x86_l_dividend / (__u8)__x86_l_divisor;\
				__u8 __x86_l_rem = __x86_l_dividend % (__u8)__x86_l_divisor;\
				X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, ((__u16)__x86_l_rem << 8) | __x86_l_q, X86_WIDTH_16);\
			} else if (__x86_l_width == X86_WIDTH_16) {        \
				__u32 __x86_l_dividend = ((__u32)(__u16)__x86_l_rdx << 16) | (__u16)__x86_l_rax;\
				X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, __x86_l_dividend / (__u16)__x86_l_divisor, X86_WIDTH_16);\
				X86_SIM_L_WRITE_REG_WIDTH(X86_RDX, __x86_l_dividend % (__u16)__x86_l_divisor, X86_WIDTH_16);\
			} else if (__x86_l_width == X86_WIDTH_32) {        \
				__u64 __x86_l_dividend = ((__u64)(__u32)__x86_l_rdx << 32) | (__u32)__x86_l_rax;\
				__u64 __x86_l_div = (__u32)__x86_l_divisor;\
				X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, __x86_l_dividend / __x86_l_div, X86_WIDTH_32);\
				X86_SIM_L_WRITE_REG_WIDTH(X86_RDX, __x86_l_dividend % __x86_l_div, X86_WIDTH_32);\
			} else {                                             \
				unsigned __int128 __x86_l_dividend =          \
					((unsigned __int128)__x86_l_rdx << 64) | __x86_l_rax;\
				X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, __x86_l_dividend / __x86_l_divisor, X86_WIDTH_64);\
				X86_SIM_L_WRITE_REG_WIDTH(X86_RDX, __x86_l_dividend % __x86_l_divisor, X86_WIDTH_64);\
			}                                                   \
		} else if ((OP) == X86_OP_SHLD_IMM ||                     \
			   (OP) == X86_OP_SHRD_IMM) {                    \
			__u64 __x86_l_dst = X86_SIM_L_READ_REG(DST);     \
			__u64 __x86_l_src = X86_SIM_L_READ_REG(SRC);     \
			__u64 __x86_l_result;                            \
			if (x86_shift_count((IMM), __x86_l_width) != 0) { \
				if ((OP) == X86_OP_SHLD_IMM) {             \
					__x86_l_result = x86_shld(__x86_l_dst, __x86_l_src, (IMM), __x86_l_width);\
					X86_SIM_L_SET_SHIFT_FLAGS(__x86_l_dst, (IMM), __x86_l_result, X86_ALU_SHL, __x86_l_width);\
				} else {                                    \
					__x86_l_result = x86_shrd(__x86_l_dst, __x86_l_src, (IMM), __x86_l_width);\
					X86_SIM_L_SET_SHIFT_FLAGS(__x86_l_dst, (IMM), __x86_l_result, X86_ALU_SHR, __x86_l_width);\
				}                                           \
				X86_SIM_L_WRITE_REG_WIDTH((DST), __x86_l_result,\
							  __x86_l_width);    \
			}                                                   \
		} else if ((OP) == X86_OP_PUSH) {                         \
			__u64 __x86_l_value = X86_SIM_L_READ_REG(SRC);    \
			__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;        \
			X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64,\
					      __x86_l_value);              \
		} else if ((OP) == X86_OP_POP) {                          \
			__u64 __x86_l_value = X86_SIM_L_STACK_READ(        \
				(__s64)(long)__x86_rsp.ptr, __x86_l_width);\
			X86_SIM_L_WRITE_REG_WIDTH((DST), __x86_l_value,   \
						  __x86_l_width);        \
			__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;        \
		}                                                         \
	} while (0)

#define X86_SIM_RUN_OP(OP, DST, SRC, FLAGS, AUX, IMM)                       \
	do {                                                               \
		X86_SIM_L_EXEC((OP), (DST), (SRC), (FLAGS), (AUX), (IMM)); \
	} while (0)

#define X86_SIM_RUN_OP_SUB(OP, DST, SRC, FLAGS, AUX, IMM)                   \
	X86_SIM_RUN_OP((OP), (DST), (SRC), (FLAGS), (AUX), (IMM))

#define X86_SIM_BPF_CALL_bpf_map_lookup_elem()                              \
	do {                                                               \
		void *__x86_bpf_ret = bpf_map_lookup_elem(                \
			X86_SIM_L_READ_REG_PTR(X86_RDI),                  \
			X86_SIM_L_HELPER_ARG_PTR(X86_RSI));               \
		X86_SIM_L_WRITE_REG_PTR_TAG(X86_RAX, __x86_bpf_ret,       \
					    X86_SIM_TAG_MAP_VALUE);        \
	} while (0)

#define X86_SIM_BPF_CALL_bpf_map_update_elem()                              \
	do {                                                               \
		long __x86_bpf_ret = bpf_map_update_elem(                 \
			X86_SIM_L_READ_REG_PTR(X86_RDI),                  \
			X86_SIM_L_HELPER_ARG_PTR(X86_RSI),                \
			X86_SIM_L_HELPER_ARG_PTR(X86_RDX),                \
			X86_SIM_L_READ_REG(X86_RCX));                     \
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, (__u64)__x86_bpf_ret,  \
					  X86_WIDTH_64);                    \
	} while (0)

#define X86_SIM_BPF_CALL_bpf_map_delete_elem()                              \
	do {                                                               \
		long __x86_bpf_ret = bpf_map_delete_elem(                 \
			X86_SIM_L_READ_REG_PTR(X86_RDI),                  \
			X86_SIM_L_HELPER_ARG_PTR(X86_RSI));               \
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, (__u64)__x86_bpf_ret,  \
					  X86_WIDTH_64);                    \
	} while (0)

#define X86_SIM_BPF_CALL_bpf_get_current_uid_gid()                          \
	do {                                                               \
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);     \
	} while (0)

#define X86_SIM_BPF_CALL_bpf_get_current_pid_tgid()                         \
	do {                                                               \
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);     \
	} while (0)

#define X86_SIM_BPF_CALL_bpf_get_smp_processor_id()                         \
	do {                                                               \
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_32);     \
	} while (0)

#define X86_SIM_BPF_CALL_bpf_ktime_get_ns()                                 \
	do {                                                               \
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, bpf_ktime_get_ns(),    \
					  X86_WIDTH_64);                    \
	} while (0)

#define X86_SIM_BPF_CALL_ID(ID)                                             \
	do {                                                               \
		__u64 __x86_helper_id = (ID);                             \
		if (__x86_helper_id == X86_SIM_HELPER_bpf_map_lookup_elem) {\
			X86_SIM_BPF_CALL_bpf_map_lookup_elem();           \
		} else if (__x86_helper_id == X86_SIM_HELPER_bpf_map_update_elem) {\
			X86_SIM_BPF_CALL_bpf_map_update_elem();           \
		} else if (__x86_helper_id == X86_SIM_HELPER_bpf_map_delete_elem) {\
			X86_SIM_BPF_CALL_bpf_map_delete_elem();           \
		} else if (__x86_helper_id == X86_SIM_HELPER_bpf_get_current_uid_gid) {\
			X86_SIM_BPF_CALL_bpf_get_current_uid_gid();       \
		} else if (__x86_helper_id == X86_SIM_HELPER_bpf_get_current_pid_tgid) {\
			X86_SIM_BPF_CALL_bpf_get_current_pid_tgid();      \
		} else if (__x86_helper_id == X86_SIM_HELPER_bpf_get_smp_processor_id) {\
			X86_SIM_BPF_CALL_bpf_get_smp_processor_id();      \
		} else if (__x86_helper_id == X86_SIM_HELPER_bpf_ktime_get_ns) {\
			X86_SIM_BPF_CALL_bpf_ktime_get_ns();              \
		} else {                                                   \
			X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);\
		}                                                          \
	} while (0)

#define X86_SIM_BPF_CALL_REG(REG)                                           \
	X86_SIM_BPF_CALL_ID(X86_SIM_L_READ_REG(REG))

#define X86_SIM_X86_RET()                                                  \
	do {                                                               \
		if (__x86_sim_skb_ctx) {                                   \
			__x86_sim_skb_ctx->cb[0] = __x86_sim_abi.cb[0];    \
			__x86_sim_skb_ctx->cb[1] = __x86_sim_abi.cb[1];    \
		}                                                          \
		return (__u32)(long)__x86_rax.ptr;                         \
	} while (0)

#define X86_SIM_X86_CALL(LABEL, RETURN_ADDR)                               \
	do {                                                               \
		__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;                \
		X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64,\
				      (RETURN_ADDR));                     \
		goto LABEL;                                               \
	} while (0)

#define X86_SIM_X86_SUB_RET(DISPATCH_LABEL)                                \
	do {                                                               \
		__x86_sim_ret_addr = X86_SIM_L_STACK_READ(                 \
			(__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);         \
		__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;                \
		goto DISPATCH_LABEL;                                      \
	} while (0)

#define X86_SIM_X86_JMP(CURRENT, TARGET, LABEL)                             \
	do {                                                               \
		(void)(CURRENT);                                           \
		(void)(TARGET);                                            \
		goto LABEL;                                                \
	} while (0)

#define X86_SIM_X86_JCC_BACKWARD(CC, LABEL, ID)                             \
	do {                                                               \
		if (!X86_SIM_L_EVAL_CC(CC)) {                               \
			goto X86_SIM_CONCAT(__x86_sim_jcc_fallthrough_, ID);\
		}                                                           \
		goto LABEL;                                                \
X86_SIM_CONCAT(__x86_sim_jcc_fallthrough_, ID):                              \
		;                                                           \
	} while (0)

#define X86_SIM_X86_JCC_IMPL(CC, CURRENT, TARGET, LABEL, ID)                \
	do {                                                               \
		if ((TARGET) <= (CURRENT)) {                                \
			X86_SIM_X86_JCC_BACKWARD((CC), LABEL, ID);         \
		} else if (X86_SIM_L_EVAL_CC(CC)) {                        \
			X86_SIM_X86_JMP((CURRENT), (TARGET), LABEL);       \
		}                                                           \
	} while (0)

#define X86_SIM_X86_JCC(CC, CURRENT, TARGET, LABEL)                         \
	X86_SIM_X86_JCC_IMPL((CC), (CURRENT), (TARGET), LABEL, __LINE__)

#define X86_SIM_X86_SUB_JMP(CURRENT, TARGET, LABEL)                         \
	X86_SIM_X86_JMP((CURRENT), (TARGET), LABEL)

#define X86_SIM_X86_SUB_JCC(CC, CURRENT, TARGET, LABEL)                     \
	X86_SIM_X86_JCC((CC), (CURRENT), (TARGET), LABEL)

#define X86_SIM_LICENSE() char LICENSE[] SEC("license") = "GPL"

#endif
