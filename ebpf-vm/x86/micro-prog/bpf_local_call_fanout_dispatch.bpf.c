#define X86_VM_ENABLE_STACK 1
#define X86_VM_ENABLE_PACKET_REG_FASTPATH 1
#include "../x86_vm_bpf.h"

struct local_call_fanout_loop_ctx {
	struct x86_state state;
	void *data;
	void *data_end;
	__u32 failed;
};

#define LOCAL_CALL_LOOP_STEP(HELPER, OP, DST, SRC, FLAGS, AUX, IMM) \
	do {                                                               \
		struct x86_insn __x86_loop_insn = X86_VM_INSN((OP), (DST),   \
			(SRC), (FLAGS), (AUX), (IMM));                         \
		int __x86_loop_ret = HELPER(&loop->state, &__x86_loop_insn,  \
					       loop->data, loop->data_end);       \
		if (__x86_loop_ret != X86_INTERP_CONTINUE) {                 \
			loop->failed = __LINE__;                               \
			return 1;                                             \
		}                                                          \
	} while (0)

static long local_call_fanout_cb(__u32 index, void *ctx)
{
	struct local_call_fanout_loop_ctx *loop = ctx;

	if (loop->failed)
		return 1;
	if (index >= 16) {
		loop->failed = __LINE__;
		return 1;
	}
	/* proof-loop induction variables from native rbx/r12/r13. */
	loop->state.rbx = (__u64)index << 3;
	loop->state.p_rbx = 0;
	loop->state.tag_rbx = X86_PTR_NONE;
	loop->state.r12 = (__u64)index << 4;
	loop->state.p_r12 = 0;
	loop->state.tag_r12 = X86_PTR_NONE;
	loop->state.r13 = 23 + ((__u64)index * 24);
	loop->state.p_r13 = 0;
	loop->state.tag_r13 = X86_PTR_NONE;
	/* 0x11b6: movzx  r15d,BYTE PTR [rsi+r13*1-0x7] */
	LOCAL_CALL_LOOP_STEP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R15, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_8), 18446744073709551609ULL);
	/* 0x11bc: and    r15d,0x3 */
	LOCAL_CALL_LOOP_STEP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 3ULL);
	/* 0x11c0: mov    r14d,DWORD PTR [rsi+r13*1-0x3] */
	LOCAL_CALL_LOOP_STEP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R14, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 18446744073709551613ULL);
	/* 0x11c5: xor    r14d,r12d */
	LOCAL_CALL_LOOP_STEP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R14, X86_R12, X86_WIDTH_32, X86_ALU_XOR, 0);
	/* 0x11c8: lea    rdx,[r13-0xf] */
	LOCAL_CALL_LOOP_STEP(x86_exec_lea, X86_OP_LEA, X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551601ULL);
	/* 0x11cc: cmp    r15,0x2 */
	LOCAL_CALL_LOOP_STEP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, 0, 2ULL);
	/* 0x11d0: je     11f0 <bpf_local_call_fanout_dispatch_xdp+0xf0> */
	if (x86_eval_cc(&loop->state, X86_CC_E)) {
		/* 0x11f0: mov    rsi,QWORD PTR [rbp-0x30] */
		LOCAL_CALL_LOOP_STEP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RSI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551568ULL);
		/* 0x11f4: mov    ecx,r14d */
		LOCAL_CALL_LOOP_STEP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RCX, X86_R14, X86_WIDTH_32, 0, 0);
		/* inline local_call_crossload in the bpf_loop verifier frame */
		{
			__u64 __save_rbx = loop->state.rbx;
			void *__save_p_rbx = loop->state.p_rbx;
			__u8 __save_tag_rbx = loop->state.tag_rbx;
			__u64 __save_r14 = loop->state.r14;
			void *__save_p_r14 = loop->state.p_r14;
			__u8 __save_tag_r14 = loop->state.tag_r14;
			/* 0x12d0: push   rbp */
			/* generated-C ABI: callee-save frame traffic handled by wrapper */
			/* 0x12d1: mov    rbp,rsp */
			/* generated-C ABI: callee-save frame traffic handled by wrapper */
			/* 0x12d4: push   r14 */
			/* generated-C ABI: callee-save frame traffic handled by wrapper */
			/* 0x12d6: push   rbx */
			/* generated-C ABI: callee-save frame traffic handled by wrapper */
			/* 0x12d7: mov    r8d,ecx */
			LOCAL_CALL_LOOP_STEP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_R8, X86_RCX, X86_WIDTH_32, 0, 0);
			/* 0x12da: mov    eax,edx */
			LOCAL_CALL_LOOP_STEP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RAX, X86_RDX, X86_WIDTH_32, 0, 0);
			/* 0x12dc: movzx  edx,BYTE PTR [rsi+rax*1] */
			LOCAL_CALL_LOOP_STEP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
			/* 0x12e0: lea    rcx,[rax+0x4] */
			LOCAL_CALL_LOOP_STEP(x86_exec_lea, X86_OP_LEA, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
			/* 0x12e4: movzx  r9d,BYTE PTR [rsi+rax*1+0x4] */
			LOCAL_CALL_LOOP_STEP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R9, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 4ULL);
			/* 0x12ea: movsxd r11,ecx */
			LOCAL_CALL_LOOP_STEP(x86_exec_movsx_reg, X86_OP_MOVSX_REG, X86_R11, X86_RCX, X86_WIDTH_64, X86_WIDTH_32, 0);
			/* 0x12ed: movzx  r10d,BYTE PTR [rsi+r11*1+0x1] */
			LOCAL_CALL_LOOP_STEP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R10, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R11, 0, X86_WIDTH_8), 1ULL);
			/* 0x12f3: add    rdi,QWORD PTR [rsi+rax*1+0x8] */
			LOCAL_CALL_LOOP_STEP(x86_exec_alu_mem, X86_OP_ALU_MEM, X86_RDI, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
			/* 0x12f8: mov    rax,QWORD PTR [rsi+rax*1+0x10] */
			LOCAL_CALL_LOOP_STEP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 16ULL);
			/* 0x12fd: xor    rax,rdi */
			LOCAL_CALL_LOOP_STEP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RDI, X86_WIDTH_64, X86_ALU_XOR, 0);
			/* 0x1300: and    dl,0x7 */
			LOCAL_CALL_LOOP_STEP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_ALU_AND, 7ULL);
			/* 0x1303: lea    ecx,[rdx+0x1] */
			LOCAL_CALL_LOOP_STEP(x86_exec_lea, X86_OP_LEA, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
			/* 0x1306: mov    rbx,rax */
			LOCAL_CALL_LOOP_STEP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RBX, X86_RAX, X86_WIDTH_64, 0, 0);
			/* 0x1309: shl    rbx,cl */
			LOCAL_CALL_LOOP_STEP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 0);
			/* 0x130c: movzx  r14d,BYTE PTR [rsi+r11*1+0x2] */
			LOCAL_CALL_LOOP_STEP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R14, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R11, 0, X86_WIDTH_8), 2ULL);
			/* 0x1312: movzx  esi,BYTE PTR [rsi+r11*1+0x3] */
			LOCAL_CALL_LOOP_STEP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R11, 0, X86_WIDTH_8), 3ULL);
			/* 0x1318: mov    ecx,edx */
			LOCAL_CALL_LOOP_STEP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RCX, X86_RDX, X86_WIDTH_32, 0, 0);
			/* 0x131a: not    cl */
			LOCAL_CALL_LOOP_STEP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_ALU_NOT, 0);
			/* 0x131c: shr    rax,cl */
			LOCAL_CALL_LOOP_STEP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 0);
			/* 0x131f: or     rax,rbx */
			LOCAL_CALL_LOOP_STEP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RBX, X86_WIDTH_64, X86_ALU_OR, 0);
			/* 0x1322: shl    rsi,0x21 */
			LOCAL_CALL_LOOP_STEP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 33ULL);
			/* 0x1326: shl    r14,0x19 */
			LOCAL_CALL_LOOP_STEP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 25ULL);
			/* 0x132a: shl    r10d,0x11 */
			LOCAL_CALL_LOOP_STEP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 17ULL);
			/* 0x132e: shl    r9d,0x9 */
			LOCAL_CALL_LOOP_STEP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 9ULL);
			/* 0x1332: or     r9d,r10d */
			LOCAL_CALL_LOOP_STEP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_R10, X86_WIDTH_32, X86_ALU_OR, 0);
			/* 0x1335: or     r9,r14 */
			LOCAL_CALL_LOOP_STEP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_R14, X86_WIDTH_64, X86_ALU_OR, 0);
			/* 0x1338: or     r9,rsi */
			LOCAL_CALL_LOOP_STEP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_RSI, X86_WIDTH_64, X86_ALU_OR, 0);
			/* 0x133b: xor    r9,rdi */
			LOCAL_CALL_LOOP_STEP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_RDI, X86_WIDTH_64, X86_ALU_XOR, 0);
			/* 0x133e: xor    r9,rax */
			LOCAL_CALL_LOOP_STEP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
			/* 0x1341: mov    esi,r8d */
			LOCAL_CALL_LOOP_STEP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RSI, X86_R8, X86_WIDTH_32, 0, 0);
			/* 0x1344: mov    ecx,edx */
			LOCAL_CALL_LOOP_STEP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RCX, X86_RDX, X86_WIDTH_32, 0, 0);
			/* 0x1346: shl    rsi,cl */
			LOCAL_CALL_LOOP_STEP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RSI, X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 0);
			/* 0x1349: add    rsi,r9 */
			LOCAL_CALL_LOOP_STEP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RSI, X86_R9, X86_WIDTH_64, X86_ALU_ADD, 0);
			/* 0x134c: shr    rax,0x5 */
			LOCAL_CALL_LOOP_STEP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 5ULL);
			/* 0x1350: xor    rax,rsi */
			LOCAL_CALL_LOOP_STEP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_XOR, 0);
			/* 0x1353: add    rax,rdi */
			LOCAL_CALL_LOOP_STEP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 0);
			/* 0x1356: pop    rbx */
			/* generated-C ABI: callee-save frame traffic handled by wrapper */
			/* 0x1357: pop    r14 */
			/* generated-C ABI: callee-save frame traffic handled by wrapper */
			/* 0x1359: pop    rbp */
			/* generated-C ABI: callee-save frame traffic handled by wrapper */
			/* 0x135a: ret */
			/* inline callee returns to structured caller */
			loop->state.rbx = __save_rbx;
			loop->state.p_rbx = __save_p_rbx;
			loop->state.tag_rbx = __save_tag_rbx;
			loop->state.r14 = __save_r14;
			loop->state.p_r14 = __save_p_r14;
			loop->state.tag_r14 = __save_tag_r14;
		}
	} else {
		/* 0x11d2: cmp    r15d,0x1 */
		LOCAL_CALL_LOOP_STEP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
		/* 0x11d6: je     1180 <bpf_local_call_fanout_dispatch_xdp+0x80> */
		if (x86_eval_cc(&loop->state, X86_CC_E)) {
			/* 0x1180: mov    rsi,QWORD PTR [rbp-0x30] */
			LOCAL_CALL_LOOP_STEP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RSI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551568ULL);
			/* 0x1184: mov    ecx,r14d */
			LOCAL_CALL_LOOP_STEP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RCX, X86_R14, X86_WIDTH_32, 0, 0);
			/* inline local_call_pressure in the bpf_loop verifier frame */
			{
				/* 0x1280: push   rbp */
				/* generated-C ABI: callee-save frame traffic handled by wrapper */
				/* 0x1281: mov    rbp,rsp */
				/* generated-C ABI: callee-save frame traffic handled by wrapper */
				/* 0x1284: mov    eax,edx */
				LOCAL_CALL_LOOP_STEP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RAX, X86_RDX, X86_WIDTH_32, 0, 0);
				/* 0x1286: mov    r8,QWORD PTR [rax+rsi*1+0x8] */
				LOCAL_CALL_LOOP_STEP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R8, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 8ULL);
				/* 0x128b: mov    rdx,QWORD PTR [rax+rsi*1+0x10] */
				LOCAL_CALL_LOOP_STEP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 16ULL);
				/* 0x1290: xor    rdi,r8 */
				LOCAL_CALL_LOOP_STEP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_R8, X86_WIDTH_64, X86_ALU_XOR, 0);
				/* 0x1293: mov    eax,ecx */
				LOCAL_CALL_LOOP_STEP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RAX, X86_RCX, X86_WIDTH_32, 0, 0);
				/* 0x1295: shl    rax,0x11 */
				LOCAL_CALL_LOOP_STEP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 17ULL);
				/* 0x1299: add    rax,rdx */
				LOCAL_CALL_LOOP_STEP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 0);
				/* 0x129c: lea    rcx,[rdi*8+0x0] */
				LOCAL_CALL_LOOP_STEP(x86_exec_lea, X86_OP_LEA, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 3), 0ULL);
				/* 0x12a4: shr    rdx,0x2 */
				LOCAL_CALL_LOOP_STEP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 2ULL);
				/* 0x12a8: xor    r8,rax */
				LOCAL_CALL_LOOP_STEP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R8, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
				/* 0x12ab: rol    r8,0x5 */
				LOCAL_CALL_LOOP_STEP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 5ULL);
				/* 0x12af: xor    rdx,rcx */
				LOCAL_CALL_LOOP_STEP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_XOR, 0);
				/* 0x12b2: lea    rcx,[rdx+rdi*1] */
				LOCAL_CALL_LOOP_STEP(x86_exec_lea, X86_OP_LEA, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
				/* 0x12b6: rol    rcx,0xb */
				LOCAL_CALL_LOOP_STEP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 11ULL);
				/* 0x12ba: add    rcx,r8 */
				LOCAL_CALL_LOOP_STEP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RCX, X86_R8, X86_WIDTH_64, X86_ALU_ADD, 0);
				/* 0x12bd: xor    rdi,rax */
				LOCAL_CALL_LOOP_STEP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
				/* 0x12c0: shr    rax,0x7 */
				LOCAL_CALL_LOOP_STEP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 7ULL);
				/* 0x12c4: xor    rax,rcx */
				LOCAL_CALL_LOOP_STEP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_XOR, 0);
				/* 0x12c7: add    rax,rdx */
				LOCAL_CALL_LOOP_STEP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 0);
				/* 0x12ca: xor    rax,rdi */
				LOCAL_CALL_LOOP_STEP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RDI, X86_WIDTH_64, X86_ALU_XOR, 0);
				/* 0x12cd: pop    rbp */
				/* generated-C ABI: callee-save frame traffic handled by wrapper */
				/* 0x12ce: ret */
				/* inline callee returns to structured caller */
			}
		} else {
			/* 0x11d8: test   r15d,r15d */
			LOCAL_CALL_LOOP_STEP(x86_exec_test_reg, X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32, 0, 0);
			/* 0x11db: jne    1200 <bpf_local_call_fanout_dispatch_xdp+0x100> */
			if (x86_eval_cc(&loop->state, X86_CC_NE)) {
				/* 0x1200: mov    rsi,QWORD PTR [rbp-0x30] */
				LOCAL_CALL_LOOP_STEP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RSI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551568ULL);
				/* 0x1204: mov    ecx,r14d */
				LOCAL_CALL_LOOP_STEP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RCX, X86_R14, X86_WIDTH_32, 0, 0);
				/* inline local_call_bytes in the bpf_loop verifier frame */
				{
					/* 0x1360: push   rbp */
					/* generated-C ABI: callee-save frame traffic handled by wrapper */
					/* 0x1361: mov    rbp,rsp */
					/* generated-C ABI: callee-save frame traffic handled by wrapper */
					/* 0x1364: mov    eax,ecx */
					LOCAL_CALL_LOOP_STEP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RAX, X86_RCX, X86_WIDTH_32, 0, 0);
					/* 0x1366: mov    ecx,edx */
					LOCAL_CALL_LOOP_STEP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RCX, X86_RDX, X86_WIDTH_32, 0, 0);
					/* 0x1368: movzx  edx,BYTE PTR [rsi+rcx*1] */
					LOCAL_CALL_LOOP_STEP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
					/* 0x136c: movabs r8,0x94d049bb133111eb */
					LOCAL_CALL_LOOP_STEP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_64, 0, 10723151780598845931ULL);
					/* 0x1376: xor    r8,rdi */
					LOCAL_CALL_LOOP_STEP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R8, X86_RDI, X86_WIDTH_64, X86_ALU_XOR, 0);
					/* 0x1379: xor    r8,rdx */
					LOCAL_CALL_LOOP_STEP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R8, X86_RDX, X86_WIDTH_64, X86_ALU_XOR, 0);
					/* 0x137c: add    r8,rax */
					LOCAL_CALL_LOOP_STEP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R8, X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 0);
					/* 0x137f: rol    r8,1 */
					LOCAL_CALL_LOOP_STEP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 1ULL);
					/* 0x1382: movzx  edx,BYTE PTR [rsi+rcx*1+0x1] */
					LOCAL_CALL_LOOP_STEP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 1ULL);
					/* 0x1387: shl    edx,0x8 */
					LOCAL_CALL_LOOP_STEP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 8ULL);
					/* 0x138a: xor    rdx,r8 */
					LOCAL_CALL_LOOP_STEP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_R8, X86_WIDTH_64, X86_ALU_XOR, 0);
					/* 0x138d: add    rdx,rax */
					LOCAL_CALL_LOOP_STEP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 0);
					/* 0x1390: inc    rdx */
					LOCAL_CALL_LOOP_STEP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_INC, 1);
					/* 0x1393: rol    rdx,0x2 */
					LOCAL_CALL_LOOP_STEP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 2ULL);
					/* 0x1397: movzx  edi,BYTE PTR [rsi+rcx*1+0x2] */
					LOCAL_CALL_LOOP_STEP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 2ULL);
					/* 0x139c: shl    edi,0x10 */
					LOCAL_CALL_LOOP_STEP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 16ULL);
					/* 0x139f: xor    rdi,rdx */
					LOCAL_CALL_LOOP_STEP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_RDX, X86_WIDTH_64, X86_ALU_XOR, 0);
					/* 0x13a2: lea    rdx,[rax+rdi*1] */
					LOCAL_CALL_LOOP_STEP(x86_exec_lea, X86_OP_LEA, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
					/* 0x13a6: add    rdx,0x2 */
					LOCAL_CALL_LOOP_STEP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
					/* 0x13aa: rol    rdx,0x3 */
					LOCAL_CALL_LOOP_STEP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 3ULL);
					/* 0x13ae: movzx  edi,BYTE PTR [rsi+rcx*1+0x3] */
					LOCAL_CALL_LOOP_STEP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 3ULL);
					/* 0x13b3: shl    edi,0x18 */
					LOCAL_CALL_LOOP_STEP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 24ULL);
					/* 0x13b6: xor    rdi,rdx */
					LOCAL_CALL_LOOP_STEP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_RDX, X86_WIDTH_64, X86_ALU_XOR, 0);
					/* 0x13b9: lea    rdx,[rax+rdi*1] */
					LOCAL_CALL_LOOP_STEP(x86_exec_lea, X86_OP_LEA, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
					/* 0x13bd: add    rdx,0x3 */
					LOCAL_CALL_LOOP_STEP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 3ULL);
					/* 0x13c1: rol    rdx,0x4 */
					LOCAL_CALL_LOOP_STEP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 4ULL);
					/* 0x13c5: movzx  edi,BYTE PTR [rsi+rcx*1+0x4] */
					LOCAL_CALL_LOOP_STEP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 4ULL);
					/* 0x13ca: shl    rdi,0x20 */
					LOCAL_CALL_LOOP_STEP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
					/* 0x13ce: xor    rdi,rdx */
					LOCAL_CALL_LOOP_STEP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_RDX, X86_WIDTH_64, X86_ALU_XOR, 0);
					/* 0x13d1: lea    rdx,[rax+rdi*1] */
					LOCAL_CALL_LOOP_STEP(x86_exec_lea, X86_OP_LEA, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
					/* 0x13d5: add    rdx,0x4 */
					LOCAL_CALL_LOOP_STEP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
					/* 0x13d9: rol    rdx,0x5 */
					LOCAL_CALL_LOOP_STEP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 5ULL);
					/* 0x13dd: movzx  edi,BYTE PTR [rsi+rcx*1+0x5] */
					LOCAL_CALL_LOOP_STEP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 5ULL);
					/* 0x13e2: shl    rdi,0x28 */
					LOCAL_CALL_LOOP_STEP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 40ULL);
					/* 0x13e6: xor    rdi,rdx */
					LOCAL_CALL_LOOP_STEP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_RDX, X86_WIDTH_64, X86_ALU_XOR, 0);
					/* 0x13e9: lea    rdx,[rax+rdi*1] */
					LOCAL_CALL_LOOP_STEP(x86_exec_lea, X86_OP_LEA, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
					/* 0x13ed: add    rdx,0x5 */
					LOCAL_CALL_LOOP_STEP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 5ULL);
					/* 0x13f1: rol    rdx,0x6 */
					LOCAL_CALL_LOOP_STEP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 6ULL);
					/* 0x13f5: movzx  edi,BYTE PTR [rsi+rcx*1+0x6] */
					LOCAL_CALL_LOOP_STEP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 6ULL);
					/* 0x13fa: shl    rdi,0x30 */
					LOCAL_CALL_LOOP_STEP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 48ULL);
					/* 0x13fe: xor    rdi,rdx */
					LOCAL_CALL_LOOP_STEP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_RDX, X86_WIDTH_64, X86_ALU_XOR, 0);
					/* 0x1401: lea    rdx,[rax+rdi*1] */
					LOCAL_CALL_LOOP_STEP(x86_exec_lea, X86_OP_LEA, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
					/* 0x1405: add    rdx,0x6 */
					LOCAL_CALL_LOOP_STEP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 6ULL);
					/* 0x1409: rol    rdx,0x7 */
					LOCAL_CALL_LOOP_STEP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 7ULL);
					/* 0x140d: movzx  edi,BYTE PTR [rsi+rcx*1+0x7] */
					LOCAL_CALL_LOOP_STEP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 7ULL);
					/* 0x1412: shl    rdi,0x38 */
					LOCAL_CALL_LOOP_STEP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 56ULL);
					/* 0x1416: xor    rdi,rdx */
					LOCAL_CALL_LOOP_STEP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_RDX, X86_WIDTH_64, X86_ALU_XOR, 0);
					/* 0x1419: add    rax,rdi */
					LOCAL_CALL_LOOP_STEP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 0);
					/* 0x141c: add    rax,0x7 */
					LOCAL_CALL_LOOP_STEP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 7ULL);
					/* 0x1420: rol    rax,0x8 */
					LOCAL_CALL_LOOP_STEP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 8ULL);
					/* 0x1424: add    rax,QWORD PTR [rsi+rcx*1+0x8] */
					LOCAL_CALL_LOOP_STEP(x86_exec_alu_mem, X86_OP_ALU_MEM, X86_RAX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
					/* 0x1429: xor    rax,QWORD PTR [rsi+rcx*1+0x10] */
					LOCAL_CALL_LOOP_STEP(x86_exec_alu_mem, X86_OP_ALU_MEM, X86_RAX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 16ULL);
					/* 0x142e: pop    rbp */
					/* generated-C ABI: callee-save frame traffic handled by wrapper */
					/* 0x142f: ret */
					/* inline callee returns to structured caller */
				}
			} else {
				/* 0x11dd: mov    rsi,QWORD PTR [rbp-0x30] */
				LOCAL_CALL_LOOP_STEP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RSI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551568ULL);
				/* 0x11e1: mov    ecx,r14d */
				LOCAL_CALL_LOOP_STEP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RCX, X86_R14, X86_WIDTH_32, 0, 0);
				/* inline local_call_linear in the bpf_loop verifier frame */
				{
					/* 0x1230: push   rbp */
					/* generated-C ABI: callee-save frame traffic handled by wrapper */
					/* 0x1231: mov    rbp,rsp */
					/* generated-C ABI: callee-save frame traffic handled by wrapper */
					/* 0x1234: mov    r8d,ecx */
					LOCAL_CALL_LOOP_STEP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_R8, X86_RCX, X86_WIDTH_32, 0, 0);
					/* 0x1237: mov    ecx,edx */
					LOCAL_CALL_LOOP_STEP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RCX, X86_RDX, X86_WIDTH_32, 0, 0);
					/* 0x1239: mov    rax,QWORD PTR [rcx+rsi*1+0x8] */
					LOCAL_CALL_LOOP_STEP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 8ULL);
					/* 0x123e: lea    r9,[rax+rax*2] */
					LOCAL_CALL_LOOP_STEP(x86_exec_lea, X86_OP_LEA, X86_R9, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
					/* 0x1242: mov    edx,r8d */
					LOCAL_CALL_LOOP_STEP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RDX, X86_R8, X86_WIDTH_32, 0, 0);
					/* 0x1245: add    rdi,rdx */
					LOCAL_CALL_LOOP_STEP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 0);
					/* 0x1248: add    r9,rdi */
					LOCAL_CALL_LOOP_STEP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 0);
					/* 0x124b: add    r9,QWORD PTR [rcx+rsi*1+0x10] */
					LOCAL_CALL_LOOP_STEP(x86_exec_alu_mem, X86_OP_ALU_MEM, X86_R9, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
					/* 0x1250: shl    rdx,0xb */
					LOCAL_CALL_LOOP_STEP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 11ULL);
					/* 0x1254: add    rdx,r9 */
					LOCAL_CALL_LOOP_STEP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_R9, X86_WIDTH_64, X86_ALU_ADD, 0);
					/* 0x1257: and    r8d,0x7 */
					LOCAL_CALL_LOOP_STEP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 7ULL);
					/* 0x125b: lea    ecx,[r8+0x1] */
					LOCAL_CALL_LOOP_STEP(x86_exec_lea, X86_OP_LEA, X86_RCX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
					/* 0x125f: mov    rsi,rdx */
					LOCAL_CALL_LOOP_STEP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RSI, X86_RDX, X86_WIDTH_64, 0, 0);
					/* 0x1262: shl    rsi,cl */
					LOCAL_CALL_LOOP_STEP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RSI, X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 0);
					/* 0x1265: not    r8b */
					LOCAL_CALL_LOOP_STEP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_8, X86_ALU_NOT, 0);
					/* 0x1268: mov    ecx,r8d */
					LOCAL_CALL_LOOP_STEP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RCX, X86_R8, X86_WIDTH_32, 0, 0);
					/* 0x126b: shr    rdx,cl */
					LOCAL_CALL_LOOP_STEP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 0);
					/* 0x126e: or     rdx,rsi */
					LOCAL_CALL_LOOP_STEP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_OR, 0);
					/* 0x1271: xor    rdx,r9 */
					LOCAL_CALL_LOOP_STEP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_R9, X86_WIDTH_64, X86_ALU_XOR, 0);
					/* 0x1274: shr    rax,0x3 */
					LOCAL_CALL_LOOP_STEP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 3ULL);
					/* 0x1278: add    rax,rdx */
					LOCAL_CALL_LOOP_STEP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 0);
					/* 0x127b: pop    rbp */
					/* generated-C ABI: callee-save frame traffic handled by wrapper */
					/* 0x127c: ret */
					/* inline callee returns to structured caller */
				}
			}
		}
	}
	/* 0x118c: mov    ecx,ebx */
	LOCAL_CALL_LOOP_STEP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RCX, X86_RBX, X86_WIDTH_32, 0, 0);
	/* 0x118e: and    cl,0x38 */
	LOCAL_CALL_LOOP_STEP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_ALU_AND, 56ULL);
	/* 0x1191: shl    r15,cl */
	LOCAL_CALL_LOOP_STEP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 0);
	/* 0x1194: mov    edi,r14d */
	LOCAL_CALL_LOOP_STEP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RDI, X86_R14, X86_WIDTH_32, 0, 0);
	/* 0x1197: add    rdi,r15 */
	LOCAL_CALL_LOOP_STEP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD, 0);
	/* 0x119a: xor    rdi,rax */
	LOCAL_CALL_LOOP_STEP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
	/* 0x119d: add    rbx,0x8 */
	LOCAL_CALL_LOOP_STEP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
	/* 0x11a1: add    r12d,0x10 */
	LOCAL_CALL_LOOP_STEP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 16ULL);
	/* 0x11a5: add    r13,0x18 */
	LOCAL_CALL_LOOP_STEP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
	/* 0x11a9: cmp    rbx,0x80 */
	LOCAL_CALL_LOOP_STEP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 128ULL);
	/* 0x11b0: mov    rsi,QWORD PTR [rbp-0x38] */
	LOCAL_CALL_LOOP_STEP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RSI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551560ULL);
	/* 0x11b4: je     1211 <bpf_local_call_fanout_dispatch_xdp+0x111> */
	/* proof-loop branch handled by bpf_loop trip count */
	return 0;
}

SEC("xdp")
int bpf_local_call_fanout_dispatch_x86_vm_xdp(struct xdp_md *ctx)
{
	void *__x86_vm_data = (void *)(long)ctx->data;
	void *__x86_vm_data_end = (void *)(long)ctx->data_end;
	struct local_call_fanout_loop_ctx __x86_loop = {};
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
	/* 0x1171: jmp    11b6 <bpf_local_call_fanout_dispatch_xdp+0xb6> */
	/* proof-loop body handled by bpf_loop callback */
	__x86_loop.data = __x86_vm_data;
	__x86_loop.data_end = __x86_vm_data_end;
	if (bpf_loop(16, local_call_fanout_cb, &__x86_loop, 0) < 0)
		return XDP_ABORTED;
	if (__x86_loop.failed)
		return XDP_ABORTED;
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
	#undef __x86_vm_insn
	#undef __x86_vm_state
	return XDP_ABORTED;
}

X86_VM_LICENSE();
