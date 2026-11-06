/* Generated from vendored Linux helper signatures. Catches wrong helper
 * identity, argument order/width, stack projection, result or clobbered GPRs. */
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;
typedef signed long long __s64;
typedef signed int __s32;
#define __always_inline inline
#define ARM64_SIM_ENABLE_STACK 1
#define bpf_map_lookup_elem bpf_map_lookup_elem_defs
#define bpf_map_update_elem bpf_map_update_elem_defs
#define bpf_map_delete_elem bpf_map_delete_elem_defs
#define bpf_probe_read bpf_probe_read_defs
#define bpf_ktime_get_ns bpf_ktime_get_ns_defs
#define bpf_trace_printk bpf_trace_printk_defs
#define bpf_get_prandom_u32 bpf_get_prandom_u32_defs
#define bpf_get_smp_processor_id bpf_get_smp_processor_id_defs
#define bpf_skb_store_bytes bpf_skb_store_bytes_defs
#define bpf_l3_csum_replace bpf_l3_csum_replace_defs
#define bpf_l4_csum_replace bpf_l4_csum_replace_defs
#define bpf_tail_call bpf_tail_call_defs
#define bpf_clone_redirect bpf_clone_redirect_defs
#define bpf_get_current_pid_tgid bpf_get_current_pid_tgid_defs
#define bpf_get_current_uid_gid bpf_get_current_uid_gid_defs
#define bpf_get_current_comm bpf_get_current_comm_defs
#define bpf_skb_get_tunnel_key bpf_skb_get_tunnel_key_defs
#define bpf_skb_set_tunnel_key bpf_skb_set_tunnel_key_defs
#define bpf_redirect bpf_redirect_defs
#define bpf_perf_event_output bpf_perf_event_output_defs
#define bpf_skb_load_bytes bpf_skb_load_bytes_defs
#define bpf_get_stackid bpf_get_stackid_defs
#define bpf_csum_diff bpf_csum_diff_defs
#define bpf_skb_change_proto bpf_skb_change_proto_defs
#define bpf_skb_change_type bpf_skb_change_type_defs
#define bpf_skb_under_cgroup bpf_skb_under_cgroup_defs
#define bpf_get_current_task bpf_get_current_task_defs
#define bpf_probe_write_user bpf_probe_write_user_defs
#define bpf_current_task_under_cgroup bpf_current_task_under_cgroup_defs
#define bpf_skb_change_tail bpf_skb_change_tail_defs
#define bpf_skb_pull_data bpf_skb_pull_data_defs
#define bpf_skb_change_head bpf_skb_change_head_defs
#define bpf_xdp_adjust_head bpf_xdp_adjust_head_defs
#define bpf_probe_read_str bpf_probe_read_str_defs
#define bpf_get_socket_cookie bpf_get_socket_cookie_defs
#define bpf_skb_adjust_room bpf_skb_adjust_room_defs
#define bpf_xdp_adjust_meta bpf_xdp_adjust_meta_defs
#define bpf_override_return bpf_override_return_defs
#define bpf_xdp_adjust_tail bpf_xdp_adjust_tail_defs
#define bpf_get_stack bpf_get_stack_defs
#define bpf_skb_load_bytes_relative bpf_skb_load_bytes_relative_defs
#define bpf_fib_lookup bpf_fib_lookup_defs
#define bpf_get_current_cgroup_id bpf_get_current_cgroup_id_defs
#define bpf_map_push_elem bpf_map_push_elem_defs
#define bpf_sk_fullsock bpf_sk_fullsock_defs
#define bpf_skc_lookup_tcp bpf_skc_lookup_tcp_defs
#define bpf_send_signal bpf_send_signal_defs
#define bpf_probe_read_user bpf_probe_read_user_defs
#define bpf_probe_read_kernel bpf_probe_read_kernel_defs
#define bpf_probe_read_user_str bpf_probe_read_user_str_defs
#define bpf_probe_read_kernel_str bpf_probe_read_kernel_str_defs
#define bpf_jiffies64 bpf_jiffies64_defs
#define bpf_get_netns_cookie bpf_get_netns_cookie_defs
#define bpf_ktime_get_boot_ns bpf_ktime_get_boot_ns_defs
#define bpf_seq_write bpf_seq_write_defs
#define bpf_ringbuf_output bpf_ringbuf_output_defs
#define bpf_copy_from_user bpf_copy_from_user_defs
#define bpf_redirect_neigh bpf_redirect_neigh_defs
#define bpf_redirect_peer bpf_redirect_peer_defs
#define bpf_get_current_task_btf bpf_get_current_task_btf_defs
#define bpf_ima_inode_hash bpf_ima_inode_hash_defs
#define bpf_get_attach_cookie bpf_get_attach_cookie_defs
#define bpf_task_pt_regs bpf_task_pt_regs_defs
#define bpf_loop bpf_loop_defs
#define bpf_get_func_arg bpf_get_func_arg_defs
#define bpf_get_func_ret bpf_get_func_ret_defs
#define bpf_get_func_arg_cnt bpf_get_func_arg_cnt_defs
#define bpf_get_retval bpf_get_retval_defs
#define bpf_copy_from_user_task bpf_copy_from_user_task_defs
#define bpf_ima_file_hash bpf_ima_file_hash_defs
#define bpf_map_lookup_percpu_elem bpf_map_lookup_percpu_elem_defs
#include "../arm64/arm64_sim_local_bpf.h"
#undef bpf_map_lookup_elem
#undef bpf_map_update_elem
#undef bpf_map_delete_elem
#undef bpf_probe_read
#undef bpf_ktime_get_ns
#undef bpf_trace_printk
#undef bpf_get_prandom_u32
#undef bpf_get_smp_processor_id
#undef bpf_skb_store_bytes
#undef bpf_l3_csum_replace
#undef bpf_l4_csum_replace
#undef bpf_tail_call
#undef bpf_clone_redirect
#undef bpf_get_current_pid_tgid
#undef bpf_get_current_uid_gid
#undef bpf_get_current_comm
#undef bpf_skb_get_tunnel_key
#undef bpf_skb_set_tunnel_key
#undef bpf_redirect
#undef bpf_perf_event_output
#undef bpf_skb_load_bytes
#undef bpf_get_stackid
#undef bpf_csum_diff
#undef bpf_skb_change_proto
#undef bpf_skb_change_type
#undef bpf_skb_under_cgroup
#undef bpf_get_current_task
#undef bpf_probe_write_user
#undef bpf_current_task_under_cgroup
#undef bpf_skb_change_tail
#undef bpf_skb_pull_data
#undef bpf_skb_change_head
#undef bpf_xdp_adjust_head
#undef bpf_probe_read_str
#undef bpf_get_socket_cookie
#undef bpf_skb_adjust_room
#undef bpf_xdp_adjust_meta
#undef bpf_override_return
#undef bpf_xdp_adjust_tail
#undef bpf_get_stack
#undef bpf_skb_load_bytes_relative
#undef bpf_fib_lookup
#undef bpf_get_current_cgroup_id
#undef bpf_map_push_elem
#undef bpf_sk_fullsock
#undef bpf_skc_lookup_tcp
#undef bpf_send_signal
#undef bpf_probe_read_user
#undef bpf_probe_read_kernel
#undef bpf_probe_read_user_str
#undef bpf_probe_read_kernel_str
#undef bpf_jiffies64
#undef bpf_get_netns_cookie
#undef bpf_ktime_get_boot_ns
#undef bpf_seq_write
#undef bpf_ringbuf_output
#undef bpf_copy_from_user
#undef bpf_redirect_neigh
#undef bpf_redirect_peer
#undef bpf_get_current_task_btf
#undef bpf_ima_inode_hash
#undef bpf_get_attach_cookie
#undef bpf_task_pt_regs
#undef bpf_loop
#undef bpf_get_func_arg
#undef bpf_get_func_ret
#undef bpf_get_func_arg_cnt
#undef bpf_get_retval
#undef bpf_copy_from_user_task
#undef bpf_ima_file_hash
#undef bpf_map_lookup_percpu_elem
#include <stdio.h>
#include <stdarg.h>
#define RETURN_BITS 0xfedcba9876543210ULL
static unsigned failures, calls, seen_id, cases, helper_id;
static __u64 expected[5];
static __u64 value_for(unsigned i) { return 0x98765432fedcba00ULL + i; }
static void check_arg(unsigned index, __u64 got) {
    if (got != expected[index]) {
        printf("helper%u arg%u got%llx expected%llx\n", seen_id, index, got, expected[index]);
        failures++;
    }
}
struct __sk_buff;
struct bpf_fib_lookup;
struct bpf_redir_neigh;
struct bpf_sock;
struct bpf_sock_tuple;
struct bpf_tunnel_key;
struct file;
struct inode;
struct pt_regs;
struct seq_file;
struct task_struct;
struct xdp_md;
static void * bpf_map_lookup_elem(void * arg0, const void * arg1)
{
    seen_id = 1; calls++;
    check_arg(0, (__u64)(unsigned long)arg0);
    check_arg(1, (__u64)(unsigned long)arg1);
    return (void *)(unsigned long)RETURN_BITS;
}

