#ifndef X86_INTERP_H
#define X86_INTERP_H

#define X86_OP_NOP 0x00U
#define X86_OP_MOV_IMM 0x01U
#define X86_OP_MOV_REG 0x02U
#define X86_OP_ADD_IMM 0x03U
#define X86_OP_ADD_REG 0x04U
#define X86_OP_XOR_REG 0x05U
#define X86_OP_MOV_LOAD 0x06U
#define X86_OP_MOV_STORE_IMM 0x07U
#define X86_OP_MOV_STORE_REG 0x08U
#define X86_OP_LEA 0x09U
#define X86_OP_ALU_IMM 0x0aU
#define X86_OP_ALU_REG 0x0bU
#define X86_OP_CMP_IMM 0x0cU
#define X86_OP_CMP_REG 0x0dU
#define X86_OP_TEST_IMM 0x0eU
#define X86_OP_TEST_REG 0x0fU
#define X86_OP_JCC 0x10U
#define X86_OP_JMP 0x11U
#define X86_OP_PUSH 0x12U
#define X86_OP_POP 0x13U
#define X86_OP_CALL 0x14U
#define X86_OP_CMOV 0x15U
#define X86_OP_SETCC 0x16U
#define X86_OP_BSWAP 0x17U
#define X86_OP_POPCNT 0x18U
#define X86_OP_XCHG 0x19U
#define X86_OP_DIV 0x1aU
#define X86_OP_SHLD_IMM 0x1bU
#define X86_OP_SHRD_IMM 0x1cU
#define X86_OP_CMP_MEM_IMM 0x1dU
#define X86_OP_TEST_MEM_IMM 0x1eU
#define X86_OP_CMP_MEM_REG 0x1fU
#define X86_OP_MOVZX_REG 0x20U
#define X86_OP_MOVSX_REG 0x21U
#define X86_OP_MOVSX_LOAD 0x22U
#define X86_OP_ALU_MEM 0x23U
#define X86_OP_RET 0xffU

#define X86_OP_MOV_IMM64 X86_OP_MOV_IMM
#define X86_OP_MOV_REG64 X86_OP_MOV_REG
#define X86_OP_ADD_IMM64 X86_OP_ADD_IMM
#define X86_OP_ADD_REG64 X86_OP_ADD_REG
#define X86_OP_XOR_REG32 X86_OP_XOR_REG

#define X86_ALU_ADD 0U
#define X86_ALU_SUB 1U
#define X86_ALU_XOR 2U
#define X86_ALU_OR 3U
#define X86_ALU_AND 4U
#define X86_ALU_SHL 5U
#define X86_ALU_SHR 6U
#define X86_ALU_SAR 7U
#define X86_ALU_ROL 8U
#define X86_ALU_IMUL 9U
#define X86_ALU_INC 10U
#define X86_ALU_NOT 11U
#define X86_ALU_SBB 12U

#define X86_CC_O 0U
#define X86_CC_NO 1U
#define X86_CC_B 2U
#define X86_CC_AE 3U
#define X86_CC_E 4U
#define X86_CC_NE 5U
#define X86_CC_BE 6U
#define X86_CC_A 7U
#define X86_CC_S 8U
#define X86_CC_NS 9U
#define X86_CC_L 12U
#define X86_CC_GE 13U
#define X86_CC_LE 14U
#define X86_CC_G 15U

#define X86_WIDTH_8 1U
#define X86_WIDTH_16 2U
#define X86_WIDTH_32 4U
#define X86_WIDTH_64 8U

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
#define X86_REG_NONE 0xffU

#define X86_INTERP_CONTINUE 0
#define X86_INTERP_DONE 1
#define X86_INTERP_TRAP -1

#define X86_PTR_NONE 0U
#define X86_PTR_CTX 1U
#define X86_PTR_PACKET 2U
#define X86_PTR_PACKET_END 3U
#define X86_PTR_RODATA 4U
#define X86_PTR_STACK 5U

#define X86_MEM_AUX(INDEX, SCALE_LOG2) \
	(((__u32)(INDEX) & 0xffU) | (((__u32)(SCALE_LOG2) & 0xffU) << 8))
#define X86_MEM_AUX_FULL(INDEX, SCALE_LOG2, MEM_WIDTH)                    \
	(X86_MEM_AUX((INDEX), (SCALE_LOG2)) |                             \
	 (((__u32)(MEM_WIDTH) & 0xffU) << 16))
#define X86_REG_AUX_SRC_SHIFT(SHIFT) (((__u32)(SHIFT) & 0xffU) << 24)
#define X86_MEM_AUX_ALU_OP(ALU) (((__u32)(ALU) & 0xffU) << 24)
#define X86_MEM_AUX_INDEX(AUX) ((__u8)((AUX) & 0xffU))
#define X86_MEM_AUX_SCALE_LOG2(AUX) ((__u8)(((AUX) >> 8) & 0xffU))
#define X86_MEM_AUX_MEM_WIDTH(AUX) ((__u8)(((AUX) >> 16) & 0xffU))
#define X86_REG_AUX_GET_SRC_SHIFT(AUX) ((__u8)(((AUX) >> 24) & 0xffU))
#define X86_MEM_AUX_GET_ALU_OP(AUX) ((__u8)(((AUX) >> 24) & 0xffU))

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
	void *p_rax;
	void *p_rcx;
	void *p_rdx;
	void *p_rbx;
	void *p_rsp;
	void *p_rbp;
	void *p_rsi;
	void *p_rdi;
	void *p_r8;
	void *p_r9;
	void *p_r10;
	void *p_r11;
	void *p_r12;
	void *p_r13;
	void *p_r14;
	void *p_r15;
	__u8 tag_rax;
	__u8 tag_rcx;
	__u8 tag_rdx;
	__u8 tag_rbx;
	__u8 tag_rsp;
	__u8 tag_rbp;
	__u8 tag_rsi;
	__u8 tag_rdi;
	__u8 tag_r8;
	__u8 tag_r9;
	__u8 tag_r10;
	__u8 tag_r11;
	__u8 tag_r12;
	__u8 tag_r13;
	__u8 tag_r14;
	__u8 tag_r15;
	__u8 cf;
	__u8 zf;
	__u8 sf;
	__u8 of;
#ifdef X86_VM_ENABLE_STACK
	__u64 stack0;
	__u64 stack1;
	__u64 stack2;
	__u64 stack3;
	__u64 stack4;
	__u64 stack5;
	__u64 stack6;
	__u64 stack7;
	__u64 stack8;
	__u64 stack9;
	__u64 stack10;
	__u64 stack11;
	void *p_stack0;
	void *p_stack1;
	void *p_stack2;
	void *p_stack3;
	void *p_stack4;
	void *p_stack5;
	void *p_stack6;
	void *p_stack7;
	void *p_stack8;
	void *p_stack9;
	void *p_stack10;
	void *p_stack11;
	__u8 tag_stack0;
	__u8 tag_stack1;
	__u8 tag_stack2;
	__u8 tag_stack3;
	__u8 tag_stack4;
	__u8 tag_stack5;
	__u8 tag_stack6;
	__u8 tag_stack7;
	__u8 tag_stack8;
	__u8 tag_stack9;
	__u8 tag_stack10;
	__u8 tag_stack11;
#endif
};

static __always_inline void x86_init_state(struct x86_state *state, void *ctx)
{
	state->p_rdi = ctx;
	state->tag_rdi = X86_PTR_CTX;
#ifdef X86_VM_ENABLE_STACK
	state->tag_rsp = X86_PTR_STACK;
#endif
}

static __always_inline __u64 x86_width_mask(__u8 width)
{
	if (width == X86_WIDTH_8)
		return 0xffULL;
	if (width == X86_WIDTH_16)
		return 0xffffULL;
	if (width == X86_WIDTH_32)
		return 0xffffffffULL;
	return 0xffffffffffffffffULL;
}

static __always_inline __u32 x86_width_bits(__u8 width)
{
	if (width == X86_WIDTH_8)
		return 8;
	if (width == X86_WIDTH_16)
		return 16;
	if (width == X86_WIDTH_32)
		return 32;
	return 64;
}

static __always_inline __u64 x86_apply_width(__u64 value, __u8 width)
{
	return value & x86_width_mask(width);
}

