#ifndef VENDOR_BPF_NATIVE_COMPAT_H
#define VENDOR_BPF_NATIVE_COMPAT_H


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
#ifdef MICRO_NATIVE_CORE_REG_PROBE_READS
#define PT_REGS_RET_CORE(x) BPF_CORE_READ(__PT_REGS_CAST(x), __PT_RET_REG)
#define PT_REGS_FP_CORE(x) BPF_CORE_READ(__PT_REGS_CAST(x), __PT_FP_REG)
#define PT_REGS_RC_CORE(x) BPF_CORE_READ(__PT_REGS_CAST(x), __PT_RC_REG)
#define PT_REGS_SP_CORE(x) BPF_CORE_READ(__PT_REGS_CAST(x), __PT_SP_REG)
#define PT_REGS_IP_CORE(x) BPF_CORE_READ(__PT_REGS_CAST(x), __PT_IP_REG)
#define PT_REGS_PARM1_CORE(x) BPF_CORE_READ(__PT_REGS_CAST(x), __PT_PARM1_REG)
#define PT_REGS_PARM2_CORE(x) BPF_CORE_READ(__PT_REGS_CAST(x), __PT_PARM2_REG)
#define PT_REGS_PARM3_CORE(x) BPF_CORE_READ(__PT_REGS_CAST(x), __PT_PARM3_REG)
#define PT_REGS_PARM4_CORE(x) BPF_CORE_READ(__PT_REGS_CAST(x), __PT_PARM4_REG)
#define PT_REGS_PARM5_CORE(x) BPF_CORE_READ(__PT_REGS_CAST(x), __PT_PARM5_REG)
#define PT_REGS_PARM6_CORE(x) BPF_CORE_READ(__PT_REGS_CAST(x), __PT_PARM6_REG)
#else
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
#endif
#define PT_REGS_PARM7_CORE(x) 0
#define PT_REGS_PARM8_CORE(x) 0
#define PT_REGS_PARM1_CORE_SYSCALL(x) PT_REGS_PARM1_CORE(x)
#define PT_REGS_PARM2_CORE_SYSCALL(x) PT_REGS_PARM2_CORE(x)
#define PT_REGS_PARM3_CORE_SYSCALL(x) PT_REGS_PARM3_CORE(x)
#ifdef MICRO_NATIVE_CORE_REG_PROBE_READS
#define PT_REGS_PARM4_CORE_SYSCALL(x) BPF_CORE_READ(__PT_REGS_CAST(x), r10)
#else
#define PT_REGS_PARM4_CORE_SYSCALL(x) PT_REGS_PARM4(x)
#endif
#define PT_REGS_PARM5_CORE_SYSCALL(x) PT_REGS_PARM5_CORE(x)
#define PT_REGS_PARM6_CORE_SYSCALL(x) PT_REGS_PARM6_CORE(x)
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

/* CO-RE answers come from the sole kernel's BTF (core-answers.py writes
 * core-compat-answers.h). Every query the app makes is a table entry; an
 * unlisted query fails the compile rather than defaulting. */
#ifdef __KPROG_SCAN_ONLY__
/* Scan mode: core-answers.py reads the AST to learn each query's base type. */
#define __kprog_scan_q(...) #__VA_ARGS__
static int __kprog_scan(const char *kind, const char *query, ...);
/* libbpf's two forms: `(expr)` and `(struct T, member)`. The second names a
 * type, which is not an expression, so the field expression is built from it. */
#define __kprog_scan_pos(kind, ...) __kprog_scan(kind, __kprog_scan_q(__VA_ARGS__), __VA_ARGS__)
#define __kprog_scan_type(kind, type, member) \
    __kprog_scan(kind, __kprog_scan_q(type, member), ((typeof(type) *)0)->member)
#define __kprog_scan_n(a, b, ...) __kprog_scan_n_(a, b, __VA_ARGS__)
#define __kprog_scan_n_(a, b, c, ...) c
#define __kprog_scan_disp(kind, ...) \
    __kprog_scan_n(__VA_ARGS__, __kprog_scan_type, __kprog_scan_pos)(kind, __VA_ARGS__)
