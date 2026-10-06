#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

/*
 * Stage 2 test: 3-map chain (ARRAY -> HASH -> PERCPU_ARRAY).
 *
 * Real-world shape: cilium-style policy chain --
 *   index by something packet-derived into a POLICY ARRAY,
 *   take that policy id and look up metadata in a HASH table,
 *   then bump a per-cpu counter so userspace can read rates.
 *
 * Crucially, this is a multi-map program: native-link MUST NOT inline
 * `bpf_map_lookup_elem` here, because two of the three lookups go to
 * non-HASH maps and would be misrouted to `__htab_map_lookup_elem`.
 * The runner enforces that (single-HASH-only inline) so this test
 * verifies the correctness guard works.
 *
 * Maps: 3 (ARRAY + HASH + PERCPU_ARRAY).
 * Helpers: 0 (besides map ops).
 * Inline-eligible: no (multi-map; runner refuses to set
 *                  --inline-hash-lookup when other map types coexist).
 */
#include "../../test/include/native_helpers.h"

struct {
    __uint(type, BPF_MAP_TYPE_ARRAY);
    __uint(max_entries, 16);
    __type(key, __u32);
    __type(value, __u64);
} policy_array SEC(".maps");

struct {
    __uint(type, BPF_MAP_TYPE_HASH);
    __uint(max_entries, 64);
    __type(key, __u64);
    __type(value, __u64);
} meta_hash SEC(".maps");

struct {
    __uint(type, BPF_MAP_TYPE_PERCPU_ARRAY);
    __uint(max_entries, 8);
    __type(key, __u32);
    __type(value, __u64);
} counter_pcpu SEC(".maps");

SEC("xdp")
int multi_map_policy_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_1:
	/* 0x1: push   r12 */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_3:
	/* 0x3: sub    rsp,0x28 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SUB, 40ULL);
x86_l_7:
	/* 0x7: mov    r13,QWORD PTR [rdi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R13, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a:
	/* 0xa: lea    rcx,[r13+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e:
	/* 0xe: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_10:
	/* 0x10: cmp    rcx,QWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_14:
	/* 0x14: ja     fd <multi_map_policy+0xfd> */
	X86_SIM_X86_JCC(X86_CC_A, 0x14, 0xfd, x86_l_fd);
x86_l_1a:
	/* 0x1a: mov    DWORD PTR [rsp+0xc],0x3 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607555ULL);
x86_l_22:
	/* 0x22: movabs rax,0xaabbccddeeff0011 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, 0, 12302652060662169617ULL);
x86_l_2c:
	/* 0x2c: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_31:
	/* 0x31: mov    r14,QWORD PTR [rip+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_R14, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)&policy_array));
x86_l_38:
	/* 0x38: mov    rbp,QWORD PTR [rip+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_HELPER_ID, X86_RBP, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_update_elem);
x86_l_3f:
	/* 0x3f: xor    ebx,ebx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_41:
	/* 0x41: lea    r15,[rsp+0xc] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_46:
	/* 0x46: lea    r12,[rsp+0x20] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4b:
	/* 0x4b: mov    rdi,r14 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_4e:
	/* 0x4e: mov    rsi,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_51:
	/* 0x51: mov    rdx,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_54:
	/* 0x54: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_56:
	/* 0x56: call   rbp */
	X86_SIM_RUN_OP(X86_OP_CALL_REG, X86_REG_NONE, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_58:
	/* 0x58: movabs rax,0x1234567812345678 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, 0, 1311768465173141112ULL);
x86_l_62:
	/* 0x62: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_67:
	/* 0x67: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)&meta_hash));
x86_l_6e:
	/* 0x6e: lea    rdx,[rsp+0x18] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_73:
	/* 0x73: mov    rsi,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_76:
	/* 0x76: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_78:
	/* 0x78: call   rbp */
	X86_SIM_RUN_OP(X86_OP_CALL_REG, X86_REG_NONE, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_7a:
	/* 0x7a: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_82:
	/* 0x82: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_8b:
	/* 0x8b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)&counter_pcpu));
x86_l_92:
	/* 0x92: lea    rsi,[rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_97:
	/* 0x97: lea    rdx,[rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_9c:
	/* 0x9c: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_9e:
	/* 0x9e: call   rbp */
	X86_SIM_RUN_OP(X86_OP_CALL_REG, X86_REG_NONE, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_a0:
	/* 0xa0: mov    rdi,r14 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_a3:
	/* 0xa3: mov    rsi,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_a6:
	/* 0xa6: call   QWORD PTR [rip+0x0] */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_ac:
	/* 0xac: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_af:
	/* 0xaf: je     c4 <multi_map_policy+0xc4> */
	X86_SIM_X86_JCC(X86_CC_E, 0xaf, 0xc4, x86_l_c4);
x86_l_b1:
	/* 0xb1: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)&meta_hash));
x86_l_b8:
	/* 0xb8: mov    rsi,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_bb:
	/* 0xbb: call   QWORD PTR [rip+0x0] */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_c1:
	/* 0xc1: mov    rbx,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RBX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_c4:
	/* 0xc4: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)&counter_pcpu));
x86_l_cb:
	/* 0xcb: lea    rsi,[rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d0:
	/* 0xd0: call   QWORD PTR [rip+0x0] */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_d6:
	/* 0xd6: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_d9:
	/* 0xd9: je     e8 <multi_map_policy+0xe8> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd9, 0xe8, x86_l_e8);
x86_l_db:
	/* 0xdb: test   rbx,rbx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_de:
	/* 0xde: je     e8 <multi_map_policy+0xe8> */
	X86_SIM_X86_JCC(X86_CC_E, 0xde, 0xe8, x86_l_e8);
x86_l_e0:
	/* 0xe0: mov    rcx,QWORD PTR [rbx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e3:
	/* 0xe3: mov    QWORD PTR [rax],rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e6:
	/* 0xe6: jmp    f4 <multi_map_policy+0xf4> */
	X86_SIM_X86_JMP(0xe6, 0xf4, x86_l_f4);
x86_l_e8:
	/* 0xe8: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_eb:
	/* 0xeb: je     f2 <multi_map_policy+0xf2> */
	X86_SIM_X86_JCC(X86_CC_E, 0xeb, 0xf2, x86_l_f2);
x86_l_ed:
	/* 0xed: mov    rcx,QWORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f0:
	/* 0xf0: jmp    f4 <multi_map_policy+0xf4> */
	X86_SIM_X86_JMP(0xf0, 0xf4, x86_l_f4);
x86_l_f2:
	/* 0xf2: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_f4:
	/* 0xf4: mov    QWORD PTR [r13+0x0],rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f8:
	/* 0xf8: mov    eax,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_fd:
	/* 0xfd: add    rsp,0x28 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_101:
	/* 0x101: pop    r12 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R12, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_103:
	/* 0x103: pop    rbp */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBP, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_104:
	/* 0x104: jmp    109 <multi_map_policy+0x109> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_109:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
