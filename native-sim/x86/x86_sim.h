#ifndef X86_SIM_H
#define X86_SIM_H

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

#define X86_SIM_CONTINUE 0

#define X86_PTR_NONE 0U
#define X86_PTR_CTX 1U
#define X86_PTR_PACKET 2U
#define X86_PTR_PACKET_END 3U
#define X86_PTR_RODATA 4U
#define X86_PTR_STACK 5U
#define X86_PTR_PACKET_LEN 6U
#define X86_STACK_PTR_SLOT_NONE 0xffU

#define X86_CTX_DATA_OFF 0LL
#define X86_CTX_DATA_END_OFF 8LL
#define X86_SKB_LEN_OFF 0x70LL
#define X86_SKB_DATA_OFF 0xd0LL

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

#ifdef X86_SIM_ENABLE_STACK
#ifndef X86_SIM_STACK_BYTES
#ifdef X86_SIM_ENABLE_STACK_DEEP
#define X86_SIM_STACK_BYTES 128U
#else
#define X86_SIM_STACK_BYTES 64U
#endif
#endif
#endif

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
	__s32 off_rax;
	__s32 off_rcx;
	__s32 off_rdx;
	__s32 off_rbx;
	__s32 off_rsp;
	__s32 off_rbp;
	__s32 off_rsi;
	__s32 off_rdi;
	__s32 off_r8;
	__s32 off_r9;
	__s32 off_r10;
	__s32 off_r11;
	__s32 off_r12;
	__s32 off_r13;
	__s32 off_r14;
	__s32 off_r15;
	__u8 cf;
	__u8 zf;
	__u8 sf;
	__u8 of;
#ifdef X86_SIM_ENABLE_STACK
	__u8 stack_mem[X86_SIM_STACK_BYTES];
#endif
};

