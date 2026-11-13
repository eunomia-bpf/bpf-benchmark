// Detect lost target offsets, existence guards, enum values and bitfield shifts.
#ifdef TEST_DRIVER
#define BPF_NO_PRESERVE_ACCESS_INDEX
#include "vmlinux.h"
extern unsigned long core_ir_test(void *);
static struct task_struct task;
int main(void) {
    task.thread_pid = (struct pid *)0x1234;
    task.loginuid.val = 501;
    task.in_iowait = 1;
    task.comm[0] = 'x';
    return core_ir_test(&task) != 0;
}
#else
#include <linux/bpf.h>
#include <bpf/bpf_helpers.h>
#include <bpf/bpf_core_read.h>
struct pid;
struct task_struct___core_ir {
#ifdef LOCAL_LAYOUT_SHIFT
    unsigned long shifted;
#endif
    union { struct pid *thread_pid; unsigned long padding; };
    struct { unsigned int val; } loginuid;
    unsigned int in_iowait:1;
    unsigned int missing_core_ir;
    char comm[3];
#ifdef RESIZED_SCALAR
    long pid;
#endif
} __attribute__((preserve_access_index));
struct kprog_missing_core_ir { int x; };
enum bpf_map_type___core_ir {
    BPF_MAP_TYPE_UNSPEC___core_ir = -7,
    BPF_MAP_TYPE_ARRAY___core_ir = 777,
    BPF_MAP_TYPE_MISSING___core_ir = 888,
};
__attribute__((section("test"))) unsigned long core_ir_test(void *context) {
    struct task_struct___core_ir *p = context;
#ifdef RESIZED_SCALAR
    return p->pid;
#endif
#ifdef UNGUARDED_MISSING
    return p->missing_core_ir;
#endif
    if (!bpf_core_field_exists(p->thread_pid) || bpf_core_field_exists(p->missing_core_ir)) return 1;
    if (bpf_core_field_exists(p->missing_core_ir)) return p->missing_core_ir;
    if (!bpf_core_type_exists(struct task_struct___core_ir) || bpf_core_type_exists(struct kprog_missing_core_ir)) return 2;
    if (p->thread_pid != (struct pid *)0x1234 || p->loginuid.val != 501) return 3;
    if (bpf_core_type_size(struct task_struct___core_ir) <= sizeof(*p)) return 4;
    if (bpf_core_type_matches(struct task_struct___core_ir)) return 9;
    if (p->comm[0] != 'x' || bpf_core_field_size(p->comm) != 16) return 5;
    unsigned long bits = *(unsigned int *)((char *)p + bpf_core_field_offset(p->in_iowait));
    bits <<= __builtin_preserve_field_info(p->in_iowait, 4);
    bits >>= __builtin_preserve_field_info(p->in_iowait, 5);
    if (bits != 1 || __builtin_preserve_field_info(p->in_iowait, 3) != 0) return 6;
    if (!bpf_core_enum_value_exists(enum bpf_map_type___core_ir, BPF_MAP_TYPE_ARRAY___core_ir) ||
        bpf_core_enum_value_exists(enum bpf_map_type___core_ir, BPF_MAP_TYPE_MISSING___core_ir)) return 7;
    if (bpf_core_enum_value(enum bpf_map_type___core_ir, BPF_MAP_TYPE_ARRAY___core_ir) != 2) return 8;
    if (bpf_core_enum_value(enum bpf_map_type___core_ir, BPF_MAP_TYPE_UNSPEC___core_ir) != 0) return 10;
    if (bpf_core_enum_value_exists(enum bpf_map_type___core_ir, BPF_MAP_TYPE_MISSING___core_ir))
        return bpf_core_enum_value(enum bpf_map_type___core_ir, BPF_MAP_TYPE_MISSING___core_ir);
    return 0;
}
#endif
