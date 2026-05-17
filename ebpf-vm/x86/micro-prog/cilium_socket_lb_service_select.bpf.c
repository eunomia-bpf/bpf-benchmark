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
	/* 0x1133: push   r15 */
	X86_VM_RUN_OP(x86_exec_push, X86_OP_PUSH, X86_REG_NONE, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_1135:
	/* 0x1135: push   r14 */
	X86_VM_RUN_OP(x86_exec_push, X86_OP_PUSH, X86_REG_NONE, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_1137:
	/* 0x1137: push   r12 */
	X86_VM_RUN_OP(x86_exec_push, X86_OP_PUSH, X86_REG_NONE, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_1139:
	/* 0x1139: push   rbx */
	X86_VM_RUN_OP(x86_exec_push, X86_OP_PUSH, X86_REG_NONE, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_113a:
	/* 0x113a: lea    r9,[r8+0x27] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_R9, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 39ULL);
x86_l_113e:
	/* 0x113e: movabs rdi,0x243f6a8885a308d3 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, 2611923443488327891ULL);
x86_l_1148:
	/* 0x1148: xor    r10d,r10d */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R10, X86_R10, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_114b:
	/* 0x114b: jmp    116e <cilium_socket_lb_service_select_xdp+0x6e> */
	goto x86_l_116e;
x86_l_114d:
	/* 0x114d: nop    DWORD PTR [rax] */
	X86_VM_RUN_OP(x86_exec_nop, X86_OP_NOP, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1150:
	/* 0x1150: shl    r11,0x20 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_1154:
	/* 0x1154: movzx  eax,bx */
	X86_VM_RUN_OP(x86_exec_movzx_reg, X86_OP_MOVZX_REG, X86_RAX, X86_RBX, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_1157:
	/* 0x1157: or     rax,r11 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_R11, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_115a:
	/* 0x115a: xor    rdi,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_115d:
	/* 0x115d: inc    r10 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1160:
	/* 0x1160: add    r9,0x18 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1164:
	/* 0x1164: cmp    r10,0x40 */
	X86_VM_RUN_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_64, 0, 64ULL);
x86_l_1168:
	/* 0x1168: je     125c <cilium_socket_lb_service_select_xdp+0x15c> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_E))
		goto x86_l_125c;
x86_l_116e:
	/* 0x116e: mov    eax,DWORD PTR [r9-0x13] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RAX, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551597ULL);
x86_l_1172:
	/* 0x1172: movzx  ebx,WORD PTR [r9-0xd] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RBX, X86_R9, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18446744073709551603ULL);
x86_l_1177:
	/* 0x1177: movzx  r11d,BYTE PTR [r9-0xb] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R11, X86_R9, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551605ULL);
x86_l_117c:
	/* 0x117c: cmp    r11,0x11 */
	X86_VM_RUN_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_64, 0, 17ULL);
x86_l_1180:
	/* 0x1180: setne  cl */
	X86_VM_RUN_OP(x86_exec_setcc, X86_OP_SETCC, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_CC_NE, 0);
x86_l_1183:
	/* 0x1183: cmp    r11,0x6 */
	X86_VM_RUN_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_64, 0, 6ULL);
x86_l_1187:
	/* 0x1187: setne  dl */
	X86_VM_RUN_OP(x86_exec_setcc, X86_OP_SETCC, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_CC_NE, 0);
x86_l_118a:
	/* 0x118a: movzx  r15d,BYTE PTR [r9-0xa] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R15, X86_R9, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551606ULL);
x86_l_118f:
	/* 0x118f: test   r15b,0x2 */
	X86_VM_RUN_OP(x86_exec_test_imm, X86_OP_TEST_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, 0, 2ULL);
x86_l_1193:
	/* 0x1193: mov    ebp,0x0 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, 0, 0ULL);
x86_l_1198:
	/* 0x1198: cmove  ebp,eax */
	X86_VM_RUN_OP(x86_exec_cmov, X86_OP_CMOV, X86_RBP, X86_RAX, X86_WIDTH_32, X86_CC_E, 0);
x86_l_119b:
	/* 0x119b: test   dl,cl */
	X86_VM_RUN_OP(x86_exec_test_reg, X86_OP_TEST_REG, X86_RDX, X86_RCX, X86_WIDTH_8, 0, 0);
x86_l_119d:
	/* 0x119d: jne    1150 <cilium_socket_lb_service_select_xdp+0x50> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_1150;
x86_l_119f:
	/* 0x119f: movzx  r12d,WORD PTR [r9-0x9] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R12, X86_R9, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18446744073709551607ULL);
x86_l_11a4:
	/* 0x11a4: test   r12w,r12w */
	X86_VM_RUN_OP(x86_exec_test_reg, X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_16, 0, 0);
x86_l_11a8:
	/* 0x11a8: je     1150 <cilium_socket_lb_service_select_xdp+0x50> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_E))
		goto x86_l_1150;
x86_l_11aa:
	/* 0x11aa: mov    r14d,DWORD PTR [r9-0x3] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R14, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_11ae:
	/* 0x11ae: movzx  ecx,WORD PTR [r9-0xf] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RCX, X86_R9, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18446744073709551601ULL);
x86_l_11b3:
	/* 0x11b3: mov    edx,ecx */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_11b5:
	/* 0x11b5: shl    edx,0x10 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 16ULL);
x86_l_11b8:
	/* 0x11b8: xor    edx,DWORD PTR [r9-0x17] */
	X86_VM_RUN_OP(x86_exec_alu_mem, X86_OP_ALU_MEM, X86_RDX, X86_R9, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 18446744073709551593ULL);
x86_l_11bc:
	/* 0x11bc: xor    edx,ebx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_11be:
	/* 0x11be: xor    edx,DWORD PTR [r9-0x7] */
	X86_VM_RUN_OP(x86_exec_alu_mem, X86_OP_ALU_MEM, X86_RDX, X86_R9, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 18446744073709551609ULL);
x86_l_11c2:
	/* 0x11c2: movsx  esi,bx */
	X86_VM_RUN_OP(x86_exec_movsx_reg, X86_OP_MOVSX_REG, X86_RSI, X86_RBX, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_11c5:
	/* 0x11c5: cmp    esi,0x752f */
	X86_VM_RUN_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 29999ULL);
x86_l_11cb:
	/* 0x11cb: jg     11f0 <cilium_socket_lb_service_select_xdp+0xf0> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_G))
		goto x86_l_11f0;
x86_l_11cd:
	/* 0x11cd: mov    esi,r15d */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RSI, X86_R15, X86_WIDTH_32, 0, 0);
x86_l_11d0:
	/* 0x11d0: and    esi,0x2 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 2ULL);
x86_l_11d3:
	/* 0x11d3: jne    11f0 <cilium_socket_lb_service_select_xdp+0xf0> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_11f0;
x86_l_11d5:
	/* 0x11d5: mov    eax,eax */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_11d7:
	/* 0x11d7: shl    rax,0x10 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 16ULL);
x86_l_11db:
	/* 0x11db: movzx  ecx,cx */
	X86_VM_RUN_OP(x86_exec_movzx_reg, X86_OP_MOVZX_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_11de:
	/* 0x11de: or     rcx,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_11e1:
	/* 0x11e1: add    rdi,rcx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_11e4:
	/* 0x11e4: jmp    115d <cilium_socket_lb_service_select_xdp+0x5d> */
	goto x86_l_115d;
x86_l_11e9:
	/* 0x11e9: nop    DWORD PTR [rax+0x0] */
	X86_VM_RUN_OP(x86_exec_nop, X86_OP_NOP, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_11f0:
	/* 0x11f0: xor    edx,ebp */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RBP, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_11f2:
	/* 0x11f2: lea    esi,[r14+r15*1] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_RSI, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_11f6:
	/* 0x11f6: add    esi,edx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD, 0);
x86_l_11f8:
	/* 0x11f8: mov    ecx,r11d */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RCX, X86_R11, X86_WIDTH_32, 0, 0);
x86_l_11fb:
	/* 0x11fb: and    ecx,0x7 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_11fe:
	/* 0x11fe: inc    ecx */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1200:
	/* 0x1200: rol    esi,cl */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_ROL, 0);
x86_l_1202:
	/* 0x1202: xor    esi,edx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1204:
	/* 0x1204: mov    eax,esi */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RAX, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_1206:
	/* 0x1206: xor    edx,edx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1208:
	/* 0x1208: div    r12d */
	X86_VM_RUN_OP(x86_exec_div, X86_OP_DIV, X86_REG_NONE, X86_R12, X86_WIDTH_32, 0, 0);
x86_l_120b:
	/* 0x120b: inc    edx */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_120d:
	/* 0x120d: shl    r15d,0x1d */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 29ULL);
x86_l_1211:
	/* 0x1211: sar    r15d,0x1f */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SAR, 31ULL);
