#define X86_VM_ENABLE_STACK 1
#define X86_VM_ENABLE_STACK_SLOT7 1
#define X86_VM_ENABLE_STACK_DEEP 1
#define X86_VM_ENABLE_STACK_EXT 1
#include "../x86_vm_bpf.h"

SEC("xdp")
int tracee_http_method_prefix_detect_x86_vm_xdp(struct xdp_md *ctx)
{
	X86_VM_DECLARE_XDP(ctx);
x86_l_1100:
	/* 0x1100: mov    rdx,QWORD PTR [rdi] */
	X86_VM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1103:
	/* 0x1103: mov    rcx,QWORD PTR [rdi+0x8] */
	X86_VM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1107:
	/* 0x1107: xor    eax,eax */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1109:
	/* 0x1109: cmp    rdx,rcx */
	X86_VM_RUN_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_110c:
	/* 0x110c: jbe    110f <tracee_http_method_prefix_detect_xdp+0xf> */
	X86_VM_X86_JCC(X86_CC_BE, 0x110c, 0x110f, x86_l_110f);
x86_l_110e:
	/* 0x110e: ret */
	X86_VM_X86_RET();
x86_l_110f:
	/* 0x110f: lea    rsi,[rdx+0x8] */
	X86_VM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1113:
	/* 0x1113: cmp    rsi,rcx */
	X86_VM_RUN_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_1116:
	/* 0x1116: ja     110e <tracee_http_method_prefix_detect_xdp+0xe> */
	X86_VM_X86_JCC(X86_CC_A, 0x1116, 0x110e, x86_l_110e);
x86_l_1118:
	/* 0x1118: lea    rsi,[rdx+0x90] */
	X86_VM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_111f:
	/* 0x111f: cmp    rsi,rcx */
	X86_VM_RUN_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_1122:
	/* 0x1122: ja     110e <tracee_http_method_prefix_detect_xdp+0xe> */
	X86_VM_X86_JCC(X86_CC_A, 0x1122, 0x110e, x86_l_110e);
x86_l_1124:
	/* 0x1124: cmp    DWORD PTR [rdx+0x8],0x8 */
	X86_VM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738376ULL);
x86_l_1128:
	/* 0x1128: jne    110e <tracee_http_method_prefix_detect_xdp+0xe> */
	X86_VM_X86_JCC(X86_CC_NE, 0x1128, 0x110e, x86_l_110e);
x86_l_112a:
	/* 0x112a: cmp    DWORD PTR [rdx+0xc],0x10 */
	X86_VM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607568ULL);
x86_l_112e:
	/* 0x112e: jne    110e <tracee_http_method_prefix_detect_xdp+0xe> */
	X86_VM_X86_JCC(X86_CC_NE, 0x112e, 0x110e, x86_l_110e);
x86_l_1130:
	/* 0x1130: push   rbp */
	X86_VM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_1131:
	/* 0x1131: mov    rbp,rsp */
	X86_VM_RUN_OP(X86_OP_MOV_REG, X86_RBP, X86_RSP, X86_WIDTH_64, 0, 0);
x86_l_1134:
	/* 0x1134: push   r14 */
	X86_VM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_1136:
	/* 0x1136: push   rbx */
	X86_VM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_1137:
	/* 0x1137: lea    rax,[rdx+0x16] */
	X86_VM_RUN_OP(X86_OP_LEA, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_113b:
	/* 0x113b: movabs rbx,0xa0761d6478bd642f */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 11562461410679940143ULL);
x86_l_1145:
	/* 0x1145: mov    ecx,0x1 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_114a:
	/* 0x114a: nop    WORD PTR [rax+rax*1+0x0] */
	X86_VM_RUN_OP(X86_OP_NOP, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1150:
	/* 0x1150: mov    rsi,rbx */
	X86_VM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_1153:
	/* 0x1153: movzx  edi,BYTE PTR [rax-0x6] */
	X86_VM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551610ULL);
x86_l_1157:
	/* 0x1157: movzx  r8d,BYTE PTR [rax-0x5] */
	X86_VM_RUN_OP(X86_OP_MOV_LOAD, X86_R8, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551611ULL);
