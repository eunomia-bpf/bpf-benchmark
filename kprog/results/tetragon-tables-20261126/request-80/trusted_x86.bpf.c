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
extern __u8 kprobe_calls[] __ksym;
extern __u8 process_call_heap[] __ksym;
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
	/* 0x19: mov    rdi,QWORD PTR [rip+0x79e0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)process_call_heap));
x86_l_20:
	/* 0x20: lea    rsi,[rsp+0x4] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_25:
	/* 0x25: call   7a0a <__native_link_local_memset_zero_dynamic+0x57a1> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_2a:
	/* 0x2a: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_2d:
	/* 0x2d: je     35e <generic_kprobe_filter_arg+0x35e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2d, 0x35e, x86_l_35e);
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
	/* 0x44: mov    rdi,QWORD PTR [rip+0x79e0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)filter_map));
x86_l_4b:
	/* 0x4b: call   7a30 <__native_link_local_memset_zero_dynamic+0x57c7> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_50:
	/* 0x50: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_53:
	/* 0x53: je     34a <generic_kprobe_filter_arg+0x34a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x53, 0x34a, x86_l_34a);
x86_l_59:
	/* 0x59: cmp    BYTE PTR [r14+0x5ee0],0x0 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104316165685248ULL);
x86_l_61:
	/* 0x61: je     34a <generic_kprobe_filter_arg+0x34a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x61, 0x34a, x86_l_34a);
x86_l_67:
	/* 0x67: mov    r15,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R15, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_6a:
	/* 0x6a: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6f:
	/* 0x6f: mov    eax,r12d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_R12, X86_WIDTH_32, 0, 0);
x86_l_72:
	/* 0x72: and    eax,0x7 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_75:
	/* 0x75: cmp    BYTE PTR [r14+rax*1+0x5ec1],0x0 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 104183021699072ULL);
x86_l_7e:
	/* 0x7e: je     10d <generic_kprobe_filter_arg+0x10d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7e, 0x10d, x86_l_10d);
x86_l_84:
	/* 0x84: mov    eax,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_86:
	/* 0x86: mov    ecx,DWORD PTR [r15+rax*4+0x4] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_8b:
	/* 0x8b: lea    rdx,[rcx+rax*4] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 2), 0ULL);
x86_l_8f:
	/* 0x8f: add    rdx,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_93:
	/* 0x93: lea    rax,[rcx+rax*4] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 2), 0ULL);
x86_l_97:
	/* 0x97: add    rax,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_9b:
	/* 0x9b: and    eax,0x3ff */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_a0:
	/* 0xa0: mov    eax,DWORD PTR [rax+r15*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_a4:
	/* 0xa4: add    rax,rdx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_a7:
	/* 0xa7: add    rax,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_ab:
	/* 0xab: mov    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_ad:
	/* 0xad: and    ecx,0x3ff */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_b3:
	/* 0xb3: mov    ecx,DWORD PTR [rcx+r15*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_b7:
	/* 0xb7: add    rcx,rax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_ba:
	/* 0xba: mov    eax,ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_bc:
	/* 0xbc: and    eax,0x3ff */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_c1:
	/* 0xc1: mov    eax,DWORD PTR [rax+r15*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_c5:
	/* 0xc5: add    rax,rcx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_c8:
	/* 0xc8: mov    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_ca:
	/* 0xca: and    ecx,0x3ff */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_d0:
	/* 0xd0: mov    ecx,DWORD PTR [rcx+r15*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_d4:
	/* 0xd4: add    rcx,rax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_d7:
	/* 0xd7: mov    eax,ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_d9:
	/* 0xd9: and    eax,0x3ff */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_de:
	/* 0xde: mov    ebp,DWORD PTR [rax+r15*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_e2:
	/* 0xe2: add    rbp,rcx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RBP, X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_e5:
	/* 0xe5: mov    r13d,ebp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R13, X86_RBP, X86_WIDTH_32, 0, 0);
x86_l_e8:
	/* 0xe8: and    r13d,0x3ff */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_ef:
	/* 0xef: cmp    DWORD PTR [r15+r13*1],0x19 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 25ULL);
x86_l_f4:
	/* 0xf4: jae    1e3 <generic_kprobe_filter_arg+0x1e3> */
	X86_SIM_X86_JCC(X86_CC_AE, 0xf4, 0x1e3, x86_l_1e3);
x86_l_fa:
	/* 0xfa: cmp    r13,0x1 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, 0, 1ULL);
x86_l_fe:
	/* 0xfe: je     34a <generic_kprobe_filter_arg+0x34a> */
	X86_SIM_X86_JCC(X86_CC_E, 0xfe, 0x34a, x86_l_34a);
x86_l_104:
	/* 0x104: test   r13d,r13d */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_32, 0, 0);
x86_l_107:
	/* 0x107: jne    32f <generic_kprobe_filter_arg+0x32f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x107, 0x32f, x86_l_32f);
x86_l_10d:
	/* 0x10d: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_112:
	/* 0x112: lea    eax,[rcx+0x1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_115:
	/* 0x115: cmp    eax,0x5 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 5ULL);
x86_l_118:
	/* 0x118: ja     373 <generic_kprobe_filter_arg+0x373> */
	X86_SIM_X86_JCC(X86_CC_A, 0x118, 0x373, x86_l_373);
x86_l_11e:
	/* Capture image-bound code identity before scheduled instructions. */
	switch (X86_SIM_L_READ_REG(X86_RAX) << 2) {
	case 0ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x12eULL); break;
	case 4ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x13aULL); break;
	case 8ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x149ULL); break;
	case 12ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x158ULL); break;
	case 16ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x167ULL); break;
	case 20ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x176ULL); break;
	default: __x86_sim_unresolved_indirect_target();
	}
x86_l_12c:
	/* 0x12c: jmp    rax */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RAX);
		switch (X86_SIM_L_REG_TAG(X86_RAX)) {
		case X86_SIM_TAG_CODE:
			switch (__x86_target) {
			case 0x12eULL: goto x86_l_12e;
			case 0x13aULL: goto x86_l_13a;
			case 0x149ULL: goto x86_l_149;
			case 0x158ULL: goto x86_l_158;
			case 0x167ULL: goto x86_l_167;
			case 0x176ULL: goto x86_l_176;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_12e:
	/* 0x12e: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_130:
	/* 0x130: cmp    BYTE PTR [r14+0x5ec1],0x0 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104183021699072ULL);
x86_l_138:
	/* 0x138: jne    185 <generic_kprobe_filter_arg+0x185> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x138, 0x185, x86_l_185);
x86_l_13a:
	/* 0x13a: mov    eax,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_13f:
	/* 0x13f: cmp    BYTE PTR [r14+0x5ec2],0x0 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104187316666368ULL);
x86_l_147:
	/* 0x147: jne    185 <generic_kprobe_filter_arg+0x185> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x147, 0x185, x86_l_185);
x86_l_149:
	/* 0x149: mov    eax,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_14e:
	/* 0x14e: cmp    BYTE PTR [r14+0x5ec3],0x0 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104191611633664ULL);
x86_l_156:
	/* 0x156: jne    185 <generic_kprobe_filter_arg+0x185> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x156, 0x185, x86_l_185);
x86_l_158:
	/* 0x158: mov    eax,0x3 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 3ULL);
x86_l_15d:
	/* 0x15d: cmp    BYTE PTR [r14+0x5ec4],0x0 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104195906600960ULL);
x86_l_165:
	/* 0x165: jne    185 <generic_kprobe_filter_arg+0x185> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x165, 0x185, x86_l_185);
x86_l_167:
	/* 0x167: mov    eax,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_16c:
	/* 0x16c: cmp    BYTE PTR [r14+0x5ec5],0x0 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104200201568256ULL);
x86_l_174:
	/* 0x174: jne    185 <generic_kprobe_filter_arg+0x185> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x174, 0x185, x86_l_185);
x86_l_176:
	/* 0x176: mov    eax,0x5 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 5ULL);
x86_l_17b:
	/* 0x17b: cmp    BYTE PTR [r14+0x5ec6],0x0 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104204496535552ULL);
x86_l_183:
	/* 0x183: je     1a0 <generic_kprobe_filter_arg+0x1a0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x183, 0x1a0, x86_l_1a0);
x86_l_185:
	/* 0x185: mov    DWORD PTR [r14+0x5f00],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24320ULL);
x86_l_18c:
	/* 0x18c: mov    rsi,QWORD PTR [rip+0x79e0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RSI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)kprobe_calls));
x86_l_193:
	/* 0x193: mov    rdi,rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_196:
	/* 0x196: mov    edx,0x3 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 3ULL);
x86_l_19b:
	/* 0x19b: call   7b80 <__native_link_local_memset_zero_dynamic+0x5917> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_tail_call);
x86_l_1a0:
	/* 0x1a0: mov    rbx,QWORD PTR [r14+0x60] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1a4:
	/* 0x1a4: call   7b89 <__native_link_local_memset_zero_dynamic+0x5920> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_get_current_pid_tgid);
x86_l_1a9:
	/* 0x1a9: mov    QWORD PTR [rsp+0x18],rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1ae:
	/* 0x1ae: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b3:
	/* 0x1b3: mov    rdi,QWORD PTR [rip+0x79e0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)retprobe_map));
x86_l_1ba:
	/* 0x1ba: lea    rsi,[rsp+0x18] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1bf:
	/* 0x1bf: call   7ba4 <__native_link_local_memset_zero_dynamic+0x593b> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_1c4:
	/* 0x1c4: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_1c7:
	/* 0x1c7: je     35e <generic_kprobe_filter_arg+0x35e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1c7, 0x35e, x86_l_35e);
x86_l_1cd:
	/* 0x1cd: mov    rdi,QWORD PTR [rip+0x79e0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)retprobe_map));
x86_l_1d4:
	/* 0x1d4: lea    rsi,[rsp+0x18] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1d9:
	/* 0x1d9: call   7bbe <__native_link_local_memset_zero_dynamic+0x5955> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_delete_elem);
x86_l_1de:
	/* 0x1de: jmp    35e <generic_kprobe_filter_arg+0x35e> */
	X86_SIM_X86_JMP(0x1de, 0x35e, x86_l_35e);
x86_l_1e3:
	/* 0x1e3: lea    rax,[r15+r13*1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_1e7:
	/* 0x1e7: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ec:
	/* 0x1ec: mov    r12d,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_1f2:
	/* 0x1f2: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f7:
	/* 0x1f7: mov    edi,DWORD PTR [rax+r12*4] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 2), 0ULL);
x86_l_1fb:
	/* 0x1fb: test   edi,0x3ff */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 1023ULL);
x86_l_201:
	/* 0x201: je     fa <generic_kprobe_filter_arg+0xfa> */
	X86_SIM_X86_JCC(X86_CC_E, 0x201, 0xfa, x86_l_fa);
x86_l_207:
	/* 0x207: add    edi,ebp */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDI, X86_RBP, X86_WIDTH_32, X86_ALU_ADD, 0);
x86_l_209:
	/* 0x209: and    edi,0x3ff */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_20f:
	/* 0x20f: mov    eax,DWORD PTR [r15+rdi*1+0x4] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 0), 4ULL);
x86_l_214:
	/* 0x214: cmp    eax,0x23 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 35ULL);
x86_l_217:
	/* 0x217: je     10d <generic_kprobe_filter_arg+0x10d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x217, 0x10d, x86_l_10d);
x86_l_21d:
	/* 0x21d: add    rdi,r15 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_220:
	/* 0x220: mov    edx,DWORD PTR [rdi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_222:
	/* 0x222: cmp    rdx,0x4 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, 0, 4ULL);
x86_l_226:
	/* 0x226: ja     10d <generic_kprobe_filter_arg+0x10d> */
	X86_SIM_X86_JCC(X86_CC_A, 0x226, 0x10d, x86_l_10d);
x86_l_22c:
	/* 0x22c: cmp    DWORD PTR [r14+rdx*4+0x5ea0],0x0 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 2), 104041287778304ULL);
x86_l_235:
	/* 0x235: jne    10d <generic_kprobe_filter_arg+0x10d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x235, 0x10d, x86_l_10d);
x86_l_23b:
	/* 0x23b: mov    ecx,DWORD PTR [rdi+0xc] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_23e:
	/* 0x23e: dec    ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_240:
	/* 0x240: cmp    ecx,0x2b */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 43ULL);
x86_l_243:
	/* 0x243: ja     30a <generic_kprobe_filter_arg+0x30a> */
	X86_SIM_X86_JCC(X86_CC_A, 0x243, 0x30a, x86_l_30a);
x86_l_249:
	/* 0x249: mov    rdx,QWORD PTR [r14+rdx*8+0x5e78] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 3), 24184ULL);
x86_l_251:
	/* 0x251: and    edx,0x7ff */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_257:
	/* 0x257: lea    rsi,[r14+rdx*1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_25b:
	/* 0x25b: add    rsi,0x90 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_262:
	/* Capture image-bound code identity before scheduled instructions. */
	switch (X86_SIM_L_READ_REG(X86_RCX) << 2) {
	case 0ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x272ULL); break;
	case 4ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x323ULL); break;
	case 8ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x30aULL); break;
	case 12ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x272ULL); break;
	case 16ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x292ULL); break;
	case 20ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x2deULL); break;
	case 24ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x292ULL); break;
	case 28ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x30aULL); break;
	case 32ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x30aULL); break;
	case 36ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x272ULL); break;
	case 40ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x272ULL); break;
	case 44ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x272ULL); break;
	case 48ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x272ULL); break;
	case 52ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x30aULL); break;
	case 56ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x2fcULL); break;
	case 60ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x2fcULL); break;
	case 64ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x2f8ULL); break;
	case 68ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x30aULL); break;
	case 72ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x30aULL); break;
	case 76ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x30aULL); break;
	case 80ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x30aULL); break;
	case 84ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x30aULL); break;
	case 88ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x30aULL); break;
	case 92ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x30aULL); break;
	case 96ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x30aULL); break;
	case 100ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x30aULL); break;
	case 104ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x30aULL); break;
	case 108ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x272ULL); break;
	case 112ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x272ULL); break;
	case 116ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x272ULL); break;
	case 120ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x272ULL); break;
	case 124ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x272ULL); break;
	case 128ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x272ULL); break;
	case 132ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x272ULL); break;
	case 136ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x272ULL); break;
	case 140ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x272ULL); break;
	case 144ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x2fcULL); break;
	case 148ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x2deULL); break;
	case 152ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x2deULL); break;
	case 156ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x292ULL); break;
	case 160ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x292ULL); break;
	case 164ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x2fcULL); break;
	case 168ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x30aULL); break;
	case 172ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x31cULL); break;
	default: __x86_sim_unresolved_indirect_target();
	}
x86_l_270:
	/* 0x270: jmp    rdx */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RDX);
		switch (X86_SIM_L_REG_TAG(X86_RDX)) {
		case X86_SIM_TAG_CODE:
			switch (__x86_target) {
			case 0x272ULL: goto x86_l_272;
			case 0x292ULL: goto x86_l_292;
			case 0x2deULL: goto x86_l_2de;
			case 0x2f8ULL: goto x86_l_2f8;
			case 0x2fcULL: goto x86_l_2fc;
			case 0x30aULL: goto x86_l_30a;
			case 0x31cULL: goto x86_l_31c;
			case 0x323ULL: goto x86_l_323;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_272:
	/* 0x272: cmp    ecx,0x23 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 35ULL);
x86_l_275:
	/* 0x275: ja     30a <generic_kprobe_filter_arg+0x30a> */
	X86_SIM_X86_JCC(X86_CC_A, 0x275, 0x30a, x86_l_30a);
x86_l_27b:
	/* Capture image-bound code identity before scheduled instructions. */
	switch (X86_SIM_L_READ_REG(X86_RCX) << 2) {
	case 0ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x28bULL); break;
	case 4ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x30aULL); break;
	case 8ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x30aULL); break;
	case 12ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x28bULL); break;
	case 16ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x30aULL); break;
	case 20ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x30aULL); break;
	case 24ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x30aULL); break;
	case 28ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x30aULL); break;
	case 32ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x30aULL); break;
	case 36ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x2d7ULL); break;
	case 40ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x2d7ULL); break;
	case 44ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x28bULL); break;
	case 48ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x28bULL); break;
	case 52ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x30aULL); break;
	case 56ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x30aULL); break;
	case 60ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x30aULL); break;
	case 64ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x30aULL); break;
	case 68ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x30aULL); break;
	case 72ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x30aULL); break;
	case 76ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x30aULL); break;
	case 80ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x30aULL); break;
	case 84ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x30aULL); break;
	case 88ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x30aULL); break;
	case 92ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x30aULL); break;
	case 96ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x30aULL); break;
	case 100ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x30aULL); break;
	case 104ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x30aULL); break;
	case 108ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x2d7ULL); break;
	case 112ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x2f1ULL); break;
	case 116ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x2f1ULL); break;
	case 120ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x2eaULL); break;
	case 124ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x2eaULL); break;
	case 128ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x299ULL); break;
	case 132ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x299ULL); break;
	case 136ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x299ULL); break;
	case 140ULL: X86_SIM_X86_CODE_ADDRESS(X86_RCX, 0x299ULL); break;
	default: __x86_sim_unresolved_indirect_target();
	}
x86_l_289:
	/* 0x289: jmp    rcx */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RCX);
		switch (X86_SIM_L_REG_TAG(X86_RCX)) {
		case X86_SIM_TAG_CODE:
			switch (__x86_target) {
			case 0x28bULL: goto x86_l_28b;
			case 0x299ULL: goto x86_l_299;
			case 0x2d7ULL: goto x86_l_2d7;
			case 0x2eaULL: goto x86_l_2ea;
			case 0x2f1ULL: goto x86_l_2f1;
			case 0x30aULL: goto x86_l_30a;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_28b:
	/* 0x28b: call   0 <generic_kprobe_filter_arg> */
	X86_SIM_X86_CALL(x86_l_381, 0x290ULL);
x86_l_290:
	/* 0x290: jmp    301 <generic_kprobe_filter_arg+0x301> */
	X86_SIM_X86_JMP(0x290, 0x301, x86_l_301);
x86_l_292:
	/* 0x292: call   0 <generic_kprobe_filter_arg> */
	X86_SIM_X86_CALL(x86_l_3c2, 0x297ULL);
x86_l_297:
	/* 0x297: jmp    301 <generic_kprobe_filter_arg+0x301> */
	X86_SIM_X86_JMP(0x297, 0x301, x86_l_301);
x86_l_299:
	/* 0x299: cmp    eax,0x1e */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 30ULL);
x86_l_29c:
	/* 0x29c: jne    2d7 <generic_kprobe_filter_arg+0x2d7> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x29c, 0x2d7, x86_l_2d7);
x86_l_29e:
	/* 0x29e: mov    eax,DWORD PTR [rdi+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a1:
	/* 0x2a1: and    eax,0x7 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_2a4:
	/* 0x2a4: mov    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_2a6:
	/* 0x2a6: cmp    DWORD PTR [r14+rcx*4+0x5ea0],0x0 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 104041287778304ULL);
x86_l_2af:
	/* 0x2af: jne    10d <generic_kprobe_filter_arg+0x10d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2af, 0x10d, x86_l_10d);
x86_l_2b5:
	/* 0x2b5: mov    rcx,QWORD PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b8:
	/* 0x2b8: mov    rdx,QWORD PTR [r14+rax*8+0x5e78] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_2c0:
	/* 0x2c0: and    edx,0x7ff */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_2c6:
	/* 0x2c6: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_2c8:
	/* 0x2c8: andn   rcx,rcx,QWORD PTR [r14+rdx*1+0x90] */
	X86_SIM_RUN_OP(X86_OP_ANDN_MEM, X86_RCX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_RDX, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_R14)), 618475290624ULL);
x86_l_2d2:
	/* 0x2d2: setne  al */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_CC_NE, 0);
x86_l_2d5:
	/* 0x2d5: jmp    301 <generic_kprobe_filter_arg+0x301> */
	X86_SIM_X86_JMP(0x2d5, 0x301, x86_l_301);
x86_l_2d7:
	/* 0x2d7: call   0 <generic_kprobe_filter_arg> */
	X86_SIM_X86_CALL(x86_l_619, 0x2dcULL);
x86_l_2dc:
	/* 0x2dc: jmp    301 <generic_kprobe_filter_arg+0x301> */
	X86_SIM_X86_JMP(0x2dc, 0x301, x86_l_301);
x86_l_2de:
	/* 0x2de: mov    edx,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_2e3:
	/* 0x2e3: call   0 <generic_kprobe_filter_arg> */
	X86_SIM_X86_CALL(x86_l_65a, 0x2e8ULL);
x86_l_2e8:
	/* 0x2e8: jmp    301 <generic_kprobe_filter_arg+0x301> */
	X86_SIM_X86_JMP(0x2e8, 0x301, x86_l_301);
x86_l_2ea:
	/* 0x2ea: call   0 <generic_kprobe_filter_arg> */
	X86_SIM_X86_CALL(x86_l_6e3, 0x2efULL);
x86_l_2ef:
	/* 0x2ef: jmp    301 <generic_kprobe_filter_arg+0x301> */
	X86_SIM_X86_JMP(0x2ef, 0x301, x86_l_301);
x86_l_2f1:
	/* 0x2f1: call   0 <generic_kprobe_filter_arg> */
	X86_SIM_X86_CALL(x86_l_724, 0x2f6ULL);
x86_l_2f6:
	/* 0x2f6: jmp    301 <generic_kprobe_filter_arg+0x301> */
	X86_SIM_X86_JMP(0x2f6, 0x301, x86_l_301);
x86_l_2f8:
	/* 0x2f8: add    rsi,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2fc:
	/* 0x2fc: call   0 <generic_kprobe_filter_arg> */
	X86_SIM_X86_CALL(x86_l_765, 0x301ULL);
x86_l_301:
	/* 0x301: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_304:
	/* 0x304: je     10d <generic_kprobe_filter_arg+0x10d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x304, 0x10d, x86_l_10d);
x86_l_30a:
	/* 0x30a: inc    r12 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_30d:
	/* 0x30d: cmp    r12,0x6 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, 0, 6ULL);
x86_l_311:
	/* 0x311: jne    1f2 <generic_kprobe_filter_arg+0x1f2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x311, 0x1f2, x86_l_1f2);
x86_l_317:
	/* 0x317: jmp    fa <generic_kprobe_filter_arg+0xfa> */
	X86_SIM_X86_JMP(0x317, 0xfa, x86_l_fa);
x86_l_31c:
	/* 0x31c: call   0 <generic_kprobe_filter_arg> */
	X86_SIM_X86_CALL(x86_l_7ec, 0x321ULL);
x86_l_321:
	/* 0x321: jmp    301 <generic_kprobe_filter_arg+0x301> */
	X86_SIM_X86_JMP(0x321, 0x301, x86_l_301);
x86_l_323:
	/* 0x323: mov    edx,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_328:
	/* 0x328: call   0 <generic_kprobe_filter_arg> */
	X86_SIM_X86_CALL(x86_l_65a, 0x32dULL);
x86_l_32d:
	/* 0x32d: jmp    301 <generic_kprobe_filter_arg+0x301> */
	X86_SIM_X86_JMP(0x32d, 0x301, x86_l_301);
x86_l_32f:
	/* 0x32f: mov    DWORD PTR [r14+0x5f04],r13d */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24324ULL);
x86_l_336:
	/* 0x336: mov    rsi,QWORD PTR [rip+0x79ef] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RSI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)kprobe_calls));
x86_l_33d:
	/* 0x33d: mov    rdi,rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_340:
	/* 0x340: mov    edx,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_345:
	/* 0x345: call   7d39 <__native_link_local_memset_zero_dynamic+0x5ad0> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_tail_call);
x86_l_34a:
	/* 0x34a: mov    rsi,QWORD PTR [rip+0x79ef] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RSI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)kprobe_calls));
x86_l_351:
	/* 0x351: mov    rdi,rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_354:
	/* 0x354: mov    edx,0x5 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 5ULL);
x86_l_359:
	/* 0x359: call   7d4d <__native_link_local_memset_zero_dynamic+0x5ae4> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_tail_call);
x86_l_35e:
	/* 0x35e: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_360:
	/* 0x360: add    rsp,0x28 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_364:
	/* 0x364: pop    rbx */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_365:
	/* 0x365: pop    r12 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R12, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_367:
	/* 0x367: pop    r13 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R13, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_369:
	/* 0x369: pop    r14 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R14, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_36b:
	/* 0x36b: pop    r15 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R15, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_36d:
	/* 0x36d: pop    rbp */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBP, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_36e:
	/* 0x36e: jmp    22e7 <__native_link_local_memset_zero_dynamic+0x7e> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_373:
	/* 0x373: cmp    ecx,0x4 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_376:
	/* 0x376: jle    185 <generic_kprobe_filter_arg+0x185> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x376, 0x185, x86_l_185);
x86_l_37c:
	/* 0x37c: jmp    1a0 <generic_kprobe_filter_arg+0x1a0> */
	X86_SIM_X86_JMP(0x37c, 0x1a0, x86_l_1a0);
x86_l_22e7:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
	/* native subroutine native_link_sub_381 */
x86_l_381:
	/* 0x381: mov    eax,DWORD PTR [rdi+0x4] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_384:
	/* 0x384: cmp    rax,0x20 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, 0, 32ULL);
x86_l_388:
	/* 0x388: ja     3bf <filter_32ty+0x3e> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x388, 0x3bf, x86_l_3bf);
x86_l_38a:
	/* 0x38a: mov    ecx,0x101e */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 4126ULL);
x86_l_38f:
	/* 0x38f: bt     rcx,rax */
	X86_SIM_RUN_OP(X86_OP_BT, X86_RCX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_393:
	/* 0x393: jae    39a <filter_32ty+0x19> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x393, 0x39a, x86_l_39a);
x86_l_395:
	/* 0x395: jmp    1ede <filter_32ty_selector_val> */
	X86_SIM_X86_SUB_JMP(0x395, 0x1ede, x86_l_1ede);
x86_l_39a:
	/* 0x39a: mov    ecx,0xc00 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 3072ULL);
x86_l_39f:
	/* 0x39f: bt     rcx,rax */
	X86_SIM_RUN_OP(X86_OP_BT, X86_RCX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_3a3:
	/* 0x3a3: jae    3aa <filter_32ty+0x29> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x3a3, 0x3aa, x86_l_3aa);
x86_l_3a5:
	/* 0x3a5: jmp    df0 <filter_32ty_map> */
	X86_SIM_X86_SUB_JMP(0x3a5, 0xdf0, x86_l_df0);
x86_l_3aa:
	/* 0x3aa: movabs rcx,0x180000000 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, 0, 6442450944ULL);
x86_l_3b4:
	/* 0x3b4: bt     rcx,rax */
	X86_SIM_RUN_OP(X86_OP_BT, X86_RCX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_3b8:
	/* 0x3b8: jae    3bf <filter_32ty+0x3e> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x3b8, 0x3bf, x86_l_3bf);
x86_l_3ba:
	/* 0x3ba: jmp    20b3 <filter_32ty_range> */
	X86_SIM_X86_SUB_JMP(0x3ba, 0x20b3, x86_l_20b3);
x86_l_3bf:
	/* 0x3bf: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_3c1:
	/* 0x3c1: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_3c1);

	/* native subroutine native_link_sub_3c2 */
x86_l_3c2:
	/* 0x3c2: push   r15 */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_3c4:
	/* 0x3c4: push   r14 */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_3c6:
	/* 0x3c6: push   r12 */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_3c8:
	/* 0x3c8: push   rbx */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_3c9:
	/* 0x3c9: sub    rsp,0x48 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SUB, 72ULL);
x86_l_3cd:
	/* 0x3cd: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_3d6:
	/* 0x3d6: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_3df:
	/* 0x3df: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_3e8:
	/* 0x3e8: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_3f1:
	/* 0x3f1: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_3fa:
	/* 0x3fa: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_401:
	/* 0x401: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_409:
	/* 0x409: mov    ecx,DWORD PTR [rdi+0xc] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_40c:
	/* 0x40c: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_40e:
	/* 0x40e: lea    edx,[rcx-0x5] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551611ULL);
x86_l_411:
	/* 0x411: cmp    edx,0x24 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 36ULL);
x86_l_414:
	/* 0x414: ja     5d5 <filter_inet+0x213> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x414, 0x5d5, x86_l_5d5);
x86_l_41a:
	/* Capture image-bound code identity before scheduled instructions. */
	switch (X86_SIM_L_READ_REG(X86_RDX) << 2) {
	case 0ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x457ULL); break;
	case 4ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x5d5ULL); break;
	case 8ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x42aULL); break;
	case 12ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x5d5ULL); break;
	case 16ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x5d5ULL); break;
	case 20ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x5d5ULL); break;
	case 24ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x5d5ULL); break;
	case 28ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x5d5ULL); break;
	case 32ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x5d5ULL); break;
	case 36ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x5d5ULL); break;
	case 40ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x5d5ULL); break;
	case 44ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x5d5ULL); break;
	case 48ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x5d5ULL); break;
	case 52ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x5d5ULL); break;
	case 56ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x5d5ULL); break;
	case 60ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x5d5ULL); break;
	case 64ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x5d5ULL); break;
	case 68ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x5d5ULL); break;
	case 72ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x5d5ULL); break;
	case 76ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x5d5ULL); break;
	case 80ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x5d5ULL); break;
	case 84ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x5d5ULL); break;
	case 88ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x5d5ULL); break;
	case 92ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x5d5ULL); break;
	case 96ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x5d5ULL); break;
	case 100ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x5d5ULL); break;
	case 104ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x5d5ULL); break;
	case 108ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x5d5ULL); break;
	case 112ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x5d5ULL); break;
	case 116ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x5d5ULL); break;
	case 120ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x5d5ULL); break;
	case 124ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x5d5ULL); break;
	case 128ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x5d5ULL); break;
	case 132ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x5d5ULL); break;
	case 136ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x5d5ULL); break;
	case 140ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x42fULL); break;
	case 144ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x42aULL); break;
	default: __x86_sim_unresolved_indirect_target();
	}
x86_l_428:
	/* 0x428: jmp    rdx */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RDX);
		switch (X86_SIM_L_REG_TAG(X86_RDX)) {
		case X86_SIM_TAG_CODE:
			switch (__x86_target) {
			case 0x42aULL: goto x86_l_42a;
			case 0x42fULL: goto x86_l_42f;
			case 0x457ULL: goto x86_l_457;
			case 0x5d5ULL: goto x86_l_5d5;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_42a:
	/* 0x42a: mov    r8,rsi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R8, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_42d:
	/* 0x42d: jmp    45a <filter_inet+0x98> */
	X86_SIM_X86_SUB_JMP(0x42d, 0x45a, x86_l_45a);
x86_l_42f:
	/* 0x42f: movzx  eax,WORD PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_432:
	/* 0x432: mov    WORD PTR [rsp+0x46],ax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 70ULL);
x86_l_437:
	/* 0x437: movzx  eax,WORD PTR [rsi+0x2] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_43b:
	/* 0x43b: mov    WORD PTR [rsp+0x40],ax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_440:
	/* 0x440: mov    rax,QWORD PTR [rsi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_444:
	/* 0x444: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_449:
	/* 0x449: mov    rax,QWORD PTR [rsi+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_44d:
	/* 0x44d: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_452:
	/* 0x452: lea    rsi,[rsp+0x20] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_457:
	/* 0x457: xor    r8d,r8d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_45a:
	/* 0x45a: mov    edx,DWORD PTR [rdi+0x4] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_45d:
	/* 0x45d: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_45f:
	/* 0x45f: add    edx,0xfffffff3 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 4294967283ULL);
x86_l_462:
	/* 0x462: cmp    edx,0x10 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 16ULL);
x86_l_465:
	/* 0x465: ja     5d5 <filter_inet+0x213> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x465, 0x5d5, x86_l_5d5);
x86_l_46b:
	/* Capture image-bound code identity before scheduled instructions. */
	switch (X86_SIM_L_READ_REG(X86_RDX) << 2) {
	case 0ULL: X86_SIM_X86_CODE_ADDRESS(X86_R10, 0x4a6ULL); break;
	case 4ULL: X86_SIM_X86_CODE_ADDRESS(X86_R10, 0x49cULL); break;
	case 8ULL: X86_SIM_X86_CODE_ADDRESS(X86_R10, 0x47cULL); break;
	case 12ULL: X86_SIM_X86_CODE_ADDRESS(X86_R10, 0x482ULL); break;
	case 16ULL: X86_SIM_X86_CODE_ADDRESS(X86_R10, 0x5b4ULL); break;
	case 20ULL: X86_SIM_X86_CODE_ADDRESS(X86_R10, 0x47cULL); break;
	case 24ULL: X86_SIM_X86_CODE_ADDRESS(X86_R10, 0x482ULL); break;
	case 28ULL: X86_SIM_X86_CODE_ADDRESS(X86_R10, 0x47cULL); break;
	case 32ULL: X86_SIM_X86_CODE_ADDRESS(X86_R10, 0x47cULL); break;
	case 36ULL: X86_SIM_X86_CODE_ADDRESS(X86_R10, 0x482ULL); break;
	case 40ULL: X86_SIM_X86_CODE_ADDRESS(X86_R10, 0x482ULL); break;
	case 44ULL: X86_SIM_X86_CODE_ADDRESS(X86_R10, 0x4a6ULL); break;
	case 48ULL: X86_SIM_X86_CODE_ADDRESS(X86_R10, 0x49cULL); break;
	case 52ULL: X86_SIM_X86_CODE_ADDRESS(X86_R10, 0x5d5ULL); break;
	case 56ULL: X86_SIM_X86_CODE_ADDRESS(X86_R10, 0x5d5ULL); break;
	case 60ULL: X86_SIM_X86_CODE_ADDRESS(X86_R10, 0x5c6ULL); break;
	case 64ULL: X86_SIM_X86_CODE_ADDRESS(X86_R10, 0x5baULL); break;
	default: __x86_sim_unresolved_indirect_target();
	}
x86_l_479:
	/* 0x479: jmp    r10 */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_R10);
		switch (X86_SIM_L_REG_TAG(X86_R10)) {
		case X86_SIM_TAG_CODE:
			switch (__x86_target) {
			case 0x47cULL: goto x86_l_47c;
			case 0x482ULL: goto x86_l_482;
			case 0x49cULL: goto x86_l_49c;
			case 0x4a6ULL: goto x86_l_4a6;
			case 0x5b4ULL: goto x86_l_5b4;
			case 0x5baULL: goto x86_l_5ba;
			case 0x5c6ULL: goto x86_l_5c6;
			case 0x5d5ULL: goto x86_l_5d5;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_47c:
	/* 0x47c: movzx  ecx,WORD PTR [rsi+0x20] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_480:
	/* 0x480: jmp    486 <filter_inet+0xc4> */
	X86_SIM_X86_SUB_JMP(0x480, 0x486, x86_l_486);
x86_l_482:
	/* 0x482: movzx  ecx,WORD PTR [rsi+0x22] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_486:
	/* 0x486: mov    DWORD PTR [rsp+0x4],ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_48a:
	/* 0x48a: xor    ebx,ebx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_48c:
	/* 0x48c: xor    r15d,r15d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_48f:
	/* 0x48f: xor    r14d,r14d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_492:
	/* 0x492: cmp    edx,0xc */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 12ULL);
x86_l_495:
	/* 0x495: jbe    4bf <filter_inet+0xfd> */
	X86_SIM_X86_SUB_JCC(X86_CC_BE, 0x495, 0x4bf, x86_l_4bf);
x86_l_497:
	/* 0x497: jmp    615 <filter_inet+0x253> */
	X86_SIM_X86_SUB_JMP(0x497, 0x615, x86_l_615);
x86_l_49c:
	/* 0x49c: mov    rbx,QWORD PTR [rsi+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4a0:
	/* 0x4a0: mov    r14,QWORD PTR [rsi+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4a4:
	/* 0x4a4: jmp    4ad <filter_inet+0xeb> */
	X86_SIM_X86_SUB_JMP(0x4a4, 0x4ad, x86_l_4ad);
x86_l_4a6:
	/* 0x4a6: mov    rbx,QWORD PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4a9:
	/* 0x4a9: mov    r14,QWORD PTR [rsi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ad:
	/* 0x4ad: mov    r15,rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R15, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_4b0:
	/* 0x4b0: shr    r15,0x20 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_4b4:
	/* 0x4b4: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_4b6:
	/* 0x4b6: cmp    edx,0xc */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 12ULL);
x86_l_4b9:
	/* 0x4b9: ja     615 <filter_inet+0x253> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x4b9, 0x615, x86_l_615);
x86_l_4bf:
	/* Capture image-bound code identity before scheduled instructions. */
	switch (X86_SIM_L_READ_REG(X86_RDX) << 2) {
	case 0ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x4cfULL); break;
	case 4ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x4cfULL); break;
	case 8ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x513ULL); break;
	case 12ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x513ULL); break;
	case 16ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x5cdULL); break;
	case 20ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x513ULL); break;
	case 24ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x513ULL); break;
	case 28ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x51dULL); break;
	case 32ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x52dULL); break;
	case 36ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x51dULL); break;
	case 40ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x52dULL); break;
	case 44ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x4cfULL); break;
	case 48ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x4cfULL); break;
	default: __x86_sim_unresolved_indirect_target();
	}
