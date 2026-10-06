#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

/*
 * Stage 2 test: LRU_HASH per-key counter (lookup, write-back).
 *
 * Real-world shape: bounded per-key rate counter where the kernel
 * evicts cold entries automatically (cilium connection-tracking,
 * tetragon process-event throttling). The BPF JIT does NOT inline
 * LRU_HASH `bpf_map_lookup_elem` because LRU access touches an
 * `access_state` bit that the inlined sequence couldn't update; native
 * code matches that behavior (regular helper call, no inline).
 *
 * Also exercises `bpf_map_delete_elem` to reset state per iteration so
 * the inner-repeat loop produces a deterministic result.
 *
 * Maps: 1 (LRU_HASH).   Helpers: 0 (besides map ops).
 * Inline-eligible: no (LRU_HASH != HASH).
 */
#include "../../test/include/native_helpers.h"

struct {
    __uint(type, BPF_MAP_TYPE_LRU_HASH);
    __uint(max_entries, 1024);
    __type(key, __u32);
    __type(value, __u64);
} cnt_lru SEC(".maps");

SEC("xdp")
int map_lru_hash_counter_x86_sim_xdp(struct xdp_md *ctx)
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
	/* 0x11: ja     74 <map_lru_hash_counter+0x74> */
	X86_SIM_X86_JCC(X86_CC_A, 0x11, 0x74, x86_l_74);
x86_l_13:
	/* 0x13: mov    DWORD PTR [rsp+0xc],0x2a */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607594ULL);
x86_l_1b:
	/* 0x1b: mov    rbx,QWORD PTR [rip+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)&cnt_lru));
x86_l_22:
	/* 0x22: lea    r14,[rsp+0xc] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_27:
	/* 0x27: mov    rdi,rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_2a:
	/* 0x2a: mov    rsi,r14 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_2d:
	/* 0x2d: call   QWORD PTR [rip+0x0] */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_delete_elem);
x86_l_33:
	/* 0x33: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3c:
	/* 0x3c: xor    r13d,r13d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_3f:
	/* 0x3f: lea    rdx,[rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_44:
	/* 0x44: mov    rdi,rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_47:
	/* 0x47: mov    rsi,r14 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_4a:
	/* 0x4a: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_4c:
	/* 0x4c: call   QWORD PTR [rip+0x0] */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_update_elem);
x86_l_52:
	/* 0x52: mov    rdi,rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_55:
	/* 0x55: mov    rsi,r14 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_58:
	/* 0x58: call   QWORD PTR [rip+0x0] */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_5e:
	/* 0x5e: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_61:
	/* 0x61: je     6c <map_lru_hash_counter+0x6c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x61, 0x6c, x86_l_6c);
x86_l_63:
	/* 0x63: mov    r13,QWORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_66:
	/* 0x66: inc    r13 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_69:
	/* 0x69: mov    QWORD PTR [rax],r13 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6c:
	/* 0x6c: mov    QWORD PTR [r15],r13 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6f:
	/* 0x6f: mov    eax,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_74:
	/* 0x74: add    rsp,0x18 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_78:
	/* 0x78: jmp    7d <map_lru_hash_counter+0x7d> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_7d:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
