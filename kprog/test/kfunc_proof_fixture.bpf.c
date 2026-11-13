#include <linux/bpf.h>
#include <bpf_helpers.h>

extern int bpf_strnstr(const char *, const char *, unsigned long) __ksym __weak;
extern int kprog_missing_function(unsigned long) __ksym __weak;

SEC("kprobe/guarded")
int guarded(void *ctx)
{
    int result = 7;
    if (bpf_strnstr)
        result += bpf_strnstr((const char *)0, (const char *)0, 0);
    if (kprog_missing_function)
        result += kprog_missing_function(0);
    return result;
}

SEC("kprobe/unguarded")
int unguarded(void *ctx)
{
    return kprog_missing_function(0);
}

char LICENSE[] SEC("license") = "GPL";
