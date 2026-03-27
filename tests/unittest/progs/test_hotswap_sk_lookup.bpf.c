// SPDX-License-Identifier: GPL-2.0

#include <linux/bpf.h>
#include <linux/in.h>
#include <bpf/bpf_helpers.h>

#define AF_INET 2
#define HOTSWAP_SK_LOOKUP_PORT 41021

struct {
	__uint(type, BPF_MAP_TYPE_SOCKMAP);
	__uint(max_entries, 2);
	__type(key, __u32);
	__type(value, __u64);
} sock_map SEC(".maps");

SEC("sk_lookup")
int rejit_hotswap_sk_lookup(struct bpf_sk_lookup *ctx)
{
	struct bpf_sock *sk;
	__u32 key = 0;
	int err;

	if (ctx->family != AF_INET || ctx->protocol != IPPROTO_TCP)
		return SK_PASS;
	if (ctx->local_port != HOTSWAP_SK_LOOKUP_PORT)
		return SK_PASS;

	sk = bpf_map_lookup_elem(&sock_map, &key);
	if (!sk)
		return SK_PASS;

	err = bpf_sk_assign(ctx, sk, BPF_SK_LOOKUP_F_NO_REUSEPORT);
	bpf_sk_release(sk);
	return err ? SK_DROP : SK_PASS;
}

char LICENSE[] SEC("license") = "GPL";
