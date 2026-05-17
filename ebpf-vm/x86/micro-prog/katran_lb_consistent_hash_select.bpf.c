#define X86_VM_ENABLE_STACK 1
#define X86_VM_ENABLE_STACK_SLOT7 1
#include "../x86_vm_bpf.h"

SEC("xdp")
int katran_lb_consistent_hash_select_x86_vm_xdp(struct xdp_md *ctx)
{
	X86_VM_DECLARE_XDP(ctx);
x86_l_1100:
	/* 0x1100: push   rbp */
	X86_VM_RUN_OP(x86_exec_push, X86_OP_PUSH, X86_REG_NONE, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_1101:
	/* 0x1101: mov    rbp,rsp */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RBP, X86_RSP, X86_WIDTH_64, 0, 0);
x86_l_1104:
	/* 0x1104: push   r15 */
	X86_VM_RUN_OP(x86_exec_push, X86_OP_PUSH, X86_REG_NONE, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_1106:
	/* 0x1106: push   r14 */
	X86_VM_RUN_OP(x86_exec_push, X86_OP_PUSH, X86_REG_NONE, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_1108:
	/* 0x1108: push   r13 */
	X86_VM_RUN_OP(x86_exec_push, X86_OP_PUSH, X86_REG_NONE, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_110a:
	/* 0x110a: push   r12 */
	X86_VM_RUN_OP(x86_exec_push, X86_OP_PUSH, X86_REG_NONE, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_110c:
	/* 0x110c: push   rbx */
	X86_VM_RUN_OP(x86_exec_push, X86_OP_PUSH, X86_REG_NONE, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_110d:
	/* 0x110d: mov    rcx,QWORD PTR [rdi] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1110:
	/* 0x1110: mov    rbx,QWORD PTR [rdi+0x8] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RBX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1114:
	/* 0x1114: xor    eax,eax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1116:
	/* 0x1116: cmp    rcx,rbx */
	X86_VM_RUN_OP(x86_exec_cmp_reg, X86_OP_CMP_REG, X86_RCX, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_1119:
	/* 0x1119: ja     1614 <katran_lb_consistent_hash_select_xdp+0x514> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_1614;
x86_l_111f:
	/* 0x111f: lea    rsi,[rcx+0x8] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1123:
	/* 0x1123: cmp    rsi,rbx */
	X86_VM_RUN_OP(x86_exec_cmp_reg, X86_OP_CMP_REG, X86_RSI, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_1126:
	/* 0x1126: ja     1614 <katran_lb_consistent_hash_select_xdp+0x514> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_1614;
x86_l_112c:
	/* 0x112c: lea    rdx,[rcx+0x16] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_1130:
	/* 0x1130: cmp    rdx,rbx */
	X86_VM_RUN_OP(x86_exec_cmp_reg, X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_1133:
	/* 0x1133: ja     1614 <katran_lb_consistent_hash_select_xdp+0x514> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_1614;
x86_l_1139:
	/* 0x1139: movabs rax,0x9e3779b97f4a7c15 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, 0, 11400714819323198485ULL);
x86_l_1143:
	/* 0x1143: mov    r10,rbx */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_R10, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_1146:
	/* 0x1146: sub    r10,rsi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R10, X86_RSI, X86_WIDTH_64, X86_ALU_SUB, 0);
x86_l_1149:
	/* 0x1149: movzx  esi,WORD PTR [rcx+0x14] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 20ULL);
x86_l_114d:
	/* 0x114d: cmp    esi,0xdd86 */
	X86_VM_RUN_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 56710ULL);
x86_l_1153:
	/* 0x1153: je     11e9 <katran_lb_consistent_hash_select_xdp+0xe9> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_E))
		goto x86_l_11e9;
x86_l_1159:
	/* 0x1159: cmp    esi,0x8 */
	X86_VM_RUN_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_115c:
	/* 0x115c: jne    1218 <katran_lb_consistent_hash_select_xdp+0x118> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_1218;
x86_l_1162:
	/* 0x1162: lea    rsi,[rcx+0x2a] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_1166:
	/* 0x1166: mov    r9d,0x1 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_116c:
	/* 0x116c: cmp    rsi,rbx */
	X86_VM_RUN_OP(x86_exec_cmp_reg, X86_OP_CMP_REG, X86_RSI, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_116f:
	/* 0x116f: ja     15ed <katran_lb_consistent_hash_select_xdp+0x4ed> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_15ed;
x86_l_1175:
	/* 0x1175: movzx  edx,BYTE PTR [rdx] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1178:
	/* 0x1178: and    dl,0xf */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_ALU_AND, 15ULL);
x86_l_117b:
	/* 0x117b: cmp    dl,0x5 */
	X86_VM_RUN_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, 0, 5ULL);
x86_l_117e:
	/* 0x117e: jne    15ed <katran_lb_consistent_hash_select_xdp+0x4ed> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_15ed;
x86_l_1184:
	/* 0x1184: movzx  edx,BYTE PTR [rcx+0x1c] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_1188:
	/* 0x1188: movzx  esi,BYTE PTR [rcx+0x1d] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_118c:
	/* 0x118c: and    edx,0x3f */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 63ULL);
x86_l_118f:
	/* 0x118f: or     dx,si */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RSI, X86_WIDTH_16, X86_ALU_OR, 0);
x86_l_1192:
	/* 0x1192: jne    15ed <katran_lb_consistent_hash_select_xdp+0x4ed> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_15ed;
x86_l_1198:
	/* 0x1198: movzx  r15d,BYTE PTR [rcx+0x1f] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R15, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_119d:
	/* 0x119d: mov    esi,0x2 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_11a2:
	/* 0x11a2: cmp    r15d,0x1 */
	X86_VM_RUN_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_11a6:
	/* 0x11a6: je     1236 <katran_lb_consistent_hash_select_xdp+0x136> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_E))
		goto x86_l_1236;
x86_l_11ac:
	/* 0x11ac: movzx  edi,BYTE PTR [rcx+0x17] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 23ULL);
x86_l_11b0:
	/* 0x11b0: movzx  r14d,WORD PTR [rcx+0x18] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 24ULL);
x86_l_11b5:
	/* 0x11b5: movzx  r11d,WORD PTR [rcx+0x22] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R11, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_11ba:
	/* 0x11ba: movzx  r8d,BYTE PTR [rcx+0x24] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R8, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 36ULL);
x86_l_11bf:
	/* 0x11bf: movzx  edx,BYTE PTR [rcx+0x25] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 37ULL);
x86_l_11c3:
	/* 0x11c3: mov    r12d,DWORD PTR [rcx+0x26] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_11c7:
	/* 0x11c7: cmp    r15d,0x11 */
	X86_VM_RUN_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_11cb:
	/* 0x11cb: je     15e4 <katran_lb_consistent_hash_select_xdp+0x4e4> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_E))
		goto x86_l_15e4;
x86_l_11d1:
	/* 0x11d1: cmp    r15d,0x6 */
	X86_VM_RUN_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 6ULL);
x86_l_11d5:
	/* 0x11d5: jne    1236 <katran_lb_consistent_hash_select_xdp+0x136> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_1236;
x86_l_11d7:
	/* 0x11d7: lea    r13,[rcx+0x3e] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_R13, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 62ULL);
x86_l_11db:
	/* 0x11db: cmp    r13,rbx */
	X86_VM_RUN_OP(x86_exec_cmp_reg, X86_OP_CMP_REG, X86_R13, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_11de:
	/* 0x11de: ja     15ed <katran_lb_consistent_hash_select_xdp+0x4ed> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_15ed;
x86_l_11e4:
	/* 0x11e4: jmp    161f <katran_lb_consistent_hash_select_xdp+0x51f> */
	goto x86_l_161f;
x86_l_11e9:
	/* 0x11e9: lea    rdx,[rcx+0x3e] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 62ULL);
x86_l_11ed:
	/* 0x11ed: mov    r9d,0x1 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_11f3:
	/* 0x11f3: cmp    rdx,rbx */
	X86_VM_RUN_OP(x86_exec_cmp_reg, X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_11f6:
	/* 0x11f6: ja     15ed <katran_lb_consistent_hash_select_xdp+0x4ed> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_15ed;
x86_l_11fc:
	/* 0x11fc: movzx  r13d,BYTE PTR [rcx+0x1c] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_1201:
	/* 0x1201: cmp    r13d,0x2c */
	X86_VM_RUN_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, 0, 44ULL);
x86_l_1205:
	/* 0x1205: je     15ed <katran_lb_consistent_hash_select_xdp+0x4ed> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_E))
		goto x86_l_15ed;
x86_l_120b:
	/* 0x120b: cmp    r13d,0x3a */
	X86_VM_RUN_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, 0, 58ULL);
x86_l_120f:
	/* 0x120f: jne    1241 <katran_lb_consistent_hash_select_xdp+0x141> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_1241;
x86_l_1211:
	/* 0x1211: mov    esi,0x2 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_1216:
	/* 0x1216: jmp    1236 <katran_lb_consistent_hash_select_xdp+0x136> */
	goto x86_l_1236;
x86_l_1218:
	/* 0x1218: add    r10,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R10, X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_121b:
	/* 0x121b: mov    rdx,r10 */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RDX, X86_R10, X86_WIDTH_64, 0, 0);
x86_l_121e:
	/* 0x121e: shl    rdx,0x6 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 6ULL);
x86_l_1222:
	/* 0x1222: add    rdx,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1225:
	/* 0x1225: mov    rsi,r10 */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RSI, X86_R10, X86_WIDTH_64, 0, 0);
x86_l_1228:
	/* 0x1228: shr    rsi,0x2 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 2ULL);
x86_l_122c:
	/* 0x122c: add    rsi,rdx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RSI, X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_122f:
	/* 0x122f: add    rsi,0x2 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_1233:
	/* 0x1233: xor    rsi,r10 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RSI, X86_R10, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1236:
	/* 0x1236: mov    r9d,0x2 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_123c:
	/* 0x123c: jmp    15f2 <katran_lb_consistent_hash_select_xdp+0x4f2> */
	goto x86_l_15f2;
x86_l_1241:
	/* 0x1241: movzx  r11d,BYTE PTR [rcx+0x16] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R11, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 22ULL);
x86_l_1246:
	/* 0x1246: movzx  r12d,BYTE PTR [rcx+0x17] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 23ULL);
x86_l_124b:
	/* 0x124b: movzx  r15d,WORD PTR [rcx+0x1a] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R15, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 26ULL);
x86_l_1250:
	/* 0x1250: mov    edx,DWORD PTR [rcx+0x1e] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_1253:
	/* 0x1253: mov    esi,DWORD PTR [rcx+0x26] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_1256:
	/* 0x1256: mov    QWORD PTR [rbp-0x38],rsi */
	X86_VM_RUN_OP(x86_exec_mov_store_reg, X86_OP_MOV_STORE_REG, X86_RBP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551560ULL);
x86_l_125a:
	/* 0x125a: mov    r14d,DWORD PTR [rcx+0x2a] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_125e:
	/* 0x125e: mov    edi,DWORD PTR [rcx+0x2e] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 46ULL);
x86_l_1261:
	/* 0x1261: mov    r8d,0xdeadc0ff */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, 0, 3735929087ULL);
x86_l_1267:
	/* 0x1267: add    r8d,DWORD PTR [rcx+0x22] */
	X86_VM_RUN_OP(x86_exec_alu_mem, X86_OP_ALU_MEM, X86_R8, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 34ULL);
x86_l_126b:
	/* 0x126b: mov    esi,0x2 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_1270:
	/* 0x1270: cmp    r13d,0x11 */
	X86_VM_RUN_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_1274:
	/* 0x1274: je     128f <katran_lb_consistent_hash_select_xdp+0x18f> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_E))
		goto x86_l_128f;
x86_l_1276:
	/* 0x1276: cmp    r13d,0x6 */
	X86_VM_RUN_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, 0, 6ULL);
