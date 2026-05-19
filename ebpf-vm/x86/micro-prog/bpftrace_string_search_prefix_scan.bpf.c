#define X86_VM_ENABLE_STACK 1
#define X86_VM_ENABLE_STACK_SLOT7 1
#define X86_VM_ENABLE_STACK_SLOT8 1
#define X86_VM_ENABLE_STACK_DEEP 1
#define X86_VM_ENABLE_STACK_EXT 1
#include "../x86_vm_bpf.h"

SEC("xdp")
int bpftrace_string_search_prefix_scan_x86_vm_xdp(struct xdp_md *ctx)
{
	X86_VM_DECLARE_XDP(ctx);
x86_l_1100:
	/* 0x1100: mov    rcx,QWORD PTR [rdi] */
	X86_VM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1103:
	/* 0x1103: mov    rsi,QWORD PTR [rdi+0x8] */
	X86_VM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1107:
	/* 0x1107: mov    rdx,rcx */
	X86_VM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_110a:
	/* 0x110a: xor    eax,eax */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_110c:
	/* 0x110c: cmp    rdx,rsi */
	X86_VM_RUN_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_110f:
	/* 0x110f: ja     12d1 <bpftrace_string_search_prefix_scan_xdp+0x1d1> */
	X86_VM_X86_JCC(X86_CC_A, 0x110f, 0x12d1, x86_l_12d1);
x86_l_1115:
	/* 0x1115: lea    rdi,[rdx+0x8] */
	X86_VM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1119:
	/* 0x1119: cmp    rdi,rsi */
	X86_VM_RUN_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_111c:
	/* 0x111c: ja     12d1 <bpftrace_string_search_prefix_scan_xdp+0x1d1> */
	X86_VM_X86_JCC(X86_CC_A, 0x111c, 0x12d1, x86_l_12d1);
x86_l_1122:
	/* 0x1122: lea    rdi,[rdx+0x78] */
	X86_VM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1126:
	/* 0x1126: cmp    rdi,rsi */
	X86_VM_RUN_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_1129:
	/* 0x1129: ja     12d1 <bpftrace_string_search_prefix_scan_xdp+0x1d1> */
	X86_VM_X86_JCC(X86_CC_A, 0x1129, 0x12d1, x86_l_12d1);
x86_l_112f:
	/* 0x112f: push   rbp */
	X86_VM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_1130:
	/* 0x1130: mov    rbp,rsp */
	X86_VM_RUN_OP(X86_OP_MOV_REG, X86_RBP, X86_RSP, X86_WIDTH_64, 0, 0);
x86_l_1133:
	/* 0x1133: push   r14 */
	X86_VM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_1135:
	/* 0x1135: push   rbx */
	X86_VM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_1136:
	/* 0x1136: mov    r8d,DWORD PTR [rdx+0x8] */
	X86_VM_RUN_OP(X86_OP_MOV_LOAD, X86_R8, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_113a:
	/* 0x113a: movzx  esi,BYTE PTR [rdx+0x70] */
	X86_VM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 112ULL);
x86_l_113e:
	/* 0x113e: xor    eax,eax */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1140:
	/* 0x1140: mov    r9d,0x0 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_32, 0, 0ULL);
x86_l_1146:
	/* 0x1146: test   sil,sil */
	X86_VM_RUN_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_8, 0, 0);
x86_l_1149:
	/* 0x1149: je     11ad <bpftrace_string_search_prefix_scan_xdp+0xad> */
	X86_VM_X86_JCC(X86_CC_E, 0x1149, 0x11ad, x86_l_11ad);
x86_l_114b:
	/* 0x114b: cmp    BYTE PTR [rdx+0x71],0x0 */
	X86_VM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 485331304448ULL);
x86_l_114f:
	/* 0x114f: je     117f <bpftrace_string_search_prefix_scan_xdp+0x7f> */
	X86_VM_X86_JCC(X86_CC_E, 0x114f, 0x117f, x86_l_117f);
x86_l_1151:
	/* 0x1151: cmp    BYTE PTR [rdx+0x72],0x0 */
	X86_VM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 489626271744ULL);
