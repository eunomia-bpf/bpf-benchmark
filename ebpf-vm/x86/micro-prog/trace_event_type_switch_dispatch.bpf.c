#define X86_VM_ENABLE_STACK 1
#define X86_VM_ENABLE_STACK_SLOT7 1
#define X86_VM_ENABLE_STACK_SLOT8 1
#define X86_VM_ENABLE_STACK_DEEP 1
#define X86_VM_ENABLE_STACK_EXT 1
#include "../x86_vm_bpf.h"

SEC("xdp")
int trace_event_type_switch_dispatch_x86_vm_xdp(struct xdp_md *ctx)
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
	/* 0x110f: jbe    1112 <trace_event_type_switch_dispatch_xdp+0x12> */
	X86_VM_X86_JCC(X86_CC_BE, 0x110f, 0x1112, x86_l_1112);
x86_l_1111:
	/* 0x1111: ret */
	X86_VM_X86_RET();
x86_l_1112:
	/* 0x1112: lea    rdi,[rdx+0x8] */
	X86_VM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1116:
	/* 0x1116: cmp    rdi,rsi */
	X86_VM_RUN_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_1119:
	/* 0x1119: ja     1111 <trace_event_type_switch_dispatch_xdp+0x11> */
	X86_VM_X86_JCC(X86_CC_A, 0x1119, 0x1111, x86_l_1111);
x86_l_111b:
	/* 0x111b: lea    r8,[rdx+0x20c] */
	X86_VM_RUN_OP(X86_OP_LEA, X86_R8, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 524ULL);
x86_l_1122:
	/* 0x1122: cmp    r8,rsi */
	X86_VM_RUN_OP(X86_OP_CMP_REG, X86_R8, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_1125:
	/* 0x1125: ja     1111 <trace_event_type_switch_dispatch_xdp+0x11> */
	X86_VM_X86_JCC(X86_CC_A, 0x1125, 0x1111, x86_l_1111);
x86_l_1127:
	/* 0x1127: cmp    DWORD PTR [rdi],0x80 */
	X86_VM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_112d:
	/* 0x112d: jne    1111 <trace_event_type_switch_dispatch_xdp+0x11> */
	X86_VM_X86_JCC(X86_CC_NE, 0x112d, 0x1111, x86_l_1111);
x86_l_112f:
	/* 0x112f: push   rbp */
	X86_VM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_1130:
	/* 0x1130: mov    rbp,rsp */
	X86_VM_RUN_OP(X86_OP_MOV_REG, X86_RBP, X86_RSP, X86_WIDTH_64, 0, 0);
x86_l_1133:
	/* 0x1133: push   rbx */
	X86_VM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_1134:
	/* 0x1134: xor    esi,esi */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1136:
	/* 0x1136: xor    ebx,ebx */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1138:
	/* 0x1138: jmp    1153 <trace_event_type_switch_dispatch_xdp+0x53> */
	X86_VM_X86_JMP(0x1138, 0x1153, x86_l_1153);
x86_l_113a:
	/* 0x113a: mov    ebx,0xc */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 12ULL);
x86_l_113f:
	/* 0x113f: nop */
	X86_VM_RUN_OP(X86_OP_NOP, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1140:
	/* 0x1140: xor    rbx,rax */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1143:
	/* 0x1143: inc    rsi */
	X86_VM_RUN_OP(X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1146:
	/* 0x1146: cmp    rsi,0x80 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, 0, 128ULL);
x86_l_114d:
	/* 0x114d: je     172a <trace_event_type_switch_dispatch_xdp+0x62a> */
	X86_VM_X86_JCC(X86_CC_E, 0x114d, 0x172a, x86_l_172a);
x86_l_1153:
	/* 0x1153: mov    rax,rbx */
	X86_VM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_1156:
	/* 0x1156: mov    edi,DWORD PTR [rdx+rsi*4+0xc] */
	X86_VM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 12ULL);
x86_l_115a:
	/* 0x115a: cmp    edi,0x1f */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 31ULL);
x86_l_115d:
	/* 0x115d: jg     11a0 <trace_event_type_switch_dispatch_xdp+0xa0> */
	X86_VM_X86_JCC(X86_CC_G, 0x115d, 0x11a0, x86_l_11a0);
x86_l_115f:
	/* 0x115f: cmp    edi,0xf */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 15ULL);
x86_l_1162:
	/* 0x1162: jg     11e0 <trace_event_type_switch_dispatch_xdp+0xe0> */
	X86_VM_X86_JCC(X86_CC_G, 0x1162, 0x11e0, x86_l_11e0);
x86_l_1164:
	/* 0x1164: cmp    edi,0x7 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 7ULL);
x86_l_1167:
	/* 0x1167: jg     1254 <trace_event_type_switch_dispatch_xdp+0x154> */
	X86_VM_X86_JCC(X86_CC_G, 0x1167, 0x1254, x86_l_1254);
x86_l_116d:
	/* 0x116d: cmp    edi,0x3 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 3ULL);
x86_l_1170:
	/* 0x1170: jg     130c <trace_event_type_switch_dispatch_xdp+0x20c> */
	X86_VM_X86_JCC(X86_CC_G, 0x1170, 0x130c, x86_l_130c);
x86_l_1176:
	/* 0x1176: cmp    edi,0x1 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_1179:
	/* 0x1179: jg     1434 <trace_event_type_switch_dispatch_xdp+0x334> */
	X86_VM_X86_JCC(X86_CC_G, 0x1179, 0x1434, x86_l_1434);
x86_l_117f:
	/* 0x117f: mov    ebx,0x38 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 56ULL);
x86_l_1184:
	/* 0x1184: test   edi,edi */
	X86_VM_RUN_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_32, 0, 0);
x86_l_1186:
	/* 0x1186: je     1140 <trace_event_type_switch_dispatch_xdp+0x40> */
	X86_VM_X86_JCC(X86_CC_E, 0x1186, 0x1140, x86_l_1140);
x86_l_1188:
	/* 0x1188: cmp    edi,0x1 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_118b:
	/* 0x118b: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> */
	X86_VM_X86_JCC(X86_CC_NE, 0x118b, 0x1720, x86_l_1720);
x86_l_1191:
	/* 0x1191: mov    ebx,0x2b */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 43ULL);
x86_l_1196:
	/* 0x1196: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> */
	X86_VM_X86_JMP(0x1196, 0x1140, x86_l_1140);