static long bpf_map_update_elem(void * arg0, const void * arg1, const void * arg2, __u64 arg3)
{
    seen_id = 2; calls++;
    check_arg(0, (__u64)(unsigned long)arg0);
    check_arg(1, (__u64)(unsigned long)arg1);
    check_arg(2, (__u64)(unsigned long)arg2);
    check_arg(3, (__u64)(unsigned long)arg3);
    return (long)(unsigned long)RETURN_BITS;
}

static long bpf_map_delete_elem(void * arg0, const void * arg1)
{
    seen_id = 3; calls++;
    check_arg(0, (__u64)(unsigned long)arg0);
    check_arg(1, (__u64)(unsigned long)arg1);
    return (long)(unsigned long)RETURN_BITS;
}

static long bpf_probe_read(void * arg0, __u32 arg1, const void * arg2)
{
    seen_id = 4; calls++;
    check_arg(0, (__u64)(unsigned long)arg0);
    check_arg(1, (__u64)(unsigned long)arg1);
    check_arg(2, (__u64)(unsigned long)arg2);
    return (long)(unsigned long)RETURN_BITS;
}

static __u64 bpf_ktime_get_ns(void)
{
    seen_id = 5; calls++;

    return (__u64)(unsigned long)RETURN_BITS;
}

static long bpf_trace_printk(const char * arg0, __u32 arg1, ...)
{
    seen_id = 6; calls++;
    check_arg(0, (__u64)(unsigned long)arg0);
    check_arg(1, (__u64)(unsigned long)arg1);
    va_list rest;
    va_start(rest, arg1);
    check_arg(2, va_arg(rest, __u64));
    check_arg(3, va_arg(rest, __u64));
    check_arg(4, va_arg(rest, __u64));
    va_end(rest);
    return (long)(unsigned long)RETURN_BITS;
}

static __u32 bpf_get_prandom_u32(void)
{
    seen_id = 7; calls++;

    return (__u32)(unsigned long)RETURN_BITS;
}

static __bpf_fastcall __u32 bpf_get_smp_processor_id(void)
{
    seen_id = 8; calls++;

    return (__bpf_fastcall __u32)(unsigned long)RETURN_BITS;
}

static long bpf_skb_store_bytes(struct __sk_buff * arg0, __u32 arg1, const void * arg2, __u32 arg3, __u64 arg4)
{
    seen_id = 9; calls++;
    check_arg(0, (__u64)(unsigned long)arg0);
    check_arg(1, (__u64)(unsigned long)arg1);
    check_arg(2, (__u64)(unsigned long)arg2);
    check_arg(3, (__u64)(unsigned long)arg3);
    check_arg(4, (__u64)(unsigned long)arg4);
    return (long)(unsigned long)RETURN_BITS;
}

static long bpf_l3_csum_replace(struct __sk_buff * arg0, __u32 arg1, __u64 arg2, __u64 arg3, __u64 arg4)
{
    seen_id = 10; calls++;
    check_arg(0, (__u64)(unsigned long)arg0);
    check_arg(1, (__u64)(unsigned long)arg1);
    check_arg(2, (__u64)(unsigned long)arg2);
    check_arg(3, (__u64)(unsigned long)arg3);
    check_arg(4, (__u64)(unsigned long)arg4);
    return (long)(unsigned long)RETURN_BITS;
}

static long bpf_l4_csum_replace(struct __sk_buff * arg0, __u32 arg1, __u64 arg2, __u64 arg3, __u64 arg4)
{
    seen_id = 11; calls++;
    check_arg(0, (__u64)(unsigned long)arg0);
    check_arg(1, (__u64)(unsigned long)arg1);
    check_arg(2, (__u64)(unsigned long)arg2);
    check_arg(3, (__u64)(unsigned long)arg3);
    check_arg(4, (__u64)(unsigned long)arg4);
    return (long)(unsigned long)RETURN_BITS;
}

static long bpf_tail_call(void * arg0, void * arg1, __u32 arg2)
{
    seen_id = 12; calls++;
    check_arg(0, (__u64)(unsigned long)arg0);
    check_arg(1, (__u64)(unsigned long)arg1);
    check_arg(2, (__u64)(unsigned long)arg2);
    return (long)(unsigned long)RETURN_BITS;
}

static long bpf_clone_redirect(struct __sk_buff * arg0, __u32 arg1, __u64 arg2)
{
    seen_id = 13; calls++;
    check_arg(0, (__u64)(unsigned long)arg0);
    check_arg(1, (__u64)(unsigned long)arg1);
    check_arg(2, (__u64)(unsigned long)arg2);
    return (long)(unsigned long)RETURN_BITS;
}

