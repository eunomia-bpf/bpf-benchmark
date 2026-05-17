
#include "../x86_vm_bpf.h"

SEC("xdp")
int packet_vlan_tcpopt_parser_x86_vm_xdp(struct xdp_md *ctx)
{
	X86_VM_DECLARE_XDP(ctx);
x86_l_1100:
	/* 0x1100: mov    rdx,QWORD PTR [rdi] */
	X86_VM_RUN_STEP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1103:
	/* 0x1103: mov    r10,QWORD PTR [rdi+0x8] */
	X86_VM_RUN_STEP(X86_OP_MOV_LOAD, X86_R10, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1107:
	/* 0x1107: xor    eax,eax */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1109:
	/* 0x1109: cmp    rdx,r10 */
	X86_VM_RUN_STEP(X86_OP_CMP_REG, X86_RDX, X86_R10, X86_WIDTH_64, 0, 0);
x86_l_110c:
	/* 0x110c: ja     1244 <packet_vlan_tcpopt_parser_xdp+0x144> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_1244;
x86_l_1112:
	/* 0x1112: lea    rcx,[rdx+0x8] */
	X86_VM_RUN_STEP(X86_OP_LEA, X86_RCX, X86_RDX, X86_WIDTH_64, 0, 8ULL);
x86_l_1116:
	/* 0x1116: cmp    rcx,r10 */
	X86_VM_RUN_STEP(X86_OP_CMP_REG, X86_RCX, X86_R10, X86_WIDTH_64, 0, 0);
x86_l_1119:
	/* 0x1119: ja     1244 <packet_vlan_tcpopt_parser_xdp+0x144> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_1244;
x86_l_111f:
	/* 0x111f: lea    r9,[rdx+0x16] */
	X86_VM_RUN_STEP(X86_OP_LEA, X86_R9, X86_RDX, X86_WIDTH_64, 0, 22ULL);
x86_l_1123:
	/* 0x1123: cmp    r9,r10 */
	X86_VM_RUN_STEP(X86_OP_CMP_REG, X86_R9, X86_R10, X86_WIDTH_64, 0, 0);
x86_l_1126:
	/* 0x1126: ja     1244 <packet_vlan_tcpopt_parser_xdp+0x144> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_1244;
x86_l_112c:
	/* 0x112c: push   rbp */
	X86_VM_RUN_STEP(X86_OP_PUSH, X86_REG_NONE, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_112d:
	/* 0x112d: push   r15 */
	X86_VM_RUN_STEP(X86_OP_PUSH, X86_REG_NONE, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_112f:
	/* 0x112f: push   r14 */
	X86_VM_RUN_STEP(X86_OP_PUSH, X86_REG_NONE, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_1131:
	/* 0x1131: push   rbx */
	X86_VM_RUN_STEP(X86_OP_PUSH, X86_REG_NONE, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_1132:
	/* 0x1132: movzx  eax,WORD PTR [rdx+0x14] */
	X86_VM_RUN_STEP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 20ULL);
x86_l_1136:
	/* 0x1136: rol    ax,0x8 */
	X86_VM_RUN_STEP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_ALU_ROL, 8ULL);
x86_l_113a:
	/* 0x113a: movzx  ecx,ax */
	X86_VM_RUN_STEP(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_113d:
	/* 0x113d: xor    eax,eax */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_113f:
	/* 0x113f: cmp    ecx,0x800 */
	X86_VM_RUN_STEP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 2048ULL);
x86_l_1145:
	/* 0x1145: je     11df <packet_vlan_tcpopt_parser_xdp+0xdf> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_E))
		goto x86_l_11df;
x86_l_114b:
	/* 0x114b: cmp    ecx,0x88a8 */
	X86_VM_RUN_STEP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 34984ULL);
x86_l_1151:
	/* 0x1151: je     115f <packet_vlan_tcpopt_parser_xdp+0x5f> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_E))
		goto x86_l_115f;
x86_l_1153:
	/* 0x1153: cmp    ecx,0x8100 */
	X86_VM_RUN_STEP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 33024ULL);
x86_l_1159:
	/* 0x1159: jne    123e <packet_vlan_tcpopt_parser_xdp+0x13e> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_123e;
x86_l_115f:
	/* 0x115f: lea    r9,[rdx+0x1a] */
	X86_VM_RUN_STEP(X86_OP_LEA, X86_R9, X86_RDX, X86_WIDTH_64, 0, 26ULL);
x86_l_1163:
	/* 0x1163: cmp    r9,r10 */
	X86_VM_RUN_STEP(X86_OP_CMP_REG, X86_R9, X86_R10, X86_WIDTH_64, 0, 0);
x86_l_1166:
	/* 0x1166: ja     123e <packet_vlan_tcpopt_parser_xdp+0x13e> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_123e;
x86_l_116c:
	/* 0x116c: movzx  esi,WORD PTR [rdx+0x16] */
	X86_VM_RUN_STEP(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 22ULL);
x86_l_1170:
	/* 0x1170: movzx  ecx,WORD PTR [rdx+0x18] */
	X86_VM_RUN_STEP(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 24ULL);
x86_l_1174:
	/* 0x1174: rol    si,0x8 */
	X86_VM_RUN_STEP(X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_16, X86_ALU_ROL, 8ULL);
x86_l_1178:
	/* 0x1178: rol    cx,0x8 */
	X86_VM_RUN_STEP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_ALU_ROL, 8ULL);
x86_l_117c:
	/* 0x117c: movzx  ecx,cx */
	X86_VM_RUN_STEP(X86_OP_MOVZX_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_117f:
	/* 0x117f: cmp    ecx,0x800 */
	X86_VM_RUN_STEP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 2048ULL);
x86_l_1185:
	/* 0x1185: je     1245 <packet_vlan_tcpopt_parser_xdp+0x145> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_E))
		goto x86_l_1245;
x86_l_118b:
	/* 0x118b: cmp    ecx,0x88a8 */
	X86_VM_RUN_STEP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 34984ULL);
