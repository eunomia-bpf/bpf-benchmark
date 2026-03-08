#include "common.h"

static __always_inline int bench_packet_parse_vlans_tcpopts(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, 14U)) {
        return -1;
    }

    u32 cursor = 14U;
    u16 ethertype = micro_read_u16_be(data, 12U);
    u16 vlan0 = 0;
    u16 vlan1 = 0;
    u32 vlan_count = 0;

    for (u32 depth = 0; depth < 2U; depth++) {
        if (ethertype != 0x8100U && ethertype != 0x88A8U) {
            break;
        }
        if (!micro_has_bytes(len, cursor, 4U)) {
            return -1;
        }
        if (vlan_count == 0U) {
            vlan0 = micro_read_u16_be(data, cursor);
        } else {
            vlan1 = micro_read_u16_be(data, cursor);
        }
        ethertype = micro_read_u16_be(data, cursor + 2U);
        vlan_count++;
        cursor += 4U;
    }

    if (ethertype != 0x0800U) {
        return -1;
    }
    if (!micro_has_bytes(len, cursor, 20U)) {
        return -1;
    }

    u8 ver_ihl = data[cursor];
    u8 version = ver_ihl >> 4;
    u8 ihl_words = ver_ihl & 0x0FU;
    if (version != 4U || ihl_words < 5U) {
        return -1;
    }

    u32 ip_header_len = (u32)ihl_words * 4U;
    if (!micro_has_bytes(len, cursor, ip_header_len)) {
        return -1;
    }

    u16 total_len = micro_read_u16_be(data, cursor + 2U);
    u8 protocol = data[cursor + 9U];
    u32 src_ip = micro_read_u32_be(data, cursor + 12U);
    u32 dst_ip = micro_read_u32_be(data, cursor + 16U);
    if (protocol != 6U) {
        return -1;
    }

    u32 tcp = cursor + ip_header_len;
    if (!micro_has_bytes(len, tcp, 20U)) {
        return -1;
    }

    u16 src_port = micro_read_u16_be(data, tcp);
    u16 dst_port = micro_read_u16_be(data, tcp + 2U);
    u8 data_offset_words = data[tcp + 12U] >> 4;
    if (data_offset_words < 5U) {
        return -1;
    }

    u32 tcp_header_len = (u32)data_offset_words * 4U;
    if (!micro_has_bytes(len, tcp, tcp_header_len)) {
        return -1;
    }

    u32 options_cursor = tcp + 20U;
    u32 options_end = tcp + tcp_header_len;
    u64 option_acc = 0;
    for (u32 step = 0; step < 10U && options_cursor < options_end; step++) {
        if (!micro_has_bytes(len, options_cursor, 1U)) {
            return -1;
        }

        u32 option_start = options_cursor;
        u8 kind = data[options_cursor];
        option_acc += (u64)kind << ((step & 7U) * 8U);
        options_cursor++;

        if (kind == 0U) {
            break;
        }
        if (kind == 1U) {
            continue;
        }
        if (!micro_has_bytes(len, options_cursor, 1U)) {
            return -1;
        }

        u8 option_len = data[options_cursor];
        if (option_len < 2U) {
            return -1;
        }
        if (!micro_has_bytes(len, option_start, option_len)) {
            return -1;
        }

        if (kind == 2U && option_len >= 4U) {
            option_acc += micro_read_u16_be(data, options_cursor + 1U);
        } else if (kind == 3U && option_len >= 3U) {
            option_acc ^= (u64)data[options_cursor + 1U] << 32U;
        } else if (kind == 4U && option_len >= 2U) {
            option_acc += 0x40000000ULL;
        }

        for (u32 byte = 2U; byte < option_len; byte++) {
            option_acc ^= (u64)data[option_start + byte] << ((byte & 7U) * 8U);
        }

        options_cursor = option_start + option_len;
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

DEFINE_PACKET_BACKED_XDP_BENCH(packet_parse_vlans_tcpopts_xdp, bench_packet_parse_vlans_tcpopts)
