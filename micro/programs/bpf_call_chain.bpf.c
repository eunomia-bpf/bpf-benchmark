#include "common.h"

#define BPF_CALL_CHAIN_INPUT_SIZE 64U
#define BPF_CALL_CHAIN_ROUNDS 64U

/* Three __noinline subprograms to force BPF-to-BPF calls */
static __noinline u64 sub_hash(u64 val, u64 mix)
{
    val ^= val >> 17;
    val *= 0xbf58476d1ce4e5b9ULL;
    val ^= val >> 31;
    val *= 0x94d049bb133111ebULL;
    val ^= val >> 32;
    return val ^ mix;
}

static __noinline u64 sub_fold(u64 acc, const u8 *data, u32 offset)
{
    u64 word = micro_read_u64_le(data, offset);
    acc = acc * 31 + word;
    acc ^= acc >> 13;
    return acc;
}

static __noinline u64 sub_combine(u64 a, u64 b, u64 round)
{
    u64 mixed = a ^ (b << 5) ^ (b >> 3);
    mixed += round * 0x9e3779b97f4a7c15ULL;
    mixed ^= mixed >> 29;
    return mixed;
}

static __always_inline int bench_bpf_call_chain(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, BPF_CALL_CHAIN_INPUT_SIZE)) {
        return -1;
    }

    u64 acc = micro_read_u64_le(data, 0);
    u64 mix = micro_read_u64_le(data, 8);
    u32 offset = 0;

    for (u32 i = 0; i < BPF_CALL_CHAIN_ROUNDS; i++) {
        /* Each iteration calls all 3 subprograms */
        u64 h = sub_hash(acc, mix + i);
        u64 f = sub_fold(acc, data, offset);
        acc = sub_combine(h, f, (u64)i);
        offset += 8;
        if (offset >= (BPF_CALL_CHAIN_INPUT_SIZE - 8 + 1)) {
            offset -= (BPF_CALL_CHAIN_INPUT_SIZE - 8 + 1);
        }
    }

    *out = acc;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    bpf_call_chain_xdp,
    bench_bpf_call_chain,
    bpf_call_chain_input_value,
    BPF_CALL_CHAIN_INPUT_SIZE)
