#define X86_VM_ENABLE_STACK 1
#include "../x86_vm_bpf.h"

SEC("xdp")
int cilium_policy_guard_tree_filter_x86_vm_xdp(struct xdp_md *ctx)
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
	/* 0x110c: jbe    110f <cilium_policy_guard_tree_filter_xdp+0xf> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_BE))
		goto x86_l_110f;
x86_l_110e:
	/* 0x110e: ret */
	X86_VM_RET_RAX();
x86_l_110f:
	/* 0x110f: lea    rsi,[rdx+0x8] */
	X86_VM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1113:
	/* 0x1113: cmp    rsi,rcx */
	X86_VM_RUN_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_1116:
	/* 0x1116: ja     110e <cilium_policy_guard_tree_filter_xdp+0xe> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_110e;
x86_l_1118:
	/* 0x1118: lea    rdi,[rdx+0x20c] */
	X86_VM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 524ULL);
x86_l_111f:
	/* 0x111f: cmp    rdi,rcx */
	X86_VM_RUN_OP(X86_OP_CMP_REG, X86_RDI, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_1122:
	/* 0x1122: ja     110e <cilium_policy_guard_tree_filter_xdp+0xe> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_110e;
x86_l_1124:
	/* 0x1124: cmp    DWORD PTR [rsi],0x20 */
	X86_VM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1127:
	/* 0x1127: jne    110e <cilium_policy_guard_tree_filter_xdp+0xe> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_110e;
x86_l_1129:
	/* 0x1129: push   rbp */
	X86_VM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_112a:
	/* 0x112a: mov    rbp,rsp */
	X86_VM_RUN_OP(X86_OP_MOV_REG, X86_RBP, X86_RSP, X86_WIDTH_64, 0, 0);
x86_l_112d:
	/* 0x112d: push   rbx */
	X86_VM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_112e:
	/* 0x112e: lea    rdi,[rdx+0x1b] */
	X86_VM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 27ULL);
x86_l_1132:
	/* 0x1132: movabs rsi,0xe7037ed1a0b428db */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, 0, 16646288086500911323ULL);
x86_l_113c:
	/* 0x113c: xor    r8d,r8d */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_113f:
	/* 0x113f: jmp    117f <cilium_policy_guard_tree_filter_xdp+0x7f> */
	goto x86_l_117f;
x86_l_1141:
	/* 0x1141: shl    rcx,0x30 */
	X86_VM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 48ULL);
x86_l_1145:
	/* 0x1145: data16 cs nop WORD PTR [rax+rax*1+0x0] */
	X86_VM_RUN_OP(X86_OP_NOP, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1150:
	/* 0x1150: xor    rax,rcx */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1153:
	/* 0x1153: add    rsi,rax */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1156:
	/* 0x1156: mov    eax,r8d */
	X86_VM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_R8, X86_WIDTH_32, 0, 0);
x86_l_1159:
	/* 0x1159: and    al,0x7 */
	X86_VM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_ALU_AND, 7ULL);
x86_l_115b:
	/* 0x115b: lea    ecx,[rax+0x1] */
	X86_VM_RUN_OP(X86_OP_LEA, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_115e:
	/* 0x115e: mov    rbx,rsi */
	X86_VM_RUN_OP(X86_OP_MOV_REG, X86_RBX, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_1161:
	/* 0x1161: shl    rbx,cl */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 0);
x86_l_1164:
	/* 0x1164: not    al */
	X86_VM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_ALU_NOT, 0);
x86_l_1166:
	/* 0x1166: mov    ecx,eax */
	X86_VM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_1168:
	/* 0x1168: shr    rsi,cl */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 0);
x86_l_116b:
	/* 0x116b: or     rsi,rbx */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RBX, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_116e:
	/* 0x116e: inc    r8 */
	X86_VM_RUN_OP(X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1171:
	/* 0x1171: add    rdi,0x10 */
	X86_VM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1175:
	/* 0x1175: cmp    r8,0x20 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_64, 0, 32ULL);
x86_l_1179:
	/* 0x1179: je     1234 <cilium_policy_guard_tree_filter_xdp+0x134> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_E))
		goto x86_l_1234;
x86_l_117f:
	/* 0x117f: movzx  ecx,BYTE PTR [rdi-0xf] */
	X86_VM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551601ULL);
x86_l_1183:
	/* 0x1183: mov    rax,QWORD PTR [rdi-0x7] */
	X86_VM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551609ULL);
x86_l_1187:
	/* 0x1187: cmp    rcx,0x21 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, 0, 33ULL);
x86_l_118b:
	/* 0x118b: jb     1150 <cilium_policy_guard_tree_filter_xdp+0x50> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_B))
		goto x86_l_1150;
x86_l_118d:
	/* 0x118d: movzx  r9d,BYTE PTR [rdi-0xe] */
	X86_VM_RUN_OP(X86_OP_MOV_LOAD, X86_R9, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551602ULL);
