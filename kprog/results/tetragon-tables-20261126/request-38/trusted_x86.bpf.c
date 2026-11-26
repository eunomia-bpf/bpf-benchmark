#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_STACK_BYTES 248U
#define X86_SIM_STACK_VALUE_WORDS(M) M(2) M(10) M(11) M(12) M(16) M(21) M(22) M(23) M(24)
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

extern __u8 addr4lpm_maps[] __ksym;
extern __u8 addr6lpm_maps[] __ksym;
extern __u8 argfilter_maps[] __ksym;
extern __u8 filter_map[] __ksym;
extern __u8 heap_ro_zero[] __ksym;
extern __u8 process_call_heap[] __ksym;
extern __u8 retkprobe_calls[] __ksym;
extern __u8 retprobe_map[] __ksym;
extern __u8 string_maps_0[] __ksym;
extern __u8 string_maps_1[] __ksym;
extern __u8 string_maps_10[] __ksym;
extern __u8 string_maps_2[] __ksym;
extern __u8 string_maps_3[] __ksym;
extern __u8 string_maps_4[] __ksym;
extern __u8 string_maps_5[] __ksym;
extern __u8 string_maps_6[] __ksym;
extern __u8 string_maps_7[] __ksym;
extern __u8 string_maps_8[] __ksym;
extern __u8 string_maps_9[] __ksym;
extern __u8 string_maps_heap[] __ksym;
extern __u8 string_postfix_maps[] __ksym;
extern __u8 string_postfix_maps_heap[] __ksym;
extern __u8 string_prefix_maps[] __ksym;
extern __u8 string_prefix_maps_heap[] __ksym;
extern __u8 substring_map[] __ksym;
#include "/workspaces/repository/kprog/x86/x86_sim_inline.h"

X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_ALU_IMM, X86_OP_ALU_IMM)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_ALU_MEM, X86_OP_ALU_MEM)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_ALU_REG, X86_OP_ALU_REG)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_ANDN_MEM, X86_OP_ANDN_MEM)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_BT, X86_OP_BT)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_CALL_HELPER, X86_OP_CALL_HELPER)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_CMOV, X86_OP_CMOV)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_CMP_IMM, X86_OP_CMP_IMM)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_CMP_MEM_IMM, X86_OP_CMP_MEM_IMM)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_CMP_MEM_REG, X86_OP_CMP_MEM_REG)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_CMP_REG, X86_OP_CMP_REG)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_CMP_REG_MEM, X86_OP_CMP_REG_MEM)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_IMUL_IMM, X86_OP_IMUL_IMM)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_LEA, X86_OP_LEA)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_MOVSX_LOAD, X86_OP_MOVSX_LOAD)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_MOVSX_REG, X86_OP_MOVSX_REG)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_MOVZX_REG, X86_OP_MOVZX_REG)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_MOV_IMM, X86_OP_MOV_IMM)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_MOV_LOAD, X86_OP_MOV_LOAD)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_MOV_LOAD_MAP_PTR, X86_OP_MOV_LOAD_MAP_PTR)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_MOV_REG, X86_OP_MOV_REG)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_MOV_STORE_IMM, X86_OP_MOV_STORE_IMM)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_MOV_STORE_REG, X86_OP_MOV_STORE_REG)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_POP, X86_OP_POP)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_PUSH, X86_OP_PUSH)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_RORX, X86_OP_RORX)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_SETCC, X86_OP_SETCC)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_TEST_IMM, X86_OP_TEST_IMM)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_TEST_MEM_REG, X86_OP_TEST_MEM_REG)
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
	/* 0xa: sub    rsp,0x28 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SUB, 40ULL);
x86_l_e:
	/* 0xe: mov    rbx,rdi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RBX, X86_RDI, X86_WIDTH_64, 0, 0);
x86_l_11:
	/* 0x11: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_19:
	/* 0x19: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)process_call_heap));
x86_l_20:
	/* 0x20: lea    rsi,[rsp+0x4] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_25:
	/* 0x25: call   2a <generic_retkprobe_filter_arg+0x2a> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_2a:
	/* 0x2a: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_2d:
	/* 0x2d: je     305 <generic_retkprobe_filter_arg+0x305> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2d, 0x305, x86_l_305);
x86_l_33:
	/* 0x33: mov    r14,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R14, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_36:
	/* 0x36: mov    r12d,DWORD PTR [rax+0x5f00] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24320ULL);
x86_l_3d:
	/* 0x3d: lea    rsi,[rax+0x5ef8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24312ULL);
x86_l_44:
	/* 0x44: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)filter_map));
x86_l_4b:
	/* 0x4b: call   50 <generic_retkprobe_filter_arg+0x50> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_50:
	/* 0x50: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_53:
	/* 0x53: je     2f1 <generic_retkprobe_filter_arg+0x2f1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x53, 0x2f1, x86_l_2f1);
x86_l_59:
	/* 0x59: cmp    BYTE PTR [r14+0x5ee0],0x0 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104316165685248ULL);
x86_l_61:
	/* 0x61: je     2f1 <generic_retkprobe_filter_arg+0x2f1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x61, 0x2f1, x86_l_2f1);
x86_l_67:
	/* 0x67: mov    r15,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R15, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_6a:
	/* 0x6a: mov    eax,r12d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_R12, X86_WIDTH_32, 0, 0);
x86_l_6d:
	/* 0x6d: and    eax,0x7 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_70:
	/* 0x70: cmp    BYTE PTR [r14+rax*1+0x5ec1],0x0 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 104183021699072ULL);
x86_l_79:
	/* 0x79: je     b7 <generic_retkprobe_filter_arg+0xb7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x79, 0xb7, x86_l_b7);
x86_l_7b:
	/* 0x7b: mov    eax,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_7d:
	/* 0x7d: mov    ecx,DWORD PTR [r15+rax*4+0x4] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_82:
	/* 0x82: lea    r13,[rcx+rax*4] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R13, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 2), 0ULL);
x86_l_86:
	/* 0x86: add    r13,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_8a:
	/* 0x8a: mov    rax,r13 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_8d:
	/* 0x8d: mov    QWORD PTR [rsp+0x10],r13 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_92:
	/* 0x92: and    r13d,0x3ff */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_99:
	/* 0x99: cmp    DWORD PTR [r15+r13*1],0x19 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 25ULL);
x86_l_9e:
	/* 0x9e: jae    18a <generic_retkprobe_filter_arg+0x18a> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x9e, 0x18a, x86_l_18a);
x86_l_a4:
	/* 0xa4: cmp    r13,0x1 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, 0, 1ULL);
x86_l_a8:
	/* 0xa8: je     2f1 <generic_retkprobe_filter_arg+0x2f1> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa8, 0x2f1, x86_l_2f1);
x86_l_ae:
	/* 0xae: test   r13d,r13d */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_32, 0, 0);
x86_l_b1:
	/* 0xb1: jne    2d6 <generic_retkprobe_filter_arg+0x2d6> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xb1, 0x2d6, x86_l_2d6);
x86_l_b7:
	/* 0xb7: lea    eax,[r12+0x1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_bc:
	/* 0xbc: cmp    eax,0x5 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 5ULL);
x86_l_bf:
	/* 0xbf: ja     31a <generic_retkprobe_filter_arg+0x31a> */
	X86_SIM_X86_JCC(X86_CC_A, 0xbf, 0x31a, x86_l_31a);
x86_l_c5:
	/* Capture image-bound code identity before scheduled instructions. */
	switch (X86_SIM_L_READ_REG(X86_RAX) << 2) {
	case 0ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0xd5ULL); break;
	case 4ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0xe1ULL); break;
	case 8ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0xf0ULL); break;
	case 12ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0xffULL); break;
	case 16ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x10eULL); break;
	case 20ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x11dULL); break;
	default: __x86_sim_unresolved_indirect_target();
	}
x86_l_d3:
	/* 0xd3: jmp    rax */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RAX);
		switch (X86_SIM_L_REG_TAG(X86_RAX)) {
		case X86_SIM_TAG_CODE:
			switch (__x86_target) {
			case 0xd5ULL: goto x86_l_d5;
			case 0xe1ULL: goto x86_l_e1;
			case 0xf0ULL: goto x86_l_f0;
			case 0xffULL: goto x86_l_ff;
			case 0x10eULL: goto x86_l_10e;
			case 0x11dULL: goto x86_l_11d;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_d5:
	/* 0xd5: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_d7:
	/* 0xd7: cmp    BYTE PTR [r14+0x5ec1],0x0 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104183021699072ULL);
x86_l_df:
	/* 0xdf: jne    12c <generic_retkprobe_filter_arg+0x12c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xdf, 0x12c, x86_l_12c);
x86_l_e1:
	/* 0xe1: mov    eax,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_e6:
	/* 0xe6: cmp    BYTE PTR [r14+0x5ec2],0x0 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104187316666368ULL);
x86_l_ee:
	/* 0xee: jne    12c <generic_retkprobe_filter_arg+0x12c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xee, 0x12c, x86_l_12c);
x86_l_f0:
	/* 0xf0: mov    eax,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_f5:
	/* 0xf5: cmp    BYTE PTR [r14+0x5ec3],0x0 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104191611633664ULL);
x86_l_fd:
	/* 0xfd: jne    12c <generic_retkprobe_filter_arg+0x12c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xfd, 0x12c, x86_l_12c);
x86_l_ff:
	/* 0xff: mov    eax,0x3 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 3ULL);
x86_l_104:
	/* 0x104: cmp    BYTE PTR [r14+0x5ec4],0x0 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104195906600960ULL);
x86_l_10c:
	/* 0x10c: jne    12c <generic_retkprobe_filter_arg+0x12c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x10c, 0x12c, x86_l_12c);
x86_l_10e:
	/* 0x10e: mov    eax,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_113:
	/* 0x113: cmp    BYTE PTR [r14+0x5ec5],0x0 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104200201568256ULL);
x86_l_11b:
	/* 0x11b: jne    12c <generic_retkprobe_filter_arg+0x12c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x11b, 0x12c, x86_l_12c);
x86_l_11d:
	/* 0x11d: mov    eax,0x5 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 5ULL);
x86_l_122:
	/* 0x122: cmp    BYTE PTR [r14+0x5ec6],0x0 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104204496535552ULL);
x86_l_12a:
	/* 0x12a: je     147 <generic_retkprobe_filter_arg+0x147> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12a, 0x147, x86_l_147);
x86_l_12c:
	/* 0x12c: mov    DWORD PTR [r14+0x5f00],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24320ULL);
x86_l_133:
	/* 0x133: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RSI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)retkprobe_calls));
x86_l_13a:
	/* 0x13a: mov    rdi,rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_13d:
	/* 0x13d: mov    edx,0x3 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 3ULL);
x86_l_142:
	/* 0x142: call   147 <generic_retkprobe_filter_arg+0x147> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_tail_call);
x86_l_147:
	/* 0x147: mov    rbx,QWORD PTR [r14+0x60] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_14b:
	/* 0x14b: call   150 <generic_retkprobe_filter_arg+0x150> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_get_current_pid_tgid);
x86_l_150:
	/* 0x150: mov    QWORD PTR [rsp+0x18],rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_155:
	/* 0x155: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_15a:
	/* 0x15a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)retprobe_map));
x86_l_161:
	/* 0x161: lea    rsi,[rsp+0x18] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_166:
	/* 0x166: call   16b <generic_retkprobe_filter_arg+0x16b> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_16b:
	/* 0x16b: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_16e:
	/* 0x16e: je     305 <generic_retkprobe_filter_arg+0x305> */
	X86_SIM_X86_JCC(X86_CC_E, 0x16e, 0x305, x86_l_305);
x86_l_174:
	/* 0x174: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)retprobe_map));
x86_l_17b:
	/* 0x17b: lea    rsi,[rsp+0x18] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_180:
	/* 0x180: call   185 <generic_retkprobe_filter_arg+0x185> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_delete_elem);
x86_l_185:
	/* 0x185: jmp    305 <generic_retkprobe_filter_arg+0x305> */
	X86_SIM_X86_JMP(0x185, 0x305, x86_l_305);
x86_l_18a:
	/* 0x18a: lea    rax,[r15+r13*1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_18e:
	/* 0x18e: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_193:
	/* 0x193: mov    ebp,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_198:
	/* 0x198: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19d:
	/* 0x19d: mov    edi,DWORD PTR [rax+rbp*4] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 2), 0ULL);
x86_l_1a0:
	/* 0x1a0: test   edi,0x3ff */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 1023ULL);
x86_l_1a6:
	/* 0x1a6: je     a4 <generic_retkprobe_filter_arg+0xa4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a6, 0xa4, x86_l_a4);
x86_l_1ac:
	/* 0x1ac: add    edi,DWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_ALU_MEM, X86_RDI, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_1b0:
	/* 0x1b0: and    edi,0x3ff */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_1b6:
	/* 0x1b6: mov    eax,DWORD PTR [r15+rdi*1+0x4] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 0), 4ULL);
x86_l_1bb:
	/* 0x1bb: cmp    eax,0x23 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 35ULL);
x86_l_1be:
	/* 0x1be: je     b7 <generic_retkprobe_filter_arg+0xb7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1be, 0xb7, x86_l_b7);
x86_l_1c4:
	/* 0x1c4: add    rdi,r15 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1c7:
	/* 0x1c7: mov    edx,DWORD PTR [rdi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c9:
	/* 0x1c9: cmp    rdx,0x4 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, 0, 4ULL);
x86_l_1cd:
	/* 0x1cd: ja     b7 <generic_retkprobe_filter_arg+0xb7> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1cd, 0xb7, x86_l_b7);
x86_l_1d3:
	/* 0x1d3: cmp    DWORD PTR [r14+rdx*4+0x5ea0],0x0 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 2), 104041287778304ULL);
x86_l_1dc:
	/* 0x1dc: jne    b7 <generic_retkprobe_filter_arg+0xb7> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1dc, 0xb7, x86_l_b7);
x86_l_1e2:
	/* 0x1e2: mov    ecx,DWORD PTR [rdi+0xc] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1e5:
	/* 0x1e5: dec    ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_1e7:
	/* 0x1e7: cmp    ecx,0x2b */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 43ULL);
x86_l_1ea:
	/* 0x1ea: ja     2b1 <generic_retkprobe_filter_arg+0x2b1> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1ea, 0x2b1, x86_l_2b1);
x86_l_1f0:
	/* 0x1f0: mov    rdx,QWORD PTR [r14+rdx*8+0x5e78] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 3), 24184ULL);
x86_l_1f8:
	/* 0x1f8: and    edx,0x7ff */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_1fe:
	/* 0x1fe: lea    rsi,[r14+rdx*1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_202:
	/* 0x202: add    rsi,0x90 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_209:
	/* Capture image-bound code identity before scheduled instructions. */
	switch (X86_SIM_L_READ_REG(X86_RCX) << 2) {
	case 0ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x219ULL); break;
	case 4ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x2caULL); break;
	case 8ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x2b1ULL); break;
	case 12ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x219ULL); break;
	case 16ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x239ULL); break;
	case 20ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x285ULL); break;
	case 24ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x239ULL); break;
	case 28ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x2b1ULL); break;
	case 32ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x2b1ULL); break;
	case 36ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x219ULL); break;
	case 40ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x219ULL); break;
	case 44ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x219ULL); break;
	case 48ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x219ULL); break;
	case 52ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x2b1ULL); break;
	case 56ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x2a3ULL); break;
	case 60ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x2a3ULL); break;
	case 64ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x29fULL); break;
	case 68ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x2b1ULL); break;
	case 72ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x2b1ULL); break;
	case 76ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x2b1ULL); break;
	case 80ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x2b1ULL); break;
	case 84ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x2b1ULL); break;
	case 88ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x2b1ULL); break;
	case 92ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x2b1ULL); break;
	case 96ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x2b1ULL); break;
	case 100ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x2b1ULL); break;
	case 104ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x2b1ULL); break;
	case 108ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x219ULL); break;
	case 112ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x219ULL); break;
	case 116ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x219ULL); break;
	case 120ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x219ULL); break;
	case 124ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x219ULL); break;
	case 128ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x219ULL); break;
	case 132ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x219ULL); break;
	case 136ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x219ULL); break;
	case 140ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x219ULL); break;
	case 144ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x2a3ULL); break;
	case 148ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x285ULL); break;
	case 152ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x285ULL); break;
	case 156ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x239ULL); break;
	case 160ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x239ULL); break;
	case 164ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x2a3ULL); break;
	case 168ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x2b1ULL); break;
	case 172ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x2c3ULL); break;
	default: __x86_sim_unresolved_indirect_target();
	}
x86_l_217:
	/* 0x217: jmp    rdx */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RDX);
		switch (X86_SIM_L_REG_TAG(X86_RDX)) {
		case X86_SIM_TAG_CODE:
			switch (__x86_target) {
			case 0x219ULL: goto x86_l_219;
			case 0x239ULL: goto x86_l_239;
			case 0x285ULL: goto x86_l_285;
			case 0x29fULL: goto x86_l_29f;
			case 0x2a3ULL: goto x86_l_2a3;
			case 0x2b1ULL: goto x86_l_2b1;
			case 0x2c3ULL: goto x86_l_2c3;
			case 0x2caULL: goto x86_l_2ca;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_219:
	/* 0x219: cmp    ecx,0x23 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 35ULL);
x86_l_21c:
	/* 0x21c: ja     2b1 <generic_retkprobe_filter_arg+0x2b1> */
	X86_SIM_X86_JCC(X86_CC_A, 0x21c, 0x2b1, x86_l_2b1);
x86_l_222:
	/* Capture image-bound code identity before scheduled instructions. */
	switch (X86_SIM_L_READ_REG(X86_RCX) << 2) {
	case 0ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x232ULL); break;
	case 4ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x2b1ULL); break;
	case 8ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x2b1ULL); break;
	case 12ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x232ULL); break;
	case 16ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x2b1ULL); break;
	case 20ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x2b1ULL); break;
	case 24ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x2b1ULL); break;
	case 28ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x2b1ULL); break;
	case 32ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x2b1ULL); break;
	case 36ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x27eULL); break;
	case 40ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x27eULL); break;
	case 44ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x232ULL); break;
	case 48ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x232ULL); break;
	case 52ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x2b1ULL); break;
	case 56ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x2b1ULL); break;
	case 60ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x2b1ULL); break;
	case 64ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x2b1ULL); break;
	case 68ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x2b1ULL); break;
	case 72ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x2b1ULL); break;
	case 76ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x2b1ULL); break;
	case 80ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x2b1ULL); break;
	case 84ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x2b1ULL); break;
	case 88ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x2b1ULL); break;
	case 92ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x2b1ULL); break;
	case 96ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x2b1ULL); break;
	case 100ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x2b1ULL); break;
	case 104ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x2b1ULL); break;
	case 108ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x27eULL); break;
	case 112ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x298ULL); break;
	case 116ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x298ULL); break;
	case 120ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x291ULL); break;
	case 124ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x291ULL); break;
	case 128ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x240ULL); break;
	case 132ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x240ULL); break;
	case 136ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x240ULL); break;
	case 140ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x240ULL); break;
	default: __x86_sim_unresolved_indirect_target();
	}
x86_l_230:
	/* 0x230: jmp    rcx */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RCX);
		switch (X86_SIM_L_REG_TAG(X86_RCX)) {
		case X86_SIM_TAG_CODE:
			switch (__x86_target) {
			case 0x232ULL: goto x86_l_232;
			case 0x240ULL: goto x86_l_240;
			case 0x27eULL: goto x86_l_27e;
			case 0x291ULL: goto x86_l_291;
			case 0x298ULL: goto x86_l_298;
			case 0x2b1ULL: goto x86_l_2b1;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_232:
	/* 0x232: call   0 <generic_retkprobe_filter_arg> */
	X86_SIM_X86_CALL(x86_l_329, 0x237ULL);
x86_l_237:
	/* 0x237: jmp    2a8 <generic_retkprobe_filter_arg+0x2a8> */
	X86_SIM_X86_JMP(0x237, 0x2a8, x86_l_2a8);
x86_l_239:
	/* 0x239: call   0 <generic_retkprobe_filter_arg> */
	X86_SIM_X86_CALL(x86_l_36a, 0x23eULL);
x86_l_23e:
	/* 0x23e: jmp    2a8 <generic_retkprobe_filter_arg+0x2a8> */
	X86_SIM_X86_JMP(0x23e, 0x2a8, x86_l_2a8);
x86_l_240:
	/* 0x240: cmp    eax,0x1e */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 30ULL);
x86_l_243:
	/* 0x243: jne    27e <generic_retkprobe_filter_arg+0x27e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x243, 0x27e, x86_l_27e);
x86_l_245:
	/* 0x245: mov    eax,DWORD PTR [rdi+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_248:
	/* 0x248: and    eax,0x7 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_24b:
	/* 0x24b: mov    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_24d:
	/* 0x24d: cmp    DWORD PTR [r14+rcx*4+0x5ea0],0x0 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 104041287778304ULL);
x86_l_256:
	/* 0x256: jne    b7 <generic_retkprobe_filter_arg+0xb7> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x256, 0xb7, x86_l_b7);
x86_l_25c:
	/* 0x25c: mov    rcx,QWORD PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_25f:
	/* 0x25f: mov    rdx,QWORD PTR [r14+rax*8+0x5e78] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_267:
	/* 0x267: and    edx,0x7ff */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_26d:
	/* 0x26d: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_26f:
	/* 0x26f: andn   rcx,rcx,QWORD PTR [r14+rdx*1+0x90] */
	X86_SIM_RUN_OP(X86_OP_ANDN_MEM, X86_RCX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_RDX, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_R14)), 618475290624ULL);
x86_l_279:
	/* 0x279: setne  al */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_CC_NE, 0);
x86_l_27c:
	/* 0x27c: jmp    2a8 <generic_retkprobe_filter_arg+0x2a8> */
	X86_SIM_X86_JMP(0x27c, 0x2a8, x86_l_2a8);
x86_l_27e:
	/* 0x27e: call   0 <generic_retkprobe_filter_arg> */
	X86_SIM_X86_CALL(x86_l_5c1, 0x283ULL);
x86_l_283:
	/* 0x283: jmp    2a8 <generic_retkprobe_filter_arg+0x2a8> */
	X86_SIM_X86_JMP(0x283, 0x2a8, x86_l_2a8);
x86_l_285:
	/* 0x285: mov    edx,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_28a:
	/* 0x28a: call   0 <generic_retkprobe_filter_arg> */
	X86_SIM_X86_CALL(x86_l_602, 0x28fULL);
x86_l_28f:
	/* 0x28f: jmp    2a8 <generic_retkprobe_filter_arg+0x2a8> */
	X86_SIM_X86_JMP(0x28f, 0x2a8, x86_l_2a8);
x86_l_291:
	/* 0x291: call   0 <generic_retkprobe_filter_arg> */
	X86_SIM_X86_CALL(x86_l_68e, 0x296ULL);
x86_l_296:
	/* 0x296: jmp    2a8 <generic_retkprobe_filter_arg+0x2a8> */
	X86_SIM_X86_JMP(0x296, 0x2a8, x86_l_2a8);
x86_l_298:
	/* 0x298: call   0 <generic_retkprobe_filter_arg> */
	X86_SIM_X86_CALL(x86_l_6cf, 0x29dULL);
x86_l_29d:
	/* 0x29d: jmp    2a8 <generic_retkprobe_filter_arg+0x2a8> */
	X86_SIM_X86_JMP(0x29d, 0x2a8, x86_l_2a8);
x86_l_29f:
	/* 0x29f: add    rsi,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2a3:
	/* 0x2a3: call   0 <generic_retkprobe_filter_arg> */
	X86_SIM_X86_CALL(x86_l_710, 0x2a8ULL);
x86_l_2a8:
	/* 0x2a8: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_2ab:
	/* 0x2ab: je     b7 <generic_retkprobe_filter_arg+0xb7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2ab, 0xb7, x86_l_b7);
x86_l_2b1:
	/* 0x2b1: inc    rbp */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_2b4:
	/* 0x2b4: cmp    rbp,0x6 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, 0, 6ULL);
x86_l_2b8:
	/* 0x2b8: jne    198 <generic_retkprobe_filter_arg+0x198> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2b8, 0x198, x86_l_198);
x86_l_2be:
	/* 0x2be: jmp    a4 <generic_retkprobe_filter_arg+0xa4> */
	X86_SIM_X86_JMP(0x2be, 0xa4, x86_l_a4);
x86_l_2c3:
	/* 0x2c3: call   0 <generic_retkprobe_filter_arg> */
	X86_SIM_X86_CALL(x86_l_797, 0x2c8ULL);
x86_l_2c8:
	/* 0x2c8: jmp    2a8 <generic_retkprobe_filter_arg+0x2a8> */
	X86_SIM_X86_JMP(0x2c8, 0x2a8, x86_l_2a8);
x86_l_2ca:
	/* 0x2ca: mov    edx,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_2cf:
	/* 0x2cf: call   0 <generic_retkprobe_filter_arg> */
	X86_SIM_X86_CALL(x86_l_602, 0x2d4ULL);
x86_l_2d4:
	/* 0x2d4: jmp    2a8 <generic_retkprobe_filter_arg+0x2a8> */
	X86_SIM_X86_JMP(0x2d4, 0x2a8, x86_l_2a8);
x86_l_2d6:
	/* 0x2d6: mov    DWORD PTR [r14+0x5f04],r13d */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24324ULL);
x86_l_2dd:
	/* 0x2dd: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RSI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)retkprobe_calls));
x86_l_2e4:
	/* 0x2e4: mov    rdi,rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_2e7:
	/* 0x2e7: mov    edx,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_2ec:
	/* 0x2ec: call   2f1 <generic_retkprobe_filter_arg+0x2f1> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_tail_call);
x86_l_2f1:
	/* 0x2f1: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RSI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)retkprobe_calls));
x86_l_2f8:
	/* 0x2f8: mov    rdi,rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_2fb:
	/* 0x2fb: mov    edx,0x5 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 5ULL);
x86_l_300:
	/* 0x300: call   305 <generic_retkprobe_filter_arg+0x305> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_tail_call);
x86_l_305:
	/* 0x305: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_307:
	/* 0x307: add    rsp,0x28 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_30b:
	/* 0x30b: pop    rbx */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_30c:
	/* 0x30c: pop    r12 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R12, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_30e:
	/* 0x30e: pop    r13 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R13, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_310:
	/* 0x310: pop    r14 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R14, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_312:
	/* 0x312: pop    r15 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R15, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_314:
	/* 0x314: pop    rbp */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBP, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_315:
	/* 0x315: jmp    230e <__native_link_local_memset_zero_dynamic+0x7e> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_31a:
	/* 0x31a: cmp    r12d,0x4 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_31e:
	/* 0x31e: jle    12c <generic_retkprobe_filter_arg+0x12c> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x31e, 0x12c, x86_l_12c);
x86_l_324:
	/* 0x324: jmp    147 <generic_retkprobe_filter_arg+0x147> */
	X86_SIM_X86_JMP(0x324, 0x147, x86_l_147);
x86_l_230e:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
	/* native subroutine native_link_sub_329 */
x86_l_329:
	/* 0x329: mov    eax,DWORD PTR [rdi+0x4] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_32c:
	/* 0x32c: cmp    rax,0x20 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, 0, 32ULL);
x86_l_330:
	/* 0x330: ja     367 <filter_32ty+0x3e> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x330, 0x367, x86_l_367);
x86_l_332:
	/* 0x332: mov    ecx,0x101e */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 4126ULL);
x86_l_337:
	/* 0x337: bt     rcx,rax */
	X86_SIM_RUN_OP(X86_OP_BT, X86_RCX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_33b:
	/* 0x33b: jae    342 <filter_32ty+0x19> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x33b, 0x342, x86_l_342);
x86_l_33d:
	/* 0x33d: jmp    1ee7 <filter_32ty_selector_val> */
	X86_SIM_X86_SUB_JMP(0x33d, 0x1ee7, x86_l_1ee7);
x86_l_342:
	/* 0x342: mov    ecx,0xc00 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 3072ULL);
x86_l_347:
	/* 0x347: bt     rcx,rax */
	X86_SIM_RUN_OP(X86_OP_BT, X86_RCX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_34b:
	/* 0x34b: jae    352 <filter_32ty+0x29> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x34b, 0x352, x86_l_352);
x86_l_34d:
	/* 0x34d: jmp    d9b <filter_32ty_map> */
	X86_SIM_X86_SUB_JMP(0x34d, 0xd9b, x86_l_d9b);
x86_l_352:
	/* 0x352: movabs rcx,0x180000000 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, 0, 6442450944ULL);
x86_l_35c:
	/* 0x35c: bt     rcx,rax */
	X86_SIM_RUN_OP(X86_OP_BT, X86_RCX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_360:
	/* 0x360: jae    367 <filter_32ty+0x3e> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x360, 0x367, x86_l_367);
x86_l_362:
	/* 0x362: jmp    20da <filter_32ty_range> */
	X86_SIM_X86_SUB_JMP(0x362, 0x20da, x86_l_20da);
x86_l_367:
	/* 0x367: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_369:
	/* 0x369: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_369);

	/* native subroutine native_link_sub_36a */
x86_l_36a:
	/* 0x36a: push   r15 */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_36c:
	/* 0x36c: push   r14 */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_36e:
	/* 0x36e: push   r12 */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_370:
	/* 0x370: push   rbx */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_371:
	/* 0x371: sub    rsp,0x48 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SUB, 72ULL);
x86_l_375:
	/* 0x375: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_37e:
	/* 0x37e: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_387:
	/* 0x387: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_390:
	/* 0x390: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_399:
	/* 0x399: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_3a2:
	/* 0x3a2: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3a9:
	/* 0x3a9: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_3b1:
	/* 0x3b1: mov    ecx,DWORD PTR [rdi+0xc] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3b4:
	/* 0x3b4: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_3b6:
	/* 0x3b6: lea    edx,[rcx-0x5] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551611ULL);
x86_l_3b9:
	/* 0x3b9: cmp    edx,0x24 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 36ULL);
x86_l_3bc:
	/* 0x3bc: ja     57d <filter_inet+0x213> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x3bc, 0x57d, x86_l_57d);
x86_l_3c2:
	/* Capture image-bound code identity before scheduled instructions. */
	switch (X86_SIM_L_READ_REG(X86_RDX) << 2) {
	case 0ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x3ffULL); break;
	case 4ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x57dULL); break;
	case 8ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x3d2ULL); break;
	case 12ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x57dULL); break;
	case 16ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x57dULL); break;
	case 20ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x57dULL); break;
	case 24ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x57dULL); break;
	case 28ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x57dULL); break;
	case 32ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x57dULL); break;
	case 36ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x57dULL); break;
	case 40ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x57dULL); break;
	case 44ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x57dULL); break;
	case 48ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x57dULL); break;
	case 52ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x57dULL); break;
	case 56ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x57dULL); break;
	case 60ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x57dULL); break;
	case 64ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x57dULL); break;
	case 68ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x57dULL); break;
	case 72ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x57dULL); break;
	case 76ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x57dULL); break;
	case 80ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x57dULL); break;
	case 84ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x57dULL); break;
	case 88ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x57dULL); break;
	case 92ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x57dULL); break;
	case 96ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x57dULL); break;
	case 100ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x57dULL); break;
	case 104ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x57dULL); break;
	case 108ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x57dULL); break;
	case 112ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x57dULL); break;
	case 116ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x57dULL); break;
	case 120ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x57dULL); break;
	case 124ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x57dULL); break;
	case 128ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x57dULL); break;
	case 132ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x57dULL); break;
	case 136ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x57dULL); break;
	case 140ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x3d7ULL); break;
	case 144ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x3d2ULL); break;
	default: __x86_sim_unresolved_indirect_target();
	}
x86_l_3d0:
	/* 0x3d0: jmp    rdx */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RDX);
		switch (X86_SIM_L_REG_TAG(X86_RDX)) {
		case X86_SIM_TAG_CODE:
			switch (__x86_target) {
			case 0x3d2ULL: goto x86_l_3d2;
			case 0x3d7ULL: goto x86_l_3d7;
			case 0x3ffULL: goto x86_l_3ff;
			case 0x57dULL: goto x86_l_57d;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_3d2:
	/* 0x3d2: mov    r8,rsi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R8, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_3d5:
	/* 0x3d5: jmp    402 <filter_inet+0x98> */
	X86_SIM_X86_SUB_JMP(0x3d5, 0x402, x86_l_402);
x86_l_3d7:
	/* 0x3d7: movzx  eax,WORD PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3da:
	/* 0x3da: mov    WORD PTR [rsp+0x46],ax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 70ULL);
x86_l_3df:
	/* 0x3df: movzx  eax,WORD PTR [rsi+0x2] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_3e3:
	/* 0x3e3: mov    WORD PTR [rsp+0x40],ax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3e8:
	/* 0x3e8: mov    rax,QWORD PTR [rsi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3ec:
	/* 0x3ec: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3f1:
	/* 0x3f1: mov    rax,QWORD PTR [rsi+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3f5:
	/* 0x3f5: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3fa:
	/* 0x3fa: lea    rsi,[rsp+0x20] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3ff:
	/* 0x3ff: xor    r8d,r8d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_402:
	/* 0x402: mov    edx,DWORD PTR [rdi+0x4] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_405:
	/* 0x405: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_407:
	/* 0x407: add    edx,0xfffffff3 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 4294967283ULL);
x86_l_40a:
	/* 0x40a: cmp    edx,0x10 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 16ULL);
x86_l_40d:
	/* 0x40d: ja     57d <filter_inet+0x213> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x40d, 0x57d, x86_l_57d);
x86_l_413:
	/* Capture image-bound code identity before scheduled instructions. */
	switch (X86_SIM_L_READ_REG(X86_RDX) << 2) {
	case 0ULL: X86_SIM_X86_CODE_ADDRESS(X86_R10, 0x44eULL); break;
	case 4ULL: X86_SIM_X86_CODE_ADDRESS(X86_R10, 0x444ULL); break;
	case 8ULL: X86_SIM_X86_CODE_ADDRESS(X86_R10, 0x424ULL); break;
	case 12ULL: X86_SIM_X86_CODE_ADDRESS(X86_R10, 0x42aULL); break;
	case 16ULL: X86_SIM_X86_CODE_ADDRESS(X86_R10, 0x55cULL); break;
	case 20ULL: X86_SIM_X86_CODE_ADDRESS(X86_R10, 0x424ULL); break;
	case 24ULL: X86_SIM_X86_CODE_ADDRESS(X86_R10, 0x42aULL); break;
	case 28ULL: X86_SIM_X86_CODE_ADDRESS(X86_R10, 0x424ULL); break;
	case 32ULL: X86_SIM_X86_CODE_ADDRESS(X86_R10, 0x424ULL); break;
	case 36ULL: X86_SIM_X86_CODE_ADDRESS(X86_R10, 0x42aULL); break;
	case 40ULL: X86_SIM_X86_CODE_ADDRESS(X86_R10, 0x42aULL); break;
	case 44ULL: X86_SIM_X86_CODE_ADDRESS(X86_R10, 0x44eULL); break;
	case 48ULL: X86_SIM_X86_CODE_ADDRESS(X86_R10, 0x444ULL); break;
	case 52ULL: X86_SIM_X86_CODE_ADDRESS(X86_R10, 0x57dULL); break;
	case 56ULL: X86_SIM_X86_CODE_ADDRESS(X86_R10, 0x57dULL); break;
	case 60ULL: X86_SIM_X86_CODE_ADDRESS(X86_R10, 0x56eULL); break;
	case 64ULL: X86_SIM_X86_CODE_ADDRESS(X86_R10, 0x562ULL); break;
	default: __x86_sim_unresolved_indirect_target();
	}
x86_l_421:
	/* 0x421: jmp    r10 */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_R10);
		switch (X86_SIM_L_REG_TAG(X86_R10)) {
		case X86_SIM_TAG_CODE:
			switch (__x86_target) {
			case 0x424ULL: goto x86_l_424;
			case 0x42aULL: goto x86_l_42a;
			case 0x444ULL: goto x86_l_444;
			case 0x44eULL: goto x86_l_44e;
			case 0x55cULL: goto x86_l_55c;
			case 0x562ULL: goto x86_l_562;
			case 0x56eULL: goto x86_l_56e;
			case 0x57dULL: goto x86_l_57d;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_424:
	/* 0x424: movzx  ecx,WORD PTR [rsi+0x20] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_428:
	/* 0x428: jmp    42e <filter_inet+0xc4> */
	X86_SIM_X86_SUB_JMP(0x428, 0x42e, x86_l_42e);
x86_l_42a:
	/* 0x42a: movzx  ecx,WORD PTR [rsi+0x22] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_42e:
	/* 0x42e: mov    DWORD PTR [rsp+0x4],ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_432:
	/* 0x432: xor    ebx,ebx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_434:
	/* 0x434: xor    r15d,r15d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_437:
	/* 0x437: xor    r14d,r14d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_43a:
	/* 0x43a: cmp    edx,0xc */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 12ULL);
x86_l_43d:
	/* 0x43d: jbe    467 <filter_inet+0xfd> */
	X86_SIM_X86_SUB_JCC(X86_CC_BE, 0x43d, 0x467, x86_l_467);
x86_l_43f:
	/* 0x43f: jmp    5bd <filter_inet+0x253> */
	X86_SIM_X86_SUB_JMP(0x43f, 0x5bd, x86_l_5bd);
x86_l_444:
	/* 0x444: mov    rbx,QWORD PTR [rsi+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_448:
	/* 0x448: mov    r14,QWORD PTR [rsi+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_44c:
	/* 0x44c: jmp    455 <filter_inet+0xeb> */
	X86_SIM_X86_SUB_JMP(0x44c, 0x455, x86_l_455);
x86_l_44e:
	/* 0x44e: mov    rbx,QWORD PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_451:
	/* 0x451: mov    r14,QWORD PTR [rsi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_455:
	/* 0x455: mov    r15,rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R15, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_458:
	/* 0x458: shr    r15,0x20 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_45c:
	/* 0x45c: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_45e:
	/* 0x45e: cmp    edx,0xc */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 12ULL);
x86_l_461:
	/* 0x461: ja     5bd <filter_inet+0x253> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x461, 0x5bd, x86_l_5bd);
x86_l_467:
	/* Capture image-bound code identity before scheduled instructions. */
	switch (X86_SIM_L_READ_REG(X86_RDX) << 2) {
	case 0ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x477ULL); break;
	case 4ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x477ULL); break;
	case 8ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x4bbULL); break;
	case 12ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x4bbULL); break;
	case 16ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x575ULL); break;
	case 20ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x4bbULL); break;
	case 24ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x4bbULL); break;
	case 28ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x4c5ULL); break;
	case 32ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x4d5ULL); break;
	case 36ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x4c5ULL); break;
	case 40ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x4d5ULL); break;
	case 44ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x477ULL); break;
	case 48ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x477ULL); break;
	default: __x86_sim_unresolved_indirect_target();
	}
