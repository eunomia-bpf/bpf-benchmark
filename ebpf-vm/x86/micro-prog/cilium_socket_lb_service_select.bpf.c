#define X86_VM_ENABLE_STACK 1
#include "../x86_vm_bpf.h"

SEC("xdp")
int cilium_socket_lb_service_select_x86_vm_xdp(struct xdp_md *ctx)
{
	X86_VM_DECLARE_XDP(ctx);
x86_l_1100:
	/* 0x1100: mov    r8,QWORD PTR [rdi] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R8, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1103:
	/* 0x1103: mov    rcx,QWORD PTR [rdi+0x8] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1107:
	/* 0x1107: xor    eax,eax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1109:
	/* 0x1109: cmp    r8,rcx */
	X86_VM_RUN_OP(x86_exec_cmp_reg, X86_OP_CMP_REG, X86_R8, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_110c:
	/* 0x110c: jbe    110f <cilium_socket_lb_service_select_xdp+0xf> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_BE))
		goto x86_l_110f;
x86_l_110e:
	/* 0x110e: ret */
	X86_VM_RET_RAX();
x86_l_110f:
	/* 0x110f: lea    rdx,[r8+0x8] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_RDX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1113:
	/* 0x1113: cmp    rdx,rcx */
	X86_VM_RUN_OP(x86_exec_cmp_reg, X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_1116:
	/* 0x1116: ja     110e <cilium_socket_lb_service_select_xdp+0xe> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_110e;
x86_l_1118:
	/* 0x1118: lea    rdx,[r8+0x610] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_RDX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1552ULL);
x86_l_111f:
	/* 0x111f: cmp    rdx,rcx */
	X86_VM_RUN_OP(x86_exec_cmp_reg, X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_1122:
	/* 0x1122: ja     110e <cilium_socket_lb_service_select_xdp+0xe> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_110e;
x86_l_1124:
	/* 0x1124: cmp    DWORD PTR [r8+0x8],0x40 */
	X86_VM_RUN_OP(x86_exec_cmp_mem_imm, X86_OP_CMP_MEM_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738432ULL);
x86_l_1129:
	/* 0x1129: jne    110e <cilium_socket_lb_service_select_xdp+0xe> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_110e;
x86_l_112b:
	/* 0x112b: cmp    DWORD PTR [r8+0xc],0x18 */
	X86_VM_RUN_OP(x86_exec_cmp_mem_imm, X86_OP_CMP_MEM_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607576ULL);
x86_l_1130:
	/* 0x1130: jne    110e <cilium_socket_lb_service_select_xdp+0xe> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_110e;
x86_l_1132:
	/* 0x1132: push   rbp */
	X86_VM_RUN_OP(x86_exec_push, X86_OP_PUSH, X86_REG_NONE, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_1133:
	/* 0x1133: mov    rbp,rsp */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RBP, X86_RSP, X86_WIDTH_64, 0, 0);
x86_l_1136:
	/* 0x1136: push   r15 */
	X86_VM_RUN_OP(x86_exec_push, X86_OP_PUSH, X86_REG_NONE, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_1138:
	/* 0x1138: push   r14 */
	X86_VM_RUN_OP(x86_exec_push, X86_OP_PUSH, X86_REG_NONE, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_113a:
	/* 0x113a: push   r13 */
	X86_VM_RUN_OP(x86_exec_push, X86_OP_PUSH, X86_REG_NONE, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_113c:
	/* 0x113c: push   r12 */
	X86_VM_RUN_OP(x86_exec_push, X86_OP_PUSH, X86_REG_NONE, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_113e:
	/* 0x113e: push   rbx */
	X86_VM_RUN_OP(x86_exec_push, X86_OP_PUSH, X86_REG_NONE, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_113f:
	/* 0x113f: lea    r9,[r8+0x27] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_R9, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 39ULL);
x86_l_1143:
	/* 0x1143: movabs rdi,0x243f6a8885a308d3 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, 2611923443488327891ULL);
x86_l_114d:
	/* 0x114d: xor    r10d,r10d */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R10, X86_R10, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1150:
	/* 0x1150: jmp    117e <cilium_socket_lb_service_select_xdp+0x7e> */
	goto x86_l_117e;
x86_l_1152:
	/* 0x1152: data16 data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0] */
	X86_VM_RUN_OP(x86_exec_nop, X86_OP_NOP, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1160:
	/* 0x1160: shl    r11,0x20 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_1164:
	/* 0x1164: movzx  eax,bx */
	X86_VM_RUN_OP(x86_exec_movzx_reg, X86_OP_MOVZX_REG, X86_RAX, X86_RBX, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_1167:
	/* 0x1167: or     rax,r11 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_R11, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_116a:
	/* 0x116a: xor    rdi,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_116d:
	/* 0x116d: inc    r10 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1170:
	/* 0x1170: add    r9,0x18 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1174:
	/* 0x1174: cmp    r10,0x40 */
	X86_VM_RUN_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_64, 0, 64ULL);
x86_l_1178:
	/* 0x1178: je     126e <cilium_socket_lb_service_select_xdp+0x16e> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_E))
		goto x86_l_126e;
x86_l_117e:
	/* 0x117e: mov    eax,DWORD PTR [r9-0x13] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RAX, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551597ULL);
x86_l_1182:
	/* 0x1182: movzx  ebx,WORD PTR [r9-0xd] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RBX, X86_R9, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18446744073709551603ULL);
x86_l_1187:
	/* 0x1187: movzx  r11d,BYTE PTR [r9-0xb] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R11, X86_R9, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551605ULL);
x86_l_118c:
	/* 0x118c: cmp    r11,0x11 */
	X86_VM_RUN_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_64, 0, 17ULL);
x86_l_1190:
	/* 0x1190: setne  cl */
	X86_VM_RUN_OP(x86_exec_setcc, X86_OP_SETCC, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_CC_NE, 0);
x86_l_1193:
	/* 0x1193: cmp    r11,0x6 */
	X86_VM_RUN_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_64, 0, 6ULL);
x86_l_1197:
	/* 0x1197: setne  dl */
	X86_VM_RUN_OP(x86_exec_setcc, X86_OP_SETCC, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_CC_NE, 0);
x86_l_119a:
	/* 0x119a: movzx  r12d,BYTE PTR [r9-0xa] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R12, X86_R9, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551606ULL);
x86_l_119f:
	/* 0x119f: test   r12b,0x2 */
	X86_VM_RUN_OP(x86_exec_test_imm, X86_OP_TEST_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, 0, 2ULL);
x86_l_11a3:
	/* 0x11a3: mov    r15d,0x0 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 0ULL);
x86_l_11a9:
	/* 0x11a9: cmove  r15d,eax */
	X86_VM_RUN_OP(x86_exec_cmov, X86_OP_CMOV, X86_R15, X86_RAX, X86_WIDTH_32, X86_CC_E, 0);
x86_l_11ad:
	/* 0x11ad: test   dl,cl */
	X86_VM_RUN_OP(x86_exec_test_reg, X86_OP_TEST_REG, X86_RDX, X86_RCX, X86_WIDTH_8, 0, 0);
x86_l_11af:
	/* 0x11af: jne    1160 <cilium_socket_lb_service_select_xdp+0x60> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_1160;
x86_l_11b1:
	/* 0x11b1: movzx  r13d,WORD PTR [r9-0x9] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R13, X86_R9, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18446744073709551607ULL);
x86_l_11b6:
	/* 0x11b6: test   r13w,r13w */
	X86_VM_RUN_OP(x86_exec_test_reg, X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_16, 0, 0);
x86_l_11ba:
	/* 0x11ba: je     1160 <cilium_socket_lb_service_select_xdp+0x60> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_E))
		goto x86_l_1160;
x86_l_11bc:
	/* 0x11bc: mov    r14d,DWORD PTR [r9-0x3] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R14, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_11c0:
	/* 0x11c0: movzx  ecx,WORD PTR [r9-0xf] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RCX, X86_R9, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18446744073709551601ULL);
x86_l_11c5:
	/* 0x11c5: mov    edx,ecx */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_11c7:
	/* 0x11c7: shl    edx,0x10 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 16ULL);
x86_l_11ca:
	/* 0x11ca: xor    edx,DWORD PTR [r9-0x17] */
	X86_VM_RUN_OP(x86_exec_alu_mem, X86_OP_ALU_MEM, X86_RDX, X86_R9, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 18446744073709551593ULL);
x86_l_11ce:
	/* 0x11ce: xor    edx,ebx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_11d0:
	/* 0x11d0: xor    edx,DWORD PTR [r9-0x7] */
	X86_VM_RUN_OP(x86_exec_alu_mem, X86_OP_ALU_MEM, X86_RDX, X86_R9, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 18446744073709551609ULL);
x86_l_11d4:
	/* 0x11d4: movsx  esi,bx */
	X86_VM_RUN_OP(x86_exec_movsx_reg, X86_OP_MOVSX_REG, X86_RSI, X86_RBX, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_11d7:
	/* 0x11d7: cmp    esi,0x752f */
	X86_VM_RUN_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 29999ULL);
x86_l_11dd:
	/* 0x11dd: jg     1200 <cilium_socket_lb_service_select_xdp+0x100> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_G))
		goto x86_l_1200;
x86_l_11df:
	/* 0x11df: mov    esi,r12d */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RSI, X86_R12, X86_WIDTH_32, 0, 0);
x86_l_11e2:
	/* 0x11e2: and    esi,0x2 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 2ULL);
x86_l_11e5:
	/* 0x11e5: jne    1200 <cilium_socket_lb_service_select_xdp+0x100> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_1200;
x86_l_11e7:
	/* 0x11e7: mov    eax,eax */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_11e9:
	/* 0x11e9: shl    rax,0x10 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 16ULL);
x86_l_11ed:
	/* 0x11ed: movzx  ecx,cx */
	X86_VM_RUN_OP(x86_exec_movzx_reg, X86_OP_MOVZX_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_11f0:
	/* 0x11f0: or     rcx,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_11f3:
	/* 0x11f3: add    rdi,rcx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_11f6:
	/* 0x11f6: jmp    116d <cilium_socket_lb_service_select_xdp+0x6d> */
	goto x86_l_116d;
x86_l_11fb:
	/* 0x11fb: nop    DWORD PTR [rax+rax*1+0x0] */
	X86_VM_RUN_OP(x86_exec_nop, X86_OP_NOP, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1200:
	/* 0x1200: xor    edx,r15d */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_R15, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1203:
	/* 0x1203: lea    esi,[r14+r12*1] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_RSI, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_1207:
	/* 0x1207: add    esi,edx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD, 0);
x86_l_1209:
	/* 0x1209: mov    ecx,r11d */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RCX, X86_R11, X86_WIDTH_32, 0, 0);
x86_l_120c:
	/* 0x120c: and    ecx,0x7 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_120f:
	/* 0x120f: inc    ecx */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1211:
	/* 0x1211: rol    esi,cl */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_ROL, 0);
x86_l_1213:
	/* 0x1213: xor    esi,edx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1215:
	/* 0x1215: mov    eax,esi */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RAX, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_1217:
	/* 0x1217: xor    edx,edx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1219:
	/* 0x1219: div    r13d */
	X86_VM_RUN_OP(x86_exec_div, X86_OP_DIV, X86_REG_NONE, X86_R13, X86_WIDTH_32, 0, 0);
x86_l_121c:
	/* 0x121c: inc    edx */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_121e:
	/* 0x121e: shl    r12d,0x1d */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 29ULL);
x86_l_1222:
	/* 0x1222: sar    r12d,0x1f */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SAR, 31ULL);
x86_l_1226:
	/* 0x1226: inc    r14d */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1229:
	/* 0x1229: and    r14d,r12d */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R14, X86_R12, X86_WIDTH_32, X86_ALU_AND, 0);
x86_l_122c:
	/* 0x122c: xor    r14d,edx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R14, X86_RDX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_122f:
	/* 0x122f: mov    eax,r15d */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RAX, X86_R15, X86_WIDTH_32, 0, 0);
x86_l_1232:
	/* 0x1232: shl    rax,0x10 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 16ULL);
x86_l_1236:
	/* 0x1236: movzx  edx,bx */
	X86_VM_RUN_OP(x86_exec_movzx_reg, X86_OP_MOVZX_REG, X86_RDX, X86_RBX, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_1239:
	/* 0x1239: shl    rdx,0x20 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_123d:
	/* 0x123d: xor    rdx,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1240:
	/* 0x1240: shl    r14,0x30 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 48ULL);
x86_l_1244:
	/* 0x1244: or     rsi,r14 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RSI, X86_R14, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_1247:
	/* 0x1247: mov    eax,r10d */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RAX, X86_R10, X86_WIDTH_32, 0, 0);
x86_l_124a:
	/* 0x124a: and    eax,0x7 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_124d:
	/* 0x124d: lea    ecx,[rax+0x1] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_1250:
	/* 0x1250: mov    rbx,rsi */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RBX, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_1253:
	/* 0x1253: shl    rbx,cl */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 0);
x86_l_1256:
	/* 0x1256: not    al */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_ALU_NOT, 0);
x86_l_1258:
	/* 0x1258: mov    ecx,eax */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_125a:
	/* 0x125a: shr    rsi,cl */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RSI, X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 0);