static __always_inline __u64 x86_sign_extend(__u64 value, __u8 width)
{
	__u64 narrowed = x86_apply_width(value, width);

	if (width == X86_WIDTH_8)
		return (__u64)(__s64)(__s8)narrowed;
	if (width == X86_WIDTH_16)
		return (__u64)(__s64)(__s16)narrowed;
	if (width == X86_WIDTH_32)
		return (__u64)(__s64)(__s32)narrowed;
	return narrowed;
}

static __always_inline void x86_clear_ptr_reg(struct x86_state *state,
					      __u8 reg)
{
	switch (reg) {
	case X86_RAX:
		state->p_rax = 0;
		state->tag_rax = X86_PTR_NONE;
		return;
	case X86_RCX:
		state->p_rcx = 0;
		state->tag_rcx = X86_PTR_NONE;
		return;
	case X86_RDX:
		state->p_rdx = 0;
		state->tag_rdx = X86_PTR_NONE;
		return;
	case X86_RBX:
		state->p_rbx = 0;
		state->tag_rbx = X86_PTR_NONE;
		return;
	case X86_RSP:
		state->p_rsp = 0;
		state->tag_rsp = X86_PTR_NONE;
		return;
	case X86_RBP:
		state->p_rbp = 0;
		state->tag_rbp = X86_PTR_NONE;
		return;
	case X86_RSI:
		state->p_rsi = 0;
		state->tag_rsi = X86_PTR_NONE;
		return;
	case X86_RDI:
		state->p_rdi = 0;
		state->tag_rdi = X86_PTR_NONE;
		return;
	case X86_R8:
		state->p_r8 = 0;
		state->tag_r8 = X86_PTR_NONE;
		return;
	case X86_R9:
		state->p_r9 = 0;
		state->tag_r9 = X86_PTR_NONE;
		return;
	case X86_R10:
		state->p_r10 = 0;
		state->tag_r10 = X86_PTR_NONE;
		return;
	case X86_R11:
		state->p_r11 = 0;
		state->tag_r11 = X86_PTR_NONE;
		return;
	case X86_R12:
		state->p_r12 = 0;
		state->tag_r12 = X86_PTR_NONE;
		return;
	case X86_R13:
		state->p_r13 = 0;
		state->tag_r13 = X86_PTR_NONE;
		return;
	case X86_R14:
		state->p_r14 = 0;
		state->tag_r14 = X86_PTR_NONE;
		return;
	case X86_R15:
		state->p_r15 = 0;
		state->tag_r15 = X86_PTR_NONE;
		return;
	default:
		return;
	}
}

static __always_inline int x86_read_ptr_reg(const struct x86_state *state,
					    __u8 reg, void **ptr, __u8 *tag)
{
	switch (reg) {
	case X86_RAX:
		*ptr = state->p_rax;
		*tag = state->tag_rax;
		return 0;
	case X86_RCX:
		*ptr = state->p_rcx;
		*tag = state->tag_rcx;
		return 0;
	case X86_RDX:
		*ptr = state->p_rdx;
		*tag = state->tag_rdx;
		return 0;
	case X86_RBX:
		*ptr = state->p_rbx;
		*tag = state->tag_rbx;
		return 0;
	case X86_RSP:
		*ptr = state->p_rsp;
		*tag = state->tag_rsp;
		return 0;
	case X86_RBP:
		*ptr = state->p_rbp;
		*tag = state->tag_rbp;
		return 0;
	case X86_RSI:
		*ptr = state->p_rsi;
		*tag = state->tag_rsi;
		return 0;
	case X86_RDI:
		*ptr = state->p_rdi;
		*tag = state->tag_rdi;
		return 0;
	case X86_R8:
		*ptr = state->p_r8;
		*tag = state->tag_r8;
		return 0;
	case X86_R9:
		*ptr = state->p_r9;
		*tag = state->tag_r9;
		return 0;
	case X86_R10:
		*ptr = state->p_r10;
		*tag = state->tag_r10;
		return 0;
	case X86_R11:
		*ptr = state->p_r11;
		*tag = state->tag_r11;
		return 0;
	case X86_R12:
		*ptr = state->p_r12;
		*tag = state->tag_r12;
		return 0;
	case X86_R13:
		*ptr = state->p_r13;
		*tag = state->tag_r13;
		return 0;
	case X86_R14:
		*ptr = state->p_r14;
		*tag = state->tag_r14;
		return 0;
	case X86_R15:
		*ptr = state->p_r15;
		*tag = state->tag_r15;
		return 0;
	default:
		return X86_INTERP_TRAP;
	}
}

static __always_inline int x86_write_ptr_reg(struct x86_state *state,
					     __u8 reg, void *ptr, __u8 tag)
{
	switch (reg) {
	case X86_RAX:
		state->p_rax = ptr;
		state->tag_rax = tag;
		return 0;
	case X86_RCX:
		state->p_rcx = ptr;
		state->tag_rcx = tag;
		return 0;
	case X86_RDX:
		state->p_rdx = ptr;
		state->tag_rdx = tag;
		return 0;
	case X86_RBX:
		state->p_rbx = ptr;
		state->tag_rbx = tag;
		return 0;
	case X86_RSP:
		state->p_rsp = ptr;
		state->tag_rsp = tag;
		return 0;
	case X86_RBP:
		state->p_rbp = ptr;
		state->tag_rbp = tag;
		return 0;
	case X86_RSI:
		state->p_rsi = ptr;
		state->tag_rsi = tag;
		return 0;
	case X86_RDI:
		state->p_rdi = ptr;
		state->tag_rdi = tag;
		return 0;
	case X86_R8:
		state->p_r8 = ptr;
		state->tag_r8 = tag;
		return 0;
	case X86_R9:
		state->p_r9 = ptr;
		state->tag_r9 = tag;
		return 0;
	case X86_R10:
		state->p_r10 = ptr;
		state->tag_r10 = tag;
		return 0;
	case X86_R11:
		state->p_r11 = ptr;
		state->tag_r11 = tag;
		return 0;
	case X86_R12:
		state->p_r12 = ptr;
		state->tag_r12 = tag;
		return 0;
	case X86_R13:
		state->p_r13 = ptr;
		state->tag_r13 = tag;
		return 0;
	case X86_R14:
		state->p_r14 = ptr;
		state->tag_r14 = tag;
		return 0;
	case X86_R15:
		state->p_r15 = ptr;
		state->tag_r15 = tag;
		return 0;
	default:
		return X86_INTERP_TRAP;
	}
}

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

static __always_inline int x86_write_reg_width(struct x86_state *state,
					       __u8 reg, __u64 value,
					       __u8 width)
{
	__u64 old_value = 0;
	__u64 next_value = value;

	x86_clear_ptr_reg(state, reg);
	if (width == X86_WIDTH_8 || width == X86_WIDTH_16) {
		if (x86_read_reg(state, reg, &old_value) < 0)
			return X86_INTERP_TRAP;
		next_value = (old_value & ~x86_width_mask(width)) |
			     (value & x86_width_mask(width));
	} else if (width == X86_WIDTH_32) {
		next_value = (__u32)value;
	}

	switch (reg) {
	case X86_RAX:
		state->rax = next_value;
		return 0;
	case X86_RCX:
		state->rcx = next_value;
		return 0;
	case X86_RDX:
		state->rdx = next_value;
		return 0;
	case X86_RBX:
		state->rbx = next_value;
		return 0;
	case X86_RSP:
		state->rsp = next_value;
		return 0;
	case X86_RBP:
		state->rbp = next_value;
		return 0;
	case X86_RSI:
		state->rsi = next_value;
		return 0;
	case X86_RDI:
		state->rdi = next_value;
		return 0;
	case X86_R8:
		state->r8 = next_value;
		return 0;
	case X86_R9:
		state->r9 = next_value;
		return 0;
	case X86_R10:
		state->r10 = next_value;
		return 0;
	case X86_R11:
		state->r11 = next_value;
		return 0;
	case X86_R12:
		state->r12 = next_value;
		return 0;
	case X86_R13:
		state->r13 = next_value;
		return 0;
	case X86_R14:
		state->r14 = next_value;
		return 0;
	case X86_R15:
		state->r15 = next_value;
		return 0;
	default:
		return X86_INTERP_TRAP;
	}
}

static __always_inline int x86_write_reg(struct x86_state *state,
					 __u8 reg, __u64 value)
{
	return x86_write_reg_width(state, reg, value, X86_WIDTH_64);
}

