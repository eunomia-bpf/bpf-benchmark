#include "x86_vm_bpf.h"

__noinline int x86_tmpl_init_state(struct x86_state *state, void *ctx)
{
	state->p_rdi = (void *)(long)X86_PTR_CTX;
	state->tag_rdi = X86_PTR_CTX;
	return X86_INTERP_CONTINUE;
}

#define X86_TMPL_WRAP(NAME)                                                \
	__noinline int x86_tmpl_##NAME(struct x86_state *state,             \
				       const struct x86_insn *insn,        \
				       void *data, void *data_end)          \
	{                                                                  \
		return x86_exec_##NAME(state, insn, data, data_end);        \
	}

X86_TMPL_WRAP(jmp)
X86_TMPL_WRAP(call)

#define X86_LINK_MAX_PACKET_OFF 65535ULL
#define x86_link_barrier_var(VAR) asm volatile("" : "+r"(VAR))

static __always_inline __u8 x86_arg_op(__u64 packed)
{
	return packed;
}

static __always_inline __u8 x86_arg_dst(__u64 packed)
{
	return packed >> 8;
}

static __always_inline __u8 x86_arg_src(__u64 packed)
{
	return packed >> 16;
}

static __always_inline __u8 x86_arg_flags(__u64 packed)
{
	return packed >> 24;
}

static __always_inline __u32 x86_arg_aux(__u64 packed)
{
	return packed >> 32;
}

static __always_inline __u8 x86_link_read_tag(const struct x86_state *state,
					      __u8 reg)
{
	switch (reg) {
	case X86_RAX:
		return (__u64)state->p_rax;
	case X86_RCX:
		return (__u64)state->p_rcx;
	case X86_RDX:
		return (__u64)state->p_rdx;
	case X86_RBX:
		return (__u64)state->p_rbx;
	case X86_RSP:
		return (__u64)state->p_rsp;
	case X86_RBP:
		return (__u64)state->p_rbp;
	case X86_RSI:
		return (__u64)state->p_rsi;
	case X86_RDI:
		return (__u64)state->p_rdi;
	case X86_R8:
		return (__u64)state->p_r8;
	case X86_R9:
		return (__u64)state->p_r9;
	case X86_R10:
		return (__u64)state->p_r10;
	case X86_R11:
		return (__u64)state->p_r11;
	case X86_R12:
		return (__u64)state->p_r12;
	case X86_R13:
		return (__u64)state->p_r13;
	case X86_R14:
		return (__u64)state->p_r14;
	case X86_R15:
		return (__u64)state->p_r15;
	default:
		return X86_PTR_NONE;
	}
}

static __always_inline int x86_link_write_tag(struct x86_state *state,
					      __u8 reg, __u8 tag)
{
	switch (reg) {
	case X86_RAX:
		state->p_rax = (void *)(long)tag;
		state->tag_rax = tag;
		return 0;
	case X86_RCX:
		state->p_rcx = (void *)(long)tag;
		state->tag_rcx = tag;
		return 0;
	case X86_RDX:
		state->p_rdx = (void *)(long)tag;
		state->tag_rdx = tag;
		return 0;
	case X86_RBX:
		state->p_rbx = (void *)(long)tag;
		state->tag_rbx = tag;
		return 0;
	case X86_RSP:
		state->p_rsp = (void *)(long)tag;
		state->tag_rsp = tag;
		return 0;
	case X86_RBP:
		state->p_rbp = (void *)(long)tag;
		state->tag_rbp = tag;
		return 0;
	case X86_RSI:
		state->p_rsi = (void *)(long)tag;
		state->tag_rsi = tag;
		return 0;
	case X86_RDI:
		state->p_rdi = (void *)(long)tag;
		state->tag_rdi = tag;
		return 0;
	case X86_R8:
		state->p_r8 = (void *)(long)tag;
		state->tag_r8 = tag;
		return 0;
	case X86_R9:
		state->p_r9 = (void *)(long)tag;
		state->tag_r9 = tag;
		return 0;
	case X86_R10:
		state->p_r10 = (void *)(long)tag;
		state->tag_r10 = tag;
		return 0;
	case X86_R11:
		state->p_r11 = (void *)(long)tag;
		state->tag_r11 = tag;
		return 0;
	case X86_R12:
		state->p_r12 = (void *)(long)tag;
		state->tag_r12 = tag;
		return 0;
	case X86_R13:
		state->p_r13 = (void *)(long)tag;
		state->tag_r13 = tag;
		return 0;
	case X86_R14:
		state->p_r14 = (void *)(long)tag;
		state->tag_r14 = tag;
		return 0;
	case X86_R15:
		state->p_r15 = (void *)(long)tag;
		state->tag_r15 = tag;
		return 0;
	default:
		return X86_INTERP_TRAP;
	}
}

static __always_inline int x86_link_clear_tag(struct x86_state *state,
					      __u8 reg)
{
	return x86_link_write_tag(state, reg, X86_PTR_NONE);
}

static __always_inline int x86_link_write_scalar(struct x86_state *state,
						 __u8 reg, __u64 value,
						 __u8 width)
{
	if (x86_write_reg_width(state, reg, value, width) < 0)
		return X86_INTERP_TRAP;
	return x86_link_clear_tag(state, reg);
}

static __always_inline int x86_link_check_width(__u8 width)
{
	if (width == X86_WIDTH_8 || width == X86_WIDTH_16 ||
	    width == X86_WIDTH_32 || width == X86_WIDTH_64)
		return 0;
	return X86_INTERP_TRAP;
}

static __always_inline int x86_link_packet_addr_const(void *data,
						      void *data_end,
						      __u64 offset,
						      __s64 disp,
						      __u8 width,
						      __u8 **out)
{
	__u64 final = offset;
	__u8 *addr;

	if (disp < 0) {
		__u64 abs = (__u64)-disp;

		if (offset < abs)
			return X86_INTERP_TRAP;
		final = offset - abs;
	} else {
		final = offset + (__u64)disp;
		if (final < offset)
			return X86_INTERP_TRAP;
	}
	if (final > X86_LINK_MAX_PACKET_OFF)
		return X86_INTERP_TRAP;
	addr = (__u8 *)data + final;
	if (width == X86_WIDTH_8) {
		if (addr + 1 > (__u8 *)data_end)
			return X86_INTERP_TRAP;
	} else if (width == X86_WIDTH_16) {
		if (addr + 2 > (__u8 *)data_end)
			return X86_INTERP_TRAP;
	} else if (width == X86_WIDTH_32) {
		if (addr + 4 > (__u8 *)data_end)
			return X86_INTERP_TRAP;
	} else if (width == X86_WIDTH_64) {
		if (addr + 8 > (__u8 *)data_end)
			return X86_INTERP_TRAP;
	} else {
		return X86_INTERP_TRAP;
	}
	*out = addr;
	return 0;
}

static __always_inline int x86_link_packet_addr(void *data, void *data_end,
						__u64 offset, __s64 disp,
						__u8 width, __u8 **out)
{
	if (width == X86_WIDTH_8)
		return x86_link_packet_addr_const(data, data_end, offset, disp,
						  X86_WIDTH_8, out);
	if (width == X86_WIDTH_16)
		return x86_link_packet_addr_const(data, data_end, offset, disp,
						  X86_WIDTH_16, out);
	if (width == X86_WIDTH_32)
		return x86_link_packet_addr_const(data, data_end, offset, disp,
						  X86_WIDTH_32, out);
	if (width == X86_WIDTH_64)
		return x86_link_packet_addr_const(data, data_end, offset, disp,
						  X86_WIDTH_64, out);
	return X86_INTERP_TRAP;
}

static __always_inline int x86_link_packet_end_const(void *data,
						     void *data_end,
						     __u64 offset,
						     __s64 disp,
						     __u8 width,
						     __u8 **out)
{
	__u8 *addr;

	if (x86_link_packet_addr_const(data, data_end, offset, disp, width,
				       &addr) < 0)
		return X86_INTERP_TRAP;
	*out = addr + width;
	return 0;
}

static __always_inline int x86_link_packet_end(void *data, void *data_end,
					       __u64 offset, __s64 disp,
					       __u8 width, __u8 **out)
{
	if (width == X86_WIDTH_8)
		return x86_link_packet_end_const(data, data_end, offset, disp,
						 X86_WIDTH_8, out);
	if (width == X86_WIDTH_16)
		return x86_link_packet_end_const(data, data_end, offset, disp,
						 X86_WIDTH_16, out);
	if (width == X86_WIDTH_32)
		return x86_link_packet_end_const(data, data_end, offset, disp,
						 X86_WIDTH_32, out);
	if (width == X86_WIDTH_64)
		return x86_link_packet_end_const(data, data_end, offset, disp,
						 X86_WIDTH_64, out);
	return X86_INTERP_TRAP;
}

static __always_inline int x86_link_packet_ptr(void *data, void *data_end,
					       __u64 offset, __u8 **out)
{
	__u8 *addr;

	if (offset > X86_LINK_MAX_PACKET_OFF)
		return X86_INTERP_TRAP;
	addr = (__u8 *)data + offset;
	*out = addr;
	return 0;
}

static __always_inline int x86_link_read_packet(void *data, void *data_end,
						__u64 base, __s64 disp,
						__u8 width, __u64 *value)
{
	__u8 *end;

	if (width == X86_WIDTH_8) {
		if (x86_link_packet_end_const(data, data_end, base, disp,
					      X86_WIDTH_8, &end) < 0)
			return X86_INTERP_TRAP;
		x86_link_barrier_var(end);
		*value = *(__u8 *)(end - 1);
		return X86_INTERP_CONTINUE;
	}
	if (width == X86_WIDTH_16) {
		if (x86_link_packet_end_const(data, data_end, base, disp,
					      X86_WIDTH_16, &end) < 0)
			return X86_INTERP_TRAP;
		x86_link_barrier_var(end);
		*value = *(__u16 *)(end - 2);
		return X86_INTERP_CONTINUE;
	}
	if (width == X86_WIDTH_32) {
		if (x86_link_packet_end_const(data, data_end, base, disp,
					      X86_WIDTH_32, &end) < 0)
			return X86_INTERP_TRAP;
		x86_link_barrier_var(end);
		*value = *(__u32 *)(end - 4);
		return X86_INTERP_CONTINUE;
	}
	if (width == X86_WIDTH_64) {
		if (x86_link_packet_end_const(data, data_end, base, disp,
					      X86_WIDTH_64, &end) < 0)
			return X86_INTERP_TRAP;
		x86_link_barrier_var(end);
		*value = *(__u64 *)(end - 8);
		return X86_INTERP_CONTINUE;
	}
	return X86_INTERP_TRAP;
}

