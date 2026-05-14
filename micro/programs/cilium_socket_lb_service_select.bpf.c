#include "common.h"

#define CILIUM_SOCKET_LB_RECORDS 64U
#define CILIUM_SOCKET_LB_RECORD_SIZE 24U
#define CILIUM_SOCKET_LB_INPUT_SIZE \
    (8U + CILIUM_SOCKET_LB_RECORDS * CILIUM_SOCKET_LB_RECORD_SIZE)
#define CILIUM_NODEPORT_MIN 30000U
#define CILIUM_NODEPORT_MAX 32767U

static __always_inline int
bench_cilium_socket_lb_service_select(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, CILIUM_SOCKET_LB_INPUT_SIZE)) {
        return -1;
    }

    u32 record_count = micro_read_u32_le(data, 0U);
    u32 record_size = micro_read_u32_le(data, 4U);
    if (record_count != CILIUM_SOCKET_LB_RECORDS ||
        record_size != CILIUM_SOCKET_LB_RECORD_SIZE) {
        return -1;
    }

    u64 acc = 0x243F6A8885A308D3ULL;
    for (u32 index = 0; index < CILIUM_SOCKET_LB_RECORDS; index++) {
        u32 base = 8U + index * CILIUM_SOCKET_LB_RECORD_SIZE;
        u32 src_ip = micro_read_u32_le(data, base);
        u32 dst_ip = micro_read_u32_le(data, base + 4U);
        u16 sport = micro_read_u16_le(data, base + 8U);
        u16 dport = micro_read_u16_le(data, base + 10U);
        u8 proto = data[base + 12U];
        u8 flags = data[base + 13U];
        u16 svc_count = micro_read_u16_le(data, base + 14U);
        u32 cookie = micro_read_u32_le(data, base + 16U);
        u32 scope = micro_read_u32_le(data, base + 20U);
        u32 is_l4 = proto == 6U || proto == 17U;
        u32 is_nodeport = dport >= CILIUM_NODEPORT_MIN && dport <= CILIUM_NODEPORT_MAX;
        u32 wildcard = (flags & 2U) != 0U;
        u32 service_ip = wildcard ? 0U : dst_ip;
        u32 hash = cookie ^ src_ip ^ service_ip ^ ((u32)sport << 16U) ^ dport;

        if (is_l4 == 0U || svc_count == 0U) {
            acc ^= ((u64)proto << 32U) | dport;
            continue;
        }
        if (is_nodeport == 0U && wildcard == 0U) {
            acc += ((u64)dst_ip << 16U) ^ sport;
            continue;
        }

        hash ^= micro_rotl32(hash + scope + flags, (proto & 7U) + 1U);
        u32 backend = (hash % svc_count) + 1U;
        if ((flags & 4U) != 0U) {
            backend ^= scope + 1U;
        }

        acc += ((u64)service_ip << 16U) ^ ((u64)dport << 32U) ^ proto;
        acc ^= micro_rotl64(((u64)backend << 48U) | hash, (index & 7U) + 1U);
    }

    *out = acc;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    cilium_socket_lb_service_select_xdp,
    bench_cilium_socket_lb_service_select,
    cilium_socket_lb_service_select_input_value,
    CILIUM_SOCKET_LB_INPUT_SIZE)
