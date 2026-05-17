#define X86_VM_ENABLE_RODATA 1
#include "../x86_vm_bpf.h"

SEC("xdp")
int tracee_http_method_prefix_detect_x86_vm_xdp(struct xdp_md *ctx)
{
	X86_VM_DECLARE_XDP(ctx);
x86_l_1100:
	/* 0x1100: mov    rdx,QWORD PTR [rdi] */
	X86_VM_RUN_STEP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1103:
	/* 0x1103: mov    rcx,QWORD PTR [rdi+0x8] */
	X86_VM_RUN_STEP(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1107:
	/* 0x1107: xor    eax,eax */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1109:
	/* 0x1109: cmp    rdx,rcx */
	X86_VM_RUN_STEP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_110c:
	/* 0x110c: jbe    110f <tracee_http_method_prefix_detect_xdp+0xf> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_BE))
		goto x86_l_110f;
x86_l_110e:
	/* 0x110e: ret */
	X86_VM_RET_RAX();
x86_l_110f:
	/* 0x110f: lea    rsi,[rdx+0x8] */
	X86_VM_RUN_STEP(X86_OP_LEA, X86_RSI, X86_RDX, X86_WIDTH_64, 0, 8ULL);
x86_l_1113:
	/* 0x1113: cmp    rsi,rcx */
	X86_VM_RUN_STEP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_1116:
	/* 0x1116: ja     110e <tracee_http_method_prefix_detect_xdp+0xe> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_110e;
x86_l_1118:
	/* 0x1118: lea    rsi,[rdx+0x90] */
	X86_VM_RUN_STEP(X86_OP_LEA, X86_RSI, X86_RDX, X86_WIDTH_64, 0, 144ULL);
x86_l_111f:
	/* 0x111f: cmp    rsi,rcx */
	X86_VM_RUN_STEP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_1122:
	/* 0x1122: ja     110e <tracee_http_method_prefix_detect_xdp+0xe> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_110e;
x86_l_1124:
	/* 0x1124: cmp    DWORD PTR [rdx+0x8],0x8 */
	X86_VM_RUN_STEP(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738376ULL);
x86_l_1128:
	/* 0x1128: jne    110e <tracee_http_method_prefix_detect_xdp+0xe> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_110e;
x86_l_112a:
	/* 0x112a: cmp    DWORD PTR [rdx+0xc],0x10 */
	X86_VM_RUN_STEP(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607568ULL);
x86_l_112e:
	/* 0x112e: jne    110e <tracee_http_method_prefix_detect_xdp+0xe> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_110e;
x86_l_1130:
	/* 0x1130: push   r15 */
	X86_VM_RUN_STEP(X86_OP_PUSH, X86_REG_NONE, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_1132:
	/* 0x1132: push   r14 */
	X86_VM_RUN_STEP(X86_OP_PUSH, X86_REG_NONE, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_1134:
	/* 0x1134: push   rbx */
	X86_VM_RUN_STEP(X86_OP_PUSH, X86_REG_NONE, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_1135:
	/* 0x1135: lea    rax,[rdx+0x16] */
	X86_VM_RUN_STEP(X86_OP_LEA, X86_RAX, X86_RDX, X86_WIDTH_64, 0, 22ULL);
x86_l_1139:
	/* 0x1139: movabs rbx,0xa0761d6478bd642f */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 11562461410679940143ULL);
x86_l_1143:
	/* 0x1143: mov    ecx,0x1 */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_1148:
	/* 0x1148: lea    rsi,[rip+0xeb1] */
	X86_VM_RUN_STEP(X86_OP_LEA, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_PTR_RODATA, 3761ULL);
x86_l_114f:
	/* 0x114f: nop */
	X86_VM_RUN_STEP(X86_OP_NOP, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1150:
	/* 0x1150: mov    rdi,rbx */
	X86_VM_RUN_STEP(X86_OP_MOV_REG, X86_RDI, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_1153:
	/* 0x1153: movzx  r8d,BYTE PTR [rax-0x6] */
	X86_VM_RUN_STEP(X86_OP_MOV_LOAD, X86_R8, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551610ULL);
x86_l_1158:
	/* 0x1158: movzx  r9d,BYTE PTR [rax-0x5] */
	X86_VM_RUN_STEP(X86_OP_MOV_LOAD, X86_R9, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551611ULL);
x86_l_115d:
	/* 0x115d: lea    r11d,[r8-0x44] */
	X86_VM_RUN_STEP(X86_OP_LEA, X86_R11, X86_R8, X86_WIDTH_32, 0, 18446744073709551548ULL);
x86_l_1161:
	/* 0x1161: cmp    r11d,0xc */
	X86_VM_RUN_STEP(X86_OP_CMP_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_32, 0, 12ULL);
x86_l_1165:
	/* 0x1165: ja     12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_12c0;
x86_l_116b:
	/* 0x116b: movzx  r10d,r9b */
	X86_VM_RUN_STEP(X86_OP_MOVZX_REG, X86_R10, X86_R9, X86_WIDTH_32, X86_WIDTH_8, 0);
x86_l_116f:
	/* 0x116f: movsxd r11,DWORD PTR [rsi+r11*4] */
	X86_VM_RUN_STEP(X86_OP_MOVSX_LOAD, X86_R11, X86_RSI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_R11, 2, X86_WIDTH_32), 0ULL);
x86_l_1173:
	/* 0x1173: add    r11,rsi */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_R11, X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1176:
	/* 0x1176: jmp    r11 */
	return XDP_ABORTED;
x86_l_1179:
	/* 0x1179: cmp    r9b,0x45 */
	X86_VM_RUN_STEP(X86_OP_CMP_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_8, 0, 69ULL);
x86_l_117d:
	/* 0x117d: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_12c0;
x86_l_1183:
	/* 0x1183: mov    r9b,0x45 */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_8, 0, 69ULL);
x86_l_1186:
	/* 0x1186: cmp    BYTE PTR [rax-0x4],0x4c */
	X86_VM_RUN_STEP(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744056529682508ULL);
x86_l_118a:
	/* 0x118a: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_12c0;
x86_l_1190:
	/* 0x1190: cmp    BYTE PTR [rax-0x3],0x45 */
	X86_VM_RUN_STEP(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744060824649797ULL);
x86_l_1194:
	/* 0x1194: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_12c0;
x86_l_119a:
	/* 0x119a: cmp    BYTE PTR [rax-0x2],0x54 */
	X86_VM_RUN_STEP(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744065119617108ULL);
x86_l_119e:
	/* 0x119e: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_12c0;
x86_l_11a4:
	/* 0x11a4: cmp    BYTE PTR [rax-0x1],0x45 */
	X86_VM_RUN_STEP(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744069414584389ULL);
x86_l_11a8:
	/* 0x11a8: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_12c0;
x86_l_11ae:
	/* 0x11ae: mov    bl,0x45 */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, 0, 69ULL);
x86_l_11b0:
	/* 0x11b0: cmp    BYTE PTR [rax],0x20 */
	X86_VM_RUN_STEP(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_11b3:
	/* 0x11b3: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_12c0;
x86_l_11b9:
	/* 0x11b9: mov    r10d,0x4 */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_11bf:
	/* 0x11bf: mov    r9b,0x4c */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_8, 0, 76ULL);
x86_l_11c2:
	/* 0x11c2: mov    r11b,0x45 */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_8, 0, 69ULL);
x86_l_11c5:
	/* 0x11c5: jmp    12cf <tracee_http_method_prefix_detect_xdp+0x1cf> */
	goto x86_l_12cf;
x86_l_11ca:
	/* 0x11ca: nop    WORD PTR [rax+rax*1+0x0] */
	X86_VM_RUN_STEP(X86_OP_NOP, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_11d0:
	/* 0x11d0: cmp    r10d,0x54 */
	X86_VM_RUN_STEP(X86_OP_CMP_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_32, 0, 84ULL);
x86_l_11d4:
	/* 0x11d4: je     1275 <tracee_http_method_prefix_detect_xdp+0x175> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_E))
		goto x86_l_1275;
x86_l_11da:
	/* 0x11da: cmp    r10d,0x45 */
	X86_VM_RUN_STEP(X86_OP_CMP_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_32, 0, 69ULL);
x86_l_11de:
	/* 0x11de: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_12c0;
x86_l_11e4:
	/* 0x11e4: mov    r9b,0x45 */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_8, 0, 69ULL);
x86_l_11e7:
	/* 0x11e7: cmp    BYTE PTR [rax-0x4],0x41 */
	X86_VM_RUN_STEP(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744056529682497ULL);
x86_l_11eb:
	/* 0x11eb: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_12c0;
x86_l_11f1:
	/* 0x11f1: cmp    BYTE PTR [rax-0x3],0x44 */
	X86_VM_RUN_STEP(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744060824649796ULL);
x86_l_11f5:
	/* 0x11f5: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_12c0;
x86_l_11fb:
	/* 0x11fb: mov    r11b,0x45 */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_8, 0, 69ULL);
x86_l_11fe:
	/* 0x11fe: cmp    BYTE PTR [rax-0x2],0x20 */
	X86_VM_RUN_STEP(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744065119617056ULL);
x86_l_1202:
	/* 0x1202: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_12c0;
x86_l_1208:
	/* 0x1208: mov    r10d,0x5 */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_32, 0, 5ULL);
