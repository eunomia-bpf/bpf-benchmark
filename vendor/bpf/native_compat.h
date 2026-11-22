#ifndef VENDOR_BPF_NATIVE_COMPAT_H
#define VENDOR_BPF_NATIVE_COMPAT_H

#ifdef MICRO_NATIVE

#define __BPF_HELPERS__
#define __BPF_TRACING_H__
#define __BPF_CORE_READ_H__
#define BPF_NO_PRESERVE_ACCESS_INDEX

#ifndef SEC
#define SEC(NAME) __attribute__((section(NAME), used))
#endif

#ifndef __uint
#define __uint(name, val) int (*name)[val]
#endif
#ifndef __type
#define __type(name, val) typeof(val) *name
#endif
#ifndef __array
#define __array(name, val) typeof(val) *name[]
#endif
#ifndef __ulong
#define __ulong(name, val) enum { name = val }
#endif

#ifndef __always_inline
#define __always_inline __inline __attribute__((__always_inline__))
#endif

#ifndef __kconfig
#define __kconfig
#endif

#ifndef NULL
#define NULL ((void *)0)
#endif

#ifndef KERNEL_VERSION
#define KERNEL_VERSION(a, b, c) (((a) << 16) + ((b) << 8) + ((c) > 255 ? 255 : (c)))
#endif

#ifndef barrier
#define barrier() asm volatile("" ::: "memory")
#endif
#ifndef compiler_barrier
#define compiler_barrier() asm volatile("" ::: "memory")
#endif
#ifndef PATH_MAP_SIZE
#define PATH_MAP_SIZE 4096
#endif
#ifndef offsetof
#define offsetof(type, member) __builtin_offsetof(type, member)
#endif
#ifndef container_of
#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))
#endif
#ifndef bpf_for
#define bpf_for(i, start, end) for ((i) = (start); (i) < (end); (i)++)
#endif
#ifndef bpf_repeat
#define bpf_repeat(n) for (int __native_repeat_i = 0; __native_repeat_i < (n); __native_repeat_i++)
#endif
#ifndef __builtin_preserve_access_index
#define __builtin_preserve_access_index(expr) (expr)
#endif
#ifndef _
#define _(P) (__builtin_preserve_access_index(P))
#endif

#if defined(__aarch64__)
#define __PT_PARM1_REG regs[0]
#define __PT_PARM2_REG regs[1]
#define __PT_PARM3_REG regs[2]
#define __PT_PARM4_REG regs[3]
#define __PT_PARM5_REG regs[4]
#define __PT_PARM6_REG regs[5]
#define __PT_RET_REG regs[30]
#define __PT_FP_REG regs[29]
#define __PT_RC_REG regs[0]
#define __PT_SP_REG sp
#define __PT_IP_REG pc
#else
#define __PT_PARM1_REG di
#define __PT_PARM2_REG si
#define __PT_PARM3_REG dx
#define __PT_PARM4_REG cx
#define __PT_PARM5_REG r8
#define __PT_PARM6_REG r9
#define __PT_RET_REG sp
#define __PT_FP_REG bp
#define __PT_RC_REG ax
#define __PT_SP_REG sp
#define __PT_IP_REG ip
#endif

#if defined(__TARGET_ARCH_x86) && !defined(bpf_target_x86)
#define bpf_target_x86
#endif
#if defined(__TARGET_ARCH_arm64) && !defined(bpf_target_arm64)
#define bpf_target_arm64
#endif

