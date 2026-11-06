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
