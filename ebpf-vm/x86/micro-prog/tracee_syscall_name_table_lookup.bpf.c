#include "../x86_vm_bpf.h"

SEC("xdp")
int tracee_syscall_name_table_lookup_x86_vm_xdp(struct xdp_md *ctx)
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
	/* 0x110c: jbe    110f <tracee_syscall_name_table_lookup_xdp+0xf> */
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
	/* 0x1116: ja     110e <tracee_syscall_name_table_lookup_xdp+0xe> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_110e;
x86_l_1118:
	/* 0x1118: lea    rdi,[rdx+0x10c] */
	X86_VM_RUN_STEP(X86_OP_LEA, X86_RDI, X86_RDX, X86_WIDTH_64, 0, 268ULL);
x86_l_111f:
	/* 0x111f: cmp    rdi,rcx */
	X86_VM_RUN_STEP(X86_OP_CMP_REG, X86_RDI, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_1122:
	/* 0x1122: ja     110e <tracee_syscall_name_table_lookup_xdp+0xe> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_110e;
x86_l_1124:
	/* 0x1124: cmp    DWORD PTR [rsi],0x40 */
	X86_VM_RUN_STEP(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1127:
	/* 0x1127: jne    110e <tracee_syscall_name_table_lookup_xdp+0xe> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_110e;
x86_l_1129:
	/* 0x1129: push   rbp */
	X86_VM_RUN_STEP(X86_OP_PUSH, X86_REG_NONE, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_112a:
	/* 0x112a: push   r15 */
	X86_VM_RUN_STEP(X86_OP_PUSH, X86_REG_NONE, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_112c:
	/* 0x112c: push   r14 */
	X86_VM_RUN_STEP(X86_OP_PUSH, X86_REG_NONE, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_112e:
	/* 0x112e: push   r13 */
	X86_VM_RUN_STEP(X86_OP_PUSH, X86_REG_NONE, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_1130:
	/* 0x1130: push   r12 */
	X86_VM_RUN_STEP(X86_OP_PUSH, X86_REG_NONE, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_1132:
	/* 0x1132: push   rbx */
	X86_VM_RUN_STEP(X86_OP_PUSH, X86_REG_NONE, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_1133:
	/* 0x1133: movabs r14,0x6a09e667f3bcc909 */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, 0, 7640891576956012809ULL);
x86_l_113d:
	/* 0x113d: movabs rsi,0x65736f6c63 */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, 0, 435728378979ULL);
x86_l_1147:
	/* 0x1147: xor    r8d,r8d */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_114a:
	/* 0x114a: lea    r10,[rip+0xeaf] */
	X86_VM_RUN_STEP(X86_OP_LEA, X86_R10, X86_REG_NONE, X86_WIDTH_64, 0, 3759ULL);
x86_l_1151:
	/* 0x1151: lea    r11,[rsi+0xfa0614] */
	X86_VM_RUN_STEP(X86_OP_LEA, X86_R11, X86_RSI, X86_WIDTH_64, 0, 16385556ULL);
x86_l_1158:
	/* 0x1158: lea    r15,[rip+0x111d] */
	X86_VM_RUN_STEP(X86_OP_LEA, X86_R15, X86_REG_NONE, X86_WIDTH_64, 0, 4381ULL);
x86_l_115f:
	/* 0x115f: movabs r13,0x74616b6e696c6e75 */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, 0, 8386102103099862645ULL);
x86_l_1169:
	/* 0x1169: movabs rbp,0x74613274617473 */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, 0, 32757966627239027ULL);
x86_l_1173:
	/* 0x1173: movabs r9,0x647466656e676973 */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_64, 0, 7238523086921230707ULL);
x86_l_117d:
	/* 0x117d: nop    DWORD PTR [rax] */
	X86_VM_RUN_STEP(X86_OP_NOP, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1180:
	/* 0x1180: movzx  edi,BYTE PTR [rdx+r8*4+0xc] */
	X86_VM_RUN_STEP(X86_OP_MOV_LOAD, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R8, 2, X86_WIDTH_8), 12ULL);
x86_l_1186:
	/* 0x1186: movzx  ecx,BYTE PTR [rdx+r8*4+0xd] */
	X86_VM_RUN_STEP(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R8, 2, X86_WIDTH_8), 13ULL);
x86_l_118c:
	/* 0x118c: shl    ecx,0x8 */
	X86_VM_RUN_STEP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 8ULL);
x86_l_118f:
	/* 0x118f: or     ecx,edi */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_RCX, X86_RDI, X86_WIDTH_32, X86_ALU_OR, 0);
