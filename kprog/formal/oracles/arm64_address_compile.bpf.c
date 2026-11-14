/* Compile-only fidelity fixture: live full-width input, both ADRP classes,
 * SP/return coordinate inputs, and observable private byte/tag release. */
#define ARM64_SIM_ENABLE_STACK 1
#include "../../arm64/arm64_sim_local_bpf.h"

SEC("socket") int arm64_address_compile(struct __sk_buff *ctx)
{
	ARM64_SIM_ENTRY_RAW(ctx);
	__u64 value = ((__u64)ctx->mark << 32) | ctx->priority;
	for (__u32 i = 0; i < ARM64_SIM_STACK_BYTES; ++i)
		__a64_stack.b[i] = (__u8)(value + i);
	for (__u32 i = 0; i < KPROG_ARM64_STACK_TAG_SLOTS(ARM64_SIM_STACK_BYTES); ++i)
		__a64_stack_tag[i] = (__u8)(value + i);
	ARM64_SIM_L_EXEC(ARM64_OP_ADRP_GOT, ARM64_X1, 0, 0, 0, ARM64_WIDTH_64, 0, value);
	ARM64_SIM_L_EXEC(ARM64_OP_ADRP_RODATA, ARM64_SP, 0, 0, 0, ARM64_WIDTH_64, 0, value);
	ARM64_SIM_L_WRITE_REG_PTR_TAG(ARM64_SP, (void *)(long)value, ARM64_SIM_TAG_RETURN);
	ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_SP, value, ARM64_WIDTH_32);
	__u64 result = (__u64)__a64_sp ^ __a64_x1.x ^ __a64_x1_tag;
	for (__u32 i = 0; i < ARM64_SIM_STACK_BYTES; ++i)
		result ^= __a64_stack.b[i];
	for (__u32 i = 0; i < KPROG_ARM64_STACK_TAG_SLOTS(ARM64_SIM_STACK_BYTES); ++i)
		result ^= __a64_stack_tag[i];
	return (__u32)result;
}
char LICENSE[] SEC("license") = "GPL";
