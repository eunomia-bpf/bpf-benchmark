"""Native C scalar helper bodies for the checked configuration's LTO."""
from inline_array import KernelTypes, field_offset


# The kernel helper's C body for LTO, as vendor/bpf/native-helpers.h carried it
# before the performance path returned to 2026-05-29 (82ec89cb4): the task is
# read through the named helper, which native-link binds, and the null result
# keeps the helper's -EINVAL return. The one caller of pid_source is
# kprog/x86/trusted_specializer.py, which emits this translation unit alone, so
# it carries its own declaration instead of including a performance header.
PID_TGID_CODE = '''\
extern unsigned long long __kprog_bpf_get_current_task(void) __asm__("bpf_get_current_task");
__attribute__((always_inline))
unsigned long long (bpf_get_current_pid_tgid)(void) {
    const char *task = (const char *)(unsigned long)__kprog_bpf_get_current_task();
    if (!task) return (unsigned long long)-22;
    return (unsigned long long)*(const int *)(task + (TGID_OFFSET)) << 32 |
           *(const int *)(task + (PID_OFFSET));
}
'''


def pid_source(kernel_btf):
    types = KernelTypes(kernel_btf)
    try:
        task = types.lib.btf__find_by_name_kind(types.btf, b'task_struct', 4)
        pid = field_offset(types, task, 'pid')
        tgid = field_offset(types, task, 'tgid')
    finally:
        types.close()
    return (PID_TGID_CODE.replace('PID_OFFSET', str(pid))
            .replace('TGID_OFFSET', str(tgid)))