x86_l_1191:
	/* 0x1191: movzx  eax,WORD PTR [rdx+r8*4+0xe] */
	X86_VM_RUN_STEP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R8, 2, X86_WIDTH_16), 14ULL);
x86_l_1197:
	/* 0x1197: shl    eax,0x10 */
	X86_VM_RUN_STEP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 16ULL);
x86_l_119a:
	/* 0x119a: or     eax,ecx */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR, 0);
x86_l_119c:
	/* 0x119c: cmp    eax,0xd8 */
	X86_VM_RUN_STEP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 216ULL);
x86_l_11a1:
	/* 0x11a1: jg     11c0 <tracee_syscall_name_table_lookup_xdp+0xc0> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_G))
		goto x86_l_11c0;
x86_l_11a3:
	/* 0x11a3: cmp    eax,0x9e */
	X86_VM_RUN_STEP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 158ULL);
x86_l_11a8:
	/* 0x11a8: ja     1218 <tracee_syscall_name_table_lookup_xdp+0x118> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_1218;
x86_l_11aa:
	/* 0x11aa: mov    ecx,eax */
	X86_VM_RUN_STEP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_11ac:
	/* 0x11ac: movsxd rcx,DWORD PTR [r10+rcx*4] */
	X86_VM_RUN_STEP(X86_OP_MOVSX_LOAD, X86_RCX, X86_R10, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_RCX, 2, X86_WIDTH_32), 0ULL);
x86_l_11b0:
	/* 0x11b0: add    rcx,r10 */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_RCX, X86_R10, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_11b3:
	/* 0x11b3: jmp    rcx */
	return XDP_ABORTED;
x86_l_11b5:
	/* 0x11b5: mov    ecx,0x72656164 */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 1919246692ULL);
x86_l_11ba:
	/* 0x11ba: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> */
	goto x86_l_1300;
x86_l_11bf:
	/* 0x11bf: nop */
	X86_VM_RUN_STEP(X86_OP_NOP, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_11c0:
	/* 0x11c0: cmp    eax,0x140 */
	X86_VM_RUN_STEP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 320ULL);
x86_l_11c5:
	/* 0x11c5: jg     11ea <tracee_syscall_name_table_lookup_xdp+0xea> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_G))
		goto x86_l_11ea;
x86_l_11c7:
	/* 0x11c7: lea    ecx,[rax-0x101] */
	X86_VM_RUN_STEP(X86_OP_LEA, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 18446744073709551359ULL);
x86_l_11cd:
	/* 0x11cd: cmp    ecx,0x22 */
	X86_VM_RUN_STEP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 34ULL);
x86_l_11d0:
	/* 0x11d0: ja     1202 <tracee_syscall_name_table_lookup_xdp+0x102> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_1202;
x86_l_11d2:
	/* 0x11d2: movsxd rcx,DWORD PTR [r15+rcx*4] */
	X86_VM_RUN_STEP(X86_OP_MOVSX_LOAD, X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_RCX, 2, X86_WIDTH_32), 0ULL);
x86_l_11d6:
	/* 0x11d6: add    rcx,r15 */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_11d9:
	/* 0x11d9: jmp    rcx */
	return XDP_ABORTED;
x86_l_11db:
	/* 0x11db: movabs rcx,0x74616e65706f */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, 0, 127961812791407ULL);
x86_l_11e5:
	/* 0x11e5: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> */
	goto x86_l_1300;
x86_l_11ea:
	/* 0x11ea: cmp    eax,0x141 */
	X86_VM_RUN_STEP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 321ULL);
x86_l_11ef:
	/* 0x11ef: je     1246 <tracee_syscall_name_table_lookup_xdp+0x146> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_E))
		goto x86_l_1246;
x86_l_11f1:
	/* 0x11f1: cmp    eax,0x14c */
	X86_VM_RUN_STEP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 332ULL);
x86_l_11f6:
	/* 0x11f6: jne    1250 <tracee_syscall_name_table_lookup_xdp+0x150> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_1250;
x86_l_11f8:
	/* 0x11f8: mov    ecx,0x78746173 */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 2020893043ULL);
x86_l_11fd:
	/* 0x11fd: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> */
	goto x86_l_1300;
x86_l_1202:
	/* 0x1202: cmp    eax,0xd9 */
	X86_VM_RUN_STEP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 217ULL);
x86_l_1207:
	/* 0x1207: jne    1250 <tracee_syscall_name_table_lookup_xdp+0x150> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_1250;
x86_l_1209:
	/* 0x1209: movabs rcx,0x646461746567 */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, 0, 110382294525287ULL);
