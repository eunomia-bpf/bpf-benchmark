#ifndef ARM64_SIM_LOCAL_BPF_H
#define ARM64_SIM_LOCAL_BPF_H

#if defined(__COMPCERT__)
#include "../formal/c/Platform.h"
#elif !defined(__VMLINUX_H__)
#include <linux/bpf.h>
#endif
#include <bpf_helpers.h>
#include "../../kinsn/module/include/native_lab_input.h"

#include "arm64_sim.h"
#include "../formal/generated/abi_load.h"
#include "../formal/generated/arm64_cond.h"
#include "../formal/generated/ptr_add.h"
#include "../formal/generated/arm64_flags.h"
#include "../formal/generated/arm64_alu_result.h"
#include "../formal/generated/arm64_alu_handler.h"
#include "../formal/generated/arm64_flag_handler.h"
#include "../formal/generated/arm64_logic_flag_handler.h"
#include "../formal/generated/arm64_ccmp_handler.h"
#include "../formal/generated/arm64_ccmp_decode.h"
#include "../formal/generated/arm64_mod.h"
#include "../formal/generated/arm64_alu_operand.h"
#include "../formal/generated/arm64_alu_operand_select.h"
#include "../formal/generated/arm64_flag_operand.h"
#include "../formal/generated/arm64_dispatch_family.h"
#include "../formal/generated/arm64_dispatch_singleton.h"
#include "../formal/generated/arm64_imm_operand.h"
#include "../formal/generated/arm64_bitfield.h"
#include "../formal/generated/arm64_mul.h"
#include "../formal/generated/arm64_extrev.h"
#include "../formal/generated/arm64_csel.h"
#include "../formal/generated/arm64_csel_ptr.h"
#include "../formal/generated/arm64_branch.h"
#include "../formal/generated/arm64_branch_emit.h"
#include "../formal/generated/arm64_movk.h"
#include "../formal/generated/arm64_shift.h"
#include "../formal/generated/arm64_reduction.h"
#include "../formal/generated/arm64_unary.h"
#include "../formal/generated/arm64_cneg.h"
#include "../formal/generated/arm64_orn.h"
#include "../formal/generated/arm64_mem_offset.h"
#include "../formal/generated/arm64_mem_index.h"
#include "../formal/generated/arm64_mem_index_value.h"
#include "../formal/generated/arm64_reg_presence.h"
#include "../formal/generated/arm64_reg_dispatch.h"
#include "../formal/generated/arm64_fmov.h"
#include "../formal/generated/arm64_fmov_dest.h"
#include "../formal/generated/arm64_load_bytes.h"
#include "../formal/generated/arm64_store_bytes.h"
#include "../formal/generated/arm64_byte_lane.h"
#include "../formal/generated/arm64_mem_dispatch.h"
#include "../formal/generated/arm64_stack_tag.h"
#include "../formal/generated/arm64_stack_arm.h"
#include "../formal/generated/arm64_stack_arena.h"
#include "../formal/generated/arm64_stack_index.h"
#include "../formal/generated/arm64_stack_write_lanes.h"
#include "../formal/generated/arm64_stack_write_tag_action.h"
#include "../formal/generated/arm64_stack_read_tag_source.h"
#include "../formal/generated/arm64_helper_arg_ptr.h"
#include "../formal/generated/arm64_mem_base_src.h"
#include "../formal/generated/arm64_dq_mem.h"
#include "../formal/generated/arm64_dq_mem_extra.h"
#include "../formal/generated/arm64_pair_mem.h"
#include "../formal/generated/arm64_mem_prepost.h"
#include "../formal/generated/arm64_vreg.h"
#include "../formal/generated/arm64_vreg_field.h"
#include "../formal/generated/arm64_write_arm.h"

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

/*
 * The dispatch cell index a decoded register number names equals the hand-written
 * `ARM64_SIM_L_FOR_EACH_GPR` order: cell `n` is `ARM64_X<n>`. The generated
 * `arm64_reg_dispatch.h` already pins each `ARM64_X<n>` to its number; these
 * asserts bind the cell selector itself to the same order, so the two cannot
 * drift apart.
 */
_Static_assert(KPROG_ARM64_GPR_CELL(ARM64_X0) == 0U,
	       "arm64 gpr dispatch cell drift");
_Static_assert(KPROG_ARM64_GPR_CELL(ARM64_X15) == 15U,
	       "arm64 gpr dispatch cell drift");
_Static_assert(KPROG_ARM64_GPR_CELL(ARM64_X30) == 30U,
	       "arm64 gpr dispatch cell drift");

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
#define ARM64_SIM_TAG_CODE 9U
#define ARM64_SIM_TAG_RETURN 10U
#include "../formal/generated/arm64_mem_write_arm.h"
#include "../formal/generated/arm64_adrp.h"
#include "../formal/generated/arm64_stlxr.h"
#include "../formal/generated/arm64_mov.h"
#include "../formal/generated/arm64_ldrsx.h"
#include "../formal/generated/arm64_ldrsx_op.h"
#include "../formal/generated/arm64_load_tag.h"
#include "../formal/generated/arm64_pair_load_tag.h"
#define ARM64_SIM_L_ADRP_TAG(OP)                                            \
	KPROG_ARM64_ADRP_TAG((OP), ARM64_SIM_L_UNSUPPORTED_OPCODE())
#define ARM64_SIM_L_STLXR_VALUE(OP, FAILURE)                                \
	KPROG_ARM64_STLXR_VALUE((OP), ARM64_WIDTH_32, (FAILURE),           \
				ARM64_SIM_L_UNSUPPORTED_OPCODE())
#define ARM64_SIM_L_MOV_PTR_TAG_PATH(OP, WIDTH)                             \
	KPROG_ARM64_MOV_PTR_TAG_PATH((OP), (WIDTH),                        \
				ARM64_SIM_L_UNSUPPORTED_OPCODE())
#define ARM64_SIM_L_LDRSX_LOAD_WIDTH(OP)                                    \
	KPROG_ARM64_LDRSX_LOAD_WIDTH((OP), ARM64_SIM_L_UNSUPPORTED_OPCODE())
#define ARM64_SIM_L_LDRSX_SXOP(OP)                                          \
	KPROG_ARM64_LDRSX_SXOP((OP), ARM64_SIM_L_UNSUPPORTED_OPCODE())
#define ARM64_SIM_L_LOAD_TAG_PRESERVE(OP, TAG, WIDTH)                       \
	KPROG_ARM64_LOAD_TAG_PRESERVE((OP), (TAG), (WIDTH),                \
				      ARM64_SIM_L_UNSUPPORTED_OPCODE())
#define ARM64_SIM_L_PAIR_LOAD_TAG_ROUTE(OP, TAG_LO, TAG_HI, WIDTH)          \
	KPROG_ARM64_PAIR_LOAD_TAG_ROUTE((OP), (TAG_LO), (TAG_HI), (WIDTH), \
					ARM64_SIM_L_UNSUPPORTED_OPCODE())

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

_Static_assert(__builtin_offsetof(struct arm64_sim_xdp_abi, data) ==
	       KPROG_ABI_XDP_DATA_OFF, "xdp data offset disagrees with ABI spec");
_Static_assert(__builtin_offsetof(struct arm64_sim_xdp_abi, data_end) ==
	       KPROG_ABI_XDP_DATA_END_OFF,
	       "xdp data_end offset disagrees with ABI spec");
_Static_assert(__builtin_offsetof(struct arm64_sim_skb_abi, data) ==
	       KPROG_ABI_SKB_DATA_OFF, "skb data offset disagrees with ABI spec");
_Static_assert(__builtin_offsetof(struct arm64_sim_skb_abi, data_end) ==
	       KPROG_ABI_SKB_DATA_END_OFF,
	       "skb data_end offset disagrees with ABI spec");

#define ARM64_SIM_L_UNSPECIFIED() NATIVE_LAB_ENTRY_INPUT(NATIVE_LAB_INPUT_UNSPECIFIED)

/* Each potentially faulting native read has a fresh environment outcome.
 * The fault arm precedes writeback and all data effects. Its fallthrough is
 * the next four-byte native instruction, as in ex_handler_bpf. Simulator
 * stack storage and translated XDP/SKB context fields are mapped objects.
 * Hosts may supply a dynamic choice to exercise both outcomes explicitly.
 */
#ifndef ARM64_SIM_L_READ_FAULT
#define ARM64_SIM_L_READ_FAULT_INTO(OUTPUT, BASE, INDEX, AUX, IMM) \
    do { \
        int __a64_fault_result = 0; \
        if ((BASE) != ARM64_SP) { \
            __u8 __a64_fault_tag; ARM64_SIM_L_REG_TAG_INTO(__a64_fault_tag, (BASE)); \
            if (__a64_fault_tag != ARM64_SIM_TAG_STACK && \
                __a64_fault_tag != ARM64_SIM_TAG_RELOC_ADDR && \
                !((__a64_sim_is_xdp || __a64_sim_abi_kind == KPROG_ABI_KIND_SKB) && \
                  __a64_fault_tag == ARM64_SIM_TAG_ABI)) { \
                if (__a64_fault_tag == ARM64_SIM_TAG_SCALAR) { \
                    __u64 __a64_fault_raw; __s64 __a64_fault_off; \
                    ARM64_SIM_L_READ_REG_RAW_INTO(__a64_fault_raw, (BASE)); \
                    ARM64_SIM_L_MEM_BASE_OFF_INTO(__a64_fault_off, (AUX), (INDEX), (IMM)); \
                    __a64_fault_result = (__a64_fault_raw + (__u64)__a64_fault_off + \
                        (__u64)KPROG_ARM64_MEM_PREPOST_PRE_DELTA((AUX), (IMM))) < 4096ULL; \
                } \
                if (!__a64_fault_result) __a64_fault_result = !!ARM64_SIM_L_UNSPECIFIED(); \
            } \
        } \
        (OUTPUT) = __a64_fault_result; \
    } while (0)
#define ARM64_SIM_L_READ_FAULT(BASE, INDEX, AUX, IMM) \
    ({ int __a64_fault_observation; \
       ARM64_SIM_L_READ_FAULT_INTO(__a64_fault_observation, (BASE), (INDEX), (AUX), (IMM)); \
       __a64_fault_observation; })
#else
#define ARM64_SIM_L_READ_FAULT_INTO(OUTPUT, BASE, INDEX, AUX, IMM) \
    do { (OUTPUT) = ARM64_SIM_L_READ_FAULT((BASE), (INDEX), (AUX), (IMM)); } while (0)
#endif
/* Native callers may also override the expression hook after inclusion.
 * Exported C uses its standard output form; both default forms share a body. */
#if defined(__COMPCERT__)
#define ARM64_SIM_L_READ_FAULT_CALL_INTO(OUTPUT, BASE, INDEX, AUX, IMM) \
    ARM64_SIM_L_READ_FAULT_INTO((OUTPUT), (BASE), (INDEX), (AUX), (IMM))
#else
#define ARM64_SIM_L_READ_FAULT_CALL_INTO(OUTPUT, BASE, INDEX, AUX, IMM) \
    do { (OUTPUT) = ARM64_SIM_L_READ_FAULT((BASE), (INDEX), (AUX), (IMM)); } while (0)
#endif
#define ARM64_SIM_L_CLEAR_READ_DEST(DST) \
    ARM64_SIM_L_WRITE_REG_WIDTH((DST), 0ULL, ARM64_WIDTH_64)

#define ARM64_SIM_L_DECLARE_REG(REG, NAME)                                  \
	union arm64_sim_gpr __a64_##NAME = { .x = (REG) == ARM64_X30 ? 0ULL : ARM64_SIM_L_UNSPECIFIED() };                    \
	__u8 __a64_##NAME##_tag = ARM64_SIM_TAG_SCALAR;

#define ARM64_SIM_L_REG_CELL(REG, NAME) [KPROG_ARM64_GPR_CELL(REG)] = &__a64_##NAME,
#define ARM64_SIM_L_TAG_CELL(REG, NAME) [KPROG_ARM64_GPR_CELL(REG)] = &__a64_##NAME##_tag,

/* Packed tag words retain verifier-known bits across field updates. */
typedef __u64 arm64_sim_tag_word __attribute__((may_alias));
#define ARM64_SIM_TAG_STORAGE_BYTES(CAPACITY) ((KPROG_ARM64_STACK_TAG_SLOTS(CAPACITY)+7U)&~7U)
#define ARM64_SIM_L_TAG_WORD_PTR(INDEX) ((volatile arm64_sim_tag_word *)(void *)&__a64_stack_tag[(__u64)(INDEX)&~7ULL])
#define ARM64_SIM_L_TAG_GET_INTO(OUTPUT, INDEX) \
    do { __u64 __ti=(INDEX); (OUTPUT)=(__u8)(*ARM64_SIM_L_TAG_WORD_PTR(__ti) >> ((__ti&7U)*8U)); } while (0)
#define ARM64_SIM_L_TAG_GET(INDEX) \
    ({ __u8 __a64_tag_result; ARM64_SIM_L_TAG_GET_INTO(__a64_tag_result, (INDEX)); __a64_tag_result; })
#define ARM64_SIM_L_TAG_SET(INDEX, TAG) do { __u64 __ti=(INDEX); __u32 __ts=(__ti&7U)*8U; volatile arm64_sim_tag_word *__tp=ARM64_SIM_L_TAG_WORD_PTR(__ti); __u64 __tv=*__tp; *__tp=(__tv&~(255ULL<<__ts))|((__u64)(__u8)(TAG)<<__ts); } while (0)
#ifndef ARM64_SIM_STACK_PAYLOAD_WORDS
#define ARM64_SIM_STACK_PAYLOAD_WORDS KPROG_ARM64_STACK_WORDS(ARM64_SIM_STACK_BYTES)
#endif
#ifndef ARM64_SIM_L_STACK_PAYLOAD_LOAD
#define ARM64_SIM_L_STACK_PAYLOAD_LOAD(INDEX) (__a64_stack_payload[(INDEX)])
#define ARM64_SIM_L_STACK_PAYLOAD_STORE(INDEX, VALUE) do { __a64_stack_payload[(INDEX)] = (VALUE); } while (0)
#endif
#ifdef ARM64_SIM_ENABLE_STACK
#define ARM64_SIM_L_DECLARE_STACK()                                         \
	volatile union {                                                            \
		__u8 b[ARM64_SIM_STACK_BYTES];                            \
		__u64 q[KPROG_ARM64_STACK_WORDS(ARM64_SIM_STACK_BYTES)];  \
	} __a64_stack;                                            \
	volatile __u64 __a64_stack_payload[ARM64_SIM_STACK_PAYLOAD_WORDS]; \
	__u8 __a64_stack_tag[ARM64_SIM_TAG_STORAGE_BYTES(ARM64_SIM_STACK_BYTES)] __attribute__((aligned(8))) = {0};\
	__s64 __a64_sp = 0
#else
#define ARM64_SIM_L_DECLARE_STACK()                                         \
	volatile union {                                                            \
		__u8 b[1];                                                \
		__u64 q[KPROG_ARM64_STACK_WORDS(1U)];                     \
	} __a64_stack;                                            \
	__u64 __a64_stack_payload[KPROG_ARM64_STACK_WORDS(1U)];            \
	__u8 __a64_stack_tag[ARM64_SIM_TAG_STORAGE_BYTES(1U)] __attribute__((aligned(8))) = {0};     \
	__s64 __a64_sp = 0
#endif

#define ARM64_SIM_L_VECTOR_LO(INDEX) (__a64_vectors[(INDEX)].lo)
#define ARM64_SIM_L_VECTOR_HI(INDEX) (__a64_vectors[(INDEX)].hi)
#define __a64_v0 ARM64_SIM_L_VECTOR_LO(0)
#define __a64_v0_hi ARM64_SIM_L_VECTOR_HI(0)
#define ARM64_SIM_L_DECLARE_STATE()                                         \
	__u64 __a64_numeric_sp __attribute__((unused)) = 0;               \
	__u64 __a64_numeric_return __attribute__((unused)) = 0;            \
	__u8 __a64_numeric_sp_valid __attribute__((unused)) = 0;           \
	__u8 __a64_numeric_return_valid __attribute__((unused)) = 0;       \
	__u8 __a64_sim_is_xdp __attribute__((unused)) = 0;               \
	void *__a64_sim_helper_ctx __attribute__((unused)) = (void *)0;                            \
	void *__a64_sim_helper_abi_base __attribute__((unused)) = (void *)0;                       \
	ARM64_SIM_L_FOR_EACH_GPR(ARM64_SIM_L_DECLARE_REG)                  \
	union arm64_sim_gpr *const __a64_cells[KPROG_ARM64_GPR_COUNT] = { \
		ARM64_SIM_L_FOR_EACH_GPR(ARM64_SIM_L_REG_CELL) };           \
	__u8 *const __a64_tag_cells[KPROG_ARM64_GPR_COUNT] = {            \
		ARM64_SIM_L_FOR_EACH_GPR(ARM64_SIM_L_TAG_CELL) };           \
	__u8 __a64_n = ARM64_SIM_L_UNSPECIFIED() & 1;                                                  \
	__u8 __a64_z = ARM64_SIM_L_UNSPECIFIED() & 1;                                                  \
	__u8 __a64_c = ARM64_SIM_L_UNSPECIFIED() & 1;                                                  \
	__u8 __a64_v = ARM64_SIM_L_UNSPECIFIED() & 1;                                                  \
	__u64 __a64_lr = 0;                                                \
	struct { __u64 lo, hi; } __a64_vectors[32] = { { ARM64_SIM_L_UNSPECIFIED(), ARM64_SIM_L_UNSPECIFIED() }, { ARM64_SIM_L_UNSPECIFIED(), ARM64_SIM_L_UNSPECIFIED() }, { ARM64_SIM_L_UNSPECIFIED(), ARM64_SIM_L_UNSPECIFIED() }, { ARM64_SIM_L_UNSPECIFIED(), ARM64_SIM_L_UNSPECIFIED() }, { ARM64_SIM_L_UNSPECIFIED(), ARM64_SIM_L_UNSPECIFIED() }, { ARM64_SIM_L_UNSPECIFIED(), ARM64_SIM_L_UNSPECIFIED() }, { ARM64_SIM_L_UNSPECIFIED(), ARM64_SIM_L_UNSPECIFIED() }, { ARM64_SIM_L_UNSPECIFIED(), ARM64_SIM_L_UNSPECIFIED() }, { ARM64_SIM_L_UNSPECIFIED(), ARM64_SIM_L_UNSPECIFIED() }, { ARM64_SIM_L_UNSPECIFIED(), ARM64_SIM_L_UNSPECIFIED() }, { ARM64_SIM_L_UNSPECIFIED(), ARM64_SIM_L_UNSPECIFIED() }, { ARM64_SIM_L_UNSPECIFIED(), ARM64_SIM_L_UNSPECIFIED() }, { ARM64_SIM_L_UNSPECIFIED(), ARM64_SIM_L_UNSPECIFIED() }, { ARM64_SIM_L_UNSPECIFIED(), ARM64_SIM_L_UNSPECIFIED() }, { ARM64_SIM_L_UNSPECIFIED(), ARM64_SIM_L_UNSPECIFIED() }, { ARM64_SIM_L_UNSPECIFIED(), ARM64_SIM_L_UNSPECIFIED() }, { ARM64_SIM_L_UNSPECIFIED(), ARM64_SIM_L_UNSPECIFIED() }, { ARM64_SIM_L_UNSPECIFIED(), ARM64_SIM_L_UNSPECIFIED() }, { ARM64_SIM_L_UNSPECIFIED(), ARM64_SIM_L_UNSPECIFIED() }, { ARM64_SIM_L_UNSPECIFIED(), ARM64_SIM_L_UNSPECIFIED() }, { ARM64_SIM_L_UNSPECIFIED(), ARM64_SIM_L_UNSPECIFIED() }, { ARM64_SIM_L_UNSPECIFIED(), ARM64_SIM_L_UNSPECIFIED() }, { ARM64_SIM_L_UNSPECIFIED(), ARM64_SIM_L_UNSPECIFIED() }, { ARM64_SIM_L_UNSPECIFIED(), ARM64_SIM_L_UNSPECIFIED() }, { ARM64_SIM_L_UNSPECIFIED(), ARM64_SIM_L_UNSPECIFIED() }, { ARM64_SIM_L_UNSPECIFIED(), ARM64_SIM_L_UNSPECIFIED() }, { ARM64_SIM_L_UNSPECIFIED(), ARM64_SIM_L_UNSPECIFIED() }, { ARM64_SIM_L_UNSPECIFIED(), ARM64_SIM_L_UNSPECIFIED() }, { ARM64_SIM_L_UNSPECIFIED(), ARM64_SIM_L_UNSPECIFIED() }, { ARM64_SIM_L_UNSPECIFIED(), ARM64_SIM_L_UNSPECIFIED() }, { ARM64_SIM_L_UNSPECIFIED(), ARM64_SIM_L_UNSPECIFIED() }, { ARM64_SIM_L_UNSPECIFIED(), ARM64_SIM_L_UNSPECIFIED() } }

#if defined(__COMPCERT__)
#define ARM64_SIM_L_ENTRY_XDP_FIELD(CTX, FIELD) \
	kprog_c_context_pointer((CTX), KPROG_ABI_KIND_XDP, __builtin_offsetof(struct xdp_md, FIELD))
#else
#define ARM64_SIM_L_ENTRY_XDP_FIELD(CTX, FIELD) ((void *)(long)(CTX)->FIELD)
#endif
/* A formal program adapter borrows the completed entry locals here. */
#define ARM64_SIM_L_ENTRY_BOUND() ((void)0)
#define ARM64_SIM_ENTRY_XDP(CTX)                                            \
	struct arm64_sim_xdp_abi __a64_sim_abi = {                         \
		.data = ARM64_SIM_L_ENTRY_XDP_FIELD(CTX, data),             \
		.data_end = ARM64_SIM_L_ENTRY_XDP_FIELD(CTX, data_end),     \
	};                                                               \
	struct __sk_buff *__a64_sim_skb_ctx = (struct __sk_buff *)0;      \
	__u8 __a64_sim_abi_kind = KPROG_ABI_KIND_XDP;                    \
	ARM64_SIM_L_DECLARE_STATE();                                      \
	ARM64_SIM_L_DECLARE_STACK();                                      \
	__a64_sim_is_xdp = 1;                                          \
	__a64_sim_helper_ctx = (void *)(CTX);                             \
	__a64_sim_helper_abi_base = &__a64_sim_abi;                       \
	__a64_x0.ptr = (void *)(CTX);                                    \
	__a64_x30_tag = ARM64_SIM_TAG_RETURN;                           \
	__a64_x0_tag = ARM64_SIM_TAG_ABI; ARM64_SIM_L_ENTRY_BOUND()

#define ARM64_SIM_ENTRY_SKB(CTX)                                            \
	struct arm64_sim_skb_abi __a64_sim_abi = {0};                       \
	struct __sk_buff *__a64_sim_skb_ctx = (CTX);                      \
	__u8 __a64_sim_abi_kind = KPROG_ABI_KIND_SKB;                    \
	ARM64_SIM_L_DECLARE_STATE();                                      \
	ARM64_SIM_L_DECLARE_STACK();                                      \
	__a64_sim_helper_ctx = (void *)(CTX);                             \
	__a64_sim_helper_abi_base = bpf_cast_to_kern_ctx((void *)(CTX));                       \
	__a64_x0.ptr = __a64_sim_helper_abi_base;                                    \
	__a64_x30_tag = ARM64_SIM_TAG_RETURN;                           \
	__a64_x0_tag = ARM64_SIM_TAG_ABI; ARM64_SIM_L_ENTRY_BOUND()

/* Raw tracing contexts keep the actual verifier context pointer. */
#define ARM64_SIM_ABI_KIND_RAW 2U
_Static_assert(ARM64_SIM_ABI_KIND_RAW != KPROG_ABI_KIND_XDP && ARM64_SIM_ABI_KIND_RAW != KPROG_ABI_KIND_SKB, "raw context ABI must have its own kind");

#define ARM64_SIM_ENTRY_RAW(CTX)                                            \
	struct arm64_sim_skb_abi __a64_sim_abi = {0};                       \
	struct __sk_buff *__a64_sim_skb_ctx = (struct __sk_buff *)0;       \
	__u8 __a64_sim_abi_kind = ARM64_SIM_ABI_KIND_RAW;                                      \
	ARM64_SIM_L_DECLARE_STATE();                                      \
	ARM64_SIM_L_DECLARE_STACK();                                      \
	__a64_sim_helper_ctx = (void *)(CTX);                             \
	__a64_sim_helper_abi_base = (void *)(CTX);                        \
	__a64_x0.ptr = (void *)(CTX);                                      \
	__a64_x30_tag = ARM64_SIM_TAG_RETURN; \
	__a64_x0_tag = ARM64_SIM_TAG_ABI; ARM64_SIM_L_ENTRY_BOUND()

/* Invocation-stable coordinate inputs are fetched only on the first use.
 * Payloads remain relative for stack indexing; numeric views carry native bits.
 * The bound entry ABI preserves source SP, including stripped save deltas.
 * Output forms share the production bodies with the public expression APIs. */
#define ARM64_SIM_L_STACK_BASE_INTO(OUTPUT) \
do { \
    if (!__a64_numeric_sp_valid) { \
        __a64_numeric_sp = NATIVE_LAB_ENTRY_INPUT(NATIVE_LAB_INPUT_SP); \
        __a64_numeric_sp_valid = 1; \
    } \
    (OUTPUT) = __a64_numeric_sp; \
} while (0)

#define ARM64_SIM_L_STACK_BASE() \
({ __u64 __a64_stack_base_result; \
   ARM64_SIM_L_STACK_BASE_INTO(__a64_stack_base_result); \
   __a64_stack_base_result; })

#define ARM64_SIM_L_RETURN_BASE_INTO(OUTPUT) \
do { \
    if (!__a64_numeric_return_valid) { \
        __a64_numeric_return = NATIVE_LAB_ENTRY_INPUT(NATIVE_LAB_INPUT_RETURN); \
        __a64_numeric_return_valid = 1; \
    } \
    (OUTPUT) = __a64_numeric_return; \
} while (0)

#define ARM64_SIM_L_RETURN_BASE() \
({ __u64 __a64_return_base_result; \
   ARM64_SIM_L_RETURN_BASE_INTO(__a64_return_base_result); \
   __a64_return_base_result; })

#define ARM64_SIM_L_MATERIALIZE_INTO(OUTPUT, VALUE, TAG) \
do { \
    __u64 __a64_mat_value = (VALUE); \
    __u8 __a64_mat_tag = (TAG); \
    if (__a64_mat_tag == ARM64_SIM_TAG_STACK) { \
        __u64 __a64_mat_base; \
        ARM64_SIM_L_STACK_BASE_INTO(__a64_mat_base); \
        __a64_mat_value += __a64_mat_base; \
    } else if (__a64_mat_tag == ARM64_SIM_TAG_RETURN) { \
        __u64 __a64_mat_base; \
        ARM64_SIM_L_RETURN_BASE_INTO(__a64_mat_base); \
        __a64_mat_value += __a64_mat_base; \
    } \
    (OUTPUT) = __a64_mat_value; \
} while (0)

#define ARM64_SIM_L_MATERIALIZE(VALUE, TAG) \
({ __u64 __a64_mat_result; \
   ARM64_SIM_L_MATERIALIZE_INTO(__a64_mat_result, VALUE, TAG); \
   __a64_mat_result; })

#define ARM64_SIM_L_UNMATERIALIZE_INTO(OUTPUT, VALUE, TAG) \
do { \
    __u64 __a64_unmat_value = (VALUE); \
    __u8 __a64_unmat_tag = (TAG); \
    if (__a64_unmat_tag == ARM64_SIM_TAG_STACK) { \
        __u64 __a64_unmat_base; \
        ARM64_SIM_L_STACK_BASE_INTO(__a64_unmat_base); \
        __a64_unmat_value -= __a64_unmat_base; \
    } else if (__a64_unmat_tag == ARM64_SIM_TAG_RETURN) { \
        __u64 __a64_unmat_base; \
        ARM64_SIM_L_RETURN_BASE_INTO(__a64_unmat_base); \
        __a64_unmat_value -= __a64_unmat_base; \
    } \
    (OUTPUT) = __a64_unmat_value; \
} while (0)

#define ARM64_SIM_L_UNMATERIALIZE(VALUE, TAG) \
({ __u64 __a64_unmat_result; \
   ARM64_SIM_L_UNMATERIALIZE_INTO(__a64_unmat_result, VALUE, TAG); \
   __a64_unmat_result; })

#define ARM64_SIM_L_READ_REG_RAW_INTO(OUTPUT, REG) \
do { \
    const __u64 __a64_l_reg = (REG); \
    (OUTPUT) = __a64_l_reg == ARM64_SP ? (__u64)__a64_sp : \
        __a64_l_reg < KPROG_ARM64_GPR_COUNT ? \
        __a64_cells[KPROG_ARM64_GPR_CELL(__a64_l_reg)]->x : 0ULL; \
} while (0)

#define ARM64_SIM_L_READ_REG_RAW(REG) \
({ __u64 __a64_read_reg_raw_result; \
   ARM64_SIM_L_READ_REG_RAW_INTO(__a64_read_reg_raw_result, REG); \
   __a64_read_reg_raw_result; })

#define ARM64_SIM_L_READ_REG_PTR_INTO(OUTPUT, REG) \
do { \
    const __u64 __a64_l_reg = (REG); \
    (OUTPUT) = __a64_l_reg == ARM64_SP ? (void *)(long)__a64_sp : \
        __a64_l_reg < KPROG_ARM64_GPR_COUNT ? \
        __a64_cells[KPROG_ARM64_GPR_CELL(__a64_l_reg)]->ptr : (void *)0; \
} while (0)

#define ARM64_SIM_L_READ_REG_PTR(REG) \
({ void * __a64_read_reg_ptr_result; \
   ARM64_SIM_L_READ_REG_PTR_INTO(__a64_read_reg_ptr_result, REG); \
   __a64_read_reg_ptr_result; })

