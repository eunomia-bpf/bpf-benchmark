#define X86_VM_ENABLE_STACK 1
#include "../x86_vm_bpf.h"

SEC("xdp")
int siphash_rotate64_mixer_x86_vm_xdp(struct xdp_md *ctx)
{
	X86_VM_DECLARE_XDP(ctx);
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
	/* 0x110c: ja     156e <siphash_rotate64_mixer_xdp+0x46e> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_156e;
x86_l_1112:
	/* 0x1112: lea    rsi,[rcx+0x8] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1116:
	/* 0x1116: cmp    rsi,rdx */
	X86_VM_RUN_OP(x86_exec_cmp_reg, X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_1119:
	/* 0x1119: ja     156e <siphash_rotate64_mixer_xdp+0x46e> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_156e;
x86_l_111f:
	/* 0x111f: lea    rsi,[rcx+0x48] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1123:
	/* 0x1123: cmp    rsi,rdx */
	X86_VM_RUN_OP(x86_exec_cmp_reg, X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_1126:
	/* 0x1126: ja     156e <siphash_rotate64_mixer_xdp+0x46e> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_156e;
x86_l_112c:
	/* 0x112c: push   rbp */
	X86_VM_RUN_OP(x86_exec_push, X86_OP_PUSH, X86_REG_NONE, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_112d:
	/* 0x112d: mov    rbp,rsp */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RBP, X86_RSP, X86_WIDTH_64, 0, 0);
x86_l_1130:
	/* 0x1130: mov    r9,QWORD PTR [rcx+0x8] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R9, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1134:
	/* 0x1134: movabs rdi,0x7465646279746573 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, 8387220255154660723ULL);
x86_l_113e:
	/* 0x113e: xor    rdi,r9 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_R9, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1141:
	/* 0x1141: movabs rdx,0x6c7967656e657261 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, 0, 7816392313619706465ULL);
x86_l_114b:
	/* 0x114b: add    rdx,rdi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_114e:
	/* 0x114e: movabs rax,0xa60c596fc19fead0 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, 0, 11965036646541290192ULL);
x86_l_1158:
	/* 0x1158: add    rax,rdi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_115b:
	/* 0x115b: rol    rdi,0x10 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 16ULL);
x86_l_115f:
	/* 0x115f: xor    rdi,rdx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_RDX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1162:
	/* 0x1162: movabs r8,0xded7d4e2d7dedfc6 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_64, 0, 16057537067162197958ULL);
x86_l_116c:
	/* 0x116c: add    r8,rdi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R8, X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_116f:
	/* 0x116f: rol    rdi,0x15 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 21ULL);
x86_l_1173:
	/* 0x1173: movabs rdx,0xe414a674f0de7325 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, 0, 16434943961369309989ULL);
x86_l_117d:
	/* 0x117d: xor    rdx,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1180:
	/* 0x1180: rol    rax,0x20 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 32ULL);
x86_l_1184:
	/* 0x1184: xor    rdi,r8 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_R8, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1187:
	/* 0x1187: add    r8,rdx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R8, X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_118a:
	/* 0x118a: rol    rdx,0xd */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 13ULL);
x86_l_118e:
	/* 0x118e: xor    rdx,r8 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_R8, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1191:
	/* 0x1191: rol    r8,0x20 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 32ULL);
x86_l_1195:
	/* 0x1195: add    rax,rdi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1198:
	/* 0x1198: rol    rdi,0x10 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 16ULL);
x86_l_119c:
	/* 0x119c: xor    rdi,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_119f:
	/* 0x119f: add    r8,rdi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R8, X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_11a2:
	/* 0x11a2: rol    rdi,0x15 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 21ULL);
x86_l_11a6:
	/* 0x11a6: add    rax,rdx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_11a9:
	/* 0x11a9: rol    rdx,0x11 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 17ULL);
x86_l_11ad:
	/* 0x11ad: mov    rsi,QWORD PTR [rcx+0x10] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11b1:
	/* 0x11b1: xor    rdx,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_11b4:
	/* 0x11b4: rol    rax,0x20 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 32ULL);
x86_l_11b8:
	/* 0x11b8: xor    r9,r8 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_R8, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_11bb:
	/* 0x11bb: add    r9,rdx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_11be:
	/* 0x11be: rol    rdx,0xd */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 13ULL);
x86_l_11c2:
	/* 0x11c2: xor    r8,rsi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R8, X86_RSI, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_11c5:
	/* 0x11c5: xor    rdx,r9 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_R9, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_11c8:
	/* 0x11c8: rol    r9,0x20 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 32ULL);
x86_l_11cc:
	/* 0x11cc: xor    r8,rdi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R8, X86_RDI, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_11cf:
	/* 0x11cf: add    rax,r8 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_R8, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_11d2:
	/* 0x11d2: rol    r8,0x10 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 16ULL);
x86_l_11d6:
	/* 0x11d6: xor    r8,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R8, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_11d9:
	/* 0x11d9: add    r9,r8 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_R8, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_11dc:
	/* 0x11dc: rol    r8,0x15 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 21ULL);
x86_l_11e0:
	/* 0x11e0: add    rax,rdx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_11e3:
	/* 0x11e3: rol    rdx,0x11 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 17ULL);
x86_l_11e7:
	/* 0x11e7: xor    rdx,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_11ea:
	/* 0x11ea: rol    rax,0x20 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 32ULL);
x86_l_11ee:
	/* 0x11ee: xor    r8,r9 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R8, X86_R9, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_11f1:
	/* 0x11f1: add    r9,rdx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_11f4:
	/* 0x11f4: rol    rdx,0xd */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 13ULL);
