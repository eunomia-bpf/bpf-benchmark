/* Partial pointer writes retain the written lane's scalar bounds. */
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_STACK_BYTES 64U
#include "kprog/x86/x86_sim_local_bpf.h"
#undef NATIVE_LAB_ENTRY_INPUT
#define NATIVE_LAB_ENTRY_INPUT(KIND) 0UL
#ifndef PARTIAL_LANE
#define PARTIAL_LANE 0
#endif

#if !defined(__bpf__) && !defined(__BPF__)
#include <stdio.h>
static unsigned observed_length;
#define bpf_probe_read(DST, SIZE, SRC) (observed_length=(SIZE), 0)
#endif

SEC("kprobe/partial_reg")
int partial_reg(void *ctx)
{
    X86_SIM_ENTRY_RAW(ctx);
    __x86_rsp.ptr=(void *)-16;
    X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RDI, X86_WIDTH_64);
    X86_SIM_L_WRITE_REG_WIDTH(X86_RCX, *(volatile __u64 *)ctx, X86_WIDTH_64);
    X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 0);
#if PARTIAL_LANE == 16
    X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, X86_SIM_L_EVAL_CC(X86_CC_E), X86_WIDTH_16);
    X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
#else
    X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E | (PARTIAL_LANE << 8));
    X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBX,
        PARTIAL_LANE ? 128U+X86_RAX : X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
#endif
    X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_XOR, 9);
    __x86_rdi.ptr=X86_SIM_L_STACK_PTR(-16); __x86_rdi_tag=X86_SIM_TAG_STACK;
    X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_32);
    X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 0);
    X86_SIM_BPF_CALL_bpf_probe_read();
    return 0;
}

#if !defined(__bpf__) && !defined(__BPF__)
int main(void)
{
    unsigned cases=0;
    for (__u64 input=0; input<2; ++input) {
        observed_length=0;
        partial_reg(&input);
        if (observed_length!=(input ? 9U : 8U)) return 1;
    }
    const __u64 seeds[]={0,0x1122334455667788ULL,0xffffffffffffffffULL};
    const __u64 values[]={0,1,0x80,0xff,0x1234,0xffff,0x123456789abcdef0ULL};
    for (unsigned tag=0;tag<=X86_SIM_TAG_CODE;++tag)
        for (unsigned s=0;s<sizeof(seeds)/sizeof(seeds[0]);++s)
            for (unsigned v=0;v<sizeof(values)/sizeof(values[0]);++v) {
                union x86_sim_gpr reg={.ptr=(void *)(long)seeds[s]};
                __u8 reg_tag=tag;
#if PARTIAL_LANE == 16
                KPROG_X86_WRITE_REG16(reg,reg_tag,values[v],X86_SIM_TAG_SCALAR);
                __u64 mask=0xffffULL, lane=values[v]&mask;
#else
                KPROG_X86_WRITE_REG8(reg,reg_tag,values[v],PARTIAL_LANE,X86_SIM_TAG_SCALAR);
                __u64 mask=0xffULL<<PARTIAL_LANE, lane=(values[v]&0xffULL)<<PARTIAL_LANE;
#endif
                if ((__u64)(long)reg.ptr!=((seeds[s]&~mask)|lane) || reg_tag!=X86_SIM_TAG_SCALAR)
                    return 1;
                ++cases;
            }
    printf("partial-register lane %u PASS: %u bit/tag cases and two boolean bounds\n",PARTIAL_LANE,cases);
    return 0;
}
#else
char LICENSE[] SEC("license")="GPL";
#endif