#define ARM64_SIM_L_REG_TAG_INTO(OUTPUT, REG) \
do { \
    const __u64 __a64_l_reg = (REG); \
    (OUTPUT) = __a64_l_reg == ARM64_SP ? ARM64_SIM_TAG_STACK : \
        __a64_l_reg < KPROG_ARM64_GPR_COUNT ? \
        *__a64_tag_cells[KPROG_ARM64_GPR_CELL(__a64_l_reg)] : ARM64_SIM_TAG_SCALAR; \
} while (0)

/* Preserve the original ternary expression's unsigned-int promotion type. */
#define ARM64_SIM_L_REG_TAG(REG) \
({ __u32 __a64_reg_tag_result; \
   ARM64_SIM_L_REG_TAG_INTO(__a64_reg_tag_result, REG); \
   __a64_reg_tag_result; })

#define ARM64_SIM_L_READ_REG_INTO(OUTPUT, REG) \
do { \
    __u64 __a64_read_value; \
    __u8 __a64_read_tag; \
    ARM64_SIM_L_READ_REG_RAW_INTO(__a64_read_value, REG); \
    ARM64_SIM_L_REG_TAG_INTO(__a64_read_tag, REG); \
    ARM64_SIM_L_MATERIALIZE_INTO(OUTPUT, __a64_read_value, __a64_read_tag); \
} while (0)

#define ARM64_SIM_L_READ_REG(REG) \
({ __u64 __a64_read_result; \
   ARM64_SIM_L_READ_REG_INTO(__a64_read_result, REG); \
   __a64_read_result; })

#define ARM64_SIM_L_WRITE_REG_WIDTH(REG, VALUE, WIDTH) \
	do { __s64 __a64_write_old_sp=__a64_sp;  const __u64 __a64_l_reg = (REG); \
	     __u64 __a64_l_next = KPROG_ARM64_APPLY_WIDTH((VALUE), (WIDTH)); \
	     if (__a64_l_reg == ARM64_SP) { \
	       __u64 __a64_write_base; \
	       ARM64_SIM_L_STACK_BASE_INTO(__a64_write_base); \
	       __a64_sp = (__s64)(__a64_l_next - __a64_write_base); \
	     } else if (__a64_l_reg < KPROG_ARM64_GPR_COUNT && KPROG_ARM64_REG_WRITABLE(__a64_l_reg)) { \
	       if (KPROG_ARM64_WRITE_ARM((WIDTH) == ARM64_WIDTH_32) == KPROG_ARM64_WRITE_ARM_NARROW) \
	         __a64_cells[KPROG_ARM64_GPR_CELL(__a64_l_reg)]->x = (__u32)__a64_l_next; \
	       else \
	         __a64_cells[KPROG_ARM64_GPR_CELL(__a64_l_reg)]->x = __a64_l_next; \
	       *__a64_tag_cells[KPROG_ARM64_GPR_CELL(__a64_l_reg)] = ARM64_SIM_TAG_SCALAR; \
	     } \
	if ((REG)==ARM64_SP) ARM64_SIM_L_STACK_RELEASE(__a64_write_old_sp); \
	} while (0)

#define ARM64_SIM_L_WRITE_REG_PTR(REG, VALUE) \
	ARM64_SIM_L_WRITE_REG_PTR_TAG((REG), (VALUE), ARM64_SIM_TAG_SCALAR)

#define ARM64_SIM_L_WRITE_REG_PTR_TAG(REG, VALUE, TAG) \
	do { __s64 __a64_write_old_sp=__a64_sp;  const __u64 __a64_l_reg = (REG); \
	     void *__a64_l_next_ptr = (void *)(VALUE); \
	     __u8 __a64_l_next_tag = (TAG); \
	     if (__a64_l_reg == ARM64_SP) { \
	       if (__a64_l_next_tag == ARM64_SIM_TAG_STACK) \
	           __a64_sp = (__s64)(long)__a64_l_next_ptr; \
	       else { \
	           __u64 __a64_write_value, __a64_write_base; \
	           ARM64_SIM_L_MATERIALIZE_INTO(__a64_write_value, (__u64)(long)__a64_l_next_ptr, __a64_l_next_tag); \
	           ARM64_SIM_L_STACK_BASE_INTO(__a64_write_base); \
	           __a64_sp = (__s64)(__a64_write_value - __a64_write_base); \
	       } \
	     } else if (__a64_l_reg < KPROG_ARM64_GPR_COUNT && KPROG_ARM64_REG_WRITABLE(__a64_l_reg)) { \
	       __a64_cells[KPROG_ARM64_GPR_CELL(__a64_l_reg)]->ptr = __a64_l_next_ptr; \
	       *__a64_tag_cells[KPROG_ARM64_GPR_CELL(__a64_l_reg)] = __a64_l_next_tag; \
	     } \
	if ((REG)==ARM64_SP) ARM64_SIM_L_STACK_RELEASE(__a64_write_old_sp); \
	} while (0)

#define ARM64_SIM_L_WRITE_REG_MAP_PTR(REG, VALUE)                            \
	ARM64_SIM_L_WRITE_REG_PTR_TAG((REG), (VALUE), ARM64_SIM_TAG_MAP_PTR)

/*
 * AUX lane decoders: the byte offsets are the machine-checked contract in
 * formal/generated/arm64_aux.h (KProgFormal/Arm64Aux.lean). Lane 1 carries the
 * source modifier, the bitfield LSB or the CCMP NZCV; lane 2 carries the ALU
 * modifier's shift amount or the bitfield width; lane 0 carries the ALU opcode,
 * the memory index, the bitfield kind and the shift *kind* (the
 * `ARM64_OP_SHIFT_*` handler switches on the low byte); lane 3 the memory
 * flags.
 */
#define ARM64_SIM_L_MOD(AUX) KPROG_ARM64_AUX_B1(AUX)
#define ARM64_SIM_L_SHIFT(AUX) KPROG_ARM64_AUX_B2(AUX)
#define ARM64_SIM_L_MEM_INDEX(AUX) KPROG_ARM64_AUX_B0(AUX)
#define ARM64_SIM_L_MEM_FLAGS(AUX) KPROG_ARM64_AUX_B3(AUX)
#define ARM64_SIM_L_BITFIELD_LSB(AUX) KPROG_ARM64_AUX_B1(AUX)
#define ARM64_SIM_L_BITFIELD_WIDTH(AUX) KPROG_ARM64_AUX_B2(AUX)
#define ARM64_SIM_L_CCMP_NZCV(AUX) KPROG_ARM64_CCMP_NZCV(AUX)
#define ARM64_SIM_L_CCMP_COND(AUX) KPROG_ARM64_CCMP_COND(AUX)

/* The width a body operates at when its decoded width field is absent (the
 * code 0): the same resolution the Lean `effective` def and the C contract
 * state. The composed body restated this fallback inline; it now shares one
 * kernel. */
#define ARM64_SIM_L_EFFECTIVE_WIDTH(WIDTH)                                  \
	arm64_width_effective(WIDTH)

/*
 * Bitfield-composition (UBFX/SBFX/UBFIZ/BFXIL/BFI) value. The five numeric
 * kinds, their shared mask/sign-extension locals and their field-placement
 * guards are the generated AArch64 bitfield contract in
 * formal/generated/arm64_bitfield.h, which KProgFormal/Arm64Bitfield.lean
 * proves equal to an independent statement over all five kinds and the whole
 * architectural field domain. An unhandled kind reaches
 * ARM64_SIM_L_UNSUPPORTED_OPCODE. ARM64_SIM_L_READ_REG is evaluated exactly
 * once per source and destination operand.
 */
#define ARM64_SIM_L_BITFIELD_VALUE(KIND, SRC, DST, LSB, BITS)               \
	KPROG_ARM64_BITFIELD_VALUE((KIND), (SRC), (DST), (LSB), (BITS),    \
				   ARM64_SIM_L_UNSUPPORTED_OPCODE())

#define ARM64_SIM_L_BITFIELD_VALUE_INTO(OUTPUT, KIND, SRC, DST, LSB, BITS) \
	KPROG_ARM64_BITFIELD_VALUE_INTO((OUTPUT), (KIND), (SRC), (DST), (LSB), (BITS),    \
				   ARM64_SIM_L_UNSUPPORTED_OPCODE())

/*
 * Source-modifier (shift/rotate/extend) value. The numeric modifier arms,
 * their shift-amount masking, and the rotate guards are the generated
 * AArch64 source-modifier contract in formal/generated/arm64_mod.h, which
 * KProgFormal/Arm64Mod.lean proves equal to an independent statement over all
 * eleven modifiers and all four widths. ARM64_SIM_L_READ_REG is evaluated
 * exactly once.
 */
#define ARM64_SIM_L_MOD_VALUE_INTO(OUTPUT, REG, MOD, SHIFT, WIDTH) \
    do { __u64 __a64_modified_input; \
         ARM64_SIM_L_READ_REG_INTO(__a64_modified_input, (REG)); \
         KPROG_ARM64_MOD_VALUE_INTO((OUTPUT), (MOD), __a64_modified_input, (SHIFT), (WIDTH)); \
    } while (0)
#define ARM64_SIM_L_MOD_VALUE(REG, MOD, SHIFT, WIDTH) \
    ({ __u64 __a64_modified_result; \
       ARM64_SIM_L_MOD_VALUE_INTO(__a64_modified_result, (REG), (MOD), (SHIFT), (WIDTH)); \
       __a64_modified_result; })

/*
 * Multiply-family value (MADD/MSUB/MUL/UMULL/UDIV/UMULH/UMADDL/SMADDL). The
 * eight opcode labels, the widened-operand and UMULH partial-product arms, and
 * the divide-by-zero guard are the generated AArch64 multiply contract in
 * formal/generated/arm64_mul.h, which KProgFormal/Arm64Mul.lean proves equal to
 * an independent statement over all eight operations. ARM64_SIM_L_READ_REG is
 * evaluated exactly once per source, second source and accumulator operand. No
 * arm writes NZCV.
 */
#define ARM64_SIM_L_MUL_VALUE(OP, SRC, SRC2, SRC3, WIDTH)                   \
	KPROG_ARM64_MUL_VALUE((OP), KPROG_ARM64_APPLY_WIDTH(              \
		ARM64_SIM_L_READ_REG(SRC), (OP) == ARM64_OP_UDIV ? (WIDTH) : ARM64_WIDTH_64), \
		KPROG_ARM64_APPLY_WIDTH(ARM64_SIM_L_READ_REG(SRC2),        \
			(OP) == ARM64_OP_UDIV ? (WIDTH) : ARM64_WIDTH_64), \
			      ARM64_SIM_L_READ_REG(SRC3),                  \
			      ARM64_SIM_L_UNSUPPORTED_OPCODE())

#define ARM64_SIM_L_MUL_VALUE_INTO(OUTPUT, OP, SRC, SRC2, SRC3, WIDTH) \
	KPROG_ARM64_MUL_VALUE_INTO((OUTPUT), (OP), KPROG_ARM64_APPLY_WIDTH(              \
		ARM64_SIM_L_READ_REG(SRC), (OP) == ARM64_OP_UDIV ? (WIDTH) : ARM64_WIDTH_64), \
		KPROG_ARM64_APPLY_WIDTH(ARM64_SIM_L_READ_REG(SRC2),        \
			(OP) == ARM64_OP_UDIV ? (WIDTH) : ARM64_WIDTH_64), \
			      ARM64_SIM_L_READ_REG(SRC3),                  \
			      ARM64_SIM_L_UNSUPPORTED_OPCODE())

/*
 * Extract/reverse/extend value (EXTR/REV/REV16/SXTH/SXTW/SXTB). The six
 * opcode labels, the EXTR masked-shift composition, the width-selected byte
 * reversals, and the sign-extension arms are the generated AArch64
 * extract/reverse/extend contract in formal/generated/arm64_extrev.h, which
 * KProgFormal/Arm64Extrev.lean proves equal to an independent statement over
 * all six operations, the architectural EXTR concatenation, and the emitted
 * REV/REV16 widths. EXTR reads SRC2 and SHIFT; REV/REV16/SXT* use SRC only.
 * ARM64_SIM_L_READ_REG is evaluated exactly once per source operand, and no
 * arm writes NZCV.
 */
#define ARM64_SIM_L_EXTREV_VALUE(OP, SRC, SRC2, SHIFT, WIDTH)               \
	KPROG_ARM64_EXTREV_VALUE((OP), KPROG_ARM64_APPLY_WIDTH(           \
		ARM64_SIM_L_READ_REG(SRC), (OP) == ARM64_OP_EXTR ? (WIDTH) : ARM64_WIDTH_64), \
		KPROG_ARM64_APPLY_WIDTH(ARM64_SIM_L_READ_REG(SRC2),        \
			(OP) == ARM64_OP_EXTR ? (WIDTH) : ARM64_WIDTH_64), (SHIFT), \
				 (WIDTH), ARM64_SIM_L_UNSUPPORTED_OPCODE())

#define ARM64_SIM_L_EXTREV_VALUE_INTO(OUTPUT, OP, SRC, SRC2, SHIFT, WIDTH) \
	KPROG_ARM64_EXTREV_VALUE_INTO((OUTPUT), (OP), KPROG_ARM64_APPLY_WIDTH(           \
		ARM64_SIM_L_READ_REG(SRC), (OP) == ARM64_OP_EXTR ? (WIDTH) : ARM64_WIDTH_64), \
		KPROG_ARM64_APPLY_WIDTH(ARM64_SIM_L_READ_REG(SRC2),        \
			(OP) == ARM64_OP_EXTR ? (WIDTH) : ARM64_WIDTH_64), (SHIFT), \
				 (WIDTH), ARM64_SIM_L_UNSUPPORTED_OPCODE())

/*
 * Conditional-select value (CSEL/CINC/CSET/CSETM/CINV/CSINV/CSINC/CSNEG). The
 * eight opcode labels and the two candidate values per arm are the generated
 * AArch64 conditional-select contract in formal/generated/arm64_csel.h, which
 * KProgFormal/Arm64Csel.lean proves equal to an independent bit-mask mux
 * statement over all eight operations and both condition outcomes, composed
 * with the already-proven condition contract. TAKEN is that condition result,
 * computed once by the caller. ARM64_SIM_L_READ_REG is evaluated exactly once
 * per source operand, and no arm writes NZCV.
 */
#define ARM64_SIM_L_CSEL_VALUE(OP, SRC, SRC2, TAKEN)                        \
	KPROG_ARM64_CSEL_VALUE((OP), ARM64_SIM_L_READ_REG(SRC),            \
			       ARM64_SIM_L_READ_REG(SRC2), (TAKEN),         \
			       ARM64_SIM_L_UNSUPPORTED_OPCODE())

#define ARM64_SIM_L_CSEL_VALUE_INTO(OUTPUT, OP, SRC, SRC2, TAKEN) \
	KPROG_ARM64_CSEL_VALUE_INTO((OUTPUT), (OP), ARM64_SIM_L_READ_REG(SRC),            \
			       ARM64_SIM_L_READ_REG(SRC2), (TAKEN),         \
			       ARM64_SIM_L_UNSUPPORTED_OPCODE())

/*
 * Sign extension of an already loaded value (the LDRSB/LDRSW/LDRSH step that
 * widens a byte/halfword/word read into the destination). Delegates to the
 * generated AArch64 extract/reverse/extend contract's SXTB/SXTH/SXTW arms,
 * which KProgFormal/Arm64Extrev.lean proves equal to the independent library
 * sign extension. The load handlers already hold the value, so there is no
 * register read to hoist; WIDTH selects the destination write width and is
 * unused by the SXT arms.
 */
#define ARM64_SIM_L_EXTREV_SIGNEXT_INTO(OUTPUT, OP, VALUE, WIDTH) \
    KPROG_ARM64_EXTREV_VALUE_INTO((OUTPUT), (OP), (VALUE), 0, 0, (WIDTH), ARM64_SIM_L_UNSUPPORTED_OPCODE())
#define ARM64_SIM_L_EXTREV_SIGNEXT(OP, VALUE, WIDTH) \
    ({ __u64 __a64_signext_result; \
       ARM64_SIM_L_EXTREV_SIGNEXT_INTO(__a64_signext_result, (OP), (VALUE), (WIDTH)); \
       __a64_signext_result; })

/*
 * Move-wide insertion (MOVK). The four architectural columns and the
 * destination-preserving insertion are the generated AArch64 move-wide contract
 * in formal/generated/arm64_movk.h, which KProgFormal/Arm64Movk.lean proves
 * equal to an independent insertion statement over all four columns. The
 * column comes from the AUX shift field, which is exactly the architectural
 * column for ARM64_AUX_MOVK(S). ARM64_SIM_L_READ_REG is evaluated exactly once,
 * and no arm writes NZCV.
 */
#define ARM64_SIM_L_MOVK_VALUE(DST, IMM, SHIFT)                             \
	KPROG_ARM64_MOVK_INSERT(ARM64_SIM_L_READ_REG(DST), (IMM), (SHIFT), \
				ARM64_SIM_L_UNSUPPORTED_OPCODE())

#define ARM64_SIM_L_MOVK_VALUE_INTO(OUTPUT, DST, IMM, SHIFT) \
	KPROG_ARM64_MOVK_INSERT_INTO((OUTPUT), ARM64_SIM_L_READ_REG(DST), (IMM), (SHIFT), \
				ARM64_SIM_L_UNSUPPORTED_OPCODE())

/*
 * Shift-by-kind (LSL/LSR/ASR/ROR) applied to an already read value. The four
 * shift kinds, the width-masked amount and the width narrowing are the
 * generated AArch64 shift contract in formal/generated/arm64_shift.h, which
 * KProgFormal/Arm64Shift.lean proves equal to an independent statement over all
 * four kinds. The kind comes from the AUX shift field; the caller supplies the
 * raw amount (an immediate or a source register) and the destination width.
 * ARM64_SIM_L_READ_REG is evaluated exactly once, and no arm writes NZCV.
 */
#define ARM64_SIM_L_SHIFT_VALUE(KIND, VALUE, AMOUNT, WIDTH)                 \
	KPROG_ARM64_SHIFT_VALUE((KIND), (VALUE), (AMOUNT), (WIDTH),        \
				ARM64_SIM_L_UNSUPPORTED_OPCODE())

#define ARM64_SIM_L_SHIFT_VALUE_INTO(OUTPUT, KIND, VALUE, AMOUNT, WIDTH) \
	KPROG_ARM64_SHIFT_VALUE_INTO((OUTPUT), (KIND), (VALUE), (AMOUNT), (WIDTH),        \
				ARM64_SIM_L_UNSUPPORTED_OPCODE())

/*
 * Byte-lane reduction (CNT/UADDLV) applied to the vector register. The two
 * reductions and their per-byte definitions are the generated AArch64
 * reduction contract in formal/generated/arm64_reduction.h, which
 * KProgFormal/Arm64Reduction.lean proves equal to an independent byte-lane
 * statement over both reductions. The value is already loaded from v0, so there
 * is no register read to hoist; no arm writes NZCV.
 */
#define ARM64_SIM_L_REDUCTION_VALUE(OP, VALUE)                              \
	KPROG_ARM64_REDUCTION_VALUE((OP), (VALUE),                         \
				    ARM64_SIM_L_UNSUPPORTED_OPCODE())

#define ARM64_SIM_L_REDUCTION_VALUE_INTO(OUTPUT, OP, VALUE) \
	KPROG_ARM64_REDUCTION_VALUE_INTO((OUTPUT), (OP), (VALUE),                         \
				    ARM64_SIM_L_UNSUPPORTED_OPCODE())

/*
 * Unary value (MVN/NEG) applied to a source register. The two opcode labels and
 * the width-narrowed complement/negation are the generated AArch64 unary
 * contract in formal/generated/arm64_unary.h, which KProgFormal/Arm64Unary.lean
 * proves equal to an independent statement over both operations and all four
 * destination widths. ARM64_SIM_L_READ_REG is evaluated exactly once, and no
 * arm writes NZCV.
 */
#define ARM64_SIM_L_UNARY_VALUE(OP, SRC, WIDTH)                             \
	KPROG_ARM64_UNARY_VALUE((OP), ARM64_SIM_L_READ_REG(SRC), (WIDTH),  \
				ARM64_SIM_L_UNSUPPORTED_OPCODE())

#define ARM64_SIM_L_UNARY_VALUE_INTO(OUTPUT, OP, SRC, WIDTH) \
	KPROG_ARM64_UNARY_VALUE_INTO((OUTPUT), (OP), ARM64_SIM_L_READ_REG(SRC), (WIDTH),  \
				ARM64_SIM_L_UNSUPPORTED_OPCODE())

/*
 * Condition-gated negation (CNEG) applied to a source register. The opcode label
 * and the width-narrowed condition-gated negation are the generated AArch64
 * CNEG contract in formal/generated/arm64_cneg.h, which
 * KProgFormal/Arm64Cneg.lean proves equal to an independent statement over both
 * condition outcomes and all four destination widths. ARM64_SIM_L_READ_REG is
 * evaluated exactly once, and no arm writes NZCV.
 */
#define ARM64_SIM_L_CNEG_VALUE(OP, SRC, TAKEN, WIDTH)                       \
	KPROG_ARM64_CNEG_VALUE((OP), ARM64_SIM_L_READ_REG(SRC), (TAKEN),   \
			       (WIDTH), ARM64_SIM_L_UNSUPPORTED_OPCODE())

#define ARM64_SIM_L_CNEG_VALUE_INTO(OUTPUT, OP, SRC, TAKEN, WIDTH) \
	KPROG_ARM64_CNEG_VALUE_INTO((OUTPUT), (OP), ARM64_SIM_L_READ_REG(SRC), (TAKEN),   \
			       (WIDTH), ARM64_SIM_L_UNSUPPORTED_OPCODE())

/*
 * Complemented logical OR (ORN_REG) applied to two source registers. The opcode
 * label and the width-narrowed OR with a complemented second source are the
 * generated AArch64 ORN contract in formal/generated/arm64_orn.h, which
 * KProgFormal/Arm64Orn.lean proves equal to an independent De Morgan statement
 * over all four destination widths. LHS and RHS are each evaluated exactly
 * once, and no arm writes NZCV.
 */
#define ARM64_SIM_L_ORN_VALUE(OP, LHS, RHS, WIDTH)                          \
	KPROG_ARM64_ORN_VALUE((OP), (LHS), (RHS), (WIDTH),                 \
			      ARM64_SIM_L_UNSUPPORTED_OPCODE())

#define ARM64_SIM_L_ORN_VALUE_INTO(OUTPUT, OP, LHS, RHS, WIDTH) \
	KPROG_ARM64_ORN_VALUE_INTO((OUTPUT), (OP), (LHS), (RHS), (WIDTH),                 \
			      ARM64_SIM_L_UNSUPPORTED_OPCODE())

#define ARM64_SIM_L_STACK_INDEX(OFF)                                       \
	KPROG_ARM64_STACK_INDEX(OFF, ARM64_SIM_STACK_BIAS)

/* Empty tied-register asm keeps invalid/dynamic accesses visible despite C
 * array UB. Known in-range indexes need no opacity; retaining their constants
 * lets LLVM scalarize the private ghost payload without changing BPF values.
 * The constant-p predicates eliminate this choice before BPF emission. */
#if defined(__COMPCERT__)
#define ARM64_SIM_L_STACK_INDEX_OPACITY(INDEX, WIDTH) ((void)(INDEX))
#else
#define ARM64_SIM_L_STACK_INDEX_OPACITY(INDEX, WIDTH)                      \
    do {                                                                  \
        if (!__builtin_constant_p(INDEX) || !__builtin_constant_p(WIDTH) || \
            (INDEX) > ARM64_SIM_STACK_BYTES ||                            \
            (WIDTH) > ARM64_SIM_STACK_BYTES - (INDEX))                     \
            asm volatile("" : "+r"(INDEX));                              \
    } while (0)
#endif

/* Bytes below the current native SP have an independent environment value.
 * Releasing an allocated byte also releases its value and pointer provenance. */
#ifndef ARM64_SIM_L_STACK_SP
#define ARM64_SIM_L_STACK_SP() (__a64_sp)
#endif
#define ARM64_SIM_L_STACK_RELEASE(OLD) \
    do { __s64 __a64_release_old=(OLD), __a64_release_new=ARM64_SIM_L_STACK_SP(); \
      if (__a64_release_new>__a64_release_old) { \
        _Pragma("unroll") \
        for (__u32 __a64_release_i=0; __a64_release_i<ARM64_SIM_STACK_BYTES; ++__a64_release_i) { \
          __s64 __a64_release_off=(__s64)__a64_release_i-(__s64)ARM64_SIM_STACK_BIAS; \
          if (__a64_release_off>=__a64_release_old && __a64_release_off<__a64_release_new) \
            __a64_stack.b[__a64_release_i]=(__u8)ARM64_SIM_L_UNSPECIFIED(); \
        } \
        _Pragma("unroll") \
        for (__u32 __a64_release_w=0; __a64_release_w<KPROG_ARM64_STACK_WORDS(ARM64_SIM_STACK_BYTES); ++__a64_release_w) \
          if ((__s64)(__a64_release_w*8U)-(__s64)ARM64_SIM_STACK_BIAS<__a64_release_new && \
              (__s64)(__a64_release_w*8U+8U)-(__s64)ARM64_SIM_STACK_BIAS>__a64_release_old) \
            ARM64_SIM_L_TAG_SET(__a64_release_w,ARM64_SIM_TAG_SCALAR); \
      } \
    } while(0)

#define ARM64_SIM_L_STACK_READ_INTO(OUTPUT, OFF, WIDTH) \
    do { __u64 __a64_observed; \
       ARM64_SIM_L_STACK_READ_OWNED_INTO(__a64_observed,(OFF),(WIDTH)); \
       if ((__s64)(OFF)<ARM64_SIM_L_STACK_SP()) __a64_observed=KPROG_ARM64_APPLY_WIDTH(ARM64_SIM_L_UNSPECIFIED(),(WIDTH)); \
       (OUTPUT) = __a64_observed; } while (0)

#define ARM64_SIM_L_STACK_READ(OFF, WIDTH) \
({ __u64 __kprog_stack_result; \
   ARM64_SIM_L_STACK_READ_INTO(__kprog_stack_result, (OFF), (WIDTH)); \
   __kprog_stack_result; })

#define ARM64_SIM_L_STACK_READ_OWNED_INTO(OUTPUT, OFF, WIDTH) \
	do {                                                                 \
		__u64 __a64_str_index = ARM64_SIM_L_STACK_INDEX(OFF);     \
		ARM64_SIM_L_STACK_INDEX_OPACITY(__a64_str_index, (WIDTH));     \
		const __u8 __a64_str_width = (WIDTH);                           \
		__u64 __a64_str_value;                                    \
		if (KPROG_ARM64_STACK_ARM(                         \
			    __a64_str_width ==                            \
				    ARM64_WIDTH_64,                       \
			    KPROG_ARM64_STACK_WORD_ALIGNED(               \
				    __a64_str_index))) {                  \
			__a64_str_value =                                  \
				__a64_stack.q[KPROG_ARM64_STACK_WORD_INDEX(__a64_str_index)];\
		} else {                                                   \
			__a64_str_value = (__u64)__a64_stack.b[__a64_str_index];\
			if (__a64_str_width >= ARM64_WIDTH_16)\
				__a64_str_value |= (__u64)__a64_stack.b[__a64_str_index + 1] << 8;\
			if (__a64_str_width >= ARM64_WIDTH_32)\
				__a64_str_value |= (__u64)__a64_stack.b[__a64_str_index + 2] << 16;\
			if (__a64_str_width >= ARM64_WIDTH_32)\
				__a64_str_value |= (__u64)__a64_stack.b[__a64_str_index + 3] << 24;\
			if (__a64_str_width >= ARM64_WIDTH_64)\
				__a64_str_value |= (__u64)__a64_stack.b[__a64_str_index + 4] << 32;\
			if (__a64_str_width >= ARM64_WIDTH_64)\
				__a64_str_value |= (__u64)__a64_stack.b[__a64_str_index + 5] << 40;\
			if (__a64_str_width >= ARM64_WIDTH_64)\
				__a64_str_value |= (__u64)__a64_stack.b[__a64_str_index + 6] << 48;\
			if (__a64_str_width >= ARM64_WIDTH_64)\
				__a64_str_value |= (__u64)__a64_stack.b[__a64_str_index + 7] << 56;\
		}                                                          \
		(OUTPUT) = __a64_str_value;                                 \
	} while (0)

#define ARM64_SIM_L_STACK_READ_OWNED(OFF, WIDTH) \
({ __u64 __kprog_stack_result; \
   ARM64_SIM_L_STACK_READ_OWNED_INTO(__kprog_stack_result, (OFF), (WIDTH)); \
   __kprog_stack_result; })

#define ARM64_SIM_L_STACK_READ_TAG_INTO(OUTPUT, OFF, WIDTH) \
	do {                                                                 \
		__u64 __a64_srt_index = ARM64_SIM_L_STACK_INDEX(OFF);     \
		ARM64_SIM_L_STACK_INDEX_OPACITY(__a64_srt_index, (WIDTH));     \
		const __u8 __a64_srt_width = (WIDTH);                           \
		const __u8 __a64_srt_source =                                   \
			KPROG_ARM64_STACK_READ_TAG_SOURCE(                \
				__a64_srt_width == ARM64_WIDTH_64,        \
				KPROG_ARM64_STACK_WORD_ALIGNED(__a64_srt_index));\
		__u8 __a64_srt_tag = ARM64_SIM_TAG_SCALAR;                \
		if ((__s64)(OFF)>=ARM64_SIM_L_STACK_SP() && __a64_srt_source ==                                   \
		    KPROG_ARM64_STACK_READ_TAG_SOURCE_STACK_TAG_ARRAY) {  \
			ARM64_SIM_L_TAG_GET_INTO(__a64_srt_tag,                    \
				KPROG_ARM64_STACK_WORD_INDEX(__a64_srt_index));\
		}                                                          \
		(OUTPUT) = __a64_srt_tag;                                             \
	} while (0)

#define ARM64_SIM_L_STACK_READ_TAG(OFF, WIDTH) \
({ __u8 __kprog_stack_result; \
   ARM64_SIM_L_STACK_READ_TAG_INTO(__kprog_stack_result, (OFF), (WIDTH)); \
   __kprog_stack_result; })

