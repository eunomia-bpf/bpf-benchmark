/* Production handlers over borrowed entry locals; no copied register bank. */
#ifndef KPROG_ARM64_PROGRAM_H
#define KPROG_ARM64_PROGRAM_H
#include "Arm64Entry.h"
#include "Arm64Addressing.h"
__u64 kprog_arm64_shift(__u64, __u64, __u64, __u64);
__u64 kprog_arm64_imm_operand(__u64, __u64, __u64);
__u64 kprog_arm64_program_raw(struct kprog_arm64_entry *, __u64);
void *kprog_arm64_program_pointer(struct kprog_arm64_entry *, __u64);
__u32 kprog_arm64_program_tag(struct kprog_arm64_entry *, __u64);
__u64 kprog_arm64_program_read(struct kprog_arm64_entry *, __u64);
void kprog_arm64_program_write(struct kprog_arm64_entry *, __u64, __u64, __u8);
void kprog_arm64_program_write_pointer(struct kprog_arm64_entry *, __u64, void *, __u8);
__u64 kprog_arm64_program_modified(struct kprog_arm64_entry *, __u64, __u8, __u8, __u8);
__u64 kprog_arm64_program_memory_read(struct kprog_arm64_entry *, __u64, __u64, __u32, __u64, __s64, __u8);
void *kprog_arm64_program_argument(struct kprog_arm64_entry *, __u64);
void *kprog_arm64_program_context(struct kprog_arm64_entry *, __u64);
int kprog_arm64_program_condition(__u64, const __u8 *, const __u8 *, const __u8 *, const __u8 *);
void kprog_arm64_program_clobbers(struct kprog_arm64_entry *);
void kprog_arm64_program_memset(struct kprog_arm64_entry *);
void kprog_arm64_program_memcpy(struct kprog_arm64_entry *);
void kprog_arm64_program_execute(struct kprog_arm64_entry *, __u32, __u64, __u64, __u64, __u64, __u8, __u32, __u64);
#define KPROG_ARM64_HELPER(ID, NAME, RESULT, ARGS) \
void kprog_arm64_program_helper_##NAME(struct kprog_arm64_entry *, RESULT (*NAME) ARGS);
#include "Arm64HelperCalls.h"
#undef KPROG_ARM64_HELPER
#endif