x86_l_4cd:
	/* 0x4cd: jmp    rdx */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RDX);
		switch (X86_SIM_L_REG_TAG(X86_RDX)) {
		case X86_SIM_TAG_CODE:
			switch (__x86_target) {
			case 0x4cfULL: goto x86_l_4cf;
			case 0x513ULL: goto x86_l_513;
			case 0x51dULL: goto x86_l_51d;
			case 0x52dULL: goto x86_l_52d;
			case 0x5cdULL: goto x86_l_5cd;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_4cf:
	/* 0x4cf: movzx  eax,WORD PTR [rsi+0x26] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_4d3:
	/* 0x4d3: cmp    eax,0xa */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 10ULL);
x86_l_4d6:
	/* 0x4d6: je     53d <filter_inet+0x17b> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x4d6, 0x53d, x86_l_53d);
x86_l_4d8:
	/* 0x4d8: cmp    eax,0x2 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_4db:
	/* 0x4db: jne    5ad <filter_inet+0x1eb> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x4db, 0x5ad, x86_l_5ad);
x86_l_4e1:
	/* 0x4e1: mov    r12,rdi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R12, X86_RDI, X86_WIDTH_64, 0, 0);
x86_l_4e4:
	/* 0x4e4: mov    eax,DWORD PTR [rdi+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4e7:
	/* 0x4e7: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4eb:
	/* 0x4eb: mov    rdi,QWORD PTR [rip+0x1bd0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)addr4lpm_maps));
x86_l_4f2:
	/* 0x4f2: lea    rsi,[rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4f7:
	/* 0x4f7: call   20cc <filter_32ty_range+0x19> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_4fc:
	/* 0x4fc: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_4ff:
	/* 0x4ff: je     5e1 <filter_inet+0x21f> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x4ff, 0x5e1, x86_l_5e1);
x86_l_505:
	/* 0x505: mov    DWORD PTR [rsp+0xc],0x20 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607584ULL);
x86_l_50d:
	/* 0x50d: mov    DWORD PTR [rsp+0x10],ebx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_511:
	/* 0x511: jmp    580 <filter_inet+0x1be> */
	X86_SIM_X86_SUB_JMP(0x511, 0x580, x86_l_580);
x86_l_513:
	/* 0x513: lea    rsi,[rsp+0x4] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_518:
	/* 0x518: jmp    5d0 <filter_inet+0x20e> */
	X86_SIM_X86_SUB_JMP(0x518, 0x5d0, x86_l_5d0);
x86_l_51d:
	/* 0x51d: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_51f:
	/* 0x51f: cmp    ecx,0x400 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 1024ULL);
x86_l_525:
	/* 0x525: setb   al */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_CC_B, 0);
x86_l_528:
	/* 0x528: jmp    5d5 <filter_inet+0x213> */
	X86_SIM_X86_SUB_JMP(0x528, 0x5d5, x86_l_5d5);
x86_l_52d:
	/* 0x52d: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_52f:
	/* 0x52f: cmp    ecx,0x400 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 1024ULL);
x86_l_535:
	/* 0x535: setae  al */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_CC_AE, 0);
x86_l_538:
	/* 0x538: jmp    5d5 <filter_inet+0x213> */
	X86_SIM_X86_SUB_JMP(0x538, 0x5d5, x86_l_5d5);
x86_l_53d:
	/* 0x53d: mov    r12,rdi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R12, X86_RDI, X86_WIDTH_64, 0, 0);
x86_l_540:
	/* 0x540: mov    eax,DWORD PTR [rdi+0x14] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_543:
	/* 0x543: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_547:
	/* 0x547: mov    rdi,QWORD PTR [rip+0x1bd0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)addr6lpm_maps));
x86_l_54e:
	/* 0x54e: lea    rsi,[rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_553:
	/* 0x553: call   2128 <filter_32ty_range+0x75> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_558:
	/* 0x558: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_55b:
	/* 0x55b: je     5e1 <filter_inet+0x21f> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x55b, 0x5e1, x86_l_5e1);
x86_l_561:
	/* 0x561: mov    DWORD PTR [rsp+0xc],0x80 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607680ULL);
x86_l_569:
	/* 0x569: mov    DWORD PTR [rsp+0x10],ebx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_56d:
	/* 0x56d: mov    DWORD PTR [rsp+0x14],r15d */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_572:
	/* 0x572: mov    DWORD PTR [rsp+0x18],r14d */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_577:
	/* 0x577: shr    r14,0x20 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_57b:
	/* 0x57b: mov    DWORD PTR [rsp+0x1c],r14d */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_580:
	/* 0x580: lea    rsi,[rsp+0xc] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_585:
	/* 0x585: mov    rdi,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_588:
	/* 0x588: call   215d <filter_32ty_range+0xaa> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_58d:
	/* 0x58d: mov    ecx,DWORD PTR [r12+0x4] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_592:
	/* 0x592: lea    edx,[rcx-0x18] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551592ULL);
x86_l_595:
	/* 0x595: cmp    edx,0x2 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_598:
	/* 0x598: jb     5ee <filter_inet+0x22c> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x598, 0x5ee, x86_l_5ee);
x86_l_59a:
	/* 0x59a: add    ecx,0xfffffff3 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 4294967283ULL);
x86_l_59d:
	/* 0x59d: cmp    ecx,0x1 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_5a0:
	/* 0x5a0: ja     5ad <filter_inet+0x1eb> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x5a0, 0x5ad, x86_l_5ad);
x86_l_5a2:
	/* 0x5a2: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_5a5:
	/* 0x5a5: setne  al */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_CC_NE, 0);
x86_l_5a8:
	/* 0x5a8: movzx  eax,al */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8, 0);
x86_l_5ab:
	/* 0x5ab: jmp    5d5 <filter_inet+0x213> */
	X86_SIM_X86_SUB_JMP(0x5ab, 0x5d5, x86_l_5d5);
x86_l_5ad:
	/* 0x5ad: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_5af:
	/* 0x5af: movzx  eax,al */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8, 0);
x86_l_5b2:
	/* 0x5b2: jmp    5d5 <filter_inet+0x213> */
	X86_SIM_X86_SUB_JMP(0x5b2, 0x5d5, x86_l_5d5);
x86_l_5b4:
	/* 0x5b4: movzx  eax,WORD PTR [rsi+0x24] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_5b8:
	/* 0x5b8: jmp    5ca <filter_inet+0x208> */
	X86_SIM_X86_SUB_JMP(0x5b8, 0x5ca, x86_l_5ca);
x86_l_5ba:
	/* 0x5ba: cmp    ecx,0x7 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 7ULL);
x86_l_5bd:
	/* 0x5bd: jne    5f9 <filter_inet+0x237> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x5bd, 0x5f9, x86_l_5f9);
x86_l_5bf:
	/* 0x5bf: test   r8,r8 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R8, X86_R8, X86_WIDTH_64, 0, 0);
x86_l_5c2:
	/* 0x5c2: jne    603 <filter_inet+0x241> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x5c2, 0x603, x86_l_603);
x86_l_5c4:
	/* 0x5c4: jmp    5cd <filter_inet+0x20b> */
	X86_SIM_X86_SUB_JMP(0x5c4, 0x5cd, x86_l_5cd);
x86_l_5c6:
	/* 0x5c6: movzx  eax,WORD PTR [rsi+0x26] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_5ca:
	/* 0x5ca: mov    DWORD PTR [rsp],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5cd:
	/* 0x5cd: mov    rsi,rsp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_RSP, X86_WIDTH_64, 0, 0);
x86_l_5d0:
	/* 0x5d0: call   df0 <filter_32ty_map> */
	X86_SIM_X86_CALL(x86_l_df0, 0x5d5ULL);
x86_l_5d5:
	/* 0x5d5: add    rsp,0x48 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 72ULL);
x86_l_5d9:
	/* 0x5d9: pop    rbx */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_5da:
	/* 0x5da: pop    r12 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R12, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_5dc:
	/* 0x5dc: pop    r14 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R14, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_5de:
	/* 0x5de: pop    r15 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R15, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_5e0:
	/* 0x5e0: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_5e0);
x86_l_5e1:
	/* 0x5e1: mov    eax,DWORD PTR [r12+0x4] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_5e6:
	/* 0x5e6: and    eax,0xfffffffe */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_5e9:
	/* 0x5e9: cmp    eax,0x18 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 24ULL);
x86_l_5ec:
	/* 0x5ec: jmp    5f1 <filter_inet+0x22f> */
	X86_SIM_X86_SUB_JMP(0x5ec, 0x5f1, x86_l_5f1);
x86_l_5ee:
	/* 0x5ee: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_5f1:
	/* 0x5f1: sete   al */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_CC_E, 0);
x86_l_5f4:
	/* 0x5f4: movzx  eax,al */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8, 0);
x86_l_5f7:
	/* 0x5f7: jmp    5d5 <filter_inet+0x213> */
	X86_SIM_X86_SUB_JMP(0x5f7, 0x5d5, x86_l_5d5);
x86_l_5f9:
	/* 0x5f9: cmp    ecx,0x29 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 41ULL);
x86_l_5fc:
	/* 0x5fc: jne    60b <filter_inet+0x249> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x5fc, 0x60b, x86_l_60b);
x86_l_5fe:
	/* 0x5fe: test   r8,r8 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R8, X86_R8, X86_WIDTH_64, 0, 0);
x86_l_601:
	/* 0x601: je     60b <filter_inet+0x249> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x601, 0x60b, x86_l_60b);
x86_l_603:
	/* 0x603: movzx  eax,BYTE PTR [r8+0x3a] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R8, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 58ULL);
x86_l_608:
	/* 0x608: mov    DWORD PTR [rsp],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_60b:
	/* 0x60b: cmp    ecx,0x29 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 41ULL);
x86_l_60e:
	/* 0x60e: je     5cd <filter_inet+0x20b> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x60e, 0x5cd, x86_l_5cd);
x86_l_610:
	/* 0x610: cmp    ecx,0x7 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 7ULL);
x86_l_613:
	/* 0x613: je     5cd <filter_inet+0x20b> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x613, 0x5cd, x86_l_5cd);
x86_l_615:
	/* 0x615: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_617:
	/* 0x617: jmp    5d5 <filter_inet+0x213> */
	X86_SIM_X86_SUB_JMP(0x617, 0x5d5, x86_l_5d5);

	/* native subroutine native_link_sub_619 */
x86_l_619:
	/* 0x619: mov    eax,DWORD PTR [rdi+0x4] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_61c:
	/* 0x61c: cmp    rax,0x20 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, 0, 32ULL);
x86_l_620:
	/* 0x620: ja     657 <filter_64ty+0x3e> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x620, 0x657, x86_l_657);
x86_l_622:
	/* 0x622: mov    ecx,0x101e */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 4126ULL);
x86_l_627:
	/* 0x627: bt     rcx,rax */
	X86_SIM_RUN_OP(X86_OP_BT, X86_RCX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_62b:
	/* 0x62b: jae    632 <filter_64ty+0x19> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x62b, 0x632, x86_l_632);
x86_l_62d:
	/* 0x62d: jmp    1a98 <filter_64ty_selector_val> */
	X86_SIM_X86_SUB_JMP(0x62d, 0x1a98, x86_l_1a98);
x86_l_632:
	/* 0x632: mov    ecx,0xc00 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 3072ULL);
x86_l_637:
	/* 0x637: bt     rcx,rax */
	X86_SIM_RUN_OP(X86_OP_BT, X86_RCX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_63b:
	/* 0x63b: jae    642 <filter_64ty+0x29> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x63b, 0x642, x86_l_642);
x86_l_63d:
	/* 0x63d: jmp    1c8f <filter_64ty_map> */
	X86_SIM_X86_SUB_JMP(0x63d, 0x1c8f, x86_l_1c8f);
x86_l_642:
	/* 0x642: movabs rcx,0x180000000 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, 0, 6442450944ULL);
x86_l_64c:
	/* 0x64c: bt     rcx,rax */
	X86_SIM_RUN_OP(X86_OP_BT, X86_RCX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_650:
	/* 0x650: jae    657 <filter_64ty+0x3e> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x650, 0x657, x86_l_657);
x86_l_652:
	/* 0x652: jmp    1d03 <filter_64ty_range> */
	X86_SIM_X86_SUB_JMP(0x652, 0x1d03, x86_l_1d03);
x86_l_657:
	/* 0x657: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_659:
	/* 0x659: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_659);

	/* native subroutine native_link_sub_65a */
x86_l_65a:
	/* 0x65a: push   rbx */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_65b:
	/* 0x65b: mov    rbx,rdi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RBX, X86_RDI, X86_WIDTH_64, 0, 0);
x86_l_65e:
	/* 0x65e: mov    edi,DWORD PTR [rdi+0x4] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_661:
	/* 0x661: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_663:
	/* 0x663: lea    r8d,[rdi-0x3] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R8, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_667:
	/* 0x667: cmp    r8d,0x1f */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, 0, 31ULL);
x86_l_66b:
	/* 0x66b: ja     6bf <filter_char_buf+0x65> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x66b, 0x6bf, x86_l_6bf);
x86_l_66d:
	/* 0x66d: mov    rcx,rsi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_670:
	/* 0x670: mov    edx,edx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_672:
	/* 0x672: add    rsi,rdx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_675:
	/* 0x675: mov    edx,DWORD PTR [rcx+rdx*1-0x4] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 18446744073709551612ULL);
x86_l_679:
	/* Capture image-bound code identity before scheduled instructions. */
	switch (X86_SIM_L_READ_REG(X86_R8) << 2) {
	case 0ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x68aULL); break;
	case 4ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x68aULL); break;
	case 8ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x6bfULL); break;
	case 12ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x6bfULL); break;
	case 16ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x6bfULL); break;
	case 20ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x69eULL); break;
	case 24ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x694ULL); break;
	case 28ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x6bfULL); break;
	case 32ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x6bfULL); break;
	case 36ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x6bfULL); break;
	case 40ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x6bfULL); break;
	case 44ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x6bfULL); break;
	case 48ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x6bfULL); break;
	case 52ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x6bfULL); break;
	case 56ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x6bfULL); break;
	case 60ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x6bfULL); break;
	case 64ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x6bfULL); break;
	case 68ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x6bfULL); break;
	case 72ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x6bfULL); break;
	case 76ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x6bfULL); break;
	case 80ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x6bfULL); break;
	case 84ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x6bfULL); break;
	case 88ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x6bfULL); break;
	case 92ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x69eULL); break;
	case 96ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x694ULL); break;
	case 100ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x6bfULL); break;
	case 104ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x6bfULL); break;
	case 108ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x6bfULL); break;
	case 112ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x6bfULL); break;
	case 116ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x6bfULL); break;
	case 120ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x6a8ULL); break;
	case 124ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x6afULL); break;
	default: __x86_sim_unresolved_indirect_target();
	}
x86_l_687:
	/* 0x687: jmp    r8 */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_R8);
		switch (X86_SIM_L_REG_TAG(X86_R8)) {
		case X86_SIM_TAG_CODE:
			switch (__x86_target) {
			case 0x68aULL: goto x86_l_68a;
			case 0x694ULL: goto x86_l_694;
			case 0x69eULL: goto x86_l_69e;
			case 0x6a8ULL: goto x86_l_6a8;
			case 0x6afULL: goto x86_l_6af;
			case 0x6bfULL: goto x86_l_6bf;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_68a:
	/* 0x68a: mov    rdi,rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_68d:
	/* 0x68d: call   892 <filter_char_buf_equal> */
	X86_SIM_X86_CALL(x86_l_892, 0x692ULL);
x86_l_692:
	/* 0x692: jmp    6bc <filter_char_buf+0x62> */
	X86_SIM_X86_SUB_JMP(0x692, 0x6bc, x86_l_6bc);
x86_l_694:
	/* 0x694: mov    edi,DWORD PTR [rbx+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_697:
	/* 0x697: call   f2a <filter_char_buf_postfix> */
	X86_SIM_X86_CALL(x86_l_f2a, 0x69cULL);
x86_l_69c:
	/* 0x69c: jmp    6bc <filter_char_buf+0x62> */
	X86_SIM_X86_SUB_JMP(0x69c, 0x6bc, x86_l_6bc);
x86_l_69e:
	/* 0x69e: mov    edi,DWORD PTR [rbx+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6a1:
	/* 0x6a1: call   cd1 <filter_char_buf_prefix> */
	X86_SIM_X86_CALL(x86_l_cd1, 0x6a6ULL);
x86_l_6a6:
	/* 0x6a6: jmp    6bc <filter_char_buf+0x62> */
	X86_SIM_X86_SUB_JMP(0x6a6, 0x6bc, x86_l_6bc);
x86_l_6a8:
	/* 0x6a8: mov    rdi,rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_6ab:
	/* 0x6ab: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_6ad:
	/* 0x6ad: jmp    6b7 <filter_char_buf+0x5d> */
	X86_SIM_X86_SUB_JMP(0x6ad, 0x6b7, x86_l_6b7);
x86_l_6af:
	/* 0x6af: mov    rdi,rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_6b2:
	/* 0x6b2: mov    ecx,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_6b7:
	/* 0x6b7: call   188e <filter_char_substring> */
	X86_SIM_X86_CALL(x86_l_188e, 0x6bcULL);
x86_l_6bc:
	/* 0x6bc: mov    edi,DWORD PTR [rbx+0x4] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_6bf:
	/* 0x6bf: cmp    edi,0x25 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 37ULL);
x86_l_6c2:
	/* 0x6c2: ja     6e1 <filter_char_buf+0x87> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x6c2, 0x6e1, x86_l_6e1);
x86_l_6c4:
	/* 0x6c4: mov    ecx,edi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RDI, X86_WIDTH_32, 0, 0);
x86_l_6c6:
	/* 0x6c6: movabs rdx,0x200c000050 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, 0, 137640280144ULL);
x86_l_6d0:
	/* 0x6d0: bt     rdx,rcx */
	X86_SIM_RUN_OP(X86_OP_BT, X86_RDX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_6d4:
	/* 0x6d4: jae    6e1 <filter_char_buf+0x87> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x6d4, 0x6e1, x86_l_6e1);
x86_l_6d6:
	/* 0x6d6: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_6d8:
	/* 0x6d8: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_6db:
	/* 0x6db: sete   cl */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_CC_E, 0);
x86_l_6de:
	/* 0x6de: mov    rax,rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_6e1:
	/* 0x6e1: pop    rbx */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_6e2:
	/* 0x6e2: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_6e2);

	/* native subroutine native_link_sub_6e3 */
x86_l_6e3:
	/* 0x6e3: mov    eax,DWORD PTR [rdi+0x4] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_6e6:
	/* 0x6e6: cmp    rax,0x20 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, 0, 32ULL);
x86_l_6ea:
	/* 0x6ea: ja     721 <filter_8ty+0x3e> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x6ea, 0x721, x86_l_721);
x86_l_6ec:
	/* 0x6ec: mov    ecx,0x101e */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 4126ULL);
x86_l_6f1:
	/* 0x6f1: bt     rcx,rax */
	X86_SIM_RUN_OP(X86_OP_BT, X86_RCX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_6f5:
	/* 0x6f5: jae    6fc <filter_8ty+0x19> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x6f5, 0x6fc, x86_l_6fc);
x86_l_6f7:
	/* 0x6f7: jmp    1479 <filter_8ty_selector_val> */
	X86_SIM_X86_SUB_JMP(0x6f7, 0x1479, x86_l_1479);
x86_l_6fc:
	/* 0x6fc: mov    ecx,0xc00 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 3072ULL);
x86_l_701:
	/* 0x701: bt     rcx,rax */
	X86_SIM_RUN_OP(X86_OP_BT, X86_RCX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_705:
	/* 0x705: jae    70c <filter_8ty+0x29> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x705, 0x70c, x86_l_70c);
x86_l_707:
	/* 0x707: jmp    1654 <filter_8ty_map> */
	X86_SIM_X86_SUB_JMP(0x707, 0x1654, x86_l_1654);
x86_l_70c:
	/* 0x70c: movabs rcx,0x180000000 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, 0, 6442450944ULL);
x86_l_716:
	/* 0x716: bt     rcx,rax */
	X86_SIM_RUN_OP(X86_OP_BT, X86_RCX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_71a:
	/* 0x71a: jae    721 <filter_8ty+0x3e> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x71a, 0x721, x86_l_721);
x86_l_71c:
	/* 0x71c: jmp    16d6 <filter_8ty_range> */
	X86_SIM_X86_SUB_JMP(0x71c, 0x16d6, x86_l_16d6);
x86_l_721:
	/* 0x721: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_723:
	/* 0x723: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_723);

	/* native subroutine native_link_sub_724 */
x86_l_724:
	/* 0x724: mov    eax,DWORD PTR [rdi+0x4] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_727:
	/* 0x727: cmp    rax,0x20 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, 0, 32ULL);
x86_l_72b:
	/* 0x72b: ja     762 <filter_16ty+0x3e> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x72b, 0x762, x86_l_762);
x86_l_72d:
	/* 0x72d: mov    ecx,0x101e */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 4126ULL);
x86_l_732:
	/* 0x732: bt     rcx,rax */
	X86_SIM_RUN_OP(X86_OP_BT, X86_RCX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_736:
	/* 0x736: jae    73d <filter_16ty+0x19> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x736, 0x73d, x86_l_73d);
x86_l_738:
	/* 0x738: jmp    1064 <filter_16ty_selector_val> */
	X86_SIM_X86_SUB_JMP(0x738, 0x1064, x86_l_1064);
x86_l_73d:
	/* 0x73d: mov    ecx,0xc00 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 3072ULL);
x86_l_742:
	/* 0x742: bt     rcx,rax */
	X86_SIM_RUN_OP(X86_OP_BT, X86_RCX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_746:
	/* 0x746: jae    74d <filter_16ty+0x29> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x746, 0x74d, x86_l_74d);
x86_l_748:
	/* 0x748: jmp    123f <filter_16ty_map> */
	X86_SIM_X86_SUB_JMP(0x748, 0x123f, x86_l_123f);
x86_l_74d:
	/* 0x74d: movabs rcx,0x180000000 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, 0, 6442450944ULL);
x86_l_757:
	/* 0x757: bt     rcx,rax */
	X86_SIM_RUN_OP(X86_OP_BT, X86_RCX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_75b:
	/* 0x75b: jae    762 <filter_16ty+0x3e> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x75b, 0x762, x86_l_762);
x86_l_75d:
	/* 0x75d: jmp    12c1 <filter_16ty_range> */
	X86_SIM_X86_SUB_JMP(0x75d, 0x12c1, x86_l_12c1);
x86_l_762:
	/* 0x762: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_764:
	/* 0x764: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_764);

	/* native subroutine native_link_sub_765 */
x86_l_765:
	/* 0x765: push   rbx */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_766:
	/* 0x766: mov    rbx,rdi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RBX, X86_RDI, X86_WIDTH_64, 0, 0);
x86_l_769:
	/* 0x769: mov    edx,DWORD PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_76b:
	/* 0x76b: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_76e:
	/* 0x76e: test   edx,edx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_770:
	/* 0x770: jne    780 <filter_file_buf+0x1b> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x770, 0x780, x86_l_780);
x86_l_772:
	/* 0x772: mov    eax,ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_774:
	/* 0x774: and    eax,0xfffffffe */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_777:
	/* 0x777: cmp    eax,0x24 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 36ULL);
x86_l_77a:
	/* 0x77a: je     780 <filter_file_buf+0x1b> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x77a, 0x780, x86_l_780);
x86_l_77c:
	/* 0x77c: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_77e:
	/* 0x77e: pop    rbx */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_77f:
	/* 0x77f: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_77f);
x86_l_780:
	/* 0x780: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_782:
	/* 0x782: lea    edi,[rcx-0x3] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_785:
	/* 0x785: cmp    edi,0x22 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 34ULL);
x86_l_788:
	/* 0x788: ja     7cf <filter_file_buf+0x6a> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x788, 0x7cf, x86_l_7cf);
x86_l_78a:
	/* Capture image-bound code identity before scheduled instructions. */
	switch (X86_SIM_L_READ_REG(X86_RDI) << 2) {
	case 0ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDI, 0x79aULL); break;
	case 4ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDI, 0x79aULL); break;
	case 8ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDI, 0x7cfULL); break;
	case 12ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDI, 0x7cfULL); break;
	case 16ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDI, 0x7cfULL); break;
	case 20ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDI, 0x7c0ULL); break;
	case 24ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDI, 0x7b2ULL); break;
	case 28ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDI, 0x7cfULL); break;
	case 32ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDI, 0x7cfULL); break;
	case 36ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDI, 0x7cfULL); break;
	case 40ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDI, 0x7cfULL); break;
	case 44ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDI, 0x7cfULL); break;
	case 48ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDI, 0x7cfULL); break;
	case 52ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDI, 0x7cfULL); break;
	case 56ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDI, 0x7cfULL); break;
	case 60ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDI, 0x7cfULL); break;
	case 64ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDI, 0x7cfULL); break;
	case 68ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDI, 0x7cfULL); break;
	case 72ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDI, 0x7cfULL); break;
	case 76ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDI, 0x7cfULL); break;
	case 80ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDI, 0x7cfULL); break;
	case 84ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDI, 0x7cfULL); break;
	case 88ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDI, 0x7cfULL); break;
	case 92ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDI, 0x7c0ULL); break;
	case 96ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDI, 0x7b2ULL); break;
	case 100ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDI, 0x7cfULL); break;
	case 104ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDI, 0x7cfULL); break;
	case 108ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDI, 0x7cfULL); break;
	case 112ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDI, 0x7cfULL); break;
	case 116ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDI, 0x7cfULL); break;
	case 120ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDI, 0x7cfULL); break;
	case 124ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDI, 0x7cfULL); break;
	case 128ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDI, 0x7cfULL); break;
	case 132ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDI, 0x7a8ULL); break;
	case 136ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDI, 0x7a8ULL); break;
	default: __x86_sim_unresolved_indirect_target();
	}
x86_l_798:
	/* 0x798: jmp    rdi */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RDI);
		switch (X86_SIM_L_REG_TAG(X86_RDI)) {
		case X86_SIM_TAG_CODE:
			switch (__x86_target) {
			case 0x79aULL: goto x86_l_79a;
			case 0x7a8ULL: goto x86_l_7a8;
			case 0x7b2ULL: goto x86_l_7b2;
			case 0x7c0ULL: goto x86_l_7c0;
			case 0x7cfULL: goto x86_l_7cf;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_79a:
	/* 0x79a: add    rsi,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_79e:
	/* 0x79e: mov    rdi,rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_7a1:
	/* 0x7a1: call   892 <filter_char_buf_equal> */
	X86_SIM_X86_CALL(x86_l_892, 0x7a6ULL);
x86_l_7a6:
	/* 0x7a6: jmp    7cc <filter_file_buf+0x67> */
	X86_SIM_X86_SUB_JMP(0x7a6, 0x7cc, x86_l_7cc);
x86_l_7a8:
	/* 0x7a8: mov    rdi,rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_7ab:
	/* 0x7ab: call   e71 <filter_file_type> */
	X86_SIM_X86_CALL(x86_l_e71, 0x7b0ULL);
x86_l_7b0:
	/* 0x7b0: jmp    7cc <filter_file_buf+0x67> */
	X86_SIM_X86_SUB_JMP(0x7b0, 0x7cc, x86_l_7cc);
x86_l_7b2:
	/* 0x7b2: add    rsi,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_7b6:
	/* 0x7b6: mov    edi,DWORD PTR [rbx+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7b9:
	/* 0x7b9: call   f2a <filter_char_buf_postfix> */
	X86_SIM_X86_CALL(x86_l_f2a, 0x7beULL);
x86_l_7be:
	/* 0x7be: jmp    7cc <filter_file_buf+0x67> */
	X86_SIM_X86_SUB_JMP(0x7be, 0x7cc, x86_l_7cc);
x86_l_7c0:
	/* 0x7c0: add    rsi,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_7c4:
	/* 0x7c4: mov    edi,DWORD PTR [rbx+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7c7:
	/* 0x7c7: call   cd1 <filter_char_buf_prefix> */
	X86_SIM_X86_CALL(x86_l_cd1, 0x7ccULL);
x86_l_7cc:
	/* 0x7cc: mov    ecx,DWORD PTR [rbx+0x4] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_7cf:
	/* 0x7cf: cmp    ecx,0x25 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 37ULL);
x86_l_7d2:
	/* 0x7d2: ja     7ea <filter_file_buf+0x85> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x7d2, 0x7ea, x86_l_7ea);
x86_l_7d4:
	/* 0x7d4: mov    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_7d6:
	/* 0x7d6: movabs rdx,0x200c000050 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, 0, 137640280144ULL);
x86_l_7e0:
	/* 0x7e0: bt     rdx,rcx */
	X86_SIM_RUN_OP(X86_OP_BT, X86_RDX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_7e4:
	/* 0x7e4: jae    7ea <filter_file_buf+0x85> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x7e4, 0x7ea, x86_l_7ea);
x86_l_7e6:
	/* 0x7e6: xor    rax,0x1 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_XOR, 1ULL);
x86_l_7ea:
	/* 0x7ea: pop    rbx */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_7eb:
	/* 0x7eb: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_77f);

	/* native subroutine native_link_sub_7ec */
x86_l_7ec:
	/* 0x7ec: push   rbx */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_7ed:
	/* 0x7ed: sub    rsp,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SUB, 16ULL);
x86_l_7f1:
	/* 0x7f1: mov    r8d,DWORD PTR [rdi+0x4] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R8, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_7f5:
	/* 0x7f5: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_7f7:
	/* 0x7f7: add    r8d,0xfffffffd */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 4294967293ULL);
x86_l_7fb:
	/* 0x7fb: cmp    r8d,0x19 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, 0, 25ULL);
x86_l_7ff:
	/* 0x7ff: ja     842 <filter_sockaddr_un+0x56> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x7ff, 0x842, x86_l_842);
x86_l_801:
	/* 0x801: lea    rcx,[rsi+0x4] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_805:
	/* 0x805: movzx  edx,BYTE PTR [rsi+0x3] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 3ULL);
x86_l_809:
	/* Capture image-bound code identity before scheduled instructions. */
	switch (X86_SIM_L_READ_REG(X86_R8) << 2) {
	case 0ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x81aULL); break;
	case 4ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x81aULL); break;
	case 8ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x842ULL); break;
	case 12ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x842ULL); break;
	case 16ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x842ULL); break;
	case 20ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x848ULL); break;
	case 24ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x842ULL); break;
	case 28ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x842ULL); break;
	case 32ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x842ULL); break;
	case 36ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x842ULL); break;
	case 40ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x842ULL); break;
	case 44ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x842ULL); break;
	case 48ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x842ULL); break;
	case 52ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x842ULL); break;
	case 56ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x842ULL); break;
	case 60ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x842ULL); break;
	case 64ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x842ULL); break;
	case 68ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x842ULL); break;
	case 72ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x842ULL); break;
	case 76ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x842ULL); break;
	case 80ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x842ULL); break;
	case 84ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x842ULL); break;
	case 88ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x842ULL); break;
	case 92ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x848ULL); break;
	case 96ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x842ULL); break;
	case 100ULL: X86_SIM_X86_CODE_ADDRESS(X86_R8, 0x87bULL); break;
	default: __x86_sim_unresolved_indirect_target();
	}
x86_l_817:
	/* 0x817: jmp    r8 */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_R8);
		switch (X86_SIM_L_REG_TAG(X86_R8)) {
		case X86_SIM_TAG_CODE:
			switch (__x86_target) {
			case 0x81aULL: goto x86_l_81a;
			case 0x842ULL: goto x86_l_842;
			case 0x848ULL: goto x86_l_848;
			case 0x87bULL: goto x86_l_87b;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_81a:
	/* 0x81a: mov    rbx,rdi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RBX, X86_RDI, X86_WIDTH_64, 0, 0);
x86_l_81d:
	/* 0x81d: mov    rsi,rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_820:
	/* 0x820: call   892 <filter_char_buf_equal> */
	X86_SIM_X86_CALL(x86_l_892, 0x825ULL);
x86_l_825:
	/* 0x825: mov    ecx,DWORD PTR [rbx+0x4] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_828:
	/* 0x828: cmp    rcx,0x25 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, 0, 37ULL);
x86_l_82c:
	/* 0x82c: ja     842 <filter_sockaddr_un+0x56> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x82c, 0x842, x86_l_842);
x86_l_82e:
	/* 0x82e: movabs rdx,0x200c000050 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, 0, 137640280144ULL);
x86_l_838:
	/* 0x838: bt     rdx,rcx */
	X86_SIM_RUN_OP(X86_OP_BT, X86_RDX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_83c:
	/* 0x83c: jae    842 <filter_sockaddr_un+0x56> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x83c, 0x842, x86_l_842);
x86_l_83e:
	/* 0x83e: xor    rax,0x1 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_XOR, 1ULL);
x86_l_842:
	/* 0x842: add    rsp,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_846:
	/* 0x846: pop    rbx */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_847:
	/* 0x847: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_847);
x86_l_848:
	/* 0x848: mov    eax,DWORD PTR [rdi+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_84b:
	/* 0x84b: mov    rbx,rdi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RBX, X86_RDI, X86_WIDTH_64, 0, 0);
x86_l_84e:
	/* 0x84e: mov    edi,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_850:
	/* 0x850: mov    rsi,rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_853:
	/* 0x853: call   cd1 <filter_char_buf_prefix> */
	X86_SIM_X86_CALL(x86_l_cd1, 0x858ULL);
x86_l_858:
	/* 0x858: mov    ecx,DWORD PTR [rbx+0x4] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_85b:
	/* 0x85b: cmp    rcx,0x25 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, 0, 37ULL);
x86_l_85f:
	/* 0x85f: ja     842 <filter_sockaddr_un+0x56> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x85f, 0x842, x86_l_842);
x86_l_861:
	/* 0x861: movabs rdx,0x200c000050 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, 0, 137640280144ULL);
x86_l_86b:
	/* 0x86b: bt     rdx,rcx */
	X86_SIM_RUN_OP(X86_OP_BT, X86_RDX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_86f:
	/* 0x86f: jae    842 <filter_sockaddr_un+0x56> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x86f, 0x842, x86_l_842);
x86_l_871:
	/* 0x871: xor    rax,0x1 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_XOR, 1ULL);
x86_l_875:
	/* 0x875: add    rsp,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_879:
	/* 0x879: pop    rbx */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_87a:
	/* 0x87a: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_847);
x86_l_87b:
	/* 0x87b: movzx  eax,WORD PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_87e:
	/* 0x87e: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_882:
	/* 0x882: lea    rsi,[rsp+0xc] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_887:
	/* 0x887: call   df0 <filter_32ty_map> */
	X86_SIM_X86_CALL(x86_l_df0, 0x88cULL);
x86_l_88c:
	/* 0x88c: add    rsp,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_890:
	/* 0x890: pop    rbx */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_891:
	/* 0x891: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_847);

	/* native subroutine native_link_sub_892 */
x86_l_892:
	/* 0x892: push   rbp */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_893:
	/* 0x893: push   r15 */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_895:
	/* 0x895: push   r14 */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_897:
	/* 0x897: push   r13 */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_899:
	/* 0x899: push   r12 */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_89b:
	/* 0x89b: push   rbx */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_89c:
	/* 0x89c: push   rax */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_89d:
	/* 0x89d: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8a4:
	/* 0x8a4: cmp    edx,0x1000 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 4096ULL);
x86_l_8aa:
	/* 0x8aa: ja     bc9 <filter_char_buf_equal+0x337> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x8aa, 0xbc9, x86_l_bc9);
x86_l_8b0:
	/* 0x8b0: movzx  eax,dx */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_8b3:
	/* 0x8b3: cmp    eax,0x90 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 144ULL);
x86_l_8b8:
	/* 0x8b8: ja     908 <filter_char_buf_equal+0x76> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x8b8, 0x908, x86_l_908);
x86_l_8ba:
	/* 0x8ba: movzx  eax,dl */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8, 0);
x86_l_8bd:
	/* 0x8bd: imul   ecx,eax,0xab */
	X86_SIM_RUN_OP(X86_OP_IMUL_IMM, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 171ULL);
x86_l_8c3:
	/* 0x8c3: shr    ecx,0x9 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_8c6:
	/* 0x8c6: and    ecx,0xfffffff8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_8c9:
	/* 0x8c9: lea    ecx,[rcx+rcx*2] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 1), 0ULL);
x86_l_8cc:
	/* 0x8cc: sub    al,cl */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB, 0);
x86_l_8ce:
	/* 0x8ce: test   dx,dx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_16, 0, 0);
x86_l_8d1:
	/* 0x8d1: je     8dc <filter_char_buf_equal+0x4a> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x8d1, 0x8dc, x86_l_8dc);
x86_l_8d3:
	/* 0x8d3: mov    ecx,edx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_8d5:
	/* 0x8d5: mov    r15d,edx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R15, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_8d8:
	/* 0x8d8: test   al,al */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8, 0, 0);
x86_l_8da:
	/* 0x8da: je     8f5 <filter_char_buf_equal+0x63> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x8da, 0x8f5, x86_l_8f5);
x86_l_8dc:
	/* 0x8dc: movzx  eax,al */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8, 0);