#define ARM64_SIM_L_STACK_WRITE_TAG(OFF, WIDTH, VALUE, TAG) \
    do { __s64 __a64_loss_off=(OFF); __u8 __a64_loss_width=(WIDTH); __u64 __a64_loss_value=(VALUE); \
      ARM64_SIM_L_STACK_WRITE_OWNED(__a64_loss_off,__a64_loss_width,__a64_loss_value,(TAG)); \
      if (__a64_loss_off<ARM64_SIM_L_STACK_SP()) { _Pragma("unroll") \
        for (__u32 __a64_loss_i=0; __a64_loss_i<8U; ++__a64_loss_i) \
          if (__a64_loss_i<__a64_loss_width && __a64_loss_off+__a64_loss_i<ARM64_SIM_L_STACK_SP()) \
            ARM64_SIM_L_STACK_WRITE_OWNED(__a64_loss_off+__a64_loss_i,1U,ARM64_SIM_L_UNSPECIFIED(),ARM64_SIM_TAG_SCALAR); \
      } \
    } while(0)

#define ARM64_SIM_L_STACK_WRITE_OWNED(OFF, WIDTH, VALUE, TAG)                  \
	do {                                                               \
		__u64 __a64_stw_index = ARM64_SIM_L_STACK_INDEX(OFF);     \
		ARM64_SIM_L_STACK_INDEX_OPACITY(__a64_stw_index, (WIDTH));     \
		const __u8 __a64_stw_width = (WIDTH);                           \
		__u64 __a64_stw_value = KPROG_ARM64_APPLY_WIDTH((VALUE), __a64_stw_width);\
		const __u8 __a64_stw_action = KPROG_ARM64_STACK_WRITE_TAG_ACTION(\
			__a64_stw_width == ARM64_WIDTH_64,                \
			KPROG_ARM64_STACK_WORD_ALIGNED(__a64_stw_index));  \
		if (__a64_stw_action ==                              \
		    KPROG_ARM64_STACK_WRITE_TAG_ACTION_WRITE_WORD_AND_TAG) {\
			__a64_stack.q[KPROG_ARM64_STACK_WORD_INDEX(__a64_stw_index)] = __a64_stw_value;\
			if ((TAG) == ARM64_SIM_TAG_STACK || (TAG) == ARM64_SIM_TAG_RETURN) { \
				__u64 __a64_stw_payload; \
				ARM64_SIM_L_UNMATERIALIZE_INTO(__a64_stw_payload, __a64_stw_value, (TAG)); \
				ARM64_SIM_L_STACK_PAYLOAD_STORE(KPROG_ARM64_STACK_WORD_INDEX(__a64_stw_index), __a64_stw_payload); \
			}\
			ARM64_SIM_L_TAG_SET(KPROG_ARM64_STACK_WORD_INDEX(__a64_stw_index), ((TAG)));\
		} else {                                                   \
			ARM64_SIM_L_TAG_SET(KPROG_ARM64_STACK_WORD_INDEX(__a64_stw_index), (ARM64_SIM_TAG_SCALAR));\
			__u64 __a64_stw_last = __a64_stw_index + KPROG_ARM64_STACK_WRITE_LANE_COUNT(__a64_stw_width) - 1U; \
			if (KPROG_ARM64_STACK_WORD_INDEX(__a64_stw_last) != KPROG_ARM64_STACK_WORD_INDEX(__a64_stw_index)) \
				ARM64_SIM_L_TAG_SET(KPROG_ARM64_STACK_WORD_INDEX(__a64_stw_last), (ARM64_SIM_TAG_SCALAR)); \
			KPROG_ARM64_BYTE_AT_INTO(__a64_stack.b[__a64_stw_index], \
				0, __a64_stw_value, ARM64_SIM_L_UNSUPPORTED_OPCODE()); \
		if (KPROG_ARM64_STACK_WRITE_LANE_ACTIVE(__a64_stw_width, 1))\
			KPROG_ARM64_BYTE_AT_INTO(__a64_stack.b[__a64_stw_index + 1], \
				1, __a64_stw_value, ARM64_SIM_L_UNSUPPORTED_OPCODE());\
		if (KPROG_ARM64_STACK_WRITE_LANE_ACTIVE(__a64_stw_width, 2))\
			KPROG_ARM64_BYTE_AT_INTO(__a64_stack.b[__a64_stw_index + 2], \
				2, __a64_stw_value, ARM64_SIM_L_UNSUPPORTED_OPCODE());\
		if (KPROG_ARM64_STACK_WRITE_LANE_ACTIVE(__a64_stw_width, 3))\
			KPROG_ARM64_BYTE_AT_INTO(__a64_stack.b[__a64_stw_index + 3], \
				3, __a64_stw_value, ARM64_SIM_L_UNSUPPORTED_OPCODE());\
		if (KPROG_ARM64_STACK_WRITE_LANE_ACTIVE(__a64_stw_width, 4))\
			KPROG_ARM64_BYTE_AT_INTO(__a64_stack.b[__a64_stw_index + 4], \
				4, __a64_stw_value, ARM64_SIM_L_UNSUPPORTED_OPCODE());\
		if (KPROG_ARM64_STACK_WRITE_LANE_ACTIVE(__a64_stw_width, 5))\
			KPROG_ARM64_BYTE_AT_INTO(__a64_stack.b[__a64_stw_index + 5], \
				5, __a64_stw_value, ARM64_SIM_L_UNSUPPORTED_OPCODE());\
		if (KPROG_ARM64_STACK_WRITE_LANE_ACTIVE(__a64_stw_width, 6))\
			KPROG_ARM64_BYTE_AT_INTO(__a64_stack.b[__a64_stw_index + 6], \
				6, __a64_stw_value, ARM64_SIM_L_UNSUPPORTED_OPCODE());\
		if (KPROG_ARM64_STACK_WRITE_LANE_ACTIVE(__a64_stw_width, 7))\
			KPROG_ARM64_BYTE_AT_INTO(__a64_stack.b[__a64_stw_index + 7], \
				7, __a64_stw_value, ARM64_SIM_L_UNSUPPORTED_OPCODE());\
		}                                                         \
	} while (0)

#define ARM64_SIM_L_STACK_WRITE(OFF, WIDTH, VALUE)                          \
	ARM64_SIM_L_STACK_WRITE_TAG((OFF), (WIDTH), (VALUE), ARM64_SIM_TAG_SCALAR)

#define ARM64_SIM_L_STACK_PTR_INTO(OUTPUT, OFF) \
	do {                                                                 \
		__s64 __a64_sp_ptr_index =                                 \
			KPROG_ARM64_STACK_PTR_INDEX((OFF), ARM64_SIM_STACK_BIAS);\
		(OUTPUT) = (void *)&__a64_stack.b[__a64_sp_ptr_index];                \
	} while (0)

#define ARM64_SIM_L_STACK_PTR(OFF) \
({ void * __kprog_stack_result; \
   ARM64_SIM_L_STACK_PTR_INTO(__kprog_stack_result, (OFF)); \
   __kprog_stack_result; })

/* Keep arena address formation inside its provenance branch. LLVM may
 * otherwise speculate fp + kernel_pointer before the verifier sees the tag. */
#if defined(__COMPCERT__)
#define ARM64_SIM_L_ADDRESS_OPACITY(VALUE) ((void)(VALUE))
#else
#define ARM64_SIM_L_ADDRESS_OPACITY(VALUE) asm volatile("" : "+r"(VALUE))
#endif
#define ARM64_SIM_L_HELPER_ARG_PTR_INTO(OUTPUT, REG) \
    do { __u8 __a64_hap_tag; void *__a64_hap_ptr; \
       ARM64_SIM_L_REG_TAG_INTO(__a64_hap_tag, (REG)); \
       if (KPROG_ARM64_HELPER_ARG_PTR_BODY(__a64_hap_tag == ARM64_SIM_TAG_STACK) == KPROG_ARM64_HELPER_ARG_PTR_BODY_STACK_ARENA_PTR) { \
           ARM64_SIM_L_READ_REG_PTR_INTO(__a64_hap_ptr, (REG)); \
           __s64 __a64_hap_off = (__s64)(long)__a64_hap_ptr; \
           ARM64_SIM_L_ADDRESS_OPACITY(__a64_hap_off); \
           ARM64_SIM_L_STACK_PTR_INTO(__a64_hap_ptr, __a64_hap_off); \
       } else { ARM64_SIM_L_READ_REG_PTR_INTO(__a64_hap_ptr, (REG)); } \
       (OUTPUT) = __a64_hap_ptr; } while (0)
#define ARM64_SIM_L_HELPER_ARG_PTR(REG) \
    ({ void *__a64_hap_result; ARM64_SIM_L_HELPER_ARG_PTR_INTO(__a64_hap_result, (REG)); __a64_hap_result; })

/* Only the proven expanded-context base denotes the original helper context.
 * Offset and arbitrary pointers retain their existing identity. */
#define ARM64_SIM_L_HELPER_CTX_PTR_INTO(OUTPUT, REG) \
    do { __u8 __a64_hcp_tag; \
         ARM64_SIM_L_REG_TAG_INTO(__a64_hcp_tag, (REG)); \
         if (__a64_hcp_tag == ARM64_SIM_TAG_ABI) { \
             void *__a64_hcp_pointer; \
             ARM64_SIM_L_READ_REG_PTR_INTO(__a64_hcp_pointer, (REG)); \
             (OUTPUT) = KPROG_ABI_HELPER_CONTEXT(__a64_hcp_pointer, __a64_sim_helper_abi_base, __a64_sim_helper_ctx); \
         } else ARM64_SIM_L_HELPER_ARG_PTR_INTO((OUTPUT), (REG)); \
    } while (0)
#define ARM64_SIM_L_HELPER_CTX_PTR(REG) \
    ({ void *__a64_hcp_result; ARM64_SIM_L_HELPER_CTX_PTR_INTO(__a64_hcp_result, (REG)); __a64_hcp_result; })

#if defined(__COMPCERT__)
#define ARM64_SIM_L_REFRESH_XDP_CONTEXT() \
    do { if (__a64_sim_helper_ctx) { \
        struct arm64_sim_xdp_abi *__a64_abi = __a64_sim_helper_abi_base; \
        __u64 __a64_refresh_value; \
        ARM64_SIM_L_XDP_FIELD_INTO(__a64_refresh_value, __a64_sim_helper_ctx, data); \
        __a64_abi->data = (void *)(unsigned long)__a64_refresh_value; \
        ARM64_SIM_L_XDP_FIELD_INTO(__a64_refresh_value, __a64_sim_helper_ctx, data_end); \
        __a64_abi->data_end = (void *)(unsigned long)__a64_refresh_value; \
    } } while (0)
#else
#define ARM64_SIM_L_REFRESH_XDP_CONTEXT()                                \
	do {                                                              \
		if (__a64_sim_helper_ctx) {                               \
			struct xdp_md *__a64_ctx = __a64_sim_helper_ctx;    \
			struct arm64_sim_xdp_abi *__a64_abi = __a64_sim_helper_abi_base; \
			__a64_abi->data = (void *)(long)__a64_ctx->data;    \
			__a64_abi->data_end = (void *)(long)__a64_ctx->data_end; \
		}                                                         \
	} while (0)

#endif

#define ARM64_SIM_L_STORE_Q0_STACK(OFF)                                    \
	do {                                                               \
		ARM64_SIM_L_STACK_WRITE((OFF), ARM64_WIDTH_64, __a64_v0);\
		ARM64_SIM_L_STACK_WRITE((__s64)(OFF) + 8, ARM64_WIDTH_64,\
					__a64_v0_hi);                    \
	} while (0)

/*
 * Little-endian byte-ladder load. The byte lanes and the width-driven ladder
 * are the generated AArch64 load-bytes contract in
 * formal/generated/arm64_load_bytes.h, which KProgFormal/Arm64LoadBytes.lean
 * proves equal to an independent masked-truncation statement over all four
 * ARM64_WIDTH_* codes. ADDR is the byte source address and WIDTH the load
 * width; the macro writes no NZCV.
 */
#define ARM64_SIM_L_LOAD_ADDR(ADDR, WIDTH)                                  \
	KPROG_ARM64_LOAD_BYTES((ADDR), (WIDTH))

/* Preserve one native-width pointer read and literal context offsets in BPF.
 * Host reads also permit unaligned words without alignment/effective-type UB. */
#ifdef __BPF__
#define ARM64_SIM_L_LOAD_PTR_AT_INTO(OUTPUT, BASE, OFFSET)                               \
	do { void *__a64_ptr_result;                                      \
	   if (__builtin_constant_p(OFFSET) && (OFFSET) >= -32768 &&      \
	       (OFFSET) <= 32767)                                       \
		if ((OFFSET) < 0)                                       \
			__asm__ volatile("%0 = *(u64 *)(%1 %2)"            \
				: "=r"(__a64_ptr_result) : "r"(BASE), "i"(OFFSET) : "memory"); \
		else                                                    \
			__asm__ volatile("%0 = *(u64 *)(%1 + %2)"          \
				: "=r"(__a64_ptr_result) : "r"(BASE), "i"(OFFSET) : "memory"); \
	   else                                                        \
		__asm__ volatile("%0 = *(u64 *)(%1 + 0)"                  \
			: "=r"(__a64_ptr_result) : "r"((__u8 *)(BASE) + (OFFSET)) : "memory"); \
	   (OUTPUT) = __a64_ptr_result; } while (0)
#elif defined(__COMPCERT__)
#define ARM64_SIM_L_LOAD_PTR_AT_INTO(OUTPUT, BASE, OFFSET) \
    KPROG_C_UNALIGNED_LOAD_INTO((OUTPUT), void *, (BASE), (OFFSET))
#else
typedef void *arm64_sim_unaligned_ptr __attribute__((aligned(1), may_alias));
#define ARM64_SIM_L_LOAD_PTR_AT_INTO(OUTPUT, BASE, OFFSET) \
    do { (OUTPUT) = *(arm64_sim_unaligned_ptr volatile *)((__u8 *)(BASE) + (OFFSET)); } while (0)
#endif
#define ARM64_SIM_L_LOAD_PTR_AT(BASE, OFFSET) \
    ({ void *__a64_ptr_copy; \
       ARM64_SIM_L_LOAD_PTR_AT_INTO(__a64_ptr_copy, (BASE), (OFFSET)); \
       __a64_ptr_copy; })
#define ARM64_SIM_L_LOAD_PTR_ADDR(ADDR) ARM64_SIM_L_LOAD_PTR_AT((ADDR), 0)

/*
 * Little-endian byte-ladder store. The byte lanes and the width-driven ladder
 * are the generated AArch64 store-bytes contract in
 * formal/generated/arm64_store_bytes.h, which KProgFormal/Arm64StoreBytes.lean
 * proves equal to an independent lane-by-lane write-then-read statement over
 * all four ARM64_WIDTH_* codes (and agrees with the load contract). ADDR is the
 * byte destination address, WIDTH the store width, VALUE the raw source value
 * (masked to the width by the macro); the macro writes no NZCV.
 */
#define ARM64_SIM_L_STORE_ADDR(ADDR, WIDTH, VALUE)                          \
	KPROG_ARM64_STORE_BYTES((ADDR), (WIDTH), (VALUE))

#define ARM64_SIM_L_MEM_BASE_OFF_INTO(OUTPUT, AUX, INDEX, IMM) \
    do { \
        const __u8 __a64_mbo_has_index = KPROG_ARM64_MEM_INDEX_PRESENT(INDEX); \
        const __u8 __a64_mbo_isrc = KPROG_ARM64_MEM_INDEX_VALUE(__a64_mbo_has_index); \
        __u64 __a64_mbo_imm = (IMM), __a64_mbo_index = 0, __a64_mbo_result; \
        if (__a64_mbo_isrc == KPROG_ARM64_MEM_INDEX_VALUE_REGISTER) \
            ARM64_SIM_L_MOD_VALUE_INTO(__a64_mbo_index, (INDEX), \
                ARM64_SIM_L_MOD(AUX), ARM64_SIM_L_SHIFT(AUX), ARM64_WIDTH_64); \
        KPROG_ARM64_MEM_OFFSET_INTO(__a64_mbo_result, \
            KPROG_ARM64_MEM_PREPOST_SUPPRESS(AUX), __a64_mbo_has_index, \
            __a64_mbo_imm, __a64_mbo_index); \
        (OUTPUT) = (__s64)__a64_mbo_result; \
    } while (0)
#define ARM64_SIM_L_MEM_BASE_OFF(AUX, INDEX, IMM) \
    ({ __s64 __a64_mbo_output; \
       ARM64_SIM_L_MEM_BASE_OFF_INTO(__a64_mbo_output, (AUX), (INDEX), (IMM)); \
       __a64_mbo_output; })

/* The pre/post-indexed address writeback contract is a decode of the packed
 * memory-flag byte into which writeback a load/store performs. Both bodies
 * route through this one step, which applies the generated per-bit delta --
 * the immediate when the matching `MEM_PRE` / `MEM_POST` bit is set and zero
 * otherwise -- to the base register (or the stack pointer), so the two bits
 * stay independent and the same immediate applies twice when both are set.
 * The address offset (`MEM_BASE_OFF`) suppresses its immediate through the
 * same decode's `SUPPRESS` gate, so a pre/post access carries the immediate
 * as its own writeback rather than in the offset. */
#define ARM64_SIM_L_MEM_PREPOST_STEP(BASE, DELTA)                           \
	do {                                                               \
		const __s64 __a64_l_pp = (__s64)(DELTA);                        \
		if (__a64_l_pp != 0) {                                    \
			if ((BASE) == ARM64_SP)                           \
				ARM64_SIM_L_WRITE_REG_PTR_TAG(ARM64_SP,   \
					(void *)(long)((__u64)__a64_sp + (__u64)__a64_l_pp), \
					ARM64_SIM_TAG_STACK);                    \
			else { \
                void *__a64_l_pp_pointer; __u8 __a64_l_pp_tag; \
                ARM64_SIM_L_READ_REG_PTR_INTO(__a64_l_pp_pointer, (BASE)); \
                ARM64_SIM_L_REG_TAG_INTO(__a64_l_pp_tag, (BASE)); \
                ARM64_SIM_L_WRITE_REG_PTR_TAG((BASE), \
                    KPROG_PTR_ADD64_NATIVE(__a64_l_pp_pointer, __a64_l_pp), __a64_l_pp_tag); \
            } \
		}                                                         \
	} while (0)

/* Arm DDI0487 CheckSPAlignment: test incoming SP before offset/writeback.
 * The Linux EL1 native-entry stack base is 16-byte aligned, so its simulator
 * coordinate has the same low four bits. GPR aliases retain ordinary addressing.
 * Arm WBOVERLAPLD/WBOVERLAPST select constrained-unpredictable behavior when
 * writeback aliases an integer transfer register (base field31 denotes SP).
 * Approved architectural faults use the existing verifier-visible fault arm.
 */
#define ARM64_SIM_L_SP_ALIGNMENT(BASE)                                    \
    do {                                                                 \
        if ((BASE) == ARM64_SP && ((__u64)__a64_sp & 15U))                 \
            ARM64_SIM_L_UNSUPPORTED_OPCODE();                            \
    } while (0)

#define ARM64_SIM_L_WRITEBACK_OVERLAP(BASE, DATA, AUX)                     \
    do {                                                                 \
        if ((ARM64_SIM_L_MEM_FLAGS(AUX) & (ARM64_MEM_PRE | ARM64_MEM_POST)) && \
            (BASE) != ARM64_SP && (BASE) == (DATA))                       \
            ARM64_SIM_L_UNSUPPORTED_OPCODE();                            \
    } while (0)

#define ARM64_SIM_L_MEM_PRE(BASE, AUX, IMM)                                \
    do {                                                                 \
        ARM64_SIM_L_SP_ALIGNMENT(BASE);                                   \
        ARM64_SIM_L_MEM_PREPOST_STEP((BASE),                               \
            KPROG_ARM64_MEM_PREPOST_PRE_DELTA((AUX), (IMM)));              \
    } while (0)

#define ARM64_SIM_L_MEM_POST(BASE, AUX, IMM)                                \
	ARM64_SIM_L_MEM_PREPOST_STEP((BASE),                                \
		KPROG_ARM64_MEM_PREPOST_POST_DELTA((AUX), (IMM)))

/* Entry-selected XDP translation is erased by specialization. Bare state
 * declarations used by routing hosts do not establish a live context.
 * Native XDP pointer fields are 64-bit; BPF ctx access uses typed fields.
 * Other accesses retain their native address and width for verifier review. */
/* C sees an opaque 64-bit result even though BPF context fields use a
 * 32-bit access opcode; the verifier/JIT supplies the actual pointer width.
 * Partial native pointer-field reads scalarize those exact native bits before
 * the source-width shift/mask. Other accesses keep their native address/width.
 */
#if defined(__bpf__) || defined(__BPF__)
#define ARM64_SIM_L_XDP_NUMERIC(VALUE) NATIVE_LAB_NUMERIC(VALUE)
#elif defined(__COMPCERT__)
#define ARM64_SIM_L_XDP_NUMERIC(VALUE) kprog_c_pointer_bits((const void *)(unsigned long)(VALUE))
#else
#define ARM64_SIM_L_XDP_NUMERIC(VALUE) ((__u64)(VALUE))
#endif
#if defined(__COMPCERT__)
#define ARM64_SIM_L_XDP_FIELD_INTO(OUTPUT, CTX, FIELD) \
    do { (OUTPUT) = (__u64)(unsigned long)kprog_c_context_pointer((CTX), KPROG_ABI_KIND_XDP, __builtin_offsetof(struct xdp_md, FIELD)); } while (0)
#else
#define ARM64_SIM_L_XDP_FIELD_INTO(OUTPUT, CTX, FIELD) \
    do { KPROG_ARM64_LOAD_ACCESS_OFFSET(32, (CTX), (__s64)__builtin_offsetof(struct xdp_md, FIELD), (OUTPUT)); } while (0)
#endif
#define ARM64_SIM_L_XDP_FIELD(CTX, FIELD) \
    ({ __u64 __a64_xf_value; ARM64_SIM_L_XDP_FIELD_INTO(__a64_xf_value, (CTX), FIELD); __a64_xf_value; })
#define ARM64_SIM_L_XDP_READ_INTO(OUTPUT, BASE, OFF, WIDTH) \
 do { void *__a64_xdp_pointer; ARM64_SIM_L_READ_REG_PTR_INTO(__a64_xdp_pointer, (BASE)); \
    __s64 __a64_xdp_off = (__s64)((__u8 *)__a64_xdp_pointer - (__u8 *)__a64_sim_helper_ctx) + (OFF); \
    struct xdp_md *__a64_xdp_ctx = __a64_sim_helper_ctx; \
    __u64 __a64_xdp_value; \
    if (__a64_xdp_off >= 0 && __a64_xdp_off < 24 && \
        (__a64_xdp_off & 7) + (WIDTH) <= 8) { \
        if (__a64_xdp_off < 8) ARM64_SIM_L_XDP_FIELD_INTO(__a64_xdp_value, __a64_xdp_ctx, data); \
        else if (__a64_xdp_off < 16) ARM64_SIM_L_XDP_FIELD_INTO(__a64_xdp_value, __a64_xdp_ctx, data_end); \
        else ARM64_SIM_L_XDP_FIELD_INTO(__a64_xdp_value, __a64_xdp_ctx, data_meta); \
        if ((WIDTH) != ARM64_WIDTH_64) { \
            __a64_xdp_value = ARM64_SIM_L_XDP_NUMERIC(__a64_xdp_value); \
            __a64_xdp_value = KPROG_ARM64_APPLY_WIDTH(__a64_xdp_value >> ((__a64_xdp_off & 7) * 8), (WIDTH)); \
        } \
    } else KPROG_ARM64_LOAD_BYTES_OFFSET_INTO(__a64_xdp_value, __a64_xdp_pointer, (OFF), (WIDTH)); \
    (OUTPUT) = __a64_xdp_value; } while (0)
#define ARM64_SIM_L_XDP_READ(BASE, OFF, WIDTH) \
    ({ __u64 __a64_context_result; \
       ARM64_SIM_L_XDP_READ_INTO(__a64_context_result, (BASE), (OFF), (WIDTH)); \
       __a64_context_result; })

