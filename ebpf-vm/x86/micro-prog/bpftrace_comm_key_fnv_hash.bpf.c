#define X86_VM_ENABLE_STACK 1
#define X86_VM_ENABLE_STACK_EXT 1
#include "../x86_vm_bpf.h"

SEC("xdp")
int bpftrace_comm_key_fnv_hash_x86_vm_xdp(struct xdp_md *ctx)
{
	X86_VM_DECLARE_XDP(ctx);
x86_l_1100:
	/* 0x1100: mov    r8,QWORD PTR [rdi] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R8, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1103:
	/* 0x1103: mov    rcx,QWORD PTR [rdi+0x8] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1107:
	/* 0x1107: xor    eax,eax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1109:
	/* 0x1109: cmp    r8,rcx */
	X86_VM_RUN_OP(x86_exec_cmp_reg, X86_OP_CMP_REG, X86_R8, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_110c:
	/* 0x110c: jbe    110f <bpftrace_comm_key_fnv_hash_xdp+0xf> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_BE))
		goto x86_l_110f;
x86_l_110e:
	/* 0x110e: ret */
	X86_VM_RET_RAX();
x86_l_110f:
	/* 0x110f: lea    rdx,[r8+0x8] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_RDX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1113:
	/* 0x1113: cmp    rdx,rcx */
	X86_VM_RUN_OP(x86_exec_cmp_reg, X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_1116:
	/* 0x1116: ja     110e <bpftrace_comm_key_fnv_hash_xdp+0xe> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_110e;
x86_l_1118:
	/* 0x1118: lea    rdx,[r8+0x410] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_RDX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1040ULL);
x86_l_111f:
	/* 0x111f: cmp    rdx,rcx */
	X86_VM_RUN_OP(x86_exec_cmp_reg, X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_1122:
	/* 0x1122: ja     110e <bpftrace_comm_key_fnv_hash_xdp+0xe> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_110e;
x86_l_1124:
	/* 0x1124: cmp    DWORD PTR [r8+0x8],0x20 */
	X86_VM_RUN_OP(x86_exec_cmp_mem_imm, X86_OP_CMP_MEM_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738400ULL);
x86_l_1129:
	/* 0x1129: jne    110e <bpftrace_comm_key_fnv_hash_xdp+0xe> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_110e;
x86_l_112b:
	/* 0x112b: cmp    DWORD PTR [r8+0xc],0x20 */
	X86_VM_RUN_OP(x86_exec_cmp_mem_imm, X86_OP_CMP_MEM_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607584ULL);
x86_l_1130:
	/* 0x1130: jne    110e <bpftrace_comm_key_fnv_hash_xdp+0xe> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_110e;
x86_l_1132:
	/* 0x1132: push   rbp */
	X86_VM_RUN_OP(x86_exec_push, X86_OP_PUSH, X86_REG_NONE, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_1133:
	/* 0x1133: mov    rbp,rsp */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RBP, X86_RSP, X86_WIDTH_64, 0, 0);
x86_l_1136:
	/* 0x1136: push   r15 */
	X86_VM_RUN_OP(x86_exec_push, X86_OP_PUSH, X86_REG_NONE, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_1138:
	/* 0x1138: push   r14 */
	X86_VM_RUN_OP(x86_exec_push, X86_OP_PUSH, X86_REG_NONE, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_113a:
	/* 0x113a: push   r13 */
	X86_VM_RUN_OP(x86_exec_push, X86_OP_PUSH, X86_REG_NONE, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_113c:
	/* 0x113c: push   r12 */
	X86_VM_RUN_OP(x86_exec_push, X86_OP_PUSH, X86_REG_NONE, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_113e:
	/* 0x113e: push   rbx */
	X86_VM_RUN_OP(x86_exec_push, X86_OP_PUSH, X86_REG_NONE, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_113f:
	/* 0x113f: mov    QWORD PTR [rbp-0x38],r8 */
	X86_VM_RUN_OP(x86_exec_mov_store_reg, X86_OP_MOV_STORE_REG, X86_RBP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551560ULL);
x86_l_1143:
	/* 0x1143: lea    rdi,[r8+0x2f] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_RDI, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 47ULL);
x86_l_1147:
	/* 0x1147: movabs r14,0x94d049bb133111eb */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, 0, 10723151780598845931ULL);
x86_l_1151:
	/* 0x1151: xor    r8d,r8d */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1154:
	/* 0x1154: jmp    11af <bpftrace_comm_key_fnv_hash_xdp+0xaf> */
	goto x86_l_11af;
x86_l_1156:
	/* 0x1156: cs nop WORD PTR [rax+rax*1+0x0] */
	X86_VM_RUN_OP(x86_exec_nop, X86_OP_NOP, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1160:
	/* 0x1160: shl    r12d,0x8 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 8ULL);
x86_l_1164:
	/* 0x1164: shl    r15d,0x10 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 16ULL);
x86_l_1168:
	/* 0x1168: or     r15d,r12d */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R15, X86_R12, X86_WIDTH_32, X86_ALU_OR, 0);
x86_l_116b:
	/* 0x116b: shl    ebx,0x18 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 24ULL);
x86_l_116e:
	/* 0x116e: mov    eax,r8d */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RAX, X86_R8, X86_WIDTH_32, 0, 0);
x86_l_1171:
	/* 0x1171: and    al,0x7 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_ALU_AND, 7ULL);
x86_l_1173:
	/* 0x1173: lea    ecx,[rax+0x1] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_1176:
	/* 0x1176: mov    rdx,r11 */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RDX, X86_R11, X86_WIDTH_64, 0, 0);
x86_l_1179:
	/* 0x1179: shl    rdx,cl */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 0);
x86_l_117c:
	/* 0x117c: not    al */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_ALU_NOT, 0);
x86_l_117e:
	/* 0x117e: mov    ecx,eax */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_1180:
	/* 0x1180: shr    r11,cl */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R11, X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 0);
x86_l_1183:
	/* 0x1183: or     ebx,r15d */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RBX, X86_R15, X86_WIDTH_32, X86_ALU_OR, 0);
x86_l_1186:
	/* 0x1186: or     ebx,esi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RBX, X86_RSI, X86_WIDTH_32, X86_ALU_OR, 0);
x86_l_1188:
	/* 0x1188: or     r11,rdx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R11, X86_RDX, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_118b:
	/* 0x118b: mov    rax,r14 */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RAX, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_118e:
	/* 0x118e: xor    rax,r11 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_R11, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1191:
	/* 0x1191: shl    r9,0x38 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 56ULL);
x86_l_1195:
	/* 0x1195: mov    r14d,ebx */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_R14, X86_RBX, X86_WIDTH_32, 0, 0);
x86_l_1198:
	/* 0x1198: or     r14,r9 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R14, X86_R9, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_119b:
	/* 0x119b: add    r14,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_119e:
	/* 0x119e: inc    r8 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_11a1:
	/* 0x11a1: add    rdi,0x20 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_11a5:
	/* 0x11a5: cmp    r8,0x20 */
	X86_VM_RUN_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_64, 0, 32ULL);
