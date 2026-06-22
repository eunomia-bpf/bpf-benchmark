#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tracee_hash_task_id_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: mov    rdx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_64);
x86_l_3:
	/* 0x3: movabs rax,0xd6bf94d5e57a42bd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 15474250491067253437ULL);
x86_l_d:
	/* 0xd: mulx   rax,rax,rax */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_12:
	/* 0x12: shr    rax,0x17 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 23ULL);
x86_l_16:
	/* 0x16: imul   rax,rax,0x989680 */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RAX, X86_WIDTH_64, 10000000ULL);
x86_l_1d:
	/* 0x1d: bswap  edi */
	X86_SIM_RUN_OP(X86_OP_BSWAP, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 0);
x86_l_1f:
	/* 0x1f: bswap  rax */
	X86_SIM_RUN_OP(X86_OP_BSWAP, X86_RAX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_22:
	/* 0x22: imul   ecx,edi,0xcc9e2d51 */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RCX, X86_RDI, X86_WIDTH_32, 3432918353ULL);
x86_l_28:
	/* 0x28: imul   edx,edi,0x16a88000 */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RDX, X86_RDI, X86_WIDTH_32, 380141568ULL);
x86_l_2e:
	/* 0x2e: shr    ecx,0x11 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 17ULL);
x86_l_31:
	/* 0x31: or     ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_OR);
x86_l_33:
	/* 0x33: imul   ecx,ecx,0x1b873593 */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RCX, X86_RCX, X86_WIDTH_32, 461845907ULL);
x86_l_39:
	/* 0x39: xor    ecx,0x18273645 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 405222981ULL);
x86_l_3f:
	/* 0x3f: rorx   ecx,ecx,0x13 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RCX, X86_RCX, X86_WIDTH_32, 0, 19ULL);
x86_l_45:
	/* 0x45: lea    ecx,[rcx+rcx*4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 0ULL);
x86_l_48:
	/* 0x48: add    ecx,0xe6546b64 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 3864292196ULL);
x86_l_4e:
	/* 0x4e: imul   edx,eax,0xcc9e2d51 */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RDX, X86_RAX, X86_WIDTH_32, 3432918353ULL);
x86_l_54:
	/* 0x54: imul   esi,eax,0x16a88000 */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RSI, X86_RAX, X86_WIDTH_32, 380141568ULL);
x86_l_5a:
	/* 0x5a: shr    edx,0x11 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHR, 17ULL);
x86_l_5d:
	/* 0x5d: or     edx,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_32, X86_ALU_OR);
x86_l_5f:
	/* 0x5f: imul   edx,edx,0x1b873593 */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RDX, X86_RDX, X86_WIDTH_32, 461845907ULL);
x86_l_65:
	/* 0x65: xor    edx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_67:
	/* 0x67: rorx   ecx,edx,0x13 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RCX, X86_RDX, X86_WIDTH_32, 0, 19ULL);
x86_l_6d:
	/* 0x6d: lea    ecx,[rcx+rcx*4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 0ULL);
x86_l_70:
	/* 0x70: add    ecx,0xe6546b64 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 3864292196ULL);
x86_l_76:
	/* 0x76: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_7a:
	/* 0x7a: imul   edx,eax,0xcc9e2d51 */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RDX, X86_RAX, X86_WIDTH_32, 3432918353ULL);
x86_l_80:
	/* 0x80: imul   eax,eax,0x16a88000 */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RAX, X86_WIDTH_32, 380141568ULL);
x86_l_86:
	/* 0x86: shr    edx,0x11 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHR, 17ULL);
x86_l_89:
	/* 0x89: or     edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_OR);
x86_l_8b:
	/* 0x8b: imul   eax,edx,0x1b873593 */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RDX, X86_WIDTH_32, 461845907ULL);
x86_l_91:
	/* 0x91: xor    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_93:
	/* 0x93: rorx   eax,eax,0x13 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 19ULL);
x86_l_99:
	/* 0x99: lea    eax,[rax+rax*4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 0ULL);
x86_l_9c:
	/* 0x9c: add    eax,0xe6546b64 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 3864292196ULL);
x86_l_a1:
	/* 0xa1: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_a3:
	/* 0xa3: shr    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_a6:
	/* 0xa6: xor    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a8:
	/* 0xa8: xor    ecx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 12ULL);
x86_l_ab:
	/* 0xab: imul   eax,ecx,0x85ebca6b */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RCX, X86_WIDTH_32, 2246822507ULL);
x86_l_b1:
	/* 0xb1: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_b3:
	/* 0xb3: shr    ecx,0xd */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 13ULL);
x86_l_b6:
	/* 0xb6: xor    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b8:
	/* 0xb8: imul   ecx,ecx,0xc2b2ae35 */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RCX, X86_RCX, X86_WIDTH_32, 3266489909ULL);
x86_l_be:
	/* 0xbe: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_c0:
	/* 0xc0: shr    eax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_c3:
	/* 0xc3: xor    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c5:
	/* 0xc5: jmp    ca <hash_task_id+0xca> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_ca:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
