#include "common.h"

static __always_inline int
micro_parse_tcp_options(const u8 *options_cursor, const u8 *options_end, const u8 *data_end, u64 *out)
{
    if (options_cursor + 12U > options_end || options_cursor + 12U > data_end) {
        return -1;
    }

    const u8 *options = options_cursor;
    u64 option_acc = 0;

    if (options[0] != 2U || options[1] < 4U) {
        return -1;
    }
    option_acc += (u64)options[0];
    option_acc += micro_read_u16_be(options, 2U);
    option_acc ^= (u64)options[2U] << 16U;
    option_acc ^= (u64)options[3U] << 24U;

    if (options[4] != 1U) {
        return -1;
    }
    option_acc += (u64)options[4U] << 8U;

    if (options[5] != 3U || options[6] < 3U) {
        return -1;
    }
    option_acc += (u64)options[5U] << 16U;
    option_acc ^= (u64)options[7U] << 32U;
    option_acc ^= (u64)options[7U] << 16U;

    if (options[8] != 4U || options[9] < 2U) {
        return -1;
    }
    option_acc += (u64)options[8U] << 24U;
    option_acc += 0x40000000ULL;

    if (options[10] != 1U) {
        return -1;
    }
    option_acc += (u64)options[10U] << 32U;

    option_acc += (u64)options[11U] << 40U;
    *out = option_acc;
    return 0;
}

static __always_inline int
bench_packet_parse_vlans_tcpopts(const u8 *data, const u8 *data_end, u64 *out)
{
    if (data + 14U > data_end) {
        return -1;
    }

    const u8 *cursor = data + 14U;
    u16 ethertype = micro_read_u16_be(data, 12U);
    u16 vlan0 = 0;
    u16 vlan1 = 0;
    u32 vlan_count = 0;

    for (u32 depth = 0; depth < 2U; depth++) {
        if (ethertype != 0x8100U && ethertype != 0x88A8U) {
            break;
        }
        if (cursor + 4U > data_end) {
            return -1;
        }
        if (vlan_count == 0U) {
            vlan0 = micro_read_u16_be(cursor, 0U);
        } else {
            vlan1 = micro_read_u16_be(cursor, 0U);
        }
        ethertype = micro_read_u16_be(cursor, 2U);
        vlan_count++;
        cursor += 4U;
    }

    if (ethertype != 0x0800U) {
        return -1;
    }

    const u8 *ip = cursor;
    if (ip + 20U > data_end) {
        return -1;
    }

    u8 ver_ihl = ip[0];
    u8 version = ver_ihl >> 4;
    u8 ihl_words = ver_ihl & 0x0FU;
    if (version != 4U || ihl_words < 5U) {
        return -1;
    }

    u32 ip_header_len = (u32)ihl_words * 4U;
    if (ip + ip_header_len > data_end) {
        return -1;
    }

    u16 total_len = micro_read_u16_be(ip, 2U);
    u8 protocol = ip[9U];
    u32 src_ip = micro_read_u32_be(ip, 12U);
    u32 dst_ip = micro_read_u32_be(ip, 16U);
    if (protocol != 6U) {
        return -1;
    }

    const u8 *tcp = ip + ip_header_len;
    if (tcp + 20U > data_end) {
        return -1;
    }

    u16 src_port = micro_read_u16_be(tcp, 0U);
    u16 dst_port = micro_read_u16_be(tcp, 2U);
    u8 data_offset_words = tcp[12U] >> 4;
    if (data_offset_words < 5U) {
        return -1;
    }

    u32 tcp_header_len = (u32)data_offset_words * 4U;
    if (tcp + tcp_header_len > data_end) {
        return -1;
    }

    u64 option_acc = 0;
    if (micro_parse_tcp_options(tcp + 20U, tcp + tcp_header_len, data_end, &option_acc) < 0) {
        return -1;
    }

    u64 acc = total_len;
    acc += (u64)src_port + dst_port;
    acc ^= (u64)src_ip;
    acc += (u64)dst_ip;
    acc ^= ((u64)vlan0 << 16U) | vlan1;
    acc += ((u64)vlan_count << 40U) |
           ((u64)protocol << 32U) |
           ((u64)ip_header_len << 8U) |
           tcp_header_len;
    acc ^= micro_rotl64(option_acc, vlan_count + 5U);

    *out = acc;
    return 0;
}

SEC("xdp") int packet_parse_vlans_tcpopts_xdp(struct xdp_md *ctx)
{
    u8 *data = (u8 *)(long)ctx->data;
    u8 *data_end = (u8 *)(long)ctx->data_end;
    u8 *payload;
    u64 result = 0;

    if (data > data_end) {
        return XDP_ABORTED;
    }

    payload = data + 8U;
    if (payload > data_end) {
        return XDP_ABORTED;
    }

    if (bench_packet_parse_vlans_tcpopts(payload, data_end, &result) < 0) {
        return XDP_ABORTED;
    }

    micro_write_u64_le(data, result);
    return XDP_PASS;
}

char LICENSE[] SEC("license") = "GPL";
