#ifndef X86_SIM_LOCAL_BPF_H
#define X86_SIM_LOCAL_BPF_H

#include <linux/bpf.h>
#include <bpf_helpers.h>

#include "x86_sim.h"
#include "../formal/generated/abi_load.h"
#include "../formal/generated/ptr_add.h"
#include "../formal/generated/x86_cond.h"
#include "../formal/generated/x86_logic_flags.h"
#include "../formal/generated/x86_sub_flags.h"
#include "../formal/generated/x86_add_flags.h"
#include "../formal/generated/x86_sbb_result.h"
#include "../formal/generated/x86_sbb_flags.h"
#include "../formal/generated/x86_adc.h"
#include "../formal/generated/x86_shift_flags.h"
#include "../formal/generated/x86_imul_flags.h"
#include "../formal/generated/x86_mem_access.h"
#include "../formal/generated/x86_reg_write.h"
#include "../formal/generated/x86_reg_read.h"
#include "../formal/generated/x86_rep_movs.h"
#include "../formal/generated/x86_setcc.h"
#include "../formal/generated/x86_setcc_mem.h"

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

_Static_assert(__builtin_offsetof(struct x86_sim_xdp_abi, data) ==
	       KPROG_ABI_XDP_DATA_OFF, "xdp data offset disagrees with ABI spec");
_Static_assert(__builtin_offsetof(struct x86_sim_xdp_abi, data_end) ==
	       KPROG_ABI_XDP_DATA_END_OFF,
	       "xdp data_end offset disagrees with ABI spec");
_Static_assert(__builtin_offsetof(struct x86_sim_skb_abi, data) ==
	       KPROG_ABI_SKB_DATA_OFF, "skb data offset disagrees with ABI spec");
_Static_assert(__builtin_offsetof(struct x86_sim_skb_abi, data_end) ==
	       KPROG_ABI_SKB_DATA_END_OFF,
	       "skb data_end offset disagrees with ABI spec");

union x86_sim_gpr {
	void *ptr;
	__u16 w;
	__u8 b[8];
};

_Static_assert(sizeof(union x86_sim_gpr) == sizeof(__u64),
	       "x86 simulator register must hold exactly 64 bits");
_Static_assert(sizeof(void *) == sizeof(__u64),
	       "x86 simulator pointer storage must hold exactly 64 bits");
_Static_assert(__BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__,
	       "x86 partial-register layout requires little endian");

union x86_sim_stack_mem {
	__u8 b[X86_SIM_STACK_BYTES];
	__u64 q[KPROG_X86_STACK_WORDS(X86_SIM_STACK_BYTES)];
};

#define X86_SIM_TAG_SCALAR 0U
#define X86_SIM_TAG_ABI 1U
#define X86_SIM_TAG_PACKET 2U
#define X86_SIM_TAG_PACKET_END 3U
#define X86_SIM_TAG_STACK 4U
#define X86_SIM_TAG_MAP_PTR 5U
#define X86_SIM_TAG_MAP_VALUE 6U
#define X86_SIM_TAG_HELPER_ID 7U

/* The pointer-write provenance selector indexes the tag codes above, so this
 * generated contract is included after them rather than with the other
 * generated contracts at the top of the file. */
#include "../formal/generated/x86_ptr_write.h"
/* The `MOV_LOAD` handler-composition contract needs the ABI memory tag and the
 * AUX memory-width decoder, so it is included here rather than with the other
 * generated contracts at the top of the file. */
#include "../formal/generated/x86_mov_load.h"

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
#define X86_SIM_HELPER_bpf_copy_from_user_str 17ULL
#define X86_SIM_HELPER_bpf_attach_map 18ULL
#define X86_SIM_HELPER_bpf_attach_tmp_map 19ULL
#define X86_SIM_HELPER_bpf_prog_load_map 20ULL
#define X86_SIM_HELPER_bpf_get_current_task 21ULL

#define X86_SIM_L_EFFECTIVE_WIDTH(WIDTH)                                    \
	((WIDTH) ? (WIDTH) : X86_WIDTH_64)

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

#define X86_SIM_L_STATE_REG_FIELD(REG, NAME)                                \
	union x86_sim_gpr NAME;                                             \
	__u8 NAME##_tag;

struct x86_sim_state {
	X86_SIM_L_FOR_EACH_GPR(X86_SIM_L_STATE_REG_FIELD)
	__u8 cf;
	__u8 zf;
	__u8 sf;
	__u8 of;
	__u64 xmm0_lo;
	__u64 xmm0_hi;
	__u64 ret_addr;
	__u32 call_depth;
	union x86_sim_stack_mem stack_mem;
	struct x86_sim_xdp_abi xdp_abi;
	struct x86_sim_skb_abi skb_abi;
	struct __sk_buff *skb_ctx;
	__u8 abi_kind;
};

#ifdef X86_SIM_USE_STATE_STRUCT
#define X86_SIM_L_BIND_COMMON_STATE(STATE_PTR)                              \
	struct x86_sim_state *__x86_state = (STATE_PTR);                    \
	(void)__x86_state

#define __x86_rax (__x86_state->rax)
#define __x86_rcx (__x86_state->rcx)
#define __x86_rdx (__x86_state->rdx)
#define __x86_rbx (__x86_state->rbx)
#define __x86_rsp (__x86_state->rsp)
#define __x86_rbp (__x86_state->rbp)
#define __x86_rsi (__x86_state->rsi)
#define __x86_rdi (__x86_state->rdi)
#define __x86_r8 (__x86_state->r8)
#define __x86_r9 (__x86_state->r9)
#define __x86_r10 (__x86_state->r10)
#define __x86_r11 (__x86_state->r11)
#define __x86_r12 (__x86_state->r12)
#define __x86_r13 (__x86_state->r13)
#define __x86_r14 (__x86_state->r14)
#define __x86_r15 (__x86_state->r15)
#define __x86_rax_tag (__x86_state->rax_tag)
#define __x86_rcx_tag (__x86_state->rcx_tag)
#define __x86_rdx_tag (__x86_state->rdx_tag)
#define __x86_rbx_tag (__x86_state->rbx_tag)
#define __x86_rsp_tag (__x86_state->rsp_tag)
#define __x86_rbp_tag (__x86_state->rbp_tag)
#define __x86_rsi_tag (__x86_state->rsi_tag)
#define __x86_rdi_tag (__x86_state->rdi_tag)
#define __x86_r8_tag (__x86_state->r8_tag)
#define __x86_r9_tag (__x86_state->r9_tag)
#define __x86_r10_tag (__x86_state->r10_tag)
#define __x86_r11_tag (__x86_state->r11_tag)
#define __x86_r12_tag (__x86_state->r12_tag)
#define __x86_r13_tag (__x86_state->r13_tag)
#define __x86_r14_tag (__x86_state->r14_tag)
#define __x86_r15_tag (__x86_state->r15_tag)
#define __x86_cf (__x86_state->cf)
#define __x86_zf (__x86_state->zf)
#define __x86_sf (__x86_state->sf)
#define __x86_of (__x86_state->of)
#define __x86_xmm0_lo (__x86_state->xmm0_lo)
#define __x86_xmm0_hi (__x86_state->xmm0_hi)
#define __x86_sim_ret_addr (__x86_state->ret_addr)
#define __x86_sim_call_depth (__x86_state->call_depth)
#define __x86_stack_mem (__x86_state->stack_mem)
#define __x86_sim_skb_ctx (__x86_state->skb_ctx)
#define __x86_sim_abi_kind (__x86_state->abi_kind)
#endif

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
	__u8 __x86_sim_abi_kind = KPROG_ABI_KIND_XDP;                    \
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
	__u8 __x86_sim_abi_kind = KPROG_ABI_KIND_SKB;                    \
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

#define X86_SIM_L_READ_REG_WIDTH_SHIFT(REG, WIDTH, SRC_SHIFT)               \
	({                                                                 \
		__u8 __x86_rd_reg = (REG);                                  \
		__u8 __x86_rd_raw_width = (WIDTH);                         \
		__u8 __x86_rd_width = __x86_rd_raw_width ?                 \
			__x86_rd_raw_width : X86_WIDTH_64;                   \
		__u8 __x86_rd_shift = (SRC_SHIFT);                          \
		__u64 __x86_rd_value =                                    \
			(__u64)(long)X86_SIM_L_READ_REG_PTR(__x86_rd_reg);  \
		KPROG_X86_READ_REG_AT(__x86_rd_value, __x86_rd_width,      \
			__x86_rd_shift);                                    \
	})

#define X86_SIM_L_READ_REG(REG)                                             \
	X86_SIM_L_READ_REG_WIDTH_SHIFT((REG), X86_WIDTH_64, 0U)

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

#define X86_SIM_L_WRITE_REG64_VALUE_CASE(REG, NAME)                         \
	case REG:                                                          \
		KPROG_X86_WRITE_REG64(__x86_##NAME, __x86_##NAME##_tag,   \
			__x86_wr_next, X86_SIM_TAG_SCALAR);                 \
		break;

#define X86_SIM_L_WRITE_REG8_VALUE_CASE(REG, NAME)                          \
	case REG:                                                          \
		KPROG_X86_WRITE_REG8(__x86_##NAME, __x86_##NAME##_tag,    \
			__x86_wr_next, __x86_wr_shift, X86_SIM_TAG_SCALAR); \
		break;

#define X86_SIM_L_WRITE_REG16_VALUE_CASE(REG, NAME)                         \
	case REG:                                                          \
		KPROG_X86_WRITE_REG16(__x86_##NAME, __x86_##NAME##_tag,   \
			__x86_wr_next, X86_SIM_TAG_SCALAR);                 \
		break;

#define X86_SIM_L_WRITE_REG32_VALUE_CASE(REG, NAME)                         \
	case REG:                                                          \
		KPROG_X86_WRITE_REG32(__x86_##NAME, __x86_##NAME##_tag,   \
			__x86_wr_next, X86_SIM_TAG_SCALAR);                 \
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

#define X86_SIM_L_WRITE_REG_WIDTH_SHIFT(REG, VALUE, WIDTH, DST_SHIFT)       \
	do {                                                               \
		__u8 __x86_wr_raw_width = (WIDTH);                         \
		__u8 __x86_wr_width = __x86_wr_raw_width ?                 \
			__x86_wr_raw_width : X86_WIDTH_64;                   \
		__u8 __x86_wr_shift = (DST_SHIFT);                          \
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
			switch (REG) {                                    \
			X86_SIM_L_FOR_EACH_GPR(X86_SIM_L_WRITE_REG32_VALUE_CASE)\
			default:                                          \
				break;                                    \
			}                                                 \
		} else {                                                  \
			switch (REG) {                                    \
			X86_SIM_L_FOR_EACH_GPR(X86_SIM_L_WRITE_REG64_VALUE_CASE)\
			default:                                          \
				break;                                    \
			}                                                 \
		}                                                         \
	} while (0)

#define X86_SIM_L_WRITE_REG_WIDTH(REG, VALUE, WIDTH)                        \
	X86_SIM_L_WRITE_REG_WIDTH_SHIFT((REG), (VALUE), (WIDTH), 0U)

/* The public sim helper (AUX, DISP) resolves the index register through the
 * sim's own register read and delegates the arithmetic to the machine-checked
 * KPROG_X86_MEM_OFFSET contract, so the sim and the Lean refinement share one
 * offset implementation rather than restating it inline. */
#define X86_SIM_L_MEM_OFFSET(AUX, DISP)                                     \
	X86_SIM_L_MEM_OFFSET_INDEXED((AUX), (DISP),                        \
		((X86_MEM_AUX_INDEX(AUX) != X86_REG_NONE                       \
			  ? X86_SIM_L_READ_REG(X86_MEM_AUX_INDEX(AUX))         \
			  : 0)),                                               \
		(X86_MEM_AUX_INDEX(AUX) != X86_REG_NONE))

/* INDEX_VALUE is already read and HAS_INDEX is an integer presence flag; the
 * generated contract decodes the scale from AUX itself. */