x86_l_8df:
	/* 0x8df: mov    ecx,edx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_8e1:
	/* 0x8e1: sub    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB, 0);
x86_l_8e3:
	/* 0x8e3: mov    eax,ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_8e5:
	/* 0x8e5: add    eax,0x18 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_8e8:
	/* 0x8e8: movzx  r15d,ax */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_8ec:
	/* 0x8ec: cmp    cx,0x78 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, 0, 120ULL);
x86_l_8f0:
	/* 0x8f0: ja     946 <filter_char_buf_equal+0xb4> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x8f0, 0x946, x86_l_946);
x86_l_8f2:
	/* 0x8f2: mov    ecx,r15d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_R15, X86_WIDTH_32, 0, 0);
x86_l_8f5:
	/* 0x8f5: movzx  eax,cl */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8, 0);
x86_l_8f8:
	/* 0x8f8: imul   ebp,eax,0xab */
	X86_SIM_RUN_OP(X86_OP_IMUL_IMM, X86_RBP, X86_RAX, X86_WIDTH_32, 0, 171ULL);
x86_l_8fe:
	/* 0x8fe: shr    ebp,0xc */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHR, 12ULL);
x86_l_901:
	/* 0x901: dec    ebp */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_903:
	/* 0x903: jmp    989 <filter_char_buf_equal+0xf7> */
	X86_SIM_X86_SUB_JMP(0x903, 0x989, x86_l_989);
x86_l_908:
	/* 0x908: mov    r15d,0x100 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 256ULL);
x86_l_90e:
	/* 0x90e: cmp    eax,0x101 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 257ULL);
x86_l_913:
	/* 0x913: jb     946 <filter_char_buf_equal+0xb4> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x913, 0x946, x86_l_946);
x86_l_915:
	/* 0x915: mov    r15d,0x200 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 512ULL);
x86_l_91b:
	/* 0x91b: cmp    eax,0x201 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 513ULL);
x86_l_920:
	/* 0x920: jb     946 <filter_char_buf_equal+0xb4> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x920, 0x946, x86_l_946);
x86_l_922:
	/* 0x922: mov    r15d,0x400 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 1024ULL);
x86_l_928:
	/* 0x928: cmp    eax,0x401 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 1025ULL);
x86_l_92d:
	/* 0x92d: jb     946 <filter_char_buf_equal+0xb4> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x92d, 0x946, x86_l_946);
x86_l_92f:
	/* 0x92f: xor    r15d,r15d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_932:
	/* 0x932: cmp    eax,0x801 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2049ULL);
x86_l_937:
	/* 0x937: setae  r15b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_CC_AE, 0);
x86_l_93b:
	/* 0x93b: shl    r15d,0xb */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 11ULL);
x86_l_93f:
	/* 0x93f: add    r15d,0x800 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 2048ULL);
x86_l_946:
	/* 0x946: lea    eax,[r15-0x100] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551360ULL);
x86_l_94d:
	/* 0x94d: rorx   eax,eax,0x8 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 8ULL);
x86_l_953:
	/* 0x953: cmp    eax,0x7 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 7ULL);
x86_l_956:
	/* 0x956: ja     984 <filter_char_buf_equal+0xf2> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x956, 0x984, x86_l_984);
x86_l_958:
	/* Capture image-bound code identity before scheduled instructions. */
	switch (X86_SIM_L_READ_REG(X86_RAX) << 2) {
	case 0ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x968ULL); break;
	case 4ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x976ULL); break;
	case 8ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x984ULL); break;
	case 12ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x96fULL); break;
	case 16ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x984ULL); break;
	case 20ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x984ULL); break;
	case 24ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x984ULL); break;
	case 28ULL: X86_SIM_X86_CODE_ADDRESS(X86_RAX, 0x97dULL); break;
	default: __x86_sim_unresolved_indirect_target();
	}
x86_l_966:
	/* 0x966: jmp    rax */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RAX);
		switch (X86_SIM_L_REG_TAG(X86_RAX)) {
		case X86_SIM_TAG_CODE:
			switch (__x86_target) {
			case 0x968ULL: goto x86_l_968;
			case 0x96fULL: goto x86_l_96f;
			case 0x976ULL: goto x86_l_976;
			case 0x97dULL: goto x86_l_97d;
			case 0x984ULL: goto x86_l_984;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_968:
	/* 0x968: mov    ebp,0x6 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, 0, 6ULL);
x86_l_96d:
	/* 0x96d: jmp    989 <filter_char_buf_equal+0xf7> */
	X86_SIM_X86_SUB_JMP(0x96d, 0x989, x86_l_989);
x86_l_96f:
	/* 0x96f: mov    ebp,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_974:
	/* 0x974: jmp    989 <filter_char_buf_equal+0xf7> */
	X86_SIM_X86_SUB_JMP(0x974, 0x989, x86_l_989);
x86_l_976:
	/* 0x976: mov    ebp,0x7 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, 0, 7ULL);
x86_l_97b:
	/* 0x97b: jmp    989 <filter_char_buf_equal+0xf7> */
	X86_SIM_X86_SUB_JMP(0x97b, 0x989, x86_l_989);
x86_l_97d:
	/* 0x97d: mov    ebp,0x9 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, 0, 9ULL);
x86_l_982:
	/* 0x982: jmp    989 <filter_char_buf_equal+0xf7> */
	X86_SIM_X86_SUB_JMP(0x982, 0x989, x86_l_989);
x86_l_984:
	/* 0x984: mov    ebp,0xa */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, 0, 10ULL);
x86_l_989:
	/* 0x989: mov    eax,ebp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RBP, X86_WIDTH_32, 0, 0);
x86_l_98b:
	/* 0x98b: and    eax,0xf */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_98e:
	/* 0x98e: mov    r12d,DWORD PTR [rdi+rax*4+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R12, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 16ULL);
x86_l_993:
	/* 0x993: cmp    r12d,0xffffffff */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 4294967295ULL);
x86_l_997:
	/* 0x997: je     bc9 <filter_char_buf_equal+0x337> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x997, 0xbc9, x86_l_bc9);
x86_l_99d:
	/* 0x99d: mov    rbx,rsi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RBX, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_9a0:
	/* 0x9a0: mov    r13d,edx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R13, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_9a3:
	/* 0x9a3: mov    rdi,QWORD PTR [rip+0x1ee0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)string_maps_heap));
x86_l_9aa:
	/* 0x9aa: mov    r14,rsp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R14, X86_RSP, X86_WIDTH_64, 0, 0);
x86_l_9ad:
	/* 0x9ad: mov    rsi,r14 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_9b0:
	/* 0x9b0: call   2895 <__native_link_local_memset_zero_dynamic+0x62c> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_9b5:
	/* 0x9b5: mov    rdi,QWORD PTR [rip+0x1ee0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)heap_ro_zero));
x86_l_9bc:
	/* 0x9bc: mov    rsi,r14 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_9bf:
	/* 0x9bf: mov    r14,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R14, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_9c2:
	/* 0x9c2: call   28a7 <__native_link_local_memset_zero_dynamic+0x63e> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_9c7:
	/* 0x9c7: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_9c9:
	/* 0x9c9: test   r14,r14 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_9cc:
	/* 0x9cc: je     bcb <filter_char_buf_equal+0x339> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x9cc, 0xbcb, x86_l_bcb);
x86_l_9d2:
	/* 0x9d2: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_9d5:
	/* 0x9d5: je     bcb <filter_char_buf_equal+0x339> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x9d5, 0xbcb, x86_l_bcb);
x86_l_9db:
	/* 0x9db: mov    esi,r13d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_R13, X86_WIDTH_32, 0, 0);
x86_l_9de:
	/* 0x9de: cmp    ebp,0x5 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, 0, 5ULL);
x86_l_9e1:
	/* 0x9e1: jg     a40 <filter_char_buf_equal+0x1ae> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x9e1, 0xa40, x86_l_a40);
x86_l_9e3:
	/* 0x9e3: mov    BYTE PTR [r14],sil */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_R14, X86_RSI, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9e6:
	/* 0x9e6: lea    rdi,[r14+0x1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_9ea:
	/* 0x9ea: test   rbx,rbx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_9ed:
	/* 0x9ed: jns    a96 <filter_char_buf_equal+0x204> */
	X86_SIM_X86_SUB_JCC(X86_CC_NS, 0x9ed, 0xa96, x86_l_a96);
x86_l_9f3:
	/* 0x9f3: test   rbx,rbx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_9f6:
	/* 0x9f6: jns    aa3 <filter_char_buf_equal+0x211> */
	X86_SIM_X86_SUB_JCC(X86_CC_NS, 0x9f6, 0xaa3, x86_l_aa3);
x86_l_9fc:
	/* 0x9fc: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_9fe:
	/* 0x9fe: cmp    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_a01:
	/* 0xa01: jb     a21 <filter_char_buf_equal+0x18f> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0xa01, 0xa21, x86_l_a21);
x86_l_a03:
	/* 0xa03: xor    r8d,r8d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_a06:
	/* 0xa06: mov    ecx,r8d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_R8, X86_WIDTH_32, 0, 0);
x86_l_a09:
	/* 0xa09: mov    r9,QWORD PTR [rbx+rcx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R9, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_a0d:
	/* 0xa0d: mov    QWORD PTR [rdi+rcx*1],r9 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_a11:
	/* 0xa11: lea    ecx,[r8+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RCX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a15:
	/* 0xa15: add    r8d,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 16ULL);
x86_l_a19:
	/* 0xa19: cmp    r8d,esi */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_R8, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_a1c:
	/* 0xa1c: mov    r8d,ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R8, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_a1f:
	/* 0xa1f: jbe    a06 <filter_char_buf_equal+0x174> */
	X86_SIM_X86_SUB_JCC(X86_CC_BE, 0xa1f, 0xa06, x86_l_a06);
x86_l_a21:
	/* 0xa21: test   sil,0x4 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, 0, 4ULL);
x86_l_a25:
	/* 0xa25: jne    bdd <filter_char_buf_equal+0x34b> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0xa25, 0xbdd, x86_l_bdd);
x86_l_a2b:
	/* 0xa2b: test   sil,0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, 0, 2ULL);
x86_l_a2f:
	/* 0xa2f: jne    bf5 <filter_char_buf_equal+0x363> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0xa2f, 0xbf5, x86_l_bf5);
x86_l_a35:
	/* 0xa35: test   sil,0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_a39:
	/* 0xa39: je     ab5 <filter_char_buf_equal+0x223> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xa39, 0xab5, x86_l_ab5);
x86_l_a3b:
	/* 0xa3b: jmp    c0f <filter_char_buf_equal+0x37d> */
	X86_SIM_X86_SUB_JMP(0xa3b, 0xc0f, x86_l_c0f);
x86_l_a40:
	/* 0xa40: mov    WORD PTR [r14],si */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_R14, X86_RSI, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a44:
	/* 0xa44: lea    rdi,[r14+0x2] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_a48:
	/* 0xa48: test   rbx,rbx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_a4b:
	/* 0xa4b: jns    a96 <filter_char_buf_equal+0x204> */
	X86_SIM_X86_SUB_JCC(X86_CC_NS, 0xa4b, 0xa96, x86_l_a96);
x86_l_a4d:
	/* 0xa4d: test   rbx,rbx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_a50:
	/* 0xa50: jns    aa3 <filter_char_buf_equal+0x211> */
	X86_SIM_X86_SUB_JCC(X86_CC_NS, 0xa50, 0xaa3, x86_l_aa3);
x86_l_a52:
	/* 0xa52: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_a54:
	/* 0xa54: cmp    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_a57:
	/* 0xa57: jb     a77 <filter_char_buf_equal+0x1e5> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0xa57, 0xa77, x86_l_a77);
x86_l_a59:
	/* 0xa59: xor    r8d,r8d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_a5c:
	/* 0xa5c: mov    ecx,r8d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_R8, X86_WIDTH_32, 0, 0);
x86_l_a5f:
	/* 0xa5f: mov    r9,QWORD PTR [rbx+rcx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R9, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_a63:
	/* 0xa63: mov    QWORD PTR [rdi+rcx*1],r9 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_a67:
	/* 0xa67: lea    ecx,[r8+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RCX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a6b:
	/* 0xa6b: add    r8d,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 16ULL);
x86_l_a6f:
	/* 0xa6f: cmp    r8d,esi */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_R8, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_a72:
	/* 0xa72: mov    r8d,ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R8, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_a75:
	/* 0xa75: jbe    a5c <filter_char_buf_equal+0x1ca> */
	X86_SIM_X86_SUB_JCC(X86_CC_BE, 0xa75, 0xa5c, x86_l_a5c);
x86_l_a77:
	/* 0xa77: test   sil,0x4 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, 0, 4ULL);
x86_l_a7b:
	/* 0xa7b: jne    c1d <filter_char_buf_equal+0x38b> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0xa7b, 0xc1d, x86_l_c1d);
x86_l_a81:
	/* 0xa81: test   sil,0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, 0, 2ULL);
x86_l_a85:
	/* 0xa85: jne    c35 <filter_char_buf_equal+0x3a3> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0xa85, 0xc35, x86_l_c35);
x86_l_a8b:
	/* 0xa8b: test   sil,0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_a8f:
	/* 0xa8f: je     ab5 <filter_char_buf_equal+0x223> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xa8f, 0xab5, x86_l_ab5);
x86_l_a91:
	/* 0xa91: jmp    c4f <filter_char_buf_equal+0x3bd> */
	X86_SIM_X86_SUB_JMP(0xa91, 0xc4f, x86_l_c4f);
x86_l_a96:
	/* 0xa96: mov    rdx,rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_a99:
	/* 0xa99: mov    rbx,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RBX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_a9c:
	/* 0xa9c: call   2997 <__native_link_local_memset_zero_dynamic+0x72e> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_aa1:
	/* 0xaa1: jmp    aaf <filter_char_buf_equal+0x21d> */
	X86_SIM_X86_SUB_JMP(0xaa1, 0xaaf, x86_l_aaf);
x86_l_aa3:
	/* 0xaa3: mov    edx,esi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_aa5:
	/* 0xaa5: xor    esi,esi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_aa7:
	/* 0xaa7: mov    rbx,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RBX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_aaa:
	/* 0xaaa: call   2269 <__native_link_local_memset_zero_dynamic> */
	X86_SIM_X86_CALL(x86_l_2269, 0xaafULL);
x86_l_aaf:
	/* 0xaaf: mov    esi,r13d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_R13, X86_WIDTH_32, 0, 0);
x86_l_ab2:
	/* 0xab2: mov    rax,rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_ab5:
	/* 0xab5: sub    r15d,esi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R15, X86_RSI, X86_WIDTH_32, X86_ALU_SUB, 0);
x86_l_ab8:
	/* 0xab8: jle    b8e <filter_char_buf_equal+0x2fc> */
	X86_SIM_X86_SUB_JCC(X86_CC_LE, 0xab8, 0xb8e, x86_l_b8e);
x86_l_abe:
	/* 0xabe: mov    ecx,esi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_ac0:
	/* 0xac0: mov    rdi,r14 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_ac3:
	/* 0xac3: add    rdi,rcx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_ac6:
	/* 0xac6: mov    esi,r15d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_R15, X86_WIDTH_32, 0, 0);
x86_l_ac9:
	/* 0xac9: and    esi,0xfff */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_acf:
	/* 0xacf: cmp    ebp,0x5 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, 0, 5ULL);
x86_l_ad2:
	/* 0xad2: jg     b2b <filter_char_buf_equal+0x299> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0xad2, 0xb2b, x86_l_b2b);
x86_l_ad4:
	/* 0xad4: inc    rdi */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_ad7:
	/* 0xad7: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_ada:
	/* 0xada: jns    b7b <filter_char_buf_equal+0x2e9> */
	X86_SIM_X86_SUB_JCC(X86_CC_NS, 0xada, 0xb7b, x86_l_b7b);
x86_l_ae0:
	/* 0xae0: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_ae3:
	/* 0xae3: jns    b85 <filter_char_buf_equal+0x2f3> */
	X86_SIM_X86_SUB_JCC(X86_CC_NS, 0xae3, 0xb85, x86_l_b85);
x86_l_ae9:
	/* 0xae9: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_aeb:
	/* 0xaeb: cmp    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_aee:
	/* 0xaee: jb     b0c <filter_char_buf_equal+0x27a> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0xaee, 0xb0c, x86_l_b0c);
x86_l_af0:
	/* 0xaf0: mov    edx,esi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_af2:
	/* 0xaf2: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_af4:
	/* 0xaf4: mov    rsi,rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_af7:
	/* 0xaf7: mov    rcx,QWORD PTR [rax+rcx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_afb:
	/* 0xafb: mov    QWORD PTR [rdi+rsi*1],rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_aff:
	/* 0xaff: lea    rcx,[rsi+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b03:
	/* 0xb03: add    rsi,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_b07:
	/* 0xb07: cmp    rsi,rdx */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_b0a:
	/* 0xb0a: jbe    af4 <filter_char_buf_equal+0x262> */
	X86_SIM_X86_SUB_JCC(X86_CC_BE, 0xb0a, 0xaf4, x86_l_af4);
x86_l_b0c:
	/* 0xb0c: test   r15b,0x4 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, 0, 4ULL);
x86_l_b10:
	/* 0xb10: jne    c5d <filter_char_buf_equal+0x3cb> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0xb10, 0xc5d, x86_l_c5d);
x86_l_b16:
	/* 0xb16: test   r15b,0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, 0, 2ULL);
x86_l_b1a:
	/* 0xb1a: jne    c72 <filter_char_buf_equal+0x3e0> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0xb1a, 0xc72, x86_l_c72);
x86_l_b20:
	/* 0xb20: test   r15b,0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_b24:
	/* 0xb24: je     b8e <filter_char_buf_equal+0x2fc> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xb24, 0xb8e, x86_l_b8e);
x86_l_b26:
	/* 0xb26: jmp    c89 <filter_char_buf_equal+0x3f7> */
	X86_SIM_X86_SUB_JMP(0xb26, 0xc89, x86_l_c89);
x86_l_b2b:
	/* 0xb2b: add    rdi,0x2 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_b2f:
	/* 0xb2f: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_b32:
	/* 0xb32: jns    b7b <filter_char_buf_equal+0x2e9> */
	X86_SIM_X86_SUB_JCC(X86_CC_NS, 0xb32, 0xb7b, x86_l_b7b);
x86_l_b34:
	/* 0xb34: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_b37:
	/* 0xb37: jns    b85 <filter_char_buf_equal+0x2f3> */
	X86_SIM_X86_SUB_JCC(X86_CC_NS, 0xb37, 0xb85, x86_l_b85);
x86_l_b39:
	/* 0xb39: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_b3b:
	/* 0xb3b: cmp    esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_b3e:
	/* 0xb3e: jb     b5c <filter_char_buf_equal+0x2ca> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0xb3e, 0xb5c, x86_l_b5c);
x86_l_b40:
	/* 0xb40: mov    edx,esi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_b42:
	/* 0xb42: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_b44:
	/* 0xb44: mov    rsi,rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_b47:
	/* 0xb47: mov    rcx,QWORD PTR [rax+rcx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_b4b:
	/* 0xb4b: mov    QWORD PTR [rdi+rsi*1],rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_b4f:
	/* 0xb4f: lea    rcx,[rsi+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b53:
	/* 0xb53: add    rsi,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_b57:
	/* 0xb57: cmp    rsi,rdx */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_b5a:
	/* 0xb5a: jbe    b44 <filter_char_buf_equal+0x2b2> */
	X86_SIM_X86_SUB_JCC(X86_CC_BE, 0xb5a, 0xb44, x86_l_b44);
x86_l_b5c:
	/* 0xb5c: test   r15b,0x4 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, 0, 4ULL);
x86_l_b60:
	/* 0xb60: jne    c97 <filter_char_buf_equal+0x405> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0xb60, 0xc97, x86_l_c97);
x86_l_b66:
	/* 0xb66: test   r15b,0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, 0, 2ULL);
x86_l_b6a:
	/* 0xb6a: jne    cac <filter_char_buf_equal+0x41a> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0xb6a, 0xcac, x86_l_cac);
x86_l_b70:
	/* 0xb70: test   r15b,0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_b74:
	/* 0xb74: je     b8e <filter_char_buf_equal+0x2fc> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xb74, 0xb8e, x86_l_b8e);
x86_l_b76:
	/* 0xb76: jmp    cc3 <filter_char_buf_equal+0x431> */
	X86_SIM_X86_SUB_JMP(0xb76, 0xcc3, x86_l_cc3);
x86_l_b7b:
	/* 0xb7b: mov    rdx,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_b7e:
	/* 0xb7e: call   2a79 <__native_link_local_memset_zero_dynamic+0x810> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_b83:
	/* 0xb83: jmp    b8e <filter_char_buf_equal+0x2fc> */
	X86_SIM_X86_SUB_JMP(0xb83, 0xb8e, x86_l_b8e);
x86_l_b85:
	/* 0xb85: mov    edx,esi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_b87:
	/* 0xb87: xor    esi,esi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_b89:
	/* 0xb89: call   2269 <__native_link_local_memset_zero_dynamic> */
	X86_SIM_X86_CALL(x86_l_2269, 0xb8eULL);
x86_l_b8e:
	/* 0xb8e: mov    DWORD PTR [rsp+0x4],r12d */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_b93:
	/* 0xb93: cmp    ebp,0xb */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, 0, 11ULL);
x86_l_b96:
	/* 0xb96: jae    bc9 <filter_char_buf_equal+0x337> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0xb96, 0xbc9, x86_l_bc9);
x86_l_b98:
	/* 0xb98: mov    eax,ebp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RBP, X86_WIDTH_32, 0, 0);
x86_l_b9a:
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
x86_l_ba5:
	/* 0xba5: lea    rsi,[rsp+0x4] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_baa:
	/* 0xbaa: call   2aa5 <__native_link_local_memset_zero_dynamic+0x83c> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_baf:
	/* 0xbaf: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_bb2:
	/* 0xbb2: je     bc9 <filter_char_buf_equal+0x337> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xbb2, 0xbc9, x86_l_bc9);
x86_l_bb4:
	/* 0xbb4: mov    rdi,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_bb7:
	/* 0xbb7: mov    rsi,r14 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_bba:
	/* 0xbba: call   2ab5 <__native_link_local_memset_zero_dynamic+0x84c> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_bbf:
	/* 0xbbf: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_bc1:
	/* 0xbc1: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_bc4:
	/* 0xbc4: setne  cl */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_CC_NE, 0);
x86_l_bc7:
	/* 0xbc7: jmp    bcb <filter_char_buf_equal+0x339> */
	X86_SIM_X86_SUB_JMP(0xbc7, 0xbcb, x86_l_bcb);
x86_l_bc9:
	/* 0xbc9: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_bcb:
	/* 0xbcb: mov    rax,rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_bce:
	/* 0xbce: add    rsp,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_bd2:
	/* 0xbd2: pop    rbx */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_bd3:
	/* 0xbd3: pop    r12 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R12, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_bd5:
	/* 0xbd5: pop    r13 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R13, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_bd7:
	/* 0xbd7: pop    r14 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R14, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_bd9:
	/* 0xbd9: pop    r15 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R15, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_bdb:
	/* 0xbdb: pop    rbp */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBP, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_bdc:
	/* 0xbdc: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_bdc);
x86_l_bdd:
	/* 0xbdd: mov    r8d,ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R8, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_be0:
	/* 0xbe0: mov    r9d,DWORD PTR [rbx+r8*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R9, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_R8, 0), 0ULL);
x86_l_be4:
	/* 0xbe4: mov    DWORD PTR [rdi+r8*1],r9d */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_R8, 0), 0ULL);
x86_l_be8:
	/* 0xbe8: or     ecx,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_OR, 4ULL);
x86_l_beb:
	/* 0xbeb: test   sil,0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, 0, 2ULL);
x86_l_bef:
	/* 0xbef: je     a35 <filter_char_buf_equal+0x1a3> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xbef, 0xa35, x86_l_a35);
x86_l_bf5:
	/* 0xbf5: mov    r8d,ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R8, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_bf8:
	/* 0xbf8: movzx  r9d,WORD PTR [rbx+r8*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R9, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R8, 0, X86_WIDTH_16), 0ULL);
x86_l_bfd:
	/* 0xbfd: mov    WORD PTR [rdi+r8*1],r9w */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_R9, X86_WIDTH_16, X86_MEM_AUX(X86_R8, 0), 0ULL);
x86_l_c02:
	/* 0xc02: add    ecx,0x2 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_c05:
	/* 0xc05: test   sil,0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_c09:
	/* 0xc09: je     ab5 <filter_char_buf_equal+0x223> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xc09, 0xab5, x86_l_ab5);
x86_l_c0f:
	/* 0xc0f: mov    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_c11:
	/* 0xc11: movzx  edx,BYTE PTR [rbx+rcx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_c15:
	/* 0xc15: mov    BYTE PTR [rdi+rcx*1],dl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RDX, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_c18:
	/* 0xc18: jmp    ab5 <filter_char_buf_equal+0x223> */
	X86_SIM_X86_SUB_JMP(0xc18, 0xab5, x86_l_ab5);
x86_l_c1d:
	/* 0xc1d: mov    r8d,ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R8, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_c20:
	/* 0xc20: mov    r9d,DWORD PTR [rbx+r8*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R9, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_R8, 0), 0ULL);
x86_l_c24:
	/* 0xc24: mov    DWORD PTR [rdi+r8*1],r9d */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_R8, 0), 0ULL);
x86_l_c28:
	/* 0xc28: or     ecx,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_OR, 4ULL);
x86_l_c2b:
	/* 0xc2b: test   sil,0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, 0, 2ULL);
x86_l_c2f:
	/* 0xc2f: je     a8b <filter_char_buf_equal+0x1f9> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xc2f, 0xa8b, x86_l_a8b);
x86_l_c35:
	/* 0xc35: mov    r8d,ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R8, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_c38:
	/* 0xc38: movzx  r9d,WORD PTR [rbx+r8*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R9, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R8, 0, X86_WIDTH_16), 0ULL);
x86_l_c3d:
	/* 0xc3d: mov    WORD PTR [rdi+r8*1],r9w */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_R9, X86_WIDTH_16, X86_MEM_AUX(X86_R8, 0), 0ULL);
x86_l_c42:
	/* 0xc42: add    ecx,0x2 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_c45:
	/* 0xc45: test   sil,0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_c49:
	/* 0xc49: je     ab5 <filter_char_buf_equal+0x223> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xc49, 0xab5, x86_l_ab5);
x86_l_c4f:
	/* 0xc4f: mov    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_c51:
	/* 0xc51: movzx  edx,BYTE PTR [rbx+rcx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_c55:
	/* 0xc55: mov    BYTE PTR [rdi+rcx*1],dl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RDX, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_c58:
	/* 0xc58: jmp    ab5 <filter_char_buf_equal+0x223> */
	X86_SIM_X86_SUB_JMP(0xc58, 0xab5, x86_l_ab5);
x86_l_c5d:
	/* 0xc5d: mov    edx,ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_c5f:
	/* 0xc5f: mov    esi,DWORD PTR [rax+rdx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_c62:
	/* 0xc62: mov    DWORD PTR [rdi+rdx*1],esi */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_c65:
	/* 0xc65: or     ecx,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_OR, 4ULL);
x86_l_c68:
	/* 0xc68: test   r15b,0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, 0, 2ULL);
x86_l_c6c:
	/* 0xc6c: je     b20 <filter_char_buf_equal+0x28e> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xc6c, 0xb20, x86_l_b20);
x86_l_c72:
	/* 0xc72: mov    edx,ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_c74:
	/* 0xc74: movzx  esi,WORD PTR [rax+rdx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RDX, 0, X86_WIDTH_16), 0ULL);
x86_l_c78:
	/* 0xc78: mov    WORD PTR [rdi+rdx*1],si */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RSI, X86_WIDTH_16, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_c7c:
	/* 0xc7c: add    ecx,0x2 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_c7f:
	/* 0xc7f: test   r15b,0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_c83:
	/* 0xc83: je     b8e <filter_char_buf_equal+0x2fc> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xc83, 0xb8e, x86_l_b8e);
x86_l_c89:
	/* 0xc89: mov    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_c8b:
	/* 0xc8b: movzx  eax,BYTE PTR [rax+rcx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_c8f:
	/* 0xc8f: mov    BYTE PTR [rdi+rcx*1],al */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_c92:
	/* 0xc92: jmp    b8e <filter_char_buf_equal+0x2fc> */
	X86_SIM_X86_SUB_JMP(0xc92, 0xb8e, x86_l_b8e);
x86_l_c97:
	/* 0xc97: mov    edx,ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_c99:
	/* 0xc99: mov    esi,DWORD PTR [rax+rdx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_c9c:
	/* 0xc9c: mov    DWORD PTR [rdi+rdx*1],esi */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_c9f:
	/* 0xc9f: or     ecx,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_OR, 4ULL);
x86_l_ca2:
	/* 0xca2: test   r15b,0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, 0, 2ULL);
x86_l_ca6:
	/* 0xca6: je     b70 <filter_char_buf_equal+0x2de> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xca6, 0xb70, x86_l_b70);
x86_l_cac:
	/* 0xcac: mov    edx,ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_cae:
	/* 0xcae: movzx  esi,WORD PTR [rax+rdx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RDX, 0, X86_WIDTH_16), 0ULL);
x86_l_cb2:
	/* 0xcb2: mov    WORD PTR [rdi+rdx*1],si */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RSI, X86_WIDTH_16, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_cb6:
	/* 0xcb6: add    ecx,0x2 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_cb9:
	/* 0xcb9: test   r15b,0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_cbd:
	/* 0xcbd: je     b8e <filter_char_buf_equal+0x2fc> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xcbd, 0xb8e, x86_l_b8e);
x86_l_cc3:
	/* 0xcc3: mov    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_cc5:
	/* 0xcc5: movzx  eax,BYTE PTR [rax+rcx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_cc9:
	/* 0xcc9: mov    BYTE PTR [rdi+rcx*1],al */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_ccc:
	/* 0xccc: jmp    b8e <filter_char_buf_equal+0x2fc> */
	X86_SIM_X86_SUB_JMP(0xccc, 0xb8e, x86_l_b8e);

	/* native subroutine native_link_sub_cd1 */
x86_l_cd1:
	/* 0xcd1: push   rbp */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_cd2:
	/* 0xcd2: push   r15 */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_cd4:
	/* 0xcd4: push   r14 */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_cd6:
	/* 0xcd6: push   rbx */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_cd7:
	/* 0xcd7: push   rax */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_cd8:
	/* 0xcd8: mov    ebp,edx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RBP, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_cda:
	/* 0xcda: mov    r14,rsi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R14, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_cdd:
	/* 0xcdd: mov    DWORD PTR [rsp+0x4],edi */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_ce1:
	/* 0xce1: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ce8:
	/* 0xce8: mov    rdi,QWORD PTR [rip+0x2340] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)string_prefix_maps));
x86_l_cef:
	/* 0xcef: lea    rsi,[rsp+0x4] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_cf4:
	/* 0xcf4: call   3039 <__native_link_local_memset_zero_dynamic+0xdd0> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_cf9:
	/* 0xcf9: mov    rbx,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RBX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_cfc:
	/* 0xcfc: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_cfe:
	/* 0xcfe: test   ebp,ebp */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32, 0, 0);
x86_l_d00:
	/* 0xd00: je     de5 <filter_char_buf_prefix+0x114> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xd00, 0xde5, x86_l_de5);
x86_l_d06:
	/* 0xd06: test   rbx,rbx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_d09:
	/* 0xd09: je     de5 <filter_char_buf_prefix+0x114> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xd09, 0xde5, x86_l_de5);
x86_l_d0f:
	/* 0xd0f: mov    rdi,QWORD PTR [rip+0x2340] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)string_prefix_maps_heap));
x86_l_d16:
	/* 0xd16: mov    rsi,rsp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_RSP, X86_WIDTH_64, 0, 0);
x86_l_d19:
	/* 0xd19: call   305e <__native_link_local_memset_zero_dynamic+0xdf5> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_d1e:
	/* 0xd1e: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_d21:
	/* 0xd21: je     d86 <filter_char_buf_prefix+0xb5> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xd21, 0xd86, x86_l_d86);
x86_l_d23:
	/* 0xd23: mov    r15,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R15, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_d26:
	/* 0xd26: cmp    ebp,0xff */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, 0, 255ULL);
x86_l_d2c:
	/* 0xd2c: mov    esi,0xff */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 255ULL);
x86_l_d31:
	/* 0xd31: cmovb  esi,ebp */
	X86_SIM_RUN_OP(X86_OP_CMOV, X86_RSI, X86_RBP, X86_WIDTH_32, X86_CC_B, 0);
x86_l_d34:
	/* 0xd34: lea    eax,[rsi*8+0x0] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 3), 0ULL);
x86_l_d3b:
	/* 0xd3b: mov    DWORD PTR [r15],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d3e:
	/* 0xd3e: mov    rdi,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_d41:
	/* 0xd41: add    rdi,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_d45:
	/* 0xd45: test   r14,r14 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_d48:
	/* 0xd48: jns    d8a <filter_char_buf_prefix+0xb9> */
	X86_SIM_X86_SUB_JCC(X86_CC_NS, 0xd48, 0xd8a, x86_l_d8a);
x86_l_d4a:
	/* 0xd4a: test   r14,r14 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_d4d:
	/* 0xd4d: jns    d94 <filter_char_buf_prefix+0xc3> */
	X86_SIM_X86_SUB_JCC(X86_CC_NS, 0xd4d, 0xd94, x86_l_d94);
x86_l_d4f:
	/* 0xd4f: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_d51:
	/* 0xd51: cmp    ebp,0x8 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_d54:
	/* 0xd54: jb     d72 <filter_char_buf_prefix+0xa1> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0xd54, 0xd72, x86_l_d72);
x86_l_d56:
	/* 0xd56: mov    ecx,esi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_d58:
	/* 0xd58: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_d5a:
	/* 0xd5a: mov    rdx,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_d5d:
	/* 0xd5d: mov    rax,QWORD PTR [r14+rax*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_d61:
	/* 0xd61: mov    QWORD PTR [rdi+rdx*1],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_d65:
	/* 0xd65: lea    rax,[rdx+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d69:
	/* 0xd69: add    rdx,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_d6d:
	/* 0xd6d: cmp    rdx,rcx */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_d70:
	/* 0xd70: jbe    d5a <filter_char_buf_prefix+0x89> */
	X86_SIM_X86_SUB_JCC(X86_CC_BE, 0xd70, 0xd5a, x86_l_d5a);
