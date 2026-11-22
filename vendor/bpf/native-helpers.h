/* Helpers for every app's native compile, called by name (operator 2026-11-22: "arm64 改成按名字调用
 * helper，去掉运行时分派", "helper 例程用 C 写在头文件里"; the form of 21b4f3012, 0e4f2da6f and
 * 3b5fa4b40 on 11-19/20, which the return to 05-29 dropped). Each helper is an extern function that
 * carries the kernel helper's name, which native-link binds; a call reaches it through a
 * function-like macro of the same name, so an app's own helper declarations (libbpf's and Katran's
 * static pointers, Cilium's and Tetragon's BPF_FUNC) stay unused. native_compat.h includes this file;
 * Katran's compile and OTel's bpfdefs.h include it directly. */
#ifndef VENDOR_BPF_NATIVE_HELPERS_H
#define VENDOR_BPF_NATIVE_HELPERS_H
#ifndef __always_inline
#define __always_inline __inline __attribute__((__always_inline__))
#endif

#define __KPROG_HELPER(ret, name, ...) extern ret __kprog_##name(__VA_ARGS__) __asm__(#name)
#define __KPROG_CALL(name, ...) __kprog_##name(__VA_ARGS__)
__KPROG_HELPER(void *, bpf_map_lookup_elem, void *, const void *);
__KPROG_HELPER(long, bpf_map_update_elem, void *, const void *, const void *, unsigned long long);
__KPROG_HELPER(long, bpf_map_delete_elem, void *, const void *);
__KPROG_HELPER(long, bpf_map_push_elem, void *, const void *, unsigned long long);
__KPROG_HELPER(long, bpf_map_pop_elem, void *, void *);
__KPROG_HELPER(long, bpf_probe_read_user, void *, unsigned int, const void *);
__KPROG_HELPER(long, bpf_probe_read_user_str, void *, unsigned int, const void *);
__KPROG_HELPER(long, bpf_probe_write_user, void *, const void *, unsigned int);
__KPROG_HELPER(long, bpf_copy_from_user, void *, unsigned int, const void *);
__KPROG_HELPER(unsigned long long, bpf_get_current_pid_tgid, void);
__KPROG_HELPER(unsigned long long, bpf_get_current_uid_gid, void);
__KPROG_HELPER(unsigned long long, bpf_ktime_get_ns, void);
__KPROG_HELPER(unsigned long long, bpf_ktime_get_boot_ns, void);
__KPROG_HELPER(unsigned int, bpf_get_smp_processor_id, void);
__KPROG_HELPER(unsigned int, bpf_get_prandom_u32, void);
__KPROG_HELPER(long, bpf_get_current_comm, void *, unsigned int);
__KPROG_HELPER(unsigned long long, bpf_get_current_cgroup_id, void);
__KPROG_HELPER(unsigned long long, bpf_get_current_task, void);
__KPROG_HELPER(void *, bpf_get_current_task_btf, void);
__KPROG_HELPER(unsigned long long, bpf_jiffies64, void);
__KPROG_HELPER(unsigned long long, bpf_get_attach_cookie, void *);
__KPROG_HELPER(unsigned long long, bpf_get_func_ip, void *);
__KPROG_HELPER(long, bpf_get_func_arg, void *, unsigned int, unsigned long long *);
__KPROG_HELPER(long, bpf_get_func_ret, void *, unsigned long long *);
__KPROG_HELPER(long, bpf_get_func_arg_cnt, void *);
__KPROG_HELPER(long, bpf_ima_inode_hash, void *, void *, unsigned int);
__KPROG_HELPER(long, bpf_ima_file_hash, void *, void *, unsigned int);
__KPROG_HELPER(void *, bpf_task_pt_regs, void *);
__KPROG_HELPER(long, bpf_send_signal, unsigned int);
__KPROG_HELPER(long, bpf_override_return, void *, unsigned long long);
__KPROG_HELPER(long, bpf_perf_event_output, void *, void *, unsigned long long, void *, unsigned long long);
__KPROG_HELPER(long, bpf_trace_printk, const char *, unsigned int, unsigned long long, unsigned long long, unsigned long long);
__KPROG_HELPER(long, bpf_ringbuf_output, void *, void *, unsigned long long, unsigned long long);
__KPROG_HELPER(void *, bpf_ringbuf_reserve, void *, unsigned long long, unsigned long long);
__KPROG_HELPER(void, bpf_ringbuf_submit, void *, unsigned long long);
__KPROG_HELPER(void, bpf_ringbuf_discard, void *, unsigned long long);
__KPROG_HELPER(long, bpf_ringbuf_query, void *, unsigned long long);
__KPROG_HELPER(long, bpf_seq_write, void *, const void *, unsigned int);
__KPROG_HELPER(long, bpf_loop, unsigned int, void *, void *, unsigned long long);
__KPROG_HELPER(long, bpf_tail_call, void *, void *, unsigned int);
__KPROG_HELPER(long, bpf_current_task_under_cgroup, void *, unsigned int);
__KPROG_HELPER(long, bpf_get_stackid, void *, void *, unsigned long long);
__KPROG_HELPER(long, bpf_get_stack, void *, void *, unsigned int, unsigned long long);
__KPROG_HELPER(void *, bpf_sk_fullsock, void *);
__KPROG_HELPER(long, bpf_skb_load_bytes, void *, unsigned int, void *, unsigned int);
__KPROG_HELPER(long, bpf_skb_load_bytes_relative, void *, unsigned int, void *, unsigned int, unsigned int);
__KPROG_HELPER(long, bpf_csum_diff, const void *, unsigned int, const void *, unsigned int, unsigned int);
__KPROG_HELPER(long, bpf_getsockopt, void *, int, int, void *, int);
__KPROG_HELPER(long, bpf_setsockopt, void *, int, int, void *, int);
__KPROG_HELPER(long, bpf_redirect, unsigned int, unsigned long long);
__KPROG_HELPER(long, bpf_skb_adjust_room, void *, int, unsigned int, unsigned long long);
__KPROG_HELPER(long, bpf_skb_set_tunnel_key, void *, void *, unsigned int, unsigned long long);
__KPROG_HELPER(long, bpf_xdp_adjust_head, void *, int);
__KPROG_HELPER(long, bpf_xdp_adjust_tail, void *, int);

