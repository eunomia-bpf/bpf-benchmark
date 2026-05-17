#include "../x86_vm_bpf.h"

SEC("xdp")
int bpftrace_string_search_prefix_scan_x86_vm_xdp(struct xdp_md *ctx)
{
	X86_VM_DECLARE_XDP(ctx);
x86_l_1100:
	/* 0x1100: mov    rcx,QWORD PTR [rdi] */
	X86_VM_RUN_STEP(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1103:
	/* 0x1103: mov    rdx,QWORD PTR [rdi+0x8] */
	X86_VM_RUN_STEP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1107:
	/* 0x1107: xor    eax,eax */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1109:
	/* 0x1109: cmp    rcx,rdx */
	X86_VM_RUN_STEP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_110c:
	/* 0x110c: ja     12c8 <bpftrace_string_search_prefix_scan_xdp+0x1c8> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_12c8;
x86_l_1112:
	/* 0x1112: lea    rsi,[rcx+0x8] */
	X86_VM_RUN_STEP(X86_OP_LEA, X86_RSI, X86_RCX, X86_WIDTH_64, 0, 8ULL);
x86_l_1116:
	/* 0x1116: cmp    rsi,rdx */
	X86_VM_RUN_STEP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_1119:
	/* 0x1119: ja     12c8 <bpftrace_string_search_prefix_scan_xdp+0x1c8> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_12c8;
x86_l_111f:
	/* 0x111f: lea    rsi,[rcx+0x78] */
	X86_VM_RUN_STEP(X86_OP_LEA, X86_RSI, X86_RCX, X86_WIDTH_64, 0, 120ULL);
x86_l_1123:
	/* 0x1123: cmp    rsi,rdx */
	X86_VM_RUN_STEP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_1126:
	/* 0x1126: ja     12c8 <bpftrace_string_search_prefix_scan_xdp+0x1c8> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_12c8;
x86_l_112c:
	/* 0x112c: push   rbx */
	X86_VM_RUN_STEP(X86_OP_PUSH, X86_REG_NONE, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_112d:
	/* 0x112d: mov    edi,DWORD PTR [rcx+0x8] */
	X86_VM_RUN_STEP(X86_OP_MOV_LOAD, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1130:
	/* 0x1130: movzx  edx,BYTE PTR [rcx+0x70] */
	X86_VM_RUN_STEP(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 112ULL);
x86_l_1134:
	/* 0x1134: xor    eax,eax */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1136:
	/* 0x1136: mov    r8d,0x0 */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, 0, 0ULL);
x86_l_113c:
	/* 0x113c: test   dl,dl */
	X86_VM_RUN_STEP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8, 0, 0);
x86_l_113e:
	/* 0x113e: je     11a2 <bpftrace_string_search_prefix_scan_xdp+0xa2> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_E))
		goto x86_l_11a2;
x86_l_1140:
	/* 0x1140: cmp    BYTE PTR [rcx+0x71],0x0 */
	X86_VM_RUN_STEP(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 485331304448ULL);
x86_l_1144:
	/* 0x1144: je     1174 <bpftrace_string_search_prefix_scan_xdp+0x74> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_E))
		goto x86_l_1174;
x86_l_1146:
	/* 0x1146: cmp    BYTE PTR [rcx+0x72],0x0 */
	X86_VM_RUN_STEP(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 489626271744ULL);
x86_l_114a:
	/* 0x114a: je     117c <bpftrace_string_search_prefix_scan_xdp+0x7c> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_E))
		goto x86_l_117c;
x86_l_114c:
	/* 0x114c: cmp    BYTE PTR [rcx+0x73],0x0 */
	X86_VM_RUN_STEP(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 493921239040ULL);
x86_l_1150:
	/* 0x1150: je     1184 <bpftrace_string_search_prefix_scan_xdp+0x84> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_E))
		goto x86_l_1184;
x86_l_1152:
	/* 0x1152: cmp    BYTE PTR [rcx+0x74],0x0 */
	X86_VM_RUN_STEP(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 498216206336ULL);
x86_l_1156:
	/* 0x1156: je     118c <bpftrace_string_search_prefix_scan_xdp+0x8c> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_E))
		goto x86_l_118c;
x86_l_1158:
	/* 0x1158: cmp    BYTE PTR [rcx+0x75],0x0 */
	X86_VM_RUN_STEP(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 502511173632ULL);
x86_l_115c:
	/* 0x115c: je     1194 <bpftrace_string_search_prefix_scan_xdp+0x94> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_E))
		goto x86_l_1194;
x86_l_115e:
	/* 0x115e: cmp    BYTE PTR [rcx+0x76],0x0 */
	X86_VM_RUN_STEP(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 506806140928ULL);
x86_l_1162:
	/* 0x1162: je     119c <bpftrace_string_search_prefix_scan_xdp+0x9c> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_E))
		goto x86_l_119c;
x86_l_1164:
	/* 0x1164: cmp    BYTE PTR [rcx+0x77],0x1 */
	X86_VM_RUN_STEP(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 511101108225ULL);
x86_l_1168:
	/* 0x1168: mov    r8d,0x8 */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_116e:
	/* 0x116e: sbb    r8d,0x0 */
	X86_VM_RUN_STEP(X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SBB, 0ULL);
x86_l_1172:
	/* 0x1172: jmp    11a2 <bpftrace_string_search_prefix_scan_xdp+0xa2> */
	goto x86_l_11a2;
x86_l_1174:
	/* 0x1174: mov    r8d,0x1 */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_117a:
	/* 0x117a: jmp    11a2 <bpftrace_string_search_prefix_scan_xdp+0xa2> */
	goto x86_l_11a2;
x86_l_117c:
	/* 0x117c: mov    r8d,0x2 */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_1182:
	/* 0x1182: jmp    11a2 <bpftrace_string_search_prefix_scan_xdp+0xa2> */
	goto x86_l_11a2;
x86_l_1184:
	/* 0x1184: mov    r8d,0x3 */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, 0, 3ULL);
x86_l_118a:
	/* 0x118a: jmp    11a2 <bpftrace_string_search_prefix_scan_xdp+0xa2> */
	goto x86_l_11a2;
x86_l_118c:
	/* 0x118c: mov    r8d,0x4 */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_1192:
	/* 0x1192: jmp    11a2 <bpftrace_string_search_prefix_scan_xdp+0xa2> */
	goto x86_l_11a2;
x86_l_1194:
	/* 0x1194: mov    r8d,0x5 */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, 0, 5ULL);