x86_l_475:
	/* 0x475: jmp    rdx */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RDX);
		switch (X86_SIM_L_REG_TAG(X86_RDX)) {
		case X86_SIM_TAG_CODE:
			switch (__x86_target) {
			case 0x477ULL: goto x86_l_477;
			case 0x4bbULL: goto x86_l_4bb;
			case 0x4c5ULL: goto x86_l_4c5;
			case 0x4d5ULL: goto x86_l_4d5;
			case 0x575ULL: goto x86_l_575;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_477:
	/* 0x477: movzx  eax,WORD PTR [rsi+0x26] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_47b:
	/* 0x47b: cmp    eax,0xa */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 10ULL);
x86_l_47e:
	/* 0x47e: je     4e5 <filter_inet+0x17b> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x47e, 0x4e5, x86_l_4e5);
x86_l_480:
	/* 0x480: cmp    eax,0x2 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_483:
	/* 0x483: jne    555 <filter_inet+0x1eb> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x483, 0x555, x86_l_555);
x86_l_489:
	/* 0x489: mov    r12,rdi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R12, X86_RDI, X86_WIDTH_64, 0, 0);
x86_l_48c:
	/* 0x48c: mov    eax,DWORD PTR [rdi+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_48f:
	/* 0x48f: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_493:
	/* 0x493: mov    rdi,QWORD PTR [rip+0x16c0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)addr4lpm_maps));
x86_l_49a:
	/* 0x49a: lea    rsi,[rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_49f:
	/* 0x49f: call   1b64 <filter_64ty_selector_val+0xdd> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_4a4:
	/* 0x4a4: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_4a7:
	/* 0x4a7: je     589 <filter_inet+0x21f> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x4a7, 0x589, x86_l_589);
x86_l_4ad:
	/* 0x4ad: mov    DWORD PTR [rsp+0xc],0x20 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607584ULL);
x86_l_4b5:
	/* 0x4b5: mov    DWORD PTR [rsp+0x10],ebx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4b9:
	/* 0x4b9: jmp    528 <filter_inet+0x1be> */
	X86_SIM_X86_SUB_JMP(0x4b9, 0x528, x86_l_528);
x86_l_4bb:
	/* 0x4bb: lea    rsi,[rsp+0x4] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4c0:
	/* 0x4c0: jmp    578 <filter_inet+0x20e> */
	X86_SIM_X86_SUB_JMP(0x4c0, 0x578, x86_l_578);
x86_l_4c5:
	/* 0x4c5: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_4c7:
	/* 0x4c7: cmp    ecx,0x400 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 1024ULL);
x86_l_4cd:
	/* 0x4cd: setb   al */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_CC_B, 0);
x86_l_4d0:
	/* 0x4d0: jmp    57d <filter_inet+0x213> */
	X86_SIM_X86_SUB_JMP(0x4d0, 0x57d, x86_l_57d);
x86_l_4d5:
	/* 0x4d5: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_4d7:
	/* 0x4d7: cmp    ecx,0x400 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 1024ULL);
x86_l_4dd:
	/* 0x4dd: setae  al */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_CC_AE, 0);
x86_l_4e0:
	/* 0x4e0: jmp    57d <filter_inet+0x213> */
	X86_SIM_X86_SUB_JMP(0x4e0, 0x57d, x86_l_57d);
x86_l_4e5:
	/* 0x4e5: mov    r12,rdi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R12, X86_RDI, X86_WIDTH_64, 0, 0);
x86_l_4e8:
	/* 0x4e8: mov    eax,DWORD PTR [rdi+0x14] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_4eb:
	/* 0x4eb: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ef:
	/* 0x4ef: mov    rdi,QWORD PTR [rip+0x16c0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)addr6lpm_maps));
x86_l_4f6:
	/* 0x4f6: lea    rsi,[rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4fb:
	/* 0x4fb: call   1bc0 <filter_64ty_selector_val+0x139> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_500:
	/* 0x500: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_503:
	/* 0x503: je     589 <filter_inet+0x21f> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x503, 0x589, x86_l_589);
x86_l_509:
	/* 0x509: mov    DWORD PTR [rsp+0xc],0x80 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607680ULL);
x86_l_511:
	/* 0x511: mov    DWORD PTR [rsp+0x10],ebx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_515:
	/* 0x515: mov    DWORD PTR [rsp+0x14],r15d */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_51a:
	/* 0x51a: mov    DWORD PTR [rsp+0x18],r14d */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_51f:
	/* 0x51f: shr    r14,0x20 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_523:
	/* 0x523: mov    DWORD PTR [rsp+0x1c],r14d */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_528:
	/* 0x528: lea    rsi,[rsp+0xc] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_52d:
	/* 0x52d: mov    rdi,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_530:
	/* 0x530: call   1bf5 <filter_64ty_selector_val+0x16e> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_535:
	/* 0x535: mov    ecx,DWORD PTR [r12+0x4] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_53a:
	/* 0x53a: lea    edx,[rcx-0x18] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551592ULL);
x86_l_53d:
	/* 0x53d: cmp    edx,0x2 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_540:
	/* 0x540: jb     596 <filter_inet+0x22c> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x540, 0x596, x86_l_596);
x86_l_542:
	/* 0x542: add    ecx,0xfffffff3 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 4294967283ULL);
x86_l_545:
	/* 0x545: cmp    ecx,0x1 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_548:
	/* 0x548: ja     555 <filter_inet+0x1eb> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x548, 0x555, x86_l_555);
x86_l_54a:
	/* 0x54a: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_54d:
	/* 0x54d: setne  al */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_CC_NE, 0);
x86_l_550:
	/* 0x550: movzx  eax,al */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8, 0);
x86_l_553:
	/* 0x553: jmp    57d <filter_inet+0x213> */
	X86_SIM_X86_SUB_JMP(0x553, 0x57d, x86_l_57d);
x86_l_555:
	/* 0x555: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_557:
	/* 0x557: movzx  eax,al */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8, 0);
x86_l_55a:
	/* 0x55a: jmp    57d <filter_inet+0x213> */
	X86_SIM_X86_SUB_JMP(0x55a, 0x57d, x86_l_57d);
x86_l_55c:
	/* 0x55c: movzx  eax,WORD PTR [rsi+0x24] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_560:
	/* 0x560: jmp    572 <filter_inet+0x208> */
	X86_SIM_X86_SUB_JMP(0x560, 0x572, x86_l_572);
x86_l_562:
	/* 0x562: cmp    ecx,0x7 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 7ULL);
x86_l_565:
	/* 0x565: jne    5a1 <filter_inet+0x237> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x565, 0x5a1, x86_l_5a1);
x86_l_567:
	/* 0x567: test   r8,r8 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R8, X86_R8, X86_WIDTH_64, 0, 0);
x86_l_56a:
	/* 0x56a: jne    5ab <filter_inet+0x241> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x56a, 0x5ab, x86_l_5ab);
x86_l_56c:
	/* 0x56c: jmp    575 <filter_inet+0x20b> */
	X86_SIM_X86_SUB_JMP(0x56c, 0x575, x86_l_575);
x86_l_56e:
	/* 0x56e: movzx  eax,WORD PTR [rsi+0x26] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_572:
	/* 0x572: mov    DWORD PTR [rsp],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_575:
	/* 0x575: mov    rsi,rsp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_RSP, X86_WIDTH_64, 0, 0);
x86_l_578:
	/* 0x578: call   d9b <filter_32ty_map> */
	X86_SIM_X86_CALL(x86_l_d9b, 0x57dULL);
x86_l_57d:
	/* 0x57d: add    rsp,0x48 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 72ULL);
x86_l_581:
	/* 0x581: pop    rbx */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_582:
	/* 0x582: pop    r12 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R12, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_584:
	/* 0x584: pop    r14 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R14, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_586:
	/* 0x586: pop    r15 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R15, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_588:
	/* 0x588: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_588);
x86_l_589:
	/* 0x589: mov    eax,DWORD PTR [r12+0x4] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_58e:
	/* 0x58e: and    eax,0xfffffffe */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_591:
	/* 0x591: cmp    eax,0x18 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 24ULL);
x86_l_594:
	/* 0x594: jmp    599 <filter_inet+0x22f> */
	X86_SIM_X86_SUB_JMP(0x594, 0x599, x86_l_599);
x86_l_596:
	/* 0x596: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_599:
	/* 0x599: sete   al */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_CC_E, 0);
x86_l_59c:
	/* 0x59c: movzx  eax,al */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8, 0);
x86_l_59f:
	/* 0x59f: jmp    57d <filter_inet+0x213> */
	X86_SIM_X86_SUB_JMP(0x59f, 0x57d, x86_l_57d);
x86_l_5a1:
	/* 0x5a1: cmp    ecx,0x29 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 41ULL);
x86_l_5a4:
	/* 0x5a4: jne    5b3 <filter_inet+0x249> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x5a4, 0x5b3, x86_l_5b3);
x86_l_5a6:
	/* 0x5a6: test   r8,r8 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R8, X86_R8, X86_WIDTH_64, 0, 0);
x86_l_5a9:
	/* 0x5a9: je     5b3 <filter_inet+0x249> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x5a9, 0x5b3, x86_l_5b3);
x86_l_5ab:
	/* 0x5ab: movzx  eax,BYTE PTR [r8+0x3a] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R8, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 58ULL);
x86_l_5b0:
	/* 0x5b0: mov    DWORD PTR [rsp],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5b3:
	/* 0x5b3: cmp    ecx,0x29 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 41ULL);
x86_l_5b6:
	/* 0x5b6: je     575 <filter_inet+0x20b> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x5b6, 0x575, x86_l_575);
x86_l_5b8:
	/* 0x5b8: cmp    ecx,0x7 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 7ULL);
x86_l_5bb:
	/* 0x5bb: je     575 <filter_inet+0x20b> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x5bb, 0x575, x86_l_575);
x86_l_5bd:
	/* 0x5bd: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_5bf:
	/* 0x5bf: jmp    57d <filter_inet+0x213> */
	X86_SIM_X86_SUB_JMP(0x5bf, 0x57d, x86_l_57d);

	/* native subroutine native_link_sub_5c1 */
x86_l_5c1:
	/* 0x5c1: mov    eax,DWORD PTR [rdi+0x4] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_5c4:
	/* 0x5c4: cmp    rax,0x20 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, 0, 32ULL);
x86_l_5c8:
	/* 0x5c8: ja     5ff <filter_64ty+0x3e> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x5c8, 0x5ff, x86_l_5ff);
x86_l_5ca:
	/* 0x5ca: mov    ecx,0x101e */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 4126ULL);
x86_l_5cf:
	/* 0x5cf: bt     rcx,rax */
	X86_SIM_RUN_OP(X86_OP_BT, X86_RCX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_5d3:
	/* 0x5d3: jae    5da <filter_64ty+0x19> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x5d3, 0x5da, x86_l_5da);
x86_l_5d5:
	/* 0x5d5: jmp    1a87 <filter_64ty_selector_val> */
	X86_SIM_X86_SUB_JMP(0x5d5, 0x1a87, x86_l_1a87);
x86_l_5da:
	/* 0x5da: mov    ecx,0xc00 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 3072ULL);
x86_l_5df:
	/* 0x5df: bt     rcx,rax */
	X86_SIM_RUN_OP(X86_OP_BT, X86_RCX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_5e3:
	/* 0x5e3: jae    5ea <filter_64ty+0x29> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x5e3, 0x5ea, x86_l_5ea);
x86_l_5e5:
	/* 0x5e5: jmp    1c98 <filter_64ty_map> */
	X86_SIM_X86_SUB_JMP(0x5e5, 0x1c98, x86_l_1c98);
x86_l_5ea:
	/* 0x5ea: movabs rcx,0x180000000 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, 0, 6442450944ULL);
x86_l_5f4:
	/* 0x5f4: bt     rcx,rax */
	X86_SIM_RUN_OP(X86_OP_BT, X86_RCX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_5f8:
	/* 0x5f8: jae    5ff <filter_64ty+0x3e> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x5f8, 0x5ff, x86_l_5ff);
x86_l_5fa:
	/* 0x5fa: jmp    1d0c <filter_64ty_range> */
	X86_SIM_X86_SUB_JMP(0x5fa, 0x1d0c, x86_l_1d0c);
x86_l_5ff:
	/* 0x5ff: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_601:
	/* 0x601: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_601);

	/* native subroutine native_link_sub_602 */
x86_l_602:
	/* 0x602: push   rbx */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_603:
	/* 0x603: mov    rbx,rdi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RBX, X86_RDI, X86_WIDTH_64, 0, 0);
x86_l_606:
	/* 0x606: mov    edi,DWORD PTR [rdi+0x4] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_609:
	/* 0x609: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_60b:
	/* 0x60b: lea    r8d,[rdi-0x3] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R8, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_60f:
	/* 0x60f: cmp    r8d,0x1f */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, 0, 31ULL);
x86_l_613:
	/* 0x613: ja     66a <filter_char_buf+0x68> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x613, 0x66a, x86_l_66a);
x86_l_615:
	/* 0x615: mov    rcx,rsi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_618:
	/* 0x618: movsxd rsi,edx */
	X86_SIM_RUN_OP(X86_OP_MOVSX_REG, X86_RSI, X86_RDX, X86_WIDTH_64, X86_WIDTH_32, 0);
x86_l_61b:
	/* 0x61b: mov    edx,DWORD PTR [rcx+rsi*1-0x4] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 0), 18446744073709551612ULL);
x86_l_61f:
	/* 0x61f: mov    esi,esi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_621:
	/* 0x621: add    rsi,rcx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_624:
	/* Capture image-bound code identity before scheduled instructions. */
	switch (X86_SIM_L_READ_REG(X86_R8) << 2) {
	case 0ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x635ULL); break;
	case 4ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x635ULL); break;
	case 8ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x66aULL); break;
	case 12ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x66aULL); break;
	case 16ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x66aULL); break;
	case 20ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x649ULL); break;
	case 24ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x63fULL); break;
	case 28ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x66aULL); break;
	case 32ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x66aULL); break;
	case 36ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x66aULL); break;
	case 40ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x66aULL); break;
	case 44ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x66aULL); break;
	case 48ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x66aULL); break;
	case 52ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x66aULL); break;
	case 56ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x66aULL); break;
	case 60ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x66aULL); break;
	case 64ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x66aULL); break;
	case 68ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x66aULL); break;
	case 72ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x66aULL); break;
	case 76ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x66aULL); break;
	case 80ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x66aULL); break;
	case 84ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x66aULL); break;
	case 88ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x66aULL); break;
	case 92ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x649ULL); break;
	case 96ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x63fULL); break;
	case 100ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x66aULL); break;
	case 104ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x66aULL); break;
	case 108ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x66aULL); break;
	case 112ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x66aULL); break;
	case 116ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x66aULL); break;
	case 120ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x653ULL); break;
	case 124ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x65aULL); break;
	default: __x86_sim_unresolved_indirect_target();
	}
x86_l_632:
	/* 0x632: jmp    r8 */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_R8);
		switch (X86_SIM_L_REG_TAG(X86_R8)) {
		case X86_SIM_TAG_CODE:
			switch (__x86_target) {
			case 0x635ULL: goto x86_l_635;
			case 0x63fULL: goto x86_l_63f;
			case 0x649ULL: goto x86_l_649;
			case 0x653ULL: goto x86_l_653;
			case 0x65aULL: goto x86_l_65a;
			case 0x66aULL: goto x86_l_66a;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_635:
	/* 0x635: mov    rdi,rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_638:
	/* 0x638: call   83d <filter_char_buf_equal> */
	X86_SIM_X86_CALL(x86_l_83d, 0x63dULL);
x86_l_63d:
	/* 0x63d: jmp    667 <filter_char_buf+0x65> */
	X86_SIM_X86_SUB_JMP(0x63d, 0x667, x86_l_667);
x86_l_63f:
	/* 0x63f: mov    edi,DWORD PTR [rbx+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_642:
	/* 0x642: call   ed5 <filter_char_buf_postfix> */
	X86_SIM_X86_CALL(x86_l_ed5, 0x647ULL);
x86_l_647:
	/* 0x647: jmp    667 <filter_char_buf+0x65> */
	X86_SIM_X86_SUB_JMP(0x647, 0x667, x86_l_667);
x86_l_649:
	/* 0x649: mov    edi,DWORD PTR [rbx+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_64c:
	/* 0x64c: call   c7c <filter_char_buf_prefix> */
	X86_SIM_X86_CALL(x86_l_c7c, 0x651ULL);
x86_l_651:
	/* 0x651: jmp    667 <filter_char_buf+0x65> */
	X86_SIM_X86_SUB_JMP(0x651, 0x667, x86_l_667);
x86_l_653:
	/* 0x653: mov    rdi,rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_656:
	/* 0x656: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_658:
	/* 0x658: jmp    662 <filter_char_buf+0x60> */
	X86_SIM_X86_SUB_JMP(0x658, 0x662, x86_l_662);
x86_l_65a:
	/* 0x65a: mov    rdi,rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_65d:
	/* 0x65d: mov    ecx,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_662:
	/* 0x662: call   187d <filter_char_substring> */
	X86_SIM_X86_CALL(x86_l_187d, 0x667ULL);
x86_l_667:
	/* 0x667: mov    edi,DWORD PTR [rbx+0x4] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_66a:
	/* 0x66a: cmp    edi,0x25 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 37ULL);
x86_l_66d:
	/* 0x66d: ja     68c <filter_char_buf+0x8a> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x66d, 0x68c, x86_l_68c);
x86_l_66f:
	/* 0x66f: mov    ecx,edi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RDI, X86_WIDTH_32, 0, 0);
x86_l_671:
	/* 0x671: movabs rdx,0x200c000050 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, 0, 137640280144ULL);
x86_l_67b:
	/* 0x67b: bt     rdx,rcx */
	X86_SIM_RUN_OP(X86_OP_BT, X86_RDX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_67f:
	/* 0x67f: jae    68c <filter_char_buf+0x8a> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x67f, 0x68c, x86_l_68c);
x86_l_681:
	/* 0x681: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_683:
	/* 0x683: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_686:
	/* 0x686: sete   cl */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_CC_E, 0);
x86_l_689:
	/* 0x689: mov    rax,rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_68c:
	/* 0x68c: pop    rbx */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_68d:
	/* 0x68d: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_68d);

	/* native subroutine native_link_sub_68e */
x86_l_68e:
	/* 0x68e: mov    eax,DWORD PTR [rdi+0x4] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_691:
	/* 0x691: cmp    rax,0x20 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, 0, 32ULL);
x86_l_695:
	/* 0x695: ja     6cc <filter_8ty+0x3e> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x695, 0x6cc, x86_l_6cc);
x86_l_697:
	/* 0x697: mov    ecx,0x101e */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 4126ULL);
x86_l_69c:
	/* 0x69c: bt     rcx,rax */
	X86_SIM_RUN_OP(X86_OP_BT, X86_RCX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_6a0:
	/* 0x6a0: jae    6a7 <filter_8ty+0x19> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x6a0, 0x6a7, x86_l_6a7);
x86_l_6a2:
	/* 0x6a2: jmp    144a <filter_8ty_selector_val> */
	X86_SIM_X86_SUB_JMP(0x6a2, 0x144a, x86_l_144a);
x86_l_6a7:
	/* 0x6a7: mov    ecx,0xc00 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 3072ULL);
x86_l_6ac:
	/* 0x6ac: bt     rcx,rax */
	X86_SIM_RUN_OP(X86_OP_BT, X86_RCX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_6b0:
	/* 0x6b0: jae    6b7 <filter_8ty+0x29> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x6b0, 0x6b7, x86_l_6b7);
x86_l_6b2:
	/* 0x6b2: jmp    1643 <filter_8ty_map> */
	X86_SIM_X86_SUB_JMP(0x6b2, 0x1643, x86_l_1643);
x86_l_6b7:
	/* 0x6b7: movabs rcx,0x180000000 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, 0, 6442450944ULL);
x86_l_6c1:
	/* 0x6c1: bt     rcx,rax */
	X86_SIM_RUN_OP(X86_OP_BT, X86_RCX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_6c5:
	/* 0x6c5: jae    6cc <filter_8ty+0x3e> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x6c5, 0x6cc, x86_l_6cc);
x86_l_6c7:
	/* 0x6c7: jmp    16c5 <filter_8ty_range> */
	X86_SIM_X86_SUB_JMP(0x6c7, 0x16c5, x86_l_16c5);
x86_l_6cc:
	/* 0x6cc: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_6ce:
	/* 0x6ce: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_6ce);

	/* native subroutine native_link_sub_6cf */
x86_l_6cf:
	/* 0x6cf: mov    eax,DWORD PTR [rdi+0x4] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_6d2:
	/* 0x6d2: cmp    rax,0x20 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, 0, 32ULL);
x86_l_6d6:
	/* 0x6d6: ja     70d <filter_16ty+0x3e> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x6d6, 0x70d, x86_l_70d);
x86_l_6d8:
	/* 0x6d8: mov    ecx,0x101e */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 4126ULL);
x86_l_6dd:
	/* 0x6dd: bt     rcx,rax */
	X86_SIM_RUN_OP(X86_OP_BT, X86_RCX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_6e1:
	/* 0x6e1: jae    6e8 <filter_16ty+0x19> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x6e1, 0x6e8, x86_l_6e8);
x86_l_6e3:
	/* 0x6e3: jmp    1017 <filter_16ty_selector_val> */
	X86_SIM_X86_SUB_JMP(0x6e3, 0x1017, x86_l_1017);
x86_l_6e8:
	/* 0x6e8: mov    ecx,0xc00 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 3072ULL);
x86_l_6ed:
	/* 0x6ed: bt     rcx,rax */
	X86_SIM_RUN_OP(X86_OP_BT, X86_RCX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_6f1:
	/* 0x6f1: jae    6f8 <filter_16ty+0x29> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x6f1, 0x6f8, x86_l_6f8);
x86_l_6f3:
	/* 0x6f3: jmp    1210 <filter_16ty_map> */
	X86_SIM_X86_SUB_JMP(0x6f3, 0x1210, x86_l_1210);
x86_l_6f8:
	/* 0x6f8: movabs rcx,0x180000000 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, 0, 6442450944ULL);
x86_l_702:
	/* 0x702: bt     rcx,rax */
	X86_SIM_RUN_OP(X86_OP_BT, X86_RCX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_706:
	/* 0x706: jae    70d <filter_16ty+0x3e> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x706, 0x70d, x86_l_70d);
x86_l_708:
	/* 0x708: jmp    1292 <filter_16ty_range> */
	X86_SIM_X86_SUB_JMP(0x708, 0x1292, x86_l_1292);
x86_l_70d:
	/* 0x70d: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_70f:
	/* 0x70f: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_70f);

	/* native subroutine native_link_sub_710 */
x86_l_710:
	/* 0x710: push   rbx */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_711:
	/* 0x711: mov    rbx,rdi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RBX, X86_RDI, X86_WIDTH_64, 0, 0);
x86_l_714:
	/* 0x714: mov    edx,DWORD PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_716:
	/* 0x716: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_719:
	/* 0x719: test   edx,edx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_71b:
	/* 0x71b: jne    72b <filter_file_buf+0x1b> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x71b, 0x72b, x86_l_72b);
x86_l_71d:
	/* 0x71d: mov    eax,ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_71f:
	/* 0x71f: and    eax,0xfffffffe */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_722:
	/* 0x722: cmp    eax,0x24 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 36ULL);
x86_l_725:
	/* 0x725: je     72b <filter_file_buf+0x1b> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x725, 0x72b, x86_l_72b);
x86_l_727:
	/* 0x727: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_729:
	/* 0x729: pop    rbx */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_72a:
	/* 0x72a: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_72a);
x86_l_72b:
	/* 0x72b: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_72d:
	/* 0x72d: lea    edi,[rcx-0x3] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_730:
	/* 0x730: cmp    edi,0x22 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 34ULL);
x86_l_733:
	/* 0x733: ja     77a <filter_file_buf+0x6a> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x733, 0x77a, x86_l_77a);
x86_l_735:
	/* Capture image-bound code identity before scheduled instructions. */
	switch (X86_SIM_L_READ_REG(X86_RDI) << 2) {
	case 0ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDI, 0x745ULL); break;
	case 4ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDI, 0x745ULL); break;
	case 8ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDI, 0x77aULL); break;
	case 12ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDI, 0x77aULL); break;
	case 16ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDI, 0x77aULL); break;
	case 20ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDI, 0x76bULL); break;
	case 24ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDI, 0x75dULL); break;
	case 28ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDI, 0x77aULL); break;
	case 32ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDI, 0x77aULL); break;
	case 36ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDI, 0x77aULL); break;
	case 40ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDI, 0x77aULL); break;
	case 44ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDI, 0x77aULL); break;
	case 48ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDI, 0x77aULL); break;
	case 52ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDI, 0x77aULL); break;
	case 56ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDI, 0x77aULL); break;
	case 60ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDI, 0x77aULL); break;
	case 64ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDI, 0x77aULL); break;
	case 68ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDI, 0x77aULL); break;
	case 72ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDI, 0x77aULL); break;
	case 76ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDI, 0x77aULL); break;
	case 80ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDI, 0x77aULL); break;
	case 84ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDI, 0x77aULL); break;
	case 88ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDI, 0x77aULL); break;
	case 92ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDI, 0x76bULL); break;
	case 96ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDI, 0x75dULL); break;
	case 100ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDI, 0x77aULL); break;
	case 104ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDI, 0x77aULL); break;
	case 108ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDI, 0x77aULL); break;
	case 112ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDI, 0x77aULL); break;
	case 116ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDI, 0x77aULL); break;
	case 120ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDI, 0x77aULL); break;
	case 124ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDI, 0x77aULL); break;
	case 128ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDI, 0x77aULL); break;
	case 132ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDI, 0x753ULL); break;
	case 136ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDI, 0x753ULL); break;
	default: __x86_sim_unresolved_indirect_target();
	}
x86_l_743:
	/* 0x743: jmp    rdi */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RDI);
		switch (X86_SIM_L_REG_TAG(X86_RDI)) {
		case X86_SIM_TAG_CODE:
			switch (__x86_target) {
			case 0x745ULL: goto x86_l_745;
			case 0x753ULL: goto x86_l_753;
			case 0x75dULL: goto x86_l_75d;
			case 0x76bULL: goto x86_l_76b;
			case 0x77aULL: goto x86_l_77a;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_745:
	/* 0x745: add    rsi,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_749:
	/* 0x749: mov    rdi,rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_74c:
	/* 0x74c: call   83d <filter_char_buf_equal> */
	X86_SIM_X86_CALL(x86_l_83d, 0x751ULL);
x86_l_751:
	/* 0x751: jmp    777 <filter_file_buf+0x67> */
	X86_SIM_X86_SUB_JMP(0x751, 0x777, x86_l_777);
x86_l_753:
	/* 0x753: mov    rdi,rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_756:
	/* 0x756: call   e1c <filter_file_type> */
	X86_SIM_X86_CALL(x86_l_e1c, 0x75bULL);
x86_l_75b:
	/* 0x75b: jmp    777 <filter_file_buf+0x67> */
	X86_SIM_X86_SUB_JMP(0x75b, 0x777, x86_l_777);
x86_l_75d:
	/* 0x75d: add    rsi,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_761:
	/* 0x761: mov    edi,DWORD PTR [rbx+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_764:
	/* 0x764: call   ed5 <filter_char_buf_postfix> */
	X86_SIM_X86_CALL(x86_l_ed5, 0x769ULL);
x86_l_769:
	/* 0x769: jmp    777 <filter_file_buf+0x67> */
	X86_SIM_X86_SUB_JMP(0x769, 0x777, x86_l_777);
x86_l_76b:
	/* 0x76b: add    rsi,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_76f:
	/* 0x76f: mov    edi,DWORD PTR [rbx+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_772:
	/* 0x772: call   c7c <filter_char_buf_prefix> */
	X86_SIM_X86_CALL(x86_l_c7c, 0x777ULL);
x86_l_777:
	/* 0x777: mov    ecx,DWORD PTR [rbx+0x4] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_77a:
	/* 0x77a: cmp    ecx,0x25 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 37ULL);
x86_l_77d:
	/* 0x77d: ja     795 <filter_file_buf+0x85> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x77d, 0x795, x86_l_795);
x86_l_77f:
	/* 0x77f: mov    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_781:
	/* 0x781: movabs rdx,0x200c000050 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, 0, 137640280144ULL);
x86_l_78b:
	/* 0x78b: bt     rdx,rcx */
	X86_SIM_RUN_OP(X86_OP_BT, X86_RDX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_78f:
	/* 0x78f: jae    795 <filter_file_buf+0x85> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x78f, 0x795, x86_l_795);
x86_l_791:
	/* 0x791: xor    rax,0x1 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_XOR, 1ULL);
x86_l_795:
	/* 0x795: pop    rbx */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_796:
	/* 0x796: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_72a);

	/* native subroutine native_link_sub_797 */
x86_l_797:
	/* 0x797: push   rbx */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_798:
	/* 0x798: sub    rsp,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SUB, 16ULL);
x86_l_79c:
	/* 0x79c: mov    r8d,DWORD PTR [rdi+0x4] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R8, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_7a0:
	/* 0x7a0: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_7a2:
	/* 0x7a2: add    r8d,0xfffffffd */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 4294967293ULL);
x86_l_7a6:
	/* 0x7a6: cmp    r8d,0x19 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, 0, 25ULL);
x86_l_7aa:
	/* 0x7aa: ja     7ed <filter_sockaddr_un+0x56> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x7aa, 0x7ed, x86_l_7ed);
x86_l_7ac:
	/* 0x7ac: lea    rcx,[rsi+0x4] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_7b0:
	/* 0x7b0: movzx  edx,BYTE PTR [rsi+0x3] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 3ULL);
x86_l_7b4:
	/* Capture image-bound code identity before scheduled instructions. */
	switch (X86_SIM_L_READ_REG(X86_R8) << 2) {
	case 0ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x7c5ULL); break;
	case 4ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x7c5ULL); break;
	case 8ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x7edULL); break;
	case 12ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x7edULL); break;
	case 16ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x7edULL); break;
	case 20ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x7f3ULL); break;
	case 24ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x7edULL); break;
	case 28ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x7edULL); break;
	case 32ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x7edULL); break;
	case 36ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x7edULL); break;
	case 40ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x7edULL); break;
	case 44ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x7edULL); break;
	case 48ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x7edULL); break;
	case 52ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x7edULL); break;
	case 56ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x7edULL); break;
	case 60ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x7edULL); break;
	case 64ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x7edULL); break;
	case 68ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x7edULL); break;
	case 72ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x7edULL); break;
	case 76ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x7edULL); break;
	case 80ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x7edULL); break;
	case 84ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x7edULL); break;
	case 88ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x7edULL); break;
	case 92ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x7f3ULL); break;
	case 96ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x7edULL); break;
	case 100ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x826ULL); break;
	default: __x86_sim_unresolved_indirect_target();
	}
x86_l_7c2:
	/* 0x7c2: jmp    r8 */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_R8);
		switch (X86_SIM_L_REG_TAG(X86_R8)) {
		case X86_SIM_TAG_CODE:
			switch (__x86_target) {
			case 0x7c5ULL: goto x86_l_7c5;
			case 0x7edULL: goto x86_l_7ed;
			case 0x7f3ULL: goto x86_l_7f3;
			case 0x826ULL: goto x86_l_826;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_7c5:
	/* 0x7c5: mov    rbx,rdi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RBX, X86_RDI, X86_WIDTH_64, 0, 0);
x86_l_7c8:
	/* 0x7c8: mov    rsi,rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_7cb:
	/* 0x7cb: call   83d <filter_char_buf_equal> */
	X86_SIM_X86_CALL(x86_l_83d, 0x7d0ULL);
x86_l_7d0:
	/* 0x7d0: mov    ecx,DWORD PTR [rbx+0x4] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_7d3:
	/* 0x7d3: cmp    rcx,0x25 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, 0, 37ULL);
x86_l_7d7:
	/* 0x7d7: ja     7ed <filter_sockaddr_un+0x56> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x7d7, 0x7ed, x86_l_7ed);
x86_l_7d9:
	/* 0x7d9: movabs rdx,0x200c000050 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, 0, 137640280144ULL);
x86_l_7e3:
	/* 0x7e3: bt     rdx,rcx */
	X86_SIM_RUN_OP(X86_OP_BT, X86_RDX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_7e7:
	/* 0x7e7: jae    7ed <filter_sockaddr_un+0x56> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x7e7, 0x7ed, x86_l_7ed);
x86_l_7e9:
	/* 0x7e9: xor    rax,0x1 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_XOR, 1ULL);
x86_l_7ed:
	/* 0x7ed: add    rsp,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_7f1:
	/* 0x7f1: pop    rbx */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_7f2:
	/* 0x7f2: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_7f2);
x86_l_7f3:
	/* 0x7f3: mov    eax,DWORD PTR [rdi+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7f6:
	/* 0x7f6: mov    rbx,rdi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RBX, X86_RDI, X86_WIDTH_64, 0, 0);
x86_l_7f9:
	/* 0x7f9: mov    edi,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_7fb:
	/* 0x7fb: mov    rsi,rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_7fe:
	/* 0x7fe: call   c7c <filter_char_buf_prefix> */
	X86_SIM_X86_CALL(x86_l_c7c, 0x803ULL);
x86_l_803:
	/* 0x803: mov    ecx,DWORD PTR [rbx+0x4] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_806:
	/* 0x806: cmp    rcx,0x25 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, 0, 37ULL);
x86_l_80a:
	/* 0x80a: ja     7ed <filter_sockaddr_un+0x56> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x80a, 0x7ed, x86_l_7ed);
x86_l_80c:
	/* 0x80c: movabs rdx,0x200c000050 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, 0, 137640280144ULL);
x86_l_816:
	/* 0x816: bt     rdx,rcx */
	X86_SIM_RUN_OP(X86_OP_BT, X86_RDX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_81a:
	/* 0x81a: jae    7ed <filter_sockaddr_un+0x56> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x81a, 0x7ed, x86_l_7ed);
x86_l_81c:
	/* 0x81c: xor    rax,0x1 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_XOR, 1ULL);
x86_l_820:
	/* 0x820: add    rsp,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_824:
	/* 0x824: pop    rbx */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_825:
	/* 0x825: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_7f2);
x86_l_826:
	/* 0x826: movzx  eax,WORD PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_829:
	/* 0x829: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_82d:
	/* 0x82d: lea    rsi,[rsp+0xc] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_832:
	/* 0x832: call   d9b <filter_32ty_map> */
	X86_SIM_X86_CALL(x86_l_d9b, 0x837ULL);
x86_l_837:
	/* 0x837: add    rsp,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_83b:
	/* 0x83b: pop    rbx */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_83c:
	/* 0x83c: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_7f2);

	/* native subroutine native_link_sub_83d */
x86_l_83d:
	/* 0x83d: push   rbp */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_83e:
	/* 0x83e: push   r15 */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_840:
	/* 0x840: push   r14 */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_842:
	/* 0x842: push   r13 */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_844:
	/* 0x844: push   r12 */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_846:
	/* 0x846: push   rbx */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_847:
	/* 0x847: push   rax */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_848:
	/* 0x848: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_84f:
	/* 0x84f: cmp    edx,0x1000 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 4096ULL);
x86_l_855:
	/* 0x855: ja     b74 <filter_char_buf_equal+0x337> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x855, 0xb74, x86_l_b74);
x86_l_85b:
	/* 0x85b: movzx  eax,dx */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_85e:
	/* 0x85e: cmp    eax,0x90 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 144ULL);
x86_l_863:
	/* 0x863: ja     8b3 <filter_char_buf_equal+0x76> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x863, 0x8b3, x86_l_8b3);
x86_l_865:
	/* 0x865: movzx  eax,dl */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8, 0);
x86_l_868:
	/* 0x868: imul   ecx,eax,0xab */
	X86_SIM_RUN_OP(X86_OP_IMUL_IMM, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 171ULL);
x86_l_86e:
	/* 0x86e: shr    ecx,0x9 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_871:
	/* 0x871: and    ecx,0xfffffff8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_874:
	/* 0x874: lea    ecx,[rcx+rcx*2] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 1), 0ULL);
x86_l_877:
	/* 0x877: sub    al,cl */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB, 0);
x86_l_879:
	/* 0x879: test   dx,dx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_16, 0, 0);
x86_l_87c:
	/* 0x87c: je     887 <filter_char_buf_equal+0x4a> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x87c, 0x887, x86_l_887);
x86_l_87e:
	/* 0x87e: mov    ecx,edx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_880:
	/* 0x880: mov    r15d,edx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R15, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_883:
	/* 0x883: test   al,al */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8, 0, 0);
x86_l_885:
	/* 0x885: je     8a0 <filter_char_buf_equal+0x63> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x885, 0x8a0, x86_l_8a0);
x86_l_887:
	/* 0x887: movzx  eax,al */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8, 0);
