from __future__ import annotations

import struct
from pathlib import Path


ROOT_DIR = Path(__file__).resolve().parents[2]
GENERATED_INPUT_DIR = ROOT_DIR / "micro" / "generated-inputs"
MASK64 = (1 << 64) - 1


def _lcg(state: int) -> int:
    return (state * 6364136223846793005 + 1442695040888963407) & MASK64


def generate_simple(output: Path) -> dict[str, int]:
    output.write_bytes(bytes(range(64)))
    return {"bytes": 64}


def generate_simple_packet(output: Path) -> dict[str, int]:
    return generate_simple(output)


def generate_bitcount(output: Path) -> dict[str, int]:
    count = 256
    seed = 0x00C0FFEE
    state = 0x1234_5678_9ABC_DEF0

    blob = bytearray(struct.pack("<II", count, seed))
    for index in range(count):
        state = _lcg(state)
        value = state ^ ((index + 1) * 0x9E37_79B9_7F4A_7C15)
        blob.extend(struct.pack("<Q", value & MASK64))

    output.write_bytes(blob)
    return {"count": count, "seed": seed}


def generate_binary_search(output: Path) -> dict[str, int]:
    data_len = 32
    query_len = 16

    data = [index * 3 + 7 for index in range(data_len)]
    queries = []
    for index in range(query_len):
        if index % 3 == 0:
            queries.append(data[(index * 17) % data_len])
        else:
            queries.append((index * 19) + 5)

    blob = bytearray(struct.pack("<II", data_len, query_len))
    for value in data:
        blob.extend(struct.pack("<Q", value))
    for value in queries:
        blob.extend(struct.pack("<Q", value))

    output.write_bytes(blob)
    return {"data_len": data_len, "query_len": query_len}


def generate_checksum(output: Path) -> dict[str, int]:
    rounds = 32
    word_count = 512
    state = 0xA5A5_5A5A_1234_9876

    blob = bytearray(struct.pack("<II", rounds, word_count))
    for index in range(word_count):
        state = _lcg(state)
        word = ((state >> 16) ^ (index * 257)) & 0xFFFF
        blob.extend(struct.pack("<H", word))

    output.write_bytes(blob)
    return {"rounds": rounds, "word_count": word_count}


def generate_hash_chain(output: Path) -> dict[str, int]:
    rounds = 16
    word_count = 8
    state = 0xFACE_CAFE_1234_5678

    blob = bytearray(struct.pack("<II", rounds, word_count))
    for index in range(word_count):
        state = _lcg(state ^ ((index + 1) * 0x9E37_79B9_7F4A_7C15))
        word = state ^ ((index + 1) * 0xD134_2543_DE82_EF95)
        blob.extend(struct.pack("<Q", word & MASK64))

    output.write_bytes(blob)
    return {"rounds": rounds, "word_count": word_count}


def _write_be16(packet: bytearray, offset: int, value: int) -> None:
    packet[offset] = (value >> 8) & 0xFF
    packet[offset + 1] = value & 0xFF


def _write_be32(packet: bytearray, offset: int, value: int) -> None:
    packet[offset] = (value >> 24) & 0xFF
    packet[offset + 1] = (value >> 16) & 0xFF
    packet[offset + 2] = (value >> 8) & 0xFF
    packet[offset + 3] = value & 0xFF


def _memcmp_prefix_pattern_byte(index: int) -> int:
    return (((index * 29) ^ (index << 2) ^ 0xA5) + 0x11) & 0xFF


def generate_packet_parse(output: Path) -> dict[str, int]:
    packet_count = 54
    packet_size = 64
    blob = bytearray(struct.pack("<II", packet_count, packet_size))

    for index in range(packet_count):
        packet = bytearray(packet_size)
        packet[12] = 0x08
        packet[13] = 0x00
        packet[14] = 0x45
        packet[15] = 0x00
        _write_be16(packet, 16, 40 + (index % 4) * 4)
        packet[22] = 64
        packet[23] = 6 if index % 2 == 0 else 17
        packet[26:30] = bytes([10, 0, index & 0xFF, (index * 3) & 0xFF])
        packet[30:34] = bytes([10, 1, (index * 5) & 0xFF, (index * 7) & 0xFF])
        _write_be16(packet, 34, 10000 + index)
        _write_be16(packet, 36, 20000 + index * 2)
        _write_be16(packet, 38, 24 + (index % 8))
        blob.extend(packet)

    output.write_bytes(blob)
    return {"packet_count": packet_count, "packet_size": packet_size}


def generate_branch_layout(output: Path) -> dict[str, int]:
    count = 432
    hot_threshold = 900

    blob = bytearray(struct.pack("<II", count, hot_threshold))
    for index in range(count):
        if index % 10 == 0:
            value = 1000 + index
        else:
            value = (index * 37) % hot_threshold
        blob.extend(struct.pack("<Q", value))

    output.write_bytes(blob)
    return {"count": count, "hot_threshold": hot_threshold}


def generate_branch_layout_predictable(output: Path) -> dict[str, int]:
    count = 432
    hot_threshold = 900

    blob = bytearray(struct.pack("<II", count, hot_threshold))
    for index in range(count):
        value = ((index * 37) + 11) % hot_threshold
        blob.extend(struct.pack("<Q", value))

    output.write_bytes(blob)
    return {"count": count, "hot_threshold": hot_threshold, "distribution": "predictable"}


def generate_branch_layout_random(output: Path) -> dict[str, int]:
    count = 432
    hot_threshold = 900
    state = 0x1234_5678_9ABC_DEF0

    blob = bytearray(struct.pack("<II", count, hot_threshold))
    for index in range(count):
        state = _lcg(state ^ ((index + 1) * 0x9E37_79B9_7F4A_7C15))
        if state & 1:
            value = state % hot_threshold
        else:
            value = hot_threshold + ((state >> 16) % 2048)
        blob.extend(struct.pack("<Q", value))

    output.write_bytes(blob)
    return {"count": count, "hot_threshold": hot_threshold, "distribution": "random"}


