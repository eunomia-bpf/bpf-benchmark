#define X86_VM_ENABLE_STACK 1
#include "../x86_vm_bpf.h"

static __noinline int x86_fn_local_call_pressure(struct x86_state *__x86_vm_state_ptr, void *__x86_vm_data, void *__x86_vm_data_end)
{
	struct x86_insn __x86_vm_insn = {};
	#define __x86_vm_state (*__x86_vm_state_ptr)
x86_l_1260:
	/* 0x1260: mov    eax,edx */
	X86_VM_RUN_STEP_SUB(X86_OP_MOV_REG, X86_RAX, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_1262:
	/* 0x1262: mov    r8,QWORD PTR [rax+rsi*1+0x8] */
	X86_VM_RUN_STEP_SUB(X86_OP_MOV_LOAD, X86_R8, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 8ULL);
x86_l_1267:
	/* 0x1267: mov    rdx,QWORD PTR [rax+rsi*1+0x10] */
	X86_VM_RUN_STEP_SUB(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 16ULL);
x86_l_126c:
	/* 0x126c: xor    rdi,r8 */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_REG, X86_RDI, X86_R8, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_126f:
	/* 0x126f: mov    eax,ecx */
	X86_VM_RUN_STEP_SUB(X86_OP_MOV_REG, X86_RAX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_1271:
	/* 0x1271: shl    rax,0x11 */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 17ULL);
x86_l_1275:
	/* 0x1275: add    rax,rdx */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_REG, X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1278:
	/* 0x1278: lea    rcx,[rdi*8+0x0] */
	X86_VM_RUN_STEP_SUB(X86_OP_LEA, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 3), 0ULL);
x86_l_1280:
	/* 0x1280: shr    rdx,0x2 */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 2ULL);
x86_l_1284:
	/* 0x1284: xor    r8,rax */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_REG, X86_R8, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1287:
	/* 0x1287: rol    r8,0x5 */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 5ULL);
x86_l_128b:
	/* 0x128b: xor    rdx,rcx */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_REG, X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_128e:
	/* 0x128e: lea    rcx,[rdx+rdi*1] */
	X86_VM_RUN_STEP_SUB(X86_OP_LEA, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_1292:
	/* 0x1292: rol    rcx,0xb */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 11ULL);
x86_l_1296:
	/* 0x1296: add    rcx,r8 */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_REG, X86_RCX, X86_R8, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1299:
	/* 0x1299: xor    rdi,rax */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_REG, X86_RDI, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_129c:
	/* 0x129c: shr    rax,0x7 */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 7ULL);
x86_l_12a0:
	/* 0x12a0: xor    rax,rcx */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_12a3:
	/* 0x12a3: add    rax,rdx */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_REG, X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_12a6:
	/* 0x12a6: xor    rax,rdi */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_REG, X86_RAX, X86_RDI, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_12a9:
	/* 0x12a9: ret */
	return X86_INTERP_CONTINUE;
	#undef __x86_vm_state
	return X86_INTERP_TRAP;
}

