#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_STACK_BYTES 480U
#define X86_SIM_STACK_VALUE_WORDS(M) M(24) M(25) M(26) M(27) M(28) M(29) M(30) M(31) M(32) M(33) M(35) M(36) M(37) M(38) M(39) M(40) M(41) M(42) M(43) M(45) M(46) M(47) M(48) M(49) M(53)
#include "/workspaces/repository/kprog/x86/x86_sim_local_bpf.h"

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
extern __u8 data_heap[] __ksym;
extern __u8 fdinstall_map[] __ksym;
extern __u8 kprobe_calls[] __ksym;
extern __u8 process_call_heap[] __ksym;
extern __u8 retprobe_map[] __ksym;
extern __u8 socktrack_map[] __ksym;
extern __u8 tcpmon_map[] __ksym;
extern __u8 tg_conf_map[] __ksym;
extern __u8 tg_errmetrics_map[] __ksym;
extern __u8 tg_ipv6_ext_heap[] __ksym;
extern __u8 tg_rb_events[] __ksym;
extern __u8 tg_stats_map[] __ksym;
#include "/workspaces/repository/kprog/x86/x86_sim_inline.h"

X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_ALU_IMM, X86_OP_ALU_IMM)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_ALU_MEM, X86_OP_ALU_MEM)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_ALU_MEM_IMM, X86_OP_ALU_MEM_IMM)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_ALU_MEM_UNARY, X86_OP_ALU_MEM_UNARY)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_ALU_REG, X86_OP_ALU_REG)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_BT, X86_OP_BT)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_BZHI_MEM, X86_OP_BZHI_MEM)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_CALL_HELPER, X86_OP_CALL_HELPER)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_CMOV, X86_OP_CMOV)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_CMP_IMM, X86_OP_CMP_IMM)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_CMP_MEM_IMM, X86_OP_CMP_MEM_IMM)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_CMP_MEM_REG, X86_OP_CMP_MEM_REG)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_CMP_REG, X86_OP_CMP_REG)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_CMP_REG_MEM, X86_OP_CMP_REG_MEM)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_LEA, X86_OP_LEA)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_MOVBE_STORE, X86_OP_MOVBE_STORE)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_MOVSX_LOAD, X86_OP_MOVSX_LOAD)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_MOVSX_REG, X86_OP_MOVSX_REG)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_MOVZX_REG, X86_OP_MOVZX_REG)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_MOV_IMM, X86_OP_MOV_IMM)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_MOV_LOAD, X86_OP_MOV_LOAD)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_MOV_LOAD_MAP_PTR, X86_OP_MOV_LOAD_MAP_PTR)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_MOV_REG, X86_OP_MOV_REG)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_MOV_STORE_IMM, X86_OP_MOV_STORE_IMM)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_MOV_STORE_REG, X86_OP_MOV_STORE_REG)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_NOP, X86_OP_NOP)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_POP, X86_OP_POP)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_PUSH, X86_OP_PUSH)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_RORX, X86_OP_RORX)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_SETCC, X86_OP_SETCC)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_SETCC_MEM, X86_OP_SETCC_MEM)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_SHIFTX, X86_OP_SHIFTX)
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
	/* 0x11: mov    rbp,rdi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RBP, X86_RDI, X86_WIDTH_64, 0, 0);
x86_l_14:
	/* 0x14: mov    DWORD PTR [rsp+0xd8],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 927712935936ULL);
x86_l_1f:
	/* 0x1f: mov    rdi,QWORD PTR [rip+0x200] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)process_call_heap));
x86_l_26:
	/* 0x26: lea    rsi,[rsp+0xd8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_2e:
	/* 0x2e: call   233 <generic_kprobe_process_event+0x233> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_33:
	/* 0x33: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_36:
	/* 0x36: je     42b6 <generic_kprobe_process_event+0x42b6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x36, 0x42b6, x86_l_42b6);
x86_l_3c:
	/* 0x3c: mov    r14,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R14, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_3f:
	/* 0x3f: mov    ebx,DWORD PTR [rax+0x5efc] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24316ULL);
x86_l_45:
	/* 0x45: mov    r12d,DWORD PTR [rax+0x4] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_49:
	/* 0x49: cmp    r12,0x2327 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, 0, 8999ULL);
x86_l_50:
	/* 0x50: ja     670 <generic_kprobe_process_event+0x670> */
	X86_SIM_X86_JCC(X86_CC_A, 0x50, 0x670, x86_l_670);
x86_l_56:
	/* 0x56: mov    DWORD PTR [rsp+0xdc],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 944892805120ULL);
x86_l_61:
	/* 0x61: mov    rdi,QWORD PTR [rip+0x200] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)process_call_heap));
x86_l_68:
	/* 0x68: lea    rsi,[rsp+0xdc] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 220ULL);
x86_l_70:
	/* 0x70: call   275 <generic_kprobe_process_event+0x275> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_75:
	/* 0x75: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_78:
	/* 0x78: je     670 <generic_kprobe_process_event+0x670> */
	X86_SIM_X86_JCC(X86_CC_E, 0x78, 0x670, x86_l_670);
x86_l_7e:
	/* 0x7e: mov    r15,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R15, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_81:
	/* 0x81: lea    rsi,[rax+0x5ef8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24312ULL);
x86_l_88:
	/* 0x88: mov    rdi,QWORD PTR [rip+0x200] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)config_map));
x86_l_8f:
	/* 0x8f: call   294 <generic_kprobe_process_event+0x294> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_94:
	/* 0x94: cmp    ebx,0x4 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_97:
	/* 0x97: jg     670 <generic_kprobe_process_event+0x670> */
	X86_SIM_X86_JCC(X86_CC_G, 0x97, 0x670, x86_l_670);
x86_l_9d:
	/* 0x9d: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_a0:
	/* 0xa0: je     670 <generic_kprobe_process_event+0x670> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa0, 0x670, x86_l_670);
x86_l_a6:
	/* 0xa6: mov    QWORD PTR [rsp+0xb0],r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_ae:
	/* 0xae: mov    esi,ebx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_RBX, X86_WIDTH_32, 0, 0);
x86_l_b0:
	/* 0xb0: and    esi,0x7 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_b3:
	/* 0xb3: mov    ecx,esi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_b5:
	/* 0xb5: mov    r13d,DWORD PTR [rax+rcx*4+0x4] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 4ULL);
x86_l_ba:
	/* 0xba: movsxd r12,DWORD PTR [rax+rcx*4+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOVSX_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_RCX, 2, X86_WIDTH_32), 24ULL);
x86_l_bf:
	/* 0xbf: mov    edx,r12d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R12, X86_WIDTH_32, 0, 0);
x86_l_c2:
	/* 0xc2: mov    QWORD PTR [rsp+0x30],rdx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_c7:
	/* 0xc7: mov    DWORD PTR [r15+rcx*4+0x5ea0],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 104041287778304ULL);
x86_l_d3:
	/* 0xd3: test   r12d,0x100 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 256ULL);
x86_l_da:
	/* 0xda: mov    QWORD PTR [rsp+0x18],rbp */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_df:
	/* 0xdf: mov    QWORD PTR [rsp+0x20],rsi */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_e4:
	/* 0xe4: mov    QWORD PTR [rsp+0x48],rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_e9:
	/* 0xe9: jne    10b <generic_kprobe_process_event+0x10b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xe9, 0x10b, x86_l_10b);
x86_l_eb:
	/* 0xeb: test   r12b,r12b */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_8, 0, 0);
x86_l_ee:
	/* 0xee: js     11c <generic_kprobe_process_event+0x11c> */
	X86_SIM_X86_JCC(X86_CC_S, 0xee, 0x11c, x86_l_11c);
x86_l_f0:
	/* 0xf0: test   BYTE PTR [rsp+0x30],0x40 */
	X86_SIM_RUN_OP(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430272ULL);
x86_l_f5:
	/* 0xf5: jne    14d <generic_kprobe_process_event+0x14d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xf5, 0x14d, x86_l_14d);
x86_l_f7:
	/* 0xf7: mov    ecx,DWORD PTR [rax+rsi*4+0x40] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 64ULL);
x86_l_fb:
	/* 0xfb: and    ecx,0x7 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_fe:
	/* 0xfe: mov    rdx,QWORD PTR [r15+rcx*8+0x5e50] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 3), 24144ULL);
x86_l_106:
	/* 0x106: jmp    1a8 <generic_kprobe_process_event+0x1a8> */
	X86_SIM_X86_JMP(0x106, 0x1a8, x86_l_1a8);
x86_l_10b:
	/* 0x10b: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_114:
	/* 0x114: xor    r15d,r15d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_117:
	/* 0x117: jmp    577 <generic_kprobe_process_event+0x577> */
	X86_SIM_X86_JMP(0x117, 0x577, x86_l_577);
x86_l_11c:
	/* 0x11c: movzx  ecx,BYTE PTR [rax+rsi*4+0x2c2] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 2, X86_WIDTH_8), 706ULL);
x86_l_124:
	/* 0x124: shl    cl,0x3 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_127:
	/* 0x127: mov    bl,0x40 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, 0, 64ULL);
x86_l_129:
	/* 0x129: sub    bl,cl */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RBX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB, 0);
x86_l_12b:
	/* 0x12b: cmp    DWORD PTR [rax+0x54],0x0 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360777252864ULL);
x86_l_12f:
	/* 0x12f: movzx  ecx,WORD PTR [rax+rsi*4+0x2c0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 2, X86_WIDTH_16), 704ULL);
x86_l_137:
	/* 0x137: je     157 <generic_kprobe_process_event+0x157> */
	X86_SIM_X86_JCC(X86_CC_E, 0x137, 0x157, x86_l_157);
x86_l_139:
	/* 0x139: test   rbp,rbp */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_13c:
	/* 0x13c: je     174 <generic_kprobe_process_event+0x174> */
	X86_SIM_X86_JCC(X86_CC_E, 0x13c, 0x174, x86_l_174);
x86_l_13e:
	/* 0x13e: add    rcx,rbp */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_141:
	/* 0x141: jns    178 <generic_kprobe_process_event+0x178> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x141, 0x178, x86_l_178);
x86_l_143:
	/* 0x143: test   rcx,rcx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_146:
	/* 0x146: jns    19c <generic_kprobe_process_event+0x19c> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x146, 0x19c, x86_l_19c);
x86_l_148:
	/* 0x148: mov    rcx,QWORD PTR [rcx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14b:
	/* 0x14b: jmp    19e <generic_kprobe_process_event+0x19e> */
	X86_SIM_X86_JMP(0x14b, 0x19e, x86_l_19e);
x86_l_14d:
	/* 0x14d: mov    rbx,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RBX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_150:
	/* 0x150: call   355 <generic_kprobe_process_event+0x355> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_get_current_task);
x86_l_155:
	/* 0x155: jmp    167 <generic_kprobe_process_event+0x167> */
	X86_SIM_X86_JMP(0x155, 0x167, x86_l_167);
x86_l_157:
	/* 0x157: movzx  edx,bl */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_RDX, X86_RBX, X86_WIDTH_32, X86_WIDTH_8, 0);
x86_l_15a:
	/* 0x15a: mov    rdi,rbp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_15d:
	/* 0x15d: mov    esi,ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_15f:
	/* 0x15f: mov    rbx,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RBX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_162:
	/* 0x162: call   0 <generic_kprobe_process_event> */
	X86_SIM_X86_CALL(x86_l_4ab4, 0x167ULL);
x86_l_167:
	/* 0x167: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_16c:
	/* 0x16c: mov    rdx,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_16f:
	/* 0x16f: mov    rax,rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_172:
	/* 0x172: jmp    1a8 <generic_kprobe_process_event+0x1a8> */
	X86_SIM_X86_JMP(0x172, 0x1a8, x86_l_1a8);
x86_l_174:
	/* 0x174: xor    edx,edx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_176:
	/* 0x176: jmp    1a8 <generic_kprobe_process_event+0x1a8> */
	X86_SIM_X86_JMP(0x176, 0x1a8, x86_l_1a8);
x86_l_178:
	/* 0x178: lea    rdi,[rsp+0x70] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_17d:
	/* 0x17d: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_182:
	/* 0x182: mov    rdx,rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_185:
	/* 0x185: mov    rbp,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RBP, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_188:
	/* 0x188: call   38d <generic_kprobe_process_event+0x38d> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_18d:
	/* 0x18d: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_192:
	/* 0x192: mov    rax,rbp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_195:
	/* 0x195: mov    rcx,QWORD PTR [rsp+0x70] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_19a:
	/* 0x19a: jmp    19e <generic_kprobe_process_event+0x19e> */
	X86_SIM_X86_JMP(0x19a, 0x19e, x86_l_19e);
x86_l_19c:
	/* 0x19c: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_19e:
	/* 0x19e: shlx   rcx,rcx,rbx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RCX, X86_RCX, X86_WIDTH_64, X86_RBX, X86_ALU_SHL);
x86_l_1a3:
	/* 0x1a3: sarx   rdx,rcx,rbx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RCX, X86_WIDTH_64, X86_RBX, X86_ALU_SAR);
x86_l_1a8:
	/* 0x1a8: mov    QWORD PTR [rsp+0x38],rdx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1ad:
	/* 0x1ad: cmp    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_1b0:
	/* 0x1b0: ja     572 <generic_kprobe_process_event+0x572> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1b0, 0x572, x86_l_572);
x86_l_1b6:
	/* 0x1b6: lea    rcx,[rsi+rsi*4] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_1ba:
	/* 0x1ba: shl    ecx,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 4ULL);
x86_l_1bd:
	/* 0x1bd: cmp    WORD PTR [rax+rcx*1+0x76],0x0 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RCX, 0), 506806140928ULL);
x86_l_1c3:
	/* 0x1c3: je     572 <generic_kprobe_process_event+0x572> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1c3, 0x572, x86_l_572);
x86_l_1c9:
	/* 0x1c9: lea    rbp,[rax+rcx*1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1cd:
	/* 0x1cd: add    rbp,0x70 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 112ULL);
x86_l_1d1:
	/* 0x1d1: mov    eax,DWORD PTR [rbp+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d4:
	/* 0x1d4: add    rdx,rax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1d7:
	/* 0x1d7: mov    QWORD PTR [rsp+0x38],rdx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1dc:
	/* 0x1dc: cmp    WORD PTR [rbp+0x4],0x0 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_1e1:
	/* 0x1e1: je     21a <generic_kprobe_process_event+0x21a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1e1, 0x21a, x86_l_21a);
x86_l_1e3:
	/* 0x1e3: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_1e6:
	/* 0x1e6: js     207 <generic_kprobe_process_event+0x207> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1e6, 0x207, x86_l_207);
x86_l_1e8:
	/* 0x1e8: lea    rdi,[rsp+0x38] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1ed:
	/* 0x1ed: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_1f2:
	/* 0x1f2: call   3f7 <generic_kprobe_process_event+0x3f7> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_1f7:
	/* 0x1f7: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1fc:
	/* 0x1fc: xor    ebx,ebx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1fe:
	/* 0x1fe: test   eax,eax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_200:
	/* 0x200: jns    21a <generic_kprobe_process_event+0x21a> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x200, 0x21a, x86_l_21a);
x86_l_202:
	/* 0x202: jmp    568 <generic_kprobe_process_event+0x568> */
	X86_SIM_X86_JMP(0x202, 0x568, x86_l_568);
x86_l_207:
	/* 0x207: xor    ebx,ebx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_209:
	/* 0x209: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_20c:
	/* 0x20c: jns    55f <generic_kprobe_process_event+0x55f> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x20c, 0x55f, x86_l_55f);
x86_l_212:
	/* 0x212: mov    rax,QWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_215:
	/* 0x215: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_21a:
	/* 0x21a: cmp    WORD PTR [rbp+0xe],0x0 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 60129542144ULL);
x86_l_21f:
	/* 0x21f: je     572 <generic_kprobe_process_event+0x572> */
	X86_SIM_X86_JCC(X86_CC_E, 0x21f, 0x572, x86_l_572);
x86_l_225:
	/* 0x225: mov    edx,DWORD PTR [rbp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_228:
	/* 0x228: add    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_RUN_OP(X86_OP_ALU_MEM, X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 56ULL);
x86_l_22d:
	/* 0x22d: mov    QWORD PTR [rsp+0x38],rdx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_232:
	/* 0x232: cmp    WORD PTR [rbp+0xc],0x0 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_237:
	/* 0x237: je     276 <generic_kprobe_process_event+0x276> */
	X86_SIM_X86_JCC(X86_CC_E, 0x237, 0x276, x86_l_276);
x86_l_239:
	/* 0x239: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_23c:
	/* 0x23c: js     260 <generic_kprobe_process_event+0x260> */
	X86_SIM_X86_JCC(X86_CC_S, 0x23c, 0x260, x86_l_260);
x86_l_23e:
	/* 0x23e: lea    rdi,[rsp+0x38] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_243:
	/* 0x243: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_248:
	/* 0x248: call   44d <generic_kprobe_process_event+0x44d> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_24d:
	/* 0x24d: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_252:
	/* 0x252: mov    ebx,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_257:
	/* 0x257: test   eax,eax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_259:
	/* 0x259: jns    276 <generic_kprobe_process_event+0x276> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x259, 0x276, x86_l_276);
x86_l_25b:
	/* 0x25b: jmp    568 <generic_kprobe_process_event+0x568> */
	X86_SIM_X86_JMP(0x25b, 0x568, x86_l_568);
x86_l_260:
	/* 0x260: mov    ebx,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_265:
	/* 0x265: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_268:
	/* 0x268: jns    55f <generic_kprobe_process_event+0x55f> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x268, 0x55f, x86_l_55f);
x86_l_26e:
	/* 0x26e: mov    rax,QWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_271:
	/* 0x271: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_276:
	/* 0x276: cmp    WORD PTR [rbp+0x16],0x0 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 94489280512ULL);
x86_l_27b:
	/* 0x27b: je     572 <generic_kprobe_process_event+0x572> */
	X86_SIM_X86_JCC(X86_CC_E, 0x27b, 0x572, x86_l_572);
x86_l_281:
	/* 0x281: mov    edx,DWORD PTR [rbp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_284:
	/* 0x284: add    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_RUN_OP(X86_OP_ALU_MEM, X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 56ULL);
x86_l_289:
	/* 0x289: mov    QWORD PTR [rsp+0x38],rdx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_28e:
	/* 0x28e: cmp    WORD PTR [rbp+0x14],0x0 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_293:
	/* 0x293: je     2d2 <generic_kprobe_process_event+0x2d2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x293, 0x2d2, x86_l_2d2);
x86_l_295:
	/* 0x295: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_298:
	/* 0x298: js     2bc <generic_kprobe_process_event+0x2bc> */
	X86_SIM_X86_JCC(X86_CC_S, 0x298, 0x2bc, x86_l_2bc);
x86_l_29a:
	/* 0x29a: lea    rdi,[rsp+0x38] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_29f:
	/* 0x29f: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_2a4:
	/* 0x2a4: call   4a9 <generic_kprobe_process_event+0x4a9> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_2a9:
	/* 0x2a9: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2ae:
	/* 0x2ae: mov    ebx,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_2b3:
	/* 0x2b3: test   eax,eax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_2b5:
	/* 0x2b5: jns    2d2 <generic_kprobe_process_event+0x2d2> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2b5, 0x2d2, x86_l_2d2);
x86_l_2b7:
	/* 0x2b7: jmp    568 <generic_kprobe_process_event+0x568> */
	X86_SIM_X86_JMP(0x2b7, 0x568, x86_l_568);
x86_l_2bc:
	/* 0x2bc: mov    ebx,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_2c1:
	/* 0x2c1: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_2c4:
	/* 0x2c4: jns    55f <generic_kprobe_process_event+0x55f> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2c4, 0x55f, x86_l_55f);
x86_l_2ca:
	/* 0x2ca: mov    rax,QWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2cd:
	/* 0x2cd: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2d2:
	/* 0x2d2: cmp    WORD PTR [rbp+0x1e],0x0 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 128849018880ULL);
x86_l_2d7:
	/* 0x2d7: je     572 <generic_kprobe_process_event+0x572> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2d7, 0x572, x86_l_572);
x86_l_2dd:
	/* 0x2dd: mov    edx,DWORD PTR [rbp+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2e0:
	/* 0x2e0: add    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_RUN_OP(X86_OP_ALU_MEM, X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 56ULL);
x86_l_2e5:
	/* 0x2e5: mov    QWORD PTR [rsp+0x38],rdx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2ea:
	/* 0x2ea: cmp    WORD PTR [rbp+0x1c],0x0 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 120259084288ULL);
x86_l_2ef:
	/* 0x2ef: je     32e <generic_kprobe_process_event+0x32e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2ef, 0x32e, x86_l_32e);
x86_l_2f1:
	/* 0x2f1: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_2f4:
	/* 0x2f4: js     318 <generic_kprobe_process_event+0x318> */
	X86_SIM_X86_JCC(X86_CC_S, 0x2f4, 0x318, x86_l_318);
x86_l_2f6:
	/* 0x2f6: lea    rdi,[rsp+0x38] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2fb:
	/* 0x2fb: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_300:
	/* 0x300: call   505 <generic_kprobe_process_event+0x505> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_305:
	/* 0x305: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_30a:
	/* 0x30a: mov    ebx,0x3 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 3ULL);
x86_l_30f:
	/* 0x30f: test   eax,eax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_311:
	/* 0x311: jns    32e <generic_kprobe_process_event+0x32e> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x311, 0x32e, x86_l_32e);
x86_l_313:
	/* 0x313: jmp    568 <generic_kprobe_process_event+0x568> */
	X86_SIM_X86_JMP(0x313, 0x568, x86_l_568);
x86_l_318:
	/* 0x318: mov    ebx,0x3 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 3ULL);
x86_l_31d:
	/* 0x31d: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_320:
	/* 0x320: jns    55f <generic_kprobe_process_event+0x55f> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x320, 0x55f, x86_l_55f);
x86_l_326:
	/* 0x326: mov    rax,QWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_329:
	/* 0x329: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_32e:
	/* 0x32e: cmp    WORD PTR [rbp+0x26],0x0 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 163208757248ULL);
x86_l_333:
	/* 0x333: je     572 <generic_kprobe_process_event+0x572> */
	X86_SIM_X86_JCC(X86_CC_E, 0x333, 0x572, x86_l_572);
x86_l_339:
	/* 0x339: mov    edx,DWORD PTR [rbp+0x20] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_33c:
	/* 0x33c: add    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_RUN_OP(X86_OP_ALU_MEM, X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 56ULL);
x86_l_341:
	/* 0x341: mov    QWORD PTR [rsp+0x38],rdx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_346:
	/* 0x346: cmp    WORD PTR [rbp+0x24],0x0 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 154618822656ULL);
x86_l_34b:
	/* 0x34b: je     38a <generic_kprobe_process_event+0x38a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x34b, 0x38a, x86_l_38a);
x86_l_34d:
	/* 0x34d: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_350:
	/* 0x350: js     374 <generic_kprobe_process_event+0x374> */
	X86_SIM_X86_JCC(X86_CC_S, 0x350, 0x374, x86_l_374);
x86_l_352:
	/* 0x352: lea    rdi,[rsp+0x38] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_357:
	/* 0x357: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_35c:
	/* 0x35c: call   561 <generic_kprobe_process_event+0x561> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_361:
	/* 0x361: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_366:
	/* 0x366: mov    ebx,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_36b:
	/* 0x36b: test   eax,eax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_36d:
	/* 0x36d: jns    38a <generic_kprobe_process_event+0x38a> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x36d, 0x38a, x86_l_38a);
x86_l_36f:
	/* 0x36f: jmp    568 <generic_kprobe_process_event+0x568> */
	X86_SIM_X86_JMP(0x36f, 0x568, x86_l_568);
x86_l_374:
	/* 0x374: mov    ebx,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_379:
	/* 0x379: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_37c:
	/* 0x37c: jns    55f <generic_kprobe_process_event+0x55f> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x37c, 0x55f, x86_l_55f);
x86_l_382:
	/* 0x382: mov    rax,QWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_385:
	/* 0x385: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_38a:
	/* 0x38a: cmp    WORD PTR [rbp+0x2e],0x0 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 197568495616ULL);
x86_l_38f:
	/* 0x38f: je     572 <generic_kprobe_process_event+0x572> */
	X86_SIM_X86_JCC(X86_CC_E, 0x38f, 0x572, x86_l_572);
x86_l_395:
	/* 0x395: mov    edx,DWORD PTR [rbp+0x28] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_398:
	/* 0x398: add    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_RUN_OP(X86_OP_ALU_MEM, X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 56ULL);
x86_l_39d:
	/* 0x39d: mov    QWORD PTR [rsp+0x38],rdx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3a2:
	/* 0x3a2: cmp    WORD PTR [rbp+0x2c],0x0 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 188978561024ULL);
x86_l_3a7:
	/* 0x3a7: je     3eb <generic_kprobe_process_event+0x3eb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3a7, 0x3eb, x86_l_3eb);
x86_l_3a9:
	/* 0x3a9: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_3ac:
	/* 0x3ac: js     3d0 <generic_kprobe_process_event+0x3d0> */
	X86_SIM_X86_JCC(X86_CC_S, 0x3ac, 0x3d0, x86_l_3d0);
x86_l_3ae:
	/* 0x3ae: lea    rdi,[rsp+0x38] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3b3:
	/* 0x3b3: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_3b8:
	/* 0x3b8: call   5bd <generic_kprobe_process_event+0x5bd> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_3bd:
	/* 0x3bd: mov    ebx,0x5 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 5ULL);
x86_l_3c2:
	/* 0x3c2: test   eax,eax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_3c4:
	/* 0x3c4: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3c9:
	/* 0x3c9: jns    3eb <generic_kprobe_process_event+0x3eb> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x3c9, 0x3eb, x86_l_3eb);
x86_l_3cb:
	/* 0x3cb: jmp    568 <generic_kprobe_process_event+0x568> */
	X86_SIM_X86_JMP(0x3cb, 0x568, x86_l_568);
x86_l_3d0:
	/* 0x3d0: mov    ebx,0x5 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 5ULL);
x86_l_3d5:
	/* 0x3d5: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_3d8:
	/* 0x3d8: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3dd:
	/* 0x3dd: jns    55f <generic_kprobe_process_event+0x55f> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x3dd, 0x55f, x86_l_55f);
x86_l_3e3:
	/* 0x3e3: mov    rax,QWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3e6:
	/* 0x3e6: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3eb:
	/* 0x3eb: cmp    WORD PTR [rbp+0x36],0x0 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 231928233984ULL);
x86_l_3f0:
	/* 0x3f0: je     572 <generic_kprobe_process_event+0x572> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3f0, 0x572, x86_l_572);
x86_l_3f6:
	/* 0x3f6: mov    edx,DWORD PTR [rbp+0x30] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3f9:
	/* 0x3f9: add    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_RUN_OP(X86_OP_ALU_MEM, X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 56ULL);
x86_l_3fe:
	/* 0x3fe: mov    QWORD PTR [rsp+0x38],rdx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_403:
	/* 0x403: cmp    WORD PTR [rbp+0x34],0x0 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 223338299392ULL);
x86_l_408:
	/* 0x408: je     44c <generic_kprobe_process_event+0x44c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x408, 0x44c, x86_l_44c);
x86_l_40a:
	/* 0x40a: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_40d:
	/* 0x40d: js     431 <generic_kprobe_process_event+0x431> */
	X86_SIM_X86_JCC(X86_CC_S, 0x40d, 0x431, x86_l_431);
x86_l_40f:
	/* 0x40f: lea    rdi,[rsp+0x38] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_414:
	/* 0x414: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_419:
	/* 0x419: call   61e <generic_kprobe_process_event+0x61e> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_41e:
	/* 0x41e: mov    ebx,0x6 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 6ULL);
x86_l_423:
	/* 0x423: test   eax,eax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_425:
	/* 0x425: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_42a:
	/* 0x42a: jns    44c <generic_kprobe_process_event+0x44c> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x42a, 0x44c, x86_l_44c);
x86_l_42c:
	/* 0x42c: jmp    568 <generic_kprobe_process_event+0x568> */
	X86_SIM_X86_JMP(0x42c, 0x568, x86_l_568);
x86_l_431:
	/* 0x431: mov    ebx,0x6 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 6ULL);
x86_l_436:
	/* 0x436: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_439:
	/* 0x439: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_43e:
	/* 0x43e: jns    55f <generic_kprobe_process_event+0x55f> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x43e, 0x55f, x86_l_55f);
x86_l_444:
	/* 0x444: mov    rax,QWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_447:
	/* 0x447: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_44c:
	/* 0x44c: cmp    WORD PTR [rbp+0x3e],0x0 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 266287972352ULL);
x86_l_451:
	/* 0x451: je     572 <generic_kprobe_process_event+0x572> */
	X86_SIM_X86_JCC(X86_CC_E, 0x451, 0x572, x86_l_572);
x86_l_457:
	/* 0x457: mov    edx,DWORD PTR [rbp+0x38] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_45a:
	/* 0x45a: add    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_RUN_OP(X86_OP_ALU_MEM, X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 56ULL);
x86_l_45f:
	/* 0x45f: mov    QWORD PTR [rsp+0x38],rdx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_464:
	/* 0x464: cmp    WORD PTR [rbp+0x3c],0x0 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_469:
	/* 0x469: je     4ad <generic_kprobe_process_event+0x4ad> */
	X86_SIM_X86_JCC(X86_CC_E, 0x469, 0x4ad, x86_l_4ad);
x86_l_46b:
	/* 0x46b: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_46e:
	/* 0x46e: js     492 <generic_kprobe_process_event+0x492> */
	X86_SIM_X86_JCC(X86_CC_S, 0x46e, 0x492, x86_l_492);
x86_l_470:
	/* 0x470: lea    rdi,[rsp+0x38] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_475:
	/* 0x475: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_47a:
	/* 0x47a: call   67f <generic_kprobe_process_event+0x67f> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_47f:
	/* 0x47f: mov    ebx,0x7 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 7ULL);
x86_l_484:
	/* 0x484: test   eax,eax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_486:
	/* 0x486: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_48b:
	/* 0x48b: jns    4ad <generic_kprobe_process_event+0x4ad> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x48b, 0x4ad, x86_l_4ad);
x86_l_48d:
	/* 0x48d: jmp    568 <generic_kprobe_process_event+0x568> */
	X86_SIM_X86_JMP(0x48d, 0x568, x86_l_568);
x86_l_492:
	/* 0x492: mov    ebx,0x7 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 7ULL);
x86_l_497:
	/* 0x497: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_49a:
	/* 0x49a: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_49f:
	/* 0x49f: jns    55f <generic_kprobe_process_event+0x55f> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x49f, 0x55f, x86_l_55f);
x86_l_4a5:
	/* 0x4a5: mov    rax,QWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4a8:
	/* 0x4a8: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_4ad:
	/* 0x4ad: cmp    WORD PTR [rbp+0x46],0x0 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 300647710720ULL);
x86_l_4b2:
	/* 0x4b2: je     572 <generic_kprobe_process_event+0x572> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4b2, 0x572, x86_l_572);
x86_l_4b8:
	/* 0x4b8: mov    edx,DWORD PTR [rbp+0x40] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_4bb:
	/* 0x4bb: add    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_RUN_OP(X86_OP_ALU_MEM, X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 56ULL);
x86_l_4c0:
	/* 0x4c0: mov    QWORD PTR [rsp+0x38],rdx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_4c5:
	/* 0x4c5: cmp    WORD PTR [rbp+0x44],0x0 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 292057776128ULL);
x86_l_4ca:
	/* 0x4ca: je     507 <generic_kprobe_process_event+0x507> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4ca, 0x507, x86_l_507);
x86_l_4cc:
	/* 0x4cc: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_4cf:
	/* 0x4cf: js     4f0 <generic_kprobe_process_event+0x4f0> */
	X86_SIM_X86_JCC(X86_CC_S, 0x4cf, 0x4f0, x86_l_4f0);
x86_l_4d1:
	/* 0x4d1: lea    rdi,[rsp+0x38] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_4d6:
	/* 0x4d6: mov    ebx,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_4db:
	/* 0x4db: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_4e0:
	/* 0x4e0: call   6e5 <generic_kprobe_process_event+0x6e5> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_4e5:
	/* 0x4e5: test   eax,eax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_4e7:
	/* 0x4e7: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4ec:
	/* 0x4ec: jns    507 <generic_kprobe_process_event+0x507> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x4ec, 0x507, x86_l_507);
x86_l_4ee:
	/* 0x4ee: jmp    568 <generic_kprobe_process_event+0x568> */
	X86_SIM_X86_JMP(0x4ee, 0x568, x86_l_568);
x86_l_4f0:
	/* 0x4f0: mov    ebx,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_4f5:
	/* 0x4f5: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_4f8:
	/* 0x4f8: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4fd:
	/* 0x4fd: jns    55f <generic_kprobe_process_event+0x55f> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x4fd, 0x55f, x86_l_55f);
x86_l_4ff:
	/* 0x4ff: mov    rax,QWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_502:
	/* 0x502: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_507:
	/* 0x507: cmp    WORD PTR [rbp+0x4e],0x0 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 335007449088ULL);
x86_l_50c:
	/* 0x50c: je     572 <generic_kprobe_process_event+0x572> */
	X86_SIM_X86_JCC(X86_CC_E, 0x50c, 0x572, x86_l_572);
x86_l_50e:
	/* 0x50e: mov    edx,DWORD PTR [rbp+0x48] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_511:
	/* 0x511: add    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_RUN_OP(X86_OP_ALU_MEM, X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 56ULL);
x86_l_516:
	/* 0x516: mov    QWORD PTR [rsp+0x38],rdx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_51b:
	/* 0x51b: cmp    WORD PTR [rbp+0x4c],0x0 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 326417514496ULL);
x86_l_520:
	/* 0x520: je     572 <generic_kprobe_process_event+0x572> */
	X86_SIM_X86_JCC(X86_CC_E, 0x520, 0x572, x86_l_572);
x86_l_522:
	/* 0x522: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_525:
	/* 0x525: js     546 <generic_kprobe_process_event+0x546> */
	X86_SIM_X86_JCC(X86_CC_S, 0x525, 0x546, x86_l_546);
x86_l_527:
	/* 0x527: lea    rdi,[rsp+0x38] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_52c:
	/* 0x52c: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_531:
	/* 0x531: call   736 <generic_kprobe_process_event+0x736> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_536:
	/* 0x536: mov    ebx,0x9 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 9ULL);
x86_l_53b:
	/* 0x53b: test   eax,eax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_53d:
	/* 0x53d: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_542:
	/* 0x542: js     568 <generic_kprobe_process_event+0x568> */
	X86_SIM_X86_JCC(X86_CC_S, 0x542, 0x568, x86_l_568);
x86_l_544:
	/* 0x544: jmp    572 <generic_kprobe_process_event+0x572> */
	X86_SIM_X86_JMP(0x544, 0x572, x86_l_572);
x86_l_546:
	/* 0x546: mov    ebx,0x9 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 9ULL);
x86_l_54b:
	/* 0x54b: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_54e:
	/* 0x54e: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_553:
	/* 0x553: jns    55f <generic_kprobe_process_event+0x55f> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x553, 0x55f, x86_l_55f);
x86_l_555:
	/* 0x555: mov    rax,QWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_558:
	/* 0x558: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_55d:
	/* 0x55d: jmp    572 <generic_kprobe_process_event+0x572> */
	X86_SIM_X86_JMP(0x55d, 0x572, x86_l_572);
x86_l_55f:
	/* 0x55f: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_568:
	/* 0x568: inc    ebx */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_56a:
	/* 0x56a: mov    DWORD PTR [r15+rsi*4+0x5ea0],ebx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 24224ULL);
x86_l_572:
	/* 0x572: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_577:
	/* 0x577: lea    ebp,[r13-0x1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RBP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_57b:
	/* 0x57b: cmp    ebp,0x2b */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, 0, 43ULL);
x86_l_57e:
	/* 0x57e: ja     5db <generic_kprobe_process_event+0x5db> */
	X86_SIM_X86_JCC(X86_CC_A, 0x57e, 0x5db, x86_l_5db);
x86_l_580:
	/* Capture image-bound code identity before scheduled instructions. */
	switch (X86_SIM_L_READ_REG(X86_RBP) << 2) {
	case 0ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x590ULL); break;
	case 4ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x590ULL); break;
	case 8ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x590ULL); break;
	case 12ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x597ULL); break;
	case 16ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x5a5ULL); break;
	case 20ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x59eULL); break;
	case 24ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x5a5ULL); break;
	case 28ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x5b3ULL); break;
	case 32ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x5dbULL); break;
	case 36ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x597ULL); break;
	case 40ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x597ULL); break;
	case 44ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x590ULL); break;
	case 48ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x590ULL); break;
	case 52ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x5dbULL); break;
	case 56ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x59eULL); break;
	case 60ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x59eULL); break;
	case 64ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x59eULL); break;
	case 68ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x5d6ULL); break;
	case 72ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x5acULL); break;
	case 76ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x5c1ULL); break;
	case 80ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x5c8ULL); break;
	case 84ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x5baULL); break;
	case 88ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x597ULL); break;
	case 92ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x5dbULL); break;
	case 96ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x5dbULL); break;
	case 100ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x5b3ULL); break;
	case 104ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x5b3ULL); break;
	case 108ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x5dbULL); break;
	case 112ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x590ULL); break;
	case 116ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x590ULL); break;
	case 120ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x590ULL); break;
	case 124ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x590ULL); break;
	case 128ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x597ULL); break;
	case 132ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x597ULL); break;
	case 136ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x597ULL); break;
	case 140ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x597ULL); break;
	case 144ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x59eULL); break;
	case 148ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x5dbULL); break;
	case 152ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x5baULL); break;
	case 156ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x5acULL); break;
	case 160ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x5a5ULL); break;
	case 164ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x59eULL); break;
	case 168ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x5acULL); break;
	case 172ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x5cfULL); break;
	default: __x86_sim_unresolved_indirect_target();
	}
x86_l_58e:
	/* 0x58e: jmp    rcx */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RCX);
		switch (X86_SIM_L_REG_TAG(X86_RCX)) {
		case X86_SIM_TAG_CODE:
			switch (__x86_target) {
			case 0x590ULL: goto x86_l_590;
			case 0x597ULL: goto x86_l_597;
			case 0x59eULL: goto x86_l_59e;
			case 0x5a5ULL: goto x86_l_5a5;
			case 0x5acULL: goto x86_l_5ac;
			case 0x5b3ULL: goto x86_l_5b3;
			case 0x5baULL: goto x86_l_5ba;
			case 0x5c1ULL: goto x86_l_5c1;
			case 0x5c8ULL: goto x86_l_5c8;
			case 0x5cfULL: goto x86_l_5cf;
			case 0x5d6ULL: goto x86_l_5d6;
			case 0x5dbULL: goto x86_l_5db;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_590:
	/* 0x590: mov    ebx,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_595:
	/* 0x595: jmp    5dd <generic_kprobe_process_event+0x5dd> */
	X86_SIM_X86_JMP(0x595, 0x5dd, x86_l_5dd);
x86_l_597:
	/* 0x597: mov    ebx,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_59c:
	/* 0x59c: jmp    5dd <generic_kprobe_process_event+0x5dd> */
	X86_SIM_X86_JMP(0x59c, 0x5dd, x86_l_5dd);
x86_l_59e:
	/* 0x59e: mov    ebx,0x1000 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 4096ULL);
x86_l_5a3:
	/* 0x5a3: jmp    5dd <generic_kprobe_process_event+0x5dd> */
	X86_SIM_X86_JMP(0x5a3, 0x5dd, x86_l_5dd);
x86_l_5a5:
	/* 0x5a5: mov    ebx,0x40 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 64ULL);
x86_l_5aa:
	/* 0x5aa: jmp    5dd <generic_kprobe_process_event+0x5dd> */
	X86_SIM_X86_JMP(0x5aa, 0x5dd, x86_l_5dd);
x86_l_5ac:
	/* 0x5ac: mov    ebx,0x18 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 24ULL);
x86_l_5b1:
	/* 0x5b1: jmp    5dd <generic_kprobe_process_event+0x5dd> */
	X86_SIM_X86_JMP(0x5b1, 0x5dd, x86_l_5dd);
x86_l_5b3:
	/* 0x5b3: mov    ebx,0x50 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 80ULL);
x86_l_5b8:
	/* 0x5b8: jmp    5dd <generic_kprobe_process_event+0x5dd> */
	X86_SIM_X86_JMP(0x5b8, 0x5dd, x86_l_5dd);
x86_l_5ba:
	/* 0x5ba: mov    ebx,0x10 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 16ULL);
x86_l_5bf:
	/* 0x5bf: jmp    5dd <generic_kprobe_process_event+0x5dd> */
	X86_SIM_X86_JMP(0x5bf, 0x5dd, x86_l_5dd);
x86_l_5c1:
	/* 0x5c1: mov    ebx,0x98 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 152ULL);
x86_l_5c6:
	/* 0x5c6: jmp    5dd <generic_kprobe_process_event+0x5dd> */
	X86_SIM_X86_JMP(0x5c6, 0x5dd, x86_l_5dd);
x86_l_5c8:
	/* 0x5c8: mov    ebx,0x20 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 32ULL);
x86_l_5cd:
	/* 0x5cd: jmp    5dd <generic_kprobe_process_event+0x5dd> */
	X86_SIM_X86_JMP(0x5cd, 0x5dd, x86_l_5dd);
x86_l_5cf:
	/* 0x5cf: mov    ebx,0x70 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 112ULL);
x86_l_5d4:
	/* 0x5d4: jmp    5dd <generic_kprobe_process_event+0x5dd> */
	X86_SIM_X86_JMP(0x5d4, 0x5dd, x86_l_5dd);
x86_l_5d6:
	/* 0x5d6: mov    rbx,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RBX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_5d9:
	/* 0x5d9: jmp    5dd <generic_kprobe_process_event+0x5dd> */
	X86_SIM_X86_JMP(0x5d9, 0x5dd, x86_l_5dd);
x86_l_5db:
	/* 0x5db: xor    ebx,ebx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_5dd:
	/* 0x5dd: mov    DWORD PTR [rsp+0xe0],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 962072674304ULL);
x86_l_5e8:
	/* 0x5e8: mov    rdi,QWORD PTR [rip+0x200] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)process_call_heap));
x86_l_5ef:
	/* 0x5ef: lea    rsi,[rsp+0xe0] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_5f7:
	/* 0x5f7: call   7fc <generic_kprobe_process_event+0x7fc> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_5fc:
	/* 0x5fc: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_5ff:
	/* 0x5ff: je     65e <generic_kprobe_process_event+0x65e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5ff, 0x65e, x86_l_65e);
x86_l_601:
	/* 0x601: mov    ecx,0x3ffb */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 16379ULL);
x86_l_606:
	/* 0x606: sub    rcx,rbx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RBX, X86_WIDTH_64, X86_ALU_SUB, 0);
x86_l_609:
	/* 0x609: cmp    rcx,QWORD PTR [rsp+0xb0] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 176ULL);
x86_l_611:
	/* 0x611: jbe    65e <generic_kprobe_process_event+0x65e> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x611, 0x65e, x86_l_65e);
x86_l_613:
	/* 0x613: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_618:
	/* 0x618: mov    ecx,DWORD PTR [rax+rsi*4+0x5ea0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 24224ULL);
x86_l_61f:
	/* 0x61f: mov    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_627:
	/* 0x627: mov    DWORD PTR [rax+rdx*1+0x90],ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 144ULL);
x86_l_62e:
	/* 0x62e: lea    rdi,[rdx+0x4] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_632:
	/* 0x632: mov    QWORD PTR [rax+rsi*8+0x5e78],rdi */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 3), 24184ULL);
x86_l_63a:
	/* 0x63a: mov    edx,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_63f:
	/* 0x63f: test   ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_641:
	/* 0x641: je     6ef <generic_kprobe_process_event+0x6ef> */
	X86_SIM_X86_JCC(X86_CC_E, 0x641, 0x6ef, x86_l_6ef);
x86_l_647:
	/* 0x647: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_64c:
	/* 0x64c: mov    rbx,QWORD PTR [rsp+0x48] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_651:
	/* 0x651: mov    r12,QWORD PTR [rsp+0xb0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_659:
	/* 0x659: jmp    4284 <generic_kprobe_process_event+0x4284> */
	X86_SIM_X86_JMP(0x659, 0x4284, x86_l_4284);
x86_l_65e:
	/* 0x65e: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_663:
	/* 0x663: mov    rbx,QWORD PTR [rsp+0x48] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_668:
	/* 0x668: mov    r12,QWORD PTR [rsp+0xb0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_670:
	/* 0x670: mov    DWORD PTR [r14+0x4],r12d */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_R14, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_674:
	/* 0x674: cmp    ebx,0x3 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 3ULL);
x86_l_677:
	/* 0x677: jg     4297 <generic_kprobe_process_event+0x4297> */
	X86_SIM_X86_JCC(X86_CC_G, 0x677, 0x4297, x86_l_4297);
x86_l_67d:
	/* 0x67d: mov    DWORD PTR [rsp+0x70],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_685:
	/* 0x685: mov    rdi,QWORD PTR [rip+0x200] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)process_call_heap));
x86_l_68c:
	/* 0x68c: lea    rsi,[rsp+0x70] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_691:
	/* 0x691: call   896 <generic_kprobe_process_event+0x896> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_696:
	/* 0x696: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_699:
	/* 0x699: je     4297 <generic_kprobe_process_event+0x4297> */
	X86_SIM_X86_JCC(X86_CC_E, 0x699, 0x4297, x86_l_4297);
x86_l_69f:
	/* 0x69f: add    rax,0x5ef8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 24312ULL);
x86_l_6a5:
	/* 0x6a5: mov    rdi,QWORD PTR [rip+0x200] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)config_map));
x86_l_6ac:
	/* 0x6ac: mov    rsi,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_6af:
	/* 0x6af: call   8b4 <generic_kprobe_process_event+0x8b4> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_6b4:
	/* 0x6b4: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_6b7:
	/* 0x6b7: je     4297 <generic_kprobe_process_event+0x4297> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6b7, 0x4297, x86_l_4297);
x86_l_6bd:
	/* 0x6bd: inc    ebx */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_6bf:
	/* 0x6bf: mov    ecx,ebx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RBX, X86_WIDTH_32, 0, 0);
x86_l_6c1:
	/* 0x6c1: and    ecx,0x7 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_6c4:
	/* 0x6c4: cmp    DWORD PTR [rax+rcx*4+0x40],0xffffffff */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 279172874239ULL);
x86_l_6c9:
	/* 0x6c9: je     4297 <generic_kprobe_process_event+0x4297> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6c9, 0x4297, x86_l_4297);
x86_l_6cf:
	/* 0x6cf: mov    DWORD PTR [r14+0x5efc],ebx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24316ULL);
x86_l_6d6:
	/* 0x6d6: mov    rsi,QWORD PTR [rip+0x200] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RSI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)kprobe_calls));
x86_l_6dd:
	/* 0x6dd: mov    rdi,rbp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_6e0:
	/* 0x6e0: mov    edx,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_6e5:
	/* 0x6e5: call   8ea <generic_kprobe_process_event+0x8ea> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_tail_call);
x86_l_6ea:
	/* 0x6ea: jmp    4297 <generic_kprobe_process_event+0x4297> */
	X86_SIM_X86_JMP(0x6ea, 0x4297, x86_l_4297);
x86_l_6ef:
	/* 0x6ef: mov    rcx,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_6f2:
	/* 0x6f2: add    rcx,0x90 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_6f9:
	/* 0x6f9: add    rcx,rdi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_6fc:
	/* 0x6fc: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_701:
	/* 0x701: mov    QWORD PTR [rsp+0x70],r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_706:
	/* 0x706: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_70f:
	/* 0x70f: lea    ecx,[r13-0xf] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551601ULL);
x86_l_713:
	/* 0x713: cmp    ecx,0x1b */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 27ULL);
x86_l_716:
	/* 0x716: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_71b:
	/* 0x71b: ja     75e <generic_kprobe_process_event+0x75e> */
	X86_SIM_X86_JCC(X86_CC_A, 0x71b, 0x75e, x86_l_75e);
x86_l_71d:
	/* Capture image-bound code identity before scheduled instructions. */
	switch (X86_SIM_L_READ_REG(X86_RCX) << 2) {
	case 0ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x72dULL); break;
	case 4ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x955ULL); break;
	case 8ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x75eULL); break;
	case 12ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x75eULL); break;
	case 16ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x75eULL); break;
	case 20ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x75eULL); break;
	case 24ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x75eULL); break;
	case 28ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x75eULL); break;
	case 32ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x75eULL); break;
	case 36ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x816ULL); break;
	case 40ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x75eULL); break;
	case 44ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x75eULL); break;
	case 48ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x75eULL); break;
	case 52ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x75eULL); break;
	case 56ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x75eULL); break;
	case 60ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x75eULL); break;
	case 64ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x75eULL); break;
	case 68ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x75eULL); break;
	case 72ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x75eULL); break;
	case 76ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x75eULL); break;
	case 80ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x75eULL); break;
	case 84ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x75eULL); break;
	case 88ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x83bULL); break;
	case 92ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x75eULL); break;
	case 96ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x75eULL); break;
	case 100ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x75eULL); break;
	case 104ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x75eULL); break;
	case 108ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x860ULL); break;
	default: __x86_sim_unresolved_indirect_target();
	}
x86_l_72b:
	/* 0x72b: jmp    rcx */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RCX);
		switch (X86_SIM_L_REG_TAG(X86_RCX)) {
		case X86_SIM_TAG_CODE:
			switch (__x86_target) {
			case 0x72dULL: goto x86_l_72d;
			case 0x75eULL: goto x86_l_75e;
			case 0x816ULL: goto x86_l_816;
			case 0x83bULL: goto x86_l_83b;
			case 0x860ULL: goto x86_l_860;
			case 0x955ULL: goto x86_l_955;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_72d:
	/* 0x72d: mov    QWORD PTR [rsp+0xb8],rdi */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_735:
	/* 0x735: lea    rax,[rsp+0x70] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_73a:
	/* 0x73a: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_73d:
	/* 0x73d: mov    QWORD PTR [rsp+0x28],r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_742:
	/* 0x742: jns    886 <generic_kprobe_process_event+0x886> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x742, 0x886, x86_l_886);
x86_l_748:
	/* 0x748: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_74b:
	/* 0x74b: mov    rbx,QWORD PTR [rsp+0x48] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_750:
	/* 0x750: jns    8ad <generic_kprobe_process_event+0x8ad> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x750, 0x8ad, x86_l_8ad);
x86_l_756:
	/* 0x756: mov    r15,QWORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_759:
	/* 0x759: jmp    8a4 <generic_kprobe_process_event+0x8a4> */
	X86_SIM_X86_JMP(0x759, 0x8a4, x86_l_8a4);
x86_l_75e:
	/* 0x75e: mov    QWORD PTR [rsp+0xb8],rdi */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_766:
	/* 0x766: mov    QWORD PTR [rsp+0x28],r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_76b:
	/* 0x76b: cmp    r13d,0x2c */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, 0, 44ULL);
x86_l_76f:
	/* 0x76f: mov    rbx,QWORD PTR [rsp+0x48] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_774:
	/* 0x774: ja     8ad <generic_kprobe_process_event+0x8ad> */
	X86_SIM_X86_JCC(X86_CC_A, 0x774, 0x8ad, x86_l_8ad);
x86_l_77a:
	/* 0x77a: mov    eax,r13d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_R13, X86_WIDTH_32, 0, 0);
x86_l_77d:
	/* 0x77d: movabs rcx,0x11c1f2027cf2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, 0, 19524686609650ULL);
x86_l_787:
	/* 0x787: bt     rcx,rax */
	X86_SIM_RUN_OP(X86_OP_BT, X86_RCX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_78b:
	/* 0x78b: jae    8ad <generic_kprobe_process_event+0x8ad> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x78b, 0x8ad, x86_l_8ad);
x86_l_791:
	/* 0x791: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_796:
	/* 0x796: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_79b:
	/* 0x79b: mov    DWORD PTR [rsp+0xc8],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 858993459200ULL);
x86_l_7a6:
	/* 0x7a6: mov    rdi,QWORD PTR [rip+0x200] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)process_call_heap));
x86_l_7ad:
	/* 0x7ad: lea    rsi,[rsp+0xc8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_7b5:
	/* 0x7b5: call   9ba <generic_kprobe_process_event+0x9ba> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_7ba:
	/* 0x7ba: xor    r15d,r15d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_7bd:
	/* 0x7bd: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_7c0:
	/* 0x7c0: je     423c <generic_kprobe_process_event+0x423c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7c0, 0x423c, x86_l_423c);
x86_l_7c6:
	/* 0x7c6: cmp    ebp,0x2b */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, 0, 43ULL);
x86_l_7c9:
	/* 0x7c9: ja     423c <generic_kprobe_process_event+0x423c> */
	X86_SIM_X86_JCC(X86_CC_A, 0x7c9, 0x423c, x86_l_423c);
x86_l_7cf:
	/* Capture image-bound code identity before scheduled instructions. */
	switch (X86_SIM_L_READ_REG(X86_RBP) << 2) {
	case 0ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1144ULL); break;
	case 4ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x4246ULL); break;
	case 8ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x4246ULL); break;
	case 12ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x7e9ULL); break;
	case 16ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x136bULL); break;
	case 20ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x2403ULL); break;
	case 24ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x12b3ULL); break;
	case 28ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x4246ULL); break;
	case 32ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x4246ULL); break;
	case 36ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x7e9ULL); break;
	case 40ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x7e9ULL); break;
	case 44ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1144ULL); break;
	case 48ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1144ULL); break;
	case 52ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1347ULL); break;
	case 56ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x4246ULL); break;
	case 60ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x4246ULL); break;
	case 64ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x143fULL); break;
	case 68ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x4246ULL); break;
	case 72ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x4246ULL); break;
	case 76ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x4246ULL); break;
	case 80ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x4246ULL); break;
	case 84ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x4246ULL); break;
	case 88ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x4246ULL); break;
	case 92ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x4246ULL); break;
	case 96ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x15f3ULL); break;
	case 100ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x4246ULL); break;
	case 104ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x4246ULL); break;
	case 108ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x7e9ULL); break;
	case 112ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x116fULL); break;
	case 116ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x116fULL); break;
	case 120ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x11baULL); break;
	case 124ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x11baULL); break;
	case 128ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x4246ULL); break;
	case 132ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x4246ULL); break;
	case 136ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x4246ULL); break;
	case 140ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x4246ULL); break;
	case 144ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x4246ULL); break;
	case 148ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x12e9ULL); break;
	case 152ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1484ULL); break;
	case 156ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1266ULL); break;
	case 160ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x4246ULL); break;
	case 164ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x4246ULL); break;
	case 168ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x4246ULL); break;
	case 172ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x139dULL); break;
	default: __x86_sim_unresolved_indirect_target();
	}
x86_l_7dd:
	/* 0x7dd: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7e2:
	/* 0x7e2: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_7e7:
	/* 0x7e7: jmp    rdx */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RDX);
		switch (X86_SIM_L_REG_TAG(X86_RDX)) {
		case X86_SIM_TAG_CODE:
			switch (__x86_target) {
			case 0x7e9ULL: goto x86_l_7e9;
			case 0x1144ULL: goto x86_l_1144;
			case 0x116fULL: goto x86_l_116f;
			case 0x11baULL: goto x86_l_11ba;
			case 0x1266ULL: goto x86_l_1266;
			case 0x12b3ULL: goto x86_l_12b3;
			case 0x12e9ULL: goto x86_l_12e9;
			case 0x1347ULL: goto x86_l_1347;
			case 0x136bULL: goto x86_l_136b;
			case 0x139dULL: goto x86_l_139d;
			case 0x143fULL: goto x86_l_143f;
			case 0x1484ULL: goto x86_l_1484;
			case 0x15f3ULL: goto x86_l_15f3;
			case 0x2403ULL: goto x86_l_2403;
			case 0x4246ULL: goto x86_l_4246;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_7e9:
	/* 0x7e9: lea    rax,[rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_7ee:
	/* 0x7ee: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_7f1:
	/* 0x7f1: jns    1196 <generic_kprobe_process_event+0x1196> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x7f1, 0x1196, x86_l_1196);
x86_l_7f7:
	/* 0x7f7: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_7fa:
	/* 0x7fa: jns    1236 <generic_kprobe_process_event+0x1236> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x7fa, 0x1236, x86_l_1236);
x86_l_800:
	/* 0x800: mov    rax,QWORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_803:
	/* 0x803: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_808:
	/* 0x808: mov    QWORD PTR [rdx],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_80b:
	/* 0x80b: mov    r15d,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_811:
	/* 0x811: jmp    4246 <generic_kprobe_process_event+0x4246> */
	X86_SIM_X86_JMP(0x811, 0x4246, x86_l_4246);
x86_l_816:
	/* 0x816: test   r15,r15 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_819:
	/* 0x819: js     936 <generic_kprobe_process_event+0x936> */
	X86_SIM_X86_JCC(X86_CC_S, 0x819, 0x936, x86_l_936);
x86_l_81f:
	/* 0x81f: lea    rdi,[rsp+0x50] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_824:
	/* 0x824: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_829:
	/* 0x829: mov    rdx,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_82c:
	/* 0x82c: call   a31 <generic_kprobe_process_event+0xa31> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_831:
	/* 0x831: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_836:
	/* 0x836: jmp    950 <generic_kprobe_process_event+0x950> */
	X86_SIM_X86_JMP(0x836, 0x950, x86_l_950);
x86_l_83b:
	/* 0x83b: add    r15,0x40 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 64ULL);
x86_l_83f:
	/* 0x83f: mov    QWORD PTR [rsp+0x70],r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_844:
	/* 0x844: jns    927 <generic_kprobe_process_event+0x927> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x844, 0x927, x86_l_927);
x86_l_84a:
	/* 0x84a: test   r15,r15 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_84d:
	/* 0x84d: mov    rbx,QWORD PTR [rsp+0x48] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_852:
	/* 0x852: jns    98e <generic_kprobe_process_event+0x98e> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x852, 0x98e, x86_l_98e);
x86_l_858:
	/* 0x858: mov    r15,QWORD PTR [r15] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R15, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_85b:
	/* 0x85b: jmp    991 <generic_kprobe_process_event+0x991> */
	X86_SIM_X86_JMP(0x85b, 0x991, x86_l_991);
x86_l_860:
	/* 0x860: mov    QWORD PTR [rsp+0xe8],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 996432412672ULL);
x86_l_86c:
	/* 0x86c: mov    QWORD PTR [rsp+0xf0],r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_874:
	/* 0x874: lea    r15,[rsp+0xe8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_87c:
	/* 0x87c: mov    rbx,QWORD PTR [rsp+0x48] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_881:
	/* 0x881: jmp    995 <generic_kprobe_process_event+0x995> */
	X86_SIM_X86_JMP(0x881, 0x995, x86_l_995);
x86_l_886:
	/* 0x886: lea    rdi,[rsp+0x60] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_88b:
	/* 0x88b: lea    rdx,[rsp+0x70] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_890:
	/* 0x890: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_895:
	/* 0x895: call   a9a <generic_kprobe_process_event+0xa9a> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_89a:
	/* 0x89a: mov    r15,QWORD PTR [rsp+0x60] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_89f:
	/* 0x89f: mov    rbx,QWORD PTR [rsp+0x48] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_8a4:
	/* 0x8a4: test   r15,r15 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_8a7:
	/* 0x8a7: jne    995 <generic_kprobe_process_event+0x995> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x8a7, 0x995, x86_l_995);
x86_l_8ad:
	/* 0x8ad: mov    DWORD PTR [rsp+0xd0],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 893353197568ULL);
x86_l_8b8:
	/* 0x8b8: mov    rdi,QWORD PTR [rip+0x200] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)process_call_heap));
x86_l_8bf:
	/* 0x8bf: lea    rsi,[rsp+0xd0] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_8c7:
	/* 0x8c7: call   acc <generic_kprobe_process_event+0xacc> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_8cc:
	/* 0x8cc: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_8cf:
	/* 0x8cf: je     2d4b <generic_kprobe_process_event+0x2d4b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8cf, 0x2d4b, x86_l_2d4b);
x86_l_8d5:
	/* 0x8d5: xor    r15d,r15d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_8d8:
	/* 0x8d8: add    r13d,0xfffffffe */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 4294967294ULL);
x86_l_8dc:
	/* 0x8dc: cmp    r13d,0x29 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, 0, 41ULL);
x86_l_8e0:
	/* 0x8e0: ja     2d4e <generic_kprobe_process_event+0x2d4e> */
	X86_SIM_X86_JCC(X86_CC_A, 0x8e0, 0x2d4e, x86_l_2d4e);
x86_l_8e6:
	/* Capture image-bound code identity before scheduled instructions. */
	switch (X86_SIM_L_READ_REG(X86_R13) << 2) {
	case 0ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1796ULL); break;
	case 4ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x16f3ULL); break;
	case 8ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x2d5dULL); break;
	case 12ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x2d5dULL); break;
	case 16ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x2d5dULL); break;
	case 20ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x2d5dULL); break;
	case 24ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x17f7ULL); break;
	case 28ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x2d5dULL); break;
	case 32ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x2d5dULL); break;
	case 36ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x2d5dULL); break;
	case 40ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x2d5dULL); break;
	case 44ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x2d5dULL); break;
	case 48ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x2d5dULL); break;
	case 52ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x2d5dULL); break;
	case 56ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x2d5dULL); break;
	case 60ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x2d5dULL); break;
	case 64ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x176aULL); break;
	case 68ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x16cbULL); break;
	case 72ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x172fULL); break;
	case 76ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x181eULL); break;
	case 80ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1845ULL); break;
	case 84ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x193eULL); break;
	case 88ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x2d5dULL); break;
	case 92ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x2d5dULL); break;
	case 96ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x189aULL); break;
	case 100ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x163cULL); break;
	case 104ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x2d5dULL); break;
	case 108ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x2d5dULL); break;
	case 112ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x2d5dULL); break;
	case 116ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x2d5dULL); break;
	case 120ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x2d5dULL); break;
	case 124ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x905ULL); break;
	case 128ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x905ULL); break;
	case 132ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x905ULL); break;
	case 136ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x905ULL); break;
	case 140ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x2d5dULL); break;
	case 144ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x2d5dULL); break;
	case 148ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x2d5dULL); break;
	case 152ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x2d5dULL); break;
	case 156ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x186fULL); break;
	case 160ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x2d5dULL); break;
	case 164ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x195cULL); break;
	default: __x86_sim_unresolved_indirect_target();
	}
x86_l_8f4:
	/* 0x8f4: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_8f9:
	/* 0x8f9: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_8fe:
	/* 0x8fe: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_903:
	/* 0x903: jmp    rdx */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RDX);
		switch (X86_SIM_L_REG_TAG(X86_RDX)) {
		case X86_SIM_TAG_CODE:
			switch (__x86_target) {
			case 0x905ULL: goto x86_l_905;
			case 0x163cULL: goto x86_l_163c;
			case 0x16cbULL: goto x86_l_16cb;
			case 0x16f3ULL: goto x86_l_16f3;
			case 0x172fULL: goto x86_l_172f;
			case 0x176aULL: goto x86_l_176a;
			case 0x1796ULL: goto x86_l_1796;
			case 0x17f7ULL: goto x86_l_17f7;
			case 0x181eULL: goto x86_l_181e;
			case 0x1845ULL: goto x86_l_1845;
			case 0x186fULL: goto x86_l_186f;
			case 0x189aULL: goto x86_l_189a;
			case 0x193eULL: goto x86_l_193e;
			case 0x195cULL: goto x86_l_195c;
			case 0x2d5dULL: goto x86_l_2d5d;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_905:
	/* 0x905: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_90a:
	/* 0x90a: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_90d:
	/* 0x90d: js     1204 <generic_kprobe_process_event+0x1204> */
	X86_SIM_X86_JCC(X86_CC_S, 0x90d, 0x1204, x86_l_1204);
x86_l_913:
	/* 0x913: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_918:
	/* 0x918: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_91d:
	/* 0x91d: call   b22 <generic_kprobe_process_event+0xb22> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_922:
	/* 0x922: jmp    19af <generic_kprobe_process_event+0x19af> */
	X86_SIM_X86_JMP(0x922, 0x19af, x86_l_19af);
x86_l_927:
	/* 0x927: lea    rdi,[rsp+0x50] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_92c:
	/* 0x92c: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_931:
	/* 0x931: mov    rdx,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_934:
	/* 0x934: jmp    97d <generic_kprobe_process_event+0x97d> */
	X86_SIM_X86_JMP(0x934, 0x97d, x86_l_97d);
x86_l_936:
	/* 0x936: test   r15,r15 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_939:
	/* 0x939: jns    945 <generic_kprobe_process_event+0x945> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x939, 0x945, x86_l_945);
x86_l_93b:
	/* 0x93b: mov    rax,QWORD PTR [r15] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_93e:
	/* 0x93e: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_943:
	/* 0x943: jmp    950 <generic_kprobe_process_event+0x950> */
	X86_SIM_X86_JMP(0x943, 0x950, x86_l_950);
x86_l_945:
	/* 0x945: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_94e:
	/* 0x94e: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_950:
	/* 0x950: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_955:
	/* 0x955: lea    rax,[rsp+0x70] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_95a:
	/* 0x95a: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_95d:
	/* 0x95d: jns    96e <generic_kprobe_process_event+0x96e> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x95d, 0x96e, x86_l_96e);
x86_l_95f:
	/* 0x95f: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_962:
	/* 0x962: mov    rbx,QWORD PTR [rsp+0x48] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_967:
	/* 0x967: jns    98e <generic_kprobe_process_event+0x98e> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x967, 0x98e, x86_l_98e);
x86_l_969:
	/* 0x969: mov    r15,QWORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_96c:
	/* 0x96c: jmp    991 <generic_kprobe_process_event+0x991> */
	X86_SIM_X86_JMP(0x96c, 0x991, x86_l_991);
x86_l_96e:
	/* 0x96e: lea    rdi,[rsp+0x50] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_973:
	/* 0x973: lea    rdx,[rsp+0x70] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_978:
	/* 0x978: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_97d:
	/* 0x97d: call   b82 <generic_kprobe_process_event+0xb82> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_982:
	/* 0x982: mov    r15,QWORD PTR [rsp+0x50] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_987:
	/* 0x987: mov    rbx,QWORD PTR [rsp+0x48] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_98c:
	/* 0x98c: jmp    991 <generic_kprobe_process_event+0x991> */
	X86_SIM_X86_JMP(0x98c, 0x991, x86_l_991);
x86_l_98e:
	/* 0x98e: xor    r15d,r15d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_991:
	/* 0x991: add    r15,0x40 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 64ULL);
x86_l_995:
	/* 0x995: mov    DWORD PTR [rsp+0xe4],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 979252543488ULL);
x86_l_9a0:
	/* 0x9a0: mov    rdi,QWORD PTR [rip+0x200] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)buffer_heap_map));
x86_l_9a7:
	/* 0x9a7: lea    rsi,[rsp+0xe4] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 228ULL);
x86_l_9af:
	/* 0x9af: call   bb4 <generic_kprobe_process_event+0xbb4> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_9b4:
	/* 0x9b4: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_9b7:
	/* 0x9b7: je     9db <generic_kprobe_process_event+0x9db> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9b7, 0x9db, x86_l_9db);
x86_l_9b9:
	/* 0x9b9: mov    r13,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R13, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_9bc:
	/* 0x9bc: call   bc1 <generic_kprobe_process_event+0xbc1> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_get_current_task);
x86_l_9c1:
	/* 0x9c1: add    rax,0xd50 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 3408ULL);
x86_l_9c7:
	/* 0x9c7: jns    9f0 <generic_kprobe_process_event+0x9f0> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x9c7, 0x9f0, x86_l_9f0);
x86_l_9c9:
	/* 0x9c9: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_9cc:
	/* 0x9cc: jns    a0f <generic_kprobe_process_event+0xa0f> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x9cc, 0xa0f, x86_l_a0f);
x86_l_9ce:
	/* 0x9ce: mov    r12,QWORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9d1:
	/* 0x9d1: mov    QWORD PTR [rsp+0xd0],r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_9d9:
	/* 0x9d9: jmp    a1e <generic_kprobe_process_event+0xa1e> */
	X86_SIM_X86_JMP(0x9d9, 0xa1e, x86_l_a1e);
x86_l_9db:
	/* 0x9db: xor    r15d,r15d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_9de:
	/* 0x9de: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_9e3:
	/* 0x9e3: mov    r12,QWORD PTR [rsp+0xb0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_9eb:
	/* 0x9eb: jmp    4258 <generic_kprobe_process_event+0x4258> */
	X86_SIM_X86_JMP(0x9eb, 0x4258, x86_l_4258);
x86_l_9f0:
	/* 0x9f0: lea    rdi,[rsp+0xd0] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_9f8:
	/* 0x9f8: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_9fd:
	/* 0x9fd: mov    rdx,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_a00:
	/* 0xa00: call   c05 <generic_kprobe_process_event+0xc05> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_a05:
	/* 0xa05: mov    r12,QWORD PTR [rsp+0xd0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_a0d:
	/* 0xa0d: jmp    a1e <generic_kprobe_process_event+0xa1e> */
	X86_SIM_X86_JMP(0xa0d, 0xa1e, x86_l_a1e);
x86_l_a0f:
	/* 0xa0f: mov    QWORD PTR [rsp+0xd0],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 893353197568ULL);
x86_l_a1b:
	/* 0xa1b: xor    r12d,r12d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_a1e:
	/* 0xa1e: mov    rdx,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_a21:
	/* 0xa21: add    rdx,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_a25:
	/* 0xa25: mov    QWORD PTR [rsp+0x30],rdx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_a2a:
	/* 0xa2a: jns    a41 <generic_kprobe_process_event+0xa41> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xa2a, 0xa41, x86_l_a41);
x86_l_a2c:
	/* 0xa2c: mov    rax,rdx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_a2f:
	/* 0xa2f: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_a32:
	/* 0xa32: jns    a5d <generic_kprobe_process_event+0xa5d> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xa32, 0xa5d, x86_l_a5d);
x86_l_a34:
	/* 0xa34: mov    rbx,QWORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a37:
	/* 0xa37: mov    QWORD PTR [rsp+0xc0],rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_a3f:
	/* 0xa3f: jmp    a6b <generic_kprobe_process_event+0xa6b> */
	X86_SIM_X86_JMP(0xa3f, 0xa6b, x86_l_a6b);
x86_l_a41:
	/* 0xa41: lea    rdi,[rsp+0xc0] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_a49:
	/* 0xa49: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_a4e:
	/* 0xa4e: call   c53 <generic_kprobe_process_event+0xc53> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_a53:
	/* 0xa53: mov    rbx,QWORD PTR [rsp+0xc0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_a5b:
	/* 0xa5b: jmp    a6b <generic_kprobe_process_event+0xa6b> */
	X86_SIM_X86_JMP(0xa5b, 0xa6b, x86_l_a6b);
x86_l_a5d:
	/* 0xa5d: mov    QWORD PTR [rsp+0xc0],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_a69:
	/* 0xa69: xor    ebx,ebx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_a6b:
	/* 0xa6b: lea    rbp,[r13+0x1000] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RBP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4096ULL);
x86_l_a72:
	/* 0xa72: mov    rdx,rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_a75:
	/* 0xa75: add    rdx,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_a79:
	/* 0xa79: jns    a85 <generic_kprobe_process_event+0xa85> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xa79, 0xa85, x86_l_a85);
x86_l_a7b:
	/* 0xa7b: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_a7e:
	/* 0xa7e: jns    aa3 <generic_kprobe_process_event+0xaa3> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xa7e, 0xaa3, x86_l_aa3);
x86_l_a80:
	/* 0xa80: mov    rcx,QWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a83:
	/* 0xa83: jmp    a99 <generic_kprobe_process_event+0xa99> */
	X86_SIM_X86_JMP(0xa83, 0xa99, x86_l_a99);
x86_l_a85:
	/* 0xa85: lea    rdi,[rsp+0x70] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_a8a:
	/* 0xa8a: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_a8f:
	/* 0xa8f: call   c94 <generic_kprobe_process_event+0xc94> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_a94:
	/* 0xa94: mov    rcx,QWORD PTR [rsp+0x70] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_a99:
	/* 0xa99: mov    eax,0x1000 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 4096ULL);
x86_l_a9e:
	/* 0xa9e: test   rcx,rcx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_aa1:
	/* 0xaa1: jne    b04 <generic_kprobe_process_event+0xb04> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xaa1, 0xb04, x86_l_b04);
x86_l_aa3:
	/* 0xaa3: mov    rdx,rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_aa6:
	/* 0xaa6: add    rdx,0x18 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_aaa:
	/* 0xaaa: jns    ab6 <generic_kprobe_process_event+0xab6> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xaaa, 0xab6, x86_l_ab6);
x86_l_aac:
	/* 0xaac: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_aaf:
	/* 0xaaf: jns    acc <generic_kprobe_process_event+0xacc> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xaaf, 0xacc, x86_l_acc);
x86_l_ab1:
	/* 0xab1: mov    rax,QWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ab4:
	/* 0xab4: jmp    ace <generic_kprobe_process_event+0xace> */
	X86_SIM_X86_JMP(0xab4, 0xace, x86_l_ace);
x86_l_ab6:
	/* 0xab6: lea    rdi,[rsp+0x70] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_abb:
	/* 0xabb: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_ac0:
	/* 0xac0: call   cc5 <generic_kprobe_process_event+0xcc5> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_ac5:
	/* 0xac5: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_aca:
	/* 0xaca: jmp    ace <generic_kprobe_process_event+0xace> */
	X86_SIM_X86_JMP(0xaca, 0xace, x86_l_ace);
x86_l_acc:
	/* 0xacc: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_ace:
	/* 0xace: cmp    rax,rbx */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RAX, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_ad1:
	/* 0xad1: je     aff <generic_kprobe_process_event+0xaff> */
	X86_SIM_X86_JCC(X86_CC_E, 0xad1, 0xaff, x86_l_aff);
x86_l_ad3:
	/* 0xad3: mov    rbp,r13 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RBP, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_ad6:
	/* 0xad6: add    rbp,0xff6 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 4086ULL);
x86_l_add:
	/* 0xadd: movabs rax,0x6574656c65642820 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, 0, 7310579611361093664ULL);
x86_l_ae7:
	/* 0xae7: mov    QWORD PTR [r13+0xff6],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4086ULL);
x86_l_aee:
	/* 0xaee: mov    WORD PTR [r13+0xffe],0x2964 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17583596120420ULL);
x86_l_af8:
	/* 0xaf8: mov    eax,0xff6 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 4086ULL);
x86_l_afd:
	/* 0xafd: jmp    b04 <generic_kprobe_process_event+0xb04> */
	X86_SIM_X86_JMP(0xafd, 0xb04, x86_l_b04);
x86_l_aff:
	/* 0xaff: mov    eax,0x1000 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 4096ULL);
x86_l_b04:
	/* 0xb04: mov    rbx,QWORD PTR [rsp+0x48] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_b09:
	/* 0xb09: mov    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_b12:
	/* 0xb12: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_b1b:
	/* 0xb1b: mov    QWORD PTR [rsp+0x80],r13 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_b23:
	/* 0xb23: mov    QWORD PTR [rsp+0x88],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_b2f:
	/* 0xb2f: mov    QWORD PTR [rsp+0x90],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_b3b:
	/* 0xb3b: mov    QWORD PTR [rsp+0x98],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_b47:
	/* 0xb47: mov    QWORD PTR [rsp+0xa0],rbp */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_b4f:
	/* 0xb4f: lea    r13,[r12+0x18] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b54:
	/* 0xb54: mov    DWORD PTR [rsp+0xa8],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_b5b:
	/* 0xb5b: mov    BYTE PTR [rsp+0xac],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_b63:
	/* 0xb63: add    r12,0x20 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_b67:
	/* 0xb67: mov    QWORD PTR [rsp+0x28],rbp */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_b6c:
	/* 0xb6c: jns    b7e <generic_kprobe_process_event+0xb7e> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xb6c, 0xb7e, x86_l_b7e);
x86_l_b6e:
	/* 0xb6e: test   r12,r12 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_b71:
	/* 0xb71: jns    b92 <generic_kprobe_process_event+0xb92> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xb71, 0xb92, x86_l_b92);
x86_l_b73:
	/* 0xb73: mov    rax,QWORD PTR [r12] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b77:
	/* 0xb77: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_b7c:
	/* 0xb7c: jmp    b9b <generic_kprobe_process_event+0xb9b> */
	X86_SIM_X86_JMP(0xb7c, 0xb9b, x86_l_b9b);
x86_l_b7e:
	/* 0xb7e: lea    rdi,[rsp+0x70] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_b83:
	/* 0xb83: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_b88:
	/* 0xb88: mov    rdx,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_b8b:
	/* 0xb8b: call   d90 <generic_kprobe_process_event+0xd90> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_b90:
	/* 0xb90: jmp    b9b <generic_kprobe_process_event+0xb9b> */
	X86_SIM_X86_JMP(0xb90, 0xb9b, x86_l_b9b);
x86_l_b92:
	/* 0xb92: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_b9b:
	/* 0xb9b: test   r13,r13 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_b9e:
	/* 0xb9e: jns    bb0 <generic_kprobe_process_event+0xbb0> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xb9e, 0xbb0, x86_l_bb0);
x86_l_ba0:
	/* 0xba0: test   r13,r13 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_ba3:
	/* 0xba3: jns    bc4 <generic_kprobe_process_event+0xbc4> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xba3, 0xbc4, x86_l_bc4);
x86_l_ba5:
	/* 0xba5: mov    rax,QWORD PTR [r13+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ba9:
	/* 0xba9: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_bae:
	/* 0xbae: jmp    bcd <generic_kprobe_process_event+0xbcd> */
	X86_SIM_X86_JMP(0xbae, 0xbcd, x86_l_bcd);
x86_l_bb0:
	/* 0xbb0: lea    rdi,[rsp+0x78] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_bb5:
	/* 0xbb5: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_bba:
	/* 0xbba: mov    rdx,r13 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_bbd:
	/* 0xbbd: call   dc2 <generic_kprobe_process_event+0xdc2> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_bc2:
	/* 0xbc2: jmp    bcd <generic_kprobe_process_event+0xbcd> */
	X86_SIM_X86_JMP(0xbc2, 0xbcd, x86_l_bcd);
x86_l_bc4:
	/* 0xbc4: mov    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_bcd:
	/* 0xbcd: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_bd2:
	/* 0xbd2: lea    rdi,[rsp+0x88] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_bda:
	/* 0xbda: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_bdd:
	/* 0xbdd: jns    bf4 <generic_kprobe_process_event+0xbf4> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xbdd, 0xbf4, x86_l_bf4);
x86_l_bdf:
	/* 0xbdf: mov    rax,rdx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_be2:
	/* 0xbe2: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_be5:
	/* 0xbe5: jns    c00 <generic_kprobe_process_event+0xc00> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xbe5, 0xc00, x86_l_c00);
x86_l_be7:
	/* 0xbe7: mov    rax,QWORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bea:
	/* 0xbea: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_bf2:
	/* 0xbf2: jmp    c0c <generic_kprobe_process_event+0xc0c> */
	X86_SIM_X86_JMP(0xbf2, 0xc0c, x86_l_c0c);
x86_l_bf4:
	/* 0xbf4: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_bf9:
	/* 0xbf9: call   dfe <generic_kprobe_process_event+0xdfe> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_bfe:
	/* 0xbfe: jmp    c0c <generic_kprobe_process_event+0xc0c> */
	X86_SIM_X86_JMP(0xbfe, 0xc0c, x86_l_c0c);
x86_l_c00:
	/* 0xc00: mov    QWORD PTR [rsp+0x88],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_c0c:
	/* 0xc0c: test   r15,r15 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_c0f:
	/* 0xc0f: jns    c23 <generic_kprobe_process_event+0xc23> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xc0f, 0xc23, x86_l_c23);
x86_l_c11:
	/* 0xc11: test   r15,r15 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_c14:
	/* 0xc14: jns    c42 <generic_kprobe_process_event+0xc42> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xc14, 0xc42, x86_l_c42);
x86_l_c16:
	/* 0xc16: mov    rax,QWORD PTR [r15] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c19:
	/* 0xc19: mov    QWORD PTR [rsp+0x90],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_c21:
	/* 0xc21: jmp    c50 <generic_kprobe_process_event+0xc50> */
	X86_SIM_X86_JMP(0xc21, 0xc50, x86_l_c50);
x86_l_c23:
	/* 0xc23: lea    rdi,[rsp+0x90] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_c2b:
	/* 0xc2b: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_c30:
	/* 0xc30: mov    rdx,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_c33:
	/* 0xc33: call   e38 <generic_kprobe_process_event+0xe38> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_c38:
	/* 0xc38: mov    rax,QWORD PTR [rsp+0x90] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_c40:
	/* 0xc40: jmp    c50 <generic_kprobe_process_event+0xc50> */
	X86_SIM_X86_JMP(0xc40, 0xc50, x86_l_c50);
x86_l_c42:
	/* 0xc42: mov    QWORD PTR [rsp+0x90],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_c4e:
	/* 0xc4e: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_c50:
	/* 0xc50: add    rax,0xffffffffffffffe0 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551584ULL);
x86_l_c54:
	/* 0xc54: mov    QWORD PTR [rsp+0x98],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_c5c:
	/* 0xc5c: xor    ebp,ebp */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_c5e:
	/* 0xc5e: jmp    ca4 <generic_kprobe_process_event+0xca4> */
	X86_SIM_X86_JMP(0xc5e, 0xca4, x86_l_ca4);
x86_l_c60:
	/* 0xc60: lea    rdi,[rsp+0x88] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_c68:
	/* 0xc68: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_c6d:
	/* 0xc6d: mov    rdx,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_c70:
	/* 0xc70: call   e75 <generic_kprobe_process_event+0xe75> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_c75:
	/* 0xc75: mov    r12,QWORD PTR [rsp+0xb0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_c7d:
	/* 0xc7d: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_c82:
	/* 0xc82: mov    QWORD PTR [rsp+0x98],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_c8a:
	/* 0xc8a: add    rax,0x20 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_c8e:
	/* 0xc8e: mov    QWORD PTR [rsp+0x90],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_c96:
	/* 0xc96: inc    ebp */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_c98:
	/* 0xc98: cmp    ebp,0x800 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, 0, 2048ULL);
x86_l_c9e:
	/* 0xc9e: je     fd1 <generic_kprobe_process_event+0xfd1> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc9e, 0xfd1, x86_l_fd1);
x86_l_ca4:
	/* 0xca4: mov    r15,QWORD PTR [rsp+0x88] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_cac:
	/* 0xcac: mov    rdx,QWORD PTR [rsp+0x90] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_cb4:
	/* 0xcb4: mov    r12,QWORD PTR [rsp+0x98] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_cbc:
	/* 0xcbc: cmp    r15,QWORD PTR [rsp+0x70] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 112ULL);
x86_l_cc1:
	/* 0xcc1: jne    cce <generic_kprobe_process_event+0xcce> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xcc1, 0xcce, x86_l_cce);
x86_l_cc3:
	/* 0xcc3: cmp    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 120ULL);
x86_l_cc8:
	/* 0xcc8: je     fb2 <generic_kprobe_process_event+0xfb2> */
	X86_SIM_X86_JCC(X86_CC_E, 0xcc8, 0xfb2, x86_l_fb2);
x86_l_cce:
	/* 0xcce: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_cd1:
	/* 0xcd1: jns    ced <generic_kprobe_process_event+0xced> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xcd1, 0xced, x86_l_ced);
x86_l_cd3:
	/* 0xcd3: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_cd6:
	/* 0xcd6: jns    d0e <generic_kprobe_process_event+0xd0e> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xcd6, 0xd0e, x86_l_d0e);
x86_l_cd8:
	/* 0xcd8: mov    rax,QWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cdb:
	/* 0xcdb: mov    QWORD PTR [rsp+0xc8],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_ce3:
	/* 0xce3: cmp    r15,rax */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_R15, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_ce6:
	/* 0xce6: jne    d21 <generic_kprobe_process_event+0xd21> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xce6, 0xd21, x86_l_d21);
x86_l_ce8:
	/* 0xce8: jmp    d88 <generic_kprobe_process_event+0xd88> */
	X86_SIM_X86_JMP(0xce8, 0xd88, x86_l_d88);
x86_l_ced:
	/* 0xced: lea    rdi,[rsp+0xc8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_cf5:
	/* 0xcf5: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_cfa:
	/* 0xcfa: call   eff <generic_kprobe_process_event+0xeff> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_cff:
	/* 0xcff: mov    rax,QWORD PTR [rsp+0xc8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_d07:
	/* 0xd07: cmp    r15,rax */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_R15, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_d0a:
	/* 0xd0a: jne    d21 <generic_kprobe_process_event+0xd21> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xd0a, 0xd21, x86_l_d21);
x86_l_d0c:
	/* 0xd0c: jmp    d88 <generic_kprobe_process_event+0xd88> */
	X86_SIM_X86_JMP(0xd0c, 0xd88, x86_l_d88);
x86_l_d0e:
	/* 0xd0e: mov    QWORD PTR [rsp+0xc8],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 858993459200ULL);
x86_l_d1a:
	/* 0xd1a: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_d1c:
	/* 0xd1c: cmp    r15,rax */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_R15, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_d1f:
	/* 0xd1f: je     d88 <generic_kprobe_process_event+0xd88> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd1f, 0xd88, x86_l_d88);
x86_l_d21:
	/* 0xd21: mov    r13,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R13, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_d24:
	/* 0xd24: add    r13,0x18 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_d28:
	/* 0xd28: jns    d3c <generic_kprobe_process_event+0xd3c> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xd28, 0xd3c, x86_l_d3c);
x86_l_d2a:
	/* 0xd2a: mov    rax,r13 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_d2d:
	/* 0xd2d: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_d30:
	/* 0xd30: jns    d6c <generic_kprobe_process_event+0xd6c> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xd30, 0xd6c, x86_l_d6c);
x86_l_d32:
	/* 0xd32: mov    rax,QWORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d35:
	/* 0xd35: cmp    r15,rax */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_R15, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_d38:
	/* 0xd38: jne    d71 <generic_kprobe_process_event+0xd71> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xd38, 0xd71, x86_l_d71);
x86_l_d3a:
	/* 0xd3a: jmp    d88 <generic_kprobe_process_event+0xd88> */
	X86_SIM_X86_JMP(0xd3a, 0xd88, x86_l_d88);
x86_l_d3c:
	/* 0xd3c: lea    rdi,[rsp+0x50] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_d41:
	/* 0xd41: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_d46:
	/* 0xd46: mov    rdx,r13 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_d49:
	/* 0xd49: call   f4e <generic_kprobe_process_event+0xf4e> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_d4e:
	/* 0xd4e: cmp    QWORD PTR [rsp+0x50],r15 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_d53:
	/* 0xd53: je     d88 <generic_kprobe_process_event+0xd88> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd53, 0xd88, x86_l_d88);
x86_l_d55:
	/* 0xd55: lea    rdi,[rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_d5a:
	/* 0xd5a: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_d5f:
	/* 0xd5f: mov    rdx,r13 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_d62:
	/* 0xd62: call   f67 <generic_kprobe_process_event+0xf67> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_d67:
	/* 0xd67: jmp    e09 <generic_kprobe_process_event+0xe09> */
	X86_SIM_X86_JMP(0xd67, 0xe09, x86_l_e09);
x86_l_d6c:
	/* 0xd6c: test   r15,r15 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_d6f:
	/* 0xd6f: je     d88 <generic_kprobe_process_event+0xd88> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd6f, 0xd88, x86_l_d88);
x86_l_d71:
	/* 0xd71: test   r13,r13 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_d74:
	/* 0xd74: jns    e00 <generic_kprobe_process_event+0xe00> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xd74, 0xe00, x86_l_e00);
x86_l_d7a:
	/* 0xd7a: mov    rax,QWORD PTR [r13+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d7e:
	/* 0xd7e: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_d83:
	/* 0xd83: jmp    e09 <generic_kprobe_process_event+0xe09> */
	X86_SIM_X86_JMP(0xd83, 0xe09, x86_l_e09);
x86_l_d88:
	/* 0xd88: mov    rdx,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_d8b:
	/* 0xd8b: add    rdx,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_d8f:
	/* 0xd8f: jns    da0 <generic_kprobe_process_event+0xda0> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xd8f, 0xda0, x86_l_da0);
x86_l_d91:
	/* 0xd91: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_d94:
	/* 0xd94: jns    db6 <generic_kprobe_process_event+0xdb6> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xd94, 0xdb6, x86_l_db6);
x86_l_d96:
	/* 0xd96: mov    rax,QWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d99:
	/* 0xd99: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_d9e:
	/* 0xd9e: jmp    dc1 <generic_kprobe_process_event+0xdc1> */
	X86_SIM_X86_JMP(0xd9e, 0xdc1, x86_l_dc1);
x86_l_da0:
	/* 0xda0: lea    rdi,[rsp+0x50] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_da5:
	/* 0xda5: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_daa:
	/* 0xdaa: call   faf <generic_kprobe_process_event+0xfaf> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_daf:
	/* 0xdaf: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_db4:
	/* 0xdb4: jmp    dc1 <generic_kprobe_process_event+0xdc1> */
	X86_SIM_X86_JMP(0xdb4, 0xdc1, x86_l_dc1);
x86_l_db6:
	/* 0xdb6: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_dbf:
	/* 0xdbf: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_dc1:
	/* 0xdc1: cmp    QWORD PTR [rsp+0x98],rax */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_dc9:
	/* 0xdc9: je     fc1 <generic_kprobe_process_event+0xfc1> */
	X86_SIM_X86_JCC(X86_CC_E, 0xdc9, 0xfc1, x86_l_fc1);
x86_l_dcf:
	/* 0xdcf: add    r12,0x18 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_dd3:
	/* 0xdd3: jns    c60 <generic_kprobe_process_event+0xc60> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xdd3, 0xc60, x86_l_c60);
x86_l_dd9:
	/* 0xdd9: test   r12,r12 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_ddc:
	/* 0xddc: jns    def <generic_kprobe_process_event+0xdef> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xddc, 0xdef, x86_l_def);
x86_l_dde:
	/* 0xdde: mov    rax,QWORD PTR [r12] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_de2:
	/* 0xde2: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_dea:
	/* 0xdea: jmp    c75 <generic_kprobe_process_event+0xc75> */
	X86_SIM_X86_JMP(0xdea, 0xc75, x86_l_c75);
x86_l_def:
	/* 0xdef: mov    QWORD PTR [rsp+0x88],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_dfb:
	/* 0xdfb: jmp    c75 <generic_kprobe_process_event+0xc75> */
	X86_SIM_X86_JMP(0xdfb, 0xc75, x86_l_c75);
x86_l_e00:
	/* 0xe00: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_e09:
	/* 0xe09: add    r15,0x20 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_e0d:
	/* 0xe0d: jns    e27 <generic_kprobe_process_event+0xe27> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xe0d, 0xe27, x86_l_e27);
x86_l_e0f:
	/* 0xe0f: test   r15,r15 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_e12:
	/* 0xe12: jns    e40 <generic_kprobe_process_event+0xe40> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xe12, 0xe40, x86_l_e40);
x86_l_e14:
	/* 0xe14: mov    rax,QWORD PTR [r15] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e17:
	/* 0xe17: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_e1c:
	/* 0xe1c: mov    rdx,QWORD PTR [r15+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e20:
	/* 0xe20: mov    QWORD PTR [rsp+0x68],rdx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_e25:
	/* 0xe25: jmp    e54 <generic_kprobe_process_event+0xe54> */
	X86_SIM_X86_JMP(0xe25, 0xe54, x86_l_e54);
x86_l_e27:
	/* 0xe27: lea    rdi,[rsp+0x60] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_e2c:
	/* 0xe2c: mov    esi,0x10 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 16ULL);
x86_l_e31:
	/* 0xe31: mov    rdx,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_e34:
	/* 0xe34: call   1039 <generic_kprobe_process_event+0x1039> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_e39:
	/* 0xe39: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_e3e:
	/* 0xe3e: jmp    e54 <generic_kprobe_process_event+0xe54> */
	X86_SIM_X86_JMP(0xe3e, 0xe54, x86_l_e54);
x86_l_e40:
	/* 0xe40: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_e49:
	/* 0xe49: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_e52:
	/* 0xe52: xor    edx,edx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_e54:
	/* 0xe54: mov    r15,QWORD PTR [rsp+0x80] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_e5c:
	/* 0xe5c: mov    r13,QWORD PTR [rsp+0xa0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_e64:
	/* 0xe64: mov    r12d,DWORD PTR [rsp+0x64] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 100ULL);
x86_l_e69:
	/* 0xe69: sub    r13,r15 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R13, X86_R15, X86_WIDTH_64, X86_ALU_SUB, 0);
x86_l_e6c:
	/* 0xe6c: mov    ebx,DWORD PTR [rsp+0xa8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_e73:
	/* 0xe73: xor    esi,esi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_e75:
	/* 0xe75: mov    ecx,r12d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_R12, X86_WIDTH_32, 0, 0);
x86_l_e78:
	/* 0xe78: sub    ecx,ebx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RBX, X86_WIDTH_32, X86_ALU_SUB, 0);
x86_l_e7a:
	/* 0xe7a: mov    eax,0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 0ULL);
x86_l_e7f:
	/* 0xe7f: cmovb  ecx,eax */
	X86_SIM_RUN_OP(X86_OP_CMOV, X86_RCX, X86_RAX, X86_WIDTH_32, X86_CC_B, 0);
x86_l_e82:
	/* 0xe82: setb   sil */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_CC_B, 0);
x86_l_e86:
	/* 0xe86: mov    eax,r12d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_R12, X86_WIDTH_32, 0, 0);
x86_l_e89:
	/* 0xe89: cmova  eax,ebx */
	X86_SIM_RUN_OP(X86_OP_CMOV, X86_RAX, X86_RBX, X86_WIDTH_32, X86_CC_A, 0);
x86_l_e8c:
	/* 0xe8c: add    esi,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 0);
x86_l_e8e:
	/* 0xe8e: mov    edi,ebx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_RBX, X86_WIDTH_32, 0, 0);
x86_l_e90:
	/* 0xe90: sub    edi,esi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB, 0);
x86_l_e92:
	/* 0xe92: mov    DWORD PTR [rsp+0xa8],edi */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_e99:
	/* 0xe99: sub    r13,rsi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R13, X86_RSI, X86_WIDTH_64, X86_ALU_SUB, 0);
x86_l_e9c:
	/* 0xe9c: jb     fba <generic_kprobe_process_event+0xfba> */
	X86_SIM_X86_JCC(X86_CC_B, 0xe9c, 0xfba, x86_l_fba);
x86_l_ea2:
	/* 0xea2: cmp    r13,0xfff */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, 0, 4095ULL);
x86_l_ea9:
	/* 0xea9: ja     fba <generic_kprobe_process_event+0xfba> */
	X86_SIM_X86_JCC(X86_CC_A, 0xea9, 0xfba, x86_l_fba);
x86_l_eaf:
	/* 0xeaf: cmp    ebx,r12d */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RBX, X86_R12, X86_WIDTH_32, 0, 0);
x86_l_eb2:
	/* 0xeb2: jbe    eb9 <generic_kprobe_process_event+0xeb9> */
	X86_SIM_X86_JCC(X86_CC_BE, 0xeb2, 0xeb9, x86_l_eb9);
x86_l_eb4:
	/* 0xeb4: mov    BYTE PTR [r15+r13*1],0x2f */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_R13, 0), 47ULL);
x86_l_eb9:
	/* 0xeb9: add    rdx,rcx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_ebc:
	/* 0xebc: cmp    r12d,ebx */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_R12, X86_RBX, X86_WIDTH_32, 0, 0);
x86_l_ebf:
	/* 0xebf: movzx  esi,al */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_RSI, X86_RAX, X86_WIDTH_32, X86_WIDTH_8, 0);
x86_l_ec2:
	/* 0xec2: mov    rdi,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_ec5:
	/* 0xec5: adc    rdi,r13 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADC, 0);
x86_l_ec8:
	/* 0xec8: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_ecb:
	/* 0xecb: jns    f16 <generic_kprobe_process_event+0xf16> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xecb, 0xf16, x86_l_f16);
x86_l_ecd:
	/* 0xecd: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_ed0:
	/* 0xed0: jns    f30 <generic_kprobe_process_event+0xf30> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xed0, 0xf30, x86_l_f30);
x86_l_ed2:
	/* 0xed2: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_ed4:
	/* 0xed4: cmp    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_ed7:
	/* 0xed7: jb     ef5 <generic_kprobe_process_event+0xef5> */
	X86_SIM_X86_JCC(X86_CC_B, 0xed7, 0xef5, x86_l_ef5);
x86_l_ed9:
	/* 0xed9: mov    esi,esi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_edb:
	/* 0xedb: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_edd:
	/* 0xedd: mov    r8,rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R8, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_ee0:
	/* 0xee0: mov    rcx,QWORD PTR [rdx+rcx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_ee4:
	/* 0xee4: mov    QWORD PTR [rdi+r8*1],rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R8, 0), 0ULL);
x86_l_ee8:
	/* 0xee8: lea    rcx,[r8+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RCX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_eec:
	/* 0xeec: add    r8,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_ef0:
	/* 0xef0: cmp    r8,rsi */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_R8, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_ef3:
	/* 0xef3: jbe    edd <generic_kprobe_process_event+0xedd> */
	X86_SIM_X86_JCC(X86_CC_BE, 0xef3, 0xedd, x86_l_edd);
x86_l_ef5:
	/* 0xef5: test   al,0x4 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, 0, 4ULL);
x86_l_ef7:
	/* 0xef7: jne    f4b <generic_kprobe_process_event+0xf4b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xef7, 0xf4b, x86_l_f4b);
x86_l_ef9:
	/* 0xef9: test   al,0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, 0, 2ULL);
x86_l_efb:
	/* 0xefb: jne    f5c <generic_kprobe_process_event+0xf5c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xefb, 0xf5c, x86_l_f5c);
x86_l_efd:
	/* 0xefd: test   al,0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_eff:
	/* 0xeff: jne    f6f <generic_kprobe_process_event+0xf6f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xeff, 0xf6f, x86_l_f6f);
x86_l_f01:
	/* 0xf01: add    r15,r13 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R15, X86_R13, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_f04:
	/* 0xf04: mov    QWORD PTR [rsp+0xa0],r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_f0c:
	/* 0xf0c: cmp    ebx,r12d */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RBX, X86_R12, X86_WIDTH_32, 0, 0);
x86_l_f0f:
	/* 0xf0f: ja     f88 <generic_kprobe_process_event+0xf88> */
	X86_SIM_X86_JCC(X86_CC_A, 0xf0f, 0xf88, x86_l_f88);
x86_l_f11:
	/* 0xf11: jmp    fba <generic_kprobe_process_event+0xfba> */
	X86_SIM_X86_JMP(0xf11, 0xfba, x86_l_fba);
x86_l_f16:
	/* 0xf16: call   111b <generic_kprobe_process_event+0x111b> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_f1b:
	/* 0xf1b: add    r15,r13 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R15, X86_R13, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_f1e:
	/* 0xf1e: mov    QWORD PTR [rsp+0xa0],r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_f26:
	/* 0xf26: cmp    ebx,r12d */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RBX, X86_R12, X86_WIDTH_32, 0, 0);
x86_l_f29:
	/* 0xf29: ja     f88 <generic_kprobe_process_event+0xf88> */
	X86_SIM_X86_JCC(X86_CC_A, 0xf29, 0xf88, x86_l_f88);
x86_l_f2b:
	/* 0xf2b: jmp    fba <generic_kprobe_process_event+0xfba> */
	X86_SIM_X86_JMP(0xf2b, 0xfba, x86_l_fba);
x86_l_f30:
	/* 0xf30: mov    edx,esi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_f32:
	/* 0xf32: xor    esi,esi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_f34:
	/* 0xf34: call   4f97 <__native_link_local_memset_zero_dynamic> */
	X86_SIM_X86_CALL(x86_l_4f97, 0xf39ULL);
x86_l_f39:
	/* 0xf39: add    r15,r13 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R15, X86_R13, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_f3c:
	/* 0xf3c: mov    QWORD PTR [rsp+0xa0],r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_f44:
	/* 0xf44: cmp    ebx,r12d */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RBX, X86_R12, X86_WIDTH_32, 0, 0);
x86_l_f47:
	/* 0xf47: ja     f88 <generic_kprobe_process_event+0xf88> */
	X86_SIM_X86_JCC(X86_CC_A, 0xf47, 0xf88, x86_l_f88);
x86_l_f49:
	/* 0xf49: jmp    fba <generic_kprobe_process_event+0xfba> */
	X86_SIM_X86_JMP(0xf49, 0xfba, x86_l_fba);
x86_l_f4b:
	/* 0xf4b: mov    esi,ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_f4d:
	/* 0xf4d: mov    r8d,DWORD PTR [rdx+rsi*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R8, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_f51:
	/* 0xf51: mov    DWORD PTR [rdi+rsi*1],r8d */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_f55:
	/* 0xf55: or     ecx,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_OR, 4ULL);
x86_l_f58:
	/* 0xf58: test   al,0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, 0, 2ULL);
x86_l_f5a:
	/* 0xf5a: je     efd <generic_kprobe_process_event+0xefd> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf5a, 0xefd, x86_l_efd);
x86_l_f5c:
	/* 0xf5c: mov    esi,ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_f5e:
	/* 0xf5e: movzx  r8d,WORD PTR [rdx+rsi*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R8, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_16), 0ULL);
x86_l_f63:
	/* 0xf63: mov    WORD PTR [rdi+rsi*1],r8w */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_R8, X86_WIDTH_16, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_f68:
	/* 0xf68: add    ecx,0x2 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_f6b:
	/* 0xf6b: test   al,0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_f6d:
	/* 0xf6d: je     f01 <generic_kprobe_process_event+0xf01> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf6d, 0xf01, x86_l_f01);
x86_l_f6f:
	/* 0xf6f: mov    eax,ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_f71:
	/* 0xf71: movzx  ecx,BYTE PTR [rdx+rax*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_f75:
	/* 0xf75: mov    BYTE PTR [rdi+rax*1],cl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_f78:
	/* 0xf78: add    r15,r13 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R15, X86_R13, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_f7b:
	/* 0xf7b: mov    QWORD PTR [rsp+0xa0],r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_f83:
	/* 0xf83: cmp    ebx,r12d */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RBX, X86_R12, X86_WIDTH_32, 0, 0);
x86_l_f86:
	/* 0xf86: jbe    fba <generic_kprobe_process_event+0xfba> */
	X86_SIM_X86_JCC(X86_CC_BE, 0xf86, 0xfba, x86_l_fba);
x86_l_f88:
	/* 0xf88: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_f8d:
	/* 0xf8d: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_f95:
	/* 0xf95: mov    rbx,QWORD PTR [rsp+0x48] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_f9a:
	/* 0xf9a: mov    r12,QWORD PTR [rsp+0xb0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_fa2:
	/* 0xfa2: inc    ebp */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_fa4:
	/* 0xfa4: cmp    ebp,0x800 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, 0, 2048ULL);
x86_l_faa:
	/* 0xfaa: jne    ca4 <generic_kprobe_process_event+0xca4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xfaa, 0xca4, x86_l_ca4);
x86_l_fb0:
	/* 0xfb0: jmp    fd1 <generic_kprobe_process_event+0xfd1> */
	X86_SIM_X86_JMP(0xfb0, 0xfd1, x86_l_fd1);
x86_l_fb2:
	/* 0xfb2: mov    BYTE PTR [rsp+0xac],0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 738734374913ULL);
x86_l_fba:
	/* 0xfba: mov    rbx,QWORD PTR [rsp+0x48] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_fbf:
	/* 0xfbf: jmp    fc9 <generic_kprobe_process_event+0xfc9> */
	X86_SIM_X86_JMP(0xfbf, 0xfc9, x86_l_fc9);
x86_l_fc1:
	/* 0xfc1: mov    BYTE PTR [rsp+0xac],0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 738734374913ULL);
x86_l_fc9:
	/* 0xfc9: mov    r12,QWORD PTR [rsp+0xb0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_fd1:
	/* 0xfd1: mov    rcx,QWORD PTR [rsp+0xa0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_fd9:
	/* 0xfd9: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_fde:
	/* 0xfde: cmp    rcx,rdx */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_fe1:
	/* 0xfe1: je     1016 <generic_kprobe_process_event+0x1016> */
	X86_SIM_X86_JCC(X86_CC_E, 0xfe1, 0x1016, x86_l_1016);
x86_l_fe3:
	/* 0xfe3: xor    ebp,ebp */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_fe5:
	/* 0xfe5: cmp    BYTE PTR [rsp+0xac],0x0 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_fed:
	/* 0xfed: sete   dl */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_CC_E, 0);
x86_l_ff0:
	/* 0xff0: mov    esi,DWORD PTR [rsp+0xa8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_ff7:
	/* 0xff7: mov    eax,0x1000 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 4096ULL);
x86_l_ffc:
	/* 0xffc: sub    eax,esi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_SUB, 0);
x86_l_ffe:
	/* 0xffe: test   esi,esi */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_1000:
	/* 0x1000: cmovle eax,esi */
	X86_SIM_RUN_OP(X86_OP_CMOV, X86_RAX, X86_RSI, X86_WIDTH_32, X86_CC_LE, 0);
x86_l_1003:
	/* 0x1003: test   rcx,rcx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_1006:
	/* 0x1006: je     1094 <generic_kprobe_process_event+0x1094> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1006, 0x1094, x86_l_1094);
x86_l_100c:
	/* 0x100c: mov    bpl,dl */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RBP, X86_RDX, X86_WIDTH_8, 0, 0);
x86_l_100f:
	/* 0x100f: add    ebp,ebp */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_ADD, 0);
x86_l_1011:
	/* 0x1011: mov    rdx,rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_1014:
	/* 0x1014: jmp    101a <generic_kprobe_process_event+0x101a> */
	X86_SIM_X86_JMP(0x1014, 0x101a, x86_l_101a);
x86_l_1016:
	/* 0x1016: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1018:
	/* 0x1018: xor    ebp,ebp */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_101a:
	/* 0x101a: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_101f:
	/* 0x101f: lea    rdi,[rcx+0x4] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1023:
	/* 0x1023: mov    r15d,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R15, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_1026:
	/* 0x1026: and    r15d,0xfff */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_102d:
	/* 0x102d: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_1030:
	/* 0x1030: jns    108a <generic_kprobe_process_event+0x108a> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1030, 0x108a, x86_l_108a);
x86_l_1032:
	/* 0x1032: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_1035:
	/* 0x1035: jns    10a1 <generic_kprobe_process_event+0x10a1> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1035, 0x10a1, x86_l_10a1);
x86_l_1037:
	/* 0x1037: mov    r9,rdx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R9, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_103a:
	/* 0x103a: xor    edx,edx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_103c:
	/* 0x103c: cmp    r15d,0x8 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_1040:
	/* 0x1040: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1045:
	/* 0x1045: jb     1067 <generic_kprobe_process_event+0x1067> */
	X86_SIM_X86_JCC(X86_CC_B, 0x1045, 0x1067, x86_l_1067);
x86_l_1047:
	/* 0x1047: mov    esi,r15d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_R15, X86_WIDTH_32, 0, 0);
x86_l_104a:
	/* 0x104a: xor    edx,edx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_104c:
	/* 0x104c: mov    r10,r9 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R10, X86_R9, X86_WIDTH_64, 0, 0);
x86_l_104f:
	/* 0x104f: mov    r8,rdx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R8, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_1052:
	/* 0x1052: mov    rdx,QWORD PTR [r10+rdx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_R10, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_1056:
	/* 0x1056: mov    QWORD PTR [rdi+r8*1],rdx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_R8, 0), 0ULL);
x86_l_105a:
	/* 0x105a: lea    rdx,[r8+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_105e:
	/* 0x105e: add    r8,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1062:
	/* 0x1062: cmp    r8,rsi */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_R8, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_1065:
	/* 0x1065: jbe    104f <generic_kprobe_process_event+0x104f> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x1065, 0x104f, x86_l_104f);
x86_l_1067:
	/* 0x1067: test   al,0x4 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, 0, 4ULL);
x86_l_1069:
	/* 0x1069: jne    1103 <generic_kprobe_process_event+0x1103> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1069, 0x1103, x86_l_1103);
x86_l_106f:
	/* 0x106f: test   al,0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, 0, 2ULL);
x86_l_1071:
	/* 0x1071: jne    1118 <generic_kprobe_process_event+0x1118> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1071, 0x1118, x86_l_1118);
x86_l_1077:
	/* 0x1077: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_107c:
	/* 0x107c: mov    r8,QWORD PTR [rsp+0x30] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1081:
	/* 0x1081: test   al,0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_1083:
	/* 0x1083: je     10ba <generic_kprobe_process_event+0x10ba> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1083, 0x10ba, x86_l_10ba);
x86_l_1085:
	/* 0x1085: jmp    1135 <generic_kprobe_process_event+0x1135> */
	X86_SIM_X86_JMP(0x1085, 0x1135, x86_l_1135);
x86_l_108a:
	/* 0x108a: mov    esi,r15d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_R15, X86_WIDTH_32, 0, 0);
x86_l_108d:
	/* 0x108d: call   1292 <generic_kprobe_process_event+0x1292> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_1092:
	/* 0x1092: jmp    10ab <generic_kprobe_process_event+0x10ab> */
	X86_SIM_X86_JMP(0x1092, 0x10ab, x86_l_10ab);
x86_l_1094:
	/* 0x1094: xor    r15d,r15d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1097:
	/* 0x1097: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_109c:
	/* 0x109c: jmp    4258 <generic_kprobe_process_event+0x4258> */
	X86_SIM_X86_JMP(0x109c, 0x4258, x86_l_4258);
x86_l_10a1:
	/* 0x10a1: mov    edx,r15d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R15, X86_WIDTH_32, 0, 0);
x86_l_10a4:
	/* 0x10a4: xor    esi,esi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_10a6:
	/* 0x10a6: call   4f97 <__native_link_local_memset_zero_dynamic> */
	X86_SIM_X86_CALL(x86_l_4f97, 0x10abULL);
x86_l_10ab:
	/* 0x10ab: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10b0:
	/* 0x10b0: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_10b5:
	/* 0x10b5: mov    r8,QWORD PTR [rsp+0x30] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_10ba:
	/* 0x10ba: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10bf:
	/* 0x10bf: mov    DWORD PTR [rdx],r15d */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10c2:
	/* 0x10c2: test   r8,r8 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R8, X86_R8, X86_WIDTH_64, 0, 0);
x86_l_10c5:
	/* 0x10c5: jns    10cc <generic_kprobe_process_event+0x10cc> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x10c5, 0x10cc, x86_l_10cc);
x86_l_10c7:
	/* 0x10c7: mov    rax,QWORD PTR [r8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10ca:
	/* 0x10ca: jmp    10ce <generic_kprobe_process_event+0x10ce> */
	X86_SIM_X86_JMP(0x10ca, 0x10ce, x86_l_10ce);
x86_l_10cc:
	/* 0x10cc: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_10ce:
	/* 0x10ce: add    rax,0x30 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_10d2:
	/* 0x10d2: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_10d5:
	/* 0x10d5: jns    10dc <generic_kprobe_process_event+0x10dc> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x10d5, 0x10dc, x86_l_10dc);
x86_l_10d7:
	/* 0x10d7: mov    rax,QWORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10da:
	/* 0x10da: jmp    10de <generic_kprobe_process_event+0x10de> */
	X86_SIM_X86_JMP(0x10da, 0x10de, x86_l_10de);
x86_l_10dc:
	/* 0x10dc: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_10de:
	/* 0x10de: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_10e1:
	/* 0x10e1: jns    10e8 <generic_kprobe_process_event+0x10e8> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x10e1, 0x10e8, x86_l_10e8);
x86_l_10e3:
	/* 0x10e3: movzx  eax,WORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_10e6:
	/* 0x10e6: jmp    10ea <generic_kprobe_process_event+0x10ea> */
	X86_SIM_X86_JMP(0x10e6, 0x10ea, x86_l_10ea);
x86_l_10e8:
	/* 0x10e8: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_10ea:
	/* 0x10ea: mov    DWORD PTR [rdx+r15*1+0x4],ebp */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 4ULL);
x86_l_10ef:
	/* 0x10ef: mov    WORD PTR [rdx+r15*1+0x8],ax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 8ULL);
x86_l_10f5:
	/* 0x10f5: add    r15d,0xa */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 10ULL);
x86_l_10f9:
	/* 0x10f9: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_10fe:
	/* 0x10fe: jmp    4253 <generic_kprobe_process_event+0x4253> */
	X86_SIM_X86_JMP(0x10fe, 0x4253, x86_l_4253);
x86_l_1103:
	/* 0x1103: mov    esi,edx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_1105:
	/* 0x1105: mov    r8d,DWORD PTR [r9+rsi*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R8, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_1109:
	/* 0x1109: mov    DWORD PTR [rdi+rsi*1],r8d */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_110d:
	/* 0x110d: or     edx,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_OR, 4ULL);
x86_l_1110:
	/* 0x1110: test   al,0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, 0, 2ULL);
x86_l_1112:
	/* 0x1112: je     1077 <generic_kprobe_process_event+0x1077> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1112, 0x1077, x86_l_1077);
x86_l_1118:
	/* 0x1118: mov    esi,edx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_111a:
	/* 0x111a: movzx  r8d,WORD PTR [r9+rsi*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R8, X86_R9, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_16), 0ULL);
x86_l_111f:
	/* 0x111f: mov    WORD PTR [rdi+rsi*1],r8w */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_R8, X86_WIDTH_16, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_1124:
	/* 0x1124: add    edx,0x2 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_1127:
	/* 0x1127: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_112c:
	/* 0x112c: mov    r8,QWORD PTR [rsp+0x30] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1131:
	/* 0x1131: test   al,0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_1133:
	/* 0x1133: je     10ba <generic_kprobe_process_event+0x10ba> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1133, 0x10ba, x86_l_10ba);
x86_l_1135:
	/* 0x1135: mov    eax,edx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_1137:
	/* 0x1137: movzx  edx,BYTE PTR [r9+rax*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_R9, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_113c:
	/* 0x113c: mov    BYTE PTR [rdi+rax*1],dl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RDX, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_113f:
	/* 0x113f: jmp    10ba <generic_kprobe_process_event+0x10ba> */
	X86_SIM_X86_JMP(0x113f, 0x10ba, x86_l_10ba);
x86_l_1144:
	/* 0x1144: lea    rax,[rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1149:
	/* 0x1149: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_114c:
	/* 0x114c: jns    11e0 <generic_kprobe_process_event+0x11e0> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x114c, 0x11e0, x86_l_11e0);
x86_l_1152:
	/* 0x1152: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_1155:
	/* 0x1155: jns    1626 <generic_kprobe_process_event+0x1626> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1155, 0x1626, x86_l_1626);
x86_l_115b:
	/* 0x115b: mov    eax,DWORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_115d:
	/* 0x115d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1162:
	/* 0x1162: mov    DWORD PTR [rdx],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1164:
	/* 0x1164: mov    r15d,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_116a:
	/* 0x116a: jmp    4246 <generic_kprobe_process_event+0x4246> */
	X86_SIM_X86_JMP(0x116a, 0x4246, x86_l_4246);
x86_l_116f:
	/* 0x116f: lea    rax,[rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1174:
	/* 0x1174: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_1177:
	/* 0x1177: jns    121d <generic_kprobe_process_event+0x121d> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1177, 0x121d, x86_l_121d);
x86_l_117d:
	/* 0x117d: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_1180:
	/* 0x1180: jns    19bf <generic_kprobe_process_event+0x19bf> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1180, 0x19bf, x86_l_19bf);
x86_l_1186:
	/* 0x1186: movzx  eax,WORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1189:
	/* 0x1189: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_118e:
	/* 0x118e: mov    WORD PTR [rcx],ax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1191:
	/* 0x1191: jmp    19d3 <generic_kprobe_process_event+0x19d3> */
	X86_SIM_X86_JMP(0x1191, 0x19d3, x86_l_19d3);
x86_l_1196:
	/* 0x1196: lea    rdx,[rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_119b:
	/* 0x119b: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11a0:
	/* 0x11a0: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_11a5:
	/* 0x11a5: call   13aa <generic_kprobe_process_event+0x13aa> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_11aa:
	/* 0x11aa: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11af:
	/* 0x11af: mov    r15d,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_11b5:
	/* 0x11b5: jmp    4246 <generic_kprobe_process_event+0x4246> */
	X86_SIM_X86_JMP(0x11b5, 0x4246, x86_l_4246);
x86_l_11ba:
	/* 0x11ba: lea    rax,[rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_11bf:
	/* 0x11bf: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_11c2:
	/* 0x11c2: jns    124d <generic_kprobe_process_event+0x124d> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x11c2, 0x124d, x86_l_124d);
x86_l_11c8:
	/* 0x11c8: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_11cb:
	/* 0x11cb: jns    19cb <generic_kprobe_process_event+0x19cb> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x11cb, 0x19cb, x86_l_19cb);
x86_l_11d1:
	/* 0x11d1: movzx  eax,BYTE PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_11d4:
	/* 0x11d4: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11d9:
	/* 0x11d9: mov    BYTE PTR [rcx],al */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11db:
	/* 0x11db: jmp    19d3 <generic_kprobe_process_event+0x19d3> */
	X86_SIM_X86_JMP(0x11db, 0x19d3, x86_l_19d3);
x86_l_11e0:
	/* 0x11e0: lea    rdx,[rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_11e5:
	/* 0x11e5: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11ea:
	/* 0x11ea: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_11ef:
	/* 0x11ef: call   13f4 <generic_kprobe_process_event+0x13f4> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_11f4:
	/* 0x11f4: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11f9:
	/* 0x11f9: mov    r15d,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_11ff:
	/* 0x11ff: jmp    4246 <generic_kprobe_process_event+0x4246> */
	X86_SIM_X86_JMP(0x11ff, 0x4246, x86_l_4246);
x86_l_1204:
	/* 0x1204: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_1207:
	/* 0x1207: jns    19a3 <generic_kprobe_process_event+0x19a3> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1207, 0x19a3, x86_l_19a3);
x86_l_120d:
	/* 0x120d: mov    rax,QWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1210:
	/* 0x1210: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1215:
	/* 0x1215: mov    QWORD PTR [rcx],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1218:
	/* 0x1218: jmp    19af <generic_kprobe_process_event+0x19af> */
	X86_SIM_X86_JMP(0x1218, 0x19af, x86_l_19af);
x86_l_121d:
	/* 0x121d: lea    rdx,[rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1222:
	/* 0x1222: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1227:
	/* 0x1227: mov    esi,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_122c:
	/* 0x122c: call   1431 <generic_kprobe_process_event+0x1431> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_1231:
	/* 0x1231: jmp    19d3 <generic_kprobe_process_event+0x19d3> */
	X86_SIM_X86_JMP(0x1231, 0x19d3, x86_l_19d3);
x86_l_1236:
	/* 0x1236: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_123b:
	/* 0x123b: mov    QWORD PTR [rax],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1242:
	/* 0x1242: mov    r15d,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_1248:
	/* 0x1248: jmp    4246 <generic_kprobe_process_event+0x4246> */
	X86_SIM_X86_JMP(0x1248, 0x4246, x86_l_4246);
x86_l_124d:
	/* 0x124d: lea    rdx,[rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1252:
	/* 0x1252: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1257:
	/* 0x1257: mov    esi,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_125c:
	/* 0x125c: call   1461 <generic_kprobe_process_event+0x1461> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_1261:
	/* 0x1261: jmp    19d3 <generic_kprobe_process_event+0x19d3> */
	X86_SIM_X86_JMP(0x1261, 0x19d3, x86_l_19d3);
x86_l_1266:
	/* 0x1266: mov    r15,QWORD PTR [rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_126b:
	/* 0x126b: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1270:
	/* 0x1270: mov    QWORD PTR [rdi+0x10],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1278:
	/* 0x1278: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1280:
	/* 0x1280: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1287:
	/* 0x1287: test   r15,r15 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_128a:
	/* 0x128a: js     1a60 <generic_kprobe_process_event+0x1a60> */
	X86_SIM_X86_JCC(X86_CC_S, 0x128a, 0x1a60, x86_l_1a60);
x86_l_1290:
	/* 0x1290: mov    esi,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_1295:
	/* 0x1295: mov    rdx,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_1298:
	/* 0x1298: call   149d <generic_kprobe_process_event+0x149d> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_129d:
	/* 0x129d: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_12a0:
	/* 0x12a0: js     3d45 <generic_kprobe_process_event+0x3d45> */
	X86_SIM_X86_JCC(X86_CC_S, 0x12a0, 0x3d45, x86_l_3d45);
x86_l_12a6:
	/* 0x12a6: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12ab:
	/* 0x12ab: movzx  eax,WORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_12ae:
	/* 0x12ae: jmp    1a77 <generic_kprobe_process_event+0x1a77> */
	X86_SIM_X86_JMP(0x12ae, 0x1a77, x86_l_1a77);
x86_l_12b3:
	/* 0x12b3: mov    r13,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R13, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_12b6:
	/* 0x12b6: mov    r15,QWORD PTR [rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_12bb:
	/* 0x12bb: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12c0:
	/* 0x12c0: mov    QWORD PTR [rax+0x28],r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_12c4:
	/* 0x12c4: lea    rdi,[rax+0x26] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_12c8:
	/* 0x12c8: mov    rdx,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_12cb:
	/* 0x12cb: add    rdx,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_12cf:
	/* 0x12cf: jns    19e3 <generic_kprobe_process_event+0x19e3> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x12cf, 0x19e3, x86_l_19e3);
x86_l_12d5:
	/* 0x12d5: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_12d8:
	/* 0x12d8: jns    1f60 <generic_kprobe_process_event+0x1f60> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x12d8, 0x1f60, x86_l_1f60);
x86_l_12de:
	/* 0x12de: movzx  eax,WORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_12e1:
	/* 0x12e1: mov    WORD PTR [rdi],ax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12e4:
	/* 0x12e4: jmp    1f65 <generic_kprobe_process_event+0x1f65> */
	X86_SIM_X86_JMP(0x12e4, 0x1f65, x86_l_1f65);
x86_l_12e9:
	/* 0x12e9: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_12ee:
	/* 0x12ee: movzx  edx,ax */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_RDX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_12f1:
	/* 0x12f1: shr    eax,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_12f4:
	/* 0x12f4: and    eax,0xfff */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_12f9:
	/* 0x12f9: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12fe:
	/* 0x12fe: lea    rdi,[rcx+0x4] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1302:
	/* 0x1302: lea    esi,[rax+0x1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_1305:
	/* 0x1305: add    rdx,rbp */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1308:
	/* 0x1308: jns    241b <generic_kprobe_process_event+0x241b> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1308, 0x241b, x86_l_241b);
x86_l_130e:
	/* 0x130e: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_1311:
	/* 0x1311: jns    20e8 <generic_kprobe_process_event+0x20e8> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1311, 0x20e8, x86_l_20e8);
x86_l_1317:
	/* 0x1317: xor    r8d,r8d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_131a:
	/* 0x131a: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_131f:
	/* 0x131f: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1324:
	/* 0x1324: cmp    rax,r8 */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RAX, X86_R8, X86_WIDTH_64, 0, 0);
x86_l_1327:
	/* 0x1327: je     2da0 <generic_kprobe_process_event+0x2da0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1327, 0x2da0, x86_l_2da0);
x86_l_132d:
	/* 0x132d: lea    r15,[r8+0x1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R15, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_1331:
	/* 0x1331: movzx  r9d,BYTE PTR [rdx+r8*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R9, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R8, 0, X86_WIDTH_8), 0ULL);
x86_l_1336:
	/* 0x1336: mov    BYTE PTR [rdi+r8*1],r9b */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_R9, X86_WIDTH_8, X86_MEM_AUX(X86_R8, 0), 0ULL);
x86_l_133a:
	/* 0x133a: mov    r8,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R8, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_133d:
	/* 0x133d: test   r9b,r9b */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R9, X86_R9, X86_WIDTH_8, 0, 0);
x86_l_1340:
	/* 0x1340: jne    1324 <generic_kprobe_process_event+0x1324> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1340, 0x1324, x86_l_1324);
x86_l_1342:
	/* 0x1342: jmp    2431 <generic_kprobe_process_event+0x2431> */
	X86_SIM_X86_JMP(0x1342, 0x2431, x86_l_2431);
x86_l_1347:
	/* 0x1347: lea    rax,[rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_134c:
	/* 0x134c: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_134f:
	/* 0x134f: jns    19f2 <generic_kprobe_process_event+0x19f2> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x134f, 0x19f2, x86_l_19f2);
x86_l_1355:
	/* 0x1355: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_1358:
	/* 0x1358: jns    20fd <generic_kprobe_process_event+0x20fd> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1358, 0x20fd, x86_l_20fd);
x86_l_135e:
	/* 0x135e: mov    rdx,QWORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1361:
	/* 0x1361: mov    QWORD PTR [rsp+0x70],rdx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1366:
	/* 0x1366: jmp    1a0b <generic_kprobe_process_event+0x1a0b> */
	X86_SIM_X86_JMP(0x1366, 0x1a0b, x86_l_1a0b);
x86_l_136b:
	/* 0x136b: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1370:
	/* 0x1370: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1375:
	/* 0x1375: lea    rdi,[rax+0x28] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1379:
	/* 0x1379: mov    QWORD PTR [rsp+0x30],rdx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_137e:
	/* 0x137e: add    rdx,0x98 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 152ULL);
x86_l_1385:
	/* 0x1385: jns    1a2a <generic_kprobe_process_event+0x1a2a> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1385, 0x1a2a, x86_l_1a2a);
x86_l_138b:
	/* 0x138b: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_138e:
	/* 0x138e: jns    211c <generic_kprobe_process_event+0x211c> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x138e, 0x211c, x86_l_211c);
x86_l_1394:
	/* 0x1394: mov    eax,DWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1396:
	/* 0x1396: mov    DWORD PTR [rdi],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1398:
	/* 0x1398: jmp    2122 <generic_kprobe_process_event+0x2122> */
	X86_SIM_X86_JMP(0x1398, 0x2122, x86_l_2122);
x86_l_139d:
	/* 0x139d: mov    r15,QWORD PTR [rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_13a2:
	/* 0x13a2: mov    BYTE PTR [rsp+0x70],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_13a7:
	/* 0x13a7: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_13ac:
	/* 0x13ac: mov    QWORD PTR [rdi+0x68],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_13b4:
	/* 0x13b4: mov    QWORD PTR [rdi+0x60],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_13bc:
	/* 0x13bc: mov    QWORD PTR [rdi+0x58],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_13c4:
	/* 0x13c4: mov    QWORD PTR [rdi+0x50],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_13cc:
	/* 0x13cc: mov    QWORD PTR [rdi+0x48],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_13d4:
	/* 0x13d4: mov    QWORD PTR [rdi+0x40],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_13dc:
	/* 0x13dc: mov    QWORD PTR [rdi+0x38],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_13e4:
	/* 0x13e4: mov    QWORD PTR [rdi+0x30],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_13ec:
	/* 0x13ec: mov    QWORD PTR [rdi+0x28],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_13f4:
	/* 0x13f4: mov    QWORD PTR [rdi+0x20],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_13fc:
	/* 0x13fc: mov    QWORD PTR [rdi+0x18],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1404:
	/* 0x1404: mov    QWORD PTR [rdi+0x10],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_140c:
	/* 0x140c: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1414:
	/* 0x1414: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_141b:
	/* 0x141b: test   r15,r15 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_141e:
	/* 0x141e: js     1aae <generic_kprobe_process_event+0x1aae> */
	X86_SIM_X86_JCC(X86_CC_S, 0x141e, 0x1aae, x86_l_1aae);
x86_l_1424:
	/* 0x1424: mov    esi,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_1429:
	/* 0x1429: mov    rdx,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_142c:
	/* 0x142c: call   1631 <generic_kprobe_process_event+0x1631> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_1431:
	/* 0x1431: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_1434:
	/* 0x1434: jns    1ac5 <generic_kprobe_process_event+0x1ac5> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1434, 0x1ac5, x86_l_1ac5);
x86_l_143a:
	/* 0x143a: jmp    4236 <generic_kprobe_process_event+0x4236> */
	X86_SIM_X86_JMP(0x143a, 0x4236, x86_l_4236);
x86_l_143f:
	/* 0x143f: mov    r13,rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R13, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_1442:
	/* 0x1442: mov    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_144b:
	/* 0x144b: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_1454:
	/* 0x1454: call   1659 <generic_kprobe_process_event+0x1659> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_get_current_pid_tgid);
x86_l_1459:
	/* 0x1459: shr    rax,0x20 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_145d:
	/* 0x145d: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1462:
	/* 0x1462: lea    rax,[rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1467:
	/* 0x1467: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_146a:
	/* 0x146a: jns    1a39 <generic_kprobe_process_event+0x1a39> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x146a, 0x1a39, x86_l_1a39);
x86_l_1470:
	/* 0x1470: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_1473:
	/* 0x1473: jns    231a <generic_kprobe_process_event+0x231a> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1473, 0x231a, x86_l_231a);
x86_l_1479:
	/* 0x1479: mov    eax,DWORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_147b:
	/* 0x147b: mov    DWORD PTR [rsp+0x60],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_147f:
	/* 0x147f: jmp    2324 <generic_kprobe_process_event+0x2324> */
	X86_SIM_X86_JMP(0x147f, 0x2324, x86_l_2324);
x86_l_1484:
	/* 0x1484: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1489:
	/* 0x1489: lea    rdi,[rax+0x4] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_148d:
	/* 0x148d: mov    edx,0x118 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 280ULL);
x86_l_1492:
	/* 0x1492: add    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_ALU_MEM, X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 64ULL);
x86_l_1497:
	/* 0x1497: jns    1a56 <generic_kprobe_process_event+0x1a56> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1497, 0x1a56, x86_l_1a56);
x86_l_149d:
	/* 0x149d: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_14a0:
	/* 0x14a0: jns    2389 <generic_kprobe_process_event+0x2389> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x14a0, 0x2389, x86_l_2389);
x86_l_14a6:
	/* 0x14a6: movzx  eax,BYTE PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_14a9:
	/* 0x14a9: mov    BYTE PTR [rdi],al */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14ab:
	/* 0x14ab: test   al,al */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8, 0, 0);
x86_l_14ad:
	/* 0x14ad: je     320f <generic_kprobe_process_event+0x320f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x14ad, 0x320f, x86_l_320f);
x86_l_14b3:
	/* 0x14b3: movzx  eax,BYTE PTR [rdx+0x1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 1ULL);
x86_l_14b7:
	/* 0x14b7: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14bc:
	/* 0x14bc: mov    BYTE PTR [rcx+0x5],al */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_14bf:
	/* 0x14bf: test   al,al */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8, 0, 0);
x86_l_14c1:
	/* 0x14c1: je     3acc <generic_kprobe_process_event+0x3acc> */
	X86_SIM_X86_JCC(X86_CC_E, 0x14c1, 0x3acc, x86_l_3acc);
x86_l_14c7:
	/* 0x14c7: movzx  eax,BYTE PTR [rdx+0x2] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 2ULL);
x86_l_14cb:
	/* 0x14cb: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14d0:
	/* 0x14d0: mov    BYTE PTR [rcx+0x6],al */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_14d3:
	/* 0x14d3: test   al,al */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8, 0, 0);
x86_l_14d5:
	/* 0x14d5: je     3e33 <generic_kprobe_process_event+0x3e33> */
	X86_SIM_X86_JCC(X86_CC_E, 0x14d5, 0x3e33, x86_l_3e33);
x86_l_14db:
	/* 0x14db: movzx  eax,BYTE PTR [rdx+0x3] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 3ULL);
x86_l_14df:
	/* 0x14df: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14e4:
	/* 0x14e4: mov    BYTE PTR [rcx+0x7],al */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 7ULL);
x86_l_14e7:
	/* 0x14e7: test   al,al */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8, 0, 0);
x86_l_14e9:
	/* 0x14e9: je     42ce <generic_kprobe_process_event+0x42ce> */
	X86_SIM_X86_JCC(X86_CC_E, 0x14e9, 0x42ce, x86_l_42ce);
x86_l_14ef:
	/* 0x14ef: movzx  eax,BYTE PTR [rdx+0x4] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 4ULL);
x86_l_14f3:
	/* 0x14f3: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14f8:
	/* 0x14f8: mov    BYTE PTR [rcx+0x8],al */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14fb:
	/* 0x14fb: test   al,al */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8, 0, 0);
x86_l_14fd:
	/* 0x14fd: je     42d9 <generic_kprobe_process_event+0x42d9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x14fd, 0x42d9, x86_l_42d9);
x86_l_1503:
	/* 0x1503: movzx  eax,BYTE PTR [rdx+0x5] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_1507:
	/* 0x1507: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_150c:
	/* 0x150c: mov    BYTE PTR [rcx+0x9],al */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 9ULL);
x86_l_150f:
	/* 0x150f: test   al,al */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8, 0, 0);
x86_l_1511:
	/* 0x1511: je     4305 <generic_kprobe_process_event+0x4305> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1511, 0x4305, x86_l_4305);
x86_l_1517:
	/* 0x1517: movzx  eax,BYTE PTR [rdx+0x6] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_151b:
	/* 0x151b: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1520:
	/* 0x1520: mov    BYTE PTR [rcx+0xa],al */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 10ULL);
x86_l_1523:
	/* 0x1523: test   al,al */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8, 0, 0);
x86_l_1525:
	/* 0x1525: je     437a <generic_kprobe_process_event+0x437a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1525, 0x437a, x86_l_437a);
x86_l_152b:
	/* 0x152b: movzx  eax,BYTE PTR [rdx+0x7] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_152f:
	/* 0x152f: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1534:
	/* 0x1534: mov    BYTE PTR [rcx+0xb],al */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 11ULL);
x86_l_1537:
	/* 0x1537: test   al,al */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8, 0, 0);
x86_l_1539:
	/* 0x1539: je     43dc <generic_kprobe_process_event+0x43dc> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1539, 0x43dc, x86_l_43dc);
x86_l_153f:
	/* 0x153f: movzx  eax,BYTE PTR [rdx+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_1543:
	/* 0x1543: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1548:
	/* 0x1548: mov    BYTE PTR [rcx+0xc],al */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_154b:
	/* 0x154b: test   al,al */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8, 0, 0);
x86_l_154d:
	/* 0x154d: je     4442 <generic_kprobe_process_event+0x4442> */
	X86_SIM_X86_JCC(X86_CC_E, 0x154d, 0x4442, x86_l_4442);
x86_l_1553:
	/* 0x1553: movzx  eax,BYTE PTR [rdx+0x9] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 9ULL);
x86_l_1557:
	/* 0x1557: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_155c:
	/* 0x155c: mov    BYTE PTR [rcx+0xd],al */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 13ULL);
x86_l_155f:
	/* 0x155f: test   al,al */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8, 0, 0);
x86_l_1561:
	/* 0x1561: je     4466 <generic_kprobe_process_event+0x4466> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1561, 0x4466, x86_l_4466);
x86_l_1567:
	/* 0x1567: movzx  eax,BYTE PTR [rdx+0xa] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 10ULL);
x86_l_156b:
	/* 0x156b: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1570:
	/* 0x1570: mov    BYTE PTR [rcx+0xe],al */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_1573:
	/* 0x1573: test   al,al */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8, 0, 0);
x86_l_1575:
	/* 0x1575: je     4471 <generic_kprobe_process_event+0x4471> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1575, 0x4471, x86_l_4471);
x86_l_157b:
	/* 0x157b: movzx  eax,BYTE PTR [rdx+0xb] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 11ULL);
x86_l_157f:
	/* 0x157f: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1584:
	/* 0x1584: mov    BYTE PTR [rcx+0xf],al */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 15ULL);
x86_l_1587:
	/* 0x1587: test   al,al */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8, 0, 0);
x86_l_1589:
	/* 0x1589: je     447c <generic_kprobe_process_event+0x447c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1589, 0x447c, x86_l_447c);
x86_l_158f:
	/* 0x158f: movzx  eax,BYTE PTR [rdx+0xc] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 12ULL);
x86_l_1593:
	/* 0x1593: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1598:
	/* 0x1598: mov    BYTE PTR [rcx+0x10],al */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_159b:
	/* 0x159b: test   al,al */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8, 0, 0);
x86_l_159d:
	/* 0x159d: je     44f8 <generic_kprobe_process_event+0x44f8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x159d, 0x44f8, x86_l_44f8);
x86_l_15a3:
	/* 0x15a3: movzx  eax,BYTE PTR [rdx+0xd] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 13ULL);
x86_l_15a7:
	/* 0x15a7: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15ac:
	/* 0x15ac: mov    BYTE PTR [rcx+0x11],al */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17ULL);
x86_l_15af:
	/* 0x15af: test   al,al */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8, 0, 0);
x86_l_15b1:
	/* 0x15b1: je     459f <generic_kprobe_process_event+0x459f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x15b1, 0x459f, x86_l_459f);
x86_l_15b7:
	/* 0x15b7: movzx  eax,BYTE PTR [rdx+0xe] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 14ULL);
x86_l_15bb:
	/* 0x15bb: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15c0:
	/* 0x15c0: mov    BYTE PTR [rcx+0x12],al */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_15c3:
	/* 0x15c3: test   al,al */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8, 0, 0);
x86_l_15c5:
	/* 0x15c5: je     45a7 <generic_kprobe_process_event+0x45a7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x15c5, 0x45a7, x86_l_45a7);
x86_l_15cb:
	/* 0x15cb: movzx  eax,BYTE PTR [rdx+0xf] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 15ULL);
x86_l_15cf:
	/* 0x15cf: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15d4:
	/* 0x15d4: mov    BYTE PTR [rcx+0x13],al */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 19ULL);
x86_l_15d7:
	/* 0x15d7: test   al,al */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8, 0, 0);
x86_l_15d9:
	/* 0x15d9: je     45c8 <generic_kprobe_process_event+0x45c8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x15d9, 0x45c8, x86_l_45c8);
x86_l_15df:
	/* 0x15df: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15e4:
	/* 0x15e4: mov    BYTE PTR [rax+0x14],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_15e8:
	/* 0x15e8: mov    r15d,0x11 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_15ee:
	/* 0x15ee: jmp    45ce <generic_kprobe_process_event+0x45ce> */
	X86_SIM_X86_JMP(0x15ee, 0x45ce, x86_l_45ce);
x86_l_15f3:
	/* 0x15f3: mov    r13,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R13, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_15f6:
	/* 0x15f6: mov    r15,QWORD PTR [rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_15fb:
	/* 0x15fb: test   r15,r15 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_15fe:
	/* 0x15fe: js     1b2e <generic_kprobe_process_event+0x1b2e> */
	X86_SIM_X86_JCC(X86_CC_S, 0x15fe, 0x1b2e, x86_l_1b2e);
x86_l_1604:
	/* 0x1604: lea    rdi,[rsp+0xc0] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_160c:
	/* 0x160c: mov    esi,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_1611:
	/* 0x1611: mov    rdx,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_1614:
	/* 0x1614: call   1819 <generic_kprobe_process_event+0x1819> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_1619:
	/* 0x1619: movzx  eax,BYTE PTR [rsp+0xc0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 192ULL);
x86_l_1621:
	/* 0x1621: jmp    1b44 <generic_kprobe_process_event+0x1b44> */
	X86_SIM_X86_JMP(0x1621, 0x1b44, x86_l_1b44);
x86_l_1626:
	/* 0x1626: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_162b:
	/* 0x162b: mov    DWORD PTR [rax],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1631:
	/* 0x1631: mov    r15d,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_1637:
	/* 0x1637: jmp    4246 <generic_kprobe_process_event+0x4246> */
	X86_SIM_X86_JMP(0x1637, 0x4246, x86_l_4246);
x86_l_163c:
	/* 0x163c: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1641:
	/* 0x1641: mov    QWORD PTR [rax+0x48],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1649:
	/* 0x1649: mov    QWORD PTR [rax+0x40],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_1651:
	/* 0x1651: mov    QWORD PTR [rax+0x38],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1659:
	/* 0x1659: mov    QWORD PTR [rax+0x30],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1661:
	/* 0x1661: mov    QWORD PTR [rax+0x28],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1669:
	/* 0x1669: mov    QWORD PTR [rax+0x20],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1671:
	/* 0x1671: mov    QWORD PTR [rax+0x18],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1679:
	/* 0x1679: mov    QWORD PTR [rax+0x10],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1681:
	/* 0x1681: mov    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1689:
	/* 0x1689: mov    QWORD PTR [rax],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1690:
	/* 0x1690: lea    rdi,[rax+0x10] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1694:
	/* 0x1694: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1699:
	/* 0x1699: add    rdx,0x18 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_169d:
	/* 0x169d: jns    1b78 <generic_kprobe_process_event+0x1b78> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x169d, 0x1b78, x86_l_1b78);
x86_l_16a3:
	/* 0x16a3: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_16a6:
	/* 0x16a6: jns    2d0c <generic_kprobe_process_event+0x2d0c> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x16a6, 0x2d0c, x86_l_2d0c);
x86_l_16ac:
	/* 0x16ac: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_16ae:
	/* 0x16ae: cmp    rax,0x3e */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, 0, 62ULL);
x86_l_16b2:
	/* 0x16b2: je     31c3 <generic_kprobe_process_event+0x31c3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x16b2, 0x31c3, x86_l_31c3);
x86_l_16b8:
	/* 0x16b8: movzx  ecx,BYTE PTR [rdx+rax*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_16bc:
	/* 0x16bc: mov    BYTE PTR [rdi+rax*1],cl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_16bf:
	/* 0x16bf: inc    rax */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_16c2:
	/* 0x16c2: test   cl,cl */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8, 0, 0);
x86_l_16c4:
	/* 0x16c4: jne    16ae <generic_kprobe_process_event+0x16ae> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x16c4, 0x16ae, x86_l_16ae);
x86_l_16c6:
	/* 0x16c6: jmp    31cc <generic_kprobe_process_event+0x31cc> */
	X86_SIM_X86_JMP(0x16c6, 0x31cc, x86_l_31cc);
x86_l_16cb:
	/* 0x16cb: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_16d0:
	/* 0x16d0: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_16d3:
	/* 0x16d3: js     1ec9 <generic_kprobe_process_event+0x1ec9> */
	X86_SIM_X86_JCC(X86_CC_S, 0x16d3, 0x1ec9, x86_l_1ec9);
x86_l_16d9:
	/* 0x16d9: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16de:
	/* 0x16de: mov    rdi,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_16e1:
	/* 0x16e1: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_16e6:
	/* 0x16e6: mov    r12,rdx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R12, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_16e9:
	/* 0x16e9: call   18ee <generic_kprobe_process_event+0x18ee> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_16ee:
	/* 0x16ee: jmp    2c48 <generic_kprobe_process_event+0x2c48> */
	X86_SIM_X86_JMP(0x16ee, 0x2c48, x86_l_2c48);
x86_l_16f3:
	/* 0x16f3: mov    r13,rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R13, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_16f6:
	/* 0x16f6: mov    rbx,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RBX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_16f9:
	/* 0x16f9: lea    rbp,[rax+0x90] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1700:
	/* 0x1700: and    r12d,0xf */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_1704:
	/* 0x1704: dec    r12d */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_1707:
	/* 0x1707: cmp    r12d,0x4 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_170b:
	/* 0x170b: ja     2e39 <generic_kprobe_process_event+0x2e39> */
	X86_SIM_X86_JCC(X86_CC_A, 0x170b, 0x2e39, x86_l_2e39);
x86_l_1711:
	/* Capture image-bound code identity before scheduled instructions. */
	switch (X86_SIM_L_READ_REG(X86_R12) << 2) {
	case 0ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x1721ULL); break;
	case 4ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x2de6ULL); break;
	case 8ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x2dd0ULL); break;
	case 12ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x2ddbULL); break;
	case 16ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x2dc5ULL); break;
	default: __x86_sim_unresolved_indirect_target();
	}
x86_l_171f:
	/* 0x171f: jmp    rcx */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RCX);
		switch (X86_SIM_L_REG_TAG(X86_RCX)) {
		case X86_SIM_TAG_CODE:
			switch (__x86_target) {
			case 0x1721ULL: goto x86_l_1721;
			case 0x2dc5ULL: goto x86_l_2dc5;
			case 0x2dd0ULL: goto x86_l_2dd0;
			case 0x2ddbULL: goto x86_l_2ddb;
			case 0x2de6ULL: goto x86_l_2de6;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_1721:
	/* 0x1721: mov    rax,rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_1724:
	/* 0x1724: add    rax,0x5e50 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 24144ULL);
x86_l_172a:
	/* 0x172a: jmp    2def <generic_kprobe_process_event+0x2def> */
	X86_SIM_X86_JMP(0x172a, 0x2def, x86_l_2def);
x86_l_172f:
	/* 0x172f: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_1738:
	/* 0x1738: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_173d:
	/* 0x173d: lea    r15,[rdx+0xd8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R15, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_1744:
	/* 0x1744: mov    r12,rdx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R12, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_1747:
	/* 0x1747: add    rdx,0x110 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 272ULL);
x86_l_174e:
	/* 0x174e: jns    1b90 <generic_kprobe_process_event+0x1b90> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x174e, 0x1b90, x86_l_1b90);
x86_l_1754:
	/* 0x1754: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_1757:
	/* 0x1757: jns    24ea <generic_kprobe_process_event+0x24ea> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1757, 0x24ea, x86_l_24ea);
x86_l_175d:
	/* 0x175d: mov    rdx,QWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1760:
	/* 0x1760: mov    QWORD PTR [rsp+0x70],rdx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1765:
	/* 0x1765: jmp    1ba4 <generic_kprobe_process_event+0x1ba4> */
	X86_SIM_X86_JMP(0x1765, 0x1ba4, x86_l_1ba4);
x86_l_176a:
	/* 0x176a: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_176f:
	/* 0x176f: and    r15d,0x3ff */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_1776:
	/* 0x1776: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_177b:
	/* 0x177b: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_177e:
	/* 0x177e: js     1ee7 <generic_kprobe_process_event+0x1ee7> */
	X86_SIM_X86_JCC(X86_CC_S, 0x177e, 0x1ee7, x86_l_1ee7);
x86_l_1784:
	/* 0x1784: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1789:
	/* 0x1789: mov    esi,r15d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_R15, X86_WIDTH_32, 0, 0);
x86_l_178c:
	/* 0x178c: call   1991 <generic_kprobe_process_event+0x1991> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_1791:
	/* 0x1791: jmp    2d4e <generic_kprobe_process_event+0x2d4e> */
	X86_SIM_X86_JMP(0x1791, 0x2d4e, x86_l_2d4e);
x86_l_1796:
	/* 0x1796: mov    rbx,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RBX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_1799:
	/* 0x1799: mov    rcx,QWORD PTR [rsp+0xb8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_17a1:
	/* 0x17a1: lea    rbp,[rax+rcx*1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_17a5:
	/* 0x17a5: add    rbp,0x90 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_17ac:
	/* 0x17ac: mov    QWORD PTR [rsp+0xc8],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 858993459200ULL);
x86_l_17b8:
	/* 0x17b8: test   r12b,0x10 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, 0, 16ULL);
x86_l_17bc:
	/* 0x17bc: jne    1bda <generic_kprobe_process_event+0x1bda> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x17bc, 0x1bda, x86_l_1bda);
x86_l_17c2:
	/* 0x17c2: mov    r12d,r12d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R12, X86_R12, X86_WIDTH_32, 0, 0);
x86_l_17c5:
	/* 0x17c5: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_17ca:
	/* 0x17ca: and    eax,0xf */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_17cd:
	/* 0x17cd: dec    eax */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_17cf:
	/* 0x17cf: cmp    eax,0x4 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_17d2:
	/* 0x17d2: ja     390e <generic_kprobe_process_event+0x390e> */
	X86_SIM_X86_JCC(X86_CC_A, 0x17d2, 0x390e, x86_l_390e);
x86_l_17d8:
	/* 0x17d8: mov    rcx,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_17db:
	/* Capture image-bound code identity before scheduled instructions. */
	switch (X86_SIM_L_READ_REG(X86_RCX) << 2) {
	case 0ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x17ebULL); break;
	case 4ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x38bcULL); break;
	case 8ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x38aaULL); break;
	case 12ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x38b3ULL); break;
	case 16ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x38a1ULL); break;
	default: __x86_sim_unresolved_indirect_target();
	}
x86_l_17e9:
	/* 0x17e9: jmp    rcx */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RCX);
		switch (X86_SIM_L_REG_TAG(X86_RCX)) {
		case X86_SIM_TAG_CODE:
			switch (__x86_target) {
			case 0x17ebULL: goto x86_l_17eb;
			case 0x38a1ULL: goto x86_l_38a1;
			case 0x38aaULL: goto x86_l_38aa;
			case 0x38b3ULL: goto x86_l_38b3;
			case 0x38bcULL: goto x86_l_38bc;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_17eb:
	/* 0x17eb: lea    rax,[rbx+0x5e50] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24144ULL);
x86_l_17f2:
	/* 0x17f2: jmp    38c3 <generic_kprobe_process_event+0x38c3> */
	X86_SIM_X86_JMP(0x17f2, 0x38c3, x86_l_38c3);
x86_l_17f7:
	/* 0x17f7: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_17fc:
	/* 0x17fc: add    rdx,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1800:
	/* 0x1800: jns    1c7a <generic_kprobe_process_event+0x1c7a> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1800, 0x1c7a, x86_l_1c7a);
x86_l_1806:
	/* 0x1806: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_1809:
	/* 0x1809: jns    25d2 <generic_kprobe_process_event+0x25d2> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1809, 0x25d2, x86_l_25d2);
x86_l_180f:
	/* 0x180f: mov    eax,DWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1811:
	/* 0x1811: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1816:
	/* 0x1816: mov    DWORD PTR [r15],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1819:
	/* 0x1819: jmp    25de <generic_kprobe_process_event+0x25de> */
	X86_SIM_X86_JMP(0x1819, 0x25de, x86_l_25de);
x86_l_181e:
	/* 0x181e: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1823:
	/* 0x1823: add    rdx,0x38 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 56ULL);
x86_l_1827:
	/* 0x1827: jns    1c91 <generic_kprobe_process_event+0x1c91> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1827, 0x1c91, x86_l_1c91);
x86_l_182d:
	/* 0x182d: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_1830:
	/* 0x1830: jns    2938 <generic_kprobe_process_event+0x2938> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1830, 0x2938, x86_l_2938);
x86_l_1836:
	/* 0x1836: mov    eax,DWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1838:
	/* 0x1838: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_183d:
	/* 0x183d: mov    DWORD PTR [r15],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1840:
	/* 0x1840: jmp    2944 <generic_kprobe_process_event+0x2944> */
	X86_SIM_X86_JMP(0x1840, 0x2944, x86_l_2944);
x86_l_1845:
	/* 0x1845: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_184a:
	/* 0x184a: add    rdx,0xc8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 200ULL);
x86_l_1851:
	/* 0x1851: jns    1ca8 <generic_kprobe_process_event+0x1ca8> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1851, 0x1ca8, x86_l_1ca8);
x86_l_1857:
	/* 0x1857: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_185a:
	/* 0x185a: jns    2a3c <generic_kprobe_process_event+0x2a3c> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x185a, 0x2a3c, x86_l_2a3c);
x86_l_1860:
	/* 0x1860: mov    eax,DWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1862:
	/* 0x1862: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1867:
	/* 0x1867: mov    DWORD PTR [r15],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_186a:
	/* 0x186a: jmp    2a48 <generic_kprobe_process_event+0x2a48> */
	X86_SIM_X86_JMP(0x186a, 0x2a48, x86_l_2a48);
x86_l_186f:
	/* 0x186f: mov    r13,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R13, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_1872:
	/* 0x1872: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1877:
	/* 0x1877: add    rdx,0x18 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_187b:
	/* 0x187b: jns    1cbf <generic_kprobe_process_event+0x1cbf> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x187b, 0x1cbf, x86_l_1cbf);
x86_l_1881:
	/* 0x1881: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_1884:
	/* 0x1884: jns    3f39 <generic_kprobe_process_event+0x3f39> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1884, 0x3f39, x86_l_3f39);
x86_l_188a:
	/* 0x188a: mov    rax,rdx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_188d:
	/* 0x188d: mov    r15,QWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R15, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1890:
	/* 0x1890: mov    QWORD PTR [rsp+0x70],r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1895:
	/* 0x1895: jmp    1cd3 <generic_kprobe_process_event+0x1cd3> */
	X86_SIM_X86_JMP(0x1895, 0x1cd3, x86_l_1cd3);
x86_l_189a:
	/* 0x189a: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_189f:
	/* 0x189f: mov    QWORD PTR [rax+0x48],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_18a7:
	/* 0x18a7: mov    QWORD PTR [rax+0x40],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_18af:
	/* 0x18af: mov    QWORD PTR [rax+0x38],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_18b7:
	/* 0x18b7: mov    QWORD PTR [rax+0x30],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_18bf:
	/* 0x18bf: mov    QWORD PTR [rax+0x28],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_18c7:
	/* 0x18c7: mov    QWORD PTR [rax+0x20],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_18cf:
	/* 0x18cf: mov    QWORD PTR [rax+0x18],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_18d7:
	/* 0x18d7: mov    QWORD PTR [rax+0x10],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_18df:
	/* 0x18df: mov    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_18e7:
	/* 0x18e7: mov    QWORD PTR [rax],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18ee:
	/* 0x18ee: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_18f3:
	/* 0x18f3: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_18f6:
	/* 0x18f6: jns    2d4b <generic_kprobe_process_event+0x2d4b> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x18f6, 0x2d4b, x86_l_2d4b);
x86_l_18fc:
	/* 0x18fc: mov    rdx,QWORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18ff:
	/* 0x18ff: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1904:
	/* 0x1904: lea    rdi,[rax+0x10] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1908:
	/* 0x1908: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_190b:
	/* 0x190b: js     2ce8 <generic_kprobe_process_event+0x2ce8> */
	X86_SIM_X86_JCC(X86_CC_S, 0x190b, 0x2ce8, x86_l_2ce8);
x86_l_1911:
	/* 0x1911: mov    esi,0x3f */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 63ULL);
x86_l_1916:
	/* 0x1916: call   1b1b <generic_kprobe_process_event+0x1b1b> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read_str);
x86_l_191b:
	/* 0x191b: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_191e:
	/* 0x191e: js     2d4b <generic_kprobe_process_event+0x2d4b> */
	X86_SIM_X86_JCC(X86_CC_S, 0x191e, 0x2d4b, x86_l_2d4b);
x86_l_1924:
	/* 0x1924: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1929:
	/* 0x1929: add    rax,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_192d:
	/* 0x192d: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_1930:
	/* 0x1930: jns    30c6 <generic_kprobe_process_event+0x30c6> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1930, 0x30c6, x86_l_30c6);
x86_l_1936:
	/* 0x1936: mov    rax,QWORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1939:
	/* 0x1939: jmp    30c8 <generic_kprobe_process_event+0x30c8> */
	X86_SIM_X86_JMP(0x1939, 0x30c8, x86_l_30c8);
x86_l_193e:
	/* 0x193e: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1943:
	/* 0x1943: mov    DWORD PTR [rax+0x4],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_194a:
	/* 0x194a: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_194f:
	/* 0x194f: mov    DWORD PTR [rax],edx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1951:
	/* 0x1951: mov    r15d,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_1957:
	/* 0x1957: jmp    2d5d <generic_kprobe_process_event+0x2d5d> */
	X86_SIM_X86_JMP(0x1957, 0x2d5d, x86_l_2d5d);
x86_l_195c:
	/* 0x195c: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1961:
	/* 0x1961: lea    rcx,[rsi+0x4] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1965:
	/* 0x1965: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1967:
	/* 0x1967: mov    edx,0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 0ULL);
x86_l_196c:
	/* 0x196c: test   rcx,rcx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_196f:
	/* 0x196f: jns    1973 <generic_kprobe_process_event+0x1973> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x196f, 0x1973, x86_l_1973);
x86_l_1971:
	/* 0x1971: mov    edx,DWORD PTR [rcx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1973:
	/* 0x1973: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1978:
	/* 0x1978: mov    DWORD PTR [rcx],edx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_197a:
	/* 0x197a: mov    rdx,rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_197d:
	/* 0x197d: lea    rcx,[rsi+0xc] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1981:
	/* 0x1981: test   rcx,rcx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_1984:
	/* 0x1984: jns    1988 <generic_kprobe_process_event+0x1988> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1984, 0x1988, x86_l_1988);
x86_l_1986:
	/* 0x1986: mov    eax,DWORD PTR [rcx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1988:
	/* 0x1988: mov    DWORD PTR [rdx+0x4],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_198b:
	/* 0x198b: add    rsi,0x50 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_198f:
	/* 0x198f: test   rsi,rsi */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_1992:
	/* 0x1992: jns    1d0a <generic_kprobe_process_event+0x1d0a> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1992, 0x1d0a, x86_l_1d0a);
x86_l_1998:
	/* 0x1998: mov    rax,rsi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_199b:
	/* 0x199b: mov    rax,QWORD PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_199e:
	/* 0x199e: jmp    1d0c <generic_kprobe_process_event+0x1d0c> */
	X86_SIM_X86_JMP(0x199e, 0x1d0c, x86_l_1d0c);
x86_l_19a3:
	/* 0x19a3: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19a8:
	/* 0x19a8: mov    QWORD PTR [rax],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19af:
	/* 0x19af: mov    r15d,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_19b5:
	/* 0x19b5: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_19ba:
	/* 0x19ba: jmp    2d58 <generic_kprobe_process_event+0x2d58> */
	X86_SIM_X86_JMP(0x19ba, 0x2d58, x86_l_2d58);
x86_l_19bf:
	/* 0x19bf: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19c4:
	/* 0x19c4: mov    WORD PTR [rax],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19c9:
	/* 0x19c9: jmp    19d3 <generic_kprobe_process_event+0x19d3> */
	X86_SIM_X86_JMP(0x19c9, 0x19d3, x86_l_19d3);
x86_l_19cb:
	/* 0x19cb: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19d0:
	/* 0x19d0: mov    BYTE PTR [rax],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19d3:
	/* 0x19d3: mov    r15d,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_19d9:
	/* 0x19d9: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_19de:
	/* 0x19de: jmp    4246 <generic_kprobe_process_event+0x4246> */
	X86_SIM_X86_JMP(0x19de, 0x4246, x86_l_4246);
x86_l_19e3:
	/* 0x19e3: mov    esi,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_19e8:
	/* 0x19e8: call   1bed <generic_kprobe_process_event+0x1bed> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_19ed:
	/* 0x19ed: jmp    1f65 <generic_kprobe_process_event+0x1f65> */
	X86_SIM_X86_JMP(0x19ed, 0x1f65, x86_l_1f65);
x86_l_19f2:
	/* 0x19f2: lea    rdi,[rsp+0x70] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_19f7:
	/* 0x19f7: lea    rdx,[rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_19fc:
	/* 0x19fc: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_1a01:
	/* 0x1a01: call   1c06 <generic_kprobe_process_event+0x1c06> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_1a06:
	/* 0x1a06: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1a0b:
	/* 0x1a0b: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_1a0e:
	/* 0x1a0e: jns    2108 <generic_kprobe_process_event+0x2108> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1a0e, 0x2108, x86_l_2108);
x86_l_1a14:
	/* 0x1a14: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_1a17:
	/* 0x1a17: jns    23f5 <generic_kprobe_process_event+0x23f5> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1a17, 0x23f5, x86_l_23f5);
x86_l_1a1d:
	/* 0x1a1d: mov    rax,QWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a20:
	/* 0x1a20: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1a25:
	/* 0x1a25: jmp    23fe <generic_kprobe_process_event+0x23fe> */
	X86_SIM_X86_JMP(0x1a25, 0x23fe, x86_l_23fe);
x86_l_1a2a:
	/* 0x1a2a: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_1a2f:
	/* 0x1a2f: call   1c34 <generic_kprobe_process_event+0x1c34> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_1a34:
	/* 0x1a34: jmp    2122 <generic_kprobe_process_event+0x2122> */
	X86_SIM_X86_JMP(0x1a34, 0x2122, x86_l_2122);
x86_l_1a39:
	/* 0x1a39: lea    rdi,[rsp+0x60] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1a3e:
	/* 0x1a3e: lea    rdx,[rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1a43:
	/* 0x1a43: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_1a48:
	/* 0x1a48: call   1c4d <generic_kprobe_process_event+0x1c4d> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_1a4d:
	/* 0x1a4d: mov    eax,DWORD PTR [rsp+0x60] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1a51:
	/* 0x1a51: jmp    2324 <generic_kprobe_process_event+0x2324> */
	X86_SIM_X86_JMP(0x1a51, 0x2324, x86_l_2324);
x86_l_1a56:
	/* 0x1a56: mov    esi,0x11 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_1a5b:
	/* 0x1a5b: jmp    241b <generic_kprobe_process_event+0x241b> */
	X86_SIM_X86_JMP(0x1a5b, 0x241b, x86_l_241b);
x86_l_1a60:
	/* 0x1a60: mov    rax,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_1a63:
	/* 0x1a63: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_1a66:
	/* 0x1a66: jns    23e0 <generic_kprobe_process_event+0x23e0> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1a66, 0x23e0, x86_l_23e0);
x86_l_1a6c:
	/* 0x1a6c: movzx  eax,WORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1a6f:
	/* 0x1a6f: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a74:
	/* 0x1a74: mov    WORD PTR [rcx],ax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a77:
	/* 0x1a77: cmp    ax,0xa */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, 0, 10ULL);
x86_l_1a7b:
	/* 0x1a7b: je     23a8 <generic_kprobe_process_event+0x23a8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a7b, 0x23a8, x86_l_23a8);
x86_l_1a81:
	/* 0x1a81: movzx  eax,ax */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_1a84:
	/* 0x1a84: cmp    eax,0x2 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_1a87:
	/* 0x1a87: jne    3d36 <generic_kprobe_process_event+0x3d36> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1a87, 0x3d36, x86_l_3d36);
x86_l_1a8d:
	/* 0x1a8d: mov    rdx,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_1a90:
	/* 0x1a90: add    rdx,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1a94:
	/* 0x1a94: jns    319c <generic_kprobe_process_event+0x319c> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1a94, 0x319c, x86_l_319c);
x86_l_1a9a:
	/* 0x1a9a: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_1a9d:
	/* 0x1a9d: jns    3cc9 <generic_kprobe_process_event+0x3cc9> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1a9d, 0x3cc9, x86_l_3cc9);
x86_l_1aa3:
	/* 0x1aa3: mov    eax,DWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1aa5:
	/* 0x1aa5: mov    DWORD PTR [rsp+0x70],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1aa9:
	/* 0x1aa9: jmp    3cd3 <generic_kprobe_process_event+0x3cd3> */
	X86_SIM_X86_JMP(0x1aa9, 0x3cd3, x86_l_3cd3);
x86_l_1aae:
	/* 0x1aae: mov    rax,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_1ab1:
	/* 0x1ab1: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_1ab4:
	/* 0x1ab4: jns    24a0 <generic_kprobe_process_event+0x24a0> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1ab4, 0x24a0, x86_l_24a0);
x86_l_1aba:
	/* 0x1aba: movzx  eax,WORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1abd:
	/* 0x1abd: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ac2:
	/* 0x1ac2: mov    WORD PTR [rcx],ax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ac5:
	/* 0x1ac5: mov    r12,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R12, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_1ac8:
	/* 0x1ac8: add    r12,0x2 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_1acc:
	/* 0x1acc: jns    1e77 <generic_kprobe_process_event+0x1e77> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1acc, 0x1e77, x86_l_1e77);
x86_l_1ad2:
	/* 0x1ad2: mov    rax,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_1ad5:
	/* 0x1ad5: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_1ad8:
	/* 0x1ad8: jns    4236 <generic_kprobe_process_event+0x4236> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1ad8, 0x4236, x86_l_4236);
x86_l_1ade:
	/* 0x1ade: movzx  eax,BYTE PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1ae1:
	/* 0x1ae1: mov    BYTE PTR [rsp+0x70],al */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1ae5:
	/* 0x1ae5: test   al,al */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8, 0, 0);
x86_l_1ae7:
	/* 0x1ae7: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1aec:
	/* 0x1aec: sete   BYTE PTR [rax+0x2] */
	X86_SIM_RUN_OP(X86_OP_SETCC_MEM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_REG_AUX_SRC_SHIFT(X86_CC_E)), 2ULL);
x86_l_1af0:
	/* 0x1af0: je     2ee9 <generic_kprobe_process_event+0x2ee9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1af0, 0x2ee9, x86_l_2ee9);
x86_l_1af6:
	/* 0x1af6: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1afb:
	/* 0x1afb: lea    rcx,[rax+0x4] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1aff:
	/* 0x1aff: test   r12,r12 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_1b02:
	/* 0x1b02: jns    3d87 <generic_kprobe_process_event+0x3d87> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1b02, 0x3d87, x86_l_3d87);
x86_l_1b08:
	/* 0x1b08: xor    edx,edx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1b0a:
	/* 0x1b0a: cmp    rdx,0x6b */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, 0, 107ULL);
x86_l_1b0e:
	/* 0x1b0e: je     421e <generic_kprobe_process_event+0x421e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1b0e, 0x421e, x86_l_421e);
x86_l_1b14:
	/* 0x1b14: lea    rax,[rdx+0x1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_1b18:
	/* 0x1b18: movzx  esi,BYTE PTR [r12+rdx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RDX, 0, X86_WIDTH_8), 0ULL);
x86_l_1b1d:
	/* 0x1b1d: mov    BYTE PTR [rcx+rdx*1],sil */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RSI, X86_WIDTH_8, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_1b21:
	/* 0x1b21: mov    rdx,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_1b24:
	/* 0x1b24: test   sil,sil */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_8, 0, 0);
x86_l_1b27:
	/* 0x1b27: jne    1b0a <generic_kprobe_process_event+0x1b0a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1b27, 0x1b0a, x86_l_1b0a);
x86_l_1b29:
	/* 0x1b29: jmp    1ebc <generic_kprobe_process_event+0x1ebc> */
	X86_SIM_X86_JMP(0x1b29, 0x1ebc, x86_l_1ebc);
x86_l_1b2e:
	/* 0x1b2e: mov    rax,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_1b31:
	/* 0x1b31: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_1b34:
	/* 0x1b34: jns    24af <generic_kprobe_process_event+0x24af> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1b34, 0x24af, x86_l_24af);
x86_l_1b3a:
	/* 0x1b3a: movzx  eax,BYTE PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1b3d:
	/* 0x1b3d: mov    BYTE PTR [rsp+0xc0],al */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_1b44:
	/* 0x1b44: test   al,al */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8, 0, 0);
x86_l_1b46:
	/* 0x1b46: je     24b7 <generic_kprobe_process_event+0x24b7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1b46, 0x24b7, x86_l_24b7);
x86_l_1b4c:
	/* 0x1b4c: movzx  eax,al */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8, 0);
x86_l_1b4f:
	/* 0x1b4f: cmp    eax,0x1 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_1b52:
	/* 0x1b52: jne    1f41 <generic_kprobe_process_event+0x1f41> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1b52, 0x1f41, x86_l_1f41);
x86_l_1b58:
	/* 0x1b58: add    r15,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1b5c:
	/* 0x1b5c: jns    2d6a <generic_kprobe_process_event+0x2d6a> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1b5c, 0x2d6a, x86_l_2d6a);
x86_l_1b62:
	/* 0x1b62: test   r15,r15 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_1b65:
	/* 0x1b65: jns    373e <generic_kprobe_process_event+0x373e> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1b65, 0x373e, x86_l_373e);
x86_l_1b6b:
	/* 0x1b6b: mov    rdx,QWORD PTR [r15] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b6e:
	/* 0x1b6e: mov    QWORD PTR [rsp+0x70],rdx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1b73:
	/* 0x1b73: jmp    2d81 <generic_kprobe_process_event+0x2d81> */
	X86_SIM_X86_JMP(0x1b73, 0x2d81, x86_l_2d81);
x86_l_1b78:
	/* 0x1b78: mov    esi,0x3f */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 63ULL);
x86_l_1b7d:
	/* 0x1b7d: call   1d82 <generic_kprobe_process_event+0x1d82> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read_str);
x86_l_1b82:
	/* 0x1b82: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_1b85:
	/* 0x1b85: jns    31cc <generic_kprobe_process_event+0x31cc> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1b85, 0x31cc, x86_l_31cc);
x86_l_1b8b:
	/* 0x1b8b: jmp    2d4b <generic_kprobe_process_event+0x2d4b> */
	X86_SIM_X86_JMP(0x1b8b, 0x2d4b, x86_l_2d4b);
x86_l_1b90:
	/* 0x1b90: lea    rdi,[rsp+0x70] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1b95:
	/* 0x1b95: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_1b9a:
	/* 0x1b9a: call   1d9f <generic_kprobe_process_event+0x1d9f> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_1b9f:
	/* 0x1b9f: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1ba4:
	/* 0x1ba4: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_1ba7:
	/* 0x1ba7: jns    24f5 <generic_kprobe_process_event+0x24f5> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1ba7, 0x24f5, x86_l_24f5);
x86_l_1bad:
	/* 0x1bad: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_1bb0:
	/* 0x1bb0: jns    3113 <generic_kprobe_process_event+0x3113> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1bb0, 0x3113, x86_l_3113);
x86_l_1bb6:
	/* 0x1bb6: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1bb8:
	/* 0x1bb8: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1bbd:
	/* 0x1bbd: cmp    rax,0x7f */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, 0, 127ULL);
x86_l_1bc1:
	/* 0x1bc1: je     3b2a <generic_kprobe_process_event+0x3b2a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1bc1, 0x3b2a, x86_l_3b2a);
x86_l_1bc7:
	/* 0x1bc7: movzx  ecx,BYTE PTR [rdx+rax*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1bcb:
	/* 0x1bcb: mov    BYTE PTR [rsi+rax*1],cl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1bce:
	/* 0x1bce: inc    rax */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1bd1:
	/* 0x1bd1: test   cl,cl */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8, 0, 0);
x86_l_1bd3:
	/* 0x1bd3: jne    1bbd <generic_kprobe_process_event+0x1bbd> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1bd3, 0x1bbd, x86_l_1bbd);
x86_l_1bd5:
	/* 0x1bd5: jmp    2504 <generic_kprobe_process_event+0x2504> */
	X86_SIM_X86_JMP(0x1bd5, 0x2504, x86_l_2504);
x86_l_1bda:
	/* 0x1bda: call   1ddf <generic_kprobe_process_event+0x1ddf> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_get_current_pid_tgid);
x86_l_1bdf:
	/* 0x1bdf: cmp    rax,0xffffffffffffffea */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, 0, 18446744073709551594ULL);
x86_l_1be3:
	/* 0x1be3: jne    1bee <generic_kprobe_process_event+0x1bee> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1be3, 0x1bee, x86_l_1bee);
x86_l_1be5:
	/* 0x1be5: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1bea:
	/* 0x1bea: mov    rax,QWORD PTR [rax+0x20] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1bee:
	/* 0x1bee: mov    rcx,QWORD PTR [rbx+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1bf2:
	/* 0x1bf2: mov    rdx,QWORD PTR [rbx+0x60] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1bf6:
	/* 0x1bf6: mov    QWORD PTR [rsp+0x70],rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1bfb:
	/* 0x1bfb: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1c00:
	/* 0x1c00: mov    QWORD PTR [rsp+0x78],rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1c05:
	/* 0x1c05: mov    QWORD PTR [rsp+0x80],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_1c11:
	/* 0x1c11: mov    QWORD PTR [rsp+0x60],rdx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1c16:
	/* 0x1c16: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1c1b:
	/* 0x1c1b: mov    rdi,QWORD PTR [rip+0x200] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)retprobe_map));
x86_l_1c22:
	/* 0x1c22: lea    rsi,[rsp+0x60] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1c27:
	/* 0x1c27: lea    rdx,[rsp+0x70] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1c2c:
	/* 0x1c2c: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1c2e:
	/* 0x1c2e: call   1e33 <generic_kprobe_process_event+0x1e33> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_update_elem);
x86_l_1c33:
	/* 0x1c33: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_1c36:
	/* 0x1c36: je     3275 <generic_kprobe_process_event+0x3275> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1c36, 0x3275, x86_l_3275);
x86_l_1c3c:
	/* 0x1c3c: neg    eax */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_1c3e:
	/* 0x1c3e: mov    WORD PTR [rsp+0x50],ax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1c43:
	/* 0x1c43: mov    WORD PTR [rsp+0x52],0x5 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 352187318277ULL);
x86_l_1c4a:
	/* 0x1c4a: movabs rax,0x200000046 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, 0, 8589934662ULL);
x86_l_1c54:
	/* 0x1c54: mov    QWORD PTR [rsp+0x54],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_1c59:
	/* 0x1c59: mov    rdi,QWORD PTR [rip+0x200] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)tg_errmetrics_map));
x86_l_1c60:
	/* 0x1c60: lea    rsi,[rsp+0x50] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1c65:
	/* 0x1c65: call   1e6a <generic_kprobe_process_event+0x1e6a> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_1c6a:
	/* 0x1c6a: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_1c6d:
	/* 0x1c6d: je     324f <generic_kprobe_process_event+0x324f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1c6d, 0x324f, x86_l_324f);
x86_l_1c73:
	/* 0x1c73: inc    DWORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_ALU_MEM_UNARY, X86_RAX, X86_REG_NONE, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1c75:
	/* 0x1c75: jmp    3275 <generic_kprobe_process_event+0x3275> */
	X86_SIM_X86_JMP(0x1c75, 0x3275, x86_l_3275);
x86_l_1c7a:
	/* 0x1c7a: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c7f:
	/* 0x1c7f: mov    rdi,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_1c82:
	/* 0x1c82: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_1c87:
	/* 0x1c87: call   1e8c <generic_kprobe_process_event+0x1e8c> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_1c8c:
	/* 0x1c8c: jmp    25de <generic_kprobe_process_event+0x25de> */
	X86_SIM_X86_JMP(0x1c8c, 0x25de, x86_l_25de);
x86_l_1c91:
	/* 0x1c91: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c96:
	/* 0x1c96: mov    rdi,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_1c99:
	/* 0x1c99: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_1c9e:
	/* 0x1c9e: call   1ea3 <generic_kprobe_process_event+0x1ea3> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_1ca3:
	/* 0x1ca3: jmp    2944 <generic_kprobe_process_event+0x2944> */
	X86_SIM_X86_JMP(0x1ca3, 0x2944, x86_l_2944);
x86_l_1ca8:
	/* 0x1ca8: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1cad:
	/* 0x1cad: mov    rdi,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_1cb0:
	/* 0x1cb0: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_1cb5:
	/* 0x1cb5: call   1eba <generic_kprobe_process_event+0x1eba> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_1cba:
	/* 0x1cba: jmp    2a48 <generic_kprobe_process_event+0x2a48> */
	X86_SIM_X86_JMP(0x1cba, 0x2a48, x86_l_2a48);
x86_l_1cbf:
	/* 0x1cbf: lea    rdi,[rsp+0x70] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1cc4:
	/* 0x1cc4: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_1cc9:
	/* 0x1cc9: call   1ece <generic_kprobe_process_event+0x1ece> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_1cce:
	/* 0x1cce: mov    r15,QWORD PTR [rsp+0x70] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1cd3:
	/* 0x1cd3: test   r15,r15 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_1cd6:
	/* 0x1cd6: je     3f39 <generic_kprobe_process_event+0x3f39> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1cd6, 0x3f39, x86_l_3f39);
x86_l_1cdc:
	/* 0x1cdc: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ce1:
	/* 0x1ce1: mov    QWORD PTR [rax+0x28],r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1ce5:
	/* 0x1ce5: lea    rdi,[rax+0x26] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_1ce9:
	/* 0x1ce9: mov    rdx,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_1cec:
	/* 0x1cec: add    rdx,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1cf0:
	/* 0x1cf0: jns    2b0b <generic_kprobe_process_event+0x2b0b> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1cf0, 0x2b0b, x86_l_2b0b);
x86_l_1cf6:
	/* 0x1cf6: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_1cf9:
	/* 0x1cf9: jns    3281 <generic_kprobe_process_event+0x3281> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1cf9, 0x3281, x86_l_3281);
x86_l_1cff:
	/* 0x1cff: movzx  eax,WORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1d02:
	/* 0x1d02: mov    WORD PTR [rdi],ax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d05:
	/* 0x1d05: jmp    3286 <generic_kprobe_process_event+0x3286> */
	X86_SIM_X86_JMP(0x1d05, 0x3286, x86_l_3286);
x86_l_1d0a:
	/* 0x1d0a: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1d0c:
	/* 0x1d0c: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d11:
	/* 0x1d11: add    rcx,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1d15:
	/* 0x1d15: add    rax,0x400 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 1024ULL);
x86_l_1d1b:
	/* 0x1d1b: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_1d1e:
	/* 0x1d1e: jns    1e5d <generic_kprobe_process_event+0x1e5d> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1d1e, 0x1e5d, x86_l_1e5d);
x86_l_1d24:
	/* 0x1d24: movzx  edx,BYTE PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1d27:
	/* 0x1d27: mov    BYTE PTR [rcx],dl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d29:
	/* 0x1d29: mov    r15d,0x18 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 24ULL);
x86_l_1d2f:
	/* 0x1d2f: test   dl,dl */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8, 0, 0);
x86_l_1d31:
	/* 0x1d31: je     2d4e <generic_kprobe_process_event+0x2d4e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1d31, 0x2d4e, x86_l_2d4e);
x86_l_1d37:
	/* 0x1d37: movzx  ecx,BYTE PTR [rax+0x1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 1ULL);
x86_l_1d3b:
	/* 0x1d3b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d40:
	/* 0x1d40: mov    BYTE PTR [rdx+0x9],cl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 9ULL);
x86_l_1d43:
	/* 0x1d43: test   cl,cl */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8, 0, 0);
x86_l_1d45:
	/* 0x1d45: je     2d4e <generic_kprobe_process_event+0x2d4e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1d45, 0x2d4e, x86_l_2d4e);
x86_l_1d4b:
	/* 0x1d4b: movzx  ecx,BYTE PTR [rax+0x2] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 2ULL);
x86_l_1d4f:
	/* 0x1d4f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d54:
	/* 0x1d54: mov    BYTE PTR [rdx+0xa],cl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 10ULL);
x86_l_1d57:
	/* 0x1d57: test   cl,cl */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8, 0, 0);
x86_l_1d59:
	/* 0x1d59: je     2d4e <generic_kprobe_process_event+0x2d4e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1d59, 0x2d4e, x86_l_2d4e);
x86_l_1d5f:
	/* 0x1d5f: movzx  ecx,BYTE PTR [rax+0x3] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 3ULL);
x86_l_1d63:
	/* 0x1d63: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d68:
	/* 0x1d68: mov    BYTE PTR [rdx+0xb],cl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 11ULL);
x86_l_1d6b:
	/* 0x1d6b: test   cl,cl */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8, 0, 0);
x86_l_1d6d:
	/* 0x1d6d: je     2d4e <generic_kprobe_process_event+0x2d4e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1d6d, 0x2d4e, x86_l_2d4e);
x86_l_1d73:
	/* 0x1d73: movzx  ecx,BYTE PTR [rax+0x4] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 4ULL);
x86_l_1d77:
	/* 0x1d77: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d7c:
	/* 0x1d7c: mov    BYTE PTR [rdx+0xc],cl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1d7f:
	/* 0x1d7f: test   cl,cl */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8, 0, 0);
x86_l_1d81:
	/* 0x1d81: je     2d4e <generic_kprobe_process_event+0x2d4e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1d81, 0x2d4e, x86_l_2d4e);
x86_l_1d87:
	/* 0x1d87: movzx  ecx,BYTE PTR [rax+0x5] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_1d8b:
	/* 0x1d8b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d90:
	/* 0x1d90: mov    BYTE PTR [rdx+0xd],cl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 13ULL);
x86_l_1d93:
	/* 0x1d93: test   cl,cl */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8, 0, 0);
x86_l_1d95:
	/* 0x1d95: je     2d4e <generic_kprobe_process_event+0x2d4e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1d95, 0x2d4e, x86_l_2d4e);
x86_l_1d9b:
	/* 0x1d9b: movzx  ecx,BYTE PTR [rax+0x6] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_1d9f:
	/* 0x1d9f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1da4:
	/* 0x1da4: mov    BYTE PTR [rdx+0xe],cl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_1da7:
	/* 0x1da7: test   cl,cl */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8, 0, 0);
x86_l_1da9:
	/* 0x1da9: je     2d4e <generic_kprobe_process_event+0x2d4e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1da9, 0x2d4e, x86_l_2d4e);
x86_l_1daf:
	/* 0x1daf: movzx  ecx,BYTE PTR [rax+0x7] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_1db3:
	/* 0x1db3: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1db8:
	/* 0x1db8: mov    BYTE PTR [rdx+0xf],cl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 15ULL);
x86_l_1dbb:
	/* 0x1dbb: test   cl,cl */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8, 0, 0);
x86_l_1dbd:
	/* 0x1dbd: je     2d4e <generic_kprobe_process_event+0x2d4e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1dbd, 0x2d4e, x86_l_2d4e);
x86_l_1dc3:
	/* 0x1dc3: movzx  ecx,BYTE PTR [rax+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_1dc7:
	/* 0x1dc7: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1dcc:
	/* 0x1dcc: mov    BYTE PTR [rdx+0x10],cl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1dcf:
	/* 0x1dcf: test   cl,cl */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8, 0, 0);
x86_l_1dd1:
	/* 0x1dd1: je     2d4e <generic_kprobe_process_event+0x2d4e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1dd1, 0x2d4e, x86_l_2d4e);
x86_l_1dd7:
	/* 0x1dd7: movzx  ecx,BYTE PTR [rax+0x9] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 9ULL);
x86_l_1ddb:
	/* 0x1ddb: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1de0:
	/* 0x1de0: mov    BYTE PTR [rdx+0x11],cl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17ULL);
x86_l_1de3:
	/* 0x1de3: test   cl,cl */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8, 0, 0);
x86_l_1de5:
	/* 0x1de5: je     2d4e <generic_kprobe_process_event+0x2d4e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1de5, 0x2d4e, x86_l_2d4e);
x86_l_1deb:
	/* 0x1deb: movzx  ecx,BYTE PTR [rax+0xa] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 10ULL);
x86_l_1def:
	/* 0x1def: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1df4:
	/* 0x1df4: mov    BYTE PTR [rdx+0x12],cl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_1df7:
	/* 0x1df7: test   cl,cl */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8, 0, 0);
x86_l_1df9:
	/* 0x1df9: je     2d4e <generic_kprobe_process_event+0x2d4e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1df9, 0x2d4e, x86_l_2d4e);
x86_l_1dff:
	/* 0x1dff: movzx  ecx,BYTE PTR [rax+0xb] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 11ULL);
x86_l_1e03:
	/* 0x1e03: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e08:
	/* 0x1e08: mov    BYTE PTR [rdx+0x13],cl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 19ULL);
x86_l_1e0b:
	/* 0x1e0b: test   cl,cl */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8, 0, 0);
x86_l_1e0d:
	/* 0x1e0d: je     2d4e <generic_kprobe_process_event+0x2d4e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1e0d, 0x2d4e, x86_l_2d4e);
x86_l_1e13:
	/* 0x1e13: movzx  ecx,BYTE PTR [rax+0xc] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 12ULL);
x86_l_1e17:
	/* 0x1e17: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e1c:
	/* 0x1e1c: mov    BYTE PTR [rdx+0x14],cl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1e1f:
	/* 0x1e1f: test   cl,cl */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8, 0, 0);
x86_l_1e21:
	/* 0x1e21: je     2d4e <generic_kprobe_process_event+0x2d4e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1e21, 0x2d4e, x86_l_2d4e);
x86_l_1e27:
	/* 0x1e27: movzx  ecx,BYTE PTR [rax+0xd] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 13ULL);
x86_l_1e2b:
	/* 0x1e2b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e30:
	/* 0x1e30: mov    BYTE PTR [rdx+0x15],cl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 21ULL);
x86_l_1e33:
	/* 0x1e33: test   cl,cl */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8, 0, 0);
x86_l_1e35:
	/* 0x1e35: je     2d4e <generic_kprobe_process_event+0x2d4e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1e35, 0x2d4e, x86_l_2d4e);
x86_l_1e3b:
	/* 0x1e3b: movzx  eax,BYTE PTR [rax+0xe] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 14ULL);
x86_l_1e3f:
	/* 0x1e3f: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e44:
	/* 0x1e44: mov    BYTE PTR [rcx+0x16],al */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_1e47:
	/* 0x1e47: test   al,al */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8, 0, 0);
x86_l_1e49:
	/* 0x1e49: je     2d4e <generic_kprobe_process_event+0x2d4e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1e49, 0x2d4e, x86_l_2d4e);
x86_l_1e4f:
	/* 0x1e4f: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e54:
	/* 0x1e54: mov    BYTE PTR [rax+0x17],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 98784247808ULL);
x86_l_1e58:
	/* 0x1e58: jmp    2d4e <generic_kprobe_process_event+0x2d4e> */
	X86_SIM_X86_JMP(0x1e58, 0x2d4e, x86_l_2d4e);
x86_l_1e5d:
	/* 0x1e5d: mov    QWORD PTR [rcx+0x8],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1e65:
	/* 0x1e65: mov    QWORD PTR [rcx],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e6c:
	/* 0x1e6c: mov    r15d,0x18 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 24ULL);
x86_l_1e72:
	/* 0x1e72: jmp    2d4e <generic_kprobe_process_event+0x2d4e> */
	X86_SIM_X86_JMP(0x1e72, 0x2d4e, x86_l_2d4e);
x86_l_1e77:
	/* 0x1e77: lea    rdi,[rsp+0x70] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1e7c:
	/* 0x1e7c: mov    esi,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_1e81:
	/* 0x1e81: mov    rdx,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_1e84:
	/* 0x1e84: call   2089 <generic_kprobe_process_event+0x2089> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_1e89:
	/* 0x1e89: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_1e8c:
	/* 0x1e8c: js     4236 <generic_kprobe_process_event+0x4236> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1e8c, 0x4236, x86_l_4236);
x86_l_1e92:
	/* 0x1e92: cmp    BYTE PTR [rsp+0x70],0x0 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_1e97:
	/* 0x1e97: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e9c:
	/* 0x1e9c: sete   BYTE PTR [rax+0x2] */
	X86_SIM_RUN_OP(X86_OP_SETCC_MEM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_REG_AUX_SRC_SHIFT(X86_CC_E)), 2ULL);
x86_l_1ea0:
	/* 0x1ea0: je     2ee9 <generic_kprobe_process_event+0x2ee9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1ea0, 0x2ee9, x86_l_2ee9);
x86_l_1ea6:
	/* 0x1ea6: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1eab:
	/* 0x1eab: lea    rdi,[rax+0x4] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1eaf:
	/* 0x1eaf: mov    esi,0x6c */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 108ULL);
x86_l_1eb4:
	/* 0x1eb4: mov    rdx,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_1eb7:
	/* 0x1eb7: call   20bc <generic_kprobe_process_event+0x20bc> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read_str);
x86_l_1ebc:
	/* 0x1ebc: test   eax,eax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_1ebe:
	/* 0x1ebe: jns    422c <generic_kprobe_process_event+0x422c> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1ebe, 0x422c, x86_l_422c);
x86_l_1ec4:
	/* 0x1ec4: jmp    4236 <generic_kprobe_process_event+0x4236> */
	X86_SIM_X86_JMP(0x1ec4, 0x4236, x86_l_4236);
x86_l_1ec9:
	/* 0x1ec9: mov    r12,rdx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R12, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_1ecc:
	/* 0x1ecc: mov    rax,rdx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_1ecf:
	/* 0x1ecf: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_1ed2:
	/* 0x1ed2: jns    2c3c <generic_kprobe_process_event+0x2c3c> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1ed2, 0x2c3c, x86_l_2c3c);
x86_l_1ed8:
	/* 0x1ed8: mov    eax,DWORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1eda:
	/* 0x1eda: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1edf:
	/* 0x1edf: mov    DWORD PTR [r15],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ee2:
	/* 0x1ee2: jmp    2c48 <generic_kprobe_process_event+0x2c48> */
	X86_SIM_X86_JMP(0x1ee2, 0x2c48, x86_l_2c48);
x86_l_1ee7:
	/* 0x1ee7: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_1eea:
	/* 0x1eea: jns    2cd7 <generic_kprobe_process_event+0x2cd7> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1eea, 0x2cd7, x86_l_2cd7);
x86_l_1ef0:
	/* 0x1ef0: mov    rdi,rdx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_1ef3:
	/* 0x1ef3: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1ef5:
	/* 0x1ef5: cmp    r15d,0x8 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_1ef9:
	/* 0x1ef9: jb     1f1d <generic_kprobe_process_event+0x1f1d> */
	X86_SIM_X86_JCC(X86_CC_B, 0x1ef9, 0x1f1d, x86_l_1f1d);
x86_l_1efb:
	/* 0x1efb: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1efd:
	/* 0x1efd: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f02:
	/* 0x1f02: mov    rsi,rdi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_RDI, X86_WIDTH_64, 0, 0);
x86_l_1f05:
	/* 0x1f05: mov    rcx,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_1f08:
	/* 0x1f08: mov    rax,QWORD PTR [rsi+rax*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1f0c:
	/* 0x1f0c: mov    QWORD PTR [rdx+rcx*1],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1f10:
	/* 0x1f10: lea    rax,[rcx+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f14:
	/* 0x1f14: add    rcx,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1f18:
	/* 0x1f18: cmp    rcx,r15 */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RCX, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_1f1b:
	/* 0x1f1b: jbe    1f05 <generic_kprobe_process_event+0x1f05> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x1f1b, 0x1f05, x86_l_1f05);
x86_l_1f1d:
	/* 0x1f1d: test   r12b,0x4 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, 0, 4ULL);
x86_l_1f21:
	/* 0x1f21: jne    36f4 <generic_kprobe_process_event+0x36f4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1f21, 0x36f4, x86_l_36f4);
x86_l_1f27:
	/* 0x1f27: test   BYTE PTR [rsp+0x30],0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430210ULL);
x86_l_1f2c:
	/* 0x1f2c: jne    370f <generic_kprobe_process_event+0x370f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1f2c, 0x370f, x86_l_370f);
x86_l_1f32:
	/* 0x1f32: test   r12b,0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_1f36:
	/* 0x1f36: je     2d4e <generic_kprobe_process_event+0x2d4e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1f36, 0x2d4e, x86_l_2d4e);
x86_l_1f3c:
	/* 0x1f3c: jmp    372b <generic_kprobe_process_event+0x372b> */
	X86_SIM_X86_JMP(0x1f3c, 0x372b, x86_l_372b);
x86_l_1f41:
	/* 0x1f41: mov    rax,QWORD PTR [rsp+0xb8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1f49:
	/* 0x1f49: mov    QWORD PTR [r13+rax*1+0x90],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 618475290624ULL);
x86_l_1f55:
	/* 0x1f55: mov    r15d,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_1f5b:
	/* 0x1f5b: jmp    41f3 <generic_kprobe_process_event+0x41f3> */
	X86_SIM_X86_JMP(0x1f5b, 0x41f3, x86_l_41f3);
x86_l_1f60:
	/* 0x1f60: mov    WORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f65:
	/* 0x1f65: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f6a:
	/* 0x1f6a: lea    rdi,[rax+0x3a] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 58ULL);
x86_l_1f6e:
	/* 0x1f6e: mov    rdx,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_1f71:
	/* 0x1f71: add    rdx,0x12 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 18ULL);
x86_l_1f75:
	/* 0x1f75: jns    1f83 <generic_kprobe_process_event+0x1f83> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1f75, 0x1f83, x86_l_1f83);
x86_l_1f77:
	/* 0x1f77: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_1f7a:
	/* 0x1f7a: jns    1f8f <generic_kprobe_process_event+0x1f8f> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1f7a, 0x1f8f, x86_l_1f8f);
x86_l_1f7c:
	/* 0x1f7c: movzx  eax,BYTE PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1f7f:
	/* 0x1f7f: mov    BYTE PTR [rdi],al */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f81:
	/* 0x1f81: jmp    1f92 <generic_kprobe_process_event+0x1f92> */
	X86_SIM_X86_JMP(0x1f81, 0x1f92, x86_l_1f92);
x86_l_1f83:
	/* 0x1f83: mov    esi,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_1f88:
	/* 0x1f88: call   218d <generic_kprobe_process_event+0x218d> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_1f8d:
	/* 0x1f8d: jmp    1f92 <generic_kprobe_process_event+0x1f92> */
	X86_SIM_X86_JMP(0x1f8d, 0x1f92, x86_l_1f92);
x86_l_1f8f:
	/* 0x1f8f: mov    BYTE PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f92:
	/* 0x1f92: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f97:
	/* 0x1f97: lea    rdi,[rax+0x38] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1f9b:
	/* 0x1f9b: mov    rdx,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_1f9e:
	/* 0x1f9e: add    rdx,0x21e */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 542ULL);
x86_l_1fa5:
	/* 0x1fa5: jns    1fb4 <generic_kprobe_process_event+0x1fb4> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1fa5, 0x1fb4, x86_l_1fb4);
x86_l_1fa7:
	/* 0x1fa7: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_1faa:
	/* 0x1faa: jns    1fc0 <generic_kprobe_process_event+0x1fc0> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1faa, 0x1fc0, x86_l_1fc0);
x86_l_1fac:
	/* 0x1fac: movzx  eax,WORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1faf:
	/* 0x1faf: mov    WORD PTR [rdi],ax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1fb2:
	/* 0x1fb2: jmp    1fc5 <generic_kprobe_process_event+0x1fc5> */
	X86_SIM_X86_JMP(0x1fb2, 0x1fc5, x86_l_1fc5);
x86_l_1fb4:
	/* 0x1fb4: mov    esi,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_1fb9:
	/* 0x1fb9: call   21be <generic_kprobe_process_event+0x21be> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_1fbe:
	/* 0x1fbe: jmp    1fc5 <generic_kprobe_process_event+0x1fc5> */
	X86_SIM_X86_JMP(0x1fbe, 0x1fc5, x86_l_1fc5);
x86_l_1fc0:
	/* 0x1fc0: mov    WORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1fc5:
	/* 0x1fc5: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1fca:
	/* 0x1fca: lea    rdi,[rax+0x24] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1fce:
	/* 0x1fce: mov    rdx,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_1fd1:
	/* 0x1fd1: add    rdx,0x21c */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 540ULL);
x86_l_1fd8:
	/* 0x1fd8: jns    1fe7 <generic_kprobe_process_event+0x1fe7> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1fd8, 0x1fe7, x86_l_1fe7);
x86_l_1fda:
	/* 0x1fda: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_1fdd:
	/* 0x1fdd: jns    1ff3 <generic_kprobe_process_event+0x1ff3> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1fdd, 0x1ff3, x86_l_1ff3);
x86_l_1fdf:
	/* 0x1fdf: movzx  eax,WORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1fe2:
	/* 0x1fe2: mov    WORD PTR [rdi],ax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1fe5:
	/* 0x1fe5: jmp    1ff8 <generic_kprobe_process_event+0x1ff8> */
	X86_SIM_X86_JMP(0x1fe5, 0x1ff8, x86_l_1ff8);
x86_l_1fe7:
	/* 0x1fe7: mov    esi,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_1fec:
	/* 0x1fec: call   21f1 <generic_kprobe_process_event+0x21f1> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_1ff1:
	/* 0x1ff1: jmp    1ff8 <generic_kprobe_process_event+0x1ff8> */
	X86_SIM_X86_JMP(0x1ff1, 0x1ff8, x86_l_1ff8);
x86_l_1ff3:
	/* 0x1ff3: mov    WORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ff8:
	/* 0x1ff8: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ffd:
	/* 0x1ffd: lea    rdi,[rax+0x30] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2001:
	/* 0x2001: mov    rdx,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_2004:
	/* 0x2004: add    rdx,0x214 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 532ULL);
x86_l_200b:
	/* 0x200b: jns    2018 <generic_kprobe_process_event+0x2018> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x200b, 0x2018, x86_l_2018);
x86_l_200d:
	/* 0x200d: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_2010:
	/* 0x2010: jns    2024 <generic_kprobe_process_event+0x2024> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2010, 0x2024, x86_l_2024);
x86_l_2012:
	/* 0x2012: mov    eax,DWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2014:
	/* 0x2014: mov    DWORD PTR [rdi],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2016:
	/* 0x2016: jmp    202a <generic_kprobe_process_event+0x202a> */
	X86_SIM_X86_JMP(0x2016, 0x202a, x86_l_202a);
x86_l_2018:
	/* 0x2018: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_201d:
	/* 0x201d: call   2222 <generic_kprobe_process_event+0x2222> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_2022:
	/* 0x2022: jmp    202a <generic_kprobe_process_event+0x202a> */
	X86_SIM_X86_JMP(0x2022, 0x202a, x86_l_202a);
x86_l_2024:
	/* 0x2024: mov    DWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_202a:
	/* 0x202a: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_202f:
	/* 0x202f: lea    rdi,[rax+0x34] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2033:
	/* 0x2033: mov    rdx,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_2036:
	/* 0x2036: add    rdx,0x210 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 528ULL);
x86_l_203d:
	/* 0x203d: jns    204a <generic_kprobe_process_event+0x204a> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x203d, 0x204a, x86_l_204a);
x86_l_203f:
	/* 0x203f: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_2042:
	/* 0x2042: jns    2056 <generic_kprobe_process_event+0x2056> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2042, 0x2056, x86_l_2056);
x86_l_2044:
	/* 0x2044: mov    eax,DWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2046:
	/* 0x2046: mov    DWORD PTR [rdi],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2048:
	/* 0x2048: jmp    205c <generic_kprobe_process_event+0x205c> */
	X86_SIM_X86_JMP(0x2048, 0x205c, x86_l_205c);
x86_l_204a:
	/* 0x204a: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_204f:
	/* 0x204f: call   2254 <generic_kprobe_process_event+0x2254> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_2054:
	/* 0x2054: jmp    205c <generic_kprobe_process_event+0x205c> */
	X86_SIM_X86_JMP(0x2054, 0x205c, x86_l_205c);
x86_l_2056:
	/* 0x2056: mov    DWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_205c:
	/* 0x205c: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2061:
	/* 0x2061: lea    r12,[rax+0x10] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2065:
	/* 0x2065: mov    QWORD PTR [rax+0x18],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_206d:
	/* 0x206d: mov    QWORD PTR [rax+0x10],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2075:
	/* 0x2075: mov    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_207d:
	/* 0x207d: mov    QWORD PTR [rax],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2084:
	/* 0x2084: movzx  eax,WORD PTR [rax+0x26] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_2088:
	/* 0x2088: cmp    eax,0xa */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 10ULL);
x86_l_208b:
	/* 0x208b: je     20ba <generic_kprobe_process_event+0x20ba> */
	X86_SIM_X86_JCC(X86_CC_E, 0x208b, 0x20ba, x86_l_20ba);
x86_l_208d:
	/* 0x208d: cmp    eax,0x2 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_2090:
	/* 0x2090: jne    3483 <generic_kprobe_process_event+0x3483> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2090, 0x3483, x86_l_3483);
x86_l_2096:
	/* 0x2096: mov    rdx,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_2099:
	/* 0x2099: add    rdx,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_209d:
	/* 0x209d: jns    2b1a <generic_kprobe_process_event+0x2b1a> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x209d, 0x2b1a, x86_l_2b1a);
x86_l_20a3:
	/* 0x20a3: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_20a6:
	/* 0x20a6: jns    3409 <generic_kprobe_process_event+0x3409> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x20a6, 0x3409, x86_l_3409);
x86_l_20ac:
	/* 0x20ac: mov    eax,DWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20ae:
	/* 0x20ae: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20b3:
	/* 0x20b3: mov    DWORD PTR [rcx],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20b5:
	/* 0x20b5: jmp    3414 <generic_kprobe_process_event+0x3414> */
	X86_SIM_X86_JMP(0x20b5, 0x3414, x86_l_3414);
x86_l_20ba:
	/* 0x20ba: mov    rdx,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_20bd:
	/* 0x20bd: add    rdx,0x48 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 72ULL);
x86_l_20c1:
	/* 0x20c1: jns    2b2e <generic_kprobe_process_event+0x2b2e> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x20c1, 0x2b2e, x86_l_2b2e);
x86_l_20c7:
	/* 0x20c7: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_20ca:
	/* 0x20ca: jns    343a <generic_kprobe_process_event+0x343a> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x20ca, 0x343a, x86_l_343a);
x86_l_20d0:
	/* 0x20d0: mov    rax,QWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20d3:
	/* 0x20d3: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20d8:
	/* 0x20d8: mov    QWORD PTR [rcx],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20db:
	/* 0x20db: mov    rax,QWORD PTR [rdx+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20df:
	/* 0x20df: mov    QWORD PTR [rcx+0x8],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20e3:
	/* 0x20e3: jmp    344e <generic_kprobe_process_event+0x344e> */
	X86_SIM_X86_JMP(0x20e3, 0x344e, x86_l_344e);
x86_l_20e8:
	/* 0x20e8: mov    edx,esi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_20ea:
	/* 0x20ea: xor    esi,esi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_20ec:
	/* 0x20ec: call   4f97 <__native_link_local_memset_zero_dynamic> */
	X86_SIM_X86_CALL(x86_l_4f97, 0x20f1ULL);
x86_l_20f1:
	/* 0x20f1: mov    r15,0xffffffffffffffde */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, 0, 18446744073709551582ULL);
x86_l_20f8:
	/* 0x20f8: jmp    423c <generic_kprobe_process_event+0x423c> */
	X86_SIM_X86_JMP(0x20f8, 0x423c, x86_l_423c);
x86_l_20fd:
	/* 0x20fd: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_2106:
	/* 0x2106: xor    edx,edx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_2108:
	/* 0x2108: lea    rdi,[rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_210d:
	/* 0x210d: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_2112:
	/* 0x2112: call   2317 <generic_kprobe_process_event+0x2317> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_2117:
	/* 0x2117: jmp    23fe <generic_kprobe_process_event+0x23fe> */
	X86_SIM_X86_JMP(0x2117, 0x23fe, x86_l_23fe);
x86_l_211c:
	/* 0x211c: mov    DWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2122:
	/* 0x2122: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2127:
	/* 0x2127: lea    rdi,[rax+0x2c] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_212b:
	/* 0x212b: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2130:
	/* 0x2130: add    rdx,0x70 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 112ULL);
x86_l_2134:
	/* 0x2134: jns    2141 <generic_kprobe_process_event+0x2141> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2134, 0x2141, x86_l_2141);
x86_l_2136:
	/* 0x2136: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_2139:
	/* 0x2139: jns    214d <generic_kprobe_process_event+0x214d> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2139, 0x214d, x86_l_214d);
x86_l_213b:
	/* 0x213b: mov    eax,DWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_213d:
	/* 0x213d: mov    DWORD PTR [rdi],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_213f:
	/* 0x213f: jmp    2153 <generic_kprobe_process_event+0x2153> */
	X86_SIM_X86_JMP(0x213f, 0x2153, x86_l_2153);
x86_l_2141:
	/* 0x2141: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_2146:
	/* 0x2146: call   234b <generic_kprobe_process_event+0x234b> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_214b:
	/* 0x214b: jmp    2153 <generic_kprobe_process_event+0x2153> */
	X86_SIM_X86_JMP(0x214b, 0x2153, x86_l_2153);
x86_l_214d:
	/* 0x214d: mov    DWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2153:
	/* 0x2153: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2158:
	/* 0x2158: lea    rdi,[rax+0x30] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_215c:
	/* 0x215c: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2161:
	/* 0x2161: add    rdx,0x90 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_2168:
	/* 0x2168: jns    2175 <generic_kprobe_process_event+0x2175> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2168, 0x2175, x86_l_2175);
x86_l_216a:
	/* 0x216a: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_216d:
	/* 0x216d: jns    2181 <generic_kprobe_process_event+0x2181> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x216d, 0x2181, x86_l_2181);
x86_l_216f:
	/* 0x216f: mov    eax,DWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2171:
	/* 0x2171: mov    DWORD PTR [rdi],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2173:
	/* 0x2173: jmp    2187 <generic_kprobe_process_event+0x2187> */
	X86_SIM_X86_JMP(0x2173, 0x2187, x86_l_2187);
x86_l_2175:
	/* 0x2175: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_217a:
	/* 0x217a: call   237f <generic_kprobe_process_event+0x237f> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_217f:
	/* 0x217f: jmp    2187 <generic_kprobe_process_event+0x2187> */
	X86_SIM_X86_JMP(0x217f, 0x2187, x86_l_2187);
x86_l_2181:
	/* 0x2181: mov    DWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2187:
	/* 0x2187: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_218c:
	/* 0x218c: lea    rdi,[rax+0x34] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2190:
	/* 0x2190: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2195:
	/* 0x2195: add    rdx,0xa8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 168ULL);
x86_l_219c:
	/* 0x219c: jns    21a9 <generic_kprobe_process_event+0x21a9> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x219c, 0x21a9, x86_l_21a9);
x86_l_219e:
	/* 0x219e: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_21a1:
	/* 0x21a1: jns    21b5 <generic_kprobe_process_event+0x21b5> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x21a1, 0x21b5, x86_l_21b5);
x86_l_21a3:
	/* 0x21a3: mov    eax,DWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21a5:
	/* 0x21a5: mov    DWORD PTR [rdi],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21a7:
	/* 0x21a7: jmp    21bb <generic_kprobe_process_event+0x21bb> */
	X86_SIM_X86_JMP(0x21a7, 0x21bb, x86_l_21bb);
x86_l_21a9:
	/* 0x21a9: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_21ae:
	/* 0x21ae: call   23b3 <generic_kprobe_process_event+0x23b3> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_21b3:
	/* 0x21b3: jmp    21bb <generic_kprobe_process_event+0x21bb> */
	X86_SIM_X86_JMP(0x21b3, 0x21bb, x86_l_21bb);
x86_l_21b5:
	/* 0x21b5: mov    DWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21bb:
	/* 0x21bb: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_21c4:
	/* 0x21c4: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_21c9:
	/* 0x21c9: add    rdx,0xc8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 200ULL);
x86_l_21d0:
	/* 0x21d0: jns    21e1 <generic_kprobe_process_event+0x21e1> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x21d0, 0x21e1, x86_l_21e1);
x86_l_21d2:
	/* 0x21d2: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_21d5:
	/* 0x21d5: jns    21f2 <generic_kprobe_process_event+0x21f2> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x21d5, 0x21f2, x86_l_21f2);
x86_l_21d7:
	/* 0x21d7: mov    rax,QWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21da:
	/* 0x21da: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_21df:
	/* 0x21df: jmp    21fb <generic_kprobe_process_event+0x21fb> */
	X86_SIM_X86_JMP(0x21df, 0x21fb, x86_l_21fb);
x86_l_21e1:
	/* 0x21e1: lea    rdi,[rsp+0x70] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_21e6:
	/* 0x21e6: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_21eb:
	/* 0x21eb: call   23f0 <generic_kprobe_process_event+0x23f0> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_21f0:
	/* 0x21f0: jmp    21fb <generic_kprobe_process_event+0x21fb> */
	X86_SIM_X86_JMP(0x21f0, 0x21fb, x86_l_21fb);
x86_l_21f2:
	/* 0x21f2: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_21fb:
	/* 0x21fb: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2200:
	/* 0x2200: add    rdx,0xb8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 184ULL);
x86_l_2207:
	/* 0x2207: jns    2218 <generic_kprobe_process_event+0x2218> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2207, 0x2218, x86_l_2218);
x86_l_2209:
	/* 0x2209: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_220c:
	/* 0x220c: jns    222e <generic_kprobe_process_event+0x222e> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x220c, 0x222e, x86_l_222e);
x86_l_220e:
	/* 0x220e: movzx  eax,WORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2211:
	/* 0x2211: mov    WORD PTR [rsp+0x50],ax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2216:
	/* 0x2216: jmp    2237 <generic_kprobe_process_event+0x2237> */
	X86_SIM_X86_JMP(0x2216, 0x2237, x86_l_2237);
x86_l_2218:
	/* 0x2218: lea    rdi,[rsp+0x50] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_221d:
	/* 0x221d: mov    esi,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_2222:
	/* 0x2222: call   2427 <generic_kprobe_process_event+0x2427> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_2227:
	/* 0x2227: movzx  eax,WORD PTR [rsp+0x50] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 80ULL);
x86_l_222c:
	/* 0x222c: jmp    2237 <generic_kprobe_process_event+0x2237> */
	X86_SIM_X86_JMP(0x222c, 0x2237, x86_l_2237);
x86_l_222e:
	/* 0x222e: mov    WORD PTR [rsp+0x50],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_2235:
	/* 0x2235: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_2237:
	/* 0x2237: movzx  r15d,ax */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_223b:
	/* 0x223b: add    r15,QWORD PTR [rsp+0x70] */
	X86_SIM_RUN_OP(X86_OP_ALU_MEM, X86_R15, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 112ULL);
x86_l_2240:
	/* 0x2240: jns    225a <generic_kprobe_process_event+0x225a> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2240, 0x225a, x86_l_225a);
x86_l_2242:
	/* 0x2242: mov    rax,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_2245:
	/* 0x2245: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_2248:
	/* 0x2248: jns    41ed <generic_kprobe_process_event+0x41ed> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2248, 0x41ed, x86_l_41ed);
x86_l_224e:
	/* 0x224e: movzx  eax,BYTE PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2251:
	/* 0x2251: mov    BYTE PTR [rsp+0xd0],al */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_2258:
	/* 0x2258: jmp    2277 <generic_kprobe_process_event+0x2277> */
	X86_SIM_X86_JMP(0x2258, 0x2277, x86_l_2277);
x86_l_225a:
	/* 0x225a: lea    rdi,[rsp+0xd0] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_2262:
	/* 0x2262: mov    esi,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_2267:
	/* 0x2267: mov    rdx,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_226a:
	/* 0x226a: call   246f <generic_kprobe_process_event+0x246f> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_226f:
	/* 0x226f: movzx  eax,BYTE PTR [rsp+0xd0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 208ULL);
x86_l_2277:
	/* 0x2277: shr    al,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_ALU_SHR, 4ULL);
x86_l_227a:
	/* 0x227a: cmp    al,0x6 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, 0, 6ULL);
x86_l_227c:
	/* 0x227c: je     22ac <generic_kprobe_process_event+0x22ac> */
	X86_SIM_X86_JCC(X86_CC_E, 0x227c, 0x22ac, x86_l_22ac);
x86_l_227e:
	/* 0x227e: movzx  eax,al */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8, 0);
x86_l_2281:
	/* 0x2281: cmp    eax,0x4 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_2284:
	/* 0x2284: jne    41ed <generic_kprobe_process_event+0x41ed> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2284, 0x41ed, x86_l_41ed);
x86_l_228a:
	/* 0x228a: mov    rdx,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_228d:
	/* 0x228d: add    rdx,0x9 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 9ULL);
x86_l_2291:
	/* 0x2291: jns    2dac <generic_kprobe_process_event+0x2dac> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2291, 0x2dac, x86_l_2dac);
x86_l_2297:
	/* 0x2297: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_229a:
	/* 0x229a: jns    376a <generic_kprobe_process_event+0x376a> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x229a, 0x376a, x86_l_376a);
x86_l_22a0:
	/* 0x22a0: movzx  eax,BYTE PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_22a3:
	/* 0x22a3: mov    BYTE PTR [rsp+0x60],al */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_22a7:
	/* 0x22a7: jmp    3771 <generic_kprobe_process_event+0x3771> */
	X86_SIM_X86_JMP(0x22a7, 0x3771, x86_l_3771);
x86_l_22ac:
	/* 0x22ac: mov    rbp,QWORD PTR [rsp+0x70] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_22b1:
	/* 0x22b1: movzx  ebx,WORD PTR [rsp+0x50] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 80ULL);
x86_l_22b6:
	/* 0x22b6: lea    rax,[rbx+rbp*1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_22ba:
	/* 0x22ba: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_22bf:
	/* 0x22bf: mov    DWORD PTR [rsp+0x60],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_22c7:
	/* 0x22c7: mov    rdi,QWORD PTR [rip+0x200] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)tg_ipv6_ext_heap));
x86_l_22ce:
	/* 0x22ce: lea    rsi,[rsp+0x60] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_22d3:
	/* 0x22d3: call   24d8 <generic_kprobe_process_event+0x24d8> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_22d8:
	/* 0x22d8: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_22db:
	/* 0x22db: je     400d <generic_kprobe_process_event+0x400d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x22db, 0x400d, x86_l_400d);
x86_l_22e1:
	/* 0x22e1: mov    r12,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R12, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_22e4:
	/* 0x22e4: mov    WORD PTR [rax],bx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22e7:
	/* 0x22e7: mov    BYTE PTR [rax+0x5],0xff */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 21474836735ULL);
x86_l_22eb:
	/* 0x22eb: mov    BYTE PTR [rax+0x7],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 30064771072ULL);
x86_l_22ef:
	/* 0x22ef: mov    r13,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R13, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_22f2:
	/* 0x22f2: add    r13,0x6 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 6ULL);
x86_l_22f6:
	/* 0x22f6: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_22fb:
	/* 0x22fb: add    rdx,0x6 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 6ULL);
x86_l_22ff:
	/* 0x22ff: jns    3548 <generic_kprobe_process_event+0x3548> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x22ff, 0x3548, x86_l_3548);
x86_l_2305:
	/* 0x2305: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_2308:
	/* 0x2308: jns    3e27 <generic_kprobe_process_event+0x3e27> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2308, 0x3e27, x86_l_3e27);
x86_l_230e:
	/* 0x230e: movzx  eax,BYTE PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2311:
	/* 0x2311: mov    BYTE PTR [r13+0x0],al */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2315:
	/* 0x2315: jmp    355e <generic_kprobe_process_event+0x355e> */
	X86_SIM_X86_JMP(0x2315, 0x355e, x86_l_355e);
x86_l_231a:
	/* 0x231a: mov    DWORD PTR [rsp+0x60],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_2322:
	/* 0x2322: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_2324:
	/* 0x2324: mov    DWORD PTR [rsp+0x78],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2328:
	/* 0x2328: mov    rdi,QWORD PTR [rip+0x200] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)fdinstall_map));
x86_l_232f:
	/* 0x232f: lea    rsi,[rsp+0x70] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2334:
	/* 0x2334: call   2539 <generic_kprobe_process_event+0x2539> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_2339:
	/* 0x2339: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_233c:
	/* 0x233c: je     2364 <generic_kprobe_process_event+0x2364> */
	X86_SIM_X86_JCC(X86_CC_E, 0x233c, 0x2364, x86_l_2364);
x86_l_233e:
	/* 0x233e: mov    r12,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R12, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_2341:
	/* 0x2341: mov    ebx,DWORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2343:
	/* 0x2343: lea    rax,[rsp+0x60] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2348:
	/* 0x2348: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_234b:
	/* 0x234b: jns    2370 <generic_kprobe_process_event+0x2370> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x234b, 0x2370, x86_l_2370);
x86_l_234d:
	/* 0x234d: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_2350:
	/* 0x2350: jns    2b42 <generic_kprobe_process_event+0x2b42> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2350, 0x2b42, x86_l_2b42);
x86_l_2356:
	/* 0x2356: mov    eax,DWORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2358:
	/* 0x2358: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_235d:
	/* 0x235d: mov    DWORD PTR [rcx],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_235f:
	/* 0x235f: jmp    2b4d <generic_kprobe_process_event+0x2b4d> */
	X86_SIM_X86_JMP(0x235f, 0x2b4d, x86_l_2b4d);
x86_l_2364:
	/* 0x2364: mov    r15,0xffffffffffffffff */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, 0, 18446744073709551615ULL);
x86_l_236b:
	/* 0x236b: jmp    2c2a <generic_kprobe_process_event+0x2c2a> */
	X86_SIM_X86_JMP(0x236b, 0x2c2a, x86_l_2c2a);
x86_l_2370:
	/* 0x2370: lea    rdx,[rsp+0x60] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2375:
	/* 0x2375: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_237a:
	/* 0x237a: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_237f:
	/* 0x237f: call   2584 <generic_kprobe_process_event+0x2584> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_2384:
	/* 0x2384: jmp    2b4d <generic_kprobe_process_event+0x2b4d> */
	X86_SIM_X86_JMP(0x2384, 0x2b4d, x86_l_2b4d);
x86_l_2389:
	/* 0x2389: mov    BYTE PTR [rdi+0x10],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_238d:
	/* 0x238d: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_2395:
	/* 0x2395: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_239c:
	/* 0x239c: mov    r15,0xffffffffffffffde */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, 0, 18446744073709551582ULL);
x86_l_23a3:
	/* 0x23a3: jmp    423c <generic_kprobe_process_event+0x423c> */
	X86_SIM_X86_JMP(0x23a3, 0x423c, x86_l_423c);
x86_l_23a8:
	/* 0x23a8: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_23ad:
	/* 0x23ad: lea    rdi,[rax+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_23b1:
	/* 0x23b1: mov    rdx,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_23b4:
	/* 0x23b4: add    rdx,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_23b8:
	/* 0x23b8: jns    31b4 <generic_kprobe_process_event+0x31b4> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x23b8, 0x31b4, x86_l_31b4);
x86_l_23be:
	/* 0x23be: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_23c1:
	/* 0x23c1: jns    3cf6 <generic_kprobe_process_event+0x3cf6> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x23c1, 0x3cf6, x86_l_3cf6);
x86_l_23c7:
	/* 0x23c7: mov    rax,QWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23ca:
	/* 0x23ca: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_23cf:
	/* 0x23cf: mov    QWORD PTR [rcx+0x8],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_23d3:
	/* 0x23d3: mov    rax,QWORD PTR [rdx+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_23d7:
	/* 0x23d7: mov    QWORD PTR [rcx+0x10],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23db:
	/* 0x23db: jmp    3d05 <generic_kprobe_process_event+0x3d05> */
	X86_SIM_X86_JMP(0x23db, 0x3d05, x86_l_3d05);
x86_l_23e0:
	/* 0x23e0: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_23e5:
	/* 0x23e5: mov    WORD PTR [rax],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23ea:
	/* 0x23ea: mov    r15d,0x18 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 24ULL);
x86_l_23f0:
	/* 0x23f0: jmp    423c <generic_kprobe_process_event+0x423c> */
	X86_SIM_X86_JMP(0x23f0, 0x423c, x86_l_423c);
x86_l_23f5:
	/* 0x23f5: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_23fe:
	/* 0x23fe: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2403:
	/* 0x2403: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2408:
	/* 0x2408: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_240d:
	/* 0x240d: lea    rdi,[rax+0x4] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2411:
	/* 0x2411: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_2414:
	/* 0x2414: js     2445 <generic_kprobe_process_event+0x2445> */
	X86_SIM_X86_JCC(X86_CC_S, 0x2414, 0x2445, x86_l_2445);
x86_l_2416:
	/* 0x2416: mov    esi,0x1001 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4097ULL);
x86_l_241b:
	/* 0x241b: call   2620 <generic_kprobe_process_event+0x2620> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read_str);
x86_l_2420:
	/* 0x2420: mov    r15,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R15, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_2423:
	/* 0x2423: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_2426:
	/* 0x2426: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_242b:
	/* 0x242b: js     4246 <generic_kprobe_process_event+0x4246> */
	X86_SIM_X86_JCC(X86_CC_S, 0x242b, 0x4246, x86_l_4246);
x86_l_2431:
	/* 0x2431: lea    eax,[r15-0x1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2435:
	/* 0x2435: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_243a:
	/* 0x243a: mov    DWORD PTR [rdx],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_243c:
	/* 0x243c: add    r15,0x3 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 3ULL);
x86_l_2440:
	/* 0x2440: jmp    4246 <generic_kprobe_process_event+0x4246> */
	X86_SIM_X86_JMP(0x2440, 0x4246, x86_l_4246);
x86_l_2445:
	/* 0x2445: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_2448:
	/* 0x2448: jns    246f <generic_kprobe_process_event+0x246f> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2448, 0x246f, x86_l_246f);
x86_l_244a:
	/* 0x244a: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_244c:
	/* 0x244c: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2451:
	/* 0x2451: cmp    rax,0x1000 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, 0, 4096ULL);
x86_l_2457:
	/* 0x2457: je     248c <generic_kprobe_process_event+0x248c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2457, 0x248c, x86_l_248c);
x86_l_2459:
	/* 0x2459: lea    r15,[rax+0x1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_245d:
	/* 0x245d: movzx  esi,BYTE PTR [rdx+rax*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2461:
	/* 0x2461: mov    BYTE PTR [rdi+rax*1],sil */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RSI, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2465:
	/* 0x2465: mov    rax,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_2468:
	/* 0x2468: test   sil,sil */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_8, 0, 0);
x86_l_246b:
	/* 0x246b: jne    2451 <generic_kprobe_process_event+0x2451> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x246b, 0x2451, x86_l_2451);
x86_l_246d:
	/* 0x246d: jmp    2431 <generic_kprobe_process_event+0x2431> */
	X86_SIM_X86_JMP(0x246d, 0x2431, x86_l_2431);
x86_l_246f:
	/* 0x246f: mov    edx,0x1001 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 4097ULL);
x86_l_2474:
	/* 0x2474: xor    esi,esi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_2476:
	/* 0x2476: call   5015 <__native_link_local_memset_zero_4097> */
	X86_SIM_X86_CALL(x86_l_5015, 0x247bULL);
x86_l_247b:
	/* 0x247b: mov    r15,0xffffffffffffffde */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, 0, 18446744073709551582ULL);
x86_l_2482:
	/* 0x2482: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2487:
	/* 0x2487: jmp    4246 <generic_kprobe_process_event+0x4246> */
	X86_SIM_X86_JMP(0x2487, 0x4246, x86_l_4246);
x86_l_248c:
	/* 0x248c: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2491:
	/* 0x2491: mov    BYTE PTR [rax+0x1004],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17609365913600ULL);
x86_l_2498:
	/* 0x2498: mov    r15d,0x1001 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 4097ULL);
x86_l_249e:
	/* 0x249e: jmp    2431 <generic_kprobe_process_event+0x2431> */
	X86_SIM_X86_JMP(0x249e, 0x2431, x86_l_2431);
x86_l_24a0:
	/* 0x24a0: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_24a5:
	/* 0x24a5: mov    WORD PTR [rax],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24aa:
	/* 0x24aa: jmp    4236 <generic_kprobe_process_event+0x4236> */
	X86_SIM_X86_JMP(0x24aa, 0x4236, x86_l_4236);
x86_l_24af:
	/* 0x24af: mov    BYTE PTR [rsp+0xc0],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_24b7:
	/* 0x24b7: mov    rdx,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_24ba:
	/* 0x24ba: add    rdx,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_24be:
	/* 0x24be: jns    24d6 <generic_kprobe_process_event+0x24d6> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x24be, 0x24d6, x86_l_24d6);
x86_l_24c0:
	/* 0x24c0: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_24c3:
	/* 0x24c3: jns    2f9a <generic_kprobe_process_event+0x2f9a> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x24c3, 0x2f9a, x86_l_2f9a);
x86_l_24c9:
	/* 0x24c9: mov    rax,QWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24cc:
	/* 0x24cc: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_24d1:
	/* 0x24d1: jmp    2fa3 <generic_kprobe_process_event+0x2fa3> */
	X86_SIM_X86_JMP(0x24d1, 0x2fa3, x86_l_2fa3);
x86_l_24d6:
	/* 0x24d6: lea    rdi,[rsp+0x60] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_24db:
	/* 0x24db: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_24e0:
	/* 0x24e0: call   26e5 <generic_kprobe_process_event+0x26e5> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_24e5:
	/* 0x24e5: jmp    2fa3 <generic_kprobe_process_event+0x2fa3> */
	X86_SIM_X86_JMP(0x24e5, 0x2fa3, x86_l_2fa3);
x86_l_24ea:
	/* 0x24ea: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_24f3:
	/* 0x24f3: xor    edx,edx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_24f5:
	/* 0x24f5: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_24fa:
	/* 0x24fa: mov    esi,0x80 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 128ULL);
x86_l_24ff:
	/* 0x24ff: call   2704 <generic_kprobe_process_event+0x2704> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read_str);
x86_l_2504:
	/* 0x2504: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2509:
	/* 0x2509: lea    rdi,[rax+0x90] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2510:
	/* 0x2510: test   r15,r15 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_2513:
	/* 0x2513: jns    2521 <generic_kprobe_process_event+0x2521> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2513, 0x2521, x86_l_2521);
x86_l_2515:
	/* 0x2515: test   r15,r15 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_2518:
	/* 0x2518: jns    2530 <generic_kprobe_process_event+0x2530> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2518, 0x2530, x86_l_2530);
x86_l_251a:
	/* 0x251a: mov    eax,DWORD PTR [r15] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_251d:
	/* 0x251d: mov    DWORD PTR [rdi],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_251f:
	/* 0x251f: jmp    2536 <generic_kprobe_process_event+0x2536> */
	X86_SIM_X86_JMP(0x251f, 0x2536, x86_l_2536);
x86_l_2521:
	/* 0x2521: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_2526:
	/* 0x2526: mov    rdx,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_2529:
	/* 0x2529: call   272e <generic_kprobe_process_event+0x272e> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_252e:
	/* 0x252e: jmp    2536 <generic_kprobe_process_event+0x2536> */
	X86_SIM_X86_JMP(0x252e, 0x2536, x86_l_2536);
x86_l_2530:
	/* 0x2530: mov    DWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2536:
	/* 0x2536: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_253b:
	/* 0x253b: lea    rdi,[rax+0x80] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2542:
	/* 0x2542: mov    rdx,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_2545:
	/* 0x2545: add    rdx,0xe0 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 224ULL);
x86_l_254c:
	/* 0x254c: jns    255b <generic_kprobe_process_event+0x255b> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x254c, 0x255b, x86_l_255b);
x86_l_254e:
	/* 0x254e: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_2551:
	/* 0x2551: jns    2567 <generic_kprobe_process_event+0x2567> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2551, 0x2567, x86_l_2567);
x86_l_2553:
	/* 0x2553: mov    rax,QWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2556:
	/* 0x2556: mov    QWORD PTR [rdi],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2559:
	/* 0x2559: jmp    256e <generic_kprobe_process_event+0x256e> */
	X86_SIM_X86_JMP(0x2559, 0x256e, x86_l_256e);
x86_l_255b:
	/* 0x255b: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_2560:
	/* 0x2560: call   2765 <generic_kprobe_process_event+0x2765> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_2565:
	/* 0x2565: jmp    256e <generic_kprobe_process_event+0x256e> */
	X86_SIM_X86_JMP(0x2565, 0x256e, x86_l_256e);
x86_l_2567:
	/* 0x2567: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_256e:
	/* 0x256e: add    QWORD PTR [rsp+0x8],0x88 */
	X86_SIM_RUN_OP(X86_OP_ALU_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 34359738504ULL);
x86_l_2577:
	/* 0x2577: mov    rdx,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_257a:
	/* 0x257a: add    rdx,0x118 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 280ULL);
x86_l_2581:
	/* 0x2581: jns    25a1 <generic_kprobe_process_event+0x25a1> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2581, 0x25a1, x86_l_25a1);
x86_l_2583:
	/* 0x2583: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_2586:
	/* 0x2586: jns    25bb <generic_kprobe_process_event+0x25bb> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2586, 0x25bb, x86_l_25bb);
x86_l_2588:
	/* 0x2588: mov    rax,rdx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_258b:
	/* 0x258b: mov    rax,QWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_258e:
	/* 0x258e: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2593:
	/* 0x2593: mov    QWORD PTR [rcx],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2596:
	/* 0x2596: mov    r15d,0x98 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 152ULL);
x86_l_259c:
	/* 0x259c: jmp    2d4e <generic_kprobe_process_event+0x2d4e> */
	X86_SIM_X86_JMP(0x259c, 0x2d4e, x86_l_2d4e);
x86_l_25a1:
	/* 0x25a1: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_25a6:
	/* 0x25a6: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_25ab:
	/* 0x25ab: call   27b0 <generic_kprobe_process_event+0x27b0> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_25b0:
	/* 0x25b0: mov    r15d,0x98 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 152ULL);
x86_l_25b6:
	/* 0x25b6: jmp    2d4e <generic_kprobe_process_event+0x2d4e> */
	X86_SIM_X86_JMP(0x25b6, 0x2d4e, x86_l_2d4e);
x86_l_25bb:
	/* 0x25bb: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_25c0:
	/* 0x25c0: mov    QWORD PTR [rax],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_25c7:
	/* 0x25c7: mov    r15d,0x98 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 152ULL);
x86_l_25cd:
	/* 0x25cd: jmp    2d4e <generic_kprobe_process_event+0x2d4e> */
	X86_SIM_X86_JMP(0x25cd, 0x2d4e, x86_l_2d4e);
x86_l_25d2:
	/* 0x25d2: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_25d7:
	/* 0x25d7: mov    DWORD PTR [r15],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_25de:
	/* 0x25de: lea    rdi,[r15+0x4] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_25e2:
	/* 0x25e2: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_25e7:
	/* 0x25e7: add    rdx,0xc */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_25eb:
	/* 0x25eb: jns    25f8 <generic_kprobe_process_event+0x25f8> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x25eb, 0x25f8, x86_l_25f8);
x86_l_25ed:
	/* 0x25ed: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_25f0:
	/* 0x25f0: jns    2604 <generic_kprobe_process_event+0x2604> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x25f0, 0x2604, x86_l_2604);
x86_l_25f2:
	/* 0x25f2: mov    eax,DWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_25f4:
	/* 0x25f4: mov    DWORD PTR [rdi],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_25f6:
	/* 0x25f6: jmp    260a <generic_kprobe_process_event+0x260a> */
	X86_SIM_X86_JMP(0x25f6, 0x260a, x86_l_260a);
x86_l_25f8:
	/* 0x25f8: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_25fd:
	/* 0x25fd: call   2802 <generic_kprobe_process_event+0x2802> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_2602:
	/* 0x2602: jmp    260a <generic_kprobe_process_event+0x260a> */
	X86_SIM_X86_JMP(0x2602, 0x260a, x86_l_260a);
x86_l_2604:
	/* 0x2604: mov    DWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_260a:
	/* 0x260a: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_260f:
	/* 0x260f: lea    rdi,[rax+0x10] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2613:
	/* 0x2613: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2618:
	/* 0x2618: add    rdx,0x18 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_261c:
	/* 0x261c: jns    2629 <generic_kprobe_process_event+0x2629> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x261c, 0x2629, x86_l_2629);
x86_l_261e:
	/* 0x261e: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_2621:
	/* 0x2621: jns    2635 <generic_kprobe_process_event+0x2635> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2621, 0x2635, x86_l_2635);
x86_l_2623:
	/* 0x2623: mov    eax,DWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2625:
	/* 0x2625: mov    DWORD PTR [rdi],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2627:
	/* 0x2627: jmp    263b <generic_kprobe_process_event+0x263b> */
	X86_SIM_X86_JMP(0x2627, 0x263b, x86_l_263b);
x86_l_2629:
	/* 0x2629: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_262e:
	/* 0x262e: call   2833 <generic_kprobe_process_event+0x2833> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_2633:
	/* 0x2633: jmp    263b <generic_kprobe_process_event+0x263b> */
	X86_SIM_X86_JMP(0x2633, 0x263b, x86_l_263b);
x86_l_2635:
	/* 0x2635: mov    DWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_263b:
	/* 0x263b: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2640:
	/* 0x2640: lea    rdi,[rax+0x14] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2644:
	/* 0x2644: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2649:
	/* 0x2649: add    rdx,0x1c */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 28ULL);
x86_l_264d:
	/* 0x264d: jns    265a <generic_kprobe_process_event+0x265a> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x264d, 0x265a, x86_l_265a);
x86_l_264f:
	/* 0x264f: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_2652:
	/* 0x2652: jns    2666 <generic_kprobe_process_event+0x2666> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2652, 0x2666, x86_l_2666);
x86_l_2654:
	/* 0x2654: mov    eax,DWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2656:
	/* 0x2656: mov    DWORD PTR [rdi],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2658:
	/* 0x2658: jmp    266c <generic_kprobe_process_event+0x266c> */
	X86_SIM_X86_JMP(0x2658, 0x266c, x86_l_266c);
x86_l_265a:
	/* 0x265a: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_265f:
	/* 0x265f: call   2864 <generic_kprobe_process_event+0x2864> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_2664:
	/* 0x2664: jmp    266c <generic_kprobe_process_event+0x266c> */
	X86_SIM_X86_JMP(0x2664, 0x266c, x86_l_266c);
x86_l_2666:
	/* 0x2666: mov    DWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_266c:
	/* 0x266c: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2671:
	/* 0x2671: lea    rdi,[rax+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2675:
	/* 0x2675: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_267a:
	/* 0x267a: add    rdx,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_267e:
	/* 0x267e: jns    268b <generic_kprobe_process_event+0x268b> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x267e, 0x268b, x86_l_268b);
x86_l_2680:
	/* 0x2680: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_2683:
	/* 0x2683: jns    2697 <generic_kprobe_process_event+0x2697> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2683, 0x2697, x86_l_2697);
x86_l_2685:
	/* 0x2685: mov    eax,DWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2687:
	/* 0x2687: mov    DWORD PTR [rdi],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2689:
	/* 0x2689: jmp    269d <generic_kprobe_process_event+0x269d> */
	X86_SIM_X86_JMP(0x2689, 0x269d, x86_l_269d);
x86_l_268b:
	/* 0x268b: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_2690:
	/* 0x2690: call   2895 <generic_kprobe_process_event+0x2895> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_2695:
	/* 0x2695: jmp    269d <generic_kprobe_process_event+0x269d> */
	X86_SIM_X86_JMP(0x2695, 0x269d, x86_l_269d);
x86_l_2697:
	/* 0x2697: mov    DWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_269d:
	/* 0x269d: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_26a2:
	/* 0x26a2: lea    rdi,[rax+0xc] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_26a6:
	/* 0x26a6: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_26ab:
	/* 0x26ab: add    rdx,0x14 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 20ULL);
x86_l_26af:
	/* 0x26af: jns    26bc <generic_kprobe_process_event+0x26bc> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x26af, 0x26bc, x86_l_26bc);
x86_l_26b1:
	/* 0x26b1: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_26b4:
	/* 0x26b4: jns    26c8 <generic_kprobe_process_event+0x26c8> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x26b4, 0x26c8, x86_l_26c8);
x86_l_26b6:
	/* 0x26b6: mov    eax,DWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26b8:
	/* 0x26b8: mov    DWORD PTR [rdi],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26ba:
	/* 0x26ba: jmp    26ce <generic_kprobe_process_event+0x26ce> */
	X86_SIM_X86_JMP(0x26ba, 0x26ce, x86_l_26ce);
x86_l_26bc:
	/* 0x26bc: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_26c1:
	/* 0x26c1: call   28c6 <generic_kprobe_process_event+0x28c6> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_26c6:
	/* 0x26c6: jmp    26ce <generic_kprobe_process_event+0x26ce> */
	X86_SIM_X86_JMP(0x26c6, 0x26ce, x86_l_26ce);
x86_l_26c8:
	/* 0x26c8: mov    DWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26ce:
	/* 0x26ce: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_26d3:
	/* 0x26d3: lea    rdi,[rax+0x18] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_26d7:
	/* 0x26d7: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_26dc:
	/* 0x26dc: add    rdx,0x20 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_26e0:
	/* 0x26e0: jns    26ed <generic_kprobe_process_event+0x26ed> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x26e0, 0x26ed, x86_l_26ed);
x86_l_26e2:
	/* 0x26e2: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_26e5:
	/* 0x26e5: jns    26f9 <generic_kprobe_process_event+0x26f9> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x26e5, 0x26f9, x86_l_26f9);
x86_l_26e7:
	/* 0x26e7: mov    eax,DWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26e9:
	/* 0x26e9: mov    DWORD PTR [rdi],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26eb:
	/* 0x26eb: jmp    26ff <generic_kprobe_process_event+0x26ff> */
	X86_SIM_X86_JMP(0x26eb, 0x26ff, x86_l_26ff);
x86_l_26ed:
	/* 0x26ed: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_26f2:
	/* 0x26f2: call   28f7 <generic_kprobe_process_event+0x28f7> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_26f7:
	/* 0x26f7: jmp    26ff <generic_kprobe_process_event+0x26ff> */
	X86_SIM_X86_JMP(0x26f7, 0x26ff, x86_l_26ff);
x86_l_26f9:
	/* 0x26f9: mov    DWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26ff:
	/* 0x26ff: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2704:
	/* 0x2704: lea    rdi,[rax+0x1c] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2708:
	/* 0x2708: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_270d:
	/* 0x270d: add    rdx,0x24 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 36ULL);
x86_l_2711:
	/* 0x2711: jns    271e <generic_kprobe_process_event+0x271e> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2711, 0x271e, x86_l_271e);
x86_l_2713:
	/* 0x2713: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_2716:
	/* 0x2716: jns    272a <generic_kprobe_process_event+0x272a> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2716, 0x272a, x86_l_272a);
x86_l_2718:
	/* 0x2718: mov    eax,DWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_271a:
	/* 0x271a: mov    DWORD PTR [rdi],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_271c:
	/* 0x271c: jmp    2730 <generic_kprobe_process_event+0x2730> */
	X86_SIM_X86_JMP(0x271c, 0x2730, x86_l_2730);
x86_l_271e:
	/* 0x271e: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_2723:
	/* 0x2723: call   2928 <generic_kprobe_process_event+0x2928> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_2728:
	/* 0x2728: jmp    2730 <generic_kprobe_process_event+0x2730> */
	X86_SIM_X86_JMP(0x2728, 0x2730, x86_l_2730);
x86_l_272a:
	/* 0x272a: mov    DWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2730:
	/* 0x2730: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2735:
	/* 0x2735: mov    DWORD PTR [rax+0x24],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 154618822656ULL);
x86_l_273c:
	/* 0x273c: lea    rdi,[rax+0x20] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2740:
	/* 0x2740: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2745:
	/* 0x2745: add    rdx,0x28 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_2749:
	/* 0x2749: jns    2756 <generic_kprobe_process_event+0x2756> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2749, 0x2756, x86_l_2756);
x86_l_274b:
	/* 0x274b: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_274e:
	/* 0x274e: jns    2762 <generic_kprobe_process_event+0x2762> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x274e, 0x2762, x86_l_2762);
x86_l_2750:
	/* 0x2750: mov    eax,DWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2752:
	/* 0x2752: mov    DWORD PTR [rdi],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2754:
	/* 0x2754: jmp    2768 <generic_kprobe_process_event+0x2768> */
	X86_SIM_X86_JMP(0x2754, 0x2768, x86_l_2768);
x86_l_2756:
	/* 0x2756: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_275b:
	/* 0x275b: call   2960 <generic_kprobe_process_event+0x2960> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_2760:
	/* 0x2760: jmp    2768 <generic_kprobe_process_event+0x2768> */
	X86_SIM_X86_JMP(0x2760, 0x2768, x86_l_2768);
x86_l_2762:
	/* 0x2762: mov    DWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2768:
	/* 0x2768: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_276d:
	/* 0x276d: lea    rdi,[rax+0x30] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2771:
	/* 0x2771: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2776:
	/* 0x2776: add    rdx,0x40 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 64ULL);
x86_l_277a:
	/* 0x277a: jns    2789 <generic_kprobe_process_event+0x2789> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x277a, 0x2789, x86_l_2789);
x86_l_277c:
	/* 0x277c: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_277f:
	/* 0x277f: jns    2795 <generic_kprobe_process_event+0x2795> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x277f, 0x2795, x86_l_2795);
x86_l_2781:
	/* 0x2781: mov    rax,QWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2784:
	/* 0x2784: mov    QWORD PTR [rdi],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2787:
	/* 0x2787: jmp    279c <generic_kprobe_process_event+0x279c> */
	X86_SIM_X86_JMP(0x2787, 0x279c, x86_l_279c);
x86_l_2789:
	/* 0x2789: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_278e:
	/* 0x278e: call   2993 <generic_kprobe_process_event+0x2993> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_2793:
	/* 0x2793: jmp    279c <generic_kprobe_process_event+0x279c> */
	X86_SIM_X86_JMP(0x2793, 0x279c, x86_l_279c);
x86_l_2795:
	/* 0x2795: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_279c:
	/* 0x279c: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_27a1:
	/* 0x27a1: lea    rdi,[rax+0x38] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_27a5:
	/* 0x27a5: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_27aa:
	/* 0x27aa: add    rdx,0x30 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_27ae:
	/* 0x27ae: jns    27bd <generic_kprobe_process_event+0x27bd> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x27ae, 0x27bd, x86_l_27bd);
x86_l_27b0:
	/* 0x27b0: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_27b3:
	/* 0x27b3: jns    27c9 <generic_kprobe_process_event+0x27c9> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x27b3, 0x27c9, x86_l_27c9);
x86_l_27b5:
	/* 0x27b5: mov    rax,QWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27b8:
	/* 0x27b8: mov    QWORD PTR [rdi],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27bb:
	/* 0x27bb: jmp    27d0 <generic_kprobe_process_event+0x27d0> */
	X86_SIM_X86_JMP(0x27bb, 0x27d0, x86_l_27d0);
x86_l_27bd:
	/* 0x27bd: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_27c2:
	/* 0x27c2: call   29c7 <generic_kprobe_process_event+0x29c7> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_27c7:
	/* 0x27c7: jmp    27d0 <generic_kprobe_process_event+0x27d0> */
	X86_SIM_X86_JMP(0x27c7, 0x27d0, x86_l_27d0);
x86_l_27c9:
	/* 0x27c9: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27d0:
	/* 0x27d0: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_27d5:
	/* 0x27d5: lea    rdi,[rax+0x28] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_27d9:
	/* 0x27d9: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_27de:
	/* 0x27de: add    rdx,0x38 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 56ULL);
x86_l_27e2:
	/* 0x27e2: jns    27f1 <generic_kprobe_process_event+0x27f1> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x27e2, 0x27f1, x86_l_27f1);
x86_l_27e4:
	/* 0x27e4: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_27e7:
	/* 0x27e7: jns    27fd <generic_kprobe_process_event+0x27fd> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x27e7, 0x27fd, x86_l_27fd);
x86_l_27e9:
	/* 0x27e9: mov    rax,QWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27ec:
	/* 0x27ec: mov    QWORD PTR [rdi],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27ef:
	/* 0x27ef: jmp    2804 <generic_kprobe_process_event+0x2804> */
	X86_SIM_X86_JMP(0x27ef, 0x2804, x86_l_2804);
x86_l_27f1:
	/* 0x27f1: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_27f6:
	/* 0x27f6: call   29fb <generic_kprobe_process_event+0x29fb> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_27fb:
	/* 0x27fb: jmp    2804 <generic_kprobe_process_event+0x2804> */
	X86_SIM_X86_JMP(0x27fb, 0x2804, x86_l_2804);
x86_l_27fd:
	/* 0x27fd: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2804:
	/* 0x2804: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2809:
	/* 0x2809: add    rdx,0x90 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_2810:
	/* 0x2810: jns    2824 <generic_kprobe_process_event+0x2824> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2810, 0x2824, x86_l_2824);
x86_l_2812:
	/* 0x2812: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_2815:
	/* 0x2815: jns    283a <generic_kprobe_process_event+0x283a> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2815, 0x283a, x86_l_283a);
x86_l_2817:
	/* 0x2817: mov    rax,rdx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_281a:
	/* 0x281a: mov    r15,QWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R15, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_281d:
	/* 0x281d: mov    QWORD PTR [rsp+0x70],r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2822:
	/* 0x2822: jmp    2846 <generic_kprobe_process_event+0x2846> */
	X86_SIM_X86_JMP(0x2822, 0x2846, x86_l_2846);
x86_l_2824:
	/* 0x2824: lea    rdi,[rsp+0x70] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2829:
	/* 0x2829: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_282e:
	/* 0x282e: call   2a33 <generic_kprobe_process_event+0x2a33> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_2833:
	/* 0x2833: mov    r15,QWORD PTR [rsp+0x70] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2838:
	/* 0x2838: jmp    2846 <generic_kprobe_process_event+0x2846> */
	X86_SIM_X86_JMP(0x2838, 0x2846, x86_l_2846);
x86_l_283a:
	/* 0x283a: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_2843:
	/* 0x2843: xor    r15d,r15d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_2846:
	/* 0x2846: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_284b:
	/* 0x284b: lea    rdi,[rax+0x40] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_284f:
	/* 0x284f: mov    rdx,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_2852:
	/* 0x2852: add    rdx,0xc8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 200ULL);
x86_l_2859:
	/* 0x2859: jns    2866 <generic_kprobe_process_event+0x2866> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2859, 0x2866, x86_l_2866);
x86_l_285b:
	/* 0x285b: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_285e:
	/* 0x285e: jns    2872 <generic_kprobe_process_event+0x2872> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x285e, 0x2872, x86_l_2872);
x86_l_2860:
	/* 0x2860: mov    eax,DWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2862:
	/* 0x2862: mov    DWORD PTR [rdi],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2864:
	/* 0x2864: jmp    2878 <generic_kprobe_process_event+0x2878> */
	X86_SIM_X86_JMP(0x2864, 0x2878, x86_l_2878);
x86_l_2866:
	/* 0x2866: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_286b:
	/* 0x286b: call   2a70 <generic_kprobe_process_event+0x2a70> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_2870:
	/* 0x2870: jmp    2878 <generic_kprobe_process_event+0x2878> */
	X86_SIM_X86_JMP(0x2870, 0x2878, x86_l_2878);
x86_l_2872:
	/* 0x2872: mov    DWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2878:
	/* 0x2878: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_287d:
	/* 0x287d: lea    rdi,[rax+0x44] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_2881:
	/* 0x2881: mov    rdx,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_2884:
	/* 0x2884: add    rdx,0xcc */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 204ULL);
x86_l_288b:
	/* 0x288b: jns    2898 <generic_kprobe_process_event+0x2898> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x288b, 0x2898, x86_l_2898);
x86_l_288d:
	/* 0x288d: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_2890:
	/* 0x2890: jns    28a4 <generic_kprobe_process_event+0x28a4> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2890, 0x28a4, x86_l_28a4);
x86_l_2892:
	/* 0x2892: mov    eax,DWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2894:
	/* 0x2894: mov    DWORD PTR [rdi],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2896:
	/* 0x2896: jmp    28aa <generic_kprobe_process_event+0x28aa> */
	X86_SIM_X86_JMP(0x2896, 0x28aa, x86_l_28aa);
x86_l_2898:
	/* 0x2898: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_289d:
	/* 0x289d: call   2aa2 <generic_kprobe_process_event+0x2aa2> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_28a2:
	/* 0x28a2: jmp    28aa <generic_kprobe_process_event+0x28aa> */
	X86_SIM_X86_JMP(0x28a2, 0x28aa, x86_l_28aa);
x86_l_28a4:
	/* 0x28a4: mov    DWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28aa:
	/* 0x28aa: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28af:
	/* 0x28af: lea    rdi,[rax+0x48] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_28b3:
	/* 0x28b3: mov    rdx,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_28b6:
	/* 0x28b6: add    rdx,0xd0 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 208ULL);
x86_l_28bd:
	/* 0x28bd: jns    28ca <generic_kprobe_process_event+0x28ca> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x28bd, 0x28ca, x86_l_28ca);
x86_l_28bf:
	/* 0x28bf: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_28c2:
	/* 0x28c2: jns    28d6 <generic_kprobe_process_event+0x28d6> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x28c2, 0x28d6, x86_l_28d6);
x86_l_28c4:
	/* 0x28c4: mov    eax,DWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28c6:
	/* 0x28c6: mov    DWORD PTR [rdi],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28c8:
	/* 0x28c8: jmp    28dc <generic_kprobe_process_event+0x28dc> */
	X86_SIM_X86_JMP(0x28c8, 0x28dc, x86_l_28dc);
x86_l_28ca:
	/* 0x28ca: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_28cf:
	/* 0x28cf: call   2ad4 <generic_kprobe_process_event+0x2ad4> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_28d4:
	/* 0x28d4: jmp    28dc <generic_kprobe_process_event+0x28dc> */
	X86_SIM_X86_JMP(0x28d4, 0x28dc, x86_l_28dc);
x86_l_28d6:
	/* 0x28d6: mov    DWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28dc:
	/* 0x28dc: add    QWORD PTR [rsp+0x8],0x4c */
	X86_SIM_RUN_OP(X86_OP_ALU_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 34359738444ULL);
x86_l_28e2:
	/* 0x28e2: add    r15,0x158 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 344ULL);
x86_l_28e9:
	/* 0x28e9: jns    2905 <generic_kprobe_process_event+0x2905> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x28e9, 0x2905, x86_l_2905);
x86_l_28eb:
	/* 0x28eb: test   r15,r15 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_28ee:
	/* 0x28ee: jns    2922 <generic_kprobe_process_event+0x2922> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x28ee, 0x2922, x86_l_2922);
x86_l_28f0:
	/* 0x28f0: mov    eax,DWORD PTR [r15] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28f3:
	/* 0x28f3: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28f8:
	/* 0x28f8: mov    DWORD PTR [rcx],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28fa:
	/* 0x28fa: mov    r15d,0x50 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 80ULL);
x86_l_2900:
	/* 0x2900: jmp    2d4e <generic_kprobe_process_event+0x2d4e> */
	X86_SIM_X86_JMP(0x2900, 0x2d4e, x86_l_2d4e);
x86_l_2905:
	/* 0x2905: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_290a:
	/* 0x290a: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_290f:
	/* 0x290f: mov    rdx,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_2912:
	/* 0x2912: call   2b17 <generic_kprobe_process_event+0x2b17> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_2917:
	/* 0x2917: mov    r15d,0x50 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 80ULL);
x86_l_291d:
	/* 0x291d: jmp    2d4e <generic_kprobe_process_event+0x2d4e> */
	X86_SIM_X86_JMP(0x291d, 0x2d4e, x86_l_2d4e);
x86_l_2922:
	/* 0x2922: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2927:
	/* 0x2927: mov    DWORD PTR [rax],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_292d:
	/* 0x292d: mov    r15d,0x50 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 80ULL);
x86_l_2933:
	/* 0x2933: jmp    2d4e <generic_kprobe_process_event+0x2d4e> */
	X86_SIM_X86_JMP(0x2933, 0x2d4e, x86_l_2d4e);
x86_l_2938:
	/* 0x2938: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_293d:
	/* 0x293d: mov    DWORD PTR [r15],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2944:
	/* 0x2944: lea    rdi,[r15+0x4] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2948:
	/* 0x2948: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_294d:
	/* 0x294d: add    rdx,0x3c */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 60ULL);
x86_l_2951:
	/* 0x2951: jns    295e <generic_kprobe_process_event+0x295e> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2951, 0x295e, x86_l_295e);
x86_l_2953:
	/* 0x2953: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_2956:
	/* 0x2956: jns    296a <generic_kprobe_process_event+0x296a> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2956, 0x296a, x86_l_296a);
x86_l_2958:
	/* 0x2958: mov    eax,DWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_295a:
	/* 0x295a: mov    DWORD PTR [rdi],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_295c:
	/* 0x295c: jmp    2970 <generic_kprobe_process_event+0x2970> */
	X86_SIM_X86_JMP(0x295c, 0x2970, x86_l_2970);
x86_l_295e:
	/* 0x295e: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_2963:
	/* 0x2963: call   2b68 <generic_kprobe_process_event+0x2b68> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_2968:
	/* 0x2968: jmp    2970 <generic_kprobe_process_event+0x2970> */
	X86_SIM_X86_JMP(0x2968, 0x2970, x86_l_2970);
x86_l_296a:
	/* 0x296a: mov    DWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2970:
	/* 0x2970: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2975:
	/* 0x2975: lea    rdi,[rax+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2979:
	/* 0x2979: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_297e:
	/* 0x297e: add    rdx,0x40 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 64ULL);
x86_l_2982:
	/* 0x2982: jns    298f <generic_kprobe_process_event+0x298f> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2982, 0x298f, x86_l_298f);
x86_l_2984:
	/* 0x2984: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_2987:
	/* 0x2987: jns    299b <generic_kprobe_process_event+0x299b> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2987, 0x299b, x86_l_299b);
x86_l_2989:
	/* 0x2989: mov    eax,DWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_298b:
	/* 0x298b: mov    DWORD PTR [rdi],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_298d:
	/* 0x298d: jmp    29a1 <generic_kprobe_process_event+0x29a1> */
	X86_SIM_X86_JMP(0x298d, 0x29a1, x86_l_29a1);
x86_l_298f:
	/* 0x298f: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_2994:
	/* 0x2994: call   2b99 <generic_kprobe_process_event+0x2b99> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_2999:
	/* 0x2999: jmp    29a1 <generic_kprobe_process_event+0x29a1> */
	X86_SIM_X86_JMP(0x2999, 0x29a1, x86_l_29a1);
x86_l_299b:
	/* 0x299b: mov    DWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29a1:
	/* 0x29a1: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_29a6:
	/* 0x29a6: lea    rdi,[rax+0xc] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_29aa:
	/* 0x29aa: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_29af:
	/* 0x29af: add    rdx,0x44 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 68ULL);
x86_l_29b3:
	/* 0x29b3: jns    29c0 <generic_kprobe_process_event+0x29c0> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x29b3, 0x29c0, x86_l_29c0);
x86_l_29b5:
	/* 0x29b5: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_29b8:
	/* 0x29b8: jns    29cc <generic_kprobe_process_event+0x29cc> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x29b8, 0x29cc, x86_l_29cc);
x86_l_29ba:
	/* 0x29ba: mov    eax,DWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29bc:
	/* 0x29bc: mov    DWORD PTR [rdi],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29be:
	/* 0x29be: jmp    29d2 <generic_kprobe_process_event+0x29d2> */
	X86_SIM_X86_JMP(0x29be, 0x29d2, x86_l_29d2);
x86_l_29c0:
	/* 0x29c0: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_29c5:
	/* 0x29c5: call   2bca <generic_kprobe_process_event+0x2bca> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_29ca:
	/* 0x29ca: jmp    29d2 <generic_kprobe_process_event+0x29d2> */
	X86_SIM_X86_JMP(0x29ca, 0x29d2, x86_l_29d2);
x86_l_29cc:
	/* 0x29cc: mov    DWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29d2:
	/* 0x29d2: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_29d7:
	/* 0x29d7: lea    rdi,[rax+0x10] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_29db:
	/* 0x29db: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_29e0:
	/* 0x29e0: sub    rdx,0xffffffffffffff80 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SUB, 18446744073709551488ULL);
x86_l_29e4:
	/* 0x29e4: jns    2a0d <generic_kprobe_process_event+0x2a0d> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x29e4, 0x2a0d, x86_l_2a0d);
x86_l_29e6:
	/* 0x29e6: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_29e9:
	/* 0x29e9: jns    2a22 <generic_kprobe_process_event+0x2a22> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x29e9, 0x2a22, x86_l_2a22);
x86_l_29eb:
	/* 0x29eb: mov    rax,rdx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_29ee:
	/* 0x29ee: mov    rax,QWORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29f1:
	/* 0x29f1: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_29f6:
	/* 0x29f6: mov    QWORD PTR [rcx+0x10],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_29fa:
	/* 0x29fa: mov    rax,QWORD PTR [rdx+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_29fe:
	/* 0x29fe: mov    QWORD PTR [rcx+0x18],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2a02:
	/* 0x2a02: mov    r15d,0x20 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 32ULL);
x86_l_2a08:
	/* 0x2a08: jmp    2d4e <generic_kprobe_process_event+0x2d4e> */
	X86_SIM_X86_JMP(0x2a08, 0x2d4e, x86_l_2d4e);
x86_l_2a0d:
	/* 0x2a0d: mov    esi,0x10 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 16ULL);
x86_l_2a12:
	/* 0x2a12: call   2c17 <generic_kprobe_process_event+0x2c17> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_2a17:
	/* 0x2a17: mov    r15d,0x20 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 32ULL);
x86_l_2a1d:
	/* 0x2a1d: jmp    2d4e <generic_kprobe_process_event+0x2d4e> */
	X86_SIM_X86_JMP(0x2a1d, 0x2d4e, x86_l_2d4e);
x86_l_2a22:
	/* 0x2a22: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_2a2a:
	/* 0x2a2a: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a31:
	/* 0x2a31: mov    r15d,0x20 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 32ULL);
x86_l_2a37:
	/* 0x2a37: jmp    2d4e <generic_kprobe_process_event+0x2d4e> */
	X86_SIM_X86_JMP(0x2a37, 0x2d4e, x86_l_2d4e);
x86_l_2a3c:
	/* 0x2a3c: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a41:
	/* 0x2a41: mov    DWORD PTR [r15],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a48:
	/* 0x2a48: lea    rdi,[r15+0x4] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2a4c:
	/* 0x2a4c: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2a51:
	/* 0x2a51: add    rdx,0xcc */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 204ULL);
x86_l_2a58:
	/* 0x2a58: jns    2a65 <generic_kprobe_process_event+0x2a65> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2a58, 0x2a65, x86_l_2a65);
x86_l_2a5a:
	/* 0x2a5a: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_2a5d:
	/* 0x2a5d: jns    2a71 <generic_kprobe_process_event+0x2a71> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2a5d, 0x2a71, x86_l_2a71);
x86_l_2a5f:
	/* 0x2a5f: mov    eax,DWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a61:
	/* 0x2a61: mov    DWORD PTR [rdi],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a63:
	/* 0x2a63: jmp    2a77 <generic_kprobe_process_event+0x2a77> */
	X86_SIM_X86_JMP(0x2a63, 0x2a77, x86_l_2a77);
x86_l_2a65:
	/* 0x2a65: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_2a6a:
	/* 0x2a6a: call   2c6f <generic_kprobe_process_event+0x2c6f> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_2a6f:
	/* 0x2a6f: jmp    2a77 <generic_kprobe_process_event+0x2a77> */
	X86_SIM_X86_JMP(0x2a6f, 0x2a77, x86_l_2a77);
x86_l_2a71:
	/* 0x2a71: mov    DWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a77:
	/* 0x2a77: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a7c:
	/* 0x2a7c: lea    rdi,[rax+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a80:
	/* 0x2a80: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2a85:
	/* 0x2a85: add    rdx,0xd0 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 208ULL);
x86_l_2a8c:
	/* 0x2a8c: jns    2a99 <generic_kprobe_process_event+0x2a99> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2a8c, 0x2a99, x86_l_2a99);
x86_l_2a8e:
	/* 0x2a8e: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_2a91:
	/* 0x2a91: jns    2aa5 <generic_kprobe_process_event+0x2aa5> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2a91, 0x2aa5, x86_l_2aa5);
x86_l_2a93:
	/* 0x2a93: mov    eax,DWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a95:
	/* 0x2a95: mov    DWORD PTR [rdi],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a97:
	/* 0x2a97: jmp    2aab <generic_kprobe_process_event+0x2aab> */
	X86_SIM_X86_JMP(0x2a97, 0x2aab, x86_l_2aab);
x86_l_2a99:
	/* 0x2a99: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_2a9e:
	/* 0x2a9e: call   2ca3 <generic_kprobe_process_event+0x2ca3> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_2aa3:
	/* 0x2aa3: jmp    2aab <generic_kprobe_process_event+0x2aab> */
	X86_SIM_X86_JMP(0x2aa3, 0x2aab, x86_l_2aab);
x86_l_2aa5:
	/* 0x2aa5: mov    DWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2aab:
	/* 0x2aab: add    QWORD PTR [rsp+0x8],0xc */
	X86_SIM_RUN_OP(X86_OP_ALU_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 34359738380ULL);
x86_l_2ab1:
	/* 0x2ab1: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2ab6:
	/* 0x2ab6: add    rdx,0x158 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 344ULL);
x86_l_2abd:
	/* 0x2abd: jns    2adb <generic_kprobe_process_event+0x2adb> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2abd, 0x2adb, x86_l_2adb);
x86_l_2abf:
	/* 0x2abf: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_2ac2:
	/* 0x2ac2: jns    2af5 <generic_kprobe_process_event+0x2af5> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2ac2, 0x2af5, x86_l_2af5);
x86_l_2ac4:
	/* 0x2ac4: mov    rax,rdx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_2ac7:
	/* 0x2ac7: mov    eax,DWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ac9:
	/* 0x2ac9: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ace:
	/* 0x2ace: mov    DWORD PTR [rcx],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ad0:
	/* 0x2ad0: mov    r15d,0x10 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 16ULL);
x86_l_2ad6:
	/* 0x2ad6: jmp    2d4e <generic_kprobe_process_event+0x2d4e> */
	X86_SIM_X86_JMP(0x2ad6, 0x2d4e, x86_l_2d4e);
x86_l_2adb:
	/* 0x2adb: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ae0:
	/* 0x2ae0: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_2ae5:
	/* 0x2ae5: call   2cea <generic_kprobe_process_event+0x2cea> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_2aea:
	/* 0x2aea: mov    r15d,0x10 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 16ULL);
x86_l_2af0:
	/* 0x2af0: jmp    2d4e <generic_kprobe_process_event+0x2d4e> */
	X86_SIM_X86_JMP(0x2af0, 0x2d4e, x86_l_2d4e);
x86_l_2af5:
	/* 0x2af5: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2afa:
	/* 0x2afa: mov    DWORD PTR [rax],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b00:
	/* 0x2b00: mov    r15d,0x10 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 16ULL);
x86_l_2b06:
	/* 0x2b06: jmp    2d4e <generic_kprobe_process_event+0x2d4e> */
	X86_SIM_X86_JMP(0x2b06, 0x2d4e, x86_l_2d4e);
x86_l_2b0b:
	/* 0x2b0b: mov    esi,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_2b10:
	/* 0x2b10: call   2d15 <generic_kprobe_process_event+0x2d15> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_2b15:
	/* 0x2b15: jmp    3286 <generic_kprobe_process_event+0x3286> */
	X86_SIM_X86_JMP(0x2b15, 0x3286, x86_l_3286);
x86_l_2b1a:
	/* 0x2b1a: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b1f:
	/* 0x2b1f: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_2b24:
	/* 0x2b24: call   2d29 <generic_kprobe_process_event+0x2d29> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_2b29:
	/* 0x2b29: jmp    3414 <generic_kprobe_process_event+0x3414> */
	X86_SIM_X86_JMP(0x2b29, 0x3414, x86_l_3414);
x86_l_2b2e:
	/* 0x2b2e: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b33:
	/* 0x2b33: mov    esi,0x10 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 16ULL);
x86_l_2b38:
	/* 0x2b38: call   2d3d <generic_kprobe_process_event+0x2d3d> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_2b3d:
	/* 0x2b3d: jmp    344e <generic_kprobe_process_event+0x344e> */
	X86_SIM_X86_JMP(0x2b3d, 0x344e, x86_l_344e);
x86_l_2b42:
	/* 0x2b42: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b47:
	/* 0x2b47: mov    DWORD PTR [rax],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b4d:
	/* 0x2b4d: mov    r15d,ebx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R15, X86_RBX, X86_WIDTH_32, 0, 0);
x86_l_2b50:
	/* 0x2b50: and    r15d,0xfff */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2b57:
	/* 0x2b57: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b5c:
	/* 0x2b5c: lea    rdi,[rax+0x4] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2b60:
	/* 0x2b60: mov    rsi,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_2b63:
	/* 0x2b63: add    rsi,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2b67:
	/* 0x2b67: test   r12,r12 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_2b6a:
	/* 0x2b6a: jns    2bbf <generic_kprobe_process_event+0x2bbf> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2b6a, 0x2bbf, x86_l_2bbf);
x86_l_2b6c:
	/* 0x2b6c: mov    rax,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_2b6f:
	/* 0x2b6f: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_2b72:
	/* 0x2b72: jns    2bc9 <generic_kprobe_process_event+0x2bc9> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2b72, 0x2bc9, x86_l_2bc9);
x86_l_2b74:
	/* 0x2b74: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_2b76:
	/* 0x2b76: cmp    r15d,0x4 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_2b7a:
	/* 0x2b7a: jb     2b96 <generic_kprobe_process_event+0x2b96> */
	X86_SIM_X86_JCC(X86_CC_B, 0x2b7a, 0x2b96, x86_l_2b96);
x86_l_2b7c:
	/* 0x2b7c: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_2b7e:
	/* 0x2b7e: mov    rdx,rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_2b81:
	/* 0x2b81: mov    rcx,QWORD PTR [rax+rcx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2b85:
	/* 0x2b85: mov    QWORD PTR [rdi+rdx*1],rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_2b89:
	/* 0x2b89: lea    rcx,[rdx+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b8d:
	/* 0x2b8d: add    rdx,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2b91:
	/* 0x2b91: cmp    rdx,rsi */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_2b94:
	/* 0x2b94: jbe    2b7e <generic_kprobe_process_event+0x2b7e> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x2b94, 0x2b7e, x86_l_2b7e);
x86_l_2b96:
	/* 0x2b96: test   bl,0x4 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, 0, 4ULL);
x86_l_2b99:
	/* 0x2b99: jne    2bd4 <generic_kprobe_process_event+0x2bd4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2b99, 0x2bd4, x86_l_2bd4);
x86_l_2b9b:
	/* 0x2b9b: mov    edx,ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_2b9d:
	/* 0x2b9d: mov    esi,DWORD PTR [rax+rdx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_2ba0:
	/* 0x2ba0: mov    DWORD PTR [rdi+rdx*1],esi */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_2ba3:
	/* 0x2ba3: or     ecx,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_OR, 4ULL);
x86_l_2ba6:
	/* 0x2ba6: test   bl,0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, 0, 2ULL);
x86_l_2ba9:
	/* 0x2ba9: je     2bd9 <generic_kprobe_process_event+0x2bd9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2ba9, 0x2bd9, x86_l_2bd9);
x86_l_2bab:
	/* 0x2bab: mov    edx,ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_2bad:
	/* 0x2bad: movzx  esi,WORD PTR [rax+rdx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RDX, 0, X86_WIDTH_16), 0ULL);
x86_l_2bb1:
	/* 0x2bb1: mov    WORD PTR [rdi+rdx*1],si */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RSI, X86_WIDTH_16, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_2bb5:
	/* 0x2bb5: add    ecx,0x2 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_2bb8:
	/* 0x2bb8: test   bl,0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_2bbb:
	/* 0x2bbb: je     2be7 <generic_kprobe_process_event+0x2be7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2bbb, 0x2be7, x86_l_2be7);
x86_l_2bbd:
	/* 0x2bbd: jmp    2bde <generic_kprobe_process_event+0x2bde> */
	X86_SIM_X86_JMP(0x2bbd, 0x2bde, x86_l_2bde);
x86_l_2bbf:
	/* 0x2bbf: mov    rdx,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_2bc2:
	/* 0x2bc2: call   2dc7 <generic_kprobe_process_event+0x2dc7> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_2bc7:
	/* 0x2bc7: jmp    2be7 <generic_kprobe_process_event+0x2be7> */
	X86_SIM_X86_JMP(0x2bc7, 0x2be7, x86_l_2be7);
x86_l_2bc9:
	/* 0x2bc9: mov    edx,esi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_2bcb:
	/* 0x2bcb: xor    esi,esi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_2bcd:
	/* 0x2bcd: call   4f97 <__native_link_local_memset_zero_dynamic> */
	X86_SIM_X86_CALL(x86_l_4f97, 0x2bd2ULL);
x86_l_2bd2:
	/* 0x2bd2: jmp    2be7 <generic_kprobe_process_event+0x2be7> */
	X86_SIM_X86_JMP(0x2bd2, 0x2be7, x86_l_2be7);
x86_l_2bd4:
	/* 0x2bd4: test   bl,0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, 0, 2ULL);
x86_l_2bd7:
	/* 0x2bd7: jne    2bab <generic_kprobe_process_event+0x2bab> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2bd7, 0x2bab, x86_l_2bab);
x86_l_2bd9:
	/* 0x2bd9: test   bl,0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_2bdc:
	/* 0x2bdc: je     2be7 <generic_kprobe_process_event+0x2be7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2bdc, 0x2be7, x86_l_2be7);
x86_l_2bde:
	/* 0x2bde: mov    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_2be0:
	/* 0x2be0: movzx  eax,BYTE PTR [rax+rcx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2be4:
	/* 0x2be4: mov    BYTE PTR [rdi+rcx*1],al */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2be7:
	/* 0x2be7: mov    eax,r15d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_R15, X86_WIDTH_32, 0, 0);
x86_l_2bea:
	/* 0x2bea: lea    r15,[rax+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2bee:
	/* 0x2bee: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2bf3:
	/* 0x2bf3: lea    rdi,[rcx+rax*1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2bf7:
	/* 0x2bf7: add    rdi,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2bfb:
	/* 0x2bfb: lea    rdx,[rax+r12*1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_2bff:
	/* 0x2bff: add    rdx,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2c03:
	/* 0x2c03: add    rdx,0xfffffffffffffffc */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551612ULL);
x86_l_2c07:
	/* 0x2c07: jns    2c14 <generic_kprobe_process_event+0x2c14> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2c07, 0x2c14, x86_l_2c14);
x86_l_2c09:
	/* 0x2c09: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_2c0c:
	/* 0x2c0c: jns    2c20 <generic_kprobe_process_event+0x2c20> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2c0c, 0x2c20, x86_l_2c20);
x86_l_2c0e:
	/* 0x2c0e: mov    eax,DWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c10:
	/* 0x2c10: mov    DWORD PTR [rdi],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c12:
	/* 0x2c12: jmp    2c26 <generic_kprobe_process_event+0x2c26> */
	X86_SIM_X86_JMP(0x2c12, 0x2c26, x86_l_2c26);
x86_l_2c14:
	/* 0x2c14: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_2c19:
	/* 0x2c19: call   2e1e <generic_kprobe_process_event+0x2e1e> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_2c1e:
	/* 0x2c1e: jmp    2c26 <generic_kprobe_process_event+0x2c26> */
	X86_SIM_X86_JMP(0x2c1e, 0x2c26, x86_l_2c26);
x86_l_2c20:
	/* 0x2c20: mov    DWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c26:
	/* 0x2c26: add    r15,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2c2a:
	/* 0x2c2a: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c2f:
	/* 0x2c2f: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2c34:
	/* 0x2c34: mov    rbx,r13 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RBX, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_2c37:
	/* 0x2c37: jmp    4246 <generic_kprobe_process_event+0x4246> */
	X86_SIM_X86_JMP(0x2c37, 0x4246, x86_l_4246);
x86_l_2c3c:
	/* 0x2c3c: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c41:
	/* 0x2c41: mov    DWORD PTR [r15],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c48:
	/* 0x2c48: lea    rdi,[r15+0x4] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2c4c:
	/* 0x2c4c: mov    rdx,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_2c4f:
	/* 0x2c4f: add    rdx,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2c53:
	/* 0x2c53: jns    2c60 <generic_kprobe_process_event+0x2c60> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2c53, 0x2c60, x86_l_2c60);
x86_l_2c55:
	/* 0x2c55: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_2c58:
	/* 0x2c58: jns    2c6c <generic_kprobe_process_event+0x2c6c> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2c58, 0x2c6c, x86_l_2c6c);
x86_l_2c5a:
	/* 0x2c5a: mov    eax,DWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c5c:
	/* 0x2c5c: mov    DWORD PTR [rdi],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c5e:
	/* 0x2c5e: jmp    2c72 <generic_kprobe_process_event+0x2c72> */
	X86_SIM_X86_JMP(0x2c5e, 0x2c72, x86_l_2c72);
x86_l_2c60:
	/* 0x2c60: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_2c65:
	/* 0x2c65: call   2e6a <generic_kprobe_process_event+0x2e6a> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_2c6a:
	/* 0x2c6a: jmp    2c72 <generic_kprobe_process_event+0x2c72> */
	X86_SIM_X86_JMP(0x2c6a, 0x2c72, x86_l_2c72);
x86_l_2c6c:
	/* 0x2c6c: mov    DWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c72:
	/* 0x2c72: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c77:
	/* 0x2c77: lea    rdi,[rax+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c7b:
	/* 0x2c7b: mov    rdx,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_2c7e:
	/* 0x2c7e: add    rdx,0x30 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_2c82:
	/* 0x2c82: jns    2cab <generic_kprobe_process_event+0x2cab> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2c82, 0x2cab, x86_l_2cab);
x86_l_2c84:
	/* 0x2c84: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_2c87:
	/* 0x2c87: jns    2cc0 <generic_kprobe_process_event+0x2cc0> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2c87, 0x2cc0, x86_l_2cc0);
x86_l_2c89:
	/* 0x2c89: mov    rax,rdx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_2c8c:
	/* 0x2c8c: mov    rax,QWORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c8f:
	/* 0x2c8f: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c94:
	/* 0x2c94: mov    QWORD PTR [rcx+0x8],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c98:
	/* 0x2c98: mov    rax,QWORD PTR [rdx+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c9c:
	/* 0x2c9c: mov    QWORD PTR [rcx+0x10],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ca0:
	/* 0x2ca0: mov    r15d,0x18 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 24ULL);
x86_l_2ca6:
	/* 0x2ca6: jmp    2d4e <generic_kprobe_process_event+0x2d4e> */
	X86_SIM_X86_JMP(0x2ca6, 0x2d4e, x86_l_2d4e);
x86_l_2cab:
	/* 0x2cab: mov    esi,0x10 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 16ULL);
x86_l_2cb0:
	/* 0x2cb0: call   2eb5 <generic_kprobe_process_event+0x2eb5> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_2cb5:
	/* 0x2cb5: mov    r15d,0x18 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 24ULL);
x86_l_2cbb:
	/* 0x2cbb: jmp    2d4e <generic_kprobe_process_event+0x2d4e> */
	X86_SIM_X86_JMP(0x2cbb, 0x2d4e, x86_l_2d4e);
x86_l_2cc0:
	/* 0x2cc0: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_2cc8:
	/* 0x2cc8: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ccf:
	/* 0x2ccf: mov    r15d,0x18 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 24ULL);
x86_l_2cd5:
	/* 0x2cd5: jmp    2d4e <generic_kprobe_process_event+0x2d4e> */
	X86_SIM_X86_JMP(0x2cd5, 0x2d4e, x86_l_2d4e);
x86_l_2cd7:
	/* 0x2cd7: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2cdc:
	/* 0x2cdc: xor    esi,esi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_2cde:
	/* 0x2cde: mov    rdx,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_2ce1:
	/* 0x2ce1: call   4f97 <__native_link_local_memset_zero_dynamic> */
	X86_SIM_X86_CALL(x86_l_4f97, 0x2ce6ULL);
x86_l_2ce6:
	/* 0x2ce6: jmp    2d4e <generic_kprobe_process_event+0x2d4e> */
	X86_SIM_X86_JMP(0x2ce6, 0x2d4e, x86_l_2d4e);
x86_l_2ce8:
	/* 0x2ce8: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_2ceb:
	/* 0x2ceb: jns    2d0c <generic_kprobe_process_event+0x2d0c> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2ceb, 0x2d0c, x86_l_2d0c);
x86_l_2ced:
	/* 0x2ced: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_2cef:
	/* 0x2cef: cmp    rax,0x3e */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, 0, 62ULL);
x86_l_2cf3:
	/* 0x2cf3: je     3e3e <generic_kprobe_process_event+0x3e3e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2cf3, 0x3e3e, x86_l_3e3e);
x86_l_2cf9:
	/* 0x2cf9: movzx  ecx,BYTE PTR [rdx+rax*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2cfd:
	/* 0x2cfd: mov    BYTE PTR [rdi+rax*1],cl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2d00:
	/* 0x2d00: inc    rax */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_2d03:
	/* 0x2d03: test   cl,cl */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8, 0, 0);
x86_l_2d05:
	/* 0x2d05: jne    2cef <generic_kprobe_process_event+0x2cef> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2d05, 0x2cef, x86_l_2cef);
x86_l_2d07:
	/* 0x2d07: jmp    1924 <generic_kprobe_process_event+0x1924> */
	X86_SIM_X86_JMP(0x2d07, 0x1924, x86_l_1924);
x86_l_2d0c:
	/* 0x2d0c: mov    QWORD PTR [rdi+0x37],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 236223201280ULL);
x86_l_2d14:
	/* 0x2d14: mov    QWORD PTR [rdi+0x30],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_2d1c:
	/* 0x2d1c: mov    QWORD PTR [rdi+0x28],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_2d24:
	/* 0x2d24: mov    QWORD PTR [rdi+0x20],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_2d2c:
	/* 0x2d2c: mov    QWORD PTR [rdi+0x18],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_2d34:
	/* 0x2d34: mov    QWORD PTR [rdi+0x10],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2d3c:
	/* 0x2d3c: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_2d44:
	/* 0x2d44: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d4b:
	/* 0x2d4b: xor    r15d,r15d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_2d4e:
	/* 0x2d4e: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d53:
	/* 0x2d53: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2d58:
	/* 0x2d58: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2d5d:
	/* 0x2d5d: mov    r12,QWORD PTR [rsp+0xb0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_2d65:
	/* 0x2d65: jmp    4253 <generic_kprobe_process_event+0x4253> */
	X86_SIM_X86_JMP(0x2d65, 0x4253, x86_l_4253);
x86_l_2d6a:
	/* 0x2d6a: lea    rdi,[rsp+0x70] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2d6f:
	/* 0x2d6f: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_2d74:
	/* 0x2d74: mov    rdx,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_2d77:
	/* 0x2d77: call   2f7c <generic_kprobe_process_event+0x2f7c> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_2d7c:
	/* 0x2d7c: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2d81:
	/* 0x2d81: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_2d84:
	/* 0x2d84: jns    3749 <generic_kprobe_process_event+0x3749> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2d84, 0x3749, x86_l_3749);
x86_l_2d8a:
	/* 0x2d8a: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_2d8d:
	/* 0x2d8d: jns    3b38 <generic_kprobe_process_event+0x3b38> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2d8d, 0x3b38, x86_l_3b38);
x86_l_2d93:
	/* 0x2d93: mov    rax,QWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d96:
	/* 0x2d96: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2d9b:
	/* 0x2d9b: jmp    3b41 <generic_kprobe_process_event+0x3b41> */
	X86_SIM_X86_JMP(0x2d9b, 0x3b41, x86_l_3b41);
x86_l_2da0:
	/* 0x2da0: mov    BYTE PTR [rdi+rax*1],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2da4:
	/* 0x2da4: mov    r15d,esi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R15, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_2da7:
	/* 0x2da7: jmp    2431 <generic_kprobe_process_event+0x2431> */
	X86_SIM_X86_JMP(0x2da7, 0x2431, x86_l_2431);
x86_l_2dac:
	/* 0x2dac: lea    rdi,[rsp+0x60] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2db1:
	/* 0x2db1: mov    esi,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_2db6:
	/* 0x2db6: call   2fbb <generic_kprobe_process_event+0x2fbb> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_2dbb:
	/* 0x2dbb: movzx  eax,BYTE PTR [rsp+0x60] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 96ULL);
x86_l_2dc0:
	/* 0x2dc0: jmp    3771 <generic_kprobe_process_event+0x3771> */
	X86_SIM_X86_JMP(0x2dc0, 0x3771, x86_l_3771);
x86_l_2dc5:
	/* 0x2dc5: mov    rax,rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_2dc8:
	/* 0x2dc8: add    rax,0x5e70 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 24176ULL);
x86_l_2dce:
	/* 0x2dce: jmp    2def <generic_kprobe_process_event+0x2def> */
	X86_SIM_X86_JMP(0x2dce, 0x2def, x86_l_2def);
x86_l_2dd0:
	/* 0x2dd0: mov    rax,rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_2dd3:
	/* 0x2dd3: add    rax,0x5e60 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 24160ULL);
x86_l_2dd9:
	/* 0x2dd9: jmp    2def <generic_kprobe_process_event+0x2def> */
	X86_SIM_X86_JMP(0x2dd9, 0x2def, x86_l_2def);
x86_l_2ddb:
	/* 0x2ddb: mov    rax,rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_2dde:
	/* 0x2dde: add    rax,0x5e68 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 24168ULL);
x86_l_2de4:
	/* 0x2de4: jmp    2def <generic_kprobe_process_event+0x2def> */
	X86_SIM_X86_JMP(0x2de4, 0x2def, x86_l_2def);
x86_l_2de6:
	/* 0x2de6: mov    rax,rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_2de9:
	/* 0x2de9: add    rax,0x5e58 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 24152ULL);
x86_l_2def:
	/* 0x2def: mov    r12,QWORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2df2:
	/* 0x2df2: test   BYTE PTR [rsp+0x30],0x10 */
	X86_SIM_RUN_OP(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430224ULL);
x86_l_2df7:
	/* 0x2df7: jne    2e4d <generic_kprobe_process_event+0x2e4d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2df7, 0x2e4d, x86_l_2e4d);
x86_l_2df9:
	/* 0x2df9: test   r12,r12 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_2dfc:
	/* 0x2dfc: je     2f7c <generic_kprobe_process_event+0x2f7c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2dfc, 0x2f7c, x86_l_2f7c);
x86_l_2e02:
	/* 0x2e02: cmp    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_2e08:
	/* 0x2e08: js     3653 <generic_kprobe_process_event+0x3653> */
	X86_SIM_X86_JCC(X86_CC_S, 0x2e08, 0x3653, x86_l_3653);
x86_l_2e0e:
	/* 0x2e0e: lea    rdi,[rsp+0x70] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2e13:
	/* 0x2e13: mov    esi,0x10 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 16ULL);
x86_l_2e18:
	/* 0x2e18: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2e1d:
	/* 0x2e1d: call   3022 <generic_kprobe_process_event+0x3022> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_2e22:
	/* 0x2e22: mov    ecx,0xfffffffe */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 4294967294ULL);
x86_l_2e27:
	/* 0x2e27: test   eax,eax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_2e29:
	/* 0x2e29: js     43b8 <generic_kprobe_process_event+0x43b8> */
	X86_SIM_X86_JCC(X86_CC_S, 0x2e29, 0x43b8, x86_l_43b8);
x86_l_2e2f:
	/* 0x2e2f: mov    r15,QWORD PTR [rsp+0x78] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2e34:
	/* 0x2e34: jmp    3677 <generic_kprobe_process_event+0x3677> */
	X86_SIM_X86_JMP(0x2e34, 0x3677, x86_l_3677);
x86_l_2e39:
	/* 0x2e39: xor    r12d,r12d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_2e3c:
	/* 0x2e3c: mov    r15d,0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 0ULL);
x86_l_2e42:
	/* 0x2e42: test   BYTE PTR [rsp+0x30],0x10 */
	X86_SIM_RUN_OP(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430224ULL);
x86_l_2e47:
	/* 0x2e47: je     2f7f <generic_kprobe_process_event+0x2f7f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2e47, 0x2f7f, x86_l_2f7f);
x86_l_2e4d:
	/* 0x2e4d: call   3052 <generic_kprobe_process_event+0x3052> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_get_current_pid_tgid);
x86_l_2e52:
	/* 0x2e52: cmp    rax,0xffffffffffffffea */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, 0, 18446744073709551594ULL);
x86_l_2e56:
	/* 0x2e56: jne    2e61 <generic_kprobe_process_event+0x2e61> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2e56, 0x2e61, x86_l_2e61);
x86_l_2e58:
	/* 0x2e58: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2e5d:
	/* 0x2e5d: mov    rax,QWORD PTR [rax+0x20] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2e61:
	/* 0x2e61: mov    rcx,QWORD PTR [rbx+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e65:
	/* 0x2e65: mov    rdx,QWORD PTR [rbx+0x60] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2e69:
	/* 0x2e69: mov    QWORD PTR [rsp+0x70],rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2e6e:
	/* 0x2e6e: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2e73:
	/* 0x2e73: mov    QWORD PTR [rsp+0x78],rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2e78:
	/* 0x2e78: mov    QWORD PTR [rsp+0x80],r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2e80:
	/* 0x2e80: mov    QWORD PTR [rsp+0x60],rdx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2e85:
	/* 0x2e85: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2e8a:
	/* 0x2e8a: mov    rdi,QWORD PTR [rip+0x200] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)retprobe_map));
x86_l_2e91:
	/* 0x2e91: lea    rsi,[rsp+0x60] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2e96:
	/* 0x2e96: lea    rdx,[rsp+0x70] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2e9b:
	/* 0x2e9b: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_2e9d:
	/* 0x2e9d: call   30a2 <generic_kprobe_process_event+0x30a2> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_update_elem);
x86_l_2ea2:
	/* 0x2ea2: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_2ea5:
	/* 0x2ea5: je     323a <generic_kprobe_process_event+0x323a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2ea5, 0x323a, x86_l_323a);
x86_l_2eab:
	/* 0x2eab: neg    eax */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_2ead:
	/* 0x2ead: mov    WORD PTR [rsp+0x50],ax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2eb2:
	/* 0x2eb2: mov    WORD PTR [rsp+0x52],0x5 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 352187318277ULL);
x86_l_2eb9:
	/* 0x2eb9: movabs rax,0x200000057 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, 0, 8589934679ULL);
x86_l_2ec3:
	/* 0x2ec3: mov    QWORD PTR [rsp+0x54],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_2ec8:
	/* 0x2ec8: mov    rdi,QWORD PTR [rip+0x200] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)tg_errmetrics_map));
x86_l_2ecf:
	/* 0x2ecf: lea    rsi,[rsp+0x50] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2ed4:
	/* 0x2ed4: call   30d9 <generic_kprobe_process_event+0x30d9> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_2ed9:
	/* 0x2ed9: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_2edc:
	/* 0x2edc: je     321a <generic_kprobe_process_event+0x321a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2edc, 0x321a, x86_l_321a);
x86_l_2ee2:
	/* 0x2ee2: inc    DWORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_ALU_MEM_UNARY, X86_RAX, X86_REG_NONE, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_2ee4:
	/* 0x2ee4: jmp    323a <generic_kprobe_process_event+0x323a> */
	X86_SIM_X86_JMP(0x2ee4, 0x323a, x86_l_323a);
x86_l_2ee9:
	/* 0x2ee9: add    r15,0x3 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 3ULL);
x86_l_2eed:
	/* 0x2eed: test   r15,r15 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_2ef0:
	/* 0x2ef0: jns    3a50 <generic_kprobe_process_event+0x3a50> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2ef0, 0x3a50, x86_l_3a50);
x86_l_2ef6:
	/* 0x2ef6: mov    rax,QWORD PTR [r15] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ef9:
	/* 0x2ef9: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2efe:
	/* 0x2efe: mov    QWORD PTR [rcx+0x4],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2f02:
	/* 0x2f02: mov    rax,QWORD PTR [r15+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f06:
	/* 0x2f06: mov    QWORD PTR [rcx+0xc],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2f0a:
	/* 0x2f0a: mov    rax,QWORD PTR [r15+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f0e:
	/* 0x2f0e: mov    QWORD PTR [rcx+0x14],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2f12:
	/* 0x2f12: mov    rax,QWORD PTR [r15+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2f16:
	/* 0x2f16: mov    QWORD PTR [rcx+0x1c],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2f1a:
	/* 0x2f1a: mov    rax,QWORD PTR [r15+0x20] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2f1e:
	/* 0x2f1e: mov    QWORD PTR [rcx+0x24],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2f22:
	/* 0x2f22: mov    rax,QWORD PTR [r15+0x28] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2f26:
	/* 0x2f26: mov    QWORD PTR [rcx+0x2c],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_2f2a:
	/* 0x2f2a: mov    rax,QWORD PTR [r15+0x30] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2f2e:
	/* 0x2f2e: mov    QWORD PTR [rcx+0x34],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2f32:
	/* 0x2f32: mov    rax,QWORD PTR [r15+0x38] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2f36:
	/* 0x2f36: mov    QWORD PTR [rcx+0x3c],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_2f3a:
	/* 0x2f3a: mov    rax,QWORD PTR [r15+0x40] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2f3e:
	/* 0x2f3e: mov    QWORD PTR [rcx+0x44],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_2f42:
	/* 0x2f42: mov    rax,QWORD PTR [r15+0x48] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2f46:
	/* 0x2f46: mov    QWORD PTR [rcx+0x4c],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_2f4a:
	/* 0x2f4a: mov    rax,QWORD PTR [r15+0x50] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2f4e:
	/* 0x2f4e: mov    QWORD PTR [rcx+0x54],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_2f52:
	/* 0x2f52: mov    rax,QWORD PTR [r15+0x58] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2f56:
	/* 0x2f56: mov    QWORD PTR [rcx+0x5c],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_2f5a:
	/* 0x2f5a: mov    rax,QWORD PTR [r15+0x60] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2f5e:
	/* 0x2f5e: mov    QWORD PTR [rcx+0x64],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 100ULL);
x86_l_2f62:
	/* 0x2f62: movzx  eax,WORD PTR [r15+0x68] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 104ULL);
x86_l_2f67:
	/* 0x2f67: mov    WORD PTR [rcx+0x6c],ax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_2f6b:
	/* 0x2f6b: movzx  eax,BYTE PTR [r15+0x6a] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 106ULL);
x86_l_2f70:
	/* 0x2f70: mov    BYTE PTR [rcx+0x6e],al */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 110ULL);
x86_l_2f73:
	/* 0x2f73: mov    BYTE PTR [rcx+0x3],0x6b */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 12884901995ULL);
x86_l_2f77:
	/* 0x2f77: jmp    4236 <generic_kprobe_process_event+0x4236> */
	X86_SIM_X86_JMP(0x2f77, 0x4236, x86_l_4236);
x86_l_2f7c:
	/* 0x2f7c: xor    r15d,r15d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_2f7f:
	/* 0x2f7f: mov    rax,QWORD PTR [rsp+0xb8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_2f87:
	/* 0x2f87: mov    DWORD PTR [rbp+rax*1+0x0],r15d */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2f8c:
	/* 0x2f8c: mov    DWORD PTR [rbp+rax*1+0x4],r15d */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 4ULL);
x86_l_2f91:
	/* 0x2f91: add    r15,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2f95:
	/* 0x2f95: jmp    43ca <generic_kprobe_process_event+0x43ca> */
	X86_SIM_X86_JMP(0x2f95, 0x43ca, x86_l_43ca);
x86_l_2f9a:
	/* 0x2f9a: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_2fa3:
	/* 0x2fa3: add    r15,0x18 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_2fa7:
	/* 0x2fa7: jns    2fb8 <generic_kprobe_process_event+0x2fb8> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2fa7, 0x2fb8, x86_l_2fb8);
x86_l_2fa9:
	/* 0x2fa9: test   r15,r15 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_2fac:
	/* 0x2fac: jns    3003 <generic_kprobe_process_event+0x3003> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2fac, 0x3003, x86_l_3003);
x86_l_2fae:
	/* 0x2fae: mov    rbx,QWORD PTR [r15] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2fb1:
	/* 0x2fb1: mov    QWORD PTR [rsp+0x50],rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2fb6:
	/* 0x2fb6: jmp    2fcf <generic_kprobe_process_event+0x2fcf> */
	X86_SIM_X86_JMP(0x2fb6, 0x2fcf, x86_l_2fcf);
x86_l_2fb8:
	/* 0x2fb8: lea    rdi,[rsp+0x50] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2fbd:
	/* 0x2fbd: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_2fc2:
	/* 0x2fc2: mov    rdx,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_2fc5:
	/* 0x2fc5: call   31ca <generic_kprobe_process_event+0x31ca> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_2fca:
	/* 0x2fca: mov    rbx,QWORD PTR [rsp+0x50] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2fcf:
	/* 0x2fcf: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2fd4:
	/* 0x2fd4: mov    rax,QWORD PTR [rsp+0xb8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_2fdc:
	/* 0x2fdc: lea    r12,[rax+r13*1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_2fe0:
	/* 0x2fe0: add    r12,0x90 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_2fe7:
	/* 0x2fe7: mov    r15d,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_2fed:
	/* 0x2fed: test   BYTE PTR [rsp+0x30],0x20 */
	X86_SIM_RUN_OP(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430240ULL);
x86_l_2ff2:
	/* 0x2ff2: je     3059 <generic_kprobe_process_event+0x3059> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2ff2, 0x3059, x86_l_3059);
x86_l_2ff4:
	/* 0x2ff4: cmp    rbx,0x1000 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 4096ULL);
x86_l_2ffb:
	/* 0x2ffb: jae    3ba8 <generic_kprobe_process_event+0x3ba8> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x2ffb, 0x3ba8, x86_l_3ba8);
x86_l_3001:
	/* 0x3001: jmp    3034 <generic_kprobe_process_event+0x3034> */
	X86_SIM_X86_JMP(0x3001, 0x3034, x86_l_3034);
x86_l_3003:
	/* 0x3003: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_300c:
	/* 0x300c: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_3011:
	/* 0x3011: xor    ebx,ebx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_3013:
	/* 0x3013: test   r12b,0x20 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, 0, 32ULL);
x86_l_3017:
	/* 0x3017: jne    3034 <generic_kprobe_process_event+0x3034> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x3017, 0x3034, x86_l_3034);
x86_l_3019:
	/* 0x3019: mov    rax,QWORD PTR [rsp+0xb8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_3021:
	/* 0x3021: lea    r12,[rax+r13*1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_3025:
	/* 0x3025: add    r12,0x90 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_302c:
	/* 0x302c: mov    r15d,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_3032:
	/* 0x3032: jmp    3059 <generic_kprobe_process_event+0x3059> */
	X86_SIM_X86_JMP(0x3032, 0x3059, x86_l_3059);
x86_l_3034:
	/* 0x3034: mov    rax,QWORD PTR [rsp+0xb0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_303c:
	/* 0x303c: mov    DWORD PTR [r13+rax*1+0x94],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 635655159808ULL);
x86_l_3048:
	/* 0x3048: lea    r12,[rax+r13*1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_304c:
	/* 0x304c: add    r12,0x98 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 152ULL);
x86_l_3053:
	/* 0x3053: mov    r15d,0xc */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 12ULL);
x86_l_3059:
	/* 0x3059: cmp    rbx,0xfff */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 4095ULL);
x86_l_3060:
	/* 0x3060: mov    r13d,0xfff */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, 0, 4095ULL);
x86_l_3066:
	/* 0x3066: cmovb  r13,rbx */
	X86_SIM_RUN_OP(X86_OP_CMOV, X86_R13, X86_RBX, X86_WIDTH_64, X86_CC_B, 0);
x86_l_306a:
	/* 0x306a: lea    rdi,[r12+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_306f:
	/* 0x306f: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_3072:
	/* 0x3072: jns    3c9b <generic_kprobe_process_event+0x3c9b> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x3072, 0x3c9b, x86_l_3c9b);
x86_l_3078:
	/* 0x3078: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_307b:
	/* 0x307b: jns    3cac <generic_kprobe_process_event+0x3cac> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x307b, 0x3cac, x86_l_3cac);
x86_l_3081:
	/* 0x3081: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_3083:
	/* 0x3083: cmp    r13d,0x8 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_3087:
	/* 0x3087: jb     30a3 <generic_kprobe_process_event+0x30a3> */
	X86_SIM_X86_JCC(X86_CC_B, 0x3087, 0x30a3, x86_l_30a3);
x86_l_3089:
	/* 0x3089: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_308b:
	/* 0x308b: mov    rcx,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_308e:
	/* 0x308e: mov    rax,QWORD PTR [rdx+rax*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3092:
	/* 0x3092: mov    QWORD PTR [rdi+rcx*1],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3096:
	/* 0x3096: lea    rax,[rcx+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_309a:
	/* 0x309a: add    rcx,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_309e:
	/* 0x309e: cmp    rcx,r13 */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RCX, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_30a1:
	/* 0x30a1: jbe    308b <generic_kprobe_process_event+0x308b> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x30a1, 0x308b, x86_l_308b);
x86_l_30a3:
	/* 0x30a3: test   r13b,0x4 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, 0, 4ULL);
x86_l_30a7:
	/* 0x30a7: jne    3d50 <generic_kprobe_process_event+0x3d50> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x30a7, 0x3d50, x86_l_3d50);
x86_l_30ad:
	/* 0x30ad: test   r13b,0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, 0, 2ULL);
x86_l_30b1:
	/* 0x30b1: jne    3d65 <generic_kprobe_process_event+0x3d65> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x30b1, 0x3d65, x86_l_3d65);
x86_l_30b7:
	/* 0x30b7: test   r13b,0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_30bb:
	/* 0x30bb: jne    3d7c <generic_kprobe_process_event+0x3d7c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x30bb, 0x3d7c, x86_l_3d7c);
x86_l_30c1:
	/* 0x30c1: jmp    3ff5 <generic_kprobe_process_event+0x3ff5> */
	X86_SIM_X86_JMP(0x30c1, 0x3ff5, x86_l_3ff5);
x86_l_30c6:
	/* 0x30c6: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_30c8:
	/* 0x30c8: add    rax,0x360 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 864ULL);
x86_l_30ce:
	/* 0x30ce: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_30d1:
	/* 0x30d1: jns    30d8 <generic_kprobe_process_event+0x30d8> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x30d1, 0x30d8, x86_l_30d8);
x86_l_30d3:
	/* 0x30d3: mov    rax,QWORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_30d6:
	/* 0x30d6: jmp    30da <generic_kprobe_process_event+0x30da> */
	X86_SIM_X86_JMP(0x30d6, 0x30da, x86_l_30da);
x86_l_30d8:
	/* 0x30d8: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_30da:
	/* 0x30da: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_30df:
	/* 0x30df: mov    QWORD PTR [rcx+0x8],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_30e3:
	/* 0x30e3: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_30e8:
	/* 0x30e8: add    rcx,0x58 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 88ULL);
x86_l_30ec:
	/* 0x30ec: mov    r15d,0x50 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 80ULL);
x86_l_30f2:
	/* 0x30f2: test   rcx,rcx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_30f5:
	/* 0x30f5: jns    2d4e <generic_kprobe_process_event+0x2d4e> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x30f5, 0x2d4e, x86_l_2d4e);
x86_l_30fb:
	/* 0x30fb: mov    rax,rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_30fe:
	/* 0x30fe: mov    eax,DWORD PTR [rcx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3100:
	/* 0x3100: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_3102:
	/* 0x3102: test   eax,eax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_3104:
	/* 0x3104: setne  cl */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_CC_NE, 0);
x86_l_3107:
	/* 0x3107: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_310c:
	/* 0x310c: mov    DWORD PTR [rax],ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_310e:
	/* 0x310e: jmp    2d4e <generic_kprobe_process_event+0x2d4e> */
	X86_SIM_X86_JMP(0x310e, 0x2d4e, x86_l_2d4e);
x86_l_3113:
	/* 0x3113: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3118:
	/* 0x3118: mov    QWORD PTR [rax+0x78],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_3120:
	/* 0x3120: mov    QWORD PTR [rax+0x70],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_3128:
	/* 0x3128: mov    QWORD PTR [rax+0x68],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_3130:
	/* 0x3130: mov    QWORD PTR [rax+0x60],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_3138:
	/* 0x3138: mov    QWORD PTR [rax+0x58],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_3140:
	/* 0x3140: mov    QWORD PTR [rax+0x50],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_3148:
	/* 0x3148: mov    QWORD PTR [rax+0x48],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_3150:
	/* 0x3150: mov    QWORD PTR [rax+0x40],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_3158:
	/* 0x3158: mov    QWORD PTR [rax+0x38],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_3160:
	/* 0x3160: mov    QWORD PTR [rax+0x30],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_3168:
	/* 0x3168: mov    QWORD PTR [rax+0x28],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_3170:
	/* 0x3170: mov    QWORD PTR [rax+0x20],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_3178:
	/* 0x3178: mov    QWORD PTR [rax+0x18],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_3180:
	/* 0x3180: mov    QWORD PTR [rax+0x10],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3188:
	/* 0x3188: mov    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_3190:
	/* 0x3190: mov    QWORD PTR [rax],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3197:
	/* 0x3197: jmp    2504 <generic_kprobe_process_event+0x2504> */
	X86_SIM_X86_JMP(0x3197, 0x2504, x86_l_2504);
x86_l_319c:
	/* 0x319c: lea    rdi,[rsp+0x70] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_31a1:
	/* 0x31a1: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_31a6:
	/* 0x31a6: call   33ab <generic_kprobe_process_event+0x33ab> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_31ab:
	/* 0x31ab: mov    eax,DWORD PTR [rsp+0x70] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_31af:
	/* 0x31af: jmp    3cd3 <generic_kprobe_process_event+0x3cd3> */
	X86_SIM_X86_JMP(0x31af, 0x3cd3, x86_l_3cd3);
x86_l_31b4:
	/* 0x31b4: mov    esi,0x10 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 16ULL);
x86_l_31b9:
	/* 0x31b9: call   33be <generic_kprobe_process_event+0x33be> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_31be:
	/* 0x31be: jmp    3d05 <generic_kprobe_process_event+0x3d05> */
	X86_SIM_X86_JMP(0x31be, 0x3d05, x86_l_3d05);
x86_l_31c3:
	/* 0x31c3: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_31c8:
	/* 0x31c8: mov    BYTE PTR [rax+0x4e],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 335007449088ULL);
x86_l_31cc:
	/* 0x31cc: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_31d1:
	/* 0x31d1: add    rcx,0x360 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 864ULL);
x86_l_31d8:
	/* 0x31d8: test   rcx,rcx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_31db:
	/* 0x31db: jns    31f7 <generic_kprobe_process_event+0x31f7> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x31db, 0x31f7, x86_l_31f7);
x86_l_31dd:
	/* 0x31dd: mov    rax,rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_31e0:
	/* 0x31e0: mov    rax,QWORD PTR [rcx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_31e3:
	/* 0x31e3: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_31e8:
	/* 0x31e8: mov    QWORD PTR [rcx+0x8],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_31ec:
	/* 0x31ec: mov    r15d,0x50 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 80ULL);
x86_l_31f2:
	/* 0x31f2: jmp    2d4e <generic_kprobe_process_event+0x2d4e> */
	X86_SIM_X86_JMP(0x31f2, 0x2d4e, x86_l_2d4e);
x86_l_31f7:
	/* 0x31f7: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_31fc:
	/* 0x31fc: mov    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_3204:
	/* 0x3204: mov    r15d,0x50 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 80ULL);
x86_l_320a:
	/* 0x320a: jmp    2d4e <generic_kprobe_process_event+0x2d4e> */
	X86_SIM_X86_JMP(0x320a, 0x2d4e, x86_l_2d4e);
x86_l_320f:
	/* 0x320f: mov    r15d,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_3215:
	/* 0x3215: jmp    45ce <generic_kprobe_process_event+0x45ce> */
	X86_SIM_X86_JMP(0x3215, 0x45ce, x86_l_45ce);
x86_l_321a:
	/* 0x321a: mov    DWORD PTR [rsp+0x40],0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 274877906945ULL);
x86_l_3222:
	/* 0x3222: mov    rdi,QWORD PTR [rip+0x200] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)tg_errmetrics_map));
x86_l_3229:
	/* 0x3229: lea    rsi,[rsp+0x50] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_322e:
	/* 0x322e: lea    rdx,[rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3233:
	/* 0x3233: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_3235:
	/* 0x3235: call   343a <generic_kprobe_process_event+0x343a> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_update_elem);
x86_l_323a:
	/* 0x323a: mov    rax,QWORD PTR [rsp+0xb8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_3242:
	/* 0x3242: mov    DWORD PTR [rbp+rax*1+0x0],0xfffffffc */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 4294967292ULL);
x86_l_324a:
	/* 0x324a: jmp    43c4 <generic_kprobe_process_event+0x43c4> */
	X86_SIM_X86_JMP(0x324a, 0x43c4, x86_l_43c4);
x86_l_324f:
	/* 0x324f: mov    DWORD PTR [rsp+0xc0],0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 824633720833ULL);
x86_l_325a:
	/* 0x325a: mov    rdi,QWORD PTR [rip+0x200] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)tg_errmetrics_map));
x86_l_3261:
	/* 0x3261: lea    rsi,[rsp+0x50] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3266:
	/* 0x3266: lea    rdx,[rsp+0xc0] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_326e:
	/* 0x326e: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_3270:
	/* 0x3270: call   3475 <generic_kprobe_process_event+0x3475> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_update_elem);
x86_l_3275:
	/* 0x3275: mov    DWORD PTR [rbp+0x0],0xfffffffc */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4294967292ULL);
x86_l_327c:
	/* 0x327c: jmp    3b10 <generic_kprobe_process_event+0x3b10> */
	X86_SIM_X86_JMP(0x327c, 0x3b10, x86_l_3b10);
x86_l_3281:
	/* 0x3281: mov    WORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3286:
	/* 0x3286: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_328b:
	/* 0x328b: lea    rdi,[rax+0x3a] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 58ULL);
x86_l_328f:
	/* 0x328f: mov    rdx,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_3292:
	/* 0x3292: add    rdx,0x12 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 18ULL);
x86_l_3296:
	/* 0x3296: jns    32a4 <generic_kprobe_process_event+0x32a4> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x3296, 0x32a4, x86_l_32a4);
x86_l_3298:
	/* 0x3298: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_329b:
	/* 0x329b: jns    32b0 <generic_kprobe_process_event+0x32b0> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x329b, 0x32b0, x86_l_32b0);
x86_l_329d:
	/* 0x329d: movzx  eax,BYTE PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_32a0:
	/* 0x32a0: mov    BYTE PTR [rdi],al */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_32a2:
	/* 0x32a2: jmp    32b3 <generic_kprobe_process_event+0x32b3> */
	X86_SIM_X86_JMP(0x32a2, 0x32b3, x86_l_32b3);
x86_l_32a4:
	/* 0x32a4: mov    esi,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_32a9:
	/* 0x32a9: call   34ae <generic_kprobe_process_event+0x34ae> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_32ae:
	/* 0x32ae: jmp    32b3 <generic_kprobe_process_event+0x32b3> */
	X86_SIM_X86_JMP(0x32ae, 0x32b3, x86_l_32b3);
x86_l_32b0:
	/* 0x32b0: mov    BYTE PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_32b3:
	/* 0x32b3: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_32b8:
	/* 0x32b8: lea    rdi,[rax+0x38] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_32bc:
	/* 0x32bc: mov    rdx,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_32bf:
	/* 0x32bf: add    rdx,0x21e */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 542ULL);
x86_l_32c6:
	/* 0x32c6: jns    32d5 <generic_kprobe_process_event+0x32d5> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x32c6, 0x32d5, x86_l_32d5);
x86_l_32c8:
	/* 0x32c8: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_32cb:
	/* 0x32cb: jns    32e1 <generic_kprobe_process_event+0x32e1> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x32cb, 0x32e1, x86_l_32e1);
x86_l_32cd:
	/* 0x32cd: movzx  eax,WORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_32d0:
	/* 0x32d0: mov    WORD PTR [rdi],ax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_32d3:
	/* 0x32d3: jmp    32e6 <generic_kprobe_process_event+0x32e6> */
	X86_SIM_X86_JMP(0x32d3, 0x32e6, x86_l_32e6);
x86_l_32d5:
	/* 0x32d5: mov    esi,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_32da:
	/* 0x32da: call   34df <generic_kprobe_process_event+0x34df> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_32df:
	/* 0x32df: jmp    32e6 <generic_kprobe_process_event+0x32e6> */
	X86_SIM_X86_JMP(0x32df, 0x32e6, x86_l_32e6);
x86_l_32e1:
	/* 0x32e1: mov    WORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_32e6:
	/* 0x32e6: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_32eb:
	/* 0x32eb: lea    rdi,[rax+0x24] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_32ef:
	/* 0x32ef: mov    rdx,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_32f2:
	/* 0x32f2: add    rdx,0x21c */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 540ULL);
x86_l_32f9:
	/* 0x32f9: jns    3308 <generic_kprobe_process_event+0x3308> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x32f9, 0x3308, x86_l_3308);
x86_l_32fb:
	/* 0x32fb: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_32fe:
	/* 0x32fe: jns    3314 <generic_kprobe_process_event+0x3314> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x32fe, 0x3314, x86_l_3314);
x86_l_3300:
	/* 0x3300: movzx  eax,WORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3303:
	/* 0x3303: mov    WORD PTR [rdi],ax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3306:
	/* 0x3306: jmp    3319 <generic_kprobe_process_event+0x3319> */
	X86_SIM_X86_JMP(0x3306, 0x3319, x86_l_3319);
x86_l_3308:
	/* 0x3308: mov    esi,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_330d:
	/* 0x330d: call   3512 <generic_kprobe_process_event+0x3512> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_3312:
	/* 0x3312: jmp    3319 <generic_kprobe_process_event+0x3319> */
	X86_SIM_X86_JMP(0x3312, 0x3319, x86_l_3319);
x86_l_3314:
	/* 0x3314: mov    WORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3319:
	/* 0x3319: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_331e:
	/* 0x331e: lea    rdi,[rax+0x30] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3322:
	/* 0x3322: mov    rdx,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_3325:
	/* 0x3325: add    rdx,0x214 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 532ULL);
x86_l_332c:
	/* 0x332c: jns    3339 <generic_kprobe_process_event+0x3339> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x332c, 0x3339, x86_l_3339);
x86_l_332e:
	/* 0x332e: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_3331:
	/* 0x3331: jns    3345 <generic_kprobe_process_event+0x3345> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x3331, 0x3345, x86_l_3345);
x86_l_3333:
	/* 0x3333: mov    eax,DWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3335:
	/* 0x3335: mov    DWORD PTR [rdi],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3337:
	/* 0x3337: jmp    334b <generic_kprobe_process_event+0x334b> */
	X86_SIM_X86_JMP(0x3337, 0x334b, x86_l_334b);
x86_l_3339:
	/* 0x3339: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_333e:
	/* 0x333e: call   3543 <generic_kprobe_process_event+0x3543> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_3343:
	/* 0x3343: jmp    334b <generic_kprobe_process_event+0x334b> */
	X86_SIM_X86_JMP(0x3343, 0x334b, x86_l_334b);
x86_l_3345:
	/* 0x3345: mov    DWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_334b:
	/* 0x334b: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3350:
	/* 0x3350: lea    rdi,[rax+0x34] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_3354:
	/* 0x3354: mov    rdx,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_3357:
	/* 0x3357: add    rdx,0x210 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 528ULL);
x86_l_335e:
	/* 0x335e: jns    336b <generic_kprobe_process_event+0x336b> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x335e, 0x336b, x86_l_336b);
x86_l_3360:
	/* 0x3360: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_3363:
	/* 0x3363: jns    3377 <generic_kprobe_process_event+0x3377> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x3363, 0x3377, x86_l_3377);
x86_l_3365:
	/* 0x3365: mov    eax,DWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3367:
	/* 0x3367: mov    DWORD PTR [rdi],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3369:
	/* 0x3369: jmp    337d <generic_kprobe_process_event+0x337d> */
	X86_SIM_X86_JMP(0x3369, 0x337d, x86_l_337d);
x86_l_336b:
	/* 0x336b: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_3370:
	/* 0x3370: call   3575 <generic_kprobe_process_event+0x3575> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_3375:
	/* 0x3375: jmp    337d <generic_kprobe_process_event+0x337d> */
	X86_SIM_X86_JMP(0x3375, 0x337d, x86_l_337d);
x86_l_3377:
	/* 0x3377: mov    DWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_337d:
	/* 0x337d: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3382:
	/* 0x3382: lea    r12,[rax+0x10] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3386:
	/* 0x3386: mov    QWORD PTR [rax+0x18],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_338e:
	/* 0x338e: mov    QWORD PTR [rax+0x10],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3396:
	/* 0x3396: mov    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_339e:
	/* 0x339e: mov    QWORD PTR [rax],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_33a5:
	/* 0x33a5: movzx  eax,WORD PTR [rax+0x26] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_33a9:
	/* 0x33a9: cmp    eax,0xa */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 10ULL);
x86_l_33ac:
	/* 0x33ac: je     33db <generic_kprobe_process_event+0x33db> */
	X86_SIM_X86_JCC(X86_CC_E, 0x33ac, 0x33db, x86_l_33db);
x86_l_33ae:
	/* 0x33ae: cmp    eax,0x2 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_33b1:
	/* 0x33b1: jne    3ecc <generic_kprobe_process_event+0x3ecc> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x33b1, 0x3ecc, x86_l_3ecc);
x86_l_33b7:
	/* 0x33b7: mov    rdx,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_33ba:
	/* 0x33ba: add    rdx,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_33be:
	/* 0x33be: jns    3ad7 <generic_kprobe_process_event+0x3ad7> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x33be, 0x3ad7, x86_l_3ad7);
x86_l_33c4:
	/* 0x33c4: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_33c7:
	/* 0x33c7: jns    3e4c <generic_kprobe_process_event+0x3e4c> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x33c7, 0x3e4c, x86_l_3e4c);
x86_l_33cd:
	/* 0x33cd: mov    eax,DWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_33cf:
	/* 0x33cf: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_33d4:
	/* 0x33d4: mov    DWORD PTR [rcx],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_33d6:
	/* 0x33d6: jmp    3e57 <generic_kprobe_process_event+0x3e57> */
	X86_SIM_X86_JMP(0x33d6, 0x3e57, x86_l_3e57);
x86_l_33db:
	/* 0x33db: mov    rdx,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_33de:
	/* 0x33de: add    rdx,0x48 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 72ULL);
x86_l_33e2:
	/* 0x33e2: jns    3aeb <generic_kprobe_process_event+0x3aeb> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x33e2, 0x3aeb, x86_l_3aeb);
x86_l_33e8:
	/* 0x33e8: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_33eb:
	/* 0x33eb: jns    3e83 <generic_kprobe_process_event+0x3e83> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x33eb, 0x3e83, x86_l_3e83);
x86_l_33f1:
	/* 0x33f1: mov    rax,QWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_33f4:
	/* 0x33f4: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_33f9:
	/* 0x33f9: mov    QWORD PTR [rcx],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_33fc:
	/* 0x33fc: mov    rax,QWORD PTR [rdx+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3400:
	/* 0x3400: mov    QWORD PTR [rcx+0x8],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3404:
	/* 0x3404: jmp    3e97 <generic_kprobe_process_event+0x3e97> */
	X86_SIM_X86_JMP(0x3404, 0x3e97, x86_l_3e97);
x86_l_3409:
	/* 0x3409: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_340e:
	/* 0x340e: mov    DWORD PTR [rax],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3414:
	/* 0x3414: test   r15,r15 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_3417:
	/* 0x3417: js     3426 <generic_kprobe_process_event+0x3426> */
	X86_SIM_X86_JCC(X86_CC_S, 0x3417, 0x3426, x86_l_3426);
x86_l_3419:
	/* 0x3419: mov    rdi,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_341c:
	/* 0x341c: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_3421:
	/* 0x3421: mov    rdx,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_3424:
	/* 0x3424: jmp    347e <generic_kprobe_process_event+0x347e> */
	X86_SIM_X86_JMP(0x3424, 0x347e, x86_l_347e);
x86_l_3426:
	/* 0x3426: mov    rax,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_3429:
	/* 0x3429: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_342c:
	/* 0x342c: jns    375d <generic_kprobe_process_event+0x375d> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x342c, 0x375d, x86_l_375d);
x86_l_3432:
	/* 0x3432: mov    eax,DWORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3434:
	/* 0x3434: mov    DWORD PTR [r12],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3438:
	/* 0x3438: jmp    3483 <generic_kprobe_process_event+0x3483> */
	X86_SIM_X86_JMP(0x3438, 0x3483, x86_l_3483);
x86_l_343a:
	/* 0x343a: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_343f:
	/* 0x343f: mov    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_3447:
	/* 0x3447: mov    QWORD PTR [rax],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_344e:
	/* 0x344e: mov    rdx,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_3451:
	/* 0x3451: add    rdx,0x38 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 56ULL);
x86_l_3455:
	/* 0x3455: jns    3476 <generic_kprobe_process_event+0x3476> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x3455, 0x3476, x86_l_3476);
x86_l_3457:
	/* 0x3457: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_345a:
	/* 0x345a: jns    3532 <generic_kprobe_process_event+0x3532> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x345a, 0x3532, x86_l_3532);
x86_l_3460:
	/* 0x3460: mov    rax,QWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3463:
	/* 0x3463: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3468:
	/* 0x3468: mov    QWORD PTR [rcx+0x10],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_346c:
	/* 0x346c: mov    rax,QWORD PTR [rdx+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3470:
	/* 0x3470: mov    QWORD PTR [rcx+0x18],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3474:
	/* 0x3474: jmp    3483 <generic_kprobe_process_event+0x3483> */
	X86_SIM_X86_JMP(0x3474, 0x3483, x86_l_3483);
x86_l_3476:
	/* 0x3476: mov    rdi,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_3479:
	/* 0x3479: mov    esi,0x10 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 16ULL);
x86_l_347e:
	/* 0x347e: call   3683 <generic_kprobe_process_event+0x3683> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_3483:
	/* 0x3483: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3488:
	/* 0x3488: lea    rdi,[rax+0x20] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_348c:
	/* 0x348c: lea    r12,[r15+0xc] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R12, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3490:
	/* 0x3490: add    r15,0xe */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 14ULL);
x86_l_3494:
	/* 0x3494: jns    34a4 <generic_kprobe_process_event+0x34a4> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x3494, 0x34a4, x86_l_34a4);
x86_l_3496:
	/* 0x3496: test   r15,r15 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_3499:
	/* 0x3499: jns    34b3 <generic_kprobe_process_event+0x34b3> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x3499, 0x34b3, x86_l_34b3);
x86_l_349b:
	/* 0x349b: movzx  eax,WORD PTR [r15] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_349f:
	/* 0x349f: mov    WORD PTR [rdi],ax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_34a2:
	/* 0x34a2: jmp    34b8 <generic_kprobe_process_event+0x34b8> */
	X86_SIM_X86_JMP(0x34a2, 0x34b8, x86_l_34b8);
x86_l_34a4:
	/* 0x34a4: mov    esi,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_34a9:
	/* 0x34a9: mov    rdx,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_34ac:
	/* 0x34ac: call   36b1 <generic_kprobe_process_event+0x36b1> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_34b1:
	/* 0x34b1: jmp    34b8 <generic_kprobe_process_event+0x34b8> */
	X86_SIM_X86_JMP(0x34b1, 0x34b8, x86_l_34b8);
x86_l_34b3:
	/* 0x34b3: mov    WORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_34b8:
	/* 0x34b8: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_34bd:
	/* 0x34bd: add    rdi,0x22 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 34ULL);
x86_l_34c1:
	/* 0x34c1: test   r12,r12 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_34c4:
	/* 0x34c4: jns    34d2 <generic_kprobe_process_event+0x34d2> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x34c4, 0x34d2, x86_l_34d2);
x86_l_34c6:
	/* 0x34c6: test   r12,r12 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_34c9:
	/* 0x34c9: jns    34eb <generic_kprobe_process_event+0x34eb> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x34c9, 0x34eb, x86_l_34eb);
x86_l_34cb:
	/* 0x34cb: movzx  eax,WORD PTR [r12] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_34d0:
	/* 0x34d0: jmp    34ed <generic_kprobe_process_event+0x34ed> */
	X86_SIM_X86_JMP(0x34d0, 0x34ed, x86_l_34ed);
x86_l_34d2:
	/* 0x34d2: mov    esi,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_34d7:
	/* 0x34d7: mov    r15,rdi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R15, X86_RDI, X86_WIDTH_64, 0, 0);
x86_l_34da:
	/* 0x34da: mov    rdx,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_34dd:
	/* 0x34dd: call   36e2 <generic_kprobe_process_event+0x36e2> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_34e2:
	/* 0x34e2: mov    rdi,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_34e5:
	/* 0x34e5: movzx  eax,WORD PTR [r15] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_34e9:
	/* 0x34e9: jmp    34ed <generic_kprobe_process_event+0x34ed> */
	X86_SIM_X86_JMP(0x34e9, 0x34ed, x86_l_34ed);
x86_l_34eb:
	/* 0x34eb: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_34ed:
	/* 0x34ed: movbe  WORD PTR [rdi],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RDI, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_34f2:
	/* 0x34f2: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_34f7:
	/* 0x34f7: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_34fc:
	/* 0x34fc: mov    rdi,QWORD PTR [rip+0x200] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)socktrack_map));
x86_l_3503:
	/* 0x3503: lea    rsi,[rsp+0x70] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_3508:
	/* 0x3508: call   370d <generic_kprobe_process_event+0x370d> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_350d:
	/* 0x350d: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_3510:
	/* 0x3510: je     3527 <generic_kprobe_process_event+0x3527> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3510, 0x3527, x86_l_3527);
x86_l_3512:
	/* 0x3512: mov    ecx,DWORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3514:
	/* 0x3514: mov    DWORD PTR [r13+0x10],ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3518:
	/* 0x3518: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_351c:
	/* 0x351c: mov    QWORD PTR [r13+0x18],rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3520:
	/* 0x3520: mov    eax,DWORD PTR [rax+0x4] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3523:
	/* 0x3523: mov    DWORD PTR [r13+0x7c],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_3527:
	/* 0x3527: mov    r15d,0x40 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 64ULL);
x86_l_352d:
	/* 0x352d: jmp    423c <generic_kprobe_process_event+0x423c> */
	X86_SIM_X86_JMP(0x352d, 0x423c, x86_l_423c);
x86_l_3532:
	/* 0x3532: mov    QWORD PTR [r12+0x8],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_353b:
	/* 0x353b: mov    QWORD PTR [r12],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3543:
	/* 0x3543: jmp    3483 <generic_kprobe_process_event+0x3483> */
	X86_SIM_X86_JMP(0x3543, 0x3483, x86_l_3483);
x86_l_3548:
	/* 0x3548: mov    rdi,r13 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_354b:
	/* 0x354b: mov    esi,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_3550:
	/* 0x3550: call   3755 <generic_kprobe_process_event+0x3755> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_3555:
	/* 0x3555: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_3558:
	/* 0x3558: js     400d <generic_kprobe_process_event+0x400d> */
	X86_SIM_X86_JCC(X86_CC_S, 0x3558, 0x400d, x86_l_400d);
x86_l_355e:
	/* 0x355e: xor    ebx,ebx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_3560:
	/* 0x3560: lea    r15,[rip+0x200] */
	X86_SIM_RUN_OP(X86_OP_NOP, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_3567:
	/* 0x3567: jmp    356b <generic_kprobe_process_event+0x356b> */
	X86_SIM_X86_JMP(0x3567, 0x356b, x86_l_356b);
x86_l_3569:
	/* 0x3569: inc    bl */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_ALU_INC, 1);
x86_l_356b:
	/* 0x356b: movzx  eax,BYTE PTR [r12+0x5] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_3571:
	/* 0x3571: lea    ecx,[rax-0x2b] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551573ULL);
x86_l_3574:
	/* 0x3574: cmp    ecx,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_3577:
	/* 0x3577: ja     3590 <generic_kprobe_process_event+0x3590> */
	X86_SIM_X86_JCC(X86_CC_A, 0x3577, 0x3590, x86_l_3590);
x86_l_3579:
	/* Capture image-bound code identity before scheduled instructions. */
	switch (X86_SIM_L_READ_REG(X86_RCX) << 2) {
	case 0ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x35a9ULL); break;
	case 4ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x3582ULL); break;
	case 8ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x35b8ULL); break;
	case 12ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x35b8ULL); break;
	case 16ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x35b8ULL); break;
	case 20ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x35b8ULL); break;
	case 24ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x35b8ULL); break;
	case 28ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x35b8ULL); break;
	case 32ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x35c0ULL); break;
	case 36ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x35b8ULL); break;
	case 40ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x35b8ULL); break;
	case 44ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x35b8ULL); break;
	case 48ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x35b8ULL); break;
	case 52ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x35b8ULL); break;
	case 56ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x35b8ULL); break;
	case 60ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x35b8ULL); break;
	case 64ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x35b8ULL); break;
	case 68ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x35a9ULL); break;
	default: __x86_sim_unresolved_indirect_target();
	}
x86_l_3580:
	/* 0x3580: jmp    rax */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RAX);
		switch (X86_SIM_L_REG_TAG(X86_RAX)) {
		case X86_SIM_TAG_CODE:
			switch (__x86_target) {
			case 0x3582ULL: goto x86_l_3582;
			case 0x35a9ULL: goto x86_l_35a9;
			case 0x35b8ULL: goto x86_l_35b8;
			case 0x35c0ULL: goto x86_l_35c0;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_3582:
	/* 0x3582: mov    WORD PTR [r12+0x2],0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_358a:
	/* 0x358a: mov    ax,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, 0, 8ULL);
x86_l_358e:
	/* 0x358e: jmp    35d3 <generic_kprobe_process_event+0x35d3> */
	X86_SIM_X86_JMP(0x358e, 0x35d3, x86_l_35d3);
x86_l_3590:
	/* 0x3590: test   eax,eax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_3592:
	/* 0x3592: je     35a9 <generic_kprobe_process_event+0x35a9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3592, 0x35a9, x86_l_35a9);
x86_l_3594:
	/* 0x3594: cmp    eax,0xff */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 255ULL);
x86_l_3599:
	/* 0x3599: jne    35b8 <generic_kprobe_process_event+0x35b8> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x3599, 0x35b8, x86_l_35b8);
x86_l_359b:
	/* 0x359b: mov    WORD PTR [r12+0x2],0x28 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_35a3:
	/* 0x35a3: mov    ax,0x28 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, 0, 40ULL);
x86_l_35a7:
	/* 0x35a7: jmp    35d3 <generic_kprobe_process_event+0x35d3> */
	X86_SIM_X86_JMP(0x35a7, 0x35d3, x86_l_35d3);
x86_l_35a9:
	/* 0x35a9: movzx  eax,BYTE PTR [r12+0x7] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_35af:
	/* 0x35af: lea    eax,[rax*8+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_35b6:
	/* 0x35b6: jmp    35cd <generic_kprobe_process_event+0x35cd> */
	X86_SIM_X86_JMP(0x35b6, 0x35cd, x86_l_35cd);
x86_l_35b8:
	/* 0x35b8: movzx  eax,WORD PTR [r12+0x2] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_35be:
	/* 0x35be: jmp    35d3 <generic_kprobe_process_event+0x35d3> */
	X86_SIM_X86_JMP(0x35be, 0x35d3, x86_l_35d3);
x86_l_35c0:
	/* 0x35c0: movzx  eax,BYTE PTR [r12+0x7] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_35c6:
	/* 0x35c6: lea    eax,[rax*4+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_35cd:
	/* 0x35cd: mov    WORD PTR [r12+0x2],ax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_35d3:
	/* 0x35d3: add    ax,WORD PTR [r12] */
	X86_SIM_RUN_OP(X86_OP_ALU_MEM, X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_35d8:
	/* 0x35d8: mov    WORD PTR [r12],ax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_35dd:
	/* 0x35dd: movzx  ecx,BYTE PTR [r12+0x6] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_35e3:
	/* 0x35e3: cmp    rcx,0x3c */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, 0, 60ULL);
x86_l_35e7:
	/* 0x35e7: ja     42f8 <generic_kprobe_process_event+0x42f8> */
	X86_SIM_X86_JCC(X86_CC_A, 0x35e7, 0x42f8, x86_l_42f8);
x86_l_35ed:
	/* 0x35ed: movabs rdx,0x1008180000000001 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, 0, 1155199692699598849ULL);
x86_l_35f7:
	/* 0x35f7: bt     rdx,rcx */
	X86_SIM_RUN_OP(X86_OP_BT, X86_RDX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_35fb:
	/* 0x35fb: jae    42f8 <generic_kprobe_process_event+0x42f8> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x35fb, 0x42f8, x86_l_42f8);
x86_l_3601:
	/* 0x3601: mov    BYTE PTR [r12+0x5],cl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_R12, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_3606:
	/* 0x3606: movzx  edx,ax */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_RDX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_3609:
	/* 0x3609: add    rdx,rbp */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_360c:
	/* 0x360c: jns    362d <generic_kprobe_process_event+0x362d> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x360c, 0x362d, x86_l_362d);
x86_l_360e:
	/* 0x360e: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_3611:
	/* 0x3611: jns    4006 <generic_kprobe_process_event+0x4006> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x3611, 0x4006, x86_l_4006);
x86_l_3617:
	/* 0x3617: movzx  eax,WORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_361a:
	/* 0x361a: mov    WORD PTR [r13+0x0],ax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_361f:
	/* 0x361f: cmp    bl,0x5 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, 0, 5ULL);
x86_l_3622:
	/* 0x3622: jbe    3569 <generic_kprobe_process_event+0x3569> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x3622, 0x3569, x86_l_3569);
x86_l_3628:
	/* 0x3628: jmp    400d <generic_kprobe_process_event+0x400d> */
	X86_SIM_X86_JMP(0x3628, 0x400d, x86_l_400d);
x86_l_362d:
	/* 0x362d: mov    rdi,r13 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_3630:
	/* 0x3630: mov    esi,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_3635:
	/* 0x3635: call   383a <generic_kprobe_process_event+0x383a> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_363a:
	/* 0x363a: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_363c:
	/* 0x363c: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_363f:
	/* 0x363f: js     400f <generic_kprobe_process_event+0x400f> */
	X86_SIM_X86_JCC(X86_CC_S, 0x363f, 0x400f, x86_l_400f);
x86_l_3645:
	/* 0x3645: cmp    bl,0x6 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, 0, 6ULL);
x86_l_3648:
	/* 0x3648: jb     3569 <generic_kprobe_process_event+0x3569> */
	X86_SIM_X86_JCC(X86_CC_B, 0x3648, 0x3569, x86_l_3569);
x86_l_364e:
	/* 0x364e: jmp    400f <generic_kprobe_process_event+0x400f> */
	X86_SIM_X86_JMP(0x364e, 0x400f, x86_l_400f);
x86_l_3653:
	/* 0x3653: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3658:
	/* 0x3658: mov    ecx,0xfffffffe */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 4294967294ULL);
x86_l_365d:
	/* 0x365d: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_3660:
	/* 0x3660: jns    43b8 <generic_kprobe_process_event+0x43b8> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x3660, 0x43b8, x86_l_43b8);
x86_l_3666:
	/* 0x3666: mov    rcx,QWORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3669:
	/* 0x3669: mov    QWORD PTR [rsp+0x70],rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_366e:
	/* 0x366e: mov    r15,QWORD PTR [rax+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3672:
	/* 0x3672: mov    QWORD PTR [rsp+0x78],r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_3677:
	/* 0x3677: mov    ecx,0xfffffffd */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 4294967293ULL);
x86_l_367c:
	/* 0x367c: cmp    r15,0xffe */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, 0, 4094ULL);
x86_l_3683:
	/* 0x3683: ja     43b8 <generic_kprobe_process_event+0x43b8> */
	X86_SIM_X86_JCC(X86_CC_A, 0x3683, 0x43b8, x86_l_43b8);
x86_l_3689:
	/* 0x3689: mov    rax,QWORD PTR [rsp+0xb0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_3691:
	/* 0x3691: lea    rbx,[rax+0xc] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3695:
	/* 0x3695: lea    rdi,[rbx+rbp*1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_3699:
	/* 0x3699: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_369e:
	/* 0x369e: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_36a1:
	/* 0x36a1: jns    4204 <generic_kprobe_process_event+0x4204> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x36a1, 0x4204, x86_l_4204);
x86_l_36a7:
	/* 0x36a7: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_36aa:
	/* 0x36aa: jns    42e4 <generic_kprobe_process_event+0x42e4> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x36aa, 0x42e4, x86_l_42e4);
x86_l_36b0:
	/* 0x36b0: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_36b2:
	/* 0x36b2: cmp    r15d,0x8 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_36b6:
	/* 0x36b6: jb     36d1 <generic_kprobe_process_event+0x36d1> */
	X86_SIM_X86_JCC(X86_CC_B, 0x36b6, 0x36d1, x86_l_36d1);
x86_l_36b8:
	/* 0x36b8: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_36ba:
	/* 0x36ba: mov    eax,ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_36bc:
	/* 0x36bc: mov    rsi,QWORD PTR [rdx+rax*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_36c0:
	/* 0x36c0: mov    QWORD PTR [rdi+rax*1],rsi */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_36c4:
	/* 0x36c4: lea    eax,[rcx+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_36c7:
	/* 0x36c7: add    ecx,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 16ULL);
x86_l_36ca:
	/* 0x36ca: cmp    ecx,r15d */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RCX, X86_R15, X86_WIDTH_32, 0, 0);
x86_l_36cd:
	/* 0x36cd: mov    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_36cf:
	/* 0x36cf: jbe    36ba <generic_kprobe_process_event+0x36ba> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x36cf, 0x36ba, x86_l_36ba);
x86_l_36d1:
	/* 0x36d1: test   r15b,0x4 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, 0, 4ULL);
x86_l_36d5:
	/* 0x36d5: jne    4310 <generic_kprobe_process_event+0x4310> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x36d5, 0x4310, x86_l_4310);
x86_l_36db:
	/* 0x36db: test   r15b,0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, 0, 2ULL);
x86_l_36df:
	/* 0x36df: jne    4325 <generic_kprobe_process_event+0x4325> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x36df, 0x4325, x86_l_4325);
x86_l_36e5:
	/* 0x36e5: test   r15b,0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_36e9:
	/* 0x36e9: jne    4338 <generic_kprobe_process_event+0x4338> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x36e9, 0x4338, x86_l_4338);
x86_l_36ef:
	/* 0x36ef: jmp    4341 <generic_kprobe_process_event+0x4341> */
	X86_SIM_X86_JMP(0x36ef, 0x4341, x86_l_4341);
x86_l_36f4:
	/* 0x36f4: mov    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_36f6:
	/* 0x36f6: mov    edx,DWORD PTR [rdi+rcx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_36f9:
	/* 0x36f9: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_36fe:
	/* 0x36fe: mov    DWORD PTR [rsi+rcx*1],edx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3701:
	/* 0x3701: or     eax,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_OR, 4ULL);
x86_l_3704:
	/* 0x3704: test   BYTE PTR [rsp+0x30],0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430210ULL);
x86_l_3709:
	/* 0x3709: je     1f32 <generic_kprobe_process_event+0x1f32> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3709, 0x1f32, x86_l_1f32);
x86_l_370f:
	/* 0x370f: mov    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_3711:
	/* 0x3711: movzx  edx,WORD PTR [rdi+rcx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_16), 0ULL);
x86_l_3715:
	/* 0x3715: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_371a:
	/* 0x371a: mov    WORD PTR [rsi+rcx*1],dx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSI, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_371e:
	/* 0x371e: add    eax,0x2 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_3721:
	/* 0x3721: test   r12b,0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_3725:
	/* 0x3725: je     2d4e <generic_kprobe_process_event+0x2d4e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3725, 0x2d4e, x86_l_2d4e);
x86_l_372b:
	/* 0x372b: mov    eax,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_372d:
	/* 0x372d: movzx  ecx,BYTE PTR [rdi+rax*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_3731:
	/* 0x3731: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3736:
	/* 0x3736: mov    BYTE PTR [rdx+rax*1],cl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3739:
	/* 0x3739: jmp    2d4e <generic_kprobe_process_event+0x2d4e> */
	X86_SIM_X86_JMP(0x3739, 0x2d4e, x86_l_2d4e);
x86_l_373e:
	/* 0x373e: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_3747:
	/* 0x3747: xor    edx,edx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_3749:
	/* 0x3749: lea    rdi,[rsp+0x60] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_374e:
	/* 0x374e: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_3753:
	/* 0x3753: call   3958 <generic_kprobe_process_event+0x3958> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_3758:
	/* 0x3758: jmp    3b41 <generic_kprobe_process_event+0x3b41> */
	X86_SIM_X86_JMP(0x3758, 0x3b41, x86_l_3b41);
x86_l_375d:
	/* 0x375d: mov    DWORD PTR [r12],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3765:
	/* 0x3765: jmp    3483 <generic_kprobe_process_event+0x3483> */
	X86_SIM_X86_JMP(0x3765, 0x3483, x86_l_3483);
x86_l_376a:
	/* 0x376a: mov    BYTE PTR [rsp+0x60],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_376f:
	/* 0x376f: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_3771:
	/* 0x3771: movzx  eax,al */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8, 0);
x86_l_3774:
	/* 0x3774: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3779:
	/* 0x3779: mov    WORD PTR [rcx+0x24],ax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_377d:
	/* 0x377d: mov    WORD PTR [rcx+0x26],0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 163208757250ULL);
x86_l_3783:
	/* 0x3783: mov    rdx,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_3786:
	/* 0x3786: add    rdx,0xc */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_378a:
	/* 0x378a: mov    QWORD PTR [rcx],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3791:
	/* 0x3791: mov    QWORD PTR [rcx+0x8],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_3799:
	/* 0x3799: mov    QWORD PTR [rcx+0x10],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_37a1:
	/* 0x37a1: mov    QWORD PTR [rcx+0x18],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_37a9:
	/* 0x37a9: jns    37bb <generic_kprobe_process_event+0x37bb> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x37a9, 0x37bb, x86_l_37bb);
x86_l_37ab:
	/* 0x37ab: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_37ae:
	/* 0x37ae: jns    37cc <generic_kprobe_process_event+0x37cc> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x37ae, 0x37cc, x86_l_37cc);
x86_l_37b0:
	/* 0x37b0: mov    eax,DWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_37b2:
	/* 0x37b2: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_37b7:
	/* 0x37b7: mov    DWORD PTR [rcx],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_37b9:
	/* 0x37b9: jmp    37d7 <generic_kprobe_process_event+0x37d7> */
	X86_SIM_X86_JMP(0x37b9, 0x37d7, x86_l_37d7);
x86_l_37bb:
	/* 0x37bb: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_37c0:
	/* 0x37c0: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_37c5:
	/* 0x37c5: call   39ca <generic_kprobe_process_event+0x39ca> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_37ca:
	/* 0x37ca: jmp    37d7 <generic_kprobe_process_event+0x37d7> */
	X86_SIM_X86_JMP(0x37ca, 0x37d7, x86_l_37d7);
x86_l_37cc:
	/* 0x37cc: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_37d1:
	/* 0x37d1: mov    DWORD PTR [rax],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_37d7:
	/* 0x37d7: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_37dc:
	/* 0x37dc: lea    rdi,[rax+0x10] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_37e0:
	/* 0x37e0: add    r15,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_37e4:
	/* 0x37e4: jns    37f2 <generic_kprobe_process_event+0x37f2> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x37e4, 0x37f2, x86_l_37f2);
x86_l_37e6:
	/* 0x37e6: test   r15,r15 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_37e9:
	/* 0x37e9: jns    3801 <generic_kprobe_process_event+0x3801> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x37e9, 0x3801, x86_l_3801);
x86_l_37eb:
	/* 0x37eb: mov    eax,DWORD PTR [r15] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_37ee:
	/* 0x37ee: mov    DWORD PTR [rdi],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_37f0:
	/* 0x37f0: jmp    3807 <generic_kprobe_process_event+0x3807> */
	X86_SIM_X86_JMP(0x37f0, 0x3807, x86_l_3807);
x86_l_37f2:
	/* 0x37f2: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_37f7:
	/* 0x37f7: mov    rdx,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_37fa:
	/* 0x37fa: call   3a02 <generic_kprobe_process_event+0x3a02> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_37ff:
	/* 0x37ff: jmp    3807 <generic_kprobe_process_event+0x3807> */
	X86_SIM_X86_JMP(0x37ff, 0x3807, x86_l_3807);
x86_l_3801:
	/* 0x3801: mov    DWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3807:
	/* 0x3807: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_380c:
	/* 0x380c: add    rdx,0xb6 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 182ULL);
x86_l_3813:
	/* 0x3813: jns    3835 <generic_kprobe_process_event+0x3835> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x3813, 0x3835, x86_l_3835);
x86_l_3815:
	/* 0x3815: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_3818:
	/* 0x3818: jns    3847 <generic_kprobe_process_event+0x3847> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x3818, 0x3847, x86_l_3847);
x86_l_381a:
	/* 0x381a: movzx  eax,WORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_381d:
	/* 0x381d: mov    WORD PTR [rsp+0xc0],ax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_3825:
	/* 0x3825: movzx  eax,BYTE PTR [rsp+0x60] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 96ULL);
x86_l_382a:
	/* 0x382a: cmp    eax,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_382d:
	/* 0x382d: jne    40d4 <generic_kprobe_process_event+0x40d4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x382d, 0x40d4, x86_l_40d4);
x86_l_3833:
	/* 0x3833: jmp    385f <generic_kprobe_process_event+0x385f> */
	X86_SIM_X86_JMP(0x3833, 0x385f, x86_l_385f);
x86_l_3835:
	/* 0x3835: lea    rdi,[rsp+0xc0] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_383d:
	/* 0x383d: mov    esi,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_3842:
	/* 0x3842: jmp    40c1 <generic_kprobe_process_event+0x40c1> */
	X86_SIM_X86_JMP(0x3842, 0x40c1, x86_l_40c1);
x86_l_3847:
	/* 0x3847: mov    WORD PTR [rsp+0xc0],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_3851:
	/* 0x3851: movzx  eax,BYTE PTR [rsp+0x60] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 96ULL);
x86_l_3856:
	/* 0x3856: cmp    eax,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_3859:
	/* 0x3859: jne    40d4 <generic_kprobe_process_event+0x40d4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x3859, 0x40d4, x86_l_40d4);
x86_l_385f:
	/* 0x385f: movzx  r15d,WORD PTR [rsp+0xc0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 192ULL);
x86_l_3868:
	/* 0x3868: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_386d:
	/* 0x386d: lea    rdi,[rax+0x20] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3871:
	/* 0x3871: add    r15,QWORD PTR [rsp+0x70] */
	X86_SIM_RUN_OP(X86_OP_ALU_MEM, X86_R15, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 112ULL);
x86_l_3876:
	/* 0x3876: jns    388f <generic_kprobe_process_event+0x388f> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x3876, 0x388f, x86_l_388f);
x86_l_3878:
	/* 0x3878: mov    rax,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_387b:
	/* 0x387b: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_387e:
	/* 0x387e: jns    3dfa <generic_kprobe_process_event+0x3dfa> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x387e, 0x3dfa, x86_l_3dfa);
x86_l_3884:
	/* 0x3884: movzx  eax,WORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3887:
	/* 0x3887: mov    WORD PTR [rdi],ax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_388a:
	/* 0x388a: jmp    3dff <generic_kprobe_process_event+0x3dff> */
	X86_SIM_X86_JMP(0x388a, 0x3dff, x86_l_3dff);
x86_l_388f:
	/* 0x388f: mov    esi,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_3894:
	/* 0x3894: mov    rdx,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_3897:
	/* 0x3897: call   3a9c <generic_kprobe_process_event+0x3a9c> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_389c:
	/* 0x389c: jmp    3dff <generic_kprobe_process_event+0x3dff> */
	X86_SIM_X86_JMP(0x389c, 0x3dff, x86_l_3dff);
x86_l_38a1:
	/* 0x38a1: lea    rax,[rbx+0x5e70] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24176ULL);
x86_l_38a8:
	/* 0x38a8: jmp    38c3 <generic_kprobe_process_event+0x38c3> */
	X86_SIM_X86_JMP(0x38a8, 0x38c3, x86_l_38c3);
x86_l_38aa:
	/* 0x38aa: lea    rax,[rbx+0x5e60] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24160ULL);
x86_l_38b1:
	/* 0x38b1: jmp    38c3 <generic_kprobe_process_event+0x38c3> */
	X86_SIM_X86_JMP(0x38b1, 0x38c3, x86_l_38c3);
x86_l_38b3:
	/* 0x38b3: lea    rax,[rbx+0x5e68] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24168ULL);
x86_l_38ba:
	/* 0x38ba: jmp    38c3 <generic_kprobe_process_event+0x38c3> */
	X86_SIM_X86_JMP(0x38ba, 0x38c3, x86_l_38c3);
x86_l_38bc:
	/* 0x38bc: lea    rax,[rbx+0x5e58] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24152ULL);
x86_l_38c3:
	/* 0x38c3: mov    rax,QWORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_38c6:
	/* 0x38c6: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_38cb:
	/* 0x38cb: lea    rax,[rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_38d0:
	/* 0x38d0: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_38d3:
	/* 0x38d3: jns    391f <generic_kprobe_process_event+0x391f> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x38d3, 0x391f, x86_l_391f);
x86_l_38d5:
	/* 0x38d5: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_38d8:
	/* 0x38d8: jns    38ea <generic_kprobe_process_event+0x38ea> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x38d8, 0x38ea, x86_l_38ea);
x86_l_38da:
	/* 0x38da: mov    rax,QWORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_38dd:
	/* 0x38dd: mov    r13,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R13, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_38e0:
	/* 0x38e0: mov    QWORD PTR [rsp+0xc8],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_38e8:
	/* 0x38e8: jmp    393e <generic_kprobe_process_event+0x393e> */
	X86_SIM_X86_JMP(0x38e8, 0x393e, x86_l_393e);
x86_l_38ea:
	/* 0x38ea: mov    QWORD PTR [rsp+0xc8],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 858993459200ULL);
x86_l_38f6:
	/* 0x38f6: mov    r15d,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_38fc:
	/* 0x38fc: xor    r13d,r13d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_38ff:
	/* 0x38ff: test   r12b,0x20 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, 0, 32ULL);
x86_l_3903:
	/* 0x3903: je     39b1 <generic_kprobe_process_event+0x39b1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3903, 0x39b1, x86_l_39b1);
x86_l_3909:
	/* 0x3909: jmp    398c <generic_kprobe_process_event+0x398c> */
	X86_SIM_X86_JMP(0x3909, 0x398c, x86_l_398c);
x86_l_390e:
	/* 0x390e: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_3910:
	/* 0x3910: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3915:
	/* 0x3915: lea    rax,[rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_391a:
	/* 0x391a: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_391d:
	/* 0x391d: js     38d5 <generic_kprobe_process_event+0x38d5> */
	X86_SIM_X86_JCC(X86_CC_S, 0x391d, 0x38d5, x86_l_38d5);
x86_l_391f:
	/* 0x391f: lea    rdi,[rsp+0xc8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_3927:
	/* 0x3927: lea    rdx,[rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_392c:
	/* 0x392c: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_3931:
	/* 0x3931: call   3b33 <generic_kprobe_process_event+0x3b33> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_3936:
	/* 0x3936: mov    r13,QWORD PTR [rsp+0xc8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_393e:
	/* 0x393e: mov    r15d,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_3944:
	/* 0x3944: test   r12b,0x20 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, 0, 32ULL);
x86_l_3948:
	/* 0x3948: je     39b1 <generic_kprobe_process_event+0x39b1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3948, 0x39b1, x86_l_39b1);
x86_l_394a:
	/* 0x394a: cmp    r13,0x1000 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, 0, 4096ULL);
x86_l_3951:
	/* 0x3951: jb     398c <generic_kprobe_process_event+0x398c> */
	X86_SIM_X86_JCC(X86_CC_B, 0x3951, 0x398c, x86_l_398c);
x86_l_3953:
	/* 0x3953: mov    rsi,rbp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_3956:
	/* 0x3956: mov    DWORD PTR [rbp+0x0],0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_395d:
	/* 0x395d: add    rsi,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_3961:
	/* 0x3961: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3966:
	/* 0x3966: mov    rdi,rbp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_3969:
	/* 0x3969: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_396e:
	/* 0x396e: mov    rcx,r13 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_3971:
	/* 0x3971: call   0 <generic_kprobe_process_event> */
	X86_SIM_X86_CALL(x86_l_4b43, 0x3976ULL);
x86_l_3976:
	/* 0x3976: mov    r15,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R15, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_3979:
	/* 0x3979: add    r15,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_397d:
	/* 0x397d: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3982:
	/* 0x3982: mov    rbx,QWORD PTR [rsp+0x48] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3987:
	/* 0x3987: jmp    2d58 <generic_kprobe_process_event+0x2d58> */
	X86_SIM_X86_JMP(0x3987, 0x2d58, x86_l_2d58);
x86_l_398c:
	/* 0x398c: add    rbx,0x90 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_3993:
	/* 0x3993: mov    rax,QWORD PTR [rsp+0xb0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_399b:
	/* 0x399b: mov    DWORD PTR [rbx+rax*1+0x4],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 17179869184ULL);
x86_l_39a3:
	/* 0x39a3: lea    rbp,[rbx+rax*1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RBP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_39a7:
	/* 0x39a7: add    rbp,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_39ab:
	/* 0x39ab: mov    r15d,0xc */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 12ULL);
x86_l_39b1:
	/* 0x39b1: mov    rax,r13 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_39b4:
	/* 0x39b4: cmp    r13,0xfff */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, 0, 4095ULL);
x86_l_39bb:
	/* 0x39bb: mov    r12d,0xfff */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 4095ULL);
x86_l_39c1:
	/* 0x39c1: cmovb  r12,r13 */
	X86_SIM_RUN_OP(X86_OP_CMOV, X86_R12, X86_R13, X86_WIDTH_64, X86_CC_B, 0);
x86_l_39c5:
	/* 0x39c5: lea    rdi,[rbp+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_39c9:
	/* 0x39c9: cmp    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_39cf:
	/* 0x39cf: js     39e7 <generic_kprobe_process_event+0x39e7> */
	X86_SIM_X86_JCC(X86_CC_S, 0x39cf, 0x39e7, x86_l_39e7);
x86_l_39d1:
	/* 0x39d1: mov    esi,r12d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_R12, X86_WIDTH_32, 0, 0);
x86_l_39d4:
	/* 0x39d4: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_39d9:
	/* 0x39d9: call   3bdb <generic_kprobe_process_event+0x3bdb> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_39de:
	/* 0x39de: test   eax,eax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_39e0:
	/* 0x39e0: jns    3a40 <generic_kprobe_process_event+0x3a40> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x39e0, 0x3a40, x86_l_3a40);
x86_l_39e2:
	/* 0x39e2: jmp    3b09 <generic_kprobe_process_event+0x3b09> */
	X86_SIM_X86_JMP(0x39e2, 0x3b09, x86_l_3b09);
x86_l_39e7:
	/* 0x39e7: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_39ec:
	/* 0x39ec: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_39ef:
	/* 0x39ef: jns    3aff <generic_kprobe_process_event+0x3aff> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x39ef, 0x3aff, x86_l_3aff);
x86_l_39f5:
	/* 0x39f5: mov    rsi,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_39f8:
	/* 0x39f8: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_39fa:
	/* 0x39fa: cmp    r12d,0x8 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_39fe:
	/* 0x39fe: jb     3a1d <generic_kprobe_process_event+0x3a1d> */
	X86_SIM_X86_JCC(X86_CC_B, 0x39fe, 0x3a1d, x86_l_3a1d);
x86_l_3a00:
	/* 0x3a00: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_3a02:
	/* 0x3a02: mov    rdx,rsi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_3a05:
	/* 0x3a05: mov    rcx,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_3a08:
	/* 0x3a08: mov    rax,QWORD PTR [rdx+rax*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3a0c:
	/* 0x3a0c: mov    QWORD PTR [rdi+rcx*1],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3a10:
	/* 0x3a10: lea    rax,[rcx+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3a14:
	/* 0x3a14: add    rcx,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3a18:
	/* 0x3a18: cmp    rcx,r12 */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RCX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_3a1b:
	/* 0x3a1b: jbe    3a05 <generic_kprobe_process_event+0x3a05> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x3a1b, 0x3a05, x86_l_3a05);
x86_l_3a1d:
	/* 0x3a1d: test   r12b,0x4 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, 0, 4ULL);
x86_l_3a21:
	/* 0x3a21: jne    3f93 <generic_kprobe_process_event+0x3f93> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x3a21, 0x3f93, x86_l_3f93);
x86_l_3a27:
	/* 0x3a27: test   r12b,0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, 0, 2ULL);
x86_l_3a2b:
	/* 0x3a2b: jne    3fa8 <generic_kprobe_process_event+0x3fa8> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x3a2b, 0x3fa8, x86_l_3fa8);
x86_l_3a31:
	/* 0x3a31: test   r12b,0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_3a35:
	/* 0x3a35: je     3a40 <generic_kprobe_process_event+0x3a40> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3a35, 0x3a40, x86_l_3a40);
x86_l_3a37:
	/* 0x3a37: mov    eax,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_3a39:
	/* 0x3a39: movzx  ecx,BYTE PTR [rsi+rax*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_3a3d:
	/* 0x3a3d: mov    BYTE PTR [rdi+rax*1],cl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3a40:
	/* 0x3a40: mov    DWORD PTR [rbp+0x0],r13d */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RBP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3a44:
	/* 0x3a44: mov    DWORD PTR [rbp+0x4],r12d */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RBP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3a48:
	/* 0x3a48: add    r15,r12 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R15, X86_R12, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_3a4b:
	/* 0x3a4b: jmp    3b16 <generic_kprobe_process_event+0x3b16> */
	X86_SIM_X86_JMP(0x3a4b, 0x3b16, x86_l_3b16);
x86_l_3a50:
	/* 0x3a50: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3a55:
	/* 0x3a55: add    rax,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_3a59:
	/* 0x3a59: mov    DWORD PTR [rax+0x67],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 442381631488ULL);
x86_l_3a60:
	/* 0x3a60: mov    QWORD PTR [rax+0x60],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_3a68:
	/* 0x3a68: mov    QWORD PTR [rax+0x58],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_3a70:
	/* 0x3a70: mov    QWORD PTR [rax+0x50],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_3a78:
	/* 0x3a78: mov    QWORD PTR [rax+0x48],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_3a80:
	/* 0x3a80: mov    QWORD PTR [rax+0x40],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_3a88:
	/* 0x3a88: mov    QWORD PTR [rax+0x38],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_3a90:
	/* 0x3a90: mov    QWORD PTR [rax+0x30],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_3a98:
	/* 0x3a98: mov    QWORD PTR [rax+0x28],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_3aa0:
	/* 0x3aa0: mov    QWORD PTR [rax+0x20],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_3aa8:
	/* 0x3aa8: mov    QWORD PTR [rax+0x18],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_3ab0:
	/* 0x3ab0: mov    QWORD PTR [rax+0x10],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3ab8:
	/* 0x3ab8: mov    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_3ac0:
	/* 0x3ac0: mov    QWORD PTR [rax],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3ac7:
	/* 0x3ac7: jmp    4236 <generic_kprobe_process_event+0x4236> */
	X86_SIM_X86_JMP(0x3ac7, 0x4236, x86_l_4236);
x86_l_3acc:
	/* 0x3acc: mov    r15d,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_3ad2:
	/* 0x3ad2: jmp    45ce <generic_kprobe_process_event+0x45ce> */
	X86_SIM_X86_JMP(0x3ad2, 0x45ce, x86_l_45ce);
x86_l_3ad7:
	/* 0x3ad7: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3adc:
	/* 0x3adc: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_3ae1:
	/* 0x3ae1: call   3ce6 <generic_kprobe_process_event+0x3ce6> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_3ae6:
	/* 0x3ae6: jmp    3e57 <generic_kprobe_process_event+0x3e57> */
	X86_SIM_X86_JMP(0x3ae6, 0x3e57, x86_l_3e57);
x86_l_3aeb:
	/* 0x3aeb: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3af0:
	/* 0x3af0: mov    esi,0x10 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 16ULL);
x86_l_3af5:
	/* 0x3af5: call   3cf7 <generic_kprobe_process_event+0x3cf7> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_3afa:
	/* 0x3afa: jmp    3e97 <generic_kprobe_process_event+0x3e97> */
	X86_SIM_X86_JMP(0x3afa, 0x3e97, x86_l_3e97);
x86_l_3aff:
	/* 0x3aff: xor    esi,esi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_3b01:
	/* 0x3b01: mov    rdx,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_3b04:
	/* 0x3b04: call   4f97 <__native_link_local_memset_zero_dynamic> */
	X86_SIM_X86_CALL(x86_l_4f97, 0x3b09ULL);
x86_l_3b09:
	/* 0x3b09: mov    DWORD PTR [rbp+0x0],0xfffffffe */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4294967294ULL);
x86_l_3b10:
	/* 0x3b10: mov    r15d,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_3b16:
	/* 0x3b16: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3b1b:
	/* 0x3b1b: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3b20:
	/* 0x3b20: mov    rbx,QWORD PTR [rsp+0x48] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3b25:
	/* 0x3b25: jmp    2d58 <generic_kprobe_process_event+0x2d58> */
	X86_SIM_X86_JMP(0x3b25, 0x2d58, x86_l_2d58);
x86_l_3b2a:
	/* 0x3b2a: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3b2f:
	/* 0x3b2f: mov    BYTE PTR [rax+0x7f],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 545460846592ULL);
x86_l_3b33:
	/* 0x3b33: jmp    2504 <generic_kprobe_process_event+0x2504> */
	X86_SIM_X86_JMP(0x3b33, 0x2504, x86_l_2504);
x86_l_3b38:
	/* 0x3b38: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_3b41:
	/* 0x3b41: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_3b46:
	/* 0x3b46: add    rdx,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3b4a:
	/* 0x3b4a: jns    3b62 <generic_kprobe_process_event+0x3b62> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x3b4a, 0x3b62, x86_l_3b62);
x86_l_3b4c:
	/* 0x3b4c: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_3b4f:
	/* 0x3b4f: jns    3bdd <generic_kprobe_process_event+0x3bdd> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x3b4f, 0x3bdd, x86_l_3bdd);
x86_l_3b55:
	/* 0x3b55: mov    rax,QWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3b58:
	/* 0x3b58: mov    rbx,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RBX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_3b5b:
	/* 0x3b5b: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3b60:
	/* 0x3b60: jmp    3b76 <generic_kprobe_process_event+0x3b76> */
	X86_SIM_X86_JMP(0x3b60, 0x3b76, x86_l_3b76);
x86_l_3b62:
	/* 0x3b62: lea    rdi,[rsp+0x50] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3b67:
	/* 0x3b67: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_3b6c:
	/* 0x3b6c: call   3d6e <generic_kprobe_process_event+0x3d6e> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_3b71:
	/* 0x3b71: mov    rbx,QWORD PTR [rsp+0x50] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3b76:
	/* 0x3b76: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_3b7b:
	/* 0x3b7b: mov    rax,QWORD PTR [rsp+0xb8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_3b83:
	/* 0x3b83: lea    r12,[rax+r13*1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_3b87:
	/* 0x3b87: add    r12,0x90 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_3b8e:
	/* 0x3b8e: mov    r15d,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_3b94:
	/* 0x3b94: test   BYTE PTR [rsp+0x30],0x20 */
	X86_SIM_RUN_OP(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430240ULL);
x86_l_3b99:
	/* 0x3b99: je     3c33 <generic_kprobe_process_event+0x3c33> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3b99, 0x3c33, x86_l_3c33);
x86_l_3b9f:
	/* 0x3b9f: cmp    rbx,0x1000 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 4096ULL);
x86_l_3ba6:
	/* 0x3ba6: jb     3c0e <generic_kprobe_process_event+0x3c0e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x3ba6, 0x3c0e, x86_l_3c0e);
x86_l_3ba8:
	/* 0x3ba8: mov    DWORD PTR [r12],0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_3bb0:
	/* 0x3bb0: add    r12,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_3bb4:
	/* 0x3bb4: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3bb9:
	/* 0x3bb9: mov    rdi,rbp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_3bbc:
	/* 0x3bbc: mov    rsi,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_3bbf:
	/* 0x3bbf: mov    rcx,rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_3bc2:
	/* 0x3bc2: call   0 <generic_kprobe_process_event> */
	X86_SIM_X86_CALL(x86_l_4b43, 0x3bc7ULL);
x86_l_3bc7:
	/* 0x3bc7: mov    r15,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R15, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_3bca:
	/* 0x3bca: add    r15,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_3bce:
	/* 0x3bce: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3bd3:
	/* 0x3bd3: mov    rbx,QWORD PTR [rsp+0x48] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3bd8:
	/* 0x3bd8: jmp    4246 <generic_kprobe_process_event+0x4246> */
	X86_SIM_X86_JMP(0x3bd8, 0x4246, x86_l_4246);
x86_l_3bdd:
	/* 0x3bdd: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_3be6:
	/* 0x3be6: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_3beb:
	/* 0x3beb: xor    ebx,ebx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_3bed:
	/* 0x3bed: test   r12b,0x20 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, 0, 32ULL);
x86_l_3bf1:
	/* 0x3bf1: jne    3c0e <generic_kprobe_process_event+0x3c0e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x3bf1, 0x3c0e, x86_l_3c0e);
x86_l_3bf3:
	/* 0x3bf3: mov    rax,QWORD PTR [rsp+0xb8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_3bfb:
	/* 0x3bfb: lea    r12,[rax+r13*1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_3bff:
	/* 0x3bff: add    r12,0x90 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_3c06:
	/* 0x3c06: mov    r15d,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_3c0c:
	/* 0x3c0c: jmp    3c33 <generic_kprobe_process_event+0x3c33> */
	X86_SIM_X86_JMP(0x3c0c, 0x3c33, x86_l_3c33);
x86_l_3c0e:
	/* 0x3c0e: mov    rax,QWORD PTR [rsp+0xb0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_3c16:
	/* 0x3c16: mov    DWORD PTR [r13+rax*1+0x94],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 635655159808ULL);
x86_l_3c22:
	/* 0x3c22: lea    r12,[rax+r13*1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_3c26:
	/* 0x3c26: add    r12,0x98 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 152ULL);
x86_l_3c2d:
	/* 0x3c2d: mov    r15d,0xc */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 12ULL);
x86_l_3c33:
	/* 0x3c33: mov    rax,rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_3c36:
	/* 0x3c36: cmp    rbx,0xfff */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 4095ULL);
x86_l_3c3d:
	/* 0x3c3d: mov    r13d,0xfff */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, 0, 4095ULL);
x86_l_3c43:
	/* 0x3c43: cmovb  r13,rbx */
	X86_SIM_RUN_OP(X86_OP_CMOV, X86_R13, X86_RBX, X86_WIDTH_64, X86_CC_B, 0);
x86_l_3c47:
	/* 0x3c47: lea    rdi,[r12+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3c4c:
	/* 0x3c4c: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_3c4f:
	/* 0x3c4f: jns    3c9b <generic_kprobe_process_event+0x3c9b> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x3c4f, 0x3c9b, x86_l_3c9b);
x86_l_3c51:
	/* 0x3c51: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_3c54:
	/* 0x3c54: jns    3cac <generic_kprobe_process_event+0x3cac> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x3c54, 0x3cac, x86_l_3cac);
x86_l_3c56:
	/* 0x3c56: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_3c58:
	/* 0x3c58: cmp    r13d,0x8 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_3c5c:
	/* 0x3c5c: jb     3c78 <generic_kprobe_process_event+0x3c78> */
	X86_SIM_X86_JCC(X86_CC_B, 0x3c5c, 0x3c78, x86_l_3c78);
x86_l_3c5e:
	/* 0x3c5e: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_3c60:
	/* 0x3c60: mov    rcx,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_3c63:
	/* 0x3c63: mov    rax,QWORD PTR [rdx+rax*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3c67:
	/* 0x3c67: mov    QWORD PTR [rdi+rcx*1],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3c6b:
	/* 0x3c6b: lea    rax,[rcx+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3c6f:
	/* 0x3c6f: add    rcx,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3c73:
	/* 0x3c73: cmp    rcx,r13 */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RCX, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_3c76:
	/* 0x3c76: jbe    3c60 <generic_kprobe_process_event+0x3c60> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x3c76, 0x3c60, x86_l_3c60);
x86_l_3c78:
	/* 0x3c78: test   r13b,0x4 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, 0, 4ULL);
x86_l_3c7c:
	/* 0x3c7c: jne    3fc4 <generic_kprobe_process_event+0x3fc4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x3c7c, 0x3fc4, x86_l_3fc4);
x86_l_3c82:
	/* 0x3c82: test   r13b,0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, 0, 2ULL);
x86_l_3c86:
	/* 0x3c86: jne    3fd9 <generic_kprobe_process_event+0x3fd9> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x3c86, 0x3fd9, x86_l_3fd9);
x86_l_3c8c:
	/* 0x3c8c: test   r13b,0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_3c90:
	/* 0x3c90: jne    3fec <generic_kprobe_process_event+0x3fec> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x3c90, 0x3fec, x86_l_3fec);
x86_l_3c96:
	/* 0x3c96: jmp    3ff5 <generic_kprobe_process_event+0x3ff5> */
	X86_SIM_X86_JMP(0x3c96, 0x3ff5, x86_l_3ff5);
x86_l_3c9b:
	/* 0x3c9b: mov    esi,r13d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_R13, X86_WIDTH_32, 0, 0);
x86_l_3c9e:
	/* 0x3c9e: call   3ea3 <generic_kprobe_process_event+0x3ea3> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_3ca3:
	/* 0x3ca3: test   eax,eax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_3ca5:
	/* 0x3ca5: js     3cb6 <generic_kprobe_process_event+0x3cb6> */
	X86_SIM_X86_JCC(X86_CC_S, 0x3ca5, 0x3cb6, x86_l_3cb6);
x86_l_3ca7:
	/* 0x3ca7: jmp    3ff5 <generic_kprobe_process_event+0x3ff5> */
	X86_SIM_X86_JMP(0x3ca7, 0x3ff5, x86_l_3ff5);
x86_l_3cac:
	/* 0x3cac: xor    esi,esi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_3cae:
	/* 0x3cae: mov    rdx,r13 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_3cb1:
	/* 0x3cb1: call   4f97 <__native_link_local_memset_zero_dynamic> */
	X86_SIM_X86_CALL(x86_l_4f97, 0x3cb6ULL);
x86_l_3cb6:
	/* 0x3cb6: mov    DWORD PTR [r12],0xfffffffe */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4294967294ULL);
x86_l_3cbe:
	/* 0x3cbe: mov    r15d,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_3cc4:
	/* 0x3cc4: jmp    41f3 <generic_kprobe_process_event+0x41f3> */
	X86_SIM_X86_JMP(0x3cc4, 0x41f3, x86_l_41f3);
x86_l_3cc9:
	/* 0x3cc9: mov    DWORD PTR [rsp+0x70],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_3cd1:
	/* 0x3cd1: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_3cd3:
	/* 0x3cd3: mov    eax,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_3cd5:
	/* 0x3cd5: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3cda:
	/* 0x3cda: mov    QWORD PTR [rcx+0x8],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3cde:
	/* 0x3cde: lea    rdi,[rcx+0x2] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_3ce2:
	/* 0x3ce2: add    r15,0x2 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_3ce6:
	/* 0x3ce6: jns    3d22 <generic_kprobe_process_event+0x3d22> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x3ce6, 0x3d22, x86_l_3d22);
x86_l_3ce8:
	/* 0x3ce8: test   r15,r15 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_3ceb:
	/* 0x3ceb: jns    3d31 <generic_kprobe_process_event+0x3d31> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x3ceb, 0x3d31, x86_l_3d31);
x86_l_3ced:
	/* 0x3ced: movzx  eax,WORD PTR [r15] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3cf1:
	/* 0x3cf1: mov    WORD PTR [rdi],ax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3cf4:
	/* 0x3cf4: jmp    3d36 <generic_kprobe_process_event+0x3d36> */
	X86_SIM_X86_JMP(0x3cf4, 0x3d36, x86_l_3d36);
x86_l_3cf6:
	/* 0x3cf6: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_3cfe:
	/* 0x3cfe: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3d05:
	/* 0x3d05: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3d0a:
	/* 0x3d0a: lea    rdi,[rax+0x2] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_3d0e:
	/* 0x3d0e: add    r15,0x2 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_3d12:
	/* 0x3d12: jns    3d22 <generic_kprobe_process_event+0x3d22> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x3d12, 0x3d22, x86_l_3d22);
x86_l_3d14:
	/* 0x3d14: test   r15,r15 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_3d17:
	/* 0x3d17: jns    3d31 <generic_kprobe_process_event+0x3d31> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x3d17, 0x3d31, x86_l_3d31);
x86_l_3d19:
	/* 0x3d19: movzx  eax,WORD PTR [r15] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3d1d:
	/* 0x3d1d: mov    WORD PTR [rdi],ax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3d20:
	/* 0x3d20: jmp    3d36 <generic_kprobe_process_event+0x3d36> */
	X86_SIM_X86_JMP(0x3d20, 0x3d36, x86_l_3d36);
x86_l_3d22:
	/* 0x3d22: mov    esi,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_3d27:
	/* 0x3d27: mov    rdx,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_3d2a:
	/* 0x3d2a: call   3f2f <generic_kprobe_process_event+0x3f2f> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_3d2f:
	/* 0x3d2f: jmp    3d36 <generic_kprobe_process_event+0x3d36> */
	X86_SIM_X86_JMP(0x3d2f, 0x3d36, x86_l_3d36);
x86_l_3d31:
	/* 0x3d31: mov    WORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3d36:
	/* 0x3d36: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3d3b:
	/* 0x3d3b: movzx  eax,WORD PTR [rcx+0x2] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_3d3f:
	/* 0x3d3f: movbe  WORD PTR [rcx+0x2],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_3d45:
	/* 0x3d45: mov    r15d,0x18 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 24ULL);
x86_l_3d4b:
	/* 0x3d4b: jmp    423c <generic_kprobe_process_event+0x423c> */
	X86_SIM_X86_JMP(0x3d4b, 0x423c, x86_l_423c);
x86_l_3d50:
	/* 0x3d50: mov    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_3d52:
	/* 0x3d52: mov    esi,DWORD PTR [rdx+rcx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3d55:
	/* 0x3d55: mov    DWORD PTR [rdi+rcx*1],esi */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3d58:
	/* 0x3d58: or     eax,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_OR, 4ULL);
x86_l_3d5b:
	/* 0x3d5b: test   r13b,0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, 0, 2ULL);
x86_l_3d5f:
	/* 0x3d5f: je     30b7 <generic_kprobe_process_event+0x30b7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3d5f, 0x30b7, x86_l_30b7);
x86_l_3d65:
	/* 0x3d65: mov    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_3d67:
	/* 0x3d67: movzx  esi,WORD PTR [rdx+rcx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_16), 0ULL);
x86_l_3d6b:
	/* 0x3d6b: mov    WORD PTR [rdi+rcx*1],si */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RSI, X86_WIDTH_16, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3d6f:
	/* 0x3d6f: add    eax,0x2 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_3d72:
	/* 0x3d72: test   r13b,0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_3d76:
	/* 0x3d76: je     3ff5 <generic_kprobe_process_event+0x3ff5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3d76, 0x3ff5, x86_l_3ff5);
x86_l_3d7c:
	/* 0x3d7c: mov    eax,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_3d7e:
	/* 0x3d7e: movzx  ecx,BYTE PTR [rdx+rax*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_3d82:
	/* 0x3d82: jmp    3ff2 <generic_kprobe_process_event+0x3ff2> */
	X86_SIM_X86_JMP(0x3d82, 0x3ff2, x86_l_3ff2);
x86_l_3d87:
	/* 0x3d87: mov    DWORD PTR [rcx+0x68],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_3d8e:
	/* 0x3d8e: mov    QWORD PTR [rcx+0x60],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_3d96:
	/* 0x3d96: mov    QWORD PTR [rcx+0x58],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_3d9e:
	/* 0x3d9e: mov    QWORD PTR [rcx+0x50],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_3da6:
	/* 0x3da6: mov    QWORD PTR [rcx+0x48],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_3dae:
	/* 0x3dae: mov    QWORD PTR [rcx+0x40],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_3db6:
	/* 0x3db6: mov    QWORD PTR [rcx+0x38],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_3dbe:
	/* 0x3dbe: mov    QWORD PTR [rcx+0x30],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_3dc6:
	/* 0x3dc6: mov    QWORD PTR [rcx+0x28],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_3dce:
	/* 0x3dce: mov    QWORD PTR [rcx+0x20],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_3dd6:
	/* 0x3dd6: mov    QWORD PTR [rcx+0x18],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_3dde:
	/* 0x3dde: mov    QWORD PTR [rcx+0x10],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3de6:
	/* 0x3de6: mov    QWORD PTR [rcx+0x8],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_3dee:
	/* 0x3dee: mov    QWORD PTR [rcx],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3df5:
	/* 0x3df5: jmp    4236 <generic_kprobe_process_event+0x4236> */
	X86_SIM_X86_JMP(0x3df5, 0x4236, x86_l_4236);
x86_l_3dfa:
	/* 0x3dfa: mov    WORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3dff:
	/* 0x3dff: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3e04:
	/* 0x3e04: lea    rdi,[rax+0x22] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_3e08:
	/* 0x3e08: add    r15,0x2 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_3e0c:
	/* 0x3e0c: jns    415f <generic_kprobe_process_event+0x415f> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x3e0c, 0x415f, x86_l_415f);
x86_l_3e12:
	/* 0x3e12: test   r15,r15 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_3e15:
	/* 0x3e15: jns    416e <generic_kprobe_process_event+0x416e> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x3e15, 0x416e, x86_l_416e);
x86_l_3e1b:
	/* 0x3e1b: movzx  eax,WORD PTR [r15] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3e1f:
	/* 0x3e1f: mov    WORD PTR [rdi],ax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3e22:
	/* 0x3e22: jmp    4173 <generic_kprobe_process_event+0x4173> */
	X86_SIM_X86_JMP(0x3e22, 0x4173, x86_l_4173);
x86_l_3e27:
	/* 0x3e27: mov    BYTE PTR [r13+0x0],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3e2c:
	/* 0x3e2c: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_3e2e:
	/* 0x3e2e: jmp    400f <generic_kprobe_process_event+0x400f> */
	X86_SIM_X86_JMP(0x3e2e, 0x400f, x86_l_400f);
x86_l_3e33:
	/* 0x3e33: mov    r15d,0x3 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 3ULL);
x86_l_3e39:
	/* 0x3e39: jmp    45ce <generic_kprobe_process_event+0x45ce> */
	X86_SIM_X86_JMP(0x3e39, 0x45ce, x86_l_45ce);
x86_l_3e3e:
	/* 0x3e3e: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3e43:
	/* 0x3e43: mov    BYTE PTR [rax+0x4e],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 335007449088ULL);
x86_l_3e47:
	/* 0x3e47: jmp    1924 <generic_kprobe_process_event+0x1924> */
	X86_SIM_X86_JMP(0x3e47, 0x1924, x86_l_1924);
x86_l_3e4c:
	/* 0x3e4c: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3e51:
	/* 0x3e51: mov    DWORD PTR [rax],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3e57:
	/* 0x3e57: test   r15,r15 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_3e5a:
	/* 0x3e5a: jns    3e6c <generic_kprobe_process_event+0x3e6c> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x3e5a, 0x3e6c, x86_l_3e6c);
x86_l_3e5c:
	/* 0x3e5c: mov    rax,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_3e5f:
	/* 0x3e5f: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_3e62:
	/* 0x3e62: jns    3e79 <generic_kprobe_process_event+0x3e79> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x3e62, 0x3e79, x86_l_3e79);
x86_l_3e64:
	/* 0x3e64: mov    eax,DWORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3e66:
	/* 0x3e66: mov    DWORD PTR [r12],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3e6a:
	/* 0x3e6a: jmp    3ecc <generic_kprobe_process_event+0x3ecc> */
	X86_SIM_X86_JMP(0x3e6a, 0x3ecc, x86_l_3ecc);
x86_l_3e6c:
	/* 0x3e6c: mov    rdi,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_3e6f:
	/* 0x3e6f: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_3e74:
	/* 0x3e74: mov    rdx,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_3e77:
	/* 0x3e77: jmp    3ec7 <generic_kprobe_process_event+0x3ec7> */
	X86_SIM_X86_JMP(0x3e77, 0x3ec7, x86_l_3ec7);
x86_l_3e79:
	/* 0x3e79: mov    DWORD PTR [r12],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3e81:
	/* 0x3e81: jmp    3ecc <generic_kprobe_process_event+0x3ecc> */
	X86_SIM_X86_JMP(0x3e81, 0x3ecc, x86_l_3ecc);
x86_l_3e83:
	/* 0x3e83: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3e88:
	/* 0x3e88: mov    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_3e90:
	/* 0x3e90: mov    QWORD PTR [rax],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3e97:
	/* 0x3e97: mov    rdx,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_3e9a:
	/* 0x3e9a: add    rdx,0x38 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 56ULL);
x86_l_3e9e:
	/* 0x3e9e: jns    3ebf <generic_kprobe_process_event+0x3ebf> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x3e9e, 0x3ebf, x86_l_3ebf);
x86_l_3ea0:
	/* 0x3ea0: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_3ea3:
	/* 0x3ea3: jns    3f7d <generic_kprobe_process_event+0x3f7d> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x3ea3, 0x3f7d, x86_l_3f7d);
x86_l_3ea9:
	/* 0x3ea9: mov    rax,QWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3eac:
	/* 0x3eac: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3eb1:
	/* 0x3eb1: mov    QWORD PTR [rcx+0x10],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3eb5:
	/* 0x3eb5: mov    rax,QWORD PTR [rdx+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3eb9:
	/* 0x3eb9: mov    QWORD PTR [rcx+0x18],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3ebd:
	/* 0x3ebd: jmp    3ecc <generic_kprobe_process_event+0x3ecc> */
	X86_SIM_X86_JMP(0x3ebd, 0x3ecc, x86_l_3ecc);
x86_l_3ebf:
	/* 0x3ebf: mov    rdi,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_3ec2:
	/* 0x3ec2: mov    esi,0x10 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 16ULL);
x86_l_3ec7:
	/* 0x3ec7: call   40c9 <generic_kprobe_process_event+0x40c9> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_3ecc:
	/* 0x3ecc: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3ed1:
	/* 0x3ed1: lea    rdi,[rax+0x20] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3ed5:
	/* 0x3ed5: lea    r12,[r15+0xc] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R12, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3ed9:
	/* 0x3ed9: add    r15,0xe */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 14ULL);
x86_l_3edd:
	/* 0x3edd: jns    3eed <generic_kprobe_process_event+0x3eed> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x3edd, 0x3eed, x86_l_3eed);
x86_l_3edf:
	/* 0x3edf: test   r15,r15 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_3ee2:
	/* 0x3ee2: jns    3efc <generic_kprobe_process_event+0x3efc> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x3ee2, 0x3efc, x86_l_3efc);
x86_l_3ee4:
	/* 0x3ee4: movzx  eax,WORD PTR [r15] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3ee8:
	/* 0x3ee8: mov    WORD PTR [rdi],ax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3eeb:
	/* 0x3eeb: jmp    3f01 <generic_kprobe_process_event+0x3f01> */
	X86_SIM_X86_JMP(0x3eeb, 0x3f01, x86_l_3f01);
x86_l_3eed:
	/* 0x3eed: mov    esi,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_3ef2:
	/* 0x3ef2: mov    rdx,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_3ef5:
	/* 0x3ef5: call   40fa <generic_kprobe_process_event+0x40fa> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_3efa:
	/* 0x3efa: jmp    3f01 <generic_kprobe_process_event+0x3f01> */
	X86_SIM_X86_JMP(0x3efa, 0x3f01, x86_l_3f01);
x86_l_3efc:
	/* 0x3efc: mov    WORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3f01:
	/* 0x3f01: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3f06:
	/* 0x3f06: lea    r15,[rax+0x22] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_3f0a:
	/* 0x3f0a: test   r12,r12 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_3f0d:
	/* 0x3f0d: jns    3f1b <generic_kprobe_process_event+0x3f1b> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x3f0d, 0x3f1b, x86_l_3f1b);
x86_l_3f0f:
	/* 0x3f0f: test   r12,r12 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_3f12:
	/* 0x3f12: jns    3f31 <generic_kprobe_process_event+0x3f31> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x3f12, 0x3f31, x86_l_3f31);
x86_l_3f14:
	/* 0x3f14: movzx  eax,WORD PTR [r12] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3f19:
	/* 0x3f19: jmp    3f33 <generic_kprobe_process_event+0x3f33> */
	X86_SIM_X86_JMP(0x3f19, 0x3f33, x86_l_3f33);
x86_l_3f1b:
	/* 0x3f1b: mov    rdi,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_3f1e:
	/* 0x3f1e: mov    esi,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_3f23:
	/* 0x3f23: mov    rdx,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_3f26:
	/* 0x3f26: call   4128 <generic_kprobe_process_event+0x4128> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_3f2b:
	/* 0x3f2b: movzx  eax,WORD PTR [r15] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3f2f:
	/* 0x3f2f: jmp    3f33 <generic_kprobe_process_event+0x3f33> */
	X86_SIM_X86_JMP(0x3f2f, 0x3f33, x86_l_3f33);
x86_l_3f31:
	/* 0x3f31: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_3f33:
	/* 0x3f33: movbe  WORD PTR [r15],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3f39:
	/* 0x3f39: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3f3e:
	/* 0x3f3e: mov    rax,QWORD PTR [rax+0x28] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3f42:
	/* 0x3f42: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_3f47:
	/* 0x3f47: mov    rdi,QWORD PTR [rip+0x1fd] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)socktrack_map));
x86_l_3f4e:
	/* 0x3f4e: lea    rsi,[rsp+0x70] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_3f53:
	/* 0x3f53: call   4155 <generic_kprobe_process_event+0x4155> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_3f58:
	/* 0x3f58: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_3f5b:
	/* 0x3f5b: je     3f72 <generic_kprobe_process_event+0x3f72> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3f5b, 0x3f72, x86_l_3f72);
x86_l_3f5d:
	/* 0x3f5d: mov    ecx,DWORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3f5f:
	/* 0x3f5f: mov    DWORD PTR [r13+0x10],ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3f63:
	/* 0x3f63: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3f67:
	/* 0x3f67: mov    QWORD PTR [r13+0x18],rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3f6b:
	/* 0x3f6b: mov    eax,DWORD PTR [rax+0x4] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3f6e:
	/* 0x3f6e: mov    DWORD PTR [r13+0x7c],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_3f72:
	/* 0x3f72: mov    r15d,0x40 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 64ULL);
x86_l_3f78:
	/* 0x3f78: jmp    2d4e <generic_kprobe_process_event+0x2d4e> */
	X86_SIM_X86_JMP(0x3f78, 0x2d4e, x86_l_2d4e);
x86_l_3f7d:
	/* 0x3f7d: mov    QWORD PTR [r12+0x8],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_3f86:
	/* 0x3f86: mov    QWORD PTR [r12],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3f8e:
	/* 0x3f8e: jmp    3ecc <generic_kprobe_process_event+0x3ecc> */
	X86_SIM_X86_JMP(0x3f8e, 0x3ecc, x86_l_3ecc);
x86_l_3f93:
	/* 0x3f93: mov    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_3f95:
	/* 0x3f95: mov    edx,DWORD PTR [rsi+rcx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3f98:
	/* 0x3f98: mov    DWORD PTR [rdi+rcx*1],edx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3f9b:
	/* 0x3f9b: or     eax,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_OR, 4ULL);
x86_l_3f9e:
	/* 0x3f9e: test   r12b,0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, 0, 2ULL);
x86_l_3fa2:
	/* 0x3fa2: je     3a31 <generic_kprobe_process_event+0x3a31> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3fa2, 0x3a31, x86_l_3a31);
x86_l_3fa8:
	/* 0x3fa8: mov    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_3faa:
	/* 0x3faa: movzx  edx,WORD PTR [rsi+rcx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_16), 0ULL);
x86_l_3fae:
	/* 0x3fae: mov    WORD PTR [rdi+rcx*1],dx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3fb2:
	/* 0x3fb2: add    eax,0x2 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_3fb5:
	/* 0x3fb5: test   r12b,0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_3fb9:
	/* 0x3fb9: jne    3a37 <generic_kprobe_process_event+0x3a37> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x3fb9, 0x3a37, x86_l_3a37);
x86_l_3fbf:
	/* 0x3fbf: jmp    3a40 <generic_kprobe_process_event+0x3a40> */
	X86_SIM_X86_JMP(0x3fbf, 0x3a40, x86_l_3a40);
x86_l_3fc4:
	/* 0x3fc4: mov    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_3fc6:
	/* 0x3fc6: mov    esi,DWORD PTR [rdx+rcx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3fc9:
	/* 0x3fc9: mov    DWORD PTR [rdi+rcx*1],esi */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3fcc:
	/* 0x3fcc: or     eax,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_OR, 4ULL);
x86_l_3fcf:
	/* 0x3fcf: test   r13b,0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, 0, 2ULL);
x86_l_3fd3:
	/* 0x3fd3: je     3c8c <generic_kprobe_process_event+0x3c8c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3fd3, 0x3c8c, x86_l_3c8c);
x86_l_3fd9:
	/* 0x3fd9: mov    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_3fdb:
	/* 0x3fdb: movzx  esi,WORD PTR [rdx+rcx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_16), 0ULL);
x86_l_3fdf:
	/* 0x3fdf: mov    WORD PTR [rdi+rcx*1],si */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RSI, X86_WIDTH_16, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3fe3:
	/* 0x3fe3: add    eax,0x2 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_3fe6:
	/* 0x3fe6: test   r13b,0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_3fea:
	/* 0x3fea: je     3ff5 <generic_kprobe_process_event+0x3ff5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3fea, 0x3ff5, x86_l_3ff5);
x86_l_3fec:
	/* 0x3fec: mov    eax,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_3fee:
	/* 0x3fee: movzx  ecx,BYTE PTR [rdx+rax*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_3ff2:
	/* 0x3ff2: mov    BYTE PTR [rdi+rax*1],cl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3ff5:
	/* 0x3ff5: mov    DWORD PTR [r12],ebx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_R12, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3ff9:
	/* 0x3ff9: mov    DWORD PTR [r12+0x4],r13d */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_R12, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3ffe:
	/* 0x3ffe: add    r15,r13 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R15, X86_R13, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_4001:
	/* 0x4001: jmp    41f3 <generic_kprobe_process_event+0x41f3> */
	X86_SIM_X86_JMP(0x4001, 0x41f3, x86_l_41f3);
x86_l_4006:
	/* 0x4006: mov    WORD PTR [r13+0x0],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_400d:
	/* 0x400d: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_400f:
	/* 0x400f: mov    BYTE PTR [rsp+0x60],cl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_4013:
	/* 0x4013: movzx  eax,cl */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8, 0);
x86_l_4016:
	/* 0x4016: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_401b:
	/* 0x401b: mov    WORD PTR [rcx+0x24],ax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_401f:
	/* 0x401f: mov    WORD PTR [rcx+0x26],0xa */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 163208757258ULL);
x86_l_4025:
	/* 0x4025: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_402a:
	/* 0x402a: add    rdx,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_402e:
	/* 0x402e: jns    404a <generic_kprobe_process_event+0x404a> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x402e, 0x404a, x86_l_404a);
x86_l_4030:
	/* 0x4030: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_4033:
	/* 0x4033: jns    405b <generic_kprobe_process_event+0x405b> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x4033, 0x405b, x86_l_405b);
x86_l_4035:
	/* 0x4035: mov    rax,QWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4038:
	/* 0x4038: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_403d:
	/* 0x403d: mov    QWORD PTR [rcx],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4040:
	/* 0x4040: mov    rax,QWORD PTR [rdx+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4044:
	/* 0x4044: mov    QWORD PTR [rcx+0x8],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4048:
	/* 0x4048: jmp    406f <generic_kprobe_process_event+0x406f> */
	X86_SIM_X86_JMP(0x4048, 0x406f, x86_l_406f);
x86_l_404a:
	/* 0x404a: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_404f:
	/* 0x404f: mov    esi,0x10 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 16ULL);
x86_l_4054:
	/* 0x4054: call   4256 <generic_kprobe_process_event+0x4256> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_4059:
	/* 0x4059: jmp    406f <generic_kprobe_process_event+0x406f> */
	X86_SIM_X86_JMP(0x4059, 0x406f, x86_l_406f);
x86_l_405b:
	/* 0x405b: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4060:
	/* 0x4060: mov    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_4068:
	/* 0x4068: mov    QWORD PTR [rax],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_406f:
	/* 0x406f: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4074:
	/* 0x4074: lea    rdi,[rax+0x10] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4078:
	/* 0x4078: add    QWORD PTR [rsp+0x28],0x18 */
	X86_SIM_RUN_OP(X86_OP_ALU_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 171798691864ULL);
x86_l_407e:
	/* 0x407e: jns    40b7 <generic_kprobe_process_event+0x40b7> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x407e, 0x40b7, x86_l_40b7);
x86_l_4080:
	/* 0x4080: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4085:
	/* 0x4085: test   rcx,rcx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_4088:
	/* 0x4088: jns    411f <generic_kprobe_process_event+0x411f> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x4088, 0x411f, x86_l_411f);
x86_l_408e:
	/* 0x408e: mov    rax,rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_4091:
	/* 0x4091: mov    rdx,rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_4094:
	/* 0x4094: mov    rax,QWORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4097:
	/* 0x4097: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_409c:
	/* 0x409c: mov    QWORD PTR [rcx+0x10],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_40a0:
	/* 0x40a0: mov    rax,QWORD PTR [rdx+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_40a4:
	/* 0x40a4: mov    QWORD PTR [rcx+0x18],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_40a8:
	/* 0x40a8: movzx  eax,BYTE PTR [rsp+0x60] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 96ULL);
x86_l_40ad:
	/* 0x40ad: cmp    eax,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_40b0:
	/* 0x40b0: jne    40d4 <generic_kprobe_process_event+0x40d4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x40b0, 0x40d4, x86_l_40d4);
x86_l_40b2:
	/* 0x40b2: jmp    385f <generic_kprobe_process_event+0x385f> */
	X86_SIM_X86_JMP(0x40b2, 0x385f, x86_l_385f);
x86_l_40b7:
	/* 0x40b7: mov    esi,0x10 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 16ULL);
x86_l_40bc:
	/* 0x40bc: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_40c1:
	/* 0x40c1: call   42c6 <generic_kprobe_process_event+0x42c6> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_40c6:
	/* 0x40c6: movzx  eax,BYTE PTR [rsp+0x60] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 96ULL);
x86_l_40cb:
	/* 0x40cb: cmp    eax,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_40ce:
	/* 0x40ce: je     385f <generic_kprobe_process_event+0x385f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x40ce, 0x385f, x86_l_385f);
x86_l_40d4:
	/* 0x40d4: cmp    eax,0x6 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 6ULL);
x86_l_40d7:
	/* 0x40d7: jne    4102 <generic_kprobe_process_event+0x4102> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x40d7, 0x4102, x86_l_4102);
x86_l_40d9:
	/* 0x40d9: movzx  r15d,WORD PTR [rsp+0xc0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 192ULL);
x86_l_40e2:
	/* 0x40e2: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_40e7:
	/* 0x40e7: lea    rdi,[rax+0x20] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_40eb:
	/* 0x40eb: add    r15,QWORD PTR [rsp+0x70] */
	X86_SIM_RUN_OP(X86_OP_ALU_MEM, X86_R15, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 112ULL);
x86_l_40f0:
	/* 0x40f0: jns    4110 <generic_kprobe_process_event+0x4110> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x40f0, 0x4110, x86_l_4110);
x86_l_40f2:
	/* 0x40f2: mov    rax,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_40f5:
	/* 0x40f5: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_40f8:
	/* 0x40f8: jns    413d <generic_kprobe_process_event+0x413d> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x40f8, 0x413d, x86_l_413d);
x86_l_40fa:
	/* 0x40fa: movzx  eax,WORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_40fd:
	/* 0x40fd: mov    WORD PTR [rdi],ax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4100:
	/* 0x4100: jmp    4142 <generic_kprobe_process_event+0x4142> */
	X86_SIM_X86_JMP(0x4100, 0x4142, x86_l_4142);
x86_l_4102:
	/* 0x4102: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4107:
	/* 0x4107: mov    DWORD PTR [rax+0x20],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_410e:
	/* 0x410e: jmp    4173 <generic_kprobe_process_event+0x4173> */
	X86_SIM_X86_JMP(0x410e, 0x4173, x86_l_4173);
x86_l_4110:
	/* 0x4110: mov    esi,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_4115:
	/* 0x4115: mov    rdx,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_4118:
	/* 0x4118: call   431a <generic_kprobe_process_event+0x431a> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_411d:
	/* 0x411d: jmp    4142 <generic_kprobe_process_event+0x4142> */
	X86_SIM_X86_JMP(0x411d, 0x4142, x86_l_4142);
x86_l_411f:
	/* 0x411f: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_4127:
	/* 0x4127: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_412e:
	/* 0x412e: movzx  eax,BYTE PTR [rsp+0x60] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 96ULL);
x86_l_4133:
	/* 0x4133: cmp    eax,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_4136:
	/* 0x4136: jne    40d4 <generic_kprobe_process_event+0x40d4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4136, 0x40d4, x86_l_40d4);
x86_l_4138:
	/* 0x4138: jmp    385f <generic_kprobe_process_event+0x385f> */
	X86_SIM_X86_JMP(0x4138, 0x385f, x86_l_385f);
x86_l_413d:
	/* 0x413d: mov    WORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4142:
	/* 0x4142: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4147:
	/* 0x4147: lea    rdi,[rax+0x22] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_414b:
	/* 0x414b: add    r15,0x2 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_414f:
	/* 0x414f: jns    415f <generic_kprobe_process_event+0x415f> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x414f, 0x415f, x86_l_415f);
x86_l_4151:
	/* 0x4151: test   r15,r15 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_4154:
	/* 0x4154: jns    416e <generic_kprobe_process_event+0x416e> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x4154, 0x416e, x86_l_416e);
x86_l_4156:
	/* 0x4156: movzx  eax,WORD PTR [r15] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_415a:
	/* 0x415a: mov    WORD PTR [rdi],ax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_415d:
	/* 0x415d: jmp    4173 <generic_kprobe_process_event+0x4173> */
	X86_SIM_X86_JMP(0x415d, 0x4173, x86_l_4173);
x86_l_415f:
	/* 0x415f: mov    esi,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_4164:
	/* 0x4164: mov    rdx,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_4167:
	/* 0x4167: call   4369 <generic_kprobe_process_event+0x4369> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_416c:
	/* 0x416c: jmp    4173 <generic_kprobe_process_event+0x4173> */
	X86_SIM_X86_JMP(0x416c, 0x4173, x86_l_4173);
x86_l_416e:
	/* 0x416e: mov    WORD PTR [rdi],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4173:
	/* 0x4173: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4178:
	/* 0x4178: movzx  eax,WORD PTR [rdx+0x20] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_417c:
	/* 0x417c: movzx  ecx,WORD PTR [rdx+0x22] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_4180:
	/* 0x4180: movbe  WORD PTR [rdx+0x20],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RDX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_4186:
	/* 0x4186: movbe  WORD PTR [rdx+0x22],cx */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RDX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_418c:
	/* 0x418c: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4191:
	/* 0x4191: add    rcx,0xe0 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 224ULL);
x86_l_4198:
	/* 0x4198: test   rcx,rcx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_419b:
	/* 0x419b: jns    41ed <generic_kprobe_process_event+0x41ed> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x419b, 0x41ed, x86_l_41ed);
x86_l_419d:
	/* 0x419d: mov    rax,rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_41a0:
	/* 0x41a0: mov    rdx,QWORD PTR [rcx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_41a3:
	/* 0x41a3: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_41a6:
	/* 0x41a6: je     41ed <generic_kprobe_process_event+0x41ed> */
	X86_SIM_X86_JCC(X86_CC_E, 0x41a6, 0x41ed, x86_l_41ed);
x86_l_41a8:
	/* 0x41a8: lea    rcx,[rdx+0x5] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_41ac:
	/* 0x41ac: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_41ae:
	/* 0x41ae: test   rcx,rcx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_41b1:
	/* 0x41b1: jns    41bc <generic_kprobe_process_event+0x41bc> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x41b1, 0x41bc, x86_l_41bc);
x86_l_41b3:
	/* 0x41b3: mov    rsi,QWORD PTR [rcx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_41b6:
	/* 0x41b6: shl    rsi,0x3 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 3ULL);
x86_l_41ba:
	/* 0x41ba: jmp    41be <generic_kprobe_process_event+0x41be> */
	X86_SIM_X86_JMP(0x41ba, 0x41be, x86_l_41be);
x86_l_41bc:
	/* 0x41bc: xor    esi,esi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_41be:
	/* 0x41be: lea    rcx,[rdx+rsi*1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_41c2:
	/* 0x41c2: add    rdx,rsi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_41c5:
	/* 0x41c5: add    rdx,0x44 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 68ULL);
x86_l_41c9:
	/* 0x41c9: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_41cc:
	/* 0x41cc: jns    41d0 <generic_kprobe_process_event+0x41d0> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x41cc, 0x41d0, x86_l_41d0);
x86_l_41ce:
	/* 0x41ce: mov    eax,DWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_41d0:
	/* 0x41d0: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_41d5:
	/* 0x41d5: mov    DWORD PTR [rdx+0x38],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_41d8:
	/* 0x41d8: add    rcx,0x45 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 69ULL);
x86_l_41dc:
	/* 0x41dc: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_41de:
	/* 0x41de: test   rcx,rcx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_41e1:
	/* 0x41e1: jns    41e5 <generic_kprobe_process_event+0x41e5> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x41e1, 0x41e5, x86_l_41e5);
x86_l_41e3:
	/* 0x41e3: mov    eax,DWORD PTR [rcx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_41e5:
	/* 0x41e5: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_41ea:
	/* 0x41ea: mov    DWORD PTR [rcx+0x3c],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_41ed:
	/* 0x41ed: mov    r15d,0x40 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 64ULL);
x86_l_41f3:
	/* 0x41f3: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_41f8:
	/* 0x41f8: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_41fd:
	/* 0x41fd: mov    rbx,QWORD PTR [rsp+0x48] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_4202:
	/* 0x4202: jmp    4246 <generic_kprobe_process_event+0x4246> */
	X86_SIM_X86_JMP(0x4202, 0x4246, x86_l_4246);
x86_l_4204:
	/* 0x4204: mov    esi,r15d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_R15, X86_WIDTH_32, 0, 0);
x86_l_4207:
	/* 0x4207: call   4409 <generic_kprobe_process_event+0x4409> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_420c:
	/* 0x420c: mov    ecx,0xfffffffe */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 4294967294ULL);
x86_l_4211:
	/* 0x4211: test   eax,eax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_4213:
	/* 0x4213: jns    4341 <generic_kprobe_process_event+0x4341> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x4213, 0x4341, x86_l_4341);
x86_l_4219:
	/* 0x4219: jmp    43b8 <generic_kprobe_process_event+0x43b8> */
	X86_SIM_X86_JMP(0x4219, 0x43b8, x86_l_43b8);
x86_l_421e:
	/* 0x421e: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4223:
	/* 0x4223: mov    BYTE PTR [rax+0x6f],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 476741369856ULL);
x86_l_4227:
	/* 0x4227: mov    eax,0x6c */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 108ULL);
x86_l_422c:
	/* 0x422c: dec    al */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_ALU_DEC, 1);
x86_l_422e:
	/* 0x422e: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4233:
	/* 0x4233: mov    BYTE PTR [rcx+0x3],al */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 3ULL);
x86_l_4236:
	/* 0x4236: mov    r15d,0x70 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 112ULL);
x86_l_423c:
	/* 0x423c: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4241:
	/* 0x4241: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4246:
	/* 0x4246: mov    r12,QWORD PTR [rsp+0xb0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_424e:
	/* 0x424e: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4253:
	/* 0x4253: test   r15d,r15d */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32, 0, 0);
x86_l_4256:
	/* 0x4256: js     4268 <generic_kprobe_process_event+0x4268> */
	X86_SIM_X86_JCC(X86_CC_S, 0x4256, 0x4268, x86_l_4268);
x86_l_4258:
	/* 0x4258: and    r15d,0x7fffffff */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_425f:
	/* 0x425f: add    r15d,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4263:
	/* 0x4263: mov    edx,r15d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R15, X86_WIDTH_32, 0, 0);
x86_l_4266:
	/* 0x4266: jmp    4284 <generic_kprobe_process_event+0x4284> */
	X86_SIM_X86_JMP(0x4266, 0x4284, x86_l_4284);
x86_l_4268:
	/* 0x4268: mov    DWORD PTR [rcx+rsi*4+0x5ea0],0xffffffff */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 104045582745599ULL);
x86_l_4273:
	/* 0x4273: mov    DWORD PTR [rcx+r12*1+0x90],0xffffffff */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 622770257919ULL);
x86_l_427f:
	/* 0x427f: mov    edx,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_4284:
	/* 0x4284: add    edx,r12d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_R12, X86_WIDTH_32, X86_ALU_ADD, 0);
x86_l_4287:
	/* 0x4287: mov    r12d,edx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R12, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_428a:
	/* 0x428a: mov    DWORD PTR [r14+0x4],r12d */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_R14, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_428e:
	/* 0x428e: cmp    ebx,0x3 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 3ULL);
x86_l_4291:
	/* 0x4291: jle    67d <generic_kprobe_process_event+0x67d> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x4291, 0x67d, x86_l_67d);
x86_l_4297:
	/* 0x4297: mov    DWORD PTR [r14+0x5efc],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104436424769536ULL);
x86_l_42a2:
	/* 0x42a2: mov    rsi,QWORD PTR [rip+0x204] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RSI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)kprobe_calls));
x86_l_42a9:
	/* 0x42a9: mov    rdi,rbp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_42ac:
	/* 0x42ac: mov    edx,0x3 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 3ULL);
x86_l_42b1:
	/* 0x42b1: call   44b3 <generic_kprobe_process_event+0x44b3> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_tail_call);
x86_l_42b6:
	/* 0x42b6: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_42b8:
	/* 0x42b8: add    rsp,0xf8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 248ULL);
x86_l_42bf:
	/* 0x42bf: pop    rbx */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_42c0:
	/* 0x42c0: pop    r12 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R12, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_42c2:
	/* 0x42c2: pop    r13 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R13, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_42c4:
	/* 0x42c4: pop    r14 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R14, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_42c6:
	/* 0x42c6: pop    r15 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R15, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_42c8:
	/* 0x42c8: pop    rbp */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBP, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_42c9:
	/* 0x42c9: jmp    5040 <__native_link_local_memset_zero_4097+0x2b> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_42ce:
	/* 0x42ce: mov    r15d,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_42d4:
	/* 0x42d4: jmp    45ce <generic_kprobe_process_event+0x45ce> */
	X86_SIM_X86_JMP(0x42d4, 0x45ce, x86_l_45ce);
x86_l_42d9:
	/* 0x42d9: mov    r15d,0x5 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 5ULL);
x86_l_42df:
	/* 0x42df: jmp    45ce <generic_kprobe_process_event+0x45ce> */
	X86_SIM_X86_JMP(0x42df, 0x45ce, x86_l_45ce);
x86_l_42e4:
	/* 0x42e4: xor    esi,esi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_42e6:
	/* 0x42e6: mov    rdx,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_42e9:
	/* 0x42e9: call   4f97 <__native_link_local_memset_zero_dynamic> */
	X86_SIM_X86_CALL(x86_l_4f97, 0x42eeULL);
x86_l_42ee:
	/* 0x42ee: mov    ecx,0xfffffffe */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 4294967294ULL);
x86_l_42f3:
	/* 0x42f3: jmp    43b8 <generic_kprobe_process_event+0x43b8> */
	X86_SIM_X86_JMP(0x42f3, 0x43b8, x86_l_43b8);
x86_l_42f8:
	/* 0x42f8: mov    WORD PTR [rsp+0xc0],ax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_4300:
	/* 0x4300: jmp    400f <generic_kprobe_process_event+0x400f> */
	X86_SIM_X86_JMP(0x4300, 0x400f, x86_l_400f);
x86_l_4305:
	/* 0x4305: mov    r15d,0x6 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 6ULL);
x86_l_430b:
	/* 0x430b: jmp    45ce <generic_kprobe_process_event+0x45ce> */
	X86_SIM_X86_JMP(0x430b, 0x45ce, x86_l_45ce);
x86_l_4310:
	/* 0x4310: mov    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_4312:
	/* 0x4312: mov    esi,DWORD PTR [rdx+rcx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4315:
	/* 0x4315: mov    DWORD PTR [rdi+rcx*1],esi */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4318:
	/* 0x4318: or     eax,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_OR, 4ULL);
x86_l_431b:
	/* 0x431b: test   r15b,0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, 0, 2ULL);
x86_l_431f:
	/* 0x431f: je     36e5 <generic_kprobe_process_event+0x36e5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x431f, 0x36e5, x86_l_36e5);
x86_l_4325:
	/* 0x4325: mov    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_4327:
	/* 0x4327: movzx  esi,WORD PTR [rdx+rcx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_16), 0ULL);
x86_l_432b:
	/* 0x432b: mov    WORD PTR [rdi+rcx*1],si */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RSI, X86_WIDTH_16, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_432f:
	/* 0x432f: add    eax,0x2 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_4332:
	/* 0x4332: test   r15b,0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_4336:
	/* 0x4336: je     4341 <generic_kprobe_process_event+0x4341> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4336, 0x4341, x86_l_4341);
x86_l_4338:
	/* 0x4338: mov    eax,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_433a:
	/* 0x433a: movzx  ecx,BYTE PTR [rdx+rax*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_433e:
	/* 0x433e: mov    BYTE PTR [rdi+rax*1],cl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_4341:
	/* 0x4341: cmp    r12,0x1 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, 0, 1ULL);
x86_l_4345:
	/* 0x4345: je     2f7f <generic_kprobe_process_event+0x2f7f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4345, 0x2f7f, x86_l_2f7f);
x86_l_434b:
	/* 0x434b: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4350:
	/* 0x4350: add    rdx,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4354:
	/* 0x4354: js     4385 <generic_kprobe_process_event+0x4385> */
	X86_SIM_X86_JCC(X86_CC_S, 0x4354, 0x4385, x86_l_4385);
x86_l_4356:
	/* 0x4356: lea    rdi,[rsp+0x70] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_435b:
	/* 0x435b: mov    esi,0x10 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 16ULL);
x86_l_4360:
	/* 0x4360: call   4565 <generic_kprobe_process_event+0x4565> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_4365:
	/* 0x4365: mov    ecx,0xfffffffe */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 4294967294ULL);
x86_l_436a:
	/* 0x436a: test   eax,eax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_436c:
	/* 0x436c: js     43b8 <generic_kprobe_process_event+0x43b8> */
	X86_SIM_X86_JCC(X86_CC_S, 0x436c, 0x43b8, x86_l_43b8);
x86_l_436e:
	/* 0x436e: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_4373:
	/* 0x4373: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4378:
	/* 0x4378: jmp    43a8 <generic_kprobe_process_event+0x43a8> */
	X86_SIM_X86_JMP(0x4378, 0x43a8, x86_l_43a8);
x86_l_437a:
	/* 0x437a: mov    r15d,0x7 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 7ULL);
x86_l_4380:
	/* 0x4380: jmp    45ce <generic_kprobe_process_event+0x45ce> */
	X86_SIM_X86_JMP(0x4380, 0x45ce, x86_l_45ce);
x86_l_4385:
	/* 0x4385: mov    ecx,0xfffffffe */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 4294967294ULL);
x86_l_438a:
	/* 0x438a: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_438d:
	/* 0x438d: jns    43b8 <generic_kprobe_process_event+0x43b8> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x438d, 0x43b8, x86_l_43b8);
x86_l_438f:
	/* 0x438f: mov    rax,QWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4392:
	/* 0x4392: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_4397:
	/* 0x4397: mov    rcx,QWORD PTR [rdx+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_439b:
	/* 0x439b: mov    rax,rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_439e:
	/* 0x439e: mov    QWORD PTR [rsp+0x30],rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_43a3:
	/* 0x43a3: mov    QWORD PTR [rsp+0x78],rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_43a8:
	/* 0x43a8: mov    ecx,0xfffffffd */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 4294967293ULL);
x86_l_43ad:
	/* 0x43ad: cmp    QWORD PTR [rsp+0x30],0xffe */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158434302ULL);
x86_l_43b6:
	/* 0x43b6: jbe    43e7 <generic_kprobe_process_event+0x43e7> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x43b6, 0x43e7, x86_l_43e7);
x86_l_43b8:
	/* 0x43b8: mov    rax,QWORD PTR [rsp+0xb8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_43c0:
	/* 0x43c0: mov    DWORD PTR [rbp+rax*1+0x0],ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_43c4:
	/* 0x43c4: mov    r15d,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_43ca:
	/* 0x43ca: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_43cf:
	/* 0x43cf: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_43d4:
	/* 0x43d4: mov    rbx,r13 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RBX, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_43d7:
	/* 0x43d7: jmp    2d58 <generic_kprobe_process_event+0x2d58> */
	X86_SIM_X86_JMP(0x43d7, 0x2d58, x86_l_2d58);
x86_l_43dc:
	/* 0x43dc: mov    r15d,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_43e2:
	/* 0x43e2: jmp    45ce <generic_kprobe_process_event+0x45ce> */
	X86_SIM_X86_JMP(0x43e2, 0x45ce, x86_l_45ce);
x86_l_43e7:
	/* 0x43e7: add    rbx,r15 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RBX, X86_R15, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_43ea:
	/* 0x43ea: mov    edi,ebx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_RBX, X86_WIDTH_32, 0, 0);
x86_l_43ec:
	/* 0x43ec: and    edi,0x3fff */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_43f2:
	/* 0x43f2: add    rdi,rbp */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_43f5:
	/* 0x43f5: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_43fa:
	/* 0x43fa: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_43fd:
	/* 0x43fd: jns    444d <generic_kprobe_process_event+0x444d> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x43fd, 0x444d, x86_l_444d);
x86_l_43ff:
	/* 0x43ff: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_4402:
	/* 0x4402: jns    493a <generic_kprobe_process_event+0x493a> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x4402, 0x493a, x86_l_493a);
x86_l_4408:
	/* 0x4408: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_440a:
	/* 0x440a: cmp    DWORD PTR [rsp+0x30],0x8 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430216ULL);
x86_l_440f:
	/* 0x440f: jb     442b <generic_kprobe_process_event+0x442b> */
	X86_SIM_X86_JCC(X86_CC_B, 0x440f, 0x442b, x86_l_442b);
x86_l_4411:
	/* 0x4411: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_4413:
	/* 0x4413: mov    eax,ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_4415:
	/* 0x4415: mov    rsi,QWORD PTR [rdx+rax*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_4419:
	/* 0x4419: mov    QWORD PTR [rdi+rax*1],rsi */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_441d:
	/* 0x441d: lea    eax,[rcx+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4420:
	/* 0x4420: add    ecx,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 16ULL);
x86_l_4423:
	/* 0x4423: cmp    ecx,DWORD PTR [rsp+0x30] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 48ULL);
x86_l_4427:
	/* 0x4427: mov    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_4429:
	/* 0x4429: jbe    4413 <generic_kprobe_process_event+0x4413> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x4429, 0x4413, x86_l_4413);
x86_l_442b:
	/* 0x442b: test   BYTE PTR [rsp+0x30],0x4 */
	X86_SIM_RUN_OP(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430212ULL);
x86_l_4430:
	/* 0x4430: jne    4487 <generic_kprobe_process_event+0x4487> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4430, 0x4487, x86_l_4487);
x86_l_4432:
	/* 0x4432: test   BYTE PTR [rsp+0x30],0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430210ULL);
x86_l_4437:
	/* 0x4437: jne    4499 <generic_kprobe_process_event+0x4499> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4437, 0x4499, x86_l_4499);
x86_l_4439:
	/* 0x4439: test   BYTE PTR [rsp+0x30],0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430209ULL);
x86_l_443e:
	/* 0x443e: jne    44ad <generic_kprobe_process_event+0x44ad> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x443e, 0x44ad, x86_l_44ad);
x86_l_4440:
	/* 0x4440: jmp    44b6 <generic_kprobe_process_event+0x44b6> */
	X86_SIM_X86_JMP(0x4440, 0x44b6, x86_l_44b6);
x86_l_4442:
	/* 0x4442: mov    r15d,0x9 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 9ULL);
x86_l_4448:
	/* 0x4448: jmp    45ce <generic_kprobe_process_event+0x45ce> */
	X86_SIM_X86_JMP(0x4448, 0x45ce, x86_l_45ce);
x86_l_444d:
	/* 0x444d: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4452:
	/* 0x4452: call   4650 <generic_kprobe_process_event+0x4650> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_4457:
	/* 0x4457: mov    ecx,0xfffffffe */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 4294967294ULL);
x86_l_445c:
	/* 0x445c: test   eax,eax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_445e:
	/* 0x445e: js     43b8 <generic_kprobe_process_event+0x43b8> */
	X86_SIM_X86_JCC(X86_CC_S, 0x445e, 0x43b8, x86_l_43b8);
x86_l_4464:
	/* 0x4464: jmp    44b6 <generic_kprobe_process_event+0x44b6> */
	X86_SIM_X86_JMP(0x4464, 0x44b6, x86_l_44b6);
x86_l_4466:
	/* 0x4466: mov    r15d,0xa */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 10ULL);
x86_l_446c:
	/* 0x446c: jmp    45ce <generic_kprobe_process_event+0x45ce> */
	X86_SIM_X86_JMP(0x446c, 0x45ce, x86_l_45ce);
x86_l_4471:
	/* 0x4471: mov    r15d,0xb */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 11ULL);
x86_l_4477:
	/* 0x4477: jmp    45ce <generic_kprobe_process_event+0x45ce> */
	X86_SIM_X86_JMP(0x4477, 0x45ce, x86_l_45ce);
x86_l_447c:
	/* 0x447c: mov    r15d,0xc */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 12ULL);
x86_l_4482:
	/* 0x4482: jmp    45ce <generic_kprobe_process_event+0x45ce> */
	X86_SIM_X86_JMP(0x4482, 0x45ce, x86_l_45ce);
x86_l_4487:
	/* 0x4487: mov    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_4489:
	/* 0x4489: mov    esi,DWORD PTR [rdx+rcx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_448c:
	/* 0x448c: mov    DWORD PTR [rdi+rcx*1],esi */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_448f:
	/* 0x448f: or     eax,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_OR, 4ULL);
x86_l_4492:
	/* 0x4492: test   BYTE PTR [rsp+0x30],0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430210ULL);
x86_l_4497:
	/* 0x4497: je     4439 <generic_kprobe_process_event+0x4439> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4497, 0x4439, x86_l_4439);
x86_l_4499:
	/* 0x4499: mov    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_449b:
	/* 0x449b: movzx  esi,WORD PTR [rdx+rcx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_16), 0ULL);
x86_l_449f:
	/* 0x449f: mov    WORD PTR [rdi+rcx*1],si */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RSI, X86_WIDTH_16, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_44a3:
	/* 0x44a3: add    eax,0x2 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_44a6:
	/* 0x44a6: test   BYTE PTR [rsp+0x30],0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430209ULL);
x86_l_44ab:
	/* 0x44ab: je     44b6 <generic_kprobe_process_event+0x44b6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x44ab, 0x44b6, x86_l_44b6);
x86_l_44ad:
	/* 0x44ad: mov    eax,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_44af:
	/* 0x44af: movzx  ecx,BYTE PTR [rdx+rax*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_44b3:
	/* 0x44b3: mov    BYTE PTR [rdi+rax*1],cl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_44b6:
	/* 0x44b6: add    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_RUN_OP(X86_OP_ALU_MEM, X86_R15, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 48ULL);
x86_l_44bb:
	/* 0x44bb: cmp    r12,0x3 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, 0, 3ULL);
x86_l_44bf:
	/* 0x44bf: jb     2f7f <generic_kprobe_process_event+0x2f7f> */
	X86_SIM_X86_JCC(X86_CC_B, 0x44bf, 0x2f7f, x86_l_2f7f);
x86_l_44c5:
	/* 0x44c5: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_44ca:
	/* 0x44ca: add    rdx,0x20 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_44ce:
	/* 0x44ce: js     4503 <generic_kprobe_process_event+0x4503> */
	X86_SIM_X86_JCC(X86_CC_S, 0x44ce, 0x4503, x86_l_4503);
x86_l_44d0:
	/* 0x44d0: lea    rdi,[rsp+0x70] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_44d5:
	/* 0x44d5: mov    esi,0x10 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 16ULL);
x86_l_44da:
	/* 0x44da: call   46df <generic_kprobe_process_event+0x46df> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_44df:
	/* 0x44df: mov    ecx,0xfffffffe */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 4294967294ULL);
x86_l_44e4:
	/* 0x44e4: test   eax,eax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_44e6:
	/* 0x44e6: js     43b8 <generic_kprobe_process_event+0x43b8> */
	X86_SIM_X86_JCC(X86_CC_S, 0x44e6, 0x43b8, x86_l_43b8);
x86_l_44ec:
	/* 0x44ec: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_44f1:
	/* 0x44f1: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_44f6:
	/* 0x44f6: jmp    452a <generic_kprobe_process_event+0x452a> */
	X86_SIM_X86_JMP(0x44f6, 0x452a, x86_l_452a);
x86_l_44f8:
	/* 0x44f8: mov    r15d,0xd */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 13ULL);
x86_l_44fe:
	/* 0x44fe: jmp    45ce <generic_kprobe_process_event+0x45ce> */
	X86_SIM_X86_JMP(0x44fe, 0x45ce, x86_l_45ce);
x86_l_4503:
	/* 0x4503: mov    ecx,0xfffffffe */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 4294967294ULL);
x86_l_4508:
	/* 0x4508: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_450b:
	/* 0x450b: jns    43b8 <generic_kprobe_process_event+0x43b8> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x450b, 0x43b8, x86_l_43b8);
x86_l_4511:
	/* 0x4511: mov    rax,QWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4514:
	/* 0x4514: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_4519:
	/* 0x4519: mov    rcx,QWORD PTR [rdx+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_451d:
	/* 0x451d: mov    rax,rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_4520:
	/* 0x4520: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4525:
	/* 0x4525: mov    QWORD PTR [rsp+0x78],rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_452a:
	/* 0x452a: mov    ecx,0xfffffffd */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 4294967293ULL);
x86_l_452f:
	/* 0x452f: cmp    QWORD PTR [rsp+0x8],0xffe */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359742462ULL);
x86_l_4538:
	/* 0x4538: ja     43b8 <generic_kprobe_process_event+0x43b8> */
	X86_SIM_X86_JCC(X86_CC_A, 0x4538, 0x43b8, x86_l_43b8);
x86_l_453e:
	/* 0x453e: mov    rdi,QWORD PTR [rsp+0x30] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4543:
	/* 0x4543: add    rdi,rbx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_4546:
	/* 0x4546: mov    rbx,rdi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RBX, X86_RDI, X86_WIDTH_64, 0, 0);
x86_l_4549:
	/* 0x4549: and    edi,0x3fff */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_454f:
	/* 0x454f: add    rdi,rbp */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_4552:
	/* 0x4552: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_4557:
	/* 0x4557: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_455a:
	/* 0x455a: jns    45af <generic_kprobe_process_event+0x45af> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x455a, 0x45af, x86_l_45af);
x86_l_455c:
	/* 0x455c: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_455f:
	/* 0x455f: jns    480c <generic_kprobe_process_event+0x480c> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x455f, 0x480c, x86_l_480c);
x86_l_4565:
	/* 0x4565: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_4567:
	/* 0x4567: cmp    DWORD PTR [rsp+0x8],0x8 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738376ULL);
x86_l_456c:
	/* 0x456c: jb     4588 <generic_kprobe_process_event+0x4588> */
	X86_SIM_X86_JCC(X86_CC_B, 0x456c, 0x4588, x86_l_4588);
x86_l_456e:
	/* 0x456e: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_4570:
	/* 0x4570: mov    eax,ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_4572:
	/* 0x4572: mov    rsi,QWORD PTR [rdx+rax*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_4576:
	/* 0x4576: mov    QWORD PTR [rdi+rax*1],rsi */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_457a:
	/* 0x457a: lea    eax,[rcx+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_457d:
	/* 0x457d: add    ecx,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 16ULL);
x86_l_4580:
	/* 0x4580: cmp    ecx,DWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_4584:
	/* 0x4584: mov    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_4586:
	/* 0x4586: jbe    4570 <generic_kprobe_process_event+0x4570> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x4586, 0x4570, x86_l_4570);
x86_l_4588:
	/* 0x4588: test   BYTE PTR [rsp+0x8],0x4 */
	X86_SIM_RUN_OP(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34359738372ULL);
x86_l_458d:
	/* 0x458d: jne    45dd <generic_kprobe_process_event+0x45dd> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x458d, 0x45dd, x86_l_45dd);
x86_l_458f:
	/* 0x458f: test   BYTE PTR [rsp+0x8],0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34359738370ULL);
x86_l_4594:
	/* 0x4594: jne    45ef <generic_kprobe_process_event+0x45ef> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4594, 0x45ef, x86_l_45ef);
x86_l_4596:
	/* 0x4596: test   BYTE PTR [rsp+0x8],0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_459b:
	/* 0x459b: jne    4603 <generic_kprobe_process_event+0x4603> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x459b, 0x4603, x86_l_4603);
x86_l_459d:
	/* 0x459d: jmp    460c <generic_kprobe_process_event+0x460c> */
	X86_SIM_X86_JMP(0x459d, 0x460c, x86_l_460c);
x86_l_459f:
	/* 0x459f: mov    r15d,0xe */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 14ULL);
x86_l_45a5:
	/* 0x45a5: jmp    45ce <generic_kprobe_process_event+0x45ce> */
	X86_SIM_X86_JMP(0x45a5, 0x45ce, x86_l_45ce);
x86_l_45a7:
	/* 0x45a7: mov    r15d,0xf */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 15ULL);
x86_l_45ad:
	/* 0x45ad: jmp    45ce <generic_kprobe_process_event+0x45ce> */
	X86_SIM_X86_JMP(0x45ad, 0x45ce, x86_l_45ce);
x86_l_45af:
	/* 0x45af: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_45b4:
	/* 0x45b4: call   47b2 <generic_kprobe_process_event+0x47b2> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_45b9:
	/* 0x45b9: mov    ecx,0xfffffffe */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 4294967294ULL);
x86_l_45be:
	/* 0x45be: test   eax,eax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_45c0:
	/* 0x45c0: js     43b8 <generic_kprobe_process_event+0x43b8> */
	X86_SIM_X86_JCC(X86_CC_S, 0x45c0, 0x43b8, x86_l_43b8);
x86_l_45c6:
	/* 0x45c6: jmp    460c <generic_kprobe_process_event+0x460c> */
	X86_SIM_X86_JMP(0x45c6, 0x460c, x86_l_460c);
x86_l_45c8:
	/* 0x45c8: mov    r15d,0x10 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 16ULL);
x86_l_45ce:
	/* 0x45ce: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_45d3:
	/* 0x45d3: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_45d8:
	/* 0x45d8: jmp    2431 <generic_kprobe_process_event+0x2431> */
	X86_SIM_X86_JMP(0x45d8, 0x2431, x86_l_2431);
x86_l_45dd:
	/* 0x45dd: mov    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_45df:
	/* 0x45df: mov    esi,DWORD PTR [rdx+rcx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_45e2:
	/* 0x45e2: mov    DWORD PTR [rdi+rcx*1],esi */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_45e5:
	/* 0x45e5: or     eax,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_OR, 4ULL);
x86_l_45e8:
	/* 0x45e8: test   BYTE PTR [rsp+0x8],0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34359738370ULL);
x86_l_45ed:
	/* 0x45ed: je     4596 <generic_kprobe_process_event+0x4596> */
	X86_SIM_X86_JCC(X86_CC_E, 0x45ed, 0x4596, x86_l_4596);
x86_l_45ef:
	/* 0x45ef: mov    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_45f1:
	/* 0x45f1: movzx  esi,WORD PTR [rdx+rcx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_16), 0ULL);
x86_l_45f5:
	/* 0x45f5: mov    WORD PTR [rdi+rcx*1],si */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RSI, X86_WIDTH_16, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_45f9:
	/* 0x45f9: add    eax,0x2 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_45fc:
	/* 0x45fc: test   BYTE PTR [rsp+0x8],0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_4601:
	/* 0x4601: je     460c <generic_kprobe_process_event+0x460c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4601, 0x460c, x86_l_460c);
x86_l_4603:
	/* 0x4603: mov    eax,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_4605:
	/* 0x4605: movzx  ecx,BYTE PTR [rdx+rax*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_4609:
	/* 0x4609: mov    BYTE PTR [rdi+rax*1],cl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_460c:
	/* 0x460c: add    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_ALU_MEM, X86_R15, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4611:
	/* 0x4611: cmp    r12,0x3 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, 0, 3ULL);
x86_l_4615:
	/* 0x4615: je     2f7f <generic_kprobe_process_event+0x2f7f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4615, 0x2f7f, x86_l_2f7f);
x86_l_461b:
	/* 0x461b: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4620:
	/* 0x4620: add    rdx,0x30 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_4624:
	/* 0x4624: js     464e <generic_kprobe_process_event+0x464e> */
	X86_SIM_X86_JCC(X86_CC_S, 0x4624, 0x464e, x86_l_464e);
x86_l_4626:
	/* 0x4626: lea    rdi,[rsp+0x70] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_462b:
	/* 0x462b: mov    esi,0x10 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 16ULL);
x86_l_4630:
	/* 0x4630: call   482e <generic_kprobe_process_event+0x482e> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_4635:
	/* 0x4635: mov    ecx,0xfffffffe */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 4294967294ULL);
x86_l_463a:
	/* 0x463a: test   eax,eax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_463c:
	/* 0x463c: js     43b8 <generic_kprobe_process_event+0x43b8> */
	X86_SIM_X86_JCC(X86_CC_S, 0x463c, 0x43b8, x86_l_43b8);
x86_l_4642:
	/* 0x4642: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_4647:
	/* 0x4647: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_464c:
	/* 0x464c: jmp    4675 <generic_kprobe_process_event+0x4675> */
	X86_SIM_X86_JMP(0x464c, 0x4675, x86_l_4675);
x86_l_464e:
	/* 0x464e: mov    ecx,0xfffffffe */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 4294967294ULL);
x86_l_4653:
	/* 0x4653: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_4656:
	/* 0x4656: jns    43b8 <generic_kprobe_process_event+0x43b8> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x4656, 0x43b8, x86_l_43b8);
x86_l_465c:
	/* 0x465c: mov    rax,QWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_465f:
	/* 0x465f: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_4664:
	/* 0x4664: mov    rcx,QWORD PTR [rdx+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4668:
	/* 0x4668: mov    rax,rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_466b:
	/* 0x466b: mov    QWORD PTR [rsp+0x30],rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4670:
	/* 0x4670: mov    QWORD PTR [rsp+0x78],rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_4675:
	/* 0x4675: mov    ecx,0xfffffffd */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 4294967293ULL);
x86_l_467a:
	/* 0x467a: cmp    QWORD PTR [rsp+0x30],0xffe */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158434302ULL);
x86_l_4683:
	/* 0x4683: ja     43b8 <generic_kprobe_process_event+0x43b8> */
	X86_SIM_X86_JCC(X86_CC_A, 0x4683, 0x43b8, x86_l_43b8);
x86_l_4689:
	/* 0x4689: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_468e:
	/* 0x468e: add    rdi,rbx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_4691:
	/* 0x4691: mov    rbx,rdi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RBX, X86_RDI, X86_WIDTH_64, 0, 0);
x86_l_4694:
	/* 0x4694: and    edi,0x3fff */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_469a:
	/* 0x469a: add    rdi,rbp */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_469d:
	/* 0x469d: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_46a2:
	/* 0x46a2: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_46a5:
	/* 0x46a5: jns    46ea <generic_kprobe_process_event+0x46ea> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x46a5, 0x46ea, x86_l_46ea);
x86_l_46a7:
	/* 0x46a7: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_46aa:
	/* 0x46aa: jns    493a <generic_kprobe_process_event+0x493a> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x46aa, 0x493a, x86_l_493a);
x86_l_46b0:
	/* 0x46b0: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_46b2:
	/* 0x46b2: cmp    DWORD PTR [rsp+0x30],0x8 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430216ULL);
x86_l_46b7:
	/* 0x46b7: jb     46d3 <generic_kprobe_process_event+0x46d3> */
	X86_SIM_X86_JCC(X86_CC_B, 0x46b7, 0x46d3, x86_l_46d3);
x86_l_46b9:
	/* 0x46b9: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_46bb:
	/* 0x46bb: mov    eax,ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_46bd:
	/* 0x46bd: mov    rsi,QWORD PTR [rdx+rax*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_46c1:
	/* 0x46c1: mov    QWORD PTR [rdi+rax*1],rsi */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_46c5:
	/* 0x46c5: lea    eax,[rcx+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_46c8:
	/* 0x46c8: add    ecx,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 16ULL);
x86_l_46cb:
	/* 0x46cb: cmp    ecx,DWORD PTR [rsp+0x30] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 48ULL);
x86_l_46cf:
	/* 0x46cf: mov    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_46d1:
	/* 0x46d1: jbe    46bb <generic_kprobe_process_event+0x46bb> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x46d1, 0x46bb, x86_l_46bb);
x86_l_46d3:
	/* 0x46d3: test   BYTE PTR [rsp+0x30],0x4 */
	X86_SIM_RUN_OP(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430212ULL);
x86_l_46d8:
	/* 0x46d8: jne    4703 <generic_kprobe_process_event+0x4703> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x46d8, 0x4703, x86_l_4703);
x86_l_46da:
	/* 0x46da: test   BYTE PTR [rsp+0x30],0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430210ULL);
x86_l_46df:
	/* 0x46df: jne    4715 <generic_kprobe_process_event+0x4715> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x46df, 0x4715, x86_l_4715);
x86_l_46e1:
	/* 0x46e1: test   BYTE PTR [rsp+0x30],0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430209ULL);
x86_l_46e6:
	/* 0x46e6: jne    4729 <generic_kprobe_process_event+0x4729> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x46e6, 0x4729, x86_l_4729);
x86_l_46e8:
	/* 0x46e8: jmp    4732 <generic_kprobe_process_event+0x4732> */
	X86_SIM_X86_JMP(0x46e8, 0x4732, x86_l_4732);
x86_l_46ea:
	/* 0x46ea: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_46ef:
	/* 0x46ef: call   48ed <generic_kprobe_process_event+0x48ed> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_46f4:
	/* 0x46f4: mov    ecx,0xfffffffe */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 4294967294ULL);
x86_l_46f9:
	/* 0x46f9: test   eax,eax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_46fb:
	/* 0x46fb: js     43b8 <generic_kprobe_process_event+0x43b8> */
	X86_SIM_X86_JCC(X86_CC_S, 0x46fb, 0x43b8, x86_l_43b8);
x86_l_4701:
	/* 0x4701: jmp    4732 <generic_kprobe_process_event+0x4732> */
	X86_SIM_X86_JMP(0x4701, 0x4732, x86_l_4732);
x86_l_4703:
	/* 0x4703: mov    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_4705:
	/* 0x4705: mov    esi,DWORD PTR [rdx+rcx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4708:
	/* 0x4708: mov    DWORD PTR [rdi+rcx*1],esi */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_470b:
	/* 0x470b: or     eax,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_OR, 4ULL);
x86_l_470e:
	/* 0x470e: test   BYTE PTR [rsp+0x30],0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430210ULL);
x86_l_4713:
	/* 0x4713: je     46e1 <generic_kprobe_process_event+0x46e1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4713, 0x46e1, x86_l_46e1);
x86_l_4715:
	/* 0x4715: mov    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_4717:
	/* 0x4717: movzx  esi,WORD PTR [rdx+rcx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_16), 0ULL);
x86_l_471b:
	/* 0x471b: mov    WORD PTR [rdi+rcx*1],si */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RSI, X86_WIDTH_16, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_471f:
	/* 0x471f: add    eax,0x2 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_4722:
	/* 0x4722: test   BYTE PTR [rsp+0x30],0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430209ULL);
x86_l_4727:
	/* 0x4727: je     4732 <generic_kprobe_process_event+0x4732> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4727, 0x4732, x86_l_4732);
x86_l_4729:
	/* 0x4729: mov    eax,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_472b:
	/* 0x472b: movzx  ecx,BYTE PTR [rdx+rax*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_472f:
	/* 0x472f: mov    BYTE PTR [rdi+rax*1],cl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_4732:
	/* 0x4732: add    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_RUN_OP(X86_OP_ALU_MEM, X86_R15, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 48ULL);
x86_l_4737:
	/* 0x4737: cmp    r12,0x5 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, 0, 5ULL);
x86_l_473b:
	/* 0x473b: jb     2f7f <generic_kprobe_process_event+0x2f7f> */
	X86_SIM_X86_JCC(X86_CC_B, 0x473b, 0x2f7f, x86_l_2f7f);
x86_l_4741:
	/* 0x4741: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4746:
	/* 0x4746: add    rdx,0x40 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 64ULL);
x86_l_474a:
	/* 0x474a: js     4774 <generic_kprobe_process_event+0x4774> */
	X86_SIM_X86_JCC(X86_CC_S, 0x474a, 0x4774, x86_l_4774);
x86_l_474c:
	/* 0x474c: lea    rdi,[rsp+0x70] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_4751:
	/* 0x4751: mov    esi,0x10 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 16ULL);
x86_l_4756:
	/* 0x4756: call   4954 <generic_kprobe_process_event+0x4954> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_475b:
	/* 0x475b: mov    ecx,0xfffffffe */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 4294967294ULL);
x86_l_4760:
	/* 0x4760: test   eax,eax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_4762:
	/* 0x4762: js     43b8 <generic_kprobe_process_event+0x43b8> */
	X86_SIM_X86_JCC(X86_CC_S, 0x4762, 0x43b8, x86_l_43b8);
x86_l_4768:
	/* 0x4768: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_476d:
	/* 0x476d: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4772:
	/* 0x4772: jmp    479b <generic_kprobe_process_event+0x479b> */
	X86_SIM_X86_JMP(0x4772, 0x479b, x86_l_479b);
x86_l_4774:
	/* 0x4774: mov    ecx,0xfffffffe */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 4294967294ULL);
x86_l_4779:
	/* 0x4779: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_477c:
	/* 0x477c: jns    43b8 <generic_kprobe_process_event+0x43b8> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x477c, 0x43b8, x86_l_43b8);
x86_l_4782:
	/* 0x4782: mov    rax,QWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4785:
	/* 0x4785: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_478a:
	/* 0x478a: mov    rcx,QWORD PTR [rdx+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_478e:
	/* 0x478e: mov    rax,rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_4791:
	/* 0x4791: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4796:
	/* 0x4796: mov    QWORD PTR [rsp+0x78],rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_479b:
	/* 0x479b: mov    ecx,0xfffffffd */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 4294967293ULL);
x86_l_47a0:
	/* 0x47a0: cmp    QWORD PTR [rsp+0x8],0xffe */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359742462ULL);
x86_l_47a9:
	/* 0x47a9: ja     43b8 <generic_kprobe_process_event+0x43b8> */
	X86_SIM_X86_JCC(X86_CC_A, 0x47a9, 0x43b8, x86_l_43b8);
x86_l_47af:
	/* 0x47af: mov    rdi,QWORD PTR [rsp+0x30] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_47b4:
	/* 0x47b4: add    rdi,rbx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_47b7:
	/* 0x47b7: mov    rbx,rdi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RBX, X86_RDI, X86_WIDTH_64, 0, 0);
x86_l_47ba:
	/* 0x47ba: and    edi,0x3fff */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_47c0:
	/* 0x47c0: add    rdi,rbp */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_47c3:
	/* 0x47c3: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_47c8:
	/* 0x47c8: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_47cb:
	/* 0x47cb: jns    4818 <generic_kprobe_process_event+0x4818> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x47cb, 0x4818, x86_l_4818);
x86_l_47cd:
	/* 0x47cd: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_47d0:
	/* 0x47d0: jns    480c <generic_kprobe_process_event+0x480c> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x47d0, 0x480c, x86_l_480c);
x86_l_47d2:
	/* 0x47d2: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_47d4:
	/* 0x47d4: cmp    DWORD PTR [rsp+0x8],0x8 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738376ULL);
x86_l_47d9:
	/* 0x47d9: jb     47f5 <generic_kprobe_process_event+0x47f5> */
	X86_SIM_X86_JCC(X86_CC_B, 0x47d9, 0x47f5, x86_l_47f5);
x86_l_47db:
	/* 0x47db: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_47dd:
	/* 0x47dd: mov    eax,ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_47df:
	/* 0x47df: mov    rsi,QWORD PTR [rdx+rax*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_47e3:
	/* 0x47e3: mov    QWORD PTR [rdi+rax*1],rsi */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_47e7:
	/* 0x47e7: lea    eax,[rcx+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_47ea:
	/* 0x47ea: add    ecx,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 16ULL);
x86_l_47ed:
	/* 0x47ed: cmp    ecx,DWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_47f1:
	/* 0x47f1: mov    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_47f3:
	/* 0x47f3: jbe    47dd <generic_kprobe_process_event+0x47dd> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x47f3, 0x47dd, x86_l_47dd);
x86_l_47f5:
	/* 0x47f5: test   BYTE PTR [rsp+0x8],0x4 */
	X86_SIM_RUN_OP(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34359738372ULL);
x86_l_47fa:
	/* 0x47fa: jne    4831 <generic_kprobe_process_event+0x4831> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x47fa, 0x4831, x86_l_4831);
x86_l_47fc:
	/* 0x47fc: test   BYTE PTR [rsp+0x8],0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34359738370ULL);
x86_l_4801:
	/* 0x4801: jne    4843 <generic_kprobe_process_event+0x4843> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4801, 0x4843, x86_l_4843);
x86_l_4803:
	/* 0x4803: test   BYTE PTR [rsp+0x8],0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_4808:
	/* 0x4808: jne    4857 <generic_kprobe_process_event+0x4857> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4808, 0x4857, x86_l_4857);
x86_l_480a:
	/* 0x480a: jmp    4860 <generic_kprobe_process_event+0x4860> */
	X86_SIM_X86_JMP(0x480a, 0x4860, x86_l_4860);
x86_l_480c:
	/* 0x480c: xor    esi,esi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_480e:
	/* 0x480e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4813:
	/* 0x4813: jmp    42e9 <generic_kprobe_process_event+0x42e9> */
	X86_SIM_X86_JMP(0x4813, 0x42e9, x86_l_42e9);
x86_l_4818:
	/* 0x4818: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_481d:
	/* 0x481d: call   4a22 <generic_kprobe_process_event+0x4a22> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_4822:
	/* 0x4822: mov    ecx,0xfffffffe */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 4294967294ULL);
x86_l_4827:
	/* 0x4827: test   eax,eax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_4829:
	/* 0x4829: js     43b8 <generic_kprobe_process_event+0x43b8> */
	X86_SIM_X86_JCC(X86_CC_S, 0x4829, 0x43b8, x86_l_43b8);
x86_l_482f:
	/* 0x482f: jmp    4860 <generic_kprobe_process_event+0x4860> */
	X86_SIM_X86_JMP(0x482f, 0x4860, x86_l_4860);
x86_l_4831:
	/* 0x4831: mov    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_4833:
	/* 0x4833: mov    esi,DWORD PTR [rdx+rcx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4836:
	/* 0x4836: mov    DWORD PTR [rdi+rcx*1],esi */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4839:
	/* 0x4839: or     eax,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_OR, 4ULL);
x86_l_483c:
	/* 0x483c: test   BYTE PTR [rsp+0x8],0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34359738370ULL);
x86_l_4841:
	/* 0x4841: je     4803 <generic_kprobe_process_event+0x4803> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4841, 0x4803, x86_l_4803);
x86_l_4843:
	/* 0x4843: mov    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_4845:
	/* 0x4845: movzx  esi,WORD PTR [rdx+rcx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_16), 0ULL);
x86_l_4849:
	/* 0x4849: mov    WORD PTR [rdi+rcx*1],si */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RSI, X86_WIDTH_16, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_484d:
	/* 0x484d: add    eax,0x2 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_4850:
	/* 0x4850: test   BYTE PTR [rsp+0x8],0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_4855:
	/* 0x4855: je     4860 <generic_kprobe_process_event+0x4860> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4855, 0x4860, x86_l_4860);
x86_l_4857:
	/* 0x4857: mov    eax,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_4859:
	/* 0x4859: movzx  ecx,BYTE PTR [rdx+rax*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_485d:
	/* 0x485d: mov    BYTE PTR [rdi+rax*1],cl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_4860:
	/* 0x4860: add    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_ALU_MEM, X86_R15, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4865:
	/* 0x4865: cmp    r12,0x5 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, 0, 5ULL);
x86_l_4869:
	/* 0x4869: je     2f7f <generic_kprobe_process_event+0x2f7f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4869, 0x2f7f, x86_l_2f7f);
x86_l_486f:
	/* 0x486f: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4874:
	/* 0x4874: add    rdx,0x50 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_4878:
	/* 0x4878: js     48a2 <generic_kprobe_process_event+0x48a2> */
	X86_SIM_X86_JCC(X86_CC_S, 0x4878, 0x48a2, x86_l_48a2);
x86_l_487a:
	/* 0x487a: lea    rdi,[rsp+0x70] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_487f:
	/* 0x487f: mov    esi,0x10 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 16ULL);
x86_l_4884:
	/* 0x4884: call   4a82 <generic_kprobe_process_event+0x4a82> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_4889:
	/* 0x4889: mov    ecx,0xfffffffe */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 4294967294ULL);
x86_l_488e:
	/* 0x488e: test   eax,eax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_4890:
	/* 0x4890: js     43b8 <generic_kprobe_process_event+0x43b8> */
	X86_SIM_X86_JCC(X86_CC_S, 0x4890, 0x43b8, x86_l_43b8);
x86_l_4896:
	/* 0x4896: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_489b:
	/* 0x489b: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_48a0:
	/* 0x48a0: jmp    48c9 <generic_kprobe_process_event+0x48c9> */
	X86_SIM_X86_JMP(0x48a0, 0x48c9, x86_l_48c9);
x86_l_48a2:
	/* 0x48a2: mov    ecx,0xfffffffe */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 4294967294ULL);
x86_l_48a7:
	/* 0x48a7: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_48aa:
	/* 0x48aa: jns    43b8 <generic_kprobe_process_event+0x43b8> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x48aa, 0x43b8, x86_l_43b8);
x86_l_48b0:
	/* 0x48b0: mov    rax,QWORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_48b3:
	/* 0x48b3: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_48b8:
	/* 0x48b8: mov    rcx,QWORD PTR [rdx+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_48bc:
	/* 0x48bc: mov    rax,rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_48bf:
	/* 0x48bf: mov    QWORD PTR [rsp+0x30],rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_48c4:
	/* 0x48c4: mov    QWORD PTR [rsp+0x78],rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_48c9:
	/* 0x48c9: mov    ecx,0xfffffffd */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 4294967293ULL);
x86_l_48ce:
	/* 0x48ce: cmp    QWORD PTR [rsp+0x30],0xffe */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158434302ULL);
x86_l_48d7:
	/* 0x48d7: ja     43b8 <generic_kprobe_process_event+0x43b8> */
	X86_SIM_X86_JCC(X86_CC_A, 0x48d7, 0x43b8, x86_l_43b8);
x86_l_48dd:
	/* 0x48dd: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_48e2:
	/* 0x48e2: add    rdi,rbx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_48e5:
	/* 0x48e5: mov    rbx,rdi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RBX, X86_RDI, X86_WIDTH_64, 0, 0);
x86_l_48e8:
	/* 0x48e8: and    edi,0x3fff */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_48ee:
	/* 0x48ee: add    rdi,rbp */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_48f1:
	/* 0x48f1: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_48f6:
	/* 0x48f6: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_48f9:
	/* 0x48f9: jns    4946 <generic_kprobe_process_event+0x4946> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x48f9, 0x4946, x86_l_4946);
x86_l_48fb:
	/* 0x48fb: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_48fe:
	/* 0x48fe: jns    493a <generic_kprobe_process_event+0x493a> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x48fe, 0x493a, x86_l_493a);
x86_l_4900:
	/* 0x4900: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_4902:
	/* 0x4902: cmp    DWORD PTR [rsp+0x30],0x8 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430216ULL);
x86_l_4907:
	/* 0x4907: jb     4923 <generic_kprobe_process_event+0x4923> */
	X86_SIM_X86_JCC(X86_CC_B, 0x4907, 0x4923, x86_l_4923);
x86_l_4909:
	/* 0x4909: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_490b:
	/* 0x490b: mov    eax,ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_490d:
	/* 0x490d: mov    rsi,QWORD PTR [rdx+rax*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_4911:
	/* 0x4911: mov    QWORD PTR [rdi+rax*1],rsi */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_4915:
	/* 0x4915: lea    eax,[rcx+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4918:
	/* 0x4918: add    ecx,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 16ULL);
x86_l_491b:
	/* 0x491b: cmp    ecx,DWORD PTR [rsp+0x30] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 48ULL);
x86_l_491f:
	/* 0x491f: mov    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_4921:
	/* 0x4921: jbe    490b <generic_kprobe_process_event+0x490b> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x4921, 0x490b, x86_l_490b);
x86_l_4923:
	/* 0x4923: test   BYTE PTR [rsp+0x30],0x4 */
	X86_SIM_RUN_OP(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430212ULL);
x86_l_4928:
	/* 0x4928: jne    495f <generic_kprobe_process_event+0x495f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4928, 0x495f, x86_l_495f);
x86_l_492a:
	/* 0x492a: test   BYTE PTR [rsp+0x30],0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430210ULL);
x86_l_492f:
	/* 0x492f: jne    4971 <generic_kprobe_process_event+0x4971> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x492f, 0x4971, x86_l_4971);
x86_l_4931:
	/* 0x4931: test   BYTE PTR [rsp+0x30],0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430209ULL);
x86_l_4936:
	/* 0x4936: jne    4985 <generic_kprobe_process_event+0x4985> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4936, 0x4985, x86_l_4985);
x86_l_4938:
	/* 0x4938: jmp    498e <generic_kprobe_process_event+0x498e> */
	X86_SIM_X86_JMP(0x4938, 0x498e, x86_l_498e);
x86_l_493a:
	/* 0x493a: xor    esi,esi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_493c:
	/* 0x493c: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4941:
	/* 0x4941: jmp    42e9 <generic_kprobe_process_event+0x42e9> */
	X86_SIM_X86_JMP(0x4941, 0x42e9, x86_l_42e9);
x86_l_4946:
	/* 0x4946: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_494b:
	/* 0x494b: call   4b49 <data_event_bytes+0x6> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_4950:
	/* 0x4950: mov    ecx,0xfffffffe */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 4294967294ULL);
x86_l_4955:
	/* 0x4955: test   eax,eax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_4957:
	/* 0x4957: js     43b8 <generic_kprobe_process_event+0x43b8> */
	X86_SIM_X86_JCC(X86_CC_S, 0x4957, 0x43b8, x86_l_43b8);
x86_l_495d:
	/* 0x495d: jmp    498e <generic_kprobe_process_event+0x498e> */
	X86_SIM_X86_JMP(0x495d, 0x498e, x86_l_498e);
x86_l_495f:
	/* 0x495f: mov    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_4961:
	/* 0x4961: mov    esi,DWORD PTR [rdx+rcx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4964:
	/* 0x4964: mov    DWORD PTR [rdi+rcx*1],esi */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4967:
	/* 0x4967: or     eax,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_OR, 4ULL);
x86_l_496a:
	/* 0x496a: test   BYTE PTR [rsp+0x30],0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430210ULL);
x86_l_496f:
	/* 0x496f: je     4931 <generic_kprobe_process_event+0x4931> */
	X86_SIM_X86_JCC(X86_CC_E, 0x496f, 0x4931, x86_l_4931);
x86_l_4971:
	/* 0x4971: mov    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_4973:
	/* 0x4973: movzx  esi,WORD PTR [rdx+rcx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_16), 0ULL);
x86_l_4977:
	/* 0x4977: mov    WORD PTR [rdi+rcx*1],si */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RSI, X86_WIDTH_16, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_497b:
	/* 0x497b: add    eax,0x2 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_497e:
	/* 0x497e: test   BYTE PTR [rsp+0x30],0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430209ULL);
x86_l_4983:
	/* 0x4983: je     498e <generic_kprobe_process_event+0x498e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4983, 0x498e, x86_l_498e);
x86_l_4985:
	/* 0x4985: mov    eax,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_4987:
	/* 0x4987: movzx  ecx,BYTE PTR [rdx+rax*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_498b:
	/* 0x498b: mov    BYTE PTR [rdi+rax*1],cl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_498e:
	/* 0x498e: add    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_RUN_OP(X86_OP_ALU_MEM, X86_R15, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 48ULL);
x86_l_4993:
	/* 0x4993: cmp    r12,0x7 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, 0, 7ULL);
x86_l_4997:
	/* 0x4997: jb     2f7f <generic_kprobe_process_event+0x2f7f> */
	X86_SIM_X86_JCC(X86_CC_B, 0x4997, 0x2f7f, x86_l_2f7f);
x86_l_499d:
	/* 0x499d: add    QWORD PTR [rsp+0x28],0x60 */
	X86_SIM_RUN_OP(X86_OP_ALU_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 171798691936ULL);
x86_l_49a3:
	/* 0x49a3: js     49cd <generic_kprobe_process_event+0x49cd> */
	X86_SIM_X86_JCC(X86_CC_S, 0x49a3, 0x49cd, x86_l_49cd);
x86_l_49a5:
	/* 0x49a5: lea    rdi,[rsp+0x70] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_49aa:
	/* 0x49aa: mov    esi,0x10 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 16ULL);
x86_l_49af:
	/* 0x49af: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_49b4:
	/* 0x49b4: call   4bb2 <data_event_bytes+0x6f> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_49b9:
	/* 0x49b9: mov    ecx,0xfffffffe */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 4294967294ULL);
x86_l_49be:
	/* 0x49be: test   eax,eax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_49c0:
	/* 0x49c0: js     43b8 <generic_kprobe_process_event+0x43b8> */
	X86_SIM_X86_JCC(X86_CC_S, 0x49c0, 0x43b8, x86_l_43b8);
x86_l_49c6:
	/* 0x49c6: mov    r12,QWORD PTR [rsp+0x78] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_49cb:
	/* 0x49cb: jmp    49f7 <generic_kprobe_process_event+0x49f7> */
	X86_SIM_X86_JMP(0x49cb, 0x49f7, x86_l_49f7);
x86_l_49cd:
	/* 0x49cd: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_49d2:
	/* 0x49d2: mov    ecx,0xfffffffe */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 4294967294ULL);
x86_l_49d7:
	/* 0x49d7: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_49da:
	/* 0x49da: jns    43b8 <generic_kprobe_process_event+0x43b8> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x49da, 0x43b8, x86_l_43b8);
x86_l_49e0:
	/* 0x49e0: mov    rax,rdx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_49e3:
	/* 0x49e3: mov    rcx,rdx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_49e6:
	/* 0x49e6: mov    rax,QWORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_49e9:
	/* 0x49e9: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_49ee:
	/* 0x49ee: mov    r12,QWORD PTR [rdx+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R12, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_49f2:
	/* 0x49f2: mov    QWORD PTR [rsp+0x78],r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_49f7:
	/* 0x49f7: mov    ecx,0xfffffffd */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 4294967293ULL);
x86_l_49fc:
	/* 0x49fc: cmp    r12,0xffe */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, 0, 4094ULL);
x86_l_4a03:
	/* 0x4a03: ja     43b8 <generic_kprobe_process_event+0x43b8> */
	X86_SIM_X86_JCC(X86_CC_A, 0x4a03, 0x43b8, x86_l_43b8);
x86_l_4a09:
	/* 0x4a09: mov    rdi,QWORD PTR [rsp+0x30] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4a0e:
	/* 0x4a0e: add    rdi,rbx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_4a11:
	/* 0x4a11: and    edi,0x3fff */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_4a17:
	/* 0x4a17: add    rdi,rbp */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_4a1a:
	/* 0x4a1a: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_4a1f:
	/* 0x4a1f: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_4a22:
	/* 0x4a22: jns    4a5e <generic_kprobe_process_event+0x4a5e> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x4a22, 0x4a5e, x86_l_4a5e);
x86_l_4a24:
	/* 0x4a24: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_4a27:
	/* 0x4a27: jns    4a75 <generic_kprobe_process_event+0x4a75> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x4a27, 0x4a75, x86_l_4a75);
x86_l_4a29:
	/* 0x4a29: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_4a2b:
	/* 0x4a2b: cmp    r12d,0x8 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_4a2f:
	/* 0x4a2f: jb     4a4a <generic_kprobe_process_event+0x4a4a> */
	X86_SIM_X86_JCC(X86_CC_B, 0x4a2f, 0x4a4a, x86_l_4a4a);
x86_l_4a31:
	/* 0x4a31: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_4a33:
	/* 0x4a33: mov    eax,ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_4a35:
	/* 0x4a35: mov    rsi,QWORD PTR [rdx+rax*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_4a39:
	/* 0x4a39: mov    QWORD PTR [rdi+rax*1],rsi */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_4a3d:
	/* 0x4a3d: lea    eax,[rcx+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4a40:
	/* 0x4a40: add    ecx,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 16ULL);
x86_l_4a43:
	/* 0x4a43: cmp    ecx,r12d */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RCX, X86_R12, X86_WIDTH_32, 0, 0);
x86_l_4a46:
	/* 0x4a46: mov    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_4a48:
	/* 0x4a48: jbe    4a33 <generic_kprobe_process_event+0x4a33> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x4a48, 0x4a33, x86_l_4a33);
x86_l_4a4a:
	/* 0x4a4a: test   r12b,0x4 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, 0, 4ULL);
x86_l_4a4e:
	/* 0x4a4e: jne    4a7f <generic_kprobe_process_event+0x4a7f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4a4e, 0x4a7f, x86_l_4a7f);
x86_l_4a50:
	/* 0x4a50: test   r12b,0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, 0, 2ULL);
x86_l_4a54:
	/* 0x4a54: jne    4a90 <generic_kprobe_process_event+0x4a90> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4a54, 0x4a90, x86_l_4a90);
x86_l_4a56:
	/* 0x4a56: test   r12b,0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_4a5a:
	/* 0x4a5a: jne    4aa3 <generic_kprobe_process_event+0x4aa3> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4a5a, 0x4aa3, x86_l_4aa3);
x86_l_4a5c:
	/* 0x4a5c: jmp    4aac <generic_kprobe_process_event+0x4aac> */
	X86_SIM_X86_JMP(0x4a5c, 0x4aac, x86_l_4aac);
x86_l_4a5e:
	/* 0x4a5e: mov    esi,r12d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_R12, X86_WIDTH_32, 0, 0);
x86_l_4a61:
	/* 0x4a61: call   4c5f <do_bytes+0x4c> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_4a66:
	/* 0x4a66: mov    ecx,0xfffffffe */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 4294967294ULL);
x86_l_4a6b:
	/* 0x4a6b: test   eax,eax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_4a6d:
	/* 0x4a6d: js     43b8 <generic_kprobe_process_event+0x43b8> */
	X86_SIM_X86_JCC(X86_CC_S, 0x4a6d, 0x43b8, x86_l_43b8);
x86_l_4a73:
	/* 0x4a73: jmp    4aac <generic_kprobe_process_event+0x4aac> */
	X86_SIM_X86_JMP(0x4a73, 0x4aac, x86_l_4aac);
x86_l_4a75:
	/* 0x4a75: xor    esi,esi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_4a77:
	/* 0x4a77: mov    rdx,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_4a7a:
	/* 0x4a7a: jmp    42e9 <generic_kprobe_process_event+0x42e9> */
	X86_SIM_X86_JMP(0x4a7a, 0x42e9, x86_l_42e9);
x86_l_4a7f:
	/* 0x4a7f: mov    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_4a81:
	/* 0x4a81: mov    esi,DWORD PTR [rdx+rcx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4a84:
	/* 0x4a84: mov    DWORD PTR [rdi+rcx*1],esi */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4a87:
	/* 0x4a87: or     eax,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_OR, 4ULL);
x86_l_4a8a:
	/* 0x4a8a: test   r12b,0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, 0, 2ULL);
x86_l_4a8e:
	/* 0x4a8e: je     4a56 <generic_kprobe_process_event+0x4a56> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4a8e, 0x4a56, x86_l_4a56);
x86_l_4a90:
	/* 0x4a90: mov    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_4a92:
	/* 0x4a92: movzx  esi,WORD PTR [rdx+rcx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_16), 0ULL);
x86_l_4a96:
	/* 0x4a96: mov    WORD PTR [rdi+rcx*1],si */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RSI, X86_WIDTH_16, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4a9a:
	/* 0x4a9a: add    eax,0x2 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_4a9d:
	/* 0x4a9d: test   r12b,0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_4aa1:
	/* 0x4aa1: je     4aac <generic_kprobe_process_event+0x4aac> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4aa1, 0x4aac, x86_l_4aac);
x86_l_4aa3:
	/* 0x4aa3: mov    eax,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_4aa5:
	/* 0x4aa5: movzx  ecx,BYTE PTR [rdx+rax*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_4aa9:
	/* 0x4aa9: mov    BYTE PTR [rdi+rax*1],cl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_4aac:
	/* 0x4aac: add    r15,r12 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R15, X86_R12, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_4aaf:
	/* 0x4aaf: jmp    2f7f <generic_kprobe_process_event+0x2f7f> */
	X86_SIM_X86_JMP(0x4aaf, 0x2f7f, x86_l_2f7f);
x86_l_5040:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
	/* native subroutine native_link_sub_4ab4 */
x86_l_4ab4:
	/* 0x4ab4: rorx   ecx,esi,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RCX, X86_RSI, X86_WIDTH_32, 0, 3ULL);
x86_l_4aba:
	/* 0x4aba: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_4abc:
	/* 0x4abc: cmp    ecx,0x13 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 19ULL);
x86_l_4abf:
	/* 0x4abf: ja     4b42 <read_reg+0x8e> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x4abf, 0x4b42, x86_l_4b42);
x86_l_4ac5:
	/* Capture image-bound code identity before scheduled instructions. */
	switch (X86_SIM_L_READ_REG(X86_RCX) << 2) {
	case 0ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x4b36ULL); break;
	case 4ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x4ad5ULL); break;
	case 8ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x4b05ULL); break;
	case 12ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x4affULL); break;
	case 16ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x4ae7ULL); break;
	case 20ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x4af3ULL); break;
	case 24ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x4b0bULL); break;
	case 28ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x4b11ULL); break;
	case 32ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x4b29ULL); break;
	case 36ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x4b23ULL); break;
	case 40ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x4ae1ULL); break;
	case 44ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x4af9ULL); break;
	case 48ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x4aedULL); break;
	case 52ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x4adbULL); break;
	case 56ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x4b17ULL); break;
	case 60ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x4b42ULL); break;
	case 64ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x4b1dULL); break;
	case 68ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x4b42ULL); break;
	case 72ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x4b42ULL); break;
	case 76ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x4b2fULL); break;
	default: __x86_sim_unresolved_indirect_target();
	}
x86_l_4ad3:
	/* 0x4ad3: jmp    rcx */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RCX);
		switch (X86_SIM_L_REG_TAG(X86_RCX)) {
		case X86_SIM_TAG_CODE:
			switch (__x86_target) {
			case 0x4ad5ULL: goto x86_l_4ad5;
			case 0x4adbULL: goto x86_l_4adb;
			case 0x4ae1ULL: goto x86_l_4ae1;
			case 0x4ae7ULL: goto x86_l_4ae7;
			case 0x4aedULL: goto x86_l_4aed;
			case 0x4af3ULL: goto x86_l_4af3;
			case 0x4af9ULL: goto x86_l_4af9;
			case 0x4affULL: goto x86_l_4aff;
			case 0x4b05ULL: goto x86_l_4b05;
			case 0x4b0bULL: goto x86_l_4b0b;
			case 0x4b11ULL: goto x86_l_4b11;
			case 0x4b17ULL: goto x86_l_4b17;
			case 0x4b1dULL: goto x86_l_4b1d;
			case 0x4b23ULL: goto x86_l_4b23;
			case 0x4b29ULL: goto x86_l_4b29;
			case 0x4b2fULL: goto x86_l_4b2f;
			case 0x4b36ULL: goto x86_l_4b36;
			case 0x4b42ULL: goto x86_l_4b42;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_4ad5:
	/* 0x4ad5: add    rdi,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4ad9:
	/* 0x4ad9: jmp    4b36 <read_reg+0x82> */
	X86_SIM_X86_SUB_JMP(0x4ad9, 0x4b36, x86_l_4b36);
x86_l_4adb:
	/* 0x4adb: add    rdi,0x68 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 104ULL);
x86_l_4adf:
	/* 0x4adf: jmp    4b36 <read_reg+0x82> */
	X86_SIM_X86_SUB_JMP(0x4adf, 0x4b36, x86_l_4b36);
x86_l_4ae1:
	/* 0x4ae1: add    rdi,0x50 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_4ae5:
	/* 0x4ae5: jmp    4b36 <read_reg+0x82> */
	X86_SIM_X86_SUB_JMP(0x4ae5, 0x4b36, x86_l_4b36);
x86_l_4ae7:
	/* 0x4ae7: add    rdi,0x20 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_4aeb:
	/* 0x4aeb: jmp    4b36 <read_reg+0x82> */
	X86_SIM_X86_SUB_JMP(0x4aeb, 0x4b36, x86_l_4b36);
x86_l_4aed:
	/* 0x4aed: add    rdi,0x60 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 96ULL);
x86_l_4af1:
	/* 0x4af1: jmp    4b36 <read_reg+0x82> */
	X86_SIM_X86_SUB_JMP(0x4af1, 0x4b36, x86_l_4b36);
x86_l_4af3:
	/* 0x4af3: add    rdi,0x28 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_4af7:
	/* 0x4af7: jmp    4b36 <read_reg+0x82> */
	X86_SIM_X86_SUB_JMP(0x4af7, 0x4b36, x86_l_4b36);
x86_l_4af9:
	/* 0x4af9: add    rdi,0x58 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 88ULL);
x86_l_4afd:
	/* 0x4afd: jmp    4b36 <read_reg+0x82> */
	X86_SIM_X86_SUB_JMP(0x4afd, 0x4b36, x86_l_4b36);
x86_l_4aff:
	/* 0x4aff: add    rdi,0x18 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_4b03:
	/* 0x4b03: jmp    4b36 <read_reg+0x82> */
	X86_SIM_X86_SUB_JMP(0x4b03, 0x4b36, x86_l_4b36);
x86_l_4b05:
	/* 0x4b05: add    rdi,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4b09:
	/* 0x4b09: jmp    4b36 <read_reg+0x82> */
	X86_SIM_X86_SUB_JMP(0x4b09, 0x4b36, x86_l_4b36);
x86_l_4b0b:
	/* 0x4b0b: add    rdi,0x30 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_4b0f:
	/* 0x4b0f: jmp    4b36 <read_reg+0x82> */
	X86_SIM_X86_SUB_JMP(0x4b0f, 0x4b36, x86_l_4b36);
x86_l_4b11:
	/* 0x4b11: add    rdi,0x38 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 56ULL);
x86_l_4b15:
	/* 0x4b15: jmp    4b36 <read_reg+0x82> */
	X86_SIM_X86_SUB_JMP(0x4b15, 0x4b36, x86_l_4b36);
x86_l_4b17:
	/* 0x4b17: add    rdi,0x70 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 112ULL);
x86_l_4b1b:
	/* 0x4b1b: jmp    4b36 <read_reg+0x82> */
	X86_SIM_X86_SUB_JMP(0x4b1b, 0x4b36, x86_l_4b36);
x86_l_4b1d:
	/* 0x4b1d: sub    rdi,0xffffffffffffff80 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SUB, 18446744073709551488ULL);
x86_l_4b21:
	/* 0x4b21: jmp    4b36 <read_reg+0x82> */
	X86_SIM_X86_SUB_JMP(0x4b21, 0x4b36, x86_l_4b36);
x86_l_4b23:
	/* 0x4b23: add    rdi,0x48 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 72ULL);
x86_l_4b27:
	/* 0x4b27: jmp    4b36 <read_reg+0x82> */
	X86_SIM_X86_SUB_JMP(0x4b27, 0x4b36, x86_l_4b36);
x86_l_4b29:
	/* 0x4b29: add    rdi,0x40 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 64ULL);
x86_l_4b2d:
	/* 0x4b2d: jmp    4b36 <read_reg+0x82> */
	X86_SIM_X86_SUB_JMP(0x4b2d, 0x4b36, x86_l_4b36);
x86_l_4b2f:
	/* 0x4b2f: add    rdi,0x98 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 152ULL);
x86_l_4b36:
	/* 0x4b36: mov    eax,0x40 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 64ULL);
x86_l_4b3b:
	/* 0x4b3b: sub    eax,edx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_ALU_SUB, 0);
x86_l_4b3d:
	/* 0x4b3d: bzhi   rax,QWORD PTR [rdi],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RAX, X86_RDI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_4b42:
	/* 0x4b42: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_4b42);

	/* native subroutine native_link_sub_4b43 */
x86_l_4b43:
	/* 0x4b43: push   rbp */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_4b44:
	/* 0x4b44: push   r15 */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_4b46:
	/* 0x4b46: push   r14 */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_4b48:
	/* 0x4b48: push   r13 */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_4b4a:
	/* 0x4b4a: push   r12 */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_4b4c:
	/* 0x4b4c: push   rbx */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_4b4d:
	/* 0x4b4d: push   rax */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_4b4e:
	/* 0x4b4e: mov    r14,rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R14, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_4b51:
	/* 0x4b51: mov    r15,rdx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R15, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_4b54:
	/* 0x4b54: mov    rbx,rsi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RBX, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_4b57:
	/* 0x4b57: mov    r12,rdi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R12, X86_RDI, X86_WIDTH_64, 0, 0);
x86_l_4b5a:
	/* 0x4b5a: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_4b62:
	/* 0x4b62: mov    rdi,QWORD PTR [rip+0x90] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)data_heap));
x86_l_4b69:
	/* 0x4b69: lea    rsi,[rsp+0x4] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4b6e:
	/* 0x4b6e: call   4c03 <data_event_bytes+0xc0> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_4b73:
	/* 0x4b73: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_4b76:
	/* 0x4b76: je     4c02 <data_event_bytes+0xbf> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x4b76, 0x4c02, x86_l_4c02);
x86_l_4b7c:
	/* 0x4b7c: mov    r13,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R13, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_4b7f:
	/* 0x4b7f: mov    DWORD PTR [rax],0x18 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4b85:
	/* 0x4b85: call   4c1a <do_bytes+0x7> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_get_current_pid_tgid);
x86_l_4b8a:
	/* 0x4b8a: mov    rbp,r13 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RBP, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_4b8d:
	/* 0x4b8d: add    rbp,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4b91:
	/* 0x4b91: mov    QWORD PTR [r13+0x10],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4b95:
	/* 0x4b95: cmp    rax,0xffffffffffffffea */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, 0, 18446744073709551594ULL);
x86_l_4b99:
	/* 0x4b99: jne    4ba4 <data_event_bytes+0x61> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x4b99, 0x4ba4, x86_l_4ba4);
x86_l_4b9b:
	/* 0x4b9b: mov    rax,QWORD PTR [r12+0x20] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4ba0:
	/* 0x4ba0: mov    QWORD PTR [rbp+0x0],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4ba4:
	/* 0x4ba4: call   4c39 <do_bytes+0x26> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_ktime_get_boot_ns);
x86_l_4ba9:
	/* 0x4ba9: mov    QWORD PTR [r13+0x18],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4bad:
	/* 0x4bad: mov    rax,QWORD PTR [rbp+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4bb1:
	/* 0x4bb1: mov    rcx,QWORD PTR [rbp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4bb5:
	/* 0x4bb5: mov    QWORD PTR [rbx+0x10],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4bb9:
	/* 0x4bb9: mov    QWORD PTR [rbx+0x18],rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4bbd:
	/* 0x4bbd: mov    rdi,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_4bc0:
	/* 0x4bc0: mov    rsi,r13 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_4bc3:
	/* 0x4bc3: mov    rdx,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_4bc6:
	/* 0x4bc6: mov    rcx,r14 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_4bc9:
	/* 0x4bc9: call   4c13 <do_bytes> */
	X86_SIM_X86_CALL(x86_l_4c13, 0x4bceULL);
x86_l_4bce:
	/* 0x4bce: mov    ecx,r14d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_R14, X86_WIDTH_32, 0, 0);
x86_l_4bd1:
	/* 0x4bd1: sub    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB, 0);
x86_l_4bd3:
	/* 0x4bd3: xor    edx,edx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_4bd5:
	/* 0x4bd5: cmp    r14,0xffffffffffffffff */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, 0, 18446744073709551615ULL);
x86_l_4bd9:
	/* 0x4bd9: cmove  ecx,edx */
	X86_SIM_RUN_OP(X86_OP_CMOV, X86_RCX, X86_RDX, X86_WIDTH_32, X86_CC_E, 0);
x86_l_4bdc:
	/* 0x4bdc: test   eax,eax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_4bde:
	/* 0x4bde: mov    esi,0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 0ULL);
x86_l_4be3:
	/* 0x4be3: cmovs  esi,eax */
	X86_SIM_RUN_OP(X86_OP_CMOV, X86_RSI, X86_RAX, X86_WIDTH_32, X86_CC_S, 0);
x86_l_4be6:
	/* 0x4be6: cmovs  ecx,edx */
	X86_SIM_RUN_OP(X86_OP_CMOV, X86_RCX, X86_RDX, X86_WIDTH_32, X86_CC_S, 0);
x86_l_4be9:
	/* 0x4be9: mov    DWORD PTR [rbx],esi */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RBX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4beb:
	/* 0x4beb: mov    DWORD PTR [rbx+0x4],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_4bf2:
	/* 0x4bf2: cmovg  edx,eax */
	X86_SIM_RUN_OP(X86_OP_CMOV, X86_RDX, X86_RAX, X86_WIDTH_32, X86_CC_G, 0);
x86_l_4bf5:
	/* 0x4bf5: mov    DWORD PTR [rbx+0x8],ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4bf8:
	/* 0x4bf8: mov    DWORD PTR [rbx+0xc],edx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RBX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_4bfb:
	/* 0x4bfb: mov    eax,0x20 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 32ULL);
x86_l_4c00:
	/* 0x4c00: jmp    4c04 <data_event_bytes+0xc1> */
	X86_SIM_X86_SUB_JMP(0x4c00, 0x4c04, x86_l_4c04);
x86_l_4c02:
	/* 0x4c02: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_4c04:
	/* 0x4c04: add    rsp,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4c08:
	/* 0x4c08: pop    rbx */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_4c09:
	/* 0x4c09: pop    r12 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R12, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_4c0b:
	/* 0x4c0b: pop    r13 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R13, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_4c0d:
	/* 0x4c0d: pop    r14 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R14, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_4c0f:
	/* 0x4c0f: pop    r15 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R15, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_4c11:
	/* 0x4c11: pop    rbp */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBP, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_4c12:
	/* 0x4c12: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_4c12);

	/* native subroutine native_link_sub_4c13 */
x86_l_4c13:
	/* 0x4c13: push   rbp */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_4c14:
	/* 0x4c14: push   r15 */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_4c16:
	/* 0x4c16: push   r14 */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_4c18:
	/* 0x4c18: push   r13 */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_4c1a:
	/* 0x4c1a: push   r12 */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_4c1c:
	/* 0x4c1c: push   rbx */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_4c1d:
	/* 0x4c1d: push   rax */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_4c1e:
	/* 0x4c1e: mov    rbx,rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RBX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_4c21:
	/* 0x4c21: mov    r14,rdx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R14, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_4c24:
	/* 0x4c24: mov    r15,rsi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R15, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_4c27:
	/* 0x4c27: mov    r12,rdi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R12, X86_RDI, X86_WIDTH_64, 0, 0);
x86_l_4c2a:
	/* 0x4c2a: call   4e5e <__do_bytes> */
	X86_SIM_X86_CALL(x86_l_4e5e, 0x4c2fULL);
x86_l_4c2f:
	/* 0x4c2f: mov    r13,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R13, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_4c32:
	/* 0x4c32: test   eax,eax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_4c34:
	/* 0x4c34: js     4dd7 <do_bytes+0x1c4> */
	X86_SIM_X86_SUB_JCC(X86_CC_S, 0x4c34, 0x4dd7, x86_l_4dd7);
x86_l_4c3a:
	/* 0x4c3a: mov    rcx,rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_4c3d:
	/* 0x4c3d: sub    rcx,rax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_SUB, 0);
x86_l_4c40:
	/* 0x4c40: je     4e4c <do_bytes+0x239> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x4c40, 0x4e4c, x86_l_4e4c);
x86_l_4c46:
	/* 0x4c46: lea    rdx,[rax+r14*1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_4c4a:
	/* 0x4c4a: mov    rdi,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_4c4d:
	/* 0x4c4d: mov    rsi,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_4c50:
	/* 0x4c50: mov    r13,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R13, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_4c53:
	/* 0x4c53: call   4e5e <__do_bytes> */
	X86_SIM_X86_CALL(x86_l_4e5e, 0x4c58ULL);
x86_l_4c58:
	/* 0x4c58: mov    rcx,r13 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_4c5b:
	/* 0x4c5b: mov    r13,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R13, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_4c5e:
	/* 0x4c5e: test   eax,eax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_4c60:
	/* 0x4c60: js     4dd7 <do_bytes+0x1c4> */
	X86_SIM_X86_SUB_JCC(X86_CC_S, 0x4c60, 0x4dd7, x86_l_4dd7);
x86_l_4c66:
	/* 0x4c66: add    rax,rcx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_4c69:
	/* 0x4c69: mov    rcx,rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_4c6c:
	/* 0x4c6c: sub    rcx,rax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_SUB, 0);
x86_l_4c6f:
	/* 0x4c6f: je     4e4c <do_bytes+0x239> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x4c6f, 0x4e4c, x86_l_4e4c);
x86_l_4c75:
	/* 0x4c75: lea    rdx,[rax+r14*1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_4c79:
	/* 0x4c79: mov    rdi,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_4c7c:
	/* 0x4c7c: mov    rsi,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_4c7f:
	/* 0x4c7f: mov    r13,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R13, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_4c82:
	/* 0x4c82: call   4e5e <__do_bytes> */
	X86_SIM_X86_CALL(x86_l_4e5e, 0x4c87ULL);
x86_l_4c87:
	/* 0x4c87: mov    rcx,r13 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_4c8a:
	/* 0x4c8a: mov    r13,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R13, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_4c8d:
	/* 0x4c8d: test   eax,eax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_4c8f:
	/* 0x4c8f: js     4dd7 <do_bytes+0x1c4> */
	X86_SIM_X86_SUB_JCC(X86_CC_S, 0x4c8f, 0x4dd7, x86_l_4dd7);
x86_l_4c95:
	/* 0x4c95: add    rax,rcx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_4c98:
	/* 0x4c98: mov    rcx,rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_4c9b:
	/* 0x4c9b: sub    rcx,rax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_SUB, 0);
x86_l_4c9e:
	/* 0x4c9e: je     4e4c <do_bytes+0x239> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x4c9e, 0x4e4c, x86_l_4e4c);
x86_l_4ca4:
	/* 0x4ca4: lea    rdx,[rax+r14*1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_4ca8:
	/* 0x4ca8: mov    rdi,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_4cab:
	/* 0x4cab: mov    rsi,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_4cae:
	/* 0x4cae: mov    r13,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R13, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_4cb1:
	/* 0x4cb1: call   4e5e <__do_bytes> */
	X86_SIM_X86_CALL(x86_l_4e5e, 0x4cb6ULL);
x86_l_4cb6:
	/* 0x4cb6: mov    rcx,r13 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_4cb9:
	/* 0x4cb9: mov    r13,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R13, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_4cbc:
	/* 0x4cbc: test   eax,eax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_4cbe:
	/* 0x4cbe: js     4dd7 <do_bytes+0x1c4> */
	X86_SIM_X86_SUB_JCC(X86_CC_S, 0x4cbe, 0x4dd7, x86_l_4dd7);
x86_l_4cc4:
	/* 0x4cc4: add    rax,rcx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_4cc7:
	/* 0x4cc7: mov    rcx,rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_4cca:
	/* 0x4cca: sub    rcx,rax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_SUB, 0);
x86_l_4ccd:
	/* 0x4ccd: je     4e4c <do_bytes+0x239> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x4ccd, 0x4e4c, x86_l_4e4c);
x86_l_4cd3:
	/* 0x4cd3: lea    rdx,[rax+r14*1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_4cd7:
	/* 0x4cd7: mov    rdi,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_4cda:
	/* 0x4cda: mov    rsi,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_4cdd:
	/* 0x4cdd: mov    r13,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R13, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_4ce0:
	/* 0x4ce0: call   4e5e <__do_bytes> */
	X86_SIM_X86_CALL(x86_l_4e5e, 0x4ce5ULL);
x86_l_4ce5:
	/* 0x4ce5: mov    rcx,r13 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_4ce8:
	/* 0x4ce8: mov    r13,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R13, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_4ceb:
	/* 0x4ceb: test   eax,eax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_4ced:
	/* 0x4ced: js     4dd7 <do_bytes+0x1c4> */
	X86_SIM_X86_SUB_JCC(X86_CC_S, 0x4ced, 0x4dd7, x86_l_4dd7);
x86_l_4cf3:
	/* 0x4cf3: add    rax,rcx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_4cf6:
	/* 0x4cf6: mov    rcx,rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_4cf9:
	/* 0x4cf9: sub    rcx,rax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_SUB, 0);
x86_l_4cfc:
	/* 0x4cfc: je     4e4c <do_bytes+0x239> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x4cfc, 0x4e4c, x86_l_4e4c);
x86_l_4d02:
	/* 0x4d02: lea    rdx,[rax+r14*1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_4d06:
	/* 0x4d06: mov    rdi,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_4d09:
	/* 0x4d09: mov    rsi,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_4d0c:
	/* 0x4d0c: mov    r13,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R13, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_4d0f:
	/* 0x4d0f: call   4e5e <__do_bytes> */
	X86_SIM_X86_CALL(x86_l_4e5e, 0x4d14ULL);
x86_l_4d14:
	/* 0x4d14: mov    rcx,r13 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_4d17:
	/* 0x4d17: mov    r13,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R13, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_4d1a:
	/* 0x4d1a: test   eax,eax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_4d1c:
	/* 0x4d1c: js     4dd7 <do_bytes+0x1c4> */
	X86_SIM_X86_SUB_JCC(X86_CC_S, 0x4d1c, 0x4dd7, x86_l_4dd7);
x86_l_4d22:
	/* 0x4d22: add    rax,rcx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_4d25:
	/* 0x4d25: mov    rcx,rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_4d28:
	/* 0x4d28: sub    rcx,rax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_SUB, 0);
x86_l_4d2b:
	/* 0x4d2b: je     4e4c <do_bytes+0x239> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x4d2b, 0x4e4c, x86_l_4e4c);
x86_l_4d31:
	/* 0x4d31: lea    rdx,[rax+r14*1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_4d35:
	/* 0x4d35: mov    rdi,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_4d38:
	/* 0x4d38: mov    rsi,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_4d3b:
	/* 0x4d3b: mov    r13,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R13, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_4d3e:
	/* 0x4d3e: call   4e5e <__do_bytes> */
	X86_SIM_X86_CALL(x86_l_4e5e, 0x4d43ULL);
x86_l_4d43:
	/* 0x4d43: mov    rcx,r13 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_4d46:
	/* 0x4d46: mov    r13,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R13, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_4d49:
	/* 0x4d49: test   eax,eax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_4d4b:
	/* 0x4d4b: js     4dd7 <do_bytes+0x1c4> */
	X86_SIM_X86_SUB_JCC(X86_CC_S, 0x4d4b, 0x4dd7, x86_l_4dd7);
x86_l_4d51:
	/* 0x4d51: add    rax,rcx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_4d54:
	/* 0x4d54: mov    rcx,rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_4d57:
	/* 0x4d57: sub    rcx,rax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_SUB, 0);
x86_l_4d5a:
	/* 0x4d5a: je     4e4c <do_bytes+0x239> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x4d5a, 0x4e4c, x86_l_4e4c);
x86_l_4d60:
	/* 0x4d60: lea    rdx,[rax+r14*1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_4d64:
	/* 0x4d64: mov    rdi,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_4d67:
	/* 0x4d67: mov    rsi,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_4d6a:
	/* 0x4d6a: mov    r13,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R13, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_4d6d:
	/* 0x4d6d: call   4e5e <__do_bytes> */
	X86_SIM_X86_CALL(x86_l_4e5e, 0x4d72ULL);
x86_l_4d72:
	/* 0x4d72: mov    rbp,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RBP, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_4d75:
	/* 0x4d75: mov    rax,r13 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_4d78:
	/* 0x4d78: mov    r13,rbp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R13, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_4d7b:
	/* 0x4d7b: test   ebp,ebp */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32, 0, 0);
x86_l_4d7d:
	/* 0x4d7d: js     4dd7 <do_bytes+0x1c4> */
	X86_SIM_X86_SUB_JCC(X86_CC_S, 0x4d7d, 0x4dd7, x86_l_4dd7);
x86_l_4d7f:
	/* 0x4d7f: add    rbp,rax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_4d82:
	/* 0x4d82: mov    rcx,rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_4d85:
	/* 0x4d85: sub    rcx,rbp */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB, 0);
x86_l_4d88:
	/* 0x4d88: je     4e4c <do_bytes+0x239> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x4d88, 0x4e4c, x86_l_4e4c);
x86_l_4d8e:
	/* 0x4d8e: lea    rdx,[r14+rbp*1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_4d92:
	/* 0x4d92: mov    rdi,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_4d95:
	/* 0x4d95: mov    rsi,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_4d98:
	/* 0x4d98: call   4e5e <__do_bytes> */
	X86_SIM_X86_CALL(x86_l_4e5e, 0x4d9dULL);
x86_l_4d9d:
	/* 0x4d9d: mov    r13,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R13, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_4da0:
	/* 0x4da0: test   eax,eax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_4da2:
	/* 0x4da2: js     4dd7 <do_bytes+0x1c4> */
	X86_SIM_X86_SUB_JCC(X86_CC_S, 0x4da2, 0x4dd7, x86_l_4dd7);
x86_l_4da4:
	/* 0x4da4: mov    rcx,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_4da7:
	/* 0x4da7: add    rax,rbp */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_4daa:
	/* 0x4daa: mov    rcx,rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_4dad:
	/* 0x4dad: sub    rcx,rax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_SUB, 0);
x86_l_4db0:
	/* 0x4db0: je     4e4c <do_bytes+0x239> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x4db0, 0x4e4c, x86_l_4e4c);
x86_l_4db6:
	/* 0x4db6: mov    rbp,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RBP, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_4db9:
	/* 0x4db9: add    r14,rax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_4dbc:
	/* 0x4dbc: mov    rdi,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_4dbf:
	/* 0x4dbf: mov    rsi,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_4dc2:
	/* 0x4dc2: mov    rdx,r14 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_4dc5:
	/* 0x4dc5: call   4e5e <__do_bytes> */
	X86_SIM_X86_CALL(x86_l_4e5e, 0x4dcaULL);
x86_l_4dca:
	/* 0x4dca: mov    r13,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R13, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_4dcd:
	/* 0x4dcd: test   r13d,r13d */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_32, 0, 0);
x86_l_4dd0:
	/* 0x4dd0: js     4dd7 <do_bytes+0x1c4> */
	X86_SIM_X86_SUB_JCC(X86_CC_S, 0x4dd0, 0x4dd7, x86_l_4dd7);
x86_l_4dd2:
	/* 0x4dd2: add    r13,rbp */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_4dd5:
	/* 0x4dd5: jmp    4e49 <do_bytes+0x236> */
	X86_SIM_X86_SUB_JMP(0x4dd5, 0x4e49, x86_l_4e49);
x86_l_4dd7:
	/* 0x4dd7: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_4ddf:
	/* 0x4ddf: mov    rdi,QWORD PTR [rip+0x160] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)tg_stats_map));
x86_l_4de6:
	/* 0x4de6: lea    rsi,[rsp+0x4] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4deb:
	/* 0x4deb: call   4f50 <__do_bytes+0xf2> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_4df0:
	/* 0x4df0: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_4df3:
	/* 0x4df3: je     4e49 <do_bytes+0x236> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x4df3, 0x4e49, x86_l_4e49);
x86_l_4df5:
	/* 0x4df5: lea    rcx,[r13+0x1c] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_4df9:
	/* 0x4df9: cmp    rcx,0x1a */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, 0, 26ULL);
x86_l_4dfd:
	/* 0x4dfd: ja     4e27 <do_bytes+0x214> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x4dfd, 0x4e27, x86_l_4e27);
x86_l_4dff:
	/* Capture image-bound code identity before scheduled instructions. */
	switch (X86_SIM_L_READ_REG(X86_RCX) << 2) {
	case 0ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x4e0fULL); break;
	case 4ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x4e27ULL); break;
	case 8ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x4e27ULL); break;
	case 12ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x4e27ULL); break;
	case 16ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x4e27ULL); break;
	case 20ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x4e27ULL); break;
	case 24ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x4e2fULL); break;
	case 28ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x4e27ULL); break;
	case 32ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x4e27ULL); break;
	case 36ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x4e27ULL); break;
	case 40ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x4e27ULL); break;
	case 44ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x4e27ULL); break;
	case 48ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x4e17ULL); break;
	case 52ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x4e27ULL); break;
	case 56ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x4e27ULL); break;
	case 60ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x4e27ULL); break;
	case 64ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x4e27ULL); break;
	case 68ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x4e37ULL); break;
	case 72ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x4e27ULL); break;
	case 76ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x4e27ULL); break;
	case 80ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x4e27ULL); break;
	case 84ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x4e3fULL); break;
	case 88ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x4e27ULL); break;
	case 92ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x4e27ULL); break;
	case 96ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x4e27ULL); break;
	case 100ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x4e27ULL); break;
	case 104ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x4e1fULL); break;
	default: __x86_sim_unresolved_indirect_target();
	}
x86_l_4e0d:
	/* 0x4e0d: jmp    rcx */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RCX);
		switch (X86_SIM_L_REG_TAG(X86_RCX)) {
		case X86_SIM_TAG_CODE:
			switch (__x86_target) {
			case 0x4e0fULL: goto x86_l_4e0f;
			case 0x4e17ULL: goto x86_l_4e17;
			case 0x4e1fULL: goto x86_l_4e1f;
			case 0x4e27ULL: goto x86_l_4e27;
			case 0x4e2fULL: goto x86_l_4e2f;
			case 0x4e37ULL: goto x86_l_4e37;
			case 0x4e3fULL: goto x86_l_4e3f;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_4e0f:
	/* 0x4e0f: add    rax,0x568 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 1384ULL);
x86_l_4e15:
	/* 0x4e15: jmp    4e45 <do_bytes+0x232> */
	X86_SIM_X86_SUB_JMP(0x4e15, 0x4e45, x86_l_4e45);
x86_l_4e17:
	/* 0x4e17: add    rax,0x558 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 1368ULL);
x86_l_4e1d:
	/* 0x4e1d: jmp    4e45 <do_bytes+0x232> */
	X86_SIM_X86_SUB_JMP(0x4e1d, 0x4e45, x86_l_4e45);
x86_l_4e1f:
	/* 0x4e1f: add    rax,0x548 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 1352ULL);
x86_l_4e25:
	/* 0x4e25: jmp    4e45 <do_bytes+0x232> */
	X86_SIM_X86_SUB_JMP(0x4e25, 0x4e45, x86_l_4e45);
x86_l_4e27:
	/* 0x4e27: add    rax,0x540 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 1344ULL);
x86_l_4e2d:
	/* 0x4e2d: jmp    4e45 <do_bytes+0x232> */
	X86_SIM_X86_SUB_JMP(0x4e2d, 0x4e45, x86_l_4e45);
x86_l_4e2f:
	/* 0x4e2f: add    rax,0x560 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 1376ULL);
x86_l_4e35:
	/* 0x4e35: jmp    4e45 <do_bytes+0x232> */
	X86_SIM_X86_SUB_JMP(0x4e35, 0x4e45, x86_l_4e45);
x86_l_4e37:
	/* 0x4e37: add    rax,0x570 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 1392ULL);
x86_l_4e3d:
	/* 0x4e3d: jmp    4e45 <do_bytes+0x232> */
	X86_SIM_X86_SUB_JMP(0x4e3d, 0x4e45, x86_l_4e45);
x86_l_4e3f:
	/* 0x4e3f: add    rax,0x550 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 1360ULL);
x86_l_4e45:
	/* 0x4e45: lock inc QWORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_ALU_MEM_UNARY, X86_RAX, X86_REG_NONE, (X86_WIDTH_64 | X86_MEM_LOCK), (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_4e49:
	/* 0x4e49: mov    rbx,r13 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RBX, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_4e4c:
	/* 0x4e4c: mov    rax,rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_4e4f:
	/* 0x4e4f: add    rsp,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4e53:
	/* 0x4e53: pop    rbx */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_4e54:
	/* 0x4e54: pop    r12 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R12, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_4e56:
	/* 0x4e56: pop    r13 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R13, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_4e58:
	/* 0x4e58: pop    r14 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R14, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_4e5a:
	/* 0x4e5a: pop    r15 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R15, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_4e5c:
	/* 0x4e5c: pop    rbp */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBP, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_4e5d:
	/* 0x4e5d: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_4e5d);

	/* native subroutine native_link_sub_4e5e */
x86_l_4e5e:
	/* 0x4e5e: push   r15 */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_4e60:
	/* 0x4e60: push   r14 */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_4e62:
	/* 0x4e62: push   r12 */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_4e64:
	/* 0x4e64: push   rbx */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_4e65:
	/* 0x4e65: push   rax */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_4e66:
	/* 0x4e66: mov    r14,rsi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R14, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_4e69:
	/* 0x4e69: mov    r15,rdi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R15, X86_RDI, X86_WIDTH_64, 0, 0);
x86_l_4e6c:
	/* 0x4e6c: cmp    rcx,0x7fe0 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, 0, 32736ULL);
x86_l_4e73:
	/* 0x4e73: mov    ebx,0x7fe0 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 32736ULL);
x86_l_4e78:
	/* 0x4e78: cmovb  rbx,rcx */
	X86_SIM_RUN_OP(X86_OP_CMOV, X86_RBX, X86_RCX, X86_WIDTH_64, X86_CC_B, 0);
x86_l_4e7c:
	/* 0x4e7c: lea    rdi,[rsi+0x20] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4e80:
	/* 0x4e80: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_4e83:
	/* 0x4e83: js     4e95 <__do_bytes+0x37> */
	X86_SIM_X86_SUB_JCC(X86_CC_S, 0x4e83, 0x4e95, x86_l_4e95);
x86_l_4e85:
	/* 0x4e85: mov    esi,ebx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_RBX, X86_WIDTH_32, 0, 0);
x86_l_4e87:
	/* 0x4e87: call   523c <__native_link_local_memset_zero_4097+0x227> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_4e8c:
	/* 0x4e8c: test   eax,eax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_4e8e:
	/* 0x4e8e: jns    4edf <__do_bytes+0x81> */
	X86_SIM_X86_SUB_JCC(X86_CC_NS, 0x4e8e, 0x4edf, x86_l_4edf);
x86_l_4e90:
	/* 0x4e90: jmp    4f56 <__do_bytes+0xf8> */
	X86_SIM_X86_SUB_JMP(0x4e90, 0x4f56, x86_l_4f56);
x86_l_4e95:
	/* 0x4e95: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_4e98:
	/* 0x4e98: jns    4f45 <__do_bytes+0xe7> */
	X86_SIM_X86_SUB_JCC(X86_CC_NS, 0x4e98, 0x4f45, x86_l_4f45);
x86_l_4e9e:
	/* 0x4e9e: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_4ea0:
	/* 0x4ea0: cmp    ebx,0x8 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_4ea3:
	/* 0x4ea3: jb     4ebf <__do_bytes+0x61> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x4ea3, 0x4ebf, x86_l_4ebf);
x86_l_4ea5:
	/* 0x4ea5: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_4ea7:
	/* 0x4ea7: mov    rcx,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_4eaa:
	/* 0x4eaa: mov    rax,QWORD PTR [rdx+rax*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_4eae:
	/* 0x4eae: mov    QWORD PTR [rdi+rcx*1],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4eb2:
	/* 0x4eb2: lea    rax,[rcx+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4eb6:
	/* 0x4eb6: add    rcx,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4eba:
	/* 0x4eba: cmp    rcx,rbx */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RCX, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_4ebd:
	/* 0x4ebd: jbe    4ea7 <__do_bytes+0x49> */
	X86_SIM_X86_SUB_JCC(X86_CC_BE, 0x4ebd, 0x4ea7, x86_l_4ea7);
x86_l_4ebf:
	/* 0x4ebf: test   bl,0x4 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, 0, 4ULL);
x86_l_4ec2:
	/* 0x4ec2: jne    4f68 <__do_bytes+0x10a> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x4ec2, 0x4f68, x86_l_4f68);
x86_l_4ec8:
	/* 0x4ec8: test   bl,0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, 0, 2ULL);
x86_l_4ecb:
	/* 0x4ecb: jne    4f7c <__do_bytes+0x11e> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x4ecb, 0x4f7c, x86_l_4f7c);
x86_l_4ed1:
	/* 0x4ed1: test   bl,0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_4ed4:
	/* 0x4ed4: je     4edf <__do_bytes+0x81> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x4ed4, 0x4edf, x86_l_4edf);
x86_l_4ed6:
	/* 0x4ed6: mov    eax,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_4ed8:
	/* 0x4ed8: movzx  ecx,BYTE PTR [rdx+rax*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_4edc:
	/* 0x4edc: mov    BYTE PTR [rdi+rax*1],cl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_4edf:
	/* 0x4edf: lea    r12d,[rbx+0x20] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R12, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4ee3:
	/* 0x4ee3: mov    DWORD PTR [r14+0x4],r12d */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_R14, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4ee7:
	/* 0x4ee7: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_4eef:
	/* 0x4eef: mov    rdi,QWORD PTR [rip+0x3b7] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)tg_conf_map));
x86_l_4ef6:
	/* 0x4ef6: lea    rsi,[rsp+0x4] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4efb:
	/* 0x4efb: call   52b7 <__native_link_local_memset_zero_4097+0x2a2> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_4f00:
	/* 0x4f00: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_4f03:
	/* 0x4f03: je     4f2b <__do_bytes+0xcd> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x4f03, 0x4f2b, x86_l_4f2b);
x86_l_4f05:
	/* 0x4f05: cmp    BYTE PTR [rax+0x28],0x0 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_4f09:
	/* 0x4f09: je     4f2b <__do_bytes+0xcd> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x4f09, 0x4f2b, x86_l_4f2b);
x86_l_4f0b:
	/* 0x4f0b: mov    rsi,QWORD PTR [rip+0x3b7] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RSI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)tcpmon_map));
x86_l_4f12:
	/* 0x4f12: mov    edx,0xffffffff */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 4294967295ULL);
x86_l_4f17:
	/* 0x4f17: mov    rdi,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_4f1a:
	/* 0x4f1a: mov    rcx,r14 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_4f1d:
	/* 0x4f1d: mov    r8,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R8, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_4f20:
	/* 0x4f20: call   52dc <__native_link_local_memset_zero_4097+0x2c7> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_perf_event_output);
x86_l_4f25:
	/* 0x4f25: test   eax,eax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_4f27:
	/* 0x4f27: js     4f56 <__do_bytes+0xf8> */
	X86_SIM_X86_SUB_JCC(X86_CC_S, 0x4f27, 0x4f56, x86_l_4f56);
x86_l_4f29:
	/* 0x4f29: jmp    4f59 <__do_bytes+0xfb> */
	X86_SIM_X86_SUB_JMP(0x4f29, 0x4f59, x86_l_4f59);
x86_l_4f2b:
	/* 0x4f2b: mov    rdi,QWORD PTR [rip+0x3b7] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)tg_rb_events));
x86_l_4f32:
	/* 0x4f32: mov    rsi,r14 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_4f35:
	/* 0x4f35: mov    rdx,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_4f38:
	/* 0x4f38: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_4f3a:
	/* 0x4f3a: call   52f6 <__native_link_local_memset_zero_4097+0x2e1> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_ringbuf_output);
x86_l_4f3f:
	/* 0x4f3f: test   eax,eax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_4f41:
	/* 0x4f41: js     4f56 <__do_bytes+0xf8> */
	X86_SIM_X86_SUB_JCC(X86_CC_S, 0x4f41, 0x4f56, x86_l_4f56);
x86_l_4f43:
	/* 0x4f43: jmp    4f59 <__do_bytes+0xfb> */
	X86_SIM_X86_SUB_JMP(0x4f43, 0x4f59, x86_l_4f59);
x86_l_4f45:
	/* 0x4f45: xor    esi,esi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_4f47:
	/* 0x4f47: mov    rdx,rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_4f4a:
	/* 0x4f4a: call   4f97 <__native_link_local_memset_zero_dynamic> */
	X86_SIM_X86_CALL(x86_l_4f97, 0x4f4fULL);
x86_l_4f4f:
	/* 0x4f4f: mov    rax,0xffffffffffffffde */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, 0, 18446744073709551582ULL);
x86_l_4f56:
	/* 0x4f56: movsxd rbx,eax */
	X86_SIM_RUN_OP(X86_OP_MOVSX_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32, 0);
x86_l_4f59:
	/* 0x4f59: mov    rax,rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_4f5c:
	/* 0x4f5c: add    rsp,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4f60:
	/* 0x4f60: pop    rbx */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_4f61:
	/* 0x4f61: pop    r12 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R12, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_4f63:
	/* 0x4f63: pop    r14 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R14, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_4f65:
	/* 0x4f65: pop    r15 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R15, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_4f67:
	/* 0x4f67: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_4f67);
x86_l_4f68:
	/* 0x4f68: mov    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_4f6a:
	/* 0x4f6a: mov    esi,DWORD PTR [rdx+rcx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4f6d:
	/* 0x4f6d: mov    DWORD PTR [rdi+rcx*1],esi */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4f70:
	/* 0x4f70: or     eax,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_OR, 4ULL);
x86_l_4f73:
	/* 0x4f73: test   bl,0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, 0, 2ULL);
x86_l_4f76:
	/* 0x4f76: je     4ed1 <__do_bytes+0x73> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x4f76, 0x4ed1, x86_l_4ed1);
x86_l_4f7c:
	/* 0x4f7c: mov    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_4f7e:
	/* 0x4f7e: movzx  esi,WORD PTR [rdx+rcx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_16), 0ULL);
x86_l_4f82:
	/* 0x4f82: mov    WORD PTR [rdi+rcx*1],si */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RSI, X86_WIDTH_16, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4f86:
	/* 0x4f86: add    eax,0x2 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_4f89:
	/* 0x4f89: test   bl,0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_4f8c:
	/* 0x4f8c: jne    4ed6 <__do_bytes+0x78> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x4f8c, 0x4ed6, x86_l_4ed6);
x86_l_4f92:
	/* 0x4f92: jmp    4edf <__do_bytes+0x81> */
	X86_SIM_X86_SUB_JMP(0x4f92, 0x4edf, x86_l_4edf);

	/* native subroutine native_link_sub_4f97 */
x86_l_4f97:
	/* 0x4f97: mov    rax,rdi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RDI, X86_WIDTH_64, 0, 0);
x86_l_4f9a:
	/* 0x4f9a: xor    r8d,r8d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_4f9d:
	/* 0x4f9d: cmp    rdx,0x20 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, 0, 32ULL);
x86_l_4fa1:
	/* 0x4fa1: jb     4fc8 <__native_link_local_memset_zero_dynamic+0x31> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x4fa1, 0x4fc8, x86_l_4fc8);
x86_l_4fa7:
	/* 0x4fa7: mov    QWORD PTR [rdi],r8 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4faa:
	/* 0x4faa: mov    QWORD PTR [rdi+0x8],r8 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4fae:
	/* 0x4fae: mov    QWORD PTR [rdi+0x10],r8 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4fb2:
	/* 0x4fb2: mov    QWORD PTR [rdi+0x18],r8 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4fb6:
	/* 0x4fb6: add    rdi,0x20 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_4fba:
	/* 0x4fba: sub    rdx,0x20 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SUB, 32ULL);
x86_l_4fbe:
	/* 0x4fbe: cmp    rdx,0x20 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, 0, 32ULL);
x86_l_4fc2:
	/* 0x4fc2: jae    4fa7 <__native_link_local_memset_zero_dynamic+0x10> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x4fc2, 0x4fa7, x86_l_4fa7);
x86_l_4fc8:
	/* 0x4fc8: cmp    rdx,0x8 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, 0, 8ULL);
x86_l_4fcc:
	/* 0x4fcc: jb     4fe7 <__native_link_local_memset_zero_dynamic+0x50> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x4fcc, 0x4fe7, x86_l_4fe7);
x86_l_4fd2:
	/* 0x4fd2: mov    QWORD PTR [rdi],r8 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4fd5:
	/* 0x4fd5: add    rdi,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4fd9:
	/* 0x4fd9: sub    rdx,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SUB, 8ULL);
x86_l_4fdd:
	/* 0x4fdd: cmp    rdx,0x8 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, 0, 8ULL);
x86_l_4fe1:
	/* 0x4fe1: jae    4fd2 <__native_link_local_memset_zero_dynamic+0x3b> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x4fe1, 0x4fd2, x86_l_4fd2);
x86_l_4fe7:
	/* 0x4fe7: test   dl,0x4 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, 0, 4ULL);
x86_l_4fea:
	/* 0x4fea: je     4ff7 <__native_link_local_memset_zero_dynamic+0x60> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x4fea, 0x4ff7, x86_l_4ff7);
x86_l_4ff0:
	/* 0x4ff0: mov    DWORD PTR [rdi],r8d */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4ff3:
	/* 0x4ff3: add    rdi,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_4ff7:
	/* 0x4ff7: test   dl,0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, 0, 2ULL);
x86_l_4ffa:
	/* 0x4ffa: je     5008 <__native_link_local_memset_zero_dynamic+0x71> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x4ffa, 0x5008, x86_l_5008);
x86_l_5000:
	/* 0x5000: mov    WORD PTR [rdi],r8w */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_R8, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5004:
	/* 0x5004: add    rdi,0x2 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_5008:
	/* 0x5008: test   dl,0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_500b:
	/* 0x500b: je     5014 <__native_link_local_memset_zero_dynamic+0x7d> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x500b, 0x5014, x86_l_5014);
x86_l_5011:
	/* 0x5011: mov    BYTE PTR [rdi],r8b */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_R8, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5014:
	/* 0x5014: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_5014);

	/* native subroutine native_link_sub_5015 */
x86_l_5015:
	/* 0x5015: mov    rax,rdi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RDI, X86_WIDTH_64, 0, 0);
x86_l_5018:
	/* 0x5018: xor    r8d,r8d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_501b:
	/* 0x501b: mov    ecx,0x80 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 128ULL);
x86_l_5020:
	/* 0x5020: mov    QWORD PTR [rdi],r8 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5023:
	/* 0x5023: mov    QWORD PTR [rdi+0x8],r8 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5027:
	/* 0x5027: mov    QWORD PTR [rdi+0x10],r8 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_502b:
	/* 0x502b: mov    QWORD PTR [rdi+0x18],r8 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_502f:
	/* 0x502f: add    rdi,0x20 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_5033:
	/* 0x5033: dec    rcx */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_5036:
	/* 0x5036: jne    5020 <__native_link_local_memset_zero_4097+0xb> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x5036, 0x5020, x86_l_5020);
x86_l_503c:
	/* 0x503c: mov    BYTE PTR [rdi],r8b */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_R8, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_503f:
	/* 0x503f: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_503f);

x86_sim_ret_dispatch_4b42:
	switch (__x86_sim_ret_addr) {
	case 0x167ULL: goto x86_l_167;
	default: __x86_sim_unresolved_indirect_target();
	}

x86_sim_ret_dispatch_4c12:
	switch (__x86_sim_ret_addr) {
	case 0x3976ULL: goto x86_l_3976;
	case 0x3bc7ULL: goto x86_l_3bc7;
	default: __x86_sim_unresolved_indirect_target();
	}

x86_sim_ret_dispatch_4e5d:
	switch (__x86_sim_ret_addr) {
	case 0x4bceULL: goto x86_l_4bce;
	default: __x86_sim_unresolved_indirect_target();
	}

x86_sim_ret_dispatch_4f67:
	switch (__x86_sim_ret_addr) {
	case 0x4c2fULL: goto x86_l_4c2f;
	case 0x4c58ULL: goto x86_l_4c58;
	case 0x4c87ULL: goto x86_l_4c87;
	case 0x4cb6ULL: goto x86_l_4cb6;
	case 0x4ce5ULL: goto x86_l_4ce5;
	case 0x4d14ULL: goto x86_l_4d14;
	case 0x4d43ULL: goto x86_l_4d43;
	case 0x4d72ULL: goto x86_l_4d72;
	case 0x4d9dULL: goto x86_l_4d9d;
	case 0x4dcaULL: goto x86_l_4dca;
	default: __x86_sim_unresolved_indirect_target();
	}

x86_sim_ret_dispatch_5014:
	switch (__x86_sim_ret_addr) {
	case 0xf39ULL: goto x86_l_f39;
	case 0x10abULL: goto x86_l_10ab;
	case 0x20f1ULL: goto x86_l_20f1;
	case 0x2bd2ULL: goto x86_l_2bd2;
	case 0x2ce6ULL: goto x86_l_2ce6;
	case 0x3b09ULL: goto x86_l_3b09;
	case 0x3cb6ULL: goto x86_l_3cb6;
	case 0x42eeULL: goto x86_l_42ee;
	case 0x4f4fULL: goto x86_l_4f4f;
	default: __x86_sim_unresolved_indirect_target();
	}

x86_sim_ret_dispatch_503f:
	switch (__x86_sim_ret_addr) {
	case 0x247bULL: goto x86_l_247b;
	default: __x86_sim_unresolved_indirect_target();
	}

}

X86_SIM_LICENSE();
