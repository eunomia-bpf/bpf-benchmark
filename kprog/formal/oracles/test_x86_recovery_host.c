/* Catch eager address/index reads, wrong input bits, early writes and changed
 * full-operand fault gates in the production and exported recovery bodies. */
#define _GNU_SOURCE
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <setjmp.h>
#include <unistd.h>
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../c/X86Pointer.h"
#pragma push_macro("X86_SIM_L_READ_RECOVERY_MEM")
#include "../../x86/x86_sim_inline.h"
#pragma pop_macro("X86_SIM_L_READ_RECOVERY_MEM")
#undef __x86_stack_mem
#define __x86_stack_mem (*arena)
#undef X86_SIM_STACK_BYTES
#define X86_SIM_STACK_BYTES capacity
#undef X86_SIM_L_SV_TAG
#undef X86_SIM_L_SV_PTR
#define X86_SIM_L_SV_TAG(I) (*facts[(I)].tag)
#define X86_SIM_L_SV_PTR(I) (*facts[(I)].pointer)

static struct x86_sim_register_state state, before, expected;
static sigjmp_buf fault_env;
static volatile sig_atomic_t armed, trapped, event_count;
static char events[16];
static __u64 choice, probe_aux, probe_index;
static __s64 probe_disp;
static int probe_present, expected_draw;
static unsigned long offset_cases, recovery_cases, inline_cases;
static int observed;
static void check(int ok, const char *what)
{
    if (!ok) { fprintf(stderr,"recovery offset=%lu case=%lu: %s\n",offset_cases,recovery_cases,what); exit(1); }
}
static void event(char c) { check(event_count<15,"event capacity"); events[event_count++]=c; events[event_count]=0; }
unsigned long native_lab_entry_input(unsigned kind)
{
    check(kind==NATIVE_LAB_INPUT_UNSPECIFIED && expected_draw,"choice gate/kind");
    check(!memcmp(&state,&before,sizeof(state)),"no state commit before input");
    event('U'); return choice;
}
static void trap_signal(int signo)
{
    if (!armed || signo!=SIGILL) _exit(90);
    trapped=1; events[event_count++]='T'; events[event_count]=0;
    siglongjmp(fault_env,1);
}
void kprog_c_trap(void) { trap_signal(SIGILL); abort(); }
void __builtin_memcpy_aligned(void *dst, const void *src, size_t size, size_t alignment)
{
    (void)dst; (void)src; (void)size; (void)alignment;
    fputs("unexpected physical read in address/recovery\n",stderr); abort();
}
static __u64 aux_probe(void) { event('A'); return probe_aux; }
static __s64 disp_probe(void) { event('D'); return probe_disp; }
static __u64 index_probe(void) { event('I'); return probe_index; }
static int present_probe(void) { event('H'); return probe_present; }
static __u64 address_probe(void) { event('A'); return probe_index; }
static __u64 number(struct x86_sim_register_state *s, struct kprog_x86_arena *a,
                      unsigned capacity, __u64 reg)
{
    unsigned r=(__u8)reg;
    if (r>=16) return 0;
    __u64 value=(uintptr_t)s->gpr_cells[r].value.ptr;
    if (r==4) return value+s->native_stack_base;
    if (s->gpr_cells[r].tag==4) return value-(uintptr_t)a->b-capacity+s->native_stack_base;
    return value;
}
static __s64 offset_reference(struct kprog_x86_arena *a, unsigned capacity, __u64 aux, __s64 disp)
{
    unsigned index=aux&255U, scale=(aux>>8)&255U;
    __u64 value=index==255 ? 0 : number(&before,a,capacity,index);
    return (__s64)((__u64)disp+(index!=255 && scale<64 ? value<<scale : 0));
}
static int native_recovery(unsigned kind, struct kprog_x86_arena *arena, __u32 capacity,
                             __u64 base, __u64 dst, __u64 address, __u64 aux, __s64 disp)
{
    struct x86_sim_register_state *__x86_state=&state;
    struct kprog_x86_stack_fact *facts=NULL;
    if (!kind) return X86_SIM_L_READ_RECOVERY_AT(base,dst,address);
    if (kind==1) return X86_SIM_L_READ_RECOVERY(base,dst);
    return X86_SIM_L_READ_RECOVERY_MEM(base,dst,aux,disp);
}
static __s64 native_offset(struct kprog_x86_arena *arena, __u32 capacity, __u64 aux, __s64 disp)
{
    struct x86_sim_register_state *__x86_state=&state;
    return X86_SIM_L_MEM_OFFSET(aux,disp);
}
static void initialize(struct kprog_x86_arena *arena, unsigned capacity, unsigned tag, __u64 origin)
{
    memset(&state,0x59,sizeof(state));
    for (unsigned r=0;r<16;r++) {
        state.gpr_cells[r].value.ptr=tag==4 ? (void *)(arena->b+(r*7U)%capacity) :
            (void *)(uintptr_t)(0x1020304050607080ULL ^ ((__u64)r*0x11223344556677ULL));
        state.gpr_cells[r].tag=tag;
    }
    state.rsp.ptr=(void *)(intptr_t)-16; state.native_stack_base=origin;
}
static int excluded_base(struct kprog_x86_arena *arena, __u32 capacity, __u64 base)
{
    struct x86_sim_register_state *__x86_state=&state;
    struct kprog_x86_stack_fact *facts=NULL;
    int result;
    X86_SIM_L_READ_RECOVERY_AT_INTO(result,base,4,address_probe());
    return result;
}
int main(void)
{
    struct sigaction action={.sa_handler=trap_signal};
    check(!sigemptyset(&action.sa_mask) && !sigaction(SIGILL,&action,NULL),"trap handler");
    const unsigned capacities[]={1,64,200}, tags[]={0,1,4,7,255};
    const unsigned scales[]={0,1,3,7,31,32,63,64,127,255};
    const __s64 disps[]={0,1,-1,4095,4096,-4096,INT64_MIN,INT64_MAX};
    const __u64 origins[]={0,~0ULL,0x123456789abcdef0ULL};
    union x86_sim_stack_mem small;
    _Alignas(8) __u8 large[512];
    memset(&small,0xa7,sizeof(small)); memset(large,0xa7,sizeof(large));
    for (unsigned ci=0;ci<3;ci++) for (unsigned ti=0;ti<5;ti++) for (unsigned oi=0;oi<3;oi++) {
        unsigned capacity=capacities[ci];
        struct kprog_x86_arena arena={.b=capacity==64?small.b:large+32,.q=NULL};
        initialize(&arena,capacity,tags[ti],origins[oi]); memcpy(&before,&state,sizeof(state));
        for (unsigned ix=0;ix<19;ix++) for (unsigned sc=0;sc<10;sc++) for (unsigned di=0;di<8;di++) {
            unsigned index=ix<16 ? ix : ix==16 ? 16 : ix==17 ? 254 : 255;
            __u64 aux=0xfedcba9800000000ULL|X86_MEM_AUX(index,scales[sc]);
            __s64 value=offset_reference(&arena,capacity,aux,disps[di]);
            struct kprog_x86_arena *a=index==255 || index>=16 ? NULL : &arena;
            struct x86_sim_register_state *s=a ? &state : NULL;
            check(kprog_x86_mem_offset(s,a,capacity,aux,disps[di])==value,"exported offset/wrapping/scale");
            check(native_offset(&arena,capacity,aux,disps[di])==value,"native offset");
#if defined(__COMPCERT__)
            if (capacity==64) {
                struct x86_sim_inline_bindings b={0};
                b.cells=s ? state.gpr_cells : NULL; b.stack=&small; b.native_stack_base=&state.native_stack_base;
                check(x86_sim_inline_mem_offset(&b,aux,disps[di])==value,"inline offset binding"); inline_cases++;
            }
#endif
            check(!memcmp(&state,&before,sizeof(state)),"offset full state frame"); offset_cases++;
        }
    }
    const __u64 bases[]={0,1,4,15,16,255,256,0x100000004ULL,~0ULL};
    const __u64 dests[]={0,1,4,15,16,255,0x100000004ULL};
    const __u64 words[]={0,1,2,0x8000000000000000ULL,0x100000001ULL,~0ULL};
    struct kprog_x86_arena arena={.b=small.b,.q=small.q}; unsigned capacity=64;
    for (unsigned bi=0;bi<9;bi++) for (unsigned dj=0;dj<7;dj++) for (unsigned ti=0;ti<4;ti++)
    for (unsigned di=0;di<8;di++) for (unsigned wi=0;wi<6;wi++) for (unsigned kind=0;kind<3;kind++) {
        __u64 base=bases[bi],dst=dests[dj],raw=(__u64)disps[di];
        initialize(&arena,64,0,origins[di%3]);
        state.gpr_cells[2].value.ptr=(void *)&small.b[7]; state.gpr_cells[2].tag=4;
        if (base<16 && base!=4) { state.gpr_cells[base].tag=tags[ti]; state.gpr_cells[base].value.ptr=(void *)(uintptr_t)raw; }
        memcpy(&before,&state,sizeof(state)); memcpy(&expected,&state,sizeof(state));
        __u64 aux=X86_MEM_AUX(di%3==0?255:di%3==1?2:4,scales[di]);
        __u64 address=!kind ? raw : number(&before,&arena,64,base);
        if (kind==2) address+=(__u64)offset_reference(&arena,64,aux,disps[di]);
        int eligible=base!=255 && base!=4 && (base>=16 || before.gpr_cells[base].tag==0);
        expected_draw=eligible && address>=4096;
        int recover=eligible && (address<4096 || (words[wi]&1)), expect_trap=recover && dst==4;
        if (recover && !expect_trap && dst<16) { expected.gpr_cells[dst].value.ptr=NULL; expected.gpr_cells[dst].tag=0; }
        choice=words[wi];
        for (unsigned mode=0;mode<3;mode++) {
#if !defined(__COMPCERT__)
            if (mode==2) continue;
#endif
            if (mode==2 && !kind) continue;
            memcpy(&state,&before,sizeof(state)); event_count=trapped=0; events[0]=0; observed=99; armed=1;
            if (!sigsetjmp(fault_env,1)) {
                if (mode==1) observed=native_recovery(kind,&arena,64,base,dst,raw,aux,disps[di]);
                else if (!mode) {
                    if (!kind) observed=kprog_x86_read_recovery_at(&state,&arena,NULL,64,base,dst,raw);
                    else if (kind==1) observed=kprog_x86_read_recovery(&state,&arena,NULL,64,base,dst);
                    else observed=kprog_x86_read_recovery_mem(&state,&arena,NULL,64,base,dst,aux,disps[di]);
                }
#if defined(__COMPCERT__)
                else {
                    struct x86_sim_inline_bindings b={0};
                    b.cells=state.gpr_cells; b.stack=&small; b.native_stack_base=&state.native_stack_base;
                    observed=kind==1 ? x86_sim_inline_read_recovery(&b,base,dst) :
                        x86_sim_inline_read_recovery_mem(&b,base,dst,aux,disps[di]); inline_cases++;
                }
#endif
            }
            armed=0;
            check(trapped==expect_trap && observed==(expect_trap?99:recover),"recovery/fault/result");
            check(!strcmp(events,expect_trap?(expected_draw?"UT":"T"):(expected_draw?"U":"")),"choice/fault prefix");
            check(!memcmp(&state,&expected,sizeof(state)),"complete destination/tag/frame");
            for (unsigned n=0;n<sizeof(small.b);n++) check(small.b[n]==0xa7,"arena unchanged");
        }
        recovery_cases++;
    }
    for (unsigned sc=0;sc<10;sc++) for (int present=0;present<3;present++) {
        probe_aux=X86_MEM_AUX(1,scales[sc]); probe_disp=INT64_MIN+17; probe_index=~0ULL; probe_present=present? -present:0;
        __s64 result; events[0]=0; event_count=0;
        KPROG_X86_MEM_OFFSET_INTO(result,aux_probe(),disp_probe(),index_probe(),present_probe());
        __u64 value=(__u64)probe_disp+(present && scales[sc]<64 ? probe_index<<scales[sc] : 0);
        check((__u64)result==value && !strcmp(events,present?"DHAI":"DH"),"lazy index/capture order");
        check(kprog_x86_mem_offset_indexed(probe_aux,probe_disp,probe_index,probe_present)==(__s64)value,"indexed root");
    }
    for (unsigned base=0;base<2;base++) {
        __u64 operand=base?255:4; int result; events[0]=0; event_count=0;
        result=excluded_base(&arena,capacity,operand);
        check(result==0 && event_count==0,"excluded base must not read address");
    }
#if defined(__COMPCERT__)
    struct x86_sim_inline_bindings empty={0};
    check(!x86_sim_inline_read_recovery(&empty,4,4) &&
          !x86_sim_inline_read_recovery_mem(&empty,255,4,~0ULL,INT64_MIN),"excluded binding needs no references");
    inline_cases+=2;
#endif
    printf("x86 recovery: %lu offsets, %lu recovery/frame cases, %lu inline executions,32 lazy capture probes\n",offset_cases,recovery_cases,inline_cases);
    return 0;
}