/* Helper routines in C (operator 2026-11-19: "手写的 helper 例程 是不是应替换成 c 实现的直接编译进去的").
 * bpf_ktime_get_ns is ktime_get_mono_fast_ns and bpf_jiffies64 reads jiffies_64; P does the same.
 * Each kernel symbol carries its kernel name, which native-link binds from the boot kernel's
 * kallsyms. get_current_task(_btf) and get_smp_processor_id stay named helper calls: as gs loads in
 * P, Tracee's guest crashed (2026-11-20 check, 3b5fa4b40). */
#if defined(__x86_64__)
#define __KPROG_INLINE extern __inline __attribute__((gnu_inline, always_inline))
extern unsigned long long ktime_get_mono_fast_ns(void);
extern char jiffies_64[];
__KPROG_INLINE unsigned long long __kprog_bpf_ktime_get_ns(void) { return ktime_get_mono_fast_ns(); }
__KPROG_INLINE unsigned long long __kprog_bpf_jiffies64(void) { return *(const volatile unsigned long long *)jiffies_64; }
#endif

/* Cilium's own helper declarations (BPF_FUNC) name the kernel helper, so they are the same extern
 * functions. Tetragon keeps its BPF_FUNC pointer variables: its error metrics record the helper id
 * through the helper's name (lib/errmetrics.h, `(__u64)bpf_helper`), and its calls reach the helpers
 * here through api.h's MICRO_NATIVE names (3e99eaa1e did the same). Helpers an app declares under
 * another name follow. */
#ifndef MICRO_NATIVE_TETRAGON
#define BPF_FUNC(NAME, ...) (NAME)(__VA_ARGS__) __asm__("bpf_" #NAME)
#endif
#define csum_diff_external(...) __KPROG_CALL(bpf_csum_diff, __VA_ARGS__)
#define get_socket_opt(...) __KPROG_CALL(bpf_getsockopt, __VA_ARGS__)
#define set_socket_opt(...) __KPROG_CALL(bpf_setsockopt, __VA_ARGS__)
#define skb_event_output(...) __KPROG_CALL(bpf_perf_event_output, __VA_ARGS__)
#define xdp_event_output(...) __KPROG_CALL(bpf_perf_event_output, __VA_ARGS__)
#define sock_event_output(...) __KPROG_CALL(bpf_perf_event_output, __VA_ARGS__)