x86_l_11f8:
	/* 0x11f8: xor    rdx,r9 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_R9, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_11fb:
	/* 0x11fb: rol    r9,0x20 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 32ULL);
x86_l_11ff:
	/* 0x11ff: add    rax,r8 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_R8, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1202:
	/* 0x1202: rol    r8,0x10 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 16ULL);
x86_l_1206:
	/* 0x1206: xor    r8,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R8, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1209:
	/* 0x1209: add    r9,r8 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_R8, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_120c:
	/* 0x120c: rol    r8,0x15 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 21ULL);
x86_l_1210:
	/* 0x1210: add    rax,rdx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1213:
	/* 0x1213: rol    rdx,0x11 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 17ULL);
x86_l_1217:
	/* 0x1217: mov    rdi,QWORD PTR [rcx+0x18] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_121b:
	/* 0x121b: xor    rdx,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_121e:
	/* 0x121e: rol    rax,0x20 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 32ULL);
x86_l_1222:
	/* 0x1222: xor    rsi,r9 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RSI, X86_R9, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1225:
	/* 0x1225: add    rsi,rdx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RSI, X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1228:
	/* 0x1228: rol    rdx,0xd */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 13ULL);
x86_l_122c:
	/* 0x122c: xor    r9,rdi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_RDI, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_122f:
	/* 0x122f: xor    rdx,rsi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1232:
	/* 0x1232: rol    rsi,0x20 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 32ULL);
x86_l_1236:
	/* 0x1236: xor    r9,r8 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_R8, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1239:
	/* 0x1239: add    rax,r9 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_R9, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_123c:
	/* 0x123c: rol    r9,0x10 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 16ULL);
x86_l_1240:
	/* 0x1240: xor    r9,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1243:
	/* 0x1243: add    rsi,r9 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RSI, X86_R9, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1246:
	/* 0x1246: rol    r9,0x15 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 21ULL);
x86_l_124a:
	/* 0x124a: add    rax,rdx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_124d:
	/* 0x124d: rol    rdx,0x11 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 17ULL);
x86_l_1251:
	/* 0x1251: xor    rdx,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1254:
	/* 0x1254: rol    rax,0x20 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 32ULL);
x86_l_1258:
	/* 0x1258: xor    r9,rsi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_RSI, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_125b:
	/* 0x125b: add    rsi,rdx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RSI, X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_125e:
	/* 0x125e: rol    rdx,0xd */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 13ULL);
x86_l_1262:
	/* 0x1262: xor    rdx,rsi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1265:
	/* 0x1265: rol    rsi,0x20 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 32ULL);
x86_l_1269:
	/* 0x1269: add    rax,r9 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_R9, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_126c:
	/* 0x126c: rol    r9,0x10 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 16ULL);
x86_l_1270:
	/* 0x1270: xor    r9,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1273:
	/* 0x1273: add    rsi,r9 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RSI, X86_R9, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1276:
	/* 0x1276: rol    r9,0x15 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 21ULL);
x86_l_127a:
	/* 0x127a: add    rax,rdx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_127d:
	/* 0x127d: rol    rdx,0x11 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 17ULL);
x86_l_1281:
	/* 0x1281: mov    r8,QWORD PTR [rcx+0x20] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R8, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1285:
	/* 0x1285: xor    rdx,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1288:
	/* 0x1288: rol    rax,0x20 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 32ULL);
x86_l_128c:
	/* 0x128c: xor    rdi,rsi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_128f:
	/* 0x128f: add    rdi,rdx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1292:
	/* 0x1292: rol    rdx,0xd */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 13ULL);
