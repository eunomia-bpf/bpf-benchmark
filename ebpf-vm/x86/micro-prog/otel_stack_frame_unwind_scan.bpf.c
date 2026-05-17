#define X86_VM_ENABLE_RODATA 1
#define X86_VM_ENABLE_STACK 1
#include "../x86_vm_bpf.h"

SEC("xdp")
int otel_stack_frame_unwind_scan_x86_vm_xdp(struct xdp_md *ctx)
{
	X86_VM_DECLARE_XDP(ctx);
x86_l_1100:
	/* 0x1100: mov    rdx,QWORD PTR [rdi] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1103:
	/* 0x1103: mov    rcx,QWORD PTR [rdi+0x8] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1107:
	/* 0x1107: xor    eax,eax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1109:
	/* 0x1109: cmp    rdx,rcx */
	X86_VM_RUN_OP(x86_exec_cmp_reg, X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_110c:
	/* 0x110c: jbe    110f <otel_stack_frame_unwind_scan_xdp+0xf> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_BE))
		goto x86_l_110f;
x86_l_110e:
	/* 0x110e: ret */
	X86_VM_RET_RAX();
x86_l_110f:
	/* 0x110f: lea    rsi,[rdx+0x8] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_RSI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1113:
	/* 0x1113: cmp    rsi,rcx */
	X86_VM_RUN_OP(x86_exec_cmp_reg, X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_1116:
	/* 0x1116: ja     110e <otel_stack_frame_unwind_scan_xdp+0xe> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_110e;
x86_l_1118:
	/* 0x1118: lea    rsi,[rdx+0x250] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_RSI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 592ULL);
x86_l_111f:
	/* 0x111f: cmp    rsi,rcx */
	X86_VM_RUN_OP(x86_exec_cmp_reg, X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_1122:
	/* 0x1122: ja     110e <otel_stack_frame_unwind_scan_xdp+0xe> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_110e;
x86_l_1124:
	/* 0x1124: cmp    DWORD PTR [rdx+0x8],0x18 */
	X86_VM_RUN_OP(x86_exec_cmp_mem_imm, X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738392ULL);
x86_l_1128:
	/* 0x1128: jne    110e <otel_stack_frame_unwind_scan_xdp+0xe> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_110e;
x86_l_112a:
	/* 0x112a: cmp    DWORD PTR [rdx+0xc],0x18 */
	X86_VM_RUN_OP(x86_exec_cmp_mem_imm, X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607576ULL);
x86_l_112e:
	/* 0x112e: jne    110e <otel_stack_frame_unwind_scan_xdp+0xe> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_110e;
x86_l_1130:
	/* 0x1130: push   rbp */
	X86_VM_RUN_OP(x86_exec_push, X86_OP_PUSH, X86_REG_NONE, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_1131:
	/* 0x1131: push   r15 */
	X86_VM_RUN_OP(x86_exec_push, X86_OP_PUSH, X86_REG_NONE, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_1133:
	/* 0x1133: push   r14 */
	X86_VM_RUN_OP(x86_exec_push, X86_OP_PUSH, X86_REG_NONE, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_1135:
	/* 0x1135: push   r13 */
	X86_VM_RUN_OP(x86_exec_push, X86_OP_PUSH, X86_REG_NONE, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_1137:
	/* 0x1137: push   r12 */
	X86_VM_RUN_OP(x86_exec_push, X86_OP_PUSH, X86_REG_NONE, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_1139:
	/* 0x1139: push   rbx */
	X86_VM_RUN_OP(x86_exec_push, X86_OP_PUSH, X86_REG_NONE, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_113a:
	/* 0x113a: lea    rsi,[rdx+0x27] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_RSI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 39ULL);
x86_l_113e:
	/* 0x113e: movabs rdi,0x100000000 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, 4294967296ULL);
x86_l_1148:
	/* 0x1148: movabs r11,0x589965cc75374cc3 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_64, 0, 6384245875588680899ULL);
x86_l_1152:
	/* 0x1152: xor    r8d,r8d */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1155:
	/* 0x1155: jmp    117b <otel_stack_frame_unwind_scan_xdp+0x7b> */
	goto x86_l_117b;
x86_l_1157:
	/* 0x1157: nop    WORD PTR [rax+rax*1+0x0] */
	X86_VM_RUN_OP(x86_exec_nop, X86_OP_NOP, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1160:
	/* 0x1160: shl    r14,0x30 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 48ULL);
x86_l_1164:
	/* 0x1164: or     r14,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_1167:
	/* 0x1167: xor    r11,r14 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R11, X86_R14, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_116a:
	/* 0x116a: inc    r8 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_116d:
	/* 0x116d: add    rsi,0x18 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1171:
	/* 0x1171: cmp    r8,0x18 */
	X86_VM_RUN_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_64, 0, 24ULL);
x86_l_1175:
	/* 0x1175: je     1241 <otel_stack_frame_unwind_scan_xdp+0x141> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_E))
		goto x86_l_1241;
x86_l_117b:
	/* 0x117b: mov    rax,QWORD PTR [rsi-0x17] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551593ULL);
x86_l_117f:
	/* 0x117f: movzx  ecx,BYTE PTR [rsi-0x5] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551611ULL);
x86_l_1183:
	/* 0x1183: movzx  r14d,BYTE PTR [rsi-0x4] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R14, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551612ULL);
x86_l_1188:
	/* 0x1188: shl    r14d,0x8 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 8ULL);
x86_l_118c:
	/* 0x118c: or     r14,rcx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_118f:
	/* 0x118f: cmp    r14w,0x3 */
	X86_VM_RUN_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, 0, 3ULL);
x86_l_1194:
	/* 0x1194: ja     1160 <otel_stack_frame_unwind_scan_xdp+0x60> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_1160;
x86_l_1196:
	/* 0x1196: mov    r15d,DWORD PTR [rsi-0xf] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R15, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551601ULL);
x86_l_119a:
	/* 0x119a: cmp    r15d,0x1000 */
	X86_VM_RUN_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 4096ULL);
x86_l_11a1:
	/* 0x11a1: ja     1160 <otel_stack_frame_unwind_scan_xdp+0x60> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_1160;
x86_l_11a3:
	/* 0x11a3: mov    r12d,DWORD PTR [rsi-0xb] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R12, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551605ULL);
x86_l_11a7:
	/* 0x11a7: cmp    r12d,0x2001 */
	X86_VM_RUN_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 8193ULL);
x86_l_11ae:
	/* 0x11ae: jae    1160 <otel_stack_frame_unwind_scan_xdp+0x60> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_AE))
		goto x86_l_1160;
x86_l_11b0:
	/* 0x11b0: movzx  ebp,WORD PTR [rsi-0x7] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18446744073709551609ULL);
x86_l_11b4:
	/* 0x11b4: mov    r9d,DWORD PTR [rsi-0x3] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R9, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_11b8:
	/* 0x11b8: movzx  r14d,r14w */
	X86_VM_RUN_OP(x86_exec_movzx_reg, X86_OP_MOVZX_REG, X86_R14, X86_R14, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_11bc:
	/* 0x11bc: test   bpl,0x1 */
	X86_VM_RUN_OP(x86_exec_test_imm, X86_OP_TEST_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_11c0:
	/* 0x11c0: mov    r13d,r12d */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_R13, X86_R12, X86_WIDTH_32, 0, 0);
x86_l_11c3:
	/* 0x11c3: mov    r10d,0x8 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_11c9:
	/* 0x11c9: cmove  r13d,r10d */
	X86_VM_RUN_OP(x86_exec_cmov, X86_OP_CMOV, X86_R13, X86_R10, X86_WIDTH_32, X86_CC_E, 0);
x86_l_11cd:
	/* 0x11cd: mov    rbx,r9 */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RBX, X86_R9, X86_WIDTH_64, 0, 0);
x86_l_11d0:
	/* 0x11d0: shl    rbx,0x20 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_11d4:
	/* 0x11d4: lea    r10,[rip+0xe25] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_R10, X86_REG_NONE, X86_WIDTH_64, X86_PTR_RODATA, 3621ULL);
x86_l_11db:
	/* 0x11db: or     rbx,QWORD PTR [r10+r14*8] */
	X86_VM_RUN_OP(x86_exec_alu_mem, X86_OP_ALU_MEM, X86_RBX, X86_R10, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_R14, 3, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 0ULL);
x86_l_11df:
	/* 0x11df: add    r13d,r15d */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R13, X86_R15, X86_WIDTH_32, X86_ALU_ADD, 0);
x86_l_11e2:
	/* 0x11e2: add    rdi,r13 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_11e5:
	/* 0x11e5: xor    rax,rdi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RDI, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_11e8:
	/* 0x11e8: xor    rax,rbx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RBX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_11eb:
	/* 0x11eb: test   bpl,0x2 */
	X86_VM_RUN_OP(x86_exec_test_imm, X86_OP_TEST_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, 0, 2ULL);
x86_l_11ef:
	/* 0x11ef: je     11f6 <otel_stack_frame_unwind_scan_xdp+0xf6> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_E))
		goto x86_l_11f6;
x86_l_11f1:
	/* 0x11f1: inc    ecx */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_11f3:
	/* 0x11f3: rol    rax,cl */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ROL, 0);
x86_l_11f6:
	/* 0x11f6: mov    ecx,r12d */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RCX, X86_R12, X86_WIDTH_32, 0, 0);
x86_l_11f9:
	/* 0x11f9: shl    rcx,0x18 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 24ULL);
x86_l_11fd:
	/* 0x11fd: mov    ebx,r15d */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RBX, X86_R15, X86_WIDTH_32, 0, 0);
x86_l_1200:
	/* 0x1200: xor    rbx,rcx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1203:
	/* 0x1203: test   bpl,0x4 */
	X86_VM_RUN_OP(x86_exec_test_imm, X86_OP_TEST_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, 0, 4ULL);
x86_l_1207:
	/* 0x1207: mov    r14d,0x0 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, 0, 0ULL);
x86_l_120d:
	/* 0x120d: cmovne r14,rbx */
	X86_VM_RUN_OP(x86_exec_cmov, X86_OP_CMOV, X86_R14, X86_RBX, X86_WIDTH_64, X86_CC_NE, 0);
x86_l_1211:
	/* 0x1211: add    r14,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1214:
	/* 0x1214: mov    eax,r8d */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RAX, X86_R8, X86_WIDTH_32, 0, 0);
x86_l_1217:
	/* 0x1217: and    al,0x7 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_ALU_AND, 7ULL);
x86_l_1219:
	/* 0x1219: lea    ecx,[rax+0x1] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_121c:
	/* 0x121c: mov    rbx,r14 */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RBX, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_121f:
	/* 0x121f: shl    rbx,cl */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 0);
x86_l_1222:
	/* 0x1222: not    al */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_ALU_NOT, 0);
