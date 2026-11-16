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

/* An app that declares its helpers as function-pointer variables (the libbpf
 * style OTel uses) reaches them through __kprog_extern_helper, which names the
 * object the same way with the declaration folded into a typedef. */
#ifndef __KPROG_HELPERS_ARE_POINTERS
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
#endif /* __KPROG_HELPERS_ARE_POINTERS */

#ifdef MICRO_NATIVE_HELPER_MACROS
static __always_inline unsigned long native_helper_id0(unsigned long id)
{
    asm volatile("" : "+r"(id) : : "memory");
    return id;
}

static __always_inline unsigned long native_helper_id1(unsigned long id,
                                                       unsigned long a0)
{
    asm volatile("" : "+r"(id) : "r"(a0) : "memory");
    return id;
}

static __always_inline unsigned long native_helper_id2(unsigned long id,
                                                       unsigned long a0,
                                                       unsigned long a1)
{
    asm volatile("" : "+r"(id) : "r"(a0), "r"(a1) : "memory");
    return id;
}

static __always_inline unsigned long native_helper_id3(unsigned long id,
                                                       unsigned long a0,
                                                       unsigned long a1,
                                                       unsigned long a2)
{
    asm volatile("" : "+r"(id) : "r"(a0), "r"(a1), "r"(a2) : "memory");
    return id;
}

static __always_inline unsigned long native_helper_id4(unsigned long id,
                                                       unsigned long a0,
                                                       unsigned long a1,
                                                       unsigned long a2,
                                                       unsigned long a3)
{
    asm volatile("" : "+r"(id) : "r"(a0), "r"(a1), "r"(a2), "r"(a3)
                 : "memory");
    return id;
}

static __always_inline unsigned long native_helper_id5(unsigned long id,
                                                       unsigned long a0,
                                                       unsigned long a1,
                                                       unsigned long a2,
                                                       unsigned long a3,
                                                       unsigned long a4)
{
    asm volatile("" : "+r"(id)
                 : "r"(a0), "r"(a1), "r"(a2), "r"(a3), "r"(a4)
                 : "memory");
    return id;
}

#define native_bpf_helper0(type, id) ((type)native_helper_id0((unsigned long)(id)))
#define native_bpf_helper1(type, id, a0) \
    ((type)native_helper_id1((unsigned long)(id), (unsigned long)(a0)))
#define __kprog_va1(a, ...) a

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
#define NATIVE_BPF_FUNC_trace_printk 6
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
/* trace_printk takes three format arguments in registers and the kernel reads
 * only the ones the format names, so a short call pads with zeros. */
static __always_inline long __kprog_trace_printk(const char *fmt, unsigned int size,
                                                 unsigned long long a1,
                                                 unsigned long long a2,
                                                 unsigned long long a3)
{
    return (long)native_helper_id5(NATIVE_BPF_FUNC_trace_printk,
                                   (unsigned long)fmt, (unsigned long)size,
                                   a1, a2, a3);
}
#define __kprog_trace_printk_pad(fmt, size, a1, a2, a3, ...) \
    __kprog_trace_printk((fmt), (size), (unsigned long long)(a1), \
                         (unsigned long long)(a2), (unsigned long long)(a3))
#undef bpf_trace_printk
#define bpf_trace_printk(...) __kprog_trace_printk_pad(__VA_ARGS__, 0, 0, 0)
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

/* Tetragon's api.h uses bare helper names. Ordinary typed C calls expose
 * every SysV caller-saved register and stack alignment requirement to clang.
 * native-link resolves their numeric helper identities, including CFG joins. */
#define __KPROG_TG_HELPER0(rettype, id) \
    (((rettype (*)(void))(unsigned long)(id))())
#define __KPROG_TG_HELPER1(rettype, id, a0) \
    (((rettype (*)(unsigned long))(unsigned long)(id))((unsigned long)(a0)))
#define __KPROG_TG_HELPER2(rettype, id, a0, a1) \
    (((rettype (*)(unsigned long, unsigned long))(unsigned long)(id))((unsigned long)(a0), (unsigned long)(a1)))
#define __KPROG_TG_HELPER3(rettype, id, a0, a1, a2) \
    (((rettype (*)(unsigned long, unsigned long, unsigned long))(unsigned long)(id))((unsigned long)(a0), (unsigned long)(a1), (unsigned long)(a2)))
#define __KPROG_TG_HELPER4(rettype, id, a0, a1, a2, a3) \
    (((rettype (*)(unsigned long, unsigned long, unsigned long, unsigned long))(unsigned long)(id))((unsigned long)(a0), (unsigned long)(a1), (unsigned long)(a2), (unsigned long)(a3)))
#define __KPROG_TG_HELPER5(rettype, id, a0, a1, a2, a3, a4) \
    (((rettype (*)(unsigned long, unsigned long, unsigned long, unsigned long, unsigned long))(unsigned long)(id))((unsigned long)(a0), (unsigned long)(a1), (unsigned long)(a2), (unsigned long)(a3), (unsigned long)(a4)))

#undef map_lookup_elem
#define map_lookup_elem(map, key) \
    __KPROG_TG_HELPER2(void *, NATIVE_BPF_FUNC_map_lookup_elem, (map), (key))
#undef map_update_elem
#define map_update_elem(map, key, value, flags) \
    __KPROG_TG_HELPER4(int, NATIVE_BPF_FUNC_map_update_elem, (map), (key), (value), (flags))