x86_l_127a:
	/* 0x127a: jne    1236 <katran_lb_consistent_hash_select_xdp+0x136> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_1236;
x86_l_127c:
	/* 0x127c: mov    QWORD PTR [rbp-0x30],rdx */
	X86_VM_RUN_OP(x86_exec_mov_store_reg, X86_OP_MOV_STORE_REG, X86_RBP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551568ULL);
x86_l_1280:
	/* 0x1280: lea    rdx,[rcx+0x52] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 82ULL);
x86_l_1284:
	/* 0x1284: cmp    rdx,rbx */
	X86_VM_RUN_OP(x86_exec_cmp_reg, X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_1287:
	/* 0x1287: ja     15ed <katran_lb_consistent_hash_select_xdp+0x4ed> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_15ed;
x86_l_128d:
	/* 0x128d: jmp    12a0 <katran_lb_consistent_hash_select_xdp+0x1a0> */
	goto x86_l_12a0;
x86_l_128f:
	/* 0x128f: mov    QWORD PTR [rbp-0x30],rdx */
	X86_VM_RUN_OP(x86_exec_mov_store_reg, X86_OP_MOV_STORE_REG, X86_RBP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551568ULL);
x86_l_1293:
	/* 0x1293: lea    rdx,[rcx+0x46] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 70ULL);
x86_l_1297:
	/* 0x1297: cmp    rdx,rbx */
	X86_VM_RUN_OP(x86_exec_cmp_reg, X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_129a:
	/* 0x129a: ja     15ed <katran_lb_consistent_hash_select_xdp+0x4ed> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_15ed;
x86_l_12a0:
	/* 0x12a0: cmp    r13d,0x6 */
	X86_VM_RUN_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, 0, 6ULL);
x86_l_12a4:
	/* 0x12a4: jne    1236 <katran_lb_consistent_hash_select_xdp+0x136> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_1236;
x86_l_12a6:
	/* 0x12a6: cmp    edi,0x101640a */
	X86_VM_RUN_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 16868362ULL);
x86_l_12ac:
	/* 0x12ac: jne    1236 <katran_lb_consistent_hash_select_xdp+0x136> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_1236;
x86_l_12ae:
	/* 0x12ae: movzx  edx,WORD PTR [rcx+0x40] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 64ULL);
x86_l_12b2:
	/* 0x12b2: mov    r9d,0x2 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_12b8:
	/* 0x12b8: cmp    edx,0x901f */
	X86_VM_RUN_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 36895ULL);
x86_l_12be:
	/* 0x12be: jne    15f2 <katran_lb_consistent_hash_select_xdp+0x4f2> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_15f2;
x86_l_12c4:
	/* 0x12c4: mov    esi,0x1 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_12c9:
	/* 0x12c9: mov    r9d,0x1 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_12cf:
	/* 0x12cf: cmp    r10,0x5ea */
	X86_VM_RUN_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_64, 0, 1514ULL);
x86_l_12d6:
	/* 0x12d6: jg     15f2 <katran_lb_consistent_hash_select_xdp+0x4f2> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_G))
		goto x86_l_15f2;
x86_l_12dc:
	/* 0x12dc: shr    r12b,0x4 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_ALU_SHR, 4ULL);
x86_l_12e0:
	/* 0x12e0: mov    r13d,r11d */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_R13, X86_R11, X86_WIDTH_32, 0, 0);
x86_l_12e3:
	/* 0x12e3: shl    r13b,0x4 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_ALU_SHL, 4ULL);
x86_l_12e7:
	/* 0x12e7: or     r13b,r12b */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R13, X86_R12, X86_WIDTH_8, X86_ALU_OR, 0);