#ifdef X86_VM_ENABLE_STACK
static __always_inline int x86_stack_write_raw(struct x86_state *state,
					       __s64 off, __u64 value,
					       void *ptr, __u8 tag)
{
	if (off == -8) {
		state->stack0 = value;
		state->p_stack0 = ptr;
		state->tag_stack0 = tag;
		return 0;
	}
	if (off == -16) {
		state->stack1 = value;
		state->p_stack1 = ptr;
		state->tag_stack1 = tag;
		return 0;
	}
	if (off == -24) {
		state->stack2 = value;
		state->p_stack2 = ptr;
		state->tag_stack2 = tag;
		return 0;
	}
	if (off == -32) {
		state->stack3 = value;
		state->p_stack3 = ptr;
		state->tag_stack3 = tag;
		return 0;
	}
	if (off == -40) {
		state->stack4 = value;
		state->p_stack4 = ptr;
		state->tag_stack4 = tag;
		return 0;
	}
	if (off == -48) {
		state->stack5 = value;
		state->p_stack5 = ptr;
		state->tag_stack5 = tag;
		return 0;
	}
	if (off == -56) {
		state->stack6 = value;
		state->p_stack6 = ptr;
		state->tag_stack6 = tag;
		return 0;
	}
	if (off == -64) {
		state->stack7 = value;
		state->p_stack7 = ptr;
		state->tag_stack7 = tag;
		return 0;
	}
	if (off == -72) {
		state->stack8 = value;
		state->p_stack8 = ptr;
		state->tag_stack8 = tag;
		return 0;
	}
	if (off == -80) {
		state->stack9 = value;
		state->p_stack9 = ptr;
		state->tag_stack9 = tag;
		return 0;
	}
	if (off == -88) {
		state->stack10 = value;
		state->p_stack10 = ptr;
		state->tag_stack10 = tag;
		return 0;
	}
	if (off == -96) {
		state->stack11 = value;
		state->p_stack11 = ptr;
		state->tag_stack11 = tag;
		return 0;
	}
	return X86_INTERP_TRAP;
}

static __always_inline int x86_stack_read_raw(struct x86_state *state,
					      __s64 off, __u64 *value,
					      void **ptr, __u8 *tag)
{
	if (off == -8) {
		*value = state->stack0;
		*ptr = state->p_stack0;
		*tag = state->tag_stack0;
		return 0;
	}
	if (off == -16) {
		*value = state->stack1;
		*ptr = state->p_stack1;
		*tag = state->tag_stack1;
		return 0;
	}
	if (off == -24) {
		*value = state->stack2;
		*ptr = state->p_stack2;
		*tag = state->tag_stack2;
		return 0;
	}
	if (off == -32) {
		*value = state->stack3;
		*ptr = state->p_stack3;
		*tag = state->tag_stack3;
		return 0;
	}
	if (off == -40) {
		*value = state->stack4;
		*ptr = state->p_stack4;
		*tag = state->tag_stack4;
		return 0;
	}
	if (off == -48) {
		*value = state->stack5;
		*ptr = state->p_stack5;
		*tag = state->tag_stack5;
		return 0;
	}
	if (off == -56) {
		*value = state->stack6;
		*ptr = state->p_stack6;
		*tag = state->tag_stack6;
		return 0;
	}
	if (off == -64) {
		*value = state->stack7;
		*ptr = state->p_stack7;
		*tag = state->tag_stack7;
		return 0;
	}
	if (off == -72) {
		*value = state->stack8;
		*ptr = state->p_stack8;
		*tag = state->tag_stack8;
		return 0;
	}
	if (off == -80) {
		*value = state->stack9;
		*ptr = state->p_stack9;
		*tag = state->tag_stack9;
		return 0;
	}
	if (off == -88) {
		*value = state->stack10;
		*ptr = state->p_stack10;
		*tag = state->tag_stack10;
		return 0;
	}
	if (off == -96) {
		*value = state->stack11;
		*ptr = state->p_stack11;
		*tag = state->tag_stack11;
		return 0;
	}
	return X86_INTERP_TRAP;
}

static __always_inline int x86_push_reg(struct x86_state *state, __u8 reg)
{
	__u64 value = 0;
	void *ptr = 0;
	__u8 tag = X86_PTR_NONE;

	if (x86_read_reg(state, reg, &value) < 0)
		return X86_INTERP_TRAP;
	x86_read_ptr_reg(state, reg, &ptr, &tag);
	state->rsp -= 8;
	return x86_stack_write_raw(state, (__s64)state->rsp, value, ptr, tag);
}

static __always_inline int x86_pop_reg(struct x86_state *state, __u8 reg,
				       __u8 width)
{
	__u64 value = 0;
	void *ptr = 0;
	__u8 tag = X86_PTR_NONE;

	if (x86_stack_read_raw(state, (__s64)state->rsp, &value, &ptr, &tag) < 0)
		return X86_INTERP_TRAP;
	if (x86_write_reg_width(state, reg, value, width) < 0)
		return X86_INTERP_TRAP;
	if (width == X86_WIDTH_64 && tag != X86_PTR_NONE &&
	    x86_write_ptr_reg(state, reg, ptr, tag) < 0)
		return X86_INTERP_TRAP;
	state->rsp += 8;
	return X86_INTERP_CONTINUE;
}

static __always_inline int x86_load_stack(struct x86_state *state, __u8 dst,
					  __s64 off, __u8 width)
{
	__u64 value = 0;
	void *ptr = 0;
	__u8 tag = X86_PTR_NONE;

	if (width != X86_WIDTH_64)
		return X86_INTERP_TRAP;
	if (x86_stack_read_raw(state, off, &value, &ptr, &tag) < 0)
		return X86_INTERP_TRAP;
	if (x86_write_reg_width(state, dst, value, width) < 0)
		return X86_INTERP_TRAP;
	if (tag != X86_PTR_NONE)
		return x86_write_ptr_reg(state, dst, ptr, tag);
	return X86_INTERP_CONTINUE;
}

static __always_inline int x86_store_stack_reg(struct x86_state *state,
					       __u8 src, __s64 off,
					       __u8 width)
{
	__u64 value = 0;
	void *ptr = 0;
	__u8 tag = X86_PTR_NONE;

	if (width != X86_WIDTH_64)
		return X86_INTERP_TRAP;
	if (x86_read_reg(state, src, &value) < 0)
		return X86_INTERP_TRAP;
	x86_read_ptr_reg(state, src, &ptr, &tag);
	return x86_stack_write_raw(state, off, value, ptr, tag);
}
#endif

static __always_inline void x86_set_logic_flags(struct x86_state *state,
						__u64 result, __u8 width)
{
	__u64 value = x86_apply_width(result, width);
	__u32 bits = x86_width_bits(width);

	state->cf = 0;
	state->of = 0;
	state->zf = value == 0;
	state->sf = (value >> (bits - 1)) & 1;
}

static __always_inline void x86_set_sub_flags(struct x86_state *state,
					      __u64 lhs, __u64 rhs,
					      __u64 result, __u8 width)
{
	__u64 mask = x86_width_mask(width);
	__u64 a = lhs & mask;
	__u64 b = rhs & mask;
	__u64 r = result & mask;
	__u32 bits = x86_width_bits(width);
	__u64 sign = 1ULL << (bits - 1);

	state->cf = a < b;
	state->zf = r == 0;
	state->sf = (r & sign) != 0;
	state->of = ((a ^ b) & (a ^ r) & sign) != 0;
}

static __always_inline __u64 x86_rol(__u64 value, __u64 shift, __u8 width)
{
	__u32 bits = x86_width_bits(width);
	__u64 mask = x86_width_mask(width);
	__u64 amount = shift & (bits - 1);
	__u64 narrowed = value & mask;

	if (amount == 0)
		return narrowed;
	return ((narrowed << amount) | (narrowed >> (bits - amount))) & mask;
}

static __always_inline __u64 x86_bswap(__u64 value, __u8 width)
{
	__u64 swapped = ((value & 0x00000000000000ffULL) << 56) |
			((value & 0x000000000000ff00ULL) << 40) |
			((value & 0x0000000000ff0000ULL) << 24) |
			((value & 0x00000000ff000000ULL) << 8) |
			((value & 0x000000ff00000000ULL) >> 8) |
			((value & 0x0000ff0000000000ULL) >> 24) |
			((value & 0x00ff000000000000ULL) >> 40) |
			((value & 0xff00000000000000ULL) >> 56);

	if (width == X86_WIDTH_32)
		return swapped >> 32;
	return swapped;
}