x86_l_1198:
	/* 0x1198: nop    DWORD PTR [rax+rax*1+0x0] */
	X86_VM_RUN_OP(X86_OP_NOP, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_11a0:
	/* 0x11a0: cmp    edi,0x2f */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 47ULL);
x86_l_11a3:
	/* 0x11a3: jg     1220 <trace_event_type_switch_dispatch_xdp+0x120> */
	X86_VM_X86_JCC(X86_CC_G, 0x11a3, 0x1220, x86_l_1220);
x86_l_11a5:
	/* 0x11a5: cmp    edi,0x27 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 39ULL);
x86_l_11a8:
	/* 0x11a8: jg     1282 <trace_event_type_switch_dispatch_xdp+0x182> */
	X86_VM_X86_JCC(X86_CC_G, 0x11a8, 0x1282, x86_l_1282);
x86_l_11ae:
	/* 0x11ae: cmp    edi,0x23 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 35ULL);
x86_l_11b1:
	/* 0x11b1: jg     1331 <trace_event_type_switch_dispatch_xdp+0x231> */
	X86_VM_X86_JCC(X86_CC_G, 0x11b1, 0x1331, x86_l_1331);
x86_l_11b7:
	/* 0x11b7: cmp    edi,0x21 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 33ULL);
x86_l_11ba:
	/* 0x11ba: jg     1450 <trace_event_type_switch_dispatch_xdp+0x350> */
	X86_VM_X86_JCC(X86_CC_G, 0x11ba, 0x1450, x86_l_1450);
x86_l_11c0:
	/* 0x11c0: cmp    edi,0x20 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 32ULL);
x86_l_11c3:
	/* 0x11c3: je     15f4 <trace_event_type_switch_dispatch_xdp+0x4f4> */
	X86_VM_X86_JCC(X86_CC_E, 0x11c3, 0x15f4, x86_l_15f4);
x86_l_11c9:
	/* 0x11c9: cmp    edi,0x21 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 33ULL);
x86_l_11cc:
	/* 0x11cc: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> */
	X86_VM_X86_JCC(X86_CC_NE, 0x11cc, 0x1720, x86_l_1720);
x86_l_11d2:
	/* 0x11d2: mov    ebx,0x27 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 39ULL);
x86_l_11d7:
	/* 0x11d7: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> */
	X86_VM_X86_JMP(0x11d7, 0x1140, x86_l_1140);
x86_l_11dc:
	/* 0x11dc: nop    DWORD PTR [rax+0x0] */
	X86_VM_RUN_OP(X86_OP_NOP, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_11e0:
	/* 0x11e0: cmp    edi,0x17 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 23ULL);
x86_l_11e3:
	/* 0x11e3: jg     12b0 <trace_event_type_switch_dispatch_xdp+0x1b0> */
	X86_VM_X86_JCC(X86_CC_G, 0x11e3, 0x12b0, x86_l_12b0);
x86_l_11e9:
	/* 0x11e9: cmp    edi,0x13 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 19ULL);
x86_l_11ec:
	/* 0x11ec: jg     1356 <trace_event_type_switch_dispatch_xdp+0x256> */
	X86_VM_X86_JCC(X86_CC_G, 0x11ec, 0x1356, x86_l_1356);
x86_l_11f2:
	/* 0x11f2: cmp    edi,0x11 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_11f5:
	/* 0x11f5: jg     146c <trace_event_type_switch_dispatch_xdp+0x36c> */
	X86_VM_X86_JCC(X86_CC_G, 0x11f5, 0x146c, x86_l_146c);
x86_l_11fb:
	/* 0x11fb: cmp    edi,0x10 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 16ULL);
x86_l_11fe:
	/* 0x11fe: je     15fe <trace_event_type_switch_dispatch_xdp+0x4fe> */
	X86_VM_X86_JCC(X86_CC_E, 0x11fe, 0x15fe, x86_l_15fe);
x86_l_1204:
	/* 0x1204: cmp    edi,0x11 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_1207:
	/* 0x1207: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> */
	X86_VM_X86_JCC(X86_CC_NE, 0x1207, 0x1720, x86_l_1720);
x86_l_120d:
	/* 0x120d: mov    ebx,0x3e */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 62ULL);
x86_l_1212:
	/* 0x1212: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> */
	X86_VM_X86_JMP(0x1212, 0x1140, x86_l_1140);
x86_l_1217:
	/* 0x1217: nop    WORD PTR [rax+rax*1+0x0] */
	X86_VM_RUN_OP(X86_OP_NOP, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1220:
	/* 0x1220: cmp    edi,0x37 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 55ULL);
x86_l_1223:
	/* 0x1223: jg     12de <trace_event_type_switch_dispatch_xdp+0x1de> */
	X86_VM_X86_JCC(X86_CC_G, 0x1223, 0x12de, x86_l_12de);
x86_l_1229:
	/* 0x1229: cmp    edi,0x33 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 51ULL);
x86_l_122c:
	/* 0x122c: jg     137b <trace_event_type_switch_dispatch_xdp+0x27b> */
	X86_VM_X86_JCC(X86_CC_G, 0x122c, 0x137b, x86_l_137b);
x86_l_1232:
	/* 0x1232: cmp    edi,0x31 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 49ULL);
x86_l_1235:
	/* 0x1235: jg     1488 <trace_event_type_switch_dispatch_xdp+0x388> */
	X86_VM_X86_JCC(X86_CC_G, 0x1235, 0x1488, x86_l_1488);
x86_l_123b:
	/* 0x123b: cmp    edi,0x30 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 48ULL);
x86_l_123e:
	/* 0x123e: je     1608 <trace_event_type_switch_dispatch_xdp+0x508> */
	X86_VM_X86_JCC(X86_CC_E, 0x123e, 0x1608, x86_l_1608);
x86_l_1244:
	/* 0x1244: cmp    edi,0x31 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 49ULL);
x86_l_1247:
	/* 0x1247: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> */
	X86_VM_X86_JCC(X86_CC_NE, 0x1247, 0x1720, x86_l_1720);
x86_l_124d:
	/* 0x124d: xor    ebx,ebx */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_124f:
	/* 0x124f: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> */
	X86_VM_X86_JMP(0x124f, 0x1140, x86_l_1140);
x86_l_1254:
	/* 0x1254: cmp    edi,0xb */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 11ULL);
