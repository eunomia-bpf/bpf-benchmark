#ifndef X86_SIM_BPF_H
#define X86_SIM_BPF_H

#include <linux/bpf.h>
#include <bpf_helpers.h>

#ifndef X86_SIM_ENABLE_PACKET_REG_FASTPATH
#define X86_SIM_ENABLE_PACKET_REG_FASTPATH 1
#endif

#ifndef X86_SIM_ENABLE_INDEX_PACKET_PROMOTE
#define X86_SIM_ENABLE_INDEX_PACKET_PROMOTE 1
#endif

#include "x86_sim.h"

#define X86_SIM_OUTPUT_OFF 0U

#ifndef X86_SIM_SUBFN_ATTR
#define X86_SIM_SUBFN_ATTR __always_inline
#endif

#define X86_SIM_CONCAT2(A, B) A##B
#define X86_SIM_CONCAT(A, B) X86_SIM_CONCAT2(A, B)

#define X86_SIM_INSN(OP, DST, SRC, FLAGS, AUX, IMM)                         \
	((struct x86_insn){                                                 \
		.op = (OP),                                                 \
		.dst = (DST),                                               \
		.src = (SRC),                                               \
		.flags = (FLAGS),                                           \
		.aux = (AUX),                                               \
		.imm = (IMM),                                               \
	})

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

#define X86_SIM_PACKET_FASTPATH_CANDIDATE(OP, DST, SRC, AUX)               \
	(X86_SIM_MEM_BASE_REG((OP), (DST), (SRC)) != X86_REG_NONE &&        \
	 X86_MEM_AUX_INDEX((AUX)) == X86_REG_NONE &&                       \
	 X86_SIM_MEM_BASE_REG((OP), (DST), (SRC)) != X86_RDI &&             \
	 X86_SIM_MEM_BASE_REG((OP), (DST), (SRC)) != X86_RSI &&             \
	 X86_SIM_MEM_BASE_REG((OP), (DST), (SRC)) != X86_RBP &&             \
	 X86_SIM_MEM_BASE_REG((OP), (DST), (SRC)) != X86_RSP)

#define X86_SIM_OP_IS_KNOWN(OP)                                            \
	((OP) == X86_OP_NOP || (OP) == X86_OP_MOV_IMM ||                  \
	 (OP) == X86_OP_MOV_REG || (OP) == X86_OP_MOVZX_REG ||            \
	 (OP) == X86_OP_MOVSX_REG || (OP) == X86_OP_MOV_LOAD ||           \
	 (OP) == X86_OP_MOVSX_LOAD || (OP) == X86_OP_MOV_STORE_IMM ||     \
	 (OP) == X86_OP_MOV_STORE_REG || (OP) == X86_OP_LEA ||            \
	 (OP) == X86_OP_ADD_IMM || (OP) == X86_OP_ALU_IMM ||              \
	 (OP) == X86_OP_ALU_MEM || (OP) == X86_OP_ADD_REG ||              \
	 (OP) == X86_OP_XOR_REG || (OP) == X86_OP_ALU_REG ||              \
	 (OP) == X86_OP_CMP_IMM || (OP) == X86_OP_CMP_REG ||              \
	 (OP) == X86_OP_CMP_MEM_IMM || (OP) == X86_OP_CMP_MEM_REG ||      \
	 (OP) == X86_OP_TEST_MEM_IMM || (OP) == X86_OP_TEST_IMM ||         \
	 (OP) == X86_OP_TEST_REG || (OP) == X86_OP_CMOV ||                \
	 (OP) == X86_OP_SETCC || (OP) == X86_OP_BSWAP ||                  \
	 (OP) == X86_OP_POPCNT || (OP) == X86_OP_XCHG ||                  \
	 (OP) == X86_OP_DIV ||                                            \
	 (OP) == X86_OP_SHLD_IMM || (OP) == X86_OP_SHRD_IMM ||            \
	 (OP) == X86_OP_PUSH || (OP) == X86_OP_POP)

#define X86_SIM_REQUIRE_KNOWN_OP(OP)                                        \
	_Static_assert(X86_SIM_OP_IS_KNOWN(OP), "unknown x86 simulator op")