static __always_inline int x86_link_store_packet(void *data, void *data_end,
						 __u64 base, __s64 disp,
						 __u8 width, __u64 value)
{
	__u8 *end;

	if (width == X86_WIDTH_8) {
		if (x86_link_packet_end_const(data, data_end, base, disp,
					      X86_WIDTH_8, &end) < 0)
			return X86_INTERP_TRAP;
		x86_link_barrier_var(end);
		*(__u8 *)(end - 1) = value;
		return X86_INTERP_CONTINUE;
	}
	if (width == X86_WIDTH_16) {
		if (x86_link_packet_end_const(data, data_end, base, disp,
					      X86_WIDTH_16, &end) < 0)
			return X86_INTERP_TRAP;
		x86_link_barrier_var(end);
		*(__u16 *)(end - 2) = value;
		return X86_INTERP_CONTINUE;
	}
	if (width == X86_WIDTH_32) {
		if (x86_link_packet_end_const(data, data_end, base, disp,
					      X86_WIDTH_32, &end) < 0)
			return X86_INTERP_TRAP;
		x86_link_barrier_var(end);
		*(__u32 *)(end - 4) = value;
		return X86_INTERP_CONTINUE;
	}
	if (width == X86_WIDTH_64) {
		if (x86_link_packet_end_const(data, data_end, base, disp,
					      X86_WIDTH_64, &end) < 0)
			return X86_INTERP_TRAP;
		x86_link_barrier_var(end);
		*(__u64 *)(end - 8) = value;
		return X86_INTERP_CONTINUE;
	}
	return X86_INTERP_TRAP;
}

static __always_inline void x86_link_set_cmp_flags(struct x86_state *state,
						   __u64 lhs, __u64 rhs,
						   __u8 width)
{
	x86_set_sub_flags(state, lhs, rhs, lhs - rhs, width);
}

static __always_inline int x86_link_set_packet_end_cmp_flags(
	struct x86_state *state, void *data, void *data_end, __u64 offset,
	__u8 packet_on_lhs)
{
	__u8 *addr;

	if (x86_link_packet_ptr(data, data_end, offset, &addr) < 0)
		return X86_INTERP_TRAP;
	if (packet_on_lhs) {
		state->cf = addr < (__u8 *)data_end;
		state->zf = addr == (__u8 *)data_end;
	} else {
		state->cf = (__u8 *)data_end < addr;
		state->zf = data_end == addr;
	}
	state->sf = 0;
	state->of = 0;
	return X86_INTERP_CONTINUE;
}

__noinline int x86_tmpl_mov_reg(struct x86_state *state,
				const struct x86_insn *insn,
				void *data, void *data_end)
{
	__u64 value = 0;
	__u8 tag = x86_link_read_tag(state, insn->src);

	if (x86_read_reg(state, insn->src, &value) < 0)
		return X86_INTERP_TRAP;
	if (x86_write_reg_width(state, insn->dst, value,
				insn->flags ? insn->flags : X86_WIDTH_64) < 0)
		return X86_INTERP_TRAP;
	if (insn->flags == X86_WIDTH_64)
		return x86_link_write_tag(state, insn->dst, tag);
	return X86_INTERP_CONTINUE;
}

__noinline int x86_tmpl_nop(struct x86_state *state,
			    const struct x86_insn *insn,
			    void *data, void *data_end)
{
	return X86_INTERP_CONTINUE;
}

__noinline int x86_tmpl_mov_imm(struct x86_state *state,
				const struct x86_insn *insn,
				void *data, void *data_end)
{
	__u8 width = insn->flags ? insn->flags : X86_WIDTH_64;

	if (x86_link_check_width(width) < 0)
		return X86_INTERP_TRAP;
	return x86_link_write_scalar(state, insn->dst, insn->imm, width);
}

__noinline int x86_tmpl_movzx_reg(struct x86_state *state,
				  const struct x86_insn *insn,
				  void *data, void *data_end)
{
	__u8 width = insn->flags ? insn->flags : X86_WIDTH_64;
	__u8 src_width = insn->aux ? insn->aux : width;
	__u64 value = 0;

	if (x86_link_check_width(width) < 0 ||
	    x86_link_check_width(src_width) < 0)
		return X86_INTERP_TRAP;
	if (x86_read_reg(state, insn->src, &value) < 0)
		return X86_INTERP_TRAP;
	return x86_link_write_scalar(state, insn->dst,
				     x86_apply_width(value, src_width),
				     width);
}

__noinline int x86_tmpl_movsx_reg(struct x86_state *state,
				  const struct x86_insn *insn,
				  void *data, void *data_end)
{
	__u8 width = insn->flags ? insn->flags : X86_WIDTH_64;
	__u8 src_width = insn->aux ? insn->aux : width;
	__u64 value = 0;

	if (x86_link_check_width(width) < 0 ||
	    x86_link_check_width(src_width) < 0)
		return X86_INTERP_TRAP;
	if (x86_read_reg(state, insn->src, &value) < 0)
		return X86_INTERP_TRAP;
	return x86_link_write_scalar(state, insn->dst,
				     x86_sign_extend(value, src_width),
				     width);
}

__noinline int x86_tmpl_mov_load(struct x86_state *state,
				 const struct x86_insn *insn,
				 void *data, void *data_end)
{
	__u8 base_tag = x86_link_read_tag(state, insn->src);
	__u8 width = insn->flags ? insn->flags : X86_WIDTH_64;
	__u64 base = 0;
	__u8 *end;
	__u64 value = 0;

	if (base_tag == X86_PTR_CTX) {
		if (insn->imm == 0) {
			if (x86_write_reg_width(state, insn->dst, 0,
						X86_WIDTH_64) < 0)
				return X86_INTERP_TRAP;
			return x86_link_write_tag(state, insn->dst,
						  X86_PTR_PACKET);
		}
		if (insn->imm == 8) {
			if (x86_write_reg_width(state, insn->dst, 0,
						X86_WIDTH_64) < 0)
				return X86_INTERP_TRAP;
			return x86_link_write_tag(state, insn->dst,
						  X86_PTR_PACKET_END);
		}
		return X86_INTERP_TRAP;
	}
	if (base_tag != X86_PTR_PACKET && base_tag != X86_PTR_PACKET_END)
		return X86_INTERP_TRAP;
	if (x86_read_reg(state, insn->src, &base) < 0)
		return X86_INTERP_TRAP;
	if (width == X86_WIDTH_8) {
		if (x86_link_packet_end_const(data, data_end, base,
					      x86_simm(insn->imm),
					      X86_WIDTH_8, &end) < 0)
			return X86_INTERP_TRAP;
		x86_link_barrier_var(end);
		value = *(__u8 *)(end - 1);
	} else if (width == X86_WIDTH_16) {
		if (x86_link_packet_end_const(data, data_end, base,
					      x86_simm(insn->imm),
					      X86_WIDTH_16, &end) < 0)
			return X86_INTERP_TRAP;
		x86_link_barrier_var(end);
		value = *(__u16 *)(end - 2);
	} else if (width == X86_WIDTH_32) {
		if (x86_link_packet_end_const(data, data_end, base,
					      x86_simm(insn->imm),
					      X86_WIDTH_32, &end) < 0)
			return X86_INTERP_TRAP;
		x86_link_barrier_var(end);
		value = *(__u32 *)(end - 4);
	} else if (width == X86_WIDTH_64) {
		if (x86_link_packet_end_const(data, data_end, base,
					      x86_simm(insn->imm),
					      X86_WIDTH_64, &end) < 0)
			return X86_INTERP_TRAP;
		x86_link_barrier_var(end);
		value = *(__u64 *)(end - 8);
	} else {
		return X86_INTERP_TRAP;
	}
	return x86_write_reg_width(state, insn->dst, value, width);
}

__noinline int x86_tmpl_movsx_load(struct x86_state *state,
				   const struct x86_insn *insn,
				   void *data, void *data_end)
{
	__u8 base_tag = x86_link_read_tag(state, insn->src);
	__u8 write_width = insn->flags ? insn->flags : X86_WIDTH_64;
	__u8 load_width = X86_MEM_AUX_MEM_WIDTH(insn->aux);
	__s64 disp = x86_simm(insn->imm);
	__u64 base = 0;
	__u64 value = 0;

	if (load_width == 0)
		load_width = write_width;
	if (base_tag != X86_PTR_PACKET)
		return X86_INTERP_TRAP;
	if (x86_read_reg(state, insn->src, &base) < 0)
		return X86_INTERP_TRAP;
	if (x86_mem_offset(state, insn->aux, disp, &disp) < 0)
		return X86_INTERP_TRAP;
	if (x86_link_read_packet(data, data_end, base, disp, load_width,
				 &value) < 0)
		return X86_INTERP_TRAP;
	value = x86_sign_extend(value, load_width);
	return x86_link_write_scalar(state, insn->dst, value, write_width);
}

