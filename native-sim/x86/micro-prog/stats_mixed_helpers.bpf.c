#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

/*
 * Stage 2 test: most-complex case -- 3 helpers + 2 maps of different
 * inline classes (HASH + PERCPU_HASH).
 *
 * Real-world shape: a tetragon/tracee-style stats aggregator that
 * tags each observation with (pid_tgid mod K) into a HASH bucket
 * for cross-cpu aggregation and bumps a PERCPU_HASH per-cpu rate
 * counter at the same time.
 *
 * Multi-map (HASH + PERCPU_HASH) so native-link inline is disabled;
 * both lookups go through plain `bpf_map_lookup_elem`. Stored tag is
 * `bpf_get_current_uid_gid()` (deterministic across runtimes, both
 * run as root) rather than `bpf_ktime_get_ns()` (advances between
 * the two TEST_RUN calls), so the XOR of the two re-reads is a
 * stable, bit-identical value `uid_gid ^ 1` across native_lab and
 * kernel runs even though pid_tgid and smp_id route them to
 * different bucket slots.
 *
 * Maps: 2 (HASH + PERCPU_HASH).   Helpers: 3.
 * Inline-eligible: no (multi-map).
 */
#include "../../test/include/native_helpers.h"

struct {
    __uint(type, BPF_MAP_TYPE_HASH);
    __uint(max_entries, 64);
    __type(key, __u32);
    __type(value, __u64);
} stats_h SEC(".maps");

struct {
    __uint(type, BPF_MAP_TYPE_PERCPU_HASH);
    __uint(max_entries, 64);
    __type(key, __u32);
    __type(value, __u64);
} rate_pcpu SEC(".maps");

SEC("xdp")
int stats_mixed_helpers_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_1:
	/* 0x1: push   r12 */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_3:
	/* 0x3: sub    rsp,0x18 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SUB, 24ULL);
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
	/* 0x14: ja     be <stats_mixed_helpers+0xbe> */
	X86_SIM_X86_JCC(X86_CC_A, 0x14, 0xbe, x86_l_be);
x86_l_1a:
	/* 0x1a: call   QWORD PTR [rip+0x0] */
	X86_SIM_BPF_CALL_bpf_get_current_pid_tgid();
x86_l_20:
	/* 0x20: and    eax,0x3f */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 63ULL);
x86_l_23:
	/* 0x23: mov    DWORD PTR [rsp],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26:
	/* 0x26: call   QWORD PTR [rip+0x0] */
	X86_SIM_BPF_CALL_bpf_get_smp_processor_id();
x86_l_2c:
	/* 0x2c: and    eax,0x3f */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 63ULL);
x86_l_2f:
	/* 0x2f: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_33:
	/* 0x33: call   QWORD PTR [rip+0x0] */
	X86_SIM_BPF_CALL_bpf_get_current_uid_gid();
x86_l_39:
	/* 0x39: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3e:
	/* 0x3e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, &stats_h);
x86_l_45:
	/* 0x45: mov    rbx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_HELPER_ID(X86_RBX, X86_SIM_HELPER_bpf_map_update_elem);
x86_l_4c:
	/* 0x4c: xor    ebp,ebp */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_4e:
	/* 0x4e: mov    rsi,rsp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_RSP, X86_WIDTH_64, 0, 0);
x86_l_51:
	/* 0x51: lea    rdx,[rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_56:
	/* 0x56: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_58:
	/* 0x58: call   rbx */
	X86_SIM_BPF_CALL_REG(X86_RBX);
x86_l_5a:
	/* 0x5a: mov    QWORD PTR [rsp+0x8],0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_63:
	/* 0x63: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, &rate_pcpu);
x86_l_6a:
	/* 0x6a: lea    r12,[rsp+0x4] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_6f:
	/* 0x6f: lea    rdx,[rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_74:
	/* 0x74: mov    rdi,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_77:
	/* 0x77: mov    rsi,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_7a:
	/* 0x7a: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_7c:
	/* 0x7c: call   rbx */
	X86_SIM_BPF_CALL_REG(X86_RBX);
x86_l_7e:
	/* 0x7e: mov    r14,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_HELPER_ID(X86_R14, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_85:
	/* 0x85: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, &stats_h);
x86_l_8c:
	/* 0x8c: mov    rsi,rsp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_RSP, X86_WIDTH_64, 0, 0);
x86_l_8f:
	/* 0x8f: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_92:
	/* 0x92: mov    rbx,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RBX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_95:
	/* 0x95: mov    rdi,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_98:
	/* 0x98: mov    rsi,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_9b:
	/* 0x9b: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_9e:
	/* 0x9e: test   rbx,rbx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_a1:
	/* 0xa1: je     a6 <stats_mixed_helpers+0xa6> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa1, 0xa6, x86_l_a6);
x86_l_a3:
	/* 0xa3: mov    rbp,QWORD PTR [rbx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a6:
	/* 0xa6: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_a9:
	/* 0xa9: je     b0 <stats_mixed_helpers+0xb0> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa9, 0xb0, x86_l_b0);
x86_l_ab:
	/* 0xab: mov    rax,QWORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ae:
	/* 0xae: jmp    b2 <stats_mixed_helpers+0xb2> */
	X86_SIM_X86_JMP(0xae, 0xb2, x86_l_b2);
x86_l_b0:
	/* 0xb0: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_b2:
	/* 0xb2: xor    rax,rbp */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RBP, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_b5:
	/* 0xb5: mov    QWORD PTR [r13+0x0],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b9:
	/* 0xb9: mov    eax,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_be:
	/* 0xbe: add    rsp,0x18 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_c2:
	/* 0xc2: pop    r12 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R12, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_c4:
	/* 0xc4: pop    rbp */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBP, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_c5:
	/* 0xc5: jmp    ca <stats_mixed_helpers+0xca> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_ca:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
