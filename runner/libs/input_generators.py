from __future__ import annotations

import struct
from pathlib import Path

import yaml

from runner.libs import ROOT_DIR

GENERATED_INPUT_DIR = ROOT_DIR / "micro" / "generated-inputs"
MASK64 = (1 << 64) - 1

_SPECS_PATH = Path(__file__).with_name("input_specs.yaml")


def _lcg(state: int) -> int:
    return (state * 6364136223846793005 + 1442695040888963407) & MASK64


def _load_specs() -> dict:
    with open(_SPECS_PATH) as f:
        return yaml.safe_load(f)


def _build_lcg_words_q(output: Path, spec: dict) -> dict:
    n = spec["word_count"]; state = spec["initial_state"] & MASK64
    salt1, salt2, offset2 = spec["salt1"], spec["salt2"], spec.get("index_offset_salt2", 1)
    words: list[int] = []
    for index in range(n):
        state = _lcg(state ^ ((index + 1) * salt1)); words.append((state ^ ((index + offset2) * salt2)) & MASK64)
    output.write_bytes(struct.pack("<" + "Q" * n, *words))
    return {spec.get("metadata_count_key", "words"): n, "bytes": n * 8}


def _build_plain_bytes(output: Path, spec: dict) -> dict:
    n = spec["count"]; output.write_bytes(bytes(range(n))); return {"bytes": n}


def _build_lcg_u64_ii(output: Path, spec: dict) -> dict:
    count = spec["count"]
    seed = spec.get("seed", 0)
    simple_mode = "salt" in spec or "mixing_salt" in spec
    state = spec.get("initial_state", spec.get("salt", 0)) & MASK64
    salt1 = spec.get("salt1", 0 if simple_mode else 0x9E3779B97F4A7C15)
    salt2 = spec.get("salt2", spec.get("mixing_salt", 0))
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
    meta_b_key = spec.get("header_b_key", "seed")
    return {"count": count, meta_b_key: seed if meta_b_key == "seed" else header_b}


def _build_lcg_u16_ii(output: Path, spec: dict) -> dict:
    rounds, word_count = spec["rounds"], spec["word_count"]
    state = spec["initial_state"] & MASK64; index_mul = spec.get("index_mul", 257)
    blob = bytearray(struct.pack("<II", rounds, word_count))
    for index in range(word_count):
        state = _lcg(state); blob.extend(struct.pack("<H", ((state >> 16) ^ (index * index_mul)) & 0xFFFF))
    output.write_bytes(blob); return {"rounds": rounds, "word_count": word_count}


def _build_trace_event_type_switch_dispatch(output: Path, spec: dict) -> dict:
    count = spec["count"]; state = spec["initial_state"] & MASK64; mask = spec.get("mask", 0x3F)
    blob = bytearray(struct.pack("<I", count))
    for index in range(count):
        state = _lcg(state); blob.extend(struct.pack("<I", ((state >> 32) ^ index) & mask))
    output.write_bytes(blob); return {"count": count}


def _build_hash_chain(output: Path, spec: dict) -> dict:
    rounds, word_count = spec["rounds"], spec["word_count"]
    state = spec["initial_state"] & MASK64
    salt1, salt2 = spec.get("salt1", 0x9E3779B97F4A7C15), spec.get("salt2", 0xD1342543DE82EF95)
    blob = bytearray(struct.pack("<II", rounds, word_count))
    for index in range(word_count):
        state = _lcg(state ^ ((index + 1) * salt1)); blob.extend(struct.pack("<Q", (state ^ ((index + 1) * salt2)) & MASK64))
    output.write_bytes(blob); return {"rounds": rounds, "word_count": word_count}