__noinline int x86_tmpl_lea(struct x86_state *state,
			    const struct x86_insn *insn,
			    void *data, void *data_end)
{
	__u64 base = 0;
	__s64 offset = 0;
	__u8 tag = x86_link_read_tag(state, insn->src);

	if (insn->src != X86_REG_NONE && x86_read_reg(state, insn->src, &base) < 0)
		return X86_INTERP_TRAP;
	if (x86_mem_offset(state, insn->aux, x86_simm(insn->imm), &offset) < 0)
		return X86_INTERP_TRAP;
	if (x86_write_reg_width(state, insn->dst, base + offset,
				insn->flags ? insn->flags : X86_WIDTH_64) < 0)
		return X86_INTERP_TRAP;
	if (tag == X86_PTR_PACKET || tag == X86_PTR_PACKET_END)
		return x86_link_write_tag(state, insn->dst, tag);
	return X86_INTERP_CONTINUE;
}

__noinline int x86_tmpl_alu_imm(struct x86_state *state,
				const struct x86_insn *insn,
				void *data, void *data_end)
{
	__u8 width = insn->flags ? insn->flags : X86_WIDTH_64;
	__u8 tag = x86_link_read_tag(state, insn->dst);
	__u64 lhs = 0;
	__u64 rhs = insn->imm;
	__u64 result;

	if (x86_link_check_width(width) < 0)
		return X86_INTERP_TRAP;
	if (x86_read_reg(state, insn->dst, &lhs) < 0)
		return X86_INTERP_TRAP;
	if (insn->aux == X86_ALU_SBB)
		rhs += state->cf;
	result = x86_alu_result(lhs, rhs, insn->aux, width);
	x86_set_alu_flags(state, lhs, rhs, result, insn->aux, width);
	if (x86_write_reg_width(state, insn->dst, result, width) < 0)
		return X86_INTERP_TRAP;
	if (width == X86_WIDTH_64 &&
	    (tag == X86_PTR_PACKET || tag == X86_PTR_PACKET_END) &&
	    (insn->aux == X86_ALU_ADD || insn->aux == X86_ALU_SUB))
		return x86_link_write_tag(state, insn->dst, tag);
	return x86_link_clear_tag(state, insn->dst);
}

__noinline int x86_tmpl_add_imm(struct x86_state *state,
				const struct x86_insn *insn,
				void *data, void *data_end)
{
	return x86_tmpl_alu_imm(state, insn, data, data_end);
}

__noinline int x86_tmpl_alu_reg(struct x86_state *state,
				const struct x86_insn *insn,
				void *data, void *data_end)
{
	__u8 width = insn->flags ? insn->flags : X86_WIDTH_64;
	__u8 dst_tag = x86_link_read_tag(state, insn->dst);
	__u8 src_tag = x86_link_read_tag(state, insn->src);
	__u64 lhs = 0;
	__u64 rhs = 0;
	__u64 result;
	__u8 result_tag = X86_PTR_NONE;

	if (x86_link_check_width(width) < 0)
		return X86_INTERP_TRAP;
	if (x86_read_reg(state, insn->dst, &lhs) < 0 ||
	    x86_read_reg(state, insn->src, &rhs) < 0)
		return X86_INTERP_TRAP;
	if (insn->aux == X86_ALU_SBB)
		rhs += state->cf;
	result = x86_alu_result(lhs, rhs, insn->aux, width);
	x86_set_alu_flags(state, lhs, rhs, result, insn->aux, width);
	if (width == X86_WIDTH_64 && insn->aux == X86_ALU_ADD &&
	    dst_tag == X86_PTR_NONE &&
	    (src_tag == X86_PTR_PACKET || src_tag == X86_PTR_PACKET_END))
		result_tag = src_tag;
	else if (width == X86_WIDTH_64 &&
		 (insn->aux == X86_ALU_ADD || insn->aux == X86_ALU_SUB) &&
		 (dst_tag == X86_PTR_PACKET || dst_tag == X86_PTR_PACKET_END))
		result_tag = dst_tag;
	if (x86_write_reg_width(state, insn->dst, result, width) < 0)
		return X86_INTERP_TRAP;
	return x86_link_write_tag(state, insn->dst, result_tag);
}

__noinline int x86_tmpl_add_reg(struct x86_state *state,
				const struct x86_insn *insn,
				void *data, void *data_end)
{
	return x86_tmpl_alu_reg(state, insn, data, data_end);
}

__noinline int x86_tmpl_xor_reg(struct x86_state *state,
				const struct x86_insn *insn,
				void *data, void *data_end)
{
	return x86_tmpl_alu_reg(state, insn, data, data_end);
}

__noinline int x86_tmpl_cmp_imm(struct x86_state *state,
				const struct x86_insn *insn,
				void *data, void *data_end)
{
	__u8 width = insn->flags ? insn->flags : X86_WIDTH_64;
	__u64 lhs = 0;

	if (x86_link_check_width(width) < 0)
		return X86_INTERP_TRAP;
	if (x86_read_reg(state, insn->dst, &lhs) < 0)
		return X86_INTERP_TRAP;
	x86_link_set_cmp_flags(state, lhs, insn->imm, width);
	return X86_INTERP_CONTINUE;
}

__noinline int x86_tmpl_cmp_reg(struct x86_state *state,
				const struct x86_insn *insn,
				void *data, void *data_end)
{
	__u8 width = insn->flags ? insn->flags : X86_WIDTH_64;
	__u8 dst_tag = x86_link_read_tag(state, insn->dst);
	__u8 src_tag = x86_link_read_tag(state, insn->src);
	__u64 lhs = 0;
	__u64 rhs = 0;

	if (x86_link_check_width(width) < 0)
		return X86_INTERP_TRAP;
	if (x86_read_reg(state, insn->dst, &lhs) < 0 ||
	    x86_read_reg(state, insn->src, &rhs) < 0)
		return X86_INTERP_TRAP;
	if (width == X86_WIDTH_64 && dst_tag == X86_PTR_PACKET &&
	    src_tag == X86_PTR_PACKET_END)
		return x86_link_set_packet_end_cmp_flags(state, data, data_end,
							 lhs, 1);
	if (width == X86_WIDTH_64 && dst_tag == X86_PTR_PACKET_END &&
	    src_tag == X86_PTR_PACKET)
		return x86_link_set_packet_end_cmp_flags(state, data, data_end,
							 rhs, 0);
	if (width == X86_WIDTH_64 && dst_tag == X86_PTR_PACKET &&
	    src_tag == X86_PTR_PACKET) {
		x86_link_set_cmp_flags(state, lhs, rhs, width);
		return X86_INTERP_CONTINUE;
	}
	if (width == X86_WIDTH_64 && dst_tag == X86_PTR_PACKET_END &&
	    src_tag == X86_PTR_PACKET_END) {
		x86_link_set_cmp_flags(state, 0, 0, width);
		return X86_INTERP_CONTINUE;
	}
	x86_link_set_cmp_flags(state, lhs, rhs, width);
	return X86_INTERP_CONTINUE;
}

__noinline int x86_tmpl_test_imm(struct x86_state *state,
				 const struct x86_insn *insn,
				 void *data, void *data_end)
{
	__u8 width = insn->flags ? insn->flags : X86_WIDTH_64;
	__u64 lhs = 0;

	if (x86_link_check_width(width) < 0)
		return X86_INTERP_TRAP;
	if (x86_read_reg(state, insn->dst, &lhs) < 0)
		return X86_INTERP_TRAP;
	x86_set_logic_flags(state, lhs & insn->imm, width);
	return X86_INTERP_CONTINUE;
}

__noinline int x86_tmpl_test_reg(struct x86_state *state,
				 const struct x86_insn *insn,
				 void *data, void *data_end)
{
	__u8 width = insn->flags ? insn->flags : X86_WIDTH_64;
	__u64 lhs = 0;
	__u64 rhs = 0;

	if (x86_link_check_width(width) < 0)
		return X86_INTERP_TRAP;
	if (x86_read_reg(state, insn->dst, &lhs) < 0 ||
	    x86_read_reg(state, insn->src, &rhs) < 0)
		return X86_INTERP_TRAP;
	x86_set_logic_flags(state, lhs & rhs, width);
	return X86_INTERP_CONTINUE;
}

__noinline int x86_tmpl_alu_mem(struct x86_state *state,
				const struct x86_insn *insn,
				void *data, void *data_end)
{
	__u8 width = insn->flags ? insn->flags : X86_WIDTH_64;
	__u8 alu = X86_MEM_AUX_GET_ALU_OP(insn->aux);
	__u8 base_tag = x86_link_read_tag(state, insn->src);
	__u64 dst_value = 0;
	__u64 mem_value = 0;
	__u64 base = 0;
	__u64 result = 0;
	__s64 disp = x86_simm(insn->imm);

	if (base_tag != X86_PTR_PACKET)
		return X86_INTERP_TRAP;
	if (x86_read_reg(state, insn->dst, &dst_value) < 0 ||
	    x86_read_reg(state, insn->src, &base) < 0)
		return X86_INTERP_TRAP;
	if (x86_mem_offset(state, insn->aux, disp, &disp) < 0)
		return X86_INTERP_TRAP;
	if (x86_link_read_packet(data, data_end, base, disp, width,
				 &mem_value) < 0)
		return X86_INTERP_TRAP;
	if (alu == X86_ALU_SBB)
		mem_value += state->cf;
	result = x86_alu_result(dst_value, mem_value, alu, width);
	x86_set_alu_flags(state, dst_value, mem_value, result, alu, width);
	return x86_link_write_scalar(state, insn->dst, result, width);
}

