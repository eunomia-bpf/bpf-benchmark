#define X86_VM_ENABLE_STACK 1
#include "../x86_vm_bpf.h"

SEC("xdp")
int packet_toeplitz_rss_hash_x86_vm_xdp(struct xdp_md *ctx)
{
	X86_VM_DECLARE_XDP(ctx);
x86_l_1100:
	/* 0x1100: mov    rsi,QWORD PTR [rdi] */
	X86_VM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1103:
	/* 0x1103: mov    rcx,QWORD PTR [rdi+0x8] */
	X86_VM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1107:
	/* 0x1107: xor    eax,eax */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1109:
	/* 0x1109: cmp    rsi,rcx */
	X86_VM_RUN_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_110c:
	/* 0x110c: jbe    110f <packet_toeplitz_rss_hash_xdp+0xf> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_BE))
		goto x86_l_110f;
x86_l_110e:
	/* 0x110e: ret */
	X86_VM_RET_RAX();
x86_l_110f:
	/* 0x110f: lea    rdx,[rsi+0x8] */
	X86_VM_RUN_OP(X86_OP_LEA, X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1113:
	/* 0x1113: cmp    rdx,rcx */
	X86_VM_RUN_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_1116:
	/* 0x1116: ja     110e <packet_toeplitz_rss_hash_xdp+0xe> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_110e;
x86_l_1118:
	/* 0x1118: lea    rdx,[rsi+0x3e] */
	X86_VM_RUN_OP(X86_OP_LEA, X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 62ULL);
x86_l_111c:
	/* 0x111c: cmp    rdx,rcx */
	X86_VM_RUN_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_111f:
	/* 0x111f: ja     110e <packet_toeplitz_rss_hash_xdp+0xe> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_110e;
x86_l_1121:
	/* 0x1121: movzx  ecx,WORD PTR [rsi+0x14] */
	X86_VM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 20ULL);
x86_l_1125:
	/* 0x1125: rol    cx,0x8 */
	X86_VM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_ALU_ROL, 8ULL);
x86_l_1129:
	/* 0x1129: movzx  ecx,cx */
	X86_VM_RUN_OP(X86_OP_MOVZX_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_112c:
	/* 0x112c: cmp    ecx,0x800 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 2048ULL);
x86_l_1132:
	/* 0x1132: jne    110e <packet_toeplitz_rss_hash_xdp+0xe> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_110e;
x86_l_1134:
	/* 0x1134: movzx  ecx,BYTE PTR [rsi+0x16] */
	X86_VM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 22ULL);
x86_l_1138:
	/* 0x1138: and    cl,0xf */
	X86_VM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_ALU_AND, 15ULL);
x86_l_113b:
	/* 0x113b: cmp    cl,0x5 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, 0, 5ULL);
x86_l_113e:
	/* 0x113e: jne    110e <packet_toeplitz_rss_hash_xdp+0xe> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_110e;
x86_l_1140:
	/* 0x1140: cmp    BYTE PTR [rsi+0x1f],0x6 */
	X86_VM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 133143986182ULL);
x86_l_1144:
	/* 0x1144: jne    110e <packet_toeplitz_rss_hash_xdp+0xe> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_110e;
x86_l_1146:
	/* 0x1146: push   rbp */
	X86_VM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_1147:
	/* 0x1147: mov    rbp,rsp */
	X86_VM_RUN_OP(X86_OP_MOV_REG, X86_RBP, X86_RSP, X86_WIDTH_64, 0, 0);
x86_l_114a:
	/* 0x114a: lea    rdi,[rsi+0x1f] */
	X86_VM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 31ULL);
x86_l_114e:
	/* 0x114e: lea    r8,[rsi+0x22] */
	X86_VM_RUN_OP(X86_OP_LEA, X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_1152:
	/* 0x1152: xor    eax,eax */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1154:
	/* 0x1154: xor    r9d,r9d */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_R9, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1157:
	/* 0x1157: jmp    117c <packet_toeplitz_rss_hash_xdp+0x7c> */
	goto x86_l_117c;
x86_l_1159:
	/* 0x1159: mov    r11d,0xc2 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_32, 0, 194ULL);
x86_l_115f:
	/* 0x115f: nop */
	X86_VM_RUN_OP(X86_OP_NOP, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1160:
	/* 0x1160: mov    dl,0x8 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, 0, 8ULL);
x86_l_1162:
	/* 0x1162: sub    dl,cl */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB, 0);
x86_l_1164:
	/* 0x1164: mov    ecx,edx */
	X86_VM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_1166:
	/* 0x1166: shr    r11d,cl */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_R11, X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 0);
