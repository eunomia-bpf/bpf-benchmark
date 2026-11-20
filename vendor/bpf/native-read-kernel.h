/* Kernel memory reads as plain loads for direct native. Its load-time LTO
 * (kprog/x86/perf_context_lto.cpp) replaces calls to bpf_probe_read_kernel and
 * bpf_probe_read_kernel_str with these bodies; P keeps the helper calls, so B
 * and the checked path keep the helper's exact results. The helper's address
 * rule (copy_from_kernel_nofault) holds: a source below the kernel half, a
 * null or user pointer, reads as zeros and -ERANGE without a fault. A fault at
 * another address zeroes the loaded register through its load site, the JIT's
 * PROBE_MEM behaviour. The empty asm keeps each loaded value and the source
 * address in registers. */
#ifndef VENDOR_BPF_NATIVE_READ_KERNEL_H
#define VENDOR_BPF_NATIVE_READ_KERNEL_H
#define __KPROG_READ_KERNEL_CODE \
typedef unsigned long long __attribute__((may_alias, aligned(1))) __kprog_rk_u64; \
typedef unsigned int __attribute__((may_alias, aligned(1))) __kprog_rk_u32; \
typedef unsigned short __attribute__((may_alias, aligned(1))) __kprog_rk_u16; \
long __kprog_direct_read_kernel(void *dst, unsigned int size, const void *src) { \
    char *d = dst; const char *s = src; \
    asm volatile("" : "+r"(s)); \
    if ((long)(unsigned long)s >= 0) { __builtin_memset(d, 0, size); return -34; } \
    unsigned int i = 0; \
    for (; i + 8 <= size; i += 8) { __kprog_rk_u64 v = *(const volatile __kprog_rk_u64 *)(s + i); asm volatile("" : "+r"(v)); *(__kprog_rk_u64 *)(d + i) = v; } \
    if (size & 4) { __kprog_rk_u32 v = *(const volatile __kprog_rk_u32 *)(s + i); asm volatile("" : "+r"(v)); *(__kprog_rk_u32 *)(d + i) = v; i += 4; } \
    if (size & 2) { __kprog_rk_u16 v = *(const volatile __kprog_rk_u16 *)(s + i); asm volatile("" : "+r"(v)); *(__kprog_rk_u16 *)(d + i) = v; i += 2; } \
    if (size & 1) { char v = *(const volatile char *)(s + i); asm volatile("" : "+r"(v)); d[i] = v; } \
    return 0; \
} \
long __kprog_direct_read_kernel_str(void *dst, unsigned int size, const void *src) { \
    char *d = dst; const char *s = src; \
    asm volatile("" : "+r"(s)); \
    if (!size) return 0; \
    if ((long)(unsigned long)s >= 0) { __builtin_memset(d, 0, size); return -34; } \
    unsigned int i = 0; \
    for (; i + 1 < size; i++) { char c = *(const volatile char *)(s + i); asm volatile("" : "+r"(c)); d[i] = c; if (!c) return i + 1; } \
    d[i] = 0; \
    return size; \
}
#endif