x86_l_1296:
	/* 0x1296: xor    rsi,r8 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RSI, X86_R8, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1299:
	/* 0x1299: xor    rdx,rdi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RDI, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_129c:
	/* 0x129c: rol    rdi,0x20 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 32ULL);
x86_l_12a0:
	/* 0x12a0: xor    rsi,r9 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RSI, X86_R9, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_12a3:
	/* 0x12a3: add    rax,rsi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_12a6:
	/* 0x12a6: rol    rsi,0x10 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 16ULL);
x86_l_12aa:
	/* 0x12aa: xor    rsi,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RSI, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_12ad:
	/* 0x12ad: add    rdi,rsi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_12b0:
	/* 0x12b0: rol    rsi,0x15 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 21ULL);
x86_l_12b4:
	/* 0x12b4: add    rax,rdx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_12b7:
	/* 0x12b7: rol    rdx,0x11 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 17ULL);
x86_l_12bb:
	/* 0x12bb: xor    rdx,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_12be:
	/* 0x12be: rol    rax,0x20 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 32ULL);
x86_l_12c2:
	/* 0x12c2: xor    rsi,rdi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RSI, X86_RDI, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_12c5:
	/* 0x12c5: add    rdi,rdx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_12c8:
	/* 0x12c8: rol    rdx,0xd */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 13ULL);
x86_l_12cc:
	/* 0x12cc: xor    rdx,rdi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RDI, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_12cf:
	/* 0x12cf: rol    rdi,0x20 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 32ULL);
x86_l_12d3:
	/* 0x12d3: add    rax,rsi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_12d6:
	/* 0x12d6: rol    rsi,0x10 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 16ULL);
x86_l_12da:
	/* 0x12da: xor    rsi,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RSI, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_12dd:
	/* 0x12dd: add    rdi,rsi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_12e0:
	/* 0x12e0: rol    rsi,0x15 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 21ULL);
x86_l_12e4:
	/* 0x12e4: add    rax,rdx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_12e7:
	/* 0x12e7: rol    rdx,0x11 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 17ULL);
x86_l_12eb:
	/* 0x12eb: mov    r9,QWORD PTR [rcx+0x28] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R9, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_12ef:
	/* 0x12ef: xor    rdx,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_12f2:
	/* 0x12f2: rol    rax,0x20 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 32ULL);
x86_l_12f6:
	/* 0x12f6: xor    r8,rdi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R8, X86_RDI, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_12f9:
	/* 0x12f9: add    r8,rdx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R8, X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_12fc:
	/* 0x12fc: rol    rdx,0xd */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 13ULL);
x86_l_1300:
	/* 0x1300: xor    rdi,r9 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_R9, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1303:
	/* 0x1303: xor    rdx,r8 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_R8, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1306:
	/* 0x1306: rol    r8,0x20 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 32ULL);
x86_l_130a:
	/* 0x130a: xor    rdi,rsi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_130d:
	/* 0x130d: add    rax,rdi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1310:
	/* 0x1310: rol    rdi,0x10 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 16ULL);
x86_l_1314:
	/* 0x1314: xor    rdi,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1317:
	/* 0x1317: add    r8,rdi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R8, X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_131a:
	/* 0x131a: rol    rdi,0x15 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 21ULL);
x86_l_131e:
	/* 0x131e: add    rax,rdx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1321:
	/* 0x1321: rol    rdx,0x11 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 17ULL);
x86_l_1325:
	/* 0x1325: xor    rdx,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1328:
	/* 0x1328: rol    rax,0x20 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 32ULL);
x86_l_132c:
	/* 0x132c: xor    rdi,r8 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_R8, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_132f:
	/* 0x132f: add    r8,rdx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R8, X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1332:
	/* 0x1332: rol    rdx,0xd */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 13ULL);
