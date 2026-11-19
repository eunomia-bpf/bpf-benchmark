#include <stdint.h>
#include <stdio.h>
#include <string.h>
static int result,domain,calls;
static unsigned long seen_size;
static void *seen_dst;
static const void *seen_src;
static long copy(void *dst,const void *src,unsigned long size,int kind) {
    ++calls; domain=kind; seen_dst=dst; seen_src=src; seen_size=size;
    if(size<=256) memcpy(dst,src,result<0?size/2:size);
    return result;
}
long copy_from_user_nofault(void *dst,const void *src,unsigned long size) { return copy(dst,src,size,1); }
long copy_from_kernel_nofault(void *dst,const void *src,unsigned long size) { return copy(dst,src,size,2); }
long bpf_probe_read(void *dst,unsigned size,const void *src) { (void)dst;(void)size;(void)src; return -123; }
extern long user8(void *,const void *), kernel8(void *,const void *);
extern long user_dynamic(void *,unsigned long,const void *),kernel_dynamic(void *,unsigned long,const void *);
extern long compat(void *,unsigned,const void *);
int main(void) {
    unsigned char dst[288],src[256]; unsigned tests=0;
    for(unsigned i=0;i<256;++i)src[i]=(unsigned char)(i+17);
    unsigned sizes[]={0,1,2,4,7,8,9,15,16,31,32,63,64,127,256};
    int results[]={0,-14,-34};
    for(int kind=1;kind<=2;++kind) for(unsigned r=0;r<3;++r) for(unsigned k=0;k<15;++k) {
        unsigned size=sizes[k]; result=results[r]; calls=0;
        memset(dst,0xa5,sizeof(dst));
        long ret=(kind==1?user_dynamic:kernel_dynamic)(dst+16,size,src);
        if(ret!=result || domain!=kind || calls!=1 || seen_dst!=dst+16 || seen_src!=src || seen_size!=size)return 1;
        for(unsigned i=0;i<sizeof(dst);++i) {
            unsigned char want=i>=16 && i<16+size ? (result<0?0:src[i-16]):0xa5;
            if(dst[i]!=want)return 2;
        }
        ++tests;
    }
    for(int kind=1;kind<=2;++kind)for(unsigned r=0;r<3;++r) {
        result=results[r];calls=0;memset(dst,0xa5,sizeof(dst));
        long ret=(kind==1?user8:kernel8)(dst+16,src);
        if(ret!=result || calls!=1 || domain!=kind || seen_size!=8)return 3;
        for(unsigned i=0;i<sizeof(dst);++i) {
            unsigned char want=i>=16 && i<24 ? (result<0?0:src[i-16]):0xa5;
            if(dst[i]!=want)return 4;
        }
        ++tests;
    }
    result=0;calls=0;
    if(user_dynamic(dst,0x100000008UL,src)!=0 || seen_size!=8 || calls!=1)return 5;
    if(kernel_dynamic(dst,0x1ffffffffUL,src)!=0 || seen_size!=0xffffffffUL || calls!=2)return 6;
    if(compat(dst,0,src)!=-123 || calls!=2)return 7;
    printf("%u probe copy/error/guard cases, two u32 lengths and compat retention passed\n",tests);
}
