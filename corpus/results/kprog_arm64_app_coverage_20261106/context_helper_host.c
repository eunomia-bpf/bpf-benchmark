/* Catch forged/offset ABI pointers being upgraded to ctx, stale packet views
 * after adjust helpers, and changes to ordinary stack-argument translation. */
#define ARM64_SIM_ENABLE_STACK 1
#define ARM64_SIM_STACK_BIAS 16LL
#define ARM64_SIM_STACK_BYTES 32U
#include <stdio.h>
#include "kprog/arm64/arm64_sim_local_bpf.h"

#define QUIET_STATE() do { \
	(void)__a64_cells; (void)__a64_tag_cells; \
	(void)__a64_n; (void)__a64_z; (void)__a64_c; (void)__a64_v; \
	(void)__a64_lr; (void)__a64_vectors; (void)__a64_sim_skb_ctx; \
	(void)__a64_sim_abi_kind; (void)__a64_stack; (void)__a64_stack_tag; (void)__a64_sp; \
} while (0)

int main(void)
{
	unsigned cases = 0;
	struct xdp_md ctx = { .data = 32, .data_end = 128 };
	{
		ARM64_SIM_ENTRY_XDP(&ctx);
		QUIET_STATE();
		if (ARM64_SIM_L_HELPER_CTX_PTR(ARM64_X0) != &ctx) return 1;
		cases++;
		void *offset = (unsigned char *)&__a64_sim_abi + 8;
		ARM64_SIM_L_WRITE_REG_PTR_TAG(ARM64_X1, offset, ARM64_SIM_TAG_ABI);
		if (ARM64_SIM_L_HELPER_CTX_PTR(ARM64_X1) != offset) return 1;
		cases++;
		ARM64_SIM_L_WRITE_REG_PTR_TAG(ARM64_X2, &__a64_sim_abi, ARM64_SIM_TAG_SCALAR);
		if (ARM64_SIM_L_HELPER_CTX_PTR(ARM64_X2) != &__a64_sim_abi) return 1;
		cases++;
		ARM64_SIM_L_WRITE_REG_PTR_TAG(ARM64_X3, (void *)-8L, ARM64_SIM_TAG_STACK);
		if (ARM64_SIM_L_HELPER_CTX_PTR(ARM64_X3) != (void *)&__a64_stack.b[8]) return 1;
		cases++;
		ctx.data = 64; ctx.data_end = 160;
		ARM64_SIM_L_REFRESH_XDP_CONTEXT();
		if (__a64_sim_abi.data != (void *)64 || __a64_sim_abi.data_end != (void *)160) return 1;
		cases++;
	}
	{
		ARM64_SIM_ENTRY_RAW(&ctx);
		QUIET_STATE();
		(void)__a64_sim_abi;
		if (ARM64_SIM_L_HELPER_CTX_PTR(ARM64_X0) != &ctx) return 1;
		cases++;
	}
	printf("ARM helper context identity and refresh: %u cases\n", cases);
	return 0;
}
