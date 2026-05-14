#include "common.h"

#define BPFTRACE_HAYSTACK_SIZE 96U
#define BPFTRACE_NEEDLE_SIZE 8U
#define BPFTRACE_SCAN_LIMIT (BPFTRACE_HAYSTACK_SIZE - BPFTRACE_NEEDLE_SIZE + 1U)
#define BPFTRACE_STRING_INPUT_SIZE (8U + BPFTRACE_HAYSTACK_SIZE + BPFTRACE_NEEDLE_SIZE)

static __always_inline u32 bpftrace_bounded_strlen(const u8 *data, u32 base)
{
    u32 len = 0;

    for (u32 index = 0; index < BPFTRACE_NEEDLE_SIZE; index++) {
        if (data[base + index] == 0) {
            break;
        }
        len++;
    }
    return len;
}

static __always_inline int
bench_bpftrace_string_search_prefix_scan(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, BPFTRACE_STRING_INPUT_SIZE)) {
        return -1;
    }

    u32 haystack_len = micro_read_u32_le(data, 0U);
    u32 declared_needle_len = micro_read_u32_le(data, 4U);
    u32 needle_base = 8U + BPFTRACE_HAYSTACK_SIZE;
    u32 needle_len = bpftrace_bounded_strlen(data, needle_base);
    if (haystack_len > BPFTRACE_HAYSTACK_SIZE ||
        declared_needle_len != needle_len ||
        needle_len == 0U) {
        return -1;
    }

    u64 acc = 0xD1B54A32D192ED03ULL;
    u32 found = BPFTRACE_HAYSTACK_SIZE;
    for (u32 pos = 0; pos < BPFTRACE_SCAN_LIMIT; pos++) {
        u32 diff = 0;

        if (pos + needle_len > haystack_len) {
            continue;
        }
        for (u32 index = 0; index < BPFTRACE_NEEDLE_SIZE; index++) {
            if (index < needle_len) {
                diff |= (u32)data[8U + pos + index] ^ data[needle_base + index];
            }
        }
        if (diff == 0U) {
            found = pos;
            break;
        }
    }

    if (found != BPFTRACE_HAYSTACK_SIZE) {
        acc += (u64)(found + 1U) * (u64)(needle_len + 3U);
        acc ^= micro_rotl64(((u64)needle_len << 32U) | found, 3U);
    } else {
        acc ^= 0x9E3779B97F4A7C15ULL;
    }

    *out = acc;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    bpftrace_string_search_prefix_scan_xdp,
    bench_bpftrace_string_search_prefix_scan,
    bpftrace_string_search_prefix_scan_input_value,
    BPFTRACE_STRING_INPUT_SIZE)
