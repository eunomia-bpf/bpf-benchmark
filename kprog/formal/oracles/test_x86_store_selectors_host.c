/* Catch store immediate slicing/sign extension, raw width truth/capture,
 * eager register/AUX reads and source-shift or whole-frame regressions. */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../c/X86Pointer.h"

static unsigned long scalar_cases,prefix_cases;
static char events[16];static unsigned count;
static __u64 bool_value,imm_value,width_value,source_value,aux_value,shift_value;
static void check(int ok,const char *why)
{
    if (!ok) { fprintf(stderr,"store scalar=%lu prefix=%lu: %s\n",scalar_cases,prefix_cases,why); exit(1); }
}
static void event(char c) { check(count<15,"repeated observation");events[count++]=c;events[count]=0; }
static __u64 boolean(void) { event('B');return bool_value; }
static __u64 immediate(void) { event('I');return imm_value++; }
static __u64 width(void) { event('W');return width_value++; }
static __u64 source(void) { event('R');return source_value++; }
static __u64 auxiliary(void) { event('A');return aux_value++; }
static __u64 shift(void) { event('S');return shift_value++; }
unsigned long native_lab_entry_input(unsigned kind)
{ (void)kind;fputs("unexpected store-selector input\n",stderr);abort(); }
void kprog_c_trap(void) { fputs("unexpected store-selector trap\n",stderr);abort(); }
void __builtin_memcpy_aligned(void *dst,const void *src,size_t n,size_t alignment)
{ (void)dst;(void)src;(void)n;(void)alignment;fputs("unexpected store-selector memory read\n",stderr);abort(); }
static void reset(void) { count=0;events[0]=0; }
static __u64 imm_reference(__u64 imm,__u64 w)
{ return (imm&0xffffffffULL) | (w==8 && (imm&0x80000000ULL)?0xffffffff00000000ULL:0); }
static void scalar_checks(void)
{
    const __u64 bools[]={0,1,2,256,~0ULL};
    const __u64 values[]={0,1,0x7fffffffULL,0x80000000ULL,0xffffffffULL,0x1234567880000000ULL,0x80000000ffffffffULL,~0ULL};
    const __u64 widths[]={0,1,2,4,8,255,256,0x100000008ULL};
    const __u64 extra[]={256,0x100000000ULL,0x100000008ULL,~0ULL};
    for (unsigned f=0;f<260;f++) {
        __u64 flags=f<256?f:extra[f-256];
        check(kprog_x86_store_width(flags)==(flags?(__u8)flags:8),"raw width before byte capture");
        for (unsigned facade=0;facade<2;facade++) {
            width_value=flags;reset();__u8 result;
            if (facade) result=KPROG_X86_STORE_WIDTH(width());
            else KPROG_X86_STORE_WIDTH_INTO(result,width());
            check(result==(flags?(__u8)(flags+1):8) && !strcmp(events,flags?"WW":"W"),"width repeated evaluation/default");
        }
    }
    for (unsigned b=0;b<5;b++) for (unsigned v=0;v<8;v++) for (unsigned w=0;w<8;w++) {
        __u64 imm=values[v],code=widths[w],truth=bools[b];
        __u64 expected=truth?imm_reference(imm,code):~imm;
        check(kprog_x86_store_value(truth,imm,code,~imm)==expected,"immediate sign extension/source selection");
        check(kprog_x86_store_disp(truth,imm)==(truth?(__s64)(__s32)(imm>>32):(__s64)imm),"high32 versus whole displacement");
        check(kprog_x86_store_src_shift(truth,imm)==(truth?0:((imm>>24)&255)),"source shift AUX byte/lazy immediate");
        check(kprog_x86_store_arm(truth)==(truth?0:1),"full boolean arm");
        bool_value=truth;reset();__u8 arm;
        KPROG_X86_STORE_ARM_INTO(arm,boolean());
        check(arm==(truth?0:1) && !strcmp(events,"B"),"arm one full-truth observation");
        for (unsigned facade=0;facade<2;facade++) {
            bool_value=truth;imm_value=imm;width_value=code;source_value=~imm;reset();__u64 result;
            if (facade) result=KPROG_X86_STORE_VALUE(boolean(),immediate(),width(),source());
            else KPROG_X86_STORE_VALUE_INTO(result,boolean(),immediate(),width(),source());
            __u64 observed=code==8?imm+1:imm;
            __u64 value=truth ? (observed&0xffffffffULL) | (code==8 && (imm&0x80000000ULL)?0xffffffff00000000ULL:0) : ~imm;
            check(result==value && !strcmp(events,!truth?"BR":code==8?"BWII":"BWI"),"value branch/evaluation order and counts");
            imm_value=imm;reset();__s64 displacement;
            if (facade) displacement=KPROG_X86_STORE_DISP(boolean(),immediate());
            else KPROG_X86_STORE_DISP_INTO(displacement,boolean(),immediate());
            check(displacement==(truth?(__s64)(__s32)(imm>>32):(__s64)imm) && !strcmp(events,"BI"),"displacement lazy selected slice");
            aux_value=imm;reset();__u32 resolved;
            if (facade) resolved=KPROG_X86_STORE_SRC_SHIFT(boolean(),auxiliary());
            else KPROG_X86_STORE_SRC_SHIFT_INTO(resolved,boolean(),auxiliary());
            check(resolved==(truth?0:((imm>>24)&255)) && !strcmp(events,truth?"B":"BA"),"no AUX observation on immediate");
        }
        for (unsigned n=0;n<64;n++) {
            check(kprog_x86_store_shifted_value(imm,n)==imm>>n,"defined source shifts");
            source_value=imm;shift_value=n;reset();__u64 result;
            KPROG_X86_STORE_SHIFTED_VALUE_INTO(result,source(),shift());
            check(result==(imm>>n) && (!strcmp(events,"RS") || !strcmp(events,"SR")),"one observation per shift operand; C order preserved");
        }
        scalar_cases++;
    }
}
static void prefix_checks(void)
{
    const __u64 extra[]={256,0x100000000ULL,0x100000008ULL,~0ULL};
    const __u64 opcodes[]={X86_OP_MOV_STORE_IMM,X86_OP_MOV_STORE_REG,0,0x100000007ULL};
    const __u64 registers[]={0,1,4,7,15,16,255,256,0x100000004ULL};
    const __u64 immediates[]={0x1234567880000000ULL,0x80000000ffffffffULL,0xffffffff7fffffffULL};
    const unsigned shifts[]={0,8,63},capacities[]={1,64,200,376};
    _Alignas(8) __u8 bytes[392],before[392];memset(bytes,0xa7,sizeof(bytes));memcpy(before,bytes,sizeof(bytes));
    struct kprog_x86_arena arena={.b=bytes,.q=(void *)bytes,.w=(void *)bytes,.d=(void *)bytes};
    struct x86_sim_register_state state,initial;
    for (unsigned c=0;c<4;c++) for (unsigned op=0;op<4;op++) for (unsigned f=0;f<260;f++)
    for (unsigned r=0;r<9;r++) for (unsigned sh=0;sh<3;sh++) for (unsigned v=0;v<3;v++) {
        unsigned capacity=capacities[c];__u64 src=registers[r],flags=f<256?f:extra[f-256],imm=immediates[v];
        __u64 aux=((__u64)shifts[sh]<<24)|0x00a139ffULL;
        unsigned code=flags?(__u8)flags:8,reg=(__u8)src;int immediate_op=opcodes[op]==X86_OP_MOV_STORE_IMM;
        memset(&state,0x6b,sizeof(state));state.native_stack_base=0xfedcba9876543210ULL;
        for (unsigned i=0;i<16;i++) {
            state.gpr_cells[i].tag=(f&1)?4:0;
            state.gpr_cells[i].value.ptr=(f&1)?bytes+(i*7U)%capacity:(void *)(uintptr_t)(0x123456789abcdef0ULL+i*17);
        }
        state.rsp.ptr=(void *)(intptr_t)-16;memcpy(&initial,&state,sizeof(state));
        __u64 raw=reg>=16?0:reg==4?state.native_stack_base-16:(f&1)?
            state.native_stack_base+((__u64)(uintptr_t)state.gpr_cells[reg].value.ptr-(__u64)(uintptr_t)(bytes+capacity)):(uintptr_t)state.gpr_cells[reg].value.ptr;
        struct kprog_x86_store_selection result;
        kprog_x86_store_selectors(immediate_op || reg>=16?NULL:&state,(f&1) && reg<16 && reg!=4 && !immediate_op?&arena:NULL,
                                  capacity,opcodes[op],src,flags,aux,imm,&result);
        __u64 expected=immediate_op?imm_reference(imm,code):raw>>shifts[sh];
        check(result.width==code && result.displacement==(immediate_op?(__s64)(__s32)(imm>>32):(__s64)imm) && result.value==expected,"actual store prefix/lazy register/capture fields");
        check(!memcmp(&state,&initial,sizeof(state)) && !memcmp(bytes,before,sizeof(bytes)),"complete prefix state/arena frame");prefix_cases++;
    }
}
int main(void)
{
    scalar_checks();prefix_checks();
    printf("x86 store selectors:260 width captures,%lu scalar/capture groups,%lu lazy prefix/frame cases\n",scalar_cases,prefix_cases);
    return 0;
}
