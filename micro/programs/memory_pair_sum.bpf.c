#include "common.h"

#define MEMORY_PAIR_SUM_INPUT_SIZE 16U

static __always_inline int bench_memory_pair_sum(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, MEMORY_PAIR_SUM_INPUT_SIZE)) {
        return -1;
    }

    *out = micro_read_u64_le(data, 0) + micro_read_u64_le(data, 8);
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    memory_pair_sum_xdp,
    bench_memory_pair_sum,
    memory_pair_sum_input_value,
    MEMORY_PAIR_SUM_INPUT_SIZE)