x86_l_88a:
	/* 0x88a: mov    ecx,edx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_88c:
	/* 0x88c: sub    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB, 0);
x86_l_88e:
	/* 0x88e: mov    eax,ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_890:
	/* 0x890: add    eax,0x18 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_893:
	/* 0x893: movzx  r15d,ax */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_897:
	/* 0x897: cmp    cx,0x78 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, 0, 120ULL);
x86_l_89b:
	/* 0x89b: ja     8f1 <filter_char_buf_equal+0xb4> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x89b, 0x8f1, x86_l_8f1);
x86_l_89d:
	/* 0x89d: mov    ecx,r15d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_R15, X86_WIDTH_32, 0, 0);
x86_l_8a0:
	/* 0x8a0: movzx  eax,cl */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8, 0);
x86_l_8a3:
	/* 0x8a3: imul   ebp,eax,0xab */
	X86_SIM_RUN_OP(X86_OP_IMUL_IMM, X86_RBP, X86_RAX, X86_WIDTH_32, 0, 171ULL);
x86_l_8a9:
	/* 0x8a9: shr    ebp,0xc */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHR, 12ULL);
x86_l_8ac:
	/* 0x8ac: dec    ebp */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_8ae:
	/* 0x8ae: jmp    934 <filter_char_buf_equal+0xf7> */
	X86_SIM_X86_SUB_JMP(0x8ae, 0x934, x86_l_934);
x86_l_8b3:
	/* 0x8b3: mov    r15d,0x100 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 256ULL);
x86_l_8b9:
	/* 0x8b9: cmp    eax,0x101 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 257ULL);
x86_l_8be:
	/* 0x8be: jb     8f1 <filter_char_buf_equal+0xb4> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x8be, 0x8f1, x86_l_8f1);
x86_l_8c0:
	/* 0x8c0: mov    r15d,0x200 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 512ULL);
x86_l_8c6:
	/* 0x8c6: cmp    eax,0x201 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 513ULL);
x86_l_8cb:
	/* 0x8cb: jb     8f1 <filter_char_buf_equal+0xb4> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x8cb, 0x8f1, x86_l_8f1);
x86_l_8cd:
	/* 0x8cd: mov    r15d,0x400 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 1024ULL);
x86_l_8d3:
	/* 0x8d3: cmp    eax,0x401 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 1025ULL);
x86_l_8d8:
	/* 0x8d8: jb     8f1 <filter_char_buf_equal+0xb4> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x8d8, 0x8f1, x86_l_8f1);
x86_l_8da:
	/* 0x8da: xor    r15d,r15d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_8dd:
	/* 0x8dd: cmp    eax,0x801 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2049ULL);
x86_l_8e2:
	/* 0x8e2: setae  r15b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_CC_AE, 0);
x86_l_8e6:
	/* 0x8e6: shl    r15d,0xb */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 11ULL);
x86_l_8ea:
	/* 0x8ea: add    r15d,0x800 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 2048ULL);
x86_l_8f1:
	/* 0x8f1: lea    eax,[r15-0x100] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551360ULL);
x86_l_8f8:
	/* 0x8f8: rorx   eax,eax,0x8 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 8ULL);
x86_l_8fe:
	/* 0x8fe: cmp    eax,0x7 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 7ULL);
x86_l_901:
	/* 0x901: ja     92f <filter_char_buf_equal+0xf2> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x901, 0x92f, x86_l_92f);
x86_l_903:
	/* Capture image-bound code identity before scheduled instructions. */
	switch (X86_SIM_L_READ_REG(X86_RAX) << 2) {
	case 0ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x913ULL); break;
	case 4ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x921ULL); break;
	case 8ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x92fULL); break;
	case 12ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x91aULL); break;
	case 16ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x92fULL); break;
	case 20ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x92fULL); break;
	case 24ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x92fULL); break;
	case 28ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x928ULL); break;
	default: __x86_sim_unresolved_indirect_target();
	}
x86_l_911:
	/* 0x911: jmp    rax */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RAX);
		switch (X86_SIM_L_REG_TAG(X86_RAX)) {
		case X86_SIM_TAG_CODE:
			switch (__x86_target) {
			case 0x913ULL: goto x86_l_913;
			case 0x91aULL: goto x86_l_91a;
			case 0x921ULL: goto x86_l_921;
			case 0x928ULL: goto x86_l_928;
			case 0x92fULL: goto x86_l_92f;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_913:
	/* 0x913: mov    ebp,0x6 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, 0, 6ULL);
x86_l_918:
	/* 0x918: jmp    934 <filter_char_buf_equal+0xf7> */
	X86_SIM_X86_SUB_JMP(0x918, 0x934, x86_l_934);
x86_l_91a:
	/* 0x91a: mov    ebp,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_91f:
	/* 0x91f: jmp    934 <filter_char_buf_equal+0xf7> */
	X86_SIM_X86_SUB_JMP(0x91f, 0x934, x86_l_934);
x86_l_921:
	/* 0x921: mov    ebp,0x7 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, 0, 7ULL);
x86_l_926:
	/* 0x926: jmp    934 <filter_char_buf_equal+0xf7> */
	X86_SIM_X86_SUB_JMP(0x926, 0x934, x86_l_934);
x86_l_928:
	/* 0x928: mov    ebp,0x9 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, 0, 9ULL);
x86_l_92d:
	/* 0x92d: jmp    934 <filter_char_buf_equal+0xf7> */
	X86_SIM_X86_SUB_JMP(0x92d, 0x934, x86_l_934);
x86_l_92f:
	/* 0x92f: mov    ebp,0xa */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, 0, 10ULL);
x86_l_934:
	/* 0x934: mov    eax,ebp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RBP, X86_WIDTH_32, 0, 0);
x86_l_936:
	/* 0x936: and    eax,0xf */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_939:
	/* 0x939: mov    r12d,DWORD PTR [rdi+rax*4+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R12, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 16ULL);
x86_l_93e:
	/* 0x93e: cmp    r12d,0xffffffff */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 4294967295ULL);
x86_l_942:
	/* 0x942: je     b74 <filter_char_buf_equal+0x337> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x942, 0xb74, x86_l_b74);
x86_l_948:
	/* 0x948: mov    rbx,rsi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RBX, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_94b:
	/* 0x94b: mov    r13d,edx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R13, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_94e:
	/* 0x94e: mov    rdi,QWORD PTR [rip+0x19d0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)string_maps_heap));
x86_l_955:
	/* 0x955: mov    r14,rsp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R14, X86_RSP, X86_WIDTH_64, 0, 0);
x86_l_958:
	/* 0x958: mov    rsi,r14 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_95b:
	/* 0x95b: call   2330 <__native_link_local_memset_zero_dynamic+0xa0> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_960:
	/* 0x960: mov    rdi,QWORD PTR [rip+0x19d0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)heap_ro_zero));
x86_l_967:
	/* 0x967: mov    rsi,r14 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_96a:
	/* 0x96a: mov    r14,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R14, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_96d:
	/* 0x96d: call   2342 <__native_link_local_memset_zero_dynamic+0xb2> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_972:
	/* 0x972: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_974:
	/* 0x974: test   r14,r14 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_977:
	/* 0x977: je     b76 <filter_char_buf_equal+0x339> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x977, 0xb76, x86_l_b76);
x86_l_97d:
	/* 0x97d: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_980:
	/* 0x980: je     b76 <filter_char_buf_equal+0x339> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x980, 0xb76, x86_l_b76);
x86_l_986:
	/* 0x986: mov    esi,r13d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_R13, X86_WIDTH_32, 0, 0);
x86_l_989:
	/* 0x989: cmp    ebp,0x5 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, 0, 5ULL);
x86_l_98c:
	/* 0x98c: jg     9eb <filter_char_buf_equal+0x1ae> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x98c, 0x9eb, x86_l_9eb);
x86_l_98e:
	/* 0x98e: mov    BYTE PTR [r14],sil */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_R14, X86_RSI, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_991:
	/* 0x991: lea    rdi,[r14+0x1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_995:
	/* 0x995: test   rbx,rbx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_998:
	/* 0x998: jns    a41 <filter_char_buf_equal+0x204> */
	X86_SIM_X86_SUB_JCC(X86_CC_NS, 0x998, 0xa41, x86_l_a41);
x86_l_99e:
	/* 0x99e: test   rbx,rbx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_9a1:
	/* 0x9a1: jns    a4e <filter_char_buf_equal+0x211> */
	X86_SIM_X86_SUB_JCC(X86_CC_NS, 0x9a1, 0xa4e, x86_l_a4e);
x86_l_9a7:
	/* 0x9a7: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_9a9:
	/* 0x9a9: cmp    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_9ac:
	/* 0x9ac: jb     9cc <filter_char_buf_equal+0x18f> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x9ac, 0x9cc, x86_l_9cc);
x86_l_9ae:
	/* 0x9ae: xor    r8d,r8d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_9b1:
	/* 0x9b1: mov    ecx,r8d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_R8, X86_WIDTH_32, 0, 0);
x86_l_9b4:
	/* 0x9b4: mov    r9,QWORD PTR [rbx+rcx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R9, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_9b8:
	/* 0x9b8: mov    QWORD PTR [rdi+rcx*1],r9 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_9bc:
	/* 0x9bc: lea    ecx,[r8+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RCX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9c0:
	/* 0x9c0: add    r8d,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 16ULL);
x86_l_9c4:
	/* 0x9c4: cmp    r8d,esi */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_R8, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_9c7:
	/* 0x9c7: mov    r8d,ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R8, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_9ca:
	/* 0x9ca: jbe    9b1 <filter_char_buf_equal+0x174> */
	X86_SIM_X86_SUB_JCC(X86_CC_BE, 0x9ca, 0x9b1, x86_l_9b1);
x86_l_9cc:
	/* 0x9cc: test   sil,0x4 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, 0, 4ULL);
x86_l_9d0:
	/* 0x9d0: jne    b88 <filter_char_buf_equal+0x34b> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x9d0, 0xb88, x86_l_b88);
x86_l_9d6:
	/* 0x9d6: test   sil,0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, 0, 2ULL);
x86_l_9da:
	/* 0x9da: jne    ba0 <filter_char_buf_equal+0x363> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x9da, 0xba0, x86_l_ba0);
x86_l_9e0:
	/* 0x9e0: test   sil,0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_9e4:
	/* 0x9e4: je     a60 <filter_char_buf_equal+0x223> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x9e4, 0xa60, x86_l_a60);
x86_l_9e6:
	/* 0x9e6: jmp    bba <filter_char_buf_equal+0x37d> */
	X86_SIM_X86_SUB_JMP(0x9e6, 0xbba, x86_l_bba);
x86_l_9eb:
	/* 0x9eb: mov    WORD PTR [r14],si */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_R14, X86_RSI, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9ef:
	/* 0x9ef: lea    rdi,[r14+0x2] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_9f3:
	/* 0x9f3: test   rbx,rbx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_9f6:
	/* 0x9f6: jns    a41 <filter_char_buf_equal+0x204> */
	X86_SIM_X86_SUB_JCC(X86_CC_NS, 0x9f6, 0xa41, x86_l_a41);
x86_l_9f8:
	/* 0x9f8: test   rbx,rbx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_9fb:
	/* 0x9fb: jns    a4e <filter_char_buf_equal+0x211> */
	X86_SIM_X86_SUB_JCC(X86_CC_NS, 0x9fb, 0xa4e, x86_l_a4e);
x86_l_9fd:
	/* 0x9fd: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_9ff:
	/* 0x9ff: cmp    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_a02:
	/* 0xa02: jb     a22 <filter_char_buf_equal+0x1e5> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0xa02, 0xa22, x86_l_a22);
x86_l_a04:
	/* 0xa04: xor    r8d,r8d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_a07:
	/* 0xa07: mov    ecx,r8d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_R8, X86_WIDTH_32, 0, 0);
x86_l_a0a:
	/* 0xa0a: mov    r9,QWORD PTR [rbx+rcx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R9, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_a0e:
	/* 0xa0e: mov    QWORD PTR [rdi+rcx*1],r9 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_a12:
	/* 0xa12: lea    ecx,[r8+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RCX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a16:
	/* 0xa16: add    r8d,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 16ULL);
x86_l_a1a:
	/* 0xa1a: cmp    r8d,esi */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_R8, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_a1d:
	/* 0xa1d: mov    r8d,ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R8, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_a20:
	/* 0xa20: jbe    a07 <filter_char_buf_equal+0x1ca> */
	X86_SIM_X86_SUB_JCC(X86_CC_BE, 0xa20, 0xa07, x86_l_a07);
x86_l_a22:
	/* 0xa22: test   sil,0x4 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, 0, 4ULL);
x86_l_a26:
	/* 0xa26: jne    bc8 <filter_char_buf_equal+0x38b> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0xa26, 0xbc8, x86_l_bc8);
x86_l_a2c:
	/* 0xa2c: test   sil,0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, 0, 2ULL);
x86_l_a30:
	/* 0xa30: jne    be0 <filter_char_buf_equal+0x3a3> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0xa30, 0xbe0, x86_l_be0);
x86_l_a36:
	/* 0xa36: test   sil,0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_a3a:
	/* 0xa3a: je     a60 <filter_char_buf_equal+0x223> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xa3a, 0xa60, x86_l_a60);
x86_l_a3c:
	/* 0xa3c: jmp    bfa <filter_char_buf_equal+0x3bd> */
	X86_SIM_X86_SUB_JMP(0xa3c, 0xbfa, x86_l_bfa);
x86_l_a41:
	/* 0xa41: mov    rdx,rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_a44:
	/* 0xa44: mov    rbx,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RBX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_a47:
	/* 0xa47: call   2432 <__native_link_local_memset_zero_dynamic+0x1a2> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_a4c:
	/* 0xa4c: jmp    a5a <filter_char_buf_equal+0x21d> */
	X86_SIM_X86_SUB_JMP(0xa4c, 0xa5a, x86_l_a5a);
x86_l_a4e:
	/* 0xa4e: mov    edx,esi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_a50:
	/* 0xa50: xor    esi,esi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_a52:
	/* 0xa52: mov    rbx,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RBX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_a55:
	/* 0xa55: call   2290 <__native_link_local_memset_zero_dynamic> */
	X86_SIM_X86_CALL(x86_l_2290, 0xa5aULL);
x86_l_a5a:
	/* 0xa5a: mov    esi,r13d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_R13, X86_WIDTH_32, 0, 0);
x86_l_a5d:
	/* 0xa5d: mov    rax,rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_a60:
	/* 0xa60: sub    r15d,esi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R15, X86_RSI, X86_WIDTH_32, X86_ALU_SUB, 0);
x86_l_a63:
	/* 0xa63: jle    b39 <filter_char_buf_equal+0x2fc> */
	X86_SIM_X86_SUB_JCC(X86_CC_LE, 0xa63, 0xb39, x86_l_b39);
x86_l_a69:
	/* 0xa69: mov    ecx,esi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_a6b:
	/* 0xa6b: mov    rdi,r14 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_a6e:
	/* 0xa6e: add    rdi,rcx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_a71:
	/* 0xa71: mov    esi,r15d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_R15, X86_WIDTH_32, 0, 0);
x86_l_a74:
	/* 0xa74: and    esi,0xfff */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_a7a:
	/* 0xa7a: cmp    ebp,0x5 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, 0, 5ULL);
x86_l_a7d:
	/* 0xa7d: jg     ad6 <filter_char_buf_equal+0x299> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0xa7d, 0xad6, x86_l_ad6);
x86_l_a7f:
	/* 0xa7f: inc    rdi */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_a82:
	/* 0xa82: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_a85:
	/* 0xa85: jns    b26 <filter_char_buf_equal+0x2e9> */
	X86_SIM_X86_SUB_JCC(X86_CC_NS, 0xa85, 0xb26, x86_l_b26);
x86_l_a8b:
	/* 0xa8b: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_a8e:
	/* 0xa8e: jns    b30 <filter_char_buf_equal+0x2f3> */
	X86_SIM_X86_SUB_JCC(X86_CC_NS, 0xa8e, 0xb30, x86_l_b30);
x86_l_a94:
	/* 0xa94: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_a96:
	/* 0xa96: cmp    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_a99:
	/* 0xa99: jb     ab7 <filter_char_buf_equal+0x27a> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0xa99, 0xab7, x86_l_ab7);
x86_l_a9b:
	/* 0xa9b: mov    edx,esi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_a9d:
	/* 0xa9d: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_a9f:
	/* 0xa9f: mov    rsi,rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_aa2:
	/* 0xaa2: mov    rcx,QWORD PTR [rax+rcx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_aa6:
	/* 0xaa6: mov    QWORD PTR [rdi+rsi*1],rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_aaa:
	/* 0xaaa: lea    rcx,[rsi+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_aae:
	/* 0xaae: add    rsi,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_ab2:
	/* 0xab2: cmp    rsi,rdx */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_ab5:
	/* 0xab5: jbe    a9f <filter_char_buf_equal+0x262> */
	X86_SIM_X86_SUB_JCC(X86_CC_BE, 0xab5, 0xa9f, x86_l_a9f);
x86_l_ab7:
	/* 0xab7: test   r15b,0x4 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, 0, 4ULL);
x86_l_abb:
	/* 0xabb: jne    c08 <filter_char_buf_equal+0x3cb> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0xabb, 0xc08, x86_l_c08);
x86_l_ac1:
	/* 0xac1: test   r15b,0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, 0, 2ULL);
x86_l_ac5:
	/* 0xac5: jne    c1d <filter_char_buf_equal+0x3e0> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0xac5, 0xc1d, x86_l_c1d);
x86_l_acb:
	/* 0xacb: test   r15b,0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_acf:
	/* 0xacf: je     b39 <filter_char_buf_equal+0x2fc> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xacf, 0xb39, x86_l_b39);
x86_l_ad1:
	/* 0xad1: jmp    c34 <filter_char_buf_equal+0x3f7> */
	X86_SIM_X86_SUB_JMP(0xad1, 0xc34, x86_l_c34);
x86_l_ad6:
	/* 0xad6: add    rdi,0x2 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_ada:
	/* 0xada: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_add:
	/* 0xadd: jns    b26 <filter_char_buf_equal+0x2e9> */
	X86_SIM_X86_SUB_JCC(X86_CC_NS, 0xadd, 0xb26, x86_l_b26);
x86_l_adf:
	/* 0xadf: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_ae2:
	/* 0xae2: jns    b30 <filter_char_buf_equal+0x2f3> */
	X86_SIM_X86_SUB_JCC(X86_CC_NS, 0xae2, 0xb30, x86_l_b30);
x86_l_ae4:
	/* 0xae4: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_ae6:
	/* 0xae6: cmp    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_ae9:
	/* 0xae9: jb     b07 <filter_char_buf_equal+0x2ca> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0xae9, 0xb07, x86_l_b07);
x86_l_aeb:
	/* 0xaeb: mov    edx,esi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_aed:
	/* 0xaed: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_aef:
	/* 0xaef: mov    rsi,rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_af2:
	/* 0xaf2: mov    rcx,QWORD PTR [rax+rcx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_af6:
	/* 0xaf6: mov    QWORD PTR [rdi+rsi*1],rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_afa:
	/* 0xafa: lea    rcx,[rsi+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_afe:
	/* 0xafe: add    rsi,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_b02:
	/* 0xb02: cmp    rsi,rdx */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_b05:
	/* 0xb05: jbe    aef <filter_char_buf_equal+0x2b2> */
	X86_SIM_X86_SUB_JCC(X86_CC_BE, 0xb05, 0xaef, x86_l_aef);
x86_l_b07:
	/* 0xb07: test   r15b,0x4 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, 0, 4ULL);
x86_l_b0b:
	/* 0xb0b: jne    c42 <filter_char_buf_equal+0x405> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0xb0b, 0xc42, x86_l_c42);
x86_l_b11:
	/* 0xb11: test   r15b,0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, 0, 2ULL);
x86_l_b15:
	/* 0xb15: jne    c57 <filter_char_buf_equal+0x41a> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0xb15, 0xc57, x86_l_c57);
x86_l_b1b:
	/* 0xb1b: test   r15b,0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_b1f:
	/* 0xb1f: je     b39 <filter_char_buf_equal+0x2fc> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xb1f, 0xb39, x86_l_b39);
x86_l_b21:
	/* 0xb21: jmp    c6e <filter_char_buf_equal+0x431> */
	X86_SIM_X86_SUB_JMP(0xb21, 0xc6e, x86_l_c6e);
x86_l_b26:
	/* 0xb26: mov    rdx,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_b29:
	/* 0xb29: call   2514 <__native_link_local_memset_zero_dynamic+0x284> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_b2e:
	/* 0xb2e: jmp    b39 <filter_char_buf_equal+0x2fc> */
	X86_SIM_X86_SUB_JMP(0xb2e, 0xb39, x86_l_b39);
x86_l_b30:
	/* 0xb30: mov    edx,esi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_b32:
	/* 0xb32: xor    esi,esi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_b34:
	/* 0xb34: call   2290 <__native_link_local_memset_zero_dynamic> */
	X86_SIM_X86_CALL(x86_l_2290, 0xb39ULL);
x86_l_b39:
	/* 0xb39: mov    DWORD PTR [rsp+0x4],r12d */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_b3e:
	/* 0xb3e: cmp    ebp,0xb */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, 0, 11ULL);
x86_l_b41:
	/* 0xb41: jae    b74 <filter_char_buf_equal+0x337> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0xb41, 0xb74, x86_l_b74);
x86_l_b43:
	/* 0xb43: mov    eax,ebp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RBP, X86_WIDTH_32, 0, 0);
x86_l_b45:
	/* Image-bound immutable capability table; private base is dead. */
	switch (X86_SIM_L_READ_REG(X86_RAX) << 3) {
	case 0ULL: X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)string_maps_0)); break;
	case 8ULL: X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)string_maps_1)); break;
	case 16ULL: X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)string_maps_2)); break;
	case 24ULL: X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)string_maps_3)); break;
	case 32ULL: X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)string_maps_4)); break;
	case 40ULL: X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)string_maps_5)); break;
	case 48ULL: X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)string_maps_6)); break;
	case 56ULL: X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)string_maps_7)); break;
	case 64ULL: X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)string_maps_8)); break;
	case 72ULL: X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)string_maps_9)); break;
	case 80ULL: X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)string_maps_10)); break;
	default: X86_SIM_L_ARCHITECTURAL_FAULT();
	}
x86_l_b50:
	/* 0xb50: lea    rsi,[rsp+0x4] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_b55:
	/* 0xb55: call   2540 <__native_link_local_memset_zero_dynamic+0x2b0> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_b5a:
	/* 0xb5a: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_b5d:
	/* 0xb5d: je     b74 <filter_char_buf_equal+0x337> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xb5d, 0xb74, x86_l_b74);
x86_l_b5f:
	/* 0xb5f: mov    rdi,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_b62:
	/* 0xb62: mov    rsi,r14 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_b65:
	/* 0xb65: call   2550 <__native_link_local_memset_zero_dynamic+0x2c0> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_b6a:
	/* 0xb6a: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_b6c:
	/* 0xb6c: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_b6f:
	/* 0xb6f: setne  cl */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_CC_NE, 0);
x86_l_b72:
	/* 0xb72: jmp    b76 <filter_char_buf_equal+0x339> */
	X86_SIM_X86_SUB_JMP(0xb72, 0xb76, x86_l_b76);
x86_l_b74:
	/* 0xb74: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_b76:
	/* 0xb76: mov    rax,rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_b79:
	/* 0xb79: add    rsp,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_b7d:
	/* 0xb7d: pop    rbx */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_b7e:
	/* 0xb7e: pop    r12 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R12, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_b80:
	/* 0xb80: pop    r13 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R13, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_b82:
	/* 0xb82: pop    r14 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R14, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_b84:
	/* 0xb84: pop    r15 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R15, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_b86:
	/* 0xb86: pop    rbp */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBP, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_b87:
	/* 0xb87: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_b87);
x86_l_b88:
	/* 0xb88: mov    r8d,ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R8, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_b8b:
	/* 0xb8b: mov    r9d,DWORD PTR [rbx+r8*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R9, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_R8, 0), 0ULL);
x86_l_b8f:
	/* 0xb8f: mov    DWORD PTR [rdi+r8*1],r9d */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_R8, 0), 0ULL);
x86_l_b93:
	/* 0xb93: or     ecx,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_OR, 4ULL);
x86_l_b96:
	/* 0xb96: test   sil,0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, 0, 2ULL);
x86_l_b9a:
	/* 0xb9a: je     9e0 <filter_char_buf_equal+0x1a3> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xb9a, 0x9e0, x86_l_9e0);
x86_l_ba0:
	/* 0xba0: mov    r8d,ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R8, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_ba3:
	/* 0xba3: movzx  r9d,WORD PTR [rbx+r8*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R9, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R8, 0, X86_WIDTH_16), 0ULL);
x86_l_ba8:
	/* 0xba8: mov    WORD PTR [rdi+r8*1],r9w */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_R9, X86_WIDTH_16, X86_MEM_AUX(X86_R8, 0), 0ULL);
x86_l_bad:
	/* 0xbad: add    ecx,0x2 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_bb0:
	/* 0xbb0: test   sil,0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_bb4:
	/* 0xbb4: je     a60 <filter_char_buf_equal+0x223> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xbb4, 0xa60, x86_l_a60);
x86_l_bba:
	/* 0xbba: mov    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_bbc:
	/* 0xbbc: movzx  edx,BYTE PTR [rbx+rcx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_bc0:
	/* 0xbc0: mov    BYTE PTR [rdi+rcx*1],dl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RDX, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_bc3:
	/* 0xbc3: jmp    a60 <filter_char_buf_equal+0x223> */
	X86_SIM_X86_SUB_JMP(0xbc3, 0xa60, x86_l_a60);
x86_l_bc8:
	/* 0xbc8: mov    r8d,ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R8, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_bcb:
	/* 0xbcb: mov    r9d,DWORD PTR [rbx+r8*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R9, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_R8, 0), 0ULL);
x86_l_bcf:
	/* 0xbcf: mov    DWORD PTR [rdi+r8*1],r9d */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_R8, 0), 0ULL);
x86_l_bd3:
	/* 0xbd3: or     ecx,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_OR, 4ULL);
x86_l_bd6:
	/* 0xbd6: test   sil,0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, 0, 2ULL);
x86_l_bda:
	/* 0xbda: je     a36 <filter_char_buf_equal+0x1f9> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xbda, 0xa36, x86_l_a36);
x86_l_be0:
	/* 0xbe0: mov    r8d,ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R8, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_be3:
	/* 0xbe3: movzx  r9d,WORD PTR [rbx+r8*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R9, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R8, 0, X86_WIDTH_16), 0ULL);
x86_l_be8:
	/* 0xbe8: mov    WORD PTR [rdi+r8*1],r9w */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_R9, X86_WIDTH_16, X86_MEM_AUX(X86_R8, 0), 0ULL);
x86_l_bed:
	/* 0xbed: add    ecx,0x2 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_bf0:
	/* 0xbf0: test   sil,0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_bf4:
	/* 0xbf4: je     a60 <filter_char_buf_equal+0x223> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xbf4, 0xa60, x86_l_a60);
x86_l_bfa:
	/* 0xbfa: mov    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_bfc:
	/* 0xbfc: movzx  edx,BYTE PTR [rbx+rcx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_c00:
	/* 0xc00: mov    BYTE PTR [rdi+rcx*1],dl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RDX, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_c03:
	/* 0xc03: jmp    a60 <filter_char_buf_equal+0x223> */
	X86_SIM_X86_SUB_JMP(0xc03, 0xa60, x86_l_a60);
x86_l_c08:
	/* 0xc08: mov    edx,ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_c0a:
	/* 0xc0a: mov    esi,DWORD PTR [rax+rdx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_c0d:
	/* 0xc0d: mov    DWORD PTR [rdi+rdx*1],esi */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_c10:
	/* 0xc10: or     ecx,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_OR, 4ULL);
x86_l_c13:
	/* 0xc13: test   r15b,0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, 0, 2ULL);
x86_l_c17:
	/* 0xc17: je     acb <filter_char_buf_equal+0x28e> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xc17, 0xacb, x86_l_acb);
x86_l_c1d:
	/* 0xc1d: mov    edx,ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_c1f:
	/* 0xc1f: movzx  esi,WORD PTR [rax+rdx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RDX, 0, X86_WIDTH_16), 0ULL);
x86_l_c23:
	/* 0xc23: mov    WORD PTR [rdi+rdx*1],si */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RSI, X86_WIDTH_16, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_c27:
	/* 0xc27: add    ecx,0x2 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_c2a:
	/* 0xc2a: test   r15b,0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_c2e:
	/* 0xc2e: je     b39 <filter_char_buf_equal+0x2fc> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xc2e, 0xb39, x86_l_b39);
x86_l_c34:
	/* 0xc34: mov    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_c36:
	/* 0xc36: movzx  eax,BYTE PTR [rax+rcx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_c3a:
	/* 0xc3a: mov    BYTE PTR [rdi+rcx*1],al */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_c3d:
	/* 0xc3d: jmp    b39 <filter_char_buf_equal+0x2fc> */
	X86_SIM_X86_SUB_JMP(0xc3d, 0xb39, x86_l_b39);
x86_l_c42:
	/* 0xc42: mov    edx,ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_c44:
	/* 0xc44: mov    esi,DWORD PTR [rax+rdx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_c47:
	/* 0xc47: mov    DWORD PTR [rdi+rdx*1],esi */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_c4a:
	/* 0xc4a: or     ecx,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_OR, 4ULL);
x86_l_c4d:
	/* 0xc4d: test   r15b,0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, 0, 2ULL);
x86_l_c51:
	/* 0xc51: je     b1b <filter_char_buf_equal+0x2de> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xc51, 0xb1b, x86_l_b1b);
x86_l_c57:
	/* 0xc57: mov    edx,ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_c59:
	/* 0xc59: movzx  esi,WORD PTR [rax+rdx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RDX, 0, X86_WIDTH_16), 0ULL);
x86_l_c5d:
	/* 0xc5d: mov    WORD PTR [rdi+rdx*1],si */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RSI, X86_WIDTH_16, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_c61:
	/* 0xc61: add    ecx,0x2 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_c64:
	/* 0xc64: test   r15b,0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_c68:
	/* 0xc68: je     b39 <filter_char_buf_equal+0x2fc> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xc68, 0xb39, x86_l_b39);
x86_l_c6e:
	/* 0xc6e: mov    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_c70:
	/* 0xc70: movzx  eax,BYTE PTR [rax+rcx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_c74:
	/* 0xc74: mov    BYTE PTR [rdi+rcx*1],al */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_c77:
	/* 0xc77: jmp    b39 <filter_char_buf_equal+0x2fc> */
	X86_SIM_X86_SUB_JMP(0xc77, 0xb39, x86_l_b39);

	/* native subroutine native_link_sub_c7c */
x86_l_c7c:
	/* 0xc7c: push   rbp */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_c7d:
	/* 0xc7d: push   r15 */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_c7f:
	/* 0xc7f: push   r14 */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_c81:
	/* 0xc81: push   rbx */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_c82:
	/* 0xc82: push   rax */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_c83:
	/* 0xc83: mov    ebp,edx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RBP, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_c85:
	/* 0xc85: mov    r14,rsi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R14, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_c88:
	/* 0xc88: mov    DWORD PTR [rsp+0x4],edi */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_c8c:
	/* 0xc8c: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c93:
	/* 0xc93: mov    rdi,QWORD PTR [rip+0x1e30] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)string_prefix_maps));
x86_l_c9a:
	/* 0xc9a: lea    rsi,[rsp+0x4] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_c9f:
	/* 0xc9f: call   2ad4 <__native_link_local_memset_zero_dynamic+0x844> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_ca4:
	/* 0xca4: mov    rbx,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RBX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_ca7:
	/* 0xca7: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_ca9:
	/* 0xca9: test   ebp,ebp */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32, 0, 0);
x86_l_cab:
	/* 0xcab: je     d90 <filter_char_buf_prefix+0x114> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xcab, 0xd90, x86_l_d90);
x86_l_cb1:
	/* 0xcb1: test   rbx,rbx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_cb4:
	/* 0xcb4: je     d90 <filter_char_buf_prefix+0x114> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xcb4, 0xd90, x86_l_d90);
x86_l_cba:
	/* 0xcba: mov    rdi,QWORD PTR [rip+0x1e30] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)string_prefix_maps_heap));
x86_l_cc1:
	/* 0xcc1: mov    rsi,rsp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_RSP, X86_WIDTH_64, 0, 0);
x86_l_cc4:
	/* 0xcc4: call   2af9 <__native_link_local_memset_zero_dynamic+0x869> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_cc9:
	/* 0xcc9: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_ccc:
	/* 0xccc: je     d31 <filter_char_buf_prefix+0xb5> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xccc, 0xd31, x86_l_d31);
x86_l_cce:
	/* 0xcce: mov    r15,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R15, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_cd1:
	/* 0xcd1: cmp    ebp,0xff */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, 0, 255ULL);
x86_l_cd7:
	/* 0xcd7: mov    esi,0xff */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 255ULL);
x86_l_cdc:
	/* 0xcdc: cmovb  esi,ebp */
	X86_SIM_RUN_OP(X86_OP_CMOV, X86_RSI, X86_RBP, X86_WIDTH_32, X86_CC_B, 0);
x86_l_cdf:
	/* 0xcdf: lea    eax,[rsi*8+0x0] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 3), 0ULL);
x86_l_ce6:
	/* 0xce6: mov    DWORD PTR [r15],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ce9:
	/* 0xce9: mov    rdi,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_cec:
	/* 0xcec: add    rdi,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_cf0:
	/* 0xcf0: test   r14,r14 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_cf3:
	/* 0xcf3: jns    d35 <filter_char_buf_prefix+0xb9> */
	X86_SIM_X86_SUB_JCC(X86_CC_NS, 0xcf3, 0xd35, x86_l_d35);
x86_l_cf5:
	/* 0xcf5: test   r14,r14 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_cf8:
	/* 0xcf8: jns    d3f <filter_char_buf_prefix+0xc3> */
	X86_SIM_X86_SUB_JCC(X86_CC_NS, 0xcf8, 0xd3f, x86_l_d3f);
