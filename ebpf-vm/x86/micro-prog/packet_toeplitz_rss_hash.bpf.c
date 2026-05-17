#define X86_VM_ENABLE_RODATA 1
#include "../x86_vm_bpf.h"

SEC("xdp")
int packet_toeplitz_rss_hash_x86_vm_xdp(struct xdp_md *ctx)
{
	X86_VM_DECLARE_XDP(ctx);
x86_l_1100:
	/* 0x1100: mov    rsi,QWORD PTR [rdi] */
	X86_VM_RUN_STEP(X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1103:
	/* 0x1103: mov    rcx,QWORD PTR [rdi+0x8] */
	X86_VM_RUN_STEP(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1107:
	/* 0x1107: xor    eax,eax */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1109:
	/* 0x1109: cmp    rsi,rcx */
	X86_VM_RUN_STEP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_110c:
	/* 0x110c: jbe    110f <packet_toeplitz_rss_hash_xdp+0xf> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_BE))
		goto x86_l_110f;
x86_l_110e:
	/* 0x110e: ret */
	X86_VM_RET_RAX();
x86_l_110f:
	/* 0x110f: lea    rdx,[rsi+0x8] */
	X86_VM_RUN_STEP(X86_OP_LEA, X86_RDX, X86_RSI, X86_WIDTH_64, 0, 8ULL);
x86_l_1113:
	/* 0x1113: cmp    rdx,rcx */
	X86_VM_RUN_STEP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_1116:
	/* 0x1116: ja     110e <packet_toeplitz_rss_hash_xdp+0xe> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_110e;
x86_l_1118:
	/* 0x1118: lea    rdx,[rsi+0x3e] */
	X86_VM_RUN_STEP(X86_OP_LEA, X86_RDX, X86_RSI, X86_WIDTH_64, 0, 62ULL);
x86_l_111c:
	/* 0x111c: cmp    rdx,rcx */
	X86_VM_RUN_STEP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_111f:
	/* 0x111f: ja     110e <packet_toeplitz_rss_hash_xdp+0xe> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_110e;
x86_l_1121:
	/* 0x1121: movzx  ecx,WORD PTR [rsi+0x14] */
	X86_VM_RUN_STEP(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 20ULL);
x86_l_1125:
	/* 0x1125: rol    cx,0x8 */
	X86_VM_RUN_STEP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_ALU_ROL, 8ULL);
x86_l_1129:
	/* 0x1129: movzx  ecx,cx */
	X86_VM_RUN_STEP(X86_OP_MOVZX_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_112c:
	/* 0x112c: cmp    ecx,0x800 */
	X86_VM_RUN_STEP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 2048ULL);
x86_l_1132:
	/* 0x1132: jne    110e <packet_toeplitz_rss_hash_xdp+0xe> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_110e;
x86_l_1134:
	/* 0x1134: movzx  ecx,BYTE PTR [rsi+0x16] */
	X86_VM_RUN_STEP(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 22ULL);
x86_l_1138:
	/* 0x1138: and    cl,0xf */
	X86_VM_RUN_STEP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_ALU_AND, 15ULL);
x86_l_113b:
	/* 0x113b: cmp    cl,0x5 */
	X86_VM_RUN_STEP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, 0, 5ULL);
x86_l_113e:
	/* 0x113e: jne    110e <packet_toeplitz_rss_hash_xdp+0xe> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_110e;
x86_l_1140:
	/* 0x1140: cmp    BYTE PTR [rsi+0x1f],0x6 */
	X86_VM_RUN_STEP(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 133143986182ULL);
