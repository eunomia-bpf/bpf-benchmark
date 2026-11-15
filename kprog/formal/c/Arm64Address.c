/* Extraction bindings for the production address and register bodies.
 * Cache payloads/validity and stack facts are supplied by the caller. */
#define ARM64_SIM_ENABLE_STACK 1
#include "Arm64Address.h"

#undef ARM64_SIM_STACK_BYTES
#define ARM64_SIM_STACK_BYTES capacity
#undef ARM64_SIM_STACK_BIAS
#define ARM64_SIM_STACK_BIAS bias

#define __a64_numeric_sp (coordinates->sp_base)
#define __a64_numeric_return (coordinates->return_base)
#define __a64_numeric_sp_valid (coordinates->sp_valid)
#define __a64_numeric_return_valid (coordinates->return_valid)
#define __a64_sp (coordinates->stack_offset)
#define __a64_stack_tag stack_tags
#define KPROG_ADDRESS_CELL(REG, NAME) [KPROG_ARM64_GPR_CELL(REG)] = &registers[KPROG_ARM64_GPR_CELL(REG)],
#define KPROG_ADDRESS_TAG(REG, NAME) [KPROG_ARM64_GPR_CELL(REG)] = &tags[KPROG_ARM64_GPR_CELL(REG)],
#define KPROG_ADDRESS_REGISTERS() \
	union arm64_sim_gpr *const __a64_cells[KPROG_ARM64_GPR_COUNT] = { ARM64_SIM_L_FOR_EACH_GPR(KPROG_ADDRESS_CELL) }; \
	__u8 *const __a64_tag_cells[KPROG_ARM64_GPR_COUNT] = { ARM64_SIM_L_FOR_EACH_GPR(KPROG_ADDRESS_TAG) }
#define KPROG_ADDRESS_STACK() \
	struct { volatile __u8 *b; } __a64_stack = {stack_bytes}

__u64 kprog_arm64_stack_base(struct kprog_arm64_coordinates *coordinates)
{
	__u64 result;
	ARM64_SIM_L_STACK_BASE_INTO(result);
	return result;
}

__u64 kprog_arm64_return_base(struct kprog_arm64_coordinates *coordinates)
{
	__u64 result;
	ARM64_SIM_L_RETURN_BASE_INTO(result);
	return result;
}

__u64 kprog_arm64_materialize(struct kprog_arm64_coordinates *coordinates,
                             __u64 value, __u8 tag)
{
	__u64 result;
	ARM64_SIM_L_MATERIALIZE_INTO(result, value, tag);
	return result;
}

__u64 kprog_arm64_unmaterialize(struct kprog_arm64_coordinates *coordinates,
                               __u64 value, __u8 tag)
{
	__u64 result;
	ARM64_SIM_L_UNMATERIALIZE_INTO(result, value, tag);
	return result;
}

__u64 kprog_arm64_read_reg(struct kprog_arm64_coordinates *coordinates,
                          union arm64_sim_gpr *registers, __u8 *tags, __u64 reg)
{
	KPROG_ADDRESS_REGISTERS();
	__u64 result;
	ARM64_SIM_L_READ_REG_INTO(result, reg);
	return result;
}

void kprog_arm64_write_reg(struct kprog_arm64_coordinates *coordinates,
                           union arm64_sim_gpr *registers, __u8 *tags,
                           volatile __u8 *stack_bytes, __u8 *stack_tags,
                           __u32 capacity, __s64 bias,
                           __u64 reg, __u64 value, __u8 width)
{
	KPROG_ADDRESS_REGISTERS();
	KPROG_ADDRESS_STACK();
	ARM64_SIM_L_WRITE_REG_WIDTH(reg, value, width);
}

void kprog_arm64_write_ptr(struct kprog_arm64_coordinates *coordinates,
                           union arm64_sim_gpr *registers, __u8 *tags,
                           volatile __u8 *stack_bytes, __u8 *stack_tags,
                           __u32 capacity, __s64 bias,
                           __u64 reg, void *value, __u8 tag)
{
	KPROG_ADDRESS_REGISTERS();
	KPROG_ADDRESS_STACK();
	ARM64_SIM_L_WRITE_REG_PTR_TAG(reg, value, tag);
}

void kprog_arm64_exec_adrp(struct kprog_arm64_coordinates *coordinates,
                      union arm64_sim_gpr *registers, __u8 *tags,
                      volatile __u8 *stack_bytes, __u8 *stack_tags,
                           __u32 capacity, __s64 bias,
                      __u64 op, __u64 dst, __u64 imm)
{
	KPROG_ADDRESS_REGISTERS();
	KPROG_ADDRESS_STACK();
	ARM64_SIM_L_EXEC_ADRP(op, dst, imm);
}
