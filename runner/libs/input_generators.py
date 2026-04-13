from __future__ import annotations

import struct
import sys as _sys
from pathlib import Path

import yaml


ROOT_DIR = Path(__file__).resolve().parents[2]
GENERATED_INPUT_DIR = ROOT_DIR / "micro" / "generated-inputs"
MASK64 = (1 << 64) - 1

_SPECS_PATH = Path(__file__).with_name("input_specs.yaml")


def _lcg(state: int) -> int:
    return (state * 6364136223846793005 + 1442695040888963407) & MASK64


def _load_specs() -> dict:
    with open(_SPECS_PATH) as f:
        return yaml.safe_load(f)


def _build_simple_lcg_u64_ii(output: Path, spec: dict) -> dict:
    """header=pack('<II',count,header_b); body=N u64s via plain _lcg(state)+XOR mix."""
    count = spec["count"]; seed = spec.get("seed", 0); salt = spec.get("salt", 0) & MASK64
    mixing_salt = spec.get("mixing_salt", 0); index_offset = spec.get("index_offset", 1)
    xor_seed = spec.get("xor_seed", False); header_b = spec.get("header_b", seed)
    state = salt; blob = bytearray(struct.pack("<II", count, header_b))
    for index in range(count):
        state = _lcg(state)
        value = (state ^ ((index + index_offset) * mixing_salt)) & MASK64 if mixing_salt else state & MASK64
        if xor_seed: value = (value ^ seed) & MASK64
        blob.extend(struct.pack("<Q", value))
    output.write_bytes(blob)
    meta_b_key = spec.get("header_b_key", "seed")
    return {"count": count, meta_b_key: seed if meta_b_key == "seed" else header_b}


def _build_code_clone(output: Path, spec: dict) -> dict:
    count, seed, salt = spec["count"], spec["seed"], spec["salt"]
    state = salt & MASK64; blob = bytearray(struct.pack("<II", count, seed))
    for index in range(count):
        state = _lcg(state); blob.extend(struct.pack("<Q", (state ^ ((index + 13) * 0x94D049BB133111EB) ^ (seed << (index & 3))) & MASK64))
    output.write_bytes(blob); return {"count": count, "seed": seed}


def _build_fixed_loop(output: Path, spec: dict) -> dict:
    rounds, mix, seed = spec["rounds"], spec["mix"], spec["seed"]
    output.write_bytes(struct.pack("<IIQ", rounds, mix, seed)); return {"rounds": rounds, "mix": mix}


def _build_lcg_words_q(output: Path, spec: dict) -> dict:
    n = spec["word_count"]; state = spec["initial_state"] & MASK64
    salt1, salt2, offset2 = spec["salt1"], spec["salt2"], spec.get("index_offset_salt2", 1)
    words: list[int] = []
    for index in range(n):
        state = _lcg(state ^ ((index + 1) * salt1)); words.append((state ^ ((index + offset2) * salt2)) & MASK64)
    output.write_bytes(struct.pack("<" + "Q" * n, *words))
    return {spec.get("metadata_count_key", "words"): n, "bytes": n * 8}


def _build_addr_calc_stride(output: Path, spec: dict) -> dict:
    n = spec["value_count"]; state = spec["initial_state"] & MASK64; salt1, salt2 = spec["salt1"], spec["salt2"]; blob = bytearray()
    for index in range(n):
        state = _lcg(state ^ ((index + 1) * salt1)); blob.extend(struct.pack("<Q", (state ^ ((index + 11) * salt2)) & MASK64))
    output.write_bytes(blob); return {"value_count": n, "bytes": n * 8}


def _build_endian_swap_dense(output: Path, spec: dict) -> dict:
    groups, lanes = spec["groups"], spec["lanes"]; count = groups * lanes
    state = spec["initial_state"] & MASK64; blob = bytearray()
    for index in range(count):
        state = _lcg(state ^ ((index + 1) * 0xE7037ED1A0B428DB))
        blob.extend(struct.pack("<I", ((state >> 16) ^ ((index + 1) * 0x9E3779B9)) & 0xFFFFFFFF))
    output.write_bytes(blob); return {"groups": groups, "lanes": lanes, "count": count}


