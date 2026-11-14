/* Caller-owned storage/profile for the production address consumers. */
#ifndef KPROG_ARM64_ADDRESSING_H
#define KPROG_ARM64_ADDRESSING_H
#include "Arm64Address.h"
struct kprog_arm64_addressing {
	struct kprog_arm64_coordinates *coordinates;
	union arm64_sim_gpr *registers;
	__u8 *tags;
	volatile __u8 *b;
	__u8 *stack_tags;
	__u64 *payload;
	__u32 capacity;
	__s64 bias;
	void *helper_context, *helper_abi_base;
	__u8 is_xdp, abi_kind;
};
__u64 kprog_arm64_modified_reg(struct kprog_arm64_addressing *, __u64, __u8, __u8, __u8);
__s64 kprog_arm64_memory_offset(struct kprog_arm64_addressing *, __u32, __u64, __u64);
void *kprog_arm64_helper_argument(struct kprog_arm64_addressing *, __u64);
void *kprog_arm64_helper_context(struct kprog_arm64_addressing *, __u64);
void kprog_arm64_memory_pre(struct kprog_arm64_addressing *, __u64, __u32, __u64);
void kprog_arm64_memory_post(struct kprog_arm64_addressing *, __u64, __u32, __u64);
__u8 kprog_arm64_memory_tag(struct kprog_arm64_addressing *, __u64, __u64, __u32, __u64, __s64, __u8);
__u64 kprog_arm64_memory_payload(struct kprog_arm64_addressing *, __u64, __u64, __u32, __u64, __s64, __u64, __u8);
__u64 kprog_arm64_xdp_read(struct kprog_arm64_addressing *, __u64, __s64, __u8);
__u64 kprog_arm64_skb_read(struct kprog_arm64_addressing *, __u64, __s64, __u8);
void kprog_arm64_skb_write(struct kprog_arm64_addressing *, __u64, __s64, __u8, __u64);
__u64 kprog_arm64_cb_read(void *, __s64, __u8);
void kprog_arm64_cb_write(void *, __s64, __u8, __u64);
#endif