x86_l_1155:
	/* 0x1155: je     1187 <bpftrace_string_search_prefix_scan_xdp+0x87> */
	X86_VM_X86_JCC(X86_CC_E, 0x1155, 0x1187, x86_l_1187);
x86_l_1157:
	/* 0x1157: cmp    BYTE PTR [rdx+0x73],0x0 */
	X86_VM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 493921239040ULL);
x86_l_115b:
	/* 0x115b: je     118f <bpftrace_string_search_prefix_scan_xdp+0x8f> */
	X86_VM_X86_JCC(X86_CC_E, 0x115b, 0x118f, x86_l_118f);
x86_l_115d:
	/* 0x115d: cmp    BYTE PTR [rdx+0x74],0x0 */
	X86_VM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 498216206336ULL);
x86_l_1161:
	/* 0x1161: je     1197 <bpftrace_string_search_prefix_scan_xdp+0x97> */
	X86_VM_X86_JCC(X86_CC_E, 0x1161, 0x1197, x86_l_1197);
x86_l_1163:
	/* 0x1163: cmp    BYTE PTR [rdx+0x75],0x0 */
	X86_VM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 502511173632ULL);
x86_l_1167:
	/* 0x1167: je     119f <bpftrace_string_search_prefix_scan_xdp+0x9f> */
	X86_VM_X86_JCC(X86_CC_E, 0x1167, 0x119f, x86_l_119f);
x86_l_1169:
	/* 0x1169: cmp    BYTE PTR [rdx+0x76],0x0 */
	X86_VM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 506806140928ULL);
x86_l_116d:
	/* 0x116d: je     11a7 <bpftrace_string_search_prefix_scan_xdp+0xa7> */
	X86_VM_X86_JCC(X86_CC_E, 0x116d, 0x11a7, x86_l_11a7);
x86_l_116f:
	/* 0x116f: cmp    BYTE PTR [rdx+0x77],0x1 */
	X86_VM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 511101108225ULL);
x86_l_1173:
	/* 0x1173: mov    r9d,0x8 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_1179:
	/* 0x1179: sbb    r9d,0x0 */
	X86_VM_RUN_OP(X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SBB, 0ULL);
x86_l_117d:
	/* 0x117d: jmp    11ad <bpftrace_string_search_prefix_scan_xdp+0xad> */
	X86_VM_X86_JMP(0x117d, 0x11ad, x86_l_11ad);
x86_l_117f:
	/* 0x117f: mov    r9d,0x1 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_1185:
	/* 0x1185: jmp    11ad <bpftrace_string_search_prefix_scan_xdp+0xad> */
	X86_VM_X86_JMP(0x1185, 0x11ad, x86_l_11ad);
x86_l_1187:
	/* 0x1187: mov    r9d,0x2 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_118d:
	/* 0x118d: jmp    11ad <bpftrace_string_search_prefix_scan_xdp+0xad> */
	X86_VM_X86_JMP(0x118d, 0x11ad, x86_l_11ad);
x86_l_118f:
	/* 0x118f: mov    r9d,0x3 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_32, 0, 3ULL);
x86_l_1195:
	/* 0x1195: jmp    11ad <bpftrace_string_search_prefix_scan_xdp+0xad> */
	X86_VM_X86_JMP(0x1195, 0x11ad, x86_l_11ad);
x86_l_1197:
	/* 0x1197: mov    r9d,0x4 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_119d:
	/* 0x119d: jmp    11ad <bpftrace_string_search_prefix_scan_xdp+0xad> */
	X86_VM_X86_JMP(0x119d, 0x11ad, x86_l_11ad);
x86_l_119f:
	/* 0x119f: mov    r9d,0x5 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_32, 0, 5ULL);
x86_l_11a5:
	/* 0x11a5: jmp    11ad <bpftrace_string_search_prefix_scan_xdp+0xad> */
	X86_VM_X86_JMP(0x11a5, 0x11ad, x86_l_11ad);
