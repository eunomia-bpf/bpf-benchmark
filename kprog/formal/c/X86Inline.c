/* Export the production inline interpreter and its actual control adapters.
 * The caller supplies live cell/fact references; this layer initializes none.
 */
#define X86_SIM_ENABLE_STACK 1
#include "../../x86/x86_sim_inline.h"

void kprog_x86_inline_execute(const struct x86_sim_inline_bindings *bindings,
                              __u8 op, __u8 dst, __u8 src, __u8 flags,
                              __u32 aux, __u64 imm)
{
	x86_sim_inline_execute(bindings, op, dst, src, flags, aux, imm);
}