x86_l_1191:
	/* 0x1191: je     119f <packet_vlan_tcpopt_parser_xdp+0x9f> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_E))
		goto x86_l_119f;
x86_l_1193:
	/* 0x1193: cmp    ecx,0x8100 */
	X86_VM_RUN_STEP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 33024ULL);
x86_l_1199:
	/* 0x1199: jne    123e <packet_vlan_tcpopt_parser_xdp+0x13e> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_123e;
x86_l_119f:
	/* 0x119f: lea    rcx,[rdx+0x1e] */
	X86_VM_RUN_STEP(X86_OP_LEA, X86_RCX, X86_RDX, X86_WIDTH_64, 0, 30ULL);
x86_l_11a3:
	/* 0x11a3: cmp    rcx,r10 */
	X86_VM_RUN_STEP(X86_OP_CMP_REG, X86_RCX, X86_R10, X86_WIDTH_64, 0, 0);
x86_l_11a6:
	/* 0x11a6: ja     123e <packet_vlan_tcpopt_parser_xdp+0x13e> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_123e;
x86_l_11ac:
	/* 0x11ac: movzx  ecx,WORD PTR [rdx+0x1c] */
	X86_VM_RUN_STEP(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 28ULL);
x86_l_11b0:
	/* 0x11b0: rol    cx,0x8 */
	X86_VM_RUN_STEP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_ALU_ROL, 8ULL);
x86_l_11b4:
	/* 0x11b4: movzx  ecx,cx */
	X86_VM_RUN_STEP(X86_OP_MOVZX_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_11b7:
	/* 0x11b7: cmp    ecx,0x800 */
	X86_VM_RUN_STEP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 2048ULL);
