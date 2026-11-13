/* One signed32 clip idiom, over arbitrary inputs, through the real simulator. */
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_STACK_BYTES 64U
#include "kprog/x86/x86_sim_local_bpf.h"
#undef NATIVE_LAB_ENTRY_INPUT
#define NATIVE_LAB_ENTRY_INPUT(KIND) 0UL

#if !defined(__bpf__) && !defined(__BPF__)
#include <stdio.h>
static unsigned observed_length;
#define bpf_probe_read(DST, SIZE, SRC) (observed_length=(SIZE), 0)
#endif

SEC("kprobe/signed_bound")
int signed_bound(void *ctx)
{
    X86_SIM_ENTRY_RAW(ctx);
    __x86_rsp.ptr=(void *)-64;
    X86_SIM_L_WRITE_REG_WIDTH(X86_RBP, *(volatile __u64 *)ctx, X86_WIDTH_32);
    X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
    if (X86_SIM_L_EVAL_CC(X86_CC_LE)) return 0;
    X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 40);
    X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 40);
    X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RDX, X86_WIDTH_32, X86_CC_GE);
    __x86_rdi.ptr=X86_SIM_L_STACK_PTR(-64); __x86_rdi_tag=X86_SIM_TAG_STACK;
    X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
    X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 0);
    X86_SIM_BPF_CALL_bpf_probe_read();
    return 0;
}

#if !defined(__bpf__) && !defined(__BPF__)
int main(void)
{
    const __u32 edges[]={0,1,39,40,41,0x7fffffffU,0x80000000U,0xffffffffU};
    unsigned cases=0;
    for (unsigned high=0;high<2;++high) for (unsigned i=0;i<sizeof(edges)/sizeof(edges[0]);++i) {
        __u64 input=((__u64)high*0xdeadbeefULL<<32)|edges[i];
        observed_length=0;
        signed_bound(&input);
        unsigned expected=(__s32)edges[i]<=0 ? 0 : edges[i]<40 ? edges[i] : 40;
        if (observed_length!=expected) { printf("signed-bound mismatch %u/%u\n",high,i); return 1; }
        ++cases;
    }
    printf("signed-bound semantics PASS: %u signed edges and high-word variants\n",cases);
    return 0;
}
#else
char LICENSE[] SEC("license")="GPL";
#endif