static __always_inline void x86_init_state(struct x86_state *state, void *ctx)
{
	state->rdi = (__u64)(long)ctx;
	state->p_rdi = ctx;
	state->tag_rdi = X86_PTR_CTX;
#ifdef X86_SIM_ENABLE_STACK
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

#define X86_FOR_EACH_GPR(X)                                                \
	X(X86_RAX, rax, p_rax, tag_rax, off_rax)                           \
	X(X86_RCX, rcx, p_rcx, tag_rcx, off_rcx)                           \
	X(X86_RDX, rdx, p_rdx, tag_rdx, off_rdx)                           \
	X(X86_RBX, rbx, p_rbx, tag_rbx, off_rbx)                           \
	X(X86_RSP, rsp, p_rsp, tag_rsp, off_rsp)                           \
	X(X86_RBP, rbp, p_rbp, tag_rbp, off_rbp)                           \
	X(X86_RSI, rsi, p_rsi, tag_rsi, off_rsi)                           \
	X(X86_RDI, rdi, p_rdi, tag_rdi, off_rdi)                           \
	X(X86_R8, r8, p_r8, tag_r8, off_r8)                                \
	X(X86_R9, r9, p_r9, tag_r9, off_r9)                                \
	X(X86_R10, r10, p_r10, tag_r10, off_r10)                           \
	X(X86_R11, r11, p_r11, tag_r11, off_r11)                           \
	X(X86_R12, r12, p_r12, tag_r12, off_r12)                           \
	X(X86_R13, r13, p_r13, tag_r13, off_r13)                           \
	X(X86_R14, r14, p_r14, tag_r14, off_r14)                           \
	X(X86_R15, r15, p_r15, tag_r15, off_r15)

static __always_inline void x86_clear_ptr_reg(struct x86_state *state,
					      __u8 reg)
{
	switch (reg) {
#define X86_CLEAR_PTR_CASE(REG, VALUE, PTR, TAG, OFF)                      \
	case REG:                                                          \
		state->PTR = 0;                                            \
		state->TAG = X86_PTR_NONE;                                 \
		state->OFF = 0;                                           \
		return;
	X86_FOR_EACH_GPR(X86_CLEAR_PTR_CASE)
#undef X86_CLEAR_PTR_CASE
	default:
		return;
	}
}

static __always_inline void x86_read_ptr_reg(const struct x86_state *state,
					     __u8 reg, void **ptr, __u8 *tag)
{
	*ptr = 0;
	*tag = X86_PTR_NONE;
	switch (reg) {
#define X86_READ_PTR_CASE(REG, VALUE, PTR, TAG, OFF)                       \
	case REG:                                                          \
		*ptr = state->PTR;                                        \
		*tag = state->TAG;                                        \
		return;
	X86_FOR_EACH_GPR(X86_READ_PTR_CASE)
#undef X86_READ_PTR_CASE
	default:
		return;
	}
}

static __always_inline __s32 x86_read_ptr_off_reg(const struct x86_state *state,
						  __u8 reg)
{
	switch (reg) {
#define X86_READ_PTR_OFF_CASE(REG, VALUE, PTR, TAG, OFF)                   \
	case REG:                                                          \
		return state->OFF;
	X86_FOR_EACH_GPR(X86_READ_PTR_OFF_CASE)
#undef X86_READ_PTR_OFF_CASE
	default:
		return 0;
	}
}

static __always_inline int x86_write_ptr_off_reg(struct x86_state *state,
						 __u8 reg, __s32 off)
{
	switch (reg) {
#define X86_WRITE_PTR_OFF_CASE(REG, VALUE, PTR, TAG, OFF)                  \
	case REG:                                                          \
		state->OFF = off;                                          \
		return X86_SIM_CONTINUE;
	X86_FOR_EACH_GPR(X86_WRITE_PTR_OFF_CASE)
#undef X86_WRITE_PTR_OFF_CASE
	default:
		return X86_SIM_CONTINUE;
	}
}

static __always_inline int x86_write_ptr_reg(struct x86_state *state,
					     __u8 reg, void *ptr, __u8 tag)
{
	x86_write_ptr_off_reg(state, reg, 0);
	switch (reg) {
#define X86_WRITE_PTR_CASE(REG, VALUE, PTR, TAG, OFF)                      \
	case REG:                                                          \
		state->PTR = ptr;                                         \
		state->TAG = tag;                                         \
		return X86_SIM_CONTINUE;
	X86_FOR_EACH_GPR(X86_WRITE_PTR_CASE)
#undef X86_WRITE_PTR_CASE
	default:
		return X86_SIM_CONTINUE;
	}
}

static __always_inline int x86_write_ptr_reg_off(struct x86_state *state,
						 __u8 reg, void *ptr, __u8 tag,
						 __s32 off)
{
	x86_write_ptr_reg(state, reg, ptr, tag);
	return x86_write_ptr_off_reg(state, reg, off);
}

static __always_inline __u64 x86_read_reg(const struct x86_state *state,
					  __u8 reg)
{
	switch (reg) {
#define X86_READ_REG_CASE(REG, VALUE, PTR, TAG, OFF)                       \
	case REG:                                                          \
		return state->VALUE;
	X86_FOR_EACH_GPR(X86_READ_REG_CASE)
#undef X86_READ_REG_CASE
	default:
		return 0;
	}
}

static __always_inline int x86_write_reg_width(struct x86_state *state,
					       __u8 reg, __u64 value,
					       __u8 width)
{
	__u64 next_value = value;

	x86_clear_ptr_reg(state, reg);
	if (width == X86_WIDTH_8 || width == X86_WIDTH_16) {
		__u64 old_value = x86_read_reg(state, reg);

		next_value = (old_value & ~x86_width_mask(width)) |
			     (value & x86_width_mask(width));
	} else if (width == X86_WIDTH_32) {
		next_value = (__u32)value;
	}

	switch (reg) {
#define X86_WRITE_REG_CASE(REG, VALUE, PTR, TAG, OFF)                      \
	case REG:                                                          \
		state->VALUE = next_value;                                \
		return X86_SIM_CONTINUE;
	X86_FOR_EACH_GPR(X86_WRITE_REG_CASE)
#undef X86_WRITE_REG_CASE
	default:
		return X86_SIM_CONTINUE;
	}
}

static __always_inline int x86_write_reg(struct x86_state *state,
					 __u8 reg, __u64 value)
{
	return x86_write_reg_width(state, reg, value, X86_WIDTH_64);
}

#ifdef X86_SIM_ENABLE_STACK
static __always_inline __u32 x86_stack_index(__s64 off)
{
	return (__u32)(off + X86_SIM_STACK_BYTES);
}

static __always_inline void
x86_stack_clear_ptr_range(struct x86_state *state, __u32 index, __u8 width)
{
	(void)state;
	(void)index;
	(void)width;
}

static __always_inline int x86_stack_write_raw(struct x86_state *state,
					       __s64 off, __u8 width,
					       __u64 value, void *ptr,
					       __u8 tag)
{
	__u32 index = x86_stack_index(off);
	__u64 narrowed = value & x86_width_mask(width);

	(void)ptr;
	(void)tag;
	state->stack_mem[index] = narrowed;
	if (width >= X86_WIDTH_16)
		state->stack_mem[index + 1] = narrowed >> 8;
	if (width >= X86_WIDTH_32) {
		state->stack_mem[index + 2] = narrowed >> 16;
		state->stack_mem[index + 3] = narrowed >> 24;
	}
	if (width == X86_WIDTH_64) {
		state->stack_mem[index + 4] = narrowed >> 32;
		state->stack_mem[index + 5] = narrowed >> 40;
		state->stack_mem[index + 6] = narrowed >> 48;
		state->stack_mem[index + 7] = narrowed >> 56;
	}
	x86_stack_clear_ptr_range(state, index, width);
	return X86_SIM_CONTINUE;
}

static __always_inline int x86_stack_read_raw(struct x86_state *state,
					      __s64 off, __u8 width,
					      __u64 *value,
					      void **ptr, __u8 *tag)
{
	__u32 index = x86_stack_index(off);

	*value = state->stack_mem[index];
	if (width >= X86_WIDTH_16)
		*value |= (__u64)state->stack_mem[index + 1] << 8;
	if (width >= X86_WIDTH_32) {
		*value |= (__u64)state->stack_mem[index + 2] << 16;
		*value |= (__u64)state->stack_mem[index + 3] << 24;
	}
	if (width == X86_WIDTH_64) {
		*value |= (__u64)state->stack_mem[index + 4] << 32;
		*value |= (__u64)state->stack_mem[index + 5] << 40;
		*value |= (__u64)state->stack_mem[index + 6] << 48;
		*value |= (__u64)state->stack_mem[index + 7] << 56;
	}
	*ptr = 0;
	*tag = X86_PTR_NONE;
	return X86_SIM_CONTINUE;
}

static __always_inline int x86_push_reg(struct x86_state *state, __u8 reg)
{
	__u64 value = 0;
	void *ptr = 0;
	__u8 tag = X86_PTR_NONE;

	value = x86_read_reg(state, reg);
	x86_read_ptr_reg(state, reg, &ptr, &tag);
	state->rsp -= 8;
	return x86_stack_write_raw(state, (__s64)state->rsp, X86_WIDTH_64,
				   value, ptr, tag);
}

static __always_inline int x86_pop_reg(struct x86_state *state, __u8 reg,
				       __u8 width)
{
	__u64 value = 0;
	void *ptr = 0;
	__u8 tag = X86_PTR_NONE;

	x86_stack_read_raw(state, (__s64)state->rsp, width, &value, &ptr,
			   &tag);
	x86_write_reg_width(state, reg, value, width);
	if (width == X86_WIDTH_64 && tag != X86_PTR_NONE)
		x86_write_ptr_reg(state, reg, ptr, tag);
	state->rsp += 8;
	return X86_SIM_CONTINUE;
}

static __always_inline int x86_load_stack(struct x86_state *state, __u8 dst,
					  __s64 off, __u8 width)
{
	__u64 value = 0;
	void *ptr = 0;
	__u8 tag = X86_PTR_NONE;

	x86_stack_read_raw(state, off, width, &value, &ptr, &tag);
	x86_write_reg_width(state, dst, value, width);
	if (tag != X86_PTR_NONE)
		return x86_write_ptr_reg(state, dst, ptr, tag);
	return X86_SIM_CONTINUE;
}

static __always_inline int x86_store_stack_reg(struct x86_state *state,
					       __u8 src, __s64 off,
					       __u8 width, __u32 aux)
{
	__u64 value = 0;
	void *ptr = 0;
	__u8 tag = X86_PTR_NONE;
	__u8 src_shift = X86_REG_AUX_GET_SRC_SHIFT(aux);

	value = x86_read_reg(state, src);
	if (src_shift != 0)
		value >>= src_shift;
	x86_read_ptr_reg(state, src, &ptr, &tag);
	if (width != X86_WIDTH_64)
		tag = X86_PTR_NONE;
	return x86_stack_write_raw(state, off, width, value, ptr, tag);
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
	state->zf = a == b;
	state->sf = (r & sign) != 0;
	state->of = ((a ^ b) & (a ^ r) & sign) != 0;
}

static __always_inline void x86_set_add_flags(struct x86_state *state,
					      __u64 lhs, __u64 rhs,
					      __u64 result, __u8 width)
{
	__u64 mask = x86_width_mask(width);
	__u64 a = lhs & mask;
	__u64 b = rhs & mask;
	__u64 r = result & mask;
	__u32 bits = x86_width_bits(width);
	__u64 sign = 1ULL << (bits - 1);

	state->cf = r < a;
	state->zf = r == 0;
	state->sf = (r & sign) != 0;
	state->of = (~(a ^ b) & (a ^ r) & sign) != 0;
}

static __always_inline __u8 x86_shift_count(__u64 rhs, __u8 width)
{
	if (width == X86_WIDTH_64)
		return rhs & 0x3f;
	return rhs & 0x1f;
}

static __always_inline void x86_set_sbb_flags(struct x86_state *state,
					      __u64 lhs, __u64 rhs,
					      __u8 borrow, __u64 result,
					      __u8 width)
{
	__u64 mask = x86_width_mask(width);
	__u64 a = lhs & mask;
	__u64 b = rhs & mask;
	__u64 sub = (b + borrow) & mask;
	__u64 r = result & mask;
	__u32 bits = x86_width_bits(width);
	__u64 sign = 1ULL << (bits - 1);

	state->cf = (a < b) || (borrow && a == b);
	state->zf = r == 0;
	state->sf = (r & sign) != 0;
	state->of = ((a ^ sub) & (a ^ r) & sign) != 0;
}

static __always_inline __u64 x86_signed_abs_width(__u64 value, __u8 width)
{
	__u64 narrowed = x86_apply_width(value, width);
	__u64 sign = 1ULL << (x86_width_bits(width) - 1);

	if (!(narrowed & sign))
		return narrowed;
	return ((~narrowed) + 1) & x86_width_mask(width);
}

static __always_inline void x86_set_imul_flags(struct x86_state *state,
					       __u64 lhs, __u64 rhs,
					       __u8 width)
{
	__u64 a_abs = x86_signed_abs_width(lhs, width);
	__u64 b_abs = x86_signed_abs_width(rhs, width);
	__u64 sign = 1ULL << (x86_width_bits(width) - 1);
	__u64 limit = ((lhs ^ rhs) & sign) ? sign : sign - 1;
	__u8 overflow = 0;

	if (a_abs != 0 && b_abs > limit / a_abs)
		overflow = 1;
	state->cf = overflow;
	state->of = overflow;
}

static __always_inline void x86_set_shift_flags(struct x86_state *state,
						__u64 lhs, __u64 rhs,
						__u64 result, __u32 alu,
						__u8 width)
{
	__u32 bits = x86_width_bits(width);
	__u64 mask = x86_width_mask(width);
	__u64 a = lhs & mask;
	__u64 r = result & mask;
	__u8 count = x86_shift_count(rhs, width);
	__u64 sign = 1ULL << (bits - 1);

	if (alu == X86_ALU_ROL) {
		__u8 amount = count % bits;

		if (amount == 0)
			return;
		state->cf = r & 1;
		if (amount == 1)
			state->of = ((r & sign) != 0) ^ state->cf;
		return;
	}
	if (count == 0)
		return;
	state->zf = r == 0;
	state->sf = (r & sign) != 0;
	if (alu == X86_ALU_SHL) {
		state->cf = count <= bits ? (a >> (bits - count)) & 1 : 0;
		if (count == 1)
			state->of = ((r & sign) != 0) ^ state->cf;
		return;
	}
	if (alu == X86_ALU_SHR) {
		state->cf = count <= bits ? (a >> (count - 1)) & 1 : 0;
		if (count == 1)
			state->of = (a & sign) != 0;
		return;
	}
	if (alu == X86_ALU_SAR) {
		state->cf = count <= bits ? (a >> (count - 1)) & 1 :
					   (a & sign) != 0;
		if (count == 1)
			state->of = 0;
	}
}

static __always_inline void x86_set_popcnt_flags(struct x86_state *state,
						 __u64 src, __u8 width)
{
	state->cf = 0;
	state->of = 0;
	state->sf = 0;
	state->zf = x86_apply_width(src, width) == 0;
}

static __always_inline void x86_set_alu_flags(struct x86_state *state,
					      __u64 lhs, __u64 rhs,
					      __u64 result, __u32 alu,
					      __u8 width)
{
	__u8 old_cf = state->cf;

	if (alu == X86_ALU_ADD) {
		x86_set_add_flags(state, lhs, rhs, result, width);
		return;
	}
	if (alu == X86_ALU_INC) {
		x86_set_add_flags(state, lhs, 1, result, width);
		state->cf = old_cf;
		return;
	}
	if (alu == X86_ALU_SUB) {
		x86_set_sub_flags(state, lhs, rhs, result, width);
		return;
	}
	if (alu == X86_ALU_SBB) {
		x86_set_sbb_flags(state, lhs, rhs, 0, result, width);
		return;
	}
	if (alu == X86_ALU_NOT)
		return;
	if (alu == X86_ALU_SHL || alu == X86_ALU_SHR ||
	    alu == X86_ALU_SAR || alu == X86_ALU_ROL) {
		x86_set_shift_flags(state, lhs, rhs, result, alu, width);
		return;
	}
	if (alu == X86_ALU_IMUL) {
		x86_set_imul_flags(state, lhs, rhs, width);
		return;
	}
	x86_set_logic_flags(state, result, width);
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
	__u64 amount = x86_shift_count(rhs, width);

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
	if (alu == X86_ALU_SHL) {
		if (amount >= bits)
			return 0;
		return lhs << amount;
	}
	if (alu == X86_ALU_SHR) {
		if (amount >= bits)
			return 0;
		return lhs >> amount;
	}
	if (alu == X86_ALU_SAR) {
		if (amount >= bits) {
			if (width == X86_WIDTH_32)
				return ((__u32)lhs & 0x80000000U) ?
					       0xffffffffU :
					       0;
			return ((__u64)lhs & 0x8000000000000000ULL) ?
				       0xffffffffffffffffULL :
				       0;
		}
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

static __always_inline __u64 x86_shld(__u64 dst, __u64 src, __u64 shift,
				      __u8 width)
{
	__u32 bits = x86_width_bits(width);
	__u64 mask = x86_width_mask(width);
	__u64 amount = x86_shift_count(shift, width);
	__u64 d = dst & mask;
	__u64 s = src & mask;

	if (amount == 0)
		return d;
	if (amount >= bits)
		return (s << (amount - bits)) & mask;
	return ((d << amount) | (s >> (bits - amount))) & mask;
}

static __always_inline __u64 x86_shrd(__u64 dst, __u64 src, __u64 shift,
				      __u8 width)
{
	__u32 bits = x86_width_bits(width);
	__u64 mask = x86_width_mask(width);
	__u64 amount = x86_shift_count(shift, width);
	__u64 d = dst & mask;
	__u64 s = src & mask;

	if (amount == 0)
		return d;
	if (amount >= bits)
		return (s >> (amount - bits)) & mask;
	return ((d >> amount) | (s << (bits - amount))) & mask;
}

static __always_inline void x86_set_shld_flags(struct x86_state *state,
					       __u64 dst, __u64 result,
					       __u64 shift, __u8 width)
{
	__u32 bits = x86_width_bits(width);
	__u64 mask = x86_width_mask(width);
	__u64 d = dst & mask;
	__u64 r = result & mask;
	__u8 count = x86_shift_count(shift, width);
	__u64 sign = 1ULL << (bits - 1);

	if (count == 0)
		return;
	state->cf = count <= bits ? (d >> (bits - count)) & 1 : 0;
	state->zf = r == 0;
	state->sf = (r & sign) != 0;
	if (count == 1)
		state->of = ((r & sign) != 0) ^ state->cf;
}

static __always_inline void x86_set_shrd_flags(struct x86_state *state,
					       __u64 dst, __u64 result,
					       __u64 shift, __u8 width)
{
	__u32 bits = x86_width_bits(width);
	__u64 mask = x86_width_mask(width);
	__u64 d = dst & mask;
	__u64 r = result & mask;
	__u8 count = x86_shift_count(shift, width);
	__u64 sign = 1ULL << (bits - 1);

	if (count == 0)
		return;
	state->cf = count <= bits ? (d >> (count - 1)) & 1 : 0;
	state->zf = r == 0;
	state->sf = (r & sign) != 0;
	if (count == 1)
		state->of = ((d ^ r) & sign) != 0;
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

static __always_inline __u64 x86_store_imm_value(__u64 value, __u8 width)
{
	__u32 imm32 = (__u32)value;

	if (width == X86_WIDTH_64)
		return (__u64)(__s64)(__s32)imm32;
	return imm32;
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
	index_value = x86_read_reg(state, index);
	*out += (__s64)(index_value << scale_log2);
	return 0;
}

static __always_inline int x86_promote_index_packet_base(struct x86_state *state,
							 __u8 base_reg,
							 __u32 aux,
							 void **base,
							 __u8 *tag,
							 __s64 *disp)
{
#ifndef X86_SIM_ENABLE_INDEX_PACKET_PROMOTE
	return 0;
#else
	__u8 index = X86_MEM_AUX_INDEX(aux);
	__u8 scale_log2 = X86_MEM_AUX_SCALE_LOG2(aux);
	void *index_ptr = 0;
	__u8 index_tag = X86_PTR_NONE;
	__u64 base_value = 0;

	if (*tag != X86_PTR_NONE || index == X86_REG_NONE || scale_log2 != 0)
		return 0;
	x86_read_ptr_reg(state, index, &index_ptr, &index_tag);
	if (index_tag != X86_PTR_PACKET)
		return 0;
	if (base_reg != X86_REG_NONE)
		base_value = x86_read_reg(state, base_reg);
	*base = index_ptr;
	*tag = X86_PTR_PACKET;
	*disp += (__s64)base_value;
	return 0;
#endif
}

static __always_inline __u8 *x86_packet_addr(void *ptr, __s64 disp)
{
	__u8 *p = ptr;

	return p + disp;
}

static __always_inline int x86_load_packet(struct x86_state *state,
					   __u8 dst, void *data,
					   void *data_end, void *base,
					   __s64 disp, __u8 load_width,
					   __u8 write_width, __u8 sign_extend)
{
	__u8 *addr;
	__u64 value = 0;

	(void)data;
	(void)data_end;
	addr = x86_packet_addr(base, disp);
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

	(void)data;
	(void)data_end;
	addr = x86_packet_addr(base, disp);
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


static __always_inline int x86_store_packet_imm(void *data, void *data_end,
						void *base, __s64 disp,
						__u8 width, __u64 value)
{
	__u8 *addr;

	(void)data;
	(void)data_end;
	addr = x86_packet_addr(base, disp);
	if (width == X86_WIDTH_8)
		*(__u8 *)addr = value;
	else if (width == X86_WIDTH_16)
		*(__u16 *)addr = value;
	else if (width == X86_WIDTH_32)
		*(__u32 *)addr = value;
	else
		*(__u64 *)addr = value;
	return X86_SIM_CONTINUE;
}

static __always_inline int x86_store_packet_reg(struct x86_state *state,
						__u8 src, void *data,
						void *data_end, void *base,
						__s64 disp, __u8 width,
						__u32 aux)
{
	__u64 value;
	__u8 src_shift = X86_REG_AUX_GET_SRC_SHIFT(aux);

	value = x86_read_reg(state, src);
	if (src_shift != 0)
		value >>= src_shift;
	return x86_store_packet_imm(data, data_end, base, disp, width, value);
}

static __always_inline int x86_load_mem(struct x86_state *state,
					const struct x86_insn *insn,
					void *data, void *data_end)
{
	void *base = 0;
	__u8 tag = X86_PTR_NONE;
	__s64 disp = x86_simm(insn->imm);
	__u8 mem_width = X86_MEM_AUX_MEM_WIDTH(insn->aux);
	__u64 base_value = 0;

	x86_mem_offset(state, insn->aux, disp, &disp);
	if (mem_width == 0)
		mem_width = insn->flags;
	if (insn->src != X86_REG_NONE) {
		base_value = x86_read_reg(state, insn->src);
		x86_read_ptr_reg(state, insn->src, &base, &tag);
	}
#ifdef X86_SIM_ENABLE_STACK
	if (insn->src == X86_RSP || insn->src == X86_RBP ||
	    tag == X86_PTR_STACK)
		return x86_load_stack(state, insn->dst,
				      (__s64)base_value + disp,
				      insn->flags);
#endif
#ifdef X86_SIM_ENABLE_PACKET_REG_FASTPATH
	if (insn->src == X86_RCX && state->tag_rcx == X86_PTR_PACKET) {
		return x86_load_packet(state, insn->dst, data, data_end,
				       state->p_rcx, disp, mem_width,
				       insn->flags,
				       insn->op == X86_OP_MOVSX_LOAD);
	}
	if (insn->src == X86_RSI && state->tag_rsi == X86_PTR_PACKET) {
		return x86_load_packet(state, insn->dst, data, data_end,
				       state->p_rsi, disp, mem_width,
				       insn->flags,
				       insn->op == X86_OP_MOVSX_LOAD);
	}
	if (X86_MEM_AUX_INDEX(insn->aux) == X86_RSI &&
	    X86_MEM_AUX_SCALE_LOG2(insn->aux) == 0 &&
	    state->tag_rsi == X86_PTR_PACKET) {
		return x86_load_packet(state, insn->dst, data, data_end,
				       state->p_rsi,
				       disp + (__s64)base_value, mem_width,
				       insn->flags,
				       insn->op == X86_OP_MOVSX_LOAD);
	}
#endif
	x86_promote_index_packet_base(state, insn->src, insn->aux,
				      &base, &tag, &disp);
	if (tag == X86_PTR_CTX && insn->src == X86_RDI &&
	    disp == X86_SKB_LEN_OFF && mem_width == X86_WIDTH_32) {
		__u64 value = (__u32)((__u64)data_end - (__u64)data);

		x86_write_reg_width(state, insn->dst, value, insn->flags);
		return x86_write_ptr_reg_off(state, insn->dst, data_end,
					     X86_PTR_PACKET_LEN, 0);
	}
	if (tag == X86_PTR_CTX && insn->src == X86_RDI &&
	    (disp == X86_CTX_DATA_OFF || disp == X86_SKB_DATA_OFF)) {
		x86_write_reg_width(state, insn->dst, (__u64)(long)data,
				    X86_WIDTH_64);
		return x86_write_ptr_reg_off(state, insn->dst, data,
					     X86_PTR_PACKET, 0);
	}
	if (tag == X86_PTR_CTX && insn->src == X86_RDI &&
	    disp == X86_CTX_DATA_END_OFF) {
		x86_write_reg_width(state, insn->dst, (__u64)(long)data_end,
				    X86_WIDTH_64);
		return x86_write_ptr_reg_off(state, insn->dst, data_end,
					     X86_PTR_PACKET_END, 0);
	}
	if (tag == X86_PTR_PACKET)
		return x86_load_packet(state, insn->dst, data, data_end, base,
				       disp, mem_width, insn->flags,
				       insn->op == X86_OP_MOVSX_LOAD);
	return x86_load_packet(state, insn->dst, data, data_end,
			       (void *)(long)base_value, disp, mem_width,
			       insn->flags, insn->op == X86_OP_MOVSX_LOAD);
}

static __always_inline int x86_read_mem_value(struct x86_state *state,
					      __u8 base_reg, __u32 aux,
					      __u64 imm, void *data,
					      void *data_end, __u8 width,
					      __u64 *value)
{
	void *base = 0;
	__u8 tag = X86_PTR_NONE;
	__s64 disp = x86_simm(imm);
	__u64 base_value = 0;

	x86_mem_offset(state, aux, disp, &disp);
	if (base_reg != X86_REG_NONE) {
		base_value = x86_read_reg(state, base_reg);
		x86_read_ptr_reg(state, base_reg, &base, &tag);
	}
#ifdef X86_SIM_ENABLE_STACK
	if (base_reg == X86_RSP || base_reg == X86_RBP ||
	    tag == X86_PTR_STACK) {
		void *ptr = 0;
		__u8 ptr_tag = X86_PTR_NONE;

		return x86_stack_read_raw(state, (__s64)base_value + disp,
					  width, value, &ptr, &ptr_tag);
	}
#endif
#ifdef X86_SIM_ENABLE_PACKET_REG_FASTPATH
	if (base_reg == X86_RCX && state->tag_rcx == X86_PTR_PACKET) {
		return x86_read_packet_value(data, data_end, state->p_rcx,
					     disp, width, value);
	}
	if (base_reg == X86_RSI && state->tag_rsi == X86_PTR_PACKET) {
		return x86_read_packet_value(data, data_end, state->p_rsi,
					     disp, width, value);
	}
	if (X86_MEM_AUX_INDEX(aux) == X86_RSI &&
	    X86_MEM_AUX_SCALE_LOG2(aux) == 0 &&
	    state->tag_rsi == X86_PTR_PACKET) {
		return x86_read_packet_value(data, data_end, state->p_rsi,
					     disp + (__s64)base_value,
					     width, value);
	}
#endif
	x86_promote_index_packet_base(state, base_reg, aux, &base, &tag,
				      &disp);
	if (tag == X86_PTR_CTX && base_reg == X86_RDI &&
	    disp == X86_SKB_LEN_OFF && width == X86_WIDTH_32) {
		*value = (__u32)((__u64)data_end - (__u64)data);
		return 0;
	}
	if (tag == X86_PTR_PACKET)
		return x86_read_packet_value(data, data_end, base, disp, width,
					     value);
	return x86_read_packet_value(data, data_end, (void *)(long)base_value,
				     disp, width, value);
}

static __always_inline int x86_store_mem(struct x86_state *state,
					 const struct x86_insn *insn,
					 void *data, void *data_end)
{
	void *base = 0;
	__u8 tag = X86_PTR_NONE;
	__s64 disp = insn->op == X86_OP_MOV_STORE_IMM ?
			     x86_store_imm_disp(insn->imm) :
			     x86_simm(insn->imm);
	__u64 base_value = 0;

	x86_mem_offset(state, insn->aux, disp, &disp);
	if (insn->dst != X86_REG_NONE) {
		base_value = x86_read_reg(state, insn->dst);
		x86_read_ptr_reg(state, insn->dst, &base, &tag);
	}
#ifdef X86_SIM_ENABLE_STACK
	if (insn->dst == X86_RSP || insn->dst == X86_RBP ||
	    tag == X86_PTR_STACK) {
		if (insn->op == X86_OP_MOV_STORE_IMM)
			return x86_stack_write_raw(state,
						   (__s64)base_value + disp,
						   insn->flags,
						   x86_store_imm_value(insn->imm,
								       insn->flags),
						   0, X86_PTR_NONE);
		return x86_store_stack_reg(state, insn->src,
					   (__s64)base_value + disp,
					   insn->flags, insn->aux);
	}
#endif
#ifdef X86_SIM_ENABLE_PACKET_REG_FASTPATH
	if (insn->dst == X86_RCX && state->tag_rcx == X86_PTR_PACKET) {
		if (insn->op == X86_OP_MOV_STORE_IMM)
			return x86_store_packet_imm(data, data_end,
						    state->p_rcx, disp,
						    insn->flags,
						    x86_store_imm_value(insn->imm,
									insn->flags));
		return x86_store_packet_reg(state, insn->src, data, data_end,
					    state->p_rcx, disp, insn->flags,
					    insn->aux);
	}
	if (insn->dst == X86_RSI && state->tag_rsi == X86_PTR_PACKET) {
		if (insn->op == X86_OP_MOV_STORE_IMM)
			return x86_store_packet_imm(data, data_end,
						    state->p_rsi, disp,
						    insn->flags,
						    x86_store_imm_value(insn->imm,
									insn->flags));
		return x86_store_packet_reg(state, insn->src, data, data_end,
					    state->p_rsi, disp, insn->flags,
					    insn->aux);
	}
#endif
	x86_promote_index_packet_base(state, insn->dst, insn->aux,
				      &base, &tag, &disp);
	if (insn->op == X86_OP_MOV_STORE_IMM)
		return x86_store_packet_imm(data, data_end,
					    tag == X86_PTR_NONE ?
						    (void *)(long)base_value : base,
					    disp,
					    insn->flags,
					    x86_store_imm_value(insn->imm,
								insn->flags));
	return x86_store_packet_reg(state, insn->src, data, data_end,
				    tag == X86_PTR_NONE ?
					    (void *)(long)base_value : base,
				    disp, insn->flags, insn->aux);
}

static __always_inline int x86_cmp_mem_imm(struct x86_state *state,
					   const struct x86_insn *insn,
					   void *data, void *data_end)
{
	void *base = 0;
	__u8 tag = X86_PTR_NONE;
	__s64 disp = insn->op == X86_OP_CMP_MEM_REG ?
			     x86_simm(insn->imm) :
			     x86_store_imm_disp(insn->imm);
	__u8 *addr;
	__u64 value = 0;
	__u64 imm = x86_store_imm_value(insn->imm, insn->flags);
	__u64 base_value = x86_read_reg(state, insn->dst);

	x86_read_ptr_reg(state, insn->dst, &base, &tag);
	x86_mem_offset(state, insn->aux, disp, &disp);
	if (tag == X86_PTR_CTX && insn->dst == X86_RDI &&
	    disp == X86_SKB_LEN_OFF && insn->flags == X86_WIDTH_32) {
		value = (__u32)((__u64)data_end - (__u64)data);
		if (insn->op == X86_OP_CMP_MEM_REG)
			imm = x86_read_reg(state, insn->src);
		if (insn->op == X86_OP_TEST_MEM_IMM)
			x86_set_logic_flags(state, value & imm, insn->flags);
		else
			x86_set_sub_flags(state, value, imm, value - imm,
					  insn->flags);
		return X86_SIM_CONTINUE;
	}
	(void)data;
	(void)data_end;
	if (tag == X86_PTR_NONE)
		base = (void *)(long)base_value;
	addr = x86_packet_addr(base, disp);
	if (insn->flags == X86_WIDTH_8)
		value = *(__u8 *)addr;
	else if (insn->flags == X86_WIDTH_16)
		value = *(__u16 *)addr;
	else if (insn->flags == X86_WIDTH_32)
		value = *(__u32 *)addr;
	else
		value = *(__u64 *)addr;
	if (insn->op == X86_OP_CMP_MEM_REG) {
		imm = x86_read_reg(state, insn->src);
		x86_set_sub_flags(state, value, imm, value - imm,
				  insn->flags);
		return X86_SIM_CONTINUE;
	}
	if (insn->op == X86_OP_TEST_MEM_IMM)
		x86_set_logic_flags(state, value & imm, insn->flags);
	else
		x86_set_sub_flags(state, value, imm, value - imm,
				  insn->flags);
	return X86_SIM_CONTINUE;
}

static __always_inline int x86_exec_nop(struct x86_state *state,
					const struct x86_insn *insn,
					void *data, void *data_end)
{
	return X86_SIM_CONTINUE;
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
	__s32 src_off = 0;

	src_value = x86_read_reg(state, insn->src);
	x86_write_reg_width(state, insn->dst, src_value, width);
	x86_read_ptr_reg(state, insn->src, &src_ptr, &src_tag);
	if (width == X86_WIDTH_64 && src_tag != X86_PTR_NONE) {
		src_off = x86_read_ptr_off_reg(state, insn->src);
		return x86_write_ptr_reg_off(state, insn->dst, src_ptr,
					     src_tag, src_off);
	}
	return X86_SIM_CONTINUE;
}

static __always_inline int x86_exec_movzx_reg(struct x86_state *state,
					      const struct x86_insn *insn,
					      void *data, void *data_end)
{
	__u8 width = insn->flags ? insn->flags : X86_WIDTH_64;
	__u8 src_width = insn->aux ? insn->aux : width;
	__u64 src_value = 0;

	src_value = x86_read_reg(state, insn->src);
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

	src_value = x86_read_reg(state, insn->src);
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
	__s32 src_off = 0;
	__s64 off = x86_simm(insn->imm);

	if (width == X86_WIDTH_64 && insn->src == X86_REG_NONE &&
	    insn->aux == X86_PTR_RODATA) {
		x86_write_reg_width(state, insn->dst, insn->imm, width);
		return X86_SIM_CONTINUE;
	}
	x86_mem_offset(state, insn->aux, off, &off);
	if (insn->src != X86_REG_NONE)
		src_value = x86_read_reg(state, insn->src);
	x86_read_ptr_reg(state, insn->src, &src_ptr, &src_tag);
	if (width == X86_WIDTH_64 &&
	    (src_tag == X86_PTR_PACKET || src_tag == X86_PTR_PACKET_END)) {
		src_off = x86_read_ptr_off_reg(state, insn->src);
		x86_write_reg_width(state, insn->dst, src_value + off, width);
		return x86_write_ptr_reg_off(state, insn->dst,
					     (__u8 *)src_ptr + off, src_tag,
					     src_off + off);
	}
	return x86_write_reg_width(state, insn->dst, src_value + off, width);
}

static __always_inline int x86_exec_alu_imm(struct x86_state *state,
					    const struct x86_insn *insn,
					    void *data, void *data_end)
{
	__u8 width = insn->flags ? insn->flags : X86_WIDTH_64;
	__u64 dst_value = 0;
	__u64 rhs = x86_store_imm_value(insn->imm, width);
	__u64 result = 0;
	void *src_ptr = 0;
	__u8 src_tag = X86_PTR_NONE;
	__s32 src_off = 0;

	dst_value = x86_read_reg(state, insn->dst);
#ifdef X86_SIM_ENABLE_STACK
	if (width == X86_WIDTH_64 && insn->dst == X86_RSP &&
	    (insn->aux == X86_ALU_ADD || insn->aux == X86_ALU_SUB)) {
		__s64 off = (__s64)rhs;

		if (insn->aux == X86_ALU_SUB)
			off = -off;
		result = x86_alu_result(dst_value, rhs, insn->aux, width);
		x86_set_alu_flags(state, dst_value, rhs, result, insn->aux,
				  width);
		x86_write_reg_width(state, insn->dst, result, width);
		return x86_write_ptr_reg(state, insn->dst, 0, X86_PTR_STACK);
	}
#endif
	x86_read_ptr_reg(state, insn->dst, &src_ptr, &src_tag);
	if (width == X86_WIDTH_64 &&
	    (insn->aux == X86_ALU_ADD || insn->aux == X86_ALU_SUB) &&
	    (src_tag == X86_PTR_PACKET || src_tag == X86_PTR_PACKET_END ||
	     src_tag == X86_PTR_STACK)) {
		__s64 off = (__s64)rhs;

		if (insn->aux == X86_ALU_SUB)
			off = -off;
		result = x86_alu_result(dst_value, rhs, insn->aux, width);
		x86_set_alu_flags(state, dst_value, rhs, result, insn->aux,
				  width);
#ifdef X86_SIM_ENABLE_STACK
		if (src_tag == X86_PTR_STACK) {
			x86_write_reg_width(state, insn->dst, result, width);
			return x86_write_ptr_reg(state, insn->dst, 0,
						 X86_PTR_STACK);
		}
#endif
		src_off = x86_read_ptr_off_reg(state, insn->dst);
		x86_write_reg_width(state, insn->dst, result, width);
		return x86_write_ptr_reg_off(state, insn->dst,
					     (__u8 *)src_ptr + off, src_tag,
					     src_off + off);
	}
	if (insn->aux == X86_ALU_SBB) {
		__u8 borrow = state->cf;

		result = dst_value - rhs - borrow;
		x86_set_sbb_flags(state, dst_value, rhs, borrow, result, width);
		return x86_write_reg_width(state, insn->dst, result, width);
	}
	result = x86_alu_result(dst_value, rhs, insn->aux, width);
	x86_set_alu_flags(state, dst_value, rhs, result, insn->aux, width);
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

	dst_value = x86_read_reg(state, insn->dst);
	x86_read_mem_value(state, insn->src, insn->aux, insn->imm, data,
			   data_end, width, &mem_value);
	if (alu == X86_ALU_SBB) {
		__u8 borrow = state->cf;

		result = dst_value - mem_value - borrow;
		x86_set_sbb_flags(state, dst_value, mem_value, borrow, result,
				  width);
		return x86_write_reg_width(state, insn->dst, result, width);
	}
	result = x86_alu_result(dst_value, mem_value, alu, width);
	x86_set_alu_flags(state, dst_value, mem_value, result, alu, width);
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
	void *dst_ptr = 0;
	void *src_ptr = 0;
	__u8 dst_tag = X86_PTR_NONE;
	__u8 src_tag = X86_PTR_NONE;
	__s32 dst_off = 0;
	__s32 src_off = 0;

	dst_value = x86_read_reg(state, insn->dst);
	src_value = x86_read_reg(state, insn->src);
	x86_read_ptr_reg(state, insn->dst, &dst_ptr, &dst_tag);
	x86_read_ptr_reg(state, insn->src, &src_ptr, &src_tag);
	if (width == X86_WIDTH_64 && insn->aux == X86_ALU_ADD &&
	    dst_tag == X86_PTR_PACKET_LEN && src_tag == X86_PTR_PACKET) {
		src_off = x86_read_ptr_off_reg(state, insn->src);
		result = x86_alu_result(dst_value, src_value, insn->aux, width);
		x86_set_alu_flags(state, dst_value, src_value, result,
				  insn->aux, width);
		x86_write_reg_width(state, insn->dst, result, width);
		return x86_write_ptr_reg_off(state, insn->dst,
					     (__u8 *)dst_ptr + src_off,
					     X86_PTR_PACKET_END, src_off);
	}
	if (width == X86_WIDTH_64 && insn->aux == X86_ALU_ADD &&
	    dst_tag == X86_PTR_PACKET && src_tag == X86_PTR_PACKET_LEN) {
		dst_off = x86_read_ptr_off_reg(state, insn->dst);
		result = x86_alu_result(dst_value, src_value, insn->aux, width);
		x86_set_alu_flags(state, dst_value, src_value, result,
				  insn->aux, width);
		x86_write_reg_width(state, insn->dst, result, width);
		return x86_write_ptr_reg_off(state, insn->dst,
					     (__u8 *)src_ptr + dst_off,
					     X86_PTR_PACKET_END, dst_off);
	}
	if (width == X86_WIDTH_64 && insn->aux == X86_ALU_ADD &&
	    (src_tag == X86_PTR_PACKET || src_tag == X86_PTR_PACKET_END) &&
	    dst_tag == X86_PTR_NONE) {
		src_off = x86_read_ptr_off_reg(state, insn->src);
		result = x86_alu_result(dst_value, src_value, insn->aux, width);
		x86_set_alu_flags(state, dst_value, src_value, result,
				  insn->aux, width);
		x86_write_reg_width(state, insn->dst, result, width);
		return x86_write_ptr_reg_off(state, insn->dst,
					     (__u8 *)src_ptr + dst_value,
					     src_tag, src_off + dst_value);
	}
	if (width == X86_WIDTH_64 &&
	    (insn->aux == X86_ALU_ADD || insn->aux == X86_ALU_SUB) &&
	    (dst_tag == X86_PTR_PACKET || dst_tag == X86_PTR_PACKET_END)) {
		__s64 off = (__s64)src_value;

		if (insn->aux == X86_ALU_SUB)
			off = -off;
		dst_off = x86_read_ptr_off_reg(state, insn->dst);
		result = x86_alu_result(dst_value, src_value, insn->aux, width);
		x86_set_alu_flags(state, dst_value, src_value, result,
				  insn->aux, width);
		x86_write_reg_width(state, insn->dst, result, width);
		return x86_write_ptr_reg_off(state, insn->dst,
					     (__u8 *)dst_ptr + off, dst_tag,
					     dst_off + off);
	}
	if (insn->aux == X86_ALU_SBB) {
		__u8 borrow = state->cf;

		result = dst_value - src_value - borrow;
		x86_set_sbb_flags(state, dst_value, src_value, borrow, result,
				  width);
		return x86_write_reg_width(state, insn->dst, result, width);
	}
	result = x86_alu_result(dst_value, src_value, insn->aux, width);
	x86_set_alu_flags(state, dst_value, src_value, result, insn->aux,
			  width);
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
	__u64 rhs = x86_store_imm_value(insn->imm, width);

	dst_value = x86_read_reg(state, insn->dst);
	x86_set_sub_flags(state, dst_value, rhs, dst_value - rhs, width);
	return X86_SIM_CONTINUE;
}

static __always_inline int x86_exec_cmp_reg(struct x86_state *state,
					    const struct x86_insn *insn,
					    void *data, void *data_end)
{
	__u8 width = insn->flags ? insn->flags : X86_WIDTH_64;
	__u64 dst_value = 0;
	__u64 src_value = 0;

	dst_value = x86_read_reg(state, insn->dst);
	src_value = x86_read_reg(state, insn->src);
	x86_set_sub_flags(state, dst_value, src_value, dst_value - src_value,
			  width);
	return X86_SIM_CONTINUE;
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
	__u64 rhs = x86_store_imm_value(insn->imm, width);

	dst_value = x86_read_reg(state, insn->dst);
	x86_set_logic_flags(state, dst_value & rhs, width);
	return X86_SIM_CONTINUE;
}

static __always_inline int x86_exec_test_reg(struct x86_state *state,
					     const struct x86_insn *insn,
					     void *data, void *data_end)
{
	__u8 width = insn->flags ? insn->flags : X86_WIDTH_64;
	__u64 dst_value = 0;
	__u64 src_value = 0;

	dst_value = x86_read_reg(state, insn->dst);
	src_value = x86_read_reg(state, insn->src);
	x86_set_logic_flags(state, dst_value & src_value, width);
	return X86_SIM_CONTINUE;
}

static __always_inline int x86_exec_cmov(struct x86_state *state,
					 const struct x86_insn *insn,
					 void *data, void *data_end)
{
	__u8 width = insn->flags ? insn->flags : X86_WIDTH_64;
	__u64 src_value = 0;
	void *src_ptr = 0;
	__u8 src_tag = X86_PTR_NONE;
	__s32 src_off = 0;

	if (!x86_eval_cc(state, insn->aux))
		return X86_SIM_CONTINUE;
	src_value = x86_read_reg(state, insn->src);
	x86_write_reg_width(state, insn->dst, src_value, width);
	x86_read_ptr_reg(state, insn->src, &src_ptr, &src_tag);
	if (width == X86_WIDTH_64 && src_tag != X86_PTR_NONE) {
		src_off = x86_read_ptr_off_reg(state, insn->src);
		return x86_write_ptr_reg_off(state, insn->dst, src_ptr,
					     src_tag, src_off);
	}
	return X86_SIM_CONTINUE;
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

	dst_value = x86_read_reg(state, insn->dst);
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

	src_value = x86_read_reg(state, insn->src);
	result = x86_popcount64(x86_apply_width(src_value, width));
	x86_set_popcnt_flags(state, src_value, width);
	return x86_write_reg_width(state, insn->dst, result, width);
}

static __always_inline int x86_exec_xchg(struct x86_state *state,
					 const struct x86_insn *insn,
					 void *data, void *data_end)
{
	__u8 width = insn->flags ? insn->flags : X86_WIDTH_64;
	__u64 dst_value = 0;
	__u64 src_value = 0;
	void *dst_ptr = 0;
	void *src_ptr = 0;
	__u8 dst_tag = X86_PTR_NONE;
	__u8 src_tag = X86_PTR_NONE;
	__s32 dst_off = 0;
	__s32 src_off = 0;

	if (insn->dst == insn->src)
		return X86_SIM_CONTINUE;
	dst_value = x86_read_reg(state, insn->dst);
	src_value = x86_read_reg(state, insn->src);
	if (width == X86_WIDTH_64) {
		x86_read_ptr_reg(state, insn->dst, &dst_ptr, &dst_tag);
		x86_read_ptr_reg(state, insn->src, &src_ptr, &src_tag);
		dst_off = x86_read_ptr_off_reg(state, insn->dst);
		src_off = x86_read_ptr_off_reg(state, insn->src);
	}
	x86_write_reg_width(state, insn->dst, src_value, width);
	x86_write_reg_width(state, insn->src, dst_value, width);
	if (width == X86_WIDTH_64 && src_tag != X86_PTR_NONE)
		x86_write_ptr_reg_off(state, insn->dst, src_ptr, src_tag,
				      src_off);
	if (width == X86_WIDTH_64 && dst_tag != X86_PTR_NONE)
		x86_write_ptr_reg_off(state, insn->src, dst_ptr, dst_tag,
				      dst_off);
	return X86_SIM_CONTINUE;
}

static __always_inline int x86_exec_div(struct x86_state *state,
					const struct x86_insn *insn,
					void *data, void *data_end)
{
	__u8 width = insn->flags ? insn->flags : X86_WIDTH_64;
	__u64 divisor = 0;
	__u64 rax = 0;
	__u64 rdx = 0;

	divisor = x86_read_reg(state, insn->src);
	rax = x86_read_reg(state, X86_RAX);
	rdx = x86_read_reg(state, X86_RDX);
	if (width == X86_WIDTH_8) {
		__u32 dividend = (__u16)rax;
		__u8 quotient = dividend / (__u8)divisor;
		__u8 remainder = dividend % (__u8)divisor;

		return x86_write_reg_width(state, X86_RAX,
					   ((__u16)remainder << 8) | quotient,
					   X86_WIDTH_16);
	}
	if (width == X86_WIDTH_16) {
		__u32 dividend = ((__u32)(__u16)rdx << 16) | (__u16)rax;
		__u16 quotient = dividend / (__u16)divisor;
		__u16 remainder = dividend % (__u16)divisor;

		x86_write_reg_width(state, X86_RAX, quotient, X86_WIDTH_16);
		return x86_write_reg_width(state, X86_RDX, remainder,
					   X86_WIDTH_16);
	}
	if (width == X86_WIDTH_32) {
		__u64 dividend;
		__u64 quotient;
		__u64 remainder;

		divisor = (__u32)divisor;
		dividend = ((__u64)(__u32)rdx << 32) | (__u32)rax;
		quotient = dividend / divisor;
		remainder = dividend % divisor;
		x86_write_reg_width(state, X86_RAX, quotient, X86_WIDTH_32);
		return x86_write_reg_width(state, X86_RDX, remainder,
					   X86_WIDTH_32);
	}
	{
		unsigned __int128 dividend =
			((unsigned __int128)rdx << 64) | rax;
		__u64 quotient = dividend / divisor;
		__u64 remainder = dividend % divisor;

		x86_write_reg_width(state, X86_RAX, quotient, X86_WIDTH_64);
		return x86_write_reg_width(state, X86_RDX, remainder,
					   X86_WIDTH_64);
	}
}

static __always_inline int x86_exec_shld_imm(struct x86_state *state,
					     const struct x86_insn *insn,
					     void *data, void *data_end)
{
	__u8 width = insn->flags ? insn->flags : X86_WIDTH_64;
	__u64 dst_value = 0;
	__u64 src_value = 0;
	__u64 result = 0;

	dst_value = x86_read_reg(state, insn->dst);
	src_value = x86_read_reg(state, insn->src);
	if (x86_shift_count(insn->imm, width) == 0)
		return X86_SIM_CONTINUE;
	result = x86_shld(dst_value, src_value, insn->imm, width);
	x86_set_shld_flags(state, dst_value, result, insn->imm, width);
	return x86_write_reg_width(state, insn->dst, result, width);
}

static __always_inline int x86_exec_shrd_imm(struct x86_state *state,
					     const struct x86_insn *insn,
					     void *data, void *data_end)
{
	__u8 width = insn->flags ? insn->flags : X86_WIDTH_64;
	__u64 dst_value = 0;
	__u64 src_value = 0;
	__u64 result = 0;

	dst_value = x86_read_reg(state, insn->dst);
	src_value = x86_read_reg(state, insn->src);
	if (x86_shift_count(insn->imm, width) == 0)
		return X86_SIM_CONTINUE;
	result = x86_shrd(dst_value, src_value, insn->imm, width);
	x86_set_shrd_flags(state, dst_value, result, insn->imm, width);
	return x86_write_reg_width(state, insn->dst, result, width);
}

static __always_inline int x86_exec_push(struct x86_state *state,
					 const struct x86_insn *insn,
					 void *data, void *data_end)
{
#ifdef X86_SIM_ENABLE_STACK
	return x86_push_reg(state, insn->src);
#else
	__builtin_unreachable();
#endif
}

static __always_inline int x86_exec_pop(struct x86_state *state,
					const struct x86_insn *insn,
					void *data, void *data_end)
{
	__u8 width = insn->flags ? insn->flags : X86_WIDTH_64;

#ifdef X86_SIM_ENABLE_STACK
	return x86_pop_reg(state, insn->dst, width);
#else
	__builtin_unreachable();
#endif
}

#endif