__noinline int x86_tmpl_mov_store_imm(struct x86_state *state,
				      const struct x86_insn *insn,
				      void *data, void *data_end)
{
	__u8 base_tag = x86_link_read_tag(state, insn->dst);
	__u64 base = 0;
	__u32 value = x86_store_imm_value(insn->imm);
	__u8 *end;

	if (base_tag != X86_PTR_PACKET)
		return X86_INTERP_TRAP;
	if (x86_read_reg(state, insn->dst, &base) < 0)
		return X86_INTERP_TRAP;
	if (insn->flags == X86_WIDTH_8) {
		if (x86_link_packet_end_const(data, data_end, base,
					      x86_store_imm_disp(insn->imm),
					      X86_WIDTH_8, &end) < 0)
			return X86_INTERP_TRAP;
		x86_link_barrier_var(end);
		*(__u8 *)(end - 1) = value;
	} else if (insn->flags == X86_WIDTH_16) {
		if (x86_link_packet_end_const(data, data_end, base,
					      x86_store_imm_disp(insn->imm),
					      X86_WIDTH_16, &end) < 0)
			return X86_INTERP_TRAP;
		x86_link_barrier_var(end);
		*(__u16 *)(end - 2) = value;
	} else if (insn->flags == X86_WIDTH_32) {
		if (x86_link_packet_end_const(data, data_end, base,
					      x86_store_imm_disp(insn->imm),
					      X86_WIDTH_32, &end) < 0)
			return X86_INTERP_TRAP;
		x86_link_barrier_var(end);
		*(__u32 *)(end - 4) = value;
	} else if (insn->flags == X86_WIDTH_64) {
		if (x86_link_packet_end_const(data, data_end, base,
					      x86_store_imm_disp(insn->imm),
					      X86_WIDTH_64, &end) < 0)
			return X86_INTERP_TRAP;
		x86_link_barrier_var(end);
		*(__u64 *)(end - 8) = value;
	} else {
		return X86_INTERP_TRAP;
	}
	return X86_INTERP_CONTINUE;
}

__noinline int x86_tmpl_mov_store_reg(struct x86_state *state,
				      const struct x86_insn *insn,
				      void *data, void *data_end)
{
	__u8 base_tag = x86_link_read_tag(state, insn->dst);
	__u64 base = 0;
	__u64 value = 0;
	__s64 disp = x86_simm(insn->imm);
	__u8 src_shift = X86_REG_AUX_GET_SRC_SHIFT(insn->aux);

	if (base_tag != X86_PTR_PACKET)
		return X86_INTERP_TRAP;
	if (x86_read_reg(state, insn->dst, &base) < 0 ||
	    x86_read_reg(state, insn->src, &value) < 0)
		return X86_INTERP_TRAP;
	if (src_shift != 0)
		value >>= src_shift;
	if (x86_mem_offset(state, insn->aux, disp, &disp) < 0)
		return X86_INTERP_TRAP;
	return x86_link_store_packet(data, data_end, base, disp,
				     insn->flags, value);
}

static __always_inline int x86_link_cmp_mem(struct x86_state *state,
					    const struct x86_insn *insn,
					    void *data, void *data_end)
{
	__u8 base_tag = x86_link_read_tag(state, insn->dst);
	__s64 disp = insn->op == X86_OP_CMP_MEM_REG ?
			     x86_simm(insn->imm) :
			     x86_store_imm_disp(insn->imm);
	__u64 base = 0;
	__u64 value = 0;
	__u64 rhs = x86_store_imm_value(insn->imm);

	if (base_tag != X86_PTR_PACKET)
		return X86_INTERP_TRAP;
	if (x86_read_reg(state, insn->dst, &base) < 0)
		return X86_INTERP_TRAP;
	if (x86_mem_offset(state, insn->aux, disp, &disp) < 0)
		return X86_INTERP_TRAP;
	if (x86_link_read_packet(data, data_end, base, disp, insn->flags,
				 &value) < 0)
		return X86_INTERP_TRAP;
	if (insn->op == X86_OP_CMP_MEM_REG &&
	    x86_read_reg(state, insn->src, &rhs) < 0)
		return X86_INTERP_TRAP;
	if (insn->op == X86_OP_TEST_MEM_IMM)
		x86_set_logic_flags(state, value & rhs, insn->flags);
	else
		x86_set_sub_flags(state, value, rhs, value - rhs,
				  insn->flags);
	return X86_INTERP_CONTINUE;
}

__noinline int x86_tmpl_cmp_mem_imm(struct x86_state *state,
				    const struct x86_insn *insn,
				    void *data, void *data_end)
{
	return x86_link_cmp_mem(state, insn, data, data_end);
}

__noinline int x86_tmpl_cmp_mem_reg(struct x86_state *state,
				    const struct x86_insn *insn,
				    void *data, void *data_end)
{
	return x86_link_cmp_mem(state, insn, data, data_end);
}

__noinline int x86_tmpl_test_mem_imm(struct x86_state *state,
				     const struct x86_insn *insn,
				     void *data, void *data_end)
{
	return x86_link_cmp_mem(state, insn, data, data_end);
}

__noinline int x86_tmpl_jcc(struct x86_state *state,
			    const struct x86_insn *insn,
			    void *data, void *data_end)
{
	return x86_eval_cc(state, insn->aux);
}

__noinline int x86_tmpl_cmov(struct x86_state *state,
			     const struct x86_insn *insn,
			     void *data, void *data_end)
{
	__u8 width = insn->flags ? insn->flags : X86_WIDTH_64;
	__u64 value = 0;
	__u8 tag;

	if (!x86_eval_cc(state, insn->aux))
		return X86_INTERP_CONTINUE;
	tag = x86_link_read_tag(state, insn->src);
	if (x86_link_check_width(width) < 0)
		return X86_INTERP_TRAP;
	if (x86_read_reg(state, insn->src, &value) < 0)
		return X86_INTERP_TRAP;
	if (x86_write_reg_width(state, insn->dst, value, width) < 0)
		return X86_INTERP_TRAP;
	if (width == X86_WIDTH_64)
		return x86_link_write_tag(state, insn->dst, tag);
	return x86_link_clear_tag(state, insn->dst);
}

__noinline int x86_tmpl_setcc(struct x86_state *state,
			      const struct x86_insn *insn,
			      void *data, void *data_end)
{
	return x86_link_write_scalar(state, insn->dst,
				     x86_eval_cc(state, insn->aux),
				     X86_WIDTH_8);
}

__noinline int x86_tmpl_bswap(struct x86_state *state,
			      const struct x86_insn *insn,
			      void *data, void *data_end)
{
	__u8 width = insn->flags ? insn->flags : X86_WIDTH_64;
	__u64 value = 0;

	if (width != X86_WIDTH_32 && width != X86_WIDTH_64)
		return X86_INTERP_TRAP;
	if (x86_read_reg(state, insn->dst, &value) < 0)
		return X86_INTERP_TRAP;
	return x86_link_write_scalar(state, insn->dst,
				     x86_bswap(value, width), width);
}

__noinline int x86_tmpl_popcnt(struct x86_state *state,
			       const struct x86_insn *insn,
			       void *data, void *data_end)
{
	__u8 width = insn->flags ? insn->flags : X86_WIDTH_64;
	__u64 value = 0;

	if (x86_link_check_width(width) < 0)
		return X86_INTERP_TRAP;
	if (x86_read_reg(state, insn->src, &value) < 0)
		return X86_INTERP_TRAP;
	return x86_link_write_scalar(state, insn->dst,
				     x86_popcount64(x86_apply_width(value, width)),
				     width);
}

__noinline int x86_tmpl_xchg(struct x86_state *state,
			     const struct x86_insn *insn,
			     void *data, void *data_end)
{
	__u8 width = insn->flags ? insn->flags : X86_WIDTH_64;
	__u64 dst_value = 0;
	__u64 src_value = 0;

	if (x86_link_check_width(width) < 0)
		return X86_INTERP_TRAP;
	if (x86_read_reg(state, insn->dst, &dst_value) < 0 ||
	    x86_read_reg(state, insn->src, &src_value) < 0)
		return X86_INTERP_TRAP;
	if (x86_link_write_scalar(state, insn->dst, src_value, width) < 0)
		return X86_INTERP_TRAP;
	return x86_link_write_scalar(state, insn->src, dst_value, width);
}

__noinline int x86_tmpl_div(struct x86_state *state,
			    const struct x86_insn *insn,
			    void *data, void *data_end)
{
	return x86_exec_div(state, insn, data, data_end);
}

__noinline int x86_tmpl_shld_imm(struct x86_state *state,
				 const struct x86_insn *insn,
				 void *data, void *data_end)
{
	__u8 width = insn->flags ? insn->flags : X86_WIDTH_64;
	__u64 dst_value = 0;
	__u64 src_value = 0;
	__u64 result = 0;

	if (x86_link_check_width(width) < 0)
		return X86_INTERP_TRAP;
	if (x86_read_reg(state, insn->dst, &dst_value) < 0 ||
	    x86_read_reg(state, insn->src, &src_value) < 0)
		return X86_INTERP_TRAP;
	result = x86_shld(dst_value, src_value, insn->imm, width);
	x86_set_logic_flags(state, result, width);
	return x86_link_write_scalar(state, insn->dst, result, width);
}

__noinline int x86_tmpl_shrd_imm(struct x86_state *state,
				 const struct x86_insn *insn,
				 void *data, void *data_end)
{
	__u8 width = insn->flags ? insn->flags : X86_WIDTH_64;
	__u64 dst_value = 0;
	__u64 src_value = 0;
	__u64 result = 0;

	if (x86_link_check_width(width) < 0)
		return X86_INTERP_TRAP;
	if (x86_read_reg(state, insn->dst, &dst_value) < 0 ||
	    x86_read_reg(state, insn->src, &src_value) < 0)
		return X86_INTERP_TRAP;
	result = x86_shrd(dst_value, src_value, insn->imm, width);
	x86_set_logic_flags(state, result, width);
	return x86_link_write_scalar(state, insn->dst, result, width);
}

__noinline int x86_tmpl_push(struct x86_state *state,
			     const struct x86_insn *insn,
			     void *data, void *data_end)
{
	return X86_INTERP_CONTINUE;
}

__noinline int x86_tmpl_pop(struct x86_state *state,
			    const struct x86_insn *insn,
			    void *data, void *data_end)
{
	return X86_INTERP_CONTINUE;
}

__noinline int x86_tmpl_ret(struct x86_state *state,
			    const struct x86_insn *insn,
			    void *data, void *data_end)
{
	return X86_INTERP_DONE;
}

