#define X86_SIM_ENABLE_STACK 1
#include "../x86_sim_bpf.h"

SEC("xdp")
int tc_packet_checksum_fold_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_DECLARE_XDP(ctx);
x86_l_1100:
	/* 0x1100: push   rbp */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_1101:
	/* 0x1101: mov    rbp,rsp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RBP, X86_RSP, X86_WIDTH_64, 0, 0);
x86_l_1104:
	/* 0x1104: mov    rdx,QWORD PTR [rdi+0xd0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_110b:
	/* 0x110b: mov    esi,DWORD PTR [rdi+0x70] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_110e:
	/* 0x110e: add    rsi,rdx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1111:
	/* 0x1111: mov    rax,rdx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_1114:
	/* 0x1114: mov    r8,rsi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R8, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_1117:
	/* 0x1117: cmp    rax,r8 */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RAX, X86_R8, X86_WIDTH_64, 0, 0);
x86_l_111a:
	/* 0x111a: jbe    1124 <tc_packet_checksum_fold_prog+0x24> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x111a, 0x1124, x86_l_1124);
x86_l_111c:
	/* 0x111c: mov    rcx,rdx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_111f:
	/* 0x111f: jmp    1214 <tc_packet_checksum_fold_prog+0x114> */
	X86_SIM_X86_JMP(0x111f, 0x1214, x86_l_1214);
x86_l_1124:
	/* 0x1124: lea    rcx,[rax+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1128:
	/* 0x1128: cmp    rcx,r8 */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RCX, X86_R8, X86_WIDTH_64, 0, 0);
x86_l_112b:
	/* 0x112b: ja     111c <tc_packet_checksum_fold_prog+0x1c> */
	X86_SIM_X86_JCC(X86_CC_A, 0x112b, 0x111c, x86_l_111c);
x86_l_112d:
	/* 0x112d: lea    rdi,[rax+0x410] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1040ULL);
x86_l_1134:
	/* 0x1134: cmp    rdi,r8 */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RDI, X86_R8, X86_WIDTH_64, 0, 0);
x86_l_1137:
	/* 0x1137: ja     111c <tc_packet_checksum_fold_prog+0x1c> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1137, 0x111c, x86_l_111c);
x86_l_1139:
	/* 0x1139: mov    r8,rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R8, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_113c:
	/* 0x113c: mov    r9,rdi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R9, X86_RDI, X86_WIDTH_64, 0, 0);
x86_l_113f:
	/* 0x113f: cmp    r8,r9 */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_R8, X86_R9, X86_WIDTH_64, 0, 0);
x86_l_1142:
	/* 0x1142: ja     1211 <tc_packet_checksum_fold_prog+0x111> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1142, 0x1211, x86_l_1211);
x86_l_1148:
	/* 0x1148: add    r8,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_114c:
	/* 0x114c: cmp    r8,r9 */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_R8, X86_R9, X86_WIDTH_64, 0, 0);
x86_l_114f:
	/* 0x114f: ja     1211 <tc_packet_checksum_fold_prog+0x111> */
	X86_SIM_X86_JCC(X86_CC_A, 0x114f, 0x1211, x86_l_1211);
x86_l_1155:
	/* 0x1155: cmp    DWORD PTR [rax+0x8],0x20 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738400ULL);
x86_l_1159:
	/* 0x1159: jne    1211 <tc_packet_checksum_fold_prog+0x111> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1159, 0x1211, x86_l_1211);
x86_l_115f:
	/* 0x115f: cmp    DWORD PTR [rax+0xc],0x200 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539608064ULL);
x86_l_1166:
	/* 0x1166: jne    1211 <tc_packet_checksum_fold_prog+0x111> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1166, 0x1211, x86_l_1211);
x86_l_116c:
	/* 0x116c: lea    r8,[rcx+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R8, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1170:
	/* 0x1170: cmp    r8,rdi */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_R8, X86_RDI, X86_WIDTH_64, 0, 0);
x86_l_1173:
	/* 0x1173: ja     1211 <tc_packet_checksum_fold_prog+0x111> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1173, 0x1211, x86_l_1211);
x86_l_1179:
	/* 0x1179: add    rcx,0x408 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 1032ULL);
x86_l_1180:
	/* 0x1180: cmp    rcx,rdi */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RCX, X86_RDI, X86_WIDTH_64, 0, 0);
x86_l_1183:
	/* 0x1183: ja     1211 <tc_packet_checksum_fold_prog+0x111> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1183, 0x1211, x86_l_1211);
x86_l_1189:
	/* 0x1189: xor    r8d,r8d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_118c:
	/* 0x118c: xor    edi,edi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_118e:
	/* 0x118e: xchg   ax,ax */
	X86_SIM_RUN_OP(X86_OP_XCHG, X86_RAX, X86_RAX, X86_WIDTH_16, 0, 0);
