#define X86_VM_ENABLE_STACK 1
#include "../x86_vm_bpf.h"

SEC("xdp")
int payload_prefix_memcmp_scan_x86_vm_xdp(struct xdp_md *ctx)
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
	/* 0x110c: ja     130e <payload_prefix_memcmp_scan_xdp+0x20e> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_130e;
x86_l_1112:
	/* 0x1112: lea    rsi,[rcx+0x8] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1116:
	/* 0x1116: cmp    rsi,rdx */
	X86_VM_RUN_OP(x86_exec_cmp_reg, X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_1119:
	/* 0x1119: ja     130e <payload_prefix_memcmp_scan_xdp+0x20e> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_130e;
x86_l_111f:
	/* 0x111f: lea    rdi,[rcx+0xcc] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_1126:
	/* 0x1126: cmp    rdi,rdx */
	X86_VM_RUN_OP(x86_exec_cmp_reg, X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_1129:
	/* 0x1129: ja     130e <payload_prefix_memcmp_scan_xdp+0x20e> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_130e;
x86_l_112f:
	/* 0x112f: push   rbp */
	X86_VM_RUN_OP(x86_exec_push, X86_OP_PUSH, X86_REG_NONE, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_1130:
	/* 0x1130: mov    rbp,rsp */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RBP, X86_RSP, X86_WIDTH_64, 0, 0);
x86_l_1133:
	/* 0x1133: cmp    DWORD PTR [rsi],0x3 */
	X86_VM_RUN_OP(x86_exec_cmp_mem_imm, X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 3ULL);
x86_l_1136:
	/* 0x1136: jne    130d <payload_prefix_memcmp_scan_xdp+0x20d> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_130d;
x86_l_113c:
	/* 0x113c: mov    dl,0x1d */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, 0, 29ULL);
x86_l_113e:
	/* 0x113e: mov    dil,0x4 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_8, 0, 4ULL);
x86_l_1141:
	/* 0x1141: xor    eax,eax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1143:
	/* 0x1143: data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0] */
	X86_VM_RUN_OP(x86_exec_nop, X86_OP_NOP, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1150:
	/* 0x1150: movzx  esi,BYTE PTR [rcx+rax*1+0xc] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 12ULL);
x86_l_1155:
	/* 0x1155: lea    r9d,[rdx-0x1d] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_R9, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551587ULL);
x86_l_1159:
	/* 0x1159: lea    r8d,[rdi-0x4] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_R8, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551612ULL);
x86_l_115d:
	/* 0x115d: xor    r8b,r9b */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R8, X86_R9, X86_WIDTH_8, X86_ALU_XOR, 0);
x86_l_1160:
	/* 0x1160: xor    r8b,0xa5 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_8, X86_ALU_XOR, 165ULL);
x86_l_1164:
	/* 0x1164: add    r8b,0x11 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_8, X86_ALU_ADD, 17ULL);
x86_l_1168:
	/* 0x1168: cmp    sil,r8b */
	X86_VM_RUN_OP(x86_exec_cmp_reg, X86_OP_CMP_REG, X86_RSI, X86_R8, X86_WIDTH_8, 0, 0);
x86_l_116b:
	/* 0x116b: jne    11a6 <payload_prefix_memcmp_scan_xdp+0xa6> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_11a6;
x86_l_116d:
	/* 0x116d: movzx  esi,BYTE PTR [rcx+rax*1+0xd] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 13ULL);
x86_l_1172:
	/* 0x1172: mov    r8d,edx */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_R8, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_1175:
	/* 0x1175: xor    r8b,dil */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R8, X86_RDI, X86_WIDTH_8, X86_ALU_XOR, 0);
x86_l_1178:
	/* 0x1178: xor    r8b,0xa5 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_8, X86_ALU_XOR, 165ULL);
x86_l_117c:
	/* 0x117c: add    r8b,0x11 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_8, X86_ALU_ADD, 17ULL);
x86_l_1180:
	/* 0x1180: add    rax,0x2 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_1184:
	/* 0x1184: cmp    sil,r8b */
	X86_VM_RUN_OP(x86_exec_cmp_reg, X86_OP_CMP_REG, X86_RSI, X86_R8, X86_WIDTH_8, 0, 0);
x86_l_1187:
	/* 0x1187: jne    11a9 <payload_prefix_memcmp_scan_xdp+0xa9> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_11a9;
x86_l_1189:
	/* 0x1189: add    dl,0x3a */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_ALU_ADD, 58ULL);
