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
	/* 0x110c: jbe    110f <payload_prefix_memcmp_scan_xdp+0xf> */
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
	/* 0x1116: ja     110e <payload_prefix_memcmp_scan_xdp+0xe> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_110e;
x86_l_1118:
	/* 0x1118: lea    rdi,[rcx+0xcc] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_111f:
	/* 0x111f: cmp    rdi,rdx */
	X86_VM_RUN_OP(x86_exec_cmp_reg, X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_1122:
	/* 0x1122: ja     110e <payload_prefix_memcmp_scan_xdp+0xe> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_110e;
x86_l_1124:
	/* 0x1124: cmp    DWORD PTR [rsi],0x3 */
	X86_VM_RUN_OP(x86_exec_cmp_mem_imm, X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 3ULL);
x86_l_1127:
	/* 0x1127: jne    110e <payload_prefix_memcmp_scan_xdp+0xe> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_110e;
x86_l_1129:
	/* 0x1129: mov    dl,0x1d */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, 0, 29ULL);
x86_l_112b:
	/* 0x112b: mov    dil,0x4 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_8, 0, 4ULL);
x86_l_112e:
	/* 0x112e: xor    eax,eax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1130:
	/* 0x1130: movzx  esi,BYTE PTR [rcx+rax*1+0xc] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 12ULL);
x86_l_1135:
	/* 0x1135: lea    r9d,[rdx-0x1d] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_R9, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551587ULL);
x86_l_1139:
	/* 0x1139: lea    r8d,[rdi-0x4] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_R8, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551612ULL);
x86_l_113d:
	/* 0x113d: xor    r8b,r9b */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R8, X86_R9, X86_WIDTH_8, X86_ALU_XOR, 0);
x86_l_1140:
	/* 0x1140: xor    r8b,0xa5 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_8, X86_ALU_XOR, 165ULL);
x86_l_1144:
	/* 0x1144: add    r8b,0x11 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_8, X86_ALU_ADD, 17ULL);
x86_l_1148:
	/* 0x1148: cmp    sil,r8b */
	X86_VM_RUN_OP(x86_exec_cmp_reg, X86_OP_CMP_REG, X86_RSI, X86_R8, X86_WIDTH_8, 0, 0);
x86_l_114b:
	/* 0x114b: jne    1186 <payload_prefix_memcmp_scan_xdp+0x86> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_1186;
x86_l_114d:
	/* 0x114d: movzx  esi,BYTE PTR [rcx+rax*1+0xd] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 13ULL);
x86_l_1152:
	/* 0x1152: mov    r8d,edx */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_R8, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_1155:
	/* 0x1155: xor    r8b,dil */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R8, X86_RDI, X86_WIDTH_8, X86_ALU_XOR, 0);
x86_l_1158:
	/* 0x1158: xor    r8b,0xa5 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_8, X86_ALU_XOR, 165ULL);
x86_l_115c:
	/* 0x115c: add    r8b,0x11 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_8, X86_ALU_ADD, 17ULL);
x86_l_1160:
	/* 0x1160: add    rax,0x2 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_1164:
	/* 0x1164: cmp    sil,r8b */
	X86_VM_RUN_OP(x86_exec_cmp_reg, X86_OP_CMP_REG, X86_RSI, X86_R8, X86_WIDTH_8, 0, 0);
x86_l_1167:
	/* 0x1167: jne    1189 <payload_prefix_memcmp_scan_xdp+0x89> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_1189;
x86_l_1169:
	/* 0x1169: add    dl,0x3a */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_ALU_ADD, 58ULL);
x86_l_116c:
	/* 0x116c: add    dil,0x8 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_8, X86_ALU_ADD, 8ULL);
x86_l_1170:
	/* 0x1170: cmp    rax,0x40 */
	X86_VM_RUN_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, 0, 64ULL);
x86_l_1174:
	/* 0x1174: jne    1130 <payload_prefix_memcmp_scan_xdp+0x30> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_1130;
x86_l_1176:
	/* 0x1176: movzx  eax,BYTE PTR [rcx+0x4b] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 75ULL);
x86_l_117a:
	/* 0x117a: movabs rdx,0xf43e9fde8cf6b51c */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, 0, 17599680172007011612ULL);
