#ifndef X86_INTERP_H
#define X86_INTERP_H

#define X86_OP_MOV_IMM64 0x01U
#define X86_OP_MOV_REG64 0x02U
#define X86_OP_ADD_IMM64 0x03U
#define X86_OP_ADD_REG64 0x04U
#define X86_OP_XOR_REG32 0x05U
#define X86_OP_RET 0xffU

#define X86_RAX 0U
#define X86_RCX 1U
#define X86_RDX 2U
#define X86_RBX 3U
#define X86_RSP 4U
#define X86_RBP 5U
#define X86_RSI 6U
#define X86_RDI 7U
#define X86_R8 8U
#define X86_R9 9U
#define X86_R10 10U
#define X86_R11 11U
#define X86_R12 12U
#define X86_R13 13U
#define X86_R14 14U
#define X86_R15 15U

#define X86_INTERP_CONTINUE 0
#define X86_INTERP_DONE 1
#define X86_INTERP_TRAP -1

struct x86_insn {
	__u8 op;
	__u8 dst;
	__u8 src;
	__u8 flags;
	__u32 aux;
	__u64 imm;
};

struct x86_state {
	__u64 rax;
	__u64 rcx;
	__u64 rdx;
	__u64 rbx;
	__u64 rsp;
	__u64 rbp;
	__u64 rsi;
	__u64 rdi;
	__u64 r8;
	__u64 r9;
	__u64 r10;
	__u64 r11;
	__u64 r12;
	__u64 r13;
	__u64 r14;
	__u64 r15;
};

static __always_inline int x86_read_reg(const struct x86_state *state,
					__u8 reg, __u64 *out)
{
	switch (reg) {
	case X86_RAX:
		*out = state->rax;
		return 0;
	case X86_RCX:
		*out = state->rcx;
		return 0;
	case X86_RDX:
		*out = state->rdx;
		return 0;
	case X86_RBX:
		*out = state->rbx;
		return 0;
	case X86_RSP:
		*out = state->rsp;
		return 0;
	case X86_RBP:
		*out = state->rbp;
		return 0;
	case X86_RSI:
		*out = state->rsi;
		return 0;
	case X86_RDI:
		*out = state->rdi;
		return 0;
	case X86_R8:
		*out = state->r8;
		return 0;
	case X86_R9:
		*out = state->r9;
		return 0;
	case X86_R10:
		*out = state->r10;
		return 0;
	case X86_R11:
		*out = state->r11;
		return 0;
	case X86_R12:
		*out = state->r12;
		return 0;
	case X86_R13:
		*out = state->r13;
		return 0;
	case X86_R14:
		*out = state->r14;
		return 0;
	case X86_R15:
		*out = state->r15;
		return 0;
	default:
		return X86_INTERP_TRAP;
	}
}

static __always_inline int x86_write_reg(struct x86_state *state,
					 __u8 reg, __u64 value)
{
	switch (reg) {
	case X86_RAX:
		state->rax = value;
		return 0;
	case X86_RCX:
		state->rcx = value;
		return 0;
	case X86_RDX:
		state->rdx = value;
		return 0;
	case X86_RBX:
		state->rbx = value;
		return 0;
	case X86_RSP:
		state->rsp = value;
		return 0;
	case X86_RBP:
		state->rbp = value;
		return 0;
	case X86_RSI:
		state->rsi = value;
		return 0;
	case X86_RDI:
		state->rdi = value;
		return 0;
	case X86_R8:
		state->r8 = value;
		return 0;
	case X86_R9:
		state->r9 = value;
		return 0;
	case X86_R10:
		state->r10 = value;
		return 0;
	case X86_R11:
		state->r11 = value;
		return 0;
	case X86_R12:
		state->r12 = value;
		return 0;
	case X86_R13:
		state->r13 = value;
		return 0;
	case X86_R14:
		state->r14 = value;
		return 0;
	case X86_R15:
		state->r15 = value;
		return 0;
	default:
		return X86_INTERP_TRAP;
	}
}

static __always_inline int x86_exec_one(struct x86_state *state,
					const struct x86_insn *insn)
{
	__u64 dst_value;
	__u64 src_value;

	if (insn->op == X86_OP_MOV_IMM64) {
		return x86_write_reg(state, insn->dst, insn->imm);
	}
	if (insn->op == X86_OP_MOV_REG64) {
		if (x86_read_reg(state, insn->src, &src_value) < 0)
			return X86_INTERP_TRAP;
		return x86_write_reg(state, insn->dst, src_value);
	}
	if (insn->op == X86_OP_ADD_IMM64) {
		if (x86_read_reg(state, insn->dst, &dst_value) < 0)
			return X86_INTERP_TRAP;
		return x86_write_reg(state, insn->dst, dst_value + insn->imm);
	}
	if (insn->op == X86_OP_ADD_REG64) {
		if (x86_read_reg(state, insn->dst, &dst_value) < 0)
			return X86_INTERP_TRAP;
		if (x86_read_reg(state, insn->src, &src_value) < 0)
			return X86_INTERP_TRAP;
		return x86_write_reg(state, insn->dst, dst_value + src_value);
	}
	if (insn->op == X86_OP_XOR_REG32) {
		if (x86_read_reg(state, insn->dst, &dst_value) < 0)
			return X86_INTERP_TRAP;
		if (x86_read_reg(state, insn->src, &src_value) < 0)
			return X86_INTERP_TRAP;
		return x86_write_reg(state, insn->dst,
				     (__u32)dst_value ^ (__u32)src_value);
	}
	if (insn->op == X86_OP_RET)
		return X86_INTERP_DONE;
	return X86_INTERP_TRAP;
}

#endif
