#ifndef X86_SIM_LOCAL_BPF_H
#define X86_SIM_LOCAL_BPF_H

#define KPROG_X86_ENTRY_SAVES_CALLEE 1

#ifndef __VMLINUX_H__
#include <linux/bpf.h>
#endif
#include <bpf_helpers.h>

#include "x86_sim.h"
#include "../../kinsn/module/include/native_lab_input.h"
#include "../formal/generated/abi_load.h"
#include "../formal/generated/ptr_add.h"
#include "../formal/generated/x86_full_condition.h"
#include "../formal/generated/x86_logic_flags.h"
#include "../formal/generated/x86_sub_flags.h"
#include "../formal/generated/x86_add_flags.h"
#include "../formal/generated/x86_aux_flags.h"
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
#include "../formal/generated/x86_branch_emit.h"
#include "../formal/generated/x86_mem_index.h"
#include "../formal/generated/x86_reg_presence.h"
#include "../formal/generated/x86_reg_dispatch.h"
#include "../formal/generated/x86_xchg.h"
#include "../formal/generated/x86_div.h"
#include "../formal/generated/x86_doubleshift_arm.h"
#include "../formal/generated/x86_popcnt_flags.h"
#include "../formal/generated/x86_movx_shape.h"
#include "../formal/generated/x86_mov_reg_arm.h"
#include "../formal/generated/x86_stack_arm.h"
#include "../formal/generated/x86_mulx_arm.h"
#include "../formal/generated/x86_bzhi_flags.h"
#include "../formal/generated/x86_write_width_arm.h"
#include "../formal/generated/x86_stack_write_lanes.h"
#include "../formal/generated/x86_alu_flag_arm.h"
#include "../formal/generated/x86_dispatch_family.h"
#include "../formal/generated/x86_dispatch_singleton.h"

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
#define X86_SIM_TAG_CODE 8U

/* Address arithmetic preserves the backing memory region's provenance. */
#define X86_SIM_L_MEMORY_TAG(TAG) \
    (((TAG)>=X86_SIM_TAG_ABI && (TAG)<=X86_SIM_TAG_STACK) || (TAG)==X86_SIM_TAG_MAP_VALUE)

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
#define X86_SIM_HELPER_bpf_probe_read 4ULL
#define X86_SIM_HELPER_bpf_ktime_get_ns 5ULL
#define X86_SIM_HELPER_bpf_trace_printk 6ULL
#define X86_SIM_HELPER_bpf_get_prandom_u32 7ULL
#define X86_SIM_HELPER_bpf_get_smp_processor_id 8ULL
#define X86_SIM_HELPER_bpf_skb_store_bytes 9ULL
#define X86_SIM_HELPER_bpf_l3_csum_replace 10ULL
#define X86_SIM_HELPER_bpf_l4_csum_replace 11ULL
#define X86_SIM_HELPER_bpf_tail_call 12ULL
#define X86_SIM_HELPER_bpf_get_current_pid_tgid 14ULL
#define X86_SIM_HELPER_bpf_get_current_uid_gid 15ULL
#define X86_SIM_HELPER_bpf_get_current_comm 16ULL
#define X86_SIM_HELPER_bpf_skb_get_tunnel_key 20ULL
#define X86_SIM_HELPER_bpf_skb_set_tunnel_key 21ULL
#define X86_SIM_HELPER_bpf_redirect 23ULL
#define X86_SIM_HELPER_bpf_perf_event_output 25ULL
#define X86_SIM_HELPER_bpf_skb_load_bytes 26ULL
#define X86_SIM_HELPER_bpf_get_stackid 27ULL
#define X86_SIM_HELPER_bpf_csum_diff 28ULL
#define X86_SIM_HELPER_bpf_skb_change_type 32ULL
#define X86_SIM_HELPER_bpf_get_current_task 35ULL
#define X86_SIM_HELPER_bpf_probe_write_user 36ULL
#define X86_SIM_HELPER_bpf_current_task_under_cgroup 37ULL
#define X86_SIM_HELPER_bpf_skb_change_tail 38ULL
#define X86_SIM_HELPER_bpf_skb_pull_data 39ULL
#define X86_SIM_HELPER_bpf_skb_change_head 43ULL
#define X86_SIM_HELPER_bpf_xdp_adjust_head 44ULL
#define X86_SIM_HELPER_bpf_probe_read_str 45ULL
#define X86_SIM_HELPER_bpf_get_socket_cookie 46ULL
#define X86_SIM_HELPER_bpf_skb_adjust_room 50ULL
#define X86_SIM_HELPER_bpf_xdp_adjust_meta 54ULL
#define X86_SIM_HELPER_bpf_override_return 58ULL
#define X86_SIM_HELPER_bpf_xdp_adjust_tail 65ULL
#define X86_SIM_HELPER_bpf_get_stack 67ULL
#define X86_SIM_HELPER_bpf_skb_load_bytes_relative 68ULL
#define X86_SIM_HELPER_bpf_fib_lookup 69ULL
#define X86_SIM_HELPER_bpf_get_current_cgroup_id 80ULL
#define X86_SIM_HELPER_bpf_sk_lookup_udp 85ULL
#define X86_SIM_HELPER_bpf_sk_release 86ULL
#define X86_SIM_HELPER_bpf_map_push_elem 87ULL
#define X86_SIM_HELPER_bpf_map_pop_elem 88ULL
#define X86_SIM_HELPER_bpf_sk_fullsock 95ULL
#define X86_SIM_HELPER_bpf_skc_lookup_tcp 99ULL
#define X86_SIM_HELPER_bpf_strtol 105ULL
#define X86_SIM_HELPER_bpf_send_signal 109ULL
#define X86_SIM_HELPER_bpf_probe_read_user 112ULL
#define X86_SIM_HELPER_bpf_probe_read_kernel 113ULL
#define X86_SIM_HELPER_bpf_probe_read_user_str 114ULL
#define X86_SIM_HELPER_bpf_probe_read_kernel_str 115ULL
#define X86_SIM_HELPER_bpf_jiffies64 118ULL
#define X86_SIM_HELPER_bpf_get_netns_cookie 122ULL
#define X86_SIM_HELPER_bpf_sk_assign 124ULL
#define X86_SIM_HELPER_bpf_ktime_get_boot_ns 125ULL
#define X86_SIM_HELPER_bpf_ringbuf_output 130ULL
#define X86_SIM_HELPER_bpf_copy_from_user 148ULL
#define X86_SIM_HELPER_bpf_redirect_neigh 152ULL
#define X86_SIM_HELPER_bpf_redirect_peer 155ULL
#define X86_SIM_HELPER_bpf_get_current_task_btf 158ULL
#define X86_SIM_HELPER_bpf_ktime_get_coarse_ns 160ULL
#define X86_SIM_HELPER_bpf_check_mtu 163ULL
#define X86_SIM_HELPER_bpf_get_func_ip 173ULL
#define X86_SIM_HELPER_bpf_get_attach_cookie 174ULL
#define X86_SIM_HELPER_bpf_task_pt_regs 175ULL
#define X86_SIM_HELPER_bpf_loop 181ULL
#define X86_SIM_HELPER_bpf_get_func_ret 184ULL
#define X86_SIM_HELPER_bpf_xdp_load_bytes 189ULL
#define X86_SIM_HELPER_bpf_ima_file_hash 193ULL

/* The helper-id -> helper-body dispatch contract. Included here, after the
 * `X86_SIM_HELPER_bpf_*` id defines above, so its `_Static_assert`s see the id
 * values and pin them to the generated ladder table. */
#include "../formal/generated/x86_helper_dispatch.h"

/* The width a body operates at when its decoded width field is absent (the
 * code 0): the same resolution the Lean `effective` def and the C contract
 * state. Bodies restated this fallback inline; they now share one kernel. */
#define X86_SIM_L_EFFECTIVE_WIDTH(WIDTH)                                    \
	x86_width_effective(WIDTH)

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

/*
 * The dispatch cell index a decoded register number names equals the hand-written
 * `X86_SIM_L_FOR_EACH_GPR` order: cell `n` is register number `X86_R<n>`, in
 * `rax rcx rdx rbx rsp rbp rsi rdi r8 .. r15` order. The generated
 * `x86_reg_dispatch.h` already pins each `X86_R<n>` to its number and
 * `KProgFormal/X86RegDispatch.lean` proves the same order, but the read path
 * resolves registers through the independent `X86_SIM_L_REG_VALUE` ternary
 * chain; these asserts bind the cell selector itself to the dispatched order,
 * so the two hand-written orders cannot drift apart from the generated table.
 */
_Static_assert(KPROG_X86_GPR_CELL(X86_RAX) == 0U,
	       "x86 gpr dispatch cell drift");
_Static_assert(KPROG_X86_GPR_CELL(X86_R8) == 8U,
	       "x86 gpr dispatch cell drift");
_Static_assert(KPROG_X86_GPR_CELL(X86_R15) == 15U,
	       "x86 gpr dispatch cell drift");

/* Native bytes and pointer representatives keep distinct storage. A named
 * layout lets the compiler scalarize each ghost cell before lowering loops. */
struct x86_sim_stack_value { void *pointer; __u8 tag; };
#ifdef X86_SIM_STACK_VALUE_WORDS
#define X86_SIM_L_SV_TAG_NAME_(I) __x86_stack_value_tag_##I
#define X86_SIM_L_SV_PTR_NAME_(I) __x86_stack_value_ptr_##I
#define X86_SIM_L_SV_TAG(I) X86_SIM_L_SV_TAG_NAME_(I)
#define X86_SIM_L_SV_PTR(I) X86_SIM_L_SV_PTR_NAME_(I)
#define X86_SIM_L_SV_DECLARE(I) __u8 X86_SIM_L_SV_TAG(I)=0; void *X86_SIM_L_SV_PTR(I)=0;
#define X86_SIM_L_DECLARE_STACK_VALUES() X86_SIM_STACK_VALUE_WORDS(X86_SIM_L_SV_DECLARE)
#define X86_SIM_L_SV_EACH(OP) X86_SIM_STACK_VALUE_WORDS(OP)
#else
#define X86_SIM_L_SV_TAG(I) __x86_stack_value_tags[(I)]
#define X86_SIM_L_SV_PTR(I) __x86_stack_value_ptrs[(I)]
#define X86_SIM_L_DECLARE_STACK_VALUES() \
    __u8 __x86_stack_value_tags[KPROG_X86_STACK_WORDS(X86_SIM_STACK_BYTES)]={}; \
    void *__x86_stack_value_ptrs[KPROG_X86_STACK_WORDS(X86_SIM_STACK_BYTES)]={}
#define X86_SIM_L_SV_EACH(OP) \
    _Pragma("unroll") \
    for (__u32 __x86_sv_i=0; __x86_sv_i<KPROG_X86_STACK_WORDS(X86_SIM_STACK_BYTES); ++__x86_sv_i) { OP(__x86_sv_i) }
#endif
/* An invalidated fact no longer needs a pointer representative. Clearing
 * both fields ends its compiler lifetime without touching native bytes. */
#define X86_SIM_L_SV_CLEAR_ONE(I) \
    do { X86_SIM_L_SV_TAG(I)=X86_SIM_TAG_SCALAR; X86_SIM_L_SV_PTR(I)=0; } while(0);
#define X86_SIM_L_STACK_VALUES_CLEAR() do { X86_SIM_L_SV_EACH(X86_SIM_L_SV_CLEAR_ONE) } while(0)
#define X86_SIM_L_SV_ERASE_ONE(I) \
    do { __u64 __x86_sv_start=(__u64)(I)*8U; \
         if (__x86_sv_index-__x86_sv_start<8U || __x86_sv_start-__x86_sv_index<__x86_sv_width) \
             X86_SIM_L_SV_CLEAR_ONE(I) } while(0);
#define X86_SIM_L_STACK_VALUES_ERASE(INDEX, WIDTH) \
    do { __u64 __x86_sv_index=(INDEX),__x86_sv_width=X86_SIM_L_EFFECTIVE_WIDTH(WIDTH); \
         X86_SIM_L_SV_EACH(X86_SIM_L_SV_ERASE_ONE) } while(0)
/* Helper lengths are byte counts, including zero, not u8 operand widths. */
#define X86_SIM_L_STACK_VALUES_ERASE_BYTES(INDEX, BYTES) \
    do { __u64 __x86_sv_index=(INDEX),__x86_sv_width=(BYTES); \
         if (__x86_sv_width) { X86_SIM_L_SV_EACH(X86_SIM_L_SV_ERASE_ONE) } } while(0)
#define X86_SIM_L_SV_SAVE_ONE(I) \
    do { if (__x86_sv_at==(__u64)(I)*8U) { \
        if (__x86_sv_tag==X86_SIM_TAG_STACK) X86_SIM_L_SV_PTR(I)=__x86_sv_pointer; \
        X86_SIM_L_SV_TAG(I)=__x86_sv_tag; } } while(0);
#define X86_SIM_L_STACK_VALUES_SAVE(INDEX, WIDTH, POINTER, TAG) \
    do { __u64 __x86_sv_at=(INDEX); __u8 __x86_sv_tag=(TAG); \
         if ((__s64)__x86_sv_at-(__s64)X86_SIM_STACK_BYTES>=X86_SIM_L_STACK_SP() && X86_SIM_L_EFFECTIVE_WIDTH(WIDTH)==X86_WIDTH_64 && __x86_sv_tag!=X86_SIM_TAG_SCALAR) { \
             void *__x86_sv_pointer=(POINTER); X86_SIM_L_SV_EACH(X86_SIM_L_SV_SAVE_ONE) } } while(0)
#define X86_SIM_L_SV_READ_ONE(I) \
    do { if (__x86_sv_at==(__u64)(I)*8U && X86_SIM_L_SV_TAG(I)!=X86_SIM_TAG_SCALAR) { \
         __x86_sv_result.tag=X86_SIM_L_SV_TAG(I); \
         if (__x86_sv_result.tag==X86_SIM_TAG_STACK) __x86_sv_result.pointer=X86_SIM_L_SV_PTR(I); } } while(0);
#define X86_SIM_L_STACK_VALUES_READ(INDEX, WIDTH) \
    ({ struct x86_sim_stack_value __x86_sv_result={}; __u64 __x86_sv_at=(INDEX); \
       if ((__s64)__x86_sv_at-(__s64)X86_SIM_STACK_BYTES>=X86_SIM_L_STACK_SP() && X86_SIM_L_EFFECTIVE_WIDTH(WIDTH)==X86_WIDTH_64) { X86_SIM_L_SV_EACH(X86_SIM_L_SV_READ_ONE) } \
       __x86_sv_result; })
/* Ordinary callees keep the caller's allocated frame. Ghost facts for older
 * deallocated slots disappear while their architectural bytes stay raw. */
#define X86_SIM_L_SV_BELOW_SP_ONE(I) \
    do { if ((__s64)((__u64)(I)*8U)-(__s64)X86_SIM_STACK_BYTES<__x86_sv_sp) \
             X86_SIM_L_SV_CLEAR_ONE(I) } while(0);
#define X86_SIM_L_STACK_VALUES_CALL_FRAME() \
    do { __s64 __x86_sv_sp=(__s64)(long)__x86_rsp.ptr; \
         X86_SIM_L_SV_EACH(X86_SIM_L_SV_BELOW_SP_ONE) } while(0)

#define X86_SIM_L_DECLARE_REG(REG, NAME)                                    \
	union x86_sim_gpr __x86_##NAME = { .ptr = (REG) == X86_RSP ? (void *)0 : (void *)X86_SIM_L_UNSPECIFIED() };              \
	__u8 __x86_##NAME##_tag = X86_SIM_TAG_SCALAR;

#define X86_SIM_L_STATE_REG_FIELD(REG, NAME)                                \
	union x86_sim_gpr NAME;                                             \
	__u8 NAME##_tag;

struct x86_sim_state {
	X86_SIM_L_FOR_EACH_GPR(X86_SIM_L_STATE_REG_FIELD)
	__u64 native_stack_base;
	__u8 cf;
	__u8 zf;
	__u8 sf;
	__u8 of;
	__u8 pf;
	__u8 af;
	__u64 xmm0_lo;
	__u64 xmm0_hi;
	__u64 ret_addr;
	__u32 call_depth;
	union x86_sim_stack_mem stack_mem;
	struct x86_sim_xdp_abi xdp_abi;
	struct x86_sim_skb_abi skb_abi;
	struct __sk_buff *skb_ctx;
	void *helper_ctx;
	__u8 is_xdp;
	void *helper_abi_base;
	__u8 abi_kind;
};

#ifdef X86_SIM_USE_STATE_STRUCT
#define X86_SIM_L_BIND_COMMON_STATE(STATE_PTR)                              \
	struct x86_sim_state *__x86_state = (STATE_PTR);                    \
	X86_SIM_L_DECLARE_STACK_VALUES();                                  \
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
#define __x86_native_stack_base (__x86_state->native_stack_base)
#define __x86_cf (__x86_state->cf)
#define __x86_zf (__x86_state->zf)
#define __x86_sf (__x86_state->sf)
#define __x86_of (__x86_state->of)
#define __x86_pf (__x86_state->pf)
#define __x86_af (__x86_state->af)
#define __x86_xmm0_lo (__x86_state->xmm0_lo)
#define __x86_xmm0_hi (__x86_state->xmm0_hi)
#define __x86_sim_ret_addr (__x86_state->ret_addr)
#define __x86_sim_call_depth (__x86_state->call_depth)
#define __x86_stack_mem (__x86_state->stack_mem)
#define __x86_sim_helper_ctx (__x86_state->helper_ctx)
#define __x86_sim_is_xdp (__x86_state->is_xdp)
#define __x86_sim_helper_abi_base (__x86_state->helper_abi_base)
#define __x86_sim_skb_ctx (__x86_state->skb_ctx)
#define __x86_sim_abi_kind (__x86_state->abi_kind)
#endif

#if defined(__bpf__) || defined(__BPF__)
#define X86_SIM_L_UNSPECIFIED() NATIVE_LAB_ENTRY_INPUT(NATIVE_LAB_INPUT_UNSPECIFIED)
#else
#define X86_SIM_L_UNSPECIFIED() 0ULL
#endif

#define X86_SIM_L_DECLARE_STATE()                                           \
	X86_SIM_L_DECLARE_STACK_VALUES();                                  \
	__u8 __x86_sim_is_xdp = 0;                 \
	void *__x86_sim_helper_ctx = (void *)0;                            \
	void *__x86_sim_helper_abi_base = (void *)0;                       \
	X86_SIM_L_FOR_EACH_GPR(X86_SIM_L_DECLARE_REG)                       \
	__u64 __x86_native_stack_base = 0;                                 \
	__u8 __x86_cf = X86_SIM_L_UNSPECIFIED() & 1;                                                  \
	__u8 __x86_zf = X86_SIM_L_UNSPECIFIED() & 1;                                                  \
	__u8 __x86_sf = X86_SIM_L_UNSPECIFIED() & 1;                                                  \
	__u8 __x86_of = X86_SIM_L_UNSPECIFIED() & 1;                                                  \
	__u8 __x86_pf = X86_SIM_L_UNSPECIFIED() & 1;                                                  \
	__u8 __x86_af = X86_SIM_L_UNSPECIFIED() & 1;                                                  \
	__u64 __x86_xmm0_lo = X86_SIM_L_UNSPECIFIED();                                            \
	__u64 __x86_xmm0_hi = X86_SIM_L_UNSPECIFIED();                                            \
	__u64 __x86_sim_ret_addr = 0

/* Width views share bytes; typed scalar spills retain verifier ranges. */
#ifdef X86_SIM_ENABLE_STACK
#define X86_SIM_L_DECLARE_STACK()                                           \
	volatile union {                                                            \
		__u8 b[X86_SIM_STACK_BYTES];                              \
		__u16 w[(X86_SIM_STACK_BYTES + 1U) / 2U];                 \
		__u32 d[(X86_SIM_STACK_BYTES + 3U) / 4U];                 \
		__u64 q[(X86_SIM_STACK_BYTES + 7U) / 8U];                 \
	} __x86_stack_mem
#else
#define X86_SIM_L_DECLARE_STACK()                                           \
	volatile union {                                                            \
		__u8 b[1];                                                \
		__u16 w[1];                                               \
		__u32 d[1];                                               \
		__u64 q[1];                                               \
	} __x86_stack_mem
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

/* Numeric entry address is distinct from the private arena's offset zero.
 * Both BPF and host use the existing explicit ABI2 entry input. Routing
 * oracles provide a zero-origin fixture; hardware observers provide their
 * actual source stack base. No production host value is guessed.
 */
#define X86_SIM_L_ENTRY_STACK_BASE() NATIVE_LAB_ENTRY_INPUT(NATIVE_LAB_INPUT_SP)

#define X86_SIM_ENTRY_XDP(CTX)                                               \
	struct x86_sim_xdp_abi __x86_sim_abi = {};                                                               \
	struct __sk_buff *__x86_sim_skb_ctx = (struct __sk_buff *)0;      \
	__u8 __x86_sim_abi_kind = KPROG_ABI_KIND_XDP;                    \
	X86_SIM_L_DECLARE_STATE();                                           \
	X86_SIM_L_DECLARE_STACK();                                           \
	__x86_native_stack_base = X86_SIM_L_ENTRY_STACK_BASE();             \
	__x86_sim_is_xdp = 1;                                        \
	__x86_sim_helper_ctx = (void *)(CTX);                            \
	__x86_sim_helper_abi_base = bpf_cast_to_kern_ctx((void *)(CTX));                        \
	__x86_rdi.ptr = __x86_sim_helper_abi_base;                                     \
	__x86_rdi_tag = X86_SIM_TAG_ABI

#define X86_SIM_ENTRY_SKB(CTX)                                               \
	struct x86_sim_skb_abi __x86_sim_abi = {};                 \
	struct __sk_buff *__x86_sim_skb_ctx = (CTX);                      \
	__u8 __x86_sim_abi_kind = KPROG_ABI_KIND_SKB;                    \
	X86_SIM_L_DECLARE_STATE();                                           \
	X86_SIM_L_DECLARE_STACK();                                           \
	__x86_native_stack_base = X86_SIM_L_ENTRY_STACK_BASE();             \
	__x86_sim_helper_ctx = (void *)(CTX);                            \
	__x86_sim_helper_abi_base = bpf_cast_to_kern_ctx((void *)(CTX));                        \
	__x86_rdi.ptr = __x86_sim_helper_abi_base;                                     \
	__x86_rdi_tag = X86_SIM_TAG_ABI

#define X86_SIM_ABI_KIND_RAW 2U
_Static_assert(X86_SIM_ABI_KIND_RAW != KPROG_ABI_KIND_XDP &&
               X86_SIM_ABI_KIND_RAW != KPROG_ABI_KIND_SKB,
               "raw context must not acquire packet ABI pointer tags");

#define X86_SIM_ENTRY_RAW(CTX)                                               \
	struct x86_sim_skb_abi __x86_sim_abi = {};                       \
	struct __sk_buff *__x86_sim_skb_ctx = (struct __sk_buff *)0;      \
	__u8 __x86_sim_abi_kind = X86_SIM_ABI_KIND_RAW;                                     \
	X86_SIM_L_DECLARE_STATE();                                       \
	X86_SIM_L_DECLARE_STACK();                                       \
	__x86_native_stack_base = X86_SIM_L_ENTRY_STACK_BASE();             \
	__x86_sim_helper_ctx = (void *)(CTX);                            \
	__x86_sim_helper_abi_base = (void *)(CTX);                        \
	__x86_rdi.ptr = (void *)(CTX);                                   \
	__x86_rdi_tag = X86_SIM_TAG_ABI

#define X86_SIM_L_READ_REG_CASE(REG, NAME)                                  \
	case REG:                                                          \
		__x86_l_value = __x86_##NAME.ptr;                         \
		break;

#define X86_SIM_L_READ_REG_PTR(REG)                                         \
	X86_SIM_L_REG_VALUE(REG)

/* Pointer addressing uses the private arena; scalar reads expose native bits. */
/* Keep pointer subtraction ahead of scalar-base addition: reassociation to
 * (native_base - arena_top) + pointer is verifier-illegal scalar-minus-fp. */
#define X86_SIM_L_STACK_NUMERIC_BITS(VALUE)                                 \
	({                                                                 \
		__u64 __x86_stack_delta = (__u64)(long)(VALUE) -             \
			(__u64)(long)X86_SIM_L_STACK_PTR(0);                 \
		X86_SIM_L_BARRIER_VAR(__x86_stack_delta);                   \
		__x86_stack_delta + __x86_native_stack_base;               \
	})