static __u64 bpf_get_current_pid_tgid(void)
{
    seen_id = 14; calls++;

    return (__u64)(unsigned long)RETURN_BITS;
}

static __u64 bpf_get_current_uid_gid(void)
{
    seen_id = 15; calls++;

    return (__u64)(unsigned long)RETURN_BITS;
}

static long bpf_get_current_comm(void * arg0, __u32 arg1)
{
    seen_id = 16; calls++;
    check_arg(0, (__u64)(unsigned long)arg0);
    check_arg(1, (__u64)(unsigned long)arg1);
    return (long)(unsigned long)RETURN_BITS;
}

static long bpf_skb_get_tunnel_key(struct __sk_buff * arg0, struct bpf_tunnel_key * arg1, __u32 arg2, __u64 arg3)
{
    seen_id = 20; calls++;
    check_arg(0, (__u64)(unsigned long)arg0);
    check_arg(1, (__u64)(unsigned long)arg1);
    check_arg(2, (__u64)(unsigned long)arg2);
    check_arg(3, (__u64)(unsigned long)arg3);
    return (long)(unsigned long)RETURN_BITS;
}

static long bpf_skb_set_tunnel_key(struct __sk_buff * arg0, struct bpf_tunnel_key * arg1, __u32 arg2, __u64 arg3)
{
    seen_id = 21; calls++;
    check_arg(0, (__u64)(unsigned long)arg0);
    check_arg(1, (__u64)(unsigned long)arg1);
    check_arg(2, (__u64)(unsigned long)arg2);
    check_arg(3, (__u64)(unsigned long)arg3);
    return (long)(unsigned long)RETURN_BITS;
}

static long bpf_redirect(__u32 arg0, __u64 arg1)
{
    seen_id = 23; calls++;
    check_arg(0, (__u64)(unsigned long)arg0);
    check_arg(1, (__u64)(unsigned long)arg1);
    return (long)(unsigned long)RETURN_BITS;
}

static long bpf_perf_event_output(void * arg0, void * arg1, __u64 arg2, void * arg3, __u64 arg4)
{
    seen_id = 25; calls++;
    check_arg(0, (__u64)(unsigned long)arg0);
    check_arg(1, (__u64)(unsigned long)arg1);
    check_arg(2, (__u64)(unsigned long)arg2);
    check_arg(3, (__u64)(unsigned long)arg3);
    check_arg(4, (__u64)(unsigned long)arg4);
    return (long)(unsigned long)RETURN_BITS;
}

static long bpf_skb_load_bytes(const void * arg0, __u32 arg1, void * arg2, __u32 arg3)
{
    seen_id = 26; calls++;
    check_arg(0, (__u64)(unsigned long)arg0);
    check_arg(1, (__u64)(unsigned long)arg1);
    check_arg(2, (__u64)(unsigned long)arg2);
    check_arg(3, (__u64)(unsigned long)arg3);
    return (long)(unsigned long)RETURN_BITS;
}

static long bpf_get_stackid(void * arg0, void * arg1, __u64 arg2)
{
    seen_id = 27; calls++;
    check_arg(0, (__u64)(unsigned long)arg0);
    check_arg(1, (__u64)(unsigned long)arg1);
    check_arg(2, (__u64)(unsigned long)arg2);
    return (long)(unsigned long)RETURN_BITS;
}

static __s64 bpf_csum_diff(__be32 * arg0, __u32 arg1, __be32 * arg2, __u32 arg3, __wsum arg4)
{
    seen_id = 28; calls++;
    check_arg(0, (__u64)(unsigned long)arg0);
    check_arg(1, (__u64)(unsigned long)arg1);
    check_arg(2, (__u64)(unsigned long)arg2);
    check_arg(3, (__u64)(unsigned long)arg3);
    check_arg(4, (__u64)(unsigned long)arg4);
    return (__s64)(unsigned long)RETURN_BITS;
}

static long bpf_skb_change_proto(struct __sk_buff * arg0, __be16 arg1, __u64 arg2)
{
    seen_id = 31; calls++;
    check_arg(0, (__u64)(unsigned long)arg0);
    check_arg(1, (__u64)(unsigned long)arg1);
    check_arg(2, (__u64)(unsigned long)arg2);
    return (long)(unsigned long)RETURN_BITS;
}

static long bpf_skb_change_type(struct __sk_buff * arg0, __u32 arg1)
{
    seen_id = 32; calls++;
    check_arg(0, (__u64)(unsigned long)arg0);
    check_arg(1, (__u64)(unsigned long)arg1);
    return (long)(unsigned long)RETURN_BITS;
}

static long bpf_skb_under_cgroup(struct __sk_buff * arg0, void * arg1, __u32 arg2)
{
    seen_id = 33; calls++;
    check_arg(0, (__u64)(unsigned long)arg0);
    check_arg(1, (__u64)(unsigned long)arg1);
    check_arg(2, (__u64)(unsigned long)arg2);
    return (long)(unsigned long)RETURN_BITS;
}

static __u64 bpf_get_current_task(void)
{
    seen_id = 35; calls++;

    return (__u64)(unsigned long)RETURN_BITS;
}

static long bpf_probe_write_user(void * arg0, const void * arg1, __u32 arg2)
{
    seen_id = 36; calls++;
    check_arg(0, (__u64)(unsigned long)arg0);
    check_arg(1, (__u64)(unsigned long)arg1);
    check_arg(2, (__u64)(unsigned long)arg2);
    return (long)(unsigned long)RETURN_BITS;
}

static long bpf_current_task_under_cgroup(void * arg0, __u32 arg1)
{
    seen_id = 37; calls++;
    check_arg(0, (__u64)(unsigned long)arg0);
    check_arg(1, (__u64)(unsigned long)arg1);
    return (long)(unsigned long)RETURN_BITS;
}

static long bpf_skb_change_tail(struct __sk_buff * arg0, __u32 arg1, __u64 arg2)
{
    seen_id = 38; calls++;
    check_arg(0, (__u64)(unsigned long)arg0);
    check_arg(1, (__u64)(unsigned long)arg1);
    check_arg(2, (__u64)(unsigned long)arg2);
    return (long)(unsigned long)RETURN_BITS;
}

static long bpf_skb_pull_data(struct __sk_buff * arg0, __u32 arg1)
{
    seen_id = 39; calls++;
    check_arg(0, (__u64)(unsigned long)arg0);
    check_arg(1, (__u64)(unsigned long)arg1);
    return (long)(unsigned long)RETURN_BITS;
}

static long bpf_skb_change_head(struct __sk_buff * arg0, __u32 arg1, __u64 arg2)
{
    seen_id = 43; calls++;
    check_arg(0, (__u64)(unsigned long)arg0);
    check_arg(1, (__u64)(unsigned long)arg1);
    check_arg(2, (__u64)(unsigned long)arg2);
    return (long)(unsigned long)RETURN_BITS;
}

