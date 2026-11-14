/* Compile fidelity for actual decoded register operands and live addressing
 * flags: modifier, immediate suppression, helpers, metadata and writeback. */
#define ARM64_SIM_ENABLE_STACK 1
#include "../../arm64/arm64_sim_local_bpf.h"
SEC("socket") int arm64_addressing_compile(struct __sk_buff *ctx)
{
	ARM64_SIM_ENTRY_RAW(ctx);
	__u64 value=((__u64)ctx->mark<<32)|ctx->priority;
	for(__u32 i=0;i<ARM64_SIM_STACK_BYTES;i++) __a64_stack.b[i]=(__u8)(value+i);
	for(__u32 i=0;i<KPROG_ARM64_STACK_WORDS(ARM64_SIM_STACK_BYTES);i++) {
		__a64_stack_tag[i]=(__u8)(value+i);__a64_stack_payload[i]=value-i;
	}
	__a64_sp=-80;
	ARM64_SIM_L_WRITE_REG_WIDTH(1,value,8);
	ARM64_SIM_L_WRITE_REG_PTR_TAG(2,(void *)(long)-64,ARM64_SIM_TAG_STACK);
	__u32 aux=((ctx->mark&3U)<<24)|(1U<<16)|(ARM64_MOD_LSL<<8);
	__u64 result=ARM64_SIM_L_MOD_VALUE(1,ARM64_MOD_ROR,7,8);
	result^=(__u64)ARM64_SIM_L_MEM_BASE_OFF(aux,1,0x12345678ffffffffULL);
	result^=(__u64)(long)ARM64_SIM_L_HELPER_ARG_PTR(2);
	result^=(__u64)(long)ARM64_SIM_L_HELPER_CTX_PTR(0);
	result^=ARM64_SIM_L_MEM_READ_TAG(ARM64_SP,255,0,0,0,8);
	result^=ARM64_SIM_L_MEM_PAYLOAD(ARM64_SP,255,0,0,0,value,ARM64_SIM_TAG_STACK);
	ARM64_SIM_L_MEM_PRE(ARM64_SP,aux,8);
	ARM64_SIM_L_MEM_POST(ARM64_SP,aux,8);
	ARM64_SIM_L_MEM_PRE(2,aux,8);
	ARM64_SIM_L_MEM_POST(2,aux,8);
	for(__u32 i=0;i<ARM64_SIM_STACK_BYTES;i++) result^=__a64_stack.b[i];
	for(__u32 i=0;i<KPROG_ARM64_STACK_WORDS(ARM64_SIM_STACK_BYTES);i++) result^=__a64_stack_tag[i]^__a64_stack_payload[i];
	return (__u32)(result^(__u64)__a64_sp^__a64_x2.x);
}
char LICENSE[] SEC("license")="GPL";
