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

#define X86_MEM_AUX(INDEX, SCALE_LOG2) \
	(((__u32)(INDEX) & 0xffU) | (((__u32)(SCALE_LOG2) & 0xffU) << 8))
#define X86_MEM_AUX_FULL(INDEX, SCALE_LOG2, MEM_WIDTH)                    \
	(X86_MEM_AUX((INDEX), (SCALE_LOG2)) |                             \
	 (((__u32)(MEM_WIDTH) & 0xffU) << 16))
#define X86_MEM_AUX_INDEX(AUX) ((__u8)((AUX) & 0xffU))
#define X86_MEM_AUX_SCALE_LOG2(AUX) ((__u8)(((AUX) >> 8) & 0xffU))
#define X86_MEM_AUX_MEM_WIDTH(AUX) ((__u8)(((AUX) >> 16) & 0xffU))

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
};

static __always_inline void x86_init_state(struct x86_state *state, void *ctx)
{
	state->p_rdi = ctx;
	state->tag_rdi = X86_PTR_CTX;
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
						__s64 disp, __u8 width)
{
	__u64 value;

	if (x86_read_reg(state, src, &value) < 0)
		return X86_INTERP_TRAP;
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
	if (tag == X86_PTR_CTX && insn->src == X86_RDI && disp == 0)
		return x86_write_ptr_reg(state, insn->dst, data,
					 X86_PTR_PACKET);
	if (tag == X86_PTR_CTX && insn->src == X86_RDI && disp == 8)
		return x86_write_ptr_reg(state, insn->dst, data_end,
					 X86_PTR_PACKET_END);
	if (mem_width == 0)
		mem_width = insn->flags;
	if (tag == X86_PTR_PACKET)
		return x86_load_packet(state, insn->dst, data, data_end, base,
				       disp, mem_width, insn->flags,
				       insn->op == X86_OP_MOVSX_LOAD);
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
	if (tag != X86_PTR_PACKET)
		return X86_INTERP_TRAP;
	if (insn->op == X86_OP_MOV_STORE_IMM)
		return x86_store_packet_imm(data, data_end, base, disp,
					    insn->flags,
					    x86_store_imm_value(insn->imm));
	return x86_store_packet_reg(state, insn->src, data, data_end, base,
				    disp, insn->flags);
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

static __always_inline int x86_exec_one(struct x86_state *state,
					const struct x86_insn *insn,
					void *data, void *data_end)
{
	__u8 width = insn->flags ? insn->flags : X86_WIDTH_64;
	__u64 dst_value = 0;
	__u64 src_value = 0;
	__u64 result = 0;
	void *src_ptr = 0;
	__u8 src_tag = X86_PTR_NONE;

	if (insn->op == X86_OP_NOP)
		return X86_INTERP_CONTINUE;
	if (insn->op == X86_OP_MOV_IMM)
		return x86_write_reg_width(state, insn->dst, insn->imm, width);
	if (insn->op == X86_OP_MOV_REG) {
		if (x86_read_reg(state, insn->src, &src_value) < 0)
			return X86_INTERP_TRAP;
		if (x86_write_reg_width(state, insn->dst, src_value, width) < 0)
			return X86_INTERP_TRAP;
		if (width == X86_WIDTH_64 &&
		    x86_read_ptr_reg(state, insn->src, &src_ptr, &src_tag) == 0 &&
		    src_tag != X86_PTR_NONE)
			return x86_write_ptr_reg(state, insn->dst, src_ptr,
						 src_tag);
		return X86_INTERP_CONTINUE;
	}
	if (insn->op == X86_OP_MOVZX_REG || insn->op == X86_OP_MOVSX_REG) {
		__u8 src_width = insn->aux ? insn->aux : width;

		if (x86_read_reg(state, insn->src, &src_value) < 0)
			return X86_INTERP_TRAP;
		if (insn->op == X86_OP_MOVSX_REG)
			src_value = x86_sign_extend(src_value, src_width);
		else
			src_value = x86_apply_width(src_value, src_width);
		return x86_write_reg_width(state, insn->dst, src_value, width);
	}
	if (insn->op == X86_OP_MOV_LOAD || insn->op == X86_OP_MOVSX_LOAD)
		return x86_load_mem(state, insn, data, data_end);
	if (insn->op == X86_OP_MOV_STORE_IMM ||
	    insn->op == X86_OP_MOV_STORE_REG)
		return x86_store_mem(state, insn, data, data_end);
	if (insn->op == X86_OP_LEA) {
		if (x86_read_reg(state, insn->src, &src_value) < 0)
			src_value = 0;
		if (width == X86_WIDTH_64 &&
		    x86_read_ptr_reg(state, insn->src, &src_ptr, &src_tag) == 0 &&
		    (src_tag == X86_PTR_PACKET ||
		     src_tag == X86_PTR_PACKET_END)) {
			if (x86_write_reg_width(state, insn->dst, 0, width) < 0)
				return X86_INTERP_TRAP;
			return x86_write_ptr_reg(state, insn->dst,
						 (__u8 *)src_ptr +
							 x86_simm(insn->imm),
						 src_tag);
		}
		return x86_write_reg_width(state, insn->dst,
					   src_value + insn->imm, width);
	}
	if (insn->op == X86_OP_ADD_IMM || insn->op == X86_OP_ALU_IMM) {
		if (x86_read_reg(state, insn->dst, &dst_value) < 0)
			return X86_INTERP_TRAP;
		if (width == X86_WIDTH_64 &&
		    (insn->aux == X86_ALU_ADD || insn->aux == X86_ALU_SUB) &&
		    x86_read_ptr_reg(state, insn->dst, &src_ptr, &src_tag) == 0 &&
		    (src_tag == X86_PTR_PACKET ||
		     src_tag == X86_PTR_PACKET_END)) {
			__s64 off = x86_simm(insn->imm);

			if (insn->aux == X86_ALU_SUB)
				off = -off;
			if (x86_write_reg_width(state, insn->dst, 0, width) < 0)
				return X86_INTERP_TRAP;
			return x86_write_ptr_reg(state, insn->dst,
						 (__u8 *)src_ptr + off,
						 src_tag);
		}
		result = x86_alu_result(dst_value, insn->imm, insn->aux, width);
		x86_set_logic_flags(state, result, width);
		return x86_write_reg_width(state, insn->dst, result, width);
	}
	if (insn->op == X86_OP_ADD_REG || insn->op == X86_OP_XOR_REG ||
	    insn->op == X86_OP_ALU_REG) {
		if (x86_read_reg(state, insn->dst, &dst_value) < 0)
			return X86_INTERP_TRAP;
		if (x86_read_reg(state, insn->src, &src_value) < 0)
			return X86_INTERP_TRAP;
		result = x86_alu_result(dst_value, src_value, insn->aux, width);
		x86_set_logic_flags(state, result, width);
		return x86_write_reg_width(state, insn->dst, result, width);
	}
	if (insn->op == X86_OP_CMP_IMM) {
		if (x86_read_reg(state, insn->dst, &dst_value) < 0)
			return X86_INTERP_TRAP;
		x86_set_sub_flags(state, dst_value, insn->imm,
				  dst_value - insn->imm, width);
		return X86_INTERP_CONTINUE;
	}
	if (insn->op == X86_OP_CMP_REG) {
		if (x86_read_reg(state, insn->dst, &dst_value) < 0)
			return X86_INTERP_TRAP;
		if (x86_read_reg(state, insn->src, &src_value) < 0)
			return X86_INTERP_TRAP;
		if (x86_read_ptr_reg(state, insn->dst, &src_ptr, &src_tag) == 0 &&
		    src_tag != X86_PTR_NONE) {
			void *rhs_ptr;
			__u8 rhs_tag;

			if (x86_read_ptr_reg(state, insn->src, &rhs_ptr,
					     &rhs_tag) == 0 &&
			    rhs_tag != X86_PTR_NONE) {
				state->cf = (__u8 *)src_ptr < (__u8 *)rhs_ptr;
				state->zf = src_ptr == rhs_ptr;
				state->sf = 0;
				state->of = 0;
				return X86_INTERP_CONTINUE;
			}
		}
		x86_set_sub_flags(state, dst_value, src_value,
				  dst_value - src_value, width);
		return X86_INTERP_CONTINUE;
	}
	if (insn->op == X86_OP_CMP_MEM_IMM ||
	    insn->op == X86_OP_CMP_MEM_REG ||
	    insn->op == X86_OP_TEST_MEM_IMM)
		return x86_cmp_mem_imm(state, insn, data, data_end);
	if (insn->op == X86_OP_TEST_IMM) {
		if (x86_read_reg(state, insn->dst, &dst_value) < 0)
			return X86_INTERP_TRAP;
		x86_set_logic_flags(state, dst_value & insn->imm, width);
		return X86_INTERP_CONTINUE;
	}
	if (insn->op == X86_OP_TEST_REG) {
		if (x86_read_reg(state, insn->dst, &dst_value) < 0)
			return X86_INTERP_TRAP;
		if (x86_read_reg(state, insn->src, &src_value) < 0)
			return X86_INTERP_TRAP;
		x86_set_logic_flags(state, dst_value & src_value, width);
		return X86_INTERP_CONTINUE;
	}
	if (insn->op == X86_OP_CMOV) {
		if (!x86_eval_cc(state, insn->aux))
			return X86_INTERP_CONTINUE;
		if (x86_read_reg(state, insn->src, &src_value) < 0)
			return X86_INTERP_TRAP;
		return x86_write_reg_width(state, insn->dst, src_value, width);
	}
	if (insn->op == X86_OP_SETCC)
		return x86_write_reg_width(state, insn->dst,
					   x86_eval_cc(state, insn->aux),
					   X86_WIDTH_8);
	if (insn->op == X86_OP_BSWAP) {
		if (x86_read_reg(state, insn->dst, &dst_value) < 0)
			return X86_INTERP_TRAP;
		return x86_write_reg_width(state, insn->dst,
					   x86_bswap(dst_value, width), width);
	}
	if (insn->op == X86_OP_POPCNT) {
		if (x86_read_reg(state, insn->src, &src_value) < 0)
			return X86_INTERP_TRAP;
		result = x86_popcount64(x86_apply_width(src_value, width));
		return x86_write_reg_width(state, insn->dst, result, width);
	}
	if (insn->op == X86_OP_XCHG) {
		if (x86_read_reg(state, insn->dst, &dst_value) < 0)
			return X86_INTERP_TRAP;
		if (x86_read_reg(state, insn->src, &src_value) < 0)
			return X86_INTERP_TRAP;
		if (x86_write_reg_width(state, insn->dst, src_value, width) < 0)
			return X86_INTERP_TRAP;
		return x86_write_reg_width(state, insn->src, dst_value, width);
	}
	if (insn->op == X86_OP_JCC || insn->op == X86_OP_JMP ||
	    insn->op == X86_OP_PUSH || insn->op == X86_OP_POP ||
	    insn->op == X86_OP_CALL || insn->op == X86_OP_DIV ||
	    insn->op == X86_OP_SHLD_IMM || insn->op == X86_OP_SHRD_IMM)
		return X86_INTERP_CONTINUE;
	if (insn->op == X86_OP_RET)
		return X86_INTERP_DONE;
	return X86_INTERP_TRAP;
}

#endif
