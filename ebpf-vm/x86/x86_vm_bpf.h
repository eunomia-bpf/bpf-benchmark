#ifndef X86_VM_BPF_H
#define X86_VM_BPF_H

#include <linux/bpf.h>
#include <bpf_helpers.h>

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
		void *__x86_vm_data = (void *)(long)(CTX)->data;            \
		void *__x86_vm_data_end = (void *)(long)(CTX)->data_end;    \
		struct x86_state __x86_vm_state = {};                       \
		struct x86_insn __x86_vm_insn = {};                         \
		x86_init_state(&__x86_vm_state, (void *)(CTX));             \
		int __x86_vm_ret = 0;

#define X86_VM_DECLARE_XDP(CTX)                                             \
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
		int __x86_vm_step_ret =                                    \
			X86_VM_EXEC_HELPER(HELPER, &__x86_vm_state, (OP),   \
					   (DST), (SRC), (FLAGS), (AUX),   \
					   (IMM));                         \
		if (__x86_vm_step_ret < 0)                                 \
			X86_VM_TRAP_RETURN();                             \
		if (__x86_vm_step_ret == X86_INTERP_DONE)                  \
			return (__u32)__x86_vm_state.rax;                  \
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

static __always_inline int
x86_vm_store_ctx_output32_imm(struct x86_state *state, void *data,
			      void *data_end, __u32 off, __u32 value)
{
	if (state->tag_rdi != X86_PTR_CTX || (off != 16 && off != 20))
		return X86_INTERP_TRAP;
	return x86_store_packet_imm(data, data_end, data, off == 16 ? 0 : 4,
				    X86_WIDTH_32, value);
}

static __always_inline int
x86_vm_store_ctx_output32_reg(struct x86_state *state, void *data,
			      void *data_end, __u8 src, __u32 off, __u32 aux)
{
	__u64 value = 0;
	__u8 src_shift = X86_REG_AUX_GET_SRC_SHIFT(aux);

	if (x86_read_reg(state, src, &value) < 0)
		return X86_INTERP_TRAP;
	if (src_shift != 0)
		value >>= src_shift;
	return x86_vm_store_ctx_output32_imm(state, data, data_end, off,
					     (__u32)value);
}

#define X86_VM_RUN_CTX_OUTPUT_IMM32(OFF, VALUE)                              \
	do {                                                                 \
		if (x86_vm_store_ctx_output32_imm(&__x86_vm_state,           \
						  __x86_vm_data,             \
						  __x86_vm_data_end,         \
						  (OFF), (VALUE)) < 0)       \
			X86_VM_TRAP_RETURN();                                 \
	} while (0)

#define X86_VM_RUN_CTX_OUTPUT_REG32(SRC, OFF, AUX)                           \
	do {                                                                 \
		if (x86_vm_store_ctx_output32_reg(&__x86_vm_state,           \
						  __x86_vm_data,             \
						  __x86_vm_data_end, (SRC),  \
						  (OFF), (AUX)) < 0)         \
			X86_VM_TRAP_RETURN();                                 \
	} while (0)

struct x86_vm_checksum_loop_ctx {
	struct x86_state state;
	void *data;
	void *data_end;
	__u32 inner;
	__u32 failed;
};

#define X86_VM_CHECKSUM_STEP(LOOP, HELPER, OP, DST, SRC, FLAGS, AUX, IMM)       \
	do {                                                                    \
		struct x86_insn __x86_checksum_insn = X86_VM_INSN(              \
			(OP), (DST), (SRC), (FLAGS), (AUX), (IMM));             \
		int __x86_checksum_ret = HELPER(&(LOOP)->state,              \
						&__x86_checksum_insn,       \
						(LOOP)->data,               \
						(LOOP)->data_end);          \
		if (__x86_checksum_ret != X86_INTERP_CONTINUE) {             \
			(LOOP)->failed = __LINE__;                           \
			return 1;                                             \
		}                                                               \
	} while (0)