x86_l_1257:
	/* 0x1257: jg     13a0 <trace_event_type_switch_dispatch_xdp+0x2a0> */
	X86_VM_X86_JCC(X86_CC_G, 0x1257, 0x13a0, x86_l_13a0);
x86_l_125d:
	/* 0x125d: cmp    edi,0x9 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 9ULL);
x86_l_1260:
	/* 0x1260: jg     14a4 <trace_event_type_switch_dispatch_xdp+0x3a4> */
	X86_VM_X86_JCC(X86_CC_G, 0x1260, 0x14a4, x86_l_14a4);
x86_l_1266:
	/* 0x1266: cmp    edi,0x8 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_1269:
	/* 0x1269: je     1612 <trace_event_type_switch_dispatch_xdp+0x512> */
	X86_VM_X86_JCC(X86_CC_E, 0x1269, 0x1612, x86_l_1612);
x86_l_126f:
	/* 0x126f: cmp    edi,0x9 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 9ULL);
x86_l_1272:
	/* 0x1272: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> */
	X86_VM_X86_JCC(X86_CC_NE, 0x1272, 0x1720, x86_l_1720);
x86_l_1278:
	/* 0x1278: mov    ebx,0x3f */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 63ULL);
x86_l_127d:
	/* 0x127d: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> */
	X86_VM_X86_JMP(0x127d, 0x1140, x86_l_1140);
x86_l_1282:
	/* 0x1282: cmp    edi,0x2b */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 43ULL);
x86_l_1285:
	/* 0x1285: jg     13c5 <trace_event_type_switch_dispatch_xdp+0x2c5> */
	X86_VM_X86_JCC(X86_CC_G, 0x1285, 0x13c5, x86_l_13c5);
x86_l_128b:
	/* 0x128b: cmp    edi,0x29 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 41ULL);
x86_l_128e:
	/* 0x128e: jg     14c0 <trace_event_type_switch_dispatch_xdp+0x3c0> */
	X86_VM_X86_JCC(X86_CC_G, 0x128e, 0x14c0, x86_l_14c0);
x86_l_1294:
	/* 0x1294: cmp    edi,0x28 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 40ULL);
x86_l_1297:
	/* 0x1297: je     161c <trace_event_type_switch_dispatch_xdp+0x51c> */
	X86_VM_X86_JCC(X86_CC_E, 0x1297, 0x161c, x86_l_161c);
x86_l_129d:
	/* 0x129d: cmp    edi,0x29 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 41ULL);
x86_l_12a0:
	/* 0x12a0: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> */
	X86_VM_X86_JCC(X86_CC_NE, 0x12a0, 0x1720, x86_l_1720);
x86_l_12a6:
	/* 0x12a6: mov    ebx,0x32 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 50ULL);
x86_l_12ab:
	/* 0x12ab: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> */
	X86_VM_X86_JMP(0x12ab, 0x1140, x86_l_1140);
x86_l_12b0:
	/* 0x12b0: cmp    edi,0x1b */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 27ULL);
x86_l_12b3:
	/* 0x12b3: jg     13ea <trace_event_type_switch_dispatch_xdp+0x2ea> */
	X86_VM_X86_JCC(X86_CC_G, 0x12b3, 0x13ea, x86_l_13ea);
x86_l_12b9:
	/* 0x12b9: cmp    edi,0x19 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 25ULL);
x86_l_12bc:
	/* 0x12bc: jg     14dc <trace_event_type_switch_dispatch_xdp+0x3dc> */
	X86_VM_X86_JCC(X86_CC_G, 0x12bc, 0x14dc, x86_l_14dc);
x86_l_12c2:
	/* 0x12c2: cmp    edi,0x18 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 24ULL);
x86_l_12c5:
	/* 0x12c5: je     1626 <trace_event_type_switch_dispatch_xdp+0x526> */
	X86_VM_X86_JCC(X86_CC_E, 0x12c5, 0x1626, x86_l_1626);
x86_l_12cb:
	/* 0x12cb: cmp    edi,0x19 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 25ULL);
x86_l_12ce:
	/* 0x12ce: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> */
	X86_VM_X86_JCC(X86_CC_NE, 0x12ce, 0x1720, x86_l_1720);
x86_l_12d4:
	/* 0x12d4: mov    ebx,0x1a */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 26ULL);
x86_l_12d9:
	/* 0x12d9: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> */
	X86_VM_X86_JMP(0x12d9, 0x1140, x86_l_1140);
x86_l_12de:
	/* 0x12de: cmp    edi,0x3b */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 59ULL);
x86_l_12e1:
	/* 0x12e1: jg     140f <trace_event_type_switch_dispatch_xdp+0x30f> */
	X86_VM_X86_JCC(X86_CC_G, 0x12e1, 0x140f, x86_l_140f);
x86_l_12e7:
	/* 0x12e7: cmp    edi,0x39 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 57ULL);
x86_l_12ea:
	/* 0x12ea: jg     14f8 <trace_event_type_switch_dispatch_xdp+0x3f8> */
	X86_VM_X86_JCC(X86_CC_G, 0x12ea, 0x14f8, x86_l_14f8);
x86_l_12f0:
	/* 0x12f0: cmp    edi,0x38 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 56ULL);
x86_l_12f3:
	/* 0x12f3: je     1630 <trace_event_type_switch_dispatch_xdp+0x530> */
	X86_VM_X86_JCC(X86_CC_E, 0x12f3, 0x1630, x86_l_1630);
x86_l_12f9:
	/* 0x12f9: cmp    edi,0x39 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 57ULL);
x86_l_12fc:
	/* 0x12fc: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> */
	X86_VM_X86_JCC(X86_CC_NE, 0x12fc, 0x1720, x86_l_1720);
x86_l_1302:
	/* 0x1302: mov    ebx,0x36 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 54ULL);
x86_l_1307:
	/* 0x1307: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> */
	X86_VM_X86_JMP(0x1307, 0x1140, x86_l_1140);
x86_l_130c:
	/* 0x130c: cmp    edi,0x5 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 5ULL);
x86_l_130f:
	/* 0x130f: jg     1514 <trace_event_type_switch_dispatch_xdp+0x414> */
	X86_VM_X86_JCC(X86_CC_G, 0x130f, 0x1514, x86_l_1514);
