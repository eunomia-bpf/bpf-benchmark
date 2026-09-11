#include "../x86_sim_local_bpf.h"

/*
 * Negative kprog proof fixture: the native program reads a packet byte
 * without first proving that the byte is within data_end.  The generated
 * simulator artifact must preserve that unsafe access so the BPF verifier
 * rejects it.
 */
#include "../../test/include/native_helpers.h"

SEC("xdp")
int unchecked_packet_read_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: mov    rax,QWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3:
	/* 0x3: movzx  eax,BYTE PTR [rax+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 64ULL);
x86_l_7:
	/* 0x7: jmp    c <unchecked_packet_read+0xc> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_c:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
