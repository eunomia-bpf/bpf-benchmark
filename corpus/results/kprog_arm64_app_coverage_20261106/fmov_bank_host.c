/* A nonzero FMOV selector must neither alias V0 nor preserve stale upper bits. */
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;
typedef signed long long __s64;
typedef signed int __s32;
#define __always_inline inline
#include "../../../kprog/arm64/arm64_sim_local_bpf.h"
#include <stdio.h>
#include <stdlib.h>

static void arm64_sim_unsupported_opcode(void) { abort(); }

static int check(unsigned selected, unsigned direction, __u64 source)
{
    ARM64_SIM_L_DECLARE_STATE();
    ARM64_SIM_L_DECLARE_STACK();
    __u8 __a64_sim_abi_kind = KPROG_ABI_KIND_XDP;
    (void)__a64_sim_abi_kind; (void)__a64_lr;
    for (unsigned i=0;i<32;i++) {
        __a64_vectors[i].lo=0xfedcba9876543210ULL+i;
        __a64_vectors[i].hi=0x0123456789abcdefULL-i;
    }
    __a64_x1.x=source;
    __a64_x2.x=0x5555; __a64_x2_tag=ARM64_SIM_TAG_STACK;
    __a64_n=1; __a64_z=0; __a64_c=1; __a64_v=1;
    unsigned width=direction<2 ? ARM64_WIDTH_64 : ARM64_WIDTH_32;
    ARM64_SIM_RUN_KNOWN_OP3(ARM64_OP_FMOV,ARM64_X2,ARM64_X1,selected,ARM64_REG_NONE,width,direction,0);
    int vector_write=!(direction&1);
    __u64 value=vector_write ? source : 0xfedcba9876543210ULL+selected;
    if (direction>=2) value=(__u32)value;
    for (unsigned i=0;i<32;i++) {
        __u64 low=vector_write && i==selected ? value : 0xfedcba9876543210ULL+i;
        __u64 high=vector_write && i==selected ? 0 : 0x0123456789abcdefULL-i;
        if (__a64_vectors[i].lo!=low || __a64_vectors[i].hi!=high) return 1;
    }
    if (__a64_x2.x!=(vector_write ? 0x5555 : value) ||
        __a64_x2_tag!=(vector_write ? ARM64_SIM_TAG_STACK : ARM64_SIM_TAG_SCALAR) ||
        __a64_x1.x!=source || __a64_n!=1 || __a64_z || __a64_c!=1 || __a64_v!=1)
        return 1;
    return 0;
}

int main(void)
{
    const __u64 inputs[]={0,1,0xffffffffULL,0x100000000ULL,0x8000000000000000ULL,
        0xffffffffffffffffULL,0x7ff8000000000001ULL,0xfff8000080000001ULL};
    unsigned count=0;
    for (unsigned reg=0;reg<32;reg++) for (unsigned dir=0;dir<4;dir++)
        for (unsigned i=0;i<sizeof(inputs)/sizeof(inputs[0]);i++) {
            if (check(reg,dir,inputs[i])) {
                fprintf(stderr,"FMOV bank mismatch: vector=%u direction=%u input=%u\n",reg,dir,i);
                return 1;
            }
            count++;
        }
    printf("%u full-bank FMOV value/state/provenance checks pass\n",count);
    return 0;
}