def generate_spill_pressure(output: Path) -> dict[str, int]:
    count = 64
    seed = 0x1020_3040
    state = 0x0F0E_0D0C_0B0A_0908

    blob = bytearray(struct.pack("<II", count, seed))
    for index in range(count):
        state = _lcg(state)
        value = state ^ ((index + 11) * 0x9E37_79B9_7F4A_7C15)
        blob.extend(struct.pack("<Q", value & MASK64))

    output.write_bytes(blob)
    return {"count": count, "seed": seed}


def generate_bounds_ladder(output: Path) -> dict[str, int]:
    record_count = 32
    record_size = 32
    state = 0x55AA_55AA_1234_9876

    blob = bytearray(struct.pack("<II", record_count, record_size))
    for index in range(record_count):
        state = _lcg(state)
        tag = (state ^ index) & 0xFFFFFFFF
        state = _lcg(state)
        left = state & MASK64
        state = _lcg(state)
        span = ((state >> 16) ^ (index * 13)) & 0xFFFFFFFF
        state = _lcg(state)
        right = state & MASK64
        state = _lcg(state)
        tail = (state ^ (index * 0xA5A5_A5A5_A5A5_A5A5)) & MASK64
        blob.extend(struct.pack("<I", tag))
        blob.extend(struct.pack("<Q", left))
        blob.extend(struct.pack("<I", span))
        blob.extend(struct.pack("<Q", right))
        blob.extend(struct.pack("<Q", tail))

    output.write_bytes(blob)
    return {"record_count": record_count, "record_size": record_size}


def generate_memory_pair_sum(output: Path) -> dict[str, int]:
    left = 0x1234_5678_9ABC_DEF0
    right = 0x0FED_CBA9_8765_4321
    output.write_bytes(struct.pack("<QQ", left, right))
    return {"left": left, "right": right}


def _generate_load_width_blob(output: Path) -> dict[str, int]:
    count = 256
    bytes_per_iter = 4
    state = 0x0DEC_0DED_C001_D00D

    blob = bytearray(struct.pack("<II", count, bytes_per_iter))
    for index in range(count):
        state = _lcg(state)
        value = ((state >> 24) ^ ((index + 1) * 0x9E37_79B9)) & 0xFFFFFFFF
        blob.extend(struct.pack("<I", value))

    output.write_bytes(blob)
    return {"count": count, "bytes_per_iter": bytes_per_iter}


def generate_load_word32(output: Path) -> dict[str, int]:
    return _generate_load_width_blob(output)


def generate_load_byte(output: Path) -> dict[str, int]:
    return _generate_load_width_blob(output)


def generate_log2_fold(output: Path) -> dict[str, int]:
    count = 128
    seed = 0xABCD_1234
    state = 0x9988_7766_5544_3322

    blob = bytearray(struct.pack("<II", count, seed))
    for index in range(count):
        state = _lcg(state)
        value = (state | 1) ^ ((index + 3) * 0x9E37_79B9_7F4A_7C15)
        blob.extend(struct.pack("<Q", value & MASK64))

    output.write_bytes(blob)
    return {"count": count, "seed": seed}


def generate_switch_dispatch(output: Path) -> dict[str, int]:
    count = 128
    state = 0x1020_3040_5060_7080

    blob = bytearray(struct.pack("<I", count))
    for index in range(count):
        state = _lcg(state)
        value = ((state >> 32) ^ index) & 0x3F
        blob.extend(struct.pack("<I", value))

    output.write_bytes(blob)
    return {"count": count}


def generate_fibonacci_iter(output: Path) -> dict[str, int]:
    rounds = 1024
    mix = 0x13579BDF
    seed = 0x1122_3344_5566_7788

    output.write_bytes(struct.pack("<IIQ", rounds, mix, seed))
    return {"rounds": rounds, "mix": mix}


def generate_fibonacci_iter_packet(output: Path) -> dict[str, int]:
    # Same as fibonacci_iter; runner prepends 8-byte result header for packet mode
    return generate_fibonacci_iter(output)


def generate_bpf_call_chain(output: Path) -> dict[str, int]:
    state = 0x1234_5678_9ABC_DEF0
    blob = bytearray()
    for _ in range(8):  # 8 u64 values = 64 bytes
        state = _lcg(state)
        blob.extend(struct.pack("<Q", state & MASK64))
    output.write_bytes(blob)
    return {"bytes": 64}


def _generate_dep_chain(output: Path, count: int, seed: int, salt: int) -> dict[str, int]:
    state = salt & MASK64
    blob = bytearray(struct.pack("<II", count, seed))
    for index in range(count):
        state = _lcg(state)
        value = state ^ ((index + 1) * 0x9E37_79B9_7F4A_7C15) ^ seed
        blob.extend(struct.pack("<Q", value & MASK64))
    output.write_bytes(blob)
    return {"count": count, "seed": seed}


def generate_dep_chain_short(output: Path) -> dict[str, int]:
    return _generate_dep_chain(output, count=64, seed=0x13572468, salt=0xDEAD_BEEF_CAFE_0123)


def generate_dep_chain_long(output: Path) -> dict[str, int]:
    return _generate_dep_chain(output, count=256, seed=0x24681357, salt=0x0123_4567_89AB_CDEF)


def _generate_multi_acc(output: Path, count: int, seed: int, salt: int) -> dict[str, int]:
    state = salt & MASK64
    blob = bytearray(struct.pack("<II", count, seed))
    for index in range(count):
        state = _lcg(state)
        value = state ^ ((index + 5) * 0xD134_2543_DE82_EF95)
        blob.extend(struct.pack("<Q", value & MASK64))
    output.write_bytes(blob)
    return {"count": count, "seed": seed}


def generate_multi_acc_4(output: Path) -> dict[str, int]:
    return _generate_multi_acc(output, count=128, seed=0x31415926, salt=0x1111_2222_3333_4444)


