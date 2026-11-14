/* Preserve native-width accesses and literal context offsets while the
 * CompCert-only representation changes. Live values keep all paths relevant. */
#include "../../arm64/arm64_sim_local_bpf.h"
SEC("socket") int arm64_access_compile(struct __sk_buff *ctx)
{
	__u64 value=((__u64)ctx->mark<<32)|ctx->priority;
	volatile __u8 bytes[64];
	for(__u32 i=0;i<64;i++) bytes[i]=(__u8)(value+i);
	__u64 result=KPROG_ARM64_LOAD_BYTES_OFFSET(ctx, __builtin_offsetof(struct __sk_buff,mark),4);
	__u8 width=(__u8)ctx->priority;
	KPROG_ARM64_STORE_BYTES(bytes+8,width,value);
	result^=KPROG_ARM64_LOAD_BYTES_OFFSET(bytes,8,width);
	result^=KPROG_ARM64_LOAD_BYTES_OFFSET(bytes+24,-8,8);
	result^=(__u64)(long)ARM64_SIM_L_LOAD_PTR_AT(bytes+24,-8);
	result^=(__u64)(long)ARM64_SIM_L_LOAD_PTR_AT(bytes,(__s64)(ctx->mark&7U));
	for(__u32 i=0;i<64;i++) result^=bytes[i];
	return (__u32)result;
}
char LICENSE[] SEC("license")="GPL";