x86_l_1336:
	/* 0x1336: xor    rdx,r8 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_R8, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1339:
	/* 0x1339: rol    r8,0x20 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 32ULL);
x86_l_133d:
	/* 0x133d: add    rax,rdi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1340:
	/* 0x1340: rol    rdi,0x10 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 16ULL);
x86_l_1344:
	/* 0x1344: xor    rdi,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1347:
	/* 0x1347: add    r8,rdi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R8, X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_134a:
	/* 0x134a: rol    rdi,0x15 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 21ULL);
x86_l_134e:
	/* 0x134e: add    rax,rdx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1351:
	/* 0x1351: rol    rdx,0x11 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 17ULL);
x86_l_1355:
	/* 0x1355: mov    rsi,QWORD PTR [rcx+0x30] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1359:
	/* 0x1359: xor    rdx,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_135c:
	/* 0x135c: rol    rax,0x20 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 32ULL);
x86_l_1360:
	/* 0x1360: xor    r9,r8 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_R8, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1363:
	/* 0x1363: add    r9,rdx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1366:
	/* 0x1366: rol    rdx,0xd */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 13ULL);
x86_l_136a:
	/* 0x136a: xor    r8,rsi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R8, X86_RSI, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_136d:
	/* 0x136d: xor    rdx,r9 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_R9, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1370:
	/* 0x1370: rol    r9,0x20 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 32ULL);
x86_l_1374:
	/* 0x1374: xor    r8,rdi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R8, X86_RDI, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1377:
	/* 0x1377: add    rax,r8 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_R8, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_137a:
	/* 0x137a: rol    r8,0x10 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 16ULL);
x86_l_137e:
	/* 0x137e: xor    r8,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R8, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1381:
	/* 0x1381: add    r9,r8 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_R8, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1384:
	/* 0x1384: rol    r8,0x15 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 21ULL);
x86_l_1388:
	/* 0x1388: add    rax,rdx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_138b:
	/* 0x138b: rol    rdx,0x11 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 17ULL);
x86_l_138f:
	/* 0x138f: xor    rdx,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1392:
	/* 0x1392: rol    rax,0x20 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 32ULL);
x86_l_1396:
	/* 0x1396: xor    r8,r9 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R8, X86_R9, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1399:
	/* 0x1399: add    r9,rdx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_139c:
	/* 0x139c: rol    rdx,0xd */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 13ULL);
x86_l_13a0:
	/* 0x13a0: xor    rdx,r9 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_R9, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_13a3:
	/* 0x13a3: rol    r9,0x20 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 32ULL);
x86_l_13a7:
	/* 0x13a7: add    rax,r8 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_R8, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_13aa:
	/* 0x13aa: rol    r8,0x10 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 16ULL);
x86_l_13ae:
	/* 0x13ae: xor    r8,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R8, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_13b1:
	/* 0x13b1: add    r9,r8 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_R8, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_13b4:
	/* 0x13b4: rol    r8,0x15 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 21ULL);
x86_l_13b8:
	/* 0x13b8: add    rax,rdx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_13bb:
	/* 0x13bb: rol    rdx,0x11 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 17ULL);
x86_l_13bf:
	/* 0x13bf: mov    rdi,QWORD PTR [rcx+0x38] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_13c3:
	/* 0x13c3: xor    rdx,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_13c6:
	/* 0x13c6: rol    rax,0x20 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 32ULL);
x86_l_13ca:
	/* 0x13ca: xor    rsi,r9 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RSI, X86_R9, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_13cd:
	/* 0x13cd: add    rsi,rdx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RSI, X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_13d0:
	/* 0x13d0: rol    rdx,0xd */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 13ULL);
x86_l_13d4:
	/* 0x13d4: xor    r9,rdi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_RDI, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_13d7:
	/* 0x13d7: xor    rdx,rsi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_13da:
	/* 0x13da: rol    rsi,0x20 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 32ULL);
x86_l_13de:
	/* 0x13de: xor    r9,r8 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_R8, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_13e1:
	/* 0x13e1: add    rax,r9 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_R9, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_13e4:
	/* 0x13e4: rol    r9,0x10 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 16ULL);
x86_l_13e8:
	/* 0x13e8: xor    r9,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_13eb:
	/* 0x13eb: add    rsi,r9 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RSI, X86_R9, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_13ee:
	/* 0x13ee: rol    r9,0x15 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 21ULL);
x86_l_13f2:
	/* 0x13f2: add    rax,rdx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_13f5:
	/* 0x13f5: rol    rdx,0x11 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 17ULL);
x86_l_13f9:
	/* 0x13f9: xor    rdx,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_13fc:
	/* 0x13fc: rol    rax,0x20 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 32ULL);
x86_l_1400:
	/* 0x1400: xor    r9,rsi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_RSI, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1403:
	/* 0x1403: add    rsi,rdx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RSI, X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1406:
	/* 0x1406: rol    rdx,0xd */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 13ULL);
