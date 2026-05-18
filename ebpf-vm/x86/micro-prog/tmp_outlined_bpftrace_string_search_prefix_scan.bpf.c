#define X86_VM_ENABLE_STACK 1
#include "../x86_vm_bpf.h"

static __noinline int x86_loop_11f0_1209_body(__u32 __x86_loop_index, struct x86_vm_loop_ctx *loop)
{
	void *__x86_vm_data = loop->data;
	void *__x86_vm_data_end = loop->data_end;
	struct x86_insn __x86_vm_insn = {};
	#define __x86_vm_state loop->state

	(void)__x86_loop_index;
	goto x86_l_1209;
x86_l_11f0:
	/* 0x11f0: test   r11b,r11b */
	X86_VM_LOOP_OP(x86_exec_test_reg, X86_OP_TEST_REG, X86_R11, X86_R11, X86_WIDTH_8, 0, 0);
x86_l_11f3:
	/* 0x11f3: je     12a8 <bpftrace_string_search_prefix_scan_xdp+0x1a8> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_E)) {
		loop->next = 0x12a8;
		return 1;
	}
x86_l_11f9:
	/* 0x11f9: inc    r8 */
	X86_VM_LOOP_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_11fc:
	/* 0x11fc: add    rdi,r10 */
	X86_VM_LOOP_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_R10, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_11ff:
	/* 0x11ff: cmp    r8,0x59 */
	X86_VM_LOOP_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_64, 0, 89ULL);
x86_l_1203:
	/* 0x1203: je     12bf <bpftrace_string_search_prefix_scan_xdp+0x1bf> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_E)) {
		loop->next = 0x12bf;
		return 1;
	}
	return 0;
x86_l_1209:
	/* 0x1209: lea    r11,[rsi+r8*1] */
	X86_VM_LOOP_OP(x86_exec_lea, X86_OP_LEA, X86_R11, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_R8, 0), 0ULL);
x86_l_120d:
	/* 0x120d: cmp    r11,r9 */
	X86_VM_LOOP_OP(x86_exec_cmp_reg, X86_OP_CMP_REG, X86_R11, X86_R9, X86_WIDTH_64, 0, 0);
x86_l_1210:
	/* 0x1210: ja     11f9 <bpftrace_string_search_prefix_scan_xdp+0xf9> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_11f9;
x86_l_1212:
	/* 0x1212: test   rsi,rsi */
	X86_VM_LOOP_OP(x86_exec_test_reg, X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_1215:
	/* 0x1215: je     12a8 <bpftrace_string_search_prefix_scan_xdp+0x1a8> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_E)) {
		loop->next = 0x12a8;
		return 1;
	}
x86_l_121b:
	/* 0x121b: movzx  r11d,BYTE PTR [rcx+r8*1+0x10] */
	X86_VM_LOOP_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R11, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R8, 0, X86_WIDTH_8), 16ULL);
x86_l_1221:
	/* 0x1221: xor    r11b,dl */
	X86_VM_LOOP_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R11, X86_RDX, X86_WIDTH_8, X86_ALU_XOR, 0);
x86_l_1224:
	/* 0x1224: cmp    esi,0x2 */
	X86_VM_LOOP_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_1227:
	/* 0x1227: jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_B))
		goto x86_l_11f0;
x86_l_1229:
	/* 0x1229: movzx  ebx,BYTE PTR [rcx+0x71] */
	X86_VM_LOOP_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RBX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 113ULL);
x86_l_122d:
	/* 0x122d: xor    bl,BYTE PTR [rcx+r8*1+0x11] */
	X86_VM_LOOP_OP(x86_exec_alu_mem, X86_OP_ALU_MEM, X86_RBX, X86_RCX, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_R8, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 17ULL);
x86_l_1232:
	/* 0x1232: or     r11b,bl */
	X86_VM_LOOP_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R11, X86_RBX, X86_WIDTH_8, X86_ALU_OR, 0);
x86_l_1235:
	/* 0x1235: cmp    esi,0x3 */
	X86_VM_LOOP_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 3ULL);
