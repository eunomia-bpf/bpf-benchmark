/* SPDX-License-Identifier: (GPL-2.0-only OR BSD-2-Clause) */
/* Copyright Authors of Cilium */

#pragma once

#include <linux/bpf.h>

#include "ctx/ctx.h"
#include "compiler.h"

#ifndef BPF_FUNC
# define BPF_FUNC(NAME, ...)						\
	(* NAME)(__VA_ARGS__) __maybe_unused = (void *)BPF_FUNC_##NAME
#endif

#ifndef BPF_STUB
# define BPF_STUB(NAME, ...)						\
	(* NAME##__stub)(__VA_ARGS__) __maybe_unused = (void *)((__u32)-1)
#endif

#ifndef BPF_FUNC_REMAP
# define BPF_FUNC_REMAP(NAME, ...)					\
	(* NAME)(__VA_ARGS__) __maybe_unused
#endif

#ifdef MICRO_NATIVE
static __always_inline unsigned long __native_helper_id(unsigned long id)
{
	asm volatile("" : "+r"(id) :: "memory");
	return id;
}

#define __native_bpf_helper(NAME, ID)					\
	((__typeof__(NAME))__native_helper_id((unsigned long)(ID)))

#define map_lookup_elem(...)						\
	__native_bpf_helper(map_lookup_elem, BPF_FUNC_map_lookup_elem)(__VA_ARGS__)
#define map_update_elem(...)						\
	__native_bpf_helper(map_update_elem, BPF_FUNC_map_update_elem)(__VA_ARGS__)
#define map_delete_elem(...)						\
	__native_bpf_helper(map_delete_elem, BPF_FUNC_map_delete_elem)(__VA_ARGS__)
#define map_lookup_percpu_elem(...)					\
	__native_bpf_helper(map_lookup_percpu_elem, BPF_FUNC_map_lookup_percpu_elem)(__VA_ARGS__)
#define for_each_map_elem(...)						\
	__native_bpf_helper(for_each_map_elem, BPF_FUNC_for_each_map_elem)(__VA_ARGS__)
#define ktime_get_ns()							\
	__native_bpf_helper(ktime_get_ns, BPF_FUNC_ktime_get_ns)()
#define ktime_get_boot_ns()						\
	__native_bpf_helper(ktime_get_boot_ns, BPF_FUNC_ktime_get_boot_ns)()
#define jiffies64()							\
	__native_bpf_helper(jiffies64, BPF_FUNC_jiffies64)()
#define get_socket_cookie(...)						\
	__native_bpf_helper(get_socket_cookie, BPF_FUNC_get_socket_cookie)(__VA_ARGS__)
#define get_netns_cookie(...)						\
	__native_bpf_helper(get_netns_cookie, BPF_FUNC_get_netns_cookie)(__VA_ARGS__)
#define get_cgroup_classid()						\
	__native_bpf_helper(get_cgroup_classid, BPF_FUNC_get_cgroup_classid)()
#define trace_printk(...)						\
	__native_bpf_helper(trace_printk, BPF_FUNC_trace_printk)(__VA_ARGS__)
#define get_prandom_u32()						\
	__native_bpf_helper(get_prandom_u32, BPF_FUNC_get_prandom_u32)()
#define csum_diff_external(...)						\
	__native_bpf_helper(csum_diff_external, BPF_FUNC_csum_diff)(__VA_ARGS__)
#define tail_call(...)							\
	__native_bpf_helper(tail_call, BPF_FUNC_tail_call)(__VA_ARGS__)
#define get_smp_processor_id()						\
	__native_bpf_helper(get_smp_processor_id, BPF_FUNC_get_smp_processor_id)()
#define fib_lookup(...)							\
	__native_bpf_helper(fib_lookup, BPF_FUNC_fib_lookup)(__VA_ARGS__)
#define sk_lookup_tcp(...)						\
	__native_bpf_helper(sk_lookup_tcp, BPF_FUNC_sk_lookup_tcp)(__VA_ARGS__)
#define sk_lookup_udp(...)						\
	__native_bpf_helper(sk_lookup_udp, BPF_FUNC_sk_lookup_udp)(__VA_ARGS__)
#define get_socket_opt(...)						\
	__native_bpf_helper(get_socket_opt, BPF_FUNC_getsockopt)(__VA_ARGS__)
#define set_socket_opt(...)						\
	__native_bpf_helper(set_socket_opt, BPF_FUNC_setsockopt)(__VA_ARGS__)
#define get_current_cgroup_id()						\
	__native_bpf_helper(get_current_cgroup_id, BPF_FUNC_get_current_cgroup_id)()
#define set_retval(...)							\
	__native_bpf_helper(set_retval, BPF_FUNC_set_retval)(__VA_ARGS__)
#define loop(...)							\
	__native_bpf_helper(loop, BPF_FUNC_loop)(__VA_ARGS__)
#define ringbuf_reserve(...)						\
	__native_bpf_helper(ringbuf_reserve, BPF_FUNC_ringbuf_reserve)(__VA_ARGS__)
#define ringbuf_submit(...)						\
	__native_bpf_helper(ringbuf_submit, BPF_FUNC_ringbuf_submit)(__VA_ARGS__)
#define ringbuf_discard(...)						\
	__native_bpf_helper(ringbuf_discard, BPF_FUNC_ringbuf_discard)(__VA_ARGS__)
#define redirect(...)							\
	__native_bpf_helper(redirect, BPF_FUNC_redirect)(__VA_ARGS__)
#define redirect_peer(...)						\
	__native_bpf_helper(redirect_peer, BPF_FUNC_redirect_peer)(__VA_ARGS__)
#define clone_redirect(...)						\
	__native_bpf_helper(clone_redirect, BPF_FUNC_clone_redirect)(__VA_ARGS__)
#define skb_load_bytes(...)						\
	__native_bpf_helper(skb_load_bytes, BPF_FUNC_skb_load_bytes)(__VA_ARGS__)
#define skb_store_bytes(...)						\
	__native_bpf_helper(skb_store_bytes, BPF_FUNC_skb_store_bytes)(__VA_ARGS__)
#define skb_adjust_room(...)						\
	__native_bpf_helper(skb_adjust_room, BPF_FUNC_skb_adjust_room)(__VA_ARGS__)
#define skb_change_type(...)						\
	__native_bpf_helper(skb_change_type, BPF_FUNC_skb_change_type)(__VA_ARGS__)
#define skb_change_proto(...)						\
	__native_bpf_helper(skb_change_proto, BPF_FUNC_skb_change_proto)(__VA_ARGS__)
#define skb_change_tail(...)						\
	__native_bpf_helper(skb_change_tail, BPF_FUNC_skb_change_tail)(__VA_ARGS__)
#define skb_change_head(...)						\
	__native_bpf_helper(skb_change_head, BPF_FUNC_skb_change_head)(__VA_ARGS__)
#define skb_pull_data(...)						\
	__native_bpf_helper(skb_pull_data, BPF_FUNC_skb_pull_data)(__VA_ARGS__)
#define skb_get_tunnel_key(...)						\
	__native_bpf_helper(skb_get_tunnel_key, BPF_FUNC_skb_get_tunnel_key)(__VA_ARGS__)
#define skb_set_tunnel_key(...)						\
	__native_bpf_helper(skb_set_tunnel_key, BPF_FUNC_skb_set_tunnel_key)(__VA_ARGS__)
#define skb_get_tunnel_opt(...)						\
	__native_bpf_helper(skb_get_tunnel_opt, BPF_FUNC_skb_get_tunnel_opt)(__VA_ARGS__)
#define skb_set_tunnel_opt(...)						\
	__native_bpf_helper(skb_set_tunnel_opt, BPF_FUNC_skb_set_tunnel_opt)(__VA_ARGS__)
#define skb_event_output(...)						\
	__native_bpf_helper(skb_event_output, BPF_FUNC_perf_event_output)(__VA_ARGS__)
#define skc_lookup_tcp(...)						\
	__native_bpf_helper(skc_lookup_tcp, BPF_FUNC_skc_lookup_tcp)(__VA_ARGS__)
#define sk_release(...)							\
	__native_bpf_helper(sk_release, BPF_FUNC_sk_release)(__VA_ARGS__)
#define sk_assign(...)							\
	__native_bpf_helper(sk_assign, BPF_FUNC_sk_assign)(__VA_ARGS__)
#define xdp_adjust_meta(...)						\
	__native_bpf_helper(xdp_adjust_meta, BPF_FUNC_xdp_adjust_meta)(__VA_ARGS__)
#define xdp_adjust_head(...)						\
	__native_bpf_helper(xdp_adjust_head, BPF_FUNC_xdp_adjust_head)(__VA_ARGS__)
#define xdp_adjust_tail(...)						\
	__native_bpf_helper(xdp_adjust_tail, BPF_FUNC_xdp_adjust_tail)(__VA_ARGS__)
#define xdp_get_buff_len(...)						\
	__native_bpf_helper(xdp_get_buff_len, BPF_FUNC_xdp_get_buff_len)(__VA_ARGS__)
#define xdp_event_output(...)						\
	__native_bpf_helper(xdp_event_output, BPF_FUNC_perf_event_output)(__VA_ARGS__)
#define sock_event_output(...)						\
	__native_bpf_helper(sock_event_output, BPF_FUNC_perf_event_output)(__VA_ARGS__)
#endif

#if __ctx_is == __ctx_skb
# include "helpers_skb.h"
#else
# include "helpers_xdp.h"
#endif

/* Map access/manipulation */
static void *BPF_FUNC(map_lookup_elem, const void *map, const void *key);
static int BPF_FUNC(map_update_elem, const void *map, const void *key,
		    const void *value, __u32 flags);
static int BPF_FUNC(map_delete_elem, const void *map, const void *key);
static void *BPF_FUNC(map_lookup_percpu_elem, void *map, const void *key,
				unsigned int cpu);
static long BPF_FUNC(for_each_map_elem, void *map, void *callback_fn,
		     void *callback_ctx, __u64 flags);

/* Time access */
static __u64 BPF_FUNC(ktime_get_ns);
static __u64 BPF_FUNC(ktime_get_boot_ns);
static __u64 BPF_FUNC(jiffies64);

/* We have cookies! ;-) */
static __sock_cookie BPF_FUNC(get_socket_cookie, void *ctx);
static __net_cookie BPF_FUNC(get_netns_cookie, void *ctx);

/* Legacy cgroups */
static __u32 BPF_FUNC(get_cgroup_classid);

/* Debugging */
static __printf(1, 3) void
BPF_FUNC(trace_printk, const char *fmt, int fmt_size, ...);

/* Random numbers */
static __u32 BPF_FUNC(get_prandom_u32);

/* Checksumming */
static int BPF_FUNC_REMAP(csum_diff_external, const void *from, __u32 size_from,
			  const void *to, __u32 size_to, __u32 seed) =
	(void *)BPF_FUNC_csum_diff;

/* Tail calls */
static void BPF_FUNC(tail_call, void *ctx, const void *map, __u32 index);

/* System helpers */
static __u32 BPF_FUNC(get_smp_processor_id);

/* Padded struct so the dmac at the end can be passed to another helper
 * e.g. as a map value buffer. Otherwise verifier will trip over it with
 * 'invalid indirect read from stack off'.
 */
struct bpf_fib_lookup_padded {
	struct bpf_fib_lookup l;
	__u8 pad[2];
};

/* Routing helpers */
static int BPF_FUNC(fib_lookup, void *ctx, struct bpf_fib_lookup *params,
		    __u32 plen, __u32 flags);

/* Socket lookup helpers */
static struct bpf_sock *BPF_FUNC(sk_lookup_tcp, void *ctx,
				 struct bpf_sock_tuple *tuple, __u32 tuple_size,
				 __u64 netns, __u64 flags);
static struct bpf_sock *BPF_FUNC(sk_lookup_udp, void *ctx,
				 struct bpf_sock_tuple *tuple, __u32 tuple_size,
				 __u64 netns, __u64 flags);

/* Socket helpers, misc */
/* Remapped name to avoid clash with getsockopt(2) when included from
 * regular applications.
 */
static int BPF_FUNC_REMAP(get_socket_opt, void *ctx, int level, int optname,
			  void *optval, int optlen) =
	(void *)BPF_FUNC_getsockopt;
static int BPF_FUNC_REMAP(set_socket_opt, void *ctx, int level, int optname,
			  void *optval, int optlen) =
	(void *)BPF_FUNC_setsockopt;

static __u64 BPF_FUNC(get_current_cgroup_id);

static int BPF_FUNC(set_retval, int retval);

static inline int try_set_retval(int retval __maybe_unused)
{
#ifdef HAVE_SET_RETVAL
	return set_retval(retval);
#else
	return 0;
#endif
}

static long BPF_FUNC(loop, __u32 nr_loops, void *callback_fn, void *callback_ctx, __u64 flags);

static void *BPF_FUNC(ringbuf_reserve, void *ringbuf, __u64 size, __u64 flags);
static void BPF_FUNC(ringbuf_submit, void *data, __u64 flags);
static void BPF_FUNC(ringbuf_discard, void *data, __u64 flags);
