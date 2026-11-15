/* Catch eager alias/tag reads, lost physical faults, width capture changes and
 * released-value/input/frame regressions in the actual exported C bodies. */
#define _GNU_SOURCE
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <unistd.h>
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../c/X86Pointer.h"

#undef __x86_stack_mem
#define __x86_stack_mem (*arena)
#undef X86_SIM_STACK_BYTES
#define X86_SIM_STACK_BYTES capacity

static unsigned long cases;
static volatile sig_atomic_t draws, tags;
static __u64 choice;
static void *page;
static size_t page_size;
static unsigned copies;
static const void *expected_source;
static size_t expected_size;
static void check(int ok, const char *what)
{
    if (!ok) { fprintf(stderr,"tagged load case %lu: %s\n",cases,what); exit(1); }
}
unsigned long native_lab_entry_input(unsigned kind)
{
    check(kind==NATIVE_LAB_INPUT_UNSPECIFIED,"input kind");
    draws++;
    return choice;
}
void kprog_c_trap(void) { fputs("unexpected tagged-load trap\n",stderr); abort(); }
#if defined(__COMPCERT__)
void __builtin_memcpy_aligned(void *dst, const void *src, size_t size, size_t alignment)
{
    check(alignment==1 && src==expected_source && size==expected_size,"unaligned copy ABI/window");
    copies++;
    memcpy(dst,src,size);
}
#endif

static __u64 native(unsigned mode, struct x86_sim_register_state *state,
                     struct kprog_x86_arena *arena, __u32 capacity,
                     const void *address, __s64 offset, __u64 width, __u64 tag)
{
    struct x86_sim_register_state *__x86_state=state;
    if (!mode) return X86_SIM_L_LOAD_ADDR_TAGGED(address,width,tag);
    return X86_SIM_L_NATIVE_DATA_LOAD_TAGGED((const __u8 *)address-offset,offset,width,tag);
}

static __u64 poison_tag(void)
{
    tags++;
    check(mprotect(page,page_size,PROT_NONE)==0,"protect after physical access");
    return X86_SIM_TAG_STACK;
}
static void fault(int signo, siginfo_t *info, void *context)
{
    (void)context;
    _exit(signo==SIGSEGV && info->si_addr==(const __u8 *)page+8 && !draws && !tags ? 0 : 1);
}
static void order_checks(void)
{
    long size=sysconf(_SC_PAGESIZE);
    check(size>0,"page size"); page_size=(size_t)size;
    page=mmap(NULL,page_size,PROT_READ|PROT_WRITE,MAP_PRIVATE|MAP_ANONYMOUS,-1,0);
    check(page!=MAP_FAILED,"guard page allocation");
    memset(page,0x39,page_size);
    struct kprog_x86_arena storage={page,page}, *arena=&storage;
    struct x86_sim_register_state state={0}, *__x86_state=&state;
    __u32 capacity=64;
    choice=0xa1b2c3d4e5f60718ULL;
    expected_source=(const __u8 *)page+8; expected_size=8;
    for (unsigned mode=0;mode<4;mode++) {
        __u64 result;
        draws=tags=0;
        if (!mode) X86_SIM_L_LOAD_ADDR_TAGGED_INTO(result,(__u8 *)page+8,8,poison_tag());
        else if (mode==1) result=X86_SIM_L_LOAD_ADDR_TAGGED((__u8 *)page+8,8,poison_tag());
        else if (mode==2) X86_SIM_L_NATIVE_DATA_LOAD_TAGGED_INTO(result,(__u8 *)page+19,-11,8,poison_tag());
        else result=X86_SIM_L_NATIVE_DATA_LOAD_TAGGED((__u8 *)page+19,-11,8,poison_tag());
        check(mprotect(page,page_size,PROT_READ|PROT_WRITE)==0,"restore after tag");
        check(result==choice && draws==1 && tags==1,"physical read before tag and choice");
    }
    for (unsigned mode=0;mode<4;mode++) {
        draws=tags=0;
        check(mprotect(page,page_size,PROT_NONE)==0,"protect source");
        pid_t child=fork(); check(child>=0,"fork source fault");
        if (!child) {
            struct sigaction action={.sa_sigaction=fault,.sa_flags=SA_SIGINFO};
            if (sigemptyset(&action.sa_mask) || sigaction(SIGSEGV,&action,NULL)) _exit(2);
            __u64 result;
            if (mode==0) X86_SIM_L_LOAD_ADDR_TAGGED_INTO(result,(__u8 *)page+8,8,poison_tag());
            else if (mode==1) result=X86_SIM_L_LOAD_ADDR_TAGGED((__u8 *)page+8,8,poison_tag());
            else if (mode==2) result=kprog_x86_load_tagged(NULL,NULL,64,(__u8 *)page+8,8,4);
            else result=kprog_x86_native_load_tagged(NULL,NULL,64,(__u8 *)page+19,-11,8,4);
            (void)result; _exit(3);
        }
        int status;
        check(waitpid(child,&status,0)==child,"wait source fault");
        check(WIFEXITED(status) && WEXITSTATUS(status)==0,"physical fault before tag/alias/input");
        check(mprotect(page,page_size,PROT_READ|PROT_WRITE)==0,"restore source");
    }
    check(munmap(page,page_size)==0,"release guard mapping");
}

