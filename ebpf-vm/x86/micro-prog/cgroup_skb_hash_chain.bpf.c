#define X86_VM_ENABLE_STACK 1
#include "../x86_vm_bpf.h"

SEC("xdp")
int cgroup_skb_hash_chain_x86_vm_xdp(struct xdp_md *ctx)
{
	X86_VM_DECLARE_XDP(ctx);
x86_l_1100:
	/* 0x1100: mov    rax,QWORD PTR [rdi] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1103:
	/* 0x1103: mov    rcx,QWORD PTR [rdi+0x8] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1107:
	/* 0x1107: cmp    rax,rcx */
	X86_VM_RUN_OP(x86_exec_cmp_reg, X86_OP_CMP_REG, X86_RAX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_110a:
	/* 0x110a: jbe    111e <cgroup_skb_hash_chain_prog+0x1e> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_BE))
		goto x86_l_111e;
x86_l_110c:
	/* 0x110c: mov    DWORD PTR [rdi+0x10],0xffffffff */
	X86_VM_RUN_OP(x86_exec_mov_store_imm, X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 73014444031ULL);
x86_l_1113:
	/* 0x1113: xor    eax,eax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1115:
	/* 0x1115: mov    edx,0xffffffff */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 4294967295ULL);
x86_l_111a:
	/* 0x111a: mov    DWORD PTR [rdi+0x14],edx */
	X86_VM_RUN_OP(x86_exec_mov_store_reg, X86_OP_MOV_STORE_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_111d:
	/* 0x111d: ret */
	X86_VM_RET_RAX();
x86_l_111e:
	/* 0x111e: lea    rdx,[rax+0x8] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1122:
	/* 0x1122: cmp    rdx,rcx */
	X86_VM_RUN_OP(x86_exec_cmp_reg, X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_1125:
	/* 0x1125: ja     110c <cgroup_skb_hash_chain_prog+0xc> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_110c;
x86_l_1127:
	/* 0x1127: lea    rdx,[rax+0x50] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_112b:
	/* 0x112b: cmp    rdx,rcx */
	X86_VM_RUN_OP(x86_exec_cmp_reg, X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_112e:
	/* 0x112e: ja     110c <cgroup_skb_hash_chain_prog+0xc> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_110c;
x86_l_1130:
	/* 0x1130: cmp    DWORD PTR [rax+0x8],0x10 */
	X86_VM_RUN_OP(x86_exec_cmp_mem_imm, X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738384ULL);
x86_l_1134:
	/* 0x1134: jne    110c <cgroup_skb_hash_chain_prog+0xc> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_110c;
x86_l_1136:
	/* 0x1136: cmp    DWORD PTR [rax+0xc],0x8 */
	X86_VM_RUN_OP(x86_exec_cmp_mem_imm, X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607560ULL);
x86_l_113a:
	/* 0x113a: jne    110c <cgroup_skb_hash_chain_prog+0xc> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_110c;
x86_l_113c:
	/* 0x113c: push   rbp */
	X86_VM_RUN_OP(x86_exec_push, X86_OP_PUSH, X86_REG_NONE, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_113d:
	/* 0x113d: mov    rbp,rsp */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RBP, X86_RSP, X86_WIDTH_64, 0, 0);
x86_l_1140:
	/* 0x1140: push   r15 */
	X86_VM_RUN_OP(x86_exec_push, X86_OP_PUSH, X86_REG_NONE, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_1142:
	/* 0x1142: push   r14 */
	X86_VM_RUN_OP(x86_exec_push, X86_OP_PUSH, X86_REG_NONE, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_1144:
	/* 0x1144: push   r12 */
	X86_VM_RUN_OP(x86_exec_push, X86_OP_PUSH, X86_REG_NONE, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_1146:
	/* 0x1146: push   rbx */
	X86_VM_RUN_OP(x86_exec_push, X86_OP_PUSH, X86_REG_NONE, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_1147:
	/* 0x1147: movabs rdx,0xcbf29ce484222325 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, 0, 14695981039346656037ULL);
x86_l_1151:
	/* 0x1151: mov    esi,0x7 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 7ULL);
x86_l_1156:
	/* 0x1156: movabs r8,0xd1342543de82ef95 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_64, 0, 15074714826142052245ULL);
x86_l_1160:
	/* 0x1160: xor    r9d,r9d */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_R9, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1163:
	/* 0x1163: movabs r10,0x9e3779b97f4a7c15 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_64, 0, 11400714819323198485ULL);
x86_l_116d:
	/* 0x116d: movabs r11,0x100000001b3 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_64, 0, 1099511628211ULL);
x86_l_1177:
	/* 0x1177: nop    WORD PTR [rax+rax*1+0x0] */
	X86_VM_RUN_OP(x86_exec_nop, X86_OP_NOP, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1180:
	/* 0x1180: inc    r9 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1183:
	/* 0x1183: mov    rbx,r9 */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RBX, X86_R9, X86_WIDTH_64, 0, 0);
x86_l_1186:
	/* 0x1186: imul   rbx,r10 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RBX, X86_R10, X86_WIDTH_64, X86_ALU_IMUL, 0);
x86_l_118a:
	/* 0x118a: mov    r14,r8 */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_R14, X86_R8, X86_WIDTH_64, 0, 0);
x86_l_118d:
	/* 0x118d: mov    rcx,rsi */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RCX, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_1190:
	/* 0x1190: xor    r15d,r15d */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1193:
	/* 0x1193: data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0] */
	X86_VM_RUN_OP(x86_exec_nop, X86_OP_NOP, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_11a0:
	/* 0x11a0: mov    r12,r14 */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_R12, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_11a3:
	/* 0x11a3: xor    r12,rbx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_11a6:
	/* 0x11a6: add    r12,QWORD PTR [rax+r15*8+0x10] */
	X86_VM_RUN_OP(x86_exec_alu_mem, X86_OP_ALU_MEM, X86_R12, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_R15, 3, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_11ab:
	/* 0x11ab: xor    r12,rdx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R12, X86_RDX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_11ae:
	/* 0x11ae: rol    r12,cl */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_ROL, 0);
x86_l_11b1:
	/* 0x11b1: inc    r15 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_11b4:
	/* 0x11b4: imul   r12,r11 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R12, X86_R11, X86_WIDTH_64, X86_ALU_IMUL, 0);
x86_l_11b8:
	/* 0x11b8: mov    rdx,r12 */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RDX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_11bb:
	/* 0x11bb: shr    rdx,0x1d */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 29ULL);
x86_l_11bf:
	/* 0x11bf: xor    rdx,r12 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_R12, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_11c2:
	/* 0x11c2: add    rcx,0xb */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 11ULL);
x86_l_11c6:
	/* 0x11c6: add    r14,r8 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R14, X86_R8, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_11c9:
	/* 0x11c9: cmp    r15,0x8 */
	X86_VM_RUN_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, 0, 8ULL);
x86_l_11cd:
	/* 0x11cd: jne    11a0 <cgroup_skb_hash_chain_prog+0xa0> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_11a0;
x86_l_11cf:
	/* 0x11cf: add    rsi,0x5 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 5ULL);
x86_l_11d3:
	/* 0x11d3: cmp    r9,0x10 */
	X86_VM_RUN_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_64, 0, 16ULL);
x86_l_11d7:
	/* 0x11d7: jne    1180 <cgroup_skb_hash_chain_prog+0x80> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_1180;
x86_l_11d9:
	/* 0x11d9: mov    DWORD PTR [rdi+0x10],edx */
	X86_VM_RUN_OP(x86_exec_mov_store_reg, X86_OP_MOV_STORE_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11dc:
	/* 0x11dc: shr    rdx,0x20 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_11e0:
	/* 0x11e0: mov    eax,0x1 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_11e5:
	/* 0x11e5: pop    rbx */
	X86_VM_RUN_OP(x86_exec_pop, X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_11e6:
	/* 0x11e6: pop    r12 */
	X86_VM_RUN_OP(x86_exec_pop, X86_OP_POP, X86_R12, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_11e8:
	/* 0x11e8: pop    r14 */
	X86_VM_RUN_OP(x86_exec_pop, X86_OP_POP, X86_R14, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_11ea:
	/* 0x11ea: pop    r15 */
	X86_VM_RUN_OP(x86_exec_pop, X86_OP_POP, X86_R15, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_11ec:
	/* 0x11ec: pop    rbp */
	X86_VM_RUN_OP(x86_exec_pop, X86_OP_POP, X86_RBP, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_11ed:
	/* 0x11ed: mov    DWORD PTR [rdi+0x14],edx */
	X86_VM_RUN_OP(x86_exec_mov_store_reg, X86_OP_MOV_STORE_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_11f0:
	/* 0x11f0: ret */
	X86_VM_RET_RAX();

	return XDP_ABORTED;
}

X86_VM_LICENSE();
