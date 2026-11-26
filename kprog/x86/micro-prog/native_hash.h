/* kernel/bpf/hashtab.c hash-family element lookup and include/linux/jhash.h (lookup3,
 * Bob Jenkins, public domain). Layout comes from the one boot kernel's BTF.
 * The byte form equals jhash2 for word-sized keys on the supported little-endian paths. */
#ifndef KPROG_NATIVE_HASH_H
#define KPROG_NATIVE_HASH_H
#define __KPROG_HASH_CODE \
typedef unsigned int __kprog_hash_u32 __attribute__((aligned(1),may_alias)); \
typedef unsigned long long __kprog_hash_u64 __attribute__((aligned(1),may_alias)); \
static __attribute__((always_inline)) inline unsigned \
__kprog_hash_rol(unsigned value,unsigned bits) { return (value<<bits)|(value>>(32-bits)); } \
static __attribute__((always_inline)) inline unsigned \
__kprog_hash_bytes(const unsigned char *key,unsigned size,unsigned seed) { \
    unsigned a=0xdeadbeef+size+seed,b=a,c=a; \
    while (size>12) { \
        a+=*(const __kprog_hash_u32 *)key; \
        b+=*(const __kprog_hash_u32 *)(key+4); \
        c+=*(const __kprog_hash_u32 *)(key+8); \
        a-=c; a^=__kprog_hash_rol(c,4); c+=b; \
        b-=a; b^=__kprog_hash_rol(a,6); a+=c; \
        c-=b; c^=__kprog_hash_rol(b,8); b+=a; \
        a-=c; a^=__kprog_hash_rol(c,16); c+=b; \
        b-=a; b^=__kprog_hash_rol(a,19); a+=c; \
        c-=b; c^=__kprog_hash_rol(b,4); b+=a; \
        key+=12; size-=12; \
    } \
    if (size>=4) a+=*(const __kprog_hash_u32 *)key; \
    else for (unsigned i=0;i<size;++i) a+=(unsigned)key[i]<<(8*i); \
    if (size>=8) b+=*(const __kprog_hash_u32 *)(key+4); \
    else for (unsigned i=4;i<size;++i) b+=(unsigned)key[i]<<(8*(i-4)); \
    if (size==12) c+=*(const __kprog_hash_u32 *)(key+8); \
    else for (unsigned i=8;i<size;++i) c+=(unsigned)key[i]<<(8*(i-8)); \
    if (size) { \
        c^=b; c-=__kprog_hash_rol(b,14); \
        a^=c; a-=__kprog_hash_rol(c,11); \
        b^=a; b-=__kprog_hash_rol(a,25); \
        c^=b; c-=__kprog_hash_rol(b,16); \
        a^=c; a-=__kprog_hash_rol(c,4); \
        b^=a; b-=__kprog_hash_rol(a,14); \
        c^=b; c-=__kprog_hash_rol(b,24); \
    } \
    return c; \
} \
static __attribute__((always_inline)) inline int \
__kprog_hash_equal(const unsigned char *a,const unsigned char *b,unsigned size) { \
    unsigned i=0; \
    for (;size-i>=8;i+=8) \
        if (*(const __kprog_hash_u64 *)(a+i)!=*(const __kprog_hash_u64 *)(b+i)) return 0; \
    if (size-i>=4) { \
        if (*(const __kprog_hash_u32 *)(a+i)!=*(const __kprog_hash_u32 *)(b+i)) return 0; \
        i+=4; \
    } \
    for (;i<size;++i) if (a[i]!=b[i]) return 0; \
    return 1; \
} \
static __attribute__((always_inline)) inline void * \
__kprog_hash_elem(void *map,const void *key,unsigned size, \
    unsigned buckets,unsigned count,unsigned seed,unsigned stride,unsigned head, \
    unsigned hash_node,unsigned next,unsigned hash_offset,unsigned key_offset) { \
    unsigned hash=__kprog_hash_bytes(key,size,*(const unsigned *)((const unsigned char *)map+seed)); \
    unsigned index=hash & (*(const unsigned *)((const unsigned char *)map+count)-1); \
    unsigned char *table=*(unsigned char *const *)((const unsigned char *)map+buckets); \
    unsigned char *bucket=table+(unsigned long)index*stride+head; \
    unsigned char *node; \
    do { \
        __asm__ __volatile__("" ::: "memory"); \
        node=*(unsigned char *const volatile *)bucket; \
        while (!((unsigned long)node & 1)) { \
            unsigned char *element=node-hash_node; \
            if (*(const unsigned *)(element+hash_offset)==hash && \
                __kprog_hash_equal(element+key_offset,key,size)) \
                return element; \
            node=*(unsigned char *const volatile *)(node+next); \
        } \
    } while (((unsigned long)node>>1)!=index); \
    return (void *)0; \
} \
static __attribute__((always_inline)) inline void * \
__kprog_hash_lookup(void *map,const void *key,unsigned size, \
    unsigned buckets,unsigned count,unsigned seed,unsigned stride,unsigned head, \
    unsigned hash_node,unsigned next,unsigned hash_offset,unsigned key_offset) { \
    unsigned char *element=__kprog_hash_elem(map,key,size,buckets,count,seed,stride,head, \
                                          hash_node,next,hash_offset,key_offset); \
    return element ? element+key_offset+((size+7UL)&~7UL) : (void *)0; \
}
#endif
