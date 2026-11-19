/* kernel/trace/bpf_trace.c and include/linux/bpf.h: common probe reads.
 * The kernel's nofault functions retain address policy, pagefault state,
 * SMAP, exception recovery and the user-access/NMI restrictions.
 */
extern long copy_from_user_nofault(void *, const void *, unsigned long);
extern long copy_from_kernel_nofault(void *, const void *, unsigned long);

__attribute__((always_inline))
long __kprog_probe_read_user(void *dst, unsigned size, const void *src)
{
    int ret = copy_from_user_nofault(dst, src, size);
    if (ret < 0)
        __builtin_memset(dst, 0, size);
    return ret;
}

__attribute__((always_inline))
long __kprog_probe_read_kernel(void *dst, unsigned size, const void *src)
{
    int ret = copy_from_kernel_nofault(dst, src, size);
    if (ret < 0)
        __builtin_memset(dst, 0, size);
    return ret;
}