#if defined(__bpf__) || defined(__BPF__)
extern void *bpf_cast_to_kern_ctx(void *) __ksym;
#define ARM64_SIM_L_SKB_STORE_ACCESS(BITS, CTX, OFF, VALUE) \
 do { if (__builtin_constant_p(OFF)) \
  asm volatile("*(u" #BITS " *)(%0 + %1) = %2" : : "r"(CTX), "i"(OFF), "r"(VALUE) : "memory"); \
 else KPROG_ARM64_STORE_ACCESS(BITS, (__u8 *)(CTX) + (OFF), VALUE); } while (0)
#else
static inline void *bpf_cast_to_kern_ctx(void *ctx) { return ctx; }
#define ARM64_SIM_L_SKB_STORE_ACCESS(BITS, CTX, OFF, VALUE) \
 KPROG_ARM64_STORE_ACCESS(BITS, (__u8 *)(CTX) + (OFF), VALUE)
#endif
/* Kernel-context addresses retain native identity. Packet and qdisc cb fields
 * select the corresponding live verifier context access at the native width. */
#define ARM64_SIM_L_SKB_OFFSET_INTO(OUTPUT, BASE, OFF) \
    do { void *__a64_skb_pointer; ARM64_SIM_L_READ_REG_PTR_INTO(__a64_skb_pointer, (BASE)); \
         (OUTPUT) = (__s64)((__u64)(long)__a64_skb_pointer - (__u64)(long)__a64_sim_helper_abi_base + (__u64)(OFF)); } while (0)
#define ARM64_SIM_L_SKB_OFFSET(BASE, OFF) \
    ({ __s64 __a64_skb_offset_result; ARM64_SIM_L_SKB_OFFSET_INTO(__a64_skb_offset_result, (BASE), (OFF)); __a64_skb_offset_result; })
#if defined(__COMPCERT__)
#define ARM64_SIM_L_SKB_FIELD_INTO(OUTPUT, CTX, FIELD) \
    do { (OUTPUT) = (__u64)(unsigned long)kprog_c_context_pointer((CTX), KPROG_ABI_KIND_SKB, __builtin_offsetof(struct __sk_buff, FIELD)); } while (0)
#else
#define ARM64_SIM_L_SKB_FIELD_INTO(OUTPUT, CTX, FIELD) \
    do { KPROG_ARM64_LOAD_ACCESS_OFFSET(32, (CTX), (__s64)__builtin_offsetof(struct __sk_buff, FIELD), (OUTPUT)); } while (0)
#endif
#define ARM64_SIM_L_SKB_FIELD(CTX, FIELD) \
    ({ __u64 __a64_sf_value; ARM64_SIM_L_SKB_FIELD_INTO(__a64_sf_value, (CTX), FIELD); __a64_sf_value; })
#define ARM64_SIM_L_SKB_CB_READ_BYTES_INTO(OUTPUT, CTX, OFF, WIDTH) \
 do { volatile const __u8 *__a64_cbr_addr=(volatile const __u8 *)(CTX)+(OFF); \
    __u64 __a64_cbr_bytes_value=__a64_cbr_addr[0]; \
    if ((WIDTH) >= ARM64_WIDTH_16) __a64_cbr_bytes_value |= (__u64)__a64_cbr_addr[1] << 8; \
    if ((WIDTH) >= ARM64_WIDTH_32) __a64_cbr_bytes_value |= (__u64)__a64_cbr_addr[2] << 16; \
    if ((WIDTH) >= ARM64_WIDTH_32) __a64_cbr_bytes_value |= (__u64)__a64_cbr_addr[3] << 24; \
    if ((WIDTH) >= ARM64_WIDTH_64) __a64_cbr_bytes_value |= (__u64)__a64_cbr_addr[4] << 32; \
    if ((WIDTH) >= ARM64_WIDTH_64) __a64_cbr_bytes_value |= (__u64)__a64_cbr_addr[5] << 40; \
    if ((WIDTH) >= ARM64_WIDTH_64) __a64_cbr_bytes_value |= (__u64)__a64_cbr_addr[6] << 48; \
    if ((WIDTH) >= ARM64_WIDTH_64) __a64_cbr_bytes_value |= (__u64)__a64_cbr_addr[7] << 56; \
    (OUTPUT) = __a64_cbr_bytes_value; } while (0)
#define ARM64_SIM_L_SKB_CB_READ_BYTES(CTX, OFF, WIDTH) \
    ({ __u64 __a64_context_result; \
       ARM64_SIM_L_SKB_CB_READ_BYTES_INTO(__a64_context_result, (CTX), (OFF), (WIDTH)); \
       __a64_context_result; })
#define ARM64_SIM_L_SKB_CB_WRITE_BYTES(CTX, OFF, WIDTH, VALUE) \
 do { volatile __u8 *__a64_cbw_addr=(volatile __u8 *)(CTX)+(OFF); \
      __u64 __a64_cbw_value=(VALUE); __a64_cbw_addr[0]=(__u8)__a64_cbw_value; \
      if ((WIDTH) >= ARM64_WIDTH_16) __a64_cbw_addr[1]=(__u8)(__a64_cbw_value >> 8); \
      if ((WIDTH) >= ARM64_WIDTH_32) __a64_cbw_addr[2]=(__u8)(__a64_cbw_value >> 16); \
      if ((WIDTH) >= ARM64_WIDTH_32) __a64_cbw_addr[3]=(__u8)(__a64_cbw_value >> 24); \
      if ((WIDTH) >= ARM64_WIDTH_64) __a64_cbw_addr[4]=(__u8)(__a64_cbw_value >> 32); \
      if ((WIDTH) >= ARM64_WIDTH_64) __a64_cbw_addr[5]=(__u8)(__a64_cbw_value >> 40); \
      if ((WIDTH) >= ARM64_WIDTH_64) __a64_cbw_addr[6]=(__u8)(__a64_cbw_value >> 48); \
      if ((WIDTH) >= ARM64_WIDTH_64) __a64_cbw_addr[7]=(__u8)(__a64_cbw_value >> 56); \
 } while (0)
#if defined(__bpf__) || defined(__BPF__)
#define ARM64_SIM_L_SKB_CB_READ_INTO(OUTPUT, CTX, OFF, WIDTH) \
 do { __u64 __a64_cbr_value, __a64_cbr_temp; \
    if (__builtin_constant_p(OFF)) { \
    if ((WIDTH) == 8) __asm__ __volatile__("%0 = *(u8 *)(%2 + %3)\n%1 = *(u8 *)(%2 + %4)\n%1 <<= 8\n%0 |= %1\n%1 = *(u8 *)(%2 + %5)\n%1 <<= 16\n%0 |= %1\n%1 = *(u8 *)(%2 + %6)\n%1 <<= 24\n%0 |= %1\n%1 = *(u8 *)(%2 + %7)\n%1 <<= 32\n%0 |= %1\n%1 = *(u8 *)(%2 + %8)\n%1 <<= 40\n%0 |= %1\n%1 = *(u8 *)(%2 + %9)\n%1 <<= 48\n%0 |= %1\n%1 = *(u8 *)(%2 + %10)\n%1 <<= 56\n%0 |= %1" : "=&r"(__a64_cbr_value), "=&r"(__a64_cbr_temp) : "r"(CTX), "i"((OFF)+0), "i"((OFF)+1), "i"((OFF)+2), "i"((OFF)+3), "i"((OFF)+4), "i"((OFF)+5), "i"((OFF)+6), "i"((OFF)+7) : "memory"); \
    else if ((WIDTH) == 4) __asm__ __volatile__("%0 = *(u8 *)(%2 + %3)\n%1 = *(u8 *)(%2 + %4)\n%1 <<= 8\n%0 |= %1\n%1 = *(u8 *)(%2 + %5)\n%1 <<= 16\n%0 |= %1\n%1 = *(u8 *)(%2 + %6)\n%1 <<= 24\n%0 |= %1" : "=&r"(__a64_cbr_value), "=&r"(__a64_cbr_temp) : "r"(CTX), "i"((OFF)+0), "i"((OFF)+1), "i"((OFF)+2), "i"((OFF)+3) : "memory"); \
    else if ((WIDTH) == 2) __asm__ __volatile__("%0 = *(u8 *)(%2 + %3)\n%1 = *(u8 *)(%2 + %4)\n%1 <<= 8\n%0 |= %1" : "=&r"(__a64_cbr_value), "=&r"(__a64_cbr_temp) : "r"(CTX), "i"((OFF)+0), "i"((OFF)+1) : "memory"); \
    else if ((WIDTH) == 1) __asm__ __volatile__("%0 = *(u8 *)(%2 + %3)" : "=&r"(__a64_cbr_value), "=&r"(__a64_cbr_temp) : "r"(CTX), "i"((OFF)+0) : "memory"); \
    } else ARM64_SIM_L_SKB_CB_READ_BYTES_INTO(__a64_cbr_value,(CTX),(OFF),(WIDTH)); \
    (OUTPUT) = __a64_cbr_value; } while (0)
#define ARM64_SIM_L_SKB_CB_READ(CTX, OFF, WIDTH) \
    ({ __u64 __a64_context_result; \
       ARM64_SIM_L_SKB_CB_READ_INTO(__a64_context_result, (CTX), (OFF), (WIDTH)); \
       __a64_context_result; })
#define ARM64_SIM_L_SKB_CB_WRITE(CTX, OFF, WIDTH, VALUE) \
 do { __u64 __a64_cbw_temp; \
      if (__builtin_constant_p(OFF)) { \
      if ((WIDTH) == 8) __asm__ __volatile__("%0 = %2\n*(u8 *)(%1 + %3) = %0\n%0 >>= 8\n*(u8 *)(%1 + %4) = %0\n%0 >>= 8\n*(u8 *)(%1 + %5) = %0\n%0 >>= 8\n*(u8 *)(%1 + %6) = %0\n%0 >>= 8\n*(u8 *)(%1 + %7) = %0\n%0 >>= 8\n*(u8 *)(%1 + %8) = %0\n%0 >>= 8\n*(u8 *)(%1 + %9) = %0\n%0 >>= 8\n*(u8 *)(%1 + %10) = %0" : "=&r"(__a64_cbw_temp) : "r"(CTX), "r"((__u64)(VALUE)), "i"((OFF)+0), "i"((OFF)+1), "i"((OFF)+2), "i"((OFF)+3), "i"((OFF)+4), "i"((OFF)+5), "i"((OFF)+6), "i"((OFF)+7) : "memory"); \
      else if ((WIDTH) == 4) __asm__ __volatile__("%0 = %2\n*(u8 *)(%1 + %3) = %0\n%0 >>= 8\n*(u8 *)(%1 + %4) = %0\n%0 >>= 8\n*(u8 *)(%1 + %5) = %0\n%0 >>= 8\n*(u8 *)(%1 + %6) = %0" : "=&r"(__a64_cbw_temp) : "r"(CTX), "r"((__u64)(VALUE)), "i"((OFF)+0), "i"((OFF)+1), "i"((OFF)+2), "i"((OFF)+3) : "memory"); \
      else if ((WIDTH) == 2) __asm__ __volatile__("%0 = %2\n*(u8 *)(%1 + %3) = %0\n%0 >>= 8\n*(u8 *)(%1 + %4) = %0" : "=&r"(__a64_cbw_temp) : "r"(CTX), "r"((__u64)(VALUE)), "i"((OFF)+0), "i"((OFF)+1) : "memory"); \
      else if ((WIDTH) == 1) __asm__ __volatile__("%0 = %2\n*(u8 *)(%1 + %3) = %0" : "=&r"(__a64_cbw_temp) : "r"(CTX), "r"((__u64)(VALUE)), "i"((OFF)+0) : "memory"); \
      } else ARM64_SIM_L_SKB_CB_WRITE_BYTES((CTX),(OFF),(WIDTH),(VALUE)); \
 } while (0)
#else
#define ARM64_SIM_L_SKB_CB_READ_INTO(OUTPUT, CTX, OFF, WIDTH) ARM64_SIM_L_SKB_CB_READ_BYTES_INTO((OUTPUT),(CTX),(OFF),(WIDTH))
#define ARM64_SIM_L_SKB_CB_READ(CTX, OFF, WIDTH) ARM64_SIM_L_SKB_CB_READ_BYTES((CTX),(OFF),(WIDTH))
#define ARM64_SIM_L_SKB_CB_WRITE(CTX, OFF, WIDTH, VALUE) ARM64_SIM_L_SKB_CB_WRITE_BYTES((CTX),(OFF),(WIDTH),(VALUE))
#endif
#define ARM64_SIM_L_SKB_READ_INTO(OUTPUT, BASE, OFF, WIDTH) \
 do { __s64 __a64_sr_off; ARM64_SIM_L_SKB_OFFSET_INTO(__a64_sr_off, (BASE), (OFF)); \
    struct __sk_buff *__a64_sr_ctx = __a64_sim_helper_ctx; \
    __u64 __a64_sr_value; \
    if (((__a64_sr_off >= ARM64_SKB_DATA_OFF && __a64_sr_off <= ARM64_SKB_DATA_OFF + 8 - (WIDTH)) || \
         (__a64_sr_off >= ARM64_SKB_DATA_END_OFF && __a64_sr_off <= ARM64_SKB_DATA_END_OFF + 8 - (WIDTH)))) { \
      __s64 __a64_sr_lane; \
      if (__a64_sr_off >= ARM64_SKB_DATA_OFF) { ARM64_SIM_L_SKB_FIELD_INTO(__a64_sr_value,__a64_sr_ctx,data); __a64_sr_lane=__a64_sr_off-ARM64_SKB_DATA_OFF; } \
      else { ARM64_SIM_L_SKB_FIELD_INTO(__a64_sr_value,__a64_sr_ctx,data_end); __a64_sr_lane=__a64_sr_off-ARM64_SKB_DATA_END_OFF; } \
      if ((WIDTH) != ARM64_WIDTH_64) __a64_sr_value=KPROG_ARM64_APPLY_WIDTH(ARM64_SIM_L_XDP_NUMERIC(__a64_sr_value) >> (__a64_sr_lane*8), (WIDTH)); \
    } else if (__a64_sr_off >= ARM64_SKB_CB_OFF && __a64_sr_off <= ARM64_SKB_CB_OFF + 20 - (WIDTH)) \
      ARM64_SIM_L_SKB_CB_READ_INTO(__a64_sr_value,__a64_sr_ctx, __a64_sr_off-ARM64_SKB_CB_OFF+(__s64)__builtin_offsetof(struct __sk_buff,cb), (WIDTH)); \
    else { void *__a64_sr_pointer; ARM64_SIM_L_READ_REG_PTR_INTO(__a64_sr_pointer, (BASE)); \
         KPROG_ARM64_LOAD_BYTES_OFFSET_INTO(__a64_sr_value,__a64_sr_pointer,(OFF),(WIDTH)); } \
    (OUTPUT) = __a64_sr_value; } while (0)
#define ARM64_SIM_L_SKB_READ(BASE, OFF, WIDTH) \
    ({ __u64 __a64_context_result; \
       ARM64_SIM_L_SKB_READ_INTO(__a64_context_result, (BASE), (OFF), (WIDTH)); \
       __a64_context_result; })
#define ARM64_SIM_L_SKB_WRITE(BASE, OFF, WIDTH, VALUE) \
 do { __s64 __a64_sw_off; ARM64_SIM_L_SKB_OFFSET_INTO(__a64_sw_off, (BASE), (OFF)); \
      __u64 __a64_sw_value=KPROG_ARM64_APPLY_WIDTH((VALUE),(WIDTH)); \
      if (__a64_sw_off >= ARM64_SKB_CB_OFF && __a64_sw_off <= ARM64_SKB_CB_OFF + 20 - (WIDTH)) { \
       __s64 __a64_sw_ctx_off=__a64_sw_off-ARM64_SKB_CB_OFF+__builtin_offsetof(struct __sk_buff,cb); \
       ARM64_SIM_L_SKB_CB_WRITE(__a64_sim_helper_ctx,__a64_sw_ctx_off,(WIDTH),__a64_sw_value); \
      } else { void *__a64_sw_pointer; ARM64_SIM_L_READ_REG_PTR_INTO(__a64_sw_pointer, (BASE)); \
          ARM64_SIM_L_STORE_ADDR((__u8 *)__a64_sw_pointer+(OFF),(WIDTH),__a64_sw_value); } \
 } while (0)

/* The generic memory dispatch retains stack observation, typed pointer loads,
 * relocation-offset rejection and ordinary native-width loads. */
#define ARM64_SIM_L_MEM_READ_DISPATCH_INTO(OUTPUT, BASE, OFF, WIDTH, SOURCE) \
    do { \
        __u64 __a64_mrd_value; \
        switch (SOURCE) { \
        case KPROG_ARM64_MEM_SRC_STACK: { \
            __s64 __a64_mrd_base; \
            if (KPROG_ARM64_MEM_BASE_SRC((BASE) == ARM64_SP) == KPROG_ARM64_MEM_BASE_SRC_SP_REGISTER) \
                __a64_mrd_base = __a64_sp; \
            else { void *__a64_mrd_pointer; ARM64_SIM_L_READ_REG_PTR_INTO(__a64_mrd_pointer, (BASE)); \
                __a64_mrd_base = (__s64)(long)__a64_mrd_pointer; } \
            ARM64_SIM_L_STACK_READ_INTO(__a64_mrd_value, __a64_mrd_base + (OFF), (WIDTH)); \
            break; \
        } \
        case KPROG_ARM64_MEM_SRC_ABI_PTR_LOAD: { \
            void *__a64_mrd_pointer, *__a64_mrd_loaded; \
            ARM64_SIM_L_READ_REG_PTR_INTO(__a64_mrd_pointer, (BASE)); \
            ARM64_SIM_L_LOAD_PTR_AT_INTO(__a64_mrd_loaded, __a64_mrd_pointer, (OFF)); \
            __a64_mrd_value = (__u64)(long)__a64_mrd_loaded; \
            break; \
        } \
        case KPROG_ARM64_MEM_SRC_RELOC_PTR: { \
            if ((OFF) != 0) ARM64_SIM_L_UNSUPPORTED_OPCODE(); \
            void *__a64_mrd_pointer; ARM64_SIM_L_READ_REG_PTR_INTO(__a64_mrd_pointer, (BASE)); \
            __a64_mrd_value = (__u64)(long)__a64_mrd_pointer; \
            break; \
        } \
        default: { \
            void *__a64_mrd_pointer; ARM64_SIM_L_READ_REG_PTR_INTO(__a64_mrd_pointer, (BASE)); \
            KPROG_ARM64_LOAD_BYTES_OFFSET_INTO(__a64_mrd_value, __a64_mrd_pointer, (OFF), (WIDTH)); \
            break; \
        } \
        } \
        (OUTPUT) = __a64_mrd_value; \
    } while (0)

/* Untyped/kernel addresses use the same probe-read route as x86 B. A caller
 * slot avoids adding an eight-byte callee frame to tail-call programs. Typed
 * stack/context/packet/map accesses and relocation-pointer loads stay direct. */
#if defined(__bpf__) || defined(__BPF__)
static __attribute__((noinline)) __u64
arm64_sim_bpf_probe_load_into(__u64 *value, const void *base,
                            __s64 displacement, __u8 width)
{
    const void *address = (const __u8 *)base + displacement;
    if (width == ARM64_WIDTH_64) {
        bpf_probe_read_kernel(value, sizeof(__u64), address);
        return *value;
    } else if (width >= ARM64_WIDTH_32) {
        bpf_probe_read_kernel(value, sizeof(__u32), address);
        return *(__u32 *)value;
    } else if (width >= ARM64_WIDTH_16) {
        bpf_probe_read_kernel(value, sizeof(__u16), address);
        return *(__u16 *)value;
    }
    bpf_probe_read_kernel(value, sizeof(__u8), address);
    return *(__u8 *)value;
}
#define ARM64_SIM_L_TAG_KERNEL_MEMORY(TAG) \
    ((TAG) != ARM64_SIM_TAG_STACK && ((TAG) != ARM64_SIM_TAG_ABI || __a64_sim_abi_kind == ARM64_SIM_ABI_KIND_RAW) && \
     (TAG) != ARM64_SIM_TAG_PACKET && (TAG) != ARM64_SIM_TAG_PACKET_END && \
     (TAG) != ARM64_SIM_TAG_MAP_PTR && (TAG) != ARM64_SIM_TAG_MAP_VALUE)
#define ARM64_SIM_L_KERNEL_LOAD_INTO(OUTPUT, BASE, OFF, WIDTH) \
    do { __u64 __a64_probe_value; \
         (OUTPUT) = arm64_sim_bpf_probe_load_into(&__a64_probe_value, (BASE), (OFF), (WIDTH)); \
    } while (0)
#else
#define ARM64_SIM_L_TAG_KERNEL_MEMORY(TAG) 0
#define ARM64_SIM_L_KERNEL_LOAD_INTO(OUTPUT, BASE, OFF, WIDTH) \
    KPROG_ARM64_LOAD_BYTES_OFFSET_INTO((OUTPUT), (BASE), (OFF), (WIDTH))
#endif

/* A known context displacement uses the entry base as the BPF instruction
 * operand. CompCert uses the generic base+offset access at that same address;
 * it has no __builtin_constant_p or physical cross-block pointer subtraction.
 * The operand/address correspondence is a platform proof obligation. */
#if defined(__COMPCERT__)
#define ARM64_SIM_L_MEM_READ_ADDRESS_INTO(OUTPUT, BASE, OFF, WIDTH, TAG, SOURCE) \
    ARM64_SIM_L_MEM_READ_DISPATCH_INTO((OUTPUT), (BASE), (OFF), (WIDTH), (SOURCE))
#else
#define ARM64_SIM_L_MEM_READ_ADDRESS_INTO(OUTPUT, BASE, OFF, WIDTH, TAG, SOURCE) \
    do { \
        void *__a64_mra_pointer; ARM64_SIM_L_READ_REG_PTR_INTO(__a64_mra_pointer, (BASE)); \
        __s64 __a64_mra_ctx_off = (__s64)((__u64)(long)__a64_mra_pointer - \
            (__u64)(long)__a64_sim_helper_ctx + (__u64)(OFF)); \
        if ((TAG) == ARM64_SIM_TAG_ABI && __builtin_constant_p(__a64_mra_ctx_off)) { \
            KPROG_ARM64_LOAD_BYTES_OFFSET_INTO((OUTPUT), __a64_sim_helper_ctx, __a64_mra_ctx_off, (WIDTH)); \
        } else if (((SOURCE) == KPROG_ARM64_MEM_SRC_NORMAL_LOAD || (SOURCE) == KPROG_ARM64_MEM_SRC_ABI_PTR_LOAD) && ARM64_SIM_L_TAG_KERNEL_MEMORY(TAG)) { \
            ARM64_SIM_L_KERNEL_LOAD_INTO((OUTPUT), __a64_mra_pointer, (OFF), (WIDTH)); \
        } else ARM64_SIM_L_MEM_READ_DISPATCH_INTO((OUTPUT), (BASE), (OFF), (WIDTH), (SOURCE)); \
    } while (0)
#endif

#define ARM64_SIM_L_MEM_READ_INTO(OUTPUT, BASE, INDEX, AUX, IMM, EXTRA, WIDTH) \
    do { \
        __s64 __a64_memory_off; \
        ARM64_SIM_L_MEM_BASE_OFF_INTO(__a64_memory_off, (AUX), (INDEX), (IMM)); \
        __a64_memory_off += (EXTRA); \
        __u8 __a64_memory_tag, __a64_memory_source; \
        ARM64_SIM_L_REG_TAG_INTO(__a64_memory_tag, (BASE)); \
        KPROG_ARM64_MEM_READ_SRC_INTO(__a64_memory_source, (BASE) == ARM64_SP, __a64_memory_tag, (WIDTH)); \
        __u64 __a64_memory_value; \
        if (__a64_sim_is_xdp && __a64_memory_tag == ARM64_SIM_TAG_ABI) { \
            ARM64_SIM_L_XDP_READ_INTO(__a64_memory_value, (BASE), __a64_memory_off, (WIDTH)); \
        } else if (__a64_sim_abi_kind == KPROG_ABI_KIND_SKB && __a64_memory_tag == ARM64_SIM_TAG_ABI) { \
            ARM64_SIM_L_SKB_READ_INTO(__a64_memory_value, (BASE), __a64_memory_off, (WIDTH)); \
        } else ARM64_SIM_L_MEM_READ_ADDRESS_INTO(__a64_memory_value, (BASE), __a64_memory_off, (WIDTH), __a64_memory_tag, __a64_memory_source); \
        (OUTPUT) = __a64_memory_value; \
    } while (0)
#define ARM64_SIM_L_MEM_READ(BASE, INDEX, AUX, IMM, EXTRA, WIDTH) \
    ({ __u64 __a64_memory_result; \
       ARM64_SIM_L_MEM_READ_INTO(__a64_memory_result, (BASE), (INDEX), (AUX), (IMM), (EXTRA), (WIDTH)); \
       __a64_memory_result; })

#define ARM64_SIM_L_MEM_READ_TAG_INTO(OUTPUT, BASE, INDEX, AUX, IMM, EXTRA, WIDTH)        \
	do {                                                                 \
		__s64 __a64_mrt_off; \
        ARM64_SIM_L_MEM_BASE_OFF_INTO(__a64_mrt_off, (AUX), (INDEX), (IMM)); \
        __a64_mrt_off += (EXTRA);\
		__u8 __a64_mrt_tag; \
        ARM64_SIM_L_REG_TAG_INTO(__a64_mrt_tag, (BASE));          \
		__u8 __a64_mrt_src; \
        KPROG_ARM64_MEM_READ_TAG_INTO(__a64_mrt_src,            \
			((BASE) == ARM64_SP), __a64_mrt_tag, (WIDTH));   \
		__u8 __a64_mrt_value_tag;                                \
		switch (__a64_mrt_src) {                                 \
		case KPROG_ARM64_MEM_TAG_STACK: {                        \
		__u8 __a64_mrt_bsrc = KPROG_ARM64_MEM_BASE_SRC(       \
			(BASE) == ARM64_SP);                             \
		__s64 __a64_mrt_base =                               \
			(__a64_mrt_bsrc == KPROG_ARM64_MEM_BASE_SRC_SP_REGISTER)\
				? __a64_sp                              \
				: 0; \
        if (__a64_mrt_bsrc != KPROG_ARM64_MEM_BASE_SRC_SP_REGISTER) { \
            void *__a64_mrt_pointer; ARM64_SIM_L_READ_REG_PTR_INTO(__a64_mrt_pointer, (BASE)); \
            __a64_mrt_base = (__s64)(long)__a64_mrt_pointer; }\
			ARM64_SIM_L_STACK_READ_TAG_INTO(__a64_mrt_value_tag,  \
				__a64_mrt_base + __a64_mrt_off, (WIDTH));\
			break;                                             \
		}                                                        \
		case KPROG_ARM64_MEM_TAG_ABI:                            \
            if (__a64_sim_abi_kind == ARM64_SIM_ABI_KIND_RAW) __a64_mrt_value_tag = ARM64_SIM_TAG_ABI; \
            else { __s64 __a64_mrt_context_off = 0; \
                if (__a64_sim_is_xdp || __a64_sim_abi_kind == KPROG_ABI_KIND_SKB) { \
                    void *__a64_mrt_pointer; ARM64_SIM_L_READ_REG_PTR_INTO(__a64_mrt_pointer, (BASE)); \
                    __a64_mrt_context_off = (__s64)((__u8 *)__a64_mrt_pointer - (__u8 *)(__a64_sim_is_xdp ? __a64_sim_helper_ctx : __a64_sim_helper_abi_base)); \
                } \
                KPROG_ABI_LOAD_TAG_INTO(__a64_mrt_value_tag, __a64_sim_abi_kind, __a64_mrt_context_off + __a64_mrt_off, \
                    ARM64_SIM_TAG_SCALAR, ARM64_SIM_TAG_PACKET, ARM64_SIM_TAG_PACKET_END); \
            } \
			break;                                             \
		case KPROG_ARM64_MEM_TAG_MAP_PTR:                        \
			if (__a64_mrt_off != 0)                            \
				ARM64_SIM_L_UNSUPPORTED_OPCODE();          \
			__a64_mrt_value_tag = ARM64_SIM_TAG_MAP_PTR;       \
			break;                                             \
		default:                                                 \
			__a64_mrt_value_tag = ARM64_SIM_TAG_SCALAR;        \
			break;                                             \
		}                                                        \
		(OUTPUT) = __a64_mrt_value_tag;                                     \
	} while (0)
#define ARM64_SIM_L_MEM_READ_TAG(BASE, INDEX, AUX, IMM, EXTRA, WIDTH) \
    ({ __u8 __a64_metadata_result; \
       ARM64_SIM_L_MEM_READ_TAG_INTO(__a64_metadata_result, (BASE), (INDEX), (AUX), (IMM), (EXTRA), (WIDTH)); \
       __a64_metadata_result; })
/* Ghost payloads recover relative addressing after a whole pointer spill.
 * Guest bytes remain materialized, so byte/word/vector observations see the
 * exact native address. Partial writes clear the corresponding tag first.
 */
#define ARM64_SIM_L_MEM_PAYLOAD_INTO(OUTPUT, BASE, INDEX, AUX, IMM, EXTRA, VALUE, TAG)   \
	do { __u64 __a64_mp_value = (VALUE); __u8 __a64_mp_tag = (TAG);     \
	   switch (__a64_mp_tag) { \
	   case ARM64_SIM_TAG_STACK: case ARM64_SIM_TAG_RETURN: { \
		__s64 __a64_mp_base; \
        if (KPROG_ARM64_MEM_BASE_SRC((BASE) == ARM64_SP) == KPROG_ARM64_MEM_BASE_SRC_SP_REGISTER) __a64_mp_base = __a64_sp; \
        else { void *__a64_mp_pointer; ARM64_SIM_L_READ_REG_PTR_INTO(__a64_mp_pointer, (BASE)); __a64_mp_base = (__s64)(long)__a64_mp_pointer; }        \
		__s64 __a64_mp_off; \
        ARM64_SIM_L_MEM_BASE_OFF_INTO(__a64_mp_off, (AUX), (INDEX), (IMM)); __a64_mp_off += (EXTRA); \
		__u64 __a64_mp_at = ARM64_SIM_L_STACK_INDEX(__a64_mp_base + __a64_mp_off); \
		ARM64_SIM_L_STACK_INDEX_OPACITY(__a64_mp_at, ARM64_WIDTH_64);                      \
		__a64_mp_value = ARM64_SIM_L_STACK_PAYLOAD_LOAD(KPROG_ARM64_STACK_WORD_INDEX(__a64_mp_at)); \
	   break; } default: break; } (OUTPUT) = __a64_mp_value; } while (0)
#define ARM64_SIM_L_MEM_PAYLOAD(BASE, INDEX, AUX, IMM, EXTRA, VALUE, TAG) \
    ({ __u64 __a64_metadata_result; \
       ARM64_SIM_L_MEM_PAYLOAD_INTO(__a64_metadata_result, (BASE), (INDEX), (AUX), (IMM), (EXTRA), (VALUE), (TAG)); \
       __a64_metadata_result; })

#define ARM64_SIM_L_MEM_WRITE_AT(BASE, OFF, WIDTH, VALUE, TAG) \
	do { \
		__s64 __a64_mwr_off = (OFF); \
		__u8 __a64_mwr_tag; ARM64_SIM_L_REG_TAG_INTO(__a64_mwr_tag, (BASE));          \
		__u8 __a64_mwr_arm = KPROG_ARM64_MEM_WRITE_ARM(          \
			((BASE) == ARM64_SP), __a64_mwr_tag);            \
		if (__a64_sim_abi_kind == KPROG_ABI_KIND_SKB && __a64_mwr_tag == ARM64_SIM_TAG_ABI) { \
            ARM64_SIM_L_SKB_WRITE((BASE), __a64_mwr_off, (WIDTH), (VALUE)); \
        } else if (__a64_mwr_arm == KPROG_ARM64_MEM_WRITE_ARM_STACK) {  \
		__u8 __a64_mwr_bsrc = KPROG_ARM64_MEM_BASE_SRC(       \
			(BASE) == ARM64_SP);                             \
		__s64 __a64_mwr_base = __a64_sp; \
        if (__a64_mwr_bsrc != KPROG_ARM64_MEM_BASE_SRC_SP_REGISTER) { \
            void *__a64_mwr_pointer; ARM64_SIM_L_READ_REG_PTR_INTO(__a64_mwr_pointer, (BASE)); \
            __a64_mwr_base = (__s64)(long)__a64_mwr_pointer; }\
			ARM64_SIM_L_STACK_WRITE_TAG(__a64_mwr_base + __a64_mwr_off,\
						    (WIDTH), (VALUE), (TAG));\
		} else {                                                   \
			void *__a64_mwr_pointer; ARM64_SIM_L_READ_REG_PTR_INTO(__a64_mwr_pointer, (BASE)); \
            void *__a64_mwr_addr = (__u8 *)__a64_mwr_pointer + __a64_mwr_off;\
			ARM64_SIM_L_STORE_ADDR(__a64_mwr_addr, (WIDTH), (VALUE));\
		}                                                         \
	} while (0)

/* Resolve the index before observing the stored value, including cold
 * coordinate inputs. Scalar instruction bodies reuse the same resolved write. */
#define ARM64_SIM_L_MEM_WRITE(BASE, INDEX, AUX, IMM, EXTRA, WIDTH, VALUE, TAG) \
    do { __s64 __a64_mws_off; \
        ARM64_SIM_L_MEM_BASE_OFF_INTO(__a64_mws_off, (AUX), (INDEX), (IMM)); \
        __a64_mws_off += (EXTRA); \
        ARM64_SIM_L_MEM_WRITE_AT((BASE), __a64_mws_off, (WIDTH), (VALUE), (TAG)); \
    } while (0)

/* Observe each source after its slot's index and before the next slot.
 * Clight requires a statement output; retain the native expression operand
 * at the write site because moving it changes LLVM's stack-slot assignment.
 * Both forms use the same read, tag and resolved memory-write bodies. */
#if defined(__COMPCERT__)
#define ARM64_SIM_L_MEM_WRITE_REG(BASE, INDEX, AUX, IMM, EXTRA, WIDTH, SRC) \
    do { __s64 __a64_mwg_off; __u64 __a64_mwg_value; __u8 __a64_mwg_tag; \
        ARM64_SIM_L_MEM_BASE_OFF_INTO(__a64_mwg_off, (AUX), (INDEX), (IMM)); \
        __a64_mwg_off += (EXTRA); \
        ARM64_SIM_L_READ_REG_INTO(__a64_mwg_value, (SRC)); \
        ARM64_SIM_L_REG_TAG_INTO(__a64_mwg_tag, (SRC)); \
        ARM64_SIM_L_MEM_WRITE_AT((BASE), __a64_mwg_off, (WIDTH), __a64_mwg_value, __a64_mwg_tag); \
    } while (0)
#else
#define ARM64_SIM_L_MEM_WRITE_REG(BASE, INDEX, AUX, IMM, EXTRA, WIDTH, SRC) \
    ARM64_SIM_L_MEM_WRITE((BASE), (INDEX), (AUX), (IMM), (EXTRA), (WIDTH), \
        ARM64_SIM_L_READ_REG(SRC), ARM64_SIM_L_REG_TAG(SRC))
#endif

/* The `LOAD_D0` / `LOAD_Q0` / `STORE_D0` / `STORE_Q0` vector memory-transfer
 * contract fixes, per opcode, the access direction (load into / store from the
 * SIMD register), the number of 64-bit lanes moved, and the lane offset plan
 * (every transferred lane is one `ARM64_WIDTH_64` access, the high lane of a
 * `.Q0` transfer eight bytes above the low one). The vector-register-file
 * contract additionally fixes which 64-bit state field each moved half maps
 * into (`__a64_v0` low, `__a64_v0_hi` high) and in which order the halves are
 * touched. The four bodies route through this one step: the memory direction,
 * lane count and per-position lane offset are selected from the generated
 * `KPROG_ARM64_DQ_MEM_*` per-opcode constants, and the half count, half plan
 * and destination state field from the generated `KPROG_ARM64_VREG_*` per-opcode
 * constants, so neither the memory facts nor the register-file facts and the
 * four C bodies can drift. */
#define ARM64_SIM_L_DQ_MEM_STEP(OP, BASE, INDEX, AUX, IMM)                  \
	do {                                                               \
		__u32 __a64_dq_idx; KPROG_ARM64_DQ_MEM_INDEX_INTO(__a64_dq_idx, (OP));         \
		__u32 __a64_dq_access = __a64_dq_idx ==               \
				KPROG_ARM64_DQ_MEM_OP_LOAD_D0_INDEX ?   \
			KPROG_ARM64_DQ_MEM_OP_LOAD_D0_ACCESS :          \
			__a64_dq_idx == KPROG_ARM64_DQ_MEM_OP_LOAD_Q0_INDEX ?\
			KPROG_ARM64_DQ_MEM_OP_LOAD_Q0_ACCESS :          \
			__a64_dq_idx == KPROG_ARM64_DQ_MEM_OP_STORE_D0_INDEX ?\
			KPROG_ARM64_DQ_MEM_OP_STORE_D0_ACCESS :         \
			KPROG_ARM64_DQ_MEM_OP_STORE_Q0_ACCESS;          \
		int __a64_dq_load =                                   \
			__a64_dq_access == KPROG_ARM64_DQ_MEM_ACCESS_LOAD;\
		if (__a64_dq_load) { int __a64_dq_fault; \
            ARM64_SIM_L_READ_FAULT_CALL_INTO(__a64_dq_fault, (BASE), (INDEX), (AUX), (IMM)); \
            if (__a64_dq_fault) break; }                                             \
		unsigned __a64_dq_lanes = __a64_dq_idx ==             \
				KPROG_ARM64_DQ_MEM_OP_LOAD_D0_INDEX ?   \
			KPROG_ARM64_DQ_MEM_OP_LOAD_D0_LANES :           \
			__a64_dq_idx == KPROG_ARM64_DQ_MEM_OP_LOAD_Q0_INDEX ?\
			KPROG_ARM64_DQ_MEM_OP_LOAD_Q0_LANES :           \
			__a64_dq_idx == KPROG_ARM64_DQ_MEM_OP_STORE_D0_INDEX ?\
			KPROG_ARM64_DQ_MEM_OP_STORE_D0_LANES :          \
			KPROG_ARM64_DQ_MEM_OP_STORE_Q0_LANES;           \
		__u32 __a64_vreg_idx; KPROG_ARM64_VREG_INDEX_INTO(__a64_vreg_idx, (OP));         \
		unsigned __a64_vreg_plan = __a64_vreg_idx ==          \
				KPROG_ARM64_VREG_OP_LOAD_D0_INDEX ?     \
			KPROG_ARM64_VREG_OP_LOAD_D0_HALVES :            \
			__a64_vreg_idx == KPROG_ARM64_VREG_OP_LOAD_Q0_INDEX ?\
			KPROG_ARM64_VREG_OP_LOAD_Q0_HALVES :            \
			__a64_vreg_idx == KPROG_ARM64_VREG_OP_STORE_D0_INDEX ?\
			KPROG_ARM64_VREG_OP_STORE_D0_HALVES :           \
			KPROG_ARM64_VREG_OP_STORE_Q0_HALVES;            \
		unsigned __a64_vreg_p;                                \
		ARM64_SIM_L_MEM_PRE((BASE), (AUX), (IMM));                 \
		for (__a64_vreg_p = 0U; __a64_vreg_p < __a64_vreg_plan;  \
		     __a64_vreg_p++) {                                 \
			unsigned __a64_vreg_half = __a64_vreg_idx ==  \
					KPROG_ARM64_VREG_OP_LOAD_D0_INDEX ?\
				KPROG_ARM64_VREG_OP_LOAD_D0_SELECT(__a64_vreg_p) :\
				__a64_vreg_idx == KPROG_ARM64_VREG_OP_LOAD_Q0_INDEX ?\
				KPROG_ARM64_VREG_OP_LOAD_Q0_SELECT(__a64_vreg_p) :\
				__a64_vreg_idx == KPROG_ARM64_VREG_OP_STORE_D0_INDEX ?\
				KPROG_ARM64_VREG_OP_STORE_D0_SELECT(__a64_vreg_p) :\
				KPROG_ARM64_VREG_OP_STORE_Q0_SELECT(__a64_vreg_p);\
			__s64 __a64_vreg_off = (__s64)                \
				KPROG_ARM64_VREG_HALF_OFFSET(__a64_vreg_half);\
			__u8 __a64_vreg_field = KPROG_ARM64_VREG_FIELD(       \
				__a64_vreg_off == (__s64)             \
					KPROG_ARM64_VREG_HIGH_OFFSET);\
			__s64 __a64_dq_extra = KPROG_ARM64_DQ_MEM_EXTRA(   \
				__a64_vreg_p == 0U, __a64_dq_lanes > 1U);\
			if (__a64_dq_load) {                          \
				__u64 __a64_dq_value; \
                ARM64_SIM_L_MEM_READ_INTO(__a64_dq_value, (BASE), (INDEX), (AUX), (IMM), \
                    __a64_dq_extra, KPROG_ARM64_DQ_MEM_LANE_STRIDE);\
				if (__a64_vreg_field ==               \
						KPROG_ARM64_VREG_HIGH_FIELD)\
					__a64_v0_hi = __a64_dq_value; \
				else                                  \
					__a64_v0 = __a64_dq_value;    \
			} else if (__a64_vreg_field ==                \
					KPROG_ARM64_VREG_HIGH_FIELD) { \
				ARM64_SIM_L_MEM_WRITE((BASE), (INDEX),\
					(AUX), (IMM), __a64_dq_extra,\
					KPROG_ARM64_DQ_MEM_LANE_STRIDE,\
					__a64_v0_hi, ARM64_SIM_TAG_SCALAR);\
			} else {                                      \
				ARM64_SIM_L_MEM_WRITE((BASE), (INDEX),\
					(AUX), (IMM), __a64_dq_extra,\
					KPROG_ARM64_DQ_MEM_LANE_STRIDE,\
					__a64_v0, ARM64_SIM_TAG_SCALAR);\
			}                                             \
		}                                                     \
		if (KPROG_ARM64_DQ_MEM_CLEAR_HIGH(OP))                    \
			__a64_v0_hi = 0;                                  \
		ARM64_SIM_L_MEM_POST((BASE), (AUX), (IMM));                \
	} while (0)

#define ARM64_SIM_L_LOAD_D0_MEM(BASE, INDEX, AUX, IMM)                       \
	ARM64_SIM_L_DQ_MEM_STEP(ARM64_OP_LOAD_D0, (BASE), (INDEX), (AUX), (IMM))

#define ARM64_SIM_L_LOAD_Q0_MEM(BASE, INDEX, AUX, IMM)                       \
	ARM64_SIM_L_DQ_MEM_STEP(ARM64_OP_LOAD_Q0, (BASE), (INDEX), (AUX), (IMM))

#define ARM64_SIM_L_STORE_D0_MEM(BASE, INDEX, AUX, IMM)                      \
	ARM64_SIM_L_DQ_MEM_STEP(ARM64_OP_STORE_D0, (BASE), (INDEX), (AUX), (IMM))

#define ARM64_SIM_L_STORE_Q0_MEM(BASE, INDEX, AUX, IMM)                      \
	ARM64_SIM_L_DQ_MEM_STEP(ARM64_OP_STORE_Q0, (BASE), (INDEX), (AUX), (IMM))

/* The `LDP` / `STP` pair-move contract fixes, per opcode, the access direction
 * (LDP loads a register pair from memory, STP stores one to memory), the number
 * of slots moved, and the slot plan (both slots are one access width apart).
 * The two bodies route through this one step, which selects the direction and
 * the slot count from the generated `KPROG_ARM64_PAIR_MEM_*` constants; the
 * access width, the address offset (`MEM_BASE_OFF`) and the pre/post base
 * adjustment (`MEM_PRE` / `MEM_POST`) stay in their own proved macros. The
 * second slot's byte offset is the parameterized `slot index * access width`,
 * so a 32-bit `LDP`/`STP` keeps its 4-byte slot stride. */
#define ARM64_SIM_L_PAIR_MEM_STEP(OP, DST, SRC, SRC2, BASE, INDEX, AUX, IMM, WIDTH)\
	do {                                                               \
		__u32 __a64_pm_index; KPROG_ARM64_PAIR_MEM_INDEX_INTO(__a64_pm_index, (OP)); \
        __u32 __a64_pm_access = __a64_pm_index ==  \
				KPROG_ARM64_PAIR_MEM_OP_LDP_INDEX ?        \
			KPROG_ARM64_PAIR_MEM_OP_LDP_ACCESS :               \
			KPROG_ARM64_PAIR_MEM_OP_STP_ACCESS;                \
		int __a64_pm_load = __a64_pm_access ==                 \
			KPROG_ARM64_PAIR_MEM_ACCESS_LOAD;                  \
		unsigned __a64_pm_slots = KPROG_ARM64_PAIR_MEM_SLOT_COUNT;\
		unsigned __a64_pm_hi = (WIDTH);                        \
        /* Arm LDPOVERLAP; pair writeback compares both data fields. */    \
        if (__a64_pm_load && (DST) == (SRC))                              \
            ARM64_SIM_L_UNSUPPORTED_OPCODE();                            \
        ARM64_SIM_L_WRITEBACK_OVERLAP((BASE),                             \
            (__a64_pm_load ? (DST) : (SRC)), (AUX));                      \
        ARM64_SIM_L_WRITEBACK_OVERLAP((BASE),                             \
            (__a64_pm_load ? (SRC) : (SRC2)), (AUX));                     \
        if (__a64_pm_load) { int __a64_pm_fault; \
            ARM64_SIM_L_READ_FAULT_CALL_INTO(__a64_pm_fault, (BASE), (INDEX), (AUX), (IMM)); \
            if (__a64_pm_fault) { \
                ARM64_SIM_L_CLEAR_READ_DEST(DST); \
                ARM64_SIM_L_CLEAR_READ_DEST(SRC); \
                break; \
            } \
        } \
		ARM64_SIM_L_MEM_PRE((BASE), (AUX), (IMM));             \
		if (__a64_pm_load) {                                   \
            __u64 __a64_pm_v0; \
            ARM64_SIM_L_MEM_READ_INTO(__a64_pm_v0, (BASE), (INDEX), (AUX), (IMM), 0, (WIDTH)); \
            __u64 __a64_pm_v1 = 0; \
            if (__a64_pm_slots > 1U) \
                ARM64_SIM_L_MEM_READ_INTO(__a64_pm_v1, (BASE), (INDEX), (AUX), (IMM), __a64_pm_hi, (WIDTH)); \
            __u8 __a64_pm_t0; \
            ARM64_SIM_L_MEM_READ_TAG_INTO(__a64_pm_t0, (BASE), (INDEX), (AUX), (IMM), 0, (WIDTH)); \
            __u8 __a64_pm_t1 = 0; \
            if (__a64_pm_slots > 1U) \
                ARM64_SIM_L_MEM_READ_TAG_INTO(__a64_pm_t1, (BASE), (INDEX), (AUX), (IMM), __a64_pm_hi, (WIDTH)); \
            __u64 __a64_pm_mask; \
            KPROG_ARM64_PAIR_LOAD_TAG_ROUTE_INTO(__a64_pm_mask, (OP), __a64_pm_t0, __a64_pm_t1, (WIDTH), ARM64_SIM_L_UNSUPPORTED_OPCODE()); \
            ARM64_SIM_L_MEM_PAYLOAD_INTO(__a64_pm_v0, (BASE), (INDEX), (AUX), (IMM), 0, __a64_pm_v0, __a64_pm_t0); \
            ARM64_SIM_L_MEM_PAYLOAD_INTO(__a64_pm_v1, (BASE), (INDEX), (AUX), (IMM), __a64_pm_hi, __a64_pm_v1, __a64_pm_t1); \
			if (KPROG_ARM64_PAIR_LOAD_TAG_ROUTE_LOW(__a64_pm_mask))\
				ARM64_SIM_L_WRITE_REG_PTR_TAG((DST),   \
					(void *)(long)__a64_pm_v0, \
					__a64_pm_t0);                  \
			else                                           \
				ARM64_SIM_L_WRITE_REG_WIDTH((DST),     \
					__a64_pm_v0, (WIDTH));         \
			if (KPROG_ARM64_PAIR_LOAD_TAG_ROUTE_HIGH(__a64_pm_mask))\
				ARM64_SIM_L_WRITE_REG_PTR_TAG((SRC),   \
					(void *)(long)__a64_pm_v1, \
					__a64_pm_t1);                  \
			else                                           \
				ARM64_SIM_L_WRITE_REG_WIDTH((SRC),     \
					__a64_pm_v1, (WIDTH));         \
		} else {                                               \
            ARM64_SIM_L_MEM_WRITE_REG((BASE), (INDEX), (AUX), (IMM), 0, (WIDTH), (SRC)); \
            if (__a64_pm_slots > 1U) \
                ARM64_SIM_L_MEM_WRITE_REG((BASE), (INDEX), (AUX), (IMM), __a64_pm_hi, (WIDTH), (SRC2)); \
		}                                                      \
		ARM64_SIM_L_MEM_POST((BASE), (AUX), (IMM));            \
	} while (0)

#define ARM64_SIM_L_LDP(DST, SRC, BASE, INDEX, AUX, IMM, WIDTH)              \
	ARM64_SIM_L_PAIR_MEM_STEP(ARM64_OP_LDP, (DST), (SRC),                 \
		ARM64_REG_NONE, (BASE), (INDEX), (AUX), (IMM), (WIDTH))

#define ARM64_SIM_L_STP(BASE, SRC, SRC2, INDEX, AUX, IMM, WIDTH)             \
	ARM64_SIM_L_PAIR_MEM_STEP(ARM64_OP_STP, ARM64_REG_NONE, (SRC),        \
		(SRC2), (BASE), (INDEX), (AUX), (IMM), (WIDTH))

#define ARM64_SIM_L_SET_SUB_FLAGS(LHS, RHS, WIDTH)                          \
	KPROG_ARM64_SET_SUB_FLAGS(__a64_n, __a64_z, __a64_c, __a64_v,       \
				  (LHS), (RHS), (WIDTH))

#define ARM64_SIM_L_SET_ADD_FLAGS(LHS, RHS, WIDTH)                          \
	KPROG_ARM64_SET_ADD_FLAGS(__a64_n, __a64_z, __a64_c, __a64_v,       \
				  (LHS), (RHS), (WIDTH))

#define ARM64_SIM_L_SET_LOGIC_FLAGS(VALUE, WIDTH)                           \
	KPROG_ARM64_SET_LOGIC_FLAGS(__a64_n, __a64_z, __a64_c, __a64_v,     \
				    (VALUE), (WIDTH))

#define ARM64_SIM_L_EVAL_COND(COND)                                         \
	KPROG_ARM64_EVAL_COND((COND), __a64_n, __a64_z, __a64_c, __a64_v,   \
		ARM64_SIM_L_UNSUPPORTED_OPCODE())

/* A reachable invalid instruction or PC rejects verification before execution. */
#if defined(__BPF__) || defined(__bpf__)
#define ARM64_SIM_L_UNSUPPORTED_OPCODE() \
    do { asm volatile("call -1" ::: "r0", "r1", "r2", "r3", "r4", "r5", "memory"); } while (0)
#else
#define ARM64_SIM_L_UNSUPPORTED_OPCODE() \
    do { extern void arm64_sim_unsupported_opcode(void); arm64_sim_unsupported_opcode(); } while (0)
#endif
#define ARM64_SIM_L_REJECT_PC() ARM64_SIM_L_UNSUPPORTED_OPCODE()

/* Decoded values retain native initializer ordering; only extraction uses
 * the corresponding standard-C output kernel with the same operands. */
#if defined(__COMPCERT__)
#define ARM64_SIM_L_VALUE(TYPE, NAME, KERNEL, ...) \
    TYPE NAME; KERNEL##_INTO(NAME, __VA_ARGS__)
#else
#define ARM64_SIM_L_VALUE(TYPE, NAME, KERNEL, ...) \
    TYPE NAME = KERNEL(__VA_ARGS__)
#endif

#define ARM64_SIM_L_EXEC_ALU(OP, DST, SRC, SRC2, FLAGS, AUX, IMM)           \
	do {                                                               \
		const __u8 __a64_alu_width = (FLAGS);                           \
		__u64 __a64_alu_lhs = ARM64_SIM_L_READ_REG(SRC);          \
		ARM64_SIM_L_VALUE(__u64, __a64_alu_rhs, KPROG_ARM64_ALU_RHS,               \
			KPROG_ARM64_ALU_OPERAND_SELECT((OP)), (IMM), ARM64_SIM_L_MOD(AUX),\
			ARM64_SIM_L_READ_REG(SRC2), ARM64_SIM_L_SHIFT(AUX),\
			__a64_alu_width);                                  \
		const __u8 __a64_alu_op = (AUX) & 0xffU;                        \
		__u8 __a64_alu_src_tag = ARM64_SIM_L_REG_TAG(SRC);        \
		ARM64_SIM_L_VALUE(__u64, __a64_alu_result, KPROG_ALU64_RESULT, __a64_alu_op, __a64_alu_lhs,   \
				__a64_alu_rhs,                            \
				ARM64_SIM_L_UNSUPPORTED_OPCODE());        \
        /* SP keeps its arena-relative coordinate through full-width ADD/SUB. */ \
        if (__a64_alu_width==ARM64_WIDTH_64 && (DST)==ARM64_SP && \
            __a64_alu_src_tag==ARM64_SIM_TAG_STACK && \
            (__a64_alu_op==ARM64_ALU_ADD || __a64_alu_op==ARM64_ALU_SUB)) \
            ARM64_SIM_L_WRITE_REG_PTR_TAG((DST),KPROG_PTR_ADD64_BITS(ARM64_SIM_L_READ_REG_PTR(SRC), \
                __a64_alu_op==ARM64_ALU_ADD ? __a64_alu_rhs : -__a64_alu_rhs),ARM64_SIM_TAG_STACK); \
        else \
		/* Native SP is 16-byte aligned at this AAPCS64 boundary. */ \
		if (__a64_alu_width == ARM64_WIDTH_64 && __a64_alu_op == ARM64_ALU_ORR && \
		    __a64_alu_src_tag == ARM64_SIM_TAG_STACK && __a64_alu_rhs < 16U) \
			ARM64_SIM_L_WRITE_REG_PTR_TAG((DST), \
				KPROG_PTR_ADD64_BITS(ARM64_SIM_L_READ_REG_PTR(SRC), \
					__a64_alu_rhs & ~(__u64)(long)ARM64_SIM_L_READ_REG_PTR(SRC)), \
				ARM64_SIM_TAG_STACK); \
		else \
		if (KPROG_ARM64_ALU_USE_STACK_SUB(__a64_alu_width, \
			__a64_alu_op, (DST) == ARM64_SP, \
			__a64_alu_src_tag == ARM64_SIM_TAG_STACK)) \
			ARM64_SIM_L_WRITE_REG_PTR_TAG((DST), \
				KPROG_PTR_ADD64_BITS(ARM64_SIM_L_READ_REG_PTR(SRC), -__a64_alu_rhs), \
				ARM64_SIM_TAG_STACK); \
		else \
		if (KPROG_ARM64_ALU_USE_POINTER(__a64_alu_width,           \
			__a64_alu_op, (DST) == ARM64_SP,                    \
			__a64_alu_src_tag == ARM64_SIM_TAG_SCALAR))         \
			ARM64_SIM_L_WRITE_REG_PTR_TAG((DST),              \
				KPROG_PTR_ADD64_BITS(                      \
					ARM64_SIM_L_READ_REG_PTR(SRC),       \
					__a64_alu_rhs),                     \
				KPROG_PTR_ADD64_TAG(__a64_alu_src_tag));   \
		else                                                       \
			ARM64_SIM_L_WRITE_REG_WIDTH((DST), __a64_alu_result, __a64_alu_width);\
	} while (0)

/* LSE atomic RMW returns the pre-update value; operands precede destination writeback.
 * Arm Instruction Set Reference 100076, section D3.6. */
#define ARM64_SIM_L_ATOMIC_KIND___atomic_fetch_add 0U
#define ARM64_SIM_L_ATOMIC_KIND___atomic_fetch_or 1U
#define ARM64_SIM_L_ATOMIC_KIND___atomic_fetch_and 2U
#if defined(__bpf__)
extern __u64 bpf_arm64_native_lab_atomic8(__u8 *word, __u64 value, __u32 operation, __u32 order) __ksym;
extern __u64 bpf_arm64_native_lab_atomic16(__u16 *word, __u64 value, __u32 operation, __u32 order) __ksym;
#define ARM64_SIM_L_ATOMIC_BYTE(FETCH, ADDR, VALUE, ORDER) \
 ((__u8)bpf_arm64_native_lab_atomic8((__u8 *)(ADDR), (VALUE), ARM64_SIM_L_ATOMIC_KIND_##FETCH, (ORDER)))
#define ARM64_SIM_L_ATOMIC_HALF(FETCH, ADDR, VALUE, ORDER) \
 ((__u16)bpf_arm64_native_lab_atomic16((__u16 *)(ADDR), (VALUE), ARM64_SIM_L_ATOMIC_KIND_##FETCH, (ORDER)))
#elif defined(__COMPCERT__)
#define ARM64_SIM_L_ATOMIC_BYTE(FETCH, ADDR, VALUE, ORDER) \
 ((__u8)kprog_c_atomic_fetch((ADDR), (__u8)(VALUE), 1U, ARM64_SIM_L_ATOMIC_KIND_##FETCH, (ORDER)))
#define ARM64_SIM_L_ATOMIC_HALF(FETCH, ADDR, VALUE, ORDER) \
 ((__u16)kprog_c_atomic_fetch((ADDR), (__u16)(VALUE), 2U, ARM64_SIM_L_ATOMIC_KIND_##FETCH, (ORDER)))
#else
#define ARM64_SIM_L_ATOMIC_BYTE(FETCH, ADDR, VALUE, ORDER) \
 FETCH((__u8 *)(ADDR), (__u8)(VALUE), (ORDER))
#define ARM64_SIM_L_ATOMIC_HALF(FETCH, ADDR, VALUE, ORDER) \
 FETCH((__u16 *)(ADDR), (__u16)(VALUE), (ORDER))
#endif

/* GCC overloads these builtins by pointed-to width. Preserve that native
 * operand form; CompCert calls the explicitly typed atomic platform operation. */
#if defined(__COMPCERT__)
#define ARM64_SIM_L_ATOMIC_WORD(FETCH, BITS, ADDR, VALUE, ORDER) \
 ((__u##BITS)kprog_c_atomic_fetch((ADDR), (__u##BITS)(VALUE), (BITS)/8U, ARM64_SIM_L_ATOMIC_KIND_##FETCH, (ORDER)))
#else
#define ARM64_SIM_L_ATOMIC_WORD(FETCH, BITS, ADDR, VALUE, ORDER) \
 FETCH((__u##BITS *)(ADDR), (__u##BITS)(VALUE), (ORDER))
#endif

#define ARM64_SIM_L_ATOMIC_RMW(FETCH, COMPLEMENT, DST, SRC, BASE, WIDTH, AUX) \
 do { \
    ARM64_SIM_L_SP_ALIGNMENT(BASE); \
    int __a64_la_fault; \
    ARM64_SIM_L_READ_FAULT_CALL_INTO(__a64_la_fault, (BASE), ARM64_REG_NONE, 0, 0); \
    if (__a64_la_fault) { \
        ARM64_SIM_L_CLEAR_READ_DEST(DST); \
        break; \
    } \
    void *__a64_la_addr; ARM64_SIM_L_HELPER_ARG_PTR_INTO(__a64_la_addr, (BASE)); \
    __u64 __a64_la_add; ARM64_SIM_L_READ_REG_INTO(__a64_la_add, (SRC)); \
    if (COMPLEMENT) __a64_la_add = ~__a64_la_add; \
    __u32 __a64_la_mem_aux = ARM64_AUX_MEM(ARM64_REG_NONE, ARM64_MOD_NONE, 0, 0); \
    __u8 __a64_la_tag; \
    ARM64_SIM_L_MEM_READ_TAG_INTO(__a64_la_tag, (BASE), ARM64_REG_NONE, __a64_la_mem_aux, 0, 0, (WIDTH)); \
    int __a64_la_acquire = ((AUX) & 1U) && (DST) != ARM64_XZR; \
    int __a64_la_order = ((AUX) & 2U) ? (__a64_la_acquire ? __ATOMIC_ACQ_REL : __ATOMIC_RELEASE) : (__a64_la_acquire ? __ATOMIC_ACQUIRE : __ATOMIC_RELAXED); \
    __u64 __a64_la_old; \
    if ((WIDTH) == ARM64_WIDTH_64) \
        __a64_la_old = ARM64_SIM_L_ATOMIC_WORD(FETCH, 64, __a64_la_addr, __a64_la_add, __a64_la_order); \
    else if ((WIDTH) == ARM64_WIDTH_32) \
        __a64_la_old = ARM64_SIM_L_ATOMIC_WORD(FETCH, 32, __a64_la_addr, __a64_la_add, __a64_la_order); \
    else if ((WIDTH) == ARM64_WIDTH_16) \
        __a64_la_old = ARM64_SIM_L_ATOMIC_HALF(FETCH, __a64_la_addr, __a64_la_add, __a64_la_order); \
    else \
        __a64_la_old = ARM64_SIM_L_ATOMIC_BYTE(FETCH, __a64_la_addr, __a64_la_add, __a64_la_order); \
    __u8 __a64_la_base_tag; ARM64_SIM_L_REG_TAG_INTO(__a64_la_base_tag, (BASE)); \
    if (__a64_la_base_tag == ARM64_SIM_TAG_STACK) { \
        void *__a64_la_base; ARM64_SIM_L_READ_REG_PTR_INTO(__a64_la_base, (BASE)); \
        if ((__s64)(long)__a64_la_base < ARM64_SIM_L_STACK_SP()) { \
            __a64_la_old = KPROG_ARM64_APPLY_WIDTH(ARM64_SIM_L_UNSPECIFIED(), (WIDTH)); \
            __u64 __a64_la_next = ARM64_SIM_L_ATOMIC_KIND_##FETCH == 0U ? __a64_la_old + __a64_la_add : \
                ARM64_SIM_L_ATOMIC_KIND_##FETCH == 1U ? __a64_la_old | __a64_la_add : __a64_la_old & __a64_la_add; \
            ARM64_SIM_L_MEM_WRITE((BASE), ARM64_REG_NONE, __a64_la_mem_aux, 0, 0, (WIDTH), __a64_la_next, ARM64_SIM_TAG_SCALAR); \
        } \
    } \
    __u64 __a64_la_payload; \
    ARM64_SIM_L_MEM_PAYLOAD_INTO(__a64_la_payload, (BASE), ARM64_REG_NONE, __a64_la_mem_aux, 0, 0, __a64_la_old, __a64_la_tag); \
    __u8 __a64_la_transfer_tag; ARM64_SIM_L_REG_TAG_INTO(__a64_la_transfer_tag, (BASE)); \
    if (__a64_la_transfer_tag == ARM64_SIM_TAG_STACK) { \
        void *__a64_la_transfer_base; ARM64_SIM_L_READ_REG_PTR_INTO(__a64_la_transfer_base, (BASE)); \
        ARM64_SIM_L_MEMORY_TAG_TRANSFER((__s64)(long)__a64_la_transfer_base, __a64_la_transfer_tag, 0, ARM64_SIM_TAG_SCALAR, (WIDTH), 0); \
    } \
    __u64 __a64_la_preserve; \
    KPROG_ARM64_LOAD_TAG_PRESERVE_INTO(__a64_la_preserve, ARM64_OP_LOAD, __a64_la_tag, (WIDTH), ARM64_SIM_L_UNSUPPORTED_OPCODE()); \
    if (__a64_la_preserve) \
        ARM64_SIM_L_WRITE_REG_PTR_TAG((DST), (void *)(long)__a64_la_payload, __a64_la_tag); \
    else \
        ARM64_SIM_L_WRITE_REG_WIDTH((DST), __a64_la_old, (WIDTH) == ARM64_WIDTH_64 ? ARM64_WIDTH_64 : ARM64_WIDTH_32); \
 } while (0)

/* The native input ABI supplies an explicit Boolean per dynamic visit.
 * Its shared header is outside this extraction layer; spell its host protocol
 * as standard statements for Clight, including the exact invalid-choice exit.
 * Native callers keep the original macro and BPF private instruction. */
#if defined(__COMPCERT__)
#define ARM64_SIM_L_EXCLUSIVE_FAILURE_INTO(OUTPUT, SITE) \
    do { unsigned long __a64_exclusive_choice = native_lab_exclusive_failure_choice((unsigned int)(SITE)); \
        if (__a64_exclusive_choice > 1) { \
            fputs("native exclusive failure choice must be 0 or 1\n", stderr); \
            exit(1); \
        } \
        (OUTPUT) = __a64_exclusive_choice; \
    } while (0)
#else
#define ARM64_SIM_L_EXCLUSIVE_FAILURE_INTO(OUTPUT, SITE) \
    do { (OUTPUT) = NATIVE_LAB_EXCLUSIVE_FAILURE(SITE); } while (0)
#endif

/* The actual exclusive-store body: rejection precedes the environment query;
 * a failed reservation observes no source or memory, then writes W status. */
#define ARM64_SIM_L_STLXR_STEP(OP, DST, SRC, BASE, AUX, SITE, WIDTH) \
    do { \
        if ((DST) == (SRC) || ((BASE) != ARM64_SP && (DST) == (BASE))) \
            ARM64_SIM_L_UNSUPPORTED_OPCODE(); \
        ARM64_SIM_L_SP_ALIGNMENT(BASE); \
        __u64 __a64_stlxr_failure; \
        ARM64_SIM_L_EXCLUSIVE_FAILURE_INTO(__a64_stlxr_failure, (SITE)); \
        if (!__a64_stlxr_failure) \
            ARM64_SIM_L_MEM_WRITE_REG((BASE), ARM64_REG_NONE, (AUX), 0, 0, (WIDTH), (SRC)); \
        __u64 __a64_stlxr_status; \
        KPROG_ARM64_STLXR_VALUE_INTO(__a64_stlxr_status, (OP), ARM64_WIDTH_32, __a64_stlxr_failure, ARM64_SIM_L_UNSUPPORTED_OPCODE()); \
        ARM64_SIM_L_WRITE_REG_WIDTH((DST), __a64_stlxr_status, ARM64_WIDTH_32); \
    } while (0)

/* The dispatcher and direct path share these complete scalar memory bodies.
 * Fault recovery precedes overlap checks and writeback exactly as before. */
#define ARM64_SIM_L_LOAD_STEP(OP, DST, BASE, INDEX, AUX, IMM, WIDTH) \
    do { \
        int __a64_load_fault; ARM64_SIM_L_READ_FAULT_CALL_INTO(__a64_load_fault, (BASE), (INDEX), (AUX), (IMM)); \
        if (__a64_load_fault) { ARM64_SIM_L_CLEAR_READ_DEST(DST); break; } \
        ARM64_SIM_L_WRITEBACK_OVERLAP((BASE), (DST), (AUX)); \
        ARM64_SIM_L_MEM_PRE((BASE), (AUX), (IMM)); \
        __u64 __a64_load_value; __u8 __a64_load_tag; \
        ARM64_SIM_L_MEM_READ_INTO(__a64_load_value, (BASE), (INDEX), (AUX), (IMM), 0, (WIDTH)); \
        ARM64_SIM_L_MEM_READ_TAG_INTO(__a64_load_tag, (BASE), (INDEX), (AUX), (IMM), 0, (WIDTH)); \
        __u64 __a64_load_preserve; \
        KPROG_ARM64_LOAD_TAG_PRESERVE_INTO(__a64_load_preserve, (OP), __a64_load_tag, (WIDTH), ARM64_SIM_L_UNSUPPORTED_OPCODE()); \
        if (__a64_load_preserve) { \
            __u64 __a64_load_payload; \
            ARM64_SIM_L_MEM_PAYLOAD_INTO(__a64_load_payload, (BASE), (INDEX), (AUX), (IMM), 0, __a64_load_value, __a64_load_tag); \
            ARM64_SIM_L_WRITE_REG_PTR_TAG((DST), (void *)(long)__a64_load_payload, __a64_load_tag); \
        } else ARM64_SIM_L_WRITE_REG_WIDTH((DST), __a64_load_value, (WIDTH)); \
        ARM64_SIM_L_MEM_POST((BASE), (AUX), (IMM)); \
    } while (0)
#define ARM64_SIM_L_LDRSX_STEP(OP, DST, BASE, INDEX, AUX, IMM, WIDTH) \
    do { \
        int __a64_sx_fault; ARM64_SIM_L_READ_FAULT_CALL_INTO(__a64_sx_fault, (BASE), (INDEX), (AUX), (IMM)); \
        if (__a64_sx_fault) { ARM64_SIM_L_CLEAR_READ_DEST(DST); break; } \
        ARM64_SIM_L_WRITEBACK_OVERLAP((BASE), (DST), (AUX)); \
        ARM64_SIM_L_MEM_PRE((BASE), (AUX), (IMM)); \
        __u64 __a64_sx_value, __a64_sx_result, __a64_sx_width, __a64_sx_op; \
        KPROG_ARM64_LDRSX_LOAD_WIDTH_INTO(__a64_sx_width, (OP), ARM64_SIM_L_UNSUPPORTED_OPCODE()); \
        ARM64_SIM_L_MEM_READ_INTO(__a64_sx_value, (BASE), (INDEX), (AUX), (IMM), 0, __a64_sx_width); \
        KPROG_ARM64_LDRSX_SXOP_INTO(__a64_sx_op, (OP), ARM64_SIM_L_UNSUPPORTED_OPCODE()); \
        ARM64_SIM_L_EXTREV_SIGNEXT_INTO(__a64_sx_result, __a64_sx_op, __a64_sx_value, (WIDTH)); \
        ARM64_SIM_L_WRITE_REG_WIDTH((DST), __a64_sx_result, (WIDTH)); \
        ARM64_SIM_L_MEM_POST((BASE), (AUX), (IMM)); \
    } while (0)
#define ARM64_SIM_L_STORE_STEP(BASE, SRC, INDEX, AUX, IMM, WIDTH) \
    do { \
        ARM64_SIM_L_WRITEBACK_OVERLAP((BASE), (SRC), (AUX)); \
        ARM64_SIM_L_MEM_PRE((BASE), (AUX), (IMM)); \
        __u64 __a64_store_value; __u8 __a64_store_tag; __s64 __a64_store_off; \
        ARM64_SIM_L_MEM_BASE_OFF_INTO(__a64_store_off, (AUX), (INDEX), (IMM)); \
        ARM64_SIM_L_READ_REG_INTO(__a64_store_value, (SRC)); \
        ARM64_SIM_L_REG_TAG_INTO(__a64_store_tag, (SRC)); \
        ARM64_SIM_L_MEM_WRITE_AT((BASE), __a64_store_off, (WIDTH), __a64_store_value, __a64_store_tag); \
        ARM64_SIM_L_MEM_POST((BASE), (AUX), (IMM)); \
    } while (0)

#define ARM64_SIM_L_EXEC_ADRP(OP, DST, IMM) \
do { \
    __u8 __a64_adrp_tag; \
    KPROG_ARM64_ADRP_TAG_INTO(__a64_adrp_tag, (OP), ARM64_SIM_L_UNSUPPORTED_OPCODE()); \
    ARM64_SIM_L_WRITE_REG_PTR_TAG((DST), (void *)(long)(IMM), __a64_adrp_tag); \
} while (0)

#define ARM64_SIM_L_EXEC(OP, DST, SRC, SRC2, SRC3, FLAGS, AUX, IMM)         \
	do {                                                               \
		const __u8 __a64_l_width = ARM64_SIM_L_EFFECTIVE_WIDTH(FLAGS);\
		if (KPROG_ARM64_DISP_NOP_HANDLED(OP)) {                    \
			(void)0;                                           \
		} else if (KPROG_ARM64_ADRP_HANDLED(OP)) {                 \
			ARM64_SIM_L_EXEC_ADRP((OP), (DST), (IMM));               \
		} else if (KPROG_ARM64_MOV_HANDLED(OP)) {                  \
			if (ARM64_SIM_L_MOV_PTR_TAG_PATH((OP), __a64_l_width)) {\
				ARM64_SIM_L_WRITE_REG_PTR_TAG((DST),       \
					ARM64_SIM_L_READ_REG_PTR(SRC),     \
					ARM64_SIM_L_REG_TAG(SRC));         \
			} else {                                           \
				ARM64_SIM_L_VALUE(__u64, __a64_l_value, KPROG_ARM64_IMM_RHS, (OP), (IMM),   \
						ARM64_SIM_L_READ_REG(SRC));\
				ARM64_SIM_L_WRITE_REG_WIDTH((DST), __a64_l_value, __a64_l_width);\
			}                                                  \
		} else if (KPROG_ARM64_DISP_MOVK_HANDLED(OP)) {            \
			ARM64_SIM_L_VALUE(__u64, __a64_l_value, ARM64_SIM_L_MOVK_VALUE, (DST), (IMM), ARM64_SIM_L_SHIFT(AUX));\
			ARM64_SIM_L_WRITE_REG_WIDTH((DST), __a64_l_value, __a64_l_width);\
		} else if (KPROG_ARM64_ALU_HANDLED(OP)) {                         \
			ARM64_SIM_L_EXEC_ALU((OP), (DST), (SRC), (SRC2), __a64_l_width, (AUX), (IMM));\
		} else if (KPROG_ARM64_SHIFT_OP_HANDLED(OP)) {                        \
			ARM64_SIM_L_VALUE(__u64, __a64_l_amount, KPROG_ARM64_IMM_RHS, (OP), (IMM),\
				ARM64_SIM_L_READ_REG(SRC2));\
			ARM64_SIM_L_VALUE(__u64, __a64_l_result, ARM64_SIM_L_SHIFT_VALUE, (AUX), ARM64_SIM_L_READ_REG(SRC), __a64_l_amount, __a64_l_width);\
			ARM64_SIM_L_WRITE_REG_WIDTH((DST), __a64_l_result, __a64_l_width);\
		} else if (KPROG_ARM64_MUL_HANDLED(OP)) {                    \
			ARM64_SIM_L_VALUE(__u64, __a64_l_result, ARM64_SIM_L_MUL_VALUE, (OP), (SRC), (SRC2), (SRC3), __a64_l_width);\
			ARM64_SIM_L_WRITE_REG_WIDTH((DST), __a64_l_result, __a64_l_width);\
		} else if (KPROG_ARM64_UNARY_HANDLED(OP)) {                 \
			ARM64_SIM_L_VALUE(__u64, __a64_l_result, KPROG_ARM64_UNARY_VALUE, (OP),                       \
					ARM64_SIM_L_MOD_VALUE((SRC), ARM64_SIM_L_MOD(AUX), \
						ARM64_SIM_L_SHIFT(AUX), __a64_l_width),        \
					__a64_l_width, ARM64_SIM_L_UNSUPPORTED_OPCODE());\
			ARM64_SIM_L_WRITE_REG_WIDTH((DST), __a64_l_result, __a64_l_width);\
		} else if (KPROG_ARM64_CNEG_HANDLED(OP)) {                   \
			ARM64_SIM_L_VALUE(__u64, __a64_l_result, ARM64_SIM_L_CNEG_VALUE, (OP), (SRC),          \
					ARM64_SIM_L_EVAL_COND(AUX), __a64_l_width);\
			ARM64_SIM_L_WRITE_REG_WIDTH((DST), __a64_l_result, __a64_l_width);\
		} else if (KPROG_ARM64_EXTREV_HANDLED(OP)) {                 \
			ARM64_SIM_L_VALUE(__u64, __a64_l_result, ARM64_SIM_L_EXTREV_VALUE, (OP), (SRC), (SRC2), (IMM), __a64_l_width);\
			ARM64_SIM_L_WRITE_REG_WIDTH((DST), __a64_l_result, __a64_l_width);\
		} else if (KPROG_ARM64_DISP_BITFIELD_HANDLED(OP)) {           \
			ARM64_SIM_L_VALUE(__u64, __a64_bf_result, ARM64_SIM_L_BITFIELD_VALUE, (AUX) & 0xffU,    \
					ARM64_SIM_L_READ_REG(SRC),           \
					ARM64_SIM_L_READ_REG(DST),           \
					ARM64_SIM_L_BITFIELD_LSB(AUX),       \
					ARM64_SIM_L_BITFIELD_WIDTH(AUX));    \
			ARM64_SIM_L_WRITE_REG_WIDTH((DST), __a64_bf_result, __a64_l_width);\
		} else if (KPROG_ARM64_SUBS_HANDLED(OP)) {                          \
			__u64 __a64_l_lhs = ARM64_SIM_L_READ_REG(SRC);      \
			ARM64_SIM_L_VALUE(__u64, __a64_l_rhs, KPROG_ARM64_FLAG_RHS, (OP), (IMM),\
				ARM64_SIM_L_MOD_VALUE((SRC2), ARM64_SIM_L_MOD(AUX), ARM64_SIM_L_SHIFT(AUX), __a64_l_width));\
			__u64 __a64_l_result = 0;                         \
			KPROG_ARM64_EXEC_ARITH_WRITEBACK(                 \
				KPROG_ARM64_ARITH_FAMILY_SUB, __a64_l_result,\
				__a64_n, __a64_z, __a64_c, __a64_v,         \
				__a64_l_lhs, __a64_l_rhs, __a64_l_width,    \
				ARM64_SIM_L_UNSUPPORTED_OPCODE());           \
			ARM64_SIM_L_WRITE_REG_WIDTH((DST), __a64_l_result, __a64_l_width);\
		} else if (KPROG_ARM64_ADDS_HANDLED(OP)) {                          \
			__u64 __a64_l_lhs = ARM64_SIM_L_READ_REG(SRC);      \
			ARM64_SIM_L_VALUE(__u64, __a64_l_rhs, KPROG_ARM64_FLAG_RHS, (OP), (IMM),\
				ARM64_SIM_L_MOD_VALUE((SRC2), ARM64_SIM_L_MOD(AUX), ARM64_SIM_L_SHIFT(AUX), __a64_l_width));\
			__u64 __a64_l_result = 0;                         \
			KPROG_ARM64_EXEC_ARITH_WRITEBACK(                 \
				KPROG_ARM64_ARITH_FAMILY_ADD, __a64_l_result,\
				__a64_n, __a64_z, __a64_c, __a64_v,         \
				__a64_l_lhs, __a64_l_rhs, __a64_l_width,    \
				ARM64_SIM_L_UNSUPPORTED_OPCODE());           \
			ARM64_SIM_L_WRITE_REG_WIDTH((DST), __a64_l_result, __a64_l_width);\
		} else if (KPROG_ARM64_DISP_CMN_IMM_HANDLED(OP)) {           \
			__u64 __a64_l_lhs = ARM64_SIM_L_READ_REG(DST);      \
			__u64 __a64_l_rhs = (__u64)(IMM);                   \
			KPROG_ARM64_EXEC_ARITH_COMPARE(                     \
				KPROG_ARM64_ARITH_FAMILY_ADD,                 \
				__a64_n, __a64_z, __a64_c, __a64_v,          \
				__a64_l_lhs, __a64_l_rhs, __a64_l_width,     \
				ARM64_SIM_L_UNSUPPORTED_OPCODE());            \
		} else if (KPROG_ARM64_DISP_CMN_REG_HANDLED(OP)) {           \
			__u64 __a64_l_lhs = ARM64_SIM_L_READ_REG(DST);      \
			__u64 __a64_l_rhs = ARM64_SIM_L_MOD_VALUE((SRC),    \
				ARM64_SIM_L_MOD(AUX), ARM64_SIM_L_SHIFT(AUX), \
				__a64_l_width);                               \
			KPROG_ARM64_EXEC_ARITH_COMPARE(                     \
				KPROG_ARM64_ARITH_FAMILY_ADD,                 \
				__a64_n, __a64_z, __a64_c, __a64_v,          \
				__a64_l_lhs, __a64_l_rhs, __a64_l_width,     \
				ARM64_SIM_L_UNSUPPORTED_OPCODE());            \
		} else if (KPROG_ARM64_CMP_HANDLED(OP)) {                         \
			__u64 __a64_l_lhs = ARM64_SIM_L_READ_REG(DST);      \
			ARM64_SIM_L_VALUE(__u64, __a64_l_rhs, KPROG_ARM64_FLAG_RHS, (OP), (IMM),\
				ARM64_SIM_L_MOD_VALUE((SRC), ARM64_SIM_L_MOD(AUX), ARM64_SIM_L_SHIFT(AUX), __a64_l_width));\
			KPROG_ARM64_EXEC_ARITH_COMPARE(                     \
				KPROG_ARM64_ARITH_FAMILY_SUB,                 \
				__a64_n, __a64_z, __a64_c, __a64_v,          \
				__a64_l_lhs, __a64_l_rhs, __a64_l_width,     \
				ARM64_SIM_L_UNSUPPORTED_OPCODE());            \
		} else if (KPROG_ARM64_TST_HANDLED(OP)) {                         \
			__u64 __a64_l_lhs = ARM64_SIM_L_READ_REG(DST);      \
			ARM64_SIM_L_VALUE(__u64, __a64_l_rhs, KPROG_ARM64_FLAG_RHS, (OP), (IMM),\
				ARM64_SIM_L_MOD_VALUE((SRC), ARM64_SIM_L_MOD(AUX), ARM64_SIM_L_SHIFT(AUX), __a64_l_width));\
			__u64 __a64_l_value = 0;                          \
			KPROG_ARM64_EXEC_LOGIC_FLAGS(                     \
				KPROG_ARM64_LOGIC_FAMILY_AND, __a64_l_value,\
				__a64_n, __a64_z, __a64_c, __a64_v,         \
				__a64_l_lhs, __a64_l_rhs, __a64_l_width,    \
				ARM64_SIM_L_UNSUPPORTED_OPCODE());           \
		} else if (KPROG_ARM64_DISP_TST_BIC_REG_HANDLED(OP)) {     \
			__u64 __a64_l_lhs = ARM64_SIM_L_READ_REG(DST);      \
			__u64 __a64_l_rhs = ARM64_SIM_L_MOD_VALUE((SRC),    \
				ARM64_SIM_L_MOD(AUX), ARM64_SIM_L_SHIFT(AUX), \
				__a64_l_width);                               \
			__u64 __a64_l_value = 0;                          \
			KPROG_ARM64_EXEC_LOGIC_FLAGS(                     \
				KPROG_ARM64_LOGIC_FAMILY_BIC, __a64_l_value,\
				__a64_n, __a64_z, __a64_c, __a64_v,         \
				__a64_l_lhs, __a64_l_rhs, __a64_l_width,    \
				ARM64_SIM_L_UNSUPPORTED_OPCODE());           \
		} else if (KPROG_ARM64_DISP_BICS_REG_HANDLED(OP)) {        \
			__u64 __a64_l_lhs = ARM64_SIM_L_READ_REG(SRC);      \
			__u64 __a64_l_rhs = ARM64_SIM_L_MOD_VALUE((SRC2),   \
				ARM64_SIM_L_MOD(AUX), ARM64_SIM_L_SHIFT(AUX), \
				__a64_l_width);                               \
			__u64 __a64_l_value = 0;                          \
			KPROG_ARM64_EXEC_LOGIC_FLAGS(                     \
				KPROG_ARM64_LOGIC_FAMILY_BIC, __a64_l_value,\
				__a64_n, __a64_z, __a64_c, __a64_v,         \
				__a64_l_lhs, __a64_l_rhs, __a64_l_width,    \
				ARM64_SIM_L_UNSUPPORTED_OPCODE());           \
			ARM64_SIM_L_WRITE_REG_WIDTH((DST), __a64_l_value, __a64_l_width);\
		} else if (KPROG_ARM64_ANDS_HANDLED(OP)) {                          \
			__u64 __a64_l_lhs = ARM64_SIM_L_READ_REG(SRC);      \
			ARM64_SIM_L_VALUE(__u64, __a64_l_rhs, KPROG_ARM64_FLAG_RHS, (OP), (IMM),\
				ARM64_SIM_L_MOD_VALUE((SRC2), ARM64_SIM_L_MOD(AUX), ARM64_SIM_L_SHIFT(AUX), __a64_l_width));\
			__u64 __a64_l_value = 0;                          \
			KPROG_ARM64_EXEC_LOGIC_FLAGS(                     \
				KPROG_ARM64_LOGIC_FAMILY_AND, __a64_l_value,\
				__a64_n, __a64_z, __a64_c, __a64_v,         \
				__a64_l_lhs, __a64_l_rhs, __a64_l_width,    \
				ARM64_SIM_L_UNSUPPORTED_OPCODE());           \
			ARM64_SIM_L_WRITE_REG_WIDTH((DST), __a64_l_value, __a64_l_width);\
		} else if (KPROG_ARM64_ORN_HANDLED(OP)) {                    \
			ARM64_SIM_L_VALUE(__u64, __a64_l_result, ARM64_SIM_L_ORN_VALUE, (OP), ARM64_SIM_L_READ_REG(SRC),\
					ARM64_SIM_L_MOD_VALUE((SRC2), ARM64_SIM_L_MOD(AUX),\
						ARM64_SIM_L_SHIFT(AUX), __a64_l_width),\
					__a64_l_width);                     \
			ARM64_SIM_L_WRITE_REG_WIDTH((DST), __a64_l_result, __a64_l_width);\
		} else if (KPROG_ARM64_CCMP_HANDLED(OP)) {                          \
			__u64 __a64_l_lhs = ARM64_SIM_L_READ_REG(DST);      \
			ARM64_SIM_L_VALUE(__u64, __a64_l_rhs, KPROG_ARM64_FLAG_RHS, (OP), (IMM),\
				ARM64_SIM_L_READ_REG(SRC));                 \
			__u8 __a64_l_cond = ARM64_SIM_L_CCMP_COND(AUX); \
			__u8 __a64_l_nzcv = ARM64_SIM_L_CCMP_NZCV(AUX); \
			KPROG_ARM64_EXEC_CCMP(__a64_l_cond, __a64_l_nzcv,\
				__a64_n, __a64_z, __a64_c, __a64_v,         \
				__a64_l_lhs, __a64_l_rhs, __a64_l_width,    \
				ARM64_SIM_L_UNSUPPORTED_OPCODE());           \
		} else if (KPROG_ARM64_CSEL_HANDLED(OP)) {                   \
			int __a64_l_taken = ARM64_SIM_L_EVAL_COND(AUX) ? 1 : 0;\
			if (KPROG_ARM64_CSEL_PTR_TAG_PATH((OP), __a64_l_width, ARM64_SIM_L_UNSUPPORTED_OPCODE())) {\
				if (__a64_l_taken)                        \
					ARM64_SIM_L_WRITE_REG_PTR_TAG((DST),\
						ARM64_SIM_L_READ_REG_PTR(SRC),\
						ARM64_SIM_L_REG_TAG(SRC));\
				else                                      \
					ARM64_SIM_L_WRITE_REG_PTR_TAG((DST),\
						ARM64_SIM_L_READ_REG_PTR(SRC2),\
						ARM64_SIM_L_REG_TAG(SRC2));\
			} else {                                          \
				ARM64_SIM_L_VALUE(__u64, __a64_l_result, ARM64_SIM_L_CSEL_VALUE, (OP), (SRC), (SRC2), __a64_l_taken);\
				ARM64_SIM_L_WRITE_REG_WIDTH((DST), __a64_l_result, __a64_l_width);\
			}                                                 \
		} else if (KPROG_ARM64_DISP_LOAD_HANDLED(OP)) { \
            ARM64_SIM_L_LOAD_STEP((OP), (DST), (SRC), (SRC2), (AUX), (IMM), __a64_l_width); \
        } else if (KPROG_ARM64_LDRSX_HANDLED(OP)) { \
            ARM64_SIM_L_LDRSX_STEP((OP), (DST), (SRC), (SRC2), (AUX), (IMM), __a64_l_width); \
        } else if (KPROG_ARM64_DISP_STORE_HANDLED(OP)) { \
            ARM64_SIM_L_STORE_STEP((DST), (SRC), (SRC2), (AUX), (IMM), __a64_l_width); \
        } else if ((OP) == ARM64_OP_LDADD) {                         \
			ARM64_SIM_L_ATOMIC_RMW(__atomic_fetch_add, 0, (DST), (SRC), (SRC2), __a64_l_width, (AUX)); \
        } else if ((OP) == ARM64_OP_LDSET) { \
            ARM64_SIM_L_ATOMIC_RMW(__atomic_fetch_or, 0, (DST), (SRC), (SRC2), __a64_l_width, (AUX)); \
        } else if ((OP) == ARM64_OP_LDCLR) { \
            ARM64_SIM_L_ATOMIC_RMW(__atomic_fetch_and, 1, (DST), (SRC), (SRC2), __a64_l_width, (AUX)); \
		} else if (KPROG_ARM64_STLXR_HANDLED(OP)) {                \
            ARM64_SIM_L_STLXR_STEP((OP), (DST), (SRC), (SRC2), (AUX), (IMM), __a64_l_width); \
		} else if (KPROG_ARM64_DISP_LDP_HANDLED(OP)) {                 \
			ARM64_SIM_L_LDP((DST), (SRC), (SRC2), (SRC3),          \
				(AUX), (IMM), __a64_l_width);                  \
		} else if (KPROG_ARM64_DISP_STP_HANDLED(OP)) {                 \
			ARM64_SIM_L_STP((DST), (SRC), (SRC2), (SRC3),          \
				(AUX), (IMM), __a64_l_width);                  \
		} else if (KPROG_ARM64_DISP_LOAD_D0_HANDLED(OP)) {             \
			ARM64_SIM_L_LOAD_D0_MEM((SRC), (SRC2), (AUX), (IMM));  \
		} else if (KPROG_ARM64_DISP_STORE_D0_HANDLED(OP)) {            \
			ARM64_SIM_L_STORE_D0_MEM((DST), (SRC2), (AUX), (IMM)); \
		} else if (KPROG_ARM64_DISP_LOAD_Q0_HANDLED(OP)) {             \
			ARM64_SIM_L_LOAD_Q0_MEM((SRC), (SRC2), (AUX), (IMM));  \
		} else if (KPROG_ARM64_DISP_STORE_Q0_HANDLED(OP)) {            \
			ARM64_SIM_L_STORE_Q0_MEM((DST), (SRC2), (AUX), (IMM)); \
		} else if (KPROG_ARM64_DISP_FMOV_HANDLED(OP)) {                \
			unsigned __a64_fmov_index = (SRC2) == ARM64_REG_NONE ? 0U : (SRC2); \
			if (__a64_fmov_index >= 32U) {                     \
				ARM64_SIM_L_UNSUPPORTED_OPCODE();           \
			} else {                                           \
			ARM64_SIM_L_VALUE(__u64, __a64_fmov_result, KPROG_ARM64_FMOV_VALUE, (AUX), ARM64_SIM_L_VECTOR_LO(__a64_fmov_index), \
					ARM64_SIM_L_READ_REG(SRC),         \
					ARM64_SIM_L_UNSUPPORTED_OPCODE()); \
			if (KPROG_ARM64_FMOV_DEST_VECTOR((AUX),           \
					ARM64_SIM_L_UNSUPPORTED_OPCODE())) { \
				ARM64_SIM_L_VECTOR_LO(__a64_fmov_index) = (AUX) == ARM64_FMOV_S_FROM_W ? \
					(__u32)__a64_fmov_result : __a64_fmov_result; \
				ARM64_SIM_L_VECTOR_HI(__a64_fmov_index) = 0;     \
			}                                                  \
			else                                               \
				ARM64_SIM_L_WRITE_REG_WIDTH((DST),         \
					__a64_fmov_result, __a64_l_width); \
			}                                                  \
		} else if (KPROG_ARM64_REDUCTION_HANDLED(OP)) {                \
			__u64 __a64_red_hi = (AUX) == 16 ?                    \
				ARM64_SIM_L_REDUCTION_VALUE((OP), __a64_v0_hi) : 0; \
			__a64_v0 = ARM64_SIM_L_REDUCTION_VALUE((OP), __a64_v0);\
			if ((OP) == ARM64_OP_CNT)                            \
				__a64_v0_hi = __a64_red_hi;                    \
			else {                                                      \
				__a64_v0 += __a64_red_hi;                      \
				__a64_v0_hi = 0;                              \
			}                                                           \
		} else {                                                       \
			ARM64_SIM_L_UNSUPPORTED_OPCODE();                      \
		}                                                            \
	} while (0)

#define ARM64_SIM_RUN_OP3(OP, DST, SRC, SRC2, SRC3, FLAGS, AUX, IMM)        \
	ARM64_SIM_L_EXEC((OP), (DST), (SRC), (SRC2), (SRC3), (FLAGS), (AUX), (IMM))

#define ARM64_SIM_RUN_OP(OP, DST, SRC, FLAGS, AUX, IMM)                     \
	ARM64_SIM_RUN_OP3((OP), (DST), (SRC), ARM64_REG_NONE, ARM64_REG_NONE, (FLAGS), (AUX), (IMM))

/* Shadow tags describe whole aligned pointer words, never overwritten bytes. */
#define ARM64_SIM_L_MEMORY_TAG_TRANSFER(DST, DTAG, SRC, STAG, LEN, COPY) \
    do { \
        if ((DTAG) == ARM64_SIM_TAG_STACK) { \
            __u64 __a64_mt_dst = ARM64_SIM_L_STACK_INDEX(DST); \
            __u64 __a64_mt_len = (LEN); \
            for (__u64 __a64_mt_i = 0; __a64_mt_i < __a64_mt_len; __a64_mt_i++) { \
                __u64 __a64_mt_at = __a64_mt_dst + __a64_mt_i; \
                if (!__a64_mt_i || !(__a64_mt_at & 7U)) { \
                    __u8 __a64_mt_tag = ARM64_SIM_TAG_SCALAR; \
                    if ((COPY) && (STAG) == ARM64_SIM_TAG_STACK && \
                        (__s64)(SRC)+(__s64)__a64_mt_i>=ARM64_SIM_L_STACK_SP() && \
                        (__s64)(DST)+(__s64)__a64_mt_i>=ARM64_SIM_L_STACK_SP() && \
                        !(__a64_mt_at & 7U) && __a64_mt_len - __a64_mt_i >= 8U) { \
                        __u64 __a64_mt_src = ARM64_SIM_L_STACK_INDEX(SRC) + __a64_mt_i; \
                        if (!(__a64_mt_src & 7U)) { \
                            ARM64_SIM_L_TAG_GET_INTO(__a64_mt_tag, __a64_mt_src >> 3); \
                            if (__a64_mt_tag == ARM64_SIM_TAG_STACK || __a64_mt_tag == ARM64_SIM_TAG_RETURN) \
                                ARM64_SIM_L_STACK_PAYLOAD_STORE(__a64_mt_at >> 3, ARM64_SIM_L_STACK_PAYLOAD_LOAD(__a64_mt_src >> 3)); \
                        } \
                    } \
                    ARM64_SIM_L_TAG_SET(__a64_mt_at >> 3, (__a64_mt_tag)); \
                } \
            } \
        } \
    } while (0)

/* Native libc calls use their actual length; there is no simulator trip cap. */
#define ARM64_SIM_LIBC_MEMSET()                                            \
	do {                                                               \
		__u8 __a64_lib_byte = (__u8)ARM64_SIM_L_READ_REG(ARM64_X1);  \
		__u64 __a64_lib_len = ARM64_SIM_L_READ_REG(ARM64_X2);       \
		for (__u64 __a64_lib_i = 0; __a64_lib_i < __a64_lib_len; __a64_lib_i++) \
			ARM64_SIM_L_MEM_WRITE(ARM64_X0,ARM64_REG_NONE,ARM64_AUX_MEM(ARM64_REG_NONE,ARM64_MOD_NONE,0,0),0,__a64_lib_i,ARM64_WIDTH_8,__a64_lib_byte,ARM64_SIM_TAG_SCALAR);               \
		ARM64_SIM_L_MEMORY_TAG_TRANSFER((__s64)(long)ARM64_SIM_L_READ_REG_PTR(ARM64_X0), ARM64_SIM_L_REG_TAG(ARM64_X0), 0, ARM64_SIM_TAG_SCALAR, __a64_lib_len, 0); \
		ARM64_SIM_L_HELPER_CLOBBERS(); \
	} while (0)

#define ARM64_SIM_LIBC_MEMCPY()                                            \
	do {                                                               \
		__u64 __a64_lib_len = ARM64_SIM_L_READ_REG(ARM64_X2);       \
        __u8 __a64_lib_src_tag;                                           \
        ARM64_SIM_L_REG_TAG_INTO(__a64_lib_src_tag, ARM64_X1);             \
        if (__a64_lib_len && __a64_lib_src_tag == ARM64_SIM_TAG_SCALAR)    \
            ARM64_SIM_L_UNSUPPORTED_OPCODE();                            \
		for (__u64 __a64_lib_i = 0; __a64_lib_i < __a64_lib_len; __a64_lib_i++) \
			ARM64_SIM_L_MEM_WRITE(ARM64_X0,ARM64_REG_NONE,ARM64_AUX_MEM(ARM64_REG_NONE,ARM64_MOD_NONE,0,0),0,__a64_lib_i,ARM64_WIDTH_8, \
                ARM64_SIM_L_MEM_READ(ARM64_X1,ARM64_REG_NONE,ARM64_AUX_MEM(ARM64_REG_NONE,ARM64_MOD_NONE,0,0),0,__a64_lib_i,ARM64_WIDTH_8),ARM64_SIM_TAG_SCALAR); \
		ARM64_SIM_L_MEMORY_TAG_TRANSFER((__s64)(long)ARM64_SIM_L_READ_REG_PTR(ARM64_X0), ARM64_SIM_L_REG_TAG(ARM64_X0), (__s64)(long)ARM64_SIM_L_READ_REG_PTR(ARM64_X1), ARM64_SIM_L_REG_TAG(ARM64_X1), __a64_lib_len, 1); \
		ARM64_SIM_L_HELPER_CLOBBERS(); \
	} while (0)

#define ARM64_SIM_L_HELPER_CLOBBERS() \
    do { ARM64_SIM_L_STACK_RELEASE(-(__s64)ARM64_SIM_STACK_BIAS); \
        __a64_x1.x = ARM64_SIM_L_UNSPECIFIED(); \
        __a64_x1_tag = ARM64_SIM_TAG_SCALAR; \
        __a64_x2.x = ARM64_SIM_L_UNSPECIFIED(); \
        __a64_x2_tag = ARM64_SIM_TAG_SCALAR; \
        __a64_x3.x = ARM64_SIM_L_UNSPECIFIED(); \
        __a64_x3_tag = ARM64_SIM_TAG_SCALAR; \
        __a64_x4.x = ARM64_SIM_L_UNSPECIFIED(); \
        __a64_x4_tag = ARM64_SIM_TAG_SCALAR; \
        __a64_x5.x = ARM64_SIM_L_UNSPECIFIED(); \
        __a64_x5_tag = ARM64_SIM_TAG_SCALAR; \
        __a64_x6.x = ARM64_SIM_L_UNSPECIFIED(); \
        __a64_x6_tag = ARM64_SIM_TAG_SCALAR; \
        __a64_x7.x = ARM64_SIM_L_UNSPECIFIED(); \
        __a64_x7_tag = ARM64_SIM_TAG_SCALAR; \
        __a64_x8.x = ARM64_SIM_L_UNSPECIFIED(); \
        __a64_x8_tag = ARM64_SIM_TAG_SCALAR; \
        __a64_x9.x = ARM64_SIM_L_UNSPECIFIED(); \
        __a64_x9_tag = ARM64_SIM_TAG_SCALAR; \
        __a64_x10.x = ARM64_SIM_L_UNSPECIFIED(); \
        __a64_x10_tag = ARM64_SIM_TAG_SCALAR; \
        __a64_x11.x = ARM64_SIM_L_UNSPECIFIED(); \
        __a64_x11_tag = ARM64_SIM_TAG_SCALAR; \
        __a64_x12.x = ARM64_SIM_L_UNSPECIFIED(); \
        __a64_x12_tag = ARM64_SIM_TAG_SCALAR; \
        __a64_x13.x = ARM64_SIM_L_UNSPECIFIED(); \
        __a64_x13_tag = ARM64_SIM_TAG_SCALAR; \
        __a64_x14.x = ARM64_SIM_L_UNSPECIFIED(); \
        __a64_x14_tag = ARM64_SIM_TAG_SCALAR; \
        __a64_x15.x = ARM64_SIM_L_UNSPECIFIED(); \
        __a64_x15_tag = ARM64_SIM_TAG_SCALAR; \
        __a64_x16.x = ARM64_SIM_L_UNSPECIFIED(); \
        __a64_x16_tag = ARM64_SIM_TAG_SCALAR; \
        __a64_x17.x = ARM64_SIM_L_UNSPECIFIED(); \
        __a64_x17_tag = ARM64_SIM_TAG_SCALAR; \
        __a64_x18.x = ARM64_SIM_L_UNSPECIFIED(); \
        __a64_x18_tag = ARM64_SIM_TAG_SCALAR; \
        __a64_n = ARM64_SIM_L_UNSPECIFIED() & 1; \
        __a64_z = ARM64_SIM_L_UNSPECIFIED() & 1; \
        __a64_c = ARM64_SIM_L_UNSPECIFIED() & 1; \
        __a64_v = ARM64_SIM_L_UNSPECIFIED() & 1; \
        ARM64_SIM_L_VECTOR_LO(0) = ARM64_SIM_L_UNSPECIFIED(); \
        ARM64_SIM_L_VECTOR_HI(0) = ARM64_SIM_L_UNSPECIFIED(); \
        ARM64_SIM_L_VECTOR_LO(1) = ARM64_SIM_L_UNSPECIFIED(); \
        ARM64_SIM_L_VECTOR_HI(1) = ARM64_SIM_L_UNSPECIFIED(); \
        ARM64_SIM_L_VECTOR_LO(2) = ARM64_SIM_L_UNSPECIFIED(); \
        ARM64_SIM_L_VECTOR_HI(2) = ARM64_SIM_L_UNSPECIFIED(); \
        ARM64_SIM_L_VECTOR_LO(3) = ARM64_SIM_L_UNSPECIFIED(); \
        ARM64_SIM_L_VECTOR_HI(3) = ARM64_SIM_L_UNSPECIFIED(); \
        ARM64_SIM_L_VECTOR_LO(4) = ARM64_SIM_L_UNSPECIFIED(); \
        ARM64_SIM_L_VECTOR_HI(4) = ARM64_SIM_L_UNSPECIFIED(); \
        ARM64_SIM_L_VECTOR_LO(5) = ARM64_SIM_L_UNSPECIFIED(); \
        ARM64_SIM_L_VECTOR_HI(5) = ARM64_SIM_L_UNSPECIFIED(); \
        ARM64_SIM_L_VECTOR_LO(6) = ARM64_SIM_L_UNSPECIFIED(); \
        ARM64_SIM_L_VECTOR_HI(6) = ARM64_SIM_L_UNSPECIFIED(); \
        ARM64_SIM_L_VECTOR_LO(7) = ARM64_SIM_L_UNSPECIFIED(); \
        ARM64_SIM_L_VECTOR_HI(7) = ARM64_SIM_L_UNSPECIFIED(); \
        ARM64_SIM_L_VECTOR_LO(8) = ARM64_SIM_L_UNSPECIFIED(); \
        ARM64_SIM_L_VECTOR_HI(8) = ARM64_SIM_L_UNSPECIFIED(); \
        ARM64_SIM_L_VECTOR_LO(9) = ARM64_SIM_L_UNSPECIFIED(); \
        ARM64_SIM_L_VECTOR_HI(9) = ARM64_SIM_L_UNSPECIFIED(); \
        ARM64_SIM_L_VECTOR_LO(10) = ARM64_SIM_L_UNSPECIFIED(); \
        ARM64_SIM_L_VECTOR_HI(10) = ARM64_SIM_L_UNSPECIFIED(); \
        ARM64_SIM_L_VECTOR_LO(11) = ARM64_SIM_L_UNSPECIFIED(); \
        ARM64_SIM_L_VECTOR_HI(11) = ARM64_SIM_L_UNSPECIFIED(); \
        ARM64_SIM_L_VECTOR_LO(12) = ARM64_SIM_L_UNSPECIFIED(); \
        ARM64_SIM_L_VECTOR_HI(12) = ARM64_SIM_L_UNSPECIFIED(); \
        ARM64_SIM_L_VECTOR_LO(13) = ARM64_SIM_L_UNSPECIFIED(); \
        ARM64_SIM_L_VECTOR_HI(13) = ARM64_SIM_L_UNSPECIFIED(); \
        ARM64_SIM_L_VECTOR_LO(14) = ARM64_SIM_L_UNSPECIFIED(); \
        ARM64_SIM_L_VECTOR_HI(14) = ARM64_SIM_L_UNSPECIFIED(); \
        ARM64_SIM_L_VECTOR_LO(15) = ARM64_SIM_L_UNSPECIFIED(); \
        ARM64_SIM_L_VECTOR_HI(15) = ARM64_SIM_L_UNSPECIFIED(); \
        ARM64_SIM_L_VECTOR_LO(16) = ARM64_SIM_L_UNSPECIFIED(); \
        ARM64_SIM_L_VECTOR_HI(16) = ARM64_SIM_L_UNSPECIFIED(); \
        ARM64_SIM_L_VECTOR_LO(17) = ARM64_SIM_L_UNSPECIFIED(); \
        ARM64_SIM_L_VECTOR_HI(17) = ARM64_SIM_L_UNSPECIFIED(); \
        ARM64_SIM_L_VECTOR_LO(18) = ARM64_SIM_L_UNSPECIFIED(); \
        ARM64_SIM_L_VECTOR_HI(18) = ARM64_SIM_L_UNSPECIFIED(); \
        ARM64_SIM_L_VECTOR_LO(19) = ARM64_SIM_L_UNSPECIFIED(); \
        ARM64_SIM_L_VECTOR_HI(19) = ARM64_SIM_L_UNSPECIFIED(); \
        ARM64_SIM_L_VECTOR_LO(20) = ARM64_SIM_L_UNSPECIFIED(); \
        ARM64_SIM_L_VECTOR_HI(20) = ARM64_SIM_L_UNSPECIFIED(); \
        ARM64_SIM_L_VECTOR_LO(21) = ARM64_SIM_L_UNSPECIFIED(); \
        ARM64_SIM_L_VECTOR_HI(21) = ARM64_SIM_L_UNSPECIFIED(); \
        ARM64_SIM_L_VECTOR_LO(22) = ARM64_SIM_L_UNSPECIFIED(); \
        ARM64_SIM_L_VECTOR_HI(22) = ARM64_SIM_L_UNSPECIFIED(); \
        ARM64_SIM_L_VECTOR_LO(23) = ARM64_SIM_L_UNSPECIFIED(); \
        ARM64_SIM_L_VECTOR_HI(23) = ARM64_SIM_L_UNSPECIFIED(); \
        ARM64_SIM_L_VECTOR_LO(24) = ARM64_SIM_L_UNSPECIFIED(); \
        ARM64_SIM_L_VECTOR_HI(24) = ARM64_SIM_L_UNSPECIFIED(); \
        ARM64_SIM_L_VECTOR_LO(25) = ARM64_SIM_L_UNSPECIFIED(); \
        ARM64_SIM_L_VECTOR_HI(25) = ARM64_SIM_L_UNSPECIFIED(); \
        ARM64_SIM_L_VECTOR_LO(26) = ARM64_SIM_L_UNSPECIFIED(); \
        ARM64_SIM_L_VECTOR_HI(26) = ARM64_SIM_L_UNSPECIFIED(); \
        ARM64_SIM_L_VECTOR_LO(27) = ARM64_SIM_L_UNSPECIFIED(); \
        ARM64_SIM_L_VECTOR_HI(27) = ARM64_SIM_L_UNSPECIFIED(); \
        ARM64_SIM_L_VECTOR_LO(28) = ARM64_SIM_L_UNSPECIFIED(); \
        ARM64_SIM_L_VECTOR_HI(28) = ARM64_SIM_L_UNSPECIFIED(); \
        ARM64_SIM_L_VECTOR_LO(29) = ARM64_SIM_L_UNSPECIFIED(); \
        ARM64_SIM_L_VECTOR_HI(29) = ARM64_SIM_L_UNSPECIFIED(); \
        ARM64_SIM_L_VECTOR_LO(30) = ARM64_SIM_L_UNSPECIFIED(); \
        ARM64_SIM_L_VECTOR_HI(30) = ARM64_SIM_L_UNSPECIFIED(); \
        ARM64_SIM_L_VECTOR_LO(31) = ARM64_SIM_L_UNSPECIFIED(); \
        ARM64_SIM_L_VECTOR_HI(31) = ARM64_SIM_L_UNSPECIFIED(); \
    } while (0)

#define ARM64_SIM_L_HELPER_SCALAR_RESULT(EXPR) \
    do { \
        __u64 __a64_helper_result = (__u64)(EXPR); \
        ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X0, __a64_helper_result, ARM64_WIDTH_64); \
        ARM64_SIM_L_HELPER_CLOBBERS(); \
    } while (0)

#define ARM64_SIM_L_HELPER_POINTER_RESULT(EXPR) \
    do { \
        void *__a64_helper_result = (void *)(EXPR); \
        ARM64_SIM_L_WRITE_REG_PTR_TAG(ARM64_X0, __a64_helper_result, ARM64_SIM_TAG_MAP_VALUE); \
        ARM64_SIM_L_HELPER_CLOBBERS(); \
    } while (0)

/* Void BPF helpers return architectural zero after the actual call. */
#if defined(__COMPCERT__)
#define ARM64_SIM_L_HELPER_VOID_RESULT(EXPR) \
    do { (EXPR); ARM64_SIM_L_HELPER_SCALAR_RESULT(0ULL); } while (0)
#else
#define ARM64_SIM_L_HELPER_VOID_RESULT(EXPR) \
    ARM64_SIM_L_HELPER_SCALAR_RESULT(({ EXPR; 0ULL; }))
#endif

/* Void kfuncs preserve the kernel operation and leave the ABI result unspecified. */
#define ARM64_SIM_KFUNC_VOID_CALL(FUNCTION) \
    do { \
        FUNCTION(); \
        ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X0, ARM64_SIM_L_UNSPECIFIED(), ARM64_WIDTH_64); \
        ARM64_SIM_L_HELPER_CLOBBERS(); \
    } while (0)

#define ARM64_SIM_BPF_CALL_bpf_map_lookup_elem() \
	ARM64_SIM_L_HELPER_POINTER_RESULT(bpf_map_lookup_elem((void *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X0), (const void *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X1)))

#define ARM64_SIM_BPF_CALL_bpf_map_update_elem() \
	ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_map_update_elem((void *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X0), (const void *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X1), (const void *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X2), (__u64)ARM64_SIM_L_READ_REG(ARM64_X3)))

#define ARM64_SIM_BPF_CALL_bpf_map_delete_elem() \
	ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_map_delete_elem((void *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X0), (const void *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X1)))

#define ARM64_SIM_BPF_CALL_bpf_probe_read() \
	do { __s64 __a64_hw_dst = (__s64)(long)ARM64_SIM_L_READ_REG_PTR(ARM64_X0); __u8 __a64_hw_dtag = ARM64_SIM_L_REG_TAG(ARM64_X0); __u32 __a64_hw_len = (__u32)ARM64_SIM_L_READ_REG(ARM64_X1); __s64 __a64_hw_src = (__s64)(long)ARM64_SIM_L_READ_REG_PTR(ARM64_X2); __u8 __a64_hw_stag = ARM64_SIM_L_REG_TAG(ARM64_X2); ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_probe_read((void *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X0), (__u32)ARM64_SIM_L_READ_REG(ARM64_X1), (const void *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X2))); ARM64_SIM_L_MEMORY_TAG_TRANSFER(__a64_hw_dst, __a64_hw_dtag, __a64_hw_src, __a64_hw_stag, __a64_hw_len, (ARM64_SIM_L_READ_REG(ARM64_X0) == 0)); } while (0)

#define ARM64_SIM_BPF_CALL_bpf_ktime_get_ns() \
	ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_ktime_get_ns())

#define ARM64_SIM_BPF_CALL_bpf_trace_printk() \
	ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_trace_printk((const char *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X0), (__u32)ARM64_SIM_L_READ_REG(ARM64_X1), ARM64_SIM_L_READ_REG(ARM64_X2), ARM64_SIM_L_READ_REG(ARM64_X3), ARM64_SIM_L_READ_REG(ARM64_X4)))

#define ARM64_SIM_BPF_CALL_bpf_get_prandom_u32() \
	ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_get_prandom_u32())

#define ARM64_SIM_BPF_CALL_bpf_get_smp_processor_id() \
	ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_get_smp_processor_id())

#define ARM64_SIM_BPF_CALL_bpf_skb_store_bytes() \
	ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_skb_store_bytes((struct __sk_buff *)ARM64_SIM_L_HELPER_CTX_PTR(ARM64_X0), (__u32)ARM64_SIM_L_READ_REG(ARM64_X1), (const void *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X2), (__u32)ARM64_SIM_L_READ_REG(ARM64_X3), (__u64)ARM64_SIM_L_READ_REG(ARM64_X4)))

#define ARM64_SIM_BPF_CALL_bpf_l3_csum_replace() \
	ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_l3_csum_replace((struct __sk_buff *)ARM64_SIM_L_HELPER_CTX_PTR(ARM64_X0), (__u32)ARM64_SIM_L_READ_REG(ARM64_X1), (__u64)ARM64_SIM_L_READ_REG(ARM64_X2), (__u64)ARM64_SIM_L_READ_REG(ARM64_X3), (__u64)ARM64_SIM_L_READ_REG(ARM64_X4)))

#define ARM64_SIM_BPF_CALL_bpf_l4_csum_replace() \
	ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_l4_csum_replace((struct __sk_buff *)ARM64_SIM_L_HELPER_CTX_PTR(ARM64_X0), (__u32)ARM64_SIM_L_READ_REG(ARM64_X1), (__u64)ARM64_SIM_L_READ_REG(ARM64_X2), (__u64)ARM64_SIM_L_READ_REG(ARM64_X3), (__u64)ARM64_SIM_L_READ_REG(ARM64_X4)))

#define ARM64_SIM_BPF_CALL_bpf_tail_call() \
	ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_tail_call((void *)ARM64_SIM_L_HELPER_CTX_PTR(ARM64_X0), (void *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X1), (__u32)ARM64_SIM_L_READ_REG(ARM64_X2)))