#define X86_SIM_L_MEM_OFFSET_INDEXED(AUX, DISP, INDEX_VALUE, HAS_INDEX)     \
	((__s64)KPROG_X86_MEM_OFFSET((AUX), (DISP), (INDEX_VALUE),         \
				     (HAS_INDEX)))

#define X86_SIM_L_BARRIER_VAR(VAR) asm volatile("" : "+r"(VAR))

#define X86_SIM_L_STACK_INDEX(OFF)                                         \
	KPROG_X86_STACK_INDEX(OFF, X86_SIM_STACK_BYTES)

#define X86_SIM_L_STACK_WRITE(OFF, WIDTH, VALUE)                            \
	do {                                                               \
		__u32 __x86_stw_index = X86_SIM_L_STACK_INDEX(OFF);       \
		if (((WIDTH) ? (WIDTH) : X86_WIDTH_64) == X86_WIDTH_64 && \
		    KPROG_X86_STACK_WORD_ALIGNED(__x86_stw_index)) {      \
			__x86_stack_mem.q                               \
				[KPROG_X86_STACK_WORD_INDEX(             \
					__x86_stw_index)] = (VALUE);     \
		} else {                                                  \
			__u8 __x86_stw_width =                            \
				(WIDTH) ? (WIDTH) : X86_WIDTH_64;         \
			__u64 __x86_stw_narrowed = (VALUE) &              \
				x86_width_mask(__x86_stw_width);          \
			__x86_stack_mem.b[__x86_stw_index] =              \
				KPROG_X86_STACK_BYTE(__x86_stw_narrowed, 0);\
			if (__x86_stw_width >= X86_WIDTH_16)              \
				__x86_stack_mem.b[__x86_stw_index + 1] =  \
					KPROG_X86_STACK_BYTE(             \
						__x86_stw_narrowed, 1);   \
			if (__x86_stw_width >= X86_WIDTH_32) {            \
				__x86_stack_mem.b[__x86_stw_index + 2] =  \
					KPROG_X86_STACK_BYTE(             \
						__x86_stw_narrowed, 2);   \
				__x86_stack_mem.b[__x86_stw_index + 3] =  \
					KPROG_X86_STACK_BYTE(             \
						__x86_stw_narrowed, 3);   \
			}                                                 \
			if (__x86_stw_width == X86_WIDTH_64) {            \
				__x86_stack_mem.b[__x86_stw_index + 4] =  \
					KPROG_X86_STACK_BYTE(             \
						__x86_stw_narrowed, 4);   \
				__x86_stack_mem.b[__x86_stw_index + 5] =  \
					KPROG_X86_STACK_BYTE(             \
						__x86_stw_narrowed, 5);   \
				__x86_stack_mem.b[__x86_stw_index + 6] =  \
					KPROG_X86_STACK_BYTE(             \
						__x86_stw_narrowed, 6);   \
				__x86_stack_mem.b[__x86_stw_index + 7] =  \
					KPROG_X86_STACK_BYTE(             \
						__x86_stw_narrowed, 7);   \
			}                                                 \
		}                                                         \
	} while (0)

#define X86_SIM_L_STACK_READ(OFF, WIDTH)                                    \
	({                                                                 \
		__u32 __x86_str_index = X86_SIM_L_STACK_INDEX(OFF);       \
		__u64 __x86_str_value;                                   \
		if (((WIDTH) ? (WIDTH) : X86_WIDTH_64) == X86_WIDTH_64 && \
		    KPROG_X86_STACK_WORD_ALIGNED(__x86_str_index)) {      \
			__x86_str_value = __x86_stack_mem.q               \
				[KPROG_X86_STACK_WORD_INDEX(             \
					__x86_str_index)];               \
		} else {                                                  \
			__u8 __x86_str_width =                            \
				(WIDTH) ? (WIDTH) : X86_WIDTH_64;         \
			__x86_str_value =                                 \
				__x86_stack_mem.b[__x86_str_index];       \
			if (__x86_str_width >= X86_WIDTH_16)              \
				__x86_str_value |=                        \
					KPROG_X86_STACK_ASSEMBLE(         \
						__x86_stack_mem.b[__x86_str_index + 1], 1);\
			if (__x86_str_width >= X86_WIDTH_32) {            \
				__x86_str_value |=                        \
					KPROG_X86_STACK_ASSEMBLE(         \
						__x86_stack_mem.b[__x86_str_index + 2], 2);\
				__x86_str_value |=                        \
					KPROG_X86_STACK_ASSEMBLE(         \
						__x86_stack_mem.b[__x86_str_index + 3], 3);\
			}                                                 \
			if (__x86_str_width == X86_WIDTH_64) {            \
				__x86_str_value |=                        \
					KPROG_X86_STACK_ASSEMBLE(         \
						__x86_stack_mem.b[__x86_str_index + 4], 4);\
				__x86_str_value |=                        \
					KPROG_X86_STACK_ASSEMBLE(         \
						__x86_stack_mem.b[__x86_str_index + 5], 5);\
				__x86_str_value |=                        \
					KPROG_X86_STACK_ASSEMBLE(         \
						__x86_stack_mem.b[__x86_str_index + 6], 6);\
				__x86_str_value |=                        \
					KPROG_X86_STACK_ASSEMBLE(         \
						__x86_stack_mem.b[__x86_str_index + 7], 7);\
			}                                                 \
		}                                                         \
		__x86_str_value;                                          \
	})

#define X86_SIM_L_STACK_PTR(OFF)                                           \
	((void *)&__x86_stack_mem.b[X86_SIM_L_STACK_INDEX((__s64)(long)(OFF))])

#define X86_SIM_L_HELPER_ARG_PTR(REG)                                      \
	X86_SIM_L_READ_REG_PTR(REG)

#define X86_SIM_L_LOAD_ADDR(ADDR, WIDTH) KPROG_X86_MEM_LOAD((ADDR), (WIDTH))

#define X86_SIM_L_LOAD_PTR_ADDR(ADDR) (*(void **)(ADDR))

#define X86_SIM_L_STORE_ADDR(ADDR, WIDTH, VALUE)                           \
	KPROG_X86_MEM_STORE((ADDR), (WIDTH), (VALUE))

#define X86_SIM_L_SET_LOGIC_FLAGS(RESULT, WIDTH)                            \
	do {                                                               \
		__u8 __x86_fl_width = (WIDTH) ? (WIDTH) : X86_WIDTH_64;   \
		__u64 __x86_fl_value = x86_apply_width((RESULT),          \
						      __x86_fl_width);    \
		__u32 __x86_fl_bits = x86_width_bits(__x86_fl_width);     \
		KPROG_X86_SET_LOGIC_FLAGS(__x86_cf, __x86_zf, __x86_sf,  \
			__x86_of, __x86_fl_value == 0,                     \
			(__x86_fl_value >> (__x86_fl_bits - 1)) & 1);       \
	} while (0)

#define X86_SIM_L_SET_SUB_FLAGS(LHS, RHS, RESULT, WIDTH)                    \
	do {                                                               \
		__u8 __x86_sub_width = (WIDTH) ? (WIDTH) : X86_WIDTH_64;  \
		__u64 __x86_sub_mask = x86_width_mask(__x86_sub_width);   \
		__u64 __x86_sub_a = (LHS) & __x86_sub_mask;               \
		__u64 __x86_sub_b = (RHS) & __x86_sub_mask;               \
		__u64 __x86_sub_r = (RESULT) & __x86_sub_mask;            \
		__u64 __x86_sub_sign = x86_width_sign_mask(__x86_sub_width);\
		KPROG_X86_SET_SUB_FLAGS(__x86_cf, __x86_zf, __x86_sf,   \
			__x86_of, __x86_sub_a, __x86_sub_b, __x86_sub_r, \
			__x86_sub_sign);                                    \
	} while (0)

#define X86_SIM_L_SET_ADD_FLAGS(LHS, RHS, RESULT, WIDTH)                    \
	do {                                                               \
		__u8 __x86_add_width = (WIDTH) ? (WIDTH) : X86_WIDTH_64;  \
		__u64 __x86_add_mask = x86_width_mask(__x86_add_width);   \
		__u64 __x86_add_a = (LHS) & __x86_add_mask;               \
		__u64 __x86_add_b = (RHS) & __x86_add_mask;               \
		__u64 __x86_add_r = (RESULT) & __x86_add_mask;            \
		__u64 __x86_add_sign = x86_width_sign_mask(__x86_add_width);\
		KPROG_X86_SET_ADD_FLAGS(__x86_cf, __x86_zf, __x86_sf,   \
			__x86_of, __x86_add_a, __x86_add_b, __x86_add_r, \
			__x86_add_sign);                                    \
	} while (0)

#define X86_SIM_L_SET_ADC_FLAGS(LHS, RHS, CARRY, RESULT, WIDTH)             \
	do {                                                               \
		__u8 __x86_adc_width = (WIDTH) ? (WIDTH) : X86_WIDTH_64;  \
		__u64 __x86_adc_mask = x86_width_mask(__x86_adc_width);   \
		__u64 __x86_adc_a = (LHS) & __x86_adc_mask;               \
		__u64 __x86_adc_b = (RHS) & __x86_adc_mask;               \
		__u64 __x86_adc_r = (RESULT) & __x86_adc_mask;            \
		__u64 __x86_adc_sign = x86_width_sign_mask(__x86_adc_width);\
		KPROG_X86_SET_ADC_FLAGS(__x86_cf, __x86_zf, __x86_sf,   \
			__x86_of, __x86_adc_a, __x86_adc_b, __x86_adc_r, \
			__x86_adc_sign, (CARRY));                           \
	} while (0)

#define X86_SIM_L_SET_SBB_FLAGS(LHS, RHS, BORROW, RESULT, WIDTH)            \
	do {                                                               \
		__u8 __x86_sbb_width = (WIDTH) ? (WIDTH) : X86_WIDTH_64;  \
		__u64 __x86_sbb_mask = x86_width_mask(__x86_sbb_width);   \
		__u64 __x86_sbb_a = (LHS) & __x86_sbb_mask;               \
		__u64 __x86_sbb_b = (RHS) & __x86_sbb_mask;               \
		__u64 __x86_sbb_r = (RESULT) & __x86_sbb_mask;            \
		__u64 __x86_sbb_sign = x86_width_sign_mask(__x86_sbb_width);\
		KPROG_X86_SET_SBB_FLAGS(__x86_cf, __x86_zf, __x86_sf,   \
			__x86_of, __x86_sbb_a, __x86_sbb_b, __x86_sbb_r,  \
			__x86_sbb_sign, (BORROW));                          \
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
		KPROG_X86_SET_IMUL_FLAGS(__x86_cf, __x86_of,           \
			__x86_imul_a_abs, __x86_imul_b_abs,          \
			__x86_imul_limit);                            \
	} while (0)

#define X86_SIM_L_SET_SHIFT_FLAGS(LHS, RHS, RESULT, ALU, WIDTH)             \
	do {                                                               \
		__u8 __x86_sh_raw_width = (WIDTH);                         \
		__u8 __x86_sh_width = __x86_sh_raw_width ?                  \
			__x86_sh_raw_width : X86_WIDTH_64;                    \
		__u32 __x86_sh_bits = x86_width_bits(__x86_sh_width);     \
		__u64 __x86_sh_mask = x86_width_mask(__x86_sh_width);     \
		__u64 __x86_sh_a = (LHS) & __x86_sh_mask;                 \
		__u64 __x86_sh_r = (RESULT) & __x86_sh_mask;              \
		__u8 __x86_sh_count = x86_shift_count((RHS), __x86_sh_width);\
		__u64 __x86_sh_sign = 1ULL << (__x86_sh_bits - 1);        \
		__u8 __x86_sh_alu = (ALU);                                 \
		KPROG_X86_SET_SHIFT_FLAGS(__x86_cf, __x86_zf, __x86_sf,   \
			__x86_of, __x86_sh_a, __x86_sh_count, __x86_sh_r,   \
			__x86_sh_bits, __x86_sh_sign, __x86_sh_alu);          \
	} while (0)