x86_l_119a:
	/* 0x119a: jmp    11a2 <bpftrace_string_search_prefix_scan_xdp+0xa2> */
	goto x86_l_11a2;
x86_l_119c:
	/* 0x119c: mov    r8d,0x6 */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, 0, 6ULL);
x86_l_11a2:
	/* 0x11a2: cmp    edi,0x60 */
	X86_VM_RUN_STEP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 96ULL);
x86_l_11a5:
	/* 0x11a5: ja     12c7 <bpftrace_string_search_prefix_scan_xdp+0x1c7> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_12c7;
x86_l_11ab:
	/* 0x11ab: mov    esi,DWORD PTR [rcx+0xc] */
	X86_VM_RUN_STEP(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_11ae:
	/* 0x11ae: cmp    esi,r8d */
	X86_VM_RUN_STEP(X86_OP_CMP_REG, X86_RSI, X86_R8, X86_WIDTH_32, 0, 0);
x86_l_11b1:
	/* 0x11b1: jne    12c7 <bpftrace_string_search_prefix_scan_xdp+0x1c7> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_12c7;
x86_l_11b7:
	/* 0x11b7: test   dl,dl */
	X86_VM_RUN_STEP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8, 0, 0);
x86_l_11b9:
	/* 0x11b9: je     12c7 <bpftrace_string_search_prefix_scan_xdp+0x1c7> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_E))
		goto x86_l_12c7;
x86_l_11bf:
	/* 0x11bf: movabs rax,0x4f82338baed89116 */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, 0, 5729198350995591446ULL);
x86_l_11c9:
	/* 0x11c9: mov    r9d,edi */
	X86_VM_RUN_STEP(X86_OP_MOV_REG, X86_R9, X86_RDI, X86_WIDTH_32, 0, 0);
x86_l_11cc:
	/* 0x11cc: lea    r10d,[rsi+0x3] */
	X86_VM_RUN_STEP(X86_OP_LEA, X86_R10, X86_RSI, X86_WIDTH_32, 0, 3ULL);
x86_l_11d0:
	/* 0x11d0: movabs rdi,0xd1b54a32d192ed03 */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, 15111065706836454659ULL);
x86_l_11da:
	/* 0x11da: add    rdi,r10 */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_RDI, X86_R10, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_11dd:
	/* 0x11dd: xor    r8d,r8d */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_11e0:
	/* 0x11e0: jmp    1209 <bpftrace_string_search_prefix_scan_xdp+0x109> */
	goto x86_l_1209;
