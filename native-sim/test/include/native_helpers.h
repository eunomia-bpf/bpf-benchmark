/*
 * Shared header for the Stage 2 native_lab test programs.
 *
 * BPF mode (`-target bpf`, no MICRO_NATIVE): pulls in libbpf helpers
 * + map-declaration macros (`__uint`, `__type`, BPF_MAP_TYPE_*).
 *
 * Native-lab mode (`-target x86_64 -DMICRO_NATIVE`): declares each BPF
 * helper as a plain C extern. clang emits a relocation against the
 * symbol name; native-link rewrites those relocations to call the real
 * kernel helper address harvested from the sibling .bpf.o's JIT image.
 * In native mode `__uint` / `__type` are stand-ins so the SEC(".maps")
 * struct still compiles -- its layout is irrelevant to the native code,
 * we only need the symbol to exist as a global so native-link can
 * relocate `&my_map` references.
 */

#ifndef NATIVE_HELPERS_H
#define NATIVE_HELPERS_H

#ifdef MICRO_NATIVE

/* common.h's MICRO_NATIVE branch sets up SEC, XDP_*, u8/u64 typedefs,
 * and ports stdint.h's __u32/__u64 names. Include it first so the helper
 * extern declarations below can use those typedefs. */
#include "../../../micro/programs/common.h"

#ifdef MICRO_NATIVE_USERSPACE
extern void *micro_native_bpf_map_lookup_elem(void *map, const void *key);
extern long  micro_native_bpf_map_update_elem(void *map, const void *key,
                                              const void *value,
                                              unsigned long long flags);
extern long  micro_native_bpf_map_delete_elem(void *map, const void *key);
extern unsigned long long micro_native_bpf_ktime_get_ns(void);
extern unsigned long long micro_native_bpf_ktime_get_boot_ns(void);
extern unsigned long long micro_native_bpf_get_current_pid_tgid(void);
extern unsigned int       micro_native_bpf_get_smp_processor_id(void);
extern unsigned long long micro_native_bpf_get_current_uid_gid(void);
extern unsigned int       micro_native_bpf_get_prandom_u32(void);
extern long               micro_native_bpf_probe_read_kernel(void *dst,
                                                            unsigned int size,
                                                            const void *unsafe_ptr);

#define bpf_map_lookup_elem micro_native_bpf_map_lookup_elem
#define bpf_map_update_elem micro_native_bpf_map_update_elem
#define bpf_map_delete_elem micro_native_bpf_map_delete_elem
#define bpf_ktime_get_ns micro_native_bpf_ktime_get_ns
#define bpf_ktime_get_boot_ns micro_native_bpf_ktime_get_boot_ns
#define bpf_get_current_pid_tgid micro_native_bpf_get_current_pid_tgid
#define bpf_get_smp_processor_id micro_native_bpf_get_smp_processor_id
#define bpf_get_current_uid_gid micro_native_bpf_get_current_uid_gid
#define bpf_get_prandom_u32 micro_native_bpf_get_prandom_u32
#define bpf_probe_read_kernel micro_native_bpf_probe_read_kernel
#else
extern void *bpf_map_lookup_elem(void *map, const void *key);
extern long  bpf_map_update_elem(void *map, const void *key, const void *value,
                                 unsigned long long flags);
extern long  bpf_map_delete_elem(void *map, const void *key);
extern unsigned long long bpf_ktime_get_ns(void);
extern unsigned long long bpf_ktime_get_boot_ns(void);
extern unsigned long long bpf_get_current_pid_tgid(void);
extern unsigned int       bpf_get_smp_processor_id(void);
extern unsigned long long bpf_get_current_uid_gid(void);
extern unsigned int       bpf_get_prandom_u32(void);
extern long               bpf_probe_read_kernel(void *dst, unsigned int size,
                                                 const void *unsafe_ptr);
#endif

/* libbpf macros used in the map struct declaration. In native mode we
 * just need the struct to exist as a global symbol; field layout is
 * unused. */
#ifndef __uint
#define __uint(name, val) int (*name)[val]
#endif
#ifndef __type
#define __type(name, val) typeof(val) *name
#endif
#ifndef BPF_MAP_TYPE_ARRAY
#define BPF_MAP_TYPE_UNSPEC        0
#define BPF_MAP_TYPE_HASH          1
#define BPF_MAP_TYPE_ARRAY         2
#define BPF_MAP_TYPE_PERCPU_HASH   5
#define BPF_MAP_TYPE_PERCPU_ARRAY  6
#define BPF_MAP_TYPE_LRU_HASH      9
#define BPF_MAP_TYPE_LRU_PERCPU_HASH 10
#endif

#else /* !MICRO_NATIVE */

#include <linux/bpf.h>
#include <bpf/bpf_helpers.h>
#include "../../../micro/programs/common.h"

#endif /* MICRO_NATIVE */

#endif /* NATIVE_HELPERS_H */
