/*
 * Negative kprog proof fixture: the native program reads a packet byte
 * without first proving that the byte is within data_end.  The generated
 * simulator artifact must preserve that unsafe access so the BPF verifier
 * rejects it.
 */
#include "include/native_helpers.h"

SEC("xdp") int unchecked_packet_read(struct xdp_md *ctx)
{
    u8 *data = (u8 *)(long)ctx->data;
    return data[64];
}

char LICENSE[] SEC("license") = "GPL";
