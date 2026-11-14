/* Same P/stock source; actual live map types, key sizes and mutable values. */
#include "../../test/include/native_helpers.h"
struct key { __u32 words[KEY_WORDS]; };
#if MAP_KIND == 13
struct inner { __uint(type, 2); __uint(max_entries, 1); __type(key, __u32); __type(value, __u64); };
#ifndef __array
#define __array(name, val) typeof(val) *name[]
#endif
struct { __uint(type, MAP_KIND); __uint(max_entries, 64); __type(key, struct key); __array(values, struct inner); } table __attribute__((section(".maps"),used));
#else
struct { __uint(type, MAP_KIND); __uint(max_entries, 64); __type(key, struct key); __type(value, __u64);
#if MAP_KIND == 11
    __uint(map_flags, 1); /* LPM requires BPF_F_NO_PREALLOC. */
#endif
} table __attribute__((section(".maps"),used));
#endif
SEC("raw_tp/sys_enter") int entry(const unsigned long *ctx)
{
    struct key key;
#if MAP_KIND == 11
    key.words[0]=ctx[1];
#pragma unroll
    for(unsigned i=1;i<KEY_WORDS;++i) key.words[i]=ctx[0]+i*0x1234567U;
#else
#pragma unroll
    for(unsigned i=0;i<KEY_WORDS;++i) key.words[i]=ctx[0]+i*0x1234567U;
#endif
    void *found=bpf_map_lookup_elem(&table,&key);
#if MAP_KIND == 13
    __u32 zero=0;
    __u64 *value=found ? bpf_map_lookup_elem(found,&zero) : 0;
#else
    __u64 *value=found;
#endif
    return value ? *value : 0;
}
char LICENSE[] SEC("license") = "GPL";
