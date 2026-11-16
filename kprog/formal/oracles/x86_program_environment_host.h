/* Observe actual rendered control flow without specialization-time refusal
 * stopping the host compiler. The unresolved continuation never returns. */
#include <stdlib.h>
extern unsigned long long kprog_x86_observe_time(void);
extern void kprog_x86_observe_unresolved(void) __attribute__((noreturn));
static __attribute__((always_inline, noreturn,
    error("indirect target was not eliminated by specialization"))) inline void
__x86_sim_unresolved_indirect_target(void) { kprog_x86_observe_unresolved(); }
#if !defined(__COMPCERT__)
#define __BPF_HELPERS__ 1
#define SEC(NAME) __attribute__((section(NAME), used))
#define ORA_MAP_PTR 0x1234ULL
#define ORA_UPD_RET (-7L)
#define ORA_DEL_RET 3L
#define ORA_KTIME kprog_x86_observe_time()
#include "generated_helper_calls.h"
#endif
