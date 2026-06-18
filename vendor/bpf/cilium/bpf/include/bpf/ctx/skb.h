/* SPDX-License-Identifier: (GPL-2.0-only OR BSD-2-Clause) */
/* Copyright Authors of Cilium */

#pragma once

#define PROG_TYPE		"tc"

#define __ctx_buff		__sk_buff
#define __ctx_is		__ctx_skb

#include "common.h"
#include "../helpers_skb.h"

#ifndef TC_ACT_OK
# define TC_ACT_OK		0
#endif

#ifndef TC_ACT_SHOT
# define TC_ACT_SHOT		2
#endif

#ifndef TC_ACT_REDIRECT
# define TC_ACT_REDIRECT	7
#endif

#define CTX_ACT_OK		TC_ACT_OK
#define CTX_ACT_DROP		TC_ACT_SHOT
#define CTX_ACT_TX		TC_ACT_REDIRECT
#define CTX_ACT_REDIRECT	TC_ACT_REDIRECT

/* Discouraged since prologue will unclone full skb. */
#define CTX_DIRECT_WRITE_OK	0

#define META_PIVOT		field_sizeof(struct __sk_buff, cb)

#define ctx_load_bytes		skb_load_bytes
#define ctx_store_bytes		skb_store_bytes

#define ctx_adjust_hroom	skb_adjust_room

#define ctx_change_type		skb_change_type
#define ctx_change_proto	skb_change_proto
#define ctx_change_tail		skb_change_tail

#define ctx_pull_data		skb_pull_data

#define ctx_get_tunnel_key	skb_get_tunnel_key
#define ctx_set_tunnel_key	skb_set_tunnel_key

#define ctx_get_tunnel_opt	skb_get_tunnel_opt
#define ctx_set_tunnel_opt	skb_set_tunnel_opt

#define ctx_event_output	skb_event_output

#define ctx_adjust_meta		({ -ENOTSUPP; })

/* Avoid expensive calls into the kernel flow dissector if it's not an L4
 * hash. We currently only use the hash for debugging. If needed later, we
 * can map it to BPF_FUNC(get_hash_recalc) to get the L4 hash.
 *
 * bpf function get_hash_recalc from ../helpers_skb.h
 */
#define get_hash(ctx)		ctx->hash

#ifdef MICRO_NATIVE
struct __native_skb_net_device {
	__u8 __pad[224];
	int ifindex;
};
_Static_assert(__builtin_offsetof(struct __native_skb_net_device, ifindex) == 224,
	       "native net_device ifindex offset");

static __always_inline void *
ctx_data(const struct __sk_buff *ctx)
{
	return ctx->data;
}

static __always_inline void *
ctx_data_end(const struct __sk_buff *ctx)
{
	return ctx->data + (ctx->len - ctx->data_len);
}

static __always_inline void *
ctx_data_meta(const struct __sk_buff *ctx)
{
	const __u8 *shinfo = ctx->head + ctx->end;
	__u8 meta_len = *(const __u8 *)(shinfo + 1);

	return ctx->data - meta_len;
}
#else
#define DEFINE_FUNC_CTX_POINTER(FIELD)						\
static __always_inline void *							\
ctx_ ## FIELD(const struct __sk_buff *ctx)					\
{										\
	void *ptr;								\
										\
	/* LLVM may generate u32 assignments of ctx->{data,data_end,data_meta}.	\
	 * With this inline asm, LLVM loses track of the fact this field is on	\
	 * 32 bits.								\
	 */									\
	asm volatile("%0 = *(u32 *)(%1 + %2)"					\
		     : "=r"(ptr)						\
		     : "r"(ctx), "i"(offsetof(struct __sk_buff, FIELD)));	\
	return ptr;								\
}
/* This defines ctx_data(). */
DEFINE_FUNC_CTX_POINTER(data)
/* This defines ctx_data_end(). */
DEFINE_FUNC_CTX_POINTER(data_end)
/* This defines ctx_data_meta(). */
DEFINE_FUNC_CTX_POINTER(data_meta)
#undef DEFINE_FUNC_CTX_POINTER
#endif

static __always_inline __maybe_unused int
ctx_redirect(const struct __sk_buff *ctx __maybe_unused, int ifindex, __u32 flags)
{
	return redirect(ifindex, flags);
}

static __always_inline __maybe_unused int
ctx_redirect_peer(const struct __sk_buff *ctx __maybe_unused, int ifindex, __u32 flags)
{
	return redirect_peer(ifindex, flags);
}

static __always_inline __maybe_unused int
ctx_adjust_troom(struct __sk_buff *ctx, const __s32 len_diff)
{
	return skb_change_tail(ctx, ctx->len + len_diff, 0);
}

static __always_inline __maybe_unused __u64
ctx_full_len(const struct __sk_buff *ctx)
{
	return ctx->len;
}

static __always_inline __maybe_unused __u32
ctx_wire_len(const struct __sk_buff *ctx)
{
#ifdef MICRO_NATIVE
	return ctx->len;
#else
	return ctx->wire_len;
#endif
}

static __always_inline __maybe_unused void
ctx_store_meta(struct __sk_buff *ctx, const __u32 off, __u32 data)
{
	ctx->cb[off] = data;
}

static __always_inline __maybe_unused __u32
ctx_load_meta(const struct __sk_buff *ctx, const __u32 off)
{
	return ctx->cb[off];
}

static __always_inline __maybe_unused __u32
ctx_load_and_clear_meta(struct __sk_buff *ctx, const __u32 off)
{
	__u32 val = ctx_load_meta(ctx, off);

	ctx_store_meta(ctx, off, 0);
	return val;
}

static __always_inline __maybe_unused __be16
ctx_get_protocol(const struct __sk_buff *ctx)
{
	return (__be16)ctx->protocol;
}

static __always_inline __maybe_unused __u32
ctx_get_ifindex(const struct __sk_buff *ctx)
{
#ifdef MICRO_NATIVE
	if (!ctx->dev)
		return 0;
	return ((const struct __native_skb_net_device *)ctx->dev)->ifindex;
#else
	return ctx->ifindex;
#endif
}

static __always_inline __maybe_unused __u32
ctx_get_ingress_ifindex(const struct __sk_buff *ctx)
{
	return ctx->ingress_ifindex;
}

static __always_inline __maybe_unused bool
ctx_has_vlan(const struct __sk_buff *ctx)
{
#ifdef MICRO_NATIVE
	return ctx->vlan_all != 0;
#else
	return ctx->vlan_present != 0;
#endif
}

static __always_inline __maybe_unused __u32
ctx_get_vlan_tci(const struct __sk_buff *ctx)
{
	return ctx->vlan_tci;
}
