/* Real retained entry: branch exits and register-indirect helper prefixes. */
#include <linux/bpf.h>
#include <bpf_helpers.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <setjmp.h>
#define KPROG_X86_HELPER(ID, NAME, RESULT, ARGS) extern RESULT kprog_x86_callee_##NAME ARGS;
#include "../c/X86HelperCalls.h"
#undef KPROG_X86_HELPER
extern int trusted_x86_x86_sim_xdp(void *);
__u8 cgroup_rate_map[1],cgroup_rate_options_map[1],execve_map[1],execve_map_stats[1],
    execve_val[1],tcpmon_map[1],tg_cgtracker_map[1],tg_conf_map[1],tg_rb_events[1],
    tg_stats_map[1],throttle_heap_map[1];
static __u64 task[354],parent[354],context[16],saved_task[354],saved_parent[354],saved_context[16];
static __u64 entropy,origin;
static unsigned scenario,inputs,sp_calls,helpers;
static void *first_destination;
static jmp_buf refusal;
static void require(int ok)
{
    if (!ok) {fprintf(stderr,"Tetragon entry mismatch: scenario %u, inputs %u, helpers %u\n",scenario,inputs,helpers);exit(1);}
}
unsigned long native_lab_entry_input(unsigned kind)
{
    require(kind==1 || kind==6);++inputs;
    if (kind==1) {++sp_calls;return origin;}
    entropy^=entropy<<13;entropy^=entropy>>7;entropy^=entropy<<17;return entropy;
}
long kprog_x86_callee_bpf_probe_read_kernel(void *dst,__u32 size,const void *src)
{
    ++helpers;require(helpers<=3 && scenario!=0);
    require(inputs==24+17*(helpers-1));
    const void *expected=helpers==1 ? (char *)task+2804 :
                         helpers==2 ? (char *)task+2816 : (char *)parent+2804;
    require(src==expected && size==(helpers==2?8U:4U));
    if (helpers==1) first_destination=dst;
    else require((uintptr_t)dst==(uintptr_t)first_destination-(helpers==3?112U:0U));
    if (scenario>=2 && helpers==scenario-1) longjmp(refusal,1);
    memcpy(dst,src,size);return 0;
}
static __attribute__((noreturn)) void unexpected(void)
{ fputs("unexpected Tetragon platform call\n",stderr);exit(1); }
void *kprog_x86_callee_bpf_map_lookup_elem(void *a,const void *b) { (void)a;(void)b;unexpected(); }
long kprog_x86_callee_bpf_map_update_elem(void *a,const void *b,const void *c,__u64 d)
{ (void)a;(void)b;(void)c;(void)d;unexpected(); }
long kprog_x86_callee_bpf_probe_read(void *a,__u32 b,const void *c) { (void)a;(void)b;(void)c;unexpected(); }
long kprog_x86_callee_bpf_probe_read_str(void *a,__u32 b,const void *c) { (void)a;(void)b;(void)c;unexpected(); }
long kprog_x86_callee_bpf_perf_event_output(void *a,void *b,__u64 c,void *d,__u64 e)
{ (void)a;(void)b;(void)c;(void)d;(void)e;unexpected(); }
__u64 kprog_x86_callee_bpf_get_current_cgroup_id(void) { unexpected(); }
__u64 kprog_x86_callee_bpf_ktime_get_boot_ns(void) { unexpected(); }
long kprog_x86_callee_bpf_ringbuf_output(void *a,void *b,__u64 c,__u64 d)
{ (void)a;(void)b;(void)c;(void)d;unexpected(); }
void kprog_x86_observe_unresolved(void) { unexpected(); }
unsigned long long kprog_x86_observe_time(void) { unexpected(); }
void kprog_c_trap(void) { unexpected(); }
void *kprog_c_context_pointer(const void *p,__u8 k,__u32 o) { (void)p;(void)k;(void)o;unexpected(); }
__u64 kprog_c_pointer_bits(const void *p) { (void)p;unexpected(); }
__u64 kprog_c_atomic_fetch(void *p,__u64 v,__u32 w,__u32 o,__u32 r)
{ (void)p;(void)v;(void)w;(void)o;(void)r;unexpected(); }
void __builtin_memcpy_aligned(void *d,const void *s,size_t n,size_t a)
{ require(a==1);memcpy(d,s,n); }
int main(void)
{
    for (volatile unsigned seed=1;seed<=8;++seed) for (scenario=0;scenario<5;++scenario) {
        memset(task,0x5a,sizeof(task));memset(parent,0xa5,sizeof(parent));memset(context,0,sizeof(context));
        context[14]=scenario?(uintptr_t)task:0;
        task[352]=scenario==4?(uintptr_t)parent:0;
        memcpy(saved_task,task,sizeof(task));memcpy(saved_parent,parent,sizeof(parent));memcpy(saved_context,context,sizeof(context));
        entropy=seed;origin=0xfedcba9800011000ULL+((__u64)seed<<12);inputs=sp_calls=helpers=0;first_destination=NULL;
        volatile int value=-1;
        if (!setjmp(refusal)) {value=trusted_x86_x86_sim_xdp(context);require(scenario<2 && value==0);}
        else require(scenario>=2);
        const unsigned expected_inputs[]={65,99,24,41,58},expected_helpers[]={0,2,1,2,3};
        require(inputs==expected_inputs[scenario] && helpers==expected_helpers[scenario] && sp_calls==1);
        require(!memcmp(task,saved_task,sizeof(task)) && !memcmp(parent,saved_parent,sizeof(parent)) && !memcmp(context,saved_context,sizeof(context)));
    }
    puts("Tetragon retained entry: 16 complete returns and 24 helper-refusal prefixes; exact inputs/arguments/input-memory frames");
    return 0;
}