x86_l_120e:
	/* 0x120e: mov    r9b,0x41 */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_8, 0, 65ULL);
x86_l_1211:
	/* 0x1211: mov    bl,0x44 */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, 0, 68ULL);
x86_l_1213:
	/* 0x1213: jmp    12cf <tracee_http_method_prefix_detect_xdp+0x1cf> */
	goto x86_l_12cf;
x86_l_1218:
	/* 0x1218: cmp    r9b,0x45 */
	X86_VM_RUN_STEP(X86_OP_CMP_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_8, 0, 69ULL);
x86_l_121c:
	/* 0x121c: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_12c0;
x86_l_1222:
	/* 0x1222: mov    r9b,0x45 */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_8, 0, 69ULL);
x86_l_1225:
	/* 0x1225: cmp    BYTE PTR [rax-0x4],0x54 */
	X86_VM_RUN_STEP(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744056529682516ULL);
x86_l_1229:
	/* 0x1229: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_12c0;
x86_l_122f:
	/* 0x122f: mov    r11b,0x45 */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_8, 0, 69ULL);
x86_l_1232:
	/* 0x1232: cmp    BYTE PTR [rax-0x3],0x20 */
	X86_VM_RUN_STEP(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744060824649760ULL);
x86_l_1236:
	/* 0x1236: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_12c0;
x86_l_123c:
	/* 0x123c: mov    r10d,0x1 */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_1242:
	/* 0x1242: jmp    12af <tracee_http_method_prefix_detect_xdp+0x1af> */
	goto x86_l_12af;
