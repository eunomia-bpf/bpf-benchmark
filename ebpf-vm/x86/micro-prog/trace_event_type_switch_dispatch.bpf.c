#define X86_VM_ENABLE_RODATA 1
#include "../x86_vm_bpf.h"

SEC("xdp")
int trace_event_type_switch_dispatch_x86_vm_xdp(struct xdp_md *ctx)
{
	X86_VM_DECLARE_XDP(ctx);
x86_l_1100:
	/* 0x1100: mov    rcx,QWORD PTR [rdi] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1103:
	/* 0x1103: mov    rdx,QWORD PTR [rdi+0x8] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1107:
	/* 0x1107: xor    eax,eax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1109:
	/* 0x1109: cmp    rcx,rdx */
	X86_VM_RUN_OP(x86_exec_cmp_reg, X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_110c:
	/* 0x110c: jbe    110f <trace_event_type_switch_dispatch_xdp+0xf> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_BE))
		goto x86_l_110f;
x86_l_110e:
	/* 0x110e: ret */
	X86_VM_RET_RAX();
x86_l_110f:
	/* 0x110f: lea    rsi,[rcx+0x8] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1113:
	/* 0x1113: cmp    rsi,rdx */
	X86_VM_RUN_OP(x86_exec_cmp_reg, X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_1116:
	/* 0x1116: ja     110e <trace_event_type_switch_dispatch_xdp+0xe> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_110e;
x86_l_1118:
	/* 0x1118: lea    rdi,[rcx+0x20c] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 524ULL);
x86_l_111f:
	/* 0x111f: cmp    rdi,rdx */
	X86_VM_RUN_OP(x86_exec_cmp_reg, X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_1122:
	/* 0x1122: ja     110e <trace_event_type_switch_dispatch_xdp+0xe> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_110e;
x86_l_1124:
	/* 0x1124: cmp    DWORD PTR [rsi],0x80 */
	X86_VM_RUN_OP(x86_exec_cmp_mem_imm, X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_112a:
	/* 0x112a: jne    110e <trace_event_type_switch_dispatch_xdp+0xe> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_110e;
x86_l_112c:
	/* 0x112c: mov    esi,0xf */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 15ULL);
x86_l_1131:
	/* 0x1131: xor    edx,edx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1133:
	/* 0x1133: lea    rdi,[rip+0xec6] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_PTR_RODATA, 3782ULL);
x86_l_113a:
	/* 0x113a: jmp    1150 <trace_event_type_switch_dispatch_xdp+0x50> */
	goto x86_l_1150;
x86_l_113c:
	/* 0x113c: nop    DWORD PTR [rax+0x0] */
	X86_VM_RUN_OP(x86_exec_nop, X86_OP_NOP, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1140:
	/* 0x1140: xor    rdx,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1143:
	/* 0x1143: add    rsi,0x4 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1147:
	/* 0x1147: cmp    rsi,0x20f */
	X86_VM_RUN_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, 0, 527ULL);
x86_l_114e:
	/* 0x114e: je     116c <trace_event_type_switch_dispatch_xdp+0x6c> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_E))
		goto x86_l_116c;
x86_l_1150:
	/* 0x1150: mov    rax,rdx */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RAX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_1153:
	/* 0x1153: mov    r8d,DWORD PTR [rcx+rsi*1-0x3] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R8, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 0), 18446744073709551613ULL);
x86_l_1158:
	/* 0x1158: mov    edx,0x1bf52 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 114514ULL);
x86_l_115d:
	/* 0x115d: cmp    r8d,0x3f */
	X86_VM_RUN_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, 0, 63ULL);
x86_l_1161:
	/* 0x1161: ja     1140 <trace_event_type_switch_dispatch_xdp+0x40> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_1140;
x86_l_1163:
	/* 0x1163: mov    edx,r8d */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RDX, X86_R8, X86_WIDTH_32, 0, 0);
x86_l_1166:
	/* 0x1166: mov    rdx,QWORD PTR [rdi+rdx*8] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 3), 0ULL);
x86_l_116a:
	/* 0x116a: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> */
	goto x86_l_1140;
x86_l_116c:
	/* 0x116c: mov    BYTE PTR [rcx],dl */
	X86_VM_RUN_OP(x86_exec_mov_store_reg, X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_116e:
	/* 0x116e: mov    BYTE PTR [rcx+0x1],dh */
	X86_VM_RUN_OP(x86_exec_mov_store_reg, X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_REG_AUX_SRC_SHIFT(8)), 1ULL);
x86_l_1171:
	/* 0x1171: shr    edx,0x10 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1174:
	/* 0x1174: mov    BYTE PTR [rcx+0x2],dl */
	X86_VM_RUN_OP(x86_exec_mov_store_reg, X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_1177:
	/* 0x1177: mov    edx,eax */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RDX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_1179:
	/* 0x1179: shr    edx,0x18 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHR, 24ULL);
x86_l_117c:
	/* 0x117c: mov    BYTE PTR [rcx+0x3],dl */
	X86_VM_RUN_OP(x86_exec_mov_store_reg, X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 3ULL);
x86_l_117f:
	/* 0x117f: mov    rdx,rax */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RDX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_1182:
	/* 0x1182: shr    rdx,0x20 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_1186:
	/* 0x1186: mov    BYTE PTR [rcx+0x4],dl */
	X86_VM_RUN_OP(x86_exec_mov_store_reg, X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1189:
	/* 0x1189: mov    rdx,rax */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RDX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_118c:
	/* 0x118c: shr    rdx,0x28 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 40ULL);
x86_l_1190:
	/* 0x1190: mov    BYTE PTR [rcx+0x5],dl */
	X86_VM_RUN_OP(x86_exec_mov_store_reg, X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_1193:
	/* 0x1193: mov    rdx,rax */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RDX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_1196:
	/* 0x1196: shr    rdx,0x30 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 48ULL);
x86_l_119a:
	/* 0x119a: mov    BYTE PTR [rcx+0x6],dl */
	X86_VM_RUN_OP(x86_exec_mov_store_reg, X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_119d:
	/* 0x119d: shr    rax,0x38 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 56ULL);
x86_l_11a1:
	/* 0x11a1: mov    BYTE PTR [rcx+0x7],al */
	X86_VM_RUN_OP(x86_exec_mov_store_reg, X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 7ULL);
x86_l_11a4:
	/* 0x11a4: mov    eax,0x2 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_11a9:
	/* 0x11a9: ret */
	X86_VM_RET_RAX();
	return XDP_ABORTED;
}

X86_VM_LICENSE();
