/* Callee parameters retain the public helper ABI, without an ID switch or
 * helper implementation. Invocation statements are the canonical C macros. */
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "X86Helpers.h"
#undef __x86_stack_mem
#define __x86_stack_mem (*arena)
#undef X86_SIM_STACK_BYTES
#define X86_SIM_STACK_BYTES capacity
#undef X86_SIM_L_SV_TAG
#undef X86_SIM_L_SV_PTR
#define X86_SIM_L_SV_TAG(I) (*facts[(I)].tag)
#define X86_SIM_L_SV_PTR(I) (*facts[(I)].pointer)
#undef X86_SIM_L_READ_REG_WIDTH_SHIFT
#define X86_SIM_L_READ_REG_WIDTH_SHIFT(REG, WIDTH, SHIFT) \
    kprog_x86_read_reg(state, arena, capacity, (REG), (WIDTH), (SHIFT))
static __u8 tag_of(struct x86_sim_register_state *state, __u64 reg)
{
    struct x86_sim_register_state *__x86_state = state;
    __u8 tag;
    X86_SIM_L_REG_TAG_INTO(tag, reg);
    return tag;
}
#undef X86_SIM_L_REG_TAG
#define X86_SIM_L_REG_TAG(REG) tag_of(state, (REG))

#define KPROG_X86_HELPER(ID, NAME, RESULT, ARGS) \
void kprog_x86_helper_##NAME(struct x86_sim_register_state *state, \
    struct kprog_x86_arena *arena, struct kprog_x86_stack_fact *facts, \
    __u32 capacity, RESULT (*NAME) ARGS) \
{ struct x86_sim_register_state *__x86_state = state; X86_SIM_BPF_CALL_##NAME(); }
#include "X86HelperCalls.h"
#undef KPROG_X86_HELPER
