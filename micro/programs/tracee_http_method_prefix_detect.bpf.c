#include "common.h"

#define TRACEE_HTTP_METHOD_RECORDS 8U
#define TRACEE_HTTP_METHOD_RECORD_SIZE 16U
#define TRACEE_HTTP_METHOD_INPUT_SIZE \
    (8U + TRACEE_HTTP_METHOD_RECORDS * TRACEE_HTTP_METHOD_RECORD_SIZE)

static __always_inline int tracee_match3(const u8 *data, u32 base, u8 a, u8 b, u8 c)
{
    return data[base] == a && data[base + 1U] == b && data[base + 2U] == c;
}

static __always_inline int tracee_match4(const u8 *data, u32 base, u8 a, u8 b, u8 c, u8 d)
{
    return tracee_match3(data, base, a, b, c) && data[base + 3U] == d;
}

static __always_inline int tracee_match5(const u8 *data, u32 base, u8 a, u8 b, u8 c, u8 d, u8 e)
{
    return tracee_match4(data, base, a, b, c, d) && data[base + 4U] == e;
}

static __always_inline int tracee_match7(const u8 *data, u32 base, u8 a, u8 b, u8 c, u8 d, u8 e, u8 f, u8 g)
{
    return tracee_match5(data, base, a, b, c, d, e) &&
           data[base + 5U] == f && data[base + 6U] == g;
}

static __always_inline u32 tracee_http_method_code(const u8 *data, u32 base)
{
    if (tracee_match4(data, base, 'G', 'E', 'T', ' ')) {
        return 1U;
    }
    if (tracee_match5(data, base, 'P', 'O', 'S', 'T', ' ')) {
        return 2U;
    }
    if (tracee_match4(data, base, 'P', 'U', 'T', ' ')) {
        return 3U;
    }
    if (tracee_match7(data, base, 'D', 'E', 'L', 'E', 'T', 'E', ' ')) {
        return 4U;
    }
    if (tracee_match5(data, base, 'H', 'E', 'A', 'D', ' ')) {
        return 5U;
    }
    if (tracee_match5(data, base, 'H', 'T', 'T', 'P', '/')) {
        return 6U;
    }
    return 0U;
}

static __always_inline int
bench_tracee_http_method_prefix_detect(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, TRACEE_HTTP_METHOD_INPUT_SIZE)) {
        return -1;
    }

    u32 record_count = micro_read_u32_le(data, 0U);
    u32 record_size = micro_read_u32_le(data, 4U);
    if (record_count != TRACEE_HTTP_METHOD_RECORDS ||
        record_size != TRACEE_HTTP_METHOD_RECORD_SIZE) {
        return -1;
    }

    u64 acc = 0xA0761D6478BD642FULL;
    for (u32 index = 0; index < TRACEE_HTTP_METHOD_RECORDS; index++) {
        u32 base = 8U + index * TRACEE_HTTP_METHOD_RECORD_SIZE;
        u32 code = tracee_http_method_code(data, base);
        u32 first = micro_read_u32_le(data, base);

        acc += (u64)(code + 1U) * (u64)(index + 11U);
        acc ^= micro_rotl64(((u64)first << 8U) | code, (index & 7U) + 1U);
    }

    *out = acc;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    tracee_http_method_prefix_detect_xdp,
    bench_tracee_http_method_prefix_detect,
    tracee_http_method_prefix_detect_input_value,
    TRACEE_HTTP_METHOD_INPUT_SIZE)