static __noinline int x86_fn_local_call_linear(struct x86_state *__x86_vm_state_ptr, void *__x86_vm_data, void *__x86_vm_data_end)
{
	struct x86_insn __x86_vm_insn = {};
	#define __x86_vm_state (*__x86_vm_state_ptr)
x86_l_1210:
	/* 0x1210: mov    r8d,ecx */
	X86_VM_RUN_STEP_SUB(X86_OP_MOV_REG, X86_R8, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_1213:
	/* 0x1213: mov    ecx,edx */
	X86_VM_RUN_STEP_SUB(X86_OP_MOV_REG, X86_RCX, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_1215:
	/* 0x1215: mov    rax,QWORD PTR [rcx+rsi*1+0x8] */
	X86_VM_RUN_STEP_SUB(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 8ULL);
x86_l_121a:
	/* 0x121a: lea    r9,[rax+rax*2] */
	X86_VM_RUN_STEP_SUB(X86_OP_LEA, X86_R9, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_121e:
	/* 0x121e: mov    edx,r8d */
	X86_VM_RUN_STEP_SUB(X86_OP_MOV_REG, X86_RDX, X86_R8, X86_WIDTH_32, 0, 0);
x86_l_1221:
	/* 0x1221: add    rdi,rdx */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_REG, X86_RDI, X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1224:
	/* 0x1224: add    r9,rdi */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_REG, X86_R9, X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1227:
	/* 0x1227: add    r9,QWORD PTR [rcx+rsi*1+0x10] */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_MEM, X86_R9, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_122c:
	/* 0x122c: shl    rdx,0xb */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 11ULL);
x86_l_1230:
	/* 0x1230: add    rdx,r9 */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_REG, X86_RDX, X86_R9, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1233:
	/* 0x1233: and    r8d,0x7 */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_1237:
	/* 0x1237: lea    ecx,[r8+0x1] */
	X86_VM_RUN_STEP_SUB(X86_OP_LEA, X86_RCX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_123b:
	/* 0x123b: mov    rsi,rdx */
	X86_VM_RUN_STEP_SUB(X86_OP_MOV_REG, X86_RSI, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_123e:
	/* 0x123e: shl    rsi,cl */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_REG, X86_RSI, X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 0);
x86_l_1241:
	/* 0x1241: not    r8b */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_8, X86_ALU_NOT, 0);
x86_l_1244:
	/* 0x1244: mov    ecx,r8d */
	X86_VM_RUN_STEP_SUB(X86_OP_MOV_REG, X86_RCX, X86_R8, X86_WIDTH_32, 0, 0);
x86_l_1247:
	/* 0x1247: shr    rdx,cl */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_REG, X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 0);
x86_l_124a:
	/* 0x124a: or     rdx,rsi */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_REG, X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_124d:
	/* 0x124d: xor    rdx,r9 */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_REG, X86_RDX, X86_R9, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1250:
	/* 0x1250: shr    rax,0x3 */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 3ULL);
x86_l_1254:
	/* 0x1254: add    rax,rdx */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_REG, X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1257:
	/* 0x1257: ret */
	return X86_INTERP_CONTINUE;
	#undef __x86_vm_state
	return X86_INTERP_TRAP;
}

static __noinline int x86_fn_local_call_crossload(struct x86_state *__x86_vm_state_ptr, void *__x86_vm_data, void *__x86_vm_data_end)
{
	struct x86_insn __x86_vm_insn = {};
	#define __x86_vm_state (*__x86_vm_state_ptr)
x86_l_12b0:
	/* 0x12b0: push   r14 */
	X86_VM_RUN_STEP_SUB(X86_OP_PUSH, X86_REG_NONE, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_12b2:
	/* 0x12b2: push   rbx */
	X86_VM_RUN_STEP_SUB(X86_OP_PUSH, X86_REG_NONE, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_12b3:
	/* 0x12b3: mov    r8d,ecx */
	X86_VM_RUN_STEP_SUB(X86_OP_MOV_REG, X86_R8, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_12b6:
	/* 0x12b6: mov    eax,edx */
	X86_VM_RUN_STEP_SUB(X86_OP_MOV_REG, X86_RAX, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_12b8:
	/* 0x12b8: movzx  edx,BYTE PTR [rsi+rax*1] */
	X86_VM_RUN_STEP_SUB(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_12bc:
	/* 0x12bc: lea    rcx,[rax+0x4] */
	X86_VM_RUN_STEP_SUB(X86_OP_LEA, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_12c0:
	/* 0x12c0: movzx  r9d,BYTE PTR [rsi+rax*1+0x4] */
	X86_VM_RUN_STEP_SUB(X86_OP_MOV_LOAD, X86_R9, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 4ULL);
x86_l_12c6:
	/* 0x12c6: movsxd r11,ecx */
	X86_VM_RUN_STEP_SUB(X86_OP_MOVSX_REG, X86_R11, X86_RCX, X86_WIDTH_64, X86_WIDTH_32, 0);
x86_l_12c9:
	/* 0x12c9: movzx  r10d,BYTE PTR [rsi+r11*1+0x1] */
	X86_VM_RUN_STEP_SUB(X86_OP_MOV_LOAD, X86_R10, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R11, 0, X86_WIDTH_8), 1ULL);
x86_l_12cf:
	/* 0x12cf: add    rdi,QWORD PTR [rsi+rax*1+0x8] */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_MEM, X86_RDI, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_12d4:
	/* 0x12d4: mov    rax,QWORD PTR [rsi+rax*1+0x10] */
	X86_VM_RUN_STEP_SUB(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 16ULL);
x86_l_12d9:
	/* 0x12d9: xor    rax,rdi */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_REG, X86_RAX, X86_RDI, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_12dc:
	/* 0x12dc: and    dl,0x7 */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_ALU_AND, 7ULL);
x86_l_12df:
	/* 0x12df: lea    ecx,[rdx+0x1] */
	X86_VM_RUN_STEP_SUB(X86_OP_LEA, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_12e2:
	/* 0x12e2: mov    rbx,rax */
	X86_VM_RUN_STEP_SUB(X86_OP_MOV_REG, X86_RBX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_12e5:
	/* 0x12e5: shl    rbx,cl */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 0);
x86_l_12e8:
	/* 0x12e8: movzx  r14d,BYTE PTR [rsi+r11*1+0x2] */
	X86_VM_RUN_STEP_SUB(X86_OP_MOV_LOAD, X86_R14, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R11, 0, X86_WIDTH_8), 2ULL);
x86_l_12ee:
	/* 0x12ee: movzx  esi,BYTE PTR [rsi+r11*1+0x3] */
	X86_VM_RUN_STEP_SUB(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R11, 0, X86_WIDTH_8), 3ULL);
x86_l_12f4:
	/* 0x12f4: mov    ecx,edx */
	X86_VM_RUN_STEP_SUB(X86_OP_MOV_REG, X86_RCX, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_12f6:
	/* 0x12f6: not    cl */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_ALU_NOT, 0);
x86_l_12f8:
	/* 0x12f8: shr    rax,cl */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 0);
x86_l_12fb:
	/* 0x12fb: or     rax,rbx */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_REG, X86_RAX, X86_RBX, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_12fe:
	/* 0x12fe: shl    rsi,0x21 */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 33ULL);
x86_l_1302:
	/* 0x1302: shl    r14,0x19 */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 25ULL);
x86_l_1306:
	/* 0x1306: shl    r10d,0x11 */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 17ULL);
