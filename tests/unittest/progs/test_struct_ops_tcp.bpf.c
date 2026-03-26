// SPDX-License-Identifier: GPL-2.0

#include <linux/bpf.h>

typedef __u32 __wsum;

#include <bpf/bpf_tracing.h>
#include "bpf_helpers.h"

struct sock;
struct rate_sample;
struct ack_sample;
union tcp_cc_info;
struct module;

enum tcp_ca_event {
	CA_EVENT_TX_START,
	CA_EVENT_CWND_RESTART,
	CA_EVENT_COMPLETE_CWR,
	CA_EVENT_LOSS,
	CA_EVENT_ECN_NO_CE,
	CA_EVENT_ECN_IS_CE,
};

#define TCP_CA_NAME_MAX 16

struct tcp_congestion_ops {
	void (*cong_avoid)(struct sock *sk, __u32 ack, __u32 acked);
	void (*cong_control)(struct sock *sk, __u32 ack, int flag,
			     const struct rate_sample *rs);
	__u32 (*ssthresh)(struct sock *sk);
	void (*set_state)(struct sock *sk, __u8 new_state);
	void (*cwnd_event)(struct sock *sk, enum tcp_ca_event ev);
	void (*in_ack_event)(struct sock *sk, __u32 flags);
	void (*pkts_acked)(struct sock *sk, const struct ack_sample *sample);
	__u32 (*min_tso_segs)(struct sock *sk);
	__u32 (*undo_cwnd)(struct sock *sk);
	__u32 (*sndbuf_expand)(struct sock *sk);
	unsigned long (*get_info)(struct sock *sk, __u32 ext, int *attr,
				 union tcp_cc_info *info);
	char name[TCP_CA_NAME_MAX];
	struct module *owner;
	struct list_head list;
	__u32 key;
	__u32 flags;
	void (*init)(struct sock *sk);
	void (*release)(struct sock *sk);
};

SEC("struct_ops")
void BPF_PROG(rejit_cc_init, struct sock *sk)
{
}

SEC("struct_ops")
void BPF_PROG(rejit_cc_cong_control, struct sock *sk,
	      const struct rate_sample *rs)
{
}

SEC("struct_ops")
__u32 BPF_PROG(rejit_cc_ssthresh, struct sock *sk)
{
	return 16;
}

SEC("struct_ops")
__u32 BPF_PROG(rejit_cc_undo_cwnd, struct sock *sk)
{
	return 16;
}

SEC(".struct_ops.link")
struct tcp_congestion_ops rejit_cc = {
	.init = (void *)rejit_cc_init,
	.cong_control = (void *)rejit_cc_cong_control,
	.ssthresh = (void *)rejit_cc_ssthresh,
	.undo_cwnd = (void *)rejit_cc_undo_cwnd,
	.name = "rejit_cc",
};

char _license[] SEC("license") = "GPL";
