// The native object's target header comes from the sole kernel's BTF.
#define BPF_NO_PRESERVE_ACCESS_INDEX
#include "vmlinux.h"
extern int printf(const char *, ...);
int main(void)
{
    printf("{\"regs_size\":%lu,\"ctx_regs\":%lu,\"ctx_data\":%lu,"
           "\"data_period\":%lu,\"data_addr\":%lu}\n",
           sizeof(((struct bpf_perf_event_data *)0)->regs),
           __builtin_offsetof(struct bpf_perf_event_data_kern, regs),
           __builtin_offsetof(struct bpf_perf_event_data_kern, data),
           __builtin_offsetof(struct perf_sample_data, period),
           __builtin_offsetof(struct perf_sample_data, addr));
}
