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

#if defined(__TARGET_ARCH_x86) && !defined(bpf_target_x86)
#define bpf_target_x86
#endif
#if defined(__TARGET_ARCH_arm64) && !defined(bpf_target_arm64)
#define bpf_target_arm64
#endif

#define __PT_REGS_CAST(x) ((struct pt_regs *)(x))

#if defined(__TARGET_ARCH_arm64)
#define __PT_PARM1(x) (__PT_REGS_CAST(x)->regs[0])
#define __PT_PARM2(x) (__PT_REGS_CAST(x)->regs[1])
#define __PT_PARM3(x) (__PT_REGS_CAST(x)->regs[2])
#define __PT_PARM4(x) (__PT_REGS_CAST(x)->regs[3])
#define __PT_PARM5(x) (__PT_REGS_CAST(x)->regs[4])
#define __PT_PARM6(x) (__PT_REGS_CAST(x)->regs[5])
#define __PT_RET(x) (__PT_REGS_CAST(x)->regs[30])
#define __PT_FP(x) (__PT_REGS_CAST(x)->regs[29])
#define __PT_RC(x) (__PT_REGS_CAST(x)->regs[0])
#define __PT_SP(x) (__PT_REGS_CAST(x)->sp)
#define __PT_IP(x) (__PT_REGS_CAST(x)->pc)
#else
#define __PT_PARM1(x) (__PT_REGS_CAST(x)->di)
#define __PT_PARM2(x) (__PT_REGS_CAST(x)->si)
#define __PT_PARM3(x) (__PT_REGS_CAST(x)->dx)
#define __PT_PARM4(x) (__PT_REGS_CAST(x)->cx)
#define __PT_PARM5(x) (__PT_REGS_CAST(x)->r8)
#define __PT_PARM6(x) (__PT_REGS_CAST(x)->r9)
#define __PT_RET(x) (__PT_REGS_CAST(x)->sp)
#define __PT_FP(x) (__PT_REGS_CAST(x)->bp)
#define __PT_RC(x) (__PT_REGS_CAST(x)->ax)
#define __PT_SP(x) (__PT_REGS_CAST(x)->sp)
#define __PT_IP(x) (__PT_REGS_CAST(x)->ip)
#endif

#define PT_REGS_PARM1(x) __PT_PARM1(x)
#define PT_REGS_PARM2(x) __PT_PARM2(x)
#define PT_REGS_PARM3(x) __PT_PARM3(x)
#define PT_REGS_PARM4(x) __PT_PARM4(x)
#define PT_REGS_PARM5(x) __PT_PARM5(x)
#define PT_REGS_PARM6(x) __PT_PARM6(x)
#define PT_REGS_RET(x) __PT_RET(x)
#define PT_REGS_FP(x) __PT_FP(x)
#define PT_REGS_RC(x) __PT_RC(x)
#define PT_REGS_SP(x) __PT_SP(x)
#define PT_REGS_IP(x) __PT_IP(x)

#if defined(__TARGET_ARCH_arm64)
#define __PT_PARM1_REG regs[0]
#define __PT_PARM2_REG regs[1]
#define __PT_PARM3_REG regs[2]
#define __PT_PARM4_REG regs[3]
#define __PT_PARM5_REG regs[4]
#define __PT_PARM6_REG regs[5]
#define __PT_PARM1_SYSCALL_REG orig_x0
#define __PT_PARM2_SYSCALL_REG __PT_PARM2_REG
#define __PT_PARM3_SYSCALL_REG __PT_PARM3_REG
#define __PT_PARM4_SYSCALL_REG __PT_PARM4_REG
#define __PT_PARM5_SYSCALL_REG __PT_PARM5_REG
#define __PT_PARM6_SYSCALL_REG __PT_PARM6_REG
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
#define __PT_PARM1_SYSCALL_REG __PT_PARM1_REG
#define __PT_PARM2_SYSCALL_REG __PT_PARM2_REG
#define __PT_PARM3_SYSCALL_REG __PT_PARM3_REG
#define __PT_PARM4_SYSCALL_REG r10
#define __PT_PARM5_SYSCALL_REG __PT_PARM5_REG
#define __PT_PARM6_SYSCALL_REG __PT_PARM6_REG
#define __PT_RET_REG sp
#define __PT_FP_REG bp
#define __PT_RC_REG ax
#define __PT_SP_REG sp
#define __PT_IP_REG ip
#endif