x86_l_1184:
	/* 0x1184: jmp    11a7 <payload_prefix_memcmp_scan_xdp+0xa7> */
	goto x86_l_11a7;
x86_l_1186:
	/* 0x1186: inc    rax */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1189:
	/* 0x1189: mov    eax,eax */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_118b:
	/* 0x118b: lea    rax,[rax+rax*4] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 2), 0ULL);
x86_l_118f:
	/* 0x118f: movabs rdx,0x6a09e667f3bcc909 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, 0, 7640891576956012809ULL);
x86_l_1199:
	/* 0x1199: add    rdx,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_119c:
	/* 0x119c: movzx  eax,sil */
	X86_VM_RUN_OP(x86_exec_movzx_reg, X86_OP_MOVZX_REG, X86_RAX, X86_RSI, X86_WIDTH_32, X86_WIDTH_8, 0);
x86_l_11a0:
	/* 0x11a0: xor    rax,rdx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_11a3:
	/* 0x11a3: movzx  edx,r8b */
	X86_VM_RUN_OP(x86_exec_movzx_reg, X86_OP_MOVZX_REG, X86_RDX, X86_R8, X86_WIDTH_32, X86_WIDTH_8, 0);
x86_l_11a7:
	/* 0x11a7: add    rdx,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_11aa:
	/* 0x11aa: rol    rdx,0x5 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 5ULL);
x86_l_11ae:
	/* 0x11ae: mov    sil,0x1d */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, 0, 29ULL);
x86_l_11b1:
	/* 0x11b1: mov    dil,0x4 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_8, 0, 4ULL);
x86_l_11b4:
	/* 0x11b4: xor    eax,eax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_11b6:
	/* 0x11b6: cs nop WORD PTR [rax+rax*1+0x0] */
	X86_VM_RUN_OP(x86_exec_nop, X86_OP_NOP, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_11c0:
	/* 0x11c0: movzx  r8d,BYTE PTR [rcx+rax*1+0x4c] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R8, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 76ULL);
x86_l_11c6:
	/* 0x11c6: lea    r10d,[rsi-0x1d] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_R10, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551587ULL);
x86_l_11ca:
	/* 0x11ca: lea    r9d,[rdi-0x4] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_R9, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551612ULL);
x86_l_11ce:
	/* 0x11ce: xor    r9b,r10b */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_R10, X86_WIDTH_8, X86_ALU_XOR, 0);
x86_l_11d1:
	/* 0x11d1: xor    r9b,0xa5 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_8, X86_ALU_XOR, 165ULL);
x86_l_11d5:
	/* 0x11d5: add    r9b,0x11 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_8, X86_ALU_ADD, 17ULL);
x86_l_11d9:
	/* 0x11d9: cmp    r8b,r9b */
	X86_VM_RUN_OP(x86_exec_cmp_reg, X86_OP_CMP_REG, X86_R8, X86_R9, X86_WIDTH_8, 0, 0);
x86_l_11dc:
	/* 0x11dc: jne    1222 <payload_prefix_memcmp_scan_xdp+0x122> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_1222;
x86_l_11de:
	/* 0x11de: movzx  r8d,BYTE PTR [rcx+rax*1+0x4d] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R8, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 77ULL);
x86_l_11e4:
	/* 0x11e4: mov    r9d,esi */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_R9, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_11e7:
	/* 0x11e7: xor    r9b,dil */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_RDI, X86_WIDTH_8, X86_ALU_XOR, 0);
x86_l_11ea:
	/* 0x11ea: xor    r9b,0xa5 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_8, X86_ALU_XOR, 165ULL);
x86_l_11ee:
	/* 0x11ee: add    r9b,0x11 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_8, X86_ALU_ADD, 17ULL);
x86_l_11f2:
	/* 0x11f2: add    rax,0x2 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_11f6:
	/* 0x11f6: cmp    r8b,r9b */
	X86_VM_RUN_OP(x86_exec_cmp_reg, X86_OP_CMP_REG, X86_R8, X86_R9, X86_WIDTH_8, 0, 0);
