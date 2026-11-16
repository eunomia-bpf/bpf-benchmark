/* Retained event_wake_up_new_task simulator from the actual Tetragon request.
 * Native proof: PERF request 3, 2026-11-16; 738 instructions, frame 336.
 * Its native-link memcpy/memset subroutines and target/return switches remain.
 * This is checked-in C: edit it directly, without a semantic generator.
 * Only the two repository-relative includes differ from the retained C body.
 */
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_STACK_BYTES 336U
#define X86_SIM_STACK_VALUE_WORDS(M) M(0) M(1) M(2) M(3) M(4) M(5) M(6) M(7) M(8) M(9) M(10) M(11) M(12) M(13) M(14) M(15) M(16) M(17) M(18) M(19) M(20) M(21) M(22) M(23) M(24) M(25) M(26) M(27) M(28) M(29) M(30) M(31) M(32) M(33) M(34) M(35) M(36) M(37) M(38) M(39) M(40) M(41)
#include "../../x86/x86_sim_local_bpf.h"

#if defined(__bpf__) || defined(__BPF__)
static __attribute__((always_inline)) inline void
__x86_sim_unresolved_indirect_target(void) {
	asm volatile("call -1" ::: "r0", "r1", "r2", "r3", "r4", "r5", "memory");
}
#else
extern void __x86_sim_unresolved_indirect_target(void)
	__attribute__((error("indirect target was not eliminated by specialization")));
#endif

extern __u8 cgroup_rate_map[] __ksym;
extern __u8 cgroup_rate_options_map[] __ksym;
extern __u8 execve_map[] __ksym;
extern __u8 execve_map_stats[] __ksym;
extern __u8 execve_val[] __ksym;
extern __u8 tcpmon_map[] __ksym;
extern __u8 tg_cgtracker_map[] __ksym;
extern __u8 tg_conf_map[] __ksym;
extern __u8 tg_rb_events[] __ksym;
extern __u8 tg_stats_map[] __ksym;
extern __u8 throttle_heap_map[] __ksym;
#include "../../x86/x86_sim_inline.h"

X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_ALU_IMM, X86_OP_ALU_IMM)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_ALU_MEM, X86_OP_ALU_MEM)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_ALU_MEM_IMM, X86_OP_ALU_MEM_IMM)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_ALU_MEM_UNARY, X86_OP_ALU_MEM_UNARY)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_ALU_REG, X86_OP_ALU_REG)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_CALL_HELPER, X86_OP_CALL_HELPER)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_CMP_IMM, X86_OP_CMP_IMM)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_CMP_MEM_IMM, X86_OP_CMP_MEM_IMM)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_CMP_REG, X86_OP_CMP_REG)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_CMP_REG_MEM, X86_OP_CMP_REG_MEM)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_DIV, X86_OP_DIV)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_LEA, X86_OP_LEA)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_MOVSX_LOAD, X86_OP_MOVSX_LOAD)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_MOVZX_REG, X86_OP_MOVZX_REG)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_MOV_IMM, X86_OP_MOV_IMM)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_MOV_LOAD, X86_OP_MOV_LOAD)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_MOV_LOAD_MAP_PTR, X86_OP_MOV_LOAD_MAP_PTR)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_MOV_REG, X86_OP_MOV_REG)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_MOV_STORE_IMM, X86_OP_MOV_STORE_IMM)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_MOV_STORE_REG, X86_OP_MOV_STORE_REG)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_POP, X86_OP_POP)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_PUSH, X86_OP_PUSH)
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
	/* 0xa: sub    rsp,0x118 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SUB, 280ULL);
x86_l_11:
	/* 0x11: mov    r14,QWORD PTR [rdi+0x70] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_15:
	/* 0x15: test   r14,r14 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_18:
	/* 0x18: je     c8c <event_wake_up_new_task+0xc8c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x18, 0xc8c, x86_l_c8c);
x86_l_1e:
	/* 0x1e: mov    rbx,rdi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RBX, X86_RDI, X86_WIDTH_64, 0, 0);
x86_l_21:
	/* 0x21: lea    rdx,[r14+0xaf4] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2804ULL);
x86_l_28:
	/* 0x28: lea    rdi,[rsp+0x80] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_30:
	/* 0x30: mov    eax,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_35:
	/* 0x35: mov    ecx,0x71 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 113ULL);
x86_l_3a:
	/* 0x3a: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_3f:
	/* 0x3f: call   rcx */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RCX);
		switch (X86_SIM_L_REG_TAG(X86_RCX)) {
		case X86_SIM_TAG_SCALAR:
			switch (__x86_target) {
			case 0x71ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read_kernel); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		case X86_SIM_TAG_HELPER_ID:
			switch (__x86_target) {
			case 0x71ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read_kernel); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_41:
	/* 0x41: mov    ebp,DWORD PTR [rsp+0x80] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_48:
	/* 0x48: mov    QWORD PTR [rsp+0x80],r14 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_50:
	/* 0x50: lea    rdx,[r14+0xb00] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2816ULL);
x86_l_57:
	/* 0x57: lea    rdi,[rsp+0x80] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_5f:
	/* 0x5f: mov    eax,0x71 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 113ULL);
x86_l_64:
	/* 0x64: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_69:
	/* 0x69: call   rax */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RAX);
		switch (X86_SIM_L_REG_TAG(X86_RAX)) {
		case X86_SIM_TAG_SCALAR:
			switch (__x86_target) {
			case 0x71ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read_kernel); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		case X86_SIM_TAG_HELPER_ID:
			switch (__x86_target) {
			case 0x71ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read_kernel); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_6b:
	/* 0x6b: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_73:
	/* 0x73: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_76:
	/* 0x76: je     c8c <event_wake_up_new_task+0xc8c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x76, 0xc8c, x86_l_c8c);
x86_l_7c:
	/* 0x7c: add    rdx,0xaf4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 2804ULL);
x86_l_83:
	/* 0x83: lea    rdi,[rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_88:
	/* 0x88: mov    eax,0x71 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 113ULL);
x86_l_8d:
	/* 0x8d: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_92:
	/* 0x92: call   rax */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RAX);
		switch (X86_SIM_L_REG_TAG(X86_RAX)) {
		case X86_SIM_TAG_SCALAR:
			switch (__x86_target) {
			case 0x71ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read_kernel); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		case X86_SIM_TAG_HELPER_ID:
			switch (__x86_target) {
			case 0x71ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read_kernel); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_94:
	/* 0x94: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_98:
	/* 0x98: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_9c:
	/* 0x9c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)execve_map));
x86_l_a3:
	/* 0xa3: lea    rsi,[rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_a8:
	/* 0xa8: mov    eax,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_ad:
	/* 0xad: call   rax */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RAX);
		switch (X86_SIM_L_REG_TAG(X86_RAX)) {
		case X86_SIM_TAG_SCALAR:
			switch (__x86_target) {
			case 0x1ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_map_lookup_elem); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		case X86_SIM_TAG_HELPER_ID:
			switch (__x86_target) {
			case 0x1ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_map_lookup_elem); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_af:
	/* 0xaf: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_b2:
	/* 0xb2: je     c2 <event_wake_up_new_task+0xc2> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb2, 0xc2, x86_l_c2);
x86_l_b4:
	/* 0xb4: mov    r15,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R15, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_b7:
	/* 0xb7: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_bc:
	/* 0xbc: jne    22e <event_wake_up_new_task+0x22e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xbc, 0x22e, x86_l_22e);
x86_l_c2:
	/* 0xc2: mov    edx,0xb00 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 2816ULL);
x86_l_c7:
	/* 0xc7: add    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_RUN_OP(X86_OP_ALU_MEM, X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 128ULL);
x86_l_cf:
	/* 0xcf: lea    rdi,[rsp+0x80] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_d7:
	/* 0xd7: mov    eax,0x71 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 113ULL);
x86_l_dc:
	/* 0xdc: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_e1:
	/* 0xe1: call   rax */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RAX);
		switch (X86_SIM_L_REG_TAG(X86_RAX)) {
		case X86_SIM_TAG_SCALAR:
			switch (__x86_target) {
			case 0x71ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read_kernel); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		case X86_SIM_TAG_HELPER_ID:
			switch (__x86_target) {
			case 0x71ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read_kernel); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_e3:
	/* 0xe3: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_eb:
	/* 0xeb: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_ee:
	/* 0xee: je     c8c <event_wake_up_new_task+0xc8c> */
	X86_SIM_X86_JCC(X86_CC_E, 0xee, 0xc8c, x86_l_c8c);
x86_l_f4:
	/* 0xf4: add    rdx,0xaf4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 2804ULL);
x86_l_fb:
	/* 0xfb: lea    rdi,[rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_100:
	/* 0x100: mov    eax,0x71 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 113ULL);
x86_l_105:
	/* 0x105: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_10a:
	/* 0x10a: call   rax */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RAX);
		switch (X86_SIM_L_REG_TAG(X86_RAX)) {
		case X86_SIM_TAG_SCALAR:
			switch (__x86_target) {
			case 0x71ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read_kernel); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		case X86_SIM_TAG_HELPER_ID:
			switch (__x86_target) {
			case 0x71ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read_kernel); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_10c:
	/* 0x10c: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_110:
	/* 0x110: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_114:
	/* 0x114: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)execve_map));
x86_l_11b:
	/* 0x11b: lea    rsi,[rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_120:
	/* 0x120: mov    eax,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_125:
	/* 0x125: call   rax */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RAX);
		switch (X86_SIM_L_REG_TAG(X86_RAX)) {
		case X86_SIM_TAG_SCALAR:
			switch (__x86_target) {
			case 0x1ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_map_lookup_elem); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		case X86_SIM_TAG_HELPER_ID:
			switch (__x86_target) {
			case 0x1ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_map_lookup_elem); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_127:
	/* 0x127: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_12a:
	/* 0x12a: je     13a <event_wake_up_new_task+0x13a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12a, 0x13a, x86_l_13a);
x86_l_12c:
	/* 0x12c: mov    r15,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R15, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_12f:
	/* 0x12f: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_134:
	/* 0x134: jne    22e <event_wake_up_new_task+0x22e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x134, 0x22e, x86_l_22e);
x86_l_13a:
	/* 0x13a: mov    edx,0xb00 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 2816ULL);
x86_l_13f:
	/* 0x13f: add    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_RUN_OP(X86_OP_ALU_MEM, X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 128ULL);
x86_l_147:
	/* 0x147: lea    rdi,[rsp+0x80] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_14f:
	/* 0x14f: mov    eax,0x71 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 113ULL);
x86_l_154:
	/* 0x154: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_159:
	/* 0x159: call   rax */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RAX);
		switch (X86_SIM_L_REG_TAG(X86_RAX)) {
		case X86_SIM_TAG_SCALAR:
			switch (__x86_target) {
			case 0x71ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read_kernel); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		case X86_SIM_TAG_HELPER_ID:
			switch (__x86_target) {
			case 0x71ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read_kernel); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_15b:
	/* 0x15b: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_163:
	/* 0x163: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_166:
	/* 0x166: je     c8c <event_wake_up_new_task+0xc8c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x166, 0xc8c, x86_l_c8c);
x86_l_16c:
	/* 0x16c: add    rdx,0xaf4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 2804ULL);
x86_l_173:
	/* 0x173: lea    rdi,[rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_178:
	/* 0x178: mov    eax,0x71 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 113ULL);
x86_l_17d:
	/* 0x17d: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_182:
	/* 0x182: call   rax */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RAX);
		switch (X86_SIM_L_REG_TAG(X86_RAX)) {
		case X86_SIM_TAG_SCALAR:
			switch (__x86_target) {
			case 0x71ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read_kernel); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		case X86_SIM_TAG_HELPER_ID:
			switch (__x86_target) {
			case 0x71ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read_kernel); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_184:
	/* 0x184: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_188:
	/* 0x188: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_18c:
	/* 0x18c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)execve_map));
x86_l_193:
	/* 0x193: lea    rsi,[rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_198:
	/* 0x198: mov    eax,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_19d:
	/* 0x19d: call   rax */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RAX);
		switch (X86_SIM_L_REG_TAG(X86_RAX)) {
		case X86_SIM_TAG_SCALAR:
			switch (__x86_target) {
			case 0x1ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_map_lookup_elem); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		case X86_SIM_TAG_HELPER_ID:
			switch (__x86_target) {
			case 0x1ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_map_lookup_elem); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_19f:
	/* 0x19f: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_1a2:
	/* 0x1a2: je     1b2 <event_wake_up_new_task+0x1b2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a2, 0x1b2, x86_l_1b2);
x86_l_1a4:
	/* 0x1a4: mov    r15,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R15, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_1a7:
	/* 0x1a7: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1ac:
	/* 0x1ac: jne    22e <event_wake_up_new_task+0x22e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1ac, 0x22e, x86_l_22e);
x86_l_1b2:
	/* 0x1b2: mov    edx,0xb00 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 2816ULL);
x86_l_1b7:
	/* 0x1b7: add    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_RUN_OP(X86_OP_ALU_MEM, X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 128ULL);
x86_l_1bf:
	/* 0x1bf: lea    rdi,[rsp+0x80] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1c7:
	/* 0x1c7: mov    eax,0x71 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 113ULL);
x86_l_1cc:
	/* 0x1cc: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_1d1:
	/* 0x1d1: call   rax */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RAX);
		switch (X86_SIM_L_REG_TAG(X86_RAX)) {
		case X86_SIM_TAG_SCALAR:
			switch (__x86_target) {
			case 0x71ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read_kernel); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		case X86_SIM_TAG_HELPER_ID:
			switch (__x86_target) {
			case 0x71ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read_kernel); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_1d3:
	/* 0x1d3: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1db:
	/* 0x1db: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_1de:
	/* 0x1de: je     c8c <event_wake_up_new_task+0xc8c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1de, 0xc8c, x86_l_c8c);
x86_l_1e4:
	/* 0x1e4: add    rdx,0xaf4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 2804ULL);
x86_l_1eb:
	/* 0x1eb: lea    rdi,[rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f0:
	/* 0x1f0: mov    eax,0x71 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 113ULL);
x86_l_1f5:
	/* 0x1f5: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_1fa:
	/* 0x1fa: call   rax */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RAX);
		switch (X86_SIM_L_REG_TAG(X86_RAX)) {
		case X86_SIM_TAG_SCALAR:
			switch (__x86_target) {
			case 0x71ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read_kernel); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		case X86_SIM_TAG_HELPER_ID:
			switch (__x86_target) {
			case 0x71ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read_kernel); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_1fc:
	/* 0x1fc: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_200:
	/* 0x200: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_204:
	/* 0x204: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)execve_map));
x86_l_20b:
	/* 0x20b: lea    rsi,[rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_210:
	/* 0x210: mov    eax,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_215:
	/* 0x215: call   rax */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RAX);
		switch (X86_SIM_L_REG_TAG(X86_RAX)) {
		case X86_SIM_TAG_SCALAR:
			switch (__x86_target) {
			case 0x1ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_map_lookup_elem); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		case X86_SIM_TAG_HELPER_ID:
			switch (__x86_target) {
			case 0x1ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_map_lookup_elem); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_217:
	/* 0x217: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_21a:
	/* 0x21a: je     c8c <event_wake_up_new_task+0xc8c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x21a, 0xc8c, x86_l_c8c);
x86_l_220:
	/* 0x220: mov    r15,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R15, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_223:
	/* 0x223: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_228:
	/* 0x228: je     c8c <event_wake_up_new_task+0xc8c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x228, 0xc8c, x86_l_c8c);
x86_l_22e:
	/* 0x22e: mov    DWORD PTR [rsp+0x40],ebp */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_232:
	/* 0x232: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)execve_map));
x86_l_239:
	/* 0x239: mov    eax,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_23e:
	/* 0x23e: call   rax */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RAX);
		switch (X86_SIM_L_REG_TAG(X86_RAX)) {
		case X86_SIM_TAG_SCALAR:
			switch (__x86_target) {
			case 0x1ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_map_lookup_elem); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		case X86_SIM_TAG_HELPER_ID:
			switch (__x86_target) {
			case 0x1ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_map_lookup_elem); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_240:
	/* 0x240: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_243:
	/* 0x243: je     476 <event_wake_up_new_task+0x476> */
	X86_SIM_X86_JCC(X86_CC_E, 0x243, 0x476, x86_l_476);
x86_l_249:
	/* 0x249: mov    r12,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R12, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_24c:
	/* 0x24c: cmp    QWORD PTR [r12+0x8],0x0 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_252:
	/* 0x252: jne    c8c <event_wake_up_new_task+0xc8c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x252, 0xc8c, x86_l_c8c);
x86_l_258:
	/* 0x258: mov    QWORD PTR [rsp+0x110],rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_260:
	/* 0x260: mov    DWORD PTR [r12+0x20],0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953473ULL);
x86_l_269:
	/* 0x269: mov    DWORD PTR [r12],ebp */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_R12, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26d:
	/* 0x26d: mov    eax,0x7d */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 125ULL);