#define __PT_CORE_READ(x, reg) (__PT_REGS_CAST(x)->reg)
#define PT_REGS_RET_CORE(x) __PT_CORE_READ(x, __PT_RET_REG)
#define PT_REGS_FP_CORE(x) __PT_CORE_READ(x, __PT_FP_REG)
#define PT_REGS_RC_CORE(x) __PT_CORE_READ(x, __PT_RC_REG)
#define PT_REGS_SP_CORE(x) __PT_CORE_READ(x, __PT_SP_REG)
#define PT_REGS_IP_CORE(x) __PT_CORE_READ(x, __PT_IP_REG)
#define PT_REGS_PARM1_CORE(x) __PT_CORE_READ(x, __PT_PARM1_REG)
#define PT_REGS_PARM2_CORE(x) __PT_CORE_READ(x, __PT_PARM2_REG)
#define PT_REGS_PARM3_CORE(x) __PT_CORE_READ(x, __PT_PARM3_REG)
#define PT_REGS_PARM4_CORE(x) __PT_CORE_READ(x, __PT_PARM4_REG)
#define PT_REGS_PARM5_CORE(x) __PT_CORE_READ(x, __PT_PARM5_REG)
#define PT_REGS_PARM6_CORE(x) __PT_CORE_READ(x, __PT_PARM6_REG)
#define PT_REGS_PARM7_CORE(x) 0
#define PT_REGS_PARM8_CORE(x) 0
#define PT_REGS_PARM1_CORE_SYSCALL(x) __PT_CORE_READ(x, __PT_PARM1_SYSCALL_REG)
#define PT_REGS_PARM2_CORE_SYSCALL(x) __PT_CORE_READ(x, __PT_PARM2_SYSCALL_REG)
#define PT_REGS_PARM3_CORE_SYSCALL(x) __PT_CORE_READ(x, __PT_PARM3_SYSCALL_REG)
#define PT_REGS_PARM4_CORE_SYSCALL(x) __PT_CORE_READ(x, __PT_PARM4_SYSCALL_REG)
#define PT_REGS_PARM5_CORE_SYSCALL(x) __PT_CORE_READ(x, __PT_PARM5_SYSCALL_REG)
#define PT_REGS_PARM6_CORE_SYSCALL(x) __PT_CORE_READ(x, __PT_PARM6_SYSCALL_REG)
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

static __always_inline int __native_core_is_null(const void *ptr)
{
    return ptr == NULL;
}

#define __native_core_is_pt_regs_ptr(src) \
    (__builtin_types_compatible_p(typeof(src), struct pt_regs *) || \
     __builtin_types_compatible_p(typeof(src), const struct pt_regs *))
#define __native_core_direct_read(dst, src, a) ({ \
    int __ret = -1; \
    if (!__native_core_is_null(src)) { \
        __builtin_memcpy((void *)(dst), (const void *)&((src)->a), sizeof(*(dst))); \
        __ret = 0; \
    } \
    __ret; \
})
#define __native_core_read_into_1(fn, dst, src, a) \
    fn((dst), sizeof(*(dst)), &((src)->a))
#define __native_core_read_into_2(fn, dst, src, a, b) ({ \
    typeof((src)->a) __t1; \
    fn(&__t1, sizeof(__t1), &((src)->a)); \
    fn((dst), sizeof(*(dst)), &(__t1->b)); \
})
#define __native_core_read_into_3(fn, dst, src, a, b, c) ({ \
    typeof((src)->a) __t1; \
    typeof(__t1->b) __t2; \
    fn(&__t1, sizeof(__t1), &((src)->a)); \
    fn(&__t2, sizeof(__t2), &(__t1->b)); \
    fn((dst), sizeof(*(dst)), &(__t2->c)); \
})
#define __native_core_read_into_4(fn, dst, src, a, b, c, d) ({ \
    typeof((src)->a) __t1; \
    typeof(__t1->b) __t2; \
    typeof(__t2->c) __t3; \
    fn(&__t1, sizeof(__t1), &((src)->a)); \
    fn(&__t2, sizeof(__t2), &(__t1->b)); \
    fn(&__t3, sizeof(__t3), &(__t2->c)); \
    fn((dst), sizeof(*(dst)), &(__t3->d)); \
})
#define __native_core_read_into_5(fn, dst, src, a, b, c, d, e) ({ \
    typeof((src)->a) __t1; \
    typeof(__t1->b) __t2; \
    typeof(__t2->c) __t3; \
    typeof(__t3->d) __t4; \
    fn(&__t1, sizeof(__t1), &((src)->a)); \
    fn(&__t2, sizeof(__t2), &(__t1->b)); \
    fn(&__t3, sizeof(__t3), &(__t2->c)); \
    fn(&__t4, sizeof(__t4), &(__t3->d)); \
    fn((dst), sizeof(*(dst)), &(__t4->e)); \
})
#define __native_core_read_into_6(fn, dst, src, a, b, c, d, e, f) ({ \
    typeof((src)->a) __t1; \
    typeof(__t1->b) __t2; \
    typeof(__t2->c) __t3; \
    typeof(__t3->d) __t4; \
    typeof(__t4->e) __t5; \
    fn(&__t1, sizeof(__t1), &((src)->a)); \
    fn(&__t2, sizeof(__t2), &(__t1->b)); \
    fn(&__t3, sizeof(__t3), &(__t2->c)); \
    fn(&__t4, sizeof(__t4), &(__t3->d)); \
    fn(&__t5, sizeof(__t5), &(__t4->e)); \
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

