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
/* Every fixed displacement takes the helper route, so reading kernel memory
 * never dereferences a computed address. The address is formed inside the
 * body, because the verifier tracks the base register and its displacement
 * separately from a pointer the caller has already advanced.
 *
 * The body is a real BPF subprogram and writes through a caller slot. A
 * callee-local destination gives the subprogram its own 8-byte frame, which
 * the verifier adds to the caller's frame rounded up to 16 inside
 * MAX_BPF_STACK when private stacks are unavailable, and a program with a
 * tail call has none: r3's 508-byte program then needs 512 + 16. The
 * caller's slot is coalesced to one for every site, so the callee adds 0.
 *
 * The C arms keep the value-returning signature the Clight export records. */
#if defined(__bpf__) || defined(__BPF__)
static __attribute__((noinline)) __u64
kprog_x86_mem_load_fixed_into(__u64 *value, const void *base,
                               long long displacement, __u8 width)
{
    const void *address=(const __u8 *)base + displacement;
    switch (width ? width : X86_WIDTH_64) {
    case X86_WIDTH_8:
        bpf_probe_read_kernel(value, sizeof(__u8), address);
        return (__u8)*value;
    case X86_WIDTH_16:
        bpf_probe_read_kernel(value, sizeof(__u16), address);
        return (__u16)*value;
    case X86_WIDTH_32:
        bpf_probe_read_kernel(value, sizeof(__u32), address);
        return (__u32)*value;
    case X86_WIDTH_64:
        bpf_probe_read_kernel(value, sizeof(__u64), address);
        return *value;
    default:
        /* KPROG_C_TRAP is illegal in BPF; this arm is unreachable for a
         * width the emitter produced. */
        __asm__ volatile("r0 = 0; exit;" ::: "r0", "memory");
        __builtin_unreachable();
    }
}
#define KPROG_X86_MEM_LOAD_FIXED(BASE, DISP, WIDTH) \
    ({ __u64 __kprog_fixed_value; \
       kprog_x86_mem_load_fixed_into(&__kprog_fixed_value, (BASE), (DISP), (WIDTH)); })
#else
static __attribute__((always_inline)) inline __u64
kprog_x86_mem_load_fixed(const void *base, long long displacement, __u8 width)
{
#if defined(__COMPCERT__)
    return kprog_x86_mem_load((const __u8 *)base + displacement, width);
#else
    /* RIP-relative host fixtures carry the symbol address in displacement
     * with a scalar zero base. Form the address bits without null-pointer
     * arithmetic; the resulting load still has exactly its original width. */
    return kprog_x86_mem_load((const void *)((unsigned long)base +
                                          (unsigned long)displacement), width);
#endif
}
#define KPROG_X86_MEM_LOAD_FIXED(BASE, DISP, WIDTH) kprog_x86_mem_load_fixed((BASE), (DISP), (WIDTH))
#endif
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
#define KPROG_X86_MEM_STORE(ADDR, WIDTH, VALUE) kprog_x86_mem_store((ADDR), (WIDTH), (VALUE))
#endif