x86_l_1315:
	/* 0x1315: cmp    edi,0x4 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_1318:
	/* 0x1318: je     163a <trace_event_type_switch_dispatch_xdp+0x53a> */
	X86_VM_X86_JCC(X86_CC_E, 0x1318, 0x163a, x86_l_163a);
x86_l_131e:
	/* 0x131e: cmp    edi,0x5 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 5ULL);
x86_l_1321:
	/* 0x1321: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> */
	X86_VM_X86_JCC(X86_CC_NE, 0x1321, 0x1720, x86_l_1720);
x86_l_1327:
	/* 0x1327: mov    ebx,0x3d */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 61ULL);
x86_l_132c:
	/* 0x132c: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> */
	X86_VM_X86_JMP(0x132c, 0x1140, x86_l_1140);
x86_l_1331:
	/* 0x1331: cmp    edi,0x25 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 37ULL);
x86_l_1334:
	/* 0x1334: jg     1530 <trace_event_type_switch_dispatch_xdp+0x430> */
	X86_VM_X86_JCC(X86_CC_G, 0x1334, 0x1530, x86_l_1530);
x86_l_133a:
	/* 0x133a: cmp    edi,0x24 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 36ULL);
x86_l_133d:
	/* 0x133d: je     1644 <trace_event_type_switch_dispatch_xdp+0x544> */
	X86_VM_X86_JCC(X86_CC_E, 0x133d, 0x1644, x86_l_1644);
x86_l_1343:
	/* 0x1343: cmp    edi,0x25 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 37ULL);
x86_l_1346:
	/* 0x1346: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> */
	X86_VM_X86_JCC(X86_CC_NE, 0x1346, 0x1720, x86_l_1720);
x86_l_134c:
	/* 0x134c: mov    ebx,0x4 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_1351:
	/* 0x1351: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> */
	X86_VM_X86_JMP(0x1351, 0x1140, x86_l_1140);
x86_l_1356:
	/* 0x1356: cmp    edi,0x15 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 21ULL);
x86_l_1359:
	/* 0x1359: jg     154c <trace_event_type_switch_dispatch_xdp+0x44c> */
	X86_VM_X86_JCC(X86_CC_G, 0x1359, 0x154c, x86_l_154c);
x86_l_135f:
	/* 0x135f: cmp    edi,0x14 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 20ULL);
x86_l_1362:
	/* 0x1362: je     164e <trace_event_type_switch_dispatch_xdp+0x54e> */
	X86_VM_X86_JCC(X86_CC_E, 0x1362, 0x164e, x86_l_164e);
x86_l_1368:
	/* 0x1368: cmp    edi,0x15 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 21ULL);
x86_l_136b:
	/* 0x136b: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> */
	X86_VM_X86_JCC(X86_CC_NE, 0x136b, 0x1720, x86_l_1720);
x86_l_1371:
	/* 0x1371: mov    ebx,0x15 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 21ULL);
x86_l_1376:
	/* 0x1376: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> */
	X86_VM_X86_JMP(0x1376, 0x1140, x86_l_1140);
x86_l_137b:
	/* 0x137b: cmp    edi,0x35 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 53ULL);
x86_l_137e:
	/* 0x137e: jg     1568 <trace_event_type_switch_dispatch_xdp+0x468> */
	X86_VM_X86_JCC(X86_CC_G, 0x137e, 0x1568, x86_l_1568);
x86_l_1384:
	/* 0x1384: cmp    edi,0x34 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 52ULL);
x86_l_1387:
	/* 0x1387: je     1658 <trace_event_type_switch_dispatch_xdp+0x558> */
	X86_VM_X86_JCC(X86_CC_E, 0x1387, 0x1658, x86_l_1658);
x86_l_138d:
	/* 0x138d: cmp    edi,0x35 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 53ULL);
x86_l_1390:
	/* 0x1390: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> */
	X86_VM_X86_JCC(X86_CC_NE, 0x1390, 0x1720, x86_l_1720);
x86_l_1396:
	/* 0x1396: mov    ebx,0x14 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 20ULL);
x86_l_139b:
	/* 0x139b: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> */
	X86_VM_X86_JMP(0x139b, 0x1140, x86_l_1140);
x86_l_13a0:
	/* 0x13a0: cmp    edi,0xd */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 13ULL);
x86_l_13a3:
	/* 0x13a3: jg     1584 <trace_event_type_switch_dispatch_xdp+0x484> */
	X86_VM_X86_JCC(X86_CC_G, 0x13a3, 0x1584, x86_l_1584);
x86_l_13a9:
	/* 0x13a9: cmp    edi,0xc */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 12ULL);
x86_l_13ac:
	/* 0x13ac: je     1662 <trace_event_type_switch_dispatch_xdp+0x562> */
	X86_VM_X86_JCC(X86_CC_E, 0x13ac, 0x1662, x86_l_1662);
x86_l_13b2:
	/* 0x13b2: cmp    edi,0xd */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 13ULL);
x86_l_13b5:
	/* 0x13b5: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> */
	X86_VM_X86_JCC(X86_CC_NE, 0x13b5, 0x1720, x86_l_1720);
x86_l_13bb:
	/* 0x13bb: mov    ebx,0x2a */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 42ULL);
x86_l_13c0:
	/* 0x13c0: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> */
	X86_VM_X86_JMP(0x13c0, 0x1140, x86_l_1140);
x86_l_13c5:
	/* 0x13c5: cmp    edi,0x2d */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 45ULL);
x86_l_13c8:
	/* 0x13c8: jg     15a0 <trace_event_type_switch_dispatch_xdp+0x4a0> */
	X86_VM_X86_JCC(X86_CC_G, 0x13c8, 0x15a0, x86_l_15a0);
x86_l_13ce:
	/* 0x13ce: cmp    edi,0x2c */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 44ULL);
x86_l_13d1:
	/* 0x13d1: je     166c <trace_event_type_switch_dispatch_xdp+0x56c> */
	X86_VM_X86_JCC(X86_CC_E, 0x13d1, 0x166c, x86_l_166c);
x86_l_13d7:
	/* 0x13d7: cmp    edi,0x2d */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 45ULL);
x86_l_13da:
	/* 0x13da: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> */
	X86_VM_X86_JCC(X86_CC_NE, 0x13da, 0x1720, x86_l_1720);
x86_l_13e0:
	/* 0x13e0: mov    ebx,0x2c */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 44ULL);
