// Catches synthetic flavor offsets, premature query folding and bitfield reads.
#define BPF_NO_PRESERVE_ACCESS_INDEX
#include "vmlinux.h"
#ifdef CORE_LOWER
#include "core-queries.h"
#endif
struct task_struct___native_test {
    union { struct pid *thread_pid; unsigned long synthetic_padding; };
    kuid_t loginuid;
    unsigned int in_iowait:1;
    unsigned int missing_native_test;
    char comm[3];
};
enum bpf_map_type___native_test {
    BPF_MAP_TYPE_ARRAY___native_test = 777,
    BPF_MAP_TYPE_ABSENT___native_test = 888,
};
static struct task_struct actual;

int main(void)
{
    actual.thread_pid = (struct pid *)0x1234;
    actual.loginuid.val = 501;
    actual.in_iowait = 1;
    actual.comm[0] = 'x';
    struct task_struct___native_test *p = (void *)&actual;
    if (!bpf_core_field_exists(p->thread_pid) || bpf_core_field_exists(p->missing_native_test))
        return 1;
    if (bpf_core_field_exists(p->missing_native_test))
        return p->missing_native_test;
    if (!bpf_core_type_exists(struct task_struct___native_test)
        || bpf_core_type_size(struct task_struct___native_test) != sizeof(actual))
        return 2;
    if (p->thread_pid != (struct pid *)0x1234 || p->loginuid.val != 501)
        return 3;
    if (p->in_iowait != 1 || p->comm[0] != 'x'
        || bpf_core_field_size(p->in_iowait) != sizeof(unsigned int)
        || bpf_core_field_size(p->comm) != sizeof(actual.comm))
        return 4;
    if (!bpf_core_enum_value_exists(enum bpf_map_type___native_test, BPF_MAP_TYPE_ARRAY___native_test)
        || bpf_core_enum_value_exists(enum bpf_map_type___native_test, BPF_MAP_TYPE_ABSENT___native_test))
        return 5;
    if (bpf_core_enum_value(enum bpf_map_type___native_test, BPF_MAP_TYPE_ARRAY___native_test) != BPF_MAP_TYPE_ARRAY)
        return 6;
    if (bpf_core_enum_value_exists(enum bpf_map_type___native_test, BPF_MAP_TYPE_ABSENT___native_test))
        return bpf_core_enum_value(enum bpf_map_type___native_test, BPF_MAP_TYPE_ABSENT___native_test);
    return 0;
}