x86_l_12ea:
	/* 0x12ea: rol    r15w,0x8 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_ALU_ROL, 8ULL);
x86_l_12ef:
	/* 0x12ef: movzx  esi,r15w */
	X86_VM_RUN_OP(x86_exec_movzx_reg, X86_OP_MOVZX_REG, X86_RSI, X86_R15, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_12f3:
	/* 0x12f3: mov    edx,r14d */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RDX, X86_R14, X86_WIDTH_32, 0, 0);
x86_l_12f6:
	/* 0x12f6: and    edx,0xff000000 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 4278190080ULL);
x86_l_12fc:
	/* 0x12fc: mov    r10,QWORD PTR [rbp-0x38] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R10, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551560ULL);
x86_l_1300:
	/* 0x1300: lea    r9d,[r10-0x21523f01] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_R9, X86_R10, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073150513407ULL);
x86_l_1307:
	/* 0x1307: mov    edi,r14d */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RDI, X86_R14, X86_WIDTH_32, 0, 0);
x86_l_130a:
	/* 0x130a: and    edi,0xff0000 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 16711680ULL);
x86_l_1310:
	/* 0x1310: add    edi,edx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD, 0);
x86_l_1312:
	/* 0x1312: mov    edx,r14d */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RDX, X86_R14, X86_WIDTH_32, 0, 0);
x86_l_1315:
	/* 0x1315: and    edx,0xff00 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 65280ULL);
x86_l_131b:
	/* 0x131b: add    edx,edi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD, 0);
x86_l_131d:
	/* 0x131d: movzx  ebx,r14b */
	X86_VM_RUN_OP(x86_exec_movzx_reg, X86_OP_MOVZX_REG, X86_RBX, X86_R14, X86_WIDTH_32, X86_WIDTH_8, 0);
x86_l_1321:
	/* 0x1321: add    ebx,edx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RBX, X86_RDX, X86_WIDTH_32, X86_ALU_ADD, 0);
x86_l_1323:
	/* 0x1323: mov    r15,QWORD PTR [rbp-0x30] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R15, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551568ULL);
x86_l_1327:
	/* 0x1327: mov    edx,r15d */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RDX, X86_R15, X86_WIDTH_32, 0, 0);
x86_l_132a:
	/* 0x132a: sub    edx,r10d */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_R10, X86_WIDTH_32, X86_ALU_SUB, 0);
x86_l_132d:
	/* 0x132d: mov    r14d,r9d */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_R14, X86_R9, X86_WIDTH_32, 0, 0);
x86_l_1330:
	/* 0x1330: rol    r14d,0x4 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ROL, 4ULL);
x86_l_1334:
	/* 0x1334: xor    r14d,edx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R14, X86_RDX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1337:
	/* 0x1337: add    r9d,r8d */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_R8, X86_WIDTH_32, X86_ALU_ADD, 0);
x86_l_133a:
	/* 0x133a: sub    r8d,r14d */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R8, X86_R14, X86_WIDTH_32, X86_ALU_SUB, 0);
x86_l_133d:
	/* 0x133d: mov    r10d,r14d */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_R10, X86_R14, X86_WIDTH_32, 0, 0);
x86_l_1340:
	/* 0x1340: rol    r10d,0x6 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ROL, 6ULL);
x86_l_1344:
	/* 0x1344: xor    r10d,r8d */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R10, X86_R8, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1347:
	/* 0x1347: add    r14d,r9d */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R14, X86_R9, X86_WIDTH_32, X86_ALU_ADD, 0);
x86_l_134a:
	/* 0x134a: lea    edx,[r10+r14*1] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_RDX, X86_R10, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_134e:
	/* 0x134e: sub    r9d,r10d */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_R10, X86_WIDTH_32, X86_ALU_SUB, 0);
x86_l_1351:
	/* 0x1351: rol    r10d,0x8 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ROL, 8ULL);
x86_l_1355:
	/* 0x1355: movzx  r8d,WORD PTR [rcx+0x3e] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R8, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 62ULL);
x86_l_135a:
	/* 0x135a: xor    r10d,r9d */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R10, X86_R9, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_135d:
	/* 0x135d: sub    r14d,r10d */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R14, X86_R10, X86_WIDTH_32, X86_ALU_SUB, 0);
x86_l_1360:
	/* 0x1360: mov    r11d,r10d */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_R11, X86_R10, X86_WIDTH_32, 0, 0);
x86_l_1363:
	/* 0x1363: rol    r11d,0x10 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ROL, 16ULL);
x86_l_1367:
	/* 0x1367: xor    r11d,r14d */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R11, X86_R14, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_136a:
	/* 0x136a: add    r10d,edx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R10, X86_RDX, X86_WIDTH_32, X86_ALU_ADD, 0);
x86_l_136d:
	/* 0x136d: sub    edx,r11d */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_R11, X86_WIDTH_32, X86_ALU_SUB, 0);
x86_l_1370:
	/* 0x1370: mov    edi,r11d */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RDI, X86_R11, X86_WIDTH_32, 0, 0);
x86_l_1373:
	/* 0x1373: rol    edi,0x13 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ROL, 19ULL);
x86_l_1376:
	/* 0x1376: xor    edi,edx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1378:
	/* 0x1378: add    r11d,r10d */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R11, X86_R10, X86_WIDTH_32, X86_ALU_ADD, 0);
x86_l_137b:
	/* 0x137b: lea    r9d,[rdi+r11*1] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_R9, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R11, 0), 0ULL);
x86_l_137f:
	/* 0x137f: sub    r10d,edi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R10, X86_RDI, X86_WIDTH_32, X86_ALU_SUB, 0);
x86_l_1382:
	/* 0x1382: rol    edi,0x4 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ROL, 4ULL);
x86_l_1385:
	/* 0x1385: add    r11d,ebx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R11, X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 0);
x86_l_1388:
	/* 0x1388: xor    r10d,r9d */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R10, X86_R9, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_138b:
	/* 0x138b: xor    r10d,edi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R10, X86_RDI, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_138e:
	/* 0x138e: mov    edx,r9d */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RDX, X86_R9, X86_WIDTH_32, 0, 0);
x86_l_1391:
	/* 0x1391: rol    edx,0xe */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ROL, 14ULL);
x86_l_1394:
	/* 0x1394: sub    r10d,edx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R10, X86_RDX, X86_WIDTH_32, X86_ALU_SUB, 0);
x86_l_1397:
	/* 0x1397: mov    edx,r10d */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RDX, X86_R10, X86_WIDTH_32, 0, 0);
x86_l_139a:
	/* 0x139a: rol    edx,0xb */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ROL, 11ULL);
x86_l_139d:
	/* 0x139d: xor    r11d,r10d */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R11, X86_R10, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_13a0:
	/* 0x13a0: sub    r11d,edx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R11, X86_RDX, X86_WIDTH_32, X86_ALU_SUB, 0);
x86_l_13a3:
	/* 0x13a3: xor    r9d,r11d */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_R11, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_13a6:
	/* 0x13a6: mov    edx,r11d */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RDX, X86_R11, X86_WIDTH_32, 0, 0);
x86_l_13a9:
	/* 0x13a9: rol    edx,0x19 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ROL, 25ULL);
x86_l_13ac:
	/* 0x13ac: sub    r9d,edx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_RDX, X86_WIDTH_32, X86_ALU_SUB, 0);
x86_l_13af:
	/* 0x13af: xor    r10d,r9d */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R10, X86_R9, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_13b2:
	/* 0x13b2: mov    edx,r9d */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RDX, X86_R9, X86_WIDTH_32, 0, 0);
