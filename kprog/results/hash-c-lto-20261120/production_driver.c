/* Catch wrong map selection/private-key preservation/value offsets in the real
 * compiler API. Stored hashes come from the kernel header, not helper C. */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "kernel_hash_reference.h"
_Alignas(64) unsigned char map_a[4096];
unsigned long long kprog_unspecified_input[1];
extern unsigned trusted_x86_x86_sim_xdp(void *);
long copy_from_kernel_nofault(void *dst,const void *src,unsigned long n) { memcpy(dst,src,n);return 0; }
long copy_from_user_nofault(void *dst,const void *src,unsigned long n) { memcpy(dst,src,n);return 0; }
void *bpf_map_lookup_elem(void *map,const void *key) { (void)map;(void)key;abort(); }
static void word(void *p,unsigned v) { memcpy(p,&v,4); }
static void pointer(void *p,void *v) { memcpy(p,&v,sizeof(v)); }
int main(void)
{
    unsigned cases=0,seeds[]={0,1,0xffffffffU,0x12345678U};
    unsigned long key=0x5a5a5a5a5a5a5a5aUL;
    for(unsigned s=0;s<4;++s) for(unsigned count=1;count<=64;count*=2) {
        unsigned char *table=calloc(count,STRIDE),*node=calloc(1,KEY_OFFSET+16);assert(table && node);
        for(unsigned i=0;i<count;++i) pointer(table+i*STRIDE+HEAD,(void *)((uintptr_t)i*2+1));
        unsigned h=jhash2((u32 *)&key,2,seeds[s]),index=h&(count-1);
        pointer(map_a+BUCKETS,table);word(map_a+COUNT,count);word(map_a+SEED,seeds[s]);
        pointer(node+HASH_NODE+NEXT,(void *)((uintptr_t)index*2+1));
        memcpy(node+KEY_OFFSET,&key,8);word(node+KEY_OFFSET+8,0x719205ab);
        for(unsigned mode=0;mode<4;++mode) {
            word(node+HASH_OFFSET,h+(mode==1));
            node[KEY_OFFSET]=0x5a^(mode==2);
            pointer(table+index*STRIDE+HEAD,mode==3 ? (void *)((uintptr_t)index*2+1) : node+HASH_NODE);
            assert(trusted_x86_x86_sim_xdp(NULL)==(mode ? 0 : 0x719205ab));++cases;
        }
        free(node);free(table);
    }
    printf("%u actual compiler-API hash cases\n",cases);
}
