#include "../x86_vm_bpf.h"

struct packet_checksum_fold_loop_ctx {
	struct x86_state state;
	struct x86_insn insn;
	void *data;
	void *data_end;
	__u32 inner;
	__u32 failed;
};

#define PACKET_CHECKSUM_LOOP_STEP(OP, DST, SRC, FLAGS, AUX, IMM)        \
	do {                                                               \
		loop->insn.op = (OP);                                         \
		loop->insn.dst = (DST);                                       \
		loop->insn.src = (SRC);                                       \
		loop->insn.flags = (FLAGS);                                  \
		loop->insn.aux = (AUX);                                      \
		loop->insn.imm = (IMM);                                      \
		int __x86_loop_ret = x86_exec_one(&loop->state, &loop->insn, \
						       loop->data, loop->data_end);     \
		if (__x86_loop_ret != X86_INTERP_CONTINUE) {                 \
			loop->failed = 1;                                      \
			return 1;                                             \
		}                                                          \
	} while (0)

#define PACKET_CHECKSUM_LOAD_U16(REG, PTR_REG, TAG_REG, OFF_EXPR) \
	do {                                                           \
		__u32 __packet_off = (OFF_EXPR);                         \
		if (__packet_off > 1038) {                              \
			loop->failed = 1;                                  \
			return 1;                                         \
		}                                                      \
		__u8 *__packet_addr = (__u8 *)loop->data + __packet_off; \
		if (__packet_addr + X86_WIDTH_16 > (__u8 *)loop->data_end) { \
			loop->failed = 1;                                  \
			return 1;                                         \
		}                                                      \
		loop->state.REG = *(__u16 *)__packet_addr;             \
		loop->state.PTR_REG = 0;                               \
		loop->state.TAG_REG = X86_PTR_NONE;                    \
	} while (0)

static long packet_checksum_fold_inner_cb(__u32 index, void *ctx)
{
	struct packet_checksum_fold_loop_ctx *loop = ctx;

	if (loop->failed)
		return 1;
	if (loop->inner >= 256) {
		loop->failed = 1;
		return 1;
	}
	loop->state.rcx = 19 + ((__u64)loop->inner << 2);
	loop->state.p_rcx = 0;
	loop->state.tag_rcx = X86_PTR_NONE;
	/* 0x1150: movzx  r8d,WORD PTR [rdx+rcx*1-0x3] */
	PACKET_CHECKSUM_LOAD_U16(r8, p_r8, tag_r8, 16 + (loop->inner << 2));
	/* 0x1156: add    r8d,edi */
	PACKET_CHECKSUM_LOOP_STEP(X86_OP_ALU_REG, X86_R8, X86_RDI, X86_WIDTH_32, X86_ALU_ADD, 0);
	/* 0x1159: movzx  edi,r8w */
	PACKET_CHECKSUM_LOOP_STEP(X86_OP_MOVZX_REG, X86_RDI, X86_R8, X86_WIDTH_32, X86_WIDTH_16, 0);
	/* 0x115d: shr    r8d,0x10 */
	PACKET_CHECKSUM_LOOP_STEP(X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
	/* 0x1161: add    r8d,edi */
	PACKET_CHECKSUM_LOOP_STEP(X86_OP_ALU_REG, X86_R8, X86_RDI, X86_WIDTH_32, X86_ALU_ADD, 0);
	/* 0x1164: movzx  edi,WORD PTR [rdx+rcx*1-0x1] */
	PACKET_CHECKSUM_LOAD_U16(rdi, p_rdi, tag_rdi, 18 + (loop->inner << 2));
	/* 0x1169: add    edi,r8d */
	PACKET_CHECKSUM_LOOP_STEP(X86_OP_ALU_REG, X86_RDI, X86_R8, X86_WIDTH_32, X86_ALU_ADD, 0);
	/* 0x116c: movzx  r8d,di */
	PACKET_CHECKSUM_LOOP_STEP(X86_OP_MOVZX_REG, X86_R8, X86_RDI, X86_WIDTH_32, X86_WIDTH_16, 0);
	/* 0x1170: shr    edi,0x10 */
	PACKET_CHECKSUM_LOOP_STEP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
	/* 0x1173: add    edi,r8d */
	PACKET_CHECKSUM_LOOP_STEP(X86_OP_ALU_REG, X86_RDI, X86_R8, X86_WIDTH_32, X86_ALU_ADD, 0);
	/* 0x1176: add    rcx,0x4 */
	PACKET_CHECKSUM_LOOP_STEP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
	/* 0x117a: cmp    rcx,0x413 */
	PACKET_CHECKSUM_LOOP_STEP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, 0, 1043ULL);
	/* 0x1181: jne    1150 <packet_checksum_fold_xdp+0x50> */
	/* proof-loop branch handled by bpf_loop trip count */
	loop->inner++;
	return 0;
}

