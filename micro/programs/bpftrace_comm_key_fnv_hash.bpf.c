#include "common.h"

#define BPFTRACE_COMM_KEY_RECORDS 32U
#define BPFTRACE_COMM_KEY_RECORD_SIZE 32U
#define BPFTRACE_COMM_KEY_INPUT_SIZE \
    (8U + BPFTRACE_COMM_KEY_RECORDS * BPFTRACE_COMM_KEY_RECORD_SIZE)
#define BPFTRACE_FNV_OFFSET 14695981039346656037ULL
#define BPFTRACE_FNV_PRIME 1099511628211ULL

static __always_inline u64 bpftrace_fnv1a_byte(u64 hash, u8 value)
{
    return (hash ^ value) * BPFTRACE_FNV_PRIME;
}

static __always_inline u64 bpftrace_fnv1a_u32(u64 hash, u32 value)
{
    hash = bpftrace_fnv1a_byte(hash, value & 0xFFU);
    hash = bpftrace_fnv1a_byte(hash, (value >> 8U) & 0xFFU);
    hash = bpftrace_fnv1a_byte(hash, (value >> 16U) & 0xFFU);
    return bpftrace_fnv1a_byte(hash, (value >> 24U) & 0xFFU);
}

static __always_inline int
bench_bpftrace_comm_key_fnv_hash(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, BPFTRACE_COMM_KEY_INPUT_SIZE)) {
        return -1;
    }

    u32 record_count = micro_read_u32_le(data, 0U);
    u32 record_size = micro_read_u32_le(data, 4U);
    if (record_count != BPFTRACE_COMM_KEY_RECORDS ||
        record_size != BPFTRACE_COMM_KEY_RECORD_SIZE) {
        return -1;
    }

    u64 acc = 0x94D049BB133111EBULL;
    for (u32 index = 0; index < BPFTRACE_COMM_KEY_RECORDS; index++) {
        u32 base = 8U + index * BPFTRACE_COMM_KEY_RECORD_SIZE;
        u32 pid = micro_read_u32_le(data, base);
        u32 tgid = micro_read_u32_le(data, base + 4U);
        u32 probe_id = micro_read_u32_le(data, base + 8U);
        u32 flags = micro_read_u32_le(data, base + 12U);
        u64 hash = BPFTRACE_FNV_OFFSET;

        hash = bpftrace_fnv1a_u32(hash, pid);
        hash = bpftrace_fnv1a_u32(hash, tgid);
        hash = bpftrace_fnv1a_u32(hash, probe_id);
        for (u32 byte = 0; byte < 16U; byte++) {
            hash = bpftrace_fnv1a_byte(hash, data[base + 16U + byte]);
        }

        if ((flags & 1U) != 0U) {
            hash ^= micro_rotl64(((u64)pid << 32U) | tgid,
                                 (probe_id & 7U) + 1U);
        }
        if ((flags & 2U) != 0U && data[base + 16U] == 'p') {
            hash += 0x9E3779B185EBCA87ULL;
        }

        acc ^= micro_rotl64(hash, (index & 7U) + 1U);
        acc += ((u64)(flags & 0xFFU) << 56U) ^ probe_id;
    }

    *out = acc;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    bpftrace_comm_key_fnv_hash_xdp,
    bench_bpftrace_comm_key_fnv_hash,
    bpftrace_comm_key_fnv_hash_input_value,
    BPFTRACE_COMM_KEY_INPUT_SIZE)
