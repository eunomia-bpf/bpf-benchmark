#include "common.h"

#define BINARY_SEARCH_MAX_DATA_LEN 32U
#define BINARY_SEARCH_MAX_QUERY_LEN 16U
#define BINARY_SEARCH_INPUT_SIZE \
    (8U + (BINARY_SEARCH_MAX_DATA_LEN + BINARY_SEARCH_MAX_QUERY_LEN) * 8U)

struct binary_search_input_value {
    unsigned char data[BINARY_SEARCH_INPUT_SIZE];
};

struct {
    __uint(type, BPF_MAP_TYPE_ARRAY);
    __uint(max_entries, 1);
    __type(key, __u32);
    __type(value, struct binary_search_input_value);
} input_map SEC(".maps");

static __always_inline int bench_binary_search(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, 8)) {
        return -1;
    }

    u32 data_len = micro_read_u32_le(data, 0);
    u32 query_len = micro_read_u32_le(data, 4);
    u32 data_bytes;
    u32 query_bytes;
    u32 query_offset;
    u64 acc = 0;

    if (data_len != BINARY_SEARCH_MAX_DATA_LEN || query_len != BINARY_SEARCH_MAX_QUERY_LEN) {
        return -1;
    }

    data_bytes = BINARY_SEARCH_MAX_DATA_LEN * 8U;
    query_bytes = BINARY_SEARCH_MAX_QUERY_LEN * 8U;
    query_offset = 8 + data_bytes;

    if (!micro_has_bytes(len, 8, data_bytes + query_bytes)) {
        return -1;
    }

    for (u32 i = 0; i < BINARY_SEARCH_MAX_QUERY_LEN; i++) {
        u64 target = micro_read_u64_le(data, query_offset + i * 8);
        u64 found = 0;
        u64 index = 0;
        for (u32 j = 0; j < BINARY_SEARCH_MAX_DATA_LEN; j++) {
            u64 current = micro_read_u64_le(data, 8 + j * 8);
            if (!found && current == target) {
                found = 1;
                index = j;
            }
        }
        if (found) {
            acc += index;
        } else {
            acc ^= target + BINARY_SEARCH_MAX_DATA_LEN;
        }
    }

    *out = acc;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    binary_search_xdp,
    bench_binary_search,
    binary_search_input_value,
    BINARY_SEARCH_INPUT_SIZE)