def generate_multi_acc_8(output: Path) -> dict[str, int]:
    return _generate_multi_acc(output, count=128, seed=0x27182818, salt=0x5555_6666_7777_8888)


def generate_fixed_loop_small(output: Path) -> dict[str, int]:
    rounds = 64
    mix = 0x89ABCDEF
    seed = 0x0F1E_2D3C_4B5A_6978
    output.write_bytes(struct.pack("<IIQ", rounds, mix, seed))
    return {"rounds": rounds, "mix": mix}


def generate_fixed_loop_large(output: Path) -> dict[str, int]:
    rounds = 1024
    mix = 0x10203040
    seed = 0x8877_6655_4433_2211
    output.write_bytes(struct.pack("<IIQ", rounds, mix, seed))
    return {"rounds": rounds, "mix": mix}


def _generate_stride_load(output: Path, count: int, stride: int, salt: int) -> dict[str, int]:
    state = salt & MASK64
    blob = bytearray(struct.pack("<II", count, stride))
    for index in range(count):
        state = _lcg(state)
        value = state ^ ((index + 7) * 0xA076_1D64_78BD_642F)
        blob.extend(struct.pack("<Q", value & MASK64))
    output.write_bytes(blob)
    return {"count": count, "stride": stride}


def generate_stride_load_4(output: Path) -> dict[str, int]:
    return _generate_stride_load(output, count=128, stride=4, salt=0xAAAA_BBBB_CCCC_DDDD)


def generate_stride_load_16(output: Path) -> dict[str, int]:
    return _generate_stride_load(output, count=128, stride=16, salt=0x1357_9BDF_2468_ACE0)


def _generate_code_clone(output: Path, count: int, seed: int, salt: int) -> dict[str, int]:
    state = salt & MASK64
    blob = bytearray(struct.pack("<II", count, seed))
    for index in range(count):
        state = _lcg(state)
        value = state ^ ((index + 13) * 0x94D049BB133111EB) ^ (seed << (index & 3))
        blob.extend(struct.pack("<Q", value & MASK64))
    output.write_bytes(blob)
    return {"count": count, "seed": seed}


def generate_code_clone_2(output: Path) -> dict[str, int]:
    return _generate_code_clone(output, count=128, seed=0x10293847, salt=0xCAFEBABE10293847)


def generate_code_clone_8(output: Path) -> dict[str, int]:
    return _generate_code_clone(output, count=128, seed=0x56473829, salt=0x0BADF00D56473829)


def _generate_large_mixed(output: Path, count: int, seed: int, salt: int) -> dict[str, int]:
    state = salt & MASK64
    blob = bytearray(struct.pack("<II", count, seed))
    for index in range(count):
        state = _lcg(state)
        value = state ^ ((index + 1) * 0xD134_2543_DE82_EF95) ^ seed
        blob.extend(struct.pack("<Q", value & MASK64))
    output.write_bytes(blob)
    return {"count": count, "seed": seed}


def generate_large_mixed_500(output: Path) -> dict[str, int]:
    return _generate_large_mixed(output, count=32, seed=0x13572468, salt=0x1111_3333_5555_7777)


def generate_large_mixed_1000(output: Path) -> dict[str, int]:
    return _generate_large_mixed(output, count=32, seed=0x24681357, salt=0x8888_6666_4444_2222)


def _generate_nested_loop_values(output: Path, header: bytes, count: int, salt: int) -> None:
    state = salt & MASK64
    blob = bytearray(header)
    for index in range(count):
        state = _lcg(state)
        value = state ^ ((index + 9) * 0xA076_1D64_78BD_642F)
        blob.extend(struct.pack("<Q", value & MASK64))
    output.write_bytes(blob)


def generate_nested_loop_2(output: Path) -> dict[str, int]:
    outer = 16
    inner = 16
    seed = 0x0123_4567_89AB_CDEF
    _generate_nested_loop_values(
        output,
        struct.pack("<IIQ", outer, inner, seed),
        count=outer * inner,
        salt=0x2222_4444_6666_8888,
    )
    return {"outer": outer, "inner": inner}


def generate_nested_loop_3(output: Path) -> dict[str, int]:
    outer = 8
    middle = 8
    inner = 4
    seed = 0x89AB_CDEF
    _generate_nested_loop_values(
        output,
        struct.pack("<IIII", outer, middle, inner, seed),
        count=outer * middle * inner,
        salt=0x9999_AAAA_BBBB_CCCC,
    )
    return {"outer": outer, "middle": middle, "inner": inner}


def generate_mixed_alu_mem(output: Path) -> dict[str, int]:
    count = 128
    seed = 0x5566_7788
    state = 0x3141_5926_5358_9793

    blob = bytearray(struct.pack("<II", count, seed))
    for index in range(count):
        state = _lcg(state)
        value = state ^ ((index + 21) * 0x94D0_49BB_1331_11EB)
        blob.extend(struct.pack("<Q", value & MASK64))

    output.write_bytes(blob)
    return {"count": count, "seed": seed}


def generate_branch_dense(output: Path) -> dict[str, int]:
    count = 128
    hot_threshold = 480
    state = 0x1357_9BDF_2468_ACE0

    blob = bytearray(struct.pack("<II", count, hot_threshold))
    for index in range(count):
        state = _lcg(state)
        if index % 5 == 0:
            value = hot_threshold + ((state >> 12) & 0x7FF)
        else:
            value = ((state >> 20) ^ (index * 73)) & 0x3FF
        blob.extend(struct.pack("<I", value))

    output.write_bytes(blob)
    return {"count": count, "hot_threshold": hot_threshold}


