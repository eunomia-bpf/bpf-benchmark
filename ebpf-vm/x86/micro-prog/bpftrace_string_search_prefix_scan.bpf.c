#define X86_VM_ENABLE_STACK 1
#define X86_VM_ENABLE_STACK_SHALLOW 1
#include "../x86_vm_bpf.h"

SEC("xdp")
int bpftrace_string_search_prefix_scan_x86_vm_xdp(struct xdp_md *ctx)
{
	void *__x86_vm_data = (void *)(long)ctx->data;
	void *__x86_vm_data_end = (void *)(long)ctx->data_end;
	struct x86_vm_bpftrace_scan_ctx __x86_scan = {};
	#define __x86_vm_state __x86_scan.state
	x86_init_state(&__x86_vm_state, (void *)ctx);
x86_l_1100:
	/* 0x1100: mov    rcx,QWORD PTR [rdi] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1103:
	/* 0x1103: mov    rdx,QWORD PTR [rdi+0x8] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1107:
	/* 0x1107: xor    eax,eax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1109:
	/* 0x1109: cmp    rcx,rdx */
	X86_VM_RUN_OP(x86_exec_cmp_reg, X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_110c:
	/* 0x110c: ja     12c9 <bpftrace_string_search_prefix_scan_xdp+0x1c9> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_12c9;
x86_l_1112:
	/* 0x1112: lea    rsi,[rcx+0x8] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1116:
	/* 0x1116: cmp    rsi,rdx */
	X86_VM_RUN_OP(x86_exec_cmp_reg, X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_1119:
	/* 0x1119: ja     12c9 <bpftrace_string_search_prefix_scan_xdp+0x1c9> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_12c9;
x86_l_111f:
	/* 0x111f: lea    rsi,[rcx+0x78] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1123:
	/* 0x1123: cmp    rsi,rdx */
	X86_VM_RUN_OP(x86_exec_cmp_reg, X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_1126:
	/* 0x1126: ja     12c9 <bpftrace_string_search_prefix_scan_xdp+0x1c9> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_12c9;
x86_l_112c:
	/* 0x112c: push   rbp */
	X86_VM_RUN_OP(x86_exec_push, X86_OP_PUSH, X86_REG_NONE, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_112d:
	/* 0x112d: mov    rbp,rsp */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RBP, X86_RSP, X86_WIDTH_64, 0, 0);
x86_l_1130:
	/* 0x1130: push   rbx */
	X86_VM_RUN_OP(x86_exec_push, X86_OP_PUSH, X86_REG_NONE, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_1131:
	/* 0x1131: mov    edi,DWORD PTR [rcx+0x8] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1134:
	/* 0x1134: movzx  edx,BYTE PTR [rcx+0x70] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 112ULL);
x86_l_1138:
	/* 0x1138: xor    eax,eax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_113a:
	/* 0x113a: mov    r8d,0x0 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, 0, 0ULL);
x86_l_1140:
	/* 0x1140: test   dl,dl */
	X86_VM_RUN_OP(x86_exec_test_reg, X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8, 0, 0);
x86_l_1142:
	/* 0x1142: je     11a6 <bpftrace_string_search_prefix_scan_xdp+0xa6> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_E))
		goto x86_l_11a6;
x86_l_1144:
	/* 0x1144: cmp    BYTE PTR [rcx+0x71],0x0 */
	X86_VM_RUN_OP(x86_exec_cmp_mem_imm, X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 485331304448ULL);
x86_l_1148:
	/* 0x1148: je     1178 <bpftrace_string_search_prefix_scan_xdp+0x78> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_E))
		goto x86_l_1178;
x86_l_114a:
	/* 0x114a: cmp    BYTE PTR [rcx+0x72],0x0 */
	X86_VM_RUN_OP(x86_exec_cmp_mem_imm, X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 489626271744ULL);
x86_l_114e:
	/* 0x114e: je     1180 <bpftrace_string_search_prefix_scan_xdp+0x80> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_E))
		goto x86_l_1180;
x86_l_1150:
	/* 0x1150: cmp    BYTE PTR [rcx+0x73],0x0 */
	X86_VM_RUN_OP(x86_exec_cmp_mem_imm, X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 493921239040ULL);
x86_l_1154:
	/* 0x1154: je     1188 <bpftrace_string_search_prefix_scan_xdp+0x88> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_E))
		goto x86_l_1188;
x86_l_1156:
	/* 0x1156: cmp    BYTE PTR [rcx+0x74],0x0 */
	X86_VM_RUN_OP(x86_exec_cmp_mem_imm, X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 498216206336ULL);
x86_l_115a:
	/* 0x115a: je     1190 <bpftrace_string_search_prefix_scan_xdp+0x90> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_E))
		goto x86_l_1190;
x86_l_115c:
	/* 0x115c: cmp    BYTE PTR [rcx+0x75],0x0 */
	X86_VM_RUN_OP(x86_exec_cmp_mem_imm, X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 502511173632ULL);
x86_l_1160:
	/* 0x1160: je     1198 <bpftrace_string_search_prefix_scan_xdp+0x98> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_E))
		goto x86_l_1198;
x86_l_1162:
	/* 0x1162: cmp    BYTE PTR [rcx+0x76],0x0 */
	X86_VM_RUN_OP(x86_exec_cmp_mem_imm, X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 506806140928ULL);
x86_l_1166:
	/* 0x1166: je     11a0 <bpftrace_string_search_prefix_scan_xdp+0xa0> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_E))
		goto x86_l_11a0;
x86_l_1168:
	/* 0x1168: cmp    BYTE PTR [rcx+0x77],0x1 */
	X86_VM_RUN_OP(x86_exec_cmp_mem_imm, X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 511101108225ULL);
x86_l_116c:
	/* 0x116c: mov    r8d,0x8 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_1172:
	/* 0x1172: sbb    r8d,0x0 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SBB, 0ULL);
x86_l_1176:
	/* 0x1176: jmp    11a6 <bpftrace_string_search_prefix_scan_xdp+0xa6> */
	goto x86_l_11a6;
x86_l_1178:
	/* 0x1178: mov    r8d,0x1 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_117e:
	/* 0x117e: jmp    11a6 <bpftrace_string_search_prefix_scan_xdp+0xa6> */
	goto x86_l_11a6;
x86_l_1180:
	/* 0x1180: mov    r8d,0x2 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_1186:
	/* 0x1186: jmp    11a6 <bpftrace_string_search_prefix_scan_xdp+0xa6> */
	goto x86_l_11a6;
x86_l_1188:
	/* 0x1188: mov    r8d,0x3 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, 0, 3ULL);
x86_l_118e:
	/* 0x118e: jmp    11a6 <bpftrace_string_search_prefix_scan_xdp+0xa6> */
	goto x86_l_11a6;
x86_l_1190:
	/* 0x1190: mov    r8d,0x4 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_1196:
	/* 0x1196: jmp    11a6 <bpftrace_string_search_prefix_scan_xdp+0xa6> */
	goto x86_l_11a6;
x86_l_1198:
	/* 0x1198: mov    r8d,0x5 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, 0, 5ULL);
x86_l_119e:
	/* 0x119e: jmp    11a6 <bpftrace_string_search_prefix_scan_xdp+0xa6> */
	goto x86_l_11a6;
x86_l_11a0:
	/* 0x11a0: mov    r8d,0x6 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, 0, 6ULL);
x86_l_11a6:
	/* 0x11a6: cmp    edi,0x60 */
	X86_VM_RUN_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 96ULL);
x86_l_11a9:
	/* 0x11a9: ja     12c7 <bpftrace_string_search_prefix_scan_xdp+0x1c7> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_12c7;
x86_l_11af:
	/* 0x11af: mov    esi,DWORD PTR [rcx+0xc] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_11b2:
	/* 0x11b2: cmp    esi,r8d */
	X86_VM_RUN_OP(x86_exec_cmp_reg, X86_OP_CMP_REG, X86_RSI, X86_R8, X86_WIDTH_32, 0, 0);
x86_l_11b5:
	/* 0x11b5: jne    12c7 <bpftrace_string_search_prefix_scan_xdp+0x1c7> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_12c7;
x86_l_11bb:
	/* 0x11bb: test   dl,dl */
	X86_VM_RUN_OP(x86_exec_test_reg, X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8, 0, 0);
x86_l_11bd:
	/* 0x11bd: je     12c7 <bpftrace_string_search_prefix_scan_xdp+0x1c7> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_E))
		goto x86_l_12c7;
x86_l_11c3:
	/* 0x11c3: movabs rax,0x4f82338baed89116 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, 0, 5729198350995591446ULL);
x86_l_11cd:
	/* 0x11cd: mov    r9d,edi */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_R9, X86_RDI, X86_WIDTH_32, 0, 0);
x86_l_11d0:
	/* 0x11d0: lea    r10d,[rsi+0x3] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_R10, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 3ULL);
x86_l_11d4:
	/* 0x11d4: movabs rdi,0xd1b54a32d192ed03 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, 15111065706836454659ULL);
x86_l_11de:
	/* 0x11de: add    rdi,r10 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_R10, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_11e1:
	/* 0x11e1: xor    r8d,r8d */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_11e4:
	/* 0x11e0..0x12bc: C-authored bpftrace string-search template */
	__x86_scan.data = __x86_vm_data;
	__x86_scan.data_end = __x86_vm_data_end;
	if (x86_vm_run_bpftrace_string_search_prefix_scan(&__x86_scan) < 0)
		return XDP_ABORTED;
x86_l_12bf:
	/* 0x12bf: mov    QWORD PTR [rcx],rax */
	X86_VM_RUN_OP(x86_exec_mov_store_reg, X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12c2:
	/* 0x12c2: mov    eax,0x2 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_12c7:
	/* 0x12c7: pop    rbx */
	X86_VM_RUN_OP(x86_exec_pop, X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_12c8:
	/* 0x12c8: pop    rbp */
	X86_VM_RUN_OP(x86_exec_pop, X86_OP_POP, X86_RBP, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_12c9:
	/* 0x12c9: ret */
	X86_VM_RET_RAX();
	#undef __x86_vm_state
	return XDP_ABORTED;
}

X86_VM_LICENSE();
