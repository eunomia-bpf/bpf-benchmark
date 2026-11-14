/* Constant and decoded-offset context reads, cb byte ladders and raw fallback
 * accesses. This compile fixture measures emitted bytes, not kernel admission. */
#include "../../arm64/arm64_sim_local_bpf.h"
SEC("xdp") int arm64_context_xdp(struct xdp_md *ctx)
{
	ARM64_SIM_ENTRY_XDP(ctx);
	__u64 result = ARM64_SIM_L_MEM_READ(0, 255, 0, 0, 0, 8);
	result ^= ARM64_SIM_L_MEM_READ(0, 255, 0, 8, 0, 8);
	result ^= ARM64_SIM_L_MEM_READ(0, 255, 0, 16, 0, 8);
	result ^= ARM64_SIM_L_MEM_READ(0, 255, 0, 7, 0, 1);
	result ^= ARM64_SIM_L_MEM_READ(0, 255, 0, 10, 0, 2);
	result ^= ARM64_SIM_L_MEM_READ(0, 255, 0, 20, 0, 4);
	result ^= ARM64_SIM_L_MEM_READ(0, 255, 0, 24, 0, 4);
	result ^= ARM64_SIM_L_MEM_READ(0, 255, 0, ctx->rx_queue_index & 31, 0, 4);
	return result;
}
SEC("tc") int arm64_context_skb(struct __sk_buff *ctx)
{
	ARM64_SIM_ENTRY_SKB(ctx);
	__u64 result = ARM64_SIM_L_MEM_READ(0, 255, 0, 208, 0, 8);
	result ^= ARM64_SIM_L_MEM_READ(0, 255, 0, 80, 0, 8);
	result ^= ARM64_SIM_L_MEM_READ(0, 255, 0, 215, 0, 1);
	result ^= ARM64_SIM_L_MEM_READ(0, 255, 0, 82, 0, 2);
	result ^= ARM64_SIM_L_MEM_READ(0, 255, 0, 212, 0, 4);
	result ^= ARM64_SIM_L_MEM_READ(0, 255, 0, 48, 0, 8);
	result ^= ARM64_SIM_L_MEM_READ(0, 255, 0, 49, 0, 4);
	result ^= ARM64_SIM_L_MEM_READ(0, 255, 0, 52, 0, 2);
	result ^= ARM64_SIM_L_MEM_READ(0, 255, 0, 63, 0, 1);
	__s64 offset = (ctx->mark & 31) + 48;
	result ^= ARM64_SIM_L_MEM_READ(0, 255, 0, offset, 0, 4);
	ARM64_SIM_L_MEM_WRITE(0, 255, 0, 48, 0, 8, result, ARM64_SIM_TAG_SCALAR);
	ARM64_SIM_L_MEM_WRITE(0, 255, 0, 49, 0, 4, result, ARM64_SIM_TAG_SCALAR);
	ARM64_SIM_L_MEM_WRITE(0, 255, 0, 52, 0, 2, result, ARM64_SIM_TAG_SCALAR);
	ARM64_SIM_L_MEM_WRITE(0, 255, 0, 63, 0, 1, result, ARM64_SIM_TAG_SCALAR);
	ARM64_SIM_L_MEM_WRITE(0, 255, 0, offset, 0, 4, result, ARM64_SIM_TAG_SCALAR);
	return result;
}
char LICENSE[] SEC("license") = "GPL";
