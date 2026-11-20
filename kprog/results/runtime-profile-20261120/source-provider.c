/* Host provider for the recognized helper in P. Its native counterpart is
 * the common wrapper that checked-sim-c already imports after B generation. */
extern long __kprog_probe_read_user(void *, unsigned, const void *);
extern long __kprog_probe_read_kernel(void *, unsigned, const void *);
long bpf_probe_read_user(void *dst, unsigned size, const void *src)
{
    return __kprog_probe_read_user(dst,size,src);
}
long bpf_probe_read_kernel(void *dst, unsigned size, const void *src)
{
    return __kprog_probe_read_kernel(dst,size,src);
}
