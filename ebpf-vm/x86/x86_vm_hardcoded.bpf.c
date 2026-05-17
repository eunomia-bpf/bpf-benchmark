#include "x86_vm_bpf.h"

#define SIMPLE_X86_PROG_LEN 2

#define SIMPLE_X86_PROG_INIT                                                \
	{                                                                   \
		{ X86_OP_MOV_IMM64, X86_RAX, 0, 0, 0,                      \
		  12345678ULL },                                            \
		{ X86_OP_RET, 0, 0, 0, 0, 0 },                              \
	}

SEC("xdp")
int x86_vm_hardcoded_xdp(struct xdp_md *ctx)
{
	const struct x86_insn prog[SIMPLE_X86_PROG_LEN] = SIMPLE_X86_PROG_INIT;

	return X86_VM_RUN_XDP(ctx, prog, SIMPLE_X86_PROG_LEN);
}

X86_VM_LICENSE();
