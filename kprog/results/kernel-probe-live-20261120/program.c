/* Native program input, executed by the existing trusted-service client.
 * Return 2 only when helper return, error zeroing and buffer guards agree
 * with the sole kernel's bpf_trace.c/maccess.c contracts. */
#include "../../../vendor/bpf/native-helpers.h"

int trusted_entry(void *context)
{
    (void)context;
    unsigned long source=0x0807060504030201UL;
    char text[8]="kprog";
    struct { unsigned char before,bytes[8],after; } area={
        0x5a,{0x7e,0x7e,0x7e,0x7e,0x7e,0x7e,0x7e,0x7e},0xa5};
    long result,expected;
    unsigned long value=0,bytes=0,mask=~0UL;
#if PROBE_CASE == 0
    result=bpf_probe_read_kernel(area.bytes,8,&source);
    expected=0;value=source;
#elif PROBE_CASE == 1
    result=bpf_probe_read_kernel(area.bytes,8,(const void *)0);
    expected=-34;
#elif PROBE_CASE == 2
    result=bpf_probe_read_kernel(area.bytes,8,(const void *)4096UL);
    expected=-34;
#elif PROBE_CASE == 3
    result=bpf_probe_read_kernel(area.bytes,8,(const void *)~0UL);
    expected=-14;
#elif PROBE_CASE == 4
    result=bpf_probe_read_kernel(area.bytes,0,(const void *)0);
    expected=-34;value=0x7e7e7e7e7e7e7e7eUL;
#elif PROBE_CASE == 5
    result=bpf_probe_read_kernel_str(area.bytes,8,text);
    expected=6;value=0x00676f72706bUL;mask=0xffffffffffffUL;
#elif PROBE_CASE == 6
    result=bpf_probe_read_kernel_str(area.bytes,8,(const void *)0);
    expected=-34;
#elif PROBE_CASE == 7
    result=bpf_probe_read_kernel_str(area.bytes,8,(const void *)~0UL);
    expected=-14;
#elif PROBE_CASE == 8
    result=bpf_probe_read_kernel(area.bytes,0,&source);
    expected=0;value=0x7e7e7e7e7e7e7e7eUL;
#elif PROBE_CASE == 9
    result=bpf_probe_read(area.bytes,8,(const void *)~0UL);
    expected=-14;
#elif PROBE_CASE == 10
    result=bpf_probe_read_user(area.bytes,8,(const void *)0);
    expected=-14;
#elif PROBE_CASE == 11
    result=bpf_probe_read_user(area.bytes,0,(const void *)0);
    expected=0;value=0x7e7e7e7e7e7e7e7eUL;
#else
#error unknown native program case
#endif
    __builtin_memcpy(&bytes,area.bytes,8);
    return result==expected && (bytes&mask)==value &&
        area.before==0x5a && area.after==0xa5 ? 2 : 3;
}
