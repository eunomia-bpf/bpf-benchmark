#define _GNU_SOURCE
#include <assert.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
struct node {uint64_t pad;struct node *child[2];uint64_t pad2;uint32_t prefix,flags;uint64_t pad3;unsigned char data[12];uint32_t value;};
struct key {uint32_t prefix;unsigned char data[12];};
_Static_assert(offsetof(struct node,child)==8 && offsetof(struct node,prefix)==32 && offsetof(struct node,flags)==36 && offsetof(struct node,data)==48,"non-kernel fixture layout");
static void u64at(unsigned char *p,unsigned offset,uint64_t x){memcpy(p+offset,&x,8);}
static void u32at(unsigned char *p,unsigned offset,uint32_t x){memcpy(p+offset,&x,4);}
__attribute__((naked)) static uintptr_t generic(void *map __attribute__((unused)),const void *key __attribute__((unused))) {
    __asm__("mov %rsp,%rax; and $15,%eax; cmp $8,%eax; jne 1f;mov %rdi,%rax;xor %rsi,%rax;ret;1:mov $0xbad,%eax;ret");
}
static unsigned bit(const unsigned char *data,unsigned index){return (data[index/8]>>(7-index%8))&1;}
/* Independent bit-at-a-time semantics, avoiding the emitter's BSR/chunk math. */
static uintptr_t reference(struct node *node,const struct key *key) {
    if(key->prefix>96)return 0;
    struct node *found=NULL;
    while(node) {
        unsigned limit=node->prefix<key->prefix?node->prefix:key->prefix,match=0;
        while(match<limit && bit(node->data,match)==bit(key->data,match))++match;
        if(match==96){found=node;break;}
        if(match<node->prefix)break;
        if(!(node->flags&1))found=node;
        node=node->child[bit(key->data,node->prefix)];
    }
    return found?(uintptr_t)&found->value:0;
}
static uint32_t random_state=0x9145abcd;
static uint32_t next(void){random_state=random_state*1664525+1013904223;return random_state;}
static struct node pool[4096];static unsigned used;
static struct node *make_node(const struct key *key,unsigned prefix){
    assert(used<4096);struct node *n=&pool[used++];memset(n,0,sizeof(*n));n->prefix=prefix;n->flags=1;memcpy(n->data,key->data,12);n->value=used+100;return n;
}
static struct node *compress(struct node *node) {
    if(!node)return NULL;
    node->child[0]=compress(node->child[0]);node->child[1]=compress(node->child[1]);
    if((node->flags&1) && !node->child[0] && node->child[1])return node->child[1];
    if((node->flags&1) && node->child[0] && !node->child[1])return node->child[0];
    return node;
}
int main(int argc,char **argv) {
    assert(argc==3);FILE *f=fopen(argv[1],"rb");assert(f);fseek(f,0,SEEK_END);long size=ftell(f);assert(size>0);rewind(f);
    unsigned char *code=mmap(NULL,size,PROT_READ|PROT_WRITE,MAP_PRIVATE|MAP_ANONYMOUS|MAP_32BIT,-1,0);assert(code!=MAP_FAILED);
    assert(fread(code,1,size,f)==(size_t)size && !fclose(f));unsigned call=strtoul(argv[2],NULL,10);assert(code[call]==0xe8);
    int64_t delta=(intptr_t)generic-(intptr_t)(code+call+5);assert(delta==(int32_t)delta);int32_t disp=delta;memcpy(code+call+1,&disp,4);
    assert(!mprotect(code,size,PROT_READ|PROT_EXEC));uintptr_t (*lookup)(void *,const void *)=(void *)code;
    unsigned char map[128]={0};u32at(map,12,11);u64at(map,56,96);u64at(map,64,12);
    unsigned char *pages=mmap(NULL,8192,PROT_READ|PROT_WRITE,MAP_PRIVATE|MAP_ANONYMOUS,-1,0);assert(pages!=MAP_FAILED && !mprotect(pages+4096,4096,PROT_NONE));
    unsigned vectors=0;struct key keys[32];
    for(unsigned tree=0;tree<64;++tree) {
        used=0;struct key zero={0};struct node *root=make_node(&zero,0);root->flags=tree%2;
        for(unsigned k=0;k<32;++k) {
            for(unsigned i=0;i<12;++i)keys[k].data[i]=next()>>24;
            keys[k].prefix=k%8==0?96:next()%97;
            struct node *node=root;
            for(unsigned p=1;p<=keys[k].prefix;++p) {
                unsigned side=bit(keys[k].data,p-1);
                if(!node->child[side])node->child[side]=make_node(&keys[k],p);
                node=node->child[side];
            }
            node->flags=0;
        }
        root=compress(root);u64at(map,40,(uintptr_t)root);
        for(unsigned sample=0;sample<1024;++sample) {
            struct key local=keys[sample%32];local.prefix=sample%113;
            if(sample>=512)for(unsigned i=0;i<12;++i)local.data[i]=next()>>24;
            /* Alternate guard-end and deliberately unaligned key addresses. */
            unsigned char *bytes=sample%2?pages+4096-sizeof(local):pages+2049;
            memcpy(bytes,&local,sizeof(local));
            assert(lookup(map,bytes)==reference(root,&local));++vectors;
        }
    }
    struct key key={.prefix=96};u64at(map,40,0);assert(!lookup(map,&key));++vectors;
    /* Invalid prefix must return before touching an inaccessible root. */
    key.prefix=97;u64at(map,40,(uintptr_t)(pages+4096));assert(!lookup(map,&key));++vectors;
    /* Kernel exact max-prefix return happens before intermediate flag test. */
    key.prefix=96;used=0;struct node *node=make_node(&key,96);u64at(map,40,(uintptr_t)node);
    assert(lookup(map,&key)==(uintptr_t)&node->value);++vectors;
    for(unsigned type=0;type<32;++type)if(type!=11) {
        u32at(map,12,type);assert(lookup(map,(void *)1)==((uintptr_t)map^1));++vectors;
    }
    u32at(map,12,11);
    for(unsigned data=0;data<=20;++data)if(data!=12) {
        u64at(map,64,data);assert(lookup(map,(void *)1)==((uintptr_t)map^1));++vectors;
    }
    printf("LPM host: %u compressed-trie/prefix/IM/guard/live-root/generic-ABI vectors PASS\n",vectors);
    return 0;
}