#define __native_core_read_value_1(fn, dst, src, a) \
    __builtin_choose_expr(__native_core_is_pt_regs_ptr(src), \
                          __native_core_direct_read((dst), (src), a), \
                          fn((dst), sizeof(*(dst)), &((src)->a)))
#define __native_core_read_value_2(fn, dst, src, a, b) \
    __native_core_read_into_2(fn, dst, src, a, b)
#define __native_core_read_value_3(fn, dst, src, a, b, c) \
    __native_core_read_into_3(fn, dst, src, a, b, c)
#define __native_core_read_value_4(fn, dst, src, a, b, c, d) \
    __native_core_read_into_4(fn, dst, src, a, b, c, d)
#define __native_core_read_value_5(fn, dst, src, a, b, c, d, e) \
    __native_core_read_into_5(fn, dst, src, a, b, c, d, e)
#define __native_core_read_value_6(fn, dst, src, a, b, c, d, e, f) \
    __native_core_read_into_6(fn, dst, src, a, b, c, d, e, f)
#define __native_core_read_value(fn, dst, src, args...) \
    __native_core_pick(args, \
                       __native_core_read_value_6, \
                       __native_core_read_value_5, \
                       __native_core_read_value_4, \
                       __native_core_read_value_3, \
                       __native_core_read_value_2, \
                       __native_core_read_value_1)(fn, dst, src, args)

#define __native_core_read_expr_1(src, a) ((src)->a)
#define __native_core_read_expr_2(src, a, b) (__native_core_read_expr_1(src, a)->b)
#define __native_core_read_expr_3(src, a, b, c) (__native_core_read_expr_2(src, a, b)->c)
#define __native_core_read_expr_4(src, a, b, c, d) (__native_core_read_expr_3(src, a, b, c)->d)
#define __native_core_read_expr_5(src, a, b, c, d, e) (__native_core_read_expr_4(src, a, b, c, d)->e)
#define __native_core_read_expr_6(src, a, b, c, d, e, f) (__native_core_read_expr_5(src, a, b, c, d, e)->f)
#define __native_core_read_expr(src, args...) \
    __native_core_pick(args, \
                       __native_core_read_expr_6, \
                       __native_core_read_expr_5, \
                       __native_core_read_expr_4, \
                       __native_core_read_expr_3, \
                       __native_core_read_expr_2, \
                       __native_core_read_expr_1)(src, args)
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
#ifdef MICRO_NATIVE_TETRAGON
#define __native_core_probe_read bpf_probe_read
#define __native_core_probe_read_str bpf_probe_read_str
#else
#define __native_core_probe_read bpf_probe_read_kernel
#define __native_core_probe_read_str bpf_probe_read_kernel_str
#endif
#ifndef bpf_core_read
#define bpf_core_read(dst, sz, src) __native_core_probe_read((dst), (sz), (src))
#endif
#ifndef BPF_CORE_READ
#define BPF_CORE_READ(src, args...) ({ \
    __native_core_type(src, args) __r; \
    __native_core_read_value(__native_core_probe_read, &__r, (src), args); \
    __r; \
})
#endif
#ifndef BPF_CORE_READ_INTO
#define BPF_CORE_READ_INTO(dst, src, args...) \
    __native_core_read_into(__native_core_probe_read, (dst), (src), args)
