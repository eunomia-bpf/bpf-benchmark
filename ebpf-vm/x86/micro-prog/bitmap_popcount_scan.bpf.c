#define X86_VM_ENABLE_STACK 1
#include "../x86_vm_bpf.h"

SEC("xdp")
int bitmap_popcount_scan_x86_vm_xdp(struct xdp_md *ctx)
{
	X86_VM_DECLARE_XDP(ctx);
x86_l_1100:
	/* 0x1100: mov    rdx,QWORD PTR [rdi] */
	X86_VM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1103:
	/* 0x1103: mov    rcx,QWORD PTR [rdi+0x8] */
	X86_VM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1107:
	/* 0x1107: xor    eax,eax */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1109:
	/* 0x1109: cmp    rdx,rcx */
	X86_VM_RUN_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_110c:
	/* 0x110c: jbe    110f <bitmap_popcount_scan_xdp+0xf> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_BE))
		goto x86_l_110f;
x86_l_110e:
	/* 0x110e: ret */
	X86_VM_RET_RAX();
x86_l_110f:
	/* 0x110f: lea    rsi,[rdx+0x8] */
	X86_VM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1113:
	/* 0x1113: cmp    rsi,rcx */
	X86_VM_RUN_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_1116:
	/* 0x1116: ja     110e <bitmap_popcount_scan_xdp+0xe> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_110e;
x86_l_1118:
	/* 0x1118: lea    rdi,[rdx+0x810] */
	X86_VM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2064ULL);
x86_l_111f:
	/* 0x111f: cmp    rdi,rcx */
	X86_VM_RUN_OP(X86_OP_CMP_REG, X86_RDI, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_1122:
	/* 0x1122: ja     110e <bitmap_popcount_scan_xdp+0xe> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_110e;
x86_l_1124:
	/* 0x1124: cmp    DWORD PTR [rsi],0x100 */
	X86_VM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_112a:
	/* 0x112a: jne    110e <bitmap_popcount_scan_xdp+0xe> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_110e;
x86_l_112c:
	/* 0x112c: push   rbp */
	X86_VM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_112d:
	/* 0x112d: mov    rbp,rsp */
	X86_VM_RUN_OP(X86_OP_MOV_REG, X86_RBP, X86_RSP, X86_WIDTH_64, 0, 0);
x86_l_1130:
	/* 0x1130: mov    ecx,DWORD PTR [rdx+0xc] */
	X86_VM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1133:
	/* 0x1133: xor    eax,eax */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1135:
	/* 0x1135: data16 cs nop WORD PTR [rax+rax*1+0x0] */
	X86_VM_RUN_OP(X86_OP_NOP, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1140:
	/* 0x1140: mov    rsi,QWORD PTR [rdx+rax*8+0x10] */
	X86_VM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 16ULL);
x86_l_1145:
	/* 0x1145: mov    rdi,rsi */
	X86_VM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_1148:
	/* 0x1148: xor    rdi,rcx */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_114b:
	/* 0x114b: popcnt rdi,rdi */
	X86_VM_RUN_OP(X86_OP_POPCNT, X86_RDI, X86_RDI, X86_WIDTH_64, 0, 0);
x86_l_1150:
	/* 0x1150: add    rdi,rcx */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1153:
	/* 0x1153: mov    ecx,eax */
	X86_VM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_1155:
	/* 0x1155: and    cl,0x7 */
	X86_VM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_ALU_AND, 7ULL);
x86_l_1158:
	/* 0x1158: shr    rsi,cl */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 0);
x86_l_115b:
	/* 0x115b: mov    rcx,rsi */
	X86_VM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_115e:
	/* 0x115e: xor    rcx,rdi */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RDI, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1161:
	/* 0x1161: inc    rax */
	X86_VM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1164:
	/* 0x1164: cmp    rax,0x100 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, 0, 256ULL);
x86_l_116a:
	/* 0x116a: jne    1140 <bitmap_popcount_scan_xdp+0x40> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_1140;
x86_l_116c:
	/* 0x116c: mov    QWORD PTR [rdx],rcx */
	X86_VM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_116f:
	/* 0x116f: mov    eax,0x2 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_1174:
	/* 0x1174: pop    rbp */
	X86_VM_RUN_OP(X86_OP_POP, X86_RBP, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1175:
	/* 0x1175: ret */
	X86_VM_RET_RAX();

	return XDP_ABORTED;
}

X86_VM_LICENSE();