#define bpf_core_field_exists(...) __kprog_scan_disp("field_exists", __VA_ARGS__)
#define bpf_core_field_size(...) __kprog_scan_disp("field_size", __VA_ARGS__)
#define bpf_core_field_offset(...) __kprog_scan_disp("field_offset", __VA_ARGS__)
/* A type is not an expression; a pointer to it is, and its pointee names the
 * type. `typeof(*p)` works here because the app declared `p`. */
#define bpf_core_type_exists(...) \
    __kprog_scan("type_exists", __kprog_scan_q(__VA_ARGS__), ((typeof(__VA_ARGS__) *)0))
#define bpf_core_type_size(...) \
    __kprog_scan("type_size", __kprog_scan_q(__VA_ARGS__), ((typeof(__VA_ARGS__) *)0))
#define bpf_core_type_matches(...) \
    __kprog_scan("type_matches", __kprog_scan_q(__VA_ARGS__), ((typeof(__VA_ARGS__) *)0))
#define bpf_core_enum_value_exists(...) \
    __kprog_scan("enum_value_exists", __kprog_scan_q(__VA_ARGS__), 0)
#define bpf_core_enum_value(...) \
    __kprog_scan("enum_value", __kprog_scan_q(__VA_ARGS__), 0)
#else
/* The query's own text, stringified before any macro inside it expands. */
#define __kprog_core_q(...) #__VA_ARGS__
static void __kprog_core_unanswered(void)
    __attribute__((error("CO-RE query is not in the answer table; "
                         "rerun core-answers.py for this app's sources")));
/* One table per app: the Makefile passes its path, and the default keeps a
 * single-app build working without it. */
#ifndef __KPROG_CORE_ANSWERS
#define __KPROG_CORE_ANSWERS "core-compat-answers.h"
#endif
#include __KPROG_CORE_ANSWERS
#endif /* __KPROG_SCAN_ONLY__ */

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

/* Helpers, one form for every app. Each helper is an ordinary extern function
 * that carries the kernel helper's name, which native-link binds; a call
 * reaches it through a function-like macro of the same name, so an app's own
 * helper declarations (libbpf's static pointers, OTel's pointer variables,
 * Tetragon's BPF_FUNC) stay unused. */
