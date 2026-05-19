#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_SLOT7 1
#define X86_SIM_ENABLE_STACK_SLOT8 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#define X86_SIM_ENABLE_STACK_EXT 1
#include "../x86_sim_bpf.h"

SEC("xdp")
int packet_toeplitz_rss_hash_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_DECLARE_XDP(ctx);
x86_l_1100:
	/* 0x1100: mov    rsi,QWORD PTR [rdi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1103:
	/* 0x1103: mov    rcx,QWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1107:
	/* 0x1107: mov    rdi,rsi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_110a:
	/* 0x110a: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_110c:
	/* 0x110c: cmp    rdi,rcx */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RDI, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_110f:
	/* 0x110f: jbe    1112 <packet_toeplitz_rss_hash_xdp+0x12> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x110f, 0x1112, x86_l_1112);
x86_l_1111:
	/* 0x1111: ret */
	X86_SIM_X86_RET();
x86_l_1112:
	/* 0x1112: lea    rdx,[rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1116:
	/* 0x1116: cmp    rdx,rcx */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_1119:
	/* 0x1119: ja     1111 <packet_toeplitz_rss_hash_xdp+0x11> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1119, 0x1111, x86_l_1111);
x86_l_111b:
	/* 0x111b: lea    rdx,[rdi+0x3e] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 62ULL);
x86_l_111f:
	/* 0x111f: cmp    rdx,rcx */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_1122:
	/* 0x1122: ja     1111 <packet_toeplitz_rss_hash_xdp+0x11> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1122, 0x1111, x86_l_1111);
x86_l_1124:
	/* 0x1124: movzx  ecx,WORD PTR [rdi+0x14] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 20ULL);
x86_l_1128:
	/* 0x1128: rol    cx,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_ALU_ROL, 8ULL);
x86_l_112c:
	/* 0x112c: movzx  ecx,cx */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_112f:
	/* 0x112f: cmp    ecx,0x800 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 2048ULL);
x86_l_1135:
	/* 0x1135: jne    1111 <packet_toeplitz_rss_hash_xdp+0x11> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1135, 0x1111, x86_l_1111);
x86_l_1137:
	/* 0x1137: movzx  ecx,BYTE PTR [rdi+0x16] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 22ULL);
x86_l_113b:
	/* 0x113b: and    cl,0xf */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_ALU_AND, 15ULL);
x86_l_113e:
	/* 0x113e: cmp    cl,0x5 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, 0, 5ULL);
x86_l_1141:
	/* 0x1141: jne    1111 <packet_toeplitz_rss_hash_xdp+0x11> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1141, 0x1111, x86_l_1111);
x86_l_1143:
	/* 0x1143: cmp    BYTE PTR [rdi+0x1f],0x6 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 133143986182ULL);
x86_l_1147:
	/* 0x1147: jne    1111 <packet_toeplitz_rss_hash_xdp+0x11> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1147, 0x1111, x86_l_1111);
x86_l_1149:
	/* 0x1149: push   rbp */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_114a:
	/* 0x114a: mov    rbp,rsp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RBP, X86_RSP, X86_WIDTH_64, 0, 0);
x86_l_114d:
	/* 0x114d: push   rbx */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_114e:
	/* 0x114e: lea    r8,[rdi+0x1f] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R8, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 31ULL);
x86_l_1152:
	/* 0x1152: mov    r9,rdi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R9, X86_RDI, X86_WIDTH_64, 0, 0);
x86_l_1155:
	/* 0x1155: add    r9,0x22 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 34ULL);
x86_l_1159:
	/* 0x1159: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_115b:
	/* 0x115b: xor    r10d,r10d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R10, X86_R10, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_115e:
	/* 0x115e: jmp    118b <packet_toeplitz_rss_hash_xdp+0x8b> */
	X86_SIM_X86_JMP(0x115e, 0x118b, x86_l_118b);
x86_l_1160:
	/* 0x1160: mov    ebx,0xc2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 194ULL);
x86_l_1165:
	/* 0x1165: data16 cs nop WORD PTR [rax+rax*1+0x0] */
	X86_SIM_RUN_OP(X86_OP_NOP, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1170:
	/* 0x1170: mov    dl,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, 0, 8ULL);
x86_l_1172:
	/* 0x1172: sub    dl,cl */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB, 0);
x86_l_1174:
	/* 0x1174: mov    ecx,edx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_1176:
	/* 0x1176: shr    ebx,cl */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RBX, X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 0);
