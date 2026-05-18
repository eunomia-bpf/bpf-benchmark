#ifndef X86_VM_BPF_H
#define X86_VM_BPF_H

#include <linux/bpf.h>
#include <bpf_helpers.h>

#ifndef X86_VM_ENABLE_PACKET_REG_FASTPATH
#define X86_VM_ENABLE_PACKET_REG_FASTPATH 1
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

#define X86_VM_EXEC(STATE, OP, DST, SRC, FLAGS, AUX, IMM)                  \
	({                                                                 \
		X86_VM_LOAD_INSN((OP), (DST), (SRC), (FLAGS), (AUX), (IMM)); \
		x86_exec_one((STATE), &__x86_vm_insn, __x86_vm_data,        \
			     __x86_vm_data_end);                            \
	})

#define X86_VM_EXEC_HELPER(HELPER, STATE, OP, DST, SRC, FLAGS, AUX, IMM)   \
	({                                                                 \
		X86_VM_LOAD_INSN((OP), (DST), (SRC), (FLAGS), (AUX), (IMM)); \
		HELPER((STATE), &__x86_vm_insn, __x86_vm_data,              \
		       __x86_vm_data_end);                                  \
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

#define X86_VM_STEP_OP(HELPER, OP, DST, SRC, FLAGS, AUX, IMM)              \
		if (__x86_vm_ret == 0) {                                      \
			int __x86_vm_step_ret =                               \
				X86_VM_EXEC_HELPER(HELPER, &__x86_vm_state,    \
						   (OP), (DST), (SRC),        \
						   (FLAGS), (AUX), (IMM));    \
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

#define X86_VM_RUN_OP(HELPER, OP, DST, SRC, FLAGS, AUX, IMM)               \
	do {                                                               \
		x86_vm_prepare_ctx_output(&__x86_vm_state, __x86_vm_ctx,    \
					  (OP), (DST), (FLAGS), (IMM));      \
		int __x86_vm_step_ret =                                    \
			X86_VM_EXEC_HELPER(HELPER, &__x86_vm_state, (OP),   \
					   (DST), (SRC), (FLAGS), (AUX),   \
					   (IMM));                         \
		if (__x86_vm_step_ret < 0)                                 \
			X86_VM_TRAP_RETURN();                             \
		if (__x86_vm_step_ret == X86_INTERP_DONE)                  \
			return (__u32)__x86_vm_state.rax;                  \
	} while (0)

#define X86_VM_RUN_CALL(FN)                                                 \
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

#define X86_VM_RUN_OP_SUB(HELPER, OP, DST, SRC, FLAGS, AUX, IMM)           \
	do {                                                               \
		int __x86_vm_step_ret =                                    \
			X86_VM_EXEC_HELPER(HELPER, &__x86_vm_state, (OP),   \
					   (DST), (SRC), (FLAGS), (AUX),   \
					   (IMM));                         \
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

#define X86_VM_RET_RAX() return x86_vm_ret_rax(&__x86_vm_state)

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

#define X86_VM_LOOP_OP(HELPER, OP, DST, SRC, FLAGS, AUX, IMM)              \
	do {                                                               \
		if (x86_vm_op_writes_reg((OP), (DST), (SRC), X86_RDI))     \
			loop->rdi_written = 1;                            \
		int __x86_vm_step_ret =                                    \
			X86_VM_EXEC_HELPER(HELPER, &__x86_vm_state, (OP),   \
					   (DST), (SRC), (FLAGS), (AUX),   \
					   (IMM));                         \
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