x86_l_d72:
	/* 0xd72: test   sil,0x4 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, 0, 4ULL);
x86_l_d76:
	/* 0xd76: jne    d9f <filter_char_buf_prefix+0xce> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0xd76, 0xd9f, x86_l_d9f);
x86_l_d78:
	/* 0xd78: test   sil,0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, 0, 2ULL);
x86_l_d7c:
	/* 0xd7c: jne    db1 <filter_char_buf_prefix+0xe0> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0xd7c, 0xdb1, x86_l_db1);
x86_l_d7e:
	/* 0xd7e: test   sil,0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_d82:
	/* 0xd82: jne    dc5 <filter_char_buf_prefix+0xf4> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0xd82, 0xdc5, x86_l_dc5);
x86_l_d84:
	/* 0xd84: jmp    dcf <filter_char_buf_prefix+0xfe> */
	X86_SIM_X86_SUB_JMP(0xd84, 0xdcf, x86_l_dcf);
x86_l_d86:
	/* 0xd86: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_d88:
	/* 0xd88: jmp    de5 <filter_char_buf_prefix+0x114> */
	X86_SIM_X86_SUB_JMP(0xd88, 0xde5, x86_l_de5);
x86_l_d8a:
	/* 0xd8a: mov    rdx,r14 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_d8d:
	/* 0xd8d: call   30d9 <__native_link_local_memset_zero_dynamic+0xe70> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_d92:
	/* 0xd92: jmp    dcf <filter_char_buf_prefix+0xfe> */
	X86_SIM_X86_SUB_JMP(0xd92, 0xdcf, x86_l_dcf);
x86_l_d94:
	/* 0xd94: mov    edx,esi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_d96:
	/* 0xd96: xor    esi,esi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_d98:
	/* 0xd98: call   2269 <__native_link_local_memset_zero_dynamic> */
	X86_SIM_X86_CALL(x86_l_2269, 0xd9dULL);
x86_l_d9d:
	/* 0xd9d: jmp    dcf <filter_char_buf_prefix+0xfe> */
	X86_SIM_X86_SUB_JMP(0xd9d, 0xdcf, x86_l_dcf);
x86_l_d9f:
	/* 0xd9f: mov    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_da1:
	/* 0xda1: mov    edx,DWORD PTR [r14+rcx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_da5:
	/* 0xda5: mov    DWORD PTR [rdi+rcx*1],edx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_da8:
	/* 0xda8: or     eax,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_OR, 4ULL);
x86_l_dab:
	/* 0xdab: test   sil,0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, 0, 2ULL);
x86_l_daf:
	/* 0xdaf: je     d7e <filter_char_buf_prefix+0xad> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xdaf, 0xd7e, x86_l_d7e);
x86_l_db1:
	/* 0xdb1: mov    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_db3:
	/* 0xdb3: movzx  edx,WORD PTR [r14+rcx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_16), 0ULL);
x86_l_db8:
	/* 0xdb8: mov    WORD PTR [rdi+rcx*1],dx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_dbc:
	/* 0xdbc: add    eax,0x2 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_dbf:
	/* 0xdbf: test   sil,0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_dc3:
	/* 0xdc3: je     dcf <filter_char_buf_prefix+0xfe> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xdc3, 0xdcf, x86_l_dcf);
x86_l_dc5:
	/* 0xdc5: mov    eax,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_dc7:
	/* 0xdc7: movzx  ecx,BYTE PTR [r14+rax*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_dcc:
	/* 0xdcc: mov    BYTE PTR [rdi+rax*1],cl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_dcf:
	/* 0xdcf: mov    rdi,rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_dd2:
	/* 0xdd2: mov    rsi,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_dd5:
	/* 0xdd5: call   3121 <__native_link_local_memset_zero_dynamic+0xeb8> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_dda:
	/* 0xdda: mov    rcx,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_ddd:
	/* 0xddd: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_ddf:
	/* 0xddf: test   rcx,rcx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_de2:
	/* 0xde2: setne  al */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_CC_NE, 0);
x86_l_de5:
	/* 0xde5: add    rsp,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_de9:
	/* 0xde9: pop    rbx */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_dea:
	/* 0xdea: pop    r14 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R14, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_dec:
	/* 0xdec: pop    r15 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R15, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_dee:
	/* 0xdee: pop    rbp */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBP, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_def:
	/* 0xdef: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_def);

	/* native subroutine native_link_sub_df0 */
x86_l_df0:
	/* 0xdf0: push   r14 */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_df2:
	/* 0xdf2: push   rbx */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_df3:
	/* 0xdf3: sub    rsp,0x18 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SUB, 24ULL);
x86_l_df7:
	/* 0xdf7: mov    r14,rsi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R14, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_dfa:
	/* 0xdfa: mov    rbx,rdi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RBX, X86_RDI, X86_WIDTH_64, 0, 0);
x86_l_dfd:
	/* 0xdfd: movzx  eax,BYTE PTR [rdi+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_e01:
	/* 0xe01: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_e05:
	/* 0xe05: mov    rdi,QWORD PTR [rip+0x1000] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)argfilter_maps));
x86_l_e0c:
	/* 0xe0c: lea    rsi,[rsp+0xc] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_e11:
	/* 0xe11: call   1e16 <filter_64ty_range+0x113> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_e16:
	/* 0xe16: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_e19:
	/* 0xe19: je     e4c <filter_32ty_map+0x5c> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xe19, 0xe4c, x86_l_e4c);
x86_l_e1b:
	/* 0xe1b: mov    ecx,DWORD PTR [r14] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e1e:
	/* 0xe1e: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e23:
	/* 0xe23: lea    rsi,[rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e28:
	/* 0xe28: mov    rdi,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_e2b:
	/* 0xe2b: call   1e30 <filter_64ty_range+0x12d> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_e30:
	/* 0xe30: mov    edx,DWORD PTR [rbx+0x4] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_e33:
	/* 0xe33: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_e35:
	/* 0xe35: cmp    edx,0x1d */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 29ULL);
x86_l_e38:
	/* 0xe38: ja     e66 <filter_32ty_map+0x76> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0xe38, 0xe66, x86_l_e66);
x86_l_e3a:
	/* 0xe3a: mov    esi,0x30038400 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 805536768ULL);
x86_l_e3f:
	/* 0xe3f: bt     esi,edx */
	X86_SIM_RUN_OP(X86_OP_BT, X86_RSI, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_e42:
	/* 0xe42: jae    e56 <filter_32ty_map+0x66> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0xe42, 0xe56, x86_l_e56);
x86_l_e44:
	/* 0xe44: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_e47:
	/* 0xe47: setne  cl */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_CC_NE, 0);
x86_l_e4a:
	/* 0xe4a: jmp    e66 <filter_32ty_map+0x76> */
	X86_SIM_X86_SUB_JMP(0xe4a, 0xe66, x86_l_e66);
x86_l_e4c:
	/* 0xe4c: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_e4e:
	/* 0xe4e: add    rsp,0x18 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_e52:
	/* 0xe52: pop    rbx */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_e53:
	/* 0xe53: pop    r14 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R14, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_e55:
	/* 0xe55: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_e55);
x86_l_e56:
	/* 0xe56: mov    esi,0xc0800 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 788480ULL);
x86_l_e5b:
	/* 0xe5b: bt     esi,edx */
	X86_SIM_RUN_OP(X86_OP_BT, X86_RSI, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_e5e:
	/* 0xe5e: jae    e66 <filter_32ty_map+0x76> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0xe5e, 0xe66, x86_l_e66);
x86_l_e60:
	/* 0xe60: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_e63:
	/* 0xe63: sete   cl */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_CC_E, 0);
x86_l_e66:
	/* 0xe66: movzx  eax,cl */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8, 0);
x86_l_e69:
	/* 0xe69: add    rsp,0x18 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_e6d:
	/* 0xe6d: pop    rbx */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_e6e:
	/* 0xe6e: pop    r14 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R14, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_e70:
	/* 0xe70: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_e55);

	/* native subroutine native_link_sub_e71 */
x86_l_e71:
	/* 0xe71: push   rbx */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_e72:
	/* 0xe72: sub    rsp,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SUB, 16ULL);
x86_l_e76:
	/* 0xe76: mov    WORD PTR [rsp+0xe],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 60129542144ULL);
x86_l_e7d:
	/* 0xe7d: mov    eax,DWORD PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e7f:
	/* 0xe7f: cmp    rax,0x1000 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, 0, 4096ULL);
x86_l_e85:
	/* 0xe85: ja     f22 <filter_file_type+0xb1> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0xe85, 0xf22, x86_l_f22);
x86_l_e8b:
	/* 0xe8b: mov    rdx,rsi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_e8e:
	/* 0xe8e: add    rdx,rax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_e91:
	/* 0xe91: add    rdx,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_e95:
	/* 0xe95: jns    ea8 <filter_file_type+0x37> */
	X86_SIM_X86_SUB_JCC(X86_CC_NS, 0xe95, 0xea8, x86_l_ea8);
x86_l_e97:
	/* 0xe97: test   rdx,rdx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_e9a:
	/* 0xe9a: jns    ece <filter_file_type+0x5d> */
	X86_SIM_X86_SUB_JCC(X86_CC_NS, 0xe9a, 0xece, x86_l_ece);
x86_l_e9c:
	/* 0xe9c: movzx  ecx,WORD PTR [rdx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_e9f:
	/* 0xe9f: mov    edx,DWORD PTR [rdi+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ea2:
	/* 0xea2: test   edx,edx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_ea4:
	/* 0xea4: jne    ed7 <filter_file_type+0x66> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0xea4, 0xed7, x86_l_ed7);
x86_l_ea6:
	/* 0xea6: jmp    f22 <filter_file_type+0xb1> */
	X86_SIM_X86_SUB_JMP(0xea6, 0xf22, x86_l_f22);
x86_l_ea8:
	/* 0xea8: lea    rax,[rsp+0xe] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_ead:
	/* 0xead: mov    rbx,rdi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RBX, X86_RDI, X86_WIDTH_64, 0, 0);
x86_l_eb0:
	/* 0xeb0: mov    rdi,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_eb3:
	/* 0xeb3: mov    esi,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_eb8:
	/* 0xeb8: call   346d <__native_link_local_memset_zero_dynamic+0x1204> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_probe_read);
x86_l_ebd:
	/* 0xebd: mov    rdi,rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_ec0:
	/* 0xec0: movzx  ecx,WORD PTR [rsp+0xe] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 14ULL);
x86_l_ec5:
	/* 0xec5: mov    edx,DWORD PTR [rdi+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ec8:
	/* 0xec8: test   edx,edx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_eca:
	/* 0xeca: jne    ed7 <filter_file_type+0x66> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0xeca, 0xed7, x86_l_ed7);
x86_l_ecc:
	/* 0xecc: jmp    f22 <filter_file_type+0xb1> */
	X86_SIM_X86_SUB_JMP(0xecc, 0xf22, x86_l_f22);
x86_l_ece:
	/* 0xece: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_ed0:
	/* 0xed0: mov    edx,DWORD PTR [rdi+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ed3:
	/* 0xed3: test   edx,edx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_ed5:
	/* 0xed5: je     f22 <filter_file_type+0xb1> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xed5, 0xf22, x86_l_f22);
x86_l_ed7:
	/* 0xed7: and    ecx,0xf000 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 61440ULL);
x86_l_edd:
	/* 0xedd: mov    eax,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_ee2:
	/* 0xee2: cmp    edx,ecx */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_ee4:
	/* 0xee4: je     f24 <filter_file_type+0xb3> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xee4, 0xf24, x86_l_f24);
x86_l_ee6:
	/* 0xee6: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ee9:
	/* 0xee9: cmp    edx,0xc */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 12ULL);
x86_l_eec:
	/* 0xeec: jbe    f22 <filter_file_type+0xb1> */
	X86_SIM_X86_SUB_JCC(X86_CC_BE, 0xeec, 0xf22, x86_l_f22);
x86_l_eee:
	/* 0xeee: mov    esi,DWORD PTR [rdi+0x14] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_ef1:
	/* 0xef1: test   esi,esi */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_ef3:
	/* 0xef3: je     f22 <filter_file_type+0xb1> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xef3, 0xf22, x86_l_f22);
x86_l_ef5:
	/* 0xef5: cmp    esi,ecx */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_ef7:
	/* 0xef7: je     f24 <filter_file_type+0xb3> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xef7, 0xf24, x86_l_f24);
x86_l_ef9:
	/* 0xef9: cmp    edx,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_efc:
	/* 0xefc: jb     f22 <filter_file_type+0xb1> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0xefc, 0xf22, x86_l_f22);
x86_l_efe:
	/* 0xefe: mov    esi,DWORD PTR [rdi+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_f01:
	/* 0xf01: test   esi,esi */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_f03:
	/* 0xf03: je     f22 <filter_file_type+0xb1> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xf03, 0xf22, x86_l_f22);
x86_l_f05:
	/* 0xf05: cmp    esi,ecx */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_f07:
	/* 0xf07: je     f24 <filter_file_type+0xb3> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xf07, 0xf24, x86_l_f24);
x86_l_f09:
	/* 0xf09: cmp    edx,0x15 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 21ULL);
x86_l_f0c:
	/* 0xf0c: jb     f22 <filter_file_type+0xb1> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0xf0c, 0xf22, x86_l_f22);
x86_l_f0e:
	/* 0xf0e: mov    edx,DWORD PTR [rdi+0x1c] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_f11:
	/* 0xf11: test   edx,edx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_f13:
	/* 0xf13: je     f22 <filter_file_type+0xb1> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xf13, 0xf22, x86_l_f22);
x86_l_f15:
	/* 0xf15: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_f17:
	/* 0xf17: cmp    edx,ecx */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_f19:
	/* 0xf19: sete   al */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_CC_E, 0);
x86_l_f1c:
	/* 0xf1c: add    rsp,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_f20:
	/* 0xf20: pop    rbx */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_f21:
	/* 0xf21: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_f21);
x86_l_f22:
	/* 0xf22: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_f24:
	/* 0xf24: add    rsp,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_f28:
	/* 0xf28: pop    rbx */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_f29:
	/* 0xf29: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_f21);

	/* native subroutine native_link_sub_f2a */
x86_l_f2a:
	/* 0xf2a: push   rbp */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_f2b:
	/* 0xf2b: push   r15 */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_f2d:
	/* 0xf2d: push   r14 */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_f2f:
	/* 0xf2f: push   r13 */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_f31:
	/* 0xf31: push   r12 */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_f33:
	/* 0xf33: push   rbx */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_f34:
	/* 0xf34: push   rax */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_f35:
	/* 0xf35: mov    ebx,edx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RBX, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_f37:
	/* 0xf37: mov    r14,rsi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R14, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_f3a:
	/* 0xf3a: mov    DWORD PTR [rsp+0x4],edi */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_f3e:
	/* 0xf3e: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f45:
	/* 0xf45: mov    rdi,QWORD PTR [rip+0x2470] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)string_postfix_maps));
x86_l_f4c:
	/* 0xf4c: lea    rsi,[rsp+0x4] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_f51:
	/* 0xf51: call   33c6 <__native_link_local_memset_zero_dynamic+0x115d> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_f56:
	/* 0xf56: mov    r15,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R15, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_f59:
	/* 0xf59: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_f5b:
	/* 0xf5b: test   ebx,ebx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_32, 0, 0);
x86_l_f5d:
	/* 0xf5d: je     1055 <filter_char_buf_postfix+0x12b> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xf5d, 0x1055, x86_l_1055);
x86_l_f63:
	/* 0xf63: test   r15,r15 */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_f66:
	/* 0xf66: je     1055 <filter_char_buf_postfix+0x12b> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xf66, 0x1055, x86_l_1055);
x86_l_f6c:
	/* 0xf6c: mov    rdi,QWORD PTR [rip+0x2470] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)string_postfix_maps_heap));
x86_l_f73:
	/* 0xf73: mov    rsi,rsp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_RSP, X86_WIDTH_64, 0, 0);
x86_l_f76:
	/* 0xf76: call   33eb <__native_link_local_memset_zero_dynamic+0x1182> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_f7b:
	/* 0xf7b: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_f7e:
	/* 0xf7e: je     1053 <filter_char_buf_postfix+0x129> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xf7e, 0x1053, x86_l_1053);
x86_l_f84:
	/* 0xf84: cmp    ebx,0x7f */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 127ULL);
x86_l_f87:
	/* 0xf87: mov    ecx,0x7f */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 127ULL);
x86_l_f8c:
	/* 0xf8c: cmovb  ecx,ebx */
	X86_SIM_RUN_OP(X86_OP_CMOV, X86_RCX, X86_RBX, X86_WIDTH_32, X86_CC_B, 0);
x86_l_f8f:
	/* 0xf8f: shl    ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_f92:
	/* 0xf92: mov    DWORD PTR [rax],ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f94:
	/* 0xf94: mov    r9d,ebx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R9, X86_RBX, X86_WIDTH_32, 0, 0);
x86_l_f97:
	/* 0xf97: lea    ecx,[rbx-0x4] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551612ULL);
x86_l_f9a:
	/* 0xf9a: mov    rdx,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_f9d:
	/* 0xf9d: add    rdx,0x7 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 7ULL);
x86_l_fa1:
	/* 0xfa1: mov    esi,0x3 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 3ULL);
x86_l_fa6:
	/* 0xfa6: sub    rsi,r9 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_R9, X86_WIDTH_64, X86_ALU_SUB, 0);
x86_l_fa9:
	/* 0xfa9: mov    edi,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_fae:
	/* 0xfae: sub    rdi,r9 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDI, X86_R9, X86_WIDTH_64, X86_ALU_SUB, 0);
x86_l_fb1:
	/* 0xfb1: mov    r8d,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_fb7:
	/* 0xfb7: sub    r8,r9 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R8, X86_R9, X86_WIDTH_64, X86_ALU_SUB, 0);
x86_l_fba:
	/* 0xfba: neg    r9 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_fbd:
	/* 0xfbd: lea    r10d,[rbx-0x3] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R10, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_fc1:
	/* 0xfc1: lea    r11d,[rbx-0x2] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R11, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_fc5:
	/* 0xfc5: dec    ebx */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_fc7:
	/* 0xfc7: xor    r12d,r12d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_fca:
	/* 0xfca: lea    r13d,[rbx+r12*1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R13, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_fce:
	/* 0xfce: and    r13d,0xfff */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_fd5:
	/* 0xfd5: movzx  ebp,BYTE PTR [r14+r13*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBP, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_8), 0ULL);
x86_l_fda:
	/* 0xfda: mov    BYTE PTR [rdx-0x3],bpl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_fde:
	/* 0xfde: cmp    r8,r12 */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_R8, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_fe1:
	/* 0xfe1: je     103b <filter_char_buf_postfix+0x111> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xfe1, 0x103b, x86_l_103b);
x86_l_fe3:
	/* 0xfe3: lea    r13d,[r11+r12*1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R13, X86_R11, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_fe7:
	/* 0xfe7: and    r13d,0xfff */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_fee:
	/* 0xfee: movzx  ebp,BYTE PTR [r14+r13*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBP, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_8), 0ULL);
x86_l_ff3:
	/* 0xff3: mov    BYTE PTR [rdx-0x2],bpl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_ff7:
	/* 0xff7: cmp    rdi,r12 */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RDI, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_ffa:
	/* 0xffa: je     103b <filter_char_buf_postfix+0x111> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xffa, 0x103b, x86_l_103b);
x86_l_ffc:
	/* 0xffc: lea    r13d,[r10+r12*1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R13, X86_R10, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_1000:
	/* 0x1000: and    r13d,0xfff */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1007:
	/* 0x1007: movzx  ebp,BYTE PTR [r14+r13*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBP, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_8), 0ULL);
x86_l_100c:
	/* 0x100c: mov    BYTE PTR [rdx-0x1],bpl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_1010:
	/* 0x1010: cmp    rsi,r12 */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RSI, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_1013:
	/* 0x1013: je     103b <filter_char_buf_postfix+0x111> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1013, 0x103b, x86_l_103b);
x86_l_1015:
	/* 0x1015: cmp    r12,0xffffffffffffff84 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, 0, 18446744073709551492ULL);
x86_l_1019:
	/* 0x1019: je     103b <filter_char_buf_postfix+0x111> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1019, 0x103b, x86_l_103b);
x86_l_101b:
	/* 0x101b: lea    r13d,[rcx+r12*1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_101f:
	/* 0x101f: and    r13d,0xfff */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1026:
	/* 0x1026: movzx  ebp,BYTE PTR [r14+r13*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBP, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_8), 0ULL);
x86_l_102b:
	/* 0x102b: mov    BYTE PTR [rdx],bpl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_102e:
	/* 0x102e: add    r12,0xfffffffffffffffc */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551612ULL);
x86_l_1032:
	/* 0x1032: add    rdx,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1036:
	/* 0x1036: cmp    r9,r12 */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_R9, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_1039:
	/* 0x1039: jne    fca <filter_char_buf_postfix+0xa0> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x1039, 0xfca, x86_l_fca);
x86_l_103b:
	/* 0x103b: mov    rdi,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_103e:
	/* 0x103e: mov    rsi,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_1041:
	/* 0x1041: call   34b6 <__native_link_local_memset_zero_dynamic+0x124d> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_1046:
	/* 0x1046: mov    rcx,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_1049:
	/* 0x1049: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_104b:
	/* 0x104b: test   rcx,rcx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_104e:
	/* 0x104e: setne  al */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_CC_NE, 0);
x86_l_1051:
	/* 0x1051: jmp    1055 <filter_char_buf_postfix+0x12b> */
	X86_SIM_X86_SUB_JMP(0x1051, 0x1055, x86_l_1055);
x86_l_1053:
	/* 0x1053: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1055:
	/* 0x1055: add    rsp,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1059:
	/* 0x1059: pop    rbx */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_105a:
	/* 0x105a: pop    r12 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R12, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_105c:
	/* 0x105c: pop    r13 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R13, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_105e:
	/* 0x105e: pop    r14 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R14, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1060:
	/* 0x1060: pop    r15 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R15, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1062:
	/* 0x1062: pop    rbp */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBP, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1063:
	/* 0x1063: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_1063);

	/* native subroutine native_link_sub_1064 */
x86_l_1064:
	/* 0x1064: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1067:
	/* 0x1067: lea    edx,[rcx-0x1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_106a:
	/* 0x106a: cmp    edx,0x24 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 36ULL);
x86_l_106d:
	/* 0x106d: ja     123c <filter_16ty_selector_val+0x1d8> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x106d, 0x123c, x86_l_123c);
x86_l_1073:
	/* 0x1073: mov    eax,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_1078:
	/* Capture image-bound code identity before scheduled instructions. */
	switch (X86_SIM_L_READ_REG(X86_RDX) << 2) {
	case 0ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x10c5ULL); break;
	case 4ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1167ULL); break;
	case 8ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1089ULL); break;
	case 12ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1089ULL); break;
	case 16ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x123cULL); break;
	case 20ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1088ULL); break;
	case 24ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x123cULL); break;
	case 28ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x123cULL); break;
	case 32ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x123cULL); break;
	case 36ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x123cULL); break;
	case 40ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x123cULL); break;
	case 44ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x111dULL); break;
	case 48ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x123cULL); break;
	case 52ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x123cULL); break;
	case 56ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x123cULL); break;
	case 60ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x123cULL); break;
	case 64ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x123cULL); break;
	case 68ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x123cULL); break;
	case 72ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x123cULL); break;
	case 76ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x123cULL); break;
	case 80ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x123cULL); break;
	case 84ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x123cULL); break;
	case 88ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x123cULL); break;
	case 92ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x123cULL); break;
	case 96ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x123cULL); break;
	case 100ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1088ULL); break;
	case 104ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1088ULL); break;
	case 108ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x123cULL); break;
	case 112ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x123cULL); break;
	case 116ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x123cULL); break;
	case 120ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x123cULL); break;
	case 124ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x123cULL); break;
	case 128ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x123cULL); break;
	case 132ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x123cULL); break;
	case 136ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x123cULL); break;
	case 140ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x123cULL); break;
	case 144ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1088ULL); break;
	default: __x86_sim_unresolved_indirect_target();
	}
x86_l_1086:
	/* 0x1086: jmp    rdx */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RDX);
		switch (X86_SIM_L_REG_TAG(X86_RDX)) {
		case X86_SIM_TAG_CODE:
			switch (__x86_target) {
			case 0x1088ULL: goto x86_l_1088;
			case 0x1089ULL: goto x86_l_1089;
			case 0x10c5ULL: goto x86_l_10c5;
			case 0x111dULL: goto x86_l_111d;
			case 0x1167ULL: goto x86_l_1167;
			case 0x123cULL: goto x86_l_123c;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_1088:
	/* 0x1088: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_764);
x86_l_1089:
	/* 0x1089: movzx  edx,WORD PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_108c:
	/* 0x108c: cmp    DWORD PTR [rdi+0x10],edx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_108f:
	/* 0x108f: jne    109a <filter_16ty_selector_val+0x36> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x108f, 0x109a, x86_l_109a);
x86_l_1091:
	/* 0x1091: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1093:
	/* 0x1093: cmp    ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 3ULL);
x86_l_1096:
	/* 0x1096: sete   al */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_CC_E, 0);
x86_l_1099:
	/* 0x1099: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_764);
x86_l_109a:
	/* 0x109a: mov    esi,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_109d:
	/* 0x109d: cmp    esi,0xd */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 13ULL);
x86_l_10a0:
	/* 0x10a0: jb     10bb <filter_16ty_selector_val+0x57> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x10a0, 0x10bb, x86_l_10bb);
x86_l_10a2:
	/* 0x10a2: cmp    DWORD PTR [rdi+0x14],edx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_10a5:
	/* 0x10a5: je     1091 <filter_16ty_selector_val+0x2d> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x10a5, 0x1091, x86_l_1091);
x86_l_10a7:
	/* 0x10a7: cmp    esi,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_10aa:
	/* 0x10aa: jb     10bb <filter_16ty_selector_val+0x57> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x10aa, 0x10bb, x86_l_10bb);
x86_l_10ac:
	/* 0x10ac: cmp    DWORD PTR [rdi+0x18],edx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_10af:
	/* 0x10af: je     1091 <filter_16ty_selector_val+0x2d> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x10af, 0x1091, x86_l_1091);
x86_l_10b1:
	/* 0x10b1: cmp    esi,0x15 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 21ULL);
x86_l_10b4:
	/* 0x10b4: jb     10bb <filter_16ty_selector_val+0x57> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x10b4, 0x10bb, x86_l_10bb);
x86_l_10b6:
	/* 0x10b6: cmp    DWORD PTR [rdi+0x1c],edx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_10b9:
	/* 0x10b9: je     1091 <filter_16ty_selector_val+0x2d> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x10b9, 0x1091, x86_l_1091);
x86_l_10bb:
	/* 0x10bb: cmp    ecx,0x4 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_10be:
	/* 0x10be: je     1088 <filter_16ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x10be, 0x1088, x86_l_1088);
x86_l_10c0:
	/* 0x10c0: jmp    123c <filter_16ty_selector_val+0x1d8> */
	X86_SIM_X86_SUB_JMP(0x10c0, 0x123c, x86_l_123c);
x86_l_10c5:
	/* 0x10c5: mov    ecx,DWORD PTR [rdi+0xc] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_10c8:
	/* 0x10c8: cmp    ecx,0xc */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 12ULL);
x86_l_10cb:
	/* 0x10cb: ja     11c8 <filter_16ty_selector_val+0x164> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x10cb, 0x11c8, x86_l_11c8);
x86_l_10d1:
	/* 0x10d1: mov    edx,0x1402 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 5122ULL);
x86_l_10d6:
	/* 0x10d6: bt     edx,ecx */
	X86_SIM_RUN_OP(X86_OP_BT, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_10d9:
	/* 0x10d9: jae    11c8 <filter_16ty_selector_val+0x164> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x10d9, 0x11c8, x86_l_11c8);
x86_l_10df:
	/* 0x10df: movsx  ecx,WORD PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOVSX_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_10e2:
	/* 0x10e2: cmp    DWORD PTR [rdi+0x10],ecx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10e5:
	/* 0x10e5: jl     1088 <filter_16ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_L, 0x10e5, 0x1088, x86_l_1088);
x86_l_10e7:
	/* 0x10e7: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10ea:
	/* 0x10ea: cmp    edx,0xd */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 13ULL);
x86_l_10ed:
	/* 0x10ed: jb     123c <filter_16ty_selector_val+0x1d8> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x10ed, 0x123c, x86_l_123c);
x86_l_10f3:
	/* 0x10f3: cmp    DWORD PTR [rdi+0x14],ecx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_10f6:
	/* 0x10f6: jl     1088 <filter_16ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_L, 0x10f6, 0x1088, x86_l_1088);
x86_l_10f8:
	/* 0x10f8: cmp    edx,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_10fb:
	/* 0x10fb: jb     123c <filter_16ty_selector_val+0x1d8> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x10fb, 0x123c, x86_l_123c);
x86_l_1101:
	/* 0x1101: cmp    DWORD PTR [rdi+0x18],ecx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1104:
	/* 0x1104: jl     1088 <filter_16ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_L, 0x1104, 0x1088, x86_l_1088);
x86_l_1106:
	/* 0x1106: cmp    edx,0x15 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 21ULL);
x86_l_1109:
	/* 0x1109: jb     123c <filter_16ty_selector_val+0x1d8> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1109, 0x123c, x86_l_123c);
x86_l_110f:
	/* 0x110f: cmp    DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1112:
	/* 0x1112: jl     1088 <filter_16ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_L, 0x1112, 0x1088, x86_l_1088);
x86_l_1118:
	/* 0x1118: jmp    123c <filter_16ty_selector_val+0x1d8> */
	X86_SIM_X86_SUB_JMP(0x1118, 0x123c, x86_l_123c);
x86_l_111d:
	/* 0x111d: movzx  ecx,WORD PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1120:
	/* 0x1120: test   DWORD PTR [rdi+0x10],ecx */
	X86_SIM_RUN_OP(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1123:
	/* 0x1123: jne    1088 <filter_16ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x1123, 0x1088, x86_l_1088);
x86_l_1129:
	/* 0x1129: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_112c:
	/* 0x112c: cmp    edx,0xd */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 13ULL);
x86_l_112f:
	/* 0x112f: jb     123c <filter_16ty_selector_val+0x1d8> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x112f, 0x123c, x86_l_123c);
x86_l_1135:
	/* 0x1135: test   DWORD PTR [rdi+0x14],ecx */
	X86_SIM_RUN_OP(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_1138:
	/* 0x1138: jne    1088 <filter_16ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x1138, 0x1088, x86_l_1088);
x86_l_113e:
	/* 0x113e: cmp    edx,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_1141:
	/* 0x1141: jb     123c <filter_16ty_selector_val+0x1d8> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1141, 0x123c, x86_l_123c);
x86_l_1147:
	/* 0x1147: test   DWORD PTR [rdi+0x18],ecx */
	X86_SIM_RUN_OP(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_114a:
	/* 0x114a: jne    1088 <filter_16ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x114a, 0x1088, x86_l_1088);
x86_l_1150:
	/* 0x1150: cmp    edx,0x15 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 21ULL);
x86_l_1153:
	/* 0x1153: jb     123c <filter_16ty_selector_val+0x1d8> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1153, 0x123c, x86_l_123c);
x86_l_1159:
	/* 0x1159: test   DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_RUN_OP(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120259084288ULL);
x86_l_115c:
	/* 0x115c: jne    1088 <filter_16ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x115c, 0x1088, x86_l_1088);
x86_l_1162:
	/* 0x1162: jmp    123c <filter_16ty_selector_val+0x1d8> */
	X86_SIM_X86_SUB_JMP(0x1162, 0x123c, x86_l_123c);
x86_l_1167:
	/* 0x1167: mov    ecx,DWORD PTR [rdi+0xc] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_116a:
	/* 0x116a: cmp    ecx,0xc */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 12ULL);
x86_l_116d:
	/* 0x116d: ja     1203 <filter_16ty_selector_val+0x19f> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x116d, 0x1203, x86_l_1203);
x86_l_1173:
	/* 0x1173: mov    edx,0x1402 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 5122ULL);
x86_l_1178:
	/* 0x1178: bt     edx,ecx */
	X86_SIM_RUN_OP(X86_OP_BT, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_117b:
	/* 0x117b: jae    1203 <filter_16ty_selector_val+0x19f> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x117b, 0x1203, x86_l_1203);
x86_l_1181:
	/* 0x1181: movsx  ecx,WORD PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOVSX_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1184:
	/* 0x1184: cmp    DWORD PTR [rdi+0x10],ecx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1187:
	/* 0x1187: jg     1088 <filter_16ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x1187, 0x1088, x86_l_1088);
x86_l_118d:
	/* 0x118d: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1190:
	/* 0x1190: cmp    edx,0xd */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 13ULL);
x86_l_1193:
	/* 0x1193: jb     123c <filter_16ty_selector_val+0x1d8> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1193, 0x123c, x86_l_123c);
x86_l_1199:
	/* 0x1199: cmp    DWORD PTR [rdi+0x14],ecx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_119c:
	/* 0x119c: jg     1088 <filter_16ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x119c, 0x1088, x86_l_1088);
x86_l_11a2:
	/* 0x11a2: cmp    edx,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_11a5:
	/* 0x11a5: jb     123c <filter_16ty_selector_val+0x1d8> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x11a5, 0x123c, x86_l_123c);
x86_l_11ab:
	/* 0x11ab: cmp    DWORD PTR [rdi+0x18],ecx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_11ae:
	/* 0x11ae: jg     1088 <filter_16ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x11ae, 0x1088, x86_l_1088);
x86_l_11b4:
	/* 0x11b4: cmp    edx,0x15 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 21ULL);
x86_l_11b7:
	/* 0x11b7: jb     123c <filter_16ty_selector_val+0x1d8> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x11b7, 0x123c, x86_l_123c);
x86_l_11bd:
	/* 0x11bd: cmp    DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_11c0:
	/* 0x11c0: jg     1088 <filter_16ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x11c0, 0x1088, x86_l_1088);
x86_l_11c6:
	/* 0x11c6: jmp    123c <filter_16ty_selector_val+0x1d8> */
	X86_SIM_X86_SUB_JMP(0x11c6, 0x123c, x86_l_123c);
x86_l_11c8:
	/* 0x11c8: movzx  ecx,WORD PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_11cb:
	/* 0x11cb: cmp    DWORD PTR [rdi+0x10],ecx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11ce:
	/* 0x11ce: jb     1088 <filter_16ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x11ce, 0x1088, x86_l_1088);
x86_l_11d4:
	/* 0x11d4: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11d7:
	/* 0x11d7: cmp    edx,0xd */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 13ULL);
x86_l_11da:
	/* 0x11da: jb     123c <filter_16ty_selector_val+0x1d8> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x11da, 0x123c, x86_l_123c);
x86_l_11dc:
	/* 0x11dc: cmp    DWORD PTR [rdi+0x14],ecx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_11df:
	/* 0x11df: jb     1088 <filter_16ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x11df, 0x1088, x86_l_1088);
x86_l_11e5:
	/* 0x11e5: cmp    edx,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_11e8:
	/* 0x11e8: jb     123c <filter_16ty_selector_val+0x1d8> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x11e8, 0x123c, x86_l_123c);
x86_l_11ea:
	/* 0x11ea: cmp    DWORD PTR [rdi+0x18],ecx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_11ed:
	/* 0x11ed: jb     1088 <filter_16ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x11ed, 0x1088, x86_l_1088);
x86_l_11f3:
	/* 0x11f3: cmp    edx,0x15 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 21ULL);
x86_l_11f6:
	/* 0x11f6: jb     123c <filter_16ty_selector_val+0x1d8> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x11f6, 0x123c, x86_l_123c);
x86_l_11f8:
	/* 0x11f8: cmp    DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_11fb:
	/* 0x11fb: jb     1088 <filter_16ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x11fb, 0x1088, x86_l_1088);
x86_l_1201:
	/* 0x1201: jmp    123c <filter_16ty_selector_val+0x1d8> */
	X86_SIM_X86_SUB_JMP(0x1201, 0x123c, x86_l_123c);
