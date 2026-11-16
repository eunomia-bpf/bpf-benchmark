/* Actual helper bodies over the existing caller-owned storage binding. */
#ifndef KPROG_X86_HELPERS_H
#define KPROG_X86_HELPERS_H
#include "X86Pointer.h"
#define KPROG_X86_HELPER(ID, NAME, RESULT, ARGS) \
void kprog_x86_helper_##NAME(struct x86_sim_register_state *, \
    struct kprog_x86_arena *, struct kprog_x86_stack_fact *, __u32, RESULT (*) ARGS);
#include "X86HelperCalls.h"
#undef KPROG_X86_HELPER
#endif
