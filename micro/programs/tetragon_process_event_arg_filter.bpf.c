#include "common.h"

#define TETRAGON_ARG_FILTER_RECORDS 32U
#define TETRAGON_ARG_FILTER_RECORD_SIZE 32U
#define TETRAGON_ARG_FILTER_INPUT_SIZE \
    (8U + TETRAGON_ARG_FILTER_RECORDS * TETRAGON_ARG_FILTER_RECORD_SIZE)

static __always_inline u32 tetragon_event_weight(u32 event_id)
{
    return event_id == 1U ? 0x11U :
           event_id == 2U ? 0x23U :
           event_id == 5U ? 0x37U :
           event_id == 9U ? 0x41U :
           event_id == 13U ? 0x59U : 0U;
}

static __always_inline u32 tetragon_arg_prefix_class(u64 arg_sig)
{
    if ((arg_sig & 0xFFFFFFFFULL) == 0x68736162ULL) {
        return 1U;
    }
    if ((arg_sig & 0xFFFFFFFFULL) == 0x6C727563ULL) {
        return 2U;
    }
    if ((arg_sig & 0xFFFFFFFFFFFFULL) == 0x6E6F68747970ULL) {
        return 3U;
    }
    if ((arg_sig & 0xFFFFFFULL) == 0x006873ULL) {
        return 4U;
    }
    return 0U;
}

static __always_inline int
bench_tetragon_process_event_arg_filter(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, TETRAGON_ARG_FILTER_INPUT_SIZE)) {
        return -1;
    }

    u32 record_count = micro_read_u32_le(data, 0U);
    u32 record_size = micro_read_u32_le(data, 4U);
    if (record_count != TETRAGON_ARG_FILTER_RECORDS ||
        record_size != TETRAGON_ARG_FILTER_RECORD_SIZE) {
        return -1;
    }

    u64 acc = 0xE7037ED1A0B428DBULL;
    for (u32 index = 0; index < TETRAGON_ARG_FILTER_RECORDS; index++) {
        u32 base = 8U + index * TETRAGON_ARG_FILTER_RECORD_SIZE;
        u32 pid = micro_read_u32_le(data, base);
        u32 tid = micro_read_u32_le(data, base + 4U);
        u32 namespace_id = micro_read_u32_le(data, base + 8U);
        u32 event_id = micro_read_u16_le(data, base + 12U);
        u32 action = micro_read_u16_le(data, base + 14U);
        u64 caps = micro_read_u64_le(data, base + 16U);
        u64 arg_sig = micro_read_u64_le(data, base + 24U);
        u32 weight = tetragon_event_weight(event_id);
        u32 arg_class = tetragon_arg_prefix_class(arg_sig);
        u32 namespace_match = (namespace_id & 0xFFU) == 0x42U;
        u32 cap_match = (caps & 0x0000000000002400ULL) != 0U;

        if (weight == 0U) {
            acc ^= ((u64)event_id << 32U) | pid;
            continue;
        }
        if (namespace_match == 0U && cap_match == 0U) {
            acc += ((u64)tid << 16U) ^ namespace_id;
            continue;
        }

        u64 decision = ((u64)weight << 48U) | ((u64)arg_class << 40U) |
                       ((u64)action << 24U) | pid;
        if ((action & 2U) != 0U && arg_class != 0U) {
            decision ^= micro_rotl64(arg_sig, (event_id & 7U) + 1U);
        }
        if ((action & 4U) != 0U) {
            decision += caps ^ tid;
        }

        acc ^= micro_rotl64(decision, (index & 7U) + 1U);
    }

    *out = acc;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    tetragon_process_event_arg_filter_xdp,
    bench_tetragon_process_event_arg_filter,
    tetragon_process_event_arg_filter_input_value,
    TETRAGON_ARG_FILTER_INPUT_SIZE)