x86_l_11a9:
	/* 0x11a9: je     13d5 <bpftrace_comm_key_fnv_hash_xdp+0x2d5> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_E))
		goto x86_l_13d5;
x86_l_11af:
	/* 0x11af: mov    QWORD PTR [rbp-0x68],r8 */
	X86_VM_RUN_OP(x86_exec_mov_store_reg, X86_OP_MOV_STORE_REG, X86_RBP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551512ULL);
x86_l_11b3:
	/* 0x11b3: movzx  r13d,BYTE PTR [rdi-0x1f] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R13, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551585ULL);
x86_l_11b8:
	/* 0x11b8: movzx  r12d,BYTE PTR [rdi-0x1e] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R12, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551586ULL);
x86_l_11bd:
	/* 0x11bd: movzx  edx,BYTE PTR [rdi-0x1d] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551587ULL);
x86_l_11c1:
	/* 0x11c1: movzx  eax,BYTE PTR [rdi-0x1c] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551588ULL);
x86_l_11c5:
	/* 0x11c5: mov    QWORD PTR [rbp-0x60],rax */
	X86_VM_RUN_OP(x86_exec_mov_store_reg, X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551520ULL);
x86_l_11c9:
	/* 0x11c9: movzx  eax,BYTE PTR [rdi-0x1b] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551589ULL);
x86_l_11cd:
	/* 0x11cd: movzx  ecx,BYTE PTR [rdi-0x1a] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551590ULL);
x86_l_11d1:
	/* 0x11d1: movzx  esi,BYTE PTR [rdi-0x19] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551591ULL);
x86_l_11d5:
	/* 0x11d5: mov    QWORD PTR [rbp-0x58],rsi */
	X86_VM_RUN_OP(x86_exec_mov_store_reg, X86_OP_MOV_STORE_REG, X86_RBP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551528ULL);
