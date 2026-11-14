/* Root the actual private-arena bodies with the producer's storage/profile. */
#define ARM64_SIM_ENABLE_STACK 1
#include "Arm64Stack.h"
#undef ARM64_SIM_STACK_BYTES
#define ARM64_SIM_STACK_BYTES (memory->capacity)
#undef ARM64_SIM_STACK_BIAS
#define ARM64_SIM_STACK_BIAS (memory->bias)
#undef ARM64_SIM_L_UNSPECIFIED
#define ARM64_SIM_L_UNSPECIFIED() NATIVE_LAB_ENTRY_INPUT(NATIVE_LAB_INPUT_UNSPECIFIED)
#define __a64_stack (*memory)
#define __a64_stack_tag (memory->tags)
#define __a64_stack_payload (memory->payload)
#define __a64_sp (memory->coordinates->stack_offset)
#define __a64_numeric_sp (memory->coordinates->sp_base)
#define __a64_numeric_return (memory->coordinates->return_base)
#define __a64_numeric_sp_valid (memory->coordinates->sp_valid)
#define __a64_numeric_return_valid (memory->coordinates->return_valid)

__u64 kprog_arm64_stack_read_owned(struct kprog_arm64_memory *memory, __s64 off, __u8 width)
{
	__u64 result;
	ARM64_SIM_L_STACK_READ_OWNED_INTO(result, off, width);
	return result;
}
__u64 kprog_arm64_stack_read(struct kprog_arm64_memory *memory, __s64 off, __u8 width)
{
	__u64 result;
	ARM64_SIM_L_STACK_READ_INTO(result, off, width);
	return result;
}
__u8 kprog_arm64_stack_read_tag(struct kprog_arm64_memory *memory, __s64 off, __u8 width)
{
	__u8 result;
	ARM64_SIM_L_STACK_READ_TAG_INTO(result, off, width);
	return result;
}
void kprog_arm64_stack_write_owned(struct kprog_arm64_memory *memory, __s64 off,
                                  __u8 width, __u64 value, __u8 tag)
{
	ARM64_SIM_L_STACK_WRITE_OWNED(off, width, value, tag);
}
void kprog_arm64_stack_write(struct kprog_arm64_memory *memory, __s64 off,
                            __u8 width, __u64 value, __u8 tag)
{
	ARM64_SIM_L_STACK_WRITE_TAG(off, width, value, tag);
}
void *kprog_arm64_stack_pointer(struct kprog_arm64_memory *memory, __s64 off)
{
	void * result;
	ARM64_SIM_L_STACK_PTR_INTO(result, off);
	return result;
}