x86_l_1203:
	/* 0x1203: movzx  ecx,WORD PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1206:
	/* 0x1206: cmp    DWORD PTR [rdi+0x10],ecx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1209:
	/* 0x1209: ja     1088 <filter_16ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x1209, 0x1088, x86_l_1088);
x86_l_120f:
	/* 0x120f: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1212:
	/* 0x1212: cmp    edx,0xd */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 13ULL);
x86_l_1215:
	/* 0x1215: jb     123c <filter_16ty_selector_val+0x1d8> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1215, 0x123c, x86_l_123c);
x86_l_1217:
	/* 0x1217: cmp    DWORD PTR [rdi+0x14],ecx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_121a:
	/* 0x121a: ja     1088 <filter_16ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x121a, 0x1088, x86_l_1088);
x86_l_1220:
	/* 0x1220: cmp    edx,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_1223:
	/* 0x1223: jb     123c <filter_16ty_selector_val+0x1d8> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1223, 0x123c, x86_l_123c);
x86_l_1225:
	/* 0x1225: cmp    DWORD PTR [rdi+0x18],ecx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1228:
	/* 0x1228: ja     1088 <filter_16ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x1228, 0x1088, x86_l_1088);
x86_l_122e:
	/* 0x122e: cmp    edx,0x15 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 21ULL);
x86_l_1231:
	/* 0x1231: jb     123c <filter_16ty_selector_val+0x1d8> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1231, 0x123c, x86_l_123c);
x86_l_1233:
	/* 0x1233: cmp    DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1236:
	/* 0x1236: ja     1088 <filter_16ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x1236, 0x1088, x86_l_1088);
x86_l_123c:
	/* 0x123c: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_123e:
	/* 0x123e: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_764);

	/* native subroutine native_link_sub_123f */
x86_l_123f:
	/* 0x123f: push   r14 */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_1241:
	/* 0x1241: push   rbx */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_1242:
	/* 0x1242: sub    rsp,0x18 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SUB, 24ULL);
x86_l_1246:
	/* 0x1246: mov    r14,rsi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R14, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_1249:
	/* 0x1249: mov    rbx,rdi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RBX, X86_RDI, X86_WIDTH_64, 0, 0);
x86_l_124c:
	/* 0x124c: movzx  eax,BYTE PTR [rdi+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_1250:
	/* 0x1250: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1254:
	/* 0x1254: mov    rdi,QWORD PTR [rip+0x1430] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)argfilter_maps));
x86_l_125b:
	/* 0x125b: lea    rsi,[rsp+0xc] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1260:
	/* 0x1260: call   2695 <__native_link_local_memset_zero_dynamic+0x42c> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_1265:
	/* 0x1265: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_1268:
	/* 0x1268: je     129c <filter_16ty_map+0x5d> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1268, 0x129c, x86_l_129c);
x86_l_126a:
	/* 0x126a: movzx  ecx,WORD PTR [r14] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_126e:
	/* 0x126e: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1273:
	/* 0x1273: lea    rsi,[rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1278:
	/* 0x1278: mov    rdi,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_127b:
	/* 0x127b: call   26b0 <__native_link_local_memset_zero_dynamic+0x447> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_1280:
	/* 0x1280: mov    edx,DWORD PTR [rbx+0x4] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1283:
	/* 0x1283: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1285:
	/* 0x1285: cmp    edx,0x1d */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 29ULL);
x86_l_1288:
	/* 0x1288: ja     12b6 <filter_16ty_map+0x77> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x1288, 0x12b6, x86_l_12b6);
x86_l_128a:
	/* 0x128a: mov    esi,0x30038400 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 805536768ULL);
x86_l_128f:
	/* 0x128f: bt     esi,edx */
	X86_SIM_RUN_OP(X86_OP_BT, X86_RSI, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_1292:
	/* 0x1292: jae    12a6 <filter_16ty_map+0x67> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x1292, 0x12a6, x86_l_12a6);
x86_l_1294:
	/* 0x1294: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_1297:
	/* 0x1297: setne  cl */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_CC_NE, 0);
x86_l_129a:
	/* 0x129a: jmp    12b6 <filter_16ty_map+0x77> */
	X86_SIM_X86_SUB_JMP(0x129a, 0x12b6, x86_l_12b6);
x86_l_129c:
	/* 0x129c: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_129e:
	/* 0x129e: add    rsp,0x18 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_12a2:
	/* 0x12a2: pop    rbx */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_12a3:
	/* 0x12a3: pop    r14 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R14, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_12a5:
	/* 0x12a5: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_764);
x86_l_12a6:
	/* 0x12a6: mov    esi,0xc0800 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 788480ULL);
x86_l_12ab:
	/* 0x12ab: bt     esi,edx */
	X86_SIM_RUN_OP(X86_OP_BT, X86_RSI, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_12ae:
	/* 0x12ae: jae    12b6 <filter_16ty_map+0x77> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x12ae, 0x12b6, x86_l_12b6);
x86_l_12b0:
	/* 0x12b0: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_12b3:
	/* 0x12b3: sete   cl */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_CC_E, 0);
x86_l_12b6:
	/* 0x12b6: movzx  eax,cl */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8, 0);
x86_l_12b9:
	/* 0x12b9: add    rsp,0x18 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_12bd:
	/* 0x12bd: pop    rbx */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_12be:
	/* 0x12be: pop    r14 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R14, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_12c0:
	/* 0x12c0: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_764);

	/* native subroutine native_link_sub_12c1 */
x86_l_12c1:
	/* 0x12c1: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_12c4:
	/* 0x12c4: mov    eax,DWORD PTR [rdi+0xc] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_12c7:
	/* 0x12c7: cmp    eax,0xc */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 12ULL);
x86_l_12ca:
	/* 0x12ca: ja     13b1 <filter_16ty_range+0xf0> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x12ca, 0x13b1, x86_l_13b1);
x86_l_12d0:
	/* 0x12d0: mov    edx,0x1402 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 5122ULL);
x86_l_12d5:
	/* 0x12d5: bt     edx,eax */
	X86_SIM_RUN_OP(X86_OP_BT, X86_RDX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_12d8:
	/* 0x12d8: jae    13b1 <filter_16ty_range+0xf0> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x12d8, 0x13b1, x86_l_13b1);
x86_l_12de:
	/* 0x12de: movsx  esi,WORD PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOVSX_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_12e1:
	/* 0x12e1: cmp    ecx,0x1f */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 31ULL);
x86_l_12e4:
	/* 0x12e4: jne    134c <filter_16ty_range+0x8b> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x12e4, 0x134c, x86_l_134c);
x86_l_12e6:
	/* 0x12e6: mov    eax,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_12eb:
	/* 0x12eb: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_12ee:
	/* 0x12ee: jg     12f9 <filter_16ty_range+0x38> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x12ee, 0x12f9, x86_l_12f9);
x86_l_12f0:
	/* 0x12f0: cmp    DWORD PTR [rdi+0x14],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_12f3:
	/* 0x12f3: jge    13c8 <filter_16ty_range+0x107> */
	X86_SIM_X86_SUB_JCC(X86_CC_GE, 0x12f3, 0x13c8, x86_l_13c8);
x86_l_12f9:
	/* 0x12f9: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12fc:
	/* 0x12fc: cmp    edx,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_12ff:
	/* 0x12ff: jb     1468 <filter_16ty_range+0x1a7> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x12ff, 0x1468, x86_l_1468);
x86_l_1305:
	/* 0x1305: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1308:
	/* 0x1308: jg     1313 <filter_16ty_range+0x52> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x1308, 0x1313, x86_l_1313);
x86_l_130a:
	/* 0x130a: cmp    DWORD PTR [rdi+0x1c],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_130d:
	/* 0x130d: jge    13c8 <filter_16ty_range+0x107> */
	X86_SIM_X86_SUB_JCC(X86_CC_GE, 0x130d, 0x13c8, x86_l_13c8);
x86_l_1313:
	/* 0x1313: cmp    edx,0x19 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 25ULL);
x86_l_1316:
	/* 0x1316: jb     1468 <filter_16ty_range+0x1a7> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1316, 0x1468, x86_l_1468);
x86_l_131c:
	/* 0x131c: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_131f:
	/* 0x131f: jg     132a <filter_16ty_range+0x69> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x131f, 0x132a, x86_l_132a);
x86_l_1321:
	/* 0x1321: cmp    DWORD PTR [rdi+0x24],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1324:
	/* 0x1324: jge    13c8 <filter_16ty_range+0x107> */
	X86_SIM_X86_SUB_JCC(X86_CC_GE, 0x1324, 0x13c8, x86_l_13c8);
x86_l_132a:
	/* 0x132a: cmp    edx,0x21 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 33ULL);
x86_l_132d:
	/* 0x132d: jb     1468 <filter_16ty_range+0x1a7> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x132d, 0x1468, x86_l_1468);
x86_l_1333:
	/* 0x1333: xor    edx,edx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1335:
	/* 0x1335: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1338:
	/* 0x1338: jg     146a <filter_16ty_range+0x1a9> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x1338, 0x146a, x86_l_146a);
x86_l_133e:
	/* 0x133e: cmp    DWORD PTR [rdi+0x2c],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1341:
	/* 0x1341: jge    13c8 <filter_16ty_range+0x107> */
	X86_SIM_X86_SUB_JCC(X86_CC_GE, 0x1341, 0x13c8, x86_l_13c8);
x86_l_1347:
	/* 0x1347: jmp    146a <filter_16ty_range+0x1a9> */
	X86_SIM_X86_SUB_JMP(0x1347, 0x146a, x86_l_146a);
x86_l_134c:
	/* 0x134c: mov    eax,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_134f:
	/* 0x134f: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1352:
	/* 0x1352: setle  r8b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R8, X86_REG_NONE, X86_WIDTH_8, X86_CC_LE, 0);
x86_l_1356:
	/* 0x1356: cmp    DWORD PTR [rdi+0x14],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1359:
	/* 0x1359: setge  dl */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_CC_GE, 0);
x86_l_135c:
	/* 0x135c: and    dl,r8b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_R8, X86_WIDTH_8, X86_ALU_AND, 0);
x86_l_135f:
	/* 0x135f: cmp    eax,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_1362:
	/* 0x1362: jb     146a <filter_16ty_range+0x1a9> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1362, 0x146a, x86_l_146a);
x86_l_1368:
	/* 0x1368: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_136b:
	/* 0x136b: setle  r8b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R8, X86_REG_NONE, X86_WIDTH_8, X86_CC_LE, 0);
x86_l_136f:
	/* 0x136f: cmp    DWORD PTR [rdi+0x1c],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1372:
	/* 0x1372: setge  r9b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R9, X86_REG_NONE, X86_WIDTH_8, X86_CC_GE, 0);
x86_l_1376:
	/* 0x1376: and    r9b,r8b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND, 0);
x86_l_1379:
	/* 0x1379: or     dl,r9b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR, 0);
x86_l_137c:
	/* 0x137c: cmp    eax,0x19 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 25ULL);
x86_l_137f:
	/* 0x137f: jb     146a <filter_16ty_range+0x1a9> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x137f, 0x146a, x86_l_146a);
x86_l_1385:
	/* 0x1385: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1388:
	/* 0x1388: setle  r8b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R8, X86_REG_NONE, X86_WIDTH_8, X86_CC_LE, 0);
x86_l_138c:
	/* 0x138c: cmp    DWORD PTR [rdi+0x24],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_138f:
	/* 0x138f: setge  r9b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R9, X86_REG_NONE, X86_WIDTH_8, X86_CC_GE, 0);
x86_l_1393:
	/* 0x1393: and    r9b,r8b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND, 0);
x86_l_1396:
	/* 0x1396: or     dl,r9b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR, 0);
x86_l_1399:
	/* 0x1399: cmp    eax,0x21 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 33ULL);
x86_l_139c:
	/* 0x139c: jb     146a <filter_16ty_range+0x1a9> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x139c, 0x146a, x86_l_146a);
x86_l_13a2:
	/* 0x13a2: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_13a5:
	/* 0x13a5: setle  al */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_CC_LE, 0);
x86_l_13a8:
	/* 0x13a8: cmp    DWORD PTR [rdi+0x2c],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_13ab:
	/* 0x13ab: setge  sil */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_CC_GE, 0);
x86_l_13af:
	/* 0x13af: jmp    1424 <filter_16ty_range+0x163> */
	X86_SIM_X86_SUB_JMP(0x13af, 0x1424, x86_l_1424);
x86_l_13b1:
	/* 0x13b1: movzx  esi,WORD PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_13b4:
	/* 0x13b4: cmp    ecx,0x1f */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 31ULL);
x86_l_13b7:
	/* 0x13b7: jne    13c9 <filter_16ty_range+0x108> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x13b7, 0x13c9, x86_l_13c9);
x86_l_13b9:
	/* 0x13b9: mov    eax,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_13be:
	/* 0x13be: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_13c1:
	/* 0x13c1: ja     142c <filter_16ty_range+0x16b> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x13c1, 0x142c, x86_l_142c);
x86_l_13c3:
	/* 0x13c3: cmp    DWORD PTR [rdi+0x14],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_13c6:
	/* 0x13c6: jb     142c <filter_16ty_range+0x16b> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x13c6, 0x142c, x86_l_142c);
x86_l_13c8:
	/* 0x13c8: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_764);
x86_l_13c9:
	/* 0x13c9: mov    eax,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_13cc:
	/* 0x13cc: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_13cf:
	/* 0x13cf: setbe  r8b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R8, X86_REG_NONE, X86_WIDTH_8, X86_CC_BE, 0);
x86_l_13d3:
	/* 0x13d3: cmp    DWORD PTR [rdi+0x14],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_13d6:
	/* 0x13d6: setae  dl */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_CC_AE, 0);
x86_l_13d9:
	/* 0x13d9: and    dl,r8b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_R8, X86_WIDTH_8, X86_ALU_AND, 0);
x86_l_13dc:
	/* 0x13dc: cmp    eax,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_13df:
	/* 0x13df: jb     146a <filter_16ty_range+0x1a9> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x13df, 0x146a, x86_l_146a);
x86_l_13e5:
	/* 0x13e5: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_13e8:
	/* 0x13e8: setbe  r8b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R8, X86_REG_NONE, X86_WIDTH_8, X86_CC_BE, 0);
x86_l_13ec:
	/* 0x13ec: cmp    DWORD PTR [rdi+0x1c],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_13ef:
	/* 0x13ef: setae  r9b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R9, X86_REG_NONE, X86_WIDTH_8, X86_CC_AE, 0);
x86_l_13f3:
	/* 0x13f3: and    r9b,r8b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND, 0);
x86_l_13f6:
	/* 0x13f6: or     dl,r9b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR, 0);
x86_l_13f9:
	/* 0x13f9: cmp    eax,0x19 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 25ULL);
x86_l_13fc:
	/* 0x13fc: jb     146a <filter_16ty_range+0x1a9> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x13fc, 0x146a, x86_l_146a);
x86_l_13fe:
	/* 0x13fe: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1401:
	/* 0x1401: setbe  r8b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R8, X86_REG_NONE, X86_WIDTH_8, X86_CC_BE, 0);
x86_l_1405:
	/* 0x1405: cmp    DWORD PTR [rdi+0x24],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1408:
	/* 0x1408: setae  r9b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R9, X86_REG_NONE, X86_WIDTH_8, X86_CC_AE, 0);
x86_l_140c:
	/* 0x140c: and    r9b,r8b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND, 0);
x86_l_140f:
	/* 0x140f: or     dl,r9b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR, 0);
x86_l_1412:
	/* 0x1412: cmp    eax,0x21 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 33ULL);
x86_l_1415:
	/* 0x1415: jb     146a <filter_16ty_range+0x1a9> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1415, 0x146a, x86_l_146a);
x86_l_1417:
	/* 0x1417: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_141a:
	/* 0x141a: setbe  al */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_CC_BE, 0);
x86_l_141d:
	/* 0x141d: cmp    DWORD PTR [rdi+0x2c],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1420:
	/* 0x1420: setae  sil */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_CC_AE, 0);
x86_l_1424:
	/* 0x1424: and    sil,al */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_ALU_AND, 0);
x86_l_1427:
	/* 0x1427: or     dl,sil */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RSI, X86_WIDTH_8, X86_ALU_OR, 0);
x86_l_142a:
	/* 0x142a: jmp    146a <filter_16ty_range+0x1a9> */
	X86_SIM_X86_SUB_JMP(0x142a, 0x146a, x86_l_146a);
x86_l_142c:
	/* 0x142c: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_142f:
	/* 0x142f: cmp    edx,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_1432:
	/* 0x1432: jb     1468 <filter_16ty_range+0x1a7> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1432, 0x1468, x86_l_1468);
x86_l_1434:
	/* 0x1434: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1437:
	/* 0x1437: ja     143e <filter_16ty_range+0x17d> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x1437, 0x143e, x86_l_143e);
x86_l_1439:
	/* 0x1439: cmp    DWORD PTR [rdi+0x1c],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_143c:
	/* 0x143c: jae    13c8 <filter_16ty_range+0x107> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x143c, 0x13c8, x86_l_13c8);
x86_l_143e:
	/* 0x143e: cmp    edx,0x19 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 25ULL);
x86_l_1441:
	/* 0x1441: jb     1468 <filter_16ty_range+0x1a7> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1441, 0x1468, x86_l_1468);
x86_l_1443:
	/* 0x1443: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1446:
	/* 0x1446: ja     1451 <filter_16ty_range+0x190> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x1446, 0x1451, x86_l_1451);
x86_l_1448:
	/* 0x1448: cmp    DWORD PTR [rdi+0x24],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_144b:
	/* 0x144b: jae    13c8 <filter_16ty_range+0x107> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x144b, 0x13c8, x86_l_13c8);
x86_l_1451:
	/* 0x1451: cmp    edx,0x21 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 33ULL);
x86_l_1454:
	/* 0x1454: jb     1468 <filter_16ty_range+0x1a7> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1454, 0x1468, x86_l_1468);
x86_l_1456:
	/* 0x1456: xor    edx,edx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1458:
	/* 0x1458: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_145b:
	/* 0x145b: ja     146a <filter_16ty_range+0x1a9> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x145b, 0x146a, x86_l_146a);
x86_l_145d:
	/* 0x145d: cmp    DWORD PTR [rdi+0x2c],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1460:
	/* 0x1460: jae    13c8 <filter_16ty_range+0x107> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x1460, 0x13c8, x86_l_13c8);
x86_l_1466:
	/* 0x1466: jmp    146a <filter_16ty_range+0x1a9> */
	X86_SIM_X86_SUB_JMP(0x1466, 0x146a, x86_l_146a);
x86_l_1468:
	/* 0x1468: xor    edx,edx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_146a:
	/* 0x146a: cmp    ecx,0x20 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 32ULL);
x86_l_146d:
	/* 0x146d: sete   al */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_CC_E, 0);
x86_l_1470:
	/* 0x1470: xor    dl,0x1 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_ALU_XOR, 1ULL);
x86_l_1473:
	/* 0x1473: and    dl,al */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RAX, X86_WIDTH_8, X86_ALU_AND, 0);
x86_l_1475:
	/* 0x1475: movzx  eax,dl */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8, 0);
x86_l_1478:
	/* 0x1478: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_764);

	/* native subroutine native_link_sub_1479 */
x86_l_1479:
	/* 0x1479: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_147c:
	/* 0x147c: lea    edx,[rcx-0x1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_147f:
	/* 0x147f: cmp    edx,0x24 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 36ULL);
x86_l_1482:
	/* 0x1482: ja     1651 <filter_8ty_selector_val+0x1d8> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x1482, 0x1651, x86_l_1651);
x86_l_1488:
	/* 0x1488: mov    eax,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_148d:
	/* Capture image-bound code identity before scheduled instructions. */
	switch (X86_SIM_L_READ_REG(X86_RDX) << 2) {
	case 0ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x14daULL); break;
	case 4ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x157cULL); break;
	case 8ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x149eULL); break;
	case 12ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x149eULL); break;
	case 16ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1651ULL); break;
	case 20ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x149dULL); break;
	case 24ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1651ULL); break;
	case 28ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1651ULL); break;
	case 32ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1651ULL); break;
	case 36ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1651ULL); break;
	case 40ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1651ULL); break;
	case 44ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1532ULL); break;
	case 48ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1651ULL); break;
	case 52ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1651ULL); break;
	case 56ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1651ULL); break;
	case 60ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1651ULL); break;
	case 64ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1651ULL); break;
	case 68ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1651ULL); break;
	case 72ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1651ULL); break;
	case 76ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1651ULL); break;
	case 80ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1651ULL); break;
	case 84ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1651ULL); break;
	case 88ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1651ULL); break;
	case 92ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1651ULL); break;
	case 96ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1651ULL); break;
	case 100ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x149dULL); break;
	case 104ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x149dULL); break;
	case 108ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1651ULL); break;
	case 112ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1651ULL); break;
	case 116ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1651ULL); break;
	case 120ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1651ULL); break;
	case 124ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1651ULL); break;
	case 128ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1651ULL); break;
	case 132ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1651ULL); break;
	case 136ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1651ULL); break;
	case 140ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1651ULL); break;
	case 144ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x149dULL); break;
	default: __x86_sim_unresolved_indirect_target();
	}
x86_l_149b:
	/* 0x149b: jmp    rdx */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RDX);
		switch (X86_SIM_L_REG_TAG(X86_RDX)) {
		case X86_SIM_TAG_CODE:
			switch (__x86_target) {
			case 0x149dULL: goto x86_l_149d;
			case 0x149eULL: goto x86_l_149e;
			case 0x14daULL: goto x86_l_14da;
			case 0x1532ULL: goto x86_l_1532;
			case 0x157cULL: goto x86_l_157c;
			case 0x1651ULL: goto x86_l_1651;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_149d:
	/* 0x149d: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_723);
x86_l_149e:
	/* 0x149e: movzx  edx,BYTE PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_14a1:
	/* 0x14a1: cmp    DWORD PTR [rdi+0x10],edx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_14a4:
	/* 0x14a4: jne    14af <filter_8ty_selector_val+0x36> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x14a4, 0x14af, x86_l_14af);
x86_l_14a6:
	/* 0x14a6: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_14a8:
	/* 0x14a8: cmp    ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 3ULL);
x86_l_14ab:
	/* 0x14ab: sete   al */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_CC_E, 0);
x86_l_14ae:
	/* 0x14ae: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_723);
x86_l_14af:
	/* 0x14af: mov    esi,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14b2:
	/* 0x14b2: cmp    esi,0xd */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 13ULL);
x86_l_14b5:
	/* 0x14b5: jb     14d0 <filter_8ty_selector_val+0x57> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x14b5, 0x14d0, x86_l_14d0);
x86_l_14b7:
	/* 0x14b7: cmp    DWORD PTR [rdi+0x14],edx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_14ba:
	/* 0x14ba: je     14a6 <filter_8ty_selector_val+0x2d> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x14ba, 0x14a6, x86_l_14a6);
x86_l_14bc:
	/* 0x14bc: cmp    esi,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_14bf:
	/* 0x14bf: jb     14d0 <filter_8ty_selector_val+0x57> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x14bf, 0x14d0, x86_l_14d0);
x86_l_14c1:
	/* 0x14c1: cmp    DWORD PTR [rdi+0x18],edx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_14c4:
	/* 0x14c4: je     14a6 <filter_8ty_selector_val+0x2d> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x14c4, 0x14a6, x86_l_14a6);
x86_l_14c6:
	/* 0x14c6: cmp    esi,0x15 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 21ULL);
x86_l_14c9:
	/* 0x14c9: jb     14d0 <filter_8ty_selector_val+0x57> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x14c9, 0x14d0, x86_l_14d0);
x86_l_14cb:
	/* 0x14cb: cmp    DWORD PTR [rdi+0x1c],edx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_14ce:
	/* 0x14ce: je     14a6 <filter_8ty_selector_val+0x2d> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x14ce, 0x14a6, x86_l_14a6);
x86_l_14d0:
	/* 0x14d0: cmp    ecx,0x4 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_14d3:
	/* 0x14d3: je     149d <filter_8ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x14d3, 0x149d, x86_l_149d);
x86_l_14d5:
	/* 0x14d5: jmp    1651 <filter_8ty_selector_val+0x1d8> */
	X86_SIM_X86_SUB_JMP(0x14d5, 0x1651, x86_l_1651);
x86_l_14da:
	/* 0x14da: mov    ecx,DWORD PTR [rdi+0xc] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_14dd:
	/* 0x14dd: cmp    ecx,0xc */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 12ULL);
x86_l_14e0:
	/* 0x14e0: ja     15dd <filter_8ty_selector_val+0x164> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x14e0, 0x15dd, x86_l_15dd);
x86_l_14e6:
	/* 0x14e6: mov    edx,0x1402 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 5122ULL);
x86_l_14eb:
	/* 0x14eb: bt     edx,ecx */
	X86_SIM_RUN_OP(X86_OP_BT, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_14ee:
	/* 0x14ee: jae    15dd <filter_8ty_selector_val+0x164> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x14ee, 0x15dd, x86_l_15dd);
x86_l_14f4:
	/* 0x14f4: movsx  ecx,BYTE PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOVSX_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_14f7:
	/* 0x14f7: cmp    DWORD PTR [rdi+0x10],ecx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_14fa:
	/* 0x14fa: jl     149d <filter_8ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_L, 0x14fa, 0x149d, x86_l_149d);
x86_l_14fc:
	/* 0x14fc: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14ff:
	/* 0x14ff: cmp    edx,0xd */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 13ULL);
x86_l_1502:
	/* 0x1502: jb     1651 <filter_8ty_selector_val+0x1d8> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1502, 0x1651, x86_l_1651);
x86_l_1508:
	/* 0x1508: cmp    DWORD PTR [rdi+0x14],ecx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_150b:
	/* 0x150b: jl     149d <filter_8ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_L, 0x150b, 0x149d, x86_l_149d);
x86_l_150d:
	/* 0x150d: cmp    edx,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_1510:
	/* 0x1510: jb     1651 <filter_8ty_selector_val+0x1d8> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1510, 0x1651, x86_l_1651);
x86_l_1516:
	/* 0x1516: cmp    DWORD PTR [rdi+0x18],ecx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1519:
	/* 0x1519: jl     149d <filter_8ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_L, 0x1519, 0x149d, x86_l_149d);
x86_l_151b:
	/* 0x151b: cmp    edx,0x15 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 21ULL);
x86_l_151e:
	/* 0x151e: jb     1651 <filter_8ty_selector_val+0x1d8> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x151e, 0x1651, x86_l_1651);
x86_l_1524:
	/* 0x1524: cmp    DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1527:
	/* 0x1527: jl     149d <filter_8ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_L, 0x1527, 0x149d, x86_l_149d);
x86_l_152d:
	/* 0x152d: jmp    1651 <filter_8ty_selector_val+0x1d8> */
	X86_SIM_X86_SUB_JMP(0x152d, 0x1651, x86_l_1651);
x86_l_1532:
	/* 0x1532: movzx  ecx,BYTE PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1535:
	/* 0x1535: test   DWORD PTR [rdi+0x10],ecx */
	X86_SIM_RUN_OP(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1538:
	/* 0x1538: jne    149d <filter_8ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x1538, 0x149d, x86_l_149d);
x86_l_153e:
	/* 0x153e: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1541:
	/* 0x1541: cmp    edx,0xd */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 13ULL);
x86_l_1544:
	/* 0x1544: jb     1651 <filter_8ty_selector_val+0x1d8> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1544, 0x1651, x86_l_1651);
x86_l_154a:
	/* 0x154a: test   DWORD PTR [rdi+0x14],ecx */
	X86_SIM_RUN_OP(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_154d:
	/* 0x154d: jne    149d <filter_8ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x154d, 0x149d, x86_l_149d);
x86_l_1553:
	/* 0x1553: cmp    edx,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_1556:
	/* 0x1556: jb     1651 <filter_8ty_selector_val+0x1d8> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1556, 0x1651, x86_l_1651);
x86_l_155c:
	/* 0x155c: test   DWORD PTR [rdi+0x18],ecx */
	X86_SIM_RUN_OP(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_155f:
	/* 0x155f: jne    149d <filter_8ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x155f, 0x149d, x86_l_149d);
x86_l_1565:
	/* 0x1565: cmp    edx,0x15 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 21ULL);
x86_l_1568:
	/* 0x1568: jb     1651 <filter_8ty_selector_val+0x1d8> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1568, 0x1651, x86_l_1651);
x86_l_156e:
	/* 0x156e: test   DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_RUN_OP(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120259084288ULL);
x86_l_1571:
	/* 0x1571: jne    149d <filter_8ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x1571, 0x149d, x86_l_149d);
x86_l_1577:
	/* 0x1577: jmp    1651 <filter_8ty_selector_val+0x1d8> */
	X86_SIM_X86_SUB_JMP(0x1577, 0x1651, x86_l_1651);
x86_l_157c:
	/* 0x157c: mov    ecx,DWORD PTR [rdi+0xc] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_157f:
	/* 0x157f: cmp    ecx,0xc */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 12ULL);
x86_l_1582:
	/* 0x1582: ja     1618 <filter_8ty_selector_val+0x19f> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x1582, 0x1618, x86_l_1618);
x86_l_1588:
	/* 0x1588: mov    edx,0x1402 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 5122ULL);
x86_l_158d:
	/* 0x158d: bt     edx,ecx */
	X86_SIM_RUN_OP(X86_OP_BT, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_1590:
	/* 0x1590: jae    1618 <filter_8ty_selector_val+0x19f> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x1590, 0x1618, x86_l_1618);
x86_l_1596:
	/* 0x1596: movsx  ecx,BYTE PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOVSX_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1599:
	/* 0x1599: cmp    DWORD PTR [rdi+0x10],ecx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_159c:
	/* 0x159c: jg     149d <filter_8ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x159c, 0x149d, x86_l_149d);
x86_l_15a2:
	/* 0x15a2: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15a5:
	/* 0x15a5: cmp    edx,0xd */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 13ULL);
x86_l_15a8:
	/* 0x15a8: jb     1651 <filter_8ty_selector_val+0x1d8> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x15a8, 0x1651, x86_l_1651);
x86_l_15ae:
	/* 0x15ae: cmp    DWORD PTR [rdi+0x14],ecx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_15b1:
	/* 0x15b1: jg     149d <filter_8ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x15b1, 0x149d, x86_l_149d);
x86_l_15b7:
	/* 0x15b7: cmp    edx,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_15ba:
	/* 0x15ba: jb     1651 <filter_8ty_selector_val+0x1d8> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x15ba, 0x1651, x86_l_1651);
x86_l_15c0:
	/* 0x15c0: cmp    DWORD PTR [rdi+0x18],ecx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_15c3:
	/* 0x15c3: jg     149d <filter_8ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x15c3, 0x149d, x86_l_149d);
x86_l_15c9:
	/* 0x15c9: cmp    edx,0x15 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 21ULL);
x86_l_15cc:
	/* 0x15cc: jb     1651 <filter_8ty_selector_val+0x1d8> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x15cc, 0x1651, x86_l_1651);
x86_l_15d2:
	/* 0x15d2: cmp    DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_15d5:
	/* 0x15d5: jg     149d <filter_8ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x15d5, 0x149d, x86_l_149d);
x86_l_15db:
	/* 0x15db: jmp    1651 <filter_8ty_selector_val+0x1d8> */
	X86_SIM_X86_SUB_JMP(0x15db, 0x1651, x86_l_1651);
x86_l_15dd:
	/* 0x15dd: movzx  ecx,BYTE PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_15e0:
	/* 0x15e0: cmp    DWORD PTR [rdi+0x10],ecx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_15e3:
	/* 0x15e3: jb     149d <filter_8ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x15e3, 0x149d, x86_l_149d);
x86_l_15e9:
	/* 0x15e9: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15ec:
	/* 0x15ec: cmp    edx,0xd */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 13ULL);
x86_l_15ef:
	/* 0x15ef: jb     1651 <filter_8ty_selector_val+0x1d8> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x15ef, 0x1651, x86_l_1651);
x86_l_15f1:
	/* 0x15f1: cmp    DWORD PTR [rdi+0x14],ecx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_15f4:
	/* 0x15f4: jb     149d <filter_8ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x15f4, 0x149d, x86_l_149d);
x86_l_15fa:
	/* 0x15fa: cmp    edx,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_15fd:
	/* 0x15fd: jb     1651 <filter_8ty_selector_val+0x1d8> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x15fd, 0x1651, x86_l_1651);
x86_l_15ff:
	/* 0x15ff: cmp    DWORD PTR [rdi+0x18],ecx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1602:
	/* 0x1602: jb     149d <filter_8ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1602, 0x149d, x86_l_149d);
x86_l_1608:
	/* 0x1608: cmp    edx,0x15 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 21ULL);
x86_l_160b:
	/* 0x160b: jb     1651 <filter_8ty_selector_val+0x1d8> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x160b, 0x1651, x86_l_1651);
x86_l_160d:
	/* 0x160d: cmp    DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1610:
	/* 0x1610: jb     149d <filter_8ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1610, 0x149d, x86_l_149d);
x86_l_1616:
	/* 0x1616: jmp    1651 <filter_8ty_selector_val+0x1d8> */
	X86_SIM_X86_SUB_JMP(0x1616, 0x1651, x86_l_1651);
x86_l_1618:
	/* 0x1618: movzx  ecx,BYTE PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_161b:
	/* 0x161b: cmp    DWORD PTR [rdi+0x10],ecx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_161e:
	/* 0x161e: ja     149d <filter_8ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x161e, 0x149d, x86_l_149d);
x86_l_1624:
	/* 0x1624: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1627:
	/* 0x1627: cmp    edx,0xd */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 13ULL);
x86_l_162a:
	/* 0x162a: jb     1651 <filter_8ty_selector_val+0x1d8> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x162a, 0x1651, x86_l_1651);
x86_l_162c:
	/* 0x162c: cmp    DWORD PTR [rdi+0x14],ecx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_162f:
	/* 0x162f: ja     149d <filter_8ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x162f, 0x149d, x86_l_149d);
x86_l_1635:
	/* 0x1635: cmp    edx,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_1638:
	/* 0x1638: jb     1651 <filter_8ty_selector_val+0x1d8> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1638, 0x1651, x86_l_1651);
x86_l_163a:
	/* 0x163a: cmp    DWORD PTR [rdi+0x18],ecx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_163d:
	/* 0x163d: ja     149d <filter_8ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x163d, 0x149d, x86_l_149d);
x86_l_1643:
	/* 0x1643: cmp    edx,0x15 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 21ULL);
x86_l_1646:
	/* 0x1646: jb     1651 <filter_8ty_selector_val+0x1d8> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1646, 0x1651, x86_l_1651);
x86_l_1648:
	/* 0x1648: cmp    DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_164b:
	/* 0x164b: ja     149d <filter_8ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x164b, 0x149d, x86_l_149d);
x86_l_1651:
	/* 0x1651: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1653:
	/* 0x1653: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_723);

	/* native subroutine native_link_sub_1654 */
x86_l_1654:
	/* 0x1654: push   r14 */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_1656:
	/* 0x1656: push   rbx */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_1657:
	/* 0x1657: sub    rsp,0x18 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SUB, 24ULL);
x86_l_165b:
	/* 0x165b: mov    r14,rsi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R14, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_165e:
	/* 0x165e: mov    rbx,rdi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RBX, X86_RDI, X86_WIDTH_64, 0, 0);
x86_l_1661:
	/* 0x1661: movzx  eax,BYTE PTR [rdi+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_1665:
	/* 0x1665: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1669:
	/* 0x1669: mov    rdi,QWORD PTR [rip+0x1860] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)argfilter_maps));
x86_l_1670:
	/* 0x1670: lea    rsi,[rsp+0xc] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1675:
	/* 0x1675: call   2eda <__native_link_local_memset_zero_dynamic+0xc71> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_167a:
	/* 0x167a: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_167d:
	/* 0x167d: je     16b1 <filter_8ty_map+0x5d> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x167d, 0x16b1, x86_l_16b1);
x86_l_167f:
	/* 0x167f: movzx  ecx,BYTE PTR [r14] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1683:
	/* 0x1683: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1688:
	/* 0x1688: lea    rsi,[rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_168d:
	/* 0x168d: mov    rdi,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_1690:
	/* 0x1690: call   2ef5 <__native_link_local_memset_zero_dynamic+0xc8c> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_1695:
	/* 0x1695: mov    edx,DWORD PTR [rbx+0x4] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1698:
	/* 0x1698: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_169a:
	/* 0x169a: cmp    edx,0x1d */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 29ULL);