static __always_inline int x86_link_read_reg_fast(const struct x86_state *state,
						  __u8 reg, __u64 *out)
{
	if (reg > X86_R15)
		return X86_INTERP_TRAP;
	*out = *((const __u64 *)state + reg);
	return 0;
}

static __always_inline int x86_link_write_reg_width_fast(
	struct x86_state *state, __u8 reg, __u64 value, __u8 width)
{
	__u64 old_value = 0;
	__u64 next_value = value;

	if (reg > X86_R15)
		return X86_INTERP_TRAP;
	if (width == X86_WIDTH_8 || width == X86_WIDTH_16) {
		old_value = *((__u64 *)state + reg);
		next_value = (old_value & ~x86_width_mask(width)) |
			     (value & x86_width_mask(width));
	} else if (width == X86_WIDTH_32) {
		next_value = (__u32)value;
	}
	*((__u64 *)state + reg) = next_value;
	*((__u64 *)&state->p_rax + reg) = X86_PTR_NONE;
	return 0;
}

static __always_inline __u8 x86_link_read_tag_fast(
	const struct x86_state *state, __u8 reg)
{
	if (reg > X86_R15)
		return X86_PTR_NONE;
	return *((const __u64 *)&state->p_rax + reg);
}

static __always_inline int x86_link_write_tag_fast(struct x86_state *state,
						   __u8 reg, __u8 tag)
{
	if (reg > X86_R15)
		return X86_INTERP_TRAP;
	*((__u64 *)&state->p_rax + reg) = tag;
	return X86_INTERP_CONTINUE;
}

static __always_inline int x86_link_clear_tag_fast(struct x86_state *state,
						   __u8 reg)
{
	return x86_link_write_tag_fast(state, reg, X86_PTR_NONE);
}

static __always_inline int x86_link_write_scalar_fast(struct x86_state *state,
						      __u8 reg, __u64 value,
						      __u8 width)
{
	if (x86_link_write_reg_width_fast(state, reg, value, width) < 0)
		return X86_INTERP_TRAP;
	return x86_link_clear_tag_fast(state, reg);
}

static __always_inline int x86_link_mem_offset_fast(struct x86_state *state,
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
	if (x86_link_read_reg_fast(state, index, &index_value) < 0)
		return X86_INTERP_TRAP;
	*out += (__s64)(index_value << scale_log2);
	return 0;
}

#define x86_read_reg x86_link_read_reg_fast
#define x86_write_reg_width x86_link_write_reg_width_fast
#define x86_link_read_tag x86_link_read_tag_fast
#define x86_link_write_tag x86_link_write_tag_fast
#define x86_link_clear_tag x86_link_clear_tag_fast
#define x86_link_write_scalar x86_link_write_scalar_fast
#define x86_mem_offset x86_link_mem_offset_fast

__noinline int x86_tmpl_arg_mov_imm(struct x86_state *state,
				    void *data, void *data_end,
				    __u64 packed, __u64 imm)
{
	__u8 width = x86_arg_flags(packed);

	if (!width)
		width = X86_WIDTH_64;
	if (x86_link_check_width(width) < 0)
		return X86_INTERP_TRAP;
	return x86_link_write_scalar(state, x86_arg_dst(packed), imm, width);
}

__noinline int x86_tmpl_arg_nop(struct x86_state *state,
				void *data, void *data_end,
				__u64 packed, __u64 imm)
{
	return X86_INTERP_CONTINUE;
}

__noinline int x86_tmpl_arg_mov_reg(struct x86_state *state,
				    void *data, void *data_end,
				    __u64 packed, __u64 imm)
{
	__u8 dst = x86_arg_dst(packed);
	__u8 src = x86_arg_src(packed);
	__u8 width = x86_arg_flags(packed);
	__u64 value = 0;
	__u8 tag = x86_link_read_tag(state, src);

	if (!width)
		width = X86_WIDTH_64;
	if (x86_read_reg(state, src, &value) < 0)
		return X86_INTERP_TRAP;
	if (x86_write_reg_width(state, dst, value, width) < 0)
		return X86_INTERP_TRAP;
	if (width == X86_WIDTH_64)
		return x86_link_write_tag(state, dst, tag);
	return X86_INTERP_CONTINUE;
}

__noinline int x86_tmpl_arg_movzx_reg(struct x86_state *state,
				      void *data, void *data_end,
				      __u64 packed, __u64 imm)
{
	__u8 dst = x86_arg_dst(packed);
	__u8 src = x86_arg_src(packed);
	__u8 width = x86_arg_flags(packed);
	__u8 src_width = x86_arg_aux(packed);
	__u64 value = 0;

	if (!width)
		width = X86_WIDTH_64;
	if (!src_width)
		src_width = width;
	if (x86_link_check_width(width) < 0 ||
	    x86_link_check_width(src_width) < 0)
		return X86_INTERP_TRAP;
	if (x86_read_reg(state, src, &value) < 0)
		return X86_INTERP_TRAP;
	return x86_link_write_scalar(state, dst,
				     x86_apply_width(value, src_width),
				     width);
}

__noinline int x86_tmpl_arg_movsx_reg(struct x86_state *state,
				      void *data, void *data_end,
				      __u64 packed, __u64 imm)
{
	__u8 dst = x86_arg_dst(packed);
	__u8 src = x86_arg_src(packed);
	__u8 width = x86_arg_flags(packed);
	__u8 src_width = x86_arg_aux(packed);
	__u64 value = 0;

	if (!width)
		width = X86_WIDTH_64;
	if (!src_width)
		src_width = width;
	if (x86_link_check_width(width) < 0 ||
	    x86_link_check_width(src_width) < 0)
		return X86_INTERP_TRAP;
	if (x86_read_reg(state, src, &value) < 0)
		return X86_INTERP_TRAP;
	return x86_link_write_scalar(state, dst,
				     x86_sign_extend(value, src_width),
				     width);
}

__noinline int x86_tmpl_arg_mov_load(struct x86_state *state,
				     void *data, void *data_end,
				     __u64 packed, __u64 imm)
{
	__u8 dst = x86_arg_dst(packed);
	__u8 src = x86_arg_src(packed);
	__u8 width = x86_arg_flags(packed);
	__u32 aux = x86_arg_aux(packed);
	__u8 base_tag = x86_link_read_tag(state, src);
	__u64 base = 0;
	__s64 disp = x86_simm(imm);
	__u8 *end;
	__u64 value = 0;

	if (!width)
		width = X86_WIDTH_64;
	if (base_tag == X86_PTR_CTX) {
		if (imm == 0) {
			if (x86_write_reg_width(state, dst, 0, X86_WIDTH_64) < 0)
				return X86_INTERP_TRAP;
			return x86_link_write_tag(state, dst, X86_PTR_PACKET);
		}
		if (imm == 8) {
			if (x86_write_reg_width(state, dst, 0, X86_WIDTH_64) < 0)
				return X86_INTERP_TRAP;
			return x86_link_write_tag(state, dst,
						  X86_PTR_PACKET_END);
		}
		return X86_INTERP_TRAP;
	}
	if (base_tag != X86_PTR_PACKET && base_tag != X86_PTR_PACKET_END)
		return X86_INTERP_TRAP;
	if (x86_read_reg(state, src, &base) < 0)
		return X86_INTERP_TRAP;
	if (x86_mem_offset(state, aux, disp, &disp) < 0)
		return X86_INTERP_TRAP;
	if (width == X86_WIDTH_8) {
		if (x86_link_packet_end_const(data, data_end, base, disp,
					      X86_WIDTH_8, &end) < 0)
			return X86_INTERP_TRAP;
		x86_link_barrier_var(end);
		value = *(__u8 *)(end - 1);
	} else if (width == X86_WIDTH_16) {
		if (x86_link_packet_end_const(data, data_end, base, disp,
					      X86_WIDTH_16, &end) < 0)
			return X86_INTERP_TRAP;
		x86_link_barrier_var(end);
		value = *(__u16 *)(end - 2);
	} else if (width == X86_WIDTH_32) {
		if (x86_link_packet_end_const(data, data_end, base, disp,
					      X86_WIDTH_32, &end) < 0)
			return X86_INTERP_TRAP;
		x86_link_barrier_var(end);
		value = *(__u32 *)(end - 4);
	} else if (width == X86_WIDTH_64) {
		if (x86_link_packet_end_const(data, data_end, base, disp,
					      X86_WIDTH_64, &end) < 0)
			return X86_INTERP_TRAP;
		x86_link_barrier_var(end);
		value = *(__u64 *)(end - 8);
	} else {
		return X86_INTERP_TRAP;
	}
	return x86_write_reg_width(state, dst, value, width);
}

__noinline int x86_tmpl_arg_movsx_load(struct x86_state *state,
				       void *data, void *data_end,
				       __u64 packed, __u64 imm)
{
	__u8 dst = x86_arg_dst(packed);
	__u8 src = x86_arg_src(packed);
	__u8 write_width = x86_arg_flags(packed);
	__u32 aux = x86_arg_aux(packed);
	__u8 load_width = X86_MEM_AUX_MEM_WIDTH(aux);
	__u8 base_tag = x86_link_read_tag(state, src);
	__s64 disp = x86_simm(imm);
	__u64 base = 0;
	__u64 value = 0;

	if (!write_width)
		write_width = X86_WIDTH_64;
	if (!load_width)
		load_width = write_width;
	if (base_tag != X86_PTR_PACKET)
		return X86_INTERP_TRAP;
	if (x86_read_reg(state, src, &base) < 0)
		return X86_INTERP_TRAP;
	if (x86_mem_offset(state, aux, disp, &disp) < 0)
		return X86_INTERP_TRAP;
	if (x86_link_read_packet(data, data_end, base, disp, load_width,
				 &value) < 0)
		return X86_INTERP_TRAP;
	value = x86_sign_extend(value, load_width);
	return x86_link_write_scalar(state, dst, value, write_width);
}