x86_l_13b5:
	/* 0x13b5: rol    edx,0x10 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ROL, 16ULL);
x86_l_13b8:
	/* 0x13b8: sub    r10d,edx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R10, X86_RDX, X86_WIDTH_32, X86_ALU_SUB, 0);
x86_l_13bb:
	/* 0x13bb: xor    r11d,r10d */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R11, X86_R10, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_13be:
	/* 0x13be: mov    edx,r10d */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RDX, X86_R10, X86_WIDTH_32, 0, 0);
x86_l_13c1:
	/* 0x13c1: rol    edx,0x4 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ROL, 4ULL);
x86_l_13c4:
	/* 0x13c4: sub    r11d,edx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R11, X86_RDX, X86_WIDTH_32, X86_ALU_SUB, 0);
x86_l_13c7:
	/* 0x13c7: xor    r9d,r11d */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_R11, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_13ca:
	/* 0x13ca: rol    r11d,0xe */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ROL, 14ULL);
x86_l_13ce:
	/* 0x13ce: sub    r9d,r11d */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_R11, X86_WIDTH_32, X86_ALU_SUB, 0);
x86_l_13d1:
	/* 0x13d1: mov    edx,r9d */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RDX, X86_R9, X86_WIDTH_32, 0, 0);
x86_l_13d4:
	/* 0x13d4: rol    edx,0x18 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ROL, 24ULL);
x86_l_13d7:
	/* 0x13d7: xor    r9d,r10d */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_R10, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_13da:
	/* 0x13da: sub    r9d,edx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_RDX, X86_WIDTH_32, X86_ALU_SUB, 0);
x86_l_13dd:
	/* 0x13dd: add    r9d,0xe0adc0f7 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 3769483511ULL);
x86_l_13e4:
	/* 0x13e4: mov    r11d,r8d */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_R11, X86_R8, X86_WIDTH_32, 0, 0);
x86_l_13e7:
	/* 0x13e7: add    r11d,0x70ccc0f7 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 1892466935ULL);
x86_l_13ee:
	/* 0x13ee: mov    r10d,r11d */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_R10, X86_R11, X86_WIDTH_32, 0, 0);
x86_l_13f1:
	/* 0x13f1: xor    r10d,0xe0adc0f7 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_32, X86_ALU_XOR, 3769483511ULL);
x86_l_13f8:
	/* 0x13f8: mov    edx,0x70cc0000 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 1892417536ULL);
x86_l_13fd:
	/* 0x13fd: shrd   edx,r11d,0x12 */
	X86_VM_RUN_OP(x86_exec_shrd_imm, X86_OP_SHRD_IMM, X86_RDX, X86_R11, X86_WIDTH_32, 0, 18ULL);
x86_l_1402:
	/* 0x1402: sub    r10d,edx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R10, X86_RDX, X86_WIDTH_32, X86_ALU_SUB, 0);
x86_l_1405:
	/* 0x1405: xor    r9d,r10d */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_R10, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1408:
	/* 0x1408: mov    edx,r10d */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RDX, X86_R10, X86_WIDTH_32, 0, 0);
x86_l_140b:
	/* 0x140b: rol    edx,0xb */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ROL, 11ULL);
x86_l_140e:
	/* 0x140e: sub    r9d,edx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_RDX, X86_WIDTH_32, X86_ALU_SUB, 0);
x86_l_1411:
	/* 0x1411: xor    r11d,r9d */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R11, X86_R9, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1414:
	/* 0x1414: mov    edx,r9d */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RDX, X86_R9, X86_WIDTH_32, 0, 0);
x86_l_1417:
	/* 0x1417: rol    edx,0x19 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ROL, 25ULL);
x86_l_141a:
	/* 0x141a: sub    r11d,edx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R11, X86_RDX, X86_WIDTH_32, X86_ALU_SUB, 0);
x86_l_141d:
	/* 0x141d: mov    edx,r11d */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RDX, X86_R11, X86_WIDTH_32, 0, 0);
x86_l_1420:
	/* 0x1420: rol    edx,0x10 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ROL, 16ULL);
x86_l_1423:
	/* 0x1423: xor    r10d,r11d */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R10, X86_R11, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1426:
	/* 0x1426: sub    r10d,edx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R10, X86_RDX, X86_WIDTH_32, X86_ALU_SUB, 0);
x86_l_1429:
	/* 0x1429: xor    r9d,r10d */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_R10, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_142c:
	/* 0x142c: mov    edx,r10d */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RDX, X86_R10, X86_WIDTH_32, 0, 0);
x86_l_142f:
	/* 0x142f: rol    edx,0x4 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ROL, 4ULL);
x86_l_1432:
	/* 0x1432: sub    r9d,edx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_RDX, X86_WIDTH_32, X86_ALU_SUB, 0);
x86_l_1435:
	/* 0x1435: xor    r11d,r9d */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R11, X86_R9, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1438:
	/* 0x1438: rol    r9d,0xe */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ROL, 14ULL);
x86_l_143c:
	/* 0x143c: sub    r11d,r9d */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R11, X86_R9, X86_WIDTH_32, X86_ALU_SUB, 0);
x86_l_143f:
	/* 0x143f: xor    r10d,r11d */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R10, X86_R11, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1442:
	/* 0x1442: rol    r11d,0x18 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ROL, 24ULL);
x86_l_1446:
	/* 0x1446: sub    r10d,r11d */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R10, X86_R11, X86_WIDTH_32, X86_ALU_SUB, 0);
x86_l_1449:
	/* 0x1449: mov    edx,0xffff0001 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 4294901761ULL);
x86_l_144e:
	/* 0x144e: imul   rdx,r10 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_R10, X86_WIDTH_64, X86_ALU_IMUL, 0);
x86_l_1452:
	/* 0x1452: shr    rdx,0x30 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 48ULL);
x86_l_1456:
	/* 0x1456: mov    edi,edx */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RDI, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_1458:
	/* 0x1458: shl    edi,0x10 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 16ULL);
x86_l_145b:
	/* 0x145b: or     edi,edx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_ALU_OR, 0);
x86_l_145d:
	/* 0x145d: sub    r10d,edi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R10, X86_RDI, X86_WIDTH_32, X86_ALU_SUB, 0);
x86_l_1460:
	/* 0x1460: mov    rdx,r15 */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RDX, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_1463:
	/* 0x1463: add    rdx,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1466:
	/* 0x1466: mov    rdi,rdx */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RDI, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_1469:
	/* 0x1469: shl    rdi,0x6 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 6ULL);
x86_l_146d:
	/* 0x146d: add    rdi,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1470:
	/* 0x1470: mov    r9,rdx */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_R9, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_1473:
	/* 0x1473: shr    r9,0x2 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 2ULL);
x86_l_1477:
	/* 0x1477: add    rdi,r9 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_R9, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_147a:
	/* 0x147a: add    rdi,0x101640a */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 16868362ULL);
x86_l_1481:
	/* 0x1481: xor    rdi,rdx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_RDX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1484:
	/* 0x1484: mov    r9,rdi */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_R9, X86_RDI, X86_WIDTH_64, 0, 0);
x86_l_1487:
	/* 0x1487: shl    r9,0x6 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 6ULL);
x86_l_148b:
	/* 0x148b: add    r9,r8 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_R8, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_148e:
	/* 0x148e: add    r9,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1491:
	/* 0x1491: mov    rdx,rdi */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RDX, X86_RDI, X86_WIDTH_64, 0, 0);
x86_l_1494:
	/* 0x1494: shr    rdx,0x2 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 2ULL);
x86_l_1498:
	/* 0x1498: mov    r11d,0x901f0000 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_32, 0, 2417950720ULL);
x86_l_149e:
	/* 0x149e: add    r11,rdx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R11, X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_14a1:
	/* 0x14a1: add    r11,r9 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R11, X86_R9, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_14a4:
	/* 0x14a4: xor    r11,rdi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R11, X86_RDI, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_14a7:
	/* 0x14a7: mov    rdx,r11 */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RDX, X86_R11, X86_WIDTH_64, 0, 0);