x86_l_272:
	/* 0x272: call   rax */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RAX);
		switch (X86_SIM_L_REG_TAG(X86_RAX)) {
		case X86_SIM_TAG_SCALAR:
			switch (__x86_target) {
			case 0x7dULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_ktime_get_boot_ns); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		case X86_SIM_TAG_HELPER_ID:
			switch (__x86_target) {
			case 0x7dULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_ktime_get_boot_ns); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_274:
	/* 0x274: mov    QWORD PTR [r12+0x8],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_279:
	/* 0x279: lea    rdx,[r14+0x60] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_27d:
	/* 0x27d: lea    rdi,[rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_282:
	/* 0x282: mov    eax,0x71 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 113ULL);
x86_l_287:
	/* 0x287: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_28c:
	/* 0x28c: call   rax */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RAX);
		switch (X86_SIM_L_REG_TAG(X86_RAX)) {
		case X86_SIM_TAG_SCALAR:
			switch (__x86_target) {
			case 0x71ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read_kernel); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		case X86_SIM_TAG_HELPER_ID:
			switch (__x86_target) {
			case 0x71ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read_kernel); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_28e:
	/* 0x28e: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_293:
	/* 0x293: xor    ebx,ebx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_295:
	/* 0x295: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_298:
	/* 0x298: je     2e5 <event_wake_up_new_task+0x2e5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x298, 0x2e5, x86_l_2e5);
x86_l_29a:
	/* 0x29a: add    rdx,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_29e:
	/* 0x29e: lea    rdi,[rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a3:
	/* 0x2a3: mov    eax,0x71 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 113ULL);
x86_l_2a8:
	/* 0x2a8: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_2ad:
	/* 0x2ad: call   rax */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RAX);
		switch (X86_SIM_L_REG_TAG(X86_RAX)) {
		case X86_SIM_TAG_SCALAR:
			switch (__x86_target) {
			case 0x71ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read_kernel); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		case X86_SIM_TAG_HELPER_ID:
			switch (__x86_target) {
			case 0x71ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read_kernel); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_2af:
	/* 0x2af: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b3:
	/* 0x2b3: test   eax,eax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_2b5:
	/* 0x2b5: je     2e5 <event_wake_up_new_task+0x2e5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2b5, 0x2e5, x86_l_2e5);
x86_l_2b7:
	/* 0x2b7: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2bc:
	/* 0x2bc: shl    eax,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 4ULL);
x86_l_2bf:
	/* 0x2bf: lea    rdx,[rcx+rax*1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2c3:
	/* 0x2c3: add    rdx,0x80 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 128ULL);
x86_l_2ca:
	/* 0x2ca: lea    rdi,[rsp+0x80] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2d2:
	/* 0x2d2: mov    eax,0x71 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 113ULL);
x86_l_2d7:
	/* 0x2d7: mov    esi,0x10 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 16ULL);
x86_l_2dc:
	/* 0x2dc: call   rax */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RAX);
		switch (X86_SIM_L_REG_TAG(X86_RAX)) {
		case X86_SIM_TAG_SCALAR:
			switch (__x86_target) {
			case 0x71ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read_kernel); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		case X86_SIM_TAG_HELPER_ID:
			switch (__x86_target) {
			case 0x71ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read_kernel); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_2de:
	/* 0x2de: mov    ebx,DWORD PTR [rsp+0x80] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2e5:
	/* 0x2e5: mov    DWORD PTR [r12+0x24],ebx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_R12, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2ea:
	/* 0x2ea: lea    rdi,[r12+0x68] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2ef:
	/* 0x2ef: lea    rsi,[r15+0x68] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2f3:
	/* 0x2f3: mov    edx,0x318 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 792ULL);
x86_l_2f8:
	/* 0x2f8: call   ca4 <__native_link_local_memcpy_any_dynamic> */
	X86_SIM_X86_CALL(x86_l_ca4, 0x2fdULL);
x86_l_2fd:
	/* 0x2fd: mov    rax,QWORD PTR [r15] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_300:
	/* 0x300: mov    rcx,QWORD PTR [r15+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_304:
	/* 0x304: mov    QWORD PTR [r12+0x10],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_309:
	/* 0x309: mov    QWORD PTR [r12+0x18],rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_R12, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_30e:
	/* 0x30e: lea    r13,[r12+0x50] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_313:
	/* 0x313: lea    rdx,[r14+0xd00] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3328ULL);
x86_l_31a:
	/* 0x31a: lea    rdi,[rsp+0x80] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_322:
	/* 0x322: mov    eax,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_327:
	/* 0x327: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_32c:
	/* 0x32c: call   rax */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RAX);
		switch (X86_SIM_L_REG_TAG(X86_RAX)) {
		case X86_SIM_TAG_SCALAR:
			switch (__x86_target) {
			case 0x4ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		case X86_SIM_TAG_HELPER_ID:
			switch (__x86_target) {
			case 0x4ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_32e:
	/* 0x32e: mov    rbp,QWORD PTR [rsp+0x80] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_336:
	/* 0x336: lea    rdi,[r12+0x58] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_33b:
	/* 0x33b: lea    rdx,[rbp+0x40] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_33f:
	/* 0x33f: mov    eax,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_344:
	/* 0x344: call   rax */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RAX);
		switch (X86_SIM_L_REG_TAG(X86_RAX)) {
		case X86_SIM_TAG_SCALAR:
			switch (__x86_target) {
			case 0x4ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		case X86_SIM_TAG_HELPER_ID:
			switch (__x86_target) {
			case 0x4ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_346:
	/* 0x346: lea    rdi,[r12+0x60] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_34b:
	/* 0x34b: lea    rdx,[rbp+0x30] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_34f:
	/* 0x34f: mov    eax,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_354:
	/* 0x354: call   rax */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RAX);
		switch (X86_SIM_L_REG_TAG(X86_RAX)) {
		case X86_SIM_TAG_SCALAR:
			switch (__x86_target) {
			case 0x4ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		case X86_SIM_TAG_HELPER_ID:
			switch (__x86_target) {
			case 0x4ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_356:
	/* 0x356: add    rbp,0x38 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 56ULL);
x86_l_35a:
	/* 0x35a: mov    eax,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_35f:
	/* 0x35f: mov    rdi,r13 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_362:
	/* 0x362: mov    rdx,rbp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_365:
	/* 0x365: call   rax */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RAX);
		switch (X86_SIM_L_REG_TAG(X86_RAX)) {
		case X86_SIM_TAG_SCALAR:
			switch (__x86_target) {
			case 0x4ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		case X86_SIM_TAG_HELPER_ID:
			switch (__x86_target) {
			case 0x4ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_367:
	/* 0x367: lea    r13,[r12+0x28] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_36c:
	/* 0x36c: lea    rdx,[r14+0xd70] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3440ULL);
x86_l_373:
	/* 0x373: lea    rdi,[rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_378:
	/* 0x378: mov    eax,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_37d:
	/* 0x37d: call   rax */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RAX);
		switch (X86_SIM_L_REG_TAG(X86_RAX)) {
		case X86_SIM_TAG_SCALAR:
			switch (__x86_target) {
			case 0x4ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		case X86_SIM_TAG_HELPER_ID:
			switch (__x86_target) {
			case 0x4ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_37f:
	/* 0x37f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_384:
	/* 0x384: lea    rdi,[rsp+0x80] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_38c:
	/* 0x38c: mov    eax,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_391:
	/* 0x391: mov    esi,0x48 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 72ULL);
x86_l_396:
	/* 0x396: call   rax */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RAX);
		switch (X86_SIM_L_REG_TAG(X86_RAX)) {
		case X86_SIM_TAG_SCALAR:
			switch (__x86_target) {
			case 0x4ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		case X86_SIM_TAG_HELPER_ID:
			switch (__x86_target) {
			case 0x4ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_398:
	/* 0x398: mov    edx,0x218 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 536ULL);
x86_l_39d:
	/* 0x39d: add    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_RUN_OP(X86_OP_ALU_MEM, X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 136ULL);
x86_l_3a5:
	/* 0x3a5: mov    eax,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_3aa:
	/* 0x3aa: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_3af:
	/* 0x3af: mov    rdi,r13 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_3b2:
	/* 0x3b2: call   rax */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RAX);
		switch (X86_SIM_L_REG_TAG(X86_RAX)) {
		case X86_SIM_TAG_SCALAR:
			switch (__x86_target) {
			case 0x4ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		case X86_SIM_TAG_HELPER_ID:
			switch (__x86_target) {
			case 0x4ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_3b4:
	/* 0x3b4: lea    rdi,[r12+0x2c] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_3b9:
	/* 0x3b9: mov    edx,0x4d8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 1240ULL);
x86_l_3be:
	/* 0x3be: add    rdx,QWORD PTR [rsp+0x90] */
	X86_SIM_RUN_OP(X86_OP_ALU_MEM, X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 144ULL);
x86_l_3c6:
	/* 0x3c6: mov    eax,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_3cb:
	/* 0x3cb: call   rax */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RAX);
		switch (X86_SIM_L_REG_TAG(X86_RAX)) {
		case X86_SIM_TAG_SCALAR:
			switch (__x86_target) {
			case 0x4ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		case X86_SIM_TAG_HELPER_ID:
			switch (__x86_target) {
			case 0x4ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_3cd:
	/* 0x3cd: lea    rdi,[r12+0x30] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3d2:
	/* 0x3d2: mov    rdx,QWORD PTR [rsp+0x98] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_3da:
	/* 0x3da: add    rdx,0x58 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 88ULL);
x86_l_3de:
	/* 0x3de: mov    eax,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_3e3:
	/* 0x3e3: call   rax */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RAX);
		switch (X86_SIM_L_REG_TAG(X86_RAX)) {
		case X86_SIM_TAG_SCALAR:
			switch (__x86_target) {
			case 0x4ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		case X86_SIM_TAG_HELPER_ID:
			switch (__x86_target) {
			case 0x4ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_3e5:
	/* 0x3e5: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3ed:
	/* 0x3ed: lea    rdx,[r14+0xb58] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2904ULL);
x86_l_3f4:
	/* 0x3f4: mov    rdi,rsp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_RSP, X86_WIDTH_64, 0, 0);
x86_l_3f7:
	/* 0x3f7: mov    eax,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_3fc:
	/* 0x3fc: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_401:
	/* 0x401: call   rax */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RAX);
		switch (X86_SIM_L_REG_TAG(X86_RAX)) {
		case X86_SIM_TAG_SCALAR:
			switch (__x86_target) {
			case 0x4ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		case X86_SIM_TAG_HELPER_ID:
			switch (__x86_target) {
			case 0x4ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_403:
	/* 0x403: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_407:
	/* 0x407: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_40a:
	/* 0x40a: je     519 <event_wake_up_new_task+0x519> */
	X86_SIM_X86_JCC(X86_CC_E, 0x40a, 0x519, x86_l_519);
x86_l_410:
	/* 0x410: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_418:
	/* 0x418: add    rdx,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_41c:
	/* 0x41c: lea    rdi,[rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_421:
	/* 0x421: mov    eax,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_426:
	/* 0x426: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_42b:
	/* 0x42b: call   rax */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RAX);
		switch (X86_SIM_L_REG_TAG(X86_RAX)) {
		case X86_SIM_TAG_SCALAR:
			switch (__x86_target) {
			case 0x4ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		case X86_SIM_TAG_HELPER_ID:
			switch (__x86_target) {
			case 0x4ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_42d:
	/* 0x42d: mov    rax,QWORD PTR [rsp] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_431:
	/* 0x431: movsxd rcx,DWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOVSX_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_436:
	/* 0x436: shl    rcx,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_43a:
	/* 0x43a: lea    rdx,[rax+rcx*1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_43e:
	/* 0x43e: add    rdx,0x80 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 128ULL);
x86_l_445:
	/* 0x445: lea    rdi,[rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_44a:
	/* 0x44a: mov    eax,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_44f:
	/* 0x44f: mov    esi,0x10 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 16ULL);
x86_l_454:
	/* 0x454: call   rax */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RAX);
		switch (X86_SIM_L_REG_TAG(X86_RAX)) {
		case X86_SIM_TAG_SCALAR:
			switch (__x86_target) {
			case 0x4ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		case X86_SIM_TAG_HELPER_ID:
			switch (__x86_target) {
			case 0x4ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_456:
	/* 0x456: lea    rdi,[r12+0x34] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_45b:
	/* 0x45b: mov    edx,0x158 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 344ULL);
x86_l_460:
	/* 0x460: add    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_RUN_OP(X86_OP_ALU_MEM, X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 72ULL);
x86_l_465:
	/* 0x465: mov    eax,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_46a:
	/* 0x46a: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_46f:
	/* 0x46f: call   rax */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RAX);
		switch (X86_SIM_L_REG_TAG(X86_RAX)) {
		case X86_SIM_TAG_SCALAR:
			switch (__x86_target) {
			case 0x4ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		case X86_SIM_TAG_HELPER_ID:
			switch (__x86_target) {
			case 0x4ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_471:
	/* 0x471: jmp    522 <event_wake_up_new_task+0x522> */
	X86_SIM_X86_JMP(0x471, 0x522, x86_l_522);
x86_l_476:
	/* 0x476: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_47e:
	/* 0x47e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)execve_val));
x86_l_485:
	/* 0x485: lea    rsi,[rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_48a:
	/* 0x48a: mov    eax,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_48f:
	/* 0x48f: call   rax */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RAX);
		switch (X86_SIM_L_REG_TAG(X86_RAX)) {
		case X86_SIM_TAG_SCALAR:
			switch (__x86_target) {
			case 0x1ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_map_lookup_elem); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		case X86_SIM_TAG_HELPER_ID:
			switch (__x86_target) {
			case 0x1ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_map_lookup_elem); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_491:
	/* 0x491: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_494:
	/* 0x494: je     c8c <event_wake_up_new_task+0xc8c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x494, 0xc8c, x86_l_c8c);
x86_l_49a:
	/* 0x49a: mov    edx,0x380 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 896ULL);
x86_l_49f:
	/* 0x49f: mov    rdi,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_4a2:
	/* 0x4a2: xor    esi,esi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_4a4:
	/* 0x4a4: mov    r12,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R12, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_4a7:
	/* 0x4a7: call   d4c <__native_link_local_memset_any_dynamic> */
	X86_SIM_X86_CALL(x86_l_d4c, 0x4acULL);
x86_l_4ac:
	/* 0x4ac: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)execve_map));
x86_l_4b3:
	/* 0x4b3: lea    rsi,[rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_4b8:
	/* 0x4b8: mov    eax,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_4bd:
	/* 0x4bd: mov    rdx,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_4c0:
	/* 0x4c0: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_4c2:
	/* 0x4c2: call   rax */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RAX);
		switch (X86_SIM_L_REG_TAG(X86_RAX)) {
		case X86_SIM_TAG_SCALAR:
			switch (__x86_target) {
			case 0x2ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_map_update_elem); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		case X86_SIM_TAG_HELPER_ID:
			switch (__x86_target) {
			case 0x2ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_map_update_elem); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_4c4:
	/* 0x4c4: test   eax,eax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_4c6:
	/* 0x4c6: je     79f <event_wake_up_new_task+0x79f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4c6, 0x79f, x86_l_79f);
x86_l_4cc:
	/* 0x4cc: mov    DWORD PTR [rsp+0x80],0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813889ULL);
x86_l_4d7:
	/* 0x4d7: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)execve_map_stats));
x86_l_4de:
	/* 0x4de: lea    rsi,[rsp+0x80] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_4e6:
	/* 0x4e6: mov    eax,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_4eb:
	/* 0x4eb: call   rax */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RAX);
		switch (X86_SIM_L_REG_TAG(X86_RAX)) {
		case X86_SIM_TAG_SCALAR:
			switch (__x86_target) {
			case 0x1ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_map_lookup_elem); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		case X86_SIM_TAG_HELPER_ID:
			switch (__x86_target) {
			case 0x1ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_map_lookup_elem); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_4ed:
	/* 0x4ed: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_4f0:
	/* 0x4f0: je     4f5 <event_wake_up_new_task+0x4f5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4f0, 0x4f5, x86_l_4f5);
x86_l_4f2:
	/* 0x4f2: inc    QWORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_ALU_MEM_UNARY, X86_RAX, X86_REG_NONE, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_4f5:
	/* 0x4f5: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)execve_map));
x86_l_4fc:
	/* 0x4fc: lea    rsi,[rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_501:
	/* 0x501: mov    eax,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_506:
	/* 0x506: call   rax */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RAX);
		switch (X86_SIM_L_REG_TAG(X86_RAX)) {
		case X86_SIM_TAG_SCALAR:
			switch (__x86_target) {
			case 0x1ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_map_lookup_elem); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		case X86_SIM_TAG_HELPER_ID:
			switch (__x86_target) {
			case 0x1ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_map_lookup_elem); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_508:
	/* 0x508: mov    r12,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R12, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_50b:
	/* 0x50b: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_50e:
	/* 0x50e: jne    24c <event_wake_up_new_task+0x24c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x50e, 0x24c, x86_l_24c);
x86_l_514:
	/* 0x514: jmp    c8c <event_wake_up_new_task+0xc8c> */
	X86_SIM_X86_JMP(0x514, 0xc8c, x86_l_c8c);
x86_l_519:
	/* 0x519: mov    DWORD PTR [r12+0x34],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 223338299392ULL);
x86_l_522:
	/* 0x522: lea    rbx,[r12+0x10] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RBX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_527:
	/* 0x527: lea    rdi,[r12+0x38] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_52c:
	/* 0x52c: mov    r13d,0x158 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, 0, 344ULL);
x86_l_532:
	/* 0x532: mov    rdx,QWORD PTR [rsp+0xa0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_53a:
	/* 0x53a: add    rdx,r13 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_R13, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_53d:
	/* 0x53d: mov    eax,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_542:
	/* 0x542: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_547:
	/* 0x547: call   rax */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RAX);
		switch (X86_SIM_L_REG_TAG(X86_RAX)) {
		case X86_SIM_TAG_SCALAR:
			switch (__x86_target) {
			case 0x4ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		case X86_SIM_TAG_HELPER_ID:
			switch (__x86_target) {
			case 0x4ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_549:
	/* 0x549: lea    rdi,[r12+0x3c] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_54e:
	/* 0x54e: mov    edx,0x118 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 280ULL);
x86_l_553:
	/* 0x553: add    rdx,QWORD PTR [rsp+0xa8] */
	X86_SIM_RUN_OP(X86_OP_ALU_MEM, X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 168ULL);
x86_l_55b:
	/* 0x55b: mov    eax,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_560:
	/* 0x560: call   rax */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RAX);
		switch (X86_SIM_L_REG_TAG(X86_RAX)) {
		case X86_SIM_TAG_SCALAR:
			switch (__x86_target) {
			case 0x4ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		case X86_SIM_TAG_HELPER_ID:
			switch (__x86_target) {
			case 0x4ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_562:
	/* 0x562: lea    rdi,[r12+0x40] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_567:
	/* 0x567: mov    ebp,0x98 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, 0, 152ULL);
x86_l_56c:
	/* 0x56c: mov    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_574:
	/* 0x574: add    rdx,rbp */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_577:
	/* 0x577: mov    eax,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_57c:
	/* 0x57c: call   rax */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RAX);
		switch (X86_SIM_L_REG_TAG(X86_RAX)) {
		case X86_SIM_TAG_SCALAR:
			switch (__x86_target) {
			case 0x4ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		case X86_SIM_TAG_HELPER_ID:
			switch (__x86_target) {
			case 0x4ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_57e:
	/* 0x57e: lea    rdi,[r12+0x44] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_583:
	/* 0x583: add    rbp,QWORD PTR [rsp+0xb8] */
	X86_SIM_RUN_OP(X86_OP_ALU_MEM, X86_RBP, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 184ULL);
x86_l_58b:
	/* 0x58b: mov    eax,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_590:
	/* 0x590: mov    rdx,rbp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_593:
	/* 0x593: call   rax */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RAX);
		switch (X86_SIM_L_REG_TAG(X86_RAX)) {
		case X86_SIM_TAG_SCALAR:
			switch (__x86_target) {
			case 0x4ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		case X86_SIM_TAG_HELPER_ID:
			switch (__x86_target) {
			case 0x4ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_595:
	/* 0x595: lea    rdi,[r12+0x48] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_59a:
	/* 0x59a: mov    rdx,QWORD PTR [rsp+0xc0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_5a2:
	/* 0x5a2: add    rdx,0x58 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 88ULL);
x86_l_5a6:
	/* 0x5a6: mov    eax,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_5ab:
	/* 0x5ab: call   rax */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RAX);
		switch (X86_SIM_L_REG_TAG(X86_RAX)) {
		case X86_SIM_TAG_SCALAR:
			switch (__x86_target) {
			case 0x4ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		case X86_SIM_TAG_HELPER_ID:
			switch (__x86_target) {
			case 0x4ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_5ad:
	/* 0x5ad: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_5b6:
	/* 0x5b6: lea    rdx,[r14+0xa78] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2680ULL);
x86_l_5bd:
	/* 0x5bd: lea    rdi,[rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_5c2:
	/* 0x5c2: mov    eax,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_5c7:
	/* 0x5c7: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_5cc:
	/* 0x5cc: call   rax */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RAX);
		switch (X86_SIM_L_REG_TAG(X86_RAX)) {
		case X86_SIM_TAG_SCALAR:
			switch (__x86_target) {
			case 0x4ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		case X86_SIM_TAG_HELPER_ID:
			switch (__x86_target) {
			case 0x4ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_5ce:
	/* 0x5ce: mov    edx,0x5a0 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 1440ULL);
x86_l_5d3:
	/* 0x5d3: add    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_ALU_MEM, X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 64ULL);
x86_l_5d8:
	/* 0x5d8: mov    rdi,rsp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_RSP, X86_WIDTH_64, 0, 0);
x86_l_5db:
	/* 0x5db: mov    eax,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_5e0:
	/* 0x5e0: call   rax */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RAX);
		switch (X86_SIM_L_REG_TAG(X86_RAX)) {
		case X86_SIM_TAG_SCALAR:
			switch (__x86_target) {
			case 0x4ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		case X86_SIM_TAG_HELPER_ID:
			switch (__x86_target) {
			case 0x4ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_5e2:
	/* 0x5e2: add    r13,QWORD PTR [rsp] */
	X86_SIM_RUN_OP(X86_OP_ALU_MEM, X86_R13, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_5e6:
	/* 0x5e6: lea    rdi,[r12+0x4c] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_5eb:
	/* 0x5eb: mov    eax,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_5f0:
	/* 0x5f0: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_5f5:
	/* 0x5f5: mov    rdx,r13 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_5f8:
	/* 0x5f8: call   rax */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RAX);
		switch (X86_SIM_L_REG_TAG(X86_RAX)) {
		case X86_SIM_TAG_SCALAR:
			switch (__x86_target) {
			case 0x4ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		case X86_SIM_TAG_HELPER_ID:
			switch (__x86_target) {
			case 0x4ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_5fa:
	/* 0x5fa: test   BYTE PTR [r15+0x23],0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 150323855362ULL);
x86_l_5ff:
	/* 0x5ff: jne    609 <event_wake_up_new_task+0x609> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x5ff, 0x609, x86_l_609);
x86_l_601:
	/* 0x601: cmp    DWORD PTR [r12+0x24],0x1 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 154618822657ULL);
x86_l_607:
	/* 0x607: jne    60f <event_wake_up_new_task+0x60f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x607, 0x60f, x86_l_60f);
x86_l_609:
	/* 0x609: or     BYTE PTR [r12+0x23],0x2 */
	X86_SIM_RUN_OP(X86_OP_ALU_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 150323855362ULL);
x86_l_60f:
	/* 0x60f: mov    BYTE PTR [rsp+0x40],0x17 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 274877906967ULL);
x86_l_614:
	/* 0x614: mov    DWORD PTR [rsp+0x44],0x38 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 292057776184ULL);
x86_l_61c:
	/* 0x61c: mov    rax,QWORD PTR [r12+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_621:
	/* 0x621: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_626:
	/* 0x626: mov    rax,QWORD PTR [rbx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_629:
	/* 0x629: mov    rcx,QWORD PTR [rbx+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_62d:
	/* 0x62d: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_632:
	/* 0x632: mov    QWORD PTR [rsp+0x58],rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_637:
	/* 0x637: mov    eax,DWORD PTR [r12] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_63b:
	/* 0x63b: mov    DWORD PTR [rsp+0x60],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_63f:
	/* 0x63f: lea    rdx,[r14+0xaf0] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2800ULL);
x86_l_646:
	/* 0x646: lea    rdi,[rsp+0x80] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_64e:
	/* 0x64e: mov    eax,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_653:
	/* 0x653: mov    ecx,0x71 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 113ULL);
x86_l_658:
	/* 0x658: mov    esi,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_65d:
	/* 0x65d: call   rcx */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RCX);
		switch (X86_SIM_L_REG_TAG(X86_RCX)) {
		case X86_SIM_TAG_SCALAR:
			switch (__x86_target) {
			case 0x71ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read_kernel); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		case X86_SIM_TAG_HELPER_ID:
			switch (__x86_target) {
			case 0x71ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read_kernel); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_65f:
	/* 0x65f: mov    eax,DWORD PTR [rsp+0x80] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_666:
	/* 0x666: mov    DWORD PTR [rsp+0x64],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 100ULL);
x86_l_66a:
	/* 0x66a: mov    rax,QWORD PTR [r12+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_66f:
	/* 0x66f: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_674:
	/* 0x674: mov    eax,DWORD PTR [r12+0x24] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_679:
	/* 0x679: mov    DWORD PTR [rsp+0x68],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_67d:
	/* 0x67d: mov    eax,DWORD PTR [r12+0x20] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_682:
	/* 0x682: mov    DWORD PTR [rsp+0x6c],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_686:
	/* 0x686: mov    DWORD PTR [rsp+0x3c],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_68e:
	/* 0x68e: lea    rdi,[rsp+0x80] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_696:
	/* 0x696: xor    r15d,r15d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_699:
	/* 0x699: mov    edx,0x90 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 144ULL);
x86_l_69e:
	/* 0x69e: xor    esi,esi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_6a0:
	/* 0x6a0: call   d4c <__native_link_local_memset_any_dynamic> */
	X86_SIM_X86_CALL(x86_l_d4c, 0x6a5ULL);
x86_l_6a5:
	/* 0x6a5: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)tg_conf_map));
x86_l_6ac:
	/* 0x6ac: lea    rsi,[rsp+0x3c] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_6b1:
	/* 0x6b1: mov    eax,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_6b6:
	/* 0x6b6: call   rax */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RAX);
		switch (X86_SIM_L_REG_TAG(X86_RAX)) {
		case X86_SIM_TAG_SCALAR:
			switch (__x86_target) {
			case 0x1ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_map_lookup_elem); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		case X86_SIM_TAG_HELPER_ID:
			switch (__x86_target) {
			case 0x1ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_map_lookup_elem); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_6b8:
	/* 0x6b8: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_6bb:
	/* 0x6bb: je     6c7 <event_wake_up_new_task+0x6c7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6bb, 0x6c7, x86_l_6c7);
x86_l_6bd:
	/* 0x6bd: mov    rbx,QWORD PTR [rax+0x20] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6c1:
	/* 0x6c1: mov    r15d,DWORD PTR [rax+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6c5:
	/* 0x6c5: jmp    6c9 <event_wake_up_new_task+0x6c9> */
	X86_SIM_X86_JMP(0x6c5, 0x6c9, x86_l_6c9);
x86_l_6c7:
	/* 0x6c7: xor    ebx,ebx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_6c9:
	/* 0x6c9: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_6d2:
	/* 0x6d2: add    r14,0xf88 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 3976ULL);
x86_l_6d9:
	/* 0x6d9: mov    rdi,rsp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_RSP, X86_WIDTH_64, 0, 0);
x86_l_6dc:
	/* 0x6dc: mov    eax,0x71 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 113ULL);
x86_l_6e1:
	/* 0x6e1: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_6e6:
	/* 0x6e6: mov    rdx,r14 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_6e9:
	/* 0x6e9: call   rax */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RAX);
		switch (X86_SIM_L_REG_TAG(X86_RAX)) {
		case X86_SIM_TAG_SCALAR:
			switch (__x86_target) {
			case 0x71ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read_kernel); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		case X86_SIM_TAG_HELPER_ID:
			switch (__x86_target) {
			case 0x71ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read_kernel); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_6eb:
	/* 0x6eb: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6ef:
	/* 0x6ef: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_6f2:
	/* 0x6f2: je     73e <event_wake_up_new_task+0x73e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6f2, 0x73e, x86_l_73e);
x86_l_6f4:
	/* 0x6f4: cmp    rbx,0x63677270 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 1667723888ULL);
x86_l_6fb:
	/* 0x6fb: jne    70f <event_wake_up_new_task+0x70f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x6fb, 0x70f, x86_l_70f);
x86_l_6fd:
	/* 0x6fd: add    rdx,0x78 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 120ULL);
x86_l_701:
	/* 0x701: lea    rdi,[rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_706:
	/* 0x706: mov    eax,0x71 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 113ULL);
x86_l_70b:
	/* 0x70b: call   rax */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RAX);
		switch (X86_SIM_L_REG_TAG(X86_RAX)) {
		case X86_SIM_TAG_SCALAR:
			switch (__x86_target) {
			case 0x71ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read_kernel); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		case X86_SIM_TAG_HELPER_ID:
			switch (__x86_target) {
			case 0x71ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read_kernel); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_70d:
	/* 0x70d: jmp    73e <event_wake_up_new_task+0x73e> */
	X86_SIM_X86_JMP(0x70d, 0x73e, x86_l_73e);
x86_l_70f:
	/* 0x70f: cmp    r15d,0xb */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 11ULL);
x86_l_713:
	/* 0x713: ja     73e <event_wake_up_new_task+0x73e> */
	X86_SIM_X86_JCC(X86_CC_A, 0x713, 0x73e, x86_l_73e);
x86_l_715:
	/* 0x715: mov    eax,r15d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_R15, X86_WIDTH_32, 0, 0);
x86_l_718:
	/* 0x718: lea    rdx,[rdx+rax*8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 0ULL);
x86_l_71c:
	/* 0x71c: lea    rdi,[rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_721:
	/* 0x721: mov    eax,0x71 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 113ULL);
x86_l_726:
	/* 0x726: call   rax */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RAX);
		switch (X86_SIM_L_REG_TAG(X86_RAX)) {
		case X86_SIM_TAG_SCALAR:
			switch (__x86_target) {
			case 0x71ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read_kernel); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		case X86_SIM_TAG_HELPER_ID:
			switch (__x86_target) {
			case 0x71ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read_kernel); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_728:
	/* 0x728: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_72d:
	/* 0x72d: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_730:
	/* 0x730: je     73e <event_wake_up_new_task+0x73e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x730, 0x73e, x86_l_73e);
x86_l_732:
	/* 0x732: lea    rdi,[rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_737:
	/* 0x737: mov    eax,0x71 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 113ULL);
x86_l_73c:
	/* 0x73c: call   rax */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RAX);
		switch (X86_SIM_L_REG_TAG(X86_RAX)) {
		case X86_SIM_TAG_SCALAR:
			switch (__x86_target) {
			case 0x71ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read_kernel); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		case X86_SIM_TAG_HELPER_ID:
			switch (__x86_target) {
			case 0x71ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read_kernel); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_73e:
	/* 0x73e: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_743:
	/* 0x743: test   r14,r14 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_746:
	/* 0x746: je     872 <event_wake_up_new_task+0x872> */
	X86_SIM_X86_JCC(X86_CC_E, 0x746, 0x872, x86_l_872);
x86_l_74c:
	/* 0x74c: cmp    rbx,0x63677270 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 1667723888ULL);
x86_l_753:
	/* 0x753: jne    75e <event_wake_up_new_task+0x75e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x753, 0x75e, x86_l_75e);
x86_l_755:
	/* 0x755: mov    eax,0x50 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 80ULL);
x86_l_75a:
	/* 0x75a: call   rax */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RAX);
		switch (X86_SIM_L_REG_TAG(X86_RAX)) {
		case X86_SIM_TAG_SCALAR:
			switch (__x86_target) {
			case 0x50ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_get_current_cgroup_id); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		case X86_SIM_TAG_HELPER_ID:
			switch (__x86_target) {
			case 0x50ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_get_current_cgroup_id); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_75c:
	/* 0x75c: jmp    7d0 <event_wake_up_new_task+0x7d0> */
	X86_SIM_X86_JMP(0x75c, 0x7d0, x86_l_7d0);
x86_l_75e:
	/* 0x75e: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_767:
	/* 0x767: lea    rdx,[r14+0x100] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_76e:
	/* 0x76e: lea    rdi,[rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_773:
	/* 0x773: mov    eax,0x71 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 113ULL);
x86_l_778:
	/* 0x778: call   rax */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RAX);
		switch (X86_SIM_L_REG_TAG(X86_RAX)) {
		case X86_SIM_TAG_SCALAR:
			switch (__x86_target) {
			case 0x71ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read_kernel); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		case X86_SIM_TAG_HELPER_ID:
			switch (__x86_target) {
			case 0x71ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read_kernel); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_77a:
	/* 0x77a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_77f:
	/* 0x77f: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_788:
	/* 0x788: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_78b:
	/* 0x78b: je     7ce <event_wake_up_new_task+0x7ce> */
	X86_SIM_X86_JCC(X86_CC_E, 0x78b, 0x7ce, x86_l_7ce);
x86_l_78d:
	/* 0x78d: add    rdx,0x60 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 96ULL);
x86_l_791:
	/* 0x791: mov    eax,0x71 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 113ULL);
x86_l_796:
	/* 0x796: call   rax */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RAX);
		switch (X86_SIM_L_REG_TAG(X86_RAX)) {
		case X86_SIM_TAG_SCALAR:
			switch (__x86_target) {
			case 0x71ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read_kernel); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		case X86_SIM_TAG_HELPER_ID:
			switch (__x86_target) {
			case 0x71ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read_kernel); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_798:
	/* 0x798: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_79d:
	/* 0x79d: jmp    7d0 <event_wake_up_new_task+0x7d0> */
	X86_SIM_X86_JMP(0x79d, 0x7d0, x86_l_7d0);
x86_l_79f:
	/* 0x79f: mov    DWORD PTR [rsp+0x80],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_7aa:
	/* 0x7aa: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)execve_map_stats));
x86_l_7b1:
	/* 0x7b1: lea    rsi,[rsp+0x80] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_7b9:
	/* 0x7b9: mov    eax,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_7be:
	/* 0x7be: call   rax */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RAX);
		switch (X86_SIM_L_REG_TAG(X86_RAX)) {
		case X86_SIM_TAG_SCALAR:
			switch (__x86_target) {
			case 0x1ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_map_lookup_elem); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		case X86_SIM_TAG_HELPER_ID:
			switch (__x86_target) {
			case 0x1ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_map_lookup_elem); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_7c0:
	/* 0x7c0: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_7c3:
	/* 0x7c3: jne    4f2 <event_wake_up_new_task+0x4f2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x7c3, 0x4f2, x86_l_4f2);
x86_l_7c9:
	/* 0x7c9: jmp    4f5 <event_wake_up_new_task+0x4f5> */
	X86_SIM_X86_JMP(0x7c9, 0x4f5, x86_l_4f5);
x86_l_7ce:
	/* 0x7ce: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_7d0:
	/* 0x7d0: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_7d8:
	/* 0x7d8: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_7db:
	/* 0x7db: je     809 <event_wake_up_new_task+0x809> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7db, 0x809, x86_l_809);
x86_l_7dd:
	/* 0x7dd: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7e2:
	/* 0x7e2: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)tg_cgtracker_map));
x86_l_7e9:
	/* 0x7e9: lea    rsi,[rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7ee:
	/* 0x7ee: mov    eax,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_7f3:
	/* 0x7f3: call   rax */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RAX);
		switch (X86_SIM_L_REG_TAG(X86_RAX)) {
		case X86_SIM_TAG_SCALAR:
			switch (__x86_target) {
			case 0x1ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_map_lookup_elem); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		case X86_SIM_TAG_HELPER_ID:
			switch (__x86_target) {
			case 0x1ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_map_lookup_elem); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_7f5:
	/* 0x7f5: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_7f8:
	/* 0x7f8: je     7ff <event_wake_up_new_task+0x7ff> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7f8, 0x7ff, x86_l_7ff);
x86_l_7fa:
	/* 0x7fa: mov    rax,QWORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7fd:
	/* 0x7fd: jmp    801 <event_wake_up_new_task+0x801> */
	X86_SIM_X86_JMP(0x7fd, 0x801, x86_l_801);
x86_l_7ff:
	/* 0x7ff: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_801:
	/* 0x801: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_809:
	/* 0x809: add    r14,0x100 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 256ULL);
x86_l_810:
	/* 0x810: mov    rdi,rsp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_RSP, X86_WIDTH_64, 0, 0);
x86_l_813:
	/* 0x813: mov    eax,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_818:
	/* 0x818: mov    ecx,0x71 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 113ULL);
x86_l_81d:
	/* 0x81d: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_822:
	/* 0x822: mov    rdx,r14 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_825:
	/* 0x825: call   rcx */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RCX);
		switch (X86_SIM_L_REG_TAG(X86_RCX)) {
		case X86_SIM_TAG_SCALAR:
			switch (__x86_target) {
			case 0x71ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read_kernel); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		case X86_SIM_TAG_HELPER_ID:
			switch (__x86_target) {
			case 0x71ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read_kernel); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_827:
	/* 0x827: mov    rax,QWORD PTR [rsp] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_82b:
	/* 0x82b: add    rax,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_82f:
	/* 0x82f: lea    rdi,[rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_834:
	/* 0x834: mov    ecx,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_839:
	/* 0x839: mov    r8d,0x71 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, 0, 113ULL);
x86_l_83f:
	/* 0x83f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_843:
	/* 0x843: add    rdx,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_847:
	/* 0x847: mov    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_84c:
	/* 0x84c: call   r8 */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_R8);
		switch (X86_SIM_L_REG_TAG(X86_R8)) {
		case X86_SIM_TAG_SCALAR:
			switch (__x86_target) {
			case 0x71ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read_kernel); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		case X86_SIM_TAG_HELPER_ID:
			switch (__x86_target) {
			case 0x71ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read_kernel); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_84f:
	/* 0x84f: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_852:
	/* 0x852: jne    872 <event_wake_up_new_task+0x872> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x852, 0x872, x86_l_872);
x86_l_854:
	/* 0x854: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_859:
	/* 0x859: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_85c:
	/* 0x85c: je     872 <event_wake_up_new_task+0x872> */
	X86_SIM_X86_JCC(X86_CC_E, 0x85c, 0x872, x86_l_872);
x86_l_85e:
	/* 0x85e: lea    rdi,[rsp+0x90] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_866:
	/* 0x866: mov    eax,0x2d */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 45ULL);
x86_l_86b:
	/* 0x86b: mov    esi,0x80 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 128ULL);
x86_l_870:
	/* 0x870: call   rax */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RAX);
		switch (X86_SIM_L_REG_TAG(X86_RAX)) {
		case X86_SIM_TAG_SCALAR:
			switch (__x86_target) {
			case 0x2dULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read_str); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		case X86_SIM_TAG_HELPER_ID:
			switch (__x86_target) {
			case 0x2dULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_probe_read_str); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_872:
	/* 0x872: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_87a:
	/* 0x87a: mov    QWORD PTR [rsp],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_87e:
	/* 0x87e: mov    DWORD PTR [rsp+0x7c],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 532575944704ULL);
x86_l_886:
	/* 0x886: mov    r15,QWORD PTR [rsp+0x70] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_88b:
	/* 0x88b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)cgroup_rate_options_map));
x86_l_892:
	/* 0x892: lea    rsi,[rsp+0x7c] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_897:
	/* 0x897: mov    eax,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_89c:
	/* 0x89c: call   rax */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RAX);
		switch (X86_SIM_L_REG_TAG(X86_RAX)) {
		case X86_SIM_TAG_SCALAR:
			switch (__x86_target) {
			case 0x1ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_map_lookup_elem); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		case X86_SIM_TAG_HELPER_ID:
			switch (__x86_target) {
			case 0x1ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_map_lookup_elem); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_89e:
	/* 0x89e: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_8a1:
	/* 0x8a1: mov    rbx,QWORD PTR [rsp+0x110] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_8a9:
	/* 0x8a9: je     b68 <event_wake_up_new_task+0xb68> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8a9, 0xb68, x86_l_b68);
x86_l_8af:
	/* 0x8af: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8b3:
	/* 0x8b3: test   r12,r12 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_8b6:
	/* 0x8b6: je     b68 <event_wake_up_new_task+0xb68> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8b6, 0xb68, x86_l_b68);
x86_l_8bc:
	/* 0x8bc: mov    r13,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R13, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_8bf:
	/* 0x8bf: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)cgroup_rate_map));
x86_l_8c6:
	/* 0x8c6: mov    rsi,rsp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_RSP, X86_WIDTH_64, 0, 0);
x86_l_8c9:
	/* 0x8c9: mov    eax,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_8ce:
	/* 0x8ce: call   rax */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RAX);
		switch (X86_SIM_L_REG_TAG(X86_RAX)) {
		case X86_SIM_TAG_SCALAR:
			switch (__x86_target) {
			case 0x1ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_map_lookup_elem); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		case X86_SIM_TAG_HELPER_ID:
			switch (__x86_target) {
			case 0x1ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_map_lookup_elem); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_8d0:
	/* 0x8d0: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_8d3:
	/* 0x8d3: je     90d <event_wake_up_new_task+0x90d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8d3, 0x90d, x86_l_90d);
x86_l_8d5:
	/* 0x8d5: mov    r14,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R14, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_8d8:
	/* 0x8d8: mov    rsi,QWORD PTR [rax+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_8dc:
	/* 0x8dc: mov    rax,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_8df:
	/* 0x8df: sub    rax,rsi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB, 0);
x86_l_8e2:
	/* 0x8e2: cmp    rax,r12 */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RAX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_8e5:
	/* 0x8e5: jbe    935 <event_wake_up_new_task+0x935> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x8e5, 0x935, x86_l_935);
x86_l_8e7:
	/* 0x8e7: lea    rcx,[r12+r12*1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_8eb:
	/* 0x8eb: cmp    rax,rcx */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RAX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_8ee:
	/* 0x8ee: jbe    93e <event_wake_up_new_task+0x93e> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x8ee, 0x93e, x86_l_93e);
x86_l_8f0:
	/* 0x8f0: mov    rax,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_8f3:
	/* 0x8f3: or     rax,r12 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_R12, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_8f6:
	/* 0x8f6: shr    rax,0x20 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_8fa:
	/* 0x8fa: je     982 <event_wake_up_new_task+0x982> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8fa, 0x982, x86_l_982);
x86_l_900:
	/* 0x900: mov    rax,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_903:
	/* 0x903: xor    edx,edx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_905:
	/* 0x905: div    r12 */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_908:
	/* 0x908: jmp    98a <event_wake_up_new_task+0x98a> */
	X86_SIM_X86_JMP(0x908, 0x98a, x86_l_98a);
x86_l_90d:
	/* 0x90d: mov    QWORD PTR [rsp+0x10],0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_916:
	/* 0x916: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_91f:
	/* 0x91f: mov    rax,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_922:
	/* 0x922: or     rax,r12 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_R12, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_925:
	/* 0x925: shr    rax,0x20 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_929:
	/* 0x929: je     946 <event_wake_up_new_task+0x946> */
	X86_SIM_X86_JCC(X86_CC_E, 0x929, 0x946, x86_l_946);
x86_l_92b:
	/* 0x92b: mov    rax,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_92e:
	/* 0x92e: xor    edx,edx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_930:
	/* 0x930: div    r12 */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_933:
	/* 0x933: jmp    94e <event_wake_up_new_task+0x94e> */
	X86_SIM_X86_JMP(0x933, 0x94e, x86_l_94e);
x86_l_935:
	/* 0x935: mov    rcx,QWORD PTR [r14] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_938:
	/* 0x938: mov    rdx,QWORD PTR [r14+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_93c:
	/* 0x93c: jmp    99c <event_wake_up_new_task+0x99c> */
	X86_SIM_X86_JMP(0x93c, 0x99c, x86_l_99c);
x86_l_93e:
	/* 0x93e: mov    rdx,QWORD PTR [r14] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_941:
	/* 0x941: add    rsi,r12 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_R12, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_944:
	/* 0x944: jmp    992 <event_wake_up_new_task+0x992> */
	X86_SIM_X86_JMP(0x944, 0x992, x86_l_992);
x86_l_946:
	/* 0x946: mov    eax,r15d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_R15, X86_WIDTH_32, 0, 0);
x86_l_949:
	/* 0x949: xor    edx,edx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_94b:
	/* 0x94b: div    r12d */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_R12, X86_WIDTH_32, 0, 0);
x86_l_94e:
	/* 0x94e: sub    r15,rdx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R15, X86_RDX, X86_WIDTH_64, X86_ALU_SUB, 0);
x86_l_951:
	/* 0x951: mov    QWORD PTR [rsp+0x20],r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_956:
	/* 0x956: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_95f:
	/* 0x95f: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_968:
	/* 0x968: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)cgroup_rate_map));
x86_l_96f:
	/* 0x96f: lea    rdx,[rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_974:
	/* 0x974: mov    eax,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_979:
	/* 0x979: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_97b:
	/* 0x97b: call   rax */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RAX);
		switch (X86_SIM_L_REG_TAG(X86_RAX)) {
		case X86_SIM_TAG_SCALAR:
			switch (__x86_target) {
			case 0x2ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_map_update_elem); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		case X86_SIM_TAG_HELPER_ID:
			switch (__x86_target) {
			case 0x2ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_map_update_elem); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_97d:
	/* 0x97d: jmp    b68 <event_wake_up_new_task+0xb68> */
	X86_SIM_X86_JMP(0x97d, 0xb68, x86_l_b68);
x86_l_982:
	/* 0x982: mov    eax,r15d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_R15, X86_WIDTH_32, 0, 0);
x86_l_985:
	/* 0x985: xor    edx,edx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_987:
	/* 0x987: div    r12d */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_R12, X86_WIDTH_32, 0, 0);
x86_l_98a:
	/* 0x98a: mov    rsi,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_98d:
	/* 0x98d: sub    rsi,rdx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RDX, X86_WIDTH_64, X86_ALU_SUB, 0);
x86_l_990:
	/* 0x990: xor    edx,edx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_992:
	/* 0x992: mov    QWORD PTR [r14+0x8],rdx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_996:
	/* 0x996: mov    QWORD PTR [r14+0x10],rsi */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_R14, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_99a:
	/* 0x99a: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_99c:
	/* 0x99c: inc    rcx */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_99f:
	/* 0x99f: mov    QWORD PTR [r14],rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9a2:
	/* 0x9a2: mov    rax,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_9a5:
	/* 0x9a5: sub    rax,r15 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_R15, X86_WIDTH_64, X86_ALU_SUB, 0);
x86_l_9a8:
	/* 0x9a8: add    rax,rsi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_9ab:
	/* 0x9ab: imul   rax,rdx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_IMUL, 0);
x86_l_9af:
	/* 0x9af: mov    rdx,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_9b2:
	/* 0x9b2: or     rdx,r12 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_R12, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_9b5:
	/* 0x9b5: shr    rdx,0x20 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_9b9:
	/* 0x9b9: je     9c2 <event_wake_up_new_task+0x9c2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9b9, 0x9c2, x86_l_9c2);
x86_l_9bb:
	/* 0x9bb: xor    edx,edx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_9bd:
	/* 0x9bd: div    r12 */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_9c0:
	/* 0x9c0: jmp    9c7 <event_wake_up_new_task+0x9c7> */
	X86_SIM_X86_JMP(0x9c0, 0x9c7, x86_l_9c7);
x86_l_9c2:
	/* 0x9c2: xor    edx,edx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_9c4:
	/* 0x9c4: div    r12d */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_R12, X86_WIDTH_32, 0, 0);
x86_l_9c7:
	/* 0x9c7: add    rax,rcx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_9ca:
	/* 0x9ca: mov    QWORD PTR [r14+0x18],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_9ce:
	/* 0x9ce: cmp    QWORD PTR [r14+0x20],0x0 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_9d3:
	/* 0x9d3: jne    c8c <event_wake_up_new_task+0xc8c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x9d3, 0xc8c, x86_l_c8c);
x86_l_9d9:
	/* 0x9d9: cmp    rax,QWORD PTR [r13+0x0] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_9dd:
	/* 0x9dd: jb     b68 <event_wake_up_new_task+0xb68> */
	X86_SIM_X86_JCC(X86_CC_B, 0x9dd, 0xb68, x86_l_b68);
x86_l_9e3:
	/* 0x9e3: mov    QWORD PTR [r14+0x20],r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_R14, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_9e7:
	/* 0x9e7: mov    DWORD PTR [rsp+0x3c],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_9ef:
	/* 0x9ef: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)throttle_heap_map));
x86_l_9f6:
	/* 0x9f6: lea    rsi,[rsp+0x3c] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_9fb:
	/* 0x9fb: mov    eax,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_a00:
	/* 0xa00: call   rax */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RAX);
		switch (X86_SIM_L_REG_TAG(X86_RAX)) {
		case X86_SIM_TAG_SCALAR:
			switch (__x86_target) {
			case 0x1ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_map_lookup_elem); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		case X86_SIM_TAG_HELPER_ID:
			switch (__x86_target) {
			case 0x1ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_map_lookup_elem); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_a02:
	/* 0xa02: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_a05:
	/* 0xa05: je     b5d <event_wake_up_new_task+0xb5d> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa05, 0xb5d, x86_l_b5d);
x86_l_a0b:
	/* 0xa0b: mov    r12,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R12, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_a0e:
	/* 0xa0e: mov    DWORD PTR [rax+0x4],0xa0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869344ULL);
x86_l_a15:
	/* 0xa15: mov    QWORD PTR [rax+0x8],r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a19:
	/* 0xa19: mov    WORD PTR [rax],0x1b */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 27ULL);
x86_l_a1e:
	/* 0xa1e: mov    rdi,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_a21:
	/* 0xa21: add    rdi,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_a25:
	/* 0xa25: lea    rsi,[rsp+0x80] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_a2d:
	/* 0xa2d: mov    edx,0x90 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 144ULL);
x86_l_a32:
	/* 0xa32: call   ca4 <__native_link_local_memcpy_any_dynamic> */
	X86_SIM_X86_CALL(x86_l_ca4, 0xa37ULL);
x86_l_a37:
	/* 0xa37: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_a3f:
	/* 0xa3f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)tg_conf_map));
x86_l_a46:
	/* 0xa46: lea    rsi,[rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a4b:
	/* 0xa4b: mov    eax,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_a50:
	/* 0xa50: call   rax */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RAX);
		switch (X86_SIM_L_REG_TAG(X86_RAX)) {
		case X86_SIM_TAG_SCALAR:
			switch (__x86_target) {
			case 0x1ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_map_lookup_elem); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		case X86_SIM_TAG_HELPER_ID:
			switch (__x86_target) {
			case 0x1ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_map_lookup_elem); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_a52:
	/* 0xa52: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_a55:
	/* 0xa55: je     ac9 <event_wake_up_new_task+0xac9> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa55, 0xac9, x86_l_ac9);
x86_l_a57:
	/* 0xa57: cmp    BYTE PTR [rax+0x28],0x0 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_a5b:
	/* 0xa5b: je     ac9 <event_wake_up_new_task+0xac9> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa5b, 0xac9, x86_l_ac9);
x86_l_a5d:
	/* 0xa5d: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RSI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)tcpmon_map));
x86_l_a64:
	/* 0xa64: mov    eax,0x19 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 25ULL);
x86_l_a69:
	/* 0xa69: mov    edx,0xffffffff */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 4294967295ULL);
x86_l_a6e:
	/* 0xa6e: mov    r8d,0xa0 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, 0, 160ULL);
x86_l_a74:
	/* 0xa74: mov    rdi,rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_a77:
	/* 0xa77: mov    rcx,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_a7a:
	/* 0xa7a: call   rax */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RAX);
		switch (X86_SIM_L_REG_TAG(X86_RAX)) {
		case X86_SIM_TAG_SCALAR:
			switch (__x86_target) {
			case 0x19ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_perf_event_output); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		case X86_SIM_TAG_HELPER_ID:
			switch (__x86_target) {
			case 0x19ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_perf_event_output); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_a7c:
	/* 0xa7c: test   eax,eax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_a7e:
	/* 0xa7e: jns    b5d <event_wake_up_new_task+0xb5d> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xa7e, 0xb5d, x86_l_b5d);
x86_l_a84:
	/* 0xa84: mov    r15d,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R15, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_a87:
	/* 0xa87: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_a8f:
	/* 0xa8f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)tg_stats_map));
x86_l_a96:
	/* 0xa96: lea    rsi,[rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a9b:
	/* 0xa9b: mov    eax,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_aa0:
	/* 0xaa0: call   rax */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RAX);
		switch (X86_SIM_L_REG_TAG(X86_RAX)) {
		case X86_SIM_TAG_SCALAR:
			switch (__x86_target) {
			case 0x1ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_map_lookup_elem); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		case X86_SIM_TAG_HELPER_ID:
			switch (__x86_target) {
			case 0x1ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_map_lookup_elem); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_aa2:
	/* 0xaa2: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_aa5:
	/* 0xaa5: je     b5d <event_wake_up_new_task+0xb5d> */
	X86_SIM_X86_JCC(X86_CC_E, 0xaa5, 0xb5d, x86_l_b5d);
x86_l_aab:
	/* 0xaab: add    r15d,0x1c */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 28ULL);
x86_l_aaf:
	/* 0xaaf: cmp    r15d,0x1a */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 26ULL);
x86_l_ab3:
	/* 0xab3: ja     b3b <event_wake_up_new_task+0xb3b> */
	X86_SIM_X86_JCC(X86_CC_A, 0xab3, 0xb3b, x86_l_b3b);
x86_l_ab9:
	/* Capture image-bound code identity before scheduled instructions. */
	switch (X86_SIM_L_READ_REG(X86_R15) << 2) {
	case 0ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xb23ULL); break;
	case 4ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xb3bULL); break;
	case 8ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xb3bULL); break;
	case 12ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xb3bULL); break;
	case 16ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xb3bULL); break;
	case 20ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xb3bULL); break;
	case 24ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xb43ULL); break;
	case 28ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xb3bULL); break;
	case 32ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xb3bULL); break;
	case 36ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xb3bULL); break;
	case 40ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xb3bULL); break;
	case 44ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xb3bULL); break;
	case 48ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xb2bULL); break;
	case 52ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xb3bULL); break;
	case 56ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xb3bULL); break;
	case 60ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xb3bULL); break;
	case 64ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xb3bULL); break;
	case 68ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xb4bULL); break;
	case 72ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xb3bULL); break;
	case 76ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xb3bULL); break;
	case 80ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xb3bULL); break;
	case 84ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xb53ULL); break;
	case 88ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xb3bULL); break;
	case 92ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xb3bULL); break;
	case 96ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xb3bULL); break;
	case 100ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xb3bULL); break;
	case 104ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xb33ULL); break;
	default: __x86_sim_unresolved_indirect_target();
	}
x86_l_ac7:
	/* 0xac7: jmp    rdx */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RDX);
		switch (X86_SIM_L_REG_TAG(X86_RDX)) {
		case X86_SIM_TAG_CODE:
			switch (__x86_target) {
			case 0xb23ULL: goto x86_l_b23;
			case 0xb2bULL: goto x86_l_b2b;
			case 0xb33ULL: goto x86_l_b33;
			case 0xb3bULL: goto x86_l_b3b;
			case 0xb43ULL: goto x86_l_b43;
			case 0xb4bULL: goto x86_l_b4b;
			case 0xb53ULL: goto x86_l_b53;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_ac9:
	/* 0xac9: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)tg_rb_events));
x86_l_ad0:
	/* 0xad0: mov    eax,0x82 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 130ULL);
x86_l_ad5:
	/* 0xad5: mov    edx,0xa0 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 160ULL);
x86_l_ada:
	/* 0xada: mov    rsi,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_add:
	/* 0xadd: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_adf:
	/* 0xadf: call   rax */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RAX);
		switch (X86_SIM_L_REG_TAG(X86_RAX)) {
		case X86_SIM_TAG_SCALAR:
			switch (__x86_target) {
			case 0x82ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_ringbuf_output); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		case X86_SIM_TAG_HELPER_ID:
			switch (__x86_target) {
			case 0x82ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_ringbuf_output); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_ae1:
	/* 0xae1: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_ae4:
	/* 0xae4: jns    b5d <event_wake_up_new_task+0xb5d> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xae4, 0xb5d, x86_l_b5d);
x86_l_ae6:
	/* 0xae6: mov    r15,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R15, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_ae9:
	/* 0xae9: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_af1:
	/* 0xaf1: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)tg_stats_map));
x86_l_af8:
	/* 0xaf8: lea    rsi,[rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_afd:
	/* 0xafd: mov    eax,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_b02:
	/* 0xb02: call   rax */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RAX);
		switch (X86_SIM_L_REG_TAG(X86_RAX)) {
		case X86_SIM_TAG_SCALAR:
			switch (__x86_target) {
			case 0x1ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_map_lookup_elem); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		case X86_SIM_TAG_HELPER_ID:
			switch (__x86_target) {
			case 0x1ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_map_lookup_elem); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_b04:
	/* 0xb04: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_b07:
	/* 0xb07: je     b5d <event_wake_up_new_task+0xb5d> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb07, 0xb5d, x86_l_b5d);
x86_l_b09:
	/* 0xb09: add    r15,0x1c */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 28ULL);
x86_l_b0d:
	/* 0xb0d: cmp    r15,0x1a */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, 0, 26ULL);
x86_l_b11:
	/* 0xb11: ja     b3b <event_wake_up_new_task+0xb3b> */
	X86_SIM_X86_JCC(X86_CC_A, 0xb11, 0xb3b, x86_l_b3b);
x86_l_b13:
	/* Capture image-bound code identity before scheduled instructions. */
	switch (X86_SIM_L_READ_REG(X86_R15) << 2) {
	case 0ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xb23ULL); break;
	case 4ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xb3bULL); break;
	case 8ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xb3bULL); break;
	case 12ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xb3bULL); break;
	case 16ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xb3bULL); break;
	case 20ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xb3bULL); break;
	case 24ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xb43ULL); break;
	case 28ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xb3bULL); break;
	case 32ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xb3bULL); break;
	case 36ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xb3bULL); break;
	case 40ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xb3bULL); break;
	case 44ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xb3bULL); break;
	case 48ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xb2bULL); break;
	case 52ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xb3bULL); break;
	case 56ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xb3bULL); break;
	case 60ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xb3bULL); break;
	case 64ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xb3bULL); break;
	case 68ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xb4bULL); break;
	case 72ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xb3bULL); break;
	case 76ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xb3bULL); break;
	case 80ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xb3bULL); break;
	case 84ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xb53ULL); break;
	case 88ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xb3bULL); break;
	case 92ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xb3bULL); break;
	case 96ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xb3bULL); break;
	case 100ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xb3bULL); break;
	case 104ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xb33ULL); break;
	default: __x86_sim_unresolved_indirect_target();
	}