#define ARM64_SIM_BPF_CALL_bpf_clone_redirect() \
	ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_clone_redirect((struct __sk_buff *)ARM64_SIM_L_HELPER_CTX_PTR(ARM64_X0), (__u32)ARM64_SIM_L_READ_REG(ARM64_X1), (__u64)ARM64_SIM_L_READ_REG(ARM64_X2)))

#define ARM64_SIM_BPF_CALL_bpf_get_current_pid_tgid() \
	ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_get_current_pid_tgid())

#define ARM64_SIM_BPF_CALL_bpf_get_current_uid_gid() \
	ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_get_current_uid_gid())

#define ARM64_SIM_BPF_CALL_bpf_get_current_comm() \
	do { __s64 __a64_hw_dst = (__s64)(long)ARM64_SIM_L_READ_REG_PTR(ARM64_X0); __u8 __a64_hw_dtag = ARM64_SIM_L_REG_TAG(ARM64_X0); __u32 __a64_hw_len = (__u32)ARM64_SIM_L_READ_REG(ARM64_X1); ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_get_current_comm((void *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X0), (__u32)ARM64_SIM_L_READ_REG(ARM64_X1))); ARM64_SIM_L_MEMORY_TAG_TRANSFER(__a64_hw_dst, __a64_hw_dtag, 0, ARM64_SIM_TAG_SCALAR, __a64_hw_len, 0); } while (0)