#define X86_SIM_L_SET_ALU_FLAGS(LHS, RHS, RESULT, ALU, WIDTH)               \
	do {                                                               \
		__u8 __x86_l_old_cf = __x86_cf;                          \
		if ((ALU) == X86_ALU_ADD || (ALU) == X86_ALU_ADC)         \
			X86_SIM_L_SET_ADD_FLAGS((LHS), (RHS), (RESULT), (WIDTH));\
		else if ((ALU) == X86_ALU_INC) {                          \
			X86_SIM_L_SET_ADD_FLAGS((LHS), 1, (RESULT), (WIDTH));\
			__x86_cf = __x86_l_old_cf;                         \
		} else if ((ALU) == X86_ALU_DEC) {                          \
			X86_SIM_L_SET_SUB_FLAGS((LHS), 1, (RESULT), (WIDTH));\
			__x86_cf = __x86_l_old_cf;                         \
		} else if ((ALU) == X86_ALU_SUB)                          \
			X86_SIM_L_SET_SUB_FLAGS((LHS), (RHS), (RESULT), (WIDTH));\
		else if ((ALU) == X86_ALU_SBB)                            \
			X86_SIM_L_SET_SBB_FLAGS((LHS), (RHS), 0, (RESULT), (WIDTH));\
		else if ((ALU) == X86_ALU_NEG)                            \
			X86_SIM_L_SET_SUB_FLAGS(0, (LHS), (RESULT), (WIDTH));\
		else if ((ALU) == X86_ALU_NOT)                            \
			KPROG_X86_PRESERVE_FLAGS();                       \
		else if ((ALU) == X86_ALU_SHL || (ALU) == X86_ALU_SHR ||  \
			 (ALU) == X86_ALU_SAR || (ALU) == X86_ALU_ROL)    \
			X86_SIM_L_SET_SHIFT_FLAGS((LHS), (RHS), (RESULT), (ALU), (WIDTH));\
		else if ((ALU) == X86_ALU_IMUL)                           \
			X86_SIM_L_SET_IMUL_FLAGS((LHS), (RHS), (WIDTH));   \
		else                                                      \
			X86_SIM_L_SET_LOGIC_FLAGS((RESULT), (WIDTH));      \
	} while (0)

#define X86_SIM_L_EVAL_CC(CC)                                               \
	KPROG_X86_EVAL_CC((CC), __x86_cf, __x86_zf, __x86_sf, __x86_of)

/* The read-dispatch classification (stack read vs. ABI pointer load vs.
 * ordinary load) is the machine-checked KPROG_X86_MEM_READ_SRC contract — the
 * same contract the arm64 read path routes through — so the sim no longer
 * restates the predicate ladder inline. */
#define X86_SIM_L_MEM_READ_SRC(BASE_REG, MEM_WIDTH)                         \
	KPROG_X86_MEM_READ_SRC(((BASE_REG) == X86_RSP),                     \
		X86_SIM_L_REG_TAG(BASE_REG), (MEM_WIDTH))
/* The store-target classification (stack write vs. ordinary little-endian
 * store) is the machine-checked KPROG_X86_STORE_ARM contract, so the store
 * body no longer restates the stack-pointer branch inline. */
#define X86_SIM_L_MEM_STORE_SRC(DST)                                        \
	KPROG_X86_STORE_ARM((DST) == X86_RSP)
/* The MOVBE store-target classification is the machine-checked
 * KPROG_X86_MOVBE_ARM contract, so the MOVBE store body no longer restates
 * the stack-pointer branch inline. */
#define X86_SIM_L_MEM_MOVBE_SRC(DST)                                        \
	KPROG_X86_MOVBE_ARM((DST) == X86_RSP)
/* The XMM0 pair-move arm classification is the machine-checked
 * KPROG_X86_XMM0_ARM contract, so both XMM0 bodies share its stack-pointer
 * test rather than restating it inline. */
#define X86_SIM_L_MEM_XMM0_ARM(BASE_REG)                                    \
	KPROG_X86_XMM0_ARM((BASE_REG) == X86_RSP)


#define X86_SIM_L_READ_MEM_VALUE(BASE_REG, AUX, IMM, WIDTH, STORE_DISP)      \
	({                                                                 \
		void *__x86_l_base_ptr = (void *)0;                      \
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
		switch (X86_SIM_L_MEM_READ_SRC(BASE_REG,                 \
					       __x86_l_mem_width)) {     \
		case KPROG_X86_MEM_SRC_STACK:                            \
			__x86_l_value = X86_SIM_L_STACK_READ(             \
				(__s64)(long)__x86_l_base_ptr + __x86_l_disp,\
				__x86_l_mem_width);                       \
			break;                                           \
		case KPROG_X86_MEM_SRC_ABI_PTR_LOAD:                     \
			__x86_l_value =                                  \
				(__u64)(long)X86_SIM_L_LOAD_PTR_ADDR(     \
					__x86_l_addr);                    \
			break;                                           \
		default:                                                 \
			__x86_l_value = X86_SIM_L_LOAD_ADDR(             \
				(void *)(long)__x86_l_addr,              \
				__x86_l_mem_width);                      \
			break;                                           \
		}                                                         \
		__x86_l_value;                                            \
	})

#define X86_SIM_L_EXEC_MOV_LOAD(OP, DST, SRC, FLAGS, AUX, IMM)              \
	do {                                                               \
		__u8 __x86_l_write_width =                                 \
			KPROG_X86_MOV_LOAD_WRITE_WIDTH(FLAGS);             \
		__u8 __x86_l_mem_width =                                   \
			KPROG_X86_MOV_LOAD_MEM_WIDTH((FLAGS), (AUX));      \
		__u8 __x86_l_arm = KPROG_X86_MOV_LOAD_ARM(                 \
			(SRC) == X86_RSP, (OP) == X86_OP_MOV_LOAD,         \
			__x86_l_mem_width, __x86_l_write_width,            \
			X86_SIM_L_REG_TAG(SRC));                           \
		__s64 __x86_l_disp = X86_SIM_L_MEM_OFFSET((AUX), x86_simm(IMM));\
		void *__x86_l_base_ptr = (void *)0;                      \
		__u64 __x86_l_value = 0;                                 \
		if ((SRC) != X86_REG_NONE)                               \
			__x86_l_base_ptr = X86_SIM_L_READ_REG_PTR(SRC);   \
		X86_SIM_L_BARRIER_VAR(__x86_l_disp);                    \
		void *__x86_l_addr = (__u8 *)__x86_l_base_ptr +           \
				     __x86_l_disp;                       \
		switch (X86_SIM_L_MEM_READ_SRC(SRC, __x86_l_mem_width)) {\
		case KPROG_X86_MEM_SRC_STACK:                            \
			__x86_l_value = X86_SIM_L_STACK_READ(             \
				(__s64)(long)__x86_l_base_ptr + __x86_l_disp,\
				__x86_l_mem_width);                       \
			X86_SIM_L_WRITE_REG_WIDTH((DST), __x86_l_value,   \
						  __x86_l_write_width);     \
			break;                                           \
		case KPROG_X86_MEM_SRC_ABI_PTR_LOAD:                     \
			if (__x86_l_arm != KPROG_X86_MOV_LOAD_ARM_ABI_PTR) {\
				__x86_l_value = X86_SIM_L_LOAD_ADDR(      \
					(void *)(long)__x86_l_addr,       \
					__x86_l_mem_width);               \
				X86_SIM_L_WRITE_REG_WIDTH((DST),          \
					__x86_l_value, __x86_l_write_width);\
				break;                                    \
			}                                                 \
			__u8 __x86_l_ptr_tag = KPROG_ABI_LOAD_TAG(       \
				__x86_sim_abi_kind, __x86_l_disp,          \
				X86_SIM_TAG_SCALAR, X86_SIM_TAG_PACKET,    \
				X86_SIM_TAG_PACKET_END);                   \
			X86_SIM_L_WRITE_REG_PTR_TAG((DST),                \
				X86_SIM_L_LOAD_PTR_ADDR(__x86_l_addr),    \
				__x86_l_ptr_tag);                        \
			break;                                           \
		default:                                                 \
			__x86_l_value = X86_SIM_L_LOAD_ADDR(             \
				(void *)(long)__x86_l_addr,              \
				__x86_l_mem_width);                       \
			if ((OP) == X86_OP_MOVSX_LOAD)                    \
				__x86_l_value = x86_sign_extend(           \
					__x86_l_value, __x86_l_mem_width);  \
			X86_SIM_L_WRITE_REG_WIDTH((DST), __x86_l_value,   \
						  __x86_l_write_width);     \
			break;                                           \
		}                                                         \
	} while (0)

#define X86_SIM_L_EXEC_STORE(OP, DST, SRC, FLAGS, AUX, IMM)                 \
	do {                                                               \
		__u8 __x86_l_width = KPROG_X86_STORE_WIDTH(FLAGS);        \
		__s64 __x86_l_disp =                                      \
			KPROG_X86_STORE_DISP((OP) == X86_OP_MOV_STORE_IMM, IMM);\
		void *__x86_l_base_ptr = (void *)0;                      \
		__u64 __x86_l_value =                                     \
			KPROG_X86_STORE_VALUE(                            \
				(OP) == X86_OP_MOV_STORE_IMM, (IMM),      \
				__x86_l_width, X86_SIM_L_READ_REG(SRC));  \
		__x86_l_value = KPROG_X86_STORE_SHIFTED_VALUE(            \
			__x86_l_value,                                    \
			KPROG_X86_STORE_SRC_SHIFT(                        \
				(OP) == X86_OP_MOV_STORE_IMM, (AUX)));    \
		__x86_l_disp = X86_SIM_L_MEM_OFFSET((AUX), __x86_l_disp); \
		X86_SIM_L_BARRIER_VAR(__x86_l_disp);                    \
		if ((DST) != X86_REG_NONE)                               \
			__x86_l_base_ptr = X86_SIM_L_READ_REG_PTR(DST);   \
		switch (X86_SIM_L_MEM_STORE_SRC(DST)) {                   \
		case KPROG_X86_STORE_ARM_STACK:                           \
			X86_SIM_L_STACK_WRITE(                            \
				(__s64)(long)__x86_l_base_ptr + __x86_l_disp,\
				X86_SIM_L_EFFECTIVE_WIDTH(FLAGS),          \
				__x86_l_value);                            \
			break;                                           \
		default:                                                 \
			void *__x86_l_addr = (__u8 *)__x86_l_base_ptr +   \
					     __x86_l_disp;               \
			X86_SIM_L_STORE_ADDR(__x86_l_addr,                \
					     __x86_l_width, __x86_l_value);\
			break;                                           \
		}                                                         \
		} while (0)

#define X86_SIM_L_EXEC_MOVBE_LOAD(DST, SRC, FLAGS, AUX, IMM)               \
	do {                                                               \
		__u8 __x86_l_width = KPROG_X86_MOVBE_WIDTH(FLAGS);        \
		__u64 __x86_l_value = X86_SIM_L_READ_MEM_VALUE((SRC),     \
			(AUX), (IMM), __x86_l_width, 0);                  \
		X86_SIM_L_WRITE_REG_WIDTH((DST),                          \
			x86_bswap(__x86_l_value, __x86_l_width),          \
			__x86_l_width);                                    \
	} while (0)