def _build_groups_lanes_u64(output: Path, spec: dict) -> dict:
    """header=none; body=(groups*lanes) u64s via lcg(state^(i+1)*salt1) ^ (i+offset)*salt2."""
    groups, lanes = spec["groups"], spec["lanes"]; count = groups * lanes
    state = spec["initial_state"] & MASK64; salt1, salt2 = spec["salt1"], spec["salt2"]
    offset = spec.get("index_offset_salt2", 1); blob = bytearray()
    for index in range(count):
        state = _lcg(state ^ ((index + 1) * salt1)); blob.extend(struct.pack("<Q", (state ^ ((index + offset) * salt2)) & MASK64))
    output.write_bytes(blob); return {"groups": groups, "lanes": lanes, "count": count}


def _build_branch_flip_dense(output: Path, spec: dict) -> dict:
    return _build_groups_lanes_u64(output, spec)


def _build_extract_dense(output: Path, spec: dict) -> dict:
    return _build_groups_lanes_u64(output, {**spec, "index_offset_salt2": spec.get("index_offset_salt2", 3)})


def _build_plain_bytes(output: Path, spec: dict) -> dict:
    n = spec["count"]; output.write_bytes(bytes(range(n))); return {"bytes": n}


def _build_plain_u64_pair(output: Path, spec: dict) -> dict:
    left, right = spec["left"], spec["right"]
    output.write_bytes(struct.pack("<QQ", left, right)); return {"left": left, "right": right}


def _build_lcg_u64_ii(output: Path, spec: dict) -> dict:
    count = spec["count"]
    seed = spec.get("seed", 0)
    state = spec["initial_state"] & MASK64
    salt1 = spec.get("salt1", 0x9E3779B97F4A7C15)
    salt2 = spec.get("salt2", 0)
    offset = spec.get("index_offset", 1)
    xor_seed = spec.get("xor_seed", False)
    header_b = spec.get("header_b", seed)  # second u32 in header (default = seed)
    or_one = spec.get("or_one", False)      # force lowest bit set before mixing
    blob = bytearray(struct.pack("<II", count, header_b))
    for index in range(count):
        state = _lcg(state ^ ((index + 1) * salt1))
        if or_one:
            value = ((state | 1) ^ ((index + offset) * salt2)) & MASK64
        elif salt2:
            value = (state ^ ((index + offset) * salt2)) & MASK64
        else:
            value = state & MASK64
        if xor_seed:
            value ^= seed
            value &= MASK64
        blob.extend(struct.pack("<Q", value))
    output.write_bytes(blob)
    return {"count": count, "seed": seed}


def _build_lcg_u32_ii(output: Path, spec: dict) -> dict:
    count = spec["count"]; header_b = spec.get("header_b", 0); state = spec["initial_state"] & MASK64
    salt1 = spec.get("salt1", 0x9E3779B97F4A7C15); salt2 = spec.get("salt2", 0)
    shift = spec.get("shift", 24); xor_index_mul = spec.get("xor_index_mul", 0); xor_seed = spec.get("xor_seed", 0)
    blob = bytearray(struct.pack("<II", count, header_b))
    for index in range(count):
        state = _lcg(state ^ ((index + 1) * salt1))
        blob.extend(struct.pack("<I", ((state >> shift) ^ ((index + 1) * xor_index_mul) ^ xor_seed) & 0xFFFFFFFF))
    output.write_bytes(blob); return {"count": count, "header_b": header_b}


def _build_lcg_u16_ii(output: Path, spec: dict) -> dict:
    rounds, word_count = spec["rounds"], spec["word_count"]
    state = spec["initial_state"] & MASK64; index_mul = spec.get("index_mul", 257)
    blob = bytearray(struct.pack("<II", rounds, word_count))
    for index in range(word_count):
        state = _lcg(state); blob.extend(struct.pack("<H", ((state >> 16) ^ (index * index_mul)) & 0xFFFF))
    output.write_bytes(blob); return {"rounds": rounds, "word_count": word_count}


