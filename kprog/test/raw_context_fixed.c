/* Direct context reads keep constant displacements in the stock BPF load. */
#include "kprog/x86/x86_sim_local_bpf.h"
#undef NATIVE_LAB_ENTRY_INPUT
#define NATIVE_LAB_ENTRY_INPUT(KIND) 0UL
#ifndef RAW_CONTEXT_READ_VALUE
#define RAW_CONTEXT_READ_VALUE 0
#endif

SEC("kprobe/raw_context")
int raw_context(void *ctx)
{
    X86_SIM_ENTRY_RAW(ctx);
    /* The actual context bits may arrive through a scalar-tagged copy. */
    __x86_rdi_tag=X86_SIM_TAG_SCALAR;
#if RAW_CONTEXT_READ_VALUE == 2
    return (__u32)KPROG_X86_MEM_LOAD_FIXED(ctx, *(volatile long long *)ctx, X86_WIDTH_64);
#elif RAW_CONTEXT_READ_VALUE == 3
    return (__u32)KPROG_X86_MEM_LOAD_FIXED(ctx, 40000, X86_WIDTH_64);
#elif RAW_CONTEXT_READ_VALUE == 4
    return (__u32)KPROG_X86_MEM_LOAD_FIXED(ctx, -40000, X86_WIDTH_64);
#elif RAW_CONTEXT_READ_VALUE == 1
    return (__u32)X86_SIM_L_READ_MEM_VALUE(X86_RDI, X86_MEM_AUX(X86_REG_NONE,0),
        80, X86_WIDTH_64, 0);
#else
    X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_64,
        X86_MEM_AUX(X86_REG_NONE,0), 80);
    return (__u32)X86_SIM_L_READ_REG(X86_RAX);
#endif
}

#if !defined(__bpf__) && !defined(__BPF__)
#include <stdio.h>
int main(void)
{
    __u64 arena[10032]={};
    unsigned char *ctx=(unsigned char *)arena+40000;
    const long displacement=RAW_CONTEXT_READ_VALUE==3 ? 40000 :
        RAW_CONTEXT_READ_VALUE==4 ? -40000 : 80;
    const __u64 values[]={0,1,0x123456789abcdef0ULL,0xffffffffffffffffULL};
    for (unsigned i=0;i<sizeof(values)/sizeof(values[0]);++i) {
        *(__u64 *)(ctx+displacement)=values[i];
        if (RAW_CONTEXT_READ_VALUE==2) *(long long *)ctx=displacement;
        if ((__u32)raw_context(ctx)!=(__u32)values[i]) return 1;
    }
    printf("raw context route %u PASS: four full-width field values\n", RAW_CONTEXT_READ_VALUE);
    return 0;
}
#else
char LICENSE[] SEC("license")="GPL";
#endif