x86_l_1178:
	/* 0x1178: or     r11d,ebx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R11, X86_RBX, X86_WIDTH_32, X86_ALU_OR, 0);
x86_l_117b:
	/* 0x117b: xor    eax,r11d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_R11, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_117e:
	/* 0x117e: inc    r10d */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1181:
	/* 0x1181: cmp    r10d,0x68 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_32, 0, 104ULL);
x86_l_1185:
	/* 0x1185: je     137e <packet_toeplitz_rss_hash_xdp+0x27e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1185, 0x137e, x86_l_137e);
x86_l_118b:
	/* 0x118b: mov    edx,r10d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R10, X86_WIDTH_32, 0, 0);
x86_l_118e:
	/* 0x118e: shr    edx,0x3 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHR, 3ULL);
x86_l_1191:
	/* 0x1191: cmp    r10d,0x1f */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_32, 0, 31ULL);
x86_l_1195:
	/* 0x1195: jbe    11b0 <packet_toeplitz_rss_hash_xdp+0xb0> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x1195, 0x11b0, x86_l_11b0);
x86_l_1197:
	/* 0x1197: cmp    r10d,0x3f */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_32, 0, 63ULL);
x86_l_119b:
	/* 0x119b: jbe    11b0 <packet_toeplitz_rss_hash_xdp+0xb0> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x119b, 0x11b0, x86_l_11b0);
x86_l_119d:
	/* 0x119d: cmp    r10d,0x4f */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_32, 0, 79ULL);
x86_l_11a1:
	/* 0x11a1: jbe    11b0 <packet_toeplitz_rss_hash_xdp+0xb0> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x11a1, 0x11b0, x86_l_11b0);
x86_l_11a3:
	/* 0x11a3: mov    rcx,r8 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_R8, X86_WIDTH_64, 0, 0);
x86_l_11a6:
	/* 0x11a6: cmp    r10d,0x5f */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_32, 0, 95ULL);
x86_l_11aa:
	/* 0x11aa: ja     11b5 <packet_toeplitz_rss_hash_xdp+0xb5> */
	X86_SIM_X86_JCC(X86_CC_A, 0x11aa, 0x11b5, x86_l_11b5);
x86_l_11ac:
	/* 0x11ac: nop    DWORD PTR [rax+0x0] */
	X86_SIM_RUN_OP(X86_OP_NOP, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_11b0:
	/* 0x11b0: mov    ecx,edx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_11b2:
	/* 0x11b2: add    rcx,r9 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_R9, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_11b5:
	/* 0x11b5: movzx  r11d,BYTE PTR [rcx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R11, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_11b9:
	/* 0x11b9: mov    ecx,r10d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_R10, X86_WIDTH_32, 0, 0);
x86_l_11bc:
	/* 0x11bc: and    ecx,0x7 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_11bf:
	/* 0x11bf: shl    r11d,cl */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R11, X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 0);
x86_l_11c2:
	/* 0x11c2: test   r11b,r11b */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R11, X86_R11, X86_WIDTH_8, 0, 0);
x86_l_11c5:
	/* 0x11c5: jns    117e <packet_toeplitz_rss_hash_xdp+0x7e> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x11c5, 0x117e, x86_l_117e);
x86_l_11c7:
	/* 0x11c7: cmp    edx,0x5 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 5ULL);
x86_l_11ca:
	/* 0x11ca: jle    11f0 <packet_toeplitz_rss_hash_xdp+0xf0> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x11ca, 0x11f0, x86_l_11f0);
x86_l_11cc:
	/* 0x11cc: cmp    edx,0x8 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_11cf:
	/* 0x11cf: jle    1212 <packet_toeplitz_rss_hash_xdp+0x112> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x11cf, 0x1212, x86_l_1212);
x86_l_11d1:
	/* 0x11d1: cmp    edx,0xa */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 10ULL);
x86_l_11d4:
	/* 0x11d4: jg     1246 <packet_toeplitz_rss_hash_xdp+0x146> */
	X86_SIM_X86_JCC(X86_CC_G, 0x11d4, 0x1246, x86_l_1246);
x86_l_11d6:
	/* 0x11d6: cmp    edx,0x9 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 9ULL);
x86_l_11d9:
	/* 0x11d9: jne    128c <packet_toeplitz_rss_hash_xdp+0x18c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x11d9, 0x128c, x86_l_128c);
x86_l_11df:
	/* 0x11df: mov    ebx,0x43 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 67ULL);
x86_l_11e4:
	/* 0x11e4: mov    r11d,0x67253d00 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_32, 0, 1730493696ULL);
x86_l_11ea:
	/* 0x11ea: jmp    12c0 <packet_toeplitz_rss_hash_xdp+0x1c0> */
	X86_SIM_X86_JMP(0x11ea, 0x12c0, x86_l_12c0);