#define X86_SIM_L_READ_REG_WIDTH_SHIFT(REG, WIDTH, SRC_SHIFT)               \
	({                                                                 \
		__u8 __x86_rd_reg = (REG);                                  \
		__u8 __x86_rd_raw_width = (WIDTH);                         \
		__u8 __x86_rd_width =                                       \
			X86_SIM_L_EFFECTIVE_WIDTH(__x86_rd_raw_width);             \
		__u8 __x86_rd_shift = (SRC_SHIFT);                          \
		void *__x86_rd_ptr = X86_SIM_L_READ_REG_PTR(__x86_rd_reg); \
		__u64 __x86_rd_value = (__u64)(long)__x86_rd_ptr;           \
		if (__x86_rd_reg == X86_RSP)                              \
			__x86_rd_value += __x86_native_stack_base;          \
		else if (X86_SIM_L_REG_TAG(__x86_rd_reg) == X86_SIM_TAG_STACK) \
			__x86_rd_value = X86_SIM_L_STACK_NUMERIC_BITS(__x86_rd_ptr); \
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

#define X86_SIM_L_WRITE_REG_PTR_VALUE_CASE(REG, NAME)                       \
	case REG:                                                          \
		__x86_##NAME.ptr = __x86_wr_next_ptr;                    \
		__x86_##NAME##_tag = __x86_wr_next_tag;                  \
		break;

#define X86_SIM_L_WRITE_REG_PTR_TAG(REG, VALUE, TAG)                         \
	do { __s64 __x86_write_old_sp=(__s64)(long)__x86_rsp.ptr;                                                                \
		void *__x86_wr_next_ptr = (void *)(VALUE);                \
		__u8 __x86_wr_next_tag = (TAG);                           \
		switch (REG) {                                            \
		X86_SIM_L_FOR_EACH_GPR(X86_SIM_L_WRITE_REG_PTR_VALUE_CASE)\
		default:                                                  \
			break;                                            \
		}                                                         \
	if ((REG)==X86_RSP) X86_SIM_L_STACK_RELEASE(__x86_write_old_sp); \
	} while (0)

#define X86_SIM_L_WRITE_REG_PTR(REG, VALUE)                                 \
	X86_SIM_L_WRITE_REG_PTR_TAG((REG), (VALUE), X86_SIM_TAG_SCALAR)

/* One register read, one width update of that value and one register store:
 * the width ladder is spelled once rather than once per register. */
#define X86_SIM_L_WRITE_REG_WIDTH_SHIFT(REG, VALUE, WIDTH, DST_SHIFT)       \
	do { __s64 __x86_write_old_sp=(__s64)(long)__x86_rsp.ptr;                                                                \
		__u8 __x86_wr_raw_width = (WIDTH);                         \
		__u8 __x86_wr_width =                                       \
			X86_SIM_L_EFFECTIVE_WIDTH(__x86_wr_raw_width);             \
		__u8 __x86_wr_shift = (DST_SHIFT);                          \
		__u64 __x86_wr_next = (VALUE);                            \
		union x86_sim_gpr __x86_wr_cell = { .ptr = X86_SIM_L_REG_VALUE(REG) }; \
		__u8 __x86_wr_cell_tag = X86_SIM_L_REG_TAG(REG);           \
		if (KPROG_X86_WRITE_WIDTH_ARM(__x86_wr_width) ==            \
		    KPROG_X86_WRITE_WIDTH_ARM_B8) {                        \
			if ((REG) == X86_RSP) __x86_wr_cell.ptr = (void *)(long)((__u64)(long)__x86_wr_cell.ptr + __x86_native_stack_base); \
			else if (__x86_wr_cell_tag == X86_SIM_TAG_STACK)    \
				__x86_wr_cell.ptr = (void *)(long)X86_SIM_L_STACK_NUMERIC_BITS(__x86_wr_cell.ptr); \
			KPROG_X86_WRITE_REG8(__x86_wr_cell, __x86_wr_cell_tag, \
				__x86_wr_next, __x86_wr_shift, X86_SIM_TAG_SCALAR); \
		} else if (KPROG_X86_WRITE_WIDTH_ARM(__x86_wr_width) ==    \
			   KPROG_X86_WRITE_WIDTH_ARM_B16) {                \
			if ((REG) == X86_RSP) __x86_wr_cell.ptr = (void *)(long)((__u64)(long)__x86_wr_cell.ptr + __x86_native_stack_base); \
			else if (__x86_wr_cell_tag == X86_SIM_TAG_STACK)    \
				__x86_wr_cell.ptr = (void *)(long)X86_SIM_L_STACK_NUMERIC_BITS(__x86_wr_cell.ptr); \
			KPROG_X86_WRITE_REG16(__x86_wr_cell, __x86_wr_cell_tag, \
				__x86_wr_next, X86_SIM_TAG_SCALAR);         \
		} else if (KPROG_X86_WRITE_WIDTH_ARM(__x86_wr_width) ==    \
			   KPROG_X86_WRITE_WIDTH_ARM_B32) {                \
			KPROG_X86_WRITE_REG32(__x86_wr_cell, __x86_wr_cell_tag, \
				__x86_wr_next, X86_SIM_TAG_SCALAR);         \
		} else {                                                  \
			KPROG_X86_WRITE_REG64(__x86_wr_cell, __x86_wr_cell_tag, \
				__x86_wr_next, X86_SIM_TAG_SCALAR);         \
		}                                                         \
		if ((REG) == X86_RSP) __x86_wr_cell.ptr = (void *)(long)((__u64)(long)__x86_wr_cell.ptr - __x86_native_stack_base); \
		void *__x86_wr_next_ptr = __x86_wr_cell.ptr;              \
		__u8 __x86_wr_next_tag = __x86_wr_cell_tag;               \
		switch (REG) {                                            \
		X86_SIM_L_FOR_EACH_GPR(X86_SIM_L_WRITE_REG_PTR_VALUE_CASE)\
		default:                                                  \
			break;                                            \
		}                                                         \
	if ((REG)==X86_RSP) X86_SIM_L_STACK_RELEASE(__x86_write_old_sp); \
	} while (0)

#define X86_SIM_L_WRITE_REG_WIDTH(REG, VALUE, WIDTH)                        \
	X86_SIM_L_WRITE_REG_WIDTH_SHIFT((REG), (VALUE), (WIDTH), 0U)

/* The public sim helper (AUX, DISP) resolves the index register presence
 * through the machine-checked KPROG_X86_MEM_INDEX_PRESENT bridge and the value
 * through the sim's own register read, then delegates the arithmetic to the
 * machine-checked KPROG_X86_MEM_OFFSET contract, so the sim and the Lean
 * refinements share one presence selector and one offset implementation rather
 * than restating them inline. */
#define X86_SIM_L_MEM_OFFSET(AUX, DISP)                                     \
	X86_SIM_L_MEM_OFFSET_INDEXED((AUX), (DISP),                         \
		(KPROG_X86_MEM_INDEX_PRESENT(X86_MEM_AUX_INDEX(AUX))            \
			  ? X86_SIM_L_READ_REG(X86_MEM_AUX_INDEX(AUX))          \
			  : 0),                                                 \
		KPROG_X86_MEM_INDEX_PRESENT(X86_MEM_AUX_INDEX(AUX)))

/* INDEX_VALUE is already read and HAS_INDEX is an integer presence flag; the
 * generated contract decodes the scale from AUX itself. */
#define X86_SIM_L_MEM_OFFSET_INDEXED(AUX, DISP, INDEX_VALUE, HAS_INDEX)     \
	((__s64)KPROG_X86_MEM_OFFSET((AUX), (DISP), (INDEX_VALUE),         \
				     (HAS_INDEX)))

#define X86_SIM_L_BARRIER_VAR(VAR) asm volatile("" : "+r"(VAR))

#define X86_SIM_L_STACK_INDEX(OFF)                                         \
	KPROG_X86_STACK_INDEX(OFF, X86_SIM_STACK_BYTES)

#define X86_SIM_L_PRIVATE_BYTE_STORE(ADDR, WIDTH, VALUE)                  \
	do {                                                               \
			volatile __u8 *__x86_stw_bytes = (ADDR); \
			__u8 __x86_stw_width =                            \
				X86_SIM_L_EFFECTIVE_WIDTH(WIDTH);         \
			__u64 __x86_stw_narrowed = (VALUE) &              \
				x86_width_mask(__x86_stw_width);          \
			__x86_stw_bytes[0] =              \
				KPROG_X86_STACK_BYTE(__x86_stw_narrowed, 0);\
			if (KPROG_X86_STACK_WRITE_LANE_ACTIVE(__x86_stw_width, 1))\
				__x86_stw_bytes[1] =  \
					KPROG_X86_STACK_BYTE(             \
						__x86_stw_narrowed, 1);   \
			if (KPROG_X86_STACK_WRITE_LANE_ACTIVE(__x86_stw_width, 2))\
				__x86_stw_bytes[2] =  \
					KPROG_X86_STACK_BYTE(             \
						__x86_stw_narrowed, 2);   \
			if (KPROG_X86_STACK_WRITE_LANE_ACTIVE(__x86_stw_width, 3))\
				__x86_stw_bytes[3] =  \
					KPROG_X86_STACK_BYTE(             \
						__x86_stw_narrowed, 3);   \
			if (KPROG_X86_STACK_WRITE_LANE_ACTIVE(__x86_stw_width, 4))\
				__x86_stw_bytes[4] =  \
					KPROG_X86_STACK_BYTE(             \
						__x86_stw_narrowed, 4);   \
			if (KPROG_X86_STACK_WRITE_LANE_ACTIVE(__x86_stw_width, 5))\
				__x86_stw_bytes[5] =  \
					KPROG_X86_STACK_BYTE(             \
						__x86_stw_narrowed, 5);   \
			if (KPROG_X86_STACK_WRITE_LANE_ACTIVE(__x86_stw_width, 6))\
				__x86_stw_bytes[6] =  \
					KPROG_X86_STACK_BYTE(             \
						__x86_stw_narrowed, 6);   \
			if (KPROG_X86_STACK_WRITE_LANE_ACTIVE(__x86_stw_width, 7))\
				__x86_stw_bytes[7] =  \
					KPROG_X86_STACK_BYTE(             \
						__x86_stw_narrowed, 7);   \
	} while (0)

#define X86_SIM_L_STACK_WRITE_RAW(OFF, WIDTH, VALUE) \
    do { __s64 __x86_loss_off=(OFF); __u8 __x86_loss_width=X86_SIM_L_EFFECTIVE_WIDTH(WIDTH); \
      __u64 __x86_loss_value=(VALUE); \
      X86_SIM_L_STACK_WRITE_OWNED(__x86_loss_off,__x86_loss_width,__x86_loss_value); \
      if (__x86_loss_off<X86_SIM_L_STACK_SP()) { _Pragma("unroll") \
        for (__u32 __x86_loss_i=0; __x86_loss_i<8U; ++__x86_loss_i) \
          if (__x86_loss_i<__x86_loss_width && __x86_loss_off+__x86_loss_i<X86_SIM_L_STACK_SP()) \
            X86_SIM_L_STACK_WRITE_OWNED(__x86_loss_off+__x86_loss_i,1U,X86_SIM_L_UNSPECIFIED()); \
      } \
    } while(0)

#define X86_SIM_L_STACK_WRITE_OWNED(OFF, WIDTH, VALUE)                            \
	do {                                                               \
		__u64 __x86_stw_index = X86_SIM_L_STACK_INDEX(OFF);       \
		if (KPROG_X86_STACK_ARM(                                  \
			    (X86_SIM_L_EFFECTIVE_WIDTH(WIDTH)) ==         \
				    X86_WIDTH_64,                         \
			    KPROG_X86_STACK_WORD_ALIGNED(                 \
				    __x86_stw_index))) {                  \
			__x86_stack_mem.q                               \
				[KPROG_X86_STACK_WORD_INDEX(             \
					__x86_stw_index)] = (VALUE);     \
		} else if (X86_SIM_L_EFFECTIVE_WIDTH(WIDTH) == X86_WIDTH_32 && \
			   (__x86_stw_index & 3U) == 0) {                    \
			__x86_stack_mem.d[__x86_stw_index / 4U] = (VALUE);    \
		} else if (X86_SIM_L_EFFECTIVE_WIDTH(WIDTH) == X86_WIDTH_16 && \
			   (__x86_stw_index & 1U) == 0) {                    \
			__x86_stack_mem.w[__x86_stw_index / 2U] = (VALUE);    \
		} else {                                                  \
			X86_SIM_L_PRIVATE_BYTE_STORE(                    \
				&__x86_stack_mem.b[__x86_stw_index],       \
				(WIDTH), (VALUE));                        \
		}                                                         \
	} while (0)

#define X86_SIM_L_STACK_WRITE(OFF, WIDTH, VALUE) \
    do { X86_SIM_L_STACK_VALUES_ERASE(X86_SIM_L_STACK_INDEX(OFF),(WIDTH)); \
         X86_SIM_L_STACK_WRITE_RAW((OFF),(WIDTH),(VALUE)); } while(0)

/* Bytes below the current native SP have an independent environment value.
 * Releasing an allocated byte also releases its value and pointer provenance. */
#ifndef X86_SIM_L_STACK_SP
#define X86_SIM_L_STACK_SP() ((__s64)(long)__x86_rsp.ptr)
#endif
#define X86_SIM_L_STACK_RELEASE(OLD) \
    do { __s64 __x86_release_old=(OLD), __x86_release_new=X86_SIM_L_STACK_SP(); \
      if (__x86_release_new>__x86_release_old) { \
        _Pragma("unroll") \
        for (__u32 __x86_release_i=0; __x86_release_i<X86_SIM_STACK_BYTES; ++__x86_release_i) { \
          __s64 __x86_release_off=(__s64)__x86_release_i-(__s64)X86_SIM_STACK_BYTES; \
          if (__x86_release_off>=__x86_release_old && __x86_release_off<__x86_release_new) \
            __x86_stack_mem.b[__x86_release_i]=(__u8)X86_SIM_L_UNSPECIFIED(); \
        } \
        X86_SIM_L_STACK_VALUES_CALL_FRAME(); \
      } \
    } while(0)

#define X86_SIM_L_STACK_READ(OFF, WIDTH) \
    ({ __u64 __x86_observed=X86_SIM_L_STACK_READ_OWNED((OFF),(WIDTH)); \
       if ((__s64)(OFF)<X86_SIM_L_STACK_SP()) __x86_observed=x86_apply_width(X86_SIM_L_UNSPECIFIED(),X86_SIM_L_EFFECTIVE_WIDTH(WIDTH)); \
       __x86_observed; })

#define X86_SIM_L_STACK_READ_OWNED(OFF, WIDTH)                                    \
	({                                                                 \
		__u64 __x86_str_index = X86_SIM_L_STACK_INDEX(OFF);       \
		__u64 __x86_str_value;                                   \
		if (KPROG_X86_STACK_ARM(                                  \
			    (X86_SIM_L_EFFECTIVE_WIDTH(WIDTH)) ==         \
				    X86_WIDTH_64,                         \
			    KPROG_X86_STACK_WORD_ALIGNED(                 \
				    __x86_str_index))) {                  \
			__x86_str_value = __x86_stack_mem.q               \
				[KPROG_X86_STACK_WORD_INDEX(             \
					__x86_str_index)];               \
		} else if (X86_SIM_L_EFFECTIVE_WIDTH(WIDTH) == X86_WIDTH_32 && \
			   (__x86_str_index & 3U) == 0) {                    \
			__x86_str_value = __x86_stack_mem.d[__x86_str_index / 4U]; \
		} else if (X86_SIM_L_EFFECTIVE_WIDTH(WIDTH) == X86_WIDTH_16 && \
			   (__x86_str_index & 1U) == 0) {                    \
			__x86_str_value = __x86_stack_mem.w[__x86_str_index / 2U]; \
		} else {                                                  \
			volatile __u8 *__x86_str_bytes = __x86_stack_mem.b; \
			__u8 __x86_str_width =                            \
				X86_SIM_L_EFFECTIVE_WIDTH(WIDTH);         \
			__x86_str_value =                                 \
				__x86_str_bytes[__x86_str_index];       \
			if (KPROG_X86_STACK_WRITE_LANE_ACTIVE(__x86_str_width, 1))\
				__x86_str_value |=                        \
					KPROG_X86_STACK_ASSEMBLE(         \
						__x86_str_bytes[__x86_str_index + 1], 1);\
			if (KPROG_X86_STACK_WRITE_LANE_ACTIVE(__x86_str_width, 2))\
				__x86_str_value |=                        \
					KPROG_X86_STACK_ASSEMBLE(         \
						__x86_str_bytes[__x86_str_index + 2], 2);\
			if (KPROG_X86_STACK_WRITE_LANE_ACTIVE(__x86_str_width, 3))\
				__x86_str_value |=                        \
					KPROG_X86_STACK_ASSEMBLE(         \
						__x86_str_bytes[__x86_str_index + 3], 3);\
			if (KPROG_X86_STACK_WRITE_LANE_ACTIVE(__x86_str_width, 4))\
				__x86_str_value |=                        \
					KPROG_X86_STACK_ASSEMBLE(         \
						__x86_str_bytes[__x86_str_index + 4], 4);\
			if (KPROG_X86_STACK_WRITE_LANE_ACTIVE(__x86_str_width, 5))\
				__x86_str_value |=                        \
					KPROG_X86_STACK_ASSEMBLE(         \
						__x86_str_bytes[__x86_str_index + 5], 5);\
			if (KPROG_X86_STACK_WRITE_LANE_ACTIVE(__x86_str_width, 6))\
				__x86_str_value |=                        \
					KPROG_X86_STACK_ASSEMBLE(         \
						__x86_str_bytes[__x86_str_index + 6], 6);\
			if (KPROG_X86_STACK_WRITE_LANE_ACTIVE(__x86_str_width, 7))\
				__x86_str_value |=                        \
					KPROG_X86_STACK_ASSEMBLE(         \
						__x86_str_bytes[__x86_str_index + 7], 7);\
		}                                                         \
		__x86_str_value;                                          \
	})

#define X86_SIM_L_STACK_PTR(OFF)                                           \
	((void *)KPROG_PTR_ADD64_BITS(&__x86_stack_mem.b[0], X86_SIM_L_STACK_INDEX((OFF))))

#define X86_SIM_L_HELPER_ARG_PTR(REG)                                      \
	X86_SIM_L_READ_REG_PTR(REG)

/* Helpers consume the original kernel context, while native context loads
 * use the expanded pointer-width ABI. Translate only its exact base. */
#define X86_SIM_L_HELPER_CTX_PTR(REG)                                      \
	KPROG_ABI_HELPER_CONTEXT(X86_SIM_L_READ_REG_PTR(REG),                \
		__x86_sim_helper_abi_base, __x86_sim_helper_ctx)


#define X86_SIM_L_LOAD_ADDR(ADDR, WIDTH) KPROG_X86_MEM_LOAD((ADDR), (WIDTH))

#ifndef X86_SIM_L_NATIVE_DATA_LOAD
#define X86_SIM_L_NATIVE_DATA_LOAD(BASE, OFF, WIDTH) \
	X86_SIM_L_LOAD_ADDR(KPROG_PTR_ADD64_BITS((BASE), (OFF)), (WIDTH))
#endif

#define X86_SIM_L_STACK_ALIAS_OFFSET(ADDR) \
    ({ __u64 __x86_alias_delta=(__u64)(long)(ADDR)-(__u64)(long)X86_SIM_L_STACK_PTR(0); \
       X86_SIM_L_BARRIER_VAR(__x86_alias_delta); (__s64)__x86_alias_delta; })
#define X86_SIM_L_LOAD_ADDR_TAGGED(ADDR, WIDTH, TAG) \
    ({ __u64 __x86_alias_observed=X86_SIM_L_LOAD_ADDR((ADDR),(WIDTH)); \
       if ((TAG)==X86_SIM_TAG_STACK && X86_SIM_L_STACK_ALIAS_OFFSET(ADDR)<X86_SIM_L_STACK_SP()) \
         __x86_alias_observed=x86_apply_width(X86_SIM_L_UNSPECIFIED(),X86_SIM_L_EFFECTIVE_WIDTH(WIDTH)); \
       __x86_alias_observed; })
#define X86_SIM_L_NATIVE_DATA_LOAD_TAGGED(BASE, OFF, WIDTH, TAG) \
    ({ __u64 __x86_alias_observed=X86_SIM_L_NATIVE_DATA_LOAD((BASE),(OFF),(WIDTH)); \
       if ((TAG)==X86_SIM_TAG_STACK && X86_SIM_L_STACK_ALIAS_OFFSET(KPROG_PTR_ADD64_BITS((BASE),(OFF)))<X86_SIM_L_STACK_SP()) \
         __x86_alias_observed=x86_apply_width(X86_SIM_L_UNSPECIFIED(),X86_SIM_L_EFFECTIVE_WIDTH(WIDTH)); \
       __x86_alias_observed; })

#if defined(__BPF__) || defined(__bpf__)
#define X86_SIM_L_LOAD_PTR_ADDR(ADDR) (*(void * volatile *)(ADDR))
#else
/* x86 permits unaligned pointer-width reads; the host C type must too. */
typedef void *x86_sim_unaligned_ptr __attribute__((aligned(1), may_alias));
#define X86_SIM_L_LOAD_PTR_ADDR(ADDR) (*(x86_sim_unaligned_ptr volatile *)(ADDR))
#endif

#define X86_SIM_L_STORE_ADDR(ADDR, WIDTH, VALUE) \
    do { X86_SIM_L_STACK_VALUES_CLEAR(); \
         KPROG_X86_MEM_STORE((ADDR), (WIDTH), (VALUE)); } while (0)
#define X86_SIM_L_STORE_ADDR_TAGGED(ADDR, WIDTH, VALUE, TAG) \
    do { \
        void *__x86_st_addr=(ADDR); __u8 __x86_st_width=(WIDTH),__x86_st_tag=(TAG); \
        __u64 __x86_st_value=(VALUE); \
        if (__x86_st_tag==X86_SIM_TAG_STACK) \
            X86_SIM_L_STACK_VALUES_ERASE((__u64)(long)__x86_st_addr-(__u64)(long)&__x86_stack_mem.b[0],__x86_st_width); \
        else if (__x86_st_tag==X86_SIM_TAG_SCALAR) X86_SIM_L_STACK_VALUES_CLEAR(); \
        KPROG_X86_MEM_STORE(__x86_st_addr,__x86_st_width,__x86_st_value); \
        if (__x86_st_tag==X86_SIM_TAG_STACK) { \
            __s64 __x86_st_off=X86_SIM_L_STACK_ALIAS_OFFSET(__x86_st_addr); \
            if (__x86_st_off<X86_SIM_L_STACK_SP()) { _Pragma("unroll") \
                for (__u32 __x86_st_i=0; __x86_st_i<8U; ++__x86_st_i) \
                    if (__x86_st_i<X86_SIM_L_EFFECTIVE_WIDTH(__x86_st_width) && \
                        __x86_st_off+__x86_st_i<X86_SIM_L_STACK_SP()) \
                        ((volatile __u8 *)__x86_st_addr)[__x86_st_i]=(__u8)X86_SIM_L_UNSPECIFIED(); \
            } \
        } \
    } while (0)

#define X86_SIM_L_SET_LOGIC_FLAGS(RESULT, WIDTH)                            \
	do {                                                               \
		__u8 __x86_fl_width = X86_SIM_L_EFFECTIVE_WIDTH(WIDTH);   \
		__u64 __x86_fl_value = x86_apply_width((RESULT),          \
						      __x86_fl_width);    \
		__u32 __x86_fl_bits = x86_width_bits(__x86_fl_width);     \
		KPROG_X86_SET_LOGIC_FLAGS(__x86_cf, __x86_zf, __x86_sf,  \
			__x86_of, __x86_fl_value == 0,                     \
			(__x86_fl_value >> (__x86_fl_bits - 1)) & 1);       \
		__x86_pf = KPROG_X86_PARITY(__x86_fl_value);             \
	} while (0)

#define X86_SIM_L_SET_POPCNT_FLAGS(SRC, WIDTH)                              \
	do {                                                               \
		__u8 __x86_pc_width = X86_SIM_L_EFFECTIVE_WIDTH(WIDTH);   \
		KPROG_X86_SET_POPCNT_FLAGS(                               \
			__x86_cf, __x86_zf, __x86_sf, __x86_of,           \
			x86_apply_width((SRC), __x86_pc_width) == 0);     \
		__x86_pf = 0;                                           \
		__x86_af = 0;                                           \
	} while (0)

/* BZHI sets CF from the byte count, ZF/SF from the result and clears OF. */
#define X86_SIM_L_SET_BZHI_FLAGS(COUNT, BITS, RESULT)                       \
	do {                                                               \
		KPROG_X86_SET_BZHI_FLAGS(                                 \
			__x86_cf, __x86_zf, __x86_sf, __x86_of,           \
			(COUNT) >= (BITS), (RESULT) == 0,                  \
			((RESULT) >> ((BITS) - 1U)) & 1U);                \
		__x86_pf = X86_SIM_L_UNSPECIFIED() & 1;                  \
		__x86_af = X86_SIM_L_UNSPECIFIED() & 1;                  \
	} while (0)

#define X86_SIM_L_SET_SUB_FLAGS(LHS, RHS, RESULT, WIDTH)                    \
	do {                                                               \
		__u8 __x86_sub_width = X86_SIM_L_EFFECTIVE_WIDTH(WIDTH);  \
		__u64 __x86_sub_mask = x86_width_mask(__x86_sub_width);   \
		__u64 __x86_sub_a = (LHS) & __x86_sub_mask;               \
		__u64 __x86_sub_b = (RHS) & __x86_sub_mask;               \
		__u64 __x86_sub_r = (RESULT) & __x86_sub_mask;            \
		__u64 __x86_sub_sign = x86_width_sign_mask(__x86_sub_width);\
		KPROG_X86_SET_SUB_FLAGS(__x86_cf, __x86_zf, __x86_sf,   \
			__x86_of, __x86_sub_a, __x86_sub_b, __x86_sub_r, \
			__x86_sub_sign);                                    \
		__x86_pf = KPROG_X86_PARITY(__x86_sub_r);              \
		__x86_af = KPROG_X86_AUX_CARRY(__x86_sub_a,            \
			__x86_sub_b, __x86_sub_r);                      \
	} while (0)

#define X86_SIM_L_SET_ADD_FLAGS(LHS, RHS, RESULT, WIDTH)                    \
	do {                                                               \
		__u8 __x86_add_width = X86_SIM_L_EFFECTIVE_WIDTH(WIDTH);  \
		__u64 __x86_add_mask = x86_width_mask(__x86_add_width);   \
		__u64 __x86_add_a = (LHS) & __x86_add_mask;               \
		__u64 __x86_add_b = (RHS) & __x86_add_mask;               \
		__u64 __x86_add_r = (RESULT) & __x86_add_mask;            \
		__u64 __x86_add_sign = x86_width_sign_mask(__x86_add_width);\
		KPROG_X86_SET_ADD_FLAGS(__x86_cf, __x86_zf, __x86_sf,   \
			__x86_of, __x86_add_a, __x86_add_b, __x86_add_r, \
			__x86_add_sign);                                    \
		__x86_pf = KPROG_X86_PARITY(__x86_add_r);              \
		__x86_af = KPROG_X86_AUX_CARRY(__x86_add_a,            \
			__x86_add_b, __x86_add_r);                      \
	} while (0)

#define X86_SIM_L_SET_ADC_FLAGS(LHS, RHS, CARRY, RESULT, WIDTH)             \
	do {                                                               \
		__u8 __x86_adc_width = X86_SIM_L_EFFECTIVE_WIDTH(WIDTH);  \
		__u64 __x86_adc_mask = x86_width_mask(__x86_adc_width);   \
		__u64 __x86_adc_a = (LHS) & __x86_adc_mask;               \
		__u64 __x86_adc_b = (RHS) & __x86_adc_mask;               \
		__u64 __x86_adc_r = (RESULT) & __x86_adc_mask;            \
		__u64 __x86_adc_sign = x86_width_sign_mask(__x86_adc_width);\
		KPROG_X86_SET_ADC_FLAGS(__x86_cf, __x86_zf, __x86_sf,   \
			__x86_of, __x86_adc_a, __x86_adc_b, __x86_adc_r, \
			__x86_adc_sign, (CARRY));                           \
		__x86_pf = KPROG_X86_PARITY(__x86_adc_r);              \
		__x86_af = KPROG_X86_AUX_CARRY(__x86_adc_a,            \
			__x86_adc_b, __x86_adc_r);                      \
	} while (0)

#define X86_SIM_L_SET_SBB_FLAGS(LHS, RHS, BORROW, RESULT, WIDTH)            \
	do {                                                               \
		__u8 __x86_sbb_width = X86_SIM_L_EFFECTIVE_WIDTH(WIDTH);  \
		__u64 __x86_sbb_mask = x86_width_mask(__x86_sbb_width);   \
		__u64 __x86_sbb_a = (LHS) & __x86_sbb_mask;               \
		__u64 __x86_sbb_b = (RHS) & __x86_sbb_mask;               \
		__u64 __x86_sbb_r = (RESULT) & __x86_sbb_mask;            \
		__u64 __x86_sbb_sign = x86_width_sign_mask(__x86_sbb_width);\
		KPROG_X86_SET_SBB_FLAGS(__x86_cf, __x86_zf, __x86_sf,   \
			__x86_of, __x86_sbb_a, __x86_sbb_b, __x86_sbb_r,  \
			__x86_sbb_sign, (BORROW));                          \
		__x86_pf = KPROG_X86_PARITY(__x86_sbb_r);              \
		__x86_af = KPROG_X86_AUX_CARRY(__x86_sbb_a,            \
			__x86_sbb_b, __x86_sbb_r);                      \
	} while (0)

#define X86_SIM_L_SET_IMUL_FLAGS(LHS, RHS, WIDTH)                           \
	do {                                                               \
		__u8 __x86_imul_width = X86_SIM_L_EFFECTIVE_WIDTH(WIDTH); \
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
		__u8 __x86_sh_width =                                       \
			X86_SIM_L_EFFECTIVE_WIDTH(__x86_sh_raw_width);             \
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
		if (__x86_sh_count != 0 &&                              \
		    (__x86_sh_alu == X86_ALU_SHL ||                      \
		     __x86_sh_alu == X86_ALU_SHR ||                      \
		     __x86_sh_alu == X86_ALU_SAR))                       \
			__x86_pf = KPROG_X86_PARITY(__x86_sh_r);          \
	} while (0)

#define X86_SIM_L_SET_ALU_FLAGS(LHS, RHS, RESULT, ALU, WIDTH)               \
	do {                                                               \
		__u8 __x86_l_old_cf = __x86_cf;                          \
		switch (KPROG_X86_ALU_FLAG_ARM((ALU))) {                 \
		case KPROG_X86_ALU_FLAG_ARM_ADD:                         \
			X86_SIM_L_SET_ADD_FLAGS((LHS), (RHS), (RESULT), (WIDTH));\
			break;                                             \
		case KPROG_X86_ALU_FLAG_ARM_INC:                         \
			X86_SIM_L_SET_ADD_FLAGS((LHS), 1, (RESULT), (WIDTH));\
			__x86_cf = __x86_l_old_cf;                         \
			break;                                             \
		case KPROG_X86_ALU_FLAG_ARM_DEC:                         \
			X86_SIM_L_SET_SUB_FLAGS((LHS), 1, (RESULT), (WIDTH));\
			__x86_cf = __x86_l_old_cf;                         \
			break;                                             \
		case KPROG_X86_ALU_FLAG_ARM_SUB:                         \
			X86_SIM_L_SET_SUB_FLAGS((LHS), (RHS), (RESULT), (WIDTH));\
			break;                                             \
		case KPROG_X86_ALU_FLAG_ARM_SBB:                         \
			X86_SIM_L_SET_SBB_FLAGS((LHS), (RHS), 0, (RESULT), (WIDTH));\
			break;                                             \
		case KPROG_X86_ALU_FLAG_ARM_NEG:                         \
			X86_SIM_L_SET_SUB_FLAGS(0, (LHS), (RESULT), (WIDTH));\
			break;                                             \
		case KPROG_X86_ALU_FLAG_ARM_NOT:                         \
			KPROG_X86_PRESERVE_FLAGS();                       \
			break;                                             \
		case KPROG_X86_ALU_FLAG_ARM_SHIFT:                       \
			X86_SIM_L_SET_SHIFT_FLAGS((LHS), (RHS), (RESULT), (ALU), (WIDTH));\
			break;                                             \
		case KPROG_X86_ALU_FLAG_ARM_IMUL:                        \
			X86_SIM_L_SET_IMUL_FLAGS((LHS), (RHS), (WIDTH));   \
			break;                                             \
		default:                                                  \
			X86_SIM_L_SET_LOGIC_FLAGS((RESULT), (WIDTH));      \
			break;                                             \
		}                                                         \
	} while (0)

#define X86_SIM_L_EVAL_CC(CC)                                               \
	KPROG_X86_EVAL_FULL_CC((CC), __x86_cf, __x86_zf, __x86_sf, __x86_of, __x86_pf)

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


/* Preserve native kernel context identity; packet fields use their live
 * verifier context values and other reads use the existing memory primitive. */
/* Entry-selected representation, erased by specialization. A pointer-null
 * test would add a branch that the verifier need not eliminate. */
#define X86_SIM_L_LIVE_XDP() (__x86_sim_is_xdp)
#define X86_SIM_L_XDP_OFFSET(BASE, OFF)                                   \
	((__s64)((__u64)(long)(BASE) - (__u64)(long)__x86_sim_helper_abi_base + (__u64)(OFF)))
#define X86_SIM_L_XDP_READ(BASE, OFF, WIDTH)                               \
	({                                                               \
		__s64 __x86_xdp_off = X86_SIM_L_XDP_OFFSET((BASE), (OFF)); \
		volatile struct xdp_md *__x86_xdp_ctx = __x86_sim_helper_ctx;      \
		__u64 __x86_xdp_value = 0;                                \
		if ((WIDTH) == X86_WIDTH_64 &&                           \
		    __x86_xdp_off == KPROG_ABI_XDP_DATA_OFF)              \
			__x86_xdp_value = (__u64)(long)(void *)(long)     \
				__x86_xdp_ctx->data;                      \
		else if ((WIDTH) == X86_WIDTH_64 &&                      \
			 __x86_xdp_off == KPROG_ABI_XDP_DATA_END_OFF)      \
			__x86_xdp_value = (__u64)(long)(void *)(long)     \
				__x86_xdp_ctx->data_end;                  \
		else if ((WIDTH) == X86_WIDTH_64 && __x86_xdp_off == 16) \
			__x86_xdp_value = (__u64)(long)(void *)(long)     \
				__x86_xdp_ctx->data_meta;                 \
		else                                                     \
			__x86_xdp_value = X86_SIM_L_SKB_NATIVE_READ((BASE), (OFF), (WIDTH));                     \
		X86_SIM_L_BARRIER_VAR(__x86_xdp_value);                    \
		__x86_xdp_value;                                         \
	})

#if defined(__bpf__) || defined(__BPF__)
extern void *bpf_cast_to_kern_ctx(void *) __ksym;
#define X86_SIM_L_CTX_NUMERIC(VALUE) NATIVE_LAB_NUMERIC(VALUE)
#else
static inline void *bpf_cast_to_kern_ctx(void *ctx) { return ctx; }
#define X86_SIM_L_CTX_NUMERIC(VALUE) ((__u64)(VALUE))
#endif
#define X86_SIM_L_SKB_NATIVE_READ(BASE, OFF, WIDTH) \
 ({ __u64 __x86_snr_value; \
    if (__builtin_constant_p(OFF)) \
      __x86_snr_value=KPROG_X86_MEM_LOAD_FIXED((BASE),(OFF),(WIDTH)); \
    else __x86_snr_value=X86_SIM_L_LOAD_ADDR((__u8 *)(BASE)+(OFF),(WIDTH)); \
    __x86_snr_value; })
/* Kernel-context addresses retain native identity. Packet and qdisc cb fields
 * select the corresponding live verifier context access at the native width. */
#define X86_SIM_L_SKB_OFFSET(BASE, OFF) \
 ((__s64)((__u64)(long)X86_SIM_L_READ_REG_PTR(BASE) - (__u64)(long)__x86_sim_helper_abi_base + (__u64)(OFF)))
#if defined(__bpf__) || defined(__BPF__)
#define X86_SIM_L_SKB_FIELD(CTX, FIELD) \
 ({ __u64 __x86_sf_value; \
    asm volatile("%0 = *(u32 *)(%1 + %2)" : "=r"(__x86_sf_value) : \
     "r"(CTX), "i"(__builtin_offsetof(struct __sk_buff,FIELD)) : "memory"); \
    __x86_sf_value; })
#else
#define X86_SIM_L_SKB_FIELD(CTX, FIELD) ((__u64)((CTX)->FIELD))
#endif

#define X86_SIM_L_SKB_CB_READ_BYTES(CTX, OFF, WIDTH) \
 ({ volatile const __u8 *__x86_cbr_addr=(volatile const __u8 *)(CTX)+(OFF); \
    __u64 __x86_cbr_value=__x86_cbr_addr[0]; \
    if ((WIDTH) >= X86_WIDTH_16) __x86_cbr_value |= (__u64)__x86_cbr_addr[1] << 8; \
    if ((WIDTH) >= X86_WIDTH_32) __x86_cbr_value |= (__u64)__x86_cbr_addr[2] << 16; \
    if ((WIDTH) >= X86_WIDTH_32) __x86_cbr_value |= (__u64)__x86_cbr_addr[3] << 24; \
    if ((WIDTH) >= X86_WIDTH_64) __x86_cbr_value |= (__u64)__x86_cbr_addr[4] << 32; \
    if ((WIDTH) >= X86_WIDTH_64) __x86_cbr_value |= (__u64)__x86_cbr_addr[5] << 40; \
    if ((WIDTH) >= X86_WIDTH_64) __x86_cbr_value |= (__u64)__x86_cbr_addr[6] << 48; \
    if ((WIDTH) >= X86_WIDTH_64) __x86_cbr_value |= (__u64)__x86_cbr_addr[7] << 56; \
    __x86_cbr_value; })
#define X86_SIM_L_SKB_CB_WRITE_BYTES(CTX, OFF, WIDTH, VALUE) \
 do { volatile __u8 *__x86_cbw_addr=(volatile __u8 *)(CTX)+(OFF); \
      __u64 __x86_cbw_value=(VALUE); __x86_cbw_addr[0]=(__u8)__x86_cbw_value; \
      if ((WIDTH) >= X86_WIDTH_16) __x86_cbw_addr[1]=(__u8)(__x86_cbw_value >> 8); \
      if ((WIDTH) >= X86_WIDTH_32) __x86_cbw_addr[2]=(__u8)(__x86_cbw_value >> 16); \
      if ((WIDTH) >= X86_WIDTH_32) __x86_cbw_addr[3]=(__u8)(__x86_cbw_value >> 24); \
      if ((WIDTH) >= X86_WIDTH_64) __x86_cbw_addr[4]=(__u8)(__x86_cbw_value >> 32); \
      if ((WIDTH) >= X86_WIDTH_64) __x86_cbw_addr[5]=(__u8)(__x86_cbw_value >> 40); \
      if ((WIDTH) >= X86_WIDTH_64) __x86_cbw_addr[6]=(__u8)(__x86_cbw_value >> 48); \
      if ((WIDTH) >= X86_WIDTH_64) __x86_cbw_addr[7]=(__u8)(__x86_cbw_value >> 56); \
 } while (0)
#if defined(__bpf__) || defined(__BPF__)
#define X86_SIM_L_SKB_CB_READ(CTX, OFF, WIDTH) \
 ({ __u64 __x86_cbr_value, __x86_cbr_temp; \
    if (__builtin_constant_p(OFF)) { \
    if ((WIDTH) == 8) __asm__ __volatile__("%0 = *(u8 *)(%2 + %3)\n%1 = *(u8 *)(%2 + %4)\n%1 <<= 8\n%0 |= %1\n%1 = *(u8 *)(%2 + %5)\n%1 <<= 16\n%0 |= %1\n%1 = *(u8 *)(%2 + %6)\n%1 <<= 24\n%0 |= %1\n%1 = *(u8 *)(%2 + %7)\n%1 <<= 32\n%0 |= %1\n%1 = *(u8 *)(%2 + %8)\n%1 <<= 40\n%0 |= %1\n%1 = *(u8 *)(%2 + %9)\n%1 <<= 48\n%0 |= %1\n%1 = *(u8 *)(%2 + %10)\n%1 <<= 56\n%0 |= %1" : "=&r"(__x86_cbr_value), "=&r"(__x86_cbr_temp) : "r"(CTX), "i"((OFF)+0), "i"((OFF)+1), "i"((OFF)+2), "i"((OFF)+3), "i"((OFF)+4), "i"((OFF)+5), "i"((OFF)+6), "i"((OFF)+7) : "memory"); \
    else if ((WIDTH) == 4) __asm__ __volatile__("%0 = *(u8 *)(%2 + %3)\n%1 = *(u8 *)(%2 + %4)\n%1 <<= 8\n%0 |= %1\n%1 = *(u8 *)(%2 + %5)\n%1 <<= 16\n%0 |= %1\n%1 = *(u8 *)(%2 + %6)\n%1 <<= 24\n%0 |= %1" : "=&r"(__x86_cbr_value), "=&r"(__x86_cbr_temp) : "r"(CTX), "i"((OFF)+0), "i"((OFF)+1), "i"((OFF)+2), "i"((OFF)+3) : "memory"); \
    else if ((WIDTH) == 2) __asm__ __volatile__("%0 = *(u8 *)(%2 + %3)\n%1 = *(u8 *)(%2 + %4)\n%1 <<= 8\n%0 |= %1" : "=&r"(__x86_cbr_value), "=&r"(__x86_cbr_temp) : "r"(CTX), "i"((OFF)+0), "i"((OFF)+1) : "memory"); \
    else if ((WIDTH) == 1) __asm__ __volatile__("%0 = *(u8 *)(%2 + %3)" : "=&r"(__x86_cbr_value), "=&r"(__x86_cbr_temp) : "r"(CTX), "i"((OFF)+0) : "memory"); \
    } else __x86_cbr_value=X86_SIM_L_SKB_CB_READ_BYTES((CTX),(OFF),(WIDTH)); \
    __x86_cbr_value; })
#define X86_SIM_L_SKB_CB_WRITE(CTX, OFF, WIDTH, VALUE) \
 do { __u64 __x86_cbw_temp; \
      if (__builtin_constant_p(OFF)) { \
      if ((WIDTH) == 8) __asm__ __volatile__("%0 = %2\n*(u8 *)(%1 + %3) = %0\n%0 >>= 8\n*(u8 *)(%1 + %4) = %0\n%0 >>= 8\n*(u8 *)(%1 + %5) = %0\n%0 >>= 8\n*(u8 *)(%1 + %6) = %0\n%0 >>= 8\n*(u8 *)(%1 + %7) = %0\n%0 >>= 8\n*(u8 *)(%1 + %8) = %0\n%0 >>= 8\n*(u8 *)(%1 + %9) = %0\n%0 >>= 8\n*(u8 *)(%1 + %10) = %0" : "=&r"(__x86_cbw_temp) : "r"(CTX), "r"((__u64)(VALUE)), "i"((OFF)+0), "i"((OFF)+1), "i"((OFF)+2), "i"((OFF)+3), "i"((OFF)+4), "i"((OFF)+5), "i"((OFF)+6), "i"((OFF)+7) : "memory"); \
      else if ((WIDTH) == 4) __asm__ __volatile__("%0 = %2\n*(u8 *)(%1 + %3) = %0\n%0 >>= 8\n*(u8 *)(%1 + %4) = %0\n%0 >>= 8\n*(u8 *)(%1 + %5) = %0\n%0 >>= 8\n*(u8 *)(%1 + %6) = %0" : "=&r"(__x86_cbw_temp) : "r"(CTX), "r"((__u64)(VALUE)), "i"((OFF)+0), "i"((OFF)+1), "i"((OFF)+2), "i"((OFF)+3) : "memory"); \
      else if ((WIDTH) == 2) __asm__ __volatile__("%0 = %2\n*(u8 *)(%1 + %3) = %0\n%0 >>= 8\n*(u8 *)(%1 + %4) = %0" : "=&r"(__x86_cbw_temp) : "r"(CTX), "r"((__u64)(VALUE)), "i"((OFF)+0), "i"((OFF)+1) : "memory"); \
      else if ((WIDTH) == 1) __asm__ __volatile__("%0 = %2\n*(u8 *)(%1 + %3) = %0" : "=&r"(__x86_cbw_temp) : "r"(CTX), "r"((__u64)(VALUE)), "i"((OFF)+0) : "memory"); \
      } else X86_SIM_L_SKB_CB_WRITE_BYTES((CTX),(OFF),(WIDTH),(VALUE)); \
 } while (0)
#else
#define X86_SIM_L_SKB_CB_READ(CTX, OFF, WIDTH) X86_SIM_L_SKB_CB_READ_BYTES((CTX),(OFF),(WIDTH))
#define X86_SIM_L_SKB_CB_WRITE(CTX, OFF, WIDTH, VALUE) X86_SIM_L_SKB_CB_WRITE_BYTES((CTX),(OFF),(WIDTH),(VALUE))
#endif
/* These native scalar fields share the live BPF context value. */
#define X86_SIM_L_SKB_SCALAR_FIELDS(X) \
 X(tc_index,134,2) X(priority,144,4) X(mark,168,4)
#define X86_SIM_L_SKB_SCALAR_READ_CASE(FIELD, NATIVE_OFF, BYTES) \
 else if (__x86_sr_off >= (NATIVE_OFF) && __x86_sr_off <= (NATIVE_OFF)+(BYTES)-(__x86_sr_width)) \
  __x86_sr_value=x86_apply_width(X86_SIM_L_SKB_FIELD(__x86_sr_ctx,FIELD) >> ((__x86_sr_off-(NATIVE_OFF))*8),(__x86_sr_width));
#if defined(__bpf__) || defined(__BPF__)
#define X86_SIM_L_SKB_SCALAR_STORE(CTX, FIELD, VALUE) \
 do { __u64 __x86_ss_value=(VALUE); \
  asm volatile("*(u32 *)(%0 + %1) = %2" : : "r"(CTX), \
   "i"(__builtin_offsetof(struct __sk_buff,FIELD)),"r"(__x86_ss_value) : "memory"); } while(0)
#else
#define X86_SIM_L_SKB_SCALAR_STORE(CTX, FIELD, VALUE) ((CTX)->FIELD=(__u32)(VALUE))
#endif
#define X86_SIM_L_SKB_SCALAR_WRITE_CASE(FIELD, NATIVE_OFF, BYTES) \
 else if (__x86_sw_off >= (NATIVE_OFF) && __x86_sw_off <= (NATIVE_OFF)+(BYTES)-(__x86_sw_width)) { \
  __u64 __x86_ss_old=X86_SIM_L_SKB_FIELD(((struct __sk_buff *)__x86_sim_helper_ctx),FIELD) & ((1ULL << ((BYTES)*8))-1); \
  __u64 __x86_ss_shift=(__x86_sw_off-(NATIVE_OFF))*8; \
  __u64 __x86_ss_mask=x86_width_mask((__x86_sw_width)) << __x86_ss_shift; \
  __u64 __x86_ss_new=(__x86_ss_old & ~__x86_ss_mask) | ((__x86_sw_value << __x86_ss_shift) & __x86_ss_mask); \
  X86_SIM_L_SKB_SCALAR_STORE(((struct __sk_buff *)__x86_sim_helper_ctx),FIELD,__x86_ss_new); \
 }
#define X86_SIM_L_SKB_READ(BASE, OFF, WIDTH) \
 ({ __u8 __x86_sr_width=(WIDTH); __s64 __x86_sr_off = X86_SIM_L_SKB_OFFSET((BASE), (OFF)); \
    struct __sk_buff *__x86_sr_ctx = __x86_sim_helper_ctx; \
    __u64 __x86_sr_value; \
    if (((__x86_sr_off >= X86_SKB_DATA_OFF && __x86_sr_off <= X86_SKB_DATA_OFF + 8 - (WIDTH)) || \
         (__x86_sr_off >= X86_SKB_DATA_END_OFF && __x86_sr_off <= X86_SKB_DATA_END_OFF + 8 - (WIDTH)))) { \
      __s64 __x86_sr_lane; \
      if (__x86_sr_off >= X86_SKB_DATA_OFF) { __x86_sr_value=X86_SIM_L_SKB_FIELD(__x86_sr_ctx,data); __x86_sr_lane=__x86_sr_off-X86_SKB_DATA_OFF; } \
      else { __x86_sr_value=X86_SIM_L_SKB_FIELD(__x86_sr_ctx,data_end); __x86_sr_lane=__x86_sr_off-X86_SKB_DATA_END_OFF; } \
      if ((WIDTH) != X86_WIDTH_64) __x86_sr_value=x86_apply_width(X86_SIM_L_CTX_NUMERIC(__x86_sr_value) >> (__x86_sr_lane*8), (WIDTH)); \
    } else if (__x86_sr_off >= X86_SKB_CB_OFF && __x86_sr_off <= X86_SKB_CB_OFF + 20 - (WIDTH)) \
      __x86_sr_value=X86_SIM_L_SKB_CB_READ(__x86_sr_ctx, __x86_sr_off-X86_SKB_CB_OFF+(__s64)__builtin_offsetof(struct __sk_buff,cb), (WIDTH)); \
    X86_SIM_L_SKB_SCALAR_FIELDS(X86_SIM_L_SKB_SCALAR_READ_CASE) \
    else __x86_sr_value=X86_SIM_L_SKB_NATIVE_READ(X86_SIM_L_READ_REG_PTR(BASE),(OFF),(WIDTH)); \
    __x86_sr_value; })
#define X86_SIM_L_SKB_WRITE(BASE, OFF, WIDTH, VALUE) \
 do { __u8 __x86_sw_width=(WIDTH); __s64 __x86_sw_off=X86_SIM_L_SKB_OFFSET((BASE),(OFF)); \
      __u64 __x86_sw_value=x86_apply_width((VALUE),(WIDTH)); \
      if (__x86_sw_off >= X86_SKB_CB_OFF && __x86_sw_off <= X86_SKB_CB_OFF + 20 - (WIDTH)) { \
       __s64 __x86_sw_ctx_off=__x86_sw_off-X86_SKB_CB_OFF+__builtin_offsetof(struct __sk_buff,cb); \
       X86_SIM_L_SKB_CB_WRITE(__x86_sim_helper_ctx,__x86_sw_ctx_off,(WIDTH),__x86_sw_value); \
      } X86_SIM_L_SKB_SCALAR_FIELDS(X86_SIM_L_SKB_SCALAR_WRITE_CASE) \
      else X86_SIM_L_STORE_ADDR((__u8 *)X86_SIM_L_READ_REG_PTR(BASE)+(OFF),(WIDTH),__x86_sw_value); \
 } while (0)

#define X86_SIM_L_WRITE_MEM_VALUE(BASE, OFF, ADDR, WIDTH, VALUE) \
 do { if (__x86_sim_abi_kind == KPROG_ABI_KIND_SKB && X86_SIM_L_REG_TAG(BASE) == X86_SIM_TAG_ABI) \
       X86_SIM_L_SKB_WRITE((BASE),(OFF),(WIDTH),(VALUE)); \
      else X86_SIM_L_STORE_ADDR_TAGGED((ADDR),(WIDTH),(VALUE),X86_SIM_L_REG_TAG(BASE)); } while(0)

#define X86_SIM_L_READ_MEM_VALUE(BASE_REG, AUX, IMM, WIDTH, STORE_DISP)      \
	({                                                                 \
		void *__x86_l_base_ptr = (void *)0;                      \
		__u8 __x86_l_read_mem_width =                            \
			X86_SIM_L_EFFECTIVE_WIDTH(WIDTH);                \
		__s64 __x86_l_disp = (STORE_DISP) ?                      \
			x86_store_imm_disp(IMM) : x86_simm(IMM);          \
		__x86_l_disp = X86_SIM_L_MEM_OFFSET((AUX), __x86_l_disp);\
		if (X86_SIM_L_REG_TAG(BASE_REG) != X86_SIM_TAG_ABI)      \
			X86_SIM_L_BARRIER_VAR(__x86_l_disp);              \
		if (KPROG_X86_REG_PRESENT(BASE_REG))                     \
			__x86_l_base_ptr = X86_SIM_L_READ_REG_PTR(BASE_REG);\
		__u64 __x86_l_value;                                     \
		void *__x86_l_addr = KPROG_X86_REG_PRESENT(BASE_REG) ?    \
			KPROG_PTR_ADD64_BITS(__x86_l_base_ptr, __x86_l_disp) :         \
			(void *)(unsigned long)__x86_l_disp;              \
		if (X86_SIM_L_LIVE_XDP() &&                               \
		    X86_SIM_L_REG_TAG(BASE_REG) == X86_SIM_TAG_ABI)       \
			__x86_l_value = X86_SIM_L_XDP_READ(              \
				__x86_l_base_ptr, __x86_l_disp,             \
				__x86_l_read_mem_width);                   \
		else if (__x86_sim_abi_kind == KPROG_ABI_KIND_SKB &&    \
		         X86_SIM_L_REG_TAG(BASE_REG) == X86_SIM_TAG_ABI) \
			__x86_l_value = X86_SIM_L_SKB_READ((BASE_REG),    \
				__x86_l_disp, __x86_l_read_mem_width);       \
		else switch (X86_SIM_L_MEM_READ_SRC(BASE_REG,                 \
					       __x86_l_read_mem_width)) {\
		case KPROG_X86_MEM_SRC_STACK:                            \
			__x86_l_value = X86_SIM_L_STACK_READ(             \
				(__s64)(long)__x86_l_base_ptr + __x86_l_disp,\
				__x86_l_read_mem_width);                  \
			break;                                           \
		case KPROG_X86_MEM_SRC_ABI_PTR_LOAD:                     \
			__x86_l_value =                                  \
				(__u64)(long)X86_SIM_L_LOAD_PTR_ADDR(     \
					__x86_l_addr);                    \
			break;                                           \
		default:                                                 \
			if (X86_SIM_L_REG_TAG(BASE_REG) == X86_SIM_TAG_ABI && \
			    X86_MEM_AUX_INDEX(AUX) == X86_REG_NONE)       \
				__x86_l_value = KPROG_X86_MEM_LOAD_FIXED( \
					__x86_l_base_ptr, (STORE_DISP) ?   \
					x86_store_imm_disp(IMM) : x86_simm(IMM), \
					__x86_l_read_mem_width);         \
			else                                             \
				__x86_l_value = X86_SIM_L_NATIVE_DATA_LOAD_TAGGED( \
					__x86_l_base_ptr, __x86_l_disp,       \
					__x86_l_read_mem_width, X86_SIM_L_REG_TAG(BASE_REG));          \
			break;                                           \
		}                                                         \
		__x86_l_value;                                            \
	})

/* The existing environment input relates a scalar read to its stock
 * exception outcome. The successful arm retains the ordinary memory access;
 * recovery clears the exception table GPR and resumes the following step.
 * Typed context/stack/map/packet/readonly routes retain their lifetime premise. */
#define X86_SIM_L_READ_RECOVERY_AT(BASE, DST, ADDRESS) \
    ({ int __x86_read_recovered = 0; \
       if (KPROG_X86_REG_PRESENT(BASE) && (BASE) != X86_RSP && \
           X86_SIM_L_REG_TAG(BASE) == X86_SIM_TAG_SCALAR && \
           ((__u64)(ADDRESS) < 4096U || (X86_SIM_L_UNSPECIFIED() & 1U))) { \
           if ((DST)==X86_RSP) X86_SIM_L_ARCHITECTURAL_FAULT(); \
           else X86_SIM_L_WRITE_REG_WIDTH((DST), 0, X86_WIDTH_64); \
           __x86_read_recovered = 1; \
       } \
       __x86_read_recovered; })

/* Effective addresses include the decoded index, scale and displacement. */
#define X86_SIM_L_READ_RECOVERY(BASE, DST) \
    X86_SIM_L_READ_RECOVERY_AT((BASE), (DST), X86_SIM_L_READ_REG(BASE))
#define X86_SIM_L_READ_RECOVERY_MEM(BASE, DST, AUX, DISP) \
    X86_SIM_L_READ_RECOVERY_AT((BASE), (DST), \
        X86_SIM_L_READ_REG(BASE) + (__u64)X86_SIM_L_MEM_OFFSET((AUX), (DISP)))

#define X86_SIM_L_EXEC_MOV_LOAD(OP, DST, SRC, FLAGS, AUX, IMM)              \
	do { \
        if (X86_SIM_L_READ_RECOVERY_MEM(SRC, DST, (AUX), x86_simm(IMM))) break; \
		__u8 __x86_l_write_width =                                 \
			KPROG_X86_MOV_LOAD_WRITE_WIDTH(FLAGS);             \
		__u8 __x86_l_mem_width =                                   \
			KPROG_X86_MOV_LOAD_MEM_WIDTH((FLAGS), (AUX));      \
		__u8 __x86_l_arm = KPROG_X86_MOV_LOAD_ARM(                 \
			(SRC) == X86_RSP, (OP) == X86_OP_MOV_LOAD,         \
			__x86_l_mem_width, __x86_l_write_width,            \
			X86_SIM_L_REG_TAG(SRC));                           \
		__s64 __x86_l_disp = X86_SIM_L_MEM_OFFSET((AUX), x86_simm(IMM));\
        __s64 __x86_l_meta_disp=__x86_l_disp; \
		void *__x86_l_base_ptr = (void *)0;                      \
		__u64 __x86_l_value = 0;                                 \
		if (KPROG_X86_REG_PRESENT(SRC))                          \
			__x86_l_base_ptr = X86_SIM_L_READ_REG_PTR(SRC);   \
		if (X86_SIM_L_REG_TAG(SRC) != X86_SIM_TAG_ABI)           \
			X86_SIM_L_BARRIER_VAR(__x86_l_disp);              \
		void *__x86_l_addr = KPROG_X86_REG_PRESENT(SRC) ?         \
			KPROG_PTR_ADD64_BITS(__x86_l_base_ptr, __x86_l_disp) :         \
			(void *)(unsigned long)__x86_l_disp;              \
		if (__x86_sim_abi_kind == KPROG_ABI_KIND_SKB &&          \
		    X86_SIM_L_REG_TAG(SRC) == X86_SIM_TAG_ABI) {        \
			__x86_l_value=X86_SIM_L_SKB_READ((SRC),             \
				__x86_l_disp,__x86_l_mem_width);              \
			if (__x86_l_arm == KPROG_X86_MOV_LOAD_ARM_ABI_PTR) { \
				__u8 __x86_skb_tag=KPROG_ABI_LOAD_TAG(        \
				 KPROG_ABI_KIND_SKB,X86_SIM_L_SKB_OFFSET((SRC),__x86_l_disp), \
				 X86_SIM_TAG_SCALAR,X86_SIM_TAG_PACKET,X86_SIM_TAG_PACKET_END); \
				if ((DST)==X86_RSP) X86_SIM_L_WRITE_REG_WIDTH((DST),__x86_l_value,X86_WIDTH_64); \
				else X86_SIM_L_WRITE_REG_PTR_TAG((DST),(void *)(long)__x86_l_value,__x86_skb_tag); \
			} else {                                            \
				if ((OP)==X86_OP_MOVSX_LOAD)                  \
				 __x86_l_value=x86_sign_extend(__x86_l_value,__x86_l_mem_width); \
				X86_SIM_L_WRITE_REG_WIDTH((DST),__x86_l_value,__x86_l_write_width); \
			}                                                  \
		} else if (X86_SIM_L_LIVE_XDP() &&                               \
		    X86_SIM_L_REG_TAG(SRC) == X86_SIM_TAG_ABI) {          \
			__u64 __x86_xdp_value = X86_SIM_L_XDP_READ(       \
				__x86_l_base_ptr, __x86_l_disp,             \
				__x86_l_mem_width);                        \
			__u8 __x86_xdp_tag = KPROG_ABI_LOAD_TAG(          \
				KPROG_ABI_KIND_XDP, X86_SIM_L_XDP_OFFSET(  \
					__x86_l_base_ptr, __x86_l_disp),    \
				X86_SIM_TAG_SCALAR, X86_SIM_TAG_PACKET,     \
				X86_SIM_TAG_PACKET_END);                   \
			if ((DST) == X86_RSP)                            \
				X86_SIM_L_WRITE_REG_WIDTH((DST),         \
					__x86_xdp_value, X86_WIDTH_64);    \
			else                                             \
				X86_SIM_L_WRITE_REG_PTR_TAG((DST),       \
					(void *)(long)__x86_xdp_value, __x86_xdp_tag); \
		} else switch (X86_SIM_L_MEM_READ_SRC(SRC, __x86_l_mem_width)) {\
		case KPROG_X86_MEM_SRC_STACK:                            \
			__x86_l_value = X86_SIM_L_STACK_READ(             \
				(__s64)(long)__x86_l_base_ptr + __x86_l_disp,\
				__x86_l_mem_width);                       \
			if ((OP) == X86_OP_MOVSX_LOAD)                    \
				__x86_l_value = x86_sign_extend(           \
					__x86_l_value, __x86_l_mem_width);  \
            struct x86_sim_stack_value __x86_mv_saved=X86_SIM_L_STACK_VALUES_READ( \
                X86_SIM_L_STACK_INDEX((__s64)(long)__x86_l_base_ptr+__x86_l_meta_disp),__x86_l_mem_width); \
            if ((OP)==X86_OP_MOV_LOAD && __x86_l_write_width==X86_WIDTH_64 && \
                __x86_mv_saved.tag!=X86_SIM_TAG_SCALAR && (DST)!=X86_RSP) \
                X86_SIM_L_WRITE_REG_PTR_TAG((DST),__x86_mv_saved.tag==X86_SIM_TAG_STACK ? __x86_mv_saved.pointer : (void *)(long)__x86_l_value,__x86_mv_saved.tag); \
            else X86_SIM_L_WRITE_REG_WIDTH((DST),__x86_l_value,__x86_l_write_width); \
            break;                                           \
		case KPROG_X86_MEM_SRC_ABI_PTR_LOAD:                     \
			if (__x86_l_arm != KPROG_X86_MOV_LOAD_ARM_ABI_PTR) {\
				if (X86_MEM_AUX_INDEX(AUX) == X86_REG_NONE) \
					__x86_l_value = KPROG_X86_MEM_LOAD_FIXED( \
						__x86_l_base_ptr, x86_simm(IMM), __x86_l_mem_width); \
				else                                      \
					__x86_l_value = X86_SIM_L_NATIVE_DATA_LOAD_TAGGED( \
					__x86_l_base_ptr, __x86_l_disp, __x86_l_mem_width, X86_SIM_L_REG_TAG(SRC)); \
				X86_SIM_L_WRITE_REG_WIDTH((DST),          \
					__x86_l_value, __x86_l_write_width);\
				break;                                    \
			}                                                 \
			__u8 __x86_l_ptr_tag = KPROG_ABI_LOAD_TAG(       \
				__x86_sim_abi_kind, __x86_l_disp,          \
				X86_SIM_TAG_SCALAR, X86_SIM_TAG_PACKET,    \
				X86_SIM_TAG_PACKET_END);                   \
			if ((DST) == X86_RSP)                             \
				X86_SIM_L_WRITE_REG_WIDTH((DST),          \
					(__u64)(long)X86_SIM_L_LOAD_PTR_ADDR(__x86_l_addr), X86_WIDTH_64); \
			else                                              \
				X86_SIM_L_WRITE_REG_PTR_TAG((DST),         \
					X86_SIM_L_LOAD_PTR_ADDR(__x86_l_addr), \
					__x86_l_ptr_tag);                  \
			break;                                           \
		default:                                                 \
			if (X86_SIM_L_REG_TAG(SRC) == X86_SIM_TAG_ABI && \
			    X86_MEM_AUX_INDEX(AUX) == X86_REG_NONE)       \
				__x86_l_value = KPROG_X86_MEM_LOAD_FIXED( \
					__x86_l_base_ptr, x86_simm(IMM), __x86_l_mem_width); \
			else                                             \
				__x86_l_value = X86_SIM_L_NATIVE_DATA_LOAD_TAGGED( \
					__x86_l_base_ptr, __x86_l_disp, __x86_l_mem_width, X86_SIM_L_REG_TAG(SRC)); \
			if ((OP) == X86_OP_MOVSX_LOAD)                    \
				__x86_l_value = x86_sign_extend(           \
					__x86_l_value, __x86_l_mem_width);  \
            struct x86_sim_stack_value __x86_mv_alias={}; \
            if (X86_SIM_L_REG_TAG(SRC)==X86_SIM_TAG_STACK) \
                __x86_mv_alias=X86_SIM_L_STACK_VALUES_READ( \
                    (__u64)(long)__x86_l_addr-(__u64)(long)&__x86_stack_mem.b[0],__x86_l_mem_width); \
            if ((OP)==X86_OP_MOV_LOAD && __x86_l_write_width==X86_WIDTH_64 && \
                __x86_mv_alias.tag!=X86_SIM_TAG_SCALAR && (DST)!=X86_RSP) \
                X86_SIM_L_WRITE_REG_PTR_TAG((DST),__x86_mv_alias.tag==X86_SIM_TAG_STACK ? __x86_mv_alias.pointer : (void *)(long)__x86_l_value,__x86_mv_alias.tag); \
            else X86_SIM_L_WRITE_REG_WIDTH((DST),__x86_l_value,__x86_l_write_width); \
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
        __s64 __x86_l_meta_disp=__x86_l_disp; \
		if (X86_SIM_L_REG_TAG(DST) != X86_SIM_TAG_ABI)       \
			X86_SIM_L_BARRIER_VAR(__x86_l_disp);                    \
		if (KPROG_X86_REG_PRESENT(DST))                          \
			__x86_l_base_ptr = X86_SIM_L_READ_REG_PTR(DST);   \
		if (__x86_sim_abi_kind == KPROG_ABI_KIND_SKB &&         \
		    X86_SIM_L_REG_TAG(DST) == X86_SIM_TAG_ABI)          \
			X86_SIM_L_SKB_WRITE((DST),__x86_l_disp,__x86_l_width,__x86_l_value); \
		else switch (X86_SIM_L_MEM_STORE_SRC(DST)) {                   \
		case KPROG_X86_STORE_ARM_STACK:                           \
            X86_SIM_L_STACK_VALUES_ERASE(X86_SIM_L_STACK_INDEX((__s64)(long)__x86_l_base_ptr+__x86_l_meta_disp),__x86_l_width); \
			X86_SIM_L_STACK_WRITE_RAW(                            \
				(__s64)(long)__x86_l_base_ptr + __x86_l_disp,\
				X86_SIM_L_EFFECTIVE_WIDTH(FLAGS),          \
                __x86_l_value); \
            if ((OP)==X86_OP_MOV_STORE_REG && __x86_l_width==X86_WIDTH_64 && \
                KPROG_X86_STORE_SRC_SHIFT(0U,(AUX))==0U) \
                X86_SIM_L_STACK_VALUES_SAVE( \
                    X86_SIM_L_STACK_INDEX((__s64)(long)__x86_l_base_ptr+__x86_l_meta_disp), \
                    __x86_l_width,(SRC)==X86_RSP ? X86_SIM_L_STACK_PTR((__s64)(long)X86_SIM_L_READ_REG_PTR(SRC)) : X86_SIM_L_READ_REG_PTR(SRC), \
                    (SRC)==X86_RSP ? X86_SIM_TAG_STACK : X86_SIM_L_REG_TAG(SRC)); \
            break;                                           \
		default:                                                 \
			void *__x86_l_addr = KPROG_PTR_ADD64_BITS(__x86_l_base_ptr, __x86_l_disp);               \
            if (X86_SIM_L_REG_TAG(DST)==X86_SIM_TAG_STACK) \
                X86_SIM_L_STACK_VALUES_ERASE((__u64)(long)__x86_l_addr-(__u64)(long)&__x86_stack_mem.b[0],__x86_l_width); \
            if (X86_SIM_L_REG_TAG(DST) == X86_SIM_TAG_STACK && \
			    ((OP) == X86_OP_MOV_STORE_IMM ||             \
			     X86_SIM_L_REG_TAG(SRC) == X86_SIM_TAG_SCALAR)) \
				X86_SIM_L_STORE_ADDR_TAGGED(             \
					__x86_l_addr, __x86_l_width,      \
					__x86_l_value, X86_SIM_TAG_STACK);                   \
			else                                             \
				X86_SIM_L_STORE_ADDR_TAGGED(__x86_l_addr, \
                    __x86_l_width,__x86_l_value,X86_SIM_L_REG_TAG(DST));     \
            if (X86_SIM_L_REG_TAG(DST)==X86_SIM_TAG_STACK && (OP)==X86_OP_MOV_STORE_REG && \
                __x86_l_width==X86_WIDTH_64 && KPROG_X86_STORE_SRC_SHIFT(0U,(AUX))==0U) \
                X86_SIM_L_STACK_VALUES_SAVE( \
                    (__u64)(long)__x86_l_addr-(__u64)(long)&__x86_stack_mem.b[0],__x86_l_width, \
                    (SRC)==X86_RSP ? X86_SIM_L_STACK_PTR((__s64)(long)X86_SIM_L_READ_REG_PTR(SRC)) : X86_SIM_L_READ_REG_PTR(SRC), \
                    (SRC)==X86_RSP ? X86_SIM_TAG_STACK : X86_SIM_L_REG_TAG(SRC)); \
            break; \
        } \
        } while (0)

#define X86_SIM_L_EXEC_MOVBE_LOAD(DST, SRC, FLAGS, AUX, IMM)               \
	do { \
        if (X86_SIM_L_READ_RECOVERY_MEM(SRC, DST, (AUX), x86_simm(IMM))) break; \
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
		void *__x86_l_base_ptr = KPROG_X86_REG_ABSENT(DST) ?      \
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
			void *__x86_l_addr = KPROG_PTR_ADD64_BITS(__x86_l_base_ptr, __x86_l_disp);               \
			X86_SIM_L_STORE_ADDR_TAGGED(__x86_l_addr, __x86_l_width, \
					     __x86_l_value, X86_SIM_L_REG_TAG(DST));              \
			break;                                            \
		}                                                         \
	} while (0)

#define X86_SIM_L_EXEC_LOAD_XMM0(SRC, AUX, IMM)                             \
	do { \
        if (X86_SIM_L_READ_RECOVERY_MEM(SRC, X86_REG_NONE, (AUX), x86_simm(IMM))) break; \
		__s64 __x86_l_disp = X86_SIM_L_MEM_OFFSET((AUX),          \
			x86_simm(IMM));                                   \
		__u8 __x86_l_arm = X86_SIM_L_MEM_XMM0_ARM(SRC);           \
		__u8 __x86_l_base_none = KPROG_X86_REG_ABSENT(SRC);       \
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
					(__u64)(IMM) + (__u64)X86_SIM_L_MEM_OFFSET((AUX), 0), \
					X86_SIM_L_READ_REG_PTR(SRC));  \
			void *__x86_l_addr =                              \
				KPROG_X86_XMM0_ADDS_DISP(                 \
					__x86_l_base_none, __x86_l_base_form) \
					? (__u8 *)__x86_l_base_ptr        \
						  + __x86_l_disp          \
					: __x86_l_base_ptr;               \
			__x86_xmm0_lo = X86_SIM_L_LOAD_ADDR_TAGGED(__x86_l_addr,\
				X86_WIDTH_64, X86_SIM_L_REG_TAG(SRC));                            \
			__x86_xmm0_hi = X86_SIM_L_LOAD_ADDR_TAGGED(             \
				(__u8 *)__x86_l_addr                       \
					+ KPROG_X86_XMM0_LANE_OFFSET(1),  \
				X86_WIDTH_64, X86_SIM_L_REG_TAG(SRC));                            \
			break;                                            \
		}                                                         \
		}                                                         \
	} while (0)