x86_l_11f9:
	/* 0x11f9: jne    1225 <payload_prefix_memcmp_scan_xdp+0x125> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_1225;
x86_l_11fb:
	/* 0x11fb: add    sil,0x3a */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_ALU_ADD, 58ULL);
x86_l_11ff:
	/* 0x11ff: add    dil,0x8 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_8, X86_ALU_ADD, 8ULL);
x86_l_1203:
	/* 0x1203: cmp    rax,0x40 */
	X86_VM_RUN_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, 0, 64ULL);
x86_l_1207:
	/* 0x1207: jne    11c0 <payload_prefix_memcmp_scan_xdp+0xc0> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_11c0;
x86_l_1209:
	/* 0x1209: movabs rax,0x9e3779b97f4a7c16 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, 0, 11400714819323198486ULL);
x86_l_1213:
	/* 0x1213: xor    rdx,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1216:
	/* 0x1216: movzx  eax,BYTE PTR [rcx+0x8b] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 139ULL);
x86_l_121d:
	/* 0x121d: shl    eax,0x8 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 8ULL);
x86_l_1220:
	/* 0x1220: jmp    123d <payload_prefix_memcmp_scan_xdp+0x13d> */
	goto x86_l_123d;
x86_l_1222:
	/* 0x1222: inc    rax */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1225:
	/* 0x1225: mov    eax,eax */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_1227:
	/* 0x1227: lea    rax,[rax+rax*2] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_122b:
	/* 0x122b: lea    rax,[rdx+rax*2] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_122f:
	/* 0x122f: movzx  edx,r8b */
	X86_VM_RUN_OP(x86_exec_movzx_reg, X86_OP_MOVZX_REG, X86_RDX, X86_R8, X86_WIDTH_32, X86_WIDTH_8, 0);
x86_l_1233:
	/* 0x1233: shl    edx,0x8 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 8ULL);
x86_l_1236:
	/* 0x1236: xor    rdx,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1239:
	/* 0x1239: movzx  eax,r9b */
	X86_VM_RUN_OP(x86_exec_movzx_reg, X86_OP_MOVZX_REG, X86_RAX, X86_R9, X86_WIDTH_32, X86_WIDTH_8, 0);
x86_l_123d:
	/* 0x123d: add    rax,rdx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1240:
	/* 0x1240: rol    rax,0x6 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 6ULL);
x86_l_1244:
	/* 0x1244: mov    dil,0x1d */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_8, 0, 29ULL);
x86_l_1247:
	/* 0x1247: mov    r8b,0x4 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_8, 0, 4ULL);
x86_l_124a:
	/* 0x124a: xor    edx,edx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_124c:
	/* 0x124c: nop    DWORD PTR [rax+0x0] */
	X86_VM_RUN_OP(x86_exec_nop, X86_OP_NOP, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1250:
	/* 0x1250: movzx  esi,BYTE PTR [rcx+rdx*1+0x8c] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RDX, 0, X86_WIDTH_8), 140ULL);
x86_l_1258:
	/* 0x1258: lea    r10d,[rdi-0x1d] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_R10, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551587ULL);
x86_l_125c:
	/* 0x125c: lea    r9d,[r8-0x4] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_R9, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551612ULL);
x86_l_1260:
	/* 0x1260: xor    r9b,r10b */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_R10, X86_WIDTH_8, X86_ALU_XOR, 0);
x86_l_1263:
	/* 0x1263: xor    r9b,0xa5 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_8, X86_ALU_XOR, 165ULL);
x86_l_1267:
	/* 0x1267: add    r9b,0x11 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_8, X86_ALU_ADD, 17ULL);
x86_l_126b:
	/* 0x126b: cmp    sil,r9b */
	X86_VM_RUN_OP(x86_exec_cmp_reg, X86_OP_CMP_REG, X86_RSI, X86_R9, X86_WIDTH_8, 0, 0);