x86_l_b21:
	/* 0xb21: jmp    rdx */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RDX);
		switch (X86_SIM_L_REG_TAG(X86_RDX)) {
		case X86_SIM_TAG_CODE:
			switch (__x86_target) {
			case 0xb23ULL: goto x86_l_b23;
			case 0xb2bULL: goto x86_l_b2b;
			case 0xb33ULL: goto x86_l_b33;
			case 0xb3bULL: goto x86_l_b3b;
			case 0xb43ULL: goto x86_l_b43;
			case 0xb4bULL: goto x86_l_b4b;
			case 0xb53ULL: goto x86_l_b53;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_b23:
	/* 0xb23: add    rax,0x610 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 1552ULL);
x86_l_b29:
	/* 0xb29: jmp    b59 <event_wake_up_new_task+0xb59> */
	X86_SIM_X86_JMP(0xb29, 0xb59, x86_l_b59);
x86_l_b2b:
	/* 0xb2b: add    rax,0x600 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 1536ULL);
x86_l_b31:
	/* 0xb31: jmp    b59 <event_wake_up_new_task+0xb59> */
	X86_SIM_X86_JMP(0xb31, 0xb59, x86_l_b59);
x86_l_b33:
	/* 0xb33: add    rax,0x5f0 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 1520ULL);
x86_l_b39:
	/* 0xb39: jmp    b59 <event_wake_up_new_task+0xb59> */
	X86_SIM_X86_JMP(0xb39, 0xb59, x86_l_b59);
x86_l_b3b:
	/* 0xb3b: add    rax,0x5e8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 1512ULL);
x86_l_b41:
	/* 0xb41: jmp    b59 <event_wake_up_new_task+0xb59> */
	X86_SIM_X86_JMP(0xb41, 0xb59, x86_l_b59);
x86_l_b43:
	/* 0xb43: add    rax,0x608 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 1544ULL);
x86_l_b49:
	/* 0xb49: jmp    b59 <event_wake_up_new_task+0xb59> */
	X86_SIM_X86_JMP(0xb49, 0xb59, x86_l_b59);
x86_l_b4b:
	/* 0xb4b: add    rax,0x618 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 1560ULL);
x86_l_b51:
	/* 0xb51: jmp    b59 <event_wake_up_new_task+0xb59> */
	X86_SIM_X86_JMP(0xb51, 0xb59, x86_l_b59);
x86_l_b53:
	/* 0xb53: add    rax,0x5f8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 1528ULL);
x86_l_b59:
	/* 0xb59: inc QWORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_ALU_MEM_UNARY, X86_RAX, X86_REG_NONE, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_b5d:
	/* 0xb5d: cmp    QWORD PTR [r14+0x20],0x0 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_b62:
	/* 0xb62: jne    c8c <event_wake_up_new_task+0xc8c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xb62, 0xc8c, x86_l_c8c);
x86_l_b68:
	/* 0xb68: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b6f:
	/* 0xb6f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)tg_conf_map));
x86_l_b76:
	/* 0xb76: mov    rsi,rsp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_RSP, X86_WIDTH_64, 0, 0);
x86_l_b79:
	/* 0xb79: mov    eax,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_b7e:
	/* 0xb7e: call   rax */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RAX);
		switch (X86_SIM_L_REG_TAG(X86_RAX)) {
		case X86_SIM_TAG_SCALAR:
			switch (__x86_target) {
			case 0x1ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_map_lookup_elem); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		case X86_SIM_TAG_HELPER_ID:
			switch (__x86_target) {
			case 0x1ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_map_lookup_elem); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_b80:
	/* 0xb80: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_b83:
	/* 0xb83: je     bf6 <event_wake_up_new_task+0xbf6> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb83, 0xbf6, x86_l_bf6);
x86_l_b85:
	/* 0xb85: cmp    BYTE PTR [rax+0x28],0x0 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_b89:
	/* 0xb89: je     bf6 <event_wake_up_new_task+0xbf6> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb89, 0xbf6, x86_l_bf6);
x86_l_b8b:
	/* 0xb8b: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RSI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)tcpmon_map));
x86_l_b92:
	/* 0xb92: lea    rcx,[rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_b97:
	/* 0xb97: mov    eax,0x19 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 25ULL);
x86_l_b9c:
	/* 0xb9c: mov    edx,0xffffffff */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 4294967295ULL);
x86_l_ba1:
	/* 0xba1: mov    r8d,0x38 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, 0, 56ULL);
x86_l_ba7:
	/* 0xba7: mov    rdi,rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_baa:
	/* 0xbaa: call   rax */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RAX);
		switch (X86_SIM_L_REG_TAG(X86_RAX)) {
		case X86_SIM_TAG_SCALAR:
			switch (__x86_target) {
			case 0x19ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_perf_event_output); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		case X86_SIM_TAG_HELPER_ID:
			switch (__x86_target) {
			case 0x19ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_perf_event_output); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_bac:
	/* 0xbac: test   eax,eax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_bae:
	/* 0xbae: jns    c8c <event_wake_up_new_task+0xc8c> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xbae, 0xc8c, x86_l_c8c);
x86_l_bb4:
	/* 0xbb4: mov    ebx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RBX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_bb6:
	/* 0xbb6: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_bbe:
	/* 0xbbe: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)tg_stats_map));
x86_l_bc5:
	/* 0xbc5: lea    rsi,[rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_bca:
	/* 0xbca: mov    eax,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_bcf:
	/* 0xbcf: call   rax */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RAX);
		switch (X86_SIM_L_REG_TAG(X86_RAX)) {
		case X86_SIM_TAG_SCALAR:
			switch (__x86_target) {
			case 0x1ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_map_lookup_elem); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		case X86_SIM_TAG_HELPER_ID:
			switch (__x86_target) {
			case 0x1ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_map_lookup_elem); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_bd1:
	/* 0xbd1: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_bd4:
	/* 0xbd4: je     c8c <event_wake_up_new_task+0xc8c> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbd4, 0xc8c, x86_l_c8c);
x86_l_bda:
	/* 0xbda: add    ebx,0x1c */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 28ULL);