x86_l_11d9:
	/* 0x11d9: movzx  esi,BYTE PTR [rdi-0x18] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551592ULL);
x86_l_11dd:
	/* 0x11dd: movzx  r8d,BYTE PTR [rdi-0x17] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R8, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551593ULL);
x86_l_11e2:
	/* 0x11e2: mov    QWORD PTR [rbp-0x30],r8 */
	X86_VM_RUN_OP(x86_exec_mov_store_reg, X86_OP_MOV_STORE_REG, X86_RBP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551568ULL);
x86_l_11e6:
	/* 0x11e6: movzx  r8d,BYTE PTR [rdi-0x16] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R8, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551594ULL);
x86_l_11eb:
	/* 0x11eb: movzx  r15d,BYTE PTR [rdi-0x15] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R15, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551595ULL);
x86_l_11f0:
	/* 0x11f0: movzx  ebx,BYTE PTR [rdi-0x14] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RBX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551596ULL);
x86_l_11f4:
	/* 0x11f4: mov    r9,r13 */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_R9, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_11f7:
	/* 0x11f7: movabs r11,0xcbf29ce484222325 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_64, 0, 14695981039346656037ULL);
x86_l_1201:
	/* 0x1201: xor    r9,r11 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_R11, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1204:
	/* 0x1204: movabs r10,0x100000001b3 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_64, 0, 1099511628211ULL);
x86_l_120e:
	/* 0x120e: imul   r9,r10 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_R10, X86_WIDTH_64, X86_ALU_IMUL, 0);
x86_l_1212:
	/* 0x1212: mov    QWORD PTR [rbp-0x40],r12 */
	X86_VM_RUN_OP(x86_exec_mov_store_reg, X86_OP_MOV_STORE_REG, X86_RBP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551552ULL);
x86_l_1216:
	/* 0x1216: xor    r9,r12 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_R12, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1219:
	/* 0x1219: mov    r12,r8 */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_R12, X86_R8, X86_WIDTH_64, 0, 0);
x86_l_121c:
	/* 0x121c: mov    r8,rsi */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_R8, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_121f:
	/* 0x121f: mov    rsi,QWORD PTR [rbp-0x58] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RSI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551528ULL);
x86_l_1223:
	/* 0x1223: imul   r9,r10 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_R10, X86_WIDTH_64, X86_ALU_IMUL, 0);
x86_l_1227:
	/* 0x1227: mov    QWORD PTR [rbp-0x48],rdx */
	X86_VM_RUN_OP(x86_exec_mov_store_reg, X86_OP_MOV_STORE_REG, X86_RBP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551544ULL);
x86_l_122b:
	/* 0x122b: xor    r9,rdx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_RDX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_122e:
	/* 0x122e: mov    rdx,QWORD PTR [rbp-0x60] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551520ULL);
x86_l_1232:
	/* 0x1232: imul   r9,r10 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_R10, X86_WIDTH_64, X86_ALU_IMUL, 0);
x86_l_1236:
	/* 0x1236: xor    r9,rdx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_RDX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1239:
	/* 0x1239: imul   r9,r10 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_R10, X86_WIDTH_64, X86_ALU_IMUL, 0);
x86_l_123d:
	/* 0x123d: mov    QWORD PTR [rbp-0x50],rax */
	X86_VM_RUN_OP(x86_exec_mov_store_reg, X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551536ULL);
x86_l_1241:
	/* 0x1241: xor    r9,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1244:
	/* 0x1244: imul   r9,r10 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_R10, X86_WIDTH_64, X86_ALU_IMUL, 0);
x86_l_1248:
	/* 0x1248: xor    r9,rcx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_RCX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_124b:
	/* 0x124b: imul   r9,r10 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_R10, X86_WIDTH_64, X86_ALU_IMUL, 0);
x86_l_124f:
	/* 0x124f: xor    r9,rsi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_RSI, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1252:
	/* 0x1252: imul   r9,r10 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_R10, X86_WIDTH_64, X86_ALU_IMUL, 0);
x86_l_1256:
	/* 0x1256: xor    r9,r8 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_R8, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1259:
	/* 0x1259: imul   r9,r10 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_R10, X86_WIDTH_64, X86_ALU_IMUL, 0);
x86_l_125d:
	/* 0x125d: xor    r9,QWORD PTR [rbp-0x30] */
	X86_VM_RUN_OP(x86_exec_alu_mem, X86_OP_ALU_MEM, X86_R9, X86_RBP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 18446744073709551568ULL);
