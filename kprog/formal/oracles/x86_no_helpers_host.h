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
/* Independent fixture representation bridge, not an instruction model.
 * These route grids bind native entry SP to zero. A STACK-tag cell stores a
 * private pointer; scalar arithmetic observes its displacement from the
 * allocated frame's top. No production read/projection macro is called. */
static inline __u64 kprog_x86_host_native_cell(__u64 raw, __u8 tag,
                                             unsigned reg, __u64 arena_top)
{
    return reg != X86_RSP && tag == X86_SIM_TAG_STACK ? raw - arena_top : raw;
}
#define X86_HOST_NATIVE_REG(REG) \
    kprog_x86_host_native_cell(mreg[(REG)], mtag[(REG)], (REG), model_arena_top)
#endif
