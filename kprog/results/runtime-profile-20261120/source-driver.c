/* Exercise the public source macros, not a direct call to the late wrapper.
 * Providers test ABI/routing/return values; kernel policy is not simulated. */
#include "../checked-probe-c-20261119/driver.c"
#include <assert.h>
extern long kernel_str8(void *, const void *);
extern long kernel_str_dynamic(void *, unsigned long, const void *);
static long string_result;
long bpf_probe_read_kernel_str(void *dst, unsigned size, const void *src)
{
    ++calls; domain=3; seen_dst=dst; seen_src=src; seen_size=size;
    if (size) *(unsigned char *)dst=0x5a;
    return string_result;
}
__attribute__((constructor)) static void string_source_cases(void)
{
    unsigned char dst[16], src[8]={0};
    const long returns[]={0,1,8,-14,-34};
    unsigned cases=0;
    for (unsigned r=0;r<5;++r) for (unsigned size=0;size<=9;++size) {
        string_result=returns[r]; calls=0; memset(dst,0xa5,sizeof(dst));
        assert(kernel_str_dynamic(dst+4,size,src)==string_result);
        assert(calls==1 && domain==3 && seen_dst==dst+4 && seen_src==src && seen_size==size);
        for (unsigned i=0;i<sizeof(dst);++i)
            assert(dst[i]==(i==4 && size ? 0x5a : 0xa5));
        ++cases;
    }
    calls=0; string_result=-14;
    assert(kernel_str8(dst,src)==-14 && calls==1 && seen_size==8);
    printf("%u string source ABI/return controls passed\n",cases+1);
}
