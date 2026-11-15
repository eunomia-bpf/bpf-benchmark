/* Width capture must evaluate once, narrow before resolving the absent code,
 * and retain the byte return type (including unary integer promotion). */
#include "kprog/x86/x86_sim_local_bpf.h"
#include <stdio.h>

static unsigned code, visits;
static unsigned visit(void) { ++visits; return code; }

static int check(unsigned value)
{
    code = value;
    visits = 0;
    unsigned expected = value & 255U;
    if (!expected) expected = 8U;
    unsigned actual = X86_SIM_L_EFFECTIVE_WIDTH(visit());
    if (visits != 1 || actual != expected) return 1;
    visits = 0;
    long long inverted = ~X86_SIM_L_EFFECTIVE_WIDTH(visit());
    if (visits != 1 || inverted != ~(int)expected) return 2;
    return 0;
}

int main(void)
{
    _Static_assert(_Generic(X86_SIM_L_EFFECTIVE_WIDTH(0), unsigned char: 1, default: 0),
                   "effective width must retain its unsigned byte result type");
    for (unsigned i = 0; i < 65536; ++i)
        if (check(i)) { fprintf(stderr, "width capture mismatch: %u\n", i); return 1; }
    if (check(0xffffffffU) || check(0x10000008U)) return 2;
    puts("width capture: 65538 single-evaluation/narrowing/promotion cases pass");
}
