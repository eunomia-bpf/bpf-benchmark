#define X86_VM_ENABLE_STACK 1
#include "../x86_vm_bpf.h"

SEC("xdp")
int otel_stack_frame_unwind_scan_x86_vm_xdp(struct xdp_md *ctx)
{
	X86_VM_DECLARE_XDP(ctx);
x86_l_1100:
	/* 0x1100: mov    rsi,QWORD PTR [rdi] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1103:
	/* 0x1103: mov    rcx,QWORD PTR [rdi+0x8] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1107:
	/* 0x1107: xor    eax,eax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1109:
	/* 0x1109: cmp    rsi,rcx */
	X86_VM_RUN_OP(x86_exec_cmp_reg, X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_110c:
	/* 0x110c: jbe    110f <otel_stack_frame_unwind_scan_xdp+0xf> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_BE))
		goto x86_l_110f;
x86_l_110e:
	/* 0x110e: ret */
	X86_VM_RET_RAX();
x86_l_110f:
	/* 0x110f: lea    rdx,[rsi+0x8] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1113:
	/* 0x1113: cmp    rdx,rcx */
	X86_VM_RUN_OP(x86_exec_cmp_reg, X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_1116:
	/* 0x1116: ja     110e <otel_stack_frame_unwind_scan_xdp+0xe> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_110e;
x86_l_1118:
	/* 0x1118: lea    rdx,[rsi+0x250] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 592ULL);
x86_l_111f:
	/* 0x111f: cmp    rdx,rcx */
	X86_VM_RUN_OP(x86_exec_cmp_reg, X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_1122:
	/* 0x1122: ja     110e <otel_stack_frame_unwind_scan_xdp+0xe> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_110e;
x86_l_1124:
	/* 0x1124: cmp    DWORD PTR [rsi+0x8],0x18 */
	X86_VM_RUN_OP(x86_exec_cmp_mem_imm, X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738392ULL);
x86_l_1128:
	/* 0x1128: jne    110e <otel_stack_frame_unwind_scan_xdp+0xe> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_110e;
x86_l_112a:
	/* 0x112a: cmp    DWORD PTR [rsi+0xc],0x18 */
	X86_VM_RUN_OP(x86_exec_cmp_mem_imm, X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607576ULL);
x86_l_112e:
	/* 0x112e: jne    110e <otel_stack_frame_unwind_scan_xdp+0xe> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_110e;
x86_l_1130:
	/* 0x1130: push   rbp */
	X86_VM_RUN_OP(x86_exec_push, X86_OP_PUSH, X86_REG_NONE, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_1131:
	/* 0x1131: mov    rbp,rsp */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RBP, X86_RSP, X86_WIDTH_64, 0, 0);
x86_l_1134:
	/* 0x1134: push   r15 */
	X86_VM_RUN_OP(x86_exec_push, X86_OP_PUSH, X86_REG_NONE, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_1136:
	/* 0x1136: push   r14 */
	X86_VM_RUN_OP(x86_exec_push, X86_OP_PUSH, X86_REG_NONE, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_1138:
	/* 0x1138: push   r13 */
	X86_VM_RUN_OP(x86_exec_push, X86_OP_PUSH, X86_REG_NONE, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_113a:
	/* 0x113a: push   r12 */
	X86_VM_RUN_OP(x86_exec_push, X86_OP_PUSH, X86_REG_NONE, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_113c:
	/* 0x113c: push   rbx */
	X86_VM_RUN_OP(x86_exec_push, X86_OP_PUSH, X86_REG_NONE, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_113d:
	/* 0x113d: lea    rdi,[rsi+0x27] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 39ULL);
x86_l_1141:
	/* 0x1141: movabs r8,0x100000000 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_64, 0, 4294967296ULL);
x86_l_114b:
	/* 0x114b: movabs r11,0x589965cc75374cc3 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_64, 0, 6384245875588680899ULL);
x86_l_1155:
	/* 0x1155: xor    r9d,r9d */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_R9, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1158:
	/* 0x1158: mov    r10d,0x8 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_115e:
	/* 0x115e: jmp    117b <otel_stack_frame_unwind_scan_xdp+0x7b> */
	goto x86_l_117b;
x86_l_1160:
	/* 0x1160: shl    rax,0x30 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 48ULL);
x86_l_1164:
	/* 0x1164: or     rax,rdx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_1167:
	/* 0x1167: xor    r11,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R11, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_116a:
	/* 0x116a: inc    r9 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_116d:
	/* 0x116d: add    rdi,0x18 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1171:
	/* 0x1171: cmp    r9,0x18 */
	X86_VM_RUN_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_64, 0, 24ULL);
x86_l_1175:
	/* 0x1175: je     1286 <otel_stack_frame_unwind_scan_xdp+0x186> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_E))
		goto x86_l_1286;
x86_l_117b:
	/* 0x117b: mov    rdx,QWORD PTR [rdi-0x17] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551593ULL);
x86_l_117f:
	/* 0x117f: mov    r15d,DWORD PTR [rdi-0xf] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R15, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551601ULL);
x86_l_1183:
	/* 0x1183: mov    r12d,DWORD PTR [rdi-0xb] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R12, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551605ULL);
x86_l_1187:
	/* 0x1187: movzx  r14d,WORD PTR [rdi-0x7] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R14, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18446744073709551609ULL);
x86_l_118c:
	/* 0x118c: movzx  eax,WORD PTR [rdi-0x5] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18446744073709551611ULL);
x86_l_1190:
	/* 0x1190: mov    ebx,DWORD PTR [rdi-0x3] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RBX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_1193:
	/* 0x1193: cmp    eax,0x1 */
	X86_VM_RUN_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_1196:
	/* 0x1196: jg     11c0 <otel_stack_frame_unwind_scan_xdp+0xc0> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_G))
		goto x86_l_11c0;
x86_l_1198:
	/* 0x1198: test   eax,eax */
	X86_VM_RUN_OP(x86_exec_test_reg, X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_119a:
	/* 0x119a: je     11da <otel_stack_frame_unwind_scan_xdp+0xda> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_E))
		goto x86_l_11da;
x86_l_119c:
	/* 0x119c: cmp    eax,0x1 */
	X86_VM_RUN_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_119f:
	/* 0x119f: jne    1160 <otel_stack_frame_unwind_scan_xdp+0x60> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_1160;
x86_l_11a1:
	/* 0x11a1: mov    ecx,0x35 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 53ULL);
x86_l_11a6:
	/* 0x11a6: cmp    r15d,0x1000 */
	X86_VM_RUN_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 4096ULL);
x86_l_11ad:
	/* 0x11ad: jbe    11ff <otel_stack_frame_unwind_scan_xdp+0xff> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_BE))
		goto x86_l_11ff;
x86_l_11af:
	/* 0x11af: jmp    1160 <otel_stack_frame_unwind_scan_xdp+0x60> */
	goto x86_l_1160;
x86_l_11b1:
	/* 0x11b1: data16 data16 data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0] */
	X86_VM_RUN_OP(x86_exec_nop, X86_OP_NOP, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_11c0:
	/* 0x11c0: cmp    eax,0x2 */
	X86_VM_RUN_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_11c3:
	/* 0x11c3: je     11ed <otel_stack_frame_unwind_scan_xdp+0xed> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_E))
		goto x86_l_11ed;
x86_l_11c5:
	/* 0x11c5: cmp    eax,0x3 */
	X86_VM_RUN_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 3ULL);
x86_l_11c8:
	/* 0x11c8: jne    1160 <otel_stack_frame_unwind_scan_xdp+0x60> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_1160;
x86_l_11ca:
	/* 0x11ca: mov    ecx,0x89 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 137ULL);
x86_l_11cf:
	/* 0x11cf: cmp    r15d,0x1000 */
	X86_VM_RUN_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 4096ULL);
x86_l_11d6:
	/* 0x11d6: jbe    11ff <otel_stack_frame_unwind_scan_xdp+0xff> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_BE))
		goto x86_l_11ff;
x86_l_11d8:
	/* 0x11d8: jmp    1160 <otel_stack_frame_unwind_scan_xdp+0x60> */
	goto x86_l_1160;
x86_l_11da:
	/* 0x11da: mov    ecx,0x21 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 33ULL);
x86_l_11df:
	/* 0x11df: cmp    r15d,0x1000 */
	X86_VM_RUN_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 4096ULL);
x86_l_11e6:
	/* 0x11e6: jbe    11ff <otel_stack_frame_unwind_scan_xdp+0xff> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_BE))
		goto x86_l_11ff;
x86_l_11e8:
	/* 0x11e8: jmp    1160 <otel_stack_frame_unwind_scan_xdp+0x60> */
	goto x86_l_1160;
x86_l_11ed:
	/* 0x11ed: mov    ecx,0x55 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 85ULL);
x86_l_11f2:
	/* 0x11f2: cmp    r15d,0x1000 */
	X86_VM_RUN_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 4096ULL);
x86_l_11f9:
	/* 0x11f9: ja     1160 <otel_stack_frame_unwind_scan_xdp+0x60> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_1160;
x86_l_11ff:
	/* 0x11ff: cmp    r12d,0x2001 */
	X86_VM_RUN_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 8193ULL);
x86_l_1206:
	/* 0x1206: jae    1160 <otel_stack_frame_unwind_scan_xdp+0x60> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_AE))
		goto x86_l_1160;
x86_l_120c:
	/* 0x120c: test   r14b,0x1 */
	X86_VM_RUN_OP(x86_exec_test_imm, X86_OP_TEST_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_1210:
	/* 0x1210: mov    r13d,r12d */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_R13, X86_R12, X86_WIDTH_32, 0, 0);
x86_l_1213:
	/* 0x1213: cmove  r13d,r10d */
	X86_VM_RUN_OP(x86_exec_cmov, X86_OP_CMOV, X86_R13, X86_R10, X86_WIDTH_32, X86_CC_E, 0);
x86_l_1217:
	/* 0x1217: add    r13d,r15d */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R13, X86_R15, X86_WIDTH_32, X86_ALU_ADD, 0);
x86_l_121a:
	/* 0x121a: add    r8,r13 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R8, X86_R13, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_121d:
	/* 0x121d: mov    r13,rbx */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_R13, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_1220:
	/* 0x1220: shl    r13,0x20 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_1224:
	/* 0x1224: or     rcx,r13 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_1227:
	/* 0x1227: xor    rdx,rcx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_122a:
	/* 0x122a: xor    rdx,r8 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_R8, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_122d:
	/* 0x122d: test   r14b,0x2 */
	X86_VM_RUN_OP(x86_exec_test_imm, X86_OP_TEST_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, 0, 2ULL);
x86_l_1231:
	/* 0x1231: je     123a <otel_stack_frame_unwind_scan_xdp+0x13a> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_E))
		goto x86_l_123a;
x86_l_1233:
	/* 0x1233: inc    al */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_ALU_INC, 1);
x86_l_1235:
	/* 0x1235: mov    ecx,eax */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_1237:
	/* 0x1237: rol    rdx,cl */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ROL, 0);
x86_l_123a:
	/* 0x123a: mov    eax,r12d */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RAX, X86_R12, X86_WIDTH_32, 0, 0);