x86_l_cfa:
	/* 0xcfa: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_cfc:
	/* 0xcfc: cmp    ebp,0x8 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_cff:
	/* 0xcff: jb     d1d <filter_char_buf_prefix+0xa1> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0xcff, 0xd1d, x86_l_d1d);
x86_l_d01:
	/* 0xd01: mov    ecx,esi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_d03:
	/* 0xd03: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_d05:
	/* 0xd05: mov    rdx,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_d08:
	/* 0xd08: mov    rax,QWORD PTR [r14+rax*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_d0c:
	/* 0xd0c: mov    QWORD PTR [rdi+rdx*1],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_d10:
	/* 0xd10: lea    rax,[rdx+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d14:
	/* 0xd14: add    rdx,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_d18:
	/* 0xd18: cmp    rdx,rcx */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_d1b:
	/* 0xd1b: jbe    d05 <filter_char_buf_prefix+0x89> */
	X86_SIM_X86_SUB_JCC(X86_CC_BE, 0xd1b, 0xd05, x86_l_d05);
x86_l_d1d:
	/* 0xd1d: test   sil,0x4 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, 0, 4ULL);
x86_l_d21:
	/* 0xd21: jne    d4a <filter_char_buf_prefix+0xce> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0xd21, 0xd4a, x86_l_d4a);
x86_l_d23:
	/* 0xd23: test   sil,0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, 0, 2ULL);
x86_l_d27:
	/* 0xd27: jne    d5c <filter_char_buf_prefix+0xe0> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0xd27, 0xd5c, x86_l_d5c);
x86_l_d29:
	/* 0xd29: test   sil,0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_d2d:
	/* 0xd2d: jne    d70 <filter_char_buf_prefix+0xf4> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0xd2d, 0xd70, x86_l_d70);
x86_l_d2f:
	/* 0xd2f: jmp    d7a <filter_char_buf_prefix+0xfe> */
	X86_SIM_X86_SUB_JMP(0xd2f, 0xd7a, x86_l_d7a);
x86_l_d31:
	/* 0xd31: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_d33:
	/* 0xd33: jmp    d90 <filter_char_buf_prefix+0x114> */
	X86_SIM_X86_SUB_JMP(0xd33, 0xd90, x86_l_d90);
x86_l_d35:
	/* 0xd35: mov    rdx,r14 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_d38:
	/* 0xd38: call   2b74 <__native_link_local_memset_zero_dynamic+0x8e4> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_d3d:
	/* 0xd3d: jmp    d7a <filter_char_buf_prefix+0xfe> */
	X86_SIM_X86_SUB_JMP(0xd3d, 0xd7a, x86_l_d7a);
x86_l_d3f:
	/* 0xd3f: mov    edx,esi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_d41:
	/* 0xd41: xor    esi,esi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_d43:
	/* 0xd43: call   2290 <__native_link_local_memset_zero_dynamic> */
	X86_SIM_X86_CALL(x86_l_2290, 0xd48ULL);
x86_l_d48:
	/* 0xd48: jmp    d7a <filter_char_buf_prefix+0xfe> */
	X86_SIM_X86_SUB_JMP(0xd48, 0xd7a, x86_l_d7a);
x86_l_d4a:
	/* 0xd4a: mov    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_d4c:
	/* 0xd4c: mov    edx,DWORD PTR [r14+rcx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_d50:
	/* 0xd50: mov    DWORD PTR [rdi+rcx*1],edx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_d53:
	/* 0xd53: or     eax,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_OR, 4ULL);
x86_l_d56:
	/* 0xd56: test   sil,0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, 0, 2ULL);
x86_l_d5a:
	/* 0xd5a: je     d29 <filter_char_buf_prefix+0xad> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xd5a, 0xd29, x86_l_d29);
x86_l_d5c:
	/* 0xd5c: mov    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_d5e:
	/* 0xd5e: movzx  edx,WORD PTR [r14+rcx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_16), 0ULL);
x86_l_d63:
	/* 0xd63: mov    WORD PTR [rdi+rcx*1],dx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_d67:
	/* 0xd67: add    eax,0x2 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_d6a:
	/* 0xd6a: test   sil,0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_d6e:
	/* 0xd6e: je     d7a <filter_char_buf_prefix+0xfe> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xd6e, 0xd7a, x86_l_d7a);
x86_l_d70:
	/* 0xd70: mov    eax,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_d72:
	/* 0xd72: movzx  ecx,BYTE PTR [r14+rax*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_d77:
	/* 0xd77: mov    BYTE PTR [rdi+rax*1],cl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_d7a:
	/* 0xd7a: mov    rdi,rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_d7d:
	/* 0xd7d: mov    rsi,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_d80:
	/* 0xd80: call   2bbc <__native_link_local_memset_zero_dynamic+0x92c> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_d85:
	/* 0xd85: mov    rcx,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_d88:
	/* 0xd88: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_d8a:
	/* 0xd8a: test   rcx,rcx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_d8d:
	/* 0xd8d: setne  al */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_CC_NE, 0);
x86_l_d90:
	/* 0xd90: add    rsp,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_d94:
	/* 0xd94: pop    rbx */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_d95:
	/* 0xd95: pop    r14 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R14, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_d97:
	/* 0xd97: pop    r15 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R15, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_d99:
	/* 0xd99: pop    rbp */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBP, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_d9a:
	/* 0xd9a: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_d9a);

	/* native subroutine native_link_sub_d9b */
x86_l_d9b:
	/* 0xd9b: push   r14 */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_d9d:
	/* 0xd9d: push   rbx */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_d9e:
	/* 0xd9e: sub    rsp,0x18 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SUB, 24ULL);
x86_l_da2:
	/* 0xda2: mov    r14,rsi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R14, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_da5:
	/* 0xda5: mov    rbx,rdi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RBX, X86_RDI, X86_WIDTH_64, 0, 0);
x86_l_da8:
	/* 0xda8: movzx  eax,BYTE PTR [rdi+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_dac:
	/* 0xdac: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_db0:
	/* 0xdb0: mov    rdi,QWORD PTR [rip+0xab0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)argfilter_maps));
x86_l_db7:
	/* 0xdb7: lea    rsi,[rsp+0xc] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_dbc:
	/* 0xdbc: call   1871 <filter_8ty_range+0x1ac> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_dc1:
	/* 0xdc1: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_dc4:
	/* 0xdc4: je     df7 <filter_32ty_map+0x5c> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xdc4, 0xdf7, x86_l_df7);
x86_l_dc6:
	/* 0xdc6: mov    ecx,DWORD PTR [r14] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_dc9:
	/* 0xdc9: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_dce:
	/* 0xdce: lea    rsi,[rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_dd3:
	/* 0xdd3: mov    rdi,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_dd6:
	/* 0xdd6: call   188b <filter_char_substring+0xe> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_ddb:
	/* 0xddb: mov    edx,DWORD PTR [rbx+0x4] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_dde:
	/* 0xdde: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_de0:
	/* 0xde0: cmp    edx,0x1d */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 29ULL);
x86_l_de3:
	/* 0xde3: ja     e11 <filter_32ty_map+0x76> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0xde3, 0xe11, x86_l_e11);
x86_l_de5:
	/* 0xde5: mov    esi,0x30038400 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 805536768ULL);
x86_l_dea:
	/* 0xdea: bt     esi,edx */
	X86_SIM_RUN_OP(X86_OP_BT, X86_RSI, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_ded:
	/* 0xded: jae    e01 <filter_32ty_map+0x66> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0xded, 0xe01, x86_l_e01);
x86_l_def:
	/* 0xdef: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_df2:
	/* 0xdf2: setne  cl */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_CC_NE, 0);
x86_l_df5:
	/* 0xdf5: jmp    e11 <filter_32ty_map+0x76> */
	X86_SIM_X86_SUB_JMP(0xdf5, 0xe11, x86_l_e11);
x86_l_df7:
	/* 0xdf7: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_df9:
	/* 0xdf9: add    rsp,0x18 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_dfd:
	/* 0xdfd: pop    rbx */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_dfe:
	/* 0xdfe: pop    r14 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R14, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_e00:
	/* 0xe00: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_e00);
x86_l_e01:
	/* 0xe01: mov    esi,0xc0800 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 788480ULL);
x86_l_e06:
	/* 0xe06: bt     esi,edx */
	X86_SIM_RUN_OP(X86_OP_BT, X86_RSI, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_e09:
	/* 0xe09: jae    e11 <filter_32ty_map+0x76> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0xe09, 0xe11, x86_l_e11);
x86_l_e0b:
	/* 0xe0b: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_e0e:
	/* 0xe0e: sete   cl */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_CC_E, 0);
x86_l_e11:
	/* 0xe11: movzx  eax,cl */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8, 0);
x86_l_e14:
	/* 0xe14: add    rsp,0x18 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_e18:
	/* 0xe18: pop    rbx */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_e19:
	/* 0xe19: pop    r14 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R14, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_e1b:
	/* 0xe1b: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_e00);

	/* native subroutine native_link_sub_e1c */
x86_l_e1c:
	/* 0xe1c: push   rbx */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_e1d:
	/* 0xe1d: sub    rsp,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SUB, 16ULL);
x86_l_e21:
	/* 0xe21: mov    WORD PTR [rsp+0xe],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 60129542144ULL);
x86_l_e28:
	/* 0xe28: mov    eax,DWORD PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e2a:
	/* 0xe2a: cmp    rax,0x1000 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, 0, 4096ULL);
x86_l_e30:
	/* 0xe30: ja     ecd <filter_file_type+0xb1> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0xe30, 0xecd, x86_l_ecd);
x86_l_e36:
	/* 0xe36: mov    rdx,rsi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_e39:
	/* 0xe39: add    rdx,rax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_e3c:
	/* 0xe3c: add    rdx,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_e40:
	/* 0xe40: jns    e53 <filter_file_type+0x37> */
	X86_SIM_X86_SUB_JCC(X86_CC_NS, 0xe40, 0xe53, x86_l_e53);
x86_l_e42:
	/* 0xe42: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_e45:
	/* 0xe45: jns    e79 <filter_file_type+0x5d> */
	X86_SIM_X86_SUB_JCC(X86_CC_NS, 0xe45, 0xe79, x86_l_e79);
x86_l_e47:
	/* 0xe47: movzx  ecx,WORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_e4a:
	/* 0xe4a: mov    edx,DWORD PTR [rdi+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e4d:
	/* 0xe4d: test   edx,edx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_e4f:
	/* 0xe4f: jne    e82 <filter_file_type+0x66> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0xe4f, 0xe82, x86_l_e82);
x86_l_e51:
	/* 0xe51: jmp    ecd <filter_file_type+0xb1> */
	X86_SIM_X86_SUB_JMP(0xe51, 0xecd, x86_l_ecd);
x86_l_e53:
	/* 0xe53: lea    rax,[rsp+0xe] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_e58:
	/* 0xe58: mov    rbx,rdi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RBX, X86_RDI, X86_WIDTH_64, 0, 0);
x86_l_e5b:
	/* 0xe5b: mov    rdi,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_e5e:
	/* 0xe5e: mov    esi,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_e63:
	/* 0xe63: call   2f18 <__native_link_local_memset_zero_dynamic+0xc88> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_e68:
	/* 0xe68: mov    rdi,rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_e6b:
	/* 0xe6b: movzx  ecx,WORD PTR [rsp+0xe] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 14ULL);
x86_l_e70:
	/* 0xe70: mov    edx,DWORD PTR [rdi+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e73:
	/* 0xe73: test   edx,edx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_e75:
	/* 0xe75: jne    e82 <filter_file_type+0x66> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0xe75, 0xe82, x86_l_e82);
x86_l_e77:
	/* 0xe77: jmp    ecd <filter_file_type+0xb1> */
	X86_SIM_X86_SUB_JMP(0xe77, 0xecd, x86_l_ecd);
x86_l_e79:
	/* 0xe79: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_e7b:
	/* 0xe7b: mov    edx,DWORD PTR [rdi+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e7e:
	/* 0xe7e: test   edx,edx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_e80:
	/* 0xe80: je     ecd <filter_file_type+0xb1> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xe80, 0xecd, x86_l_ecd);
x86_l_e82:
	/* 0xe82: and    ecx,0xf000 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 61440ULL);
x86_l_e88:
	/* 0xe88: mov    eax,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_e8d:
	/* 0xe8d: cmp    edx,ecx */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_e8f:
	/* 0xe8f: je     ecf <filter_file_type+0xb3> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xe8f, 0xecf, x86_l_ecf);
x86_l_e91:
	/* 0xe91: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e94:
	/* 0xe94: cmp    edx,0xc */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 12ULL);
x86_l_e97:
	/* 0xe97: jbe    ecd <filter_file_type+0xb1> */
	X86_SIM_X86_SUB_JCC(X86_CC_BE, 0xe97, 0xecd, x86_l_ecd);
x86_l_e99:
	/* 0xe99: mov    esi,DWORD PTR [rdi+0x14] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_e9c:
	/* 0xe9c: test   esi,esi */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_e9e:
	/* 0xe9e: je     ecd <filter_file_type+0xb1> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xe9e, 0xecd, x86_l_ecd);
x86_l_ea0:
	/* 0xea0: cmp    esi,ecx */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_ea2:
	/* 0xea2: je     ecf <filter_file_type+0xb3> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xea2, 0xecf, x86_l_ecf);
x86_l_ea4:
	/* 0xea4: cmp    edx,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_ea7:
	/* 0xea7: jb     ecd <filter_file_type+0xb1> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0xea7, 0xecd, x86_l_ecd);
x86_l_ea9:
	/* 0xea9: mov    esi,DWORD PTR [rdi+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_eac:
	/* 0xeac: test   esi,esi */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_eae:
	/* 0xeae: je     ecd <filter_file_type+0xb1> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xeae, 0xecd, x86_l_ecd);
x86_l_eb0:
	/* 0xeb0: cmp    esi,ecx */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_eb2:
	/* 0xeb2: je     ecf <filter_file_type+0xb3> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xeb2, 0xecf, x86_l_ecf);
x86_l_eb4:
	/* 0xeb4: cmp    edx,0x15 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 21ULL);
x86_l_eb7:
	/* 0xeb7: jb     ecd <filter_file_type+0xb1> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0xeb7, 0xecd, x86_l_ecd);
x86_l_eb9:
	/* 0xeb9: mov    edx,DWORD PTR [rdi+0x1c] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_ebc:
	/* 0xebc: test   edx,edx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_ebe:
	/* 0xebe: je     ecd <filter_file_type+0xb1> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xebe, 0xecd, x86_l_ecd);
x86_l_ec0:
	/* 0xec0: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_ec2:
	/* 0xec2: cmp    edx,ecx */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_ec4:
	/* 0xec4: sete   al */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_CC_E, 0);
x86_l_ec7:
	/* 0xec7: add    rsp,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_ecb:
	/* 0xecb: pop    rbx */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_ecc:
	/* 0xecc: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_ecc);
x86_l_ecd:
	/* 0xecd: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_ecf:
	/* 0xecf: add    rsp,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_ed3:
	/* 0xed3: pop    rbx */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_ed4:
	/* 0xed4: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_ecc);

	/* native subroutine native_link_sub_ed5 */
x86_l_ed5:
	/* 0xed5: push   r15 */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_ed7:
	/* 0xed7: push   r14 */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_ed9:
	/* 0xed9: push   rbx */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_eda:
	/* 0xeda: sub    rsp,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SUB, 16ULL);
x86_l_ede:
	/* 0xede: mov    ebx,edx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RBX, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_ee0:
	/* 0xee0: mov    r14,rsi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R14, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_ee3:
	/* 0xee3: mov    DWORD PTR [rsp+0xc],edi */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_ee7:
	/* 0xee7: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_eef:
	/* 0xeef: mov    rdi,QWORD PTR [rip+0x1f60] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)string_postfix_maps));
x86_l_ef6:
	/* 0xef6: lea    rsi,[rsp+0xc] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_efb:
	/* 0xefb: call   2e60 <__native_link_local_memset_zero_dynamic+0xbd0> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_f00:
	/* 0xf00: mov    r15,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R15, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_f03:
	/* 0xf03: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_f05:
	/* 0xf05: test   ebx,ebx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_32, 0, 0);
x86_l_f07:
	/* 0xf07: je     100d <filter_char_buf_postfix+0x138> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xf07, 0x100d, x86_l_100d);
x86_l_f0d:
	/* 0xf0d: test   r15,r15 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_f10:
	/* 0xf10: je     100d <filter_char_buf_postfix+0x138> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xf10, 0x100d, x86_l_100d);
x86_l_f16:
	/* 0xf16: mov    rdi,QWORD PTR [rip+0x1f60] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)string_postfix_maps_heap));
x86_l_f1d:
	/* 0xf1d: lea    rsi,[rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f22:
	/* 0xf22: call   2e87 <__native_link_local_memset_zero_dynamic+0xbf7> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_f27:
	/* 0xf27: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_f2a:
	/* 0xf2a: je     100b <filter_char_buf_postfix+0x136> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xf2a, 0x100b, x86_l_100b);
x86_l_f30:
	/* 0xf30: cmp    ebx,0x7f */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 127ULL);
x86_l_f33:
	/* 0xf33: mov    ecx,0x7f */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 127ULL);
x86_l_f38:
	/* 0xf38: cmovb  ecx,ebx */
	X86_SIM_RUN_OP(X86_OP_CMOV, X86_RCX, X86_RBX, X86_WIDTH_32, X86_CC_B, 0);
x86_l_f3b:
	/* 0xf3b: shl    ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_f3e:
	/* 0xf3e: mov    DWORD PTR [rax],ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f40:
	/* 0xf40: mov    ecx,ebx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RBX, X86_WIDTH_32, 0, 0);
x86_l_f42:
	/* 0xf42: lea    edx,[rbx-0x4] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551612ULL);
x86_l_f45:
	/* 0xf45: mov    rsi,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_f48:
	/* 0xf48: add    rsi,0x7 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 7ULL);
x86_l_f4c:
	/* 0xf4c: lea    edi,[rbx-0x3] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_f4f:
	/* 0xf4f: lea    r8d,[rbx-0x2] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R8, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_f53:
	/* 0xf53: dec    ebx */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_f55:
	/* 0xf55: mov    r9,0xfffffffffffffffd */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_64, 0, 18446744073709551613ULL);
x86_l_f5c:
	/* 0xf5c: lea    r10d,[rbx+r9*1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R10, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_f60:
	/* 0xf60: add    r10d,0x3 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_f64:
	/* 0xf64: and    r10d,0xfff */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_f6b:
	/* 0xf6b: movzx  r10d,BYTE PTR [r14+r10*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R10, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R10, 0, X86_WIDTH_8), 0ULL);
x86_l_f70:
	/* 0xf70: mov    BYTE PTR [rsi-0x3],r10b */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSI, X86_R10, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_f74:
	/* 0xf74: lea    r10,[rcx+r9*1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R10, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_f78:
	/* 0xf78: cmp    r10,0xfffffffffffffffe */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_64, 0, 18446744073709551614ULL);
x86_l_f7c:
	/* 0xf7c: je     ff3 <filter_char_buf_postfix+0x11e> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xf7c, 0xff3, x86_l_ff3);
x86_l_f7e:
	/* 0xf7e: lea    r11d,[r8+r9*1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R11, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_f82:
	/* 0xf82: add    r11d,0x3 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_f86:
	/* 0xf86: and    r11d,0xfff */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_f8d:
	/* 0xf8d: movzx  r11d,BYTE PTR [r14+r11*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R11, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R11, 0, X86_WIDTH_8), 0ULL);
x86_l_f92:
	/* 0xf92: mov    BYTE PTR [rsi-0x2],r11b */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSI, X86_R11, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_f96:
	/* 0xf96: cmp    r10,0xffffffffffffffff */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_64, 0, 18446744073709551615ULL);
x86_l_f9a:
	/* 0xf9a: je     ff3 <filter_char_buf_postfix+0x11e> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xf9a, 0xff3, x86_l_ff3);
x86_l_f9c:
	/* 0xf9c: lea    r10d,[rdi+r9*1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R10, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_fa0:
	/* 0xfa0: add    r10d,0x3 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_fa4:
	/* 0xfa4: and    r10d,0xfff */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_fab:
	/* 0xfab: movzx  r10d,BYTE PTR [r14+r10*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R10, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R10, 0, X86_WIDTH_8), 0ULL);
x86_l_fb0:
	/* 0xfb0: mov    BYTE PTR [rsi-0x1],r10b */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSI, X86_R10, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_fb4:
	/* 0xfb4: mov    r10,rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R10, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_fb7:
	/* 0xfb7: add    r10,r9 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R10, X86_R9, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_fba:
	/* 0xfba: je     ff3 <filter_char_buf_postfix+0x11e> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xfba, 0xff3, x86_l_ff3);
x86_l_fbc:
	/* 0xfbc: cmp    r9,0xffffffffffffff81 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_64, 0, 18446744073709551489ULL);
x86_l_fc0:
	/* 0xfc0: je     ff3 <filter_char_buf_postfix+0x11e> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xfc0, 0xff3, x86_l_ff3);
x86_l_fc2:
	/* 0xfc2: lea    r10d,[rdx+r9*1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R10, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_fc6:
	/* 0xfc6: add    r10d,0x3 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_fca:
	/* 0xfca: and    r10d,0xfff */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_fd1:
	/* 0xfd1: movzx  r10d,BYTE PTR [r14+r10*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R10, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R10, 0, X86_WIDTH_8), 0ULL);
x86_l_fd6:
	/* 0xfd6: mov    BYTE PTR [rsi],r10b */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSI, X86_R10, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fd9:
	/* 0xfd9: add    rsi,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_fdd:
	/* 0xfdd: lea    r10,[rcx+r9*1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R10, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_fe1:
	/* 0xfe1: add    r10,0xfffffffffffffffc */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551612ULL);
x86_l_fe5:
	/* 0xfe5: add    r9,0xfffffffffffffffc */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551612ULL);
x86_l_fe9:
	/* 0xfe9: cmp    r10,0xfffffffffffffffd */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_64, 0, 18446744073709551613ULL);
x86_l_fed:
	/* 0xfed: jne    f5c <filter_char_buf_postfix+0x87> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0xfed, 0xf5c, x86_l_f5c);
x86_l_ff3:
	/* 0xff3: mov    rdi,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_ff6:
	/* 0xff6: mov    rsi,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_ff9:
	/* 0xff9: call   2f67 <__native_link_local_memset_zero_dynamic+0xcd7> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_ffe:
	/* 0xffe: mov    rcx,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_1001:
	/* 0x1001: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1003:
	/* 0x1003: test   rcx,rcx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_1006:
	/* 0x1006: setne  al */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_CC_NE, 0);
x86_l_1009:
	/* 0x1009: jmp    100d <filter_char_buf_postfix+0x138> */
	X86_SIM_X86_SUB_JMP(0x1009, 0x100d, x86_l_100d);
x86_l_100b:
	/* 0x100b: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_100d:
	/* 0x100d: add    rsp,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1011:
	/* 0x1011: pop    rbx */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1012:
	/* 0x1012: pop    r14 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R14, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1014:
	/* 0x1014: pop    r15 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R15, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1016:
	/* 0x1016: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_1016);

	/* native subroutine native_link_sub_1017 */
x86_l_1017:
	/* 0x1017: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_101a:
	/* 0x101a: lea    edx,[rcx-0x1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_101d:
	/* 0x101d: cmp    edx,0x24 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 36ULL);
x86_l_1020:
	/* 0x1020: ja     120d <filter_16ty_selector_val+0x1f6> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x1020, 0x120d, x86_l_120d);
x86_l_1026:
	/* 0x1026: mov    eax,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_102b:
	/* Capture image-bound code identity before scheduled instructions. */
	switch (X86_SIM_L_READ_REG(X86_RDX) << 2) {
	case 0ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x108eULL); break;
	case 4ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1138ULL); break;
	case 8ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x103cULL); break;
	case 12ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x103cULL); break;
	case 16ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x120dULL); break;
	case 20ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x103bULL); break;
	case 24ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x120dULL); break;
	case 28ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x120dULL); break;
	case 32ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x120dULL); break;
	case 36ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x120dULL); break;
	case 40ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x120dULL); break;
	case 44ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x10eeULL); break;
	case 48ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x120dULL); break;
	case 52ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x120dULL); break;
	case 56ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x120dULL); break;
	case 60ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x120dULL); break;
	case 64ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x120dULL); break;
	case 68ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x120dULL); break;
	case 72ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x120dULL); break;
	case 76ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x120dULL); break;
	case 80ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x120dULL); break;
	case 84ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x120dULL); break;
	case 88ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x120dULL); break;
	case 92ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x120dULL); break;
	case 96ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x120dULL); break;
	case 100ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x103bULL); break;
	case 104ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x103bULL); break;
	case 108ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x120dULL); break;
	case 112ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x120dULL); break;
	case 116ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x120dULL); break;
	case 120ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x120dULL); break;
	case 124ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x120dULL); break;
	case 128ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x120dULL); break;
	case 132ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x120dULL); break;
	case 136ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x120dULL); break;
	case 140ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x120dULL); break;
	case 144ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x103bULL); break;
	default: __x86_sim_unresolved_indirect_target();
	}
x86_l_1039:
	/* 0x1039: jmp    rdx */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RDX);
		switch (X86_SIM_L_REG_TAG(X86_RDX)) {
		case X86_SIM_TAG_CODE:
			switch (__x86_target) {
			case 0x103bULL: goto x86_l_103b;
			case 0x103cULL: goto x86_l_103c;
			case 0x108eULL: goto x86_l_108e;
			case 0x10eeULL: goto x86_l_10ee;
			case 0x1138ULL: goto x86_l_1138;
			case 0x120dULL: goto x86_l_120d;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_103b:
	/* 0x103b: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_70f);
x86_l_103c:
	/* 0x103c: movzx  edx,WORD PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_103f:
	/* 0x103f: cmp    DWORD PTR [rdi+0x10],edx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1042:
	/* 0x1042: jne    104d <filter_16ty_selector_val+0x36> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x1042, 0x104d, x86_l_104d);
x86_l_1044:
	/* 0x1044: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1046:
	/* 0x1046: cmp    ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 3ULL);
x86_l_1049:
	/* 0x1049: sete   al */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_CC_E, 0);
x86_l_104c:
	/* 0x104c: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_70f);
x86_l_104d:
	/* 0x104d: mov    esi,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1050:
	/* 0x1050: cmp    esi,0xd */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 13ULL);
x86_l_1053:
	/* 0x1053: jb     106e <filter_16ty_selector_val+0x57> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1053, 0x106e, x86_l_106e);
x86_l_1055:
	/* 0x1055: cmp    DWORD PTR [rdi+0x14],edx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1058:
	/* 0x1058: je     1044 <filter_16ty_selector_val+0x2d> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1058, 0x1044, x86_l_1044);
x86_l_105a:
	/* 0x105a: cmp    esi,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_105d:
	/* 0x105d: jb     106e <filter_16ty_selector_val+0x57> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x105d, 0x106e, x86_l_106e);
x86_l_105f:
	/* 0x105f: cmp    DWORD PTR [rdi+0x18],edx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1062:
	/* 0x1062: je     1044 <filter_16ty_selector_val+0x2d> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1062, 0x1044, x86_l_1044);
x86_l_1064:
	/* 0x1064: cmp    esi,0x15 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 21ULL);
x86_l_1067:
	/* 0x1067: jb     106e <filter_16ty_selector_val+0x57> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1067, 0x106e, x86_l_106e);
x86_l_1069:
	/* 0x1069: cmp    DWORD PTR [rdi+0x1c],edx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_106c:
	/* 0x106c: je     1044 <filter_16ty_selector_val+0x2d> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x106c, 0x1044, x86_l_1044);
x86_l_106e:
	/* 0x106e: cmp    ecx,0x25 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 37ULL);
x86_l_1071:
	/* 0x1071: ja     120d <filter_16ty_selector_val+0x1f6> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x1071, 0x120d, x86_l_120d);
x86_l_1077:
	/* 0x1077: mov    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_1079:
	/* 0x1079: movabs rdx,0x200c000050 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, 0, 137640280144ULL);
x86_l_1083:
	/* 0x1083: bt     rdx,rcx */
	X86_SIM_RUN_OP(X86_OP_BT, X86_RDX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_1087:
	/* 0x1087: jb     103b <filter_16ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1087, 0x103b, x86_l_103b);
x86_l_1089:
	/* 0x1089: jmp    120d <filter_16ty_selector_val+0x1f6> */
	X86_SIM_X86_SUB_JMP(0x1089, 0x120d, x86_l_120d);
x86_l_108e:
	/* 0x108e: mov    ecx,DWORD PTR [rdi+0xc] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1091:
	/* 0x1091: cmp    ecx,0xc */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 12ULL);
x86_l_1094:
	/* 0x1094: ja     1199 <filter_16ty_selector_val+0x182> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x1094, 0x1199, x86_l_1199);
x86_l_109a:
	/* 0x109a: mov    edx,0x1402 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 5122ULL);
x86_l_109f:
	/* 0x109f: bt     edx,ecx */
	X86_SIM_RUN_OP(X86_OP_BT, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_10a2:
	/* 0x10a2: jae    1199 <filter_16ty_selector_val+0x182> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x10a2, 0x1199, x86_l_1199);
x86_l_10a8:
	/* 0x10a8: movsx  ecx,WORD PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOVSX_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_10ab:
	/* 0x10ab: cmp    DWORD PTR [rdi+0x10],ecx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10ae:
	/* 0x10ae: jl     103b <filter_16ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_L, 0x10ae, 0x103b, x86_l_103b);
x86_l_10b0:
	/* 0x10b0: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10b3:
	/* 0x10b3: cmp    edx,0xd */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 13ULL);
x86_l_10b6:
	/* 0x10b6: jb     120d <filter_16ty_selector_val+0x1f6> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x10b6, 0x120d, x86_l_120d);
x86_l_10bc:
	/* 0x10bc: cmp    DWORD PTR [rdi+0x14],ecx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_10bf:
	/* 0x10bf: jl     103b <filter_16ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_L, 0x10bf, 0x103b, x86_l_103b);
x86_l_10c5:
	/* 0x10c5: cmp    edx,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_10c8:
	/* 0x10c8: jb     120d <filter_16ty_selector_val+0x1f6> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x10c8, 0x120d, x86_l_120d);
x86_l_10ce:
	/* 0x10ce: cmp    DWORD PTR [rdi+0x18],ecx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_10d1:
	/* 0x10d1: jl     103b <filter_16ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_L, 0x10d1, 0x103b, x86_l_103b);
x86_l_10d7:
	/* 0x10d7: cmp    edx,0x15 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 21ULL);
x86_l_10da:
	/* 0x10da: jb     120d <filter_16ty_selector_val+0x1f6> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x10da, 0x120d, x86_l_120d);
x86_l_10e0:
	/* 0x10e0: cmp    DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_10e3:
	/* 0x10e3: jl     103b <filter_16ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_L, 0x10e3, 0x103b, x86_l_103b);
x86_l_10e9:
	/* 0x10e9: jmp    120d <filter_16ty_selector_val+0x1f6> */
	X86_SIM_X86_SUB_JMP(0x10e9, 0x120d, x86_l_120d);
x86_l_10ee:
	/* 0x10ee: movzx  ecx,WORD PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_10f1:
	/* 0x10f1: test   DWORD PTR [rdi+0x10],ecx */
	X86_SIM_RUN_OP(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_10f4:
	/* 0x10f4: jne    103b <filter_16ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x10f4, 0x103b, x86_l_103b);
x86_l_10fa:
	/* 0x10fa: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10fd:
	/* 0x10fd: cmp    edx,0xd */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 13ULL);
x86_l_1100:
	/* 0x1100: jb     120d <filter_16ty_selector_val+0x1f6> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1100, 0x120d, x86_l_120d);
x86_l_1106:
	/* 0x1106: test   DWORD PTR [rdi+0x14],ecx */
	X86_SIM_RUN_OP(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_1109:
	/* 0x1109: jne    103b <filter_16ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x1109, 0x103b, x86_l_103b);
x86_l_110f:
	/* 0x110f: cmp    edx,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_1112:
	/* 0x1112: jb     120d <filter_16ty_selector_val+0x1f6> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1112, 0x120d, x86_l_120d);
x86_l_1118:
	/* 0x1118: test   DWORD PTR [rdi+0x18],ecx */
	X86_SIM_RUN_OP(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_111b:
	/* 0x111b: jne    103b <filter_16ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x111b, 0x103b, x86_l_103b);
x86_l_1121:
	/* 0x1121: cmp    edx,0x15 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 21ULL);
x86_l_1124:
	/* 0x1124: jb     120d <filter_16ty_selector_val+0x1f6> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1124, 0x120d, x86_l_120d);
x86_l_112a:
	/* 0x112a: test   DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_RUN_OP(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120259084288ULL);
x86_l_112d:
	/* 0x112d: jne    103b <filter_16ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x112d, 0x103b, x86_l_103b);
x86_l_1133:
	/* 0x1133: jmp    120d <filter_16ty_selector_val+0x1f6> */
	X86_SIM_X86_SUB_JMP(0x1133, 0x120d, x86_l_120d);
x86_l_1138:
	/* 0x1138: mov    ecx,DWORD PTR [rdi+0xc] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_113b:
	/* 0x113b: cmp    ecx,0xc */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 12ULL);
x86_l_113e:
	/* 0x113e: ja     11d4 <filter_16ty_selector_val+0x1bd> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x113e, 0x11d4, x86_l_11d4);
x86_l_1144:
	/* 0x1144: mov    edx,0x1402 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 5122ULL);
x86_l_1149:
	/* 0x1149: bt     edx,ecx */
	X86_SIM_RUN_OP(X86_OP_BT, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_114c:
	/* 0x114c: jae    11d4 <filter_16ty_selector_val+0x1bd> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x114c, 0x11d4, x86_l_11d4);
x86_l_1152:
	/* 0x1152: movsx  ecx,WORD PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOVSX_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1155:
	/* 0x1155: cmp    DWORD PTR [rdi+0x10],ecx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1158:
	/* 0x1158: jg     103b <filter_16ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x1158, 0x103b, x86_l_103b);
x86_l_115e:
	/* 0x115e: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1161:
	/* 0x1161: cmp    edx,0xd */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 13ULL);
x86_l_1164:
	/* 0x1164: jb     120d <filter_16ty_selector_val+0x1f6> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1164, 0x120d, x86_l_120d);
x86_l_116a:
	/* 0x116a: cmp    DWORD PTR [rdi+0x14],ecx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_116d:
	/* 0x116d: jg     103b <filter_16ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x116d, 0x103b, x86_l_103b);
x86_l_1173:
	/* 0x1173: cmp    edx,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_1176:
	/* 0x1176: jb     120d <filter_16ty_selector_val+0x1f6> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1176, 0x120d, x86_l_120d);
x86_l_117c:
	/* 0x117c: cmp    DWORD PTR [rdi+0x18],ecx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_117f:
	/* 0x117f: jg     103b <filter_16ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x117f, 0x103b, x86_l_103b);
x86_l_1185:
	/* 0x1185: cmp    edx,0x15 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 21ULL);
x86_l_1188:
	/* 0x1188: jb     120d <filter_16ty_selector_val+0x1f6> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1188, 0x120d, x86_l_120d);
x86_l_118e:
	/* 0x118e: cmp    DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1191:
	/* 0x1191: jg     103b <filter_16ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x1191, 0x103b, x86_l_103b);
x86_l_1197:
	/* 0x1197: jmp    120d <filter_16ty_selector_val+0x1f6> */
	X86_SIM_X86_SUB_JMP(0x1197, 0x120d, x86_l_120d);
x86_l_1199:
	/* 0x1199: movzx  ecx,WORD PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_119c:
	/* 0x119c: cmp    DWORD PTR [rdi+0x10],ecx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_119f:
	/* 0x119f: jb     103b <filter_16ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x119f, 0x103b, x86_l_103b);
x86_l_11a5:
	/* 0x11a5: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11a8:
	/* 0x11a8: cmp    edx,0xd */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 13ULL);
