/* Catch binding aliases that lose helper results, clobbers or free stack facts. */
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_STACK_BYTES 64U
#include "../x86/x86_sim_local_bpf.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

static unsigned choices, calls;
unsigned long native_lab_entry_input(unsigned int kind)
{
    if (kind == 1) return 0;
    if (kind != 6) abort();
    ++choices;
    return 0;
}
static __u64 observed_clock(void) { ++calls; return 0x123456789abcdef0ULL; }
#define bpf_ktime_get_ns observed_clock
#include "../x86/x86_sim_inline.h"

int main(void)
{
    char context[8] = {0};
    X86_SIM_ENTRY_RAW(context);
    for (unsigned i=0; i<16; ++i) {
        __x86_gpr_cells[i].value.ptr=(void *)(long)(0x100+i);
        __x86_gpr_cells[i].tag=X86_SIM_TAG_SCALAR;
    }
    __x86_rsp.ptr=0;
    __x86_cf=__x86_zf=__x86_sf=__x86_of=__x86_pf=__x86_af=1;
    __x86_xmm0_lo=__x86_xmm0_hi=~0ULL;
    for (unsigned i=0; i<64; ++i) __x86_stack_mem.b[i]=0xa5;
    for (unsigned i=0; i<8; ++i) {
        X86_SIM_L_SV_TAG(i)=X86_SIM_TAG_STACK;
        X86_SIM_L_SV_PTR(i)=(void *)&__x86_stack_mem.b[i*8];
    }
    X86_SIM_BIND_INLINE();
    choices=0;
    X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_ktime_get_ns);
    assert(calls==1 && (__u64)(long)__x86_rax.ptr==0x123456789abcdef0ULL);
    for (unsigned i=1; i<16; ++i) {
        int preserved=i==X86_RBX || i==X86_RBP || i>=X86_R12;
        __u64 expected=preserved?0x100+i:0;
        assert((__u64)(long)__x86_gpr_cells[i].value.ptr==expected);
        assert(__x86_gpr_cells[i].tag==X86_SIM_TAG_SCALAR);
    }
    assert(!__x86_cf && !__x86_zf && !__x86_sf && !__x86_of && !__x86_pf && !__x86_af);
    assert(!__x86_xmm0_lo && !__x86_xmm0_hi);
    for (unsigned i=0; i<64; ++i) assert(__x86_stack_mem.b[i]==0);
    for (unsigned i=0; i<8; ++i) {
        assert(X86_SIM_L_SV_TAG(i)==X86_SIM_TAG_SCALAR);
        assert(X86_SIM_L_SV_PTR(i)==0);
    }
    printf("{\"clock_calls\":%u,\"unspecified_choices\":%u,\"stack_bytes\":64,\"full_clobber_checks\":true}\n", calls, choices);
    return 0;
}
