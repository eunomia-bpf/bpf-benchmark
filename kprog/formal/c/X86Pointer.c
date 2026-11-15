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

__s64 kprog_x86_mem_offset_indexed(__u64 aux, __s64 displacement, __u64 index, int present)
{
	__s64 offset;
	KPROG_X86_MEM_OFFSET_INTO(offset, aux, displacement, index, present);
	return offset;
}

/* Expression adapters call the already exported read/offset bodies. Arguments
 * are scalar fields; address evaluation stays behind the recovery gates. */
#undef X86_SIM_L_READ_REG_WIDTH_SHIFT
#define X86_SIM_L_READ_REG_WIDTH_SHIFT(REG, WIDTH, SHIFT) \
    kprog_x86_read_reg(state, arena, capacity, (REG), (WIDTH), (SHIFT))
__s64 kprog_x86_mem_offset(struct x86_sim_register_state *state,
                           struct kprog_x86_arena *arena, __u32 capacity,
                           __u64 aux, __s64 displacement)
{
	__s64 offset;
	X86_SIM_L_MEM_OFFSET_INTO(offset, aux, displacement);
	return offset;
}
#undef X86_SIM_L_MEM_OFFSET
#define X86_SIM_L_MEM_OFFSET(AUX, DISP) \
    kprog_x86_mem_offset(state, arena, capacity, (AUX), (DISP))

int kprog_x86_read_recovery_at(struct x86_sim_register_state *state,
                               struct kprog_x86_arena *arena,
                               struct kprog_x86_stack_fact *facts, __u32 capacity,
                               __u64 base, __u64 dst, __u64 address)
{
	struct x86_sim_register_state *__x86_state = state;
	int recovered;
	X86_SIM_L_READ_RECOVERY_AT_INTO(recovered, base, dst, address);
	return recovered;
}
int kprog_x86_read_recovery(struct x86_sim_register_state *state,
                            struct kprog_x86_arena *arena,
                            struct kprog_x86_stack_fact *facts, __u32 capacity,
                            __u64 base, __u64 dst)
{
	struct x86_sim_register_state *__x86_state = state;
	int recovered;
	X86_SIM_L_READ_RECOVERY_INTO(recovered, base, dst);
	return recovered;
}
int kprog_x86_read_recovery_mem(struct x86_sim_register_state *state,
                                struct kprog_x86_arena *arena,
                                struct kprog_x86_stack_fact *facts, __u32 capacity,
                                __u64 base, __u64 dst, __u64 aux, __s64 displacement)
{
	struct x86_sim_register_state *__x86_state = state;
	int recovered;
	X86_SIM_L_READ_RECOVERY_MEM_INTO(recovered, base, dst, aux, displacement);
	return recovered;
}

__u8 kprog_x86_mov_load_write_width(__u64 flags)
{
	__u8 width;
	KPROG_X86_MOV_LOAD_WRITE_WIDTH_INTO(width, flags);
	return width;
}
__u8 kprog_x86_mov_load_mem_width(__u64 flags, __u64 aux)
{
	__u8 width;
	KPROG_X86_MOV_LOAD_MEM_WIDTH_INTO(width, flags, aux);
	return width;
}
__u8 kprog_x86_mov_load_arm(__u64 stack, __u64 plain, __u64 memory, __u64 write, __u64 tag)
{
	__u8 arm;
	KPROG_X86_MOV_LOAD_ARM_INTO(arm, stack, plain, memory, write, tag);
	return arm;
}