#define X86_SIM_L_EXEC_STORE_XMM0(DST, AUX, IMM)                            \
	do {                                                               \
		__s64 __x86_l_disp = X86_SIM_L_MEM_OFFSET((AUX),          \
			x86_simm(IMM));                                   \
		__u8 __x86_l_arm = X86_SIM_L_MEM_XMM0_ARM(DST);           \
		__u8 __x86_l_base_none = KPROG_X86_REG_ABSENT(DST);       \
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
			X86_SIM_L_STORE_ADDR_TAGGED(__x86_l_addr, X86_WIDTH_64,  \
					     __x86_xmm0_lo, X86_SIM_L_REG_TAG(DST));              \
			X86_SIM_L_STORE_ADDR_TAGGED(                             \
				(__u8 *)__x86_l_addr                       \
					+ KPROG_X86_XMM0_LANE_OFFSET(1),  \
				X86_WIDTH_64, __x86_xmm0_hi, X86_SIM_L_REG_TAG(DST));             \
			break;                                            \
		}                                                         \
		}                                                         \
	} while (0)

#define X86_SIM_L_EXEC_LEA(DST, SRC, FLAGS, AUX, IMM)                       \
	do {                                                               \
		__u8 __x86_l_width = X86_SIM_L_EFFECTIVE_WIDTH(FLAGS);    \
		if (__x86_l_width == X86_WIDTH_64 && KPROG_X86_REG_ABSENT(SRC) &&\
		    (AUX) == X86_LEA_AUX_RODATA) {                        \
			X86_SIM_L_WRITE_REG_WIDTH((DST), (IMM), __x86_l_width);\
		} else {                                                  \
			__s64 __x86_l_off = X86_SIM_L_MEM_OFFSET((AUX), x86_simm(IMM));\
			X86_SIM_L_BARRIER_VAR(__x86_l_off);               \
			void *__x86_l_src_ptr = KPROG_X86_REG_ABSENT(SRC) ? (void *)0 :\
				X86_SIM_L_READ_REG_PTR(SRC);                 \
			__u8 __x86_l_src_tag = X86_SIM_L_REG_TAG(SRC);      \
			void *__x86_l_result;                            \
			if (__x86_l_width == X86_WIDTH_64) {              \
				__u8 __x86_l_dst_tag =                 \
					KPROG_PTR_ADD64_TAG(__x86_l_src_tag);\
				if (KPROG_X86_LEA_STACK_REFERENCE((SRC) == X86_RSP, (DST) == X86_RSP)) {                  \
					__s64 __x86_l_stack_off =          \
						(__s64)((__u64)(unsigned long)__x86_l_src_ptr + (__u64)__x86_l_off);\
					__x86_l_result =                  \
						X86_SIM_L_STACK_PTR(__x86_l_stack_off);\
					__x86_l_dst_tag = X86_SIM_TAG_STACK;\
				} else {                                  \
					__x86_l_result =                  \
						KPROG_PTR_ADD64_BITS(          \
							__x86_l_src_ptr, __x86_l_off);\
				}                                         \
				if (__x86_l_src_tag==X86_SIM_TAG_SCALAR && \
				    KPROG_X86_MEM_INDEX_PRESENT(X86_MEM_AUX_INDEX(AUX)) && \
				    X86_MEM_AUX_SCALE_LOG2(AUX)==0 && \
				    X86_SIM_L_MEMORY_TAG(X86_SIM_L_REG_TAG(X86_MEM_AUX_INDEX(AUX)))) { \
					__x86_l_result=KPROG_PTR_ADD64_BITS(X86_SIM_L_READ_REG_PTR(X86_MEM_AUX_INDEX(AUX)), \
						(__u64)(long)__x86_l_src_ptr + x86_simm(IMM)); \
					__x86_l_dst_tag=KPROG_PTR_ADD64_TAG(X86_SIM_L_REG_TAG(X86_MEM_AUX_INDEX(AUX))); \
				} \
				if ((DST) == X86_RSP)                      \
					X86_SIM_L_WRITE_REG_WIDTH((DST),  \
						(KPROG_X86_REG_ABSENT(SRC) ? 0 : X86_SIM_L_READ_REG(SRC)) + __x86_l_off, __x86_l_width); \
				else                                      \
					X86_SIM_L_WRITE_REG_PTR_TAG((DST), \
						__x86_l_result, __x86_l_dst_tag); \
			} else {                                           \
				__u64 __x86_l_numeric =                    \
					(KPROG_X86_REG_ABSENT(SRC) ? 0 : X86_SIM_L_READ_REG(SRC)) + __x86_l_off; \
				X86_SIM_L_WRITE_REG_WIDTH((DST), __x86_l_numeric, __x86_l_width); \
			}                                                 \
		}                                                         \
	} while (0)

