#define X86_SIM_ENABLE_STACK 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int cilium_bpf_overlay___mcast_ep_delivery_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5:
	/* 0x5: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_8:
	/* 0x8: je     49 <__mcast_ep_delivery+0x49> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8, 0x49, x86_l_49);
x86_l_a:
	/* 0xa: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_d:
	/* 0xd: je     49 <__mcast_ep_delivery+0x49> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd, 0x49, x86_l_49);
x86_l_f:
	/* 0xf: mov    rdi,QWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12:
	/* 0x12: test   rdi,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_64);
x86_l_15:
	/* 0x15: je     49 <__mcast_ep_delivery+0x49> */
	X86_SIM_X86_JCC(X86_CC_E, 0x15, 0x49, x86_l_49);
x86_l_17:
	/* 0x17: test   BYTE PTR [rdx+0xb],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 47244640257ULL);
x86_l_1b:
	/* 0x1b: jne    47 <__mcast_ep_delivery+0x47> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1b, 0x47, x86_l_47);
x86_l_1d:
	/* 0x1d: mov    esi,DWORD PTR [rdx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_20:
	/* 0x20: test   esi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_32);
x86_l_22:
	/* 0x22: je     49 <__mcast_ep_delivery+0x49> */
	X86_SIM_X86_JCC(X86_CC_E, 0x22, 0x49, x86_l_49);
x86_l_24:
	/* 0x24: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_25:
	/* 0x25: mov    rbx,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RCX, X86_WIDTH_64);
x86_l_28:
	/* 0x28: mov    eax,0xd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 13ULL);
x86_l_2d:
	/* 0x2d: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f:
	/* 0x2f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31:
	/* 0x31: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_33:
	/* 0x33: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_35:
	/* 0x35: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_37:
	/* 0x37: je     41 <__mcast_ep_delivery+0x41> */
	X86_SIM_X86_JCC(X86_CC_E, 0x37, 0x41, x86_l_41);
x86_l_39:
	/* 0x39: mov    DWORD PTR [rbx+0x8],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3c:
	/* 0x3c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_41:
	/* 0x41: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_42:
	/* 0x42: jmp    4e <__mcast_ep_delivery+0x4e> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_47:
	/* 0x47: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_49:
	/* 0x49: jmp    4e <__mcast_ep_delivery+0x4e> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_4e:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
