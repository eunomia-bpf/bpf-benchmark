#include "common.h"

#define TRACEE_SYSCALL_LOOKUP_COUNT 64U
#define TRACEE_SYSCALL_LOOKUP_INPUT_SIZE (4U + TRACEE_SYSCALL_LOOKUP_COUNT * 4U)

static __always_inline u64 tracee_syscall_name_sig(u32 syscall_id)
{
    switch (syscall_id) {
    case 0U: return 0x0000000072656164ULL;
    case 1U: return 0x0000006574697277ULL;
    case 2U: return 0x000000006E65706FULL;
    case 3U: return 0x00000065736F6C63ULL;
    case 9U: return 0x0000000070616D6DULL;
    case 12U: return 0x000000006B72626BULL;
    case 39U: return 0x0000006469707467ULL;
    case 56U: return 0x0000656E6F6C6355ULL;
    case 57U: return 0x000000006B726F66ULL;
    case 59U: return 0x0000657663657865ULL;
    case 60U: return 0x0000000074697865ULL;
    case 61U: return 0x0000347469617755ULL;
    case 80U: return 0x0000000069646863ULL;
    case 87U: return 0x00006B6E696C6E75ULL;
    case 89U: return 0x0000006B6E696C55ULL;
    case 158U: return 0x006C74635F68637261ULL;
    case 202U: return 0x0000786574756655ULL;
    case 217U: return 0x0000646461746567ULL;
    case 257U: return 0x000074616E65706FULL;
    case 263U: return 0x0074616B6E696C6E75ULL;
    case 281U: return 0x0074613274617473ULL;
    case 291U: return 0x647466656E676973ULL;
    case 321U: return 0x0000000000706662ULL;
    case 332U: return 0x0000000078746173ULL;
    default: return 0ULL;
    }
}

static __always_inline int
bench_tracee_syscall_name_table_lookup(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, TRACEE_SYSCALL_LOOKUP_INPUT_SIZE)) {
        return -1;
    }

    u32 count = micro_read_u32_le(data, 0U);
    if (count != TRACEE_SYSCALL_LOOKUP_COUNT) {
        return -1;
    }

    u64 acc = 0x6A09E667F3BCC909ULL;
    for (u32 index = 0; index < TRACEE_SYSCALL_LOOKUP_COUNT; index++) {
        u32 syscall_id = micro_read_u32_le(data, 4U + index * 4U);
        u64 sig = tracee_syscall_name_sig(syscall_id);

        if (sig != 0U) {
            acc += micro_rotl64(sig ^ syscall_id, (index & 7U) + 1U);
            acc ^= (u64)(syscall_id & 0xFFU) << ((index & 7U) * 8U);
        } else {
            acc ^= (u64)syscall_id * 0x9E3779B185EBCA87ULL;
        }
    }

    *out = acc;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    tracee_syscall_name_table_lookup_xdp,
    bench_tracee_syscall_name_table_lookup,
    tracee_syscall_name_table_lookup_input_value,
    TRACEE_SYSCALL_LOOKUP_INPUT_SIZE)