static __always_inline __u64 x86_popcount64(__u64 value)
{
	value = value - ((value >> 1) & 0x5555555555555555ULL);
	value = (value & 0x3333333333333333ULL) +
		((value >> 2) & 0x3333333333333333ULL);
	value = (value + (value >> 4)) & 0x0f0f0f0f0f0f0f0fULL;
	return (value * 0x0101010101010101ULL) >> 56;
}

static __always_inline __u64 x86_alu_result(__u64 lhs, __u64 rhs,
					    __u32 alu, __u8 width)
{
	__u32 bits = x86_width_bits(width);
	__u64 amount = rhs & (bits - 1);

	if (alu == X86_ALU_ADD)
		return lhs + rhs;
	if (alu == X86_ALU_SUB || alu == X86_ALU_SBB)
		return lhs - rhs;
	if (alu == X86_ALU_XOR)
		return lhs ^ rhs;
	if (alu == X86_ALU_OR)
		return lhs | rhs;
	if (alu == X86_ALU_AND)
		return lhs & rhs;
	if (alu == X86_ALU_SHL)
		return lhs << amount;
	if (alu == X86_ALU_SHR)
		return lhs >> amount;
	if (alu == X86_ALU_SAR) {
		if (width == X86_WIDTH_32)
			return (__u32)((__s32)lhs >> amount);
		return (__u64)((__s64)lhs >> amount);
	}
	if (alu == X86_ALU_ROL)
		return x86_rol(lhs, rhs, width);
	if (alu == X86_ALU_IMUL)
		return lhs * rhs;
	if (alu == X86_ALU_INC)
		return lhs + 1;
	if (alu == X86_ALU_NOT)
		return ~lhs;
	return lhs;
}

static __always_inline int x86_eval_cc(const struct x86_state *state,
				       __u32 cc)
{
	if (cc == X86_CC_B)
		return state->cf;
	if (cc == X86_CC_AE)
		return !state->cf;
	if (cc == X86_CC_E)
		return state->zf;
	if (cc == X86_CC_NE)
		return !state->zf;
	if (cc == X86_CC_BE)
		return state->cf || state->zf;
	if (cc == X86_CC_A)
		return !state->cf && !state->zf;
	if (cc == X86_CC_S)
		return state->sf;
	if (cc == X86_CC_NS)
		return !state->sf;
	if (cc == X86_CC_L)
		return state->sf != state->of;
	if (cc == X86_CC_GE)
		return state->sf == state->of;
	if (cc == X86_CC_LE)
		return state->zf || state->sf != state->of;
	if (cc == X86_CC_G)
		return !state->zf && state->sf == state->of;
	if (cc == X86_CC_O)
		return state->of;
	if (cc == X86_CC_NO)
		return !state->of;
	return 0;
}

static __always_inline __s64 x86_simm(__u64 value)
{
	return (__s64)value;
}

static __always_inline __u32 x86_store_imm_value(__u64 value)
{
	return (__u32)value;
}

static __always_inline __s32 x86_store_imm_disp(__u64 value)
{
	return (__s32)(value >> 32);
}

static __always_inline int x86_mem_offset(struct x86_state *state,
					  __u32 aux, __s64 disp,
					  __s64 *out)
{
	__u8 index = X86_MEM_AUX_INDEX(aux);
	__u8 scale_log2 = X86_MEM_AUX_SCALE_LOG2(aux);
	__u64 index_value = 0;

	*out = disp;
	if (index == X86_REG_NONE)
		return 0;
	if (scale_log2 > 3)
		return X86_INTERP_TRAP;
	if (x86_read_reg(state, index, &index_value) < 0)
		return X86_INTERP_TRAP;
	*out += (__s64)(index_value << scale_log2);
	return 0;
}

static __always_inline int x86_packet_bounds(void *data, void *data_end,
					     void *ptr, __s64 disp,
					     __u8 width, __u8 **out)
{
	__u8 *p = ptr;
	__u8 *start = data;
	__u8 *end = data_end;
	__u8 *addr = p + disp;
	__u8 size = width;

	if (size != X86_WIDTH_8 && size != X86_WIDTH_16 &&
	    size != X86_WIDTH_32 && size != X86_WIDTH_64)
		return X86_INTERP_TRAP;
	if (addr < start || addr + size > end)
		return X86_INTERP_TRAP;
	*out = addr;
	return 0;
}

static __always_inline int x86_load_packet(struct x86_state *state,
					   __u8 dst, void *data,
					   void *data_end, void *base,
					   __s64 disp, __u8 load_width,
					   __u8 write_width, __u8 sign_extend)
{
	__u8 *addr;
	__u64 value = 0;

	if (x86_packet_bounds(data, data_end, base, disp, load_width, &addr) < 0)
		return X86_INTERP_TRAP;
	if (load_width == X86_WIDTH_8)
		value = *(__u8 *)addr;
	else if (load_width == X86_WIDTH_16)
		value = *(__u16 *)addr;
	else if (load_width == X86_WIDTH_32)
		value = *(__u32 *)addr;
	else
		value = *(__u64 *)addr;
	if (sign_extend)
		value = x86_sign_extend(value, load_width);
	return x86_write_reg_width(state, dst, value, write_width);
}

static __always_inline int x86_read_packet_value(void *data, void *data_end,
						 void *base, __s64 disp,
						 __u8 width, __u64 *value)
{
	__u8 *addr;

	if (x86_packet_bounds(data, data_end, base, disp, width, &addr) < 0)
		return X86_INTERP_TRAP;
	if (width == X86_WIDTH_8)
		*value = *(__u8 *)addr;
	else if (width == X86_WIDTH_16)
		*value = *(__u16 *)addr;
	else if (width == X86_WIDTH_32)
		*value = *(__u32 *)addr;
	else
		*value = *(__u64 *)addr;
	return 0;
}

#ifdef X86_VM_ENABLE_RODATA
static __always_inline int x86_rodata_trace_event_switch(__u64 index,
							 __u64 *out)
{
	if (index == 0) {
		*out = 56;
		return 0;
	}
	if (index == 1) {
		*out = 43;
		return 0;
	}
	if (index == 2) {
		*out = 57;
		return 0;
	}
	if (index == 3) {
		*out = 28;
		return 0;
	}
	if (index == 4) {
		*out = 14;
		return 0;
	}
	if (index == 5) {
		*out = 61;
		return 0;
	}
	if (index == 6) {
		*out = 10;
		return 0;
	}
	if (index == 7) {
		*out = 58;
		return 0;
	}
	if (index == 8) {
		*out = 2;
		return 0;
	}
	if (index == 9) {
		*out = 63;
		return 0;
	}
	if (index == 10) {
		*out = 49;
		return 0;
	}
	if (index == 11) {
		*out = 36;
		return 0;
	}
	if (index == 12) {
		*out = 19;
		return 0;
	}
	if (index == 13) {
		*out = 42;
		return 0;
	}
	if (index == 14) {
		*out = 37;
		return 0;
	}
	if (index == 15) {
		*out = 46;
		return 0;
	}
	if (index == 16) {
		*out = 34;
		return 0;
	}
	if (index == 17) {
		*out = 62;
		return 0;
	}
	if (index == 18) {
		*out = 47;
		return 0;
	}
	if (index == 19) {
		*out = 6;
		return 0;
	}
	if (index == 20) {
		*out = 29;
		return 0;
	}
	if (index == 21) {
		*out = 21;
		return 0;
	}
	if (index == 22) {
		*out = 15;
		return 0;
	}
	if (index == 23) {
		*out = 40;
		return 0;
	}
	if (index == 24) {
		*out = 38;
		return 0;
	}
	if (index == 25) {
		*out = 26;
		return 0;
	}
	if (index == 26) {
		*out = 17;
		return 0;
	}
	if (index == 27) {
		*out = 41;
		return 0;
	}
	if (index == 28) {
		*out = 33;
		return 0;
	}
	if (index == 29) {
		*out = 31;
		return 0;
	}
	if (index == 30) {
		*out = 23;
		return 0;
	}
	if (index == 31) {
		*out = 52;
		return 0;
	}
	if (index == 32) {
		*out = 25;
		return 0;
	}
	if (index == 33) {
		*out = 39;
		return 0;
	}
	if (index == 34) {
		*out = 11;
		return 0;
	}
	if (index == 35) {
		*out = 27;
		return 0;
	}
	if (index == 36) {
		*out = 53;
		return 0;
	}
	if (index == 37) {
		*out = 4;
		return 0;
	}
	if (index == 38) {
		*out = 24;
		return 0;
	}
	if (index == 39) {
		*out = 48;
		return 0;
	}
	if (index == 40) {
		*out = 32;
		return 0;
	}
	if (index == 41) {
		*out = 50;
		return 0;
	}
	if (index == 42) {
		*out = 7;
		return 0;
	}
	if (index == 43) {
		*out = 35;
		return 0;
	}
	if (index == 44) {
		*out = 8;
		return 0;
	}
	if (index == 45) {
		*out = 44;
		return 0;
	}
	if (index == 46) {
		*out = 51;
		return 0;
	}
	if (index == 47) {
		*out = 59;
		return 0;
	}
	if (index == 48) {
		*out = 45;
		return 0;
	}
	if (index == 49) {
		*out = 0;
		return 0;
	}
	if (index == 50) {
		*out = 9;
		return 0;
	}
	if (index == 51) {
		*out = 3;
		return 0;
	}
	if (index == 52) {
		*out = 13;
		return 0;
	}
	if (index == 53) {
		*out = 20;
		return 0;
	}
	if (index == 54) {
		*out = 30;
		return 0;
	}
	if (index == 55) {
		*out = 18;
		return 0;
	}
	if (index == 56) {
		*out = 1;
		return 0;
	}
	if (index == 57) {
		*out = 54;
		return 0;
	}
	if (index == 58) {
		*out = 22;
		return 0;
	}
	if (index == 59) {
		*out = 16;
		return 0;
	}
	if (index == 60) {
		*out = 60;
		return 0;
	}
	if (index == 61) {
		*out = 5;
		return 0;
	}
	if (index == 62) {
		*out = 12;
		return 0;
	}
	if (index == 63) {
		*out = 55;
		return 0;
	}
	return X86_INTERP_TRAP;
}

