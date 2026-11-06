/* Native-link inputs for the real shared-loader binding regression. */
int tv_short_entry(void *ctx)
{
	(void)ctx;
	return 2;
}

int tv_long_entry(void *ctx)
{
	(void)ctx;
	__asm__ __volatile__(".rept 80\naddq $1, %%rax\n.endr" : : : "rax", "cc");
	return 2;
}

extern unsigned long bpf_get_prandom_u32(void);
extern unsigned long bpf_ktime_get_coarse_ns(void);
extern unsigned long bpf_get_func_ip(void *ctx);

int tv_func_ip_entry(void *ctx)
{
	(void)bpf_get_func_ip(ctx);
	return 0;
}

int tv_coarse_helper_entry(void *ctx)
{
	(void)ctx;
	(void)bpf_ktime_get_coarse_ns();
	return 2;
}

int tv_helper_entry(void *ctx)
{
	(void)ctx;
	(void)bpf_get_prandom_u32();
	return 2;
}

int tv_large_entry(void *ctx)
{
	(void)ctx;
	(void)bpf_get_prandom_u32();
	return 2;
}

__attribute__((section(".maps"))) unsigned char tv_map;
extern void *bpf_map_lookup_elem(void *map, const void *key);

int tv_map_entry(void *ctx)
{
	int key = 0;
	(void)ctx;
	int *value = bpf_map_lookup_elem(&tv_map, &key);
	return value ? *value : 0;
}

__attribute__((section(".maps"))) unsigned char tv_hash_map;
int tv_hash_entry(void *ctx)
{
	int key = 0;
	(void)ctx;
	int *value = bpf_map_lookup_elem(&tv_hash_map, &key);
	return value ? *value : 0;
}

const unsigned long tv_readonly_data[2] = {
	0x1122334400000002UL, 0xaabbccdd00000000UL,
};
int tv_readonly_entry(void *ctx)
{
	(void)ctx;
	const volatile unsigned long *data = tv_readonly_data;
	return data[0] + data[1];
}

const unsigned long tv_readonly_a[2] __attribute__((section(".rodata.tv_a"))) = {
	0x1122334400000002UL, 0xaabbccdd00000000UL,
};
const unsigned long tv_readonly_b[2] __attribute__((section(".rodata.tv_b"))) = {
	0x1122334400000002UL, 0xaabbccdd00000000UL,
};
int tv_duplicate_readonly_entry(void *ctx)
{
	(void)ctx;
	const volatile unsigned long *a = tv_readonly_a, *b = tv_readonly_b;
	return ((unsigned)(a[0] + a[1]) + (unsigned)(b[0] + b[1])) >> 1;
}

/* Relocated to the exact source LDDW map-value site, including its offset. */
extern const unsigned char tv_source_value[];
__attribute__((noinline)) int tv_source_value_entry(void *ctx)
{
    (void)ctx;
    const unsigned char *address = tv_source_value;
    __asm__ volatile("" : "+r"(address));
    return address[0];
}

/* TRACING uses the kernel's raw-tracepoint helper variants, including fentry. */
__attribute__((section(".maps"))) unsigned char tv_context_map;
extern long bpf_perf_event_output(void *ctx, void *map, unsigned long flags,
                                 const void *data, unsigned long size);
extern long bpf_get_stackid(void *ctx, void *map, unsigned long flags);
extern long bpf_get_stack(void *ctx, void *buffer, unsigned long size, unsigned long flags);
int tv_perf_entry(void *ctx)
{
    unsigned long value = 0;
    (void)bpf_perf_event_output(ctx, &tv_context_map, 0xffffffffUL, &value, sizeof(value));
    return 0;
}
int tv_stackid_entry(void *ctx)
{
    (void)bpf_get_stackid(ctx, &tv_context_map, 0);
    return 0;
}
int tv_stack_entry(void *ctx)
{
    unsigned long stack[2];
    (void)bpf_get_stack(ctx, stack, sizeof(stack), 0);
    return 0;
}
