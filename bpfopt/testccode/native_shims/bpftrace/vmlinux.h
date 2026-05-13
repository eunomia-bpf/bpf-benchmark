#ifndef BPFOPT_TESTCCODE_NATIVE_SHIMS_BPFTRACE_VMLINUX_H
#define BPFOPT_TESTCCODE_NATIVE_SHIMS_BPFTRACE_VMLINUX_H

#ifndef __VMLINUX_H__
#define bpf_iter_task_vma_new __bpfopt_native_bpf_iter_task_vma_new
#define bpf_iter_task_vma_next __bpfopt_native_bpf_iter_task_vma_next
#define bpf_iter_task_vma_destroy __bpfopt_native_bpf_iter_task_vma_destroy
#include_next <vmlinux.h>
#undef bpf_iter_task_vma_new
#undef bpf_iter_task_vma_next
#undef bpf_iter_task_vma_destroy
#else
#include <stdbool.h>

typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;
typedef signed char __s8;
typedef signed short __s16;
typedef signed int __s32;
typedef signed long long __s64;

typedef __u8 u8;
typedef __u16 u16;
typedef __u32 u32;
typedef __u64 u64;
typedef __s8 s8;
typedef __s16 s16;
typedef __s32 s32;
typedef __s64 s64;
typedef __u16 __be16;
typedef __u32 __be32;
typedef __u32 __wsum;

#ifndef BPF_MAP_TYPE_HASH
#define BPF_MAP_TYPE_HASH 1
#endif
#ifndef BPF_MAP_TYPE_ARRAY
#define BPF_MAP_TYPE_ARRAY 2
#endif

struct __sk_buff;

struct pt_regs {
	unsigned long r15, r14, r13, r12, rbp, rbx;
	unsigned long r11, r10, r9, r8, rax, rcx, rdx, rsi, rdi;
	unsigned long orig_rax, rip, cs, eflags, rsp, ss;
	unsigned long di, si, dx, cx, sp, bp, ax, ip;
};

struct user_pt_regs {
	unsigned long regs[31];
	unsigned long sp;
	unsigned long pc;
};
#endif

#endif
