#ifndef X86_SIM_BPF_HELPER_SELECTION_H
#define X86_SIM_BPF_HELPER_SELECTION_H

#include <linux/bpf.h>
#include <bpf_helpers.h>

#ifndef X86_SIM_ENABLE_PACKET_REG_FASTPATH
#define X86_SIM_ENABLE_PACKET_REG_FASTPATH 1
#endif

#include "x86_sim.h"

#define X86_SIM_OUTPUT_OFF 0U

#define X86_SIM_INSN(OP, DST, SRC, FLAGS, AUX, IMM)                         \
	((struct x86_insn){                                                 \
		.op = (OP),                                                 \
		.dst = (DST),                                               \
		.src = (SRC),                                               \
		.flags = (FLAGS),                                           \
		.aux = (AUX),                                               \
		.imm = (IMM),                                               \
	})

#define X86_SIM_LOAD_INSN(OP, DST, SRC, FLAGS, AUX, IMM)                    \
	do {                                                               \
		__x86_sim_insn.op = (OP);                                   \
		__x86_sim_insn.dst = (DST);                                 \
		__x86_sim_insn.src = (SRC);                                 \
		__x86_sim_insn.flags = (FLAGS);                             \
		__x86_sim_insn.aux = (AUX);                                 \
		__x86_sim_insn.imm = (IMM);                                 \
	} while (0)

#define X86_SIM_MEM_OP_SRC_BASE(OP)                                         \
	((OP) == X86_OP_MOV_LOAD || (OP) == X86_OP_MOVSX_LOAD ||           \
	 (OP) == X86_OP_ALU_MEM)

#define X86_SIM_MEM_OP_DST_BASE(OP)                                         \
	((OP) == X86_OP_MOV_STORE_IMM || (OP) == X86_OP_MOV_STORE_REG ||    \
	 (OP) == X86_OP_CMP_MEM_IMM || (OP) == X86_OP_TEST_MEM_IMM ||       \
	 (OP) == X86_OP_CMP_MEM_REG)

#define X86_SIM_MEM_BASE_REG(OP, DST, SRC)                                  \
	(X86_SIM_MEM_OP_SRC_BASE(OP) ? (SRC) :                              \
	 X86_SIM_MEM_OP_DST_BASE(OP) ? (DST) : X86_REG_NONE)

#define X86_SIM_PACKET_FASTPATH_CANDIDATE(OP, DST, SRC)                    \
	(X86_SIM_MEM_BASE_REG((OP), (DST), (SRC)) != X86_REG_NONE &&        \
	 X86_SIM_MEM_BASE_REG((OP), (DST), (SRC)) != X86_RDI &&             \
	 X86_SIM_MEM_BASE_REG((OP), (DST), (SRC)) != X86_RBP &&             \
	 X86_SIM_MEM_BASE_REG((OP), (DST), (SRC)) != X86_RSP)

#define X86_SIM_EXEC_PACKET(STATE, OP)                                      \
	({                                                                 \
		int __x86_sim_packet_ret = X86_SIM_UNSUPPORTED;                 \
		if ((OP) == X86_OP_MOV_LOAD || (OP) == X86_OP_MOVSX_LOAD)  \
			__x86_sim_packet_ret =                              \
				x86_exec_mov_load_packet((STATE),           \
							 &__x86_sim_insn,    \
							 __x86_sim_data,     \
							 __x86_sim_data_end);\
		else if ((OP) == X86_OP_MOV_STORE_IMM)                    \
			__x86_sim_packet_ret =                              \
				x86_exec_mov_store_imm_packet(               \
					(STATE), &__x86_sim_insn,              \
					__x86_sim_data, __x86_sim_data_end);    \
		else if ((OP) == X86_OP_MOV_STORE_REG)                    \
			__x86_sim_packet_ret =                              \
				x86_exec_mov_store_reg_packet(               \
					(STATE), &__x86_sim_insn,              \
					__x86_sim_data, __x86_sim_data_end);    \
		else if ((OP) == X86_OP_ALU_MEM)                          \
			__x86_sim_packet_ret =                              \
				x86_exec_alu_mem_packet((STATE),             \
							&__x86_sim_insn,      \
							__x86_sim_data,       \
							__x86_sim_data_end);  \
		else if ((OP) == X86_OP_CMP_MEM_IMM)                      \
			__x86_sim_packet_ret =                              \
				x86_exec_cmp_mem_imm_packet(                 \
					(STATE), &__x86_sim_insn,              \
					__x86_sim_data, __x86_sim_data_end);    \
		else if ((OP) == X86_OP_TEST_MEM_IMM)                     \
			__x86_sim_packet_ret =                              \
				x86_exec_test_mem_imm_packet(                \
					(STATE), &__x86_sim_insn,              \
					__x86_sim_data, __x86_sim_data_end);    \
		else if ((OP) == X86_OP_CMP_MEM_REG)                      \
			__x86_sim_packet_ret =                              \
				x86_exec_cmp_mem_reg_packet(                 \
					(STATE), &__x86_sim_insn,              \
					__x86_sim_data, __x86_sim_data_end);    \
		__x86_sim_packet_ret;                                      \
	})

