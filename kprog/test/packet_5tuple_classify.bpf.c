/*
 * Stage 2 test: HASH map keyed by a 16-byte 5-tuple struct.
 *
 * Real-world shape: simplified connection classifier. We read the
 * 5-tuple fields out of the packet (offsets 16..28 -- well outside the
 * 0..7 result-write zone so input bytes survive across inner-repeat
 * iterations and the lookup key stays stable). Zero-filled test input
 * means the key is all zero in practice; we populate that key with a
 * known verdict before the lookup so both BPF JIT and native paths
 * read back the same value.
 *
 * Maps: 1 (HASH).   Helpers: 0.   Inline-eligible: yes.
 */
#include "include/native_helpers.h"

struct flow_key {
    __u32 src_ip;
    __u32 dst_ip;
    __u16 src_port;
    __u16 dst_port;
    __u8  proto;
    __u8  _pad[3];
};

struct {
    __uint(type, BPF_MAP_TYPE_HASH);
    __uint(max_entries, 1024);
    __type(key, struct flow_key);
    __type(value, __u32);
} flow_table SEC(".maps");

SEC("xdp") int packet_5tuple_classify(struct xdp_md *ctx)
{
    u8 *data = (u8 *)(long)ctx->data;
    u8 *data_end = (u8 *)(long)ctx->data_end;
    if (data + 32 > data_end) {
        return XDP_ABORTED;
    }

    struct flow_key fk = {};
    fk.src_ip   = *(__u32 *)(data + 16);
    fk.dst_ip   = *(__u32 *)(data + 20);
    fk.src_port = *(__u16 *)(data + 24);
    fk.dst_port = *(__u16 *)(data + 26);
    fk.proto    = data[28];

    __u32 verdict = 0xCAFEBABE;
    bpf_map_update_elem(&flow_table, &fk, &verdict, 0);

    __u32 *got = bpf_map_lookup_elem(&flow_table, &fk);
    __u64 out = got ? (__u64)*got : 0;
    micro_write_u64_le(data, out);
    return XDP_PASS;
}

char LICENSE[] SEC("license") = "GPL";
