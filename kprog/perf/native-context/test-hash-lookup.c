#define _GNU_SOURCE
#include <assert.h>
#include <pthread.h>
#include <stdatomic.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <linux/jhash.h>

/* Deliberately non-kernel offsets: catch embedded guessed layout values. */
static void u32at(unsigned char *p,unsigned off,uint32_t x){memcpy(p+off,&x,4);}
static void ptrat(unsigned char *p,unsigned off,void *x){memcpy(p+off,&x,8);}
__attribute__((naked)) static uintptr_t generic(void *map __attribute__((unused)),const void *key __attribute__((unused)))
{
    __asm__("mov %rsp,%rax; and $15,%eax; cmp $8,%eax; jne 1f;"
            "mov %rdi,%rax; xor %rsi,%rax; ret; 1: mov $0xbad,%eax; ret");
}
struct restore { _Atomic uintptr_t *head; uintptr_t node; };
static void *restore_head(void *data)
{
    struct restore *r=data;usleep(1000);atomic_store_explicit(r->head,r->node,memory_order_release);return NULL;
}
int main(int argc,char **argv)
{
    assert(argc==3);FILE *f=fopen(argv[1],"rb");assert(f);fseek(f,0,SEEK_END);long n=ftell(f);assert(n>0);rewind(f);
    unsigned char *code=mmap(NULL,n,PROT_READ|PROT_WRITE,MAP_ANONYMOUS|MAP_PRIVATE|MAP_32BIT,-1,0);
    assert(code!=MAP_FAILED && fread(code,1,n,f)==(size_t)n);assert(!fclose(f));
    unsigned call=(unsigned)strtoul(argv[2],NULL,10);assert(code[call]==0xe8);
    int64_t distance=(intptr_t)generic-(intptr_t)(code+call+5);assert(distance==(int32_t)distance);
    int32_t disp=distance;memcpy(code+call+1,&disp,4);assert(!mprotect(code,n,PROT_READ|PROT_EXEC));
    uintptr_t (*lookup)(void *,const void *)=(void *)code;
    unsigned char map[128]={0},buckets[512]={0},hit[96]={0},collision[96]={0};
    ptrat(map,40,buckets);u32at(map,32,16);
    unsigned char *pages=mmap(NULL,8192,PROT_READ|PROT_WRITE,MAP_ANONYMOUS|MAP_PRIVATE,-1,0);
    assert(pages!=MAP_FAILED && !mprotect(pages+4096,4096,PROT_NONE));
    uint32_t random=0x91abcdef;unsigned vectors=0;
    for(unsigned size=4;size<=16;size+=4) for(unsigned sample=0;sample<512;++sample) {
        unsigned char *key=sample<256 ? pages+2048+sample%4 : pages+4096-size;
        for(unsigned i=0;i<size;++i){random=random*1664525+1013904223;key[i]=random>>24;}
        uint32_t seed=random,hash=jhash2((const u32 *)key,size/4,seed),index=hash&15;
        u32at(map,12,size);u32at(map,20,seed);
        for(unsigned i=0;i<16;++i)ptrat(buckets+i*32,8,(void *)(uintptr_t)(i*2+1));
        u32at(hit,32,hash);memcpy(hit+40,key,size);ptrat(hit,8,(void *)(uintptr_t)(index*2+1));
        u32at(collision,32,hash);memcpy(collision+40,key,size);collision[40+sample%size]^=1;
        ptrat(collision,8,hit+8);ptrat(buckets+index*32,8,collision+8);
        assert(lookup(map,key)==(uintptr_t)hit);++vectors; /* same-hash collision skip */
        ptrat(buckets+index*32,8,(void *)(uintptr_t)(index*2+1));assert(!lookup(map,key));++vectors;
        ptrat(buckets+index*32,8,hit+8);u32at(hit,32,hash^0x80000000);
        assert(!lookup(map,key));++vectors; /* full hash equality, not bucket equality */
    }
    /* Arbitrary unsupported sizes preserve original helper+args+stack alignment. */
    for(unsigned size=0;size<32;++size) if(size!=4 && size!=8 && size!=12 && size!=16) {
        u32at(map,12,size);assert(lookup(map,(void *)1)==((uintptr_t)map^1));++vectors;
    }
    unsigned char *key=pages+4096-16;u32at(map,12,16);u32at(map,20,123);
    uint32_t hash=jhash2((const u32 *)key,4,123),index=hash&15;
    u32at(hit,32,hash);memcpy(hit+40,key,16);ptrat(hit,8,(void *)(uintptr_t)(index*2+1));
    _Atomic uintptr_t *head=(void *)(buckets+index*32+8);
    atomic_store(head,((uintptr_t)(index^1)<<1)|1); /* wrong marker must retry */
    struct restore restore={head,(uintptr_t)(hit+8)};pthread_t thread;
    assert(!pthread_create(&thread,NULL,restore_head,&restore));
    assert(lookup(map,key)==(uintptr_t)hit);assert(!pthread_join(thread,NULL));++vectors;
    printf("hash host: %u kernel-jhash2/table/guard/collision/null/retry/ABI vectors PASS\n",vectors);
    return 0;
}
