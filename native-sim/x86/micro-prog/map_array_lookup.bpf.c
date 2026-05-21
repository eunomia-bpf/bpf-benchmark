#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

/*
 * Stage 2 POC: BPF_MAP_TYPE_ARRAY with write + lookup.
 *
 * The program writes a deterministic value at key=0 and then reads it
 * back via bpf_map_lookup_elem. Both runtimes must yield identical
 * results.
 *
 * BPF JIT inlines bpf_map_lookup_elem for ARRAY maps -- replaces the
 * call with direct pointer math against map->data. native_lab will
 * still emit a real call, so this is one of the cases where BPF JIT
 * is expected to be faster than native_lab.
 */
#include "../../test/include/native_helpers.h"

struct {
    __uint(type, BPF_MAP_TYPE_ARRAY);
    __uint(max_entries, 4);
    __type(key, __u32);
    __type(value, __u64);
} test_array SEC(".maps");

SEC("xdp")
int map_array_lookup_x86_sim_xdp(struct xdp_md *ctx)
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
	/* 0x11: ja     68 <map_array_lookup+0x68> */
	X86_SIM_X86_JCC(X86_CC_A, 0x11, 0x68, x86_l_68);
x86_l_13:
	/* 0x13: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_1b:
	/* 0x1b: movabs rax,0xdeadbeefcafe0001 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, 0, 16045690984503050241ULL);
x86_l_25:
	/* 0x25: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a:
	/* 0x2a: mov    rbx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, &test_array);
x86_l_31:
	/* 0x31: xor    r13d,r13d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_34:
	/* 0x34: lea    r14,[rsp+0xc] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_39:
	/* 0x39: lea    rdx,[rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3e:
	/* 0x3e: mov    rdi,rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_41:
	/* 0x41: mov    rsi,r14 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_44:
	/* 0x44: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_46:
	/* 0x46: call   QWORD PTR [rip+0x0] */
	X86_SIM_BPF_CALL_bpf_map_update_elem();
x86_l_4c:
	/* 0x4c: mov    rdi,rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_4f:
	/* 0x4f: mov    rsi,r14 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_52:
	/* 0x52: call   QWORD PTR [rip+0x0] */
	X86_SIM_BPF_CALL_bpf_map_lookup_elem();
x86_l_58:
	/* 0x58: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_5b:
	/* 0x5b: je     60 <map_array_lookup+0x60> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5b, 0x60, x86_l_60);
x86_l_5d:
	/* 0x5d: mov    r13,QWORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_60:
	/* 0x60: mov    QWORD PTR [r15],r13 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_63:
	/* 0x63: mov    eax,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_68:
	/* 0x68: add    rsp,0x18 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_6c:
	/* 0x6c: jmp    71 <map_array_lookup+0x71> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_71:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
