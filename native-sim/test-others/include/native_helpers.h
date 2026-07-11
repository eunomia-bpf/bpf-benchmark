/*
 * Shared header for native-sim/test-others/ programs.
 *
 * BPF mode (`-target bpf`, no MICRO_NATIVE): pulls in libbpf helpers
 * + map-declaration macros. Programs use the standard SEC() decorations.
 *
 * Native-lab mode (`-target x86_64 -DMICRO_NATIVE`): every BPF helper
 * is declared as a plain C extern so clang emits a GOTPCREL relocation
 * (via -fno-plt) against the symbol name. native-link rewrites those
 * relocations to point at literal-pool entries holding the kernel
 * helper's kallsyms-resolved address. The `pt_regs` /
 * `bpf_raw_tracepoint_args` types are stubbed to empty structs since
 * the test programs don't read context fields -- they only increment
 * a map counter.
 *
 * NOTE: without this header, `<bpf/bpf_helpers.h>` defines helpers as
 * `((void *(*)(...))BPF_FUNC_xxx)` -- i.e. integer-literal-cast-to-
 * function-pointer. Under `-target x86_64` clang emits `mov eax,
 * <id>; call rax`, which is meaningless when the kop splats the
 * blob into the JIT image (RAX holds a tiny integer, the call jumps
 * to a tiny address, kernel oopses). The extern-declaration pattern
 * forces clang to emit a real GOTPCREL relocation that native-link
 * patches to the kallsyms address.
 */
#ifndef TEST_OTHERS_NATIVE_HELPERS_H
#define TEST_OTHERS_NATIVE_HELPERS_H

#ifdef MICRO_NATIVE

/* Minimal context-type stubs. Test programs don't read pt_regs or
 * bpf_raw_tracepoint_args fields; they only need the types to exist
 * so the BPF function signatures compile cleanly. */
struct pt_regs;
struct bpf_raw_tracepoint_args;

typedef unsigned int       __u32;
typedef unsigned long long __u64;

extern void *bpf_map_lookup_elem(void *map, const void *key);
extern long  bpf_map_update_elem(void *map, const void *key, const void *value,
                                 unsigned long long flags);
extern long  bpf_map_delete_elem(void *map, const void *key);

/* libbpf macros used in the map struct declaration. In native mode we
 * just need the struct to exist as a global symbol so native-link can
 * relocate `&my_map` references. */
#ifndef __uint
#define __uint(name, val) int (*name)[val]
#endif
#ifndef __type
#define __type(name, val) typeof(val) *name
#endif
#define BPF_MAP_TYPE_HASH          1
#define BPF_MAP_TYPE_ARRAY         2

/* SEC() macro is a no-op in native mode — clang doesn't emit a section
 * directive that matters for the .native.o → native-link → kop
 * pipeline (native-link reads the entry symbol by name + walks `.text`). */
#ifndef SEC
#define SEC(NAME) __attribute__((section(NAME), used))
#endif

#else /* !MICRO_NATIVE */

#include <linux/bpf.h>
#include <linux/types.h>
#include <bpf/bpf_helpers.h>
#include <bpf/bpf_tracing.h>

#endif /* MICRO_NATIVE */

#endif