x86_l_115c:
	/* 0x115c: cmp    edi,0x47 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 71ULL);
x86_l_115f:
	/* 0x115f: jg     11b0 <tracee_http_method_prefix_detect_xdp+0xb0> */
	X86_VM_X86_JCC(X86_CC_G, 0x115f, 0x11b0, x86_l_11b0);
x86_l_1161:
	/* 0x1161: cmp    edi,0x44 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 68ULL);
x86_l_1164:
	/* 0x1164: je     120f <tracee_http_method_prefix_detect_xdp+0x10f> */
	X86_VM_X86_JCC(X86_CC_E, 0x1164, 0x120f, x86_l_120f);
x86_l_116a:
	/* 0x116a: cmp    edi,0x47 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 71ULL);
x86_l_116d:
	/* 0x116d: jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0> */
	X86_VM_X86_JCC(X86_CC_NE, 0x116d, 0x12e0, x86_l_12e0);
x86_l_1173:
	/* 0x1173: cmp    r8b,0x45 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_8, 0, 69ULL);
x86_l_1177:
	/* 0x1177: jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0> */
	X86_VM_X86_JCC(X86_CC_NE, 0x1177, 0x12e0, x86_l_12e0);
x86_l_117d:
	/* 0x117d: mov    r8b,0x45 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_8, 0, 69ULL);
x86_l_1180:
	/* 0x1180: cmp    BYTE PTR [rax-0x4],0x54 */
	X86_VM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744056529682516ULL);
x86_l_1184:
	/* 0x1184: jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0> */
	X86_VM_X86_JCC(X86_CC_NE, 0x1184, 0x12e0, x86_l_12e0);
x86_l_118a:
	/* 0x118a: mov    r10b,0x45 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_8, 0, 69ULL);
x86_l_118d:
	/* 0x118d: cmp    BYTE PTR [rax-0x3],0x20 */
	X86_VM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744060824649760ULL);
x86_l_1191:
	/* 0x1191: jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0> */
	X86_VM_X86_JCC(X86_CC_NE, 0x1191, 0x12e0, x86_l_12e0);
x86_l_1197:
	/* 0x1197: mov    r9d,0x1 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_119d:
	/* 0x119d: jmp    12ab <tracee_http_method_prefix_detect_xdp+0x1ab> */
	X86_VM_X86_JMP(0x119d, 0x12ab, x86_l_12ab);
x86_l_11a2:
	/* 0x11a2: data16 data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0] */
	X86_VM_RUN_OP(X86_OP_NOP, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_11b0:
	/* 0x11b0: movzx  r9d,r8b */
	X86_VM_RUN_OP(X86_OP_MOVZX_REG, X86_R9, X86_R8, X86_WIDTH_32, X86_WIDTH_8, 0);
x86_l_11b4:
	/* 0x11b4: cmp    edi,0x48 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 72ULL);
x86_l_11b7:
	/* 0x11b7: je     1261 <tracee_http_method_prefix_detect_xdp+0x161> */
	X86_VM_X86_JCC(X86_CC_E, 0x11b7, 0x1261, x86_l_1261);
x86_l_11bd:
	/* 0x11bd: cmp    edi,0x50 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 80ULL);
x86_l_11c0:
	/* 0x11c0: jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0> */
	X86_VM_X86_JCC(X86_CC_NE, 0x11c0, 0x12e0, x86_l_12e0);
x86_l_11c6:
	/* 0x11c6: cmp    r9d,0x55 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_32, 0, 85ULL);
x86_l_11ca:
	/* 0x11ca: je     1293 <tracee_http_method_prefix_detect_xdp+0x193> */
	X86_VM_X86_JCC(X86_CC_E, 0x11ca, 0x1293, x86_l_1293);
x86_l_11d0:
	/* 0x11d0: cmp    r9d,0x4f */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_32, 0, 79ULL);
x86_l_11d4:
	/* 0x11d4: jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0> */
	X86_VM_X86_JCC(X86_CC_NE, 0x11d4, 0x12e0, x86_l_12e0);
x86_l_11da:
	/* 0x11da: mov    r8b,0x4f */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_8, 0, 79ULL);
