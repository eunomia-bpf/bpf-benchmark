/* The entry continuation borrows the actual locals for this call only.
 * Cells are individually declared by production C, not a dense register bank.
 * Byte/payload storage starts uninitialized; this view does not read it.
 */
#ifndef KPROG_ARM64_ENTRY_H
#define KPROG_ARM64_ENTRY_H
#include "../../arm64/arm64_sim_local_bpf.h"
/* Compile the active producer layout, including its compact rank expressions.
 * These bodies access only the supplied storage; declaring the view reads none.
 */
static inline __u64 kprog_arm64_payload_load(volatile __u64 *__a64_stack_payload, __u64 index)
{ return ARM64_SIM_L_STACK_PAYLOAD_LOAD(index); }
static inline void kprog_arm64_payload_store(volatile __u64 *__a64_stack_payload, __u64 index, __u64 value)
{ ARM64_SIM_L_STACK_PAYLOAD_STORE(index, value); }
struct kprog_arm64_entry {
	union arm64_sim_gpr *const *cells;
	__u8 *const *tag_cells;
	__u64 *sp_base, *return_base, *lr;
	__s64 *sp;
	__u8 *sp_valid, *return_valid;
	__u8 *n, *z, *c, *v;
	__u64 *vector_lo[32], *vector_hi[32];
	volatile __u8 *b;
	volatile __u64 *q, *payload;
	__u64 (*payload_load)(volatile __u64 *, __u64);
	void (*payload_store)(volatile __u64 *, __u64, __u64);
	__u8 *stack_tags;
	__u32 capacity, payload_words, tag_bytes;
	__s64 bias;
	void **helper_context, **helper_abi_base;
	__u8 *is_xdp, *abi_kind;
	struct __sk_buff **skb_context;
	void *abi;
};
typedef __u32 (*kprog_arm64_entry_continuation)(struct kprog_arm64_entry *);
__u32 kprog_arm64_entry_raw(void *, kprog_arm64_entry_continuation);
__u32 kprog_arm64_entry_xdp(struct xdp_md *, kprog_arm64_entry_continuation);
__u32 kprog_arm64_entry_skb(struct __sk_buff *, void *(*)(void *), kprog_arm64_entry_continuation);
#define KPROG_ARM64_ENTRY_VIEW(NAME) \
	struct kprog_arm64_entry NAME = { \
		.cells = __a64_cells, .tag_cells = __a64_tag_cells, \
		.sp_base = &__a64_numeric_sp, .return_base = &__a64_numeric_return, \
		.sp = &__a64_sp, .sp_valid = &__a64_numeric_sp_valid, \
		.return_valid = &__a64_numeric_return_valid, .lr = &__a64_lr, \
		.n = &__a64_n, .z = &__a64_z, .c = &__a64_c, .v = &__a64_v, \
		.b = __a64_stack.b, .q = __a64_stack.q, \
		.payload = __a64_stack_payload, .stack_tags = __a64_stack_tag, \
		.payload_load = kprog_arm64_payload_load, .payload_store = kprog_arm64_payload_store, \
		.capacity = sizeof(__a64_stack.b), .bias = ARM64_SIM_STACK_BIAS, \
		.payload_words = sizeof(__a64_stack_payload) / sizeof(__a64_stack_payload[0]), \
		.tag_bytes = sizeof(__a64_stack_tag), \
		.helper_context = &__a64_sim_helper_ctx, \
		.helper_abi_base = &__a64_sim_helper_abi_base, \
		.is_xdp = &__a64_sim_is_xdp, .abi_kind = &__a64_sim_abi_kind, \
		.skb_context = &__a64_sim_skb_ctx, .abi = &__a64_sim_abi \
	}; \
	for (__u32 i = 0; i < 32; ++i) { \
		NAME.vector_lo[i] = &__a64_vectors[i].lo; \
		NAME.vector_hi[i] = &__a64_vectors[i].hi; \
	}

#endif