x86_l_1215:
	/* 0x1215: inc    r14d */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1218:
	/* 0x1218: and    r14d,r15d */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R14, X86_R15, X86_WIDTH_32, X86_ALU_AND, 0);
x86_l_121b:
	/* 0x121b: xor    r14d,edx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R14, X86_RDX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_121e:
	/* 0x121e: mov    eax,ebp */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RAX, X86_RBP, X86_WIDTH_32, 0, 0);
x86_l_1220:
	/* 0x1220: shl    rax,0x10 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 16ULL);
x86_l_1224:
	/* 0x1224: movzx  edx,bx */
	X86_VM_RUN_OP(x86_exec_movzx_reg, X86_OP_MOVZX_REG, X86_RDX, X86_RBX, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_1227:
	/* 0x1227: shl    rdx,0x20 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_122b:
	/* 0x122b: xor    rdx,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_122e:
	/* 0x122e: shl    r14,0x30 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 48ULL);
x86_l_1232:
	/* 0x1232: or     rsi,r14 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RSI, X86_R14, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_1235:
	/* 0x1235: mov    eax,r10d */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RAX, X86_R10, X86_WIDTH_32, 0, 0);
x86_l_1238:
	/* 0x1238: and    eax,0x7 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_123b:
	/* 0x123b: lea    ecx,[rax+0x1] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_123e:
	/* 0x123e: mov    rbx,rsi */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RBX, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_1241:
	/* 0x1241: shl    rbx,cl */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 0);
