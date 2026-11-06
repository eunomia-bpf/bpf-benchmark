/* Regression: compose CMP/B.GT without losing overflow, narrowing or flags. */
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

void arm64_sim_unsupported_opcode(void) { abort(); }
struct observation { __u64 lhs, rhs; unsigned flags, taken; };

static struct observation run(unsigned fast, unsigned immediate, unsigned width,
                              __u64 lhs, __u64 rhs, unsigned backwards)
{
    struct xdp_md ctx = {0};
    ARM64_SIM_ENTRY_XDP(&ctx);
    ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X3, lhs, ARM64_WIDTH_64);
    ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X4, rhs, ARM64_WIDTH_64);
    unsigned op = immediate ? ARM64_OP_CMP_IMM : ARM64_OP_CMP_REG;
    unsigned taken = 0;
    if (fast) {
        ARM64_SIM_A64_CMP_GT(op, ARM64_X3, ARM64_X4, width,
                            ARM64_AUX_ALU(0, ARM64_MOD_NONE, 0), rhs, yes);
    } else {
        ARM64_SIM_RUN_OP3(op, ARM64_X3, ARM64_X4, ARM64_REG_NONE, ARM64_REG_NONE,
                         width, ARM64_AUX_ALU(0, ARM64_MOD_NONE, 0), rhs);
        ARM64_SIM_A64_JCC(ARM64_COND_GT, 0x10, backwards ? 0 : 0x20, yes);
    }
    goto done;
yes:
    taken = 1;
done:
    (void)__a64_sim_skb_ctx; (void)__a64_sim_abi_kind;
    (void)__a64_lr; (void)__a64_v0; (void)__a64_v0_hi;
    (void)&__a64_stack; (void)__a64_stack_tag[0];
    return (struct observation){__a64_x3.x, __a64_x4.x,
        __a64_n | (__a64_z<<1) | (__a64_c<<2) | (__a64_v<<3), taken};
}

int main(void)
{
    const __u64 edges[] = {0, 1, 0x7fffffff, 0x80000000, 0xffffffff,
        0x100000000, 0x7fffffffffffffffULL, 0x8000000000000000ULL, ~0ULL};
    __u64 random = 0x6a09e667f3bcc909ULL;
    unsigned cases = 0;
    for (unsigned width=4; width<=8; width+=4)
      for (unsigned immediate=0; immediate<2; immediate++)
       for (unsigned backwards=0; backwards<2; backwards++)
        for (unsigned index=0; index<1081; index++) {
            random ^= random<<13; random ^= random>>7; random ^= random<<17;
            __u64 lhs = index<81 ? edges[index/9] : random;
            __u64 rhs = index<81 ? edges[index%9] : ~random*0x9e3779b97f4a7c15ULL;
            struct observation old = run(0, immediate, width, lhs, rhs, backwards);
            struct observation fused = run(1, immediate, width, lhs, rhs, backwards);
            if (old.lhs!=fused.lhs || old.rhs!=fused.rhs ||
                old.flags!=fused.flags || old.taken!=fused.taken) {
                printf("CMP/GT mismatch width%u lhs%llx rhs%llx\n", width, lhs, rhs);
                return 1;
            }
            cases++;
        }
    printf("arm64 CMP/GT composition: %u cases pass\n", cases);
    return 0;
}