x86_l_11ef:
	/* 0x11ef: nop */
	X86_SIM_RUN_OP(X86_OP_NOP, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_11f0:
	/* 0x11f0: cmp    edx,0x2 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_11f3:
	/* 0x11f3: jg     122c <packet_toeplitz_rss_hash_xdp+0x12c> */
	X86_SIM_X86_JCC(X86_CC_G, 0x11f3, 0x122c, x86_l_122c);
x86_l_11f5:
	/* 0x11f5: test   edx,edx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_11f7:
	/* 0x11f7: je     1265 <packet_toeplitz_rss_hash_xdp+0x165> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11f7, 0x1265, x86_l_1265);
x86_l_11f9:
	/* 0x11f9: cmp    edx,0x1 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_11fc:
	/* 0x11fc: jne    12a6 <packet_toeplitz_rss_hash_xdp+0x1a6> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x11fc, 0x12a6, x86_l_12a6);
x86_l_1202:
	/* 0x1202: mov    ebx,0x25 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 37ULL);
x86_l_1207:
	/* 0x1207: mov    r11d,0x5a56da00 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_32, 0, 1515641344ULL);
x86_l_120d:
	/* 0x120d: jmp    12c0 <packet_toeplitz_rss_hash_xdp+0x1c0> */
	X86_SIM_X86_JMP(0x120d, 0x12c0, x86_l_12c0);
x86_l_1212:
	/* 0x1212: cmp    edx,0x6 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 6ULL);
x86_l_1215:
	/* 0x1215: je     1258 <packet_toeplitz_rss_hash_xdp+0x158> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1215, 0x1258, x86_l_1258);
x86_l_1217:
	/* 0x1217: cmp    edx,0x7 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 7ULL);
x86_l_121a:
	/* 0x121a: jne    127f <packet_toeplitz_rss_hash_xdp+0x17f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x121a, 0x127f, x86_l_127f);
x86_l_121c:
	/* 0x121c: mov    ebx,0x25 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 37ULL);
x86_l_1221:
	/* 0x1221: mov    r11d,0xc2416700 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_32, 0, 3259066112ULL);
x86_l_1227:
	/* 0x1227: jmp    12c0 <packet_toeplitz_rss_hash_xdp+0x1c0> */
	X86_SIM_X86_JMP(0x1227, 0x12c0, x86_l_12c0);
x86_l_122c:
	/* 0x122c: cmp    edx,0x3 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 3ULL);
x86_l_122f:
	/* 0x122f: je     1272 <packet_toeplitz_rss_hash_xdp+0x172> */
	X86_SIM_X86_JCC(X86_CC_E, 0x122f, 0x1272, x86_l_1272);
x86_l_1231:
	/* 0x1231: cmp    edx,0x4 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_1234:
	/* 0x1234: jne    12b3 <packet_toeplitz_rss_hash_xdp+0x1b3> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1234, 0x12b3, x86_l_12b3);
x86_l_1236:
	/* 0x1236: mov    ebx,0xc2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 194ULL);
x86_l_123b:
	/* 0x123b: mov    r11d,0x255b0e00 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_32, 0, 626724352ULL);
x86_l_1241:
	/* 0x1241: jmp    12c0 <packet_toeplitz_rss_hash_xdp+0x1c0> */
	X86_SIM_X86_JMP(0x1241, 0x12c0, x86_l_12c0);
x86_l_1246:
	/* 0x1246: cmp    edx,0xb */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 11ULL);
x86_l_1249:
	/* 0x1249: jne    1299 <packet_toeplitz_rss_hash_xdp+0x199> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1249, 0x1299, x86_l_1299);
x86_l_124b:
	/* 0x124b: mov    ebx,0x8f */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 143ULL);
x86_l_1250:
	/* 0x1250: mov    r11d,0x3d43a300 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_32, 0, 1027842816ULL);
x86_l_1256:
	/* 0x1256: jmp    12c0 <packet_toeplitz_rss_hash_xdp+0x1c0> */
	X86_SIM_X86_JMP(0x1256, 0x12c0, x86_l_12c0);