def generate_bounds_check_heavy(output: Path) -> dict[str, int]:
    record_count = 32
    record_size = 32
    state = 0x0F0F_1E1E_2D2D_3C3C

    blob = bytearray(struct.pack("<II", record_count, record_size))
    for index in range(record_count):
        state = _lcg(state)
        span0 = 4 + (state & 7)
        state = _lcg(state)
        off1 = state & 7
        state = _lcg(state)
        off2 = state & 7
        state = _lcg(state)
        selector = state & 0x1F
        record = bytearray(record_size)
        record[0] = span0 & 0xFF
        record[1] = off1 & 0xFF
        record[2] = off2 & 0xFF
        record[3] = selector & 0xFF
        for offset in range(4, record_size, 8):
            state = _lcg(state)
            value = state ^ ((index + offset) * 0x9E37_79B9_7F4A_7C15)
            width = min(8, record_size - offset)
            record[offset : offset + width] = struct.pack("<Q", value & MASK64)[:width]
        blob.extend(record)

    output.write_bytes(blob)
    return {"record_count": record_count, "record_size": record_size}


def generate_packet_redundant_bounds(output: Path) -> dict[str, int]:
    record_count = 32
    record_size = 24
    state = 0x1020_3040_5060_7080

    blob = bytearray(struct.pack("<II", record_count, record_size))
    for index in range(record_count):
        record = bytearray(record_size)
        state = _lcg(state)
        record[0] = (state ^ index) & 0x03
        state = _lcg(state)
        record[1] = ((state >> 16) ^ (index * 13)) & 0xFF
        record[2] = ((state >> 24) ^ index) & 0xFF
        record[3] = ((state >> 32) ^ (index * 7)) & 0xFF
        for offset in (4, 8, 12, 16):
            state = _lcg(state)
            value = ((state >> 20) ^ ((index + offset) * 0x9E37_79B9)) & 0xFFFFFFFF
            record[offset : offset + 4] = struct.pack("<I", value)
        state = _lcg(state)
        record[20:22] = struct.pack("<H", ((state >> 17) ^ (index * 23)) & 0xFFFF)
        state = _lcg(state)
        record[22:24] = struct.pack("<H", ((state >> 9) ^ (index * 41)) & 0xFFFF)
        blob.extend(record)

    output.write_bytes(blob)
    return {"record_count": record_count, "record_size": record_size}


def generate_const_fold_chain(output: Path) -> dict[str, int]:
    count = 128
    seed = 0x3141_5926
    state = 0x8899_AABB_CCDD_EEFF

    blob = bytearray(struct.pack("<II", count, seed))
    for index in range(count):
        state = _lcg(state ^ ((index + 1) * 0xA076_1D64_78BD_642F))
        value = ((state >> 24) ^ ((index + 3) * 0x9E37_79B9) ^ seed) & 0xFFFFFFFF
        blob.extend(struct.pack("<I", value))

    output.write_bytes(blob)
    return {"count": count, "seed": seed}


def _generate_load_isolation(output: Path, count: int, seed: int) -> dict[str, int]:
    """Generate data for byte-recompose causal isolation pair."""
    state = seed
    blob = bytearray(struct.pack("<II", count, 0))  # count + padding
    for _ in range(count):
        state = _lcg(state)
        blob.extend(struct.pack("<Q", state & MASK64))
    output.write_bytes(blob)
    return {"count": count, "seed": seed}


def generate_load_byte_recompose(output: Path) -> dict[str, int]:
    return _generate_load_isolation(output, count=128, seed=0xBEEF_CAFE_1234_5678)


def generate_load_native_u64(output: Path) -> dict[str, int]:
    return _generate_load_isolation(output, count=128, seed=0xBEEF_CAFE_1234_5678)

def generate_cmov_select(output: Path) -> dict[str, int]:
    groups = 27
    lanes = 4
    count = groups * lanes
    compare_mask = (1 << 63) - 1
    state = 0x1234_5678_9ABC_DEF0

    compare_lhs: list[int] = []
    compare_rhs: list[int] = []
    select_true: list[int] = []
    select_false: list[int] = []

    for index in range(count):
        state = _lcg(state ^ ((index + 1) * 0x9E37_79B9_7F4A_7C15))
        raw_lhs = state & compare_mask
        state = _lcg(state ^ ((index + 1) * 0xD134_2543_DE82_EF95))
        raw_rhs = state & compare_mask

        hi = raw_lhs if raw_lhs >= raw_rhs else raw_rhs
        lo = raw_rhs if raw_lhs >= raw_rhs else raw_lhs
        if hi == lo:
            if hi < compare_mask:
                hi += 1
            elif lo > 0:
                lo -= 1

        if index & 1:
            compare_lhs.append(hi)
            compare_rhs.append(lo)
        else:
            compare_lhs.append(lo)
            compare_rhs.append(hi)

        state = _lcg(state ^ ((index + 1) * 0xA076_1D64_78BD_642F))
        select_true.append((state ^ ((index + 5) * 0xE703_7ED1_A0B4_28DB)) & MASK64)
        state = _lcg(state ^ ((index + 1) * 0x8EBC_6AF0_9C88_C6E3))
        select_false.append((state ^ ((index + 9) * 0x5899_65CC_7537_4CC3)) & MASK64)

    blob = bytearray(struct.pack("<II", count, groups))
    for values in (compare_lhs, compare_rhs, select_true, select_false):
        for value in values:
            blob.extend(struct.pack("<Q", value))

    output.write_bytes(blob)
    return {"count": count, "groups": groups, "lanes": lanes}


def generate_cmov_dense(output: Path) -> dict[str, int]:
    count = 32
    state = 0xC001_D00D_F00D_BAAD

    arrays: list[list[int]] = [[], [], [], []]

    for index in range(count):
        for array_index, values in enumerate(arrays):
            state = _lcg(state ^ ((index + 1) * (array_index + 3) * 0x9E37_79B9_7F4A_7C15))
            values.append(state & MASK64)

    blob = bytearray()
    for values in arrays:
        for value in values:
            blob.extend(struct.pack("<Q", value))

    output.write_bytes(blob)
    return {"count": count, "arrays": len(arrays)}


