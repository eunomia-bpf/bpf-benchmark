#include "/workspaces/repository/kprog/x86/x86_sim_local_bpf.h"

struct { __uint(type, BPF_MAP_TYPE_ARRAY); __uint(max_entries, 1); __type(key, __u32); __type(value, __u64); } neg_map SEC(".maps");

SEC("xdp")
int map_value_oob_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: mov    rsi,QWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3:
	/* 0x3: mov    rax,QWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7:
	/* 0x7: lea    rdx,[rsi+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_b:
	/* 0xb: cmp    rdx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_e:
	/* 0xe: ja     26 <entry+0x26> */
	X86_SIM_X86_JCC(X86_CC_A, 0xe, 0x26, x86_l_26);
x86_l_10:
	/* 0x10: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)&neg_map));
x86_l_17:
	/* 0x17: call   1c <entry+0x1c> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_1c:
	/* 0x1c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1f:
	/* 0x1f: je     26 <entry+0x26> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1f, 0x26, x86_l_26);
x86_l_21:
	/* 0x21: mov    rax,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_25:
	/* 0x25: ret */
	X86_SIM_X86_RET();
x86_l_26:
	/* 0x26: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_2b:
	/* 0x2b: ret */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