x86_l_1224:
	/* 0x1224: mov    ecx,eax */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_1226:
	/* 0x1226: shr    r14,cl */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 0);
x86_l_1229:
	/* 0x1229: or     r14,rbx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R14, X86_RBX, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_122c:
	/* 0x122c: add    r14,r11 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R14, X86_R11, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_122f:
	/* 0x122f: movzx  eax,bp */
	X86_VM_RUN_OP(x86_exec_movzx_reg, X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_1232:
	/* 0x1232: shl    rax,0x28 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 40ULL);
x86_l_1236:
	/* 0x1236: or     r9,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_RAX, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_1239:
	/* 0x1239: mov    r11,r9 */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_R11, X86_R9, X86_WIDTH_64, 0, 0);
x86_l_123c:
	/* 0x123c: jmp    1167 <otel_stack_frame_unwind_scan_xdp+0x67> */
	goto x86_l_1167;
x86_l_1241:
	/* 0x1241: mov    QWORD PTR [rdx],r11 */
	X86_VM_RUN_OP(x86_exec_mov_store_reg, X86_OP_MOV_STORE_REG, X86_RDX, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1244:
	/* 0x1244: mov    eax,0x2 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_1249:
	/* 0x1249: pop    rbx */
	X86_VM_RUN_OP(x86_exec_pop, X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_124a:
	/* 0x124a: pop    r12 */
	X86_VM_RUN_OP(x86_exec_pop, X86_OP_POP, X86_R12, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_124c:
	/* 0x124c: pop    r13 */
	X86_VM_RUN_OP(x86_exec_pop, X86_OP_POP, X86_R13, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_124e:
	/* 0x124e: pop    r14 */
	X86_VM_RUN_OP(x86_exec_pop, X86_OP_POP, X86_R14, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1250:
	/* 0x1250: pop    r15 */
	X86_VM_RUN_OP(x86_exec_pop, X86_OP_POP, X86_R15, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1252:
	/* 0x1252: pop    rbp */
	X86_VM_RUN_OP(x86_exec_pop, X86_OP_POP, X86_RBP, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1253:
	/* 0x1253: ret */
	X86_VM_RET_RAX();
	return XDP_ABORTED;
}

X86_VM_LICENSE();