x86_l_11dd:
	/* 0x11dd: cmp    BYTE PTR [rax-0x4],0x53 */
	X86_VM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744056529682515ULL);
x86_l_11e1:
	/* 0x11e1: jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0> */
	X86_VM_X86_JCC(X86_CC_NE, 0x11e1, 0x12e0, x86_l_12e0);
x86_l_11e7:
	/* 0x11e7: cmp    BYTE PTR [rax-0x3],0x54 */
	X86_VM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744060824649812ULL);
x86_l_11eb:
	/* 0x11eb: jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0> */
	X86_VM_X86_JCC(X86_CC_NE, 0x11eb, 0x12e0, x86_l_12e0);
x86_l_11f1:
	/* 0x11f1: mov    r10b,0x4f */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_8, 0, 79ULL);
x86_l_11f4:
	/* 0x11f4: cmp    BYTE PTR [rax-0x2],0x20 */
	X86_VM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744065119617056ULL);
x86_l_11f8:
	/* 0x11f8: jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0> */
	X86_VM_X86_JCC(X86_CC_NE, 0x11f8, 0x12e0, x86_l_12e0);
x86_l_11fe:
	/* 0x11fe: mov    r9d,0x2 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_1204:
	/* 0x1204: mov    r8b,0x53 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_8, 0, 83ULL);
x86_l_1207:
	/* 0x1207: mov    r11b,0x54 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_8, 0, 84ULL);
x86_l_120a:
	/* 0x120a: jmp    12f0 <tracee_http_method_prefix_detect_xdp+0x1f0> */
	X86_VM_X86_JMP(0x120a, 0x12f0, x86_l_12f0);
x86_l_120f:
	/* 0x120f: cmp    r8b,0x45 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_8, 0, 69ULL);
x86_l_1213:
	/* 0x1213: jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0> */
	X86_VM_X86_JCC(X86_CC_NE, 0x1213, 0x12e0, x86_l_12e0);
x86_l_1219:
	/* 0x1219: mov    r8b,0x45 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_8, 0, 69ULL);
x86_l_121c:
	/* 0x121c: cmp    BYTE PTR [rax-0x4],0x4c */
	X86_VM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744056529682508ULL);
x86_l_1220:
	/* 0x1220: jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0> */
	X86_VM_X86_JCC(X86_CC_NE, 0x1220, 0x12e0, x86_l_12e0);
x86_l_1226:
	/* 0x1226: cmp    BYTE PTR [rax-0x3],0x45 */
	X86_VM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744060824649797ULL);
x86_l_122a:
	/* 0x122a: jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0> */
	X86_VM_X86_JCC(X86_CC_NE, 0x122a, 0x12e0, x86_l_12e0);
x86_l_1230:
	/* 0x1230: cmp    BYTE PTR [rax-0x2],0x54 */
	X86_VM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744065119617108ULL);
x86_l_1234:
	/* 0x1234: jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0> */
	X86_VM_X86_JCC(X86_CC_NE, 0x1234, 0x12e0, x86_l_12e0);
x86_l_123a:
	/* 0x123a: cmp    BYTE PTR [rax-0x1],0x45 */
	X86_VM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744069414584389ULL);
x86_l_123e:
	/* 0x123e: jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0> */
	X86_VM_X86_JCC(X86_CC_NE, 0x123e, 0x12e0, x86_l_12e0);
x86_l_1244:
	/* 0x1244: mov    r11b,0x45 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_8, 0, 69ULL);
x86_l_1247:
	/* 0x1247: cmp    BYTE PTR [rax],0x20 */
	X86_VM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_124a:
	/* 0x124a: jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0> */
	X86_VM_X86_JCC(X86_CC_NE, 0x124a, 0x12e0, x86_l_12e0);
x86_l_1250:
	/* 0x1250: mov    r9d,0x4 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_1256:
	/* 0x1256: mov    r8b,0x4c */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_8, 0, 76ULL);
x86_l_1259:
	/* 0x1259: mov    r10b,0x45 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_8, 0, 69ULL);
x86_l_125c:
	/* 0x125c: jmp    12f0 <tracee_http_method_prefix_detect_xdp+0x1f0> */
	X86_VM_X86_JMP(0x125c, 0x12f0, x86_l_12f0);
