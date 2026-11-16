/* Canonical simulator C. Edit directly; export the Lean AST with clightgen. */
#ifndef KPROG_FORMAL_GENERATED_X86_MEM_ACCESS_H
#define KPROG_FORMAL_GENERATED_X86_MEM_ACCESS_H
#include "../c/Platform.h"
/* Each guest access keeps its native width and executes exactly once. The
 * host types permit unaligned accesses and aliasing; BPF asm prevents LLVM
 * splitting an unaligned wide operation into multiple byte operations. */
typedef unsigned char kprog_x86_unaligned8 __attribute__((aligned(1),may_alias));
typedef unsigned short kprog_x86_unaligned16 __attribute__((aligned(1),may_alias));
typedef unsigned int kprog_x86_unaligned32 __attribute__((aligned(1),may_alias));
typedef __u64 kprog_x86_unaligned64 __attribute__((aligned(1),may_alias));
#if defined(__COMPCERT__)
/* Clight scalar chunks require alignment even for aligned(1) C types.
 * The upstream alignment-1 copy preserves the complete source byte window.
 * A volatile local keeps the physical observation used before tag/choice
 * evaluation, including when the logical released value replaces it. Its
 * block is local, rather than a new volatile global or platform import. */
#define KPROG_X86_CLIGHT_LOAD_RETURN(TYPE) \
    do { volatile TYPE observed; \
         __builtin_memcpy_aligned((void *)&observed,address,sizeof(TYPE),1); \
         return observed; } while(0)
#endif
static __attribute__((always_inline)) inline __u64
kprog_x86_mem_load(const void *address, __u8 width)
{
#if defined(__bpf__) || defined(__BPF__)
    __u64 value;
#endif
    switch (width ? width : X86_WIDTH_64) {
    case X86_WIDTH_8:
#if defined(__bpf__) || defined(__BPF__)
        asm volatile("%0 = *(u8 *)(%1 + 0)" : "=r"(value) : "r"(address) : "memory");
        return (__u8)value;
#elif defined(__COMPCERT__)
        KPROG_X86_CLIGHT_LOAD_RETURN(__u8);
#else
        return *(volatile const kprog_x86_unaligned8 *)address;
#endif
    case X86_WIDTH_16:
#if defined(__bpf__) || defined(__BPF__)
        asm volatile("%0 = *(u16 *)(%1 + 0)" : "=r"(value) : "r"(address) : "memory");
        return (__u16)value;
#elif defined(__COMPCERT__)
        KPROG_X86_CLIGHT_LOAD_RETURN(__u16);
#else
        return *(volatile const kprog_x86_unaligned16 *)address;
#endif
    case X86_WIDTH_32:
#if defined(__bpf__) || defined(__BPF__)
        asm volatile("%0 = *(u32 *)(%1 + 0)" : "=r"(value) : "r"(address) : "memory");
        return (__u32)value;
#elif defined(__COMPCERT__)
        KPROG_X86_CLIGHT_LOAD_RETURN(__u32);
#else
        return *(volatile const kprog_x86_unaligned32 *)address;
#endif
    case X86_WIDTH_64:
#if defined(__bpf__) || defined(__BPF__)
        asm volatile("%0 = *(u64 *)(%1 + 0)" : "=r"(value) : "r"(address) : "memory");
        return value;
#elif defined(__COMPCERT__)
        KPROG_X86_CLIGHT_LOAD_RETURN(__u64);
#else
        return *(volatile const kprog_x86_unaligned64 *)address;
#endif
    default: KPROG_C_TRAP();
    }
}
#if defined(__COMPCERT__)
#undef KPROG_X86_CLIGHT_LOAD_RETURN
#endif
/* Preserve the context register itself: the verifier distinguishes a fixed
 * LDX offset from adding the same offset to a context pointer first.
 * Other displacements use the equivalent computed-address encoding. */
