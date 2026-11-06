#ifndef KPROG_X86_NO_HELPERS_HOST_H
#define KPROG_X86_NO_HELPERS_HOST_H
#include <stdio.h>
#include <stdlib.h>
/* These runtime-opcode grids test non-helper instructions. A helper route is
 * always a failure, even when its return would alias the expected state. The
 * real ladder and its compile-error default have separate ABI/error hosts. */
#undef X86_SIM_BPF_CALL_ID
#define X86_SIM_BPF_CALL_ID(ID) do { \
    fprintf(stderr, "unexpected helper event %llu\n", (unsigned long long)(ID)); \
    abort(); \
} while (0)
#endif