x86_l_1238:
	/* 0x1238: jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_B))
		goto x86_l_11f0;
x86_l_123a:
	/* 0x123a: movzx  ebx,BYTE PTR [rcx+0x72] */
	X86_VM_LOOP_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RBX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 114ULL);
x86_l_123e:
	/* 0x123e: xor    bl,BYTE PTR [rcx+r8*1+0x12] */
	X86_VM_LOOP_OP(x86_exec_alu_mem, X86_OP_ALU_MEM, X86_RBX, X86_RCX, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_R8, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 18ULL);
x86_l_1243:
	/* 0x1243: or     r11b,bl */
	X86_VM_LOOP_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R11, X86_RBX, X86_WIDTH_8, X86_ALU_OR, 0);
x86_l_1246:
	/* 0x1246: cmp    esi,0x4 */
	X86_VM_LOOP_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_1249:
	/* 0x1249: jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_B))
		goto x86_l_11f0;
x86_l_124b:
	/* 0x124b: movzx  ebx,BYTE PTR [rcx+0x73] */
	X86_VM_LOOP_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RBX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 115ULL);
x86_l_124f:
	/* 0x124f: xor    bl,BYTE PTR [rcx+r8*1+0x13] */
	X86_VM_LOOP_OP(x86_exec_alu_mem, X86_OP_ALU_MEM, X86_RBX, X86_RCX, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_R8, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 19ULL);
x86_l_1254:
	/* 0x1254: or     r11b,bl */
	X86_VM_LOOP_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R11, X86_RBX, X86_WIDTH_8, X86_ALU_OR, 0);
x86_l_1257:
	/* 0x1257: cmp    esi,0x5 */
	X86_VM_LOOP_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 5ULL);
x86_l_125a:
	/* 0x125a: jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_B))
		goto x86_l_11f0;
x86_l_125c:
	/* 0x125c: movzx  ebx,BYTE PTR [rcx+0x74] */
	X86_VM_LOOP_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RBX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 116ULL);
x86_l_1260:
	/* 0x1260: xor    bl,BYTE PTR [rcx+r8*1+0x14] */
	X86_VM_LOOP_OP(x86_exec_alu_mem, X86_OP_ALU_MEM, X86_RBX, X86_RCX, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_R8, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 20ULL);
x86_l_1265:
	/* 0x1265: or     r11b,bl */
	X86_VM_LOOP_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R11, X86_RBX, X86_WIDTH_8, X86_ALU_OR, 0);
x86_l_1268:
	/* 0x1268: cmp    esi,0x6 */
	X86_VM_LOOP_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 6ULL);
x86_l_126b:
	/* 0x126b: jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_B))
		goto x86_l_11f0;
x86_l_126d:
	/* 0x126d: movzx  ebx,BYTE PTR [rcx+0x75] */
	X86_VM_LOOP_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RBX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 117ULL);
x86_l_1271:
	/* 0x1271: xor    bl,BYTE PTR [rcx+r8*1+0x15] */
	X86_VM_LOOP_OP(x86_exec_alu_mem, X86_OP_ALU_MEM, X86_RBX, X86_RCX, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_R8, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 21ULL);
x86_l_1276:
	/* 0x1276: or     r11b,bl */
	X86_VM_LOOP_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R11, X86_RBX, X86_WIDTH_8, X86_ALU_OR, 0);
x86_l_1279:
	/* 0x1279: cmp    esi,0x7 */
	X86_VM_LOOP_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 7ULL);
x86_l_127c:
	/* 0x127c: jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_B))
		goto x86_l_11f0;
x86_l_1282:
	/* 0x1282: movzx  ebx,BYTE PTR [rcx+0x76] */
	X86_VM_LOOP_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RBX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 118ULL);
x86_l_1286:
	/* 0x1286: xor    bl,BYTE PTR [rcx+r8*1+0x16] */
	X86_VM_LOOP_OP(x86_exec_alu_mem, X86_OP_ALU_MEM, X86_RBX, X86_RCX, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_R8, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 22ULL);