#define ARM64_SIM_BPF_CALL_bpf_skb_get_tunnel_key() \
	ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_skb_get_tunnel_key((struct __sk_buff *)ARM64_SIM_L_HELPER_CTX_PTR(ARM64_X0), (struct bpf_tunnel_key *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X1), (__u32)ARM64_SIM_L_READ_REG(ARM64_X2), (__u64)ARM64_SIM_L_READ_REG(ARM64_X3)))

#define ARM64_SIM_BPF_CALL_bpf_skb_set_tunnel_key() \
	ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_skb_set_tunnel_key((struct __sk_buff *)ARM64_SIM_L_HELPER_CTX_PTR(ARM64_X0), (struct bpf_tunnel_key *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X1), (__u32)ARM64_SIM_L_READ_REG(ARM64_X2), (__u64)ARM64_SIM_L_READ_REG(ARM64_X3)))

#define ARM64_SIM_BPF_CALL_bpf_redirect() \
	ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_redirect((__u32)ARM64_SIM_L_READ_REG(ARM64_X0), (__u64)ARM64_SIM_L_READ_REG(ARM64_X1)))

#define ARM64_SIM_BPF_CALL_bpf_perf_event_output() \
	ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_perf_event_output((void *)ARM64_SIM_L_HELPER_CTX_PTR(ARM64_X0), (void *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X1), (__u64)ARM64_SIM_L_READ_REG(ARM64_X2), (void *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X3), (__u64)ARM64_SIM_L_READ_REG(ARM64_X4)))