/* Classic ROR updates only CF/OF. The masked count, not count modulo
 * operand bits, decides whether flags change (e.g. ROR byte by eight). */
#define X86_SIM_L_SET_ROR_FLAGS(RESULT, COUNT, WIDTH) \
	do { \
		__u8 __x86_ror_n = x86_shift_count((COUNT), (WIDTH)); \
		if (__x86_ror_n) { \
			__u32 __x86_ror_bits = x86_width_bits(WIDTH); \
			__x86_cf = ((RESULT) >> (__x86_ror_bits - 1)) & 1; \
			if (__x86_ror_n == 1) \
				__x86_of = __x86_cf ^ (((RESULT) >> (__x86_ror_bits - 2)) & 1); \
		} \
	} while (0)

#define X86_SIM_L_EXEC_ROR(DST, FLAGS, AUX, IMM) \
	do { \
		__u8 __x86_ror_width = X86_SIM_L_EFFECTIVE_WIDTH(FLAGS); \
		__u64 __x86_ror_count = (IMM); \
		__u8 __x86_ror_lane = KPROG_X86_REG_LANE_AUX_DST_SHIFT(AUX); \
		__u64 __x86_ror_result = x86_ror(X86_SIM_L_READ_REG_WIDTH_SHIFT( \
			(DST), __x86_ror_width, __x86_ror_lane), __x86_ror_count, __x86_ror_width); \
		X86_SIM_L_WRITE_REG_WIDTH_SHIFT((DST), __x86_ror_result, __x86_ror_width, __x86_ror_lane); \
		X86_SIM_L_SET_ROR_FLAGS(__x86_ror_result, __x86_ror_count, __x86_ror_width); \
	} while (0)

/* RORX reads its source before writing its destination and preserves flags. */
#define X86_SIM_L_EXEC_RORX(DST, SRC, FLAGS, IMM)                         \
	do {                                                               \
		__u8 __x86_rorx_width = X86_SIM_L_EFFECTIVE_WIDTH(FLAGS); \
		__u64 __x86_rorx_src = X86_SIM_L_READ_REG(SRC);           \
		X86_SIM_L_WRITE_REG_WIDTH((DST),                         \
			x86_ror(__x86_rorx_src, (IMM), __x86_rorx_width),  \
			__x86_rorx_width);                               \
	} while (0)

#define X86_SIM_L_EXEC_ROR_MEM(DST, FLAGS, AUX, IMM) \
	do { \
        if (X86_SIM_L_READ_RECOVERY_MEM(DST, X86_REG_NONE, (AUX), x86_simm(IMM))) break; \
		__u8 __x86_ror_width = X86_SIM_L_EFFECTIVE_WIDTH(FLAGS); \
		__u32 __x86_ror_aux = (AUX); \
		__u8 __x86_ror_count = KPROG_X86_MEM_AUX_OP(__x86_ror_aux); \
		__u64 __x86_ror_address = (IMM); \
		__u64 __x86_ror_result = x86_ror(X86_SIM_L_READ_MEM_VALUE( \
			(DST), __x86_ror_aux, __x86_ror_address, __x86_ror_width, 0), \
			__x86_ror_count, __x86_ror_width); \
		__s64 __x86_ror_disp = X86_SIM_L_MEM_OFFSET(__x86_ror_aux, x86_simm(__x86_ror_address)); \
		void *__x86_ror_base = (void *)0; \
		X86_SIM_L_BARRIER_VAR(__x86_ror_disp); \
		if (KPROG_X86_REG_PRESENT(DST)) __x86_ror_base = X86_SIM_L_READ_REG_PTR(DST); \
		if ((DST) == X86_RSP) \
			X86_SIM_L_STACK_WRITE((__s64)(long)__x86_ror_base + __x86_ror_disp, __x86_ror_width, __x86_ror_result); \
		else { \
			void *__x86_ror_addr = KPROG_PTR_ADD64_BITS(__x86_ror_base, __x86_ror_disp); \
			X86_SIM_L_STORE_ADDR_TAGGED(__x86_ror_addr, __x86_ror_width, __x86_ror_result, X86_SIM_L_REG_TAG(DST)); \
		} \
		X86_SIM_L_SET_ROR_FLAGS(__x86_ror_result, __x86_ror_count, __x86_ror_width); \
	} while (0)

#define X86_SIM_L_EXEC_ALU_IMM(DST, FLAGS, ALU, IMM)                        \
	do {                                                               \
		__u8 __x86_l_width = X86_SIM_L_EFFECTIVE_WIDTH(FLAGS);    \
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
            if ((DST)==X86_RSP && __x86_l_width==X86_WIDTH_64 && \
                (__x86_l_alu==X86_ALU_ADD || __x86_l_alu==X86_ALU_SUB)) \
                X86_SIM_L_WRITE_REG_PTR_TAG((DST), KPROG_PTR_ADD64_BITS(__x86_rsp.ptr, \
                    __x86_l_alu==X86_ALU_ADD ? __x86_l_rhs : -__x86_l_rhs),X86_SIM_TAG_SCALAR); \
            else if (__x86_l_width==X86_WIDTH_64 && __x86_l_dst_shift==0 && \
                X86_SIM_L_MEMORY_TAG(X86_SIM_L_REG_TAG(DST)) && \
                (__x86_l_alu==X86_ALU_ADD || __x86_l_alu==X86_ALU_SUB)) \
                X86_SIM_L_WRITE_REG_PTR_TAG((DST), KPROG_PTR_ADD64_BITS(X86_SIM_L_READ_REG_PTR(DST), \
                    __x86_l_alu==X86_ALU_ADD ? __x86_l_rhs : -__x86_l_rhs), \
                    KPROG_PTR_ADD64_TAG(X86_SIM_L_REG_TAG(DST))); \
            else \
			X86_SIM_L_WRITE_REG_WIDTH_SHIFT((DST), __x86_l_result,\
				__x86_l_width, __x86_l_dst_shift);           \
		}                                                         \
	} while (0)

#define X86_SIM_L_EXEC_ALU_REG(DST, SRC, FLAGS, ALU)                        \
	do {                                                               \
		__u8 __x86_l_width = X86_SIM_L_EFFECTIVE_WIDTH(FLAGS);    \
		__u32 __x86_l_aux = (ALU);                               \
		__u8 __x86_l_alu =                                      \
			KPROG_X86_REG_LANE_AUX_PAYLOAD(__x86_l_aux);       \
		__u8 __x86_l_dst_shift =                                  \
			KPROG_X86_REG_LANE_AUX_DST_SHIFT(__x86_l_aux);       \
		__u8 __x86_l_src_shift =                                  \
			KPROG_X86_REG_LANE_AUX_SRC_SHIFT(__x86_l_aux);       \
		__u64 __x86_l_lhs = 0, __x86_l_rhs = 0;                  \
		/* XOR of the same decoded register lane is always zero. */ \
		if (!(__x86_l_alu == X86_ALU_XOR && (DST) == (SRC) &&     \
		      __x86_l_dst_shift == __x86_l_src_shift)) {          \
			__x86_l_lhs = X86_SIM_L_READ_REG_WIDTH_SHIFT(     \
				(DST), __x86_l_width, __x86_l_dst_shift);  \
			__x86_l_rhs = X86_SIM_L_READ_REG_WIDTH_SHIFT(     \
				(SRC), __x86_l_width, __x86_l_src_shift);  \
		}                                                        \
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
            if ((DST)==X86_RSP && __x86_l_width==X86_WIDTH_64 && \
                (__x86_l_alu==X86_ALU_ADD || __x86_l_alu==X86_ALU_SUB)) \
                X86_SIM_L_WRITE_REG_PTR_TAG((DST), KPROG_PTR_ADD64_BITS(__x86_rsp.ptr, \
                    __x86_l_alu==X86_ALU_ADD ? __x86_l_rhs : -__x86_l_rhs),X86_SIM_TAG_SCALAR); \
            else if (__x86_l_width==X86_WIDTH_64 && __x86_l_dst_shift==0 && __x86_l_src_shift==0 && \
                X86_SIM_L_MEMORY_TAG(X86_SIM_L_REG_TAG(DST)) && X86_SIM_L_REG_TAG(SRC)==X86_SIM_TAG_SCALAR && \
                (__x86_l_alu==X86_ALU_ADD || __x86_l_alu==X86_ALU_SUB)) \
                X86_SIM_L_WRITE_REG_PTR_TAG((DST), KPROG_PTR_ADD64_BITS(X86_SIM_L_READ_REG_PTR(DST), \
                    __x86_l_alu==X86_ALU_ADD ? __x86_l_rhs : -__x86_l_rhs), \
                    KPROG_PTR_ADD64_TAG(X86_SIM_L_REG_TAG(DST))); \
            else if (__x86_l_width==X86_WIDTH_64 && __x86_l_dst_shift==0 && __x86_l_src_shift==0 && \
                __x86_l_alu==X86_ALU_ADD && X86_SIM_L_REG_TAG(DST)==X86_SIM_TAG_SCALAR && \
                X86_SIM_L_MEMORY_TAG(X86_SIM_L_REG_TAG(SRC))) \
                X86_SIM_L_WRITE_REG_PTR_TAG((DST), KPROG_PTR_ADD64_BITS(X86_SIM_L_READ_REG_PTR(SRC),__x86_l_lhs), \
                    KPROG_PTR_ADD64_TAG(X86_SIM_L_REG_TAG(SRC))); \
            else \
			X86_SIM_L_WRITE_REG_WIDTH_SHIFT((DST), __x86_l_result,\
				__x86_l_width, __x86_l_dst_shift);           \
		}                                                         \
	} while (0)

