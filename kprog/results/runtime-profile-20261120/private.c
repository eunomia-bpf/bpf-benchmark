/* Private stack byte writes must preserve every untouched byte and width. */
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#define X86_SIM_STACK_BYTES 64U
#include "../../x86/x86_sim_local_bpf.h"

static uint64_t check(uint64_t seed, int off, unsigned width)
{
    X86_SIM_L_DECLARE_STACK();
    unsigned char expected[64];
    for (unsigned i=0; i<8; ++i) {
        __x86_stack_mem.q[i]=seed;
        memcpy(expected+i*8, &seed, 8);
    }
    uint64_t value=~seed;
    X86_SIM_L_STACK_WRITE_OWNED(off, width, value);
    memcpy(expected+64+off, &value, width);
    for (unsigned i=0; i<64; ++i) assert(__x86_stack_mem.b[i]==expected[i]);
    uint64_t result=X86_SIM_L_STACK_READ_OWNED(off, width);
    uint64_t reference=0;
    memcpy(&reference, expected+64+off, width);
    assert(result==reference);
    return result;
}

int main(void)
{
    uint64_t seeds[]={0,1,0xffffffffUL,0x100000000UL,0x8000000000000000UL,~0UL};
    unsigned cases=0;
    for (unsigned s=0; s<6; ++s)
        for (int off=-64; off<=-8; ++off)
            for (unsigned width=1; width<=8; width*=2) {
                (void)check(seeds[s],off,width);
                ++cases;
            }
    printf("%u private arena byte/width/neighbor cases passed\n",cases);
}