#define __KPROG_HELPER(ret, name, ...) extern ret __kprog_##name(__VA_ARGS__) __asm__(#name)
#define __KPROG_CALL(name, ...) __kprog_##name(__VA_ARGS__)
__KPROG_HELPER(void *, bpf_map_lookup_elem, void *, const void *);
__KPROG_HELPER(long, bpf_map_update_elem, void *, const void *, const void *, unsigned long long);
__KPROG_HELPER(long, bpf_map_delete_elem, void *, const void *);
__KPROG_HELPER(long, bpf_map_push_elem, void *, const void *, unsigned long long);
__KPROG_HELPER(long, bpf_map_pop_elem, void *, void *);
__KPROG_HELPER(long, bpf_probe_read, void *, unsigned int, const void *);
__KPROG_HELPER(long, bpf_probe_read_str, void *, unsigned int, const void *);
__KPROG_HELPER(long, bpf_probe_read_user, void *, unsigned int, const void *);
__KPROG_HELPER(long, bpf_probe_read_user_str, void *, unsigned int, const void *);
__KPROG_HELPER(long, bpf_probe_write_user, void *, const void *, unsigned int);
__KPROG_HELPER(long, bpf_copy_from_user, void *, unsigned int, const void *);
__KPROG_HELPER(unsigned long long, bpf_get_current_pid_tgid, void);
__KPROG_HELPER(unsigned long long, bpf_get_current_uid_gid, void);
__KPROG_HELPER(unsigned long long, bpf_ktime_get_ns, void);
__KPROG_HELPER(unsigned long long, bpf_ktime_get_boot_ns, void);
__KPROG_HELPER(unsigned int, bpf_get_smp_processor_id, void);
__KPROG_HELPER(unsigned int, bpf_get_prandom_u32, void);
__KPROG_HELPER(long, bpf_get_current_comm, void *, unsigned int);
__KPROG_HELPER(unsigned long long, bpf_get_current_cgroup_id, void);
__KPROG_HELPER(unsigned long long, bpf_get_current_task, void);
__KPROG_HELPER(void *, bpf_get_current_task_btf, void);
__KPROG_HELPER(unsigned long long, bpf_get_attach_cookie, void *);
__KPROG_HELPER(unsigned long long, bpf_get_func_ip, void *);
__KPROG_HELPER(long, bpf_get_func_arg, void *, unsigned int, unsigned long long *);
__KPROG_HELPER(long, bpf_get_func_ret, void *, unsigned long long *);
__KPROG_HELPER(long, bpf_get_func_arg_cnt, void *);
__KPROG_HELPER(long, bpf_ima_inode_hash, void *, void *, unsigned int);
__KPROG_HELPER(long, bpf_ima_file_hash, void *, void *, unsigned int);
__KPROG_HELPER(void *, bpf_task_pt_regs, void *);
__KPROG_HELPER(long, bpf_send_signal, unsigned int);
__KPROG_HELPER(long, bpf_override_return, void *, unsigned long long);
__KPROG_HELPER(long, bpf_perf_event_output, void *, void *, unsigned long long, void *, unsigned long long);
__KPROG_HELPER(long, bpf_trace_printk, const char *, unsigned int, unsigned long long, unsigned long long, unsigned long long);
__KPROG_HELPER(long, bpf_ringbuf_output, void *, void *, unsigned long long, unsigned long long);
__KPROG_HELPER(void *, bpf_ringbuf_reserve, void *, unsigned long long, unsigned long long);
__KPROG_HELPER(void, bpf_ringbuf_submit, void *, unsigned long long);
__KPROG_HELPER(void, bpf_ringbuf_discard, void *, unsigned long long);
__KPROG_HELPER(long, bpf_ringbuf_query, void *, unsigned long long);
__KPROG_HELPER(long, bpf_seq_write, void *, const void *, unsigned int);
__KPROG_HELPER(long, bpf_loop, unsigned int, void *, void *, unsigned long long);
__KPROG_HELPER(long, bpf_tail_call, void *, void *, unsigned int);
__KPROG_HELPER(long, bpf_current_task_under_cgroup, void *, unsigned int);
__KPROG_HELPER(long, bpf_get_stackid, void *, void *, unsigned long long);
__KPROG_HELPER(long, bpf_get_stack, void *, void *, unsigned int, unsigned long long);
__KPROG_HELPER(void *, bpf_sk_fullsock, void *);
__KPROG_HELPER(long, bpf_skb_load_bytes, void *, unsigned int, void *, unsigned int);
__KPROG_HELPER(long, bpf_skb_load_bytes_relative, void *, unsigned int, void *, unsigned int, unsigned int);

/* Kernel memory reads are plain loads. native-link records every load as a
 * load site, so a fault zeroes the loaded register and execution continues,
 * the JIT's PROBE_MEM behaviour. The empty asm keeps each loaded value in a
 * general register, the load site's recovery destination. */
typedef unsigned long long __attribute__((may_alias, aligned(1))) __kprog_u64;
typedef unsigned int __attribute__((may_alias, aligned(1))) __kprog_u32;
typedef unsigned short __attribute__((may_alias, aligned(1))) __kprog_u16;
#define __KPROG_LOAD(type, p) ({ type __v = *(const volatile type *)(p); asm volatile("" : "+r"(__v)); __v; })
static __always_inline long __kprog_read_kernel(void *dst, unsigned int size, const void *src)
{
    char *d = dst;
    const char *s = src;
    unsigned int i = 0;
    for (; i + 8 <= size; i += 8)
        *(__kprog_u64 *)(d + i) = __KPROG_LOAD(__kprog_u64, s + i);
    if (size & 4) { *(__kprog_u32 *)(d + i) = __KPROG_LOAD(__kprog_u32, s + i); i += 4; }
    if (size & 2) { *(__kprog_u16 *)(d + i) = __KPROG_LOAD(__kprog_u16, s + i); i += 2; }
    if (size & 1) d[i] = __KPROG_LOAD(char, s + i);
    return 0;
}
static __always_inline long __kprog_read_kernel_str(void *dst, unsigned int size, const void *src)
{
    char *d = dst;
    const char *s = src;
    unsigned int i = 0;
    if (!size)
        return 0;
    for (; i + 1 < size; i++) {
        char c = __KPROG_LOAD(char, s + i);
        d[i] = c;
        if (!c)
            return i + 1;
    }
    d[i] = 0;
    return size;
}
/* bpf_probe_read and bpf_probe_read_str pick kernel or user memory by address,
 * as the kernel's compat helpers do: upper-half addresses are read directly. */
