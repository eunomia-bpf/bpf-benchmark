#ifndef KPROG_ARM64_ACCESS_BINDING_H
#define KPROG_ARM64_ACCESS_BINDING_H
#include <linux/types.h>
__u64 kprog_arm64_access_read(const void *, __s64, __u8);
void kprog_arm64_access_write(void *, __u8, __u64);
void *kprog_arm64_access_pointer(const void *, __s64);
#endif