static __always_inline int x86_load_rodata(struct x86_state *state,
					   __u8 dst, __u64 base,
					   __s64 disp, __u8 load_width,
					   __u8 write_width, __u8 sign_extend)
{
	__u64 value = 0;

	if (base == 3782 && load_width == X86_WIDTH_64 &&
	    disp >= 0 && disp < 512 && (disp & 7) == 0) {
		if (x86_rodata_trace_event_switch((__u64)disp >> 3,
						  &value) < 0)
			return X86_INTERP_TRAP;
		if (sign_extend)
			value = x86_sign_extend(value, load_width);
		return x86_write_reg_width(state, dst, value, write_width);
	}
	return X86_INTERP_TRAP;
}
#endif

static __always_inline int x86_store_packet_imm(void *data, void *data_end,
						void *base, __s64 disp,
						__u8 width, __u64 value)
{
	__u8 *addr;

	if (x86_packet_bounds(data, data_end, base, disp, width, &addr) < 0)
		return X86_INTERP_TRAP;
	if (width == X86_WIDTH_8)
		*(__u8 *)addr = value;
	else if (width == X86_WIDTH_16)
		*(__u16 *)addr = value;
	else if (width == X86_WIDTH_32)
		*(__u32 *)addr = value;
	else
		*(__u64 *)addr = value;
	return X86_INTERP_CONTINUE;
}

static __always_inline int x86_store_packet_reg(struct x86_state *state,
						__u8 src, void *data,
						void *data_end, void *base,
						__s64 disp, __u8 width,
						__u32 aux)
{
	__u64 value;
	__u8 src_shift = X86_REG_AUX_GET_SRC_SHIFT(aux);

	if (x86_read_reg(state, src, &value) < 0)
		return X86_INTERP_TRAP;
	if (src_shift != 0)
		value >>= src_shift;
	return x86_store_packet_imm(data, data_end, base, disp, width, value);
}

static __always_inline int x86_load_mem(struct x86_state *state,
					const struct x86_insn *insn,
					void *data, void *data_end)
{
	void *base;
	__u8 tag;
	__s64 disp = x86_simm(insn->imm);
	__u8 mem_width = X86_MEM_AUX_MEM_WIDTH(insn->aux);

	if (x86_read_ptr_reg(state, insn->src, &base, &tag) < 0)
		return X86_INTERP_TRAP;
	if (x86_mem_offset(state, insn->aux, disp, &disp) < 0)
		return X86_INTERP_TRAP;
	if (mem_width == 0)
		mem_width = insn->flags;
#ifdef X86_VM_ENABLE_STACK
	if (insn->src == X86_RSP) {
		__u64 base_value = 0;

		if (x86_read_reg(state, insn->src, &base_value) < 0)
			return X86_INTERP_TRAP;
		return x86_load_stack(state, insn->dst,
				      (__s64)base_value + disp,
				      insn->flags);
	}
#endif
	if (tag == X86_PTR_CTX && insn->src == X86_RDI && disp == 0)
		return x86_write_ptr_reg(state, insn->dst, data,
					 X86_PTR_PACKET);
	if (tag == X86_PTR_CTX && insn->src == X86_RDI && disp == 8)
		return x86_write_ptr_reg(state, insn->dst, data_end,
					 X86_PTR_PACKET_END);
#ifdef X86_VM_ENABLE_STACK
	if (tag == X86_PTR_STACK) {
		__u64 base_value = 0;

		if (x86_read_reg(state, insn->src, &base_value) < 0)
			return X86_INTERP_TRAP;
		return x86_load_stack(state, insn->dst,
				      (__s64)base_value + disp,
				      insn->flags);
	}
#endif
	if (tag == X86_PTR_PACKET)
		return x86_load_packet(state, insn->dst, data, data_end, base,
				       disp, mem_width, insn->flags,
				       insn->op == X86_OP_MOVSX_LOAD);
#ifdef X86_VM_ENABLE_RODATA
	if (tag == X86_PTR_RODATA) {
		__u64 base_value = 0;

		if (x86_read_reg(state, insn->src, &base_value) < 0)
			return X86_INTERP_TRAP;
		return x86_load_rodata(state, insn->dst, base_value, disp,
				       mem_width, insn->flags,
				       insn->op == X86_OP_MOVSX_LOAD);
	}
#endif
	return X86_INTERP_TRAP;
}

static __always_inline int x86_read_mem_value(struct x86_state *state,
					      __u8 base_reg, __u32 aux,
					      __u64 imm, void *data,
					      void *data_end, __u8 width,
					      __u64 *value)
{
	void *base;
	__u8 tag;
	__s64 disp = x86_simm(imm);

	if (x86_read_ptr_reg(state, base_reg, &base, &tag) < 0)
		return X86_INTERP_TRAP;
	if (x86_mem_offset(state, aux, disp, &disp) < 0)
		return X86_INTERP_TRAP;
#ifdef X86_VM_ENABLE_STACK
	if (tag == X86_PTR_STACK) {
		__u64 stack_base = 0;
		void *ptr = 0;
		__u8 ptr_tag = X86_PTR_NONE;

		if (x86_read_reg(state, base_reg, &stack_base) < 0)
			return X86_INTERP_TRAP;
		if (width != X86_WIDTH_64)
			return X86_INTERP_TRAP;
		return x86_stack_read_raw(state, (__s64)stack_base + disp,
					  value, &ptr, &ptr_tag);
	}
#endif
	if (tag == X86_PTR_PACKET)
		return x86_read_packet_value(data, data_end, base, disp, width,
					     value);
	return X86_INTERP_TRAP;
}

static __always_inline int x86_store_mem(struct x86_state *state,
					 const struct x86_insn *insn,
					 void *data, void *data_end)
{
	void *base;
	__u8 tag;
	__s64 disp = insn->op == X86_OP_MOV_STORE_IMM ?
			     x86_store_imm_disp(insn->imm) :
			     x86_simm(insn->imm);

	if (x86_read_ptr_reg(state, insn->dst, &base, &tag) < 0)
		return X86_INTERP_TRAP;
	if (x86_mem_offset(state, insn->aux, disp, &disp) < 0)
		return X86_INTERP_TRAP;
#ifdef X86_VM_ENABLE_STACK
	if (insn->dst == X86_RSP) {
		__u64 base_value = 0;

		if (insn->op == X86_OP_MOV_STORE_IMM)
			return X86_INTERP_TRAP;
		if (x86_read_reg(state, insn->dst, &base_value) < 0)
			return X86_INTERP_TRAP;
		return x86_store_stack_reg(state, insn->src,
					   (__s64)base_value + disp,
					   insn->flags);
	}
	if (tag == X86_PTR_STACK) {
		__u64 base_value = 0;

		if (insn->op == X86_OP_MOV_STORE_IMM)
			return X86_INTERP_TRAP;
		if (x86_read_reg(state, insn->dst, &base_value) < 0)
			return X86_INTERP_TRAP;
		return x86_store_stack_reg(state, insn->src,
					   (__s64)base_value + disp,
					   insn->flags);
	}
#endif
	if (tag != X86_PTR_PACKET)
		return X86_INTERP_TRAP;
	if (insn->op == X86_OP_MOV_STORE_IMM)
		return x86_store_packet_imm(data, data_end, base, disp,
					    insn->flags,
					    x86_store_imm_value(insn->imm));
	return x86_store_packet_reg(state, insn->src, data, data_end, base,
				    disp, insn->flags, insn->aux);
}