#define X86_SIM_L_EXEC_ALU_MEM(DST, SRC, FLAGS, AUX, IMM)                   \
	do { \
        if (X86_SIM_L_READ_RECOVERY_MEM(SRC, DST, (AUX), x86_simm(IMM))) break; \
		__u8 __x86_l_width = X86_SIM_L_EFFECTIVE_WIDTH(FLAGS);    \
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
	do { \
        if (X86_SIM_L_READ_RECOVERY_MEM(DST, X86_REG_NONE, (AUX), x86_simm(IMM))) break; \
		__u8 __x86_l_width = X86_SIM_L_EFFECTIVE_WIDTH(FLAGS);    \
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
		if (KPROG_X86_REG_PRESENT(DST))                           \
			__x86_l_base_ptr = X86_SIM_L_READ_REG_PTR(DST);    \
		if ((DST) == X86_RSP)                                     \
			X86_SIM_L_STACK_WRITE(                            \
				(__s64)(long)__x86_l_base_ptr + __x86_l_disp,\
				__x86_l_width, __x86_l_result);          \
		else {                                                    \
			void *__x86_l_addr = KPROG_PTR_ADD64_BITS(__x86_l_base_ptr, __x86_l_disp);               \
			X86_SIM_L_WRITE_MEM_VALUE((DST),__x86_l_disp,__x86_l_addr,                \
					     __x86_l_width, __x86_l_result);\
		}                                                         \
	} while (0)

#define X86_SIM_L_EXEC_ALU_MEM_IMM(DST, FLAGS, AUX, IMM)                    \
	do { \
        if (X86_SIM_L_READ_RECOVERY_MEM(DST, X86_REG_NONE, (AUX), x86_store_imm_disp(IMM))) break; \
		__u8 __x86_l_width = X86_SIM_L_EFFECTIVE_WIDTH(FLAGS);    \
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
		if (KPROG_X86_REG_PRESENT(DST))                           \
			__x86_l_base_ptr = X86_SIM_L_READ_REG_PTR(DST);    \
		if ((DST) == X86_RSP)                                     \
			X86_SIM_L_STACK_WRITE(                            \
				(__s64)(long)__x86_l_base_ptr + __x86_l_disp,\
				__x86_l_width, __x86_l_result);          \
		else {                                                    \
			void *__x86_l_addr = KPROG_PTR_ADD64_BITS(__x86_l_base_ptr, __x86_l_disp);               \
			X86_SIM_L_WRITE_MEM_VALUE((DST),__x86_l_disp,__x86_l_addr,                \
					     __x86_l_width, __x86_l_result);\
		}                                                         \
	} while (0)

#define X86_SIM_L_EXEC_ALU_MEM_REG(DST, SRC, FLAGS, AUX, IMM)               \
	do { \
        if (X86_SIM_L_READ_RECOVERY_MEM(DST, X86_REG_NONE, (AUX), x86_simm(IMM))) break; \
		__u8 __x86_l_width = X86_SIM_L_EFFECTIVE_WIDTH(FLAGS);    \
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
		if (KPROG_X86_REG_PRESENT(DST))                           \
			__x86_l_base_ptr = X86_SIM_L_READ_REG_PTR(DST);    \
		if ((DST) == X86_RSP)                                     \
			X86_SIM_L_STACK_WRITE(                            \
				(__s64)(long)__x86_l_base_ptr + __x86_l_disp,\
				__x86_l_width, __x86_l_result);          \
		else {                                                    \
			void *__x86_l_addr = KPROG_PTR_ADD64_BITS(__x86_l_base_ptr, __x86_l_disp);               \
			X86_SIM_L_WRITE_MEM_VALUE((DST),__x86_l_disp,__x86_l_addr,                \
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
	do { \
        if ((OP_IS_MEM) && X86_SIM_L_READ_RECOVERY_MEM(SRC, DST, (AUX), x86_simm(IMM))) break; \
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
		X86_SIM_L_SET_BZHI_FLAGS(__x86_l_count, __x86_l_bits,    \
					 __x86_l_result);                  \
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
	do { \
        if ((OP_IS_MEM) && X86_SIM_L_READ_RECOVERY_MEM(DST, X86_REG_NONE, (AUX), x86_store_imm_disp(IMM))) break; \
		__u8 __x86_l_width =                                      \
			KPROG_X86_BT_WRITE_WIDTH(FLAGS);                  \
		__u64 __x86_l_base;                                       \
		if (KPROG_X86_BT_BASE_SOURCE(OP_IS_MEM) ==                \
		    KPROG_X86_BT_BASE_MEMORY)                             \
			__x86_l_base = X86_SIM_L_READ_MEM_VALUE(          \
				(DST), (AUX), (IMM),     \
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
		__u8 __x86_l_width = X86_SIM_L_EFFECTIVE_WIDTH(FLAGS);    \
		__u64 __x86_l_lhs = X86_SIM_L_READ_REG(SRC);             \
		__u64 __x86_l_rhs = x86_sign_extend((IMM), __x86_l_width);\
		__u64 __x86_l_result = __x86_l_lhs * __x86_l_rhs;        \
		X86_SIM_L_SET_IMUL_FLAGS(__x86_l_lhs, __x86_l_rhs,       \
					 __x86_l_width);                 \
		X86_SIM_L_WRITE_REG_WIDTH((DST), __x86_l_result,         \
					  __x86_l_width);                    \
	} while (0)

#define X86_SIM_L_EXEC_IMUL_MEM_IMM(DST, SRC, FLAGS, AUX, IMM)              \
	do { \
        if (X86_SIM_L_READ_RECOVERY_MEM(SRC, DST, (AUX), x86_store_imm_disp(IMM))) break; \
		__u8 __x86_l_width = X86_SIM_L_EFFECTIVE_WIDTH(FLAGS);    \
		__u8 __x86_l_mem_width = X86_MEM_AUX_MEM_WIDTH(AUX);     \
		if (!__x86_l_mem_width)                                  \
			__x86_l_mem_width = __x86_l_width;                \
		__u64 __x86_l_lhs = X86_SIM_L_READ_MEM_VALUE((SRC),      \
			(AUX), (IMM), __x86_l_mem_width,\
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
		__u8 __x86_l_width = X86_SIM_L_EFFECTIVE_WIDTH(FLAGS);    \
		__u64 __x86_l_lhs = X86_SIM_L_READ_REG(X86_RDX);         \
		__u64 __x86_l_rhs = X86_SIM_L_READ_REG(SRC);             \
		__u64 __x86_l_low;                                       \
		__u64 __x86_l_high;                                      \
		if (KPROG_X86_MULX_ARM(__x86_l_width) ==                  \
		    KPROG_X86_MULX_ARM_SINGLE_PRODUCT) {                  \
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
		if (KPROG_X86_REG_PRESENT(AUX))                           \
			X86_SIM_L_WRITE_REG_WIDTH((AUX), __x86_l_high,    \
						  __x86_l_width);        \
	} while (0)

/* REP STOS in the native ABI's clear-DF profile uses the full RCX count. */
#define X86_SIM_L_EXEC_REP_STOS(WIDTH)                                    \
    do {                                                                 \
        __u8 __x86_stos_width = X86_SIM_L_EFFECTIVE_WIDTH(WIDTH);           \
        __u64 __x86_stos_count = X86_SIM_L_READ_REG(X86_RCX);              \
        __u64 __x86_stos_value = X86_SIM_L_READ_REG(X86_RAX);              \
        void *__x86_stos_dst = X86_SIM_L_READ_REG_PTR(X86_RDI);            \
        __u8 __x86_stos_tag = X86_SIM_L_REG_TAG(X86_RDI);                  \
        for (__u64 __x86_stos_i = 0; __x86_stos_i < __x86_stos_count;       \
             ++__x86_stos_i)                                             \
            X86_SIM_L_STORE_ADDR_TAGGED(                                 \
                KPROG_PTR_ADD64_BITS(__x86_stos_dst,                       \
                    __x86_stos_i * __x86_stos_width),                     \
                __x86_stos_width, __x86_stos_value, __x86_stos_tag);        \
        X86_SIM_L_WRITE_REG_PTR_TAG(X86_RDI,                              \
            KPROG_PTR_ADD64_BITS(__x86_stos_dst,                           \
                __x86_stos_count * __x86_stos_width), __x86_stos_tag);      \
        X86_SIM_L_WRITE_REG_WIDTH(X86_RCX, 0, X86_WIDTH_64);               \
    } while (0)

#define X86_SIM_L_REP_MOVS_ONE(WIDTH, INDEX)                                \
	do {                                                               \
		if (__x86_l_i == (INDEX) && __x86_l_i < __x86_l_count) {  \
			void *__x86_l_src_addr = KPROG_PTR_ADD64_BITS(__x86_l_src_ptr,\
				(__x86_l_i * (WIDTH)));                    \
			void *__x86_l_dst_addr = KPROG_PTR_ADD64_BITS(__x86_l_dst_ptr,\
				(__x86_l_i * (WIDTH)));                    \
			__u64 __x86_l_value = X86_SIM_L_LOAD_ADDR_TAGGED(       \
				__x86_l_src_addr, (WIDTH), __x86_l_src_tag);              \
			X86_SIM_L_STORE_ADDR_TAGGED(__x86_l_dst_addr, (WIDTH),  \
					     __x86_l_value, __x86_l_dst_tag);              \
		}                                                         \
	} while (0)

#define X86_SIM_L_EXEC_REP_MOVS(FLAGS, IMM)                                  \
	do {                                                               \
		__u8 __x86_l_width = KPROG_X86_REP_MOVS_WIDTH(FLAGS);    \
		__u64 __x86_l_count = X86_SIM_L_READ_REG(X86_RCX);                             \
		void *__x86_l_src_ptr = X86_SIM_L_READ_REG_PTR(X86_RSI); \
		void *__x86_l_dst_ptr = X86_SIM_L_READ_REG_PTR(X86_RDI); \
		__u8 __x86_l_src_tag = X86_SIM_L_REG_TAG(X86_RSI);       \
		__u8 __x86_l_dst_tag = X86_SIM_L_REG_TAG(X86_RDI);       \
		__u64 __x86_l_i;                                         \
		for (__x86_l_i = 0; __x86_l_i < __x86_l_count; \
			__x86_l_i++) {                                           \
            if (X86_SIM_L_READ_RECOVERY_AT(X86_RSI, X86_RCX, (__u64)(unsigned long)__x86_l_src_ptr + __x86_l_i * __x86_l_width)) { \
                __x86_l_count = __x86_l_i; break; \
            } \
			X86_SIM_L_REP_MOVS_ONE(__x86_l_width, __x86_l_i); \
        } \
		X86_SIM_L_WRITE_REG_PTR_TAG(X86_RSI,                     \
			KPROG_PTR_ADD64_BITS(__x86_l_src_ptr, __x86_l_count * __x86_l_width),\
			__x86_l_src_tag);                                \
		X86_SIM_L_WRITE_REG_PTR_TAG(X86_RDI,                     \
			KPROG_PTR_ADD64_BITS(__x86_l_dst_ptr, __x86_l_count * __x86_l_width),\
			__x86_l_dst_tag);                                \
		X86_SIM_L_WRITE_REG_WIDTH(X86_RCX, 0,                     \
			KPROG_X86_REP_MOVS_COUNT_WIDTH);                         \
	} while (0)

/* Copy/fill uses the exact native 64-bit count, without a simulator cap. */
#define X86_SIM_L_EXEC_CALL_MEM_STEP(IMM, OP_IS_COPY, OP_IS_REG)             \
	do {                                                               \
		void *__x86_l_dst_ptr = X86_SIM_L_READ_REG_PTR(X86_RDI);    \
		void *__x86_l_src_ptr = X86_SIM_L_READ_REG_PTR(X86_RSI);    \
		__u64 __x86_l_value = X86_SIM_L_READ_REG(X86_RSI);          \
		__u64 __x86_l_count;                                      \
		__u64 __x86_l_i;                                          \
		if (KPROG_X86_CALLMEM_COUNT_SOURCE(OP_IS_REG) ==          \
		    KPROG_X86_CALLMEM_COUNT_REG)                          \
			__x86_l_count = X86_SIM_L_READ_REG(X86_RDX);       \
		else                                                     \
			__x86_l_count = (IMM);                            \
		for (__x86_l_i = 0; __x86_l_i < __x86_l_count;            \
		     __x86_l_i++) {                                      \
			__u64 __x86_l_byte;                               \
			if (KPROG_X86_CALLMEM_KIND(OP_IS_COPY) ==          \
			    KPROG_X86_CALLMEM_COPY)                      \
				__x86_l_byte = X86_SIM_L_LOAD_ADDR_TAGGED(       \
					KPROG_PTR_ADD64_BITS(             \
						__x86_l_src_ptr, __x86_l_i), \
					X86_WIDTH_8, X86_SIM_L_REG_TAG(X86_RSI));                    \
			else                                             \
				__x86_l_byte = __x86_l_value & 0xff;     \
			X86_SIM_L_STORE_ADDR_TAGGED(                            \
				KPROG_PTR_ADD64_BITS(__x86_l_dst_ptr,     \
						    __x86_l_i),          \
				X86_WIDTH_8, __x86_l_byte, X86_SIM_L_REG_TAG(X86_RDI));              \
		}                                                        \
		X86_SIM_L_WRITE_REG_PTR_TAG(X86_RAX, __x86_l_dst_ptr,     \
					    X86_SIM_L_REG_TAG(X86_RDI)); \
		X86_SIM_L_HELPER_CLOBBERS();                             \
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
	do { \
        if ((OP_IS_MEM) && X86_SIM_L_READ_RECOVERY_MEM(X86_REG_AUX_GET_SRC_SHIFT(AUX), DST, (AUX), x86_store_imm_disp(IMM))) break; \
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
		__x86_pf = X86_SIM_L_UNSPECIFIED() & 1;                  \
		__x86_af = X86_SIM_L_UNSPECIFIED() & 1;                  \
		X86_SIM_L_WRITE_REG_WIDTH((DST), __x86_l_result,          \
					  __x86_l_width);                    \
	} while (0)

#define X86_SIM_L_EXEC_ANDN(DST, SRC, AUX, FLAGS)                           \
	X86_SIM_L_EXEC_ANDN_STEP(0U, (DST), (SRC), (AUX), (FLAGS), 0U)

#define X86_SIM_L_EXEC_ANDN_MEM(DST, SRC, FLAGS, AUX, IMM)                  \
	X86_SIM_L_EXEC_ANDN_STEP(1U, (DST), (SRC), (AUX), (FLAGS), (IMM))

/* The `CMP` / `TEST` handler-composition contract selects the left-hand-side
 * source (destination register or addressed memory), the right-hand-side source
 * (decoded immediate or register), the flag kind (zero-borrow subtraction or
 * logical), the `FLAGS`-resolved width, and — for the memory forms — the
 * displacement kind (the whole immediate as a signed displacement, or the high
 * 32 bits as a store displacement). The eight bodies route through this one step
 * so the register forms (which read `SRC` at the resolved width and lane) and
 * the memory forms (which load the operand from the addressed bytes and read
 * `SRC` whole at 64 bits, letting the flag production narrow it) cannot drift. */
#define X86_SIM_L_EXEC_CMP_STEP(OP_IS_MEM, OP_IS_TEST, RHS_IS_REG,          \
				OP_IS_CMP_MEM_REG, DST, SRC, FLAGS, AUX,    \
				IMM)                                        \
	do { \
        if ((OP_IS_MEM) && X86_SIM_L_READ_RECOVERY_MEM(DST, X86_REG_NONE, (AUX), (KPROG_X86_CMPOP_DISP_KIND(OP_IS_CMP_MEM_REG) == KPROG_X86_CMPOP_DISP_STORE ? x86_store_imm_disp(IMM) : x86_simm(IMM)))) break; \
		__u8 __x86_l_width =                                       \
			KPROG_X86_CMPOP_WRITE_WIDTH(FLAGS);                \
		__u32 __x86_l_aux = (AUX);                                 \
		__u64 __x86_l_lhs;                                         \
		if (KPROG_X86_CMPOP_LHS_SOURCE(OP_IS_MEM) ==               \
		    KPROG_X86_CMPOP_LHS_MEMORY)                            \
			__x86_l_lhs = X86_SIM_L_READ_MEM_VALUE((DST),      \
				(AUX), (IMM), __x86_l_width,               \
				KPROG_X86_CMPOP_DISP_KIND(                  \
					OP_IS_CMP_MEM_REG) ==               \
					KPROG_X86_CMPOP_DISP_STORE);        \
		else                                                       \
			__x86_l_lhs = X86_SIM_L_READ_REG_WIDTH_SHIFT(      \
				(DST), __x86_l_width,                      \
				KPROG_X86_REG_LANE_AUX_DST_SHIFT(          \
					__x86_l_aux));                     \
		__u64 __x86_l_rhs;                                         \
		if (KPROG_X86_CMPOP_RHS_SOURCE(RHS_IS_REG) ==              \
		    KPROG_X86_CMPOP_RHS_REGISTER) {                        \
			if (KPROG_X86_CMPOP_LHS_SOURCE(OP_IS_MEM) ==       \
			    KPROG_X86_CMPOP_LHS_MEMORY)                    \
				__x86_l_rhs = X86_SIM_L_READ_REG((SRC));   \
			else                                               \
				__x86_l_rhs =                              \
					X86_SIM_L_READ_REG_WIDTH_SHIFT(    \
						(SRC), __x86_l_width,      \
						KPROG_X86_REG_LANE_AUX_SRC_SHIFT(\
							__x86_l_aux));    \
		} else {                                                   \
			__x86_l_rhs = x86_store_imm_value((IMM),           \
							  __x86_l_width);   \
		}                                                          \
		if (KPROG_X86_CMPOP_FLAG_KIND(OP_IS_TEST) ==               \
		    KPROG_X86_CMPOP_FLAGS_LOGIC)                           \
			X86_SIM_L_SET_LOGIC_FLAGS(                         \
				__x86_l_lhs & __x86_l_rhs, __x86_l_width);  \
		else {                                                     \
			X86_SIM_L_SET_SUB_FLAGS(__x86_l_lhs, __x86_l_rhs,  \
				KPROG_X86_SBB_RESULT(__x86_l_lhs,          \
					__x86_l_rhs, 0), __x86_l_width);   \
			/* For CMP's exact subtraction, SF xor OF is signed LT. */ \
			__x86_of = __x86_sf ^                            \
				((__s64)x86_sign_extend(__x86_l_lhs, __x86_l_width) < \
				 (__s64)x86_sign_extend(__x86_l_rhs, __x86_l_width)); \
		}                                                          \
	} while (0)

#define X86_SIM_L_EXEC_CMP_MEM(OP, DST, SRC, FLAGS, AUX, IMM)               \
	X86_SIM_L_EXEC_CMP_STEP(1U,                                        \
		(OP) == X86_OP_TEST_MEM_IMM || (OP) == X86_OP_TEST_MEM_REG,\
		(OP) == X86_OP_CMP_MEM_REG || (OP) == X86_OP_TEST_MEM_REG, \
		(OP) == X86_OP_CMP_MEM_REG, (DST), (SRC), (FLAGS), (AUX),  \
		(IMM))

#define X86_SIM_L_EXEC_CMP_REG_MEM(DST, SRC, FLAGS, AUX, IMM)               \
	do { \
        if (X86_SIM_L_READ_RECOVERY_MEM(SRC, X86_REG_NONE, (AUX), x86_simm(IMM))) break; \
		__u8 __x86_l_width = X86_SIM_L_EFFECTIVE_WIDTH(FLAGS);    \
		__u64 __x86_l_lhs = X86_SIM_L_READ_REG(DST);             \
		__u64 __x86_l_rhs = X86_SIM_L_READ_MEM_VALUE((SRC), (AUX),\
			(IMM), __x86_l_width, 0);                         \
		X86_SIM_L_SET_SUB_FLAGS(__x86_l_lhs, __x86_l_rhs,        \
			KPROG_X86_SBB_RESULT(__x86_l_lhs, __x86_l_rhs, 0),\
			__x86_l_width);                                     \
	} while (0)

#define X86_SIM_L_EXEC_MOV_IMM_AUX(DST, FLAGS, AUX, IMM)                    \
	do {                                                               \
		__u8 __x86_l_width = X86_SIM_L_EFFECTIVE_WIDTH(FLAGS);    \
		X86_SIM_L_WRITE_REG_WIDTH_SHIFT((DST), (IMM), __x86_l_width,\
			KPROG_X86_REG_LANE_AUX_DST_SHIFT(AUX));              \
	} while (0)

#define X86_SIM_L_EXEC_MOV_IMM(DST, FLAGS, IMM)                             \
	X86_SIM_L_EXEC_MOV_IMM_AUX((DST), (FLAGS), 0U, (IMM))

/* Full-width MOV keeps source selection separate from native destination writeback. */
#define X86_SIM_L_WRITE_MOV_REG_PTR(DST, SRC, VALUE, TAG)                   \
	do {                                                               \
        if ((DST)==X86_RSP && (TAG)==X86_SIM_TAG_STACK) \
            X86_SIM_L_WRITE_REG_PTR_TAG((DST), (void *)(long)X86_SIM_L_STACK_ALIAS_OFFSET(VALUE), X86_SIM_TAG_SCALAR); \
        else if (KPROG_X86_MOV_REG_ARM(KPROG_X86_MOV_REG_FULL_WIDTH, (DST)) == KPROG_X86_MOV_REG_ARM_STACK_PTR) \
			X86_SIM_L_WRITE_REG_WIDTH((DST), X86_SIM_L_READ_REG(SRC), KPROG_X86_MOV_REG_FULL_WIDTH); \
		else                                                       \
			X86_SIM_L_WRITE_REG_PTR_TAG((DST), (VALUE), (TAG)); \
	} while (0)

#define X86_SIM_L_EXEC_MOV_REG_AUX(DST, SRC, FLAGS, AUX)                    \
	do {                                                               \
		__u8 __x86_l_width = X86_SIM_L_EFFECTIVE_WIDTH(FLAGS);    \
		if (KPROG_X86_MOV_REG_ARM(__x86_l_width, (SRC)) ==         \
		    KPROG_X86_MOV_REG_ARM_STACK_PTR) {                     \
			X86_SIM_L_WRITE_MOV_REG_PTR((DST), (SRC),                \
				X86_SIM_L_STACK_PTR(                       \
					(__s64)(long)X86_SIM_L_READ_REG_PTR(SRC)),\
				X86_SIM_TAG_STACK);                        \
		} else if (KPROG_X86_MOV_REG_ARM(__x86_l_width, (SRC)) ==  \
			   KPROG_X86_MOV_REG_ARM_POINTER) {               \
			X86_SIM_L_WRITE_MOV_REG_PTR((DST), (SRC),                \
				X86_SIM_L_READ_REG_PTR(SRC),              \
				X86_SIM_L_REG_TAG(SRC));                  \
		} else if (KPROG_X86_MOV_REG_ARM(__x86_l_width, (SRC)) ==  \
			   KPROG_X86_MOV_REG_ARM_NARROW) {                \
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
		__u8 __x86_l_width = X86_SIM_L_EFFECTIVE_WIDTH(FLAGS);    \
		__u8 __x86_l_src_width =                                  \
			KPROG_X86_MOVX_SRC_WIDTH((AUX), __x86_l_width);   \
		__u8 __x86_l_shape = KPROG_X86_MOVX_SHAPE((OP));          \
		__u64 __x86_l_value = X86_SIM_L_READ_REG_WIDTH_SHIFT(   \
			KPROG_X86_MOVX_SOURCE_REG(SRC), __x86_l_src_width, \
			KPROG_X86_MOVX_SOURCE_SHIFT(SRC));            \
		if (__x86_l_shape ==                                      \
		    KPROG_X86_MOVX_SHAPE_SIGN_EXTEND) {                   \
			__x86_l_value = x86_sign_extend(__x86_l_value,    \
				__x86_l_src_width);                       \
		} else {                                                  \
			__x86_l_value = x86_apply_width(__x86_l_value,    \
				__x86_l_src_width);                       \
		}                                                         \
		if (__x86_l_width == X86_WIDTH_32) {                    \
			__u32 __x86_l_lane32 = (__u32)__x86_l_value;      \
			__asm__("" : "+r"(__x86_l_lane32));              \
			__x86_l_value = __x86_l_lane32;                    \
		} else __asm__("" : "+r"(__x86_l_value));               \
		X86_SIM_L_WRITE_REG_WIDTH((DST), __x86_l_value,           \
					  __x86_l_width);                    \
	} while (0)

#define X86_SIM_L_EXEC_CMP_IMM_OP_AUX(OP, DST, FLAGS, AUX, IMM)             \
	X86_SIM_L_EXEC_CMP_STEP(0U, (OP) == X86_OP_TEST_IMM, 0U, 0U, (DST),\
				0U, (FLAGS), (AUX), (IMM))

#define X86_SIM_L_EXEC_CMP_IMM_OP(OP, DST, FLAGS, IMM)                      \
	X86_SIM_L_EXEC_CMP_IMM_OP_AUX((OP), (DST), (FLAGS), 0U, (IMM))

#define X86_SIM_L_EXEC_CMP_REG_OP_AUX(OP, DST, SRC, FLAGS, AUX)             \
	X86_SIM_L_EXEC_CMP_STEP(0U, (OP) == X86_OP_TEST_REG, 1U, 0U, (DST),\
				(SRC), (FLAGS), (AUX), 0U)

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
/* Intel SDM CMOVcc: the source is read even when the condition is false.
 * Keep that read observable to clang; a plain unused load can be eliminated.
 * A false 32-bit CMOV still clears the destination's upper 32 bits. */
#define X86_SIM_L_EXEC_CMOV_STEP(RHS_IS_MEM, DST, SRC, FLAGS, AUX, IMM)     \
	do { \
        if ((RHS_IS_MEM) && X86_SIM_L_READ_RECOVERY_MEM(SRC, DST, (AUX), KPROG_X86_CMOV_MEM_DISP(IMM))) break; \
		__u32 __x86_l_cc = (RHS_IS_MEM) ?                         \
			(__u32)KPROG_X86_CMOV_MEM_CONDITION(AUX) :        \
			(__u32)KPROG_X86_CMOV_CONDITION(AUX);             \
		__u8 __x86_l_width = KPROG_X86_CMOV_WIDTH(FLAGS);         \
		__u8 __x86_l_cmw = (RHS_IS_MEM) ?                         \
			KPROG_X86_CMOV_MEM_WIDTH(AUX, FLAGS) : __x86_l_width; \
		__u64 __x86_l_value;                                      \
		if (RHS_IS_MEM) {                                        \
			volatile __u64 __x86_l_mem_value =                \
				X86_SIM_L_READ_MEM_VALUE((SRC), (AUX),    \
					KPROG_X86_CMOV_MEM_DISP(IMM), __x86_l_cmw, 0); \
			__x86_l_value = __x86_l_mem_value;                 \
		} else {                                                \
			__x86_l_value = X86_SIM_L_READ_REG(SRC);           \
		}                                                       \
		if (X86_SIM_L_EVAL_CC(__x86_l_cc)) {                      \
			__u8 __x86_l_wb = KPROG_X86_CMOV_WRITEBACK(       \
				__x86_l_width == X86_WIDTH_64);           \
			if (__x86_l_wb ==                                 \
			    KPROG_X86_CMOV_WRITEBACK_POINTER_TAG) {       \
				if (RHS_IS_MEM)                           \
					X86_SIM_L_WRITE_REG_WIDTH((DST), __x86_l_value, __x86_l_width); \
				else                                      \
					X86_SIM_L_WRITE_MOV_REG_PTR((DST), (SRC), \
						(SRC) == X86_RSP ? X86_SIM_L_STACK_PTR((__s64)(long)X86_SIM_L_READ_REG_PTR(SRC)) : X86_SIM_L_READ_REG_PTR(SRC), \
						(SRC) == X86_RSP ? X86_SIM_TAG_STACK : X86_SIM_L_REG_TAG(SRC)); \
			}                                                \
			else                                              \
				X86_SIM_L_WRITE_REG_WIDTH((DST),          \
					__x86_l_value, __x86_l_width);    \
		} else if (__x86_l_width == X86_WIDTH_32) {                  \
			X86_SIM_L_WRITE_REG_WIDTH((DST),                         \
				X86_SIM_L_READ_REG(DST), X86_WIDTH_32);              \
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
 * which byte receives the condition rather than restating the test. The
 * register form's condition byte passes through the contract's matched fold
 * before the evaluation, which is the identity on the accepted subset and
 * the no-match sentinel elsewhere; the Lean refinement pins that route to
 * the raw evaluation. */
#define X86_SIM_L_EXEC_SETCC_STEP(DST, AUX)                                  \
	do {                                                                \
		__u8 __x86_l_sc_shift =                                     \
			KPROG_X86_REG_LANE_AUX_DST_SHIFT(AUX);              \
		__u8 __x86_l_sc_lane = KPROG_X86_SETCC_LANE(                \
			__x86_l_sc_shift);                                   \
		X86_SIM_L_WRITE_REG_WIDTH_SHIFT((DST),                      \
			X86_SIM_L_EVAL_CC(                                           \
				KPROG_X86_FULL_CONDITION_MATCHED(                            \
					KPROG_X86_REG_LANE_AUX_PAYLOAD(AUX))),                     \
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
			X86_SIM_L_STORE_ADDR_TAGGED(                               \
				(__u8 *)__x86_l_scm_base +                   \
					__x86_l_scm_disp,                    \
				KPROG_X86_SETCC_MEM_WIDTH_CODE,              \
				__x86_l_scm_value, X86_SIM_L_REG_TAG(DST));                          \
	} while (0)

/* Operand-sized transfers. POP increments old RSP before destination write,
 * so POP RSP/SP does not add the step to the value just popped. */
#define X86_SIM_L_EXEC_PUSH_POP_STEP(IS_POP, DST, SRC, FLAGS)               \
	do { \
        if ((IS_POP) && X86_SIM_L_READ_RECOVERY(X86_RSP, DST)) break; \
		__u8 __x86_l_pp_dir = KPROG_X86_PUSH_STEP_DIRECTION(IS_POP); \
		__u8 __x86_l_pp_flags_width =                             \
			KPROG_X86_PUSH_FLAGS_WIDTH(                       \
				(FLAGS) == KPROG_X86_PUSH_WIDTH_ABSENT);  \
		__u8 __x86_l_pp_width =                                   \
			(__x86_l_pp_flags_width ==                        \
			 KPROG_X86_PUSH_FLAGS_ABSENT) ?                   \
				X86_WIDTH_64 : (FLAGS);                   \
		__u64 __x86_l_pp_step =                                   \
			(__u64)KPROG_X86_PUSH_STEP_BYTES(__x86_l_pp_width);\
		if (__x86_l_pp_dir ==                                     \
		    KPROG_X86_PUSH_STEP_PRE_DECREMENT) {                  \
			__u64 __x86_l_pp_value = X86_SIM_L_READ_REG(SRC); \
			__x86_rsp.ptr =                                   \
				KPROG_PTR_ADD64_BITS(__x86_rsp.ptr, -__x86_l_pp_step);  \
			X86_SIM_L_STACK_WRITE(                            \
				(__s64)(long)__x86_rsp.ptr,               \
				__x86_l_pp_width, __x86_l_pp_value);      \
		} else {                                                  \
			__u64 __x86_l_pp_value = X86_SIM_L_STACK_READ(    \
				(__s64)(long)__x86_rsp.ptr,               \
				__x86_l_pp_width);                        \
			__x86_rsp.ptr =                                   \
				KPROG_PTR_ADD64_BITS(__x86_rsp.ptr, __x86_l_pp_step); \
            X86_SIM_L_STACK_RELEASE((__s64)(long)__x86_rsp.ptr - __x86_l_pp_step);  \
			X86_SIM_L_WRITE_REG_WIDTH((DST),                  \
				__x86_l_pp_value, __x86_l_pp_width);      \
		}                                                         \
	} while (0)

#define X86_SIM_L_EXEC_PUSH(SRC, FLAGS)                                             \
	X86_SIM_L_EXEC_PUSH_POP_STEP(0U, X86_REG_NONE, (SRC), (FLAGS))

#define X86_SIM_L_EXEC_POP(DST, FLAGS)                                       \
	X86_SIM_L_EXEC_PUSH_POP_STEP(1U, (DST), X86_REG_NONE, (FLAGS))

/* Memory PUSH reads using old RSP; memory POP forms its effective address
 * after incrementing RSP. Keep the actual transfer raw, like other memory ops. */
#define X86_SIM_L_EXEC_PUSH_OP(SRC, FLAGS, AUX, IMM)                         \
	do { \
        if (X86_PUSHPOP_AUX_MODE(AUX) == 2U && X86_SIM_L_READ_RECOVERY_MEM(SRC, X86_REG_NONE, (AUX), x86_simm(IMM))) break; \
		if (X86_PUSHPOP_AUX_MODE(AUX) != 1U && X86_PUSHPOP_AUX_MODE(AUX) != 2U) {                     \
			X86_SIM_L_EXEC_PUSH((SRC), (FLAGS));               \
		} else {                                                    \
			__u8 __x86_pp_width = (FLAGS) ? (FLAGS) : X86_WIDTH_64; \
			__u64 __x86_pp_value =                             \
				X86_PUSHPOP_AUX_MODE(AUX) == 1U ? (__u64)(IMM) : \
				X86_SIM_L_READ_MEM_VALUE((SRC), (AUX), (IMM), \
					__x86_pp_width, 0);                    \
			__x86_rsp.ptr = KPROG_PTR_ADD64_BITS(__x86_rsp.ptr, -(__u64)KPROG_X86_PUSH_STEP_BYTES(__x86_pp_width));  \
			X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr,  \
				__x86_pp_width, __x86_pp_value);            \
		}                                                           \
	} while (0)

#define X86_SIM_L_EXEC_POP_OP(DST, FLAGS, AUX, IMM)                          \
	do { \
        if (X86_PUSHPOP_AUX_MODE(AUX) == 2U && X86_SIM_L_READ_RECOVERY(X86_RSP, X86_REG_NONE)) break; \
		if (X86_PUSHPOP_AUX_MODE(AUX) != 2U) {                     \
			X86_SIM_L_EXEC_POP((DST), (FLAGS));                \
		} else {                                                    \
			__u8 __x86_pp_width = (FLAGS) ? (FLAGS) : X86_WIDTH_64; \
			__u64 __x86_pp_value = X86_SIM_L_STACK_READ(       \
				(__s64)(long)__x86_rsp.ptr, __x86_pp_width); \
			__x86_rsp.ptr = KPROG_PTR_ADD64_BITS(__x86_rsp.ptr, (__u64)KPROG_X86_PUSH_STEP_BYTES(__x86_pp_width)); \
            X86_SIM_L_STACK_RELEASE((__s64)(long)__x86_rsp.ptr - KPROG_X86_PUSH_STEP_BYTES(__x86_pp_width));  \
			__s64 __x86_pp_disp = X86_SIM_L_MEM_OFFSET((AUX), x86_simm(IMM)); \
			if ((DST) == X86_RSP)                              \
				X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr + \
					__x86_pp_disp, __x86_pp_width, __x86_pp_value); \
			else                                                       \
				X86_SIM_L_STORE_ADDR_TAGGED((__u8 *)X86_SIM_L_READ_REG_PTR(DST) + \
					__x86_pp_disp, __x86_pp_width, __x86_pp_value, X86_SIM_L_REG_TAG(DST)); \
		}                                                           \
	} while (0)

#define X86_SIM_L_EXEC_PTR_LOAD(OP, DST, AUX, IMM) \
	do { \
			__u8 __x86_l_pw_tag =                             \
				KPROG_X86_PTR_WRITE_SOURCE_TAG(           \
					(OP) == X86_OP_MOV_LOAD_MAP_PTR,   \
					(OP) == X86_OP_MOV_LOAD_HELPER_ID, (AUX));\
			if (KPROG_X86_PTR_WRITE_IS_HELPER_ID(             \
				    __x86_l_pw_tag))                      \
				X86_SIM_L_WRITE_REG_WIDTH((DST), (IMM), \
							  X86_WIDTH_64);\
			X86_SIM_L_WRITE_REG_PTR_TAG((DST),                \
				(void *)(long)((__u64)(IMM) -              \
					((DST) == X86_RSP ?                \
					 __x86_native_stack_base : 0)),     \
				__x86_l_pw_tag);                          \
	} while (0)

/* Native architectural faults reach the existing verifier-visible memory
 * fault arm. Native #DE and UD2/#UD retain their faulting control paths. */
#if defined(__bpf__)
#define X86_SIM_L_ARCHITECTURAL_FAULT() do {                                    \
    __asm__ volatile("r0 = 0; *(u64 *)(r0 + 0) = r0; exit;" ::: "r0", "memory"); \
    __builtin_unreachable();                                             \
} while (0)
#else
#define X86_SIM_L_ARCHITECTURAL_FAULT() __builtin_trap()
#endif

#define X86_SIM_L_DIVIDE_FAULT() X86_SIM_L_ARCHITECTURAL_FAULT()
#define X86_SIM_L_INVALID_OPCODE_FAULT() X86_SIM_L_ARCHITECTURAL_FAULT()

struct x86_sim_divmod64 {
    __u64 quotient;
    __u64 remainder;
};

/* Exact radix-two division of the complete high:low pair. The caller has
 * established divisor != 0 and high < divisor, so the quotient fits 64 bits.
 * Every input bit is consumed once; this loop is the arithmetic algorithm. */
static __always_inline struct x86_sim_divmod64
x86_sim_divmod128(__u64 high, __u64 low, __u64 divisor)
{
    struct x86_sim_divmod64 result = {0, high};
#ifdef __clang__
#pragma unroll
#endif
    for (int bit = 63; bit >= 0; --bit) {
        __u64 carry = result.remainder >> 63;
        result.remainder = (result.remainder << 1) | ((low >> bit) & 1ULL);
        result.quotient <<= 1;
        if (carry || result.remainder >= divisor) {
            result.remainder -= divisor;
            result.quotient |= 1ULL;
        }
    }
    return result;
}

/*
 * The opcode dispatch chain.
 *
 * The chain has no final `else`, deliberately. The AMD64 simulator mirrors the
 * AArch64 one in every other respect, but not here: a non-member opcode is a
 * no-op by definition, and the two dispatch route hosts pin that as an
 * observable property -- they drive `X86_OP_RET`, which has no arm, and
 * require the whole state to come back byte-identical to its seed
 * (`test_x86_dispatch_{family,singleton}_route_host.c`). Non-membership is
 * therefore observable as an unchanged state rather than through a counter,
 * because the x86 chain carries no unsupported-opcode hook.
 *
 * This differs from the repo's fail-fast rule only in appearance. Unsupported
 * *input* still fails: the encoder raises before emitting an opcode it cannot
 * lower, so an unknown mnemonic never reaches this chain. An opcode that is
 * decoded but has no arm is a no-op because the two hosts above define it to
 * be one. Adding an `else` arm here would silently invalidate both hosts.
 */
#define X86_SIM_L_EXEC(OP, DST, SRC, FLAGS, AUX, IMM)                       \
	do {                                                               \
		__u8 __x86_l_width = X86_SIM_L_EFFECTIVE_WIDTH(FLAGS);    \
		if (KPROG_X86_DISP_NOP_HANDLED(OP)) {                      \
			(void)0;                                           \
		} else if (KPROG_X86_MOV_LOAD_PTR_HANDLED(OP)) {          \
			X86_SIM_L_EXEC_PTR_LOAD((OP), (DST), (AUX), (IMM)); \
		} else if (KPROG_X86_DISP_CALL_MEMCPY_HANDLED(OP)) {     \
			X86_SIM_L_EXEC_CALL_MEMCPY((IMM));                \
		} else if (KPROG_X86_DISP_CALL_MEMSET_HANDLED(OP)) {     \
			X86_SIM_L_EXEC_CALL_MEMSET((IMM));                \
		} else if (KPROG_X86_DISP_CALL_MEMCPY_REG_HANDLED(OP)) { \
			X86_SIM_L_EXEC_CALL_MEMCPY_REG((IMM));            \
		} else if (KPROG_X86_DISP_CALL_MEMSET_REG_HANDLED(OP)) { \
			X86_SIM_L_EXEC_CALL_MEMSET_REG((IMM));            \
		} else if (KPROG_X86_DISP_CALL_REG_HANDLED(OP)) {        \
			X86_SIM_BPF_CALL_REG((SRC));                      \
		} else if (KPROG_X86_DISP_MOV_IMM_HANDLED(OP)) {          \
			X86_SIM_L_WRITE_REG_WIDTH_SHIFT((DST), (IMM),         \
				__x86_l_width,                                \
				KPROG_X86_REG_LANE_AUX_DST_SHIFT(AUX));        \
		} else if (KPROG_X86_DISP_MOV_REG_HANDLED(OP)) {          \
			if (KPROG_X86_MOV_REG_ARM(__x86_l_width, (SRC)) ==\
			    KPROG_X86_MOV_REG_ARM_STACK_PTR) {            \
				X86_SIM_L_WRITE_MOV_REG_PTR((DST), (SRC),         \
					X86_SIM_L_STACK_PTR(               \
						(__s64)(long)X86_SIM_L_READ_REG_PTR(SRC)),\
					X86_SIM_TAG_STACK);                \
			} else if (KPROG_X86_MOV_REG_ARM(__x86_l_width,   \
				   (SRC)) ==                              \
				   KPROG_X86_MOV_REG_ARM_POINTER) {       \
				X86_SIM_L_WRITE_MOV_REG_PTR((DST), (SRC),         \
					X86_SIM_L_READ_REG_PTR(SRC),       \
					X86_SIM_L_REG_TAG(SRC));           \
			} else if (KPROG_X86_MOV_REG_ARM(__x86_l_width,   \
				   (SRC)) ==                              \
				   KPROG_X86_MOV_REG_ARM_NARROW) {        \
				__u64 __x86_l_value =                    \
					X86_SIM_L_READ_REG_WIDTH_SHIFT(   \
						(SRC), __x86_l_width,        \
						KPROG_X86_REG_LANE_AUX_SRC_SHIFT(AUX));\
				X86_SIM_L_WRITE_REG_WIDTH_SHIFT((DST),   \
					__x86_l_value, __x86_l_width,      \
					KPROG_X86_REG_LANE_AUX_DST_SHIFT(AUX));\
			}                                                 \
		} else if (KPROG_X86_MOVX_REG_HANDLED(OP)) {              \
			X86_SIM_L_EXEC_MOVX_REG((OP), (DST), (SRC), (FLAGS), (AUX)); \
		} else if (KPROG_X86_MOV_LOAD_HANDLED(OP)) {              \
				X86_SIM_L_EXEC_MOV_LOAD((OP), (DST), (SRC), (FLAGS),\
							(AUX), (IMM));          \
			} else if (KPROG_X86_DISP_MOVBE_LOAD_HANDLED(OP)) {     \
				X86_SIM_L_EXEC_MOVBE_LOAD((DST), (SRC), (FLAGS),\
							  (AUX), (IMM));     \
			} else if (KPROG_X86_MOV_STORE_HANDLED(OP)) {             \
				X86_SIM_L_EXEC_STORE((OP), (DST), (SRC), (FLAGS),  \
						     (AUX), (IMM));               \
		} else if (KPROG_X86_DISP_MOVBE_STORE_HANDLED(OP)) {     \
			X86_SIM_L_EXEC_MOVBE_STORE((DST), (SRC), (FLAGS),\
						   (AUX), (IMM));    \
		} else if (KPROG_X86_DISP_LOAD_XMM0_HANDLED(OP)) {       \
			X86_SIM_L_EXEC_LOAD_XMM0((SRC), (AUX), (IMM));   \
		} else if (KPROG_X86_DISP_STORE_XMM0_HANDLED(OP)) {      \
			X86_SIM_L_EXEC_STORE_XMM0((DST), (AUX), (IMM));  \
		} else if (KPROG_X86_DISP_LEA_HANDLED(OP)) {             \
			X86_SIM_L_EXEC_LEA((DST), (SRC), (FLAGS), (AUX), (IMM));\
		} else if (KPROG_X86_ALU_IMM_HANDLED(OP)) {               \
			X86_SIM_L_EXEC_ALU_IMM((DST), (FLAGS), (AUX), (IMM));\
		} else if (KPROG_X86_ALU_REG_HANDLED(OP)) {               \
			X86_SIM_L_EXEC_ALU_REG((DST), (SRC), (FLAGS), (AUX));\
		} else if (KPROG_X86_DISP_ALU_MEM_HANDLED(OP)) {         \
			X86_SIM_L_EXEC_ALU_MEM((DST), (SRC), (FLAGS), (AUX), (IMM));\
		} else if (KPROG_X86_DISP_ALU_MEM_UNARY_HANDLED(OP)) {   \
			X86_SIM_L_EXEC_ALU_MEM_UNARY((DST), (FLAGS), (AUX), (IMM));\
		} else if (KPROG_X86_DISP_ALU_MEM_IMM_HANDLED(OP)) {     \
			X86_SIM_L_EXEC_ALU_MEM_IMM((DST), (FLAGS), (AUX), (IMM));\
		} else if (KPROG_X86_DISP_ALU_MEM_REG_HANDLED(OP)) {     \
			X86_SIM_L_EXEC_ALU_MEM_REG((DST), (SRC), (FLAGS), (AUX), (IMM));\
		} else if (KPROG_X86_CMP_IMM_HANDLED(OP)) {               \
			X86_SIM_L_EXEC_CMP_IMM_OP_AUX((OP), (DST), (FLAGS),\
				(AUX), (IMM));                                 \
		} else if (KPROG_X86_CMP_REG_HANDLED(OP)) {               \
			X86_SIM_L_EXEC_CMP_REG_OP_AUX((OP), (DST), (SRC), \
				(FLAGS), (AUX));                              \
		} else if (KPROG_X86_CMP_MEM_HANDLED(OP)) {               \
			X86_SIM_L_EXEC_CMP_MEM((OP), (DST), (SRC), (FLAGS),\
					       (AUX), (IMM));             \
		} else if (KPROG_X86_DISP_CMP_REG_MEM_HANDLED(OP)) {     \
			X86_SIM_L_EXEC_CMP_REG_MEM((DST), (SRC), (FLAGS), \
						   (AUX), (IMM));        \
		} else if (KPROG_X86_DISP_CMOV_HANDLED(OP)) {            \
			X86_SIM_L_EXEC_CMOV((DST), (SRC), (FLAGS), (AUX));\
		} else if (KPROG_X86_DISP_CMOV_MEM_HANDLED(OP)) {       \
			X86_SIM_L_EXEC_CMOV_MEM((DST), (SRC), (FLAGS),    \
						(AUX), (IMM));            \
		} else if (KPROG_X86_DISP_SETCC_HANDLED(OP)) {           \
			X86_SIM_L_EXEC_SETCC_STEP((DST), (AUX));           \
		} else if (KPROG_X86_DISP_SETCC_MEM_HANDLED(OP)) {       \
			X86_SIM_L_EXEC_SETCC_MEM((DST), (AUX), (IMM));    \
		} else if (KPROG_X86_DISP_BSWAP_HANDLED(OP)) {           \
			X86_SIM_L_WRITE_REG_WIDTH((DST),                  \
				x86_bswap(X86_SIM_L_READ_REG(DST), __x86_l_width),\
				__x86_l_width);                          \
			} else if (KPROG_X86_DISP_POPCNT_HANDLED(OP)) {         \
				__u64 __x86_l_src = X86_SIM_L_READ_REG(SRC);      \
				__u64 __x86_l_result =                            \
					x86_popcount64(x86_apply_width(__x86_l_src,\
								       __x86_l_width));\
				X86_SIM_L_SET_POPCNT_FLAGS(__x86_l_src,           \
							  __x86_l_width);        \
				X86_SIM_L_WRITE_REG_WIDTH((DST), __x86_l_result,  \
							  __x86_l_width);        \
			} else if (KPROG_X86_DISP_POPCNT_MEM_HANDLED(OP)) { \
                if (X86_SIM_L_READ_RECOVERY_MEM(SRC, DST, (AUX), x86_simm(IMM))) break; \
				__u64 __x86_l_src = X86_SIM_L_READ_MEM_VALUE(     \
					(SRC), (AUX), (IMM), (FLAGS), 0);         \
				__u64 __x86_l_result = x86_popcount64(            \
					x86_apply_width(__x86_l_src, __x86_l_width)); \
				X86_SIM_L_SET_POPCNT_FLAGS(__x86_l_src,           \
					__x86_l_width);                          \
				X86_SIM_L_WRITE_REG_WIDTH((DST), __x86_l_result,  \
					__x86_l_width);                          \
			} else if (KPROG_X86_DISP_SHIFTX_HANDLED(OP)) {         \
				__u64 __x86_l_src = X86_SIM_L_READ_REG(SRC);      \
				__u64 __x86_l_count = X86_SIM_L_READ_REG(AUX);    \
				__u64 __x86_l_result = x86_alu_result(            \
					__x86_l_src, __x86_l_count, (IMM),        \
					__x86_l_width);                          \
				X86_SIM_L_WRITE_REG_WIDTH((DST), __x86_l_result,  \
							  __x86_l_width);        \
			} else if (KPROG_X86_DISP_SHIFTX_MEM_HANDLED(OP)) { \
                if (X86_SIM_L_READ_RECOVERY_MEM(SRC, DST, (AUX), x86_store_imm_disp(IMM))) break; \
				__u64 __x86_l_src = X86_SIM_L_READ_MEM_VALUE(     \
					(SRC), (AUX), (IMM), (FLAGS), 1);         \
				__u64 __x86_l_count = X86_SIM_L_READ_REG(         \
					X86_REG_AUX_GET_SRC_SHIFT(AUX));          \
				__u64 __x86_l_result = x86_alu_result(            \
					__x86_l_src, __x86_l_count,              \
					(__u8)(IMM), __x86_l_width);             \
				X86_SIM_L_WRITE_REG_WIDTH((DST), __x86_l_result,  \
							  __x86_l_width);        \
			} else if (KPROG_X86_DISP_ROR_HANDLED(OP)) { \
				X86_SIM_L_EXEC_ROR((DST), (FLAGS), (AUX), (IMM)); \
			} else if (KPROG_X86_DISP_ROR_MEM_HANDLED(OP)) { \
				X86_SIM_L_EXEC_ROR_MEM((DST), (FLAGS), (AUX), (IMM)); \
			} else if (KPROG_X86_DISP_RORX_HANDLED(OP)) {           \
				X86_SIM_L_EXEC_RORX((DST), (SRC), (FLAGS), (IMM)); \
			} else if (KPROG_X86_DISP_RORX_MEM_HANDLED(OP)) { \
                if (X86_SIM_L_READ_RECOVERY_MEM(SRC, DST, (AUX), x86_store_imm_disp(IMM))) break; \
				__u64 __x86_l_src = X86_SIM_L_READ_MEM_VALUE(     \
					(SRC), (AUX), (IMM), (FLAGS), 1);         \
				X86_SIM_L_WRITE_REG_WIDTH((DST),                  \
					x86_ror(__x86_l_src, (__u8)(IMM),         \
						__x86_l_width),                   \
					__x86_l_width);                          \
			} else if (KPROG_X86_DISP_BZHI_HANDLED(OP)) {           \
				X86_SIM_L_EXEC_BZHI((DST), (SRC), (AUX), (FLAGS));\
			} else if (KPROG_X86_DISP_BZHI_MEM_HANDLED(OP)) {       \
				X86_SIM_L_EXEC_BZHI_MEM((DST), (SRC), (FLAGS), (AUX), (IMM));\
			} else if (KPROG_X86_DISP_BT_HANDLED(OP)) {             \
				X86_SIM_L_EXEC_BT((DST), (SRC), (FLAGS));          \
			} else if (KPROG_X86_DISP_BT_IMM_HANDLED(OP)) {         \
				X86_SIM_L_EXEC_BT_IMM((DST), (FLAGS), (IMM));      \
			} else if (KPROG_X86_DISP_BT_MEM_IMM_HANDLED(OP)) {     \
				X86_SIM_L_EXEC_BT_MEM_IMM((DST), (FLAGS), (AUX), (IMM));\
			} else if (KPROG_X86_DISP_IMUL_IMM_HANDLED(OP)) {       \
				X86_SIM_L_EXEC_IMUL_IMM((DST), (SRC), (FLAGS), (IMM));\
			} else if (KPROG_X86_DISP_IMUL_MEM_IMM_HANDLED(OP)) {   \
				X86_SIM_L_EXEC_IMUL_MEM_IMM((DST), (SRC), (FLAGS), (AUX), (IMM));\
			} else if (KPROG_X86_DISP_MULX_HANDLED(OP)) {           \
				X86_SIM_L_EXEC_MULX((DST), (SRC), (AUX), (FLAGS)); \
			} else if (KPROG_X86_DISP_REP_MOVS_HANDLED(OP)) {       \
				X86_SIM_L_EXEC_REP_MOVS((FLAGS), (IMM));          \
			} else if (KPROG_X86_DISP_ANDN_HANDLED(OP)) {           \
				X86_SIM_L_EXEC_ANDN((DST), (SRC), (AUX), (FLAGS)); \
			} else if (KPROG_X86_DISP_ANDN_MEM_HANDLED(OP)) {       \
				X86_SIM_L_EXEC_ANDN_MEM((DST), (SRC), (FLAGS), (AUX), (IMM));\
			} else if (KPROG_X86_DISP_XCHG_HANDLED(OP)) {           \
				if (KPROG_X86_XCHG_ARM(__x86_l_width) ==                \
				    KPROG_X86_XCHG_ARM_POINTER_SWAP) {              \
				void *__x86_l_dst_ptr = (DST) == X86_RSP ? X86_SIM_L_STACK_PTR((__s64)(long)X86_SIM_L_READ_REG_PTR(DST)) : X86_SIM_L_READ_REG_PTR(DST); \
				void *__x86_l_src_ptr = (SRC) == X86_RSP ? X86_SIM_L_STACK_PTR((__s64)(long)X86_SIM_L_READ_REG_PTR(SRC)) : X86_SIM_L_READ_REG_PTR(SRC); \
				__u8 __x86_l_dst_tag = (DST) == X86_RSP ? X86_SIM_TAG_STACK : X86_SIM_L_REG_TAG(DST); \
				__u8 __x86_l_src_tag = (SRC) == X86_RSP ? X86_SIM_TAG_STACK : X86_SIM_L_REG_TAG(SRC); \
				__u64 __x86_l_dst_bits = X86_SIM_L_READ_REG(DST); \
				__u64 __x86_l_src_bits = X86_SIM_L_READ_REG(SRC); \
				if ((DST) == X86_RSP) \
				    X86_SIM_L_WRITE_REG_WIDTH((DST), __x86_l_src_bits, X86_WIDTH_64); \
				else \
				    X86_SIM_L_WRITE_REG_PTR_TAG((DST), __x86_l_src_ptr, __x86_l_src_tag); \
				if ((SRC) == X86_RSP) \
				    X86_SIM_L_WRITE_REG_WIDTH((SRC), __x86_l_dst_bits, X86_WIDTH_64); \
				else \
				    X86_SIM_L_WRITE_REG_PTR_TAG((SRC), __x86_l_dst_ptr, __x86_l_dst_tag); \
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
		} else if (KPROG_X86_DISP_DIV_HANDLED(OP)) { \
            __u64 __x86_l_divisor = (SRC) == X86_REG_NONE ? (IMM) : X86_SIM_L_READ_REG(SRC); \
            __u64 __x86_l_rax = X86_SIM_L_READ_REG(X86_RAX); \
            __u64 __x86_l_rdx = X86_SIM_L_READ_REG(X86_RDX); \
            if ((AUX) & X86_DIV_AUX_SIGNED) { \
                __u32 __x86_id_bits = (__u32)__x86_l_width * 8; \
                __u64 __x86_id_mask = ~0ULL >> (64 - __x86_id_bits); \
                __u64 __x86_id_sign = 1ULL << (__x86_id_bits - 1); \
                __u64 __x86_id_hi = (__x86_l_width == X86_WIDTH_8 ? __x86_l_rax >> 8 : __x86_l_rdx) & __x86_id_mask; \
                __u64 __x86_id_lo = __x86_l_rax & __x86_id_mask; \
                __u64 __x86_id_div = __x86_l_divisor & __x86_id_mask; \
                __u8 __x86_id_negative = (__x86_id_hi & __x86_id_sign) != 0; \
                __u8 __x86_id_qnegative = __x86_id_negative ^ ((__x86_id_div & __x86_id_sign) != 0); \
                if (__x86_id_negative) { \
                    __x86_id_lo = (0ULL - __x86_id_lo) & __x86_id_mask; \
                    __x86_id_hi = (~__x86_id_hi + (__x86_id_lo == 0)) & __x86_id_mask; \
                } \
                if (__x86_id_div & __x86_id_sign) \
                    __x86_id_div = (0ULL - __x86_id_div) & __x86_id_mask; \
                if (__x86_id_div == 0 || __x86_id_hi >= __x86_id_div) \
                    X86_SIM_L_DIVIDE_FAULT(); \
                struct x86_sim_divmod64 __x86_id_result; \
                if (__x86_l_width == X86_WIDTH_64) { \
                    if (__x86_id_hi == 0) { \
                        __x86_id_result.quotient = __x86_id_lo / __x86_id_div; \
                        __x86_id_result.remainder = __x86_id_lo % __x86_id_div; \
                    } else { \
                        __x86_id_result = x86_sim_divmod128(__x86_id_hi, __x86_id_lo, __x86_id_div); \
                    } \
                } else { \
                    __u64 __x86_id_dividend = (__x86_id_hi << __x86_id_bits) | __x86_id_lo; \
                    __x86_id_result.quotient = __x86_id_dividend / __x86_id_div; \
                    __x86_id_result.remainder = __x86_id_dividend % __x86_id_div; \
                } \
                if (__x86_id_result.quotient > __x86_id_sign - (__x86_id_qnegative == 0)) \
                    X86_SIM_L_DIVIDE_FAULT(); \
                if (__x86_id_qnegative) \
                    __x86_id_result.quotient = 0ULL - __x86_id_result.quotient; \
                if (__x86_id_negative) \
                    __x86_id_result.remainder = 0ULL - __x86_id_result.remainder; \
                if (__x86_l_width == X86_WIDTH_8) { \
                    X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, \
                        ((__x86_id_result.remainder & 0xff) << 8) | (__x86_id_result.quotient & 0xff), X86_WIDTH_16); \
                } else { \
                    X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, __x86_id_result.quotient, __x86_l_width); \
                    X86_SIM_L_WRITE_REG_WIDTH(X86_RDX, __x86_id_result.remainder, __x86_l_width); \
                } \
                __x86_cf = X86_SIM_L_UNSPECIFIED() & 1; \
                __x86_zf = X86_SIM_L_UNSPECIFIED() & 1; \
                __x86_sf = X86_SIM_L_UNSPECIFIED() & 1; \
                __x86_of = X86_SIM_L_UNSPECIFIED() & 1; \
                __x86_pf = X86_SIM_L_UNSPECIFIED() & 1; \
                __x86_af = X86_SIM_L_UNSPECIFIED() & 1; \
            } else if (KPROG_X86_DIV_ARM(__x86_l_width) == KPROG_X86_DIV_ARM_B8) { \
                __u32 __x86_l_dividend = (__u16)__x86_l_rax; \
                __u8 __x86_l_div = (__u8)__x86_l_divisor; \
                if (__x86_l_div == 0 || (__x86_l_dividend >> 8) >= __x86_l_div) \
                    X86_SIM_L_DIVIDE_FAULT(); \
                __u8 __x86_l_q = __x86_l_dividend / __x86_l_div; \
                __u8 __x86_l_rem = __x86_l_dividend % __x86_l_div; \
                X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, ((__u16)__x86_l_rem << 8) | __x86_l_q, X86_WIDTH_16); \
            } else if (KPROG_X86_DIV_ARM(__x86_l_width) == KPROG_X86_DIV_ARM_B16) { \
                __u32 __x86_l_dividend = ((__u32)(__u16)__x86_l_rdx << 16) | (__u16)__x86_l_rax; \
                __u16 __x86_l_div = (__u16)__x86_l_divisor; \
                if (__x86_l_div == 0 || (__u16)__x86_l_rdx >= __x86_l_div) \
                    X86_SIM_L_DIVIDE_FAULT(); \
                X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, __x86_l_dividend / __x86_l_div, X86_WIDTH_16); \
                X86_SIM_L_WRITE_REG_WIDTH(X86_RDX, __x86_l_dividend % __x86_l_div, X86_WIDTH_16); \
            } else if (KPROG_X86_DIV_ARM(__x86_l_width) == KPROG_X86_DIV_ARM_B32) { \
                __u64 __x86_l_dividend = ((__u64)(__u32)__x86_l_rdx << 32) | (__u32)__x86_l_rax; \
                __u32 __x86_l_div = (__u32)__x86_l_divisor; \
                if (__x86_l_div == 0 || (__u32)__x86_l_rdx >= __x86_l_div) \
                    X86_SIM_L_DIVIDE_FAULT(); \
                X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, __x86_l_dividend / __x86_l_div, X86_WIDTH_32); \
                X86_SIM_L_WRITE_REG_WIDTH(X86_RDX, __x86_l_dividend % __x86_l_div, X86_WIDTH_32); \
            } else { \
                if (__x86_l_divisor == 0 || __x86_l_rdx >= __x86_l_divisor) \
                    X86_SIM_L_DIVIDE_FAULT(); \
                if (__x86_l_rdx == 0) { \
                    X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, __x86_l_rax / __x86_l_divisor, X86_WIDTH_64); \
                    X86_SIM_L_WRITE_REG_WIDTH(X86_RDX, __x86_l_rax % __x86_l_divisor, X86_WIDTH_64); \
                } else { \
                    struct x86_sim_divmod64 __x86_l_result = x86_sim_divmod128(__x86_l_rdx, __x86_l_rax, __x86_l_divisor); \
                    X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, __x86_l_result.quotient, X86_WIDTH_64); \
                    X86_SIM_L_WRITE_REG_WIDTH(X86_RDX, __x86_l_result.remainder, X86_WIDTH_64); \
                } \
            } \
		} else if (KPROG_X86_DOUBLE_SHIFT_HANDLED(OP)) {          \
			__u64 __x86_l_dst = X86_SIM_L_READ_REG(DST);     \
			__u64 __x86_l_src = X86_SIM_L_READ_REG(SRC);     \
			__u64 __x86_l_result;                            \
			__u8 __x86_l_arm =                               \
				KPROG_X86_DOUBLESHIFT_ARM((OP));         \
			__u32 __x86_l_alu =                              \
				KPROG_X86_DOUBLESHIFT_ARM_FLAGS((OP));   \
			if (x86_shift_count((IMM), __x86_l_width) != 0) { \
				if (__x86_l_arm == KPROG_X86_DOUBLESHIFT_ARM_SHLD) {\
					__x86_l_result = x86_shld(__x86_l_dst, __x86_l_src, (IMM), __x86_l_width);\
					X86_SIM_L_SET_SHIFT_FLAGS(__x86_l_dst, (IMM), __x86_l_result, __x86_l_alu, __x86_l_width);\
				} else {                                    \
					__x86_l_result = x86_shrd(__x86_l_dst, __x86_l_src, (IMM), __x86_l_width);\
					X86_SIM_L_SET_SHIFT_FLAGS(__x86_l_dst, (IMM), __x86_l_result, __x86_l_alu, __x86_l_width);\
				}                                           \
				__x86_of = KPROG_X86_DOUBLESHIFT_OF(             \
					((__x86_l_dst & x86_width_sign_mask(__x86_l_width)) != 0),    \
					((__x86_l_result & x86_width_sign_mask(__x86_l_width)) != 0), \
					x86_shift_count((IMM), __x86_l_width), __x86_of);\
				X86_SIM_L_WRITE_REG_WIDTH((DST), __x86_l_result,\
							  __x86_l_width);    \
			} else if (__x86_l_width == X86_WIDTH_32) {       \
				X86_SIM_L_WRITE_REG_WIDTH((DST), __x86_l_dst, X86_WIDTH_32);\
			}                                                   \
		} else if (KPROG_X86_DISP_PUSH_HANDLED(OP)) {            \
			X86_SIM_L_EXEC_PUSH_OP((SRC), (FLAGS), (AUX), (IMM)); \
		} else if (KPROG_X86_DISP_POP_HANDLED(OP)) {             \
			X86_SIM_L_EXEC_POP_OP((DST), (FLAGS), (AUX), (IMM)); \
		}                                                         \
	} while (0)

#define X86_SIM_RUN_OP(OP, DST, SRC, FLAGS, AUX, IMM)                       \
	do {                                                               \
		X86_SIM_L_EXEC((OP), (DST), (SRC), (FLAGS), (AUX), (IMM)); \
	} while (0)

#define X86_SIM_RUN_OP_SUB(OP, DST, SRC, FLAGS, AUX, IMM)                   \
	X86_SIM_RUN_OP((OP), (DST), (SRC), (FLAGS), (AUX), (IMM))

/* No machine code is emitted for an unresolved helper: specialization must
 * eliminate this declaration's call before an artifact can compile. */
extern void __x86_sim_unsupported_helper(void)
    __attribute__((error("unresolved x86 helper ID")));
#define X86_SIM_L_UNSUPPORTED_HELPER() __x86_sim_unsupported_helper()

#define X86_SIM_L_HELPER_REGISTER_CLOBBERS() \
    do { X86_SIM_L_STACK_RELEASE(-(__s64)X86_SIM_STACK_BYTES); \
        __x86_rcx.ptr = (void *)X86_SIM_L_UNSPECIFIED(); \
        __x86_rcx_tag = X86_SIM_TAG_SCALAR; \
        __x86_rdx.ptr = (void *)X86_SIM_L_UNSPECIFIED(); \
        __x86_rdx_tag = X86_SIM_TAG_SCALAR; \
        __x86_rsi.ptr = (void *)X86_SIM_L_UNSPECIFIED(); \
        __x86_rsi_tag = X86_SIM_TAG_SCALAR; \
        __x86_rdi.ptr = (void *)X86_SIM_L_UNSPECIFIED(); \
        __x86_rdi_tag = X86_SIM_TAG_SCALAR; \
        __x86_r8.ptr = (void *)X86_SIM_L_UNSPECIFIED(); \
        __x86_r8_tag = X86_SIM_TAG_SCALAR; \
        __x86_r9.ptr = (void *)X86_SIM_L_UNSPECIFIED(); \
        __x86_r9_tag = X86_SIM_TAG_SCALAR; \
        __x86_r10.ptr = (void *)X86_SIM_L_UNSPECIFIED(); \
        __x86_r10_tag = X86_SIM_TAG_SCALAR; \
        __x86_r11.ptr = (void *)X86_SIM_L_UNSPECIFIED(); \
        __x86_r11_tag = X86_SIM_TAG_SCALAR; \
        __x86_cf = X86_SIM_L_UNSPECIFIED() & 1; \
        __x86_zf = X86_SIM_L_UNSPECIFIED() & 1; \
        __x86_sf = X86_SIM_L_UNSPECIFIED() & 1; \
        __x86_of = X86_SIM_L_UNSPECIFIED() & 1; \
        __x86_pf = X86_SIM_L_UNSPECIFIED() & 1; \
        __x86_af = X86_SIM_L_UNSPECIFIED() & 1; \
        __x86_xmm0_lo = X86_SIM_L_UNSPECIFIED(); \
        __x86_xmm0_hi = X86_SIM_L_UNSPECIFIED(); \
    } while (0)

#define X86_SIM_L_HELPER_CLOBBERS() \
    do { X86_SIM_L_STACK_VALUES_CLEAR(); X86_SIM_L_HELPER_REGISTER_CLOBBERS(); } while(0)
#define X86_SIM_L_HELPER_READONLY_SCALAR_RESULT(EXPR) \
    do { __u64 __x86_hr=(__u64)(EXPR); X86_SIM_L_WRITE_REG_WIDTH(X86_RAX,__x86_hr,X86_WIDTH_64); \
         X86_SIM_L_STACK_VALUES_CALL_FRAME(); X86_SIM_L_HELPER_REGISTER_CLOBBERS(); } while(0)
#define X86_SIM_L_HELPER_READONLY_POINTER_RESULT(EXPR) \
    do { void *__x86_hr=(void *)(EXPR); X86_SIM_L_WRITE_REG_PTR_TAG(X86_RAX,__x86_hr,X86_SIM_TAG_MAP_VALUE); \
         X86_SIM_L_STACK_VALUES_CALL_FRAME(); X86_SIM_L_HELPER_REGISTER_CLOBBERS(); } while(0)
/* Preserve caller facts outside a helper's possible output interval. */
#define X86_SIM_L_HELPER_WRITE_SCALAR_RESULT(EXPR, DST, SIZE) \
    do { void *__x86_hw_dst=X86_SIM_L_HELPER_ARG_PTR(DST); \
         __u64 __x86_hw_size=(__u32)X86_SIM_L_READ_REG(SIZE); \
         __u8 __x86_hw_tag=(DST)==X86_RSP ? X86_SIM_TAG_STACK : X86_SIM_L_REG_TAG(DST); \
         __u64 __x86_hw_result=(__u64)(EXPR); \
         if (__x86_hw_size && __x86_hw_tag==X86_SIM_TAG_STACK) \
             X86_SIM_L_STACK_VALUES_ERASE_BYTES((__u64)(long)__x86_hw_dst-(__u64)(long)&__x86_stack_mem.b[0],__x86_hw_size); \
         else if (__x86_hw_size && __x86_hw_tag==X86_SIM_TAG_SCALAR) X86_SIM_L_STACK_VALUES_CLEAR(); \
         X86_SIM_L_WRITE_REG_WIDTH(X86_RAX,__x86_hw_result,X86_WIDTH_64); \
         X86_SIM_L_STACK_VALUES_CALL_FRAME(); X86_SIM_L_HELPER_REGISTER_CLOBBERS(); } while(0)

#define X86_SIM_L_HELPER_SCALAR_RESULT(EXPR) \
    do { \
        __u64 __x86_helper_result = (__u64)(EXPR); \
        X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, __x86_helper_result, X86_WIDTH_64); \
        X86_SIM_L_HELPER_CLOBBERS(); \
    } while (0)

#define X86_SIM_L_HELPER_POINTER_RESULT(EXPR) \
    do { \
        void *__x86_helper_result = (void *)(EXPR); \
        X86_SIM_L_WRITE_REG_PTR_TAG(X86_RAX, __x86_helper_result, X86_SIM_TAG_MAP_VALUE); \
        X86_SIM_L_HELPER_CLOBBERS(); \
    } while (0)

#define X86_SIM_BPF_CALL_bpf_map_lookup_elem() \
	X86_SIM_L_HELPER_READONLY_POINTER_RESULT(bpf_map_lookup_elem((void *)X86_SIM_L_HELPER_ARG_PTR(X86_RDI), (const void *)X86_SIM_L_HELPER_ARG_PTR(X86_RSI)))

/* Map mutation reads caller key/value buffers and writes map-owned storage. */
#define X86_SIM_BPF_CALL_bpf_map_update_elem() \
	X86_SIM_L_HELPER_READONLY_SCALAR_RESULT(bpf_map_update_elem((void *)X86_SIM_L_HELPER_ARG_PTR(X86_RDI), (const void *)X86_SIM_L_HELPER_ARG_PTR(X86_RSI), (const void *)X86_SIM_L_HELPER_ARG_PTR(X86_RDX), (__u64)X86_SIM_L_READ_REG(X86_RCX)))

#define X86_SIM_BPF_CALL_bpf_map_delete_elem() \
	X86_SIM_L_HELPER_READONLY_SCALAR_RESULT(bpf_map_delete_elem((void *)X86_SIM_L_HELPER_ARG_PTR(X86_RDI), (const void *)X86_SIM_L_HELPER_ARG_PTR(X86_RSI)))

#define X86_SIM_BPF_CALL_bpf_probe_read() \
	X86_SIM_L_HELPER_WRITE_SCALAR_RESULT(bpf_probe_read((void *)X86_SIM_L_HELPER_ARG_PTR(X86_RDI), (__u32)X86_SIM_L_READ_REG(X86_RSI), (const void *)X86_SIM_L_HELPER_ARG_PTR(X86_RDX)), X86_RDI, X86_RSI)

#define X86_SIM_BPF_CALL_bpf_ktime_get_ns() \
	X86_SIM_L_HELPER_READONLY_SCALAR_RESULT(bpf_ktime_get_ns())

#define X86_SIM_BPF_CALL_bpf_trace_printk() \
	X86_SIM_L_HELPER_SCALAR_RESULT(bpf_trace_printk((const char *)X86_SIM_L_HELPER_ARG_PTR(X86_RDI), (__u32)X86_SIM_L_READ_REG(X86_RSI), X86_SIM_L_READ_REG(X86_RDX), X86_SIM_L_READ_REG(X86_RCX), X86_SIM_L_READ_REG(X86_R8)))

#define X86_SIM_BPF_CALL_bpf_get_prandom_u32() \
	X86_SIM_L_HELPER_READONLY_SCALAR_RESULT(bpf_get_prandom_u32())

#define X86_SIM_BPF_CALL_bpf_get_smp_processor_id() \
	X86_SIM_L_HELPER_READONLY_SCALAR_RESULT(bpf_get_smp_processor_id())

#define X86_SIM_BPF_CALL_bpf_skb_store_bytes() \
	X86_SIM_L_HELPER_READONLY_SCALAR_RESULT(bpf_skb_store_bytes((struct __sk_buff *)X86_SIM_L_HELPER_CTX_PTR(X86_RDI), (__u32)X86_SIM_L_READ_REG(X86_RSI), (const void *)X86_SIM_L_HELPER_ARG_PTR(X86_RDX), (__u32)X86_SIM_L_READ_REG(X86_RCX), (__u64)X86_SIM_L_READ_REG(X86_R8)))

#define X86_SIM_BPF_CALL_bpf_l3_csum_replace() \
	X86_SIM_L_HELPER_SCALAR_RESULT(bpf_l3_csum_replace((struct __sk_buff *)X86_SIM_L_HELPER_CTX_PTR(X86_RDI), (__u32)X86_SIM_L_READ_REG(X86_RSI), (__u64)X86_SIM_L_READ_REG(X86_RDX), (__u64)X86_SIM_L_READ_REG(X86_RCX), (__u64)X86_SIM_L_READ_REG(X86_R8)))

#define X86_SIM_BPF_CALL_bpf_l4_csum_replace() \
	X86_SIM_L_HELPER_SCALAR_RESULT(bpf_l4_csum_replace((struct __sk_buff *)X86_SIM_L_HELPER_CTX_PTR(X86_RDI), (__u32)X86_SIM_L_READ_REG(X86_RSI), (__u64)X86_SIM_L_READ_REG(X86_RDX), (__u64)X86_SIM_L_READ_REG(X86_RCX), (__u64)X86_SIM_L_READ_REG(X86_R8)))

#define X86_SIM_BPF_CALL_bpf_tail_call() \
	X86_SIM_L_HELPER_SCALAR_RESULT(bpf_tail_call((void *)X86_SIM_L_HELPER_CTX_PTR(X86_RDI), (void *)X86_SIM_L_HELPER_ARG_PTR(X86_RSI), (__u32)X86_SIM_L_READ_REG(X86_RDX)))

#define X86_SIM_BPF_CALL_bpf_get_current_pid_tgid() \
	X86_SIM_L_HELPER_READONLY_SCALAR_RESULT(bpf_get_current_pid_tgid())

#define X86_SIM_BPF_CALL_bpf_get_current_uid_gid() \
	X86_SIM_L_HELPER_READONLY_SCALAR_RESULT(bpf_get_current_uid_gid())

#define X86_SIM_BPF_CALL_bpf_get_current_comm() \
	X86_SIM_L_HELPER_WRITE_SCALAR_RESULT(bpf_get_current_comm((void *)X86_SIM_L_HELPER_ARG_PTR(X86_RDI), (__u32)X86_SIM_L_READ_REG(X86_RSI)), X86_RDI, X86_RSI)

#define X86_SIM_BPF_CALL_bpf_skb_get_tunnel_key() \
	X86_SIM_L_HELPER_SCALAR_RESULT(bpf_skb_get_tunnel_key((struct __sk_buff *)X86_SIM_L_HELPER_CTX_PTR(X86_RDI), (struct bpf_tunnel_key *)X86_SIM_L_HELPER_ARG_PTR(X86_RSI), (__u32)X86_SIM_L_READ_REG(X86_RDX), (__u64)X86_SIM_L_READ_REG(X86_RCX)))

#define X86_SIM_BPF_CALL_bpf_skb_set_tunnel_key() \
	X86_SIM_L_HELPER_SCALAR_RESULT(bpf_skb_set_tunnel_key((struct __sk_buff *)X86_SIM_L_HELPER_CTX_PTR(X86_RDI), (struct bpf_tunnel_key *)X86_SIM_L_HELPER_ARG_PTR(X86_RSI), (__u32)X86_SIM_L_READ_REG(X86_RDX), (__u64)X86_SIM_L_READ_REG(X86_RCX)))

#define X86_SIM_BPF_CALL_bpf_redirect() \
	X86_SIM_L_HELPER_SCALAR_RESULT(bpf_redirect((__u32)X86_SIM_L_READ_REG(X86_RDI), (__u64)X86_SIM_L_READ_REG(X86_RSI)))

#define X86_SIM_BPF_CALL_bpf_perf_event_output() \
	X86_SIM_L_HELPER_SCALAR_RESULT(bpf_perf_event_output((void *)X86_SIM_L_HELPER_CTX_PTR(X86_RDI), (void *)X86_SIM_L_HELPER_ARG_PTR(X86_RSI), (__u64)X86_SIM_L_READ_REG(X86_RDX), (void *)X86_SIM_L_HELPER_ARG_PTR(X86_RCX), (__u64)X86_SIM_L_READ_REG(X86_R8)))

#define X86_SIM_BPF_CALL_bpf_skb_load_bytes() \
	X86_SIM_L_HELPER_WRITE_SCALAR_RESULT(bpf_skb_load_bytes((const void *)X86_SIM_L_HELPER_CTX_PTR(X86_RDI), (__u32)X86_SIM_L_READ_REG(X86_RSI), (void *)X86_SIM_L_HELPER_ARG_PTR(X86_RDX), (__u32)X86_SIM_L_READ_REG(X86_RCX)), X86_RDX, X86_RCX)

#define X86_SIM_BPF_CALL_bpf_get_stackid() \
	X86_SIM_L_HELPER_SCALAR_RESULT(bpf_get_stackid((void *)X86_SIM_L_HELPER_CTX_PTR(X86_RDI), (void *)X86_SIM_L_HELPER_ARG_PTR(X86_RSI), (__u64)X86_SIM_L_READ_REG(X86_RDX)))

#define X86_SIM_BPF_CALL_bpf_csum_diff() \
	X86_SIM_L_HELPER_SCALAR_RESULT(bpf_csum_diff((__be32 *)X86_SIM_L_HELPER_ARG_PTR(X86_RDI), (__u32)X86_SIM_L_READ_REG(X86_RSI), (__be32 *)X86_SIM_L_HELPER_ARG_PTR(X86_RDX), (__u32)X86_SIM_L_READ_REG(X86_RCX), (__wsum)X86_SIM_L_READ_REG(X86_R8)))

#define X86_SIM_BPF_CALL_bpf_skb_change_type() \
	X86_SIM_L_HELPER_SCALAR_RESULT(bpf_skb_change_type((struct __sk_buff *)X86_SIM_L_HELPER_CTX_PTR(X86_RDI), (__u32)X86_SIM_L_READ_REG(X86_RSI)))

#define X86_SIM_BPF_CALL_bpf_get_current_task() \
	X86_SIM_L_HELPER_READONLY_SCALAR_RESULT(bpf_get_current_task())

#define X86_SIM_BPF_CALL_bpf_probe_write_user() \
	X86_SIM_L_HELPER_SCALAR_RESULT(bpf_probe_write_user((void *)X86_SIM_L_HELPER_ARG_PTR(X86_RDI), (const void *)X86_SIM_L_HELPER_ARG_PTR(X86_RSI), (__u32)X86_SIM_L_READ_REG(X86_RDX)))

#define X86_SIM_BPF_CALL_bpf_current_task_under_cgroup() \
	X86_SIM_L_HELPER_SCALAR_RESULT(bpf_current_task_under_cgroup((void *)X86_SIM_L_HELPER_ARG_PTR(X86_RDI), (__u32)X86_SIM_L_READ_REG(X86_RSI)))

#define X86_SIM_BPF_CALL_bpf_skb_change_tail() \
	X86_SIM_L_HELPER_SCALAR_RESULT(bpf_skb_change_tail((struct __sk_buff *)X86_SIM_L_HELPER_CTX_PTR(X86_RDI), (__u32)X86_SIM_L_READ_REG(X86_RSI), (__u64)X86_SIM_L_READ_REG(X86_RDX)))

#define X86_SIM_BPF_CALL_bpf_skb_pull_data() \
	X86_SIM_L_HELPER_SCALAR_RESULT(bpf_skb_pull_data((struct __sk_buff *)X86_SIM_L_HELPER_CTX_PTR(X86_RDI), (__u32)X86_SIM_L_READ_REG(X86_RSI)))

#define X86_SIM_BPF_CALL_bpf_skb_change_head() \
	X86_SIM_L_HELPER_SCALAR_RESULT(bpf_skb_change_head((struct __sk_buff *)X86_SIM_L_HELPER_CTX_PTR(X86_RDI), (__u32)X86_SIM_L_READ_REG(X86_RSI), (__u64)X86_SIM_L_READ_REG(X86_RDX)))

#define X86_SIM_BPF_CALL_bpf_xdp_adjust_head() \
	X86_SIM_L_HELPER_SCALAR_RESULT(bpf_xdp_adjust_head((struct xdp_md *)X86_SIM_L_HELPER_CTX_PTR(X86_RDI), (int)X86_SIM_L_READ_REG(X86_RSI)))

#define X86_SIM_BPF_CALL_bpf_probe_read_str() \
	X86_SIM_L_HELPER_SCALAR_RESULT(bpf_probe_read_str((void *)X86_SIM_L_HELPER_ARG_PTR(X86_RDI), (__u32)X86_SIM_L_READ_REG(X86_RSI), (const void *)X86_SIM_L_HELPER_ARG_PTR(X86_RDX)))

#define X86_SIM_BPF_CALL_bpf_get_socket_cookie() \
	X86_SIM_L_HELPER_SCALAR_RESULT(bpf_get_socket_cookie((void *)X86_SIM_L_HELPER_CTX_PTR(X86_RDI)))

#define X86_SIM_BPF_CALL_bpf_skb_adjust_room() \
	X86_SIM_L_HELPER_SCALAR_RESULT(bpf_skb_adjust_room((struct __sk_buff *)X86_SIM_L_HELPER_CTX_PTR(X86_RDI), (__s32)X86_SIM_L_READ_REG(X86_RSI), (__u32)X86_SIM_L_READ_REG(X86_RDX), (__u64)X86_SIM_L_READ_REG(X86_RCX)))

#define X86_SIM_BPF_CALL_bpf_xdp_adjust_meta() \
	X86_SIM_L_HELPER_SCALAR_RESULT(bpf_xdp_adjust_meta((struct xdp_md *)X86_SIM_L_HELPER_CTX_PTR(X86_RDI), (int)X86_SIM_L_READ_REG(X86_RSI)))

#define X86_SIM_BPF_CALL_bpf_override_return() \
	X86_SIM_L_HELPER_SCALAR_RESULT(bpf_override_return((struct pt_regs *)X86_SIM_L_HELPER_ARG_PTR(X86_RDI), (__u64)X86_SIM_L_READ_REG(X86_RSI)))

#define X86_SIM_BPF_CALL_bpf_xdp_adjust_tail() \
	X86_SIM_L_HELPER_SCALAR_RESULT(bpf_xdp_adjust_tail((struct xdp_md *)X86_SIM_L_HELPER_CTX_PTR(X86_RDI), (int)X86_SIM_L_READ_REG(X86_RSI)))

#define X86_SIM_BPF_CALL_bpf_get_stack() \
	X86_SIM_L_HELPER_WRITE_SCALAR_RESULT(bpf_get_stack((void *)X86_SIM_L_HELPER_CTX_PTR(X86_RDI), (void *)X86_SIM_L_HELPER_ARG_PTR(X86_RSI), (__u32)X86_SIM_L_READ_REG(X86_RDX), (__u64)X86_SIM_L_READ_REG(X86_RCX)), X86_RSI, X86_RDX)

#define X86_SIM_BPF_CALL_bpf_skb_load_bytes_relative() \
	X86_SIM_L_HELPER_WRITE_SCALAR_RESULT(bpf_skb_load_bytes_relative((const void *)X86_SIM_L_HELPER_CTX_PTR(X86_RDI), (__u32)X86_SIM_L_READ_REG(X86_RSI), (void *)X86_SIM_L_HELPER_ARG_PTR(X86_RDX), (__u32)X86_SIM_L_READ_REG(X86_RCX), (__u32)X86_SIM_L_READ_REG(X86_R8)), X86_RDX, X86_RCX)

#define X86_SIM_BPF_CALL_bpf_fib_lookup() \
	X86_SIM_L_HELPER_SCALAR_RESULT(bpf_fib_lookup((void *)X86_SIM_L_HELPER_CTX_PTR(X86_RDI), (struct bpf_fib_lookup *)X86_SIM_L_HELPER_ARG_PTR(X86_RSI), (int)X86_SIM_L_READ_REG(X86_RDX), (__u32)X86_SIM_L_READ_REG(X86_RCX)))

#define X86_SIM_BPF_CALL_bpf_get_current_cgroup_id() \
	X86_SIM_L_HELPER_READONLY_SCALAR_RESULT(bpf_get_current_cgroup_id())

#define X86_SIM_BPF_CALL_bpf_sk_lookup_udp() \
	X86_SIM_L_HELPER_POINTER_RESULT(bpf_sk_lookup_udp((void *)X86_SIM_L_HELPER_CTX_PTR(X86_RDI), (struct bpf_sock_tuple *)X86_SIM_L_HELPER_ARG_PTR(X86_RSI), (__u32)X86_SIM_L_READ_REG(X86_RDX), (__u64)X86_SIM_L_READ_REG(X86_RCX), (__u64)X86_SIM_L_READ_REG(X86_R8)))

#define X86_SIM_BPF_CALL_bpf_sk_release() \
	X86_SIM_L_HELPER_SCALAR_RESULT(bpf_sk_release((void *)X86_SIM_L_HELPER_ARG_PTR(X86_RDI)))

#define X86_SIM_BPF_CALL_bpf_map_push_elem() \
	X86_SIM_L_HELPER_SCALAR_RESULT(bpf_map_push_elem((void *)X86_SIM_L_HELPER_ARG_PTR(X86_RDI), (const void *)X86_SIM_L_HELPER_ARG_PTR(X86_RSI), (__u64)X86_SIM_L_READ_REG(X86_RDX)))

#define X86_SIM_BPF_CALL_bpf_map_pop_elem() \
	X86_SIM_L_HELPER_SCALAR_RESULT(bpf_map_pop_elem((void *)X86_SIM_L_HELPER_ARG_PTR(X86_RDI), (void *)X86_SIM_L_HELPER_ARG_PTR(X86_RSI)))

#define X86_SIM_BPF_CALL_bpf_sk_fullsock() \
	X86_SIM_L_HELPER_POINTER_RESULT(bpf_sk_fullsock((struct bpf_sock *)X86_SIM_L_HELPER_ARG_PTR(X86_RDI)))

#define X86_SIM_BPF_CALL_bpf_skc_lookup_tcp() \
	X86_SIM_L_HELPER_POINTER_RESULT(bpf_skc_lookup_tcp((void *)X86_SIM_L_HELPER_CTX_PTR(X86_RDI), (struct bpf_sock_tuple *)X86_SIM_L_HELPER_ARG_PTR(X86_RSI), (__u32)X86_SIM_L_READ_REG(X86_RDX), (__u64)X86_SIM_L_READ_REG(X86_RCX), (__u64)X86_SIM_L_READ_REG(X86_R8)))

#define X86_SIM_BPF_CALL_bpf_strtol() \
	X86_SIM_L_HELPER_SCALAR_RESULT(bpf_strtol((const char *)X86_SIM_L_HELPER_ARG_PTR(X86_RDI), (unsigned long)X86_SIM_L_READ_REG(X86_RSI), (__u64)X86_SIM_L_READ_REG(X86_RDX), (long *)X86_SIM_L_HELPER_ARG_PTR(X86_RCX)))

#define X86_SIM_BPF_CALL_bpf_send_signal() \
	X86_SIM_L_HELPER_SCALAR_RESULT(bpf_send_signal((__u32)X86_SIM_L_READ_REG(X86_RDI)))

#define X86_SIM_BPF_CALL_bpf_probe_read_user() \
	X86_SIM_L_HELPER_WRITE_SCALAR_RESULT(bpf_probe_read_user((void *)X86_SIM_L_HELPER_ARG_PTR(X86_RDI), (__u32)X86_SIM_L_READ_REG(X86_RSI), (const void *)X86_SIM_L_HELPER_ARG_PTR(X86_RDX)), X86_RDI, X86_RSI)

#define X86_SIM_BPF_CALL_bpf_probe_read_kernel() \
	X86_SIM_L_HELPER_WRITE_SCALAR_RESULT(bpf_probe_read_kernel((void *)X86_SIM_L_HELPER_ARG_PTR(X86_RDI), (__u32)X86_SIM_L_READ_REG(X86_RSI), (const void *)X86_SIM_L_HELPER_ARG_PTR(X86_RDX)), X86_RDI, X86_RSI)

#define X86_SIM_BPF_CALL_bpf_probe_read_user_str() \
	X86_SIM_L_HELPER_SCALAR_RESULT(bpf_probe_read_user_str((void *)X86_SIM_L_HELPER_ARG_PTR(X86_RDI), (__u32)X86_SIM_L_READ_REG(X86_RSI), (const void *)X86_SIM_L_HELPER_ARG_PTR(X86_RDX)))

#define X86_SIM_BPF_CALL_bpf_probe_read_kernel_str() \
	X86_SIM_L_HELPER_SCALAR_RESULT(bpf_probe_read_kernel_str((void *)X86_SIM_L_HELPER_ARG_PTR(X86_RDI), (__u32)X86_SIM_L_READ_REG(X86_RSI), (const void *)X86_SIM_L_HELPER_ARG_PTR(X86_RDX)))

#define X86_SIM_BPF_CALL_bpf_jiffies64() \
	X86_SIM_L_HELPER_READONLY_SCALAR_RESULT(bpf_jiffies64())

#define X86_SIM_BPF_CALL_bpf_get_netns_cookie() \
	X86_SIM_L_HELPER_SCALAR_RESULT(bpf_get_netns_cookie((void *)X86_SIM_L_HELPER_ARG_PTR(X86_RDI)))

#define X86_SIM_BPF_CALL_bpf_sk_assign() \
	X86_SIM_L_HELPER_SCALAR_RESULT(bpf_sk_assign((void *)X86_SIM_L_HELPER_ARG_PTR(X86_RDI), (void *)X86_SIM_L_HELPER_ARG_PTR(X86_RSI), (__u64)X86_SIM_L_READ_REG(X86_RDX)))

#define X86_SIM_BPF_CALL_bpf_ktime_get_boot_ns() \
	X86_SIM_L_HELPER_READONLY_SCALAR_RESULT(bpf_ktime_get_boot_ns())

#define X86_SIM_BPF_CALL_bpf_ringbuf_output() \
	X86_SIM_L_HELPER_SCALAR_RESULT(bpf_ringbuf_output((void *)X86_SIM_L_HELPER_ARG_PTR(X86_RDI), (void *)X86_SIM_L_HELPER_ARG_PTR(X86_RSI), (__u64)X86_SIM_L_READ_REG(X86_RDX), (__u64)X86_SIM_L_READ_REG(X86_RCX)))

#define X86_SIM_BPF_CALL_bpf_copy_from_user() \
	X86_SIM_L_HELPER_WRITE_SCALAR_RESULT(bpf_copy_from_user((void *)X86_SIM_L_HELPER_ARG_PTR(X86_RDI), (__u32)X86_SIM_L_READ_REG(X86_RSI), (const void *)X86_SIM_L_HELPER_ARG_PTR(X86_RDX)), X86_RDI, X86_RSI)

#define X86_SIM_BPF_CALL_bpf_redirect_neigh() \
	X86_SIM_L_HELPER_SCALAR_RESULT(bpf_redirect_neigh((__u32)X86_SIM_L_READ_REG(X86_RDI), (struct bpf_redir_neigh *)X86_SIM_L_HELPER_ARG_PTR(X86_RSI), (int)X86_SIM_L_READ_REG(X86_RDX), (__u64)X86_SIM_L_READ_REG(X86_RCX)))

#define X86_SIM_BPF_CALL_bpf_redirect_peer() \
	X86_SIM_L_HELPER_SCALAR_RESULT(bpf_redirect_peer((__u32)X86_SIM_L_READ_REG(X86_RDI), (__u64)X86_SIM_L_READ_REG(X86_RSI)))

#define X86_SIM_BPF_CALL_bpf_get_current_task_btf() \
	X86_SIM_L_HELPER_READONLY_POINTER_RESULT(bpf_get_current_task_btf())

#define X86_SIM_BPF_CALL_bpf_ktime_get_coarse_ns() \
	X86_SIM_L_HELPER_READONLY_SCALAR_RESULT(bpf_ktime_get_coarse_ns())

#define X86_SIM_BPF_CALL_bpf_check_mtu() \
	X86_SIM_L_HELPER_SCALAR_RESULT(bpf_check_mtu((void *)X86_SIM_L_HELPER_CTX_PTR(X86_RDI), (__u32)X86_SIM_L_READ_REG(X86_RSI), (__u32 *)X86_SIM_L_HELPER_ARG_PTR(X86_RDX), (__s32)X86_SIM_L_READ_REG(X86_RCX), (__u64)X86_SIM_L_READ_REG(X86_R8)))

#define X86_SIM_BPF_CALL_bpf_get_func_ip() \
	X86_SIM_L_HELPER_SCALAR_RESULT(bpf_get_func_ip((void *)X86_SIM_L_HELPER_CTX_PTR(X86_RDI)))

#define X86_SIM_BPF_CALL_bpf_get_attach_cookie() \
	X86_SIM_L_HELPER_SCALAR_RESULT(bpf_get_attach_cookie((void *)X86_SIM_L_HELPER_CTX_PTR(X86_RDI)))

#define X86_SIM_BPF_CALL_bpf_task_pt_regs() \
	X86_SIM_L_HELPER_SCALAR_RESULT(bpf_task_pt_regs((struct task_struct *)X86_SIM_L_HELPER_ARG_PTR(X86_RDI)))

#define X86_SIM_BPF_CALL_bpf_loop() \
	X86_SIM_L_HELPER_SCALAR_RESULT(bpf_loop((__u32)X86_SIM_L_READ_REG(X86_RDI), (void *)X86_SIM_L_HELPER_ARG_PTR(X86_RSI), (void *)X86_SIM_L_HELPER_ARG_PTR(X86_RDX), (__u64)X86_SIM_L_READ_REG(X86_RCX)))

#define X86_SIM_BPF_CALL_bpf_get_func_ret() \
	X86_SIM_L_HELPER_SCALAR_RESULT(bpf_get_func_ret((void *)X86_SIM_L_HELPER_CTX_PTR(X86_RDI), (__u64 *)X86_SIM_L_HELPER_ARG_PTR(X86_RSI)))

#define X86_SIM_BPF_CALL_bpf_xdp_load_bytes() \
	X86_SIM_L_HELPER_SCALAR_RESULT(bpf_xdp_load_bytes((struct xdp_md *)X86_SIM_L_HELPER_CTX_PTR(X86_RDI), (__u32)X86_SIM_L_READ_REG(X86_RSI), (void *)X86_SIM_L_HELPER_ARG_PTR(X86_RDX), (__u32)X86_SIM_L_READ_REG(X86_RCX)))

#define X86_SIM_BPF_CALL_bpf_ima_file_hash() \
	X86_SIM_L_HELPER_SCALAR_RESULT(bpf_ima_file_hash((struct file *)X86_SIM_L_HELPER_ARG_PTR(X86_RDI), (void *)X86_SIM_L_HELPER_ARG_PTR(X86_RSI), (__u32)X86_SIM_L_READ_REG(X86_RDX)))

#define X86_SIM_BPF_CALL_bpf_kptr_xchg() \
	X86_SIM_L_HELPER_POINTER_RESULT(bpf_kptr_xchg((void *)X86_SIM_L_HELPER_ARG_PTR(X86_RDI), (void *)X86_SIM_L_HELPER_ARG_PTR(X86_RSI)))

#define X86_SIM_BPF_CALL_bpf_this_cpu_ptr() \
	X86_SIM_L_HELPER_POINTER_RESULT(bpf_this_cpu_ptr((const void *)X86_SIM_L_HELPER_ARG_PTR(X86_RDI)))

#define X86_SIM_BPF_CALL_bpf_dynptr_from_mem() \
	X86_SIM_L_HELPER_SCALAR_RESULT(bpf_dynptr_from_mem((void *)X86_SIM_L_HELPER_ARG_PTR(X86_RDI), (__u64)X86_SIM_L_READ_REG(X86_RSI), (__u64)X86_SIM_L_READ_REG(X86_RDX), (struct bpf_dynptr *)X86_SIM_L_HELPER_ARG_PTR(X86_RCX)))

#define X86_SIM_BPF_CALL_bpf_ringbuf_reserve_dynptr() \
	X86_SIM_L_HELPER_SCALAR_RESULT(bpf_ringbuf_reserve_dynptr((void *)X86_SIM_L_HELPER_ARG_PTR(X86_RDI), (__u32)X86_SIM_L_READ_REG(X86_RSI), (__u64)X86_SIM_L_READ_REG(X86_RDX), (struct bpf_dynptr *)X86_SIM_L_HELPER_ARG_PTR(X86_RCX)))

#define X86_SIM_BPF_CALL_bpf_dynptr_write() \
	X86_SIM_L_HELPER_SCALAR_RESULT(bpf_dynptr_write((const struct bpf_dynptr *)X86_SIM_L_HELPER_ARG_PTR(X86_RDI), (__u64)X86_SIM_L_READ_REG(X86_RSI), (void *)X86_SIM_L_HELPER_ARG_PTR(X86_RDX), (__u64)X86_SIM_L_READ_REG(X86_RCX), (__u64)X86_SIM_L_READ_REG(X86_R8)))

/* Paired kernel/bpf/ringbuf.c submit/discard helpers return architectural zero. */
#define X86_SIM_BPF_CALL_bpf_strncmp() \
	X86_SIM_L_HELPER_SCALAR_RESULT(bpf_strncmp((const char *)X86_SIM_L_HELPER_ARG_PTR(X86_RDI), (__u32)X86_SIM_L_READ_REG(X86_RSI), (const char *)X86_SIM_L_HELPER_ARG_PTR(X86_RDX)))

#define X86_SIM_BPF_CALL_bpf_ringbuf_submit() \
	X86_SIM_L_HELPER_SCALAR_RESULT(({ bpf_ringbuf_submit((void *)X86_SIM_L_HELPER_ARG_PTR(X86_RDI), (__u64)X86_SIM_L_READ_REG(X86_RSI)); 0ULL; }))

#define X86_SIM_BPF_CALL_bpf_ringbuf_submit_dynptr() \
	X86_SIM_L_HELPER_SCALAR_RESULT(({ bpf_ringbuf_submit_dynptr((struct bpf_dynptr *)X86_SIM_L_HELPER_ARG_PTR(X86_RDI), (__u64)X86_SIM_L_READ_REG(X86_RSI)); 0ULL; }))

#define X86_SIM_BPF_CALL_bpf_ringbuf_discard_dynptr() \
	X86_SIM_L_HELPER_SCALAR_RESULT(({ bpf_ringbuf_discard_dynptr((struct bpf_dynptr *)X86_SIM_L_HELPER_ARG_PTR(X86_RDI), (__u64)X86_SIM_L_READ_REG(X86_RSI)); 0ULL; }))

#define X86_SIM_BPF_CALL_bpf_dynptr_read() \
	X86_SIM_L_HELPER_SCALAR_RESULT(bpf_dynptr_read((void *)X86_SIM_L_HELPER_ARG_PTR(X86_RDI), (__u64)X86_SIM_L_READ_REG(X86_RSI), (const struct bpf_dynptr *)X86_SIM_L_HELPER_ARG_PTR(X86_RDX), (__u64)X86_SIM_L_READ_REG(X86_RCX), (__u64)X86_SIM_L_READ_REG(X86_R8)))

#define X86_SIM_BPF_CALL_bpf_dynptr_data() \
	X86_SIM_L_HELPER_POINTER_RESULT(bpf_dynptr_data((const struct bpf_dynptr *)X86_SIM_L_HELPER_ARG_PTR(X86_RDI), (__u64)X86_SIM_L_READ_REG(X86_RSI), (__u64)X86_SIM_L_READ_REG(X86_RDX)))

#define X86_SIM_BPF_CALL_ID(ID) \
	do { \
		switch (KPROG_X86_HELPER_SLOT((__u64)(ID))) { \
		case KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_bpf_map_lookup_elem): \
			X86_SIM_BPF_CALL_bpf_map_lookup_elem(); \
			break; \
		case KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_bpf_map_update_elem): \
			X86_SIM_BPF_CALL_bpf_map_update_elem(); \
			break; \
		case KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_bpf_map_delete_elem): \
			X86_SIM_BPF_CALL_bpf_map_delete_elem(); \
			break; \
		case KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_bpf_probe_read): \
			X86_SIM_BPF_CALL_bpf_probe_read(); \
			break; \
		case KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_bpf_ktime_get_ns): \
			X86_SIM_BPF_CALL_bpf_ktime_get_ns(); \
			break; \
		case KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_bpf_trace_printk): \
			X86_SIM_BPF_CALL_bpf_trace_printk(); \
			break; \
		case KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_bpf_get_prandom_u32): \
			X86_SIM_BPF_CALL_bpf_get_prandom_u32(); \
			break; \
		case KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_bpf_get_smp_processor_id): \
			X86_SIM_BPF_CALL_bpf_get_smp_processor_id(); \
			break; \
		case KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_bpf_skb_store_bytes): \
			X86_SIM_BPF_CALL_bpf_skb_store_bytes(); \
			break; \
		case KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_bpf_l3_csum_replace): \
			X86_SIM_BPF_CALL_bpf_l3_csum_replace(); \
			break; \
		case KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_bpf_l4_csum_replace): \
			X86_SIM_BPF_CALL_bpf_l4_csum_replace(); \
			break; \
		case KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_bpf_tail_call): \
			X86_SIM_BPF_CALL_bpf_tail_call(); \
			break; \
		case KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_bpf_get_current_pid_tgid): \
			X86_SIM_BPF_CALL_bpf_get_current_pid_tgid(); \
			break; \
		case KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_bpf_get_current_uid_gid): \
			X86_SIM_BPF_CALL_bpf_get_current_uid_gid(); \
			break; \
		case KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_bpf_get_current_comm): \
			X86_SIM_BPF_CALL_bpf_get_current_comm(); \
			break; \
		case KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_bpf_skb_get_tunnel_key): \
			X86_SIM_BPF_CALL_bpf_skb_get_tunnel_key(); \
			break; \
		case KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_bpf_skb_set_tunnel_key): \
			X86_SIM_BPF_CALL_bpf_skb_set_tunnel_key(); \
			break; \
		case KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_bpf_redirect): \
			X86_SIM_BPF_CALL_bpf_redirect(); \
			break; \
		case KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_bpf_perf_event_output): \
			X86_SIM_BPF_CALL_bpf_perf_event_output(); \
			break; \
		case KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_bpf_skb_load_bytes): \
			X86_SIM_BPF_CALL_bpf_skb_load_bytes(); \
			break; \
		case KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_bpf_get_stackid): \
			X86_SIM_BPF_CALL_bpf_get_stackid(); \
			break; \
		case KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_bpf_csum_diff): \
			X86_SIM_BPF_CALL_bpf_csum_diff(); \
			break; \
		case KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_bpf_skb_change_type): \
			X86_SIM_BPF_CALL_bpf_skb_change_type(); \
			break; \
		case KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_bpf_get_current_task): \
			X86_SIM_BPF_CALL_bpf_get_current_task(); \
			break; \
		case KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_bpf_probe_write_user): \
			X86_SIM_BPF_CALL_bpf_probe_write_user(); \
			break; \
		case KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_bpf_current_task_under_cgroup): \
			X86_SIM_BPF_CALL_bpf_current_task_under_cgroup(); \
			break; \
		case KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_bpf_skb_change_tail): \
			X86_SIM_BPF_CALL_bpf_skb_change_tail(); \
			break; \
		case KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_bpf_skb_pull_data): \
			X86_SIM_BPF_CALL_bpf_skb_pull_data(); \
			break; \
		case KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_bpf_skb_change_head): \
			X86_SIM_BPF_CALL_bpf_skb_change_head(); \
			break; \
		case KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_bpf_xdp_adjust_head): \
			X86_SIM_BPF_CALL_bpf_xdp_adjust_head(); \
			break; \
		case KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_bpf_probe_read_str): \
			X86_SIM_BPF_CALL_bpf_probe_read_str(); \
			break; \
		case KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_bpf_get_socket_cookie): \
			X86_SIM_BPF_CALL_bpf_get_socket_cookie(); \
			break; \
		case KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_bpf_skb_adjust_room): \
			X86_SIM_BPF_CALL_bpf_skb_adjust_room(); \
			break; \
		case KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_bpf_xdp_adjust_meta): \
			X86_SIM_BPF_CALL_bpf_xdp_adjust_meta(); \
			break; \
		case KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_bpf_override_return): \
			X86_SIM_BPF_CALL_bpf_override_return(); \
			break; \
		case KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_bpf_xdp_adjust_tail): \
			X86_SIM_BPF_CALL_bpf_xdp_adjust_tail(); \
			break; \
		case KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_bpf_get_stack): \
			X86_SIM_BPF_CALL_bpf_get_stack(); \
			break; \
		case KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_bpf_skb_load_bytes_relative): \
			X86_SIM_BPF_CALL_bpf_skb_load_bytes_relative(); \
			break; \
		case KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_bpf_fib_lookup): \
			X86_SIM_BPF_CALL_bpf_fib_lookup(); \
			break; \
		case KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_bpf_get_current_cgroup_id): \
			X86_SIM_BPF_CALL_bpf_get_current_cgroup_id(); \
			break; \
		case KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_bpf_sk_lookup_udp): \
			X86_SIM_BPF_CALL_bpf_sk_lookup_udp(); \
			break; \
		case KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_bpf_sk_release): \
			X86_SIM_BPF_CALL_bpf_sk_release(); \
			break; \
		case KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_bpf_map_push_elem): \
			X86_SIM_BPF_CALL_bpf_map_push_elem(); \
			break; \
		case KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_bpf_map_pop_elem): \
			X86_SIM_BPF_CALL_bpf_map_pop_elem(); \
			break; \
		case KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_bpf_sk_fullsock): \
			X86_SIM_BPF_CALL_bpf_sk_fullsock(); \
			break; \
		case KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_bpf_skc_lookup_tcp): \
			X86_SIM_BPF_CALL_bpf_skc_lookup_tcp(); \
			break; \
		case KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_bpf_strtol): \
			X86_SIM_BPF_CALL_bpf_strtol(); \
			break; \
		case KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_bpf_send_signal): \
			X86_SIM_BPF_CALL_bpf_send_signal(); \
			break; \
		case KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_bpf_probe_read_user): \
			X86_SIM_BPF_CALL_bpf_probe_read_user(); \
			break; \
		case KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_bpf_probe_read_kernel): \
			X86_SIM_BPF_CALL_bpf_probe_read_kernel(); \
			break; \
		case KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_bpf_probe_read_user_str): \
			X86_SIM_BPF_CALL_bpf_probe_read_user_str(); \
			break; \
		case KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_bpf_probe_read_kernel_str): \
			X86_SIM_BPF_CALL_bpf_probe_read_kernel_str(); \
			break; \
		case KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_bpf_jiffies64): \
			X86_SIM_BPF_CALL_bpf_jiffies64(); \
			break; \
		case KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_bpf_get_netns_cookie): \
			X86_SIM_BPF_CALL_bpf_get_netns_cookie(); \
			break; \
		case KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_bpf_sk_assign): \
			X86_SIM_BPF_CALL_bpf_sk_assign(); \
			break; \
		case KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_bpf_ktime_get_boot_ns): \
			X86_SIM_BPF_CALL_bpf_ktime_get_boot_ns(); \
			break; \
		case KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_bpf_ringbuf_output): \
			X86_SIM_BPF_CALL_bpf_ringbuf_output(); \
			break; \
		case KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_bpf_copy_from_user): \
			X86_SIM_BPF_CALL_bpf_copy_from_user(); \
			break; \
		case KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_bpf_redirect_neigh): \
			X86_SIM_BPF_CALL_bpf_redirect_neigh(); \
			break; \
		case KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_bpf_redirect_peer): \
			X86_SIM_BPF_CALL_bpf_redirect_peer(); \
			break; \
		case KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_bpf_get_current_task_btf): \
			X86_SIM_BPF_CALL_bpf_get_current_task_btf(); \
			break; \
		case KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_bpf_ktime_get_coarse_ns): \
			X86_SIM_BPF_CALL_bpf_ktime_get_coarse_ns(); \
			break; \
		case KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_bpf_check_mtu): \
			X86_SIM_BPF_CALL_bpf_check_mtu(); \
			break; \
		case KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_bpf_get_func_ip): \
			X86_SIM_BPF_CALL_bpf_get_func_ip(); \
			break; \
		case KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_bpf_get_attach_cookie): \
			X86_SIM_BPF_CALL_bpf_get_attach_cookie(); \
			break; \
		case KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_bpf_task_pt_regs): \
			X86_SIM_BPF_CALL_bpf_task_pt_regs(); \
			break; \
		case KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_bpf_loop): \
			X86_SIM_BPF_CALL_bpf_loop(); \
			break; \
		case KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_bpf_get_func_ret): \
			X86_SIM_BPF_CALL_bpf_get_func_ret(); \
			break; \
		case KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_bpf_xdp_load_bytes): \
			X86_SIM_BPF_CALL_bpf_xdp_load_bytes(); \
			break; \
		case KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_bpf_ima_file_hash): \
			X86_SIM_BPF_CALL_bpf_ima_file_hash(); \
			break; \
		default: X86_SIM_L_UNSUPPORTED_HELPER(); break; \
		} \
	} while (0)