static long bpf_xdp_adjust_head(struct xdp_md * arg0, int arg1)
{
    seen_id = 44; calls++;
    check_arg(0, (__u64)(unsigned long)arg0);
    check_arg(1, (__u64)(unsigned long)arg1);
    return (long)(unsigned long)RETURN_BITS;
}

static long bpf_probe_read_str(void * arg0, __u32 arg1, const void * arg2)
{
    seen_id = 45; calls++;
    check_arg(0, (__u64)(unsigned long)arg0);
    check_arg(1, (__u64)(unsigned long)arg1);
    check_arg(2, (__u64)(unsigned long)arg2);
    return (long)(unsigned long)RETURN_BITS;
}

static __u64 bpf_get_socket_cookie(void * arg0)
{
    seen_id = 46; calls++;
    check_arg(0, (__u64)(unsigned long)arg0);
    return (__u64)(unsigned long)RETURN_BITS;
}

static long bpf_skb_adjust_room(struct __sk_buff * arg0, __s32 arg1, __u32 arg2, __u64 arg3)
{
    seen_id = 50; calls++;
    check_arg(0, (__u64)(unsigned long)arg0);
    check_arg(1, (__u64)(unsigned long)arg1);
    check_arg(2, (__u64)(unsigned long)arg2);
    check_arg(3, (__u64)(unsigned long)arg3);
    return (long)(unsigned long)RETURN_BITS;
}

static long bpf_xdp_adjust_meta(struct xdp_md * arg0, int arg1)
{
    seen_id = 54; calls++;
    check_arg(0, (__u64)(unsigned long)arg0);
    check_arg(1, (__u64)(unsigned long)arg1);
    return (long)(unsigned long)RETURN_BITS;
}

static long bpf_override_return(struct pt_regs * arg0, __u64 arg1)
{
    seen_id = 58; calls++;
    check_arg(0, (__u64)(unsigned long)arg0);
    check_arg(1, (__u64)(unsigned long)arg1);
    return (long)(unsigned long)RETURN_BITS;
}

static long bpf_xdp_adjust_tail(struct xdp_md * arg0, int arg1)
{
    seen_id = 65; calls++;
    check_arg(0, (__u64)(unsigned long)arg0);
    check_arg(1, (__u64)(unsigned long)arg1);
    return (long)(unsigned long)RETURN_BITS;
}

static long bpf_get_stack(void * arg0, void * arg1, __u32 arg2, __u64 arg3)
{
    seen_id = 67; calls++;
    check_arg(0, (__u64)(unsigned long)arg0);
    check_arg(1, (__u64)(unsigned long)arg1);
    check_arg(2, (__u64)(unsigned long)arg2);
    check_arg(3, (__u64)(unsigned long)arg3);
    return (long)(unsigned long)RETURN_BITS;
}

static long bpf_skb_load_bytes_relative(const void * arg0, __u32 arg1, void * arg2, __u32 arg3, __u32 arg4)
{
    seen_id = 68; calls++;
    check_arg(0, (__u64)(unsigned long)arg0);
    check_arg(1, (__u64)(unsigned long)arg1);
    check_arg(2, (__u64)(unsigned long)arg2);
    check_arg(3, (__u64)(unsigned long)arg3);
    check_arg(4, (__u64)(unsigned long)arg4);
    return (long)(unsigned long)RETURN_BITS;
}

static long bpf_fib_lookup(void * arg0, struct bpf_fib_lookup * arg1, int arg2, __u32 arg3)
{
    seen_id = 69; calls++;
    check_arg(0, (__u64)(unsigned long)arg0);
    check_arg(1, (__u64)(unsigned long)arg1);
    check_arg(2, (__u64)(unsigned long)arg2);
    check_arg(3, (__u64)(unsigned long)arg3);
    return (long)(unsigned long)RETURN_BITS;
}

static __u64 bpf_get_current_cgroup_id(void)
{
    seen_id = 80; calls++;

    return (__u64)(unsigned long)RETURN_BITS;
}

static long bpf_map_push_elem(void * arg0, const void * arg1, __u64 arg2)
{
    seen_id = 87; calls++;
    check_arg(0, (__u64)(unsigned long)arg0);
    check_arg(1, (__u64)(unsigned long)arg1);
    check_arg(2, (__u64)(unsigned long)arg2);
    return (long)(unsigned long)RETURN_BITS;
}

static struct bpf_sock * bpf_sk_fullsock(struct bpf_sock * arg0)
{
    seen_id = 95; calls++;
    check_arg(0, (__u64)(unsigned long)arg0);
    return (struct bpf_sock *)(unsigned long)RETURN_BITS;
}

static struct bpf_sock * bpf_skc_lookup_tcp(void * arg0, struct bpf_sock_tuple * arg1, __u32 arg2, __u64 arg3, __u64 arg4)
{
    seen_id = 99; calls++;
    check_arg(0, (__u64)(unsigned long)arg0);
    check_arg(1, (__u64)(unsigned long)arg1);
    check_arg(2, (__u64)(unsigned long)arg2);
    check_arg(3, (__u64)(unsigned long)arg3);
    check_arg(4, (__u64)(unsigned long)arg4);
    return (struct bpf_sock *)(unsigned long)RETURN_BITS;
}

static long bpf_send_signal(__u32 arg0)
{
    seen_id = 109; calls++;
    check_arg(0, (__u64)(unsigned long)arg0);
    return (long)(unsigned long)RETURN_BITS;
}

static long bpf_probe_read_user(void * arg0, __u32 arg1, const void * arg2)
{
    seen_id = 112; calls++;
    check_arg(0, (__u64)(unsigned long)arg0);
    check_arg(1, (__u64)(unsigned long)arg1);
    check_arg(2, (__u64)(unsigned long)arg2);
    return (long)(unsigned long)RETURN_BITS;
}

static long bpf_probe_read_kernel(void * arg0, __u32 arg1, const void * arg2)
{
    seen_id = 113; calls++;
    check_arg(0, (__u64)(unsigned long)arg0);
    check_arg(1, (__u64)(unsigned long)arg1);
    check_arg(2, (__u64)(unsigned long)arg2);
    return (long)(unsigned long)RETURN_BITS;
}

static long bpf_probe_read_user_str(void * arg0, __u32 arg1, const void * arg2)
{
    seen_id = 114; calls++;
    check_arg(0, (__u64)(unsigned long)arg0);
    check_arg(1, (__u64)(unsigned long)arg1);
    check_arg(2, (__u64)(unsigned long)arg2);
    return (long)(unsigned long)RETURN_BITS;
}

static long bpf_probe_read_kernel_str(void * arg0, __u32 arg1, const void * arg2)
{
    seen_id = 115; calls++;
    check_arg(0, (__u64)(unsigned long)arg0);
    check_arg(1, (__u64)(unsigned long)arg1);
    check_arg(2, (__u64)(unsigned long)arg2);
    return (long)(unsigned long)RETURN_BITS;
}

