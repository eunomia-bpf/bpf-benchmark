#include "helpers_fixture.c"
static u64 (*pid_tgid)(void) = (void *)14;
u64 pid_probe_entry(const u64 *src) {
    u64 value=0;
    long rc=read_kernel(&value,8,src);
    return pid_tgid()+rc+(rc?0:value);
}
