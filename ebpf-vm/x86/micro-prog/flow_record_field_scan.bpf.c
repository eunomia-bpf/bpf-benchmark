#define X86_VM_ENABLE_STACK 1
#include "../x86_vm_bpf.h"

SEC("xdp")
int flow_record_field_scan_x86_vm_xdp(struct xdp_md *ctx)
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
	/* 0x110c: jbe    110f <flow_record_field_scan_xdp+0xf> */
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
	/* 0x1116: ja     110e <flow_record_field_scan_xdp+0xe> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_110e;
x86_l_1118:
	/* 0x1118: lea    rdi,[rdx+0x410] */
	X86_VM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1040ULL);
x86_l_111f:
	/* 0x111f: cmp    rdi,rcx */
	X86_VM_RUN_OP(X86_OP_CMP_REG, X86_RDI, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_1122:
	/* 0x1122: ja     110e <flow_record_field_scan_xdp+0xe> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_110e;
x86_l_1124:
	/* 0x1124: cmp    DWORD PTR [rsi],0x20 */
	X86_VM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1127:
	/* 0x1127: jne    110e <flow_record_field_scan_xdp+0xe> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_110e;
x86_l_1129:
	/* 0x1129: cmp    DWORD PTR [rdx+0xc],0x20 */
	X86_VM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607584ULL);
x86_l_112d:
	/* 0x112d: jne    110e <flow_record_field_scan_xdp+0xe> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_110e;
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
	/* 0x1134: movabs r8,0x9e3779b97f4a7c15 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_64, 0, 11400714819323198485ULL);
x86_l_113e:
	/* 0x113e: xor    esi,esi */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1140:
	/* 0x1140: xor    edi,edi */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1142:
	/* 0x1142: jmp    118e <flow_record_field_scan_xdp+0x8e> */
	goto x86_l_118e;
x86_l_1144:
	/* 0x1144: data16 data16 cs nop WORD PTR [rax+rax*1+0x0] */
	X86_VM_RUN_OP(X86_OP_NOP, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1150:
	/* 0x1150: mov    ecx,edi */
	X86_VM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RDI, X86_WIDTH_32, 0, 0);
x86_l_1152:
	/* 0x1152: and    cl,0x7 */
	X86_VM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_ALU_AND, 7ULL);
x86_l_1155:
	/* 0x1155: shr    r10,cl */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_R10, X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 0);
x86_l_1158:
	/* 0x1158: xor    r9,r10 */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_R10, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_115b:
	/* 0x115b: add    r9,r11 */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_R11, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_115e:
	/* 0x115e: mov    ecx,esi */
	X86_VM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_1160:
	/* 0x1160: and    cl,0x18 */
	X86_VM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_ALU_AND, 24ULL);
x86_l_1163:
	/* 0x1163: mov    r8,rax */
	X86_VM_RUN_OP(X86_OP_MOV_REG, X86_R8, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_1166:
	/* 0x1166: shl    r8,cl */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_R8, X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 0);
x86_l_1169:
	/* 0x1169: xor    r8,r9 */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_R8, X86_R9, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_116c:
	/* 0x116c: and    al,0x7 */
	X86_VM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_ALU_AND, 7ULL);
x86_l_116e:
	/* 0x116e: lea    ecx,[rax+0x1] */
	X86_VM_RUN_OP(X86_OP_LEA, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_1171:
	/* 0x1171: mov    rbx,r8 */
	X86_VM_RUN_OP(X86_OP_MOV_REG, X86_RBX, X86_R8, X86_WIDTH_64, 0, 0);
x86_l_1174:
	/* 0x1174: shl    rbx,cl */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 0);
x86_l_1177:
	/* 0x1177: not    al */
	X86_VM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_ALU_NOT, 0);
x86_l_1179:
	/* 0x1179: mov    ecx,eax */
	X86_VM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_117b:
	/* 0x117b: shr    r8,cl */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_R8, X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 0);
x86_l_117e:
	/* 0x117e: or     r8,rbx */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_R8, X86_RBX, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_1181:
	/* 0x1181: inc    rdi */
	X86_VM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1184:
	/* 0x1184: add    rsi,0x8 */
	X86_VM_RUN_OP(X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1188:
	/* 0x1188: cmp    rdi,0x20 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, 32ULL);
x86_l_118c:
	/* 0x118c: je     11d6 <flow_record_field_scan_xdp+0xd6> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_E))
		goto x86_l_11d6;
x86_l_118e:
	/* 0x118e: mov    r10,QWORD PTR [rdx+rsi*4+0x20] */
	X86_VM_RUN_OP(X86_OP_MOV_LOAD, X86_R10, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 2), 32ULL);
x86_l_1193:
	/* 0x1193: mov    rcx,QWORD PTR [rdx+rsi*4+0x18] */
	X86_VM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 2), 24ULL);
x86_l_1198:
	/* 0x1198: add    rcx,r10 */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_R10, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_119b:
	/* 0x119b: mov    eax,DWORD PTR [rdx+rsi*4+0x28] */
	X86_VM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 40ULL);
