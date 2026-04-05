#ifndef REMOTE_SELFTEST_COMPAT_H
#define REMOTE_SELFTEST_COMPAT_H

#ifdef __BPF__
#include <linux/types.h>

struct sk_buff;
struct Qdisc;
struct bpf_sk_buff_ptr;

extern void bpf_qdisc_skb_drop(struct sk_buff *skb,
                               struct bpf_sk_buff_ptr *to_free_list) __ksym;
extern void bpf_qdisc_bstats_update(struct Qdisc *sch,
                                    const struct sk_buff *skb) __ksym;
extern void bpf_kfree_skb(struct sk_buff *skb) __ksym;
extern __u32 bpf_skb_get_hash(struct sk_buff *skb) __ksym;
extern void bpf_qdisc_watchdog_schedule(struct Qdisc *sch, __u64 expire,
                                        __u64 delta_ns) __ksym;
#endif

#endif