static __always_inline int x86_cmp_mem_imm(struct x86_state *state,
					   const struct x86_insn *insn,
					   void *data, void *data_end)
{
	void *base;
	__u8 tag;
	__s64 disp = insn->op == X86_OP_CMP_MEM_REG ?
			     x86_simm(insn->imm) :
			     x86_store_imm_disp(insn->imm);
	__u8 *addr;
	__u64 value = 0;
	__u64 imm = x86_store_imm_value(insn->imm);

	if (x86_read_ptr_reg(state, insn->dst, &base, &tag) < 0)
		return X86_INTERP_TRAP;
	if (x86_mem_offset(state, insn->aux, disp, &disp) < 0)
		return X86_INTERP_TRAP;
	if (tag != X86_PTR_PACKET)
		return X86_INTERP_TRAP;
	if (x86_packet_bounds(data, data_end, base, disp, insn->flags, &addr) < 0)
		return X86_INTERP_TRAP;
	if (insn->flags == X86_WIDTH_8)
		value = *(__u8 *)addr;
	else if (insn->flags == X86_WIDTH_16)
		value = *(__u16 *)addr;
	else if (insn->flags == X86_WIDTH_32)
		value = *(__u32 *)addr;
	else
		value = *(__u64 *)addr;
	if (insn->op == X86_OP_CMP_MEM_REG) {
		if (x86_read_reg(state, insn->src, &imm) < 0)
			return X86_INTERP_TRAP;
		x86_set_sub_flags(state, value, imm, value - imm,
				  insn->flags);
		return X86_INTERP_CONTINUE;
	}
	if (insn->op == X86_OP_TEST_MEM_IMM)
		x86_set_logic_flags(state, value & imm, insn->flags);
	else
		x86_set_sub_flags(state, value, imm, value - imm,
				  insn->flags);
	return X86_INTERP_CONTINUE;
}

static __always_inline int x86_exec_nop(struct x86_state *state,
					const struct x86_insn *insn,
					void *data, void *data_end)
{
	return X86_INTERP_CONTINUE;
}

static __always_inline int x86_exec_mov_imm(struct x86_state *state,
					    const struct x86_insn *insn,
					    void *data, void *data_end)
{
	__u8 width = insn->flags ? insn->flags : X86_WIDTH_64;

	return x86_write_reg_width(state, insn->dst, insn->imm, width);
}

static __always_inline int x86_exec_mov_reg(struct x86_state *state,
					    const struct x86_insn *insn,
					    void *data, void *data_end)
{
	__u8 width = insn->flags ? insn->flags : X86_WIDTH_64;
	__u64 src_value = 0;
	void *src_ptr = 0;
	__u8 src_tag = X86_PTR_NONE;

	if (x86_read_reg(state, insn->src, &src_value) < 0)
		return X86_INTERP_TRAP;
	if (x86_write_reg_width(state, insn->dst, src_value, width) < 0)
		return X86_INTERP_TRAP;
	if (width == X86_WIDTH_64 &&
	    x86_read_ptr_reg(state, insn->src, &src_ptr, &src_tag) == 0 &&
	    src_tag != X86_PTR_NONE)
		return x86_write_ptr_reg(state, insn->dst, src_ptr, src_tag);
	return X86_INTERP_CONTINUE;
}

static __always_inline int x86_exec_movzx_reg(struct x86_state *state,
					      const struct x86_insn *insn,
					      void *data, void *data_end)
{
	__u8 width = insn->flags ? insn->flags : X86_WIDTH_64;
	__u8 src_width = insn->aux ? insn->aux : width;
	__u64 src_value = 0;

	if (x86_read_reg(state, insn->src, &src_value) < 0)
		return X86_INTERP_TRAP;
	src_value = x86_apply_width(src_value, src_width);
	return x86_write_reg_width(state, insn->dst, src_value, width);
}

static __always_inline int x86_exec_movsx_reg(struct x86_state *state,
					      const struct x86_insn *insn,
					      void *data, void *data_end)
{
	__u8 width = insn->flags ? insn->flags : X86_WIDTH_64;
	__u8 src_width = insn->aux ? insn->aux : width;
	__u64 src_value = 0;

	if (x86_read_reg(state, insn->src, &src_value) < 0)
		return X86_INTERP_TRAP;
	src_value = x86_sign_extend(src_value, src_width);
	return x86_write_reg_width(state, insn->dst, src_value, width);
}

static __always_inline int x86_exec_mov_load(struct x86_state *state,
					     const struct x86_insn *insn,
					     void *data, void *data_end)
{
	return x86_load_mem(state, insn, data, data_end);
}

static __always_inline int x86_exec_movsx_load(struct x86_state *state,
					       const struct x86_insn *insn,
					       void *data, void *data_end)
{
	return x86_load_mem(state, insn, data, data_end);
}

static __always_inline int x86_exec_mov_store_imm(struct x86_state *state,
						  const struct x86_insn *insn,
						  void *data, void *data_end)
{
	return x86_store_mem(state, insn, data, data_end);
}

static __always_inline int x86_exec_mov_store_reg(struct x86_state *state,
						  const struct x86_insn *insn,
						  void *data, void *data_end)
{
	return x86_store_mem(state, insn, data, data_end);
}

static __always_inline int x86_exec_lea(struct x86_state *state,
					const struct x86_insn *insn,
					void *data, void *data_end)
{
	__u8 width = insn->flags ? insn->flags : X86_WIDTH_64;
	__u64 src_value = 0;
	void *src_ptr = 0;
	__u8 src_tag = X86_PTR_NONE;
	__s64 off = x86_simm(insn->imm);

#ifdef X86_VM_ENABLE_RODATA
	if (width == X86_WIDTH_64 && insn->src == X86_REG_NONE &&
	    insn->aux == X86_PTR_RODATA) {
		if (x86_write_reg_width(state, insn->dst, insn->imm, width) < 0)
			return X86_INTERP_TRAP;
		return x86_write_ptr_reg(state, insn->dst, 0, X86_PTR_RODATA);
	}
#endif
	if (x86_mem_offset(state, insn->aux, off, &off) < 0)
		return X86_INTERP_TRAP;
	if (insn->src != X86_REG_NONE &&
	    x86_read_reg(state, insn->src, &src_value) < 0)
		return X86_INTERP_TRAP;
	if (width == X86_WIDTH_64 &&
	    x86_read_ptr_reg(state, insn->src, &src_ptr, &src_tag) == 0 &&
	    (src_tag == X86_PTR_PACKET || src_tag == X86_PTR_PACKET_END)) {
		if (x86_write_reg_width(state, insn->dst, 0, width) < 0)
			return X86_INTERP_TRAP;
		return x86_write_ptr_reg(state, insn->dst, (__u8 *)src_ptr + off,
					 src_tag);
	}
	return x86_write_reg_width(state, insn->dst, src_value + off, width);
}