def _build_lcg_u64_no_header(output: Path, spec: dict) -> dict:
    n = spec["count"]; state = spec["initial_state"] & MASK64; blob = bytearray()
    for _ in range(n):
        state = _lcg(state); blob.extend(struct.pack("<Q", state & MASK64))
    output.write_bytes(blob); return {"bytes": n * 8}


def _build_switch_dispatch(output: Path, spec: dict) -> dict:
    count = spec["count"]; state = spec["initial_state"] & MASK64; mask = spec.get("mask", 0x3F)
    blob = bytearray(struct.pack("<I", count))
    for index in range(count):
        state = _lcg(state); blob.extend(struct.pack("<I", ((state >> 32) ^ index) & mask))
    output.write_bytes(blob); return {"count": count}


def _build_branch_layout(output: Path, spec: dict) -> dict:
    count = spec["count"]
    hot_threshold = spec["hot_threshold"]
    distribution = spec.get("distribution", "linear")
    blob = bytearray(struct.pack("<II", count, hot_threshold))
    state = spec.get("initial_state", 0) & MASK64
    salt = spec.get("salt", 0x9E3779B97F4A7C15)
    for index in range(count):
        if distribution == "predictable":
            value = ((index * 37) + 11) % hot_threshold
        elif distribution == "random":
            state = _lcg(state ^ ((index + 1) * salt))
            if state & 1:
                value = state % hot_threshold
            else:
                value = hot_threshold + ((state >> 16) % 2048)
        else:  # linear (original branch_layout behaviour)
            if index % 10 == 0:
                value = 1000 + index
            else:
                value = (index * 37) % hot_threshold
        blob.extend(struct.pack("<Q", value))
    output.write_bytes(blob)
    meta = {"count": count, "hot_threshold": hot_threshold}
    if distribution != "linear":
        meta["distribution"] = distribution
    return meta


def _build_nested_loop(output: Path, spec: dict) -> dict:
    outer = spec["outer"]
    inner = spec["inner"]
    seed = spec["seed"]
    salt = spec["salt"] & MASK64
    middle = spec.get("middle")
    if middle is not None:
        header = struct.pack("<IIII", outer, middle, inner, seed)
        count = outer * middle * inner
    else:
        header = struct.pack("<IIQ", outer, inner, seed)
        count = outer * inner
    state = salt
    blob = bytearray(header)
    for index in range(count):
        state = _lcg(state)
        value = state ^ ((index + 9) * 0xA0761D6478BD642F)
        blob.extend(struct.pack("<Q", value & MASK64))
    output.write_bytes(blob)
    meta = {"outer": outer, "inner": inner}
    if middle is not None:
        meta["middle"] = middle
    return meta


def _build_hash_chain(output: Path, spec: dict) -> dict:
    rounds, word_count = spec["rounds"], spec["word_count"]
    state = spec["initial_state"] & MASK64
    salt1, salt2 = spec.get("salt1", 0x9E3779B97F4A7C15), spec.get("salt2", 0xD1342543DE82EF95)
    blob = bytearray(struct.pack("<II", rounds, word_count))
    for index in range(word_count):
        state = _lcg(state ^ ((index + 1) * salt1)); blob.extend(struct.pack("<Q", (state ^ ((index + 1) * salt2)) & MASK64))
    output.write_bytes(blob); return {"rounds": rounds, "word_count": word_count}


def _build_branch_dense(output: Path, spec: dict) -> dict:
    count = spec["count"]; hot_threshold = spec["hot_threshold"]
    state = spec["initial_state"] & MASK64; hot_every = spec.get("hot_every", 5)
    blob = bytearray(struct.pack("<II", count, hot_threshold))
    for index in range(count):
        state = _lcg(state)
        value = hot_threshold + ((state >> 12) & 0x7FF) if index % hot_every == 0 else ((state >> 20) ^ (index * 73)) & 0x3FF
        blob.extend(struct.pack("<I", value))
    output.write_bytes(blob); return {"count": count, "hot_threshold": hot_threshold}


