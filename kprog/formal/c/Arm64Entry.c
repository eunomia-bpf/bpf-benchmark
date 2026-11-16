/* Actual production entry declarations, followed by a borrowed continuation.
 * The continuation is an explicit hole for the program body, not a proof
 * that arbitrary producer labels, helper targets or return cases are bound.
 */
#define ARM64_SIM_ENABLE_STACK 1
#include "Arm64Entry.h"

#define ENTRY_CONTINUE() \
	struct kprog_arm64_entry entry = { \
		.cells = __a64_cells, .tag_cells = __a64_tag_cells, \
		.sp_base = &__a64_numeric_sp, .return_base = &__a64_numeric_return, \
		.sp = &__a64_sp, .sp_valid = &__a64_numeric_sp_valid, \
		.return_valid = &__a64_numeric_return_valid, .lr = &__a64_lr, \
		.n = &__a64_n, .z = &__a64_z, .c = &__a64_c, .v = &__a64_v, \
		.bytes = __a64_stack.b, .words = __a64_stack.q, \
		.payload = __a64_stack_payload, .stack_tags = __a64_stack_tag, \
		.capacity = ARM64_SIM_STACK_BYTES, .bias = ARM64_SIM_STACK_BIAS, \
		.payload_words = ARM64_SIM_STACK_PAYLOAD_WORDS, \
		.tag_bytes = ARM64_SIM_TAG_STORAGE_BYTES(ARM64_SIM_STACK_BYTES), \
		.helper_context = &__a64_sim_helper_ctx, \
		.helper_abi_base = &__a64_sim_helper_abi_base, \
		.is_xdp = &__a64_sim_is_xdp, .abi_kind = &__a64_sim_abi_kind, \
		.skb_context = &__a64_sim_skb_ctx, .abi = &__a64_sim_abi \
	}; \
	for (__u32 i = 0; i < 32; ++i) { \
		entry.vector_lo[i] = &__a64_vectors[i].lo; \
		entry.vector_hi[i] = &__a64_vectors[i].hi; \
	} \
	return continuation(&entry)

__u32 kprog_arm64_entry_raw(void *ctx, kprog_arm64_entry_continuation continuation)
{
	ARM64_SIM_ENTRY_RAW(ctx);
	ENTRY_CONTINUE();
}
__u32 kprog_arm64_entry_xdp(struct xdp_md *ctx, kprog_arm64_entry_continuation continuation)
{
	ARM64_SIM_ENTRY_XDP(ctx);
	ENTRY_CONTINUE();
}
__u32 kprog_arm64_entry_skb(struct __sk_buff *ctx, void *(*bpf_cast_to_kern_ctx)(void *),
                            kprog_arm64_entry_continuation continuation)
{
	ARM64_SIM_ENTRY_SKB(ctx);
	ENTRY_CONTINUE();
}