def generate_cond_select_dense(output: Path) -> dict[str, int]:
    groups = 13
    lanes = 8
    count = groups * lanes
    state = 0xC0DE_CAFE_1234_5678

    compare_lhs: list[int] = []
    compare_rhs: list[int] = []
    on_true: list[int] = []
    on_false: list[int] = []

    for index in range(count):
        state = _lcg(state ^ ((index + 1) * 0x9E37_79B9_7F4A_7C15))
        base = state & ((1 << 61) - 1)
        state = _lcg(state ^ ((index + 5) * 0xA076_1D64_78BD_642F))
        delta = ((state >> 9) & 0xFFFFF) + 1

        if index & 1:
            lhs = base
            rhs = base + delta
        else:
            rhs = base
            lhs = base + delta

        state = _lcg(state ^ ((index + 9) * 0xD134_2543_DE82_EF95))
        compare_lhs.append(lhs & MASK64)
        compare_rhs.append(rhs & MASK64)
        on_true.append((state ^ ((index + 1) * 0x94D0_49BB_1331_11EB)) & MASK64)
        state = _lcg(state ^ ((index + 13) * 0xBF58_476D_1CE4_E5B9))
        on_false.append((state ^ ((index + 1) * 0x369D_EA0F_31A5_3F85)) & MASK64)

    blob = bytearray()
    for values in (compare_lhs, compare_rhs, on_true, on_false):
        for value in values:
            blob.extend(struct.pack("<Q", value))

    output.write_bytes(blob)
    return {"groups": groups, "lanes": lanes, "count": count}


def generate_memcmp_prefix_64(output: Path) -> dict[str, int]:
    scenario_count = 3
    pattern = bytearray(_memcmp_prefix_pattern_byte(index) for index in range(64))

    early_mismatch = bytearray(pattern)
    early_mismatch[0] ^= 0xFF

    late_mismatch = bytearray(pattern)
    late_mismatch[63] ^= 0x3C

    full_match = bytearray(pattern)

    blob = bytearray(struct.pack("<I", scenario_count))
    blob.extend(early_mismatch)
    blob.extend(late_mismatch)
    blob.extend(full_match)
    output.write_bytes(blob)
    return {"scenario_count": scenario_count, "bytes_per_candidate": 64}


def generate_packet_parse_vlans_tcpopts(output: Path) -> dict[str, int]:
    packet = bytearray(74)

    packet[0:6] = bytes([0x00, 0x11, 0x22, 0x33, 0x44, 0x55])
    packet[6:12] = bytes([0x66, 0x77, 0x88, 0x99, 0xAA, 0xBB])
    _write_be16(packet, 12, 0x8100)
    _write_be16(packet, 14, 0x0064)
    _write_be16(packet, 16, 0x88A8)
    _write_be16(packet, 18, 0x00C8)
    _write_be16(packet, 20, 0x0800)

    ip = 22
    packet[ip] = 0x45
    packet[ip + 1] = 0x00
    _write_be16(packet, ip + 2, 52)
    _write_be16(packet, ip + 4, 0x1234)
    _write_be16(packet, ip + 6, 0x4000)
    packet[ip + 8] = 64
    packet[ip + 9] = 6
    _write_be16(packet, ip + 10, 0)
    packet[ip + 12 : ip + 16] = bytes([192, 168, 1, 10])
    packet[ip + 16 : ip + 20] = bytes([10, 1, 2, 3])

    tcp = ip + 20
    _write_be16(packet, tcp, 12345)
    _write_be16(packet, tcp + 2, 443)
    _write_be32(packet, tcp + 4, 0x11223344)
    _write_be32(packet, tcp + 8, 0x55667788)
    packet[tcp + 12] = 0x80
    packet[tcp + 13] = 0x18
    _write_be16(packet, tcp + 14, 0x4000)
    _write_be16(packet, tcp + 16, 0)
    _write_be16(packet, tcp + 18, 0)
    packet[tcp + 20 : tcp + 32] = bytes([2, 4, 0x05, 0xB4, 1, 3, 3, 7, 4, 2, 1, 0])

    output.write_bytes(packet)
    return {"packet_len": len(packet), "vlan_count": 2, "tcp_header_len": 32}


def generate_local_call_fanout(output: Path) -> dict[str, int]:
    record_count = 16
    record_size = 24
    state = 0x0123_4567_89AB_CDEF

    blob = bytearray(struct.pack("<II", record_count, record_size))
    for index in range(record_count):
        selector = index % 4
        state = _lcg(state)
        tag = ((state >> 24) ^ (index * 17)) & 0xFFFFFFFF
        state = _lcg(state)
        left = (state ^ ((index + 1) * 0x9E37_79B9_7F4A_7C15)) & MASK64
        state = _lcg(state)
        right = (state ^ ((index + 7) * 0xD134_2543_DE82_EF95)) & MASK64
        blob.extend(struct.pack("<IIQQ", selector, tag, left, right))

    output.write_bytes(blob)
    return {"record_count": record_count, "record_size": record_size}


def generate_packet_rss_hash(output: Path) -> dict[str, int]:
    packet = bytearray(54)

    packet[0:6] = bytes([0x10, 0x11, 0x12, 0x13, 0x14, 0x15])
    packet[6:12] = bytes([0x20, 0x21, 0x22, 0x23, 0x24, 0x25])
    _write_be16(packet, 12, 0x0800)

    ip = 14
    packet[ip] = 0x45
    packet[ip + 1] = 0x00
    _write_be16(packet, ip + 2, 40)
    _write_be16(packet, ip + 4, 0xBEEF)
    _write_be16(packet, ip + 6, 0x0000)
    packet[ip + 8] = 32
    packet[ip + 9] = 6
    _write_be16(packet, ip + 10, 0)
    packet[ip + 12 : ip + 16] = bytes([172, 16, 1, 9])
    packet[ip + 16 : ip + 20] = bytes([203, 0, 113, 7])

    tcp = ip + 20
    _write_be16(packet, tcp, 1234)
    _write_be16(packet, tcp + 2, 8080)
    _write_be32(packet, tcp + 4, 0x01020304)
    _write_be32(packet, tcp + 8, 0x05060708)
    packet[tcp + 12] = 0x50
    packet[tcp + 13] = 0x12
    _write_be16(packet, tcp + 14, 0x2000)
    _write_be16(packet, tcp + 16, 0)
    _write_be16(packet, tcp + 18, 0)

    output.write_bytes(packet)
    return {"packet_len": len(packet), "protocol": 6}

