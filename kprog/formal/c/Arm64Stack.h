/* Private-stack extraction ABI. b/q name the same live arena, tags has the
 * canonical aligned packed extent, and payload has one cell per stack word.
 * Coordinates and all storage are caller-owned inputs, including padding. */
#ifndef KPROG_ARM64_STACK_BINDING_H
#define KPROG_ARM64_STACK_BINDING_H
#include "Arm64Address.h"
struct kprog_arm64_memory {
	struct kprog_arm64_coordinates *coordinates;
	volatile __u8 *b;
	volatile __u64 *q;
	__u8 *tags;
	__u64 *payload;
	__u32 capacity;
	__s64 bias;
};
__u64 kprog_arm64_stack_read_owned(struct kprog_arm64_memory *, __s64, __u8);
__u64 kprog_arm64_stack_read(struct kprog_arm64_memory *, __s64, __u8);
__u8 kprog_arm64_stack_read_tag(struct kprog_arm64_memory *, __s64, __u8);
void kprog_arm64_stack_write_owned(struct kprog_arm64_memory *, __s64, __u8, __u64, __u8);
void kprog_arm64_stack_write(struct kprog_arm64_memory *, __s64, __u8, __u64, __u8);
void *kprog_arm64_stack_pointer(struct kprog_arm64_memory *, __s64);
#endif
