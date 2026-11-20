/* Shared source for native helpers and the load-time C compiler. Offsets and
 * map sizes come from the boot kernel and the actual loaded map. */
#ifndef VENDOR_BPF_NATIVE_LPM_H
#define VENDOR_BPF_NATIVE_LPM_H
#define __KPROG_LPM_CODE \
typedef unsigned long long __kprog_lpm_u64 __attribute__((aligned(1),may_alias)); \
typedef unsigned int __kprog_lpm_u32 __attribute__((aligned(1),may_alias)); \
typedef unsigned short __kprog_lpm_u16 __attribute__((aligned(1),may_alias)); \
static __attribute__((always_inline)) inline int \
__kprog_lpm_prefix_equal(const unsigned char *node, const unsigned char *key, unsigned long bytes, unsigned bits) { \
    if (!bits) return 1; \
    unsigned long i=0; \
    if (bytes>=8) { \
        __kprog_lpm_u64 different=*(const __kprog_lpm_u64 *)node ^ *(const __kprog_lpm_u64 *)key; \
        if (bits<=64) return !(__builtin_bswap64(different)>>(64-bits)); \
        if (different) return 0; \
        bits-=64; i=8; \
    } \
    while (bytes-i>=4) { \
        __kprog_lpm_u32 different=*(const __kprog_lpm_u32 *)(node+i) ^ *(const __kprog_lpm_u32 *)(key+i); \
        if (bits<=32) return !(__builtin_bswap32(different)>>(32-bits)); \
        if (different) return 0; \
        bits-=32; i+=4; \
    } \
    if (bytes-i>=2) { \
        unsigned different=__builtin_bswap16(*(const __kprog_lpm_u16 *)(node+i) ^ *(const __kprog_lpm_u16 *)(key+i)); \
        if (bits<=16) return !(different>>(16-bits)); \
        if (different) return 0; \
        bits-=16; i+=2; \
    } \
    return !((node[i]^key[i])>>(8-bits)); \
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
        if (length>key_prefix || !__kprog_lpm_prefix_equal(node+data,(const unsigned char *)key+4,bytes,length)) break; \
        if (length==maximum) { found=node; break; } \
        if (!(*(const __kprog_lpm_u32 *)(node+flags)&1)) found=node; \
        unsigned bit=!!(((const unsigned char *)key)[4+length/8] & (1u<<(7-length%8))); \
        node=*(unsigned char *const volatile *)(node+child+bit*sizeof(void *)); \
    } \
    return found ? found+data+bytes : (void *)0; \
}
#endif
