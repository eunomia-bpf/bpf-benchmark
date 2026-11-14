/* Constant and decoded-offset context reads, cb byte ladders and raw fallback
 * accesses. This compile fixture measures emitted bytes, not kernel admission. */
#include "../../arm64/arm64_sim_local_bpf.h"
SEC("xdp") int arm64_context_xdp(struct xdp_md *ctx)
{
	ARM64_SIM_ENTRY_XDP(ctx);
	__u64 result = ARM64_SIM_L_XDP_READ(0, 0, 8);
	result ^= ARM64_SIM_L_XDP_READ(0, 8, 8);
	result ^= ARM64_SIM_L_XDP_READ(0, 16, 8);
	result ^= ARM64_SIM_L_XDP_READ(0, 7, 1);
	result ^= ARM64_SIM_L_XDP_READ(0, 10, 2);
	result ^= ARM64_SIM_L_XDP_READ(0, 20, 4);
	result ^= ARM64_SIM_L_XDP_READ(0, 24, 4);
	result ^= ARM64_SIM_L_XDP_READ(0, ctx->rx_queue_index & 31, 4);
	return result;
}
SEC("tc") int arm64_context_skb(struct __sk_buff *ctx)
{
	ARM64_SIM_ENTRY_SKB(ctx);
	__u64 result = ARM64_SIM_L_SKB_READ(0, 208, 8);
	result ^= ARM64_SIM_L_SKB_READ(0, 80, 8);
	result ^= ARM64_SIM_L_SKB_READ(0, 215, 1);
	result ^= ARM64_SIM_L_SKB_READ(0, 82, 2);
	result ^= ARM64_SIM_L_SKB_READ(0, 212, 4);
	result ^= ARM64_SIM_L_SKB_READ(0, 48, 8);
	result ^= ARM64_SIM_L_SKB_READ(0, 49, 4);
	result ^= ARM64_SIM_L_SKB_READ(0, 52, 2);
	result ^= ARM64_SIM_L_SKB_READ(0, 63, 1);
	__s64 offset = (ctx->mark & 31) + 48;
	result ^= ARM64_SIM_L_SKB_READ(0, offset, 4);
	ARM64_SIM_L_SKB_WRITE(0, 48, 8, result);
	ARM64_SIM_L_SKB_WRITE(0, 49, 4, result);
	ARM64_SIM_L_SKB_WRITE(0, 52, 2, result);
	ARM64_SIM_L_SKB_WRITE(0, 63, 1, result);
	ARM64_SIM_L_SKB_WRITE(0, offset, 4, result);
	return result;
}
char LICENSE[] SEC("license") = "GPL";