x86_l_169d:
	/* 0x169d: ja     16cb <filter_8ty_map+0x77> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x169d, 0x16cb, x86_l_16cb);
x86_l_169f:
	/* 0x169f: mov    esi,0x30038400 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 805536768ULL);
x86_l_16a4:
	/* 0x16a4: bt     esi,edx */
	X86_SIM_RUN_OP(X86_OP_BT, X86_RSI, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_16a7:
	/* 0x16a7: jae    16bb <filter_8ty_map+0x67> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x16a7, 0x16bb, x86_l_16bb);
x86_l_16a9:
	/* 0x16a9: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_16ac:
	/* 0x16ac: setne  cl */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_CC_NE, 0);
x86_l_16af:
	/* 0x16af: jmp    16cb <filter_8ty_map+0x77> */
	X86_SIM_X86_SUB_JMP(0x16af, 0x16cb, x86_l_16cb);
x86_l_16b1:
	/* 0x16b1: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_16b3:
	/* 0x16b3: add    rsp,0x18 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_16b7:
	/* 0x16b7: pop    rbx */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_16b8:
	/* 0x16b8: pop    r14 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R14, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_16ba:
	/* 0x16ba: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_723);
x86_l_16bb:
	/* 0x16bb: mov    esi,0xc0800 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 788480ULL);
x86_l_16c0:
	/* 0x16c0: bt     esi,edx */
	X86_SIM_RUN_OP(X86_OP_BT, X86_RSI, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_16c3:
	/* 0x16c3: jae    16cb <filter_8ty_map+0x77> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x16c3, 0x16cb, x86_l_16cb);
x86_l_16c5:
	/* 0x16c5: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_16c8:
	/* 0x16c8: sete   cl */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_CC_E, 0);
x86_l_16cb:
	/* 0x16cb: movzx  eax,cl */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8, 0);
x86_l_16ce:
	/* 0x16ce: add    rsp,0x18 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_16d2:
	/* 0x16d2: pop    rbx */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_16d3:
	/* 0x16d3: pop    r14 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R14, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_16d5:
	/* 0x16d5: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_723);

	/* native subroutine native_link_sub_16d6 */
x86_l_16d6:
	/* 0x16d6: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_16d9:
	/* 0x16d9: mov    eax,DWORD PTR [rdi+0xc] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_16dc:
	/* 0x16dc: cmp    eax,0xc */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 12ULL);
x86_l_16df:
	/* 0x16df: ja     17c6 <filter_8ty_range+0xf0> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x16df, 0x17c6, x86_l_17c6);
x86_l_16e5:
	/* 0x16e5: mov    edx,0x1402 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 5122ULL);
x86_l_16ea:
	/* 0x16ea: bt     edx,eax */
	X86_SIM_RUN_OP(X86_OP_BT, X86_RDX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_16ed:
	/* 0x16ed: jae    17c6 <filter_8ty_range+0xf0> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x16ed, 0x17c6, x86_l_17c6);
x86_l_16f3:
	/* 0x16f3: movsx  esi,BYTE PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOVSX_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_16f6:
	/* 0x16f6: cmp    ecx,0x1f */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 31ULL);
x86_l_16f9:
	/* 0x16f9: jne    1761 <filter_8ty_range+0x8b> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x16f9, 0x1761, x86_l_1761);
x86_l_16fb:
	/* 0x16fb: mov    eax,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_1700:
	/* 0x1700: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1703:
	/* 0x1703: jg     170e <filter_8ty_range+0x38> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x1703, 0x170e, x86_l_170e);
x86_l_1705:
	/* 0x1705: cmp    DWORD PTR [rdi+0x14],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1708:
	/* 0x1708: jge    17dd <filter_8ty_range+0x107> */
	X86_SIM_X86_SUB_JCC(X86_CC_GE, 0x1708, 0x17dd, x86_l_17dd);
x86_l_170e:
	/* 0x170e: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1711:
	/* 0x1711: cmp    edx,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_1714:
	/* 0x1714: jb     187d <filter_8ty_range+0x1a7> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1714, 0x187d, x86_l_187d);
x86_l_171a:
	/* 0x171a: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_171d:
	/* 0x171d: jg     1728 <filter_8ty_range+0x52> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x171d, 0x1728, x86_l_1728);
x86_l_171f:
	/* 0x171f: cmp    DWORD PTR [rdi+0x1c],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1722:
	/* 0x1722: jge    17dd <filter_8ty_range+0x107> */
	X86_SIM_X86_SUB_JCC(X86_CC_GE, 0x1722, 0x17dd, x86_l_17dd);
x86_l_1728:
	/* 0x1728: cmp    edx,0x19 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 25ULL);
x86_l_172b:
	/* 0x172b: jb     187d <filter_8ty_range+0x1a7> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x172b, 0x187d, x86_l_187d);
x86_l_1731:
	/* 0x1731: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1734:
	/* 0x1734: jg     173f <filter_8ty_range+0x69> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x1734, 0x173f, x86_l_173f);
x86_l_1736:
	/* 0x1736: cmp    DWORD PTR [rdi+0x24],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1739:
	/* 0x1739: jge    17dd <filter_8ty_range+0x107> */
	X86_SIM_X86_SUB_JCC(X86_CC_GE, 0x1739, 0x17dd, x86_l_17dd);
x86_l_173f:
	/* 0x173f: cmp    edx,0x21 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 33ULL);
x86_l_1742:
	/* 0x1742: jb     187d <filter_8ty_range+0x1a7> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1742, 0x187d, x86_l_187d);
x86_l_1748:
	/* 0x1748: xor    edx,edx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_174a:
	/* 0x174a: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_174d:
	/* 0x174d: jg     187f <filter_8ty_range+0x1a9> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x174d, 0x187f, x86_l_187f);
x86_l_1753:
	/* 0x1753: cmp    DWORD PTR [rdi+0x2c],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1756:
	/* 0x1756: jge    17dd <filter_8ty_range+0x107> */
	X86_SIM_X86_SUB_JCC(X86_CC_GE, 0x1756, 0x17dd, x86_l_17dd);
x86_l_175c:
	/* 0x175c: jmp    187f <filter_8ty_range+0x1a9> */
	X86_SIM_X86_SUB_JMP(0x175c, 0x187f, x86_l_187f);
x86_l_1761:
	/* 0x1761: mov    eax,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1764:
	/* 0x1764: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1767:
	/* 0x1767: setle  r8b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R8, X86_REG_NONE, X86_WIDTH_8, X86_CC_LE, 0);
x86_l_176b:
	/* 0x176b: cmp    DWORD PTR [rdi+0x14],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_176e:
	/* 0x176e: setge  dl */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_CC_GE, 0);
x86_l_1771:
	/* 0x1771: and    dl,r8b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_R8, X86_WIDTH_8, X86_ALU_AND, 0);
x86_l_1774:
	/* 0x1774: cmp    eax,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_1777:
	/* 0x1777: jb     187f <filter_8ty_range+0x1a9> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1777, 0x187f, x86_l_187f);
x86_l_177d:
	/* 0x177d: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1780:
	/* 0x1780: setle  r8b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R8, X86_REG_NONE, X86_WIDTH_8, X86_CC_LE, 0);
x86_l_1784:
	/* 0x1784: cmp    DWORD PTR [rdi+0x1c],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1787:
	/* 0x1787: setge  r9b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R9, X86_REG_NONE, X86_WIDTH_8, X86_CC_GE, 0);
x86_l_178b:
	/* 0x178b: and    r9b,r8b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND, 0);
x86_l_178e:
	/* 0x178e: or     dl,r9b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR, 0);
x86_l_1791:
	/* 0x1791: cmp    eax,0x19 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 25ULL);
x86_l_1794:
	/* 0x1794: jb     187f <filter_8ty_range+0x1a9> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1794, 0x187f, x86_l_187f);
x86_l_179a:
	/* 0x179a: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_179d:
	/* 0x179d: setle  r8b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R8, X86_REG_NONE, X86_WIDTH_8, X86_CC_LE, 0);
x86_l_17a1:
	/* 0x17a1: cmp    DWORD PTR [rdi+0x24],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_17a4:
	/* 0x17a4: setge  r9b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R9, X86_REG_NONE, X86_WIDTH_8, X86_CC_GE, 0);
x86_l_17a8:
	/* 0x17a8: and    r9b,r8b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND, 0);
x86_l_17ab:
	/* 0x17ab: or     dl,r9b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR, 0);
x86_l_17ae:
	/* 0x17ae: cmp    eax,0x21 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 33ULL);
x86_l_17b1:
	/* 0x17b1: jb     187f <filter_8ty_range+0x1a9> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x17b1, 0x187f, x86_l_187f);
x86_l_17b7:
	/* 0x17b7: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_17ba:
	/* 0x17ba: setle  al */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_CC_LE, 0);
x86_l_17bd:
	/* 0x17bd: cmp    DWORD PTR [rdi+0x2c],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_17c0:
	/* 0x17c0: setge  sil */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_CC_GE, 0);
x86_l_17c4:
	/* 0x17c4: jmp    1839 <filter_8ty_range+0x163> */
	X86_SIM_X86_SUB_JMP(0x17c4, 0x1839, x86_l_1839);
x86_l_17c6:
	/* 0x17c6: movzx  esi,BYTE PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_17c9:
	/* 0x17c9: cmp    ecx,0x1f */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 31ULL);
x86_l_17cc:
	/* 0x17cc: jne    17de <filter_8ty_range+0x108> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x17cc, 0x17de, x86_l_17de);
x86_l_17ce:
	/* 0x17ce: mov    eax,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_17d3:
	/* 0x17d3: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17d6:
	/* 0x17d6: ja     1841 <filter_8ty_range+0x16b> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x17d6, 0x1841, x86_l_1841);
x86_l_17d8:
	/* 0x17d8: cmp    DWORD PTR [rdi+0x14],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_17db:
	/* 0x17db: jb     1841 <filter_8ty_range+0x16b> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x17db, 0x1841, x86_l_1841);
x86_l_17dd:
	/* 0x17dd: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_723);
x86_l_17de:
	/* 0x17de: mov    eax,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17e1:
	/* 0x17e1: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17e4:
	/* 0x17e4: setbe  r8b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R8, X86_REG_NONE, X86_WIDTH_8, X86_CC_BE, 0);
x86_l_17e8:
	/* 0x17e8: cmp    DWORD PTR [rdi+0x14],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_17eb:
	/* 0x17eb: setae  dl */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_CC_AE, 0);
x86_l_17ee:
	/* 0x17ee: and    dl,r8b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_R8, X86_WIDTH_8, X86_ALU_AND, 0);
x86_l_17f1:
	/* 0x17f1: cmp    eax,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_17f4:
	/* 0x17f4: jb     187f <filter_8ty_range+0x1a9> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x17f4, 0x187f, x86_l_187f);
x86_l_17fa:
	/* 0x17fa: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_17fd:
	/* 0x17fd: setbe  r8b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R8, X86_REG_NONE, X86_WIDTH_8, X86_CC_BE, 0);
x86_l_1801:
	/* 0x1801: cmp    DWORD PTR [rdi+0x1c],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1804:
	/* 0x1804: setae  r9b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R9, X86_REG_NONE, X86_WIDTH_8, X86_CC_AE, 0);
x86_l_1808:
	/* 0x1808: and    r9b,r8b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND, 0);
x86_l_180b:
	/* 0x180b: or     dl,r9b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR, 0);
x86_l_180e:
	/* 0x180e: cmp    eax,0x19 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 25ULL);
x86_l_1811:
	/* 0x1811: jb     187f <filter_8ty_range+0x1a9> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1811, 0x187f, x86_l_187f);
x86_l_1813:
	/* 0x1813: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1816:
	/* 0x1816: setbe  r8b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R8, X86_REG_NONE, X86_WIDTH_8, X86_CC_BE, 0);
x86_l_181a:
	/* 0x181a: cmp    DWORD PTR [rdi+0x24],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_181d:
	/* 0x181d: setae  r9b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R9, X86_REG_NONE, X86_WIDTH_8, X86_CC_AE, 0);
x86_l_1821:
	/* 0x1821: and    r9b,r8b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND, 0);
x86_l_1824:
	/* 0x1824: or     dl,r9b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR, 0);
x86_l_1827:
	/* 0x1827: cmp    eax,0x21 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 33ULL);
x86_l_182a:
	/* 0x182a: jb     187f <filter_8ty_range+0x1a9> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x182a, 0x187f, x86_l_187f);
x86_l_182c:
	/* 0x182c: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_182f:
	/* 0x182f: setbe  al */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_CC_BE, 0);
x86_l_1832:
	/* 0x1832: cmp    DWORD PTR [rdi+0x2c],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1835:
	/* 0x1835: setae  sil */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_CC_AE, 0);
x86_l_1839:
	/* 0x1839: and    sil,al */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_ALU_AND, 0);
x86_l_183c:
	/* 0x183c: or     dl,sil */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RSI, X86_WIDTH_8, X86_ALU_OR, 0);
x86_l_183f:
	/* 0x183f: jmp    187f <filter_8ty_range+0x1a9> */
	X86_SIM_X86_SUB_JMP(0x183f, 0x187f, x86_l_187f);
x86_l_1841:
	/* 0x1841: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1844:
	/* 0x1844: cmp    edx,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_1847:
	/* 0x1847: jb     187d <filter_8ty_range+0x1a7> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1847, 0x187d, x86_l_187d);
x86_l_1849:
	/* 0x1849: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_184c:
	/* 0x184c: ja     1853 <filter_8ty_range+0x17d> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x184c, 0x1853, x86_l_1853);
x86_l_184e:
	/* 0x184e: cmp    DWORD PTR [rdi+0x1c],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1851:
	/* 0x1851: jae    17dd <filter_8ty_range+0x107> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x1851, 0x17dd, x86_l_17dd);
x86_l_1853:
	/* 0x1853: cmp    edx,0x19 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 25ULL);
x86_l_1856:
	/* 0x1856: jb     187d <filter_8ty_range+0x1a7> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1856, 0x187d, x86_l_187d);
x86_l_1858:
	/* 0x1858: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_185b:
	/* 0x185b: ja     1866 <filter_8ty_range+0x190> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x185b, 0x1866, x86_l_1866);
x86_l_185d:
	/* 0x185d: cmp    DWORD PTR [rdi+0x24],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1860:
	/* 0x1860: jae    17dd <filter_8ty_range+0x107> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x1860, 0x17dd, x86_l_17dd);
x86_l_1866:
	/* 0x1866: cmp    edx,0x21 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 33ULL);
x86_l_1869:
	/* 0x1869: jb     187d <filter_8ty_range+0x1a7> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1869, 0x187d, x86_l_187d);
x86_l_186b:
	/* 0x186b: xor    edx,edx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_186d:
	/* 0x186d: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1870:
	/* 0x1870: ja     187f <filter_8ty_range+0x1a9> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x1870, 0x187f, x86_l_187f);
x86_l_1872:
	/* 0x1872: cmp    DWORD PTR [rdi+0x2c],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1875:
	/* 0x1875: jae    17dd <filter_8ty_range+0x107> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x1875, 0x17dd, x86_l_17dd);
x86_l_187b:
	/* 0x187b: jmp    187f <filter_8ty_range+0x1a9> */
	X86_SIM_X86_SUB_JMP(0x187b, 0x187f, x86_l_187f);
x86_l_187d:
	/* 0x187d: xor    edx,edx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_187f:
	/* 0x187f: cmp    ecx,0x20 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 32ULL);
x86_l_1882:
	/* 0x1882: sete   al */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_CC_E, 0);
x86_l_1885:
	/* 0x1885: xor    dl,0x1 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_ALU_XOR, 1ULL);
x86_l_1888:
	/* 0x1888: and    dl,al */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RAX, X86_WIDTH_8, X86_ALU_AND, 0);
x86_l_188a:
	/* 0x188a: movzx  eax,dl */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8, 0);
x86_l_188d:
	/* 0x188d: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_723);

	/* native subroutine native_link_sub_188e */
x86_l_188e:
	/* 0x188e: push   rbp */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_188f:
	/* 0x188f: push   r15 */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_1891:
	/* 0x1891: push   r14 */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_1893:
	/* 0x1893: push   r13 */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_1895:
	/* 0x1895: push   r12 */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_1897:
	/* 0x1897: push   rbx */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_1898:
	/* 0x1898: push   rax */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_1899:
	/* 0x1899: mov    r15,rsi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R15, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_189c:
	/* 0x189c: mov    r14,rdi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R14, X86_RDI, X86_WIDTH_64, 0, 0);
x86_l_189f:
	/* 0x189f: mov    ebp,edx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RBP, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_18a1:
	/* 0x18a1: test   ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_18a3:
	/* 0x18a3: je     1969 <filter_char_substring+0xdb> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x18a3, 0x1969, x86_l_1969);
x86_l_18a9:
	/* 0x18a9: test   edx,edx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_18ab:
	/* 0x18ab: je     1a00 <filter_char_substring+0x172> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x18ab, 0x1a00, x86_l_1a00);
x86_l_18b1:
	/* 0x18b1: lea    r13,[rsp+0x4] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_18b6:
	/* 0x18b6: xor    ebx,ebx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_18b8:
	/* 0x18b8: xor    r12d,r12d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_18bb:
	/* 0x18bb: mov    eax,DWORD PTR [r14+rbx*4+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 16ULL);
x86_l_18c0:
	/* 0x18c0: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_18c4:
	/* 0x18c4: mov    rdi,QWORD PTR [rip+0x2673] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)substring_map));
x86_l_18cb:
	/* 0x18cb: mov    rsi,r13 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_18ce:
	/* 0x18ce: call   3f46 <__native_link_local_memset_zero_dynamic+0x1cdd> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_18d3:
	/* 0x18d3: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_18d6:
	/* 0x18d6: je     1a80 <filter_char_substring+0x1f2> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x18d6, 0x1a80, x86_l_1a80);
x86_l_18dc:
	/* 0x18dc: mov    rdx,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_18df:
	/* 0x18df: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_18e1:
	/* 0x18e1: jmp    18ee <filter_char_substring+0x60> */
	X86_SIM_X86_SUB_JMP(0x18e1, 0x18ee, x86_l_18ee);
x86_l_18e3:
	/* 0x18e3: inc    rcx */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_18e6:
	/* 0x18e6: inc    rdx */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_18e9:
	/* 0x18e9: cmp    rcx,rbp */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_18ec:
	/* 0x18ec: je     1944 <filter_char_substring+0xb6> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x18ec, 0x1944, x86_l_1944);
x86_l_18ee:
	/* 0x18ee: xor    esi,esi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_18f0:
	/* 0x18f0: lea    rdi,[rcx+rsi*1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_18f4:
	/* 0x18f4: cmp    rdi,rbp */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RDI, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_18f7:
	/* 0x18f7: jae    18e3 <filter_char_substring+0x55> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x18f7, 0x18e3, x86_l_18e3);
x86_l_18f9:
	/* 0x18f9: movsx  edi,BYTE PTR [rax+rsi*1] */
	X86_SIM_RUN_OP(X86_OP_MOVSX_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 0ULL);
x86_l_18fd:
	/* 0x18fd: test   edi,edi */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_32, 0, 0);
x86_l_18ff:
	/* 0x18ff: je     193c <filter_char_substring+0xae> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x18ff, 0x193c, x86_l_193c);
x86_l_1901:
	/* 0x1901: movsx  r9d,BYTE PTR [rdx+rsi*1] */
	X86_SIM_RUN_OP(X86_OP_MOVSX_LOAD, X86_R9, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 0ULL);
x86_l_1906:
	/* 0x1906: lea    r10d,[r9-0x41] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R10, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551551ULL);
x86_l_190a:
	/* 0x190a: mov    r8d,r9d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R8, X86_R9, X86_WIDTH_32, 0, 0);
x86_l_190d:
	/* 0x190d: or     r8d,0x20 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_ALU_OR, 32ULL);
x86_l_1911:
	/* 0x1911: cmp    r10d,0x1a */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_32, 0, 26ULL);
x86_l_1915:
	/* 0x1915: cmovae r8d,r9d */
	X86_SIM_RUN_OP(X86_OP_CMOV, X86_R8, X86_R9, X86_WIDTH_32, X86_CC_AE, 0);
x86_l_1919:
	/* 0x1919: lea    r10d,[rdi-0x41] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R10, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551551ULL);
x86_l_191d:
	/* 0x191d: mov    r9d,edi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R9, X86_RDI, X86_WIDTH_32, 0, 0);
x86_l_1920:
	/* 0x1920: or     r9d,0x20 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_32, X86_ALU_OR, 32ULL);
x86_l_1924:
	/* 0x1924: cmp    r10d,0x1a */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_32, 0, 26ULL);
x86_l_1928:
	/* 0x1928: cmovae r9d,edi */
	X86_SIM_RUN_OP(X86_OP_CMOV, X86_R9, X86_RDI, X86_WIDTH_32, X86_CC_AE, 0);
x86_l_192c:
	/* 0x192c: cmp    rsi,0x62 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, 0, 98ULL);
x86_l_1930:
	/* 0x1930: ja     18e3 <filter_char_substring+0x55> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x1930, 0x18e3, x86_l_18e3);
x86_l_1932:
	/* 0x1932: inc    rsi */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1935:
	/* 0x1935: cmp    r8d,r9d */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_R8, X86_R9, X86_WIDTH_32, 0, 0);
x86_l_1938:
	/* 0x1938: je     18f0 <filter_char_substring+0x62> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1938, 0x18f0, x86_l_18f0);
x86_l_193a:
	/* 0x193a: jmp    18e3 <filter_char_substring+0x55> */
	X86_SIM_X86_SUB_JMP(0x193a, 0x18e3, x86_l_18e3);
x86_l_193c:
	/* 0x193c: test   ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_193e:
	/* 0x193e: jns    1a91 <filter_char_substring+0x203> */
	X86_SIM_X86_SUB_JCC(X86_CC_NS, 0x193e, 0x1a91, x86_l_1a91);
x86_l_1944:
	/* 0x1944: lea    eax,[r12+0xc] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1949:
	/* 0x1949: cmp    eax,DWORD PTR [r14+0x8] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_194d:
	/* 0x194d: jae    1a80 <filter_char_substring+0x1f2> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x194d, 0x1a80, x86_l_1a80);
x86_l_1953:
	/* 0x1953: add    r12d,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1957:
	/* 0x1957: inc    rbx */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_195a:
	/* 0x195a: cmp    rbx,0x64 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 100ULL);
x86_l_195e:
	/* 0x195e: jne    18bb <filter_char_substring+0x2d> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x195e, 0x18bb, x86_l_18bb);
x86_l_1964:
	/* 0x1964: jmp    1a80 <filter_char_substring+0x1f2> */
	X86_SIM_X86_SUB_JMP(0x1964, 0x1a80, x86_l_1a80);
x86_l_1969:
	/* 0x1969: test   edx,edx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_196b:
	/* 0x196b: je     1a41 <filter_char_substring+0x1b3> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x196b, 0x1a41, x86_l_1a41);
x86_l_1971:
	/* 0x1971: lea    r13,[rsp+0x4] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1976:
	/* 0x1976: xor    ebx,ebx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1978:
	/* 0x1978: xor    r12d,r12d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_197b:
	/* 0x197b: mov    eax,DWORD PTR [r14+rbx*4+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 16ULL);
x86_l_1980:
	/* 0x1980: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1984:
	/* 0x1984: mov    rdi,QWORD PTR [rip+0x2683] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)substring_map));
x86_l_198b:
	/* 0x198b: mov    rsi,r13 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_198e:
	/* 0x198e: call   4016 <__native_link_local_memset_zero_dynamic+0x1dad> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_1993:
	/* 0x1993: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_1996:
	/* 0x1996: je     1a80 <filter_char_substring+0x1f2> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1996, 0x1a80, x86_l_1a80);
x86_l_199c:
	/* 0x199c: mov    rdx,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_199f:
	/* 0x199f: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_19a1:
	/* 0x19a1: jmp    19ae <filter_char_substring+0x120> */
	X86_SIM_X86_SUB_JMP(0x19a1, 0x19ae, x86_l_19ae);
x86_l_19a3:
	/* 0x19a3: inc    rcx */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_19a6:
	/* 0x19a6: inc    rdx */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_19a9:
	/* 0x19a9: cmp    rcx,rbp */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_19ac:
	/* 0x19ac: je     19df <filter_char_substring+0x151> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x19ac, 0x19df, x86_l_19df);
x86_l_19ae:
	/* 0x19ae: xor    esi,esi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_19b0:
	/* 0x19b0: lea    rdi,[rcx+rsi*1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_19b4:
	/* 0x19b4: cmp    rdi,rbp */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RDI, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_19b7:
	/* 0x19b7: jae    19a3 <filter_char_substring+0x115> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x19b7, 0x19a3, x86_l_19a3);
x86_l_19b9:
	/* 0x19b9: movzx  edi,BYTE PTR [rax+rsi*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 0ULL);
x86_l_19bd:
	/* 0x19bd: test   dil,dil */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_8, 0, 0);
x86_l_19c0:
	/* 0x19c0: je     19d7 <filter_char_substring+0x149> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x19c0, 0x19d7, x86_l_19d7);
x86_l_19c2:
	/* 0x19c2: cmp    rsi,0x62 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, 0, 98ULL);
x86_l_19c6:
	/* 0x19c6: ja     19a3 <filter_char_substring+0x115> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x19c6, 0x19a3, x86_l_19a3);
x86_l_19c8:
	/* 0x19c8: lea    r8,[rsi+0x1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_19cc:
	/* 0x19cc: cmp    BYTE PTR [rdx+rsi*1],dil */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDX, X86_RDI, X86_WIDTH_8, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_19d0:
	/* 0x19d0: mov    rsi,r8 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_R8, X86_WIDTH_64, 0, 0);
x86_l_19d3:
	/* 0x19d3: je     19b0 <filter_char_substring+0x122> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x19d3, 0x19b0, x86_l_19b0);
x86_l_19d5:
	/* 0x19d5: jmp    19a3 <filter_char_substring+0x115> */
	X86_SIM_X86_SUB_JMP(0x19d5, 0x19a3, x86_l_19a3);
x86_l_19d7:
	/* 0x19d7: test   ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_19d9:
	/* 0x19d9: jns    1a91 <filter_char_substring+0x203> */
	X86_SIM_X86_SUB_JCC(X86_CC_NS, 0x19d9, 0x1a91, x86_l_1a91);
x86_l_19df:
	/* 0x19df: lea    eax,[r12+0xc] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_19e4:
	/* 0x19e4: cmp    eax,DWORD PTR [r14+0x8] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_19e8:
	/* 0x19e8: jae    1a80 <filter_char_substring+0x1f2> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x19e8, 0x1a80, x86_l_1a80);
x86_l_19ee:
	/* 0x19ee: add    r12d,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_19f2:
	/* 0x19f2: inc    rbx */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_19f5:
	/* 0x19f5: cmp    rbx,0x64 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 100ULL);
x86_l_19f9:
	/* 0x19f9: jne    197b <filter_char_substring+0xed> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x19f9, 0x197b, x86_l_197b);
x86_l_19fb:
	/* 0x19fb: jmp    1a80 <filter_char_substring+0x1f2> */
	X86_SIM_X86_SUB_JMP(0x19fb, 0x1a80, x86_l_1a80);
x86_l_1a00:
	/* 0x1a00: mov    ebx,0x10 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 16ULL);
x86_l_1a05:
	/* 0x1a05: mov    r15,QWORD PTR [rip+0x269b] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_R15, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)substring_map));
x86_l_1a0c:
	/* 0x1a0c: lea    r12,[rsp+0x4] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1a11:
	/* 0x1a11: mov    eax,DWORD PTR [r14+rbx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_1a15:
	/* 0x1a15: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1a19:
	/* 0x1a19: mov    rdi,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_1a1c:
	/* 0x1a1c: mov    rsi,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_1a1f:
	/* 0x1a1f: call   40c1 <__native_link_local_memset_zero_dynamic+0x1e58> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_1a24:
	/* 0x1a24: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_1a27:
	/* 0x1a27: je     1a80 <filter_char_substring+0x1f2> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1a27, 0x1a80, x86_l_1a80);
x86_l_1a29:
	/* 0x1a29: add    rbx,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1a2d:
	/* 0x1a2d: lea    eax,[rbx-0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551608ULL);
x86_l_1a30:
	/* 0x1a30: cmp    eax,DWORD PTR [r14+0x8] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_1a34:
	/* 0x1a34: jae    1a80 <filter_char_substring+0x1f2> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x1a34, 0x1a80, x86_l_1a80);
x86_l_1a36:
	/* 0x1a36: cmp    rbx,0x1a0 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 416ULL);
x86_l_1a3d:
	/* 0x1a3d: jne    1a11 <filter_char_substring+0x183> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x1a3d, 0x1a11, x86_l_1a11);
x86_l_1a3f:
	/* 0x1a3f: jmp    1a80 <filter_char_substring+0x1f2> */
	X86_SIM_X86_SUB_JMP(0x1a3f, 0x1a80, x86_l_1a80);
x86_l_1a41:
	/* 0x1a41: mov    ebx,0x10 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 16ULL);
x86_l_1a46:
	/* 0x1a46: mov    r15,QWORD PTR [rip+0x269d] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_R15, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)substring_map));
x86_l_1a4d:
	/* 0x1a4d: lea    r12,[rsp+0x4] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1a52:
	/* 0x1a52: mov    eax,DWORD PTR [r14+rbx*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_1a56:
	/* 0x1a56: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1a5a:
	/* 0x1a5a: mov    rdi,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_1a5d:
	/* 0x1a5d: mov    rsi,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_1a60:
	/* 0x1a60: call   4111 <__native_link_local_memset_zero_dynamic+0x1ea8> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_1a65:
	/* 0x1a65: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_1a68:
	/* 0x1a68: je     1a80 <filter_char_substring+0x1f2> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1a68, 0x1a80, x86_l_1a80);
x86_l_1a6a:
	/* 0x1a6a: add    rbx,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1a6e:
	/* 0x1a6e: lea    eax,[rbx-0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551608ULL);
x86_l_1a71:
	/* 0x1a71: cmp    eax,DWORD PTR [r14+0x8] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_1a75:
	/* 0x1a75: jae    1a80 <filter_char_substring+0x1f2> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x1a75, 0x1a80, x86_l_1a80);
x86_l_1a77:
	/* 0x1a77: cmp    rbx,0x1a0 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 416ULL);
x86_l_1a7e:
	/* 0x1a7e: jne    1a52 <filter_char_substring+0x1c4> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x1a7e, 0x1a52, x86_l_1a52);
x86_l_1a80:
	/* 0x1a80: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1a82:
	/* 0x1a82: add    rsp,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1a86:
	/* 0x1a86: pop    rbx */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1a87:
	/* 0x1a87: pop    r12 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R12, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1a89:
	/* 0x1a89: pop    r13 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R13, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1a8b:
	/* 0x1a8b: pop    r14 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R14, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1a8d:
	/* 0x1a8d: pop    r15 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R15, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1a8f:
	/* 0x1a8f: pop    rbp */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBP, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1a90:
	/* 0x1a90: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_1a90);
x86_l_1a91:
	/* 0x1a91: mov    eax,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_1a96:
	/* 0x1a96: jmp    1a82 <filter_char_substring+0x1f4> */
	X86_SIM_X86_SUB_JMP(0x1a96, 0x1a82, x86_l_1a82);

	/* native subroutine native_link_sub_1a98 */
x86_l_1a98:
	/* 0x1a98: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1a9b:
	/* 0x1a9b: lea    edx,[rcx-0x1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_1a9e:
	/* 0x1a9e: cmp    edx,0x24 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 36ULL);
x86_l_1aa1:
	/* 0x1aa1: ja     1c8c <filter_64ty_selector_val+0x1f4> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x1aa1, 0x1c8c, x86_l_1c8c);
x86_l_1aa7:
	/* 0x1aa7: mov    eax,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_1aac:
	/* Capture image-bound code identity before scheduled instructions. */
	switch (X86_SIM_L_READ_REG(X86_RDX) << 2) {
	case 0ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1afdULL); break;
	case 4ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1babULL); break;
	case 8ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1abdULL); break;
	case 12ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1abdULL); break;
	case 16ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1c8cULL); break;
	case 20ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1abcULL); break;
	case 24ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1c8cULL); break;
	case 28ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1c8cULL); break;
	case 32ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1c8cULL); break;
	case 36ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1c8cULL); break;
	case 40ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1c8cULL); break;
	case 44ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1b5dULL); break;
	case 48ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1c8cULL); break;
	case 52ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1c8cULL); break;
	case 56ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1c8cULL); break;
	case 60ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1c8cULL); break;
	case 64ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1c8cULL); break;
	case 68ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1c8cULL); break;
	case 72ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1c8cULL); break;
	case 76ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1c8cULL); break;
	case 80ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1c8cULL); break;
	case 84ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1c8cULL); break;
	case 88ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1c8cULL); break;
	case 92ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1c8cULL); break;
	case 96ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1c8cULL); break;
	case 100ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1abcULL); break;
	case 104ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1abcULL); break;
	case 108ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1c8cULL); break;
	case 112ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1c8cULL); break;
	case 116ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1c8cULL); break;
	case 120ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1c8cULL); break;
	case 124ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1c8cULL); break;
	case 128ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1c8cULL); break;
	case 132ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1c8cULL); break;
	case 136ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1c8cULL); break;
	case 140ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1c8cULL); break;
	case 144ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1abcULL); break;
	default: __x86_sim_unresolved_indirect_target();
	}
x86_l_1aba:
	/* 0x1aba: jmp    rdx */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RDX);
		switch (X86_SIM_L_REG_TAG(X86_RDX)) {
		case X86_SIM_TAG_CODE:
			switch (__x86_target) {
			case 0x1abcULL: goto x86_l_1abc;
			case 0x1abdULL: goto x86_l_1abd;
			case 0x1afdULL: goto x86_l_1afd;
			case 0x1b5dULL: goto x86_l_1b5d;
			case 0x1babULL: goto x86_l_1bab;
			case 0x1c8cULL: goto x86_l_1c8c;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_1abc:
	/* 0x1abc: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_659);
x86_l_1abd:
	/* 0x1abd: mov    rdx,QWORD PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ac0:
	/* 0x1ac0: cmp    rdx,QWORD PTR [rdi+0x10] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_1ac4:
	/* 0x1ac4: jne    1acf <filter_64ty_selector_val+0x37> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x1ac4, 0x1acf, x86_l_1acf);
x86_l_1ac6:
	/* 0x1ac6: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1ac8:
	/* 0x1ac8: cmp    ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 3ULL);
x86_l_1acb:
	/* 0x1acb: sete   al */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_CC_E, 0);
x86_l_1ace:
	/* 0x1ace: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_659);
x86_l_1acf:
	/* 0x1acf: mov    esi,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ad2:
	/* 0x1ad2: cmp    esi,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_1ad5:
	/* 0x1ad5: jb     1af3 <filter_64ty_selector_val+0x5b> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1ad5, 0x1af3, x86_l_1af3);
x86_l_1ad7:
	/* 0x1ad7: cmp    rdx,QWORD PTR [rdi+0x18] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_1adb:
	/* 0x1adb: je     1ac6 <filter_64ty_selector_val+0x2e> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1adb, 0x1ac6, x86_l_1ac6);
x86_l_1add:
	/* 0x1add: cmp    esi,0x19 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 25ULL);
x86_l_1ae0:
	/* 0x1ae0: jb     1af3 <filter_64ty_selector_val+0x5b> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1ae0, 0x1af3, x86_l_1af3);
x86_l_1ae2:
	/* 0x1ae2: cmp    rdx,QWORD PTR [rdi+0x20] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_1ae6:
	/* 0x1ae6: je     1ac6 <filter_64ty_selector_val+0x2e> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1ae6, 0x1ac6, x86_l_1ac6);
x86_l_1ae8:
	/* 0x1ae8: cmp    esi,0x21 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 33ULL);
x86_l_1aeb:
	/* 0x1aeb: jb     1af3 <filter_64ty_selector_val+0x5b> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1aeb, 0x1af3, x86_l_1af3);
x86_l_1aed:
	/* 0x1aed: cmp    rdx,QWORD PTR [rdi+0x28] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_1af1:
	/* 0x1af1: je     1ac6 <filter_64ty_selector_val+0x2e> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1af1, 0x1ac6, x86_l_1ac6);
x86_l_1af3:
	/* 0x1af3: cmp    ecx,0x4 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_1af6:
	/* 0x1af6: je     1abc <filter_64ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1af6, 0x1abc, x86_l_1abc);
x86_l_1af8:
	/* 0x1af8: jmp    1c8c <filter_64ty_selector_val+0x1f4> */
	X86_SIM_X86_SUB_JMP(0x1af8, 0x1c8c, x86_l_1c8c);
x86_l_1afd:
	/* 0x1afd: mov    ecx,DWORD PTR [rdi+0xc] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1b00:
	/* 0x1b00: cmp    ecx,0xc */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 12ULL);