#undef map_delete_elem
#define map_delete_elem(map, key) \
    __KPROG_TG_HELPER2(int, NATIVE_BPF_FUNC_map_delete_elem, (map), (key))
#undef probe_read
#define probe_read(dst, size, src) \
    __KPROG_TG_HELPER3(int, NATIVE_BPF_FUNC_probe_read, (dst), (size), (src))
#undef probe_read_str
#define probe_read_str(dst, size, src) \
    __KPROG_TG_HELPER3(int, NATIVE_BPF_FUNC_probe_read_str, (dst), (size), (src))
#undef probe_read_kernel
#define probe_read_kernel(dst, size, src) \
    __KPROG_TG_HELPER3(int, NATIVE_BPF_FUNC_probe_read_kernel, (dst), (size), (src))
#undef probe_read_user
#define probe_read_user(dst, size, src) \
    __KPROG_TG_HELPER3(int, NATIVE_BPF_FUNC_probe_read_user, (dst), (size), (src))
#undef probe_write_user
#define probe_write_user(dst, src, len) \
    __KPROG_TG_HELPER3(int, NATIVE_BPF_FUNC_probe_write_user, (dst), (src), (len))
#undef copy_from_user
#define copy_from_user(dst, size, src) \
    __KPROG_TG_HELPER3(int, NATIVE_BPF_FUNC_copy_from_user, (dst), (size), (src))
#undef ktime_get_ns
#define ktime_get_ns() \
    __KPROG_TG_HELPER0(unsigned long long, NATIVE_BPF_FUNC_ktime_get_ns)
#undef ktime_get_boot_ns
#define ktime_get_boot_ns() \
    __KPROG_TG_HELPER0(unsigned long long, NATIVE_BPF_FUNC_ktime_get_boot_ns)
#undef get_smp_processor_id
#define get_smp_processor_id() \
    __KPROG_TG_HELPER0(unsigned int, NATIVE_BPF_FUNC_get_smp_processor_id)
#undef get_current_pid_tgid
#define get_current_pid_tgid() \
    __KPROG_TG_HELPER0(unsigned long long, NATIVE_BPF_FUNC_get_current_pid_tgid)
#undef get_current_cgroup_id
#define get_current_cgroup_id() \
    __KPROG_TG_HELPER0(unsigned long long, NATIVE_BPF_FUNC_get_current_cgroup_id)
#undef get_current_task
#define get_current_task() \
    __KPROG_TG_HELPER0(unsigned long long, NATIVE_BPF_FUNC_get_current_task)
#undef get_stackid
#define get_stackid(ctx, map, flags) \
    __KPROG_TG_HELPER3(long, NATIVE_BPF_FUNC_get_stackid, (ctx), (map), (flags))
#undef perf_event_output
#define perf_event_output(ctx, map, flags, data, size) \
    __KPROG_TG_HELPER5(int, NATIVE_BPF_FUNC_perf_event_output, \
                       (ctx), (map), (flags), (data), (size))
#define __KPROG_TG_HELPER3V(id, a0, a1, a2) \
    __KPROG_TG_HELPER3(void, (id), (a0), (a1), (a2))
#undef tail_call
#define tail_call(ctx, map, index) \
    (__KPROG_TG_HELPER3V(NATIVE_BPF_FUNC_tail_call, (ctx), (map), (index)), (void)0)
#undef send_signal
#define send_signal(sig) \
    __KPROG_TG_HELPER1(int, NATIVE_BPF_FUNC_send_signal, (sig))
#undef seq_write
#define seq_write(seq, data, len) \
    __KPROG_TG_HELPER3(int, NATIVE_BPF_FUNC_seq_write, (seq), (data), (len))
#undef ringbuf_output
#define ringbuf_output(ringbuf, data, size, flags) \
    __KPROG_TG_HELPER4(long, NATIVE_BPF_FUNC_ringbuf_output, \
                       (ringbuf), (data), (size), (flags))
#undef loop
#define loop(nr_loops, callback_fn, ctx, flags) \
    __KPROG_TG_HELPER4(long, NATIVE_BPF_FUNC_loop, \
                       (nr_loops), (callback_fn), (ctx), (flags))
#undef get_func_ret
#define get_func_ret(ctx, value) \
    __KPROG_TG_HELPER2(int, NATIVE_BPF_FUNC_get_func_ret, (ctx), (value))
#undef get_func_arg
#define get_func_arg(ctx, n, value) \
    __KPROG_TG_HELPER3(int, NATIVE_BPF_FUNC_get_func_arg, (ctx), (n), (value))
#undef get_attach_cookie
#define get_attach_cookie(ctx) \
    __KPROG_TG_HELPER1(unsigned long long, NATIVE_BPF_FUNC_get_attach_cookie, (ctx))
#undef ima_inode_hash
#define ima_inode_hash(inode, dst, size) \
    __KPROG_TG_HELPER3(long, NATIVE_BPF_FUNC_ima_inode_hash, (inode), (dst), (size))
#undef ima_file_hash
#define ima_file_hash(file, dst, size) \
    __KPROG_TG_HELPER3(long, NATIVE_BPF_FUNC_ima_file_hash, (file), (dst), (size))
#undef override_return
#define override_return(ctx, rc) \
    __KPROG_TG_HELPER2(int, NATIVE_BPF_FUNC_override_return, (ctx), (rc))
#endif

/* access.h keeps a BPF-register asm arm under `__bpf__` and a plain C arm
 * otherwise; nothing is needed here. Cilium's own arms now split on `__bpf__`,
 * so a native target reaches the C arm. */
