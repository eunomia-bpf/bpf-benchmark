/* Native stack lifetime: allocated cells persist, released/below-SP cells draw fresh input. */
#include <stdio.h>
static unsigned long draws;
static unsigned long fresh(void) { ++draws; return 0x5a5a5a5a5a5a5a5aUL; }
#ifdef TEST_ARM64
#define ARM64_SIM_ENABLE_STACK 1
#include "kprog/arm64/arm64_sim_local_bpf.h"
#undef ARM64_SIM_L_UNSPECIFIED
#define ARM64_SIM_L_UNSPECIFIED() fresh()
#define ENTRY() ARM64_SIM_ENTRY_RAW((void *)0)
#define SET_SP(V) ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_SP,(__u64)(V),8)
#define WRITE(O,W,V) ARM64_SIM_L_STACK_WRITE((O),(W),(V))
#define READ(O,W) ARM64_SIM_L_STACK_READ((O),(W))
#define BYTE(I) __a64_stack.b[ARM64_SIM_STACK_BIAS+(I)]
#else
#define X86_SIM_ENABLE_STACK 1
#include "kprog/x86/x86_sim_local_bpf.h"
#undef X86_SIM_L_UNSPECIFIED
#define X86_SIM_L_UNSPECIFIED() fresh()
#define ENTRY() X86_SIM_ENTRY_RAW((void *)0)
#define SET_SP(V) X86_SIM_L_WRITE_REG_WIDTH(X86_RSP,(__u64)(V),8)
#define WRITE(O,W,V) X86_SIM_L_STACK_WRITE((O),(W),(V))
#define READ(O,W) X86_SIM_L_STACK_READ((O),(W))
#define BYTE(I) __x86_stack_mem.b[X86_SIM_STACK_BYTES+(I)]
#endif
unsigned long native_lab_entry_input(unsigned int kind) { return 0; }
#define REQUIRE(C) do { if (!(C)) { printf("stack contract failure line %d\n",__LINE__); return 1; } } while(0)
int main(void) {
    ENTRY();
    SET_SP(-32);
    WRITE(-24,8,0x1122334455667788ULL);
    REQUIRE(READ(-24,8)==0x1122334455667788ULL);
    SET_SP(-16); SET_SP(-32);
    REQUIRE(READ(-24,8)==0x5a5a5a5a5a5a5a5aULL);
    SET_SP(-16);
    BYTE(-24)=0x91;
    WRITE(-24,8,3);
    REQUIRE(BYTE(-24)==0x91);
    unsigned long before=draws;
    REQUIRE(READ(-24,8)==0x5a5a5a5a5a5a5a5aULL && draws==before+1);
    WRITE(-20,8,0x0807060504030201ULL);
    REQUIRE(READ(-16,4)==0x08070605ULL);
#ifdef TEST_ARM64
    ARM64_SIM_L_STACK_WRITE_TAG(-24,8,0,ARM64_SIM_TAG_RETURN);
    REQUIRE(ARM64_SIM_L_STACK_READ_TAG(-24,8)==ARM64_SIM_TAG_SCALAR);
#else
    X86_SIM_L_STACK_VALUES_SAVE(X86_SIM_L_STACK_INDEX(-24),8,(void*)1,X86_SIM_TAG_STACK);
    REQUIRE(X86_SIM_L_STACK_VALUES_READ(X86_SIM_L_STACK_INDEX(-24),8).tag==X86_SIM_TAG_SCALAR);
    before=draws;
    REQUIRE(X86_SIM_L_LOAD_ADDR_TAGGED(X86_SIM_L_STACK_PTR(-24),8,X86_SIM_TAG_STACK)==0x5a5a5a5a5a5a5a5aULL && draws==before+1);
    X86_SIM_L_STORE_ADDR_TAGGED(X86_SIM_L_STACK_PTR(-24),8,9,X86_SIM_TAG_STACK);
    REQUIRE(BYTE(-24)==0x91);
#endif
    puts("stack lifetime PASS: allocated, released, below-SP, boundary and provenance cases");
    return 0;
}
