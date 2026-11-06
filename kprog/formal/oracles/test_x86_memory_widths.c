/* Compile the production memory contract to BPF: each guest access must keep
 * its width/address and happen once, including unaligned addresses and width0. */
typedef unsigned char __u8;
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
