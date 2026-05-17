#define X86_VM_ENABLE_STACK 1
#include "../x86_vm_bpf.h"

SEC("xdp")
int bcc_tcpconnect_ipv4_tuple_filter_x86_vm_xdp(struct xdp_md *ctx)
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
	/* 0x110c: jbe    110f <bcc_tcpconnect_ipv4_tuple_filter_xdp+0xf> */
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
	/* 0x1116: ja     110e <bcc_tcpconnect_ipv4_tuple_filter_xdp+0xe> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_110e;
x86_l_1118:
	/* 0x1118: lea    rsi,[rdx+0x310] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_RSI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 784ULL);
x86_l_111f:
	/* 0x111f: cmp    rsi,rcx */
	X86_VM_RUN_OP(x86_exec_cmp_reg, X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_1122:
	/* 0x1122: ja     110e <bcc_tcpconnect_ipv4_tuple_filter_xdp+0xe> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_110e;
x86_l_1124:
	/* 0x1124: cmp    DWORD PTR [rdx+0x8],0x20 */
	X86_VM_RUN_OP(x86_exec_cmp_mem_imm, X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738400ULL);
x86_l_1128:
	/* 0x1128: jne    110e <bcc_tcpconnect_ipv4_tuple_filter_xdp+0xe> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_110e;
x86_l_112a:
	/* 0x112a: cmp    DWORD PTR [rdx+0xc],0x18 */
	X86_VM_RUN_OP(x86_exec_cmp_mem_imm, X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607576ULL);
x86_l_112e:
	/* 0x112e: jne    110e <bcc_tcpconnect_ipv4_tuple_filter_xdp+0xe> */
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
	/* 0x1135: push   rbx */
	X86_VM_RUN_OP(x86_exec_push, X86_OP_PUSH, X86_REG_NONE, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_1136:
	/* 0x1136: lea    rsi,[rdx+0x27] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_RSI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 39ULL);
x86_l_113a:
	/* 0x113a: movabs r8,0xa0761d6478bd642f */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_64, 0, 11562461410679940143ULL);
x86_l_1144:
	/* 0x1144: xor    edi,edi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1146:
	/* 0x1146: jmp    116d <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x6d> */
	goto x86_l_116d;
x86_l_1148:
	/* 0x1148: nop    DWORD PTR [rax+rax*1+0x0] */
	X86_VM_RUN_OP(x86_exec_nop, X86_OP_NOP, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1150:
	/* 0x1150: shl    rcx,0x30 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 48ULL);
x86_l_1154:
	/* 0x1154: mov    eax,ebx */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RAX, X86_RBX, X86_WIDTH_32, 0, 0);
x86_l_1156:
	/* 0x1156: or     rax,rcx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_1159:
	/* 0x1159: xor    r8,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R8, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_115c:
	/* 0x115c: inc    rdi */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_115f:
	/* 0x115f: add    rsi,0x18 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1163:
	/* 0x1163: cmp    rdi,0x20 */
	X86_VM_RUN_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, 32ULL);
x86_l_1167:
	/* 0x1167: je     129f <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x19f> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_E))
		goto x86_l_129f;
x86_l_116d:
	/* 0x116d: movzx  eax,WORD PTR [rsi-0x5] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18446744073709551611ULL);
x86_l_1171:
	/* 0x1171: cmp    eax,0x1f8f */
	X86_VM_RUN_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 8079ULL);
x86_l_1176:
	/* 0x1176: jg     1190 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x90> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_G))
		goto x86_l_1190;
x86_l_1178:
	/* 0x1178: cmp    eax,0x50 */
	X86_VM_RUN_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 80ULL);
x86_l_117b:
	/* 0x117b: je     11bc <bcc_tcpconnect_ipv4_tuple_filter_xdp+0xbc> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_E))
		goto x86_l_11bc;
x86_l_117d:
	/* 0x117d: cmp    eax,0x1bb */
	X86_VM_RUN_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 443ULL);
x86_l_1182:
	/* 0x1182: jne    11a6 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0xa6> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_11a6;
x86_l_1184:
	/* 0x1184: mov    r9d,0x2 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_118a:
	/* 0x118a: jmp    11d0 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0xd0> */
	goto x86_l_11d0;
x86_l_118c:
	/* 0x118c: nop    DWORD PTR [rax+0x0] */
	X86_VM_RUN_OP(x86_exec_nop, X86_OP_NOP, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1190:
	/* 0x1190: cmp    eax,0x1f90 */
	X86_VM_RUN_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 8080ULL);
x86_l_1195:
	/* 0x1195: je     119e <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x9e> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_E))
		goto x86_l_119e;
x86_l_1197:
	/* 0x1197: cmp    eax,0x20fb */
	X86_VM_RUN_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 8443ULL);
