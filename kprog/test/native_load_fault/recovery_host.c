/* Exercise recovery routing and external-copy faults through the real bodies. */
#define X86_SIM_USE_STATE_STRUCT
#define X86_SIM_ENABLE_STACK 1
#include "../../x86/x86_sim_local_bpf.h"
#include "../../formal/oracles/x86_no_helpers_host.h"
#include <setjmp.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#undef X86_SIM_L_LIVE_XDP
#define X86_SIM_L_LIVE_XDP() 0
static __u64 choice;
static unsigned calls;
static jmp_buf fault;
#undef X86_SIM_L_UNSPECIFIED
#define X86_SIM_L_UNSPECIFIED() (calls++, choice)
#undef X86_SIM_L_ARCHITECTURAL_FAULT
#define X86_SIM_L_ARCHITECTURAL_FAULT() longjmp(fault, 1)
static int recover(struct x86_sim_state *s, unsigned base) {
    X86_SIM_L_BIND_COMMON_STATE(s);
    return X86_SIM_L_READ_RECOVERY(base, X86_RAX);
}
static int recover_mem(struct x86_sim_state *s, __s64 disp, unsigned scale) {
    X86_SIM_L_BIND_COMMON_STATE(s);
    return X86_SIM_L_READ_RECOVERY_MEM(X86_RDI, X86_RAX,
        X86_MEM_AUX(X86_RCX, scale), disp);
}
static void indexed_load(struct x86_sim_state *s) {
    X86_SIM_L_BIND_COMMON_STATE(s);
    X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI,
        X86_WIDTH_64, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_64), 0ULL);
}
static void copy(struct x86_sim_state *s, unsigned reg, unsigned count) {
    X86_SIM_L_BIND_COMMON_STATE(s);
    if (reg) X86_SIM_L_EXEC_CALL_MEMCPY_REG(count);
    else X86_SIM_L_EXEC_CALL_MEMCPY(count);
}
/* The saved-frame handler clears full GPRs and retains flags and RSP. */
static void profile(struct x86_sim_state *s, unsigned form) {
    X86_SIM_L_BIND_COMMON_STATE(s);
    switch (form) {
    case 0:
        X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI,
            X86_WIDTH_8, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
        break;
    case 1:
        X86_SIM_L_EXEC_CMOV_MEM(X86_RAX, X86_RDI, X86_WIDTH_64,
            X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) |
            X86_REG_AUX_SRC_SHIFT(X86_CC_NE), 0ULL);
        break;
    case 2:
        X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RDI, X86_WIDTH_8,
            X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
        break;
    case 3:
        X86_SIM_L_EXEC_PUSH_OP(X86_RDI, X86_WIDTH_64,
            X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) |
            X86_PUSHPOP_AUX_MEM, 0ULL);
        break;
    }
}
int main(void) {
    unsigned cases=0;
    for (unsigned base=0; base<=16; base++)
    for (unsigned tag=0; tag<8; tag++)
    for (unsigned zero=0; zero<2; zero++)
    for (choice=0; choice<2; choice++) {
        struct x86_sim_state s={0};
        unsigned reg=base==16 ? X86_REG_NONE : base;
        /* All registers share the address/tag seed; destination clearing is separate. */
#define SEED(R,N) s.N.ptr=(void *)(unsigned long)(zero?0:0x1000); s.N##_tag=tag;
        X86_SIM_L_FOR_EACH_GPR(SEED)
#undef SEED
        s.rax.ptr=(void *)0x1234;
        /* RAX is both source and destination for its own route. */
        if (reg==X86_RAX) s.rax.ptr=(void *)(unsigned long)(zero?0:0x1000);
        struct x86_sim_state expected=s;
        int scalar=reg!=X86_RSP && reg!=X86_REG_NONE && tag==X86_SIM_TAG_SCALAR;
        int result=scalar && (zero || choice);
        if(result) {expected.rax.ptr=0;expected.rax_tag=X86_SIM_TAG_SCALAR;}
        calls=0;
        if(recover(&s,reg)!=result || memcmp(&s,&expected,sizeof(s)) ||
           calls!=(unsigned)(scalar && !zero)) abort();
        cases++;
    }
    for(unsigned reg=0;reg<2;reg++)
    for(unsigned tag=0;tag<2;tag++)
    for(unsigned count=0;count<=4;count++) {
        unsigned char src[4]={1,2,3,4},dst[4]={0},expected[4]={0};
        struct x86_sim_state s={0};
        s.rdi.ptr=dst;s.rdi_tag=X86_SIM_TAG_MAP_VALUE;
        s.rsi.ptr=src;s.rsi_tag=tag?X86_SIM_TAG_MAP_VALUE:X86_SIM_TAG_SCALAR;
        s.rdx.ptr=(void *)(unsigned long)count;
        int trapped=setjmp(fault);
        if(!trapped) copy(&s,reg,count);
        if(!!trapped != (!tag && count>0)) abort();
        if(tag) memcpy(expected,src,count);
        if(memcmp(dst,expected,4)) abort();
        cases++;
    }
    for (unsigned form=0;form<4;form++)
    for (unsigned flags=0;flags<64;flags++) {
        unsigned long datum=0x12345678;
        struct x86_sim_state s={0};
        s.rdi.ptr=&datum;s.rdi_tag=X86_SIM_TAG_SCALAR;
        s.rax.ptr=(void *)~0UL;s.rax_tag=X86_SIM_TAG_MAP_VALUE;
        s.rsp.ptr=(void *)-16L;
        s.cf=flags&1;s.pf=(flags>>1)&1;s.af=(flags>>2)&1;
        s.zf=(flags>>3)&1;s.sf=(flags>>4)&1;s.of=(flags>>5)&1;
        struct x86_sim_state expected=s;
        if(form<2) {expected.rax.ptr=0;expected.rax_tag=X86_SIM_TAG_SCALAR;}
        choice=1;calls=0;profile(&s,form);
        if(calls!=1 || memcmp(&s,&expected,sizeof(s)) || datum!=0x12345678) abort();
        cases++;
    }
    const struct { __u64 base,index; unsigned scale; __s64 disp; int low; } addresses[]={
        {0,0,0,0,1},{0,16,3,-8,1},{0,4096,0,0,0},
        {0,1024,2,0,0},{4096,0,0,-1,1},{4096,0,0,0,0},
        {~0ULL,1,0,0,1},{0,0,0,-1,0},{0,0,0,4095,1},
        {0,0,0,4096,0},{0,4096,3,-28672,0},{0,4096,3,-28673,1}
    };
    for(unsigned i=0;i<sizeof(addresses)/sizeof(addresses[0]);i++)
    for(choice=0;choice<2;choice++) {
        struct x86_sim_state s={0};
        s.rdi.ptr=(void *)(unsigned long)addresses[i].base;
        s.rcx.ptr=(void *)(unsigned long)addresses[i].index;
        s.rcx_tag=X86_SIM_TAG_ABI;s.rax.ptr=(void *)1234;
        struct x86_sim_state expected=s;
        int result=addresses[i].low || choice;
        if(result) expected.rax.ptr=0;
        calls=0;
        if(recover_mem(&s,addresses[i].disp,addresses[i].scale)!=result ||
           calls!=(unsigned)!addresses[i].low || memcmp(&s,&expected,sizeof(s))) abort();
        cases++;
    }
    {
        unsigned long datum=0x1234;
        struct x86_sim_state s={0};
        s.rcx.ptr=&datum;s.rcx_tag=X86_SIM_TAG_ABI;
        choice=0;calls=0;indexed_load(&s);
        if((unsigned long)s.rax.ptr!=datum || datum!=0x1234 || calls!=1) abort();
        cases++;
    }
    printf("x86 read recovery routes and external copies: OK (%u cases)\n",cases);
    return 0;
}