def _build_branch_fanout(output: Path, spec: dict) -> dict:
    tags = spec["tags"]
    count = spec["count"]
    distribution = spec.get("distribution", "cyclic")
    state = spec.get("initial_state", 0) & MASK64
    salt = spec.get("salt", 0xA0761D6478BD642F)
    fixed_tag_index = spec.get("fixed_tag_index", 0)
    index_step = spec.get("index_step", 9)
    index_shift = spec.get("index_shift", 5)
    blob = bytearray(struct.pack("<I", count))
    for index in range(count):
        base = (((index + 1) * 0x1F123BB5) ^ (index * 0x9E3779B9)) & 0xFFFFFFFF
        if distribution == "predictable":
            tag = tags[fixed_tag_index]
        elif distribution == "random":
            state = _lcg(state ^ ((index + 3) * salt))
            tag = tags[state % len(tags)]
            base = (base ^ (state >> 7)) & 0xFFFFFFFF
        else:  # cyclic
            tag = tags[(index * index_step + index_shift) % len(tags)]
        value = (base & ~63) | tag
        blob.extend(struct.pack("<I", value))
    output.write_bytes(blob)
    meta: dict = {"count": count, "fanout": 1 if distribution == "predictable" else len(tags)}
    if distribution != "cyclic":
        meta["distribution"] = distribution
    return meta


_KIND_BUILDERS = {
    "simple_lcg_u64_ii":  _build_simple_lcg_u64_ii,
    "dep_chain":           _build_simple_lcg_u64_ii,  # alias; YAML provides mixing_salt/index_offset/xor_seed
    "multi_acc":           _build_simple_lcg_u64_ii,  # alias
    "stride_load":         _build_simple_lcg_u64_ii,  # alias
    "large_mixed":         _build_simple_lcg_u64_ii,  # alias
    "load_isolation":      _build_simple_lcg_u64_ii,  # alias; mixing_salt=0
    "code_clone":          _build_code_clone,
    "fixed_loop":          _build_fixed_loop,
    "lcg_words_q":         _build_lcg_words_q,
    "addr_calc_stride":    _build_addr_calc_stride,
    "endian_swap_dense":   _build_endian_swap_dense,
    "groups_lanes_u64":    _build_groups_lanes_u64,
    "branch_flip_dense":   _build_branch_flip_dense,  # alias
    "extract_dense":       _build_extract_dense,       # alias
    "plain_bytes":         _build_plain_bytes,
    "plain_u64_pair":      _build_plain_u64_pair,
    "lcg_u64_ii":          _build_lcg_u64_ii,
    "lcg_u32_ii":          _build_lcg_u32_ii,
    "lcg_u16_ii":          _build_lcg_u16_ii,
    "lcg_u64_no_header":   _build_lcg_u64_no_header,
    "switch_dispatch":     _build_switch_dispatch,
    "branch_layout":       _build_branch_layout,
    "nested_loop":         _build_nested_loop,
    "hash_chain":          _build_hash_chain,
    "branch_dense":        _build_branch_dense,
    "branch_fanout":       _build_branch_fanout,
}


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


def generate_binary_search(output: Path) -> dict[str, int]:
    data_len, query_len = 32, 16
    data = [index * 3 + 7 for index in range(data_len)]
    queries = [data[(index * 17) % data_len] if index % 3 == 0 else (index * 19) + 5 for index in range(query_len)]
    blob = bytearray(struct.pack("<II", data_len, query_len))
    for value in data: blob.extend(struct.pack("<Q", value))
    for value in queries: blob.extend(struct.pack("<Q", value))
    output.write_bytes(blob); return {"data_len": data_len, "query_len": query_len}


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