x86_l_130a:
	/* 0x130a: shl    r9d,0x9 */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 9ULL);
x86_l_130e:
	/* 0x130e: or     r9d,r10d */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_REG, X86_R9, X86_R10, X86_WIDTH_32, X86_ALU_OR, 0);
x86_l_1311:
	/* 0x1311: or     r9,r14 */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_REG, X86_R9, X86_R14, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_1314:
	/* 0x1314: or     r9,rsi */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_REG, X86_R9, X86_RSI, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_1317:
	/* 0x1317: xor    r9,rdi */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_REG, X86_R9, X86_RDI, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_131a:
	/* 0x131a: xor    r9,rax */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_REG, X86_R9, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_131d:
	/* 0x131d: mov    esi,r8d */
	X86_VM_RUN_STEP_SUB(X86_OP_MOV_REG, X86_RSI, X86_R8, X86_WIDTH_32, 0, 0);
x86_l_1320:
	/* 0x1320: mov    ecx,edx */
	X86_VM_RUN_STEP_SUB(X86_OP_MOV_REG, X86_RCX, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_1322:
	/* 0x1322: shl    rsi,cl */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_REG, X86_RSI, X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 0);
x86_l_1325:
	/* 0x1325: add    rsi,r9 */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_REG, X86_RSI, X86_R9, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1328:
	/* 0x1328: shr    rax,0x5 */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 5ULL);
