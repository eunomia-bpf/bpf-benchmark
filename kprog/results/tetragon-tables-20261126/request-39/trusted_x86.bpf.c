#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_STACK_BYTES 304U
#define X86_SIM_STACK_VALUE_WORDS(M) M(1) M(2) M(3) M(4) M(5) M(6) M(7) M(8) M(9) M(10) M(11) M(12) M(13) M(14) M(15) M(17) M(18) M(19) M(20) M(21) M(22) M(23) M(24) M(25) M(26) M(27) M(28) M(31)
#include "/workspaces/repository/kprog/x86/x86_sim_local_bpf.h"
#include "/workspaces/repository/kprog/results/tetragon-tables-20261126/cache_tag_only.h"

#if defined(__bpf__) || defined(__BPF__)
static __attribute__((always_inline)) inline void
__x86_sim_unresolved_indirect_target(void) {
	asm volatile("call -1" ::: "r0", "r1", "r2", "r3", "r4", "r5", "memory");
}
#else
extern void __x86_sim_unresolved_indirect_target(void)
	__attribute__((error("indirect target was not eliminated by specialization")));
#endif

extern __u8 buffer_heap_map[] __ksym;
extern __u8 config_map[] __ksym;
extern __u8 execve_map[] __ksym;
extern __u8 fdinstall_map[] __ksym;
extern __u8 process_call_heap[] __ksym;
extern __u8 retkprobe_calls[] __ksym;
extern __u8 retprobe_map[] __ksym;
extern __u8 socktrack_map[] __ksym;
extern __u8 tg_ipv6_ext_heap[] __ksym;
#include "/workspaces/repository/kprog/x86/x86_sim_inline.h"

X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_ALU_IMM, X86_OP_ALU_IMM)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_ALU_MEM, X86_OP_ALU_MEM)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_ALU_MEM_IMM, X86_OP_ALU_MEM_IMM)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_ALU_REG, X86_OP_ALU_REG)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_BT, X86_OP_BT)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_CALL_HELPER, X86_OP_CALL_HELPER)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_CMOV, X86_OP_CMOV)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_CMP_IMM, X86_OP_CMP_IMM)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_CMP_MEM_IMM, X86_OP_CMP_MEM_IMM)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_CMP_MEM_REG, X86_OP_CMP_MEM_REG)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_CMP_REG, X86_OP_CMP_REG)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_CMP_REG_MEM, X86_OP_CMP_REG_MEM)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_LEA, X86_OP_LEA)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_MOVBE_STORE, X86_OP_MOVBE_STORE)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_MOVZX_REG, X86_OP_MOVZX_REG)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_MOV_IMM, X86_OP_MOV_IMM)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_MOV_LOAD, X86_OP_MOV_LOAD)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_MOV_LOAD_MAP_PTR, X86_OP_MOV_LOAD_MAP_PTR)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_MOV_REG, X86_OP_MOV_REG)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_MOV_STORE_IMM, X86_OP_MOV_STORE_IMM)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_MOV_STORE_REG, X86_OP_MOV_STORE_REG)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_POP, X86_OP_POP)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_PUSH, X86_OP_PUSH)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_SETCC, X86_OP_SETCC)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_SETCC_MEM, X86_OP_SETCC_MEM)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_TEST_IMM, X86_OP_TEST_IMM)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_TEST_MEM_IMM, X86_OP_TEST_MEM_IMM)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_TEST_REG, X86_OP_TEST_REG)

SEC("kprobe/trusted")
int trusted_x86_x86_sim_xdp(void *ctx)
{
	X86_SIM_ENTRY_RAW(ctx);
	X86_SIM_BIND_INLINE();
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_1:
	/* 0x1: push   r15 */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_3:
	/* 0x3: push   r14 */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_5:
	/* 0x5: push   r13 */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_7:
	/* 0x7: push   r12 */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_9:
	/* 0x9: push   rbx */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_a:
	/* 0xa: sub    rsp,0xf8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SUB, 248ULL);
x86_l_11:
	/* 0x11: mov    r15,rdi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R15, X86_RDI, X86_WIDTH_64, 0, 0);
x86_l_14:
	/* 0x14: mov    rax,QWORD PTR [rdi+0x50] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_18:
	/* 0x18: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_20:
	/* 0x20: mov    DWORD PTR [rsp+0xe4],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 979252543488ULL);
x86_l_2b:
	/* 0x2b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)process_call_heap));
x86_l_32:
	/* 0x32: lea    rsi,[rsp+0xe4] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 228ULL);
x86_l_3a:
	/* 0x3a: call   3f <generic_retkprobe_event+0x3f> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_3f:
	/* 0x3f: xor    ebp,ebp */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_41:
	/* 0x41: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_44:
	/* 0x44: je     693 <generic_retkprobe_event+0x693> */
	X86_SIM_X86_JCC(X86_CC_E, 0x44, 0x693, x86_l_693);
x86_l_4a:
	/* 0x4a: mov    r14,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R14, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_4d:
	/* 0x4d: mov    rbx,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RBX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_50:
	/* 0x50: lea    rsi,[rax+0x5ef8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24312ULL);
x86_l_57:
	/* 0x57: mov    DWORD PTR [r14+0x5ef8],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104419244900352ULL);
x86_l_62:
	/* 0x62: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)config_map));
x86_l_69:
	/* 0x69: call   6e <generic_retkprobe_event+0x6e> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_6e:
	/* 0x6e: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_71:
	/* 0x71: je     693 <generic_retkprobe_event+0x693> */
	X86_SIM_X86_JCC(X86_CC_E, 0x71, 0x693, x86_l_693);
x86_l_77:
	/* 0x77: mov    r12,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R12, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_7a:
	/* 0x7a: mov    eax,DWORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7c:
	/* 0x7c: mov    QWORD PTR [rbx+0x60],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_80:
	/* 0x80: call   85 <generic_retkprobe_event+0x85> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_get_current_pid_tgid);
x86_l_85:
	/* 0x85: cmp    rax,0xffffffffffffffea */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, 0, 18446744073709551594ULL);
x86_l_89:
	/* 0x89: jne    8f <generic_retkprobe_event+0x8f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x89, 0x8f, x86_l_8f);
x86_l_8b:
	/* 0x8b: mov    rax,QWORD PTR [r15+0x20] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_8f:
	/* 0x8f: mov    QWORD PTR [rbx+0x68],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_93:
	/* 0x93: call   98 <generic_retkprobe_event+0x98> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_get_current_pid_tgid);
x86_l_98:
	/* 0x98: mov    DWORD PTR [rbx+0x7c],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_9b:
	/* 0x9b: mov    rax,QWORD PTR [rbx+0x60] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_9f:
	/* 0x9f: mov    rcx,QWORD PTR [rbx+0x68] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_a3:
	/* 0xa3: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_a8:
	/* 0xa8: mov    QWORD PTR [rsp+0x48],rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_ad:
	/* 0xad: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)retprobe_map));
x86_l_b4:
	/* 0xb4: lea    rsi,[rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_b9:
	/* 0xb9: call   be <generic_retkprobe_event+0xbe> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_be:
	/* 0xbe: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_c1:
	/* 0xc1: je     693 <generic_retkprobe_event+0x693> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc1, 0x693, x86_l_693);
x86_l_c7:
	/* 0xc7: mov    QWORD PTR [rsp],r14 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cb:
	/* 0xcb: mov    r14,QWORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ce:
	/* 0xce: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d2:
	/* 0xd2: mov    QWORD PTR [rsp+0x38],rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_d7:
	/* 0xd7: mov    rax,QWORD PTR [rax+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_db:
	/* 0xdb: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_e3:
	/* 0xe3: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)retprobe_map));
x86_l_ea:
	/* 0xea: lea    r13,[rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_ef:
	/* 0xef: mov    rsi,r13 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_f2:
	/* 0xf2: call   f7 <generic_retkprobe_event+0xf7> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_delete_elem);
x86_l_f7:
	/* 0xf7: mov    QWORD PTR [rbx+0x90],r14 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_fe:
	/* 0xfe: mov    eax,DWORD PTR [r12+0x58] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_103:
	/* 0x103: mov    r14d,DWORD PTR [r12+0x5c] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_108:
	/* 0x108: test   r14d,r14d */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_32, 0, 0);
x86_l_10b:
	/* 0x10b: mov    QWORD PTR [rsp+0xf0],r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_113:
	/* 0x113: mov    QWORD PTR [rsp+0xd0],r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_11b:
	/* 0x11b: je     1df <generic_retkprobe_event+0x1df> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11b, 0x1df, x86_l_1df);
x86_l_121:
	/* 0x121: mov    DWORD PTR [rsp+0x28],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_125:
	/* 0x125: mov    DWORD PTR [rbx+0x5ea0],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104041287778304ULL);
x86_l_12f:
	/* 0x12f: mov    rbp,QWORD PTR [rsp+0xc0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_137:
	/* 0x137: mov    DWORD PTR [rsp+0xe8],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 996432412672ULL);
x86_l_142:
	/* 0x142: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)process_call_heap));
x86_l_149:
	/* 0x149: lea    rsi,[rsp+0xe8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_151:
	/* 0x151: call   156 <generic_retkprobe_event+0x156> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_156:
	/* 0x156: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_159:
	/* 0x159: je     25f <generic_retkprobe_event+0x25f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x159, 0x25f, x86_l_25f);
x86_l_15f:
	/* 0x15f: mov    edx,DWORD PTR [rax+0x5ea0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24224ULL);
x86_l_165:
	/* 0x165: mov    DWORD PTR [rax+0x98],edx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_16b:
	/* 0x16b: mov    QWORD PTR [rax+0x5e78],0xc */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103869489086476ULL);
x86_l_176:
	/* 0x176: test   edx,edx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_178:
	/* 0x178: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_17d:
	/* 0x17d: je     30f <generic_retkprobe_event+0x30f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x17d, 0x30f, x86_l_30f);
x86_l_183:
	/* 0x183: mov    r14,QWORD PTR [rsp] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_187:
	/* 0x187: mov    r13d,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_18d:
	/* 0x18d: add    r13,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_191:
	/* 0x191: mov    eax,DWORD PTR [r12+0x60] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_196:
	/* 0x196: cmp    eax,0xb */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 11ULL);
x86_l_199:
	/* 0x199: je     27d <generic_retkprobe_event+0x27d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x199, 0x27d, x86_l_27d);
x86_l_19f:
	/* 0x19f: cmp    eax,0xa */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 10ULL);
x86_l_1a2:
	/* 0x1a2: jne    296 <generic_retkprobe_event+0x296> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1a2, 0x296, x86_l_296);
x86_l_1a8:
	/* 0x1a8: mov    eax,DWORD PTR [rbx+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ab:
	/* 0x1ab: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1af:
	/* 0x1af: mov    eax,DWORD PTR [rbx+0x7c] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_1b2:
	/* 0x1b2: mov    DWORD PTR [rsp+0x44],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_1b6:
	/* 0x1b6: mov    rax,QWORD PTR [rbx+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1ba:
	/* 0x1ba: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1bf:
	/* 0x1bf: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)socktrack_map));
x86_l_1c6:
	/* 0x1c6: lea    rsi,[rsp+0xc0] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_1ce:
	/* 0x1ce: lea    rdx,[rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1d3:
	/* 0x1d3: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1d5:
	/* 0x1d5: call   1da <generic_retkprobe_event+0x1da> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_update_elem);
x86_l_1da:
	/* 0x1da: jmp    291 <generic_retkprobe_event+0x291> */
	X86_SIM_X86_JMP(0x1da, 0x291, x86_l_291);
x86_l_1df:
	/* 0x1df: mov    r13d,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_1e5:
	/* 0x1e5: mov    r14,QWORD PTR [rsp] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e9:
	/* 0x1e9: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1ee:
	/* 0x1ee: add    r14,0x90 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_1f5:
	/* 0x1f5: cmp    eax,0x3 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 3ULL);
x86_l_1f8:
	/* 0x1f8: jne    2b1 <generic_retkprobe_event+0x2b1> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1f8, 0x2b1, x86_l_2b1);
x86_l_1fe:
	/* 0x1fe: mov    DWORD PTR [r14+r13*1],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_206:
	/* 0x206: lea    r8,[r13+0x4] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R8, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_20a:
	/* 0x20a: cmp    QWORD PTR [rsp+0xb0],0x0 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_213:
	/* 0x213: je     3b2 <generic_retkprobe_event+0x3b2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x213, 0x3b2, x86_l_3b2);
x86_l_219:
	/* 0x219: mov    r12,r13 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R12, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_21c:
	/* 0x21c: mov    r9,QWORD PTR [rsp+0xc0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_224:
	/* 0x224: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_227:
	/* 0x227: js     3c4 <generic_retkprobe_event+0x3c4> */
	X86_SIM_X86_JCC(X86_CC_S, 0x227, 0x3c4, x86_l_3c4);
x86_l_22d:
	/* 0x22d: lea    rdi,[rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_232:
	/* 0x232: mov    esi,0x10 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 16ULL);
x86_l_237:
	/* 0x237: mov    r15,r8 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R15, X86_R8, X86_WIDTH_64, 0, 0);
x86_l_23a:
	/* 0x23a: mov    r13,r9 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R13, X86_R9, X86_WIDTH_64, 0, 0);
x86_l_23d:
	/* 0x23d: call   242 <generic_retkprobe_event+0x242> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_242:
	/* 0x242: mov    r8,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R8, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_245:
	/* 0x245: mov    ecx,0xfffffffe */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 4294967294ULL);
x86_l_24a:
	/* 0x24a: test   eax,eax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_24c:
	/* 0x24c: js     401 <generic_retkprobe_event+0x401> */
	X86_SIM_X86_JCC(X86_CC_S, 0x24c, 0x401, x86_l_401);
x86_l_252:
	/* 0x252: mov    r9,r13 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R9, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_255:
	/* 0x255: mov    rbp,QWORD PTR [rsp+0x48] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_25a:
	/* 0x25a: jmp    3e2 <generic_retkprobe_event+0x3e2> */
	X86_SIM_X86_JMP(0x25a, 0x3e2, x86_l_3e2);
x86_l_25f:
	/* 0x25f: xor    r13d,r13d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_262:
	/* 0x262: mov    r14,QWORD PTR [rsp] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_266:
	/* 0x266: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_26b:
	/* 0x26b: add    r13,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_26f:
	/* 0x26f: mov    eax,DWORD PTR [r12+0x60] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_274:
	/* 0x274: cmp    eax,0xb */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 11ULL);
x86_l_277:
	/* 0x277: jne    19f <generic_retkprobe_event+0x19f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x277, 0x19f, x86_l_19f);
x86_l_27d:
	/* 0x27d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)socktrack_map));
x86_l_284:
	/* 0x284: lea    rsi,[rsp+0xc0] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_28c:
	/* 0x28c: call   291 <generic_retkprobe_event+0x291> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_delete_elem);
x86_l_291:
	/* 0x291: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_296:
	/* 0x296: and    r13d,0x1fff */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 8191ULL);
x86_l_29d:
	/* 0x29d: mov    eax,DWORD PTR [rsp+0x28] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2a1:
	/* 0x2a1: add    r14,0x90 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_2a8:
	/* 0x2a8: cmp    eax,0x3 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 3ULL);
x86_l_2ab:
	/* 0x2ab: je     1fe <generic_retkprobe_event+0x1fe> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2ab, 0x1fe, x86_l_1fe);
x86_l_2b1:
	/* 0x2b1: cmp    eax,0x2 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_2b4:
	/* 0x2b4: jne    4ee <generic_retkprobe_event+0x4ee> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2b4, 0x4ee, x86_l_4ee);
x86_l_2ba:
	/* 0x2ba: mov    DWORD PTR [r14+r13*1],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_2c2:
	/* 0x2c2: mov    rax,r14 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_2c5:
	/* 0x2c5: lea    r14,[r13+0x4] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R14, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2c9:
	/* 0x2c9: mov    rcx,r13 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_2cc:
	/* 0x2cc: mov    r13,QWORD PTR [rsp+0xc0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_2d4:
	/* 0x2d4: lea    r15,[rax+rcx*1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2d8:
	/* 0x2d8: add    r15,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2dc:
	/* 0x2dc: cmp    r13,0xfff */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, 0, 4095ULL);
x86_l_2e3:
	/* 0x2e3: mov    r12d,0xfff */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 4095ULL);
x86_l_2e9:
	/* 0x2e9: cmovb  r12,r13 */
	X86_SIM_RUN_OP(X86_OP_CMOV, X86_R12, X86_R13, X86_WIDTH_64, X86_CC_B, 0);
x86_l_2ed:
	/* 0x2ed: lea    rdi,[rax+rcx*1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2f1:
	/* 0x2f1: add    rdi,0xc */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_2f5:
	/* 0x2f5: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_2f8:
	/* 0x2f8: js     375 <generic_retkprobe_event+0x375> */
	X86_SIM_X86_JCC(X86_CC_S, 0x2f8, 0x375, x86_l_375);
x86_l_2fa:
	/* 0x2fa: mov    esi,r12d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_R12, X86_WIDTH_32, 0, 0);
x86_l_2fd:
	/* 0x2fd: call   302 <generic_retkprobe_event+0x302> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_302:
	/* 0x302: test   eax,eax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_304:
	/* 0x304: js     41d <generic_retkprobe_event+0x41d> */
	X86_SIM_X86_JCC(X86_CC_S, 0x304, 0x41d, x86_l_41d);
x86_l_30a:
	/* 0x30a: jmp    4dd <generic_retkprobe_event+0x4dd> */
	X86_SIM_X86_JMP(0x30a, 0x4dd, x86_l_4dd);
x86_l_30f:
	/* 0x30f: mov    rcx,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_312:
	/* 0x312: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_317:
	/* 0x317: lea    rcx,[rax+0x9c] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_31e:
	/* 0x31e: mov    QWORD PTR [rsp+0x18],rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_323:
	/* 0x323: mov    QWORD PTR [rsp+0x40],rbp */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_328:
	/* 0x328: mov    QWORD PTR [rsp+0x80],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_334:
	/* 0x334: lea    edx,[r14-0xf] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551601ULL);
x86_l_338:
	/* 0x338: cmp    edx,0x1b */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 27ULL);
x86_l_33b:
	/* 0x33b: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_340:
	/* 0x340: ja     6f3 <generic_retkprobe_event+0x6f3> */
	X86_SIM_X86_JCC(X86_CC_A, 0x340, 0x6f3, x86_l_6f3);
x86_l_346:
	/* Capture image-bound code identity before scheduled instructions. */
	switch (X86_SIM_L_READ_REG(X86_RDX) << 2) {
	case 0ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x356ULL); break;
	case 4ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x97cULL); break;
	case 8ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x6f3ULL); break;
	case 12ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x6f3ULL); break;
	case 16ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x6f3ULL); break;
	case 20ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x6f3ULL); break;
	case 24ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x6f3ULL); break;
	case 28ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x6f3ULL); break;
	case 32ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x6f3ULL); break;
	case 36ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x798ULL); break;
	case 40ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x6f3ULL); break;
	case 44ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x6f3ULL); break;
	case 48ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x6f3ULL); break;
	case 52ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x6f3ULL); break;
	case 56ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x6f3ULL); break;
	case 60ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x6f3ULL); break;
	case 64ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x6f3ULL); break;
	case 68ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x6f3ULL); break;
	case 72ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x6f3ULL); break;
	case 76ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x6f3ULL); break;
	case 80ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x6f3ULL); break;
	case 84ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x6f3ULL); break;
	case 88ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x7bdULL); break;
	case 92ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x6f3ULL); break;
	case 96ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x6f3ULL); break;
	case 100ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x6f3ULL); break;
	case 104ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x6f3ULL); break;
	case 108ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x7deULL); break;
	default: __x86_sim_unresolved_indirect_target();
	}
x86_l_354:
	/* 0x354: jmp    rax */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RAX);
		switch (X86_SIM_L_REG_TAG(X86_RAX)) {
		case X86_SIM_TAG_CODE:
			switch (__x86_target) {
			case 0x356ULL: goto x86_l_356;
			case 0x6f3ULL: goto x86_l_6f3;
			case 0x798ULL: goto x86_l_798;
			case 0x7bdULL: goto x86_l_7bd;
			case 0x7deULL: goto x86_l_7de;
			case 0x97cULL: goto x86_l_97c;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_356:
	/* 0x356: test   r13,r13 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_359:
	/* 0x359: jns    819 <generic_retkprobe_event+0x819> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x359, 0x819, x86_l_819);
x86_l_35f:
	/* 0x35f: lea    rax,[rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_364:
	/* 0x364: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_367:
	/* 0x367: jns    841 <generic_retkprobe_event+0x841> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x367, 0x841, x86_l_841);
x86_l_36d:
	/* 0x36d: mov    r12,QWORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_370:
	/* 0x370: jmp    838 <generic_retkprobe_event+0x838> */
	X86_SIM_X86_JMP(0x370, 0x838, x86_l_838);
x86_l_375:
	/* 0x375: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_378:
	/* 0x378: jns    413 <generic_retkprobe_event+0x413> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x378, 0x413, x86_l_413);
x86_l_37e:
	/* 0x37e: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_380:
	/* 0x380: cmp    r12d,0x8 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_384:
	/* 0x384: jb     3a0 <generic_retkprobe_event+0x3a0> */
	X86_SIM_X86_JCC(X86_CC_B, 0x384, 0x3a0, x86_l_3a0);
x86_l_386:
	/* 0x386: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_388:
	/* 0x388: mov    rcx,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_38b:
	/* 0x38b: mov    rax,QWORD PTR [rdx+rax*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_38f:
	/* 0x38f: mov    QWORD PTR [rdi+rcx*1],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_393:
	/* 0x393: lea    rax,[rcx+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_397:
	/* 0x397: add    rcx,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_39b:
	/* 0x39b: cmp    rcx,r12 */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RCX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_39e:
	/* 0x39e: jbe    388 <generic_retkprobe_event+0x388> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x39e, 0x388, x86_l_388);
x86_l_3a0:
	/* 0x3a0: test   r12b,0x4 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, 0, 4ULL);
x86_l_3a4:
	/* 0x3a4: jne    4ad <generic_retkprobe_event+0x4ad> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x3a4, 0x4ad, x86_l_4ad);
x86_l_3aa:
	/* 0x3aa: mov    rsi,rdx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_3ad:
	/* 0x3ad: jmp    4bb <generic_retkprobe_event+0x4bb> */
	X86_SIM_X86_JMP(0x3ad, 0x4bb, x86_l_4bb);
x86_l_3b2:
	/* 0x3b2: xor    r13d,r13d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_3b5:
	/* 0x3b5: mov    DWORD PTR [r14+r8*1],r13d */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R8, 0), 0ULL);
x86_l_3b9:
	/* 0x3b9: mov    DWORD PTR [r14+r8*1+0x4],r13d */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R8, 0), 4ULL);
x86_l_3be:
	/* 0x3be: add    r13,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3c2:
	/* 0x3c2: jmp    40b <generic_retkprobe_event+0x40b> */
	X86_SIM_X86_JMP(0x3c2, 0x40b, x86_l_40b);
x86_l_3c4:
	/* 0x3c4: mov    rax,rdx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_3c7:
	/* 0x3c7: mov    ecx,0xfffffffe */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 4294967294ULL);
x86_l_3cc:
	/* 0x3cc: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_3cf:
	/* 0x3cf: jns    401 <generic_retkprobe_event+0x401> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x3cf, 0x401, x86_l_401);
x86_l_3d1:
	/* 0x3d1: mov    rcx,QWORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3d4:
	/* 0x3d4: mov    QWORD PTR [rsp+0x40],rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3d9:
	/* 0x3d9: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3dd:
	/* 0x3dd: mov    QWORD PTR [rsp+0x48],rbp */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3e2:
	/* 0x3e2: cmp    rbp,r9 */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RBP, X86_R9, X86_WIDTH_64, 0, 0);
x86_l_3e5:
	/* 0x3e5: mov    r13,r9 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R13, X86_R9, X86_WIDTH_64, 0, 0);
x86_l_3e8:
	/* 0x3e8: cmovb  r13,rbp */
	X86_SIM_RUN_OP(X86_OP_CMOV, X86_R13, X86_RBP, X86_WIDTH_64, X86_CC_B, 0);
x86_l_3ec:
	/* 0x3ec: test   r9,r9 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R9, X86_R9, X86_WIDTH_64, 0, 0);
x86_l_3ef:
	/* 0x3ef: cmovne rbp,r13 */
	X86_SIM_RUN_OP(X86_OP_CMOV, X86_RBP, X86_R13, X86_WIDTH_64, X86_CC_NE, 0);
x86_l_3f3:
	/* 0x3f3: mov    ecx,0xfffffffd */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 4294967293ULL);
x86_l_3f8:
	/* 0x3f8: cmp    rbp,0xffe */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, 0, 4094ULL);
x86_l_3ff:
	/* 0x3ff: jbe    430 <generic_retkprobe_event+0x430> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x3ff, 0x430, x86_l_430);
x86_l_401:
	/* 0x401: mov    DWORD PTR [r14+r8*1],ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R8, 0), 0ULL);
x86_l_405:
	/* 0x405: mov    r13d,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_40b:
	/* 0x40b: add    r13,r8 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R13, X86_R8, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_40e:
	/* 0x40e: jmp    4ee <generic_retkprobe_event+0x4ee> */
	X86_SIM_X86_JMP(0x40e, 0x4ee, x86_l_4ee);
x86_l_413:
	/* 0x413: xor    esi,esi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_415:
	/* 0x415: mov    rdx,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_418:
	/* 0x418: call   47c5 <__native_link_local_memset_zero_dynamic> */
	X86_SIM_X86_CALL(x86_l_47c5, 0x41dULL);
x86_l_41d:
	/* 0x41d: mov    DWORD PTR [r15],0xfffffffe */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4294967294ULL);
x86_l_424:
	/* 0x424: add    r14,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_428:
	/* 0x428: mov    r13,r14 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R13, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_42b:
	/* 0x42b: jmp    4ee <generic_retkprobe_event+0x4ee> */
	X86_SIM_X86_JMP(0x42b, 0x4ee, x86_l_4ee);
x86_l_430:
	/* 0x430: add    r12,0xc */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_434:
	/* 0x434: mov    QWORD PTR [rsp+0x28],r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_439:
	/* 0x439: lea    rdi,[r14+r12*1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_43d:
	/* 0x43d: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_442:
	/* 0x442: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_445:
	/* 0x445: jns    6ab <generic_retkprobe_event+0x6ab> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x445, 0x6ab, x86_l_6ab);
x86_l_44b:
	/* 0x44b: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_44e:
	/* 0x44e: jns    7ff <generic_retkprobe_event+0x7ff> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x44e, 0x7ff, x86_l_7ff);
x86_l_454:
	/* 0x454: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_456:
	/* 0x456: cmp    ebp,0x8 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_459:
	/* 0x459: jb     473 <generic_retkprobe_event+0x473> */
	X86_SIM_X86_JCC(X86_CC_B, 0x459, 0x473, x86_l_473);
x86_l_45b:
	/* 0x45b: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_45d:
	/* 0x45d: mov    eax,ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_45f:
	/* 0x45f: mov    rsi,QWORD PTR [rdx+rax*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_463:
	/* 0x463: mov    QWORD PTR [rdi+rax*1],rsi */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_467:
	/* 0x467: lea    eax,[rcx+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_46a:
	/* 0x46a: add    ecx,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 16ULL);
x86_l_46d:
	/* 0x46d: cmp    ecx,ebp */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_32, 0, 0);
x86_l_46f:
	/* 0x46f: mov    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_471:
	/* 0x471: jbe    45d <generic_retkprobe_event+0x45d> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x471, 0x45d, x86_l_45d);
x86_l_473:
	/* 0x473: test   bpl,0x4 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, 0, 4ULL);
x86_l_477:
	/* 0x477: jne    924 <generic_retkprobe_event+0x924> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x477, 0x924, x86_l_924);
x86_l_47d:
	/* 0x47d: test   bpl,0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, 0, 2ULL);
x86_l_481:
	/* 0x481: jne    939 <generic_retkprobe_event+0x939> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x481, 0x939, x86_l_939);
x86_l_487:
	/* 0x487: test   bpl,0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_48b:
	/* 0x48b: jne    950 <generic_retkprobe_event+0x950> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x48b, 0x950, x86_l_950);
x86_l_491:
	/* 0x491: test   r9,r9 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R9, X86_R9, X86_WIDTH_64, 0, 0);
x86_l_494:
	/* 0x494: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_499:
	/* 0x499: je     6d9 <generic_retkprobe_event+0x6d9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x499, 0x6d9, x86_l_6d9);
x86_l_49f:
	/* 0x49f: sub    r9,r13 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_R13, X86_WIDTH_64, X86_ALU_SUB, 0);
x86_l_4a2:
	/* 0x4a2: jne    6dc <generic_retkprobe_event+0x6dc> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4a2, 0x6dc, x86_l_6dc);
x86_l_4a8:
	/* 0x4a8: jmp    3b5 <generic_retkprobe_event+0x3b5> */
	X86_SIM_X86_JMP(0x4a8, 0x3b5, x86_l_3b5);
x86_l_4ad:
	/* 0x4ad: mov    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_4af:
	/* 0x4af: mov    rsi,rdx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_4b2:
	/* 0x4b2: mov    edx,DWORD PTR [rdx+rcx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4b5:
	/* 0x4b5: mov    DWORD PTR [rdi+rcx*1],edx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4b8:
	/* 0x4b8: or     eax,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_OR, 4ULL);
x86_l_4bb:
	/* 0x4bb: test   r12b,0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, 0, 2ULL);
x86_l_4bf:
	/* 0x4bf: je     4ce <generic_retkprobe_event+0x4ce> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4bf, 0x4ce, x86_l_4ce);
x86_l_4c1:
	/* 0x4c1: mov    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_4c3:
	/* 0x4c3: movzx  edx,WORD PTR [rsi+rcx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_16), 0ULL);
x86_l_4c7:
	/* 0x4c7: mov    WORD PTR [rdi+rcx*1],dx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4cb:
	/* 0x4cb: add    eax,0x2 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_4ce:
	/* 0x4ce: test   r12b,0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_4d2:
	/* 0x4d2: je     4dd <generic_retkprobe_event+0x4dd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4d2, 0x4dd, x86_l_4dd);
x86_l_4d4:
	/* 0x4d4: mov    eax,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_4d6:
	/* 0x4d6: movzx  ecx,BYTE PTR [rsi+rax*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_4da:
	/* 0x4da: mov    BYTE PTR [rdi+rax*1],cl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_4dd:
	/* 0x4dd: mov    DWORD PTR [r15],r13d */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_R15, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4e0:
	/* 0x4e0: mov    DWORD PTR [r15+0x4],r12d */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_R15, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4e4:
	/* 0x4e4: add    r12,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4e8:
	/* 0x4e8: add    r12,r14 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R12, X86_R14, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_4eb:
	/* 0x4eb: mov    r13,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R13, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_4ee:
	/* 0x4ee: call   4f3 <generic_retkprobe_event+0x4f3> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_get_current_task);
x86_l_4f3:
	/* 0x4f3: mov    r12,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R12, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_4f6:
	/* 0x4f6: lea    rcx,[rax+0xaf4] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2804ULL);
x86_l_4fd:
	/* 0x4fd: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_4ff:
	/* 0x4ff: test   rcx,rcx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_502:
	/* 0x502: jns    506 <generic_retkprobe_event+0x506> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x502, 0x506, x86_l_506);
x86_l_504:
	/* 0x504: mov    eax,DWORD PTR [rcx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_506:
	/* 0x506: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_50a:
	/* 0x50a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)execve_map));
x86_l_511:
	/* 0x511: lea    rsi,[rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_516:
	/* 0x516: call   51b <generic_retkprobe_event+0x51b> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_51b:
	/* 0x51b: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_51e:
	/* 0x51e: je     52e <generic_retkprobe_event+0x52e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x51e, 0x52e, x86_l_52e);
x86_l_520:
	/* 0x520: mov    r15,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R15, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_523:
	/* 0x523: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_528:
	/* 0x528: jne    636 <generic_retkprobe_event+0x636> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x528, 0x636, x86_l_636);
x86_l_52e:
	/* 0x52e: add    r12,0xb00 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 2816ULL);
x86_l_535:
	/* 0x535: test   r12,r12 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_538:
	/* 0x538: jns    633 <generic_retkprobe_event+0x633> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x538, 0x633, x86_l_633);
x86_l_53e:
	/* 0x53e: mov    r14,QWORD PTR [r12] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_542:
	/* 0x542: xor    r15d,r15d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_545:
	/* 0x545: test   r14,r14 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_548:
	/* 0x548: je     636 <generic_retkprobe_event+0x636> */
	X86_SIM_X86_JCC(X86_CC_E, 0x548, 0x636, x86_l_636);
x86_l_54e:
	/* 0x54e: lea    rax,[r14+0xaf4] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2804ULL);
x86_l_555:
	/* 0x555: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_558:
	/* 0x558: jns    55d <generic_retkprobe_event+0x55d> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x558, 0x55d, x86_l_55d);
x86_l_55a:
	/* 0x55a: mov    r15d,DWORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_55d:
	/* 0x55d: mov    DWORD PTR [rsp+0x40],r15d */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_562:
	/* 0x562: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)execve_map));
x86_l_569:
	/* 0x569: lea    rsi,[rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_56e:
	/* 0x56e: call   573 <generic_retkprobe_event+0x573> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_573:
	/* 0x573: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_576:
	/* 0x576: je     586 <generic_retkprobe_event+0x586> */
	X86_SIM_X86_JCC(X86_CC_E, 0x576, 0x586, x86_l_586);
x86_l_578:
	/* 0x578: mov    r15,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R15, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_57b:
	/* 0x57b: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_580:
	/* 0x580: jne    636 <generic_retkprobe_event+0x636> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x580, 0x636, x86_l_636);
x86_l_586:
	/* 0x586: add    r14,0xb00 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 2816ULL);
x86_l_58d:
	/* 0x58d: test   r14,r14 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_590:
	/* 0x590: jns    633 <generic_retkprobe_event+0x633> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x590, 0x633, x86_l_633);
x86_l_596:
	/* 0x596: mov    r14,QWORD PTR [r14] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_599:
	/* 0x599: xor    r15d,r15d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_59c:
	/* 0x59c: test   r14,r14 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_59f:
	/* 0x59f: je     636 <generic_retkprobe_event+0x636> */
	X86_SIM_X86_JCC(X86_CC_E, 0x59f, 0x636, x86_l_636);
x86_l_5a5:
	/* 0x5a5: lea    rax,[r14+0xaf4] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2804ULL);
x86_l_5ac:
	/* 0x5ac: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_5af:
	/* 0x5af: jns    5b4 <generic_retkprobe_event+0x5b4> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x5af, 0x5b4, x86_l_5b4);
x86_l_5b1:
	/* 0x5b1: mov    r15d,DWORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5b4:
	/* 0x5b4: mov    DWORD PTR [rsp+0x40],r15d */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_5b9:
	/* 0x5b9: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)execve_map));
x86_l_5c0:
	/* 0x5c0: lea    rsi,[rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_5c5:
	/* 0x5c5: call   5ca <generic_retkprobe_event+0x5ca> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_5ca:
	/* 0x5ca: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_5cd:
	/* 0x5cd: je     5d9 <generic_retkprobe_event+0x5d9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5cd, 0x5d9, x86_l_5d9);
x86_l_5cf:
	/* 0x5cf: mov    r15,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R15, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_5d2:
	/* 0x5d2: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_5d7:
	/* 0x5d7: jne    636 <generic_retkprobe_event+0x636> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x5d7, 0x636, x86_l_636);
x86_l_5d9:
	/* 0x5d9: add    r14,0xb00 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 2816ULL);
x86_l_5e0:
	/* 0x5e0: test   r14,r14 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_5e3:
	/* 0x5e3: jns    633 <generic_retkprobe_event+0x633> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x5e3, 0x633, x86_l_633);
x86_l_5e5:
	/* 0x5e5: mov    r14,QWORD PTR [r14] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5e8:
	/* 0x5e8: xor    r15d,r15d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_5eb:
	/* 0x5eb: test   r14,r14 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_5ee:
	/* 0x5ee: je     636 <generic_retkprobe_event+0x636> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5ee, 0x636, x86_l_636);
x86_l_5f0:
	/* 0x5f0: lea    rax,[r14+0xaf4] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2804ULL);
x86_l_5f7:
	/* 0x5f7: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_5fa:
	/* 0x5fa: jns    5ff <generic_retkprobe_event+0x5ff> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x5fa, 0x5ff, x86_l_5ff);
x86_l_5fc:
	/* 0x5fc: mov    r15d,DWORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5ff:
	/* 0x5ff: mov    DWORD PTR [rsp+0x40],r15d */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_604:
	/* 0x604: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)execve_map));
x86_l_60b:
	/* 0x60b: lea    rsi,[rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_610:
	/* 0x610: call   615 <generic_retkprobe_event+0x615> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_615:
	/* 0x615: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_618:
	/* 0x618: je     624 <generic_retkprobe_event+0x624> */
	X86_SIM_X86_JCC(X86_CC_E, 0x618, 0x624, x86_l_624);
x86_l_61a:
	/* 0x61a: mov    r15,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R15, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_61d:
	/* 0x61d: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_622:
	/* 0x622: jne    636 <generic_retkprobe_event+0x636> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x622, 0x636, x86_l_636);
x86_l_624:
	/* 0x624: add    r14,0xb00 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 2816ULL);
x86_l_62b:
	/* 0x62b: test   r14,r14 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_62e:
	/* 0x62e: jns    633 <generic_retkprobe_event+0x633> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x62e, 0x633, x86_l_633);
x86_l_630:
	/* 0x630: mov    rax,QWORD PTR [r14] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_633:
	/* 0x633: xor    r15d,r15d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_636:
	/* 0x636: mov    DWORD PTR [rbx],0x10d */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 269ULL);
x86_l_63c:
	/* 0x63c: mov    DWORD PTR [rbx+0x4],r13d */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_640:
	/* 0x640: call   645 <generic_retkprobe_event+0x645> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_ktime_get_boot_ns);
x86_l_645:
	/* 0x645: mov    QWORD PTR [rbx+0x8],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_649:
	/* 0x649: test   r15,r15 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_64c:
	/* 0x64c: je     65c <generic_retkprobe_event+0x65c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x64c, 0x65c, x86_l_65c);
x86_l_64e:
	/* 0x64e: mov    eax,DWORD PTR [r15] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_651:
	/* 0x651: mov    DWORD PTR [rbx+0x10],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_654:
	/* 0x654: mov    rax,QWORD PTR [r15+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_658:
	/* 0x658: mov    QWORD PTR [rbx+0x18],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_65c:
	/* 0x65c: mov    DWORD PTR [rbx+0x14],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_663:
	/* 0x663: mov    rax,QWORD PTR [rsp+0xd0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_66b:
	/* 0x66b: mov    eax,DWORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_66d:
	/* 0x66d: mov    QWORD PTR [rbx+0x60],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_671:
	/* 0x671: mov    DWORD PTR [rbx+0x4],r13d */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_675:
	/* 0x675: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RSI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)retkprobe_calls));
x86_l_67c:
	/* 0x67c: mov    rdi,QWORD PTR [rsp+0xf0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_684:
	/* 0x684: mov    edx,0x3 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 3ULL);
x86_l_689:
	/* 0x689: call   68e <generic_retkprobe_event+0x68e> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_tail_call);
x86_l_68e:
	/* 0x68e: mov    ebp,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_693:
	/* 0x693: mov    eax,ebp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RBP, X86_WIDTH_32, 0, 0);
x86_l_695:
	/* 0x695: add    rsp,0xf8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 248ULL);
x86_l_69c:
	/* 0x69c: pop    rbx */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_69d:
	/* 0x69d: pop    r12 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R12, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_69f:
	/* 0x69f: pop    r13 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R13, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_6a1:
	/* 0x6a1: pop    r14 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R14, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_6a3:
	/* 0x6a3: pop    r15 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R15, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_6a5:
	/* 0x6a5: pop    rbp */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBP, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_6a6:
	/* 0x6a6: jmp    4843 <__native_link_local_memset_zero_dynamic+0x7e> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_6ab:
	/* 0x6ab: mov    esi,ebp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_RBP, X86_WIDTH_32, 0, 0);
x86_l_6ad:
	/* 0x6ad: mov    r12,r8 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R12, X86_R8, X86_WIDTH_64, 0, 0);
x86_l_6b0:
	/* 0x6b0: mov    r15,r9 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R15, X86_R9, X86_WIDTH_64, 0, 0);
x86_l_6b3:
	/* 0x6b3: call   6b8 <generic_retkprobe_event+0x6b8> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_6b8:
	/* 0x6b8: mov    r8,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R8, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_6bb:
	/* 0x6bb: mov    ecx,0xfffffffe */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 4294967294ULL);
x86_l_6c0:
	/* 0x6c0: test   eax,eax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_6c2:
	/* 0x6c2: js     401 <generic_retkprobe_event+0x401> */
	X86_SIM_X86_JCC(X86_CC_S, 0x6c2, 0x401, x86_l_401);
x86_l_6c8:
	/* 0x6c8: mov    r9,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R9, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_6cb:
	/* 0x6cb: test   r9,r9 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R9, X86_R9, X86_WIDTH_64, 0, 0);
x86_l_6ce:
	/* 0x6ce: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_6d3:
	/* 0x6d3: jne    49f <generic_retkprobe_event+0x49f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x6d3, 0x49f, x86_l_49f);
x86_l_6d9:
	/* 0x6d9: xor    r9d,r9d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_R9, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_6dc:
	/* 0x6dc: cmp    QWORD PTR [rsp+0xb0],0x1 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244097ULL);
x86_l_6e5:
	/* 0x6e5: jne    8d4 <generic_retkprobe_event+0x8d4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x6e5, 0x8d4, x86_l_8d4);
x86_l_6eb:
	/* 0x6eb: mov    r13,rbp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R13, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_6ee:
	/* 0x6ee: jmp    3b5 <generic_retkprobe_event+0x3b5> */
	X86_SIM_X86_JMP(0x6ee, 0x3b5, x86_l_3b5);
x86_l_6f3:
	/* 0x6f3: cmp    r14d,0x2c */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, 0, 44ULL);
x86_l_6f7:
	/* 0x6f7: ja     841 <generic_retkprobe_event+0x841> */
	X86_SIM_X86_JCC(X86_CC_A, 0x6f7, 0x841, x86_l_841);
x86_l_6fd:
	/* 0x6fd: mov    eax,r14d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_R14, X86_WIDTH_32, 0, 0);
x86_l_700:
	/* 0x700: movabs rcx,0x11c1f2027cf2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, 0, 19524686609650ULL);
x86_l_70a:
	/* 0x70a: bt     rcx,rax */
	X86_SIM_RUN_OP(X86_OP_BT, X86_RCX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_70e:
	/* 0x70e: jae    841 <generic_retkprobe_event+0x841> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x70e, 0x841, x86_l_841);
x86_l_714:
	/* 0x714: mov    QWORD PTR [rsp+0x20],rbp */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_719:
	/* 0x719: mov    DWORD PTR [rsp+0xc8],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 858993459200ULL);
x86_l_724:
	/* 0x724: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)process_call_heap));
x86_l_72b:
	/* 0x72b: lea    rsi,[rsp+0xc8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_733:
	/* 0x733: call   738 <generic_retkprobe_event+0x738> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_738:
	/* 0x738: xor    r12d,r12d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_73b:
	/* 0x73b: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_73e:
	/* 0x73e: je     3d29 <generic_retkprobe_event+0x3d29> */
	X86_SIM_X86_JCC(X86_CC_E, 0x73e, 0x3d29, x86_l_3d29);
x86_l_744:
	/* 0x744: dec    r14d */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_747:
	/* 0x747: cmp    r14d,0x2b */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, 0, 43ULL);
x86_l_74b:
	/* 0x74b: mov    r13d,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_751:
	/* 0x751: ja     1ab2 <generic_retkprobe_event+0x1ab2> */
	X86_SIM_X86_JCC(X86_CC_A, 0x751, 0x1ab2, x86_l_1ab2);
x86_l_757:
	/* Capture image-bound code identity before scheduled instructions. */
	switch (X86_SIM_L_READ_REG(X86_R14) << 2) {
	case 0ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x120cULL); break;
	case 4ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x3d33ULL); break;
	case 8ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x3d33ULL); break;
	case 12ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x76bULL); break;
	case 16ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x14abULL); break;
	case 20ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x25e0ULL); break;
	case 24ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x13eaULL); break;
	case 28ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x3d33ULL); break;
	case 32ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x3d33ULL); break;
	case 36ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x76bULL); break;
	case 40ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x76bULL); break;
	case 44ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x120cULL); break;
	case 48ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x120cULL); break;
	case 52ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1487ULL); break;
	case 56ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x3d33ULL); break;
	case 60ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x3d33ULL); break;
	case 64ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1580ULL); break;
	case 68ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x3d33ULL); break;
	case 72ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x3d33ULL); break;
	case 76ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x3d33ULL); break;
	case 80ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x3d33ULL); break;
	case 84ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x3d33ULL); break;
	case 88ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x3d33ULL); break;
	case 92ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x3d33ULL); break;
	case 96ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x176bULL); break;
	case 100ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x3d33ULL); break;
	case 104ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x3d33ULL); break;
	case 108ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x76bULL); break;
	case 112ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1237ULL); break;
	case 116ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1237ULL); break;
	case 120ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1283ULL); break;
	case 124ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1283ULL); break;
	case 128ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x3d33ULL); break;
	case 132ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x3d33ULL); break;
	case 136ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x3d33ULL); break;
	case 140ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x3d33ULL); break;
	case 144ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x3d33ULL); break;
	case 148ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x142bULL); break;
	case 152ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x15c5ULL); break;
	case 156ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x139eULL); break;
	case 160ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x3d33ULL); break;
	case 164ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x3d33ULL); break;
	case 168ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x3d33ULL); break;
	case 172ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x14deULL); break;
	default: __x86_sim_unresolved_indirect_target();
	}
x86_l_765:
	/* 0x765: mov    r14,QWORD PTR [rsp] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_769:
	/* 0x769: jmp    rdx */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RDX);
		switch (X86_SIM_L_REG_TAG(X86_RDX)) {
		case X86_SIM_TAG_CODE:
			switch (__x86_target) {
			case 0x76bULL: goto x86_l_76b;
			case 0x120cULL: goto x86_l_120c;
			case 0x1237ULL: goto x86_l_1237;
			case 0x1283ULL: goto x86_l_1283;
			case 0x139eULL: goto x86_l_139e;
			case 0x13eaULL: goto x86_l_13ea;
			case 0x142bULL: goto x86_l_142b;
			case 0x1487ULL: goto x86_l_1487;
			case 0x14abULL: goto x86_l_14ab;
			case 0x14deULL: goto x86_l_14de;
			case 0x1580ULL: goto x86_l_1580;
			case 0x15c5ULL: goto x86_l_15c5;
			case 0x176bULL: goto x86_l_176b;
			case 0x25e0ULL: goto x86_l_25e0;
			case 0x3d33ULL: goto x86_l_3d33;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_76b:
	/* 0x76b: lea    rax,[rsp+0x20] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_770:
	/* 0x770: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_773:
	/* 0x773: jns    1264 <generic_retkprobe_event+0x1264> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x773, 0x1264, x86_l_1264);
x86_l_779:
	/* 0x779: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_77c:
	/* 0x77c: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_781:
	/* 0x781: jns    136d <generic_retkprobe_event+0x136d> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x781, 0x136d, x86_l_136d);
x86_l_787:
	/* 0x787: mov    rax,QWORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_78a:
	/* 0x78a: mov    QWORD PTR [rcx],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_78d:
	/* 0x78d: mov    r12d,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_793:
	/* 0x793: jmp    3d33 <generic_retkprobe_event+0x3d33> */
	X86_SIM_X86_JMP(0x793, 0x3d33, x86_l_3d33);
x86_l_798:
	/* 0x798: test   rbp,rbp */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_79b:
	/* 0x79b: js     914 <generic_retkprobe_event+0x914> */
	X86_SIM_X86_JCC(X86_CC_S, 0x79b, 0x914, x86_l_914);
x86_l_7a1:
	/* 0x7a1: lea    rdi,[rsp+0x20] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_7a6:
	/* 0x7a6: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_7ab:
	/* 0x7ab: mov    rdx,rbp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_7ae:
	/* 0x7ae: call   7b3 <generic_retkprobe_event+0x7b3> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_7b3:
	/* 0x7b3: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_7b8:
	/* 0x7b8: jmp    977 <generic_retkprobe_event+0x977> */
	X86_SIM_X86_JMP(0x7b8, 0x977, x86_l_977);
x86_l_7bd:
	/* 0x7bd: add    rbp,0x40 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 64ULL);
x86_l_7c1:
	/* 0x7c1: mov    QWORD PTR [rsp+0x40],rbp */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_7c6:
	/* 0x7c6: jns    8b8 <generic_retkprobe_event+0x8b8> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x7c6, 0x8b8, x86_l_8b8);
x86_l_7cc:
	/* 0x7cc: test   rbp,rbp */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_7cf:
	/* 0x7cf: jns    9ab <generic_retkprobe_event+0x9ab> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x7cf, 0x9ab, x86_l_9ab);
x86_l_7d5:
	/* 0x7d5: mov    r12,QWORD PTR [rbp+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R12, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7d9:
	/* 0x7d9: jmp    9ae <generic_retkprobe_event+0x9ae> */
	X86_SIM_X86_JMP(0x7d9, 0x9ae, x86_l_9ae);
x86_l_7de:
	/* 0x7de: mov    QWORD PTR [rsp+0xa0],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_7ea:
	/* 0x7ea: mov    QWORD PTR [rsp+0xa8],rbp */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_7f2:
	/* 0x7f2: lea    r12,[rsp+0xa0] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_7fa:
	/* 0x7fa: jmp    9b2 <generic_retkprobe_event+0x9b2> */
	X86_SIM_X86_JMP(0x7fa, 0x9b2, x86_l_9b2);
x86_l_7ff:
	/* 0x7ff: xor    esi,esi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_801:
	/* 0x801: mov    rdx,rbp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_804:
	/* 0x804: mov    r15,r8 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R15, X86_R8, X86_WIDTH_64, 0, 0);
x86_l_807:
	/* 0x807: call   47c5 <__native_link_local_memset_zero_dynamic> */
	X86_SIM_X86_CALL(x86_l_47c5, 0x80cULL);
x86_l_80c:
	/* 0x80c: mov    r8,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R8, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_80f:
	/* 0x80f: mov    ecx,0xfffffffe */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 4294967294ULL);
x86_l_814:
	/* 0x814: jmp    401 <generic_retkprobe_event+0x401> */
	X86_SIM_X86_JMP(0x814, 0x401, x86_l_401);
x86_l_819:
	/* 0x819: lea    rdi,[rsp+0x80] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_821:
	/* 0x821: lea    rdx,[rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_826:
	/* 0x826: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_82b:
	/* 0x82b: call   830 <generic_retkprobe_event+0x830> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_830:
	/* 0x830: mov    r12,QWORD PTR [rsp+0x80] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_838:
	/* 0x838: test   r12,r12 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_83b:
	/* 0x83b: jne    9b2 <generic_retkprobe_event+0x9b2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x83b, 0x9b2, x86_l_9b2);
x86_l_841:
	/* 0x841: mov    DWORD PTR [rsp+0xa0],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_84c:
	/* 0x84c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)process_call_heap));
x86_l_853:
	/* 0x853: lea    rsi,[rsp+0xa0] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_85b:
	/* 0x85b: call   860 <generic_retkprobe_event+0x860> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_860:
	/* 0x860: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_863:
	/* 0x863: je     381c <generic_retkprobe_event+0x381c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x863, 0x381c, x86_l_381c);
x86_l_869:
	/* 0x869: xor    r12d,r12d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_86c:
	/* 0x86c: add    r14d,0xfffffffe */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 4294967294ULL);
x86_l_870:
	/* 0x870: cmp    r14d,0x29 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, 0, 41ULL);
x86_l_874:
	/* 0x874: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_879:
	/* 0x879: ja     381f <generic_retkprobe_event+0x381f> */
	X86_SIM_X86_JCC(X86_CC_A, 0x879, 0x381f, x86_l_381f);
x86_l_87f:
	/* Capture image-bound code identity before scheduled instructions. */
	switch (X86_SIM_L_READ_REG(X86_R14) << 2) {
	case 0ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x18d8ULL); break;
	case 4ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1877ULL); break;
	case 8ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x3828ULL); break;
	case 12ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x3828ULL); break;
	case 16ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x3828ULL); break;
	case 20ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x3828ULL); break;
	case 24ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1917ULL); break;
	case 28ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x3828ULL); break;
	case 32ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x3828ULL); break;
	case 36ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x3828ULL); break;
	case 40ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x3828ULL); break;
	case 44ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x3828ULL); break;
	case 48ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x3828ULL); break;
	case 52ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x3828ULL); break;
	case 56ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x3828ULL); break;
	case 60ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x3828ULL); break;
	case 64ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x18bdULL); break;
	case 68ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x185cULL); break;
	case 72ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1887ULL); break;
	case 76ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x193bULL); break;
	case 80ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x195fULL); break;
	case 84ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1a4eULL); break;
	case 88ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x3828ULL); break;
	case 92ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x3828ULL); break;
	case 96ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x19b1ULL); break;
	case 100ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x17c9ULL); break;
	case 104ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x3828ULL); break;
	case 108ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x3828ULL); break;
	case 112ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x3828ULL); break;
	case 116ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x3828ULL); break;
	case 120ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x3828ULL); break;
	case 124ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x898ULL); break;
	case 128ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x898ULL); break;
	case 132ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x898ULL); break;
	case 136ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x898ULL); break;
	case 140ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x3828ULL); break;
	case 144ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x3828ULL); break;
	case 148ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x3828ULL); break;
	case 152ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x3828ULL); break;
	case 156ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1986ULL); break;
	case 160ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x3828ULL); break;
	case 164ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1a60ULL); break;
	default: __x86_sim_unresolved_indirect_target();
	}
x86_l_88d:
	/* 0x88d: mov    r14,QWORD PTR [rsp] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_891:
	/* 0x891: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_896:
	/* 0x896: jmp    rdx */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RDX);
		switch (X86_SIM_L_REG_TAG(X86_RDX)) {
		case X86_SIM_TAG_CODE:
			switch (__x86_target) {
			case 0x898ULL: goto x86_l_898;
			case 0x17c9ULL: goto x86_l_17c9;
			case 0x185cULL: goto x86_l_185c;
			case 0x1877ULL: goto x86_l_1877;
			case 0x1887ULL: goto x86_l_1887;
			case 0x18bdULL: goto x86_l_18bd;
			case 0x18d8ULL: goto x86_l_18d8;
			case 0x1917ULL: goto x86_l_1917;
			case 0x193bULL: goto x86_l_193b;
			case 0x195fULL: goto x86_l_195f;
			case 0x1986ULL: goto x86_l_1986;
			case 0x19b1ULL: goto x86_l_19b1;
			case 0x1a4eULL: goto x86_l_1a4e;
			case 0x1a60ULL: goto x86_l_1a60;
			case 0x3828ULL: goto x86_l_3828;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_898:
	/* 0x898: test   rbp,rbp */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_89b:
	/* 0x89b: js     1347 <generic_retkprobe_event+0x1347> */
	X86_SIM_X86_JCC(X86_CC_S, 0x89b, 0x1347, x86_l_1347);
x86_l_8a1:
	/* 0x8a1: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_8a6:
	/* 0x8a6: mov    rdx,rbp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_8a9:
	/* 0x8a9: call   8ae <generic_retkprobe_event+0x8ae> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_8ae:
	/* 0x8ae: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8b3:
	/* 0x8b3: jmp    1aa7 <generic_retkprobe_event+0x1aa7> */
	X86_SIM_X86_JMP(0x8b3, 0x1aa7, x86_l_1aa7);
x86_l_8b8:
	/* 0x8b8: lea    rdi,[rsp+0x20] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_8bd:
	/* 0x8bd: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_8c2:
	/* 0x8c2: mov    rdx,rbp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_8c5:
	/* 0x8c5: call   8ca <generic_retkprobe_event+0x8ca> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_8ca:
	/* 0x8ca: mov    r12,QWORD PTR [rsp+0x20] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_8cf:
	/* 0x8cf: jmp    9ae <generic_retkprobe_event+0x9ae> */
	X86_SIM_X86_JMP(0x8cf, 0x9ae, x86_l_9ae);
x86_l_8d4:
	/* 0x8d4: mov    QWORD PTR [rsp],r14 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8d8:
	/* 0x8d8: add    rdx,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_8dc:
	/* 0x8dc: js     113e <generic_retkprobe_event+0x113e> */
	X86_SIM_X86_JCC(X86_CC_S, 0x8dc, 0x113e, x86_l_113e);
x86_l_8e2:
	/* 0x8e2: lea    rdi,[rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_8e7:
	/* 0x8e7: mov    esi,0x10 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 16ULL);
x86_l_8ec:
	/* 0x8ec: mov    r14,r8 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R14, X86_R8, X86_WIDTH_64, 0, 0);
x86_l_8ef:
	/* 0x8ef: mov    r15,r9 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R15, X86_R9, X86_WIDTH_64, 0, 0);
x86_l_8f2:
	/* 0x8f2: call   8f7 <generic_retkprobe_event+0x8f7> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_8f7:
	/* 0x8f7: mov    r8,r14 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R8, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_8fa:
	/* 0x8fa: mov    ecx,0xfffffffe */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 4294967294ULL);
x86_l_8ff:
	/* 0x8ff: test   eax,eax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_901:
	/* 0x901: js     1178 <generic_retkprobe_event+0x1178> */
	X86_SIM_X86_JCC(X86_CC_S, 0x901, 0x1178, x86_l_1178);
x86_l_907:
	/* 0x907: mov    r9,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R9, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_90a:
	/* 0x90a: mov    r13,QWORD PTR [rsp+0x48] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_90f:
	/* 0x90f: jmp    1159 <generic_retkprobe_event+0x1159> */
	X86_SIM_X86_JMP(0x90f, 0x1159, x86_l_1159);
x86_l_914:
	/* 0x914: test   rbp,rbp */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_917:
	/* 0x917: jns    96c <generic_retkprobe_event+0x96c> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x917, 0x96c, x86_l_96c);
x86_l_919:
	/* 0x919: mov    rax,QWORD PTR [rbp+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_91d:
	/* 0x91d: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_922:
	/* 0x922: jmp    977 <generic_retkprobe_event+0x977> */
	X86_SIM_X86_JMP(0x922, 0x977, x86_l_977);
x86_l_924:
	/* 0x924: mov    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_926:
	/* 0x926: mov    esi,DWORD PTR [rdx+rcx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_929:
	/* 0x929: mov    DWORD PTR [rdi+rcx*1],esi */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_92c:
	/* 0x92c: or     eax,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_OR, 4ULL);
x86_l_92f:
	/* 0x92f: test   bpl,0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, 0, 2ULL);
x86_l_933:
	/* 0x933: je     487 <generic_retkprobe_event+0x487> */
	X86_SIM_X86_JCC(X86_CC_E, 0x933, 0x487, x86_l_487);
x86_l_939:
	/* 0x939: mov    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_93b:
	/* 0x93b: movzx  esi,WORD PTR [rdx+rcx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_16), 0ULL);
x86_l_93f:
	/* 0x93f: mov    WORD PTR [rdi+rcx*1],si */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RSI, X86_WIDTH_16, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_943:
	/* 0x943: add    eax,0x2 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_946:
	/* 0x946: test   bpl,0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_94a:
	/* 0x94a: je     491 <generic_retkprobe_event+0x491> */
	X86_SIM_X86_JCC(X86_CC_E, 0x94a, 0x491, x86_l_491);
x86_l_950:
	/* 0x950: mov    eax,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_952:
	/* 0x952: movzx  ecx,BYTE PTR [rdx+rax*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_956:
	/* 0x956: mov    BYTE PTR [rdi+rax*1],cl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_959:
	/* 0x959: test   r9,r9 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R9, X86_R9, X86_WIDTH_64, 0, 0);
x86_l_95c:
	/* 0x95c: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_961:
	/* 0x961: jne    49f <generic_retkprobe_event+0x49f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x961, 0x49f, x86_l_49f);
x86_l_967:
	/* 0x967: jmp    6d9 <generic_retkprobe_event+0x6d9> */
	X86_SIM_X86_JMP(0x967, 0x6d9, x86_l_6d9);
x86_l_96c:
	/* 0x96c: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_975:
	/* 0x975: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_977:
	/* 0x977: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_97c:
	/* 0x97c: test   r13,r13 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_97f:
	/* 0x97f: jns    990 <generic_retkprobe_event+0x990> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x97f, 0x990, x86_l_990);
x86_l_981:
	/* 0x981: lea    rax,[rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_986:
	/* 0x986: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_989:
	/* 0x989: jns    9ab <generic_retkprobe_event+0x9ab> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x989, 0x9ab, x86_l_9ab);
x86_l_98b:
	/* 0x98b: mov    r12,QWORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_98e:
	/* 0x98e: jmp    9ae <generic_retkprobe_event+0x9ae> */
	X86_SIM_X86_JMP(0x98e, 0x9ae, x86_l_9ae);
x86_l_990:
	/* 0x990: lea    rdi,[rsp+0x20] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_995:
	/* 0x995: lea    rdx,[rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_99a:
	/* 0x99a: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_99f:
	/* 0x99f: call   9a4 <generic_retkprobe_event+0x9a4> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_9a4:
	/* 0x9a4: mov    r12,QWORD PTR [rsp+0x20] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_9a9:
	/* 0x9a9: jmp    9ae <generic_retkprobe_event+0x9ae> */
	X86_SIM_X86_JMP(0x9a9, 0x9ae, x86_l_9ae);
x86_l_9ab:
	/* 0x9ab: xor    r12d,r12d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_9ae:
	/* 0x9ae: add    r12,0x40 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 64ULL);
x86_l_9b2:
	/* 0x9b2: mov    DWORD PTR [rsp+0xec],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1013612281856ULL);
x86_l_9bd:
	/* 0x9bd: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)buffer_heap_map));
x86_l_9c4:
	/* 0x9c4: lea    rsi,[rsp+0xec] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 236ULL);
x86_l_9cc:
	/* 0x9cc: call   9d1 <generic_retkprobe_event+0x9d1> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_9d1:
	/* 0x9d1: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_9d4:
	/* 0x9d4: je     9f8 <generic_retkprobe_event+0x9f8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9d4, 0x9f8, x86_l_9f8);
x86_l_9d6:
	/* 0x9d6: mov    r13,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R13, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_9d9:
	/* 0x9d9: call   9de <generic_retkprobe_event+0x9de> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_get_current_task);
x86_l_9de:
	/* 0x9de: add    rax,0xd50 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 3408ULL);
x86_l_9e4:
	/* 0x9e4: jns    a04 <generic_retkprobe_event+0xa04> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x9e4, 0xa04, x86_l_a04);
x86_l_9e6:
	/* 0x9e6: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_9e9:
	/* 0x9e9: jns    a23 <generic_retkprobe_event+0xa23> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x9e9, 0xa23, x86_l_a23);
x86_l_9eb:
	/* 0x9eb: mov    rbp,QWORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9ee:
	/* 0x9ee: mov    QWORD PTR [rsp+0xd8],rbp */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_9f6:
	/* 0x9f6: jmp    a31 <generic_retkprobe_event+0xa31> */
	X86_SIM_X86_JMP(0x9f6, 0xa31, x86_l_a31);
x86_l_9f8:
	/* 0x9f8: xor    r12d,r12d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_9fb:
	/* 0x9fb: mov    r14,QWORD PTR [rsp] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9ff:
	/* 0x9ff: jmp    108a <generic_retkprobe_event+0x108a> */
	X86_SIM_X86_JMP(0x9ff, 0x108a, x86_l_108a);
x86_l_a04:
	/* 0xa04: lea    rdi,[rsp+0xd8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_a0c:
	/* 0xa0c: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_a11:
	/* 0xa11: mov    rdx,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_a14:
	/* 0xa14: call   a19 <generic_retkprobe_event+0xa19> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_a19:
	/* 0xa19: mov    rbp,QWORD PTR [rsp+0xd8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_a21:
	/* 0xa21: jmp    a31 <generic_retkprobe_event+0xa31> */
	X86_SIM_X86_JMP(0xa21, 0xa31, x86_l_a31);
x86_l_a23:
	/* 0xa23: mov    QWORD PTR [rsp+0xd8],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 927712935936ULL);
x86_l_a2f:
	/* 0xa2f: xor    ebp,ebp */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_a31:
	/* 0xa31: mov    rdx,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_a34:
	/* 0xa34: add    rdx,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_a38:
	/* 0xa38: mov    QWORD PTR [rsp+0x98],rdx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_a40:
	/* 0xa40: jns    a57 <generic_retkprobe_event+0xa57> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xa40, 0xa57, x86_l_a57);
x86_l_a42:
	/* 0xa42: mov    rax,rdx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_a45:
	/* 0xa45: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_a48:
	/* 0xa48: jns    a73 <generic_retkprobe_event+0xa73> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xa48, 0xa73, x86_l_a73);
x86_l_a4a:
	/* 0xa4a: mov    r14,QWORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a4d:
	/* 0xa4d: mov    QWORD PTR [rsp+0xb8],r14 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_a55:
	/* 0xa55: jmp    a82 <generic_retkprobe_event+0xa82> */
	X86_SIM_X86_JMP(0xa55, 0xa82, x86_l_a82);
x86_l_a57:
	/* 0xa57: lea    rdi,[rsp+0xb8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_a5f:
	/* 0xa5f: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_a64:
	/* 0xa64: call   a69 <generic_retkprobe_event+0xa69> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_a69:
	/* 0xa69: mov    r14,QWORD PTR [rsp+0xb8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_a71:
	/* 0xa71: jmp    a82 <generic_retkprobe_event+0xa82> */
	X86_SIM_X86_JMP(0xa71, 0xa82, x86_l_a82);
x86_l_a73:
	/* 0xa73: mov    QWORD PTR [rsp+0xb8],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_a7f:
	/* 0xa7f: xor    r14d,r14d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_a82:
	/* 0xa82: lea    r15,[r13+0x1000] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4096ULL);
x86_l_a89:
	/* 0xa89: mov    rdx,r14 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_a8c:
	/* 0xa8c: add    rdx,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_a90:
	/* 0xa90: jns    a9c <generic_retkprobe_event+0xa9c> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xa90, 0xa9c, x86_l_a9c);
x86_l_a92:
	/* 0xa92: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_a95:
	/* 0xa95: jns    aba <generic_retkprobe_event+0xaba> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xa95, 0xaba, x86_l_aba);
x86_l_a97:
	/* 0xa97: mov    rcx,QWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a9a:
	/* 0xa9a: jmp    ab0 <generic_retkprobe_event+0xab0> */
	X86_SIM_X86_JMP(0xa9a, 0xab0, x86_l_ab0);
x86_l_a9c:
	/* 0xa9c: lea    rdi,[rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_aa1:
	/* 0xaa1: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_aa6:
	/* 0xaa6: call   aab <generic_retkprobe_event+0xaab> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_aab:
	/* 0xaab: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_ab0:
	/* 0xab0: mov    eax,0x1000 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 4096ULL);
x86_l_ab5:
	/* 0xab5: test   rcx,rcx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_ab8:
	/* 0xab8: jne    b1b <generic_retkprobe_event+0xb1b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xab8, 0xb1b, x86_l_b1b);
x86_l_aba:
	/* 0xaba: mov    rdx,r14 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_abd:
	/* 0xabd: add    rdx,0x18 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_ac1:
	/* 0xac1: jns    acd <generic_retkprobe_event+0xacd> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xac1, 0xacd, x86_l_acd);
x86_l_ac3:
	/* 0xac3: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_ac6:
	/* 0xac6: jns    ae3 <generic_retkprobe_event+0xae3> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xac6, 0xae3, x86_l_ae3);
x86_l_ac8:
	/* 0xac8: mov    rax,QWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_acb:
	/* 0xacb: jmp    ae5 <generic_retkprobe_event+0xae5> */
	X86_SIM_X86_JMP(0xacb, 0xae5, x86_l_ae5);
x86_l_acd:
	/* 0xacd: lea    rdi,[rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_ad2:
	/* 0xad2: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_ad7:
	/* 0xad7: call   adc <generic_retkprobe_event+0xadc> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_adc:
	/* 0xadc: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_ae1:
	/* 0xae1: jmp    ae5 <generic_retkprobe_event+0xae5> */
	X86_SIM_X86_JMP(0xae1, 0xae5, x86_l_ae5);
x86_l_ae3:
	/* 0xae3: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_ae5:
	/* 0xae5: cmp    rax,r14 */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RAX, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_ae8:
	/* 0xae8: je     b16 <generic_retkprobe_event+0xb16> */
	X86_SIM_X86_JCC(X86_CC_E, 0xae8, 0xb16, x86_l_b16);
x86_l_aea:
	/* 0xaea: mov    r15,r13 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R15, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_aed:
	/* 0xaed: add    r15,0xff6 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 4086ULL);
x86_l_af4:
	/* 0xaf4: movabs rax,0x6574656c65642820 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, 0, 7310579611361093664ULL);
x86_l_afe:
	/* 0xafe: mov    QWORD PTR [r13+0xff6],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4086ULL);
x86_l_b05:
	/* 0xb05: mov    WORD PTR [r13+0xffe],0x2964 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17583596120420ULL);
x86_l_b0f:
	/* 0xb0f: mov    eax,0xff6 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 4086ULL);
x86_l_b14:
	/* 0xb14: jmp    b1b <generic_retkprobe_event+0xb1b> */
	X86_SIM_X86_JMP(0xb14, 0xb1b, x86_l_b1b);
x86_l_b16:
	/* 0xb16: mov    eax,0x1000 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 4096ULL);
x86_l_b1b:
	/* 0xb1b: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_b24:
	/* 0xb24: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_b2d:
	/* 0xb2d: mov    QWORD PTR [rsp+0x50],r13 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_b32:
	/* 0xb32: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_b3b:
	/* 0xb3b: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_b44:
	/* 0xb44: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_b4d:
	/* 0xb4d: mov    QWORD PTR [rsp+0x70],r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_b52:
	/* 0xb52: lea    r13,[rbp+0x18] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R13, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b56:
	/* 0xb56: mov    DWORD PTR [rsp+0x78],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_b5a:
	/* 0xb5a: mov    BYTE PTR [rsp+0x7c],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 532575944704ULL);
x86_l_b5f:
	/* 0xb5f: add    rbp,0x20 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_b63:
	/* 0xb63: jns    b75 <generic_retkprobe_event+0xb75> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xb63, 0xb75, x86_l_b75);
x86_l_b65:
	/* 0xb65: test   rbp,rbp */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_b68:
	/* 0xb68: jns    b89 <generic_retkprobe_event+0xb89> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xb68, 0xb89, x86_l_b89);
x86_l_b6a:
	/* 0xb6a: mov    rax,QWORD PTR [rbp+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b6e:
	/* 0xb6e: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_b73:
	/* 0xb73: jmp    b92 <generic_retkprobe_event+0xb92> */
	X86_SIM_X86_JMP(0xb73, 0xb92, x86_l_b92);
x86_l_b75:
	/* 0xb75: lea    rdi,[rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_b7a:
	/* 0xb7a: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_b7f:
	/* 0xb7f: mov    rdx,rbp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_b82:
	/* 0xb82: call   b87 <generic_retkprobe_event+0xb87> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_b87:
	/* 0xb87: jmp    b92 <generic_retkprobe_event+0xb92> */
	X86_SIM_X86_JMP(0xb87, 0xb92, x86_l_b92);
x86_l_b89:
	/* 0xb89: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_b92:
	/* 0xb92: test   r13,r13 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_b95:
	/* 0xb95: jns    ba7 <generic_retkprobe_event+0xba7> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xb95, 0xba7, x86_l_ba7);
x86_l_b97:
	/* 0xb97: test   r13,r13 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_b9a:
	/* 0xb9a: jns    bbb <generic_retkprobe_event+0xbbb> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xb9a, 0xbbb, x86_l_bbb);
x86_l_b9c:
	/* 0xb9c: mov    rax,QWORD PTR [r13+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ba0:
	/* 0xba0: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_ba5:
	/* 0xba5: jmp    bc4 <generic_retkprobe_event+0xbc4> */
	X86_SIM_X86_JMP(0xba5, 0xbc4, x86_l_bc4);
x86_l_ba7:
	/* 0xba7: lea    rdi,[rsp+0x48] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_bac:
	/* 0xbac: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_bb1:
	/* 0xbb1: mov    rdx,r13 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_bb4:
	/* 0xbb4: call   bb9 <generic_retkprobe_event+0xbb9> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_bb9:
	/* 0xbb9: jmp    bc4 <generic_retkprobe_event+0xbc4> */
	X86_SIM_X86_JMP(0xbb9, 0xbc4, x86_l_bc4);
x86_l_bbb:
	/* 0xbbb: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_bc4:
	/* 0xbc4: mov    rdx,QWORD PTR [rsp+0x98] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_bcc:
	/* 0xbcc: lea    rdi,[rsp+0x58] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_bd1:
	/* 0xbd1: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_bd4:
	/* 0xbd4: jns    be8 <generic_retkprobe_event+0xbe8> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xbd4, 0xbe8, x86_l_be8);
x86_l_bd6:
	/* 0xbd6: mov    rax,rdx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_bd9:
	/* 0xbd9: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_bdc:
	/* 0xbdc: jns    bf4 <generic_retkprobe_event+0xbf4> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xbdc, 0xbf4, x86_l_bf4);
x86_l_bde:
	/* 0xbde: mov    rax,QWORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_be1:
	/* 0xbe1: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_be6:
	/* 0xbe6: jmp    bfd <generic_retkprobe_event+0xbfd> */
	X86_SIM_X86_JMP(0xbe6, 0xbfd, x86_l_bfd);
x86_l_be8:
	/* 0xbe8: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_bed:
	/* 0xbed: call   bf2 <generic_retkprobe_event+0xbf2> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_bf2:
	/* 0xbf2: jmp    bfd <generic_retkprobe_event+0xbfd> */
	X86_SIM_X86_JMP(0xbf2, 0xbfd, x86_l_bfd);
x86_l_bf4:
	/* 0xbf4: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_bfd:
	/* 0xbfd: test   r12,r12 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_c00:
	/* 0xc00: jns    c12 <generic_retkprobe_event+0xc12> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xc00, 0xc12, x86_l_c12);
x86_l_c02:
	/* 0xc02: test   r12,r12 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_c05:
	/* 0xc05: jns    c2b <generic_retkprobe_event+0xc2b> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xc05, 0xc2b, x86_l_c2b);
x86_l_c07:
	/* 0xc07: mov    rax,QWORD PTR [r12] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c0b:
	/* 0xc0b: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_c10:
	/* 0xc10: jmp    c36 <generic_retkprobe_event+0xc36> */
	X86_SIM_X86_JMP(0xc10, 0xc36, x86_l_c36);
x86_l_c12:
	/* 0xc12: lea    rdi,[rsp+0x60] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_c17:
	/* 0xc17: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_c1c:
	/* 0xc1c: mov    rdx,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_c1f:
	/* 0xc1f: call   c24 <generic_retkprobe_event+0xc24> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_c24:
	/* 0xc24: mov    rax,QWORD PTR [rsp+0x60] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_c29:
	/* 0xc29: jmp    c36 <generic_retkprobe_event+0xc36> */
	X86_SIM_X86_JMP(0xc29, 0xc36, x86_l_c36);
x86_l_c2b:
	/* 0xc2b: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_c34:
	/* 0xc34: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_c36:
	/* 0xc36: add    rax,0xffffffffffffffe0 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551584ULL);
x86_l_c3a:
	/* 0xc3a: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_c3f:
	/* 0xc3f: xor    r14d,r14d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_c42:
	/* 0xc42: mov    QWORD PTR [rsp+0x30],r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_c47:
	/* 0xc47: jmp    c84 <generic_retkprobe_event+0xc84> */
	X86_SIM_X86_JMP(0xc47, 0xc84, x86_l_c84);
x86_l_c49:
	/* 0xc49: lea    rdi,[rsp+0x58] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_c4e:
	/* 0xc4e: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_c53:
	/* 0xc53: mov    rdx,r13 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_c56:
	/* 0xc56: call   c5b <generic_retkprobe_event+0xc5b> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_c5b:
	/* 0xc5b: mov    r13d,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_c61:
	/* 0xc61: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c66:
	/* 0xc66: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_c6b:
	/* 0xc6b: add    rax,0x20 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_c6f:
	/* 0xc6f: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_c74:
	/* 0xc74: inc    r14d */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_c77:
	/* 0xc77: cmp    r14d,0x800 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, 0, 2048ULL);
x86_l_c7e:
	/* 0xc7e: je     fbd <generic_retkprobe_event+0xfbd> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc7e, 0xfbd, x86_l_fbd);
x86_l_c84:
	/* 0xc84: mov    r12,QWORD PTR [rsp+0x58] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_c89:
	/* 0xc89: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_c8e:
	/* 0xc8e: mov    r13,QWORD PTR [rsp+0x68] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_c93:
	/* 0xc93: cmp    r12,QWORD PTR [rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 64ULL);
x86_l_c98:
	/* 0xc98: jne    ca5 <generic_retkprobe_event+0xca5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xc98, 0xca5, x86_l_ca5);
x86_l_c9a:
	/* 0xc9a: cmp    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 72ULL);
x86_l_c9f:
	/* 0xc9f: je     fa0 <generic_retkprobe_event+0xfa0> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc9f, 0xfa0, x86_l_fa0);
x86_l_ca5:
	/* 0xca5: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_ca8:
	/* 0xca8: jns    cc4 <generic_retkprobe_event+0xcc4> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xca8, 0xcc4, x86_l_cc4);
x86_l_caa:
	/* 0xcaa: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_cad:
	/* 0xcad: jns    ce8 <generic_retkprobe_event+0xce8> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xcad, 0xce8, x86_l_ce8);
x86_l_caf:
	/* 0xcaf: mov    rax,QWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cb2:
	/* 0xcb2: mov    QWORD PTR [rsp+0x90],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_cba:
	/* 0xcba: cmp    r12,rax */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_R12, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_cbd:
	/* 0xcbd: jne    cfb <generic_retkprobe_event+0xcfb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xcbd, 0xcfb, x86_l_cfb);
x86_l_cbf:
	/* 0xcbf: jmp    d68 <generic_retkprobe_event+0xd68> */
	X86_SIM_X86_JMP(0xcbf, 0xd68, x86_l_d68);
x86_l_cc4:
	/* 0xcc4: lea    rdi,[rsp+0x90] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_ccc:
	/* 0xccc: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_cd1:
	/* 0xcd1: call   cd6 <generic_retkprobe_event+0xcd6> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_cd6:
	/* 0xcd6: mov    rax,QWORD PTR [rsp+0x90] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_cde:
	/* 0xcde: cmp    r12,rax */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_R12, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_ce1:
	/* 0xce1: jne    cfb <generic_retkprobe_event+0xcfb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xce1, 0xcfb, x86_l_cfb);
x86_l_ce3:
	/* 0xce3: jmp    d68 <generic_retkprobe_event+0xd68> */
	X86_SIM_X86_JMP(0xce3, 0xd68, x86_l_d68);
x86_l_ce8:
	/* 0xce8: mov    QWORD PTR [rsp+0x90],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_cf4:
	/* 0xcf4: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_cf6:
	/* 0xcf6: cmp    r12,rax */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_R12, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_cf9:
	/* 0xcf9: je     d68 <generic_retkprobe_event+0xd68> */
	X86_SIM_X86_JCC(X86_CC_E, 0xcf9, 0xd68, x86_l_d68);
x86_l_cfb:
	/* 0xcfb: mov    rbp,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RBP, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_cfe:
	/* 0xcfe: add    rbp,0x18 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_d02:
	/* 0xd02: jns    d16 <generic_retkprobe_event+0xd16> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xd02, 0xd16, x86_l_d16);
x86_l_d04:
	/* 0xd04: mov    rax,rbp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_d07:
	/* 0xd07: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_d0a:
	/* 0xd0a: jns    d49 <generic_retkprobe_event+0xd49> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xd0a, 0xd49, x86_l_d49);
x86_l_d0c:
	/* 0xd0c: mov    rax,QWORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d0f:
	/* 0xd0f: cmp    r12,rax */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_R12, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_d12:
	/* 0xd12: jne    d4e <generic_retkprobe_event+0xd4e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xd12, 0xd4e, x86_l_d4e);
x86_l_d14:
	/* 0xd14: jmp    d68 <generic_retkprobe_event+0xd68> */
	X86_SIM_X86_JMP(0xd14, 0xd68, x86_l_d68);
x86_l_d16:
	/* 0xd16: lea    rdi,[rsp+0x20] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d1b:
	/* 0xd1b: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_d20:
	/* 0xd20: mov    rdx,rbp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_d23:
	/* 0xd23: call   d28 <generic_retkprobe_event+0xd28> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_d28:
	/* 0xd28: cmp    QWORD PTR [rsp+0x20],r12 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d2d:
	/* 0xd2d: je     d68 <generic_retkprobe_event+0xd68> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd2d, 0xd68, x86_l_d68);
x86_l_d2f:
	/* 0xd2f: lea    rdi,[rsp+0xc8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_d37:
	/* 0xd37: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_d3c:
	/* 0xd3c: mov    rdx,rbp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_d3f:
	/* 0xd3f: call   d44 <generic_retkprobe_event+0xd44> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_d44:
	/* 0xd44: jmp    df7 <generic_retkprobe_event+0xdf7> */
	X86_SIM_X86_JMP(0xd44, 0xdf7, x86_l_df7);
x86_l_d49:
	/* 0xd49: test   r12,r12 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_d4c:
	/* 0xd4c: je     d68 <generic_retkprobe_event+0xd68> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd4c, 0xd68, x86_l_d68);
x86_l_d4e:
	/* 0xd4e: test   rbp,rbp */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_d51:
	/* 0xd51: jns    deb <generic_retkprobe_event+0xdeb> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xd51, 0xdeb, x86_l_deb);
x86_l_d57:
	/* 0xd57: mov    rax,QWORD PTR [rbp+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d5b:
	/* 0xd5b: mov    QWORD PTR [rsp+0xc8],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_d63:
	/* 0xd63: jmp    df7 <generic_retkprobe_event+0xdf7> */
	X86_SIM_X86_JMP(0xd63, 0xdf7, x86_l_df7);
x86_l_d68:
	/* 0xd68: mov    rdx,r13 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_d6b:
	/* 0xd6b: add    rdx,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_d6f:
	/* 0xd6f: jns    d8a <generic_retkprobe_event+0xd8a> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xd6f, 0xd8a, x86_l_d8a);
x86_l_d71:
	/* 0xd71: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_d74:
	/* 0xd74: jns    daa <generic_retkprobe_event+0xdaa> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xd74, 0xdaa, x86_l_daa);
x86_l_d76:
	/* 0xd76: mov    rax,QWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d79:
	/* 0xd79: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d7e:
	/* 0xd7e: cmp    QWORD PTR [rsp+0x68],rax */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_d83:
	/* 0xd83: jne    dc0 <generic_retkprobe_event+0xdc0> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xd83, 0xdc0, x86_l_dc0);
x86_l_d85:
	/* 0xd85: jmp    fb2 <generic_retkprobe_event+0xfb2> */
	X86_SIM_X86_JMP(0xd85, 0xfb2, x86_l_fb2);
x86_l_d8a:
	/* 0xd8a: lea    rdi,[rsp+0x20] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d8f:
	/* 0xd8f: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_d94:
	/* 0xd94: call   d99 <generic_retkprobe_event+0xd99> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_d99:
	/* 0xd99: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d9e:
	/* 0xd9e: cmp    QWORD PTR [rsp+0x68],rax */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_da3:
	/* 0xda3: jne    dc0 <generic_retkprobe_event+0xdc0> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xda3, 0xdc0, x86_l_dc0);
x86_l_da5:
	/* 0xda5: jmp    fb2 <generic_retkprobe_event+0xfb2> */
	X86_SIM_X86_JMP(0xda5, 0xfb2, x86_l_fb2);
x86_l_daa:
	/* 0xdaa: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_db3:
	/* 0xdb3: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_db5:
	/* 0xdb5: cmp    QWORD PTR [rsp+0x68],rax */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_dba:
	/* 0xdba: je     fb2 <generic_retkprobe_event+0xfb2> */
	X86_SIM_X86_JCC(X86_CC_E, 0xdba, 0xfb2, x86_l_fb2);
x86_l_dc0:
	/* 0xdc0: add    r13,0x18 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_dc4:
	/* 0xdc4: jns    c49 <generic_retkprobe_event+0xc49> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xdc4, 0xc49, x86_l_c49);
x86_l_dca:
	/* 0xdca: test   r13,r13 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_dcd:
	/* 0xdcd: jns    ddd <generic_retkprobe_event+0xddd> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xdcd, 0xddd, x86_l_ddd);
x86_l_dcf:
	/* 0xdcf: mov    rax,QWORD PTR [r13+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_dd3:
	/* 0xdd3: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_dd8:
	/* 0xdd8: jmp    c5b <generic_retkprobe_event+0xc5b> */
	X86_SIM_X86_JMP(0xdd8, 0xc5b, x86_l_c5b);
x86_l_ddd:
	/* 0xddd: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_de6:
	/* 0xde6: jmp    c5b <generic_retkprobe_event+0xc5b> */
	X86_SIM_X86_JMP(0xde6, 0xc5b, x86_l_c5b);
x86_l_deb:
	/* 0xdeb: mov    QWORD PTR [rsp+0xc8],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 858993459200ULL);
x86_l_df7:
	/* 0xdf7: add    r12,0x20 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_dfb:
	/* 0xdfb: jns    e1d <generic_retkprobe_event+0xe1d> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xdfb, 0xe1d, x86_l_e1d);
x86_l_dfd:
	/* 0xdfd: test   r12,r12 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_e00:
	/* 0xe00: jns    e3c <generic_retkprobe_event+0xe3c> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xe00, 0xe3c, x86_l_e3c);
x86_l_e02:
	/* 0xe02: mov    rax,QWORD PTR [r12] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e06:
	/* 0xe06: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_e0e:
	/* 0xe0e: mov    rdx,QWORD PTR [r12+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e13:
	/* 0xe13: mov    QWORD PTR [rsp+0x88],rdx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_e1b:
	/* 0xe1b: jmp    e56 <generic_retkprobe_event+0xe56> */
	X86_SIM_X86_JMP(0xe1b, 0xe56, x86_l_e56);
x86_l_e1d:
	/* 0xe1d: lea    rdi,[rsp+0x80] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_e25:
	/* 0xe25: mov    esi,0x10 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 16ULL);
x86_l_e2a:
	/* 0xe2a: mov    rdx,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_e2d:
	/* 0xe2d: call   e32 <generic_retkprobe_event+0xe32> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_e32:
	/* 0xe32: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_e3a:
	/* 0xe3a: jmp    e56 <generic_retkprobe_event+0xe56> */
	X86_SIM_X86_JMP(0xe3a, 0xe56, x86_l_e56);
x86_l_e3c:
	/* 0xe3c: mov    QWORD PTR [rsp+0x88],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_e48:
	/* 0xe48: mov    QWORD PTR [rsp+0x80],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_e54:
	/* 0xe54: xor    edx,edx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_e56:
	/* 0xe56: mov    r12,QWORD PTR [rsp+0x50] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_e5b:
	/* 0xe5b: mov    r13,QWORD PTR [rsp+0x70] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_e60:
	/* 0xe60: mov    ebp,DWORD PTR [rsp+0x84] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132ULL);
x86_l_e67:
	/* 0xe67: sub    r13,r12 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R13, X86_R12, X86_WIDTH_64, X86_ALU_SUB, 0);
x86_l_e6a:
	/* 0xe6a: mov    r15d,DWORD PTR [rsp+0x78] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_e6f:
	/* 0xe6f: xor    esi,esi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_e71:
	/* 0xe71: mov    ecx,ebp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RBP, X86_WIDTH_32, 0, 0);
x86_l_e73:
	/* 0xe73: sub    ecx,r15d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_R15, X86_WIDTH_32, X86_ALU_SUB, 0);
x86_l_e76:
	/* 0xe76: mov    eax,0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 0ULL);
x86_l_e7b:
	/* 0xe7b: cmovb  ecx,eax */
	X86_SIM_RUN_OP(X86_OP_CMOV, X86_RCX, X86_RAX, X86_WIDTH_32, X86_CC_B, 0);
x86_l_e7e:
	/* 0xe7e: setb   sil */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_CC_B, 0);
x86_l_e82:
	/* 0xe82: mov    eax,ebp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RBP, X86_WIDTH_32, 0, 0);
x86_l_e84:
	/* 0xe84: cmova  eax,r15d */
	X86_SIM_RUN_OP(X86_OP_CMOV, X86_RAX, X86_R15, X86_WIDTH_32, X86_CC_A, 0);
x86_l_e88:
	/* 0xe88: add    esi,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 0);
x86_l_e8a:
	/* 0xe8a: mov    edi,r15d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_R15, X86_WIDTH_32, 0, 0);
x86_l_e8d:
	/* 0xe8d: sub    edi,esi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB, 0);
x86_l_e8f:
	/* 0xe8f: mov    DWORD PTR [rsp+0x78],edi */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_e93:
	/* 0xe93: sub    r13,rsi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R13, X86_RSI, X86_WIDTH_64, X86_ALU_SUB, 0);
x86_l_e96:
	/* 0xe96: jb     fa5 <generic_retkprobe_event+0xfa5> */
	X86_SIM_X86_JCC(X86_CC_B, 0xe96, 0xfa5, x86_l_fa5);
x86_l_e9c:
	/* 0xe9c: cmp    r13,0xfff */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, 0, 4095ULL);
x86_l_ea3:
	/* 0xea3: ja     fa5 <generic_retkprobe_event+0xfa5> */
	X86_SIM_X86_JCC(X86_CC_A, 0xea3, 0xfa5, x86_l_fa5);
x86_l_ea9:
	/* 0xea9: cmp    r15d,ebp */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_R15, X86_RBP, X86_WIDTH_32, 0, 0);
x86_l_eac:
	/* 0xeac: jbe    eb3 <generic_retkprobe_event+0xeb3> */
	X86_SIM_X86_JCC(X86_CC_BE, 0xeac, 0xeb3, x86_l_eb3);
x86_l_eae:
	/* 0xeae: mov    BYTE PTR [r12+r13*1],0x2f */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_R13, 0), 47ULL);
x86_l_eb3:
	/* 0xeb3: add    rdx,rcx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_eb6:
	/* 0xeb6: cmp    ebp,r15d */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RBP, X86_R15, X86_WIDTH_32, 0, 0);
x86_l_eb9:
	/* 0xeb9: movzx  esi,al */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_RSI, X86_RAX, X86_WIDTH_32, X86_WIDTH_8, 0);
x86_l_ebc:
	/* 0xebc: mov    rdi,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_ebf:
	/* 0xebf: adc    rdi,r13 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADC, 0);
x86_l_ec2:
	/* 0xec2: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_ec5:
	/* 0xec5: jns    f0d <generic_retkprobe_event+0xf0d> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xec5, 0xf0d, x86_l_f0d);
x86_l_ec7:
	/* 0xec7: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_eca:
	/* 0xeca: jns    f24 <generic_retkprobe_event+0xf24> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xeca, 0xf24, x86_l_f24);
x86_l_ecc:
	/* 0xecc: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_ece:
	/* 0xece: cmp    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_ed1:
	/* 0xed1: jb     eef <generic_retkprobe_event+0xeef> */
	X86_SIM_X86_JCC(X86_CC_B, 0xed1, 0xeef, x86_l_eef);
x86_l_ed3:
	/* 0xed3: mov    esi,esi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_ed5:
	/* 0xed5: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_ed7:
	/* 0xed7: mov    r8,rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R8, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_eda:
	/* 0xeda: mov    rcx,QWORD PTR [rdx+rcx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_ede:
	/* 0xede: mov    QWORD PTR [rdi+r8*1],rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R8, 0), 0ULL);
x86_l_ee2:
	/* 0xee2: lea    rcx,[r8+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RCX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ee6:
	/* 0xee6: add    r8,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_eea:
	/* 0xeea: cmp    r8,rsi */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_R8, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_eed:
	/* 0xeed: jbe    ed7 <generic_retkprobe_event+0xed7> */
	X86_SIM_X86_JCC(X86_CC_BE, 0xeed, 0xed7, x86_l_ed7);
x86_l_eef:
	/* 0xeef: test   al,0x4 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, 0, 4ULL);
x86_l_ef1:
	/* 0xef1: jne    f3c <generic_retkprobe_event+0xf3c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xef1, 0xf3c, x86_l_f3c);
x86_l_ef3:
	/* 0xef3: test   al,0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, 0, 2ULL);
x86_l_ef5:
	/* 0xef5: jne    f4d <generic_retkprobe_event+0xf4d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xef5, 0xf4d, x86_l_f4d);
x86_l_ef7:
	/* 0xef7: test   al,0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_ef9:
	/* 0xef9: jne    f60 <generic_retkprobe_event+0xf60> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xef9, 0xf60, x86_l_f60);
x86_l_efb:
	/* 0xefb: add    r12,r13 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R12, X86_R13, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_efe:
	/* 0xefe: mov    QWORD PTR [rsp+0x70],r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_f03:
	/* 0xf03: cmp    r15d,ebp */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_R15, X86_RBP, X86_WIDTH_32, 0, 0);
x86_l_f06:
	/* 0xf06: ja     f76 <generic_retkprobe_event+0xf76> */
	X86_SIM_X86_JCC(X86_CC_A, 0xf06, 0xf76, x86_l_f76);
x86_l_f08:
	/* 0xf08: jmp    fa5 <generic_retkprobe_event+0xfa5> */
	X86_SIM_X86_JMP(0xf08, 0xfa5, x86_l_fa5);
x86_l_f0d:
	/* 0xf0d: call   f12 <generic_retkprobe_event+0xf12> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_f12:
	/* 0xf12: add    r12,r13 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R12, X86_R13, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_f15:
	/* 0xf15: mov    QWORD PTR [rsp+0x70],r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_f1a:
	/* 0xf1a: cmp    r15d,ebp */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_R15, X86_RBP, X86_WIDTH_32, 0, 0);
x86_l_f1d:
	/* 0xf1d: ja     f76 <generic_retkprobe_event+0xf76> */
	X86_SIM_X86_JCC(X86_CC_A, 0xf1d, 0xf76, x86_l_f76);
x86_l_f1f:
	/* 0xf1f: jmp    fa5 <generic_retkprobe_event+0xfa5> */
	X86_SIM_X86_JMP(0xf1f, 0xfa5, x86_l_fa5);
x86_l_f24:
	/* 0xf24: mov    edx,esi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_f26:
	/* 0xf26: xor    esi,esi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_f28:
	/* 0xf28: call   47c5 <__native_link_local_memset_zero_dynamic> */
	X86_SIM_X86_CALL(x86_l_47c5, 0xf2dULL);
x86_l_f2d:
	/* 0xf2d: add    r12,r13 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R12, X86_R13, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_f30:
	/* 0xf30: mov    QWORD PTR [rsp+0x70],r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_f35:
	/* 0xf35: cmp    r15d,ebp */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_R15, X86_RBP, X86_WIDTH_32, 0, 0);
x86_l_f38:
	/* 0xf38: ja     f76 <generic_retkprobe_event+0xf76> */
	X86_SIM_X86_JCC(X86_CC_A, 0xf38, 0xf76, x86_l_f76);
x86_l_f3a:
	/* 0xf3a: jmp    fa5 <generic_retkprobe_event+0xfa5> */
	X86_SIM_X86_JMP(0xf3a, 0xfa5, x86_l_fa5);
x86_l_f3c:
	/* 0xf3c: mov    esi,ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_f3e:
	/* 0xf3e: mov    r8d,DWORD PTR [rdx+rsi*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R8, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_f42:
	/* 0xf42: mov    DWORD PTR [rdi+rsi*1],r8d */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_f46:
	/* 0xf46: or     ecx,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_OR, 4ULL);
x86_l_f49:
	/* 0xf49: test   al,0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, 0, 2ULL);
x86_l_f4b:
	/* 0xf4b: je     ef7 <generic_retkprobe_event+0xef7> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf4b, 0xef7, x86_l_ef7);
x86_l_f4d:
	/* 0xf4d: mov    esi,ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_f4f:
	/* 0xf4f: movzx  r8d,WORD PTR [rdx+rsi*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R8, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_16), 0ULL);
x86_l_f54:
	/* 0xf54: mov    WORD PTR [rdi+rsi*1],r8w */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_R8, X86_WIDTH_16, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_f59:
	/* 0xf59: add    ecx,0x2 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_f5c:
	/* 0xf5c: test   al,0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_f5e:
	/* 0xf5e: je     efb <generic_retkprobe_event+0xefb> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf5e, 0xefb, x86_l_efb);
x86_l_f60:
	/* 0xf60: mov    eax,ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_f62:
	/* 0xf62: movzx  ecx,BYTE PTR [rdx+rax*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_f66:
	/* 0xf66: mov    BYTE PTR [rdi+rax*1],cl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_f69:
	/* 0xf69: add    r12,r13 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R12, X86_R13, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_f6c:
	/* 0xf6c: mov    QWORD PTR [rsp+0x70],r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_f71:
	/* 0xf71: cmp    r15d,ebp */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_R15, X86_RBP, X86_WIDTH_32, 0, 0);
x86_l_f74:
	/* 0xf74: jbe    fa5 <generic_retkprobe_event+0xfa5> */
	X86_SIM_X86_JCC(X86_CC_BE, 0xf74, 0xfa5, x86_l_fa5);
x86_l_f76:
	/* 0xf76: mov    rax,QWORD PTR [rsp+0xc8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_f7e:
	/* 0xf7e: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_f83:
	/* 0xf83: mov    r13d,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_f89:
	/* 0xf89: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_f8e:
	/* 0xf8e: inc    r14d */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_f91:
	/* 0xf91: cmp    r14d,0x800 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, 0, 2048ULL);
x86_l_f98:
	/* 0xf98: jne    c84 <generic_retkprobe_event+0xc84> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xf98, 0xc84, x86_l_c84);
x86_l_f9e:
	/* 0xf9e: jmp    fbd <generic_retkprobe_event+0xfbd> */
	X86_SIM_X86_JMP(0xf9e, 0xfbd, x86_l_fbd);
x86_l_fa0:
	/* 0xfa0: mov    BYTE PTR [rsp+0x7c],0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 532575944705ULL);
x86_l_fa5:
	/* 0xfa5: mov    r13d,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_fab:
	/* 0xfab: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_fb0:
	/* 0xfb0: jmp    fbd <generic_retkprobe_event+0xfbd> */
	X86_SIM_X86_JMP(0xfb0, 0xfbd, x86_l_fbd);
x86_l_fb2:
	/* 0xfb2: mov    BYTE PTR [rsp+0x7c],0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 532575944705ULL);
x86_l_fb7:
	/* 0xfb7: mov    r13d,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_fbd:
	/* 0xfbd: mov    rcx,QWORD PTR [rsp+0x70] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_fc2:
	/* 0xfc2: xor    ebp,ebp */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_fc4:
	/* 0xfc4: cmp    rcx,r15 */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RCX, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_fc7:
	/* 0xfc7: je     ff8 <generic_retkprobe_event+0xff8> */
	X86_SIM_X86_JCC(X86_CC_E, 0xfc7, 0xff8, x86_l_ff8);
x86_l_fc9:
	/* 0xfc9: cmp    BYTE PTR [rsp+0x7c],0x0 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 532575944704ULL);
x86_l_fce:
	/* 0xfce: sete   dl */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_CC_E, 0);
x86_l_fd1:
	/* 0xfd1: mov    esi,DWORD PTR [rsp+0x78] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_fd5:
	/* 0xfd5: mov    eax,0x1000 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 4096ULL);
x86_l_fda:
	/* 0xfda: sub    eax,esi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_SUB, 0);
x86_l_fdc:
	/* 0xfdc: test   esi,esi */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_fde:
	/* 0xfde: cmovle eax,esi */
	X86_SIM_RUN_OP(X86_OP_CMOV, X86_RAX, X86_RSI, X86_WIDTH_32, X86_CC_LE, 0);
x86_l_fe1:
	/* 0xfe1: test   rcx,rcx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_fe4:
	/* 0xfe4: mov    r14,QWORD PTR [rsp] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fe8:
	/* 0xfe8: je     1087 <generic_retkprobe_event+0x1087> */
	X86_SIM_X86_JCC(X86_CC_E, 0xfe8, 0x1087, x86_l_1087);
x86_l_fee:
	/* 0xfee: mov    bpl,dl */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RBP, X86_RDX, X86_WIDTH_8, 0, 0);
x86_l_ff1:
	/* 0xff1: add    ebp,ebp */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_ADD, 0);
x86_l_ff3:
	/* 0xff3: mov    r15,rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R15, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_ff6:
	/* 0xff6: jmp    ffe <generic_retkprobe_event+0xffe> */
	X86_SIM_X86_JMP(0xff6, 0xffe, x86_l_ffe);
x86_l_ff8:
	/* 0xff8: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_ffa:
	/* 0xffa: mov    r14,QWORD PTR [rsp] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ffe:
	/* 0xffe: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1003:
	/* 0x1003: add    rdi,0xa0 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 160ULL);
x86_l_100a:
	/* 0x100a: mov    r12d,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R12, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_100d:
	/* 0x100d: and    r12d,0xfff */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1014:
	/* 0x1014: test   r15,r15 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_1017:
	/* 0x1017: jns    107a <generic_retkprobe_event+0x107a> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1017, 0x107a, x86_l_107a);
x86_l_1019:
	/* 0x1019: test   r15,r15 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_101c:
	/* 0x101c: jns    1094 <generic_retkprobe_event+0x1094> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x101c, 0x1094, x86_l_1094);
x86_l_101e:
	/* 0x101e: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1020:
	/* 0x1020: cmp    r12d,0x8 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_1024:
	/* 0x1024: mov    r8,QWORD PTR [rsp+0x98] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_102c:
	/* 0x102c: jb     104b <generic_retkprobe_event+0x104b> */
	X86_SIM_X86_JCC(X86_CC_B, 0x102c, 0x104b, x86_l_104b);
x86_l_102e:
	/* 0x102e: mov    edx,r12d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R12, X86_WIDTH_32, 0, 0);
x86_l_1031:
	/* 0x1031: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1033:
	/* 0x1033: mov    rsi,rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_1036:
	/* 0x1036: mov    rcx,QWORD PTR [r15+rcx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_103a:
	/* 0x103a: mov    QWORD PTR [rdi+rsi*1],rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_103e:
	/* 0x103e: lea    rcx,[rsi+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1042:
	/* 0x1042: add    rsi,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1046:
	/* 0x1046: cmp    rsi,rdx */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_1049:
	/* 0x1049: jbe    1033 <generic_retkprobe_event+0x1033> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x1049, 0x1033, x86_l_1033);
x86_l_104b:
	/* 0x104b: test   al,0x4 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, 0, 4ULL);
x86_l_104d:
	/* 0x104d: jne    10ef <generic_retkprobe_event+0x10ef> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x104d, 0x10ef, x86_l_10ef);
x86_l_1053:
	/* 0x1053: test   al,0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, 0, 2ULL);
x86_l_1055:
	/* 0x1055: jne    1103 <generic_retkprobe_event+0x1103> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1055, 0x1103, x86_l_1103);
x86_l_105b:
	/* 0x105b: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1060:
	/* 0x1060: mov    rsi,QWORD PTR [rsp+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1065:
	/* 0x1065: test   al,0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_1067:
	/* 0x1067: jne    1123 <generic_retkprobe_event+0x1123> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1067, 0x1123, x86_l_1123);
x86_l_106d:
	/* 0x106d: mov    DWORD PTR [rsi],r12d */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1070:
	/* 0x1070: test   r8,r8 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R8, X86_R8, X86_WIDTH_64, 0, 0);
x86_l_1073:
	/* 0x1073: jns    10b8 <generic_retkprobe_event+0x10b8> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1073, 0x10b8, x86_l_10b8);
x86_l_1075:
	/* 0x1075: mov    rax,QWORD PTR [r8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1078:
	/* 0x1078: jmp    10ba <generic_retkprobe_event+0x10ba> */
	X86_SIM_X86_JMP(0x1078, 0x10ba, x86_l_10ba);
x86_l_107a:
	/* 0x107a: mov    esi,r12d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_R12, X86_WIDTH_32, 0, 0);
x86_l_107d:
	/* 0x107d: mov    rdx,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_1080:
	/* 0x1080: call   1085 <generic_retkprobe_event+0x1085> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_1085:
	/* 0x1085: jmp    109e <generic_retkprobe_event+0x109e> */
	X86_SIM_X86_JMP(0x1085, 0x109e, x86_l_109e);
x86_l_1087:
	/* 0x1087: xor    r12d,r12d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_108a:
	/* 0x108a: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_108f:
	/* 0x108f: jmp    3d42 <generic_retkprobe_event+0x3d42> */
	X86_SIM_X86_JMP(0x108f, 0x3d42, x86_l_3d42);
x86_l_1094:
	/* 0x1094: mov    edx,r12d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R12, X86_WIDTH_32, 0, 0);
x86_l_1097:
	/* 0x1097: xor    esi,esi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1099:
	/* 0x1099: call   47c5 <__native_link_local_memset_zero_dynamic> */
	X86_SIM_X86_CALL(x86_l_47c5, 0x109eULL);
x86_l_109e:
	/* 0x109e: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_10a3:
	/* 0x10a3: mov    rsi,QWORD PTR [rsp+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_10a8:
	/* 0x10a8: mov    r8,QWORD PTR [rsp+0x98] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_10b0:
	/* 0x10b0: mov    DWORD PTR [rsi],r12d */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10b3:
	/* 0x10b3: test   r8,r8 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R8, X86_R8, X86_WIDTH_64, 0, 0);
x86_l_10b6:
	/* 0x10b6: js     1075 <generic_retkprobe_event+0x1075> */
	X86_SIM_X86_JCC(X86_CC_S, 0x10b6, 0x1075, x86_l_1075);
x86_l_10b8:
	/* 0x10b8: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_10ba:
	/* 0x10ba: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10bf:
	/* 0x10bf: add    rax,0x30 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_10c3:
	/* 0x10c3: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_10c6:
	/* 0x10c6: jns    10cd <generic_retkprobe_event+0x10cd> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x10c6, 0x10cd, x86_l_10cd);
x86_l_10c8:
	/* 0x10c8: mov    rax,QWORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10cb:
	/* 0x10cb: jmp    10cf <generic_retkprobe_event+0x10cf> */
	X86_SIM_X86_JMP(0x10cb, 0x10cf, x86_l_10cf);
x86_l_10cd:
	/* 0x10cd: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_10cf:
	/* 0x10cf: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_10d2:
	/* 0x10d2: jns    10d9 <generic_retkprobe_event+0x10d9> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x10d2, 0x10d9, x86_l_10d9);
x86_l_10d4:
	/* 0x10d4: movzx  eax,WORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_10d7:
	/* 0x10d7: jmp    10db <generic_retkprobe_event+0x10db> */
	X86_SIM_X86_JMP(0x10d7, 0x10db, x86_l_10db);
x86_l_10d9:
	/* 0x10d9: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_10db:
	/* 0x10db: mov    DWORD PTR [rsi+r12*1+0x4],ebp */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSI, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 4ULL);
x86_l_10e0:
	/* 0x10e0: mov    WORD PTR [rsi+r12*1+0x8],ax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 8ULL);
x86_l_10e6:
	/* 0x10e6: add    r12d,0xa */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 10ULL);
x86_l_10ea:
	/* 0x10ea: jmp    3d3d <generic_retkprobe_event+0x3d3d> */
	X86_SIM_X86_JMP(0x10ea, 0x3d3d, x86_l_3d3d);
x86_l_10ef:
	/* 0x10ef: mov    edx,ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_10f1:
	/* 0x10f1: mov    esi,DWORD PTR [r15+rdx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_10f5:
	/* 0x10f5: mov    DWORD PTR [rdi+rdx*1],esi */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_10f8:
	/* 0x10f8: or     ecx,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_OR, 4ULL);
x86_l_10fb:
	/* 0x10fb: test   al,0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, 0, 2ULL);
x86_l_10fd:
	/* 0x10fd: je     105b <generic_retkprobe_event+0x105b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10fd, 0x105b, x86_l_105b);
x86_l_1103:
	/* 0x1103: mov    edx,ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_1105:
	/* 0x1105: movzx  esi,WORD PTR [r15+rdx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RDX, 0, X86_WIDTH_16), 0ULL);
x86_l_110a:
	/* 0x110a: mov    WORD PTR [rdi+rdx*1],si */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RSI, X86_WIDTH_16, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_110e:
	/* 0x110e: add    ecx,0x2 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_1111:
	/* 0x1111: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1116:
	/* 0x1116: mov    rsi,QWORD PTR [rsp+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_111b:
	/* 0x111b: test   al,0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_111d:
	/* 0x111d: je     106d <generic_retkprobe_event+0x106d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x111d, 0x106d, x86_l_106d);
x86_l_1123:
	/* 0x1123: mov    eax,ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_1125:
	/* 0x1125: movzx  ecx,BYTE PTR [r15+rax*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_112a:
	/* 0x112a: mov    BYTE PTR [rdi+rax*1],cl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_112d:
	/* 0x112d: mov    DWORD PTR [rsi],r12d */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1130:
	/* 0x1130: test   r8,r8 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R8, X86_R8, X86_WIDTH_64, 0, 0);
x86_l_1133:
	/* 0x1133: js     1075 <generic_retkprobe_event+0x1075> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1133, 0x1075, x86_l_1075);
x86_l_1139:
	/* 0x1139: jmp    10b8 <generic_retkprobe_event+0x10b8> */
	X86_SIM_X86_JMP(0x1139, 0x10b8, x86_l_10b8);
x86_l_113e:
	/* 0x113e: mov    ecx,0xfffffffe */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 4294967294ULL);
x86_l_1143:
	/* 0x1143: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_1146:
	/* 0x1146: jns    1178 <generic_retkprobe_event+0x1178> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1146, 0x1178, x86_l_1178);
x86_l_1148:
	/* 0x1148: mov    rax,QWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_114b:
	/* 0x114b: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1150:
	/* 0x1150: mov    r13,QWORD PTR [rdx+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R13, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1154:
	/* 0x1154: mov    QWORD PTR [rsp+0x48],r13 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1159:
	/* 0x1159: cmp    r13,r9 */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_R13, X86_R9, X86_WIDTH_64, 0, 0);
x86_l_115c:
	/* 0x115c: mov    r14,r9 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R14, X86_R9, X86_WIDTH_64, 0, 0);
x86_l_115f:
	/* 0x115f: cmovb  r14,r13 */
	X86_SIM_RUN_OP(X86_OP_CMOV, X86_R14, X86_R13, X86_WIDTH_64, X86_CC_B, 0);
x86_l_1163:
	/* 0x1163: test   r9,r9 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R9, X86_R9, X86_WIDTH_64, 0, 0);
x86_l_1166:
	/* 0x1166: cmovne r13,r14 */
	X86_SIM_RUN_OP(X86_OP_CMOV, X86_R13, X86_R14, X86_WIDTH_64, X86_CC_NE, 0);
x86_l_116a:
	/* 0x116a: mov    ecx,0xfffffffd */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 4294967293ULL);
x86_l_116f:
	/* 0x116f: cmp    r13,0xffe */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, 0, 4094ULL);
x86_l_1176:
	/* 0x1176: jbe    1185 <generic_retkprobe_event+0x1185> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x1176, 0x1185, x86_l_1185);
x86_l_1178:
	/* 0x1178: mov    rax,QWORD PTR [rsp] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_117c:
	/* 0x117c: mov    DWORD PTR [rax+r8*1],ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R8, 0), 0ULL);
x86_l_1180:
	/* 0x1180: jmp    405 <generic_retkprobe_event+0x405> */
	X86_SIM_X86_JMP(0x1180, 0x405, x86_l_405);
x86_l_1185:
	/* 0x1185: mov    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_118a:
	/* 0x118a: add    rdi,rbp */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_118d:
	/* 0x118d: mov    QWORD PTR [rsp+0x28],rdi */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1192:
	/* 0x1192: and    edi,0x3fff */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_1198:
	/* 0x1198: add    rdi,QWORD PTR [rsp] */
	X86_SIM_RUN_OP(X86_OP_ALU_MEM, X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_119c:
	/* 0x119c: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_11a1:
	/* 0x11a1: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_11a4:
	/* 0x11a4: jns    12af <generic_retkprobe_event+0x12af> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x11a4, 0x12af, x86_l_12af);
x86_l_11aa:
	/* 0x11aa: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_11ad:
	/* 0x11ad: jns    179e <generic_retkprobe_event+0x179e> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x11ad, 0x179e, x86_l_179e);
x86_l_11b3:
	/* 0x11b3: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_11b5:
	/* 0x11b5: cmp    r13d,0x8 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_11b9:
	/* 0x11b9: jb     11d4 <generic_retkprobe_event+0x11d4> */
	X86_SIM_X86_JCC(X86_CC_B, 0x11b9, 0x11d4, x86_l_11d4);
x86_l_11bb:
	/* 0x11bb: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_11bd:
	/* 0x11bd: mov    eax,ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_11bf:
	/* 0x11bf: mov    rsi,QWORD PTR [rdx+rax*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_11c3:
	/* 0x11c3: mov    QWORD PTR [rdi+rax*1],rsi */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_11c7:
	/* 0x11c7: lea    eax,[rcx+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11ca:
	/* 0x11ca: add    ecx,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 16ULL);
x86_l_11cd:
	/* 0x11cd: cmp    ecx,r13d */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RCX, X86_R13, X86_WIDTH_32, 0, 0);
x86_l_11d0:
	/* 0x11d0: mov    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_11d2:
	/* 0x11d2: jbe    11bd <generic_retkprobe_event+0x11bd> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x11d2, 0x11bd, x86_l_11bd);
x86_l_11d4:
	/* 0x11d4: test   r13b,0x4 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, 0, 4ULL);
x86_l_11d8:
	/* 0x11d8: jne    1b70 <generic_retkprobe_event+0x1b70> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x11d8, 0x1b70, x86_l_1b70);
x86_l_11de:
	/* 0x11de: test   r13b,0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, 0, 2ULL);
x86_l_11e2:
	/* 0x11e2: jne    1b85 <generic_retkprobe_event+0x1b85> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x11e2, 0x1b85, x86_l_1b85);
x86_l_11e8:
	/* 0x11e8: test   r13b,0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_11ec:
	/* 0x11ec: jne    1b9c <generic_retkprobe_event+0x1b9c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x11ec, 0x1b9c, x86_l_1b9c);
x86_l_11f2:
	/* 0x11f2: add    rbp,r13 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_11f5:
	/* 0x11f5: test   r9,r9 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R9, X86_R9, X86_WIDTH_64, 0, 0);
x86_l_11f8:
	/* 0x11f8: je     12dc <generic_retkprobe_event+0x12dc> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11f8, 0x12dc, x86_l_12dc);
x86_l_11fe:
	/* 0x11fe: sub    r9,r14 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_R14, X86_WIDTH_64, X86_ALU_SUB, 0);
x86_l_1201:
	/* 0x1201: jne    12df <generic_retkprobe_event+0x12df> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1201, 0x12df, x86_l_12df);
x86_l_1207:
	/* 0x1207: jmp    133b <generic_retkprobe_event+0x133b> */
	X86_SIM_X86_JMP(0x1207, 0x133b, x86_l_133b);
x86_l_120c:
	/* 0x120c: lea    rax,[rsp+0x20] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1211:
	/* 0x1211: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_1214:
	/* 0x1214: jns    132a <generic_retkprobe_event+0x132a> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1214, 0x132a, x86_l_132a);
x86_l_121a:
	/* 0x121a: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_121d:
	/* 0x121d: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1222:
	/* 0x1222: jns    17b8 <generic_retkprobe_event+0x17b8> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1222, 0x17b8, x86_l_17b8);
x86_l_1228:
	/* 0x1228: mov    eax,DWORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_122a:
	/* 0x122a: mov    DWORD PTR [rcx],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_122c:
	/* 0x122c: mov    r12d,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_1232:
	/* 0x1232: jmp    3d33 <generic_retkprobe_event+0x3d33> */
	X86_SIM_X86_JMP(0x1232, 0x3d33, x86_l_3d33);
x86_l_1237:
	/* 0x1237: lea    rax,[rsp+0x20] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_123c:
	/* 0x123c: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_123f:
	/* 0x123f: jns    135c <generic_retkprobe_event+0x135c> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x123f, 0x135c, x86_l_135c);
x86_l_1245:
	/* 0x1245: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_1248:
	/* 0x1248: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_124d:
	/* 0x124d: jns    1abb <generic_retkprobe_event+0x1abb> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x124d, 0x1abb, x86_l_1abb);
x86_l_1253:
	/* 0x1253: movzx  eax,WORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1256:
	/* 0x1256: mov    WORD PTR [rcx],ax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1259:
	/* 0x1259: mov    r12d,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_125f:
	/* 0x125f: jmp    3d33 <generic_retkprobe_event+0x3d33> */
	X86_SIM_X86_JMP(0x125f, 0x3d33, x86_l_3d33);
x86_l_1264:
	/* 0x1264: lea    rdx,[rsp+0x20] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1269:
	/* 0x1269: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_126e:
	/* 0x126e: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_1273:
	/* 0x1273: call   1278 <generic_retkprobe_event+0x1278> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_1278:
	/* 0x1278: mov    r12d,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_127e:
	/* 0x127e: jmp    3d33 <generic_retkprobe_event+0x3d33> */
	X86_SIM_X86_JMP(0x127e, 0x3d33, x86_l_3d33);
x86_l_1283:
	/* 0x1283: lea    rax,[rsp+0x20] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1288:
	/* 0x1288: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_128b:
	/* 0x128b: jns    137f <generic_retkprobe_event+0x137f> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x128b, 0x137f, x86_l_137f);
x86_l_1291:
	/* 0x1291: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_1294:
	/* 0x1294: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1299:
	/* 0x1299: jns    1acb <generic_retkprobe_event+0x1acb> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1299, 0x1acb, x86_l_1acb);
x86_l_129f:
	/* 0x129f: movzx  eax,BYTE PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_12a2:
	/* 0x12a2: mov    BYTE PTR [rcx],al */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12a4:
	/* 0x12a4: mov    r12d,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_12aa:
	/* 0x12aa: jmp    3d33 <generic_retkprobe_event+0x3d33> */
	X86_SIM_X86_JMP(0x12aa, 0x3d33, x86_l_3d33);
x86_l_12af:
	/* 0x12af: mov    esi,r13d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_R13, X86_WIDTH_32, 0, 0);
x86_l_12b2:
	/* 0x12b2: mov    r12,r8 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R12, X86_R8, X86_WIDTH_64, 0, 0);
x86_l_12b5:
	/* 0x12b5: mov    r15,r9 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R15, X86_R9, X86_WIDTH_64, 0, 0);
x86_l_12b8:
	/* 0x12b8: call   12bd <generic_retkprobe_event+0x12bd> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_12bd:
	/* 0x12bd: mov    r8,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R8, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_12c0:
	/* 0x12c0: mov    ecx,0xfffffffe */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 4294967294ULL);
x86_l_12c5:
	/* 0x12c5: test   eax,eax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_12c7:
	/* 0x12c7: js     1178 <generic_retkprobe_event+0x1178> */
	X86_SIM_X86_JCC(X86_CC_S, 0x12c7, 0x1178, x86_l_1178);
x86_l_12cd:
	/* 0x12cd: mov    r9,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R9, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_12d0:
	/* 0x12d0: add    rbp,r13 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_12d3:
	/* 0x12d3: test   r9,r9 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R9, X86_R9, X86_WIDTH_64, 0, 0);
x86_l_12d6:
	/* 0x12d6: jne    11fe <generic_retkprobe_event+0x11fe> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x12d6, 0x11fe, x86_l_11fe);
x86_l_12dc:
	/* 0x12dc: xor    r9d,r9d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_R9, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_12df:
	/* 0x12df: cmp    QWORD PTR [rsp+0xb0],0x3 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244099ULL);
x86_l_12e8:
	/* 0x12e8: jb     133b <generic_retkprobe_event+0x133b> */
	X86_SIM_X86_JCC(X86_CC_B, 0x12e8, 0x133b, x86_l_133b);
x86_l_12ea:
	/* 0x12ea: mov    r15,rbp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R15, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_12ed:
	/* 0x12ed: mov    r12,r9 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R12, X86_R9, X86_WIDTH_64, 0, 0);
x86_l_12f0:
	/* 0x12f0: mov    QWORD PTR [rsp+0x30],r8 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_12f5:
	/* 0x12f5: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_12fa:
	/* 0x12fa: add    rdx,0x20 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_12fe:
	/* 0x12fe: js     2023 <generic_retkprobe_event+0x2023> */
	X86_SIM_X86_JCC(X86_CC_S, 0x12fe, 0x2023, x86_l_2023);
x86_l_1304:
	/* 0x1304: lea    rdi,[rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1309:
	/* 0x1309: mov    esi,0x10 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 16ULL);
x86_l_130e:
	/* 0x130e: call   1313 <generic_retkprobe_event+0x1313> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_1313:
	/* 0x1313: mov    ecx,0xfffffffe */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 4294967294ULL);
x86_l_1318:
	/* 0x1318: test   eax,eax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_131a:
	/* 0x131a: js     3c7e <generic_retkprobe_event+0x3c7e> */
	X86_SIM_X86_JCC(X86_CC_S, 0x131a, 0x3c7e, x86_l_3c7e);
x86_l_1320:
	/* 0x1320: mov    rbp,QWORD PTR [rsp+0x48] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1325:
	/* 0x1325: jmp    2042 <generic_retkprobe_event+0x2042> */
	X86_SIM_X86_JMP(0x1325, 0x2042, x86_l_2042);
x86_l_132a:
	/* 0x132a: lea    rdx,[rsp+0x20] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_132f:
	/* 0x132f: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1334:
	/* 0x1334: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_1339:
	/* 0x1339: jmp    138e <generic_retkprobe_event+0x138e> */
	X86_SIM_X86_JMP(0x1339, 0x138e, x86_l_138e);
x86_l_133b:
	/* 0x133b: mov    r13,rbp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R13, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_133e:
	/* 0x133e: mov    r14,QWORD PTR [rsp] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1342:
	/* 0x1342: jmp    3b5 <generic_retkprobe_event+0x3b5> */
	X86_SIM_X86_JMP(0x1342, 0x3b5, x86_l_3b5);
x86_l_1347:
	/* 0x1347: test   rbp,rbp */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_134a:
	/* 0x134a: jns    1aa0 <generic_retkprobe_event+0x1aa0> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x134a, 0x1aa0, x86_l_1aa0);
x86_l_1350:
	/* 0x1350: mov    rax,QWORD PTR [rbp+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1354:
	/* 0x1354: mov    QWORD PTR [rdi],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1357:
	/* 0x1357: jmp    1aa7 <generic_retkprobe_event+0x1aa7> */
	X86_SIM_X86_JMP(0x1357, 0x1aa7, x86_l_1aa7);
x86_l_135c:
	/* 0x135c: lea    rdx,[rsp+0x20] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1361:
	/* 0x1361: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1366:
	/* 0x1366: mov    esi,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_136b:
	/* 0x136b: jmp    138e <generic_retkprobe_event+0x138e> */
	X86_SIM_X86_JMP(0x136b, 0x138e, x86_l_138e);
x86_l_136d:
	/* 0x136d: mov    QWORD PTR [rcx],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1374:
	/* 0x1374: mov    r12d,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_137a:
	/* 0x137a: jmp    3d33 <generic_retkprobe_event+0x3d33> */
	X86_SIM_X86_JMP(0x137a, 0x3d33, x86_l_3d33);
x86_l_137f:
	/* 0x137f: lea    rdx,[rsp+0x20] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1384:
	/* 0x1384: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1389:
	/* 0x1389: mov    esi,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_138e:
	/* 0x138e: call   1393 <generic_retkprobe_event+0x1393> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_1393:
	/* 0x1393: mov    r12d,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_1399:
	/* 0x1399: jmp    3d33 <generic_retkprobe_event+0x3d33> */
	X86_SIM_X86_JMP(0x1399, 0x3d33, x86_l_3d33);
x86_l_139e:
	/* 0x139e: mov    r12,QWORD PTR [rsp+0x20] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_13a3:
	/* 0x13a3: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_13a8:
	/* 0x13a8: mov    QWORD PTR [rdi+0x10],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_13b0:
	/* 0x13b0: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_13b8:
	/* 0x13b8: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13bf:
	/* 0x13bf: test   r12,r12 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_13c2:
	/* 0x13c2: js     1bb6 <generic_retkprobe_event+0x1bb6> */
	X86_SIM_X86_JCC(X86_CC_S, 0x13c2, 0x1bb6, x86_l_1bb6);
x86_l_13c8:
	/* 0x13c8: mov    r15,rdi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R15, X86_RDI, X86_WIDTH_64, 0, 0);
x86_l_13cb:
	/* 0x13cb: mov    esi,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_13d0:
	/* 0x13d0: mov    rdx,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_13d3:
	/* 0x13d3: call   13d8 <generic_retkprobe_event+0x13d8> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_13d8:
	/* 0x13d8: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_13db:
	/* 0x13db: js     3be8 <generic_retkprobe_event+0x3be8> */
	X86_SIM_X86_JCC(X86_CC_S, 0x13db, 0x3be8, x86_l_3be8);
x86_l_13e1:
	/* 0x13e1: movzx  eax,WORD PTR [r15] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_13e5:
	/* 0x13e5: jmp    1bcd <generic_retkprobe_event+0x1bcd> */
	X86_SIM_X86_JMP(0x13e5, 0x1bcd, x86_l_1bcd);
x86_l_13ea:
	/* 0x13ea: mov    rbp,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RBP, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_13ed:
	/* 0x13ed: mov    r12,QWORD PTR [rsp+0x20] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_13f2:
	/* 0x13f2: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_13f7:
	/* 0x13f7: mov    QWORD PTR [rax+0xc4],r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_13fe:
	/* 0x13fe: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1403:
	/* 0x1403: lea    rdi,[rcx+0xc2] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 194ULL);
x86_l_140a:
	/* 0x140a: mov    rdx,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_140d:
	/* 0x140d: add    rdx,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1411:
	/* 0x1411: jns    1ad9 <generic_retkprobe_event+0x1ad9> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1411, 0x1ad9, x86_l_1ad9);
x86_l_1417:
	/* 0x1417: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_141a:
	/* 0x141a: jns    20d3 <generic_retkprobe_event+0x20d3> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x141a, 0x20d3, x86_l_20d3);
x86_l_1420:
	/* 0x1420: movzx  eax,WORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1423:
	/* 0x1423: mov    WORD PTR [rdi],ax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1426:
	/* 0x1426: jmp    20d8 <generic_retkprobe_event+0x20d8> */
	X86_SIM_X86_JMP(0x1426, 0x20d8, x86_l_20d8);
x86_l_142b:
	/* 0x142b: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1430:
	/* 0x1430: movzx  edx,ax */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_RDX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_1433:
	/* 0x1433: shr    eax,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1436:
	/* 0x1436: and    eax,0xfff */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_143b:
	/* 0x143b: add    QWORD PTR [rsp+0x10],0xa0 */
	X86_SIM_RUN_OP(X86_OP_ALU_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 68719476896ULL);
x86_l_1444:
	/* 0x1444: lea    esi,[rax+0x1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_1447:
	/* 0x1447: add    rdx,QWORD PTR [rsp+0xf0] */
	X86_SIM_RUN_OP(X86_OP_ALU_MEM, X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 240ULL);
x86_l_144f:
	/* 0x144f: jns    1aed <generic_retkprobe_event+0x1aed> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x144f, 0x1aed, x86_l_1aed);
x86_l_1455:
	/* 0x1455: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_1458:
	/* 0x1458: jns    227c <generic_retkprobe_event+0x227c> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1458, 0x227c, x86_l_227c);
x86_l_145e:
	/* 0x145e: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1460:
	/* 0x1460: mov    r8,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1465:
	/* 0x1465: cmp    rax,rcx */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RAX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_1468:
	/* 0x1468: je     3060 <generic_retkprobe_event+0x3060> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1468, 0x3060, x86_l_3060);
x86_l_146e:
	/* 0x146e: lea    r12,[rcx+0x1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R12, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_1472:
	/* 0x1472: movzx  edi,BYTE PTR [rdx+rcx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1476:
	/* 0x1476: mov    BYTE PTR [r8+rcx*1],dil */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_R8, X86_RDI, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_147a:
	/* 0x147a: mov    rcx,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_147d:
	/* 0x147d: test   dil,dil */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_8, 0, 0);
x86_l_1480:
	/* 0x1480: jne    1465 <generic_retkprobe_event+0x1465> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1480, 0x1465, x86_l_1465);
x86_l_1482:
	/* 0x1482: jmp    260c <generic_retkprobe_event+0x260c> */
	X86_SIM_X86_JMP(0x1482, 0x260c, x86_l_260c);
x86_l_1487:
	/* 0x1487: lea    rax,[rsp+0x20] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_148c:
	/* 0x148c: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_148f:
	/* 0x148f: jns    1af7 <generic_retkprobe_event+0x1af7> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x148f, 0x1af7, x86_l_1af7);
x86_l_1495:
	/* 0x1495: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_1498:
	/* 0x1498: jns    2288 <generic_retkprobe_event+0x2288> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1498, 0x2288, x86_l_2288);
x86_l_149e:
	/* 0x149e: mov    rdx,QWORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14a1:
	/* 0x14a1: mov    QWORD PTR [rsp+0x40],rdx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_14a6:
	/* 0x14a6: jmp    1b10 <generic_retkprobe_event+0x1b10> */
	X86_SIM_X86_JMP(0x14a6, 0x1b10, x86_l_1b10);
x86_l_14ab:
	/* 0x14ab: mov    r14,QWORD PTR [rsp+0x20] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_14b0:
	/* 0x14b0: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_14b5:
	/* 0x14b5: lea    rdi,[rcx+0xc4] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_14bc:
	/* 0x14bc: mov    rdx,r14 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_14bf:
	/* 0x14bf: add    rdx,0x98 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 152ULL);
x86_l_14c6:
	/* 0x14c6: jns    1b2f <generic_retkprobe_event+0x1b2f> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x14c6, 0x1b2f, x86_l_1b2f);
x86_l_14cc:
	/* 0x14cc: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_14cf:
	/* 0x14cf: jns    22a7 <generic_retkprobe_event+0x22a7> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x14cf, 0x22a7, x86_l_22a7);
x86_l_14d5:
	/* 0x14d5: mov    eax,DWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14d7:
	/* 0x14d7: mov    DWORD PTR [rdi],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14d9:
	/* 0x14d9: jmp    22ad <generic_retkprobe_event+0x22ad> */
	X86_SIM_X86_JMP(0x14d9, 0x22ad, x86_l_22ad);
x86_l_14de:
	/* 0x14de: mov    r12,QWORD PTR [rsp+0x20] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_14e3:
	/* 0x14e3: mov    BYTE PTR [rsp+0x40],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_14e8:
	/* 0x14e8: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_14ed:
	/* 0x14ed: mov    QWORD PTR [rdi+0x68],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_14f5:
	/* 0x14f5: mov    QWORD PTR [rdi+0x60],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_14fd:
	/* 0x14fd: mov    QWORD PTR [rdi+0x58],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_1505:
	/* 0x1505: mov    QWORD PTR [rdi+0x50],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_150d:
	/* 0x150d: mov    QWORD PTR [rdi+0x48],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1515:
	/* 0x1515: mov    QWORD PTR [rdi+0x40],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_151d:
	/* 0x151d: mov    QWORD PTR [rdi+0x38],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1525:
	/* 0x1525: mov    QWORD PTR [rdi+0x30],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_152d:
	/* 0x152d: mov    QWORD PTR [rdi+0x28],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1535:
	/* 0x1535: mov    QWORD PTR [rdi+0x20],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_153d:
	/* 0x153d: mov    QWORD PTR [rdi+0x18],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1545:
	/* 0x1545: mov    QWORD PTR [rdi+0x10],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_154d:
	/* 0x154d: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1555:
	/* 0x1555: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_155c:
	/* 0x155c: test   r12,r12 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_155f:
	/* 0x155f: js     1c04 <generic_retkprobe_event+0x1c04> */
	X86_SIM_X86_JCC(X86_CC_S, 0x155f, 0x1c04, x86_l_1c04);
x86_l_1565:
	/* 0x1565: mov    esi,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_156a:
	/* 0x156a: mov    rdx,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_156d:
	/* 0x156d: call   1572 <generic_retkprobe_event+0x1572> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_1572:
	/* 0x1572: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_1575:
	/* 0x1575: jns    1c1f <generic_retkprobe_event+0x1c1f> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1575, 0x1c1f, x86_l_1c1f);
x86_l_157b:
	/* 0x157b: jmp    4159 <generic_retkprobe_event+0x4159> */
	X86_SIM_X86_JMP(0x157b, 0x4159, x86_l_4159);
x86_l_1580:
	/* 0x1580: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1589:
	/* 0x1589: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_1592:
	/* 0x1592: call   1597 <generic_retkprobe_event+0x1597> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_get_current_pid_tgid);
x86_l_1597:
	/* 0x1597: shr    rax,0x20 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_159b:
	/* 0x159b: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_15a0:
	/* 0x15a0: lea    rax,[rsp+0x20] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_15a5:
	/* 0x15a5: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_15a8:
	/* 0x15a8: jns    1b43 <generic_retkprobe_event+0x1b43> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x15a8, 0x1b43, x86_l_1b43);
x86_l_15ae:
	/* 0x15ae: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_15b1:
	/* 0x15b1: jns    24d7 <generic_retkprobe_event+0x24d7> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x15b1, 0x24d7, x86_l_24d7);
x86_l_15b7:
	/* 0x15b7: mov    eax,DWORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15b9:
	/* 0x15b9: mov    DWORD PTR [rsp+0x80],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_15c0:
	/* 0x15c0: jmp    24e4 <generic_retkprobe_event+0x24e4> */
	X86_SIM_X86_JMP(0x15c0, 0x24e4, x86_l_24e4);
x86_l_15c5:
	/* 0x15c5: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_15ca:
	/* 0x15ca: add    rdi,0xa0 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 160ULL);
x86_l_15d1:
	/* 0x15d1: mov    edx,0x118 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 280ULL);
x86_l_15d6:
	/* 0x15d6: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_RUN_OP(X86_OP_ALU_MEM, X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_15db:
	/* 0x15db: jns    1b66 <generic_retkprobe_event+0x1b66> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x15db, 0x1b66, x86_l_1b66);
x86_l_15e1:
	/* 0x15e1: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_15e4:
	/* 0x15e4: jns    2550 <generic_retkprobe_event+0x2550> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x15e4, 0x2550, x86_l_2550);
x86_l_15ea:
	/* 0x15ea: movzx  eax,BYTE PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_15ed:
	/* 0x15ed: mov    BYTE PTR [rdi],al */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15ef:
	/* 0x15ef: test   al,al */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8, 0, 0);
x86_l_15f1:
	/* 0x15f1: je     3375 <generic_retkprobe_event+0x3375> */
	X86_SIM_X86_JCC(X86_CC_E, 0x15f1, 0x3375, x86_l_3375);
x86_l_15f7:
	/* 0x15f7: movzx  eax,BYTE PTR [rdx+0x1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 1ULL);
x86_l_15fb:
	/* 0x15fb: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1600:
	/* 0x1600: mov    BYTE PTR [rcx+0xa1],al */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 161ULL);
x86_l_1606:
	/* 0x1606: test   al,al */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8, 0, 0);
x86_l_1608:
	/* 0x1608: je     39d0 <generic_retkprobe_event+0x39d0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1608, 0x39d0, x86_l_39d0);
x86_l_160e:
	/* 0x160e: movzx  eax,BYTE PTR [rdx+0x2] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 2ULL);
x86_l_1612:
	/* 0x1612: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1617:
	/* 0x1617: mov    BYTE PTR [rcx+0xa2],al */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 162ULL);
x86_l_161d:
	/* 0x161d: test   al,al */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8, 0, 0);
x86_l_161f:
	/* 0x161f: je     3cc6 <generic_retkprobe_event+0x3cc6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x161f, 0x3cc6, x86_l_3cc6);
x86_l_1625:
	/* 0x1625: movzx  eax,BYTE PTR [rdx+0x3] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 3ULL);
x86_l_1629:
	/* 0x1629: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_162e:
	/* 0x162e: mov    BYTE PTR [rcx+0xa3],al */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 163ULL);
x86_l_1634:
	/* 0x1634: test   al,al */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8, 0, 0);
x86_l_1636:
	/* 0x1636: je     4164 <generic_retkprobe_event+0x4164> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1636, 0x4164, x86_l_4164);
x86_l_163c:
	/* 0x163c: movzx  eax,BYTE PTR [rdx+0x4] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 4ULL);
x86_l_1640:
	/* 0x1640: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1645:
	/* 0x1645: mov    BYTE PTR [rcx+0xa4],al */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_164b:
	/* 0x164b: test   al,al */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8, 0, 0);
x86_l_164d:
	/* 0x164d: je     4200 <generic_retkprobe_event+0x4200> */
	X86_SIM_X86_JCC(X86_CC_E, 0x164d, 0x4200, x86_l_4200);
x86_l_1653:
	/* 0x1653: movzx  eax,BYTE PTR [rdx+0x5] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_1657:
	/* 0x1657: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_165c:
	/* 0x165c: mov    BYTE PTR [rcx+0xa5],al */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 165ULL);
x86_l_1662:
	/* 0x1662: test   al,al */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8, 0, 0);
x86_l_1664:
	/* 0x1664: je     42de <generic_retkprobe_event+0x42de> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1664, 0x42de, x86_l_42de);
x86_l_166a:
	/* 0x166a: movzx  eax,BYTE PTR [rdx+0x6] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_166e:
	/* 0x166e: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1673:
	/* 0x1673: mov    BYTE PTR [rcx+0xa6],al */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 166ULL);
x86_l_1679:
	/* 0x1679: test   al,al */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8, 0, 0);
x86_l_167b:
	/* 0x167b: je     42ed <generic_retkprobe_event+0x42ed> */
	X86_SIM_X86_JCC(X86_CC_E, 0x167b, 0x42ed, x86_l_42ed);
x86_l_1681:
	/* 0x1681: movzx  eax,BYTE PTR [rdx+0x7] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_1685:
	/* 0x1685: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_168a:
	/* 0x168a: mov    BYTE PTR [rcx+0xa7],al */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 167ULL);
x86_l_1690:
	/* 0x1690: test   al,al */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8, 0, 0);
x86_l_1692:
	/* 0x1692: je     4315 <generic_retkprobe_event+0x4315> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1692, 0x4315, x86_l_4315);
x86_l_1698:
	/* 0x1698: movzx  eax,BYTE PTR [rdx+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_169c:
	/* 0x169c: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16a1:
	/* 0x16a1: mov    BYTE PTR [rcx+0xa8],al */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_16a7:
	/* 0x16a7: test   al,al */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8, 0, 0);
x86_l_16a9:
	/* 0x16a9: je     4324 <generic_retkprobe_event+0x4324> */
	X86_SIM_X86_JCC(X86_CC_E, 0x16a9, 0x4324, x86_l_4324);
x86_l_16af:
	/* 0x16af: movzx  eax,BYTE PTR [rdx+0x9] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 9ULL);
x86_l_16b3:
	/* 0x16b3: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16b8:
	/* 0x16b8: mov    BYTE PTR [rcx+0xa9],al */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 169ULL);
x86_l_16be:
	/* 0x16be: test   al,al */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8, 0, 0);
x86_l_16c0:
	/* 0x16c0: je     4333 <generic_retkprobe_event+0x4333> */
	X86_SIM_X86_JCC(X86_CC_E, 0x16c0, 0x4333, x86_l_4333);
x86_l_16c6:
	/* 0x16c6: movzx  eax,BYTE PTR [rdx+0xa] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 10ULL);
x86_l_16ca:
	/* 0x16ca: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16cf:
	/* 0x16cf: mov    BYTE PTR [rcx+0xaa],al */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 170ULL);
x86_l_16d5:
	/* 0x16d5: test   al,al */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8, 0, 0);
x86_l_16d7:
	/* 0x16d7: je     43c9 <generic_retkprobe_event+0x43c9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x16d7, 0x43c9, x86_l_43c9);
x86_l_16dd:
	/* 0x16dd: movzx  eax,BYTE PTR [rdx+0xb] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 11ULL);
x86_l_16e1:
	/* 0x16e1: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16e6:
	/* 0x16e6: mov    BYTE PTR [rcx+0xab],al */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 171ULL);
x86_l_16ec:
	/* 0x16ec: test   al,al */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8, 0, 0);
x86_l_16ee:
	/* 0x16ee: je     448e <generic_retkprobe_event+0x448e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x16ee, 0x448e, x86_l_448e);
x86_l_16f4:
	/* 0x16f4: movzx  eax,BYTE PTR [rdx+0xc] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 12ULL);
x86_l_16f8:
	/* 0x16f8: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16fd:
	/* 0x16fd: mov    BYTE PTR [rcx+0xac],al */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_1703:
	/* 0x1703: test   al,al */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8, 0, 0);
x86_l_1705:
	/* 0x1705: je     449d <generic_retkprobe_event+0x449d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1705, 0x449d, x86_l_449d);
x86_l_170b:
	/* 0x170b: movzx  eax,BYTE PTR [rdx+0xd] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 13ULL);
x86_l_170f:
	/* 0x170f: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1714:
	/* 0x1714: mov    BYTE PTR [rcx+0xad],al */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 173ULL);
x86_l_171a:
	/* 0x171a: test   al,al */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8, 0, 0);
x86_l_171c:
	/* 0x171c: je     44ac <generic_retkprobe_event+0x44ac> */
	X86_SIM_X86_JCC(X86_CC_E, 0x171c, 0x44ac, x86_l_44ac);
x86_l_1722:
	/* 0x1722: movzx  eax,BYTE PTR [rdx+0xe] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 14ULL);
x86_l_1726:
	/* 0x1726: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_172b:
	/* 0x172b: mov    BYTE PTR [rcx+0xae],al */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 174ULL);
x86_l_1731:
	/* 0x1731: test   al,al */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8, 0, 0);
x86_l_1733:
	/* 0x1733: je     44d2 <generic_retkprobe_event+0x44d2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1733, 0x44d2, x86_l_44d2);
x86_l_1739:
	/* 0x1739: movzx  eax,BYTE PTR [rdx+0xf] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 15ULL);
x86_l_173d:
	/* 0x173d: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1742:
	/* 0x1742: mov    BYTE PTR [rcx+0xaf],al */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 175ULL);
x86_l_1748:
	/* 0x1748: test   al,al */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8, 0, 0);
x86_l_174a:
	/* 0x174a: je     44e1 <generic_retkprobe_event+0x44e1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x174a, 0x44e1, x86_l_44e1);
x86_l_1750:
	/* 0x1750: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1755:
	/* 0x1755: mov    BYTE PTR [rax+0xb0],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_175c:
	/* 0x175c: mov    r12d,0x11 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_1762:
	/* 0x1762: mov    r14,QWORD PTR [rsp] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1766:
	/* 0x1766: jmp    260c <generic_retkprobe_event+0x260c> */
	X86_SIM_X86_JMP(0x1766, 0x260c, x86_l_260c);
x86_l_176b:
	/* 0x176b: mov    r13,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R13, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_176e:
	/* 0x176e: mov    r12,QWORD PTR [rsp+0x20] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1773:
	/* 0x1773: test   r12,r12 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_1776:
	/* 0x1776: js     1c8f <generic_retkprobe_event+0x1c8f> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1776, 0x1c8f, x86_l_1c8f);
x86_l_177c:
	/* 0x177c: lea    rdi,[rsp+0x90] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1784:
	/* 0x1784: mov    esi,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_1789:
	/* 0x1789: mov    rdx,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_178c:
	/* 0x178c: call   1791 <generic_retkprobe_event+0x1791> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_1791:
	/* 0x1791: movzx  eax,BYTE PTR [rsp+0x90] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 144ULL);
x86_l_1799:
	/* 0x1799: jmp    1ca5 <generic_retkprobe_event+0x1ca5> */
	X86_SIM_X86_JMP(0x1799, 0x1ca5, x86_l_1ca5);
x86_l_179e:
	/* 0x179e: xor    esi,esi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_17a0:
	/* 0x17a0: mov    rdx,r13 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_17a3:
	/* 0x17a3: mov    r14,r8 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R14, X86_R8, X86_WIDTH_64, 0, 0);
x86_l_17a6:
	/* 0x17a6: call   47c5 <__native_link_local_memset_zero_dynamic> */
	X86_SIM_X86_CALL(x86_l_47c5, 0x17abULL);
x86_l_17ab:
	/* 0x17ab: mov    r8,r14 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R8, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_17ae:
	/* 0x17ae: mov    ecx,0xfffffffe */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 4294967294ULL);
x86_l_17b3:
	/* 0x17b3: jmp    1178 <generic_retkprobe_event+0x1178> */
	X86_SIM_X86_JMP(0x17b3, 0x1178, x86_l_1178);
x86_l_17b8:
	/* 0x17b8: mov    DWORD PTR [rcx],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_17be:
	/* 0x17be: mov    r12d,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_17c4:
	/* 0x17c4: jmp    3d33 <generic_retkprobe_event+0x3d33> */
	X86_SIM_X86_JMP(0x17c4, 0x3d33, x86_l_3d33);
x86_l_17c9:
	/* 0x17c9: mov    QWORD PTR [rdi+0x48],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_17d1:
	/* 0x17d1: mov    QWORD PTR [rdi+0x40],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_17d9:
	/* 0x17d9: mov    QWORD PTR [rdi+0x38],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_17e1:
	/* 0x17e1: mov    QWORD PTR [rdi+0x30],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_17e9:
	/* 0x17e9: mov    QWORD PTR [rdi+0x28],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_17f1:
	/* 0x17f1: mov    QWORD PTR [rdi+0x20],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_17f9:
	/* 0x17f9: mov    QWORD PTR [rdi+0x18],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1801:
	/* 0x1801: mov    QWORD PTR [rdi+0x10],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1809:
	/* 0x1809: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1811:
	/* 0x1811: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1818:
	/* 0x1818: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_181d:
	/* 0x181d: add    rdi,0xac */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 172ULL);
x86_l_1824:
	/* 0x1824: mov    rdx,rbp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_1827:
	/* 0x1827: add    rdx,0x18 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_182b:
	/* 0x182b: jns    1cda <generic_retkprobe_event+0x1cda> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x182b, 0x1cda, x86_l_1cda);
x86_l_1831:
	/* 0x1831: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_1834:
	/* 0x1834: jns    26c4 <generic_retkprobe_event+0x26c4> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1834, 0x26c4, x86_l_26c4);
x86_l_183a:
	/* 0x183a: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_183c:
	/* 0x183c: mov    rsi,rdi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_RDI, X86_WIDTH_64, 0, 0);
x86_l_183f:
	/* 0x183f: cmp    rax,0x3e */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, 0, 62ULL);
x86_l_1843:
	/* 0x1843: je     332c <generic_retkprobe_event+0x332c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1843, 0x332c, x86_l_332c);
x86_l_1849:
	/* 0x1849: movzx  ecx,BYTE PTR [rdx+rax*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_184d:
	/* 0x184d: mov    BYTE PTR [rsi+rax*1],cl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1850:
	/* 0x1850: inc    rax */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1853:
	/* 0x1853: test   cl,cl */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8, 0, 0);
x86_l_1855:
	/* 0x1855: jne    183f <generic_retkprobe_event+0x183f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1855, 0x183f, x86_l_183f);
x86_l_1857:
	/* 0x1857: jmp    3338 <generic_retkprobe_event+0x3338> */
	X86_SIM_X86_JMP(0x1857, 0x3338, x86_l_3338);
x86_l_185c:
	/* 0x185c: test   rbp,rbp */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_185f:
	/* 0x185f: js     1feb <generic_retkprobe_event+0x1feb> */
	X86_SIM_X86_JCC(X86_CC_S, 0x185f, 0x1feb, x86_l_1feb);
x86_l_1865:
	/* 0x1865: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_186a:
	/* 0x186a: mov    rdx,rbp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_186d:
	/* 0x186d: call   1872 <generic_retkprobe_event+0x1872> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_1872:
	/* 0x1872: jmp    2f35 <generic_retkprobe_event+0x2f35> */
	X86_SIM_X86_JMP(0x1872, 0x2f35, x86_l_2f35);
x86_l_1877:
	/* 0x1877: mov    QWORD PTR [rax+0x9c],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_1882:
	/* 0x1882: jmp    1aa7 <generic_retkprobe_event+0x1aa7> */
	X86_SIM_X86_JMP(0x1882, 0x1aa7, x86_l_1aa7);
x86_l_1887:
	/* 0x1887: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_1890:
	/* 0x1890: lea    r12,[rbp+0xd8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R12, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_1897:
	/* 0x1897: mov    rdx,rbp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_189a:
	/* 0x189a: add    rdx,0x110 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 272ULL);
x86_l_18a1:
	/* 0x18a1: jns    1cf2 <generic_retkprobe_event+0x1cf2> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x18a1, 0x1cf2, x86_l_1cf2);
x86_l_18a7:
	/* 0x18a7: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_18aa:
	/* 0x18aa: jns    2708 <generic_retkprobe_event+0x2708> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x18aa, 0x2708, x86_l_2708);
x86_l_18b0:
	/* 0x18b0: mov    rdx,QWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18b3:
	/* 0x18b3: mov    QWORD PTR [rsp+0x40],rdx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_18b8:
	/* 0x18b8: jmp    1d06 <generic_retkprobe_event+0x1d06> */
	X86_SIM_X86_JMP(0x18b8, 0x1d06, x86_l_1d06);
x86_l_18bd:
	/* 0x18bd: test   rbp,rbp */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_18c0:
	/* 0x18c0: js     2005 <generic_retkprobe_event+0x2005> */
	X86_SIM_X86_JCC(X86_CC_S, 0x18c0, 0x2005, x86_l_2005);
x86_l_18c6:
	/* 0x18c6: xor    r12d,r12d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_18c9:
	/* 0x18c9: xor    esi,esi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_18cb:
	/* 0x18cb: mov    rdx,rbp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_18ce:
	/* 0x18ce: call   18d3 <generic_retkprobe_event+0x18d3> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_18d3:
	/* 0x18d3: jmp    3823 <generic_retkprobe_event+0x3823> */
	X86_SIM_X86_JMP(0x18d3, 0x3823, x86_l_3823);
x86_l_18d8:
	/* 0x18d8: mov    r14,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R14, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_18db:
	/* 0x18db: mov    QWORD PTR [rsp+0x80],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_18e7:
	/* 0x18e7: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_18f0:
	/* 0x18f0: test   r13,r13 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_18f3:
	/* 0x18f3: jns    1d3c <generic_retkprobe_event+0x1d3c> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x18f3, 0x1d3c, x86_l_1d3c);
x86_l_18f9:
	/* 0x18f9: lea    rax,[rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_18fe:
	/* 0x18fe: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_1901:
	/* 0x1901: jns    27e3 <generic_retkprobe_event+0x27e3> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1901, 0x27e3, x86_l_27e3);
x86_l_1907:
	/* 0x1907: mov    r15,QWORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_190a:
	/* 0x190a: mov    QWORD PTR [rsp+0x80],r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1912:
	/* 0x1912: jmp    27f2 <generic_retkprobe_event+0x27f2> */
	X86_SIM_X86_JMP(0x1912, 0x27f2, x86_l_27f2);
x86_l_1917:
	/* 0x1917: mov    rdx,rbp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_191a:
	/* 0x191a: add    rdx,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_191e:
	/* 0x191e: jns    1d60 <generic_retkprobe_event+0x1d60> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x191e, 0x1d60, x86_l_1d60);
x86_l_1924:
	/* 0x1924: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_1927:
	/* 0x1927: jns    288d <generic_retkprobe_event+0x288d> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1927, 0x288d, x86_l_288d);
x86_l_192d:
	/* 0x192d: mov    eax,DWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_192f:
	/* 0x192f: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1934:
	/* 0x1934: mov    DWORD PTR [rcx],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1936:
	/* 0x1936: jmp    2898 <generic_retkprobe_event+0x2898> */
	X86_SIM_X86_JMP(0x1936, 0x2898, x86_l_2898);
x86_l_193b:
	/* 0x193b: mov    rdx,rbp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_193e:
	/* 0x193e: add    rdx,0x38 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 56ULL);
x86_l_1942:
	/* 0x1942: jns    1d6f <generic_retkprobe_event+0x1d6f> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1942, 0x1d6f, x86_l_1d6f);
x86_l_1948:
	/* 0x1948: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_194b:
	/* 0x194b: jns    2c07 <generic_retkprobe_event+0x2c07> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x194b, 0x2c07, x86_l_2c07);
x86_l_1951:
	/* 0x1951: mov    eax,DWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1953:
	/* 0x1953: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1958:
	/* 0x1958: mov    DWORD PTR [rcx],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_195a:
	/* 0x195a: jmp    2c12 <generic_retkprobe_event+0x2c12> */
	X86_SIM_X86_JMP(0x195a, 0x2c12, x86_l_2c12);
x86_l_195f:
	/* 0x195f: mov    rdx,rbp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_1962:
	/* 0x1962: add    rdx,0xc8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 200ULL);
x86_l_1969:
	/* 0x1969: jns    1d7e <generic_retkprobe_event+0x1d7e> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1969, 0x1d7e, x86_l_1d7e);
x86_l_196f:
	/* 0x196f: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_1972:
	/* 0x1972: jns    2d1b <generic_retkprobe_event+0x2d1b> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1972, 0x2d1b, x86_l_2d1b);
x86_l_1978:
	/* 0x1978: mov    eax,DWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_197a:
	/* 0x197a: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_197f:
	/* 0x197f: mov    DWORD PTR [rcx],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1981:
	/* 0x1981: jmp    2d26 <generic_retkprobe_event+0x2d26> */
	X86_SIM_X86_JMP(0x1981, 0x2d26, x86_l_2d26);
x86_l_1986:
	/* 0x1986: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_198b:
	/* 0x198b: add    rbp,0x18 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_198f:
	/* 0x198f: jns    1d8d <generic_retkprobe_event+0x1d8d> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x198f, 0x1d8d, x86_l_1d8d);
x86_l_1995:
	/* 0x1995: test   rbp,rbp */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_1998:
	/* 0x1998: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_199d:
	/* 0x199d: jns    3e8b <generic_retkprobe_event+0x3e8b> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x199d, 0x3e8b, x86_l_3e8b);
x86_l_19a3:
	/* 0x19a3: mov    r12,QWORD PTR [rbp+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R12, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19a7:
	/* 0x19a7: mov    QWORD PTR [rsp+0x40],r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_19ac:
	/* 0x19ac: jmp    1da4 <generic_retkprobe_event+0x1da4> */
	X86_SIM_X86_JMP(0x19ac, 0x1da4, x86_l_1da4);
x86_l_19b1:
	/* 0x19b1: mov    QWORD PTR [rdi+0x48],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_19b9:
	/* 0x19b9: mov    QWORD PTR [rdi+0x40],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_19c1:
	/* 0x19c1: mov    QWORD PTR [rdi+0x38],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_19c9:
	/* 0x19c9: mov    QWORD PTR [rdi+0x30],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_19d1:
	/* 0x19d1: mov    QWORD PTR [rdi+0x28],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_19d9:
	/* 0x19d9: mov    QWORD PTR [rdi+0x20],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_19e1:
	/* 0x19e1: mov    QWORD PTR [rdi+0x18],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_19e9:
	/* 0x19e9: mov    QWORD PTR [rdi+0x10],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_19f1:
	/* 0x19f1: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_19f9:
	/* 0x19f9: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a00:
	/* 0x1a00: mov    rax,rbp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_1a03:
	/* 0x1a03: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_1a06:
	/* 0x1a06: jns    1de6 <generic_retkprobe_event+0x1de6> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1a06, 0x1de6, x86_l_1de6);
x86_l_1a0c:
	/* 0x1a0c: mov    rdx,QWORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a0f:
	/* 0x1a0f: add    QWORD PTR [rsp+0x10],0xac */
	X86_SIM_RUN_OP(X86_OP_ALU_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 68719476908ULL);
x86_l_1a18:
	/* 0x1a18: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_1a1b:
	/* 0x1a1b: js     2ffa <generic_retkprobe_event+0x2ffa> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1a1b, 0x2ffa, x86_l_2ffa);
x86_l_1a21:
	/* 0x1a21: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a26:
	/* 0x1a26: mov    esi,0x3f */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 63ULL);
x86_l_1a2b:
	/* 0x1a2b: call   1a30 <generic_retkprobe_event+0x1a30> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read_str);
x86_l_1a30:
	/* 0x1a30: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_1a33:
	/* 0x1a33: js     381c <generic_retkprobe_event+0x381c> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1a33, 0x381c, x86_l_381c);
x86_l_1a39:
	/* 0x1a39: lea    rax,[rbp+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a3d:
	/* 0x1a3d: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_1a40:
	/* 0x1a40: jns    3233 <generic_retkprobe_event+0x3233> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1a40, 0x3233, x86_l_3233);
x86_l_1a46:
	/* 0x1a46: mov    rax,QWORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a49:
	/* 0x1a49: jmp    3235 <generic_retkprobe_event+0x3235> */
	X86_SIM_X86_JMP(0x1a49, 0x3235, x86_l_3235);
x86_l_1a4e:
	/* 0x1a4e: mov    DWORD PTR [rcx+0xa0],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_1a58:
	/* 0x1a58: mov    DWORD PTR [rcx+0x9c],ebp */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_1a5e:
	/* 0x1a5e: jmp    1aa7 <generic_retkprobe_event+0x1aa7> */
	X86_SIM_X86_JMP(0x1a5e, 0x1aa7, x86_l_1aa7);
x86_l_1a60:
	/* 0x1a60: lea    rcx,[rbp+0x4] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RCX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1a64:
	/* 0x1a64: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1a66:
	/* 0x1a66: mov    edx,0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 0ULL);
x86_l_1a6b:
	/* 0x1a6b: test   rcx,rcx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_1a6e:
	/* 0x1a6e: jns    1a72 <generic_retkprobe_event+0x1a72> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1a6e, 0x1a72, x86_l_1a72);
x86_l_1a70:
	/* 0x1a70: mov    edx,DWORD PTR [rcx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a72:
	/* 0x1a72: mov    DWORD PTR [rdi],edx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a74:
	/* 0x1a74: lea    rcx,[rbp+0xc] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RCX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1a78:
	/* 0x1a78: test   rcx,rcx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_1a7b:
	/* 0x1a7b: jns    1a7f <generic_retkprobe_event+0x1a7f> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1a7b, 0x1a7f, x86_l_1a7f);
x86_l_1a7d:
	/* 0x1a7d: mov    eax,DWORD PTR [rcx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a7f:
	/* 0x1a7f: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a84:
	/* 0x1a84: mov    DWORD PTR [rcx+0xa0],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1a8a:
	/* 0x1a8a: add    rbp,0x50 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_1a8e:
	/* 0x1a8e: test   rbp,rbp */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_1a91:
	/* 0x1a91: jns    1dee <generic_retkprobe_event+0x1dee> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1a91, 0x1dee, x86_l_1dee);
x86_l_1a97:
	/* 0x1a97: mov    rax,QWORD PTR [rbp+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a9b:
	/* 0x1a9b: jmp    1df0 <generic_retkprobe_event+0x1df0> */
	X86_SIM_X86_JMP(0x1a9b, 0x1df0, x86_l_1df0);
x86_l_1aa0:
	/* 0x1aa0: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1aa7:
	/* 0x1aa7: mov    r12d,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_1aad:
	/* 0x1aad: jmp    3828 <generic_retkprobe_event+0x3828> */
	X86_SIM_X86_JMP(0x1aad, 0x3828, x86_l_3828);
x86_l_1ab2:
	/* 0x1ab2: mov    r14,QWORD PTR [rsp] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ab6:
	/* 0x1ab6: jmp    3d33 <generic_retkprobe_event+0x3d33> */
	X86_SIM_X86_JMP(0x1ab6, 0x3d33, x86_l_3d33);
x86_l_1abb:
	/* 0x1abb: mov    WORD PTR [rcx],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ac0:
	/* 0x1ac0: mov    r12d,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_1ac6:
	/* 0x1ac6: jmp    3d33 <generic_retkprobe_event+0x3d33> */
	X86_SIM_X86_JMP(0x1ac6, 0x3d33, x86_l_3d33);
x86_l_1acb:
	/* 0x1acb: mov    BYTE PTR [rcx],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ace:
	/* 0x1ace: mov    r12d,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_1ad4:
	/* 0x1ad4: jmp    3d33 <generic_retkprobe_event+0x3d33> */
	X86_SIM_X86_JMP(0x1ad4, 0x3d33, x86_l_3d33);
x86_l_1ad9:
	/* 0x1ad9: mov    esi,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_1ade:
	/* 0x1ade: call   1ae3 <generic_retkprobe_event+0x1ae3> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_1ae3:
	/* 0x1ae3: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ae8:
	/* 0x1ae8: jmp    20d8 <generic_retkprobe_event+0x20d8> */
	X86_SIM_X86_JMP(0x1ae8, 0x20d8, x86_l_20d8);
x86_l_1aed:
	/* 0x1aed: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1af2:
	/* 0x1af2: jmp    25fb <generic_retkprobe_event+0x25fb> */
	X86_SIM_X86_JMP(0x1af2, 0x25fb, x86_l_25fb);
x86_l_1af7:
	/* 0x1af7: lea    rdi,[rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1afc:
	/* 0x1afc: lea    rdx,[rsp+0x20] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b01:
	/* 0x1b01: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_1b06:
	/* 0x1b06: call   1b0b <generic_retkprobe_event+0x1b0b> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_1b0b:
	/* 0x1b0b: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1b10:
	/* 0x1b10: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_1b13:
	/* 0x1b13: jns    2293 <generic_retkprobe_event+0x2293> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1b13, 0x2293, x86_l_2293);
x86_l_1b19:
	/* 0x1b19: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_1b1c:
	/* 0x1b1c: jns    25cd <generic_retkprobe_event+0x25cd> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1b1c, 0x25cd, x86_l_25cd);
x86_l_1b22:
	/* 0x1b22: mov    rax,QWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b25:
	/* 0x1b25: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b2a:
	/* 0x1b2a: jmp    25d6 <generic_retkprobe_event+0x25d6> */
	X86_SIM_X86_JMP(0x1b2a, 0x25d6, x86_l_25d6);
x86_l_1b2f:
	/* 0x1b2f: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_1b34:
	/* 0x1b34: call   1b39 <generic_retkprobe_event+0x1b39> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_1b39:
	/* 0x1b39: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b3e:
	/* 0x1b3e: jmp    22ad <generic_retkprobe_event+0x22ad> */
	X86_SIM_X86_JMP(0x1b3e, 0x22ad, x86_l_22ad);
x86_l_1b43:
	/* 0x1b43: lea    rdi,[rsp+0x80] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1b4b:
	/* 0x1b4b: lea    rdx,[rsp+0x20] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b50:
	/* 0x1b50: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_1b55:
	/* 0x1b55: call   1b5a <generic_retkprobe_event+0x1b5a> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_1b5a:
	/* 0x1b5a: mov    eax,DWORD PTR [rsp+0x80] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1b61:
	/* 0x1b61: jmp    24e4 <generic_retkprobe_event+0x24e4> */
	X86_SIM_X86_JMP(0x1b61, 0x24e4, x86_l_24e4);
x86_l_1b66:
	/* 0x1b66: mov    esi,0x11 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_1b6b:
	/* 0x1b6b: jmp    25fb <generic_retkprobe_event+0x25fb> */
	X86_SIM_X86_JMP(0x1b6b, 0x25fb, x86_l_25fb);
x86_l_1b70:
	/* 0x1b70: mov    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_1b72:
	/* 0x1b72: mov    esi,DWORD PTR [rdx+rcx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1b75:
	/* 0x1b75: mov    DWORD PTR [rdi+rcx*1],esi */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1b78:
	/* 0x1b78: or     eax,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_OR, 4ULL);
x86_l_1b7b:
	/* 0x1b7b: test   r13b,0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, 0, 2ULL);
x86_l_1b7f:
	/* 0x1b7f: je     11e8 <generic_retkprobe_event+0x11e8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1b7f, 0x11e8, x86_l_11e8);
x86_l_1b85:
	/* 0x1b85: mov    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_1b87:
	/* 0x1b87: movzx  esi,WORD PTR [rdx+rcx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_16), 0ULL);
x86_l_1b8b:
	/* 0x1b8b: mov    WORD PTR [rdi+rcx*1],si */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RSI, X86_WIDTH_16, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1b8f:
	/* 0x1b8f: add    eax,0x2 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_1b92:
	/* 0x1b92: test   r13b,0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_1b96:
	/* 0x1b96: je     11f2 <generic_retkprobe_event+0x11f2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1b96, 0x11f2, x86_l_11f2);
x86_l_1b9c:
	/* 0x1b9c: mov    eax,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_1b9e:
	/* 0x1b9e: movzx  ecx,BYTE PTR [rdx+rax*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1ba2:
	/* 0x1ba2: mov    BYTE PTR [rdi+rax*1],cl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1ba5:
	/* 0x1ba5: add    rbp,r13 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1ba8:
	/* 0x1ba8: test   r9,r9 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R9, X86_R9, X86_WIDTH_64, 0, 0);
x86_l_1bab:
	/* 0x1bab: jne    11fe <generic_retkprobe_event+0x11fe> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1bab, 0x11fe, x86_l_11fe);
x86_l_1bb1:
	/* 0x1bb1: jmp    12dc <generic_retkprobe_event+0x12dc> */
	X86_SIM_X86_JMP(0x1bb1, 0x12dc, x86_l_12dc);
x86_l_1bb6:
	/* 0x1bb6: mov    rax,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_1bb9:
	/* 0x1bb9: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_1bbc:
	/* 0x1bbc: jns    25b4 <generic_retkprobe_event+0x25b4> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1bbc, 0x25b4, x86_l_25b4);
x86_l_1bc2:
	/* 0x1bc2: movzx  eax,WORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1bc5:
	/* 0x1bc5: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1bca:
	/* 0x1bca: mov    WORD PTR [rcx],ax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1bcd:
	/* 0x1bcd: cmp    ax,0xa */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, 0, 10ULL);
x86_l_1bd1:
	/* 0x1bd1: je     2573 <generic_retkprobe_event+0x2573> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1bd1, 0x2573, x86_l_2573);
x86_l_1bd7:
	/* 0x1bd7: movzx  eax,ax */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_1bda:
	/* 0x1bda: cmp    eax,0x2 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_1bdd:
	/* 0x1bdd: jne    3bc9 <generic_retkprobe_event+0x3bc9> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1bdd, 0x3bc9, x86_l_3bc9);
x86_l_1be3:
	/* 0x1be3: mov    rdx,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_1be6:
	/* 0x1be6: add    rdx,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1bea:
	/* 0x1bea: jns    3305 <generic_retkprobe_event+0x3305> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1bea, 0x3305, x86_l_3305);
x86_l_1bf0:
	/* 0x1bf0: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_1bf3:
	/* 0x1bf3: jns    3b46 <generic_retkprobe_event+0x3b46> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1bf3, 0x3b46, x86_l_3b46);
x86_l_1bf9:
	/* 0x1bf9: mov    eax,DWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1bfb:
	/* 0x1bfb: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1bff:
	/* 0x1bff: jmp    3b50 <generic_retkprobe_event+0x3b50> */
	X86_SIM_X86_JMP(0x1bff, 0x3b50, x86_l_3b50);
x86_l_1c04:
	/* 0x1c04: mov    rax,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_1c07:
	/* 0x1c07: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_1c0a:
	/* 0x1c0a: jns    2670 <generic_retkprobe_event+0x2670> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1c0a, 0x2670, x86_l_2670);
x86_l_1c10:
	/* 0x1c10: movzx  eax,WORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1c13:
	/* 0x1c13: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1c18:
	/* 0x1c18: mov    WORD PTR [rcx],ax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c1b:
	/* 0x1c1b: mov    r14,QWORD PTR [rsp] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c1f:
	/* 0x1c1f: mov    r13,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R13, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_1c22:
	/* 0x1c22: add    r13,0x2 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_1c26:
	/* 0x1c26: jns    1f8f <generic_retkprobe_event+0x1f8f> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1c26, 0x1f8f, x86_l_1f8f);
x86_l_1c2c:
	/* 0x1c2c: mov    rax,r13 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_1c2f:
	/* 0x1c2f: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_1c32:
	/* 0x1c32: jns    4159 <generic_retkprobe_event+0x4159> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1c32, 0x4159, x86_l_4159);
x86_l_1c38:
	/* 0x1c38: movzx  eax,BYTE PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1c3b:
	/* 0x1c3b: mov    BYTE PTR [rsp+0x40],al */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1c3f:
	/* 0x1c3f: test   al,al */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8, 0, 0);
x86_l_1c41:
	/* 0x1c41: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c46:
	/* 0x1c46: sete   BYTE PTR [rax+0x9e] */
	X86_SIM_RUN_OP(X86_OP_SETCC_MEM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_REG_AUX_SRC_SHIFT(X86_CC_E)), 158ULL);
x86_l_1c4d:
	/* 0x1c4d: je     3090 <generic_retkprobe_event+0x3090> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1c4d, 0x3090, x86_l_3090);
x86_l_1c53:
	/* 0x1c53: add    QWORD PTR [rsp+0x10],0xa0 */
	X86_SIM_RUN_OP(X86_OP_ALU_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 68719476896ULL);
x86_l_1c5c:
	/* 0x1c5c: test   r13,r13 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_1c5f:
	/* 0x1c5f: jns    3bf3 <generic_retkprobe_event+0x3bf3> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1c5f, 0x3bf3, x86_l_3bf3);
x86_l_1c65:
	/* 0x1c65: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1c67:
	/* 0x1c67: mov    rsi,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c6c:
	/* 0x1c6c: cmp    rcx,0x6b */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, 0, 107ULL);
x86_l_1c70:
	/* 0x1c70: je     4137 <generic_retkprobe_event+0x4137> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1c70, 0x4137, x86_l_4137);
x86_l_1c76:
	/* 0x1c76: lea    rax,[rcx+0x1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_1c7a:
	/* 0x1c7a: movzx  edx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1c80:
	/* 0x1c80: mov    BYTE PTR [rsi+rcx*1],dl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSI, X86_RDX, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1c83:
	/* 0x1c83: mov    rcx,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_1c86:
	/* 0x1c86: test   dl,dl */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8, 0, 0);
x86_l_1c88:
	/* 0x1c88: jne    1c6c <generic_retkprobe_event+0x1c6c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1c88, 0x1c6c, x86_l_1c6c);
x86_l_1c8a:
	/* 0x1c8a: jmp    1fda <generic_retkprobe_event+0x1fda> */
	X86_SIM_X86_JMP(0x1c8a, 0x1fda, x86_l_1fda);
x86_l_1c8f:
	/* 0x1c8f: mov    rax,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_1c92:
	/* 0x1c92: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_1c95:
	/* 0x1c95: jns    2683 <generic_retkprobe_event+0x2683> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1c95, 0x2683, x86_l_2683);
x86_l_1c9b:
	/* 0x1c9b: movzx  eax,BYTE PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1c9e:
	/* 0x1c9e: mov    BYTE PTR [rsp+0x90],al */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1ca5:
	/* 0x1ca5: test   al,al */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8, 0, 0);
x86_l_1ca7:
	/* 0x1ca7: je     268b <generic_retkprobe_event+0x268b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1ca7, 0x268b, x86_l_268b);
x86_l_1cad:
	/* 0x1cad: movzx  eax,al */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8, 0);
x86_l_1cb0:
	/* 0x1cb0: cmp    eax,0x1 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_1cb3:
	/* 0x1cb3: jne    200d <generic_retkprobe_event+0x200d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1cb3, 0x200d, x86_l_200d);
x86_l_1cb9:
	/* 0x1cb9: add    r12,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1cbd:
	/* 0x1cbd: jns    3027 <generic_retkprobe_event+0x3027> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1cbd, 0x3027, x86_l_3027);
x86_l_1cc3:
	/* 0x1cc3: test   r12,r12 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_1cc6:
	/* 0x1cc6: jns    3838 <generic_retkprobe_event+0x3838> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1cc6, 0x3838, x86_l_3838);
x86_l_1ccc:
	/* 0x1ccc: mov    rdx,QWORD PTR [r12] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1cd0:
	/* 0x1cd0: mov    QWORD PTR [rsp+0x40],rdx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1cd5:
	/* 0x1cd5: jmp    303e <generic_retkprobe_event+0x303e> */
	X86_SIM_X86_JMP(0x1cd5, 0x303e, x86_l_303e);
x86_l_1cda:
	/* 0x1cda: mov    esi,0x3f */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 63ULL);
x86_l_1cdf:
	/* 0x1cdf: call   1ce4 <generic_retkprobe_event+0x1ce4> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read_str);
x86_l_1ce4:
	/* 0x1ce4: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_1ce7:
	/* 0x1ce7: jns    3338 <generic_retkprobe_event+0x3338> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1ce7, 0x3338, x86_l_3338);
x86_l_1ced:
	/* 0x1ced: jmp    381c <generic_retkprobe_event+0x381c> */
	X86_SIM_X86_JMP(0x1ced, 0x381c, x86_l_381c);
x86_l_1cf2:
	/* 0x1cf2: lea    rdi,[rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1cf7:
	/* 0x1cf7: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_1cfc:
	/* 0x1cfc: call   1d01 <generic_retkprobe_event+0x1d01> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_1d01:
	/* 0x1d01: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1d06:
	/* 0x1d06: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_1d09:
	/* 0x1d09: jns    2713 <generic_retkprobe_event+0x2713> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1d09, 0x2713, x86_l_2713);
x86_l_1d0f:
	/* 0x1d0f: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_1d12:
	/* 0x1d12: jns    327c <generic_retkprobe_event+0x327c> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1d12, 0x327c, x86_l_327c);
x86_l_1d18:
	/* 0x1d18: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1d1a:
	/* 0x1d1a: mov    rsi,QWORD PTR [rsp+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1d1f:
	/* 0x1d1f: cmp    rax,0x7f */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, 0, 127ULL);
x86_l_1d23:
	/* 0x1d23: je     3a3e <generic_retkprobe_event+0x3a3e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1d23, 0x3a3e, x86_l_3a3e);
x86_l_1d29:
	/* 0x1d29: movzx  ecx,BYTE PTR [rdx+rax*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1d2d:
	/* 0x1d2d: mov    BYTE PTR [rsi+rax*1],cl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1d30:
	/* 0x1d30: inc    rax */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1d33:
	/* 0x1d33: test   cl,cl */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8, 0, 0);
x86_l_1d35:
	/* 0x1d35: jne    1d1f <generic_retkprobe_event+0x1d1f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1d35, 0x1d1f, x86_l_1d1f);
x86_l_1d37:
	/* 0x1d37: jmp    2722 <generic_retkprobe_event+0x2722> */
	X86_SIM_X86_JMP(0x1d37, 0x2722, x86_l_2722);
x86_l_1d3c:
	/* 0x1d3c: lea    rdi,[rsp+0x80] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1d44:
	/* 0x1d44: lea    rdx,[rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1d49:
	/* 0x1d49: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_1d4e:
	/* 0x1d4e: call   1d53 <generic_retkprobe_event+0x1d53> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_1d53:
	/* 0x1d53: mov    r15,QWORD PTR [rsp+0x80] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1d5b:
	/* 0x1d5b: jmp    27f2 <generic_retkprobe_event+0x27f2> */
	X86_SIM_X86_JMP(0x1d5b, 0x27f2, x86_l_27f2);
x86_l_1d60:
	/* 0x1d60: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_1d65:
	/* 0x1d65: call   1d6a <generic_retkprobe_event+0x1d6a> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_1d6a:
	/* 0x1d6a: jmp    2898 <generic_retkprobe_event+0x2898> */
	X86_SIM_X86_JMP(0x1d6a, 0x2898, x86_l_2898);
x86_l_1d6f:
	/* 0x1d6f: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_1d74:
	/* 0x1d74: call   1d79 <generic_retkprobe_event+0x1d79> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_1d79:
	/* 0x1d79: jmp    2c12 <generic_retkprobe_event+0x2c12> */
	X86_SIM_X86_JMP(0x1d79, 0x2c12, x86_l_2c12);
x86_l_1d7e:
	/* 0x1d7e: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_1d83:
	/* 0x1d83: call   1d88 <generic_retkprobe_event+0x1d88> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_1d88:
	/* 0x1d88: jmp    2d26 <generic_retkprobe_event+0x2d26> */
	X86_SIM_X86_JMP(0x1d88, 0x2d26, x86_l_2d26);
x86_l_1d8d:
	/* 0x1d8d: lea    rdi,[rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1d92:
	/* 0x1d92: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_1d97:
	/* 0x1d97: mov    rdx,rbp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_1d9a:
	/* 0x1d9a: call   1d9f <generic_retkprobe_event+0x1d9f> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_1d9f:
	/* 0x1d9f: mov    r12,QWORD PTR [rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1da4:
	/* 0x1da4: test   r12,r12 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_1da7:
	/* 0x1da7: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1dac:
	/* 0x1dac: je     3e8b <generic_retkprobe_event+0x3e8b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1dac, 0x3e8b, x86_l_3e8b);
x86_l_1db2:
	/* 0x1db2: mov    QWORD PTR [rax+0xc4],r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_1db9:
	/* 0x1db9: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1dbe:
	/* 0x1dbe: lea    rdi,[rax+0xc2] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 194ULL);
x86_l_1dc5:
	/* 0x1dc5: mov    rdx,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_1dc8:
	/* 0x1dc8: add    rdx,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1dcc:
	/* 0x1dcc: jns    2de3 <generic_retkprobe_event+0x2de3> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1dcc, 0x2de3, x86_l_2de3);
x86_l_1dd2:
	/* 0x1dd2: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_1dd5:
	/* 0x1dd5: jns    339d <generic_retkprobe_event+0x339d> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1dd5, 0x339d, x86_l_339d);
x86_l_1ddb:
	/* 0x1ddb: movzx  eax,WORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1dde:
	/* 0x1dde: mov    WORD PTR [rdi],ax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1de1:
	/* 0x1de1: jmp    33a2 <generic_retkprobe_event+0x33a2> */
	X86_SIM_X86_JMP(0x1de1, 0x33a2, x86_l_33a2);
x86_l_1de6:
	/* 0x1de6: xor    r12d,r12d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1de9:
	/* 0x1de9: jmp    3828 <generic_retkprobe_event+0x3828> */
	X86_SIM_X86_JMP(0x1de9, 0x3828, x86_l_3828);
x86_l_1dee:
	/* 0x1dee: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1df0:
	/* 0x1df0: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1df5:
	/* 0x1df5: add    rdx,0xa4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 164ULL);
x86_l_1dfc:
	/* 0x1dfc: add    rax,0x400 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 1024ULL);
x86_l_1e02:
	/* 0x1e02: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_1e05:
	/* 0x1e05: jns    1f75 <generic_retkprobe_event+0x1f75> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1e05, 0x1f75, x86_l_1f75);
x86_l_1e0b:
	/* 0x1e0b: movzx  ecx,BYTE PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1e0e:
	/* 0x1e0e: mov    BYTE PTR [rdx],cl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e10:
	/* 0x1e10: mov    r12d,0x18 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 24ULL);
x86_l_1e16:
	/* 0x1e16: test   cl,cl */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8, 0, 0);
x86_l_1e18:
	/* 0x1e18: je     381f <generic_retkprobe_event+0x381f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1e18, 0x381f, x86_l_381f);
x86_l_1e1e:
	/* 0x1e1e: movzx  ecx,BYTE PTR [rax+0x1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 1ULL);
x86_l_1e22:
	/* 0x1e22: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e27:
	/* 0x1e27: mov    BYTE PTR [rdx+0xa5],cl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 165ULL);
x86_l_1e2d:
	/* 0x1e2d: test   cl,cl */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8, 0, 0);
x86_l_1e2f:
	/* 0x1e2f: je     381f <generic_retkprobe_event+0x381f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1e2f, 0x381f, x86_l_381f);
x86_l_1e35:
	/* 0x1e35: movzx  ecx,BYTE PTR [rax+0x2] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 2ULL);
x86_l_1e39:
	/* 0x1e39: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e3e:
	/* 0x1e3e: mov    BYTE PTR [rdx+0xa6],cl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 166ULL);
x86_l_1e44:
	/* 0x1e44: test   cl,cl */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8, 0, 0);
x86_l_1e46:
	/* 0x1e46: je     381f <generic_retkprobe_event+0x381f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1e46, 0x381f, x86_l_381f);
x86_l_1e4c:
	/* 0x1e4c: movzx  ecx,BYTE PTR [rax+0x3] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 3ULL);
x86_l_1e50:
	/* 0x1e50: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e55:
	/* 0x1e55: mov    BYTE PTR [rdx+0xa7],cl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 167ULL);
x86_l_1e5b:
	/* 0x1e5b: test   cl,cl */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8, 0, 0);
x86_l_1e5d:
	/* 0x1e5d: je     381f <generic_retkprobe_event+0x381f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1e5d, 0x381f, x86_l_381f);
x86_l_1e63:
	/* 0x1e63: movzx  ecx,BYTE PTR [rax+0x4] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 4ULL);
x86_l_1e67:
	/* 0x1e67: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e6c:
	/* 0x1e6c: mov    BYTE PTR [rdx+0xa8],cl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1e72:
	/* 0x1e72: test   cl,cl */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8, 0, 0);
x86_l_1e74:
	/* 0x1e74: je     381f <generic_retkprobe_event+0x381f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1e74, 0x381f, x86_l_381f);
x86_l_1e7a:
	/* 0x1e7a: movzx  ecx,BYTE PTR [rax+0x5] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_1e7e:
	/* 0x1e7e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e83:
	/* 0x1e83: mov    BYTE PTR [rdx+0xa9],cl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 169ULL);
x86_l_1e89:
	/* 0x1e89: test   cl,cl */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8, 0, 0);
x86_l_1e8b:
	/* 0x1e8b: je     381f <generic_retkprobe_event+0x381f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1e8b, 0x381f, x86_l_381f);
x86_l_1e91:
	/* 0x1e91: movzx  ecx,BYTE PTR [rax+0x6] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_1e95:
	/* 0x1e95: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e9a:
	/* 0x1e9a: mov    BYTE PTR [rdx+0xaa],cl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 170ULL);
x86_l_1ea0:
	/* 0x1ea0: test   cl,cl */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8, 0, 0);
x86_l_1ea2:
	/* 0x1ea2: je     381f <generic_retkprobe_event+0x381f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1ea2, 0x381f, x86_l_381f);
x86_l_1ea8:
	/* 0x1ea8: movzx  ecx,BYTE PTR [rax+0x7] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_1eac:
	/* 0x1eac: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1eb1:
	/* 0x1eb1: mov    BYTE PTR [rdx+0xab],cl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 171ULL);
x86_l_1eb7:
	/* 0x1eb7: test   cl,cl */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8, 0, 0);
x86_l_1eb9:
	/* 0x1eb9: je     381f <generic_retkprobe_event+0x381f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1eb9, 0x381f, x86_l_381f);
x86_l_1ebf:
	/* 0x1ebf: movzx  ecx,BYTE PTR [rax+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_1ec3:
	/* 0x1ec3: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ec8:
	/* 0x1ec8: mov    BYTE PTR [rdx+0xac],cl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_1ece:
	/* 0x1ece: test   cl,cl */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8, 0, 0);
x86_l_1ed0:
	/* 0x1ed0: je     381f <generic_retkprobe_event+0x381f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1ed0, 0x381f, x86_l_381f);
x86_l_1ed6:
	/* 0x1ed6: movzx  ecx,BYTE PTR [rax+0x9] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 9ULL);
x86_l_1eda:
	/* 0x1eda: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1edf:
	/* 0x1edf: mov    BYTE PTR [rdx+0xad],cl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 173ULL);
x86_l_1ee5:
	/* 0x1ee5: test   cl,cl */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8, 0, 0);
x86_l_1ee7:
	/* 0x1ee7: je     381f <generic_retkprobe_event+0x381f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1ee7, 0x381f, x86_l_381f);
x86_l_1eed:
	/* 0x1eed: movzx  ecx,BYTE PTR [rax+0xa] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 10ULL);
x86_l_1ef1:
	/* 0x1ef1: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ef6:
	/* 0x1ef6: mov    BYTE PTR [rdx+0xae],cl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 174ULL);
x86_l_1efc:
	/* 0x1efc: test   cl,cl */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8, 0, 0);
x86_l_1efe:
	/* 0x1efe: je     381f <generic_retkprobe_event+0x381f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1efe, 0x381f, x86_l_381f);
x86_l_1f04:
	/* 0x1f04: movzx  ecx,BYTE PTR [rax+0xb] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 11ULL);
x86_l_1f08:
	/* 0x1f08: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f0d:
	/* 0x1f0d: mov    BYTE PTR [rdx+0xaf],cl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 175ULL);
x86_l_1f13:
	/* 0x1f13: test   cl,cl */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8, 0, 0);
x86_l_1f15:
	/* 0x1f15: je     381f <generic_retkprobe_event+0x381f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1f15, 0x381f, x86_l_381f);
x86_l_1f1b:
	/* 0x1f1b: movzx  ecx,BYTE PTR [rax+0xc] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 12ULL);
x86_l_1f1f:
	/* 0x1f1f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f24:
	/* 0x1f24: mov    BYTE PTR [rdx+0xb0],cl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1f2a:
	/* 0x1f2a: test   cl,cl */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8, 0, 0);
x86_l_1f2c:
	/* 0x1f2c: je     381f <generic_retkprobe_event+0x381f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1f2c, 0x381f, x86_l_381f);
x86_l_1f32:
	/* 0x1f32: movzx  ecx,BYTE PTR [rax+0xd] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 13ULL);
x86_l_1f36:
	/* 0x1f36: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f3b:
	/* 0x1f3b: mov    BYTE PTR [rdx+0xb1],cl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 177ULL);
x86_l_1f41:
	/* 0x1f41: test   cl,cl */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8, 0, 0);
x86_l_1f43:
	/* 0x1f43: je     381f <generic_retkprobe_event+0x381f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1f43, 0x381f, x86_l_381f);
x86_l_1f49:
	/* 0x1f49: movzx  eax,BYTE PTR [rax+0xe] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 14ULL);
x86_l_1f4d:
	/* 0x1f4d: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f52:
	/* 0x1f52: mov    BYTE PTR [rcx+0xb2],al */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 178ULL);
x86_l_1f58:
	/* 0x1f58: test   al,al */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8, 0, 0);
x86_l_1f5a:
	/* 0x1f5a: je     381f <generic_retkprobe_event+0x381f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1f5a, 0x381f, x86_l_381f);
x86_l_1f60:
	/* 0x1f60: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f65:
	/* 0x1f65: mov    BYTE PTR [rcx+0xb3],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 768799145984ULL);
x86_l_1f6c:
	/* 0x1f6c: mov    r14,QWORD PTR [rsp] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f70:
	/* 0x1f70: jmp    3828 <generic_retkprobe_event+0x3828> */
	X86_SIM_X86_JMP(0x1f70, 0x3828, x86_l_3828);
x86_l_1f75:
	/* 0x1f75: mov    QWORD PTR [rdx+0x8],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1f7d:
	/* 0x1f7d: mov    QWORD PTR [rdx],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f84:
	/* 0x1f84: mov    r12d,0x18 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 24ULL);
x86_l_1f8a:
	/* 0x1f8a: jmp    381f <generic_retkprobe_event+0x381f> */
	X86_SIM_X86_JMP(0x1f8a, 0x381f, x86_l_381f);
x86_l_1f8f:
	/* 0x1f8f: lea    rdi,[rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1f94:
	/* 0x1f94: mov    esi,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_1f99:
	/* 0x1f99: mov    rdx,r13 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_1f9c:
	/* 0x1f9c: call   1fa1 <generic_retkprobe_event+0x1fa1> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_1fa1:
	/* 0x1fa1: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_1fa4:
	/* 0x1fa4: js     4159 <generic_retkprobe_event+0x4159> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1fa4, 0x4159, x86_l_4159);
x86_l_1faa:
	/* 0x1faa: cmp    BYTE PTR [rsp+0x40],0x0 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_1faf:
	/* 0x1faf: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1fb4:
	/* 0x1fb4: sete   BYTE PTR [rax+0x9e] */
	X86_SIM_RUN_OP(X86_OP_SETCC_MEM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_REG_AUX_SRC_SHIFT(X86_CC_E)), 158ULL);
x86_l_1fbb:
	/* 0x1fbb: je     3090 <generic_retkprobe_event+0x3090> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1fbb, 0x3090, x86_l_3090);
x86_l_1fc1:
	/* 0x1fc1: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1fc6:
	/* 0x1fc6: add    rdi,0xa0 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 160ULL);
x86_l_1fcd:
	/* 0x1fcd: mov    esi,0x6c */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 108ULL);
x86_l_1fd2:
	/* 0x1fd2: mov    rdx,r13 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_1fd5:
	/* 0x1fd5: call   1fda <generic_retkprobe_event+0x1fda> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read_str);
x86_l_1fda:
	/* 0x1fda: test   eax,eax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_1fdc:
	/* 0x1fdc: mov    r14,QWORD PTR [rsp] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1fe0:
	/* 0x1fe0: jns    414c <generic_retkprobe_event+0x414c> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1fe0, 0x414c, x86_l_414c);
x86_l_1fe6:
	/* 0x1fe6: jmp    4159 <generic_retkprobe_event+0x4159> */
	X86_SIM_X86_JMP(0x1fe6, 0x4159, x86_l_4159);
x86_l_1feb:
	/* 0x1feb: mov    rax,rbp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_1fee:
	/* 0x1fee: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_1ff1:
	/* 0x1ff1: jns    2f2a <generic_retkprobe_event+0x2f2a> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1ff1, 0x2f2a, x86_l_2f2a);
x86_l_1ff7:
	/* 0x1ff7: mov    eax,DWORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ff9:
	/* 0x1ff9: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1ffe:
	/* 0x1ffe: mov    DWORD PTR [rcx],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2000:
	/* 0x2000: jmp    2f35 <generic_retkprobe_event+0x2f35> */
	X86_SIM_X86_JMP(0x2000, 0x2f35, x86_l_2f35);
x86_l_2005:
	/* 0x2005: xor    r12d,r12d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_2008:
	/* 0x2008: jmp    3823 <generic_retkprobe_event+0x3823> */
	X86_SIM_X86_JMP(0x2008, 0x3823, x86_l_3823);
x86_l_200d:
	/* 0x200d: mov    QWORD PTR [r13+0x9c],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_2018:
	/* 0x2018: mov    r12d,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_201e:
	/* 0x201e: jmp    3d29 <generic_retkprobe_event+0x3d29> */
	X86_SIM_X86_JMP(0x201e, 0x3d29, x86_l_3d29);
x86_l_2023:
	/* 0x2023: mov    ecx,0xfffffffe */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 4294967294ULL);
x86_l_2028:
	/* 0x2028: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_202b:
	/* 0x202b: jns    3c7e <generic_retkprobe_event+0x3c7e> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x202b, 0x3c7e, x86_l_3c7e);
x86_l_2031:
	/* 0x2031: mov    rax,QWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2034:
	/* 0x2034: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2039:
	/* 0x2039: mov    rbp,QWORD PTR [rdx+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_203d:
	/* 0x203d: mov    QWORD PTR [rsp+0x48],rbp */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2042:
	/* 0x2042: mov    rax,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_2045:
	/* 0x2045: cmp    rbp,r12 */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RBP, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_2048:
	/* 0x2048: mov    r14,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R14, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_204b:
	/* 0x204b: cmovb  r14,rbp */
	X86_SIM_RUN_OP(X86_OP_CMOV, X86_R14, X86_RBP, X86_WIDTH_64, X86_CC_B, 0);
x86_l_204f:
	/* 0x204f: test   r12,r12 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_2052:
	/* 0x2052: cmovne rbp,r14 */
	X86_SIM_RUN_OP(X86_OP_CMOV, X86_RBP, X86_R14, X86_WIDTH_64, X86_CC_NE, 0);
x86_l_2056:
	/* 0x2056: mov    ecx,0xfffffffd */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 4294967293ULL);
x86_l_205b:
	/* 0x205b: cmp    rbp,0xffe */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, 0, 4094ULL);
x86_l_2062:
	/* 0x2062: ja     3c7e <generic_retkprobe_event+0x3c7e> */
	X86_SIM_X86_JCC(X86_CC_A, 0x2062, 0x3c7e, x86_l_3c7e);
x86_l_2068:
	/* 0x2068: add    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_RUN_OP(X86_OP_ALU_MEM, X86_R13, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_206d:
	/* 0x206d: mov    edi,r13d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_R13, X86_WIDTH_32, 0, 0);
x86_l_2070:
	/* 0x2070: and    edi,0x3fff */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2076:
	/* 0x2076: add    rdi,QWORD PTR [rsp] */
	X86_SIM_RUN_OP(X86_OP_ALU_MEM, X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_207a:
	/* 0x207a: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_207f:
	/* 0x207f: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_2082:
	/* 0x2082: jns    3384 <generic_retkprobe_event+0x3384> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2082, 0x3384, x86_l_3384);
x86_l_2088:
	/* 0x2088: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_208b:
	/* 0x208b: jns    3c6f <generic_retkprobe_event+0x3c6f> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x208b, 0x3c6f, x86_l_3c6f);
x86_l_2091:
	/* 0x2091: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_2093:
	/* 0x2093: cmp    ebp,0x8 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_2096:
	/* 0x2096: jb     20b0 <generic_retkprobe_event+0x20b0> */
	X86_SIM_X86_JCC(X86_CC_B, 0x2096, 0x20b0, x86_l_20b0);
x86_l_2098:
	/* 0x2098: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_209a:
	/* 0x209a: mov    eax,ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_209c:
	/* 0x209c: mov    rsi,QWORD PTR [rdx+rax*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_20a0:
	/* 0x20a0: mov    QWORD PTR [rdi+rax*1],rsi */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_20a4:
	/* 0x20a4: lea    eax,[rcx+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20a7:
	/* 0x20a7: add    ecx,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 16ULL);
x86_l_20aa:
	/* 0x20aa: cmp    ecx,ebp */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_32, 0, 0);
x86_l_20ac:
	/* 0x20ac: mov    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_20ae:
	/* 0x20ae: jbe    209a <generic_retkprobe_event+0x209a> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x20ae, 0x209a, x86_l_209a);
x86_l_20b0:
	/* 0x20b0: test   bpl,0x4 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, 0, 4ULL);
x86_l_20b4:
	/* 0x20b4: jne    4173 <generic_retkprobe_event+0x4173> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x20b4, 0x4173, x86_l_4173);
x86_l_20ba:
	/* 0x20ba: test   bpl,0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, 0, 2ULL);
x86_l_20be:
	/* 0x20be: jne    4188 <generic_retkprobe_event+0x4188> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x20be, 0x4188, x86_l_4188);
x86_l_20c4:
	/* 0x20c4: test   bpl,0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_20c8:
	/* 0x20c8: jne    419b <generic_retkprobe_event+0x419b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x20c8, 0x419b, x86_l_419b);
x86_l_20ce:
	/* 0x20ce: jmp    41a4 <generic_retkprobe_event+0x41a4> */
	X86_SIM_X86_JMP(0x20ce, 0x41a4, x86_l_41a4);
x86_l_20d3:
	/* 0x20d3: mov    WORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20d8:
	/* 0x20d8: lea    rdi,[rcx+0xd6] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 214ULL);
x86_l_20df:
	/* 0x20df: mov    rdx,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_20e2:
	/* 0x20e2: add    rdx,0x12 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 18ULL);
x86_l_20e6:
	/* 0x20e6: jns    20f4 <generic_retkprobe_event+0x20f4> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x20e6, 0x20f4, x86_l_20f4);
x86_l_20e8:
	/* 0x20e8: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_20eb:
	/* 0x20eb: jns    2105 <generic_retkprobe_event+0x2105> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x20eb, 0x2105, x86_l_2105);
x86_l_20ed:
	/* 0x20ed: movzx  eax,BYTE PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_20f0:
	/* 0x20f0: mov    BYTE PTR [rdi],al */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20f2:
	/* 0x20f2: jmp    2108 <generic_retkprobe_event+0x2108> */
	X86_SIM_X86_JMP(0x20f2, 0x2108, x86_l_2108);
x86_l_20f4:
	/* 0x20f4: mov    esi,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_20f9:
	/* 0x20f9: call   20fe <generic_retkprobe_event+0x20fe> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_20fe:
	/* 0x20fe: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2103:
	/* 0x2103: jmp    2108 <generic_retkprobe_event+0x2108> */
	X86_SIM_X86_JMP(0x2103, 0x2108, x86_l_2108);
x86_l_2105:
	/* 0x2105: mov    BYTE PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2108:
	/* 0x2108: lea    rdi,[rcx+0xd4] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 212ULL);
x86_l_210f:
	/* 0x210f: mov    rdx,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_2112:
	/* 0x2112: add    rdx,0x21e */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 542ULL);
x86_l_2119:
	/* 0x2119: jns    2128 <generic_retkprobe_event+0x2128> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2119, 0x2128, x86_l_2128);
x86_l_211b:
	/* 0x211b: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_211e:
	/* 0x211e: jns    2139 <generic_retkprobe_event+0x2139> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x211e, 0x2139, x86_l_2139);
x86_l_2120:
	/* 0x2120: movzx  eax,WORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2123:
	/* 0x2123: mov    WORD PTR [rdi],ax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2126:
	/* 0x2126: jmp    213e <generic_retkprobe_event+0x213e> */
	X86_SIM_X86_JMP(0x2126, 0x213e, x86_l_213e);
x86_l_2128:
	/* 0x2128: mov    esi,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_212d:
	/* 0x212d: call   2132 <generic_retkprobe_event+0x2132> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_2132:
	/* 0x2132: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2137:
	/* 0x2137: jmp    213e <generic_retkprobe_event+0x213e> */
	X86_SIM_X86_JMP(0x2137, 0x213e, x86_l_213e);
x86_l_2139:
	/* 0x2139: mov    WORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_213e:
	/* 0x213e: lea    rdi,[rcx+0xc0] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_2145:
	/* 0x2145: mov    rdx,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_2148:
	/* 0x2148: add    rdx,0x21c */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 540ULL);
x86_l_214f:
	/* 0x214f: jns    215e <generic_retkprobe_event+0x215e> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x214f, 0x215e, x86_l_215e);
x86_l_2151:
	/* 0x2151: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_2154:
	/* 0x2154: jns    216f <generic_retkprobe_event+0x216f> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2154, 0x216f, x86_l_216f);
x86_l_2156:
	/* 0x2156: movzx  eax,WORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2159:
	/* 0x2159: mov    WORD PTR [rdi],ax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_215c:
	/* 0x215c: jmp    2174 <generic_retkprobe_event+0x2174> */
	X86_SIM_X86_JMP(0x215c, 0x2174, x86_l_2174);
x86_l_215e:
	/* 0x215e: mov    esi,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_2163:
	/* 0x2163: call   2168 <generic_retkprobe_event+0x2168> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_2168:
	/* 0x2168: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_216d:
	/* 0x216d: jmp    2174 <generic_retkprobe_event+0x2174> */
	X86_SIM_X86_JMP(0x216d, 0x2174, x86_l_2174);
x86_l_216f:
	/* 0x216f: mov    WORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2174:
	/* 0x2174: lea    rdi,[rcx+0xcc] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_217b:
	/* 0x217b: mov    rdx,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_217e:
	/* 0x217e: add    rdx,0x214 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 532ULL);
x86_l_2185:
	/* 0x2185: jns    2192 <generic_retkprobe_event+0x2192> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2185, 0x2192, x86_l_2192);
x86_l_2187:
	/* 0x2187: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_218a:
	/* 0x218a: jns    21a3 <generic_retkprobe_event+0x21a3> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x218a, 0x21a3, x86_l_21a3);
x86_l_218c:
	/* 0x218c: mov    eax,DWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_218e:
	/* 0x218e: mov    DWORD PTR [rdi],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2190:
	/* 0x2190: jmp    21a9 <generic_retkprobe_event+0x21a9> */
	X86_SIM_X86_JMP(0x2190, 0x21a9, x86_l_21a9);
x86_l_2192:
	/* 0x2192: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_2197:
	/* 0x2197: call   219c <generic_retkprobe_event+0x219c> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_219c:
	/* 0x219c: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_21a1:
	/* 0x21a1: jmp    21a9 <generic_retkprobe_event+0x21a9> */
	X86_SIM_X86_JMP(0x21a1, 0x21a9, x86_l_21a9);
x86_l_21a3:
	/* 0x21a3: mov    DWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21a9:
	/* 0x21a9: lea    rdi,[rcx+0xd0] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_21b0:
	/* 0x21b0: mov    rdx,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_21b3:
	/* 0x21b3: add    rdx,0x210 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 528ULL);
x86_l_21ba:
	/* 0x21ba: jns    21c7 <generic_retkprobe_event+0x21c7> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x21ba, 0x21c7, x86_l_21c7);
x86_l_21bc:
	/* 0x21bc: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_21bf:
	/* 0x21bf: jns    21d8 <generic_retkprobe_event+0x21d8> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x21bf, 0x21d8, x86_l_21d8);
x86_l_21c1:
	/* 0x21c1: mov    eax,DWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21c3:
	/* 0x21c3: mov    DWORD PTR [rdi],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21c5:
	/* 0x21c5: jmp    21de <generic_retkprobe_event+0x21de> */
	X86_SIM_X86_JMP(0x21c5, 0x21de, x86_l_21de);
x86_l_21c7:
	/* 0x21c7: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_21cc:
	/* 0x21cc: call   21d1 <generic_retkprobe_event+0x21d1> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_21d1:
	/* 0x21d1: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_21d6:
	/* 0x21d6: jmp    21de <generic_retkprobe_event+0x21de> */
	X86_SIM_X86_JMP(0x21d6, 0x21de, x86_l_21de);
x86_l_21d8:
	/* 0x21d8: mov    DWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21de:
	/* 0x21de: lea    r13,[rcx+0xac] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R13, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_21e5:
	/* 0x21e5: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_21ea:
	/* 0x21ea: mov    QWORD PTR [rax+0x18],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_21f2:
	/* 0x21f2: mov    QWORD PTR [rax+0x10],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_21fa:
	/* 0x21fa: mov    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_2202:
	/* 0x2202: mov    QWORD PTR [rax],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2209:
	/* 0x2209: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_220e:
	/* 0x220e: movzx  eax,WORD PTR [rax+0xc2] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 194ULL);
x86_l_2215:
	/* 0x2215: cmp    eax,0xa */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 10ULL);
x86_l_2218:
	/* 0x2218: je     2247 <generic_retkprobe_event+0x2247> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2218, 0x2247, x86_l_2247);
x86_l_221a:
	/* 0x221a: cmp    eax,0x2 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_221d:
	/* 0x221d: jne    35d0 <generic_retkprobe_event+0x35d0> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x221d, 0x35d0, x86_l_35d0);
x86_l_2223:
	/* 0x2223: mov    rdx,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_2226:
	/* 0x2226: add    rdx,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_222a:
	/* 0x222a: jns    2df2 <generic_retkprobe_event+0x2df2> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x222a, 0x2df2, x86_l_2df2);
x86_l_2230:
	/* 0x2230: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_2233:
	/* 0x2233: jns    354b <generic_retkprobe_event+0x354b> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2233, 0x354b, x86_l_354b);
x86_l_2239:
	/* 0x2239: mov    eax,DWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_223b:
	/* 0x223b: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2240:
	/* 0x2240: mov    DWORD PTR [rcx],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2242:
	/* 0x2242: jmp    3556 <generic_retkprobe_event+0x3556> */
	X86_SIM_X86_JMP(0x2242, 0x3556, x86_l_3556);
x86_l_2247:
	/* 0x2247: mov    rdx,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_224a:
	/* 0x224a: add    rdx,0x48 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 72ULL);
x86_l_224e:
	/* 0x224e: jns    2e06 <generic_retkprobe_event+0x2e06> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x224e, 0x2e06, x86_l_2e06);
x86_l_2254:
	/* 0x2254: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_2257:
	/* 0x2257: jns    357c <generic_retkprobe_event+0x357c> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2257, 0x357c, x86_l_357c);
x86_l_225d:
	/* 0x225d: mov    rax,QWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2260:
	/* 0x2260: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2265:
	/* 0x2265: mov    QWORD PTR [rcx+0x9c],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_226c:
	/* 0x226c: mov    rax,QWORD PTR [rdx+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2270:
	/* 0x2270: mov    QWORD PTR [rcx+0xa4],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_2277:
	/* 0x2277: jmp    3590 <generic_retkprobe_event+0x3590> */
	X86_SIM_X86_JMP(0x2277, 0x3590, x86_l_3590);
x86_l_227c:
	/* 0x227c: mov    edx,esi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_227e:
	/* 0x227e: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2283:
	/* 0x2283: jmp    2649 <generic_retkprobe_event+0x2649> */
	X86_SIM_X86_JMP(0x2283, 0x2649, x86_l_2649);
x86_l_2288:
	/* 0x2288: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_2291:
	/* 0x2291: xor    edx,edx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_2293:
	/* 0x2293: lea    rdi,[rsp+0x20] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2298:
	/* 0x2298: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_229d:
	/* 0x229d: call   22a2 <generic_retkprobe_event+0x22a2> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_22a2:
	/* 0x22a2: jmp    25d6 <generic_retkprobe_event+0x25d6> */
	X86_SIM_X86_JMP(0x22a2, 0x25d6, x86_l_25d6);
x86_l_22a7:
	/* 0x22a7: mov    DWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22ad:
	/* 0x22ad: lea    rdi,[rcx+0xc8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_22b4:
	/* 0x22b4: mov    rdx,r14 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_22b7:
	/* 0x22b7: add    rdx,0x70 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 112ULL);
x86_l_22bb:
	/* 0x22bb: jns    22c8 <generic_retkprobe_event+0x22c8> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x22bb, 0x22c8, x86_l_22c8);
x86_l_22bd:
	/* 0x22bd: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_22c0:
	/* 0x22c0: jns    22d9 <generic_retkprobe_event+0x22d9> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x22c0, 0x22d9, x86_l_22d9);
x86_l_22c2:
	/* 0x22c2: mov    eax,DWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22c4:
	/* 0x22c4: mov    DWORD PTR [rdi],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22c6:
	/* 0x22c6: jmp    22df <generic_retkprobe_event+0x22df> */
	X86_SIM_X86_JMP(0x22c6, 0x22df, x86_l_22df);
x86_l_22c8:
	/* 0x22c8: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_22cd:
	/* 0x22cd: call   22d2 <generic_retkprobe_event+0x22d2> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_22d2:
	/* 0x22d2: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22d7:
	/* 0x22d7: jmp    22df <generic_retkprobe_event+0x22df> */
	X86_SIM_X86_JMP(0x22d7, 0x22df, x86_l_22df);
x86_l_22d9:
	/* 0x22d9: mov    DWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22df:
	/* 0x22df: lea    rdi,[rcx+0xcc] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_22e6:
	/* 0x22e6: mov    rdx,r14 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_22e9:
	/* 0x22e9: add    rdx,0x90 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_22f0:
	/* 0x22f0: jns    22fd <generic_retkprobe_event+0x22fd> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x22f0, 0x22fd, x86_l_22fd);
x86_l_22f2:
	/* 0x22f2: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_22f5:
	/* 0x22f5: jns    230e <generic_retkprobe_event+0x230e> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x22f5, 0x230e, x86_l_230e);
x86_l_22f7:
	/* 0x22f7: mov    eax,DWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22f9:
	/* 0x22f9: mov    DWORD PTR [rdi],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22fb:
	/* 0x22fb: jmp    2314 <generic_retkprobe_event+0x2314> */
	X86_SIM_X86_JMP(0x22fb, 0x2314, x86_l_2314);
x86_l_22fd:
	/* 0x22fd: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_2302:
	/* 0x2302: call   2307 <generic_retkprobe_event+0x2307> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_2307:
	/* 0x2307: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_230c:
	/* 0x230c: jmp    2314 <generic_retkprobe_event+0x2314> */
	X86_SIM_X86_JMP(0x230c, 0x2314, x86_l_2314);
x86_l_230e:
	/* 0x230e: mov    DWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2314:
	/* 0x2314: lea    rdi,[rcx+0xd0] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_231b:
	/* 0x231b: mov    rdx,r14 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_231e:
	/* 0x231e: add    rdx,0xa8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 168ULL);
x86_l_2325:
	/* 0x2325: jns    2332 <generic_retkprobe_event+0x2332> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2325, 0x2332, x86_l_2332);
x86_l_2327:
	/* 0x2327: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_232a:
	/* 0x232a: jns    233e <generic_retkprobe_event+0x233e> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x232a, 0x233e, x86_l_233e);
x86_l_232c:
	/* 0x232c: mov    eax,DWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_232e:
	/* 0x232e: mov    DWORD PTR [rdi],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2330:
	/* 0x2330: jmp    2344 <generic_retkprobe_event+0x2344> */
	X86_SIM_X86_JMP(0x2330, 0x2344, x86_l_2344);
x86_l_2332:
	/* 0x2332: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_2337:
	/* 0x2337: call   233c <generic_retkprobe_event+0x233c> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_233c:
	/* 0x233c: jmp    2344 <generic_retkprobe_event+0x2344> */
	X86_SIM_X86_JMP(0x233c, 0x2344, x86_l_2344);
x86_l_233e:
	/* 0x233e: mov    DWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2344:
	/* 0x2344: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_234d:
	/* 0x234d: mov    rdx,r14 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_2350:
	/* 0x2350: add    rdx,0xc8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 200ULL);
x86_l_2357:
	/* 0x2357: jns    2368 <generic_retkprobe_event+0x2368> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2357, 0x2368, x86_l_2368);
x86_l_2359:
	/* 0x2359: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_235c:
	/* 0x235c: jns    2379 <generic_retkprobe_event+0x2379> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x235c, 0x2379, x86_l_2379);
x86_l_235e:
	/* 0x235e: mov    rax,QWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2361:
	/* 0x2361: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2366:
	/* 0x2366: jmp    2382 <generic_retkprobe_event+0x2382> */
	X86_SIM_X86_JMP(0x2366, 0x2382, x86_l_2382);
x86_l_2368:
	/* 0x2368: lea    rdi,[rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_236d:
	/* 0x236d: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_2372:
	/* 0x2372: call   2377 <generic_retkprobe_event+0x2377> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_2377:
	/* 0x2377: jmp    2382 <generic_retkprobe_event+0x2382> */
	X86_SIM_X86_JMP(0x2377, 0x2382, x86_l_2382);
x86_l_2379:
	/* 0x2379: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_2382:
	/* 0x2382: mov    rdx,r14 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_2385:
	/* 0x2385: add    rdx,0xb8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 184ULL);
x86_l_238c:
	/* 0x238c: mov    QWORD PTR [rsp+0x30],r14 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2391:
	/* 0x2391: jns    23a5 <generic_retkprobe_event+0x23a5> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2391, 0x23a5, x86_l_23a5);
x86_l_2393:
	/* 0x2393: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_2396:
	/* 0x2396: jns    23c1 <generic_retkprobe_event+0x23c1> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2396, 0x23c1, x86_l_23c1);
x86_l_2398:
	/* 0x2398: movzx  eax,WORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_239b:
	/* 0x239b: mov    WORD PTR [rsp+0xa0],ax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_23a3:
	/* 0x23a3: jmp    23cd <generic_retkprobe_event+0x23cd> */
	X86_SIM_X86_JMP(0x23a3, 0x23cd, x86_l_23cd);
x86_l_23a5:
	/* 0x23a5: lea    rdi,[rsp+0xa0] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_23ad:
	/* 0x23ad: mov    esi,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_23b2:
	/* 0x23b2: call   23b7 <generic_retkprobe_event+0x23b7> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_23b7:
	/* 0x23b7: movzx  eax,WORD PTR [rsp+0xa0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 160ULL);
x86_l_23bf:
	/* 0x23bf: jmp    23cd <generic_retkprobe_event+0x23cd> */
	X86_SIM_X86_JMP(0x23bf, 0x23cd, x86_l_23cd);
x86_l_23c1:
	/* 0x23c1: mov    WORD PTR [rsp+0xa0],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_23cb:
	/* 0x23cb: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_23cd:
	/* 0x23cd: movzx  r12d,ax */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_23d1:
	/* 0x23d1: add    r12,QWORD PTR [rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_ALU_MEM, X86_R12, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 64ULL);
x86_l_23d6:
	/* 0x23d6: jns    23fa <generic_retkprobe_event+0x23fa> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x23d6, 0x23fa, x86_l_23fa);
x86_l_23d8:
	/* 0x23d8: mov    rax,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_23db:
	/* 0x23db: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_23de:
	/* 0x23de: mov    r14,QWORD PTR [rsp] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23e2:
	/* 0x23e2: mov    r13d,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_23e8:
	/* 0x23e8: jns    412c <generic_retkprobe_event+0x412c> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x23e8, 0x412c, x86_l_412c);
x86_l_23ee:
	/* 0x23ee: movzx  eax,BYTE PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_23f1:
	/* 0x23f1: mov    BYTE PTR [rsp+0xb8],al */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_23f8:
	/* 0x23f8: jmp    2417 <generic_retkprobe_event+0x2417> */
	X86_SIM_X86_JMP(0x23f8, 0x2417, x86_l_2417);
x86_l_23fa:
	/* 0x23fa: lea    rdi,[rsp+0xb8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_2402:
	/* 0x2402: mov    esi,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_2407:
	/* 0x2407: mov    rdx,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_240a:
	/* 0x240a: call   240f <generic_retkprobe_event+0x240f> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_240f:
	/* 0x240f: movzx  eax,BYTE PTR [rsp+0xb8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 184ULL);
x86_l_2417:
	/* 0x2417: shr    al,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_ALU_SHR, 4ULL);
x86_l_241a:
	/* 0x241a: cmp    al,0x6 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, 0, 6ULL);
x86_l_241c:
	/* 0x241c: je     2459 <generic_retkprobe_event+0x2459> */
	X86_SIM_X86_JCC(X86_CC_E, 0x241c, 0x2459, x86_l_2459);
x86_l_241e:
	/* 0x241e: movzx  eax,al */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8, 0);
x86_l_2421:
	/* 0x2421: cmp    eax,0x4 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_2424:
	/* 0x2424: mov    r14,QWORD PTR [rsp] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2428:
	/* 0x2428: mov    r13d,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_242e:
	/* 0x242e: jne    412c <generic_retkprobe_event+0x412c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x242e, 0x412c, x86_l_412c);
x86_l_2434:
	/* 0x2434: mov    rdx,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_2437:
	/* 0x2437: add    rdx,0x9 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 9ULL);
x86_l_243b:
	/* 0x243b: jns    3071 <generic_retkprobe_event+0x3071> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x243b, 0x3071, x86_l_3071);
x86_l_2441:
	/* 0x2441: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_2444:
	/* 0x2444: jns    3867 <generic_retkprobe_event+0x3867> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2444, 0x3867, x86_l_3867);
x86_l_244a:
	/* 0x244a: movzx  eax,BYTE PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_244d:
	/* 0x244d: mov    BYTE PTR [rsp+0x80],al */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2454:
	/* 0x2454: jmp    3871 <generic_retkprobe_event+0x3871> */
	X86_SIM_X86_JMP(0x2454, 0x3871, x86_l_3871);
x86_l_2459:
	/* 0x2459: mov    r14,QWORD PTR [rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_245e:
	/* 0x245e: movzx  r15d,WORD PTR [rsp+0xa0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 160ULL);
x86_l_2467:
	/* 0x2467: lea    rax,[r14+r15*1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_246b:
	/* 0x246b: mov    QWORD PTR [rsp+0x98],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2473:
	/* 0x2473: mov    DWORD PTR [rsp+0x80],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_247e:
	/* 0x247e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)tg_ipv6_ext_heap));
x86_l_2485:
	/* 0x2485: lea    rsi,[rsp+0x80] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_248d:
	/* 0x248d: call   2492 <generic_retkprobe_event+0x2492> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_2492:
	/* 0x2492: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_2495:
	/* 0x2495: je     3eeb <generic_retkprobe_event+0x3eeb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2495, 0x3eeb, x86_l_3eeb);
x86_l_249b:
	/* 0x249b: mov    r13,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R13, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_249e:
	/* 0x249e: mov    WORD PTR [rax],r15w */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RAX, X86_R15, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24a2:
	/* 0x24a2: mov    BYTE PTR [rax+0x5],0xff */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 21474836735ULL);
x86_l_24a6:
	/* 0x24a6: mov    BYTE PTR [rax+0x7],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 30064771072ULL);
x86_l_24aa:
	/* 0x24aa: mov    rbp,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RBP, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_24ad:
	/* 0x24ad: add    rbp,0x6 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 6ULL);
x86_l_24b1:
	/* 0x24b1: mov    rdx,QWORD PTR [rsp+0x98] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_24b9:
	/* 0x24b9: add    rdx,0x6 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 6ULL);
x86_l_24bd:
	/* 0x24bd: jns    36a0 <generic_retkprobe_event+0x36a0> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x24bd, 0x36a0, x86_l_36a0);
x86_l_24c3:
	/* 0x24c3: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_24c6:
	/* 0x24c6: jns    3cbb <generic_retkprobe_event+0x3cbb> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x24c6, 0x3cbb, x86_l_3cbb);
x86_l_24cc:
	/* 0x24cc: movzx  eax,BYTE PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_24cf:
	/* 0x24cf: mov    BYTE PTR [rbp+0x0],al */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24d2:
	/* 0x24d2: jmp    36b6 <generic_retkprobe_event+0x36b6> */
	X86_SIM_X86_JMP(0x24d2, 0x36b6, x86_l_36b6);
x86_l_24d7:
	/* 0x24d7: mov    DWORD PTR [rsp+0x80],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_24e2:
	/* 0x24e2: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_24e4:
	/* 0x24e4: mov    DWORD PTR [rsp+0x48],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_24e8:
	/* 0x24e8: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)fdinstall_map));
x86_l_24ef:
	/* 0x24ef: lea    rsi,[rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_24f4:
	/* 0x24f4: call   24f9 <generic_retkprobe_event+0x24f9> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_24f9:
	/* 0x24f9: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_24fc:
	/* 0x24fc: je     2528 <generic_retkprobe_event+0x2528> */
	X86_SIM_X86_JCC(X86_CC_E, 0x24fc, 0x2528, x86_l_2528);
x86_l_24fe:
	/* 0x24fe: mov    r13,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R13, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_2501:
	/* 0x2501: mov    r14d,DWORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2504:
	/* 0x2504: lea    rax,[rsp+0x80] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_250c:
	/* 0x250c: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_250f:
	/* 0x250f: jns    2534 <generic_retkprobe_event+0x2534> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x250f, 0x2534, x86_l_2534);
x86_l_2511:
	/* 0x2511: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_2514:
	/* 0x2514: jns    2e1a <generic_retkprobe_event+0x2e1a> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2514, 0x2e1a, x86_l_2e1a);
x86_l_251a:
	/* 0x251a: mov    eax,DWORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_251c:
	/* 0x251c: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2521:
	/* 0x2521: mov    DWORD PTR [rcx],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2523:
	/* 0x2523: jmp    2e25 <generic_retkprobe_event+0x2e25> */
	X86_SIM_X86_JMP(0x2523, 0x2e25, x86_l_2e25);
x86_l_2528:
	/* 0x2528: mov    r12,0xffffffffffffffff */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, 0, 18446744073709551615ULL);
x86_l_252f:
	/* 0x252f: jmp    3d29 <generic_retkprobe_event+0x3d29> */
	X86_SIM_X86_JMP(0x252f, 0x3d29, x86_l_3d29);
x86_l_2534:
	/* 0x2534: lea    rdx,[rsp+0x80] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_253c:
	/* 0x253c: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2541:
	/* 0x2541: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_2546:
	/* 0x2546: call   254b <generic_retkprobe_event+0x254b> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_254b:
	/* 0x254b: jmp    2e25 <generic_retkprobe_event+0x2e25> */
	X86_SIM_X86_JMP(0x254b, 0x2e25, x86_l_2e25);
x86_l_2550:
	/* 0x2550: mov    BYTE PTR [rdi+0x10],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2554:
	/* 0x2554: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_255c:
	/* 0x255c: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2563:
	/* 0x2563: mov    r12,0xffffffffffffffde */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, 0, 18446744073709551582ULL);
x86_l_256a:
	/* 0x256a: mov    r14,QWORD PTR [rsp] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_256e:
	/* 0x256e: jmp    3d33 <generic_retkprobe_event+0x3d33> */
	X86_SIM_X86_JMP(0x256e, 0x3d33, x86_l_3d33);
x86_l_2573:
	/* 0x2573: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2578:
	/* 0x2578: lea    rdi,[rax+0xa4] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_257f:
	/* 0x257f: mov    rdx,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_2582:
	/* 0x2582: add    rdx,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2586:
	/* 0x2586: jns    331d <generic_retkprobe_event+0x331d> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2586, 0x331d, x86_l_331d);
x86_l_258c:
	/* 0x258c: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_258f:
	/* 0x258f: jns    3b79 <generic_retkprobe_event+0x3b79> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x258f, 0x3b79, x86_l_3b79);
x86_l_2595:
	/* 0x2595: mov    rax,QWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2598:
	/* 0x2598: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_259d:
	/* 0x259d: mov    QWORD PTR [rcx+0xa4],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_25a4:
	/* 0x25a4: mov    rax,QWORD PTR [rdx+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_25a8:
	/* 0x25a8: mov    QWORD PTR [rcx+0xac],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_25af:
	/* 0x25af: jmp    3b88 <generic_retkprobe_event+0x3b88> */
	X86_SIM_X86_JMP(0x25af, 0x3b88, x86_l_3b88);
x86_l_25b4:
	/* 0x25b4: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_25b9:
	/* 0x25b9: mov    WORD PTR [rax],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_25be:
	/* 0x25be: mov    r14,QWORD PTR [rsp] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_25c2:
	/* 0x25c2: mov    r12d,0x18 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 24ULL);
x86_l_25c8:
	/* 0x25c8: jmp    3d33 <generic_retkprobe_event+0x3d33> */
	X86_SIM_X86_JMP(0x25c8, 0x3d33, x86_l_3d33);
x86_l_25cd:
	/* 0x25cd: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_25d6:
	/* 0x25d6: mov    r14,QWORD PTR [rsp] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_25da:
	/* 0x25da: mov    r13d,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_25e0:
	/* 0x25e0: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_25e5:
	/* 0x25e5: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_25ea:
	/* 0x25ea: add    rdi,0xa0 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 160ULL);
x86_l_25f1:
	/* 0x25f1: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_25f4:
	/* 0x25f4: js     2621 <generic_retkprobe_event+0x2621> */
	X86_SIM_X86_JCC(X86_CC_S, 0x25f4, 0x2621, x86_l_2621);
x86_l_25f6:
	/* 0x25f6: mov    esi,0x1001 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4097ULL);
x86_l_25fb:
	/* 0x25fb: call   2600 <generic_retkprobe_event+0x2600> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read_str);
x86_l_2600:
	/* 0x2600: mov    r12,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R12, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_2603:
	/* 0x2603: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_2606:
	/* 0x2606: js     3d33 <generic_retkprobe_event+0x3d33> */
	X86_SIM_X86_JCC(X86_CC_S, 0x2606, 0x3d33, x86_l_3d33);
x86_l_260c:
	/* 0x260c: lea    eax,[r12-0x1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2611:
	/* 0x2611: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2616:
	/* 0x2616: mov    DWORD PTR [rcx],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2618:
	/* 0x2618: add    r12,0x3 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 3ULL);
x86_l_261c:
	/* 0x261c: jmp    3d33 <generic_retkprobe_event+0x3d33> */
	X86_SIM_X86_JMP(0x261c, 0x3d33, x86_l_3d33);
x86_l_2621:
	/* 0x2621: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_2624:
	/* 0x2624: jns    2644 <generic_retkprobe_event+0x2644> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2624, 0x2644, x86_l_2644);
x86_l_2626:
	/* 0x2626: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_2628:
	/* 0x2628: cmp    rax,0x1000 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, 0, 4096ULL);
x86_l_262e:
	/* 0x262e: je     265c <generic_retkprobe_event+0x265c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x262e, 0x265c, x86_l_265c);
x86_l_2630:
	/* 0x2630: lea    r12,[rax+0x1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2634:
	/* 0x2634: movzx  ecx,BYTE PTR [rdx+rax*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2638:
	/* 0x2638: mov    BYTE PTR [rdi+rax*1],cl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_263b:
	/* 0x263b: mov    rax,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_263e:
	/* 0x263e: test   cl,cl */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8, 0, 0);
x86_l_2640:
	/* 0x2640: jne    2628 <generic_retkprobe_event+0x2628> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2640, 0x2628, x86_l_2628);
x86_l_2642:
	/* 0x2642: jmp    260c <generic_retkprobe_event+0x260c> */
	X86_SIM_X86_JMP(0x2642, 0x260c, x86_l_260c);
x86_l_2644:
	/* 0x2644: mov    edx,0x1001 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 4097ULL);
x86_l_2649:
	/* 0x2649: xor    esi,esi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_264b:
	/* 0x264b: call   47c5 <__native_link_local_memset_zero_dynamic> */
	X86_SIM_X86_CALL(x86_l_47c5, 0x2650ULL);
x86_l_2650:
	/* 0x2650: mov    r12,0xffffffffffffffde */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, 0, 18446744073709551582ULL);
x86_l_2657:
	/* 0x2657: jmp    3d33 <generic_retkprobe_event+0x3d33> */
	X86_SIM_X86_JMP(0x2657, 0x3d33, x86_l_3d33);
x86_l_265c:
	/* 0x265c: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2661:
	/* 0x2661: mov    BYTE PTR [rax+0x10a0],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18279380811776ULL);
x86_l_2668:
	/* 0x2668: mov    r12d,0x1001 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 4097ULL);
x86_l_266e:
	/* 0x266e: jmp    260c <generic_retkprobe_event+0x260c> */
	X86_SIM_X86_JMP(0x266e, 0x260c, x86_l_260c);
x86_l_2670:
	/* 0x2670: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2675:
	/* 0x2675: mov    WORD PTR [rax],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_267a:
	/* 0x267a: mov    r14,QWORD PTR [rsp] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_267e:
	/* 0x267e: jmp    4159 <generic_retkprobe_event+0x4159> */
	X86_SIM_X86_JMP(0x267e, 0x4159, x86_l_4159);
x86_l_2683:
	/* 0x2683: mov    BYTE PTR [rsp+0x90],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_268b:
	/* 0x268b: mov    rdx,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_268e:
	/* 0x268e: add    rdx,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2692:
	/* 0x2692: jns    26ad <generic_retkprobe_event+0x26ad> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2692, 0x26ad, x86_l_26ad);
x86_l_2694:
	/* 0x2694: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_2697:
	/* 0x2697: jns    3166 <generic_retkprobe_event+0x3166> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2697, 0x3166, x86_l_3166);
x86_l_269d:
	/* 0x269d: mov    rax,QWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26a0:
	/* 0x26a0: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_26a8:
	/* 0x26a8: jmp    3172 <generic_retkprobe_event+0x3172> */
	X86_SIM_X86_JMP(0x26a8, 0x3172, x86_l_3172);
x86_l_26ad:
	/* 0x26ad: lea    rdi,[rsp+0x80] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_26b5:
	/* 0x26b5: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_26ba:
	/* 0x26ba: call   26bf <generic_retkprobe_event+0x26bf> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_26bf:
	/* 0x26bf: jmp    3172 <generic_retkprobe_event+0x3172> */
	X86_SIM_X86_JMP(0x26bf, 0x3172, x86_l_3172);
x86_l_26c4:
	/* 0x26c4: mov    QWORD PTR [rdi+0x37],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 236223201280ULL);
x86_l_26cc:
	/* 0x26cc: mov    QWORD PTR [rdi+0x30],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_26d4:
	/* 0x26d4: mov    QWORD PTR [rdi+0x28],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_26dc:
	/* 0x26dc: mov    QWORD PTR [rdi+0x20],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_26e4:
	/* 0x26e4: mov    QWORD PTR [rdi+0x18],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_26ec:
	/* 0x26ec: mov    QWORD PTR [rdi+0x10],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_26f4:
	/* 0x26f4: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_26fc:
	/* 0x26fc: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2703:
	/* 0x2703: jmp    381c <generic_retkprobe_event+0x381c> */
	X86_SIM_X86_JMP(0x2703, 0x381c, x86_l_381c);
x86_l_2708:
	/* 0x2708: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_2711:
	/* 0x2711: xor    edx,edx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_2713:
	/* 0x2713: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2718:
	/* 0x2718: mov    esi,0x80 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 128ULL);
x86_l_271d:
	/* 0x271d: call   2722 <generic_retkprobe_event+0x2722> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read_str);
x86_l_2722:
	/* 0x2722: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2727:
	/* 0x2727: lea    rdi,[rax+0x12c] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 300ULL);
x86_l_272e:
	/* 0x272e: test   r12,r12 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_2731:
	/* 0x2731: jns    2740 <generic_retkprobe_event+0x2740> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2731, 0x2740, x86_l_2740);
x86_l_2733:
	/* 0x2733: test   r12,r12 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_2736:
	/* 0x2736: jns    274f <generic_retkprobe_event+0x274f> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2736, 0x274f, x86_l_274f);
x86_l_2738:
	/* 0x2738: mov    eax,DWORD PTR [r12] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_273c:
	/* 0x273c: mov    DWORD PTR [rdi],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_273e:
	/* 0x273e: jmp    2755 <generic_retkprobe_event+0x2755> */
	X86_SIM_X86_JMP(0x273e, 0x2755, x86_l_2755);
x86_l_2740:
	/* 0x2740: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_2745:
	/* 0x2745: mov    rdx,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_2748:
	/* 0x2748: call   274d <generic_retkprobe_event+0x274d> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_274d:
	/* 0x274d: jmp    2755 <generic_retkprobe_event+0x2755> */
	X86_SIM_X86_JMP(0x274d, 0x2755, x86_l_2755);
x86_l_274f:
	/* 0x274f: mov    DWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2755:
	/* 0x2755: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_275a:
	/* 0x275a: lea    rdi,[rax+0x11c] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 284ULL);
x86_l_2761:
	/* 0x2761: mov    rdx,rbp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_2764:
	/* 0x2764: add    rdx,0xe0 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 224ULL);
x86_l_276b:
	/* 0x276b: jns    277a <generic_retkprobe_event+0x277a> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x276b, 0x277a, x86_l_277a);
x86_l_276d:
	/* 0x276d: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_2770:
	/* 0x2770: jns    2786 <generic_retkprobe_event+0x2786> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2770, 0x2786, x86_l_2786);
x86_l_2772:
	/* 0x2772: mov    rax,QWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2775:
	/* 0x2775: mov    QWORD PTR [rdi],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2778:
	/* 0x2778: jmp    278d <generic_retkprobe_event+0x278d> */
	X86_SIM_X86_JMP(0x2778, 0x278d, x86_l_278d);
x86_l_277a:
	/* 0x277a: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_277f:
	/* 0x277f: call   2784 <generic_retkprobe_event+0x2784> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_2784:
	/* 0x2784: jmp    278d <generic_retkprobe_event+0x278d> */
	X86_SIM_X86_JMP(0x2784, 0x278d, x86_l_278d);
x86_l_2786:
	/* 0x2786: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_278d:
	/* 0x278d: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2792:
	/* 0x2792: add    rdi,0x124 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 292ULL);
x86_l_2799:
	/* 0x2799: add    rbp,0x118 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 280ULL);
x86_l_27a0:
	/* 0x27a0: jns    27b9 <generic_retkprobe_event+0x27b9> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x27a0, 0x27b9, x86_l_27b9);
x86_l_27a2:
	/* 0x27a2: test   rbp,rbp */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_27a5:
	/* 0x27a5: jns    27d1 <generic_retkprobe_event+0x27d1> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x27a5, 0x27d1, x86_l_27d1);
x86_l_27a7:
	/* 0x27a7: mov    rax,QWORD PTR [rbp+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27ab:
	/* 0x27ab: mov    QWORD PTR [rdi],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27ae:
	/* 0x27ae: mov    r12d,0x98 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 152ULL);
x86_l_27b4:
	/* 0x27b4: jmp    381f <generic_retkprobe_event+0x381f> */
	X86_SIM_X86_JMP(0x27b4, 0x381f, x86_l_381f);
x86_l_27b9:
	/* 0x27b9: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_27be:
	/* 0x27be: mov    rdx,rbp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_27c1:
	/* 0x27c1: call   27c6 <generic_retkprobe_event+0x27c6> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_27c6:
	/* 0x27c6: mov    r12d,0x98 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 152ULL);
x86_l_27cc:
	/* 0x27cc: jmp    381f <generic_retkprobe_event+0x381f> */
	X86_SIM_X86_JMP(0x27cc, 0x381f, x86_l_381f);
x86_l_27d1:
	/* 0x27d1: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27d8:
	/* 0x27d8: mov    r12d,0x98 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 152ULL);
x86_l_27de:
	/* 0x27de: jmp    381f <generic_retkprobe_event+0x381f> */
	X86_SIM_X86_JMP(0x27de, 0x381f, x86_l_381f);
x86_l_27e3:
	/* 0x27e3: mov    QWORD PTR [rsp+0x80],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_27ef:
	/* 0x27ef: xor    r15d,r15d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_27f2:
	/* 0x27f2: cmp    r15,0xfff */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, 0, 4095ULL);
x86_l_27f9:
	/* 0x27f9: mov    r12d,0xfff */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 4095ULL);
x86_l_27ff:
	/* 0x27ff: cmovb  r12,r15 */
	X86_SIM_RUN_OP(X86_OP_CMOV, X86_R12, X86_R15, X86_WIDTH_64, X86_CC_B, 0);
x86_l_2803:
	/* 0x2803: mov    rdi,r14 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_2806:
	/* 0x2806: add    rdi,0xa4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 164ULL);
x86_l_280d:
	/* 0x280d: test   rbp,rbp */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_2810:
	/* 0x2810: js     2826 <generic_retkprobe_event+0x2826> */
	X86_SIM_X86_JCC(X86_CC_S, 0x2810, 0x2826, x86_l_2826);
x86_l_2812:
	/* 0x2812: mov    esi,r12d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_R12, X86_WIDTH_32, 0, 0);
x86_l_2815:
	/* 0x2815: mov    rdx,rbp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_2818:
	/* 0x2818: call   281d <generic_retkprobe_event+0x281d> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_281d:
	/* 0x281d: test   eax,eax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_281f:
	/* 0x281f: jns    2876 <generic_retkprobe_event+0x2876> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x281f, 0x2876, x86_l_2876);
x86_l_2821:
	/* 0x2821: jmp    2fe4 <generic_retkprobe_event+0x2fe4> */
	X86_SIM_X86_JMP(0x2821, 0x2fe4, x86_l_2fe4);
x86_l_2826:
	/* 0x2826: test   rbp,rbp */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_2829:
	/* 0x2829: jns    2fda <generic_retkprobe_event+0x2fda> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2829, 0x2fda, x86_l_2fda);
x86_l_282f:
	/* 0x282f: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_2831:
	/* 0x2831: cmp    r12d,0x8 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_2835:
	/* 0x2835: jb     2852 <generic_retkprobe_event+0x2852> */
	X86_SIM_X86_JCC(X86_CC_B, 0x2835, 0x2852, x86_l_2852);
x86_l_2837:
	/* 0x2837: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_2839:
	/* 0x2839: mov    rcx,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_283c:
	/* 0x283c: mov    rax,QWORD PTR [rbp+rax*1+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2841:
	/* 0x2841: mov    QWORD PTR [rdi+rcx*1],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2845:
	/* 0x2845: lea    rax,[rcx+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2849:
	/* 0x2849: add    rcx,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_284d:
	/* 0x284d: cmp    rcx,r12 */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RCX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_2850:
	/* 0x2850: jbe    2839 <generic_retkprobe_event+0x2839> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x2850, 0x2839, x86_l_2839);
x86_l_2852:
	/* 0x2852: test   r12b,0x4 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, 0, 4ULL);
x86_l_2856:
	/* 0x2856: jne    37a5 <generic_retkprobe_event+0x37a5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2856, 0x37a5, x86_l_37a5);
x86_l_285c:
	/* 0x285c: test   r12b,0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, 0, 2ULL);
x86_l_2860:
	/* 0x2860: jne    37bb <generic_retkprobe_event+0x37bb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2860, 0x37bb, x86_l_37bb);
x86_l_2866:
	/* 0x2866: test   r12b,0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_286a:
	/* 0x286a: je     2876 <generic_retkprobe_event+0x2876> */
	X86_SIM_X86_JCC(X86_CC_E, 0x286a, 0x2876, x86_l_2876);
x86_l_286c:
	/* 0x286c: mov    eax,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_286e:
	/* 0x286e: movzx  ecx,BYTE PTR [rbp+rax*1+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2873:
	/* 0x2873: mov    BYTE PTR [rdi+rax*1],cl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2876:
	/* 0x2876: mov    DWORD PTR [r14+0x9c],r15d */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_R14, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_287d:
	/* 0x287d: mov    DWORD PTR [r14+0xa0],r12d */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_R14, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2884:
	/* 0x2884: add    r12,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2888:
	/* 0x2888: jmp    381f <generic_retkprobe_event+0x381f> */
	X86_SIM_X86_JMP(0x2888, 0x381f, x86_l_381f);
x86_l_288d:
	/* 0x288d: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2892:
	/* 0x2892: mov    DWORD PTR [rax],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2898:
	/* 0x2898: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_289d:
	/* 0x289d: lea    rdi,[rax+0xa0] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_28a4:
	/* 0x28a4: mov    rdx,rbp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_28a7:
	/* 0x28a7: add    rdx,0xc */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_28ab:
	/* 0x28ab: jns    28b8 <generic_retkprobe_event+0x28b8> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x28ab, 0x28b8, x86_l_28b8);
x86_l_28ad:
	/* 0x28ad: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_28b0:
	/* 0x28b0: jns    28c4 <generic_retkprobe_event+0x28c4> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x28b0, 0x28c4, x86_l_28c4);
x86_l_28b2:
	/* 0x28b2: mov    eax,DWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28b4:
	/* 0x28b4: mov    DWORD PTR [rdi],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28b6:
	/* 0x28b6: jmp    28ca <generic_retkprobe_event+0x28ca> */
	X86_SIM_X86_JMP(0x28b6, 0x28ca, x86_l_28ca);
x86_l_28b8:
	/* 0x28b8: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_28bd:
	/* 0x28bd: call   28c2 <generic_retkprobe_event+0x28c2> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_28c2:
	/* 0x28c2: jmp    28ca <generic_retkprobe_event+0x28ca> */
	X86_SIM_X86_JMP(0x28c2, 0x28ca, x86_l_28ca);
x86_l_28c4:
	/* 0x28c4: mov    DWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28ca:
	/* 0x28ca: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_28cf:
	/* 0x28cf: lea    rdi,[rax+0xac] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_28d6:
	/* 0x28d6: mov    rdx,rbp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_28d9:
	/* 0x28d9: add    rdx,0x18 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_28dd:
	/* 0x28dd: jns    28ea <generic_retkprobe_event+0x28ea> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x28dd, 0x28ea, x86_l_28ea);
x86_l_28df:
	/* 0x28df: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_28e2:
	/* 0x28e2: jns    28f6 <generic_retkprobe_event+0x28f6> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x28e2, 0x28f6, x86_l_28f6);
x86_l_28e4:
	/* 0x28e4: mov    eax,DWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28e6:
	/* 0x28e6: mov    DWORD PTR [rdi],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28e8:
	/* 0x28e8: jmp    28fc <generic_retkprobe_event+0x28fc> */
	X86_SIM_X86_JMP(0x28e8, 0x28fc, x86_l_28fc);
x86_l_28ea:
	/* 0x28ea: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_28ef:
	/* 0x28ef: call   28f4 <generic_retkprobe_event+0x28f4> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_28f4:
	/* 0x28f4: jmp    28fc <generic_retkprobe_event+0x28fc> */
	X86_SIM_X86_JMP(0x28f4, 0x28fc, x86_l_28fc);
x86_l_28f6:
	/* 0x28f6: mov    DWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28fc:
	/* 0x28fc: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2901:
	/* 0x2901: lea    rdi,[rax+0xb0] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_2908:
	/* 0x2908: mov    rdx,rbp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_290b:
	/* 0x290b: add    rdx,0x1c */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 28ULL);
x86_l_290f:
	/* 0x290f: jns    291c <generic_retkprobe_event+0x291c> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x290f, 0x291c, x86_l_291c);
x86_l_2911:
	/* 0x2911: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_2914:
	/* 0x2914: jns    2928 <generic_retkprobe_event+0x2928> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2914, 0x2928, x86_l_2928);
x86_l_2916:
	/* 0x2916: mov    eax,DWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2918:
	/* 0x2918: mov    DWORD PTR [rdi],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_291a:
	/* 0x291a: jmp    292e <generic_retkprobe_event+0x292e> */
	X86_SIM_X86_JMP(0x291a, 0x292e, x86_l_292e);
x86_l_291c:
	/* 0x291c: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_2921:
	/* 0x2921: call   2926 <generic_retkprobe_event+0x2926> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_2926:
	/* 0x2926: jmp    292e <generic_retkprobe_event+0x292e> */
	X86_SIM_X86_JMP(0x2926, 0x292e, x86_l_292e);
x86_l_2928:
	/* 0x2928: mov    DWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_292e:
	/* 0x292e: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2933:
	/* 0x2933: lea    rdi,[rax+0xa4] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_293a:
	/* 0x293a: mov    rdx,rbp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_293d:
	/* 0x293d: add    rdx,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2941:
	/* 0x2941: jns    294e <generic_retkprobe_event+0x294e> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2941, 0x294e, x86_l_294e);
x86_l_2943:
	/* 0x2943: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_2946:
	/* 0x2946: jns    295a <generic_retkprobe_event+0x295a> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2946, 0x295a, x86_l_295a);
x86_l_2948:
	/* 0x2948: mov    eax,DWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_294a:
	/* 0x294a: mov    DWORD PTR [rdi],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_294c:
	/* 0x294c: jmp    2960 <generic_retkprobe_event+0x2960> */
	X86_SIM_X86_JMP(0x294c, 0x2960, x86_l_2960);
x86_l_294e:
	/* 0x294e: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_2953:
	/* 0x2953: call   2958 <generic_retkprobe_event+0x2958> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_2958:
	/* 0x2958: jmp    2960 <generic_retkprobe_event+0x2960> */
	X86_SIM_X86_JMP(0x2958, 0x2960, x86_l_2960);
x86_l_295a:
	/* 0x295a: mov    DWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2960:
	/* 0x2960: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2965:
	/* 0x2965: lea    rdi,[rax+0xa8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_296c:
	/* 0x296c: mov    rdx,rbp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_296f:
	/* 0x296f: add    rdx,0x14 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 20ULL);
x86_l_2973:
	/* 0x2973: jns    2980 <generic_retkprobe_event+0x2980> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2973, 0x2980, x86_l_2980);
x86_l_2975:
	/* 0x2975: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_2978:
	/* 0x2978: jns    298c <generic_retkprobe_event+0x298c> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2978, 0x298c, x86_l_298c);
x86_l_297a:
	/* 0x297a: mov    eax,DWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_297c:
	/* 0x297c: mov    DWORD PTR [rdi],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_297e:
	/* 0x297e: jmp    2992 <generic_retkprobe_event+0x2992> */
	X86_SIM_X86_JMP(0x297e, 0x2992, x86_l_2992);
x86_l_2980:
	/* 0x2980: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_2985:
	/* 0x2985: call   298a <generic_retkprobe_event+0x298a> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_298a:
	/* 0x298a: jmp    2992 <generic_retkprobe_event+0x2992> */
	X86_SIM_X86_JMP(0x298a, 0x2992, x86_l_2992);
x86_l_298c:
	/* 0x298c: mov    DWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2992:
	/* 0x2992: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2997:
	/* 0x2997: lea    rdi,[rax+0xb4] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 180ULL);
x86_l_299e:
	/* 0x299e: mov    rdx,rbp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_29a1:
	/* 0x29a1: add    rdx,0x20 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_29a5:
	/* 0x29a5: jns    29b2 <generic_retkprobe_event+0x29b2> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x29a5, 0x29b2, x86_l_29b2);
x86_l_29a7:
	/* 0x29a7: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_29aa:
	/* 0x29aa: jns    29be <generic_retkprobe_event+0x29be> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x29aa, 0x29be, x86_l_29be);
x86_l_29ac:
	/* 0x29ac: mov    eax,DWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29ae:
	/* 0x29ae: mov    DWORD PTR [rdi],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29b0:
	/* 0x29b0: jmp    29c4 <generic_retkprobe_event+0x29c4> */
	X86_SIM_X86_JMP(0x29b0, 0x29c4, x86_l_29c4);
x86_l_29b2:
	/* 0x29b2: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_29b7:
	/* 0x29b7: call   29bc <generic_retkprobe_event+0x29bc> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_29bc:
	/* 0x29bc: jmp    29c4 <generic_retkprobe_event+0x29c4> */
	X86_SIM_X86_JMP(0x29bc, 0x29c4, x86_l_29c4);
x86_l_29be:
	/* 0x29be: mov    DWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29c4:
	/* 0x29c4: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_29c9:
	/* 0x29c9: lea    rdi,[rax+0xb8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_29d0:
	/* 0x29d0: mov    rdx,rbp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_29d3:
	/* 0x29d3: add    rdx,0x24 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 36ULL);
x86_l_29d7:
	/* 0x29d7: jns    29e4 <generic_retkprobe_event+0x29e4> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x29d7, 0x29e4, x86_l_29e4);
x86_l_29d9:
	/* 0x29d9: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_29dc:
	/* 0x29dc: jns    29f0 <generic_retkprobe_event+0x29f0> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x29dc, 0x29f0, x86_l_29f0);
x86_l_29de:
	/* 0x29de: mov    eax,DWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29e0:
	/* 0x29e0: mov    DWORD PTR [rdi],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29e2:
	/* 0x29e2: jmp    29f6 <generic_retkprobe_event+0x29f6> */
	X86_SIM_X86_JMP(0x29e2, 0x29f6, x86_l_29f6);
x86_l_29e4:
	/* 0x29e4: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_29e9:
	/* 0x29e9: call   29ee <generic_retkprobe_event+0x29ee> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_29ee:
	/* 0x29ee: jmp    29f6 <generic_retkprobe_event+0x29f6> */
	X86_SIM_X86_JMP(0x29ee, 0x29f6, x86_l_29f6);
x86_l_29f0:
	/* 0x29f0: mov    DWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29f6:
	/* 0x29f6: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_29fb:
	/* 0x29fb: mov    DWORD PTR [rax+0xc0],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_2a05:
	/* 0x2a05: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a0a:
	/* 0x2a0a: lea    rdi,[rax+0xbc] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_2a11:
	/* 0x2a11: mov    rdx,rbp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_2a14:
	/* 0x2a14: add    rdx,0x28 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_2a18:
	/* 0x2a18: jns    2a25 <generic_retkprobe_event+0x2a25> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2a18, 0x2a25, x86_l_2a25);
x86_l_2a1a:
	/* 0x2a1a: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_2a1d:
	/* 0x2a1d: jns    2a31 <generic_retkprobe_event+0x2a31> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2a1d, 0x2a31, x86_l_2a31);
x86_l_2a1f:
	/* 0x2a1f: mov    eax,DWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a21:
	/* 0x2a21: mov    DWORD PTR [rdi],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a23:
	/* 0x2a23: jmp    2a37 <generic_retkprobe_event+0x2a37> */
	X86_SIM_X86_JMP(0x2a23, 0x2a37, x86_l_2a37);
x86_l_2a25:
	/* 0x2a25: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_2a2a:
	/* 0x2a2a: call   2a2f <generic_retkprobe_event+0x2a2f> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_2a2f:
	/* 0x2a2f: jmp    2a37 <generic_retkprobe_event+0x2a37> */
	X86_SIM_X86_JMP(0x2a2f, 0x2a37, x86_l_2a37);
x86_l_2a31:
	/* 0x2a31: mov    DWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a37:
	/* 0x2a37: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a3c:
	/* 0x2a3c: lea    rdi,[rax+0xcc] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_2a43:
	/* 0x2a43: mov    rdx,rbp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_2a46:
	/* 0x2a46: add    rdx,0x40 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 64ULL);
x86_l_2a4a:
	/* 0x2a4a: jns    2a59 <generic_retkprobe_event+0x2a59> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2a4a, 0x2a59, x86_l_2a59);
x86_l_2a4c:
	/* 0x2a4c: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_2a4f:
	/* 0x2a4f: jns    2a65 <generic_retkprobe_event+0x2a65> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2a4f, 0x2a65, x86_l_2a65);
x86_l_2a51:
	/* 0x2a51: mov    rax,QWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a54:
	/* 0x2a54: mov    QWORD PTR [rdi],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a57:
	/* 0x2a57: jmp    2a6c <generic_retkprobe_event+0x2a6c> */
	X86_SIM_X86_JMP(0x2a57, 0x2a6c, x86_l_2a6c);
x86_l_2a59:
	/* 0x2a59: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_2a5e:
	/* 0x2a5e: call   2a63 <generic_retkprobe_event+0x2a63> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_2a63:
	/* 0x2a63: jmp    2a6c <generic_retkprobe_event+0x2a6c> */
	X86_SIM_X86_JMP(0x2a63, 0x2a6c, x86_l_2a6c);
x86_l_2a65:
	/* 0x2a65: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a6c:
	/* 0x2a6c: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a71:
	/* 0x2a71: lea    rdi,[rax+0xd4] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 212ULL);
x86_l_2a78:
	/* 0x2a78: mov    rdx,rbp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_2a7b:
	/* 0x2a7b: add    rdx,0x30 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_2a7f:
	/* 0x2a7f: jns    2a8e <generic_retkprobe_event+0x2a8e> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2a7f, 0x2a8e, x86_l_2a8e);
x86_l_2a81:
	/* 0x2a81: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_2a84:
	/* 0x2a84: jns    2a9a <generic_retkprobe_event+0x2a9a> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2a84, 0x2a9a, x86_l_2a9a);
x86_l_2a86:
	/* 0x2a86: mov    rax,QWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a89:
	/* 0x2a89: mov    QWORD PTR [rdi],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a8c:
	/* 0x2a8c: jmp    2aa1 <generic_retkprobe_event+0x2aa1> */
	X86_SIM_X86_JMP(0x2a8c, 0x2aa1, x86_l_2aa1);
x86_l_2a8e:
	/* 0x2a8e: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_2a93:
	/* 0x2a93: call   2a98 <generic_retkprobe_event+0x2a98> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_2a98:
	/* 0x2a98: jmp    2aa1 <generic_retkprobe_event+0x2aa1> */
	X86_SIM_X86_JMP(0x2a98, 0x2aa1, x86_l_2aa1);
x86_l_2a9a:
	/* 0x2a9a: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2aa1:
	/* 0x2aa1: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2aa6:
	/* 0x2aa6: lea    rdi,[rax+0xc4] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_2aad:
	/* 0x2aad: mov    rdx,rbp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_2ab0:
	/* 0x2ab0: add    rdx,0x38 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 56ULL);
x86_l_2ab4:
	/* 0x2ab4: jns    2ac3 <generic_retkprobe_event+0x2ac3> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2ab4, 0x2ac3, x86_l_2ac3);
x86_l_2ab6:
	/* 0x2ab6: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_2ab9:
	/* 0x2ab9: jns    2acf <generic_retkprobe_event+0x2acf> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2ab9, 0x2acf, x86_l_2acf);
x86_l_2abb:
	/* 0x2abb: mov    rax,QWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2abe:
	/* 0x2abe: mov    QWORD PTR [rdi],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ac1:
	/* 0x2ac1: jmp    2ad6 <generic_retkprobe_event+0x2ad6> */
	X86_SIM_X86_JMP(0x2ac1, 0x2ad6, x86_l_2ad6);
x86_l_2ac3:
	/* 0x2ac3: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_2ac8:
	/* 0x2ac8: call   2acd <generic_retkprobe_event+0x2acd> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_2acd:
	/* 0x2acd: jmp    2ad6 <generic_retkprobe_event+0x2ad6> */
	X86_SIM_X86_JMP(0x2acd, 0x2ad6, x86_l_2ad6);
x86_l_2acf:
	/* 0x2acf: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ad6:
	/* 0x2ad6: add    rbp,0x90 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_2add:
	/* 0x2add: jns    2aef <generic_retkprobe_event+0x2aef> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2add, 0x2aef, x86_l_2aef);
x86_l_2adf:
	/* 0x2adf: test   rbp,rbp */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_2ae2:
	/* 0x2ae2: jns    2b08 <generic_retkprobe_event+0x2b08> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2ae2, 0x2b08, x86_l_2b08);
x86_l_2ae4:
	/* 0x2ae4: mov    r12,QWORD PTR [rbp+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R12, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ae8:
	/* 0x2ae8: mov    QWORD PTR [rsp+0x40],r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2aed:
	/* 0x2aed: jmp    2b14 <generic_retkprobe_event+0x2b14> */
	X86_SIM_X86_JMP(0x2aed, 0x2b14, x86_l_2b14);
x86_l_2aef:
	/* 0x2aef: lea    rdi,[rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2af4:
	/* 0x2af4: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_2af9:
	/* 0x2af9: mov    rdx,rbp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_2afc:
	/* 0x2afc: call   2b01 <generic_retkprobe_event+0x2b01> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_2b01:
	/* 0x2b01: mov    r12,QWORD PTR [rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2b06:
	/* 0x2b06: jmp    2b14 <generic_retkprobe_event+0x2b14> */
	X86_SIM_X86_JMP(0x2b06, 0x2b14, x86_l_2b14);
x86_l_2b08:
	/* 0x2b08: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_2b11:
	/* 0x2b11: xor    r12d,r12d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_2b14:
	/* 0x2b14: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b19:
	/* 0x2b19: lea    rdi,[rax+0xdc] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 220ULL);
x86_l_2b20:
	/* 0x2b20: mov    rdx,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_2b23:
	/* 0x2b23: add    rdx,0xc8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 200ULL);
x86_l_2b2a:
	/* 0x2b2a: jns    2b37 <generic_retkprobe_event+0x2b37> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2b2a, 0x2b37, x86_l_2b37);
x86_l_2b2c:
	/* 0x2b2c: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_2b2f:
	/* 0x2b2f: jns    2b43 <generic_retkprobe_event+0x2b43> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2b2f, 0x2b43, x86_l_2b43);
x86_l_2b31:
	/* 0x2b31: mov    eax,DWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b33:
	/* 0x2b33: mov    DWORD PTR [rdi],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b35:
	/* 0x2b35: jmp    2b49 <generic_retkprobe_event+0x2b49> */
	X86_SIM_X86_JMP(0x2b35, 0x2b49, x86_l_2b49);
x86_l_2b37:
	/* 0x2b37: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_2b3c:
	/* 0x2b3c: call   2b41 <generic_retkprobe_event+0x2b41> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_2b41:
	/* 0x2b41: jmp    2b49 <generic_retkprobe_event+0x2b49> */
	X86_SIM_X86_JMP(0x2b41, 0x2b49, x86_l_2b49);
x86_l_2b43:
	/* 0x2b43: mov    DWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b49:
	/* 0x2b49: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b4e:
	/* 0x2b4e: lea    rdi,[rax+0xe0] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_2b55:
	/* 0x2b55: mov    rdx,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_2b58:
	/* 0x2b58: add    rdx,0xcc */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 204ULL);
x86_l_2b5f:
	/* 0x2b5f: jns    2b6c <generic_retkprobe_event+0x2b6c> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2b5f, 0x2b6c, x86_l_2b6c);
x86_l_2b61:
	/* 0x2b61: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_2b64:
	/* 0x2b64: jns    2b78 <generic_retkprobe_event+0x2b78> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2b64, 0x2b78, x86_l_2b78);
x86_l_2b66:
	/* 0x2b66: mov    eax,DWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b68:
	/* 0x2b68: mov    DWORD PTR [rdi],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b6a:
	/* 0x2b6a: jmp    2b7e <generic_retkprobe_event+0x2b7e> */
	X86_SIM_X86_JMP(0x2b6a, 0x2b7e, x86_l_2b7e);
x86_l_2b6c:
	/* 0x2b6c: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_2b71:
	/* 0x2b71: call   2b76 <generic_retkprobe_event+0x2b76> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_2b76:
	/* 0x2b76: jmp    2b7e <generic_retkprobe_event+0x2b7e> */
	X86_SIM_X86_JMP(0x2b76, 0x2b7e, x86_l_2b7e);
x86_l_2b78:
	/* 0x2b78: mov    DWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b7e:
	/* 0x2b7e: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b83:
	/* 0x2b83: lea    rdi,[rax+0xe4] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 228ULL);
x86_l_2b8a:
	/* 0x2b8a: mov    rdx,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_2b8d:
	/* 0x2b8d: add    rdx,0xd0 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 208ULL);
x86_l_2b94:
	/* 0x2b94: jns    2ba1 <generic_retkprobe_event+0x2ba1> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2b94, 0x2ba1, x86_l_2ba1);
x86_l_2b96:
	/* 0x2b96: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_2b99:
	/* 0x2b99: jns    2bad <generic_retkprobe_event+0x2bad> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2b99, 0x2bad, x86_l_2bad);
x86_l_2b9b:
	/* 0x2b9b: mov    eax,DWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b9d:
	/* 0x2b9d: mov    DWORD PTR [rdi],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b9f:
	/* 0x2b9f: jmp    2bb3 <generic_retkprobe_event+0x2bb3> */
	X86_SIM_X86_JMP(0x2b9f, 0x2bb3, x86_l_2bb3);
x86_l_2ba1:
	/* 0x2ba1: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_2ba6:
	/* 0x2ba6: call   2bab <generic_retkprobe_event+0x2bab> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_2bab:
	/* 0x2bab: jmp    2bb3 <generic_retkprobe_event+0x2bb3> */
	X86_SIM_X86_JMP(0x2bab, 0x2bb3, x86_l_2bb3);
x86_l_2bad:
	/* 0x2bad: mov    DWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bb3:
	/* 0x2bb3: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2bb8:
	/* 0x2bb8: add    rdi,0xe8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 232ULL);
x86_l_2bbf:
	/* 0x2bbf: add    r12,0x158 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 344ULL);
x86_l_2bc6:
	/* 0x2bc6: jns    2bde <generic_retkprobe_event+0x2bde> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2bc6, 0x2bde, x86_l_2bde);
x86_l_2bc8:
	/* 0x2bc8: test   r12,r12 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_2bcb:
	/* 0x2bcb: jns    2bf6 <generic_retkprobe_event+0x2bf6> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2bcb, 0x2bf6, x86_l_2bf6);
x86_l_2bcd:
	/* 0x2bcd: mov    eax,DWORD PTR [r12] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bd1:
	/* 0x2bd1: mov    DWORD PTR [rdi],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bd3:
	/* 0x2bd3: mov    r12d,0x50 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 80ULL);
x86_l_2bd9:
	/* 0x2bd9: jmp    381f <generic_retkprobe_event+0x381f> */
	X86_SIM_X86_JMP(0x2bd9, 0x381f, x86_l_381f);
x86_l_2bde:
	/* 0x2bde: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_2be3:
	/* 0x2be3: mov    rdx,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_2be6:
	/* 0x2be6: call   2beb <generic_retkprobe_event+0x2beb> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_2beb:
	/* 0x2beb: mov    r12d,0x50 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 80ULL);
x86_l_2bf1:
	/* 0x2bf1: jmp    381f <generic_retkprobe_event+0x381f> */
	X86_SIM_X86_JMP(0x2bf1, 0x381f, x86_l_381f);
x86_l_2bf6:
	/* 0x2bf6: mov    DWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bfc:
	/* 0x2bfc: mov    r12d,0x50 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 80ULL);
x86_l_2c02:
	/* 0x2c02: jmp    381f <generic_retkprobe_event+0x381f> */
	X86_SIM_X86_JMP(0x2c02, 0x381f, x86_l_381f);
x86_l_2c07:
	/* 0x2c07: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2c0c:
	/* 0x2c0c: mov    DWORD PTR [rax],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c12:
	/* 0x2c12: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c17:
	/* 0x2c17: lea    rdi,[rax+0xa0] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2c1e:
	/* 0x2c1e: mov    rdx,rbp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_2c21:
	/* 0x2c21: add    rdx,0x3c */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 60ULL);
x86_l_2c25:
	/* 0x2c25: jns    2c32 <generic_retkprobe_event+0x2c32> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2c25, 0x2c32, x86_l_2c32);
x86_l_2c27:
	/* 0x2c27: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_2c2a:
	/* 0x2c2a: jns    2c3e <generic_retkprobe_event+0x2c3e> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2c2a, 0x2c3e, x86_l_2c3e);
x86_l_2c2c:
	/* 0x2c2c: mov    eax,DWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c2e:
	/* 0x2c2e: mov    DWORD PTR [rdi],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c30:
	/* 0x2c30: jmp    2c44 <generic_retkprobe_event+0x2c44> */
	X86_SIM_X86_JMP(0x2c30, 0x2c44, x86_l_2c44);
x86_l_2c32:
	/* 0x2c32: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_2c37:
	/* 0x2c37: call   2c3c <generic_retkprobe_event+0x2c3c> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_2c3c:
	/* 0x2c3c: jmp    2c44 <generic_retkprobe_event+0x2c44> */
	X86_SIM_X86_JMP(0x2c3c, 0x2c44, x86_l_2c44);
x86_l_2c3e:
	/* 0x2c3e: mov    DWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c44:
	/* 0x2c44: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c49:
	/* 0x2c49: lea    rdi,[rax+0xa4] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_2c50:
	/* 0x2c50: mov    rdx,rbp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_2c53:
	/* 0x2c53: add    rdx,0x40 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 64ULL);
x86_l_2c57:
	/* 0x2c57: jns    2c64 <generic_retkprobe_event+0x2c64> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2c57, 0x2c64, x86_l_2c64);
x86_l_2c59:
	/* 0x2c59: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_2c5c:
	/* 0x2c5c: jns    2c70 <generic_retkprobe_event+0x2c70> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2c5c, 0x2c70, x86_l_2c70);
x86_l_2c5e:
	/* 0x2c5e: mov    eax,DWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c60:
	/* 0x2c60: mov    DWORD PTR [rdi],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c62:
	/* 0x2c62: jmp    2c76 <generic_retkprobe_event+0x2c76> */
	X86_SIM_X86_JMP(0x2c62, 0x2c76, x86_l_2c76);
x86_l_2c64:
	/* 0x2c64: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_2c69:
	/* 0x2c69: call   2c6e <generic_retkprobe_event+0x2c6e> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_2c6e:
	/* 0x2c6e: jmp    2c76 <generic_retkprobe_event+0x2c76> */
	X86_SIM_X86_JMP(0x2c6e, 0x2c76, x86_l_2c76);
x86_l_2c70:
	/* 0x2c70: mov    DWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c76:
	/* 0x2c76: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c7b:
	/* 0x2c7b: lea    rdi,[rax+0xa8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_2c82:
	/* 0x2c82: mov    rdx,rbp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_2c85:
	/* 0x2c85: add    rdx,0x44 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 68ULL);
x86_l_2c89:
	/* 0x2c89: jns    2c96 <generic_retkprobe_event+0x2c96> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2c89, 0x2c96, x86_l_2c96);
x86_l_2c8b:
	/* 0x2c8b: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_2c8e:
	/* 0x2c8e: jns    2ca2 <generic_retkprobe_event+0x2ca2> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2c8e, 0x2ca2, x86_l_2ca2);
x86_l_2c90:
	/* 0x2c90: mov    eax,DWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c92:
	/* 0x2c92: mov    DWORD PTR [rdi],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c94:
	/* 0x2c94: jmp    2ca8 <generic_retkprobe_event+0x2ca8> */
	X86_SIM_X86_JMP(0x2c94, 0x2ca8, x86_l_2ca8);
x86_l_2c96:
	/* 0x2c96: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_2c9b:
	/* 0x2c9b: call   2ca0 <generic_retkprobe_event+0x2ca0> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_2ca0:
	/* 0x2ca0: jmp    2ca8 <generic_retkprobe_event+0x2ca8> */
	X86_SIM_X86_JMP(0x2ca0, 0x2ca8, x86_l_2ca8);
x86_l_2ca2:
	/* 0x2ca2: mov    DWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ca8:
	/* 0x2ca8: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2cad:
	/* 0x2cad: add    rdi,0xac */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 172ULL);
x86_l_2cb4:
	/* 0x2cb4: sub    rbp,0xffffffffffffff80 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SUB, 18446744073709551488ULL);
x86_l_2cb8:
	/* 0x2cb8: jns    2ce9 <generic_retkprobe_event+0x2ce9> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2cb8, 0x2ce9, x86_l_2ce9);
x86_l_2cba:
	/* 0x2cba: test   rbp,rbp */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_2cbd:
	/* 0x2cbd: jns    2d01 <generic_retkprobe_event+0x2d01> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2cbd, 0x2d01, x86_l_2d01);
x86_l_2cbf:
	/* 0x2cbf: mov    rax,QWORD PTR [rbp+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2cc3:
	/* 0x2cc3: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2cc8:
	/* 0x2cc8: mov    QWORD PTR [rcx+0xac],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_2ccf:
	/* 0x2ccf: mov    rax,QWORD PTR [rbp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2cd3:
	/* 0x2cd3: mov    QWORD PTR [rcx+0xb4],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 180ULL);
x86_l_2cda:
	/* 0x2cda: mov    r12d,0x20 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 32ULL);
x86_l_2ce0:
	/* 0x2ce0: mov    r14,QWORD PTR [rsp] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ce4:
	/* 0x2ce4: jmp    3828 <generic_retkprobe_event+0x3828> */
	X86_SIM_X86_JMP(0x2ce4, 0x3828, x86_l_3828);
x86_l_2ce9:
	/* 0x2ce9: mov    esi,0x10 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 16ULL);
x86_l_2cee:
	/* 0x2cee: mov    rdx,rbp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_2cf1:
	/* 0x2cf1: call   2cf6 <generic_retkprobe_event+0x2cf6> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_2cf6:
	/* 0x2cf6: mov    r12d,0x20 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 32ULL);
x86_l_2cfc:
	/* 0x2cfc: jmp    381f <generic_retkprobe_event+0x381f> */
	X86_SIM_X86_JMP(0x2cfc, 0x381f, x86_l_381f);
x86_l_2d01:
	/* 0x2d01: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_2d09:
	/* 0x2d09: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d10:
	/* 0x2d10: mov    r12d,0x20 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 32ULL);
x86_l_2d16:
	/* 0x2d16: jmp    381f <generic_retkprobe_event+0x381f> */
	X86_SIM_X86_JMP(0x2d16, 0x381f, x86_l_381f);
x86_l_2d1b:
	/* 0x2d1b: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2d20:
	/* 0x2d20: mov    DWORD PTR [rax],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d26:
	/* 0x2d26: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d2b:
	/* 0x2d2b: lea    rdi,[rax+0xa0] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2d32:
	/* 0x2d32: mov    rdx,rbp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_2d35:
	/* 0x2d35: add    rdx,0xcc */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 204ULL);
x86_l_2d3c:
	/* 0x2d3c: jns    2d49 <generic_retkprobe_event+0x2d49> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2d3c, 0x2d49, x86_l_2d49);
x86_l_2d3e:
	/* 0x2d3e: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_2d41:
	/* 0x2d41: jns    2d55 <generic_retkprobe_event+0x2d55> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2d41, 0x2d55, x86_l_2d55);
x86_l_2d43:
	/* 0x2d43: mov    eax,DWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d45:
	/* 0x2d45: mov    DWORD PTR [rdi],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d47:
	/* 0x2d47: jmp    2d5b <generic_retkprobe_event+0x2d5b> */
	X86_SIM_X86_JMP(0x2d47, 0x2d5b, x86_l_2d5b);
x86_l_2d49:
	/* 0x2d49: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_2d4e:
	/* 0x2d4e: call   2d53 <generic_retkprobe_event+0x2d53> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_2d53:
	/* 0x2d53: jmp    2d5b <generic_retkprobe_event+0x2d5b> */
	X86_SIM_X86_JMP(0x2d53, 0x2d5b, x86_l_2d5b);
x86_l_2d55:
	/* 0x2d55: mov    DWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d5b:
	/* 0x2d5b: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d60:
	/* 0x2d60: lea    rdi,[rax+0xa4] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_2d67:
	/* 0x2d67: mov    rdx,rbp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_2d6a:
	/* 0x2d6a: add    rdx,0xd0 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 208ULL);
x86_l_2d71:
	/* 0x2d71: jns    2d7e <generic_retkprobe_event+0x2d7e> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2d71, 0x2d7e, x86_l_2d7e);
x86_l_2d73:
	/* 0x2d73: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_2d76:
	/* 0x2d76: jns    2d8a <generic_retkprobe_event+0x2d8a> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2d76, 0x2d8a, x86_l_2d8a);
x86_l_2d78:
	/* 0x2d78: mov    eax,DWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d7a:
	/* 0x2d7a: mov    DWORD PTR [rdi],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d7c:
	/* 0x2d7c: jmp    2d90 <generic_retkprobe_event+0x2d90> */
	X86_SIM_X86_JMP(0x2d7c, 0x2d90, x86_l_2d90);
x86_l_2d7e:
	/* 0x2d7e: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_2d83:
	/* 0x2d83: call   2d88 <generic_retkprobe_event+0x2d88> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_2d88:
	/* 0x2d88: jmp    2d90 <generic_retkprobe_event+0x2d90> */
	X86_SIM_X86_JMP(0x2d88, 0x2d90, x86_l_2d90);
x86_l_2d8a:
	/* 0x2d8a: mov    DWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d90:
	/* 0x2d90: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d95:
	/* 0x2d95: add    rdi,0xa8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 168ULL);
x86_l_2d9c:
	/* 0x2d9c: add    rbp,0x158 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 344ULL);
x86_l_2da3:
	/* 0x2da3: jns    2dba <generic_retkprobe_event+0x2dba> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2da3, 0x2dba, x86_l_2dba);
x86_l_2da5:
	/* 0x2da5: test   rbp,rbp */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_2da8:
	/* 0x2da8: jns    2dd2 <generic_retkprobe_event+0x2dd2> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2da8, 0x2dd2, x86_l_2dd2);
x86_l_2daa:
	/* 0x2daa: mov    eax,DWORD PTR [rbp+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2dad:
	/* 0x2dad: mov    DWORD PTR [rdi],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2daf:
	/* 0x2daf: mov    r12d,0x10 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 16ULL);
x86_l_2db5:
	/* 0x2db5: jmp    381f <generic_retkprobe_event+0x381f> */
	X86_SIM_X86_JMP(0x2db5, 0x381f, x86_l_381f);
x86_l_2dba:
	/* 0x2dba: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_2dbf:
	/* 0x2dbf: mov    rdx,rbp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_2dc2:
	/* 0x2dc2: call   2dc7 <generic_retkprobe_event+0x2dc7> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_2dc7:
	/* 0x2dc7: mov    r12d,0x10 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 16ULL);
x86_l_2dcd:
	/* 0x2dcd: jmp    381f <generic_retkprobe_event+0x381f> */
	X86_SIM_X86_JMP(0x2dcd, 0x381f, x86_l_381f);
x86_l_2dd2:
	/* 0x2dd2: mov    DWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2dd8:
	/* 0x2dd8: mov    r12d,0x10 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 16ULL);
x86_l_2dde:
	/* 0x2dde: jmp    381f <generic_retkprobe_event+0x381f> */
	X86_SIM_X86_JMP(0x2dde, 0x381f, x86_l_381f);
x86_l_2de3:
	/* 0x2de3: mov    esi,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_2de8:
	/* 0x2de8: call   2ded <generic_retkprobe_event+0x2ded> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_2ded:
	/* 0x2ded: jmp    33a2 <generic_retkprobe_event+0x33a2> */
	X86_SIM_X86_JMP(0x2ded, 0x33a2, x86_l_33a2);
x86_l_2df2:
	/* 0x2df2: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2df7:
	/* 0x2df7: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_2dfc:
	/* 0x2dfc: call   2e01 <generic_retkprobe_event+0x2e01> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_2e01:
	/* 0x2e01: jmp    3556 <generic_retkprobe_event+0x3556> */
	X86_SIM_X86_JMP(0x2e01, 0x3556, x86_l_3556);
x86_l_2e06:
	/* 0x2e06: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2e0b:
	/* 0x2e0b: mov    esi,0x10 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 16ULL);
x86_l_2e10:
	/* 0x2e10: call   2e15 <generic_retkprobe_event+0x2e15> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_2e15:
	/* 0x2e15: jmp    3590 <generic_retkprobe_event+0x3590> */
	X86_SIM_X86_JMP(0x2e15, 0x3590, x86_l_3590);
x86_l_2e1a:
	/* 0x2e1a: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2e1f:
	/* 0x2e1f: mov    DWORD PTR [rax],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e25:
	/* 0x2e25: mov    r15d,r14d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R15, X86_R14, X86_WIDTH_32, 0, 0);
x86_l_2e28:
	/* 0x2e28: and    r15d,0xfff */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2e2f:
	/* 0x2e2f: add    QWORD PTR [rsp+0x10],0xa0 */
	X86_SIM_RUN_OP(X86_OP_ALU_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 68719476896ULL);
x86_l_2e38:
	/* 0x2e38: mov    rsi,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_2e3b:
	/* 0x2e3b: add    rsi,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2e3f:
	/* 0x2e3f: test   r13,r13 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_2e42:
	/* 0x2e42: jns    2ea9 <generic_retkprobe_event+0x2ea9> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2e42, 0x2ea9, x86_l_2ea9);
x86_l_2e44:
	/* 0x2e44: mov    rax,r13 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_2e47:
	/* 0x2e47: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_2e4a:
	/* 0x2e4a: jns    2eb8 <generic_retkprobe_event+0x2eb8> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2e4a, 0x2eb8, x86_l_2eb8);
x86_l_2e4c:
	/* 0x2e4c: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_2e4e:
	/* 0x2e4e: cmp    r15d,0x4 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_2e52:
	/* 0x2e52: jb     2e73 <generic_retkprobe_event+0x2e73> */
	X86_SIM_X86_JCC(X86_CC_B, 0x2e52, 0x2e73, x86_l_2e73);
x86_l_2e54:
	/* 0x2e54: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_2e56:
	/* 0x2e56: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e5b:
	/* 0x2e5b: mov    rdx,rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_2e5e:
	/* 0x2e5e: mov    rcx,QWORD PTR [rax+rcx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2e62:
	/* 0x2e62: mov    QWORD PTR [rdi+rdx*1],rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_2e66:
	/* 0x2e66: lea    rcx,[rdx+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e6a:
	/* 0x2e6a: add    rdx,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2e6e:
	/* 0x2e6e: cmp    rdx,rsi */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_2e71:
	/* 0x2e71: jbe    2e5b <generic_retkprobe_event+0x2e5b> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x2e71, 0x2e5b, x86_l_2e5b);
x86_l_2e73:
	/* 0x2e73: test   r14b,0x4 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, 0, 4ULL);
x86_l_2e77:
	/* 0x2e77: jne    2ec8 <generic_retkprobe_event+0x2ec8> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2e77, 0x2ec8, x86_l_2ec8);
x86_l_2e79:
	/* 0x2e79: mov    edx,ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_2e7b:
	/* 0x2e7b: mov    esi,DWORD PTR [rax+rdx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_2e7e:
	/* 0x2e7e: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e83:
	/* 0x2e83: mov    DWORD PTR [rdi+rdx*1],esi */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_2e86:
	/* 0x2e86: or     ecx,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_OR, 4ULL);
x86_l_2e89:
	/* 0x2e89: test   r14b,0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, 0, 2ULL);
x86_l_2e8d:
	/* 0x2e8d: je     2ece <generic_retkprobe_event+0x2ece> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2e8d, 0x2ece, x86_l_2ece);
x86_l_2e8f:
	/* 0x2e8f: mov    edx,ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_2e91:
	/* 0x2e91: movzx  esi,WORD PTR [rax+rdx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RDX, 0, X86_WIDTH_16), 0ULL);
x86_l_2e95:
	/* 0x2e95: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e9a:
	/* 0x2e9a: mov    WORD PTR [rdi+rdx*1],si */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RSI, X86_WIDTH_16, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_2e9e:
	/* 0x2e9e: add    ecx,0x2 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_2ea1:
	/* 0x2ea1: test   r14b,0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_2ea5:
	/* 0x2ea5: je     2ee2 <generic_retkprobe_event+0x2ee2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2ea5, 0x2ee2, x86_l_2ee2);
x86_l_2ea7:
	/* 0x2ea7: jmp    2ed4 <generic_retkprobe_event+0x2ed4> */
	X86_SIM_X86_JMP(0x2ea7, 0x2ed4, x86_l_2ed4);
x86_l_2ea9:
	/* 0x2ea9: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2eae:
	/* 0x2eae: mov    rdx,r13 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_2eb1:
	/* 0x2eb1: call   2eb6 <generic_retkprobe_event+0x2eb6> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_2eb6:
	/* 0x2eb6: jmp    2ee2 <generic_retkprobe_event+0x2ee2> */
	X86_SIM_X86_JMP(0x2eb6, 0x2ee2, x86_l_2ee2);
x86_l_2eb8:
	/* 0x2eb8: mov    edx,esi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_2eba:
	/* 0x2eba: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ebf:
	/* 0x2ebf: xor    esi,esi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_2ec1:
	/* 0x2ec1: call   47c5 <__native_link_local_memset_zero_dynamic> */
	X86_SIM_X86_CALL(x86_l_47c5, 0x2ec6ULL);
x86_l_2ec6:
	/* 0x2ec6: jmp    2ee2 <generic_retkprobe_event+0x2ee2> */
	X86_SIM_X86_JMP(0x2ec6, 0x2ee2, x86_l_2ee2);
x86_l_2ec8:
	/* 0x2ec8: test   r14b,0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, 0, 2ULL);
x86_l_2ecc:
	/* 0x2ecc: jne    2e8f <generic_retkprobe_event+0x2e8f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2ecc, 0x2e8f, x86_l_2e8f);
x86_l_2ece:
	/* 0x2ece: test   r14b,0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_2ed2:
	/* 0x2ed2: je     2ee2 <generic_retkprobe_event+0x2ee2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2ed2, 0x2ee2, x86_l_2ee2);
x86_l_2ed4:
	/* 0x2ed4: mov    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_2ed6:
	/* 0x2ed6: movzx  eax,BYTE PTR [rax+rcx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2eda:
	/* 0x2eda: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2edf:
	/* 0x2edf: mov    BYTE PTR [rdx+rcx*1],al */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2ee2:
	/* 0x2ee2: mov    eax,r15d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_R15, X86_WIDTH_32, 0, 0);
x86_l_2ee5:
	/* 0x2ee5: lea    r12,[rax+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ee9:
	/* 0x2ee9: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2eee:
	/* 0x2eee: lea    rdi,[rcx+rax*1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2ef2:
	/* 0x2ef2: add    rdi,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2ef6:
	/* 0x2ef6: lea    rdx,[rax+r13*1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_2efa:
	/* 0x2efa: add    rdx,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2efe:
	/* 0x2efe: add    rdx,0xfffffffffffffffc */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551612ULL);
x86_l_2f02:
	/* 0x2f02: jns    2f0f <generic_retkprobe_event+0x2f0f> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2f02, 0x2f0f, x86_l_2f0f);
x86_l_2f04:
	/* 0x2f04: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_2f07:
	/* 0x2f07: jns    2f1b <generic_retkprobe_event+0x2f1b> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2f07, 0x2f1b, x86_l_2f1b);
x86_l_2f09:
	/* 0x2f09: mov    eax,DWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f0b:
	/* 0x2f0b: mov    DWORD PTR [rdi],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f0d:
	/* 0x2f0d: jmp    2f21 <generic_retkprobe_event+0x2f21> */
	X86_SIM_X86_JMP(0x2f0d, 0x2f21, x86_l_2f21);
x86_l_2f0f:
	/* 0x2f0f: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_2f14:
	/* 0x2f14: call   2f19 <generic_retkprobe_event+0x2f19> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_2f19:
	/* 0x2f19: jmp    2f21 <generic_retkprobe_event+0x2f21> */
	X86_SIM_X86_JMP(0x2f19, 0x2f21, x86_l_2f21);
x86_l_2f1b:
	/* 0x2f1b: mov    DWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f21:
	/* 0x2f21: add    r12,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2f25:
	/* 0x2f25: jmp    3d29 <generic_retkprobe_event+0x3d29> */
	X86_SIM_X86_JMP(0x2f25, 0x3d29, x86_l_3d29);
x86_l_2f2a:
	/* 0x2f2a: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2f2f:
	/* 0x2f2f: mov    DWORD PTR [rax],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f35:
	/* 0x2f35: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f3a:
	/* 0x2f3a: lea    rdi,[rax+0xa0] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2f41:
	/* 0x2f41: mov    rdx,rbp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_2f44:
	/* 0x2f44: add    rdx,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2f48:
	/* 0x2f48: jns    2f55 <generic_retkprobe_event+0x2f55> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2f48, 0x2f55, x86_l_2f55);
x86_l_2f4a:
	/* 0x2f4a: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_2f4d:
	/* 0x2f4d: jns    2f61 <generic_retkprobe_event+0x2f61> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2f4d, 0x2f61, x86_l_2f61);
x86_l_2f4f:
	/* 0x2f4f: mov    eax,DWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f51:
	/* 0x2f51: mov    DWORD PTR [rdi],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f53:
	/* 0x2f53: jmp    2f67 <generic_retkprobe_event+0x2f67> */
	X86_SIM_X86_JMP(0x2f53, 0x2f67, x86_l_2f67);
x86_l_2f55:
	/* 0x2f55: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_2f5a:
	/* 0x2f5a: call   2f5f <generic_retkprobe_event+0x2f5f> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_2f5f:
	/* 0x2f5f: jmp    2f67 <generic_retkprobe_event+0x2f67> */
	X86_SIM_X86_JMP(0x2f5f, 0x2f67, x86_l_2f67);
x86_l_2f61:
	/* 0x2f61: mov    DWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f67:
	/* 0x2f67: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f6c:
	/* 0x2f6c: add    rdi,0xa4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 164ULL);
x86_l_2f73:
	/* 0x2f73: add    rbp,0x30 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_2f77:
	/* 0x2f77: jns    2fa8 <generic_retkprobe_event+0x2fa8> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2f77, 0x2fa8, x86_l_2fa8);
x86_l_2f79:
	/* 0x2f79: test   rbp,rbp */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_2f7c:
	/* 0x2f7c: jns    2fc0 <generic_retkprobe_event+0x2fc0> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2f7c, 0x2fc0, x86_l_2fc0);
x86_l_2f7e:
	/* 0x2f7e: mov    rax,QWORD PTR [rbp+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f82:
	/* 0x2f82: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f87:
	/* 0x2f87: mov    QWORD PTR [rcx+0xa4],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_2f8e:
	/* 0x2f8e: mov    rax,QWORD PTR [rbp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f92:
	/* 0x2f92: mov    QWORD PTR [rcx+0xac],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_2f99:
	/* 0x2f99: mov    r12d,0x18 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 24ULL);
x86_l_2f9f:
	/* 0x2f9f: mov    r14,QWORD PTR [rsp] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2fa3:
	/* 0x2fa3: jmp    3828 <generic_retkprobe_event+0x3828> */
	X86_SIM_X86_JMP(0x2fa3, 0x3828, x86_l_3828);
x86_l_2fa8:
	/* 0x2fa8: mov    esi,0x10 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 16ULL);
x86_l_2fad:
	/* 0x2fad: mov    rdx,rbp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_2fb0:
	/* 0x2fb0: call   2fb5 <generic_retkprobe_event+0x2fb5> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_2fb5:
	/* 0x2fb5: mov    r12d,0x18 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 24ULL);
x86_l_2fbb:
	/* 0x2fbb: jmp    381f <generic_retkprobe_event+0x381f> */
	X86_SIM_X86_JMP(0x2fbb, 0x381f, x86_l_381f);
x86_l_2fc0:
	/* 0x2fc0: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_2fc8:
	/* 0x2fc8: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2fcf:
	/* 0x2fcf: mov    r12d,0x18 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 24ULL);
x86_l_2fd5:
	/* 0x2fd5: jmp    381f <generic_retkprobe_event+0x381f> */
	X86_SIM_X86_JMP(0x2fd5, 0x381f, x86_l_381f);
x86_l_2fda:
	/* 0x2fda: xor    esi,esi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_2fdc:
	/* 0x2fdc: mov    rdx,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_2fdf:
	/* 0x2fdf: call   47c5 <__native_link_local_memset_zero_dynamic> */
	X86_SIM_X86_CALL(x86_l_47c5, 0x2fe4ULL);
x86_l_2fe4:
	/* 0x2fe4: mov    DWORD PTR [r14+0x9c],0xfffffffe */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 674309865470ULL);
x86_l_2fef:
	/* 0x2fef: mov    r12d,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_2ff5:
	/* 0x2ff5: jmp    381f <generic_retkprobe_event+0x381f> */
	X86_SIM_X86_JMP(0x2ff5, 0x381f, x86_l_381f);
x86_l_2ffa:
	/* 0x2ffa: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_2ffd:
	/* 0x2ffd: jns    37d8 <generic_retkprobe_event+0x37d8> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2ffd, 0x37d8, x86_l_37d8);
x86_l_3003:
	/* 0x3003: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_3005:
	/* 0x3005: mov    rsi,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_300a:
	/* 0x300a: cmp    rax,0x3e */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, 0, 62ULL);
x86_l_300e:
	/* 0x300e: je     3cd5 <generic_retkprobe_event+0x3cd5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x300e, 0x3cd5, x86_l_3cd5);
x86_l_3014:
	/* 0x3014: movzx  ecx,BYTE PTR [rdx+rax*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_3018:
	/* 0x3018: mov    BYTE PTR [rsi+rax*1],cl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_301b:
	/* 0x301b: inc    rax */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_301e:
	/* 0x301e: test   cl,cl */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8, 0, 0);
x86_l_3020:
	/* 0x3020: jne    300a <generic_retkprobe_event+0x300a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x3020, 0x300a, x86_l_300a);
x86_l_3022:
	/* 0x3022: jmp    1a39 <generic_retkprobe_event+0x1a39> */
	X86_SIM_X86_JMP(0x3022, 0x1a39, x86_l_1a39);
x86_l_3027:
	/* 0x3027: lea    rdi,[rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_302c:
	/* 0x302c: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_3031:
	/* 0x3031: mov    rdx,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_3034:
	/* 0x3034: call   3039 <generic_retkprobe_event+0x3039> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_3039:
	/* 0x3039: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_303e:
	/* 0x303e: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_3041:
	/* 0x3041: jns    3843 <generic_retkprobe_event+0x3843> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x3041, 0x3843, x86_l_3843);
x86_l_3047:
	/* 0x3047: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_304a:
	/* 0x304a: jns    3a4f <generic_retkprobe_event+0x3a4f> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x304a, 0x3a4f, x86_l_3a4f);
x86_l_3050:
	/* 0x3050: mov    rax,QWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3053:
	/* 0x3053: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_305b:
	/* 0x305b: jmp    3a5b <generic_retkprobe_event+0x3a5b> */
	X86_SIM_X86_JMP(0x305b, 0x3a5b, x86_l_3a5b);
x86_l_3060:
	/* 0x3060: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3065:
	/* 0x3065: mov    BYTE PTR [rcx+rax*1],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3069:
	/* 0x3069: mov    r12d,esi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R12, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_306c:
	/* 0x306c: jmp    260c <generic_retkprobe_event+0x260c> */
	X86_SIM_X86_JMP(0x306c, 0x260c, x86_l_260c);
x86_l_3071:
	/* 0x3071: lea    rdi,[rsp+0x80] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3079:
	/* 0x3079: mov    esi,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_307e:
	/* 0x307e: call   3083 <generic_retkprobe_event+0x3083> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_3083:
	/* 0x3083: movzx  eax,BYTE PTR [rsp+0x80] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 128ULL);
x86_l_308b:
	/* 0x308b: jmp    3871 <generic_retkprobe_event+0x3871> */
	X86_SIM_X86_JMP(0x308b, 0x3871, x86_l_3871);
x86_l_3090:
	/* 0x3090: add    r12,0x3 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 3ULL);
x86_l_3094:
	/* 0x3094: test   r12,r12 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_3097:
	/* 0x3097: jns    39b9 <generic_retkprobe_event+0x39b9> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x3097, 0x39b9, x86_l_39b9);
x86_l_309d:
	/* 0x309d: mov    rax,QWORD PTR [r12] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_30a1:
	/* 0x30a1: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_30a6:
	/* 0x30a6: mov    QWORD PTR [rcx+0xa0],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_30ad:
	/* 0x30ad: mov    rax,QWORD PTR [r12+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_30b2:
	/* 0x30b2: mov    QWORD PTR [rcx+0xa8],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_30b9:
	/* 0x30b9: mov    rax,QWORD PTR [r12+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_30be:
	/* 0x30be: mov    QWORD PTR [rcx+0xb0],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_30c5:
	/* 0x30c5: mov    rax,QWORD PTR [r12+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_30ca:
	/* 0x30ca: mov    QWORD PTR [rcx+0xb8],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_30d1:
	/* 0x30d1: mov    rax,QWORD PTR [r12+0x20] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_30d6:
	/* 0x30d6: mov    QWORD PTR [rcx+0xc0],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_30dd:
	/* 0x30dd: mov    rax,QWORD PTR [r12+0x28] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_30e2:
	/* 0x30e2: mov    QWORD PTR [rcx+0xc8],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_30e9:
	/* 0x30e9: mov    rax,QWORD PTR [r12+0x30] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_30ee:
	/* 0x30ee: mov    QWORD PTR [rcx+0xd0],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_30f5:
	/* 0x30f5: mov    rax,QWORD PTR [r12+0x38] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_30fa:
	/* 0x30fa: mov    QWORD PTR [rcx+0xd8],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_3101:
	/* 0x3101: mov    rax,QWORD PTR [r12+0x40] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3106:
	/* 0x3106: mov    QWORD PTR [rcx+0xe0],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_310d:
	/* 0x310d: mov    rax,QWORD PTR [r12+0x48] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3112:
	/* 0x3112: mov    QWORD PTR [rcx+0xe8],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_3119:
	/* 0x3119: mov    rax,QWORD PTR [r12+0x50] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_311e:
	/* 0x311e: mov    QWORD PTR [rcx+0xf0],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_3125:
	/* 0x3125: mov    rax,QWORD PTR [r12+0x58] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_312a:
	/* 0x312a: mov    QWORD PTR [rcx+0xf8],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_3131:
	/* 0x3131: mov    rax,QWORD PTR [r12+0x60] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_3136:
	/* 0x3136: mov    QWORD PTR [rcx+0x100],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_313d:
	/* 0x313d: movzx  eax,WORD PTR [r12+0x68] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 104ULL);
x86_l_3143:
	/* 0x3143: mov    WORD PTR [rcx+0x108],ax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_314a:
	/* 0x314a: movzx  eax,BYTE PTR [r12+0x6a] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 106ULL);
x86_l_3150:
	/* 0x3150: mov    BYTE PTR [rcx+0x10a],al */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 266ULL);
x86_l_3156:
	/* 0x3156: mov    BYTE PTR [rcx+0x9f],0x6b */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 682899800171ULL);
x86_l_315d:
	/* 0x315d: mov    r14,QWORD PTR [rsp] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3161:
	/* 0x3161: jmp    4159 <generic_retkprobe_event+0x4159> */
	X86_SIM_X86_JMP(0x3161, 0x4159, x86_l_4159);
x86_l_3166:
	/* 0x3166: mov    QWORD PTR [rsp+0x80],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_3172:
	/* 0x3172: add    r12,0x18 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_3176:
	/* 0x3176: jns    318b <generic_retkprobe_event+0x318b> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x3176, 0x318b, x86_l_318b);
x86_l_3178:
	/* 0x3178: test   r12,r12 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_317b:
	/* 0x317b: jns    31aa <generic_retkprobe_event+0x31aa> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x317b, 0x31aa, x86_l_31aa);
x86_l_317d:
	/* 0x317d: mov    r14,QWORD PTR [r12] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3181:
	/* 0x3181: mov    QWORD PTR [rsp+0xa0],r14 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_3189:
	/* 0x3189: jmp    31b9 <generic_retkprobe_event+0x31b9> */
	X86_SIM_X86_JMP(0x3189, 0x31b9, x86_l_31b9);
x86_l_318b:
	/* 0x318b: lea    rdi,[rsp+0xa0] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_3193:
	/* 0x3193: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_3198:
	/* 0x3198: mov    rdx,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_319b:
	/* 0x319b: call   31a0 <generic_retkprobe_event+0x31a0> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_31a0:
	/* 0x31a0: mov    r14,QWORD PTR [rsp+0xa0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_31a8:
	/* 0x31a8: jmp    31b9 <generic_retkprobe_event+0x31b9> */
	X86_SIM_X86_JMP(0x31a8, 0x31b9, x86_l_31b9);
x86_l_31aa:
	/* 0x31aa: mov    QWORD PTR [rsp+0xa0],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_31b6:
	/* 0x31b6: xor    r14d,r14d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_31b9:
	/* 0x31b9: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_31c1:
	/* 0x31c1: cmp    r14,0xfff */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, 0, 4095ULL);
x86_l_31c8:
	/* 0x31c8: mov    r12d,0xfff */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 4095ULL);
x86_l_31ce:
	/* 0x31ce: cmovb  r12,r14 */
	X86_SIM_RUN_OP(X86_OP_CMOV, X86_R12, X86_R14, X86_WIDTH_64, X86_CC_B, 0);
x86_l_31d2:
	/* 0x31d2: mov    rdi,r13 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_31d5:
	/* 0x31d5: add    rdi,0xa4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 164ULL);
x86_l_31dc:
	/* 0x31dc: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_31df:
	/* 0x31df: jns    3b15 <generic_retkprobe_event+0x3b15> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x31df, 0x3b15, x86_l_3b15);
x86_l_31e5:
	/* 0x31e5: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_31e8:
	/* 0x31e8: jns    3b26 <generic_retkprobe_event+0x3b26> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x31e8, 0x3b26, x86_l_3b26);
x86_l_31ee:
	/* 0x31ee: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_31f0:
	/* 0x31f0: cmp    r12d,0x8 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_31f4:
	/* 0x31f4: jb     3210 <generic_retkprobe_event+0x3210> */
	X86_SIM_X86_JCC(X86_CC_B, 0x31f4, 0x3210, x86_l_3210);
x86_l_31f6:
	/* 0x31f6: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_31f8:
	/* 0x31f8: mov    rcx,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_31fb:
	/* 0x31fb: mov    rax,QWORD PTR [rdx+rax*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_31ff:
	/* 0x31ff: mov    QWORD PTR [rdi+rcx*1],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3203:
	/* 0x3203: lea    rax,[rcx+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3207:
	/* 0x3207: add    rcx,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_320b:
	/* 0x320b: cmp    rcx,r12 */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RCX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_320e:
	/* 0x320e: jbe    31f8 <generic_retkprobe_event+0x31f8> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x320e, 0x31f8, x86_l_31f8);
x86_l_3210:
	/* 0x3210: test   r12b,0x4 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, 0, 4ULL);
x86_l_3214:
	/* 0x3214: jne    3a07 <generic_retkprobe_event+0x3a07> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x3214, 0x3a07, x86_l_3a07);
x86_l_321a:
	/* 0x321a: test   r12b,0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, 0, 2ULL);
x86_l_321e:
	/* 0x321e: jne    3a1c <generic_retkprobe_event+0x3a1c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x321e, 0x3a1c, x86_l_3a1c);
x86_l_3224:
	/* 0x3224: test   r12b,0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_3228:
	/* 0x3228: jne    3a33 <generic_retkprobe_event+0x3a33> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x3228, 0x3a33, x86_l_3a33);
x86_l_322e:
	/* 0x322e: jmp    3d17 <generic_retkprobe_event+0x3d17> */
	X86_SIM_X86_JMP(0x322e, 0x3d17, x86_l_3d17);
x86_l_3233:
	/* 0x3233: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_3235:
	/* 0x3235: add    rax,0x360 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 864ULL);
x86_l_323b:
	/* 0x323b: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_323e:
	/* 0x323e: jns    3245 <generic_retkprobe_event+0x3245> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x323e, 0x3245, x86_l_3245);
x86_l_3240:
	/* 0x3240: mov    rax,QWORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3243:
	/* 0x3243: jmp    3247 <generic_retkprobe_event+0x3247> */
	X86_SIM_X86_JMP(0x3243, 0x3247, x86_l_3247);
x86_l_3245:
	/* 0x3245: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_3247:
	/* 0x3247: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_324c:
	/* 0x324c: mov    QWORD PTR [rcx+0xa4],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_3253:
	/* 0x3253: add    rbp,0x58 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 88ULL);
x86_l_3257:
	/* 0x3257: mov    r12d,0x50 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 80ULL);
x86_l_325d:
	/* 0x325d: test   rbp,rbp */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_3260:
	/* 0x3260: jns    381f <generic_retkprobe_event+0x381f> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x3260, 0x381f, x86_l_381f);
x86_l_3266:
	/* 0x3266: mov    eax,DWORD PTR [rbp+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3269:
	/* 0x3269: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_326b:
	/* 0x326b: test   eax,eax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_326d:
	/* 0x326d: setne  cl */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_CC_NE, 0);
x86_l_3270:
	/* 0x3270: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3275:
	/* 0x3275: mov    DWORD PTR [rax],ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3277:
	/* 0x3277: jmp    381f <generic_retkprobe_event+0x381f> */
	X86_SIM_X86_JMP(0x3277, 0x381f, x86_l_381f);
x86_l_327c:
	/* 0x327c: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3281:
	/* 0x3281: mov    QWORD PTR [rax+0x78],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_3289:
	/* 0x3289: mov    QWORD PTR [rax+0x70],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_3291:
	/* 0x3291: mov    QWORD PTR [rax+0x68],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_3299:
	/* 0x3299: mov    QWORD PTR [rax+0x60],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_32a1:
	/* 0x32a1: mov    QWORD PTR [rax+0x58],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_32a9:
	/* 0x32a9: mov    QWORD PTR [rax+0x50],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_32b1:
	/* 0x32b1: mov    QWORD PTR [rax+0x48],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_32b9:
	/* 0x32b9: mov    QWORD PTR [rax+0x40],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_32c1:
	/* 0x32c1: mov    QWORD PTR [rax+0x38],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_32c9:
	/* 0x32c9: mov    QWORD PTR [rax+0x30],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_32d1:
	/* 0x32d1: mov    QWORD PTR [rax+0x28],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_32d9:
	/* 0x32d9: mov    QWORD PTR [rax+0x20],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_32e1:
	/* 0x32e1: mov    QWORD PTR [rax+0x18],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_32e9:
	/* 0x32e9: mov    QWORD PTR [rax+0x10],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_32f1:
	/* 0x32f1: mov    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_32f9:
	/* 0x32f9: mov    QWORD PTR [rax],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3300:
	/* 0x3300: jmp    2722 <generic_retkprobe_event+0x2722> */
	X86_SIM_X86_JMP(0x3300, 0x2722, x86_l_2722);
x86_l_3305:
	/* 0x3305: lea    rdi,[rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_330a:
	/* 0x330a: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_330f:
	/* 0x330f: call   3314 <generic_retkprobe_event+0x3314> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_3314:
	/* 0x3314: mov    eax,DWORD PTR [rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3318:
	/* 0x3318: jmp    3b50 <generic_retkprobe_event+0x3b50> */
	X86_SIM_X86_JMP(0x3318, 0x3b50, x86_l_3b50);
x86_l_331d:
	/* 0x331d: mov    esi,0x10 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 16ULL);
x86_l_3322:
	/* 0x3322: call   3327 <generic_retkprobe_event+0x3327> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_3327:
	/* 0x3327: jmp    3b88 <generic_retkprobe_event+0x3b88> */
	X86_SIM_X86_JMP(0x3327, 0x3b88, x86_l_3b88);
x86_l_332c:
	/* 0x332c: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3331:
	/* 0x3331: mov    BYTE PTR [rax+0xea],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 1005022347264ULL);
x86_l_3338:
	/* 0x3338: add    rbp,0x360 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 864ULL);
x86_l_333f:
	/* 0x333f: test   rbp,rbp */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_3342:
	/* 0x3342: jns    3356 <generic_retkprobe_event+0x3356> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x3342, 0x3356, x86_l_3356);
x86_l_3344:
	/* 0x3344: mov    rax,QWORD PTR [rbp+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3348:
	/* 0x3348: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_334d:
	/* 0x334d: mov    QWORD PTR [rcx+0xa4],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_3354:
	/* 0x3354: jmp    3366 <generic_retkprobe_event+0x3366> */
	X86_SIM_X86_JMP(0x3354, 0x3366, x86_l_3366);
x86_l_3356:
	/* 0x3356: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_335b:
	/* 0x335b: mov    QWORD PTR [rcx+0xa4],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_3366:
	/* 0x3366: mov    r12d,0x50 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 80ULL);
x86_l_336c:
	/* 0x336c: mov    r14,QWORD PTR [rsp] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3370:
	/* 0x3370: jmp    3828 <generic_retkprobe_event+0x3828> */
	X86_SIM_X86_JMP(0x3370, 0x3828, x86_l_3828);
x86_l_3375:
	/* 0x3375: mov    r12d,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_337b:
	/* 0x337b: mov    r14,QWORD PTR [rsp] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_337f:
	/* 0x337f: jmp    260c <generic_retkprobe_event+0x260c> */
	X86_SIM_X86_JMP(0x337f, 0x260c, x86_l_260c);
x86_l_3384:
	/* 0x3384: mov    esi,ebp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_RBP, X86_WIDTH_32, 0, 0);
x86_l_3386:
	/* 0x3386: call   338b <generic_retkprobe_event+0x338b> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_338b:
	/* 0x338b: mov    ecx,0xfffffffe */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 4294967294ULL);
x86_l_3390:
	/* 0x3390: test   eax,eax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_3392:
	/* 0x3392: js     3c7e <generic_retkprobe_event+0x3c7e> */
	X86_SIM_X86_JCC(X86_CC_S, 0x3392, 0x3c7e, x86_l_3c7e);
x86_l_3398:
	/* 0x3398: jmp    41a4 <generic_retkprobe_event+0x41a4> */
	X86_SIM_X86_JMP(0x3398, 0x41a4, x86_l_41a4);
x86_l_339d:
	/* 0x339d: mov    WORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_33a2:
	/* 0x33a2: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_33a7:
	/* 0x33a7: lea    rdi,[rax+0xd6] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 214ULL);
x86_l_33ae:
	/* 0x33ae: mov    rdx,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_33b1:
	/* 0x33b1: add    rdx,0x12 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 18ULL);
x86_l_33b5:
	/* 0x33b5: jns    33c3 <generic_retkprobe_event+0x33c3> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x33b5, 0x33c3, x86_l_33c3);
x86_l_33b7:
	/* 0x33b7: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_33ba:
	/* 0x33ba: jns    33cf <generic_retkprobe_event+0x33cf> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x33ba, 0x33cf, x86_l_33cf);
x86_l_33bc:
	/* 0x33bc: movzx  eax,BYTE PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_33bf:
	/* 0x33bf: mov    BYTE PTR [rdi],al */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_33c1:
	/* 0x33c1: jmp    33d2 <generic_retkprobe_event+0x33d2> */
	X86_SIM_X86_JMP(0x33c1, 0x33d2, x86_l_33d2);
x86_l_33c3:
	/* 0x33c3: mov    esi,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_33c8:
	/* 0x33c8: call   33cd <generic_retkprobe_event+0x33cd> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_33cd:
	/* 0x33cd: jmp    33d2 <generic_retkprobe_event+0x33d2> */
	X86_SIM_X86_JMP(0x33cd, 0x33d2, x86_l_33d2);
x86_l_33cf:
	/* 0x33cf: mov    BYTE PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_33d2:
	/* 0x33d2: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_33d7:
	/* 0x33d7: lea    rdi,[rax+0xd4] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 212ULL);
x86_l_33de:
	/* 0x33de: mov    rdx,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_33e1:
	/* 0x33e1: add    rdx,0x21e */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 542ULL);
x86_l_33e8:
	/* 0x33e8: jns    33f7 <generic_retkprobe_event+0x33f7> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x33e8, 0x33f7, x86_l_33f7);
x86_l_33ea:
	/* 0x33ea: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_33ed:
	/* 0x33ed: jns    3403 <generic_retkprobe_event+0x3403> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x33ed, 0x3403, x86_l_3403);
x86_l_33ef:
	/* 0x33ef: movzx  eax,WORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_33f2:
	/* 0x33f2: mov    WORD PTR [rdi],ax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_33f5:
	/* 0x33f5: jmp    3408 <generic_retkprobe_event+0x3408> */
	X86_SIM_X86_JMP(0x33f5, 0x3408, x86_l_3408);
x86_l_33f7:
	/* 0x33f7: mov    esi,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_33fc:
	/* 0x33fc: call   3401 <generic_retkprobe_event+0x3401> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_3401:
	/* 0x3401: jmp    3408 <generic_retkprobe_event+0x3408> */
	X86_SIM_X86_JMP(0x3401, 0x3408, x86_l_3408);
x86_l_3403:
	/* 0x3403: mov    WORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3408:
	/* 0x3408: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_340d:
	/* 0x340d: lea    rdi,[rax+0xc0] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_3414:
	/* 0x3414: mov    rdx,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_3417:
	/* 0x3417: add    rdx,0x21c */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 540ULL);
x86_l_341e:
	/* 0x341e: jns    342d <generic_retkprobe_event+0x342d> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x341e, 0x342d, x86_l_342d);
x86_l_3420:
	/* 0x3420: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_3423:
	/* 0x3423: jns    3439 <generic_retkprobe_event+0x3439> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x3423, 0x3439, x86_l_3439);
x86_l_3425:
	/* 0x3425: movzx  eax,WORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3428:
	/* 0x3428: mov    WORD PTR [rdi],ax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_342b:
	/* 0x342b: jmp    343e <generic_retkprobe_event+0x343e> */
	X86_SIM_X86_JMP(0x342b, 0x343e, x86_l_343e);
x86_l_342d:
	/* 0x342d: mov    esi,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_3432:
	/* 0x3432: call   3437 <generic_retkprobe_event+0x3437> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_3437:
	/* 0x3437: jmp    343e <generic_retkprobe_event+0x343e> */
	X86_SIM_X86_JMP(0x3437, 0x343e, x86_l_343e);
x86_l_3439:
	/* 0x3439: mov    WORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_343e:
	/* 0x343e: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3443:
	/* 0x3443: lea    rdi,[rax+0xcc] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_344a:
	/* 0x344a: mov    rdx,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_344d:
	/* 0x344d: add    rdx,0x214 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 532ULL);
x86_l_3454:
	/* 0x3454: jns    3461 <generic_retkprobe_event+0x3461> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x3454, 0x3461, x86_l_3461);
x86_l_3456:
	/* 0x3456: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_3459:
	/* 0x3459: jns    346d <generic_retkprobe_event+0x346d> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x3459, 0x346d, x86_l_346d);
x86_l_345b:
	/* 0x345b: mov    eax,DWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_345d:
	/* 0x345d: mov    DWORD PTR [rdi],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_345f:
	/* 0x345f: jmp    3473 <generic_retkprobe_event+0x3473> */
	X86_SIM_X86_JMP(0x345f, 0x3473, x86_l_3473);
x86_l_3461:
	/* 0x3461: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_3466:
	/* 0x3466: call   346b <generic_retkprobe_event+0x346b> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_346b:
	/* 0x346b: jmp    3473 <generic_retkprobe_event+0x3473> */
	X86_SIM_X86_JMP(0x346b, 0x3473, x86_l_3473);
x86_l_346d:
	/* 0x346d: mov    DWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3473:
	/* 0x3473: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3478:
	/* 0x3478: lea    rdi,[rax+0xd0] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_347f:
	/* 0x347f: mov    rdx,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_3482:
	/* 0x3482: add    rdx,0x210 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 528ULL);
x86_l_3489:
	/* 0x3489: jns    3496 <generic_retkprobe_event+0x3496> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x3489, 0x3496, x86_l_3496);
x86_l_348b:
	/* 0x348b: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_348e:
	/* 0x348e: jns    34a2 <generic_retkprobe_event+0x34a2> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x348e, 0x34a2, x86_l_34a2);
x86_l_3490:
	/* 0x3490: mov    eax,DWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3492:
	/* 0x3492: mov    DWORD PTR [rdi],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3494:
	/* 0x3494: jmp    34a8 <generic_retkprobe_event+0x34a8> */
	X86_SIM_X86_JMP(0x3494, 0x34a8, x86_l_34a8);
x86_l_3496:
	/* 0x3496: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_349b:
	/* 0x349b: call   34a0 <generic_retkprobe_event+0x34a0> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_34a0:
	/* 0x34a0: jmp    34a8 <generic_retkprobe_event+0x34a8> */
	X86_SIM_X86_JMP(0x34a0, 0x34a8, x86_l_34a8);
x86_l_34a2:
	/* 0x34a2: mov    DWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_34a8:
	/* 0x34a8: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_34ad:
	/* 0x34ad: lea    r13,[rax+0xac] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_34b4:
	/* 0x34b4: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_34b9:
	/* 0x34b9: mov    QWORD PTR [rax+0x18],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_34c1:
	/* 0x34c1: mov    QWORD PTR [rax+0x10],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_34c9:
	/* 0x34c9: mov    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_34d1:
	/* 0x34d1: mov    QWORD PTR [rax],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_34d8:
	/* 0x34d8: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_34dd:
	/* 0x34dd: movzx  eax,WORD PTR [rax+0xc2] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 194ULL);
x86_l_34e4:
	/* 0x34e4: cmp    eax,0xa */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 10ULL);
x86_l_34e7:
	/* 0x34e7: je     3516 <generic_retkprobe_event+0x3516> */
	X86_SIM_X86_JCC(X86_CC_E, 0x34e7, 0x3516, x86_l_3516);
x86_l_34e9:
	/* 0x34e9: cmp    eax,0x2 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_34ec:
	/* 0x34ec: jne    3e0b <generic_retkprobe_event+0x3e0b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x34ec, 0x3e0b, x86_l_3e0b);
x86_l_34f2:
	/* 0x34f2: mov    rdx,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_34f5:
	/* 0x34f5: add    rdx,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_34f9:
	/* 0x34f9: jns    39df <generic_retkprobe_event+0x39df> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x34f9, 0x39df, x86_l_39df);
x86_l_34ff:
	/* 0x34ff: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_3502:
	/* 0x3502: jns    3d85 <generic_retkprobe_event+0x3d85> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x3502, 0x3d85, x86_l_3d85);
x86_l_3508:
	/* 0x3508: mov    eax,DWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_350a:
	/* 0x350a: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_350f:
	/* 0x350f: mov    DWORD PTR [rcx],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3511:
	/* 0x3511: jmp    3d90 <generic_retkprobe_event+0x3d90> */
	X86_SIM_X86_JMP(0x3511, 0x3d90, x86_l_3d90);
x86_l_3516:
	/* 0x3516: mov    rdx,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_3519:
	/* 0x3519: add    rdx,0x48 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 72ULL);
x86_l_351d:
	/* 0x351d: jns    39f3 <generic_retkprobe_event+0x39f3> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x351d, 0x39f3, x86_l_39f3);
x86_l_3523:
	/* 0x3523: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_3526:
	/* 0x3526: jns    3dbc <generic_retkprobe_event+0x3dbc> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x3526, 0x3dbc, x86_l_3dbc);
x86_l_352c:
	/* 0x352c: mov    rax,QWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_352f:
	/* 0x352f: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3534:
	/* 0x3534: mov    QWORD PTR [rcx+0x9c],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_353b:
	/* 0x353b: mov    rax,QWORD PTR [rdx+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_353f:
	/* 0x353f: mov    QWORD PTR [rcx+0xa4],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_3546:
	/* 0x3546: jmp    3dd0 <generic_retkprobe_event+0x3dd0> */
	X86_SIM_X86_JMP(0x3546, 0x3dd0, x86_l_3dd0);
x86_l_354b:
	/* 0x354b: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3550:
	/* 0x3550: mov    DWORD PTR [rax],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3556:
	/* 0x3556: test   r12,r12 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_3559:
	/* 0x3559: js     3568 <generic_retkprobe_event+0x3568> */
	X86_SIM_X86_JCC(X86_CC_S, 0x3559, 0x3568, x86_l_3568);
x86_l_355b:
	/* 0x355b: mov    rdi,r13 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_355e:
	/* 0x355e: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_3563:
	/* 0x3563: mov    rdx,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_3566:
	/* 0x3566: jmp    35c6 <generic_retkprobe_event+0x35c6> */
	X86_SIM_X86_JMP(0x3566, 0x35c6, x86_l_35c6);
x86_l_3568:
	/* 0x3568: mov    rax,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_356b:
	/* 0x356b: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_356e:
	/* 0x356e: jns    385a <generic_retkprobe_event+0x385a> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x356e, 0x385a, x86_l_385a);
x86_l_3574:
	/* 0x3574: mov    eax,DWORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3576:
	/* 0x3576: mov    DWORD PTR [r13+0x0],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_357a:
	/* 0x357a: jmp    35cb <generic_retkprobe_event+0x35cb> */
	X86_SIM_X86_JMP(0x357a, 0x35cb, x86_l_35cb);
x86_l_357c:
	/* 0x357c: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3581:
	/* 0x3581: mov    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_3589:
	/* 0x3589: mov    QWORD PTR [rax],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3590:
	/* 0x3590: mov    rdx,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_3593:
	/* 0x3593: add    rdx,0x38 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 56ULL);
x86_l_3597:
	/* 0x3597: jns    35be <generic_retkprobe_event+0x35be> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x3597, 0x35be, x86_l_35be);
x86_l_3599:
	/* 0x3599: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_359c:
	/* 0x359c: jns    368b <generic_retkprobe_event+0x368b> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x359c, 0x368b, x86_l_368b);
x86_l_35a2:
	/* 0x35a2: mov    rax,QWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_35a5:
	/* 0x35a5: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_35aa:
	/* 0x35aa: mov    QWORD PTR [rcx+0xac],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_35b1:
	/* 0x35b1: mov    rax,QWORD PTR [rdx+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_35b5:
	/* 0x35b5: mov    QWORD PTR [rcx+0xb4],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 180ULL);
x86_l_35bc:
	/* 0x35bc: jmp    35cb <generic_retkprobe_event+0x35cb> */
	X86_SIM_X86_JMP(0x35bc, 0x35cb, x86_l_35cb);
x86_l_35be:
	/* 0x35be: mov    rdi,r13 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_35c1:
	/* 0x35c1: mov    esi,0x10 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 16ULL);
x86_l_35c6:
	/* 0x35c6: call   35cb <generic_retkprobe_event+0x35cb> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_35cb:
	/* 0x35cb: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_35d0:
	/* 0x35d0: lea    rdi,[rcx+0xbc] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_35d7:
	/* 0x35d7: lea    r13,[r12+0xc] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_35dc:
	/* 0x35dc: add    r12,0xe */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 14ULL);
x86_l_35e0:
	/* 0x35e0: jns    35f1 <generic_retkprobe_event+0x35f1> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x35e0, 0x35f1, x86_l_35f1);
x86_l_35e2:
	/* 0x35e2: test   r12,r12 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_35e5:
	/* 0x35e5: jns    3605 <generic_retkprobe_event+0x3605> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x35e5, 0x3605, x86_l_3605);
x86_l_35e7:
	/* 0x35e7: movzx  eax,WORD PTR [r12] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_35ec:
	/* 0x35ec: mov    WORD PTR [rdi],ax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_35ef:
	/* 0x35ef: jmp    360a <generic_retkprobe_event+0x360a> */
	X86_SIM_X86_JMP(0x35ef, 0x360a, x86_l_360a);
x86_l_35f1:
	/* 0x35f1: mov    esi,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_35f6:
	/* 0x35f6: mov    rdx,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_35f9:
	/* 0x35f9: call   35fe <generic_retkprobe_event+0x35fe> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_35fe:
	/* 0x35fe: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3603:
	/* 0x3603: jmp    360a <generic_retkprobe_event+0x360a> */
	X86_SIM_X86_JMP(0x3603, 0x360a, x86_l_360a);
x86_l_3605:
	/* 0x3605: mov    WORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_360a:
	/* 0x360a: add    rcx,0xbe */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 190ULL);
x86_l_3611:
	/* 0x3611: test   r13,r13 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_3614:
	/* 0x3614: jns    3622 <generic_retkprobe_event+0x3622> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x3614, 0x3622, x86_l_3622);
x86_l_3616:
	/* 0x3616: test   r13,r13 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_3619:
	/* 0x3619: jns    363e <generic_retkprobe_event+0x363e> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x3619, 0x363e, x86_l_363e);
x86_l_361b:
	/* 0x361b: movzx  eax,WORD PTR [r13+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3620:
	/* 0x3620: jmp    3640 <generic_retkprobe_event+0x3640> */
	X86_SIM_X86_JMP(0x3620, 0x3640, x86_l_3640);
x86_l_3622:
	/* 0x3622: mov    rdi,rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_3625:
	/* 0x3625: mov    r14,rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R14, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_3628:
	/* 0x3628: mov    esi,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_362d:
	/* 0x362d: mov    rdx,r13 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_3630:
	/* 0x3630: call   3635 <generic_retkprobe_event+0x3635> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_3635:
	/* 0x3635: mov    rcx,r14 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_3638:
	/* 0x3638: movzx  eax,WORD PTR [r14] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_363c:
	/* 0x363c: jmp    3640 <generic_retkprobe_event+0x3640> */
	X86_SIM_X86_JMP(0x363c, 0x3640, x86_l_3640);
x86_l_363e:
	/* 0x363e: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_3640:
	/* 0x3640: mov    r14,QWORD PTR [rsp] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3644:
	/* 0x3644: movbe  WORD PTR [rcx],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3649:
	/* 0x3649: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_364e:
	/* 0x364e: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3653:
	/* 0x3653: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)socktrack_map));
x86_l_365a:
	/* 0x365a: lea    rsi,[rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_365f:
	/* 0x365f: call   3664 <generic_retkprobe_event+0x3664> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_3664:
	/* 0x3664: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_3667:
	/* 0x3667: mov    r13d,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_366d:
	/* 0x366d: je     412c <generic_retkprobe_event+0x412c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x366d, 0x412c, x86_l_412c);
x86_l_3673:
	/* 0x3673: mov    ecx,DWORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3675:
	/* 0x3675: mov    DWORD PTR [rbp+0x10],ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3678:
	/* 0x3678: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_367c:
	/* 0x367c: mov    QWORD PTR [rbp+0x18],rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3680:
	/* 0x3680: mov    eax,DWORD PTR [rax+0x4] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3683:
	/* 0x3683: mov    DWORD PTR [rbp+0x7c],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_3686:
	/* 0x3686: jmp    412c <generic_retkprobe_event+0x412c> */
	X86_SIM_X86_JMP(0x3686, 0x412c, x86_l_412c);
x86_l_368b:
	/* 0x368b: mov    QWORD PTR [r13+0x8],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_3693:
	/* 0x3693: mov    QWORD PTR [r13+0x0],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_369b:
	/* 0x369b: jmp    35cb <generic_retkprobe_event+0x35cb> */
	X86_SIM_X86_JMP(0x369b, 0x35cb, x86_l_35cb);
x86_l_36a0:
	/* 0x36a0: mov    rdi,rbp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_36a3:
	/* 0x36a3: mov    esi,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_36a8:
	/* 0x36a8: call   36ad <generic_retkprobe_event+0x36ad> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_36ad:
	/* 0x36ad: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_36b0:
	/* 0x36b0: js     3eeb <generic_retkprobe_event+0x3eeb> */
	X86_SIM_X86_JCC(X86_CC_S, 0x36b0, 0x3eeb, x86_l_3eeb);
x86_l_36b6:
	/* 0x36b6: xor    r15d,r15d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_36b9:
	/* 0x36b9: movabs r12,0x1008180000000001 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, 0, 1155199692699598849ULL);
x86_l_36c3:
	/* 0x36c3: jmp    36c8 <generic_retkprobe_event+0x36c8> */
	X86_SIM_X86_JMP(0x36c3, 0x36c8, x86_l_36c8);
x86_l_36c5:
	/* 0x36c5: inc    r15b */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_ALU_INC, 1);
x86_l_36c8:
	/* 0x36c8: movzx  eax,BYTE PTR [r13+0x5] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_36cd:
	/* 0x36cd: lea    ecx,[rax-0x2b] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551573ULL);
x86_l_36d0:
	/* 0x36d0: cmp    ecx,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_36d3:
	/* 0x36d3: ja     36f2 <generic_retkprobe_event+0x36f2> */
	X86_SIM_X86_JCC(X86_CC_A, 0x36d3, 0x36f2, x86_l_36f2);
x86_l_36d5:
	/* Capture image-bound code identity before scheduled instructions. */
	switch (X86_SIM_L_READ_REG(X86_RCX) << 2) {
	case 0ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x370aULL); break;
	case 4ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x36e5ULL); break;
	case 8ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x3718ULL); break;
	case 12ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x3718ULL); break;
	case 16ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x3718ULL); break;
	case 20ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x3718ULL); break;
	case 24ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x3718ULL); break;
	case 28ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x3718ULL); break;
	case 32ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x371fULL); break;
	case 36ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x3718ULL); break;
	case 40ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x3718ULL); break;
	case 44ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x3718ULL); break;
	case 48ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x3718ULL); break;
	case 52ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x3718ULL); break;
	case 56ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x3718ULL); break;
	case 60ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x3718ULL); break;
	case 64ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x3718ULL); break;
	case 68ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x370aULL); break;
	default: __x86_sim_unresolved_indirect_target();
	}
x86_l_36e3:
	/* 0x36e3: jmp    rax */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RAX);
		switch (X86_SIM_L_REG_TAG(X86_RAX)) {
		case X86_SIM_TAG_CODE:
			switch (__x86_target) {
			case 0x36e5ULL: goto x86_l_36e5;
			case 0x370aULL: goto x86_l_370a;
			case 0x3718ULL: goto x86_l_3718;
			case 0x371fULL: goto x86_l_371f;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_36e5:
	/* 0x36e5: mov    WORD PTR [r13+0x2],0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_36ec:
	/* 0x36ec: mov    ax,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, 0, 8ULL);
x86_l_36f0:
	/* 0x36f0: jmp    3730 <generic_retkprobe_event+0x3730> */
	X86_SIM_X86_JMP(0x36f0, 0x3730, x86_l_3730);
x86_l_36f2:
	/* 0x36f2: test   eax,eax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_36f4:
	/* 0x36f4: je     370a <generic_retkprobe_event+0x370a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x36f4, 0x370a, x86_l_370a);
x86_l_36f6:
	/* 0x36f6: cmp    eax,0xff */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 255ULL);
x86_l_36fb:
	/* 0x36fb: jne    3718 <generic_retkprobe_event+0x3718> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x36fb, 0x3718, x86_l_3718);
x86_l_36fd:
	/* 0x36fd: mov    WORD PTR [r13+0x2],0x28 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_3704:
	/* 0x3704: mov    ax,0x28 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, 0, 40ULL);
x86_l_3708:
	/* 0x3708: jmp    3730 <generic_retkprobe_event+0x3730> */
	X86_SIM_X86_JMP(0x3708, 0x3730, x86_l_3730);
x86_l_370a:
	/* 0x370a: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_370f:
	/* 0x370f: lea    eax,[rax*8+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_3716:
	/* 0x3716: jmp    372b <generic_retkprobe_event+0x372b> */
	X86_SIM_X86_JMP(0x3716, 0x372b, x86_l_372b);
x86_l_3718:
	/* 0x3718: movzx  eax,WORD PTR [r13+0x2] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_371d:
	/* 0x371d: jmp    3730 <generic_retkprobe_event+0x3730> */
	X86_SIM_X86_JMP(0x371d, 0x3730, x86_l_3730);
x86_l_371f:
	/* 0x371f: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_3724:
	/* 0x3724: lea    eax,[rax*4+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_372b:
	/* 0x372b: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_3730:
	/* 0x3730: add    ax,WORD PTR [r13+0x0] */
	X86_SIM_RUN_OP(X86_OP_ALU_MEM, X86_RAX, X86_R13, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3735:
	/* 0x3735: mov    WORD PTR [r13+0x0],ax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_373a:
	/* 0x373a: movzx  ecx,BYTE PTR [r13+0x6] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_373f:
	/* 0x373f: cmp    rcx,0x3c */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, 0, 60ULL);
x86_l_3743:
	/* 0x3743: ja     42d1 <generic_retkprobe_event+0x42d1> */
	X86_SIM_X86_JCC(X86_CC_A, 0x3743, 0x42d1, x86_l_42d1);
x86_l_3749:
	/* 0x3749: bt     r12,rcx */
	X86_SIM_RUN_OP(X86_OP_BT, X86_R12, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_374d:
	/* 0x374d: jae    42d1 <generic_retkprobe_event+0x42d1> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x374d, 0x42d1, x86_l_42d1);
x86_l_3753:
	/* 0x3753: mov    BYTE PTR [r13+0x5],cl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_3757:
	/* 0x3757: movzx  edx,ax */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_RDX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_375a:
	/* 0x375a: add    rdx,r14 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_375d:
	/* 0x375d: jns    377e <generic_retkprobe_event+0x377e> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x375d, 0x377e, x86_l_377e);
x86_l_375f:
	/* 0x375f: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_3762:
	/* 0x3762: jns    3ee5 <generic_retkprobe_event+0x3ee5> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x3762, 0x3ee5, x86_l_3ee5);
x86_l_3768:
	/* 0x3768: movzx  eax,WORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_376b:
	/* 0x376b: mov    WORD PTR [rbp+0x0],ax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_376f:
	/* 0x376f: cmp    r15b,0x5 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, 0, 5ULL);
x86_l_3773:
	/* 0x3773: jbe    36c5 <generic_retkprobe_event+0x36c5> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x3773, 0x36c5, x86_l_36c5);
x86_l_3779:
	/* 0x3779: jmp    3eeb <generic_retkprobe_event+0x3eeb> */
	X86_SIM_X86_JMP(0x3779, 0x3eeb, x86_l_3eeb);
x86_l_377e:
	/* 0x377e: mov    rdi,rbp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_3781:
	/* 0x3781: mov    esi,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_3786:
	/* 0x3786: call   378b <generic_retkprobe_event+0x378b> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_378b:
	/* 0x378b: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_378d:
	/* 0x378d: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_3790:
	/* 0x3790: js     3eed <generic_retkprobe_event+0x3eed> */
	X86_SIM_X86_JCC(X86_CC_S, 0x3790, 0x3eed, x86_l_3eed);
x86_l_3796:
	/* 0x3796: cmp    r15b,0x6 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, 0, 6ULL);
x86_l_379a:
	/* 0x379a: jb     36c5 <generic_retkprobe_event+0x36c5> */
	X86_SIM_X86_JCC(X86_CC_B, 0x379a, 0x36c5, x86_l_36c5);
x86_l_37a0:
	/* 0x37a0: jmp    3eed <generic_retkprobe_event+0x3eed> */
	X86_SIM_X86_JMP(0x37a0, 0x3eed, x86_l_3eed);
x86_l_37a5:
	/* 0x37a5: mov    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_37a7:
	/* 0x37a7: mov    edx,DWORD PTR [rbp+rcx*1+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_37ab:
	/* 0x37ab: mov    DWORD PTR [rdi+rcx*1],edx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_37ae:
	/* 0x37ae: or     eax,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_OR, 4ULL);
x86_l_37b1:
	/* 0x37b1: test   r12b,0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, 0, 2ULL);
x86_l_37b5:
	/* 0x37b5: je     2866 <generic_retkprobe_event+0x2866> */
	X86_SIM_X86_JCC(X86_CC_E, 0x37b5, 0x2866, x86_l_2866);
x86_l_37bb:
	/* 0x37bb: mov    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_37bd:
	/* 0x37bd: movzx  edx,WORD PTR [rbp+rcx*1+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_16), 0ULL);
x86_l_37c2:
	/* 0x37c2: mov    WORD PTR [rdi+rcx*1],dx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_37c6:
	/* 0x37c6: add    eax,0x2 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_37c9:
	/* 0x37c9: test   r12b,0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_37cd:
	/* 0x37cd: jne    286c <generic_retkprobe_event+0x286c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x37cd, 0x286c, x86_l_286c);
x86_l_37d3:
	/* 0x37d3: jmp    2876 <generic_retkprobe_event+0x2876> */
	X86_SIM_X86_JMP(0x37d3, 0x2876, x86_l_2876);
x86_l_37d8:
	/* 0x37d8: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_37dd:
	/* 0x37dd: mov    QWORD PTR [rax+0x37],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 236223201280ULL);
x86_l_37e5:
	/* 0x37e5: mov    QWORD PTR [rax+0x30],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_37ed:
	/* 0x37ed: mov    QWORD PTR [rax+0x28],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_37f5:
	/* 0x37f5: mov    QWORD PTR [rax+0x20],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_37fd:
	/* 0x37fd: mov    QWORD PTR [rax+0x18],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_3805:
	/* 0x3805: mov    QWORD PTR [rax+0x10],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_380d:
	/* 0x380d: mov    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_3815:
	/* 0x3815: mov    QWORD PTR [rax],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_381c:
	/* 0x381c: xor    r12d,r12d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_381f:
	/* 0x381f: mov    r14,QWORD PTR [rsp] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3823:
	/* 0x3823: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3828:
	/* 0x3828: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_382d:
	/* 0x382d: mov    r13d,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_3833:
	/* 0x3833: jmp    3d3d <generic_retkprobe_event+0x3d3d> */
	X86_SIM_X86_JMP(0x3833, 0x3d3d, x86_l_3d3d);
x86_l_3838:
	/* 0x3838: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_3841:
	/* 0x3841: xor    edx,edx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_3843:
	/* 0x3843: lea    rdi,[rsp+0x80] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_384b:
	/* 0x384b: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_3850:
	/* 0x3850: call   3855 <generic_retkprobe_event+0x3855> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_3855:
	/* 0x3855: jmp    3a5b <generic_retkprobe_event+0x3a5b> */
	X86_SIM_X86_JMP(0x3855, 0x3a5b, x86_l_3a5b);
x86_l_385a:
	/* 0x385a: mov    DWORD PTR [r13+0x0],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3862:
	/* 0x3862: jmp    35cb <generic_retkprobe_event+0x35cb> */
	X86_SIM_X86_JMP(0x3862, 0x35cb, x86_l_35cb);
x86_l_3867:
	/* 0x3867: mov    BYTE PTR [rsp+0x80],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_386f:
	/* 0x386f: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_3871:
	/* 0x3871: movzx  eax,al */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8, 0);
x86_l_3874:
	/* 0x3874: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3879:
	/* 0x3879: mov    WORD PTR [rcx+0xc0],ax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_3880:
	/* 0x3880: mov    WORD PTR [rcx+0xc2],0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 833223655426ULL);
x86_l_3889:
	/* 0x3889: mov    rdx,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_388c:
	/* 0x388c: add    rdx,0xc */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_3890:
	/* 0x3890: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3895:
	/* 0x3895: mov    QWORD PTR [rax+0x18],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_389d:
	/* 0x389d: mov    QWORD PTR [rax+0x10],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_38a5:
	/* 0x38a5: mov    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_38ad:
	/* 0x38ad: mov    QWORD PTR [rax],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_38b4:
	/* 0x38b4: jns    38c6 <generic_retkprobe_event+0x38c6> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x38b4, 0x38c6, x86_l_38c6);
x86_l_38b6:
	/* 0x38b6: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_38b9:
	/* 0x38b9: jns    38d7 <generic_retkprobe_event+0x38d7> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x38b9, 0x38d7, x86_l_38d7);
x86_l_38bb:
	/* 0x38bb: mov    eax,DWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_38bd:
	/* 0x38bd: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_38c2:
	/* 0x38c2: mov    DWORD PTR [rcx],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_38c4:
	/* 0x38c4: jmp    38e2 <generic_retkprobe_event+0x38e2> */
	X86_SIM_X86_JMP(0x38c4, 0x38e2, x86_l_38e2);
x86_l_38c6:
	/* 0x38c6: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_38cb:
	/* 0x38cb: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_38d0:
	/* 0x38d0: call   38d5 <generic_retkprobe_event+0x38d5> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_38d5:
	/* 0x38d5: jmp    38e2 <generic_retkprobe_event+0x38e2> */
	X86_SIM_X86_JMP(0x38d5, 0x38e2, x86_l_38e2);
x86_l_38d7:
	/* 0x38d7: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_38dc:
	/* 0x38dc: mov    DWORD PTR [rax],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_38e2:
	/* 0x38e2: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_38e7:
	/* 0x38e7: lea    rdi,[rax+0xac] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_38ee:
	/* 0x38ee: add    r12,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_38f2:
	/* 0x38f2: jns    3901 <generic_retkprobe_event+0x3901> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x38f2, 0x3901, x86_l_3901);
x86_l_38f4:
	/* 0x38f4: test   r12,r12 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_38f7:
	/* 0x38f7: jns    3910 <generic_retkprobe_event+0x3910> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x38f7, 0x3910, x86_l_3910);
x86_l_38f9:
	/* 0x38f9: mov    eax,DWORD PTR [r12] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_38fd:
	/* 0x38fd: mov    DWORD PTR [rdi],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_38ff:
	/* 0x38ff: jmp    3916 <generic_retkprobe_event+0x3916> */
	X86_SIM_X86_JMP(0x38ff, 0x3916, x86_l_3916);
x86_l_3901:
	/* 0x3901: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_3906:
	/* 0x3906: mov    rdx,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_3909:
	/* 0x3909: call   390e <generic_retkprobe_event+0x390e> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_390e:
	/* 0x390e: jmp    3916 <generic_retkprobe_event+0x3916> */
	X86_SIM_X86_JMP(0x390e, 0x3916, x86_l_3916);
x86_l_3910:
	/* 0x3910: mov    DWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3916:
	/* 0x3916: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_391b:
	/* 0x391b: add    rdx,0xb6 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 182ULL);
x86_l_3922:
	/* 0x3922: jns    3947 <generic_retkprobe_event+0x3947> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x3922, 0x3947, x86_l_3947);
x86_l_3924:
	/* 0x3924: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_3927:
	/* 0x3927: jns    3959 <generic_retkprobe_event+0x3959> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x3927, 0x3959, x86_l_3959);
x86_l_3929:
	/* 0x3929: movzx  eax,WORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_392c:
	/* 0x392c: mov    WORD PTR [rsp+0x90],ax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_3934:
	/* 0x3934: movzx  eax,BYTE PTR [rsp+0x80] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 128ULL);
x86_l_393c:
	/* 0x393c: cmp    eax,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_393f:
	/* 0x393f: jne    3fdd <generic_retkprobe_event+0x3fdd> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x393f, 0x3fdd, x86_l_3fdd);
x86_l_3945:
	/* 0x3945: jmp    3974 <generic_retkprobe_event+0x3974> */
	X86_SIM_X86_JMP(0x3945, 0x3974, x86_l_3974);
x86_l_3947:
	/* 0x3947: lea    rdi,[rsp+0x90] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_394f:
	/* 0x394f: mov    esi,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_3954:
	/* 0x3954: jmp    3fc7 <generic_retkprobe_event+0x3fc7> */
	X86_SIM_X86_JMP(0x3954, 0x3fc7, x86_l_3fc7);
x86_l_3959:
	/* 0x3959: mov    WORD PTR [rsp+0x90],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_3963:
	/* 0x3963: movzx  eax,BYTE PTR [rsp+0x80] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 128ULL);
x86_l_396b:
	/* 0x396b: cmp    eax,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_396e:
	/* 0x396e: jne    3fdd <generic_retkprobe_event+0x3fdd> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x396e, 0x3fdd, x86_l_3fdd);
x86_l_3974:
	/* 0x3974: movzx  r12d,WORD PTR [rsp+0x90] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 144ULL);
x86_l_397d:
	/* 0x397d: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3982:
	/* 0x3982: lea    rdi,[rax+0xbc] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_3989:
	/* 0x3989: add    r12,QWORD PTR [rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_ALU_MEM, X86_R12, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 64ULL);
x86_l_398e:
	/* 0x398e: jns    39a7 <generic_retkprobe_event+0x39a7> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x398e, 0x39a7, x86_l_39a7);
x86_l_3990:
	/* 0x3990: mov    rax,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_3993:
	/* 0x3993: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_3996:
	/* 0x3996: jns    3c90 <generic_retkprobe_event+0x3c90> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x3996, 0x3c90, x86_l_3c90);
x86_l_399c:
	/* 0x399c: movzx  eax,WORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_399f:
	/* 0x399f: mov    WORD PTR [rdi],ax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_39a2:
	/* 0x39a2: jmp    3c95 <generic_retkprobe_event+0x3c95> */
	X86_SIM_X86_JMP(0x39a2, 0x3c95, x86_l_3c95);
x86_l_39a7:
	/* 0x39a7: mov    esi,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_39ac:
	/* 0x39ac: mov    rdx,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_39af:
	/* 0x39af: call   39b4 <generic_retkprobe_event+0x39b4> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_39b4:
	/* 0x39b4: jmp    3c95 <generic_retkprobe_event+0x3c95> */
	X86_SIM_X86_JMP(0x39b4, 0x3c95, x86_l_3c95);
x86_l_39b9:
	/* 0x39b9: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_39be:
	/* 0x39be: add    rax,0xa0 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 160ULL);
x86_l_39c4:
	/* 0x39c4: mov    DWORD PTR [rax+0x67],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 442381631488ULL);
x86_l_39cb:
	/* 0x39cb: jmp    3bff <generic_retkprobe_event+0x3bff> */
	X86_SIM_X86_JMP(0x39cb, 0x3bff, x86_l_3bff);
x86_l_39d0:
	/* 0x39d0: mov    r12d,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_39d6:
	/* 0x39d6: mov    r14,QWORD PTR [rsp] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_39da:
	/* 0x39da: jmp    260c <generic_retkprobe_event+0x260c> */
	X86_SIM_X86_JMP(0x39da, 0x260c, x86_l_260c);
x86_l_39df:
	/* 0x39df: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_39e4:
	/* 0x39e4: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_39e9:
	/* 0x39e9: call   39ee <generic_retkprobe_event+0x39ee> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_39ee:
	/* 0x39ee: jmp    3d90 <generic_retkprobe_event+0x3d90> */
	X86_SIM_X86_JMP(0x39ee, 0x3d90, x86_l_3d90);
x86_l_39f3:
	/* 0x39f3: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_39f8:
	/* 0x39f8: mov    esi,0x10 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 16ULL);
x86_l_39fd:
	/* 0x39fd: call   3a02 <generic_retkprobe_event+0x3a02> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_3a02:
	/* 0x3a02: jmp    3dd0 <generic_retkprobe_event+0x3dd0> */
	X86_SIM_X86_JMP(0x3a02, 0x3dd0, x86_l_3dd0);
x86_l_3a07:
	/* 0x3a07: mov    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_3a09:
	/* 0x3a09: mov    esi,DWORD PTR [rdx+rcx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3a0c:
	/* 0x3a0c: mov    DWORD PTR [rdi+rcx*1],esi */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3a0f:
	/* 0x3a0f: or     eax,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_OR, 4ULL);
x86_l_3a12:
	/* 0x3a12: test   r12b,0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, 0, 2ULL);
x86_l_3a16:
	/* 0x3a16: je     3224 <generic_retkprobe_event+0x3224> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3a16, 0x3224, x86_l_3224);
x86_l_3a1c:
	/* 0x3a1c: mov    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_3a1e:
	/* 0x3a1e: movzx  esi,WORD PTR [rdx+rcx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_16), 0ULL);
x86_l_3a22:
	/* 0x3a22: mov    WORD PTR [rdi+rcx*1],si */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RSI, X86_WIDTH_16, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3a26:
	/* 0x3a26: add    eax,0x2 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_3a29:
	/* 0x3a29: test   r12b,0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_3a2d:
	/* 0x3a2d: je     3d17 <generic_retkprobe_event+0x3d17> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3a2d, 0x3d17, x86_l_3d17);
x86_l_3a33:
	/* 0x3a33: mov    eax,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_3a35:
	/* 0x3a35: movzx  ecx,BYTE PTR [rdx+rax*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_3a39:
	/* 0x3a39: jmp    3d14 <generic_retkprobe_event+0x3d14> */
	X86_SIM_X86_JMP(0x3a39, 0x3d14, x86_l_3d14);
x86_l_3a3e:
	/* 0x3a3e: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3a43:
	/* 0x3a43: mov    BYTE PTR [rax+0x11b],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 1215475744768ULL);
x86_l_3a4a:
	/* 0x3a4a: jmp    2722 <generic_retkprobe_event+0x2722> */
	X86_SIM_X86_JMP(0x3a4a, 0x2722, x86_l_2722);
x86_l_3a4f:
	/* 0x3a4f: mov    QWORD PTR [rsp+0x80],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_3a5b:
	/* 0x3a5b: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3a60:
	/* 0x3a60: add    rdx,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3a64:
	/* 0x3a64: jns    3a78 <generic_retkprobe_event+0x3a78> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x3a64, 0x3a78, x86_l_3a78);
x86_l_3a66:
	/* 0x3a66: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_3a69:
	/* 0x3a69: jns    3a94 <generic_retkprobe_event+0x3a94> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x3a69, 0x3a94, x86_l_3a94);
x86_l_3a6b:
	/* 0x3a6b: mov    r14,QWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3a6e:
	/* 0x3a6e: mov    QWORD PTR [rsp+0xa0],r14 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_3a76:
	/* 0x3a76: jmp    3aa3 <generic_retkprobe_event+0x3aa3> */
	X86_SIM_X86_JMP(0x3a76, 0x3aa3, x86_l_3aa3);
x86_l_3a78:
	/* 0x3a78: lea    rdi,[rsp+0xa0] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_3a80:
	/* 0x3a80: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_3a85:
	/* 0x3a85: call   3a8a <generic_retkprobe_event+0x3a8a> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_3a8a:
	/* 0x3a8a: mov    r14,QWORD PTR [rsp+0xa0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_3a92:
	/* 0x3a92: jmp    3aa3 <generic_retkprobe_event+0x3aa3> */
	X86_SIM_X86_JMP(0x3a92, 0x3aa3, x86_l_3aa3);
x86_l_3a94:
	/* 0x3a94: mov    QWORD PTR [rsp+0xa0],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_3aa0:
	/* 0x3aa0: xor    r14d,r14d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_3aa3:
	/* 0x3aa3: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3aab:
	/* 0x3aab: cmp    r14,0xfff */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, 0, 4095ULL);
x86_l_3ab2:
	/* 0x3ab2: mov    r12d,0xfff */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 4095ULL);
x86_l_3ab8:
	/* 0x3ab8: cmovb  r12,r14 */
	X86_SIM_RUN_OP(X86_OP_CMOV, X86_R12, X86_R14, X86_WIDTH_64, X86_CC_B, 0);
x86_l_3abc:
	/* 0x3abc: mov    rdi,r13 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_3abf:
	/* 0x3abf: add    rdi,0xa4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 164ULL);
x86_l_3ac6:
	/* 0x3ac6: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_3ac9:
	/* 0x3ac9: jns    3b15 <generic_retkprobe_event+0x3b15> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x3ac9, 0x3b15, x86_l_3b15);
x86_l_3acb:
	/* 0x3acb: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_3ace:
	/* 0x3ace: jns    3b26 <generic_retkprobe_event+0x3b26> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x3ace, 0x3b26, x86_l_3b26);
x86_l_3ad0:
	/* 0x3ad0: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_3ad2:
	/* 0x3ad2: cmp    r12d,0x8 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_3ad6:
	/* 0x3ad6: jb     3af2 <generic_retkprobe_event+0x3af2> */
	X86_SIM_X86_JCC(X86_CC_B, 0x3ad6, 0x3af2, x86_l_3af2);
x86_l_3ad8:
	/* 0x3ad8: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_3ada:
	/* 0x3ada: mov    rcx,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_3add:
	/* 0x3add: mov    rax,QWORD PTR [rdx+rax*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3ae1:
	/* 0x3ae1: mov    QWORD PTR [rdi+rcx*1],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3ae5:
	/* 0x3ae5: lea    rax,[rcx+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3ae9:
	/* 0x3ae9: add    rcx,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3aed:
	/* 0x3aed: cmp    rcx,r12 */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RCX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_3af0:
	/* 0x3af0: jbe    3ada <generic_retkprobe_event+0x3ada> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x3af0, 0x3ada, x86_l_3ada);
x86_l_3af2:
	/* 0x3af2: test   r12b,0x4 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, 0, 4ULL);
x86_l_3af6:
	/* 0x3af6: jne    3ce6 <generic_retkprobe_event+0x3ce6> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x3af6, 0x3ce6, x86_l_3ce6);
x86_l_3afc:
	/* 0x3afc: test   r12b,0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, 0, 2ULL);
x86_l_3b00:
	/* 0x3b00: jne    3cfb <generic_retkprobe_event+0x3cfb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x3b00, 0x3cfb, x86_l_3cfb);
x86_l_3b06:
	/* 0x3b06: test   r12b,0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_3b0a:
	/* 0x3b0a: jne    3d0e <generic_retkprobe_event+0x3d0e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x3b0a, 0x3d0e, x86_l_3d0e);
x86_l_3b10:
	/* 0x3b10: jmp    3d17 <generic_retkprobe_event+0x3d17> */
	X86_SIM_X86_JMP(0x3b10, 0x3d17, x86_l_3d17);
x86_l_3b15:
	/* 0x3b15: mov    esi,r12d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_R12, X86_WIDTH_32, 0, 0);
x86_l_3b18:
	/* 0x3b18: call   3b1d <generic_retkprobe_event+0x3b1d> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_3b1d:
	/* 0x3b1d: test   eax,eax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_3b1f:
	/* 0x3b1f: js     3b30 <generic_retkprobe_event+0x3b30> */
	X86_SIM_X86_JCC(X86_CC_S, 0x3b1f, 0x3b30, x86_l_3b30);
x86_l_3b21:
	/* 0x3b21: jmp    3d17 <generic_retkprobe_event+0x3d17> */
	X86_SIM_X86_JMP(0x3b21, 0x3d17, x86_l_3d17);
x86_l_3b26:
	/* 0x3b26: xor    esi,esi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_3b28:
	/* 0x3b28: mov    rdx,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_3b2b:
	/* 0x3b2b: call   47c5 <__native_link_local_memset_zero_dynamic> */
	X86_SIM_X86_CALL(x86_l_47c5, 0x3b30ULL);
x86_l_3b30:
	/* 0x3b30: mov    DWORD PTR [r13+0x9c],0xfffffffe */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 674309865470ULL);
x86_l_3b3b:
	/* 0x3b3b: mov    r12d,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_3b41:
	/* 0x3b41: jmp    3d29 <generic_retkprobe_event+0x3d29> */
	X86_SIM_X86_JMP(0x3b41, 0x3d29, x86_l_3d29);
x86_l_3b46:
	/* 0x3b46: mov    DWORD PTR [rsp+0x40],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_3b4e:
	/* 0x3b4e: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_3b50:
	/* 0x3b50: mov    eax,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_3b52:
	/* 0x3b52: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3b57:
	/* 0x3b57: mov    QWORD PTR [rcx+0xa4],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_3b5e:
	/* 0x3b5e: add    QWORD PTR [rsp+0x10],0x9e */
	X86_SIM_RUN_OP(X86_OP_ALU_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 68719476894ULL);
x86_l_3b67:
	/* 0x3b67: add    r12,0x2 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_3b6b:
	/* 0x3b6b: jns    3bab <generic_retkprobe_event+0x3bab> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x3b6b, 0x3bab, x86_l_3bab);
x86_l_3b6d:
	/* 0x3b6d: test   r12,r12 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_3b70:
	/* 0x3b70: jns    3bbf <generic_retkprobe_event+0x3bbf> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x3b70, 0x3bbf, x86_l_3bbf);
x86_l_3b72:
	/* 0x3b72: movzx  eax,WORD PTR [r12] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3b77:
	/* 0x3b77: jmp    3ba1 <generic_retkprobe_event+0x3ba1> */
	X86_SIM_X86_JMP(0x3b77, 0x3ba1, x86_l_3ba1);
x86_l_3b79:
	/* 0x3b79: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_3b81:
	/* 0x3b81: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3b88:
	/* 0x3b88: add    QWORD PTR [rsp+0x10],0x9e */
	X86_SIM_RUN_OP(X86_OP_ALU_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 68719476894ULL);
x86_l_3b91:
	/* 0x3b91: add    r12,0x2 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_3b95:
	/* 0x3b95: jns    3bab <generic_retkprobe_event+0x3bab> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x3b95, 0x3bab, x86_l_3bab);
x86_l_3b97:
	/* 0x3b97: test   r12,r12 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_3b9a:
	/* 0x3b9a: jns    3bbf <generic_retkprobe_event+0x3bbf> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x3b9a, 0x3bbf, x86_l_3bbf);
x86_l_3b9c:
	/* 0x3b9c: movzx  eax,WORD PTR [r12] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3ba1:
	/* 0x3ba1: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3ba6:
	/* 0x3ba6: mov    WORD PTR [rcx],ax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3ba9:
	/* 0x3ba9: jmp    3bc9 <generic_retkprobe_event+0x3bc9> */
	X86_SIM_X86_JMP(0x3ba9, 0x3bc9, x86_l_3bc9);
x86_l_3bab:
	/* 0x3bab: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3bb0:
	/* 0x3bb0: mov    esi,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_3bb5:
	/* 0x3bb5: mov    rdx,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_3bb8:
	/* 0x3bb8: call   3bbd <generic_retkprobe_event+0x3bbd> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_3bbd:
	/* 0x3bbd: jmp    3bc9 <generic_retkprobe_event+0x3bc9> */
	X86_SIM_X86_JMP(0x3bbd, 0x3bc9, x86_l_3bc9);
x86_l_3bbf:
	/* 0x3bbf: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3bc4:
	/* 0x3bc4: mov    WORD PTR [rax],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3bc9:
	/* 0x3bc9: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3bce:
	/* 0x3bce: movzx  eax,WORD PTR [rcx+0x9e] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 158ULL);
x86_l_3bd5:
	/* 0x3bd5: movbe  WORD PTR [rcx+0x9e],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 158ULL);
x86_l_3bde:
	/* 0x3bde: mov    r14,QWORD PTR [rsp] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3be2:
	/* 0x3be2: mov    r13d,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_3be8:
	/* 0x3be8: mov    r12d,0x18 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 24ULL);
x86_l_3bee:
	/* 0x3bee: jmp    3d33 <generic_retkprobe_event+0x3d33> */
	X86_SIM_X86_JMP(0x3bee, 0x3d33, x86_l_3d33);
x86_l_3bf3:
	/* 0x3bf3: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3bf8:
	/* 0x3bf8: mov    DWORD PTR [rax+0x68],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_3bff:
	/* 0x3bff: mov    QWORD PTR [rax+0x60],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_3c07:
	/* 0x3c07: mov    QWORD PTR [rax+0x58],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_3c0f:
	/* 0x3c0f: mov    QWORD PTR [rax+0x50],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_3c17:
	/* 0x3c17: mov    QWORD PTR [rax+0x48],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_3c1f:
	/* 0x3c1f: mov    QWORD PTR [rax+0x40],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_3c27:
	/* 0x3c27: mov    QWORD PTR [rax+0x38],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_3c2f:
	/* 0x3c2f: mov    QWORD PTR [rax+0x30],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_3c37:
	/* 0x3c37: mov    QWORD PTR [rax+0x28],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_3c3f:
	/* 0x3c3f: mov    QWORD PTR [rax+0x20],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_3c47:
	/* 0x3c47: mov    QWORD PTR [rax+0x18],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_3c4f:
	/* 0x3c4f: mov    QWORD PTR [rax+0x10],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3c57:
	/* 0x3c57: mov    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_3c5f:
	/* 0x3c5f: mov    QWORD PTR [rax],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3c66:
	/* 0x3c66: mov    r14,QWORD PTR [rsp] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3c6a:
	/* 0x3c6a: jmp    4159 <generic_retkprobe_event+0x4159> */
	X86_SIM_X86_JMP(0x3c6a, 0x4159, x86_l_4159);
x86_l_3c6f:
	/* 0x3c6f: xor    esi,esi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_3c71:
	/* 0x3c71: mov    rdx,rbp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_3c74:
	/* 0x3c74: call   47c5 <__native_link_local_memset_zero_dynamic> */
	X86_SIM_X86_CALL(x86_l_47c5, 0x3c79ULL);
x86_l_3c79:
	/* 0x3c79: mov    ecx,0xfffffffe */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 4294967294ULL);
x86_l_3c7e:
	/* 0x3c7e: mov    rax,QWORD PTR [rsp] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3c82:
	/* 0x3c82: mov    r8,QWORD PTR [rsp+0x30] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3c87:
	/* 0x3c87: mov    DWORD PTR [rax+r8*1],ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R8, 0), 0ULL);
x86_l_3c8b:
	/* 0x3c8b: jmp    405 <generic_retkprobe_event+0x405> */
	X86_SIM_X86_JMP(0x3c8b, 0x405, x86_l_405);
x86_l_3c90:
	/* 0x3c90: mov    WORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3c95:
	/* 0x3c95: add    QWORD PTR [rsp+0x10],0xbe */
	X86_SIM_RUN_OP(X86_OP_ALU_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 68719476926ULL);
x86_l_3c9e:
	/* 0x3c9e: add    r12,0x2 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_3ca2:
	/* 0x3ca2: jns    4077 <generic_retkprobe_event+0x4077> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x3ca2, 0x4077, x86_l_4077);
x86_l_3ca8:
	/* 0x3ca8: test   r12,r12 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_3cab:
	/* 0x3cab: jns    408b <generic_retkprobe_event+0x408b> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x3cab, 0x408b, x86_l_408b);
x86_l_3cb1:
	/* 0x3cb1: movzx  eax,WORD PTR [r12] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3cb6:
	/* 0x3cb6: jmp    406d <generic_retkprobe_event+0x406d> */
	X86_SIM_X86_JMP(0x3cb6, 0x406d, x86_l_406d);
x86_l_3cbb:
	/* 0x3cbb: mov    BYTE PTR [rbp+0x0],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3cbf:
	/* 0x3cbf: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_3cc1:
	/* 0x3cc1: jmp    3eed <generic_retkprobe_event+0x3eed> */
	X86_SIM_X86_JMP(0x3cc1, 0x3eed, x86_l_3eed);
x86_l_3cc6:
	/* 0x3cc6: mov    r12d,0x3 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 3ULL);
x86_l_3ccc:
	/* 0x3ccc: mov    r14,QWORD PTR [rsp] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3cd0:
	/* 0x3cd0: jmp    260c <generic_retkprobe_event+0x260c> */
	X86_SIM_X86_JMP(0x3cd0, 0x260c, x86_l_260c);
x86_l_3cd5:
	/* 0x3cd5: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3cda:
	/* 0x3cda: mov    BYTE PTR [rax+0xea],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 1005022347264ULL);
x86_l_3ce1:
	/* 0x3ce1: jmp    1a39 <generic_retkprobe_event+0x1a39> */
	X86_SIM_X86_JMP(0x3ce1, 0x1a39, x86_l_1a39);
x86_l_3ce6:
	/* 0x3ce6: mov    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_3ce8:
	/* 0x3ce8: mov    esi,DWORD PTR [rdx+rcx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3ceb:
	/* 0x3ceb: mov    DWORD PTR [rdi+rcx*1],esi */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3cee:
	/* 0x3cee: or     eax,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_OR, 4ULL);
x86_l_3cf1:
	/* 0x3cf1: test   r12b,0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, 0, 2ULL);
x86_l_3cf5:
	/* 0x3cf5: je     3b06 <generic_retkprobe_event+0x3b06> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3cf5, 0x3b06, x86_l_3b06);
x86_l_3cfb:
	/* 0x3cfb: mov    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_3cfd:
	/* 0x3cfd: movzx  esi,WORD PTR [rdx+rcx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_16), 0ULL);
x86_l_3d01:
	/* 0x3d01: mov    WORD PTR [rdi+rcx*1],si */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RSI, X86_WIDTH_16, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3d05:
	/* 0x3d05: add    eax,0x2 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_3d08:
	/* 0x3d08: test   r12b,0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_3d0c:
	/* 0x3d0c: je     3d17 <generic_retkprobe_event+0x3d17> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3d0c, 0x3d17, x86_l_3d17);
x86_l_3d0e:
	/* 0x3d0e: mov    eax,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_3d10:
	/* 0x3d10: movzx  ecx,BYTE PTR [rdx+rax*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_3d14:
	/* 0x3d14: mov    BYTE PTR [rdi+rax*1],cl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3d17:
	/* 0x3d17: mov    DWORD PTR [r13+0x9c],r14d */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_R13, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_3d1e:
	/* 0x3d1e: mov    DWORD PTR [r13+0xa0],r12d */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_R13, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_3d25:
	/* 0x3d25: add    r12,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3d29:
	/* 0x3d29: mov    r14,QWORD PTR [rsp] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3d2d:
	/* 0x3d2d: mov    r13d,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_3d33:
	/* 0x3d33: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3d38:
	/* 0x3d38: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3d3d:
	/* 0x3d3d: test   r12d,r12d */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32, 0, 0);
x86_l_3d40:
	/* 0x3d40: js     3d52 <generic_retkprobe_event+0x3d52> */
	X86_SIM_X86_JCC(X86_CC_S, 0x3d40, 0x3d52, x86_l_3d52);
x86_l_3d42:
	/* 0x3d42: and    r12d,0x7fffffff */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_3d49:
	/* 0x3d49: add    r12,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_3d4d:
	/* 0x3d4d: mov    r13,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R13, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_3d50:
	/* 0x3d50: jmp    3d66 <generic_retkprobe_event+0x3d66> */
	X86_SIM_X86_JMP(0x3d50, 0x3d66, x86_l_3d66);
x86_l_3d52:
	/* 0x3d52: mov    DWORD PTR [rcx+0x5ea0],0xffffffff */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104045582745599ULL);
x86_l_3d5c:
	/* 0x3d5c: mov    DWORD PTR [rcx+0x98],0xffffffff */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 657129996287ULL);
x86_l_3d66:
	/* 0x3d66: mov    r12,QWORD PTR [rsp+0xd0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_3d6e:
	/* 0x3d6e: add    r13,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3d72:
	/* 0x3d72: mov    eax,DWORD PTR [r12+0x60] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_3d77:
	/* 0x3d77: cmp    eax,0xb */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 11ULL);
x86_l_3d7a:
	/* 0x3d7a: jne    19f <generic_retkprobe_event+0x19f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x3d7a, 0x19f, x86_l_19f);
x86_l_3d80:
	/* 0x3d80: jmp    27d <generic_retkprobe_event+0x27d> */
	X86_SIM_X86_JMP(0x3d80, 0x27d, x86_l_27d);
x86_l_3d85:
	/* 0x3d85: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3d8a:
	/* 0x3d8a: mov    DWORD PTR [rax],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3d90:
	/* 0x3d90: test   r12,r12 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_3d93:
	/* 0x3d93: jns    3da5 <generic_retkprobe_event+0x3da5> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x3d93, 0x3da5, x86_l_3da5);
x86_l_3d95:
	/* 0x3d95: mov    rax,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_3d98:
	/* 0x3d98: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_3d9b:
	/* 0x3d9b: jns    3db2 <generic_retkprobe_event+0x3db2> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x3d9b, 0x3db2, x86_l_3db2);
x86_l_3d9d:
	/* 0x3d9d: mov    eax,DWORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3d9f:
	/* 0x3d9f: mov    DWORD PTR [r13+0x0],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3da3:
	/* 0x3da3: jmp    3e0b <generic_retkprobe_event+0x3e0b> */
	X86_SIM_X86_JMP(0x3da3, 0x3e0b, x86_l_3e0b);
x86_l_3da5:
	/* 0x3da5: mov    rdi,r13 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_3da8:
	/* 0x3da8: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_3dad:
	/* 0x3dad: mov    rdx,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_3db0:
	/* 0x3db0: jmp    3e06 <generic_retkprobe_event+0x3e06> */
	X86_SIM_X86_JMP(0x3db0, 0x3e06, x86_l_3e06);
x86_l_3db2:
	/* 0x3db2: mov    DWORD PTR [r13+0x0],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3dba:
	/* 0x3dba: jmp    3e0b <generic_retkprobe_event+0x3e0b> */
	X86_SIM_X86_JMP(0x3dba, 0x3e0b, x86_l_3e0b);
x86_l_3dbc:
	/* 0x3dbc: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3dc1:
	/* 0x3dc1: mov    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_3dc9:
	/* 0x3dc9: mov    QWORD PTR [rax],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3dd0:
	/* 0x3dd0: mov    rdx,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_3dd3:
	/* 0x3dd3: add    rdx,0x38 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 56ULL);
x86_l_3dd7:
	/* 0x3dd7: jns    3dfe <generic_retkprobe_event+0x3dfe> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x3dd7, 0x3dfe, x86_l_3dfe);
x86_l_3dd9:
	/* 0x3dd9: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_3ddc:
	/* 0x3ddc: jns    3ed0 <generic_retkprobe_event+0x3ed0> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x3ddc, 0x3ed0, x86_l_3ed0);
x86_l_3de2:
	/* 0x3de2: mov    rax,QWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3de5:
	/* 0x3de5: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3dea:
	/* 0x3dea: mov    QWORD PTR [rcx+0xac],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_3df1:
	/* 0x3df1: mov    rax,QWORD PTR [rdx+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3df5:
	/* 0x3df5: mov    QWORD PTR [rcx+0xb4],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 180ULL);
x86_l_3dfc:
	/* 0x3dfc: jmp    3e0b <generic_retkprobe_event+0x3e0b> */
	X86_SIM_X86_JMP(0x3dfc, 0x3e0b, x86_l_3e0b);
x86_l_3dfe:
	/* 0x3dfe: mov    rdi,r13 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_3e01:
	/* 0x3e01: mov    esi,0x10 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 16ULL);
x86_l_3e06:
	/* 0x3e06: call   3e0b <generic_retkprobe_event+0x3e0b> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_3e0b:
	/* 0x3e0b: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3e10:
	/* 0x3e10: lea    rdi,[rax+0xbc] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_3e17:
	/* 0x3e17: lea    r13,[r12+0xc] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3e1c:
	/* 0x3e1c: add    r12,0xe */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 14ULL);
x86_l_3e20:
	/* 0x3e20: jns    3e31 <generic_retkprobe_event+0x3e31> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x3e20, 0x3e31, x86_l_3e31);
x86_l_3e22:
	/* 0x3e22: test   r12,r12 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_3e25:
	/* 0x3e25: jns    3e40 <generic_retkprobe_event+0x3e40> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x3e25, 0x3e40, x86_l_3e40);
x86_l_3e27:
	/* 0x3e27: movzx  eax,WORD PTR [r12] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3e2c:
	/* 0x3e2c: mov    WORD PTR [rdi],ax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3e2f:
	/* 0x3e2f: jmp    3e45 <generic_retkprobe_event+0x3e45> */
	X86_SIM_X86_JMP(0x3e2f, 0x3e45, x86_l_3e45);
x86_l_3e31:
	/* 0x3e31: mov    esi,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_3e36:
	/* 0x3e36: mov    rdx,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_3e39:
	/* 0x3e39: call   3e3e <generic_retkprobe_event+0x3e3e> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_3e3e:
	/* 0x3e3e: jmp    3e45 <generic_retkprobe_event+0x3e45> */
	X86_SIM_X86_JMP(0x3e3e, 0x3e45, x86_l_3e45);
x86_l_3e40:
	/* 0x3e40: mov    WORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3e45:
	/* 0x3e45: add    QWORD PTR [rsp+0x10],0xbe */
	X86_SIM_RUN_OP(X86_OP_ALU_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 68719476926ULL);
x86_l_3e4e:
	/* 0x3e4e: test   r13,r13 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_3e51:
	/* 0x3e51: jns    3e5f <generic_retkprobe_event+0x3e5f> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x3e51, 0x3e5f, x86_l_3e5f);
x86_l_3e53:
	/* 0x3e53: test   r13,r13 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_3e56:
	/* 0x3e56: jns    3e7a <generic_retkprobe_event+0x3e7a> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x3e56, 0x3e7a, x86_l_3e7a);
x86_l_3e58:
	/* 0x3e58: movzx  eax,WORD PTR [r13+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3e5d:
	/* 0x3e5d: jmp    3e7c <generic_retkprobe_event+0x3e7c> */
	X86_SIM_X86_JMP(0x3e5d, 0x3e7c, x86_l_3e7c);
x86_l_3e5f:
	/* 0x3e5f: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3e64:
	/* 0x3e64: mov    rdi,r14 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_3e67:
	/* 0x3e67: mov    esi,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_3e6c:
	/* 0x3e6c: mov    rdx,r13 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_3e6f:
	/* 0x3e6f: call   3e74 <generic_retkprobe_event+0x3e74> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_3e74:
	/* 0x3e74: movzx  eax,WORD PTR [r14] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3e78:
	/* 0x3e78: jmp    3e7c <generic_retkprobe_event+0x3e7c> */
	X86_SIM_X86_JMP(0x3e78, 0x3e7c, x86_l_3e7c);
x86_l_3e7a:
	/* 0x3e7a: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_3e7c:
	/* 0x3e7c: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3e81:
	/* 0x3e81: movbe  WORD PTR [rcx],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3e86:
	/* 0x3e86: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3e8b:
	/* 0x3e8b: mov    rax,QWORD PTR [rax+0xc4] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_3e92:
	/* 0x3e92: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3e97:
	/* 0x3e97: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)socktrack_map));
x86_l_3e9e:
	/* 0x3e9e: lea    rsi,[rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3ea3:
	/* 0x3ea3: call   3ea8 <generic_retkprobe_event+0x3ea8> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_3ea8:
	/* 0x3ea8: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_3eab:
	/* 0x3eab: je     3ec5 <generic_retkprobe_event+0x3ec5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3eab, 0x3ec5, x86_l_3ec5);
x86_l_3ead:
	/* 0x3ead: mov    ecx,DWORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3eaf:
	/* 0x3eaf: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3eb4:
	/* 0x3eb4: mov    DWORD PTR [rdx+0x10],ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3eb7:
	/* 0x3eb7: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3ebb:
	/* 0x3ebb: mov    QWORD PTR [rdx+0x18],rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3ebf:
	/* 0x3ebf: mov    eax,DWORD PTR [rax+0x4] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3ec2:
	/* 0x3ec2: mov    DWORD PTR [rdx+0x7c],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_3ec5:
	/* 0x3ec5: mov    r12d,0x40 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 64ULL);
x86_l_3ecb:
	/* 0x3ecb: jmp    381f <generic_retkprobe_event+0x381f> */
	X86_SIM_X86_JMP(0x3ecb, 0x381f, x86_l_381f);
x86_l_3ed0:
	/* 0x3ed0: mov    QWORD PTR [r13+0x8],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_3ed8:
	/* 0x3ed8: mov    QWORD PTR [r13+0x0],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3ee0:
	/* 0x3ee0: jmp    3e0b <generic_retkprobe_event+0x3e0b> */
	X86_SIM_X86_JMP(0x3ee0, 0x3e0b, x86_l_3e0b);
x86_l_3ee5:
	/* 0x3ee5: mov    WORD PTR [rbp+0x0],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3eeb:
	/* 0x3eeb: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_3eed:
	/* 0x3eed: mov    BYTE PTR [rsp+0x80],cl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3ef4:
	/* 0x3ef4: movzx  eax,cl */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8, 0);
x86_l_3ef7:
	/* 0x3ef7: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3efc:
	/* 0x3efc: mov    WORD PTR [rcx+0xc0],ax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_3f03:
	/* 0x3f03: mov    WORD PTR [rcx+0xc2],0xa */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 833223655434ULL);
x86_l_3f0c:
	/* 0x3f0c: mov    rdx,QWORD PTR [rsp+0x98] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_3f14:
	/* 0x3f14: add    rdx,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3f18:
	/* 0x3f18: jns    3f3b <generic_retkprobe_event+0x3f3b> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x3f18, 0x3f3b, x86_l_3f3b);
x86_l_3f1a:
	/* 0x3f1a: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_3f1d:
	/* 0x3f1d: jns    3f4c <generic_retkprobe_event+0x3f4c> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x3f1d, 0x3f4c, x86_l_3f4c);
x86_l_3f1f:
	/* 0x3f1f: mov    rax,QWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3f22:
	/* 0x3f22: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3f27:
	/* 0x3f27: mov    QWORD PTR [rcx+0x9c],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_3f2e:
	/* 0x3f2e: mov    rax,QWORD PTR [rdx+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3f32:
	/* 0x3f32: mov    QWORD PTR [rcx+0xa4],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_3f39:
	/* 0x3f39: jmp    3f60 <generic_retkprobe_event+0x3f60> */
	X86_SIM_X86_JMP(0x3f39, 0x3f60, x86_l_3f60);
x86_l_3f3b:
	/* 0x3f3b: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3f40:
	/* 0x3f40: mov    esi,0x10 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 16ULL);
x86_l_3f45:
	/* 0x3f45: call   3f4a <generic_retkprobe_event+0x3f4a> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_3f4a:
	/* 0x3f4a: jmp    3f60 <generic_retkprobe_event+0x3f60> */
	X86_SIM_X86_JMP(0x3f4a, 0x3f60, x86_l_3f60);
x86_l_3f4c:
	/* 0x3f4c: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3f51:
	/* 0x3f51: mov    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_3f59:
	/* 0x3f59: mov    QWORD PTR [rax],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3f60:
	/* 0x3f60: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3f65:
	/* 0x3f65: lea    rdi,[rax+0xac] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_3f6c:
	/* 0x3f6c: add    QWORD PTR [rsp+0x98],0x18 */
	X86_SIM_RUN_OP(X86_OP_ALU_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 652835029016ULL);
x86_l_3f75:
	/* 0x3f75: jns    3fba <generic_retkprobe_event+0x3fba> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x3f75, 0x3fba, x86_l_3fba);
x86_l_3f77:
	/* 0x3f77: mov    rcx,QWORD PTR [rsp+0x98] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_3f7f:
	/* 0x3f7f: test   rcx,rcx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_3f82:
	/* 0x3f82: jns    402e <generic_retkprobe_event+0x402e> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x3f82, 0x402e, x86_l_402e);
x86_l_3f88:
	/* 0x3f88: mov    rax,rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_3f8b:
	/* 0x3f8b: mov    rdx,rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_3f8e:
	/* 0x3f8e: mov    rax,QWORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3f91:
	/* 0x3f91: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3f96:
	/* 0x3f96: mov    QWORD PTR [rcx+0xac],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_3f9d:
	/* 0x3f9d: mov    rax,QWORD PTR [rdx+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3fa1:
	/* 0x3fa1: mov    QWORD PTR [rcx+0xb4],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 180ULL);
x86_l_3fa8:
	/* 0x3fa8: movzx  eax,BYTE PTR [rsp+0x80] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 128ULL);
x86_l_3fb0:
	/* 0x3fb0: cmp    eax,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_3fb3:
	/* 0x3fb3: jne    3fdd <generic_retkprobe_event+0x3fdd> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x3fb3, 0x3fdd, x86_l_3fdd);
x86_l_3fb5:
	/* 0x3fb5: jmp    3974 <generic_retkprobe_event+0x3974> */
	X86_SIM_X86_JMP(0x3fb5, 0x3974, x86_l_3974);
x86_l_3fba:
	/* 0x3fba: mov    esi,0x10 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 16ULL);
x86_l_3fbf:
	/* 0x3fbf: mov    rdx,QWORD PTR [rsp+0x98] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_3fc7:
	/* 0x3fc7: call   3fcc <generic_retkprobe_event+0x3fcc> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_3fcc:
	/* 0x3fcc: movzx  eax,BYTE PTR [rsp+0x80] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 128ULL);
x86_l_3fd4:
	/* 0x3fd4: cmp    eax,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_3fd7:
	/* 0x3fd7: je     3974 <generic_retkprobe_event+0x3974> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3fd7, 0x3974, x86_l_3974);
x86_l_3fdd:
	/* 0x3fdd: cmp    eax,0x6 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 6ULL);
x86_l_3fe0:
	/* 0x3fe0: jne    400e <generic_retkprobe_event+0x400e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x3fe0, 0x400e, x86_l_400e);
x86_l_3fe2:
	/* 0x3fe2: movzx  r12d,WORD PTR [rsp+0x90] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 144ULL);
x86_l_3feb:
	/* 0x3feb: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3ff0:
	/* 0x3ff0: lea    rdi,[rax+0xbc] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_3ff7:
	/* 0x3ff7: add    r12,QWORD PTR [rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_ALU_MEM, X86_R12, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 64ULL);
x86_l_3ffc:
	/* 0x3ffc: jns    401f <generic_retkprobe_event+0x401f> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x3ffc, 0x401f, x86_l_401f);
x86_l_3ffe:
	/* 0x3ffe: mov    rax,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_4001:
	/* 0x4001: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_4004:
	/* 0x4004: jns    404f <generic_retkprobe_event+0x404f> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x4004, 0x404f, x86_l_404f);
x86_l_4006:
	/* 0x4006: movzx  eax,WORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4009:
	/* 0x4009: mov    WORD PTR [rdi],ax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_400c:
	/* 0x400c: jmp    4054 <generic_retkprobe_event+0x4054> */
	X86_SIM_X86_JMP(0x400c, 0x4054, x86_l_4054);
x86_l_400e:
	/* 0x400e: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4013:
	/* 0x4013: mov    DWORD PTR [rax+0xbc],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_401d:
	/* 0x401d: jmp    4095 <generic_retkprobe_event+0x4095> */
	X86_SIM_X86_JMP(0x401d, 0x4095, x86_l_4095);
x86_l_401f:
	/* 0x401f: mov    esi,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_4024:
	/* 0x4024: mov    rdx,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_4027:
	/* 0x4027: call   402c <generic_retkprobe_event+0x402c> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_402c:
	/* 0x402c: jmp    4054 <generic_retkprobe_event+0x4054> */
	X86_SIM_X86_JMP(0x402c, 0x4054, x86_l_4054);
x86_l_402e:
	/* 0x402e: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_4036:
	/* 0x4036: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_403d:
	/* 0x403d: movzx  eax,BYTE PTR [rsp+0x80] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 128ULL);
x86_l_4045:
	/* 0x4045: cmp    eax,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_4048:
	/* 0x4048: jne    3fdd <generic_retkprobe_event+0x3fdd> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4048, 0x3fdd, x86_l_3fdd);
x86_l_404a:
	/* 0x404a: jmp    3974 <generic_retkprobe_event+0x3974> */
	X86_SIM_X86_JMP(0x404a, 0x3974, x86_l_3974);
x86_l_404f:
	/* 0x404f: mov    WORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4054:
	/* 0x4054: add    QWORD PTR [rsp+0x10],0xbe */
	X86_SIM_RUN_OP(X86_OP_ALU_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 68719476926ULL);
x86_l_405d:
	/* 0x405d: add    r12,0x2 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_4061:
	/* 0x4061: jns    4077 <generic_retkprobe_event+0x4077> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x4061, 0x4077, x86_l_4077);
x86_l_4063:
	/* 0x4063: test   r12,r12 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_4066:
	/* 0x4066: jns    408b <generic_retkprobe_event+0x408b> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x4066, 0x408b, x86_l_408b);
x86_l_4068:
	/* 0x4068: movzx  eax,WORD PTR [r12] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_406d:
	/* 0x406d: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4072:
	/* 0x4072: mov    WORD PTR [rcx],ax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4075:
	/* 0x4075: jmp    4095 <generic_retkprobe_event+0x4095> */
	X86_SIM_X86_JMP(0x4075, 0x4095, x86_l_4095);
x86_l_4077:
	/* 0x4077: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_407c:
	/* 0x407c: mov    esi,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_4081:
	/* 0x4081: mov    rdx,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_4084:
	/* 0x4084: call   4089 <generic_retkprobe_event+0x4089> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_4089:
	/* 0x4089: jmp    4095 <generic_retkprobe_event+0x4095> */
	X86_SIM_X86_JMP(0x4089, 0x4095, x86_l_4095);
x86_l_408b:
	/* 0x408b: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4090:
	/* 0x4090: mov    WORD PTR [rax],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4095:
	/* 0x4095: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_409a:
	/* 0x409a: movzx  eax,WORD PTR [rdx+0xbc] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 188ULL);
x86_l_40a1:
	/* 0x40a1: movzx  ecx,WORD PTR [rdx+0xbe] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 190ULL);
x86_l_40a8:
	/* 0x40a8: movbe  WORD PTR [rdx+0xbc],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RDX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 188ULL);
x86_l_40b1:
	/* 0x40b1: movbe  WORD PTR [rdx+0xbe],cx */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RDX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 190ULL);
x86_l_40ba:
	/* 0x40ba: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_40bf:
	/* 0x40bf: add    rcx,0xe0 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 224ULL);
x86_l_40c6:
	/* 0x40c6: test   rcx,rcx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_40c9:
	/* 0x40c9: mov    r14,QWORD PTR [rsp] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_40cd:
	/* 0x40cd: mov    r13d,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_40d3:
	/* 0x40d3: jns    412c <generic_retkprobe_event+0x412c> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x40d3, 0x412c, x86_l_412c);
x86_l_40d5:
	/* 0x40d5: mov    rax,rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_40d8:
	/* 0x40d8: mov    rdx,QWORD PTR [rcx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_40db:
	/* 0x40db: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_40de:
	/* 0x40de: je     412c <generic_retkprobe_event+0x412c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x40de, 0x412c, x86_l_412c);
x86_l_40e0:
	/* 0x40e0: lea    rcx,[rdx+0x5] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_40e4:
	/* 0x40e4: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_40e6:
	/* 0x40e6: test   rcx,rcx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_40e9:
	/* 0x40e9: jns    40f0 <generic_retkprobe_event+0x40f0> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x40e9, 0x40f0, x86_l_40f0);
x86_l_40eb:
	/* 0x40eb: mov    rsi,QWORD PTR [rcx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_40ee:
	/* 0x40ee: jmp    40f2 <generic_retkprobe_event+0x40f2> */
	X86_SIM_X86_JMP(0x40ee, 0x40f2, x86_l_40f2);
x86_l_40f0:
	/* 0x40f0: xor    esi,esi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_40f2:
	/* 0x40f2: lea    rcx,[rdx+rsi*8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 3), 0ULL);
x86_l_40f6:
	/* 0x40f6: lea    rdx,[rdx+rsi*8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 3), 0ULL);
x86_l_40fa:
	/* 0x40fa: add    rdx,0x44 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 68ULL);
x86_l_40fe:
	/* 0x40fe: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_4101:
	/* 0x4101: jns    4105 <generic_retkprobe_event+0x4105> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x4101, 0x4105, x86_l_4105);
x86_l_4103:
	/* 0x4103: mov    eax,DWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4105:
	/* 0x4105: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_410a:
	/* 0x410a: mov    DWORD PTR [rdx+0xd4],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 212ULL);
x86_l_4110:
	/* 0x4110: add    rcx,0x45 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 69ULL);
x86_l_4114:
	/* 0x4114: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_4116:
	/* 0x4116: test   rcx,rcx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_4119:
	/* 0x4119: jns    411d <generic_retkprobe_event+0x411d> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x4119, 0x411d, x86_l_411d);
x86_l_411b:
	/* 0x411b: mov    eax,DWORD PTR [rcx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_411d:
	/* 0x411d: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4122:
	/* 0x4122: mov    DWORD PTR [rcx+0xd8],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_4128:
	/* 0x4128: mov    r14,QWORD PTR [rsp] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_412c:
	/* 0x412c: mov    r12d,0x40 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 64ULL);
x86_l_4132:
	/* 0x4132: jmp    3d33 <generic_retkprobe_event+0x3d33> */
	X86_SIM_X86_JMP(0x4132, 0x3d33, x86_l_3d33);
x86_l_4137:
	/* 0x4137: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_413c:
	/* 0x413c: mov    BYTE PTR [rax+0x10b],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 1146756268032ULL);
x86_l_4143:
	/* 0x4143: mov    eax,0x6c */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 108ULL);
x86_l_4148:
	/* 0x4148: mov    r14,QWORD PTR [rsp] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_414c:
	/* 0x414c: dec    al */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_ALU_DEC, 1);
x86_l_414e:
	/* 0x414e: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4153:
	/* 0x4153: mov    BYTE PTR [rcx+0x9f],al */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 159ULL);
x86_l_4159:
	/* 0x4159: mov    r12d,0x70 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 112ULL);
x86_l_415f:
	/* 0x415f: jmp    3d2d <generic_retkprobe_event+0x3d2d> */
	X86_SIM_X86_JMP(0x415f, 0x3d2d, x86_l_3d2d);
x86_l_4164:
	/* 0x4164: mov    r12d,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_416a:
	/* 0x416a: mov    r14,QWORD PTR [rsp] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_416e:
	/* 0x416e: jmp    260c <generic_retkprobe_event+0x260c> */
	X86_SIM_X86_JMP(0x416e, 0x260c, x86_l_260c);
x86_l_4173:
	/* 0x4173: mov    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_4175:
	/* 0x4175: mov    esi,DWORD PTR [rdx+rcx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4178:
	/* 0x4178: mov    DWORD PTR [rdi+rcx*1],esi */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_417b:
	/* 0x417b: or     eax,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_OR, 4ULL);
x86_l_417e:
	/* 0x417e: test   bpl,0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, 0, 2ULL);
x86_l_4182:
	/* 0x4182: je     20c4 <generic_retkprobe_event+0x20c4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4182, 0x20c4, x86_l_20c4);
x86_l_4188:
	/* 0x4188: mov    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_418a:
	/* 0x418a: movzx  esi,WORD PTR [rdx+rcx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_16), 0ULL);
x86_l_418e:
	/* 0x418e: mov    WORD PTR [rdi+rcx*1],si */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RSI, X86_WIDTH_16, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4192:
	/* 0x4192: add    eax,0x2 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_4195:
	/* 0x4195: test   bpl,0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_4199:
	/* 0x4199: je     41a4 <generic_retkprobe_event+0x41a4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4199, 0x41a4, x86_l_41a4);
x86_l_419b:
	/* 0x419b: mov    eax,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_419d:
	/* 0x419d: movzx  ecx,BYTE PTR [rdx+rax*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_41a1:
	/* 0x41a1: mov    BYTE PTR [rdi+rax*1],cl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_41a4:
	/* 0x41a4: add    r15,rbp */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R15, X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_41a7:
	/* 0x41a7: test   r12,r12 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_41aa:
	/* 0x41aa: je     41b3 <generic_retkprobe_event+0x41b3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x41aa, 0x41b3, x86_l_41b3);
x86_l_41ac:
	/* 0x41ac: sub    r12,r14 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R12, X86_R14, X86_WIDTH_64, X86_ALU_SUB, 0);
x86_l_41af:
	/* 0x41af: jne    41b6 <generic_retkprobe_event+0x41b6> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x41af, 0x41b6, x86_l_41b6);
x86_l_41b1:
	/* 0x41b1: jmp    41c1 <generic_retkprobe_event+0x41c1> */
	X86_SIM_X86_JMP(0x41b1, 0x41c1, x86_l_41c1);
x86_l_41b3:
	/* 0x41b3: xor    r12d,r12d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_41b6:
	/* 0x41b6: cmp    QWORD PTR [rsp+0xb0],0x3 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244099ULL);
x86_l_41bf:
	/* 0x41bf: jne    41d2 <generic_retkprobe_event+0x41d2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x41bf, 0x41d2, x86_l_41d2);
x86_l_41c1:
	/* 0x41c1: mov    r13,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R13, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_41c4:
	/* 0x41c4: mov    r14,QWORD PTR [rsp] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_41c8:
	/* 0x41c8: mov    r8,QWORD PTR [rsp+0x30] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_41cd:
	/* 0x41cd: jmp    3b5 <generic_retkprobe_event+0x3b5> */
	X86_SIM_X86_JMP(0x41cd, 0x3b5, x86_l_3b5);
x86_l_41d2:
	/* 0x41d2: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_41d7:
	/* 0x41d7: add    rdx,0x30 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_41db:
	/* 0x41db: js     420f <generic_retkprobe_event+0x420f> */
	X86_SIM_X86_JCC(X86_CC_S, 0x41db, 0x420f, x86_l_420f);
x86_l_41dd:
	/* 0x41dd: lea    rdi,[rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_41e2:
	/* 0x41e2: mov    esi,0x10 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 16ULL);
x86_l_41e7:
	/* 0x41e7: call   41ec <generic_retkprobe_event+0x41ec> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_41ec:
	/* 0x41ec: mov    ecx,0xfffffffe */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 4294967294ULL);
x86_l_41f1:
	/* 0x41f1: test   eax,eax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_41f3:
	/* 0x41f3: js     3c7e <generic_retkprobe_event+0x3c7e> */
	X86_SIM_X86_JCC(X86_CC_S, 0x41f3, 0x3c7e, x86_l_3c7e);
x86_l_41f9:
	/* 0x41f9: mov    rcx,QWORD PTR [rsp+0x48] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_41fe:
	/* 0x41fe: jmp    4231 <generic_retkprobe_event+0x4231> */
	X86_SIM_X86_JMP(0x41fe, 0x4231, x86_l_4231);
x86_l_4200:
	/* 0x4200: mov    r12d,0x5 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 5ULL);
x86_l_4206:
	/* 0x4206: mov    r14,QWORD PTR [rsp] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_420a:
	/* 0x420a: jmp    260c <generic_retkprobe_event+0x260c> */
	X86_SIM_X86_JMP(0x420a, 0x260c, x86_l_260c);
x86_l_420f:
	/* 0x420f: mov    ecx,0xfffffffe */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 4294967294ULL);
x86_l_4214:
	/* 0x4214: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_4217:
	/* 0x4217: jns    3c7e <generic_retkprobe_event+0x3c7e> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x4217, 0x3c7e, x86_l_3c7e);
x86_l_421d:
	/* 0x421d: mov    rax,QWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4220:
	/* 0x4220: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_4225:
	/* 0x4225: mov    rax,QWORD PTR [rdx+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4229:
	/* 0x4229: mov    rcx,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_422c:
	/* 0x422c: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_4231:
	/* 0x4231: mov    rax,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_4234:
	/* 0x4234: mov    rdx,rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_4237:
	/* 0x4237: cmp    rcx,r12 */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RCX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_423a:
	/* 0x423a: mov    r14,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R14, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_423d:
	/* 0x423d: cmovb  r14,rcx */
	X86_SIM_RUN_OP(X86_OP_CMOV, X86_R14, X86_RCX, X86_WIDTH_64, X86_CC_B, 0);
x86_l_4241:
	/* 0x4241: test   r12,r12 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_4244:
	/* 0x4244: cmovne rdx,r14 */
	X86_SIM_RUN_OP(X86_OP_CMOV, X86_RDX, X86_R14, X86_WIDTH_64, X86_CC_NE, 0);
x86_l_4248:
	/* 0x4248: mov    ecx,0xfffffffd */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 4294967293ULL);
x86_l_424d:
	/* 0x424d: mov    rax,rdx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_4250:
	/* 0x4250: mov    QWORD PTR [rsp+0x28],rdx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4255:
	/* 0x4255: cmp    rdx,0xffe */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, 0, 4094ULL);
x86_l_425c:
	/* 0x425c: ja     3c7e <generic_retkprobe_event+0x3c7e> */
	X86_SIM_X86_JCC(X86_CC_A, 0x425c, 0x3c7e, x86_l_3c7e);
x86_l_4262:
	/* 0x4262: add    rbp,r13 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_4265:
	/* 0x4265: mov    edi,ebp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_RBP, X86_WIDTH_32, 0, 0);
x86_l_4267:
	/* 0x4267: and    edi,0x3fff */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_426d:
	/* 0x426d: add    rdi,QWORD PTR [rsp] */
	X86_SIM_RUN_OP(X86_OP_ALU_MEM, X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4271:
	/* 0x4271: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_4276:
	/* 0x4276: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_4279:
	/* 0x4279: jns    42fc <generic_retkprobe_event+0x42fc> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x4279, 0x42fc, x86_l_42fc);
x86_l_427f:
	/* 0x427f: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_4282:
	/* 0x4282: jns    4622 <generic_retkprobe_event+0x4622> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x4282, 0x4622, x86_l_4622);
x86_l_4288:
	/* 0x4288: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_428a:
	/* 0x428a: cmp    DWORD PTR [rsp+0x28],0x8 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691848ULL);
x86_l_428f:
	/* 0x428f: jb     42ab <generic_retkprobe_event+0x42ab> */
	X86_SIM_X86_JCC(X86_CC_B, 0x428f, 0x42ab, x86_l_42ab);
x86_l_4291:
	/* 0x4291: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_4293:
	/* 0x4293: mov    eax,ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_4295:
	/* 0x4295: mov    rsi,QWORD PTR [rdx+rax*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_4299:
	/* 0x4299: mov    QWORD PTR [rdi+rax*1],rsi */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_429d:
	/* 0x429d: lea    eax,[rcx+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_42a0:
	/* 0x42a0: add    ecx,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 16ULL);
x86_l_42a3:
	/* 0x42a3: cmp    ecx,DWORD PTR [rsp+0x28] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 40ULL);
x86_l_42a7:
	/* 0x42a7: mov    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_42a9:
	/* 0x42a9: jbe    4293 <generic_retkprobe_event+0x4293> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x42a9, 0x4293, x86_l_4293);
x86_l_42ab:
	/* 0x42ab: test   BYTE PTR [rsp+0x28],0x4 */
	X86_SIM_RUN_OP(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 171798691844ULL);
x86_l_42b0:
	/* 0x42b0: jne    4342 <generic_retkprobe_event+0x4342> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x42b0, 0x4342, x86_l_4342);
x86_l_42b6:
	/* 0x42b6: test   BYTE PTR [rsp+0x28],0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 171798691842ULL);
x86_l_42bb:
	/* 0x42bb: jne    4358 <generic_retkprobe_event+0x4358> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x42bb, 0x4358, x86_l_4358);
x86_l_42c1:
	/* 0x42c1: test   BYTE PTR [rsp+0x28],0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 171798691841ULL);
x86_l_42c6:
	/* 0x42c6: jne    436c <generic_retkprobe_event+0x436c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x42c6, 0x436c, x86_l_436c);
x86_l_42cc:
	/* 0x42cc: jmp    4375 <generic_retkprobe_event+0x4375> */
	X86_SIM_X86_JMP(0x42cc, 0x4375, x86_l_4375);
x86_l_42d1:
	/* 0x42d1: mov    WORD PTR [rsp+0x90],ax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_42d9:
	/* 0x42d9: jmp    3eed <generic_retkprobe_event+0x3eed> */
	X86_SIM_X86_JMP(0x42d9, 0x3eed, x86_l_3eed);
x86_l_42de:
	/* 0x42de: mov    r12d,0x6 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 6ULL);
x86_l_42e4:
	/* 0x42e4: mov    r14,QWORD PTR [rsp] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_42e8:
	/* 0x42e8: jmp    260c <generic_retkprobe_event+0x260c> */
	X86_SIM_X86_JMP(0x42e8, 0x260c, x86_l_260c);
x86_l_42ed:
	/* 0x42ed: mov    r12d,0x7 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 7ULL);
x86_l_42f3:
	/* 0x42f3: mov    r14,QWORD PTR [rsp] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_42f7:
	/* 0x42f7: jmp    260c <generic_retkprobe_event+0x260c> */
	X86_SIM_X86_JMP(0x42f7, 0x260c, x86_l_260c);
x86_l_42fc:
	/* 0x42fc: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4301:
	/* 0x4301: call   4306 <generic_retkprobe_event+0x4306> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_4306:
	/* 0x4306: mov    ecx,0xfffffffe */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 4294967294ULL);
x86_l_430b:
	/* 0x430b: test   eax,eax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_430d:
	/* 0x430d: js     3c7e <generic_retkprobe_event+0x3c7e> */
	X86_SIM_X86_JCC(X86_CC_S, 0x430d, 0x3c7e, x86_l_3c7e);
x86_l_4313:
	/* 0x4313: jmp    4375 <generic_retkprobe_event+0x4375> */
	X86_SIM_X86_JMP(0x4313, 0x4375, x86_l_4375);
x86_l_4315:
	/* 0x4315: mov    r12d,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_431b:
	/* 0x431b: mov    r14,QWORD PTR [rsp] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_431f:
	/* 0x431f: jmp    260c <generic_retkprobe_event+0x260c> */
	X86_SIM_X86_JMP(0x431f, 0x260c, x86_l_260c);
x86_l_4324:
	/* 0x4324: mov    r12d,0x9 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 9ULL);
x86_l_432a:
	/* 0x432a: mov    r14,QWORD PTR [rsp] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_432e:
	/* 0x432e: jmp    260c <generic_retkprobe_event+0x260c> */
	X86_SIM_X86_JMP(0x432e, 0x260c, x86_l_260c);
x86_l_4333:
	/* 0x4333: mov    r12d,0xa */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 10ULL);
x86_l_4339:
	/* 0x4339: mov    r14,QWORD PTR [rsp] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_433d:
	/* 0x433d: jmp    260c <generic_retkprobe_event+0x260c> */
	X86_SIM_X86_JMP(0x433d, 0x260c, x86_l_260c);
x86_l_4342:
	/* 0x4342: mov    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_4344:
	/* 0x4344: mov    esi,DWORD PTR [rdx+rcx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4347:
	/* 0x4347: mov    DWORD PTR [rdi+rcx*1],esi */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_434a:
	/* 0x434a: or     eax,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_OR, 4ULL);
x86_l_434d:
	/* 0x434d: test   BYTE PTR [rsp+0x28],0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 171798691842ULL);
x86_l_4352:
	/* 0x4352: je     42c1 <generic_retkprobe_event+0x42c1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4352, 0x42c1, x86_l_42c1);
x86_l_4358:
	/* 0x4358: mov    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_435a:
	/* 0x435a: movzx  esi,WORD PTR [rdx+rcx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_16), 0ULL);
x86_l_435e:
	/* 0x435e: mov    WORD PTR [rdi+rcx*1],si */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RSI, X86_WIDTH_16, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4362:
	/* 0x4362: add    eax,0x2 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_4365:
	/* 0x4365: test   BYTE PTR [rsp+0x28],0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 171798691841ULL);
x86_l_436a:
	/* 0x436a: je     4375 <generic_retkprobe_event+0x4375> */
	X86_SIM_X86_JCC(X86_CC_E, 0x436a, 0x4375, x86_l_4375);
x86_l_436c:
	/* 0x436c: mov    eax,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_436e:
	/* 0x436e: movzx  ecx,BYTE PTR [rdx+rax*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_4372:
	/* 0x4372: mov    BYTE PTR [rdi+rax*1],cl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_4375:
	/* 0x4375: add    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_RUN_OP(X86_OP_ALU_MEM, X86_R15, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_437a:
	/* 0x437a: test   r12,r12 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_437d:
	/* 0x437d: je     4389 <generic_retkprobe_event+0x4389> */
	X86_SIM_X86_JCC(X86_CC_E, 0x437d, 0x4389, x86_l_4389);
x86_l_437f:
	/* 0x437f: sub    r12,r14 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R12, X86_R14, X86_WIDTH_64, X86_ALU_SUB, 0);
x86_l_4382:
	/* 0x4382: jne    438c <generic_retkprobe_event+0x438c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4382, 0x438c, x86_l_438c);
x86_l_4384:
	/* 0x4384: jmp    41c1 <generic_retkprobe_event+0x41c1> */
	X86_SIM_X86_JMP(0x4384, 0x41c1, x86_l_41c1);
x86_l_4389:
	/* 0x4389: xor    r12d,r12d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_438c:
	/* 0x438c: cmp    QWORD PTR [rsp+0xb0],0x5 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244101ULL);
x86_l_4395:
	/* 0x4395: jb     41c1 <generic_retkprobe_event+0x41c1> */
	X86_SIM_X86_JCC(X86_CC_B, 0x4395, 0x41c1, x86_l_41c1);
x86_l_439b:
	/* 0x439b: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_43a0:
	/* 0x43a0: add    rdx,0x40 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 64ULL);
x86_l_43a4:
	/* 0x43a4: js     43d8 <generic_retkprobe_event+0x43d8> */
	X86_SIM_X86_JCC(X86_CC_S, 0x43a4, 0x43d8, x86_l_43d8);
x86_l_43a6:
	/* 0x43a6: lea    rdi,[rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_43ab:
	/* 0x43ab: mov    esi,0x10 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 16ULL);
x86_l_43b0:
	/* 0x43b0: call   43b5 <generic_retkprobe_event+0x43b5> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_43b5:
	/* 0x43b5: mov    ecx,0xfffffffe */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 4294967294ULL);
x86_l_43ba:
	/* 0x43ba: test   eax,eax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_43bc:
	/* 0x43bc: js     3c7e <generic_retkprobe_event+0x3c7e> */
	X86_SIM_X86_JCC(X86_CC_S, 0x43bc, 0x3c7e, x86_l_3c7e);
x86_l_43c2:
	/* 0x43c2: mov    rcx,QWORD PTR [rsp+0x48] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_43c7:
	/* 0x43c7: jmp    43fa <generic_retkprobe_event+0x43fa> */
	X86_SIM_X86_JMP(0x43c7, 0x43fa, x86_l_43fa);
x86_l_43c9:
	/* 0x43c9: mov    r12d,0xb */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 11ULL);
x86_l_43cf:
	/* 0x43cf: mov    r14,QWORD PTR [rsp] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_43d3:
	/* 0x43d3: jmp    260c <generic_retkprobe_event+0x260c> */
	X86_SIM_X86_JMP(0x43d3, 0x260c, x86_l_260c);
x86_l_43d8:
	/* 0x43d8: mov    ecx,0xfffffffe */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 4294967294ULL);
x86_l_43dd:
	/* 0x43dd: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_43e0:
	/* 0x43e0: jns    3c7e <generic_retkprobe_event+0x3c7e> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x43e0, 0x3c7e, x86_l_3c7e);
x86_l_43e6:
	/* 0x43e6: mov    rax,QWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_43e9:
	/* 0x43e9: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_43ee:
	/* 0x43ee: mov    rax,QWORD PTR [rdx+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_43f2:
	/* 0x43f2: mov    rcx,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_43f5:
	/* 0x43f5: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_43fa:
	/* 0x43fa: mov    rax,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_43fd:
	/* 0x43fd: mov    rdx,rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_4400:
	/* 0x4400: cmp    rcx,r12 */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RCX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_4403:
	/* 0x4403: mov    r14,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R14, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_4406:
	/* 0x4406: cmovb  r14,rcx */
	X86_SIM_RUN_OP(X86_OP_CMOV, X86_R14, X86_RCX, X86_WIDTH_64, X86_CC_B, 0);
x86_l_440a:
	/* 0x440a: test   r12,r12 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_440d:
	/* 0x440d: cmovne rdx,r14 */
	X86_SIM_RUN_OP(X86_OP_CMOV, X86_RDX, X86_R14, X86_WIDTH_64, X86_CC_NE, 0);
x86_l_4411:
	/* 0x4411: mov    ecx,0xfffffffd */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 4294967293ULL);
x86_l_4416:
	/* 0x4416: cmp    rdx,0xffe */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, 0, 4094ULL);
x86_l_441d:
	/* 0x441d: ja     3c7e <generic_retkprobe_event+0x3c7e> */
	X86_SIM_X86_JCC(X86_CC_A, 0x441d, 0x3c7e, x86_l_3c7e);
x86_l_4423:
	/* 0x4423: mov    r13,rdx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R13, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_4426:
	/* 0x4426: mov    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_442b:
	/* 0x442b: add    rdi,rbp */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_442e:
	/* 0x442e: mov    rbp,rdi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RBP, X86_RDI, X86_WIDTH_64, 0, 0);
x86_l_4431:
	/* 0x4431: and    edi,0x3fff */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_4437:
	/* 0x4437: add    rdi,QWORD PTR [rsp] */
	X86_SIM_RUN_OP(X86_OP_ALU_MEM, X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_443b:
	/* 0x443b: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_4440:
	/* 0x4440: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_4443:
	/* 0x4443: jns    44bb <generic_retkprobe_event+0x44bb> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x4443, 0x44bb, x86_l_44bb);
x86_l_4445:
	/* 0x4445: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_4448:
	/* 0x4448: jns    476f <generic_retkprobe_event+0x476f> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x4448, 0x476f, x86_l_476f);
x86_l_444e:
	/* 0x444e: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_4450:
	/* 0x4450: cmp    r13d,0x8 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_4454:
	/* 0x4454: jb     446f <generic_retkprobe_event+0x446f> */
	X86_SIM_X86_JCC(X86_CC_B, 0x4454, 0x446f, x86_l_446f);
x86_l_4456:
	/* 0x4456: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_4458:
	/* 0x4458: mov    eax,ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_445a:
	/* 0x445a: mov    rsi,QWORD PTR [rdx+rax*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_445e:
	/* 0x445e: mov    QWORD PTR [rdi+rax*1],rsi */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_4462:
	/* 0x4462: lea    eax,[rcx+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4465:
	/* 0x4465: add    ecx,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 16ULL);
x86_l_4468:
	/* 0x4468: cmp    ecx,r13d */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RCX, X86_R13, X86_WIDTH_32, 0, 0);
x86_l_446b:
	/* 0x446b: mov    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_446d:
	/* 0x446d: jbe    4458 <generic_retkprobe_event+0x4458> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x446d, 0x4458, x86_l_4458);
x86_l_446f:
	/* 0x446f: test   r13b,0x4 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, 0, 4ULL);
x86_l_4473:
	/* 0x4473: jne    44f0 <generic_retkprobe_event+0x44f0> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4473, 0x44f0, x86_l_44f0);
x86_l_4475:
	/* 0x4475: test   r13b,0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, 0, 2ULL);
x86_l_4479:
	/* 0x4479: jne    4505 <generic_retkprobe_event+0x4505> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4479, 0x4505, x86_l_4505);
x86_l_447f:
	/* 0x447f: test   r13b,0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_4483:
	/* 0x4483: jne    4518 <generic_retkprobe_event+0x4518> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4483, 0x4518, x86_l_4518);
x86_l_4489:
	/* 0x4489: jmp    4521 <generic_retkprobe_event+0x4521> */
	X86_SIM_X86_JMP(0x4489, 0x4521, x86_l_4521);
x86_l_448e:
	/* 0x448e: mov    r12d,0xc */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 12ULL);
x86_l_4494:
	/* 0x4494: mov    r14,QWORD PTR [rsp] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4498:
	/* 0x4498: jmp    260c <generic_retkprobe_event+0x260c> */
	X86_SIM_X86_JMP(0x4498, 0x260c, x86_l_260c);
x86_l_449d:
	/* 0x449d: mov    r12d,0xd */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 13ULL);
x86_l_44a3:
	/* 0x44a3: mov    r14,QWORD PTR [rsp] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_44a7:
	/* 0x44a7: jmp    260c <generic_retkprobe_event+0x260c> */
	X86_SIM_X86_JMP(0x44a7, 0x260c, x86_l_260c);
x86_l_44ac:
	/* 0x44ac: mov    r12d,0xe */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 14ULL);
x86_l_44b2:
	/* 0x44b2: mov    r14,QWORD PTR [rsp] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_44b6:
	/* 0x44b6: jmp    260c <generic_retkprobe_event+0x260c> */
	X86_SIM_X86_JMP(0x44b6, 0x260c, x86_l_260c);
x86_l_44bb:
	/* 0x44bb: mov    esi,r13d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_R13, X86_WIDTH_32, 0, 0);
x86_l_44be:
	/* 0x44be: call   44c3 <generic_retkprobe_event+0x44c3> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_44c3:
	/* 0x44c3: mov    ecx,0xfffffffe */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 4294967294ULL);
x86_l_44c8:
	/* 0x44c8: test   eax,eax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_44ca:
	/* 0x44ca: js     3c7e <generic_retkprobe_event+0x3c7e> */
	X86_SIM_X86_JCC(X86_CC_S, 0x44ca, 0x3c7e, x86_l_3c7e);
x86_l_44d0:
	/* 0x44d0: jmp    4521 <generic_retkprobe_event+0x4521> */
	X86_SIM_X86_JMP(0x44d0, 0x4521, x86_l_4521);
x86_l_44d2:
	/* 0x44d2: mov    r12d,0xf */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 15ULL);
x86_l_44d8:
	/* 0x44d8: mov    r14,QWORD PTR [rsp] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_44dc:
	/* 0x44dc: jmp    260c <generic_retkprobe_event+0x260c> */
	X86_SIM_X86_JMP(0x44dc, 0x260c, x86_l_260c);
x86_l_44e1:
	/* 0x44e1: mov    r12d,0x10 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 16ULL);
x86_l_44e7:
	/* 0x44e7: mov    r14,QWORD PTR [rsp] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_44eb:
	/* 0x44eb: jmp    260c <generic_retkprobe_event+0x260c> */
	X86_SIM_X86_JMP(0x44eb, 0x260c, x86_l_260c);
x86_l_44f0:
	/* 0x44f0: mov    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_44f2:
	/* 0x44f2: mov    esi,DWORD PTR [rdx+rcx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_44f5:
	/* 0x44f5: mov    DWORD PTR [rdi+rcx*1],esi */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_44f8:
	/* 0x44f8: or     eax,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_OR, 4ULL);
x86_l_44fb:
	/* 0x44fb: test   r13b,0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, 0, 2ULL);
x86_l_44ff:
	/* 0x44ff: je     447f <generic_retkprobe_event+0x447f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x44ff, 0x447f, x86_l_447f);
x86_l_4505:
	/* 0x4505: mov    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_4507:
	/* 0x4507: movzx  esi,WORD PTR [rdx+rcx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_16), 0ULL);
x86_l_450b:
	/* 0x450b: mov    WORD PTR [rdi+rcx*1],si */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RSI, X86_WIDTH_16, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_450f:
	/* 0x450f: add    eax,0x2 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_4512:
	/* 0x4512: test   r13b,0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_4516:
	/* 0x4516: je     4521 <generic_retkprobe_event+0x4521> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4516, 0x4521, x86_l_4521);
x86_l_4518:
	/* 0x4518: mov    eax,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_451a:
	/* 0x451a: movzx  ecx,BYTE PTR [rdx+rax*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_451e:
	/* 0x451e: mov    BYTE PTR [rdi+rax*1],cl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_4521:
	/* 0x4521: add    r15,r13 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R15, X86_R13, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_4524:
	/* 0x4524: test   r12,r12 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_4527:
	/* 0x4527: je     4533 <generic_retkprobe_event+0x4533> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4527, 0x4533, x86_l_4533);
x86_l_4529:
	/* 0x4529: sub    r12,r14 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R12, X86_R14, X86_WIDTH_64, X86_ALU_SUB, 0);
x86_l_452c:
	/* 0x452c: jne    4536 <generic_retkprobe_event+0x4536> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x452c, 0x4536, x86_l_4536);
x86_l_452e:
	/* 0x452e: jmp    41c1 <generic_retkprobe_event+0x41c1> */
	X86_SIM_X86_JMP(0x452e, 0x41c1, x86_l_41c1);
x86_l_4533:
	/* 0x4533: xor    r12d,r12d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_4536:
	/* 0x4536: cmp    QWORD PTR [rsp+0xb0],0x5 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244101ULL);
x86_l_453f:
	/* 0x453f: je     41c1 <generic_retkprobe_event+0x41c1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x453f, 0x41c1, x86_l_41c1);
x86_l_4545:
	/* 0x4545: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_454a:
	/* 0x454a: add    rdx,0x50 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_454e:
	/* 0x454e: js     4573 <generic_retkprobe_event+0x4573> */
	X86_SIM_X86_JCC(X86_CC_S, 0x454e, 0x4573, x86_l_4573);
x86_l_4550:
	/* 0x4550: lea    rdi,[rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_4555:
	/* 0x4555: mov    esi,0x10 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 16ULL);
x86_l_455a:
	/* 0x455a: call   455f <generic_retkprobe_event+0x455f> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_455f:
	/* 0x455f: mov    ecx,0xfffffffe */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 4294967294ULL);
x86_l_4564:
	/* 0x4564: test   eax,eax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_4566:
	/* 0x4566: js     3c7e <generic_retkprobe_event+0x3c7e> */
	X86_SIM_X86_JCC(X86_CC_S, 0x4566, 0x3c7e, x86_l_3c7e);
x86_l_456c:
	/* 0x456c: mov    rcx,QWORD PTR [rsp+0x48] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_4571:
	/* 0x4571: jmp    4595 <generic_retkprobe_event+0x4595> */
	X86_SIM_X86_JMP(0x4571, 0x4595, x86_l_4595);
x86_l_4573:
	/* 0x4573: mov    ecx,0xfffffffe */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 4294967294ULL);
x86_l_4578:
	/* 0x4578: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_457b:
	/* 0x457b: jns    3c7e <generic_retkprobe_event+0x3c7e> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x457b, 0x3c7e, x86_l_3c7e);
x86_l_4581:
	/* 0x4581: mov    rax,QWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4584:
	/* 0x4584: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_4589:
	/* 0x4589: mov    rax,QWORD PTR [rdx+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_458d:
	/* 0x458d: mov    rcx,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_4590:
	/* 0x4590: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_4595:
	/* 0x4595: mov    rax,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_4598:
	/* 0x4598: mov    rdx,rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_459b:
	/* 0x459b: cmp    rcx,r12 */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RCX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_459e:
	/* 0x459e: mov    r14,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R14, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_45a1:
	/* 0x45a1: cmovb  r14,rcx */
	X86_SIM_RUN_OP(X86_OP_CMOV, X86_R14, X86_RCX, X86_WIDTH_64, X86_CC_B, 0);
x86_l_45a5:
	/* 0x45a5: test   r12,r12 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_45a8:
	/* 0x45a8: cmovne rdx,r14 */
	X86_SIM_RUN_OP(X86_OP_CMOV, X86_RDX, X86_R14, X86_WIDTH_64, X86_CC_NE, 0);
x86_l_45ac:
	/* 0x45ac: mov    ecx,0xfffffffd */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 4294967293ULL);
x86_l_45b1:
	/* 0x45b1: mov    rax,rdx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_45b4:
	/* 0x45b4: mov    QWORD PTR [rsp+0x28],rdx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_45b9:
	/* 0x45b9: cmp    rdx,0xffe */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, 0, 4094ULL);
x86_l_45c0:
	/* 0x45c0: ja     3c7e <generic_retkprobe_event+0x3c7e> */
	X86_SIM_X86_JCC(X86_CC_A, 0x45c0, 0x3c7e, x86_l_3c7e);
x86_l_45c6:
	/* 0x45c6: add    r13,rbp */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_45c9:
	/* 0x45c9: mov    rbp,r13 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RBP, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_45cc:
	/* 0x45cc: mov    edi,r13d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_R13, X86_WIDTH_32, 0, 0);
x86_l_45cf:
	/* 0x45cf: and    edi,0x3fff */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_45d5:
	/* 0x45d5: add    rdi,QWORD PTR [rsp] */
	X86_SIM_RUN_OP(X86_OP_ALU_MEM, X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_45d9:
	/* 0x45d9: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_45de:
	/* 0x45de: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_45e1:
	/* 0x45e1: jns    462e <generic_retkprobe_event+0x462e> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x45e1, 0x462e, x86_l_462e);
x86_l_45e3:
	/* 0x45e3: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_45e6:
	/* 0x45e6: jns    4622 <generic_retkprobe_event+0x4622> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x45e6, 0x4622, x86_l_4622);
x86_l_45e8:
	/* 0x45e8: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_45ea:
	/* 0x45ea: cmp    DWORD PTR [rsp+0x28],0x8 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691848ULL);
x86_l_45ef:
	/* 0x45ef: jb     460b <generic_retkprobe_event+0x460b> */
	X86_SIM_X86_JCC(X86_CC_B, 0x45ef, 0x460b, x86_l_460b);
x86_l_45f1:
	/* 0x45f1: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_45f3:
	/* 0x45f3: mov    eax,ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_45f5:
	/* 0x45f5: mov    rsi,QWORD PTR [rdx+rax*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_45f9:
	/* 0x45f9: mov    QWORD PTR [rdi+rax*1],rsi */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_45fd:
	/* 0x45fd: lea    eax,[rcx+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4600:
	/* 0x4600: add    ecx,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 16ULL);
x86_l_4603:
	/* 0x4603: cmp    ecx,DWORD PTR [rsp+0x28] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 40ULL);
x86_l_4607:
	/* 0x4607: mov    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_4609:
	/* 0x4609: jbe    45f3 <generic_retkprobe_event+0x45f3> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x4609, 0x45f3, x86_l_45f3);
x86_l_460b:
	/* 0x460b: test   BYTE PTR [rsp+0x28],0x4 */
	X86_SIM_RUN_OP(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 171798691844ULL);
x86_l_4610:
	/* 0x4610: jne    4647 <generic_retkprobe_event+0x4647> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4610, 0x4647, x86_l_4647);
x86_l_4612:
	/* 0x4612: test   BYTE PTR [rsp+0x28],0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 171798691842ULL);
x86_l_4617:
	/* 0x4617: jne    4659 <generic_retkprobe_event+0x4659> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4617, 0x4659, x86_l_4659);
x86_l_4619:
	/* 0x4619: test   BYTE PTR [rsp+0x28],0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 171798691841ULL);
x86_l_461e:
	/* 0x461e: jne    466d <generic_retkprobe_event+0x466d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x461e, 0x466d, x86_l_466d);
x86_l_4620:
	/* 0x4620: jmp    4676 <generic_retkprobe_event+0x4676> */
	X86_SIM_X86_JMP(0x4620, 0x4676, x86_l_4676);
x86_l_4622:
	/* 0x4622: xor    esi,esi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_4624:
	/* 0x4624: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4629:
	/* 0x4629: jmp    3c74 <generic_retkprobe_event+0x3c74> */
	X86_SIM_X86_JMP(0x4629, 0x3c74, x86_l_3c74);
x86_l_462e:
	/* 0x462e: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4633:
	/* 0x4633: call   4638 <generic_retkprobe_event+0x4638> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_4638:
	/* 0x4638: mov    ecx,0xfffffffe */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 4294967294ULL);
x86_l_463d:
	/* 0x463d: test   eax,eax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_463f:
	/* 0x463f: js     3c7e <generic_retkprobe_event+0x3c7e> */
	X86_SIM_X86_JCC(X86_CC_S, 0x463f, 0x3c7e, x86_l_3c7e);
x86_l_4645:
	/* 0x4645: jmp    4676 <generic_retkprobe_event+0x4676> */
	X86_SIM_X86_JMP(0x4645, 0x4676, x86_l_4676);
x86_l_4647:
	/* 0x4647: mov    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_4649:
	/* 0x4649: mov    esi,DWORD PTR [rdx+rcx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_464c:
	/* 0x464c: mov    DWORD PTR [rdi+rcx*1],esi */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_464f:
	/* 0x464f: or     eax,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_OR, 4ULL);
x86_l_4652:
	/* 0x4652: test   BYTE PTR [rsp+0x28],0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 171798691842ULL);
x86_l_4657:
	/* 0x4657: je     4619 <generic_retkprobe_event+0x4619> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4657, 0x4619, x86_l_4619);
x86_l_4659:
	/* 0x4659: mov    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_465b:
	/* 0x465b: movzx  esi,WORD PTR [rdx+rcx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_16), 0ULL);
x86_l_465f:
	/* 0x465f: mov    WORD PTR [rdi+rcx*1],si */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RSI, X86_WIDTH_16, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4663:
	/* 0x4663: add    eax,0x2 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_4666:
	/* 0x4666: test   BYTE PTR [rsp+0x28],0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 171798691841ULL);
x86_l_466b:
	/* 0x466b: je     4676 <generic_retkprobe_event+0x4676> */
	X86_SIM_X86_JCC(X86_CC_E, 0x466b, 0x4676, x86_l_4676);
x86_l_466d:
	/* 0x466d: mov    eax,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_466f:
	/* 0x466f: movzx  ecx,BYTE PTR [rdx+rax*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_4673:
	/* 0x4673: mov    BYTE PTR [rdi+rax*1],cl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_4676:
	/* 0x4676: add    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_RUN_OP(X86_OP_ALU_MEM, X86_R15, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_467b:
	/* 0x467b: test   r12,r12 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_467e:
	/* 0x467e: je     468a <generic_retkprobe_event+0x468a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x467e, 0x468a, x86_l_468a);
x86_l_4680:
	/* 0x4680: sub    r12,r14 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R12, X86_R14, X86_WIDTH_64, X86_ALU_SUB, 0);
x86_l_4683:
	/* 0x4683: jne    468d <generic_retkprobe_event+0x468d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4683, 0x468d, x86_l_468d);
x86_l_4685:
	/* 0x4685: jmp    41c1 <generic_retkprobe_event+0x41c1> */
	X86_SIM_X86_JMP(0x4685, 0x41c1, x86_l_41c1);
x86_l_468a:
	/* 0x468a: xor    r12d,r12d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_468d:
	/* 0x468d: cmp    QWORD PTR [rsp+0xb0],0x7 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244103ULL);
x86_l_4696:
	/* 0x4696: jb     41c1 <generic_retkprobe_event+0x41c1> */
	X86_SIM_X86_JCC(X86_CC_B, 0x4696, 0x41c1, x86_l_41c1);
x86_l_469c:
	/* 0x469c: add    QWORD PTR [rsp+0x38],0x60 */
	X86_SIM_RUN_OP(X86_OP_ALU_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 240518168672ULL);
x86_l_46a2:
	/* 0x46a2: js     46cc <generic_retkprobe_event+0x46cc> */
	X86_SIM_X86_JCC(X86_CC_S, 0x46a2, 0x46cc, x86_l_46cc);
x86_l_46a4:
	/* 0x46a4: lea    rdi,[rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_46a9:
	/* 0x46a9: mov    esi,0x10 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 16ULL);
x86_l_46ae:
	/* 0x46ae: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_46b3:
	/* 0x46b3: call   46b8 <generic_retkprobe_event+0x46b8> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_46b8:
	/* 0x46b8: mov    ecx,0xfffffffe */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 4294967294ULL);
x86_l_46bd:
	/* 0x46bd: test   eax,eax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_46bf:
	/* 0x46bf: js     3c7e <generic_retkprobe_event+0x3c7e> */
	X86_SIM_X86_JCC(X86_CC_S, 0x46bf, 0x3c7e, x86_l_3c7e);
x86_l_46c5:
	/* 0x46c5: mov    rax,QWORD PTR [rsp+0x48] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_46ca:
	/* 0x46ca: jmp    46f6 <generic_retkprobe_event+0x46f6> */
	X86_SIM_X86_JMP(0x46ca, 0x46f6, x86_l_46f6);
x86_l_46cc:
	/* 0x46cc: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_46d1:
	/* 0x46d1: mov    ecx,0xfffffffe */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 4294967294ULL);
x86_l_46d6:
	/* 0x46d6: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_46d9:
	/* 0x46d9: jns    3c7e <generic_retkprobe_event+0x3c7e> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x46d9, 0x3c7e, x86_l_3c7e);
x86_l_46df:
	/* 0x46df: mov    rax,rdx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_46e2:
	/* 0x46e2: mov    rcx,rdx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_46e5:
	/* 0x46e5: mov    rax,QWORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_46e8:
	/* 0x46e8: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_46ed:
	/* 0x46ed: mov    rax,QWORD PTR [rdx+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_46f1:
	/* 0x46f1: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_46f6:
	/* 0x46f6: cmp    rax,r12 */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RAX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_46f9:
	/* 0x46f9: mov    r13,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R13, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_46fc:
	/* 0x46fc: cmovb  r13,rax */
	X86_SIM_RUN_OP(X86_OP_CMOV, X86_R13, X86_RAX, X86_WIDTH_64, X86_CC_B, 0);
x86_l_4700:
	/* 0x4700: test   r12,r12 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_4703:
	/* 0x4703: cmove  r13,rax */
	X86_SIM_RUN_OP(X86_OP_CMOV, X86_R13, X86_RAX, X86_WIDTH_64, X86_CC_E, 0);
x86_l_4707:
	/* 0x4707: mov    ecx,0xfffffffd */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 4294967293ULL);
x86_l_470c:
	/* 0x470c: cmp    r13,0xffe */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, 0, 4094ULL);
x86_l_4713:
	/* 0x4713: ja     3c7e <generic_retkprobe_event+0x3c7e> */
	X86_SIM_X86_JCC(X86_CC_A, 0x4713, 0x3c7e, x86_l_3c7e);
x86_l_4719:
	/* 0x4719: mov    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_471e:
	/* 0x471e: add    rdi,rbp */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_4721:
	/* 0x4721: and    edi,0x3fff */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_4727:
	/* 0x4727: add    rdi,QWORD PTR [rsp] */
	X86_SIM_RUN_OP(X86_OP_ALU_MEM, X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_472b:
	/* 0x472b: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_4730:
	/* 0x4730: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_4733:
	/* 0x4733: jns    4779 <generic_retkprobe_event+0x4779> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x4733, 0x4779, x86_l_4779);
x86_l_4735:
	/* 0x4735: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_4738:
	/* 0x4738: jns    476f <generic_retkprobe_event+0x476f> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x4738, 0x476f, x86_l_476f);
x86_l_473a:
	/* 0x473a: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_473c:
	/* 0x473c: cmp    r13d,0x8 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_4740:
	/* 0x4740: jb     475b <generic_retkprobe_event+0x475b> */
	X86_SIM_X86_JCC(X86_CC_B, 0x4740, 0x475b, x86_l_475b);
x86_l_4742:
	/* 0x4742: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_4744:
	/* 0x4744: mov    eax,ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_4746:
	/* 0x4746: mov    rsi,QWORD PTR [rdx+rax*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_474a:
	/* 0x474a: mov    QWORD PTR [rdi+rax*1],rsi */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_474e:
	/* 0x474e: lea    eax,[rcx+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4751:
	/* 0x4751: add    ecx,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 16ULL);
x86_l_4754:
	/* 0x4754: cmp    ecx,r13d */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RCX, X86_R13, X86_WIDTH_32, 0, 0);
x86_l_4757:
	/* 0x4757: mov    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_4759:
	/* 0x4759: jbe    4744 <generic_retkprobe_event+0x4744> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x4759, 0x4744, x86_l_4744);
x86_l_475b:
	/* 0x475b: test   r13b,0x4 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, 0, 4ULL);
x86_l_475f:
	/* 0x475f: jne    4790 <generic_retkprobe_event+0x4790> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x475f, 0x4790, x86_l_4790);
x86_l_4761:
	/* 0x4761: test   r13b,0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, 0, 2ULL);
x86_l_4765:
	/* 0x4765: jne    47a1 <generic_retkprobe_event+0x47a1> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4765, 0x47a1, x86_l_47a1);
x86_l_4767:
	/* 0x4767: test   r13b,0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_476b:
	/* 0x476b: jne    47b4 <generic_retkprobe_event+0x47b4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x476b, 0x47b4, x86_l_47b4);
x86_l_476d:
	/* 0x476d: jmp    47bd <generic_retkprobe_event+0x47bd> */
	X86_SIM_X86_JMP(0x476d, 0x47bd, x86_l_47bd);
x86_l_476f:
	/* 0x476f: xor    esi,esi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_4771:
	/* 0x4771: mov    rdx,r13 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_4774:
	/* 0x4774: jmp    3c74 <generic_retkprobe_event+0x3c74> */
	X86_SIM_X86_JMP(0x4774, 0x3c74, x86_l_3c74);
x86_l_4779:
	/* 0x4779: mov    esi,r13d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_R13, X86_WIDTH_32, 0, 0);
x86_l_477c:
	/* 0x477c: call   4781 <generic_retkprobe_event+0x4781> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_4781:
	/* 0x4781: mov    ecx,0xfffffffe */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 4294967294ULL);
x86_l_4786:
	/* 0x4786: test   eax,eax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_4788:
	/* 0x4788: js     3c7e <generic_retkprobe_event+0x3c7e> */
	X86_SIM_X86_JCC(X86_CC_S, 0x4788, 0x3c7e, x86_l_3c7e);
x86_l_478e:
	/* 0x478e: jmp    47bd <generic_retkprobe_event+0x47bd> */
	X86_SIM_X86_JMP(0x478e, 0x47bd, x86_l_47bd);
x86_l_4790:
	/* 0x4790: mov    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_4792:
	/* 0x4792: mov    esi,DWORD PTR [rdx+rcx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4795:
	/* 0x4795: mov    DWORD PTR [rdi+rcx*1],esi */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4798:
	/* 0x4798: or     eax,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_OR, 4ULL);
x86_l_479b:
	/* 0x479b: test   r13b,0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, 0, 2ULL);
x86_l_479f:
	/* 0x479f: je     4767 <generic_retkprobe_event+0x4767> */
	X86_SIM_X86_JCC(X86_CC_E, 0x479f, 0x4767, x86_l_4767);
x86_l_47a1:
	/* 0x47a1: mov    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_47a3:
	/* 0x47a3: movzx  esi,WORD PTR [rdx+rcx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_16), 0ULL);
x86_l_47a7:
	/* 0x47a7: mov    WORD PTR [rdi+rcx*1],si */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RSI, X86_WIDTH_16, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_47ab:
	/* 0x47ab: add    eax,0x2 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_47ae:
	/* 0x47ae: test   r13b,0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_47b2:
	/* 0x47b2: je     47bd <generic_retkprobe_event+0x47bd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x47b2, 0x47bd, x86_l_47bd);
x86_l_47b4:
	/* 0x47b4: mov    eax,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_47b6:
	/* 0x47b6: movzx  ecx,BYTE PTR [rdx+rax*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_47ba:
	/* 0x47ba: mov    BYTE PTR [rdi+rax*1],cl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_47bd:
	/* 0x47bd: add    r13,r15 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R13, X86_R15, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_47c0:
	/* 0x47c0: jmp    41c4 <generic_retkprobe_event+0x41c4> */
	X86_SIM_X86_JMP(0x47c0, 0x41c4, x86_l_41c4);
x86_l_4843:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
	/* native subroutine native_link_sub_47c5 */
x86_l_47c5:
	/* 0x47c5: mov    rax,rdi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RDI, X86_WIDTH_64, 0, 0);
x86_l_47c8:
	/* 0x47c8: xor    r8d,r8d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_47cb:
	/* 0x47cb: cmp    rdx,0x20 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, 0, 32ULL);
x86_l_47cf:
	/* 0x47cf: jb     47f6 <__native_link_local_memset_zero_dynamic+0x31> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x47cf, 0x47f6, x86_l_47f6);
x86_l_47d5:
	/* 0x47d5: mov    QWORD PTR [rdi],r8 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_47d8:
	/* 0x47d8: mov    QWORD PTR [rdi+0x8],r8 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_47dc:
	/* 0x47dc: mov    QWORD PTR [rdi+0x10],r8 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_47e0:
	/* 0x47e0: mov    QWORD PTR [rdi+0x18],r8 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_47e4:
	/* 0x47e4: add    rdi,0x20 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_47e8:
	/* 0x47e8: sub    rdx,0x20 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SUB, 32ULL);
x86_l_47ec:
	/* 0x47ec: cmp    rdx,0x20 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, 0, 32ULL);
x86_l_47f0:
	/* 0x47f0: jae    47d5 <__native_link_local_memset_zero_dynamic+0x10> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x47f0, 0x47d5, x86_l_47d5);
x86_l_47f6:
	/* 0x47f6: cmp    rdx,0x8 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, 0, 8ULL);
x86_l_47fa:
	/* 0x47fa: jb     4815 <__native_link_local_memset_zero_dynamic+0x50> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x47fa, 0x4815, x86_l_4815);
x86_l_4800:
	/* 0x4800: mov    QWORD PTR [rdi],r8 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4803:
	/* 0x4803: add    rdi,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4807:
	/* 0x4807: sub    rdx,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SUB, 8ULL);
x86_l_480b:
	/* 0x480b: cmp    rdx,0x8 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, 0, 8ULL);
x86_l_480f:
	/* 0x480f: jae    4800 <__native_link_local_memset_zero_dynamic+0x3b> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x480f, 0x4800, x86_l_4800);
x86_l_4815:
	/* 0x4815: test   dl,0x4 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, 0, 4ULL);
x86_l_4818:
	/* 0x4818: je     4825 <__native_link_local_memset_zero_dynamic+0x60> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x4818, 0x4825, x86_l_4825);
x86_l_481e:
	/* 0x481e: mov    DWORD PTR [rdi],r8d */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4821:
	/* 0x4821: add    rdi,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_4825:
	/* 0x4825: test   dl,0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, 0, 2ULL);
x86_l_4828:
	/* 0x4828: je     4836 <__native_link_local_memset_zero_dynamic+0x71> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x4828, 0x4836, x86_l_4836);
x86_l_482e:
	/* 0x482e: mov    WORD PTR [rdi],r8w */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_R8, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4832:
	/* 0x4832: add    rdi,0x2 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_4836:
	/* 0x4836: test   dl,0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_4839:
	/* 0x4839: je     4842 <__native_link_local_memset_zero_dynamic+0x7d> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x4839, 0x4842, x86_l_4842);
x86_l_483f:
	/* 0x483f: mov    BYTE PTR [rdi],r8b */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_R8, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4842:
	/* 0x4842: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_4842);

x86_sim_ret_dispatch_4842:
	switch (__x86_sim_ret_addr) {
	case 0x41dULL: goto x86_l_41d;
	case 0x80cULL: goto x86_l_80c;
	case 0xf2dULL: goto x86_l_f2d;
	case 0x109eULL: goto x86_l_109e;
	case 0x17abULL: goto x86_l_17ab;
	case 0x2650ULL: goto x86_l_2650;
	case 0x2ec6ULL: goto x86_l_2ec6;
	case 0x2fe4ULL: goto x86_l_2fe4;
	case 0x3b30ULL: goto x86_l_3b30;
	case 0x3c79ULL: goto x86_l_3c79;
	default: __x86_sim_unresolved_indirect_target();
	}

}

X86_SIM_LICENSE();
