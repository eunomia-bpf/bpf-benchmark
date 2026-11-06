#include <linux/bpf.h>
#include <bpf/bpf_helpers.h>

#if TV_CONTEXT_HELPER == 25
struct {
    __uint(type, BPF_MAP_TYPE_PERF_EVENT_ARRAY);
    __uint(max_entries, 128);
    __uint(key_size, 4);
    __uint(value_size, 4);
} tv_context_map SEC(".maps");
#elif TV_CONTEXT_HELPER == 27
struct {
    __uint(type, BPF_MAP_TYPE_STACK_TRACE);
    __uint(max_entries, 8);
    __uint(key_size, 4);
    __uint(value_size, 128);
} tv_context_map SEC(".maps");
#elif TV_CONTEXT_HELPER != 67
#error unknown contextual helper fixture
#endif

SEC("fentry/bpf_fentry_test1") int tv_proof_contextual(void *ctx)
{
#if TV_CONTEXT_HELPER == 25
    unsigned long value = 0;
    (void)bpf_perf_event_output(ctx, &tv_context_map, BPF_F_CURRENT_CPU, &value, sizeof(value));
#elif TV_CONTEXT_HELPER == 27
    (void)bpf_get_stackid(ctx, &tv_context_map, 0);
#else
    unsigned long stack[2];
    (void)bpf_get_stack(ctx, stack, sizeof(stack), 0);
#endif
    return 0;
}
char LICENSE[] SEC("license") = "GPL";