x86_l_118c:
	/* 0x118c: add    dil,0x8 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_8, X86_ALU_ADD, 8ULL);
x86_l_1190:
	/* 0x1190: cmp    rax,0x40 */
	X86_VM_RUN_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, 0, 64ULL);
x86_l_1194:
	/* 0x1194: jne    1150 <payload_prefix_memcmp_scan_xdp+0x50> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_1150;
x86_l_1196:
	/* 0x1196: movzx  eax,BYTE PTR [rcx+0x4b] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 75ULL);
x86_l_119a:
	/* 0x119a: movabs rdx,0xf43e9fde8cf6b51c */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, 0, 17599680172007011612ULL);
x86_l_11a4:
	/* 0x11a4: jmp    11c7 <payload_prefix_memcmp_scan_xdp+0xc7> */
	goto x86_l_11c7;
x86_l_11a6:
	/* 0x11a6: inc    rax */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_11a9:
	/* 0x11a9: mov    eax,eax */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_11ab:
	/* 0x11ab: lea    rax,[rax+rax*4] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 2), 0ULL);
x86_l_11af:
	/* 0x11af: movabs rdx,0x6a09e667f3bcc909 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, 0, 7640891576956012809ULL);
x86_l_11b9:
	/* 0x11b9: add    rdx,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_11bc:
	/* 0x11bc: movzx  eax,sil */
	X86_VM_RUN_OP(x86_exec_movzx_reg, X86_OP_MOVZX_REG, X86_RAX, X86_RSI, X86_WIDTH_32, X86_WIDTH_8, 0);
x86_l_11c0:
	/* 0x11c0: xor    rax,rdx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_11c3:
	/* 0x11c3: movzx  edx,r8b */
	X86_VM_RUN_OP(x86_exec_movzx_reg, X86_OP_MOVZX_REG, X86_RDX, X86_R8, X86_WIDTH_32, X86_WIDTH_8, 0);
x86_l_11c7:
	/* 0x11c7: add    rdx,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_11ca:
	/* 0x11ca: rol    rdx,0x5 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 5ULL);
x86_l_11ce:
	/* 0x11ce: mov    sil,0x1d */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, 0, 29ULL);
x86_l_11d1:
	/* 0x11d1: mov    dil,0x4 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_8, 0, 4ULL);
x86_l_11d4:
	/* 0x11d4: xor    eax,eax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_11d6:
	/* 0x11d6: cs nop WORD PTR [rax+rax*1+0x0] */
	X86_VM_RUN_OP(x86_exec_nop, X86_OP_NOP, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_11e0:
	/* 0x11e0: movzx  r8d,BYTE PTR [rcx+rax*1+0x4c] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R8, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 76ULL);
x86_l_11e6:
	/* 0x11e6: lea    r10d,[rsi-0x1d] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_R10, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551587ULL);
x86_l_11ea:
	/* 0x11ea: lea    r9d,[rdi-0x4] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_R9, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551612ULL);
x86_l_11ee:
	/* 0x11ee: xor    r9b,r10b */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_R10, X86_WIDTH_8, X86_ALU_XOR, 0);
x86_l_11f1:
	/* 0x11f1: xor    r9b,0xa5 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_8, X86_ALU_XOR, 165ULL);
x86_l_11f5:
	/* 0x11f5: add    r9b,0x11 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_8, X86_ALU_ADD, 17ULL);
x86_l_11f9:
	/* 0x11f9: cmp    r8b,r9b */
	X86_VM_RUN_OP(x86_exec_cmp_reg, X86_OP_CMP_REG, X86_R8, X86_R9, X86_WIDTH_8, 0, 0);
x86_l_11fc:
	/* 0x11fc: jne    1242 <payload_prefix_memcmp_scan_xdp+0x142> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_1242;
x86_l_11fe:
	/* 0x11fe: movzx  r8d,BYTE PTR [rcx+rax*1+0x4d] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R8, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 77ULL);
x86_l_1204:
	/* 0x1204: mov    r9d,esi */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_R9, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_1207:
	/* 0x1207: xor    r9b,dil */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_RDI, X86_WIDTH_8, X86_ALU_XOR, 0);