x86_l_1b03:
	/* 0x1b03: ja     1c10 <filter_64ty_selector_val+0x178> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x1b03, 0x1c10, x86_l_1c10);
x86_l_1b09:
	/* 0x1b09: mov    edx,0x1402 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 5122ULL);
x86_l_1b0e:
	/* 0x1b0e: bt     edx,ecx */
	X86_SIM_RUN_OP(X86_OP_BT, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_1b11:
	/* 0x1b11: jae    1c10 <filter_64ty_selector_val+0x178> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x1b11, 0x1c10, x86_l_1c10);
x86_l_1b17:
	/* 0x1b17: mov    rcx,QWORD PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b1a:
	/* 0x1b1a: cmp    rcx,QWORD PTR [rdi+0x10] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_1b1e:
	/* 0x1b1e: jg     1abc <filter_64ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x1b1e, 0x1abc, x86_l_1abc);
x86_l_1b20:
	/* 0x1b20: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b23:
	/* 0x1b23: cmp    edx,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_1b26:
	/* 0x1b26: jb     1c8c <filter_64ty_selector_val+0x1f4> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1b26, 0x1c8c, x86_l_1c8c);
x86_l_1b2c:
	/* 0x1b2c: cmp    rcx,QWORD PTR [rdi+0x18] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_1b30:
	/* 0x1b30: jg     1abc <filter_64ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x1b30, 0x1abc, x86_l_1abc);
x86_l_1b32:
	/* 0x1b32: cmp    edx,0x19 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 25ULL);
x86_l_1b35:
	/* 0x1b35: jb     1c8c <filter_64ty_selector_val+0x1f4> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1b35, 0x1c8c, x86_l_1c8c);
x86_l_1b3b:
	/* 0x1b3b: cmp    rcx,QWORD PTR [rdi+0x20] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_1b3f:
	/* 0x1b3f: jg     1abc <filter_64ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x1b3f, 0x1abc, x86_l_1abc);
x86_l_1b45:
	/* 0x1b45: cmp    edx,0x21 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 33ULL);
x86_l_1b48:
	/* 0x1b48: jb     1c8c <filter_64ty_selector_val+0x1f4> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1b48, 0x1c8c, x86_l_1c8c);
x86_l_1b4e:
	/* 0x1b4e: cmp    rcx,QWORD PTR [rdi+0x28] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_1b52:
	/* 0x1b52: jg     1abc <filter_64ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x1b52, 0x1abc, x86_l_1abc);
x86_l_1b58:
	/* 0x1b58: jmp    1c8c <filter_64ty_selector_val+0x1f4> */
	X86_SIM_X86_SUB_JMP(0x1b58, 0x1c8c, x86_l_1c8c);
x86_l_1b5d:
	/* 0x1b5d: mov    rcx,QWORD PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b60:
	/* 0x1b60: test   QWORD PTR [rdi+0x10],rcx */
	X86_SIM_RUN_OP(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1b64:
	/* 0x1b64: jne    1abc <filter_64ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x1b64, 0x1abc, x86_l_1abc);
x86_l_1b6a:
	/* 0x1b6a: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b6d:
	/* 0x1b6d: cmp    edx,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_1b70:
	/* 0x1b70: jb     1c8c <filter_64ty_selector_val+0x1f4> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1b70, 0x1c8c, x86_l_1c8c);
x86_l_1b76:
	/* 0x1b76: test   QWORD PTR [rdi+0x18],rcx */
	X86_SIM_RUN_OP(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1b7a:
	/* 0x1b7a: jne    1abc <filter_64ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x1b7a, 0x1abc, x86_l_1abc);
x86_l_1b80:
	/* 0x1b80: cmp    edx,0x19 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 25ULL);
x86_l_1b83:
	/* 0x1b83: jb     1c8c <filter_64ty_selector_val+0x1f4> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1b83, 0x1c8c, x86_l_1c8c);
x86_l_1b89:
	/* 0x1b89: test   QWORD PTR [rdi+0x20],rcx */
	X86_SIM_RUN_OP(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1b8d:
	/* 0x1b8d: jne    1abc <filter_64ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x1b8d, 0x1abc, x86_l_1abc);
x86_l_1b93:
	/* 0x1b93: cmp    edx,0x21 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 33ULL);
x86_l_1b96:
	/* 0x1b96: jb     1c8c <filter_64ty_selector_val+0x1f4> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1b96, 0x1c8c, x86_l_1c8c);
x86_l_1b9c:
	/* 0x1b9c: test   QWORD PTR [rdi+0x28],rcx */
	X86_SIM_RUN_OP(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1ba0:
	/* 0x1ba0: jne    1abc <filter_64ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x1ba0, 0x1abc, x86_l_1abc);
x86_l_1ba6:
	/* 0x1ba6: jmp    1c8c <filter_64ty_selector_val+0x1f4> */
	X86_SIM_X86_SUB_JMP(0x1ba6, 0x1c8c, x86_l_1c8c);
x86_l_1bab:
	/* 0x1bab: mov    ecx,DWORD PTR [rdi+0xc] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1bae:
	/* 0x1bae: cmp    ecx,0xc */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 12ULL);
x86_l_1bb1:
	/* 0x1bb1: ja     1c4f <filter_64ty_selector_val+0x1b7> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x1bb1, 0x1c4f, x86_l_1c4f);
x86_l_1bb7:
	/* 0x1bb7: mov    edx,0x1402 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 5122ULL);
x86_l_1bbc:
	/* 0x1bbc: bt     edx,ecx */
	X86_SIM_RUN_OP(X86_OP_BT, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_1bbf:
	/* 0x1bbf: jae    1c4f <filter_64ty_selector_val+0x1b7> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x1bbf, 0x1c4f, x86_l_1c4f);
x86_l_1bc5:
	/* 0x1bc5: mov    rcx,QWORD PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1bc8:
	/* 0x1bc8: cmp    rcx,QWORD PTR [rdi+0x10] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_1bcc:
	/* 0x1bcc: jl     1abc <filter_64ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_L, 0x1bcc, 0x1abc, x86_l_1abc);
x86_l_1bd2:
	/* 0x1bd2: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1bd5:
	/* 0x1bd5: cmp    edx,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_1bd8:
	/* 0x1bd8: jb     1c8c <filter_64ty_selector_val+0x1f4> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1bd8, 0x1c8c, x86_l_1c8c);
x86_l_1bde:
	/* 0x1bde: cmp    rcx,QWORD PTR [rdi+0x18] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_1be2:
	/* 0x1be2: jl     1abc <filter_64ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_L, 0x1be2, 0x1abc, x86_l_1abc);
x86_l_1be8:
	/* 0x1be8: cmp    edx,0x19 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 25ULL);
x86_l_1beb:
	/* 0x1beb: jb     1c8c <filter_64ty_selector_val+0x1f4> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1beb, 0x1c8c, x86_l_1c8c);
x86_l_1bf1:
	/* 0x1bf1: cmp    rcx,QWORD PTR [rdi+0x20] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_1bf5:
	/* 0x1bf5: jl     1abc <filter_64ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_L, 0x1bf5, 0x1abc, x86_l_1abc);
x86_l_1bfb:
	/* 0x1bfb: cmp    edx,0x21 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 33ULL);
x86_l_1bfe:
	/* 0x1bfe: jb     1c8c <filter_64ty_selector_val+0x1f4> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1bfe, 0x1c8c, x86_l_1c8c);
x86_l_1c04:
	/* 0x1c04: cmp    rcx,QWORD PTR [rdi+0x28] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_1c08:
	/* 0x1c08: jl     1abc <filter_64ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_L, 0x1c08, 0x1abc, x86_l_1abc);
x86_l_1c0e:
	/* 0x1c0e: jmp    1c8c <filter_64ty_selector_val+0x1f4> */
	X86_SIM_X86_SUB_JMP(0x1c0e, 0x1c8c, x86_l_1c8c);
x86_l_1c10:
	/* 0x1c10: mov    rcx,QWORD PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c13:
	/* 0x1c13: cmp    rcx,QWORD PTR [rdi+0x10] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_1c17:
	/* 0x1c17: ja     1abc <filter_64ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x1c17, 0x1abc, x86_l_1abc);
x86_l_1c1d:
	/* 0x1c1d: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c20:
	/* 0x1c20: cmp    edx,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_1c23:
	/* 0x1c23: jb     1c8c <filter_64ty_selector_val+0x1f4> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1c23, 0x1c8c, x86_l_1c8c);
x86_l_1c25:
	/* 0x1c25: cmp    rcx,QWORD PTR [rdi+0x18] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_1c29:
	/* 0x1c29: ja     1abc <filter_64ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x1c29, 0x1abc, x86_l_1abc);
x86_l_1c2f:
	/* 0x1c2f: cmp    edx,0x19 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 25ULL);
x86_l_1c32:
	/* 0x1c32: jb     1c8c <filter_64ty_selector_val+0x1f4> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1c32, 0x1c8c, x86_l_1c8c);
x86_l_1c34:
	/* 0x1c34: cmp    rcx,QWORD PTR [rdi+0x20] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_1c38:
	/* 0x1c38: ja     1abc <filter_64ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x1c38, 0x1abc, x86_l_1abc);
x86_l_1c3e:
	/* 0x1c3e: cmp    edx,0x21 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 33ULL);
x86_l_1c41:
	/* 0x1c41: jb     1c8c <filter_64ty_selector_val+0x1f4> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1c41, 0x1c8c, x86_l_1c8c);
x86_l_1c43:
	/* 0x1c43: cmp    rcx,QWORD PTR [rdi+0x28] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_1c47:
	/* 0x1c47: ja     1abc <filter_64ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x1c47, 0x1abc, x86_l_1abc);
x86_l_1c4d:
	/* 0x1c4d: jmp    1c8c <filter_64ty_selector_val+0x1f4> */
	X86_SIM_X86_SUB_JMP(0x1c4d, 0x1c8c, x86_l_1c8c);
x86_l_1c4f:
	/* 0x1c4f: mov    rcx,QWORD PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c52:
	/* 0x1c52: cmp    rcx,QWORD PTR [rdi+0x10] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_1c56:
	/* 0x1c56: jb     1abc <filter_64ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1c56, 0x1abc, x86_l_1abc);
x86_l_1c5c:
	/* 0x1c5c: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c5f:
	/* 0x1c5f: cmp    edx,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_1c62:
	/* 0x1c62: jb     1c8c <filter_64ty_selector_val+0x1f4> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1c62, 0x1c8c, x86_l_1c8c);
x86_l_1c64:
	/* 0x1c64: cmp    rcx,QWORD PTR [rdi+0x18] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_1c68:
	/* 0x1c68: jb     1abc <filter_64ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1c68, 0x1abc, x86_l_1abc);
x86_l_1c6e:
	/* 0x1c6e: cmp    edx,0x19 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 25ULL);
x86_l_1c71:
	/* 0x1c71: jb     1c8c <filter_64ty_selector_val+0x1f4> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1c71, 0x1c8c, x86_l_1c8c);
x86_l_1c73:
	/* 0x1c73: cmp    rcx,QWORD PTR [rdi+0x20] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_1c77:
	/* 0x1c77: jb     1abc <filter_64ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1c77, 0x1abc, x86_l_1abc);
x86_l_1c7d:
	/* 0x1c7d: cmp    edx,0x21 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 33ULL);
x86_l_1c80:
	/* 0x1c80: jb     1c8c <filter_64ty_selector_val+0x1f4> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1c80, 0x1c8c, x86_l_1c8c);
x86_l_1c82:
	/* 0x1c82: cmp    rcx,QWORD PTR [rdi+0x28] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_1c86:
	/* 0x1c86: jb     1abc <filter_64ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1c86, 0x1abc, x86_l_1abc);
x86_l_1c8c:
	/* 0x1c8c: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1c8e:
	/* 0x1c8e: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_659);

	/* native subroutine native_link_sub_1c8f */
x86_l_1c8f:
	/* 0x1c8f: push   r14 */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_1c91:
	/* 0x1c91: push   rbx */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_1c92:
	/* 0x1c92: sub    rsp,0x18 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SUB, 24ULL);
x86_l_1c96:
	/* 0x1c96: mov    r14,rsi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R14, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_1c99:
	/* 0x1c99: mov    rbx,rdi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RBX, X86_RDI, X86_WIDTH_64, 0, 0);
x86_l_1c9c:
	/* 0x1c9c: movzx  eax,BYTE PTR [rdi+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_1ca0:
	/* 0x1ca0: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1ca4:
	/* 0x1ca4: mov    rdi,QWORD PTR [rip+0xbd0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD_MAP_PTR, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, ((__u64)(long)argfilter_maps));
x86_l_1cab:
	/* 0x1cab: lea    rsi,[rsp+0xc] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1cb0:
	/* 0x1cb0: call   2885 <__native_link_local_memset_zero_dynamic+0x61c> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_1cb5:
	/* 0x1cb5: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_1cb8:
	/* 0x1cb8: je     1ce4 <filter_64ty_map+0x55> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1cb8, 0x1ce4, x86_l_1ce4);
x86_l_1cba:
	/* 0x1cba: mov    rcx,QWORD PTR [r14] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1cbd:
	/* 0x1cbd: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1cc2:
	/* 0x1cc2: lea    rsi,[rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1cc7:
	/* 0x1cc7: mov    rdi,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_1cca:
	/* 0x1cca: call   289f <__native_link_local_memset_zero_dynamic+0x636> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_1ccf:
	/* 0x1ccf: mov    ecx,DWORD PTR [rbx+0x4] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1cd2:
	/* 0x1cd2: cmp    ecx,0xb */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 11ULL);
x86_l_1cd5:
	/* 0x1cd5: je     1cee <filter_64ty_map+0x5f> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1cd5, 0x1cee, x86_l_1cee);
x86_l_1cd7:
	/* 0x1cd7: cmp    ecx,0xa */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 10ULL);
x86_l_1cda:
	/* 0x1cda: jne    1cf6 <filter_64ty_map+0x67> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x1cda, 0x1cf6, x86_l_1cf6);
x86_l_1cdc:
	/* 0x1cdc: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_1cdf:
	/* 0x1cdf: setne  al */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_CC_NE, 0);
x86_l_1ce2:
	/* 0x1ce2: jmp    1cf8 <filter_64ty_map+0x69> */
	X86_SIM_X86_SUB_JMP(0x1ce2, 0x1cf8, x86_l_1cf8);
x86_l_1ce4:
	/* 0x1ce4: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1ce6:
	/* 0x1ce6: add    rsp,0x18 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1cea:
	/* 0x1cea: pop    rbx */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1ceb:
	/* 0x1ceb: pop    r14 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R14, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1ced:
	/* 0x1ced: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_659);
x86_l_1cee:
	/* 0x1cee: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_1cf1:
	/* 0x1cf1: sete   al */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_CC_E, 0);
x86_l_1cf4:
	/* 0x1cf4: jmp    1cf8 <filter_64ty_map+0x69> */
	X86_SIM_X86_SUB_JMP(0x1cf4, 0x1cf8, x86_l_1cf8);
x86_l_1cf6:
	/* 0x1cf6: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1cf8:
	/* 0x1cf8: movzx  eax,al */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8, 0);
x86_l_1cfb:
	/* 0x1cfb: add    rsp,0x18 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1cff:
	/* 0x1cff: pop    rbx */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1d00:
	/* 0x1d00: pop    r14 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R14, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1d02:
	/* 0x1d02: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_659);

	/* native subroutine native_link_sub_1d03 */
x86_l_1d03:
	/* 0x1d03: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1d06:
	/* 0x1d06: mov    eax,DWORD PTR [rdi+0xc] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1d09:
	/* 0x1d09: cmp    eax,0xc */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 12ULL);
x86_l_1d0c:
	/* 0x1d0c: ja     1e06 <filter_64ty_range+0x103> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x1d0c, 0x1e06, x86_l_1e06);
x86_l_1d12:
	/* 0x1d12: mov    edx,0x1402 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 5122ULL);
x86_l_1d17:
	/* 0x1d17: bt     edx,eax */
	X86_SIM_RUN_OP(X86_OP_BT, X86_RDX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_1d1a:
	/* 0x1d1a: jae    1e06 <filter_64ty_range+0x103> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x1d1a, 0x1e06, x86_l_1e06);
x86_l_1d20:
	/* 0x1d20: mov    rsi,QWORD PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d23:
	/* 0x1d23: cmp    ecx,0x1f */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 31ULL);
x86_l_1d26:
	/* 0x1d26: jne    1d96 <filter_64ty_range+0x93> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x1d26, 0x1d96, x86_l_1d96);
x86_l_1d28:
	/* 0x1d28: mov    eax,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_1d2d:
	/* 0x1d2d: cmp    QWORD PTR [rdi+0x10],rsi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d31:
	/* 0x1d31: jg     1d3d <filter_64ty_range+0x3a> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x1d31, 0x1d3d, x86_l_1d3d);
x86_l_1d33:
	/* 0x1d33: cmp    rsi,QWORD PTR [rdi+0x18] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_1d37:
	/* 0x1d37: jle    1e1f <filter_64ty_range+0x11c> */
	X86_SIM_X86_SUB_JCC(X86_CC_LE, 0x1d37, 0x1e1f, x86_l_1e1f);
x86_l_1d3d:
	/* 0x1d3d: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d40:
	/* 0x1d40: cmp    edx,0x19 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 25ULL);
x86_l_1d43:
	/* 0x1d43: jb     1ecd <filter_64ty_range+0x1ca> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1d43, 0x1ecd, x86_l_1ecd);
x86_l_1d49:
	/* 0x1d49: cmp    QWORD PTR [rdi+0x20],rsi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d4d:
	/* 0x1d4d: jg     1d59 <filter_64ty_range+0x56> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x1d4d, 0x1d59, x86_l_1d59);
x86_l_1d4f:
	/* 0x1d4f: cmp    rsi,QWORD PTR [rdi+0x28] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_1d53:
	/* 0x1d53: jle    1e1f <filter_64ty_range+0x11c> */
	X86_SIM_X86_SUB_JCC(X86_CC_LE, 0x1d53, 0x1e1f, x86_l_1e1f);
x86_l_1d59:
	/* 0x1d59: cmp    edx,0x29 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 41ULL);
x86_l_1d5c:
	/* 0x1d5c: jb     1ecd <filter_64ty_range+0x1ca> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1d5c, 0x1ecd, x86_l_1ecd);
x86_l_1d62:
	/* 0x1d62: cmp    QWORD PTR [rdi+0x30],rsi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1d66:
	/* 0x1d66: jg     1d72 <filter_64ty_range+0x6f> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x1d66, 0x1d72, x86_l_1d72);
x86_l_1d68:
	/* 0x1d68: cmp    rsi,QWORD PTR [rdi+0x38] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_1d6c:
	/* 0x1d6c: jle    1e1f <filter_64ty_range+0x11c> */
	X86_SIM_X86_SUB_JCC(X86_CC_LE, 0x1d6c, 0x1e1f, x86_l_1e1f);
x86_l_1d72:
	/* 0x1d72: cmp    edx,0x39 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 57ULL);
x86_l_1d75:
	/* 0x1d75: jb     1ecd <filter_64ty_range+0x1ca> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1d75, 0x1ecd, x86_l_1ecd);
x86_l_1d7b:
	/* 0x1d7b: xor    edx,edx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1d7d:
	/* 0x1d7d: cmp    QWORD PTR [rdi+0x40],rsi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1d81:
	/* 0x1d81: jg     1ecf <filter_64ty_range+0x1cc> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x1d81, 0x1ecf, x86_l_1ecf);
x86_l_1d87:
	/* 0x1d87: cmp    rsi,QWORD PTR [rdi+0x48] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 72ULL);
x86_l_1d8b:
	/* 0x1d8b: jle    1e1f <filter_64ty_range+0x11c> */
	X86_SIM_X86_SUB_JCC(X86_CC_LE, 0x1d8b, 0x1e1f, x86_l_1e1f);
x86_l_1d91:
	/* 0x1d91: jmp    1ecf <filter_64ty_range+0x1cc> */
	X86_SIM_X86_SUB_JMP(0x1d91, 0x1ecf, x86_l_1ecf);
x86_l_1d96:
	/* 0x1d96: mov    eax,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d99:
	/* 0x1d99: cmp    QWORD PTR [rdi+0x10],rsi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d9d:
	/* 0x1d9d: setle  r8b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R8, X86_REG_NONE, X86_WIDTH_8, X86_CC_LE, 0);
x86_l_1da1:
	/* 0x1da1: cmp    rsi,QWORD PTR [rdi+0x18] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_1da5:
	/* 0x1da5: setle  dl */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_CC_LE, 0);
x86_l_1da8:
	/* 0x1da8: and    dl,r8b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_R8, X86_WIDTH_8, X86_ALU_AND, 0);
x86_l_1dab:
	/* 0x1dab: cmp    eax,0x19 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 25ULL);
x86_l_1dae:
	/* 0x1dae: jb     1ecf <filter_64ty_range+0x1cc> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1dae, 0x1ecf, x86_l_1ecf);
x86_l_1db4:
	/* 0x1db4: cmp    QWORD PTR [rdi+0x20],rsi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1db8:
	/* 0x1db8: setle  r8b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R8, X86_REG_NONE, X86_WIDTH_8, X86_CC_LE, 0);
x86_l_1dbc:
	/* 0x1dbc: cmp    rsi,QWORD PTR [rdi+0x28] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_1dc0:
	/* 0x1dc0: setle  r9b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R9, X86_REG_NONE, X86_WIDTH_8, X86_CC_LE, 0);
x86_l_1dc4:
	/* 0x1dc4: and    r9b,r8b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND, 0);
x86_l_1dc7:
	/* 0x1dc7: or     dl,r9b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR, 0);
x86_l_1dca:
	/* 0x1dca: cmp    eax,0x29 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 41ULL);
x86_l_1dcd:
	/* 0x1dcd: jb     1ecf <filter_64ty_range+0x1cc> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1dcd, 0x1ecf, x86_l_1ecf);
x86_l_1dd3:
	/* 0x1dd3: cmp    QWORD PTR [rdi+0x30],rsi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1dd7:
	/* 0x1dd7: setle  r8b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R8, X86_REG_NONE, X86_WIDTH_8, X86_CC_LE, 0);
x86_l_1ddb:
	/* 0x1ddb: cmp    rsi,QWORD PTR [rdi+0x38] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_1ddf:
	/* 0x1ddf: setle  r9b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R9, X86_REG_NONE, X86_WIDTH_8, X86_CC_LE, 0);
x86_l_1de3:
	/* 0x1de3: and    r9b,r8b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND, 0);
x86_l_1de6:
	/* 0x1de6: or     dl,r9b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR, 0);
x86_l_1de9:
	/* 0x1de9: cmp    eax,0x39 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 57ULL);
x86_l_1dec:
	/* 0x1dec: jb     1ecf <filter_64ty_range+0x1cc> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1dec, 0x1ecf, x86_l_1ecf);
x86_l_1df2:
	/* 0x1df2: cmp    QWORD PTR [rdi+0x40],rsi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1df6:
	/* 0x1df6: setle  al */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_CC_LE, 0);
x86_l_1df9:
	/* 0x1df9: cmp    rsi,QWORD PTR [rdi+0x48] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 72ULL);
x86_l_1dfd:
	/* 0x1dfd: setle  sil */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_CC_LE, 0);
x86_l_1e01:
	/* 0x1e01: jmp    1e83 <filter_64ty_range+0x180> */
	X86_SIM_X86_SUB_JMP(0x1e01, 0x1e83, x86_l_1e83);
x86_l_1e06:
	/* 0x1e06: mov    rsi,QWORD PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e09:
	/* 0x1e09: cmp    ecx,0x1f */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 31ULL);
x86_l_1e0c:
	/* 0x1e0c: jne    1e20 <filter_64ty_range+0x11d> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x1e0c, 0x1e20, x86_l_1e20);
x86_l_1e0e:
	/* 0x1e0e: mov    eax,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_1e13:
	/* 0x1e13: cmp    QWORD PTR [rdi+0x10],rsi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e17:
	/* 0x1e17: ja     1e8b <filter_64ty_range+0x188> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x1e17, 0x1e8b, x86_l_1e8b);
x86_l_1e19:
	/* 0x1e19: cmp    rsi,QWORD PTR [rdi+0x18] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_1e1d:
	/* 0x1e1d: ja     1e8b <filter_64ty_range+0x188> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x1e1d, 0x1e8b, x86_l_1e8b);
x86_l_1e1f:
	/* 0x1e1f: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_659);
x86_l_1e20:
	/* 0x1e20: mov    eax,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e23:
	/* 0x1e23: cmp    QWORD PTR [rdi+0x10],rsi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e27:
	/* 0x1e27: setbe  r8b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R8, X86_REG_NONE, X86_WIDTH_8, X86_CC_BE, 0);
x86_l_1e2b:
	/* 0x1e2b: cmp    rsi,QWORD PTR [rdi+0x18] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_1e2f:
	/* 0x1e2f: setbe  dl */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_CC_BE, 0);
x86_l_1e32:
	/* 0x1e32: and    dl,r8b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_R8, X86_WIDTH_8, X86_ALU_AND, 0);
x86_l_1e35:
	/* 0x1e35: cmp    eax,0x19 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 25ULL);
x86_l_1e38:
	/* 0x1e38: jb     1ecf <filter_64ty_range+0x1cc> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1e38, 0x1ecf, x86_l_1ecf);
x86_l_1e3e:
	/* 0x1e3e: cmp    QWORD PTR [rdi+0x20],rsi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1e42:
	/* 0x1e42: setbe  r8b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R8, X86_REG_NONE, X86_WIDTH_8, X86_CC_BE, 0);
x86_l_1e46:
	/* 0x1e46: cmp    rsi,QWORD PTR [rdi+0x28] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_1e4a:
	/* 0x1e4a: setbe  r9b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R9, X86_REG_NONE, X86_WIDTH_8, X86_CC_BE, 0);
x86_l_1e4e:
	/* 0x1e4e: and    r9b,r8b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND, 0);
x86_l_1e51:
	/* 0x1e51: or     dl,r9b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR, 0);
x86_l_1e54:
	/* 0x1e54: cmp    eax,0x29 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 41ULL);
x86_l_1e57:
	/* 0x1e57: jb     1ecf <filter_64ty_range+0x1cc> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1e57, 0x1ecf, x86_l_1ecf);
x86_l_1e59:
	/* 0x1e59: cmp    QWORD PTR [rdi+0x30],rsi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1e5d:
	/* 0x1e5d: setbe  r8b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R8, X86_REG_NONE, X86_WIDTH_8, X86_CC_BE, 0);
x86_l_1e61:
	/* 0x1e61: cmp    rsi,QWORD PTR [rdi+0x38] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_1e65:
	/* 0x1e65: setbe  r9b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R9, X86_REG_NONE, X86_WIDTH_8, X86_CC_BE, 0);
x86_l_1e69:
	/* 0x1e69: and    r9b,r8b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND, 0);
x86_l_1e6c:
	/* 0x1e6c: or     dl,r9b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR, 0);
x86_l_1e6f:
	/* 0x1e6f: cmp    eax,0x39 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 57ULL);
x86_l_1e72:
	/* 0x1e72: jb     1ecf <filter_64ty_range+0x1cc> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1e72, 0x1ecf, x86_l_1ecf);
x86_l_1e74:
	/* 0x1e74: cmp    QWORD PTR [rdi+0x40],rsi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1e78:
	/* 0x1e78: setbe  al */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_CC_BE, 0);
x86_l_1e7b:
	/* 0x1e7b: cmp    rsi,QWORD PTR [rdi+0x48] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 72ULL);
x86_l_1e7f:
	/* 0x1e7f: setbe  sil */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_CC_BE, 0);
x86_l_1e83:
	/* 0x1e83: and    sil,al */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_ALU_AND, 0);
x86_l_1e86:
	/* 0x1e86: or     dl,sil */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RSI, X86_WIDTH_8, X86_ALU_OR, 0);
x86_l_1e89:
	/* 0x1e89: jmp    1ecf <filter_64ty_range+0x1cc> */
	X86_SIM_X86_SUB_JMP(0x1e89, 0x1ecf, x86_l_1ecf);
x86_l_1e8b:
	/* 0x1e8b: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e8e:
	/* 0x1e8e: cmp    edx,0x19 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 25ULL);
x86_l_1e91:
	/* 0x1e91: jb     1ecd <filter_64ty_range+0x1ca> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1e91, 0x1ecd, x86_l_1ecd);
x86_l_1e93:
	/* 0x1e93: cmp    QWORD PTR [rdi+0x20],rsi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1e97:
	/* 0x1e97: ja     1e9f <filter_64ty_range+0x19c> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x1e97, 0x1e9f, x86_l_1e9f);
x86_l_1e99:
	/* 0x1e99: cmp    rsi,QWORD PTR [rdi+0x28] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_1e9d:
	/* 0x1e9d: jbe    1e1f <filter_64ty_range+0x11c> */
	X86_SIM_X86_SUB_JCC(X86_CC_BE, 0x1e9d, 0x1e1f, x86_l_1e1f);
x86_l_1e9f:
	/* 0x1e9f: cmp    edx,0x29 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 41ULL);
x86_l_1ea2:
	/* 0x1ea2: jb     1ecd <filter_64ty_range+0x1ca> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1ea2, 0x1ecd, x86_l_1ecd);
x86_l_1ea4:
	/* 0x1ea4: cmp    QWORD PTR [rdi+0x30],rsi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1ea8:
	/* 0x1ea8: ja     1eb4 <filter_64ty_range+0x1b1> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x1ea8, 0x1eb4, x86_l_1eb4);
x86_l_1eaa:
	/* 0x1eaa: cmp    rsi,QWORD PTR [rdi+0x38] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_1eae:
	/* 0x1eae: jbe    1e1f <filter_64ty_range+0x11c> */
	X86_SIM_X86_SUB_JCC(X86_CC_BE, 0x1eae, 0x1e1f, x86_l_1e1f);
x86_l_1eb4:
	/* 0x1eb4: cmp    edx,0x39 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 57ULL);
x86_l_1eb7:
	/* 0x1eb7: jb     1ecd <filter_64ty_range+0x1ca> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1eb7, 0x1ecd, x86_l_1ecd);
x86_l_1eb9:
	/* 0x1eb9: xor    edx,edx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1ebb:
	/* 0x1ebb: cmp    QWORD PTR [rdi+0x40],rsi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1ebf:
	/* 0x1ebf: ja     1ecf <filter_64ty_range+0x1cc> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x1ebf, 0x1ecf, x86_l_1ecf);
x86_l_1ec1:
	/* 0x1ec1: cmp    rsi,QWORD PTR [rdi+0x48] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 72ULL);
x86_l_1ec5:
	/* 0x1ec5: jbe    1e1f <filter_64ty_range+0x11c> */
	X86_SIM_X86_SUB_JCC(X86_CC_BE, 0x1ec5, 0x1e1f, x86_l_1e1f);
x86_l_1ecb:
	/* 0x1ecb: jmp    1ecf <filter_64ty_range+0x1cc> */
	X86_SIM_X86_SUB_JMP(0x1ecb, 0x1ecf, x86_l_1ecf);
x86_l_1ecd:
	/* 0x1ecd: xor    edx,edx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1ecf:
	/* 0x1ecf: cmp    ecx,0x20 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 32ULL);
x86_l_1ed2:
	/* 0x1ed2: sete   al */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_CC_E, 0);
x86_l_1ed5:
	/* 0x1ed5: xor    dl,0x1 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_ALU_XOR, 1ULL);
x86_l_1ed8:
	/* 0x1ed8: and    dl,al */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RAX, X86_WIDTH_8, X86_ALU_AND, 0);
x86_l_1eda:
	/* 0x1eda: movzx  eax,dl */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8, 0);
x86_l_1edd:
	/* 0x1edd: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_659);

	/* native subroutine native_link_sub_1ede */
x86_l_1ede:
	/* 0x1ede: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1ee1:
	/* 0x1ee1: lea    edx,[rcx-0x1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_1ee4:
	/* 0x1ee4: cmp    edx,0x24 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 36ULL);
x86_l_1ee7:
	/* 0x1ee7: ja     20b0 <filter_32ty_selector_val+0x1d2> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x1ee7, 0x20b0, x86_l_20b0);
x86_l_1eed:
	/* 0x1eed: mov    eax,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_1ef2:
	/* Capture image-bound code identity before scheduled instructions. */
	switch (X86_SIM_L_READ_REG(X86_RDX) << 2) {
	case 0ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1f3eULL); break;
	case 4ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1fdeULL); break;
	case 8ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1f03ULL); break;
	case 12ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1f03ULL); break;
	case 16ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x20b0ULL); break;
	case 20ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1f02ULL); break;
	case 24ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x20b0ULL); break;
	case 28ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x20b0ULL); break;
	case 32ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x20b0ULL); break;
	case 36ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x20b0ULL); break;
	case 40ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x20b0ULL); break;
	case 44ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1f95ULL); break;
	case 48ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x20b0ULL); break;
	case 52ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x20b0ULL); break;
	case 56ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x20b0ULL); break;
	case 60ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x20b0ULL); break;
	case 64ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x20b0ULL); break;
	case 68ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x20b0ULL); break;
	case 72ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x20b0ULL); break;
	case 76ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x20b0ULL); break;
	case 80ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x20b0ULL); break;
	case 84ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x20b0ULL); break;
	case 88ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x20b0ULL); break;
	case 92ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x20b0ULL); break;
	case 96ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x20b0ULL); break;
	case 100ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1f02ULL); break;
	case 104ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1f02ULL); break;
	case 108ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x20b0ULL); break;
	case 112ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x20b0ULL); break;
	case 116ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x20b0ULL); break;
	case 120ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x20b0ULL); break;
	case 124ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x20b0ULL); break;
	case 128ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x20b0ULL); break;
	case 132ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x20b0ULL); break;
	case 136ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x20b0ULL); break;
	case 140ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x20b0ULL); break;
	case 144ULL: X86_SIM_X86_CODE_ADDRESS(X86_RDX, 0x1f02ULL); break;
	default: __x86_sim_unresolved_indirect_target();
	}
x86_l_1f00:
	/* 0x1f00: jmp    rdx */
	{
		__u64 __x86_target = X86_SIM_L_READ_REG(X86_RDX);
		switch (X86_SIM_L_REG_TAG(X86_RDX)) {
		case X86_SIM_TAG_CODE:
			switch (__x86_target) {
			case 0x1f02ULL: goto x86_l_1f02;
			case 0x1f03ULL: goto x86_l_1f03;
			case 0x1f3eULL: goto x86_l_1f3e;
			case 0x1f95ULL: goto x86_l_1f95;
			case 0x1fdeULL: goto x86_l_1fde;
			case 0x20b0ULL: goto x86_l_20b0;
			default: __x86_sim_unresolved_indirect_target();
			}
			break;
		default: __x86_sim_unresolved_indirect_target();
		}
	}