x86_l_14aa:
	/* 0x14aa: shl    rdx,0x6 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 6ULL);
x86_l_14ae:
	/* 0x14ae: mov    rdi,r11 */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RDI, X86_R11, X86_WIDTH_64, 0, 0);
x86_l_14b1:
	/* 0x14b1: shr    rdi,0x2 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 2ULL);
x86_l_14b5:
	/* 0x14b5: add    rdx,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_14b8:
	/* 0x14b8: add    rdx,rdi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_14bb:
	/* 0x14bb: add    rdx,r10 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_R10, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_14be:
	/* 0x14be: xor    rdx,r11 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_R11, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_14c1:
	/* 0x14c1: mov    rdi,rdx */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RDI, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_14c4:
	/* 0x14c4: shl    rdi,0x6 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 6ULL);
x86_l_14c8:
	/* 0x14c8: add    rdi,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_14cb:
	/* 0x14cb: mov    r9,rdx */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_R9, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_14ce:
	/* 0x14ce: shr    r9,0x2 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 2ULL);
x86_l_14d2:
	/* 0x14d2: add    rdi,r9 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_R9, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_14d5:
	/* 0x14d5: inc    rdi */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_14d8:
	/* 0x14d8: xor    rdi,rdx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_RDX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_14db:
	/* 0x14db: mov    rdx,rdi */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RDX, X86_RDI, X86_WIDTH_64, 0, 0);
x86_l_14de:
	/* 0x14de: shl    rdx,0x6 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 6ULL);
x86_l_14e2:
	/* 0x14e2: add    rdx,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_14e5:
	/* 0x14e5: mov    r10,rdi */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_R10, X86_RDI, X86_WIDTH_64, 0, 0);
x86_l_14e8:
	/* 0x14e8: shr    r10,0x2 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 2ULL);
x86_l_14ec:
	/* 0x14ec: add    r10,rdx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R10, X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_14ef:
	/* 0x14ef: xor    r10,rdi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R10, X86_RDI, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_14f2:
	/* 0x14f2: mov    rdi,r10 */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RDI, X86_R10, X86_WIDTH_64, 0, 0);
x86_l_14f5:
	/* 0x14f5: shl    rdi,0x6 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 6ULL);
x86_l_14f9:
	/* 0x14f9: add    rdi,rsi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_14fc:
	/* 0x14fc: add    rdi,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_14ff:
	/* 0x14ff: mov    r9,r10 */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_R9, X86_R10, X86_WIDTH_64, 0, 0);
x86_l_1502:
	/* 0x1502: shr    r9,0x2 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 2ULL);
x86_l_1506:
	/* 0x1506: add    r9,rdi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1509:
	/* 0x1509: rol    r8w,0x8 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_16, X86_ALU_ROL, 8ULL);
x86_l_150e:
	/* 0x150e: shl    r8d,0x10 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 16ULL);
x86_l_1512:
	/* 0x1512: and    r15d,0xffff0000 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 4294901760ULL);
x86_l_1519:
	/* 0x1519: xor    r15d,r8d */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R15, X86_R8, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_151c:
	/* 0x151c: mov    edx,esi */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RDX, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_151e:
	/* 0x151e: add    edx,0x14 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 20ULL);
x86_l_1521:
	/* 0x1521: rol    dx,0x8 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_16, X86_ALU_ROL, 8ULL);
x86_l_1525:
	/* 0x1525: movzx  edi,r13b */
	X86_VM_RUN_OP(x86_exec_movzx_reg, X86_OP_MOVZX_REG, X86_RDI, X86_R13, X86_WIDTH_32, X86_WIDTH_8, 0);
x86_l_1529:
	/* 0x1529: movzx  edx,dx */
	X86_VM_RUN_OP(x86_exec_movzx_reg, X86_OP_MOVZX_REG, X86_RDX, X86_RDX, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_152c:
	/* 0x152c: mov    r8d,r15d */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_R8, X86_R15, X86_WIDTH_32, 0, 0);
x86_l_152f:
	/* 0x152f: shr    r8d,0x10 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1533:
	/* 0x1533: add    rdx,rdi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1536:
	/* 0x1536: add    rdx,r8 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_R8, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1539:
	/* 0x1539: add    rdx,0xdf3b */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 57147ULL);
x86_l_1540:
	/* 0x1540: mov    edi,edx */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RDI, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_1542:
	/* 0x1542: shr    edi,0x10 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1545:
	/* 0x1545: movzx  r8d,dx */
	X86_VM_RUN_OP(x86_exec_movzx_reg, X86_OP_MOVZX_REG, X86_R8, X86_RDX, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_1549:
	/* 0x1549: add    r8,rdi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R8, X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_154c:
	/* 0x154c: cmp    rdx,0x10000 */
	X86_VM_RUN_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, 0, 65536ULL);
x86_l_1553:
	/* 0x1553: cmovb  r8,rdx */
	X86_VM_RUN_OP(x86_exec_cmov, X86_OP_CMOV, X86_R8, X86_RDX, X86_WIDTH_64, X86_CC_B, 0);
x86_l_1557:
	/* 0x1557: mov    edx,r8d */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RDX, X86_R8, X86_WIDTH_32, 0, 0);
x86_l_155a:
	/* 0x155a: shr    edx,0x10 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_155d:
	/* 0x155d: movzx  edi,r8w */
	X86_VM_RUN_OP(x86_exec_movzx_reg, X86_OP_MOVZX_REG, X86_RDI, X86_R8, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_1561:
	/* 0x1561: add    rdi,rdx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1564:
	/* 0x1564: cmp    r8,0x10000 */
	X86_VM_RUN_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_64, 0, 65536ULL);
x86_l_156b:
	/* 0x156b: cmovb  rdi,r8 */
	X86_VM_RUN_OP(x86_exec_cmov, X86_OP_CMOV, X86_RDI, X86_R8, X86_WIDTH_64, X86_CC_B, 0);
x86_l_156f:
	/* 0x156f: mov    edx,edi */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RDX, X86_RDI, X86_WIDTH_32, 0, 0);
x86_l_1571:
	/* 0x1571: shr    edx,0x10 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1574:
	/* 0x1574: movzx  r8d,di */
	X86_VM_RUN_OP(x86_exec_movzx_reg, X86_OP_MOVZX_REG, X86_R8, X86_RDI, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_1578:
	/* 0x1578: add    r8,rdx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R8, X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_157b:
	/* 0x157b: cmp    rdi,0x10000 */
	X86_VM_RUN_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, 65536ULL);
x86_l_1582:
	/* 0x1582: cmovb  r8,rdi */
	X86_VM_RUN_OP(x86_exec_cmov, X86_OP_CMOV, X86_R8, X86_RDI, X86_WIDTH_64, X86_CC_B, 0);
x86_l_1586:
	/* 0x1586: mov    edx,r8d */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RDX, X86_R8, X86_WIDTH_32, 0, 0);
x86_l_1589:
	/* 0x1589: shr    edx,0x10 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_158c:
	/* 0x158c: add    edx,r8d */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_R8, X86_WIDTH_32, X86_ALU_ADD, 0);
x86_l_158f:
	/* 0x158f: xor    r9,r10 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_R10, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1592:
	/* 0x1592: or     r15d,0x10ac */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_ALU_OR, 4268ULL);
x86_l_1599:
	/* 0x1599: shl    r15,0x20 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_159d:
	/* 0x159d: or     r15,0x200c80a */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_ALU_OR, 33605642ULL);
x86_l_15a4:
	/* 0x15a4: cmp    r8,0x10000 */
	X86_VM_RUN_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_64, 0, 65536ULL);
