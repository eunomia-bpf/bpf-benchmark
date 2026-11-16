/* The entry continuation borrows the actual locals for this call only.
 * Cells are individually declared by production C, not a dense register bank.
 * Byte/payload storage starts uninitialized; this view does not read it.
 */
#ifndef KPROG_ARM64_ENTRY_H
#define KPROG_ARM64_ENTRY_H
#include "../../arm64/arm64_sim_local_bpf.h"
struct kprog_arm64_entry {
	union arm64_sim_gpr *const *cells;
	__u8 *const *tag_cells;
	__u64 *sp_base, *return_base, *lr;
	__s64 *sp;
	__u8 *sp_valid, *return_valid;
	__u8 *n, *z, *c, *v;
	__u64 *vector_lo[32], *vector_hi[32];
	volatile __u8 *bytes;
	volatile __u64 *words, *payload;
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
#endif