x86_l_11ab:
	/* 0x11ab: jb     120d <filter_16ty_selector_val+0x1f6> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x11ab, 0x120d, x86_l_120d);
x86_l_11ad:
	/* 0x11ad: cmp    DWORD PTR [rdi+0x14],ecx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_11b0:
	/* 0x11b0: jb     103b <filter_16ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x11b0, 0x103b, x86_l_103b);
x86_l_11b6:
	/* 0x11b6: cmp    edx,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_11b9:
	/* 0x11b9: jb     120d <filter_16ty_selector_val+0x1f6> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x11b9, 0x120d, x86_l_120d);
x86_l_11bb:
	/* 0x11bb: cmp    DWORD PTR [rdi+0x18],ecx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_11be:
	/* 0x11be: jb     103b <filter_16ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x11be, 0x103b, x86_l_103b);
x86_l_11c4:
	/* 0x11c4: cmp    edx,0x15 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 21ULL);
x86_l_11c7:
	/* 0x11c7: jb     120d <filter_16ty_selector_val+0x1f6> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x11c7, 0x120d, x86_l_120d);
x86_l_11c9:
	/* 0x11c9: cmp    DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_11cc:
	/* 0x11cc: jb     103b <filter_16ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x11cc, 0x103b, x86_l_103b);
x86_l_11d2:
	/* 0x11d2: jmp    120d <filter_16ty_selector_val+0x1f6> */
	X86_SIM_X86_SUB_JMP(0x11d2, 0x120d, x86_l_120d);
x86_l_11d4:
	/* 0x11d4: movzx  ecx,WORD PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_11d7:
	/* 0x11d7: cmp    DWORD PTR [rdi+0x10],ecx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11da:
	/* 0x11da: ja     103b <filter_16ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x11da, 0x103b, x86_l_103b);
x86_l_11e0:
	/* 0x11e0: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11e3:
	/* 0x11e3: cmp    edx,0xd */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 13ULL);
x86_l_11e6:
	/* 0x11e6: jb     120d <filter_16ty_selector_val+0x1f6> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x11e6, 0x120d, x86_l_120d);
x86_l_11e8:
	/* 0x11e8: cmp    DWORD PTR [rdi+0x14],ecx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_11eb:
	/* 0x11eb: ja     103b <filter_16ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x11eb, 0x103b, x86_l_103b);
x86_l_11f1:
	/* 0x11f1: cmp    edx,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_11f4:
	/* 0x11f4: jb     120d <filter_16ty_selector_val+0x1f6> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x11f4, 0x120d, x86_l_120d);
x86_l_11f6:
	/* 0x11f6: cmp    DWORD PTR [rdi+0x18],ecx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_11f9:
	/* 0x11f9: ja     103b <filter_16ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x11f9, 0x103b, x86_l_103b);
x86_l_11ff:
	/* 0x11ff: cmp    edx,0x15 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 21ULL);
x86_l_1202:
	/* 0x1202: jb     120d <filter_16ty_selector_val+0x1f6> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1202, 0x120d, x86_l_120d);
x86_l_1204:
	/* 0x1204: cmp    DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1207:
	/* 0x1207: ja     103b <filter_16ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x1207, 0x103b, x86_l_103b);
x86_l_120d:
	/* 0x120d: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_120f:
	/* 0x120f: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_70f);

	/* native subroutine native_link_sub_1210 */
x86_l_1210:
	/* 0x1210: push   r14 */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_1212:
	/* 0x1212: push   rbx */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_1213:
	/* 0x1213: sub    rsp,0x18 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SUB, 24ULL);
x86_l_1217:
	/* 0x1217: mov    r14,rsi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R14, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_121a:
	/* 0x121a: mov    rbx,rdi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RBX, X86_RDI, X86_WIDTH_64, 0, 0);
x86_l_121d:
	/* 0x121d: movzx  eax,BYTE PTR [rdi+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_1221:
	/* 0x1221: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1225:
	/* 0x1225: mov    rdi,QWORD PTR [rip+0xf00] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)argfilter_maps));
x86_l_122c:
	/* 0x122c: lea    rsi,[rsp+0xc] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1231:
	/* 0x1231: call   2136 <filter_32ty_range+0x5c> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_1236:
	/* 0x1236: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_1239:
	/* 0x1239: je     126d <filter_16ty_map+0x5d> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1239, 0x126d, x86_l_126d);
x86_l_123b:
	/* 0x123b: movzx  ecx,WORD PTR [r14] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_123f:
	/* 0x123f: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1244:
	/* 0x1244: lea    rsi,[rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1249:
	/* 0x1249: mov    rdi,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_124c:
	/* 0x124c: call   2151 <filter_32ty_range+0x77> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_1251:
	/* 0x1251: mov    edx,DWORD PTR [rbx+0x4] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1254:
	/* 0x1254: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1256:
	/* 0x1256: cmp    edx,0x1d */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 29ULL);
x86_l_1259:
	/* 0x1259: ja     1287 <filter_16ty_map+0x77> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x1259, 0x1287, x86_l_1287);
x86_l_125b:
	/* 0x125b: mov    esi,0x30038400 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 805536768ULL);
x86_l_1260:
	/* 0x1260: bt     esi,edx */
	X86_SIM_RUN_OP(X86_OP_BT, X86_RSI, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_1263:
	/* 0x1263: jae    1277 <filter_16ty_map+0x67> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x1263, 0x1277, x86_l_1277);
x86_l_1265:
	/* 0x1265: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_1268:
	/* 0x1268: setne  cl */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_CC_NE, 0);
x86_l_126b:
	/* 0x126b: jmp    1287 <filter_16ty_map+0x77> */
	X86_SIM_X86_SUB_JMP(0x126b, 0x1287, x86_l_1287);
x86_l_126d:
	/* 0x126d: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_126f:
	/* 0x126f: add    rsp,0x18 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1273:
	/* 0x1273: pop    rbx */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1274:
	/* 0x1274: pop    r14 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R14, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1276:
	/* 0x1276: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_70f);
x86_l_1277:
	/* 0x1277: mov    esi,0xc0800 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 788480ULL);
x86_l_127c:
	/* 0x127c: bt     esi,edx */
	X86_SIM_RUN_OP(X86_OP_BT, X86_RSI, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_127f:
	/* 0x127f: jae    1287 <filter_16ty_map+0x77> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x127f, 0x1287, x86_l_1287);
x86_l_1281:
	/* 0x1281: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_1284:
	/* 0x1284: sete   cl */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_CC_E, 0);
x86_l_1287:
	/* 0x1287: movzx  eax,cl */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8, 0);
x86_l_128a:
	/* 0x128a: add    rsp,0x18 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_128e:
	/* 0x128e: pop    rbx */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_128f:
	/* 0x128f: pop    r14 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R14, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1291:
	/* 0x1291: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_70f);

	/* native subroutine native_link_sub_1292 */
x86_l_1292:
	/* 0x1292: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1295:
	/* 0x1295: mov    eax,DWORD PTR [rdi+0xc] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1298:
	/* 0x1298: cmp    eax,0xc */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 12ULL);
x86_l_129b:
	/* 0x129b: ja     1382 <filter_16ty_range+0xf0> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x129b, 0x1382, x86_l_1382);
x86_l_12a1:
	/* 0x12a1: mov    edx,0x1402 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 5122ULL);
x86_l_12a6:
	/* 0x12a6: bt     edx,eax */
	X86_SIM_RUN_OP(X86_OP_BT, X86_RDX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_12a9:
	/* 0x12a9: jae    1382 <filter_16ty_range+0xf0> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x12a9, 0x1382, x86_l_1382);
x86_l_12af:
	/* 0x12af: movsx  esi,WORD PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOVSX_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_12b2:
	/* 0x12b2: cmp    ecx,0x1f */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 31ULL);
x86_l_12b5:
	/* 0x12b5: jne    131d <filter_16ty_range+0x8b> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x12b5, 0x131d, x86_l_131d);
x86_l_12b7:
	/* 0x12b7: mov    eax,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_12bc:
	/* 0x12bc: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_12bf:
	/* 0x12bf: jg     12ca <filter_16ty_range+0x38> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x12bf, 0x12ca, x86_l_12ca);
x86_l_12c1:
	/* 0x12c1: cmp    DWORD PTR [rdi+0x14],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_12c4:
	/* 0x12c4: jge    1399 <filter_16ty_range+0x107> */
	X86_SIM_X86_SUB_JCC(X86_CC_GE, 0x12c4, 0x1399, x86_l_1399);
x86_l_12ca:
	/* 0x12ca: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12cd:
	/* 0x12cd: cmp    edx,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_12d0:
	/* 0x12d0: jb     1439 <filter_16ty_range+0x1a7> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x12d0, 0x1439, x86_l_1439);
x86_l_12d6:
	/* 0x12d6: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_12d9:
	/* 0x12d9: jg     12e4 <filter_16ty_range+0x52> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x12d9, 0x12e4, x86_l_12e4);
x86_l_12db:
	/* 0x12db: cmp    DWORD PTR [rdi+0x1c],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_12de:
	/* 0x12de: jge    1399 <filter_16ty_range+0x107> */
	X86_SIM_X86_SUB_JCC(X86_CC_GE, 0x12de, 0x1399, x86_l_1399);
x86_l_12e4:
	/* 0x12e4: cmp    edx,0x19 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 25ULL);
x86_l_12e7:
	/* 0x12e7: jb     1439 <filter_16ty_range+0x1a7> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x12e7, 0x1439, x86_l_1439);
x86_l_12ed:
	/* 0x12ed: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_12f0:
	/* 0x12f0: jg     12fb <filter_16ty_range+0x69> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x12f0, 0x12fb, x86_l_12fb);
x86_l_12f2:
	/* 0x12f2: cmp    DWORD PTR [rdi+0x24],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_12f5:
	/* 0x12f5: jge    1399 <filter_16ty_range+0x107> */
	X86_SIM_X86_SUB_JCC(X86_CC_GE, 0x12f5, 0x1399, x86_l_1399);
x86_l_12fb:
	/* 0x12fb: cmp    edx,0x21 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 33ULL);
x86_l_12fe:
	/* 0x12fe: jb     1439 <filter_16ty_range+0x1a7> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x12fe, 0x1439, x86_l_1439);
x86_l_1304:
	/* 0x1304: xor    edx,edx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1306:
	/* 0x1306: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1309:
	/* 0x1309: jg     143b <filter_16ty_range+0x1a9> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x1309, 0x143b, x86_l_143b);
x86_l_130f:
	/* 0x130f: cmp    DWORD PTR [rdi+0x2c],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1312:
	/* 0x1312: jge    1399 <filter_16ty_range+0x107> */
	X86_SIM_X86_SUB_JCC(X86_CC_GE, 0x1312, 0x1399, x86_l_1399);
x86_l_1318:
	/* 0x1318: jmp    143b <filter_16ty_range+0x1a9> */
	X86_SIM_X86_SUB_JMP(0x1318, 0x143b, x86_l_143b);
x86_l_131d:
	/* 0x131d: mov    eax,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1320:
	/* 0x1320: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1323:
	/* 0x1323: setle  r8b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R8, X86_REG_NONE, X86_WIDTH_8, X86_CC_LE, 0);
x86_l_1327:
	/* 0x1327: cmp    DWORD PTR [rdi+0x14],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_132a:
	/* 0x132a: setge  dl */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_CC_GE, 0);
x86_l_132d:
	/* 0x132d: and    dl,r8b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_R8, X86_WIDTH_8, X86_ALU_AND, 0);
x86_l_1330:
	/* 0x1330: cmp    eax,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_1333:
	/* 0x1333: jb     143b <filter_16ty_range+0x1a9> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1333, 0x143b, x86_l_143b);
x86_l_1339:
	/* 0x1339: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_133c:
	/* 0x133c: setle  r8b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R8, X86_REG_NONE, X86_WIDTH_8, X86_CC_LE, 0);
x86_l_1340:
	/* 0x1340: cmp    DWORD PTR [rdi+0x1c],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1343:
	/* 0x1343: setge  r9b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R9, X86_REG_NONE, X86_WIDTH_8, X86_CC_GE, 0);
x86_l_1347:
	/* 0x1347: and    r9b,r8b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND, 0);
x86_l_134a:
	/* 0x134a: or     dl,r9b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR, 0);
x86_l_134d:
	/* 0x134d: cmp    eax,0x19 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 25ULL);
x86_l_1350:
	/* 0x1350: jb     143b <filter_16ty_range+0x1a9> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1350, 0x143b, x86_l_143b);
x86_l_1356:
	/* 0x1356: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1359:
	/* 0x1359: setle  r8b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R8, X86_REG_NONE, X86_WIDTH_8, X86_CC_LE, 0);
x86_l_135d:
	/* 0x135d: cmp    DWORD PTR [rdi+0x24],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1360:
	/* 0x1360: setge  r9b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R9, X86_REG_NONE, X86_WIDTH_8, X86_CC_GE, 0);
x86_l_1364:
	/* 0x1364: and    r9b,r8b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND, 0);
x86_l_1367:
	/* 0x1367: or     dl,r9b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR, 0);
x86_l_136a:
	/* 0x136a: cmp    eax,0x21 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 33ULL);
x86_l_136d:
	/* 0x136d: jb     143b <filter_16ty_range+0x1a9> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x136d, 0x143b, x86_l_143b);
x86_l_1373:
	/* 0x1373: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1376:
	/* 0x1376: setle  al */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_CC_LE, 0);
x86_l_1379:
	/* 0x1379: cmp    DWORD PTR [rdi+0x2c],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_137c:
	/* 0x137c: setge  sil */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_CC_GE, 0);
x86_l_1380:
	/* 0x1380: jmp    13f5 <filter_16ty_range+0x163> */
	X86_SIM_X86_SUB_JMP(0x1380, 0x13f5, x86_l_13f5);
x86_l_1382:
	/* 0x1382: movzx  esi,WORD PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1385:
	/* 0x1385: cmp    ecx,0x1f */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 31ULL);
x86_l_1388:
	/* 0x1388: jne    139a <filter_16ty_range+0x108> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x1388, 0x139a, x86_l_139a);
x86_l_138a:
	/* 0x138a: mov    eax,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_138f:
	/* 0x138f: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1392:
	/* 0x1392: ja     13fd <filter_16ty_range+0x16b> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x1392, 0x13fd, x86_l_13fd);
x86_l_1394:
	/* 0x1394: cmp    DWORD PTR [rdi+0x14],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1397:
	/* 0x1397: jb     13fd <filter_16ty_range+0x16b> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1397, 0x13fd, x86_l_13fd);
x86_l_1399:
	/* 0x1399: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_70f);
x86_l_139a:
	/* 0x139a: mov    eax,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_139d:
	/* 0x139d: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_13a0:
	/* 0x13a0: setbe  r8b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R8, X86_REG_NONE, X86_WIDTH_8, X86_CC_BE, 0);
x86_l_13a4:
	/* 0x13a4: cmp    DWORD PTR [rdi+0x14],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_13a7:
	/* 0x13a7: setae  dl */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_CC_AE, 0);
x86_l_13aa:
	/* 0x13aa: and    dl,r8b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_R8, X86_WIDTH_8, X86_ALU_AND, 0);
x86_l_13ad:
	/* 0x13ad: cmp    eax,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_13b0:
	/* 0x13b0: jb     143b <filter_16ty_range+0x1a9> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x13b0, 0x143b, x86_l_143b);
x86_l_13b6:
	/* 0x13b6: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_13b9:
	/* 0x13b9: setbe  r8b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R8, X86_REG_NONE, X86_WIDTH_8, X86_CC_BE, 0);
x86_l_13bd:
	/* 0x13bd: cmp    DWORD PTR [rdi+0x1c],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_13c0:
	/* 0x13c0: setae  r9b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R9, X86_REG_NONE, X86_WIDTH_8, X86_CC_AE, 0);
x86_l_13c4:
	/* 0x13c4: and    r9b,r8b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND, 0);
x86_l_13c7:
	/* 0x13c7: or     dl,r9b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR, 0);
x86_l_13ca:
	/* 0x13ca: cmp    eax,0x19 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 25ULL);
x86_l_13cd:
	/* 0x13cd: jb     143b <filter_16ty_range+0x1a9> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x13cd, 0x143b, x86_l_143b);
x86_l_13cf:
	/* 0x13cf: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_13d2:
	/* 0x13d2: setbe  r8b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R8, X86_REG_NONE, X86_WIDTH_8, X86_CC_BE, 0);
x86_l_13d6:
	/* 0x13d6: cmp    DWORD PTR [rdi+0x24],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_13d9:
	/* 0x13d9: setae  r9b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R9, X86_REG_NONE, X86_WIDTH_8, X86_CC_AE, 0);
x86_l_13dd:
	/* 0x13dd: and    r9b,r8b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND, 0);
x86_l_13e0:
	/* 0x13e0: or     dl,r9b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR, 0);
x86_l_13e3:
	/* 0x13e3: cmp    eax,0x21 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 33ULL);
x86_l_13e6:
	/* 0x13e6: jb     143b <filter_16ty_range+0x1a9> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x13e6, 0x143b, x86_l_143b);
x86_l_13e8:
	/* 0x13e8: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_13eb:
	/* 0x13eb: setbe  al */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_CC_BE, 0);
x86_l_13ee:
	/* 0x13ee: cmp    DWORD PTR [rdi+0x2c],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_13f1:
	/* 0x13f1: setae  sil */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_CC_AE, 0);
x86_l_13f5:
	/* 0x13f5: and    sil,al */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_ALU_AND, 0);
x86_l_13f8:
	/* 0x13f8: or     dl,sil */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RSI, X86_WIDTH_8, X86_ALU_OR, 0);
x86_l_13fb:
	/* 0x13fb: jmp    143b <filter_16ty_range+0x1a9> */
	X86_SIM_X86_SUB_JMP(0x13fb, 0x143b, x86_l_143b);
x86_l_13fd:
	/* 0x13fd: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1400:
	/* 0x1400: cmp    edx,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_1403:
	/* 0x1403: jb     1439 <filter_16ty_range+0x1a7> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1403, 0x1439, x86_l_1439);
x86_l_1405:
	/* 0x1405: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1408:
	/* 0x1408: ja     140f <filter_16ty_range+0x17d> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x1408, 0x140f, x86_l_140f);
x86_l_140a:
	/* 0x140a: cmp    DWORD PTR [rdi+0x1c],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_140d:
	/* 0x140d: jae    1399 <filter_16ty_range+0x107> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x140d, 0x1399, x86_l_1399);
x86_l_140f:
	/* 0x140f: cmp    edx,0x19 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 25ULL);
x86_l_1412:
	/* 0x1412: jb     1439 <filter_16ty_range+0x1a7> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1412, 0x1439, x86_l_1439);
x86_l_1414:
	/* 0x1414: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1417:
	/* 0x1417: ja     1422 <filter_16ty_range+0x190> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x1417, 0x1422, x86_l_1422);
x86_l_1419:
	/* 0x1419: cmp    DWORD PTR [rdi+0x24],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_141c:
	/* 0x141c: jae    1399 <filter_16ty_range+0x107> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x141c, 0x1399, x86_l_1399);
x86_l_1422:
	/* 0x1422: cmp    edx,0x21 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 33ULL);
x86_l_1425:
	/* 0x1425: jb     1439 <filter_16ty_range+0x1a7> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1425, 0x1439, x86_l_1439);
x86_l_1427:
	/* 0x1427: xor    edx,edx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1429:
	/* 0x1429: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_142c:
	/* 0x142c: ja     143b <filter_16ty_range+0x1a9> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x142c, 0x143b, x86_l_143b);
x86_l_142e:
	/* 0x142e: cmp    DWORD PTR [rdi+0x2c],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1431:
	/* 0x1431: jae    1399 <filter_16ty_range+0x107> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x1431, 0x1399, x86_l_1399);
x86_l_1437:
	/* 0x1437: jmp    143b <filter_16ty_range+0x1a9> */
	X86_SIM_X86_SUB_JMP(0x1437, 0x143b, x86_l_143b);
x86_l_1439:
	/* 0x1439: xor    edx,edx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_143b:
	/* 0x143b: cmp    ecx,0x20 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 32ULL);
x86_l_143e:
	/* 0x143e: sete   al */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_CC_E, 0);
x86_l_1441:
	/* 0x1441: xor    dl,0x1 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_ALU_XOR, 1ULL);
x86_l_1444:
	/* 0x1444: and    dl,al */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RAX, X86_WIDTH_8, X86_ALU_AND, 0);
x86_l_1446:
	/* 0x1446: movzx  eax,dl */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8, 0);
x86_l_1449:
	/* 0x1449: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_70f);

	/* native subroutine native_link_sub_144a */
x86_l_144a:
	/* 0x144a: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_144d:
	/* 0x144d: lea    edx,[rcx-0x1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_1450:
	/* 0x1450: cmp    edx,0x24 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 36ULL);
x86_l_1453:
	/* 0x1453: ja     1640 <filter_8ty_selector_val+0x1f6> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x1453, 0x1640, x86_l_1640);
x86_l_1459:
	/* 0x1459: mov    eax,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_145e:
	/* Capture image-bound code identity before scheduled instructions. */
	switch (X86_SIM_L_READ_REG(X86_RDX) << 2) {
	case 0ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x14c1ULL); break;
	case 4ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x156bULL); break;
	case 8ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x146fULL); break;
	case 12ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x146fULL); break;
	case 16ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1640ULL); break;
	case 20ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x146eULL); break;
	case 24ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1640ULL); break;
	case 28ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1640ULL); break;
	case 32ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1640ULL); break;
	case 36ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1640ULL); break;
	case 40ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1640ULL); break;
	case 44ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1521ULL); break;
	case 48ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1640ULL); break;
	case 52ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1640ULL); break;
	case 56ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1640ULL); break;
	case 60ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1640ULL); break;
	case 64ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1640ULL); break;
	case 68ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1640ULL); break;
	case 72ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1640ULL); break;
	case 76ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1640ULL); break;
	case 80ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1640ULL); break;
	case 84ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1640ULL); break;
	case 88ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1640ULL); break;
	case 92ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1640ULL); break;
	case 96ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1640ULL); break;
	case 100ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x146eULL); break;
	case 104ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x146eULL); break;
	case 108ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1640ULL); break;
	case 112ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1640ULL); break;
	case 116ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1640ULL); break;
	case 120ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1640ULL); break;
	case 124ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1640ULL); break;
	case 128ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1640ULL); break;
	case 132ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1640ULL); break;
	case 136ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1640ULL); break;
	case 140ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1640ULL); break;
	case 144ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x146eULL); break;
	default: __x86_sim_unresolved_indirect_target();
	}
x86_l_146c:
	/* 0x146c: jmp    rdx */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RDX);
		switch (X86_SIM_L_REG_TAG(X86_RDX)) {
		case X86_SIM_TAG_CODE:
			switch (__x86_target) {
			case 0x146eULL: goto x86_l_146e;
			case 0x146fULL: goto x86_l_146f;
			case 0x14c1ULL: goto x86_l_14c1;
			case 0x1521ULL: goto x86_l_1521;
			case 0x156bULL: goto x86_l_156b;
			case 0x1640ULL: goto x86_l_1640;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_146e:
	/* 0x146e: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_6ce);
x86_l_146f:
	/* 0x146f: movzx  edx,BYTE PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1472:
	/* 0x1472: cmp    DWORD PTR [rdi+0x10],edx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1475:
	/* 0x1475: jne    1480 <filter_8ty_selector_val+0x36> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x1475, 0x1480, x86_l_1480);
x86_l_1477:
	/* 0x1477: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1479:
	/* 0x1479: cmp    ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 3ULL);
x86_l_147c:
	/* 0x147c: sete   al */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_CC_E, 0);
x86_l_147f:
	/* 0x147f: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_6ce);
x86_l_1480:
	/* 0x1480: mov    esi,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1483:
	/* 0x1483: cmp    esi,0xd */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 13ULL);
x86_l_1486:
	/* 0x1486: jb     14a1 <filter_8ty_selector_val+0x57> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1486, 0x14a1, x86_l_14a1);
x86_l_1488:
	/* 0x1488: cmp    DWORD PTR [rdi+0x14],edx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_148b:
	/* 0x148b: je     1477 <filter_8ty_selector_val+0x2d> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x148b, 0x1477, x86_l_1477);
x86_l_148d:
	/* 0x148d: cmp    esi,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_1490:
	/* 0x1490: jb     14a1 <filter_8ty_selector_val+0x57> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1490, 0x14a1, x86_l_14a1);
x86_l_1492:
	/* 0x1492: cmp    DWORD PTR [rdi+0x18],edx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1495:
	/* 0x1495: je     1477 <filter_8ty_selector_val+0x2d> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1495, 0x1477, x86_l_1477);
x86_l_1497:
	/* 0x1497: cmp    esi,0x15 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 21ULL);
x86_l_149a:
	/* 0x149a: jb     14a1 <filter_8ty_selector_val+0x57> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x149a, 0x14a1, x86_l_14a1);
x86_l_149c:
	/* 0x149c: cmp    DWORD PTR [rdi+0x1c],edx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_149f:
	/* 0x149f: je     1477 <filter_8ty_selector_val+0x2d> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x149f, 0x1477, x86_l_1477);
x86_l_14a1:
	/* 0x14a1: cmp    ecx,0x25 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 37ULL);
x86_l_14a4:
	/* 0x14a4: ja     1640 <filter_8ty_selector_val+0x1f6> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x14a4, 0x1640, x86_l_1640);
x86_l_14aa:
	/* 0x14aa: mov    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_14ac:
	/* 0x14ac: movabs rdx,0x200c000050 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, 0, 137640280144ULL);
x86_l_14b6:
	/* 0x14b6: bt     rdx,rcx */
	X86_SIM_RUN_OP(X86_OP_BT, X86_RDX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_14ba:
	/* 0x14ba: jb     146e <filter_8ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x14ba, 0x146e, x86_l_146e);
x86_l_14bc:
	/* 0x14bc: jmp    1640 <filter_8ty_selector_val+0x1f6> */
	X86_SIM_X86_SUB_JMP(0x14bc, 0x1640, x86_l_1640);
x86_l_14c1:
	/* 0x14c1: mov    ecx,DWORD PTR [rdi+0xc] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_14c4:
	/* 0x14c4: cmp    ecx,0xc */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 12ULL);
x86_l_14c7:
	/* 0x14c7: ja     15cc <filter_8ty_selector_val+0x182> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x14c7, 0x15cc, x86_l_15cc);
x86_l_14cd:
	/* 0x14cd: mov    edx,0x1402 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 5122ULL);
x86_l_14d2:
	/* 0x14d2: bt     edx,ecx */
	X86_SIM_RUN_OP(X86_OP_BT, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_14d5:
	/* 0x14d5: jae    15cc <filter_8ty_selector_val+0x182> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x14d5, 0x15cc, x86_l_15cc);
x86_l_14db:
	/* 0x14db: movsx  ecx,BYTE PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOVSX_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_14de:
	/* 0x14de: cmp    DWORD PTR [rdi+0x10],ecx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_14e1:
	/* 0x14e1: jl     146e <filter_8ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_L, 0x14e1, 0x146e, x86_l_146e);
x86_l_14e3:
	/* 0x14e3: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14e6:
	/* 0x14e6: cmp    edx,0xd */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 13ULL);
x86_l_14e9:
	/* 0x14e9: jb     1640 <filter_8ty_selector_val+0x1f6> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x14e9, 0x1640, x86_l_1640);
x86_l_14ef:
	/* 0x14ef: cmp    DWORD PTR [rdi+0x14],ecx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_14f2:
	/* 0x14f2: jl     146e <filter_8ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_L, 0x14f2, 0x146e, x86_l_146e);
x86_l_14f8:
	/* 0x14f8: cmp    edx,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_14fb:
	/* 0x14fb: jb     1640 <filter_8ty_selector_val+0x1f6> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x14fb, 0x1640, x86_l_1640);
x86_l_1501:
	/* 0x1501: cmp    DWORD PTR [rdi+0x18],ecx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1504:
	/* 0x1504: jl     146e <filter_8ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_L, 0x1504, 0x146e, x86_l_146e);
x86_l_150a:
	/* 0x150a: cmp    edx,0x15 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 21ULL);
x86_l_150d:
	/* 0x150d: jb     1640 <filter_8ty_selector_val+0x1f6> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x150d, 0x1640, x86_l_1640);
x86_l_1513:
	/* 0x1513: cmp    DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1516:
	/* 0x1516: jl     146e <filter_8ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_L, 0x1516, 0x146e, x86_l_146e);
x86_l_151c:
	/* 0x151c: jmp    1640 <filter_8ty_selector_val+0x1f6> */
	X86_SIM_X86_SUB_JMP(0x151c, 0x1640, x86_l_1640);
x86_l_1521:
	/* 0x1521: movzx  ecx,BYTE PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1524:
	/* 0x1524: test   DWORD PTR [rdi+0x10],ecx */
	X86_SIM_RUN_OP(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1527:
	/* 0x1527: jne    146e <filter_8ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x1527, 0x146e, x86_l_146e);
x86_l_152d:
	/* 0x152d: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1530:
	/* 0x1530: cmp    edx,0xd */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 13ULL);
x86_l_1533:
	/* 0x1533: jb     1640 <filter_8ty_selector_val+0x1f6> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1533, 0x1640, x86_l_1640);
x86_l_1539:
	/* 0x1539: test   DWORD PTR [rdi+0x14],ecx */
	X86_SIM_RUN_OP(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_153c:
	/* 0x153c: jne    146e <filter_8ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x153c, 0x146e, x86_l_146e);
x86_l_1542:
	/* 0x1542: cmp    edx,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_1545:
	/* 0x1545: jb     1640 <filter_8ty_selector_val+0x1f6> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1545, 0x1640, x86_l_1640);
x86_l_154b:
	/* 0x154b: test   DWORD PTR [rdi+0x18],ecx */
	X86_SIM_RUN_OP(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_154e:
	/* 0x154e: jne    146e <filter_8ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x154e, 0x146e, x86_l_146e);
x86_l_1554:
	/* 0x1554: cmp    edx,0x15 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 21ULL);
x86_l_1557:
	/* 0x1557: jb     1640 <filter_8ty_selector_val+0x1f6> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1557, 0x1640, x86_l_1640);
x86_l_155d:
	/* 0x155d: test   DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_RUN_OP(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120259084288ULL);
x86_l_1560:
	/* 0x1560: jne    146e <filter_8ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x1560, 0x146e, x86_l_146e);
x86_l_1566:
	/* 0x1566: jmp    1640 <filter_8ty_selector_val+0x1f6> */
	X86_SIM_X86_SUB_JMP(0x1566, 0x1640, x86_l_1640);
x86_l_156b:
	/* 0x156b: mov    ecx,DWORD PTR [rdi+0xc] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_156e:
	/* 0x156e: cmp    ecx,0xc */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 12ULL);
x86_l_1571:
	/* 0x1571: ja     1607 <filter_8ty_selector_val+0x1bd> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x1571, 0x1607, x86_l_1607);
x86_l_1577:
	/* 0x1577: mov    edx,0x1402 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 5122ULL);
x86_l_157c:
	/* 0x157c: bt     edx,ecx */
	X86_SIM_RUN_OP(X86_OP_BT, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_157f:
	/* 0x157f: jae    1607 <filter_8ty_selector_val+0x1bd> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x157f, 0x1607, x86_l_1607);
x86_l_1585:
	/* 0x1585: movsx  ecx,BYTE PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOVSX_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1588:
	/* 0x1588: cmp    DWORD PTR [rdi+0x10],ecx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_158b:
	/* 0x158b: jg     146e <filter_8ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x158b, 0x146e, x86_l_146e);
x86_l_1591:
	/* 0x1591: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1594:
	/* 0x1594: cmp    edx,0xd */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 13ULL);
x86_l_1597:
	/* 0x1597: jb     1640 <filter_8ty_selector_val+0x1f6> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1597, 0x1640, x86_l_1640);
x86_l_159d:
	/* 0x159d: cmp    DWORD PTR [rdi+0x14],ecx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_15a0:
	/* 0x15a0: jg     146e <filter_8ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x15a0, 0x146e, x86_l_146e);
x86_l_15a6:
	/* 0x15a6: cmp    edx,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_15a9:
	/* 0x15a9: jb     1640 <filter_8ty_selector_val+0x1f6> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x15a9, 0x1640, x86_l_1640);
x86_l_15af:
	/* 0x15af: cmp    DWORD PTR [rdi+0x18],ecx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_15b2:
	/* 0x15b2: jg     146e <filter_8ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x15b2, 0x146e, x86_l_146e);
x86_l_15b8:
	/* 0x15b8: cmp    edx,0x15 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 21ULL);
x86_l_15bb:
	/* 0x15bb: jb     1640 <filter_8ty_selector_val+0x1f6> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x15bb, 0x1640, x86_l_1640);
x86_l_15c1:
	/* 0x15c1: cmp    DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_15c4:
	/* 0x15c4: jg     146e <filter_8ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x15c4, 0x146e, x86_l_146e);
x86_l_15ca:
	/* 0x15ca: jmp    1640 <filter_8ty_selector_val+0x1f6> */
	X86_SIM_X86_SUB_JMP(0x15ca, 0x1640, x86_l_1640);
x86_l_15cc:
	/* 0x15cc: movzx  ecx,BYTE PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_15cf:
	/* 0x15cf: cmp    DWORD PTR [rdi+0x10],ecx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_15d2:
	/* 0x15d2: jb     146e <filter_8ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x15d2, 0x146e, x86_l_146e);
x86_l_15d8:
	/* 0x15d8: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15db:
	/* 0x15db: cmp    edx,0xd */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 13ULL);
x86_l_15de:
	/* 0x15de: jb     1640 <filter_8ty_selector_val+0x1f6> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x15de, 0x1640, x86_l_1640);
x86_l_15e0:
	/* 0x15e0: cmp    DWORD PTR [rdi+0x14],ecx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_15e3:
	/* 0x15e3: jb     146e <filter_8ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x15e3, 0x146e, x86_l_146e);
x86_l_15e9:
	/* 0x15e9: cmp    edx,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_15ec:
	/* 0x15ec: jb     1640 <filter_8ty_selector_val+0x1f6> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x15ec, 0x1640, x86_l_1640);
x86_l_15ee:
	/* 0x15ee: cmp    DWORD PTR [rdi+0x18],ecx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_15f1:
	/* 0x15f1: jb     146e <filter_8ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x15f1, 0x146e, x86_l_146e);
x86_l_15f7:
	/* 0x15f7: cmp    edx,0x15 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 21ULL);
x86_l_15fa:
	/* 0x15fa: jb     1640 <filter_8ty_selector_val+0x1f6> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x15fa, 0x1640, x86_l_1640);
x86_l_15fc:
	/* 0x15fc: cmp    DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_15ff:
	/* 0x15ff: jb     146e <filter_8ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x15ff, 0x146e, x86_l_146e);
x86_l_1605:
	/* 0x1605: jmp    1640 <filter_8ty_selector_val+0x1f6> */
	X86_SIM_X86_SUB_JMP(0x1605, 0x1640, x86_l_1640);
x86_l_1607:
	/* 0x1607: movzx  ecx,BYTE PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_160a:
	/* 0x160a: cmp    DWORD PTR [rdi+0x10],ecx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_160d:
	/* 0x160d: ja     146e <filter_8ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x160d, 0x146e, x86_l_146e);
x86_l_1613:
	/* 0x1613: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1616:
	/* 0x1616: cmp    edx,0xd */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 13ULL);
x86_l_1619:
	/* 0x1619: jb     1640 <filter_8ty_selector_val+0x1f6> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1619, 0x1640, x86_l_1640);
x86_l_161b:
	/* 0x161b: cmp    DWORD PTR [rdi+0x14],ecx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_161e:
	/* 0x161e: ja     146e <filter_8ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x161e, 0x146e, x86_l_146e);
x86_l_1624:
	/* 0x1624: cmp    edx,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_1627:
	/* 0x1627: jb     1640 <filter_8ty_selector_val+0x1f6> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1627, 0x1640, x86_l_1640);
x86_l_1629:
	/* 0x1629: cmp    DWORD PTR [rdi+0x18],ecx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_162c:
	/* 0x162c: ja     146e <filter_8ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x162c, 0x146e, x86_l_146e);
x86_l_1632:
	/* 0x1632: cmp    edx,0x15 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 21ULL);
x86_l_1635:
	/* 0x1635: jb     1640 <filter_8ty_selector_val+0x1f6> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1635, 0x1640, x86_l_1640);
x86_l_1637:
	/* 0x1637: cmp    DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_163a:
	/* 0x163a: ja     146e <filter_8ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x163a, 0x146e, x86_l_146e);
x86_l_1640:
	/* 0x1640: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1642:
	/* 0x1642: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_6ce);

	/* native subroutine native_link_sub_1643 */