x86_l_1f02:
	/* 0x1f02: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_3c1);
x86_l_1f03:
	/* 0x1f03: mov    edx,DWORD PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f05:
	/* 0x1f05: cmp    edx,DWORD PTR [rdi+0x10] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 16ULL);
x86_l_1f08:
	/* 0x1f08: jne    1f13 <filter_32ty_selector_val+0x35> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x1f08, 0x1f13, x86_l_1f13);
x86_l_1f0a:
	/* 0x1f0a: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1f0c:
	/* 0x1f0c: cmp    ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 3ULL);
x86_l_1f0f:
	/* 0x1f0f: sete   al */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_CC_E, 0);
x86_l_1f12:
	/* 0x1f12: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_3c1);
x86_l_1f13:
	/* 0x1f13: mov    esi,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f16:
	/* 0x1f16: cmp    esi,0xd */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 13ULL);
x86_l_1f19:
	/* 0x1f19: jb     1f34 <filter_32ty_selector_val+0x56> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1f19, 0x1f34, x86_l_1f34);
x86_l_1f1b:
	/* 0x1f1b: cmp    edx,DWORD PTR [rdi+0x14] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_1f1e:
	/* 0x1f1e: je     1f0a <filter_32ty_selector_val+0x2c> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1f1e, 0x1f0a, x86_l_1f0a);
x86_l_1f20:
	/* 0x1f20: cmp    esi,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_1f23:
	/* 0x1f23: jb     1f34 <filter_32ty_selector_val+0x56> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1f23, 0x1f34, x86_l_1f34);
x86_l_1f25:
	/* 0x1f25: cmp    edx,DWORD PTR [rdi+0x18] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 24ULL);
x86_l_1f28:
	/* 0x1f28: je     1f0a <filter_32ty_selector_val+0x2c> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1f28, 0x1f0a, x86_l_1f0a);
x86_l_1f2a:
	/* 0x1f2a: cmp    esi,0x15 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 21ULL);
x86_l_1f2d:
	/* 0x1f2d: jb     1f34 <filter_32ty_selector_val+0x56> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1f2d, 0x1f34, x86_l_1f34);
x86_l_1f2f:
	/* 0x1f2f: cmp    edx,DWORD PTR [rdi+0x1c] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 28ULL);
x86_l_1f32:
	/* 0x1f32: je     1f0a <filter_32ty_selector_val+0x2c> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1f32, 0x1f0a, x86_l_1f0a);
x86_l_1f34:
	/* 0x1f34: cmp    ecx,0x4 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_1f37:
	/* 0x1f37: je     1f02 <filter_32ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1f37, 0x1f02, x86_l_1f02);
x86_l_1f39:
	/* 0x1f39: jmp    20b0 <filter_32ty_selector_val+0x1d2> */
	X86_SIM_X86_SUB_JMP(0x1f39, 0x20b0, x86_l_20b0);
x86_l_1f3e:
	/* 0x1f3e: mov    ecx,DWORD PTR [rdi+0xc] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1f41:
	/* 0x1f41: cmp    ecx,0xc */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 12ULL);
x86_l_1f44:
	/* 0x1f44: ja     203e <filter_32ty_selector_val+0x160> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x1f44, 0x203e, x86_l_203e);
x86_l_1f4a:
	/* 0x1f4a: mov    edx,0x1402 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 5122ULL);
x86_l_1f4f:
	/* 0x1f4f: bt     edx,ecx */
	X86_SIM_RUN_OP(X86_OP_BT, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_1f52:
	/* 0x1f52: jae    203e <filter_32ty_selector_val+0x160> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x1f52, 0x203e, x86_l_203e);
x86_l_1f58:
	/* 0x1f58: mov    ecx,DWORD PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f5a:
	/* 0x1f5a: cmp    ecx,DWORD PTR [rdi+0x10] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 16ULL);
x86_l_1f5d:
	/* 0x1f5d: jg     1f02 <filter_32ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x1f5d, 0x1f02, x86_l_1f02);
x86_l_1f5f:
	/* 0x1f5f: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f62:
	/* 0x1f62: cmp    edx,0xd */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 13ULL);
x86_l_1f65:
	/* 0x1f65: jb     20b0 <filter_32ty_selector_val+0x1d2> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1f65, 0x20b0, x86_l_20b0);
x86_l_1f6b:
	/* 0x1f6b: cmp    ecx,DWORD PTR [rdi+0x14] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_1f6e:
	/* 0x1f6e: jg     1f02 <filter_32ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x1f6e, 0x1f02, x86_l_1f02);
x86_l_1f70:
	/* 0x1f70: cmp    edx,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_1f73:
	/* 0x1f73: jb     20b0 <filter_32ty_selector_val+0x1d2> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1f73, 0x20b0, x86_l_20b0);
x86_l_1f79:
	/* 0x1f79: cmp    ecx,DWORD PTR [rdi+0x18] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 24ULL);
x86_l_1f7c:
	/* 0x1f7c: jg     1f02 <filter_32ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x1f7c, 0x1f02, x86_l_1f02);
x86_l_1f7e:
	/* 0x1f7e: cmp    edx,0x15 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 21ULL);
x86_l_1f81:
	/* 0x1f81: jb     20b0 <filter_32ty_selector_val+0x1d2> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1f81, 0x20b0, x86_l_20b0);
x86_l_1f87:
	/* 0x1f87: cmp    ecx,DWORD PTR [rdi+0x1c] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 28ULL);
x86_l_1f8a:
	/* 0x1f8a: jg     1f02 <filter_32ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x1f8a, 0x1f02, x86_l_1f02);
x86_l_1f90:
	/* 0x1f90: jmp    20b0 <filter_32ty_selector_val+0x1d2> */
	X86_SIM_X86_SUB_JMP(0x1f90, 0x20b0, x86_l_20b0);
x86_l_1f95:
	/* 0x1f95: mov    ecx,DWORD PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f97:
	/* 0x1f97: test   DWORD PTR [rdi+0x10],ecx */
	X86_SIM_RUN_OP(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1f9a:
	/* 0x1f9a: jne    1f02 <filter_32ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x1f9a, 0x1f02, x86_l_1f02);
x86_l_1fa0:
	/* 0x1fa0: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1fa3:
	/* 0x1fa3: cmp    edx,0xd */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 13ULL);
x86_l_1fa6:
	/* 0x1fa6: jb     20b0 <filter_32ty_selector_val+0x1d2> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1fa6, 0x20b0, x86_l_20b0);
x86_l_1fac:
	/* 0x1fac: test   DWORD PTR [rdi+0x14],ecx */
	X86_SIM_RUN_OP(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_1faf:
	/* 0x1faf: jne    1f02 <filter_32ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x1faf, 0x1f02, x86_l_1f02);
x86_l_1fb5:
	/* 0x1fb5: cmp    edx,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_1fb8:
	/* 0x1fb8: jb     20b0 <filter_32ty_selector_val+0x1d2> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1fb8, 0x20b0, x86_l_20b0);
x86_l_1fbe:
	/* 0x1fbe: test   DWORD PTR [rdi+0x18],ecx */
	X86_SIM_RUN_OP(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1fc1:
	/* 0x1fc1: jne    1f02 <filter_32ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x1fc1, 0x1f02, x86_l_1f02);
x86_l_1fc7:
	/* 0x1fc7: cmp    edx,0x15 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 21ULL);
x86_l_1fca:
	/* 0x1fca: jb     20b0 <filter_32ty_selector_val+0x1d2> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1fca, 0x20b0, x86_l_20b0);
x86_l_1fd0:
	/* 0x1fd0: test   DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_RUN_OP(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120259084288ULL);
x86_l_1fd3:
	/* 0x1fd3: jne    1f02 <filter_32ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x1fd3, 0x1f02, x86_l_1f02);
x86_l_1fd9:
	/* 0x1fd9: jmp    20b0 <filter_32ty_selector_val+0x1d2> */
	X86_SIM_X86_SUB_JMP(0x1fd9, 0x20b0, x86_l_20b0);
x86_l_1fde:
	/* 0x1fde: mov    ecx,DWORD PTR [rdi+0xc] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1fe1:
	/* 0x1fe1: cmp    ecx,0xc */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 12ULL);
x86_l_1fe4:
	/* 0x1fe4: ja     2078 <filter_32ty_selector_val+0x19a> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x1fe4, 0x2078, x86_l_2078);
x86_l_1fea:
	/* 0x1fea: mov    edx,0x1402 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 5122ULL);
x86_l_1fef:
	/* 0x1fef: bt     edx,ecx */
	X86_SIM_RUN_OP(X86_OP_BT, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_1ff2:
	/* 0x1ff2: jae    2078 <filter_32ty_selector_val+0x19a> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x1ff2, 0x2078, x86_l_2078);
x86_l_1ff8:
	/* 0x1ff8: mov    ecx,DWORD PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ffa:
	/* 0x1ffa: cmp    ecx,DWORD PTR [rdi+0x10] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 16ULL);
x86_l_1ffd:
	/* 0x1ffd: jl     1f02 <filter_32ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_L, 0x1ffd, 0x1f02, x86_l_1f02);
x86_l_2003:
	/* 0x2003: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2006:
	/* 0x2006: cmp    edx,0xd */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 13ULL);
x86_l_2009:
	/* 0x2009: jb     20b0 <filter_32ty_selector_val+0x1d2> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x2009, 0x20b0, x86_l_20b0);
x86_l_200f:
	/* 0x200f: cmp    ecx,DWORD PTR [rdi+0x14] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_2012:
	/* 0x2012: jl     1f02 <filter_32ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_L, 0x2012, 0x1f02, x86_l_1f02);
x86_l_2018:
	/* 0x2018: cmp    edx,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_201b:
	/* 0x201b: jb     20b0 <filter_32ty_selector_val+0x1d2> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x201b, 0x20b0, x86_l_20b0);
x86_l_2021:
	/* 0x2021: cmp    ecx,DWORD PTR [rdi+0x18] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 24ULL);
x86_l_2024:
	/* 0x2024: jl     1f02 <filter_32ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_L, 0x2024, 0x1f02, x86_l_1f02);
x86_l_202a:
	/* 0x202a: cmp    edx,0x15 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 21ULL);
x86_l_202d:
	/* 0x202d: jb     20b0 <filter_32ty_selector_val+0x1d2> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x202d, 0x20b0, x86_l_20b0);
x86_l_2033:
	/* 0x2033: cmp    ecx,DWORD PTR [rdi+0x1c] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 28ULL);
x86_l_2036:
	/* 0x2036: jl     1f02 <filter_32ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_L, 0x2036, 0x1f02, x86_l_1f02);
x86_l_203c:
	/* 0x203c: jmp    20b0 <filter_32ty_selector_val+0x1d2> */
	X86_SIM_X86_SUB_JMP(0x203c, 0x20b0, x86_l_20b0);
x86_l_203e:
	/* 0x203e: mov    ecx,DWORD PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2040:
	/* 0x2040: cmp    ecx,DWORD PTR [rdi+0x10] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 16ULL);
x86_l_2043:
	/* 0x2043: ja     1f02 <filter_32ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x2043, 0x1f02, x86_l_1f02);
x86_l_2049:
	/* 0x2049: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_204c:
	/* 0x204c: cmp    edx,0xd */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 13ULL);
x86_l_204f:
	/* 0x204f: jb     20b0 <filter_32ty_selector_val+0x1d2> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x204f, 0x20b0, x86_l_20b0);
x86_l_2051:
	/* 0x2051: cmp    ecx,DWORD PTR [rdi+0x14] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_2054:
	/* 0x2054: ja     1f02 <filter_32ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x2054, 0x1f02, x86_l_1f02);
x86_l_205a:
	/* 0x205a: cmp    edx,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_205d:
	/* 0x205d: jb     20b0 <filter_32ty_selector_val+0x1d2> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x205d, 0x20b0, x86_l_20b0);
x86_l_205f:
	/* 0x205f: cmp    ecx,DWORD PTR [rdi+0x18] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 24ULL);
x86_l_2062:
	/* 0x2062: ja     1f02 <filter_32ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x2062, 0x1f02, x86_l_1f02);
x86_l_2068:
	/* 0x2068: cmp    edx,0x15 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 21ULL);
x86_l_206b:
	/* 0x206b: jb     20b0 <filter_32ty_selector_val+0x1d2> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x206b, 0x20b0, x86_l_20b0);
x86_l_206d:
	/* 0x206d: cmp    ecx,DWORD PTR [rdi+0x1c] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 28ULL);
x86_l_2070:
	/* 0x2070: ja     1f02 <filter_32ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x2070, 0x1f02, x86_l_1f02);
x86_l_2076:
	/* 0x2076: jmp    20b0 <filter_32ty_selector_val+0x1d2> */
	X86_SIM_X86_SUB_JMP(0x2076, 0x20b0, x86_l_20b0);
x86_l_2078:
	/* 0x2078: mov    ecx,DWORD PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_207a:
	/* 0x207a: cmp    ecx,DWORD PTR [rdi+0x10] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 16ULL);
x86_l_207d:
	/* 0x207d: jb     1f02 <filter_32ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x207d, 0x1f02, x86_l_1f02);
x86_l_2083:
	/* 0x2083: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2086:
	/* 0x2086: cmp    edx,0xd */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 13ULL);
x86_l_2089:
	/* 0x2089: jb     20b0 <filter_32ty_selector_val+0x1d2> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x2089, 0x20b0, x86_l_20b0);
x86_l_208b:
	/* 0x208b: cmp    ecx,DWORD PTR [rdi+0x14] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_208e:
	/* 0x208e: jb     1f02 <filter_32ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x208e, 0x1f02, x86_l_1f02);
x86_l_2094:
	/* 0x2094: cmp    edx,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_2097:
	/* 0x2097: jb     20b0 <filter_32ty_selector_val+0x1d2> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x2097, 0x20b0, x86_l_20b0);
x86_l_2099:
	/* 0x2099: cmp    ecx,DWORD PTR [rdi+0x18] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 24ULL);
x86_l_209c:
	/* 0x209c: jb     1f02 <filter_32ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x209c, 0x1f02, x86_l_1f02);
x86_l_20a2:
	/* 0x20a2: cmp    edx,0x15 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 21ULL);
x86_l_20a5:
	/* 0x20a5: jb     20b0 <filter_32ty_selector_val+0x1d2> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x20a5, 0x20b0, x86_l_20b0);
x86_l_20a7:
	/* 0x20a7: cmp    ecx,DWORD PTR [rdi+0x1c] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 28ULL);
x86_l_20aa:
	/* 0x20aa: jb     1f02 <filter_32ty_selector_val+0x24> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x20aa, 0x1f02, x86_l_1f02);
x86_l_20b0:
	/* 0x20b0: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_20b2:
	/* 0x20b2: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_3c1);

	/* native subroutine native_link_sub_20b3 */
x86_l_20b3:
	/* 0x20b3: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_20b6:
	/* 0x20b6: mov    eax,DWORD PTR [rdi+0xc] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_20b9:
	/* 0x20b9: cmp    eax,0xc */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 12ULL);
x86_l_20bc:
	/* 0x20bc: ja     21a2 <filter_32ty_range+0xef> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x20bc, 0x21a2, x86_l_21a2);
x86_l_20c2:
	/* 0x20c2: mov    edx,0x1402 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 5122ULL);
x86_l_20c7:
	/* 0x20c7: bt     edx,eax */
	X86_SIM_RUN_OP(X86_OP_BT, X86_RDX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_20ca:
	/* 0x20ca: jae    21a2 <filter_32ty_range+0xef> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x20ca, 0x21a2, x86_l_21a2);
x86_l_20d0:
	/* 0x20d0: mov    esi,DWORD PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20d2:
	/* 0x20d2: cmp    ecx,0x1f */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 31ULL);
x86_l_20d5:
	/* 0x20d5: jne    213d <filter_32ty_range+0x8a> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x20d5, 0x213d, x86_l_213d);
x86_l_20d7:
	/* 0x20d7: mov    eax,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_20dc:
	/* 0x20dc: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_20df:
	/* 0x20df: jg     20ea <filter_32ty_range+0x37> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x20df, 0x20ea, x86_l_20ea);
x86_l_20e1:
	/* 0x20e1: cmp    esi,DWORD PTR [rdi+0x14] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_20e4:
	/* 0x20e4: jle    21b8 <filter_32ty_range+0x105> */
	X86_SIM_X86_SUB_JCC(X86_CC_LE, 0x20e4, 0x21b8, x86_l_21b8);
x86_l_20ea:
	/* 0x20ea: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20ed:
	/* 0x20ed: cmp    edx,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_20f0:
	/* 0x20f0: jb     2258 <filter_32ty_range+0x1a5> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x20f0, 0x2258, x86_l_2258);
x86_l_20f6:
	/* 0x20f6: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_20f9:
	/* 0x20f9: jg     2104 <filter_32ty_range+0x51> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x20f9, 0x2104, x86_l_2104);
x86_l_20fb:
	/* 0x20fb: cmp    esi,DWORD PTR [rdi+0x1c] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 28ULL);
x86_l_20fe:
	/* 0x20fe: jle    21b8 <filter_32ty_range+0x105> */
	X86_SIM_X86_SUB_JCC(X86_CC_LE, 0x20fe, 0x21b8, x86_l_21b8);
x86_l_2104:
	/* 0x2104: cmp    edx,0x19 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 25ULL);
x86_l_2107:
	/* 0x2107: jb     2258 <filter_32ty_range+0x1a5> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x2107, 0x2258, x86_l_2258);
x86_l_210d:
	/* 0x210d: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2110:
	/* 0x2110: jg     211b <filter_32ty_range+0x68> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x2110, 0x211b, x86_l_211b);
x86_l_2112:
	/* 0x2112: cmp    esi,DWORD PTR [rdi+0x24] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 36ULL);
x86_l_2115:
	/* 0x2115: jle    21b8 <filter_32ty_range+0x105> */
	X86_SIM_X86_SUB_JCC(X86_CC_LE, 0x2115, 0x21b8, x86_l_21b8);
x86_l_211b:
	/* 0x211b: cmp    edx,0x21 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 33ULL);
x86_l_211e:
	/* 0x211e: jb     2258 <filter_32ty_range+0x1a5> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x211e, 0x2258, x86_l_2258);
x86_l_2124:
	/* 0x2124: xor    edx,edx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_2126:
	/* 0x2126: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2129:
	/* 0x2129: jg     225a <filter_32ty_range+0x1a7> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x2129, 0x225a, x86_l_225a);
x86_l_212f:
	/* 0x212f: cmp    esi,DWORD PTR [rdi+0x2c] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 44ULL);
x86_l_2132:
	/* 0x2132: jle    21b8 <filter_32ty_range+0x105> */
	X86_SIM_X86_SUB_JCC(X86_CC_LE, 0x2132, 0x21b8, x86_l_21b8);
x86_l_2138:
	/* 0x2138: jmp    225a <filter_32ty_range+0x1a7> */
	X86_SIM_X86_SUB_JMP(0x2138, 0x225a, x86_l_225a);
x86_l_213d:
	/* 0x213d: mov    eax,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2140:
	/* 0x2140: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2143:
	/* 0x2143: setle  r8b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R8, X86_REG_NONE, X86_WIDTH_8, X86_CC_LE, 0);
x86_l_2147:
	/* 0x2147: cmp    esi,DWORD PTR [rdi+0x14] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_214a:
	/* 0x214a: setle  dl */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_CC_LE, 0);
x86_l_214d:
	/* 0x214d: and    dl,r8b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_R8, X86_WIDTH_8, X86_ALU_AND, 0);
x86_l_2150:
	/* 0x2150: cmp    eax,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_2153:
	/* 0x2153: jb     225a <filter_32ty_range+0x1a7> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x2153, 0x225a, x86_l_225a);
x86_l_2159:
	/* 0x2159: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_215c:
	/* 0x215c: setle  r8b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R8, X86_REG_NONE, X86_WIDTH_8, X86_CC_LE, 0);
x86_l_2160:
	/* 0x2160: cmp    esi,DWORD PTR [rdi+0x1c] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 28ULL);
x86_l_2163:
	/* 0x2163: setle  r9b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R9, X86_REG_NONE, X86_WIDTH_8, X86_CC_LE, 0);
x86_l_2167:
	/* 0x2167: and    r9b,r8b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND, 0);
x86_l_216a:
	/* 0x216a: or     dl,r9b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR, 0);
x86_l_216d:
	/* 0x216d: cmp    eax,0x19 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 25ULL);
x86_l_2170:
	/* 0x2170: jb     225a <filter_32ty_range+0x1a7> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x2170, 0x225a, x86_l_225a);
x86_l_2176:
	/* 0x2176: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2179:
	/* 0x2179: setle  r8b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R8, X86_REG_NONE, X86_WIDTH_8, X86_CC_LE, 0);
x86_l_217d:
	/* 0x217d: cmp    esi,DWORD PTR [rdi+0x24] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 36ULL);
x86_l_2180:
	/* 0x2180: setle  r9b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R9, X86_REG_NONE, X86_WIDTH_8, X86_CC_LE, 0);
x86_l_2184:
	/* 0x2184: and    r9b,r8b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND, 0);
x86_l_2187:
	/* 0x2187: or     dl,r9b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR, 0);
x86_l_218a:
	/* 0x218a: cmp    eax,0x21 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 33ULL);
x86_l_218d:
	/* 0x218d: jb     225a <filter_32ty_range+0x1a7> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x218d, 0x225a, x86_l_225a);
x86_l_2193:
	/* 0x2193: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2196:
	/* 0x2196: setle  al */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_CC_LE, 0);
x86_l_2199:
	/* 0x2199: cmp    esi,DWORD PTR [rdi+0x2c] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 44ULL);
x86_l_219c:
	/* 0x219c: setle  sil */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_CC_LE, 0);
x86_l_21a0:
	/* 0x21a0: jmp    2214 <filter_32ty_range+0x161> */
	X86_SIM_X86_SUB_JMP(0x21a0, 0x2214, x86_l_2214);
x86_l_21a2:
	/* 0x21a2: mov    esi,DWORD PTR [rsi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21a4:
	/* 0x21a4: cmp    ecx,0x1f */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 31ULL);
x86_l_21a7:
	/* 0x21a7: jne    21b9 <filter_32ty_range+0x106> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x21a7, 0x21b9, x86_l_21b9);
x86_l_21a9:
	/* 0x21a9: mov    eax,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_21ae:
	/* 0x21ae: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_21b1:
	/* 0x21b1: ja     221c <filter_32ty_range+0x169> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x21b1, 0x221c, x86_l_221c);
x86_l_21b3:
	/* 0x21b3: cmp    esi,DWORD PTR [rdi+0x14] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_21b6:
	/* 0x21b6: ja     221c <filter_32ty_range+0x169> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x21b6, 0x221c, x86_l_221c);
x86_l_21b8:
	/* 0x21b8: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_3c1);
x86_l_21b9:
	/* 0x21b9: mov    eax,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_21bc:
	/* 0x21bc: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_21bf:
	/* 0x21bf: setbe  r8b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R8, X86_REG_NONE, X86_WIDTH_8, X86_CC_BE, 0);
x86_l_21c3:
	/* 0x21c3: cmp    esi,DWORD PTR [rdi+0x14] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_21c6:
	/* 0x21c6: setbe  dl */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_CC_BE, 0);
x86_l_21c9:
	/* 0x21c9: and    dl,r8b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_R8, X86_WIDTH_8, X86_ALU_AND, 0);
x86_l_21cc:
	/* 0x21cc: cmp    eax,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_21cf:
	/* 0x21cf: jb     225a <filter_32ty_range+0x1a7> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x21cf, 0x225a, x86_l_225a);
x86_l_21d5:
	/* 0x21d5: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_21d8:
	/* 0x21d8: setbe  r8b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R8, X86_REG_NONE, X86_WIDTH_8, X86_CC_BE, 0);
x86_l_21dc:
	/* 0x21dc: cmp    esi,DWORD PTR [rdi+0x1c] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 28ULL);
x86_l_21df:
	/* 0x21df: setbe  r9b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R9, X86_REG_NONE, X86_WIDTH_8, X86_CC_BE, 0);
x86_l_21e3:
	/* 0x21e3: and    r9b,r8b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND, 0);
x86_l_21e6:
	/* 0x21e6: or     dl,r9b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR, 0);
x86_l_21e9:
	/* 0x21e9: cmp    eax,0x19 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 25ULL);
x86_l_21ec:
	/* 0x21ec: jb     225a <filter_32ty_range+0x1a7> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x21ec, 0x225a, x86_l_225a);
x86_l_21ee:
	/* 0x21ee: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_21f1:
	/* 0x21f1: setbe  r8b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R8, X86_REG_NONE, X86_WIDTH_8, X86_CC_BE, 0);
x86_l_21f5:
	/* 0x21f5: cmp    esi,DWORD PTR [rdi+0x24] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 36ULL);
x86_l_21f8:
	/* 0x21f8: setbe  r9b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R9, X86_REG_NONE, X86_WIDTH_8, X86_CC_BE, 0);
x86_l_21fc:
	/* 0x21fc: and    r9b,r8b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND, 0);
x86_l_21ff:
	/* 0x21ff: or     dl,r9b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR, 0);
x86_l_2202:
	/* 0x2202: cmp    eax,0x21 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 33ULL);
x86_l_2205:
	/* 0x2205: jb     225a <filter_32ty_range+0x1a7> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x2205, 0x225a, x86_l_225a);
x86_l_2207:
	/* 0x2207: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_220a:
	/* 0x220a: setbe  al */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_CC_BE, 0);
x86_l_220d:
	/* 0x220d: cmp    esi,DWORD PTR [rdi+0x2c] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 44ULL);
x86_l_2210:
	/* 0x2210: setbe  sil */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_CC_BE, 0);
x86_l_2214:
	/* 0x2214: and    sil,al */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_ALU_AND, 0);
x86_l_2217:
	/* 0x2217: or     dl,sil */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RSI, X86_WIDTH_8, X86_ALU_OR, 0);
x86_l_221a:
	/* 0x221a: jmp    225a <filter_32ty_range+0x1a7> */
	X86_SIM_X86_SUB_JMP(0x221a, 0x225a, x86_l_225a);
x86_l_221c:
	/* 0x221c: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_221f:
	/* 0x221f: cmp    edx,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_2222:
	/* 0x2222: jb     2258 <filter_32ty_range+0x1a5> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x2222, 0x2258, x86_l_2258);
x86_l_2224:
	/* 0x2224: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2227:
	/* 0x2227: ja     222e <filter_32ty_range+0x17b> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x2227, 0x222e, x86_l_222e);
x86_l_2229:
	/* 0x2229: cmp    esi,DWORD PTR [rdi+0x1c] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 28ULL);
x86_l_222c:
	/* 0x222c: jbe    21b8 <filter_32ty_range+0x105> */
	X86_SIM_X86_SUB_JCC(X86_CC_BE, 0x222c, 0x21b8, x86_l_21b8);
x86_l_222e:
	/* 0x222e: cmp    edx,0x19 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 25ULL);
x86_l_2231:
	/* 0x2231: jb     2258 <filter_32ty_range+0x1a5> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x2231, 0x2258, x86_l_2258);
x86_l_2233:
	/* 0x2233: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2236:
	/* 0x2236: ja     2241 <filter_32ty_range+0x18e> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x2236, 0x2241, x86_l_2241);
x86_l_2238:
	/* 0x2238: cmp    esi,DWORD PTR [rdi+0x24] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 36ULL);
x86_l_223b:
	/* 0x223b: jbe    21b8 <filter_32ty_range+0x105> */
	X86_SIM_X86_SUB_JCC(X86_CC_BE, 0x223b, 0x21b8, x86_l_21b8);
x86_l_2241:
	/* 0x2241: cmp    edx,0x21 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 33ULL);
x86_l_2244:
	/* 0x2244: jb     2258 <filter_32ty_range+0x1a5> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x2244, 0x2258, x86_l_2258);
x86_l_2246:
	/* 0x2246: xor    edx,edx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_2248:
	/* 0x2248: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_224b:
	/* 0x224b: ja     225a <filter_32ty_range+0x1a7> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x224b, 0x225a, x86_l_225a);
x86_l_224d:
	/* 0x224d: cmp    esi,DWORD PTR [rdi+0x2c] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 44ULL);
x86_l_2250:
	/* 0x2250: jbe    21b8 <filter_32ty_range+0x105> */
	X86_SIM_X86_SUB_JCC(X86_CC_BE, 0x2250, 0x21b8, x86_l_21b8);
x86_l_2256:
	/* 0x2256: jmp    225a <filter_32ty_range+0x1a7> */
	X86_SIM_X86_SUB_JMP(0x2256, 0x225a, x86_l_225a);
x86_l_2258:
	/* 0x2258: xor    edx,edx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_225a:
	/* 0x225a: cmp    ecx,0x20 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 32ULL);
x86_l_225d:
	/* 0x225d: sete   al */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_CC_E, 0);
x86_l_2260:
	/* 0x2260: xor    dl,0x1 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_ALU_XOR, 1ULL);
x86_l_2263:
	/* 0x2263: and    dl,al */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RAX, X86_WIDTH_8, X86_ALU_AND, 0);
x86_l_2265:
	/* 0x2265: movzx  eax,dl */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8, 0);
x86_l_2268:
	/* 0x2268: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_3c1);

	/* native subroutine native_link_sub_2269 */
x86_l_2269:
	/* 0x2269: mov    rax,rdi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RDI, X86_WIDTH_64, 0, 0);
x86_l_226c:
	/* 0x226c: xor    r8d,r8d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_226f:
	/* 0x226f: cmp    rdx,0x20 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, 0, 32ULL);
x86_l_2273:
	/* 0x2273: jb     229a <__native_link_local_memset_zero_dynamic+0x31> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x2273, 0x229a, x86_l_229a);
x86_l_2279:
	/* 0x2279: mov    QWORD PTR [rdi],r8 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_227c:
	/* 0x227c: mov    QWORD PTR [rdi+0x8],r8 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2280:
	/* 0x2280: mov    QWORD PTR [rdi+0x10],r8 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2284:
	/* 0x2284: mov    QWORD PTR [rdi+0x18],r8 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2288:
	/* 0x2288: add    rdi,0x20 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_228c:
	/* 0x228c: sub    rdx,0x20 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SUB, 32ULL);
x86_l_2290:
	/* 0x2290: cmp    rdx,0x20 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, 0, 32ULL);
x86_l_2294:
	/* 0x2294: jae    2279 <__native_link_local_memset_zero_dynamic+0x10> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x2294, 0x2279, x86_l_2279);
x86_l_229a:
	/* 0x229a: cmp    rdx,0x8 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, 0, 8ULL);
x86_l_229e:
	/* 0x229e: jb     22b9 <__native_link_local_memset_zero_dynamic+0x50> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x229e, 0x22b9, x86_l_22b9);
x86_l_22a4:
	/* 0x22a4: mov    QWORD PTR [rdi],r8 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22a7:
	/* 0x22a7: add    rdi,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_22ab:
	/* 0x22ab: sub    rdx,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SUB, 8ULL);
x86_l_22af:
	/* 0x22af: cmp    rdx,0x8 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, 0, 8ULL);
x86_l_22b3:
	/* 0x22b3: jae    22a4 <__native_link_local_memset_zero_dynamic+0x3b> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x22b3, 0x22a4, x86_l_22a4);
x86_l_22b9:
	/* 0x22b9: test   dl,0x4 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, 0, 4ULL);
x86_l_22bc:
	/* 0x22bc: je     22c9 <__native_link_local_memset_zero_dynamic+0x60> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x22bc, 0x22c9, x86_l_22c9);
x86_l_22c2:
	/* 0x22c2: mov    DWORD PTR [rdi],r8d */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22c5:
	/* 0x22c5: add    rdi,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_22c9:
	/* 0x22c9: test   dl,0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, 0, 2ULL);
x86_l_22cc:
	/* 0x22cc: je     22da <__native_link_local_memset_zero_dynamic+0x71> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x22cc, 0x22da, x86_l_22da);
x86_l_22d2:
	/* 0x22d2: mov    WORD PTR [rdi],r8w */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_R8, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22d6:
	/* 0x22d6: add    rdi,0x2 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_22da:
	/* 0x22da: test   dl,0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_22dd:
	/* 0x22dd: je     22e6 <__native_link_local_memset_zero_dynamic+0x7d> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x22dd, 0x22e6, x86_l_22e6);
x86_l_22e3:
	/* 0x22e3: mov    BYTE PTR [rdi],r8b */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_R8, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22e6:
	/* 0x22e6: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_22e6);

x86_sim_ret_dispatch_3c1:
	switch (__x86_sim_ret_addr) {
	case 0x290ULL: goto x86_l_290;
	default: __x86_sim_unresolved_indirect_target();
	}

x86_sim_ret_dispatch_5e0:
	switch (__x86_sim_ret_addr) {
	case 0x297ULL: goto x86_l_297;
	default: __x86_sim_unresolved_indirect_target();
	}

x86_sim_ret_dispatch_659:
	switch (__x86_sim_ret_addr) {
	case 0x2dcULL: goto x86_l_2dc;
	default: __x86_sim_unresolved_indirect_target();
	}

x86_sim_ret_dispatch_6e2:
	switch (__x86_sim_ret_addr) {
	case 0x2e8ULL: goto x86_l_2e8;
	case 0x32dULL: goto x86_l_32d;
	default: __x86_sim_unresolved_indirect_target();
	}

x86_sim_ret_dispatch_723:
	switch (__x86_sim_ret_addr) {
	case 0x2efULL: goto x86_l_2ef;
	default: __x86_sim_unresolved_indirect_target();
	}

x86_sim_ret_dispatch_764:
	switch (__x86_sim_ret_addr) {
	case 0x2f6ULL: goto x86_l_2f6;
	default: __x86_sim_unresolved_indirect_target();
	}

x86_sim_ret_dispatch_77f:
	switch (__x86_sim_ret_addr) {
	case 0x301ULL: goto x86_l_301;
	default: __x86_sim_unresolved_indirect_target();
	}

x86_sim_ret_dispatch_847:
	switch (__x86_sim_ret_addr) {
	case 0x321ULL: goto x86_l_321;
	default: __x86_sim_unresolved_indirect_target();
	}

x86_sim_ret_dispatch_bdc:
	switch (__x86_sim_ret_addr) {
	case 0x692ULL: goto x86_l_692;
	case 0x7a6ULL: goto x86_l_7a6;
	case 0x825ULL: goto x86_l_825;
	default: __x86_sim_unresolved_indirect_target();
	}

x86_sim_ret_dispatch_def:
	switch (__x86_sim_ret_addr) {
	case 0x6a6ULL: goto x86_l_6a6;
	case 0x7ccULL: goto x86_l_7cc;
	case 0x858ULL: goto x86_l_858;
	default: __x86_sim_unresolved_indirect_target();
	}

x86_sim_ret_dispatch_e55:
	switch (__x86_sim_ret_addr) {
	case 0x290ULL: goto x86_l_290;
	case 0x5d5ULL: goto x86_l_5d5;
	case 0x88cULL: goto x86_l_88c;
	default: __x86_sim_unresolved_indirect_target();
	}

x86_sim_ret_dispatch_f21:
	switch (__x86_sim_ret_addr) {
	case 0x7b0ULL: goto x86_l_7b0;
	default: __x86_sim_unresolved_indirect_target();
	}

x86_sim_ret_dispatch_1063:
	switch (__x86_sim_ret_addr) {
	case 0x69cULL: goto x86_l_69c;
	case 0x7beULL: goto x86_l_7be;
	default: __x86_sim_unresolved_indirect_target();
	}

x86_sim_ret_dispatch_1a90:
	switch (__x86_sim_ret_addr) {
	case 0x6bcULL: goto x86_l_6bc;
	default: __x86_sim_unresolved_indirect_target();
	}

x86_sim_ret_dispatch_22e6:
	switch (__x86_sim_ret_addr) {
	case 0xaafULL: goto x86_l_aaf;
	case 0xb8eULL: goto x86_l_b8e;
	case 0xd9dULL: goto x86_l_d9d;
	default: __x86_sim_unresolved_indirect_target();
	}

}

X86_SIM_LICENSE();