x86_l_1261:
	/* 0x1261: imul   r9,r10 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_R10, X86_WIDTH_64, X86_ALU_IMUL, 0);
x86_l_1265:
	/* 0x1265: xor    r9,r12 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_R12, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1268:
	/* 0x1268: imul   r9,r10 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_R10, X86_WIDTH_64, X86_ALU_IMUL, 0);
x86_l_126c:
	/* 0x126c: xor    r9,r15 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_R15, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_126f:
	/* 0x126f: imul   r9,r10 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_R10, X86_WIDTH_64, X86_ALU_IMUL, 0);
x86_l_1273:
	/* 0x1273: mov    r11,rbx */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_R11, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_1276:
	/* 0x1276: xor    r11,r9 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R11, X86_R9, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1279:
	/* 0x1279: imul   r11,r10 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R11, X86_R10, X86_WIDTH_64, X86_ALU_IMUL, 0);
x86_l_127d:
	/* 0x127d: movzx  r9d,BYTE PTR [rdi-0xf] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R9, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551601ULL);
x86_l_1282:
	/* 0x1282: xor    r9,r11 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_R11, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1285:
	/* 0x1285: imul   r9,r10 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_R10, X86_WIDTH_64, X86_ALU_IMUL, 0);
x86_l_1289:
	/* 0x1289: movzx  r11d,BYTE PTR [rdi-0xe] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R11, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551602ULL);
x86_l_128e:
	/* 0x128e: xor    r11,r9 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R11, X86_R9, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1291:
	/* 0x1291: imul   r11,r10 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R11, X86_R10, X86_WIDTH_64, X86_ALU_IMUL, 0);
x86_l_1295:
	/* 0x1295: movzx  r9d,BYTE PTR [rdi-0xd] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R9, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551603ULL);
x86_l_129a:
	/* 0x129a: xor    r9,r11 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_R11, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_129d:
	/* 0x129d: imul   r9,r10 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_R10, X86_WIDTH_64, X86_ALU_IMUL, 0);
x86_l_12a1:
	/* 0x12a1: movzx  r11d,BYTE PTR [rdi-0xc] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R11, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551604ULL);
x86_l_12a6:
	/* 0x12a6: xor    r11,r9 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R11, X86_R9, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_12a9:
	/* 0x12a9: imul   r11,r10 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R11, X86_R10, X86_WIDTH_64, X86_ALU_IMUL, 0);
x86_l_12ad:
	/* 0x12ad: movzx  r9d,BYTE PTR [rdi-0xb] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R9, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551605ULL);
x86_l_12b2:
	/* 0x12b2: xor    r9,r11 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_R11, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_12b5:
	/* 0x12b5: imul   r9,r10 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_R10, X86_WIDTH_64, X86_ALU_IMUL, 0);
x86_l_12b9:
	/* 0x12b9: movzx  r11d,BYTE PTR [rdi-0xa] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R11, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551606ULL);
x86_l_12be:
	/* 0x12be: xor    r11,r9 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R11, X86_R9, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_12c1:
	/* 0x12c1: imul   r11,r10 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R11, X86_R10, X86_WIDTH_64, X86_ALU_IMUL, 0);
x86_l_12c5:
	/* 0x12c5: movzx  r9d,BYTE PTR [rdi-0x9] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R9, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551607ULL);
x86_l_12ca:
	/* 0x12ca: xor    r9,r11 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_R11, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_12cd:
	/* 0x12cd: imul   r9,r10 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_R10, X86_WIDTH_64, X86_ALU_IMUL, 0);
x86_l_12d1:
	/* 0x12d1: movzx  r11d,BYTE PTR [rdi-0x8] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R11, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551608ULL);
x86_l_12d6:
	/* 0x12d6: xor    r11,r9 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R11, X86_R9, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_12d9:
	/* 0x12d9: imul   r11,r10 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R11, X86_R10, X86_WIDTH_64, X86_ALU_IMUL, 0);
x86_l_12dd:
	/* 0x12dd: movzx  r9d,BYTE PTR [rdi-0x7] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R9, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551609ULL);
x86_l_12e2:
	/* 0x12e2: xor    r9,r11 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_R11, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_12e5:
	/* 0x12e5: imul   r9,r10 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_R10, X86_WIDTH_64, X86_ALU_IMUL, 0);
x86_l_12e9:
	/* 0x12e9: movzx  r11d,BYTE PTR [rdi-0x6] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R11, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551610ULL);
x86_l_12ee:
	/* 0x12ee: xor    r11,r9 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R11, X86_R9, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_12f1:
	/* 0x12f1: imul   r11,r10 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R11, X86_R10, X86_WIDTH_64, X86_ALU_IMUL, 0);
x86_l_12f5:
	/* 0x12f5: movzx  r9d,BYTE PTR [rdi-0x5] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R9, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551611ULL);
x86_l_12fa:
	/* 0x12fa: xor    r9,r11 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_R11, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_12fd:
	/* 0x12fd: imul   r9,r10 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_R10, X86_WIDTH_64, X86_ALU_IMUL, 0);
x86_l_1301:
	/* 0x1301: movzx  r11d,BYTE PTR [rdi-0x4] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R11, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551612ULL);
x86_l_1306:
	/* 0x1306: xor    r11,r9 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R11, X86_R9, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1309:
	/* 0x1309: imul   r11,r10 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R11, X86_R10, X86_WIDTH_64, X86_ALU_IMUL, 0);
x86_l_130d:
	/* 0x130d: movzx  r9d,BYTE PTR [rdi-0x3] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R9, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551613ULL);
x86_l_1312:
	/* 0x1312: xor    r9,r11 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_R11, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1315:
	/* 0x1315: imul   r9,r10 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_R10, X86_WIDTH_64, X86_ALU_IMUL, 0);
x86_l_1319:
	/* 0x1319: movzx  r11d,BYTE PTR [rdi-0x2] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R11, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551614ULL);
x86_l_131e:
	/* 0x131e: xor    r11,r9 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R11, X86_R9, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1321:
	/* 0x1321: imul   r11,r10 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R11, X86_R10, X86_WIDTH_64, X86_ALU_IMUL, 0);
x86_l_1325:
	/* 0x1325: movzx  r9d,BYTE PTR [rdi-0x1] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R9, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551615ULL);
x86_l_132a:
	/* 0x132a: xor    r9,r11 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_R11, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_132d:
	/* 0x132d: imul   r9,r10 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_R10, X86_WIDTH_64, X86_ALU_IMUL, 0);
x86_l_1331:
	/* 0x1331: movzx  r11d,BYTE PTR [rdi] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R11, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1335:
	/* 0x1335: xor    r11,r9 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R11, X86_R9, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1338:
	/* 0x1338: imul   r11,r10 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R11, X86_R10, X86_WIDTH_64, X86_ALU_IMUL, 0);
x86_l_133c:
	/* 0x133c: movzx  r9d,BYTE PTR [rdi-0x13] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R9, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551597ULL);
x86_l_1341:
	/* 0x1341: test   r9b,0x1 */
	X86_VM_RUN_OP(x86_exec_test_imm, X86_OP_TEST_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_1345:
	/* 0x1345: jne    1350 <bpftrace_comm_key_fnv_hash_xdp+0x250> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_1350;
x86_l_1347:
	/* 0x1347: mov    rsi,QWORD PTR [rbp-0x30] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RSI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551568ULL);
x86_l_134b:
	/* 0x134b: jmp    13ad <bpftrace_comm_key_fnv_hash_xdp+0x2ad> */
	goto x86_l_13ad;
x86_l_134d:
	/* 0x134d: nop    DWORD PTR [rax] */
	X86_VM_RUN_OP(x86_exec_nop, X86_OP_NOP, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1350:
	/* 0x1350: mov    rax,rcx */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RAX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_1353:
	/* 0x1353: shl    r8d,0x18 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 24ULL);
x86_l_1357:
	/* 0x1357: shl    esi,0x10 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 16ULL);
x86_l_135a:
	/* 0x135a: mov    r10,rcx */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_R10, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_135d:
	/* 0x135d: shl    r10d,0x8 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 8ULL);
x86_l_1361:
	/* 0x1361: mov    rax,QWORD PTR [rbp-0x48] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551544ULL);
x86_l_1365:
	/* 0x1365: shl    rax,0x30 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 48ULL);
x86_l_1369:
	/* 0x1369: shl    rdx,0x38 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 56ULL);
x86_l_136d:
	/* 0x136d: mov    rcx,QWORD PTR [rbp-0x40] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551552ULL);
x86_l_1371:
	/* 0x1371: shl    rcx,0x28 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 40ULL);
x86_l_1375:
	/* 0x1375: shl    r13,0x20 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_1379:
	/* 0x1379: or     r13,rcx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R13, X86_RCX, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_137c:
	/* 0x137c: or     r13,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_137f:
	/* 0x137f: or     r13,rdx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R13, X86_RDX, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_1382:
	/* 0x1382: or     r13,r10 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R13, X86_R10, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_1385:
	/* 0x1385: or     r13,rsi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R13, X86_RSI, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_1388:
	/* 0x1388: or     r13,r8 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R13, X86_R8, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_138b:
	/* 0x138b: or     r13,QWORD PTR [rbp-0x50] */
	X86_VM_RUN_OP(x86_exec_alu_mem, X86_OP_ALU_MEM, X86_R13, X86_RBP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 18446744073709551536ULL);
x86_l_138f:
	/* 0x138f: mov    rsi,QWORD PTR [rbp-0x30] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RSI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551568ULL);
x86_l_1393:
	/* 0x1393: mov    eax,esi */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RAX, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_1395:
	/* 0x1395: and    al,0x7 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_ALU_AND, 7ULL);
x86_l_1397:
	/* 0x1397: lea    ecx,[rax+0x1] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_139a:
	/* 0x139a: mov    rdx,r13 */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RDX, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_139d:
	/* 0x139d: shl    rdx,cl */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 0);
x86_l_13a0:
	/* 0x13a0: not    al */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_ALU_NOT, 0);