def generate_imm64_storm(output: Path) -> dict[str, int]:
    state = 0x0123_4567_89AB_CDEF
    words: list[int] = []

    for index in range(4):
        state = _lcg(state ^ ((index + 1) * 0x9E37_79B9_7F4A_7C15))
        words.append((state ^ ((index + 1) * 0xD134_2543_DE82_EF95)) & MASK64)

    output.write_bytes(struct.pack("<QQQQ", *words))
    return {"words": len(words), "bytes": len(words) * 8}


def generate_alu32_64_pingpong(output: Path) -> dict[str, int]:
    count = 64
    seed = 0x3141_5926
    state = 0xCAFE_BABE_1029_3847

    blob = bytearray(struct.pack("<II", count, seed))
    for index in range(count):
        state = _lcg(state ^ ((index + 1) * 0xA076_1D64_78BD_642F))
        value = (state ^ ((index + 1) * 0x9E37_79B9_7F4A_7C15) ^ ((seed + index) << 32)) & MASK64
        blob.extend(struct.pack("<Q", value))

    output.write_bytes(blob)
    return {"count": count, "seed": seed}


def generate_struct_field_cluster(output: Path) -> dict[str, int]:
    record_count = 32
    record_size = 32
    state = 0x2468_ACE1_1357_9BDF

    blob = bytearray(struct.pack("<II", record_count, record_size))
    for index in range(record_count):
        state = _lcg(state)
        tag = ((state >> 24) ^ (index * 19)) & 0xFFFFFFFF
        state = _lcg(state)
        flags = ((state >> 20) ^ (index * 7)) & 0xFFFF
        state = _lcg(state)
        length = 64 + (((state >> 18) ^ (index * 5)) & 0x1FF)
        state = _lcg(state)
        src = (state ^ ((index + 1) * 0x9E37_79B9_7F4A_7C15)) & MASK64
        state = _lcg(state)
        dst = (state ^ ((index + 11) * 0xD134_2543_DE82_EF95)) & MASK64
        state = _lcg(state)
        sport = 10000 + (((state >> 16) ^ (index * 17)) & 0xFFFF)
        state = _lcg(state)
        dport = 20000 + (((state >> 24) ^ (index * 29)) & 0xFFFF)
        blob.extend(struct.pack("<IHHQQII", tag, flags, length, src, dst, sport, dport))

    output.write_bytes(blob)
    return {"record_count": record_count, "record_size": record_size}


def generate_bitfield_extract(output: Path) -> dict[str, int]:
    record_count = 32
    record_words = 2
    state = 0xA5A5_5A5A_DEAD_BEEF

    blob = bytearray(struct.pack("<II", record_count, record_words))
    params = [
        (0x9E37_79B9_7F4A_7C15, 0, 0x3F),
        (0xD134_2543_DE82_EF95, 7, 0x1F),
        (0xA076_1D64_78BD_642F, 13, 0x7FF),
        (0xE703_7ED1_A0B4_28DB, 19, 0xFF),
        (0x8EBC_6AF0_9C88_C6E3, 11, 0x3FFF),
        (0x5899_65CC_7537_4CC3, 29, 0x3FF),
        (0x1D8E_4E27_C47D_124F, 17, 0x3FF),
        (0xEB44_ACCA_B455_D165, 5, 0xF),
        (0xF135_7AEA_2E62_A9C5, 9, 0xFF),
        (0x94D0_49BB_1331_11EB, 21, 0xFFF),
        (0xBF58_476D_1CE4_E5B9, 25, 0xFFFF),
        (0x369D_EA0F_31A5_3F85, 31, 0xFFFFFF),
    ]

    for index in range(record_count):
        fields: list[int] = []
        for salt, shift, mask in params:
            state = _lcg(state ^ ((index + 1) * salt))
            fields.append((state >> shift) & mask)

        word0 = (
            fields[0]
            | (fields[1] << 6)
            | (fields[2] << 11)
            | (fields[3] << 22)
            | (fields[4] << 30)
            | (fields[5] << 44)
            | (fields[6] << 54)
        ) & MASK64
        word1 = (
            fields[7]
            | (fields[8] << 4)
            | (fields[9] << 12)
            | (fields[10] << 24)
            | (fields[11] << 40)
        ) & MASK64
        blob.extend(struct.pack("<QQ", word0, word1))

    output.write_bytes(blob)
    return {"record_count": record_count, "record_words": record_words}


def generate_extract_dense(output: Path) -> dict[str, int]:
    groups = 32
    lanes = 8
    count = groups * lanes
    state = 0x1357_9BDF_2468_ACE0

    blob = bytearray()
    for index in range(count):
        state = _lcg(state ^ ((index + 1) * 0x8EBC_6AF0_9C88_C6E3))
        value = (state ^ ((index + 3) * 0x5899_65CC_7537_4CC3)) & MASK64
        blob.extend(struct.pack("<Q", value))

    output.write_bytes(blob)
    return {"groups": groups, "lanes": lanes, "count": count}


def generate_smallmul_strength_reduce(output: Path) -> dict[str, int]:
    count = 128
    seed = 0x89AB_CDEF
    state = 0x55AA_33CC_77EE_11DD

    blob = bytearray(struct.pack("<II", count, seed))
    for index in range(count):
        state = _lcg(state ^ ((index + 5) * 0xA076_1D64_78BD_642F))
        value = (state ^ ((index + 1) * 0x94D0_49BB_1331_11EB) ^ seed) & MASK64
        blob.extend(struct.pack("<Q", value))

    output.write_bytes(blob)
    return {"count": count, "seed": seed}