x86_l_11e2:
	/* 0x11e2: data16 data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0] */
	X86_VM_RUN_STEP(X86_OP_NOP, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_11f0:
	/* 0x11f0: test   r11b,r11b */
	X86_VM_RUN_STEP(X86_OP_TEST_REG, X86_R11, X86_R11, X86_WIDTH_8, 0, 0);
x86_l_11f3:
	/* 0x11f3: je     12a8 <bpftrace_string_search_prefix_scan_xdp+0x1a8> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_E))
		goto x86_l_12a8;
x86_l_11f9:
	/* 0x11f9: inc    r8 */
	X86_VM_RUN_STEP(X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_11fc:
	/* 0x11fc: add    rdi,r10 */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_RDI, X86_R10, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_11ff:
	/* 0x11ff: cmp    r8,0x59 */
	X86_VM_RUN_STEP(X86_OP_CMP_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_64, 0, 89ULL);
x86_l_1203:
	/* 0x1203: je     12bf <bpftrace_string_search_prefix_scan_xdp+0x1bf> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_E))
		goto x86_l_12bf;
x86_l_1209:
	/* 0x1209: lea    r11,[rsi+r8*1] */
	X86_VM_RUN_STEP(X86_OP_LEA, X86_R11, X86_RSI, X86_WIDTH_64, 0, 0ULL);
x86_l_120d:
	/* 0x120d: cmp    r11,r9 */
	X86_VM_RUN_STEP(X86_OP_CMP_REG, X86_R11, X86_R9, X86_WIDTH_64, 0, 0);
x86_l_1210:
	/* 0x1210: ja     11f9 <bpftrace_string_search_prefix_scan_xdp+0xf9> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_11f9;
x86_l_1212:
	/* 0x1212: test   rsi,rsi */
	X86_VM_RUN_STEP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_1215:
	/* 0x1215: je     12a8 <bpftrace_string_search_prefix_scan_xdp+0x1a8> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_E))
		goto x86_l_12a8;
x86_l_121b:
	/* 0x121b: movzx  r11d,BYTE PTR [rcx+r8*1+0x10] */
	X86_VM_RUN_STEP(X86_OP_MOV_LOAD, X86_R11, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R8, 0, X86_WIDTH_8), 16ULL);
x86_l_1221:
	/* 0x1221: xor    r11b,dl */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_R11, X86_RDX, X86_WIDTH_8, X86_ALU_XOR, 0);
x86_l_1224:
	/* 0x1224: cmp    esi,0x2 */
	X86_VM_RUN_STEP(X86_OP_CMP_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_1227:
	/* 0x1227: jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_B))
		goto x86_l_11f0;
x86_l_1229:
	/* 0x1229: movzx  ebx,BYTE PTR [rcx+0x71] */
	X86_VM_RUN_STEP(X86_OP_MOV_LOAD, X86_RBX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 113ULL);
x86_l_122d:
	/* 0x122d: xor    bl,BYTE PTR [rcx+r8*1+0x11] */
	X86_VM_RUN_STEP(X86_OP_NOP, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_8, X86_ALU_XOR, 0);
x86_l_1232:
	/* 0x1232: or     r11b,bl */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_R11, X86_RBX, X86_WIDTH_8, X86_ALU_OR, 0);
x86_l_1235:
	/* 0x1235: cmp    esi,0x3 */
	X86_VM_RUN_STEP(X86_OP_CMP_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 3ULL);
x86_l_1238:
	/* 0x1238: jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_B))
		goto x86_l_11f0;
x86_l_123a:
	/* 0x123a: movzx  ebx,BYTE PTR [rcx+0x72] */
	X86_VM_RUN_STEP(X86_OP_MOV_LOAD, X86_RBX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 114ULL);
x86_l_123e:
	/* 0x123e: xor    bl,BYTE PTR [rcx+r8*1+0x12] */
	X86_VM_RUN_STEP(X86_OP_NOP, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_8, X86_ALU_XOR, 0);
x86_l_1243:
	/* 0x1243: or     r11b,bl */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_R11, X86_RBX, X86_WIDTH_8, X86_ALU_OR, 0);
x86_l_1246:
	/* 0x1246: cmp    esi,0x4 */
	X86_VM_RUN_STEP(X86_OP_CMP_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_1249:
	/* 0x1249: jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_B))
		goto x86_l_11f0;
x86_l_124b:
	/* 0x124b: movzx  ebx,BYTE PTR [rcx+0x73] */
	X86_VM_RUN_STEP(X86_OP_MOV_LOAD, X86_RBX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 115ULL);
x86_l_124f:
	/* 0x124f: xor    bl,BYTE PTR [rcx+r8*1+0x13] */
	X86_VM_RUN_STEP(X86_OP_NOP, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_8, X86_ALU_XOR, 0);
x86_l_1254:
	/* 0x1254: or     r11b,bl */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_R11, X86_RBX, X86_WIDTH_8, X86_ALU_OR, 0);
x86_l_1257:
	/* 0x1257: cmp    esi,0x5 */
	X86_VM_RUN_STEP(X86_OP_CMP_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 5ULL);
