#ifndef X86_VM_BPF_H
#define X86_VM_BPF_H

#include <linux/bpf.h>
#include <bpf_helpers.h>

#ifndef X86_VM_ENABLE_PACKET_REG_FASTPATH
#define X86_VM_ENABLE_PACKET_REG_FASTPATH 1
#endif

#ifndef X86_VM_LOOP_FUEL
#define X86_VM_LOOP_FUEL 4096U
#endif

#include "x86_interp.h"

#define X86_VM_OUTPUT_OFF 0U

#define X86_VM_INSN(OP, DST, SRC, FLAGS, AUX, IMM)                         \
	((struct x86_insn){                                                 \
		.op = (OP),                                                 \
		.dst = (DST),                                               \
		.src = (SRC),                                               \
		.flags = (FLAGS),                                           \
		.aux = (AUX),                                               \
		.imm = (IMM),                                               \
	})

#define X86_VM_LOAD_INSN(OP, DST, SRC, FLAGS, AUX, IMM)                    \
	do {                                                               \
		__x86_vm_insn.op = (OP);                                   \
		__x86_vm_insn.dst = (DST);                                 \
		__x86_vm_insn.src = (SRC);                                 \
		__x86_vm_insn.flags = (FLAGS);                             \
		__x86_vm_insn.aux = (AUX);                                 \
		__x86_vm_insn.imm = (IMM);                                 \
	} while (0)

#define X86_VM_MEM_OP_SRC_BASE(OP)                                         \
	((OP) == X86_OP_MOV_LOAD || (OP) == X86_OP_MOVSX_LOAD ||           \
	 (OP) == X86_OP_ALU_MEM)

#define X86_VM_MEM_OP_DST_BASE(OP)                                         \
	((OP) == X86_OP_MOV_STORE_IMM || (OP) == X86_OP_MOV_STORE_REG ||    \
	 (OP) == X86_OP_CMP_MEM_IMM || (OP) == X86_OP_TEST_MEM_IMM ||       \
	 (OP) == X86_OP_CMP_MEM_REG)

#define X86_VM_MEM_BASE_REG(OP, DST, SRC)                                  \
	(X86_VM_MEM_OP_SRC_BASE(OP) ? (SRC) :                              \
	 X86_VM_MEM_OP_DST_BASE(OP) ? (DST) : X86_REG_NONE)

#define X86_VM_PACKET_FASTPATH_CANDIDATE(OP, DST, SRC)                    \
	(X86_VM_MEM_BASE_REG((OP), (DST), (SRC)) != X86_REG_NONE &&        \
	 X86_VM_MEM_BASE_REG((OP), (DST), (SRC)) != X86_RDI &&             \
	 X86_VM_MEM_BASE_REG((OP), (DST), (SRC)) != X86_RBP &&             \
	 X86_VM_MEM_BASE_REG((OP), (DST), (SRC)) != X86_RSP)

#define X86_VM_EXEC_PACKET(STATE, OP)                                      \
	({                                                                 \
		int __x86_vm_packet_ret = X86_INTERP_TRAP;                 \
		if ((OP) == X86_OP_MOV_LOAD || (OP) == X86_OP_MOVSX_LOAD)  \
			__x86_vm_packet_ret =                              \
				x86_exec_mov_load_packet((STATE),           \
							 &__x86_vm_insn,    \
							 __x86_vm_data,     \
							 __x86_vm_data_end);\
		else if ((OP) == X86_OP_MOV_STORE_IMM)                    \
			__x86_vm_packet_ret =                              \
				x86_exec_mov_store_imm_packet(               \
					(STATE), &__x86_vm_insn,              \
					__x86_vm_data, __x86_vm_data_end);    \
		else if ((OP) == X86_OP_MOV_STORE_REG)                    \
			__x86_vm_packet_ret =                              \
				x86_exec_mov_store_reg_packet(               \
					(STATE), &__x86_vm_insn,              \
					__x86_vm_data, __x86_vm_data_end);    \
		else if ((OP) == X86_OP_ALU_MEM)                          \
			__x86_vm_packet_ret =                              \
				x86_exec_alu_mem_packet((STATE),             \
							&__x86_vm_insn,      \
							__x86_vm_data,       \
							__x86_vm_data_end);  \
		else if ((OP) == X86_OP_CMP_MEM_IMM)                      \
			__x86_vm_packet_ret =                              \
				x86_exec_cmp_mem_imm_packet(                 \
					(STATE), &__x86_vm_insn,              \
					__x86_vm_data, __x86_vm_data_end);    \
		else if ((OP) == X86_OP_TEST_MEM_IMM)                     \
			__x86_vm_packet_ret =                              \
				x86_exec_test_mem_imm_packet(                \
					(STATE), &__x86_vm_insn,              \
					__x86_vm_data, __x86_vm_data_end);    \
		else if ((OP) == X86_OP_CMP_MEM_REG)                      \
			__x86_vm_packet_ret =                              \
				x86_exec_cmp_mem_reg_packet(                 \
					(STATE), &__x86_vm_insn,              \
					__x86_vm_data, __x86_vm_data_end);    \
		__x86_vm_packet_ret;                                      \
	})