#define X86_SIM_L_EXEC_MOVBE_STORE(DST, SRC, FLAGS, AUX, IMM)              \
	do {                                                               \
		__u8 __x86_l_width = KPROG_X86_MOVBE_WIDTH(FLAGS);        \
		__s64 __x86_l_disp = X86_SIM_L_MEM_OFFSET((AUX),          \
			KPROG_X86_MOVBE_DISP(IMM));                       \
		X86_SIM_L_BARRIER_VAR(__x86_l_disp);                    \
		void *__x86_l_base_ptr = (DST) == X86_REG_NONE ?          \
			(void *)0 : X86_SIM_L_READ_REG_PTR(DST);          \
		__u64 __x86_l_value = x86_bswap(                          \
			X86_SIM_L_READ_REG(SRC), __x86_l_width);          \
		switch (X86_SIM_L_MEM_MOVBE_SRC(DST)) {                   \
		case KPROG_X86_MOVBE_ARM_STACK:                           \
			X86_SIM_L_STACK_WRITE(                            \
				(__s64)(long)__x86_l_base_ptr + __x86_l_disp,\
				__x86_l_width, __x86_l_value);             \
			break;                                            \
		default:                                                  \
			void *__x86_l_addr = (__u8 *)__x86_l_base_ptr +   \
					     __x86_l_disp;               \
			X86_SIM_L_STORE_ADDR(__x86_l_addr, __x86_l_width, \
					     __x86_l_value);              \
			break;                                            \
		}                                                         \
	} while (0)

#define X86_SIM_L_EXEC_LOAD_XMM0(SRC, AUX, IMM)                             \
	do {                                                               \
		__s64 __x86_l_disp = X86_SIM_L_MEM_OFFSET((AUX),          \
			x86_simm(IMM));                                   \
		__u8 __x86_l_arm = X86_SIM_L_MEM_XMM0_ARM(SRC);           \
		__u8 __x86_l_base_none = ((SRC) == X86_REG_NONE);         \
		__u8 __x86_l_base_form = KPROG_X86_XMM0_BASE_FORM(1U);    \
		X86_SIM_L_BARRIER_VAR(__x86_l_disp);                    \
		switch (__x86_l_arm) {                                    \
		case KPROG_X86_XMM0_ARM_STACK: {                          \
			void *__x86_l_base_ptr = X86_SIM_L_READ_REG_PTR(SRC);\
			__x86_xmm0_lo = X86_SIM_L_STACK_READ(             \
				(__s64)(long)__x86_l_base_ptr + __x86_l_disp,\
				X86_WIDTH_64);                            \
			__x86_xmm0_hi = X86_SIM_L_STACK_READ(             \
				(__s64)(long)__x86_l_base_ptr + __x86_l_disp  \
					+ KPROG_X86_XMM0_LANE_OFFSET(1),  \
				X86_WIDTH_64);                            \
			break;                                            \
		}                                                         \
		default: {                                                \
			void *__x86_l_base_ptr =                          \
				KPROG_X86_XMM0_BASE_PTR(                  \
					__x86_l_base_none, __x86_l_base_form, \
					(IMM), X86_SIM_L_READ_REG_PTR(SRC));  \
			void *__x86_l_addr =                              \
				KPROG_X86_XMM0_ADDS_DISP(                 \
					__x86_l_base_none, __x86_l_base_form) \
					? (__u8 *)__x86_l_base_ptr        \
						  + __x86_l_disp          \
					: __x86_l_base_ptr;               \
			__x86_xmm0_lo = X86_SIM_L_LOAD_ADDR(__x86_l_addr,\
				X86_WIDTH_64);                            \
			__x86_xmm0_hi = X86_SIM_L_LOAD_ADDR(             \
				(__u8 *)__x86_l_addr                       \
					+ KPROG_X86_XMM0_LANE_OFFSET(1),  \
				X86_WIDTH_64);                            \
			break;                                            \
		}                                                         \
		}                                                         \
	} while (0)