def generate_branch_fanout_32(output: Path) -> dict[str, int]:
    tags = BRANCH_FANOUT_32_TAGS
    count = 128
    blob = bytearray(struct.pack("<I", count))
    for index in range(count):
        tag = tags[(index * 9 + 5) % len(tags)]
        value = (((index + 1) * 0x1F12_3BB5) ^ (index * 0x9E37_79B9)) & 0xFFFFFFFF
        value = (value & ~63) | tag
        blob.extend(struct.pack("<I", value))

    output.write_bytes(blob)
    return {"count": count, "fanout": len(tags)}


BRANCH_FANOUT_32_TAGS = [
    0,
    2,
    3,
    5,
    7,
    9,
    11,
    12,
    14,
    17,
    19,
    21,
    24,
    25,
    26,
    28,
    31,
    33,
    35,
    37,
    38,
    40,
    42,
    45,
    47,
    49,
    52,
    54,
    56,
    59,
    61,
    63,
]


def generate_branch_fanout_32_predictable(output: Path) -> dict[str, int]:
    count = 128
    tag = BRANCH_FANOUT_32_TAGS[16]
    blob = bytearray(struct.pack("<I", count))
    for index in range(count):
        value = (((index + 1) * 0x1F12_3BB5) ^ (index * 0x9E37_79B9)) & 0xFFFFFFFF
        value = (value & ~63) | tag
        blob.extend(struct.pack("<I", value))

    output.write_bytes(blob)
    return {"count": count, "fanout": 1, "distribution": "predictable"}


def generate_branch_fanout_32_random(output: Path) -> dict[str, int]:
    count = 128
    state = 0x0BAD_F00D_CAFE_BEEF
    blob = bytearray(struct.pack("<I", count))
    for index in range(count):
        state = _lcg(state ^ ((index + 3) * 0xA076_1D64_78BD_642F))
        tag = BRANCH_FANOUT_32_TAGS[state % len(BRANCH_FANOUT_32_TAGS)]
        value = (((index + 1) * 0x1F12_3BB5) ^ (index * 0x9E37_79B9) ^ (state >> 7)) & 0xFFFFFFFF
        value = (value & ~63) | tag
        blob.extend(struct.pack("<I", value))

    output.write_bytes(blob)
    return {"count": count, "fanout": len(BRANCH_FANOUT_32_TAGS), "distribution": "random"}


def generate_deep_guard_tree_8(output: Path) -> dict[str, int]:
    record_count = 32
    record_size = 16
    state = 0x0F1E_2D3C_4B5A_6978

    blob = bytearray(struct.pack("<I", record_count))
    for index in range(record_count):
        state = _lcg(state ^ ((index + 1) * 0xD134_2543_DE82_EF95))
        payload = (state ^ ((index + 1) * 0xA076_1D64_78BD_642F)) & MASK64
        leaf = index % 9

        if leaf == 0:
            fields = (0x10, 0x00, 0x40, 0x80, 0x08, 0x00, 0x33, 0x00)
        elif leaf == 1:
            fields = (0x31, 0x02, 0x40, 0x80, 0x08, 0x00, 0x33, 0x00)
        elif leaf == 2:
            fields = (0x32, 0x01, 0x90, 0x80, 0x08, 0x00, 0x33, 0x00)
        elif leaf == 3:
            fields = (0x33, 0x01, 0x40, index & 0xFF, 0x08, 0x10, 0x33, 0x00)
        elif leaf == 4:
            fields = (0x40, 0x01, 0x40, 0x80, 0x90, 0x10, 0x33, 0x00)
        elif leaf == 5:
            fields = (0x34, 0x01, 0x40, 0x80, 0x08, 0x08, 0x33, 0x00)
        elif leaf == 6:
            fields = (0x35, 0x01, 0x40, 0x80, 0x08, 0x10, 0xAA, 0x00)
        elif leaf == 7:
            fields = (0x36, 0x01, 0x40, 0x80, 0x08, 0x10, 0x44, 0x01)
        else:
            fields = (0x37, 0x01, 0x40, 0x80, 0x08, 0x10, 0x55, 0x02)

        blob.extend(bytes(fields))
        blob.extend(struct.pack("<Q", payload))

    output.write_bytes(blob)
    return {"record_count": record_count, "record_size": record_size}


def generate_rotate_dense(output: Path) -> dict[str, int]:
    state = 0x0DDC_0FFE_EE11_2244
    seeds: list[int] = []

    for index in range(8):
        state = _lcg(state ^ ((index + 1) * 0x94D0_49BB_1331_11EB))
        seeds.append((state ^ ((index + 7) * 0xD134_2543_DE82_EF95)) & MASK64)

    output.write_bytes(struct.pack("<QQQQQQQQ", *seeds))
    return {"seeds": len(seeds), "bytes": len(seeds) * 8}


def generate_addr_calc_stride(output: Path) -> dict[str, int]:
    value_count = 256
    state = 0x0123_4567_89AB_CDEF

    blob = bytearray()
    for index in range(value_count):
        state = _lcg(state ^ ((index + 1) * 0xA076_1D64_78BD_642F))
        value = (state ^ ((index + 11) * 0x9E37_79B9_7F4A_7C15)) & MASK64
        blob.extend(struct.pack("<Q", value))

    output.write_bytes(blob)
    return {"value_count": value_count, "bytes": value_count * 8}


def generate_endian_swap_dense(output: Path) -> dict[str, int]:
    groups = 32
    lanes = 8
    count = groups * lanes
    state = 0x55AA_33CC_77EE_11FF

    blob = bytearray()
    for index in range(count):
        state = _lcg(state ^ ((index + 1) * 0xE703_7ED1_A0B4_28DB))
        value = ((state >> 16) ^ ((index + 1) * 0x9E37_79B9)) & 0xFFFFFFFF
        blob.extend(struct.pack("<I", value))

    output.write_bytes(blob)
    return {"groups": groups, "lanes": lanes, "count": count}