#define __KPROG_KERNEL_ADDRESS(p) ((long)(unsigned long)(p) < 0)
static __always_inline long __kprog_probe_read(void *dst, unsigned int size, const void *src)
{
    return __KPROG_KERNEL_ADDRESS(src) ? __kprog_read_kernel(dst, size, src)
                                       : __kprog_bpf_probe_read(dst, size, src);
}
static __always_inline long __kprog_probe_read_str(void *dst, unsigned int size, const void *src)
{
    return __KPROG_KERNEL_ADDRESS(src) ? __kprog_read_kernel_str(dst, size, src)
                                       : __kprog_bpf_probe_read_str(dst, size, src);
}

#undef bpf_map_lookup_elem
#define bpf_map_lookup_elem(...) __KPROG_CALL(bpf_map_lookup_elem, __VA_ARGS__)
#undef bpf_map_update_elem
#define bpf_map_update_elem(...) __KPROG_CALL(bpf_map_update_elem, __VA_ARGS__)
#undef bpf_map_delete_elem
#define bpf_map_delete_elem(...) __KPROG_CALL(bpf_map_delete_elem, __VA_ARGS__)
#undef bpf_map_push_elem
#define bpf_map_push_elem(...) __KPROG_CALL(bpf_map_push_elem, __VA_ARGS__)
#undef bpf_map_pop_elem
#define bpf_map_pop_elem(...) __KPROG_CALL(bpf_map_pop_elem, __VA_ARGS__)
#undef bpf_probe_read_kernel
#define bpf_probe_read_kernel(...) __kprog_read_kernel(__VA_ARGS__)
#undef bpf_probe_read_kernel_str
#define bpf_probe_read_kernel_str(...) __kprog_read_kernel_str(__VA_ARGS__)
#undef bpf_probe_read
#define bpf_probe_read(...) __kprog_probe_read(__VA_ARGS__)
#undef bpf_probe_read_str
#define bpf_probe_read_str(...) __kprog_probe_read_str(__VA_ARGS__)
#undef bpf_probe_read_user
#define bpf_probe_read_user(...) __KPROG_CALL(bpf_probe_read_user, __VA_ARGS__)
#undef bpf_probe_read_user_str
#define bpf_probe_read_user_str(...) __KPROG_CALL(bpf_probe_read_user_str, __VA_ARGS__)
#undef bpf_probe_write_user
#define bpf_probe_write_user(...) __KPROG_CALL(bpf_probe_write_user, __VA_ARGS__)
#undef bpf_copy_from_user
#define bpf_copy_from_user(...) __KPROG_CALL(bpf_copy_from_user, __VA_ARGS__)
#undef bpf_get_current_pid_tgid
#define bpf_get_current_pid_tgid() __kprog_bpf_get_current_pid_tgid()
#undef bpf_get_current_uid_gid
#define bpf_get_current_uid_gid() __kprog_bpf_get_current_uid_gid()
#undef bpf_ktime_get_ns
#define bpf_ktime_get_ns() __kprog_bpf_ktime_get_ns()
#undef bpf_ktime_get_boot_ns
#define bpf_ktime_get_boot_ns() __kprog_bpf_ktime_get_boot_ns()
#undef bpf_get_smp_processor_id
#define bpf_get_smp_processor_id() __kprog_bpf_get_smp_processor_id()
#undef bpf_get_prandom_u32
#define bpf_get_prandom_u32() __kprog_bpf_get_prandom_u32()
#undef bpf_get_current_comm
#define bpf_get_current_comm(...) __KPROG_CALL(bpf_get_current_comm, __VA_ARGS__)
#undef bpf_get_current_cgroup_id
#define bpf_get_current_cgroup_id() __kprog_bpf_get_current_cgroup_id()
#undef bpf_get_current_task
#define bpf_get_current_task() __kprog_bpf_get_current_task()
#undef bpf_get_current_task_btf
#define bpf_get_current_task_btf() __kprog_bpf_get_current_task_btf()
#undef bpf_get_attach_cookie
#define bpf_get_attach_cookie(...) __KPROG_CALL(bpf_get_attach_cookie, __VA_ARGS__)
#undef bpf_get_func_ip
#define bpf_get_func_ip(...) __KPROG_CALL(bpf_get_func_ip, __VA_ARGS__)
#undef bpf_get_func_arg
#define bpf_get_func_arg(...) __KPROG_CALL(bpf_get_func_arg, __VA_ARGS__)
#undef bpf_get_func_ret
#define bpf_get_func_ret(...) __KPROG_CALL(bpf_get_func_ret, __VA_ARGS__)
#undef bpf_get_func_arg_cnt
#define bpf_get_func_arg_cnt(...) __KPROG_CALL(bpf_get_func_arg_cnt, __VA_ARGS__)
#undef bpf_ima_inode_hash
#define bpf_ima_inode_hash(...) __KPROG_CALL(bpf_ima_inode_hash, __VA_ARGS__)
#undef bpf_ima_file_hash
#define bpf_ima_file_hash(...) __KPROG_CALL(bpf_ima_file_hash, __VA_ARGS__)
#undef bpf_task_pt_regs
#define bpf_task_pt_regs(...) __KPROG_CALL(bpf_task_pt_regs, __VA_ARGS__)
#undef bpf_send_signal
#define bpf_send_signal(...) __KPROG_CALL(bpf_send_signal, __VA_ARGS__)
#undef bpf_override_return
#define bpf_override_return(...) __KPROG_CALL(bpf_override_return, __VA_ARGS__)
#undef bpf_perf_event_output
#define bpf_perf_event_output(...) __KPROG_CALL(bpf_perf_event_output, __VA_ARGS__)
/* trace_printk takes three format arguments and the kernel reads only the ones
 * the format names, so a short call pads with zeros. */
