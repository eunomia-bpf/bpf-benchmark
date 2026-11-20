/* Shared source for native helpers and the load-time C compiler. Offsets and
 * map sizes come from the boot kernel and the actual loaded map. */
#ifndef VENDOR_BPF_NATIVE_LPM_H
#define VENDOR_BPF_NATIVE_LPM_H
#define __KPROG_LPM_CODE \
typedef unsigned long long __kprog_lpm_u64 __attribute__((aligned(1),may_alias)); \
typedef unsigned int __kprog_lpm_u32 __attribute__((aligned(1),may_alias)); \
typedef unsigned short __kprog_lpm_u16 __attribute__((aligned(1),may_alias)); \
static __attribute__((always_inline)) inline int \
__kprog_lpm_prefix_equal(const unsigned char *node, const unsigned char *key, unsigned bits) { \
    unsigned long i=0; \
    if (bits>=64) { \
        if (*(const __kprog_lpm_u64 *)node != *(const __kprog_lpm_u64 *)key) return 0; \
        bits-=64; i=8; \
    } \
    while (bits>=32) { \
        if (*(const __kprog_lpm_u32 *)(node+i) != *(const __kprog_lpm_u32 *)(key+i)) return 0; \
        bits-=32; i+=4; \
    } \
    if (bits>=16) { \
        if (*(const __kprog_lpm_u16 *)(node+i) != *(const __kprog_lpm_u16 *)(key+i)) return 0; \
        bits-=16; i+=2; \
    } \
    if (bits>=8) { \
        if (node[i]!=key[i]) return 0; \
        bits-=8; ++i; \
    } \
    return !bits || !((node[i]^key[i])>>(8-bits)); \
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
        if (length>key_prefix || !__kprog_lpm_prefix_equal(node+data,(const unsigned char *)key+4,length)) break; \
        if (length==maximum) { found=node; break; } \
        if (!(*(const __kprog_lpm_u32 *)(node+flags)&1)) found=node; \
        unsigned bit=!!(((const unsigned char *)key)[4+length/8] & (1u<<(7-length%8))); \
        if (bit) node=*(unsigned char *const volatile *)(node+child+sizeof(void *)); \
        else node=*(unsigned char *const volatile *)(node+child); \
    } \
    return found ? found+data+bytes : (void *)0; \
}
#endif
