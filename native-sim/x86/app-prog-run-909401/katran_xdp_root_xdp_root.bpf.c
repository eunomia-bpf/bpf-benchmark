extern char root_array;
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int katran_xdp_root_xdp_root_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_3:
	/* 0x3: mov    r14,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&root_array)));
x86_l_a:
	/* 0xa: mov    r15d,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 12ULL);
x86_l_10:
	/* 0x10: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_13:
	/* 0x13: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15:
	/* 0x15: call   r15 */
	X86_SIM_BPF_CALL_REG(X86_R15);
x86_l_18:
	/* 0x18: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1b:
	/* 0x1b: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_1e:
	/* 0x1e: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_23:
	/* 0x23: call   r15 */
	X86_SIM_BPF_CALL_REG(X86_R15);
x86_l_26:
	/* 0x26: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_29:
	/* 0x29: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_2c:
	/* 0x2c: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_31:
	/* 0x31: call   r15 */
	X86_SIM_BPF_CALL_REG(X86_R15);
x86_l_34:
	/* 0x34: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_39:
	/* 0x39: jmp    3e <xdp_root+0x3e> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_3e:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
