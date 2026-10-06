#include "../arm64_sim_local_bpf.h"

/*
 * Negative kprog proof fixture: the native program reads a packet byte
 * without first proving that the byte is within data_end.  The generated
 * simulator artifact must preserve that unsafe access so the BPF verifier
 * rejects it.
 */
#include "../../test/include/native_helpers.h"

SEC("xdp")
int unchecked_packet_read_arm64_sim_xdp(struct xdp_md *ctx)
{
	ARM64_SIM_ENTRY_XDP(ctx);
arm64_l_0:
	/* 0x0: ldr x8, [x0] */
	ARM64_SIM_RUN_OP3(ARM64_OP_LOAD, ARM64_X8, ARM64_X0, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_MEM(ARM64_REG_NONE, ARM64_MOD_NONE, 0, 0), 0ULL);
arm64_l_4:
	/* 0x4: ldrb w0, [x8, #64] */
	ARM64_SIM_RUN_OP3(ARM64_OP_LOAD, ARM64_X0, ARM64_X8, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_8, ARM64_AUX_MEM(ARM64_REG_NONE, ARM64_MOD_NONE, 0, 0), 64ULL);
arm64_l_8:
	/* 0x8: b 10 <__native_link_arm64_ret_trampoline> */
	ARM64_SIM_A64_JMP(0x8, 0x10, arm64_l_10);
arm64_l_c:
	/* 0xc: nop */
	ARM64_SIM_RUN_OP3(ARM64_OP_NOP, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, 0, 0);
arm64_l_10:
	/* 0x10: mov x7, x0 */
	ARM64_SIM_RUN_OP3(ARM64_OP_MOV_REG, ARM64_X7, ARM64_X0, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, 0, 0);
	ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X0, ARM64_SIM_L_READ_REG(ARM64_X7), ARM64_WIDTH_64);
	ARM64_SIM_RET();
}

ARM64_SIM_LICENSE();