x86_l_11a7:
	/* 0x11a7: mov    r9d,0x6 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_32, 0, 6ULL);
x86_l_11ad:
	/* 0x11ad: cmp    r8d,0x60 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, 0, 96ULL);
x86_l_11b1:
	/* 0x11b1: ja     12cd <bpftrace_string_search_prefix_scan_xdp+0x1cd> */
	X86_VM_X86_JCC(X86_CC_A, 0x11b1, 0x12cd, x86_l_12cd);
x86_l_11b7:
	/* 0x11b7: mov    edi,DWORD PTR [rdx+0xc] */
	X86_VM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_11ba:
	/* 0x11ba: cmp    edi,r9d */
	X86_VM_RUN_OP(X86_OP_CMP_REG, X86_RDI, X86_R9, X86_WIDTH_32, 0, 0);
x86_l_11bd:
	/* 0x11bd: jne    12cd <bpftrace_string_search_prefix_scan_xdp+0x1cd> */
	X86_VM_X86_JCC(X86_CC_NE, 0x11bd, 0x12cd, x86_l_12cd);
x86_l_11c3:
	/* 0x11c3: test   sil,sil */
	X86_VM_RUN_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_8, 0, 0);
x86_l_11c6:
	/* 0x11c6: je     12cd <bpftrace_string_search_prefix_scan_xdp+0x1cd> */
	X86_VM_X86_JCC(X86_CC_E, 0x11c6, 0x12cd, x86_l_12cd);
x86_l_11cc:
	/* 0x11cc: movabs rax,0x4f82338baed89116 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, 0, 5729198350995591446ULL);
x86_l_11d6:
	/* 0x11d6: mov    r10d,r8d */
	X86_VM_RUN_OP(X86_OP_MOV_REG, X86_R10, X86_R8, X86_WIDTH_32, 0, 0);
x86_l_11d9:
	/* 0x11d9: lea    r11d,[rdi+0x3] */
	X86_VM_RUN_OP(X86_OP_LEA, X86_R11, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 3ULL);
x86_l_11dd:
	/* 0x11dd: movabs r8,0xd1b54a32d192ed03 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_64, 0, 15111065706836454659ULL);
x86_l_11e7:
	/* 0x11e7: add    r8,r11 */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_R8, X86_R11, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_11ea:
	/* 0x11ea: xor    r9d,r9d */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_R9, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_11ed:
	/* 0x11ed: jmp    1208 <bpftrace_string_search_prefix_scan_xdp+0x108> */
	X86_VM_X86_JMP(0x11ed, 0x1208, x86_l_1208);
x86_l_11ef:
	/* 0x11ef: nop */
	X86_VM_RUN_OP(X86_OP_NOP, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_11f0:
	/* 0x11f0: test   bl,bl */
	X86_VM_RUN_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_8, 0, 0);
x86_l_11f2:
	/* 0x11f2: je     12ae <bpftrace_string_search_prefix_scan_xdp+0x1ae> */
	X86_VM_X86_JCC(X86_CC_E, 0x11f2, 0x12ae, x86_l_12ae);
x86_l_11f8:
	/* 0x11f8: inc    r9 */
	X86_VM_RUN_OP(X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_11fb:
	/* 0x11fb: add    r8,r11 */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_R8, X86_R11, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_11fe:
	/* 0x11fe: cmp    r9,0x59 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_64, 0, 89ULL);
x86_l_1202:
	/* 0x1202: je     12c5 <bpftrace_string_search_prefix_scan_xdp+0x1c5> */
	X86_VM_X86_JCC(X86_CC_E, 0x1202, 0x12c5, x86_l_12c5);
x86_l_1208:
	/* 0x1208: lea    rbx,[rdi+r9*1] */
	X86_VM_RUN_OP(X86_OP_LEA, X86_RBX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_120c:
	/* 0x120c: cmp    rbx,r10 */
	X86_VM_RUN_OP(X86_OP_CMP_REG, X86_RBX, X86_R10, X86_WIDTH_64, 0, 0);
x86_l_120f:
	/* 0x120f: ja     11f8 <bpftrace_string_search_prefix_scan_xdp+0xf8> */
	X86_VM_X86_JCC(X86_CC_A, 0x120f, 0x11f8, x86_l_11f8);
x86_l_1211:
	/* 0x1211: test   rdi,rdi */
	X86_VM_RUN_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_64, 0, 0);
x86_l_1214:
	/* 0x1214: je     12ae <bpftrace_string_search_prefix_scan_xdp+0x1ae> */
	X86_VM_X86_JCC(X86_CC_E, 0x1214, 0x12ae, x86_l_12ae);
x86_l_121a:
	/* 0x121a: movzx  ebx,BYTE PTR [rdx+r9*1+0x10] */
	X86_VM_RUN_OP(X86_OP_MOV_LOAD, X86_RBX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R9, 0, X86_WIDTH_8), 16ULL);