x86_l_1643:
	/* 0x1643: push   r14 */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_1645:
	/* 0x1645: push   rbx */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_1646:
	/* 0x1646: sub    rsp,0x18 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SUB, 24ULL);
x86_l_164a:
	/* 0x164a: mov    r14,rsi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R14, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_164d:
	/* 0x164d: mov    rbx,rdi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RBX, X86_RDI, X86_WIDTH_64, 0, 0);
x86_l_1650:
	/* 0x1650: movzx  eax,BYTE PTR [rdi+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_1654:
	/* 0x1654: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1658:
	/* 0x1658: mov    rdi,QWORD PTR [rip+0x1350] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)argfilter_maps));
x86_l_165f:
	/* 0x165f: lea    rsi,[rsp+0xc] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1664:
	/* 0x1664: call   29b9 <__native_link_local_memset_zero_dynamic+0x729> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_1669:
	/* 0x1669: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_166c:
	/* 0x166c: je     16a0 <filter_8ty_map+0x5d> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x166c, 0x16a0, x86_l_16a0);
x86_l_166e:
	/* 0x166e: movzx  ecx,BYTE PTR [r14] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1672:
	/* 0x1672: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1677:
	/* 0x1677: lea    rsi,[rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_167c:
	/* 0x167c: mov    rdi,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_167f:
	/* 0x167f: call   29d4 <__native_link_local_memset_zero_dynamic+0x744> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_1684:
	/* 0x1684: mov    edx,DWORD PTR [rbx+0x4] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1687:
	/* 0x1687: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1689:
	/* 0x1689: cmp    edx,0x1d */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 29ULL);
x86_l_168c:
	/* 0x168c: ja     16ba <filter_8ty_map+0x77> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x168c, 0x16ba, x86_l_16ba);
x86_l_168e:
	/* 0x168e: mov    esi,0x30038400 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 805536768ULL);
x86_l_1693:
	/* 0x1693: bt     esi,edx */
	X86_SIM_RUN_OP(X86_OP_BT, X86_RSI, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_1696:
	/* 0x1696: jae    16aa <filter_8ty_map+0x67> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x1696, 0x16aa, x86_l_16aa);
x86_l_1698:
	/* 0x1698: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_169b:
	/* 0x169b: setne  cl */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_CC_NE, 0);
x86_l_169e:
	/* 0x169e: jmp    16ba <filter_8ty_map+0x77> */
	X86_SIM_X86_SUB_JMP(0x169e, 0x16ba, x86_l_16ba);
x86_l_16a0:
	/* 0x16a0: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_16a2:
	/* 0x16a2: add    rsp,0x18 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_16a6:
	/* 0x16a6: pop    rbx */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_16a7:
	/* 0x16a7: pop    r14 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R14, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_16a9:
	/* 0x16a9: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_6ce);
x86_l_16aa:
	/* 0x16aa: mov    esi,0xc0800 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 788480ULL);
x86_l_16af:
	/* 0x16af: bt     esi,edx */
	X86_SIM_RUN_OP(X86_OP_BT, X86_RSI, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_16b2:
	/* 0x16b2: jae    16ba <filter_8ty_map+0x77> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x16b2, 0x16ba, x86_l_16ba);
x86_l_16b4:
	/* 0x16b4: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_16b7:
	/* 0x16b7: sete   cl */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_CC_E, 0);
x86_l_16ba:
	/* 0x16ba: movzx  eax,cl */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8, 0);
x86_l_16bd:
	/* 0x16bd: add    rsp,0x18 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_16c1:
	/* 0x16c1: pop    rbx */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_16c2:
	/* 0x16c2: pop    r14 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R14, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_16c4:
	/* 0x16c4: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_6ce);

	/* native subroutine native_link_sub_16c5 */
x86_l_16c5:
	/* 0x16c5: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_16c8:
	/* 0x16c8: mov    eax,DWORD PTR [rdi+0xc] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_16cb:
	/* 0x16cb: cmp    eax,0xc */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 12ULL);
x86_l_16ce:
	/* 0x16ce: ja     17b5 <filter_8ty_range+0xf0> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x16ce, 0x17b5, x86_l_17b5);
x86_l_16d4:
	/* 0x16d4: mov    edx,0x1402 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 5122ULL);
x86_l_16d9:
	/* 0x16d9: bt     edx,eax */
	X86_SIM_RUN_OP(X86_OP_BT, X86_RDX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_16dc:
	/* 0x16dc: jae    17b5 <filter_8ty_range+0xf0> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x16dc, 0x17b5, x86_l_17b5);
x86_l_16e2:
	/* 0x16e2: movsx  esi,BYTE PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOVSX_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_16e5:
	/* 0x16e5: cmp    ecx,0x1f */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 31ULL);
x86_l_16e8:
	/* 0x16e8: jne    1750 <filter_8ty_range+0x8b> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x16e8, 0x1750, x86_l_1750);
x86_l_16ea:
	/* 0x16ea: mov    eax,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_16ef:
	/* 0x16ef: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_16f2:
	/* 0x16f2: jg     16fd <filter_8ty_range+0x38> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x16f2, 0x16fd, x86_l_16fd);
x86_l_16f4:
	/* 0x16f4: cmp    DWORD PTR [rdi+0x14],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_16f7:
	/* 0x16f7: jge    17cc <filter_8ty_range+0x107> */
	X86_SIM_X86_SUB_JCC(X86_CC_GE, 0x16f7, 0x17cc, x86_l_17cc);
x86_l_16fd:
	/* 0x16fd: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1700:
	/* 0x1700: cmp    edx,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_1703:
	/* 0x1703: jb     186c <filter_8ty_range+0x1a7> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1703, 0x186c, x86_l_186c);
x86_l_1709:
	/* 0x1709: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_170c:
	/* 0x170c: jg     1717 <filter_8ty_range+0x52> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x170c, 0x1717, x86_l_1717);
x86_l_170e:
	/* 0x170e: cmp    DWORD PTR [rdi+0x1c],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1711:
	/* 0x1711: jge    17cc <filter_8ty_range+0x107> */
	X86_SIM_X86_SUB_JCC(X86_CC_GE, 0x1711, 0x17cc, x86_l_17cc);
x86_l_1717:
	/* 0x1717: cmp    edx,0x19 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 25ULL);
x86_l_171a:
	/* 0x171a: jb     186c <filter_8ty_range+0x1a7> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x171a, 0x186c, x86_l_186c);
x86_l_1720:
	/* 0x1720: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1723:
	/* 0x1723: jg     172e <filter_8ty_range+0x69> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x1723, 0x172e, x86_l_172e);
x86_l_1725:
	/* 0x1725: cmp    DWORD PTR [rdi+0x24],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1728:
	/* 0x1728: jge    17cc <filter_8ty_range+0x107> */
	X86_SIM_X86_SUB_JCC(X86_CC_GE, 0x1728, 0x17cc, x86_l_17cc);
x86_l_172e:
	/* 0x172e: cmp    edx,0x21 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 33ULL);
x86_l_1731:
	/* 0x1731: jb     186c <filter_8ty_range+0x1a7> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1731, 0x186c, x86_l_186c);
x86_l_1737:
	/* 0x1737: xor    edx,edx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1739:
	/* 0x1739: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_173c:
	/* 0x173c: jg     186e <filter_8ty_range+0x1a9> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x173c, 0x186e, x86_l_186e);
x86_l_1742:
	/* 0x1742: cmp    DWORD PTR [rdi+0x2c],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1745:
	/* 0x1745: jge    17cc <filter_8ty_range+0x107> */
	X86_SIM_X86_SUB_JCC(X86_CC_GE, 0x1745, 0x17cc, x86_l_17cc);
x86_l_174b:
	/* 0x174b: jmp    186e <filter_8ty_range+0x1a9> */
	X86_SIM_X86_SUB_JMP(0x174b, 0x186e, x86_l_186e);
x86_l_1750:
	/* 0x1750: mov    eax,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1753:
	/* 0x1753: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1756:
	/* 0x1756: setle  r8b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R8, X86_REG_NONE, X86_WIDTH_8, X86_CC_LE, 0);
x86_l_175a:
	/* 0x175a: cmp    DWORD PTR [rdi+0x14],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_175d:
	/* 0x175d: setge  dl */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_CC_GE, 0);
x86_l_1760:
	/* 0x1760: and    dl,r8b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_R8, X86_WIDTH_8, X86_ALU_AND, 0);
x86_l_1763:
	/* 0x1763: cmp    eax,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_1766:
	/* 0x1766: jb     186e <filter_8ty_range+0x1a9> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1766, 0x186e, x86_l_186e);
x86_l_176c:
	/* 0x176c: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_176f:
	/* 0x176f: setle  r8b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R8, X86_REG_NONE, X86_WIDTH_8, X86_CC_LE, 0);
x86_l_1773:
	/* 0x1773: cmp    DWORD PTR [rdi+0x1c],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1776:
	/* 0x1776: setge  r9b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R9, X86_REG_NONE, X86_WIDTH_8, X86_CC_GE, 0);
x86_l_177a:
	/* 0x177a: and    r9b,r8b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND, 0);
x86_l_177d:
	/* 0x177d: or     dl,r9b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR, 0);
x86_l_1780:
	/* 0x1780: cmp    eax,0x19 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 25ULL);
x86_l_1783:
	/* 0x1783: jb     186e <filter_8ty_range+0x1a9> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1783, 0x186e, x86_l_186e);
x86_l_1789:
	/* 0x1789: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_178c:
	/* 0x178c: setle  r8b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R8, X86_REG_NONE, X86_WIDTH_8, X86_CC_LE, 0);
x86_l_1790:
	/* 0x1790: cmp    DWORD PTR [rdi+0x24],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1793:
	/* 0x1793: setge  r9b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R9, X86_REG_NONE, X86_WIDTH_8, X86_CC_GE, 0);
x86_l_1797:
	/* 0x1797: and    r9b,r8b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND, 0);
x86_l_179a:
	/* 0x179a: or     dl,r9b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR, 0);
x86_l_179d:
	/* 0x179d: cmp    eax,0x21 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 33ULL);
x86_l_17a0:
	/* 0x17a0: jb     186e <filter_8ty_range+0x1a9> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x17a0, 0x186e, x86_l_186e);
x86_l_17a6:
	/* 0x17a6: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_17a9:
	/* 0x17a9: setle  al */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_CC_LE, 0);
x86_l_17ac:
	/* 0x17ac: cmp    DWORD PTR [rdi+0x2c],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_17af:
	/* 0x17af: setge  sil */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_CC_GE, 0);
x86_l_17b3:
	/* 0x17b3: jmp    1828 <filter_8ty_range+0x163> */
	X86_SIM_X86_SUB_JMP(0x17b3, 0x1828, x86_l_1828);
x86_l_17b5:
	/* 0x17b5: movzx  esi,BYTE PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_17b8:
	/* 0x17b8: cmp    ecx,0x1f */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 31ULL);
x86_l_17bb:
	/* 0x17bb: jne    17cd <filter_8ty_range+0x108> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x17bb, 0x17cd, x86_l_17cd);
x86_l_17bd:
	/* 0x17bd: mov    eax,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_17c2:
	/* 0x17c2: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17c5:
	/* 0x17c5: ja     1830 <filter_8ty_range+0x16b> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x17c5, 0x1830, x86_l_1830);
x86_l_17c7:
	/* 0x17c7: cmp    DWORD PTR [rdi+0x14],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_17ca:
	/* 0x17ca: jb     1830 <filter_8ty_range+0x16b> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x17ca, 0x1830, x86_l_1830);
x86_l_17cc:
	/* 0x17cc: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_6ce);
x86_l_17cd:
	/* 0x17cd: mov    eax,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17d0:
	/* 0x17d0: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17d3:
	/* 0x17d3: setbe  r8b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R8, X86_REG_NONE, X86_WIDTH_8, X86_CC_BE, 0);
x86_l_17d7:
	/* 0x17d7: cmp    DWORD PTR [rdi+0x14],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_17da:
	/* 0x17da: setae  dl */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_CC_AE, 0);
x86_l_17dd:
	/* 0x17dd: and    dl,r8b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_R8, X86_WIDTH_8, X86_ALU_AND, 0);
x86_l_17e0:
	/* 0x17e0: cmp    eax,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_17e3:
	/* 0x17e3: jb     186e <filter_8ty_range+0x1a9> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x17e3, 0x186e, x86_l_186e);
x86_l_17e9:
	/* 0x17e9: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_17ec:
	/* 0x17ec: setbe  r8b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R8, X86_REG_NONE, X86_WIDTH_8, X86_CC_BE, 0);
x86_l_17f0:
	/* 0x17f0: cmp    DWORD PTR [rdi+0x1c],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_17f3:
	/* 0x17f3: setae  r9b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R9, X86_REG_NONE, X86_WIDTH_8, X86_CC_AE, 0);
x86_l_17f7:
	/* 0x17f7: and    r9b,r8b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND, 0);
x86_l_17fa:
	/* 0x17fa: or     dl,r9b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR, 0);
x86_l_17fd:
	/* 0x17fd: cmp    eax,0x19 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 25ULL);
x86_l_1800:
	/* 0x1800: jb     186e <filter_8ty_range+0x1a9> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1800, 0x186e, x86_l_186e);
x86_l_1802:
	/* 0x1802: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1805:
	/* 0x1805: setbe  r8b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R8, X86_REG_NONE, X86_WIDTH_8, X86_CC_BE, 0);
x86_l_1809:
	/* 0x1809: cmp    DWORD PTR [rdi+0x24],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_180c:
	/* 0x180c: setae  r9b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R9, X86_REG_NONE, X86_WIDTH_8, X86_CC_AE, 0);
x86_l_1810:
	/* 0x1810: and    r9b,r8b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND, 0);
x86_l_1813:
	/* 0x1813: or     dl,r9b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR, 0);
x86_l_1816:
	/* 0x1816: cmp    eax,0x21 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 33ULL);
x86_l_1819:
	/* 0x1819: jb     186e <filter_8ty_range+0x1a9> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1819, 0x186e, x86_l_186e);
x86_l_181b:
	/* 0x181b: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_181e:
	/* 0x181e: setbe  al */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_CC_BE, 0);
x86_l_1821:
	/* 0x1821: cmp    DWORD PTR [rdi+0x2c],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1824:
	/* 0x1824: setae  sil */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_CC_AE, 0);
x86_l_1828:
	/* 0x1828: and    sil,al */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_ALU_AND, 0);
x86_l_182b:
	/* 0x182b: or     dl,sil */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RSI, X86_WIDTH_8, X86_ALU_OR, 0);
x86_l_182e:
	/* 0x182e: jmp    186e <filter_8ty_range+0x1a9> */
	X86_SIM_X86_SUB_JMP(0x182e, 0x186e, x86_l_186e);
x86_l_1830:
	/* 0x1830: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1833:
	/* 0x1833: cmp    edx,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_1836:
	/* 0x1836: jb     186c <filter_8ty_range+0x1a7> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1836, 0x186c, x86_l_186c);
x86_l_1838:
	/* 0x1838: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_183b:
	/* 0x183b: ja     1842 <filter_8ty_range+0x17d> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x183b, 0x1842, x86_l_1842);
x86_l_183d:
	/* 0x183d: cmp    DWORD PTR [rdi+0x1c],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1840:
	/* 0x1840: jae    17cc <filter_8ty_range+0x107> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x1840, 0x17cc, x86_l_17cc);
x86_l_1842:
	/* 0x1842: cmp    edx,0x19 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 25ULL);
x86_l_1845:
	/* 0x1845: jb     186c <filter_8ty_range+0x1a7> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1845, 0x186c, x86_l_186c);
x86_l_1847:
	/* 0x1847: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_184a:
	/* 0x184a: ja     1855 <filter_8ty_range+0x190> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x184a, 0x1855, x86_l_1855);
x86_l_184c:
	/* 0x184c: cmp    DWORD PTR [rdi+0x24],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_184f:
	/* 0x184f: jae    17cc <filter_8ty_range+0x107> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x184f, 0x17cc, x86_l_17cc);
x86_l_1855:
	/* 0x1855: cmp    edx,0x21 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 33ULL);
x86_l_1858:
	/* 0x1858: jb     186c <filter_8ty_range+0x1a7> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1858, 0x186c, x86_l_186c);
x86_l_185a:
	/* 0x185a: xor    edx,edx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_185c:
	/* 0x185c: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_185f:
	/* 0x185f: ja     186e <filter_8ty_range+0x1a9> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x185f, 0x186e, x86_l_186e);
x86_l_1861:
	/* 0x1861: cmp    DWORD PTR [rdi+0x2c],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1864:
	/* 0x1864: jae    17cc <filter_8ty_range+0x107> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x1864, 0x17cc, x86_l_17cc);
x86_l_186a:
	/* 0x186a: jmp    186e <filter_8ty_range+0x1a9> */
	X86_SIM_X86_SUB_JMP(0x186a, 0x186e, x86_l_186e);
x86_l_186c:
	/* 0x186c: xor    edx,edx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_186e:
	/* 0x186e: cmp    ecx,0x20 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 32ULL);
x86_l_1871:
	/* 0x1871: sete   al */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_CC_E, 0);
x86_l_1874:
	/* 0x1874: xor    dl,0x1 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_ALU_XOR, 1ULL);
x86_l_1877:
	/* 0x1877: and    dl,al */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RAX, X86_WIDTH_8, X86_ALU_AND, 0);
x86_l_1879:
	/* 0x1879: movzx  eax,dl */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8, 0);
x86_l_187c:
	/* 0x187c: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_6ce);

	/* native subroutine native_link_sub_187d */
x86_l_187d:
	/* 0x187d: push   rbp */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_187e:
	/* 0x187e: push   r15 */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_1880:
	/* 0x1880: push   r14 */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_1882:
	/* 0x1882: push   r13 */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_1884:
	/* 0x1884: push   r12 */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_1886:
	/* 0x1886: push   rbx */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_1887:
	/* 0x1887: push   rax */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_1888:
	/* 0x1888: mov    r15,rsi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R15, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_188b:
	/* 0x188b: mov    r14,rdi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R14, X86_RDI, X86_WIDTH_64, 0, 0);
x86_l_188e:
	/* 0x188e: mov    ebp,edx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RBP, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_1890:
	/* 0x1890: test   ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_1892:
	/* 0x1892: je     1958 <filter_char_substring+0xdb> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1892, 0x1958, x86_l_1958);
x86_l_1898:
	/* 0x1898: test   edx,edx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_189a:
	/* 0x189a: je     19ef <filter_char_substring+0x172> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x189a, 0x19ef, x86_l_19ef);
x86_l_18a0:
	/* 0x18a0: lea    r13,[rsp+0x4] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_18a5:
	/* 0x18a5: xor    ebx,ebx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_18a7:
	/* 0x18a7: xor    r12d,r12d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_18aa:
	/* 0x18aa: mov    eax,DWORD PTR [r14+rbx*4+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 16ULL);
x86_l_18af:
	/* 0x18af: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_18b3:
	/* 0x18b3: mov    rdi,QWORD PTR [rip+0x2173] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)substring_map));
x86_l_18ba:
	/* 0x18ba: mov    rsi,r13 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_18bd:
	/* 0x18bd: call   3a35 <__native_link_local_memset_zero_dynamic+0x17a5> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_18c2:
	/* 0x18c2: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_18c5:
	/* 0x18c5: je     1a6f <filter_char_substring+0x1f2> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x18c5, 0x1a6f, x86_l_1a6f);
x86_l_18cb:
	/* 0x18cb: mov    rdx,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_18ce:
	/* 0x18ce: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_18d0:
	/* 0x18d0: jmp    18dd <filter_char_substring+0x60> */
	X86_SIM_X86_SUB_JMP(0x18d0, 0x18dd, x86_l_18dd);
x86_l_18d2:
	/* 0x18d2: inc    rcx */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_18d5:
	/* 0x18d5: inc    rdx */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_18d8:
	/* 0x18d8: cmp    rcx,rbp */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_18db:
	/* 0x18db: je     1933 <filter_char_substring+0xb6> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x18db, 0x1933, x86_l_1933);
x86_l_18dd:
	/* 0x18dd: xor    esi,esi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_18df:
	/* 0x18df: lea    rdi,[rcx+rsi*1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_18e3:
	/* 0x18e3: cmp    rdi,rbp */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RDI, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_18e6:
	/* 0x18e6: jae    18d2 <filter_char_substring+0x55> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x18e6, 0x18d2, x86_l_18d2);
x86_l_18e8:
	/* 0x18e8: movsx  edi,BYTE PTR [rax+rsi*1] */
	X86_SIM_RUN_OP(X86_OP_MOVSX_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 0ULL);
x86_l_18ec:
	/* 0x18ec: test   edi,edi */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_32, 0, 0);
x86_l_18ee:
	/* 0x18ee: je     192b <filter_char_substring+0xae> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x18ee, 0x192b, x86_l_192b);
x86_l_18f0:
	/* 0x18f0: movsx  r9d,BYTE PTR [rdx+rsi*1] */
	X86_SIM_RUN_OP(X86_OP_MOVSX_LOAD, X86_R9, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 0ULL);
x86_l_18f5:
	/* 0x18f5: lea    r10d,[r9-0x41] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R10, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551551ULL);
x86_l_18f9:
	/* 0x18f9: mov    r8d,r9d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R8, X86_R9, X86_WIDTH_32, 0, 0);
x86_l_18fc:
	/* 0x18fc: or     r8d,0x20 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_ALU_OR, 32ULL);
x86_l_1900:
	/* 0x1900: cmp    r10d,0x1a */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_32, 0, 26ULL);
x86_l_1904:
	/* 0x1904: cmovae r8d,r9d */
	X86_SIM_RUN_OP(X86_OP_CMOV, X86_R8, X86_R9, X86_WIDTH_32, X86_CC_AE, 0);
x86_l_1908:
	/* 0x1908: lea    r10d,[rdi-0x41] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R10, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551551ULL);
x86_l_190c:
	/* 0x190c: mov    r9d,edi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R9, X86_RDI, X86_WIDTH_32, 0, 0);
x86_l_190f:
	/* 0x190f: or     r9d,0x20 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_32, X86_ALU_OR, 32ULL);
x86_l_1913:
	/* 0x1913: cmp    r10d,0x1a */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_32, 0, 26ULL);
x86_l_1917:
	/* 0x1917: cmovae r9d,edi */
	X86_SIM_RUN_OP(X86_OP_CMOV, X86_R9, X86_RDI, X86_WIDTH_32, X86_CC_AE, 0);
x86_l_191b:
	/* 0x191b: cmp    rsi,0x62 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, 0, 98ULL);
x86_l_191f:
	/* 0x191f: ja     18d2 <filter_char_substring+0x55> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x191f, 0x18d2, x86_l_18d2);
x86_l_1921:
	/* 0x1921: inc    rsi */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1924:
	/* 0x1924: cmp    r8d,r9d */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_R8, X86_R9, X86_WIDTH_32, 0, 0);
x86_l_1927:
	/* 0x1927: je     18df <filter_char_substring+0x62> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1927, 0x18df, x86_l_18df);
x86_l_1929:
	/* 0x1929: jmp    18d2 <filter_char_substring+0x55> */
	X86_SIM_X86_SUB_JMP(0x1929, 0x18d2, x86_l_18d2);
x86_l_192b:
	/* 0x192b: test   ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_192d:
	/* 0x192d: jns    1a80 <filter_char_substring+0x203> */
	X86_SIM_X86_SUB_JCC(X86_CC_NS, 0x192d, 0x1a80, x86_l_1a80);
x86_l_1933:
	/* 0x1933: lea    eax,[r12+0xc] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1938:
	/* 0x1938: cmp    eax,DWORD PTR [r14+0x8] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_193c:
	/* 0x193c: jae    1a6f <filter_char_substring+0x1f2> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x193c, 0x1a6f, x86_l_1a6f);
x86_l_1942:
	/* 0x1942: add    r12d,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1946:
	/* 0x1946: inc    rbx */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1949:
	/* 0x1949: cmp    rbx,0x64 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 100ULL);
x86_l_194d:
	/* 0x194d: jne    18aa <filter_char_substring+0x2d> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x194d, 0x18aa, x86_l_18aa);
x86_l_1953:
	/* 0x1953: jmp    1a6f <filter_char_substring+0x1f2> */
	X86_SIM_X86_SUB_JMP(0x1953, 0x1a6f, x86_l_1a6f);
x86_l_1958:
	/* 0x1958: test   edx,edx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_195a:
	/* 0x195a: je     1a30 <filter_char_substring+0x1b3> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x195a, 0x1a30, x86_l_1a30);
x86_l_1960:
	/* 0x1960: lea    r13,[rsp+0x4] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1965:
	/* 0x1965: xor    ebx,ebx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1967:
	/* 0x1967: xor    r12d,r12d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_196a:
	/* 0x196a: mov    eax,DWORD PTR [r14+rbx*4+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 16ULL);
x86_l_196f:
	/* 0x196f: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1973:
	/* 0x1973: mov    rdi,QWORD PTR [rip+0x2183] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)substring_map));
x86_l_197a:
	/* 0x197a: mov    rsi,r13 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_197d:
	/* 0x197d: call   3b05 <__native_link_local_memset_zero_dynamic+0x1875> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_1982:
	/* 0x1982: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_1985:
	/* 0x1985: je     1a6f <filter_char_substring+0x1f2> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1985, 0x1a6f, x86_l_1a6f);
x86_l_198b:
	/* 0x198b: mov    rdx,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_198e:
	/* 0x198e: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1990:
	/* 0x1990: jmp    199d <filter_char_substring+0x120> */
	X86_SIM_X86_SUB_JMP(0x1990, 0x199d, x86_l_199d);
x86_l_1992:
	/* 0x1992: inc    rcx */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1995:
	/* 0x1995: inc    rdx */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1998:
	/* 0x1998: cmp    rcx,rbp */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_199b:
	/* 0x199b: je     19ce <filter_char_substring+0x151> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x199b, 0x19ce, x86_l_19ce);
x86_l_199d:
	/* 0x199d: xor    esi,esi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_199f:
	/* 0x199f: lea    rdi,[rcx+rsi*1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_19a3:
	/* 0x19a3: cmp    rdi,rbp */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RDI, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_19a6:
	/* 0x19a6: jae    1992 <filter_char_substring+0x115> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x19a6, 0x1992, x86_l_1992);
x86_l_19a8:
	/* 0x19a8: movzx  edi,BYTE PTR [rax+rsi*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 0ULL);
x86_l_19ac:
	/* 0x19ac: test   dil,dil */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_8, 0, 0);
x86_l_19af:
	/* 0x19af: je     19c6 <filter_char_substring+0x149> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x19af, 0x19c6, x86_l_19c6);
x86_l_19b1:
	/* 0x19b1: cmp    rsi,0x62 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, 0, 98ULL);
x86_l_19b5:
	/* 0x19b5: ja     1992 <filter_char_substring+0x115> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x19b5, 0x1992, x86_l_1992);
x86_l_19b7:
	/* 0x19b7: lea    r8,[rsi+0x1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_19bb:
	/* 0x19bb: cmp    BYTE PTR [rdx+rsi*1],dil */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDX, X86_RDI, X86_WIDTH_8, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_19bf:
	/* 0x19bf: mov    rsi,r8 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_R8, X86_WIDTH_64, 0, 0);
x86_l_19c2:
	/* 0x19c2: je     199f <filter_char_substring+0x122> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x19c2, 0x199f, x86_l_199f);
x86_l_19c4:
	/* 0x19c4: jmp    1992 <filter_char_substring+0x115> */
	X86_SIM_X86_SUB_JMP(0x19c4, 0x1992, x86_l_1992);
x86_l_19c6:
	/* 0x19c6: test   ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_19c8:
	/* 0x19c8: jns    1a80 <filter_char_substring+0x203> */
	X86_SIM_X86_SUB_JCC(X86_CC_NS, 0x19c8, 0x1a80, x86_l_1a80);
x86_l_19ce:
	/* 0x19ce: lea    eax,[r12+0xc] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_19d3:
	/* 0x19d3: cmp    eax,DWORD PTR [r14+0x8] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_19d7:
	/* 0x19d7: jae    1a6f <filter_char_substring+0x1f2> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x19d7, 0x1a6f, x86_l_1a6f);
x86_l_19dd:
	/* 0x19dd: add    r12d,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_19e1:
	/* 0x19e1: inc    rbx */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_19e4:
	/* 0x19e4: cmp    rbx,0x64 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 100ULL);
x86_l_19e8:
	/* 0x19e8: jne    196a <filter_char_substring+0xed> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x19e8, 0x196a, x86_l_196a);
x86_l_19ea:
	/* 0x19ea: jmp    1a6f <filter_char_substring+0x1f2> */
	X86_SIM_X86_SUB_JMP(0x19ea, 0x1a6f, x86_l_1a6f);
x86_l_19ef:
	/* 0x19ef: mov    ebx,0x10 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 16ULL);
x86_l_19f4:
	/* 0x19f4: mov    r15,QWORD PTR [rip+0x219b] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_R15, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)substring_map));
x86_l_19fb:
	/* 0x19fb: lea    r12,[rsp+0x4] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1a00:
	/* 0x1a00: mov    eax,DWORD PTR [r14+rbx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_1a04:
	/* 0x1a04: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1a08:
	/* 0x1a08: mov    rdi,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_1a0b:
	/* 0x1a0b: mov    rsi,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_1a0e:
	/* 0x1a0e: call   3bb0 <__native_link_local_memset_zero_dynamic+0x1920> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_1a13:
	/* 0x1a13: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_1a16:
	/* 0x1a16: je     1a6f <filter_char_substring+0x1f2> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1a16, 0x1a6f, x86_l_1a6f);
x86_l_1a18:
	/* 0x1a18: add    rbx,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1a1c:
	/* 0x1a1c: lea    eax,[rbx-0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551608ULL);
x86_l_1a1f:
	/* 0x1a1f: cmp    eax,DWORD PTR [r14+0x8] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_1a23:
	/* 0x1a23: jae    1a6f <filter_char_substring+0x1f2> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x1a23, 0x1a6f, x86_l_1a6f);
x86_l_1a25:
	/* 0x1a25: cmp    rbx,0x1a0 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 416ULL);
x86_l_1a2c:
	/* 0x1a2c: jne    1a00 <filter_char_substring+0x183> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x1a2c, 0x1a00, x86_l_1a00);
x86_l_1a2e:
	/* 0x1a2e: jmp    1a6f <filter_char_substring+0x1f2> */
	X86_SIM_X86_SUB_JMP(0x1a2e, 0x1a6f, x86_l_1a6f);
x86_l_1a30:
	/* 0x1a30: mov    ebx,0x10 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 16ULL);
x86_l_1a35:
	/* 0x1a35: mov    r15,QWORD PTR [rip+0x219d] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_R15, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)substring_map));
x86_l_1a3c:
	/* 0x1a3c: lea    r12,[rsp+0x4] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1a41:
	/* 0x1a41: mov    eax,DWORD PTR [r14+rbx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_1a45:
	/* 0x1a45: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1a49:
	/* 0x1a49: mov    rdi,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_1a4c:
	/* 0x1a4c: mov    rsi,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_1a4f:
	/* 0x1a4f: call   3c00 <__native_link_local_memset_zero_dynamic+0x1970> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_1a54:
	/* 0x1a54: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_1a57:
	/* 0x1a57: je     1a6f <filter_char_substring+0x1f2> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1a57, 0x1a6f, x86_l_1a6f);
x86_l_1a59:
	/* 0x1a59: add    rbx,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1a5d:
	/* 0x1a5d: lea    eax,[rbx-0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551608ULL);
x86_l_1a60:
	/* 0x1a60: cmp    eax,DWORD PTR [r14+0x8] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_1a64:
	/* 0x1a64: jae    1a6f <filter_char_substring+0x1f2> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x1a64, 0x1a6f, x86_l_1a6f);
x86_l_1a66:
	/* 0x1a66: cmp    rbx,0x1a0 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 416ULL);
x86_l_1a6d:
	/* 0x1a6d: jne    1a41 <filter_char_substring+0x1c4> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x1a6d, 0x1a41, x86_l_1a41);
x86_l_1a6f:
	/* 0x1a6f: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1a71:
	/* 0x1a71: add    rsp,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1a75:
	/* 0x1a75: pop    rbx */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1a76:
	/* 0x1a76: pop    r12 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R12, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1a78:
	/* 0x1a78: pop    r13 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R13, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1a7a:
	/* 0x1a7a: pop    r14 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R14, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1a7c:
	/* 0x1a7c: pop    r15 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R15, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1a7e:
	/* 0x1a7e: pop    rbp */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBP, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1a7f:
	/* 0x1a7f: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_1a7f);
x86_l_1a80:
	/* 0x1a80: mov    eax,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_1a85:
	/* 0x1a85: jmp    1a71 <filter_char_substring+0x1f4> */
	X86_SIM_X86_SUB_JMP(0x1a85, 0x1a71, x86_l_1a71);

	/* native subroutine native_link_sub_1a87 */
x86_l_1a87:
	/* 0x1a87: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1a8a:
	/* 0x1a8a: lea    edx,[rcx-0x1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_1a8d:
	/* 0x1a8d: cmp    edx,0x24 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 36ULL);
x86_l_1a90:
	/* 0x1a90: ja     1c95 <filter_64ty_selector_val+0x20e> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x1a90, 0x1c95, x86_l_1c95);
x86_l_1a96:
	/* 0x1a96: mov    eax,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_1a9b:
	/* Capture image-bound code identity before scheduled instructions. */
	switch (X86_SIM_L_READ_REG(X86_RDX) << 2) {
	case 0ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1b02ULL); break;
	case 4ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1bb4ULL); break;
	case 8ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1aacULL); break;
	case 12ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1aacULL); break;
	case 16ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1c95ULL); break;
	case 20ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1aabULL); break;
	case 24ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1c95ULL); break;
	case 28ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1c95ULL); break;
	case 32ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1c95ULL); break;
	case 36ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1c95ULL); break;
	case 40ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1c95ULL); break;
	case 44ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1b66ULL); break;
	case 48ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1c95ULL); break;
	case 52ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1c95ULL); break;
	case 56ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1c95ULL); break;
	case 60ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1c95ULL); break;
	case 64ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1c95ULL); break;
	case 68ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1c95ULL); break;
	case 72ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1c95ULL); break;
	case 76ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1c95ULL); break;
	case 80ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1c95ULL); break;
	case 84ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1c95ULL); break;
	case 88ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1c95ULL); break;
	case 92ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1c95ULL); break;
	case 96ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1c95ULL); break;
	case 100ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1aabULL); break;
	case 104ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1aabULL); break;
	case 108ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1c95ULL); break;
	case 112ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1c95ULL); break;
	case 116ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1c95ULL); break;
	case 120ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1c95ULL); break;
	case 124ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1c95ULL); break;
	case 128ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1c95ULL); break;
	case 132ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1c95ULL); break;
	case 136ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1c95ULL); break;
	case 140ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1c95ULL); break;
	case 144ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1aabULL); break;
	default: __x86_sim_unresolved_indirect_target();
	}