x86_l_120a:
	/* 0x120a: xor    r9b,0xa5 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_8, X86_ALU_XOR, 165ULL);
x86_l_120e:
	/* 0x120e: add    r9b,0x11 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_8, X86_ALU_ADD, 17ULL);
x86_l_1212:
	/* 0x1212: add    rax,0x2 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_1216:
	/* 0x1216: cmp    r8b,r9b */
	X86_VM_RUN_OP(x86_exec_cmp_reg, X86_OP_CMP_REG, X86_R8, X86_R9, X86_WIDTH_8, 0, 0);
x86_l_1219:
	/* 0x1219: jne    1245 <payload_prefix_memcmp_scan_xdp+0x145> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_1245;
x86_l_121b:
	/* 0x121b: add    sil,0x3a */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_ALU_ADD, 58ULL);
x86_l_121f:
	/* 0x121f: add    dil,0x8 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_8, X86_ALU_ADD, 8ULL);
x86_l_1223:
	/* 0x1223: cmp    rax,0x40 */
	X86_VM_RUN_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, 0, 64ULL);
x86_l_1227:
	/* 0x1227: jne    11e0 <payload_prefix_memcmp_scan_xdp+0xe0> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_11e0;
x86_l_1229:
	/* 0x1229: movabs rax,0x9e3779b97f4a7c16 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, 0, 11400714819323198486ULL);
x86_l_1233:
	/* 0x1233: xor    rdx,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1236:
	/* 0x1236: movzx  eax,BYTE PTR [rcx+0x8b] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 139ULL);
x86_l_123d:
	/* 0x123d: shl    eax,0x8 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 8ULL);
x86_l_1240:
	/* 0x1240: jmp    125d <payload_prefix_memcmp_scan_xdp+0x15d> */
	goto x86_l_125d;
x86_l_1242:
	/* 0x1242: inc    rax */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1245:
	/* 0x1245: mov    eax,eax */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_1247:
	/* 0x1247: lea    rax,[rax+rax*2] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_124b:
	/* 0x124b: lea    rax,[rdx+rax*2] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_124f:
	/* 0x124f: movzx  edx,r8b */
	X86_VM_RUN_OP(x86_exec_movzx_reg, X86_OP_MOVZX_REG, X86_RDX, X86_R8, X86_WIDTH_32, X86_WIDTH_8, 0);
x86_l_1253:
	/* 0x1253: shl    edx,0x8 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 8ULL);
x86_l_1256:
	/* 0x1256: xor    rdx,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1259:
	/* 0x1259: movzx  eax,r9b */
	X86_VM_RUN_OP(x86_exec_movzx_reg, X86_OP_MOVZX_REG, X86_RAX, X86_R9, X86_WIDTH_32, X86_WIDTH_8, 0);
x86_l_125d:
	/* 0x125d: add    rax,rdx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1260:
	/* 0x1260: rol    rax,0x6 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 6ULL);
x86_l_1264:
	/* 0x1264: mov    dil,0x1d */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_8, 0, 29ULL);
x86_l_1267:
	/* 0x1267: mov    r8b,0x4 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_8, 0, 4ULL);
x86_l_126a:
	/* 0x126a: xor    edx,edx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_126c:
	/* 0x126c: nop    DWORD PTR [rax+0x0] */
	X86_VM_RUN_OP(x86_exec_nop, X86_OP_NOP, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1270:
	/* 0x1270: movzx  esi,BYTE PTR [rcx+rdx*1+0x8c] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RDX, 0, X86_WIDTH_8), 140ULL);
x86_l_1278:
	/* 0x1278: lea    r10d,[rdi-0x1d] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_R10, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551587ULL);
x86_l_127c:
	/* 0x127c: lea    r9d,[r8-0x4] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_R9, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551612ULL);
x86_l_1280:
	/* 0x1280: xor    r9b,r10b */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_R10, X86_WIDTH_8, X86_ALU_XOR, 0);
x86_l_1283:
	/* 0x1283: xor    r9b,0xa5 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_8, X86_ALU_XOR, 165ULL);
x86_l_1287:
	/* 0x1287: add    r9b,0x11 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_8, X86_ALU_ADD, 17ULL);
x86_l_128b:
	/* 0x128b: cmp    sil,r9b */
	X86_VM_RUN_OP(x86_exec_cmp_reg, X86_OP_CMP_REG, X86_RSI, X86_R9, X86_WIDTH_8, 0, 0);