#endif
#ifndef BPF_CORE_READ_STR_INTO
#define BPF_CORE_READ_STR_INTO(dst, src, args...) \
    __native_core_read_into(__native_core_probe_read_str, (dst), (src), args)
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

extern void *bpf_map_lookup_elem(void *map, const void *key);
extern long bpf_map_update_elem(void *map, const void *key, const void *value,
                                unsigned long long flags);
extern long bpf_map_delete_elem(void *map, const void *key);
extern long bpf_map_push_elem(void *map, const void *value,
                              unsigned long long flags);
extern long bpf_map_pop_elem(void *map, void *value);
extern long bpf_probe_read_kernel(void *dst, unsigned int size,
                                  const void *unsafe_ptr);
extern long bpf_probe_read_user(void *dst, unsigned int size,
                                const void *unsafe_ptr);
extern long bpf_probe_read(void *dst, unsigned int size,
                           const void *unsafe_ptr);
extern long bpf_probe_read_kernel_str(void *dst, unsigned int size,
                                      const void *unsafe_ptr);
extern long bpf_probe_read_user_str(void *dst, unsigned int size,
                                    const void *unsafe_ptr);
extern long bpf_probe_read_str(void *dst, unsigned int size,
                               const void *unsafe_ptr);
extern unsigned long long bpf_get_current_pid_tgid(void);
extern unsigned long long bpf_get_current_uid_gid(void);
extern unsigned long long bpf_ktime_get_ns(void);
extern unsigned long long bpf_ktime_get_boot_ns(void);
extern unsigned int bpf_get_smp_processor_id(void);
extern unsigned int bpf_get_prandom_u32(void);
extern long bpf_get_current_comm(void *buf, unsigned int size);
extern unsigned long long bpf_get_current_cgroup_id(void);
extern unsigned long long bpf_get_current_task(void);
extern void *bpf_get_current_task_btf(void);
extern void *bpf_task_pt_regs(void *task);
extern long bpf_perf_event_output(void *ctx, void *map,
                                  unsigned long long flags,
                                  void *data, unsigned long long size);
extern long bpf_tail_call(void *ctx, void *map, unsigned int index);
extern long bpf_current_task_under_cgroup(void *map, unsigned int index);
extern long bpf_get_stackid(void *ctx, void *map, unsigned long long flags);
extern long bpf_get_stack(void *ctx, void *buf, unsigned int size,
                          unsigned long long flags);
extern void *bpf_sk_fullsock(void *sk);
extern long bpf_skb_load_bytes(void *skb, unsigned int offset, void *to,
                               unsigned int len);
extern long bpf_skb_load_bytes_relative(void *skb, unsigned int offset,
                                        void *to, unsigned int len,
                                        unsigned int start_header);

#ifdef MICRO_NATIVE_HELPER_MACROS
static __always_inline unsigned long native_helper_id0(unsigned long id)
{
    asm volatile("" : "+r"(id) : : "memory");
    return id;
}

static __always_inline unsigned long native_helper_id1(unsigned long id,
                                                       unsigned long a0)
{
    (void)a0;
    asm volatile("" : "+r"(id) : : "memory");
    return id;
}

static __always_inline unsigned long native_helper_id2(unsigned long id,
                                                       unsigned long a0,
                                                       unsigned long a1)
{
    (void)a0;
    (void)a1;
    asm volatile("" : "+r"(id) : : "memory");
    return id;
}

static __always_inline unsigned long native_helper_id3(unsigned long id,
                                                       unsigned long a0,
                                                       unsigned long a1,
                                                       unsigned long a2)
{
    (void)a0;
    (void)a1;
    (void)a2;
    asm volatile("" : "+r"(id) : : "memory");
    return id;
}

static __always_inline unsigned long native_helper_id4(unsigned long id,
                                                       unsigned long a0,
                                                       unsigned long a1,
                                                       unsigned long a2,
                                                       unsigned long a3)
{
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    asm volatile("" : "+r"(id) : : "memory");
    return id;
}

static __always_inline unsigned long native_helper_id5(unsigned long id,
                                                       unsigned long a0,
                                                       unsigned long a1,
                                                       unsigned long a2,
                                                       unsigned long a3,
                                                       unsigned long a4)
{
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    asm volatile("" : "+r"(id) : : "memory");
    return id;
}

#define native_bpf_helper0(type, id) ((type)native_helper_id0((unsigned long)(id)))
#define native_bpf_helper1(type, id, a0) \
    ((type)native_helper_id1((unsigned long)(id), (unsigned long)(a0)))
