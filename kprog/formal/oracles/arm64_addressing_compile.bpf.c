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
	ARM64_SIM_L_MEM_WRITE(ARM64_SP,255,0,8,0,8,value,ARM64_SIM_TAG_RETURN);
	result^=ARM64_SIM_L_MEM_READ(ARM64_SP,255,0,8,0,8);
	ARM64_SIM_L_MEM_WRITE(2,255,0,0,0,4,value,ARM64_SIM_TAG_SCALAR);
	result^=ARM64_SIM_L_MEM_READ(2,255,0,0,0,4);
	result^=ARM64_SIM_L_MEM_READ(0,255,0,40,0,8);
	result^=ARM64_SIM_L_MEM_READ(0,255,0,ctx->mark&7,48,4);
	ARM64_SIM_L_WRITE_REG_PTR_TAG(3,(__u8 *)ctx+16,ARM64_SIM_TAG_RELOC_ADDR);
	result^=ARM64_SIM_L_MEM_READ(3,255,0,ctx->mark&1,0,8);
	ARM64_SIM_DIRECT_ARM64_OP_LOAD(10,0,255,255,8,0,40);
	ARM64_SIM_DIRECT_ARM64_OP_LDRSB(11,0,255,255,8,0,41);
	ARM64_SIM_DIRECT_ARM64_OP_LDRSH(12,0,255,255,4,0,42);
	ARM64_SIM_DIRECT_ARM64_OP_LDRSW(13,0,255,255,8,0,44);
	ARM64_SIM_DIRECT_ARM64_OP_STORE(2,10,255,255,8,0,8);
	result^=__a64_x10.x^__a64_x11.x^__a64_x12.x^__a64_x13.x;
	ARM64_SIM_L_WRITE_REG_WIDTH(14,value,8);
	result^=ARM64_SIM_L_READ_FAULT(14,1,aux,ctx->hash);
	ARM64_SIM_DIRECT_ARM64_OP_STP(2,10,11,255,8,aux,8);
	ARM64_SIM_DIRECT_ARM64_OP_LDP(16,17,2,255,4,aux,8);
	__a64_v0=value; __a64_v0_hi=~value;
	ARM64_SIM_L_STORE_Q0_MEM(2,255,aux,8);
	ARM64_SIM_L_LOAD_D0_MEM(2,255,aux,8);
	ARM64_SIM_L_STORE_D0_MEM(2,255,aux,8);
	ARM64_SIM_L_LOAD_Q0_MEM(2,255,aux,8);
	result^=__a64_x16.x^__a64_x17.x^__a64_v0^__a64_v0_hi;
	ARM64_SIM_L_MEM_PRE(ARM64_SP,aux,8);
	ARM64_SIM_L_MEM_POST(ARM64_SP,aux,8);
	ARM64_SIM_L_MEM_PRE(2,aux,8);
	ARM64_SIM_L_MEM_POST(2,aux,8);
	for(__u32 i=0;i<ARM64_SIM_STACK_BYTES;i++) result^=__a64_stack.b[i];
	for(__u32 i=0;i<KPROG_ARM64_STACK_WORDS(ARM64_SIM_STACK_BYTES);i++) result^=__a64_stack_tag[i]^__a64_stack_payload[i];
	return (__u32)(result^(__u64)__a64_sp^__a64_x2.x);
}
char LICENSE[] SEC("license")="GPL";
