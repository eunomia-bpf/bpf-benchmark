/* CO-RE metadata overlay on the current native compatibility/helper base.
 * Only target-BTF answer tables are generated; application C is unchanged. */
#ifndef VENDOR_BPF_CORE_COMPAT_H
#define VENDOR_BPF_CORE_COMPAT_H
#include "native_compat.h"

#undef __builtin_preserve_access_index
#undef bpf_core_field_exists
#undef bpf_core_field_size
#undef bpf_core_field_offset
#undef bpf_core_type_exists
#undef bpf_core_type_size
#undef bpf_core_type_matches
#undef bpf_core_enum_value_exists
#undef bpf_core_enum_value
#undef bpf_core_read
#undef bpf_core_read_user
#undef __native_core_read_into_1
#undef __native_core_read_into_2
#undef __native_core_read_into_3
#undef __native_core_read_into_4
#undef __native_core_read_into_5
#undef __native_core_read_into_6

#ifdef __KPROG_SCAN_ONLY__
static unsigned long __kprog_scan_access(const char *, const char *, ...);
#define __builtin_preserve_access_index(expr) \
    ((typeof(expr))__kprog_scan_access("access_delta", #expr, (expr), __FILE__, __LINE__))
#else
#define __builtin_preserve_access_index(expr) \
    __builtin_choose_expr(__builtin_classify_type(expr) == 5, \
        (typeof(expr))(unsigned long)((char *)(unsigned long)(expr) + \
            __kprog_core_lookup_access_delta(#expr, __FILE__, __LINE__)), \
        (__kprog_core_lookup_access_delta(#expr, __FILE__, __LINE__), (expr)))
#endif

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
/* Like libbpf's poisoned relocation: dead accesses fold away; a live marker
 * has no target and the existing native linker refuses it. */
extern void __kprog_core_poisoned(void);
/* One table per app: the Makefile passes its path, and the default keeps a
 * single-app build working without it. */
#ifndef __KPROG_CORE_ANSWERS
#define __KPROG_CORE_ANSWERS "core-compat-answers.h"
#endif
#include __KPROG_CORE_ANSWERS
#endif /* __KPROG_SCAN_ONLY__ */


#define __native_core_read_into_1(fn, dst, src, a) \
    fn((dst), sizeof(*(dst)), __builtin_preserve_access_index(&((src)->a)))
#define __native_core_read_into_2(fn, dst, src, a, b) ({ \
    typeof((src)->a) __t1; \
    bpf_probe_read_kernel(&__t1, sizeof(__t1), __builtin_preserve_access_index(&((src)->a))); \
    fn((dst), sizeof(*(dst)), __builtin_preserve_access_index(&(__t1->b))); \
})
#define __native_core_read_into_3(fn, dst, src, a, b, c) ({ \
    typeof((src)->a) __t1; \
    typeof(__t1->b) __t2; \
    bpf_probe_read_kernel(&__t1, sizeof(__t1), __builtin_preserve_access_index(&((src)->a))); \
    bpf_probe_read_kernel(&__t2, sizeof(__t2), __builtin_preserve_access_index(&(__t1->b))); \
    fn((dst), sizeof(*(dst)), __builtin_preserve_access_index(&(__t2->c))); \
})
#define __native_core_read_into_4(fn, dst, src, a, b, c, d) ({ \
    typeof((src)->a) __t1; \
    typeof(__t1->b) __t2; \
    typeof(__t2->c) __t3; \
    bpf_probe_read_kernel(&__t1, sizeof(__t1), __builtin_preserve_access_index(&((src)->a))); \
    bpf_probe_read_kernel(&__t2, sizeof(__t2), __builtin_preserve_access_index(&(__t1->b))); \
    bpf_probe_read_kernel(&__t3, sizeof(__t3), __builtin_preserve_access_index(&(__t2->c))); \
    fn((dst), sizeof(*(dst)), __builtin_preserve_access_index(&(__t3->d))); \
})
#define __native_core_read_into_5(fn, dst, src, a, b, c, d, e) ({ \
    typeof((src)->a) __t1; \
    typeof(__t1->b) __t2; \
    typeof(__t2->c) __t3; \
    typeof(__t3->d) __t4; \
    bpf_probe_read_kernel(&__t1, sizeof(__t1), __builtin_preserve_access_index(&((src)->a))); \
    bpf_probe_read_kernel(&__t2, sizeof(__t2), __builtin_preserve_access_index(&(__t1->b))); \
    bpf_probe_read_kernel(&__t3, sizeof(__t3), __builtin_preserve_access_index(&(__t2->c))); \
    bpf_probe_read_kernel(&__t4, sizeof(__t4), __builtin_preserve_access_index(&(__t3->d))); \
    fn((dst), sizeof(*(dst)), __builtin_preserve_access_index(&(__t4->e))); \
})
#define __native_core_read_into_6(fn, dst, src, a, b, c, d, e, f) ({ \
    typeof((src)->a) __t1; \
    typeof(__t1->b) __t2; \
    typeof(__t2->c) __t3; \
    typeof(__t3->d) __t4; \
    typeof(__t4->e) __t5; \
    bpf_probe_read_kernel(&__t1, sizeof(__t1), __builtin_preserve_access_index(&((src)->a))); \
    bpf_probe_read_kernel(&__t2, sizeof(__t2), __builtin_preserve_access_index(&(__t1->b))); \
    bpf_probe_read_kernel(&__t3, sizeof(__t3), __builtin_preserve_access_index(&(__t2->c))); \
    bpf_probe_read_kernel(&__t4, sizeof(__t4), __builtin_preserve_access_index(&(__t3->d))); \
    bpf_probe_read_kernel(&__t5, sizeof(__t5), __builtin_preserve_access_index(&(__t4->e))); \
    fn((dst), sizeof(*(dst)), __builtin_preserve_access_index(&(__t5->f))); \
})

#define bpf_core_read(dst, sz, src) \
    bpf_probe_read_kernel((dst), (sz), __builtin_preserve_access_index(src))
#define bpf_core_read_user(dst, sz, src) \
    bpf_probe_read_user((dst), (sz), __builtin_preserve_access_index(src))
#endif