#undef bpf_map_lookup_elem
#define bpf_map_lookup_elem(...) __KPROG_CALL(bpf_map_lookup_elem, __VA_ARGS__)
#undef bpf_map_update_elem
#define bpf_map_update_elem(...) __KPROG_CALL(bpf_map_update_elem, __VA_ARGS__)
#undef bpf_map_delete_elem
#define bpf_map_delete_elem(...) __KPROG_CALL(bpf_map_delete_elem, __VA_ARGS__)
#undef bpf_map_push_elem
#define bpf_map_push_elem(...) __KPROG_CALL(bpf_map_push_elem, __VA_ARGS__)
#undef bpf_map_pop_elem
#define bpf_map_pop_elem(...) __KPROG_CALL(bpf_map_pop_elem, __VA_ARGS__)
#undef bpf_probe_read_user
#define bpf_probe_read_user(...) __KPROG_CALL(bpf_probe_read_user, __VA_ARGS__)
#undef bpf_probe_read_user_str
#define bpf_probe_read_user_str(...) __KPROG_CALL(bpf_probe_read_user_str, __VA_ARGS__)
#undef bpf_probe_write_user
#define bpf_probe_write_user(...) __KPROG_CALL(bpf_probe_write_user, __VA_ARGS__)
#undef bpf_copy_from_user
#define bpf_copy_from_user(...) __KPROG_CALL(bpf_copy_from_user, __VA_ARGS__)
#undef bpf_get_current_pid_tgid
#define bpf_get_current_pid_tgid() __kprog_bpf_get_current_pid_tgid()
#undef bpf_get_current_uid_gid
#define bpf_get_current_uid_gid() __kprog_bpf_get_current_uid_gid()
#undef bpf_ktime_get_ns
#define bpf_ktime_get_ns() __kprog_bpf_ktime_get_ns()
#undef bpf_ktime_get_boot_ns
#define bpf_ktime_get_boot_ns() __kprog_bpf_ktime_get_boot_ns()
#undef bpf_get_smp_processor_id
#define bpf_get_smp_processor_id() __kprog_bpf_get_smp_processor_id()
#undef bpf_get_prandom_u32
#define bpf_get_prandom_u32() __kprog_bpf_get_prandom_u32()
#undef bpf_get_current_comm
#define bpf_get_current_comm(...) __KPROG_CALL(bpf_get_current_comm, __VA_ARGS__)
#undef bpf_get_current_cgroup_id
#define bpf_get_current_cgroup_id() __kprog_bpf_get_current_cgroup_id()
#undef bpf_get_current_task
#define bpf_get_current_task() __kprog_bpf_get_current_task()
#undef bpf_get_current_task_btf
#define bpf_get_current_task_btf() __kprog_bpf_get_current_task_btf()
#undef bpf_jiffies64
#define bpf_jiffies64() __kprog_bpf_jiffies64()
#undef bpf_get_attach_cookie
#define bpf_get_attach_cookie(...) __KPROG_CALL(bpf_get_attach_cookie, __VA_ARGS__)
#undef bpf_get_func_ip
#define bpf_get_func_ip(...) __KPROG_CALL(bpf_get_func_ip, __VA_ARGS__)
#undef bpf_get_func_arg
#define bpf_get_func_arg(...) __KPROG_CALL(bpf_get_func_arg, __VA_ARGS__)
#undef bpf_get_func_ret
#define bpf_get_func_ret(...) __KPROG_CALL(bpf_get_func_ret, __VA_ARGS__)
#undef bpf_get_func_arg_cnt
#define bpf_get_func_arg_cnt(...) __KPROG_CALL(bpf_get_func_arg_cnt, __VA_ARGS__)
#undef bpf_ima_inode_hash
#define bpf_ima_inode_hash(...) __KPROG_CALL(bpf_ima_inode_hash, __VA_ARGS__)
#undef bpf_ima_file_hash
#define bpf_ima_file_hash(...) __KPROG_CALL(bpf_ima_file_hash, __VA_ARGS__)
#undef bpf_task_pt_regs
#define bpf_task_pt_regs(...) __KPROG_CALL(bpf_task_pt_regs, __VA_ARGS__)
#undef bpf_send_signal
#define bpf_send_signal(...) __KPROG_CALL(bpf_send_signal, __VA_ARGS__)
#undef bpf_override_return
#define bpf_override_return(...) __KPROG_CALL(bpf_override_return, __VA_ARGS__)
#undef bpf_perf_event_output
#define bpf_perf_event_output(...) __KPROG_CALL(bpf_perf_event_output, __VA_ARGS__)
/* trace_printk takes three format arguments and the kernel reads only the ones the format names,
 * so a short call pads with zeros. */
