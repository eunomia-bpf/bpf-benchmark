/* The native view of Katran's BPF context, force-included before every Katran
 * object. Upstream source is untouched; only what its headers declare changes.
 *
 * Katran's bpf.h (katran/lib/linux_includes/bpf.h) declares struct xdp_md and
 * struct __sk_buff as the __u32 *mirrors* that the verifier rewrites into
 * 64-bit loads and into fields elsewhere in the kernel object. Compiled to x86
 * the program is handed the kernel object itself, so the mirror's fields have
 * to be read where the JIT would have read them:
 *
 *   xdp_md.data      -> (u64)(xdp_buff + 0)     xdp_convert_ctx_access,
 *   xdp_md.data_end  -> (u64)(xdp_buff + 8)     net/core/filter.c:10325-10340
 *   __sk_buff.len    -> (u32)(sk_buff + 112)    bpf_convert_ctx_access,
 *   __sk_buff.mark   -> (u32)(sk_buff + 168)    net/core/filter.c:9762,9813
 *   __sk_buff.data   -> (u64)(sk_buff + 208)    net/core/filter.c:9899
 *   __sk_buff.data_end -> (u64)(sk_buff->cb + 40) = (u64)(sk_buff + 80)
 *       bpf_convert_ctx_access expands data_end to offsetof(sk_buff, cb) +
 *       offsetof(bpf_skb_data_end, data_end) (net/core/filter.c:9917); for
 *       BPF_PROG_TYPE_SCHED_CLS the caller is cls_bpf.c:100, which enters the
 *       program through bpf_prog_run_data_pointers() (include/linux/filter.h:906),
 *       and that fills cb->data_end = skb->data + skb_headlen(skb) first. The
 *       sk_skb expansion (skb->data + len - data_len) is a different program
 *       type and is not what these programs see.
 *
 * The offsets are this kernel's, read from its own BTF
 * (`bpftool btf dump file build-x86/vmlinux format raw`): struct xdp_buff
 * size=56 with data 0, data_end 8, data_meta 16, data_hard_start 24, rxq 32,
 * txq 40, frame_sz|flags 48; struct sk_buff size=232 with cb 40, len 112,
 * mark 168, protocol 180, head 200, data 208.
 */
#ifndef KATRAN_COMPAT_H
#define KATRAN_COMPAT_H

/* Take the upstream header's constants, enums and helper declarations, but let
 * its two mirror structs and the two accessors built on them land under private
 * names: the physical layout is supplied below instead. The header's other
 * declarations name the context as `void*`, so the tags do not appear in them.
 */
#define xdp_md __katran_uapi_xdp_md
#define __sk_buff __katran_uapi_sk_buff
#define katran_skb_data __katran_uapi_skb_data
#define katran_skb_data_end __katran_uapi_skb_data_end
#include "katran/lib/linux_includes/bpf.h"
#undef xdp_md
#undef __sk_buff
#undef katran_skb_data
#undef katran_skb_data_end

/* Katran's bpf_helpers.h declares helpers as pointer variables named like the
 * helpers. The ones Katran calls land under private names here, so the calls
 * reach the common helpers by name (native-helpers.h). */
#define bpf_map_lookup_elem __katran_ptr_bpf_map_lookup_elem
#define bpf_map_update_elem __katran_ptr_bpf_map_update_elem
#define bpf_csum_diff __katran_ptr_bpf_csum_diff
#define bpf_skb_adjust_room __katran_ptr_bpf_skb_adjust_room
#define bpf_tail_call __katran_ptr_bpf_tail_call
#define bpf_redirect __katran_ptr_bpf_redirect
#define bpf_ktime_get_ns __katran_ptr_bpf_ktime_get_ns
#define bpf_get_smp_processor_id __katran_ptr_bpf_get_smp_processor_id
#define bpf_xdp_adjust_tail __katran_ptr_bpf_xdp_adjust_tail
#define bpf_xdp_adjust_head __katran_ptr_bpf_xdp_adjust_head
#define bpf_trace_printk __katran_ptr_bpf_trace_printk
#define bpf_skb_set_tunnel_key __katran_ptr_bpf_skb_set_tunnel_key
#define bpf_perf_event_output __katran_ptr_bpf_perf_event_output
#define bpf_get_prandom_u32 __katran_ptr_bpf_get_prandom_u32
#include "katran/lib/linux_includes/bpf_helpers.h"
#undef bpf_map_lookup_elem
#undef bpf_map_update_elem
#undef bpf_csum_diff
#undef bpf_skb_adjust_room
#undef bpf_tail_call
#undef bpf_redirect
#undef bpf_ktime_get_ns
#undef bpf_get_smp_processor_id
#undef bpf_xdp_adjust_tail
#undef bpf_xdp_adjust_head
#undef bpf_trace_printk
#undef bpf_skb_set_tunnel_key
#undef bpf_perf_event_output
#undef bpf_get_prandom_u32
#include "native-helpers.h"

/* struct xdp_buff: data, data_end, data_meta and data_hard_start are pointers.
 * The verifier's mirror stores them as __u32; here they keep their width. */
struct xdp_md {
  void* data;
  void* data_end;
  void* data_meta;
  void* data_hard_start;
  void* rxq;
  void* txq;
  __u32 frame_sz;
  __u32 flags;
};

_Static_assert(sizeof(struct xdp_md) == 56, "xdp_buff size");
_Static_assert(__builtin_offsetof(struct xdp_md, data) == 0, "xdp data");
_Static_assert(__builtin_offsetof(struct xdp_md, data_end) == 8, "xdp data_end");
_Static_assert(__builtin_offsetof(struct xdp_md, data_meta) == 16, "xdp data_meta");

/* The fields of struct sk_buff these programs touch, at their real offsets.
 * `data_end` is not a member of sk_buff at all: the kernel stashes it in the
 * control block a TC program is entered through (bpf_skb_data_end.data_end). */
struct __sk_buff {
  __u8 __to_cb[80];
  void* data_end;
  __u8 __to_len[24];
  __u32 len;
  __u8 __to_mark[52];
  __u32 mark;
  __u8 __to_data[36];
  void* data;
};

_Static_assert(__builtin_offsetof(struct __sk_buff, data_end) == 80, "skb data_end");
_Static_assert(__builtin_offsetof(struct __sk_buff, len) == 112, "skb len");
_Static_assert(__builtin_offsetof(struct __sk_buff, mark) == 168, "skb mark");
_Static_assert(__builtin_offsetof(struct __sk_buff, data) == 208, "skb data");

/* Same names, same signatures, same values as the upstream header's. */
static inline void* katran_skb_data(const struct __sk_buff* skb) {
  return skb->data;
}

static inline void* katran_skb_data_end(const struct __sk_buff* skb) {
  return skb->data_end;
}

#endif