x86_l_1aa9:
	/* 0x1aa9: jmp    rdx */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RDX);
		switch (X86_SIM_L_REG_TAG(X86_RDX)) {
		case X86_SIM_TAG_CODE:
			switch (__x86_target) {
			case 0x1aabULL: goto x86_l_1aab;
			case 0x1aacULL: goto x86_l_1aac;
			case 0x1b02ULL: goto x86_l_1b02;
			case 0x1b66ULL: goto x86_l_1b66;
			case 0x1bb4ULL: goto x86_l_1bb4;
			case 0x1c95ULL: goto x86_l_1c95;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_1aab:
	/* 0x1aab: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_601);
x86_l_1aac:
	/* 0x1aac: mov    rdx,QWORD PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1aaf:
	/* 0x1aaf: cmp    rdx,QWORD PTR [rdi+0x10] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_1ab3:
	/* 0x1ab3: jne    1abe <filter_64ty_selector_val+0x37> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x1ab3, 0x1abe, x86_l_1abe);
x86_l_1ab5:
	/* 0x1ab5: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1ab7:
	/* 0x1ab7: cmp    ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 3ULL);
x86_l_1aba:
	/* 0x1aba: sete   al */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_CC_E, 0);
x86_l_1abd:
	/* 0x1abd: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_601);
x86_l_1abe:
	/* 0x1abe: mov    esi,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ac1:
	/* 0x1ac1: cmp    esi,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_1ac4:
	/* 0x1ac4: jb     1ae2 <filter_64ty_selector_val+0x5b> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1ac4, 0x1ae2, x86_l_1ae2);
x86_l_1ac6:
	/* 0x1ac6: cmp    rdx,QWORD PTR [rdi+0x18] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_1aca:
	/* 0x1aca: je     1ab5 <filter_64ty_selector_val+0x2e> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1aca, 0x1ab5, x86_l_1ab5);
x86_l_1acc:
	/* 0x1acc: cmp    esi,0x19 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 25ULL);
x86_l_1acf:
	/* 0x1acf: jb     1ae2 <filter_64ty_selector_val+0x5b> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1acf, 0x1ae2, x86_l_1ae2);
x86_l_1ad1:
	/* 0x1ad1: cmp    rdx,QWORD PTR [rdi+0x20] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_1ad5:
	/* 0x1ad5: je     1ab5 <filter_64ty_selector_val+0x2e> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1ad5, 0x1ab5, x86_l_1ab5);
x86_l_1ad7:
	/* 0x1ad7: cmp    esi,0x21 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 33ULL);
x86_l_1ada:
	/* 0x1ada: jb     1ae2 <filter_64ty_selector_val+0x5b> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1ada, 0x1ae2, x86_l_1ae2);
x86_l_1adc:
	/* 0x1adc: cmp    rdx,QWORD PTR [rdi+0x28] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_1ae0:
	/* 0x1ae0: je     1ab5 <filter_64ty_selector_val+0x2e> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1ae0, 0x1ab5, x86_l_1ab5);
x86_l_1ae2:
	/* 0x1ae2: cmp    ecx,0x25 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 37ULL);
x86_l_1ae5:
	/* 0x1ae5: ja     1c95 <filter_64ty_selector_val+0x20e> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x1ae5, 0x1c95, x86_l_1c95);
x86_l_1aeb:
	/* 0x1aeb: mov    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_1aed:
	/* 0x1aed: movabs rdx,0x200c000050 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, 0, 137640280144ULL);
x86_l_1af7:
	/* 0x1af7: bt     rdx,rcx */
	X86_SIM_RUN_OP(X86_OP_BT, X86_RDX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_1afb:
	/* 0x1afb: jb     1aab <filter_64ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1afb, 0x1aab, x86_l_1aab);
x86_l_1afd:
	/* 0x1afd: jmp    1c95 <filter_64ty_selector_val+0x20e> */
	X86_SIM_X86_SUB_JMP(0x1afd, 0x1c95, x86_l_1c95);
x86_l_1b02:
	/* 0x1b02: mov    ecx,DWORD PTR [rdi+0xc] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1b05:
	/* 0x1b05: cmp    ecx,0xc */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 12ULL);
x86_l_1b08:
	/* 0x1b08: ja     1c19 <filter_64ty_selector_val+0x192> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x1b08, 0x1c19, x86_l_1c19);
x86_l_1b0e:
	/* 0x1b0e: mov    edx,0x1402 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 5122ULL);
x86_l_1b13:
	/* 0x1b13: bt     edx,ecx */
	X86_SIM_RUN_OP(X86_OP_BT, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_1b16:
	/* 0x1b16: jae    1c19 <filter_64ty_selector_val+0x192> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x1b16, 0x1c19, x86_l_1c19);
x86_l_1b1c:
	/* 0x1b1c: mov    rcx,QWORD PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b1f:
	/* 0x1b1f: cmp    rcx,QWORD PTR [rdi+0x10] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_1b23:
	/* 0x1b23: jg     1aab <filter_64ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x1b23, 0x1aab, x86_l_1aab);
x86_l_1b25:
	/* 0x1b25: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b28:
	/* 0x1b28: cmp    edx,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_1b2b:
	/* 0x1b2b: jb     1c95 <filter_64ty_selector_val+0x20e> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1b2b, 0x1c95, x86_l_1c95);
x86_l_1b31:
	/* 0x1b31: cmp    rcx,QWORD PTR [rdi+0x18] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_1b35:
	/* 0x1b35: jg     1aab <filter_64ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x1b35, 0x1aab, x86_l_1aab);
x86_l_1b3b:
	/* 0x1b3b: cmp    edx,0x19 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 25ULL);
x86_l_1b3e:
	/* 0x1b3e: jb     1c95 <filter_64ty_selector_val+0x20e> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1b3e, 0x1c95, x86_l_1c95);
x86_l_1b44:
	/* 0x1b44: cmp    rcx,QWORD PTR [rdi+0x20] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_1b48:
	/* 0x1b48: jg     1aab <filter_64ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x1b48, 0x1aab, x86_l_1aab);
x86_l_1b4e:
	/* 0x1b4e: cmp    edx,0x21 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 33ULL);
x86_l_1b51:
	/* 0x1b51: jb     1c95 <filter_64ty_selector_val+0x20e> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1b51, 0x1c95, x86_l_1c95);
x86_l_1b57:
	/* 0x1b57: cmp    rcx,QWORD PTR [rdi+0x28] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_1b5b:
	/* 0x1b5b: jg     1aab <filter_64ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x1b5b, 0x1aab, x86_l_1aab);
x86_l_1b61:
	/* 0x1b61: jmp    1c95 <filter_64ty_selector_val+0x20e> */
	X86_SIM_X86_SUB_JMP(0x1b61, 0x1c95, x86_l_1c95);
x86_l_1b66:
	/* 0x1b66: mov    rcx,QWORD PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b69:
	/* 0x1b69: test   QWORD PTR [rdi+0x10],rcx */
	X86_SIM_RUN_OP(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1b6d:
	/* 0x1b6d: jne    1aab <filter_64ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x1b6d, 0x1aab, x86_l_1aab);
x86_l_1b73:
	/* 0x1b73: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b76:
	/* 0x1b76: cmp    edx,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_1b79:
	/* 0x1b79: jb     1c95 <filter_64ty_selector_val+0x20e> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1b79, 0x1c95, x86_l_1c95);
x86_l_1b7f:
	/* 0x1b7f: test   QWORD PTR [rdi+0x18],rcx */
	X86_SIM_RUN_OP(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1b83:
	/* 0x1b83: jne    1aab <filter_64ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x1b83, 0x1aab, x86_l_1aab);
x86_l_1b89:
	/* 0x1b89: cmp    edx,0x19 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 25ULL);
x86_l_1b8c:
	/* 0x1b8c: jb     1c95 <filter_64ty_selector_val+0x20e> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1b8c, 0x1c95, x86_l_1c95);
x86_l_1b92:
	/* 0x1b92: test   QWORD PTR [rdi+0x20],rcx */
	X86_SIM_RUN_OP(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1b96:
	/* 0x1b96: jne    1aab <filter_64ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x1b96, 0x1aab, x86_l_1aab);
x86_l_1b9c:
	/* 0x1b9c: cmp    edx,0x21 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 33ULL);
x86_l_1b9f:
	/* 0x1b9f: jb     1c95 <filter_64ty_selector_val+0x20e> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1b9f, 0x1c95, x86_l_1c95);
x86_l_1ba5:
	/* 0x1ba5: test   QWORD PTR [rdi+0x28],rcx */
	X86_SIM_RUN_OP(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1ba9:
	/* 0x1ba9: jne    1aab <filter_64ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x1ba9, 0x1aab, x86_l_1aab);
x86_l_1baf:
	/* 0x1baf: jmp    1c95 <filter_64ty_selector_val+0x20e> */
	X86_SIM_X86_SUB_JMP(0x1baf, 0x1c95, x86_l_1c95);
x86_l_1bb4:
	/* 0x1bb4: mov    ecx,DWORD PTR [rdi+0xc] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1bb7:
	/* 0x1bb7: cmp    ecx,0xc */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 12ULL);
x86_l_1bba:
	/* 0x1bba: ja     1c58 <filter_64ty_selector_val+0x1d1> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x1bba, 0x1c58, x86_l_1c58);
x86_l_1bc0:
	/* 0x1bc0: mov    edx,0x1402 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 5122ULL);
x86_l_1bc5:
	/* 0x1bc5: bt     edx,ecx */
	X86_SIM_RUN_OP(X86_OP_BT, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_1bc8:
	/* 0x1bc8: jae    1c58 <filter_64ty_selector_val+0x1d1> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x1bc8, 0x1c58, x86_l_1c58);
x86_l_1bce:
	/* 0x1bce: mov    rcx,QWORD PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1bd1:
	/* 0x1bd1: cmp    rcx,QWORD PTR [rdi+0x10] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_1bd5:
	/* 0x1bd5: jl     1aab <filter_64ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_L, 0x1bd5, 0x1aab, x86_l_1aab);
x86_l_1bdb:
	/* 0x1bdb: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1bde:
	/* 0x1bde: cmp    edx,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_1be1:
	/* 0x1be1: jb     1c95 <filter_64ty_selector_val+0x20e> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1be1, 0x1c95, x86_l_1c95);
x86_l_1be7:
	/* 0x1be7: cmp    rcx,QWORD PTR [rdi+0x18] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_1beb:
	/* 0x1beb: jl     1aab <filter_64ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_L, 0x1beb, 0x1aab, x86_l_1aab);
x86_l_1bf1:
	/* 0x1bf1: cmp    edx,0x19 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 25ULL);
x86_l_1bf4:
	/* 0x1bf4: jb     1c95 <filter_64ty_selector_val+0x20e> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1bf4, 0x1c95, x86_l_1c95);
x86_l_1bfa:
	/* 0x1bfa: cmp    rcx,QWORD PTR [rdi+0x20] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_1bfe:
	/* 0x1bfe: jl     1aab <filter_64ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_L, 0x1bfe, 0x1aab, x86_l_1aab);
x86_l_1c04:
	/* 0x1c04: cmp    edx,0x21 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 33ULL);
x86_l_1c07:
	/* 0x1c07: jb     1c95 <filter_64ty_selector_val+0x20e> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1c07, 0x1c95, x86_l_1c95);
x86_l_1c0d:
	/* 0x1c0d: cmp    rcx,QWORD PTR [rdi+0x28] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_1c11:
	/* 0x1c11: jl     1aab <filter_64ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_L, 0x1c11, 0x1aab, x86_l_1aab);
x86_l_1c17:
	/* 0x1c17: jmp    1c95 <filter_64ty_selector_val+0x20e> */
	X86_SIM_X86_SUB_JMP(0x1c17, 0x1c95, x86_l_1c95);
x86_l_1c19:
	/* 0x1c19: mov    rcx,QWORD PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c1c:
	/* 0x1c1c: cmp    rcx,QWORD PTR [rdi+0x10] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_1c20:
	/* 0x1c20: ja     1aab <filter_64ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x1c20, 0x1aab, x86_l_1aab);
x86_l_1c26:
	/* 0x1c26: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c29:
	/* 0x1c29: cmp    edx,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_1c2c:
	/* 0x1c2c: jb     1c95 <filter_64ty_selector_val+0x20e> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1c2c, 0x1c95, x86_l_1c95);
x86_l_1c2e:
	/* 0x1c2e: cmp    rcx,QWORD PTR [rdi+0x18] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_1c32:
	/* 0x1c32: ja     1aab <filter_64ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x1c32, 0x1aab, x86_l_1aab);
x86_l_1c38:
	/* 0x1c38: cmp    edx,0x19 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 25ULL);
x86_l_1c3b:
	/* 0x1c3b: jb     1c95 <filter_64ty_selector_val+0x20e> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1c3b, 0x1c95, x86_l_1c95);
x86_l_1c3d:
	/* 0x1c3d: cmp    rcx,QWORD PTR [rdi+0x20] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_1c41:
	/* 0x1c41: ja     1aab <filter_64ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x1c41, 0x1aab, x86_l_1aab);
x86_l_1c47:
	/* 0x1c47: cmp    edx,0x21 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 33ULL);
x86_l_1c4a:
	/* 0x1c4a: jb     1c95 <filter_64ty_selector_val+0x20e> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1c4a, 0x1c95, x86_l_1c95);
x86_l_1c4c:
	/* 0x1c4c: cmp    rcx,QWORD PTR [rdi+0x28] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_1c50:
	/* 0x1c50: ja     1aab <filter_64ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x1c50, 0x1aab, x86_l_1aab);
x86_l_1c56:
	/* 0x1c56: jmp    1c95 <filter_64ty_selector_val+0x20e> */
	X86_SIM_X86_SUB_JMP(0x1c56, 0x1c95, x86_l_1c95);
x86_l_1c58:
	/* 0x1c58: mov    rcx,QWORD PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c5b:
	/* 0x1c5b: cmp    rcx,QWORD PTR [rdi+0x10] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_1c5f:
	/* 0x1c5f: jb     1aab <filter_64ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1c5f, 0x1aab, x86_l_1aab);
x86_l_1c65:
	/* 0x1c65: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c68:
	/* 0x1c68: cmp    edx,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_1c6b:
	/* 0x1c6b: jb     1c95 <filter_64ty_selector_val+0x20e> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1c6b, 0x1c95, x86_l_1c95);
x86_l_1c6d:
	/* 0x1c6d: cmp    rcx,QWORD PTR [rdi+0x18] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_1c71:
	/* 0x1c71: jb     1aab <filter_64ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1c71, 0x1aab, x86_l_1aab);
x86_l_1c77:
	/* 0x1c77: cmp    edx,0x19 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 25ULL);
x86_l_1c7a:
	/* 0x1c7a: jb     1c95 <filter_64ty_selector_val+0x20e> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1c7a, 0x1c95, x86_l_1c95);
x86_l_1c7c:
	/* 0x1c7c: cmp    rcx,QWORD PTR [rdi+0x20] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_1c80:
	/* 0x1c80: jb     1aab <filter_64ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1c80, 0x1aab, x86_l_1aab);
x86_l_1c86:
	/* 0x1c86: cmp    edx,0x21 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 33ULL);
x86_l_1c89:
	/* 0x1c89: jb     1c95 <filter_64ty_selector_val+0x20e> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1c89, 0x1c95, x86_l_1c95);
x86_l_1c8b:
	/* 0x1c8b: cmp    rcx,QWORD PTR [rdi+0x28] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_1c8f:
	/* 0x1c8f: jb     1aab <filter_64ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1c8f, 0x1aab, x86_l_1aab);
x86_l_1c95:
	/* 0x1c95: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1c97:
	/* 0x1c97: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_601);

	/* native subroutine native_link_sub_1c98 */
x86_l_1c98:
	/* 0x1c98: push   r14 */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_1c9a:
	/* 0x1c9a: push   rbx */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_1c9b:
	/* 0x1c9b: sub    rsp,0x18 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SUB, 24ULL);
x86_l_1c9f:
	/* 0x1c9f: mov    r14,rsi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R14, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_1ca2:
	/* 0x1ca2: mov    rbx,rdi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RBX, X86_RDI, X86_WIDTH_64, 0, 0);
x86_l_1ca5:
	/* 0x1ca5: movzx  eax,BYTE PTR [rdi+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_1ca9:
	/* 0x1ca9: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1cad:
	/* 0x1cad: mov    rdi,QWORD PTR [rip+0x660] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)argfilter_maps));
x86_l_1cb4:
	/* 0x1cb4: lea    rsi,[rsp+0xc] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1cb9:
	/* 0x1cb9: call   231e <__native_link_local_memset_zero_dynamic+0x8e> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_1cbe:
	/* 0x1cbe: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_1cc1:
	/* 0x1cc1: je     1ced <filter_64ty_map+0x55> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1cc1, 0x1ced, x86_l_1ced);
x86_l_1cc3:
	/* 0x1cc3: mov    rcx,QWORD PTR [r14] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1cc6:
	/* 0x1cc6: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ccb:
	/* 0x1ccb: lea    rsi,[rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1cd0:
	/* 0x1cd0: mov    rdi,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_1cd3:
	/* 0x1cd3: call   2338 <__native_link_local_memset_zero_dynamic+0xa8> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_1cd8:
	/* 0x1cd8: mov    ecx,DWORD PTR [rbx+0x4] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1cdb:
	/* 0x1cdb: cmp    ecx,0xb */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 11ULL);
x86_l_1cde:
	/* 0x1cde: je     1cf7 <filter_64ty_map+0x5f> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1cde, 0x1cf7, x86_l_1cf7);
x86_l_1ce0:
	/* 0x1ce0: cmp    ecx,0xa */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 10ULL);
x86_l_1ce3:
	/* 0x1ce3: jne    1cff <filter_64ty_map+0x67> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x1ce3, 0x1cff, x86_l_1cff);
x86_l_1ce5:
	/* 0x1ce5: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_1ce8:
	/* 0x1ce8: setne  al */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_CC_NE, 0);
x86_l_1ceb:
	/* 0x1ceb: jmp    1d01 <filter_64ty_map+0x69> */
	X86_SIM_X86_SUB_JMP(0x1ceb, 0x1d01, x86_l_1d01);
x86_l_1ced:
	/* 0x1ced: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1cef:
	/* 0x1cef: add    rsp,0x18 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1cf3:
	/* 0x1cf3: pop    rbx */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1cf4:
	/* 0x1cf4: pop    r14 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R14, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1cf6:
	/* 0x1cf6: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_601);
x86_l_1cf7:
	/* 0x1cf7: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_1cfa:
	/* 0x1cfa: sete   al */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_CC_E, 0);
x86_l_1cfd:
	/* 0x1cfd: jmp    1d01 <filter_64ty_map+0x69> */
	X86_SIM_X86_SUB_JMP(0x1cfd, 0x1d01, x86_l_1d01);
x86_l_1cff:
	/* 0x1cff: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1d01:
	/* 0x1d01: movzx  eax,al */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8, 0);
x86_l_1d04:
	/* 0x1d04: add    rsp,0x18 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1d08:
	/* 0x1d08: pop    rbx */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1d09:
	/* 0x1d09: pop    r14 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R14, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1d0b:
	/* 0x1d0b: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_601);

	/* native subroutine native_link_sub_1d0c */
x86_l_1d0c:
	/* 0x1d0c: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1d0f:
	/* 0x1d0f: mov    eax,DWORD PTR [rdi+0xc] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1d12:
	/* 0x1d12: cmp    eax,0xc */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 12ULL);
x86_l_1d15:
	/* 0x1d15: ja     1e0f <filter_64ty_range+0x103> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x1d15, 0x1e0f, x86_l_1e0f);
x86_l_1d1b:
	/* 0x1d1b: mov    edx,0x1402 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 5122ULL);
x86_l_1d20:
	/* 0x1d20: bt     edx,eax */
	X86_SIM_RUN_OP(X86_OP_BT, X86_RDX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_1d23:
	/* 0x1d23: jae    1e0f <filter_64ty_range+0x103> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x1d23, 0x1e0f, x86_l_1e0f);
x86_l_1d29:
	/* 0x1d29: mov    rsi,QWORD PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d2c:
	/* 0x1d2c: cmp    ecx,0x1f */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 31ULL);
x86_l_1d2f:
	/* 0x1d2f: jne    1d9f <filter_64ty_range+0x93> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x1d2f, 0x1d9f, x86_l_1d9f);
x86_l_1d31:
	/* 0x1d31: mov    eax,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_1d36:
	/* 0x1d36: cmp    QWORD PTR [rdi+0x10],rsi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d3a:
	/* 0x1d3a: jg     1d46 <filter_64ty_range+0x3a> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x1d3a, 0x1d46, x86_l_1d46);
x86_l_1d3c:
	/* 0x1d3c: cmp    rsi,QWORD PTR [rdi+0x18] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_1d40:
	/* 0x1d40: jle    1e28 <filter_64ty_range+0x11c> */
	X86_SIM_X86_SUB_JCC(X86_CC_LE, 0x1d40, 0x1e28, x86_l_1e28);
x86_l_1d46:
	/* 0x1d46: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d49:
	/* 0x1d49: cmp    edx,0x19 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 25ULL);
x86_l_1d4c:
	/* 0x1d4c: jb     1ed6 <filter_64ty_range+0x1ca> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1d4c, 0x1ed6, x86_l_1ed6);
x86_l_1d52:
	/* 0x1d52: cmp    QWORD PTR [rdi+0x20],rsi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d56:
	/* 0x1d56: jg     1d62 <filter_64ty_range+0x56> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x1d56, 0x1d62, x86_l_1d62);
x86_l_1d58:
	/* 0x1d58: cmp    rsi,QWORD PTR [rdi+0x28] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_1d5c:
	/* 0x1d5c: jle    1e28 <filter_64ty_range+0x11c> */
	X86_SIM_X86_SUB_JCC(X86_CC_LE, 0x1d5c, 0x1e28, x86_l_1e28);
x86_l_1d62:
	/* 0x1d62: cmp    edx,0x29 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 41ULL);
x86_l_1d65:
	/* 0x1d65: jb     1ed6 <filter_64ty_range+0x1ca> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1d65, 0x1ed6, x86_l_1ed6);
x86_l_1d6b:
	/* 0x1d6b: cmp    QWORD PTR [rdi+0x30],rsi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1d6f:
	/* 0x1d6f: jg     1d7b <filter_64ty_range+0x6f> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x1d6f, 0x1d7b, x86_l_1d7b);
x86_l_1d71:
	/* 0x1d71: cmp    rsi,QWORD PTR [rdi+0x38] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_1d75:
	/* 0x1d75: jle    1e28 <filter_64ty_range+0x11c> */
	X86_SIM_X86_SUB_JCC(X86_CC_LE, 0x1d75, 0x1e28, x86_l_1e28);
x86_l_1d7b:
	/* 0x1d7b: cmp    edx,0x39 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 57ULL);
x86_l_1d7e:
	/* 0x1d7e: jb     1ed6 <filter_64ty_range+0x1ca> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1d7e, 0x1ed6, x86_l_1ed6);
x86_l_1d84:
	/* 0x1d84: xor    edx,edx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1d86:
	/* 0x1d86: cmp    QWORD PTR [rdi+0x40],rsi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1d8a:
	/* 0x1d8a: jg     1ed8 <filter_64ty_range+0x1cc> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x1d8a, 0x1ed8, x86_l_1ed8);
x86_l_1d90:
	/* 0x1d90: cmp    rsi,QWORD PTR [rdi+0x48] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 72ULL);
x86_l_1d94:
	/* 0x1d94: jle    1e28 <filter_64ty_range+0x11c> */
	X86_SIM_X86_SUB_JCC(X86_CC_LE, 0x1d94, 0x1e28, x86_l_1e28);
x86_l_1d9a:
	/* 0x1d9a: jmp    1ed8 <filter_64ty_range+0x1cc> */
	X86_SIM_X86_SUB_JMP(0x1d9a, 0x1ed8, x86_l_1ed8);
x86_l_1d9f:
	/* 0x1d9f: mov    eax,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1da2:
	/* 0x1da2: cmp    QWORD PTR [rdi+0x10],rsi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1da6:
	/* 0x1da6: setle  r8b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R8, X86_REG_NONE, X86_WIDTH_8, X86_CC_LE, 0);
x86_l_1daa:
	/* 0x1daa: cmp    rsi,QWORD PTR [rdi+0x18] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_1dae:
	/* 0x1dae: setle  dl */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_CC_LE, 0);
x86_l_1db1:
	/* 0x1db1: and    dl,r8b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_R8, X86_WIDTH_8, X86_ALU_AND, 0);
x86_l_1db4:
	/* 0x1db4: cmp    eax,0x19 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 25ULL);
x86_l_1db7:
	/* 0x1db7: jb     1ed8 <filter_64ty_range+0x1cc> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1db7, 0x1ed8, x86_l_1ed8);
x86_l_1dbd:
	/* 0x1dbd: cmp    QWORD PTR [rdi+0x20],rsi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1dc1:
	/* 0x1dc1: setle  r8b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R8, X86_REG_NONE, X86_WIDTH_8, X86_CC_LE, 0);
x86_l_1dc5:
	/* 0x1dc5: cmp    rsi,QWORD PTR [rdi+0x28] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_1dc9:
	/* 0x1dc9: setle  r9b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R9, X86_REG_NONE, X86_WIDTH_8, X86_CC_LE, 0);
x86_l_1dcd:
	/* 0x1dcd: and    r9b,r8b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND, 0);
x86_l_1dd0:
	/* 0x1dd0: or     dl,r9b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR, 0);
x86_l_1dd3:
	/* 0x1dd3: cmp    eax,0x29 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 41ULL);
x86_l_1dd6:
	/* 0x1dd6: jb     1ed8 <filter_64ty_range+0x1cc> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1dd6, 0x1ed8, x86_l_1ed8);
x86_l_1ddc:
	/* 0x1ddc: cmp    QWORD PTR [rdi+0x30],rsi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1de0:
	/* 0x1de0: setle  r8b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R8, X86_REG_NONE, X86_WIDTH_8, X86_CC_LE, 0);
x86_l_1de4:
	/* 0x1de4: cmp    rsi,QWORD PTR [rdi+0x38] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_1de8:
	/* 0x1de8: setle  r9b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R9, X86_REG_NONE, X86_WIDTH_8, X86_CC_LE, 0);
x86_l_1dec:
	/* 0x1dec: and    r9b,r8b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND, 0);
x86_l_1def:
	/* 0x1def: or     dl,r9b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR, 0);
x86_l_1df2:
	/* 0x1df2: cmp    eax,0x39 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 57ULL);
x86_l_1df5:
	/* 0x1df5: jb     1ed8 <filter_64ty_range+0x1cc> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1df5, 0x1ed8, x86_l_1ed8);
x86_l_1dfb:
	/* 0x1dfb: cmp    QWORD PTR [rdi+0x40],rsi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1dff:
	/* 0x1dff: setle  al */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_CC_LE, 0);
x86_l_1e02:
	/* 0x1e02: cmp    rsi,QWORD PTR [rdi+0x48] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 72ULL);
x86_l_1e06:
	/* 0x1e06: setle  sil */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_CC_LE, 0);
x86_l_1e0a:
	/* 0x1e0a: jmp    1e8c <filter_64ty_range+0x180> */
	X86_SIM_X86_SUB_JMP(0x1e0a, 0x1e8c, x86_l_1e8c);
x86_l_1e0f:
	/* 0x1e0f: mov    rsi,QWORD PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e12:
	/* 0x1e12: cmp    ecx,0x1f */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 31ULL);
x86_l_1e15:
	/* 0x1e15: jne    1e29 <filter_64ty_range+0x11d> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x1e15, 0x1e29, x86_l_1e29);
x86_l_1e17:
	/* 0x1e17: mov    eax,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_1e1c:
	/* 0x1e1c: cmp    QWORD PTR [rdi+0x10],rsi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e20:
	/* 0x1e20: ja     1e94 <filter_64ty_range+0x188> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x1e20, 0x1e94, x86_l_1e94);
x86_l_1e22:
	/* 0x1e22: cmp    rsi,QWORD PTR [rdi+0x18] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_1e26:
	/* 0x1e26: ja     1e94 <filter_64ty_range+0x188> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x1e26, 0x1e94, x86_l_1e94);
x86_l_1e28:
	/* 0x1e28: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_601);
x86_l_1e29:
	/* 0x1e29: mov    eax,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e2c:
	/* 0x1e2c: cmp    QWORD PTR [rdi+0x10],rsi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e30:
	/* 0x1e30: setbe  r8b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R8, X86_REG_NONE, X86_WIDTH_8, X86_CC_BE, 0);
x86_l_1e34:
	/* 0x1e34: cmp    rsi,QWORD PTR [rdi+0x18] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_1e38:
	/* 0x1e38: setbe  dl */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_CC_BE, 0);
x86_l_1e3b:
	/* 0x1e3b: and    dl,r8b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_R8, X86_WIDTH_8, X86_ALU_AND, 0);
x86_l_1e3e:
	/* 0x1e3e: cmp    eax,0x19 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 25ULL);
x86_l_1e41:
	/* 0x1e41: jb     1ed8 <filter_64ty_range+0x1cc> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1e41, 0x1ed8, x86_l_1ed8);
x86_l_1e47:
	/* 0x1e47: cmp    QWORD PTR [rdi+0x20],rsi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1e4b:
	/* 0x1e4b: setbe  r8b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R8, X86_REG_NONE, X86_WIDTH_8, X86_CC_BE, 0);
x86_l_1e4f:
	/* 0x1e4f: cmp    rsi,QWORD PTR [rdi+0x28] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_1e53:
	/* 0x1e53: setbe  r9b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R9, X86_REG_NONE, X86_WIDTH_8, X86_CC_BE, 0);
x86_l_1e57:
	/* 0x1e57: and    r9b,r8b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND, 0);
x86_l_1e5a:
	/* 0x1e5a: or     dl,r9b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR, 0);
x86_l_1e5d:
	/* 0x1e5d: cmp    eax,0x29 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 41ULL);
x86_l_1e60:
	/* 0x1e60: jb     1ed8 <filter_64ty_range+0x1cc> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1e60, 0x1ed8, x86_l_1ed8);
x86_l_1e62:
	/* 0x1e62: cmp    QWORD PTR [rdi+0x30],rsi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1e66:
	/* 0x1e66: setbe  r8b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R8, X86_REG_NONE, X86_WIDTH_8, X86_CC_BE, 0);
x86_l_1e6a:
	/* 0x1e6a: cmp    rsi,QWORD PTR [rdi+0x38] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_1e6e:
	/* 0x1e6e: setbe  r9b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R9, X86_REG_NONE, X86_WIDTH_8, X86_CC_BE, 0);
x86_l_1e72:
	/* 0x1e72: and    r9b,r8b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND, 0);
x86_l_1e75:
	/* 0x1e75: or     dl,r9b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR, 0);
x86_l_1e78:
	/* 0x1e78: cmp    eax,0x39 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 57ULL);
x86_l_1e7b:
	/* 0x1e7b: jb     1ed8 <filter_64ty_range+0x1cc> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1e7b, 0x1ed8, x86_l_1ed8);
x86_l_1e7d:
	/* 0x1e7d: cmp    QWORD PTR [rdi+0x40],rsi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1e81:
	/* 0x1e81: setbe  al */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_CC_BE, 0);
x86_l_1e84:
	/* 0x1e84: cmp    rsi,QWORD PTR [rdi+0x48] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 72ULL);
x86_l_1e88:
	/* 0x1e88: setbe  sil */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_CC_BE, 0);
x86_l_1e8c:
	/* 0x1e8c: and    sil,al */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_ALU_AND, 0);
x86_l_1e8f:
	/* 0x1e8f: or     dl,sil */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RSI, X86_WIDTH_8, X86_ALU_OR, 0);
x86_l_1e92:
	/* 0x1e92: jmp    1ed8 <filter_64ty_range+0x1cc> */
	X86_SIM_X86_SUB_JMP(0x1e92, 0x1ed8, x86_l_1ed8);
x86_l_1e94:
	/* 0x1e94: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e97:
	/* 0x1e97: cmp    edx,0x19 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 25ULL);
x86_l_1e9a:
	/* 0x1e9a: jb     1ed6 <filter_64ty_range+0x1ca> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1e9a, 0x1ed6, x86_l_1ed6);
x86_l_1e9c:
	/* 0x1e9c: cmp    QWORD PTR [rdi+0x20],rsi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ea0:
	/* 0x1ea0: ja     1ea8 <filter_64ty_range+0x19c> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x1ea0, 0x1ea8, x86_l_1ea8);
x86_l_1ea2:
	/* 0x1ea2: cmp    rsi,QWORD PTR [rdi+0x28] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_1ea6:
	/* 0x1ea6: jbe    1e28 <filter_64ty_range+0x11c> */
	X86_SIM_X86_SUB_JCC(X86_CC_BE, 0x1ea6, 0x1e28, x86_l_1e28);
x86_l_1ea8:
	/* 0x1ea8: cmp    edx,0x29 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 41ULL);
x86_l_1eab:
	/* 0x1eab: jb     1ed6 <filter_64ty_range+0x1ca> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1eab, 0x1ed6, x86_l_1ed6);
x86_l_1ead:
	/* 0x1ead: cmp    QWORD PTR [rdi+0x30],rsi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1eb1:
	/* 0x1eb1: ja     1ebd <filter_64ty_range+0x1b1> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x1eb1, 0x1ebd, x86_l_1ebd);
x86_l_1eb3:
	/* 0x1eb3: cmp    rsi,QWORD PTR [rdi+0x38] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_1eb7:
	/* 0x1eb7: jbe    1e28 <filter_64ty_range+0x11c> */
	X86_SIM_X86_SUB_JCC(X86_CC_BE, 0x1eb7, 0x1e28, x86_l_1e28);
x86_l_1ebd:
	/* 0x1ebd: cmp    edx,0x39 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 57ULL);
x86_l_1ec0:
	/* 0x1ec0: jb     1ed6 <filter_64ty_range+0x1ca> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1ec0, 0x1ed6, x86_l_1ed6);
x86_l_1ec2:
	/* 0x1ec2: xor    edx,edx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1ec4:
	/* 0x1ec4: cmp    QWORD PTR [rdi+0x40],rsi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1ec8:
	/* 0x1ec8: ja     1ed8 <filter_64ty_range+0x1cc> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x1ec8, 0x1ed8, x86_l_1ed8);
x86_l_1eca:
	/* 0x1eca: cmp    rsi,QWORD PTR [rdi+0x48] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 72ULL);
x86_l_1ece:
	/* 0x1ece: jbe    1e28 <filter_64ty_range+0x11c> */
	X86_SIM_X86_SUB_JCC(X86_CC_BE, 0x1ece, 0x1e28, x86_l_1e28);
x86_l_1ed4:
	/* 0x1ed4: jmp    1ed8 <filter_64ty_range+0x1cc> */
	X86_SIM_X86_SUB_JMP(0x1ed4, 0x1ed8, x86_l_1ed8);
x86_l_1ed6:
	/* 0x1ed6: xor    edx,edx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1ed8:
	/* 0x1ed8: cmp    ecx,0x20 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 32ULL);
x86_l_1edb:
	/* 0x1edb: sete   al */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_CC_E, 0);
x86_l_1ede:
	/* 0x1ede: xor    dl,0x1 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_ALU_XOR, 1ULL);
x86_l_1ee1:
	/* 0x1ee1: and    dl,al */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RAX, X86_WIDTH_8, X86_ALU_AND, 0);
x86_l_1ee3:
	/* 0x1ee3: movzx  eax,dl */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8, 0);
x86_l_1ee6:
	/* 0x1ee6: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_601);

	/* native subroutine native_link_sub_1ee7 */
x86_l_1ee7:
	/* 0x1ee7: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1eea:
	/* 0x1eea: lea    edx,[rcx-0x1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_1eed:
	/* 0x1eed: cmp    edx,0x24 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 36ULL);
x86_l_1ef0:
	/* 0x1ef0: ja     20d7 <filter_32ty_selector_val+0x1f0> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x1ef0, 0x20d7, x86_l_20d7);
x86_l_1ef6:
	/* 0x1ef6: mov    eax,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_1efb:
	/* Capture image-bound code identity before scheduled instructions. */
	switch (X86_SIM_L_READ_REG(X86_RDX) << 2) {
	case 0ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1f5dULL); break;
	case 4ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x2005ULL); break;
	case 8ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1f0cULL); break;
	case 12ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1f0cULL); break;
	case 16ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x20d7ULL); break;
	case 20ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1f0bULL); break;
	case 24ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x20d7ULL); break;
	case 28ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x20d7ULL); break;
	case 32ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x20d7ULL); break;
	case 36ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x20d7ULL); break;
	case 40ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x20d7ULL); break;
	case 44ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1fbcULL); break;
	case 48ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x20d7ULL); break;
	case 52ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x20d7ULL); break;
	case 56ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x20d7ULL); break;
	case 60ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x20d7ULL); break;
	case 64ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x20d7ULL); break;
	case 68ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x20d7ULL); break;
	case 72ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x20d7ULL); break;
	case 76ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x20d7ULL); break;
	case 80ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x20d7ULL); break;
	case 84ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x20d7ULL); break;
	case 88ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x20d7ULL); break;
	case 92ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x20d7ULL); break;
	case 96ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x20d7ULL); break;
	case 100ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1f0bULL); break;
	case 104ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1f0bULL); break;
	case 108ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x20d7ULL); break;
	case 112ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x20d7ULL); break;
	case 116ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x20d7ULL); break;
	case 120ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x20d7ULL); break;
	case 124ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x20d7ULL); break;
	case 128ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x20d7ULL); break;
	case 132ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x20d7ULL); break;
	case 136ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x20d7ULL); break;
	case 140ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x20d7ULL); break;
	case 144ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1f0bULL); break;
	default: __x86_sim_unresolved_indirect_target();
	}