x86_l_1144:
	/* 0x1144: jne    110e <packet_toeplitz_rss_hash_xdp+0xe> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_110e;
x86_l_1146:
	/* 0x1146: push   rbp */
	X86_VM_RUN_STEP(X86_OP_PUSH, X86_REG_NONE, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_1147:
	/* 0x1147: push   r14 */
	X86_VM_RUN_STEP(X86_OP_PUSH, X86_REG_NONE, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_1149:
	/* 0x1149: push   rbx */
	X86_VM_RUN_STEP(X86_OP_PUSH, X86_REG_NONE, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_114a:
	/* 0x114a: lea    rdi,[rsi+0x1f] */
	X86_VM_RUN_STEP(X86_OP_LEA, X86_RDI, X86_RSI, X86_WIDTH_64, 0, 31ULL);
x86_l_114e:
	/* 0x114e: lea    r8,[rsi+0x22] */
	X86_VM_RUN_STEP(X86_OP_LEA, X86_R8, X86_RSI, X86_WIDTH_64, 0, 34ULL);
x86_l_1152:
	/* 0x1152: xor    eax,eax */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1154:
	/* 0x1154: lea    r9,[rip+0xea5] */
	X86_VM_RUN_STEP(X86_OP_LEA, X86_R9, X86_REG_NONE, X86_WIDTH_64, X86_PTR_RODATA, 3749ULL);
x86_l_115b:
	/* 0x115b: lea    r10,[rip+0xed2] */
	X86_VM_RUN_STEP(X86_OP_LEA, X86_R10, X86_REG_NONE, X86_WIDTH_64, X86_PTR_RODATA, 3794ULL);
x86_l_1162:
	/* 0x1162: lea    r11,[rip+0xeff] */
	X86_VM_RUN_STEP(X86_OP_LEA, X86_R11, X86_REG_NONE, X86_WIDTH_64, X86_PTR_RODATA, 3839ULL);
x86_l_1169:
	/* 0x1169: xor    ebx,ebx */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_116b:
	/* 0x116b: jmp    1179 <packet_toeplitz_rss_hash_xdp+0x79> */
	goto x86_l_1179;
x86_l_116d:
	/* 0x116d: nop    DWORD PTR [rax] */
	X86_VM_RUN_STEP(X86_OP_NOP, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1170:
	/* 0x1170: xor    eax,ebp */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1172:
	/* 0x1172: inc    ebx */
	X86_VM_RUN_STEP(X86_OP_ALU_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1174:
	/* 0x1174: cmp    ebx,0x68 */
	X86_VM_RUN_STEP(X86_OP_CMP_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 104ULL);
x86_l_1177:
	/* 0x1177: je     11d6 <packet_toeplitz_rss_hash_xdp+0xd6> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_E))
		goto x86_l_11d6;
x86_l_1179:
	/* 0x1179: mov    edx,ebx */
	X86_VM_RUN_STEP(X86_OP_MOV_REG, X86_RDX, X86_RBX, X86_WIDTH_32, 0, 0);
x86_l_117b:
	/* 0x117b: shr    edx,0x3 */
	X86_VM_RUN_STEP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHR, 3ULL);
x86_l_117e:
	/* 0x117e: cmp    ebx,0x1f */
	X86_VM_RUN_STEP(X86_OP_CMP_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 31ULL);
x86_l_1181:
	/* 0x1181: jbe    11a0 <packet_toeplitz_rss_hash_xdp+0xa0> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_BE))
		goto x86_l_11a0;
x86_l_1183:
	/* 0x1183: cmp    ebx,0x3f */
	X86_VM_RUN_STEP(X86_OP_CMP_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 63ULL);
x86_l_1186:
	/* 0x1186: jbe    11a0 <packet_toeplitz_rss_hash_xdp+0xa0> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_BE))
		goto x86_l_11a0;
x86_l_1188:
	/* 0x1188: cmp    ebx,0x4f */
	X86_VM_RUN_STEP(X86_OP_CMP_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 79ULL);
x86_l_118b:
	/* 0x118b: jbe    11a0 <packet_toeplitz_rss_hash_xdp+0xa0> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_BE))
		goto x86_l_11a0;
x86_l_118d:
	/* 0x118d: mov    rcx,rdi */
	X86_VM_RUN_STEP(X86_OP_MOV_REG, X86_RCX, X86_RDI, X86_WIDTH_64, 0, 0);
x86_l_1190:
	/* 0x1190: cmp    ebx,0x5f */
	X86_VM_RUN_STEP(X86_OP_CMP_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 95ULL);
x86_l_1193:
	/* 0x1193: ja     11a5 <packet_toeplitz_rss_hash_xdp+0xa5> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_11a5;
x86_l_1195:
	/* 0x1195: data16 cs nop WORD PTR [rax+rax*1+0x0] */
	X86_VM_RUN_STEP(X86_OP_NOP, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_11a0:
	/* 0x11a0: mov    ecx,edx */
	X86_VM_RUN_STEP(X86_OP_MOV_REG, X86_RCX, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_11a2:
	/* 0x11a2: add    rcx,r8 */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_RCX, X86_R8, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_11a5:
	/* 0x11a5: movzx  ebp,BYTE PTR [rcx] */
	X86_VM_RUN_STEP(X86_OP_MOV_LOAD, X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_11a8:
	/* 0x11a8: mov    ecx,ebx */
	X86_VM_RUN_STEP(X86_OP_MOV_REG, X86_RCX, X86_RBX, X86_WIDTH_32, 0, 0);
x86_l_11aa:
	/* 0x11aa: and    ecx,0x7 */
	X86_VM_RUN_STEP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_11ad:
	/* 0x11ad: shl    ebp,cl */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_RBP, X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 0);
x86_l_11af:
	/* 0x11af: test   bpl,bpl */
	X86_VM_RUN_STEP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_8, 0, 0);
x86_l_11b2:
	/* 0x11b2: jns    1172 <packet_toeplitz_rss_hash_xdp+0x72> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NS))
		goto x86_l_1172;
x86_l_11b4:
	/* 0x11b4: mov    edx,edx */
	X86_VM_RUN_STEP(X86_OP_MOV_REG, X86_RDX, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_11b6:
	/* 0x11b6: mov    ebp,DWORD PTR [r10+rdx*4] */
	X86_VM_RUN_STEP(X86_OP_MOV_LOAD, X86_RBP, X86_R10, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 2), 0ULL);
x86_l_11ba:
	/* 0x11ba: or     ebp,DWORD PTR [r9+rdx*4] */
	X86_VM_RUN_STEP(X86_OP_NOP, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_32, X86_ALU_OR, 0);
x86_l_11be:
	/* 0x11be: test   ecx,ecx */
	X86_VM_RUN_STEP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_11c0:
	/* 0x11c0: je     1170 <packet_toeplitz_rss_hash_xdp+0x70> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_E))
		goto x86_l_1170;
x86_l_11c2:
	/* 0x11c2: shl    ebp,cl */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_RBP, X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 0);
x86_l_11c4:
	/* 0x11c4: mov    r14d,DWORD PTR [r11+rdx*4] */
	X86_VM_RUN_STEP(X86_OP_MOV_LOAD, X86_R14, X86_R11, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 2), 0ULL);
x86_l_11c8:
	/* 0x11c8: mov    dl,0x8 */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, 0, 8ULL);
x86_l_11ca:
	/* 0x11ca: sub    dl,cl */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_RDX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB, 0);
x86_l_11cc:
	/* 0x11cc: mov    ecx,edx */
	X86_VM_RUN_STEP(X86_OP_MOV_REG, X86_RCX, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_11ce:
	/* 0x11ce: shr    r14d,cl */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 0);
x86_l_11d1:
	/* 0x11d1: or     ebp,r14d */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_RBP, X86_R14, X86_WIDTH_32, X86_ALU_OR, 0);
