/* Compile the production handler with arbitrary incoming architectural values.
 * This is a block-checking fixture, not an application entry/ABI substitute. */
#include "../x86/x86_sim_local_bpf.h"

#define CMOV_BLOCK(BITS, WIDTH)                                             \
__attribute__((section("tv/cmov" #BITS), used))                             \
__u64 tv_cmov##BITS(__u64 old, __u64 source, __u64 flags)                    \
{                                                                          \
    X86_SIM_L_DECLARE_STATE();                                              \
    X86_SIM_L_DECLARE_STACK();                                              \
    struct __sk_buff *__x86_sim_skb_ctx = 0;                                 \
    __u8 __x86_sim_abi_kind = 0;                                             \
    __x86_rax.ptr = (void *)(long)old;                                       \
    __x86_rdx.ptr = (void *)(long)source;                                    \
    __x86_zf = (flags >> 6) & 1;                                            \
    X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RDX, WIDTH, X86_CC_E);                  \
    return X86_SIM_L_READ_REG(X86_RAX);                                     \
}

CMOV_BLOCK(16, X86_WIDTH_16)
CMOV_BLOCK(32, X86_WIDTH_32)
CMOV_BLOCK(64, X86_WIDTH_64)

#define CMOV_CONDITION(NAME, WIDTH, CC)                                             \
__attribute__((section("tv/cmov/" #NAME), used))                             \
__u64 NAME(__u64 old, __u64 source, __u64 flags)                    \
{                                                                          \
    X86_SIM_L_DECLARE_STATE();                                              \
    X86_SIM_L_DECLARE_STACK();                                              \
    struct __sk_buff *__x86_sim_skb_ctx = 0;                                 \
    __u8 __x86_sim_abi_kind = 0;                                             \
    __x86_rax.ptr = (void *)(long)old;                                       \
    __x86_rdx.ptr = (void *)(long)source;                                    \
    __x86_cf = flags & 1;                                                 \
    __x86_pf = (flags >> 2) & 1;                                          \
    __x86_sf = (flags >> 7) & 1;                                          \
    __x86_of = (flags >> 11) & 1;                                         \
    __x86_zf = (flags >> 6) & 1;                                            \
    X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RDX, WIDTH, CC);                  \
    return X86_SIM_L_READ_REG(X86_RAX);                                     \
}

CMOV_CONDITION(tv_cmov16_c0, X86_WIDTH_16, 0)
CMOV_CONDITION(tv_cmov16_c1, X86_WIDTH_16, 1)
CMOV_CONDITION(tv_cmov16_c2, X86_WIDTH_16, 2)
CMOV_CONDITION(tv_cmov16_c3, X86_WIDTH_16, 3)
CMOV_CONDITION(tv_cmov16_c4, X86_WIDTH_16, 4)
CMOV_CONDITION(tv_cmov16_c5, X86_WIDTH_16, 5)
CMOV_CONDITION(tv_cmov16_c6, X86_WIDTH_16, 6)
CMOV_CONDITION(tv_cmov16_c7, X86_WIDTH_16, 7)
CMOV_CONDITION(tv_cmov16_c8, X86_WIDTH_16, 8)
CMOV_CONDITION(tv_cmov16_c9, X86_WIDTH_16, 9)
CMOV_CONDITION(tv_cmov16_c10, X86_WIDTH_16, 10)
CMOV_CONDITION(tv_cmov16_c11, X86_WIDTH_16, 11)
CMOV_CONDITION(tv_cmov16_c12, X86_WIDTH_16, 12)
CMOV_CONDITION(tv_cmov16_c13, X86_WIDTH_16, 13)
CMOV_CONDITION(tv_cmov16_c14, X86_WIDTH_16, 14)
CMOV_CONDITION(tv_cmov16_c15, X86_WIDTH_16, 15)
CMOV_CONDITION(tv_cmov32_c0, X86_WIDTH_32, 0)
CMOV_CONDITION(tv_cmov32_c1, X86_WIDTH_32, 1)
CMOV_CONDITION(tv_cmov32_c2, X86_WIDTH_32, 2)
CMOV_CONDITION(tv_cmov32_c3, X86_WIDTH_32, 3)
CMOV_CONDITION(tv_cmov32_c4, X86_WIDTH_32, 4)
CMOV_CONDITION(tv_cmov32_c5, X86_WIDTH_32, 5)
CMOV_CONDITION(tv_cmov32_c6, X86_WIDTH_32, 6)
CMOV_CONDITION(tv_cmov32_c7, X86_WIDTH_32, 7)
CMOV_CONDITION(tv_cmov32_c8, X86_WIDTH_32, 8)
CMOV_CONDITION(tv_cmov32_c9, X86_WIDTH_32, 9)
CMOV_CONDITION(tv_cmov32_c10, X86_WIDTH_32, 10)
CMOV_CONDITION(tv_cmov32_c11, X86_WIDTH_32, 11)
CMOV_CONDITION(tv_cmov32_c12, X86_WIDTH_32, 12)
CMOV_CONDITION(tv_cmov32_c13, X86_WIDTH_32, 13)
CMOV_CONDITION(tv_cmov32_c14, X86_WIDTH_32, 14)
CMOV_CONDITION(tv_cmov32_c15, X86_WIDTH_32, 15)
CMOV_CONDITION(tv_cmov64_c0, X86_WIDTH_64, 0)
CMOV_CONDITION(tv_cmov64_c1, X86_WIDTH_64, 1)
CMOV_CONDITION(tv_cmov64_c2, X86_WIDTH_64, 2)
CMOV_CONDITION(tv_cmov64_c3, X86_WIDTH_64, 3)
CMOV_CONDITION(tv_cmov64_c4, X86_WIDTH_64, 4)
CMOV_CONDITION(tv_cmov64_c5, X86_WIDTH_64, 5)
CMOV_CONDITION(tv_cmov64_c6, X86_WIDTH_64, 6)
CMOV_CONDITION(tv_cmov64_c7, X86_WIDTH_64, 7)
CMOV_CONDITION(tv_cmov64_c8, X86_WIDTH_64, 8)
CMOV_CONDITION(tv_cmov64_c9, X86_WIDTH_64, 9)
CMOV_CONDITION(tv_cmov64_c10, X86_WIDTH_64, 10)
CMOV_CONDITION(tv_cmov64_c11, X86_WIDTH_64, 11)
CMOV_CONDITION(tv_cmov64_c12, X86_WIDTH_64, 12)
CMOV_CONDITION(tv_cmov64_c13, X86_WIDTH_64, 13)
CMOV_CONDITION(tv_cmov64_c14, X86_WIDTH_64, 14)
CMOV_CONDITION(tv_cmov64_c15, X86_WIDTH_64, 15)