x86_l_140a:
	/* 0x140a: xor    rdx,rsi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_140d:
	/* 0x140d: rol    rsi,0x20 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 32ULL);
x86_l_1411:
	/* 0x1411: add    rax,r9 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_R9, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1414:
	/* 0x1414: rol    r9,0x10 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 16ULL);
x86_l_1418:
	/* 0x1418: xor    r9,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R9, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_141b:
	/* 0x141b: add    rsi,r9 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RSI, X86_R9, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_141e:
	/* 0x141e: rol    r9,0x15 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 21ULL);
x86_l_1422:
	/* 0x1422: add    rax,rdx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1425:
	/* 0x1425: rol    rdx,0x11 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 17ULL);
x86_l_1429:
	/* 0x1429: mov    r8,QWORD PTR [rcx+0x40] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R8, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_142d:
	/* 0x142d: xor    rdx,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1430:
	/* 0x1430: rol    rax,0x20 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 32ULL);
x86_l_1434:
	/* 0x1434: xor    rdi,rsi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1437:
	/* 0x1437: add    rdi,rdx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_143a:
	/* 0x143a: rol    rdx,0xd */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 13ULL);
x86_l_143e:
	/* 0x143e: xor    rsi,r8 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RSI, X86_R8, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1441:
	/* 0x1441: xor    rdx,rdi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RDI, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1444:
	/* 0x1444: rol    rdi,0x20 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 32ULL);
x86_l_1448:
	/* 0x1448: xor    rsi,r9 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RSI, X86_R9, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_144b:
	/* 0x144b: add    rax,rsi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_144e:
	/* 0x144e: rol    rsi,0x10 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 16ULL);
x86_l_1452:
	/* 0x1452: xor    rsi,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RSI, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1455:
	/* 0x1455: add    rdi,rsi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1458:
	/* 0x1458: rol    rsi,0x15 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 21ULL);
x86_l_145c:
	/* 0x145c: add    rax,rdx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_145f:
	/* 0x145f: rol    rdx,0x11 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 17ULL);
x86_l_1463:
	/* 0x1463: xor    rdx,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1466:
	/* 0x1466: rol    rax,0x20 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 32ULL);
x86_l_146a:
	/* 0x146a: xor    rsi,rdi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RSI, X86_RDI, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_146d:
	/* 0x146d: add    rdi,rdx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1470:
	/* 0x1470: rol    rdx,0xd */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 13ULL);
x86_l_1474:
	/* 0x1474: xor    rdx,rdi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RDI, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1477:
	/* 0x1477: rol    rdi,0x20 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 32ULL);
x86_l_147b:
	/* 0x147b: add    rax,rsi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_147e:
	/* 0x147e: rol    rsi,0x10 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 16ULL);
x86_l_1482:
	/* 0x1482: xor    rsi,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RSI, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1485:
	/* 0x1485: add    rdi,rsi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1488:
	/* 0x1488: rol    rsi,0x15 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 21ULL);
x86_l_148c:
	/* 0x148c: add    rax,rdx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_148f:
	/* 0x148f: rol    rdx,0x11 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 17ULL);
x86_l_1493:
	/* 0x1493: xor    rsi,rdi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RSI, X86_RDI, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1496:
	/* 0x1496: xor    rdx,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1499:
	/* 0x1499: rol    rax,0x20 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 32ULL);
x86_l_149d:
	/* 0x149d: xor    rdi,r8 */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_R8, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_14a0:
	/* 0x14a0: add    rdi,rdx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_14a3:
	/* 0x14a3: rol    rdx,0xd */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 13ULL);
x86_l_14a7:
	/* 0x14a7: xor    rdx,rdi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RDI, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_14aa:
	/* 0x14aa: rol    rdi,0x20 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 32ULL);
x86_l_14ae:
	/* 0x14ae: xor    rax,0xff */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_XOR, 255ULL);