x86_l_1213:
	/* 0x1213: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> */
	goto x86_l_1300;
x86_l_1218:
	/* 0x1218: cmp    eax,0xca */
	X86_VM_RUN_STEP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 202ULL);
x86_l_121d:
	/* 0x121d: jne    1250 <tracee_syscall_name_table_lookup_xdp+0x150> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_1250;
x86_l_121f:
	/* 0x121f: movabs rcx,0x786574756655 */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, 0, 132377140880981ULL);
x86_l_1229:
	/* 0x1229: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> */
	goto x86_l_1300;
x86_l_122e:
	/* 0x122e: mov    rcx,r13 */
	X86_VM_RUN_STEP(X86_OP_MOV_REG, X86_RCX, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_1231:
	/* 0x1231: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> */
	goto x86_l_1300;
x86_l_1236:
	/* 0x1236: mov    rcx,rbp */
	X86_VM_RUN_STEP(X86_OP_MOV_REG, X86_RCX, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_1239:
	/* 0x1239: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> */
	goto x86_l_1300;
x86_l_123e:
	/* 0x123e: mov    rcx,r9 */
	X86_VM_RUN_STEP(X86_OP_MOV_REG, X86_RCX, X86_R9, X86_WIDTH_64, 0, 0);
x86_l_1241:
	/* 0x1241: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> */
	goto x86_l_1300;
x86_l_1246:
	/* 0x1246: mov    ecx,0x706662 */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 7366242ULL);
x86_l_124b:
	/* 0x124b: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> */
	goto x86_l_1300;
x86_l_1250:
	/* 0x1250: mov    eax,eax */
	X86_VM_RUN_STEP(X86_OP_MOV_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_1252:
	/* 0x1252: movabs rcx,0x9e3779b185ebca87 */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, 0, 11400714785074694791ULL);
x86_l_125c:
	/* 0x125c: imul   rax,rcx */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_IMUL, 0);
x86_l_1260:
	/* 0x1260: xor    r14,rax */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1263:
	/* 0x1263: jmp    132f <tracee_syscall_name_table_lookup_xdp+0x22f> */
	goto x86_l_132f;
x86_l_1268:
	/* 0x1268: movabs rcx,0x657663657865 */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, 0, 111559148140645ULL);
x86_l_1272:
	/* 0x1272: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> */
	goto x86_l_1300;
x86_l_1277:
	/* 0x1277: movabs rcx,0x6469707467 */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, 0, 431265707111ULL);
x86_l_1281:
	/* 0x1281: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> */
	goto x86_l_1300;
x86_l_1283:
	/* 0x1283: mov    ecx,0x70616d6d */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 1885433197ULL);
x86_l_1288:
	/* 0x1288: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> */
	goto x86_l_1300;
x86_l_128a:
	/* 0x128a: movabs rcx,0x6b6e696c6e75 */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, 0, 118121959288437ULL);
x86_l_1294:
	/* 0x1294: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> */
	goto x86_l_1300;
x86_l_1296:
	/* 0x1296: movabs rcx,0x656e6f6c6355 */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, 0, 111524990182229ULL);
x86_l_12a0:
	/* 0x12a0: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> */
	goto x86_l_1300;
x86_l_12a2:
	/* 0x12a2: movabs rcx,0x347469617755 */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, 0, 57674588845909ULL);
x86_l_12ac:
	/* 0x12ac: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> */
	goto x86_l_1300;
x86_l_12ae:
	/* 0x12ae: mov    ecx,0x6e65706f */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 1852141679ULL);
x86_l_12b3:
	/* 0x12b3: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> */
	goto x86_l_1300;
x86_l_12b5:
	/* 0x12b5: mov    rcx,rsi */
	X86_VM_RUN_STEP(X86_OP_MOV_REG, X86_RCX, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_12b8:
	/* 0x12b8: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> */
	goto x86_l_1300;
x86_l_12ba:
	/* 0x12ba: mov    ecx,0x6b726f66 */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 1802661734ULL);
x86_l_12bf:
	/* 0x12bf: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> */
	goto x86_l_1300;
x86_l_12c1:
	/* 0x12c1: mov    ecx,0x74697865 */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 1953069157ULL);
x86_l_12c6:
	/* 0x12c6: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> */
	goto x86_l_1300;
x86_l_12c8:
	/* 0x12c8: mov    rcx,r11 */
	X86_VM_RUN_STEP(X86_OP_MOV_REG, X86_RCX, X86_R11, X86_WIDTH_64, 0, 0);
