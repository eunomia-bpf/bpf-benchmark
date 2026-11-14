/* Reachable fault behavior must survive compiling a checked simulator copy. */
#include "kprog/x86/x86_sim_local_bpf.h"

int architectural_fault(unsigned value)
{
    if (!value) X86_SIM_L_ARCHITECTURAL_FAULT();
    return value + 3;
}

int dispatch_fault(unsigned value)
{
    if (!value) {
        __asm__ volatile("call -1" ::: "r0", "r1", "r2", "r3", "r4", "r5", "memory");
        __builtin_unreachable();
    }
    return value + 3;
}

#ifdef UNKNOWN_ASM
int unknown_asm(void)
{
    __asm__ volatile("unsupported simulator fault marker" ::: "memory");
    return 0;
}
#endif
