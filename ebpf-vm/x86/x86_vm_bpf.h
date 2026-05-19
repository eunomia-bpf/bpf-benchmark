#ifndef X86_VM_BPF_H
#define X86_VM_BPF_H

#include <linux/bpf.h>
#include <bpf_helpers.h>

#ifndef X86_VM_ENABLE_PACKET_REG_FASTPATH
#define X86_VM_ENABLE_PACKET_REG_FASTPATH 1
#endif

#ifndef X86_VM_ENABLE_INDEX_PACKET_PROMOTE
#define X86_VM_ENABLE_INDEX_PACKET_PROMOTE 1
#endif

#include "x86_interp.h"

#define X86_VM_OUTPUT_OFF 0U

#ifndef X86_VM_SUBFN_ATTR
#define X86_VM_SUBFN_ATTR __always_inline
#endif

static __u64 (*x86_vm_unreachable_trap)(void) = (void *)999999;

#define X86_VM_CONCAT2(A, B) A##B
#define X86_VM_CONCAT(A, B) X86_VM_CONCAT2(A, B)

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

#define X86_VM_PACKET_FASTPATH_CANDIDATE(OP, DST, SRC, AUX)               \
	(X86_VM_MEM_BASE_REG((OP), (DST), (SRC)) != X86_REG_NONE &&        \
	 X86_MEM_AUX_INDEX((AUX)) == X86_REG_NONE &&                       \
	 X86_VM_MEM_BASE_REG((OP), (DST), (SRC)) != X86_RDI &&             \
	 X86_VM_MEM_BASE_REG((OP), (DST), (SRC)) != X86_RSI &&             \
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

#define X86_VM_EXEC_TYPED(STATE, OP)                                       \
	({                                                                 \
		int __x86_vm_typed_ret = X86_INTERP_TRAP;                  \
		if ((OP) == X86_OP_NOP)                                   \
			__x86_vm_typed_ret =                              \
				x86_exec_nop((STATE), &__x86_vm_insn,     \
					     __x86_vm_data,                  \
					     __x86_vm_data_end);              \
		else if ((OP) == X86_OP_MOV_IMM)                          \
			__x86_vm_typed_ret =                              \
				x86_exec_mov_imm((STATE), &__x86_vm_insn, \
						 __x86_vm_data,          \
						 __x86_vm_data_end);      \
		else if ((OP) == X86_OP_MOV_REG)                          \
			__x86_vm_typed_ret =                              \
				x86_exec_mov_reg((STATE), &__x86_vm_insn, \
						 __x86_vm_data,          \
						 __x86_vm_data_end);      \
		else if ((OP) == X86_OP_MOVZX_REG)                        \
			__x86_vm_typed_ret =                              \
				x86_exec_movzx_reg((STATE),                 \
						   &__x86_vm_insn,          \
						   __x86_vm_data,           \
						   __x86_vm_data_end);       \
		else if ((OP) == X86_OP_MOVSX_REG)                        \
			__x86_vm_typed_ret =                              \
				x86_exec_movsx_reg((STATE),                 \
						   &__x86_vm_insn,          \
						   __x86_vm_data,           \
						   __x86_vm_data_end);       \
		else if ((OP) == X86_OP_MOV_LOAD)                         \
			__x86_vm_typed_ret =                              \
				x86_exec_mov_load((STATE), &__x86_vm_insn,\
						  __x86_vm_data,           \
						  __x86_vm_data_end);       \
		else if ((OP) == X86_OP_MOVSX_LOAD)                       \
			__x86_vm_typed_ret =                              \
				x86_exec_movsx_load((STATE),                \
						    &__x86_vm_insn,         \
						    __x86_vm_data,          \
						    __x86_vm_data_end);      \
		else if ((OP) == X86_OP_MOV_STORE_IMM)                    \
			__x86_vm_typed_ret =                              \
				x86_exec_mov_store_imm(                     \
					(STATE), &__x86_vm_insn,              \
					__x86_vm_data, __x86_vm_data_end);    \
		else if ((OP) == X86_OP_MOV_STORE_REG)                    \
			__x86_vm_typed_ret =                              \
				x86_exec_mov_store_reg(                     \
					(STATE), &__x86_vm_insn,              \
					__x86_vm_data, __x86_vm_data_end);    \
		else if ((OP) == X86_OP_LEA)                              \
			__x86_vm_typed_ret =                              \
				x86_exec_lea((STATE), &__x86_vm_insn,     \
					     __x86_vm_data,                  \
					     __x86_vm_data_end);              \
		else if ((OP) == X86_OP_ADD_IMM)                          \
			__x86_vm_typed_ret =                              \
				x86_exec_add_imm((STATE), &__x86_vm_insn, \
						 __x86_vm_data,          \
						 __x86_vm_data_end);      \
		else if ((OP) == X86_OP_ALU_IMM)                          \
			__x86_vm_typed_ret =                              \
				x86_exec_alu_imm((STATE), &__x86_vm_insn, \
						 __x86_vm_data,          \
						 __x86_vm_data_end);      \
		else if ((OP) == X86_OP_ALU_MEM)                          \
			__x86_vm_typed_ret =                              \
				x86_exec_alu_mem((STATE), &__x86_vm_insn, \
						 __x86_vm_data,          \
						 __x86_vm_data_end);      \
		else if ((OP) == X86_OP_ADD_REG)                          \
			__x86_vm_typed_ret =                              \
				x86_exec_add_reg((STATE), &__x86_vm_insn, \
						 __x86_vm_data,          \
						 __x86_vm_data_end);      \
		else if ((OP) == X86_OP_XOR_REG)                          \
			__x86_vm_typed_ret =                              \
				x86_exec_xor_reg((STATE), &__x86_vm_insn, \
						 __x86_vm_data,          \
						 __x86_vm_data_end);      \
		else if ((OP) == X86_OP_ALU_REG)                          \
			__x86_vm_typed_ret =                              \
				x86_exec_alu_reg((STATE), &__x86_vm_insn, \
						 __x86_vm_data,          \
						 __x86_vm_data_end);      \
		else if ((OP) == X86_OP_CMP_IMM)                          \
			__x86_vm_typed_ret =                              \
				x86_exec_cmp_imm((STATE), &__x86_vm_insn, \
						 __x86_vm_data,          \
						 __x86_vm_data_end);      \
		else if ((OP) == X86_OP_CMP_REG)                          \
			__x86_vm_typed_ret =                              \
				x86_exec_cmp_reg((STATE), &__x86_vm_insn, \
						 __x86_vm_data,          \
						 __x86_vm_data_end);      \
		else if ((OP) == X86_OP_CMP_MEM_IMM)                      \
			__x86_vm_typed_ret =                              \
				x86_exec_cmp_mem_imm(                       \
					(STATE), &__x86_vm_insn,              \
					__x86_vm_data, __x86_vm_data_end);    \
		else if ((OP) == X86_OP_CMP_MEM_REG)                      \
			__x86_vm_typed_ret =                              \
				x86_exec_cmp_mem_reg(                       \
					(STATE), &__x86_vm_insn,              \
					__x86_vm_data, __x86_vm_data_end);    \
		else if ((OP) == X86_OP_TEST_MEM_IMM)                     \
			__x86_vm_typed_ret =                              \
				x86_exec_test_mem_imm(                      \
					(STATE), &__x86_vm_insn,              \
					__x86_vm_data, __x86_vm_data_end);    \
		else if ((OP) == X86_OP_TEST_IMM)                         \
			__x86_vm_typed_ret =                              \
				x86_exec_test_imm((STATE), &__x86_vm_insn,\
						  __x86_vm_data,           \
						  __x86_vm_data_end);       \
		else if ((OP) == X86_OP_TEST_REG)                         \
			__x86_vm_typed_ret =                              \
				x86_exec_test_reg((STATE), &__x86_vm_insn,\
						  __x86_vm_data,           \
						  __x86_vm_data_end);       \
		else if ((OP) == X86_OP_CMOV)                             \
			__x86_vm_typed_ret =                              \
				x86_exec_cmov((STATE), &__x86_vm_insn,    \
					      __x86_vm_data,                 \
					      __x86_vm_data_end);             \
		else if ((OP) == X86_OP_SETCC)                            \
			__x86_vm_typed_ret =                              \
				x86_exec_setcc((STATE), &__x86_vm_insn,   \
					       __x86_vm_data,                \
					       __x86_vm_data_end);            \
		else if ((OP) == X86_OP_BSWAP)                            \
			__x86_vm_typed_ret =                              \
				x86_exec_bswap((STATE), &__x86_vm_insn,   \
					       __x86_vm_data,                \
					       __x86_vm_data_end);            \
		else if ((OP) == X86_OP_POPCNT)                           \
			__x86_vm_typed_ret =                              \
				x86_exec_popcnt((STATE), &__x86_vm_insn,  \
						__x86_vm_data,               \
						__x86_vm_data_end);           \
		else if ((OP) == X86_OP_XCHG)                             \
			__x86_vm_typed_ret =                              \
				x86_exec_xchg((STATE), &__x86_vm_insn,    \
					      __x86_vm_data,                 \
					      __x86_vm_data_end);             \
		else if ((OP) == X86_OP_JCC)                              \
			__x86_vm_typed_ret =                              \
				x86_exec_jcc((STATE), &__x86_vm_insn,     \
					     __x86_vm_data,                  \
					     __x86_vm_data_end);              \
		else if ((OP) == X86_OP_JMP)                              \
			__x86_vm_typed_ret =                              \
				x86_exec_jmp((STATE), &__x86_vm_insn,     \
					     __x86_vm_data,                  \
					     __x86_vm_data_end);              \
		else if ((OP) == X86_OP_CALL)                             \
			__x86_vm_typed_ret =                              \
				x86_exec_call((STATE), &__x86_vm_insn,    \
					      __x86_vm_data,                 \
					      __x86_vm_data_end);             \
		else if ((OP) == X86_OP_DIV)                              \
			__x86_vm_typed_ret =                              \
				x86_exec_div((STATE), &__x86_vm_insn,     \
					     __x86_vm_data,                  \
					     __x86_vm_data_end);              \
		else if ((OP) == X86_OP_SHLD_IMM)                         \
			__x86_vm_typed_ret =                              \
				x86_exec_shld_imm((STATE), &__x86_vm_insn,\
						  __x86_vm_data,           \
						  __x86_vm_data_end);       \
		else if ((OP) == X86_OP_SHRD_IMM)                         \
			__x86_vm_typed_ret =                              \
				x86_exec_shrd_imm((STATE), &__x86_vm_insn,\
						  __x86_vm_data,           \
						  __x86_vm_data_end);       \
		else if ((OP) == X86_OP_PUSH)                             \
			__x86_vm_typed_ret =                              \
				x86_exec_push((STATE), &__x86_vm_insn,    \
					      __x86_vm_data,                 \
					      __x86_vm_data_end);             \
		else if ((OP) == X86_OP_POP)                              \
			__x86_vm_typed_ret =                              \
				x86_exec_pop((STATE), &__x86_vm_insn,     \
					     __x86_vm_data,                  \
					     __x86_vm_data_end);              \
		else if ((OP) == X86_OP_RET)                              \
			__x86_vm_typed_ret =                              \
				x86_exec_ret((STATE), &__x86_vm_insn,     \
					     __x86_vm_data,                  \
					     __x86_vm_data_end);              \
		__x86_vm_typed_ret;                                      \
	})

#define X86_VM_EXEC(STATE, OP, DST, SRC, FLAGS, AUX, IMM)                  \
	({                                                                 \
		X86_VM_LOAD_INSN((OP), (DST), (SRC), (FLAGS), (AUX), (IMM)); \
		X86_VM_PACKET_FASTPATH_CANDIDATE((OP), (DST), (SRC),      \
						  (AUX)) ?                  \
			X86_VM_EXEC_PACKET((STATE), (OP)) :                 \
			X86_VM_EXEC_TYPED((STATE), (OP));                  \
	})

#define X86_VM_EXEC_SUB(STATE, OP, DST, SRC, FLAGS, AUX, IMM)              \
	({                                                                 \
		X86_VM_LOAD_INSN((OP), (DST), (SRC), (FLAGS), (AUX), (IMM)); \
		X86_VM_EXEC_TYPED((STATE), (OP));                           \
	})

static __always_inline int x86_vm_write_result_u64(void *data, void *data_end,
						   __u64 value)
{
	__u8 *p = data + X86_VM_OUTPUT_OFF;

	(void)data_end;
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
		if (x86_vm_call_enter(&__x86_vm_state) < 0)                  \
			X86_VM_TRAP_RETURN();                                \
		int __x86_vm_call_ret =                                    \
			FN(&__x86_vm_state, __x86_vm_data,                 \
			   __x86_vm_data_end);                              \
		if (__x86_vm_call_ret < 0)                                \
			X86_VM_TRAP_RETURN();                              \
		x86_vm_call_leave(&__x86_vm_state);                         \
	} while (0)

#define X86_VM_RUN_STEP_SUB(OP, DST, SRC, FLAGS, AUX, IMM)                  \
	do {                                                               \
		int __x86_vm_step_ret =                                    \
			X86_VM_EXEC_SUB(&__x86_vm_state, (OP), (DST),      \
					 (SRC), (FLAGS), (AUX), (IMM));    \
		if (__x86_vm_step_ret < 0)                                 \
			return X86_INTERP_TRAP;                            \
		if (__x86_vm_step_ret == X86_INTERP_DONE)                  \
			return X86_INTERP_CONTINUE;                        \
	} while (0)

#define X86_VM_RUN_OP_SUB(OP, DST, SRC, FLAGS, AUX, IMM)                   \
	do {                                                               \
		int __x86_vm_step_ret =                                    \
			X86_VM_EXEC_SUB(&__x86_vm_state, (OP), (DST),     \
					 (SRC), (FLAGS), (AUX), (IMM));   \
		if (__x86_vm_step_ret < 0)                                 \
			return X86_INTERP_TRAP;                            \
		if (__x86_vm_step_ret == X86_INTERP_DONE)                  \
			return X86_INTERP_CONTINUE;                        \
	} while (0)

static __always_inline __u32 x86_vm_ret_rax(struct x86_state *state)
{
	return (__u32)state->rax;
}

#define X86_VM_TRAP_RETURN() return (__u32)x86_vm_unreachable_trap()

#define X86_VM_X86_RET() return x86_vm_ret_rax(&__x86_vm_state)

#define X86_VM_X86_JMP(CURRENT, TARGET, LABEL)                              \
	do {                                                                 \
		(void)(CURRENT);                                             \
		(void)(TARGET);                                              \
		goto LABEL;                                                   \
	} while (0)

#define X86_VM_X86_JCC_BACKWARD(CC, LABEL, ID)                              \
	do {                                                                 \
		if (!x86_eval_cc(&__x86_vm_state, (CC))) {                    \
			goto X86_VM_CONCAT(__x86_vm_jcc_fallthrough_, ID);    \
		}                                                            \
		goto LABEL;                                                   \
X86_VM_CONCAT(__x86_vm_jcc_fallthrough_, ID):                               \
		;                                                            \
	} while (0)

#define X86_VM_X86_JCC_IMPL(CC, CURRENT, TARGET, LABEL, ID)                 \
	do {                                                                 \
		if ((TARGET) <= (CURRENT)) {                                  \
			X86_VM_X86_JCC_BACKWARD((CC), LABEL, ID);             \
		} else if (x86_eval_cc(&__x86_vm_state, (CC))) {              \
			X86_VM_X86_JMP((CURRENT), (TARGET), LABEL);           \
		}                                                            \
	} while (0)

#define X86_VM_X86_JCC(CC, CURRENT, TARGET, LABEL)                          \
	X86_VM_X86_JCC_IMPL((CC), (CURRENT), (TARGET), LABEL, __LINE__)

#define X86_VM_X86_SUB_JMP(CURRENT, TARGET, LABEL)                          \
	do {                                                                 \
		(void)(CURRENT);                                             \
		(void)(TARGET);                                              \
		goto LABEL;                                                   \
	} while (0)

#define X86_VM_X86_SUB_JCC_BACKWARD(CC, LABEL, ID)                          \
	do {                                                                 \
		if (!x86_eval_cc(&__x86_vm_state, (CC))) {                    \
			goto X86_VM_CONCAT(__x86_vm_sub_jcc_fallthrough_,     \
					   ID);                                  \
		}                                                            \
		goto LABEL;                                                   \
X86_VM_CONCAT(__x86_vm_sub_jcc_fallthrough_, ID):                           \
		;                                                            \
	} while (0)

#define X86_VM_X86_SUB_JCC_IMPL(CC, CURRENT, TARGET, LABEL, ID)             \
	do {                                                                 \
		if ((TARGET) <= (CURRENT)) {                                  \
			X86_VM_X86_SUB_JCC_BACKWARD((CC), LABEL, ID);         \
		} else if (x86_eval_cc(&__x86_vm_state, (CC))) {              \
			X86_VM_X86_SUB_JMP((CURRENT), (TARGET), LABEL);       \
		}                                                            \
	} while (0)

#define X86_VM_X86_SUB_JCC(CC, CURRENT, TARGET, LABEL)                      \
	X86_VM_X86_SUB_JCC_IMPL((CC), (CURRENT), (TARGET), LABEL, __LINE__)

static __always_inline int x86_vm_call_enter(struct x86_state *state)
{
#ifdef X86_VM_ENABLE_STACK
	state->rsp -= 8;
	return x86_stack_write_raw(state, (__s64)state->rsp, X86_WIDTH_64,
				   0, 0, X86_PTR_NONE);
#else
	return X86_INTERP_CONTINUE;
#endif
}

static __always_inline void x86_vm_call_leave(struct x86_state *state)
{
#ifdef X86_VM_ENABLE_STACK
	state->rsp += 8;
#else
	(void)state;
#endif
}

#define X86_VM_SUB_BEGIN()                                                  \
	struct x86_insn __x86_vm_insn = {}

#define X86_VM_X86_SUB_RET()                                                \
	do {                                                                 \
		return X86_INTERP_CONTINUE;                                  \
	} while (0)

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

static __always_inline int x86_vm_read_packet_value_proven(void *data,
							   void *data_end,
							   void *base,
							   __s32 base_off,
							   __s64 disp,
							   __u8 width,
							   __u64 *value)
{
	__u8 *addr;

	(void)data;
	(void)base_off;
	addr = (__u8 *)base + disp;
	(void)data_end;
	if (width == X86_WIDTH_8)
		*value = *(__u8 *)addr;
	else if (width == X86_WIDTH_16)
		*value = *(__u16 *)addr;
	else if (width == X86_WIDTH_32)
		*value = *(__u32 *)addr;
	else if (width == X86_WIDTH_64)
		*value = *(__u64 *)addr;
	else
		return X86_INTERP_TRAP;
	return X86_INTERP_CONTINUE;
}

static __always_inline int x86_vm_load_packet_proven(struct x86_state *state,
						     __u8 dst, void *data,
						     void *data_end, void *base,
						     __s32 base_off, __s64 disp,
						     __u8 load_width,
						     __u8 write_width,
						     __u8 sign_extend)
{
	__u64 value = 0;

	if (x86_vm_read_packet_value_proven(data, data_end, base, base_off, disp,
					    load_width, &value) < 0)
		return X86_INTERP_TRAP;
	if (sign_extend)
		value = x86_sign_extend(value, load_width);
	return x86_write_reg_width(state, dst, value, write_width);
}

static __always_inline int
x86_vm_read_packet_mem_value(struct x86_state *state, __u8 base_reg, __u32 aux,
			     __s64 disp, void *data, void *data_end,
			     __u8 width, __u64 *value)
{
	void *base = 0;
	__u8 tag = X86_PTR_NONE;
	__s32 base_off = 0;

	if (x86_mem_offset(state, aux, disp, &disp) < 0)
		return X86_INTERP_TRAP;
	if (x86_read_ptr_reg(state, base_reg, &base, &tag) < 0)
		return X86_INTERP_TRAP;
	if (tag != X86_PTR_PACKET)
		return X86_INTERP_TRAP;
	if (x86_read_ptr_off_reg(state, base_reg, &base_off) < 0)
		return X86_INTERP_TRAP;
	return x86_vm_read_packet_value_proven(data, data_end, base, base_off, disp,
					       width, value);
}

static __always_inline int
x86_exec_mov_load_packet(struct x86_state *state, const struct x86_insn *insn,
			 void *data, void *data_end)
{
	__u8 mem_width = X86_MEM_AUX_MEM_WIDTH(insn->aux);
	void *base = 0;
	__u8 tag = X86_PTR_NONE;
	__s64 disp = x86_simm(insn->imm);
	__s32 base_off = 0;

	if (!mem_width)
		mem_width = insn->flags;
	if (x86_mem_offset(state, insn->aux, disp, &disp) < 0)
		return X86_INTERP_TRAP;
	if (x86_read_ptr_reg(state, insn->src, &base, &tag) < 0)
		return X86_INTERP_TRAP;
	if (tag != X86_PTR_PACKET)
		return X86_INTERP_TRAP;
	if (x86_read_ptr_off_reg(state, insn->src, &base_off) < 0)
		return X86_INTERP_TRAP;
	return x86_vm_load_packet_proven(
		state, insn->dst, data, data_end, base, base_off, disp,
		mem_width, insn->flags, insn->op == X86_OP_MOVSX_LOAD);
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
	if (tag != X86_PTR_PACKET)
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
	if (tag != X86_PTR_PACKET)
		return X86_INTERP_TRAP;
	return x86_store_packet_imm(data, data_end, base, disp, insn->flags,
				    x86_store_imm_value(insn->imm));
}

#define X86_VM_END_XDP()                                                    \
		int __x86_vm_xdp_ret = XDP_PASS;                         \
		if (__x86_vm_ret < 0 ||                                      \
		    x86_vm_write_result_u64(__x86_vm_data,                   \
					    __x86_vm_data_end,             \
					    __x86_vm_state.rax) < 0)       \
			X86_VM_TRAP_RETURN();                              \
		__x86_vm_xdp_ret;                                           \
	})

#define X86_VM_END_XDP_RET_RAX()                                            \
		int __x86_vm_xdp_ret = (__u32)__x86_vm_state.rax;          \
		if (__x86_vm_ret < 0)                                      \
			X86_VM_TRAP_RETURN();                              \
		__x86_vm_xdp_ret;                                           \
	})

#define X86_VM_LICENSE() char LICENSE[] SEC("license") = "GPL"

#endif