#define __kprog_trace_printk_pad(fmt, size, a1, a2, a3, ...) \
    __kprog_bpf_trace_printk((fmt), (size), (unsigned long long)(a1), \
                             (unsigned long long)(a2), (unsigned long long)(a3))
#undef bpf_trace_printk
#define bpf_trace_printk(...) __kprog_trace_printk_pad(__VA_ARGS__, 0, 0, 0)
#undef bpf_ringbuf_output
#define bpf_ringbuf_output(...) __KPROG_CALL(bpf_ringbuf_output, __VA_ARGS__)
#undef bpf_ringbuf_reserve
#define bpf_ringbuf_reserve(...) __KPROG_CALL(bpf_ringbuf_reserve, __VA_ARGS__)
#undef bpf_ringbuf_submit
#define bpf_ringbuf_submit(...) __KPROG_CALL(bpf_ringbuf_submit, __VA_ARGS__)
#undef bpf_ringbuf_discard
#define bpf_ringbuf_discard(...) __KPROG_CALL(bpf_ringbuf_discard, __VA_ARGS__)
#undef bpf_ringbuf_query
#define bpf_ringbuf_query(...) __KPROG_CALL(bpf_ringbuf_query, __VA_ARGS__)
#undef bpf_seq_write
#define bpf_seq_write(...) __KPROG_CALL(bpf_seq_write, __VA_ARGS__)
#undef bpf_loop
#define bpf_loop(...) __KPROG_CALL(bpf_loop, __VA_ARGS__)
#undef bpf_tail_call
#define bpf_tail_call(...) __KPROG_CALL(bpf_tail_call, __VA_ARGS__)
#undef bpf_current_task_under_cgroup
#define bpf_current_task_under_cgroup(...) __KPROG_CALL(bpf_current_task_under_cgroup, __VA_ARGS__)
#undef bpf_get_stackid
#define bpf_get_stackid(...) __KPROG_CALL(bpf_get_stackid, __VA_ARGS__)
#undef bpf_get_stack
#define bpf_get_stack(...) __KPROG_CALL(bpf_get_stack, __VA_ARGS__)
#undef bpf_sk_fullsock
#define bpf_sk_fullsock(...) __KPROG_CALL(bpf_sk_fullsock, __VA_ARGS__)
#undef bpf_skb_load_bytes
#define bpf_skb_load_bytes(...) __KPROG_CALL(bpf_skb_load_bytes, __VA_ARGS__)
#undef bpf_skb_load_bytes_relative
#define bpf_skb_load_bytes_relative(...) __KPROG_CALL(bpf_skb_load_bytes_relative, __VA_ARGS__)
#undef bpf_redirect
#define bpf_redirect(...) __KPROG_CALL(bpf_redirect, __VA_ARGS__)
#undef bpf_skb_adjust_room
#define bpf_skb_adjust_room(...) __KPROG_CALL(bpf_skb_adjust_room, __VA_ARGS__)
#undef bpf_skb_set_tunnel_key
#define bpf_skb_set_tunnel_key(...) __KPROG_CALL(bpf_skb_set_tunnel_key, __VA_ARGS__)
#undef bpf_xdp_adjust_head
#define bpf_xdp_adjust_head(...) __KPROG_CALL(bpf_xdp_adjust_head, __VA_ARGS__)
#undef bpf_xdp_adjust_tail
#define bpf_xdp_adjust_tail(...) __KPROG_CALL(bpf_xdp_adjust_tail, __VA_ARGS__)
#undef bpf_csum_diff
#define bpf_csum_diff(...) __KPROG_CALL(bpf_csum_diff, __VA_ARGS__)