#define __PT_REGS_CAST(x) ((struct pt_regs *)(x))
#define PT_REGS_PARM1(x) (__PT_REGS_CAST(x)->__PT_PARM1_REG)
#define PT_REGS_PARM2(x) (__PT_REGS_CAST(x)->__PT_PARM2_REG)
#define PT_REGS_PARM3(x) (__PT_REGS_CAST(x)->__PT_PARM3_REG)
#define PT_REGS_PARM4(x) (__PT_REGS_CAST(x)->__PT_PARM4_REG)
#define PT_REGS_PARM5(x) (__PT_REGS_CAST(x)->__PT_PARM5_REG)
#define PT_REGS_PARM6(x) (__PT_REGS_CAST(x)->__PT_PARM6_REG)
#define PT_REGS_RET(x) (__PT_REGS_CAST(x)->__PT_RET_REG)
#define PT_REGS_FP(x) (__PT_REGS_CAST(x)->__PT_FP_REG)
#define PT_REGS_RC(x) (__PT_REGS_CAST(x)->__PT_RC_REG)
#define PT_REGS_SP(x) (__PT_REGS_CAST(x)->__PT_SP_REG)
#define PT_REGS_IP(x) (__PT_REGS_CAST(x)->__PT_IP_REG)
#define PT_REGS_RET_CORE(x) PT_REGS_RET(x)
#define PT_REGS_FP_CORE(x) PT_REGS_FP(x)
#define PT_REGS_RC_CORE(x) PT_REGS_RC(x)
#define PT_REGS_SP_CORE(x) PT_REGS_SP(x)
#define PT_REGS_IP_CORE(x) PT_REGS_IP(x)
#define PT_REGS_PARM1_CORE(x) PT_REGS_PARM1(x)
#define PT_REGS_PARM2_CORE(x) PT_REGS_PARM2(x)
#define PT_REGS_PARM3_CORE(x) PT_REGS_PARM3(x)
#define PT_REGS_PARM4_CORE(x) PT_REGS_PARM4(x)
#define PT_REGS_PARM5_CORE(x) PT_REGS_PARM5(x)
#define PT_REGS_PARM6_CORE(x) PT_REGS_PARM6(x)
#define PT_REGS_PARM7_CORE(x) 0
#define PT_REGS_PARM8_CORE(x) 0
#define PT_REGS_PARM1_CORE_SYSCALL(x) PT_REGS_PARM1(x)
#define PT_REGS_PARM2_CORE_SYSCALL(x) PT_REGS_PARM2(x)
#define PT_REGS_PARM3_CORE_SYSCALL(x) PT_REGS_PARM3(x)
#define PT_REGS_PARM4_CORE_SYSCALL(x) PT_REGS_PARM4(x)
#define PT_REGS_PARM5_CORE_SYSCALL(x) PT_REGS_PARM5(x)
#define PT_REGS_PARM6_CORE_SYSCALL(x) PT_REGS_PARM6(x)
#define PT_REGS_PARM7_CORE_SYSCALL(x) 0
#define PT_REGS_SYSCALL_REGS(x) (x)

#ifndef bpf_ksym_exists
#define bpf_ksym_exists(sym) (1)
#endif

#ifndef ___bpf_concat
#define ___bpf_concat(a, b) a ## b
#endif
#ifndef ___bpf_apply
#define ___bpf_apply(fn, n) ___bpf_concat(fn, n)
#endif
#ifndef ___bpf_nth
#define ___bpf_nth(_, _1, _2, _3, _4, _5, _6, _7, _8, _9, _a, _b, _c, N, ...) N
#endif
#ifndef ___bpf_narg
#define ___bpf_narg(...) ___bpf_nth(_, ##__VA_ARGS__, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)
#endif

#define ___bpf_ctx_cast0()            ctx
#define ___bpf_ctx_cast1(x)           ___bpf_ctx_cast0(), (void *)ctx[0]
#define ___bpf_ctx_cast2(x, args...)  ___bpf_ctx_cast1(args), (void *)ctx[1]
#define ___bpf_ctx_cast3(x, args...)  ___bpf_ctx_cast2(args), (void *)ctx[2]
#define ___bpf_ctx_cast4(x, args...)  ___bpf_ctx_cast3(args), (void *)ctx[3]
#define ___bpf_ctx_cast5(x, args...)  ___bpf_ctx_cast4(args), (void *)ctx[4]
#define ___bpf_ctx_cast6(x, args...)  ___bpf_ctx_cast5(args), (void *)ctx[5]
#define ___bpf_ctx_cast7(x, args...)  ___bpf_ctx_cast6(args), (void *)ctx[6]
#define ___bpf_ctx_cast8(x, args...)  ___bpf_ctx_cast7(args), (void *)ctx[7]
#define ___bpf_ctx_cast9(x, args...)  ___bpf_ctx_cast8(args), (void *)ctx[8]
#define ___bpf_ctx_cast10(x, args...) ___bpf_ctx_cast9(args), (void *)ctx[9]
#define ___bpf_ctx_cast11(x, args...) ___bpf_ctx_cast10(args), (void *)ctx[10]
#define ___bpf_ctx_cast12(x, args...) ___bpf_ctx_cast11(args), (void *)ctx[11]
#define ___bpf_ctx_cast(args...)      ___bpf_apply(___bpf_ctx_cast, ___bpf_narg(args))(args)