x86_l_125d:
	/* 0x125d: add    rdi,r11 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_R11, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1260:
	/* 0x1260: add    rdi,rdx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1263:
	/* 0x1263: or     rsi,rbx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RSI, X86_RBX, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_1266:
	/* 0x1266: xor    rdi,rsi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1269:
	/* 0x1269: jmp    116d <cilium_socket_lb_service_select_xdp+0x6d> */
	goto x86_l_116d;
x86_l_126e:
	/* 0x126e: mov    QWORD PTR [r8],rdi */
	X86_VM_RUN_OP(x86_exec_mov_store_reg, X86_OP_MOV_STORE_REG, X86_R8, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1271:
	/* 0x1271: mov    eax,0x2 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_1276:
	/* 0x1276: pop    rbx */
	X86_VM_RUN_OP(x86_exec_pop, X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1277:
	/* 0x1277: pop    r12 */
	X86_VM_RUN_OP(x86_exec_pop, X86_OP_POP, X86_R12, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1279:
	/* 0x1279: pop    r13 */
	X86_VM_RUN_OP(x86_exec_pop, X86_OP_POP, X86_R13, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_127b:
	/* 0x127b: pop    r14 */
	X86_VM_RUN_OP(x86_exec_pop, X86_OP_POP, X86_R14, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_127d:
	/* 0x127d: pop    r15 */
	X86_VM_RUN_OP(x86_exec_pop, X86_OP_POP, X86_R15, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_127f:
	/* 0x127f: pop    rbp */
	X86_VM_RUN_OP(x86_exec_pop, X86_OP_POP, X86_RBP, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1280:
	/* 0x1280: ret */
	X86_VM_RET_RAX();
	return XDP_ABORTED;
}

X86_VM_LICENSE();
