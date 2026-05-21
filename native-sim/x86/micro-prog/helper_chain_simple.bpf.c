#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

/*
 * Stage 2 test: chain of 4 distinct deterministic helper calls.
 *
 * Exercises uid_gid + map_update + map_lookup + map_delete on a
 * single-slot HASH map. The stored value is `bpf_get_current_uid_gid()`
 * which is identical between the native_lab and kernel TEST_RUN
 * processes (both run as root), and lookup returns exactly what
 * update wrote, so result is bit-identical across runtimes -- a real
 * correctness invariant rather than a non-deterministic loose check.
 *
 * Replaces an earlier ktime/prandom-XOR chain that varied by design.
 *
 * Maps: 1 (HASH).   Helpers: 4.   Inline-eligible: yes (HASH map).
 */
#include "../../test/include/native_helpers.h"

struct {
    __uint(type, BPF_MAP_TYPE_HASH);
    __uint(max_entries, 1);
    __type(key, __u32);
    __type(value, __u64);
} chain_h SEC(".maps");

SEC("xdp")
int helper_chain_simple_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: sub    rsp,0x18 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SUB, 24ULL);
x86_l_4:
	/* 0x4: mov    r15,QWORD PTR [rdi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R15, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7:
	/* 0x7: lea    rcx,[r15+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b:
	/* 0xb: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_d:
	/* 0xd: cmp    rcx,QWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_11:
	/* 0x11: ja     76 <helper_chain_simple+0x76> */
	X86_SIM_X86_JCC(X86_CC_A, 0x11, 0x76, x86_l_76);
x86_l_13:
	/* 0x13: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_1b:
	/* 0x1b: call   QWORD PTR [rip+0x0] */
	X86_SIM_BPF_CALL_bpf_get_current_uid_gid();
x86_l_21:
	/* 0x21: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26:
	/* 0x26: mov    rbx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, &chain_h);
x86_l_2d:
	/* 0x2d: xor    r13d,r13d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_30:
	/* 0x30: lea    r14,[rsp+0xc] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_35:
	/* 0x35: lea    rdx,[rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3a:
	/* 0x3a: mov    rdi,rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_3d:
	/* 0x3d: mov    rsi,r14 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_40:
	/* 0x40: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_42:
	/* 0x42: call   QWORD PTR [rip+0x0] */
	X86_SIM_BPF_CALL_bpf_map_update_elem();
x86_l_48:
	/* 0x48: mov    rdi,rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_4b:
	/* 0x4b: mov    rsi,r14 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_4e:
	/* 0x4e: call   QWORD PTR [rip+0x0] */
	X86_SIM_BPF_CALL_bpf_map_lookup_elem();
x86_l_54:
	/* 0x54: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_57:
	/* 0x57: je     5c <helper_chain_simple+0x5c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x57, 0x5c, x86_l_5c);
x86_l_59:
	/* 0x59: mov    r13,QWORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5c:
	/* 0x5c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, &chain_h);
x86_l_63:
	/* 0x63: lea    rsi,[rsp+0xc] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_68:
	/* 0x68: call   QWORD PTR [rip+0x0] */
	X86_SIM_BPF_CALL_bpf_map_delete_elem();
x86_l_6e:
	/* 0x6e: mov    QWORD PTR [r15],r13 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_71:
	/* 0x71: mov    eax,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_76:
	/* 0x76: add    rsp,0x18 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_7a:
	/* 0x7a: jmp    7f <helper_chain_simple+0x7f> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_7f:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