#define BPF_PROG(name, args...)                                             \
name(unsigned long long *ctx);                                              \
static __always_inline typeof(name(0))                                      \
____##name(unsigned long long *ctx, ##args);                                \
typeof(name(0)) name(unsigned long long *ctx)                               \
{                                                                           \
    _Pragma("GCC diagnostic push")                                          \
    _Pragma("GCC diagnostic ignored \"-Wint-conversion\"")                 \
    return ____##name(___bpf_ctx_cast(args));                               \
    _Pragma("GCC diagnostic pop")                                           \
}                                                                           \
static __always_inline typeof(name(0))                                      \
____##name(unsigned long long *ctx, ##args)

#define BPF_PROG2(name, args...) BPF_PROG(name, ##args)

#define ___bpf_kprobe_args0()           ctx
#define ___bpf_kprobe_args1(x)          ___bpf_kprobe_args0(), (void *)PT_REGS_PARM1(ctx)
#define ___bpf_kprobe_args2(x, args...) ___bpf_kprobe_args1(args), (void *)PT_REGS_PARM2(ctx)
#define ___bpf_kprobe_args3(x, args...) ___bpf_kprobe_args2(args), (void *)PT_REGS_PARM3(ctx)
#define ___bpf_kprobe_args4(x, args...) ___bpf_kprobe_args3(args), (void *)PT_REGS_PARM4(ctx)
#define ___bpf_kprobe_args5(x, args...) ___bpf_kprobe_args4(args), (void *)PT_REGS_PARM5(ctx)
#define ___bpf_kprobe_args6(x, args...) ___bpf_kprobe_args5(args), (void *)PT_REGS_PARM6(ctx)
#define ___bpf_kprobe_args(args...)     ___bpf_apply(___bpf_kprobe_args, ___bpf_narg(args))(args)

#define BPF_KPROBE(name, args...)                                           \
name(struct pt_regs *ctx);                                                  \
static __always_inline typeof(name(0))                                      \
____##name(struct pt_regs *ctx, ##args);                                    \
typeof(name(0)) name(struct pt_regs *ctx)                                   \
{                                                                           \
    _Pragma("GCC diagnostic push")                                          \
    _Pragma("GCC diagnostic ignored \"-Wint-conversion\"")                 \
    return ____##name(___bpf_kprobe_args(args));                            \
    _Pragma("GCC diagnostic pop")                                           \
}                                                                           \
static __always_inline typeof(name(0))                                      \
____##name(struct pt_regs *ctx, ##args)

#define ___bpf_kretprobe_args0()       ctx
#define ___bpf_kretprobe_args1(x)      ___bpf_kretprobe_args0(), (void *)PT_REGS_RC(ctx)
#define ___bpf_kretprobe_args(args...) ___bpf_apply(___bpf_kretprobe_args, ___bpf_narg(args))(args)

#define BPF_KRETPROBE(name, args...)                                        \
name(struct pt_regs *ctx);                                                  \
static __always_inline typeof(name(0))                                      \
____##name(struct pt_regs *ctx, ##args);                                    \
typeof(name(0)) name(struct pt_regs *ctx)                                   \
{                                                                           \
    _Pragma("GCC diagnostic push")                                          \
    _Pragma("GCC diagnostic ignored \"-Wint-conversion\"")                 \
    return ____##name(___bpf_kretprobe_args(args));                         \
    _Pragma("GCC diagnostic pop")                                           \
}                                                                           \
static __always_inline typeof(name(0))                                      \
____##name(struct pt_regs *ctx, ##args)