#define X86_VM_CHECKSUM_LOAD_U16(LOOP, REG, PTR_REG, TAG_REG, OFF_EXPR)         \
	do {                                                                    \
		__u32 __packet_off = (OFF_EXPR);                                \
		if (__packet_off > 1038) {                                      \
			(LOOP)->failed = __LINE__;                              \
			return 1;                                               \
		}                                                               \
		__u8 *__packet_addr = (__u8 *)(LOOP)->data + __packet_off;      \
		if (__packet_addr + X86_WIDTH_16 > (__u8 *)(LOOP)->data_end) {  \
			(LOOP)->failed = __LINE__;                              \
			return 1;                                               \
		}                                                               \
		(LOOP)->state.REG = *(__u16 *)__packet_addr;                   \
		(LOOP)->state.PTR_REG = 0;                                     \
		(LOOP)->state.TAG_REG = X86_PTR_NONE;                          \
	} while (0)

static long x86_vm_packet_checksum_inner_cb(__u32 index, void *ctx)
{
	struct x86_vm_checksum_loop_ctx *loop = ctx;

	(void)index;
	if (loop->failed)
		return 1;
	if (loop->inner >= 256) {
		loop->failed = __LINE__;
		return 1;
	}
	loop->state.rcx = 19 + ((__u64)loop->inner << 2);
	loop->state.p_rcx = 0;
	loop->state.tag_rcx = X86_PTR_NONE;

	X86_VM_CHECKSUM_LOAD_U16(loop, r8, p_r8, tag_r8,
				 16 + (loop->inner << 2));
	X86_VM_CHECKSUM_STEP(loop, x86_exec_alu_reg, X86_OP_ALU_REG,
			     X86_R8, X86_RDI, X86_WIDTH_32, X86_ALU_ADD, 0);
	X86_VM_CHECKSUM_STEP(loop, x86_exec_movzx_reg, X86_OP_MOVZX_REG,
			     X86_RDI, X86_R8, X86_WIDTH_32, X86_WIDTH_16, 0);
	X86_VM_CHECKSUM_STEP(loop, x86_exec_alu_imm, X86_OP_ALU_IMM,
			     X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHR,
			     16);
	X86_VM_CHECKSUM_STEP(loop, x86_exec_alu_reg, X86_OP_ALU_REG,
			     X86_R8, X86_RDI, X86_WIDTH_32, X86_ALU_ADD, 0);
	X86_VM_CHECKSUM_LOAD_U16(loop, rdi, p_rdi, tag_rdi,
				 18 + (loop->inner << 2));
	X86_VM_CHECKSUM_STEP(loop, x86_exec_alu_reg, X86_OP_ALU_REG,
			     X86_RDI, X86_R8, X86_WIDTH_32, X86_ALU_ADD, 0);
	X86_VM_CHECKSUM_STEP(loop, x86_exec_movzx_reg, X86_OP_MOVZX_REG,
			     X86_R8, X86_RDI, X86_WIDTH_32, X86_WIDTH_16, 0);
	X86_VM_CHECKSUM_STEP(loop, x86_exec_alu_imm, X86_OP_ALU_IMM,
			     X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHR,
			     16);
	X86_VM_CHECKSUM_STEP(loop, x86_exec_alu_reg, X86_OP_ALU_REG,
			     X86_RDI, X86_R8, X86_WIDTH_32, X86_ALU_ADD, 0);
	X86_VM_CHECKSUM_STEP(loop, x86_exec_alu_imm, X86_OP_ALU_IMM,
			     X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD,
			     4);
	X86_VM_CHECKSUM_STEP(loop, x86_exec_cmp_imm, X86_OP_CMP_IMM,
			     X86_RCX, X86_REG_NONE, X86_WIDTH_64, 0, 1043);
	loop->inner++;
	return 0;
}