static long packet_checksum_fold_outer_cb(__u32 index, void *ctx)
{
	struct packet_checksum_fold_loop_ctx *loop = ctx;

	if (loop->failed)
		return 1;
	loop->inner = 0;
	/* 0x1140: mov    ecx,0x13 */
	PACKET_CHECKSUM_LOOP_STEP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 19ULL);
	/* 0x1145: xor    edi,edi */
	PACKET_CHECKSUM_LOOP_STEP(X86_OP_ALU_REG, X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR, 0);
	/* 0x1147: nop    WORD PTR [rax+rax*1+0x0] */
	PACKET_CHECKSUM_LOOP_STEP(X86_OP_NOP, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, 0);
	if (bpf_loop(256, packet_checksum_fold_inner_cb, loop, 0) < 0) {
		loop->failed = 1;
		return 1;
	}
	if (loop->failed)
		return 1;
	/* 0x1183: mov    ecx,edi */
	PACKET_CHECKSUM_LOOP_STEP(X86_OP_MOV_REG, X86_RCX, X86_RDI, X86_WIDTH_32, 0, 0);
	/* 0x1185: shr    ecx,0x10 */
	PACKET_CHECKSUM_LOOP_STEP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
	/* 0x1188: add    ecx,edi */
	PACKET_CHECKSUM_LOOP_STEP(X86_OP_ALU_REG, X86_RCX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD, 0);
	/* 0x118a: not    ecx */
	PACKET_CHECKSUM_LOOP_STEP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_NOT, 0);
	/* 0x118c: movzx  edi,cx */
	PACKET_CHECKSUM_LOOP_STEP(X86_OP_MOVZX_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_WIDTH_16, 0);
	/* 0x118f: mov    ecx,eax */
	PACKET_CHECKSUM_LOOP_STEP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
	/* 0x1191: shl    ecx,0x4 */
	PACKET_CHECKSUM_LOOP_STEP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 4ULL);
	/* 0x1194: shl    rdi,cl */
	PACKET_CHECKSUM_LOOP_STEP(X86_OP_ALU_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 0);
	/* 0x1197: xor    rsi,rdi */
	PACKET_CHECKSUM_LOOP_STEP(X86_OP_ALU_REG, X86_RSI, X86_RDI, X86_WIDTH_64, X86_ALU_XOR, 0);
	/* 0x119a: inc    eax */
	PACKET_CHECKSUM_LOOP_STEP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_INC, 1);
	/* 0x119c: cmp    eax,0x20 */
	PACKET_CHECKSUM_LOOP_STEP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 32ULL);
	/* 0x119f: jne    1140 <packet_checksum_fold_xdp+0x40> */
	/* proof-loop branch handled by outer bpf_loop trip count */
	return 0;
}

#undef PACKET_CHECKSUM_LOOP_STEP

SEC("xdp")
int packet_checksum_fold_x86_vm_xdp(struct xdp_md *ctx)
{
	void *__x86_vm_data = (void *)(long)ctx->data;
	void *__x86_vm_data_end = (void *)(long)ctx->data_end;
	struct packet_checksum_fold_loop_ctx __x86_loop = {};
	#define __x86_vm_state __x86_loop.state
	#define __x86_vm_insn __x86_loop.insn
	x86_init_state(&__x86_vm_state, (void *)ctx);
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
	/* 0x110c: jbe    110f <packet_checksum_fold_xdp+0xf> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_BE))
		goto x86_l_110f;
x86_l_110e:
	/* 0x110e: ret */
	X86_VM_RET_RAX();
x86_l_110f:
	/* 0x110f: lea    rsi,[rdx+0x8] */
	X86_VM_RUN_STEP(X86_OP_LEA, X86_RSI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1113:
	/* 0x1113: cmp    rsi,rcx */
	X86_VM_RUN_STEP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_1116:
	/* 0x1116: ja     110e <packet_checksum_fold_xdp+0xe> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_110e;
x86_l_1118:
	/* 0x1118: lea    rsi,[rdx+0x410] */
	X86_VM_RUN_STEP(X86_OP_LEA, X86_RSI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1040ULL);
x86_l_111f:
	/* 0x111f: cmp    rsi,rcx */
	X86_VM_RUN_STEP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_1122:
	/* 0x1122: ja     110e <packet_checksum_fold_xdp+0xe> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_110e;
x86_l_1124:
	/* 0x1124: cmp    DWORD PTR [rdx+0x8],0x20 */
	X86_VM_RUN_STEP(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738400ULL);
x86_l_1128:
	/* 0x1128: jne    110e <packet_checksum_fold_xdp+0xe> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_110e;
x86_l_112a:
	/* 0x112a: cmp    DWORD PTR [rdx+0xc],0x200 */
	X86_VM_RUN_STEP(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539608064ULL);
x86_l_1131:
	/* 0x1131: jne    110e <packet_checksum_fold_xdp+0xe> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_110e;
x86_l_1133:
	/* 0x1133: xor    eax,eax */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1135:
	/* 0x1135: xor    esi,esi */
	X86_VM_RUN_STEP(X86_OP_ALU_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1137:
	/* 0x1137: nop    WORD PTR [rax+rax*1+0x0] */
	X86_VM_RUN_STEP(X86_OP_NOP, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, 0);
	__x86_loop.data = __x86_vm_data;
	__x86_loop.data_end = __x86_vm_data_end;
	if (bpf_loop(32, packet_checksum_fold_outer_cb, &__x86_loop, 0) < 0)
		return XDP_ABORTED;
	if (__x86_loop.failed)
		return XDP_ABORTED;
	/* 0x11a1: mov    QWORD PTR [rdx],rsi */
	X86_VM_RUN_STEP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
	/* 0x11a4: mov    eax,0x2 */
	X86_VM_RUN_STEP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
	/* 0x11a9: ret */
	X86_VM_RET_RAX();
	#undef __x86_vm_insn
	#undef __x86_vm_state
	return XDP_ABORTED;
}

X86_VM_LICENSE();
