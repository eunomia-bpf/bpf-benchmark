/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */
/* Context declarations from vendor/libbpf/include/uapi/linux/bpf.h.
 * Copyright (c) 2011-2014 PLUMgrid, http://plumgrid.com
 * Only padding syntax changes: complete fields/layouts are checked against
 * the original header by oracles/test_bpf_abi_layout.c. Normal builds retain
 * their original Linux/vmlinux declarations and compiler trap.
 */
#ifndef KPROG_CLIGHT_PLATFORM_H
#define KPROG_CLIGHT_PLATFORM_H
#if defined(__COMPCERT__)
#include <linux/types.h>
struct bpf_flow_keys;
struct bpf_sock;
#define KPROG_BPF_MD_PTR(type, name) \
  union { type name; __u64 __kprog_padding_##name; } __attribute__((aligned(8)))
struct __sk_buff {
	__u32 len;
	__u32 pkt_type;
	__u32 mark;
	__u32 queue_mapping;
	__u32 protocol;
	__u32 vlan_present;
	__u32 vlan_tci;
	__u32 vlan_proto;
	__u32 priority;
	__u32 ingress_ifindex;
	__u32 ifindex;
	__u32 tc_index;
	__u32 cb[5];
	__u32 hash;
	__u32 tc_classid;
	__u32 data;
	__u32 data_end;
	__u32 napi_id;

	/* Accessed by BPF_PROG_TYPE_sk_skb types from here to ... */
	__u32 family;
	__u32 remote_ip4;	/* Stored in network byte order */
	__u32 local_ip4;	/* Stored in network byte order */
	__u32 remote_ip6[4];	/* Stored in network byte order */
	__u32 local_ip6[4];	/* Stored in network byte order */
	__u32 remote_port;	/* Stored in network byte order */
	__u32 local_port;	/* stored in host byte order */
	/* ... here. */

	__u32 data_meta;
	KPROG_BPF_MD_PTR(struct bpf_flow_keys *, flow_keys);
	__u64 tstamp;
	__u32 wire_len;
	__u32 gso_segs;
	KPROG_BPF_MD_PTR(struct bpf_sock *, sk);
	__u32 gso_size;
	__u8  tstamp_type;
	__u8 __kprog_reserved[3];		/* Padding, future use. */
	__u64 hwtstamp;
};

struct xdp_md {
	__u32 data;
	__u32 data_end;
	__u32 data_meta;
	/* Below access go through struct xdp_rxq_info */
	__u32 ingress_ifindex; /* rxq->dev->ifindex */
	__u32 rx_queue_index;  /* rxq->queue_index  */

	__u32 egress_ifindex;  /* txq->dev->ifindex */
};

struct bpf_dynptr {
	__u64 __opaque[2];
} __attribute__((aligned(8)));
#undef KPROG_BPF_MD_PTR
_Static_assert(sizeof(void *) == 8, "kprog models the 64-bit BPF context ABI");
/* This is a platform boundary, never a returning or zero-valued fallback.
 * Clight fault refinements must supply its nonreturning external semantics. */
extern void kprog_c_trap(void) __attribute__((noreturn));
#define KPROG_C_TRAP() kprog_c_trap()
/* CompCert's alignment-1 memcpy builtin has upstream Clight semantics for
 * the complete byte window, including pointer fragments. These adapters
 * keep typed local storage aligned without imposing alignment on the source
 * or destination. Native volatile/BPF accesses keep their existing bodies. */
#define KPROG_C_UNALIGNED_LOAD_INTO(OUTPUT, TYPE, BASE, OFFSET) \
    do { TYPE __kprog_c_load_value; \
         __builtin_memcpy_aligned(&__kprog_c_load_value, \
             (const __u8 *)(BASE) + (OFFSET), sizeof(TYPE), 1); \
         (OUTPUT) = __kprog_c_load_value; } while (0)
#define KPROG_C_UNALIGNED_STORE(TYPE, ADDR, VALUE) \
    do { TYPE __kprog_c_store_value = (TYPE)(VALUE); \
         __builtin_memcpy_aligned((void *)(ADDR), &__kprog_c_store_value, \
             sizeof(TYPE), 1); } while (0)
/* Empty register asm preserves the value; only native compilation needs the
 * optimizer barrier. This adapter applies only to that identity operation. */
#define KPROG_C_BARRIER_VAR(VAR) ((void)(VAR))
#define KPROG_C_VALUE_BARRIER_VAR(VAR) ((void)(VAR))
#else
#define KPROG_C_TRAP() __builtin_trap()
#define KPROG_C_BARRIER_VAR(VAR) __asm__ volatile("" : "+r"(VAR))
#define KPROG_C_VALUE_BARRIER_VAR(VAR) __asm__("" : "+r"(VAR))
#endif
#endif