def generate_bounds_ladder(output: Path) -> dict[str, int]:
    record_count, record_size = 32, 32
    state = 0x55AA55AA12349876; blob = bytearray(struct.pack("<II", record_count, record_size))
    for index in range(record_count):
        state = _lcg(state); tag = (state ^ index) & 0xFFFFFFFF
        state = _lcg(state); left = state & MASK64
        state = _lcg(state); span = ((state >> 16) ^ (index * 13)) & 0xFFFFFFFF
        state = _lcg(state); right = state & MASK64
        state = _lcg(state); tail = (state ^ (index * 0xA5A5A5A5A5A5A5A5)) & MASK64
        blob.extend(struct.pack("<IQIQQ", tag, left, span, right, tail))
    output.write_bytes(blob); return {"record_count": record_count, "record_size": record_size}


def generate_bounds_check_heavy(output: Path) -> dict[str, int]:
    record_count = 32
    record_size = 32
    state = 0x0F0F1E1E2D2D3C3C
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
            value = state ^ ((index + offset) * 0x9E3779B97F4A7C15)
            width = min(8, record_size - offset)
            record[offset : offset + width] = struct.pack("<Q", value & MASK64)[:width]
        blob.extend(record)
    output.write_bytes(blob)
    return {"record_count": record_count, "record_size": record_size}


def generate_packet_redundant_bounds(output: Path) -> dict[str, int]:
    record_count = 32
    record_size = 24
    state = 0x1020304050607080
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
            value = ((state >> 20) ^ ((index + offset) * 0x9E3779B9)) & 0xFFFFFFFF
            record[offset : offset + 4] = struct.pack("<I", value)
        state = _lcg(state)
        record[20:22] = struct.pack("<H", ((state >> 17) ^ (index * 23)) & 0xFFFF)
        state = _lcg(state)
        record[22:24] = struct.pack("<H", ((state >> 9) ^ (index * 41)) & 0xFFFF)
        blob.extend(record)
    output.write_bytes(blob)
    return {"record_count": record_count, "record_size": record_size}


def generate_cmov_select(output: Path) -> dict[str, int]:
    groups, lanes = 27, 4; count = groups * lanes; compare_mask = (1 << 63) - 1
    state = 0x123456789ABCDEF0
    compare_lhs: list[int] = []; compare_rhs: list[int] = []
    select_true: list[int] = []; select_false: list[int] = []
    for index in range(count):
        state = _lcg(state ^ ((index + 1) * 0x9E3779B97F4A7C15)); raw_lhs = state & compare_mask
        state = _lcg(state ^ ((index + 1) * 0xD1342543DE82EF95)); raw_rhs = state & compare_mask
        hi, lo = (raw_lhs, raw_rhs) if raw_lhs >= raw_rhs else (raw_rhs, raw_lhs)
        if hi == lo: hi += 1 if hi < compare_mask else 0; lo -= 1 if lo > 0 else 0
        if index & 1: compare_lhs.append(hi); compare_rhs.append(lo)
        else: compare_lhs.append(lo); compare_rhs.append(hi)
        state = _lcg(state ^ ((index + 1) * 0xA0761D6478BD642F))
        select_true.append((state ^ ((index + 5) * 0xE7037ED1A0B428DB)) & MASK64)
        state = _lcg(state ^ ((index + 1) * 0x8EBC6AF09C88C6E3))
        select_false.append((state ^ ((index + 9) * 0x589965CC75374CC3)) & MASK64)
    blob = bytearray(struct.pack("<II", count, groups))
    for values in (compare_lhs, compare_rhs, select_true, select_false):
        for value in values: blob.extend(struct.pack("<Q", value))
    output.write_bytes(blob); return {"count": count, "groups": groups, "lanes": lanes}