x86_l_1258:
	/* 0x1258: mov    ebx,0x67 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 103ULL);
x86_l_125d:
	/* 0x125d: mov    r11d,0xec24100 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_32, 0, 247611648ULL);
x86_l_1263:
	/* 0x1263: jmp    12c0 <packet_toeplitz_rss_hash_xdp+0x1c0> */
	X86_SIM_X86_JMP(0x1263, 0x12c0, x86_l_12c0);
x86_l_1265:
	/* 0x1265: mov    ebx,0xda */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 218ULL);
x86_l_126a:
	/* 0x126a: mov    r11d,0x6d5a5600 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_32, 0, 1834636800ULL);
x86_l_1270:
	/* 0x1270: jmp    12c0 <packet_toeplitz_rss_hash_xdp+0x1c0> */
	X86_SIM_X86_JMP(0x1270, 0x12c0, x86_l_12c0);
x86_l_1272:
	/* 0x1272: mov    ebx,0xe */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 14ULL);
x86_l_1277:
	/* 0x1277: mov    r11d,0xda255b00 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_32, 0, 3659881216ULL);
x86_l_127d:
	/* 0x127d: jmp    12c0 <packet_toeplitz_rss_hash_xdp+0x1c0> */
	X86_SIM_X86_JMP(0x127d, 0x12c0, x86_l_12c0);
x86_l_127f:
	/* 0x127f: mov    ebx,0x3d */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 61ULL);
x86_l_1284:
	/* 0x1284: mov    r11d,0x41672500 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_32, 0, 1097278720ULL);
x86_l_128a:
	/* 0x128a: jmp    12c0 <packet_toeplitz_rss_hash_xdp+0x1c0> */
	X86_SIM_X86_JMP(0x128a, 0x12c0, x86_l_12c0);
x86_l_128c:
	/* 0x128c: mov    ebx,0xa3 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 163ULL);
x86_l_1291:
	/* 0x1291: mov    r11d,0x253d4300 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_32, 0, 624771840ULL);
x86_l_1297:
	/* 0x1297: jmp    12c0 <packet_toeplitz_rss_hash_xdp+0x1c0> */
	X86_SIM_X86_JMP(0x1297, 0x12c0, x86_l_12c0);
x86_l_1299:
	/* 0x1299: mov    ebx,0xb0 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 176ULL);
x86_l_129e:
	/* 0x129e: mov    r11d,0x43a38f00 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_32, 0, 1134792448ULL);
x86_l_12a4:
	/* 0x12a4: jmp    12c0 <packet_toeplitz_rss_hash_xdp+0x1c0> */
	X86_SIM_X86_JMP(0x12a4, 0x12c0, x86_l_12c0);
x86_l_12a6:
	/* 0x12a6: mov    ebx,0x5b */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 91ULL);
x86_l_12ab:
	/* 0x12ab: mov    r11d,0x56da2500 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_32, 0, 1457136896ULL);
x86_l_12b1:
	/* 0x12b1: jmp    12c0 <packet_toeplitz_rss_hash_xdp+0x1c0> */
	X86_SIM_X86_JMP(0x12b1, 0x12c0, x86_l_12c0);
x86_l_12b3:
	/* 0x12b3: mov    ebx,0x41 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 65ULL);
x86_l_12b8:
	/* 0x12b8: mov    r11d,0x5b0ec200 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_32, 0, 1527693824ULL);
x86_l_12be:
	/* 0x12be: xchg   ax,ax */
	X86_SIM_RUN_OP(X86_OP_XCHG, X86_RAX, X86_RAX, X86_WIDTH_16, 0, 0);
x86_l_12c0:
	/* 0x12c0: or     r11d,ebx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R11, X86_RBX, X86_WIDTH_32, X86_ALU_OR, 0);
x86_l_12c3:
	/* 0x12c3: test   ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_12c5:
	/* 0x12c5: je     117b <packet_toeplitz_rss_hash_xdp+0x7b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12c5, 0x117b, x86_l_117b);
x86_l_12cb:
	/* 0x12cb: shl    r11d,cl */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R11, X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 0);
x86_l_12ce:
	/* 0x12ce: mov    ebx,0x25 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 37ULL);
x86_l_12d3:
	/* 0x12d3: cmp    edx,0x5 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 5ULL);
x86_l_12d6:
	/* 0x12d6: jle    12f1 <packet_toeplitz_rss_hash_xdp+0x1f1> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x12d6, 0x12f1, x86_l_12f1);
x86_l_12d8:
	/* 0x12d8: cmp    edx,0x8 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_12db:
	/* 0x12db: jle    130d <packet_toeplitz_rss_hash_xdp+0x20d> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x12db, 0x130d, x86_l_130d);
x86_l_12dd:
	/* 0x12dd: cmp    edx,0xa */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 10ULL);