x86_l_1190:
	/* 0x1190: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1192:
	/* 0x1192: xor    r9d,r9d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_R9, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1195:
	/* 0x1195: data16 cs nop WORD PTR [rax+rax*1+0x0] */
	X86_SIM_RUN_OP(X86_OP_NOP, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_11a0:
	/* 0x11a0: movzx  r10d,WORD PTR [rax+rcx*2+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R10, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 1, X86_WIDTH_16), 16ULL);
x86_l_11a6:
	/* 0x11a6: add    r10d,r9d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R10, X86_R9, X86_WIDTH_32, X86_ALU_ADD, 0);
x86_l_11a9:
	/* 0x11a9: movzx  r9d,r10w */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_R9, X86_R10, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_11ad:
	/* 0x11ad: shr    r10d,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_11b1:
	/* 0x11b1: add    r10d,r9d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R10, X86_R9, X86_WIDTH_32, X86_ALU_ADD, 0);
x86_l_11b4:
	/* 0x11b4: movzx  r9d,WORD PTR [rax+rcx*2+0x12] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R9, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 1, X86_WIDTH_16), 18ULL);
x86_l_11ba:
	/* 0x11ba: add    r9d,r10d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_R10, X86_WIDTH_32, X86_ALU_ADD, 0);
x86_l_11bd:
	/* 0x11bd: movzx  r10d,r9w */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_R10, X86_R9, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_11c1:
	/* 0x11c1: shr    r9d,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_11c5:
	/* 0x11c5: add    r9d,r10d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_R10, X86_WIDTH_32, X86_ALU_ADD, 0);
x86_l_11c8:
	/* 0x11c8: add    rcx,0x2 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_11cc:
	/* 0x11cc: cmp    rcx,0x200 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, 0, 512ULL);
x86_l_11d3:
	/* 0x11d3: jne    11a0 <tc_packet_checksum_fold_prog+0xa0> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x11d3, 0x11a0, x86_l_11a0);
x86_l_11d5:
	/* 0x11d5: mov    ecx,r9d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_R9, X86_WIDTH_32, 0, 0);
x86_l_11d8:
	/* 0x11d8: shr    ecx,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_11db:
	/* 0x11db: add    ecx,r9d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_R9, X86_WIDTH_32, X86_ALU_ADD, 0);
x86_l_11de:
	/* 0x11de: not    ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_11e0:
	/* 0x11e0: movzx  r9d,cx */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_R9, X86_RCX, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_11e4:
	/* 0x11e4: mov    ecx,r8d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_R8, X86_WIDTH_32, 0, 0);
x86_l_11e7:
	/* 0x11e7: shl    ecx,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 4ULL);
x86_l_11ea:
	/* 0x11ea: shl    r9,cl */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 0);
x86_l_11ed:
	/* 0x11ed: xor    rdi,r9 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDI, X86_R9, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_11f0:
	/* 0x11f0: inc    r8d */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_11f3:
	/* 0x11f3: cmp    r8d,0x20 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, 0, 32ULL);
x86_l_11f7:
	/* 0x11f7: jne    1190 <tc_packet_checksum_fold_prog+0x90> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x11f7, 0x1190, x86_l_1190);
x86_l_11f9:
	/* 0x11f9: mov    rcx,rdx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_11fc:
	/* 0x11fc: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_11fe:
	/* 0x11fe: cmp    rcx,rsi */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RCX, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_1201:
	/* 0x1201: ja     122e <tc_packet_checksum_fold_prog+0x12e> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1201, 0x122e, x86_l_122e);
x86_l_1203:
	/* 0x1203: add    rcx,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1207:
	/* 0x1207: cmp    rcx,rsi */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RCX, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_120a:
	/* 0x120a: ja     122e <tc_packet_checksum_fold_prog+0x12e> */
	X86_SIM_X86_JCC(X86_CC_A, 0x120a, 0x122e, x86_l_122e);
x86_l_120c:
	/* 0x120c: mov    QWORD PTR [rdx],rdi */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_120f:
	/* 0x120f: pop    rbp */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBP, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1210:
	/* 0x1210: ret */
	X86_SIM_X86_RET();
x86_l_1211:
	/* 0x1211: mov    rcx,rdx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_1214:
	/* 0x1214: mov    eax,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_1219:
	/* 0x1219: cmp    rcx,rsi */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RCX, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_121c:
	/* 0x121c: ja     122e <tc_packet_checksum_fold_prog+0x12e> */
	X86_SIM_X86_JCC(X86_CC_A, 0x121c, 0x122e, x86_l_122e);
x86_l_121e:
	/* 0x121e: add    rcx,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1222:
	/* 0x1222: cmp    rcx,rsi */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RCX, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_1225:
	/* 0x1225: ja     122e <tc_packet_checksum_fold_prog+0x12e> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1225, 0x122e, x86_l_122e);
x86_l_1227:
	/* 0x1227: mov    QWORD PTR [rdx],0xffffffffffffffff */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4294967295ULL);
x86_l_122e:
	/* 0x122e: pop    rbp */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBP, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_122f:
	/* 0x122f: ret */
	X86_SIM_X86_RET();
	__builtin_unreachable();
}

X86_SIM_LICENSE();