x86_l_119c:
	/* 0x119c: jne    11a6 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0xa6> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_11a6;
x86_l_119e:
	/* 0x119e: mov    r9d,0x3 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_32, 0, 3ULL);
x86_l_11a4:
	/* 0x11a4: jmp    11d0 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0xd0> */
	goto x86_l_11d0;
x86_l_11a6:
	/* 0x11a6: movsx  ecx,ax */
	X86_VM_RUN_OP(x86_exec_movsx_reg, X86_OP_MOVSX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_11a9:
	/* 0x11a9: xor    r9d,r9d */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_R9, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_11ac:
	/* 0x11ac: cmp    ecx,0x7530 */
	X86_VM_RUN_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 30000ULL);
x86_l_11b2:
	/* 0x11b2: setge  r9b */
	X86_VM_RUN_OP(x86_exec_setcc, X86_OP_SETCC, X86_R9, X86_REG_NONE, X86_WIDTH_8, X86_CC_GE, 0);
x86_l_11b6:
	/* 0x11b6: shl    r9d,0x2 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 2ULL);
x86_l_11ba:
	/* 0x11ba: jmp    11d0 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0xd0> */
	goto x86_l_11d0;
x86_l_11bc:
	/* 0x11bc: mov    r9d,0x1 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_11c2:
	/* 0x11c2: data16 data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0] */
	X86_VM_RUN_OP(x86_exec_nop, X86_OP_NOP, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_11d0:
	/* 0x11d0: mov    ebx,DWORD PTR [rsi-0x17] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RBX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551593ULL);
x86_l_11d3:
	/* 0x11d3: movzx  ecx,BYTE PTR [rsi-0x3] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551613ULL);
x86_l_11d7:
	/* 0x11d7: cmp    ecx,0x2 */
	X86_VM_RUN_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_11da:
	/* 0x11da: jne    1150 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x50> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_1150;
x86_l_11e0:
	/* 0x11e0: mov    r10d,DWORD PTR [rsi-0x13] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R10, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551597ULL);
x86_l_11e4:
	/* 0x11e4: movzx  ebp,BYTE PTR [rsi-0x2] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551614ULL);
x86_l_11e8:
	/* 0x11e8: test   bpl,0x1 */
	X86_VM_RUN_OP(x86_exec_test_imm, X86_OP_TEST_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_11ec:
	/* 0x11ec: je     1290 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x190> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_E))
		goto x86_l_1290;
x86_l_11f2:
	/* 0x11f2: test   r9d,r9d */
	X86_VM_RUN_OP(x86_exec_test_reg, X86_OP_TEST_REG, X86_R9, X86_R9, X86_WIDTH_32, 0, 0);
x86_l_11f5:
	/* 0x11f5: je     1290 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x190> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_E))
		goto x86_l_1290;
x86_l_11fb:
	/* 0x11fb: mov    ecx,DWORD PTR [rsi-0xb] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551605ULL);
x86_l_11fe:
	/* 0x11fe: movzx  r14d,BYTE PTR [rsi-0x7] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R14, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551609ULL);
x86_l_1203:
	/* 0x1203: movzx  r15d,BYTE PTR [rsi-0x6] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R15, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551610ULL);
x86_l_1208:
	/* 0x1208: rol    ecx,0x7 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ROL, 7ULL);
x86_l_120b:
	/* 0x120b: xor    ecx,DWORD PTR [rsi-0xf] */
	X86_VM_RUN_OP(x86_exec_alu_mem, X86_OP_ALU_MEM, X86_RCX, X86_RSI, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 18446744073709551601ULL);
x86_l_120e:
	/* 0x120e: movzx  r11d,WORD PTR [rsi-0x1] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R11, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18446744073709551615ULL);
x86_l_1213:
	/* 0x1213: shl    r15d,0x18 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 24ULL);
x86_l_1217:
	/* 0x1217: shl    r14d,0x10 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 16ULL);
x86_l_121b:
	/* 0x121b: or     r14d,r15d */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R14, X86_R15, X86_WIDTH_32, X86_ALU_OR, 0);
x86_l_121e:
	/* 0x121e: movzx  eax,ax */
	X86_VM_RUN_OP(x86_exec_movzx_reg, X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_1221:
	/* 0x1221: xor    eax,r14d */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_R14, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1224:
	/* 0x1224: xor    eax,ecx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1226:
	/* 0x1226: mov    ecx,ebp */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RCX, X86_RBP, X86_WIDTH_32, 0, 0);
x86_l_1228:
	/* 0x1228: shl    ecx,0x1e */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 30ULL);