x86_l_128e:
	/* 0x128e: jne    12dd <payload_prefix_memcmp_scan_xdp+0x1dd> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_12dd;
x86_l_1290:
	/* 0x1290: movzx  esi,BYTE PTR [rcx+rdx*1+0x8d] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RDX, 0, X86_WIDTH_8), 141ULL);
x86_l_1298:
	/* 0x1298: mov    r9d,edi */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_R9, X86_RDI, X86_WIDTH_32, 0, 0);
x86_l_129b:
	/* 0x129b: xor    r9b,r8b */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_XOR, 0);
x86_l_129e:
	/* 0x129e: xor    r9b,0xa5 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_8, X86_ALU_XOR, 165ULL);
x86_l_12a2:
	/* 0x12a2: add    r9b,0x11 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_8, X86_ALU_ADD, 17ULL);
x86_l_12a6:
	/* 0x12a6: add    rdx,0x2 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_12aa:
	/* 0x12aa: cmp    sil,r9b */
	X86_VM_RUN_OP(x86_exec_cmp_reg, X86_OP_CMP_REG, X86_RSI, X86_R9, X86_WIDTH_8, 0, 0);
x86_l_12ad:
	/* 0x12ad: jne    12e0 <payload_prefix_memcmp_scan_xdp+0x1e0> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_12e0;
x86_l_12af:
	/* 0x12af: add    dil,0x3a */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_8, X86_ALU_ADD, 58ULL);
x86_l_12b3:
	/* 0x12b3: add    r8b,0x8 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_8, X86_ALU_ADD, 8ULL);
x86_l_12b7:
	/* 0x12b7: cmp    rdx,0x40 */
	X86_VM_RUN_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, 0, 64ULL);
x86_l_12bb:
	/* 0x12bb: jne    1270 <payload_prefix_memcmp_scan_xdp+0x170> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_1270;
x86_l_12bd:
	/* 0x12bd: movabs rdx,0x9e3779b97f4a7c16 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, 0, 11400714819323198486ULL);
x86_l_12c7:
	/* 0x12c7: or     rdx,0x1 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_OR, 1ULL);
x86_l_12cb:
	/* 0x12cb: xor    rax,rdx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_12ce:
	/* 0x12ce: movzx  edx,BYTE PTR [rcx+0xcb] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 203ULL);
x86_l_12d5:
	/* 0x12d5: shl    edx,0x10 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 16ULL);
x86_l_12d8:
	/* 0x12d8: add    rdx,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_12db:
	/* 0x12db: jmp    1301 <payload_prefix_memcmp_scan_xdp+0x201> */
	goto x86_l_1301;
x86_l_12dd:
	/* 0x12dd: inc    rdx */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_12e0:
	/* 0x12e0: mov    edx,edx */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RDX, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_12e2:
	/* 0x12e2: lea    rdi,[rdx*8+0x0] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 3), 0ULL);
x86_l_12ea:
	/* 0x12ea: sub    rdi,rdx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_RDX, X86_WIDTH_64, X86_ALU_SUB, 0);
x86_l_12ed:
	/* 0x12ed: add    rax,rdi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_12f0:
	/* 0x12f0: movzx  esi,sil */
	X86_VM_RUN_OP(x86_exec_movzx_reg, X86_OP_MOVZX_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_WIDTH_8, 0);
x86_l_12f4:
	/* 0x12f4: shl    esi,0x10 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 16ULL);
x86_l_12f7:
	/* 0x12f7: xor    rsi,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RSI, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_12fa:
	/* 0x12fa: movzx  edx,r9b */
	X86_VM_RUN_OP(x86_exec_movzx_reg, X86_OP_MOVZX_REG, X86_RDX, X86_R9, X86_WIDTH_32, X86_WIDTH_8, 0);
x86_l_12fe:
	/* 0x12fe: add    rdx,rsi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1301:
	/* 0x1301: rol    rdx,0x7 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 7ULL);
x86_l_1305:
	/* 0x1305: mov    QWORD PTR [rcx],rdx */
	X86_VM_RUN_OP(x86_exec_mov_store_reg, X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1308:
	/* 0x1308: mov    eax,0x2 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_130d:
	/* 0x130d: pop    rbp */
	X86_VM_RUN_OP(x86_exec_pop, X86_OP_POP, X86_RBP, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_130e:
	/* 0x130e: ret */
	X86_VM_RET_RAX();
	return XDP_ABORTED;
}

X86_VM_LICENSE();