x86_l_132c:
	/* 0x132c: xor    rax,rsi */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_REG, X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_132f:
	/* 0x132f: add    rax,rdi */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_REG, X86_RAX, X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1332:
	/* 0x1332: pop    rbx */
	X86_VM_RUN_STEP_SUB(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1333:
	/* 0x1333: pop    r14 */
	X86_VM_RUN_STEP_SUB(X86_OP_POP, X86_R14, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1335:
	/* 0x1335: ret */
	return X86_INTERP_CONTINUE;
	#undef __x86_vm_state
	return X86_INTERP_TRAP;
}

static __noinline int x86_fn_local_call_bytes(struct x86_state *__x86_vm_state_ptr, void *__x86_vm_data, void *__x86_vm_data_end)
{
	struct x86_insn __x86_vm_insn = {};
	#define __x86_vm_state (*__x86_vm_state_ptr)
x86_l_1340:
	/* 0x1340: mov    eax,ecx */
	X86_VM_RUN_STEP_SUB(X86_OP_MOV_REG, X86_RAX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_1342:
	/* 0x1342: mov    ecx,edx */
	X86_VM_RUN_STEP_SUB(X86_OP_MOV_REG, X86_RCX, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_1344:
	/* 0x1344: movzx  edx,BYTE PTR [rsi+rcx*1] */
	X86_VM_RUN_STEP_SUB(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1348:
	/* 0x1348: movabs r8,0x94d049bb133111eb */
	X86_VM_RUN_STEP_SUB(X86_OP_MOV_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_64, 0, 10723151780598845931ULL);
x86_l_1352:
	/* 0x1352: xor    r8,rdi */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_REG, X86_R8, X86_RDI, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1355:
	/* 0x1355: xor    r8,rdx */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_REG, X86_R8, X86_RDX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1358:
	/* 0x1358: add    r8,rax */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_REG, X86_R8, X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_135b:
	/* 0x135b: rol    r8,1 */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 1ULL);
x86_l_135e:
	/* 0x135e: movzx  edx,BYTE PTR [rsi+rcx*1+0x1] */
	X86_VM_RUN_STEP_SUB(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 1ULL);
x86_l_1363:
	/* 0x1363: shl    edx,0x8 */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 8ULL);
x86_l_1366:
	/* 0x1366: xor    rdx,r8 */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_REG, X86_RDX, X86_R8, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1369:
	/* 0x1369: add    rdx,rax */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_REG, X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_136c:
	/* 0x136c: inc    rdx */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_136f:
	/* 0x136f: rol    rdx,0x2 */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 2ULL);
x86_l_1373:
	/* 0x1373: movzx  edi,BYTE PTR [rsi+rcx*1+0x2] */
	X86_VM_RUN_STEP_SUB(X86_OP_MOV_LOAD, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 2ULL);
x86_l_1378:
	/* 0x1378: shl    edi,0x10 */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 16ULL);
x86_l_137b:
	/* 0x137b: xor    rdi,rdx */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_REG, X86_RDI, X86_RDX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_137e:
	/* 0x137e: lea    rdx,[rax+rdi*1] */
	X86_VM_RUN_STEP_SUB(X86_OP_LEA, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_1382:
	/* 0x1382: add    rdx,0x2 */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_1386:
	/* 0x1386: rol    rdx,0x3 */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 3ULL);
x86_l_138a:
	/* 0x138a: movzx  edi,BYTE PTR [rsi+rcx*1+0x3] */
	X86_VM_RUN_STEP_SUB(X86_OP_MOV_LOAD, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 3ULL);
x86_l_138f:
	/* 0x138f: shl    edi,0x18 */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 24ULL);
x86_l_1392:
	/* 0x1392: xor    rdi,rdx */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_REG, X86_RDI, X86_RDX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1395:
	/* 0x1395: lea    rdx,[rax+rdi*1] */
	X86_VM_RUN_STEP_SUB(X86_OP_LEA, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_1399:
	/* 0x1399: add    rdx,0x3 */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 3ULL);
x86_l_139d:
	/* 0x139d: rol    rdx,0x4 */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 4ULL);
x86_l_13a1:
	/* 0x13a1: movzx  edi,BYTE PTR [rsi+rcx*1+0x4] */
	X86_VM_RUN_STEP_SUB(X86_OP_MOV_LOAD, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 4ULL);
x86_l_13a6:
	/* 0x13a6: shl    rdi,0x20 */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_13aa:
	/* 0x13aa: xor    rdi,rdx */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_REG, X86_RDI, X86_RDX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_13ad:
	/* 0x13ad: lea    rdx,[rax+rdi*1] */
	X86_VM_RUN_STEP_SUB(X86_OP_LEA, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_13b1:
	/* 0x13b1: add    rdx,0x4 */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_13b5:
	/* 0x13b5: rol    rdx,0x5 */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 5ULL);
x86_l_13b9:
	/* 0x13b9: movzx  edi,BYTE PTR [rsi+rcx*1+0x5] */
	X86_VM_RUN_STEP_SUB(X86_OP_MOV_LOAD, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 5ULL);
x86_l_13be:
	/* 0x13be: shl    rdi,0x28 */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 40ULL);
x86_l_13c2:
	/* 0x13c2: xor    rdi,rdx */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_REG, X86_RDI, X86_RDX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_13c5:
	/* 0x13c5: lea    rdx,[rax+rdi*1] */
	X86_VM_RUN_STEP_SUB(X86_OP_LEA, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_13c9:
	/* 0x13c9: add    rdx,0x5 */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 5ULL);
x86_l_13cd:
	/* 0x13cd: rol    rdx,0x6 */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 6ULL);
