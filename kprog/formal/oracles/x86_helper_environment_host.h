#ifndef KPROG_X86_HELPER_ENVIRONMENT_HOST_H
#define KPROG_X86_HELPER_ENVIRONMENT_HOST_H
/* Callable public-ABI environment for host oracles. Kernel helper behavior is
 * checked in VM tests; these stubs expose identity/arguments/results to tests. */
#define __BPF_HELPERS__ 1
#define ORA_MAP_PTR 0x0000123400005678ULL
#define ORA_UPD_RET ((long)-7LL)
#define ORA_DEL_RET ((long)3LL)
#define ORA_KTIME 0xaabbccddeeff0011ULL
#include "generated_helper_calls.h"
static inline int ora_x86_armed(__u64 id)
{
    switch (id) {
    case 1ULL:
    case 2ULL:
    case 3ULL:
    case 4ULL:
    case 5ULL:
    case 6ULL:
    case 7ULL:
    case 8ULL:
    case 9ULL:
    case 10ULL:
    case 11ULL:
    case 12ULL:
    case 14ULL:
    case 15ULL:
    case 16ULL:
    case 20ULL:
    case 21ULL:
    case 23ULL:
    case 25ULL:
    case 26ULL:
    case 27ULL:
    case 28ULL:
    case 32ULL:
    case 35ULL:
    case 36ULL:
    case 37ULL:
    case 38ULL:
    case 39ULL:
    case 43ULL:
    case 44ULL:
    case 45ULL:
    case 46ULL:
    case 50ULL:
    case 54ULL:
    case 58ULL:
    case 65ULL:
    case 67ULL:
    case 68ULL:
    case 69ULL:
    case 80ULL:
    case 85ULL:
    case 86ULL:
    case 87ULL:
    case 88ULL:
    case 95ULL:
    case 99ULL:
    case 109ULL:
    case 112ULL:
    case 113ULL:
    case 114ULL:
    case 115ULL:
    case 118ULL:
    case 122ULL:
    case 124ULL:
    case 125ULL:
    case 130ULL:
    case 148ULL:
    case 152ULL:
    case 155ULL:
    case 158ULL:
    case 160ULL:
    case 173ULL:
    case 174ULL:
    case 175ULL:
    case 181ULL:
    case 184ULL:
    case 193ULL:
        return 1;
    default: return 0;
    }
}

#endif