def generate_cmov_dense(output: Path) -> dict[str, int]:
    count = 32; state = 0xC001D00DF00DBAAD; arrays: list[list[int]] = [[], [], [], []]
    for index in range(count):
        for array_index, values in enumerate(arrays):
            state = _lcg(state ^ ((index + 1) * (array_index + 3) * 0x9E3779B97F4A7C15)); values.append(state & MASK64)
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
    state = 0xC0DECAFE12345678
    compare_lhs: list[int] = []
    compare_rhs: list[int] = []
    on_true: list[int] = []
    on_false: list[int] = []
    for index in range(count):
        state = _lcg(state ^ ((index + 1) * 0x9E3779B97F4A7C15))
        base = state & ((1 << 61) - 1)
        state = _lcg(state ^ ((index + 5) * 0xA0761D6478BD642F))
        delta = ((state >> 9) & 0xFFFFF) + 1
        if index & 1:
            lhs = base
            rhs = base + delta
        else:
            rhs = base
            lhs = base + delta
        state = _lcg(state ^ ((index + 9) * 0xD1342543DE82EF95))
        compare_lhs.append(lhs & MASK64)
        compare_rhs.append(rhs & MASK64)
        on_true.append((state ^ ((index + 1) * 0x94D049BB133111EB)) & MASK64)
        state = _lcg(state ^ ((index + 13) * 0xBF58476D1CE4E5B9))
        on_false.append((state ^ ((index + 1) * 0x369DEA0F31A53F85)) & MASK64)
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
    record_count, record_size = 16, 24
    state = 0x0123456789ABCDEF; blob = bytearray(struct.pack("<II", record_count, record_size))
    for index in range(record_count):
        state = _lcg(state); tag = ((state >> 24) ^ (index * 17)) & 0xFFFFFFFF
        state = _lcg(state); left = (state ^ ((index + 1) * 0x9E3779B97F4A7C15)) & MASK64
        state = _lcg(state); right = (state ^ ((index + 7) * 0xD1342543DE82EF95)) & MASK64
        blob.extend(struct.pack("<IIQQ", index % 4, tag, left, right))
    output.write_bytes(blob); return {"record_count": record_count, "record_size": record_size}


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


def generate_struct_field_cluster(output: Path) -> dict[str, int]:
    record_count, record_size = 32, 32
    state = 0x2468ACE113579BDF; blob = bytearray(struct.pack("<II", record_count, record_size))
    for index in range(record_count):
        state = _lcg(state); tag = ((state >> 24) ^ (index * 19)) & 0xFFFFFFFF
        state = _lcg(state); flags = ((state >> 20) ^ (index * 7)) & 0xFFFF
        state = _lcg(state); length = 64 + (((state >> 18) ^ (index * 5)) & 0x1FF)
        state = _lcg(state); src = (state ^ ((index + 1) * 0x9E3779B97F4A7C15)) & MASK64
        state = _lcg(state); dst = (state ^ ((index + 11) * 0xD1342543DE82EF95)) & MASK64
        state = _lcg(state); sport = 10000 + (((state >> 16) ^ (index * 17)) & 0xFFFF)
        state = _lcg(state); dport = 20000 + (((state >> 24) ^ (index * 29)) & 0xFFFF)
        blob.extend(struct.pack("<IHHQQII", tag, flags, length, src, dst, sport, dport))
    output.write_bytes(blob); return {"record_count": record_count, "record_size": record_size}


