#include "common.h"

#define MIXED_ALU_MEM_COUNT 128U
#define MIXED_ALU_MEM_INPUT_SIZE (8U + MIXED_ALU_MEM_COUNT * 8U)

static __always_inline int bench_mixed_alu_mem(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, 8U)) {
        return -1;
    }

    u32 count = micro_read_u32_le(data, 0);
    u32 seed = micro_read_u32_le(data, 4);

    if (count != MIXED_ALU_MEM_COUNT) {
        return -1;
    }
    if (!micro_has_bytes(len, 8U, MIXED_ALU_MEM_COUNT * 8U)) {
        return -1;
    }

    u64 acc = ((u64)seed << 21) ^ 0x369DEA0F31A53F85ULL;
    for (u32 i = 0; i < MIXED_ALU_MEM_COUNT; i++) {
        u64 a = micro_read_u64_le(data, 8U + i * 8U);
        u64 b = micro_read_u64_le(data, 8U + (((i + 17U) & (MIXED_ALU_MEM_COUNT - 1U)) * 8U));
        u64 c = micro_read_u64_le(data, 8U + (((i * 5U) & (MIXED_ALU_MEM_COUNT - 1U)) * 8U));

        acc += (a ^ micro_rotl64(b, (i & 7U) + 1U)) + (c >> ((i >> 1) & 7U));
        if (((a ^ c) & 1ULL) != 0ULL) {
            acc ^= b + ((u64)i * 0x9E3779B1ULL);
        } else {
            acc += a - c;
        }
        acc ^= micro_rotl64(acc + a, ((u32)(a >> 3) & 7U) + 1U);
    }

    *out = acc;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    mixed_alu_mem_xdp,
    bench_mixed_alu_mem,
    mixed_alu_mem_input_value,
    MIXED_ALU_MEM_INPUT_SIZE)
