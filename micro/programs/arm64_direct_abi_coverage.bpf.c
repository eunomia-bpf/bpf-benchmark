#include "common.h"

struct arm64_direct_abi_slot {
    u8 byte_value;
    u8 pad0;
    u16 half_value;
    u32 word_value;
    u64 dword_value;
};

static __always_inline u64
consume_arm64_direct_abi_slot(const struct arm64_direct_abi_slot *slot)
{
    return (u64)slot->byte_value ^ ((u64)slot->half_value << 8) ^
           ((u64)slot->word_value << 24) ^
           micro_rotl64(slot->dword_value, 17);
}

static __always_inline int
bench_arm64_direct_abi_coverage(const u8 *data, u32 len, u64 *out)
{
    struct arm64_direct_abi_slot slot;
    u8 byte_value = 0x12;
    u16 half_value = 0x3456;
    u32 word_value = 0x789abcde;
    u64 dword_value = 0x1122334455667788ULL;

    (void)data;
    if (!micro_has_bytes(len, 0, 1)) {
        return -1;
    }

    __asm__ __volatile__("" : "+r"(byte_value), "+r"(half_value),
                         "+r"(word_value), "+r"(dword_value) :: "memory");
    slot.byte_value = byte_value;
    slot.half_value = half_value;
    slot.word_value = word_value;
    slot.dword_value = dword_value;
    __asm__ __volatile__("" : : "m"(slot) : "memory");

    *out = consume_arm64_direct_abi_slot(&slot);
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(arm64_direct_abi_coverage_xdp,
                              bench_arm64_direct_abi_coverage,
                              arm64_direct_abi_coverage_input_value, 64U)
