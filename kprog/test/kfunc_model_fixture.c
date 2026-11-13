extern int bpf_strnstr(const char *, const char *, unsigned long) __attribute__((weak));
extern int kprog_missing_function(unsigned long) __attribute__((weak));
struct bpf_iter_num { unsigned long opaque; };
extern int bpf_iter_num_new(struct bpf_iter_num *, int, int) __attribute__((weak));
extern int *bpf_iter_num_next(struct bpf_iter_num *) __attribute__((weak));
extern void bpf_iter_num_destroy(struct bpf_iter_num *) __attribute__((weak));

long entry(void *context)
{
    int result = 7;
    if (bpf_strnstr)
        result = bpf_strnstr((const char *)0, (const char *)0, 0);
    if (kprog_missing_function)
        result += kprog_missing_function(0);
    return result;
}

long iterator(void *context)
{
    if (!bpf_iter_num_new || !bpf_iter_num_next || !bpf_iter_num_destroy)
        return 7;
    struct bpf_iter_num iterator;
    bpf_iter_num_new(&iterator, 0, 3);
    int *value = bpf_iter_num_next(&iterator);
    int result = value ? *value : 0;
    bpf_iter_num_destroy(&iterator);
    return result;
}
