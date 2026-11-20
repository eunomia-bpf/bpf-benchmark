#include "../../../vendor/bpf/native-helpers.h"
#include "../../x86/micro-prog/inline_probe.c"
long user8(void *dst, const void *src) { return bpf_probe_read_user(dst,8,src); }
long user_dynamic(void *dst, unsigned long size, const void *src) {
    return bpf_probe_read_user(dst,(unsigned)size,src);
}
long kernel8(void *dst, const void *src) { return __kprog_probe_read_kernel(dst,8,src); }
long kernel_dynamic(void *dst, unsigned long size, const void *src) {
    return __kprog_probe_read_kernel(dst,(unsigned)size,src);
}
