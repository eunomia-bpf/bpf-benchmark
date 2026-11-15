/* Catch lost/over-cleared pointer facts and extra free-byte draws in stores
 * through a STACK-tagged register other than RSP. Expected bytes and facts
 * use ordinary interval arithmetic, independently of the store macros. */
#define X86_SIM_ENABLE_STACK 1
#include "kprog/x86/x86_sim_local_bpf.h"
#include <stdio.h>
#include <string.h>

static unsigned long choice;
static unsigned draws;
static const unsigned long origin = 0x12340000UL;
unsigned long native_lab_entry_input(unsigned kind)
{
    if (kind == NATIVE_LAB_INPUT_SP) return origin;
    if (kind == NATIVE_LAB_INPUT_UNSPECIFIED) { ++draws; return choice; }
    abort();
}

static int check(long off, unsigned width, unsigned tag, unsigned shift,
                 unsigned index, unsigned disp, unsigned immediate,
                 unsigned nonzero)
{
    X86_SIM_ENTRY_RAW((void *)0);
    __x86_rsp.ptr = (void *)-48L;
    unsigned char expected[X86_SIM_STACK_BYTES];
    unsigned char tags[X86_SIM_STACK_BYTES / 8];
    void *pointers[X86_SIM_STACK_BYTES / 8];
    for (unsigned i = 0; i < X86_SIM_STACK_BYTES; ++i)
        expected[i] = __x86_stack_mem.b[i] = (unsigned char)(0x80U + i);
    for (unsigned i = 0; i < X86_SIM_STACK_BYTES / 8; ++i) {
        tags[i] = i >= 2 ? X86_SIM_TAG_STACK : X86_SIM_TAG_SCALAR;
        pointers[i] = i >= 2 ? X86_SIM_L_STACK_PTR(-8L * (i + 1)) : 0;
        X86_SIM_L_SV_TAG(i) = tags[i]; X86_SIM_L_SV_PTR(i) = pointers[i];
    }
    void *source = tag == X86_SIM_TAG_STACK ? X86_SIM_L_STACK_PTR(-16) :
        (void *)0x1234567887654321UL;
    __x86_r12.ptr = source; __x86_r12_tag = tag;
    __x86_rdx.ptr = (void *)(unsigned long)index;
    __x86_rdx_tag = X86_SIM_TAG_SCALAR;
    __x86_rbp.ptr = X86_SIM_L_STACK_PTR(off - (long)disp - 2L * index);
    __x86_rbp_tag = X86_SIM_TAG_STACK;
    __x86_cf = 1; __x86_zf = 0; __x86_sf = 1;
    __x86_of = 0; __x86_pf = 1; __x86_af = 0;
    choice = nonzero ? 0xa7a7a7a7a7a7a7a7UL : 0; draws = 0;
    unsigned op = immediate ? X86_OP_MOV_STORE_IMM : X86_OP_MOV_STORE_REG;
    unsigned aux = X86_MEM_AUX(X86_RDX, 1) | (shift << 24);
    unsigned long long imm = immediate ? ((unsigned long long)disp << 32) | 0x87654321U : disp;
    X86_SIM_L_EXEC_STORE(op, X86_RBP, X86_R12, width, aux, imm);

    unsigned at = X86_SIM_STACK_BYTES + off, expected_draws = 0;
    unsigned long long value = immediate ? (width == 8 ? 0xffffffff87654321ULL : 0x87654321ULL) :
        (tag == X86_SIM_TAG_STACK ? origin - 16 : (unsigned long long)(unsigned long)source) >> shift;
    for (unsigned lane = 0; lane < width; ++lane) {
        expected[at + lane] = (unsigned char)(value >> (8 * lane));
        if (off + (long)lane < -48) {
            expected[at + lane] = (unsigned char)choice; ++expected_draws;
        }
    }
    for (unsigned i = 0; i < X86_SIM_STACK_BYTES / 8; ++i) {
        if (i * 8 < at + width && at < i * 8 + 8) { tags[i] = 0; pointers[i] = 0; }
        if (!immediate && width == 8 && !shift && off >= -48 && at == i * 8 && tag) {
            tags[i] = tag; pointers[i] = tag == X86_SIM_TAG_STACK ? source : 0;
        }
        if (X86_SIM_L_SV_TAG(i) != tags[i] || X86_SIM_L_SV_PTR(i) != pointers[i]) {
            fprintf(stderr, "fact mismatch slot=%u off=%ld width=%u tag=%u shift=%u imm=%u\n",
                    i, off, width, tag, shift, immediate); return 1;
        }
    }
    if (draws != expected_draws || memcmp(expected, (const void *)__x86_stack_mem.b, sizeof(expected)) ||
        __x86_cf != 1 || __x86_zf || __x86_sf != 1 || __x86_of || __x86_pf != 1 || __x86_af) {
        fprintf(stderr, "bytes/flags/draw mismatch off=%ld width=%u tag=%u shift=%u imm=%u draws=%u/%u\n",
                off, width, tag, shift, immediate, draws, expected_draws); return 1;
    }
    return 0;
}

int main(void)
{
    const long offsets[] = {-56, -49, -48, -47, -40, -39, -33, -32, -25, -24, -8};
    const unsigned widths[] = {1, 2, 4, 8}, tags[] = {0, X86_SIM_TAG_STACK, X86_SIM_TAG_MAP_VALUE};
    unsigned count = 0;
    for (unsigned a = 0; a < 11; ++a) for (unsigned w = 0; w < 4; ++w)
    for (unsigned t = 0; t < 3; ++t) for (unsigned s = 0; s < 2; ++s)
    for (unsigned i = 0; i < 2; ++i) for (unsigned d = 0; d < 2; ++d)
    for (unsigned m = 0; m < 2; ++m) for (unsigned n = 0; n < 2; ++n) {
        if (check(offsets[a], widths[w], tags[t], s * 8, i * 3, d * 5, m, n)) return 1;
        ++count;
    }
    printf("store alias: %u complete arena/facts/flags/free-input cases pass\n", count);
}