x86_l_1169:
	/* 0x1169: or     r10d,r11d */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_R10, X86_R11, X86_WIDTH_32, X86_ALU_OR, 0);
x86_l_116c:
	/* 0x116c: xor    eax,r10d */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_R10, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_116f:
	/* 0x116f: inc    r9d */
	X86_VM_RUN_OP(X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1172:
	/* 0x1172: cmp    r9d,0x68 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_32, 0, 104ULL);
x86_l_1176:
	/* 0x1176: je     1389 <packet_toeplitz_rss_hash_xdp+0x289> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_E))
		goto x86_l_1389;
x86_l_117c:
	/* 0x117c: mov    edx,r9d */
	X86_VM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R9, X86_WIDTH_32, 0, 0);
x86_l_117f:
	/* 0x117f: shr    edx,0x3 */
	X86_VM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHR, 3ULL);
x86_l_1182:
	/* 0x1182: cmp    r9d,0x1f */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_32, 0, 31ULL);
x86_l_1186:
	/* 0x1186: jbe    11a0 <packet_toeplitz_rss_hash_xdp+0xa0> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_BE))
		goto x86_l_11a0;
x86_l_1188:
	/* 0x1188: cmp    r9d,0x3f */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_32, 0, 63ULL);
x86_l_118c:
	/* 0x118c: jbe    11a0 <packet_toeplitz_rss_hash_xdp+0xa0> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_BE))
		goto x86_l_11a0;
x86_l_118e:
	/* 0x118e: cmp    r9d,0x4f */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_32, 0, 79ULL);
x86_l_1192:
	/* 0x1192: jbe    11a0 <packet_toeplitz_rss_hash_xdp+0xa0> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_BE))
		goto x86_l_11a0;
x86_l_1194:
	/* 0x1194: mov    rcx,rdi */
	X86_VM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RDI, X86_WIDTH_64, 0, 0);
x86_l_1197:
	/* 0x1197: cmp    r9d,0x5f */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_32, 0, 95ULL);
x86_l_119b:
	/* 0x119b: ja     11a5 <packet_toeplitz_rss_hash_xdp+0xa5> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_11a5;
x86_l_119d:
	/* 0x119d: nop    DWORD PTR [rax] */
	X86_VM_RUN_OP(X86_OP_NOP, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_11a0:
	/* 0x11a0: mov    ecx,edx */
	X86_VM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_11a2:
	/* 0x11a2: add    rcx,r8 */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_R8, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_11a5:
	/* 0x11a5: movzx  r10d,BYTE PTR [rcx] */
	X86_VM_RUN_OP(X86_OP_MOV_LOAD, X86_R10, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_11a9:
	/* 0x11a9: mov    ecx,r9d */
	X86_VM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_R9, X86_WIDTH_32, 0, 0);
x86_l_11ac:
	/* 0x11ac: and    ecx,0x7 */
	X86_VM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_11af:
	/* 0x11af: shl    r10d,cl */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_R10, X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 0);
x86_l_11b2:
	/* 0x11b2: test   r10b,r10b */
	X86_VM_RUN_OP(X86_OP_TEST_REG, X86_R10, X86_R10, X86_WIDTH_8, 0, 0);
x86_l_11b5:
	/* 0x11b5: jns    116f <packet_toeplitz_rss_hash_xdp+0x6f> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NS))
		goto x86_l_116f;
x86_l_11b7:
	/* 0x11b7: cmp    edx,0x5 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 5ULL);
x86_l_11ba:
	/* 0x11ba: jle    11e0 <packet_toeplitz_rss_hash_xdp+0xe0> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_LE))
		goto x86_l_11e0;
x86_l_11bc:
	/* 0x11bc: cmp    edx,0x8 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_11bf:
	/* 0x11bf: jle    1203 <packet_toeplitz_rss_hash_xdp+0x103> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_LE))
		goto x86_l_1203;
x86_l_11c1:
	/* 0x11c1: cmp    edx,0xa */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 10ULL);
