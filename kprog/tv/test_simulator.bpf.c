#include <linux/bpf.h>
#include <bpf/bpf_helpers.h>

#ifndef TV_MAP_MAX_ENTRIES
#define TV_MAP_MAX_ENTRIES 1
#endif
#ifndef TV_MAP_VALUE_SIZE
#define TV_MAP_VALUE_SIZE 4
#endif
struct {
    __uint(type, BPF_MAP_TYPE_ARRAY);
    __uint(max_entries, TV_MAP_MAX_ENTRIES);
    __uint(key_size, 4);
    __uint(value_size, TV_MAP_VALUE_SIZE);
} tv_map SEC(".maps");

struct {
    __uint(type, BPF_MAP_TYPE_HASH);
    __uint(max_entries, 1);
    __type(key, int);
    __type(value, int);
} tv_hash_map SEC(".maps");

SEC("xdp") int tv_proof_helper(struct xdp_md *ctx)
{
    (void)ctx;
    (void)bpf_get_prandom_u32();
    return 2;
}

SEC("xdp") int tv_proof_map(struct xdp_md *ctx)
{
    int key = 0;
    (void)ctx;
    int *value = bpf_map_lookup_elem(&tv_map, &key);
    return value ? *value : 0;
}

SEC("xdp") int tv_proof_hash(struct xdp_md *ctx)
{
    int key = 0;
    (void)ctx;
    int *value = bpf_map_lookup_elem(&tv_hash_map, &key);
    return value ? *value : 0;
}

char LICENSE[] SEC("license") = "GPL";

static volatile int private_zero;
SEC("xdp") int tv_proof_private(struct xdp_md *ctx)
{
    (void)ctx;
    return private_zero == 0 ? 2 : 0;
}

#ifndef TV_READONLY_WORD
#define TV_READONLY_WORD 0x1122334400000002ULL
#endif
static const __u64 tv_readonly_data[2] = {TV_READONLY_WORD, 0xaabbccdd00000000ULL};
SEC("xdp") int tv_proof_readonly_source(struct xdp_md *ctx)
{
    (void)ctx;
    const volatile __u64 *data = tv_readonly_data;
    return (__u32)(data[0] + data[1]);
}

static const __u64 tv_private_readonly_data[2] SEC(".rodata.native.0") = {
    TV_READONLY_WORD, 0xaabbccdd00000000ULL,
};
static const __u64 tv_private_a[2] SEC(".rodata.native.1") = {
    TV_READONLY_WORD, 0xaabbccdd00000000ULL,
};
static const __u64 tv_private_b[2] SEC(".rodata.native.2") = {
    TV_READONLY_WORD, 0xaabbccdd00000000ULL,
};
static const char tv_readonly_metadata[] SEC(".native_lab.rodata") =
    "{\"version\":1,\"objects\":[{\"proof_section\":\".rodata.native.0\","
    "\"proof_symbol\":\"tv_private_readonly_data\",\"native_symbol\":\"tv_readonly_data\",\"size\":16},"
    "{\"proof_section\":\".rodata.native.1\",\"proof_symbol\":\"tv_private_a\",\"native_symbol\":\"tv_readonly_a\",\"size\":16},"
    "{\"proof_section\":\".rodata.native.2\",\"proof_symbol\":\"tv_private_b\",\"native_symbol\":\"tv_readonly_b\",\"size\":16}]}";
SEC("xdp") int tv_proof_readonly(struct xdp_md *ctx)
{
    (void)ctx;
    const volatile __u64 *data = tv_private_readonly_data;
    return (__u32)(data[0] + data[1]);
}

SEC("xdp") int tv_proof_duplicate_readonly(struct xdp_md *ctx)
{
    (void)ctx;
    const volatile __u64 *a = tv_private_a, *b = tv_private_b;
    return ((__u32)(a[0] + a[1]) + (__u32)(b[0] + b[1])) >> 1;
}

/* Same 15-byte name, type and bytecode; full BTF entry identifies the source. */
SEC("xdp") int tv_collision_entry_alpha(struct xdp_md *ctx)
{
    (void)ctx;
    return 2;
}

SEC("xdp") int tv_collision_entry_beta(struct xdp_md *ctx)
{
    (void)ctx;
    return 2;
}
