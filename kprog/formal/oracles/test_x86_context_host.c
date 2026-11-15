/* Context identity/field/full-pointer, byte windows, lazy fallbacks and frame
 * checks. Platform operations below are fixture interpretations, not proofs
 * of the concrete kernel/Clight context-view and memory correspondence. */
#define _GNU_SOURCE
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <unistd.h>
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../c/X86Context.h"

static unsigned long cases;
static unsigned fields, bits, copies;
static const void *key, *expected_source;
static __u8 kind;
static __u32 expected_field;
static __u64 pointer_values[3], expected_bits;
static size_t expected_size;
static void check(int ok, const char *what)
{
    if (!ok) { fprintf(stderr,"x86 context case %lu: %s\n",cases,what); exit(1); }
}
unsigned long native_lab_entry_input(unsigned input)
{
    (void)input; fputs("unexpected free input in context read\n",stderr); abort();
}
void kprog_c_trap(void) { fputs("unexpected context trap\n",stderr); abort(); }
void *kprog_c_context_pointer(const void *context, __u8 actual_kind, __u32 offset)
{
    check(context==key && actual_kind==kind && offset==expected_field,"context identity/kind/UAPI field");
    fields++;
    if (kind==KPROG_ABI_KIND_SKB) {
        if (offset==offsetof(struct __sk_buff,data)) return (void *)(uintptr_t)pointer_values[0];
        if (offset==offsetof(struct __sk_buff,data_end)) return (void *)(uintptr_t)pointer_values[1];
    } else if (kind==KPROG_ABI_KIND_XDP) {
        if (offset==offsetof(struct xdp_md,data)) return (void *)(uintptr_t)pointer_values[0];
        if (offset==offsetof(struct xdp_md,data_end)) return (void *)(uintptr_t)pointer_values[1];
        if (offset==offsetof(struct xdp_md,data_meta)) return (void *)(uintptr_t)pointer_values[2];
    }
    check(0,"unsupported context field"); abort();
}
__u64 kprog_c_pointer_bits(const void *pointer)
{
    check(fields==1 && (uintptr_t)pointer==expected_bits,"field-before-exposure/full pointer bits");
    bits++; return (uintptr_t)pointer;
}
void __builtin_memcpy_aligned(void *dst, const void *src, size_t size, size_t alignment)
{
    check(src==expected_source && size==expected_size && alignment==1,"fallback physical address/width/alignment");
    copies++; memcpy(dst,src,size);
}
static __u64 little(const __u8 *p, unsigned size)
{
    __u64 v=0; for (unsigned i=0;i<size;i++) v|=(__u64)p[i]<<(8*i); return v;
}
static __u64 pointer(unsigned index)
{
#if defined(__COMPCERT__)
    return pointer_values[index];
#else
    /* The host fixture has no verifier's pointer-width context conversion. */
    return (__u32)pointer_values[index];
#endif
}
static __u64 native(unsigned xdp, struct x86_sim_register_state *state,
                     __u64 base, const void *address, __s64 off, __u64 width)
{
    struct x86_sim_register_state *__x86_state=state;
    if (xdp) return X86_SIM_L_XDP_READ(address,off,width);
    return X86_SIM_L_SKB_READ(base,off,width);
}
static void reset(void) { fields=bits=copies=0; }
static const void *fault_address;
static void fault(int signo, siginfo_t *info, void *context)
{
    (void)context;
    _exit(signo==SIGSEGV && info->si_addr==fault_address ? 0 : 1);
}
static void guarded_bytes(void)
{
    long ps=sysconf(_SC_PAGESIZE); check(ps>0,"page size");
    __u8 *p=mmap(NULL,2*(size_t)ps,PROT_READ|PROT_WRITE,MAP_PRIVATE|MAP_ANONYMOUS,-1,0);
    check(p!=MAP_FAILED,"guard mapping"); memset(p,0x5c,2*(size_t)ps);
    check(!mprotect(p+ps,(size_t)ps,PROT_NONE),"guard next page");
    for (unsigned w=1;w<=8;w*=2) {
        __u64 expected=w==8 ? 0x5c5c5c5c5c5c5c5cULL : 0x5c5c5c5c5c5c5c5cULL&((1ULL<<(w*8))-1);
        check(kprog_x86_cb_read(p+ps-w,0,w)==expected,"no extra byte reads past selected width");
    }
    check(!mprotect(p,(size_t)ps,PROT_NONE),"guard first page");
    fault_address=p+ps-1;
    for (unsigned mode=0;mode<2;mode++) {
        pid_t child=fork(); check(child>=0,"fork byte ordering");
        if (!child) {
            struct sigaction action={.sa_sigaction=fault,.sa_flags=SA_SIGINFO};
            if (sigemptyset(&action.sa_mask) || sigaction(SIGSEGV,&action,NULL)) _exit(2);
            volatile __u64 value=mode ? X86_SIM_L_SKB_CB_READ_BYTES(fault_address,0,8) : kprog_x86_cb_read(fault_address,0,8);
            (void)value; _exit(3);
        }
        int status; check(waitpid(child,&status,0)==child,"wait byte ordering");
        check(WIFEXITED(status) && WEXITSTATUS(status)==0,"byte zero is first fault");
    }
    check(!munmap(p,2*(size_t)ps),"release guard mapping");
}
int main(void)
{
    _Alignas(8) __u8 memory[768], original[768];
    struct __sk_buff skb, skb_before; struct xdp_md xdp, xdp_before;
    struct x86_sim_register_state state, before;
    const __u64 patterns[]={0,0xffffffffULL,0x123456789abcdef0ULL,0xffff000012345678ULL,~0ULL};
    const __s64 deltas[]={-16,0,17};
    for (unsigned i=0;i<sizeof(memory);i++) memory[i]=(__u8)(29*i+73);
    memcpy(original,memory,sizeof(memory));
    for (unsigned pi=0;pi<5;pi++) {
        pointer_values[0]=patterns[pi]; pointer_values[1]=patterns[pi]^0x8a7b6c5d4e3f2011ULL; pointer_values[2]=~patterns[pi];
        memset(&skb,0x39,sizeof(skb)); memset(&xdp,0x51,sizeof(xdp));
        skb.data=(__u32)pointer_values[0]; skb.data_end=(__u32)pointer_values[1];
        xdp.data=(__u32)pointer_values[0]; xdp.data_end=(__u32)pointer_values[1]; xdp.data_meta=(__u32)pointer_values[2];
        skb.tc_index=0x89abcdefU; skb.priority=0x12345678U; skb.mark=0xfedcba98U;
        memcpy(&skb_before,&skb,sizeof(skb)); memcpy(&xdp_before,&xdp,sizeof(xdp));
        for (unsigned xp=0;xp<2;xp++) for (unsigned d=0;d<3;d++)
        for (unsigned wi=0;wi<4;wi++) for (unsigned off=0;off<(xp?64:256);off++) {
            unsigned width=1U<<wi, field_calls=0, bit_calls=0, copy_calls=0;
            memset(&state,0x6b,sizeof(state));
            state.helper_abi_base=memory+256; state.helper_ctx=xp?(void *)&xdp:(void *)&skb;
            state.gpr_cells[7].value.ptr=memory+256+deltas[d];
            memcpy(&before,&state,sizeof(state)); key=state.helper_ctx; kind=xp?KPROG_ABI_KIND_XDP:KPROG_ABI_KIND_SKB;
            expected_source=memory+256+off; expected_size=width;
            __u64 expected=little(expected_source,width);
            if (xp && width==8 && off<24 && !(off&7)) {
                unsigned field=off/8; expected=pointer(field); field_calls=1;
                expected_field=field==0?offsetof(struct xdp_md,data):field==1?offsetof(struct xdp_md,data_end):offsetof(struct xdp_md,data_meta);
            } else if (!xp && ((off>=X86_SKB_DATA_OFF && off+width<=X86_SKB_DATA_OFF+8) ||
                              (off>=X86_SKB_DATA_END_OFF && off+width<=X86_SKB_DATA_END_OFF+8))) {
                unsigned field=off>=X86_SKB_DATA_OFF?0:1, lane=off-(field?X86_SKB_DATA_END_OFF:X86_SKB_DATA_OFF);
                expected_bits=pointer(field); expected=expected_bits>>(lane*8); field_calls=1; bit_calls=width!=8;
                expected_field=field?offsetof(struct __sk_buff,data_end):offsetof(struct __sk_buff,data);
            } else if (!xp && off>=X86_SKB_CB_OFF && off+width<=X86_SKB_CB_OFF+20) {
                expected=little((const __u8 *)skb.cb+off-X86_SKB_CB_OFF,width);
            } else if (!xp && off>=134 && off+width<=136) expected=(__u64)skb.tc_index>>((off-134)*8);
            else if (!xp && off>=144 && off+width<=148) expected=(__u64)skb.priority>>((off-144)*8);
            else if (!xp && off>=168 && off+width<=172) expected=(__u64)skb.mark>>((off-168)*8);
            else copy_calls=1;
            if (width!=8) expected&=(1ULL<<(width*8))-1;
            for (unsigned mode=0;mode<2;mode++) {
                reset();
                __u64 value=mode ? native(xp,&state,7,state.gpr_cells[7].value.ptr,(__s64)off-deltas[d],width) :
                    xp?kprog_x86_xdp_read(&state,state.gpr_cells[7].value.ptr,(__s64)off-deltas[d],width):
                       kprog_x86_skb_read(&state,7,(__s64)off-deltas[d],width);
                check(value==expected,"context/partial/scalar/cb/fallback value");
#if defined(__COMPCERT__)
                check(fields==field_calls && bits==bit_calls && copies==copy_calls,"exact selected platform observations");
#else
                check(!fields && !bits && !copies,"native host uses actual C accesses");
#endif
                check(!memcmp(&state,&before,sizeof(state)) && !memcmp(&skb,&skb_before,sizeof(skb)) &&
                      !memcmp(&xdp,&xdp_before,sizeof(xdp)) && !memcmp(memory,original,sizeof(memory)),"whole context/state/physical frame");
            }
            cases++;
        }
    }
    const __u64 widths[]={0,1,2,3,4,7,8,9,255,256,0x100000001ULL,~0ULL};
    for (unsigned w=0;w<12;w++) for (int off=-7;off<25;off++) {
        unsigned length=1; while (length<8 && 2U*length<=widths[w]) length*=2;
        reset(); check(kprog_x86_cb_read(memory+64,off,widths[w])==little(memory+64+off,length),"raw-width byte ladder");
        check(!fields && !bits && !copies,"byte path has no unrelated platform calls"); cases++;
    }
    guarded_bytes();
    const __u64 kinds[]={0,1,2,255,256,257,~0ULL};
    const __s64 offsets[]={0,8,16,80,208,1,-1,INT64_MIN,INT64_MAX,0x1000000d0LL};
    for (unsigned k=0;k<7;k++) for (unsigned o=0;o<10;o++) {
        unsigned captured=(__u8)kinds[k]; __s64 off=offsets[o];
        unsigned expected=captured==0 && off==0 ? 2 : captured==0 && off==8 ? 3 :
                          captured==1 && off==208 ? 2 : captured==1 && off==80 ? 3 : 0;
        reset();
        check(kprog_x86_context_tag(kinds[k],off)==expected &&
              KPROG_ABI_LOAD_TAG(kinds[k],off,0,2,3)==expected,"byte kind/full signed offset/provenance tag");
        check(!fields && !bits && !copies,"tag selection performs no context read"); cases++;
    }
    printf("x86 context: %lu identity/pointer/partial/scalar/cb/fallback/tag/frame cases and6 guarded byte probes\n",cases);
    return 0;
}
