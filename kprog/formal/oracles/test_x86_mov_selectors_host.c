/* Catch truth-before-byte capture, fallback evaluation order and eager tag
 * observations in the actual MOV-load selector kernels and declaration forms. */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../c/X86Pointer.h"

static unsigned long widths, arms, fields;
static char events[16];
static unsigned count;
static __u64 flags_probe, aux_probe_value, stack_probe, plain_probe, mem_probe, write_probe, tag_probe;
static void check(int ok, const char *what)
{
    if (!ok) { fprintf(stderr,"MOV selectors widths=%lu arms=%lu fields=%lu: %s\n",widths,arms,fields,what); exit(1); }
}
static void event(char c) { check(count<15,"event capacity"); events[count++]=c; events[count]=0; }
static __u64 flag(void) { event('F'); return flags_probe++; }
static __u64 auxiliary(void) { event('A'); return aux_probe_value++; }
static __u64 stack(void) { event('B'); return stack_probe; }
static __u64 plain(void) { event('I'); return plain_probe; }
static __u64 memory(void) { event('M'); return mem_probe; }
static __u64 writing(void) { event('W'); return write_probe; }
static __u64 tag(void) { event('T'); return tag_probe; }
unsigned long native_lab_entry_input(unsigned kind)
{
    (void)kind; fputs("unexpected input in MOV selectors\n",stderr); abort();
}
void kprog_c_trap(void) { fputs("unexpected selector trap\n",stderr); abort(); }
void __builtin_memcpy_aligned(void *dst, const void *src, size_t size, size_t alignment)
{
    (void)dst; (void)src; (void)size; (void)alignment;
    fputs("unexpected physical read in MOV selectors\n",stderr); abort();
}
struct selection { unsigned write, memory, arm; };
static struct selection select_fields(struct x86_sim_register_state *state,
                                        __u64 op, __u64 src, __u64 flags, __u64 aux)
{
    struct x86_sim_register_state *__x86_state=state;
    X86_SIM_L_MOV_LOAD_SELECTORS(op,src,flags,aux);
    return (struct selection){__x86_l_write_width,__x86_l_mem_width,__x86_l_arm};
}
int main(void)
{
    const __u64 other_aux[]={0,~0ULL,0x123456789abcdef0ULL};
    const __u64 extra_flags[]={256,0x100000000ULL,0x100000008ULL,~0ULL};
    const __u64 opcodes[]={X86_OP_MOV_LOAD,X86_OP_MOVSX_LOAD,0,0x100000000ULL|X86_OP_MOV_LOAD};
    const __u64 sources[]={0,4,15,255,0x100000004ULL};
    const unsigned tag_codes[]={0,1,255};
    struct x86_sim_register_state state, before;
    memset(&state,0x6b,sizeof(state));
    for (unsigned fi=0;fi<260;fi++) for (unsigned m=0;m<256;m++) for (unsigned a=0;a<3;a++) {
        __u64 f=fi<256 ? fi : extra_flags[fi-256];
        __u64 aux=(other_aux[a]&~(0xffULL<<16))|((__u64)m<<16);
        unsigned w=f ? (__u8)f : 8, mw=m ? m : w;
        check(kprog_x86_mov_load_write_width(f)==w && KPROG_X86_MOV_LOAD_WRITE_WIDTH(f)==w,"raw write-width truth/capture");
        check(kprog_x86_mov_load_mem_width(f,aux)==mw && KPROG_X86_MOV_LOAD_MEM_WIDTH(f,aux)==mw,"memory width/fallback/aux byte");
        for (unsigned r=0;r<16;r++) state.gpr_cells[r].tag=tag_codes[a];
        memcpy(&before,&state,sizeof(state));
        for (unsigned oi=0;oi<4;oi++) for (unsigned si=0;si<5;si++) {
            __u64 src=sources[si], op=opcodes[oi];
            int needs_tag=src!=4 && op==X86_OP_MOV_LOAD && mw==8 && w==8 && src<16;
            unsigned expected=src==4 ? 0 : needs_tag && tag_codes[a]==1 ? 1 : 2;
            struct selection result=select_fields(needs_tag?&state:NULL,op,src,f,aux);
            check(result.write==w && result.memory==mw && result.arm==expected,"actual declaration/lazy state binding");
            check(!memcmp(&state,&before,sizeof(state)),"complete state frame"); fields++;
        }
        widths++;
    }
    const __u64 bools[]={0,1,2,256,~0ULL};
    const __u64 sizes[]={0,1,2,4,8,256,0x100000008ULL};
    const __u64 tags[]={0,1,4,255,256,0x100000001ULL};
    for (unsigned b=0;b<5;b++) for (unsigned p=0;p<5;p++)
    for (unsigned m=0;m<7;m++) for (unsigned w=0;w<7;w++) for (unsigned t=0;t<6;t++) {
        __u64 bs=bools[b], pl=bools[p], mem=sizes[m], wr=sizes[w], tg=tags[t];
        unsigned expected=bs ? 0 : pl && mem==8 && wr==8 && tg==1 ? 1 : 2;
        check(kprog_x86_mov_load_arm(bs,pl,mem,wr,tg)==expected &&
              KPROG_X86_MOV_LOAD_ARM(bs,pl,mem,wr,tg)==expected,"full-width arm facts/priority");
        __u8 actual;
        stack_probe=bs; plain_probe=pl; mem_probe=mem; write_probe=wr; tag_probe=tg;
        count=0; events[0]=0;
        KPROG_X86_MOV_LOAD_ARM_INTO(actual,stack(),plain(),memory(),writing(),tag());
        const char *prefix=bs?"B":!pl?"BI":mem!=8?"BIM":wr!=8?"BIMW":"BIMWT";
        check(actual==expected && !strcmp(events,prefix),"arm short-circuit/capture order"); arms++;
    }
    const __u64 probes[]={0,1,255,256,0x100000000ULL,~0ULL};
    for (unsigned fi=0;fi<6;fi++) for (unsigned m=0;m<2;m++) for (unsigned facade=0;facade<2;facade++) {
        __u64 initial=probes[fi]; __u8 result;
        flags_probe=initial; aux_probe_value=(__u64)m<<16; count=0; events[0]=0;
        if (facade) result=KPROG_X86_MOV_LOAD_MEM_WIDTH(flag(),auxiliary());
        else KPROG_X86_MOV_LOAD_MEM_WIDTH_INTO(result,flag(),auxiliary());
        unsigned expected=m ? m : initial ? (__u8)(initial+1) : 8;
        check(result==expected && !strcmp(events,m?"A":initial?"AFF":"AF"),"lazy fallback/test-before-capture");
        check(flags_probe==initial+(m?0:initial?2:1) && aux_probe_value==((__u64)m<<16)+1,"input evaluation counts");
        flags_probe=initial; count=0; events[0]=0;
        if (facade) result=KPROG_X86_MOV_LOAD_WRITE_WIDTH(flag());
        else KPROG_X86_MOV_LOAD_WRITE_WIDTH_INTO(result,flag());
        check(result==(initial?(__u8)(initial+1):8) && !strcmp(events,initial?"FF":"F"),"write capture sequence");
    }
    printf("x86 MOV selectors: %lu width/aux cases, %lu full arm/capture cases, %lu lazy state/frame declarations,48 fallback/capture probes\n",widths,arms,fields);
    return 0;
}