x86_l_bdd:
	/* 0xbdd: cmp    ebx,0x1a */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 26ULL);
x86_l_be0:
	/* 0xbe0: ja     c6a <event_wake_up_new_task+0xc6a> */
	X86_SIM_X86_JCC(X86_CC_A, 0xbe0, 0xc6a, x86_l_c6a);
x86_l_be6:
	/* Capture image-bound code identity before scheduled instructions. */
	switch (X86_SIM_L_READ_REG(X86_RBX) << 2) {
	case 0ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xc52ULL); break;
	case 4ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xc6aULL); break;
	case 8ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xc6aULL); break;
	case 12ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xc6aULL); break;
	case 16ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xc6aULL); break;
	case 20ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xc6aULL); break;
	case 24ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xc72ULL); break;
	case 28ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xc6aULL); break;
	case 32ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xc6aULL); break;
	case 36ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xc6aULL); break;
	case 40ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xc6aULL); break;
	case 44ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xc6aULL); break;
	case 48ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xc5aULL); break;
	case 52ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xc6aULL); break;
	case 56ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xc6aULL); break;
	case 60ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xc6aULL); break;
	case 64ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xc6aULL); break;
	case 68ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xc7aULL); break;
	case 72ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xc6aULL); break;
	case 76ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xc6aULL); break;
	case 80ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xc6aULL); break;
	case 84ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xc82ULL); break;
	case 88ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xc6aULL); break;
	case 92ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xc6aULL); break;
	case 96ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xc6aULL); break;
	case 100ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xc6aULL); break;
	case 104ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xc62ULL); break;
	default: __x86_sim_unresolved_indirect_target();
	}
