#include "common.h"

#define CMOV_DENSE_COUNT 32U
#define CMOV_DENSE_INPUT_SIZE (CMOV_DENSE_COUNT * 8U * 4U)

struct cmov_dense_input {
    u64 a[CMOV_DENSE_COUNT];
    u64 b[CMOV_DENSE_COUNT];
    u64 x[CMOV_DENSE_COUNT];
    u64 y[CMOV_DENSE_COUNT];
};

#define CMOV_DENSE_ROT(INDEX) ((((INDEX) * 5U) & 15U) + 1U)
#define CMOV_DENSE_SHIFT(INDEX) ((((INDEX) * 3U) >> 1U) & 7U)
#define CMOV_DENSE_BIAS(INDEX) ((u64)(0x9E37U + ((INDEX) * 0x45D9U)))

#define CMOV_DENSE_STEP(INDEX, COND_EXPR)                                       \
    do {                                                                        \
        u64 lhs = input->a[(INDEX)];                                            \
        u64 rhs = input->b[(INDEX)];                                            \
        u64 on_true = input->x[(INDEX)];                                        \
        u64 on_false = input->y[(INDEX)];                                       \
        u64 selected = on_true;                                                 \
        if (!(COND_EXPR))                                                       \
            selected = on_false;                                                \
        asm volatile("" : "+r"(selected), "+r"(on_true), "+r"(on_false)       \
                     :: "memory");                                             \
        acc ^= selected + CMOV_DENSE_BIAS(INDEX);                               \
        acc = micro_rotl64(acc, CMOV_DENSE_ROT(INDEX));                         \
        acc += selected ^ (acc >> CMOV_DENSE_SHIFT(INDEX));                     \
        asm volatile("" : "+r"(acc) : "r"(selected) : "memory");              \
    } while (0)

static __always_inline int bench_cmov_dense(const u8 *data, u32 len, u64 *out)
{
    const struct cmov_dense_input *input = (const struct cmov_dense_input *)data;

    if (!micro_has_bytes(len, 0, CMOV_DENSE_INPUT_SIZE)) {
        return -1;
    }

    u64 acc = 0x243F6A8885A308D3ULL;

    CMOV_DENSE_STEP(0, lhs > rhs);
    CMOV_DENSE_STEP(1, lhs >= rhs);
    CMOV_DENSE_STEP(2, (long long)lhs > (long long)rhs);
    CMOV_DENSE_STEP(3, (long long)lhs >= (long long)rhs);
    CMOV_DENSE_STEP(4, rhs > lhs);
    CMOV_DENSE_STEP(5, rhs >= lhs);
    CMOV_DENSE_STEP(6, (long long)rhs > (long long)lhs);
    CMOV_DENSE_STEP(7, (long long)rhs >= (long long)lhs);

    CMOV_DENSE_STEP(8, lhs > rhs);
    CMOV_DENSE_STEP(9, lhs >= rhs);
    CMOV_DENSE_STEP(10, (long long)lhs > (long long)rhs);
    CMOV_DENSE_STEP(11, (long long)lhs >= (long long)rhs);
    CMOV_DENSE_STEP(12, rhs > lhs);
    CMOV_DENSE_STEP(13, rhs >= lhs);
    CMOV_DENSE_STEP(14, (long long)rhs > (long long)lhs);
    CMOV_DENSE_STEP(15, (long long)rhs >= (long long)lhs);

    CMOV_DENSE_STEP(16, lhs > rhs);
    CMOV_DENSE_STEP(17, lhs >= rhs);
    CMOV_DENSE_STEP(18, (long long)lhs > (long long)rhs);
    CMOV_DENSE_STEP(19, (long long)lhs >= (long long)rhs);
    CMOV_DENSE_STEP(20, rhs > lhs);
    CMOV_DENSE_STEP(21, rhs >= lhs);
    CMOV_DENSE_STEP(22, (long long)rhs > (long long)lhs);
    CMOV_DENSE_STEP(23, (long long)rhs >= (long long)lhs);

    CMOV_DENSE_STEP(24, lhs > rhs);
    CMOV_DENSE_STEP(25, lhs >= rhs);
    CMOV_DENSE_STEP(26, (long long)lhs > (long long)rhs);
    CMOV_DENSE_STEP(27, (long long)lhs >= (long long)rhs);
    CMOV_DENSE_STEP(28, rhs > lhs);
    CMOV_DENSE_STEP(29, rhs >= lhs);
    CMOV_DENSE_STEP(30, (long long)rhs > (long long)lhs);
    CMOV_DENSE_STEP(31, (long long)rhs >= (long long)lhs);

    *out = acc;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    cmov_dense_xdp,
    bench_cmov_dense,
    cmov_dense_input_value,
    CMOV_DENSE_INPUT_SIZE)
