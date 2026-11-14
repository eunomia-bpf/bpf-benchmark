/* Compile fidelity: dynamic alignment/width, pointer payloads, released-byte
 * inputs, packed tags and live outputs from the canonical private stack. */
#define ARM64_SIM_ENABLE_STACK 1
#include "../../arm64/arm64_sim_local_bpf.h"
SEC("socket") int arm64_stack_compile(struct __sk_buff *ctx)
{
	ARM64_SIM_ENTRY_RAW(ctx);
	__u64 value=((__u64)ctx->mark<<32)|ctx->priority;
	for(__u32 i=0;i<ARM64_SIM_STACK_BYTES;i++) __a64_stack.b[i]=(__u8)(value+i);
	for(__u32 i=0;i<KPROG_ARM64_STACK_WORDS(ARM64_SIM_STACK_BYTES);i++) {
		__a64_stack_tag[i]=(__u8)(value+i);
		__a64_stack_payload[i]=value-i;
	}
	__a64_sp=-ARM64_SIM_STACK_BIAS;
	ARM64_SIM_L_STACK_WRITE_TAG(-64,8,value,ARM64_SIM_TAG_STACK);
	__u64 result=ARM64_SIM_L_STACK_READ(-64,8)^ARM64_SIM_L_STACK_READ_TAG(-64,8);
	__s64 off=-80+(ctx->mark&7U);
	ARM64_SIM_L_STACK_WRITE_TAG(off,8,value,ARM64_SIM_TAG_RETURN);
	result^=ARM64_SIM_L_STACK_READ(off,8)^ARM64_SIM_L_STACK_READ_TAG(off,8);
	__a64_sp=off+3;
	ARM64_SIM_L_STACK_WRITE_TAG(off,(__u8)ctx->priority,value,ARM64_SIM_TAG_MAP_VALUE);
	result^=ARM64_SIM_L_STACK_READ(off,(__u8)ctx->priority)^ARM64_SIM_L_STACK_READ_TAG(off,8);
	for(__u32 i=0;i<ARM64_SIM_STACK_BYTES;i++) result^=__a64_stack.b[i];
	for(__u32 i=0;i<KPROG_ARM64_STACK_WORDS(ARM64_SIM_STACK_BYTES);i++) result^=__a64_stack_tag[i]^__a64_stack_payload[i];
	return (__u32)result;
}
char LICENSE[] SEC("license")="GPL";