def generate_branch_flip_dense(output: Path) -> dict[str, int]:
    groups = 32
    lanes = 8
    count = groups * lanes
    state = 0x4242_A5A5_C3C3_5A5A

    blob = bytearray()
    for index in range(count):
        state = _lcg(state ^ ((index + 1) * 0xBF58_476D_1CE4_E5B9))
        value = (state ^ ((index + 1) * 0x369D_EA0F_31A5_3F85)) & MASK64
        blob.extend(struct.pack("<Q", value))

    output.write_bytes(blob)
    return {"groups": groups, "lanes": lanes, "count": count}


def generate_mega_basic_block_2048(output: Path) -> dict[str, int]:
    state = 0x1357_2468_ACE0_BDF1
    words: list[int] = []

    for index in range(8):
        state = _lcg(state ^ ((index + 1) * 0x9E37_79B9_7F4A_7C15))
        words.append((state ^ ((index + 1) * 0xA076_1D64_78BD_642F)) & MASK64)

    output.write_bytes(struct.pack("<QQQQQQQQ", *words))
    return {"words": len(words), "bytes": len(words) * 8}


def generate_rotate64_hash(output: Path) -> dict[str, int]:
    state = 0x1234_5678_9ABC_DEF0
    words: list[int] = []

    for index in range(8):
        state = _lcg(state ^ ((index + 1) * 0x9E37_79B9_7F4A_7C15))
        words.append((state ^ ((index + 1) * 0xD134_2543_DE82_EF95)) & MASK64)

    output.write_bytes(struct.pack("<QQQQQQQQ", *words))
    return {"words": len(words), "bytes": len(words) * 8}


GENERATORS = {
    "simple": generate_simple,
    "simple_packet": generate_simple_packet,
    "bitcount": generate_bitcount,
    "binary_search": generate_binary_search,
    "checksum": generate_checksum,
    "hash_chain": generate_hash_chain,
    "packet_parse": generate_packet_parse,
    "branch_layout": generate_branch_layout,
    "branch_layout_predictable": generate_branch_layout_predictable,
    "branch_layout_random": generate_branch_layout_random,
    "spill_pressure": generate_spill_pressure,
    "bounds_ladder": generate_bounds_ladder,
    "memory_pair_sum": generate_memory_pair_sum,
    "load_word32": generate_load_word32,
    "load_byte": generate_load_byte,
    "log2_fold": generate_log2_fold,
    "switch_dispatch": generate_switch_dispatch,
    "fibonacci_iter": generate_fibonacci_iter,
    "fibonacci_iter_packet": generate_fibonacci_iter_packet,
    "bpf_call_chain": generate_bpf_call_chain,
    "dep_chain_short": generate_dep_chain_short,
    "dep_chain_long": generate_dep_chain_long,
    "multi_acc_4": generate_multi_acc_4,
    "multi_acc_8": generate_multi_acc_8,
    "fixed_loop_small": generate_fixed_loop_small,
    "fixed_loop_large": generate_fixed_loop_large,
    "stride_load_4": generate_stride_load_4,
    "stride_load_16": generate_stride_load_16,
    "code_clone_2": generate_code_clone_2,
    "code_clone_8": generate_code_clone_8,
    "large_mixed_500": generate_large_mixed_500,
    "large_mixed_1000": generate_large_mixed_1000,
    "nested_loop_2": generate_nested_loop_2,
    "nested_loop_3": generate_nested_loop_3,
    "mixed_alu_mem": generate_mixed_alu_mem,
    "branch_dense": generate_branch_dense,
    "bounds_check_heavy": generate_bounds_check_heavy,
    "packet_redundant_bounds": generate_packet_redundant_bounds,
    "const_fold_chain": generate_const_fold_chain,
    "load_byte_recompose": generate_load_byte_recompose,
    "load_native_u64": generate_load_native_u64,
    "cmov_select": generate_cmov_select,
    "cmov_dense": generate_cmov_dense,
    "cond_select_dense": generate_cond_select_dense,
    "memcmp_prefix_64": generate_memcmp_prefix_64,
    "packet_parse_vlans_tcpopts": generate_packet_parse_vlans_tcpopts,
    "local_call_fanout": generate_local_call_fanout,
    "packet_rss_hash": generate_packet_rss_hash,
    "struct_field_cluster": generate_struct_field_cluster,
    "bitfield_extract": generate_bitfield_extract,
    "extract_dense": generate_extract_dense,
    "smallmul_strength_reduce": generate_smallmul_strength_reduce,
    "imm64_storm": generate_imm64_storm,
    "alu32_64_pingpong": generate_alu32_64_pingpong,
    "branch_fanout_32": generate_branch_fanout_32,
    "branch_fanout_32_predictable": generate_branch_fanout_32_predictable,
    "branch_fanout_32_random": generate_branch_fanout_32_random,
    "branch_flip_dense": generate_branch_flip_dense,
    "deep_guard_tree_8": generate_deep_guard_tree_8,
    "mega_basic_block_2048": generate_mega_basic_block_2048,
    "rotate64_hash": generate_rotate64_hash,
    "rotate_dense": generate_rotate_dense,
    "addr_calc_stride": generate_addr_calc_stride,
    "endian_swap_dense": generate_endian_swap_dense,
}


def materialize_input(generator_name: str, force: bool = False) -> tuple[Path, dict[str, int]]:
    if generator_name not in GENERATORS:
        raise KeyError(f"unknown input generator: {generator_name}")

    GENERATED_INPUT_DIR.mkdir(parents=True, exist_ok=True)
    output = GENERATED_INPUT_DIR / f"{generator_name}.mem"

    if output.exists() and not force:
        return output, {}

    metadata = GENERATORS[generator_name](output)
    return output, metadata