__noinline int x86_tmpl_arg_lea(struct x86_state *state,
				void *data, void *data_end,
				__u64 packed, __u64 imm)
{
	__u8 dst = x86_arg_dst(packed);
	__u8 src = x86_arg_src(packed);
	__u8 width = x86_arg_flags(packed);
	__u32 aux = x86_arg_aux(packed);
	__u64 base = 0;
	__s64 offset = 0;
	__u8 tag = x86_link_read_tag(state, src);

	if (!width)
		width = X86_WIDTH_64;
#ifdef X86_VM_ENABLE_RODATA
	if (width == X86_WIDTH_64 && src == X86_REG_NONE &&
	    aux == X86_PTR_RODATA) {
		if (x86_write_reg_width(state, dst, imm, width) < 0)
			return X86_INTERP_TRAP;
		return x86_link_write_tag(state, dst, X86_PTR_RODATA);
	}
#endif
	if (src != X86_REG_NONE && x86_read_reg(state, src, &base) < 0)
		return X86_INTERP_TRAP;
	if (x86_mem_offset(state, aux, x86_simm(imm), &offset) < 0)
		return X86_INTERP_TRAP;
	if (x86_write_reg_width(state, dst, base + offset, width) < 0)
		return X86_INTERP_TRAP;
	if (tag == X86_PTR_PACKET || tag == X86_PTR_PACKET_END)
		return x86_link_write_tag(state, dst, tag);
	return X86_INTERP_CONTINUE;
}

__noinline int x86_tmpl_arg_alu_imm(struct x86_state *state,
				    void *data, void *data_end,
				    __u64 packed, __u64 imm)
{
	__u8 dst = x86_arg_dst(packed);
	__u8 width = x86_arg_flags(packed);
	__u32 aux = x86_arg_aux(packed);
	__u8 tag = x86_link_read_tag(state, dst);
	__u64 lhs = 0;
	__u64 rhs = imm;
	__u64 result;

	if (!width)
		width = X86_WIDTH_64;
	if (x86_link_check_width(width) < 0)
		return X86_INTERP_TRAP;
	if (x86_read_reg(state, dst, &lhs) < 0)
		return X86_INTERP_TRAP;
	if (aux == X86_ALU_SBB)
		rhs += state->cf;
	result = x86_alu_result(lhs, rhs, aux, width);
	x86_set_alu_flags(state, lhs, rhs, result, aux, width);
	if (x86_write_reg_width(state, dst, result, width) < 0)
		return X86_INTERP_TRAP;
	if (width == X86_WIDTH_64 &&
	    (tag == X86_PTR_PACKET || tag == X86_PTR_PACKET_END) &&
	    (aux == X86_ALU_ADD || aux == X86_ALU_SUB))
		return x86_link_write_tag(state, dst, tag);
	return x86_link_clear_tag(state, dst);
}

__noinline int x86_tmpl_arg_alu_reg(struct x86_state *state,
				    void *data, void *data_end,
				    __u64 packed, __u64 imm)
{
	__u8 dst = x86_arg_dst(packed);
	__u8 src = x86_arg_src(packed);
	__u8 width = x86_arg_flags(packed);
	__u32 aux = x86_arg_aux(packed);
	__u8 dst_tag = x86_link_read_tag(state, dst);
	__u8 src_tag = x86_link_read_tag(state, src);
	__u64 lhs = 0;
	__u64 rhs = 0;
	__u64 result;
	__u8 result_tag = X86_PTR_NONE;

	if (!width)
		width = X86_WIDTH_64;
	if (x86_link_check_width(width) < 0)
		return X86_INTERP_TRAP;
	if (x86_read_reg(state, dst, &lhs) < 0 ||
	    x86_read_reg(state, src, &rhs) < 0)
		return X86_INTERP_TRAP;
	if (aux == X86_ALU_SBB)
		rhs += state->cf;
	result = x86_alu_result(lhs, rhs, aux, width);
	x86_set_alu_flags(state, lhs, rhs, result, aux, width);
	if (width == X86_WIDTH_64 && aux == X86_ALU_ADD &&
	    dst_tag == X86_PTR_NONE &&
	    (src_tag == X86_PTR_PACKET || src_tag == X86_PTR_PACKET_END))
		result_tag = src_tag;
	else if (width == X86_WIDTH_64 &&
		 (aux == X86_ALU_ADD || aux == X86_ALU_SUB) &&
		 (dst_tag == X86_PTR_PACKET || dst_tag == X86_PTR_PACKET_END))
		result_tag = dst_tag;
	if (x86_write_reg_width(state, dst, result, width) < 0)
		return X86_INTERP_TRAP;
	return x86_link_write_tag(state, dst, result_tag);
}

__noinline int x86_tmpl_arg_alu_mem(struct x86_state *state,
				    void *data, void *data_end,
				    __u64 packed, __u64 imm)
{
	__u8 dst = x86_arg_dst(packed);
	__u8 src = x86_arg_src(packed);
	__u8 width = x86_arg_flags(packed);
	__u32 aux = x86_arg_aux(packed);
	__u8 alu = X86_MEM_AUX_GET_ALU_OP(aux);
	__u8 base_tag = x86_link_read_tag(state, src);
	__u64 dst_value = 0;
	__u64 mem_value = 0;
	__u64 base = 0;
	__u64 result = 0;
	__s64 disp = x86_simm(imm);

	if (!width)
		width = X86_WIDTH_64;
	if (base_tag != X86_PTR_PACKET)
		return X86_INTERP_TRAP;
	if (x86_read_reg(state, dst, &dst_value) < 0 ||
	    x86_read_reg(state, src, &base) < 0)
		return X86_INTERP_TRAP;
	if (x86_mem_offset(state, aux, disp, &disp) < 0)
		return X86_INTERP_TRAP;
	if (x86_link_read_packet(data, data_end, base, disp, width,
				 &mem_value) < 0)
		return X86_INTERP_TRAP;
	if (alu == X86_ALU_SBB)
		mem_value += state->cf;
	result = x86_alu_result(dst_value, mem_value, alu, width);
	x86_set_alu_flags(state, dst_value, mem_value, result, alu, width);
	return x86_link_write_scalar(state, dst, result, width);
}

#define X86_ARG_ALU_IMM_TEMPLATE(NAME, ALU_OP)                             \
	__noinline int x86_tmpl_arg_alu_imm_##NAME(                       \
		struct x86_state *state, void *data, void *data_end,       \
		__u64 packed, __u64 imm)                                  \
	{                                                                  \
		__u8 dst = x86_arg_dst(packed);                            \
		__u8 width = x86_arg_flags(packed);                        \
		__u8 tag = x86_link_read_tag(state, dst);                  \
		__u64 lhs = 0;                                             \
		__u64 rhs = imm;                                           \
		__u64 result;                                              \
		if (!width)                                                \
			width = X86_WIDTH_64;                              \
		if (x86_link_check_width(width) < 0)                       \
			return X86_INTERP_TRAP;                            \
		if (x86_read_reg(state, dst, &lhs) < 0)                    \
			return X86_INTERP_TRAP;                            \
		if ((ALU_OP) == X86_ALU_SBB)                               \
			rhs += state->cf;                                  \
		result = x86_alu_result(lhs, rhs, (ALU_OP), width);        \
		x86_set_alu_flags(state, lhs, rhs, result, (ALU_OP),       \
				  width);                                  \
		if (x86_write_reg_width(state, dst, result, width) < 0)    \
			return X86_INTERP_TRAP;                            \
		if (width == X86_WIDTH_64 &&                               \
		    (tag == X86_PTR_PACKET || tag == X86_PTR_PACKET_END) && \
		    ((ALU_OP) == X86_ALU_ADD || (ALU_OP) == X86_ALU_SUB))   \
			return x86_link_write_tag(state, dst, tag);        \
		return x86_link_clear_tag(state, dst);                     \
	}

#define X86_ARG_ALU_REG_TEMPLATE(NAME, ALU_OP)                              \
	__noinline int x86_tmpl_arg_alu_reg_##NAME(                       \
		struct x86_state *state, void *data, void *data_end,       \
		__u64 packed, __u64 imm)                                  \
	{                                                                  \
		__u8 dst = x86_arg_dst(packed);                            \
		__u8 src = x86_arg_src(packed);                            \
		__u8 width = x86_arg_flags(packed);                        \
		__u8 dst_tag = x86_link_read_tag(state, dst);              \
		__u8 src_tag = x86_link_read_tag(state, src);              \
		__u64 lhs = 0;                                             \
		__u64 rhs = 0;                                             \
		__u64 result;                                              \
		__u8 result_tag = X86_PTR_NONE;                            \
		if (!width)                                                \
			width = X86_WIDTH_64;                              \
		if (x86_link_check_width(width) < 0)                       \
			return X86_INTERP_TRAP;                            \
		if (x86_read_reg(state, dst, &lhs) < 0 ||                  \
		    x86_read_reg(state, src, &rhs) < 0)                    \
			return X86_INTERP_TRAP;                            \
		if ((ALU_OP) == X86_ALU_SBB)                               \
			rhs += state->cf;                                  \
		result = x86_alu_result(lhs, rhs, (ALU_OP), width);        \
		x86_set_alu_flags(state, lhs, rhs, result, (ALU_OP),       \
				  width);                                  \
		if (width == X86_WIDTH_64 && (ALU_OP) == X86_ALU_ADD &&    \
		    dst_tag == X86_PTR_NONE &&                             \
		    (src_tag == X86_PTR_PACKET ||                          \
		     src_tag == X86_PTR_PACKET_END))                       \
			result_tag = src_tag;                              \
		else if (width == X86_WIDTH_64 &&                          \
			 ((ALU_OP) == X86_ALU_ADD ||                      \
			  (ALU_OP) == X86_ALU_SUB) &&                     \
			 (dst_tag == X86_PTR_PACKET ||                    \
			  dst_tag == X86_PTR_PACKET_END))                 \
			result_tag = dst_tag;                              \
		if (x86_write_reg_width(state, dst, result, width) < 0)    \
			return X86_INTERP_TRAP;                            \
		return x86_link_write_tag(state, dst, result_tag);         \
	}