x86_l_1220:
	/* 0x1220: xor    bl,sil */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_RBX, X86_RSI, X86_WIDTH_8, X86_ALU_XOR, 0);
x86_l_1223:
	/* 0x1223: cmp    edi,0x2 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_1226:
	/* 0x1226: jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0> */
	X86_VM_X86_JCC(X86_CC_B, 0x1226, 0x11f0, x86_l_11f0);
x86_l_1228:
	/* 0x1228: movzx  r14d,BYTE PTR [rdx+0x71] */
	X86_VM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 113ULL);
x86_l_122d:
	/* 0x122d: xor    r14b,BYTE PTR [rdx+r9*1+0x11] */
	X86_VM_RUN_OP(X86_OP_ALU_MEM, X86_R14, X86_RDX, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_R9, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 17ULL);
x86_l_1232:
	/* 0x1232: or     bl,r14b */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_RBX, X86_R14, X86_WIDTH_8, X86_ALU_OR, 0);
x86_l_1235:
	/* 0x1235: cmp    edi,0x3 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 3ULL);
x86_l_1238:
	/* 0x1238: jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0> */
	X86_VM_X86_JCC(X86_CC_B, 0x1238, 0x11f0, x86_l_11f0);
x86_l_123a:
	/* 0x123a: movzx  r14d,BYTE PTR [rdx+0x72] */
	X86_VM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 114ULL);
x86_l_123f:
	/* 0x123f: xor    r14b,BYTE PTR [rdx+r9*1+0x12] */
	X86_VM_RUN_OP(X86_OP_ALU_MEM, X86_R14, X86_RDX, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_R9, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 18ULL);
x86_l_1244:
	/* 0x1244: or     bl,r14b */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_RBX, X86_R14, X86_WIDTH_8, X86_ALU_OR, 0);
x86_l_1247:
	/* 0x1247: cmp    edi,0x4 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_124a:
	/* 0x124a: jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0> */
	X86_VM_X86_JCC(X86_CC_B, 0x124a, 0x11f0, x86_l_11f0);
x86_l_124c:
	/* 0x124c: movzx  r14d,BYTE PTR [rdx+0x73] */
	X86_VM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 115ULL);
x86_l_1251:
	/* 0x1251: xor    r14b,BYTE PTR [rdx+r9*1+0x13] */
	X86_VM_RUN_OP(X86_OP_ALU_MEM, X86_R14, X86_RDX, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_R9, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 19ULL);
x86_l_1256:
	/* 0x1256: or     bl,r14b */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_RBX, X86_R14, X86_WIDTH_8, X86_ALU_OR, 0);
x86_l_1259:
	/* 0x1259: cmp    edi,0x5 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 5ULL);
x86_l_125c:
	/* 0x125c: jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0> */
	X86_VM_X86_JCC(X86_CC_B, 0x125c, 0x11f0, x86_l_11f0);
x86_l_125e:
	/* 0x125e: movzx  r14d,BYTE PTR [rdx+0x74] */
	X86_VM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 116ULL);
x86_l_1263:
	/* 0x1263: xor    r14b,BYTE PTR [rdx+r9*1+0x14] */
	X86_VM_RUN_OP(X86_OP_ALU_MEM, X86_R14, X86_RDX, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_R9, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 20ULL);
x86_l_1268:
	/* 0x1268: or     bl,r14b */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_RBX, X86_R14, X86_WIDTH_8, X86_ALU_OR, 0);
x86_l_126b:
	/* 0x126b: cmp    edi,0x6 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 6ULL);
x86_l_126e:
	/* 0x126e: jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0> */
	X86_VM_X86_JCC(X86_CC_B, 0x126e, 0x11f0, x86_l_11f0);
