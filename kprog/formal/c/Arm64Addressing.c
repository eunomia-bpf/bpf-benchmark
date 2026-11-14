/* Root existing production consumers; numerical operations remain canonical. */
#define ARM64_SIM_ENABLE_STACK 1
#include "Arm64Addressing.h"
#undef ARM64_SIM_STACK_BYTES
#define ARM64_SIM_STACK_BYTES (addressing->capacity)
#undef ARM64_SIM_STACK_BIAS
#define ARM64_SIM_STACK_BIAS (addressing->bias)
#undef ARM64_SIM_L_UNSPECIFIED
#define ARM64_SIM_L_UNSPECIFIED() NATIVE_LAB_ENTRY_INPUT(NATIVE_LAB_INPUT_UNSPECIFIED)
#define __a64_stack (*addressing)
#define __a64_stack_tag (addressing->stack_tags)
#define __a64_stack_payload (addressing->payload)
#define __a64_sp (addressing->coordinates->stack_offset)
#define __a64_numeric_sp (addressing->coordinates->sp_base)
#define __a64_numeric_return (addressing->coordinates->return_base)
#define __a64_numeric_sp_valid (addressing->coordinates->sp_valid)
#define __a64_numeric_return_valid (addressing->coordinates->return_valid)
#define __a64_sim_helper_ctx (addressing->helper_context)
#define __a64_sim_helper_abi_base (addressing->helper_abi_base)
#define __a64_sim_is_xdp (addressing->is_xdp)
#define __a64_sim_abi_kind (addressing->abi_kind)
#define CELL(REG, NAME) [KPROG_ARM64_GPR_CELL(REG)] = &addressing->registers[KPROG_ARM64_GPR_CELL(REG)],
#define TAG(REG, NAME) [KPROG_ARM64_GPR_CELL(REG)] = &addressing->tags[KPROG_ARM64_GPR_CELL(REG)],
#define REGISTERS() \
	union arm64_sim_gpr *const __a64_cells[31] = { ARM64_SIM_L_FOR_EACH_GPR(CELL) }; \
	__u8 *const __a64_tag_cells[31] = { ARM64_SIM_L_FOR_EACH_GPR(TAG) }

__u64 kprog_arm64_modified_reg(struct kprog_arm64_addressing *addressing,
                              __u64 reg, __u8 mod, __u8 shift, __u8 width)
{
	REGISTERS();
	__u64 result;
	ARM64_SIM_L_MOD_VALUE_INTO(result, reg, mod, shift, width);
	return result;
}
__s64 kprog_arm64_memory_offset(struct kprog_arm64_addressing *addressing,
                               __u32 aux, __u64 index, __u64 imm)
{
	REGISTERS();
	__s64 result;
	ARM64_SIM_L_MEM_BASE_OFF_INTO(result, aux, index, imm);
	return result;
}
void *kprog_arm64_helper_argument(struct kprog_arm64_addressing *addressing, __u64 reg)
{
	REGISTERS();
	void * result;
	ARM64_SIM_L_HELPER_ARG_PTR_INTO(result, reg);
	return result;
}
void *kprog_arm64_helper_context(struct kprog_arm64_addressing *addressing, __u64 reg)
{
	REGISTERS();
	void * result;
	ARM64_SIM_L_HELPER_CTX_PTR_INTO(result, reg);
	return result;
}
void kprog_arm64_memory_pre(struct kprog_arm64_addressing *addressing,
                           __u64 base, __u32 aux, __u64 imm)
{
	REGISTERS();
	ARM64_SIM_L_MEM_PRE(base, aux, imm);
}
void kprog_arm64_memory_post(struct kprog_arm64_addressing *addressing,
                            __u64 base, __u32 aux, __u64 imm)
{
	REGISTERS();
	ARM64_SIM_L_MEM_POST(base, aux, imm);
}
__u8 kprog_arm64_memory_tag(struct kprog_arm64_addressing *addressing,
                           __u64 base, __u64 index, __u32 aux, __u64 imm,
                           __s64 extra, __u8 width)
{
	REGISTERS();
	__u8 result;
	ARM64_SIM_L_MEM_READ_TAG_INTO(result, base, index, aux, imm, extra, width);
	return result;
}
__u64 kprog_arm64_memory_payload(struct kprog_arm64_addressing *addressing,
                                __u64 base, __u64 index, __u32 aux, __u64 imm,
                                __s64 extra, __u64 value, __u8 tag)
{
	REGISTERS();
	__u64 result;
	ARM64_SIM_L_MEM_PAYLOAD_INTO(result, base, index, aux, imm, extra, value, tag);
	return result;
}