x86_l_12cb:
	/* 0x12cb: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> */
	goto x86_l_1300;
x86_l_12cd:
	/* 0x12cd: movabs rcx,0x6b6e696c55 */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, 0, 461413903445ULL);
x86_l_12d7:
	/* 0x12d7: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> */
	goto x86_l_1300;
x86_l_12d9:
	/* 0x12d9: mov    ecx,0x6b72626b */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 1802658411ULL);
x86_l_12de:
	/* 0x12de: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> */
	goto x86_l_1300;
x86_l_12e0:
	/* 0x12e0: mov    ecx,0x69646863 */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 1768188003ULL);
x86_l_12e5:
	/* 0x12e5: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> */
	goto x86_l_1300;
x86_l_12e7:
	/* 0x12e7: movabs rcx,0x6c74635f68637261 */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, 0, 7814980514819043937ULL);
x86_l_12f1:
	/* 0x12f1: data16 data16 data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0] */
	X86_VM_RUN_STEP(X86_OP_NOP, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1300:
	/* 0x1300: mov    ebx,eax */
	X86_VM_RUN_STEP(X86_OP_MOV_REG, X86_RBX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_1302:
	/* 0x1302: xor    rbx,rcx */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1305:
	/* 0x1305: mov    eax,r8d */
	X86_VM_RUN_STEP(X86_OP_MOV_REG, X86_RAX, X86_R8, X86_WIDTH_32, 0, 0);
x86_l_1308:
	/* 0x1308: and    eax,0x7 */
	X86_VM_RUN_STEP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_130b:
	/* 0x130b: lea    ecx,[rax+0x1] */
	X86_VM_RUN_STEP(X86_OP_LEA, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 1ULL);
x86_l_130e:
	/* 0x130e: mov    r12,rbx */
	X86_VM_RUN_STEP(X86_OP_MOV_REG, X86_R12, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_1311:
	/* 0x1311: shl    r12,cl */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 0);
x86_l_1314:
	/* 0x1314: mov    ecx,eax */
	X86_VM_RUN_STEP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_1316:
	/* 0x1316: not    cl */
	X86_VM_RUN_STEP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_ALU_NOT, 0);
x86_l_1318:
	/* 0x1318: shr    rbx,cl */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 0);
x86_l_131b:
	/* 0x131b: shl    eax,0x3 */
	X86_VM_RUN_STEP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_131e:
	/* 0x131e: mov    ecx,eax */
	X86_VM_RUN_STEP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_1320:
	/* 0x1320: shl    rdi,cl */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 0);
x86_l_1323:
	/* 0x1323: or     rbx,r12 */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_RBX, X86_R12, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_1326:
	/* 0x1326: add    rbx,r14 */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_RBX, X86_R14, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1329:
	/* 0x1329: xor    rdi,rbx */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_132c:
	/* 0x132c: mov    r14,rdi */
	X86_VM_RUN_STEP(X86_OP_MOV_REG, X86_R14, X86_RDI, X86_WIDTH_64, 0, 0);
x86_l_132f:
	/* 0x132f: inc    r8 */
	X86_VM_RUN_STEP(X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1332:
	/* 0x1332: cmp    r8,0x40 */
	X86_VM_RUN_STEP(X86_OP_CMP_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_64, 0, 64ULL);
x86_l_1336:
	/* 0x1336: jne    1180 <tracee_syscall_name_table_lookup_xdp+0x80> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_1180;
x86_l_133c:
	/* 0x133c: mov    QWORD PTR [rdx],r14 */
	X86_VM_RUN_STEP(X86_OP_MOV_STORE_REG, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_133f:
	/* 0x133f: mov    eax,0x2 */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_1344:
	/* 0x1344: pop    rbx */
	X86_VM_RUN_STEP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1345:
	/* 0x1345: pop    r12 */
	X86_VM_RUN_STEP(X86_OP_POP, X86_R12, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1347:
	/* 0x1347: pop    r13 */
	X86_VM_RUN_STEP(X86_OP_POP, X86_R13, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1349:
	/* 0x1349: pop    r14 */
	X86_VM_RUN_STEP(X86_OP_POP, X86_R14, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_134b:
	/* 0x134b: pop    r15 */
	X86_VM_RUN_STEP(X86_OP_POP, X86_R15, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_134d:
	/* 0x134d: pop    rbp */
	X86_VM_RUN_STEP(X86_OP_POP, X86_RBP, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_134e:
	/* 0x134e: ret */
	X86_VM_RET_RAX();
	return XDP_ABORTED;
}

X86_VM_LICENSE();
