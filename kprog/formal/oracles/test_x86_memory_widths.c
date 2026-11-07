/* Compile the production memory contract to BPF: each guest access must keep
 * its width/address and happen once, including unaligned addresses and width0. */
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;
#define X86_WIDTH_8 1U
#define X86_WIDTH_16 2U
#define X86_WIDTH_32 4U
#define X86_WIDTH_64 8U
#include "generated/x86_width.h"
#include "generated/x86_mem_access.h"

#define ACCESS(NAME, WIDTH)                                              \
__attribute__((used,noinline)) __u64 load_##NAME(const __u8 *p)            \
{ return KPROG_X86_MEM_LOAD(p + 3, (WIDTH)); }                             \
__attribute__((used,noinline)) void store_##NAME(__u8 *p, __u64 value)      \
{ KPROG_X86_MEM_STORE(p + 3, (WIDTH), value); }

ACCESS(b8, X86_WIDTH_8)
ACCESS(b16, X86_WIDTH_16)
ACCESS(b32, X86_WIDTH_32)
ACCESS(b64, X86_WIDTH_64)
ACCESS(default, 0)

#define FIXED(NAME, WIDTH, OFFSET, SUFFIX)                                \
__attribute__((used,noinline)) __u64 fixed_##NAME##_##SUFFIX(const __u8 *p) \
{ return KPROG_X86_MEM_LOAD_FIXED(p, OFFSET, WIDTH); }
#define FIXED_WIDTH(NAME, WIDTH)                                         \
FIXED(NAME, WIDTH, 88, context)                                          \
FIXED(NAME, WIDTH, -3, negative)                                         \
FIXED(NAME, WIDTH, -32768, minimum)                                      \
FIXED(NAME, WIDTH, 32767, maximum)
FIXED_WIDTH(b8, X86_WIDTH_8)
FIXED_WIDTH(b16, X86_WIDTH_16)
FIXED_WIDTH(b32, X86_WIDTH_32)
FIXED_WIDTH(b64, X86_WIDTH_64)
FIXED_WIDTH(default, 0)

#ifdef KPROG_TEST_BAD_FIXED
__u64 bad_fixed(const __u8 *p, long long offset)
{
#if KPROG_TEST_BAD_FIXED == 1
    return KPROG_X86_MEM_LOAD_FIXED(p, offset, X86_WIDTH_32);
#elif KPROG_TEST_BAD_FIXED == 2
    return KPROG_X86_MEM_LOAD_FIXED(p, 32768, X86_WIDTH_32);
#else
    return KPROG_X86_MEM_LOAD_FIXED(p, -32769, X86_WIDTH_32);
#endif
}
#endif