x86_l_1f09:
	/* 0x1f09: jmp    rdx */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RDX);
		switch (X86_SIM_L_REG_TAG(X86_RDX)) {
		case X86_SIM_TAG_CODE:
			switch (__x86_target) {
			case 0x1f0bULL: goto x86_l_1f0b;
			case 0x1f0cULL: goto x86_l_1f0c;
			case 0x1f5dULL: goto x86_l_1f5d;
			case 0x1fbcULL: goto x86_l_1fbc;
			case 0x2005ULL: goto x86_l_2005;
			case 0x20d7ULL: goto x86_l_20d7;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_1f0b:
	/* 0x1f0b: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_369);
x86_l_1f0c:
	/* 0x1f0c: mov    edx,DWORD PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f0e:
	/* 0x1f0e: cmp    edx,DWORD PTR [rdi+0x10] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 16ULL);
x86_l_1f11:
	/* 0x1f11: jne    1f1c <filter_32ty_selector_val+0x35> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x1f11, 0x1f1c, x86_l_1f1c);
x86_l_1f13:
	/* 0x1f13: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1f15:
	/* 0x1f15: cmp    ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 3ULL);
x86_l_1f18:
	/* 0x1f18: sete   al */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_CC_E, 0);
x86_l_1f1b:
	/* 0x1f1b: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_369);
x86_l_1f1c:
	/* 0x1f1c: mov    esi,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f1f:
	/* 0x1f1f: cmp    esi,0xd */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 13ULL);
x86_l_1f22:
	/* 0x1f22: jb     1f3d <filter_32ty_selector_val+0x56> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1f22, 0x1f3d, x86_l_1f3d);
x86_l_1f24:
	/* 0x1f24: cmp    edx,DWORD PTR [rdi+0x14] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_1f27:
	/* 0x1f27: je     1f13 <filter_32ty_selector_val+0x2c> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1f27, 0x1f13, x86_l_1f13);
x86_l_1f29:
	/* 0x1f29: cmp    esi,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_1f2c:
	/* 0x1f2c: jb     1f3d <filter_32ty_selector_val+0x56> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1f2c, 0x1f3d, x86_l_1f3d);
x86_l_1f2e:
	/* 0x1f2e: cmp    edx,DWORD PTR [rdi+0x18] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 24ULL);
x86_l_1f31:
	/* 0x1f31: je     1f13 <filter_32ty_selector_val+0x2c> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1f31, 0x1f13, x86_l_1f13);
x86_l_1f33:
	/* 0x1f33: cmp    esi,0x15 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 21ULL);
x86_l_1f36:
	/* 0x1f36: jb     1f3d <filter_32ty_selector_val+0x56> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1f36, 0x1f3d, x86_l_1f3d);
x86_l_1f38:
	/* 0x1f38: cmp    edx,DWORD PTR [rdi+0x1c] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 28ULL);
x86_l_1f3b:
	/* 0x1f3b: je     1f13 <filter_32ty_selector_val+0x2c> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1f3b, 0x1f13, x86_l_1f13);
x86_l_1f3d:
	/* 0x1f3d: cmp    ecx,0x25 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 37ULL);
x86_l_1f40:
	/* 0x1f40: ja     20d7 <filter_32ty_selector_val+0x1f0> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x1f40, 0x20d7, x86_l_20d7);
x86_l_1f46:
	/* 0x1f46: mov    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_1f48:
	/* 0x1f48: movabs rdx,0x200c000050 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, 0, 137640280144ULL);
x86_l_1f52:
	/* 0x1f52: bt     rdx,rcx */
	X86_SIM_RUN_OP(X86_OP_BT, X86_RDX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_1f56:
	/* 0x1f56: jb     1f0b <filter_32ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1f56, 0x1f0b, x86_l_1f0b);
x86_l_1f58:
	/* 0x1f58: jmp    20d7 <filter_32ty_selector_val+0x1f0> */
	X86_SIM_X86_SUB_JMP(0x1f58, 0x20d7, x86_l_20d7);
x86_l_1f5d:
	/* 0x1f5d: mov    ecx,DWORD PTR [rdi+0xc] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1f60:
	/* 0x1f60: cmp    ecx,0xc */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 12ULL);
x86_l_1f63:
	/* 0x1f63: ja     2065 <filter_32ty_selector_val+0x17e> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x1f63, 0x2065, x86_l_2065);
x86_l_1f69:
	/* 0x1f69: mov    edx,0x1402 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 5122ULL);
x86_l_1f6e:
	/* 0x1f6e: bt     edx,ecx */
	X86_SIM_RUN_OP(X86_OP_BT, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_1f71:
	/* 0x1f71: jae    2065 <filter_32ty_selector_val+0x17e> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x1f71, 0x2065, x86_l_2065);
x86_l_1f77:
	/* 0x1f77: mov    ecx,DWORD PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f79:
	/* 0x1f79: cmp    ecx,DWORD PTR [rdi+0x10] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 16ULL);
x86_l_1f7c:
	/* 0x1f7c: jg     1f0b <filter_32ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x1f7c, 0x1f0b, x86_l_1f0b);
x86_l_1f7e:
	/* 0x1f7e: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f81:
	/* 0x1f81: cmp    edx,0xd */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 13ULL);
x86_l_1f84:
	/* 0x1f84: jb     20d7 <filter_32ty_selector_val+0x1f0> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1f84, 0x20d7, x86_l_20d7);
x86_l_1f8a:
	/* 0x1f8a: cmp    ecx,DWORD PTR [rdi+0x14] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_1f8d:
	/* 0x1f8d: jg     1f0b <filter_32ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x1f8d, 0x1f0b, x86_l_1f0b);
x86_l_1f93:
	/* 0x1f93: cmp    edx,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_1f96:
	/* 0x1f96: jb     20d7 <filter_32ty_selector_val+0x1f0> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1f96, 0x20d7, x86_l_20d7);
x86_l_1f9c:
	/* 0x1f9c: cmp    ecx,DWORD PTR [rdi+0x18] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 24ULL);
x86_l_1f9f:
	/* 0x1f9f: jg     1f0b <filter_32ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x1f9f, 0x1f0b, x86_l_1f0b);
x86_l_1fa5:
	/* 0x1fa5: cmp    edx,0x15 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 21ULL);
x86_l_1fa8:
	/* 0x1fa8: jb     20d7 <filter_32ty_selector_val+0x1f0> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1fa8, 0x20d7, x86_l_20d7);
x86_l_1fae:
	/* 0x1fae: cmp    ecx,DWORD PTR [rdi+0x1c] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 28ULL);
x86_l_1fb1:
	/* 0x1fb1: jg     1f0b <filter_32ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x1fb1, 0x1f0b, x86_l_1f0b);
x86_l_1fb7:
	/* 0x1fb7: jmp    20d7 <filter_32ty_selector_val+0x1f0> */
	X86_SIM_X86_SUB_JMP(0x1fb7, 0x20d7, x86_l_20d7);
x86_l_1fbc:
	/* 0x1fbc: mov    ecx,DWORD PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1fbe:
	/* 0x1fbe: test   DWORD PTR [rdi+0x10],ecx */
	X86_SIM_RUN_OP(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1fc1:
	/* 0x1fc1: jne    1f0b <filter_32ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x1fc1, 0x1f0b, x86_l_1f0b);
x86_l_1fc7:
	/* 0x1fc7: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1fca:
	/* 0x1fca: cmp    edx,0xd */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 13ULL);
x86_l_1fcd:
	/* 0x1fcd: jb     20d7 <filter_32ty_selector_val+0x1f0> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1fcd, 0x20d7, x86_l_20d7);
x86_l_1fd3:
	/* 0x1fd3: test   DWORD PTR [rdi+0x14],ecx */
	X86_SIM_RUN_OP(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_1fd6:
	/* 0x1fd6: jne    1f0b <filter_32ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x1fd6, 0x1f0b, x86_l_1f0b);
x86_l_1fdc:
	/* 0x1fdc: cmp    edx,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_1fdf:
	/* 0x1fdf: jb     20d7 <filter_32ty_selector_val+0x1f0> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1fdf, 0x20d7, x86_l_20d7);
x86_l_1fe5:
	/* 0x1fe5: test   DWORD PTR [rdi+0x18],ecx */
	X86_SIM_RUN_OP(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1fe8:
	/* 0x1fe8: jne    1f0b <filter_32ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x1fe8, 0x1f0b, x86_l_1f0b);
x86_l_1fee:
	/* 0x1fee: cmp    edx,0x15 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 21ULL);
x86_l_1ff1:
	/* 0x1ff1: jb     20d7 <filter_32ty_selector_val+0x1f0> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1ff1, 0x20d7, x86_l_20d7);
x86_l_1ff7:
	/* 0x1ff7: test   DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_RUN_OP(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120259084288ULL);
x86_l_1ffa:
	/* 0x1ffa: jne    1f0b <filter_32ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x1ffa, 0x1f0b, x86_l_1f0b);
x86_l_2000:
	/* 0x2000: jmp    20d7 <filter_32ty_selector_val+0x1f0> */
	X86_SIM_X86_SUB_JMP(0x2000, 0x20d7, x86_l_20d7);
x86_l_2005:
	/* 0x2005: mov    ecx,DWORD PTR [rdi+0xc] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2008:
	/* 0x2008: cmp    ecx,0xc */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 12ULL);
x86_l_200b:
	/* 0x200b: ja     209f <filter_32ty_selector_val+0x1b8> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x200b, 0x209f, x86_l_209f);
x86_l_2011:
	/* 0x2011: mov    edx,0x1402 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 5122ULL);
x86_l_2016:
	/* 0x2016: bt     edx,ecx */
	X86_SIM_RUN_OP(X86_OP_BT, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_2019:
	/* 0x2019: jae    209f <filter_32ty_selector_val+0x1b8> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x2019, 0x209f, x86_l_209f);
x86_l_201f:
	/* 0x201f: mov    ecx,DWORD PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2021:
	/* 0x2021: cmp    ecx,DWORD PTR [rdi+0x10] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 16ULL);
x86_l_2024:
	/* 0x2024: jl     1f0b <filter_32ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_L, 0x2024, 0x1f0b, x86_l_1f0b);
x86_l_202a:
	/* 0x202a: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_202d:
	/* 0x202d: cmp    edx,0xd */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 13ULL);
x86_l_2030:
	/* 0x2030: jb     20d7 <filter_32ty_selector_val+0x1f0> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x2030, 0x20d7, x86_l_20d7);
x86_l_2036:
	/* 0x2036: cmp    ecx,DWORD PTR [rdi+0x14] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_2039:
	/* 0x2039: jl     1f0b <filter_32ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_L, 0x2039, 0x1f0b, x86_l_1f0b);
x86_l_203f:
	/* 0x203f: cmp    edx,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_2042:
	/* 0x2042: jb     20d7 <filter_32ty_selector_val+0x1f0> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x2042, 0x20d7, x86_l_20d7);
x86_l_2048:
	/* 0x2048: cmp    ecx,DWORD PTR [rdi+0x18] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 24ULL);
x86_l_204b:
	/* 0x204b: jl     1f0b <filter_32ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_L, 0x204b, 0x1f0b, x86_l_1f0b);
x86_l_2051:
	/* 0x2051: cmp    edx,0x15 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 21ULL);
x86_l_2054:
	/* 0x2054: jb     20d7 <filter_32ty_selector_val+0x1f0> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x2054, 0x20d7, x86_l_20d7);
x86_l_205a:
	/* 0x205a: cmp    ecx,DWORD PTR [rdi+0x1c] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 28ULL);
x86_l_205d:
	/* 0x205d: jl     1f0b <filter_32ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_L, 0x205d, 0x1f0b, x86_l_1f0b);
x86_l_2063:
	/* 0x2063: jmp    20d7 <filter_32ty_selector_val+0x1f0> */
	X86_SIM_X86_SUB_JMP(0x2063, 0x20d7, x86_l_20d7);
x86_l_2065:
	/* 0x2065: mov    ecx,DWORD PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2067:
	/* 0x2067: cmp    ecx,DWORD PTR [rdi+0x10] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 16ULL);
x86_l_206a:
	/* 0x206a: ja     1f0b <filter_32ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x206a, 0x1f0b, x86_l_1f0b);
x86_l_2070:
	/* 0x2070: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2073:
	/* 0x2073: cmp    edx,0xd */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 13ULL);
x86_l_2076:
	/* 0x2076: jb     20d7 <filter_32ty_selector_val+0x1f0> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x2076, 0x20d7, x86_l_20d7);
x86_l_2078:
	/* 0x2078: cmp    ecx,DWORD PTR [rdi+0x14] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_207b:
	/* 0x207b: ja     1f0b <filter_32ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x207b, 0x1f0b, x86_l_1f0b);
x86_l_2081:
	/* 0x2081: cmp    edx,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_2084:
	/* 0x2084: jb     20d7 <filter_32ty_selector_val+0x1f0> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x2084, 0x20d7, x86_l_20d7);
x86_l_2086:
	/* 0x2086: cmp    ecx,DWORD PTR [rdi+0x18] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 24ULL);
x86_l_2089:
	/* 0x2089: ja     1f0b <filter_32ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x2089, 0x1f0b, x86_l_1f0b);
x86_l_208f:
	/* 0x208f: cmp    edx,0x15 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 21ULL);
x86_l_2092:
	/* 0x2092: jb     20d7 <filter_32ty_selector_val+0x1f0> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x2092, 0x20d7, x86_l_20d7);
x86_l_2094:
	/* 0x2094: cmp    ecx,DWORD PTR [rdi+0x1c] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 28ULL);
x86_l_2097:
	/* 0x2097: ja     1f0b <filter_32ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x2097, 0x1f0b, x86_l_1f0b);
x86_l_209d:
	/* 0x209d: jmp    20d7 <filter_32ty_selector_val+0x1f0> */
	X86_SIM_X86_SUB_JMP(0x209d, 0x20d7, x86_l_20d7);
x86_l_209f:
	/* 0x209f: mov    ecx,DWORD PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20a1:
	/* 0x20a1: cmp    ecx,DWORD PTR [rdi+0x10] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 16ULL);
x86_l_20a4:
	/* 0x20a4: jb     1f0b <filter_32ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x20a4, 0x1f0b, x86_l_1f0b);
x86_l_20aa:
	/* 0x20aa: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20ad:
	/* 0x20ad: cmp    edx,0xd */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 13ULL);
x86_l_20b0:
	/* 0x20b0: jb     20d7 <filter_32ty_selector_val+0x1f0> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x20b0, 0x20d7, x86_l_20d7);
x86_l_20b2:
	/* 0x20b2: cmp    ecx,DWORD PTR [rdi+0x14] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_20b5:
	/* 0x20b5: jb     1f0b <filter_32ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x20b5, 0x1f0b, x86_l_1f0b);
x86_l_20bb:
	/* 0x20bb: cmp    edx,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_20be:
	/* 0x20be: jb     20d7 <filter_32ty_selector_val+0x1f0> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x20be, 0x20d7, x86_l_20d7);
x86_l_20c0:
	/* 0x20c0: cmp    ecx,DWORD PTR [rdi+0x18] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 24ULL);
x86_l_20c3:
	/* 0x20c3: jb     1f0b <filter_32ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x20c3, 0x1f0b, x86_l_1f0b);
x86_l_20c9:
	/* 0x20c9: cmp    edx,0x15 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 21ULL);
x86_l_20cc:
	/* 0x20cc: jb     20d7 <filter_32ty_selector_val+0x1f0> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x20cc, 0x20d7, x86_l_20d7);
x86_l_20ce:
	/* 0x20ce: cmp    ecx,DWORD PTR [rdi+0x1c] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 28ULL);
x86_l_20d1:
	/* 0x20d1: jb     1f0b <filter_32ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x20d1, 0x1f0b, x86_l_1f0b);
x86_l_20d7:
	/* 0x20d7: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_20d9:
	/* 0x20d9: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_369);

	/* native subroutine native_link_sub_20da */
x86_l_20da:
	/* 0x20da: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_20dd:
	/* 0x20dd: mov    eax,DWORD PTR [rdi+0xc] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_20e0:
	/* 0x20e0: cmp    eax,0xc */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 12ULL);
x86_l_20e3:
	/* 0x20e3: ja     21c9 <filter_32ty_range+0xef> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x20e3, 0x21c9, x86_l_21c9);
x86_l_20e9:
	/* 0x20e9: mov    edx,0x1402 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 5122ULL);
x86_l_20ee:
	/* 0x20ee: bt     edx,eax */
	X86_SIM_RUN_OP(X86_OP_BT, X86_RDX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_20f1:
	/* 0x20f1: jae    21c9 <filter_32ty_range+0xef> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x20f1, 0x21c9, x86_l_21c9);
x86_l_20f7:
	/* 0x20f7: mov    esi,DWORD PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20f9:
	/* 0x20f9: cmp    ecx,0x1f */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 31ULL);
x86_l_20fc:
	/* 0x20fc: jne    2164 <filter_32ty_range+0x8a> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x20fc, 0x2164, x86_l_2164);
x86_l_20fe:
	/* 0x20fe: mov    eax,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_2103:
	/* 0x2103: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2106:
	/* 0x2106: jg     2111 <filter_32ty_range+0x37> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x2106, 0x2111, x86_l_2111);
x86_l_2108:
	/* 0x2108: cmp    esi,DWORD PTR [rdi+0x14] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_210b:
	/* 0x210b: jle    21df <filter_32ty_range+0x105> */
	X86_SIM_X86_SUB_JCC(X86_CC_LE, 0x210b, 0x21df, x86_l_21df);
x86_l_2111:
	/* 0x2111: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2114:
	/* 0x2114: cmp    edx,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_2117:
	/* 0x2117: jb     227f <filter_32ty_range+0x1a5> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x2117, 0x227f, x86_l_227f);
x86_l_211d:
	/* 0x211d: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2120:
	/* 0x2120: jg     212b <filter_32ty_range+0x51> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x2120, 0x212b, x86_l_212b);
x86_l_2122:
	/* 0x2122: cmp    esi,DWORD PTR [rdi+0x1c] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 28ULL);
x86_l_2125:
	/* 0x2125: jle    21df <filter_32ty_range+0x105> */
	X86_SIM_X86_SUB_JCC(X86_CC_LE, 0x2125, 0x21df, x86_l_21df);
x86_l_212b:
	/* 0x212b: cmp    edx,0x19 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 25ULL);
x86_l_212e:
	/* 0x212e: jb     227f <filter_32ty_range+0x1a5> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x212e, 0x227f, x86_l_227f);
x86_l_2134:
	/* 0x2134: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2137:
	/* 0x2137: jg     2142 <filter_32ty_range+0x68> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x2137, 0x2142, x86_l_2142);
x86_l_2139:
	/* 0x2139: cmp    esi,DWORD PTR [rdi+0x24] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 36ULL);
x86_l_213c:
	/* 0x213c: jle    21df <filter_32ty_range+0x105> */
	X86_SIM_X86_SUB_JCC(X86_CC_LE, 0x213c, 0x21df, x86_l_21df);
x86_l_2142:
	/* 0x2142: cmp    edx,0x21 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 33ULL);
x86_l_2145:
	/* 0x2145: jb     227f <filter_32ty_range+0x1a5> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x2145, 0x227f, x86_l_227f);
x86_l_214b:
	/* 0x214b: xor    edx,edx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_214d:
	/* 0x214d: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2150:
	/* 0x2150: jg     2281 <filter_32ty_range+0x1a7> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x2150, 0x2281, x86_l_2281);
x86_l_2156:
	/* 0x2156: cmp    esi,DWORD PTR [rdi+0x2c] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 44ULL);
x86_l_2159:
	/* 0x2159: jle    21df <filter_32ty_range+0x105> */
	X86_SIM_X86_SUB_JCC(X86_CC_LE, 0x2159, 0x21df, x86_l_21df);
x86_l_215f:
	/* 0x215f: jmp    2281 <filter_32ty_range+0x1a7> */
	X86_SIM_X86_SUB_JMP(0x215f, 0x2281, x86_l_2281);
x86_l_2164:
	/* 0x2164: mov    eax,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2167:
	/* 0x2167: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_216a:
	/* 0x216a: setle  r8b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R8, X86_REG_NONE, X86_WIDTH_8, X86_CC_LE, 0);
x86_l_216e:
	/* 0x216e: cmp    esi,DWORD PTR [rdi+0x14] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_2171:
	/* 0x2171: setle  dl */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_CC_LE, 0);
x86_l_2174:
	/* 0x2174: and    dl,r8b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_R8, X86_WIDTH_8, X86_ALU_AND, 0);
x86_l_2177:
	/* 0x2177: cmp    eax,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_217a:
	/* 0x217a: jb     2281 <filter_32ty_range+0x1a7> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x217a, 0x2281, x86_l_2281);
x86_l_2180:
	/* 0x2180: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2183:
	/* 0x2183: setle  r8b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R8, X86_REG_NONE, X86_WIDTH_8, X86_CC_LE, 0);
x86_l_2187:
	/* 0x2187: cmp    esi,DWORD PTR [rdi+0x1c] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 28ULL);
x86_l_218a:
	/* 0x218a: setle  r9b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R9, X86_REG_NONE, X86_WIDTH_8, X86_CC_LE, 0);
x86_l_218e:
	/* 0x218e: and    r9b,r8b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND, 0);
x86_l_2191:
	/* 0x2191: or     dl,r9b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR, 0);
x86_l_2194:
	/* 0x2194: cmp    eax,0x19 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 25ULL);
x86_l_2197:
	/* 0x2197: jb     2281 <filter_32ty_range+0x1a7> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x2197, 0x2281, x86_l_2281);
x86_l_219d:
	/* 0x219d: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_21a0:
	/* 0x21a0: setle  r8b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R8, X86_REG_NONE, X86_WIDTH_8, X86_CC_LE, 0);
x86_l_21a4:
	/* 0x21a4: cmp    esi,DWORD PTR [rdi+0x24] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 36ULL);
x86_l_21a7:
	/* 0x21a7: setle  r9b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R9, X86_REG_NONE, X86_WIDTH_8, X86_CC_LE, 0);
x86_l_21ab:
	/* 0x21ab: and    r9b,r8b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND, 0);
x86_l_21ae:
	/* 0x21ae: or     dl,r9b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR, 0);
x86_l_21b1:
	/* 0x21b1: cmp    eax,0x21 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 33ULL);
x86_l_21b4:
	/* 0x21b4: jb     2281 <filter_32ty_range+0x1a7> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x21b4, 0x2281, x86_l_2281);
x86_l_21ba:
	/* 0x21ba: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_21bd:
	/* 0x21bd: setle  al */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_CC_LE, 0);
x86_l_21c0:
	/* 0x21c0: cmp    esi,DWORD PTR [rdi+0x2c] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 44ULL);
x86_l_21c3:
	/* 0x21c3: setle  sil */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_CC_LE, 0);
x86_l_21c7:
	/* 0x21c7: jmp    223b <filter_32ty_range+0x161> */
	X86_SIM_X86_SUB_JMP(0x21c7, 0x223b, x86_l_223b);
x86_l_21c9:
	/* 0x21c9: mov    esi,DWORD PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21cb:
	/* 0x21cb: cmp    ecx,0x1f */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 31ULL);
x86_l_21ce:
	/* 0x21ce: jne    21e0 <filter_32ty_range+0x106> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x21ce, 0x21e0, x86_l_21e0);
x86_l_21d0:
	/* 0x21d0: mov    eax,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_21d5:
	/* 0x21d5: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_21d8:
	/* 0x21d8: ja     2243 <filter_32ty_range+0x169> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x21d8, 0x2243, x86_l_2243);
x86_l_21da:
	/* 0x21da: cmp    esi,DWORD PTR [rdi+0x14] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_21dd:
	/* 0x21dd: ja     2243 <filter_32ty_range+0x169> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x21dd, 0x2243, x86_l_2243);
x86_l_21df:
	/* 0x21df: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_369);
x86_l_21e0:
	/* 0x21e0: mov    eax,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_21e3:
	/* 0x21e3: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_21e6:
	/* 0x21e6: setbe  r8b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R8, X86_REG_NONE, X86_WIDTH_8, X86_CC_BE, 0);
x86_l_21ea:
	/* 0x21ea: cmp    esi,DWORD PTR [rdi+0x14] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_21ed:
	/* 0x21ed: setbe  dl */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_CC_BE, 0);
x86_l_21f0:
	/* 0x21f0: and    dl,r8b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_R8, X86_WIDTH_8, X86_ALU_AND, 0);
x86_l_21f3:
	/* 0x21f3: cmp    eax,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_21f6:
	/* 0x21f6: jb     2281 <filter_32ty_range+0x1a7> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x21f6, 0x2281, x86_l_2281);
x86_l_21fc:
	/* 0x21fc: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_21ff:
	/* 0x21ff: setbe  r8b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R8, X86_REG_NONE, X86_WIDTH_8, X86_CC_BE, 0);
x86_l_2203:
	/* 0x2203: cmp    esi,DWORD PTR [rdi+0x1c] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 28ULL);
x86_l_2206:
	/* 0x2206: setbe  r9b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R9, X86_REG_NONE, X86_WIDTH_8, X86_CC_BE, 0);
x86_l_220a:
	/* 0x220a: and    r9b,r8b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND, 0);
x86_l_220d:
	/* 0x220d: or     dl,r9b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR, 0);
x86_l_2210:
	/* 0x2210: cmp    eax,0x19 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 25ULL);
x86_l_2213:
	/* 0x2213: jb     2281 <filter_32ty_range+0x1a7> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x2213, 0x2281, x86_l_2281);
x86_l_2215:
	/* 0x2215: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2218:
	/* 0x2218: setbe  r8b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R8, X86_REG_NONE, X86_WIDTH_8, X86_CC_BE, 0);
x86_l_221c:
	/* 0x221c: cmp    esi,DWORD PTR [rdi+0x24] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 36ULL);
x86_l_221f:
	/* 0x221f: setbe  r9b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R9, X86_REG_NONE, X86_WIDTH_8, X86_CC_BE, 0);
x86_l_2223:
	/* 0x2223: and    r9b,r8b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND, 0);
x86_l_2226:
	/* 0x2226: or     dl,r9b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR, 0);
x86_l_2229:
	/* 0x2229: cmp    eax,0x21 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 33ULL);
x86_l_222c:
	/* 0x222c: jb     2281 <filter_32ty_range+0x1a7> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x222c, 0x2281, x86_l_2281);
x86_l_222e:
	/* 0x222e: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2231:
	/* 0x2231: setbe  al */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_CC_BE, 0);
x86_l_2234:
	/* 0x2234: cmp    esi,DWORD PTR [rdi+0x2c] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 44ULL);
x86_l_2237:
	/* 0x2237: setbe  sil */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_CC_BE, 0);
x86_l_223b:
	/* 0x223b: and    sil,al */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_ALU_AND, 0);
x86_l_223e:
	/* 0x223e: or     dl,sil */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RSI, X86_WIDTH_8, X86_ALU_OR, 0);
x86_l_2241:
	/* 0x2241: jmp    2281 <filter_32ty_range+0x1a7> */
	X86_SIM_X86_SUB_JMP(0x2241, 0x2281, x86_l_2281);
x86_l_2243:
	/* 0x2243: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2246:
	/* 0x2246: cmp    edx,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_2249:
	/* 0x2249: jb     227f <filter_32ty_range+0x1a5> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x2249, 0x227f, x86_l_227f);
x86_l_224b:
	/* 0x224b: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_224e:
	/* 0x224e: ja     2255 <filter_32ty_range+0x17b> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x224e, 0x2255, x86_l_2255);
x86_l_2250:
	/* 0x2250: cmp    esi,DWORD PTR [rdi+0x1c] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 28ULL);
x86_l_2253:
	/* 0x2253: jbe    21df <filter_32ty_range+0x105> */
	X86_SIM_X86_SUB_JCC(X86_CC_BE, 0x2253, 0x21df, x86_l_21df);
x86_l_2255:
	/* 0x2255: cmp    edx,0x19 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 25ULL);
x86_l_2258:
	/* 0x2258: jb     227f <filter_32ty_range+0x1a5> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x2258, 0x227f, x86_l_227f);
x86_l_225a:
	/* 0x225a: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_225d:
	/* 0x225d: ja     2268 <filter_32ty_range+0x18e> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x225d, 0x2268, x86_l_2268);
x86_l_225f:
	/* 0x225f: cmp    esi,DWORD PTR [rdi+0x24] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 36ULL);
x86_l_2262:
	/* 0x2262: jbe    21df <filter_32ty_range+0x105> */
	X86_SIM_X86_SUB_JCC(X86_CC_BE, 0x2262, 0x21df, x86_l_21df);
x86_l_2268:
	/* 0x2268: cmp    edx,0x21 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 33ULL);
x86_l_226b:
	/* 0x226b: jb     227f <filter_32ty_range+0x1a5> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x226b, 0x227f, x86_l_227f);
x86_l_226d:
	/* 0x226d: xor    edx,edx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_226f:
	/* 0x226f: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2272:
	/* 0x2272: ja     2281 <filter_32ty_range+0x1a7> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x2272, 0x2281, x86_l_2281);
x86_l_2274:
	/* 0x2274: cmp    esi,DWORD PTR [rdi+0x2c] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 44ULL);
x86_l_2277:
	/* 0x2277: jbe    21df <filter_32ty_range+0x105> */
	X86_SIM_X86_SUB_JCC(X86_CC_BE, 0x2277, 0x21df, x86_l_21df);
x86_l_227d:
	/* 0x227d: jmp    2281 <filter_32ty_range+0x1a7> */
	X86_SIM_X86_SUB_JMP(0x227d, 0x2281, x86_l_2281);
x86_l_227f:
	/* 0x227f: xor    edx,edx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_2281:
	/* 0x2281: cmp    ecx,0x20 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 32ULL);
x86_l_2284:
	/* 0x2284: sete   al */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_CC_E, 0);
x86_l_2287:
	/* 0x2287: xor    dl,0x1 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_ALU_XOR, 1ULL);
x86_l_228a:
	/* 0x228a: and    dl,al */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RAX, X86_WIDTH_8, X86_ALU_AND, 0);
x86_l_228c:
	/* 0x228c: movzx  eax,dl */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8, 0);
x86_l_228f:
	/* 0x228f: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_369);

	/* native subroutine native_link_sub_2290 */
x86_l_2290:
	/* 0x2290: mov    rax,rdi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RDI, X86_WIDTH_64, 0, 0);
x86_l_2293:
	/* 0x2293: xor    r8d,r8d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_2296:
	/* 0x2296: cmp    rdx,0x20 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, 0, 32ULL);
x86_l_229a:
	/* 0x229a: jb     22c1 <__native_link_local_memset_zero_dynamic+0x31> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x229a, 0x22c1, x86_l_22c1);
x86_l_22a0:
	/* 0x22a0: mov    QWORD PTR [rdi],r8 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22a3:
	/* 0x22a3: mov    QWORD PTR [rdi+0x8],r8 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22a7:
	/* 0x22a7: mov    QWORD PTR [rdi+0x10],r8 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22ab:
	/* 0x22ab: mov    QWORD PTR [rdi+0x18],r8 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_22af:
	/* 0x22af: add    rdi,0x20 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_22b3:
	/* 0x22b3: sub    rdx,0x20 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SUB, 32ULL);
x86_l_22b7:
	/* 0x22b7: cmp    rdx,0x20 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, 0, 32ULL);
x86_l_22bb:
	/* 0x22bb: jae    22a0 <__native_link_local_memset_zero_dynamic+0x10> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x22bb, 0x22a0, x86_l_22a0);
x86_l_22c1:
	/* 0x22c1: cmp    rdx,0x8 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, 0, 8ULL);
x86_l_22c5:
	/* 0x22c5: jb     22e0 <__native_link_local_memset_zero_dynamic+0x50> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x22c5, 0x22e0, x86_l_22e0);
x86_l_22cb:
	/* 0x22cb: mov    QWORD PTR [rdi],r8 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22ce:
	/* 0x22ce: add    rdi,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_22d2:
	/* 0x22d2: sub    rdx,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SUB, 8ULL);
x86_l_22d6:
	/* 0x22d6: cmp    rdx,0x8 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, 0, 8ULL);
x86_l_22da:
	/* 0x22da: jae    22cb <__native_link_local_memset_zero_dynamic+0x3b> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x22da, 0x22cb, x86_l_22cb);
x86_l_22e0:
	/* 0x22e0: test   dl,0x4 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, 0, 4ULL);
x86_l_22e3:
	/* 0x22e3: je     22f0 <__native_link_local_memset_zero_dynamic+0x60> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x22e3, 0x22f0, x86_l_22f0);
x86_l_22e9:
	/* 0x22e9: mov    DWORD PTR [rdi],r8d */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22ec:
	/* 0x22ec: add    rdi,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_22f0:
	/* 0x22f0: test   dl,0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, 0, 2ULL);
x86_l_22f3:
	/* 0x22f3: je     2301 <__native_link_local_memset_zero_dynamic+0x71> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x22f3, 0x2301, x86_l_2301);
x86_l_22f9:
	/* 0x22f9: mov    WORD PTR [rdi],r8w */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_R8, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22fd:
	/* 0x22fd: add    rdi,0x2 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_2301:
	/* 0x2301: test   dl,0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_2304:
	/* 0x2304: je     230d <__native_link_local_memset_zero_dynamic+0x7d> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x2304, 0x230d, x86_l_230d);
x86_l_230a:
	/* 0x230a: mov    BYTE PTR [rdi],r8b */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_R8, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_230d:
	/* 0x230d: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_230d);

x86_sim_ret_dispatch_369:
	switch (__x86_sim_ret_addr) {
	case 0x237ULL: goto x86_l_237;
	default: __x86_sim_unresolved_indirect_target();
	}

x86_sim_ret_dispatch_588:
	switch (__x86_sim_ret_addr) {
	case 0x23eULL: goto x86_l_23e;
	default: __x86_sim_unresolved_indirect_target();
	}

x86_sim_ret_dispatch_601:
	switch (__x86_sim_ret_addr) {
	case 0x283ULL: goto x86_l_283;
	default: __x86_sim_unresolved_indirect_target();
	}

x86_sim_ret_dispatch_68d:
	switch (__x86_sim_ret_addr) {
	case 0x28fULL: goto x86_l_28f;
	case 0x2d4ULL: goto x86_l_2d4;
	default: __x86_sim_unresolved_indirect_target();
	}

x86_sim_ret_dispatch_6ce:
	switch (__x86_sim_ret_addr) {
	case 0x296ULL: goto x86_l_296;
	default: __x86_sim_unresolved_indirect_target();
	}

x86_sim_ret_dispatch_70f:
	switch (__x86_sim_ret_addr) {
	case 0x29dULL: goto x86_l_29d;
	default: __x86_sim_unresolved_indirect_target();
	}

x86_sim_ret_dispatch_72a:
	switch (__x86_sim_ret_addr) {
	case 0x2a8ULL: goto x86_l_2a8;
	default: __x86_sim_unresolved_indirect_target();
	}

x86_sim_ret_dispatch_7f2:
	switch (__x86_sim_ret_addr) {
	case 0x2c8ULL: goto x86_l_2c8;
	default: __x86_sim_unresolved_indirect_target();
	}

x86_sim_ret_dispatch_b87:
	switch (__x86_sim_ret_addr) {
	case 0x63dULL: goto x86_l_63d;
	case 0x751ULL: goto x86_l_751;
	case 0x7d0ULL: goto x86_l_7d0;
	default: __x86_sim_unresolved_indirect_target();
	}

x86_sim_ret_dispatch_d9a:
	switch (__x86_sim_ret_addr) {
	case 0x651ULL: goto x86_l_651;
	case 0x777ULL: goto x86_l_777;
	case 0x803ULL: goto x86_l_803;
	default: __x86_sim_unresolved_indirect_target();
	}

x86_sim_ret_dispatch_e00:
	switch (__x86_sim_ret_addr) {
	case 0x237ULL: goto x86_l_237;
	case 0x57dULL: goto x86_l_57d;
	case 0x837ULL: goto x86_l_837;
	default: __x86_sim_unresolved_indirect_target();
	}

x86_sim_ret_dispatch_ecc:
	switch (__x86_sim_ret_addr) {
	case 0x75bULL: goto x86_l_75b;
	default: __x86_sim_unresolved_indirect_target();
	}

x86_sim_ret_dispatch_1016:
	switch (__x86_sim_ret_addr) {
	case 0x647ULL: goto x86_l_647;
	case 0x769ULL: goto x86_l_769;
	default: __x86_sim_unresolved_indirect_target();
	}

x86_sim_ret_dispatch_1a7f:
	switch (__x86_sim_ret_addr) {
	case 0x667ULL: goto x86_l_667;
	default: __x86_sim_unresolved_indirect_target();
	}

x86_sim_ret_dispatch_230d:
	switch (__x86_sim_ret_addr) {
	case 0xa5aULL: goto x86_l_a5a;
	case 0xb39ULL: goto x86_l_b39;
	case 0xd48ULL: goto x86_l_d48;
	default: __x86_sim_unresolved_indirect_target();
	}

}

X86_SIM_LICENSE();