x86_l_bf4:
	/* 0xbf4: jmp    rdx */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RDX);
		switch (X86_SIM_L_REG_TAG(X86_RDX)) {
		case X86_SIM_TAG_CODE:
			switch (__x86_target) {
			case 0xc52ULL: goto x86_l_c52;
			case 0xc5aULL: goto x86_l_c5a;
			case 0xc62ULL: goto x86_l_c62;
			case 0xc6aULL: goto x86_l_c6a;
			case 0xc72ULL: goto x86_l_c72;
			case 0xc7aULL: goto x86_l_c7a;
			case 0xc82ULL: goto x86_l_c82;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_bf6:
	/* 0xbf6: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)tg_rb_events));
x86_l_bfd:
	/* 0xbfd: lea    rsi,[rsp+0x40] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_c02:
	/* 0xc02: mov    eax,0x82 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 130ULL);
x86_l_c07:
	/* 0xc07: mov    edx,0x38 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 56ULL);
x86_l_c0c:
	/* 0xc0c: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_c0e:
	/* 0xc0e: call   rax */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RAX);
		switch (X86_SIM_L_REG_TAG(X86_RAX)) {
		case X86_SIM_TAG_SCALAR:
			switch (__x86_target) {
			case 0x82ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_ringbuf_output); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		case X86_SIM_TAG_HELPER_ID:
			switch (__x86_target) {
			case 0x82ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_ringbuf_output); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_c10:
	/* 0xc10: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_c13:
	/* 0xc13: jns    c8c <event_wake_up_new_task+0xc8c> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xc13, 0xc8c, x86_l_c8c);
x86_l_c15:
	/* 0xc15: mov    rbx,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RBX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_c18:
	/* 0xc18: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_c20:
	/* 0xc20: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)tg_stats_map));
x86_l_c27:
	/* 0xc27: lea    rsi,[rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c2c:
	/* 0xc2c: mov    eax,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_c31:
	/* 0xc31: call   rax */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RAX);
		switch (X86_SIM_L_REG_TAG(X86_RAX)) {
		case X86_SIM_TAG_SCALAR:
			switch (__x86_target) {
			case 0x1ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_map_lookup_elem); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		case X86_SIM_TAG_HELPER_ID:
			switch (__x86_target) {
			case 0x1ULL: X86_SIM_RUN_OP(X86_OP_CALL_HELPER, 0, 0, 0, 0, X86_SIM_HELPER_bpf_map_lookup_elem); break;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_c33:
	/* 0xc33: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_c36:
	/* 0xc36: je     c8c <event_wake_up_new_task+0xc8c> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc36, 0xc8c, x86_l_c8c);
x86_l_c38:
	/* 0xc38: add    rbx,0x1c */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 28ULL);
x86_l_c3c:
	/* 0xc3c: cmp    rbx,0x1a */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 26ULL);
x86_l_c40:
	/* 0xc40: ja     c6a <event_wake_up_new_task+0xc6a> */
	X86_SIM_X86_JCC(X86_CC_A, 0xc40, 0xc6a, x86_l_c6a);
x86_l_c42:
	/* Capture image-bound code identity before scheduled instructions. */
	switch (X86_SIM_L_READ_REG(X86_RBX) << 2) {
	case 0ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xc52ULL); break;
	case 4ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xc6aULL); break;
	case 8ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xc6aULL); break;
	case 12ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xc6aULL); break;
	case 16ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xc6aULL); break;
	case 20ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xc6aULL); break;
	case 24ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xc72ULL); break;
	case 28ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xc6aULL); break;
	case 32ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xc6aULL); break;
	case 36ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xc6aULL); break;
	case 40ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xc6aULL); break;
	case 44ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xc6aULL); break;
	case 48ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xc5aULL); break;
	case 52ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xc6aULL); break;
	case 56ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xc6aULL); break;
	case 60ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xc6aULL); break;
	case 64ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xc6aULL); break;
	case 68ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xc7aULL); break;
	case 72ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xc6aULL); break;
	case 76ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xc6aULL); break;
	case 80ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xc6aULL); break;
	case 84ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xc82ULL); break;
	case 88ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xc6aULL); break;
	case 92ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xc6aULL); break;
	case 96ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xc6aULL); break;
	case 100ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xc6aULL); break;
	case 104ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0xc62ULL); break;
	default: __x86_sim_unresolved_indirect_target();
	}
