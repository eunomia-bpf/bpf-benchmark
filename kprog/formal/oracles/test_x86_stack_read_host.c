/* Catch lost volatile reads on released slots, q/d/w/b width selection,
 * fixed-capacity bindings and eager ghost payload/reference observations. */
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

static unsigned long reads, metadata;
static volatile sig_atomic_t draws;
static __u64 choice;
static void *fault_address;
static void check(int ok, const char *why)
{
    if (!ok) { fprintf(stderr,"stack reads=%lu metadata=%lu: %s\n",reads,metadata,why); exit(1); }
}
unsigned long native_lab_entry_input(unsigned kind)
{ check(kind==NATIVE_LAB_INPUT_UNSPECIFIED,"input kind"); draws++; return choice; }
void kprog_c_trap(void) { fputs("unexpected stack trap\n",stderr); abort(); }
void __builtin_memcpy_aligned(void *dst, const void *src, size_t size, size_t alignment)
{
    (void)dst; (void)src; (void)size; (void)alignment;
    fputs("unexpected nonarena read\n",stderr); abort();
}
static __u64 bytes_value(const __u8 *bytes, unsigned n)
{
    __u64 v=0; for (unsigned i=0;i<n;i++) v|=(__u64)bytes[i]<<(8*i); return v;
}
static void read_cases(void)
{
    const unsigned capacities[]={1,7,9,64,200,376};
    const __u64 extra[]={256,0x100000001ULL,0x100000008ULL,~0ULL};
    const __u64 values[]={0,0xa1b2c3d4e5f60718ULL,~0ULL};
    _Alignas(8) __u8 bytes[392],before[392];
    struct x86_sim_register_state state,initial;
    for (unsigned i=0;i<sizeof(bytes);i++) bytes[i]=(__u8)(i*37+0x83);
    memcpy(before,bytes,sizeof(bytes));
    for (unsigned ci=0;ci<6;ci++) for (unsigned wi=0;wi<260;wi++) {
        unsigned capacity=capacities[ci]; __u64 width=wi<256?wi:extra[wi-256];
        unsigned code=(__u8)width; if (!code) code=8;
        unsigned n=code==1?1:code==2?2:code==4?4:8;
        if (n>capacity) continue;
        for (unsigned probe=0;probe<18;probe++) {
            unsigned index=probe<16?probe:probe==16?capacity/2:capacity-n;
            if (index+n>capacity) continue;
            __s64 offset=(__s64)index-capacity;
            struct kprog_x86_arena arena={0};
            if (code==8 && !(index&7)) arena.q=(volatile __u64 *)(void *)bytes;
            else if (code==4 && !(index&3)) arena.d=(volatile __u32 *)(void *)bytes;
            else if (code==2 && !(index&1)) arena.w=(volatile __u16 *)(void *)bytes;
            else arena.b=bytes;
            __u64 physical=bytes_value(bytes+index,n);
            draws=0;
            check(kprog_x86_stack_read_owned(&arena,capacity,offset,width)==physical && !draws,"owned selected view/width/capacity");
            for (unsigned sp=0;sp<3;sp++) for (unsigned v=0;v<3;v++) {
                memset(&state,0x6b,sizeof(state));
                state.rsp.ptr=(void *)(intptr_t)(offset+(int)sp-1);
                memcpy(&initial,&state,sizeof(state)); choice=values[v]; draws=0;
                __u64 mask=n==8?~0ULL:(1ULL<<(n*8))-1;
                __u64 expected=sp==2 ? choice&mask : physical;
                check(kprog_x86_stack_read(&state,&arena,capacity,offset,width)==expected,"released value/width mask");
                check(draws==(sp==2),"release-boundary choice count");
                check(!memcmp(&state,&initial,sizeof(state)) && !memcmp(bytes,before,sizeof(bytes)),"complete state/bytes frame");
                reads++;
            }
        }
    }
}
static void fact_cases(void)
{
    const unsigned capacities[]={0,1,7,9,64,200,376};
    const __u64 widths[]={0,1,2,4,8,255,256,0x100000008ULL};
    struct scattered { __u64 guard; __u8 tag; void *pointer; __u64 end; } cells[47],before[47];
    struct kprog_x86_stack_fact facts[47];
    struct x86_sim_register_state state,initial;
    for (unsigned ci=0;ci<7;ci++) for (unsigned wi=0;wi<8;wi++)
    for (unsigned t=0;t<256;t++) for (unsigned at=0;at<51;at++) {
        unsigned capacity=capacities[ci],words=(capacity+7)/8;
        __u64 index=at<48 ? at*8ULL : at==48?1:at==49?0x100000000ULL:~0ULL;
        /* The original signed coordinate subtraction must be defined. */
        __s64 coordinate=(__s64)index-capacity;
        for (unsigned r=0;r<words;r++) {
            cells[r]=(struct scattered){.guard=0x12340000ULL+r,.tag=t,
                .pointer=(void *)(uintptr_t)(0xfedcba9876543200ULL+r*8),.end=~(__u64)r};
            facts[r].tag=&cells[r].tag;
            facts[r].pointer=t==4 ? &cells[r].pointer : NULL;
        }
        memcpy(before,cells,sizeof(cells));
        for (unsigned released=0;released<2;released++) {
            memset(&state,0x6b,sizeof(state)); state.rsp.ptr=(void *)(intptr_t)(coordinate+released);
            memcpy(&initial,&state,sizeof(state)); draws=0;
            unsigned code=(__u8)widths[wi]; if (!code) code=8;
            int selected=!released && code==8 && index/8<words && !(index&7);
            struct x86_sim_stack_value output={.tag=0xaa,.pointer=(void *)(uintptr_t)0x123};
            kprog_x86_stack_values_read(&state,selected?facts:NULL,capacity,index,widths[wi],&output);
            check(output.tag==(selected?t:0),"ghost tag/width/coordinate/word matching");
            check(output.pointer==(selected && t==4 ? cells[index/8].pointer : NULL),"lazy stack-only ghost payload");
            check(!draws && !memcmp(&state,&initial,sizeof(state)) && !memcmp(cells,before,sizeof(cells)),"ghost complete frame/input");
            metadata++;
        }
    }
}
static void fault(int sig, siginfo_t *info, void *context)
{ (void)context; _exit(sig==SIGSEGV && info->si_addr==fault_address && !draws ? 0 : 1); }
static void guard_cases(void)
{
    long page=sysconf(_SC_PAGESIZE); check(page>0,"page size");
    __u8 *memory=mmap(NULL,page*3,PROT_READ|PROT_WRITE,MAP_PRIVATE|MAP_ANONYMOUS,-1,0);
    check(memory!=MAP_FAILED,"guard mapping"); memset(memory,0x39,page);
    check(!mprotect(memory+page,page*2,PROT_NONE),"guard protection");
    for (unsigned n=1;n<=8;n*=2) {
        struct x86_sim_register_state state={0}; state.rsp.ptr=0;
        struct kprog_x86_arena arena={.b=memory+page-n,
            .q=(volatile __u64 *)(void *)(memory+page-n),
            .w=(volatile __u16 *)(void *)(memory+page-n),
            .d=(volatile __u32 *)(void *)(memory+page-n)};
        choice=~0ULL; draws=0;
        check(kprog_x86_stack_read_owned(&arena,n,-(__s64)n,n)==bytes_value(memory+page-n,n),"guarded exact read size");
        check(kprog_x86_stack_read(&state,&arena,n,-(__s64)n,n)==(n==8?~0ULL:(1ULL<<(n*8))-1) && draws==1,"guarded released read");
    }
    for (unsigned owned=0;owned<2;owned++) {
        pid_t pid=fork(); check(pid>=0,"fault fork");
        if (!pid) {
            struct sigaction action={0}; action.sa_sigaction=fault; action.sa_flags=SA_SIGINFO;
            if (sigemptyset(&action.sa_mask) || sigaction(SIGSEGV,&action,NULL)) _exit(2);
            struct kprog_x86_arena arena={.q=(volatile __u64 *)(void *)(memory+page-8)};
            fault_address=memory+page; draws=0;
            /* SP itself is inaccessible on a distinct page: physical read
             * must fault first, even for a released-value observation. */
            if (owned) (void)kprog_x86_stack_read_owned(&arena,16,-8,8);
            else (void)kprog_x86_stack_read((void *)(memory+page*2),&arena,16,-8,8);
            _exit(3);
        }
        int status; check(waitpid(pid,&status,0)==pid && WIFEXITED(status) && !WEXITSTATUS(status),"physical fault before SP/choice");
    }
    check(!munmap(memory,page*3),"guard unmap");
}
static unsigned offset_calls,width_calls,sp_calls;
static __s64 capture_offset;
static __u64 capture_width;
static int capture_released;
static void *capture_page;
static size_t capture_page_size;
static __s64 offset_probe(void) { offset_calls++; return capture_offset; }
static __u64 width_probe(void) { width_calls++; return capture_width; }
static __s64 sp_probe(void)
{
    sp_calls++;
    check(!mprotect(capture_page,capture_page_size,PROT_NONE),"protect at SP observation");
    return capture_offset+capture_released;
}
#undef __x86_stack_mem
#define __x86_stack_mem (*arena)
#undef X86_SIM_STACK_BYTES
#define X86_SIM_STACK_BYTES capacity
#pragma push_macro("X86_SIM_L_STACK_SP")
#undef X86_SIM_L_STACK_SP
#define X86_SIM_L_STACK_SP() sp_probe()
static void capture_cases(void)
{
    const __u64 widths[]={0,1,2,4,8,3,0x100000008ULL};
    capture_page_size=(size_t)sysconf(_SC_PAGESIZE);
    capture_page=mmap(NULL,capture_page_size,PROT_READ|PROT_WRITE,MAP_PRIVATE|MAP_ANONYMOUS,-1,0);
    check(capture_page!=MAP_FAILED,"capture mapping"); memset(capture_page,0x39,capture_page_size);
    __u32 capacity=64;
    struct kprog_x86_arena storage={.b=capture_page,.q=capture_page,.w=capture_page,.d=capture_page},*arena=&storage;
    for (unsigned wi=0;wi<7;wi++) for (unsigned index=8;index<16;index++)
    for (unsigned released=0;released<2;released++) for (unsigned facade=0;facade<2;facade++) {
        capture_offset=(__s64)index-capacity; capture_width=widths[wi]; capture_released=released;
        unsigned code=(__u8)capture_width; if (!code) code=8;
        unsigned n=code==1?1:code==2?2:code==4?4:8;
        unsigned physical_evals=code==8 && !(index&7)?1:code==4 && !(index&3)?2:code==2 && !(index&1)?3:4;
        choice=~0ULL; offset_calls=width_calls=sp_calls=0; draws=0;
        __u64 expected=released ? n==8?~0ULL:(1ULL<<(n*8))-1 : bytes_value((__u8 *)capture_page+index,n);
        __u64 value;
        if (facade) value=X86_SIM_L_STACK_READ(offset_probe(),width_probe());
        else X86_SIM_L_STACK_READ_INTO(value,offset_probe(),width_probe());
        check(!mprotect(capture_page,capture_page_size,PROT_READ|PROT_WRITE),"restore after SP observation");
        check(value==expected && draws==released,"read before SP protection/choice");
        check(offset_calls==2 && width_calls==physical_evals+released && sp_calls==1,"repeated operand capture counts");
    }
    check(!munmap(capture_page,capture_page_size),"capture unmap");
}
#pragma pop_macro("X86_SIM_L_STACK_SP")
int main(void)
{
    read_cases(); fact_cases(); guard_cases(); capture_cases();
    printf("x86 stack read: %lu read/frame cases, %lu lazy metadata/frame cases, 6 guarded size/fault probes,224 capture/protected-SP probes\n",reads,metadata);
    return 0;
}