x86_l_11c4:
	/* 0x11c4: jg     123d <packet_toeplitz_rss_hash_xdp+0x13d> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_G))
		goto x86_l_123d;
x86_l_11c6:
	/* 0x11c6: cmp    edx,0x9 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 9ULL);
x86_l_11c9:
	/* 0x11c9: jne    1288 <packet_toeplitz_rss_hash_xdp+0x188> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_1288;
x86_l_11cf:
	/* 0x11cf: mov    r11d,0x43 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_32, 0, 67ULL);
x86_l_11d5:
	/* 0x11d5: mov    r10d,0x67253d00 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_32, 0, 1730493696ULL);
x86_l_11db:
	/* 0x11db: jmp    12c0 <packet_toeplitz_rss_hash_xdp+0x1c0> */
	goto x86_l_12c0;
x86_l_11e0:
	/* 0x11e0: cmp    edx,0x2 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_11e3:
	/* 0x11e3: jg     121e <packet_toeplitz_rss_hash_xdp+0x11e> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_G))
		goto x86_l_121e;
x86_l_11e5:
	/* 0x11e5: test   edx,edx */
	X86_VM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_11e7:
	/* 0x11e7: je     125e <packet_toeplitz_rss_hash_xdp+0x15e> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_E))
		goto x86_l_125e;
x86_l_11e9:
	/* 0x11e9: cmp    edx,0x1 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_11ec:
	/* 0x11ec: jne    12a4 <packet_toeplitz_rss_hash_xdp+0x1a4> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_12a4;
x86_l_11f2:
	/* 0x11f2: mov    r11d,0x25 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_32, 0, 37ULL);
x86_l_11f8:
	/* 0x11f8: mov    r10d,0x5a56da00 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_32, 0, 1515641344ULL);
x86_l_11fe:
	/* 0x11fe: jmp    12c0 <packet_toeplitz_rss_hash_xdp+0x1c0> */
	goto x86_l_12c0;
x86_l_1203:
	/* 0x1203: cmp    edx,0x6 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 6ULL);
x86_l_1206:
	/* 0x1206: je     1250 <packet_toeplitz_rss_hash_xdp+0x150> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_E))
		goto x86_l_1250;
x86_l_1208:
	/* 0x1208: cmp    edx,0x7 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 7ULL);
x86_l_120b:
	/* 0x120b: jne    127a <packet_toeplitz_rss_hash_xdp+0x17a> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_127a;
x86_l_120d:
	/* 0x120d: mov    r11d,0x25 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_32, 0, 37ULL);
x86_l_1213:
	/* 0x1213: mov    r10d,0xc2416700 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_32, 0, 3259066112ULL);
x86_l_1219:
	/* 0x1219: jmp    12c0 <packet_toeplitz_rss_hash_xdp+0x1c0> */
	goto x86_l_12c0;
x86_l_121e:
	/* 0x121e: cmp    edx,0x3 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 3ULL);
x86_l_1221:
	/* 0x1221: je     126c <packet_toeplitz_rss_hash_xdp+0x16c> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_E))
		goto x86_l_126c;
x86_l_1223:
	/* 0x1223: cmp    edx,0x4 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_1226:
	/* 0x1226: jne    12b2 <packet_toeplitz_rss_hash_xdp+0x1b2> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_12b2;
x86_l_122c:
	/* 0x122c: mov    r11d,0xc2 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_32, 0, 194ULL);
x86_l_1232:
	/* 0x1232: mov    r10d,0x255b0e00 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_32, 0, 626724352ULL);
x86_l_1238:
	/* 0x1238: jmp    12c0 <packet_toeplitz_rss_hash_xdp+0x1c0> */
	goto x86_l_12c0;
x86_l_123d:
	/* 0x123d: cmp    edx,0xb */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 11ULL);
x86_l_1240:
	/* 0x1240: jne    1296 <packet_toeplitz_rss_hash_xdp+0x196> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_1296;
x86_l_1242:
	/* 0x1242: mov    r11d,0x8f */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_32, 0, 143ULL);
x86_l_1248:
	/* 0x1248: mov    r10d,0x3d43a300 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_32, 0, 1027842816ULL);
x86_l_124e:
	/* 0x124e: jmp    12c0 <packet_toeplitz_rss_hash_xdp+0x1c0> */
	goto x86_l_12c0;
x86_l_1250:
	/* 0x1250: mov    r11d,0x67 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_32, 0, 103ULL);
x86_l_1256:
	/* 0x1256: mov    r10d,0xec24100 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_32, 0, 247611648ULL);
x86_l_125c:
	/* 0x125c: jmp    12c0 <packet_toeplitz_rss_hash_xdp+0x1c0> */
	goto x86_l_12c0;