x86_l_13e5:
	/* 0x13e5: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> */
	X86_VM_X86_JMP(0x13e5, 0x1140, x86_l_1140);
x86_l_13ea:
	/* 0x13ea: cmp    edi,0x1d */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 29ULL);
x86_l_13ed:
	/* 0x13ed: jg     15bc <trace_event_type_switch_dispatch_xdp+0x4bc> */
	X86_VM_X86_JCC(X86_CC_G, 0x13ed, 0x15bc, x86_l_15bc);
x86_l_13f3:
	/* 0x13f3: cmp    edi,0x1c */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 28ULL);
x86_l_13f6:
	/* 0x13f6: je     1676 <trace_event_type_switch_dispatch_xdp+0x576> */
	X86_VM_X86_JCC(X86_CC_E, 0x13f6, 0x1676, x86_l_1676);
x86_l_13fc:
	/* 0x13fc: cmp    edi,0x1d */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 29ULL);
x86_l_13ff:
	/* 0x13ff: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> */
	X86_VM_X86_JCC(X86_CC_NE, 0x13ff, 0x1720, x86_l_1720);
x86_l_1405:
	/* 0x1405: mov    ebx,0x1f */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 31ULL);
x86_l_140a:
	/* 0x140a: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> */
	X86_VM_X86_JMP(0x140a, 0x1140, x86_l_1140);
x86_l_140f:
	/* 0x140f: cmp    edi,0x3d */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 61ULL);
x86_l_1412:
	/* 0x1412: jg     15d8 <trace_event_type_switch_dispatch_xdp+0x4d8> */
	X86_VM_X86_JCC(X86_CC_G, 0x1412, 0x15d8, x86_l_15d8);
x86_l_1418:
	/* 0x1418: cmp    edi,0x3c */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 60ULL);
x86_l_141b:
	/* 0x141b: je     1680 <trace_event_type_switch_dispatch_xdp+0x580> */
	X86_VM_X86_JCC(X86_CC_E, 0x141b, 0x1680, x86_l_1680);
x86_l_1421:
	/* 0x1421: cmp    edi,0x3d */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 61ULL);
x86_l_1424:
	/* 0x1424: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> */
	X86_VM_X86_JCC(X86_CC_NE, 0x1424, 0x1720, x86_l_1720);
x86_l_142a:
	/* 0x142a: mov    ebx,0x5 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 5ULL);
x86_l_142f:
	/* 0x142f: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> */
	X86_VM_X86_JMP(0x142f, 0x1140, x86_l_1140);
x86_l_1434:
	/* 0x1434: cmp    edi,0x2 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_1437:
	/* 0x1437: je     168a <trace_event_type_switch_dispatch_xdp+0x58a> */
	X86_VM_X86_JCC(X86_CC_E, 0x1437, 0x168a, x86_l_168a);
x86_l_143d:
	/* 0x143d: cmp    edi,0x3 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 3ULL);
x86_l_1440:
	/* 0x1440: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> */
	X86_VM_X86_JCC(X86_CC_NE, 0x1440, 0x1720, x86_l_1720);
x86_l_1446:
	/* 0x1446: mov    ebx,0x1c */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 28ULL);
x86_l_144b:
	/* 0x144b: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> */
	X86_VM_X86_JMP(0x144b, 0x1140, x86_l_1140);
x86_l_1450:
	/* 0x1450: cmp    edi,0x22 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 34ULL);
x86_l_1453:
	/* 0x1453: je     1694 <trace_event_type_switch_dispatch_xdp+0x594> */
	X86_VM_X86_JCC(X86_CC_E, 0x1453, 0x1694, x86_l_1694);
x86_l_1459:
	/* 0x1459: cmp    edi,0x23 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 35ULL);
x86_l_145c:
	/* 0x145c: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> */
	X86_VM_X86_JCC(X86_CC_NE, 0x145c, 0x1720, x86_l_1720);
x86_l_1462:
	/* 0x1462: mov    ebx,0x1b */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 27ULL);
x86_l_1467:
	/* 0x1467: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> */
	X86_VM_X86_JMP(0x1467, 0x1140, x86_l_1140);
x86_l_146c:
	/* 0x146c: cmp    edi,0x12 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 18ULL);
x86_l_146f:
	/* 0x146f: je     169e <trace_event_type_switch_dispatch_xdp+0x59e> */
	X86_VM_X86_JCC(X86_CC_E, 0x146f, 0x169e, x86_l_169e);
x86_l_1475:
	/* 0x1475: cmp    edi,0x13 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 19ULL);
x86_l_1478:
	/* 0x1478: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> */
	X86_VM_X86_JCC(X86_CC_NE, 0x1478, 0x1720, x86_l_1720);
x86_l_147e:
	/* 0x147e: mov    ebx,0x6 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 6ULL);
x86_l_1483:
	/* 0x1483: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> */
	X86_VM_X86_JMP(0x1483, 0x1140, x86_l_1140);
x86_l_1488:
	/* 0x1488: cmp    edi,0x32 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 50ULL);
x86_l_148b:
	/* 0x148b: je     16a8 <trace_event_type_switch_dispatch_xdp+0x5a8> */
	X86_VM_X86_JCC(X86_CC_E, 0x148b, 0x16a8, x86_l_16a8);
x86_l_1491:
	/* 0x1491: cmp    edi,0x33 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 51ULL);
x86_l_1494:
	/* 0x1494: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> */
	X86_VM_X86_JCC(X86_CC_NE, 0x1494, 0x1720, x86_l_1720);
x86_l_149a:
	/* 0x149a: mov    ebx,0x3 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 3ULL);
x86_l_149f:
	/* 0x149f: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> */
	X86_VM_X86_JMP(0x149f, 0x1140, x86_l_1140);
x86_l_14a4:
	/* 0x14a4: cmp    edi,0xa */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 10ULL);
x86_l_14a7:
	/* 0x14a7: je     16b2 <trace_event_type_switch_dispatch_xdp+0x5b2> */
	X86_VM_X86_JCC(X86_CC_E, 0x14a7, 0x16b2, x86_l_16b2);
x86_l_14ad:
	/* 0x14ad: cmp    edi,0xb */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 11ULL);
x86_l_14b0:
	/* 0x14b0: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> */
	X86_VM_X86_JCC(X86_CC_NE, 0x14b0, 0x1720, x86_l_1720);
