/* Shared source for native helpers and the load-time C compiler. Offsets and
 * map sizes come from the boot kernel and the actual loaded map. */
#ifndef VENDOR_BPF_NATIVE_LPM_H
#define VENDOR_BPF_NATIVE_LPM_H
#define __KPROG_LPM_CODE \
typedef unsigned long long __kprog_lpm_u64 __attribute__((aligned(1),may_alias)); \
typedef unsigned int __kprog_lpm_u32 __attribute__((aligned(1),may_alias)); \
typedef unsigned short __kprog_lpm_u16 __attribute__((aligned(1),may_alias)); \
static __attribute__((always_inline)) inline unsigned \
__kprog_lpm_match(const unsigned char *node, const unsigned char *key, \
                  unsigned long bytes, unsigned limit) { \
    unsigned prefix=0; unsigned long i=0; \
    if (bytes>=8) { \
        unsigned long long d=__builtin_bswap64(*(const __kprog_lpm_u64 *)node ^ \
                                             *(const __kprog_lpm_u64 *)key); \
        prefix=d ? (unsigned)__builtin_clzll(d) : 64; \
        if (prefix>=limit) return limit; \
        if (d) return prefix; \
        i=8; \
    } \
    while (bytes>=i+4) { \
        unsigned d=__builtin_bswap32(*(const __kprog_lpm_u32 *)(node+i) ^ \
                                     *(const __kprog_lpm_u32 *)(key+i)); \
        prefix+=d ? (unsigned)__builtin_clz(d) : 32; \
        if (prefix>=limit) return limit; \
        if (d) return prefix; \
        i+=4; \
    } \
    if (bytes>=i+2) { \
        unsigned d=__builtin_bswap16(*(const __kprog_lpm_u16 *)(node+i) ^ \
                                     *(const __kprog_lpm_u16 *)(key+i)); \
        prefix+=d ? (unsigned)__builtin_clz(d)-16 : 16; \
        if (prefix>=limit) return limit; \
        if (d) return prefix; \
        i+=2; \
    } \
    if (bytes>=i+1) { \
        unsigned d=node[i]^key[i]; \
        prefix+=d ? (unsigned)__builtin_clz(d)-24 : 8; \
        if (prefix>=limit) return limit; \
    } \
    return prefix; \
} \
static __attribute__((always_inline)) inline void * \
__kprog_lpm_lookup(void *map, const void *key, unsigned long bytes, unsigned long maximum, \
    unsigned root, unsigned child, unsigned prefix, unsigned flags, unsigned data) { \
    unsigned key_prefix=*(const __kprog_lpm_u32 *)key; \
    if (key_prefix>maximum) return (void *)0; \
    unsigned char *node=*(unsigned char *const volatile *)((const unsigned char *)map+root); \
    unsigned char *found=(void *)0; \
    while (node) { \
        unsigned length=*(const __kprog_lpm_u32 *)(node+prefix); \
        unsigned limit=length<key_prefix ? length : key_prefix; \
        unsigned match=__kprog_lpm_match(node+data,(const unsigned char *)key+4,bytes,limit); \
        if (match==maximum) { found=node; break; } \
        if (match<length) break; \
        if (!(*(const __kprog_lpm_u32 *)(node+flags)&1)) found=node; \
        unsigned bit=!!(((const unsigned char *)key)[4+length/8] & (1u<<(7-length%8))); \
        node=*(unsigned char *const volatile *)(node+child+bit*sizeof(void *)); \
    } \
    return found ? found+data+bytes : (void *)0; \
}
#endif