def generate_bitfield_extract(output: Path) -> dict[str, int]:
    record_count = 32
    record_words = 2
    state = 0xA5A55A5ADEADBEEF
    blob = bytearray(struct.pack("<II", record_count, record_words))
    params = [
        (0x9E3779B97F4A7C15, 0, 0x3F),
        (0xD1342543DE82EF95, 7, 0x1F),
        (0xA0761D6478BD642F, 13, 0x7FF),
        (0xE7037ED1A0B428DB, 19, 0xFF),
        (0x8EBC6AF09C88C6E3, 11, 0x3FFF),
        (0x589965CC75374CC3, 29, 0x3FF),
        (0x1D8E4E27C47D124F, 17, 0x3FF),
        (0xEB44ACCAB455D165, 5, 0xF),
        (0xF1357AEA2E62A9C5, 9, 0xFF),
        (0x94D049BB133111EB, 21, 0xFFF),
        (0xBF58476D1CE4E5B9, 25, 0xFFFF),
        (0x369DEA0F31A53F85, 31, 0xFFFFFF),
    ]
    for index in range(record_count):
        fields: list[int] = []
        for salt, shift, mask in params:
            state = _lcg(state ^ ((index + 1) * salt))
            fields.append((state >> shift) & mask)
        word0 = (fields[0] | (fields[1] << 6) | (fields[2] << 11) | (fields[3] << 22)
                 | (fields[4] << 30) | (fields[5] << 44) | (fields[6] << 54)) & MASK64
        word1 = (fields[7] | (fields[8] << 4) | (fields[9] << 12)
                 | (fields[10] << 24) | (fields[11] << 40)) & MASK64
        blob.extend(struct.pack("<QQ", word0, word1))
    output.write_bytes(blob)
    return {"record_count": record_count, "record_words": record_words}


def generate_deep_guard_tree_8(output: Path) -> dict[str, int]:
    record_count, record_size = 32, 16
    state = 0x0F1E2D3C4B5A6978; blob = bytearray(struct.pack("<I", record_count))
    leaf_table = [(0x10, 0x00, 0x40, 0x80, 0x08, 0x00, 0x33, 0x00), (0x31, 0x02, 0x40, 0x80, 0x08, 0x00, 0x33, 0x00),
                  (0x32, 0x01, 0x90, 0x80, 0x08, 0x00, 0x33, 0x00), None,  # leaf 3 uses index-dependent field
                  (0x40, 0x01, 0x40, 0x80, 0x90, 0x10, 0x33, 0x00), (0x34, 0x01, 0x40, 0x80, 0x08, 0x08, 0x33, 0x00),
                  (0x35, 0x01, 0x40, 0x80, 0x08, 0x10, 0xAA, 0x00), (0x36, 0x01, 0x40, 0x80, 0x08, 0x10, 0x44, 0x01),
                  (0x37, 0x01, 0x40, 0x80, 0x08, 0x10, 0x55, 0x02)]
    for index in range(record_count):
        state = _lcg(state ^ ((index + 1) * 0xD1342543DE82EF95))
        payload = (state ^ ((index + 1) * 0xA0761D6478BD642F)) & MASK64
        leaf = index % 9
        fields = (0x33, 0x01, 0x40, index & 0xFF, 0x08, 0x10, 0x33, 0x00) if leaf == 3 else leaf_table[leaf]
        blob.extend(bytes(fields)); blob.extend(struct.pack("<Q", payload))
    output.write_bytes(blob); return {"record_count": record_count, "record_size": record_size}


def _make_spec_generator(name: str, spec: dict):
    builder = _KIND_BUILDERS[spec["kind"]]
    def _gen(output: Path) -> dict[str, int]: return builder(output, spec)
    _gen.__name__ = f"generate_{name}"
    return _gen


def _build_generators() -> dict[str, object]:
    _mod = _sys.modules[__name__]
    hand_written = {name[len("generate_"):]: fn for name, fn in vars(_mod).items()
                    if name.startswith("generate_") and callable(fn)}
    spec_driven = {name: _make_spec_generator(name, spec) for name, spec in _load_specs().items()}
    merged = {**spec_driven, **hand_written}
    for _name, _fn in spec_driven.items():
        if _name not in hand_written: setattr(_mod, f"generate_{_name}", _fn)
    return merged


GENERATORS = _build_generators()


def materialize_input(generator_name: str, force: bool = False) -> tuple[Path, dict[str, int]]:
    if generator_name not in GENERATORS:
        raise KeyError(f"unknown input generator: {generator_name}")

    GENERATED_INPUT_DIR.mkdir(parents=True, exist_ok=True)
    output = GENERATED_INPUT_DIR / f"{generator_name}.mem"

    if output.exists() and not force:
        return output, {}

    metadata = GENERATORS[generator_name](output)
    return output, metadata