x86_l_11bd:
	/* 0x11bd: jne    123e <packet_vlan_tcpopt_parser_xdp+0x13e> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_123e;
x86_l_11bf:
	/* 0x11bf: lea    rcx,[rdx+0x32] */
	X86_VM_RUN_STEP(X86_OP_LEA, X86_RCX, X86_RDX, X86_WIDTH_64, 0, 50ULL);
x86_l_11c3:
	/* 0x11c3: cmp    rcx,r10 */
	X86_VM_RUN_STEP(X86_OP_CMP_REG, X86_RCX, X86_R10, X86_WIDTH_64, 0, 0);
x86_l_11c6:
	/* 0x11c6: ja     123e <packet_vlan_tcpopt_parser_xdp+0x13e> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_123e;
x86_l_11c8:
	/* 0x11c8: lea    r9,[rdx+0x1e] */
	X86_VM_RUN_STEP(X86_OP_LEA, X86_R9, X86_RDX, X86_WIDTH_64, 0, 30ULL);
x86_l_11cc:
	/* 0x11cc: movzx  ecx,WORD PTR [rdx+0x1a] */
	X86_VM_RUN_STEP(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 26ULL);
x86_l_11d0:
	/* 0x11d0: rol    cx,0x8 */
	X86_VM_RUN_STEP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_ALU_ROL, 8ULL);