x86_l_1244:
	/* 0x1244: not    al */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_ALU_NOT, 0);
x86_l_1246:
	/* 0x1246: mov    ecx,eax */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_1248:
	/* 0x1248: shr    rsi,cl */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RSI, X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 0);
x86_l_124b:
	/* 0x124b: add    rdi,r11 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_R11, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_124e:
	/* 0x124e: add    rdi,rdx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1251:
	/* 0x1251: or     rsi,rbx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RSI, X86_RBX, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_1254:
	/* 0x1254: xor    rdi,rsi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1257:
	/* 0x1257: jmp    115d <cilium_socket_lb_service_select_xdp+0x5d> */
	goto x86_l_115d;
x86_l_125c:
	/* 0x125c: mov    QWORD PTR [r8],rdi */
	X86_VM_RUN_OP(x86_exec_mov_store_reg, X86_OP_MOV_STORE_REG, X86_R8, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_125f:
	/* 0x125f: mov    eax,0x2 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_1264:
	/* 0x1264: pop    rbx */
	X86_VM_RUN_OP(x86_exec_pop, X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1265:
	/* 0x1265: pop    r12 */
	X86_VM_RUN_OP(x86_exec_pop, X86_OP_POP, X86_R12, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1267:
	/* 0x1267: pop    r14 */
	X86_VM_RUN_OP(x86_exec_pop, X86_OP_POP, X86_R14, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1269:
	/* 0x1269: pop    r15 */
	X86_VM_RUN_OP(x86_exec_pop, X86_OP_POP, X86_R15, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_126b:
	/* 0x126b: pop    rbp */
	X86_VM_RUN_OP(x86_exec_pop, X86_OP_POP, X86_RBP, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_126c:
	/* 0x126c: ret */
	X86_VM_RET_RAX();
	return XDP_ABORTED;
}

X86_VM_LICENSE();
