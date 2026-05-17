#include "../x86_vm_bpf.h"

SEC("xdp")
int bpf_local_call_fanout_dispatch_x86_vm_xdp(struct xdp_md *ctx)
{
	X86_VM_DECLARE_XDP(ctx);
x86_l_1100:
	/* 0x1100: push   rbp */
	X86_VM_RUN_STEP(X86_OP_PUSH, X86_REG_NONE, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_1101:
	/* 0x1101: push   r15 */
	X86_VM_RUN_STEP(X86_OP_PUSH, X86_REG_NONE, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_1103:
	/* 0x1103: push   r14 */
	X86_VM_RUN_STEP(X86_OP_PUSH, X86_REG_NONE, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_1105:
	/* 0x1105: push   r13 */
	X86_VM_RUN_STEP(X86_OP_PUSH, X86_REG_NONE, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_1107:
	/* 0x1107: push   r12 */
	X86_VM_RUN_STEP(X86_OP_PUSH, X86_REG_NONE, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_1109:
	/* 0x1109: push   rbx */
	X86_VM_RUN_STEP(X86_OP_PUSH, X86_REG_NONE, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_110a:
	/* 0x110a: push   rax */
	X86_VM_RUN_STEP(X86_OP_PUSH, X86_REG_NONE, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_110b:
	/* 0x110b: mov    r14,QWORD PTR [rdi] */
	X86_VM_RUN_STEP(X86_OP_MOV_LOAD, X86_R14, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_110e:
	/* 0x110e: mov    rcx,QWORD PTR [rdi+0x8] */
	X86_VM_RUN_STEP(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1112:
	/* 0x1112: xor    eax,eax */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1114:
	/* 0x1114: cmp    r14,rcx */
	X86_VM_RUN_STEP(X86_OP_CMP_REG, X86_R14, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_1117:
	/* 0x1117: jbe    1128 <bpf_local_call_fanout_dispatch_xdp+0x28> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_BE))
		goto x86_l_1128;
x86_l_1119:
	/* 0x1119: add    rsp,0x8 */
	X86_VM_RUN_STEP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_111d:
	/* 0x111d: pop    rbx */
	X86_VM_RUN_STEP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_111e:
	/* 0x111e: pop    r12 */
	X86_VM_RUN_STEP(X86_OP_POP, X86_R12, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1120:
	/* 0x1120: pop    r13 */
	X86_VM_RUN_STEP(X86_OP_POP, X86_R13, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1122:
	/* 0x1122: pop    r14 */
	X86_VM_RUN_STEP(X86_OP_POP, X86_R14, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1124:
	/* 0x1124: pop    r15 */
	X86_VM_RUN_STEP(X86_OP_POP, X86_R15, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1126:
	/* 0x1126: pop    rbp */
	X86_VM_RUN_STEP(X86_OP_POP, X86_RBP, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1127:
	/* 0x1127: ret */
	X86_VM_RET_RAX();
x86_l_1128:
	/* 0x1128: lea    rdx,[r14+0x8] */
	X86_VM_RUN_STEP(X86_OP_LEA, X86_RDX, X86_R14, X86_WIDTH_64, 0, 8ULL);
x86_l_112c:
	/* 0x112c: mov    QWORD PTR [rsp],rdx */
	X86_VM_RUN_STEP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1130:
	/* 0x1130: cmp    rdx,rcx */
	X86_VM_RUN_STEP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_1133:
	/* 0x1133: ja     1119 <bpf_local_call_fanout_dispatch_xdp+0x19> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_1119;
x86_l_1135:
	/* 0x1135: lea    rdx,[r14+0x190] */
	X86_VM_RUN_STEP(X86_OP_LEA, X86_RDX, X86_R14, X86_WIDTH_64, 0, 400ULL);
x86_l_113c:
	/* 0x113c: cmp    rdx,rcx */
	X86_VM_RUN_STEP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_113f:
	/* 0x113f: ja     1119 <bpf_local_call_fanout_dispatch_xdp+0x19> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_1119;
x86_l_1141:
	/* 0x1141: cmp    DWORD PTR [r14+0x8],0x10 */
	X86_VM_RUN_STEP(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738384ULL);
x86_l_1146:
	/* 0x1146: jne    1119 <bpf_local_call_fanout_dispatch_xdp+0x19> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_1119;
x86_l_1148:
	/* 0x1148: cmp    DWORD PTR [r14+0xc],0x18 */
	X86_VM_RUN_STEP(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607576ULL);
x86_l_114d:
	/* 0x114d: jne    1119 <bpf_local_call_fanout_dispatch_xdp+0x19> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_1119;
x86_l_114f:
	/* 0x114f: movabs rdi,0x243f6a8885a308d3 */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, 2611923443488327891ULL);
x86_l_1159:
	/* 0x1159: xor    r15d,r15d */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_115c:
	/* 0x115c: mov    r12d,0x17 */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 23ULL);
x86_l_1162:
	/* 0x1162: xor    r13d,r13d */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1165:
	/* 0x1165: jmp    11a1 <bpf_local_call_fanout_dispatch_xdp+0xa1> */
	goto x86_l_11a1;
x86_l_1167:
	/* 0x1167: nop    WORD PTR [rax+rax*1+0x0] */
	X86_VM_RUN_STEP(X86_OP_NOP, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1170:
	/* 0x1170: mov    rsi,QWORD PTR [rsp] */
	X86_VM_RUN_STEP(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1174:
	/* 0x1174: mov    ecx,ebp */
	X86_VM_RUN_STEP(X86_OP_MOV_REG, X86_RCX, X86_RBP, X86_WIDTH_32, 0, 0);
x86_l_1176:
	/* 0x1176: call   1260 <local_call_pressure> */
	X86_VM_RUN_STEP(X86_OP_CALL, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, 4704ULL);
x86_l_117b:
	/* 0x117b: mov    ecx,r13d */
	X86_VM_RUN_STEP(X86_OP_MOV_REG, X86_RCX, X86_R13, X86_WIDTH_32, 0, 0);
x86_l_117e:
	/* 0x117e: and    cl,0x38 */
	X86_VM_RUN_STEP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_ALU_AND, 56ULL);
x86_l_1181:
	/* 0x1181: shl    rbx,cl */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 0);
x86_l_1184:
	/* 0x1184: mov    edi,ebp */
	X86_VM_RUN_STEP(X86_OP_MOV_REG, X86_RDI, X86_RBP, X86_WIDTH_32, 0, 0);
x86_l_1186:
	/* 0x1186: add    rdi,rbx */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1189:
	/* 0x1189: xor    rdi,rax */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_RDI, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_118c:
	/* 0x118c: add    r13,0x8 */
	X86_VM_RUN_STEP(X86_OP_ALU_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1190:
	/* 0x1190: add    r15d,0x10 */
	X86_VM_RUN_STEP(X86_OP_ALU_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 16ULL);
x86_l_1194:
	/* 0x1194: add    r12,0x18 */
	X86_VM_RUN_STEP(X86_OP_ALU_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1198:
	/* 0x1198: cmp    r13,0x80 */
	X86_VM_RUN_STEP(X86_OP_CMP_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, 0, 128ULL);
x86_l_119f:
	/* 0x119f: je     1200 <bpf_local_call_fanout_dispatch_xdp+0x100> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_E))
		goto x86_l_1200;
x86_l_11a1:
	/* 0x11a1: movzx  ebx,BYTE PTR [r14+r12*1-0x7] */
	X86_VM_RUN_STEP(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R12, 0, X86_WIDTH_8), 18446744073709551609ULL);
x86_l_11a7:
	/* 0x11a7: and    ebx,0x3 */
	X86_VM_RUN_STEP(X86_OP_ALU_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 3ULL);
x86_l_11aa:
	/* 0x11aa: mov    ebp,DWORD PTR [r14+r12*1-0x3] */
	X86_VM_RUN_STEP(X86_OP_MOV_LOAD, X86_RBP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 18446744073709551613ULL);
x86_l_11af:
	/* 0x11af: xor    ebp,r15d */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_RBP, X86_R15, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_11b2:
	/* 0x11b2: lea    rdx,[r12-0xf] */
	X86_VM_RUN_STEP(X86_OP_LEA, X86_RDX, X86_R12, X86_WIDTH_64, 0, 18446744073709551601ULL);
x86_l_11b7:
	/* 0x11b7: cmp    rbx,0x2 */
	X86_VM_RUN_STEP(X86_OP_CMP_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 2ULL);
x86_l_11bb:
	/* 0x11bb: je     11e0 <bpf_local_call_fanout_dispatch_xdp+0xe0> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_E))
		goto x86_l_11e0;
x86_l_11bd:
	/* 0x11bd: cmp    ebx,0x1 */
	X86_VM_RUN_STEP(X86_OP_CMP_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_11c0:
	/* 0x11c0: je     1170 <bpf_local_call_fanout_dispatch_xdp+0x70> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_E))
		goto x86_l_1170;
x86_l_11c2:
	/* 0x11c2: test   ebx,ebx */
	X86_VM_RUN_STEP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_32, 0, 0);
x86_l_11c4:
	/* 0x11c4: jne    11f0 <bpf_local_call_fanout_dispatch_xdp+0xf0> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_11f0;
x86_l_11c6:
	/* 0x11c6: mov    rsi,QWORD PTR [rsp] */
	X86_VM_RUN_STEP(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11ca:
	/* 0x11ca: mov    ecx,ebp */
	X86_VM_RUN_STEP(X86_OP_MOV_REG, X86_RCX, X86_RBP, X86_WIDTH_32, 0, 0);
x86_l_11cc:
	/* 0x11cc: call   1210 <local_call_linear> */
	X86_VM_RUN_STEP(X86_OP_CALL, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, 4624ULL);
x86_l_11d1:
	/* 0x11d1: jmp    117b <bpf_local_call_fanout_dispatch_xdp+0x7b> */
	goto x86_l_117b;
x86_l_11d3:
	/* 0x11d3: data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0] */
	X86_VM_RUN_STEP(X86_OP_NOP, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_11e0:
	/* 0x11e0: mov    rsi,QWORD PTR [rsp] */
	X86_VM_RUN_STEP(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11e4:
	/* 0x11e4: mov    ecx,ebp */
	X86_VM_RUN_STEP(X86_OP_MOV_REG, X86_RCX, X86_RBP, X86_WIDTH_32, 0, 0);
x86_l_11e6:
	/* 0x11e6: call   12b0 <local_call_crossload> */
	X86_VM_RUN_STEP(X86_OP_CALL, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, 4784ULL);
x86_l_11eb:
	/* 0x11eb: jmp    117b <bpf_local_call_fanout_dispatch_xdp+0x7b> */
	goto x86_l_117b;
x86_l_11ed:
	/* 0x11ed: nop    DWORD PTR [rax] */
	X86_VM_RUN_STEP(X86_OP_NOP, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_11f0:
	/* 0x11f0: mov    rsi,QWORD PTR [rsp] */
	X86_VM_RUN_STEP(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11f4:
	/* 0x11f4: mov    ecx,ebp */
	X86_VM_RUN_STEP(X86_OP_MOV_REG, X86_RCX, X86_RBP, X86_WIDTH_32, 0, 0);
x86_l_11f6:
	/* 0x11f6: call   1340 <local_call_bytes> */
	X86_VM_RUN_STEP(X86_OP_CALL, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, 4928ULL);
x86_l_11fb:
	/* 0x11fb: jmp    117b <bpf_local_call_fanout_dispatch_xdp+0x7b> */
	goto x86_l_117b;
x86_l_1200:
	/* 0x1200: mov    QWORD PTR [r14],rdi */
	X86_VM_RUN_STEP(X86_OP_MOV_STORE_REG, X86_R14, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1203:
	/* 0x1203: mov    eax,0x2 */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_1208:
	/* 0x1208: jmp    1119 <bpf_local_call_fanout_dispatch_xdp+0x19> */
	goto x86_l_1119;
	return XDP_ABORTED;
}

X86_VM_LICENSE();