#define BPF_UPROBE(name, args...) BPF_KPROBE(name, ##args)
#define BPF_URETPROBE(name, args...) BPF_KRETPROBE(name, ##args)
#define BPF_KSYSCALL(name, args...) BPF_KPROBE(name, ##args)

#define __native_core_type_1(src, a) typeof((src)->a)
#define __native_core_type_2(src, a, b) typeof(((src)->a)->b)
#define __native_core_type_3(src, a, b, c) typeof((((src)->a)->b)->c)
#define __native_core_type_4(src, a, b, c, d) typeof(((((src)->a)->b)->c)->d)
#define __native_core_type_5(src, a, b, c, d, e) typeof((((((src)->a)->b)->c)->d)->e)
#define __native_core_type_6(src, a, b, c, d, e, f) typeof(((((((src)->a)->b)->c)->d)->e)->f)
#define __native_core_pick(_1, _2, _3, _4, _5, _6, name, ...) name
#define __native_core_type(src, args...) \
    __native_core_pick(args, \
                       __native_core_type_6, \
                       __native_core_type_5, \
                       __native_core_type_4, \
                       __native_core_type_3, \
                       __native_core_type_2, \
                       __native_core_type_1)(src, args)

#define __native_core_read_into_1(fn, dst, src, a) \
    fn((dst), sizeof(*(dst)), &((src)->a))
#define __native_core_read_into_2(fn, dst, src, a, b) ({ \
    typeof((src)->a) __t1; \
    bpf_probe_read_kernel(&__t1, sizeof(__t1), &((src)->a)); \
    fn((dst), sizeof(*(dst)), &(__t1->b)); \
})
#define __native_core_read_into_3(fn, dst, src, a, b, c) ({ \
    typeof((src)->a) __t1; \
    typeof(__t1->b) __t2; \
    bpf_probe_read_kernel(&__t1, sizeof(__t1), &((src)->a)); \
    bpf_probe_read_kernel(&__t2, sizeof(__t2), &(__t1->b)); \
    fn((dst), sizeof(*(dst)), &(__t2->c)); \
})
#define __native_core_read_into_4(fn, dst, src, a, b, c, d) ({ \
    typeof((src)->a) __t1; \
    typeof(__t1->b) __t2; \
    typeof(__t2->c) __t3; \
    bpf_probe_read_kernel(&__t1, sizeof(__t1), &((src)->a)); \
    bpf_probe_read_kernel(&__t2, sizeof(__t2), &(__t1->b)); \
    bpf_probe_read_kernel(&__t3, sizeof(__t3), &(__t2->c)); \
    fn((dst), sizeof(*(dst)), &(__t3->d)); \
})
#define __native_core_read_into_5(fn, dst, src, a, b, c, d, e) ({ \
    typeof((src)->a) __t1; \
    typeof(__t1->b) __t2; \
    typeof(__t2->c) __t3; \
    typeof(__t3->d) __t4; \
    bpf_probe_read_kernel(&__t1, sizeof(__t1), &((src)->a)); \
    bpf_probe_read_kernel(&__t2, sizeof(__t2), &(__t1->b)); \
    bpf_probe_read_kernel(&__t3, sizeof(__t3), &(__t2->c)); \
    bpf_probe_read_kernel(&__t4, sizeof(__t4), &(__t3->d)); \
    fn((dst), sizeof(*(dst)), &(__t4->e)); \
})
#define __native_core_read_into_6(fn, dst, src, a, b, c, d, e, f) ({ \
    typeof((src)->a) __t1; \
    typeof(__t1->b) __t2; \
    typeof(__t2->c) __t3; \
    typeof(__t3->d) __t4; \
    typeof(__t4->e) __t5; \
    bpf_probe_read_kernel(&__t1, sizeof(__t1), &((src)->a)); \
    bpf_probe_read_kernel(&__t2, sizeof(__t2), &(__t1->b)); \
    bpf_probe_read_kernel(&__t3, sizeof(__t3), &(__t2->c)); \
    bpf_probe_read_kernel(&__t4, sizeof(__t4), &(__t3->d)); \
    bpf_probe_read_kernel(&__t5, sizeof(__t5), &(__t4->e)); \
    fn((dst), sizeof(*(dst)), &(__t5->f)); \
})
#define __native_core_read_into(fn, dst, src, args...) \
    __native_core_pick(args, \
                       __native_core_read_into_6, \
                       __native_core_read_into_5, \
                       __native_core_read_into_4, \
                       __native_core_read_into_3, \
                       __native_core_read_into_2, \
                       __native_core_read_into_1)(fn, dst, src, args)

