#include "common.h"

#define PROBE_READ_HEAVY_MAX_READS 64U
#define PROBE_READ_HEAVY_INPUT_SIZE 16U

struct probe_read_heavy_input_value {
    unsigned char data[PROBE_READ_HEAVY_INPUT_SIZE];
};

struct {
    __uint(type, BPF_MAP_TYPE_ARRAY);
    __uint(max_entries, 1);
    __type(key, __u32);
    __type(value, struct probe_read_heavy_input_value);
} input_map SEC(".maps");

static __always_inline int bench_probe_read_heavy(const u8 *data, u32 len, u64 *out)
{
    u64 requested_address;
    const void *source;
    u64 acc = 0;
    u32 count;

    if (!micro_has_bytes(len, 0, PROBE_READ_HEAVY_INPUT_SIZE)) {
        return -1;
    }

    requested_address = micro_read_u64_le(data, 0);
    count = micro_read_u32_le(data, 8);
    if (count > PROBE_READ_HEAVY_MAX_READS) {
        return -1;
    }

    source = (const void *)data;
    if (requested_address != 0) {
        source = (const void *)(long)requested_address;
    }

    for (u32 i = 0; i < PROBE_READ_HEAVY_MAX_READS; i++) {
        u64 word = 0;

        if (i >= count) {
            break;
        }
        if (bpf_probe_read_kernel(&word, sizeof(word), source) != 0) {
            return -1;
        }

        acc ^= micro_rotl64(word ^ (u64)i, i & 7U);
        acc += 0x9E3779B97F4A7C15ULL + i;
    }

    *out = acc;
    return 0;
}

DEFINE_MAP_BACKED_XDP_BENCH(
    probe_read_heavy_xdp,
    bench_probe_read_heavy,
    probe_read_heavy_input_value,
    PROBE_READ_HEAVY_INPUT_SIZE)