x86_l_15ab:
	/* 0x15ab: cmovb  edx,r8d */
	X86_VM_RUN_OP(x86_exec_cmov, X86_OP_CMOV, X86_RDX, X86_R8, X86_WIDTH_32, X86_CC_B, 0);
x86_l_15af:
	/* 0x15af: shl    edx,0x10 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 16ULL);
x86_l_15b2:
	/* 0x15b2: xor    r15,rsi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R15, X86_RSI, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_15b5:
	/* 0x15b5: movabs rsi,0x200ffff000b */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, 0, 2203318157323ULL);
x86_l_15bf:
	/* 0x15bf: xor    rsi,r15 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RSI, X86_R15, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_15c2:
	/* 0x15c2: xor    rsi,rdx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RSI, X86_RDX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_15c5:
	/* 0x15c5: mov    rdx,r9 */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RDX, X86_R9, X86_WIDTH_64, 0, 0);
x86_l_15c8:
	/* 0x15c8: shl    rdx,0x6 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 6ULL);
x86_l_15cc:
	/* 0x15cc: mov    rdi,r9 */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RDI, X86_R9, X86_WIDTH_64, 0, 0);
x86_l_15cf:
	/* 0x15cf: shr    rdi,0x2 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 2ULL);
x86_l_15d3:
	/* 0x15d3: add    rdi,rsi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_15d6:
	/* 0x15d6: add    rdx,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_15d9:
	/* 0x15d9: add    rdx,rdi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_15dc:
	/* 0x15dc: xor    rdx,r9 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_R9, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_15df:
	/* 0x15df: jmp    1880 <katran_lb_consistent_hash_select_xdp+0x780> */
	goto x86_l_1880;
x86_l_15e4:
	/* 0x15e4: lea    r13,[rcx+0x32] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_R13, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 50ULL);
x86_l_15e8:
	/* 0x15e8: cmp    r13,rbx */
	X86_VM_RUN_OP(x86_exec_cmp_reg, X86_OP_CMP_REG, X86_R13, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_15eb:
	/* 0x15eb: jbe    161f <katran_lb_consistent_hash_select_xdp+0x51f> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_BE))
		goto x86_l_161f;
x86_l_15ed:
	/* 0x15ed: mov    esi,0x1 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_15f2:
	/* 0x15f2: mov    rdx,rsi */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RDX, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_15f5:
	/* 0x15f5: shl    rdx,0x6 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 6ULL);
x86_l_15f9:
	/* 0x15f9: mov    rdi,rsi */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RDI, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_15fc:
	/* 0x15fc: shr    rdi,0x2 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 2ULL);
x86_l_1600:
	/* 0x1600: add    rdi,r9 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_R9, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1603:
	/* 0x1603: add    rdx,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1606:
	/* 0x1606: add    rdx,rdi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1609:
	/* 0x1609: xor    rdx,rsi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_160c:
	/* 0x160c: mov    QWORD PTR [rcx],rdx */
	X86_VM_RUN_OP(x86_exec_mov_store_reg, X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_160f:
	/* 0x160f: mov    eax,0x2 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_1614:
	/* 0x1614: pop    rbx */
	X86_VM_RUN_OP(x86_exec_pop, X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1615:
	/* 0x1615: pop    r12 */
	X86_VM_RUN_OP(x86_exec_pop, X86_OP_POP, X86_R12, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1617:
	/* 0x1617: pop    r13 */
	X86_VM_RUN_OP(x86_exec_pop, X86_OP_POP, X86_R13, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1619:
	/* 0x1619: pop    r14 */
	X86_VM_RUN_OP(x86_exec_pop, X86_OP_POP, X86_R14, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_161b:
	/* 0x161b: pop    r15 */
	X86_VM_RUN_OP(x86_exec_pop, X86_OP_POP, X86_R15, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_161d:
	/* 0x161d: pop    rbp */
	X86_VM_RUN_OP(x86_exec_pop, X86_OP_POP, X86_RBP, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_161e:
	/* 0x161e: ret */
	X86_VM_RET_RAX();
x86_l_161f:
	/* 0x161f: cmp    r12d,0x101640a */
	X86_VM_RUN_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 16868362ULL);
x86_l_1626:
	/* 0x1626: jne    1236 <katran_lb_consistent_hash_select_xdp+0x136> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_1236;
x86_l_162c:
	/* 0x162c: movzx  r9d,WORD PTR [rcx+0x2c] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R9, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 44ULL);
x86_l_1631:
	/* 0x1631: cmp    r9d,0x901f */
	X86_VM_RUN_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_32, 0, 36895ULL);
x86_l_1638:
	/* 0x1638: jne    1236 <katran_lb_consistent_hash_select_xdp+0x136> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_1236;
x86_l_163e:
	/* 0x163e: mov    r9d,0x2 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_1644:
	/* 0x1644: cmp    r15b,0x6 */
	X86_VM_RUN_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, 0, 6ULL);
x86_l_1648:
	/* 0x1648: jne    15f2 <katran_lb_consistent_hash_select_xdp+0x4f2> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_15f2;
x86_l_164a:
	/* 0x164a: mov    esi,0x1 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_164f:
	/* 0x164f: mov    r9d,0x1 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_1655:
	/* 0x1655: cmp    r10,0x5ea */
	X86_VM_RUN_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_64, 0, 1514ULL);
x86_l_165c:
	/* 0x165c: jg     15f2 <katran_lb_consistent_hash_select_xdp+0x4f2> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_G))
		goto x86_l_15f2;
x86_l_165e:
	/* 0x165e: rol    r14w,0x8 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_ALU_ROL, 8ULL);
x86_l_1663:
	/* 0x1663: movzx  esi,r14w */
	X86_VM_RUN_OP(x86_exec_movzx_reg, X86_OP_MOVZX_REG, X86_RSI, X86_R14, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_1667:
	/* 0x1667: shl    r8d,0x10 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 16ULL);
x86_l_166b:
	/* 0x166b: shl    edx,0x18 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 24ULL);
x86_l_166e:
	/* 0x166e: or     r11d,r8d */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R11, X86_R8, X86_WIDTH_32, X86_ALU_OR, 0);
x86_l_1671:
	/* 0x1671: or     r11d,edx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R11, X86_RDX, X86_WIDTH_32, X86_ALU_OR, 0);
x86_l_1674:
	/* 0x1674: movzx  r9d,WORD PTR [rcx+0x2a] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R9, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 42ULL);
x86_l_1679:
	/* 0x1679: mov    ebx,r9d */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RBX, X86_R9, X86_WIDTH_32, 0, 0);
x86_l_167c:
	/* 0x167c: add    ebx,0x70ccc0f7 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 1892466935ULL);
x86_l_1682:
	/* 0x1682: mov    r10d,ebx */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_R10, X86_RBX, X86_WIDTH_32, 0, 0);
x86_l_1685:
	/* 0x1685: xor    r10d,0xe0adc0f7 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_32, X86_ALU_XOR, 3769483511ULL);
x86_l_168c:
	/* 0x168c: mov    r14d,0x70cc0000 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, 0, 1892417536ULL);
x86_l_1692:
	/* 0x1692: shrd   r14d,ebx,0x12 */
	X86_VM_RUN_OP(x86_exec_shrd_imm, X86_OP_SHRD_IMM, X86_R14, X86_RBX, X86_WIDTH_32, 0, 18ULL);
x86_l_1697:
	/* 0x1697: sub    r10d,r14d */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R10, X86_R14, X86_WIDTH_32, X86_ALU_SUB, 0);
x86_l_169a:
	/* 0x169a: lea    r14d,[r11-0x1f523f09] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_R14, X86_R11, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073184067831ULL);
x86_l_16a1:
	/* 0x16a1: xor    r14d,r10d */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R14, X86_R10, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_16a4:
	/* 0x16a4: mov    r15d,r10d */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_R15, X86_R10, X86_WIDTH_32, 0, 0);