x86_l_14b4:
	/* 0x14b4: add    rax,rsi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_14b7:
	/* 0x14b7: rol    rsi,0x10 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 16ULL);
x86_l_14bb:
	/* 0x14bb: xor    rsi,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RSI, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_14be:
	/* 0x14be: add    rdi,rsi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_14c1:
	/* 0x14c1: rol    rsi,0x15 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 21ULL);
x86_l_14c5:
	/* 0x14c5: add    rax,rdx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_14c8:
	/* 0x14c8: rol    rdx,0x11 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 17ULL);
x86_l_14cc:
	/* 0x14cc: xor    rdx,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_14cf:
	/* 0x14cf: rol    rax,0x20 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 32ULL);
x86_l_14d3:
	/* 0x14d3: xor    rsi,rdi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RSI, X86_RDI, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_14d6:
	/* 0x14d6: add    rdi,rdx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_14d9:
	/* 0x14d9: rol    rdx,0xd */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 13ULL);
x86_l_14dd:
	/* 0x14dd: xor    rdx,rdi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RDI, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_14e0:
	/* 0x14e0: rol    rdi,0x20 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 32ULL);
x86_l_14e4:
	/* 0x14e4: add    rax,rsi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_14e7:
	/* 0x14e7: rol    rsi,0x10 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 16ULL);
x86_l_14eb:
	/* 0x14eb: xor    rsi,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RSI, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_14ee:
	/* 0x14ee: add    rdi,rsi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_14f1:
	/* 0x14f1: rol    rsi,0x15 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 21ULL);
x86_l_14f5:
	/* 0x14f5: add    rax,rdx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_14f8:
	/* 0x14f8: rol    rdx,0x11 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 17ULL);
x86_l_14fc:
	/* 0x14fc: xor    rdx,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_14ff:
	/* 0x14ff: rol    rax,0x20 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 32ULL);
x86_l_1503:
	/* 0x1503: xor    rsi,rdi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RSI, X86_RDI, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1506:
	/* 0x1506: add    rdi,rdx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1509:
	/* 0x1509: rol    rdx,0xd */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 13ULL);
x86_l_150d:
	/* 0x150d: xor    rdx,rdi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RDI, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1510:
	/* 0x1510: rol    rdi,0x20 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 32ULL);
x86_l_1514:
	/* 0x1514: add    rax,rsi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1517:
	/* 0x1517: rol    rsi,0x10 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 16ULL);
x86_l_151b:
	/* 0x151b: xor    rsi,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RSI, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_151e:
	/* 0x151e: add    rdi,rsi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1521:
	/* 0x1521: rol    rsi,0x15 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 21ULL);
x86_l_1525:
	/* 0x1525: add    rax,rdx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1528:
	/* 0x1528: rol    rdx,0x11 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 17ULL);
x86_l_152c:
	/* 0x152c: xor    rdx,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_152f:
	/* 0x152f: rol    rax,0x20 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 32ULL);
x86_l_1533:
	/* 0x1533: xor    rsi,rdi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RSI, X86_RDI, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1536:
	/* 0x1536: add    rdi,rdx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1539:
	/* 0x1539: rol    rdx,0xd */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 13ULL);
x86_l_153d:
	/* 0x153d: add    rax,rsi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1540:
	/* 0x1540: rol    rsi,0x10 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 16ULL);
x86_l_1544:
	/* 0x1544: xor    rsi,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RSI, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1547:
	/* 0x1547: rol    rsi,0x15 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 21ULL);
x86_l_154b:
	/* 0x154b: xor    rdx,rdi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RDI, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_154e:
	/* 0x154e: add    rax,rdx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1551:
	/* 0x1551: rol    rdx,0x11 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 17ULL);
x86_l_1555:
	/* 0x1555: mov    rdi,rax */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RDI, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_1558:
	/* 0x1558: rol    rdi,0x20 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ROL, 32ULL);
x86_l_155c:
	/* 0x155c: xor    rdi,rdx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_RDX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_155f:
	/* 0x155f: xor    rdi,rsi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1562:
	/* 0x1562: xor    rdi,rax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1565:
	/* 0x1565: mov    QWORD PTR [rcx],rdi */
	X86_VM_RUN_OP(x86_exec_mov_store_reg, X86_OP_MOV_STORE_REG, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1568:
	/* 0x1568: mov    eax,0x2 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_156d:
	/* 0x156d: pop    rbp */
	X86_VM_RUN_OP(x86_exec_pop, X86_OP_POP, X86_RBP, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_156e:
	/* 0x156e: ret */
	X86_VM_RET_RAX();

	return XDP_ABORTED;
}

X86_VM_LICENSE();