static __u64 bpf_jiffies64(void)
{
    seen_id = 118; calls++;

    return (__u64)(unsigned long)RETURN_BITS;
}

static __u64 bpf_get_netns_cookie(void * arg0)
{
    seen_id = 122; calls++;
    check_arg(0, (__u64)(unsigned long)arg0);
    return (__u64)(unsigned long)RETURN_BITS;
}

static __u64 bpf_ktime_get_boot_ns(void)
{
    seen_id = 125; calls++;

    return (__u64)(unsigned long)RETURN_BITS;
}

static long bpf_seq_write(struct seq_file * arg0, const void * arg1, __u32 arg2)
{
    seen_id = 127; calls++;
    check_arg(0, (__u64)(unsigned long)arg0);
    check_arg(1, (__u64)(unsigned long)arg1);
    check_arg(2, (__u64)(unsigned long)arg2);
    return (long)(unsigned long)RETURN_BITS;
}

static long bpf_ringbuf_output(void * arg0, void * arg1, __u64 arg2, __u64 arg3)
{
    seen_id = 130; calls++;
    check_arg(0, (__u64)(unsigned long)arg0);
    check_arg(1, (__u64)(unsigned long)arg1);
    check_arg(2, (__u64)(unsigned long)arg2);
    check_arg(3, (__u64)(unsigned long)arg3);
    return (long)(unsigned long)RETURN_BITS;
}

static long bpf_copy_from_user(void * arg0, __u32 arg1, const void * arg2)
{
    seen_id = 148; calls++;
    check_arg(0, (__u64)(unsigned long)arg0);
    check_arg(1, (__u64)(unsigned long)arg1);
    check_arg(2, (__u64)(unsigned long)arg2);
    return (long)(unsigned long)RETURN_BITS;
}

static long bpf_redirect_neigh(__u32 arg0, struct bpf_redir_neigh * arg1, int arg2, __u64 arg3)
{
    seen_id = 152; calls++;
    check_arg(0, (__u64)(unsigned long)arg0);
    check_arg(1, (__u64)(unsigned long)arg1);
    check_arg(2, (__u64)(unsigned long)arg2);
    check_arg(3, (__u64)(unsigned long)arg3);
    return (long)(unsigned long)RETURN_BITS;
}

static long bpf_redirect_peer(__u32 arg0, __u64 arg1)
{
    seen_id = 155; calls++;
    check_arg(0, (__u64)(unsigned long)arg0);
    check_arg(1, (__u64)(unsigned long)arg1);
    return (long)(unsigned long)RETURN_BITS;
}

static struct task_struct * bpf_get_current_task_btf(void)
{
    seen_id = 158; calls++;

    return (struct task_struct *)(unsigned long)RETURN_BITS;
}

static long bpf_ima_inode_hash(struct inode * arg0, void * arg1, __u32 arg2)
{
    seen_id = 161; calls++;
    check_arg(0, (__u64)(unsigned long)arg0);
    check_arg(1, (__u64)(unsigned long)arg1);
    check_arg(2, (__u64)(unsigned long)arg2);
    return (long)(unsigned long)RETURN_BITS;
}

static __u64 bpf_get_attach_cookie(void * arg0)
{
    seen_id = 174; calls++;
    check_arg(0, (__u64)(unsigned long)arg0);
    return (__u64)(unsigned long)RETURN_BITS;
}

static long bpf_task_pt_regs(struct task_struct * arg0)
{
    seen_id = 175; calls++;
    check_arg(0, (__u64)(unsigned long)arg0);
    return (long)(unsigned long)RETURN_BITS;
}

static long bpf_loop(__u32 arg0, void * arg1, void * arg2, __u64 arg3)
{
    seen_id = 181; calls++;
    check_arg(0, (__u64)(unsigned long)arg0);
    check_arg(1, (__u64)(unsigned long)arg1);
    check_arg(2, (__u64)(unsigned long)arg2);
    check_arg(3, (__u64)(unsigned long)arg3);
    return (long)(unsigned long)RETURN_BITS;
}

static long bpf_get_func_arg(void * arg0, __u32 arg1, __u64 * arg2)
{
    seen_id = 183; calls++;
    check_arg(0, (__u64)(unsigned long)arg0);
    check_arg(1, (__u64)(unsigned long)arg1);
    check_arg(2, (__u64)(unsigned long)arg2);
    return (long)(unsigned long)RETURN_BITS;
}

static long bpf_get_func_ret(void * arg0, __u64 * arg1)
{
    seen_id = 184; calls++;
    check_arg(0, (__u64)(unsigned long)arg0);
    check_arg(1, (__u64)(unsigned long)arg1);
    return (long)(unsigned long)RETURN_BITS;
}

static long bpf_get_func_arg_cnt(void * arg0)
{
    seen_id = 185; calls++;
    check_arg(0, (__u64)(unsigned long)arg0);
    return (long)(unsigned long)RETURN_BITS;
}

static int bpf_get_retval(void)
{
    seen_id = 186; calls++;

    return (int)(unsigned long)RETURN_BITS;
}

static long bpf_copy_from_user_task(void * arg0, __u32 arg1, const void * arg2, struct task_struct * arg3, __u64 arg4)
{
    seen_id = 191; calls++;
    check_arg(0, (__u64)(unsigned long)arg0);
    check_arg(1, (__u64)(unsigned long)arg1);
    check_arg(2, (__u64)(unsigned long)arg2);
    check_arg(3, (__u64)(unsigned long)arg3);
    check_arg(4, (__u64)(unsigned long)arg4);
    return (long)(unsigned long)RETURN_BITS;
}

static long bpf_ima_file_hash(struct file * arg0, void * arg1, __u32 arg2)
{
    seen_id = 193; calls++;
    check_arg(0, (__u64)(unsigned long)arg0);
    check_arg(1, (__u64)(unsigned long)arg1);
    check_arg(2, (__u64)(unsigned long)arg2);
    return (long)(unsigned long)RETURN_BITS;
}

