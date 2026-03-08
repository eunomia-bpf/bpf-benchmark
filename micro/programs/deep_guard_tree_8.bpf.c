#include "common.h"

#define DEEP_GUARD_TREE_8_RECORDS 32U
#define DEEP_GUARD_TREE_8_RECORD_SIZE 16U
#define DEEP_GUARD_TREE_8_INPUT_SIZE \
    (4U + DEEP_GUARD_TREE_8_RECORDS * DEEP_GUARD_TREE_8_RECORD_SIZE)

struct deep_guard_tree_8_input_value {
    unsigned char data[DEEP_GUARD_TREE_8_INPUT_SIZE];
};

struct {
    __uint(type, BPF_MAP_TYPE_ARRAY);
    __uint(max_entries, 1);
    __type(key, __u32);
    __type(value, struct deep_guard_tree_8_input_value);
} input_map SEC(".maps");

static __always_inline int bench_deep_guard_tree_8(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, 4U)) {
        return -1;
    }

    u32 record_count = micro_read_u32_le(data, 0U);
    if (record_count != DEEP_GUARD_TREE_8_RECORDS) {
        return -1;
    }
    if (!micro_has_bytes(len, 4U, DEEP_GUARD_TREE_8_RECORDS * DEEP_GUARD_TREE_8_RECORD_SIZE)) {
        return -1;
    }

    u64 acc = 0xE7037ED1A0B428DBULL;
    for (u32 index = 0; index < DEEP_GUARD_TREE_8_RECORDS; index++) {
        u32 base = 4U + index * DEEP_GUARD_TREE_8_RECORD_SIZE;
        u8 f0 = data[base + 0U];
        u8 f1 = data[base + 1U];
        u8 f2 = data[base + 2U];
        u8 f3 = data[base + 3U];
        u8 f4 = data[base + 4U];
        u8 f5 = data[base + 5U];
        u8 f6 = data[base + 6U];
        u8 f7 = data[base + 7U];
        u64 payload = micro_read_u64_le(data, base + 8U);

        if (f0 > 0x20U) {
            if ((f1 & 1U) != 0U) {
                if (f2 < 0x80U) {
                    if ((u8)(f3 ^ index) > 0x10U) {
                        if ((u8)(f4 + f0) < 0xC0U) {
                            if ((f5 & 0x18U) == 0x10U) {
                                if (f6 != 0xAAU) {
                                    if ((f7 & 3U) == 1U) {
                                        acc += payload ^ ((u64)f7 << 48U);
                                    } else {
                                        acc ^= payload + ((u64)f6 << 40U);
                                    }
                                } else {
                                    acc += micro_rotl64(payload ^ f5, 7U);
                                }
                            } else {
                                acc ^= payload + ((u64)f5 << 32U);
                            }
                        } else {
                            acc += payload ^ ((u64)f4 << 24U);
                        }
                    } else {
                        acc ^= payload + ((u64)f3 << 16U);
                    }
                } else {
                    acc += payload ^ ((u64)f2 << 8U);
                }
            } else {
                acc ^= payload + f1;
            }
        } else {
            acc += payload ^ f0;
        }

        acc = micro_rotl64(acc, (index & 7U) + 1U);
    }

    *out = acc;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    deep_guard_tree_8_xdp,
    bench_deep_guard_tree_8,
    deep_guard_tree_8_input_value,
    DEEP_GUARD_TREE_8_INPUT_SIZE)