x86_l_1270:
	/* 0x1270: movzx  r14d,BYTE PTR [rdx+0x75] */
	X86_VM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 117ULL);
x86_l_1275:
	/* 0x1275: xor    r14b,BYTE PTR [rdx+r9*1+0x15] */
	X86_VM_RUN_OP(X86_OP_ALU_MEM, X86_R14, X86_RDX, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_R9, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 21ULL);
x86_l_127a:
	/* 0x127a: or     bl,r14b */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_RBX, X86_R14, X86_WIDTH_8, X86_ALU_OR, 0);
x86_l_127d:
	/* 0x127d: cmp    edi,0x7 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 7ULL);
x86_l_1280:
	/* 0x1280: jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0> */
	X86_VM_X86_JCC(X86_CC_B, 0x1280, 0x11f0, x86_l_11f0);
x86_l_1286:
	/* 0x1286: movzx  r14d,BYTE PTR [rdx+0x76] */
	X86_VM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 118ULL);
x86_l_128b:
	/* 0x128b: xor    r14b,BYTE PTR [rdx+r9*1+0x16] */
	X86_VM_RUN_OP(X86_OP_ALU_MEM, X86_R14, X86_RDX, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_R9, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 22ULL);
x86_l_1290:
	/* 0x1290: or     bl,r14b */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_RBX, X86_R14, X86_WIDTH_8, X86_ALU_OR, 0);
x86_l_1293:
	/* 0x1293: cmp    edi,0x8 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_1296:
	/* 0x1296: jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0> */
	X86_VM_X86_JCC(X86_CC_B, 0x1296, 0x11f0, x86_l_11f0);
x86_l_129c:
	/* 0x129c: movzx  r14d,BYTE PTR [rdx+0x77] */
	X86_VM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 119ULL);
x86_l_12a1:
	/* 0x12a1: xor    r14b,BYTE PTR [rdx+r9*1+0x17] */
	X86_VM_RUN_OP(X86_OP_ALU_MEM, X86_R14, X86_RDX, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_R9, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 23ULL);
x86_l_12a6:
	/* 0x12a6: or     bl,r14b */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_RBX, X86_R14, X86_WIDTH_8, X86_ALU_OR, 0);
x86_l_12a9:
	/* 0x12a9: jmp    11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0> */
	X86_VM_X86_JMP(0x12a9, 0x11f0, x86_l_11f0);
x86_l_12ae:
	/* 0x12ae: cmp    r9,0x60 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_64, 0, 96ULL);
x86_l_12b2:
	/* 0x12b2: je     12c5 <bpftrace_string_search_prefix_scan_xdp+0x1c5> */
	X86_VM_X86_JCC(X86_CC_E, 0x12b2, 0x12c5, x86_l_12c5);
x86_l_12b4:
	/* 0x12b4: shl    rdi,0x20 */
	X86_VM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_12b8:
	/* 0x12b8: add    rdi,r9 */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_RDI, X86_R9, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_12bb:
	/* 0x12bb: rol    rdi,0x3 */
	X86_VM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 3ULL);
x86_l_12bf:
	/* 0x12bf: xor    r8,rdi */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_R8, X86_RDI, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_12c2:
	/* 0x12c2: mov    rax,r8 */
	X86_VM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_R8, X86_WIDTH_64, 0, 0);
x86_l_12c5:
	/* 0x12c5: mov    QWORD PTR [rcx],rax */
	X86_VM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12c8:
	/* 0x12c8: mov    eax,0x2 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_12cd:
	/* 0x12cd: pop    rbx */
	X86_VM_RUN_OP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_12ce:
	/* 0x12ce: pop    r14 */
	X86_VM_RUN_OP(X86_OP_POP, X86_R14, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_12d0:
	/* 0x12d0: pop    rbp */
	X86_VM_RUN_OP(X86_OP_POP, X86_RBP, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_12d1:
	/* 0x12d1: ret */
	X86_VM_X86_RET();
	X86_VM_TRAP_RETURN();
}

X86_VM_LICENSE();
