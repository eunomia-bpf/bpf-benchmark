#include "common.h"

#define BRANCH_FANOUT_32_COUNT 128U
#define BRANCH_FANOUT_32_INPUT_SIZE (4U + BRANCH_FANOUT_32_COUNT * 4U)

#define BRANCH_FANOUT_CASE(TAG, SALT)                                           \
    case (TAG): {                                                               \
        u64 tmp = ((u64)value << (((SALT) & 7U) + 1U)) ^ acc;                   \
        tmp += 0x9E3779B97F4A7C15ULL + ((u64)(SALT) * 0x100000001B3ULL);        \
        tmp ^= micro_rotl64(tmp, ((SALT) & 15U) + 1U);                          \
        acc += tmp ^ ((u64)index << (((SALT) >> 1U) & 7U));                     \
        break;                                                                  \
    }

static __always_inline int bench_branch_fanout_32(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, 4U)) {
        return -1;
    }

    u32 count = micro_read_u32_le(data, 0U);
    if (count != BRANCH_FANOUT_32_COUNT) {
        return -1;
    }
    if (!micro_has_bytes(len, 4U, BRANCH_FANOUT_32_COUNT * 4U)) {
        return -1;
    }

    u64 acc = 0xD6E8FEB86659FD93ULL;
    for (u32 index = 0; index < BRANCH_FANOUT_32_COUNT; index++) {
        u32 value = micro_read_u32_le(data, 4U + index * 4U);
        u32 tag = value & 63U;

        switch (tag) {
        BRANCH_FANOUT_CASE(0U, 1U)
        BRANCH_FANOUT_CASE(2U, 2U)
        BRANCH_FANOUT_CASE(3U, 3U)
        BRANCH_FANOUT_CASE(5U, 4U)
        BRANCH_FANOUT_CASE(7U, 5U)
        BRANCH_FANOUT_CASE(9U, 6U)
        BRANCH_FANOUT_CASE(11U, 7U)
        BRANCH_FANOUT_CASE(12U, 8U)
        BRANCH_FANOUT_CASE(14U, 9U)
        BRANCH_FANOUT_CASE(17U, 10U)
        BRANCH_FANOUT_CASE(19U, 11U)
        BRANCH_FANOUT_CASE(21U, 12U)
        BRANCH_FANOUT_CASE(24U, 13U)
        BRANCH_FANOUT_CASE(25U, 14U)
        BRANCH_FANOUT_CASE(26U, 15U)
        BRANCH_FANOUT_CASE(28U, 16U)
        BRANCH_FANOUT_CASE(31U, 17U)
        BRANCH_FANOUT_CASE(33U, 18U)
        BRANCH_FANOUT_CASE(35U, 19U)
        BRANCH_FANOUT_CASE(37U, 20U)
        BRANCH_FANOUT_CASE(38U, 21U)
        BRANCH_FANOUT_CASE(40U, 22U)
        BRANCH_FANOUT_CASE(42U, 23U)
        BRANCH_FANOUT_CASE(45U, 24U)
        BRANCH_FANOUT_CASE(47U, 25U)
        BRANCH_FANOUT_CASE(49U, 26U)
        BRANCH_FANOUT_CASE(52U, 27U)
        BRANCH_FANOUT_CASE(54U, 28U)
        BRANCH_FANOUT_CASE(56U, 29U)
        BRANCH_FANOUT_CASE(59U, 30U)
        BRANCH_FANOUT_CASE(61U, 31U)
        BRANCH_FANOUT_CASE(63U, 32U)
        default:
            acc ^= (u64)value + 0x94D049BB133111EBULL;
            break;
        }

        acc ^= (u64)tag << ((index & 7U) * 8U);
    }

    *out = acc;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    branch_fanout_32_xdp,
    bench_branch_fanout_32,
    branch_fanout_32_input_value,
    BRANCH_FANOUT_32_INPUT_SIZE)
