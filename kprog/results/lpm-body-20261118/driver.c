#define _GNU_SOURCE
#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>
#include "layout.h"

typedef void *(*lookup)(void *, const void *);
struct key { uint32_t prefix; unsigned char data[12]; };
static void put32(void *p, size_t off, uint32_t value) { memcpy((char *)p+off,&value,4); }
static void put64(void *p, size_t off, uint64_t value) { memcpy((char *)p+off,&value,8); }
static void pointer(void *p, size_t off, void *value) { memcpy((char *)p+off,&value,sizeof(value)); }
static void die(const char *s) { perror(s); exit(1); }

static lookup load(const char *path) {
    FILE *f=fopen(path,"rb"); if(!f) die(path);
    struct stat st; if(fstat(fileno(f),&st)) die("fstat");
    void *p=mmap(NULL,st.st_size,PROT_READ|PROT_WRITE,MAP_PRIVATE|MAP_ANONYMOUS,-1,0);
    if(p==MAP_FAILED) die("mmap");
    if(fread(p,1,st.st_size,f)!=(size_t)st.st_size) { fprintf(stderr,"short body read\n"); exit(1); }
    if(fclose(f)) die("fclose");
    if(mprotect(p,st.st_size,PROT_READ|PROT_EXEC)) die("mprotect");
    return (lookup)p;
}
static uint64_t now(void) {
    struct timespec t; if(clock_gettime(CLOCK_MONOTONIC_RAW,&t)) die("clock_gettime");
    return (uint64_t)t.tv_sec*1000000000+t.tv_nsec;
}
static void verify(lookup *fn, void *map, struct key *key, void *expected, const char *name) {
    for(unsigned arm=0;arm<2;arm++) {
        void *actual=fn[arm](map,key);
        if(actual!=expected) { fprintf(stderr,"%s arm%u: actual=%p expected=%p\n",name,arm,actual,expected); exit(1); }
    }
    printf("check,%s,pass\n",name);
}
static void measure(lookup *fn, void *map, struct key *keys, size_t count, const char *name) {
    const unsigned calls=1000000;
    for(unsigned sample=0;sample<3;sample++) for(unsigned order=0;order<2;order++) {
        unsigned arm=(sample+order)%2;
        uintptr_t sum=0;
        uint64_t start=now();
        for(unsigned n=0;n<calls;n++) sum+=(uintptr_t)fn[arm](map,&keys[n%count]);
        uint64_t elapsed=now()-start;
        printf("sample,%s,%u,%s,%u,%llu,%llu\n",name,sample,arm?"native":"kernel",calls,
               (unsigned long long)elapsed,(unsigned long long)sum);
    }
}
int main(int argc,char **argv) {
    if(argc!=3) { fprintf(stderr,"usage: driver kernel-host.bin native-host.bin\n"); return 1; }
    lookup fn[]={load(argv[1]),load(argv[2])};
    unsigned char map[512]={0}, single[64]={0};
    put32(map,L_map_type,L_lpm_type); put64(map,L_data_size,12); put32(map,L_max_prefixlen,96);
    struct key key={.prefix=96,.data={0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0xaa,0xbb,0xcc}};
    verify(fn,map,&key,NULL,"empty");
    pointer(map,L_root,single); put32(single,L_node_prefixlen,96);
    memcpy(single+L_node_data,key.data,12);
    verify(fn,map,&key,single+L_node_data+12,"full-hit");
    measure(fn,map,&key,1,"full-hit");
    key.prefix=95; verify(fn,map,&key,NULL,"short-query");
    key.prefix=97; verify(fn,map,&key,NULL,"over-max");
    key.prefix=96; key.data[0]^=0x80; verify(fn,map,&key,NULL,"first-bit-miss");
    measure(fn,map,&key,1,"first-bit-miss");
    key.data[0]^=0x80; key.data[11]^=1; verify(fn,map,&key,NULL,"last-bit-miss");

    /* Stable balanced 14-level trie, 32 shared leading bits, 2 MiB nodes. */
    enum { DEPTH=14, LEAVES=1<<DEPTH, NODES=2*LEAVES-1, QUERIES=4096 };
    unsigned char *nodes=calloc(NODES,64); if(!nodes) die("calloc");
    for(unsigned d=0;d<=DEPTH;d++) for(unsigned k=0;k<(1u<<d);k++) {
        unsigned index=(1u<<d)-1+k;
        unsigned char *node=nodes+index*64;
        put32(node,L_node_prefixlen,32+d); put32(node,L_node_flags,d<DEPTH?1:0);
        uint32_t bits=d?k<<(32-d):0;
        node[L_node_data+4]=bits>>24; node[L_node_data+5]=bits>>16;
        if(d<DEPTH) for(unsigned child=0;child<2;child++)
            pointer(node,L_child+child*L_child_stride,nodes+(2*index+1+child)*64);
    }
    pointer(map,L_root,nodes);
    struct key keys[QUERIES]; uint32_t random=0x12345678;
    for(unsigned n=0;n<QUERIES;n++) {
        random^=random<<13; random^=random>>17; random^=random<<5;
        keys[n]=(struct key){.prefix=96};
        keys[n].data[4]=random>>24; keys[n].data[5]=random>>16;
        unsigned leaf=random>>(32-DEPTH);
        void *expected=nodes+(LEAVES-1+leaf)*64+L_node_data+12;
        for(unsigned arm=0;arm<2;arm++) if(fn[arm](map,&keys[n])!=expected) {
            fprintf(stderr,"deep trie query%u arm%u differs\n",n,arm); return 1;
        }
    }
    printf("check,deep-4096-queries,pass\n");
    measure(fn,map,keys,QUERIES,"deep-trie-hit");
    /* Real-valued ancestor must survive a shorter query below intermediate nodes. */
    put32(nodes,L_node_flags,0); keys[0].prefix=40;
    verify(fn,map,&keys[0],nodes+L_node_data+12,"ancestor-value");
    free(nodes); return 0;
}
