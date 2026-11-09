/* Recovery precedes copy, vector transfer and writeback. */
#define ARM64_SIM_ENABLE_STACK 1
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;
typedef signed long long __s64;
typedef signed int __s32;
#define __always_inline inline
#include "../arm64/arm64_sim_local_bpf.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <setjmp.h>
unsigned long native_lab_entry_input(unsigned int kind) { (void)kind; return 0; }
static unsigned draw, visits, faults, failures, cases;
static jmp_buf fault_return;
static unsigned long outcome(void) { ++visits; return draw; }
#undef ARM64_SIM_L_UNSPECIFIED
#define ARM64_SIM_L_UNSPECIFIED() outcome()
void arm64_sim_unsupported_opcode(void) { ++faults; longjmp(fault_return, 1); }
#define CHECK(TEST, NAME) do { ++cases; if (!(TEST)) { ++failures; fprintf(stderr, "%s\n", NAME); } } while (0)
static void zero_base(void)
{
    ARM64_SIM_L_DECLARE_STATE(); ARM64_SIM_L_DECLARE_STACK();
    __u8 __a64_sim_abi_kind = ARM64_SIM_ABI_KIND_RAW;
    ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X1, 0, ARM64_WIDTH_64);
    visits=0; draw=0;
    int recovered=ARM64_SIM_L_READ_FAULT(ARM64_X1);
    CHECK(recovered, "zero SCALAR base selects recovery with success draw");
    if (recovered) {
        ARM64_SIM_RUN_KNOWN_OP3(ARM64_OP_LOAD, ARM64_X2, ARM64_X1, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_MEM(ARM64_REG_NONE,ARM64_MOD_NONE,0,ARM64_MEM_POST),8);
        CHECK(ARM64_SIM_L_READ_REG_RAW(ARM64_X2)==0 && ARM64_SIM_L_READ_REG_RAW(ARM64_X1)==0,"zero recovery preserves base and clears destination");
    }
}
static void copy_source(unsigned tag, unsigned length)
{
    ARM64_SIM_L_DECLARE_STATE(); ARM64_SIM_L_DECLARE_STACK();
    __u8 __a64_sim_abi_kind = ARM64_SIM_ABI_KIND_RAW;
    unsigned char src[8]={1,2,3,4,5,6,7,8};
    static unsigned char dst[8];
    memset(dst,0x5a,sizeof(dst));
    ARM64_SIM_L_WRITE_REG_PTR_TAG(ARM64_X0,dst,ARM64_SIM_TAG_ABI);
    ARM64_SIM_L_WRITE_REG_PTR_TAG(ARM64_X1,src,tag);
    ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X2,length,ARM64_WIDTH_64);
    faults=0; draw=0;
    if (setjmp(fault_return)==0) ARM64_SIM_LIBC_MEMCPY();
    if (tag==ARM64_SIM_TAG_SCALAR) {
        CHECK(faults==1,"SCALAR memcpy source selects architectural fault");
        for (unsigned i=0;i<sizeof(dst);++i) CHECK(dst[i]==0x5a,"copy fault precedes memory effects");
    } else {
        CHECK(faults==0,"typed memcpy source selects transfer");
        CHECK(memcmp(dst,src,length)==0,"typed memcpy transfers source bytes");
    }
}
static void vector_read(unsigned op, unsigned flags, unsigned via, unsigned selected)
{
    ARM64_SIM_L_DECLARE_STATE(); ARM64_SIM_L_DECLARE_STACK();
    __u8 __a64_sim_abi_kind = ARM64_SIM_ABI_KIND_RAW;
    __u64 source[8]={11,22,33,44,55,66,77,88};
    __u64 before[31]; __u8 tags[31];
    for (unsigned i=0;i<31;++i) ARM64_SIM_L_WRITE_REG_WIDTH(i,0x12340000ULL+i,ARM64_WIDTH_64);
    ARM64_SIM_L_WRITE_REG_PTR_TAG(ARM64_X1,&source[2],ARM64_SIM_TAG_ABI);
    for (unsigned i=0;i<31;++i) { before[i]=ARM64_SIM_L_READ_REG_RAW(i); tags[i]=ARM64_SIM_L_REG_TAG(i); }
    for (unsigned i=0;i<32;++i) { __a64_vectors[i].lo=0x11110000+i;__a64_vectors[i].hi=0x22220000+i; }
    __a64_n=1;__a64_z=0;__a64_c=1;__a64_v=1;__a64_sp=-32;
    __u32 aux=ARM64_AUX_MEM(ARM64_REG_NONE,ARM64_MOD_NONE,0,flags);
    visits=0;draw=selected;
    if (via) {
        if (op==ARM64_OP_LOAD_D0) ARM64_SIM_RUN_KNOWN_OP3(ARM64_OP_LOAD_D0,ARM64_REG_NONE,ARM64_X1,ARM64_REG_NONE,ARM64_REG_NONE,ARM64_WIDTH_64,aux,16);
        else ARM64_SIM_RUN_KNOWN_OP3(ARM64_OP_LOAD_Q0,ARM64_REG_NONE,ARM64_X1,ARM64_REG_NONE,ARM64_REG_NONE,ARM64_WIDTH_64,aux,16);
    } else ARM64_SIM_L_DQ_MEM_STEP(op,ARM64_X1,ARM64_REG_NONE,aux,16);
    CHECK(visits==1,"vector read consumes one recovery outcome");
    for (unsigned i=0;i<31;++i) {
        __u64 expected=before[i];
        if (!selected && i==ARM64_X1 && flags) expected+=16;
        CHECK(ARM64_SIM_L_READ_REG_RAW(i)==expected && ARM64_SIM_L_REG_TAG(i)==tags[i],"vector read retains GPR frame with selected writeback");
    }
    unsigned first=flags==ARM64_MEM_POST?2:4;
    for (unsigned i=0;i<32;++i) {
        __u64 lo=0x11110000+i,hi=0x22220000+i;
        if (!selected && i==0) { lo=source[first];hi=op==ARM64_OP_LOAD_D0?0:source[first+1]; }
        CHECK(__a64_vectors[i].lo==lo && __a64_vectors[i].hi==hi,"vector read preserves fault SIMD frame and transfers success data");
    }
    CHECK(__a64_n==1 && __a64_z==0 && __a64_c==1 && __a64_v==1 && __a64_sp==-32,"vector recovery preserves flags and SP");
    CHECK(source[0]==11 && source[7]==88,"vector recovery retains memory");
}
int main(void)
{
    zero_base();
    for(unsigned n=0;n<=8;n+=8) { copy_source(ARM64_SIM_TAG_SCALAR,n);copy_source(ARM64_SIM_TAG_ABI,n); }
    const unsigned ops[]={ARM64_OP_LOAD_D0,ARM64_OP_LOAD_Q0};
    for(unsigned oi=0;oi<2;++oi)
      for(unsigned mode=0;mode<3;++mode)
        for(unsigned via=0;via<2;++via)
          for(unsigned selected=0;selected<2;++selected)
            vector_read(ops[oi],mode==0?0:mode==1?ARM64_MEM_PRE:ARM64_MEM_POST,via,selected);
    printf("arm64 read follow-up host: %s (%u checks; %u discrepancies)\n",failures?"FAIL":"OK",cases,failures);
    return failures?1:0;
}
