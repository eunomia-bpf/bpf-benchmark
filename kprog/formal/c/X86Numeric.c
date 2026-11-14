/* Export the production numeric helpers, without copying their bodies. */
#include <linux/types.h>
#ifndef __always_inline
#define __always_inline inline
#endif
#include "../../x86/x86_sim.h"

/* A public extraction root keeps the production static helper and its real
 * callees reachable; an include-only unit is pruned by CompCert's frontend. */
__u64 kprog_x86_alu_result(__u64 lhs, __u64 rhs, __u32 operation, __u8 width)
{
	return x86_alu_result(lhs, rhs, operation, width);
}