x86_l_125e:
	/* 0x125e: mov    r11d,0xda */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_32, 0, 218ULL);
x86_l_1264:
	/* 0x1264: mov    r10d,0x6d5a5600 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_32, 0, 1834636800ULL);
x86_l_126a:
	/* 0x126a: jmp    12c0 <packet_toeplitz_rss_hash_xdp+0x1c0> */
	goto x86_l_12c0;
x86_l_126c:
	/* 0x126c: mov    r11d,0xe */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_32, 0, 14ULL);
x86_l_1272:
	/* 0x1272: mov    r10d,0xda255b00 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_32, 0, 3659881216ULL);
x86_l_1278:
	/* 0x1278: jmp    12c0 <packet_toeplitz_rss_hash_xdp+0x1c0> */
	goto x86_l_12c0;
x86_l_127a:
	/* 0x127a: mov    r11d,0x3d */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_32, 0, 61ULL);
x86_l_1280:
	/* 0x1280: mov    r10d,0x41672500 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_32, 0, 1097278720ULL);
x86_l_1286:
	/* 0x1286: jmp    12c0 <packet_toeplitz_rss_hash_xdp+0x1c0> */
	goto x86_l_12c0;
x86_l_1288:
	/* 0x1288: mov    r11d,0xa3 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_32, 0, 163ULL);
x86_l_128e:
	/* 0x128e: mov    r10d,0x253d4300 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_32, 0, 624771840ULL);
x86_l_1294:
	/* 0x1294: jmp    12c0 <packet_toeplitz_rss_hash_xdp+0x1c0> */
	goto x86_l_12c0;
x86_l_1296:
	/* 0x1296: mov    r11d,0xb0 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_32, 0, 176ULL);
x86_l_129c:
	/* 0x129c: mov    r10d,0x43a38f00 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_32, 0, 1134792448ULL);
x86_l_12a2:
	/* 0x12a2: jmp    12c0 <packet_toeplitz_rss_hash_xdp+0x1c0> */
	goto x86_l_12c0;
x86_l_12a4:
	/* 0x12a4: mov    r11d,0x5b */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_32, 0, 91ULL);
x86_l_12aa:
	/* 0x12aa: mov    r10d,0x56da2500 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_32, 0, 1457136896ULL);
x86_l_12b0:
	/* 0x12b0: jmp    12c0 <packet_toeplitz_rss_hash_xdp+0x1c0> */
	goto x86_l_12c0;
x86_l_12b2:
	/* 0x12b2: mov    r11d,0x41 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_32, 0, 65ULL);
x86_l_12b8:
	/* 0x12b8: mov    r10d,0x5b0ec200 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_32, 0, 1527693824ULL);
x86_l_12be:
	/* 0x12be: xchg   ax,ax */
	X86_VM_RUN_OP(X86_OP_XCHG, X86_RAX, X86_RAX, X86_WIDTH_16, 0, 0);
x86_l_12c0:
	/* 0x12c0: or     r10d,r11d */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_R10, X86_R11, X86_WIDTH_32, X86_ALU_OR, 0);
x86_l_12c3:
	/* 0x12c3: test   ecx,ecx */
	X86_VM_RUN_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_12c5:
	/* 0x12c5: je     116c <packet_toeplitz_rss_hash_xdp+0x6c> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_E))
		goto x86_l_116c;
x86_l_12cb:
	/* 0x12cb: shl    r10d,cl */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_R10, X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 0);
x86_l_12ce:
	/* 0x12ce: mov    r11d,0x25 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_32, 0, 37ULL);
x86_l_12d4:
	/* 0x12d4: cmp    edx,0x5 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 5ULL);
x86_l_12d7:
	/* 0x12d7: jle    12f3 <packet_toeplitz_rss_hash_xdp+0x1f3> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_LE))
		goto x86_l_12f3;
x86_l_12d9:
	/* 0x12d9: cmp    edx,0x8 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_12dc:
	/* 0x12dc: jle    1310 <packet_toeplitz_rss_hash_xdp+0x210> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_LE))
		goto x86_l_1310;
x86_l_12de:
	/* 0x12de: cmp    edx,0xa */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 10ULL);