x86_l_119f:
	/* 0x119f: shl    rax,0x20 */
	X86_VM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_11a3:
	/* 0x11a3: mov    r9d,DWORD PTR [rdx+rsi*4+0x2c] */
	X86_VM_RUN_OP(X86_OP_MOV_LOAD, X86_R9, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 44ULL);
x86_l_11a8:
	/* 0x11a8: or     r9,rax */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_RAX, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_11ab:
	/* 0x11ab: mov    eax,DWORD PTR [rdx+rsi*4+0x10] */
	X86_VM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 16ULL);
x86_l_11af:
	/* 0x11af: mov    r11,rax */
	X86_VM_RUN_OP(X86_OP_MOV_REG, X86_R11, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_11b2:
	/* 0x11b2: shl    r11,0x10 */
	X86_VM_RUN_OP(X86_OP_ALU_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 16ULL);
x86_l_11b6:
	/* 0x11b6: movzx  ebx,WORD PTR [rdx+rsi*4+0x14] */
	X86_VM_RUN_OP(X86_OP_MOV_LOAD, X86_RBX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 2, X86_WIDTH_16), 20ULL);
x86_l_11bb:
	/* 0x11bb: or     r11,rbx */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_R11, X86_RBX, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_11be:
	/* 0x11be: xor    r11,rcx */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_R11, X86_RCX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_11c1:
	/* 0x11c1: add    r11,r8 */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_R11, X86_R8, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_11c4:
	/* 0x11c4: test   bl,0x1 */
	X86_VM_RUN_OP(X86_OP_TEST_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_11c7:
	/* 0x11c7: je     1150 <flow_record_field_scan_xdp+0x50> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_E))
		goto x86_l_1150;
x86_l_11c9:
	/* 0x11c9: movzx  ecx,WORD PTR [rdx+rsi*4+0x16] */
	X86_VM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 2, X86_WIDTH_16), 22ULL);
x86_l_11ce:
	/* 0x11ce: add    r9,rcx */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_11d1:
	/* 0x11d1: xor    r9,r11 */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_R11, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_11d4:
	/* 0x11d4: jmp    115e <flow_record_field_scan_xdp+0x5e> */
	goto x86_l_115e;
x86_l_11d6:
	/* 0x11d6: mov    BYTE PTR [rdx],r8b */
	X86_VM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_R8, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11d9:
	/* 0x11d9: mov    BYTE PTR [rdx+0x1],bh */
	X86_VM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RBX, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_REG_AUX_SRC_SHIFT(8)), 1ULL);
x86_l_11dc:
	/* 0x11dc: mov    eax,ebx */
	X86_VM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RBX, X86_WIDTH_32, 0, 0);
x86_l_11de:
	/* 0x11de: shr    eax,0x10 */
	X86_VM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_11e1:
	/* 0x11e1: mov    BYTE PTR [rdx+0x2],al */
	X86_VM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_11e4:
	/* 0x11e4: mov    eax,ebx */
	X86_VM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RBX, X86_WIDTH_32, 0, 0);
x86_l_11e6:
	/* 0x11e6: shr    eax,0x18 */
	X86_VM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHR, 24ULL);
x86_l_11e9:
	/* 0x11e9: mov    BYTE PTR [rdx+0x3],al */
	X86_VM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 3ULL);
x86_l_11ec:
	/* 0x11ec: mov    rax,rbx */
	X86_VM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_11ef:
	/* 0x11ef: shr    rax,0x20 */
	X86_VM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_11f3:
	/* 0x11f3: mov    BYTE PTR [rdx+0x4],al */
	X86_VM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_11f6:
	/* 0x11f6: mov    rax,rbx */
	X86_VM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_11f9:
	/* 0x11f9: shr    rax,0x28 */
	X86_VM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 40ULL);
x86_l_11fd:
	/* 0x11fd: mov    BYTE PTR [rdx+0x5],al */
	X86_VM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_1200:
	/* 0x1200: mov    rax,rbx */
	X86_VM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_1203:
	/* 0x1203: shr    rax,0x30 */
	X86_VM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 48ULL);
x86_l_1207:
	/* 0x1207: mov    BYTE PTR [rdx+0x6],al */
	X86_VM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_120a:
	/* 0x120a: shr    rbx,0x38 */
	X86_VM_RUN_OP(X86_OP_ALU_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 56ULL);
x86_l_120e:
	/* 0x120e: mov    BYTE PTR [rdx+0x7],bl */
	X86_VM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RBX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 7ULL);
x86_l_1211:
	/* 0x1211: mov    eax,0x2 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_1216:
	/* 0x1216: pop    rbx */
	X86_VM_RUN_OP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1217:
	/* 0x1217: pop    rbp */
	X86_VM_RUN_OP(X86_OP_POP, X86_RBP, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1218:
	/* 0x1218: ret */
	X86_VM_RET_RAX();

	return XDP_ABORTED;
}

X86_VM_LICENSE();
