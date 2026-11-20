/* Compare the C/native helper with the sole kernel's actual jhash header.
 * Catch key overreads, seed/bucket errors, collision handling, padded value
 * offsets, mixed-map selection and the nulls restart after a bucket move. */
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <unistd.h>
#include "kernel_hash_reference.h"
#include "../../x86/micro-prog/native_hash.h"
__KPROG_HASH_CODE
_Alignas(64) unsigned char map_a[4096],map_b[4096],map_c[4096];
extern unsigned char map_same[4096] __attribute__((alias("map_a")));
extern void *entry(const void *);
extern void *entry_b(const void *);
extern void *entry_same(const void *);
struct query { unsigned selector; unsigned char key[260]; };
extern void *entry_select(struct query *);
extern void *entry_unknown(const void *);
static unsigned cases,hash_cases,restarts,generic_calls,same_map_aliases;
static void word(void *p,unsigned v) { memcpy(p,&v,4); }
static void pointer(void *p,void *v) { memcpy(p,&v,sizeof(v)); }
static unsigned read_word(const void *p) { unsigned v;memcpy(&v,p,4);return v; }
static void *read_pointer(const void *p) { void *v;memcpy(&v,p,sizeof(v));return v; }
static unsigned hash(const void *key,unsigned size,unsigned seed)
{ return size%4 ? jhash(key,size,seed) : jhash2(key,size/4,seed); }
static void *reference(void *map,const void *key,unsigned size)
{
    unsigned h=hash(key,size,read_word((char *)map+SEED));
    unsigned index=h&(read_word((char *)map+COUNT)-1);
    unsigned char *table=read_pointer((char *)map+BUCKETS);
    unsigned char *node=read_pointer(table+index*STRIDE+HEAD);
    while (!((uintptr_t)node&1)) {
        unsigned char *element=node-HASH_NODE;
        if (read_word(element+HASH_OFFSET)==h && !memcmp(element+KEY_OFFSET,key,size))
            return element+KEY_OFFSET+((size+7)&~7U);
        node=read_pointer(node+NEXT);
    }
    assert(((uintptr_t)node>>1)==index);
    return NULL;
}
void *bpf_map_lookup_elem(void *map,const void *key)
{
    ++generic_calls;assert(key);
    if(map==map_a) return reference(map,key,8);
    if(map==map_b) return reference(map,key,16);
    assert(map==map_c);return map_c;
}
static void *actual(void *map,const void *key,unsigned size)
{ return __kprog_hash_lookup(map,key,size,BUCKETS,COUNT,SEED,STRIDE,HEAD,HASH_NODE,NEXT,HASH_OFFSET,KEY_OFFSET); }
static void shape(unsigned char *key,unsigned size,unsigned seed,unsigned count)
{
    unsigned char *table=calloc(count,STRIDE);assert(table);
    for(unsigned i=0;i<count;++i) pointer(table+i*STRIDE+HEAD,(void *)((uintptr_t)i*2+1));
    pointer(map_a+BUCKETS,table);word(map_a+COUNT,count);word(map_a+SEED,seed);
    unsigned h=hash(key,size,seed),index=h&(count-1);
    unsigned char *nodes[3];
    for(unsigned i=0;i<3;++i) {
        nodes[i]=calloc(1,KEY_OFFSET+((size+7)&~7U)+8);assert(nodes[i]);
        memcpy(nodes[i]+KEY_OFFSET,key,size);word(nodes[i]+HASH_OFFSET,h);
        pointer(nodes[i]+HASH_NODE+NEXT,(void *)((uintptr_t)index*2+1));
    }
    for(unsigned n=0;n<=3;++n) {
        pointer(table+index*STRIDE+HEAD,n ? nodes[0]+HASH_NODE : (void *)((uintptr_t)index*2+1));
        for(unsigned i=0;i<n;++i) pointer(nodes[i]+HASH_NODE+NEXT,
            i+1<n ? nodes[i+1]+HASH_NODE : (void *)((uintptr_t)index*2+1));
        for(unsigned match=0;match<=n;++match) for(unsigned bad_hash=0;bad_hash<2;++bad_hash) {
            for(unsigned i=0;i<n;++i) {
                nodes[i][KEY_OFFSET]^=1;
                if(i==match) nodes[i][KEY_OFFSET]^=1;
                word(nodes[i]+HASH_OFFSET,h+(i==match && bad_hash));
            }
            void *expected=reference(map_a,key,size);
            assert(actual(map_a,key,size)==expected);
            if(size==8) {
                assert(entry(key)==expected);
                assert(entry_same(key)==expected);++same_map_aliases;
                struct query q={0};memcpy(q.key,key,size);assert(entry_select(&q)==expected);
            }
            for(unsigned i=0;i<n;++i) memcpy(nodes[i]+KEY_OFFSET,key,size);
            ++cases;
        }
    }
    /* A separately sized map exercises the same native call with a different
     * immutable shape. It has a real hit, so ARRAY misrouting cannot pass. */
    if(size==16) {
        memcpy(map_b,map_a,sizeof(map_a));pointer(table+index*STRIDE+HEAD,nodes[0]+HASH_NODE);
        memcpy(nodes[0]+KEY_OFFSET,key,size);word(nodes[0]+HASH_OFFSET,h);
        struct query q={.selector=1};memcpy(q.key,key,size);
        assert(entry_b(key)==reference(map_b,key,size));
        assert(entry_select(&q)==reference(map_b,key,size));++cases;
    }
    for(unsigned i=0;i<3;++i) free(nodes[i]);free(table);
}
int main(void)
{
    long page=sysconf(_SC_PAGESIZE);assert(page>0);
    unsigned char *arena=mmap(NULL,page*2,PROT_READ|PROT_WRITE,MAP_PRIVATE|MAP_ANONYMOUS,-1,0);
    assert(arena!=MAP_FAILED && !mprotect(arena+page,page,PROT_NONE));
    unsigned seeds[]={0,1,0xffffffffU,0x12345678U};
    for(unsigned size=0;size<=257;++size) {
        unsigned char *key=arena+page-size;
        for(unsigned i=0;i<size;++i) key[i]=(unsigned char)(i*37+size);
        for(unsigned s=0;s<4;++s) {
            assert(__kprog_hash_bytes(key,size,seeds[s])==hash(key,size,seeds[s]));++hash_cases;
            if(size && size<=256) for(unsigned count=1;count<=64;count*=2) shape(key,size,seeds[s],count);
        }
    }
    assert(entry_unknown(arena)==map_c && generic_calls==589);
    /* Shared memory across processes supplies a genuine changed nulls marker,
     * without a private test hook or a second helper implementation. */
    unsigned char *table=mmap(NULL,page,PROT_READ|PROT_WRITE,MAP_SHARED|MAP_ANONYMOUS,-1,0);
    assert(table!=MAP_FAILED);unsigned char key[8]={0};
    word(map_a+SEED,0);word(map_a+COUNT,8);pointer(map_a+BUCKETS,table);
    unsigned index=hash(key,8,0)&7,wrong=(index+1)&7;
    pointer(table+index*STRIDE+HEAD,(void *)((uintptr_t)wrong*2+1));
    pid_t child=fork();assert(child>=0);
    if(!child) { usleep(20000); *(void * volatile *)(table+index*STRIDE+HEAD)=(void *)((uintptr_t)index*2+1);_exit(0); }
    assert(actual(map_a,key,8)==NULL);
    assert((uintptr_t)read_pointer(table+index*STRIDE+HEAD)==index*2+1);++restarts;
    int status;assert(waitpid(child,&status,0)==child && WIFEXITED(status) && WEXITSTATUS(status)==0);
    assert(!munmap(table,page) && !munmap(arena,page*2));
    printf("%u kernel hash oracle cases, %u C/native lookup cases, %u nulls restart, %u generic calls, %u same-map alias cases\n",hash_cases,cases,restarts,generic_calls,same_map_aliases);
}