x86_l_12e1:
	/* 0x12e1: jg     1342 <packet_toeplitz_rss_hash_xdp+0x242> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_G))
		goto x86_l_1342;
x86_l_12e3:
	/* 0x12e3: cmp    edx,0x9 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 9ULL);
x86_l_12e6:
	/* 0x12e6: jne    135d <packet_toeplitz_rss_hash_xdp+0x25d> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_135d;
x86_l_12e8:
	/* 0x12e8: mov    r11d,0xa3 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_32, 0, 163ULL);
x86_l_12ee:
	/* 0x12ee: jmp    1160 <packet_toeplitz_rss_hash_xdp+0x60> */
	goto x86_l_1160;
x86_l_12f3:
	/* 0x12f3: cmp    edx,0x2 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_12f6:
	/* 0x12f6: jg     1329 <packet_toeplitz_rss_hash_xdp+0x229> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_G))
		goto x86_l_1329;
x86_l_12f8:
	/* 0x12f8: test   edx,edx */
	X86_VM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_12fa:
	/* 0x12fa: je     1160 <packet_toeplitz_rss_hash_xdp+0x60> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_E))
		goto x86_l_1160;
x86_l_1300:
	/* 0x1300: cmp    edx,0x1 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_1303:
	/* 0x1303: jne    1373 <packet_toeplitz_rss_hash_xdp+0x273> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_1373;
x86_l_1305:
	/* 0x1305: mov    r11d,0x5b */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_32, 0, 91ULL);
x86_l_130b:
	/* 0x130b: jmp    1160 <packet_toeplitz_rss_hash_xdp+0x60> */
	goto x86_l_1160;
x86_l_1310:
	/* 0x1310: cmp    edx,0x6 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 6ULL);
x86_l_1313:
	/* 0x1313: je     1160 <packet_toeplitz_rss_hash_xdp+0x60> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_E))
		goto x86_l_1160;
x86_l_1319:
	/* 0x1319: cmp    edx,0x7 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 7ULL);
x86_l_131c:
	/* 0x131c: jne    1352 <packet_toeplitz_rss_hash_xdp+0x252> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_1352;
x86_l_131e:
	/* 0x131e: mov    r11d,0x3d */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_32, 0, 61ULL);
x86_l_1324:
	/* 0x1324: jmp    1160 <packet_toeplitz_rss_hash_xdp+0x60> */
	goto x86_l_1160;
x86_l_1329:
	/* 0x1329: cmp    edx,0x3 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 3ULL);
x86_l_132c:
	/* 0x132c: je     1159 <packet_toeplitz_rss_hash_xdp+0x59> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_E))
		goto x86_l_1159;
x86_l_1332:
	/* 0x1332: cmp    edx,0x4 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_1335:
	/* 0x1335: jne    137e <packet_toeplitz_rss_hash_xdp+0x27e> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_137e;
x86_l_1337:
	/* 0x1337: mov    r11d,0x41 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_32, 0, 65ULL);
x86_l_133d:
	/* 0x133d: jmp    1160 <packet_toeplitz_rss_hash_xdp+0x60> */
	goto x86_l_1160;
x86_l_1342:
	/* 0x1342: cmp    edx,0xb */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 11ULL);
x86_l_1345:
	/* 0x1345: jne    1368 <packet_toeplitz_rss_hash_xdp+0x268> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_1368;
x86_l_1347:
	/* 0x1347: mov    r11d,0xb0 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_32, 0, 176ULL);
x86_l_134d:
	/* 0x134d: jmp    1160 <packet_toeplitz_rss_hash_xdp+0x60> */
	goto x86_l_1160;
x86_l_1352:
	/* 0x1352: mov    r11d,0x43 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_32, 0, 67ULL);
x86_l_1358:
	/* 0x1358: jmp    1160 <packet_toeplitz_rss_hash_xdp+0x60> */
	goto x86_l_1160;
x86_l_135d:
	/* 0x135d: mov    r11d,0x8f */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_32, 0, 143ULL);
x86_l_1363:
	/* 0x1363: jmp    1160 <packet_toeplitz_rss_hash_xdp+0x60> */
	goto x86_l_1160;
x86_l_1368:
	/* 0x1368: mov    r11d,0xd0 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_32, 0, 208ULL);
x86_l_136e:
	/* 0x136e: jmp    1160 <packet_toeplitz_rss_hash_xdp+0x60> */
	goto x86_l_1160;
x86_l_1373:
	/* 0x1373: mov    r11d,0xe */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_32, 0, 14ULL);
