/* A fault precedes transfer/writeback: every GPR/tag, NZCV, SIMD lane and
 * memory byte is compared. The protected address is inaccessible, so a
 * transfer performed before the recovery branch also fails this oracle. */
#define ARM64_SIM_ENABLE_STACK 1
static unsigned fault_visits, choose_fault;
static unsigned long read_outcome(void) { ++fault_visits; return choose_fault; }
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
#undef ARM64_SIM_L_UNSPECIFIED
#define ARM64_SIM_L_UNSPECIFIED() read_outcome()
static void arm64_sim_unsupported_opcode(void) { fputs("architectural fault\n", stderr); exit(1); }
static unsigned long cases;
static void check(unsigned op, unsigned dst, unsigned second, unsigned width,
                  unsigned flags, unsigned via)
{
    ARM64_SIM_L_DECLARE_STATE();
    ARM64_SIM_L_DECLARE_STACK();
    __u8 __a64_sim_abi_kind = ARM64_SIM_ABI_KIND_RAW;
    __u64 before[31];
    unsigned base = dst == 30 ? 29 : 30, i;
    __u32 aux = ARM64_AUX_MEM(ARM64_REG_NONE, ARM64_MOD_NONE, 0, flags);
    unsigned char stack_before[sizeof(__a64_stack.b)];
    for (i = 0; i < 31; ++i) {
        before[i] = 0xfedcba9800000001ULL + i;
        ARM64_SIM_L_WRITE_REG_PTR_TAG(i, (void *)(unsigned long)before[i], ARM64_SIM_TAG_SCALAR);
    }
    ARM64_SIM_L_WRITE_REG_PTR_TAG(base, (void *)1, ARM64_SIM_TAG_ABI);
    before[base] = 1;
    __a64_sp = -32;
    __a64_n = 1; __a64_z = 0; __a64_c = 1; __a64_v = 1;
    for (i = 0; i < 32; ++i) {
        __a64_vectors[i].lo = 0xa5a5ULL + i;
        __a64_vectors[i].hi = 0x5a5aULL + i;
    }
    memset((void *)__a64_stack.b, 0x5c, sizeof(__a64_stack.b));
    memcpy(stack_before, (const void *)__a64_stack.b, sizeof(stack_before));
    fault_visits = 0;
    choose_fault = 1;
    if (op == ARM64_OP_LDP) {
        if (via) ARM64_SIM_RUN_KNOWN_OP3(ARM64_OP_LDP, dst, second, base, ARM64_REG_NONE, width, aux, 16);
        else ARM64_SIM_L_EXEC(op, dst, second, base, ARM64_REG_NONE, width, aux, 16);
    } else if (op == ARM64_OP_LDADD || op == ARM64_OP_LDSET || op == ARM64_OP_LDCLR) {
        if (via) {
            if (op == ARM64_OP_LDADD) ARM64_SIM_RUN_KNOWN_OP3(ARM64_OP_LDADD, dst, second, base, ARM64_REG_NONE, width, 3, 0);
            if (op == ARM64_OP_LDSET) ARM64_SIM_RUN_KNOWN_OP3(ARM64_OP_LDSET, dst, second, base, ARM64_REG_NONE, width, 3, 0);
            if (op == ARM64_OP_LDCLR) ARM64_SIM_RUN_KNOWN_OP3(ARM64_OP_LDCLR, dst, second, base, ARM64_REG_NONE, width, 3, 0);
        } else ARM64_SIM_L_EXEC(op, dst, second, base, ARM64_REG_NONE, width, 3, 0);
    } else {
        if (via) {
            if (op == ARM64_OP_LOAD) ARM64_SIM_RUN_KNOWN_OP3(ARM64_OP_LOAD, dst, base, ARM64_REG_NONE, ARM64_REG_NONE, width, aux, 16);
            if (op == ARM64_OP_LDRSB) ARM64_SIM_RUN_KNOWN_OP3(ARM64_OP_LDRSB, dst, base, ARM64_REG_NONE, ARM64_REG_NONE, width, aux, 16);
            if (op == ARM64_OP_LDRSH) ARM64_SIM_RUN_KNOWN_OP3(ARM64_OP_LDRSH, dst, base, ARM64_REG_NONE, ARM64_REG_NONE, width, aux, 16);
            if (op == ARM64_OP_LDRSW) ARM64_SIM_RUN_KNOWN_OP3(ARM64_OP_LDRSW, dst, base, ARM64_REG_NONE, ARM64_REG_NONE, width, aux, 16);
        } else ARM64_SIM_L_EXEC(op, dst, base, ARM64_REG_NONE, ARM64_REG_NONE, width, aux, 16);
    }
    for (i = 0; i < 31; ++i) {
        int cleared = i == dst || (op == ARM64_OP_LDP && i == second);
        __u64 expected = cleared ? 0 : before[i];
        unsigned tag = cleared ? ARM64_SIM_TAG_SCALAR : i == base ? ARM64_SIM_TAG_ABI : ARM64_SIM_TAG_SCALAR;
        if (ARM64_SIM_L_READ_REG_RAW(i) != expected || ARM64_SIM_L_REG_TAG(i) != tag) { fprintf(stderr,"op%u dst%u second%u width%u flags%u via%u reg%u actual%llx expected%llx tag%u/%u\n", op,dst,second,width,flags,via,i,ARM64_SIM_L_READ_REG_RAW(i),expected,ARM64_SIM_L_REG_TAG(i),tag); exit(1); }
    }
    if (fault_visits != 1 || __a64_sp != -32 || __a64_n != 1 || __a64_z || __a64_c != 1 || __a64_v != 1 ||
        memcmp(stack_before, (const void *)__a64_stack.b, sizeof(stack_before))) { fputs("frame mismatch\n",stderr); exit(1); }
    for (i = 0; i < 32; ++i)
        if (__a64_vectors[i].lo != 0xa5a5ULL+i || __a64_vectors[i].hi != 0x5a5aULL+i) { fputs("SIMD frame mismatch\n",stderr); exit(1); }
    choose_fault = 0;
    ++cases;
}
int main(void)
{
    const unsigned ops[] = {ARM64_OP_LOAD, ARM64_OP_LDRSB, ARM64_OP_LDRSH, ARM64_OP_LDRSW,
        ARM64_OP_LDP, ARM64_OP_LDADD, ARM64_OP_LDSET, ARM64_OP_LDCLR};
    const unsigned flags[] = {0, ARM64_MEM_PRE, ARM64_MEM_POST};
    for (unsigned op = 0; op < sizeof(ops)/sizeof(ops[0]); ++op)
        for (unsigned dst = 0; dst <= 31; ++dst)
            for (unsigned width = 1; width <= 8; width *= 2)
                for (unsigned f = 0; f < 3; ++f)
                    for (unsigned via = 0; via < 2; ++via)
                        check(ops[op], dst == 31 ? ARM64_XZR : dst, (dst+1)%30, width, flags[f], via);
    printf("arm64 protected-read recovery host cross-check: OK (%lu cases)\n", cases);
    return 0;
}
