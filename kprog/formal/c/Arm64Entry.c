/* Actual production entry declarations, followed by a borrowed continuation.
 * The continuation is an explicit hole for the program body, not a proof
 * that arbitrary producer labels, helper targets or return cases are bound.
 */
#define ARM64_SIM_ENABLE_STACK 1
#include "Arm64Entry.h"


__u32 kprog_arm64_entry_raw(void *ctx, kprog_arm64_entry_continuation continuation)
{
	ARM64_SIM_ENTRY_RAW(ctx);
	KPROG_ARM64_ENTRY_VIEW(entry);
	return continuation(&entry);
}
__u32 kprog_arm64_entry_xdp(struct xdp_md *ctx, kprog_arm64_entry_continuation continuation)
{
	ARM64_SIM_ENTRY_XDP(ctx);
	KPROG_ARM64_ENTRY_VIEW(entry);
	return continuation(&entry);
}
__u32 kprog_arm64_entry_skb(struct __sk_buff *ctx, void *(*bpf_cast_to_kern_ctx)(void *),
                            kprog_arm64_entry_continuation continuation)
{
	ARM64_SIM_ENTRY_SKB(ctx);
	KPROG_ARM64_ENTRY_VIEW(entry);
	return continuation(&entry);
}
