/* Catch incorrect prefix limits, byte ordering, intermediate-node handling,
 * value offsets and widened reads. The oracle compares one bit at a time. */
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include "../../../vendor/bpf/native-lpm.h"
__KPROG_LPM_CODE

_Alignas(64) unsigned char map_a[4096], map_b[4096];
struct query { unsigned selector; unsigned char key[260]; };
extern void *entry(const void *);
extern void *entry_select(struct query *);
static unsigned long cases, generic_calls;
static unsigned long bytes;
static unsigned read32(const void *p) { unsigned v; memcpy(&v,p,4); return v; }
static void word(void *p, unsigned v) { memcpy(p,&v,4); }
static void pointer(void *p, void *v) { memcpy(p,&v,sizeof(v)); }
static unsigned char *root(const void *map)
{
    unsigned char *v; memcpy(&v,(const char *)map+ROOT_OFF,sizeof(v)); return v;
}
static void *reference(void *map, const void *key)
{
    unsigned key_prefix=read32(key), maximum=bytes*8;
    const unsigned char *bits=(const unsigned char *)key+4;
    if (key_prefix>maximum) return NULL;
    unsigned char *found=NULL;
    for (unsigned char *node=root(map); node;) {
        unsigned length=read32(node+PREFIX_OFF), limit=length<key_prefix ? length : key_prefix;
        unsigned match=0;
        while (match<limit && !((node[DATA_OFF+match/8]^bits[match/8]) & (128u>>(match%8)))) ++match;
        if (match==maximum) { found=node; break; }
        if (match<length) break;
        if (!(read32(node+FLAGS_OFF)&1)) found=node;
        unsigned bit=!!(bits[length/8] & (128u>>(length%8)));
        memcpy(&node,node+CHILD_OFF+bit*sizeof(void *),sizeof(node));
    }
    return found ? found+DATA_OFF+bytes : NULL;
}
void *bpf_map_lookup_elem(void *map, const void *key)
{
    ++generic_calls;
    return reference(map,key);
}
static void check(unsigned char *key)
{
    void *expected=reference(map_a,key);
    void *actual=__kprog_lpm_lookup(map_a,key,bytes,bytes*8,ROOT_OFF,CHILD_OFF,PREFIX_OFF,FLAGS_OFF,DATA_OFF);
    assert(actual==expected);
    assert(entry(key)==expected);
    struct query query={0}; memcpy(query.key,key,bytes+4);
    assert(entry_select(&query)==expected);
    ++cases;
}
static void shape(unsigned size, unsigned char *key)
{
    bytes=size;
    unsigned long maximum=bytes*8;
    memcpy(map_a+SIZE_OFF,&bytes,sizeof(bytes));
    memcpy(map_a+MAX_OFF,&maximum,sizeof(maximum));
    /* Allocation puts the last payload byte directly before PROT_NONE. */
    long page=sysconf(_SC_PAGESIZE);
    unsigned char *arena=mmap(NULL,page*2,PROT_READ|PROT_WRITE,MAP_PRIVATE|MAP_ANONYMOUS,-1,0);
    assert(arena!=MAP_FAILED && !mprotect(arena+page,page,PROT_NONE));
    unsigned char *node=arena+page-DATA_OFF-bytes;
    memset(node,0,DATA_OFF+bytes); memset(node+DATA_OFF,0x5a,bytes);
    pointer(map_a+ROOT_OFF,NULL); word(key,maximum); memcpy(key+4,node+DATA_OFF,bytes); check(key);
    pointer(map_a+ROOT_OFF,node);
    const unsigned step=maximum>128 ? 17 : 1;
    for (unsigned length=0; length<=maximum; length+=step) {
        word(node+PREFIX_OFF,length);
        for (unsigned flags=0;flags<2;++flags) {
            word(node+FLAGS_OFF,flags);
            unsigned limits[]={0,length ? length-1 : 0,length,length+1,maximum,maximum+1};
            for (unsigned l=0;l<sizeof(limits)/sizeof(limits[0]);++l) {
                word(key,limits[l]);
                memcpy(key+4,node+DATA_OFF,bytes); check(key);
                for (unsigned bit=0;bit<maximum;bit+=step) {
                    key[4+bit/8]^=128u>>(bit%8); check(key); key[4+bit/8]^=128u>>(bit%8);
                }
            }
        }
    }
    /* A valid increasing-prefix chain exercises child selection and parent
     * retention across an intermediate node and a later mismatch. */
    unsigned char *parent=calloc(1,DATA_OFF+bytes);
    assert(parent); memcpy(parent+DATA_OFF,node+DATA_OFF,bytes); word(parent+PREFIX_OFF,0);
    pointer(map_a+ROOT_OFF,parent); word(node+PREFIX_OFF,maximum); word(node+FLAGS_OFF,0);
    for (unsigned bit=0;bit<2;++bit) {
        pointer(parent+CHILD_OFF+bit*sizeof(void *),node);
        for(unsigned flags=0;flags<2;++flags) {
            word(parent+FLAGS_OFF,flags); word(key,maximum); memcpy(key+4,node+DATA_OFF,bytes); check(key);
            key[4]^=128; check(key); key[4]^=128;
        }
        pointer(parent+CHILD_OFF+bit*sizeof(void *),NULL);
    }
    free(parent); assert(!munmap(arena,page*2));
}
int main(void)
{
    long page=sysconf(_SC_PAGESIZE);
    unsigned char *arena=mmap(NULL,page*2,PROT_READ|PROT_WRITE,MAP_PRIVATE|MAP_ANONYMOUS,-1,0);
    assert(arena!=MAP_FAILED && !mprotect(arena+page,page,PROT_NONE));
#ifdef FIXED_KEY
    const unsigned sizes[]={12};
#else
    const unsigned sizes[]={1,2,3,4,5,7,8,9,12,16,17,32,256};
#endif
    for(unsigned i=0;i<sizeof(sizes)/sizeof(sizes[0]);++i) shape(sizes[i],arena+page-sizes[i]-4);
    assert(generic_calls==cases*EXPECTED_GENERIC);
    assert(!munmap(arena,page*2));
    printf("%lu cases, %lu generic calls\n",cases,generic_calls);
}