#define __kprog_trace_printk_pad(fmt, size, a1, a2, a3, ...) \
    __kprog_bpf_trace_printk((fmt), (size), (unsigned long long)(a1), \
                             (unsigned long long)(a2), (unsigned long long)(a3))
#undef bpf_trace_printk
#define bpf_trace_printk(...) __kprog_trace_printk_pad(__VA_ARGS__, 0, 0, 0)
#undef bpf_ringbuf_output
#define bpf_ringbuf_output(...) __KPROG_CALL(bpf_ringbuf_output, __VA_ARGS__)
#undef bpf_ringbuf_reserve
#define bpf_ringbuf_reserve(...) __KPROG_CALL(bpf_ringbuf_reserve, __VA_ARGS__)
#undef bpf_ringbuf_submit
#define bpf_ringbuf_submit(...) __KPROG_CALL(bpf_ringbuf_submit, __VA_ARGS__)
#undef bpf_ringbuf_discard
#define bpf_ringbuf_discard(...) __KPROG_CALL(bpf_ringbuf_discard, __VA_ARGS__)
#undef bpf_ringbuf_query
#define bpf_ringbuf_query(...) __KPROG_CALL(bpf_ringbuf_query, __VA_ARGS__)
#undef bpf_seq_write
#define bpf_seq_write(...) __KPROG_CALL(bpf_seq_write, __VA_ARGS__)
#undef bpf_loop
#define bpf_loop(...) __KPROG_CALL(bpf_loop, __VA_ARGS__)
#undef bpf_tail_call
#define bpf_tail_call(...) __KPROG_CALL(bpf_tail_call, __VA_ARGS__)
#undef bpf_current_task_under_cgroup
#define bpf_current_task_under_cgroup(...) __KPROG_CALL(bpf_current_task_under_cgroup, __VA_ARGS__)
#undef bpf_get_stackid
#define bpf_get_stackid(...) __KPROG_CALL(bpf_get_stackid, __VA_ARGS__)
#undef bpf_get_stack
#define bpf_get_stack(...) __KPROG_CALL(bpf_get_stack, __VA_ARGS__)
#undef bpf_sk_fullsock
#define bpf_sk_fullsock(...) __KPROG_CALL(bpf_sk_fullsock, __VA_ARGS__)
#undef bpf_skb_load_bytes
#define bpf_skb_load_bytes(...) __KPROG_CALL(bpf_skb_load_bytes, __VA_ARGS__)
#undef bpf_skb_load_bytes_relative
#define bpf_skb_load_bytes_relative(...) __KPROG_CALL(bpf_skb_load_bytes_relative, __VA_ARGS__)

#endif

#ifdef MICRO_NATIVE_TETRAGON
/* Tetragon's CONFIG() reads a rodata constant through BPF-target asm; natively
 * the constant is the declaration itself. */