static long x86_vm_packet_checksum_outer_cb(__u32 index, void *ctx)
{
	struct x86_vm_checksum_loop_ctx *loop = ctx;

	(void)index;
	if (loop->failed)
		return 1;
	loop->inner = 0;
	X86_VM_CHECKSUM_STEP(loop, x86_exec_mov_imm, X86_OP_MOV_IMM,
			     X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 19);
	X86_VM_CHECKSUM_STEP(loop, x86_exec_alu_reg, X86_OP_ALU_REG,
			     X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR, 0);
	X86_VM_CHECKSUM_STEP(loop, x86_exec_nop, X86_OP_NOP,
			     X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, 0);
	if (bpf_loop(256, x86_vm_packet_checksum_inner_cb, loop, 0) < 0) {
		loop->failed = __LINE__;
		return 1;
	}
	if (loop->failed)
		return 1;
	X86_VM_CHECKSUM_STEP(loop, x86_exec_mov_reg, X86_OP_MOV_REG,
			     X86_RCX, X86_RDI, X86_WIDTH_32, 0, 0);
	X86_VM_CHECKSUM_STEP(loop, x86_exec_alu_imm, X86_OP_ALU_IMM,
			     X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHR,
			     16);
	X86_VM_CHECKSUM_STEP(loop, x86_exec_alu_reg, X86_OP_ALU_REG,
			     X86_RCX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD, 0);
	X86_VM_CHECKSUM_STEP(loop, x86_exec_alu_imm, X86_OP_ALU_IMM,
			     X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_NOT,
			     0);
	X86_VM_CHECKSUM_STEP(loop, x86_exec_movzx_reg, X86_OP_MOVZX_REG,
			     X86_RDI, X86_RCX, X86_WIDTH_64, X86_WIDTH_16, 0);
	X86_VM_CHECKSUM_STEP(loop, x86_exec_mov_reg, X86_OP_MOV_REG,
			     X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
	X86_VM_CHECKSUM_STEP(loop, x86_exec_alu_imm, X86_OP_ALU_IMM,
			     X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL,
			     4);
	X86_VM_CHECKSUM_STEP(loop, x86_exec_alu_reg, X86_OP_ALU_REG,
			     X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 0);
	X86_VM_CHECKSUM_STEP(loop, x86_exec_alu_reg, X86_OP_ALU_REG,
			     X86_RSI, X86_RDI, X86_WIDTH_64, X86_ALU_XOR, 0);
	X86_VM_CHECKSUM_STEP(loop, x86_exec_alu_imm, X86_OP_ALU_IMM,
			     X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_INC,
			     1);
	X86_VM_CHECKSUM_STEP(loop, x86_exec_cmp_imm, X86_OP_CMP_IMM,
			     X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 32);
	return 0;
}

static __always_inline int
x86_vm_run_packet_checksum_fold(struct x86_vm_checksum_loop_ctx *loop)
{
	if (bpf_loop(32, x86_vm_packet_checksum_outer_cb, loop, 0) < 0)
		return X86_INTERP_TRAP;
	if (loop->failed)
		return X86_INTERP_TRAP;
	return X86_INTERP_CONTINUE;
}

static long x86_vm_tc_checksum_inner_cb(__u32 index, void *ctx)
{
	struct x86_vm_checksum_loop_ctx *loop = ctx;

	(void)index;
	if (loop->failed)
		return 1;
	if (loop->inner >= 256) {
		loop->failed = __LINE__;
		return 1;
	}
	loop->state.rcx = (__u64)loop->inner << 1;
	loop->state.p_rcx = 0;
	loop->state.tag_rcx = X86_PTR_NONE;

	X86_VM_CHECKSUM_LOAD_U16(loop, r9, p_r9, tag_r9,
				 16 + (loop->inner << 2));
	X86_VM_CHECKSUM_STEP(loop, x86_exec_alu_reg, X86_OP_ALU_REG,
			     X86_R9, X86_R8, X86_WIDTH_32, X86_ALU_ADD, 0);
	X86_VM_CHECKSUM_STEP(loop, x86_exec_movzx_reg, X86_OP_MOVZX_REG,
			     X86_R8, X86_R9, X86_WIDTH_32, X86_WIDTH_16, 0);
	X86_VM_CHECKSUM_STEP(loop, x86_exec_alu_imm, X86_OP_ALU_IMM,
			     X86_R9, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHR,
			     16);
	X86_VM_CHECKSUM_STEP(loop, x86_exec_alu_reg, X86_OP_ALU_REG,
			     X86_R9, X86_R8, X86_WIDTH_32, X86_ALU_ADD, 0);
	X86_VM_CHECKSUM_LOAD_U16(loop, r8, p_r8, tag_r8,
				 18 + (loop->inner << 2));
	X86_VM_CHECKSUM_STEP(loop, x86_exec_alu_reg, X86_OP_ALU_REG,
			     X86_R8, X86_R9, X86_WIDTH_32, X86_ALU_ADD, 0);
	X86_VM_CHECKSUM_STEP(loop, x86_exec_movzx_reg, X86_OP_MOVZX_REG,
			     X86_R9, X86_R8, X86_WIDTH_32, X86_WIDTH_16, 0);
	X86_VM_CHECKSUM_STEP(loop, x86_exec_alu_imm, X86_OP_ALU_IMM,
			     X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHR,
			     16);
	X86_VM_CHECKSUM_STEP(loop, x86_exec_alu_reg, X86_OP_ALU_REG,
			     X86_R8, X86_R9, X86_WIDTH_32, X86_ALU_ADD, 0);
	X86_VM_CHECKSUM_STEP(loop, x86_exec_alu_imm, X86_OP_ALU_IMM,
			     X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD,
			     2);
	X86_VM_CHECKSUM_STEP(loop, x86_exec_cmp_imm, X86_OP_CMP_IMM,
			     X86_RCX, X86_REG_NONE, X86_WIDTH_64, 0, 512);
	loop->inner++;
	return 0;
}

static long x86_vm_tc_checksum_outer_cb(__u32 index, void *ctx)
{
	struct x86_vm_checksum_loop_ctx *loop = ctx;

	(void)index;
	if (loop->failed)
		return 1;
	loop->inner = 0;
	X86_VM_CHECKSUM_STEP(loop, x86_exec_alu_reg, X86_OP_ALU_REG,
			     X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
	X86_VM_CHECKSUM_STEP(loop, x86_exec_alu_reg, X86_OP_ALU_REG,
			     X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR, 0);
	if (bpf_loop(256, x86_vm_tc_checksum_inner_cb, loop, 0) < 0) {
		loop->failed = __LINE__;
		return 1;
	}
	if (loop->failed)
		return 1;
	X86_VM_CHECKSUM_STEP(loop, x86_exec_mov_reg, X86_OP_MOV_REG,
			     X86_RCX, X86_R8, X86_WIDTH_32, 0, 0);
	X86_VM_CHECKSUM_STEP(loop, x86_exec_alu_imm, X86_OP_ALU_IMM,
			     X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHR,
			     16);
	X86_VM_CHECKSUM_STEP(loop, x86_exec_alu_reg, X86_OP_ALU_REG,
			     X86_RCX, X86_R8, X86_WIDTH_32, X86_ALU_ADD, 0);
	X86_VM_CHECKSUM_STEP(loop, x86_exec_alu_imm, X86_OP_ALU_IMM,
			     X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_NOT,
			     0);
	X86_VM_CHECKSUM_STEP(loop, x86_exec_movzx_reg, X86_OP_MOVZX_REG,
			     X86_R8, X86_RCX, X86_WIDTH_32, X86_WIDTH_16, 0);
	X86_VM_CHECKSUM_STEP(loop, x86_exec_mov_reg, X86_OP_MOV_REG,
			     X86_RCX, X86_RSI, X86_WIDTH_32, 0, 0);
	X86_VM_CHECKSUM_STEP(loop, x86_exec_alu_imm, X86_OP_ALU_IMM,
			     X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL,
			     4);
	X86_VM_CHECKSUM_STEP(loop, x86_exec_alu_reg, X86_OP_ALU_REG,
			     X86_R8, X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 0);
	X86_VM_CHECKSUM_STEP(loop, x86_exec_alu_reg, X86_OP_ALU_REG,
			     X86_RDX, X86_R8, X86_WIDTH_64, X86_ALU_XOR, 0);
	X86_VM_CHECKSUM_STEP(loop, x86_exec_alu_imm, X86_OP_ALU_IMM,
			     X86_RSI, X86_REG_NONE, X86_WIDTH_32, X86_ALU_INC,
			     1);
	X86_VM_CHECKSUM_STEP(loop, x86_exec_cmp_imm, X86_OP_CMP_IMM,
			     X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 32);
	return 0;
}

static __always_inline int
x86_vm_run_tc_packet_checksum_fold(struct x86_vm_checksum_loop_ctx *loop)
{
	if (bpf_loop(32, x86_vm_tc_checksum_outer_cb, loop, 0) < 0)
		return X86_INTERP_TRAP;
	if (loop->failed)
		return X86_INTERP_TRAP;
	return X86_INTERP_CONTINUE;
}

struct x86_vm_bpftrace_scan_ctx {
	struct x86_state state;
	void *data;
	void *data_end;
	__u32 found;
	__u32 failed;
};

static __always_inline int
x86_vm_bpftrace_load_u8(struct x86_vm_bpftrace_scan_ctx *loop, __u32 off)
{
	__u8 *addr;

	if (off > 119) {
		loop->failed = __LINE__;
		return -1;
	}
	addr = (__u8 *)loop->data + off;
	if (addr + 1 > (__u8 *)loop->data_end) {
		loop->failed = __LINE__;
		return -1;
	}
	return *addr;
}

static long x86_vm_bpftrace_scan_cb(__u32 pos, void *ctx)
{
	struct x86_vm_bpftrace_scan_ctx *loop = ctx;
	__u32 needle_len = (__u32)loop->state.rsi;
	__u32 haystack_len = (__u32)loop->state.r9;
	__u32 diff;
	int hay;
	int needle;

	if (loop->failed || loop->found != 96)
		return 1;
	if (pos >= 89) {
		loop->failed = __LINE__;
		return 1;
	}
	loop->state.r8 = pos;
	if (pos + needle_len > haystack_len)
		goto no_match;

	hay = x86_vm_bpftrace_load_u8(loop, 16 + pos);
	needle = x86_vm_bpftrace_load_u8(loop, 112);
	if (hay < 0 || needle < 0)
		return 1;
	diff = hay ^ needle;
	if (needle_len >= 2) {
		hay = x86_vm_bpftrace_load_u8(loop, 17 + pos);
		needle = x86_vm_bpftrace_load_u8(loop, 113);
		if (hay < 0 || needle < 0)
			return 1;
		diff |= hay ^ needle;
	}
	if (needle_len >= 3) {
		hay = x86_vm_bpftrace_load_u8(loop, 18 + pos);
		needle = x86_vm_bpftrace_load_u8(loop, 114);
		if (hay < 0 || needle < 0)
			return 1;
		diff |= hay ^ needle;
	}
	if (needle_len >= 4) {
		hay = x86_vm_bpftrace_load_u8(loop, 19 + pos);
		needle = x86_vm_bpftrace_load_u8(loop, 115);
		if (hay < 0 || needle < 0)
			return 1;
		diff |= hay ^ needle;
	}
	if (needle_len >= 5) {
		hay = x86_vm_bpftrace_load_u8(loop, 20 + pos);
		needle = x86_vm_bpftrace_load_u8(loop, 116);
		if (hay < 0 || needle < 0)
			return 1;
		diff |= hay ^ needle;
	}
	if (needle_len >= 6) {
		hay = x86_vm_bpftrace_load_u8(loop, 21 + pos);
		needle = x86_vm_bpftrace_load_u8(loop, 117);
		if (hay < 0 || needle < 0)
			return 1;
		diff |= hay ^ needle;
	}
	if (needle_len >= 7) {
		hay = x86_vm_bpftrace_load_u8(loop, 22 + pos);
		needle = x86_vm_bpftrace_load_u8(loop, 118);
		if (hay < 0 || needle < 0)
			return 1;
		diff |= hay ^ needle;
	}
	if (needle_len >= 8) {
		hay = x86_vm_bpftrace_load_u8(loop, 23 + pos);
		needle = x86_vm_bpftrace_load_u8(loop, 119);
		if (hay < 0 || needle < 0)
			return 1;
		diff |= hay ^ needle;
	}
	loop->state.r11 = diff;
	if (diff == 0) {
		loop->found = pos;
		return 1;
	}

no_match:
	loop->state.r8 = pos + 1;
	loop->state.rdi += loop->state.r10;
	return loop->state.r8 == 89;
}

static __always_inline int
x86_vm_run_bpftrace_string_search_prefix_scan(
	struct x86_vm_bpftrace_scan_ctx *loop)
{
	__u64 packed;

	loop->found = 96;
	loop->failed = 0;
	if (bpf_loop(89, x86_vm_bpftrace_scan_cb, loop, 0) < 0)
		return X86_INTERP_TRAP;
	if (loop->failed)
		return X86_INTERP_TRAP;
	if (loop->found == 96)
		return X86_INTERP_CONTINUE;

	loop->state.r8 = loop->found;
	packed = ((loop->state.rsi & 0xffffffffULL) << 32) | loop->found;
	loop->state.rsi = (packed << 3) | (packed >> 61);
	loop->state.rdi ^= loop->state.rsi;
	loop->state.rax = loop->state.rdi;
	return X86_INTERP_CONTINUE;
}

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