x86_l_1192:
	/* 0x1192: test   r9b,0x1 */
	X86_VM_RUN_OP(X86_OP_TEST_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_1196:
	/* 0x1196: je     11f9 <cilium_policy_guard_tree_filter_xdp+0xf9> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_E))
		goto x86_l_11f9;
x86_l_1198:
	/* 0x1198: movzx  r9d,BYTE PTR [rdi-0xd] */
	X86_VM_RUN_OP(X86_OP_MOV_LOAD, X86_R9, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551603ULL);
x86_l_119d:
	/* 0x119d: test   r9b,r9b */
	X86_VM_RUN_OP(X86_OP_TEST_REG, X86_R9, X86_R9, X86_WIDTH_8, 0, 0);
x86_l_11a0:
	/* 0x11a0: js     11ef <cilium_policy_guard_tree_filter_xdp+0xef> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_S))
		goto x86_l_11ef;
x86_l_11a2:
	/* 0x11a2: movzx  r9d,BYTE PTR [rdi-0xc] */
	X86_VM_RUN_OP(X86_OP_MOV_LOAD, X86_R9, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551604ULL);
x86_l_11a7:
	/* 0x11a7: mov    r10d,r9d */
	X86_VM_RUN_OP(X86_OP_MOV_REG, X86_R10, X86_R9, X86_WIDTH_32, 0, 0);
x86_l_11aa:
	/* 0x11aa: xor    r10d,r8d */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_R10, X86_R8, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_11ad:
	/* 0x11ad: cmp    r10b,0x11 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_8, 0, 17ULL);
x86_l_11b1:
	/* 0x11b1: jb     11f5 <cilium_policy_guard_tree_filter_xdp+0xf5> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_B))
		goto x86_l_11f5;
x86_l_11b3:
	/* 0x11b3: movzx  r9d,BYTE PTR [rdi-0xb] */
	X86_VM_RUN_OP(X86_OP_MOV_LOAD, X86_R9, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551605ULL);
x86_l_11b8:
	/* 0x11b8: add    cl,r9b */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_R9, X86_WIDTH_8, X86_ALU_ADD, 0);
x86_l_11bb:
	/* 0x11bb: cmp    cl,0xbf */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, 0, 191ULL);
x86_l_11be:
	/* 0x11be: ja     1204 <cilium_policy_guard_tree_filter_xdp+0x104> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_1204;
x86_l_11c0:
	/* 0x11c0: movzx  ecx,BYTE PTR [rdi-0xa] */
	X86_VM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551606ULL);
x86_l_11c4:
	/* 0x11c4: mov    r9d,ecx */
	X86_VM_RUN_OP(X86_OP_MOV_REG, X86_R9, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_11c7:
	/* 0x11c7: and    r9b,0x18 */
	X86_VM_RUN_OP(X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_8, X86_ALU_AND, 24ULL);
x86_l_11cb:
	/* 0x11cb: cmp    r9b,0x10 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_8, 0, 16ULL);
x86_l_11cf:
	/* 0x11cf: jne    1210 <cilium_policy_guard_tree_filter_xdp+0x110> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_1210;
x86_l_11d1:
	/* 0x11d1: movzx  r9d,BYTE PTR [rdi-0x9] */
	X86_VM_RUN_OP(X86_OP_MOV_LOAD, X86_R9, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551607ULL);
x86_l_11d6:
	/* 0x11d6: cmp    r9d,0xaa */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_32, 0, 170ULL);
x86_l_11dd:
	/* 0x11dd: jne    1219 <cilium_policy_guard_tree_filter_xdp+0x119> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_1219;
x86_l_11df:
	/* 0x11df: xor    rcx,rax */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_11e2:
	/* 0x11e2: shld   rcx,rax,0x7 */
	X86_VM_RUN_OP(X86_OP_SHLD_IMM, X86_RCX, X86_RAX, X86_WIDTH_64, 0, 7ULL);
x86_l_11e7:
	/* 0x11e7: add    rsi,rcx */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_11ea:
	/* 0x11ea: jmp    1156 <cilium_policy_guard_tree_filter_xdp+0x56> */
	goto x86_l_1156;
x86_l_11ef:
	/* 0x11ef: shl    r9d,0x8 */
	X86_VM_RUN_OP(X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 8ULL);
x86_l_11f3:
	/* 0x11f3: jmp    1208 <cilium_policy_guard_tree_filter_xdp+0x108> */
	goto x86_l_1208;
x86_l_11f5:
	/* 0x11f5: shl    r9d,0x10 */
	X86_VM_RUN_OP(X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 16ULL);