#ifdef X86_SIM_ENABLE_STACK
#define X86_SIM_REQUIRE_STACK_OP(OP) ((void)0)
#define X86_SIM_REQUIRE_STACK_CALL() ((void)0)
#else
#define X86_SIM_REQUIRE_STACK_OP(OP)                                        \
	_Static_assert((OP) != X86_OP_PUSH && (OP) != X86_OP_POP,          \
		       "x86 stack instruction requires X86_SIM_ENABLE_STACK")
#define X86_SIM_REQUIRE_STACK_CALL()                                        \
	_Static_assert(0, "x86 call requires X86_SIM_ENABLE_STACK")
#endif

#define X86_SIM_EXEC_PACKET(STATE, OP)                                      \
	({                                                                 \
		int __x86_sim_packet_ret = X86_SIM_CONTINUE;             \
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

#define X86_SIM_EXEC_TYPED(STATE, OP)                                       \
	({                                                                 \
		int __x86_sim_typed_ret = X86_SIM_CONTINUE;              \
		if ((OP) == X86_OP_NOP)                                   \
			__x86_sim_typed_ret =                              \
				x86_exec_nop((STATE), &__x86_sim_insn,     \
					     __x86_sim_data,                  \
					     __x86_sim_data_end);              \
		else if ((OP) == X86_OP_MOV_IMM)                          \
			__x86_sim_typed_ret =                              \
				x86_exec_mov_imm((STATE), &__x86_sim_insn, \
						 __x86_sim_data,          \
						 __x86_sim_data_end);      \
		else if ((OP) == X86_OP_MOV_REG)                          \
			__x86_sim_typed_ret =                              \
				x86_exec_mov_reg((STATE), &__x86_sim_insn, \
						 __x86_sim_data,          \
						 __x86_sim_data_end);      \
		else if ((OP) == X86_OP_MOVZX_REG)                        \
			__x86_sim_typed_ret =                              \
				x86_exec_movzx_reg((STATE),                 \
						   &__x86_sim_insn,          \
						   __x86_sim_data,           \
						   __x86_sim_data_end);       \
		else if ((OP) == X86_OP_MOVSX_REG)                        \
			__x86_sim_typed_ret =                              \
				x86_exec_movsx_reg((STATE),                 \
						   &__x86_sim_insn,          \
						   __x86_sim_data,           \
						   __x86_sim_data_end);       \
		else if ((OP) == X86_OP_MOV_LOAD)                         \
			__x86_sim_typed_ret =                              \
				x86_exec_mov_load((STATE), &__x86_sim_insn,\
						  __x86_sim_data,           \
						  __x86_sim_data_end);       \
		else if ((OP) == X86_OP_MOVSX_LOAD)                       \
			__x86_sim_typed_ret =                              \
				x86_exec_movsx_load((STATE),                \
						    &__x86_sim_insn,         \
						    __x86_sim_data,          \
						    __x86_sim_data_end);      \
		else if ((OP) == X86_OP_MOV_STORE_IMM)                    \
			__x86_sim_typed_ret =                              \
				x86_exec_mov_store_imm(                     \
					(STATE), &__x86_sim_insn,              \
					__x86_sim_data, __x86_sim_data_end);    \
		else if ((OP) == X86_OP_MOV_STORE_REG)                    \
			__x86_sim_typed_ret =                              \
				x86_exec_mov_store_reg(                     \
					(STATE), &__x86_sim_insn,              \
					__x86_sim_data, __x86_sim_data_end);    \
		else if ((OP) == X86_OP_LEA)                              \
			__x86_sim_typed_ret =                              \
				x86_exec_lea((STATE), &__x86_sim_insn,     \
					     __x86_sim_data,                  \
					     __x86_sim_data_end);              \
		else if ((OP) == X86_OP_ADD_IMM)                          \
			__x86_sim_typed_ret =                              \
				x86_exec_add_imm((STATE), &__x86_sim_insn, \
						 __x86_sim_data,          \
						 __x86_sim_data_end);      \
		else if ((OP) == X86_OP_ALU_IMM)                          \
			__x86_sim_typed_ret =                              \
				x86_exec_alu_imm((STATE), &__x86_sim_insn, \
						 __x86_sim_data,          \
						 __x86_sim_data_end);      \
		else if ((OP) == X86_OP_ALU_MEM)                          \
			__x86_sim_typed_ret =                              \
				x86_exec_alu_mem((STATE), &__x86_sim_insn, \
						 __x86_sim_data,          \
						 __x86_sim_data_end);      \
		else if ((OP) == X86_OP_ADD_REG)                          \
			__x86_sim_typed_ret =                              \
				x86_exec_add_reg((STATE), &__x86_sim_insn, \
						 __x86_sim_data,          \
						 __x86_sim_data_end);      \
		else if ((OP) == X86_OP_XOR_REG)                          \
			__x86_sim_typed_ret =                              \
				x86_exec_xor_reg((STATE), &__x86_sim_insn, \
						 __x86_sim_data,          \
						 __x86_sim_data_end);      \
		else if ((OP) == X86_OP_ALU_REG)                          \
			__x86_sim_typed_ret =                              \
				x86_exec_alu_reg((STATE), &__x86_sim_insn, \
						 __x86_sim_data,          \
						 __x86_sim_data_end);      \
		else if ((OP) == X86_OP_CMP_IMM)                          \
			__x86_sim_typed_ret =                              \
				x86_exec_cmp_imm((STATE), &__x86_sim_insn, \
						 __x86_sim_data,          \
						 __x86_sim_data_end);      \
		else if ((OP) == X86_OP_CMP_REG)                          \
			__x86_sim_typed_ret =                              \
				x86_exec_cmp_reg((STATE), &__x86_sim_insn, \
						 __x86_sim_data,          \
						 __x86_sim_data_end);      \
		else if ((OP) == X86_OP_CMP_MEM_IMM)                      \
			__x86_sim_typed_ret =                              \
				x86_exec_cmp_mem_imm(                       \
					(STATE), &__x86_sim_insn,              \
					__x86_sim_data, __x86_sim_data_end);    \
		else if ((OP) == X86_OP_CMP_MEM_REG)                      \
			__x86_sim_typed_ret =                              \
				x86_exec_cmp_mem_reg(                       \
					(STATE), &__x86_sim_insn,              \
					__x86_sim_data, __x86_sim_data_end);    \
		else if ((OP) == X86_OP_TEST_MEM_IMM)                     \
			__x86_sim_typed_ret =                              \
				x86_exec_test_mem_imm(                      \
					(STATE), &__x86_sim_insn,              \
					__x86_sim_data, __x86_sim_data_end);    \
		else if ((OP) == X86_OP_TEST_IMM)                         \
			__x86_sim_typed_ret =                              \
				x86_exec_test_imm((STATE), &__x86_sim_insn,\
						  __x86_sim_data,           \
						  __x86_sim_data_end);       \
		else if ((OP) == X86_OP_TEST_REG)                         \
			__x86_sim_typed_ret =                              \
				x86_exec_test_reg((STATE), &__x86_sim_insn,\
						  __x86_sim_data,           \
						  __x86_sim_data_end);       \
		else if ((OP) == X86_OP_CMOV)                             \
			__x86_sim_typed_ret =                              \
				x86_exec_cmov((STATE), &__x86_sim_insn,    \
					      __x86_sim_data,                 \
					      __x86_sim_data_end);             \
		else if ((OP) == X86_OP_SETCC)                            \
			__x86_sim_typed_ret =                              \
				x86_exec_setcc((STATE), &__x86_sim_insn,   \
					       __x86_sim_data,                \
					       __x86_sim_data_end);            \
		else if ((OP) == X86_OP_BSWAP)                            \
			__x86_sim_typed_ret =                              \
				x86_exec_bswap((STATE), &__x86_sim_insn,   \
					       __x86_sim_data,                \
					       __x86_sim_data_end);            \
		else if ((OP) == X86_OP_POPCNT)                           \
			__x86_sim_typed_ret =                              \
				x86_exec_popcnt((STATE), &__x86_sim_insn,  \
						__x86_sim_data,               \
						__x86_sim_data_end);           \
		else if ((OP) == X86_OP_XCHG)                             \
			__x86_sim_typed_ret =                              \
				x86_exec_xchg((STATE), &__x86_sim_insn,    \
					      __x86_sim_data,                 \
					      __x86_sim_data_end);             \
		else if ((OP) == X86_OP_DIV)                              \
			__x86_sim_typed_ret =                              \
				x86_exec_div((STATE), &__x86_sim_insn,     \
					     __x86_sim_data,                  \
					     __x86_sim_data_end);              \
		else if ((OP) == X86_OP_SHLD_IMM)                         \
			__x86_sim_typed_ret =                              \
				x86_exec_shld_imm((STATE), &__x86_sim_insn,\
						  __x86_sim_data,           \
						  __x86_sim_data_end);       \
		else if ((OP) == X86_OP_SHRD_IMM)                         \
			__x86_sim_typed_ret =                              \
				x86_exec_shrd_imm((STATE), &__x86_sim_insn,\
						  __x86_sim_data,           \
						  __x86_sim_data_end);       \
		else if ((OP) == X86_OP_PUSH)                             \
			__x86_sim_typed_ret =                              \
				x86_exec_push((STATE), &__x86_sim_insn,    \
					      __x86_sim_data,                 \
					      __x86_sim_data_end);             \
		else if ((OP) == X86_OP_POP)                              \
			__x86_sim_typed_ret =                              \
				x86_exec_pop((STATE), &__x86_sim_insn,     \
					     __x86_sim_data,                  \
					     __x86_sim_data_end);              \
		__x86_sim_typed_ret;                                      \
	})

#define X86_SIM_EXEC(STATE, OP, DST, SRC, FLAGS, AUX, IMM)                  \
	({                                                                 \
		const struct x86_insn __x86_sim_insn =                    \
			X86_SIM_INSN((OP), (DST), (SRC), (FLAGS), (AUX),   \
				     (IMM));                                \
		X86_SIM_REQUIRE_KNOWN_OP(OP);                              \
		X86_SIM_REQUIRE_STACK_OP(OP);                              \
		X86_SIM_PACKET_FASTPATH_CANDIDATE((OP), (DST), (SRC),      \
						  (AUX)) ?                  \
			X86_SIM_EXEC_PACKET((STATE), (OP)) :                 \
			X86_SIM_EXEC_TYPED((STATE), (OP));                  \
	})

#define X86_SIM_EXEC_SUB(STATE, OP, DST, SRC, FLAGS, AUX, IMM)              \
	({                                                                 \
		const struct x86_insn __x86_sim_insn =                    \
			X86_SIM_INSN((OP), (DST), (SRC), (FLAGS), (AUX),   \
				     (IMM));                                \
		X86_SIM_REQUIRE_KNOWN_OP(OP);                              \
		X86_SIM_REQUIRE_STACK_OP(OP);                              \
		X86_SIM_EXEC_TYPED((STATE), (OP));                           \
	})

#define X86_SIM_DECLARE_XDP(CTX)                                             \
	void *__x86_sim_ctx = (void *)(CTX);                                     \
	void *__x86_sim_data = (void *)(long)(CTX)->data;                    \
	void *__x86_sim_data_end = (void *)(long)(CTX)->data_end;            \
	struct x86_state __x86_sim_state = {};                               \
	x86_init_state(&__x86_sim_state, (void *)(CTX))

#define X86_SIM_RUN_OP(OP, DST, SRC, FLAGS, AUX, IMM)                       \
	do {                                                               \
		X86_SIM_EXEC(&__x86_sim_state, (OP), (DST), (SRC),        \
			     (FLAGS), (AUX), (IMM));                         \
	} while (0)

#define X86_SIM_X86_CALL(FN, RETURN_ADDR)                                    \
	do {                                                                 \
		X86_SIM_REQUIRE_STACK_CALL();                                \
		x86_sim_call_enter(&__x86_sim_state, (RETURN_ADDR));         \
		FN(&__x86_sim_state, __x86_sim_data, __x86_sim_data_end);    \
	} while (0)

#define X86_SIM_RUN_OP_SUB(OP, DST, SRC, FLAGS, AUX, IMM)                   \
	do {                                                               \
		X86_SIM_EXEC_SUB(&__x86_sim_state, (OP), (DST), (SRC),    \
				 (FLAGS), (AUX), (IMM));                     \
	} while (0)

static __always_inline __u32 x86_sim_ret_rax(struct x86_state *state)
{
	return (__u32)state->rax;
}

#define X86_SIM_X86_RET() return x86_sim_ret_rax(&__x86_sim_state)

#define X86_SIM_X86_JMP(CURRENT, TARGET, LABEL)                              \
	do {                                                                 \
		(void)(CURRENT);                                             \
		(void)(TARGET);                                              \
		goto LABEL;                                                   \
	} while (0)

#define X86_SIM_X86_JCC_BACKWARD(CC, LABEL, ID)                              \
	do {                                                                 \
		if (!x86_eval_cc(&__x86_sim_state, (CC))) {                    \
			goto X86_SIM_CONCAT(__x86_sim_jcc_fallthrough_, ID);    \
		}                                                            \
		goto LABEL;                                                   \
X86_SIM_CONCAT(__x86_sim_jcc_fallthrough_, ID):                               \
		;                                                            \
	} while (0)

#define X86_SIM_X86_JCC_IMPL(CC, CURRENT, TARGET, LABEL, ID)                 \
	do {                                                                 \
		if ((TARGET) <= (CURRENT)) {                                  \
			X86_SIM_X86_JCC_BACKWARD((CC), LABEL, ID);             \
		} else if (x86_eval_cc(&__x86_sim_state, (CC))) {              \
			X86_SIM_X86_JMP((CURRENT), (TARGET), LABEL);           \
		}                                                            \
	} while (0)

#define X86_SIM_X86_JCC(CC, CURRENT, TARGET, LABEL)                          \
	X86_SIM_X86_JCC_IMPL((CC), (CURRENT), (TARGET), LABEL, __LINE__)

#define X86_SIM_X86_SUB_JMP(CURRENT, TARGET, LABEL)                          \
	do {                                                                 \
		(void)(CURRENT);                                             \
		(void)(TARGET);                                              \
		goto LABEL;                                                   \
	} while (0)

#define X86_SIM_X86_SUB_JCC_BACKWARD(CC, LABEL, ID)                          \
	do {                                                                 \
		if (!x86_eval_cc(&__x86_sim_state, (CC))) {                    \
			goto X86_SIM_CONCAT(__x86_sim_sub_jcc_fallthrough_,     \
					   ID);                                  \
		}                                                            \
		goto LABEL;                                                   \
X86_SIM_CONCAT(__x86_sim_sub_jcc_fallthrough_, ID):                           \
		;                                                            \
	} while (0)

#define X86_SIM_X86_SUB_JCC_IMPL(CC, CURRENT, TARGET, LABEL, ID)             \
	do {                                                                 \
		if ((TARGET) <= (CURRENT)) {                                  \
			X86_SIM_X86_SUB_JCC_BACKWARD((CC), LABEL, ID);         \
		} else if (x86_eval_cc(&__x86_sim_state, (CC))) {              \
			X86_SIM_X86_SUB_JMP((CURRENT), (TARGET), LABEL);       \
		}                                                            \
	} while (0)

#define X86_SIM_X86_SUB_JCC(CC, CURRENT, TARGET, LABEL)                      \
	X86_SIM_X86_SUB_JCC_IMPL((CC), (CURRENT), (TARGET), LABEL, __LINE__)

static __always_inline int x86_sim_call_enter(struct x86_state *state,
					      __u64 return_addr)
{
#ifdef X86_SIM_ENABLE_STACK
	state->rsp -= 8;
	return x86_stack_write_raw(state, (__s64)state->rsp, X86_WIDTH_64,
				   return_addr);
#else
	(void)state;
	(void)return_addr;
	__builtin_unreachable();
#endif
}

static __always_inline void x86_sim_ret_pop(struct x86_state *state)
{
#ifdef X86_SIM_ENABLE_STACK
	__u64 return_addr = 0;

	x86_stack_read_raw(state, (__s64)state->rsp, X86_WIDTH_64,
			   &return_addr);
	state->rsp += 8;
#else
	(void)state;
#endif
}

#define X86_SIM_SUB_BEGIN() ((void)0)

#define X86_SIM_X86_SUB_RET()                                                \
	do {                                                                 \
		x86_sim_ret_pop(&__x86_sim_state);                        \
		return X86_SIM_CONTINUE;                                  \
	} while (0)

static __always_inline void x86_sim_read_packet_value_raw(void *data,
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
	else
		*value = *(__u64 *)addr;
}

static __always_inline int x86_sim_load_packet_raw(struct x86_state *state,
						   __u8 dst, void *data,
						   void *data_end, void *base,
						   __s32 base_off, __s64 disp,
						   __u8 load_width,
						   __u8 write_width,
						   __u8 sign_extend)
{
	__u64 value = 0;

	x86_sim_read_packet_value_raw(data, data_end, base, base_off, disp,
				      load_width, &value);
	if (sign_extend)
		value = x86_sign_extend(value, load_width);
	return x86_write_reg_width(state, dst, value, write_width);
}

static __always_inline int
x86_sim_read_packet_mem_value(struct x86_state *state, __u8 base_reg, __u32 aux,
			     __s64 disp, void *data, void *data_end,
			     __u8 width, __u64 *value)
{
	void *base = 0;
	__u8 tag = X86_PTR_NONE;
	__s32 base_off = 0;
	__u64 base_value = 0;

	x86_mem_offset(state, aux, disp, &disp);
	if (base_reg != X86_REG_NONE)
		base_value = x86_read_reg(state, base_reg);
	x86_read_ptr_reg(state, base_reg, &base, &tag);
	if (tag != X86_PTR_PACKET)
		return x86_read_packet_value(data, data_end,
					     (void *)(long)base_value, disp,
					     width, value);
	base_off = x86_read_ptr_off_reg(state, base_reg);
	x86_sim_read_packet_value_raw(data, data_end, base, base_off, disp,
				      width, value);
	return X86_SIM_CONTINUE;
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
	x86_mem_offset(state, insn->aux, disp, &disp);
	x86_read_ptr_reg(state, insn->src, &base, &tag);
	if (tag != X86_PTR_PACKET)
		return x86_load_mem(state, insn, data, data_end);
	base_off = x86_read_ptr_off_reg(state, insn->src);
	return x86_sim_load_packet_raw(
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

	dst_value = x86_read_reg(state, insn->dst);
	x86_sim_read_packet_mem_value(state, insn->src, insn->aux,
				      x86_simm(insn->imm), data, data_end,
				      width, &mem_value);
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

static __always_inline int
x86_exec_cmp_mem_packet(struct x86_state *state, const struct x86_insn *insn,
			void *data, void *data_end)
{
	__u64 lhs = 0;
	__u64 rhs = x86_store_imm_value(insn->imm, insn->flags);
	__s64 disp = insn->op == X86_OP_CMP_MEM_REG ?
			     x86_simm(insn->imm) :
			     x86_store_imm_disp(insn->imm);

	x86_sim_read_packet_mem_value(state, insn->dst, insn->aux,
				      disp, data, data_end, insn->flags,
				      &lhs);
	if (insn->op == X86_OP_CMP_MEM_REG)
		rhs = x86_read_reg(state, insn->src);
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

	x86_mem_offset(state, insn->aux, disp, &disp);
	x86_read_ptr_reg(state, insn->dst, &base, &tag);
	if (tag != X86_PTR_PACKET)
		return x86_store_mem(state, insn, data, data_end);
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

	x86_mem_offset(state, insn->aux, disp, &disp);
	x86_read_ptr_reg(state, insn->dst, &base, &tag);
	if (tag != X86_PTR_PACKET)
		return x86_store_mem(state, insn, data, data_end);
	return x86_store_packet_imm(data, data_end, base, disp, insn->flags,
				    x86_store_imm_value(insn->imm, insn->flags));
}

#define X86_SIM_LICENSE() char LICENSE[] SEC("license") = "GPL"

#endif
