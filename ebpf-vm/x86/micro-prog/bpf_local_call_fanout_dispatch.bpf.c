#define X86_VM_ENABLE_STACK 1
#include "../x86_vm_bpf.h"

static __noinline int x86_fn_local_call_pressure(struct x86_state *__x86_vm_state_ptr, void *__x86_vm_data, void *__x86_vm_data_end)
{
	#define __x86_vm_state (*__x86_vm_state_ptr)
	struct x86_insn __x86_vm_insn = {};
	__u64 __save_rbx = __x86_vm_state.rbx;
	void *__save_p_rbx = __x86_vm_state.p_rbx;
	__u8 __save_tag_rbx = __x86_vm_state.tag_rbx;
	__u64 __save_r12 = __x86_vm_state.r12;
	void *__save_p_r12 = __x86_vm_state.p_r12;
	__u8 __save_tag_r12 = __x86_vm_state.tag_r12;
	__u64 __save_r13 = __x86_vm_state.r13;
	void *__save_p_r13 = __x86_vm_state.p_r13;
	__u8 __save_tag_r13 = __x86_vm_state.tag_r13;
	__u64 __save_r14 = __x86_vm_state.r14;
	void *__save_p_r14 = __x86_vm_state.p_r14;
	__u8 __save_tag_r14 = __x86_vm_state.tag_r14;
	__u64 __save_r15 = __x86_vm_state.r15;
	void *__save_p_r15 = __x86_vm_state.p_r15;
	__u8 __save_tag_r15 = __x86_vm_state.tag_r15;
	#define X86_VM_SUB_RETURN() do { \
		__x86_vm_state.rbx = __save_rbx; \
		__x86_vm_state.r12 = __save_r12; \
		__x86_vm_state.r13 = __save_r13; \
		__x86_vm_state.r14 = __save_r14; \
		__x86_vm_state.r15 = __save_r15; \
		__x86_vm_state.p_rbx = __save_p_rbx; \
		__x86_vm_state.p_r12 = __save_p_r12; \
		__x86_vm_state.p_r13 = __save_p_r13; \
		__x86_vm_state.p_r14 = __save_p_r14; \
		__x86_vm_state.p_r15 = __save_p_r15; \
		__x86_vm_state.tag_rbx = __save_tag_rbx; \
		__x86_vm_state.tag_r12 = __save_tag_r12; \
		__x86_vm_state.tag_r13 = __save_tag_r13; \
		__x86_vm_state.tag_r14 = __save_tag_r14; \
		__x86_vm_state.tag_r15 = __save_tag_r15; \
		return X86_INTERP_CONTINUE; \
	} while (0)
	/* 0x1280: push   rbp */
	/* generated-C ABI: callee-save frame traffic handled by wrapper */
	/* 0x1281: mov    rbp,rsp */
	/* generated-C ABI: callee-save frame traffic handled by wrapper */