x86_l_11f9:
	/* 0x11f9: add    rax,r9 */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_R9, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_11fc:
	/* 0x11fc: xor    rsi,rax */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_11ff:
	/* 0x11ff: jmp    1156 <cilium_policy_guard_tree_filter_xdp+0x56> */
	goto x86_l_1156;
x86_l_1204:
	/* 0x1204: shl    r9d,0x18 */
	X86_VM_RUN_OP(X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 24ULL);
x86_l_1208:
	/* 0x1208: xor    rax,r9 */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_R9, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_120b:
	/* 0x120b: jmp    1153 <cilium_policy_guard_tree_filter_xdp+0x53> */
	goto x86_l_1153;
x86_l_1210:
	/* 0x1210: shl    rcx,0x20 */
	X86_VM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_1214:
	/* 0x1214: add    rax,rcx */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1217:
	/* 0x1217: jmp    11fc <cilium_policy_guard_tree_filter_xdp+0xfc> */
	goto x86_l_11fc;
x86_l_1219:
	/* 0x1219: movzx  ecx,BYTE PTR [rdi-0x8] */
	X86_VM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551608ULL);
x86_l_121d:
	/* 0x121d: mov    r10d,ecx */
	X86_VM_RUN_OP(X86_OP_MOV_REG, X86_R10, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_1220:
	/* 0x1220: and    r10b,0x3 */
	X86_VM_RUN_OP(X86_OP_ALU_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_8, X86_ALU_AND, 3ULL);
x86_l_1224:
	/* 0x1224: cmp    r10b,0x1 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_1228:
	/* 0x1228: je     1141 <cilium_policy_guard_tree_filter_xdp+0x41> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_E))
		goto x86_l_1141;
x86_l_122e:
	/* 0x122e: shl    r9,0x28 */
	X86_VM_RUN_OP(X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 40ULL);
x86_l_1232:
	/* 0x1232: jmp    11f9 <cilium_policy_guard_tree_filter_xdp+0xf9> */
	goto x86_l_11f9;
x86_l_1234:
	/* 0x1234: mov    BYTE PTR [rdx],sil */
	X86_VM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RSI, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1237:
	/* 0x1237: mov    BYTE PTR [rdx+0x1],bh */
	X86_VM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RBX, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_REG_AUX_SRC_SHIFT(8)), 1ULL);
x86_l_123a:
	/* 0x123a: mov    eax,ebx */
	X86_VM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RBX, X86_WIDTH_32, 0, 0);
x86_l_123c:
	/* 0x123c: shr    eax,0x10 */
	X86_VM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_123f:
	/* 0x123f: mov    BYTE PTR [rdx+0x2],al */
	X86_VM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_1242:
	/* 0x1242: mov    eax,ebx */
	X86_VM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RBX, X86_WIDTH_32, 0, 0);
x86_l_1244:
	/* 0x1244: shr    eax,0x18 */
	X86_VM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHR, 24ULL);
x86_l_1247:
	/* 0x1247: mov    BYTE PTR [rdx+0x3],al */
	X86_VM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 3ULL);
x86_l_124a:
	/* 0x124a: mov    rax,rbx */
	X86_VM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_124d:
	/* 0x124d: shr    rax,0x20 */
	X86_VM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_1251:
	/* 0x1251: mov    BYTE PTR [rdx+0x4],al */
	X86_VM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1254:
	/* 0x1254: mov    rax,rbx */
	X86_VM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_1257:
	/* 0x1257: shr    rax,0x28 */
	X86_VM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 40ULL);
x86_l_125b:
	/* 0x125b: mov    BYTE PTR [rdx+0x5],al */
	X86_VM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_125e:
	/* 0x125e: mov    rax,rbx */
	X86_VM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_1261:
	/* 0x1261: shr    rax,0x30 */
	X86_VM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 48ULL);
x86_l_1265:
	/* 0x1265: mov    BYTE PTR [rdx+0x6],al */
	X86_VM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_1268:
	/* 0x1268: shr    rbx,0x38 */
	X86_VM_RUN_OP(X86_OP_ALU_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 56ULL);
x86_l_126c:
	/* 0x126c: mov    BYTE PTR [rdx+0x7],bl */
	X86_VM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RBX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 7ULL);
x86_l_126f:
	/* 0x126f: mov    eax,0x2 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_1274:
	/* 0x1274: pop    rbx */
	X86_VM_RUN_OP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1275:
	/* 0x1275: pop    rbp */
	X86_VM_RUN_OP(X86_OP_POP, X86_RBP, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1276:
	/* 0x1276: ret */
	X86_VM_RET_RAX();

	return XDP_ABORTED;
}

X86_VM_LICENSE();