static __always_inline int x86_exec_alu_imm(struct x86_state *state,
					    const struct x86_insn *insn,
					    void *data, void *data_end)
{
	__u8 width = insn->flags ? insn->flags : X86_WIDTH_64;
	__u64 dst_value = 0;
	__u64 result = 0;
	void *src_ptr = 0;
	__u8 src_tag = X86_PTR_NONE;

	if (x86_read_reg(state, insn->dst, &dst_value) < 0)
		return X86_INTERP_TRAP;
#ifdef X86_VM_ENABLE_STACK
	if (width == X86_WIDTH_64 && insn->dst == X86_RSP &&
	    (insn->aux == X86_ALU_ADD || insn->aux == X86_ALU_SUB)) {
		__s64 off = x86_simm(insn->imm);

		if (insn->aux == X86_ALU_SUB)
			off = -off;
		result = dst_value + off;
		if (x86_write_reg_width(state, insn->dst, result, width) < 0)
			return X86_INTERP_TRAP;
		return x86_write_ptr_reg(state, insn->dst, 0, X86_PTR_STACK);
	}
#endif
	if (width == X86_WIDTH_64 &&
	    (insn->aux == X86_ALU_ADD || insn->aux == X86_ALU_SUB) &&
	    x86_read_ptr_reg(state, insn->dst, &src_ptr, &src_tag) == 0 &&
	    (src_tag == X86_PTR_PACKET || src_tag == X86_PTR_PACKET_END ||
	     src_tag == X86_PTR_STACK)) {
		__s64 off = x86_simm(insn->imm);

		if (insn->aux == X86_ALU_SUB)
			off = -off;
#ifdef X86_VM_ENABLE_STACK
		if (src_tag == X86_PTR_STACK) {
			result = dst_value + off;
			if (x86_write_reg_width(state, insn->dst, result,
						width) < 0)
				return X86_INTERP_TRAP;
			return x86_write_ptr_reg(state, insn->dst, 0,
						 X86_PTR_STACK);
		}
#endif
		if (x86_write_reg_width(state, insn->dst, 0, width) < 0)
			return X86_INTERP_TRAP;
		return x86_write_ptr_reg(state, insn->dst,
					 (__u8 *)src_ptr + off, src_tag);
	}
	result = x86_alu_result(dst_value, insn->imm, insn->aux, width);
	x86_set_logic_flags(state, result, width);
	return x86_write_reg_width(state, insn->dst, result, width);
}

static __always_inline int x86_exec_add_imm(struct x86_state *state,
					    const struct x86_insn *insn,
					    void *data, void *data_end)
{
	return x86_exec_alu_imm(state, insn, data, data_end);
}

static __always_inline int x86_exec_alu_mem(struct x86_state *state,
					    const struct x86_insn *insn,
					    void *data, void *data_end)
{
	__u8 width = insn->flags ? insn->flags : X86_WIDTH_64;
	__u8 alu = X86_MEM_AUX_GET_ALU_OP(insn->aux);
	__u64 dst_value = 0;
	__u64 mem_value = 0;
	__u64 result = 0;

	if (x86_read_reg(state, insn->dst, &dst_value) < 0)
		return X86_INTERP_TRAP;
	if (x86_read_mem_value(state, insn->src, insn->aux, insn->imm, data,
			       data_end, width, &mem_value) < 0)
		return X86_INTERP_TRAP;
	result = x86_alu_result(dst_value, mem_value, alu, width);
	x86_set_logic_flags(state, result, width);
	return x86_write_reg_width(state, insn->dst, result, width);
}

static __always_inline int x86_exec_alu_reg(struct x86_state *state,
					    const struct x86_insn *insn,
					    void *data, void *data_end)
{
	__u8 width = insn->flags ? insn->flags : X86_WIDTH_64;
	__u64 dst_value = 0;
	__u64 src_value = 0;
	__u64 result = 0;

	if (x86_read_reg(state, insn->dst, &dst_value) < 0)
		return X86_INTERP_TRAP;
	if (x86_read_reg(state, insn->src, &src_value) < 0)
		return X86_INTERP_TRAP;
	result = x86_alu_result(dst_value, src_value, insn->aux, width);
	x86_set_logic_flags(state, result, width);
	return x86_write_reg_width(state, insn->dst, result, width);
}

static __always_inline int x86_exec_add_reg(struct x86_state *state,
					    const struct x86_insn *insn,
					    void *data, void *data_end)
{
	return x86_exec_alu_reg(state, insn, data, data_end);
}

static __always_inline int x86_exec_xor_reg(struct x86_state *state,
					    const struct x86_insn *insn,
					    void *data, void *data_end)
{
	return x86_exec_alu_reg(state, insn, data, data_end);
}

static __always_inline int x86_exec_cmp_imm(struct x86_state *state,
					    const struct x86_insn *insn,
					    void *data, void *data_end)
{
	__u8 width = insn->flags ? insn->flags : X86_WIDTH_64;
	__u64 dst_value = 0;

	if (x86_read_reg(state, insn->dst, &dst_value) < 0)
		return X86_INTERP_TRAP;
	x86_set_sub_flags(state, dst_value, insn->imm, dst_value - insn->imm,
			  width);
	return X86_INTERP_CONTINUE;
}

static __always_inline int x86_exec_cmp_reg(struct x86_state *state,
					    const struct x86_insn *insn,
					    void *data, void *data_end)
{
	__u8 width = insn->flags ? insn->flags : X86_WIDTH_64;
	__u64 dst_value = 0;
	__u64 src_value = 0;
	void *src_ptr = 0;
	__u8 src_tag = X86_PTR_NONE;

	if (x86_read_reg(state, insn->dst, &dst_value) < 0)
		return X86_INTERP_TRAP;
	if (x86_read_reg(state, insn->src, &src_value) < 0)
		return X86_INTERP_TRAP;
	if (x86_read_ptr_reg(state, insn->dst, &src_ptr, &src_tag) == 0 &&
	    src_tag != X86_PTR_NONE) {
		void *rhs_ptr;
		__u8 rhs_tag;

		if (x86_read_ptr_reg(state, insn->src, &rhs_ptr, &rhs_tag) == 0 &&
		    rhs_tag != X86_PTR_NONE) {
			state->cf = (__u8 *)src_ptr < (__u8 *)rhs_ptr;
			state->zf = src_ptr == rhs_ptr;
			state->sf = 0;
			state->of = 0;
			return X86_INTERP_CONTINUE;
		}
	}
	x86_set_sub_flags(state, dst_value, src_value, dst_value - src_value,
			  width);
	return X86_INTERP_CONTINUE;
}

static __always_inline int x86_exec_cmp_mem_imm(struct x86_state *state,
						const struct x86_insn *insn,
						void *data, void *data_end)
{
	return x86_cmp_mem_imm(state, insn, data, data_end);
}

static __always_inline int x86_exec_cmp_mem_reg(struct x86_state *state,
						const struct x86_insn *insn,
						void *data, void *data_end)
{
	return x86_cmp_mem_imm(state, insn, data, data_end);
}

static __always_inline int x86_exec_test_mem_imm(struct x86_state *state,
						 const struct x86_insn *insn,
						 void *data, void *data_end)
{
	return x86_cmp_mem_imm(state, insn, data, data_end);
}

static __always_inline int x86_exec_test_imm(struct x86_state *state,
					     const struct x86_insn *insn,
					     void *data, void *data_end)
{
	__u8 width = insn->flags ? insn->flags : X86_WIDTH_64;
	__u64 dst_value = 0;

	if (x86_read_reg(state, insn->dst, &dst_value) < 0)
		return X86_INTERP_TRAP;
	x86_set_logic_flags(state, dst_value & insn->imm, width);
	return X86_INTERP_CONTINUE;
}

static __always_inline int x86_exec_test_reg(struct x86_state *state,
					     const struct x86_insn *insn,
					     void *data, void *data_end)
{
	__u8 width = insn->flags ? insn->flags : X86_WIDTH_64;
	__u64 dst_value = 0;
	__u64 src_value = 0;

	if (x86_read_reg(state, insn->dst, &dst_value) < 0)
		return X86_INTERP_TRAP;
	if (x86_read_reg(state, insn->src, &src_value) < 0)
		return X86_INTERP_TRAP;
	x86_set_logic_flags(state, dst_value & src_value, width);
	return X86_INTERP_CONTINUE;
}

static __always_inline int x86_exec_cmov(struct x86_state *state,
					 const struct x86_insn *insn,
					 void *data, void *data_end)
{
	__u8 width = insn->flags ? insn->flags : X86_WIDTH_64;
	__u64 src_value = 0;

	if (!x86_eval_cc(state, insn->aux))
		return X86_INTERP_CONTINUE;
	if (x86_read_reg(state, insn->src, &src_value) < 0)
		return X86_INTERP_TRAP;
	return x86_write_reg_width(state, insn->dst, src_value, width);
}

static __always_inline int x86_exec_setcc(struct x86_state *state,
					  const struct x86_insn *insn,
					  void *data, void *data_end)
{
	return x86_write_reg_width(state, insn->dst,
				   x86_eval_cc(state, insn->aux), X86_WIDTH_8);
}