#define X86_SIM_L_EXEC_STORE_XMM0(DST, AUX, IMM)                            \
	do {                                                               \
		__s64 __x86_l_disp = X86_SIM_L_MEM_OFFSET((AUX),          \
			x86_simm(IMM));                                   \
		__u8 __x86_l_arm = X86_SIM_L_MEM_XMM0_ARM(DST);           \
		__u8 __x86_l_base_none = ((DST) == X86_REG_NONE);         \
		__u8 __x86_l_base_form = KPROG_X86_XMM0_BASE_FORM(0U);    \
		void *__x86_l_base_ptr = KPROG_X86_XMM0_BASE_PTR(         \
			__x86_l_base_none, __x86_l_base_form, (IMM),      \
			X86_SIM_L_READ_REG_PTR(DST));                     \
		X86_SIM_L_BARRIER_VAR(__x86_l_disp);                    \
		switch (__x86_l_arm) {                                    \
		case KPROG_X86_XMM0_ARM_STACK:                            \
			X86_SIM_L_STACK_WRITE(                            \
				(__s64)(long)__x86_l_base_ptr + __x86_l_disp,\
				X86_WIDTH_64, __x86_xmm0_lo);             \
			X86_SIM_L_STACK_WRITE(                            \
				(__s64)(long)__x86_l_base_ptr + __x86_l_disp  \
					+ KPROG_X86_XMM0_LANE_OFFSET(1),  \
				X86_WIDTH_64, __x86_xmm0_hi);             \
			break;                                            \
		default: {                                                \
			void *__x86_l_addr =                              \
				KPROG_X86_XMM0_ADDS_DISP(                 \
					__x86_l_base_none, __x86_l_base_form) \
					? (__u8 *)__x86_l_base_ptr        \
						  + __x86_l_disp          \
					: __x86_l_base_ptr;               \
			X86_SIM_L_STORE_ADDR(__x86_l_addr, X86_WIDTH_64,  \
					     __x86_xmm0_lo);              \
			X86_SIM_L_STORE_ADDR(                             \
				(__u8 *)__x86_l_addr                       \
					+ KPROG_X86_XMM0_LANE_OFFSET(1),  \
				X86_WIDTH_64, __x86_xmm0_hi);             \
			break;                                            \
		}                                                         \
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
				__u8 __x86_l_dst_tag =                 \
					KPROG_PTR_ADD64_TAG(__x86_l_src_tag);\
				if ((SRC) == X86_RSP) {                  \
					__s64 __x86_l_stack_off =          \
						(__s64)(long)__x86_l_src_ptr + __x86_l_off;\
					__x86_l_result =                  \
						X86_SIM_L_STACK_PTR(__x86_l_stack_off);\
					__x86_l_dst_tag = X86_SIM_TAG_STACK;\
				} else {                                  \
					__x86_l_result =                  \
						KPROG_PTR_ADD64_BITS(          \
							__x86_l_src_ptr, __x86_l_off);\
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
		__u32 __x86_l_aux = (ALU);                               \
		__u8 __x86_l_alu =                                      \
			KPROG_X86_REG_LANE_AUX_PAYLOAD(__x86_l_aux);       \
		__u8 __x86_l_dst_shift =                                  \
			KPROG_X86_REG_LANE_AUX_DST_SHIFT(__x86_l_aux);       \
		__u64 __x86_l_lhs = X86_SIM_L_READ_REG_WIDTH_SHIFT(       \
			(DST), __x86_l_width, __x86_l_dst_shift);           \
		__u64 __x86_l_rhs = x86_store_imm_value((IMM), __x86_l_width);\
		__u64 __x86_l_result;                                    \
		if (KPROG_X86_ALU_USES_SBB_HANDLER(__x86_l_alu)) {        \
			__u8 __x86_l_borrow = __x86_cf;                   \
			__x86_l_result = KPROG_X86_SBB_RESULT(             \
				__x86_l_lhs, __x86_l_rhs, __x86_l_borrow);  \
			X86_SIM_L_SET_SBB_FLAGS(__x86_l_lhs, __x86_l_rhs, \
						__x86_l_borrow,          \
						__x86_l_result,          \
						__x86_l_width);          \
			X86_SIM_L_WRITE_REG_WIDTH_SHIFT((DST), __x86_l_result,\
				__x86_l_width, __x86_l_dst_shift);           \
		} else if (KPROG_X86_ALU_USES_ADC_HANDLER(__x86_l_alu)) {  \
			__u8 __x86_l_carry = __x86_cf;                    \
			__x86_l_result = KPROG_X86_ADC_RESULT(             \
				__x86_l_lhs, __x86_l_rhs, __x86_l_carry);   \
			X86_SIM_L_SET_ADC_FLAGS(__x86_l_lhs, __x86_l_rhs,  \
						__x86_l_carry,        \
						__x86_l_result,       \
						__x86_l_width);       \
			X86_SIM_L_WRITE_REG_WIDTH_SHIFT((DST), __x86_l_result,\
				__x86_l_width, __x86_l_dst_shift);           \
		} else {                                                   \
			__x86_l_result = x86_alu_result(__x86_l_lhs,       \
							__x86_l_rhs,       \
							__x86_l_alu,       \
							__x86_l_width);    \
			X86_SIM_L_SET_ALU_FLAGS(__x86_l_lhs, __x86_l_rhs,  \
						__x86_l_result, __x86_l_alu,\
						__x86_l_width);        \
			X86_SIM_L_WRITE_REG_WIDTH_SHIFT((DST), __x86_l_result,\
				__x86_l_width, __x86_l_dst_shift);           \
		}                                                         \
	} while (0)

#define X86_SIM_L_EXEC_ALU_REG(DST, SRC, FLAGS, ALU)                        \
	do {                                                               \
		__u8 __x86_l_width = (FLAGS) ? (FLAGS) : X86_WIDTH_64;    \
		__u32 __x86_l_aux = (ALU);                               \
		__u8 __x86_l_alu =                                      \
			KPROG_X86_REG_LANE_AUX_PAYLOAD(__x86_l_aux);       \
		__u8 __x86_l_dst_shift =                                  \
			KPROG_X86_REG_LANE_AUX_DST_SHIFT(__x86_l_aux);       \
		__u64 __x86_l_lhs = X86_SIM_L_READ_REG_WIDTH_SHIFT(       \
			(DST), __x86_l_width, __x86_l_dst_shift);           \
		__u64 __x86_l_rhs = X86_SIM_L_READ_REG_WIDTH_SHIFT(       \
			(SRC), __x86_l_width,                              \
			KPROG_X86_REG_LANE_AUX_SRC_SHIFT(__x86_l_aux));      \
		__u64 __x86_l_result;                                    \
		if (KPROG_X86_ALU_USES_SBB_HANDLER(__x86_l_alu)) {        \
			__u8 __x86_l_borrow = __x86_cf;                   \
			__x86_l_result = KPROG_X86_SBB_RESULT(             \
				__x86_l_lhs, __x86_l_rhs, __x86_l_borrow);  \
			X86_SIM_L_SET_SBB_FLAGS(__x86_l_lhs, __x86_l_rhs, \
						__x86_l_borrow,          \
						__x86_l_result,          \
						__x86_l_width);          \
			X86_SIM_L_WRITE_REG_WIDTH_SHIFT((DST), __x86_l_result,\
				__x86_l_width, __x86_l_dst_shift);           \
		} else if (KPROG_X86_ALU_USES_ADC_HANDLER(__x86_l_alu)) {  \
			__u8 __x86_l_carry = __x86_cf;                    \
			__x86_l_result = KPROG_X86_ADC_RESULT(             \
				__x86_l_lhs, __x86_l_rhs, __x86_l_carry);   \
			X86_SIM_L_SET_ADC_FLAGS(__x86_l_lhs, __x86_l_rhs,  \
						__x86_l_carry,        \
						__x86_l_result,       \
						__x86_l_width);       \
			X86_SIM_L_WRITE_REG_WIDTH_SHIFT((DST), __x86_l_result,\
				__x86_l_width, __x86_l_dst_shift);           \
		} else {                                                   \
			__x86_l_result = x86_alu_result(__x86_l_lhs,       \
							__x86_l_rhs,       \
							__x86_l_alu,       \
							__x86_l_width);    \
			X86_SIM_L_SET_ALU_FLAGS(__x86_l_lhs, __x86_l_rhs,  \
						__x86_l_result, __x86_l_alu,\
						__x86_l_width);        \
			X86_SIM_L_WRITE_REG_WIDTH_SHIFT((DST), __x86_l_result,\
				__x86_l_width, __x86_l_dst_shift);           \
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
		if (KPROG_X86_ALU_USES_SBB_HANDLER(__x86_l_alu)) {        \
			__u8 __x86_l_borrow = __x86_cf;                   \
			__x86_l_result = KPROG_X86_SBB_RESULT(             \
				__x86_l_lhs, __x86_l_rhs, __x86_l_borrow);  \
			X86_SIM_L_SET_SBB_FLAGS(__x86_l_lhs, __x86_l_rhs, \
				__x86_l_borrow, __x86_l_result, __x86_l_width);\
		} else if (KPROG_X86_ALU_USES_ADC_HANDLER(__x86_l_alu)) {  \
			__u8 __x86_l_carry = __x86_cf;                    \
			__x86_l_result = KPROG_X86_ADC_RESULT(             \
				__x86_l_lhs, __x86_l_rhs, __x86_l_carry);   \
			X86_SIM_L_SET_ADC_FLAGS(__x86_l_lhs, __x86_l_rhs,  \
				__x86_l_carry, __x86_l_result, __x86_l_width);\
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
		__u64 __x86_l_result;                                    \
		__s64 __x86_l_disp = X86_SIM_L_MEM_OFFSET((AUX),          \
			x86_store_imm_disp(IMM));                         \
		void *__x86_l_base_ptr = (void *)0;                       \
		if (KPROG_X86_ALU_USES_SBB_HANDLER(__x86_l_alu)) {        \
			__u8 __x86_l_borrow = __x86_cf;                   \
			__x86_l_result = KPROG_X86_SBB_RESULT(             \
				__x86_l_lhs, __x86_l_rhs, __x86_l_borrow);  \
			X86_SIM_L_SET_SBB_FLAGS(__x86_l_lhs, __x86_l_rhs, \
				__x86_l_borrow, __x86_l_result, __x86_l_width);\
		} else if (KPROG_X86_ALU_USES_ADC_HANDLER(__x86_l_alu)) {  \
			__u8 __x86_l_carry = __x86_cf;                    \
			__x86_l_result = KPROG_X86_ADC_RESULT(             \
				__x86_l_lhs, __x86_l_rhs, __x86_l_carry);   \
			X86_SIM_L_SET_ADC_FLAGS(__x86_l_lhs, __x86_l_rhs,  \
				__x86_l_carry, __x86_l_result, __x86_l_width);\
		} else {                                                   \
			__x86_l_result = x86_alu_result(__x86_l_lhs,       \
				__x86_l_rhs, __x86_l_alu, __x86_l_width);    \
			X86_SIM_L_SET_ALU_FLAGS(__x86_l_lhs, __x86_l_rhs,  \
				__x86_l_result, __x86_l_alu, __x86_l_width); \
		}                                                         \
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

#define X86_SIM_L_EXEC_ALU_MEM_REG(DST, SRC, FLAGS, AUX, IMM)               \
	do {                                                               \
		__u8 __x86_l_width = (FLAGS) ? (FLAGS) : X86_WIDTH_64;    \
		__u8 __x86_l_alu = X86_MEM_AUX_GET_ALU_OP(AUX);           \
		__u64 __x86_l_lhs = X86_SIM_L_READ_MEM_VALUE((DST), (AUX),\
			(IMM), __x86_l_width, 0);                         \
		__u64 __x86_l_rhs = X86_SIM_L_READ_REG(SRC);             \
		__u64 __x86_l_result;                                    \
		__s64 __x86_l_disp = X86_SIM_L_MEM_OFFSET((AUX),          \
			x86_simm(IMM));                                    \
		void *__x86_l_base_ptr = (void *)0;                       \
		if (KPROG_X86_ALU_USES_SBB_HANDLER(__x86_l_alu)) {        \
			__u8 __x86_l_borrow = __x86_cf;                   \
			__x86_l_result = KPROG_X86_SBB_RESULT(             \
				__x86_l_lhs, __x86_l_rhs, __x86_l_borrow);  \
			X86_SIM_L_SET_SBB_FLAGS(__x86_l_lhs, __x86_l_rhs, \
				__x86_l_borrow, __x86_l_result, __x86_l_width);\
		} else if (KPROG_X86_ALU_USES_ADC_HANDLER(__x86_l_alu)) {  \
			__u8 __x86_l_carry = __x86_cf;                    \
			__x86_l_result = KPROG_X86_ADC_RESULT(             \
				__x86_l_lhs, __x86_l_rhs, __x86_l_carry);   \
			X86_SIM_L_SET_ADC_FLAGS(__x86_l_lhs, __x86_l_rhs,  \
				__x86_l_carry, __x86_l_result, __x86_l_width);\
		} else {                                                   \
			__x86_l_result = x86_alu_result(__x86_l_lhs,       \
				__x86_l_rhs, __x86_l_alu, __x86_l_width);    \
			X86_SIM_L_SET_ALU_FLAGS(__x86_l_lhs, __x86_l_rhs,  \
				__x86_l_result, __x86_l_alu, __x86_l_width); \
		}                                                         \
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

/*
 * `BZHI` (register value and count) and `BZHI_MEM` (memory value, AUX-named
 * count) share one composition whose value source, count source, byte mask,
 * and single resolved width come from the machine-checked x86_bzhi.h
 * contract; the reads, the masked bit-clear, the flag production, and the
 * writeback stay here.
 */
#define X86_SIM_L_EXEC_BZHI_STEP(OP_IS_MEM, DST, SRC, COUNT, AUX, FLAGS, IMM) \
	do {                                                               \
		__u8 __x86_l_width =                                      \
			KPROG_X86_BZHI_WRITE_WIDTH(FLAGS);                \
		__u32 __x86_l_bits = x86_width_bits(__x86_l_width);       \
		__u64 __x86_l_src;                                        \
		__u64 __x86_l_count;                                      \
		if (KPROG_X86_BZHI_VALUE_SOURCE(OP_IS_MEM) ==             \
		    KPROG_X86_BZHI_VALUE_MEMORY)                          \
			__x86_l_src = X86_SIM_L_READ_MEM_VALUE(           \
				(SRC), (AUX), (IMM), __x86_l_width, 0);   \
		else                                                      \
			__x86_l_src = X86_SIM_L_READ_REG(SRC);            \
		if (KPROG_X86_BZHI_COUNT_SOURCE(OP_IS_MEM) ==             \
		    KPROG_X86_BZHI_COUNT_AUX_SHIFT)                       \
			__x86_l_count = X86_SIM_L_READ_REG(               \
				X86_REG_AUX_GET_SRC_SHIFT(AUX)) &         \
				KPROG_X86_BZHI_COUNT_MASK;                \
		else                                                      \
			__x86_l_count = X86_SIM_L_READ_REG(COUNT) &       \
				KPROG_X86_BZHI_COUNT_MASK;                \
		__u64 __x86_l_result =                                   \
			kprog_x86_bzhi_value(__x86_l_src, __x86_l_count,  \
					     __x86_l_width);              \
		__x86_cf = __x86_l_count >= __x86_l_bits;                 \
		__x86_of = 0;                                             \
		__x86_sf = 0;                                             \
		__x86_zf = __x86_l_result == 0;                           \
		X86_SIM_L_WRITE_REG_WIDTH((DST), __x86_l_result,          \
					  __x86_l_width);                    \
	} while (0)

#define X86_SIM_L_EXEC_BZHI(DST, SRC, COUNT, FLAGS)                         \
	X86_SIM_L_EXEC_BZHI_STEP(0U, (DST), (SRC), (COUNT), 0U, (FLAGS), 0U)

#define X86_SIM_L_EXEC_BZHI_MEM(DST, SRC, FLAGS, AUX, IMM)                  \
	X86_SIM_L_EXEC_BZHI_STEP(1U, (DST), (SRC), X86_REG_NONE, (AUX),     \
				 (FLAGS), (IMM))

/* The three `BT` forms share one composition that routes the tested-base
 * source and the bit-index source through the machine-checked
 * `x86_bt.h` contract. Only the memory form reads memory; the index source is
 * a register (`BT`), the raw immediate (`BT_IMM`), or the immediate widened to
 * 32 bits (`BT_MEM_IMM`). The reads, the bit test, and the CF assignment stay
 * in the composed body by contract design. */
#define X86_SIM_L_EXEC_BT_STEP(OP_IS_MEM, INDEX_IS_MEM, INDEX_IS_REG, DST, \
			       SRC, FLAGS, AUX, IMM)                       \
	do {                                                               \
		__u8 __x86_l_width =                                      \
			KPROG_X86_BT_WRITE_WIDTH(FLAGS);                  \
		__u64 __x86_l_base;                                       \
		if (KPROG_X86_BT_BASE_SOURCE(OP_IS_MEM) ==                \
		    KPROG_X86_BT_BASE_MEMORY)                             \
			__x86_l_base = X86_SIM_L_READ_MEM_VALUE(          \
				(DST), (AUX), x86_store_imm_disp(IMM),     \
				__x86_l_width, 1);                         \
		else                                                      \
			__x86_l_base = X86_SIM_L_READ_REG(DST);           \
		__u8 __x86_l_index_source =                               \
			KPROG_X86_BT_INDEX_SOURCE(INDEX_IS_MEM,            \
						  INDEX_IS_REG);           \
		__u64 __x86_l_index;                                      \
		if (__x86_l_index_source == KPROG_X86_BT_INDEX_REGISTER)  \
			__x86_l_index = X86_SIM_L_READ_REG(SRC);          \
		else if (__x86_l_index_source == KPROG_X86_BT_INDEX_IMM32)\
			__x86_l_index = x86_store_imm_value(              \
				(IMM), X86_WIDTH_32);                      \
		else                                                      \
			__x86_l_index = (IMM);                            \
		__x86_cf = kprog_x86_bt_value(__x86_l_base,               \
					      __x86_l_index,              \
					      __x86_l_width);             \
	} while (0)

#define X86_SIM_L_EXEC_BT(DST, SRC, FLAGS)                                  \
	X86_SIM_L_EXEC_BT_STEP(0U, 0U, 1U, (DST), (SRC), (FLAGS), 0U, 0U)

#define X86_SIM_L_EXEC_BT_IMM(DST, FLAGS, IMM)                              \
	X86_SIM_L_EXEC_BT_STEP(0U, 0U, 0U, (DST), 0U, (FLAGS), 0U, (IMM))

#define X86_SIM_L_EXEC_BT_MEM_IMM(DST, FLAGS, AUX, IMM)                     \
	X86_SIM_L_EXEC_BT_STEP(1U, 1U, 0U, (DST), 0U, (FLAGS), (AUX), (IMM))

#define X86_SIM_L_EXEC_IMUL_IMM(DST, SRC, FLAGS, IMM)                       \
	do {                                                               \
		__u8 __x86_l_width = (FLAGS) ? (FLAGS) : X86_WIDTH_64;    \
		__u64 __x86_l_lhs = X86_SIM_L_READ_REG(SRC);             \
		__u64 __x86_l_rhs = x86_sign_extend((IMM), __x86_l_width);\
		__u64 __x86_l_result = __x86_l_lhs * __x86_l_rhs;        \
		X86_SIM_L_SET_IMUL_FLAGS(__x86_l_lhs, __x86_l_rhs,       \
					 __x86_l_width);                 \
		X86_SIM_L_WRITE_REG_WIDTH((DST), __x86_l_result,         \
					  __x86_l_width);                    \
	} while (0)

#define X86_SIM_L_EXEC_IMUL_MEM_IMM(DST, SRC, FLAGS, AUX, IMM)              \
	do {                                                               \
		__u8 __x86_l_width = (FLAGS) ? (FLAGS) : X86_WIDTH_64;    \
		__u8 __x86_l_mem_width = X86_MEM_AUX_MEM_WIDTH(AUX);     \
		if (!__x86_l_mem_width)                                  \
			__x86_l_mem_width = __x86_l_width;                \
		__u64 __x86_l_lhs = X86_SIM_L_READ_MEM_VALUE((SRC),      \
			(AUX), x86_store_imm_disp(IMM), __x86_l_mem_width,\
			1);                                              \
		__u64 __x86_l_rhs = x86_sign_extend(                     \
			x86_store_imm_value((IMM), __x86_l_width),        \
			__x86_l_width);                                   \
		__u64 __x86_l_result = x86_sign_extend(__x86_l_lhs,      \
			__x86_l_mem_width) * __x86_l_rhs;                 \
		X86_SIM_L_SET_IMUL_FLAGS(__x86_l_lhs, __x86_l_rhs,       \
					 __x86_l_width);                 \
		X86_SIM_L_WRITE_REG_WIDTH((DST), __x86_l_result,         \
					  __x86_l_width);                    \
	} while (0)

#define X86_SIM_L_EXEC_MULX(DST, SRC, AUX, FLAGS)                           \
	do {                                                               \
		__u8 __x86_l_width = (FLAGS) ? (FLAGS) : X86_WIDTH_64;    \
		__u64 __x86_l_lhs = X86_SIM_L_READ_REG(X86_RDX);         \
		__u64 __x86_l_rhs = X86_SIM_L_READ_REG(SRC);             \
		__u64 __x86_l_low;                                       \
		__u64 __x86_l_high;                                      \
		if (__x86_l_width == X86_WIDTH_32) {                      \
			__u64 __x86_l_product = (__u64)(__u32)__x86_l_lhs *\
					       (__u64)(__u32)__x86_l_rhs;\
			__x86_l_low = (__u32)__x86_l_product;             \
			__x86_l_high = (__u32)(__x86_l_product >> 32);    \
		} else {                                                   \
			__u64 __x86_l_a0 = (__u32)__x86_l_lhs;            \
			__u64 __x86_l_a1 = __x86_l_lhs >> 32;             \
			__u64 __x86_l_b0 = (__u32)__x86_l_rhs;            \
			__u64 __x86_l_b1 = __x86_l_rhs >> 32;             \
			__u64 __x86_l_p0 = __x86_l_a0 * __x86_l_b0;      \
			__u64 __x86_l_p1 = __x86_l_a0 * __x86_l_b1;      \
			__u64 __x86_l_p2 = __x86_l_a1 * __x86_l_b0;      \
			__u64 __x86_l_p3 = __x86_l_a1 * __x86_l_b1;      \
			__u64 __x86_l_mid = (__x86_l_p0 >> 32) +         \
				(__u32)__x86_l_p1 + (__u32)__x86_l_p2;    \
			__x86_l_low = __x86_l_lhs * __x86_l_rhs;         \
			__x86_l_high = __x86_l_p3 + (__x86_l_p1 >> 32) + \
				(__x86_l_p2 >> 32) + (__x86_l_mid >> 32); \
		}                                                         \
		X86_SIM_L_WRITE_REG_WIDTH((DST), __x86_l_low,             \
					  __x86_l_width);                    \
		if ((AUX) != X86_REG_NONE)                                \
			X86_SIM_L_WRITE_REG_WIDTH((AUX), __x86_l_high,    \
						  __x86_l_width);        \
	} while (0)

#define X86_SIM_L_REP_MOVS_ONE(WIDTH, INDEX)                                \
	do {                                                               \
		if (__x86_l_i == (INDEX) && __x86_l_i < __x86_l_count) {  \
			void *__x86_l_src_addr = (__u8 *)__x86_l_src_ptr +\
				(__x86_l_i * (WIDTH));                    \
			void *__x86_l_dst_addr = (__u8 *)__x86_l_dst_ptr +\
				(__x86_l_i * (WIDTH));                    \
			__u64 __x86_l_value = X86_SIM_L_LOAD_ADDR(       \
				__x86_l_src_addr, (WIDTH));              \
			X86_SIM_L_STORE_ADDR(__x86_l_dst_addr, (WIDTH),  \
					     __x86_l_value);              \
		}                                                         \
	} while (0)

#define X86_SIM_L_EXEC_REP_MOVS(FLAGS, IMM)                                  \
	do {                                                               \
		__u8 __x86_l_width = KPROG_X86_REP_MOVS_WIDTH(FLAGS);    \
		__u64 __x86_l_count = (IMM);                             \
		void *__x86_l_src_ptr = X86_SIM_L_READ_REG_PTR(X86_RSI); \
		void *__x86_l_dst_ptr = X86_SIM_L_READ_REG_PTR(X86_RDI); \
		__u8 __x86_l_src_tag = X86_SIM_L_REG_TAG(X86_RSI);       \
		__u8 __x86_l_dst_tag = X86_SIM_L_REG_TAG(X86_RDI);       \
		__u32 __x86_l_i;                                         \
		for (__x86_l_i = 0; __x86_l_i < KPROG_X86_REP_MOVS_BOUND; \
			__x86_l_i++)                                             \
			X86_SIM_L_REP_MOVS_ONE(__x86_l_width, __x86_l_i); \
		X86_SIM_L_WRITE_REG_PTR_TAG(X86_RSI,                     \
			(__u8 *)__x86_l_src_ptr + __x86_l_count * __x86_l_width,\
			__x86_l_src_tag);                                \
		X86_SIM_L_WRITE_REG_PTR_TAG(X86_RDI,                     \
			(__u8 *)__x86_l_dst_ptr + __x86_l_count * __x86_l_width,\
			__x86_l_dst_tag);                                \
		X86_SIM_L_WRITE_REG_WIDTH(X86_RCX, 0,                     \
			KPROG_X86_REP_MOVS_COUNT_WIDTH);                         \
	} while (0)

/* The four block-copy/block-fill bodies compose the machine-checked
 * KPROG_X86_CALLMEM_* contract: the kind, count-source, and bound-form
 * selectors choose the array shape, the copied/filled length's source, and the
 * array bound, so the four bodies and the Lean refinement share one block-copy
 * composition rather than four restated loop ladders. */
#define X86_SIM_L_EXEC_CALL_MEM_STEP(IMM, OP_IS_COPY, OP_IS_REG)            \
	do {                                                                \
		void *__x86_l_dst_ptr = X86_SIM_L_READ_REG_PTR(X86_RDI);    \
		void *__x86_l_src_ptr = X86_SIM_L_READ_REG_PTR(X86_RSI);    \
		__u64 __x86_l_value = X86_SIM_L_READ_REG(X86_RSI);          \
		__u64 __x86_l_count;                                        \
		__u64 __x86_l_bound;                                        \
		__u32 __x86_l_i;                                            \
		if (KPROG_X86_CALLMEM_COUNT_SOURCE(OP_IS_REG) ==            \
		    KPROG_X86_CALLMEM_COUNT_REG)                            \
			__x86_l_count = X86_SIM_L_READ_REG(X86_RDX);        \
		else                                                        \
			__x86_l_count = (IMM);                              \
		__x86_l_bound =                                             \
			KPROG_X86_CALLMEM_BOUND_FORM(OP_IS_REG) ==          \
					KPROG_X86_CALLMEM_BOUND_FIXED       \
				? (__u64)KPROG_X86_CALLMEM_FIXED_BOUND      \
				: (__u64)(IMM);                             \
		for (__x86_l_i = 0; __x86_l_i < __x86_l_bound;              \
		     __x86_l_i++) {                                         \
			if (__x86_l_i < __x86_l_count) {                    \
				__u64 __x86_l_byte;                         \
				if (KPROG_X86_CALLMEM_KIND(OP_IS_COPY) ==   \
				    KPROG_X86_CALLMEM_COPY)                 \
					__x86_l_byte =                      \
						X86_SIM_L_LOAD_ADDR(        \
							(__u8 *)__x86_l_src_ptr + \
								__x86_l_i,  \
							X86_WIDTH_8);       \
				else                                        \
					__x86_l_byte = __x86_l_value & 0xff; \
				X86_SIM_L_STORE_ADDR(                       \
					(__u8 *)__x86_l_dst_ptr +           \
						__x86_l_i,                  \
					X86_WIDTH_8, __x86_l_byte);         \
			}                                                   \
		}                                                           \
		X86_SIM_L_WRITE_REG_PTR_TAG(X86_RAX, __x86_l_dst_ptr,       \
					    X86_SIM_L_REG_TAG(X86_RDI));    \
	} while (0)

#define X86_SIM_L_EXEC_CALL_MEMSET(IMM)                                     \
	X86_SIM_L_EXEC_CALL_MEM_STEP((IMM), 0U, 0U)

#define X86_SIM_L_EXEC_CALL_MEMSET_REG(IMM)                                 \
	X86_SIM_L_EXEC_CALL_MEM_STEP((IMM), 0U, 1U)

#define X86_SIM_L_EXEC_CALL_MEMCPY(IMM)                                     \
	X86_SIM_L_EXEC_CALL_MEM_STEP((IMM), 1U, 0U)

#define X86_SIM_L_EXEC_CALL_MEMCPY_REG(IMM)                                 \
	X86_SIM_L_EXEC_CALL_MEM_STEP((IMM), 1U, 1U)

/*
 * `ANDN` (register second operand) and `ANDN_MEM` (memory second operand)
 * share one composition whose second-operand source, destination write width,
 * and memory-read width come from the machine-checked x86_andn.h contract;
 * the complement/and, the flag production, and the writeback stay here.
 */
#define X86_SIM_L_EXEC_ANDN_STEP(OP_IS_MEM, DST, SRC, AUX, FLAGS, IMM)      \
	do {                                                               \
		__u8 __x86_l_width =                                      \
			KPROG_X86_ANDN_WRITE_WIDTH(FLAGS);                \
		__u64 __x86_l_src1 = X86_SIM_L_READ_REG(SRC);             \
		__u64 __x86_l_src2;                                       \
		if (KPROG_X86_ANDN_SOURCE(OP_IS_MEM) ==                   \
		    KPROG_X86_ANDN_SOURCE_MEMORY) {                       \
			__u8 __x86_l_andn_mem_width =                      \
				KPROG_X86_ANDN_MEM_WIDTH(                 \
					X86_MEM_AUX_MEM_WIDTH(AUX),       \
					(FLAGS));                         \
			__x86_l_src2 = X86_SIM_L_READ_MEM_VALUE(          \
				X86_REG_AUX_GET_SRC_SHIFT(AUX), (AUX),    \
				(IMM), __x86_l_andn_mem_width, 1);        \
		} else                                                    \
			__x86_l_src2 = X86_SIM_L_READ_REG(AUX);           \
		__u64 __x86_l_result = (~__x86_l_src1) & __x86_l_src2;    \
		X86_SIM_L_SET_LOGIC_FLAGS(__x86_l_result, __x86_l_width); \
		X86_SIM_L_WRITE_REG_WIDTH((DST), __x86_l_result,          \
					  __x86_l_width);                    \
	} while (0)

#define X86_SIM_L_EXEC_ANDN(DST, SRC, AUX, FLAGS)                           \
	X86_SIM_L_EXEC_ANDN_STEP(0U, (DST), (SRC), (AUX), (FLAGS), 0U)

#define X86_SIM_L_EXEC_ANDN_MEM(DST, SRC, FLAGS, AUX, IMM)                  \
	X86_SIM_L_EXEC_ANDN_STEP(1U, (DST), (SRC), (AUX), (FLAGS), (IMM))

#define X86_SIM_L_EXEC_CMP_MEM(OP, DST, SRC, FLAGS, AUX, IMM)               \
	do {                                                               \
		__u8 __x86_l_width = (FLAGS) ? (FLAGS) : X86_WIDTH_64;    \
		__u64 __x86_l_lhs = X86_SIM_L_READ_MEM_VALUE((DST), (AUX),\
			(IMM), __x86_l_width, (OP) != X86_OP_CMP_MEM_REG);\
		__u64 __x86_l_rhs = ((OP) == X86_OP_CMP_MEM_REG ||        \
				     (OP) == X86_OP_TEST_MEM_REG) ?       \
			X86_SIM_L_READ_REG(SRC) :                         \
			x86_store_imm_value((IMM), __x86_l_width);        \
		if ((OP) == X86_OP_TEST_MEM_IMM ||                         \
		    (OP) == X86_OP_TEST_MEM_REG)                           \
			X86_SIM_L_SET_LOGIC_FLAGS(__x86_l_lhs & __x86_l_rhs,\
						  __x86_l_width);        \
		else                                                      \
			X86_SIM_L_SET_SUB_FLAGS(__x86_l_lhs, __x86_l_rhs, \
				KPROG_X86_SBB_RESULT(__x86_l_lhs,          \
					__x86_l_rhs, 0), __x86_l_width);     \
	} while (0)

#define X86_SIM_L_EXEC_CMP_REG_MEM(DST, SRC, FLAGS, AUX, IMM)               \
	do {                                                               \
		__u8 __x86_l_width = (FLAGS) ? (FLAGS) : X86_WIDTH_64;    \
		__u64 __x86_l_lhs = X86_SIM_L_READ_REG(DST);             \
		__u64 __x86_l_rhs = X86_SIM_L_READ_MEM_VALUE((SRC), (AUX),\
			(IMM), __x86_l_width, 0);                         \
		X86_SIM_L_SET_SUB_FLAGS(__x86_l_lhs, __x86_l_rhs,        \
			KPROG_X86_SBB_RESULT(__x86_l_lhs, __x86_l_rhs, 0),\
			__x86_l_width);                                     \
	} while (0)

#define X86_SIM_L_EXEC_MOV_IMM_AUX(DST, FLAGS, AUX, IMM)                    \
	do {                                                               \
		__u8 __x86_l_width = (FLAGS) ? (FLAGS) : X86_WIDTH_64;    \
		X86_SIM_L_WRITE_REG_WIDTH_SHIFT((DST), (IMM), __x86_l_width,\
			KPROG_X86_REG_LANE_AUX_DST_SHIFT(AUX));              \
	} while (0)

#define X86_SIM_L_EXEC_MOV_IMM(DST, FLAGS, IMM)                             \
	X86_SIM_L_EXEC_MOV_IMM_AUX((DST), (FLAGS), 0U, (IMM))

#define X86_SIM_L_EXEC_MOV_REG_AUX(DST, SRC, FLAGS, AUX)                    \
	do {                                                               \
		__u8 __x86_l_width = (FLAGS) ? (FLAGS) : X86_WIDTH_64;    \
		if (__x86_l_width == X86_WIDTH_64 && (SRC) == X86_RSP) {  \
			X86_SIM_L_WRITE_REG_PTR_TAG((DST),                \
				X86_SIM_L_STACK_PTR(                       \
					(__s64)(long)X86_SIM_L_READ_REG_PTR(SRC)),\
				X86_SIM_TAG_STACK);                        \
		} else if (__x86_l_width == X86_WIDTH_64) {              \
			X86_SIM_L_WRITE_REG_PTR_TAG((DST),                \
				X86_SIM_L_READ_REG_PTR(SRC),              \
				X86_SIM_L_REG_TAG(SRC));                  \
		} else {                                                  \
			__u64 __x86_l_value = X86_SIM_L_READ_REG_WIDTH_SHIFT(\
				(SRC), __x86_l_width,                         \
				KPROG_X86_REG_LANE_AUX_SRC_SHIFT(AUX));       \
			X86_SIM_L_WRITE_REG_WIDTH_SHIFT((DST), __x86_l_value,\
				__x86_l_width,                                \
				KPROG_X86_REG_LANE_AUX_DST_SHIFT(AUX));        \
		}                                                         \
	} while (0)

#define X86_SIM_L_EXEC_MOV_REG(DST, SRC, FLAGS)                             \
	X86_SIM_L_EXEC_MOV_REG_AUX((DST), (SRC), (FLAGS), 0U)

#define X86_SIM_L_EXEC_MOVX_REG(OP, DST, SRC, FLAGS, AUX)                   \
	do {                                                               \
		__u8 __x86_l_width = (FLAGS) ? (FLAGS) : X86_WIDTH_64;    \
		__u8 __x86_l_src_width = (AUX) ? (AUX) : __x86_l_width;   \
		__u64 __x86_l_value = X86_SIM_L_READ_REG(SRC);            \
		__x86_l_value = (OP) == X86_OP_MOVSX_REG ?                \
			x86_sign_extend(__x86_l_value, __x86_l_src_width) :\
			x86_apply_width(__x86_l_value, __x86_l_src_width); \
		X86_SIM_L_WRITE_REG_WIDTH((DST), __x86_l_value,           \
					  __x86_l_width);                    \
	} while (0)

#define X86_SIM_L_EXEC_CMP_REG_STEP(OP_IS_TEST, RHS_IS_REG, DST, FLAGS,     \
				    AUX, SRC, IMM)                      \
	do {                                                               \
		__u8 __x86_l_width =                                      \
			KPROG_X86_CMPOP_WRITE_WIDTH(FLAGS);               \
		__u32 __x86_l_aux = (AUX);                               \
		__u64 __x86_l_lhs = X86_SIM_L_READ_REG_WIDTH_SHIFT(       \
			(DST), __x86_l_width,                              \
			KPROG_X86_REG_LANE_AUX_DST_SHIFT(__x86_l_aux));      \
		__u64 __x86_l_rhs;                                       \
		if (KPROG_X86_CMPOP_RHS_SOURCE(RHS_IS_REG) ==            \
		    KPROG_X86_CMPOP_RHS_REGISTER)                        \
			__x86_l_rhs = X86_SIM_L_READ_REG_WIDTH_SHIFT(     \
				(SRC), __x86_l_width,                      \
				KPROG_X86_REG_LANE_AUX_SRC_SHIFT(          \
					__x86_l_aux));                     \
		else                                                      \
			__x86_l_rhs = x86_store_imm_value((IMM),          \
							  __x86_l_width);  \
		if (KPROG_X86_CMPOP_FLAG_KIND(OP_IS_TEST) ==             \
		    KPROG_X86_CMPOP_FLAGS_LOGIC)                          \
			X86_SIM_L_SET_LOGIC_FLAGS(                        \
				__x86_l_lhs & __x86_l_rhs, __x86_l_width); \
		else                                                      \
			X86_SIM_L_SET_SUB_FLAGS(__x86_l_lhs, __x86_l_rhs, \
				KPROG_X86_SBB_RESULT(__x86_l_lhs,          \
					__x86_l_rhs, 0), __x86_l_width);     \
	} while (0)

#define X86_SIM_L_EXEC_CMP_IMM_OP_AUX(OP, DST, FLAGS, AUX, IMM)             \
	X86_SIM_L_EXEC_CMP_REG_STEP((OP) == X86_OP_TEST_IMM, 0U, (DST),   \
				    (FLAGS), (AUX), 0U, (IMM))

#define X86_SIM_L_EXEC_CMP_IMM_OP(OP, DST, FLAGS, IMM)                      \
	X86_SIM_L_EXEC_CMP_IMM_OP_AUX((OP), (DST), (FLAGS), 0U, (IMM))

#define X86_SIM_L_EXEC_CMP_REG_OP_AUX(OP, DST, SRC, FLAGS, AUX)             \
	X86_SIM_L_EXEC_CMP_REG_STEP((OP) == X86_OP_TEST_REG, 1U, (DST),   \
				    (FLAGS), (AUX), (SRC), 0U)

#define X86_SIM_L_EXEC_CMP_REG_OP(OP, DST, SRC, FLAGS)                      \
	X86_SIM_L_EXEC_CMP_REG_OP_AUX((OP), (DST), (SRC), (FLAGS), 0U)

/* The `CMOV` / `CMOV_MEM` handler-composition contract selects the condition
 * (whole AUX word for the register form, the source-shift byte at bits 24..31
 * for the memory form), the write width, the memory access width, the
 * displacement, and the 64-bit-vs-narrow writeback arm. The two bodies route
 * through this one step so the register form (which samples the pointer and
 * provenance at 64 bits) and the memory form (which scalarizes at every width)
 * cannot drift: at 64 bits the memory form passes a scalar source tag, which
 * writes exactly the bits and tag the scalarizing partial-register write did. */
#define X86_SIM_L_EXEC_CMOV_STEP(RHS_IS_MEM, DST, SRC, FLAGS, AUX, IMM)     \
	do {                                                               \
		__u32 __x86_l_cc = (RHS_IS_MEM) ?                         \
			(__u32)KPROG_X86_CMOV_MEM_CONDITION(AUX) :        \
			(__u32)KPROG_X86_CMOV_CONDITION(AUX);             \
		if (X86_SIM_L_EVAL_CC(__x86_l_cc)) {                      \
			__u8 __x86_l_width = KPROG_X86_CMOV_WIDTH(FLAGS); \
			__u8 __x86_l_cmw = (RHS_IS_MEM) ?                 \
				KPROG_X86_CMOV_MEM_WIDTH(AUX, FLAGS) :    \
				__x86_l_width;                            \
			__u64 __x86_l_value = (RHS_IS_MEM) ?              \
				X86_SIM_L_READ_MEM_VALUE((SRC), (AUX),   \
					(IMM), __x86_l_cmw, 1) :          \
				X86_SIM_L_READ_REG(SRC);                  \
			__u8 __x86_l_wb = KPROG_X86_CMOV_WRITEBACK(       \
				__x86_l_width == X86_WIDTH_64);           \
			if (__x86_l_wb ==                                 \
			    KPROG_X86_CMOV_WRITEBACK_POINTER_TAG)         \
				X86_SIM_L_WRITE_REG_PTR_TAG((DST),        \
					(void *)(long)__x86_l_value,      \
					(RHS_IS_MEM) ? X86_SIM_TAG_SCALAR :\
						X86_SIM_L_REG_TAG(SRC));  \
			else                                              \
				X86_SIM_L_WRITE_REG_WIDTH((DST),          \
					__x86_l_value, __x86_l_width);    \
		}                                                         \
	} while (0)

#define X86_SIM_L_EXEC_CMOV(DST, SRC, FLAGS, AUX)                           \
	X86_SIM_L_EXEC_CMOV_STEP(0U, (DST), (SRC), (FLAGS), (AUX), 0ULL)

#define X86_SIM_L_EXEC_CMOV_MEM(DST, SRC, FLAGS, AUX, IMM)                  \
	X86_SIM_L_EXEC_CMOV_STEP(1U, (DST), (SRC), (FLAGS), (AUX), (IMM))

/* The `SETCC` / `SETCC_MEM` handler-composition contracts select the
 * destination byte lane, the condition code, the constant one-byte access
 * width, the base pointer and the store arm. The register form reads the
 * condition from the AUX payload byte (bits 0..7) and the lane from the
 * destination-shift byte (bits 8..15); the memory form reads the condition
 * from the source-shift byte (bits 24..31), forms a process-null base for the
 * absent register, and picks the stack helper from the register number. The
 * lane the register form selects is the contract's equality test, consumed by
 * the write helper's own `== 8` branch, so the C and the Lean step agree on
 * which byte receives the condition rather than restating the test. */
#define X86_SIM_L_EXEC_SETCC_STEP(DST, AUX)                                  \
	do {                                                                \
		__u8 __x86_l_sc_shift =                                     \
			KPROG_X86_REG_LANE_AUX_DST_SHIFT(AUX);              \
		__u8 __x86_l_sc_lane = KPROG_X86_SETCC_LANE(                \
			__x86_l_sc_shift);                                   \
		X86_SIM_L_WRITE_REG_WIDTH_SHIFT((DST),                      \
			X86_SIM_L_EVAL_CC(                                  \
				KPROG_X86_REG_LANE_AUX_PAYLOAD(AUX)),        \
			X86_WIDTH_8,                                        \
			__x86_l_sc_lane == KPROG_X86_SETCC_LANE_HIGH        \
				? 8U : 0U);                                 \
	} while (0)

#define X86_SIM_L_EXEC_SETCC(DST, AUX)                                       \
	X86_SIM_L_EXEC_SETCC_STEP((DST), (AUX))

#define X86_SIM_L_EXEC_SETCC_MEM(DST, AUX, IMM)                              \
	do {                                                               \
		__u8 __x86_l_scm_cc =                                      \
			KPROG_X86_SETCC_MEM_CONDITION(AUX);                 \
		__u64 __x86_l_scm_value = X86_SIM_L_EVAL_CC(               \
			__x86_l_scm_cc);                                   \
		__s64 __x86_l_scm_disp = X86_SIM_L_MEM_OFFSET((AUX),       \
			x86_simm(IMM));                                    \
		void *__x86_l_scm_base = KPROG_X86_SETCC_MEM_BASE(DST) ==  \
			KPROG_X86_SETCC_MEM_BASE_NULL                      \
				? (void *)0 : X86_SIM_L_READ_REG_PTR(DST);         \
		X86_SIM_L_BARRIER_VAR(__x86_l_scm_disp);                    \
		if (KPROG_X86_SETCC_MEM_ARM((DST) ==                       \
				KPROG_X86_SETCC_MEM_RSP_REG) ==              \
		    KPROG_X86_SETCC_MEM_ARM_STACK)                         \
			X86_SIM_L_STACK_WRITE(                              \
				(__s64)(long)__x86_l_scm_base +              \
					__x86_l_scm_disp,                    \
				KPROG_X86_SETCC_MEM_WIDTH_CODE,              \
				__x86_l_scm_value);                          \
		else                                                        \
			X86_SIM_L_STORE_ADDR(                               \
				(__u8 *)__x86_l_scm_base +                   \
					__x86_l_scm_disp,                    \
				KPROG_X86_SETCC_MEM_WIDTH_CODE,              \
				__x86_l_scm_value);                          \
	} while (0)

/* The two stack-transfer bodies compose the machine-checked
 * KPROG_X86_PUSH_* contract: the step direction, the width source, and the
 * absent-FLAGS default select when the stack pointer steps, which body
 * honours the FLAGS code, and what an absent code resolves to, while the
 * shared stack-step literal fixes the byte amount both step by; the bodies
 * and the Lean refinement share one stack-transfer composition rather than
 * two restated step sequences. */
#define X86_SIM_L_EXEC_PUSH_POP_STEP(IS_POP, DST, SRC, FLAGS)               \
	do {                                                                \
		__u8 __x86_l_pp_dir = KPROG_X86_PUSH_STEP_DIRECTION(IS_POP); \
		__u8 __x86_l_pp_wsrc = KPROG_X86_PUSH_WIDTH_SOURCE(IS_POP);  \
		__u8 __x86_l_pp_flags_width =                             \
			KPROG_X86_PUSH_FLAGS_WIDTH(                       \
				(FLAGS) == KPROG_X86_PUSH_WIDTH_ABSENT);  \
		__u8 __x86_l_pp_width =                                   \
			(__x86_l_pp_wsrc ==                               \
			 KPROG_X86_PUSH_WIDTH_HARDCODED_64) ?             \
				X86_WIDTH_64 :                            \
			(__x86_l_pp_flags_width ==                        \
			 KPROG_X86_PUSH_FLAGS_ABSENT) ?                   \
				X86_WIDTH_64 : (FLAGS);                   \
		__u64 __x86_l_pp_step =                                   \
			(__u64)KPROG_X86_PUSH_STACK_STEP;                 \
		if (__x86_l_pp_dir ==                                     \
		    KPROG_X86_PUSH_STEP_PRE_DECREMENT) {                  \
			__u64 __x86_l_pp_value = X86_SIM_L_READ_REG(SRC); \
			__x86_rsp.ptr =                                   \
				(__u8 *)__x86_rsp.ptr - __x86_l_pp_step;  \
			X86_SIM_L_STACK_WRITE(                            \
				(__s64)(long)__x86_rsp.ptr,               \
				__x86_l_pp_width, __x86_l_pp_value);      \
		} else {                                                  \
			__u64 __x86_l_pp_value = X86_SIM_L_STACK_READ(    \
				(__s64)(long)__x86_rsp.ptr,               \
				__x86_l_pp_width);                        \
			X86_SIM_L_WRITE_REG_WIDTH((DST),                  \
				__x86_l_pp_value, __x86_l_pp_width);      \
			__x86_rsp.ptr =                                   \
				(__u8 *)__x86_rsp.ptr + __x86_l_pp_step;  \
		}                                                         \
	} while (0)

#define X86_SIM_L_EXEC_PUSH(SRC)                                             \
	X86_SIM_L_EXEC_PUSH_POP_STEP(0U, X86_REG_NONE, (SRC), 0U)

#define X86_SIM_L_EXEC_POP(DST, FLAGS)                                       \
	X86_SIM_L_EXEC_PUSH_POP_STEP(1U, (DST), X86_REG_NONE, (FLAGS))

#define X86_SIM_L_EXEC(OP, DST, SRC, FLAGS, AUX, IMM)                       \
	do {                                                               \
		__u8 __x86_l_width = (FLAGS) ? (FLAGS) : X86_WIDTH_64;    \
		if ((OP) == X86_OP_NOP) {                                  \
			(void)0;                                           \
		} else if ((OP) == X86_OP_MOV_LOAD_MAP_PTR ||             \
			   (OP) == X86_OP_MOV_LOAD_HELPER_ID) {            \
			__u8 __x86_l_pw_tag =                             \
				KPROG_X86_PTR_WRITE_TAG(                  \
					(OP) == X86_OP_MOV_LOAD_MAP_PTR,   \
					(OP) == X86_OP_MOV_LOAD_HELPER_ID);\
			if (KPROG_X86_PTR_WRITE_IS_HELPER_ID(             \
				    __x86_l_pw_tag))                      \
				X86_SIM_L_WRITE_REG_WIDTH((DST), (IMM), \
							  X86_WIDTH_64);\
			X86_SIM_L_WRITE_REG_PTR_TAG((DST),                \
				(void *)(long)(IMM), __x86_l_pw_tag);     \
		} else if ((OP) == X86_OP_CALL_MEMCPY) {                  \
			X86_SIM_L_EXEC_CALL_MEMCPY((IMM));                \
		} else if ((OP) == X86_OP_CALL_MEMSET) {                  \
			X86_SIM_L_EXEC_CALL_MEMSET((IMM));                \
		} else if ((OP) == X86_OP_CALL_MEMCPY_REG) {              \
			X86_SIM_L_EXEC_CALL_MEMCPY_REG((IMM));            \
		} else if ((OP) == X86_OP_CALL_MEMSET_REG) {              \
			X86_SIM_L_EXEC_CALL_MEMSET_REG((IMM));            \
		} else if ((OP) == X86_OP_CALL_REG) {                     \
			X86_SIM_BPF_CALL_REG((SRC));                      \
		} else if ((OP) == X86_OP_MOV_IMM) {                       \
			X86_SIM_L_WRITE_REG_WIDTH_SHIFT((DST), (IMM),         \
				__x86_l_width,                                \
				KPROG_X86_REG_LANE_AUX_DST_SHIFT(AUX));        \
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
					X86_SIM_L_READ_REG_WIDTH_SHIFT(   \
						(SRC), __x86_l_width,        \
						KPROG_X86_REG_LANE_AUX_SRC_SHIFT(AUX));\
				X86_SIM_L_WRITE_REG_WIDTH_SHIFT((DST),   \
					__x86_l_value, __x86_l_width,      \
					KPROG_X86_REG_LANE_AUX_DST_SHIFT(AUX));\
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
		} else if ((OP) == X86_OP_ALU_MEM_REG) {                  \
			X86_SIM_L_EXEC_ALU_MEM_REG((DST), (SRC), (FLAGS), (AUX), (IMM));\
		} else if ((OP) == X86_OP_CMP_IMM ||                      \
			   (OP) == X86_OP_TEST_IMM) {                    \
			X86_SIM_L_EXEC_CMP_IMM_OP_AUX((OP), (DST), (FLAGS),\
				(AUX), (IMM));                                 \
		} else if ((OP) == X86_OP_CMP_REG ||                      \
			   (OP) == X86_OP_TEST_REG) {                    \
			X86_SIM_L_EXEC_CMP_REG_OP_AUX((OP), (DST), (SRC), \
				(FLAGS), (AUX));                              \
		} else if ((OP) == X86_OP_CMP_MEM_IMM ||                  \
			   (OP) == X86_OP_TEST_MEM_IMM ||                 \
			   (OP) == X86_OP_CMP_MEM_REG ||                  \
			   (OP) == X86_OP_TEST_MEM_REG) {                 \
			X86_SIM_L_EXEC_CMP_MEM((OP), (DST), (SRC), (FLAGS),\
					       (AUX), (IMM));             \
		} else if ((OP) == X86_OP_CMP_REG_MEM) {                  \
			X86_SIM_L_EXEC_CMP_REG_MEM((DST), (SRC), (FLAGS), \
						   (AUX), (IMM));        \
		} else if ((OP) == X86_OP_CMOV) {                         \
			X86_SIM_L_EXEC_CMOV((DST), (SRC), (FLAGS), (AUX));\
		} else if ((OP) == X86_OP_CMOV_MEM) {                    \
			X86_SIM_L_EXEC_CMOV_MEM((DST), (SRC), (FLAGS),    \
						(AUX), (IMM));            \
		} else if ((OP) == X86_OP_SETCC) {                        \
			X86_SIM_L_EXEC_SETCC_STEP((DST), (AUX));           \
		} else if ((OP) == X86_OP_SETCC_MEM) {                    \
			X86_SIM_L_EXEC_SETCC_MEM((DST), (AUX), (IMM));    \
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
			} else if ((OP) == X86_OP_BZHI) {                         \
				X86_SIM_L_EXEC_BZHI((DST), (SRC), (AUX), (FLAGS));\
			} else if ((OP) == X86_OP_BZHI_MEM) {                     \
				X86_SIM_L_EXEC_BZHI_MEM((DST), (SRC), (FLAGS), (AUX), (IMM));\
			} else if ((OP) == X86_OP_BT) {                           \
				X86_SIM_L_EXEC_BT((DST), (SRC), (FLAGS));          \
			} else if ((OP) == X86_OP_BT_IMM) {                       \
				X86_SIM_L_EXEC_BT_IMM((DST), (FLAGS), (IMM));      \
			} else if ((OP) == X86_OP_BT_MEM_IMM) {                   \
				X86_SIM_L_EXEC_BT_MEM_IMM((DST), (FLAGS), (AUX), (IMM));\
			} else if ((OP) == X86_OP_IMUL_IMM) {                     \
				X86_SIM_L_EXEC_IMUL_IMM((DST), (SRC), (FLAGS), (IMM));\
			} else if ((OP) == X86_OP_IMUL_MEM_IMM) {                 \
				X86_SIM_L_EXEC_IMUL_MEM_IMM((DST), (SRC), (FLAGS), (AUX), (IMM));\
			} else if ((OP) == X86_OP_MULX) {                         \
				X86_SIM_L_EXEC_MULX((DST), (SRC), (AUX), (FLAGS)); \
			} else if ((OP) == X86_OP_REP_MOVS) {                     \
				X86_SIM_L_EXEC_REP_MOVS((FLAGS), (IMM));          \
			} else if ((OP) == X86_OP_ANDN) {                         \
				X86_SIM_L_EXEC_ANDN((DST), (SRC), (AUX), (FLAGS)); \
			} else if ((OP) == X86_OP_ANDN_MEM) {                     \
				X86_SIM_L_EXEC_ANDN_MEM((DST), (SRC), (FLAGS), (AUX), (IMM));\
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
				__u64 __x86_l_q = 0xffffffffffffffffULL;     \
				__u64 __x86_l_rem = __x86_l_rdx;             \
				if (__x86_l_rdx == 0) {                      \
					__x86_l_q = __x86_l_rax / __x86_l_divisor;\
					__x86_l_rem = __x86_l_rax % __x86_l_divisor;\
				}                                             \
				X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, __x86_l_q, X86_WIDTH_64);\
				X86_SIM_L_WRITE_REG_WIDTH(X86_RDX, __x86_l_rem, X86_WIDTH_64);\
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
			X86_SIM_L_EXEC_PUSH((SRC));                       \
		} else if ((OP) == X86_OP_POP) {                          \
			X86_SIM_L_EXEC_POP((DST), (FLAGS));               \
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
