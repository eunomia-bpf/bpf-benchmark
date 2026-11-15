/* Catch eager/reordered tag or width reads, input truncation and wrong stack
 * priority in the actual shared memory-read source selector. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../c/X86Pointer.h"

static unsigned long cases;
static char events[4];
static unsigned count;
static __u64 stack_value, tag_value, width_value;
static void check(int ok, const char *why)
{
    if (!ok) { fprintf(stderr,"read source case %lu: %s\n",cases,why); exit(1); }
}
static __u64 observe(char event, __u64 value)
{
    check(count<3,"unexpected repeated observation");
    events[count++]=event; events[count]=0; return value;
}
unsigned long native_lab_entry_input(unsigned kind)
{ (void)kind; fputs("unexpected selector input\n",stderr); abort(); }
void kprog_c_trap(void) { fputs("unexpected selector trap\n",stderr); abort(); }
void __builtin_memcpy_aligned(void *dst, const void *src, size_t size, size_t alignment)
{
    (void)dst; (void)src; (void)size; (void)alignment;
    fputs("unexpected selector memory read\n",stderr); abort();
}
int main(void)
{
    const __u64 bools[]={0,1,2,256,~0ULL};
    const __u64 extra[]={256,0x100000001ULL,0x100000008ULL,~0ULL};
    for (unsigned b=0;b<5;b++) for (unsigned t=0;t<260;t++)
    for (unsigned w=0;w<260;w++) {
        stack_value=bools[b]; tag_value=t<256?t:extra[t-256];
        width_value=w<256?w:extra[w-256];
        unsigned expected=stack_value ? 0 : tag_value==1 && width_value==8 ? 1 : 2;
        check(kprog_x86_mem_read_src(stack_value,tag_value,width_value)==expected,"root/full operand selection");
        for (unsigned facade=0;facade<2;facade++) {
            __u8 actual; count=0; events[0]=0;
            if (facade) actual=KPROG_X86_MEM_READ_SRC(observe('S',stack_value),observe('T',tag_value),observe('W',width_value));
            else KPROG_X86_MEM_READ_SRC_INTO(actual,observe('S',stack_value),observe('T',tag_value),observe('W',width_value));
            check(actual==expected,"facade/output selection");
            check(!strcmp(events,stack_value?"S":tag_value==1?"STW":"ST"),"lazy evaluation order/count");
        }
        cases++;
    }
    printf("x86 memory-read source: %lu full-operand root and lazy facade/output cases\n",cases);
    return 0;
}