#define ARM64_SIM_BPF_CALL_bpf_skb_load_bytes() \
	do { __s64 __a64_hw_dst = (__s64)(long)ARM64_SIM_L_READ_REG_PTR(ARM64_X2); __u8 __a64_hw_dtag = ARM64_SIM_L_REG_TAG(ARM64_X2); __u32 __a64_hw_len = (__u32)ARM64_SIM_L_READ_REG(ARM64_X3); ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_skb_load_bytes((const void *)ARM64_SIM_L_HELPER_CTX_PTR(ARM64_X0), (__u32)ARM64_SIM_L_READ_REG(ARM64_X1), (void *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X2), (__u32)ARM64_SIM_L_READ_REG(ARM64_X3))); ARM64_SIM_L_MEMORY_TAG_TRANSFER(__a64_hw_dst, __a64_hw_dtag, 0, ARM64_SIM_TAG_SCALAR, __a64_hw_len, 0); } while (0)

#define ARM64_SIM_BPF_CALL_bpf_get_stackid() \
	ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_get_stackid((void *)ARM64_SIM_L_HELPER_CTX_PTR(ARM64_X0), (void *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X1), (__u64)ARM64_SIM_L_READ_REG(ARM64_X2)))

#define ARM64_SIM_BPF_CALL_bpf_csum_diff() \
	ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_csum_diff((__be32 *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X0), (__u32)ARM64_SIM_L_READ_REG(ARM64_X1), (__be32 *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X2), (__u32)ARM64_SIM_L_READ_REG(ARM64_X3), (__wsum)ARM64_SIM_L_READ_REG(ARM64_X4)))

#define ARM64_SIM_BPF_CALL_bpf_skb_change_proto() \
	ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_skb_change_proto((struct __sk_buff *)ARM64_SIM_L_HELPER_CTX_PTR(ARM64_X0), (__be16)ARM64_SIM_L_READ_REG(ARM64_X1), (__u64)ARM64_SIM_L_READ_REG(ARM64_X2)))

#define ARM64_SIM_BPF_CALL_bpf_skb_change_type() \
	ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_skb_change_type((struct __sk_buff *)ARM64_SIM_L_HELPER_CTX_PTR(ARM64_X0), (__u32)ARM64_SIM_L_READ_REG(ARM64_X1)))

#define ARM64_SIM_BPF_CALL_bpf_skb_under_cgroup() \
	ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_skb_under_cgroup((struct __sk_buff *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X0), (void *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X1), (__u32)ARM64_SIM_L_READ_REG(ARM64_X2)))

#define ARM64_SIM_BPF_CALL_bpf_get_current_task() \
	ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_get_current_task())

#define ARM64_SIM_BPF_CALL_bpf_probe_write_user() \
	ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_probe_write_user((void *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X0), (const void *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X1), (__u32)ARM64_SIM_L_READ_REG(ARM64_X2)))

#define ARM64_SIM_BPF_CALL_bpf_current_task_under_cgroup() \
	ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_current_task_under_cgroup((void *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X0), (__u32)ARM64_SIM_L_READ_REG(ARM64_X1)))

#define ARM64_SIM_BPF_CALL_bpf_skb_change_tail() \
	ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_skb_change_tail((struct __sk_buff *)ARM64_SIM_L_HELPER_CTX_PTR(ARM64_X0), (__u32)ARM64_SIM_L_READ_REG(ARM64_X1), (__u64)ARM64_SIM_L_READ_REG(ARM64_X2)))

#define ARM64_SIM_BPF_CALL_bpf_skb_pull_data() \
	ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_skb_pull_data((struct __sk_buff *)ARM64_SIM_L_HELPER_CTX_PTR(ARM64_X0), (__u32)ARM64_SIM_L_READ_REG(ARM64_X1)))

#define ARM64_SIM_BPF_CALL_bpf_skb_change_head() \
	ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_skb_change_head((struct __sk_buff *)ARM64_SIM_L_HELPER_CTX_PTR(ARM64_X0), (__u32)ARM64_SIM_L_READ_REG(ARM64_X1), (__u64)ARM64_SIM_L_READ_REG(ARM64_X2)))

#define ARM64_SIM_BPF_CALL_bpf_xdp_adjust_head() \
	do { \
	ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_xdp_adjust_head((struct xdp_md *)ARM64_SIM_L_HELPER_CTX_PTR(ARM64_X0), (int)ARM64_SIM_L_READ_REG(ARM64_X1))); \
		ARM64_SIM_L_REFRESH_XDP_CONTEXT(); \
	} while (0)

#define ARM64_SIM_BPF_CALL_bpf_probe_read_str() \
	do { __s64 __a64_hw_dst = (__s64)(long)ARM64_SIM_L_READ_REG_PTR(ARM64_X0); __u8 __a64_hw_dtag = ARM64_SIM_L_REG_TAG(ARM64_X0); __u32 __a64_hw_len = (__u32)ARM64_SIM_L_READ_REG(ARM64_X1); ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_probe_read_str((void *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X0), (__u32)ARM64_SIM_L_READ_REG(ARM64_X1), (const void *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X2))); ARM64_SIM_L_MEMORY_TAG_TRANSFER(__a64_hw_dst, __a64_hw_dtag, 0, ARM64_SIM_TAG_SCALAR, __a64_hw_len, 0); } while (0)

#define ARM64_SIM_BPF_CALL_bpf_get_socket_cookie() \
	ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_get_socket_cookie((void *)ARM64_SIM_L_HELPER_CTX_PTR(ARM64_X0)))

#define ARM64_SIM_BPF_CALL_bpf_skb_adjust_room() \
	ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_skb_adjust_room((struct __sk_buff *)ARM64_SIM_L_HELPER_CTX_PTR(ARM64_X0), (__s32)ARM64_SIM_L_READ_REG(ARM64_X1), (__u32)ARM64_SIM_L_READ_REG(ARM64_X2), (__u64)ARM64_SIM_L_READ_REG(ARM64_X3)))

#define ARM64_SIM_BPF_CALL_bpf_xdp_adjust_meta() \
	do { \
	ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_xdp_adjust_meta((struct xdp_md *)ARM64_SIM_L_HELPER_CTX_PTR(ARM64_X0), (int)ARM64_SIM_L_READ_REG(ARM64_X1))); \
		ARM64_SIM_L_REFRESH_XDP_CONTEXT(); \
	} while (0)

#define ARM64_SIM_BPF_CALL_bpf_override_return() \
	ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_override_return((struct pt_regs *)ARM64_SIM_L_HELPER_CTX_PTR(ARM64_X0), (__u64)ARM64_SIM_L_READ_REG(ARM64_X1)))

#define ARM64_SIM_BPF_CALL_bpf_xdp_adjust_tail() \
	do { \
	ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_xdp_adjust_tail((struct xdp_md *)ARM64_SIM_L_HELPER_CTX_PTR(ARM64_X0), (int)ARM64_SIM_L_READ_REG(ARM64_X1))); \
		ARM64_SIM_L_REFRESH_XDP_CONTEXT(); \
	} while (0)

#define ARM64_SIM_BPF_CALL_bpf_get_stack() \
	do { __s64 __a64_hw_dst = (__s64)(long)ARM64_SIM_L_READ_REG_PTR(ARM64_X1); __u8 __a64_hw_dtag = ARM64_SIM_L_REG_TAG(ARM64_X1); __u32 __a64_hw_len = (__u32)ARM64_SIM_L_READ_REG(ARM64_X2); ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_get_stack((void *)ARM64_SIM_L_HELPER_CTX_PTR(ARM64_X0), (void *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X1), (__u32)ARM64_SIM_L_READ_REG(ARM64_X2), (__u64)ARM64_SIM_L_READ_REG(ARM64_X3))); ARM64_SIM_L_MEMORY_TAG_TRANSFER(__a64_hw_dst, __a64_hw_dtag, 0, ARM64_SIM_TAG_SCALAR, __a64_hw_len, 0); } while (0)

#define ARM64_SIM_BPF_CALL_bpf_skb_load_bytes_relative() \
	do { __s64 __a64_hw_dst = (__s64)(long)ARM64_SIM_L_READ_REG_PTR(ARM64_X2); __u8 __a64_hw_dtag = ARM64_SIM_L_REG_TAG(ARM64_X2); __u32 __a64_hw_len = (__u32)ARM64_SIM_L_READ_REG(ARM64_X3); ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_skb_load_bytes_relative((const void *)ARM64_SIM_L_HELPER_CTX_PTR(ARM64_X0), (__u32)ARM64_SIM_L_READ_REG(ARM64_X1), (void *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X2), (__u32)ARM64_SIM_L_READ_REG(ARM64_X3), (__u32)ARM64_SIM_L_READ_REG(ARM64_X4))); ARM64_SIM_L_MEMORY_TAG_TRANSFER(__a64_hw_dst, __a64_hw_dtag, 0, ARM64_SIM_TAG_SCALAR, __a64_hw_len, 0); } while (0)