x86_l_1261:
	/* 0x1261: cmp    r9d,0x54 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_32, 0, 84ULL);
x86_l_1265:
	/* 0x1265: je     12b3 <tracee_http_method_prefix_detect_xdp+0x1b3> */
	X86_VM_X86_JCC(X86_CC_E, 0x1265, 0x12b3, x86_l_12b3);
x86_l_1267:
	/* 0x1267: cmp    r9d,0x45 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_32, 0, 69ULL);
x86_l_126b:
	/* 0x126b: jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0> */
	X86_VM_X86_JCC(X86_CC_NE, 0x126b, 0x12e0, x86_l_12e0);
x86_l_126d:
	/* 0x126d: mov    r8b,0x45 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_8, 0, 69ULL);
x86_l_1270:
	/* 0x1270: cmp    BYTE PTR [rax-0x4],0x41 */
	X86_VM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744056529682497ULL);
x86_l_1274:
	/* 0x1274: jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0> */
	X86_VM_X86_JCC(X86_CC_NE, 0x1274, 0x12e0, x86_l_12e0);
x86_l_1276:
	/* 0x1276: cmp    BYTE PTR [rax-0x3],0x44 */
	X86_VM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744060824649796ULL);
x86_l_127a:
	/* 0x127a: jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0> */
	X86_VM_X86_JCC(X86_CC_NE, 0x127a, 0x12e0, x86_l_12e0);
x86_l_127c:
	/* 0x127c: mov    r10b,0x45 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_8, 0, 69ULL);
x86_l_127f:
	/* 0x127f: cmp    BYTE PTR [rax-0x2],0x20 */
	X86_VM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744065119617056ULL);
x86_l_1283:
	/* 0x1283: jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0> */
	X86_VM_X86_JCC(X86_CC_NE, 0x1283, 0x12e0, x86_l_12e0);
x86_l_1285:
	/* 0x1285: mov    r9d,0x5 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_32, 0, 5ULL);
x86_l_128b:
	/* 0x128b: mov    r8b,0x41 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_8, 0, 65ULL);
x86_l_128e:
	/* 0x128e: mov    r11b,0x44 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_8, 0, 68ULL);
x86_l_1291:
	/* 0x1291: jmp    12f0 <tracee_http_method_prefix_detect_xdp+0x1f0> */
	X86_VM_X86_JMP(0x1291, 0x12f0, x86_l_12f0);
x86_l_1293:
	/* 0x1293: mov    r8b,0x55 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_8, 0, 85ULL);
x86_l_1296:
	/* 0x1296: cmp    BYTE PTR [rax-0x4],0x54 */
	X86_VM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744056529682516ULL);
x86_l_129a:
	/* 0x129a: jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0> */
	X86_VM_X86_JCC(X86_CC_NE, 0x129a, 0x12e0, x86_l_12e0);
x86_l_129c:
	/* 0x129c: mov    r10b,0x55 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_8, 0, 85ULL);
x86_l_129f:
	/* 0x129f: cmp    BYTE PTR [rax-0x3],0x20 */
	X86_VM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744060824649760ULL);
x86_l_12a3:
	/* 0x12a3: jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0> */
	X86_VM_X86_JCC(X86_CC_NE, 0x12a3, 0x12e0, x86_l_12e0);
x86_l_12a5:
	/* 0x12a5: mov    r9d,0x3 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_32, 0, 3ULL);
x86_l_12ab:
	/* 0x12ab: mov    r8b,0x54 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_8, 0, 84ULL);
x86_l_12ae:
	/* 0x12ae: mov    r11b,0x20 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_8, 0, 32ULL);
x86_l_12b1:
	/* 0x12b1: jmp    12f0 <tracee_http_method_prefix_detect_xdp+0x1f0> */
	X86_VM_X86_JMP(0x12b1, 0x12f0, x86_l_12f0);
x86_l_12b3:
	/* 0x12b3: mov    r8b,0x54 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_8, 0, 84ULL);
x86_l_12b6:
	/* 0x12b6: cmp    BYTE PTR [rax-0x4],0x54 */
	X86_VM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744056529682516ULL);