x86_l_125a:
	/* 0x125a: jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_B))
		goto x86_l_11f0;
x86_l_125c:
	/* 0x125c: movzx  ebx,BYTE PTR [rcx+0x74] */
	X86_VM_RUN_STEP(X86_OP_MOV_LOAD, X86_RBX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 116ULL);
x86_l_1260:
	/* 0x1260: xor    bl,BYTE PTR [rcx+r8*1+0x14] */
	X86_VM_RUN_STEP(X86_OP_NOP, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_8, X86_ALU_XOR, 0);
x86_l_1265:
	/* 0x1265: or     r11b,bl */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_R11, X86_RBX, X86_WIDTH_8, X86_ALU_OR, 0);
x86_l_1268:
	/* 0x1268: cmp    esi,0x6 */
	X86_VM_RUN_STEP(X86_OP_CMP_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 6ULL);
x86_l_126b:
	/* 0x126b: jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_B))
		goto x86_l_11f0;
x86_l_126d:
	/* 0x126d: movzx  ebx,BYTE PTR [rcx+0x75] */
	X86_VM_RUN_STEP(X86_OP_MOV_LOAD, X86_RBX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 117ULL);
x86_l_1271:
	/* 0x1271: xor    bl,BYTE PTR [rcx+r8*1+0x15] */
	X86_VM_RUN_STEP(X86_OP_NOP, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_8, X86_ALU_XOR, 0);
x86_l_1276:
	/* 0x1276: or     r11b,bl */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_R11, X86_RBX, X86_WIDTH_8, X86_ALU_OR, 0);
x86_l_1279:
	/* 0x1279: cmp    esi,0x7 */
	X86_VM_RUN_STEP(X86_OP_CMP_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 7ULL);
x86_l_127c:
	/* 0x127c: jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_B))
		goto x86_l_11f0;
x86_l_1282:
	/* 0x1282: movzx  ebx,BYTE PTR [rcx+0x76] */
	X86_VM_RUN_STEP(X86_OP_MOV_LOAD, X86_RBX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 118ULL);
x86_l_1286:
	/* 0x1286: xor    bl,BYTE PTR [rcx+r8*1+0x16] */
	X86_VM_RUN_STEP(X86_OP_NOP, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_8, X86_ALU_XOR, 0);
x86_l_128b:
	/* 0x128b: or     r11b,bl */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_R11, X86_RBX, X86_WIDTH_8, X86_ALU_OR, 0);
x86_l_128e:
	/* 0x128e: cmp    esi,0x8 */
	X86_VM_RUN_STEP(X86_OP_CMP_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_1291:
	/* 0x1291: jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_B))
		goto x86_l_11f0;
x86_l_1297:
	/* 0x1297: movzx  ebx,BYTE PTR [rcx+0x77] */
	X86_VM_RUN_STEP(X86_OP_MOV_LOAD, X86_RBX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 119ULL);
x86_l_129b:
	/* 0x129b: xor    bl,BYTE PTR [rcx+r8*1+0x17] */
	X86_VM_RUN_STEP(X86_OP_NOP, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_8, X86_ALU_XOR, 0);
x86_l_12a0:
	/* 0x12a0: or     r11b,bl */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_R11, X86_RBX, X86_WIDTH_8, X86_ALU_OR, 0);
x86_l_12a3:
	/* 0x12a3: jmp    11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0> */
	goto x86_l_11f0;
x86_l_12a8:
	/* 0x12a8: cmp    r8,0x60 */
	X86_VM_RUN_STEP(X86_OP_CMP_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_64, 0, 96ULL);
x86_l_12ac:
	/* 0x12ac: je     12bf <bpftrace_string_search_prefix_scan_xdp+0x1bf> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_E))
		goto x86_l_12bf;
x86_l_12ae:
	/* 0x12ae: shl    rsi,0x20 */
	X86_VM_RUN_STEP(X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_12b2:
	/* 0x12b2: add    rsi,r8 */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_RSI, X86_R8, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_12b5:
	/* 0x12b5: rol    rsi,0x3 */
	X86_VM_RUN_STEP(X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 3ULL);
x86_l_12b9:
	/* 0x12b9: xor    rdi,rsi */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_12bc:
	/* 0x12bc: mov    rax,rdi */
	X86_VM_RUN_STEP(X86_OP_MOV_REG, X86_RAX, X86_RDI, X86_WIDTH_64, 0, 0);
x86_l_12bf:
	/* 0x12bf: mov    QWORD PTR [rcx],rax */
	X86_VM_RUN_STEP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12c2:
	/* 0x12c2: mov    eax,0x2 */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_12c7:
	/* 0x12c7: pop    rbx */
	X86_VM_RUN_STEP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_12c8:
	/* 0x12c8: ret */
	X86_VM_RET_RAX();
	return XDP_ABORTED;
}

X86_VM_LICENSE();
