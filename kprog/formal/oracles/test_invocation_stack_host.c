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
#ifndef TEST_ARM64
#undef X86_SIM_L_ARCHITECTURAL_FAULT
#define X86_SIM_L_ARCHITECTURAL_FAULT() return 99
static unsigned rsp_recovery(void) {
    ENTRY();
    __x86_rax.ptr=0;
    X86_SIM_L_READ_RECOVERY(X86_RAX,X86_RSP);
    return 0;
}
#endif
#define REQUIRE(C) do { if (!(C)) { printf("stack contract failure line %d\n",__LINE__); return 1; } } while(0)
int main(void) {
#ifndef TEST_ARM64
    REQUIRE(rsp_recovery()==99);
#endif
    ENTRY();
    SET_SP(-32);
    WRITE(-24,8,0x1122334455667788ULL);
    REQUIRE(READ(-24,8)==0x1122334455667788ULL);
    SET_SP(-16); SET_SP(-32);
    REQUIRE(READ(-24,8)==0x5a5a5a5a5a5a5a5aULL);
    SET_SP(-16);
    BYTE(-24)=0x91;
    WRITE(-24,8,3);
    REQUIRE(BYTE(-24)==0x5a);
    unsigned long before=draws;
    REQUIRE(READ(-24,8)==0x5a5a5a5a5a5a5a5aULL && draws==before+1);
    WRITE(-20,8,0x0807060504030201ULL);
    REQUIRE(READ(-16,4)==0x08070605ULL);
#ifdef TEST_ARM64
    __a64_x3.ptr=(void *)-24; __a64_x3_tag=ARM64_SIM_TAG_STACK;
    __a64_x2.x=1;
    BYTE(-24)=3;
    ARM64_SIM_L_ATOMIC_RMW(__atomic_fetch_add,0,ARM64_X1,ARM64_X2,ARM64_X3,ARM64_WIDTH_8,0);
    REQUIRE(__a64_x1.x==0x5a && BYTE(-24)==0x5a);
    __a64_x0.ptr=(void *)-16; __a64_x0_tag=ARM64_SIM_TAG_STACK;
    __a64_x1.ptr=(void *)-24; __a64_x1_tag=ARM64_SIM_TAG_STACK;
    __a64_x2.x=1;
    ARM64_SIM_LIBC_MEMCPY();
    REQUIRE(BYTE(-16)==0x5a);
    ARM64_SIM_L_STACK_WRITE_TAG(-24,8,0,ARM64_SIM_TAG_RETURN);
    REQUIRE(ARM64_SIM_L_STACK_READ_TAG(-24,8)==ARM64_SIM_TAG_SCALAR);
#else
    X86_SIM_L_STACK_VALUES_SAVE(X86_SIM_L_STACK_INDEX(-24),8,(void*)1,X86_SIM_TAG_STACK);
    REQUIRE(X86_SIM_L_STACK_VALUES_READ(X86_SIM_L_STACK_INDEX(-24),8).tag==X86_SIM_TAG_SCALAR);
    before=draws;
    REQUIRE(X86_SIM_L_LOAD_ADDR_TAGGED(X86_SIM_L_STACK_PTR(-24),8,X86_SIM_TAG_STACK)==0x5a5a5a5a5a5a5a5aULL && draws==before+1);
    X86_SIM_L_STORE_ADDR_TAGGED(X86_SIM_L_STACK_PTR(-24),8,9,X86_SIM_TAG_STACK);
    REQUIRE(BYTE(-24)==0x5a);
    /* Alias writes preserve live bytes across SP for every width/alignment. */
    const unsigned widths[]={1,2,4,8};
    for(unsigned wi=0;wi<4;++wi) for(long off=-32;off+(long)widths[wi]<=0;++off)
      for(long sp=-32;sp<=0;++sp) {
        __x86_rsp.ptr=(void *)sp;
        for(long byte=-64;byte<0;++byte) BYTE(byte)=0xc3;
        before=draws;
        X86_SIM_L_STORE_ADDR_TAGGED(X86_SIM_L_STACK_PTR(off),widths[wi],
            0x8877665544332211ULL,X86_SIM_TAG_STACK);
        unsigned lost=0;
        for(long byte=-64;byte<0;++byte) {
          unsigned expected=0xc3;
          if(byte>=off && byte<off+(long)widths[wi]) {
            if(byte<sp) { expected=0x5a; ++lost; }
            else expected=(0x8877665544332211ULL>>((byte-off)*8))&0xff;
          }
          REQUIRE(BYTE(byte)==expected);
        }
        REQUIRE(draws==before+lost);
      }
    __x86_rsp.ptr=(void *)-16;
#endif
    /* A helper output below SP loses its bytes before later allocation. */
    BYTE(-24)=0x12;
#ifdef TEST_ARM64
    ARM64_SIM_L_HELPER_CLOBBERS();
#else
    X86_SIM_L_HELPER_CLOBBERS();
#endif
    SET_SP(-32);
    REQUIRE(READ(-24,8)==0x5a5a5a5a5a5a5a5aULL);
    puts("stack lifetime PASS: allocated, released, below-SP, boundary and provenance cases");
    return 0;
}
