/* Root production pointer and register handlers with their existing state ABI.
 * Ghost stack facts are inputs, rather than a fresh zero-initialized fixture. */
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../../x86/x86_sim_local_bpf.h"

#undef X86_SIM_L_SV_TAG
#undef X86_SIM_L_SV_PTR
#define X86_SIM_L_SV_TAG(I) value_tags[(I)]
#define X86_SIM_L_SV_PTR(I) value_ptrs[(I)]

void kprog_x86_ptr_load(struct x86_sim_state *state,
                      __u8 *value_tags, void **value_ptrs,
                      __u8 op, __u8 dst, __u32 aux, __u64 imm)
{
	struct x86_sim_state *__x86_state = state;
	X86_SIM_L_EXEC_PTR_LOAD(op, dst, aux, imm);
}

/* Register observations and moves share the same production state aliases. */
__u64 kprog_x86_read_reg(struct x86_sim_state *state,
                        __u8 reg, __u8 width, __u8 shift)
{
	struct x86_sim_state *__x86_state = state;
	__u64 result;
	X86_SIM_L_READ_REG_WIDTH_SHIFT_INTO(result, reg, width, shift);
	return result;
}

void kprog_x86_write_reg(struct x86_sim_state *state,
                         __u8 *value_tags, void **value_ptrs,
                         __u8 reg, __u64 value, __u8 width, __u8 shift)
{
	struct x86_sim_state *__x86_state = state;
	X86_SIM_L_WRITE_REG_WIDTH_SHIFT(reg, value, width, shift);
}

void kprog_x86_mov_imm(struct x86_sim_state *state,
                       __u8 *value_tags, void **value_ptrs,
                       __u8 dst, __u8 flags, __u32 aux, __u64 imm)
{
	struct x86_sim_state *__x86_state = state;
	X86_SIM_L_EXEC_MOV_IMM_AUX(dst, flags, aux, imm);
}

void kprog_x86_mov_reg(struct x86_sim_state *state,
                       __u8 *value_tags, void **value_ptrs,
                       __u8 dst, __u8 src, __u8 flags, __u32 aux)
{
	struct x86_sim_state *__x86_state = state;
	X86_SIM_L_EXEC_MOV_REG_AUX(dst, src, flags, aux);
}

void kprog_x86_movx_reg(struct x86_sim_state *state,
                        __u8 *value_tags, void **value_ptrs,
                        __u8 op, __u8 dst, __u8 src, __u8 flags, __u32 aux)
{
	struct x86_sim_state *__x86_state = state;
	X86_SIM_L_EXEC_MOVX_REG(op, dst, src, flags, aux);
}