x86_l_1379:
	/* 0x1379: jmp    1160 <packet_toeplitz_rss_hash_xdp+0x60> */
	goto x86_l_1160;
x86_l_137e:
	/* 0x137e: mov    r11d,0x67 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_32, 0, 103ULL);
x86_l_1384:
	/* 0x1384: jmp    1160 <packet_toeplitz_rss_hash_xdp+0x60> */
	goto x86_l_1160;
x86_l_1389:
	/* 0x1389: mov    edx,DWORD PTR [rsi+0x26] */
	X86_VM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_138c:
	/* 0x138c: movzx  r9d,BYTE PTR [rsi+0x2a] */
	X86_VM_RUN_OP(X86_OP_MOV_LOAD, X86_R9, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_1391:
	/* 0x1391: movzx  r10d,BYTE PTR [rsi+0x2b] */
	X86_VM_RUN_OP(X86_OP_MOV_LOAD, X86_R10, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_1396:
	/* 0x1396: movzx  r8d,BYTE PTR [rsi+0x2c] */
	X86_VM_RUN_OP(X86_OP_MOV_LOAD, X86_R8, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 44ULL);
x86_l_139b:
	/* 0x139b: movzx  ecx,BYTE PTR [rsi+0x2d] */
	X86_VM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 45ULL);
x86_l_139f:
	/* 0x139f: mov    r11,rax */
	X86_VM_RUN_OP(X86_OP_MOV_REG, X86_R11, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_13a2:
	/* 0x13a2: shl    r11,0x20 */
	X86_VM_RUN_OP(X86_OP_ALU_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_13a6:
	/* 0x13a6: xor    edx,DWORD PTR [rsi+0x22] */
	X86_VM_RUN_OP(X86_OP_ALU_MEM, X86_RDX, X86_RSI, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 34ULL);
x86_l_13a9:
	/* 0x13a9: bswap  edx */
	X86_VM_RUN_OP(X86_OP_BSWAP, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 0);
x86_l_13ab:
	/* 0x13ab: mov    edi,edx */
	X86_VM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_13ad:
	/* 0x13ad: xor    edi,eax */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_13af:
	/* 0x13af: or     rdi,r11 */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_RDI, X86_R11, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_13b2:
	/* 0x13b2: shl    r9,0x38 */
	X86_VM_RUN_OP(X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 56ULL);
x86_l_13b6:
	/* 0x13b6: shl    r10,0x30 */
	X86_VM_RUN_OP(X86_OP_ALU_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 48ULL);
x86_l_13ba:
	/* 0x13ba: or     r10,r9 */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_R10, X86_R9, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_13bd:
	/* 0x13bd: shl    r8,0x28 */
	X86_VM_RUN_OP(X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 40ULL);
x86_l_13c1:
	/* 0x13c1: or     r8,r10 */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_R8, X86_R10, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_13c4:
	/* 0x13c4: shl    rcx,0x20 */
	X86_VM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_13c8:
	/* 0x13c8: or     rdx,r8 */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_R8, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_13cb:
	/* 0x13cb: or     rdx,rcx */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_13ce:
	/* 0x13ce: and    eax,0x7 */
	X86_VM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_13d1:
	/* 0x13d1: lea    ecx,[rax+0x1] */
	X86_VM_RUN_OP(X86_OP_LEA, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_13d4:
	/* 0x13d4: mov    r8,rdx */
	X86_VM_RUN_OP(X86_OP_MOV_REG, X86_R8, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_13d7:
	/* 0x13d7: shl    r8,cl */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_R8, X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 0);
x86_l_13da:
	/* 0x13da: not    al */
	X86_VM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_ALU_NOT, 0);
x86_l_13dc:
	/* 0x13dc: mov    ecx,eax */
	X86_VM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_13de:
	/* 0x13de: shr    rdx,cl */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 0);
x86_l_13e1:
	/* 0x13e1: or     rdx,r8 */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_R8, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_13e4:
	/* 0x13e4: xor    rdx,rdi */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RDI, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_13e7:
	/* 0x13e7: mov    QWORD PTR [rsi],rdx */
	X86_VM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13ea:
	/* 0x13ea: mov    eax,0x2 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_13ef:
	/* 0x13ef: pop    rbp */
	X86_VM_RUN_OP(X86_OP_POP, X86_RBP, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_13f0:
	/* 0x13f0: ret */
	X86_VM_RET_RAX();

	return XDP_ABORTED;
}

X86_VM_LICENSE();