x86_l_13a2:
	/* 0x13a2: mov    ecx,eax */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_13a4:
	/* 0x13a4: shr    r13,cl */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R13, X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 0);
x86_l_13a7:
	/* 0x13a7: or     r13,rdx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R13, X86_RDX, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_13aa:
	/* 0x13aa: xor    r11,r13 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R11, X86_R13, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_13ad:
	/* 0x13ad: test   r9b,0x2 */
	X86_VM_RUN_OP(x86_exec_test_imm, X86_OP_TEST_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_8, 0, 2ULL);
x86_l_13b1:
	/* 0x13b1: mov    r8,QWORD PTR [rbp-0x68] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R8, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551512ULL);
x86_l_13b5:
	/* 0x13b5: je     1160 <bpftrace_comm_key_fnv_hash_xdp+0x60> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_E))
		goto x86_l_1160;
x86_l_13bb:
	/* 0x13bb: movabs rax,0x9e3779b185ebca87 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, 0, 11400714785074694791ULL);
x86_l_13c5:
	/* 0x13c5: add    rax,r11 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_R11, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_13c8:
	/* 0x13c8: cmp    BYTE PTR [rdi-0xf],0x70 */
	X86_VM_RUN_OP(x86_exec_cmp_mem_imm, X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744009285042288ULL);