#define X86_SIM_EXEC(STATE, OP, DST, SRC, FLAGS, AUX, IMM)                  \
	({                                                                 \
		X86_SIM_LOAD_INSN((OP), (DST), (SRC), (FLAGS), (AUX), (IMM)); \
		X86_SIM_PACKET_FASTPATH_CANDIDATE((OP), (DST), (SRC)) ?     \
			X86_SIM_EXEC_PACKET((STATE), (OP)) :                 \
			x86_exec_one((STATE), &__x86_sim_insn,               \
				     __x86_sim_data, __x86_sim_data_end);     \
	})

#define X86_SIM_EXEC_HELPER(HELPER, STATE, OP, DST, SRC, FLAGS, AUX, IMM)   \
	({                                                                 \
		X86_SIM_LOAD_INSN((OP), (DST), (SRC), (FLAGS), (AUX), (IMM)); \
		HELPER((STATE), &__x86_sim_insn, __x86_sim_data,              \
		       __x86_sim_data_end);                                  \
	})

static __always_inline int x86_sim_write_result_u64(void *data, void *data_end,
						   __u64 value)
{
	__u8 *p = data + X86_SIM_OUTPUT_OFF;

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

#define X86_SIM_BEGIN_XDP(CTX)                                               \
	({                                                                 \
		void *__x86_sim_ctx = (void *)(CTX);                         \
		void *__x86_sim_data = (void *)(long)(CTX)->data;            \
		void *__x86_sim_data_end = (void *)(long)(CTX)->data_end;    \
		struct x86_state __x86_sim_state = {};                       \
		struct x86_insn __x86_sim_insn = {};                         \
		x86_init_state(&__x86_sim_state, (void *)(CTX));             \
		int __x86_sim_ret = 0;

#define X86_SIM_DECLARE_XDP(CTX)                                             \
	void *__x86_sim_ctx = (void *)(CTX);                                     \
	void *__x86_sim_data = (void *)(long)(CTX)->data;                    \
	void *__x86_sim_data_end = (void *)(long)(CTX)->data_end;            \
	struct x86_state __x86_sim_state = {};                               \
	struct x86_insn __x86_sim_insn = {};                                 \
	x86_init_state(&__x86_sim_state, (void *)(CTX))

#define X86_SIM_STEP(OP, DST, SRC, FLAGS, AUX, IMM)                          \
		if (__x86_sim_ret == 0) {                                      \
			int __x86_sim_step_ret =                               \
				X86_SIM_EXEC(&__x86_sim_state, (OP), (DST),      \
					     (SRC), (FLAGS), (AUX), (IMM));    \
			if (__x86_sim_step_ret == X86_SIM_DONE)              \
				__x86_sim_ret = X86_SIM_DONE;                \
			else if (__x86_sim_step_ret < 0)                        \
				__x86_sim_ret = __x86_sim_step_ret;              \
		}

#define X86_SIM_STEP_OP(HELPER, OP, DST, SRC, FLAGS, AUX, IMM)              \
		if (__x86_sim_ret == 0) {                                      \
			int __x86_sim_step_ret =                               \
				X86_SIM_EXEC_HELPER(HELPER, &__x86_sim_state,    \
						   (OP), (DST), (SRC),        \
						   (FLAGS), (AUX), (IMM));    \
			if (__x86_sim_step_ret == X86_SIM_DONE)              \
				__x86_sim_ret = X86_SIM_DONE;                \
			else if (__x86_sim_step_ret < 0)                        \
				__x86_sim_ret = __x86_sim_step_ret;              \
		}

#define X86_SIM_RUN_STEP(OP, DST, SRC, FLAGS, AUX, IMM)                      \
	do {                                                               \
		int __x86_sim_step_ret =                                    \
			X86_SIM_EXEC(&__x86_sim_state, (OP), (DST), (SRC),    \
				     (FLAGS), (AUX), (IMM));                 \
		if (__x86_sim_step_ret < 0)                                 \
			X86_SIM_UNSUPPORTED_RETURN();                             \
		if (__x86_sim_step_ret == X86_SIM_DONE)                  \
			return (__u32)__x86_sim_state.rax;                  \
	} while (0)

#define X86_SIM_RUN_OP(HELPER, OP, DST, SRC, FLAGS, AUX, IMM)               \
	do {                                                               \
		x86_sim_prepare_ctx_output(&__x86_sim_state, __x86_sim_ctx,    \
					  (OP), (DST), (FLAGS), (IMM));      \
		int __x86_sim_step_ret =                                    \
			X86_SIM_EXEC_HELPER(HELPER, &__x86_sim_state, (OP),   \
					   (DST), (SRC), (FLAGS), (AUX),   \
					   (IMM));                         \
		if (__x86_sim_step_ret < 0)                                 \
			X86_SIM_UNSUPPORTED_RETURN();                             \
		if (__x86_sim_step_ret == X86_SIM_DONE)                  \
			return (__u32)__x86_sim_state.rax;                  \
	} while (0)

#define X86_SIM_RUN_CALL(FN)                                                 \
	do {                                                                 \
		if (FN(&__x86_sim_state, __x86_sim_data, __x86_sim_data_end) < \
		    0)                                                       \
			X86_SIM_UNSUPPORTED_RETURN();                                \
	} while (0)

#define X86_SIM_RUN_STEP_SUB(OP, DST, SRC, FLAGS, AUX, IMM)                  \
	do {                                                               \
		int __x86_sim_step_ret =                                    \
			X86_SIM_EXEC(&__x86_sim_state, (OP), (DST), (SRC),    \
				     (FLAGS), (AUX), (IMM));                 \
		if (__x86_sim_step_ret < 0)                                 \
			return X86_SIM_UNSUPPORTED;                            \
		if (__x86_sim_step_ret == X86_SIM_DONE)                  \
			return X86_SIM_CONTINUE;                        \
	} while (0)

#define X86_SIM_RUN_OP_SUB(HELPER, OP, DST, SRC, FLAGS, AUX, IMM)           \
	do {                                                               \
		int __x86_sim_step_ret =                                    \
			X86_SIM_EXEC_HELPER(HELPER, &__x86_sim_state, (OP),   \
					   (DST), (SRC), (FLAGS), (AUX),   \
					   (IMM));                         \
		if (__x86_sim_step_ret < 0)                                 \
			return X86_SIM_UNSUPPORTED;                            \
		if (__x86_sim_step_ret == X86_SIM_DONE)                  \
			return X86_SIM_CONTINUE;                        \
	} while (0)

static __always_inline __u32 x86_sim_ret_rax(struct x86_state *state)
{
	return (__u32)state->rax;
}

#define X86_SIM_UNSUPPORTED_RETURN() return XDP_ABORTED

#define X86_SIM_RET_RAX() return x86_sim_ret_rax(&__x86_sim_state)

struct x86_sim_loop_ctx {
	struct x86_state state;
	void *data;
	void *data_end;
	__u32 failed;
	__u32 done;
	__u32 next;
	__u32 rdi_written;
};

struct x86_sim_reg_save {
	__u64 value;
	void *ptr;
	__u8 tag;
};

static __always_inline int x86_sim_op_writes_reg(__u8 op, __u8 dst, __u8 src,
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

static __always_inline int x86_sim_is_ctx_output_store(__u8 op, __u8 dst,
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
x86_sim_prepare_ctx_output(struct x86_state *state, void *ctx, __u8 op,
			  __u8 dst, __u8 flags, __u64 imm)
{
	if (!x86_sim_is_ctx_output_store(op, dst, flags, imm))
		return;
	state->p_rdi = ctx;
	state->tag_rdi = X86_PTR_CTX;
}

static __always_inline int
x86_sim_read_packet_mem_value(struct x86_state *state, __u8 base_reg, __u32 aux,
			     __s64 disp, void *data, void *data_end,
			     __u8 width, __u64 *value)
{
	void *base = 0;
	__u8 tag = X86_PTR_NONE;

	if (x86_mem_offset(state, aux, disp, &disp) < 0)
		return X86_SIM_UNSUPPORTED;
	if (x86_read_ptr_reg(state, base_reg, &base, &tag) < 0)
		return X86_SIM_UNSUPPORTED;
	if (tag != X86_PTR_PACKET || !base)
		return X86_SIM_UNSUPPORTED;
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
		return X86_SIM_UNSUPPORTED;
	if (x86_read_ptr_reg(state, insn->src, &base, &tag) < 0)
		return X86_SIM_UNSUPPORTED;
	if (tag != X86_PTR_PACKET || !base)
		return X86_SIM_UNSUPPORTED;
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
		return X86_SIM_UNSUPPORTED;
	if (x86_sim_read_packet_mem_value(state, insn->src, insn->aux,
					 x86_simm(insn->imm), data, data_end,
					 width, &mem_value) < 0)
		return X86_SIM_UNSUPPORTED;
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

	if (x86_sim_read_packet_mem_value(state, insn->dst, insn->aux,
					 disp, data, data_end, insn->flags,
					 &lhs) < 0)
		return X86_SIM_UNSUPPORTED;
	if (insn->op == X86_OP_CMP_MEM_REG &&
	    x86_read_reg(state, insn->src, &rhs) < 0)
		return X86_SIM_UNSUPPORTED;
	if (insn->op == X86_OP_TEST_MEM_IMM) {
		x86_set_logic_flags(state, lhs & rhs, insn->flags);
		return X86_SIM_CONTINUE;
	}
	x86_set_sub_flags(state, lhs, rhs, lhs - rhs, insn->flags);
	return X86_SIM_CONTINUE;
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
		return X86_SIM_UNSUPPORTED;
	if (x86_read_ptr_reg(state, insn->dst, &base, &tag) < 0)
		return X86_SIM_UNSUPPORTED;
	if (tag != X86_PTR_PACKET || !base)
		return X86_SIM_UNSUPPORTED;
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
		return X86_SIM_UNSUPPORTED;
	if (x86_read_ptr_reg(state, insn->dst, &base, &tag) < 0)
		return X86_SIM_UNSUPPORTED;
	if (tag != X86_PTR_PACKET || !base)
		return X86_SIM_UNSUPPORTED;
	return x86_store_packet_imm(data, data_end, base, disp, insn->flags,
				    x86_store_imm_value(insn->imm));
}

static __always_inline void
x86_sim_loop_prepare(struct x86_sim_loop_ctx *loop, void *data, void *data_end,
		    struct x86_sim_reg_save *save_rdi)
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
x86_sim_loop_restore_rdi(struct x86_sim_loop_ctx *loop,
			const struct x86_sim_reg_save *save_rdi)
{
	if (loop->rdi_written)
		return;
	loop->state.rdi = save_rdi->value;
	loop->state.p_rdi = save_rdi->ptr;
	loop->state.tag_rdi = save_rdi->tag;
}

#define X86_SIM_LOOP_FAIL()                                                   \
	do {                                                                 \
		loop->failed = __LINE__;                                     \
		return 1;                                                    \
	} while (0)

#define X86_SIM_LOOP_EXIT(NEXT)                                               \
	do {                                                                 \
		loop->next = (NEXT);                                        \
		return 1;                                                    \
	} while (0)

#define X86_SIM_LOOP_RET()                                                    \
	do {                                                                 \
		loop->done = 1;                                            \
		return 1;                                                    \
	} while (0)

#define X86_SIM_LOOP_OP(HELPER, OP, DST, SRC, FLAGS, AUX, IMM)              \
	do {                                                               \
		if (x86_sim_op_writes_reg((OP), (DST), (SRC), X86_RDI))     \
			loop->rdi_written = 1;                            \
		int __x86_sim_step_ret =                                    \
			X86_SIM_EXEC_HELPER(HELPER, &__x86_sim_state, (OP),   \
					   (DST), (SRC), (FLAGS), (AUX),   \
					   (IMM));                         \
		if (__x86_sim_step_ret < 0)                                 \
			X86_SIM_LOOP_FAIL();                                \
		if (__x86_sim_step_ret == X86_SIM_DONE)                  \
			X86_SIM_LOOP_RET();                                 \
	} while (0)

#define X86_SIM_LOOP_CALL(FN)                                                 \
	do {                                                                 \
		loop->rdi_written = 1;                                      \
		if (FN(&__x86_sim_state, __x86_sim_data, __x86_sim_data_end) < \
		    0)                                                       \
			X86_SIM_LOOP_FAIL();                                  \
	} while (0)

#define X86_SIM_END_XDP()                                                    \
		int __x86_sim_xdp_ret = XDP_PASS;                         \
		if (__x86_sim_ret < 0 ||                                      \
		    x86_sim_write_result_u64(__x86_sim_data,                   \
					    __x86_sim_data_end,             \
					    __x86_sim_state.rax) < 0)       \
			__x86_sim_xdp_ret = XDP_ABORTED;                    \
		__x86_sim_xdp_ret;                                           \
	})

#define X86_SIM_END_XDP_RET_RAX()                                            \
		int __x86_sim_xdp_ret = (__u32)__x86_sim_state.rax;          \
		if (__x86_sim_ret < 0)                                      \
			__x86_sim_xdp_ret = XDP_ABORTED;                    \
		__x86_sim_xdp_ret;                                           \
	})

#define X86_SIM_LICENSE() char LICENSE[] SEC("license") = "GPL"

#endif