x86_l_11d4:
	/* 0x11d4: movzx  r8d,cx */
	X86_VM_RUN_STEP(X86_OP_MOVZX_REG, X86_R8, X86_RCX, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_11d8:
	/* 0x11d8: mov    ecx,0x2 */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_11dd:
	/* 0x11dd: jmp    11ef <packet_vlan_tcpopt_parser_xdp+0xef> */
	goto x86_l_11ef;
x86_l_11df:
	/* 0x11df: xor    esi,esi */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_11e1:
	/* 0x11e1: xor    ecx,ecx */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_11e3:
	/* 0x11e3: lea    rdi,[r9+0x14] */
	X86_VM_RUN_STEP(X86_OP_LEA, X86_RDI, X86_R9, X86_WIDTH_64, 0, 20ULL);
x86_l_11e7:
	/* 0x11e7: cmp    rdi,r10 */
	X86_VM_RUN_STEP(X86_OP_CMP_REG, X86_RDI, X86_R10, X86_WIDTH_64, 0, 0);
x86_l_11ea:
	/* 0x11ea: ja     123e <packet_vlan_tcpopt_parser_xdp+0x13e> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_123e;
x86_l_11ec:
	/* 0x11ec: xor    r8d,r8d */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_11ef:
	/* 0x11ef: movzx  edi,BYTE PTR [r9] */
	X86_VM_RUN_STEP(X86_OP_MOV_LOAD, X86_RDI, X86_R9, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_11f3:
	/* 0x11f3: mov    r11d,edi */
	X86_VM_RUN_STEP(X86_OP_MOV_REG, X86_R11, X86_RDI, X86_WIDTH_32, 0, 0);
x86_l_11f6:
	/* 0x11f6: and    r11b,0xf0 */
	X86_VM_RUN_STEP(X86_OP_ALU_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_8, X86_ALU_AND, 240ULL);
x86_l_11fa:
	/* 0x11fa: cmp    r11b,0x40 */
	X86_VM_RUN_STEP(X86_OP_CMP_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_8, 0, 64ULL);
x86_l_11fe:
	/* 0x11fe: jne    123e <packet_vlan_tcpopt_parser_xdp+0x13e> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_123e;
x86_l_1200:
	/* 0x1200: and    edi,0xf */
	X86_VM_RUN_STEP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_1203:
	/* 0x1203: cmp    dil,0x5 */
	X86_VM_RUN_STEP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_8, 0, 5ULL);
x86_l_1207:
	/* 0x1207: jb     123e <packet_vlan_tcpopt_parser_xdp+0x13e> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_B))
		goto x86_l_123e;
x86_l_1209:
	/* 0x1209: lea    rbx,[r9+rdi*4] */
	X86_VM_RUN_STEP(X86_OP_LEA, X86_RBX, X86_R9, X86_WIDTH_64, 0, 0ULL);
x86_l_120d:
	/* 0x120d: cmp    rbx,r10 */
	X86_VM_RUN_STEP(X86_OP_CMP_REG, X86_RBX, X86_R10, X86_WIDTH_64, 0, 0);
x86_l_1210:
	/* 0x1210: ja     123e <packet_vlan_tcpopt_parser_xdp+0x13e> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_123e;
x86_l_1212:
	/* 0x1212: cmp    BYTE PTR [r9+0x9],0x6 */
	X86_VM_RUN_STEP(X86_OP_CMP_MEM_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38654705670ULL);
x86_l_1217:
	/* 0x1217: jne    123e <packet_vlan_tcpopt_parser_xdp+0x13e> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_123e;
x86_l_1219:
	/* 0x1219: lea    r14,[rbx+0x14] */
	X86_VM_RUN_STEP(X86_OP_LEA, X86_R14, X86_RBX, X86_WIDTH_64, 0, 20ULL);
x86_l_121d:
	/* 0x121d: cmp    r14,r10 */
	X86_VM_RUN_STEP(X86_OP_CMP_REG, X86_R14, X86_R10, X86_WIDTH_64, 0, 0);
x86_l_1220:
	/* 0x1220: ja     123e <packet_vlan_tcpopt_parser_xdp+0x13e> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_123e;
x86_l_1222:
	/* 0x1222: movzx  r11d,BYTE PTR [rbx+0xc] */
	X86_VM_RUN_STEP(X86_OP_MOV_LOAD, X86_R11, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 12ULL);
x86_l_1227:
	/* 0x1227: cmp    r11,0x50 */
	X86_VM_RUN_STEP(X86_OP_CMP_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_64, 0, 80ULL);
x86_l_122b:
	/* 0x122b: jb     123e <packet_vlan_tcpopt_parser_xdp+0x13e> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_B))
		goto x86_l_123e;
x86_l_122d:
	/* 0x122d: shr    r11d,0x2 */
	X86_VM_RUN_STEP(X86_OP_ALU_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHR, 2ULL);
x86_l_1231:
	/* 0x1231: and    r11d,0xfffffffc */
	X86_VM_RUN_STEP(X86_OP_ALU_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 4294967292ULL);
x86_l_1235:
	/* 0x1235: lea    r15,[rbx+r11*1] */
	X86_VM_RUN_STEP(X86_OP_LEA, X86_R15, X86_RBX, X86_WIDTH_64, 0, 0ULL);
x86_l_1239:
	/* 0x1239: cmp    r15,r10 */
	X86_VM_RUN_STEP(X86_OP_CMP_REG, X86_R15, X86_R10, X86_WIDTH_64, 0, 0);
x86_l_123c:
	/* 0x123c: jbe    124c <packet_vlan_tcpopt_parser_xdp+0x14c> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_BE))
		goto x86_l_124c;
x86_l_123e:
	/* 0x123e: pop    rbx */
	X86_VM_RUN_STEP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_123f:
	/* 0x123f: pop    r14 */
	X86_VM_RUN_STEP(X86_OP_POP, X86_R14, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1241:
	/* 0x1241: pop    r15 */
	X86_VM_RUN_STEP(X86_OP_POP, X86_R15, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1243:
	/* 0x1243: pop    rbp */
	X86_VM_RUN_STEP(X86_OP_POP, X86_RBP, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1244:
	/* 0x1244: ret */
	X86_VM_RET_RAX();
x86_l_1245:
	/* 0x1245: mov    ecx,0x1 */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_124a:
	/* 0x124a: jmp    11e3 <packet_vlan_tcpopt_parser_xdp+0xe3> */
	goto x86_l_11e3;
x86_l_124c:
	/* 0x124c: lea    r15,[rbx+0x20] */
	X86_VM_RUN_STEP(X86_OP_LEA, X86_R15, X86_RBX, X86_WIDTH_64, 0, 32ULL);
x86_l_1250:
	/* 0x1250: cmp    r15,r10 */
	X86_VM_RUN_STEP(X86_OP_CMP_REG, X86_R15, X86_R10, X86_WIDTH_64, 0, 0);
x86_l_1253:
	/* 0x1253: ja     123e <packet_vlan_tcpopt_parser_xdp+0x13e> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_123e;
x86_l_1255:
	/* 0x1255: cmp    r11b,0x20 */
	X86_VM_RUN_STEP(X86_OP_CMP_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_8, 0, 32ULL);
x86_l_1259:
	/* 0x1259: jb     123e <packet_vlan_tcpopt_parser_xdp+0x13e> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_B))
		goto x86_l_123e;
x86_l_125b:
	/* 0x125b: cmp    BYTE PTR [r14],0x2 */
	X86_VM_RUN_STEP(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_125f:
	/* 0x125f: jne    123e <packet_vlan_tcpopt_parser_xdp+0x13e> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_123e;
x86_l_1261:
	/* 0x1261: cmp    BYTE PTR [rbx+0x15],0x4 */
	X86_VM_RUN_STEP(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 90194313220ULL);
x86_l_1265:
	/* 0x1265: jb     123e <packet_vlan_tcpopt_parser_xdp+0x13e> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_B))
		goto x86_l_123e;
x86_l_1267:
	/* 0x1267: cmp    BYTE PTR [rbx+0x18],0x1 */
	X86_VM_RUN_STEP(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 103079215105ULL);
x86_l_126b:
	/* 0x126b: jne    123e <packet_vlan_tcpopt_parser_xdp+0x13e> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_123e;
x86_l_126d:
	/* 0x126d: cmp    BYTE PTR [rbx+0x19],0x3 */
	X86_VM_RUN_STEP(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 107374182403ULL);
x86_l_1271:
	/* 0x1271: jne    123e <packet_vlan_tcpopt_parser_xdp+0x13e> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_123e;
x86_l_1273:
	/* 0x1273: cmp    BYTE PTR [rbx+0x1a],0x3 */
	X86_VM_RUN_STEP(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 111669149699ULL);
x86_l_1277:
	/* 0x1277: jb     123e <packet_vlan_tcpopt_parser_xdp+0x13e> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_B))
		goto x86_l_123e;
x86_l_1279:
	/* 0x1279: cmp    BYTE PTR [rbx+0x1c],0x4 */
	X86_VM_RUN_STEP(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 120259084292ULL);
x86_l_127d:
	/* 0x127d: jne    123e <packet_vlan_tcpopt_parser_xdp+0x13e> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_123e;
x86_l_127f:
	/* 0x127f: cmp    BYTE PTR [rbx+0x1d],0x2 */
	X86_VM_RUN_STEP(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 124554051586ULL);
x86_l_1283:
	/* 0x1283: jb     123e <packet_vlan_tcpopt_parser_xdp+0x13e> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_B))
		goto x86_l_123e;
x86_l_1285:
	/* 0x1285: cmp    BYTE PTR [rbx+0x1e],0x1 */
	X86_VM_RUN_STEP(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 128849018881ULL);
x86_l_1289:
	/* 0x1289: jne    123e <packet_vlan_tcpopt_parser_xdp+0x13e> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_123e;
x86_l_128b:
	/* 0x128b: shl    rdi,0x2 */
	X86_VM_RUN_STEP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 2ULL);
x86_l_128f:
	/* 0x128f: movzx  eax,WORD PTR [r9+0x2] */
	X86_VM_RUN_STEP(X86_OP_MOV_LOAD, X86_RAX, X86_R9, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_1294:
	/* 0x1294: rol    ax,0x8 */
	X86_VM_RUN_STEP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_ALU_ROL, 8ULL);
x86_l_1298:
	/* 0x1298: movzx  eax,ax */
	X86_VM_RUN_STEP(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_129b:
	/* 0x129b: mov    r10d,DWORD PTR [r9+0xc] */
	X86_VM_RUN_STEP(X86_OP_MOV_LOAD, X86_R10, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_129f:
	/* 0x129f: bswap  r10d */
	X86_VM_RUN_STEP(X86_OP_BSWAP, X86_R10, X86_REG_NONE, X86_WIDTH_32, 0, 0);
x86_l_12a2:
	/* 0x12a2: mov    r9d,DWORD PTR [r9+0x10] */
	X86_VM_RUN_STEP(X86_OP_MOV_LOAD, X86_R9, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_12a6:
	/* 0x12a6: bswap  r9d */
	X86_VM_RUN_STEP(X86_OP_BSWAP, X86_R9, X86_REG_NONE, X86_WIDTH_32, 0, 0);
x86_l_12a9:
	/* 0x12a9: movzx  ebp,WORD PTR [rbx] */
	X86_VM_RUN_STEP(X86_OP_MOV_LOAD, X86_RBP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_12ac:
	/* 0x12ac: movzx  r14d,WORD PTR [rbx+0x2] */
	X86_VM_RUN_STEP(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_12b1:
	/* 0x12b1: rol    bp,0x8 */
	X86_VM_RUN_STEP(X86_OP_ALU_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_ALU_ROL, 8ULL);
x86_l_12b5:
	/* 0x12b5: movzx  r15d,bp */
	X86_VM_RUN_STEP(X86_OP_MOVZX_REG, X86_R15, X86_RBP, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_12b9:
	/* 0x12b9: add    r15,rax */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_12bc:
	/* 0x12bc: rol    r14w,0x8 */
	X86_VM_RUN_STEP(X86_OP_ALU_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_ALU_ROL, 8ULL);
x86_l_12c1:
	/* 0x12c1: movzx  eax,r14w */
	X86_VM_RUN_STEP(X86_OP_MOVZX_REG, X86_RAX, X86_R14, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_12c5:
	/* 0x12c5: add    rax,r15 */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_RAX, X86_R15, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_12c8:
	/* 0x12c8: xor    rax,r10 */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_RAX, X86_R10, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_12cb:
	/* 0x12cb: add    rax,r9 */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_RAX, X86_R9, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_12ce:
	/* 0x12ce: movzx  r9d,BYTE PTR [rbx+0x16] */
	X86_VM_RUN_STEP(X86_OP_MOV_LOAD, X86_R9, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 22ULL);
x86_l_12d3:
	/* 0x12d3: mov    r10d,r9d */
	X86_VM_RUN_STEP(X86_OP_MOV_REG, X86_R10, X86_R9, X86_WIDTH_32, 0, 0);
x86_l_12d6:
	/* 0x12d6: shl    r10d,0x8 */
	X86_VM_RUN_STEP(X86_OP_ALU_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 8ULL);
x86_l_12da:
	/* 0x12da: movzx  r14d,BYTE PTR [rbx+0x17] */
	X86_VM_RUN_STEP(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 23ULL);
x86_l_12df:
	/* 0x12df: or     r10d,r14d */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_R10, X86_R14, X86_WIDTH_32, X86_ALU_OR, 0);
x86_l_12e2:
	/* 0x12e2: add    r10,0x2 */
	X86_VM_RUN_STEP(X86_OP_ALU_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_12e6:
	/* 0x12e6: shl    r9d,0x10 */
	X86_VM_RUN_STEP(X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 16ULL);
x86_l_12ea:
	/* 0x12ea: xor    r9,r10 */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_R9, X86_R10, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_12ed:
	/* 0x12ed: shl    r14d,0x18 */
	X86_VM_RUN_STEP(X86_OP_ALU_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 24ULL);
x86_l_12f1:
	/* 0x12f1: add    r9,r14 */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_R9, X86_R14, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_12f4:
	/* 0x12f4: add    r9,0x30100 */
	X86_VM_RUN_STEP(X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 196864ULL);
x86_l_12fb:
	/* 0x12fb: movzx  r10d,BYTE PTR [rbx+0x1b] */
	X86_VM_RUN_STEP(X86_OP_MOV_LOAD, X86_R10, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_1300:
	/* 0x1300: mov    r14,r10 */
	X86_VM_RUN_STEP(X86_OP_MOV_REG, X86_R14, X86_R10, X86_WIDTH_64, 0, 0);
x86_l_1303:
	/* 0x1303: shl    r14,0x20 */
	X86_VM_RUN_STEP(X86_OP_ALU_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_1307:
	/* 0x1307: shl    r10d,0x10 */
	X86_VM_RUN_STEP(X86_OP_ALU_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 16ULL);
x86_l_130b:
	/* 0x130b: xor    r10,r14 */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_R10, X86_R14, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_130e:
	/* 0x130e: xor    r10,r9 */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_R10, X86_R9, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1311:
	/* 0x1311: movzx  ebx,BYTE PTR [rbx+0x1f] */
	X86_VM_RUN_STEP(X86_OP_MOV_LOAD, X86_RBX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_1315:
	/* 0x1315: shl    rbx,0x28 */
	X86_VM_RUN_STEP(X86_OP_ALU_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 40ULL);
x86_l_1319:
	/* 0x1319: or     rbx,r10 */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_RBX, X86_R10, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_131c:
	/* 0x131c: movabs r9,0x144000000 */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_64, 0, 5435817984ULL);
x86_l_1326:
	/* 0x1326: add    r9,rbx */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_R9, X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1329:
	/* 0x1329: shl    esi,0x10 */
	X86_VM_RUN_STEP(X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 16ULL);
x86_l_132c:
	/* 0x132c: or     rsi,r8 */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_RSI, X86_R8, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_132f:
	/* 0x132f: xor    rsi,rax */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_RSI, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1332:
	/* 0x1332: mov    rax,rcx */
	X86_VM_RUN_STEP(X86_OP_MOV_REG, X86_RAX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_1335:
	/* 0x1335: shl    rax,0x28 */
	X86_VM_RUN_STEP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 40ULL);
x86_l_1339:
	/* 0x1339: shl    edi,0x8 */
	X86_VM_RUN_STEP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 8ULL);
x86_l_133c:
	/* 0x133c: or     rdi,rax */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_RDI, X86_RAX, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_133f:
	/* 0x133f: or     rdi,r11 */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_RDI, X86_R11, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_1342:
	/* 0x1342: movabs rax,0x600000000 */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, 0, 25769803776ULL);
x86_l_134c:
	/* 0x134c: add    rax,rdi */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_RAX, X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_134f:
	/* 0x134f: add    ecx,0x5 */
	X86_VM_RUN_STEP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_1352:
	/* 0x1352: rol    r9,cl */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_R9, X86_RCX, X86_WIDTH_64, X86_ALU_ROL, 0);
x86_l_1355:
	/* 0x1355: add    rax,rsi */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1358:
	/* 0x1358: xor    r9,rax */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_R9, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_135b:
	/* 0x135b: mov    QWORD PTR [rdx],r9 */
	X86_VM_RUN_STEP(X86_OP_MOV_STORE_REG, X86_RDX, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_135e:
	/* 0x135e: mov    eax,0x2 */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_1363:
	/* 0x1363: jmp    123e <packet_vlan_tcpopt_parser_xdp+0x13e> */
	goto x86_l_123e;
	return XDP_ABORTED;
}

X86_VM_LICENSE();