static __attribute__((always_inline)) inline __u64
kprog_x86_mem_load_fixed(const void *base, long long displacement, __u8 width)
{
#if defined(__bpf__) || defined(__BPF__)
    if (!__builtin_constant_p(displacement) || displacement < -32768 || displacement > 32767)
        return kprog_x86_mem_load((const __u8 *)base + displacement, width);
    __u64 value;
    switch (width ? width : X86_WIDTH_64) {
    case X86_WIDTH_8:
        if (displacement < 0)
            asm volatile("%0 = *(u8 *)(%1 - %2)" : "=r"(value) : "r"(base), "i"(-displacement) : "memory");
        else
            asm volatile("%0 = *(u8 *)(%1 + %2)" : "=r"(value) : "r"(base), "i"(displacement) : "memory");
        return (__u8)value;
    case X86_WIDTH_16:
        if (displacement < 0)
            asm volatile("%0 = *(u16 *)(%1 - %2)" : "=r"(value) : "r"(base), "i"(-displacement) : "memory");
        else
            asm volatile("%0 = *(u16 *)(%1 + %2)" : "=r"(value) : "r"(base), "i"(displacement) : "memory");
        return (__u16)value;
    case X86_WIDTH_32:
        if (displacement < 0)
            asm volatile("%0 = *(u32 *)(%1 - %2)" : "=r"(value) : "r"(base), "i"(-displacement) : "memory");
        else
            asm volatile("%0 = *(u32 *)(%1 + %2)" : "=r"(value) : "r"(base), "i"(displacement) : "memory");
        return (__u32)value;
    case X86_WIDTH_64:
        if (displacement < 0)
            asm volatile("%0 = *(u64 *)(%1 - %2)" : "=r"(value) : "r"(base), "i"(-displacement) : "memory");
        else
            asm volatile("%0 = *(u64 *)(%1 + %2)" : "=r"(value) : "r"(base), "i"(displacement) : "memory");
        return value;
    default: KPROG_C_TRAP();
    }
#elif defined(__COMPCERT__)
    return kprog_x86_mem_load((const __u8 *)base + displacement, width);
#else
    /* RIP-relative host fixtures carry the symbol address in displacement
     * with a scalar zero base. Form the address bits without null-pointer
     * arithmetic; the resulting load still has exactly its original width. */
    return kprog_x86_mem_load((const void *)((unsigned long)base +
                                          (unsigned long)displacement), width);
#endif
}
static __attribute__((always_inline)) inline void
kprog_x86_mem_store(void *address, __u8 width, __u64 value)
{
    switch (width ? width : X86_WIDTH_64) {
    case X86_WIDTH_8:
#if defined(__bpf__) || defined(__BPF__)
        asm volatile("*(u8 *)(%0 + 0) = %1" : : "r"(address), "r"(value) : "memory");
#elif defined(__COMPCERT__)
        KPROG_C_UNALIGNED_STORE(__u8,address,value);
#else
        *(volatile kprog_x86_unaligned8 *)address = (kprog_x86_unaligned8)value;
#endif
        return;
    case X86_WIDTH_16:
#if defined(__bpf__) || defined(__BPF__)
        asm volatile("*(u16 *)(%0 + 0) = %1" : : "r"(address), "r"(value) : "memory");
#elif defined(__COMPCERT__)
        KPROG_C_UNALIGNED_STORE(__u16,address,value);
#else
        *(volatile kprog_x86_unaligned16 *)address = (kprog_x86_unaligned16)value;
#endif
        return;
    case X86_WIDTH_32:
#if defined(__bpf__) || defined(__BPF__)
        asm volatile("*(u32 *)(%0 + 0) = %1" : : "r"(address), "r"(value) : "memory");
#elif defined(__COMPCERT__)
        KPROG_C_UNALIGNED_STORE(__u32,address,value);
#else
        *(volatile kprog_x86_unaligned32 *)address = (kprog_x86_unaligned32)value;
#endif
        return;
    case X86_WIDTH_64:
#if defined(__bpf__) || defined(__BPF__)
        asm volatile("*(u64 *)(%0 + 0) = %1" : : "r"(address), "r"(value) : "memory");
#elif defined(__COMPCERT__)
        KPROG_C_UNALIGNED_STORE(__u64,address,value);
#else
        *(volatile kprog_x86_unaligned64 *)address = (kprog_x86_unaligned64)value;
#endif
        return;
    default: KPROG_C_TRAP();
    }
}
#define KPROG_X86_MEM_LOAD(ADDR, WIDTH) kprog_x86_mem_load((ADDR), (WIDTH))
#define KPROG_X86_MEM_LOAD_FIXED(BASE, DISP, WIDTH) kprog_x86_mem_load_fixed((BASE), (DISP), (WIDTH))
#define KPROG_X86_MEM_STORE(ADDR, WIDTH, VALUE) kprog_x86_mem_store((ADDR), (WIDTH), (VALUE))
#endif
