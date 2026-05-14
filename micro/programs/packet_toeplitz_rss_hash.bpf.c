#include "common.h"

#define PACKET_TOEPLITZ_RSS_INPUT_SIZE 54U
#define PACKET_TOEPLITZ_TUPLE_BITS 104U

static __always_inline u8 packet_toeplitz_key_byte(u32 index)
{
    switch (index) {
    case 0U: return 0x6DU;
    case 1U: return 0x5AU;
    case 2U: return 0x56U;
    case 3U: return 0xDAU;
    case 4U: return 0x25U;
    case 5U: return 0x5BU;
    case 6U: return 0x0EU;
    case 7U: return 0xC2U;
    case 8U: return 0x41U;
    case 9U: return 0x67U;
    case 10U: return 0x25U;
    case 11U: return 0x3DU;
    case 12U: return 0x43U;
    case 13U: return 0xA3U;
    case 14U: return 0x8FU;
    case 15U: return 0xB0U;
    case 16U: return 0xD0U;
    default: return 0U;
    }
}

static __always_inline u32 packet_toeplitz_word(u32 bit)
{
    u32 byte = bit >> 3U;
    u32 shift = bit & 7U;
    u32 word = ((u32)packet_toeplitz_key_byte(byte) << 24U) |
               ((u32)packet_toeplitz_key_byte(byte + 1U) << 16U) |
               ((u32)packet_toeplitz_key_byte(byte + 2U) << 8U) |
               (u32)packet_toeplitz_key_byte(byte + 3U);

    if (shift != 0U) {
        word = (word << shift) |
               ((u32)packet_toeplitz_key_byte(byte + 4U) >> (8U - shift));
    }
    return word;
}

static __always_inline u8
packet_toeplitz_tuple_byte(const u8 *data, u32 ip, u32 tcp, u32 index)
{
    if (index < 4U) {
        return data[ip + 12U + index];
    }
    if (index < 8U) {
        return data[ip + 16U + (index - 4U)];
    }
    if (index < 10U) {
        return data[tcp + (index - 8U)];
    }
    if (index < 12U) {
        return data[tcp + 2U + (index - 10U)];
    }
    return data[ip + 9U];
}

static __always_inline int
bench_packet_toeplitz_rss_hash(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, PACKET_TOEPLITZ_RSS_INPUT_SIZE)) {
        return -1;
    }
    if (micro_read_u16_be(data, 12U) != 0x0800U) {
        return -1;
    }

    u32 ip = 14U;
    u8 ihl = (data[ip] & 0x0FU) * 4U;
    if (ihl != 20U || data[ip + 9U] != 6U) {
        return -1;
    }
    u32 tcp = ip + ihl;
    if (!micro_has_bytes(len, tcp, 20U)) {
        return -1;
    }

    u32 hash = 0U;
    for (u32 bit = 0; bit < PACKET_TOEPLITZ_TUPLE_BITS; bit++) {
        u8 tuple = packet_toeplitz_tuple_byte(data, ip, tcp, bit >> 3U);
        if ((tuple & (0x80U >> (bit & 7U))) != 0U) {
            hash ^= packet_toeplitz_word(bit);
        }
    }

    u32 src = micro_read_u32_be(data, ip + 12U);
    u32 dst = micro_read_u32_be(data, ip + 16U);
    u16 sport = micro_read_u16_be(data, tcp);
    u16 dport = micro_read_u16_be(data, tcp + 2U);
    u64 acc = ((u64)hash << 32U) | (hash ^ src ^ dst);
    acc ^= micro_rotl64(((u64)sport << 48U) | ((u64)dport << 32U) |
                            ((u64)src ^ dst),
                        (hash & 7U) + 1U);

    *out = acc;
    return 0;
}

DEFINE_FIXED_PACKET_BACKED_XDP_BENCH(
    packet_toeplitz_rss_hash_xdp,
    bench_packet_toeplitz_rss_hash,
    PACKET_TOEPLITZ_RSS_INPUT_SIZE)
