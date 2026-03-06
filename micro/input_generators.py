from __future__ import annotations

import struct
from pathlib import Path


ROOT_DIR = Path(__file__).resolve().parent
GENERATED_INPUT_DIR = ROOT_DIR / "generated-inputs"
MASK64 = (1 << 64) - 1


def _lcg(state: int) -> int:
    return (state * 6364136223846793005 + 1442695040888963407) & MASK64


def generate_simple(output: Path) -> dict[str, int]:
    output.write_bytes(bytes(range(64)))
    return {"bytes": 64}


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


def _write_be16(packet: bytearray, offset: int, value: int) -> None:
    packet[offset] = (value >> 8) & 0xFF
    packet[offset + 1] = value & 0xFF


def generate_packet_parse(output: Path) -> dict[str, int]:
    packet_count = 64
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
    count = 512
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


def generate_map_lookup_churn(output: Path) -> dict[str, int]:
    rounds = 128
    stride = 7
    seed = 0x2468ACE1
    word_count = 64
    state = 0x0123_4567_89AB_CDEF

    blob = bytearray(struct.pack("<III", rounds, stride, seed))
    for index in range(word_count):
        state = _lcg(state)
        value = state ^ ((index + 1) * 0xD134_2543_DE82_EF95) ^ seed
        blob.extend(struct.pack("<Q", value & MASK64))

    output.write_bytes(blob)
    return {"rounds": rounds, "stride": stride, "word_count": word_count}


def generate_map_roundtrip(output: Path) -> dict[str, int]:
    rounds = 64
    mix = 0x31415926
    seed = 0x0BAD_F00D_CAFE_BEEF

    blob = bytearray(struct.pack("<IIQ", rounds, mix, seed))
    output.write_bytes(blob)
    return {"rounds": rounds, "mix": mix}


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


GENERATORS = {
    "simple": generate_simple,
    "bitcount": generate_bitcount,
    "binary_search": generate_binary_search,
    "checksum": generate_checksum,
    "packet_parse": generate_packet_parse,
    "branch_layout": generate_branch_layout,
    "map_lookup_churn": generate_map_lookup_churn,
    "map_roundtrip": generate_map_roundtrip,
    "spill_pressure": generate_spill_pressure,
    "bounds_ladder": generate_bounds_ladder,
    "memory_pair_sum": generate_memory_pair_sum,
    "log2_fold": generate_log2_fold,
    "switch_dispatch": generate_switch_dispatch,
    "fibonacci_iter": generate_fibonacci_iter,
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