#define native_bpf_helper2(type, id, a0, a1) \
    ((type)native_helper_id2((unsigned long)(id), (unsigned long)(a0), (unsigned long)(a1)))
#define native_bpf_helper3(type, id, a0, a1, a2) \
    ((type)native_helper_id3((unsigned long)(id), (unsigned long)(a0), \
                             (unsigned long)(a1), (unsigned long)(a2)))
#define native_bpf_helper4(type, id, a0, a1, a2, a3) \
    ((type)native_helper_id4((unsigned long)(id), (unsigned long)(a0), \
                             (unsigned long)(a1), (unsigned long)(a2), \
                             (unsigned long)(a3)))
#define native_bpf_helper5(type, id, a0, a1, a2, a3, a4) \
    ((type)native_helper_id5((unsigned long)(id), (unsigned long)(a0), \
                             (unsigned long)(a1), (unsigned long)(a2), \
                             (unsigned long)(a3), (unsigned long)(a4)))

#define NATIVE_BPF_FUNC_map_lookup_elem 1
#define NATIVE_BPF_FUNC_map_update_elem 2
#define NATIVE_BPF_FUNC_map_delete_elem 3
#define NATIVE_BPF_FUNC_probe_read 4
#define NATIVE_BPF_FUNC_ktime_get_ns 5
#define NATIVE_BPF_FUNC_get_prandom_u32 7
#define NATIVE_BPF_FUNC_get_smp_processor_id 8
#define NATIVE_BPF_FUNC_tail_call 12
#define NATIVE_BPF_FUNC_get_current_pid_tgid 14
#define NATIVE_BPF_FUNC_get_current_uid_gid 15
#define NATIVE_BPF_FUNC_get_current_comm 16
#define NATIVE_BPF_FUNC_perf_event_output 25
#define NATIVE_BPF_FUNC_skb_load_bytes 26
#define NATIVE_BPF_FUNC_get_stackid 27
#define NATIVE_BPF_FUNC_get_current_task 35
#define NATIVE_BPF_FUNC_probe_write_user 36
#define NATIVE_BPF_FUNC_current_task_under_cgroup 37
#define NATIVE_BPF_FUNC_probe_read_str 45
#define NATIVE_BPF_FUNC_get_stack 67
#define NATIVE_BPF_FUNC_skb_load_bytes_relative 68
#define NATIVE_BPF_FUNC_get_current_cgroup_id 80
#define NATIVE_BPF_FUNC_map_push_elem 87
#define NATIVE_BPF_FUNC_map_pop_elem 88
#define NATIVE_BPF_FUNC_sk_fullsock 95
#define NATIVE_BPF_FUNC_send_signal 109
#define NATIVE_BPF_FUNC_probe_read_user 112
#define NATIVE_BPF_FUNC_probe_read_kernel 113
#define NATIVE_BPF_FUNC_probe_read_user_str 114
#define NATIVE_BPF_FUNC_probe_read_kernel_str 115
#define NATIVE_BPF_FUNC_ktime_get_boot_ns 125
#define NATIVE_BPF_FUNC_seq_write 127
#define NATIVE_BPF_FUNC_ringbuf_output 130
#define NATIVE_BPF_FUNC_ringbuf_reserve 131
#define NATIVE_BPF_FUNC_ringbuf_submit 132
#define NATIVE_BPF_FUNC_ringbuf_discard 133
#define NATIVE_BPF_FUNC_ringbuf_query 134
#define NATIVE_BPF_FUNC_copy_from_user 148
#define NATIVE_BPF_FUNC_get_current_task_btf 158
#define NATIVE_BPF_FUNC_ima_inode_hash 161
#define NATIVE_BPF_FUNC_get_func_ip 173
#define NATIVE_BPF_FUNC_get_attach_cookie 174
#define NATIVE_BPF_FUNC_task_pt_regs 175
#define NATIVE_BPF_FUNC_loop 181
#define NATIVE_BPF_FUNC_get_func_arg 183
#define NATIVE_BPF_FUNC_get_func_ret 184
#define NATIVE_BPF_FUNC_get_func_arg_cnt 185
#define NATIVE_BPF_FUNC_ima_file_hash 193
#define NATIVE_BPF_FUNC_override_return 58

#undef bpf_map_lookup_elem
#define bpf_map_lookup_elem(map, key) \
    native_bpf_helper2(void *(*)(void *, const void *), NATIVE_BPF_FUNC_map_lookup_elem, \
                       (map), (key))((map), (key))