static __always_inline int x86_exec_bswap(struct x86_state *state,
					  const struct x86_insn *insn,
					  void *data, void *data_end)
{
	__u8 width = insn->flags ? insn->flags : X86_WIDTH_64;
	__u64 dst_value = 0;

	if (x86_read_reg(state, insn->dst, &dst_value) < 0)
		return X86_INTERP_TRAP;
	return x86_write_reg_width(state, insn->dst,
				   x86_bswap(dst_value, width), width);
}

static __always_inline int x86_exec_popcnt(struct x86_state *state,
					   const struct x86_insn *insn,
					   void *data, void *data_end)
{
	__u8 width = insn->flags ? insn->flags : X86_WIDTH_64;
	__u64 src_value = 0;
	__u64 result = 0;

	if (x86_read_reg(state, insn->src, &src_value) < 0)
		return X86_INTERP_TRAP;
	result = x86_popcount64(x86_apply_width(src_value, width));
	return x86_write_reg_width(state, insn->dst, result, width);
}

static __always_inline int x86_exec_xchg(struct x86_state *state,
					 const struct x86_insn *insn,
					 void *data, void *data_end)
{
	__u8 width = insn->flags ? insn->flags : X86_WIDTH_64;
	__u64 dst_value = 0;
	__u64 src_value = 0;

	if (x86_read_reg(state, insn->dst, &dst_value) < 0)
		return X86_INTERP_TRAP;
	if (x86_read_reg(state, insn->src, &src_value) < 0)
		return X86_INTERP_TRAP;
	if (x86_write_reg_width(state, insn->dst, src_value, width) < 0)
		return X86_INTERP_TRAP;
	return x86_write_reg_width(state, insn->src, dst_value, width);
}

static __always_inline int x86_exec_control_noop(struct x86_state *state,
						 const struct x86_insn *insn,
						 void *data, void *data_end)
{
	return X86_INTERP_CONTINUE;
}

static __always_inline int x86_exec_jcc(struct x86_state *state,
					const struct x86_insn *insn,
					void *data, void *data_end)
{
	return x86_exec_control_noop(state, insn, data, data_end);
}

static __always_inline int x86_exec_jmp(struct x86_state *state,
					const struct x86_insn *insn,
					void *data, void *data_end)
{
	return x86_exec_control_noop(state, insn, data, data_end);
}

static __always_inline int x86_exec_call(struct x86_state *state,
					 const struct x86_insn *insn,
					 void *data, void *data_end)
{
	return x86_exec_control_noop(state, insn, data, data_end);
}

static __always_inline int x86_exec_div(struct x86_state *state,
					const struct x86_insn *insn,
					void *data, void *data_end)
{
	return x86_exec_control_noop(state, insn, data, data_end);
}

static __always_inline int x86_exec_shld_imm(struct x86_state *state,
					     const struct x86_insn *insn,
					     void *data, void *data_end)
{
	return x86_exec_control_noop(state, insn, data, data_end);
}

static __always_inline int x86_exec_shrd_imm(struct x86_state *state,
					     const struct x86_insn *insn,
					     void *data, void *data_end)
{
	return x86_exec_control_noop(state, insn, data, data_end);
}

static __always_inline int x86_exec_push(struct x86_state *state,
					 const struct x86_insn *insn,
					 void *data, void *data_end)
{
#ifdef X86_VM_ENABLE_STACK
	return x86_push_reg(state, insn->src);
#else
	return X86_INTERP_CONTINUE;
#endif
}

static __always_inline int x86_exec_pop(struct x86_state *state,
					const struct x86_insn *insn,
					void *data, void *data_end)
{
	__u8 width = insn->flags ? insn->flags : X86_WIDTH_64;

#ifdef X86_VM_ENABLE_STACK
	return x86_pop_reg(state, insn->dst, width);
#else
	return X86_INTERP_CONTINUE;
#endif
}

static __always_inline int x86_exec_ret(struct x86_state *state,
					const struct x86_insn *insn,
					void *data, void *data_end)
{
	return X86_INTERP_DONE;
}

static __always_inline int x86_exec_one(struct x86_state *state,
					const struct x86_insn *insn,
					void *data, void *data_end)
{
	if (insn->op == X86_OP_NOP)
		return x86_exec_nop(state, insn, data, data_end);
	if (insn->op == X86_OP_MOV_IMM)
		return x86_exec_mov_imm(state, insn, data, data_end);
	if (insn->op == X86_OP_MOV_REG)
		return x86_exec_mov_reg(state, insn, data, data_end);
	if (insn->op == X86_OP_MOVZX_REG)
		return x86_exec_movzx_reg(state, insn, data, data_end);
	if (insn->op == X86_OP_MOVSX_REG)
		return x86_exec_movsx_reg(state, insn, data, data_end);
	if (insn->op == X86_OP_MOV_LOAD)
		return x86_exec_mov_load(state, insn, data, data_end);
	if (insn->op == X86_OP_MOVSX_LOAD)
		return x86_exec_movsx_load(state, insn, data, data_end);
	if (insn->op == X86_OP_MOV_STORE_IMM)
		return x86_exec_mov_store_imm(state, insn, data, data_end);
	if (insn->op == X86_OP_MOV_STORE_REG)
		return x86_exec_mov_store_reg(state, insn, data, data_end);
	if (insn->op == X86_OP_LEA)
		return x86_exec_lea(state, insn, data, data_end);
	if (insn->op == X86_OP_ADD_IMM)
		return x86_exec_add_imm(state, insn, data, data_end);
	if (insn->op == X86_OP_ALU_IMM)
		return x86_exec_alu_imm(state, insn, data, data_end);
	if (insn->op == X86_OP_ALU_MEM)
		return x86_exec_alu_mem(state, insn, data, data_end);
	if (insn->op == X86_OP_ADD_REG)
		return x86_exec_add_reg(state, insn, data, data_end);
	if (insn->op == X86_OP_XOR_REG)
		return x86_exec_xor_reg(state, insn, data, data_end);
	if (insn->op == X86_OP_ALU_REG)
		return x86_exec_alu_reg(state, insn, data, data_end);
	if (insn->op == X86_OP_CMP_IMM)
		return x86_exec_cmp_imm(state, insn, data, data_end);
	if (insn->op == X86_OP_CMP_REG)
		return x86_exec_cmp_reg(state, insn, data, data_end);
	if (insn->op == X86_OP_CMP_MEM_IMM)
		return x86_exec_cmp_mem_imm(state, insn, data, data_end);
	if (insn->op == X86_OP_CMP_MEM_REG)
		return x86_exec_cmp_mem_reg(state, insn, data, data_end);
	if (insn->op == X86_OP_TEST_MEM_IMM)
		return x86_exec_test_mem_imm(state, insn, data, data_end);
	if (insn->op == X86_OP_TEST_IMM)
		return x86_exec_test_imm(state, insn, data, data_end);
	if (insn->op == X86_OP_TEST_REG)
		return x86_exec_test_reg(state, insn, data, data_end);
	if (insn->op == X86_OP_CMOV)
		return x86_exec_cmov(state, insn, data, data_end);
	if (insn->op == X86_OP_SETCC)
		return x86_exec_setcc(state, insn, data, data_end);
	if (insn->op == X86_OP_BSWAP)
		return x86_exec_bswap(state, insn, data, data_end);
	if (insn->op == X86_OP_POPCNT)
		return x86_exec_popcnt(state, insn, data, data_end);
	if (insn->op == X86_OP_XCHG)
		return x86_exec_xchg(state, insn, data, data_end);
	if (insn->op == X86_OP_JCC)
		return x86_exec_jcc(state, insn, data, data_end);
	if (insn->op == X86_OP_JMP)
		return x86_exec_jmp(state, insn, data, data_end);
	if (insn->op == X86_OP_CALL)
		return x86_exec_call(state, insn, data, data_end);
	if (insn->op == X86_OP_DIV)
		return x86_exec_div(state, insn, data, data_end);
	if (insn->op == X86_OP_SHLD_IMM)
		return x86_exec_shld_imm(state, insn, data, data_end);
	if (insn->op == X86_OP_SHRD_IMM)
		return x86_exec_shrd_imm(state, insn, data, data_end);
	if (insn->op == X86_OP_PUSH)
		return x86_exec_push(state, insn, data, data_end);
	if (insn->op == X86_OP_POP)
		return x86_exec_pop(state, insn, data, data_end);
	if (insn->op == X86_OP_RET)
		return x86_exec_ret(state, insn, data, data_end);
	return X86_INTERP_TRAP;
}

#endif