#define X86_ARG_ALU_MEM_TEMPLATE(NAME, ALU_OP)                              \
	__noinline int x86_tmpl_arg_alu_mem_##NAME(                       \
		struct x86_state *state, void *data, void *data_end,       \
		__u64 packed, __u64 imm)                                  \
	{                                                                  \
		__u8 dst = x86_arg_dst(packed);                            \
		__u8 src = x86_arg_src(packed);                            \
		__u8 width = x86_arg_flags(packed);                        \
		__u32 aux = x86_arg_aux(packed);                           \
		__u8 base_tag = x86_link_read_tag(state, src);             \
		__u64 dst_value = 0;                                       \
		__u64 mem_value = 0;                                       \
		__u64 base = 0;                                            \
		__u64 result = 0;                                          \
		__s64 disp = x86_simm(imm);                                \
		if (!width)                                                \
			width = X86_WIDTH_64;                              \
		if (base_tag != X86_PTR_PACKET)                            \
			return X86_INTERP_TRAP;                            \
		if (x86_read_reg(state, dst, &dst_value) < 0 ||            \
		    x86_read_reg(state, src, &base) < 0)                   \
			return X86_INTERP_TRAP;                            \
		if (x86_mem_offset(state, aux, disp, &disp) < 0)           \
			return X86_INTERP_TRAP;                            \
		if (x86_link_read_packet(data, data_end, base, disp,       \
					 width, &mem_value) < 0)          \
			return X86_INTERP_TRAP;                            \
		if ((ALU_OP) == X86_ALU_SBB)                               \
			mem_value += state->cf;                            \
		result = x86_alu_result(dst_value, mem_value, (ALU_OP),    \
					width);                            \
		x86_set_alu_flags(state, dst_value, mem_value, result,     \
				  (ALU_OP), width);                       \
		return x86_link_write_scalar(state, dst, result, width);   \
	}

X86_ARG_ALU_IMM_TEMPLATE(add, X86_ALU_ADD)
X86_ARG_ALU_IMM_TEMPLATE(sub, X86_ALU_SUB)
X86_ARG_ALU_IMM_TEMPLATE(xor, X86_ALU_XOR)
X86_ARG_ALU_IMM_TEMPLATE(or, X86_ALU_OR)
X86_ARG_ALU_IMM_TEMPLATE(and, X86_ALU_AND)
X86_ARG_ALU_IMM_TEMPLATE(shl, X86_ALU_SHL)
X86_ARG_ALU_IMM_TEMPLATE(shr, X86_ALU_SHR)
X86_ARG_ALU_IMM_TEMPLATE(sar, X86_ALU_SAR)
X86_ARG_ALU_IMM_TEMPLATE(rol, X86_ALU_ROL)
X86_ARG_ALU_IMM_TEMPLATE(inc, X86_ALU_INC)
X86_ARG_ALU_IMM_TEMPLATE(not, X86_ALU_NOT)
X86_ARG_ALU_IMM_TEMPLATE(sbb, X86_ALU_SBB)

X86_ARG_ALU_REG_TEMPLATE(add, X86_ALU_ADD)
X86_ARG_ALU_REG_TEMPLATE(sub, X86_ALU_SUB)
X86_ARG_ALU_REG_TEMPLATE(xor, X86_ALU_XOR)
X86_ARG_ALU_REG_TEMPLATE(or, X86_ALU_OR)
X86_ARG_ALU_REG_TEMPLATE(and, X86_ALU_AND)
X86_ARG_ALU_REG_TEMPLATE(shl, X86_ALU_SHL)
X86_ARG_ALU_REG_TEMPLATE(shr, X86_ALU_SHR)
X86_ARG_ALU_REG_TEMPLATE(rol, X86_ALU_ROL)
X86_ARG_ALU_REG_TEMPLATE(imul, X86_ALU_IMUL)

X86_ARG_ALU_MEM_TEMPLATE(add, X86_ALU_ADD)
X86_ARG_ALU_MEM_TEMPLATE(xor, X86_ALU_XOR)
X86_ARG_ALU_MEM_TEMPLATE(or, X86_ALU_OR)

__noinline int x86_tmpl_arg_cmp_imm(struct x86_state *state,
				    void *data, void *data_end,
				    __u64 packed, __u64 imm)
{
	__u8 dst = x86_arg_dst(packed);
	__u8 width = x86_arg_flags(packed);
	__u64 lhs = 0;

	if (!width)
		width = X86_WIDTH_64;
	if (x86_link_check_width(width) < 0)
		return X86_INTERP_TRAP;
	if (x86_read_reg(state, dst, &lhs) < 0)
		return X86_INTERP_TRAP;
	x86_link_set_cmp_flags(state, lhs, imm, width);
	return X86_INTERP_CONTINUE;
}

__noinline int x86_tmpl_arg_cmp_reg(struct x86_state *state,
				    void *data, void *data_end,
				    __u64 packed, __u64 imm)
{
	__u8 dst = x86_arg_dst(packed);
	__u8 src = x86_arg_src(packed);
	__u8 width = x86_arg_flags(packed);
	__u8 dst_tag = x86_link_read_tag(state, dst);
	__u8 src_tag = x86_link_read_tag(state, src);
	__u64 lhs = 0;
	__u64 rhs = 0;

	if (!width)
		width = X86_WIDTH_64;
	if (x86_link_check_width(width) < 0)
		return X86_INTERP_TRAP;
	if (x86_read_reg(state, dst, &lhs) < 0 ||
	    x86_read_reg(state, src, &rhs) < 0)
		return X86_INTERP_TRAP;
	if (width == X86_WIDTH_64 && dst_tag == X86_PTR_PACKET &&
	    src_tag == X86_PTR_PACKET_END)
		return x86_link_set_packet_end_cmp_flags(state, data, data_end,
							 lhs, 1);
	if (width == X86_WIDTH_64 && dst_tag == X86_PTR_PACKET_END &&
	    src_tag == X86_PTR_PACKET)
		return x86_link_set_packet_end_cmp_flags(state, data, data_end,
							 rhs, 0);
	x86_link_set_cmp_flags(state, lhs, rhs, width);
	return X86_INTERP_CONTINUE;
}

__noinline int x86_tmpl_arg_test_imm(struct x86_state *state,
				     void *data, void *data_end,
				     __u64 packed, __u64 imm)
{
	__u8 dst = x86_arg_dst(packed);
	__u8 width = x86_arg_flags(packed);
	__u64 lhs = 0;

	if (!width)
		width = X86_WIDTH_64;
	if (x86_link_check_width(width) < 0)
		return X86_INTERP_TRAP;
	if (x86_read_reg(state, dst, &lhs) < 0)
		return X86_INTERP_TRAP;
	x86_set_logic_flags(state, lhs & imm, width);
	return X86_INTERP_CONTINUE;
}

__noinline int x86_tmpl_arg_test_reg(struct x86_state *state,
				     void *data, void *data_end,
				     __u64 packed, __u64 imm)
{
	__u8 dst = x86_arg_dst(packed);
	__u8 src = x86_arg_src(packed);
	__u8 width = x86_arg_flags(packed);
	__u64 lhs = 0;
	__u64 rhs = 0;

	if (!width)
		width = X86_WIDTH_64;
	if (x86_link_check_width(width) < 0)
		return X86_INTERP_TRAP;
	if (x86_read_reg(state, dst, &lhs) < 0 ||
	    x86_read_reg(state, src, &rhs) < 0)
		return X86_INTERP_TRAP;
	x86_set_logic_flags(state, lhs & rhs, width);
	return X86_INTERP_CONTINUE;
}

static __always_inline int x86_link_arg_cmp_mem(struct x86_state *state,
						void *data, void *data_end,
						__u64 packed, __u64 imm)
{
	__u8 op = x86_arg_op(packed);
	__u8 dst = x86_arg_dst(packed);
	__u8 src = x86_arg_src(packed);
	__u8 width = x86_arg_flags(packed);
	__u32 aux = x86_arg_aux(packed);
	__u8 base_tag = x86_link_read_tag(state, dst);
	__s64 disp = op == X86_OP_CMP_MEM_REG ?
			     x86_simm(imm) :
			     x86_store_imm_disp(imm);
	__u64 base = 0;
	__u64 value = 0;
	__u64 rhs = x86_store_imm_value(imm);

	if (!width)
		width = X86_WIDTH_64;
	if (base_tag != X86_PTR_PACKET)
		return X86_INTERP_TRAP;
	if (x86_read_reg(state, dst, &base) < 0)
		return X86_INTERP_TRAP;
	if (x86_mem_offset(state, aux, disp, &disp) < 0)
		return X86_INTERP_TRAP;
	if (x86_link_read_packet(data, data_end, base, disp, width,
				 &value) < 0)
		return X86_INTERP_TRAP;
	if (op == X86_OP_CMP_MEM_REG &&
	    x86_read_reg(state, src, &rhs) < 0)
		return X86_INTERP_TRAP;
	if (op == X86_OP_TEST_MEM_IMM)
		x86_set_logic_flags(state, value & rhs, width);
	else
		x86_set_sub_flags(state, value, rhs, value - rhs, width);
	return X86_INTERP_CONTINUE;
}

__noinline int x86_tmpl_arg_cmp_mem_imm(struct x86_state *state,
					void *data, void *data_end,
					__u64 packed, __u64 imm)
{
	return x86_link_arg_cmp_mem(state, data, data_end, packed, imm);
}

__noinline int x86_tmpl_arg_cmp_mem_reg(struct x86_state *state,
					void *data, void *data_end,
					__u64 packed, __u64 imm)
{
	return x86_link_arg_cmp_mem(state, data, data_end, packed, imm);
}