x86_l_12ba:
	/* 0x12ba: jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0> */
	X86_VM_X86_JCC(X86_CC_NE, 0x12ba, 0x12e0, x86_l_12e0);
x86_l_12bc:
	/* 0x12bc: cmp    BYTE PTR [rax-0x3],0x50 */
	X86_VM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744060824649808ULL);
x86_l_12c0:
	/* 0x12c0: jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0> */
	X86_VM_X86_JCC(X86_CC_NE, 0x12c0, 0x12e0, x86_l_12e0);
x86_l_12c2:
	/* 0x12c2: cmp    BYTE PTR [rax-0x2],0x2f */
	X86_VM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744065119617071ULL);
x86_l_12c6:
	/* 0x12c6: jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0> */
	X86_VM_X86_JCC(X86_CC_NE, 0x12c6, 0x12e0, x86_l_12e0);
x86_l_12c8:
	/* 0x12c8: mov    r9d,0x6 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_32, 0, 6ULL);
x86_l_12ce:
	/* 0x12ce: mov    r11b,0x50 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_8, 0, 80ULL);
x86_l_12d1:
	/* 0x12d1: mov    r10b,0x54 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_8, 0, 84ULL);
x86_l_12d4:
	/* 0x12d4: jmp    12f0 <tracee_http_method_prefix_detect_xdp+0x1f0> */
	X86_VM_X86_JMP(0x12d4, 0x12f0, x86_l_12f0);
x86_l_12d6:
	/* 0x12d6: cs nop WORD PTR [rax+rax*1+0x0] */
	X86_VM_RUN_OP(X86_OP_NOP, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_12e0:
	/* 0x12e0: mov    r10d,r8d */
	X86_VM_RUN_OP(X86_OP_MOV_REG, X86_R10, X86_R8, X86_WIDTH_32, 0, 0);
x86_l_12e3:
	/* 0x12e3: movzx  r8d,BYTE PTR [rax-0x4] */
	X86_VM_RUN_OP(X86_OP_MOV_LOAD, X86_R8, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551612ULL);
x86_l_12e8:
	/* 0x12e8: movzx  r11d,BYTE PTR [rax-0x3] */
	X86_VM_RUN_OP(X86_OP_MOV_LOAD, X86_R11, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551613ULL);
x86_l_12ed:
	/* 0x12ed: xor    r9d,r9d */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_R9, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_12f0:
	/* 0x12f0: movzx  r11d,r11b */
	X86_VM_RUN_OP(X86_OP_MOVZX_REG, X86_R11, X86_R11, X86_WIDTH_32, X86_WIDTH_8, 0);
x86_l_12f4:
	/* 0x12f4: lea    ebx,[r9+0x1] */
	X86_VM_RUN_OP(X86_OP_LEA, X86_RBX, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_12f8:
	/* 0x12f8: lea    r14,[rcx+0xa] */
	X86_VM_RUN_OP(X86_OP_LEA, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 10ULL);
x86_l_12fc:
	/* 0x12fc: imul   rbx,r14 */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_RBX, X86_R14, X86_WIDTH_64, X86_ALU_IMUL, 0);
x86_l_1300:
	/* 0x1300: add    rsi,rbx */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1303:
	/* 0x1303: shl    r11,0x20 */
	X86_VM_RUN_OP(X86_OP_ALU_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_1307:
	/* 0x1307: movzx  r8d,r8b */
	X86_VM_RUN_OP(X86_OP_MOVZX_REG, X86_R8, X86_R8, X86_WIDTH_32, X86_WIDTH_8, 0);
x86_l_130b:
	/* 0x130b: shl    r8d,0x18 */
	X86_VM_RUN_OP(X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 24ULL);
x86_l_130f:
	/* 0x130f: movzx  r10d,r10b */
	X86_VM_RUN_OP(X86_OP_MOVZX_REG, X86_R10, X86_R10, X86_WIDTH_32, X86_WIDTH_8, 0);
x86_l_1313:
	/* 0x1313: shl    r10d,0x10 */
	X86_VM_RUN_OP(X86_OP_ALU_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 16ULL);
x86_l_1317:
	/* 0x1317: shl    edi,0x8 */
	X86_VM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 8ULL);
x86_l_131a:
	/* 0x131a: or     edi,r10d */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_RDI, X86_R10, X86_WIDTH_32, X86_ALU_OR, 0);
