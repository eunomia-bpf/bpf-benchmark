typedef unsigned long u64;
extern u64 bpf_ktime_get_ns(void);
extern long bpf_tail_call(void *, void *, unsigned);

u64 atomic_entry(u64 *value)
{
    return __atomic_fetch_add(value, 1, __ATOMIC_SEQ_CST);
}

u64 tail_entry(void *ctx, void *map, const volatile u64 *values)
{
#define LOAD(N) u64 a##N = values[N];
    LOAD(0) LOAD(1) LOAD(2) LOAD(3) LOAD(4) LOAD(5)
    LOAD(6) LOAD(7) LOAD(8) LOAD(9) LOAD(10) LOAD(11)
#undef LOAD
    u64 time = bpf_ktime_get_ns();
    bpf_tail_call(ctx, map, (unsigned)(time & 31));
#define TERM(N) (a##N ^ (time + N))
    return TERM(0) + TERM(1) + TERM(2) + TERM(3) + TERM(4) + TERM(5)
         + TERM(6) + TERM(7) + TERM(8) + TERM(9) + TERM(10) + TERM(11);
#undef TERM
}