x86_l_13cc:
	/* 0x13cc: cmove  r11,rax */
	X86_VM_RUN_OP(x86_exec_cmov, X86_OP_CMOV, X86_R11, X86_RAX, X86_WIDTH_64, X86_CC_E, 0);
x86_l_13d0:
	/* 0x13d0: jmp    1160 <bpftrace_comm_key_fnv_hash_xdp+0x60> */
	goto x86_l_1160;
x86_l_13d5:
	/* 0x13d5: mov    rax,QWORD PTR [rbp-0x38] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551560ULL);
x86_l_13d9:
	/* 0x13d9: mov    QWORD PTR [rax],r14 */
	X86_VM_RUN_OP(x86_exec_mov_store_reg, X86_OP_MOV_STORE_REG, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13dc:
	/* 0x13dc: mov    eax,0x2 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_13e1:
	/* 0x13e1: pop    rbx */
	X86_VM_RUN_OP(x86_exec_pop, X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_13e2:
	/* 0x13e2: pop    r12 */
	X86_VM_RUN_OP(x86_exec_pop, X86_OP_POP, X86_R12, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_13e4:
	/* 0x13e4: pop    r13 */
	X86_VM_RUN_OP(x86_exec_pop, X86_OP_POP, X86_R13, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_13e6:
	/* 0x13e6: pop    r14 */
	X86_VM_RUN_OP(x86_exec_pop, X86_OP_POP, X86_R14, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_13e8:
	/* 0x13e8: pop    r15 */
	X86_VM_RUN_OP(x86_exec_pop, X86_OP_POP, X86_R15, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_13ea:
	/* 0x13ea: pop    rbp */
	X86_VM_RUN_OP(x86_exec_pop, X86_OP_POP, X86_RBP, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_13eb:
	/* 0x13eb: ret */
	X86_VM_RET_RAX();
	return XDP_ABORTED;
}

X86_VM_LICENSE();