x86_l_16a7:
	/* 0x16a7: rol    r15d,0xb */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ROL, 11ULL);
x86_l_16ab:
	/* 0x16ab: sub    r14d,r15d */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R14, X86_R15, X86_WIDTH_32, X86_ALU_SUB, 0);
x86_l_16ae:
	/* 0x16ae: mov    r15d,r14d */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_R15, X86_R14, X86_WIDTH_32, 0, 0);
x86_l_16b1:
	/* 0x16b1: rol    r15d,0x19 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ROL, 25ULL);
x86_l_16b5:
	/* 0x16b5: xor    ebx,r14d */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RBX, X86_R14, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_16b8:
	/* 0x16b8: sub    ebx,r15d */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RBX, X86_R15, X86_WIDTH_32, X86_ALU_SUB, 0);
x86_l_16bb:
	/* 0x16bb: xor    r10d,ebx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R10, X86_RBX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_16be:
	/* 0x16be: mov    r15d,ebx */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_R15, X86_RBX, X86_WIDTH_32, 0, 0);
x86_l_16c1:
	/* 0x16c1: rol    r15d,0x10 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ROL, 16ULL);
x86_l_16c5:
	/* 0x16c5: sub    r10d,r15d */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R10, X86_R15, X86_WIDTH_32, X86_ALU_SUB, 0);
x86_l_16c8:
	/* 0x16c8: xor    r14d,r10d */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R14, X86_R10, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_16cb:
	/* 0x16cb: mov    r15d,r10d */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_R15, X86_R10, X86_WIDTH_32, 0, 0);
x86_l_16ce:
	/* 0x16ce: rol    r15d,0x4 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ROL, 4ULL);
x86_l_16d2:
	/* 0x16d2: sub    r14d,r15d */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R14, X86_R15, X86_WIDTH_32, X86_ALU_SUB, 0);
x86_l_16d5:
	/* 0x16d5: xor    ebx,r14d */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RBX, X86_R14, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_16d8:
	/* 0x16d8: rol    r14d,0xe */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ROL, 14ULL);
x86_l_16dc:
	/* 0x16dc: sub    ebx,r14d */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RBX, X86_R14, X86_WIDTH_32, X86_ALU_SUB, 0);
x86_l_16df:
	/* 0x16df: xor    r10d,ebx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R10, X86_RBX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_16e2:
	/* 0x16e2: rol    ebx,0x18 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ROL, 24ULL);
x86_l_16e5:
	/* 0x16e5: sub    r10d,ebx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R10, X86_RBX, X86_WIDTH_32, X86_ALU_SUB, 0);
x86_l_16e8:
	/* 0x16e8: mov    ebx,0xffff0001 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 4294901761ULL);
x86_l_16ed:
	/* 0x16ed: imul   rbx,r10 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RBX, X86_R10, X86_WIDTH_64, X86_ALU_IMUL, 0);
x86_l_16f1:
	/* 0x16f1: shr    rbx,0x30 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 48ULL);
x86_l_16f5:
	/* 0x16f5: mov    r14d,ebx */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_R14, X86_RBX, X86_WIDTH_32, 0, 0);
x86_l_16f8:
	/* 0x16f8: shl    r14d,0x10 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 16ULL);
x86_l_16fc:
	/* 0x16fc: or     r14d,ebx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R14, X86_RBX, X86_WIDTH_32, X86_ALU_OR, 0);
x86_l_16ff:
	/* 0x16ff: sub    r10d,r14d */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R10, X86_R14, X86_WIDTH_32, X86_ALU_SUB, 0);
x86_l_1702:
	/* 0x1702: mov    r11d,r11d */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_R11, X86_R11, X86_WIDTH_32, 0, 0);
x86_l_1705:
	/* 0x1705: add    r11,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R11, X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1708:
	/* 0x1708: mov    rbx,r11 */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RBX, X86_R11, X86_WIDTH_64, 0, 0);
x86_l_170b:
	/* 0x170b: shl    rbx,0x6 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 6ULL);
x86_l_170f:
	/* 0x170f: mov    r14,r11 */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_R14, X86_R11, X86_WIDTH_64, 0, 0);
x86_l_1712:
	/* 0x1712: shr    r14,0x2 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 2ULL);
x86_l_1716:
	/* 0x1716: add    r14,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1719:
	/* 0x1719: add    rbx,r14 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RBX, X86_R14, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_171c:
	/* 0x171c: add    rbx,0x101640a */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 16868362ULL);
x86_l_1723:
	/* 0x1723: xor    rbx,r11 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RBX, X86_R11, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1726:
	/* 0x1726: mov    r11,rbx */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_R11, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_1729:
	/* 0x1729: shl    r11,0x6 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 6ULL);
x86_l_172d:
	/* 0x172d: mov    r14,rbx */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_R14, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_1730:
	/* 0x1730: shr    r14,0x2 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 2ULL);
x86_l_1734:
	/* 0x1734: add    r14,r9 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R14, X86_R9, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1737:
	/* 0x1737: add    r11,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R11, X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_173a:
	/* 0x173a: add    r11,r14 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R11, X86_R14, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_173d:
	/* 0x173d: mov    r14d,0x901f0000 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, 0, 2417950720ULL);
x86_l_1743:
	/* 0x1743: add    r14,r11 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R14, X86_R11, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1746:
	/* 0x1746: xor    r14,rbx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R14, X86_RBX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1749:
	/* 0x1749: mov    r11,r14 */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_R11, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_174c:
	/* 0x174c: shl    r11,0x6 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 6ULL);
x86_l_1750:
	/* 0x1750: mov    rbx,r14 */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RBX, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_1753:
	/* 0x1753: shr    rbx,0x2 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 2ULL);
x86_l_1757:
	/* 0x1757: add    r11,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R11, X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_175a:
	/* 0x175a: add    r11,rbx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R11, X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_175d:
	/* 0x175d: add    r11,r10 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R11, X86_R10, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1760:
	/* 0x1760: xor    r11,r14 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R11, X86_R14, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1763:
	/* 0x1763: mov    r10,r11 */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_R10, X86_R11, X86_WIDTH_64, 0, 0);
x86_l_1766:
	/* 0x1766: shl    r10,0x6 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 6ULL);
x86_l_176a:
	/* 0x176a: add    r10,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R10, X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_176d:
	/* 0x176d: mov    rbx,r11 */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RBX, X86_R11, X86_WIDTH_64, 0, 0);
x86_l_1770:
	/* 0x1770: shr    rbx,0x2 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 2ULL);
x86_l_1774:
	/* 0x1774: add    r10,rbx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R10, X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1777:
	/* 0x1777: inc    r10 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_177a:
	/* 0x177a: xor    r10,r11 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R10, X86_R11, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_177d:
	/* 0x177d: mov    rbx,r10 */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RBX, X86_R10, X86_WIDTH_64, 0, 0);
x86_l_1780:
	/* 0x1780: shl    rbx,0x6 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 6ULL);
x86_l_1784:
	/* 0x1784: add    rbx,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1787:
	/* 0x1787: mov    r11,r10 */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_R11, X86_R10, X86_WIDTH_64, 0, 0);
x86_l_178a:
	/* 0x178a: shr    r11,0x2 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 2ULL);
x86_l_178e:
	/* 0x178e: add    r11,rbx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R11, X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1791:
	/* 0x1791: xor    r11,r10 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R11, X86_R10, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1794:
	/* 0x1794: mov    rbx,r11 */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RBX, X86_R11, X86_WIDTH_64, 0, 0);
