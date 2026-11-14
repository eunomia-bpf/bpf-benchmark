/* Extraction ABI: caller-owned complete byte/tag storage and native profile.
 * Packed tag storage retains its canonical size, alignment and padding. */
#ifndef KPROG_ARM64_ADDRESS_BINDING_H
#define KPROG_ARM64_ADDRESS_BINDING_H
#include "../../arm64/arm64_sim_local_bpf.h"

struct kprog_arm64_coordinates {
	__u64 sp_base, return_base;
	__s64 stack_offset;
	__u8 sp_valid, return_valid;
};
__u64 kprog_arm64_stack_base(struct kprog_arm64_coordinates *);
__u64 kprog_arm64_return_base(struct kprog_arm64_coordinates *);
__u64 kprog_arm64_materialize(struct kprog_arm64_coordinates *, __u64, __u8);
__u64 kprog_arm64_unmaterialize(struct kprog_arm64_coordinates *, __u64, __u8);
__u64 kprog_arm64_read_reg(struct kprog_arm64_coordinates *, union arm64_sim_gpr *, __u8 *, __u64);
void kprog_arm64_write_reg(struct kprog_arm64_coordinates *, union arm64_sim_gpr *, __u8 *,
                           volatile __u8 *, __u8 *, __u32, __s64, __u64, __u64, __u8);
void kprog_arm64_write_ptr(struct kprog_arm64_coordinates *, union arm64_sim_gpr *, __u8 *,
                           volatile __u8 *, __u8 *, __u32, __s64, __u64, void *, __u8);
void kprog_arm64_exec_adrp(struct kprog_arm64_coordinates *, union arm64_sim_gpr *, __u8 *,
                          volatile __u8 *, __u8 *, __u32, __s64, __u64, __u64, __u64);
#endif