x86_l_123d:
	/* 0x123d: shl    rax,0x18 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 24ULL);
x86_l_1241:
	/* 0x1241: mov    ecx,r15d */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RCX, X86_R15, X86_WIDTH_32, 0, 0);
x86_l_1244:
	/* 0x1244: xor    rcx,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1247:
	/* 0x1247: test   r14b,0x4 */
	X86_VM_RUN_OP(x86_exec_test_imm, X86_OP_TEST_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, 0, 4ULL);
x86_l_124b:
	/* 0x124b: mov    eax,0x0 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 0ULL);
x86_l_1250:
	/* 0x1250: cmovne rax,rcx */
	X86_VM_RUN_OP(x86_exec_cmov, X86_OP_CMOV, X86_RAX, X86_RCX, X86_WIDTH_64, X86_CC_NE, 0);
x86_l_1254:
	/* 0x1254: add    rax,rdx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1257:
	/* 0x1257: mov    edx,r9d */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RDX, X86_R9, X86_WIDTH_32, 0, 0);
x86_l_125a:
	/* 0x125a: and    dl,0x7 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_ALU_AND, 7ULL);
x86_l_125d:
	/* 0x125d: lea    ecx,[rdx+0x1] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_1260:
	/* 0x1260: mov    r15,rax */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_R15, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_1263:
	/* 0x1263: shl    r15,cl */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 0);
