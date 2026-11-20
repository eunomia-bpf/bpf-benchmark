/* Catch private-key preservation, LPM selection, returned-value offset and
 * partial-prefix/intermediate-node errors in the actual compiled simulator. */
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
_Alignas(64) unsigned char map_a[4096],map_b[4096];
unsigned long long kprog_unspecified_input[1];
extern unsigned trusted_x86_x86_sim_xdp(void *);
long copy_from_kernel_nofault(void *dst,const void *src,unsigned long size)
{
    memcpy(dst,src,size); return 0;
}
long copy_from_user_nofault(void *dst,const void *src,unsigned long size)
{
    memcpy(dst,src,size); return 0;
}
void *bpf_map_lookup_elem(void *map,const void *key)
{
    (void)map; (void)key; fputs("unexpected generic LPM call\n",stderr); abort();
}
static void word(void *p,unsigned value) { memcpy(p,&value,4); }
int main(void)
{
    _Alignas(8) unsigned char node[48]={0};
    const unsigned payload[3]={0x5a5a5a5a,0x5a5a5a5a,0x5a5a5a5a};
    unsigned char key[12]; memcpy(key,payload,sizeof(key));
    assert(trusted_x86_x86_sim_xdp(NULL)==0);
    void *root=node; memcpy(map_a+ROOT_OFF,&root,sizeof(root));
    memcpy(node+DATA_OFF,key,sizeof(key)); word(node+DATA_OFF+12,0x719205ab);
    unsigned long cases=1;
    for(unsigned prefix=0;prefix<=96;++prefix) {
        word(node+PREFIX_OFF,prefix);
        for(unsigned flag=0;flag<2;++flag) {
            word(node+FLAGS_OFF,flag);
            for(unsigned bit=0;bit<=96;++bit) {
                if(bit<96) node[DATA_OFF+bit/8]^=128u>>(bit%8);
                unsigned expected=(flag && prefix<96) || bit<prefix ? 0 : 0x719205ab;
                assert(trusted_x86_x86_sim_xdp(NULL)==expected);
                if(bit<96) node[DATA_OFF+bit/8]^=128u>>(bit%8);
                ++cases;
            }
        }
    }
    printf("%lu actual simulator LPM cases\n",cases);
}