__noinline int x86_tmpl_arg_test_mem_imm(struct x86_state *state,
					 void *data, void *data_end,
					 __u64 packed, __u64 imm)
{
	return x86_link_arg_cmp_mem(state, data, data_end, packed, imm);
}

__noinline int x86_tmpl_arg_jcc(struct x86_state *state,
				void *data, void *data_end,
				__u64 packed, __u64 imm)
{
	return x86_eval_cc(state, x86_arg_aux(packed));
}

__noinline int x86_tmpl_arg_mov_store_imm(struct x86_state *state,
					  void *data, void *data_end,
					  __u64 packed, __u64 imm)
{
	__u8 dst = x86_arg_dst(packed);
	__u8 width = x86_arg_flags(packed);
	__u8 base_tag = x86_link_read_tag(state, dst);
	__u64 base = 0;
	__u32 value = x86_store_imm_value(imm);

	if (base_tag != X86_PTR_PACKET)
		return X86_INTERP_TRAP;
	if (x86_read_reg(state, dst, &base) < 0)
		return X86_INTERP_TRAP;
	return x86_link_store_packet(data, data_end, base,
				     x86_store_imm_disp(imm), width, value);
}

__noinline int x86_tmpl_arg_mov_store_reg(struct x86_state *state,
					  void *data, void *data_end,
					  __u64 packed, __u64 imm)
{
	__u8 dst = x86_arg_dst(packed);
	__u8 src = x86_arg_src(packed);
	__u8 width = x86_arg_flags(packed);
	__u32 aux = x86_arg_aux(packed);
	__u8 base_tag = x86_link_read_tag(state, dst);
	__u64 base = 0;
	__u64 value = 0;
	__s64 disp = x86_simm(imm);
	__u8 src_shift = X86_REG_AUX_GET_SRC_SHIFT(aux);

	if (base_tag != X86_PTR_PACKET)
		return X86_INTERP_TRAP;
	if (x86_read_reg(state, dst, &base) < 0 ||
	    x86_read_reg(state, src, &value) < 0)
		return X86_INTERP_TRAP;
	if (src_shift != 0)
		value >>= src_shift;
	if (x86_mem_offset(state, aux, disp, &disp) < 0)
		return X86_INTERP_TRAP;
	return x86_link_store_packet(data, data_end, base, disp, width, value);
}

__noinline int x86_tmpl_arg_cmov(struct x86_state *state,
				 void *data, void *data_end,
				 __u64 packed, __u64 imm)
{
	__u8 dst = x86_arg_dst(packed);
	__u8 src = x86_arg_src(packed);
	__u8 width = x86_arg_flags(packed);
	__u32 aux = x86_arg_aux(packed);
	__u64 value = 0;
	__u8 tag;

	if (!width)
		width = X86_WIDTH_64;
	if (!x86_eval_cc(state, aux))
		return X86_INTERP_CONTINUE;
	tag = x86_link_read_tag(state, src);
	if (x86_link_check_width(width) < 0)
		return X86_INTERP_TRAP;
	if (x86_read_reg(state, src, &value) < 0)
		return X86_INTERP_TRAP;
	if (x86_write_reg_width(state, dst, value, width) < 0)
		return X86_INTERP_TRAP;
	if (width == X86_WIDTH_64)
		return x86_link_write_tag(state, dst, tag);
	return x86_link_clear_tag(state, dst);
}

__noinline int x86_tmpl_arg_setcc(struct x86_state *state,
				  void *data, void *data_end,
				  __u64 packed, __u64 imm)
{
	return x86_link_write_scalar(state, x86_arg_dst(packed),
				     x86_eval_cc(state, x86_arg_aux(packed)),
				     X86_WIDTH_8);
}

__noinline int x86_tmpl_arg_bswap(struct x86_state *state,
				  void *data, void *data_end,
				  __u64 packed, __u64 imm)
{
	__u8 dst = x86_arg_dst(packed);
	__u8 width = x86_arg_flags(packed);
	__u64 value = 0;

	if (!width)
		width = X86_WIDTH_64;
	if (width != X86_WIDTH_32 && width != X86_WIDTH_64)
		return X86_INTERP_TRAP;
	if (x86_read_reg(state, dst, &value) < 0)
		return X86_INTERP_TRAP;
	return x86_link_write_scalar(state, dst, x86_bswap(value, width),
				     width);
}

__noinline int x86_tmpl_arg_popcnt(struct x86_state *state,
				   void *data, void *data_end,
				   __u64 packed, __u64 imm)
{
	__u8 dst = x86_arg_dst(packed);
	__u8 src = x86_arg_src(packed);
	__u8 width = x86_arg_flags(packed);
	__u64 value = 0;

	if (!width)
		width = X86_WIDTH_64;
	if (x86_link_check_width(width) < 0)
		return X86_INTERP_TRAP;
	if (x86_read_reg(state, src, &value) < 0)
		return X86_INTERP_TRAP;
	return x86_link_write_scalar(state, dst,
				     x86_popcount64(x86_apply_width(value,
								    width)),
				     width);
}

__noinline int x86_tmpl_arg_xchg(struct x86_state *state,
				 void *data, void *data_end,
				 __u64 packed, __u64 imm)
{
	__u8 dst = x86_arg_dst(packed);
	__u8 src = x86_arg_src(packed);
	__u8 width = x86_arg_flags(packed);
	__u64 dst_value = 0;
	__u64 src_value = 0;

	if (!width)
		width = X86_WIDTH_64;
	if (x86_link_check_width(width) < 0)
		return X86_INTERP_TRAP;
	if (x86_read_reg(state, dst, &dst_value) < 0 ||
	    x86_read_reg(state, src, &src_value) < 0)
		return X86_INTERP_TRAP;
	if (x86_link_write_scalar(state, dst, src_value, width) < 0)
		return X86_INTERP_TRAP;
	return x86_link_write_scalar(state, src, dst_value, width);
}

__noinline int x86_tmpl_arg_div(struct x86_state *state,
				void *data, void *data_end,
				__u64 packed, __u64 imm)
{
	__u8 src = x86_arg_src(packed);
	__u8 width = x86_arg_flags(packed);
	__u64 divisor = 0;
	__u64 rax = 0;
	__u64 rdx = 0;

	if (!width)
		width = X86_WIDTH_64;
	if (x86_read_reg(state, src, &divisor) < 0 ||
	    x86_read_reg(state, X86_RAX, &rax) < 0 ||
	    x86_read_reg(state, X86_RDX, &rdx) < 0)
		return X86_INTERP_TRAP;
	if (width == X86_WIDTH_32) {
		__u64 dividend;
		__u64 quotient;
		__u64 remainder;

		divisor = (__u32)divisor;
		if (divisor == 0)
			return X86_INTERP_TRAP;
		dividend = ((__u64)(__u32)rdx << 32) | (__u32)rax;
		quotient = dividend / divisor;
		remainder = dividend % divisor;
		if (quotient > 0xffffffffULL)
			return X86_INTERP_TRAP;
		if (x86_link_write_scalar(state, X86_RAX, quotient,
					  X86_WIDTH_32) < 0)
			return X86_INTERP_TRAP;
		return x86_link_write_scalar(state, X86_RDX, remainder,
					     X86_WIDTH_32);
	}
	if (width != X86_WIDTH_64 || divisor == 0 || rdx != 0)
		return X86_INTERP_TRAP;
	if (x86_link_write_scalar(state, X86_RAX, rax / divisor,
				  X86_WIDTH_64) < 0)
		return X86_INTERP_TRAP;
	return x86_link_write_scalar(state, X86_RDX, rax % divisor,
				     X86_WIDTH_64);
}

__noinline int x86_tmpl_arg_shld_imm(struct x86_state *state,
				     void *data, void *data_end,
				     __u64 packed, __u64 imm)
{
	__u8 dst = x86_arg_dst(packed);
	__u8 src = x86_arg_src(packed);
	__u8 width = x86_arg_flags(packed);
	__u64 dst_value = 0;
	__u64 src_value = 0;
	__u64 result = 0;

	if (!width)
		width = X86_WIDTH_64;
	if (x86_link_check_width(width) < 0)
		return X86_INTERP_TRAP;
	if (x86_read_reg(state, dst, &dst_value) < 0 ||
	    x86_read_reg(state, src, &src_value) < 0)
		return X86_INTERP_TRAP;
	result = x86_shld(dst_value, src_value, imm, width);
	x86_set_logic_flags(state, result, width);
	return x86_link_write_scalar(state, dst, result, width);
}

__noinline int x86_tmpl_arg_shrd_imm(struct x86_state *state,
				     void *data, void *data_end,
				     __u64 packed, __u64 imm)
{
	__u8 dst = x86_arg_dst(packed);
	__u8 src = x86_arg_src(packed);
	__u8 width = x86_arg_flags(packed);
	__u64 dst_value = 0;
	__u64 src_value = 0;
	__u64 result = 0;

	if (!width)
		width = X86_WIDTH_64;
	if (x86_link_check_width(width) < 0)
		return X86_INTERP_TRAP;
	if (x86_read_reg(state, dst, &dst_value) < 0 ||
	    x86_read_reg(state, src, &src_value) < 0)
		return X86_INTERP_TRAP;
	result = x86_shrd(dst_value, src_value, imm, width);
	x86_set_logic_flags(state, result, width);
	return x86_link_write_scalar(state, dst, result, width);
}

__noinline int x86_tmpl_arg_push(struct x86_state *state,
				 void *data, void *data_end,
				 __u64 packed, __u64 imm)
{
	return X86_INTERP_CONTINUE;
}

__noinline int x86_tmpl_arg_pop(struct x86_state *state,
				void *data, void *data_end,
				__u64 packed, __u64 imm)
{
	return X86_INTERP_CONTINUE;
}

__noinline int x86_tmpl_arg_ret(struct x86_state *state,
				void *data, void *data_end,
				__u64 packed, __u64 imm)
{
	return X86_INTERP_DONE;
}