x86_l_13d1:
	/* 0x13d1: movzx  edi,BYTE PTR [rsi+rcx*1+0x6] */
	X86_VM_RUN_STEP_SUB(X86_OP_MOV_LOAD, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 6ULL);
x86_l_13d6:
	/* 0x13d6: shl    rdi,0x30 */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 48ULL);
x86_l_13da:
	/* 0x13da: xor    rdi,rdx */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_REG, X86_RDI, X86_RDX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_13dd:
	/* 0x13dd: lea    rdx,[rax+rdi*1] */
	X86_VM_RUN_STEP_SUB(X86_OP_LEA, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_13e1:
	/* 0x13e1: add    rdx,0x6 */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 6ULL);
x86_l_13e5:
	/* 0x13e5: rol    rdx,0x7 */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 7ULL);
x86_l_13e9:
	/* 0x13e9: movzx  edi,BYTE PTR [rsi+rcx*1+0x7] */
	X86_VM_RUN_STEP_SUB(X86_OP_MOV_LOAD, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 7ULL);
x86_l_13ee:
	/* 0x13ee: shl    rdi,0x38 */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 56ULL);
x86_l_13f2:
	/* 0x13f2: xor    rdi,rdx */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_REG, X86_RDI, X86_RDX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_13f5:
	/* 0x13f5: add    rax,rdi */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_REG, X86_RAX, X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_13f8:
	/* 0x13f8: add    rax,0x7 */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 7ULL);
x86_l_13fc:
	/* 0x13fc: rol    rax,0x8 */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 8ULL);
x86_l_1400:
	/* 0x1400: add    rax,QWORD PTR [rsi+rcx*1+0x8] */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_MEM, X86_RAX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1405:
	/* 0x1405: xor    rax,QWORD PTR [rsi+rcx*1+0x10] */
	X86_VM_RUN_STEP_SUB(X86_OP_ALU_MEM, X86_RAX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 16ULL);
x86_l_140a:
	/* 0x140a: ret */
	return X86_INTERP_CONTINUE;
	#undef __x86_vm_state
	return X86_INTERP_TRAP;
}

SEC("xdp")
int bpf_local_call_fanout_dispatch_x86_vm_xdp(struct xdp_md *ctx)
{
	X86_VM_DECLARE_XDP(ctx);
	__u64 __x86_call_ret0 = 0;
	__u64 __x86_call_ret1 = 0;
	__u32 __x86_call_depth = 0;
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
	if (__x86_call_depth == 0)
		X86_VM_RET_RAX();
	if (__x86_call_depth == 1) {
		__x86_call_depth = 0;
		if (__x86_call_ret0 == 0x117b)
			goto x86_l_117b;
		if (__x86_call_ret0 == 0x11d1)
			goto x86_l_11d1;
		if (__x86_call_ret0 == 0x11eb)
			goto x86_l_11eb;
		if (__x86_call_ret0 == 0x11fb)
			goto x86_l_11fb;
		return XDP_ABORTED;
	}
	if (__x86_call_depth == 2) {
		__x86_call_depth = 1;
		if (__x86_call_ret1 == 0x117b)
			goto x86_l_117b;
		if (__x86_call_ret1 == 0x11d1)
			goto x86_l_11d1;
		if (__x86_call_ret1 == 0x11eb)
			goto x86_l_11eb;
		if (__x86_call_ret1 == 0x11fb)
			goto x86_l_11fb;
		return XDP_ABORTED;
	}
	return XDP_ABORTED;
x86_l_1128:
	/* 0x1128: lea    rdx,[r14+0x8] */
	X86_VM_RUN_STEP(X86_OP_LEA, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
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
	X86_VM_RUN_STEP(X86_OP_LEA, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 400ULL);
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
	if (x86_fn_local_call_pressure(&__x86_vm_state, __x86_vm_data, __x86_vm_data_end) < 0)
		return XDP_ABORTED;
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
	X86_VM_RUN_STEP(X86_OP_LEA, X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551601ULL);
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
	if (x86_fn_local_call_linear(&__x86_vm_state, __x86_vm_data, __x86_vm_data_end) < 0)
		return XDP_ABORTED;
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
	if (x86_fn_local_call_crossload(&__x86_vm_state, __x86_vm_data, __x86_vm_data_end) < 0)
		return XDP_ABORTED;
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
	if (x86_fn_local_call_bytes(&__x86_vm_state, __x86_vm_data, __x86_vm_data_end) < 0)
		return XDP_ABORTED;
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