x86_l_14b6:
	/* 0x14b6: mov    ebx,0x24 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 36ULL);
x86_l_14bb:
	/* 0x14bb: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> */
	X86_VM_X86_JMP(0x14bb, 0x1140, x86_l_1140);
x86_l_14c0:
	/* 0x14c0: cmp    edi,0x2a */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 42ULL);
x86_l_14c3:
	/* 0x14c3: je     16bc <trace_event_type_switch_dispatch_xdp+0x5bc> */
	X86_VM_X86_JCC(X86_CC_E, 0x14c3, 0x16bc, x86_l_16bc);
x86_l_14c9:
	/* 0x14c9: cmp    edi,0x2b */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 43ULL);
x86_l_14cc:
	/* 0x14cc: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> */
	X86_VM_X86_JCC(X86_CC_NE, 0x14cc, 0x1720, x86_l_1720);
x86_l_14d2:
	/* 0x14d2: mov    ebx,0x23 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 35ULL);
x86_l_14d7:
	/* 0x14d7: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> */
	X86_VM_X86_JMP(0x14d7, 0x1140, x86_l_1140);
x86_l_14dc:
	/* 0x14dc: cmp    edi,0x1a */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 26ULL);
x86_l_14df:
	/* 0x14df: je     16c6 <trace_event_type_switch_dispatch_xdp+0x5c6> */
	X86_VM_X86_JCC(X86_CC_E, 0x14df, 0x16c6, x86_l_16c6);
x86_l_14e5:
	/* 0x14e5: cmp    edi,0x1b */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 27ULL);
x86_l_14e8:
	/* 0x14e8: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> */
	X86_VM_X86_JCC(X86_CC_NE, 0x14e8, 0x1720, x86_l_1720);
x86_l_14ee:
	/* 0x14ee: mov    ebx,0x29 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 41ULL);
x86_l_14f3:
	/* 0x14f3: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> */
	X86_VM_X86_JMP(0x14f3, 0x1140, x86_l_1140);
x86_l_14f8:
	/* 0x14f8: cmp    edi,0x3a */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 58ULL);
x86_l_14fb:
	/* 0x14fb: je     16d0 <trace_event_type_switch_dispatch_xdp+0x5d0> */
	X86_VM_X86_JCC(X86_CC_E, 0x14fb, 0x16d0, x86_l_16d0);
x86_l_1501:
	/* 0x1501: cmp    edi,0x3b */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 59ULL);
x86_l_1504:
	/* 0x1504: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> */
	X86_VM_X86_JCC(X86_CC_NE, 0x1504, 0x1720, x86_l_1720);
x86_l_150a:
	/* 0x150a: mov    ebx,0x10 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 16ULL);
x86_l_150f:
	/* 0x150f: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> */
	X86_VM_X86_JMP(0x150f, 0x1140, x86_l_1140);
x86_l_1514:
	/* 0x1514: cmp    edi,0x6 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 6ULL);
x86_l_1517:
	/* 0x1517: je     16da <trace_event_type_switch_dispatch_xdp+0x5da> */
	X86_VM_X86_JCC(X86_CC_E, 0x1517, 0x16da, x86_l_16da);
x86_l_151d:
	/* 0x151d: cmp    edi,0x7 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 7ULL);
x86_l_1520:
	/* 0x1520: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> */
	X86_VM_X86_JCC(X86_CC_NE, 0x1520, 0x1720, x86_l_1720);
x86_l_1526:
	/* 0x1526: mov    ebx,0x3a */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 58ULL);
x86_l_152b:
	/* 0x152b: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> */
	X86_VM_X86_JMP(0x152b, 0x1140, x86_l_1140);
x86_l_1530:
	/* 0x1530: cmp    edi,0x26 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 38ULL);
x86_l_1533:
	/* 0x1533: je     16e4 <trace_event_type_switch_dispatch_xdp+0x5e4> */
	X86_VM_X86_JCC(X86_CC_E, 0x1533, 0x16e4, x86_l_16e4);
x86_l_1539:
	/* 0x1539: cmp    edi,0x27 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 39ULL);
x86_l_153c:
	/* 0x153c: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> */
	X86_VM_X86_JCC(X86_CC_NE, 0x153c, 0x1720, x86_l_1720);
x86_l_1542:
	/* 0x1542: mov    ebx,0x30 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 48ULL);
x86_l_1547:
	/* 0x1547: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> */
	X86_VM_X86_JMP(0x1547, 0x1140, x86_l_1140);
x86_l_154c:
	/* 0x154c: cmp    edi,0x16 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 22ULL);
x86_l_154f:
	/* 0x154f: je     16ee <trace_event_type_switch_dispatch_xdp+0x5ee> */
	X86_VM_X86_JCC(X86_CC_E, 0x154f, 0x16ee, x86_l_16ee);
x86_l_1555:
	/* 0x1555: cmp    edi,0x17 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 23ULL);
x86_l_1558:
	/* 0x1558: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> */
	X86_VM_X86_JCC(X86_CC_NE, 0x1558, 0x1720, x86_l_1720);
x86_l_155e:
	/* 0x155e: mov    ebx,0x28 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 40ULL);
x86_l_1563:
	/* 0x1563: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> */
	X86_VM_X86_JMP(0x1563, 0x1140, x86_l_1140);
x86_l_1568:
	/* 0x1568: cmp    edi,0x36 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 54ULL);
x86_l_156b:
	/* 0x156b: je     16f8 <trace_event_type_switch_dispatch_xdp+0x5f8> */
	X86_VM_X86_JCC(X86_CC_E, 0x156b, 0x16f8, x86_l_16f8);
x86_l_1571:
	/* 0x1571: cmp    edi,0x37 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 55ULL);
x86_l_1574:
	/* 0x1574: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> */
	X86_VM_X86_JCC(X86_CC_NE, 0x1574, 0x1720, x86_l_1720);
x86_l_157a:
	/* 0x157a: mov    ebx,0x12 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 18ULL);
x86_l_157f:
	/* 0x157f: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> */
	X86_VM_X86_JMP(0x157f, 0x1140, x86_l_1140);
x86_l_1584:
	/* 0x1584: cmp    edi,0xe */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 14ULL);
x86_l_1587:
	/* 0x1587: je     1702 <trace_event_type_switch_dispatch_xdp+0x602> */
	X86_VM_X86_JCC(X86_CC_E, 0x1587, 0x1702, x86_l_1702);