#define X86_SIM_BPF_CALL_REG(REG)                                           \
	X86_SIM_BPF_CALL_ID(X86_SIM_L_READ_REG(REG))

#define X86_SIM_X86_RET()                                                  \
	do {                                                               \
        if (__x86_rsp.ptr != (void *)0) X86_SIM_L_ARCHITECTURAL_FAULT(); \
		return (__u32)X86_SIM_L_READ_REG(X86_RAX);                 \
	} while (0)

#define X86_SIM_X86_CALL(LABEL, RETURN_ADDR)                               \
	do {                                                               \
		__x86_rsp.ptr = KPROG_PTR_ADD64_BITS(__x86_rsp.ptr, -8);                \
		X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64,\
				      (RETURN_ADDR));                     \
		goto LABEL;                                               \
	} while (0)

/* Code addresses use linked-code offsets, in a namespace distinct from helper
 * numbers. MOV/CMOV preserve this representation through ordinary 64-bit copies. */
#define X86_SIM_X86_CODE_ADDRESS(DST, ADDRESS)                              \
	X86_SIM_L_WRITE_REG_PTR_TAG((DST), (void *)(long)(ADDRESS), X86_SIM_TAG_CODE)

#define X86_SIM_X86_SUB_RET(DISPATCH_LABEL)                                \
	do {                                                               \
		__x86_sim_ret_addr = X86_SIM_L_STACK_READ(                 \
			(__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);         \
		__x86_rsp.ptr = KPROG_PTR_ADD64_BITS(__x86_rsp.ptr, +8); \
            X86_SIM_L_STACK_RELEASE((__s64)(long)__x86_rsp.ptr - 8);                \
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
		if (KPROG_X86_BRANCH_BACKWARD((CURRENT), (TARGET))) {         \
			X86_SIM_X86_JCC_BACKWARD((CC), LABEL, ID);         \
		} else if (X86_SIM_L_EVAL_CC(CC)) {                        \
			X86_SIM_X86_JMP((CURRENT), (TARGET), LABEL);       \
		}                                                           \
		asm volatile("" ::: "memory");                            \
	} while (0)

#define X86_SIM_X86_JCC(CC, CURRENT, TARGET, LABEL)                         \
	X86_SIM_X86_JCC_IMPL((CC), (CURRENT), (TARGET), LABEL, __LINE__)

#define X86_SIM_X86_SUB_JMP(CURRENT, TARGET, LABEL)                         \
	X86_SIM_X86_JMP((CURRENT), (TARGET), LABEL)

#define X86_SIM_X86_SUB_JCC(CC, CURRENT, TARGET, LABEL)                     \
	X86_SIM_X86_JCC((CC), (CURRENT), (TARGET), LABEL)

#define X86_SIM_LICENSE() char LICENSE[] SEC("license") = "GPL"

#endif