x86_l_126e:
	/* 0x126e: jne    12bd <payload_prefix_memcmp_scan_xdp+0x1bd> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_12bd;
x86_l_1270:
	/* 0x1270: movzx  esi,BYTE PTR [rcx+rdx*1+0x8d] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RDX, 0, X86_WIDTH_8), 141ULL);
x86_l_1278:
	/* 0x1278: mov    r9d,edi */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_R9, X86_RDI, X86_WIDTH_32, 0, 0);
x86_l_127b:
	/* 0x127b: xor    r9b,r8b */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_XOR, 0);
x86_l_127e:
	/* 0x127e: xor    r9b,0xa5 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_8, X86_ALU_XOR, 165ULL);
x86_l_1282:
	/* 0x1282: add    r9b,0x11 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_8, X86_ALU_ADD, 17ULL);
x86_l_1286:
	/* 0x1286: add    rdx,0x2 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_128a:
	/* 0x128a: cmp    sil,r9b */
	X86_VM_RUN_OP(x86_exec_cmp_reg, X86_OP_CMP_REG, X86_RSI, X86_R9, X86_WIDTH_8, 0, 0);
x86_l_128d:
	/* 0x128d: jne    12c0 <payload_prefix_memcmp_scan_xdp+0x1c0> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_12c0;
x86_l_128f:
	/* 0x128f: add    dil,0x3a */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_8, X86_ALU_ADD, 58ULL);
x86_l_1293:
	/* 0x1293: add    r8b,0x8 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_8, X86_ALU_ADD, 8ULL);
x86_l_1297:
	/* 0x1297: cmp    rdx,0x40 */
	X86_VM_RUN_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, 0, 64ULL);
x86_l_129b:
	/* 0x129b: jne    1250 <payload_prefix_memcmp_scan_xdp+0x150> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_1250;
x86_l_129d:
	/* 0x129d: movabs rdx,0x9e3779b97f4a7c16 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, 0, 11400714819323198486ULL);
x86_l_12a7:
	/* 0x12a7: or     rdx,0x1 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_OR, 1ULL);
x86_l_12ab:
	/* 0x12ab: xor    rax,rdx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_12ae:
	/* 0x12ae: movzx  edx,BYTE PTR [rcx+0xcb] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 203ULL);
x86_l_12b5:
	/* 0x12b5: shl    edx,0x10 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 16ULL);
x86_l_12b8:
	/* 0x12b8: add    rdx,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_12bb:
	/* 0x12bb: jmp    12e1 <payload_prefix_memcmp_scan_xdp+0x1e1> */
	goto x86_l_12e1;
x86_l_12bd:
	/* 0x12bd: inc    rdx */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_12c0:
	/* 0x12c0: mov    edx,edx */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RDX, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_12c2:
	/* 0x12c2: lea    rdi,[rdx*8+0x0] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 3), 0ULL);
x86_l_12ca:
	/* 0x12ca: sub    rdi,rdx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_RDX, X86_WIDTH_64, X86_ALU_SUB, 0);
x86_l_12cd:
	/* 0x12cd: add    rax,rdi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_12d0:
	/* 0x12d0: movzx  esi,sil */
	X86_VM_RUN_OP(x86_exec_movzx_reg, X86_OP_MOVZX_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_WIDTH_8, 0);
x86_l_12d4:
	/* 0x12d4: shl    esi,0x10 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 16ULL);
x86_l_12d7:
	/* 0x12d7: xor    rsi,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RSI, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_12da:
	/* 0x12da: movzx  edx,r9b */
	X86_VM_RUN_OP(x86_exec_movzx_reg, X86_OP_MOVZX_REG, X86_RDX, X86_R9, X86_WIDTH_32, X86_WIDTH_8, 0);
x86_l_12de:
	/* 0x12de: add    rdx,rsi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_12e1:
	/* 0x12e1: rol    rdx,0x7 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 7ULL);
x86_l_12e5:
	/* 0x12e5: mov    QWORD PTR [rcx],rdx */
	X86_VM_RUN_OP(x86_exec_mov_store_reg, X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12e8:
	/* 0x12e8: mov    eax,0x2 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_12ed:
	/* 0x12ed: ret */
	X86_VM_RET_RAX();
	return XDP_ABORTED;
}

X86_VM_LICENSE();