x86_l_158d:
	/* 0x158d: cmp    edi,0xf */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 15ULL);
x86_l_1590:
	/* 0x1590: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> */
	X86_VM_X86_JCC(X86_CC_NE, 0x1590, 0x1720, x86_l_1720);
x86_l_1596:
	/* 0x1596: mov    ebx,0x2e */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 46ULL);
x86_l_159b:
	/* 0x159b: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> */
	X86_VM_X86_JMP(0x159b, 0x1140, x86_l_1140);
x86_l_15a0:
	/* 0x15a0: cmp    edi,0x2e */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 46ULL);
x86_l_15a3:
	/* 0x15a3: je     170c <trace_event_type_switch_dispatch_xdp+0x60c> */
	X86_VM_X86_JCC(X86_CC_E, 0x15a3, 0x170c, x86_l_170c);
x86_l_15a9:
	/* 0x15a9: cmp    edi,0x2f */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 47ULL);
x86_l_15ac:
	/* 0x15ac: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> */
	X86_VM_X86_JCC(X86_CC_NE, 0x15ac, 0x1720, x86_l_1720);
x86_l_15b2:
	/* 0x15b2: mov    ebx,0x3b */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 59ULL);
x86_l_15b7:
	/* 0x15b7: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> */
	X86_VM_X86_JMP(0x15b7, 0x1140, x86_l_1140);
x86_l_15bc:
	/* 0x15bc: cmp    edi,0x1e */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 30ULL);
x86_l_15bf:
	/* 0x15bf: je     1716 <trace_event_type_switch_dispatch_xdp+0x616> */
	X86_VM_X86_JCC(X86_CC_E, 0x15bf, 0x1716, x86_l_1716);
x86_l_15c5:
	/* 0x15c5: cmp    edi,0x1f */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 31ULL);
x86_l_15c8:
	/* 0x15c8: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> */
	X86_VM_X86_JCC(X86_CC_NE, 0x15c8, 0x1720, x86_l_1720);
x86_l_15ce:
	/* 0x15ce: mov    ebx,0x34 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 52ULL);
x86_l_15d3:
	/* 0x15d3: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> */
	X86_VM_X86_JMP(0x15d3, 0x1140, x86_l_1140);
x86_l_15d8:
	/* 0x15d8: cmp    edi,0x3e */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 62ULL);
x86_l_15db:
	/* 0x15db: je     113a <trace_event_type_switch_dispatch_xdp+0x3a> */
	X86_VM_X86_JCC(X86_CC_E, 0x15db, 0x113a, x86_l_113a);
x86_l_15e1:
	/* 0x15e1: cmp    edi,0x3f */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 63ULL);
x86_l_15e4:
	/* 0x15e4: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> */
	X86_VM_X86_JCC(X86_CC_NE, 0x15e4, 0x1720, x86_l_1720);
x86_l_15ea:
	/* 0x15ea: mov    ebx,0x37 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 55ULL);
x86_l_15ef:
	/* 0x15ef: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> */
	X86_VM_X86_JMP(0x15ef, 0x1140, x86_l_1140);
x86_l_15f4:
	/* 0x15f4: mov    ebx,0x19 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 25ULL);
x86_l_15f9:
	/* 0x15f9: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> */
	X86_VM_X86_JMP(0x15f9, 0x1140, x86_l_1140);
x86_l_15fe:
	/* 0x15fe: mov    ebx,0x22 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 34ULL);
x86_l_1603:
	/* 0x1603: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> */
	X86_VM_X86_JMP(0x1603, 0x1140, x86_l_1140);
x86_l_1608:
	/* 0x1608: mov    ebx,0x2d */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 45ULL);
x86_l_160d:
	/* 0x160d: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> */
	X86_VM_X86_JMP(0x160d, 0x1140, x86_l_1140);
x86_l_1612:
	/* 0x1612: mov    ebx,0x2 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_1617:
	/* 0x1617: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> */
	X86_VM_X86_JMP(0x1617, 0x1140, x86_l_1140);
x86_l_161c:
	/* 0x161c: mov    ebx,0x20 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 32ULL);
x86_l_1621:
	/* 0x1621: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> */
	X86_VM_X86_JMP(0x1621, 0x1140, x86_l_1140);
x86_l_1626:
	/* 0x1626: mov    ebx,0x26 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 38ULL);
x86_l_162b:
	/* 0x162b: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> */
	X86_VM_X86_JMP(0x162b, 0x1140, x86_l_1140);
x86_l_1630:
	/* 0x1630: mov    ebx,0x1 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_1635:
	/* 0x1635: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> */
	X86_VM_X86_JMP(0x1635, 0x1140, x86_l_1140);
x86_l_163a:
	/* 0x163a: mov    ebx,0xe */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 14ULL);
x86_l_163f:
	/* 0x163f: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> */
	X86_VM_X86_JMP(0x163f, 0x1140, x86_l_1140);
x86_l_1644:
	/* 0x1644: mov    ebx,0x35 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 53ULL);
x86_l_1649:
	/* 0x1649: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> */
	X86_VM_X86_JMP(0x1649, 0x1140, x86_l_1140);
x86_l_164e:
	/* 0x164e: mov    ebx,0x1d */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 29ULL);
x86_l_1653:
	/* 0x1653: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> */
	X86_VM_X86_JMP(0x1653, 0x1140, x86_l_1140);
x86_l_1658:
	/* 0x1658: mov    ebx,0xd */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 13ULL);
x86_l_165d:
	/* 0x165d: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> */
	X86_VM_X86_JMP(0x165d, 0x1140, x86_l_1140);
x86_l_1662:
	/* 0x1662: mov    ebx,0x13 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 19ULL);
x86_l_1667:
	/* 0x1667: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> */
	X86_VM_X86_JMP(0x1667, 0x1140, x86_l_1140);
x86_l_166c:
	/* 0x166c: mov    ebx,0x8 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_1671:
	/* 0x1671: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> */
	X86_VM_X86_JMP(0x1671, 0x1140, x86_l_1140);
x86_l_1676:
	/* 0x1676: mov    ebx,0x21 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 33ULL);
x86_l_167b:
	/* 0x167b: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> */
	X86_VM_X86_JMP(0x167b, 0x1140, x86_l_1140);
x86_l_1680:
	/* 0x1680: mov    ebx,0x3c */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 60ULL);
