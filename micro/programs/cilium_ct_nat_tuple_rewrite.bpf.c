#include "common.h"

#define CILIUM_CT_NAT_RECORDS 32U
#define CILIUM_CT_NAT_RECORD_SIZE 32U
#define CILIUM_CT_NAT_INPUT_SIZE \
    (8U + CILIUM_CT_NAT_RECORDS * CILIUM_CT_NAT_RECORD_SIZE)

static __always_inline int
bench_cilium_ct_nat_tuple_rewrite(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, CILIUM_CT_NAT_INPUT_SIZE)) {
        return -1;
    }

    u32 record_count = micro_read_u32_le(data, 0U);
    u32 record_size = micro_read_u32_le(data, 4U);
    if (record_count != CILIUM_CT_NAT_RECORDS ||
        record_size != CILIUM_CT_NAT_RECORD_SIZE) {
        return -1;
    }

    u64 acc = 0x8EBC6AF09C88C6E3ULL;
    for (u32 index = 0; index < CILIUM_CT_NAT_RECORDS; index++) {
        u32 base = 8U + index * CILIUM_CT_NAT_RECORD_SIZE;
        u32 src = micro_read_u32_le(data, base);
        u32 dst = micro_read_u32_le(data, base + 4U);
        u16 sport = micro_read_u16_le(data, base + 8U);
        u16 dport = micro_read_u16_le(data, base + 10U);
        u8 proto = data[base + 12U];
        u8 direction = data[base + 13U];
        u16 flags = micro_read_u16_le(data, base + 14U);
        u32 nat_src = micro_read_u32_le(data, base + 16U);
        u32 nat_dst = micro_read_u32_le(data, base + 20U);
        u16 rev_nat_id = micro_read_u16_le(data, base + 24U);
        u16 identity = micro_read_u16_le(data, base + 26U);
        u32 lifetime = micro_read_u32_le(data, base + 28U);

        if (proto != 6U && proto != 17U) {
            acc ^= ((u64)proto << 56U) | lifetime;
            continue;
        }

        if ((flags & 1U) != 0U) {
            src = nat_src;
            sport ^= rev_nat_id;
        }
        if ((flags & 2U) != 0U) {
            dst = nat_dst;
            dport ^= rev_nat_id;
        }
        if ((direction & 1U) != 0U) {
            u32 tmp_ip = src;
            u16 tmp_port = sport;
            src = dst;
            dst = tmp_ip;
            sport = dport;
            dport = tmp_port;
        }

        u32 tuple_hash = src ^ micro_rotl32(dst, 11U) ^
                         ((u32)sport << 16U) ^ dport ^
                         ((u32)proto << 24U) ^ identity;
        if ((flags & 4U) != 0U) {
            tuple_hash += lifetime ^ ((u32)rev_nat_id << 8U);
        }

        acc += ((u64)tuple_hash << 32U) | lifetime;
        acc ^= micro_rotl64(((u64)src << 32U) | dst, (index & 7U) + 1U);
    }

    *out = acc;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    cilium_ct_nat_tuple_rewrite_xdp,
    bench_cilium_ct_nat_tuple_rewrite,
    cilium_ct_nat_tuple_rewrite_input_value,
    CILIUM_CT_NAT_INPUT_SIZE)
