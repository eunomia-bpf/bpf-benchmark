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