x86_l_1244:
	/* 0x1244: cmp    r10d,0x55 */
	X86_VM_RUN_STEP(X86_OP_CMP_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_32, 0, 85ULL);
x86_l_1248:
	/* 0x1248: je     1297 <tracee_http_method_prefix_detect_xdp+0x197> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_E))
		goto x86_l_1297;
x86_l_124a:
	/* 0x124a: cmp    r10d,0x4f */
	X86_VM_RUN_STEP(X86_OP_CMP_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_32, 0, 79ULL);
x86_l_124e:
	/* 0x124e: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_12c0;
x86_l_1250:
	/* 0x1250: mov    r9b,0x4f */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_8, 0, 79ULL);
x86_l_1253:
	/* 0x1253: cmp    BYTE PTR [rax-0x4],0x53 */
	X86_VM_RUN_STEP(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744056529682515ULL);
x86_l_1257:
	/* 0x1257: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_12c0;
x86_l_1259:
	/* 0x1259: cmp    BYTE PTR [rax-0x3],0x54 */
	X86_VM_RUN_STEP(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744060824649812ULL);
x86_l_125d:
	/* 0x125d: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_12c0;
x86_l_125f:
	/* 0x125f: mov    r11b,0x4f */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_8, 0, 79ULL);
x86_l_1262:
	/* 0x1262: cmp    BYTE PTR [rax-0x2],0x20 */
	X86_VM_RUN_STEP(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744065119617056ULL);
