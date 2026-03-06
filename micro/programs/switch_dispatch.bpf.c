#include "common.h"

#define SWITCH_DISPATCH_COUNT 128U
#define SWITCH_DISPATCH_INPUT_SIZE (4U + SWITCH_DISPATCH_COUNT * 4U)

struct switch_dispatch_input_value {
    unsigned char data[SWITCH_DISPATCH_INPUT_SIZE];
};

struct {
    __uint(type, BPF_MAP_TYPE_ARRAY);
    __uint(max_entries, 1);
    __type(key, __u32);
    __type(value, struct switch_dispatch_input_value);
} input_map SEC(".maps");

static __always_inline u32 switch_value(u32 value)
{
    switch (value) {
    case 0: return 56;
    case 1: return 43;
    case 2: return 57;
    case 3: return 28;
    case 4: return 14;
    case 5: return 61;
    case 6: return 10;
    case 7: return 58;
    case 8: return 2;
    case 9: return 63;
    case 10: return 49;
    case 11: return 36;
    case 12: return 19;
    case 13: return 42;
    case 14: return 37;
    case 15: return 46;
    case 16: return 34;
    case 17: return 62;
    case 18: return 47;
    case 19: return 6;
    case 20: return 29;
    case 21: return 21;
    case 22: return 15;
    case 23: return 40;
    case 24: return 38;
    case 25: return 26;
    case 26: return 17;
    case 27: return 41;
    case 28: return 33;
    case 29: return 31;
    case 30: return 23;
    case 31: return 52;
    case 32: return 25;
    case 33: return 39;
    case 34: return 11;
    case 35: return 27;
    case 36: return 53;
    case 37: return 4;
    case 38: return 24;
    case 39: return 48;
    case 40: return 32;
    case 41: return 50;
    case 42: return 7;
    case 43: return 35;
    case 44: return 8;
    case 45: return 44;
    case 46: return 51;
    case 47: return 59;
    case 48: return 45;
    case 49: return 0;
    case 50: return 9;
    case 51: return 3;
    case 52: return 13;
    case 53: return 20;
    case 54: return 30;
    case 55: return 18;
    case 56: return 1;
    case 57: return 54;
    case 58: return 22;
    case 59: return 16;
    case 60: return 60;
    case 61: return 5;
    case 62: return 12;
    case 63: return 55;
    default: return 114514U;
    }
}

static __always_inline int bench_switch_dispatch(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, 4)) {
        return -1;
    }

    u32 count = micro_read_u32_le(data, 0);

    if (count != SWITCH_DISPATCH_COUNT) {
        return -1;
    }
    if (!micro_has_bytes(len, 4, SWITCH_DISPATCH_COUNT * 4U)) {
        return -1;
    }

    u64 hash = 0;
    for (u32 i = 0; i < SWITCH_DISPATCH_COUNT; i++) {
        hash ^= switch_value(micro_read_u32_le(data, 4 + i * 4U));
    }

    *out = hash;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    switch_dispatch_xdp,
    bench_switch_dispatch,
    switch_dispatch_input_value,
    SWITCH_DISPATCH_INPUT_SIZE)
