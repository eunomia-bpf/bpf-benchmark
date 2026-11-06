#ifndef KPROG_X86_HELPER_ENVIRONMENT_HOST_H
#define KPROG_X86_HELPER_ENVIRONMENT_HOST_H
/* Callable public-ABI environment for host oracles. Kernel helper behavior is
 * checked in VM tests; these stubs expose identity/arguments/results to tests. */
#define __BPF_HELPERS__ 1
#define ORA_MAP_PTR 0x0000123400005678ULL
#define ORA_UPD_RET ((long)-7LL)
#define ORA_DEL_RET ((long)3LL)
#define ORA_KTIME 0xaabbccddeeff0011ULL
#include "generated_x86_helper_calls.h"
#endif
