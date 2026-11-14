/* Root the production pointer-load handler with its existing state ABI.
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
