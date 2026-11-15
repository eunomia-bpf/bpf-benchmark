/* A helper call that must remain observable after ordinary x86 compilation. */
extern unsigned long long bpf_ktime_get_ns(void);
unsigned long long clock_audit(void *context)
{
    (void)context;
    return bpf_ktime_get_ns() + 1;
}
