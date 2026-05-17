#ifndef X86_VM_BPF_H
#define X86_VM_BPF_H

#include <linux/bpf.h>
#include <bpf_helpers.h>

#include "x86_interp.h"

#define X86_VM_OUTPUT_OFF 0U

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

#define X86_VM_RUN_PROGRAM(STATE, PROG, PROG_LEN)                         \
	({                                                                \
		int __x86_vm_ret = 0;                                      \
		__u32 __x86_vm_pc;                                        \
		_Pragma("clang loop unroll(full)")                         \
		for (__x86_vm_pc = 0; __x86_vm_pc < (PROG_LEN);            \
		     __x86_vm_pc++) {                                      \
			int __x86_vm_step_ret =                           \
				x86_exec_one((STATE), &(PROG)[__x86_vm_pc]); \
			if (__x86_vm_step_ret == X86_INTERP_DONE)          \
				break;                                    \
			if (__x86_vm_step_ret < 0) {                       \
				__x86_vm_ret = __x86_vm_step_ret;          \
				break;                                    \
			}                                                 \
		}                                                         \
		__x86_vm_ret;                                             \
	})

#define X86_VM_RUN_XDP(CTX, PROG, PROG_LEN)                                \
	({                                                                 \
		void *__x86_vm_data = (void *)(long)(CTX)->data;            \
		void *__x86_vm_data_end = (void *)(long)(CTX)->data_end;    \
		struct x86_state __x86_vm_state = {};                       \
		int __x86_vm_ret;                                           \
		int __x86_vm_xdp_ret;                                       \
		__x86_vm_ret =                                              \
			X86_VM_RUN_PROGRAM(&__x86_vm_state, PROG, PROG_LEN); \
		if (__x86_vm_ret < 0 ||                                     \
		    x86_vm_write_result_u64(__x86_vm_data,                  \
					    __x86_vm_data_end,             \
					    __x86_vm_state.rax) < 0)       \
			__x86_vm_xdp_ret = XDP_ABORTED;                    \
		else                                                           \
			__x86_vm_xdp_ret = XDP_PASS;                       \
		__x86_vm_xdp_ret;                                           \
	})

#define X86_VM_LICENSE() char LICENSE[] SEC("license") = "GPL"

#endif
