#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#define X86_SIM_USE_STATE_STRUCT
#define X86_SIM_STACK_BYTES 64U
#include "../../x86/x86_sim_local_bpf.h"

static unsigned visits;
unsigned long native_lab_entry_input(unsigned kind)
{
    assert(kind == NATIVE_LAB_INPUT_UNSPECIFIED);
    ++visits;
    return 0x1020304050607080UL;
}

static uint64_t observe(struct x86_sim_state *state, unsigned family,
                         unsigned mode, unsigned width)
{
    X86_SIM_L_BIND_COMMON_STATE(state);
    unsigned src=mode==0?X86_RSP:X86_RDI;
    unsigned aux=X86_MEM_AUX_FULL(mode==2?X86_RCX:X86_REG_NONE,0,width);
    uint64_t imm=mode==0?(uint64_t)-24-(uintptr_t)state->rsp.ptr:0;
    if (family==0)
        return X86_SIM_L_READ_MEM_VALUE(src,aux,imm,width,0);
    X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD,X86_RAX,src,width,aux,imm);
    return (uintptr_t)state->rax.ptr;
}

int main(void)
{
    printf("{\"cases\":[");
    unsigned count=0;
    for (unsigned family=0; family<2; ++family)
    for (unsigned released=0; released<2; ++released)
    for (unsigned width=1; width<=8; width*=2)
    for (unsigned mode=0; mode<3; ++mode) {
        struct x86_sim_state state={0};
        state.abi_kind=X86_SIM_ABI_KIND_RAW;
        state.rsp.ptr=(void *)(intptr_t)(released?-16:-32);
        state.rdi.ptr=&state.stack_mem.b[mode==2?32:40];
        state.rdi_tag=X86_SIM_TAG_STACK;
        state.rcx.ptr=(void *)8;
        state.stack_mem.q[5]=0x1122334455667788ULL;
        visits=0;
        uint64_t value=observe(&state,family,mode,width);
        printf("%s{\"family\":%u,\"released\":%u,\"width\":%u,\"address_mode\":%u,"
               "\"arena_index\":40,\"value\":\"0x%llx\",\"input_visits\":%u}",
               count++?",":"",family,released,width,mode,(unsigned long long)value,visits);
    }
    puts("]}");
    return 0;
}
