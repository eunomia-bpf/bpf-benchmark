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


GENERATORS = {
    "simple": generate_simple,
    "bitcount": generate_bitcount,
    "binary_search": generate_binary_search,
    "checksum": generate_checksum,
    "packet_parse": generate_packet_parse,
    "branch_layout": generate_branch_layout,
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