x86_l_1284:
	/* 0x1284: mov    eax,edx */
	X86_VM_RUN_OP_SUB(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RAX, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_1286:
	/* 0x1286: mov    r8,QWORD PTR [rax+rsi*1+0x8] */
	X86_VM_RUN_OP_SUB(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R8, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 8ULL);
x86_l_128b:
	/* 0x128b: mov    rdx,QWORD PTR [rax+rsi*1+0x10] */
	X86_VM_RUN_OP_SUB(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 16ULL);
x86_l_1290:
	/* 0x1290: xor    rdi,r8 */
	X86_VM_RUN_OP_SUB(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_R8, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1293:
	/* 0x1293: mov    eax,ecx */
	X86_VM_RUN_OP_SUB(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RAX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_1295:
	/* 0x1295: shl    rax,0x11 */
	X86_VM_RUN_OP_SUB(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 17ULL);
x86_l_1299:
	/* 0x1299: add    rax,rdx */
	X86_VM_RUN_OP_SUB(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_129c:
	/* 0x129c: lea    rcx,[rdi*8+0x0] */
	X86_VM_RUN_OP_SUB(x86_exec_lea, X86_OP_LEA, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 3), 0ULL);
x86_l_12a4:
	/* 0x12a4: shr    rdx,0x2 */
	X86_VM_RUN_OP_SUB(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 2ULL);
x86_l_12a8:
	/* 0x12a8: xor    r8,rax */
	X86_VM_RUN_OP_SUB(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R8, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_12ab:
	/* 0x12ab: rol    r8,0x5 */
	X86_VM_RUN_OP_SUB(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 5ULL);
x86_l_12af:
	/* 0x12af: xor    rdx,rcx */
	X86_VM_RUN_OP_SUB(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_12b2:
	/* 0x12b2: lea    rcx,[rdx+rdi*1] */
	X86_VM_RUN_OP_SUB(x86_exec_lea, X86_OP_LEA, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_12b6:
	/* 0x12b6: rol    rcx,0xb */
	X86_VM_RUN_OP_SUB(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 11ULL);
x86_l_12ba:
	/* 0x12ba: add    rcx,r8 */
	X86_VM_RUN_OP_SUB(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RCX, X86_R8, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_12bd:
	/* 0x12bd: xor    rdi,rax */
	X86_VM_RUN_OP_SUB(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_12c0:
	/* 0x12c0: shr    rax,0x7 */
	X86_VM_RUN_OP_SUB(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 7ULL);
x86_l_12c4:
	/* 0x12c4: xor    rax,rcx */
	X86_VM_RUN_OP_SUB(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_12c7:
	/* 0x12c7: add    rax,rdx */
	X86_VM_RUN_OP_SUB(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_12ca:
	/* 0x12ca: xor    rax,rdi */
	X86_VM_RUN_OP_SUB(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RDI, X86_WIDTH_64, X86_ALU_XOR, 0);
	/* 0x12cd: pop    rbp */
	/* generated-C ABI: callee-save frame traffic handled by wrapper */
x86_l_12ce:
	/* 0x12ce: ret */
	X86_VM_SUB_RETURN();
	#undef X86_VM_SUB_RETURN
	#undef __x86_vm_state
	return X86_INTERP_TRAP;
}

static __noinline int x86_fn_local_call_linear(struct x86_state *__x86_vm_state_ptr, void *__x86_vm_data, void *__x86_vm_data_end)
{
	#define __x86_vm_state (*__x86_vm_state_ptr)
	struct x86_insn __x86_vm_insn = {};
	__u64 __save_rbx = __x86_vm_state.rbx;
	void *__save_p_rbx = __x86_vm_state.p_rbx;
	__u8 __save_tag_rbx = __x86_vm_state.tag_rbx;
	__u64 __save_r12 = __x86_vm_state.r12;
	void *__save_p_r12 = __x86_vm_state.p_r12;
	__u8 __save_tag_r12 = __x86_vm_state.tag_r12;
	__u64 __save_r13 = __x86_vm_state.r13;
	void *__save_p_r13 = __x86_vm_state.p_r13;
	__u8 __save_tag_r13 = __x86_vm_state.tag_r13;
	__u64 __save_r14 = __x86_vm_state.r14;
	void *__save_p_r14 = __x86_vm_state.p_r14;
	__u8 __save_tag_r14 = __x86_vm_state.tag_r14;
	__u64 __save_r15 = __x86_vm_state.r15;
	void *__save_p_r15 = __x86_vm_state.p_r15;
	__u8 __save_tag_r15 = __x86_vm_state.tag_r15;
	#define X86_VM_SUB_RETURN() do { \
		__x86_vm_state.rbx = __save_rbx; \
		__x86_vm_state.r12 = __save_r12; \
		__x86_vm_state.r13 = __save_r13; \
		__x86_vm_state.r14 = __save_r14; \
		__x86_vm_state.r15 = __save_r15; \
		__x86_vm_state.p_rbx = __save_p_rbx; \
		__x86_vm_state.p_r12 = __save_p_r12; \
		__x86_vm_state.p_r13 = __save_p_r13; \
		__x86_vm_state.p_r14 = __save_p_r14; \
		__x86_vm_state.p_r15 = __save_p_r15; \
		__x86_vm_state.tag_rbx = __save_tag_rbx; \
		__x86_vm_state.tag_r12 = __save_tag_r12; \
		__x86_vm_state.tag_r13 = __save_tag_r13; \
		__x86_vm_state.tag_r14 = __save_tag_r14; \
		__x86_vm_state.tag_r15 = __save_tag_r15; \
		return X86_INTERP_CONTINUE; \
	} while (0)
	/* 0x1230: push   rbp */
	/* generated-C ABI: callee-save frame traffic handled by wrapper */
	/* 0x1231: mov    rbp,rsp */
	/* generated-C ABI: callee-save frame traffic handled by wrapper */
x86_l_1234:
	/* 0x1234: mov    r8d,ecx */
	X86_VM_RUN_OP_SUB(x86_exec_mov_reg, X86_OP_MOV_REG, X86_R8, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_1237:
	/* 0x1237: mov    ecx,edx */
	X86_VM_RUN_OP_SUB(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RCX, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_1239:
	/* 0x1239: mov    rax,QWORD PTR [rcx+rsi*1+0x8] */
	X86_VM_RUN_OP_SUB(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 8ULL);
x86_l_123e:
	/* 0x123e: lea    r9,[rax+rax*2] */
	X86_VM_RUN_OP_SUB(x86_exec_lea, X86_OP_LEA, X86_R9, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_1242:
	/* 0x1242: mov    edx,r8d */
	X86_VM_RUN_OP_SUB(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RDX, X86_R8, X86_WIDTH_32, 0, 0);
x86_l_1245:
	/* 0x1245: add    rdi,rdx */
	X86_VM_RUN_OP_SUB(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1248:
	/* 0x1248: add    r9,rdi */
	X86_VM_RUN_OP_SUB(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_124b:
	/* 0x124b: add    r9,QWORD PTR [rcx+rsi*1+0x10] */
	X86_VM_RUN_OP_SUB(x86_exec_alu_mem, X86_OP_ALU_MEM, X86_R9, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_1250:
	/* 0x1250: shl    rdx,0xb */
	X86_VM_RUN_OP_SUB(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 11ULL);
x86_l_1254:
	/* 0x1254: add    rdx,r9 */
	X86_VM_RUN_OP_SUB(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_R9, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1257:
	/* 0x1257: and    r8d,0x7 */
	X86_VM_RUN_OP_SUB(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_125b:
	/* 0x125b: lea    ecx,[r8+0x1] */
	X86_VM_RUN_OP_SUB(x86_exec_lea, X86_OP_LEA, X86_RCX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_125f:
	/* 0x125f: mov    rsi,rdx */
	X86_VM_RUN_OP_SUB(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RSI, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_1262:
	/* 0x1262: shl    rsi,cl */
	X86_VM_RUN_OP_SUB(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RSI, X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 0);
x86_l_1265:
	/* 0x1265: not    r8b */
	X86_VM_RUN_OP_SUB(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_8, X86_ALU_NOT, 0);
x86_l_1268:
	/* 0x1268: mov    ecx,r8d */
	X86_VM_RUN_OP_SUB(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RCX, X86_R8, X86_WIDTH_32, 0, 0);
x86_l_126b:
	/* 0x126b: shr    rdx,cl */
	X86_VM_RUN_OP_SUB(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 0);
x86_l_126e:
	/* 0x126e: or     rdx,rsi */
	X86_VM_RUN_OP_SUB(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_1271:
	/* 0x1271: xor    rdx,r9 */
	X86_VM_RUN_OP_SUB(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_R9, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1274:
	/* 0x1274: shr    rax,0x3 */
	X86_VM_RUN_OP_SUB(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 3ULL);
x86_l_1278:
	/* 0x1278: add    rax,rdx */
	X86_VM_RUN_OP_SUB(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 0);
	/* 0x127b: pop    rbp */
	/* generated-C ABI: callee-save frame traffic handled by wrapper */
x86_l_127c:
	/* 0x127c: ret */
	X86_VM_SUB_RETURN();
	#undef X86_VM_SUB_RETURN
	#undef __x86_vm_state
	return X86_INTERP_TRAP;
}

static __noinline int x86_fn_local_call_crossload(struct x86_state *__x86_vm_state_ptr, void *__x86_vm_data, void *__x86_vm_data_end)
{
	#define __x86_vm_state (*__x86_vm_state_ptr)
	struct x86_insn __x86_vm_insn = {};
	__u64 __save_rbx = __x86_vm_state.rbx;
	void *__save_p_rbx = __x86_vm_state.p_rbx;
	__u8 __save_tag_rbx = __x86_vm_state.tag_rbx;
	__u64 __save_r12 = __x86_vm_state.r12;
	void *__save_p_r12 = __x86_vm_state.p_r12;
	__u8 __save_tag_r12 = __x86_vm_state.tag_r12;
	__u64 __save_r13 = __x86_vm_state.r13;
	void *__save_p_r13 = __x86_vm_state.p_r13;
	__u8 __save_tag_r13 = __x86_vm_state.tag_r13;
	__u64 __save_r14 = __x86_vm_state.r14;
	void *__save_p_r14 = __x86_vm_state.p_r14;
	__u8 __save_tag_r14 = __x86_vm_state.tag_r14;
	__u64 __save_r15 = __x86_vm_state.r15;
	void *__save_p_r15 = __x86_vm_state.p_r15;
	__u8 __save_tag_r15 = __x86_vm_state.tag_r15;
	#define X86_VM_SUB_RETURN() do { \
		__x86_vm_state.rbx = __save_rbx; \
		__x86_vm_state.r12 = __save_r12; \
		__x86_vm_state.r13 = __save_r13; \
		__x86_vm_state.r14 = __save_r14; \
		__x86_vm_state.r15 = __save_r15; \
		__x86_vm_state.p_rbx = __save_p_rbx; \
		__x86_vm_state.p_r12 = __save_p_r12; \
		__x86_vm_state.p_r13 = __save_p_r13; \
		__x86_vm_state.p_r14 = __save_p_r14; \
		__x86_vm_state.p_r15 = __save_p_r15; \
		__x86_vm_state.tag_rbx = __save_tag_rbx; \
		__x86_vm_state.tag_r12 = __save_tag_r12; \
		__x86_vm_state.tag_r13 = __save_tag_r13; \
		__x86_vm_state.tag_r14 = __save_tag_r14; \
		__x86_vm_state.tag_r15 = __save_tag_r15; \
		return X86_INTERP_CONTINUE; \
	} while (0)
	/* 0x12d0: push   rbp */
	/* generated-C ABI: callee-save frame traffic handled by wrapper */
	/* 0x12d1: mov    rbp,rsp */
	/* generated-C ABI: callee-save frame traffic handled by wrapper */
	/* 0x12d4: push   r14 */
	/* generated-C ABI: callee-save frame traffic handled by wrapper */
	/* 0x12d6: push   rbx */
	/* generated-C ABI: callee-save frame traffic handled by wrapper */
x86_l_12d7:
	/* 0x12d7: mov    r8d,ecx */
	X86_VM_RUN_OP_SUB(x86_exec_mov_reg, X86_OP_MOV_REG, X86_R8, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_12da:
	/* 0x12da: mov    eax,edx */
	X86_VM_RUN_OP_SUB(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RAX, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_12dc:
	/* 0x12dc: movzx  edx,BYTE PTR [rsi+rax*1] */
	X86_VM_RUN_OP_SUB(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_12e0:
	/* 0x12e0: lea    rcx,[rax+0x4] */
	X86_VM_RUN_OP_SUB(x86_exec_lea, X86_OP_LEA, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_12e4:
	/* 0x12e4: movzx  r9d,BYTE PTR [rsi+rax*1+0x4] */
	X86_VM_RUN_OP_SUB(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R9, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 4ULL);
x86_l_12ea:
	/* 0x12ea: movsxd r11,ecx */
	X86_VM_RUN_OP_SUB(x86_exec_movsx_reg, X86_OP_MOVSX_REG, X86_R11, X86_RCX, X86_WIDTH_64, X86_WIDTH_32, 0);
x86_l_12ed:
	/* 0x12ed: movzx  r10d,BYTE PTR [rsi+r11*1+0x1] */
	X86_VM_RUN_OP_SUB(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R10, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R11, 0, X86_WIDTH_8), 1ULL);
x86_l_12f3:
	/* 0x12f3: add    rdi,QWORD PTR [rsi+rax*1+0x8] */
	X86_VM_RUN_OP_SUB(x86_exec_alu_mem, X86_OP_ALU_MEM, X86_RDI, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_12f8:
	/* 0x12f8: mov    rax,QWORD PTR [rsi+rax*1+0x10] */
	X86_VM_RUN_OP_SUB(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 16ULL);
x86_l_12fd:
	/* 0x12fd: xor    rax,rdi */
	X86_VM_RUN_OP_SUB(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RDI, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1300:
	/* 0x1300: and    dl,0x7 */
	X86_VM_RUN_OP_SUB(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_ALU_AND, 7ULL);
x86_l_1303:
	/* 0x1303: lea    ecx,[rdx+0x1] */
	X86_VM_RUN_OP_SUB(x86_exec_lea, X86_OP_LEA, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_1306:
	/* 0x1306: mov    rbx,rax */
	X86_VM_RUN_OP_SUB(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RBX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_1309:
	/* 0x1309: shl    rbx,cl */
	X86_VM_RUN_OP_SUB(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 0);
x86_l_130c:
	/* 0x130c: movzx  r14d,BYTE PTR [rsi+r11*1+0x2] */
	X86_VM_RUN_OP_SUB(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R14, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R11, 0, X86_WIDTH_8), 2ULL);
x86_l_1312:
	/* 0x1312: movzx  esi,BYTE PTR [rsi+r11*1+0x3] */
	X86_VM_RUN_OP_SUB(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R11, 0, X86_WIDTH_8), 3ULL);
x86_l_1318:
	/* 0x1318: mov    ecx,edx */
	X86_VM_RUN_OP_SUB(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RCX, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_131a:
	/* 0x131a: not    cl */
	X86_VM_RUN_OP_SUB(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_ALU_NOT, 0);
x86_l_131c:
	/* 0x131c: shr    rax,cl */
	X86_VM_RUN_OP_SUB(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 0);
x86_l_131f:
	/* 0x131f: or     rax,rbx */
	X86_VM_RUN_OP_SUB(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RBX, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_1322:
	/* 0x1322: shl    rsi,0x21 */
	X86_VM_RUN_OP_SUB(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 33ULL);
x86_l_1326:
	/* 0x1326: shl    r14,0x19 */
	X86_VM_RUN_OP_SUB(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 25ULL);
x86_l_132a:
	/* 0x132a: shl    r10d,0x11 */
	X86_VM_RUN_OP_SUB(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 17ULL);
x86_l_132e:
	/* 0x132e: shl    r9d,0x9 */
	X86_VM_RUN_OP_SUB(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 9ULL);
x86_l_1332:
	/* 0x1332: or     r9d,r10d */
	X86_VM_RUN_OP_SUB(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_R10, X86_WIDTH_32, X86_ALU_OR, 0);
x86_l_1335:
	/* 0x1335: or     r9,r14 */
	X86_VM_RUN_OP_SUB(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_R14, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_1338:
	/* 0x1338: or     r9,rsi */
	X86_VM_RUN_OP_SUB(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_RSI, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_133b:
	/* 0x133b: xor    r9,rdi */
	X86_VM_RUN_OP_SUB(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_RDI, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_133e:
	/* 0x133e: xor    r9,rax */
	X86_VM_RUN_OP_SUB(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1341:
	/* 0x1341: mov    esi,r8d */
	X86_VM_RUN_OP_SUB(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RSI, X86_R8, X86_WIDTH_32, 0, 0);
x86_l_1344:
	/* 0x1344: mov    ecx,edx */
	X86_VM_RUN_OP_SUB(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RCX, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_1346:
	/* 0x1346: shl    rsi,cl */
	X86_VM_RUN_OP_SUB(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RSI, X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 0);
x86_l_1349:
	/* 0x1349: add    rsi,r9 */
	X86_VM_RUN_OP_SUB(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RSI, X86_R9, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_134c:
	/* 0x134c: shr    rax,0x5 */
	X86_VM_RUN_OP_SUB(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 5ULL);
x86_l_1350:
	/* 0x1350: xor    rax,rsi */
	X86_VM_RUN_OP_SUB(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1353:
	/* 0x1353: add    rax,rdi */
	X86_VM_RUN_OP_SUB(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 0);
	/* 0x1356: pop    rbx */
	/* generated-C ABI: callee-save frame traffic handled by wrapper */
	/* 0x1357: pop    r14 */
	/* generated-C ABI: callee-save frame traffic handled by wrapper */
	/* 0x1359: pop    rbp */
	/* generated-C ABI: callee-save frame traffic handled by wrapper */
x86_l_135a:
	/* 0x135a: ret */
	X86_VM_SUB_RETURN();
	#undef X86_VM_SUB_RETURN
	#undef __x86_vm_state
	return X86_INTERP_TRAP;
}

static __noinline int x86_fn_local_call_bytes(struct x86_state *__x86_vm_state_ptr, void *__x86_vm_data, void *__x86_vm_data_end)
{
	#define __x86_vm_state (*__x86_vm_state_ptr)
	struct x86_insn __x86_vm_insn = {};
	__u64 __save_rbx = __x86_vm_state.rbx;
	void *__save_p_rbx = __x86_vm_state.p_rbx;
	__u8 __save_tag_rbx = __x86_vm_state.tag_rbx;
	__u64 __save_r12 = __x86_vm_state.r12;
	void *__save_p_r12 = __x86_vm_state.p_r12;
	__u8 __save_tag_r12 = __x86_vm_state.tag_r12;
	__u64 __save_r13 = __x86_vm_state.r13;
	void *__save_p_r13 = __x86_vm_state.p_r13;
	__u8 __save_tag_r13 = __x86_vm_state.tag_r13;
	__u64 __save_r14 = __x86_vm_state.r14;
	void *__save_p_r14 = __x86_vm_state.p_r14;
	__u8 __save_tag_r14 = __x86_vm_state.tag_r14;
	__u64 __save_r15 = __x86_vm_state.r15;
	void *__save_p_r15 = __x86_vm_state.p_r15;
	__u8 __save_tag_r15 = __x86_vm_state.tag_r15;
	#define X86_VM_SUB_RETURN() do { \
		__x86_vm_state.rbx = __save_rbx; \
		__x86_vm_state.r12 = __save_r12; \
		__x86_vm_state.r13 = __save_r13; \
		__x86_vm_state.r14 = __save_r14; \
		__x86_vm_state.r15 = __save_r15; \
		__x86_vm_state.p_rbx = __save_p_rbx; \
		__x86_vm_state.p_r12 = __save_p_r12; \
		__x86_vm_state.p_r13 = __save_p_r13; \
		__x86_vm_state.p_r14 = __save_p_r14; \
		__x86_vm_state.p_r15 = __save_p_r15; \
		__x86_vm_state.tag_rbx = __save_tag_rbx; \
		__x86_vm_state.tag_r12 = __save_tag_r12; \
		__x86_vm_state.tag_r13 = __save_tag_r13; \
		__x86_vm_state.tag_r14 = __save_tag_r14; \
		__x86_vm_state.tag_r15 = __save_tag_r15; \
		return X86_INTERP_CONTINUE; \
	} while (0)
	/* 0x1360: push   rbp */
	/* generated-C ABI: callee-save frame traffic handled by wrapper */
	/* 0x1361: mov    rbp,rsp */
	/* generated-C ABI: callee-save frame traffic handled by wrapper */
x86_l_1364:
	/* 0x1364: mov    eax,ecx */
	X86_VM_RUN_OP_SUB(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RAX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_1366:
	/* 0x1366: mov    ecx,edx */
	X86_VM_RUN_OP_SUB(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RCX, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_1368:
	/* 0x1368: movzx  edx,BYTE PTR [rsi+rcx*1] */
	X86_VM_RUN_OP_SUB(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_136c:
	/* 0x136c: movabs r8,0x94d049bb133111eb */
	X86_VM_RUN_OP_SUB(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_64, 0, 10723151780598845931ULL);
x86_l_1376:
	/* 0x1376: xor    r8,rdi */
	X86_VM_RUN_OP_SUB(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R8, X86_RDI, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1379:
	/* 0x1379: xor    r8,rdx */
	X86_VM_RUN_OP_SUB(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R8, X86_RDX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_137c:
	/* 0x137c: add    r8,rax */
	X86_VM_RUN_OP_SUB(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R8, X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_137f:
	/* 0x137f: rol    r8,1 */
	X86_VM_RUN_OP_SUB(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 1ULL);
x86_l_1382:
	/* 0x1382: movzx  edx,BYTE PTR [rsi+rcx*1+0x1] */
	X86_VM_RUN_OP_SUB(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 1ULL);
x86_l_1387:
	/* 0x1387: shl    edx,0x8 */
	X86_VM_RUN_OP_SUB(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 8ULL);
x86_l_138a:
	/* 0x138a: xor    rdx,r8 */
	X86_VM_RUN_OP_SUB(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_R8, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_138d:
	/* 0x138d: add    rdx,rax */
	X86_VM_RUN_OP_SUB(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1390:
	/* 0x1390: inc    rdx */
	X86_VM_RUN_OP_SUB(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1393:
	/* 0x1393: rol    rdx,0x2 */
	X86_VM_RUN_OP_SUB(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 2ULL);
x86_l_1397:
	/* 0x1397: movzx  edi,BYTE PTR [rsi+rcx*1+0x2] */
	X86_VM_RUN_OP_SUB(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 2ULL);
x86_l_139c:
	/* 0x139c: shl    edi,0x10 */
	X86_VM_RUN_OP_SUB(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 16ULL);
x86_l_139f:
	/* 0x139f: xor    rdi,rdx */
	X86_VM_RUN_OP_SUB(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_RDX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_13a2:
	/* 0x13a2: lea    rdx,[rax+rdi*1] */
	X86_VM_RUN_OP_SUB(x86_exec_lea, X86_OP_LEA, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_13a6:
	/* 0x13a6: add    rdx,0x2 */
	X86_VM_RUN_OP_SUB(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_13aa:
	/* 0x13aa: rol    rdx,0x3 */
	X86_VM_RUN_OP_SUB(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 3ULL);
x86_l_13ae:
	/* 0x13ae: movzx  edi,BYTE PTR [rsi+rcx*1+0x3] */
	X86_VM_RUN_OP_SUB(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 3ULL);
x86_l_13b3:
	/* 0x13b3: shl    edi,0x18 */
	X86_VM_RUN_OP_SUB(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 24ULL);
x86_l_13b6:
	/* 0x13b6: xor    rdi,rdx */
	X86_VM_RUN_OP_SUB(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_RDX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_13b9:
	/* 0x13b9: lea    rdx,[rax+rdi*1] */
	X86_VM_RUN_OP_SUB(x86_exec_lea, X86_OP_LEA, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_13bd:
	/* 0x13bd: add    rdx,0x3 */
	X86_VM_RUN_OP_SUB(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 3ULL);
x86_l_13c1:
	/* 0x13c1: rol    rdx,0x4 */
	X86_VM_RUN_OP_SUB(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 4ULL);
x86_l_13c5:
	/* 0x13c5: movzx  edi,BYTE PTR [rsi+rcx*1+0x4] */
	X86_VM_RUN_OP_SUB(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 4ULL);
x86_l_13ca:
	/* 0x13ca: shl    rdi,0x20 */
	X86_VM_RUN_OP_SUB(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_13ce:
	/* 0x13ce: xor    rdi,rdx */
	X86_VM_RUN_OP_SUB(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_RDX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_13d1:
	/* 0x13d1: lea    rdx,[rax+rdi*1] */
	X86_VM_RUN_OP_SUB(x86_exec_lea, X86_OP_LEA, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_13d5:
	/* 0x13d5: add    rdx,0x4 */
	X86_VM_RUN_OP_SUB(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_13d9:
	/* 0x13d9: rol    rdx,0x5 */
	X86_VM_RUN_OP_SUB(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 5ULL);
x86_l_13dd:
	/* 0x13dd: movzx  edi,BYTE PTR [rsi+rcx*1+0x5] */
	X86_VM_RUN_OP_SUB(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 5ULL);
x86_l_13e2:
	/* 0x13e2: shl    rdi,0x28 */
	X86_VM_RUN_OP_SUB(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 40ULL);
x86_l_13e6:
	/* 0x13e6: xor    rdi,rdx */
	X86_VM_RUN_OP_SUB(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_RDX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_13e9:
	/* 0x13e9: lea    rdx,[rax+rdi*1] */
	X86_VM_RUN_OP_SUB(x86_exec_lea, X86_OP_LEA, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_13ed:
	/* 0x13ed: add    rdx,0x5 */
	X86_VM_RUN_OP_SUB(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 5ULL);
x86_l_13f1:
	/* 0x13f1: rol    rdx,0x6 */
	X86_VM_RUN_OP_SUB(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 6ULL);
x86_l_13f5:
	/* 0x13f5: movzx  edi,BYTE PTR [rsi+rcx*1+0x6] */
	X86_VM_RUN_OP_SUB(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 6ULL);
x86_l_13fa:
	/* 0x13fa: shl    rdi,0x30 */
	X86_VM_RUN_OP_SUB(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 48ULL);
x86_l_13fe:
	/* 0x13fe: xor    rdi,rdx */
	X86_VM_RUN_OP_SUB(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_RDX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1401:
	/* 0x1401: lea    rdx,[rax+rdi*1] */
	X86_VM_RUN_OP_SUB(x86_exec_lea, X86_OP_LEA, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_1405:
	/* 0x1405: add    rdx,0x6 */
	X86_VM_RUN_OP_SUB(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 6ULL);
x86_l_1409:
	/* 0x1409: rol    rdx,0x7 */
	X86_VM_RUN_OP_SUB(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 7ULL);
x86_l_140d:
	/* 0x140d: movzx  edi,BYTE PTR [rsi+rcx*1+0x7] */
	X86_VM_RUN_OP_SUB(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 7ULL);
x86_l_1412:
	/* 0x1412: shl    rdi,0x38 */
	X86_VM_RUN_OP_SUB(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 56ULL);
x86_l_1416:
	/* 0x1416: xor    rdi,rdx */
	X86_VM_RUN_OP_SUB(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_RDX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1419:
	/* 0x1419: add    rax,rdi */
	X86_VM_RUN_OP_SUB(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_141c:
	/* 0x141c: add    rax,0x7 */
	X86_VM_RUN_OP_SUB(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 7ULL);
x86_l_1420:
	/* 0x1420: rol    rax,0x8 */
	X86_VM_RUN_OP_SUB(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 8ULL);
x86_l_1424:
	/* 0x1424: add    rax,QWORD PTR [rsi+rcx*1+0x8] */
	X86_VM_RUN_OP_SUB(x86_exec_alu_mem, X86_OP_ALU_MEM, X86_RAX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1429:
	/* 0x1429: xor    rax,QWORD PTR [rsi+rcx*1+0x10] */
	X86_VM_RUN_OP_SUB(x86_exec_alu_mem, X86_OP_ALU_MEM, X86_RAX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 16ULL);
	/* 0x142e: pop    rbp */
	/* generated-C ABI: callee-save frame traffic handled by wrapper */
x86_l_142f:
	/* 0x142f: ret */
	X86_VM_SUB_RETURN();
	#undef X86_VM_SUB_RETURN
	#undef __x86_vm_state
	return X86_INTERP_TRAP;
}

static long x86_loop_1180_11b6_cb(__u32 __x86_loop_index, void *ctx)
{
	struct x86_vm_loop_ctx *loop = ctx;
	void *__x86_vm_data = loop->data;
	void *__x86_vm_data_end = loop->data_end;
	struct x86_insn __x86_vm_insn = {};
	#define __x86_vm_state loop->state

	(void)__x86_loop_index;
	if (loop->failed || loop->done || loop->next)
		return 1;
	goto x86_l_11b6;
x86_l_1180:
	/* 0x1180: mov    rsi,QWORD PTR [rbp-0x30] */
	X86_VM_LOOP_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RSI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551568ULL);
x86_l_1184:
	/* 0x1184: mov    ecx,r14d */
	X86_VM_LOOP_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RCX, X86_R14, X86_WIDTH_32, 0, 0);
x86_l_1187:
	/* 0x1187: call   1280 <local_call_pressure> */
	X86_VM_LOOP_CALL(x86_fn_local_call_pressure);
x86_l_118c:
	/* 0x118c: mov    ecx,ebx */
	X86_VM_LOOP_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RCX, X86_RBX, X86_WIDTH_32, 0, 0);
x86_l_118e:
	/* 0x118e: and    cl,0x38 */
	X86_VM_LOOP_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_ALU_AND, 56ULL);
x86_l_1191:
	/* 0x1191: shl    r15,cl */
	X86_VM_LOOP_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 0);
x86_l_1194:
	/* 0x1194: mov    edi,r14d */
	X86_VM_LOOP_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RDI, X86_R14, X86_WIDTH_32, 0, 0);
x86_l_1197:
	/* 0x1197: add    rdi,r15 */
	X86_VM_LOOP_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_119a:
	/* 0x119a: xor    rdi,rax */
	X86_VM_LOOP_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_119d:
	/* 0x119d: add    rbx,0x8 */
	X86_VM_LOOP_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_11a1:
	/* 0x11a1: add    r12d,0x10 */
	X86_VM_LOOP_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 16ULL);
x86_l_11a5:
	/* 0x11a5: add    r13,0x18 */
	X86_VM_LOOP_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_11a9:
	/* 0x11a9: cmp    rbx,0x80 */
	X86_VM_LOOP_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 128ULL);
x86_l_11b0:
	/* 0x11b0: mov    rsi,QWORD PTR [rbp-0x38] */
	X86_VM_LOOP_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RSI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551560ULL);
x86_l_11b4:
	/* 0x11b4: je     1211 <bpf_local_call_fanout_dispatch_xdp+0x111> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_E)) {
		X86_VM_LOOP_EXIT(0x1211);
	}
	return 0;
x86_l_11b6:
	/* 0x11b6: movzx  r15d,BYTE PTR [rsi+r13*1-0x7] */
	X86_VM_LOOP_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R15, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_8), 18446744073709551609ULL);
x86_l_11bc:
	/* 0x11bc: and    r15d,0x3 */
	X86_VM_LOOP_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 3ULL);
x86_l_11c0:
	/* 0x11c0: mov    r14d,DWORD PTR [rsi+r13*1-0x3] */
	X86_VM_LOOP_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R14, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 18446744073709551613ULL);
x86_l_11c5:
	/* 0x11c5: xor    r14d,r12d */
	X86_VM_LOOP_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R14, X86_R12, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_11c8:
	/* 0x11c8: lea    rdx,[r13-0xf] */
	X86_VM_LOOP_OP(x86_exec_lea, X86_OP_LEA, X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551601ULL);
x86_l_11cc:
	/* 0x11cc: cmp    r15,0x2 */
	X86_VM_LOOP_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, 0, 2ULL);
x86_l_11d0:
	/* 0x11d0: je     11f0 <bpf_local_call_fanout_dispatch_xdp+0xf0> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_E))
		goto x86_l_11f0;
x86_l_11d2:
	/* 0x11d2: cmp    r15d,0x1 */
	X86_VM_LOOP_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_11d6:
	/* 0x11d6: je     1180 <bpf_local_call_fanout_dispatch_xdp+0x80> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_E))
		goto x86_l_1180;
x86_l_11d8:
	/* 0x11d8: test   r15d,r15d */
	X86_VM_LOOP_OP(x86_exec_test_reg, X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32, 0, 0);
x86_l_11db:
	/* 0x11db: jne    1200 <bpf_local_call_fanout_dispatch_xdp+0x100> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_1200;
x86_l_11dd:
	/* 0x11dd: mov    rsi,QWORD PTR [rbp-0x30] */
	X86_VM_LOOP_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RSI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551568ULL);
x86_l_11e1:
	/* 0x11e1: mov    ecx,r14d */
	X86_VM_LOOP_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RCX, X86_R14, X86_WIDTH_32, 0, 0);
x86_l_11e4:
	/* 0x11e4: call   1230 <local_call_linear> */
	X86_VM_LOOP_CALL(x86_fn_local_call_linear);
x86_l_11e9:
	/* 0x11e9: jmp    118c <bpf_local_call_fanout_dispatch_xdp+0x8c> */
	goto x86_l_118c;
x86_l_11eb:
	/* 0x11eb: nop    DWORD PTR [rax+rax*1+0x0] */
	X86_VM_LOOP_OP(x86_exec_nop, X86_OP_NOP, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_11f0:
	/* 0x11f0: mov    rsi,QWORD PTR [rbp-0x30] */
	X86_VM_LOOP_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RSI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551568ULL);
x86_l_11f4:
	/* 0x11f4: mov    ecx,r14d */
	X86_VM_LOOP_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RCX, X86_R14, X86_WIDTH_32, 0, 0);
x86_l_11f7:
	/* 0x11f7: call   12d0 <local_call_crossload> */
	X86_VM_LOOP_CALL(x86_fn_local_call_crossload);
x86_l_11fc:
	/* 0x11fc: jmp    118c <bpf_local_call_fanout_dispatch_xdp+0x8c> */
	goto x86_l_118c;
x86_l_11fe:
	/* 0x11fe: xchg   ax,ax */
	X86_VM_LOOP_OP(x86_exec_xchg, X86_OP_XCHG, X86_RAX, X86_RAX, X86_WIDTH_16, 0, 0);
x86_l_1200:
	/* 0x1200: mov    rsi,QWORD PTR [rbp-0x30] */
	X86_VM_LOOP_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RSI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551568ULL);
x86_l_1204:
	/* 0x1204: mov    ecx,r14d */
	X86_VM_LOOP_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RCX, X86_R14, X86_WIDTH_32, 0, 0);
x86_l_1207:
	/* 0x1207: call   1360 <local_call_bytes> */
	X86_VM_LOOP_CALL(x86_fn_local_call_bytes);
x86_l_120c:
	/* 0x120c: jmp    118c <bpf_local_call_fanout_dispatch_xdp+0x8c> */
	goto x86_l_118c;
	#undef __x86_vm_state
	return 0;
}

SEC("xdp")
int bpf_local_call_fanout_dispatch_x86_vm_xdp(struct xdp_md *ctx)
{
	void *__x86_vm_ctx = (void *)ctx;
	void *__x86_vm_data = (void *)(long)ctx->data;
	void *__x86_vm_data_end = (void *)(long)ctx->data_end;
	struct x86_vm_loop_ctx __x86_loop = {};
	struct x86_insn __x86_vm_insn = {};
	#define __x86_vm_state __x86_loop.state
	x86_init_state(&__x86_vm_state, (void *)ctx);
	__x86_vm_state.rbp = 0;
	__x86_vm_state.p_rbp = 0;
	__x86_vm_state.tag_rbp = X86_PTR_STACK;
	__x86_vm_state.rsp = 0;
	__x86_vm_state.p_rsp = 0;
	__x86_vm_state.tag_rsp = X86_PTR_STACK;
x86_l_1100:
	/* 0x1100: mov    rsi,QWORD PTR [rdi] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1103:
	/* 0x1103: mov    rcx,QWORD PTR [rdi+0x8] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1107:
	/* 0x1107: xor    eax,eax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1109:
	/* 0x1109: cmp    rsi,rcx */
	X86_VM_RUN_OP(x86_exec_cmp_reg, X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_110c:
	/* 0x110c: ja     1227 <bpf_local_call_fanout_dispatch_xdp+0x127> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_1227;
x86_l_1112:
	/* 0x1112: push   rbp */
	/* generated-C ABI: entry frame traffic handled by wrapper */
x86_l_1113:
	/* 0x1113: mov    rbp,rsp */
	/* generated-C ABI: entry frame traffic handled by wrapper */
x86_l_1116:
	/* 0x1116: push   r15 */
	/* generated-C ABI: entry frame traffic handled by wrapper */
x86_l_1118:
	/* 0x1118: push   r14 */
	/* generated-C ABI: entry frame traffic handled by wrapper */
x86_l_111a:
	/* 0x111a: push   r13 */
	/* generated-C ABI: entry frame traffic handled by wrapper */
x86_l_111c:
	/* 0x111c: push   r12 */
	/* generated-C ABI: entry frame traffic handled by wrapper */
x86_l_111e:
	/* 0x111e: push   rbx */
	/* generated-C ABI: entry frame traffic handled by wrapper */
x86_l_111f:
	/* 0x111f: sub    rsp,0x18 */
	/* generated-C ABI: entry frame traffic handled by wrapper */
x86_l_1123:
	/* 0x1123: lea    rdx,[rsi+0x8] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1127:
	/* 0x1127: mov    QWORD PTR [rbp-0x30],rdx */
	X86_VM_RUN_OP(x86_exec_mov_store_reg, X86_OP_MOV_STORE_REG, X86_RBP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551568ULL);
x86_l_112b:
	/* 0x112b: cmp    rdx,rcx */
	X86_VM_RUN_OP(x86_exec_cmp_reg, X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_112e:
	/* 0x112e: ja     1219 <bpf_local_call_fanout_dispatch_xdp+0x119> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_1219;
x86_l_1134:
	/* 0x1134: lea    rdx,[rsi+0x190] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 400ULL);
x86_l_113b:
	/* 0x113b: cmp    rdx,rcx */
	X86_VM_RUN_OP(x86_exec_cmp_reg, X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_113e:
	/* 0x113e: ja     1219 <bpf_local_call_fanout_dispatch_xdp+0x119> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_1219;
x86_l_1144:
	/* 0x1144: cmp    DWORD PTR [rsi+0x8],0x10 */
	X86_VM_RUN_OP(x86_exec_cmp_mem_imm, X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738384ULL);
x86_l_1148:
	/* 0x1148: jne    1219 <bpf_local_call_fanout_dispatch_xdp+0x119> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_1219;
x86_l_114e:
	/* 0x114e: cmp    DWORD PTR [rsi+0xc],0x18 */
	X86_VM_RUN_OP(x86_exec_cmp_mem_imm, X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607576ULL);
x86_l_1152:
	/* 0x1152: jne    1219 <bpf_local_call_fanout_dispatch_xdp+0x119> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_1219;
x86_l_1158:
	/* 0x1158: movabs rdi,0x243f6a8885a308d3 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, 2611923443488327891ULL);
x86_l_1162:
	/* 0x1162: xor    r12d,r12d */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1165:
	/* 0x1165: mov    r13d,0x17 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, 0, 23ULL);
x86_l_116b:
	/* 0x116b: xor    ebx,ebx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_116d:
	/* 0x116d: mov    QWORD PTR [rbp-0x38],rsi */
	X86_VM_RUN_OP(x86_exec_mov_store_reg, X86_OP_MOV_STORE_REG, X86_RBP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551560ULL);
x86_l_1171:
	/* 0x1171: jmp    11b6 <bpf_local_call_fanout_dispatch_xdp+0xb6> */
	/* verifier loop lowering: bpf_loop callback preserves x86 steps */
	struct x86_vm_reg_save __x86_loop_save_1180_11b6_rdi = {};
	x86_vm_loop_prepare((&__x86_loop), __x86_vm_data, __x86_vm_data_end, &__x86_loop_save_1180_11b6_rdi);
	if (bpf_loop(16, x86_loop_1180_11b6_cb, (&__x86_loop), 0) < 0) {
		(&__x86_loop)->failed = __LINE__;
		return XDP_ABORTED;
	}
	x86_vm_loop_restore_rdi((&__x86_loop), &__x86_loop_save_1180_11b6_rdi);
	if ((&__x86_loop)->failed)
		return XDP_ABORTED;
	if ((&__x86_loop)->done)
		X86_VM_RET_RAX();
	if ((&__x86_loop)->next == 0x1211) {
		goto x86_l_1211;
	}
	return XDP_ABORTED;
x86_l_1173:
	/* 0x1173: data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0] */
	X86_VM_RUN_OP(x86_exec_nop, X86_OP_NOP, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1211:
	/* 0x1211: mov    QWORD PTR [rsi],rdi */
	X86_VM_RUN_OP(x86_exec_mov_store_reg, X86_OP_MOV_STORE_REG, X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1214:
	/* 0x1214: mov    eax,0x2 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_1219:
	/* 0x1219: add    rsp,0x18 */
	/* generated-C ABI: entry frame traffic handled by wrapper */
x86_l_121d:
	/* 0x121d: pop    rbx */
	/* generated-C ABI: entry frame traffic handled by wrapper */
x86_l_121e:
	/* 0x121e: pop    r12 */
	/* generated-C ABI: entry frame traffic handled by wrapper */
x86_l_1220:
	/* 0x1220: pop    r13 */
	/* generated-C ABI: entry frame traffic handled by wrapper */
x86_l_1222:
	/* 0x1222: pop    r14 */
	/* generated-C ABI: entry frame traffic handled by wrapper */
x86_l_1224:
	/* 0x1224: pop    r15 */
	/* generated-C ABI: entry frame traffic handled by wrapper */
x86_l_1226:
	/* 0x1226: pop    rbp */
	/* generated-C ABI: entry frame traffic handled by wrapper */
x86_l_1227:
	/* 0x1227: ret */
	X86_VM_RET_RAX();
	#undef __x86_vm_state
	return XDP_ABORTED;
}

X86_VM_LICENSE();