x86_l_1797:
	/* 0x1797: shl    rbx,0x6 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 6ULL);
x86_l_179b:
	/* 0x179b: add    rbx,rsi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RBX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_179e:
	/* 0x179e: add    rbx,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_17a1:
	/* 0x17a1: mov    r10,r11 */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_R10, X86_R11, X86_WIDTH_64, 0, 0);
x86_l_17a4:
	/* 0x17a4: shr    r10,0x2 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 2ULL);
x86_l_17a8:
	/* 0x17a8: rol    r9w,0x8 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_16, X86_ALU_ROL, 8ULL);
x86_l_17ad:
	/* 0x17ad: add    r10,rbx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R10, X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_17b0:
	/* 0x17b0: shl    r9d,0x10 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 16ULL);
x86_l_17b4:
	/* 0x17b4: or     edx,r8d */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_R8, X86_WIDTH_32, X86_ALU_OR, 0);
x86_l_17b7:
	/* 0x17b7: xor    edx,r9d */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_R9, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_17ba:
	/* 0x17ba: mov    r8d,esi */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_R8, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_17bd:
	/* 0x17bd: add    r8d,0x14 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 20ULL);
x86_l_17c1:
	/* 0x17c1: rol    r8w,0x8 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_16, X86_ALU_ROL, 8ULL);
x86_l_17c6:
	/* 0x17c6: movzx  r8d,r8w */
	X86_VM_RUN_OP(x86_exec_movzx_reg, X86_OP_MOVZX_REG, X86_R8, X86_R8, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_17ca:
	/* 0x17ca: mov    r9d,edx */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_R9, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_17cd:
	/* 0x17cd: shr    r9d,0x10 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_17d1:
	/* 0x17d1: add    r8,rdi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R8, X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_17d4:
	/* 0x17d4: lea    rdi,[r9+r8*1] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_RDI, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_R8, 0), 0ULL);
x86_l_17d8:
	/* 0x17d8: add    rdi,0xdf3b */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 57147ULL);
x86_l_17df:
	/* 0x17df: mov    r8d,edi */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_R8, X86_RDI, X86_WIDTH_32, 0, 0);
x86_l_17e2:
	/* 0x17e2: shr    r8d,0x10 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_17e6:
	/* 0x17e6: movzx  r9d,di */
	X86_VM_RUN_OP(x86_exec_movzx_reg, X86_OP_MOVZX_REG, X86_R9, X86_RDI, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_17ea:
	/* 0x17ea: add    r9,r8 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_R8, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_17ed:
	/* 0x17ed: cmp    rdi,0x10000 */
	X86_VM_RUN_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, 65536ULL);
x86_l_17f4:
	/* 0x17f4: cmovb  r9,rdi */
	X86_VM_RUN_OP(x86_exec_cmov, X86_OP_CMOV, X86_R9, X86_RDI, X86_WIDTH_64, X86_CC_B, 0);
x86_l_17f8:
	/* 0x17f8: mov    edi,r9d */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RDI, X86_R9, X86_WIDTH_32, 0, 0);
x86_l_17fb:
	/* 0x17fb: shr    edi,0x10 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_17fe:
	/* 0x17fe: movzx  r8d,r9w */
	X86_VM_RUN_OP(x86_exec_movzx_reg, X86_OP_MOVZX_REG, X86_R8, X86_R9, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_1802:
	/* 0x1802: add    r8,rdi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R8, X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1805:
	/* 0x1805: cmp    r9,0x10000 */
	X86_VM_RUN_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_64, 0, 65536ULL);
x86_l_180c:
	/* 0x180c: cmovb  r8,r9 */
	X86_VM_RUN_OP(x86_exec_cmov, X86_OP_CMOV, X86_R8, X86_R9, X86_WIDTH_64, X86_CC_B, 0);
x86_l_1810:
	/* 0x1810: mov    edi,r8d */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RDI, X86_R8, X86_WIDTH_32, 0, 0);
x86_l_1813:
	/* 0x1813: shr    edi,0x10 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1816:
	/* 0x1816: movzx  r9d,r8w */
	X86_VM_RUN_OP(x86_exec_movzx_reg, X86_OP_MOVZX_REG, X86_R9, X86_R8, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_181a:
	/* 0x181a: add    r9,rdi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_181d:
	/* 0x181d: cmp    r8,0x10000 */
	X86_VM_RUN_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_64, 0, 65536ULL);
x86_l_1824:
	/* 0x1824: cmovb  r9,r8 */
	X86_VM_RUN_OP(x86_exec_cmov, X86_OP_CMOV, X86_R9, X86_R8, X86_WIDTH_64, X86_CC_B, 0);
x86_l_1828:
	/* 0x1828: mov    edi,r9d */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RDI, X86_R9, X86_WIDTH_32, 0, 0);
x86_l_182b:
	/* 0x182b: shr    edi,0x10 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_182e:
	/* 0x182e: add    edi,r9d */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_R9, X86_WIDTH_32, X86_ALU_ADD, 0);
x86_l_1831:
	/* 0x1831: xor    r10,r11 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R10, X86_R11, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1834:
	/* 0x1834: or     edx,0x10ac */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_OR, 4268ULL);
x86_l_183a:
	/* 0x183a: shl    rdx,0x20 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_183e:
	/* 0x183e: or     rdx,0x200c80a */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_OR, 33605642ULL);
x86_l_1845:
	/* 0x1845: cmp    r9,0x10000 */
	X86_VM_RUN_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_64, 0, 65536ULL);
x86_l_184c:
	/* 0x184c: cmovb  edi,r9d */
	X86_VM_RUN_OP(x86_exec_cmov, X86_OP_CMOV, X86_RDI, X86_R9, X86_WIDTH_32, X86_CC_B, 0);
x86_l_1850:
	/* 0x1850: shl    edi,0x10 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 16ULL);
x86_l_1853:
	/* 0x1853: xor    rdx,rsi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1856:
	/* 0x1856: movabs rsi,0x200ffff000b */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, 0, 2203318157323ULL);
x86_l_1860:
	/* 0x1860: xor    rsi,rdx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RSI, X86_RDX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1863:
	/* 0x1863: xor    rsi,rdi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RSI, X86_RDI, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1866:
	/* 0x1866: mov    rdx,r10 */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RDX, X86_R10, X86_WIDTH_64, 0, 0);
x86_l_1869:
	/* 0x1869: shl    rdx,0x6 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 6ULL);
x86_l_186d:
	/* 0x186d: mov    rdi,r10 */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RDI, X86_R10, X86_WIDTH_64, 0, 0);
x86_l_1870:
	/* 0x1870: shr    rdi,0x2 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 2ULL);
x86_l_1874:
	/* 0x1874: add    rdi,rsi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1877:
	/* 0x1877: add    rdx,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_187a:
	/* 0x187a: add    rdx,rdi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_187d:
	/* 0x187d: xor    rdx,r10 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_R10, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1880:
	/* 0x1880: mov    rsi,rdx */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RSI, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_1883:
	/* 0x1883: shl    rsi,0x6 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 6ULL);
x86_l_1887:
	/* 0x1887: add    rsi,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RSI, X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_188a:
	/* 0x188a: mov    rdi,rdx */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RDI, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_188d:
	/* 0x188d: shr    rdi,0x2 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 2ULL);
x86_l_1891:
	/* 0x1891: add    rsi,rdi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RSI, X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1894:
	/* 0x1894: add    rsi,0x3 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 3ULL);
x86_l_1898:
	/* 0x1898: xor    rsi,rdx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RSI, X86_RDX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_189b:
	/* 0x189b: mov    r9d,0x3 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_32, 0, 3ULL);
x86_l_18a1:
	/* 0x18a1: jmp    15f2 <katran_lb_consistent_hash_select_xdp+0x4f2> */
	goto x86_l_15f2;

	return XDP_ABORTED;
}

X86_VM_LICENSE();