x86_l_12e0:
	/* 0x12e0: jg     133d <packet_toeplitz_rss_hash_xdp+0x23d> */
	X86_SIM_X86_JCC(X86_CC_G, 0x12e0, 0x133d, x86_l_133d);
x86_l_12e2:
	/* 0x12e2: cmp    edx,0x9 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 9ULL);
x86_l_12e5:
	/* 0x12e5: jne    1356 <packet_toeplitz_rss_hash_xdp+0x256> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x12e5, 0x1356, x86_l_1356);
x86_l_12e7:
	/* 0x12e7: mov    ebx,0xa3 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 163ULL);
x86_l_12ec:
	/* 0x12ec: jmp    1170 <packet_toeplitz_rss_hash_xdp+0x70> */
	X86_SIM_X86_JMP(0x12ec, 0x1170, x86_l_1170);
x86_l_12f1:
	/* 0x12f1: cmp    edx,0x2 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_12f4:
	/* 0x12f4: jg     1325 <packet_toeplitz_rss_hash_xdp+0x225> */
	X86_SIM_X86_JCC(X86_CC_G, 0x12f4, 0x1325, x86_l_1325);
x86_l_12f6:
	/* 0x12f6: test   edx,edx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_12f8:
	/* 0x12f8: je     1170 <packet_toeplitz_rss_hash_xdp+0x70> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12f8, 0x1170, x86_l_1170);
x86_l_12fe:
	/* 0x12fe: cmp    edx,0x1 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_1301:
	/* 0x1301: jne    136a <packet_toeplitz_rss_hash_xdp+0x26a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1301, 0x136a, x86_l_136a);
x86_l_1303:
	/* 0x1303: mov    ebx,0x5b */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 91ULL);
x86_l_1308:
	/* 0x1308: jmp    1170 <packet_toeplitz_rss_hash_xdp+0x70> */
	X86_SIM_X86_JMP(0x1308, 0x1170, x86_l_1170);
x86_l_130d:
	/* 0x130d: cmp    edx,0x6 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 6ULL);
x86_l_1310:
	/* 0x1310: je     1170 <packet_toeplitz_rss_hash_xdp+0x70> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1310, 0x1170, x86_l_1170);
x86_l_1316:
	/* 0x1316: cmp    edx,0x7 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 7ULL);
x86_l_1319:
	/* 0x1319: jne    134c <packet_toeplitz_rss_hash_xdp+0x24c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1319, 0x134c, x86_l_134c);
x86_l_131b:
	/* 0x131b: mov    ebx,0x3d */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 61ULL);
x86_l_1320:
	/* 0x1320: jmp    1170 <packet_toeplitz_rss_hash_xdp+0x70> */
	X86_SIM_X86_JMP(0x1320, 0x1170, x86_l_1170);
x86_l_1325:
	/* 0x1325: cmp    edx,0x3 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 3ULL);
x86_l_1328:
	/* 0x1328: je     1160 <packet_toeplitz_rss_hash_xdp+0x60> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1328, 0x1160, x86_l_1160);
x86_l_132e:
	/* 0x132e: cmp    edx,0x4 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_1331:
	/* 0x1331: jne    1374 <packet_toeplitz_rss_hash_xdp+0x274> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1331, 0x1374, x86_l_1374);
x86_l_1333:
	/* 0x1333: mov    ebx,0x41 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 65ULL);
x86_l_1338:
	/* 0x1338: jmp    1170 <packet_toeplitz_rss_hash_xdp+0x70> */
	X86_SIM_X86_JMP(0x1338, 0x1170, x86_l_1170);
x86_l_133d:
	/* 0x133d: cmp    edx,0xb */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 11ULL);
x86_l_1340:
	/* 0x1340: jne    1360 <packet_toeplitz_rss_hash_xdp+0x260> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1340, 0x1360, x86_l_1360);
x86_l_1342:
	/* 0x1342: mov    ebx,0xb0 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 176ULL);
x86_l_1347:
	/* 0x1347: jmp    1170 <packet_toeplitz_rss_hash_xdp+0x70> */
	X86_SIM_X86_JMP(0x1347, 0x1170, x86_l_1170);
x86_l_134c:
	/* 0x134c: mov    ebx,0x43 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 67ULL);
x86_l_1351:
	/* 0x1351: jmp    1170 <packet_toeplitz_rss_hash_xdp+0x70> */
	X86_SIM_X86_JMP(0x1351, 0x1170, x86_l_1170);
