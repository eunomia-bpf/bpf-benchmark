/* Katran's linux_includes/bpf_helpers.h declares its helpers as pointer variables named like the
 * helpers (static void (*bpf_tail_call)(...) = (void *)12). A variable named like a helper takes
 * the helper's symbol, so the ones Katran calls land under private names while that header is
 * included, and the calls reach the helpers by name through native-helpers.h (11-19's
 * katran-compat.h did the same). Force-included before every Katran object. */
#ifndef VENDOR_BPF_KATRAN_HELPERS_H
#define VENDOR_BPF_KATRAN_HELPERS_H
#include "katran/lib/linux_includes/bpf.h"
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
#endif