static void * bpf_map_lookup_percpu_elem(void * arg0, const void * arg1, __u32 arg2)
{
    seen_id = 195; calls++;
    check_arg(0, (__u64)(unsigned long)arg0);
    check_arg(1, (__u64)(unsigned long)arg1);
    check_arg(2, (__u64)(unsigned long)arg2);
    return (void *)(unsigned long)RETURN_BITS;
}
#define CHECK_HELPER(NAME, RESULT, MASK, TAG, ...) \
    do { \
        ARM64_SIM_ENTRY_XDP(&ctx); \
        for (unsigned i=0; i<31; i++) { \
            ARM64_SIM_L_WRITE_REG_WIDTH(i, value_for(i), ARM64_WIDTH_64); \
            if (stack_mode && ((MASK) & (1ULL<<i))) \
                ARM64_SIM_L_WRITE_REG_PTR_TAG(i, (void *)-8L, ARM64_SIM_TAG_STACK); \
        } \
        __VA_ARGS__ \
        calls=0; seen_id=0; \
        __a64_n=0; __a64_z=1; __a64_c=1; __a64_v=0; \
        ARM64_SIM_BPF_CALL_##NAME(); \
        if (calls!=1 || seen_id!=helper_id || __a64_x0.x!=(__u64)(unsigned long)(RESULT)RETURN_BITS \
            || __a64_x0_tag!=(TAG) || __a64_n!=0 || __a64_z!=1 || __a64_c!=1 || __a64_v!=0) failures++; \
        for (unsigned i=1; i<31; i++) { \
            __u64 want = stack_mode && ((MASK) & (1ULL<<i)) ? (__u64)-8LL : value_for(i); \
            __u8 tag = stack_mode && ((MASK) & (1ULL<<i)) ? ARM64_SIM_TAG_STACK : ARM64_SIM_TAG_SCALAR; \
            if (ARM64_SIM_L_READ_REG(i)!=want || ARM64_SIM_L_REG_TAG(i)!=tag) failures++; \
        } \
        if (__a64_sp != 0 || __a64_lr != 0 || __a64_v0 != 0 || __a64_v0_hi != 0) failures++; \
        (void)__a64_sim_skb_ctx; (void)__a64_sim_abi_kind; \
        (void)&__a64_stack; (void)__a64_stack_tag[0]; \
        cases++; \
    } while (0)