#undef CONFIG
#define CONFIG(name) CONFIG_##name

/* kfuncs Tetragon calls. The one kernel's BTF dump carries no kfunc prototypes, so the
 * native compile declares them here, as the earlier generated header did. */
struct cgroup;
struct bpf_iter_num;
extern void bpf_cgroup_release(struct cgroup *cgrp) __attribute__((weak)) __attribute__((section(".ksyms")));
extern int bpf_copy_from_user_str(void *dst, unsigned int dst__sz, const void *unsafe_ptr__ign, unsigned long long flags) __attribute__((weak)) __attribute__((section(".ksyms")));
extern int bpf_iter_num_new(struct bpf_iter_num *it, int start, int end) __attribute__((weak)) __attribute__((section(".ksyms")));
extern int *bpf_iter_num_next(struct bpf_iter_num *it) __attribute__((weak)) __attribute__((section(".ksyms")));
extern void bpf_iter_num_destroy(struct bpf_iter_num *it) __attribute__((weak)) __attribute__((section(".ksyms")));

/* Tetragon's own helper names reach the common helpers above. */
#undef map_lookup_elem
#define map_lookup_elem(...) bpf_map_lookup_elem(__VA_ARGS__)
#undef map_update_elem
#define map_update_elem(...) bpf_map_update_elem(__VA_ARGS__)
#undef map_delete_elem
#define map_delete_elem(...) bpf_map_delete_elem(__VA_ARGS__)
#undef probe_read
#define probe_read(...) bpf_probe_read(__VA_ARGS__)
#undef probe_read_str
#define probe_read_str(...) bpf_probe_read_str(__VA_ARGS__)
#undef probe_read_kernel
#define probe_read_kernel(...) bpf_probe_read_kernel(__VA_ARGS__)
#undef probe_read_user
#define probe_read_user(...) bpf_probe_read_user(__VA_ARGS__)
#undef probe_write_user
#define probe_write_user(...) bpf_probe_write_user(__VA_ARGS__)
#undef copy_from_user
#define copy_from_user(...) bpf_copy_from_user(__VA_ARGS__)
#undef ktime_get_ns
#define ktime_get_ns() bpf_ktime_get_ns()
#undef ktime_get_boot_ns
#define ktime_get_boot_ns() bpf_ktime_get_boot_ns()
#undef get_smp_processor_id
#define get_smp_processor_id() bpf_get_smp_processor_id()
#undef get_current_pid_tgid
#define get_current_pid_tgid() bpf_get_current_pid_tgid()
#undef get_current_cgroup_id
#define get_current_cgroup_id() bpf_get_current_cgroup_id()
#undef get_current_task
#define get_current_task() bpf_get_current_task()
#undef get_stackid
#define get_stackid(...) bpf_get_stackid(__VA_ARGS__)
#undef perf_event_output
#define perf_event_output(...) bpf_perf_event_output(__VA_ARGS__)
#undef tail_call
#define tail_call(...) ((void)bpf_tail_call(__VA_ARGS__))
#undef send_signal
#define send_signal(...) bpf_send_signal(__VA_ARGS__)
#undef seq_write
#define seq_write(...) bpf_seq_write(__VA_ARGS__)
#undef ringbuf_output
#define ringbuf_output(...) bpf_ringbuf_output(__VA_ARGS__)
#undef loop
#define loop(...) bpf_loop(__VA_ARGS__)
#undef get_func_ret
#define get_func_ret(...) bpf_get_func_ret(__VA_ARGS__)
#undef get_func_arg
#define get_func_arg(...) bpf_get_func_arg(__VA_ARGS__)
#undef get_attach_cookie
#define get_attach_cookie(...) bpf_get_attach_cookie(__VA_ARGS__)
#undef ima_inode_hash
#define ima_inode_hash(...) bpf_ima_inode_hash(__VA_ARGS__)
#undef ima_file_hash
#define ima_file_hash(...) bpf_ima_file_hash(__VA_ARGS__)
#undef override_return
#define override_return(...) bpf_override_return(__VA_ARGS__)
#endif

/* access.h keeps a BPF-register asm arm under `__bpf__` and a plain C arm
 * otherwise; nothing is needed here. Cilium's own arms now split on `__bpf__`,
 * so a native target reaches the C arm. */