x86_l_1266:
	/* 0x1266: not    dl */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_ALU_NOT, 0);
x86_l_1268:
	/* 0x1268: mov    ecx,edx */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RCX, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_126a:
	/* 0x126a: shr    rax,cl */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 0);
x86_l_126d:
	/* 0x126d: or     rax,r15 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_R15, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_1270:
	/* 0x1270: add    rax,r11 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_R11, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1273:
	/* 0x1273: movzx  ecx,r14w */
	X86_VM_RUN_OP(x86_exec_movzx_reg, X86_OP_MOVZX_REG, X86_RCX, X86_R14, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_1277:
	/* 0x1277: shl    rcx,0x28 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 40ULL);
x86_l_127b:
	/* 0x127b: or     rbx,rcx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_127e:
	/* 0x127e: mov    r11,rbx */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_R11, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_1281:
	/* 0x1281: jmp    1167 <otel_stack_frame_unwind_scan_xdp+0x67> */
	goto x86_l_1167;
x86_l_1286:
	/* 0x1286: mov    QWORD PTR [rsi],r11 */
	X86_VM_RUN_OP(x86_exec_mov_store_reg, X86_OP_MOV_STORE_REG, X86_RSI, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1289:
	/* 0x1289: mov    eax,0x2 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_128e:
	/* 0x128e: pop    rbx */
	X86_VM_RUN_OP(x86_exec_pop, X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_128f:
	/* 0x128f: pop    r12 */
	X86_VM_RUN_OP(x86_exec_pop, X86_OP_POP, X86_R12, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1291:
	/* 0x1291: pop    r13 */
	X86_VM_RUN_OP(x86_exec_pop, X86_OP_POP, X86_R13, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1293:
	/* 0x1293: pop    r14 */
	X86_VM_RUN_OP(x86_exec_pop, X86_OP_POP, X86_R14, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1295:
	/* 0x1295: pop    r15 */
	X86_VM_RUN_OP(x86_exec_pop, X86_OP_POP, X86_R15, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1297:
	/* 0x1297: pop    rbp */
	X86_VM_RUN_OP(x86_exec_pop, X86_OP_POP, X86_RBP, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1298:
	/* 0x1298: ret */
	X86_VM_RET_RAX();
	return XDP_ABORTED;
}

X86_VM_LICENSE();