x86_l_11d4:
	/* 0x11d4: jmp    1170 <packet_toeplitz_rss_hash_xdp+0x70> */
	goto x86_l_1170;
x86_l_11d6:
	/* 0x11d6: mov    edx,DWORD PTR [rsi+0x26] */
	X86_VM_RUN_STEP(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_11d9:
	/* 0x11d9: movzx  ecx,BYTE PTR [rsi+0x2a] */
	X86_VM_RUN_STEP(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_11dd:
	/* 0x11dd: movzx  r8d,BYTE PTR [rsi+0x2b] */
	X86_VM_RUN_STEP(X86_OP_MOV_LOAD, X86_R8, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_11e2:
	/* 0x11e2: movzx  r9d,BYTE PTR [rsi+0x2c] */
	X86_VM_RUN_STEP(X86_OP_MOV_LOAD, X86_R9, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 44ULL);
x86_l_11e7:
	/* 0x11e7: movzx  r10d,BYTE PTR [rsi+0x2d] */
	X86_VM_RUN_STEP(X86_OP_MOV_LOAD, X86_R10, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 45ULL);
x86_l_11ec:
	/* 0x11ec: mov    r11,rax */
	X86_VM_RUN_STEP(X86_OP_MOV_REG, X86_R11, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_11ef:
	/* 0x11ef: shl    r11,0x20 */
	X86_VM_RUN_STEP(X86_OP_ALU_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_11f3:
	/* 0x11f3: xor    edx,DWORD PTR [rsi+0x22] */
	X86_VM_RUN_STEP(X86_OP_NOP, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_11f6:
	/* 0x11f6: bswap  edx */
	X86_VM_RUN_STEP(X86_OP_BSWAP, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 0);
x86_l_11f8:
	/* 0x11f8: mov    edi,edx */
	X86_VM_RUN_STEP(X86_OP_MOV_REG, X86_RDI, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_11fa:
	/* 0x11fa: xor    edi,eax */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_11fc:
	/* 0x11fc: or     rdi,r11 */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_RDI, X86_R11, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_11ff:
	/* 0x11ff: shl    rcx,0x38 */
	X86_VM_RUN_STEP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 56ULL);
x86_l_1203:
	/* 0x1203: shl    r8,0x30 */
	X86_VM_RUN_STEP(X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 48ULL);
x86_l_1207:
	/* 0x1207: or     r8,rcx */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_R8, X86_RCX, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_120a:
	/* 0x120a: shl    r9,0x28 */
	X86_VM_RUN_STEP(X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 40ULL);
x86_l_120e:
	/* 0x120e: or     r9,r8 */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_R9, X86_R8, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_1211:
	/* 0x1211: shl    r10,0x20 */
	X86_VM_RUN_STEP(X86_OP_ALU_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_1215:
	/* 0x1215: or     rdx,r9 */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_RDX, X86_R9, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_1218:
	/* 0x1218: or     rdx,r10 */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_RDX, X86_R10, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_121b:
	/* 0x121b: and    eax,0x7 */
	X86_VM_RUN_STEP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_121e:
	/* 0x121e: lea    ecx,[rax+0x1] */
	X86_VM_RUN_STEP(X86_OP_LEA, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 1ULL);
x86_l_1221:
	/* 0x1221: mov    r8,rdx */
	X86_VM_RUN_STEP(X86_OP_MOV_REG, X86_R8, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_1224:
	/* 0x1224: shl    r8,cl */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_R8, X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 0);
x86_l_1227:
	/* 0x1227: not    al */
	X86_VM_RUN_STEP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_ALU_NOT, 0);
x86_l_1229:
	/* 0x1229: mov    ecx,eax */
	X86_VM_RUN_STEP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_122b:
	/* 0x122b: shr    rdx,cl */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 0);
x86_l_122e:
	/* 0x122e: or     rdx,r8 */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_RDX, X86_R8, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_1231:
	/* 0x1231: xor    rdx,rdi */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_RDX, X86_RDI, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1234:
	/* 0x1234: mov    QWORD PTR [rsi],rdx */
	X86_VM_RUN_STEP(X86_OP_MOV_STORE_REG, X86_RSI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1237:
	/* 0x1237: mov    eax,0x2 */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_123c:
	/* 0x123c: pop    rbx */
	X86_VM_RUN_STEP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_123d:
	/* 0x123d: pop    r14 */
	X86_VM_RUN_STEP(X86_OP_POP, X86_R14, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_123f:
	/* 0x123f: pop    rbp */
	X86_VM_RUN_STEP(X86_OP_POP, X86_RBP, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1240:
	/* 0x1240: ret */
	X86_VM_RET_RAX();
	return XDP_ABORTED;
}

X86_VM_LICENSE();