x86_l_1356:
	/* 0x1356: mov    ebx,0x8f */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 143ULL);
x86_l_135b:
	/* 0x135b: jmp    1170 <packet_toeplitz_rss_hash_xdp+0x70> */
	X86_SIM_X86_JMP(0x135b, 0x1170, x86_l_1170);
x86_l_1360:
	/* 0x1360: mov    ebx,0xd0 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 208ULL);
x86_l_1365:
	/* 0x1365: jmp    1170 <packet_toeplitz_rss_hash_xdp+0x70> */
	X86_SIM_X86_JMP(0x1365, 0x1170, x86_l_1170);
x86_l_136a:
	/* 0x136a: mov    ebx,0xe */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 14ULL);
x86_l_136f:
	/* 0x136f: jmp    1170 <packet_toeplitz_rss_hash_xdp+0x70> */
	X86_SIM_X86_JMP(0x136f, 0x1170, x86_l_1170);
x86_l_1374:
	/* 0x1374: mov    ebx,0x67 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 103ULL);
x86_l_1379:
	/* 0x1379: jmp    1170 <packet_toeplitz_rss_hash_xdp+0x70> */
	X86_SIM_X86_JMP(0x1379, 0x1170, x86_l_1170);
x86_l_137e:
	/* 0x137e: mov    edx,DWORD PTR [rdi+0x26] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_1381:
	/* 0x1381: movzx  r9d,BYTE PTR [rdi+0x2a] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R9, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_1386:
	/* 0x1386: movzx  r10d,BYTE PTR [rdi+0x2b] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R10, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_138b:
	/* 0x138b: movzx  r8d,BYTE PTR [rdi+0x2c] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R8, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 44ULL);
x86_l_1390:
	/* 0x1390: movzx  ecx,BYTE PTR [rdi+0x2d] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 45ULL);
x86_l_1394:
	/* 0x1394: mov    r11,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R11, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_1397:
	/* 0x1397: shl    r11,0x20 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_139b:
	/* 0x139b: xor    edx,DWORD PTR [rdi+0x22] */
	X86_SIM_RUN_OP(X86_OP_ALU_MEM, X86_RDX, X86_RDI, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 34ULL);
x86_l_139e:
	/* 0x139e: bswap  edx */
	X86_SIM_RUN_OP(X86_OP_BSWAP, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 0);
x86_l_13a0:
	/* 0x13a0: mov    edi,edx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_13a2:
	/* 0x13a2: xor    edi,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_13a4:
	/* 0x13a4: or     rdi,r11 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDI, X86_R11, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_13a7:
	/* 0x13a7: shl    r9,0x38 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 56ULL);
x86_l_13ab:
	/* 0x13ab: shl    r10,0x30 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 48ULL);
x86_l_13af:
	/* 0x13af: or     r10,r9 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R10, X86_R9, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_13b2:
	/* 0x13b2: shl    r8,0x28 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 40ULL);
x86_l_13b6:
	/* 0x13b6: or     r8,r10 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R8, X86_R10, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_13b9:
	/* 0x13b9: shl    rcx,0x20 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_13bd:
	/* 0x13bd: or     rdx,r8 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_R8, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_13c0:
	/* 0x13c0: or     rdx,rcx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_13c3:
	/* 0x13c3: and    eax,0x7 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_13c6:
	/* 0x13c6: lea    ecx,[rax+0x1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_13c9:
	/* 0x13c9: mov    r8,rdx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R8, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_13cc:
	/* 0x13cc: shl    r8,cl */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R8, X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 0);
x86_l_13cf:
	/* 0x13cf: not    al */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_ALU_NOT, 0);
x86_l_13d1:
	/* 0x13d1: mov    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_13d3:
	/* 0x13d3: shr    rdx,cl */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 0);
x86_l_13d6:
	/* 0x13d6: or     rdx,r8 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_R8, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_13d9:
	/* 0x13d9: xor    rdx,rdi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RDI, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_13dc:
	/* 0x13dc: mov    QWORD PTR [rsi],rdx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13df:
	/* 0x13df: mov    eax,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_13e4:
	/* 0x13e4: pop    rbx */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_13e5:
	/* 0x13e5: pop    rbp */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBP, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_13e6:
	/* 0x13e6: ret */
	X86_SIM_X86_RET();
	return x86_sim_ret_rax(&__x86_sim_state);
}

X86_SIM_LICENSE();