x86_l_1266:
	/* 0x1266: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_12c0;
x86_l_1268:
	/* 0x1268: mov    r10d,0x2 */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_126e:
	/* 0x126e: mov    r9b,0x53 */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_8, 0, 83ULL);
x86_l_1271:
	/* 0x1271: mov    bl,0x54 */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, 0, 84ULL);
x86_l_1273:
	/* 0x1273: jmp    12cf <tracee_http_method_prefix_detect_xdp+0x1cf> */
	goto x86_l_12cf;
x86_l_1275:
	/* 0x1275: mov    r9b,0x54 */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_8, 0, 84ULL);
x86_l_1278:
	/* 0x1278: cmp    BYTE PTR [rax-0x4],0x54 */
	X86_VM_RUN_STEP(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744056529682516ULL);
x86_l_127c:
	/* 0x127c: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_12c0;
x86_l_127e:
	/* 0x127e: cmp    BYTE PTR [rax-0x3],0x50 */
	X86_VM_RUN_STEP(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744060824649808ULL);
x86_l_1282:
	/* 0x1282: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_12c0;
x86_l_1284:
	/* 0x1284: cmp    BYTE PTR [rax-0x2],0x2f */
	X86_VM_RUN_STEP(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744065119617071ULL);
x86_l_1288:
	/* 0x1288: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_12c0;
x86_l_128a:
	/* 0x128a: mov    r10d,0x6 */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_32, 0, 6ULL);
x86_l_1290:
	/* 0x1290: mov    bl,0x50 */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, 0, 80ULL);
x86_l_1292:
	/* 0x1292: mov    r11b,0x54 */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_8, 0, 84ULL);
x86_l_1295:
	/* 0x1295: jmp    12cf <tracee_http_method_prefix_detect_xdp+0x1cf> */
	goto x86_l_12cf;
x86_l_1297:
	/* 0x1297: mov    r9b,0x55 */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_8, 0, 85ULL);
x86_l_129a:
	/* 0x129a: cmp    BYTE PTR [rax-0x4],0x54 */
	X86_VM_RUN_STEP(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744056529682516ULL);
x86_l_129e:
	/* 0x129e: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_12c0;
x86_l_12a0:
	/* 0x12a0: mov    r11b,0x55 */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_8, 0, 85ULL);
x86_l_12a3:
	/* 0x12a3: cmp    BYTE PTR [rax-0x3],0x20 */
	X86_VM_RUN_STEP(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744060824649760ULL);
x86_l_12a7:
	/* 0x12a7: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_12c0;
x86_l_12a9:
	/* 0x12a9: mov    r10d,0x3 */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_32, 0, 3ULL);
x86_l_12af:
	/* 0x12af: mov    r9b,0x54 */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_8, 0, 84ULL);
x86_l_12b2:
	/* 0x12b2: mov    bl,0x20 */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, 0, 32ULL);
x86_l_12b4:
	/* 0x12b4: jmp    12cf <tracee_http_method_prefix_detect_xdp+0x1cf> */
	goto x86_l_12cf;