#define X86_VM_EXEC(STATE, OP, DST, SRC, FLAGS, AUX, IMM)                  \
	({                                                                 \
		X86_VM_LOAD_INSN((OP), (DST), (SRC), (FLAGS), (AUX), (IMM)); \
		X86_VM_PACKET_FASTPATH_CANDIDATE((OP), (DST), (SRC)) ?     \
			X86_VM_EXEC_PACKET((STATE), (OP)) :                 \
			x86_exec_one((STATE), &__x86_vm_insn,               \
				     __x86_vm_data, __x86_vm_data_end);     \
	})

static __always_inline int x86_vm_write_result_u64(void *data, void *data_end,
						   __u64 value)
{
	__u8 *p = data + X86_VM_OUTPUT_OFF;

	if (p + 8 > (__u8 *)data_end)
		return -1;
	p[0] = value;
	p[1] = value >> 8;
	p[2] = value >> 16;
	p[3] = value >> 24;
	p[4] = value >> 32;
	p[5] = value >> 40;
	p[6] = value >> 48;
	p[7] = value >> 56;
	return 0;
}

#define X86_VM_BEGIN_XDP(CTX)                                               \
	({                                                                 \
		void *__x86_vm_ctx = (void *)(CTX);                         \
		void *__x86_vm_data = (void *)(long)(CTX)->data;            \
		void *__x86_vm_data_end = (void *)(long)(CTX)->data_end;    \
		struct x86_state __x86_vm_state = {};                       \
		struct x86_insn __x86_vm_insn = {};                         \
		x86_init_state(&__x86_vm_state, (void *)(CTX));             \
		int __x86_vm_ret = 0;

#define X86_VM_DECLARE_XDP(CTX)                                             \
	void *__x86_vm_ctx = (void *)(CTX);                                     \
	void *__x86_vm_data = (void *)(long)(CTX)->data;                    \
	void *__x86_vm_data_end = (void *)(long)(CTX)->data_end;            \
	struct x86_state __x86_vm_state = {};                               \
	struct x86_insn __x86_vm_insn = {};                                 \
	__u32 __x86_vm_loop_fuel = X86_VM_LOOP_FUEL;                       \
	x86_init_state(&__x86_vm_state, (void *)(CTX))

#define X86_VM_STEP(OP, DST, SRC, FLAGS, AUX, IMM)                          \
		if (__x86_vm_ret == 0) {                                      \
			int __x86_vm_step_ret =                               \
				X86_VM_EXEC(&__x86_vm_state, (OP), (DST),      \
					     (SRC), (FLAGS), (AUX), (IMM));    \
			if (__x86_vm_step_ret == X86_INTERP_DONE)              \
				__x86_vm_ret = X86_INTERP_DONE;                \
			else if (__x86_vm_step_ret < 0)                        \
				__x86_vm_ret = __x86_vm_step_ret;              \
		}

#define X86_VM_STEP_OP(OP, DST, SRC, FLAGS, AUX, IMM)                      \
		if (__x86_vm_ret == 0) {                                      \
			int __x86_vm_step_ret =                               \
				X86_VM_EXEC(&__x86_vm_state, (OP), (DST),      \
					     (SRC), (FLAGS), (AUX), (IMM));    \
			if (__x86_vm_step_ret == X86_INTERP_DONE)              \
				__x86_vm_ret = X86_INTERP_DONE;                \
			else if (__x86_vm_step_ret < 0)                        \
				__x86_vm_ret = __x86_vm_step_ret;              \
		}

#define X86_VM_RUN_STEP(OP, DST, SRC, FLAGS, AUX, IMM)                      \
	do {                                                               \
		int __x86_vm_step_ret =                                    \
			X86_VM_EXEC(&__x86_vm_state, (OP), (DST), (SRC),    \
				     (FLAGS), (AUX), (IMM));                 \
		if (__x86_vm_step_ret < 0)                                 \
			X86_VM_TRAP_RETURN();                             \
		if (__x86_vm_step_ret == X86_INTERP_DONE)                  \
			return (__u32)__x86_vm_state.rax;                  \
	} while (0)

#define X86_VM_RUN_OP(OP, DST, SRC, FLAGS, AUX, IMM)                       \
	do {                                                               \
		x86_vm_prepare_ctx_output(&__x86_vm_state, __x86_vm_ctx,    \
					  (OP), (DST), (FLAGS), (IMM));      \
		int __x86_vm_step_ret =                                    \
			X86_VM_EXEC(&__x86_vm_state, (OP), (DST), (SRC),   \
				     (FLAGS), (AUX), (IMM));                \
		if (__x86_vm_step_ret < 0)                                 \
			X86_VM_TRAP_RETURN();                             \
		if (__x86_vm_step_ret == X86_INTERP_DONE)                  \
			return (__u32)__x86_vm_state.rax;                  \
	} while (0)

#define X86_VM_X86_CALL(FN)                                                 \
	do {                                                                 \
		if (FN(&__x86_vm_state, __x86_vm_data, __x86_vm_data_end) < \
		    0)                                                       \
			X86_VM_TRAP_RETURN();                                \
	} while (0)

#define X86_VM_RUN_STEP_SUB(OP, DST, SRC, FLAGS, AUX, IMM)                  \
	do {                                                               \
		int __x86_vm_step_ret =                                    \
			X86_VM_EXEC(&__x86_vm_state, (OP), (DST), (SRC),    \
				     (FLAGS), (AUX), (IMM));                 \
		if (__x86_vm_step_ret < 0)                                 \
			return X86_INTERP_TRAP;                            \
		if (__x86_vm_step_ret == X86_INTERP_DONE)                  \
			return X86_INTERP_CONTINUE;                        \
	} while (0)

#define X86_VM_RUN_OP_SUB(OP, DST, SRC, FLAGS, AUX, IMM)                   \
	do {                                                               \
		int __x86_vm_step_ret =                                    \
			X86_VM_EXEC(&__x86_vm_state, (OP), (DST), (SRC),   \
				     (FLAGS), (AUX), (IMM));                \
		if (__x86_vm_step_ret < 0)                                 \
			return X86_INTERP_TRAP;                            \
		if (__x86_vm_step_ret == X86_INTERP_DONE)                  \
			return X86_INTERP_CONTINUE;                        \
	} while (0)

static __always_inline __u32 x86_vm_ret_rax(struct x86_state *state)
{
	return (__u32)state->rax;
}

#define X86_VM_TRAP_RETURN() return XDP_ABORTED

#define X86_VM_X86_RET() return x86_vm_ret_rax(&__x86_vm_state)

#define X86_VM_X86_BACKEDGE_GUARD(CURRENT, TARGET)                          \
	do {                                                                 \
		if ((__u64)(TARGET) <= (__u64)(CURRENT)) {                    \
			if (__x86_vm_loop_fuel == 0)                          \
				X86_VM_TRAP_RETURN();                         \
			__x86_vm_loop_fuel--;                                \
		}                                                            \
	} while (0)

#define X86_VM_X86_JMP(CURRENT, TARGET, LABEL)                              \
	do {                                                                 \
		X86_VM_X86_BACKEDGE_GUARD((CURRENT), (TARGET));               \
		goto LABEL;                                                   \
	} while (0)

#define X86_VM_X86_JCC(CC, CURRENT, TARGET, LABEL)                           \
	do {                                                                 \
		if (x86_eval_cc(&__x86_vm_state, (CC)))                       \
			X86_VM_X86_JMP((CURRENT), (TARGET), LABEL);           \
	} while (0)

#define X86_VM_X86_SUB_BACKEDGE_GUARD(CURRENT, TARGET)                      \
	do {                                                                 \
		if ((__u64)(TARGET) <= (__u64)(CURRENT)) {                    \
			if (__x86_vm_loop_fuel == 0)                          \
				return X86_INTERP_TRAP;                       \
			__x86_vm_loop_fuel--;                                \
		}                                                            \
	} while (0)

#define X86_VM_X86_SUB_JMP(CURRENT, TARGET, LABEL)                          \
	do {                                                                 \
		X86_VM_X86_SUB_BACKEDGE_GUARD((CURRENT), (TARGET));           \
		goto LABEL;                                                   \
	} while (0)

#define X86_VM_X86_SUB_JCC(CC, CURRENT, TARGET, LABEL)                       \
	do {                                                                 \
		if (x86_eval_cc(&__x86_vm_state, (CC)))                       \
			X86_VM_X86_SUB_JMP((CURRENT), (TARGET), LABEL);       \
	} while (0)

struct x86_vm_loop_ctx {
	struct x86_state state;
	void *data;
	void *data_end;
	__u32 failed;
	__u32 done;
	__u32 next;
	__u32 rdi_written;
};

struct x86_vm_reg_save {
	__u64 value;
	void *ptr;
	__u8 tag;
};

struct x86_vm_callee_saved {
	__u64 rbx;
	__u64 r12;
	__u64 r13;
	__u64 r14;
	__u64 r15;
	void *p_rbx;
	void *p_r12;
	void *p_r13;
	void *p_r14;
	void *p_r15;
	__u8 tag_rbx;
	__u8 tag_r12;
	__u8 tag_r13;
	__u8 tag_r14;
	__u8 tag_r15;
};

static __always_inline void
x86_vm_save_callee(struct x86_vm_callee_saved *saved,
		   const struct x86_state *state)
{
	saved->rbx = state->rbx;
	saved->r12 = state->r12;
	saved->r13 = state->r13;
	saved->r14 = state->r14;
	saved->r15 = state->r15;
	saved->p_rbx = state->p_rbx;
	saved->p_r12 = state->p_r12;
	saved->p_r13 = state->p_r13;
	saved->p_r14 = state->p_r14;
	saved->p_r15 = state->p_r15;
	saved->tag_rbx = state->tag_rbx;
	saved->tag_r12 = state->tag_r12;
	saved->tag_r13 = state->tag_r13;
	saved->tag_r14 = state->tag_r14;
	saved->tag_r15 = state->tag_r15;
}

static __always_inline void
x86_vm_restore_callee(struct x86_state *state,
		      const struct x86_vm_callee_saved *saved)
{
	state->rbx = saved->rbx;
	state->r12 = saved->r12;
	state->r13 = saved->r13;
	state->r14 = saved->r14;
	state->r15 = saved->r15;
	state->p_rbx = saved->p_rbx;
	state->p_r12 = saved->p_r12;
	state->p_r13 = saved->p_r13;
	state->p_r14 = saved->p_r14;
	state->p_r15 = saved->p_r15;
	state->tag_rbx = saved->tag_rbx;
	state->tag_r12 = saved->tag_r12;
	state->tag_r13 = saved->tag_r13;
	state->tag_r14 = saved->tag_r14;
	state->tag_r15 = saved->tag_r15;
}

#define X86_VM_SUB_BEGIN()                                                  \
	struct x86_insn __x86_vm_insn = {};                                 \
	__u32 __x86_vm_loop_fuel = X86_VM_LOOP_FUEL;                       \
	struct x86_vm_callee_saved __x86_vm_callee_saved = {};              \
	x86_vm_save_callee(&__x86_vm_callee_saved, &__x86_vm_state)

#define X86_VM_X86_SUB_RET()                                                \
	do {                                                                 \
		x86_vm_restore_callee(&__x86_vm_state,                       \
				      &__x86_vm_callee_saved);              \
		return X86_INTERP_CONTINUE;                                  \
	} while (0)

static __always_inline int x86_vm_op_writes_reg(__u8 op, __u8 dst, __u8 src,
						__u8 reg)
{
	if (op == X86_OP_XCHG)
		return dst == reg || src == reg;
	if (op == X86_OP_DIV)
		return reg == X86_RAX || reg == X86_RDX;
	if (dst != reg)
		return 0;
	if (op == X86_OP_MOV_IMM || op == X86_OP_MOV_REG ||
	    op == X86_OP_MOVZX_REG || op == X86_OP_MOVSX_REG ||
	    op == X86_OP_MOV_LOAD || op == X86_OP_MOVSX_LOAD ||
	    op == X86_OP_LEA || op == X86_OP_ADD_IMM ||
	    op == X86_OP_ADD_REG || op == X86_OP_XOR_REG ||
	    op == X86_OP_ALU_IMM || op == X86_OP_ALU_REG ||
	    op == X86_OP_ALU_MEM || op == X86_OP_CMOV ||
	    op == X86_OP_SETCC || op == X86_OP_BSWAP ||
	    op == X86_OP_POPCNT || op == X86_OP_SHLD_IMM ||
	    op == X86_OP_SHRD_IMM || op == X86_OP_POP)
		return 1;
	return 0;
}

static __always_inline int x86_vm_is_ctx_output_store(__u8 op, __u8 dst,
						      __u8 flags, __u64 imm)
{
	__s64 disp;

	if (op != X86_OP_MOV_STORE_IMM && op != X86_OP_MOV_STORE_REG)
		return 0;
	if (dst != X86_RDI || flags != X86_WIDTH_32)
		return 0;
	disp = op == X86_OP_MOV_STORE_IMM ? x86_store_imm_disp(imm) :
					    x86_simm(imm);
	return disp == 16 || disp == 20;
}

static __always_inline void
x86_vm_prepare_ctx_output(struct x86_state *state, void *ctx, __u8 op,
			  __u8 dst, __u8 flags, __u64 imm)
{
	if (!x86_vm_is_ctx_output_store(op, dst, flags, imm))
		return;
	state->p_rdi = ctx;
	state->tag_rdi = X86_PTR_CTX;
}

static __always_inline int
x86_vm_read_packet_mem_value(struct x86_state *state, __u8 base_reg, __u32 aux,
			     __s64 disp, void *data, void *data_end,
			     __u8 width, __u64 *value)
{
	void *base = 0;
	__u8 tag = X86_PTR_NONE;

	if (x86_mem_offset(state, aux, disp, &disp) < 0)
		return X86_INTERP_TRAP;
	if (x86_read_ptr_reg(state, base_reg, &base, &tag) < 0)
		return X86_INTERP_TRAP;
	if (tag != X86_PTR_PACKET || !base)
		return X86_INTERP_TRAP;
	return x86_read_packet_value(data, data_end, base, disp, width, value);
}

static __always_inline int
x86_exec_mov_load_packet(struct x86_state *state, const struct x86_insn *insn,
			 void *data, void *data_end)
{
	__u8 mem_width = X86_MEM_AUX_MEM_WIDTH(insn->aux);
	void *base = 0;
	__u8 tag = X86_PTR_NONE;
	__s64 disp = x86_simm(insn->imm);

	if (!mem_width)
		mem_width = insn->flags;
	if (x86_mem_offset(state, insn->aux, disp, &disp) < 0)
		return X86_INTERP_TRAP;
	if (x86_read_ptr_reg(state, insn->src, &base, &tag) < 0)
		return X86_INTERP_TRAP;
	if (tag != X86_PTR_PACKET || !base)
		return X86_INTERP_TRAP;
	return x86_load_packet(state, insn->dst, data, data_end, base, disp,
			       mem_width, insn->flags,
			       insn->op == X86_OP_MOVSX_LOAD);
}

static __always_inline int
x86_exec_alu_mem_packet(struct x86_state *state, const struct x86_insn *insn,
			void *data, void *data_end)
{
	__u8 width = insn->flags ? insn->flags : X86_WIDTH_64;
	__u8 alu = X86_MEM_AUX_GET_ALU_OP(insn->aux);
	__u64 dst_value = 0;
	__u64 mem_value = 0;
	__u64 result = 0;

	if (x86_read_reg(state, insn->dst, &dst_value) < 0)
		return X86_INTERP_TRAP;
	if (x86_vm_read_packet_mem_value(state, insn->src, insn->aux,
					 x86_simm(insn->imm), data, data_end,
					 width, &mem_value) < 0)
		return X86_INTERP_TRAP;
	if (alu == X86_ALU_SBB)
		mem_value += state->cf;
	result = x86_alu_result(dst_value, mem_value, alu, width);
	x86_set_alu_flags(state, dst_value, mem_value, result, alu, width);
	return x86_write_reg_width(state, insn->dst, result, width);
}

static __always_inline int
x86_exec_cmp_mem_packet(struct x86_state *state, const struct x86_insn *insn,
			void *data, void *data_end)
{
	__u64 lhs = 0;
	__u64 rhs = x86_store_imm_value(insn->imm);
	__s64 disp = insn->op == X86_OP_CMP_MEM_REG ?
			     x86_simm(insn->imm) :
			     x86_store_imm_disp(insn->imm);

	if (x86_vm_read_packet_mem_value(state, insn->dst, insn->aux,
					 disp, data, data_end, insn->flags,
					 &lhs) < 0)
		return X86_INTERP_TRAP;
	if (insn->op == X86_OP_CMP_MEM_REG &&
	    x86_read_reg(state, insn->src, &rhs) < 0)
		return X86_INTERP_TRAP;
	if (insn->op == X86_OP_TEST_MEM_IMM) {
		x86_set_logic_flags(state, lhs & rhs, insn->flags);
		return X86_INTERP_CONTINUE;
	}
	x86_set_sub_flags(state, lhs, rhs, lhs - rhs, insn->flags);
	return X86_INTERP_CONTINUE;
}

static __always_inline int
x86_exec_cmp_mem_imm_packet(struct x86_state *state,
			    const struct x86_insn *insn, void *data,
			    void *data_end)
{
	return x86_exec_cmp_mem_packet(state, insn, data, data_end);
}

static __always_inline int
x86_exec_cmp_mem_reg_packet(struct x86_state *state,
			    const struct x86_insn *insn, void *data,
			    void *data_end)
{
	return x86_exec_cmp_mem_packet(state, insn, data, data_end);
}

static __always_inline int
x86_exec_test_mem_imm_packet(struct x86_state *state,
			     const struct x86_insn *insn, void *data,
			     void *data_end)
{
	return x86_exec_cmp_mem_packet(state, insn, data, data_end);
}

static __always_inline int
x86_exec_mov_store_reg_packet(struct x86_state *state,
			      const struct x86_insn *insn, void *data,
			      void *data_end)
{
	void *base = 0;
	__u8 tag = X86_PTR_NONE;
	__s64 disp = x86_simm(insn->imm);

	if (x86_mem_offset(state, insn->aux, disp, &disp) < 0)
		return X86_INTERP_TRAP;
	if (x86_read_ptr_reg(state, insn->dst, &base, &tag) < 0)
		return X86_INTERP_TRAP;
	if (tag != X86_PTR_PACKET || !base)
		return X86_INTERP_TRAP;
	return x86_store_packet_reg(state, insn->src, data, data_end, base,
				    disp, insn->flags, insn->aux);
}

static __always_inline int
x86_exec_mov_store_imm_packet(struct x86_state *state,
			      const struct x86_insn *insn, void *data,
			      void *data_end)
{
	void *base = 0;
	__u8 tag = X86_PTR_NONE;
	__s64 disp = x86_store_imm_disp(insn->imm);

	if (x86_mem_offset(state, insn->aux, disp, &disp) < 0)
		return X86_INTERP_TRAP;
	if (x86_read_ptr_reg(state, insn->dst, &base, &tag) < 0)
		return X86_INTERP_TRAP;
	if (tag != X86_PTR_PACKET || !base)
		return X86_INTERP_TRAP;
	return x86_store_packet_imm(data, data_end, base, disp, insn->flags,
				    x86_store_imm_value(insn->imm));
}

static __always_inline void
x86_vm_loop_prepare(struct x86_vm_loop_ctx *loop, void *data, void *data_end,
		    struct x86_vm_reg_save *save_rdi)
{
	loop->failed = 0;
	loop->done = 0;
	loop->next = 0;
	loop->rdi_written = 0;
	loop->data = data;
	loop->data_end = data_end;
	save_rdi->value = loop->state.rdi;
	save_rdi->ptr = loop->state.p_rdi;
	save_rdi->tag = loop->state.tag_rdi;
}

static __always_inline void
x86_vm_loop_restore_rdi(struct x86_vm_loop_ctx *loop,
			const struct x86_vm_reg_save *save_rdi)
{
	if (loop->rdi_written)
		return;
	loop->state.rdi = save_rdi->value;
	loop->state.p_rdi = save_rdi->ptr;
	loop->state.tag_rdi = save_rdi->tag;
}

#define X86_VM_LOOP_FAIL()                                                   \
	do {                                                                 \
		loop->failed = __LINE__;                                     \
		return 1;                                                    \
	} while (0)

#define X86_VM_LOOP_EXIT(NEXT)                                               \
	do {                                                                 \
		loop->next = (NEXT);                                        \
		return 1;                                                    \
	} while (0)

#define X86_VM_LOOP_RET()                                                    \
	do {                                                                 \
		loop->done = 1;                                            \
		return 1;                                                    \
	} while (0)

#define X86_VM_LOOP_OP(OP, DST, SRC, FLAGS, AUX, IMM)                      \
	do {                                                               \
		if (x86_vm_op_writes_reg((OP), (DST), (SRC), X86_RDI))     \
			loop->rdi_written = 1;                            \
		int __x86_vm_step_ret =                                    \
			X86_VM_EXEC(&__x86_vm_state, (OP), (DST), (SRC),   \
				     (FLAGS), (AUX), (IMM));                \
		if (__x86_vm_step_ret < 0)                                 \
			X86_VM_LOOP_FAIL();                                \
		if (__x86_vm_step_ret == X86_INTERP_DONE)                  \
			X86_VM_LOOP_RET();                                 \
	} while (0)

#define X86_VM_LOOP_CALL(FN)                                                 \
	do {                                                                 \
		loop->rdi_written = 1;                                      \
		if (FN(&__x86_vm_state, __x86_vm_data, __x86_vm_data_end) < \
		    0)                                                       \
			X86_VM_LOOP_FAIL();                                  \
	} while (0)

#define X86_VM_END_XDP()                                                    \
		int __x86_vm_xdp_ret = XDP_PASS;                         \
		if (__x86_vm_ret < 0 ||                                      \
		    x86_vm_write_result_u64(__x86_vm_data,                   \
					    __x86_vm_data_end,             \
					    __x86_vm_state.rax) < 0)       \
			__x86_vm_xdp_ret = XDP_ABORTED;                    \
		__x86_vm_xdp_ret;                                           \
	})

#define X86_VM_END_XDP_RET_RAX()                                            \
		int __x86_vm_xdp_ret = (__u32)__x86_vm_state.rax;          \
		if (__x86_vm_ret < 0)                                      \
			__x86_vm_xdp_ret = XDP_ABORTED;                    \
		__x86_vm_xdp_ret;                                           \
	})

#define X86_VM_LICENSE() char LICENSE[] SEC("license") = "GPL"

#endif
