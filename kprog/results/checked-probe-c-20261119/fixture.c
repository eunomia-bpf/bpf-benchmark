#include <linux/bpf.h>
#define PROBE(ID) ((long (*)(void *, unsigned, const void *))(ID))
long user8(void *dst, const void *src) { return PROBE(BPF_FUNC_probe_read_user)(dst,8,src); }
long kernel8(void *dst, const void *src) { return PROBE(BPF_FUNC_probe_read_kernel)(dst,8,src); }
long user_dynamic(void *dst, unsigned long size, const void *src) {
    return PROBE(BPF_FUNC_probe_read_user)(dst,(unsigned)size,src);
}
long kernel_dynamic(void *dst, unsigned long size, const void *src) {
    return PROBE(BPF_FUNC_probe_read_kernel)(dst,(unsigned)size,src);
}
long compat(void *dst, unsigned size, const void *src) { return PROBE(BPF_FUNC_probe_read)(dst,size,src); }