x86_l_12b6:
	/* 0x12b6: cs nop WORD PTR [rax+rax*1+0x0] */
	X86_VM_RUN_STEP(X86_OP_NOP, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_12c0:
	/* 0x12c0: mov    r11d,r9d */
	X86_VM_RUN_STEP(X86_OP_MOV_REG, X86_R11, X86_R9, X86_WIDTH_32, 0, 0);
x86_l_12c3:
	/* 0x12c3: movzx  r9d,BYTE PTR [rax-0x4] */
	X86_VM_RUN_STEP(X86_OP_MOV_LOAD, X86_R9, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551612ULL);
x86_l_12c8:
	/* 0x12c8: movzx  ebx,BYTE PTR [rax-0x3] */
	X86_VM_RUN_STEP(X86_OP_MOV_LOAD, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551613ULL);
x86_l_12cc:
	/* 0x12cc: xor    r10d,r10d */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_R10, X86_R10, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_12cf:
	/* 0x12cf: movzx  ebx,bl */
	X86_VM_RUN_STEP(X86_OP_MOVZX_REG, X86_RBX, X86_RBX, X86_WIDTH_32, X86_WIDTH_8, 0);
x86_l_12d2:
	/* 0x12d2: lea    r14d,[r10+0x1] */
	X86_VM_RUN_STEP(X86_OP_LEA, X86_R14, X86_R10, X86_WIDTH_32, 0, 1ULL);
x86_l_12d6:
	/* 0x12d6: lea    r15,[rcx+0xa] */
	X86_VM_RUN_STEP(X86_OP_LEA, X86_R15, X86_RCX, X86_WIDTH_64, 0, 10ULL);
x86_l_12da:
	/* 0x12da: imul   r14,r15 */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_R14, X86_R15, X86_WIDTH_64, X86_ALU_IMUL, 0);
x86_l_12de:
	/* 0x12de: add    rdi,r14 */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_RDI, X86_R14, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_12e1:
	/* 0x12e1: shl    rbx,0x20 */
	X86_VM_RUN_STEP(X86_OP_ALU_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_12e5:
	/* 0x12e5: movzx  r9d,r9b */
	X86_VM_RUN_STEP(X86_OP_MOVZX_REG, X86_R9, X86_R9, X86_WIDTH_32, X86_WIDTH_8, 0);
x86_l_12e9:
	/* 0x12e9: shl    r9d,0x18 */
	X86_VM_RUN_STEP(X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 24ULL);
x86_l_12ed:
	/* 0x12ed: movzx  r11d,r11b */
	X86_VM_RUN_STEP(X86_OP_MOVZX_REG, X86_R11, X86_R11, X86_WIDTH_32, X86_WIDTH_8, 0);
x86_l_12f1:
	/* 0x12f1: shl    r11d,0x10 */
	X86_VM_RUN_STEP(X86_OP_ALU_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 16ULL);
x86_l_12f5:
	/* 0x12f5: shl    r8d,0x8 */
	X86_VM_RUN_STEP(X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 8ULL);
x86_l_12f9:
	/* 0x12f9: or     r8d,r11d */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_R8, X86_R11, X86_WIDTH_32, X86_ALU_OR, 0);
x86_l_12fc:
	/* 0x12fc: or     r8d,r9d */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_R8, X86_R9, X86_WIDTH_32, X86_ALU_OR, 0);
x86_l_12ff:
	/* 0x12ff: or     r8,rbx */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_R8, X86_RBX, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_1302:
	/* 0x1302: mov    ebx,r10d */
	X86_VM_RUN_STEP(X86_OP_MOV_REG, X86_RBX, X86_R10, X86_WIDTH_32, 0, 0);
x86_l_1305:
	/* 0x1305: or     rbx,r8 */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_RBX, X86_R8, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_1308:
	/* 0x1308: shl    rbx,cl */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 0);
