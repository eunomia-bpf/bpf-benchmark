#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_STACK_BYTES 48U
#define X86_SIM_STACK_VALUE_WORDS(M) M(0) M(1) M(2) M(3) M(4) M(5)
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

#include "/workspaces/repository/kprog/x86/x86_sim_inline.h"

X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_ALU_IMM, X86_OP_ALU_IMM)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_ALU_REG, X86_OP_ALU_REG)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_CALL_HELPER, X86_OP_CALL_HELPER)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_LEA, X86_OP_LEA)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_MOV_LOAD, X86_OP_MOV_LOAD)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_MOV_REG, X86_OP_MOV_REG)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_MOV_STORE_REG, X86_OP_MOV_STORE_REG)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_POP, X86_OP_POP)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_PUSH, X86_OP_PUSH)

SEC("socket")
int x86_program_profile_x86_sim_xdp(void *ctx)
{
	X86_SIM_ENTRY_RAW(ctx);
	X86_SIM_BIND_INLINE();
x86_l_0:
	/* 0x0: push   rbx */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_1:
	/* 0x1: sub    rsp,0x20 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SUB, 32ULL);
x86_l_5:
	/* 0x5: lea    rbx,[rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a:
	/* 0xa: call   34 <x86_program_inner> */
	X86_SIM_X86_CALL(x86_l_34, 0xfULL);
x86_l_f:
	/* 0xf: mov    QWORD PTR [rsp],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13:
	/* 0x13: call   3a <x86_program_tail> */
	X86_SIM_X86_CALL(x86_l_3a, 0x18ULL);
x86_l_18:
	/* 0x18: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c:
	/* 0x1c: xor    rax,rcx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1f:
	/* 0x1f: mov    rcx,rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_22:
	/* 0x22: xor    rax,rcx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_25:
	/* 0x25: mov    rcx,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_28:
	/* 0x28: shr    rcx,0x20 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_2c:
	/* 0x2c: xor    eax,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_2e:
	/* 0x2e: add    rsp,0x20 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_32:
	/* 0x32: pop    rbx */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_33:
	/* 0x33: ret */
	X86_SIM_X86_RET();
x86_l_3f:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
	/* native subroutine native_link_sub_34 */
x86_l_34:
	/* 0x34: call   39 <x86_program_inner+0x5> */
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_ktime_get_ns);
x86_l_39:
	/* 0x39: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);

	/* native subroutine native_link_sub_3a */
x86_l_3a:
	X86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_ktime_get_ns);
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);

x86_sim_ret_dispatch:
	switch (__x86_sim_ret_addr) {
	case 0xfULL: goto x86_l_f;
	case 0x18ULL: goto x86_l_18;
	default: __x86_sim_unresolved_indirect_target();
	}

}

X86_SIM_LICENSE();