#undef bpf_map_update_elem
#define bpf_map_update_elem(map, key, value, flags) \
    native_bpf_helper4(long (*)(void *, const void *, const void *, unsigned long long), \
                       NATIVE_BPF_FUNC_map_update_elem, (map), (key), (value), (flags))( \
        (map), (key), (value), (flags))
#undef bpf_map_delete_elem
#define bpf_map_delete_elem(map, key) \
    native_bpf_helper2(long (*)(void *, const void *), NATIVE_BPF_FUNC_map_delete_elem, \
                       (map), (key))((map), (key))
#undef bpf_map_push_elem
#define bpf_map_push_elem(map, value, flags) \
    native_bpf_helper3(long (*)(void *, const void *, unsigned long long), \
                       NATIVE_BPF_FUNC_map_push_elem, (map), (value), (flags))( \
        (map), (value), (flags))
#undef bpf_map_pop_elem
#define bpf_map_pop_elem(map, value) \
    native_bpf_helper2(long (*)(void *, void *), NATIVE_BPF_FUNC_map_pop_elem, \
                       (map), (value))((map), (value))
#undef bpf_probe_read
#define bpf_probe_read(dst, size, unsafe_ptr) \
    native_bpf_helper3(long (*)(void *, unsigned int, const void *), \
                       NATIVE_BPF_FUNC_probe_read, (dst), (size), (unsafe_ptr))( \
        (dst), (size), (unsafe_ptr))
#undef bpf_probe_read_kernel
#define bpf_probe_read_kernel(dst, size, unsafe_ptr) \
    native_bpf_helper3(long (*)(void *, unsigned int, const void *), \
                       NATIVE_BPF_FUNC_probe_read_kernel, (dst), (size), (unsafe_ptr))( \
        (dst), (size), (unsafe_ptr))
#undef bpf_probe_read_user
#define bpf_probe_read_user(dst, size, unsafe_ptr) \
    native_bpf_helper3(long (*)(void *, unsigned int, const void *), \
                       NATIVE_BPF_FUNC_probe_read_user, (dst), (size), (unsafe_ptr))( \
        (dst), (size), (unsafe_ptr))
#undef bpf_probe_write_user
#define bpf_probe_write_user(dst, src, len) \
    native_bpf_helper3(long (*)(void *, const void *, unsigned int), \
                       NATIVE_BPF_FUNC_probe_write_user, (dst), (src), (len))( \
        (dst), (src), (len))
#undef bpf_copy_from_user
#define bpf_copy_from_user(dst, size, unsafe_ptr) \
    native_bpf_helper3(long (*)(void *, unsigned int, const void *), \
                       NATIVE_BPF_FUNC_copy_from_user, (dst), (size), (unsafe_ptr))( \
        (dst), (size), (unsafe_ptr))
#undef bpf_probe_read_kernel_str
#define bpf_probe_read_kernel_str(dst, size, unsafe_ptr) \
    native_bpf_helper3(long (*)(void *, unsigned int, const void *), \
                       NATIVE_BPF_FUNC_probe_read_kernel_str, (dst), (size), (unsafe_ptr))( \
        (dst), (size), (unsafe_ptr))
#undef bpf_probe_read_user_str
#define bpf_probe_read_user_str(dst, size, unsafe_ptr) \
    native_bpf_helper3(long (*)(void *, unsigned int, const void *), \
                       NATIVE_BPF_FUNC_probe_read_user_str, (dst), (size), (unsafe_ptr))( \
        (dst), (size), (unsafe_ptr))
#undef bpf_probe_read_str
#define bpf_probe_read_str(dst, size, unsafe_ptr) \
    native_bpf_helper3(long (*)(void *, unsigned int, const void *), \
                       NATIVE_BPF_FUNC_probe_read_str, (dst), (size), (unsafe_ptr))( \
        (dst), (size), (unsafe_ptr))
#undef bpf_get_current_pid_tgid
#define bpf_get_current_pid_tgid() \
    native_bpf_helper0(unsigned long long (*)(void), NATIVE_BPF_FUNC_get_current_pid_tgid)()
#undef bpf_get_current_uid_gid
#define bpf_get_current_uid_gid() \
    native_bpf_helper0(unsigned long long (*)(void), NATIVE_BPF_FUNC_get_current_uid_gid)()
#undef bpf_ktime_get_ns
#define bpf_ktime_get_ns() \
    native_bpf_helper0(unsigned long long (*)(void), NATIVE_BPF_FUNC_ktime_get_ns)()
