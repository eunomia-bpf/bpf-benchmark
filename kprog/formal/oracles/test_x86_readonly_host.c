/* Actual linked readonly program plus all finite value windows and generic
 * memory selection. Independent byte packing catches width/offset errors. */
#include <linux/types.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>
#include "compcert_memory_host.h"
#define KPROG_X86_PROGRAM_EXPORT 1
#include "../build/x86_readonly_profile.bpf.c"
extern int x86_readonly_profile(void);
static const __u8 expected_data[16]={0x12,0x83,0xfe,0x45,0x67,0x89,0xab,0xcd,0xef,0x20,0x31,0x42,0x53,0x64,0x75,0x96};
static unsigned cases,inputs,sp_calls,copies,sequence;
static __u64 entropy,origin;
static void require(int ok)
{ if (!ok) {fprintf(stderr,"readonly mismatch at case %u, inputs %u, copies %u\n",cases,inputs,copies);exit(1);} }
unsigned long native_lab_entry_input(unsigned kind)
{
    require(kind==1 || kind==6);++inputs;
    if (kind==1) {++sp_calls;return origin;}
    entropy^=entropy<<13;entropy^=entropy>>7;entropy^=entropy<<17;
    /* Scalar-address recovery chooses zero for the four real reads. */
    return entropy & ~1ULL;
}
void kprog_c_trap(void) { _exit(77); }
void *kprog_c_context_pointer(const void *p,__u8 k,__u32 o)
{ (void)p;(void)k;(void)o;abort(); }
__u64 kprog_c_pointer_bits(const void *p) { (void)p;abort(); }
void __builtin_memcpy_aligned(void *d,const void *s,size_t n,size_t a)
{ require(a==1 && (n==1 || n==2 || n==4 || n==8));++copies;memcpy(d,s,n); }
static __u64 little(const __u8 *p,unsigned n)
{ __u64 value=0;for (unsigned i=0;i<n;++i) value|=(__u64)p[i]<<(i*8);return value; }
static __u64 selected(const void *base,__u64 offset,__u8 width)
{
#if defined(__COMPCERT__)
    return x86_sim_inline_native_data_load(base,offset,width);
#else
    return X86_SIM_L_NATIVE_DATA_LOAD(base,offset,width);
#endif
}
static const void *marked_base(void) { require(sequence++==0);return __x86_rodata_0; }
static __u64 marked_offset(void) { require(sequence++==1);return 3; }
static __u8 marked_width(void) { require(sequence++==2);return 4; }
static void refused_width(__u8 width,unsigned direct)
{
    pid_t child=fork();require(child>=0);
    if (!child) {
        volatile __u64 value=direct?__x86_rodata_0_value(0,width):selected(__x86_rodata_0,0,width);
        (void)value;_exit(1);
    }
    int status;require(waitpid(child,&status,0)==child);
#if defined(__COMPCERT__)
    require(WIFEXITED(status) && WEXITSTATUS(status)==77);
#else
    require(WIFSIGNALED(status) && WTERMSIG(status)==SIGILL);
#endif
}
int main(void)
{
    __u8 other[32],saved[32];for (unsigned i=0;i<32;++i) other[i]=29*i+7;
    memcpy(saved,other,sizeof(other));require(!memcmp(__x86_rodata_0,expected_data,16));
    const unsigned widths[]={0,1,2,4,8,256,257,258,260,264};
    for (unsigned wi=0;wi<10;++wi) {
        __u8 width=widths[wi];unsigned n=width?width:8;
        for (unsigned off=0;off+n<=16;++off) {
            __u64 expected=little(expected_data+off,n);copies=0;
            require(__x86_rodata_0_value(off,width)==expected);
            require(selected(__x86_rodata_0,off,width)==expected);
            require(selected(__x86_rodata_0+off,0,width)==expected);
            require(selected(other,off,width)==little(other+off,n));
            require(inputs==0 && !memcmp(other,saved,sizeof(other)) && !memcmp(__x86_rodata_0,expected_data,16));
            ++cases;
        }
    }
    sequence=0;__u64 captured=0;
    X86_SIM_L_NATIVE_DATA_LOAD_INTO(captured,marked_base(),marked_offset(),marked_width());
    require(sequence==3 && captured==little(expected_data+3,4));
    sequence=0;captured=X86_SIM_L_NATIVE_DATA_LOAD(marked_base(),marked_offset(),marked_width());
    require(sequence==3 && captured==little(expected_data+3,4));
    for (unsigned d=0;d<2;++d) {refused_width(3,d);refused_width(255,d);}
    __u64 mixed=little(expected_data,8)^little(expected_data+7,2)^expected_data[15]^little(expected_data+3,4);
    __u32 expected=(__u32)(mixed^(mixed>>32));require((__u32)x86_readonly_profile()==expected);
    for (unsigned seed=1;seed<=16;++seed) {
        inputs=sp_calls=copies=0;entropy=seed;origin=0xffff000012340000ULL+((__u64)seed<<12);
        require((__u32)x86_readonly_profile_x86_sim_xdp(NULL)==expected && inputs==29 && sp_calls==1);
        require(!memcmp(__x86_rodata_0,expected_data,16));
    }
    printf("readonly: %u window/width/identity frames, ordered captures, four width refusals and 16 complete native-matched producer returns\n",cases);
    return 0;
}
