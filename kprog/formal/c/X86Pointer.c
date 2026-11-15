/* Root the same production bodies for arbitrary producer arena capacities.
 * Fact references preserve either array or scalarized caller-owned cells. */
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "X86Pointer.h"

#undef X86_SIM_L_SV_TAG
#undef X86_SIM_L_SV_PTR
#define X86_SIM_L_SV_TAG(I) (*facts[(I)].tag)
#define X86_SIM_L_SV_PTR(I) (*facts[(I)].pointer)
#undef __x86_stack_mem
#define __x86_stack_mem (*arena)
#undef X86_SIM_STACK_BYTES
#define X86_SIM_STACK_BYTES capacity
/* Bind the production free-input interface on host extraction executions too. */

void kprog_x86_ptr_load(struct x86_sim_register_state *state,
                      struct kprog_x86_arena *arena,
                      struct kprog_x86_stack_fact *facts, __u32 capacity,
                      __u8 op, __u8 dst, __u32 aux, __u64 imm)
{
	struct x86_sim_register_state *__x86_state = state;
	X86_SIM_L_EXEC_PTR_LOAD(op, dst, aux, imm);
}

/* Register observations and moves share the same production state aliases. */
__u64 kprog_x86_read_reg(struct x86_sim_register_state *state,
                         struct kprog_x86_arena *arena,
                         __u32 capacity, __u8 reg, __u8 width, __u8 shift)
{
	struct x86_sim_register_state *__x86_state = state;
	__u64 result;
	X86_SIM_L_READ_REG_WIDTH_SHIFT_INTO(result, reg, width, shift);
	return result;
}

void kprog_x86_write_reg(struct x86_sim_register_state *state,
                         struct kprog_x86_arena *arena,
                         struct kprog_x86_stack_fact *facts, __u32 capacity,
                         __u8 reg, __u64 value, __u8 width, __u8 shift)
{
	struct x86_sim_register_state *__x86_state = state;
	X86_SIM_L_WRITE_REG_WIDTH_SHIFT(reg, value, width, shift);
}

void kprog_x86_mov_imm(struct x86_sim_register_state *state,
                       struct kprog_x86_arena *arena,
                       struct kprog_x86_stack_fact *facts, __u32 capacity,
                       __u8 dst, __u8 flags, __u32 aux, __u64 imm)
{
	struct x86_sim_register_state *__x86_state = state;
	X86_SIM_L_EXEC_MOV_IMM_AUX(dst, flags, aux, imm);
}

void kprog_x86_mov_reg(struct x86_sim_register_state *state,
                       struct kprog_x86_arena *arena,
                       struct kprog_x86_stack_fact *facts, __u32 capacity,
                       __u8 dst, __u8 src, __u8 flags, __u32 aux)
{
	struct x86_sim_register_state *__x86_state = state;
	X86_SIM_L_EXEC_MOV_REG_AUX(dst, src, flags, aux);
}

void kprog_x86_movx_reg(struct x86_sim_register_state *state,
                        struct kprog_x86_arena *arena,
                        struct kprog_x86_stack_fact *facts, __u32 capacity,
                        __u8 op, __u8 dst, __u8 src, __u8 flags, __u32 aux)
{
	struct x86_sim_register_state *__x86_state = state;
	X86_SIM_L_EXEC_MOVX_REG(op, dst, src, flags, aux);
}

/* Actual tagged-memory primitives, including read-before-release observation.
 * Full-width width/tag inputs retain the native macro's capture boundaries. */
__s64 kprog_x86_stack_alias(struct kprog_x86_arena *arena, __u32 capacity,
                            const void *address)
{
	__s64 result;
	X86_SIM_L_STACK_ALIAS_OFFSET_INTO(result, address);
	return result;
}

__u64 kprog_x86_load_tagged(struct x86_sim_register_state *state,
                            struct kprog_x86_arena *arena, __u32 capacity,
                            const void *address, __u64 width, __u64 tag)
{
	struct x86_sim_register_state *__x86_state = state;
	__u64 result;
	X86_SIM_L_LOAD_ADDR_TAGGED_INTO(result, address, width, tag);
	return result;
}

__u64 kprog_x86_native_load_tagged(struct x86_sim_register_state *state,
                                   struct kprog_x86_arena *arena, __u32 capacity,
                                   const void *base, __s64 offset, __u64 width, __u64 tag)
{
	struct x86_sim_register_state *__x86_state = state;
	__u64 result;
	X86_SIM_L_NATIVE_DATA_LOAD_TAGGED_INTO(result, base, offset, width, tag);
	return result;
}