x86_l_131d:
	/* 0x131d: or     edi,r8d */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_RDI, X86_R8, X86_WIDTH_32, X86_ALU_OR, 0);
x86_l_1320:
	/* 0x1320: or     rdi,r11 */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_RDI, X86_R11, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_1323:
	/* 0x1323: mov    ebx,r9d */
	X86_VM_RUN_OP(X86_OP_MOV_REG, X86_RBX, X86_R9, X86_WIDTH_32, 0, 0);
x86_l_1326:
	/* 0x1326: or     rbx,rdi */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_RBX, X86_RDI, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_1329:
	/* 0x1329: shl    rbx,cl */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 0);
x86_l_132c:
	/* 0x132c: xor    rbx,rsi */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_RBX, X86_RSI, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_132f:
	/* 0x132f: add    rax,0x10 */
	X86_VM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1333:
	/* 0x1333: inc    rcx */
	X86_VM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1336:
	/* 0x1336: cmp    rcx,0x9 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, 0, 9ULL);
x86_l_133a:
	/* 0x133a: jne    1150 <tracee_http_method_prefix_detect_xdp+0x50> */
	X86_VM_X86_JCC(X86_CC_NE, 0x133a, 0x1150, x86_l_1150);
x86_l_1340:
	/* 0x1340: mov    BYTE PTR [rdx],sil */
	X86_VM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RSI, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1343:
	/* 0x1343: mov    BYTE PTR [rdx+0x1],bh */
	X86_VM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RBX, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_REG_AUX_SRC_SHIFT(8)), 1ULL);
x86_l_1346:
	/* 0x1346: mov    eax,ebx */
	X86_VM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RBX, X86_WIDTH_32, 0, 0);
x86_l_1348:
	/* 0x1348: shr    eax,0x10 */
	X86_VM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_134b:
	/* 0x134b: mov    BYTE PTR [rdx+0x2],al */
	X86_VM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_134e:
	/* 0x134e: mov    eax,ebx */
	X86_VM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RBX, X86_WIDTH_32, 0, 0);
x86_l_1350:
	/* 0x1350: shr    eax,0x18 */
	X86_VM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHR, 24ULL);
x86_l_1353:
	/* 0x1353: mov    BYTE PTR [rdx+0x3],al */
	X86_VM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 3ULL);
x86_l_1356:
	/* 0x1356: mov    rax,rbx */
	X86_VM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_1359:
	/* 0x1359: shr    rax,0x20 */
	X86_VM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_135d:
	/* 0x135d: mov    BYTE PTR [rdx+0x4],al */
	X86_VM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1360:
	/* 0x1360: mov    rax,rbx */
	X86_VM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_1363:
	/* 0x1363: shr    rax,0x28 */
	X86_VM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 40ULL);
x86_l_1367:
	/* 0x1367: mov    BYTE PTR [rdx+0x5],al */
	X86_VM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_136a:
	/* 0x136a: mov    rax,rbx */
	X86_VM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_136d:
	/* 0x136d: shr    rax,0x30 */
	X86_VM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 48ULL);
x86_l_1371:
	/* 0x1371: mov    BYTE PTR [rdx+0x6],al */
	X86_VM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_1374:
	/* 0x1374: shr    rbx,0x38 */
	X86_VM_RUN_OP(X86_OP_ALU_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 56ULL);
x86_l_1378:
	/* 0x1378: mov    BYTE PTR [rdx+0x7],bl */
	X86_VM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RBX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 7ULL);
x86_l_137b:
	/* 0x137b: mov    eax,0x2 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_1380:
	/* 0x1380: pop    rbx */
	X86_VM_RUN_OP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1381:
	/* 0x1381: pop    r14 */
	X86_VM_RUN_OP(X86_OP_POP, X86_R14, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1383:
	/* 0x1383: pop    rbp */
	X86_VM_RUN_OP(X86_OP_POP, X86_RBP, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1384:
	/* 0x1384: ret */
	X86_VM_X86_RET();
	return XDP_ABORTED;
}

X86_VM_LICENSE();
