/* Native byte fidelity for all three void forms and typed scalar/pointer calls. */
#define X86_SIM_ENABLE_STACK 1
#include "../../x86/x86_sim_local_bpf.h"

SEC("socket") int x86_helpers_compile(struct __sk_buff *ctx)
{
	X86_SIM_ENTRY_RAW(ctx);
	__x86_rsi.ptr=(void *)(long)ctx->mark;
	X86_SIM_BPF_CALL_bpf_ringbuf_submit();
	__x86_rdi.ptr=(void *)ctx;
	__x86_rsi.ptr=(void *)(long)ctx->priority;
	X86_SIM_BPF_CALL_bpf_ringbuf_submit_dynptr();
	__x86_rdi.ptr=(void *)ctx;
	__x86_rsi.ptr=(void *)(long)ctx->hash;
	X86_SIM_BPF_CALL_bpf_ringbuf_discard_dynptr();
	X86_SIM_BPF_CALL_bpf_ktime_get_ns();
	__x86_rbx.ptr=__x86_rax.ptr;
	__x86_rdi.ptr=(void *)ctx;
	__x86_rsi.ptr=(void *)ctx;
	X86_SIM_BPF_CALL_bpf_map_lookup_elem();
	return (__u32)((__u64)(long)__x86_rax.ptr^(__u64)(long)__x86_rbx.ptr);
}
char LICENSE[] SEC("license")="GPL";
