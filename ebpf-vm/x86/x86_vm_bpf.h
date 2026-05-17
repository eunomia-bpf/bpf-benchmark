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

#define X86_VM_RUN_STEP(OP, DST, SRC, FLAGS, AUX, IMM)                      \
	do {                                                               \
		int __x86_vm_step_ret =                                    \
			X86_VM_EXEC(&__x86_vm_state, (OP), (DST), (SRC),    \
				     (FLAGS), (AUX), (IMM));                 \
		if (__x86_vm_step_ret < 0)                                 \
			return XDP_ABORTED;                                \
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
			return XDP_ABORTED;                                \
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

#define X86_VM_RET_RAX() return (__u32)__x86_vm_state.rax

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
