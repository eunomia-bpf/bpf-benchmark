#include "../x86_vm_bpf.h"

SEC("xdp")
int sorted_rule_binary_search_x86_vm_xdp(struct xdp_md *ctx)
{
	X86_VM_DECLARE_XDP(ctx);
x86_l_1100:
	/* 0x1100: mov    rcx,QWORD PTR [rdi] */
	X86_VM_RUN_STEP(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1103:
	/* 0x1103: mov    rdx,QWORD PTR [rdi+0x8] */
	X86_VM_RUN_STEP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1107:
	/* 0x1107: xor    eax,eax */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1109:
	/* 0x1109: cmp    rcx,rdx */
	X86_VM_RUN_STEP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_110c:
	/* 0x110c: jbe    110f <sorted_rule_binary_search_xdp+0xf> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_BE))
		goto x86_l_110f;
x86_l_110e:
	/* 0x110e: ret */
	X86_VM_RET_RAX();
x86_l_110f:
	/* 0x110f: lea    rsi,[rcx+0x8] */
	X86_VM_RUN_STEP(X86_OP_LEA, X86_RSI, X86_RCX, X86_WIDTH_64, 0, 8ULL);
x86_l_1113:
	/* 0x1113: cmp    rsi,rdx */
	X86_VM_RUN_STEP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_1116:
	/* 0x1116: ja     110e <sorted_rule_binary_search_xdp+0xe> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_110e;
x86_l_1118:
	/* 0x1118: lea    rsi,[rcx+0x190] */
	X86_VM_RUN_STEP(X86_OP_LEA, X86_RSI, X86_RCX, X86_WIDTH_64, 0, 400ULL);
x86_l_111f:
	/* 0x111f: cmp    rsi,rdx */
	X86_VM_RUN_STEP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_1122:
	/* 0x1122: ja     110e <sorted_rule_binary_search_xdp+0xe> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_110e;
x86_l_1124:
	/* 0x1124: cmp    DWORD PTR [rcx+0x8],0x20 */
	X86_VM_RUN_STEP(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738400ULL);
x86_l_1128:
	/* 0x1128: jne    110e <sorted_rule_binary_search_xdp+0xe> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_110e;
x86_l_112a:
	/* 0x112a: cmp    DWORD PTR [rcx+0xc],0x10 */
	X86_VM_RUN_STEP(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607568ULL);
x86_l_112e:
	/* 0x112e: jne    110e <sorted_rule_binary_search_xdp+0xe> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_110e;
x86_l_1130:
	/* 0x1130: xor    eax,eax */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1132:
	/* 0x1132: xor    edx,edx */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1134:
	/* 0x1134: data16 data16 cs nop WORD PTR [rax+rax*1+0x0] */
	X86_VM_RUN_STEP(X86_OP_NOP, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1140:
	/* 0x1140: mov    rsi,QWORD PTR [rcx+rax*8+0x110] */
	X86_VM_RUN_STEP(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 272ULL);
x86_l_1148:
	/* 0x1148: xor    r8d,r8d */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_114b:
	/* 0x114b: xor    edi,edi */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_114d:
	/* 0x114d: xor    r9d,r9d */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_R9, X86_R9, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1150:
	/* 0x1150: mov    r10d,r9d */
	X86_VM_RUN_STEP(X86_OP_MOV_REG, X86_R10, X86_R9, X86_WIDTH_32, 0, 0);
x86_l_1153:
	/* 0x1153: mov    r11,rdi */
	X86_VM_RUN_STEP(X86_OP_MOV_REG, X86_R11, X86_RDI, X86_WIDTH_64, 0, 0);
x86_l_1156:
	/* 0x1156: cmp    QWORD PTR [rcx+r8*8+0x10],rsi */
	X86_VM_RUN_STEP(X86_OP_CMP_MEM_REG, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_R8, 3), 16ULL);
x86_l_115b:
	/* 0x115b: sete   r9b */
	X86_VM_RUN_STEP(X86_OP_SETCC, X86_R9, X86_REG_NONE, X86_WIDTH_8, X86_CC_E, 0);
x86_l_115f:
	/* 0x115f: cmove  rdi,r8 */
	X86_VM_RUN_STEP(X86_OP_CMOV, X86_RDI, X86_R8, X86_WIDTH_64, X86_CC_E, 0);
x86_l_1163:
	/* 0x1163: or     r9b,r10b */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_R9, X86_R10, X86_WIDTH_8, X86_ALU_OR, 0);
x86_l_1166:
	/* 0x1166: test   r10b,0x1 */
	X86_VM_RUN_STEP(X86_OP_TEST_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_116a:
	/* 0x116a: cmovne rdi,r11 */
	X86_VM_RUN_STEP(X86_OP_CMOV, X86_RDI, X86_R11, X86_WIDTH_64, X86_CC_NE, 0);
x86_l_116e:
	/* 0x116e: inc    r8 */
	X86_VM_RUN_STEP(X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1171:
	/* 0x1171: cmp    r8,0x20 */
	X86_VM_RUN_STEP(X86_OP_CMP_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_64, 0, 32ULL);
x86_l_1175:
	/* 0x1175: jne    1150 <sorted_rule_binary_search_xdp+0x50> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_1150;
x86_l_1177:
	/* 0x1177: add    rdi,rdx */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_RDI, X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_117a:
	/* 0x117a: add    rsi,0x20 */
	X86_VM_RUN_STEP(X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_117e:
	/* 0x117e: xor    rdx,rsi */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1181:
	/* 0x1181: test   r9b,0x1 */
	X86_VM_RUN_STEP(X86_OP_TEST_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_1185:
	/* 0x1185: cmovne rdx,rdi */
	X86_VM_RUN_STEP(X86_OP_CMOV, X86_RDX, X86_RDI, X86_WIDTH_64, X86_CC_NE, 0);
x86_l_1189:
	/* 0x1189: inc    rax */
	X86_VM_RUN_STEP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_118c:
	/* 0x118c: cmp    rax,0x10 */
	X86_VM_RUN_STEP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, 0, 16ULL);
x86_l_1190:
	/* 0x1190: jne    1140 <sorted_rule_binary_search_xdp+0x40> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_1140;
x86_l_1192:
	/* 0x1192: mov    QWORD PTR [rcx],rdx */
	X86_VM_RUN_STEP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1195:
	/* 0x1195: mov    eax,0x2 */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_119a:
	/* 0x119a: ret */
	X86_VM_RET_RAX();
	return XDP_ABORTED;
}

X86_VM_LICENSE();