x86_l_1685:
	/* 0x1685: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> */
	X86_VM_X86_JMP(0x1685, 0x1140, x86_l_1140);
x86_l_168a:
	/* 0x168a: mov    ebx,0x39 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 57ULL);
x86_l_168f:
	/* 0x168f: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> */
	X86_VM_X86_JMP(0x168f, 0x1140, x86_l_1140);
x86_l_1694:
	/* 0x1694: mov    ebx,0xb */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 11ULL);
x86_l_1699:
	/* 0x1699: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> */
	X86_VM_X86_JMP(0x1699, 0x1140, x86_l_1140);
x86_l_169e:
	/* 0x169e: mov    ebx,0x2f */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 47ULL);
x86_l_16a3:
	/* 0x16a3: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> */
	X86_VM_X86_JMP(0x16a3, 0x1140, x86_l_1140);
x86_l_16a8:
	/* 0x16a8: mov    ebx,0x9 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 9ULL);
x86_l_16ad:
	/* 0x16ad: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> */
	X86_VM_X86_JMP(0x16ad, 0x1140, x86_l_1140);
x86_l_16b2:
	/* 0x16b2: mov    ebx,0x31 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 49ULL);
x86_l_16b7:
	/* 0x16b7: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> */
	X86_VM_X86_JMP(0x16b7, 0x1140, x86_l_1140);
x86_l_16bc:
	/* 0x16bc: mov    ebx,0x7 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 7ULL);
x86_l_16c1:
	/* 0x16c1: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> */
	X86_VM_X86_JMP(0x16c1, 0x1140, x86_l_1140);
x86_l_16c6:
	/* 0x16c6: mov    ebx,0x11 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_16cb:
	/* 0x16cb: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> */
	X86_VM_X86_JMP(0x16cb, 0x1140, x86_l_1140);
x86_l_16d0:
	/* 0x16d0: mov    ebx,0x16 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 22ULL);
x86_l_16d5:
	/* 0x16d5: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> */
	X86_VM_X86_JMP(0x16d5, 0x1140, x86_l_1140);
x86_l_16da:
	/* 0x16da: mov    ebx,0xa */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 10ULL);
x86_l_16df:
	/* 0x16df: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> */
	X86_VM_X86_JMP(0x16df, 0x1140, x86_l_1140);
x86_l_16e4:
	/* 0x16e4: mov    ebx,0x18 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 24ULL);
x86_l_16e9:
	/* 0x16e9: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> */
	X86_VM_X86_JMP(0x16e9, 0x1140, x86_l_1140);
x86_l_16ee:
	/* 0x16ee: mov    ebx,0xf */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 15ULL);
x86_l_16f3:
	/* 0x16f3: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> */
	X86_VM_X86_JMP(0x16f3, 0x1140, x86_l_1140);
x86_l_16f8:
	/* 0x16f8: mov    ebx,0x1e */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 30ULL);
x86_l_16fd:
	/* 0x16fd: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> */
	X86_VM_X86_JMP(0x16fd, 0x1140, x86_l_1140);
x86_l_1702:
	/* 0x1702: mov    ebx,0x25 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 37ULL);
x86_l_1707:
	/* 0x1707: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> */
	X86_VM_X86_JMP(0x1707, 0x1140, x86_l_1140);
x86_l_170c:
	/* 0x170c: mov    ebx,0x33 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 51ULL);
x86_l_1711:
	/* 0x1711: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> */
	X86_VM_X86_JMP(0x1711, 0x1140, x86_l_1140);
x86_l_1716:
	/* 0x1716: mov    ebx,0x17 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 23ULL);
x86_l_171b:
	/* 0x171b: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> */
	X86_VM_X86_JMP(0x171b, 0x1140, x86_l_1140);
x86_l_1720:
	/* 0x1720: mov    ebx,0x1bf52 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 114514ULL);
x86_l_1725:
	/* 0x1725: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> */
	X86_VM_X86_JMP(0x1725, 0x1140, x86_l_1140);
x86_l_172a:
	/* 0x172a: mov    BYTE PTR [rcx],bl */
	X86_VM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RBX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_172c:
	/* 0x172c: mov    BYTE PTR [rcx+0x1],bh */
	X86_VM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RBX, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_REG_AUX_SRC_SHIFT(8)), 1ULL);
x86_l_172f:
	/* 0x172f: shr    ebx,0x10 */
	X86_VM_RUN_OP(X86_OP_ALU_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1732:
	/* 0x1732: mov    BYTE PTR [rcx+0x2],bl */
	X86_VM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RBX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_1735:
	/* 0x1735: mov    edx,eax */
	X86_VM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_1737:
	/* 0x1737: shr    edx,0x18 */
	X86_VM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHR, 24ULL);
x86_l_173a:
	/* 0x173a: mov    BYTE PTR [rcx+0x3],dl */
	X86_VM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 3ULL);
x86_l_173d:
	/* 0x173d: mov    rdx,rax */
	X86_VM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_1740:
	/* 0x1740: shr    rdx,0x20 */
	X86_VM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_1744:
	/* 0x1744: mov    BYTE PTR [rcx+0x4],dl */
	X86_VM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1747:
	/* 0x1747: mov    rdx,rax */
	X86_VM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_174a:
	/* 0x174a: shr    rdx,0x28 */
	X86_VM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 40ULL);
x86_l_174e:
	/* 0x174e: mov    BYTE PTR [rcx+0x5],dl */
	X86_VM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_1751:
	/* 0x1751: mov    rdx,rax */
	X86_VM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_1754:
	/* 0x1754: shr    rdx,0x30 */
	X86_VM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 48ULL);
x86_l_1758:
	/* 0x1758: mov    BYTE PTR [rcx+0x6],dl */
	X86_VM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_175b:
	/* 0x175b: shr    rax,0x38 */
	X86_VM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 56ULL);
x86_l_175f:
	/* 0x175f: mov    BYTE PTR [rcx+0x7],al */
	X86_VM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 7ULL);
x86_l_1762:
	/* 0x1762: mov    eax,0x2 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_1767:
	/* 0x1767: pop    rbx */
	X86_VM_RUN_OP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1768:
	/* 0x1768: pop    rbp */
	X86_VM_RUN_OP(X86_OP_POP, X86_RBP, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1769:
	/* 0x1769: ret */
	X86_VM_X86_RET();
	X86_VM_TRAP_RETURN();
}

X86_VM_LICENSE();