#ifndef bpf_core_field_exists
#ifdef MICRO_NATIVE_TETRAGON
/*
 * Native objects are compiled against the generated target vmlinux header, not
 * libbpf-relocated BPF CO-RE metadata. Most field-existence probes used by the
 * corpus should therefore fold to true when the expression compiles. CO-RE
 * flavor structs are the exception. Their fields exist in the source C type,
 * but their offsets are synthetic until libbpf CO-RE relocates them against
 * the target kernel BTF. Taking those branches in native C reads the synthetic
 * layout instead of the real vmlinux_generated_*.h layout.
 */
#define __native_bpf_core_field_exists_text(field_text) \
    (__builtin_strcmp((field_text), "((struct kernfs_node___old *)0)->id.id") != 0 && \
     __builtin_strcmp((field_text), "cgrp_new->ancestors") != 0)
#define bpf_core_field_exists(field...) \
    __native_bpf_core_field_exists_text(#field)
#else
#define bpf_core_field_exists(field...) (1)
#endif
#endif
#ifndef bpf_core_type_exists
#define bpf_core_type_exists(type) (1)
#endif
#ifndef bpf_core_type_size
#define bpf_core_type_size(type) sizeof(type)
#endif
#ifndef bpf_core_field_size
#define bpf_core_field_size(field) sizeof(field)
#endif
#ifndef bpf_core_enum_value_exists
#define bpf_core_enum_value_exists(type, value) (1)
#endif
#ifndef bpf_core_enum_value
#define bpf_core_enum_value(type, value) (value)
#endif
#ifndef bpf_core_read
#define bpf_core_read(dst, sz, src) bpf_probe_read_kernel((dst), (sz), (src))
#endif
#ifndef BPF_CORE_READ
#define BPF_CORE_READ(src, args...) ({ \
    __native_core_type(src, args) __r; \
    BPF_CORE_READ_INTO(&__r, (src), args); \
    __r; \
})
#endif
#ifndef BPF_CORE_READ_INTO
#define BPF_CORE_READ_INTO(dst, src, args...) \
    __native_core_read_into(bpf_probe_read_kernel, (dst), (src), args)
#endif
#ifndef BPF_CORE_READ_STR_INTO
#define BPF_CORE_READ_STR_INTO(dst, src, args...) \
    __native_core_read_into(bpf_probe_read_kernel_str, (dst), (src), args)
#endif
#ifndef bpf_core_read_user
#define bpf_core_read_user(dst, sz, src) bpf_probe_read_user((dst), (sz), (src))
#endif
#ifndef BPF_CORE_READ_USER
#define BPF_CORE_READ_USER(src, args...) ({ \
    __native_core_type(src, args) __r; \
    __native_core_read_into(bpf_probe_read_user, &__r, (src), args); \
    __r; \
})
#endif


#endif

#ifdef MICRO_NATIVE_TETRAGON
/* The one kernel's BTF carries no kfunc declarations, so its vmlinux.h lacks this one. */
extern int bpf_copy_from_user_str(void *dst, unsigned int dst__sz, const void *unsafe_ptr,
				  unsigned long long flags);
#endif

#include "native-helpers.h"

#endif