int main(void)
{
    const unsigned capacities[]={1,7,9,64,200,376};
    const __u64 widths[]={0,1,2,4,8,256,257,0x100000004ULL,0x100000008ULL};
    const __u64 tag_codes[]={0,1,4,255,256,0x100000004ULL};
    const __u64 choices[]={0,~0ULL,0x8123456789abcdefULL};
    const __s64 offsets[]={0,11,-17};
    _Alignas(8) __u8 bytes[512], before_bytes[512];
    struct x86_sim_register_state state, before;
    struct kprog_x86_arena arena={bytes+32,(volatile __u64 *)(void *)(bytes+32)};
    for (unsigned i=0;i<sizeof(bytes);i++) bytes[i]=(__u8)(17U*i+91U);
    memcpy(before_bytes,bytes,sizeof(bytes));
    memset(&state,0x6d,sizeof(state));
    for (unsigned ci=0;ci<sizeof(capacities)/sizeof(capacities[0]);ci++) {
        __u32 capacity=capacities[ci];
        const unsigned indices[]={0,1,7,capacity-1,capacity,capacity+7};
        const __s64 sps[]={-(__s64)capacity,1-(__s64)capacity,-8,0,4};
        for (unsigned ii=0;ii<6;ii++) for (unsigned si=0;si<5;si++)
        for (unsigned ti=0;ti<6;ti++) for (unsigned wi=0;wi<9;wi++)
        for (unsigned ei=0;ei<3;ei++) for (unsigned mode=0;mode<2;mode++) {
            const __u8 *address=bytes+32+indices[ii];
            __s64 alias=(__s64)indices[ii]-capacity, offset=offsets[ei];
            state.rsp.ptr=(void *)(intptr_t)sps[si];
            memcpy(&before,&state,sizeof(state));
            __u64 tag=tag_codes[ti], width=widths[wi], expected=0;
            unsigned lanes=(__u8)width; if (!lanes) lanes=8;
            for (unsigned lane=0;lane<lanes;lane++) expected|=(__u64)address[lane]<<(8U*lane);
            int released=tag==4 && alias<sps[si];
            choice=choices[ei];
            if (released) expected=choice & (lanes==8 ? ~0ULL : (1ULL<<(8U*lanes))-1);
            struct x86_sim_register_state *s=tag==4 ? &state : NULL;
            struct kprog_x86_arena *a=tag==4 ? &arena : NULL;
            draws=0;
            copies=0; expected_source=address; expected_size=lanes;
            __u64 result=mode ? kprog_x86_native_load_tagged(s,a,capacity,address-offset,offset,width,tag) :
                                kprog_x86_load_tagged(s,a,capacity,address,width,tag);
            check(result==expected && draws==released,"exported value/full tag/width/input");
#if defined(__COMPCERT__)
            check(copies==1,"one exported physical window");
#endif
            draws=0;
            copies=0;
            check(native(mode,s,a,capacity,address,offset,width,tag)==expected && draws==released,"native facade");
#if defined(__COMPCERT__)
            check(copies==1,"one facade physical window");
#endif
            check(kprog_x86_stack_alias(&arena,capacity,address)==alias,"full signed alias offset");
            check(!memcmp(&state,&before,sizeof(state)) && !memcmp(bytes,before_bytes,sizeof(bytes)),"whole state/byte frame");
            cases++;
        }
    }
    order_checks();
    printf("x86 tagged loads: %lu profile/width/tag/release/frame cases and8 ordered access probes\n",cases);
    return 0;
}