x86_l_c50:
	/* 0xc50: jmp    rdx */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RDX);
		switch (X86_SIM_L_REG_TAG(X86_RDX)) {
		case X86_SIM_TAG_CODE:
			switch (__x86_target) {
			case 0xc52ULL: goto x86_l_c52;
			case 0xc5aULL: goto x86_l_c5a;
			case 0xc62ULL: goto x86_l_c62;
			case 0xc6aULL: goto x86_l_c6a;
			case 0xc72ULL: goto x86_l_c72;
			case 0xc7aULL: goto x86_l_c7a;
			case 0xc82ULL: goto x86_l_c82;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_c52:
	/* 0xc52: add    rax,0x530 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 1328ULL);
x86_l_c58:
	/* 0xc58: jmp    c88 <event_wake_up_new_task+0xc88> */
	X86_SIM_X86_JMP(0xc58, 0xc88, x86_l_c88);
x86_l_c5a:
	/* 0xc5a: add    rax,0x520 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 1312ULL);
x86_l_c60:
	/* 0xc60: jmp    c88 <event_wake_up_new_task+0xc88> */
	X86_SIM_X86_JMP(0xc60, 0xc88, x86_l_c88);
x86_l_c62:
	/* 0xc62: add    rax,0x510 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 1296ULL);
x86_l_c68:
	/* 0xc68: jmp    c88 <event_wake_up_new_task+0xc88> */
	X86_SIM_X86_JMP(0xc68, 0xc88, x86_l_c88);
x86_l_c6a:
	/* 0xc6a: add    rax,0x508 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 1288ULL);
x86_l_c70:
	/* 0xc70: jmp    c88 <event_wake_up_new_task+0xc88> */
	X86_SIM_X86_JMP(0xc70, 0xc88, x86_l_c88);
x86_l_c72:
	/* 0xc72: add    rax,0x528 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 1320ULL);
x86_l_c78:
	/* 0xc78: jmp    c88 <event_wake_up_new_task+0xc88> */
	X86_SIM_X86_JMP(0xc78, 0xc88, x86_l_c88);
x86_l_c7a:
	/* 0xc7a: add    rax,0x538 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 1336ULL);
x86_l_c80:
	/* 0xc80: jmp    c88 <event_wake_up_new_task+0xc88> */
	X86_SIM_X86_JMP(0xc80, 0xc88, x86_l_c88);
x86_l_c82:
	/* 0xc82: add    rax,0x518 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 1304ULL);
x86_l_c88:
	/* 0xc88: inc QWORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_ALU_MEM_UNARY, X86_RAX, X86_REG_NONE, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_c8c:
	/* 0xc8c: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_c8e:
	/* 0xc8e: add    rsp,0x118 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 280ULL);
x86_l_c95:
	/* 0xc95: pop    rbx */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_c96:
	/* 0xc96: pop    r12 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R12, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_c98:
	/* 0xc98: pop    r13 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R13, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_c9a:
	/* 0xc9a: pop    r14 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R14, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_c9c:
	/* 0xc9c: pop    r15 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R15, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_c9e:
	/* 0xc9e: pop    rbp */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBP, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_c9f:
	/* 0xc9f: jmp    dd9 <__native_link_local_memset_any_dynamic+0x8d> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_dd9:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
	/* native subroutine native_link_sub_ca4 */
x86_l_ca4:
	/* 0xca4: mov    rax,rdi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RDI, X86_WIDTH_64, 0, 0);
x86_l_ca7:
	/* 0xca7: cmp    rdx,0x20 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, 0, 32ULL);
x86_l_cab:
	/* 0xcab: jb     ce5 <__native_link_local_memcpy_any_dynamic+0x41> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0xcab, 0xce5, x86_l_ce5);
x86_l_cb1:
	/* 0xcb1: mov    r8,QWORD PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cb4:
	/* 0xcb4: mov    QWORD PTR [rdi],r8 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cb7:
	/* 0xcb7: mov    r8,QWORD PTR [rsi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_cbb:
	/* 0xcbb: mov    QWORD PTR [rdi+0x8],r8 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_cbf:
	/* 0xcbf: mov    r8,QWORD PTR [rsi+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_cc3:
	/* 0xcc3: mov    QWORD PTR [rdi+0x10],r8 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_cc7:
	/* 0xcc7: mov    r8,QWORD PTR [rsi+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_ccb:
	/* 0xccb: mov    QWORD PTR [rdi+0x18],r8 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_ccf:
	/* 0xccf: add    rdi,0x20 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_cd3:
	/* 0xcd3: add    rsi,0x20 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_cd7:
	/* 0xcd7: sub    rdx,0x20 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SUB, 32ULL);
x86_l_cdb:
	/* 0xcdb: cmp    rdx,0x20 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, 0, 32ULL);
x86_l_cdf:
	/* 0xcdf: jae    cb1 <__native_link_local_memcpy_any_dynamic+0xd> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0xcdf, 0xcb1, x86_l_cb1);
x86_l_ce5:
	/* 0xce5: cmp    rdx,0x8 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, 0, 8ULL);
x86_l_ce9:
	/* 0xce9: jb     d0b <__native_link_local_memcpy_any_dynamic+0x67> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0xce9, 0xd0b, x86_l_d0b);
x86_l_cef:
	/* 0xcef: mov    r8,QWORD PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cf2:
	/* 0xcf2: mov    QWORD PTR [rdi],r8 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cf5:
	/* 0xcf5: add    rdi,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_cf9:
	/* 0xcf9: add    rsi,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_cfd:
	/* 0xcfd: sub    rdx,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SUB, 8ULL);
x86_l_d01:
	/* 0xd01: cmp    rdx,0x8 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, 0, 8ULL);
x86_l_d05:
	/* 0xd05: jae    cef <__native_link_local_memcpy_any_dynamic+0x4b> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0xd05, 0xcef, x86_l_cef);
x86_l_d0b:
	/* 0xd0b: test   dl,0x4 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, 0, 4ULL);
x86_l_d0e:
	/* 0xd0e: je     d22 <__native_link_local_memcpy_any_dynamic+0x7e> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xd0e, 0xd22, x86_l_d22);
x86_l_d14:
	/* 0xd14: mov    r8d,DWORD PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R8, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d17:
	/* 0xd17: mov    DWORD PTR [rdi],r8d */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d1a:
	/* 0xd1a: add    rdi,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_d1e:
	/* 0xd1e: add    rsi,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_d22:
	/* 0xd22: test   dl,0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, 0, 2ULL);
x86_l_d25:
	/* 0xd25: je     d3b <__native_link_local_memcpy_any_dynamic+0x97> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xd25, 0xd3b, x86_l_d3b);
x86_l_d2b:
	/* 0xd2b: movzx  r8d,WORD PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R8, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_d2f:
	/* 0xd2f: mov    WORD PTR [rdi],r8w */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_R8, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d33:
	/* 0xd33: add    rdi,0x2 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_d37:
	/* 0xd37: add    rsi,0x2 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_d3b:
	/* 0xd3b: test   dl,0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_d3e:
	/* 0xd3e: je     d4b <__native_link_local_memcpy_any_dynamic+0xa7> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xd3e, 0xd4b, x86_l_d4b);
x86_l_d44:
	/* 0xd44: movzx  r8d,BYTE PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R8, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_d48:
	/* 0xd48: mov    BYTE PTR [rdi],r8b */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_R8, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d4b:
	/* 0xd4b: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);

	/* native subroutine native_link_sub_d4c */
x86_l_d4c:
	/* 0xd4c: mov    rax,rdi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RDI, X86_WIDTH_64, 0, 0);
x86_l_d4f:
	/* 0xd4f: movzx  r8d,sil */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_R8, X86_RSI, X86_WIDTH_32, X86_WIDTH_8, 0);
x86_l_d53:
	/* 0xd53: movabs r9,0x101010101010101 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_64, 0, 72340172838076673ULL);
x86_l_d5d:
	/* 0xd5d: imul   r8,r9 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R8, X86_R9, X86_WIDTH_64, X86_ALU_IMUL, 0);
x86_l_d61:
	/* 0xd61: cmp    rdx,0x20 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, 0, 32ULL);
x86_l_d65:
	/* 0xd65: jb     d8c <__native_link_local_memset_any_dynamic+0x40> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0xd65, 0xd8c, x86_l_d8c);
x86_l_d6b:
	/* 0xd6b: mov    QWORD PTR [rdi],r8 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d6e:
	/* 0xd6e: mov    QWORD PTR [rdi+0x8],r8 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d72:
	/* 0xd72: mov    QWORD PTR [rdi+0x10],r8 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d76:
	/* 0xd76: mov    QWORD PTR [rdi+0x18],r8 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_d7a:
	/* 0xd7a: add    rdi,0x20 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_d7e:
	/* 0xd7e: sub    rdx,0x20 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SUB, 32ULL);
x86_l_d82:
	/* 0xd82: cmp    rdx,0x20 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, 0, 32ULL);
x86_l_d86:
	/* 0xd86: jae    d6b <__native_link_local_memset_any_dynamic+0x1f> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0xd86, 0xd6b, x86_l_d6b);
x86_l_d8c:
	/* 0xd8c: cmp    rdx,0x8 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, 0, 8ULL);
x86_l_d90:
	/* 0xd90: jb     dab <__native_link_local_memset_any_dynamic+0x5f> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0xd90, 0xdab, x86_l_dab);
x86_l_d96:
	/* 0xd96: mov    QWORD PTR [rdi],r8 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d99:
	/* 0xd99: add    rdi,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_d9d:
	/* 0xd9d: sub    rdx,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SUB, 8ULL);
x86_l_da1:
	/* 0xda1: cmp    rdx,0x8 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, 0, 8ULL);
x86_l_da5:
	/* 0xda5: jae    d96 <__native_link_local_memset_any_dynamic+0x4a> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0xda5, 0xd96, x86_l_d96);
x86_l_dab:
	/* 0xdab: test   dl,0x4 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, 0, 4ULL);
x86_l_dae:
	/* 0xdae: je     dbb <__native_link_local_memset_any_dynamic+0x6f> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xdae, 0xdbb, x86_l_dbb);
x86_l_db4:
	/* 0xdb4: mov    DWORD PTR [rdi],r8d */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_db7:
	/* 0xdb7: add    rdi,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_dbb:
	/* 0xdbb: test   dl,0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, 0, 2ULL);
x86_l_dbe:
	/* 0xdbe: je     dcc <__native_link_local_memset_any_dynamic+0x80> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xdbe, 0xdcc, x86_l_dcc);
x86_l_dc4:
	/* 0xdc4: mov    WORD PTR [rdi],r8w */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_R8, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_dc8:
	/* 0xdc8: add    rdi,0x2 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_dcc:
	/* 0xdcc: test   dl,0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_dcf:
	/* 0xdcf: je     dd8 <__native_link_local_memset_any_dynamic+0x8c> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xdcf, 0xdd8, x86_l_dd8);
x86_l_dd5:
	/* 0xdd5: mov    BYTE PTR [rdi],r8b */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_R8, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_dd8:
	/* 0xdd8: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);

x86_sim_ret_dispatch:
	switch (__x86_sim_ret_addr) {
	case 0x2fdULL: goto x86_l_2fd;
	case 0x4acULL: goto x86_l_4ac;
	case 0x6a5ULL: goto x86_l_6a5;
	case 0xa37ULL: goto x86_l_a37;
	default: __x86_sim_unresolved_indirect_target();
	}

}

X86_SIM_LICENSE();