static void run(unsigned stack_mode) {
    struct xdp_md ctx={0};
    helper_id=1; CHECK_HELPER(bpf_map_lookup_elem, void *, 3, ARM64_SIM_TAG_MAP_VALUE,
        expected[0] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(0);
        expected[1] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(1););
    helper_id=2; CHECK_HELPER(bpf_map_update_elem, long, 7, ARM64_SIM_TAG_SCALAR,
        expected[0] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(0);
        expected[1] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(1);
        expected[2] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(2);
        expected[3] = (__u64)(unsigned long)(__u64)value_for(3););
    helper_id=3; CHECK_HELPER(bpf_map_delete_elem, long, 3, ARM64_SIM_TAG_SCALAR,
        expected[0] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(0);
        expected[1] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(1););
    helper_id=4; CHECK_HELPER(bpf_probe_read, long, 5, ARM64_SIM_TAG_SCALAR,
        expected[0] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(0);
        expected[1] = (__u64)(unsigned long)(__u32)value_for(1);
        expected[2] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(2););
    helper_id=5; CHECK_HELPER(bpf_ktime_get_ns, __u64, 0, ARM64_SIM_TAG_SCALAR,
        );
    helper_id=6; CHECK_HELPER(bpf_trace_printk, long, 1, ARM64_SIM_TAG_SCALAR,
        expected[0] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(0);
        expected[1] = (__u64)(unsigned long)(__u32)value_for(1);
        expected[2] = value_for(2);
        expected[3] = value_for(3);
        expected[4] = value_for(4););
    helper_id=7; CHECK_HELPER(bpf_get_prandom_u32, __u32, 0, ARM64_SIM_TAG_SCALAR,
        );
    helper_id=8; CHECK_HELPER(bpf_get_smp_processor_id, __bpf_fastcall __u32, 0, ARM64_SIM_TAG_SCALAR,
        );
    helper_id=9; CHECK_HELPER(bpf_skb_store_bytes, long, 5, ARM64_SIM_TAG_SCALAR,
        expected[0] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(0);
        expected[1] = (__u64)(unsigned long)(__u32)value_for(1);
        expected[2] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(2);
        expected[3] = (__u64)(unsigned long)(__u32)value_for(3);
        expected[4] = (__u64)(unsigned long)(__u64)value_for(4););
    helper_id=10; CHECK_HELPER(bpf_l3_csum_replace, long, 1, ARM64_SIM_TAG_SCALAR,
        expected[0] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(0);
        expected[1] = (__u64)(unsigned long)(__u32)value_for(1);
        expected[2] = (__u64)(unsigned long)(__u64)value_for(2);
        expected[3] = (__u64)(unsigned long)(__u64)value_for(3);
        expected[4] = (__u64)(unsigned long)(__u64)value_for(4););
    helper_id=11; CHECK_HELPER(bpf_l4_csum_replace, long, 1, ARM64_SIM_TAG_SCALAR,
        expected[0] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(0);
        expected[1] = (__u64)(unsigned long)(__u32)value_for(1);
        expected[2] = (__u64)(unsigned long)(__u64)value_for(2);
        expected[3] = (__u64)(unsigned long)(__u64)value_for(3);
        expected[4] = (__u64)(unsigned long)(__u64)value_for(4););
    helper_id=12; CHECK_HELPER(bpf_tail_call, long, 3, ARM64_SIM_TAG_SCALAR,
        expected[0] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(0);
        expected[1] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(1);
        expected[2] = (__u64)(unsigned long)(__u32)value_for(2););
    helper_id=13; CHECK_HELPER(bpf_clone_redirect, long, 1, ARM64_SIM_TAG_SCALAR,
        expected[0] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(0);
        expected[1] = (__u64)(unsigned long)(__u32)value_for(1);
        expected[2] = (__u64)(unsigned long)(__u64)value_for(2););
    helper_id=14; CHECK_HELPER(bpf_get_current_pid_tgid, __u64, 0, ARM64_SIM_TAG_SCALAR,
        );
    helper_id=15; CHECK_HELPER(bpf_get_current_uid_gid, __u64, 0, ARM64_SIM_TAG_SCALAR,
        );
    helper_id=16; CHECK_HELPER(bpf_get_current_comm, long, 1, ARM64_SIM_TAG_SCALAR,
        expected[0] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(0);
        expected[1] = (__u64)(unsigned long)(__u32)value_for(1););
    helper_id=20; CHECK_HELPER(bpf_skb_get_tunnel_key, long, 3, ARM64_SIM_TAG_SCALAR,
        expected[0] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(0);
        expected[1] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(1);
        expected[2] = (__u64)(unsigned long)(__u32)value_for(2);
        expected[3] = (__u64)(unsigned long)(__u64)value_for(3););
    helper_id=21; CHECK_HELPER(bpf_skb_set_tunnel_key, long, 3, ARM64_SIM_TAG_SCALAR,
        expected[0] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(0);
        expected[1] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(1);
        expected[2] = (__u64)(unsigned long)(__u32)value_for(2);
        expected[3] = (__u64)(unsigned long)(__u64)value_for(3););
    helper_id=23; CHECK_HELPER(bpf_redirect, long, 0, ARM64_SIM_TAG_SCALAR,
        expected[0] = (__u64)(unsigned long)(__u32)value_for(0);
        expected[1] = (__u64)(unsigned long)(__u64)value_for(1););
    helper_id=25; CHECK_HELPER(bpf_perf_event_output, long, 11, ARM64_SIM_TAG_SCALAR,
        expected[0] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(0);
        expected[1] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(1);
        expected[2] = (__u64)(unsigned long)(__u64)value_for(2);
        expected[3] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(3);
        expected[4] = (__u64)(unsigned long)(__u64)value_for(4););
    helper_id=26; CHECK_HELPER(bpf_skb_load_bytes, long, 5, ARM64_SIM_TAG_SCALAR,
        expected[0] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(0);
        expected[1] = (__u64)(unsigned long)(__u32)value_for(1);
        expected[2] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(2);
        expected[3] = (__u64)(unsigned long)(__u32)value_for(3););
    helper_id=27; CHECK_HELPER(bpf_get_stackid, long, 3, ARM64_SIM_TAG_SCALAR,
        expected[0] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(0);
        expected[1] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(1);
        expected[2] = (__u64)(unsigned long)(__u64)value_for(2););
    helper_id=28; CHECK_HELPER(bpf_csum_diff, __s64, 5, ARM64_SIM_TAG_SCALAR,
        expected[0] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(0);
        expected[1] = (__u64)(unsigned long)(__u32)value_for(1);
        expected[2] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(2);
        expected[3] = (__u64)(unsigned long)(__u32)value_for(3);
        expected[4] = (__u64)(unsigned long)(__wsum)value_for(4););
    helper_id=31; CHECK_HELPER(bpf_skb_change_proto, long, 1, ARM64_SIM_TAG_SCALAR,
        expected[0] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(0);
        expected[1] = (__u64)(unsigned long)(__be16)value_for(1);
        expected[2] = (__u64)(unsigned long)(__u64)value_for(2););
    helper_id=32; CHECK_HELPER(bpf_skb_change_type, long, 1, ARM64_SIM_TAG_SCALAR,
        expected[0] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(0);
        expected[1] = (__u64)(unsigned long)(__u32)value_for(1););
    helper_id=33; CHECK_HELPER(bpf_skb_under_cgroup, long, 3, ARM64_SIM_TAG_SCALAR,
        expected[0] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(0);
        expected[1] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(1);
        expected[2] = (__u64)(unsigned long)(__u32)value_for(2););
    helper_id=35; CHECK_HELPER(bpf_get_current_task, __u64, 0, ARM64_SIM_TAG_SCALAR,
        );
    helper_id=36; CHECK_HELPER(bpf_probe_write_user, long, 3, ARM64_SIM_TAG_SCALAR,
        expected[0] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(0);
        expected[1] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(1);
        expected[2] = (__u64)(unsigned long)(__u32)value_for(2););
    helper_id=37; CHECK_HELPER(bpf_current_task_under_cgroup, long, 1, ARM64_SIM_TAG_SCALAR,
        expected[0] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(0);
        expected[1] = (__u64)(unsigned long)(__u32)value_for(1););
    helper_id=38; CHECK_HELPER(bpf_skb_change_tail, long, 1, ARM64_SIM_TAG_SCALAR,
        expected[0] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(0);
        expected[1] = (__u64)(unsigned long)(__u32)value_for(1);
        expected[2] = (__u64)(unsigned long)(__u64)value_for(2););
    helper_id=39; CHECK_HELPER(bpf_skb_pull_data, long, 1, ARM64_SIM_TAG_SCALAR,
        expected[0] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(0);
        expected[1] = (__u64)(unsigned long)(__u32)value_for(1););
    helper_id=43; CHECK_HELPER(bpf_skb_change_head, long, 1, ARM64_SIM_TAG_SCALAR,
        expected[0] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(0);
        expected[1] = (__u64)(unsigned long)(__u32)value_for(1);
        expected[2] = (__u64)(unsigned long)(__u64)value_for(2););
    helper_id=44; CHECK_HELPER(bpf_xdp_adjust_head, long, 1, ARM64_SIM_TAG_SCALAR,
        expected[0] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(0);
        expected[1] = (__u64)(unsigned long)(int)value_for(1););
    helper_id=45; CHECK_HELPER(bpf_probe_read_str, long, 5, ARM64_SIM_TAG_SCALAR,
        expected[0] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(0);
        expected[1] = (__u64)(unsigned long)(__u32)value_for(1);
        expected[2] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(2););
    helper_id=46; CHECK_HELPER(bpf_get_socket_cookie, __u64, 1, ARM64_SIM_TAG_SCALAR,
        expected[0] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(0););
    helper_id=50; CHECK_HELPER(bpf_skb_adjust_room, long, 1, ARM64_SIM_TAG_SCALAR,
        expected[0] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(0);
        expected[1] = (__u64)(unsigned long)(__s32)value_for(1);
        expected[2] = (__u64)(unsigned long)(__u32)value_for(2);
        expected[3] = (__u64)(unsigned long)(__u64)value_for(3););
    helper_id=54; CHECK_HELPER(bpf_xdp_adjust_meta, long, 1, ARM64_SIM_TAG_SCALAR,
        expected[0] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(0);
        expected[1] = (__u64)(unsigned long)(int)value_for(1););
    helper_id=58; CHECK_HELPER(bpf_override_return, long, 1, ARM64_SIM_TAG_SCALAR,
        expected[0] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(0);
        expected[1] = (__u64)(unsigned long)(__u64)value_for(1););
    helper_id=65; CHECK_HELPER(bpf_xdp_adjust_tail, long, 1, ARM64_SIM_TAG_SCALAR,
        expected[0] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(0);
        expected[1] = (__u64)(unsigned long)(int)value_for(1););
    helper_id=67; CHECK_HELPER(bpf_get_stack, long, 3, ARM64_SIM_TAG_SCALAR,
        expected[0] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(0);
        expected[1] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(1);
        expected[2] = (__u64)(unsigned long)(__u32)value_for(2);
        expected[3] = (__u64)(unsigned long)(__u64)value_for(3););
    helper_id=68; CHECK_HELPER(bpf_skb_load_bytes_relative, long, 5, ARM64_SIM_TAG_SCALAR,
        expected[0] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(0);
        expected[1] = (__u64)(unsigned long)(__u32)value_for(1);
        expected[2] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(2);
        expected[3] = (__u64)(unsigned long)(__u32)value_for(3);
        expected[4] = (__u64)(unsigned long)(__u32)value_for(4););
    helper_id=69; CHECK_HELPER(bpf_fib_lookup, long, 3, ARM64_SIM_TAG_SCALAR,
        expected[0] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(0);
        expected[1] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(1);
        expected[2] = (__u64)(unsigned long)(int)value_for(2);
        expected[3] = (__u64)(unsigned long)(__u32)value_for(3););
    helper_id=80; CHECK_HELPER(bpf_get_current_cgroup_id, __u64, 0, ARM64_SIM_TAG_SCALAR,
        );
    helper_id=87; CHECK_HELPER(bpf_map_push_elem, long, 3, ARM64_SIM_TAG_SCALAR,
        expected[0] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(0);
        expected[1] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(1);
        expected[2] = (__u64)(unsigned long)(__u64)value_for(2););
    helper_id=95; CHECK_HELPER(bpf_sk_fullsock, struct bpf_sock *, 1, ARM64_SIM_TAG_MAP_VALUE,
        expected[0] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(0););
    helper_id=99; CHECK_HELPER(bpf_skc_lookup_tcp, struct bpf_sock *, 3, ARM64_SIM_TAG_MAP_VALUE,
        expected[0] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(0);
        expected[1] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(1);
        expected[2] = (__u64)(unsigned long)(__u32)value_for(2);
        expected[3] = (__u64)(unsigned long)(__u64)value_for(3);
        expected[4] = (__u64)(unsigned long)(__u64)value_for(4););
    helper_id=109; CHECK_HELPER(bpf_send_signal, long, 0, ARM64_SIM_TAG_SCALAR,
        expected[0] = (__u64)(unsigned long)(__u32)value_for(0););
    helper_id=112; CHECK_HELPER(bpf_probe_read_user, long, 5, ARM64_SIM_TAG_SCALAR,
        expected[0] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(0);
        expected[1] = (__u64)(unsigned long)(__u32)value_for(1);
        expected[2] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(2););
    helper_id=113; CHECK_HELPER(bpf_probe_read_kernel, long, 5, ARM64_SIM_TAG_SCALAR,
        expected[0] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(0);
        expected[1] = (__u64)(unsigned long)(__u32)value_for(1);
        expected[2] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(2););
    helper_id=114; CHECK_HELPER(bpf_probe_read_user_str, long, 5, ARM64_SIM_TAG_SCALAR,
        expected[0] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(0);
        expected[1] = (__u64)(unsigned long)(__u32)value_for(1);
        expected[2] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(2););
    helper_id=115; CHECK_HELPER(bpf_probe_read_kernel_str, long, 5, ARM64_SIM_TAG_SCALAR,
        expected[0] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(0);
        expected[1] = (__u64)(unsigned long)(__u32)value_for(1);
        expected[2] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(2););
    helper_id=118; CHECK_HELPER(bpf_jiffies64, __u64, 0, ARM64_SIM_TAG_SCALAR,
        );
    helper_id=122; CHECK_HELPER(bpf_get_netns_cookie, __u64, 1, ARM64_SIM_TAG_SCALAR,
        expected[0] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(0););
    helper_id=125; CHECK_HELPER(bpf_ktime_get_boot_ns, __u64, 0, ARM64_SIM_TAG_SCALAR,
        );
    helper_id=127; CHECK_HELPER(bpf_seq_write, long, 3, ARM64_SIM_TAG_SCALAR,
        expected[0] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(0);
        expected[1] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(1);
        expected[2] = (__u64)(unsigned long)(__u32)value_for(2););
    helper_id=130; CHECK_HELPER(bpf_ringbuf_output, long, 3, ARM64_SIM_TAG_SCALAR,
        expected[0] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(0);
        expected[1] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(1);
        expected[2] = (__u64)(unsigned long)(__u64)value_for(2);
        expected[3] = (__u64)(unsigned long)(__u64)value_for(3););
    helper_id=148; CHECK_HELPER(bpf_copy_from_user, long, 5, ARM64_SIM_TAG_SCALAR,
        expected[0] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(0);
        expected[1] = (__u64)(unsigned long)(__u32)value_for(1);
        expected[2] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(2););
    helper_id=152; CHECK_HELPER(bpf_redirect_neigh, long, 2, ARM64_SIM_TAG_SCALAR,
        expected[0] = (__u64)(unsigned long)(__u32)value_for(0);
        expected[1] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(1);
        expected[2] = (__u64)(unsigned long)(int)value_for(2);
        expected[3] = (__u64)(unsigned long)(__u64)value_for(3););
    helper_id=155; CHECK_HELPER(bpf_redirect_peer, long, 0, ARM64_SIM_TAG_SCALAR,
        expected[0] = (__u64)(unsigned long)(__u32)value_for(0);
        expected[1] = (__u64)(unsigned long)(__u64)value_for(1););
    helper_id=158; CHECK_HELPER(bpf_get_current_task_btf, struct task_struct *, 0, ARM64_SIM_TAG_MAP_VALUE,
        );
    helper_id=161; CHECK_HELPER(bpf_ima_inode_hash, long, 3, ARM64_SIM_TAG_SCALAR,
        expected[0] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(0);
        expected[1] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(1);
        expected[2] = (__u64)(unsigned long)(__u32)value_for(2););
    helper_id=174; CHECK_HELPER(bpf_get_attach_cookie, __u64, 1, ARM64_SIM_TAG_SCALAR,
        expected[0] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(0););
    helper_id=175; CHECK_HELPER(bpf_task_pt_regs, long, 1, ARM64_SIM_TAG_SCALAR,
        expected[0] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(0););
    helper_id=181; CHECK_HELPER(bpf_loop, long, 6, ARM64_SIM_TAG_SCALAR,
        expected[0] = (__u64)(unsigned long)(__u32)value_for(0);
        expected[1] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(1);
        expected[2] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(2);
        expected[3] = (__u64)(unsigned long)(__u64)value_for(3););
    helper_id=183; CHECK_HELPER(bpf_get_func_arg, long, 5, ARM64_SIM_TAG_SCALAR,
        expected[0] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(0);
        expected[1] = (__u64)(unsigned long)(__u32)value_for(1);
        expected[2] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(2););
    helper_id=184; CHECK_HELPER(bpf_get_func_ret, long, 3, ARM64_SIM_TAG_SCALAR,
        expected[0] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(0);
        expected[1] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(1););
    helper_id=185; CHECK_HELPER(bpf_get_func_arg_cnt, long, 1, ARM64_SIM_TAG_SCALAR,
        expected[0] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(0););
    helper_id=186; CHECK_HELPER(bpf_get_retval, int, 0, ARM64_SIM_TAG_SCALAR,
        );
    helper_id=191; CHECK_HELPER(bpf_copy_from_user_task, long, 13, ARM64_SIM_TAG_SCALAR,
        expected[0] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(0);
        expected[1] = (__u64)(unsigned long)(__u32)value_for(1);
        expected[2] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(2);
        expected[3] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(3);
        expected[4] = (__u64)(unsigned long)(__u64)value_for(4););
    helper_id=193; CHECK_HELPER(bpf_ima_file_hash, long, 3, ARM64_SIM_TAG_SCALAR,
        expected[0] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(0);
        expected[1] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(1);
        expected[2] = (__u64)(unsigned long)(__u32)value_for(2););
    helper_id=195; CHECK_HELPER(bpf_map_lookup_percpu_elem, void *, 3, ARM64_SIM_TAG_MAP_VALUE,
        expected[0] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(0);
        expected[1] = stack_mode ? (__u64)(unsigned long)&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for(1);
        expected[2] = (__u64)(unsigned long)(__u32)value_for(2););
}
int main(void) {
    run(0); run(1);
    printf("arm64 real helper ABI: %u cases, %u failures\n", cases, failures);
    return failures != 0;
}