x86_l_128b:
	/* 0x128b: or     r11b,bl */
	X86_VM_LOOP_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R11, X86_RBX, X86_WIDTH_8, X86_ALU_OR, 0);
x86_l_128e:
	/* 0x128e: cmp    esi,0x8 */
	X86_VM_LOOP_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_1291:
	/* 0x1291: jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_B))
		goto x86_l_11f0;
x86_l_1297:
	/* 0x1297: movzx  ebx,BYTE PTR [rcx+0x77] */
	X86_VM_LOOP_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RBX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 119ULL);
x86_l_129b:
	/* 0x129b: xor    bl,BYTE PTR [rcx+r8*1+0x17] */
	X86_VM_LOOP_OP(x86_exec_alu_mem, X86_OP_ALU_MEM, X86_RBX, X86_RCX, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_R8, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 23ULL);
x86_l_12a0:
	/* 0x12a0: or     r11b,bl */
	X86_VM_LOOP_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R11, X86_RBX, X86_WIDTH_8, X86_ALU_OR, 0);
x86_l_12a3:
	/* 0x12a3: jmp    11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0> */
	goto x86_l_11f0;
	#undef __x86_vm_state
	return 0;
}

static long x86_loop_11f0_1209_cb(__u32 __x86_loop_index, void *ctx)
{
	struct x86_vm_loop_ctx *loop = ctx;
	if (loop->failed || loop->done || loop->next)
		return 1;
	return x86_loop_11f0_1209_body(__x86_loop_index, loop);
}

SEC("xdp")
int bpftrace_string_search_prefix_scan_x86_vm_xdp(struct xdp_md *ctx)
{
	void *__x86_vm_data = (void *)(long)ctx->data;
	void *__x86_vm_data_end = (void *)(long)ctx->data_end;
	struct x86_vm_loop_ctx __x86_loop = {};
	struct x86_insn __x86_vm_insn = {};
	#define __x86_vm_state __x86_loop.state
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
	/* 0x11e4: jmp    1209 <bpftrace_string_search_prefix_scan_xdp+0x109> */
	/* verifier loop lowering: bpf_loop callback preserves x86 steps */
	(&__x86_loop)->failed = 0;
	(&__x86_loop)->done = 0;
	(&__x86_loop)->next = 0;
	(&__x86_loop)->data = __x86_vm_data;
	(&__x86_loop)->data_end = __x86_vm_data_end;
	if (bpf_loop(89, x86_loop_11f0_1209_cb, (&__x86_loop), 0) < 0) {
		(&__x86_loop)->failed = __LINE__;
		return XDP_ABORTED;
	}
	if ((&__x86_loop)->failed)
		return XDP_ABORTED;
	if ((&__x86_loop)->done)
		X86_VM_RET_RAX();
	if ((&__x86_loop)->next == 0x12a8) {
		goto x86_l_12a8;
	}
	if ((&__x86_loop)->next == 0x12bf) {
		goto x86_l_12bf;
	}
	return XDP_ABORTED;
x86_l_11e6:
	/* 0x11e6: cs nop WORD PTR [rax+rax*1+0x0] */
	X86_VM_RUN_OP(x86_exec_nop, X86_OP_NOP, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_12a8:
	/* 0x12a8: cmp    r8,0x60 */
	X86_VM_RUN_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_64, 0, 96ULL);
x86_l_12ac:
	/* 0x12ac: je     12bf <bpftrace_string_search_prefix_scan_xdp+0x1bf> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_E))
		goto x86_l_12bf;
x86_l_12ae:
	/* 0x12ae: shl    rsi,0x20 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_12b2:
	/* 0x12b2: add    rsi,r8 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RSI, X86_R8, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_12b5:
	/* 0x12b5: rol    rsi,0x3 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 3ULL);
x86_l_12b9:
	/* 0x12b9: xor    rdi,rsi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_12bc:
	/* 0x12bc: mov    rax,rdi */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RAX, X86_RDI, X86_WIDTH_64, 0, 0);
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