x86_l_122b:
	/* 0x122b: sar    ecx,0x1f */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SAR, 31ULL);
x86_l_122e:
	/* 0x122e: lea    r14d,[r10+rbx*1] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_R14, X86_R10, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_1232:
	/* 0x1232: and    r14d,ecx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_ALU_AND, 0);
x86_l_1235:
	/* 0x1235: xor    r14d,r11d */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R14, X86_R11, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1238:
	/* 0x1238: xor    r14d,eax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_123b:
	/* 0x123b: lea    ecx,[r9+0x3] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_RCX, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 3ULL);
x86_l_123f:
	/* 0x123f: mov    eax,r14d */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RAX, X86_R14, X86_WIDTH_32, 0, 0);
x86_l_1242:
	/* 0x1242: rol    eax,cl */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_ROL, 0);
x86_l_1244:
	/* 0x1244: test   bpl,0x4 */
	X86_VM_RUN_OP(x86_exec_test_imm, X86_OP_TEST_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, 0, 4ULL);
x86_l_1248:
	/* 0x1248: cmove  eax,r14d */
	X86_VM_RUN_OP(x86_exec_cmov, X86_OP_CMOV, X86_RAX, X86_R14, X86_WIDTH_32, X86_CC_E, 0);
x86_l_124c:
	/* 0x124c: shl    rax,0x20 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_1250:
	/* 0x1250: mov    ebx,ebx */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RBX, X86_RBX, X86_WIDTH_32, 0, 0);
x86_l_1252:
	/* 0x1252: or     rbx,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_1255:
	/* 0x1255: mov    eax,edi */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RAX, X86_RDI, X86_WIDTH_32, 0, 0);
x86_l_1257:
	/* 0x1257: and    al,0x7 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_ALU_AND, 7ULL);
x86_l_1259:
	/* 0x1259: lea    ecx,[rax+0x1] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_125c:
	/* 0x125c: mov    r14,rbx */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_R14, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_125f:
	/* 0x125f: shl    r14,cl */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 0);
x86_l_1262:
	/* 0x1262: not    al */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_ALU_NOT, 0);
x86_l_1264:
	/* 0x1264: mov    ecx,eax */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_1266:
	/* 0x1266: shr    rbx,cl */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 0);
x86_l_1269:
	/* 0x1269: or     rbx,r14 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RBX, X86_R14, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_126c:
	/* 0x126c: xor    rbx,r8 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RBX, X86_R8, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_126f:
	/* 0x126f: shl    r9,0x38 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 56ULL);
x86_l_1273:
	/* 0x1273: shl    r11d,0x10 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 16ULL);
x86_l_1277:
	/* 0x1277: or     r11,r9 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R11, X86_R9, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_127a:
	/* 0x127a: mov    r8d,r10d */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_R8, X86_R10, X86_WIDTH_32, 0, 0);
x86_l_127d:
	/* 0x127d: xor    r8,r11 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R8, X86_R11, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1280:
	/* 0x1280: add    r8,rbx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R8, X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1283:
	/* 0x1283: jmp    115c <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x5c> */
	goto x86_l_115c;
x86_l_1288:
	/* 0x1288: nop    DWORD PTR [rax+rax*1+0x0] */
	X86_VM_RUN_OP(x86_exec_nop, X86_OP_NOP, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1290:
	/* 0x1290: shl    r10,0x20 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_1294:
	/* 0x1294: or     r10,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R10, X86_RAX, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_1297:
	/* 0x1297: add    r8,r10 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R8, X86_R10, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_129a:
	/* 0x129a: jmp    115c <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x5c> */
	goto x86_l_115c;
x86_l_129f:
	/* 0x129f: mov    QWORD PTR [rdx],r8 */
	X86_VM_RUN_OP(x86_exec_mov_store_reg, X86_OP_MOV_STORE_REG, X86_RDX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12a2:
	/* 0x12a2: mov    eax,0x2 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_12a7:
	/* 0x12a7: pop    rbx */
	X86_VM_RUN_OP(x86_exec_pop, X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_12a8:
	/* 0x12a8: pop    r14 */
	X86_VM_RUN_OP(x86_exec_pop, X86_OP_POP, X86_R14, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_12aa:
	/* 0x12aa: pop    r15 */
	X86_VM_RUN_OP(x86_exec_pop, X86_OP_POP, X86_R15, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_12ac:
	/* 0x12ac: pop    rbp */
	X86_VM_RUN_OP(x86_exec_pop, X86_OP_POP, X86_RBP, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_12ad:
	/* 0x12ad: ret */
	X86_VM_RET_RAX();
	return XDP_ABORTED;
}

X86_VM_LICENSE();