#undef bpf_ktime_get_boot_ns
#define bpf_ktime_get_boot_ns() \
    native_bpf_helper0(unsigned long long (*)(void), NATIVE_BPF_FUNC_ktime_get_boot_ns)()
#undef bpf_get_smp_processor_id
#define bpf_get_smp_processor_id() \
    native_bpf_helper0(unsigned int (*)(void), NATIVE_BPF_FUNC_get_smp_processor_id)()
#undef bpf_get_prandom_u32
#define bpf_get_prandom_u32() \
    native_bpf_helper0(unsigned int (*)(void), NATIVE_BPF_FUNC_get_prandom_u32)()
#undef bpf_get_current_comm
#define bpf_get_current_comm(buf, size) \
    native_bpf_helper2(long (*)(void *, unsigned int), NATIVE_BPF_FUNC_get_current_comm, \
                       (buf), (size))((buf), (size))
#undef bpf_get_current_cgroup_id
#define bpf_get_current_cgroup_id() \
    native_bpf_helper0(unsigned long long (*)(void), NATIVE_BPF_FUNC_get_current_cgroup_id)()
#undef bpf_get_current_task
#define bpf_get_current_task() \
    native_bpf_helper0(unsigned long long (*)(void), NATIVE_BPF_FUNC_get_current_task)()
#undef bpf_get_current_task_btf
#define bpf_get_current_task_btf() \
    native_bpf_helper0(void *(*)(void), NATIVE_BPF_FUNC_get_current_task_btf)()
#undef bpf_get_attach_cookie
#define bpf_get_attach_cookie(ctx) \
    native_bpf_helper1(unsigned long long (*)(void *), NATIVE_BPF_FUNC_get_attach_cookie, (ctx))( \
        (ctx))
#undef bpf_get_func_ip
#define bpf_get_func_ip(ctx) \
    native_bpf_helper1(unsigned long long (*)(void *), NATIVE_BPF_FUNC_get_func_ip, (ctx))((ctx))
#undef bpf_get_func_arg
#define bpf_get_func_arg(ctx, n, value) \
    native_bpf_helper3(long (*)(void *, unsigned int, unsigned long long *), \
                       NATIVE_BPF_FUNC_get_func_arg, (ctx), (n), (value))((ctx), (n), (value))
#undef bpf_get_func_ret
#define bpf_get_func_ret(ctx, value) \
    native_bpf_helper2(long (*)(void *, unsigned long long *), \
                       NATIVE_BPF_FUNC_get_func_ret, (ctx), (value))((ctx), (value))
#undef bpf_get_func_arg_cnt
#define bpf_get_func_arg_cnt(ctx) \
    native_bpf_helper1(long (*)(void *), NATIVE_BPF_FUNC_get_func_arg_cnt, (ctx))((ctx))
#undef bpf_ima_inode_hash
#define bpf_ima_inode_hash(inode, dst, size) \
    native_bpf_helper3(long (*)(void *, void *, unsigned int), NATIVE_BPF_FUNC_ima_inode_hash, \
                       (inode), (dst), (size))((inode), (dst), (size))
#undef bpf_ima_file_hash
#define bpf_ima_file_hash(file, dst, size) \
    native_bpf_helper3(long (*)(void *, void *, unsigned int), NATIVE_BPF_FUNC_ima_file_hash, \
                       (file), (dst), (size))((file), (dst), (size))
#undef bpf_task_pt_regs
#define bpf_task_pt_regs(task) \
    native_bpf_helper1(void *(*)(void *), NATIVE_BPF_FUNC_task_pt_regs, (task))((task))
#undef bpf_send_signal
#define bpf_send_signal(sig) \
    native_bpf_helper1(long (*)(unsigned int), NATIVE_BPF_FUNC_send_signal, (sig))((sig))
#undef bpf_override_return
#define bpf_override_return(ctx, rc) \
    native_bpf_helper2(long (*)(void *, unsigned long long), NATIVE_BPF_FUNC_override_return, \
                       (ctx), (rc))((ctx), (rc))
#undef bpf_perf_event_output
#define bpf_perf_event_output(ctx, map, flags, data, size) \
    native_bpf_helper5(long (*)(void *, void *, unsigned long long, void *, unsigned long long), \
                       NATIVE_BPF_FUNC_perf_event_output, (ctx), (map), (flags), (data), (size))( \
        (ctx), (map), (flags), (data), (size))