/* Kernel memory reads are plain loads (operator 2026-11-19: "读内核内存要调用 bpf_probe_read
 * ... 不能也直接内联和解引用???"). native-link records every load of P as a load site; a faulting
 * load reads 0 and continues, the JIT's PROBE_MEM behaviour. The empty asm keeps each value in a
 * general register (the site's fixup destination) and the address in a register. Lower-half
 * addresses get the helper's answer for them: -ERANGE and a zeroed destination. */
typedef unsigned long long __attribute__((may_alias, aligned(1))) __native_u64;
typedef unsigned int __attribute__((may_alias, aligned(1))) __native_u32;
typedef unsigned short __attribute__((may_alias, aligned(1))) __native_u16;
#define __NATIVE_LOAD(type, p) ({ type __v = *(const volatile type *)(p); asm volatile("" : "+r"(__v)); __v; })
#define __NATIVE_KERNEL_ADDRESS(p) ((long)(unsigned long)(p) < 0)
static __always_inline long __native_read_kernel(void *dst, unsigned int size, const void *src)
{
    char *d = dst;
    const char *s = src;
    unsigned int i = 0;

    asm volatile("" : "+r"(s));
    if (!__NATIVE_KERNEL_ADDRESS(s)) {
        __builtin_memset(d, 0, size);
        return -34; /* -ERANGE */
    }
    for (; i + 8 <= size; i += 8)
        *(__native_u64 *)(d + i) = __NATIVE_LOAD(__native_u64, s + i);
    if (size & 4) { *(__native_u32 *)(d + i) = __NATIVE_LOAD(__native_u32, s + i); i += 4; }
    if (size & 2) { *(__native_u16 *)(d + i) = __NATIVE_LOAD(__native_u16, s + i); i += 2; }
    if (size & 1) d[i] = __NATIVE_LOAD(char, s + i);
    return 0;
}
static __always_inline long __native_read_kernel_str(void *dst, unsigned int size, const void *src)
{
    char *d = dst;
    const char *s = src;
    unsigned int i = 0;

    asm volatile("" : "+r"(s));
    if (!size)
        return 0;
    if (!__NATIVE_KERNEL_ADDRESS(s)) {
        __builtin_memset(d, 0, size);
        return -34; /* -ERANGE */
    }
    for (; i + 1 < size; i++) {
        char c = __NATIVE_LOAD(char, s + i);
        d[i] = c;
        if (!c)
            return i + 1;
    }
    d[i] = 0;
    return size;
}
/* bpf_probe_read and bpf_probe_read_str pick kernel or user memory by address. */
static __always_inline long __native_probe_read(void *dst, unsigned int size, const void *src)
{
    return __NATIVE_KERNEL_ADDRESS(src) ? __native_read_kernel(dst, size, src)
                                        : __KPROG_CALL(bpf_probe_read_user, dst, size, src);
}
static __always_inline long __native_probe_read_str(void *dst, unsigned int size, const void *src)
{
    return __NATIVE_KERNEL_ADDRESS(src) ? __native_read_kernel_str(dst, size, src)
                                        : __KPROG_CALL(bpf_probe_read_user_str, dst, size, src);
}
#undef bpf_probe_read_kernel
#define bpf_probe_read_kernel(dst, size, src) __native_read_kernel((dst), (size), (src))
#undef bpf_probe_read_kernel_str
#define bpf_probe_read_kernel_str(dst, size, src) __native_read_kernel_str((dst), (size), (src))
#undef bpf_probe_read
#define bpf_probe_read(dst, size, src) __native_probe_read((dst), (size), (src))
#undef bpf_probe_read_str
#define bpf_probe_read_str(dst, size, src) __native_probe_read_str((dst), (size), (src))

#endif