#define ARM64_SIM_BPF_CALL_bpf_fib_lookup() \
	ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_fib_lookup((void *)ARM64_SIM_L_HELPER_CTX_PTR(ARM64_X0), (struct bpf_fib_lookup *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X1), (int)ARM64_SIM_L_READ_REG(ARM64_X2), (__u32)ARM64_SIM_L_READ_REG(ARM64_X3)))

#define ARM64_SIM_BPF_CALL_bpf_get_current_cgroup_id() \
	ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_get_current_cgroup_id())

#define ARM64_SIM_BPF_CALL_bpf_sk_lookup_udp() \
	ARM64_SIM_L_HELPER_POINTER_RESULT(bpf_sk_lookup_udp((void *)ARM64_SIM_L_HELPER_CTX_PTR(ARM64_X0), (struct bpf_sock_tuple *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X1), (__u32)ARM64_SIM_L_READ_REG(ARM64_X2), (__u64)ARM64_SIM_L_READ_REG(ARM64_X3), (__u64)ARM64_SIM_L_READ_REG(ARM64_X4)))

#define ARM64_SIM_BPF_CALL_bpf_sk_release() \
	ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_sk_release((void *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X0)))

#define ARM64_SIM_BPF_CALL_bpf_map_push_elem() \
	ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_map_push_elem((void *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X0), (const void *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X1), (__u64)ARM64_SIM_L_READ_REG(ARM64_X2)))

#define ARM64_SIM_BPF_CALL_bpf_map_pop_elem() \
	ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_map_pop_elem((void *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X0), (void *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X1)))

#define ARM64_SIM_BPF_CALL_bpf_sk_fullsock() \
	ARM64_SIM_L_HELPER_POINTER_RESULT(bpf_sk_fullsock((struct bpf_sock *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X0)))

#define ARM64_SIM_BPF_CALL_bpf_skc_lookup_tcp() \
	ARM64_SIM_L_HELPER_POINTER_RESULT(bpf_skc_lookup_tcp((void *)ARM64_SIM_L_HELPER_CTX_PTR(ARM64_X0), (struct bpf_sock_tuple *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X1), (__u32)ARM64_SIM_L_READ_REG(ARM64_X2), (__u64)ARM64_SIM_L_READ_REG(ARM64_X3), (__u64)ARM64_SIM_L_READ_REG(ARM64_X4)))

#define ARM64_SIM_BPF_CALL_bpf_strtol() \
    do { __s64 __a64_hw_dst = (__s64)(long)ARM64_SIM_L_READ_REG_PTR(ARM64_X3); __u8 __a64_hw_dtag = ARM64_SIM_L_REG_TAG(ARM64_X3); ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_strtol((const char *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X0), (unsigned long)ARM64_SIM_L_READ_REG(ARM64_X1), (__u64)ARM64_SIM_L_READ_REG(ARM64_X2), (long *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X3))); ARM64_SIM_L_MEMORY_TAG_TRANSFER(__a64_hw_dst, __a64_hw_dtag, 0, ARM64_SIM_TAG_SCALAR, sizeof(long), 0); } while (0)

#define ARM64_SIM_BPF_CALL_bpf_send_signal() \
	ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_send_signal((__u32)ARM64_SIM_L_READ_REG(ARM64_X0)))

#define ARM64_SIM_BPF_CALL_bpf_probe_read_user() \
	do { __s64 __a64_hw_dst = (__s64)(long)ARM64_SIM_L_READ_REG_PTR(ARM64_X0); __u8 __a64_hw_dtag = ARM64_SIM_L_REG_TAG(ARM64_X0); __u32 __a64_hw_len = (__u32)ARM64_SIM_L_READ_REG(ARM64_X1); __s64 __a64_hw_src = (__s64)(long)ARM64_SIM_L_READ_REG_PTR(ARM64_X2); __u8 __a64_hw_stag = ARM64_SIM_L_REG_TAG(ARM64_X2); ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_probe_read_user((void *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X0), (__u32)ARM64_SIM_L_READ_REG(ARM64_X1), (const void *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X2))); ARM64_SIM_L_MEMORY_TAG_TRANSFER(__a64_hw_dst, __a64_hw_dtag, __a64_hw_src, __a64_hw_stag, __a64_hw_len, (ARM64_SIM_L_READ_REG(ARM64_X0) == 0)); } while (0)

#define ARM64_SIM_BPF_CALL_bpf_probe_read_kernel() \
	do { __s64 __a64_hw_dst = (__s64)(long)ARM64_SIM_L_READ_REG_PTR(ARM64_X0); __u8 __a64_hw_dtag = ARM64_SIM_L_REG_TAG(ARM64_X0); __u32 __a64_hw_len = (__u32)ARM64_SIM_L_READ_REG(ARM64_X1); __s64 __a64_hw_src = (__s64)(long)ARM64_SIM_L_READ_REG_PTR(ARM64_X2); __u8 __a64_hw_stag = ARM64_SIM_L_REG_TAG(ARM64_X2); ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_probe_read_kernel((void *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X0), (__u32)ARM64_SIM_L_READ_REG(ARM64_X1), (const void *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X2))); ARM64_SIM_L_MEMORY_TAG_TRANSFER(__a64_hw_dst, __a64_hw_dtag, __a64_hw_src, __a64_hw_stag, __a64_hw_len, (ARM64_SIM_L_READ_REG(ARM64_X0) == 0)); } while (0)

#define ARM64_SIM_BPF_CALL_bpf_probe_read_user_str() \
	do { __s64 __a64_hw_dst = (__s64)(long)ARM64_SIM_L_READ_REG_PTR(ARM64_X0); __u8 __a64_hw_dtag = ARM64_SIM_L_REG_TAG(ARM64_X0); __u32 __a64_hw_len = (__u32)ARM64_SIM_L_READ_REG(ARM64_X1); ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_probe_read_user_str((void *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X0), (__u32)ARM64_SIM_L_READ_REG(ARM64_X1), (const void *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X2))); ARM64_SIM_L_MEMORY_TAG_TRANSFER(__a64_hw_dst, __a64_hw_dtag, 0, ARM64_SIM_TAG_SCALAR, __a64_hw_len, 0); } while (0)

#define ARM64_SIM_BPF_CALL_bpf_probe_read_kernel_str() \
	do { __s64 __a64_hw_dst = (__s64)(long)ARM64_SIM_L_READ_REG_PTR(ARM64_X0); __u8 __a64_hw_dtag = ARM64_SIM_L_REG_TAG(ARM64_X0); __u32 __a64_hw_len = (__u32)ARM64_SIM_L_READ_REG(ARM64_X1); ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_probe_read_kernel_str((void *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X0), (__u32)ARM64_SIM_L_READ_REG(ARM64_X1), (const void *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X2))); ARM64_SIM_L_MEMORY_TAG_TRANSFER(__a64_hw_dst, __a64_hw_dtag, 0, ARM64_SIM_TAG_SCALAR, __a64_hw_len, 0); } while (0)

#define ARM64_SIM_BPF_CALL_bpf_jiffies64() \
	ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_jiffies64())

#define ARM64_SIM_BPF_CALL_bpf_get_netns_cookie() \
	ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_get_netns_cookie((void *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X0)))

#define ARM64_SIM_BPF_CALL_bpf_sk_assign() \
	ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_sk_assign((void *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X0), (void *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X1), (__u64)ARM64_SIM_L_READ_REG(ARM64_X2)))

#define ARM64_SIM_BPF_CALL_bpf_ktime_get_boot_ns() \
	ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_ktime_get_boot_ns())

#define ARM64_SIM_BPF_CALL_bpf_seq_write() \
	ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_seq_write((struct seq_file *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X0), (const void *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X1), (__u32)ARM64_SIM_L_READ_REG(ARM64_X2)))

/* Paired ringbuf submit/discard helpers return architectural zero. */
#define ARM64_SIM_BPF_CALL_bpf_ringbuf_reserve() \
	ARM64_SIM_L_HELPER_POINTER_RESULT(bpf_ringbuf_reserve((void *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X0), (__u64)ARM64_SIM_L_READ_REG(ARM64_X1), (__u64)ARM64_SIM_L_READ_REG(ARM64_X2)))

#define ARM64_SIM_BPF_CALL_bpf_ringbuf_submit() \
	ARM64_SIM_L_HELPER_VOID_RESULT(bpf_ringbuf_submit((void *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X0), (__u64)ARM64_SIM_L_READ_REG(ARM64_X1)))

#define ARM64_SIM_BPF_CALL_bpf_ringbuf_discard() \
	ARM64_SIM_L_HELPER_VOID_RESULT(bpf_ringbuf_discard((void *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X0), (__u64)ARM64_SIM_L_READ_REG(ARM64_X1)))

#define ARM64_SIM_BPF_CALL_bpf_this_cpu_ptr() \
	ARM64_SIM_L_HELPER_POINTER_RESULT(bpf_this_cpu_ptr((const void *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X0)))

#define ARM64_SIM_BPF_CALL_bpf_strncmp() \
	ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_strncmp((const char *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X0), (__u32)ARM64_SIM_L_READ_REG(ARM64_X1), (const char *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X2)))

#define ARM64_SIM_BPF_CALL_bpf_ringbuf_output() \
	ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_ringbuf_output((void *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X0), (void *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X1), (__u64)ARM64_SIM_L_READ_REG(ARM64_X2), (__u64)ARM64_SIM_L_READ_REG(ARM64_X3)))

#define ARM64_SIM_BPF_CALL_bpf_copy_from_user() \
	do { __s64 __a64_hw_dst = (__s64)(long)ARM64_SIM_L_READ_REG_PTR(ARM64_X0); __u8 __a64_hw_dtag = ARM64_SIM_L_REG_TAG(ARM64_X0); __u32 __a64_hw_len = (__u32)ARM64_SIM_L_READ_REG(ARM64_X1); __s64 __a64_hw_src = (__s64)(long)ARM64_SIM_L_READ_REG_PTR(ARM64_X2); __u8 __a64_hw_stag = ARM64_SIM_L_REG_TAG(ARM64_X2); ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_copy_from_user((void *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X0), (__u32)ARM64_SIM_L_READ_REG(ARM64_X1), (const void *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X2))); ARM64_SIM_L_MEMORY_TAG_TRANSFER(__a64_hw_dst, __a64_hw_dtag, __a64_hw_src, __a64_hw_stag, __a64_hw_len, (ARM64_SIM_L_READ_REG(ARM64_X0) == 0)); } while (0)

#define ARM64_SIM_BPF_CALL_bpf_redirect_neigh() \
	ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_redirect_neigh((__u32)ARM64_SIM_L_READ_REG(ARM64_X0), (struct bpf_redir_neigh *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X1), (int)ARM64_SIM_L_READ_REG(ARM64_X2), (__u64)ARM64_SIM_L_READ_REG(ARM64_X3)))

#define ARM64_SIM_BPF_CALL_bpf_redirect_peer() \
	ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_redirect_peer((__u32)ARM64_SIM_L_READ_REG(ARM64_X0), (__u64)ARM64_SIM_L_READ_REG(ARM64_X1)))

#define ARM64_SIM_BPF_CALL_bpf_get_current_task_btf() \
	ARM64_SIM_L_HELPER_POINTER_RESULT(bpf_get_current_task_btf())

#define ARM64_SIM_BPF_CALL_bpf_ktime_get_coarse_ns() \
	ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_ktime_get_coarse_ns())

#define ARM64_SIM_BPF_CALL_bpf_ima_inode_hash() \
	ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_ima_inode_hash((struct inode *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X0), (void *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X1), (__u32)ARM64_SIM_L_READ_REG(ARM64_X2)))

#define ARM64_SIM_BPF_CALL_bpf_check_mtu() \
    do { __s64 __a64_hw_dst = (__s64)(long)ARM64_SIM_L_READ_REG_PTR(ARM64_X2); __u8 __a64_hw_dtag = ARM64_SIM_L_REG_TAG(ARM64_X2); ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_check_mtu((void *)ARM64_SIM_L_HELPER_CTX_PTR(ARM64_X0), (__u32)ARM64_SIM_L_READ_REG(ARM64_X1), (__u32 *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X2), (__s32)ARM64_SIM_L_READ_REG(ARM64_X3), (__u64)ARM64_SIM_L_READ_REG(ARM64_X4))); if ((__s64)ARM64_SIM_L_READ_REG(ARM64_X0) >= 0) ARM64_SIM_L_MEMORY_TAG_TRANSFER(__a64_hw_dst, __a64_hw_dtag, 0, ARM64_SIM_TAG_SCALAR, sizeof(__u32), 0); } while (0)

#define ARM64_SIM_BPF_CALL_bpf_get_func_ip() \
	ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_get_func_ip((void *)ARM64_SIM_L_HELPER_CTX_PTR(ARM64_X0)))

#define ARM64_SIM_BPF_CALL_bpf_get_attach_cookie() \
	ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_get_attach_cookie((void *)ARM64_SIM_L_HELPER_CTX_PTR(ARM64_X0)))

#define ARM64_SIM_BPF_CALL_bpf_task_pt_regs() \
	ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_task_pt_regs((struct task_struct *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X0)))

#define ARM64_SIM_BPF_CALL_bpf_loop() \
	ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_loop((__u32)ARM64_SIM_L_READ_REG(ARM64_X0), (void *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X1), (void *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X2), (__u64)ARM64_SIM_L_READ_REG(ARM64_X3)))

#define ARM64_SIM_BPF_CALL_bpf_get_func_arg() \
	ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_get_func_arg((void *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X0), (__u32)ARM64_SIM_L_READ_REG(ARM64_X1), (__u64 *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X2)))

#define ARM64_SIM_BPF_CALL_bpf_get_func_ret() \
	ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_get_func_ret((void *)ARM64_SIM_L_HELPER_CTX_PTR(ARM64_X0), (__u64 *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X1)))

#define ARM64_SIM_BPF_CALL_bpf_get_func_arg_cnt() \
	ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_get_func_arg_cnt((void *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X0)))

#define ARM64_SIM_BPF_CALL_bpf_get_retval() \
	ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_get_retval())

#define ARM64_SIM_BPF_CALL_bpf_xdp_get_buff_len() \
	ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_xdp_get_buff_len((struct xdp_md *)ARM64_SIM_L_HELPER_CTX_PTR(ARM64_X0)))

#define ARM64_SIM_BPF_CALL_bpf_xdp_load_bytes() \
	do { \
		__s64 __a64_hw_dst = (__s64)(long)ARM64_SIM_L_READ_REG_PTR(ARM64_X2); \
		__u8 __a64_hw_dtag = ARM64_SIM_L_REG_TAG(ARM64_X2); \
		__u32 __a64_hw_len = (__u32)ARM64_SIM_L_READ_REG(ARM64_X3); \
		ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_xdp_load_bytes((struct xdp_md *)ARM64_SIM_L_HELPER_CTX_PTR(ARM64_X0), (__u32)ARM64_SIM_L_READ_REG(ARM64_X1), (void *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X2), __a64_hw_len)); \
		if (ARM64_SIM_L_READ_REG(ARM64_X0) == 0) \
			ARM64_SIM_L_MEMORY_TAG_TRANSFER(__a64_hw_dst, __a64_hw_dtag, 0, ARM64_SIM_TAG_SCALAR, __a64_hw_len, 0); \
	} while (0)

#define ARM64_SIM_BPF_CALL_bpf_xdp_store_bytes() \
	ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_xdp_store_bytes((struct xdp_md *)ARM64_SIM_L_HELPER_CTX_PTR(ARM64_X0), (__u32)ARM64_SIM_L_READ_REG(ARM64_X1), (void *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X2), (__u32)ARM64_SIM_L_READ_REG(ARM64_X3)))

#define ARM64_SIM_BPF_CALL_bpf_copy_from_user_task() \
	ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_copy_from_user_task((void *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X0), (__u32)ARM64_SIM_L_READ_REG(ARM64_X1), (const void *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X2), (struct task_struct *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X3), (__u64)ARM64_SIM_L_READ_REG(ARM64_X4)))

#define ARM64_SIM_BPF_CALL_bpf_ima_file_hash() \
	ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_ima_file_hash((struct file *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X0), (void *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X1), (__u32)ARM64_SIM_L_READ_REG(ARM64_X2)))

#define ARM64_SIM_BPF_CALL_bpf_kptr_xchg() \
	ARM64_SIM_L_HELPER_POINTER_RESULT(bpf_kptr_xchg((void *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X0), (void *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X1)))

#define ARM64_SIM_BPF_CALL_bpf_map_lookup_percpu_elem() \
	ARM64_SIM_L_HELPER_POINTER_RESULT(bpf_map_lookup_percpu_elem((void *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X0), (const void *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X1), (__u32)ARM64_SIM_L_READ_REG(ARM64_X2)))

/* LOCAL dynptr initialization writes all opaque bytes on success and error. */
#define ARM64_SIM_BPF_CALL_bpf_dynptr_from_mem() \
    do { \
        __s64 __a64_hw_dst = (__s64)(long)ARM64_SIM_L_READ_REG_PTR(ARM64_X3); \
        __u8 __a64_hw_dtag = ARM64_SIM_L_REG_TAG(ARM64_X3); \
        ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_dynptr_from_mem((void *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X0), (__u64)ARM64_SIM_L_READ_REG(ARM64_X1), (__u64)ARM64_SIM_L_READ_REG(ARM64_X2), (struct bpf_dynptr *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X3))); \
        ARM64_SIM_L_MEMORY_TAG_TRANSFER(__a64_hw_dst, __a64_hw_dtag, 0, ARM64_SIM_TAG_SCALAR, sizeof(struct bpf_dynptr), 0); \
    } while (0)

/* Stock dynptr helper calls retain their native five-argument ABI and pointer result. */
#define ARM64_SIM_BPF_CALL_bpf_dynptr_read() \
    do { \
        __s64 __a64_hw_dst = (__s64)(long)ARM64_SIM_L_READ_REG_PTR(ARM64_X0); \
        __u8 __a64_hw_dtag = ARM64_SIM_L_REG_TAG(ARM64_X0); \
        __u64 __a64_hw_len = ARM64_SIM_L_READ_REG(ARM64_X1); \
        ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_dynptr_read((void *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X0), __a64_hw_len, (const struct bpf_dynptr *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X2), (__u64)ARM64_SIM_L_READ_REG(ARM64_X3), (__u64)ARM64_SIM_L_READ_REG(ARM64_X4))); \
        ARM64_SIM_L_MEMORY_TAG_TRANSFER(__a64_hw_dst, __a64_hw_dtag, 0, ARM64_SIM_TAG_SCALAR, __a64_hw_len, 0); \
    } while (0)

#define ARM64_SIM_BPF_CALL_bpf_dynptr_write() \
    ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_dynptr_write((const struct bpf_dynptr *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X0), (__u64)ARM64_SIM_L_READ_REG(ARM64_X1), (void *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X2), (__u64)ARM64_SIM_L_READ_REG(ARM64_X3), (__u64)ARM64_SIM_L_READ_REG(ARM64_X4)))

#define ARM64_SIM_BPF_CALL_bpf_dynptr_data() \
    ARM64_SIM_L_HELPER_POINTER_RESULT(bpf_dynptr_data((const struct bpf_dynptr *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X0), (__u64)ARM64_SIM_L_READ_REG(ARM64_X1), (__u64)ARM64_SIM_L_READ_REG(ARM64_X2)))

/* The paired ringbuf helpers write the complete opaque dynptr on all returns. */
#define ARM64_SIM_BPF_CALL_bpf_ringbuf_reserve_dynptr() \
    do { \
        __s64 __a64_hw_dst = (__s64)(long)ARM64_SIM_L_READ_REG_PTR(ARM64_X3); \
        __u8 __a64_hw_dtag = ARM64_SIM_L_REG_TAG(ARM64_X3); \
        ARM64_SIM_L_HELPER_SCALAR_RESULT(bpf_ringbuf_reserve_dynptr((void *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X0), (__u32)ARM64_SIM_L_READ_REG(ARM64_X1), (__u64)ARM64_SIM_L_READ_REG(ARM64_X2), (struct bpf_dynptr *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X3))); \
        ARM64_SIM_L_MEMORY_TAG_TRANSFER(__a64_hw_dst, __a64_hw_dtag, 0, ARM64_SIM_TAG_SCALAR, sizeof(struct bpf_dynptr), 0); \
    } while (0)

#define ARM64_SIM_BPF_CALL_bpf_ringbuf_submit_dynptr() \
    do { \
        __s64 __a64_hw_dst = (__s64)(long)ARM64_SIM_L_READ_REG_PTR(ARM64_X0); \
        __u8 __a64_hw_dtag = ARM64_SIM_L_REG_TAG(ARM64_X0); \
        ARM64_SIM_L_HELPER_VOID_RESULT(bpf_ringbuf_submit_dynptr((struct bpf_dynptr *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X0), (__u64)ARM64_SIM_L_READ_REG(ARM64_X1))); \
        ARM64_SIM_L_MEMORY_TAG_TRANSFER(__a64_hw_dst, __a64_hw_dtag, 0, ARM64_SIM_TAG_SCALAR, sizeof(struct bpf_dynptr), 0); \
    } while (0)

#define ARM64_SIM_BPF_CALL_bpf_ringbuf_discard_dynptr() \
    do { \
        __s64 __a64_hw_dst = (__s64)(long)ARM64_SIM_L_READ_REG_PTR(ARM64_X0); \
        __u8 __a64_hw_dtag = ARM64_SIM_L_REG_TAG(ARM64_X0); \
        ARM64_SIM_L_HELPER_VOID_RESULT(bpf_ringbuf_discard_dynptr((struct bpf_dynptr *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X0), (__u64)ARM64_SIM_L_READ_REG(ARM64_X1))); \
        ARM64_SIM_L_MEMORY_TAG_TRANSFER(__a64_hw_dst, __a64_hw_dtag, 0, ARM64_SIM_TAG_SCALAR, sizeof(struct bpf_dynptr), 0); \
    } while (0)

#define ARM64_SIM_RET()                                                     \
	do {                                                               \
        if (__a64_sp != 0) ARM64_SIM_L_REJECT_PC(); \
		return (__u32)ARM64_SIM_L_READ_REG(ARM64_X0);                                  \
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
		if (KPROG_ARM64_BRANCH_BACKWARD((CURRENT), (TARGET))) {                                \
			ARM64_SIM_A64_JCC_BACKWARD((COND), LABEL, ID);     \
		} else if (ARM64_SIM_L_EVAL_COND(COND)) {                  \
			ARM64_SIM_A64_JMP((CURRENT), (TARGET), LABEL);     \
		}                                                          \
	} while (0)

#define ARM64_SIM_A64_JCC(COND, CURRENT, TARGET, LABEL)                     \
	ARM64_SIM_A64_JCC_IMPL((COND), (CURRENT), (TARGET), LABEL, __LINE__)

/* CMP followed by B.GT, with no other incoming edge between them. Preserve
 * all four flags, while exposing the equivalent signed comparison directly.
 * KProgFormal.Arm64CompareCond proves this from the existing SUB/NZCV rules. */
#define ARM64_SIM_A64_CMP_GT(OP, LHS, RHS, WIDTH, AUX, IMM, LABEL)          \
    do {                                                                 \
        const __u8 __a64_cmp_width = (WIDTH);                                  \
        __u64 __a64_cmp_lhs = ARM64_SIM_L_READ_REG(LHS);                  \
        __u64 __a64_cmp_rhs = KPROG_ARM64_FLAG_RHS((OP), (IMM),           \
            ARM64_SIM_L_MOD_VALUE((RHS), ARM64_SIM_L_MOD(AUX),           \
                ARM64_SIM_L_SHIFT(AUX), __a64_cmp_width));                \
        ARM64_SIM_L_SET_SUB_FLAGS(__a64_cmp_lhs, __a64_cmp_rhs, __a64_cmp_width); \
        if (__a64_cmp_width == ARM64_WIDTH_32) {                         \
            if ((__s32)__a64_cmp_lhs > (__s32)__a64_cmp_rhs) goto LABEL;  \
        } else if (__a64_cmp_width == ARM64_WIDTH_64) {                  \
            if ((__s64)__a64_cmp_lhs > (__s64)__a64_cmp_rhs) goto LABEL;  \
        } else { ARM64_SIM_L_UNSUPPORTED_OPCODE(); }                    \
    } while (0)

#define ARM64_SIM_A64_CBZ_VALUE_IMPL(VALUE, KIND, CURRENT, TARGET, LABEL, ID)        \
	do {                                                               \
		__u64 __a64_l_value = (VALUE);          \
		int __a64_l_taken =                                        \
			KPROG_ARM64_BRANCH_TEST((KIND), __a64_l_value, 0ULL);\
		if (KPROG_ARM64_BRANCH_BACKWARD((CURRENT), (TARGET))) {                              \
			if (!__a64_l_taken) {                             \
				goto ARM64_SIM_CONCAT(__a64_sim_cb_fallthrough_, ID);\
			}                                                 \
			goto LABEL;                                      \
ARM64_SIM_CONCAT(__a64_sim_cb_fallthrough_, ID):                             \
			;                                                \
		} else if (__a64_l_taken) {                               \
			goto LABEL;                                      \
		}                                                         \
	} while (0)

#define ARM64_SIM_A64_CBZ_IMPL(REG, KIND, CURRENT, TARGET, LABEL, ID)       \
    ARM64_SIM_A64_CBZ_VALUE_IMPL(ARM64_SIM_L_READ_REG(REG), (KIND), (CURRENT), (TARGET), LABEL, ID)

/* W-form tests consume the low32 bits without writing the source register. */
#define ARM64_SIM_A64_CBZ_W(REG, CURRENT, TARGET, LABEL)                   \
    ARM64_SIM_A64_CBZ_VALUE_IMPL((__u32)ARM64_SIM_L_READ_REG(REG), KPROG_ARM64_BRANCH_CBZ, (CURRENT), (TARGET), LABEL, __LINE__)
#define ARM64_SIM_A64_CBNZ_W(REG, CURRENT, TARGET, LABEL)                  \
    ARM64_SIM_A64_CBZ_VALUE_IMPL((__u32)ARM64_SIM_L_READ_REG(REG), KPROG_ARM64_BRANCH_CBNZ, (CURRENT), (TARGET), LABEL, __LINE__)

#define ARM64_SIM_A64_CBZ(REG, CURRENT, TARGET, LABEL)                      \
	ARM64_SIM_A64_CBZ_IMPL((REG), KPROG_ARM64_BRANCH_CBZ, (CURRENT), (TARGET), LABEL, __LINE__)

#define ARM64_SIM_A64_CBNZ(REG, CURRENT, TARGET, LABEL)                     \
	ARM64_SIM_A64_CBZ_IMPL((REG), KPROG_ARM64_BRANCH_CBNZ, (CURRENT), (TARGET), LABEL, __LINE__)

#define ARM64_SIM_A64_TBZ_IMPL(REG, BIT, KIND, CURRENT, TARGET, LABEL, ID)  \
	do {                                                               \
		int __a64_l_taken =                                        \
			KPROG_ARM64_BRANCH_TEST((KIND), ARM64_SIM_L_READ_REG(REG), (BIT));\
		if (KPROG_ARM64_BRANCH_BACKWARD((CURRENT), (TARGET))) {                              \
			if (!__a64_l_taken) {                             \
				goto ARM64_SIM_CONCAT(__a64_sim_tb_fallthrough_, ID);\
			}                                                 \
			goto LABEL;                                      \
ARM64_SIM_CONCAT(__a64_sim_tb_fallthrough_, ID):                             \
			;                                                \
		} else if (__a64_l_taken) {                               \
			goto LABEL;                                      \
		}                                                         \
	} while (0)

#define ARM64_SIM_A64_TBZ(REG, BIT, CURRENT, TARGET, LABEL)                 \
	ARM64_SIM_A64_TBZ_IMPL((REG), (BIT), KPROG_ARM64_BRANCH_TBZ, (CURRENT), (TARGET), LABEL, __LINE__)

#define ARM64_SIM_A64_TBNZ(REG, BIT, CURRENT, TARGET, LABEL)                \
	ARM64_SIM_A64_TBZ_IMPL((REG), (BIT), KPROG_ARM64_BRANCH_TBNZ, (CURRENT), (TARGET), LABEL, __LINE__)

#define ARM64_SIM_A64_ADR(REG, ADDRESS)                                    \
	ARM64_SIM_L_WRITE_REG_PTR_TAG((REG), (void *)(long)(ADDRESS), ARM64_SIM_TAG_CODE)

#define ARM64_SIM_A64_LINK(RETURN_ADDR)                                     \
	do {                                                               \
		__a64_lr = (RETURN_ADDR);                                  \
		ARM64_SIM_A64_ADR(ARM64_X30, __a64_lr);                  \
	} while (0)

#define ARM64_SIM_A64_CALL(LABEL, RETURN_ADDR)                              \
	do {                                                               \
		ARM64_SIM_A64_LINK(RETURN_ADDR);                           \
		goto LABEL;                                                \
	} while (0)

#define ARM64_SIM_A64_RET_TO(REG, CASES)                                    \
	do {                                                               \
		__a64_lr = ARM64_SIM_L_READ_REG_RAW(REG);                      \
		if (__a64_lr || ARM64_SIM_L_REG_TAG(REG) != ARM64_SIM_TAG_RETURN) {\
			if (ARM64_SIM_L_REG_TAG(REG) != ARM64_SIM_TAG_CODE) { \
				ARM64_SIM_L_REJECT_PC();                         \
			} else switch (__a64_lr) {                               \
			CASES                                                   \
			default: ARM64_SIM_L_REJECT_PC(); break;          \
			}                                                 \
		}                                                          \
		ARM64_SIM_RET();                                          \
	} while (0)

#define ARM64_SIM_A64_RET_REG(REG) ARM64_SIM_A64_RET_TO((REG), ARM64_SIM_RETURN_CASES)
#define ARM64_SIM_A64_RET() ARM64_SIM_A64_RET_REG(ARM64_X30)

#define ARM64_SIM_LICENSE() char LICENSE[] SEC("license") = "GPL"

#include "arm64_sim_direct.h"

/* The formal whole-program frontend binds after the actual producer profile
 * definitions. Component exports and native builds retain their own bindings. */
#if defined(KPROG_ARM64_PROGRAM_EXPORT)
#include "../formal/c/Arm64ProgramBinding.h"
#endif

#endif