x86_l_130b:
	/* 0x130b: xor    rbx,rdi */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_RBX, X86_RDI, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_130e:
	/* 0x130e: add    rax,0x10 */
	X86_VM_RUN_STEP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1312:
	/* 0x1312: inc    rcx */
	X86_VM_RUN_STEP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1315:
	/* 0x1315: cmp    rcx,0x9 */
	X86_VM_RUN_STEP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, 0, 9ULL);
x86_l_1319:
	/* 0x1319: jne    1150 <tracee_http_method_prefix_detect_xdp+0x50> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_1150;
x86_l_131f:
	/* 0x131f: mov    BYTE PTR [rdx],dil */
	X86_VM_RUN_STEP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RDI, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1322:
	/* 0x1322: mov    BYTE PTR [rdx+0x1],bh */
	X86_VM_RUN_STEP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RBX, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_REG_AUX_SRC_SHIFT(8)), 1ULL);
x86_l_1325:
	/* 0x1325: mov    eax,ebx */
	X86_VM_RUN_STEP(X86_OP_MOV_REG, X86_RAX, X86_RBX, X86_WIDTH_32, 0, 0);
x86_l_1327:
	/* 0x1327: shr    eax,0x10 */
	X86_VM_RUN_STEP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_132a:
	/* 0x132a: mov    BYTE PTR [rdx+0x2],al */
	X86_VM_RUN_STEP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_132d:
	/* 0x132d: mov    eax,ebx */
	X86_VM_RUN_STEP(X86_OP_MOV_REG, X86_RAX, X86_RBX, X86_WIDTH_32, 0, 0);
x86_l_132f:
	/* 0x132f: shr    eax,0x18 */
	X86_VM_RUN_STEP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHR, 24ULL);
x86_l_1332:
	/* 0x1332: mov    BYTE PTR [rdx+0x3],al */
	X86_VM_RUN_STEP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 3ULL);
x86_l_1335:
	/* 0x1335: mov    rax,rbx */
	X86_VM_RUN_STEP(X86_OP_MOV_REG, X86_RAX, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_1338:
	/* 0x1338: shr    rax,0x20 */
	X86_VM_RUN_STEP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_133c:
	/* 0x133c: mov    BYTE PTR [rdx+0x4],al */
	X86_VM_RUN_STEP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_133f:
	/* 0x133f: mov    rax,rbx */
	X86_VM_RUN_STEP(X86_OP_MOV_REG, X86_RAX, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_1342:
	/* 0x1342: shr    rax,0x28 */
	X86_VM_RUN_STEP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 40ULL);
x86_l_1346:
	/* 0x1346: mov    BYTE PTR [rdx+0x5],al */
	X86_VM_RUN_STEP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_1349:
	/* 0x1349: mov    rax,rbx */
	X86_VM_RUN_STEP(X86_OP_MOV_REG, X86_RAX, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_134c:
	/* 0x134c: shr    rax,0x30 */
	X86_VM_RUN_STEP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 48ULL);
x86_l_1350:
	/* 0x1350: mov    BYTE PTR [rdx+0x6],al */
	X86_VM_RUN_STEP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_1353:
	/* 0x1353: shr    rbx,0x38 */
	X86_VM_RUN_STEP(X86_OP_ALU_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 56ULL);
x86_l_1357:
	/* 0x1357: mov    BYTE PTR [rdx+0x7],bl */
	X86_VM_RUN_STEP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RBX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 7ULL);
x86_l_135a:
	/* 0x135a: mov    eax,0x2 */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_135f:
	/* 0x135f: pop    rbx */
	X86_VM_RUN_STEP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1360:
	/* 0x1360: pop    r14 */
	X86_VM_RUN_STEP(X86_OP_POP, X86_R14, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1362:
	/* 0x1362: pop    r15 */
	X86_VM_RUN_STEP(X86_OP_POP, X86_R15, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1364:
	/* 0x1364: ret */
	X86_VM_RET_RAX();
	return XDP_ABORTED;
}

X86_VM_LICENSE();
