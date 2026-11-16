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
	/* q and b name the same live private arena, as in Arm64Stack.h. */
	volatile __u64 *q;
};
/* The production state holds32 anonymous {lo,hi} vector cells. */
struct kprog_arm64_vector { __u64 lo, hi; };
int kprog_arm64_branch_test(__u64, __u64, __u64);
void kprog_arm64_helper_clobbers(struct kprog_arm64_addressing *, struct kprog_arm64_vector *, __u8 *, __u8 *, __u8 *, __u8 *);
void kprog_arm64_libc_memset(struct kprog_arm64_addressing *, struct kprog_arm64_vector *, __u8 *, __u8 *, __u8 *, __u8 *);
void kprog_arm64_libc_memcpy(struct kprog_arm64_addressing *, struct kprog_arm64_vector *, __u8 *, __u8 *, __u8 *, __u8 *);
int kprog_arm64_jcc(struct kprog_arm64_addressing *, __u8 *, __u8 *, __u8 *, __u8 *, __u64, __u64, __u64);
int kprog_arm64_cbz_x(struct kprog_arm64_addressing *, __u64, __u64, __u64, __u64);
int kprog_arm64_cbz_w(struct kprog_arm64_addressing *, __u64, __u64, __u64, __u64);
int kprog_arm64_tbz(struct kprog_arm64_addressing *, __u64, __u64, __u64, __u64, __u64);
int kprog_arm64_cmp_gt(struct kprog_arm64_addressing *, __u8 *, __u8 *, __u8 *, __u8 *, __u32, __u64, __u64, __u8, __u32, __u64);
__u64 kprog_arm64_link(struct kprog_arm64_addressing *, __u64);
__u32 kprog_arm64_exit(struct kprog_arm64_addressing *);
__u32 kprog_arm64_return_to(struct kprog_arm64_addressing *, __u64);
__u64 kprog_arm64_mov_path(__u64, __u64);
__u64 kprog_arm64_csel_path(__u64, __u64);
__u8 kprog_arm64_alu_source(__u64);
__u64 kprog_arm64_flag_rhs(__u64, __u64, __u64);
__u64 kprog_arm64_movk(__u64, __u64, __u64);
__u64 kprog_arm64_alu_result(__u64, __u64, __u64);
__u64 kprog_arm64_reduction(__u64, __u64);
__u64 kprog_arm64_fmov_dest(__u64);
void kprog_arm64_execute(struct kprog_arm64_addressing *, struct kprog_arm64_vector *,
                         __u8 *, __u8 *, __u8 *, __u8 *, __u32, __u64, __u64,
                         __u64, __u64, __u8, __u32, __u64);
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
__u64 kprog_arm64_memory_read(struct kprog_arm64_addressing *, __u64, __u64, __u32, __u64, __s64, __u8);
void kprog_arm64_memory_write(struct kprog_arm64_addressing *, __u64, __u64, __u32, __u64, __s64, __u8, __u64, __u8);
int kprog_arm64_read_fault(struct kprog_arm64_addressing *, __u64, __u64, __u32, __u64);
void kprog_arm64_load(struct kprog_arm64_addressing *, __u64, __u64, __u64, __u32, __u64, __u8);
void kprog_arm64_signed_load(struct kprog_arm64_addressing *, __u32, __u64, __u64, __u64, __u32, __u64, __u8);
void kprog_arm64_store(struct kprog_arm64_addressing *, __u64, __u64, __u64, __u32, __u64, __u8);
void kprog_arm64_pair_step(struct kprog_arm64_addressing *, __u32, __u64, __u64, __u64, __u64, __u64, __u32, __u64, __u8);
void kprog_arm64_vector_step(struct kprog_arm64_addressing *, __u64 *, __u64 *, __u32, __u64, __u64, __u32, __u64);
void kprog_arm64_exclusive_store(struct kprog_arm64_addressing *, __u64, __u64, __u64, __u32, __u64, __u8);
void kprog_arm64_atomic_add(struct kprog_arm64_addressing *, __u64, __u64, __u64, __u32, __u8);
void kprog_arm64_atomic_set(struct kprog_arm64_addressing *, __u64, __u64, __u64, __u32, __u8);
void kprog_arm64_atomic_clear(struct kprog_arm64_addressing *, __u64, __u64, __u64, __u32, __u8);
void kprog_arm64_memory_tags(struct kprog_arm64_addressing *, __s64, __u8, __s64, __u8, __u64, __u8);
/* A symbolic function pointer is supplied by the platform binding. Its type
 * matches libbpf; the production helper's numeric identity stays unchanged. */
#define KPROG_ARM64_HELPER(ID, NAME, RESULT, ARGS) \
void kprog_arm64_helper_##NAME(struct kprog_arm64_addressing *, struct kprog_arm64_vector *, \
                               __u8 *, __u8 *, __u8 *, __u8 *, RESULT (*NAME) ARGS);
#include "Arm64HelperCalls.h"
#undef KPROG_ARM64_HELPER
#endif