_KIND_BUILDERS = {
    "lcg_words_q": _build_lcg_words_q,
    "plain_bytes": _build_plain_bytes,
    "lcg_u64_ii": _build_lcg_u64_ii,
    "lcg_u16_ii": _build_lcg_u16_ii,
    "trace_event_type_switch_dispatch": _build_trace_event_type_switch_dispatch,
    "hash_chain": _build_hash_chain,
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


def generate_sorted_rule_binary_search(output: Path) -> dict[str, int]:
    data_len, query_len = 32, 16
    data = [index * 3 + 7 for index in range(data_len)]
    queries = [data[(index * 17) % data_len] if index % 3 == 0 else (index * 19) + 5 for index in range(query_len)]
    blob = bytearray(struct.pack("<II", data_len, query_len))
    for value in data: blob.extend(struct.pack("<Q", value))
    for value in queries: blob.extend(struct.pack("<Q", value))
    output.write_bytes(blob); return {"data_len": data_len, "query_len": query_len}


def generate_packet_record_bounds_window(output: Path) -> dict[str, int]:
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


def generate_payload_prefix_memcmp_scan(output: Path) -> dict[str, int]:
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


def generate_packet_vlan_tcpopt_parser(output: Path) -> dict[str, int]:
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


def generate_bpf_local_call_fanout_dispatch(output: Path) -> dict[str, int]:
    record_count, record_size = 16, 24
    state = 0x0123456789ABCDEF; blob = bytearray(struct.pack("<II", record_count, record_size))
    for index in range(record_count):
        state = _lcg(state); tag = ((state >> 24) ^ (index * 17)) & 0xFFFFFFFF
        state = _lcg(state); left = (state ^ ((index + 1) * 0x9E3779B97F4A7C15)) & MASK64
        state = _lcg(state); right = (state ^ ((index + 7) * 0xD1342543DE82EF95)) & MASK64
        blob.extend(struct.pack("<IIQQ", index % 4, tag, left, right))
    output.write_bytes(blob); return {"record_count": record_count, "record_size": record_size}


def generate_flow_5tuple_rss_hash(output: Path) -> dict[str, int]:
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


def generate_katran_lb_consistent_hash_select(output: Path) -> dict[str, int]:
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
    packet[ip + 16 : ip + 20] = bytes([10, 100, 1, 1])
    tcp = ip + 20
    _write_be16(packet, tcp, 1234)
    _write_be16(packet, tcp + 2, 8080)
    _write_be32(packet, tcp + 4, 0x01020304)
    _write_be32(packet, tcp + 8, 0x05060708)
    packet[tcp + 12] = 0x50
    packet[tcp + 13] = 0x18
    _write_be16(packet, tcp + 14, 0x2000)
    _write_be16(packet, tcp + 16, 0)
    _write_be16(packet, tcp + 18, 0)
    output.write_bytes(packet)
    return {"packet_len": len(packet), "protocol": 6, "vip_port": 8080}


def generate_flow_record_field_scan(output: Path) -> dict[str, int]:
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


def generate_packed_header_bitfield_decode(output: Path) -> dict[str, int]:
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


def generate_cilium_policy_guard_tree_filter(output: Path) -> dict[str, int]:
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


def generate_bpftrace_string_search_prefix_scan(output: Path) -> dict[str, int]:
    haystack_size = 96
    needle_size = 8
    haystack_text = (
        b"tracepoint:syscalls:sys_enter_openat /usr/bin/python3 "
        b"GET /healthz service=bpftrace"
    )
    needle = b"service"

    haystack = bytearray(haystack_size)
    haystack[:len(haystack_text)] = haystack_text
    blob = bytearray(struct.pack("<II", len(haystack_text), len(needle)))
    blob.extend(haystack)
    padded = bytearray(needle_size)
    padded[:len(needle)] = needle
    blob.extend(padded)

    output.write_bytes(blob)
    return {"haystack_len": len(haystack_text), "needle_len": len(needle)}


def generate_tracee_http_method_prefix_detect(output: Path) -> dict[str, int]:
    record_count = 8
    record_size = 16
    payloads = [
        b"GET /index",
        b"POST /v1",
        b"PUT /obj",
        b"DELETE /",
        b"HEAD /",
        b"HTTP/1.1",
        b"PATCH /x",
        b"XYZ /bad",
    ]
    blob = bytearray(struct.pack("<II", record_count, record_size))
    for payload in payloads:
        record = bytearray(record_size)
        record[:len(payload)] = payload
        blob.extend(record)

    output.write_bytes(blob)
    return {"record_count": record_count, "record_size": record_size}


def generate_tracee_syscall_name_table_lookup(output: Path) -> dict[str, int]:
    syscall_ids = [
        0, 1, 2, 3, 9, 12, 39, 56,
        57, 59, 60, 61, 80, 87, 89, 158,
        202, 217, 257, 263, 281, 291, 321, 332,
        333, 334, 424, 425, 426, 427, 428, 429,
    ]
    while len(syscall_ids) < 64:
        syscall_ids.append(700 + len(syscall_ids) * 13)

    blob = bytearray(struct.pack("<I", len(syscall_ids)))
    for syscall_id in syscall_ids:
        blob.extend(struct.pack("<I", syscall_id))

    output.write_bytes(blob)
    return {"syscall_count": len(syscall_ids)}


def generate_cilium_socket_lb_service_select(output: Path) -> dict[str, int]:
    record_count = 64
    record_size = 24
    state = 0xC1111A5E5ACCE55
    blob = bytearray(struct.pack("<II", record_count, record_size))
    for index in range(record_count):
        state = _lcg(state ^ ((index + 1) * 0x9E3779B97F4A7C15))
        src_ip = 0x0A000000 | ((index + 1) & 0xFF)
        dst_ip = 0xAC100000 | ((index * 17) & 0xFFFF)
        sport = 10000 + ((state >> 8) & 0x3FFF)
        dport = 30000 + (index * 37 % 2768) if (index & 3) != 0 else 80 + index
        proto = 6 if (index & 1) == 0 else 17
        if index % 11 == 0:
            proto = 1
        flags = ((index & 1) | (((index >> 1) & 1) << 1) | (((index >> 2) & 1) << 2))
        svc_count = (index % 7) + 1
        cookie = (state ^ ((index + 3) * 0xD1342543DE82EF95)) & 0xFFFFFFFF
        scope = 1 if (index % 5) == 0 else 0
        blob.extend(struct.pack(
            "<IIHHBBHII",
            src_ip,
            dst_ip,
            sport,
            dport,
            proto,
            flags,
            svc_count,
            cookie,
            scope,
        ))

    output.write_bytes(blob)
    return {"record_count": record_count, "record_size": record_size}


def generate_bcc_tcpconnect_ipv4_tuple_filter(output: Path) -> dict[str, int]:
    record_count = 32
    record_size = 24
    state = 0xBCC700C0FFEE1234
    blob = bytearray(struct.pack("<II", record_count, record_size))
    ports = [22, 53, 80, 443, 8080, 8443, 30001, 32767]
    for index in range(record_count):
        state = _lcg(state ^ ((index + 1) * 0x9E3779B97F4A7C15))
        pid = 1000 + index * 17
        uid = 1000 + (index % 9)
        src = 0x0A010000 | ((index + 1) & 0xFF)
        dst = 0xAC100000 | ((index * 37) & 0xFFFF)
        sport = 20000 + ((state >> 8) & 0x3FFF)
        dport = ports[index % len(ports)]
        family = 2 if index % 7 != 0 else 10
        flags = (1 if index % 3 != 0 else 0) | (2 if index % 4 == 0 else 0) | (4 if index % 5 == 0 else 0)
        netns = 400 + (index * 11)
        blob.extend(struct.pack("<IIIIHHBBH", pid, uid, src, dst, sport, dport, family, flags, netns))

    output.write_bytes(blob)
    return {"record_count": record_count, "record_size": record_size}


def generate_tetragon_process_event_arg_filter(output: Path) -> dict[str, int]:
    record_count = 32
    record_size = 32
    state = 0x7E7A60A123456789
    arg_names = [b"bash", b"curl", b"python", b"sh", b"nginx", b"sshd", b"java", b"bpftool"]
    event_ids = [1, 2, 5, 9, 13, 17]
    blob = bytearray(struct.pack("<II", record_count, record_size))
    for index in range(record_count):
        state = _lcg(state ^ ((index + 3) * 0xD1342543DE82EF95))
        pid = 2000 + index * 19
        tid = pid + (index & 3)
        namespace_id = 0x4200 | (index & 0xFF) if index % 4 == 0 else 0x1100 | index
        event_id = event_ids[index % len(event_ids)]
        action = (index & 7) | (2 if index % 3 == 0 else 0)
        caps = (0x2400 if index % 5 == 0 else 0x80) ^ (state & 0xFFFF)
        arg = bytearray(8)
        name = arg_names[index % len(arg_names)]
        arg[:len(name)] = name[:8]
        arg_sig = struct.unpack("<Q", bytes(arg))[0]
        blob.extend(struct.pack("<IIIHHQQ", pid, tid, namespace_id, event_id, action, caps, arg_sig))

    output.write_bytes(blob)
    return {"record_count": record_count, "record_size": record_size}


def generate_otel_stack_frame_unwind_scan(output: Path) -> dict[str, int]:
    frame_count = 24
    frame_size = 24
    state = 0x07E15A5ECAFED00D
    blob = bytearray(struct.pack("<II", frame_count, frame_size))
    for index in range(frame_count):
        state = _lcg(state ^ ((index + 5) * 0xA0761D6478BD642F))
        ip = 0x7F0000000000 + ((state >> 12) & 0xFFFFFFF)
        sp_delta = 8 + ((index % 9) * 16)
        fp_delta = 16 + ((index % 7) * 24)
        if index % 11 == 0:
            fp_delta = 9000
        flags = (index & 7) | (2 if index % 4 == 0 else 0)
        kind = index % 5
        symbol_hash = ((state >> 28) ^ (index * 0x45D9F3B)) & 0xFFFFFFFF
        blob.extend(struct.pack("<QIIHHI", ip, sp_delta, fp_delta, flags, kind, symbol_hash))

    output.write_bytes(blob)
    return {"frame_count": frame_count, "frame_size": frame_size}


def generate_cilium_ct_nat_tuple_rewrite(output: Path) -> dict[str, int]:
    record_count = 32
    record_size = 32
    state = 0xC71110A7DEADBEEF
    blob = bytearray(struct.pack("<II", record_count, record_size))
    for index in range(record_count):
        state = _lcg(state ^ ((index + 1) * 0x9E3779B97F4A7C15))
        src = 0x0A020000 | ((index + 1) & 0xFF)
        dst = 0xAC110000 | ((index * 29) & 0xFFFF)
        sport = 10000 + ((state >> 9) & 0x3FFF)
        dport = 30000 + (index * 31 % 2768)
        proto = 6 if index % 3 != 0 else 17
        if index % 13 == 0:
            proto = 1
        direction = index & 1
        flags = (1 if index % 2 == 0 else 0) | (2 if index % 3 == 0 else 0) | (4 if index % 5 == 0 else 0)
        nat_src = 0x0A640000 | ((index + 7) & 0xFF)
        nat_dst = 0x0A650000 | ((index * 7) & 0xFF)
        rev_nat_id = 100 + index
        identity = 2000 + (index * 3)
        lifetime = 30 + ((state >> 17) & 0xFFFF)
        blob.extend(struct.pack(
            "<IIHHBBHIIHHI",
            src,
            dst,
            sport,
            dport,
            proto,
            direction,
            flags,
            nat_src,
            nat_dst,
            rev_nat_id,
            identity,
            lifetime,
        ))

    output.write_bytes(blob)
    return {"record_count": record_count, "record_size": record_size}


def generate_packet_toeplitz_rss_hash(output: Path) -> dict[str, int]:
    packet = bytearray(54)
    packet[0:6] = bytes([0x00, 0x16, 0x3E, 0x12, 0x34, 0x56])
    packet[6:12] = bytes([0x52, 0x54, 0x00, 0xAB, 0xCD, 0xEF])
    _write_be16(packet, 12, 0x0800)
    ip = 14
    packet[ip] = 0x45
    packet[ip + 1] = 0x00
    _write_be16(packet, ip + 2, 40)
    _write_be16(packet, ip + 4, 0x4321)
    _write_be16(packet, ip + 6, 0x4000)
    packet[ip + 8] = 64
    packet[ip + 9] = 6
    _write_be16(packet, ip + 10, 0)
    packet[ip + 12 : ip + 16] = bytes([10, 2, 3, 4])
    packet[ip + 16 : ip + 20] = bytes([198, 51, 100, 77])
    tcp = ip + 20
    _write_be16(packet, tcp, 41432)
    _write_be16(packet, tcp + 2, 443)
    _write_be32(packet, tcp + 4, 0x10203040)
    _write_be32(packet, tcp + 8, 0x50607080)
    packet[tcp + 12] = 0x50
    packet[tcp + 13] = 0x18
    _write_be16(packet, tcp + 14, 0x4000)
    _write_be16(packet, tcp + 16, 0)
    _write_be16(packet, tcp + 18, 0)
    output.write_bytes(packet)
    return {"packet_len": len(packet), "protocol": 6}


def generate_bpftrace_comm_key_fnv_hash(output: Path) -> dict[str, int]:
    record_count = 32
    record_size = 32
    comms = [b"python3", b"node", b"bash", b"curl", b"java", b"nginx", b"postgres", b"bpftrace"]
    blob = bytearray(struct.pack("<II", record_count, record_size))
    for index in range(record_count):
        pid = 3000 + index * 23
        tgid = pid - (index & 3)
        probe_id = 0x100 + (index % 11)
        flags = (index & 3) | (1 if index % 5 == 0 else 0)
        comm = bytearray(16)
        raw = comms[index % len(comms)]
        comm[:len(raw)] = raw
        blob.extend(struct.pack("<IIII", pid, tgid, probe_id, flags))
        blob.extend(comm)

    output.write_bytes(blob)
    return {"record_count": record_count, "record_size": record_size}


def _make_spec_generator(name: str, spec: dict):
    builder = _KIND_BUILDERS[spec["kind"]]
    def _gen(output: Path) -> dict[str, int]: return builder(output, spec)
    _gen.__name__ = f"generate_{name}"
    return _gen


def _build_generators() -> dict[str, object]:
    hand_written = {name[len("generate_"):]: fn for name, fn in globals().items()
                    if name.startswith("generate_") and callable(fn)}
    spec_driven = {name: _make_spec_generator(name, spec) for name, spec in _load_specs().items()}
    return {**spec_driven, **hand_written}


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