#undef bpf_ringbuf_output
#define bpf_ringbuf_output(ringbuf, data, size, flags) \
    native_bpf_helper4(long (*)(void *, void *, unsigned long long, unsigned long long), \
                       NATIVE_BPF_FUNC_ringbuf_output, (ringbuf), (data), (size), (flags))( \
        (ringbuf), (data), (size), (flags))
#undef bpf_ringbuf_reserve
#define bpf_ringbuf_reserve(ringbuf, size, flags) \
    native_bpf_helper3(void *(*)(void *, unsigned long long, unsigned long long), \
                       NATIVE_BPF_FUNC_ringbuf_reserve, (ringbuf), (size), (flags))( \
        (ringbuf), (size), (flags))
#undef bpf_ringbuf_submit
#define bpf_ringbuf_submit(data, flags) \
    native_bpf_helper2(void (*)(void *, unsigned long long), \
                       NATIVE_BPF_FUNC_ringbuf_submit, (data), (flags))((data), (flags))
#undef bpf_ringbuf_discard
#define bpf_ringbuf_discard(data, flags) \
    native_bpf_helper2(void (*)(void *, unsigned long long), \
                       NATIVE_BPF_FUNC_ringbuf_discard, (data), (flags))((data), (flags))
#undef bpf_ringbuf_query
#define bpf_ringbuf_query(ringbuf, flags) \
    native_bpf_helper2(long (*)(void *, unsigned long long), \
                       NATIVE_BPF_FUNC_ringbuf_query, (ringbuf), (flags))((ringbuf), (flags))
#undef bpf_seq_write
#define bpf_seq_write(seq, data, len) \
    native_bpf_helper3(long (*)(void *, const void *, unsigned int), NATIVE_BPF_FUNC_seq_write, \
                       (seq), (data), (len))((seq), (data), (len))
#undef bpf_loop
#define bpf_loop(nr_loops, callback_fn, callback_ctx, flags) \
    native_bpf_helper4(long (*)(unsigned int, void *, void *, unsigned long long), \
                       NATIVE_BPF_FUNC_loop, (nr_loops), (callback_fn), (callback_ctx), (flags))( \
        (nr_loops), (callback_fn), (callback_ctx), (flags))
#undef bpf_tail_call
#define bpf_tail_call(ctx, map, index) \
    native_bpf_helper3(long (*)(void *, void *, unsigned int), NATIVE_BPF_FUNC_tail_call, \
                       (ctx), (map), (index))((ctx), (map), (index))
#undef bpf_current_task_under_cgroup
#define bpf_current_task_under_cgroup(map, index) \
    native_bpf_helper2(long (*)(void *, unsigned int), NATIVE_BPF_FUNC_current_task_under_cgroup, \
                       (map), (index))((map), (index))
#undef bpf_get_stackid
#define bpf_get_stackid(ctx, map, flags) \
    native_bpf_helper3(long (*)(void *, void *, unsigned long long), NATIVE_BPF_FUNC_get_stackid, \
                       (ctx), (map), (flags))((ctx), (map), (flags))
#undef bpf_get_stack
#define bpf_get_stack(ctx, buf, size, flags) \
    native_bpf_helper4(long (*)(void *, void *, unsigned int, unsigned long long), \
                       NATIVE_BPF_FUNC_get_stack, (ctx), (buf), (size), (flags))( \
        (ctx), (buf), (size), (flags))
#undef bpf_sk_fullsock
#define bpf_sk_fullsock(sk) \
    native_bpf_helper1(void *(*)(void *), NATIVE_BPF_FUNC_sk_fullsock, (sk))((sk))
#undef bpf_skb_load_bytes
#define bpf_skb_load_bytes(skb, offset, to, len) \
    native_bpf_helper4(long (*)(void *, unsigned int, void *, unsigned int), \
                       NATIVE_BPF_FUNC_skb_load_bytes, (skb), (offset), (to), (len))( \
        (skb), (offset), (to), (len))
#undef bpf_skb_load_bytes_relative
#define bpf_skb_load_bytes_relative(skb, offset, to, len, start_header) \
    native_bpf_helper5(long (*)(void *, unsigned int, void *, unsigned int, unsigned int), \
                       NATIVE_BPF_FUNC_skb_load_bytes_relative, (skb), (offset), (to), \
                       (len), (start_header))( \
        (skb), (offset), (to), (len), (start_header))
#endif

#endif

#endif
