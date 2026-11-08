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

/* All16 conditions for both legal byte-register slices. */
#define SETCC_UNIT(NAME, SHIFT, CC) \
__attribute__((section("tv/setcc/" #NAME), used)) \
__u64 NAME(__u64 old, __u64 flags) \
{ \
    X86_SIM_L_DECLARE_STATE(); \
    X86_SIM_L_DECLARE_STACK(); \
    struct __sk_buff *__x86_sim_skb_ctx = 0; \
    __u8 __x86_sim_abi_kind = 0; \
    __x86_rax.ptr = (void *)(long)old; \
    __x86_cf = flags & 1; \
    __x86_pf = (flags >> 2) & 1; \
    __x86_zf = (flags >> 6) & 1; \
    __x86_sf = (flags >> 7) & 1; \
    __x86_of = (flags >> 11) & 1; \
    X86_SIM_L_EXEC_SETCC(X86_RAX, KPROG_X86_REG_LANE_AUX(CC, SHIFT, 0)); \
    return X86_SIM_L_READ_REG(X86_RAX); \
}
SETCC_UNIT(tv_setcc_lo_c0, 0, 0)
SETCC_UNIT(tv_setcc_lo_c1, 0, 1)
SETCC_UNIT(tv_setcc_lo_c2, 0, 2)
SETCC_UNIT(tv_setcc_lo_c3, 0, 3)
SETCC_UNIT(tv_setcc_lo_c4, 0, 4)
SETCC_UNIT(tv_setcc_lo_c5, 0, 5)
SETCC_UNIT(tv_setcc_lo_c6, 0, 6)
SETCC_UNIT(tv_setcc_lo_c7, 0, 7)
SETCC_UNIT(tv_setcc_lo_c8, 0, 8)
SETCC_UNIT(tv_setcc_lo_c9, 0, 9)
SETCC_UNIT(tv_setcc_lo_c10, 0, 10)
SETCC_UNIT(tv_setcc_lo_c11, 0, 11)
SETCC_UNIT(tv_setcc_lo_c12, 0, 12)
SETCC_UNIT(tv_setcc_lo_c13, 0, 13)
SETCC_UNIT(tv_setcc_lo_c14, 0, 14)
SETCC_UNIT(tv_setcc_lo_c15, 0, 15)
SETCC_UNIT(tv_setcc_hi_c0, 8, 0)
SETCC_UNIT(tv_setcc_hi_c1, 8, 1)
SETCC_UNIT(tv_setcc_hi_c2, 8, 2)
SETCC_UNIT(tv_setcc_hi_c3, 8, 3)
SETCC_UNIT(tv_setcc_hi_c4, 8, 4)
SETCC_UNIT(tv_setcc_hi_c5, 8, 5)
SETCC_UNIT(tv_setcc_hi_c6, 8, 6)
SETCC_UNIT(tv_setcc_hi_c7, 8, 7)
SETCC_UNIT(tv_setcc_hi_c8, 8, 8)
SETCC_UNIT(tv_setcc_hi_c9, 8, 9)
SETCC_UNIT(tv_setcc_hi_c10, 8, 10)
SETCC_UNIT(tv_setcc_hi_c11, 8, 11)
SETCC_UNIT(tv_setcc_hi_c12, 8, 12)
SETCC_UNIT(tv_setcc_hi_c13, 8, 13)
SETCC_UNIT(tv_setcc_hi_c14, 8, 14)
SETCC_UNIT(tv_setcc_hi_c15, 8, 15)

/* Production dispatcher BSWAP units: both architectural operand widths. */
#define BSWAP_UNIT(BITS, WIDTH) \
__attribute__((section("tv/bswap" #BITS), used)) \
__u64 tv_bswap##BITS(__u64 old) \
{ \
    X86_SIM_L_DECLARE_STATE(); \
    X86_SIM_L_DECLARE_STACK(); \
    struct __sk_buff *__x86_sim_skb_ctx = 0; \
    __u8 __x86_sim_abi_kind = 0; \
    __x86_rax.ptr = (void *)(long)old; \
    X86_SIM_L_EXEC(X86_OP_BSWAP, X86_RAX, 0, WIDTH, 0, 0); \
    return X86_SIM_L_READ_REG(X86_RAX); \
}
BSWAP_UNIT(32, X86_WIDTH_32)
BSWAP_UNIT(64, X86_WIDTH_64)

/* Scalar MOV_REG production-dispatch units, independent of applications. */
#define MOVREG_UNIT(NAME, WIDTH, DS, SS) \
__attribute__((section("tv/movreg/" #NAME), used)) \
__u64 NAME(__u64 old, __u64 source) \
{ \
    X86_SIM_L_DECLARE_STATE(); \
    X86_SIM_L_DECLARE_STACK(); \
    struct __sk_buff *__x86_sim_skb_ctx = 0; \
    __u8 __x86_sim_abi_kind = 0; \
    __x86_rax.ptr = (void *)(long)old; \
    __x86_rdx.ptr = (void *)(long)source; \
    X86_SIM_L_EXEC(X86_OP_MOV_REG, X86_RAX, X86_RDX, WIDTH, \
        KPROG_X86_REG_LANE_AUX(0, DS, SS), 0); \
    return X86_SIM_L_READ_REG(X86_RAX); \
}
MOVREG_UNIT(tv_mov8_ll, X86_WIDTH_8, 0, 0)
MOVREG_UNIT(tv_mov8_lh, X86_WIDTH_8, 0, 8)
MOVREG_UNIT(tv_mov8_hl, X86_WIDTH_8, 8, 0)
MOVREG_UNIT(tv_mov8_hh, X86_WIDTH_8, 8, 8)
MOVREG_UNIT(tv_mov16, X86_WIDTH_16, 0, 0)
MOVREG_UNIT(tv_mov32, X86_WIDTH_32, 0, 0)
MOVREG_UNIT(tv_mov64, X86_WIDTH_64, 0, 0)

#define MOVX_UNIT(NAME, OP, TARGET, SOURCE, SLICE) \
__attribute__((section("tv/movx/" #NAME), used)) \
__u64 NAME(__u64 old, __u64 source) \
{ \
    X86_SIM_L_DECLARE_STATE(); \
    X86_SIM_L_DECLARE_STACK(); \
    struct __sk_buff *__x86_sim_skb_ctx = 0; \
    __u8 __x86_sim_abi_kind = 0; \
    __x86_rax.ptr = (void *)(long)old; \
    __x86_rdx.ptr = (void *)(long)source; \
    X86_SIM_L_EXEC(OP, X86_RAX, SLICE, TARGET, SOURCE, 0); \
    return X86_SIM_L_READ_REG(X86_RAX); \
}
MOVX_UNIT(tv_movz8lto16, X86_OP_MOVZX_REG, X86_WIDTH_16, X86_WIDTH_8, X86_RDX)
MOVX_UNIT(tv_movz8lto32, X86_OP_MOVZX_REG, X86_WIDTH_32, X86_WIDTH_8, X86_RDX)
MOVX_UNIT(tv_movz8lto64, X86_OP_MOVZX_REG, X86_WIDTH_64, X86_WIDTH_8, X86_RDX)
MOVX_UNIT(tv_movz8hto16, X86_OP_MOVZX_REG, X86_WIDTH_16, X86_WIDTH_8, 130)
MOVX_UNIT(tv_movz8hto32, X86_OP_MOVZX_REG, X86_WIDTH_32, X86_WIDTH_8, 130)
MOVX_UNIT(tv_movz16lto32, X86_OP_MOVZX_REG, X86_WIDTH_32, X86_WIDTH_16, X86_RDX)
MOVX_UNIT(tv_movz16lto64, X86_OP_MOVZX_REG, X86_WIDTH_64, X86_WIDTH_16, X86_RDX)
MOVX_UNIT(tv_movs8lto16, X86_OP_MOVSX_REG, X86_WIDTH_16, X86_WIDTH_8, X86_RDX)
MOVX_UNIT(tv_movs8lto32, X86_OP_MOVSX_REG, X86_WIDTH_32, X86_WIDTH_8, X86_RDX)
MOVX_UNIT(tv_movs8lto64, X86_OP_MOVSX_REG, X86_WIDTH_64, X86_WIDTH_8, X86_RDX)
MOVX_UNIT(tv_movs8hto16, X86_OP_MOVSX_REG, X86_WIDTH_16, X86_WIDTH_8, 130)
MOVX_UNIT(tv_movs8hto32, X86_OP_MOVSX_REG, X86_WIDTH_32, X86_WIDTH_8, 130)
MOVX_UNIT(tv_movs16lto32, X86_OP_MOVSX_REG, X86_WIDTH_32, X86_WIDTH_16, X86_RDX)
MOVX_UNIT(tv_movs16lto64, X86_OP_MOVSX_REG, X86_WIDTH_64, X86_WIDTH_16, X86_RDX)
MOVX_UNIT(tv_movs32lto64, X86_OP_MOVSX_REG, X86_WIDTH_64, X86_WIDTH_32, X86_RDX)

#define SHIFTX_UNIT(NAME, WIDTH, KIND) \
__attribute__((section("tv/shiftx/" #NAME), used)) \
__u64 NAME(__u64 old, __u64 source, __u64 count) \
{ \
    X86_SIM_L_DECLARE_STATE(); \
    X86_SIM_L_DECLARE_STACK(); \
    struct __sk_buff *__x86_sim_skb_ctx = 0; \
    __u8 __x86_sim_abi_kind = 0; \
    __x86_rax.ptr = (void *)(long)old; \
    __x86_rdx.ptr = (void *)(long)source; \
    __x86_rcx.ptr = (void *)(long)count; \
    X86_SIM_L_EXEC(X86_OP_SHIFTX, X86_RAX, X86_RDX, WIDTH, X86_RCX, KIND); \
    return X86_SIM_L_READ_REG(X86_RAX); \
}
SHIFTX_UNIT(tv_shl32, X86_WIDTH_32, X86_ALU_SHL)
SHIFTX_UNIT(tv_shl64, X86_WIDTH_64, X86_ALU_SHL)
SHIFTX_UNIT(tv_shr32, X86_WIDTH_32, X86_ALU_SHR)
SHIFTX_UNIT(tv_shr64, X86_WIDTH_64, X86_ALU_SHR)
SHIFTX_UNIT(tv_sar32, X86_WIDTH_32, X86_ALU_SAR)
SHIFTX_UNIT(tv_sar64, X86_WIDTH_64, X86_ALU_SAR)

#define POPCOUNT_UNIT(NAME, WIDTH) \
__attribute__((section("tv/popcount/" #NAME), used)) \
__u64 NAME(__u64 old, __u64 source) \
{ \
    X86_SIM_L_DECLARE_STATE(); \
    X86_SIM_L_DECLARE_STACK(); \
    struct __sk_buff *__x86_sim_skb_ctx = 0; \
    __u8 __x86_sim_abi_kind = 0; \
    __x86_rax.ptr = (void *)(long)old; \
    __x86_rdx.ptr = (void *)(long)source; \
    X86_SIM_L_EXEC(X86_OP_POPCNT, X86_RAX, X86_RDX, WIDTH, 0U, 0ULL); \
    return X86_SIM_L_READ_REG(X86_RAX); \
}
POPCOUNT_UNIT(tv_popcount16, X86_WIDTH_16)
POPCOUNT_UNIT(tv_popcount32, X86_WIDTH_32)
POPCOUNT_UNIT(tv_popcount64, X86_WIDTH_64)

#define ANDN_UNIT(NAME, WIDTH) \
__attribute__((section("tv/andn/" #NAME), used)) \
__u64 NAME(__u64 first, __u64 second) \
{ \
    X86_SIM_L_DECLARE_STATE(); \
    X86_SIM_L_DECLARE_STACK(); \
    struct __sk_buff *__x86_sim_skb_ctx = 0; \
    __u8 __x86_sim_abi_kind = 0; \
    __x86_rax.ptr = (void *)(long)first; \
    __x86_rdx.ptr = (void *)(long)second; \
    X86_SIM_L_EXEC(X86_OP_ANDN, X86_RAX, X86_RAX, WIDTH, X86_RDX, 0ULL); \
    return X86_SIM_L_READ_REG(X86_RAX); \
}
ANDN_UNIT(tv_andn32, X86_WIDTH_32)
ANDN_UNIT(tv_andn64, X86_WIDTH_64)
