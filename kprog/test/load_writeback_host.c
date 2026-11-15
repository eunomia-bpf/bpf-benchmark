/* Catch loss of saved pointer representatives, overlapping-base writes,
 * RSP release ordering and extra environment draws during load writeback. */
#define X86_SIM_ENABLE_STACK 1
#include "kprog/x86/x86_sim_local_bpf.h"
#include <stdio.h>
#include <string.h>

static unsigned long choice;
static unsigned draws;
static const unsigned long origin = 0x12340000UL;

unsigned long native_lab_entry_input(unsigned int kind)
{
    if (kind == NATIVE_LAB_INPUT_SP) return origin;
    if (kind == NATIVE_LAB_INPUT_UNSPECIFIED) { ++draws; return choice; }
    abort();
}

static int run(unsigned mode, unsigned tag)
{
    X86_SIM_ENTRY_RAW((void *)0);
    __x86_rsp.ptr = (void *)-48L;
    for (unsigned i = 0; i < X86_SIM_STACK_BYTES; ++i)
        __x86_stack_mem.b[i] = (unsigned char)(0x80U + i);
    unsigned char before[X86_SIM_STACK_BYTES];
    void *representative = X86_SIM_L_STACK_PTR(-8);
    unsigned long bits = tag == X86_SIM_TAG_STACK ? origin - 8 : 0x87654321UL;
    if (mode == 3) bits = origin - 16;
    __x86_stack_mem.q[(X86_SIM_STACK_BYTES - 40) / 8] = bits;
    X86_SIM_L_STACK_VALUES_SAVE(X86_SIM_STACK_BYTES - 40, X86_WIDTH_64,
                               representative, tag);
    __x86_rbp.ptr = X86_SIM_L_STACK_PTR(-40);
    __x86_rbp_tag = X86_SIM_TAG_STACK;
    __x86_cf = 1; __x86_zf = 0; __x86_sf = 1;
    __x86_of = 0; __x86_pf = 1; __x86_af = 0;
    memcpy(before, (const void *)__x86_stack_mem.b, sizeof(before));
    choice = 0;
    draws = 0;
    unsigned dst = mode == 2 ? X86_RBP : mode == 3 ? X86_RSP : X86_R12;
    unsigned src = mode == 0 || mode == 3 ? X86_RSP : X86_RBP;
    X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, dst, src, X86_WIDTH_64,
                            X86_MEM_AUX(X86_REG_NONE, 0), src == X86_RSP ? 8 : 0);
    void *expected = tag == X86_SIM_TAG_STACK ? representative : (void *)bits;
    unsigned expected_tag = tag;
    if (mode == 3) {
        expected = (void *)-16L;
        expected_tag = X86_SIM_TAG_SCALAR;
        memset(before + X86_SIM_STACK_BYTES - 48, 0, 32);
        struct x86_sim_stack_value stale = X86_SIM_L_STACK_VALUES_READ(
            X86_SIM_STACK_BYTES - 40, X86_WIDTH_64);
        if (stale.tag != X86_SIM_TAG_SCALAR || stale.pointer) {
            fprintf(stderr, "released fact: tag=%u pointer=%p\n", stale.tag, stale.pointer);
            return 1;
        }
    }
    if (X86_SIM_L_READ_REG_PTR(dst) != expected || X86_SIM_L_REG_TAG(dst) != expected_tag ||
        draws != (mode == 3 ? 4U : 0U) ||
        memcmp(before, (const void *)__x86_stack_mem.b, sizeof(before)) ||
        __x86_cf != 1 || __x86_zf != 0 || __x86_sf != 1 ||
        __x86_of != 0 || __x86_pf != 1 || __x86_af != 0) {
        fprintf(stderr, "actual ptr=%p tag=%u draws=%u memory_diff=%d; expected ptr=%p tag=%u draws=%u\n",
                X86_SIM_L_READ_REG_PTR(dst), X86_SIM_L_REG_TAG(dst), draws,
                memcmp(before, (const void *)__x86_stack_mem.b, sizeof(before)),
                expected, expected_tag, mode == 3 ? 4U : 0U);
        return 1;
    }
    return 0;
}

static int recovery(unsigned visit)
{
    X86_SIM_ENTRY_RAW((void *)0);
    __x86_r14.ptr = visit ? (void *)0x123456UL : 0;
    __x86_r14_tag = X86_SIM_TAG_SCALAR;
    __x86_r12.ptr = (void *)0x777777UL;
    __x86_r12_tag = X86_SIM_TAG_MAP_VALUE;
    choice = 1;
    draws = 0;
    X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_64,
                            X86_MEM_AUX(X86_REG_NONE, 0), 0);
    return __x86_r12.ptr != 0 || __x86_r12_tag != X86_SIM_TAG_SCALAR || draws != visit;
}

int main(void)
{
    const unsigned tags[] = {X86_SIM_TAG_STACK, X86_SIM_TAG_MAP_VALUE, X86_SIM_TAG_PACKET};
    for (unsigned mode = 0; mode < 4; ++mode)
        for (unsigned i = 0; i < sizeof(tags) / sizeof(tags[0]); ++i)
            if (run(mode, tags[i])) {
                fprintf(stderr, "load writeback mismatch mode=%u tag=%u\n", mode, tags[i]);
                return 1;
            }
    if (recovery(0) || recovery(1)) return 2;
    puts("load writeback: 14 saved-pointer/overlap/RSP/recovery cases pass");
}
